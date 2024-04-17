#include "pch.h"
#include "../hook.h"
#include "../Menu/menu.h"


extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI HOOK::WndProc_Hook(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) 
{
	if (wparam == 0x09) //Q key
	{
		if (msg == WM_KEYDOWN)
		{
			smile::vars->showGhost = true;
		}
		else
		if (msg == WM_KEYUP)
		{
			if (!smile::vars->unAppearGhost)
				smile::vars->unAppearGhost = true;
		}
	}

	if (msg == WM_KEYUP)
	{
		if (wparam == VK_INSERT)
		{
			static int lastLockedState = -1;
			static bool wasVisible = false;

			if (!smile::vars->menuOpened)   //just come logic to see cursor state before opening the menu so it can return to that state after
			{
				lastLockedState = GetLockState(0);
				if (lastLockedState == 0)
					wasVisible = true;
				else
					wasVisible = false;
			}

			smile::vars->menuOpened = !smile::vars->menuOpened;

			if (!smile::vars->menuOpened)
			{
				if (lastLockedState != -1)
					SetLockState(lastLockedState, 0);

				SetCursorVisible(wasVisible, 0);
			}
			else
			{
				SetCursorVisible(true, 0);
				SetLockState(0, 0);
			}
		}
	}

	if (smile::vars->menuOpened) 
	{
		ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam);
		return true;
	}

	return CallWindowProc(oWndProc, hwnd, msg, wparam, lparam);
}

HRESULT HOOK::PresentHook(IDXGISwapChain* __this, UINT sync, UINT flags) {
	if (smile::vars->waitinForEject)
		return oPresent(__this, sync, flags);

	if (!menu.initialized) 
	{
		//For some reason this needs to be here. if this line is not here the FOV works but the menu never gets initialized... beats me as to why but it is what it is

		menu.swapChain = __this;
		__this->GetDevice(__uuidof(ID3D11Device), reinterpret_cast<PVOID*>(&menu.device));
		menu.device->GetImmediateContext(&menu.context);

		DXGI_SWAP_CHAIN_DESC desc;
		__this->GetDesc(&desc);

		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.IniFilename = NULL;
		menu.window = desc.OutputWindow;

		ImGui_ImplWin32_Init(menu.window);
		ImGui_ImplDX11_Init(menu.device, menu.context);
		ImGui::GetIO().ImeWindowHandle = menu.window;
		ImGui_ImplDX11_CreateDeviceObjects();

		menu.MenuFont = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\consolab.ttf", 14.0f);
		menu.One_Font = io.Fonts->AddFontFromMemoryTTF(&Shrift1, sizeof Shrift1, 20.f, NULL, io.Fonts->GetGlyphRangesCyrillic());

		io.Fonts->Build();
		ImGui_ImplDX11_InvalidateDeviceObjects();

		ID3D11Texture2D* backBuffer;
		ImGuiStyle& style = ImGui::GetStyle();

		style.Colors[ImGuiCol_WindowBg] = ImColor(12, 12, 12, 240);
		style.Colors[ImGuiCol_TitleBg] = ImColor(12, 12, 12);
		style.Colors[ImGuiCol_TitleBgActive] = ImColor(12, 12, 12);

		style.Colors[ImGuiCol_Button] = ImColor(100, 100, 100);
		style.Colors[ImGuiCol_ButtonActive] = ImColor(200, 200, 200);
		style.Colors[ImGuiCol_ButtonHovered] = ImColor(155, 155, 155);

		style.Colors[ImGuiCol_HeaderHovered] = ImColor(80, 80, 80);
		style.Colors[ImGuiCol_HeaderActive] = ImColor(100, 100, 100);
		style.Colors[ImGuiCol_Header] = ImColor(41, 41, 41);

		style.Colors[ImGuiCol_FrameBg] = ImColor(41, 41, 41);
		style.Colors[ImGuiCol_FrameBgHovered] = ImColor(80, 80, 80);
		style.Colors[ImGuiCol_FrameBgActive] = ImColor(80, 80, 80);


		style.Colors[ImGuiCol_CheckMark] = ImColor(0, 255, 0);

		style.Colors[ImGuiCol_SliderGrabActive] = ImColor(155, 155, 155);
		style.Colors[ImGuiCol_SliderGrab] = ImColor(0, 255, 0);

		__this->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backBuffer);
		menu.device->CreateRenderTargetView(backBuffer, NULL, &menu.targetView);
		backBuffer->Release();

		menu.Init(menu.device);

		oWndProc = reinterpret_cast<WNDPROC>(SetWindowLongPtr(menu.window, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(WndProc_Hook)));

		menu.initialized = true;
	}

	ImGui_ImplWin32_NewFrame();
	ImGui_ImplDX11_NewFrame();

	ImGui::NewFrame();

	ImGui::PushFont(menu.One_Font);

	if (smile::vars->menuOpened)
		menu.Loop();

	menu.RenderOverlay();


	ImGui::PopFont();

	ImGui::EndFrame();
	ImGui::Render();

	menu.context->OMSetRenderTargets(1, &menu.targetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());


	return oPresent(__this, sync, flags);
}