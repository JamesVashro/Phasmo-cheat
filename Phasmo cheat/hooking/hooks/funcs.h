#pragma once
#include <cstdint>
#include "hooking/memory.h"


struct PhotonObjectInteract_o;
struct GhostAI_o;
struct Player_o;
struct GhostActivity_o;
struct MethodInfo;
struct PhotonObjectInteract_o;
struct PhotonObjectInteract_array;
struct Door_o;
struct UnityEngine_Transform_o;
struct UnityEngine_Vector3_o;
struct UnityEngine_Component_o;
struct GhostController_o;
struct LevelRoom_o;
struct GhostEventPlayer_o;
struct System_Char_array;
struct System_String_o;
struct Il2CppClass;
struct Il2CppType;
struct Il2CppObject;

struct MethodInfo1
{
    void* methodPointer;
};

//possible PE type function
//void __stdcall UnityEngine_MonoBehaviour__Invoke(UnityEngine_MonoBehaviour_o *this, System_String_o *methodName, float time, const MethodInfo *method)

typedef __int64(__fastcall* il2cpp_value_box)(void* a1, void* a2);

typedef void(__stdcall* UnityEngine_Cursor__set_visible)(bool value, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Cursor__set_lockState)(int32_t value, const MethodInfo* method);
typedef int32_t(__stdcall* UnityEngine_Cursor__get_lockState)(const MethodInfo* method);

typedef void(__stdcall* System_String__CopyTo)(System_String_o* _this, int32_t sourceIndex, System_Char_array* destination, int32_t destinationIndex, int32_t count, const MethodInfo* method);
typedef void(__stdcall* GhostAI_Appear)(GhostAI_o*, int, MethodInfo*);
typedef void(__stdcall* GhostActivity__Interact)(GhostActivity_o* _this, const MethodInfo* method);
typedef PhotonObjectInteract_o* (__stdcall* GhostActivity__GetPropToThrow)(GhostActivity_o* _this, const MethodInfo* method);
typedef void(__stdcall* GhostActivity__ForceInteractWithProp)(GhostActivity_o* _this, bool _, const MethodInfo* method);
typedef void(__stdcall* GhostActivity__InteractWithARandomProp)(GhostActivity_o* _this, bool _, bool a3, const MethodInfo* method);
typedef void(__stdcall* GhostAI____________6465085056)(GhostAI_o* _this, bool _, int32_t a3, const MethodInfo* method);
typedef void(__stdcall* GhostAI__ChangeState)(GhostAI_o* _this, int32_t state, PhotonObjectInteract_o* object, PhotonObjectInteract_array* objects, bool _a, const MethodInfo* method);
typedef Door_o* (__stdcall* GhostActivity__GetDoorToOpen)(GhostActivity_o* _this, const MethodInfo* method);
typedef void(__stdcall* GhostController__ChangeFavouriteRoomTo)(GhostController_o* _this, LevelRoom_o* room, const MethodInfo* method);
typedef void(__stdcall* GhostAI____________6465066416)(GhostAI_o* _this, bool _, int32_t a3, const MethodInfo* method);
typedef void(__stdcall* Player__Teleport)(Player_o* _this, UnityEngine_Vector3_o* _, const MethodInfo* method);
typedef UnityEngine_Vector3_o* (__stdcall* UnityEngine_Transform__get_position)(UnityEngine_Vector3_o* retstr, UnityEngine_Transform_o* _this, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Transform__set_position)(UnityEngine_Transform_o* _this, UnityEngine_Vector3_o* value, const MethodInfo* method);
typedef UnityEngine_Transform_o* (__stdcall* UnityEngine_Component__get_transform)(UnityEngine_Component_o* _this, const MethodInfo* method);
typedef UnityEngine_Vector3_o* (__stdcall* UnityEngine_Transform__get_forward)(UnityEngine_Vector3_o* retstr, UnityEngine_Transform_o* _this, const MethodInfo* method);
typedef void(__stdcall* GhostAI__DelayTeleportToFavouriteRoom)(GhostAI_o* _this, float _, const MethodInfo* method);

typedef void(__stdcall* GhostEventPlayer____________6465199120)(GhostEventPlayer_o* _this, Player_o* _, UnityEngine_Vector3_o* a3, const MethodInfo* method);
typedef DWORD* (__fastcall* il2cpp_array_new_specific_0)(__int64 a1, unsigned __int64 a2);
typedef __int64(__fastcall* il2cpp_class_get_method_from_name)(Il2CppClass* clasz, const char* a2, __int64 a3);
typedef Il2CppClass*(__fastcall* il2cpp_class_from_name)(void* image, const char* namespaze, const char* name);
typedef void* (__fastcall* il2cpp_assembly_get_image)(void* assembly);
typedef void*(__fastcall* il2cpp_domain_assembly_open)(void* domain, const char* name);
typedef void* (__fastcall* il2cpp_domain_get)();
typedef Il2CppType* (__fastcall* il2cpp_class_get_type)(Il2CppClass* klass);
typedef Il2CppObject* (__fastcall* il2cpp_type_get_object)(Il2CppType* type);

