﻿#include "pch.h"
#include <cstdio>
#include <iostream>
#include <thread>
#include "hooking/hook.h"
#include "hooking/memory.h"

#include "vars.h"
#include <menu.h>

#pragma comment(lib, "libMinHook.x64.lib")


FILE* f;

uintptr_t base{};

auto vars = std::make_unique<smile::Vars>();

bool InitializeHooks()
{
    MH_Initialize();

    if (!FUNCS::Init())
    {
        printf("couldnt init funcs\n");
        return false;
    }

    base = (uintptr_t)getModuleInfo("GameAssembly.dll").lpBaseOfDll;

    //GetMethodFromName = (uintptr_t)signature("48 89 5C 24 ? 48 89 6C 24 ? 56 57 41 56 48 83 EC 20 41 8B F1 41 8B D8 4C 8B F2 48 8B F9 E8 ? ? ? ?").import("GameAssembly.dll").GetPointer();
    //GetClassFromName = (uintptr_t)signature("48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 4D 8B E0 4C 8B EA 48 8B F9 48 83 79 ? ? 0F 85 ? ? ? ? ").import("GameAssembly.dll").GetPointer();

    //smile::vars->object_TypeInfo = (Il2CppClass*)signature("48 8D 0D ? ? ? ? 48 89 BC 24 ? ? ? ? E8 ? ? ? ? 48 8B C8 BA ? ? ? ? E8 ? ? ? ?").resolveRelativeAddr(3, 7);
    //smile::vars->int_TypeInfo = (System_Int32_c*)signature("48 8D 0D ? ? ? ? E8 ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? C6 05 ? ? ? ? ? 8B 47 10 48 8D 54 24 ?").resolveRelativeAddr(3, 7);
    //smile::vars->bool_TypeInfo = (System_Boolean_c*)signature("48 8D 0D ? ? ? ? E8 ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? 48 83 7B ? ? 75 08 48 8B CB E8 ? ? ? ?").resolveRelativeAddr(3, 7);

    //MainManager_o* manager = reinterpret_cast<MainManager_c*>(FUNCS::GetClass("Assembly-CSharp", "", "MainManager"))->static_fields->_________;

    vars->cursedICClass = reinterpret_cast<CursedItemsController_c*>(FUNCS::GetClass("Assembly-CSharp", "", "CursedItemsController"));
    
    //__int64 gCreateGhost = (__int64)signature("E9 ? ? ? ? E8 ? ? ? ? CC CC CC CC CC CC CC CC 40 53 48 83 EC 20 80 3D ? ? ? ? ? 48 8B D9 75 1F 48 8D 0D ? ? ? ? E8 ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? C6 05 ? ? ? ? ? 48 8B 83 ? ? ? ?").resolveRelativeAddr(1, 5);

    //hook((void*)gCreateGhost, (void*)HOOK::GhostController_CreateGhost, (void**)&HOOK::oCreateGhost);

    /*if (!HOOK::Hook((void*)gCreateGhost, HOOK::GhostController_CreateGhost, (void**)&HOOK::oCreateGhost))
        return false;*/

    //-15E
    //8B 4C 81 20 89 4C 24 30 48 8D 4C 24 ? E8 ? ? ? ? 48 8B 15 ? ? ? ? 45 33 C0 48 8B C8 E8 ? ? ? ? 48 8B 0D ? ? ? ? 48 8B E8 


    if (!HOOK::Hook(HOOK::getPresent(), HOOK::PresentHook, (void**)&HOOK::oPresent))
        return false;

    if (!HOOK::Hook((void*)(FUNCS::GetMethodPtr("", "GhostController", "Update", 0)), HOOK::OnGhostControllerUpdate, (void**)&HOOK::oUpdateGhostController))
        return false;

    if (!HOOK::Hook((void*)(signature("E8 ? ? ? ? 48 8B 0D ? ? ? ? 48 8B BE ? ? ? ? E8 ? ? ? ? 4C 8B 06 45 33 C9 48 8B D6").resolveRelativeAddr(1, 5)), HOOK::OnPlayMessageSequence, (void**)&HOOK::oPlayMessageSequence))
        return false;

    if (!HOOK::Hook((void*)(FUNCS::GetMethodPtr("", "Player", "Update", 0)), HOOK::OnPlayerUpdate, (void**)&HOOK::oUpdatePlayer))
        return false;

    if (!HOOK::Hook((void*)(FUNCS::GetMethodPtr("", "GhostAI", "Update", 0)), HOOK::OnGhostUpdate, (void**)&HOOK::oUpdateGhost))
        return false;

    if (!HOOK::Hook((void*)(FUNCS::GetMethodPtr("", "GhostEventPlayer", "Update", 0)), HOOK::OnGhostEventPlayerUpdate, (void**)&HOOK::oUpdateGhostEventPlayer))
        return false;

    if (!HOOK::Hook((void*)(FUNCS::GetMethodPtr("Photon.Pun", "PhotonView", "RPC", 3, "PhotonUnityNetworking")), HOOK::RPCFunc, (void**)&oRpc))
        return false;

    if (!HOOK::Hook((void*)(FUNCS::GetMethodPtr("", "FirstPersonController", "Update", 0, "Assembly-CSharp-firstpass")), HOOK::OnFPCUpdate, (void**)&HOOK::oUpdateFPC))
        return false;

    if (!HOOK::Hook((void*)(FUNCS::GetMethodPtr("", "FirstPersonController", "FixedUpdate", 0, "Assembly-CSharp-firstpass")), HOOK::OnFixedUpdateFPC, (void**)&HOOK::oFixedUpdateFPC))
        return false;

    if (!HOOK::Hook((void*)(FUNCS::GetMethodPtr("UnityEngine.AI", "NavMeshAgent", "SetDestination", 1, "UnityEngine.AIModule")), HOOK::SetDestination, (void**)&HOOK::_SetDestination))
        return false;

    if (!HOOK::Hook((void*)(FUNCS::GetMethodPtr("UnityEngine.AI", "NavMeshAgent", "set_destination", 1, "UnityEngine.AIModule")), HOOK::SetDestination2, (void**)&HOOK::_SetDestination2))
        return false;

    if (!HOOK::Hook((void*)(FUNCS::GetMethodPtr("UnityEngine", "Animator", "SetIntegerString", 2, "UnityEngine.AnimationModule")), HOOK::SetIntHk, (void**)&HOOK::_SetInteger))
        return false;

    if (!HOOK::Hook((void*)(FUNCS::GetMethodPtr("UnityEngine", "Animator", "SetBoolString", 2, "UnityEngine.AnimationModule")), HOOK::SetBoolHk, (void**)&HOOK::_SetBool))
        return false;

    //This hook is only good for finding the func address of the actual SpawnCursedItem func
    /*if (!HOOK::Hook((void*)signature("E8 ? ? ? ? 8B F8 EB 02 33 FF 48 8B 43 78 48 8B 73 20").resolveRelativeAddr(1, 5), HOOK::GetSpawnCursedItemHk, (void**)&HOOK::GetSpawnCursedItemHook))
        return false;*/

    if (!HOOK::Hook((void*)(((uintptr_t)signature("48 8B AF ? ? ? ? E8 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 48 8B 40 30 48 85 C0 0F 84 ? ? ? ? 48 8B 80 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 3B 58 18 0F 83 ? ? ? ? 48 85 ED").GetPointer(1)) - 0x1A5), HOOK::SpawnCursedItemHk, (void**)&HOOK::oSpawnCursedItem))
        return false;

    return true;
}

