#include "pch.h"
#include "../hook.h"
using namespace smile;

void HOOK::OnPlayerUpdate(Player_o* _this, MethodInfo* mInfo)
{
    
    if (_this != vars->localPlayer)
        return oUpdatePlayer(_this, mInfo);

    if (GetAsyncKeyState(0x58) & 1) // X
    {
        if (vars->localPlayer)
        {
            UnityEngine_Vector3_o dir = vars->localPlayer->GetMoveDir();
            UnityEngine_Vector3_o mypos = vars->localPlayer->GetPosition();
            UnityEngine_Vector3_o newpos = mypos + (dir * 2);

            vars->localPlayer->GetTransform()->SetPosition(newpos);
        }
    }

    if (GetAsyncKeyState(0x5A) & 1) //z key
    {
        vars->controllingGhost = !vars->controllingGhost;
       
        if (vars->controllingGhost && vars->currentGhost)
        {
            //Enable
            vars->cachedCam = GetMainCamera(0);
            reinterpret_cast<UnityEngine_Behaviour_o*>(vars->cachedCam)->SetEnabled(false);

            vars->ghostLight = UnityEngine_GameObject_o::CreatePrimitive(0);

            reinterpret_cast<UnityEngine_Object_o*>(vars->ghostLight)->DontDestroyOnLoad();
            UnityEngine_Light_o* light = reinterpret_cast<UnityEngine_Light_o*>(vars->ghostLight->AddComponent("UnityEngine.Light"));

            UnityEngine_Collider_o* collider = (UnityEngine_Collider_o*)vars->ghostLight->GetComponent("UnityEngine.Collider");
            if (collider)
                collider->SetEnabled(false);

            UnityEngine_Vector3_o pos = vars->currentGhost->GetPosition();
            auto lightTrans = reinterpret_cast<UnityEngine_Component_o*>(light)->GetTransform();
            lightTrans->SetPosition(pos);
            lightTrans->SetParent(*vars->currentGhost->GetTransform());

            light->SetColor(35, 0, 0, 0.1f);
            light->SetIntensity(0.001f);
            light->SetRange(6.f);

            System_String_o* camName = SystemStringCtor("freecam", 0, strlen("freecam"), 0);
            vars->ghostCam = (UnityEngine_Camera_o*)il2cppObjectNew((__int64)vars->cachedCam->klass->_1.klass);

            GameObjConstruct((UnityEngine_GameObject_o*)vars->ghostCam, camName, 0);

            reinterpret_cast<UnityEngine_GameObject_o*>(vars->ghostCam)->AddComponent("UnityEngine.Camera");

            reinterpret_cast<UnityEngine_GameObject_o*>(vars->ghostCam)->SetTag("MainCamera");

            reinterpret_cast<UnityEngine_Object_o*>(vars->ghostCam)->DontDestroyOnLoad();
            UnityEngine_Vector3_o iPos = vars->localPlayer->GetCameraPosition();
            vars->ghostCam->GetTransform()->SetPosition(iPos);


            vars->ghostCam->SetActive(true);


            System_String_o* nstr = SystemStringCtor("WalkType", 0, strlen("WalkType"), 0);
            System_String_o* nstr1 = SystemStringCtor("isIdle", 0, strlen("isIdle"), 0);

            HOOK::_SetBool(vars->currentGhost->fields._8_model->fields._3_animator, nstr1, 0, 0);
            HOOK::_SetInteger(vars->currentGhost->fields._8_model->fields._3_animator, nstr, vars->controlGhostWalkType, 0);


            /*UnityEngine_Collider_o* gCollider = (UnityEngine_Collider_o*)reinterpret_cast<UnityEngine_GameObject_o*>(vars->currentGhost)->GetComponent("UnityEngine.Collider");
            auto rigid = gCollider->GetRigidBody();
            rigid->SetUseGravity(false);
            rigid->SetIsKinematic(false);*/
        }
        else
        {
            //Disable
            reinterpret_cast<UnityEngine_Behaviour_o*>(vars->cachedCam)->SetEnabled(true);
            ObjectDestroy((UnityEngine_Object_o*)vars->ghostCam, 0.f, 0);
            ObjectDestroy((UnityEngine_Object_o*)vars->ghostLight, 0.f, 0);

        }
    }

    if (GetAsyncKeyState(VK_F9) & 1)
    {

    }
    if (GetAsyncKeyState(VK_F8) & 1)
    {
        if (vars->spookPlayer)
        {
            printf("killing\n");
            vars->spookPlayer->StartKilling();

        }
       /* try
        {
            Il2CppClass* boolTypeInfo = FUNCS::GetClass("mscorlib", "System", "Boolean");
            Il2CppClass* intTypeInfo = FUNCS::GetClass("mscorlib", "System", "Int32");
            Il2CppClass* genericList = FUNCS::GetClass("mscorlib", "System.Collections", "ArrayList");

            System_Collections_ArrayList_o* genArray = (System_Collections_ArrayList_o*)il2cppObjectNew((__int64)genericList);
            genArray->Construct();

            genArray->AddItem<bool>(false, boolTypeInfo);
            genArray->AddItem<int>(3, intTypeInfo);
            genArray->AddItem<bool>(false, boolTypeInfo);

            vars->ghostController->fields.view->SendRPC("CreateGhost", genArray->GetObjArray(), 3);
        }
        catch (...)
        {
            printf("fucked\n");
        }*/
        
    }
    return oUpdatePlayer(_this, mInfo);
}