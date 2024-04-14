#include "pch.h"
#include "../hook.h"
#include <ctime>
#include <iostream>
#include <random>

template <typename T>
void DoInterceptedGhostMovement(UnityEngine_AI_NavMeshAgent_o* _this, T func, const MethodInfo* method)
{
    if (GetAsyncKeyState(VK_LSHIFT))
    {
        _this->SetSpeed(smile::vars->currentGhost->fields._22_ghostSpeed * 5);
    }
    else
    {
        _this->SetSpeed(smile::vars->currentGhost->fields._22_ghostSpeed);
    }

    if (GetAsyncKeyState(0x57)) //w
    {
        auto forward = smile::vars->currentGhost->GetTransform()->GetForwardVector();
        auto curPos = smile::vars->currentGhost->GetPosition();
        auto newPos = curPos + forward;

        func(_this, &newPos, method);
    }

    if (GetAsyncKeyState(0x53)) //S
    {
        auto back = (smile::vars->currentGhost->GetTransform()->GetForwardVector() * -1);
        auto curPos = smile::vars->currentGhost->GetPosition();
        auto newPos = curPos + back;

        func(_this, &newPos, method);
    }

    if (GetAsyncKeyState(0x44)) //D
    {
        auto right = smile::vars->currentGhost->GetTransform()->GetRightVector();
        auto curPos = smile::vars->currentGhost->GetPosition();
        auto newPos = curPos + right;

        func(_this, &newPos, method);
    }

    if (GetAsyncKeyState(0x41)) //A
    {
        auto left = (smile::vars->currentGhost->GetTransform()->GetRightVector() * -1);
        auto curPos = smile::vars->currentGhost->GetPosition();
        auto newPos = curPos + left;

        func(_this, &newPos, method);
    }
}
bool HOOK::SetDestination(UnityEngine_AI_NavMeshAgent_o* _this, UnityEngine_Vector3_o* target, const MethodInfo* method)
{
    if (smile::vars->controllingGhost)
    {
        DoInterceptedGhostMovement<UnityEngine_AI_NavMeshAgent__SetDestination>(_this, _SetDestination, method);
        return false;
    }

    if (!smile::vars->controllingGhost)
        return _SetDestination(_this, target, method);
}
void HOOK::SetDestination2(UnityEngine_AI_NavMeshAgent_o* _this, UnityEngine_Vector3_o* target, const MethodInfo* method)
{
    if (smile::vars->controllingGhost)
    {
        DoInterceptedGhostMovement<UnityEngine_AI_NavMeshAgent__SetDestination2>(_this, _SetDestination2, method);
        return;
    }

    if (!smile::vars->controllingGhost)
        return _SetDestination2(_this, target, method);
}

void HOOK::OnGhostControllerUpdate(GhostController_o* _this, const MethodInfo* method)
{
    if (!smile::vars->ghostController)
        smile::vars->ghostController = _this;

    return oUpdateGhostController(_this, method);
}

bool CheckDirection(UnityEngine_Vector3_o startPos, UnityEngine_Vector3_o direction)
{
    auto res = CastRay(&startPos, &direction, 2.5, -5, 0, 0);
    if (res->max_length > 0)
    {
        for (int i = 0; i < res->max_length; i++)
        {
            UnityEngine_Collider_o* collider = GetCollider(&res->m_Items[i], 0);
            auto gameObj = GetGameObject((UnityEngine_Component_o*)collider, 0);

            auto str = ObjectGetName((UnityEngine_Object_o*)gameObj, 0);
            std::wstring wstr(str->fields.buffer);

            if (wstr.find(L"Wall") != -1)
            {
                return false;
                break;
            }
        }
    }

    return true;
}


void DoGhostControls(GhostAI_o* _this)
{
    static clock_t lastForwardTime = std::clock();
    if (GetAsyncKeyState(VK_LSHIFT))
    {
        _this->fields._4_NavMeshAgent->SetSpeed(_this->fields._22_ghostSpeed * 5);
    }
    else
    {
        _this->fields._4_NavMeshAgent->SetSpeed(_this->fields._22_ghostSpeed);
    }

    if (GetAsyncKeyState(0x57)) //w
    {
        auto forward = _this->GetTransform()->GetForwardVector();
        auto curPos = _this->GetPosition();
        auto newPos = curPos + forward;

        HOOK::_SetDestination(_this->fields._4_NavMeshAgent, &newPos, 0);
    }

    if (GetAsyncKeyState(0x53)) //S
    {
        auto back = (_this->GetTransform()->GetForwardVector() * -1);
        auto curPos = _this->GetPosition();
        auto newPos = curPos + back;

        HOOK::_SetDestination(_this->fields._4_NavMeshAgent, &newPos, 0);

    }

    if (GetAsyncKeyState(0x44)) //D
    {
        auto right = _this->GetTransform()->GetRightVector();
        auto curPos = _this->GetPosition();
        auto newPos = curPos + right;

        HOOK::_SetDestination(_this->fields._4_NavMeshAgent, &newPos, 0);
    }

    if (GetAsyncKeyState(0x41)) //A
    {
        auto left = (_this->GetTransform()->GetRightVector() * -1);
        auto curPos = _this->GetPosition();
        auto newPos = curPos + left;

        HOOK::_SetDestination(_this->fields._4_NavMeshAgent, &newPos, 0);
    }
}