void CleanupAndShutDown(HMODULE mod)
{
    SetWindowLongPtr(menu.window, GWLP_WNDPROC, (LONG_PTR)HOOK::oWndProc);
    MH_Uninitialize();

    vars.reset();

    FreeConsole();
    fclose(f);

    CloseHandle(mod);
    FreeLibraryAndExitThread(mod, 0);
}

void MainThread(HMODULE mod)
{
    AllocConsole();
    freopen_s(&f, "CONOUT$", "w", stdout);

    if (!InitializeHooks())
    {
        printf("couldnt init hooks\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));


        CleanupAndShutDown(mod);
        return;
    }

    while (!smile::vars->waitinForEject)
    {
        if (GetAsyncKeyState(VK_DELETE) & 1)
        {
            smile::vars->waitinForEject = true;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        }
        //std::cout.put('.');
        
        //try
        //{   //spam setting this to the cursed item you want, forces the item to spawn, need to find the func that sets this and hook it
        //    if (vars->cursedICClass && vars->cursedICClass->static_fields && vars->cursedICClass->static_fields->_________)
        //    {
        //        vars->cursedIC = vars->cursedICClass->static_fields->_________;
        //        vars->cursedIC->fields._15_listEnum->fields._items->m_Items[0].cursedItemIndex = vars->forcedCursedItem;
        //    }
        //}
        //catch (...)
        //{
        //    printf("fuuuck\n");
        //}
        //std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }

    

    CleanupAndShutDown(mod);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)MainThread, hModule, NULL, NULL);
    }
    return TRUE;
}

