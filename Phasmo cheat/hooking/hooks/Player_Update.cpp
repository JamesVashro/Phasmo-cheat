#include "pch.h"
#include "../hook.h"
using namespace smile;

void HOOK::OnPlayerUpdate(Player_o* _this, MethodInfo* mInfo)
{
    smile::vars->localPlayer = _this;
    /*if (!smile::vars->network || !smile::vars->localPlayer)
    {
        smile::vars->network = NetworkGetInstance(0);

        if (smile::vars->network)
        {
            auto playerList = smile::vars->network->fields._2__________;

            for (int i = 0; i < playerList->fields._items->max_length; i++)
            {
                auto playerSpot = playerList->fields._items->m_Items[i];
                if (!playerSpot)
                    continue;

                if (playerSpot->fields.photonPlayer->fields.IsLocal)
                {
                    smile::vars->localPlayer = playerSpot->fields.player;
                    wprintf(L"set local Player: %ls\n", playerSpot->fields.accountName->fields.buffer);
                }
            }
        }
    }*/

    if (GetAsyncKeyState(0x58) & 1) // X
    {
        if (vars->localPlayer)
        {
            UnityEngine_Vector3_o dir = vars->localPlayer->GetMoveDir();
            UnityEngine_Vector3_o mypos = vars->localPlayer->GetPosition();
            UnityEngine_Vector3_o newpos = mypos + (dir * 2);

            vars->localPlayer->GetTransform()->SetPosition(&newpos);
        }
    }

    if (GetAsyncKeyState(VK_F6) & 1)
    {
        const char* mName = "SpawnDeadBodyNetworked";
        System_String_o* SpawnDeadBodyNetworked = SystemStringCtor(mName, 0, strlen(mName), 0);
        DWORD* arr = il2cppArrayNewSpecific((__int64)smile::vars->object_TypeInfo, 0);

        HOOK::oRpc(vars->localPlayer->fields._view, SpawnDeadBodyNetworked, 0, (System_Object_array*)arr, 0);
    }

    if (GetAsyncKeyState(0x5A) & 1) //z key
    {
        vars->controllingGhost = !vars->controllingGhost;
       
        if (vars->controllingGhost)
        {
            //Enable
            vars->cachedCam = GetMainCamera(0);
            reinterpret_cast<UnityEngine_Behaviour_o*>(vars->cachedCam)->SetEnabled(false);

            System_String_o* camName = SystemStringCtor("freecam", 0, strlen("freecam"), 0);
            vars->ghostCam = (UnityEngine_Camera_o*)il2cppObjectNew((__int64)vars->cachedCam->klass->_1.klass);

            GameObjConstruct((UnityEngine_GameObject_o*)vars->ghostCam, camName, 0);

            reinterpret_cast<UnityEngine_GameObject_o*>(vars->ghostCam)->AddComponent("UnityEngine.Camera");

            reinterpret_cast<UnityEngine_GameObject_o*>(vars->ghostCam)->SetTag("MainCamera");
            reinterpret_cast<UnityEngine_Object_o*>(vars->ghostCam)->DontDestroyOnLoad();

            UnityEngine_Vector3_o iPos = vars->localPlayer->GetCameraPosition();
            vars->ghostCam->GetTransform()->SetPosition(&iPos);


            vars->ghostCam->SetActive(true);
        }
        else
        {
            //Disable
            reinterpret_cast<UnityEngine_Behaviour_o*>(vars->cachedCam)->SetEnabled(true);
            ObjectDestroy((UnityEngine_Object_o*)vars->ghostCam, 0.f, 0);
        }
    }

    return oUpdatePlayer(_this, mInfo);
}