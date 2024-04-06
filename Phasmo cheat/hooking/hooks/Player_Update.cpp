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
            //auto transform = HOOK::GetTransform(vars->currentGhost->fields._28__________, 0);
            UnityEngine_Vector3_o dir = vars->localPlayer->GetMoveDir();
            UnityEngine_Vector3_o mypos = vars->localPlayer->GetPosition();
            UnityEngine_Vector3_o newpos = mypos + (dir * 2);

            //Teleport(vars->localPlayer, &newpos, 0);
            vars->localPlayer->GetTransform()->SetPosition(&newpos);
            ////HOOK::RandomGhostEvent(smile::vars->currentGhost, false, -1, 0);
            //if (smile::vars->currentGhost->fields._1__________ == 0) //idle
            //{
            //    try
            //    {
            //        //smile::vars->currentGhost->fields._1__________ = 14;
            //        HOOK::ChangeState(smile::vars->currentGhost, 14, nullptr, nullptr, true, nullptr);
            //    }
            //    catch (...)
            //    {
            //        printf("fuck\n");
            //    }
            //}
        }
    }


    return oUpdatePlayer(_this, mInfo);
}