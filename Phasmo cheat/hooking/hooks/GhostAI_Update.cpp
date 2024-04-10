#include "pch.h"
#include "../hook.h"
#include <ctime>
#include <iostream>
#include <random>

void HOOK::OnGhostControllerUpdate(GhostController_o* _this, const MethodInfo* method)
{
    if (!smile::vars->ghostController)
        smile::vars->ghostController = _this;

    return oUpdateGhostController(_this, method);
}

void HOOK::OnGhostUpdate(GhostAI_o* _this, MethodInfo* mInfo)
{
    static bool playedSound = false;
    static clock_t spookStartTime = std::clock();

    std::mt19937 rng(time(NULL));
    std::uniform_int_distribution<int> gen(0, 1000);
    int rand = (smile::vars->randomSpook ? gen(rng) : 0);


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
        smile::vars->spookPlayer = smile::vars->localPlayer;

        if (smile::vars->spookPlayer)
        {
            UnityEngine_Vector3_o playerPos = smile::vars->spookPlayer->GetPosition();
            UnityEngine_Vector3_o forward = smile::vars->spookPlayer->GetForward();
            UnityEngine_Vector3_o playerCamera = smile::vars->spookPlayer->GetCameraPosition();


            bool hit = false;
            auto results = CastRay(&playerCamera, &forward, FLT_MAX, 335644, 0, 0);
            if (results->max_length > 0 && results->m_Items[0].fields.m_Distance < 8.f)
            {
                //printf("hit! setting pos to hitpoint\n");
                auto hitPoint = results->m_Items[0].fields.m_Point;
                smile::vars->spookPos = hitPoint;
                hit = true;
            }

            if (!hit)
            {
                UnityEngine_Vector3_o ghostPos = playerPos + (forward * 2);
                UnityEngine_Vector3_o down{};
                down.fields.x = 0;
                down.fields.y = -1;
                down.fields.z = 0;

                auto results = CastRay(&ghostPos, &down, FLT_MAX, 335644, 0, 0);
                if (results->max_length > 0 && results->m_Items[0].fields.m_Distance < 8.f)
                {
                    //printf("missed, getting closer floor point!\n");
                    smile::vars->spookPos = results->m_Items[0].fields.m_Point;
                    hit = true;
                }
            }

            //if after 2 tries, the ray just cant hit the floor then just do nothing because itll be fucked up anyways
            if (!hit)
                return oUpdateGhost(_this, mInfo);

            spookStartTime = std::clock();
            playedSound = false;
            smile::vars->spookingPlayer = true;
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