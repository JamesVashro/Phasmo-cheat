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
    smile::vars->ghostState = _this->fields._1__________;

    if (smile::vars->showGhost)
        Appear(_this, 4, nullptr);

    if (GetAsyncKeyState(0x5A) & 1)
    {
        if (smile::vars->localPlayer)
        {
            UnityEngine_Vector3_o myPos = smile::vars->localPlayer->GetPosition();

            _this->GetTransform()->SetPosition(&myPos);
            
            auto curRoom = smile::vars->localPlayer->fields._10__________;
            ChangeFavRoom(smile::vars->ghostController, curRoom, 0);
        }
    }

    if (GetAsyncKeyState(VK_F1) & 1)
        InteractWithRandomProp(_this->fields._7__________, true, false, 0);

    if (GetAsyncKeyState(VK_F2) & 1)
    {
        RandomGhostEvent(_this, 0, -1, 0);
        //ChangeState(_this, 3, 0, 0, true, 0);
    }

    if (GetAsyncKeyState(VK_F3) & 1)
    {

        int v93 = 1;
        __int64 v63 = il2cppValueBox((__int64)smile::vars->bool_TypeInfo, (__int64)&v93);
        Il2CppObject* boxedBoolean = (Il2CppObject*)v63;

        int v94 = 0;
        __int64 v67 = il2cppValueBox((__int64)smile::vars->int_TypeInfo, (__int64)&v94);
        Il2CppObject* boxedInt = (Il2CppObject*)v67;

        System_Object_array* array = (System_Object_array*)il2cppArrayNewSpecific((__int64)smile::vars->object_TypeInfo, 2i64);

        array->m_Items[0] = boxedBoolean;
        array->m_Items[1] = boxedInt;


    }

    if (GetAsyncKeyState(0x50) & 1)
    {
        smile::vars->showGhost = !smile::vars->showGhost;
        printf("ShowGhost: %d\n", smile::vars->showGhost);
    }

    return oUpdateGhost(_this, mInfo);
}