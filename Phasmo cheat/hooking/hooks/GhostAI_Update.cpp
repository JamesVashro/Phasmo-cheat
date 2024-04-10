#include "pch.h"
#include "../hook.h"
#include <ctime>
#include <iostream>

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
        if (diff > 1)
        {
            smile::vars->spookingPlayer = false;
            playedSound = false;
            return oUpdateGhost(_this, mInfo);
        }

        Appear(_this, 4, nullptr); //2 shadow, 4 full model, 3 translusent

        auto transform = _this->GetTransform();

        transform->SetPosition(&smile::vars->spookPos);

        LookAtPlayer(_this, smile::vars->spookPlayer, 0);

        auto rot = transform->GetRotation();
        transform->SetRotation(0, rot.fields.y, 0, rot.fields.w);

        //TODO
        //3. play certain audio?

        if (!playedSound)
        {
            //gepPlaySound(smile::vars->ghostEventPlayer, smile::vars->localPlayer->fields._view->fields._Owner_k__BackingField, 0);
            _PlaySound(_this->fields._5_audio, smile::vars->spookSoundEffect, 0);
            //nPlaySound(smile::vars->ghostEventPlayer->fields.noise, smile::vars->ghostEventPlayer->fields.audioClip, 1, 0, 0, 0);
            playedSound = true;
        }
    }

    if (smile::vars->showGhost)
    {
        Appear(_this, 4, nullptr); //2 shadow, 4 full model, 3 translusent
    }

    if (GetAsyncKeyState(VK_F5) & 1)
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
                printf("hit! setting pos to hitpoint\n");
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
                    printf("missed, getting closer floor point!\n");
                    smile::vars->spookPos = results->m_Items[0].fields.m_Point;
                }
                else
                {
                    printf("%d\n", results->max_length);
                }
            }

            spookStartTime = std::clock();
            playedSound = false;
            smile::vars->spookingPlayer = true;
        }

        /*for (int i = 0; i < _this->fields._5_audio->fields.screamSoundClips->max_length; i++)
        {
           auto name = aGetName(_this->fields._5_audio->fields.screamSoundClips->m_Items[i], 0);
           wprintf(L"%ls\n", name->fields.buffer);
        }*/
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