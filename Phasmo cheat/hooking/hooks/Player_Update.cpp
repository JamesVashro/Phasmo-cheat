#include "pch.h"
#include "../hook.h"
using namespace smile;

void HOOK::OnPlayerUpdate(Player_o* _this, MethodInfo* mInfo)
{
    vars->localPlayer = _this;

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

        HOOK::oRpc(vars->localPlayer->fields._________, SpawnDeadBodyNetworked, 0, (System_Object_array*)arr, 0);
    }

    return oUpdatePlayer(_this, mInfo);
}