void HOOK::OnGhostUpdate(GhostAI_o* _this, MethodInfo* mInfo)
{
    if (smile::vars->waitinForEject)
        return oUpdateGhost(_this, mInfo);

    if (smile::vars->controllingGhost)
        DoGhostControls(_this);

    static bool playedSound = false;
    static clock_t spookStartTime = std::clock();
    static float originalSpeed = -1;
    static UnityEngine_Vector3_o oRayPos{};

    std::mt19937 rng(time(NULL));
    std::uniform_int_distribution<int> gen(0, 1000);
    int rand = (smile::vars->randomSpook ? gen(rng) : 0);

    
    //printf("%f   %f   %f\n", _this->fields._15_float1, _this->fields._22_ghostSpeed, _this->fields._23_float3);
    //printf("%f   %f   %f\n===================\n", _this->fields._24_float4, _this->fields._34_float5, _this->fields._52_float6);

    if (smile::vars->currentGhost != _this)
    {
        printf("Ghost: %p\n", _this);
    }

    smile::vars->currentGhost = _this;
    smile::vars->ghostState = _this->fields._1_state;

    if (smile::vars->spookingPlayer)
    {
        clock_t curTime = clock();
        auto diff = (clock() - spookStartTime) / CLOCKS_PER_SEC;
        if (diff > 0.5f)
        {
            smile::vars->spookingPlayer = false;
            playedSound = false;
            UnAppear(_this, 0);
            _this->fields._4_NavMeshAgent->SetSpeed(_this->fields._22_ghostSpeed);
            return oUpdateGhost(_this, mInfo);
        }

        Appear(_this, 4, nullptr); //2 shadow, 4 full model, 3 translusent

        auto transform = _this->GetTransform();

        transform->SetPosition(&smile::vars->spookPos);

        LookAtPlayer(_this, smile::vars->spookPlayer, 0);

        auto rot = transform->GetRotation();
        transform->SetRotation(0, rot.fields.y, 0, rot.fields.w);


        if (!playedSound)
        {
            TurnOnOrOffAppearSource(_this->fields._5_audio, true, true, 0);
            PlayOrStopAppearSource(_this->fields._5_audio, true, 0);

            //gepPlaySound(smile::vars->ghostEventPlayer, smile::vars->localPlayer->fields._view->fields._Owner_k__BackingField, 0);
            //_PlaySound(_this->fields._5_audio, smile::vars->spookSoundEffect, 0);
            //nPlaySound(smile::vars->ghostEventPlayer->fields.noise, smile::vars->ghostEventPlayer->fields.audioClip, 1, 0, 0, 0);
            playedSound = true;
        }
    }

    if (smile::vars->showGhost)
    {
        Appear(_this, 4, nullptr); //2 shadow, 4 full model, 3 translusent
    }

    if ((smile::vars->randomSpook && (!smile::vars->spookingPlayer && rand <= smile::vars->spookFrequency)) || GetAsyncKeyState(VK_F5) & 1)
    {
        auto network = NetworkGetInstance(0);

        if (!network || !network->fields._2_players)
            return oUpdateGhost(_this, mInfo);

        auto players = network->fields._2_players->fields._items->max_length;
        std::uniform_int_distribution<int> gen1(0, players);
        
        Network_PlayerSpot_o* spookSpot = nullptr;

        while (!spookSpot)
        {
            int randP = gen1(rng);
            spookSpot = network->fields._2_players->fields._items->m_Items[randP];
        }

        _this->fields._4_NavMeshAgent->SetSpeed(5.7);
        smile::vars->spookPlayer = spookSpot->fields.player;

        if (smile::vars->spookPlayer)
        {
            UnityEngine_Vector3_o playerPos = smile::vars->spookPlayer->GetPosition();
            UnityEngine_Vector3_o forward = smile::vars->spookPlayer->GetForward();
            UnityEngine_Vector3_o right = smile::vars->spookPlayer->GetRight();
            UnityEngine_Vector3_o left = right * -1;
            UnityEngine_Vector3_o playerCamera = smile::vars->spookPlayer->GetCameraPosition();

            bool hit = false;
            bool hitwall = false;
            float hitDist = 0.f;
            bool rightGood = false;
            bool leftGood = false;

            //335644 floor mask

            auto wallResults = CastRay(&playerCamera, &forward, 6, -5, 0, 0); //raycast for wall first
            if (wallResults->max_length > 0)
            {
                for (int i = 0; i < wallResults->max_length; i++)
                {
                    UnityEngine_Collider_o* collider = GetCollider(&wallResults->m_Items[i], 0);
                    auto gameObj = GetGameObject((UnityEngine_Component_o*)collider, 0);

                    auto str = ObjectGetName((UnityEngine_Object_o*)gameObj, 0);
                    std::wstring wstr(str->fields.buffer);
                    //wprintf(L"\n%d: %ls\n", i, str->fields.buffer);

                    if (wstr.find(L"Wall") != -1)
                    {
                        hitwall = true;
                        hitDist = wallResults->m_Items[i].fields.m_Distance;
                        break;
                    }
                }
            }

            if (!hitwall) //if no wall hit, raycast for floor and use that point
            {
                auto floorResults = CastRay(&playerCamera, &forward, 6, 335644, 0, 0);
                if (floorResults->max_length > 0)
                {
                    
                    printf("hit floor! spawning at hitpoint\n");
                    UnityEngine_Collider_o* collider = GetCollider(&wallResults->m_Items[0], 0);
                    auto gameObj = GetGameObject((UnityEngine_Component_o*)collider, 0);

                    auto str = ObjectGetName((UnityEngine_Object_o*)gameObj, 0);
                    // std::wstring wstr(str->fields.buffer);
                    wprintf(L"%ls\n", str->fields.buffer);
                    auto hitPoint = floorResults->m_Items[0].fields.m_Point;
                    smile::vars->spookPos = hitPoint;
                    hit = true;
                    
                    
                }
            }

            if (hitwall) //wall raycast hit a wall, decide where to spawn ghost
            {
                if (hitDist <= 3.f) //player is to close to wall to jumpscare, spawn ghost either to right or left of player
                {
                    printf("to close to wall!\n");
                    
                    rightGood = CheckDirection(playerCamera, right);
                    leftGood = CheckDirection(playerCamera, left);

                    std::uniform_int_distribution<int> gen2(0, 1);
                    int rand = gen2(rng);

                    //holy moly i have no idea why i wanted to make this in this format but... good luck
                    UnityEngine_Vector3_o ghostPos = playerPos +
                        (!rightGood && !leftGood ? forward * (hitDist < 2.5f ? 1.5f : (hitDist > 3.f ? -2 : 2)) :
                            (rightGood && leftGood ? (rand == 0 ? right * 2 : left * 2) : 
                                (rightGood && !leftGood ? right * 2 : 
                                    (!rightGood && leftGood ? left * 2 : forward * -2))));

                    ghostPos.fields.y += 3; //adjust start point incase ghostPos was originally in the floor a little
                    UnityEngine_Vector3_o down{};
                    down.fields.x = 0;
                    down.fields.y = -1;
                    down.fields.z = 0;

                    auto results = CastRay(&ghostPos, &down, FLT_MAX, 335644, 0, 0); //ghost can spawn in the air, raycast to floor and spawn ghost there.
                    if (results->max_length > 0 && results->m_Items[0].fields.m_Distance < 8.f)
                    {
                        smile::vars->spookPos = results->m_Items[0].fields.m_Point;
                        hit = true;
                    }
                }
            }

            if (!hit) //if didnt hit anything within 6m, spawn ghost 2m infront of player
            {
                UnityEngine_Vector3_o ghostPos = playerPos + (forward * 2);
                ghostPos.fields.y += 3;
                UnityEngine_Vector3_o down{};
                down.fields.x = 0;
                down.fields.y = -1;
                down.fields.z = 0;

                auto results = CastRay(&ghostPos, &down, FLT_MAX, 335644, 0, 0);
                if (results->max_length > 0 && results->m_Items[0].fields.m_Distance < 8.f)
                {
                    if (hitwall)
                        printf("hit wall, getting close floor point!\n");
                    else
                        printf("missed, getting close floor point!\n");

                    smile::vars->spookPos = results->m_Items[0].fields.m_Point;
                    hit = true;
                }
            }

            //if something went wrong just do nothing
            if (!hit && !hitwall)
                return oUpdateGhost(_this, mInfo);

            spookStartTime = std::clock();
            playedSound = false;
            smile::vars->spookingPlayer = true;
            smile::vars->spookRayStartPos = playerCamera;
        }
    }

    if (GetAsyncKeyState(VK_F1) & 1)
    {
        /*auto interaction = _this->fields._6_interaction;
        interaction->fields.footstepSpawnPoint = smile::vars->localPlayer->GetTransform();
        SpawnFootstep(interaction, false, 0);*/
        ForceInteract(_this->fields._7_activity, true, 0);
    }
    

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