typedef System_String_o* (__stdcall* System_String__Ctor_6497373952)(const char* value, int32_t startIndex, int32_t length, const MethodInfo* method);

inline UnityEngine_Cursor__set_visible SetCursorVisible{};
inline UnityEngine_Cursor__set_lockState SetLockState{};
inline UnityEngine_Cursor__get_lockState GetLockState{};

inline il2cpp_value_box il2cppValueBox{};
inline il2cpp_array_new_specific_0 il2cppArrayNewSpecific{};
inline il2cpp_class_get_method_from_name il2cppClassGetMethodFromName{};
inline il2cpp_class_from_name il2cppClassFromName{};
inline il2cpp_assembly_get_image il2cppAssemblyGetImage{};
inline il2cpp_domain_assembly_open il2cppDomainAssemblyOpen{};
inline il2cpp_domain_get il2cppDomainGet{};
inline il2cpp_class_get_type il2cppClassGetType{};
inline il2cpp_type_get_object il2cppTypeGetObject{};

inline System_String__Ctor_6497373952 SystemStringCtor{};
inline System_String__CopyTo CopyTo{};
inline UnityEngine_Component__get_transform _GetTransform{};
inline GhostAI_Appear Appear{};
inline GhostActivity__GetPropToThrow GetPropToThrow{};
inline GhostActivity__Interact Interact{};
inline GhostActivity__ForceInteractWithProp ForceInteract{};
inline GhostAI____________6465085056 RandomGhostEvent{};
inline GhostAI__ChangeState ChangeState{};
inline GhostActivity__GetDoorToOpen GetDoorToOpen{};
inline GhostController__ChangeFavouriteRoomTo ChangeFavRoom{};
inline Player__Teleport Teleport{};
inline UnityEngine_Transform__get_position _GetPosition{};
inline UnityEngine_Transform__set_position _SetPosition{};
inline UnityEngine_Transform__get_forward _GetForwardVector{};
inline GhostActivity__InteractWithARandomProp InteractWithRandomProp{};
inline GhostAI__DelayTeleportToFavouriteRoom DelayTeleportToRoom{};

namespace FUNCS
{
    inline void* GetFuncPtr(uint64_t offset)
    {
        static uintptr_t base = (uintptr_t)getModuleInfo("GameAssembly.dll").lpBaseOfDll;

        return (void*)(base + offset);
    }

    inline void* GetImage(const char* imageName)
    {
        void* assembly = il2cppDomainAssemblyOpen(il2cppDomainGet(), imageName);
        return il2cppAssemblyGetImage(assembly);
    }

    inline Il2CppClass* GetClass(const char* image, const char* namespaze, const char* className)
    {
        return il2cppClassFromName(GetImage(image), namespaze, className);
    }

    inline uint8_t* GetMethodPtr(const char* namespaze, const char* className, const char* funcName, int argCount, const char* image = "Assembly-CSharp")
    {
        const MethodInfo1* mInfo = (MethodInfo1*)il2cppClassGetMethodFromName(GetClass(image, namespaze, className), funcName, argCount);
        if (mInfo == NULL)
        {
            printf("MethodInfo returned null: %s\t%s\n", className, funcName);
            return nullptr;
        }
        return (uint8_t*)mInfo->methodPointer;
    }

