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
			auto exitDoors = levelController->fields._17_doorArray2;

			/*const char* mName = "HuntingCloseDoorNetworked";
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
			}*/
		}

		if (ImGui::Button("Change Ghost Room", 5))
		{
			ChangeFavRoom(smile::vars->ghostController, smile::vars->localPlayer->GetCurrentRoom(), 0);
			DelayTeleportToRoom(smile::vars->currentGhost, 0.f, 0);
		}

		//ImGui::LineSliderInt("Sound", &smile::vars->spookSoundEffect, 0, 10, 1);
		ImGui::CheckboxSlider("Random Spook", &smile::vars->randomSpook);
		ImGui::LineSliderFloat("Ghost Speed", &smile::vars->ghostSpeed, 0.5, 25.f, 1);
		if (smile::vars->randomSpook)
			ImGui::LineSliderInt("Spook Frequency", &smile::vars->spookFrequency, 0, 1000, 1);



		if (ImGui::Button("Use Cusom Coords", 5))
		{
			smile::vars->useCustom = true;
			smile::vars->x = smile::vars->currentGhost->GetPosition().fields.x;
			smile::vars->y = smile::vars->currentGhost->GetPosition().fields.y;
			smile::vars->z = smile::vars->currentGhost->GetPosition().fields.z;

			smile::vars->x1 = smile::vars->currentGhost->GetTransform()->GetRotation().fields.x;
			smile::vars->y1 = smile::vars->currentGhost->GetTransform()->GetRotation().fields.y;
			smile::vars->z1 = smile::vars->currentGhost->GetTransform()->GetRotation().fields.z;
			smile::vars->w = smile::vars->currentGhost->GetTransform()->GetRotation().fields.w;
		}

		if (smile::vars->useCustom)
		{
			ImGui::CheckboxSlider("use", &smile::vars->useCustom);
			ImGui::LineSliderFloat("pX", &smile::vars->x, -10.f, 10.f, 1.f);
			ImGui::LineSliderFloat("pY", &smile::vars->y, -10.f, 10.f, 1.f);
			ImGui::LineSliderFloat("pZ", &smile::vars->z, -10.f, 10.f, 1.f);

			ImGui::LineSliderFloat("rX", &smile::vars->x1, -20.f, 20.f, 1.f);
			ImGui::LineSliderFloat("rY", &smile::vars->y1, -20.f, 20.f, 1.f);
			ImGui::LineSliderFloat("rZ", &smile::vars->z1, -20.f, 20.f, 1.f);
			ImGui::LineSliderFloat("rW", &smile::vars->w, -20.f, 20.f, 1.f);

		}

		/*ImGui::LineSliderFloat("X", &smile::vars->x, -180.f, 180.f, 1);
		ImGui::LineSliderFloat("Y", &smile::vars->y, -180.f, 180.f, 1);
		ImGui::LineSliderFloat("Z", &smile::vars->z, -180.f, 180.f, 1);
		ImGui::LineSliderFloat("W", &smile::vars->w, -180.f, 180.f, 1);*/

		Network_o* network = NetworkGetInstance(0);
		if (network)
		{
			auto playerList = network->fields._2_players->fields._items;
			for (int i = 0; i < playerList->max_length; i++)
			{
				auto playerSpot = playerList->m_Items[i];
				if (!playerSpot)
					continue;

				Player_o* player = playerSpot->fields.player;
				if (!player)
					continue;

				System_String_o* playerName = playerSpot->fields.accountName;
				std::wstring wPName(playerName->fields.buffer);
				std::string sPName(wPName.begin(), wPName.end());


				ImGui::Separator();
				ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 15);
				ImGui::Text(sPName.c_str());
				ImGui::Text("Dead?:  %d", player->fields._1_dead);
				if (ImGui::Button("Revive", 5))
				{
					if (player->fields._1_dead)
						player->Revive();
				}

				if (ImGui::Button("Kill Fast", 5))
				{
					player->KillFast();
				}

				if (ImGui::Button("Kill Slow", 5))
				{
					player->StartKilling();
				}

				ImGui::Separator();

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
		ImGui::Text("Controlling Ghost: %d\n", smile::vars->controllingGhost);
		ImGui::Text("Ghost Walk Type: %d\n", smile::vars->controlGhostWalkType);

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
				if (smile::vars->rpcCalls[i].find("Ouija") != -1)
					ImGui::TextColored(ImVec4(130, 130, 255, 255), smile::vars->rpcCalls[i].c_str());
				else
					ImGui::Text(smile::vars->rpcCalls[i].c_str());
			}

			ImGui::EndChild();
		}
		ImGui::End();
	}
}
