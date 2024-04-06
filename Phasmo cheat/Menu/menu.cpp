#include "pch.h"
#include "menu.h"

void Menu::Init(ID3D11Device* device)
{

}

void Menu::Loop()
{
	ImGui::SetNextWindowSize(ImVec2(150, 150));

	if (ImGui::Begin("widner", &smile::vars->menuOpened, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize))
	{


		ImGui::End();
	}
}

void Menu::RenderOverlay()
{
	ImGui::SetNextWindowPos(ImVec2(5, 5));
	ImGuiWindowFlags flags = { ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDecoration };
	if (ImGui::Begin("ghostOInfoOverlay", &smile::vars->ghostInfoOverlay, flags))
	{
		ImGui::Text("Ghost State: %d\n", smile::vars->ghostState);
		ImGui::Text("Appearing: %d\n", smile::vars->showGhost);

		ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 250);
		if (ImGui::BeginChild("##Rpcs", ImVec2(250, 550), true))
		{
			for (int i = smile::vars->rpcCalls.size() - 1; i > 0; i--)
			{
				ImGui::Text(smile::vars->rpcCalls[i].c_str());
			}

			ImGui::EndChild();
		}
		ImGui::End();
	}
}