	inline bool Init()
	{
        bool work = true;
        //
        HMODULE mod = GetModuleHandleA("GameAssembly.dll");

        SystemStringCtor = (System_String__Ctor_6497373952)signature("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 80 3D ? ? ? ? ? 41 8B D8 48 63 FA 48 8B F1 75 13 48 8D 0D ? ? ? ? E8 ? ? ? ? C6 05 ? ? ? ? ?").GetPointer();
        work &= (SystemStringCtor != 0);

        il2cppArrayNewSpecific = (il2cpp_array_new_specific_0)GetFuncPtr(0x2F1D80);
        work &= (il2cppArrayNewSpecific != 0);

        il2cppValueBox = (il2cpp_value_box)GetProcAddress(mod, "il2cpp_value_box");
        work &= (il2cppValueBox != 0);

        il2cppClassGetMethodFromName = (il2cpp_class_get_method_from_name)GetProcAddress(mod, "il2cpp_class_get_method_from_name");
        work &= (il2cppClassGetMethodFromName != 0);

        il2cppClassFromName = (il2cpp_class_from_name)GetProcAddress(mod, "il2cpp_class_from_name");
        work &= (il2cppClassFromName != 0);

        il2cppAssemblyGetImage = (il2cpp_assembly_get_image)GetProcAddress(mod, "il2cpp_assembly_get_image");
        work &= (il2cppAssemblyGetImage != 0);

        il2cppDomainAssemblyOpen = (il2cpp_domain_assembly_open)GetProcAddress(mod, "il2cpp_domain_assembly_open");
        work &= (il2cppDomainAssemblyOpen != 0);

        il2cppDomainGet = (il2cpp_domain_get)GetProcAddress(mod, "il2cpp_domain_get");
        work &= (il2cppDomainGet != 0);

        il2cppClassGetType = (il2cpp_class_get_type)GetProcAddress(mod, "il2cpp_class_get_type");
        work &= (il2cppClassGetType != 0);

        il2cppTypeGetObject = (il2cpp_type_get_object)GetProcAddress(mod, "il2cpp_type_get_object");
        work &= (il2cppTypeGetObject != 0);

        SetCursorVisible = (UnityEngine_Cursor__set_visible)(FUNCS::GetMethodPtr("UnityEngine", "Cursor", "set_visible", 1, "UnityEngine.CoreModule"));
        work &= (SetCursorVisible != 0);

        SetLockState = (UnityEngine_Cursor__set_lockState)(FUNCS::GetMethodPtr("UnityEngine", "Cursor", "set_lockState", 1, "UnityEngine.CoreModule"));
        work &= (SetLockState != 0);

        GetLockState = (UnityEngine_Cursor__get_lockState)(FUNCS::GetMethodPtr("UnityEngine", "Cursor", "get_lockState", 0, "UnityEngine.CoreModule"));
        work &= (GetLockState != 0);

        CopyTo = (System_String__CopyTo)GetFuncPtr(0x3460510);
        work &= (CopyTo != 0);

        _GetTransform = (UnityEngine_Component__get_transform)GetFuncPtr(0x436C770);
        work &= (_GetTransform != 0);

        _GetForwardVector = (UnityEngine_Transform__get_forward)GetFuncPtr(0x4380E70);
        work &= (_GetForwardVector != 0);

        _SetPosition = (UnityEngine_Transform__set_position)GetFuncPtr(0x4381C20);
        work &= (_SetPosition != 0);

        _GetPosition = (UnityEngine_Transform__get_position)GetFuncPtr(0x43813D0);
        work &= (_GetPosition != 0);

        Teleport = (Player__Teleport)GetMethodPtr("", "Player", "Teleport", 1);
        work &= (Teleport != 0);

        Appear = (GhostAI_Appear)GetMethodPtr("", "GhostAI", "Appear", 1);
        work &= (Appear != 0);

        Interact = (GhostActivity__Interact)GetMethodPtr("", "GhostActivity", "Interact", 0);
        work &= (Interact != 0);

        GetPropToThrow = (GhostActivity__GetPropToThrow)GetMethodPtr("", "GhostActivity", "GetPropToThrow", 0);
        work &= (GetPropToThrow != 0);

        ForceInteract = (GhostActivity__ForceInteractWithProp)GetMethodPtr("", "GhostActivity", "ForceInteractWithProp", 1);
        work &= (ForceInteract != 0);

        InteractWithRandomProp = (GhostActivity__InteractWithARandomProp)GetMethodPtr("", "GhostActivity", "InteractWithARandomProp", 2);
        work &= (InteractWithRandomProp != 0);

        RandomGhostEvent = (GhostAI____________6465085056)signature("E8 ?? ?? ?? ?? E9 ?? ?? ?? ?? 45 33 C9 4C 8B C5").resolveRelativeAddr(1, 5);
        work &= (RandomGhostEvent != 0);

        ChangeState = (GhostAI__ChangeState)GetMethodPtr("", "GhostAI", "ChangeState", 4);
        work &= (ChangeState != 0);

        GetDoorToOpen = (GhostActivity__GetDoorToOpen)GetMethodPtr("", "GhostActivity", "GetDoorToOpen", 0);
        work &= (GetDoorToOpen != 0);

        ChangeFavRoom = (GhostController__ChangeFavouriteRoomTo)GetMethodPtr("", "GhostController", "ChangeFavouriteRoomTo", 1);
        work &= (ChangeFavRoom != 0);

        DelayTeleportToRoom = (GhostAI__DelayTeleportToFavouriteRoom)GetMethodPtr("", "GhostAI", "DelayTeleportToFavouriteRoom", 1);
        work &= (DelayTeleportToRoom != 0);

        return work;
	}
}