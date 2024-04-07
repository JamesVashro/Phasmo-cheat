#include "pch.h"
#include "menu.h"
#include "../hooking/hook.h"

void Menu::Init(ID3D11Device* device)
{

}

void Menu::Loop()
{
	ImGui::SetNextWindowSize(ImVec2(350, 650));

	if (ImGui::Begin("widner", &smile::vars->menuOpened, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize))
	{
		ImGui::CheckboxSlider("Custom Ouija Response", &smile::vars->bInterceptOuijaMessage);
		ImGui::InputText("Message", &smile::vars->interceptOuijaMessage);
		if (ImGui::Button("Change ghost room", 5))
		{
			ChangeFavRoom(smile::vars->ghostController, smile::vars->localPlayer->GetCurrentRoom(), 0);
		}
		if (ImGui::Button("Lock exits", 5))
		{
			auto levelController = smile::vars->currentGhost->fields._7_activity->fields._5__________;
			auto exitDoors = levelController->fields._17_DoorArray2;

			const char* mName = "HuntingCloseDoorNetworked";
			System_String_o* HuntingCloseDoorNetworked = SystemStringCtor(mName, 0, strlen(mName), 0);
			DWORD* arr = il2cppArrayNewSpecific((__int64)smile::vars->object_TypeInfo, 0);
			for (int i = 0; i < exitDoors->max_length; i++)
			{
				auto door = exitDoors->m_Items[i];

				if (!door)
				{
					printf("no door\n");
					continue;
				}

				HOOK::oRpc(door->fields._16_view, HuntingCloseDoorNetworked, 0, (System_Object_array*)arr, 0);
			}
		}

		ImGui::End();
	}
}

void Menu::RenderOverlay()
{
	ImGui::SetNextWindowPos(ImVec2(5, 5));
	ImGuiWindowFlags flags = { ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDecoration };
	if (ImGui::Begin("ghostOInfoOverlay", &smile::vars->ghostInfoOverlay, flags))
	{
		ImGui::Text("Ghost State: %d\n", smile::vars->ghostState);
		ImGui::Text("Appearing: %d\n", smile::vars->showGhost);
		ImGui::End();
	}
	ImGuiIO& io = ImGui::GetIO();
	//ImGui::SetCursorPos(ImVec2(io.DisplaySize.x - 265, io.DisplaySize.y - 565));
	ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x - 265, io.DisplaySize.y - 565), ImGuiCond_FirstUseEver);

	if (ImGui::Begin("rpcList", &smile::vars->showRPCs, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDecoration))
	{
		if (ImGui::BeginChild("##Rpcs", ImVec2(250, 550), true))
		{
			if (smile::vars->menuOpened)
				if (ImGui::Button("Clear output", 5))
					smile::vars->rpcCalls.clear();

			for (int i = smile::vars->rpcCalls.size() - 1; i > 0; i--)
			{
				ImGui::Text(smile::vars->rpcCalls[i].c_str());
			}

			ImGui::EndChild();
		}
		ImGui::End();
	}
}
