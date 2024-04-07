#include "pch.h"
#include "../hook.h"

void HOOK::OnGhostControllerUpdate(GhostController_o* _this, const MethodInfo* method)
{
    smile::vars->ghostController = _this;
    return oUpdateGhostController(_this, method);
}

void HOOK::OnGhostUpdate(GhostAI_o* _this, MethodInfo* mInfo)
{
    if (smile::vars->currentGhost != _this)
        printf("Ghost: %p\n", _this);

    smile::vars->currentGhost = _this;
    smile::vars->ghostState = _this->fields._1_state;

    if (smile::vars->showGhost)
        Appear(_this, 4, nullptr);

    if (GetAsyncKeyState(VK_F5) & 1)
    {
        if (smile::vars->localPlayer)
        {
            UnityEngine_Vector3_o myPos = smile::vars->localPlayer->GetPosition();

            _this->GetTransform()->SetPosition(&myPos);
            
            auto curRoom = smile::vars->localPlayer->fields._10__________;
            ChangeFavRoom(smile::vars->ghostController, curRoom, 0);
            DelayTeleportToRoom(_this, 0.1f, 0);
        }
    }

    if (GetAsyncKeyState(VK_F1) & 1)
        ForceInteract(_this->fields._7_activity, true, 0);

    if (GetAsyncKeyState(VK_F2) & 1)
    {
        //RandomGhostEvent(_this, 0, -1, 0);
        ChangeState(_this, 14, 0, 0, true, 0);
    }

    if (GetAsyncKeyState(VK_F3) & 1)
        ChangeState(_this, 2, 0, 0, true, 0); //hunt

    if (GetAsyncKeyState(VK_F4) & 1)
    {
        smile::vars->showGhost = !smile::vars->showGhost;
        printf("ShowGhost: %d\n", smile::vars->showGhost);
    }

    return oUpdateGhost(_this, mInfo);
}