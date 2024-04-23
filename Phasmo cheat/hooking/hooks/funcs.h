﻿#pragma once
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
struct UnityEngine_MonoBehaviour_o;
struct Network_o;
struct UnityEngine_GameObject_o;
struct UnityEngine_Quaternion_o;
struct GhostAudio_o;
struct UnityEngine_AudioClip_o;
struct Noise_o;
struct Photon_Realtime_Player_o;
struct UnityEngine_RaycastHit_array;
struct UnityEngine_Color_o;
struct UnityEngine_Camera_o;
struct UnityEngine_Resolution_o;
struct UnityEngine_Collider_o;
struct UnityEngine_RaycastHit_o;
struct UnityEngine_Object_o;
struct UnityEngine_AI_NavMeshAgent_o;
struct GhostInteraction_o;
struct UnityEngine_Camera_array;
struct System_Type_o;
struct UnityEngine_Behaviour_o;
struct MouseLook_o;
struct FirstPersonController_o;
struct UnityEngine_Animator_o;
struct UnityEngine_Bounds_o;
struct UnityEngine_Renderer_o;
struct UnityEngine_Rigidbody_o;
struct UnityEngine_Component_array;
struct UnityEngine_Light_o;
struct GameController_c;
struct GhostModel_o;
struct Photon_Pun_PhotonView_o;
struct System_Object_array;
struct System_Array_o;
struct System_Collections_ArrayList_o;
struct TarotCard_o;
struct TarotCards_o;
struct CursedItemsController_o;


struct MethodInfo1
{
    void* methodPointer;
};

//possible PE type function
//void __stdcall UnityEngine_MonoBehaviour__Invoke(UnityEngine_MonoBehaviour_o *this, System_String_o *methodName, float time, const MethodInfo *method)

typedef void(__stdcall* TarotCard____________6472688672)(TarotCard_o* _this, const MethodInfo* method);

typedef void(__stdcall* Photon_Pun_PhotonView__RPC)(Photon_Pun_PhotonView_o* _this, System_String_o* methodName, int32_t target, System_Object_array* parameters, const MethodInfo* method);

typedef __int64(__fastcall* weirdInitParamsFunc)(__int64 arrayIndexPtr, __int64 value);
typedef Network_o* (__stdcall* Network__get_Instance)(const MethodInfo* method);
typedef Il2CppObject*(__fastcall* il2cpp_value_box)(Il2CppClass* classType, void* value);

typedef void(__stdcall* Photon_Pun_PhotonView__RPC_6500903728)(Photon_Pun_PhotonView_o* _this, System_String_o* methodName, Photon_Realtime_Player_o* targetPlayer, System_Object_array* parameters, const MethodInfo* method);

typedef UnityEngine_GameObject_o* (__stdcall* UnityEngine_GameObject__CreatePrimitive)(int32_t type, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Light__set_color)(UnityEngine_Light_o* _this, UnityEngine_Color_o* value, const MethodInfo* method);

typedef UnityEngine_Rigidbody_o* (__stdcall* UnityEngine_Collider__get_attachedRigidbody)(UnityEngine_Collider_o* _this, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Renderer__set_localBounds)(UnityEngine_Renderer_o* _this, UnityEngine_Bounds_o* value, const MethodInfo* method);
typedef UnityEngine_Bounds_o* (__stdcall* UnityEngine_Renderer__get_bounds)(UnityEngine_Bounds_o* retstr, UnityEngine_Renderer_o* _this, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Light__set_intensity)(UnityEngine_Light_o* _this, float value, const MethodInfo* method);

typedef int32_t(__stdcall* UnityEngine_Screen__get_height)(const MethodInfo* method);
typedef UnityEngine_Camera_o* (__stdcall* UnityEngine_Camera__get_main)(const MethodInfo* method);
typedef UnityEngine_Vector3_o* (__stdcall* UnityEngine_Camera__WorldToScreenPoint)(UnityEngine_Vector3_o* retstr, UnityEngine_Camera_o* _this, UnityEngine_Vector3_o* position, int32_t eye, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Cursor__set_visible)(bool value, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Cursor__set_lockState)(int32_t value, const MethodInfo* method);
typedef int32_t(__stdcall* UnityEngine_Cursor__get_lockState)(const MethodInfo* method);
typedef void(__stdcall* UnityEngine_GameObject__SetActive)(UnityEngine_GameObject_o* _this, bool value, const MethodInfo* method);
typedef UnityEngine_GameObject_o* (__stdcall* UnityEngine_Component__get_gameObject)(UnityEngine_Component_o* _this, const MethodInfo* method);
typedef UnityEngine_Quaternion_o* (__fastcall* UnityEngine_Transform__get_rotation)(UnityEngine_Quaternion_o* retstr, UnityEngine_Transform_o* _this, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Transform__set_rotation)(UnityEngine_Transform_o* _this, UnityEngine_Quaternion_o* value, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Transform__LookAt)(UnityEngine_Transform_o* _this, UnityEngine_Transform_o* target, UnityEngine_Vector3_o* worldUp, const MethodInfo* method);
typedef UnityEngine_Transform_o* (__stdcall* UnityEngine_Transform__GetRoot)(UnityEngine_Transform_o* _this, const MethodInfo* method);
typedef System_String_o* (__stdcall* UnityEngine_AudioClip__GetName)(UnityEngine_AudioClip_o* _this, const MethodInfo* method);
typedef UnityEngine_RaycastHit_array* (__stdcall* UnityEngine_Physics__RaycastAll)(UnityEngine_Vector3_o* origin, UnityEngine_Vector3_o* direction, float maxDistance, int32_t layerMask, int32_t queryTriggerInteraction, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Debug__DrawLine)(UnityEngine_Vector3_o* start, UnityEngine_Vector3_o* end, UnityEngine_Color_o* color, float duration, const MethodInfo* method);
typedef int32_t(__stdcall* UnityEngine_LayerMask__NameToLayer)(System_String_o* layerName, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Gizmos__DrawLine)(UnityEngine_Vector3_o* from, UnityEngine_Vector3_o* to, const MethodInfo* method);
typedef System_String_o* (__stdcall* UnityEngine_Component__get_tag)(UnityEngine_Component_o* _this, const MethodInfo* method);
typedef UnityEngine_Collider_o* (__stdcall* UnityEngine_RaycastHit__get_collider)(UnityEngine_RaycastHit_o* _this, const MethodInfo* method);
typedef System_String_o* (__stdcall* UnityEngine_Object__GetName)(UnityEngine_Object_o* obj, const MethodInfo* method);
typedef UnityEngine_Vector3_o* (__stdcall* UnityEngine_Transform__get_right)(UnityEngine_Vector3_o* retstr, UnityEngine_Transform_o* _this, const MethodInfo* method);
typedef UnityEngine_Vector3_o* (__stdcall* UnityEngine_Transform__get_forward)(UnityEngine_Vector3_o* retstr, UnityEngine_Transform_o* _this, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Camera__CopyFrom)(UnityEngine_Camera_o* _this, UnityEngine_Camera_o* other, const MethodInfo* method);
typedef void(__stdcall* MouseLook__LookRotation)(MouseLook_o* _this, UnityEngine_Transform_o* character, UnityEngine_Transform_o* camera, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Animator__set_speed)(UnityEngine_Animator_o* _this, float value, const MethodInfo* method);

typedef void(__stdcall* UnityEngine_Collider__set_enabled)(UnityEngine_Collider_o* _this, bool value, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Transform__set_parent)(UnityEngine_Transform_o* _this, UnityEngine_Transform_o* value, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Object__Destroy)(UnityEngine_Object_o* obj, float t, const MethodInfo* method);
typedef UnityEngine_Transform_o* (__stdcall* UnityEngine_GameObject__get_transform)(UnityEngine_GameObject_o* _this, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Behaviour__set_enabled)(UnityEngine_Behaviour_o* _this, bool value, const MethodInfo* method);
typedef System_Type_o* (__stdcall* System_Type__GetType_6498422912)(System_String_o* typeName, const MethodInfo* method);
typedef UnityEngine_Component_o* (__stdcall* UnityEngine_GameObject__AddComponent)(UnityEngine_GameObject_o* _this, System_Type_o* componentType, const MethodInfo* method);
typedef int32_t(__stdcall* UnityEngine_Object__get_hideFlags)(UnityEngine_Object_o* _this, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Object__set_hideFlags)(UnityEngine_Object_o* _this, int32_t value, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_GameObject__set_tag)(UnityEngine_GameObject_o* _this, System_String_o* value, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_GameObject___ctor)(UnityEngine_GameObject_o* _this, System_String_o* name, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Object__DontDestroyOnLoad)(UnityEngine_Object_o* target, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_AI_NavMeshAgent__set_speed)(UnityEngine_AI_NavMeshAgent_o* _this, float value, const MethodInfo* method);
typedef float(__stdcall* UnityEngine_AI_NavMeshAgent__get_speed)(UnityEngine_AI_NavMeshAgent_o* _this, const MethodInfo* method);

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
typedef void(__stdcall* GhostAI__DelayTeleportToFavouriteRoom)(GhostAI_o* _this, float _, const MethodInfo* method);
typedef void(__stdcall* GhostAI__LookAtPlayer)(GhostAI_o* _this, Player_o* _, const MethodInfo* method);
typedef void(__stdcall* GhostAudio__PlaySound)(GhostAudio_o* _this, int32_t clipIndex, const MethodInfo* method);
typedef void(__stdcall* Noise__PlaySound)(Noise_o* _this, UnityEngine_AudioClip_o* _, float a3, bool a4, bool _a, const MethodInfo* method);
typedef void(__stdcall* GhostEventPlayer__PlaySound)(GhostEventPlayer_o* _this, Photon_Realtime_Player_o* _, const MethodInfo* method);
typedef void(__stdcall* GhostAudio__TurnOnOrOffAppearSource)(GhostAudio_o* _this, bool _, bool a3, const MethodInfo* method);
typedef void(__stdcall* GhostAudio__PlayOrStopAppearSource)(GhostAudio_o* _this, bool _, const MethodInfo* method);
typedef void(__stdcall* GhostInteraction_____SpawnFootstep____6465324256)(GhostInteraction_o* _this, bool _, const MethodInfo* method);
typedef void(__stdcall* FirstPersonController__GetInput)(FirstPersonController_o* _this, const MethodInfo* method);

typedef void(__stdcall* Player__RevivePlayer)(Player_o* _this, const MethodInfo* method);


typedef void(__stdcall* System_Collections_ArrayList___ctor)(System_Collections_ArrayList_o* _this, const MethodInfo* method);
typedef int32_t(__stdcall* System_Collections_ArrayList__Add)(System_Collections_ArrayList_o* _this, Il2CppObject* value, const MethodInfo* method);

typedef void(__stdcall* GhostAI__UnAppear)(GhostAI_o* _this, const MethodInfo* method);
typedef void(__stdcall* GhostEventPlayer____________6465199120)(GhostEventPlayer_o* _this, Player_o* _, UnityEngine_Vector3_o* a3, const MethodInfo* method);
typedef System_Object_array* (__fastcall* il2cpp_array_new_specific_0)(Il2CppClass* classType, unsigned __int64 arraySize);
typedef __int64(__fastcall* il2cpp_object_new)(__int64 a1);
typedef __int64(__fastcall* il2cpp_class_get_method_from_name)(Il2CppClass* clasz, const char* a2, __int64 a3);
typedef Il2CppClass*(__fastcall* il2cpp_class_from_name)(void* image, const char* namespaze, const char* name);
typedef void* (__fastcall* il2cpp_assembly_get_image)(void* assembly);
typedef void*(__fastcall* il2cpp_domain_assembly_open)(void* domain, const char* name);
typedef void* (__fastcall* il2cpp_domain_get)();
typedef Il2CppType* (__fastcall* il2cpp_class_get_type)(Il2CppClass* klass);
typedef Il2CppObject* (__fastcall* il2cpp_type_get_object)(Il2CppType* type);
typedef void(__fastcall* il2cpp_runtime_class_init)(Il2CppClass* klass);
typedef System_String_o* (__stdcall* System_String__Ctor_6497373952)(const char* value, int32_t startIndex, int32_t length, const MethodInfo* method);

typedef UnityEngine_Collider_o* (__stdcall* UnityEngine_Physics__GetColliderByInstanceID)(int32_t instanceID, const MethodInfo* method);
typedef int32_t(__stdcall* UnityEngine_Object__GetInstanceID)(UnityEngine_Object_o* _this, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Rigidbody__set_useGravity)(UnityEngine_Rigidbody_o* _this, bool value, const MethodInfo* method);
typedef UnityEngine_Component_array* (__stdcall* UnityEngine_GameObject__GetComponents)(UnityEngine_GameObject_o* _this, System_Type_o* type, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Light__set_range)(UnityEngine_Light_o* _this, float value, const MethodInfo* method);

typedef void(__stdcall* UnityEngine_AI_NavMeshAgent__set_acceleration)(UnityEngine_AI_NavMeshAgent_o* _this, float value, const MethodInfo* method);
typedef UnityEngine_Component_o* (__stdcall* UnityEngine_GameObject__GetComponent)(UnityEngine_GameObject_o* _this, System_Type_o* type, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Rigidbody__set_isKinematic)(UnityEngine_Rigidbody_o* _this, bool value, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Rigidbody__AddForce)(UnityEngine_Rigidbody_o* _this, UnityEngine_Vector3_o* force, int32_t mode, const MethodInfo* method);

typedef void(__stdcall* GhostAI__FlashAppear)(GhostAI_o* _this, const MethodInfo* method);
typedef void(__stdcall* GhostAI__SetGhostModel_6465062688)(GhostAI_o* _this, GhostModel_o* _, bool a3, const MethodInfo* method);
typedef void(__stdcall* GhostAI__SetGhostModel)(GhostAI_o* _this, int _, bool a3, const MethodInfo* method);

typedef __int64* (__fastcall* idkwtf)(__int64 a1, __int64 a2);

typedef __int64(__fastcall* il2cpp_type_get_name)(__int64 a1);

typedef void(__stdcall* Player__KillPlayer)(Player_o* _this, bool _, const MethodInfo* method);
typedef void(__stdcall* Player__StartKillingPlayer)(Player_o* _this, const MethodInfo* method);


typedef System_Object_array* (__stdcall* System_Collections_ArrayList__ToArray)(System_Collections_ArrayList_o* _this, const MethodInfo* method);

inline UnityEngine_GameObject__CreatePrimitive _CreatePrimitive{};
inline UnityEngine_Collider__set_enabled _ColliderSetEnabled{};
inline UnityEngine_AI_NavMeshAgent__set_acceleration _SetAcceleration{};
inline UnityEngine_Rigidbody__set_isKinematic _SetIsKinematic{};
inline UnityEngine_Rigidbody__AddForce _AddForce{};

inline UnityEngine_Light__set_color LightSetColor{};
inline UnityEngine_Light__set_intensity LightSetIntensity{};
inline weirdInitParamsFunc InitParam{};

inline TarotCard____________6472688672 card{};

inline Photon_Pun_PhotonView__RPC_6500903728 TargettedRPC{};
inline UnityEngine_GameObject__GetComponent _GetComponent{};
inline UnityEngine_GameObject__GetComponents _GetComponents{};
inline UnityEngine_Rigidbody__set_useGravity _SetUseGravity{};
inline UnityEngine_Object__GetInstanceID _GetInstanceID{};
inline UnityEngine_Physics__GetColliderByInstanceID GetColliderByInstanceID{};
inline UnityEngine_Collider__get_attachedRigidbody _GetRigidBody{};
inline UnityEngine_Renderer__set_localBounds _SetBounds{};
inline UnityEngine_Renderer__get_bounds _GetBounds{};
inline UnityEngine_Cursor__set_visible SetCursorVisible{};
inline UnityEngine_Cursor__set_lockState SetLockState{};
inline UnityEngine_Cursor__get_lockState GetLockState{};
inline UnityEngine_Physics__RaycastAll CastRay{};
inline UnityEngine_Debug__DrawLine DebugDrawLine{};
inline UnityEngine_Gizmos__DrawLine GizmoDrawLine{};
inline UnityEngine_LayerMask__NameToLayer NameToLayer{};
inline UnityEngine_Camera__WorldToScreenPoint WorldToScreen{};
inline UnityEngine_Camera__get_main GetMainCamera{};
inline UnityEngine_Screen__get_height GetScreenHeight{};
inline UnityEngine_Component__get_tag ComponentGetTag{};
inline UnityEngine_RaycastHit__get_collider GetCollider{};
inline UnityEngine_Object__GetName ObjectGetName{};
inline UnityEngine_Camera__CopyFrom _CopyFrom{};
inline UnityEngine_Animator__set_speed _AnimatorSetSpeed{};

inline GhostAI__SetGhostModel_6465062688 _SetGhostModel{};
inline GhostAI__SetGhostModel _SetGhostModelInt{};

inline UnityEngine_Light__set_range _SetRange{};
inline FirstPersonController__GetInput GetInput{};
inline MouseLook__LookRotation MouseLookRotation{};
inline UnityEngine_AI_NavMeshAgent__set_speed _SetSpeed{};
inline UnityEngine_AI_NavMeshAgent__get_speed _GetSpeed{};

inline System_Collections_ArrayList___ctor ArrayListCtor{};


inline UnityEngine_Object__Destroy ObjectDestroy{};
inline UnityEngine_GameObject___ctor GameObjConstruct{};
inline UnityEngine_GameObject__set_tag _SetTag{};
inline UnityEngine_Object__DontDestroyOnLoad _DontDestroyOnLoad{};
inline UnityEngine_Object__set_hideFlags _SetHideFlags{};
inline UnityEngine_Object__get_hideFlags _GetHideFlags{};
inline UnityEngine_GameObject__AddComponent _AddComponent{};
inline System_Type__GetType_6498422912 GetTypeByName{};
inline UnityEngine_Behaviour__set_enabled _SetEnabled{};

inline il2cpp_type_get_name il2cppTypeGetName{};

inline UnityEngine_GameObject__SetActive _SetActive{};
inline UnityEngine_Component__get_gameObject GetGameObject{};
inline UnityEngine_Transform__get_rotation _GetRotation{};
inline UnityEngine_Transform__set_rotation _SetRotation{};
inline UnityEngine_Transform__LookAt _LookAt{};
inline UnityEngine_Transform__GetRoot _GetRoot{};
inline UnityEngine_AudioClip__GetName aGetName{};
inline Noise__PlaySound nPlaySound{};
inline GhostEventPlayer__PlaySound gepPlaySound{};

inline UnityEngine_Transform__set_parent _SetParent{};

inline il2cpp_object_new il2cppObjectNew{};
inline il2cpp_value_box il2cppValueBox{};
inline il2cpp_runtime_class_init il2cppRuntimeClassInit{};

inline il2cpp_array_new_specific_0 il2cppArrayNewSpecific{};
inline il2cpp_class_get_method_from_name il2cppClassGetMethodFromName{};
inline il2cpp_class_from_name il2cppClassFromName{};
inline il2cpp_assembly_get_image il2cppAssemblyGetImage{};
inline il2cpp_domain_assembly_open il2cppDomainAssemblyOpen{};
inline il2cpp_domain_get il2cppDomainGet{};
inline il2cpp_class_get_type il2cppClassGetType{};
inline il2cpp_type_get_object il2cppTypeGetObject{};

inline GhostAI__FlashAppear _FlashAppear{};
inline System_String__Ctor_6497373952 SystemStringCtor{};
inline System_String__CopyTo CopyTo{};
inline UnityEngine_Component__get_transform _GetTransform{};
inline UnityEngine_GameObject__get_transform _ObjectGetTransform{};
inline GhostAI_Appear _Appear{};
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
inline UnityEngine_Transform__get_right _GetRightVector{};
inline GhostActivity__InteractWithARandomProp InteractWithRandomProp{};
inline GhostAI__DelayTeleportToFavouriteRoom DelayTeleportToRoom{};
inline GhostAI__LookAtPlayer LookAtPlayer{};
inline GhostAudio__PlaySound _PlaySound{};
inline GhostAudio__TurnOnOrOffAppearSource TurnOnOrOffAppearSource{};
inline GhostAudio__PlayOrStopAppearSource PlayOrStopAppearSource{};
inline GhostAI__UnAppear _UnAppear{};
inline GhostInteraction_____SpawnFootstep____6465324256 SpawnFootstep{};

inline Player__StartKillingPlayer _StartKilling{};
inline Player__RevivePlayer _Revive{};
inline Player__KillPlayer _Kill{};

inline Network__get_Instance NetworkGetInstance{};

inline idkwtf idek{};
inline System_Collections_ArrayList__Add _Add{};

typedef int32_t(__stdcall* System_Array__System_Collections_IList_Add)(System_Array_o* _this, Il2CppObject* value, const MethodInfo* method);
inline System_Array__System_Collections_IList_Add Array_Add{};

inline Photon_Pun_PhotonView__RPC oRpc{};

typedef void(__stdcall* spawnCursedItem)(CursedItemsController_o* _this, const MethodInfo* method);
inline spawnCursedItem tFunc{};
inline spawnCursedItem oFunc{};
inline spawnCursedItem mFunc{};
inline spawnCursedItem mbFunc{};
inline spawnCursedItem cFunc{};
inline spawnCursedItem vFunc{};
inline spawnCursedItem pFunc{};

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
        if (!assembly)
        {
            printf("Assembly: %s  couldnt be found\n", imageName);
            return nullptr;
        }
        void* ret = il2cppAssemblyGetImage(assembly);
        //printf("%s -> %p\n", imageName, ret);
        return ret;
    }

    inline Il2CppClass* GetClass(const char* image, const char* namespaze, const char* className)
    {
        return il2cppClassFromName(GetImage(image), namespaze, className);
    }

    inline uint8_t* GetMethodPtr(const char* namespaze, const char* className, const char* funcName, int argCount, const char* image = "Assembly-CSharp")
    {
        Il2CppClass* klass = GetClass(image, namespaze, className);
        if (!klass)
        {
            printf("Class: %s couldnt be found\n", className);
            return nullptr;
        }
        const MethodInfo1* mInfo = (MethodInfo1*)il2cppClassGetMethodFromName(klass, funcName, argCount);
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
       

        HMODULE mod = GetModuleHandleA("GameAssembly.dll");

        il2cppArrayNewSpecific = (il2cpp_array_new_specific_0)GetProcAddress(mod, "il2cpp_array_new_specific");
        work &= (il2cppArrayNewSpecific != 0);

        il2cppObjectNew = (il2cpp_object_new)GetProcAddress(mod, "il2cpp_object_new");
        work &= (il2cppObjectNew != 0);

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

        il2cppRuntimeClassInit = (il2cpp_runtime_class_init)GetProcAddress(mod, "il2cpp_runtime_class_init");
        work &= (il2cppRuntimeClassInit != 0);

        il2cppClassGetType = (il2cpp_class_get_type)GetProcAddress(mod, "il2cpp_class_get_type");
        work &= (il2cppClassGetType != 0);

        il2cppTypeGetObject = (il2cpp_type_get_object)GetProcAddress(mod, "il2cpp_type_get_object");
        work &= (il2cppTypeGetObject != 0);

        il2cppTypeGetName = (il2cpp_type_get_name)GetProcAddress(mod, "il2cpp_type_get_name");
        work &= (il2cppTypeGetName != 0);

        InitParam = (weirdInitParamsFunc)(signature("E8 ? ? ? ? 8B 47 10 89 43 10 8B 47 14 89 43 14 83 7F 18 00 0F 95 C0").resolveRelativeAddr(1, 5));
        work &= (InitParam != 0);

        idek = (idkwtf)(signature("E8 ? ? ? ? 48 85 C0 74 0F EB 02 33 C0 48 8B 5C 24 ?").resolveRelativeAddr(1, 5));
        work &= (idek != 0);

        SetCursorVisible = (UnityEngine_Cursor__set_visible)(GetMethodPtr("UnityEngine", "Cursor", "set_visible", 1, "UnityEngine.CoreModule"));
        work &= (SetCursorVisible != 0);

        SetLockState = (UnityEngine_Cursor__set_lockState)(GetMethodPtr("UnityEngine", "Cursor", "set_lockState", 1, "UnityEngine.CoreModule"));
        work &= (SetLockState != 0);

        GetLockState = (UnityEngine_Cursor__get_lockState)(GetMethodPtr("UnityEngine", "Cursor", "get_lockState", 0, "UnityEngine.CoreModule"));
        work &= (GetLockState != 0);

        NameToLayer = (UnityEngine_LayerMask__NameToLayer)(FUNCS::GetMethodPtr("UnityEngine", "LayerMask", "NameToLayer", 1, "UnityEngine.CoreModule"));
        work &= (NameToLayer != 0);

        DebugDrawLine = (UnityEngine_Debug__DrawLine)(GetMethodPtr("UnityEngine", "Debug", "DrawLine", 4, "UnityEngine.CoreModule"));
        work &= (DebugDrawLine != 0);

        GizmoDrawLine = (UnityEngine_Gizmos__DrawLine)(GetMethodPtr("UnityEngine", "Gizmos", "DrawLine", 2, "UnityEngine.CoreModule"));
        work &= (GizmoDrawLine != 0);

        GetScreenHeight = (UnityEngine_Screen__get_height)(GetMethodPtr("UnityEngine", "Screen", "get_height", 0, "UnityEngine.CoreModule"));
        work &= (GetScreenHeight != 0);

        WorldToScreen = (UnityEngine_Camera__WorldToScreenPoint)(GetMethodPtr("UnityEngine", "Camera", "WorldToScreenPoint", 2, "UnityEngine.CoreModule"));
        work &= (WorldToScreen != 0);


        


        card = (TarotCard____________6472688672)signature("E8 ? ? ? ? EB 0A 33 D2 48 8B CD E8 ? ? ? ? 48 8B 0D ? ? ? ? 83 B9 ? ? ? ? ?").resolveRelativeAddr(1, 5);
        work &= (card != 0);

        ComponentGetTag = (UnityEngine_Component__get_tag)(GetMethodPtr("UnityEngine", "Component", "get_tag", 0, "UnityEngine.CoreModule"));
        work &= (ComponentGetTag != 0);

        CastRay = (UnityEngine_Physics__RaycastAll)(GetMethodPtr("UnityEngine", "Physics", "RaycastAll", 5, "UnityEngine.PhysicsModule"));
        work &= (CastRay != 0);

        GetCollider = (UnityEngine_RaycastHit__get_collider)(GetMethodPtr("UnityEngine", "RaycastHit", "get_collider", 0, "UnityEngine.PhysicsModule"));
        work &= (CastRay != 0);

        ObjectGetName = (UnityEngine_Object__GetName)(GetMethodPtr("UnityEngine", "Object", "get_name", 0, "UnityEngine.CoreModule"));
        work &= (ObjectGetName != 0);

        aGetName = (UnityEngine_AudioClip__GetName)(GetMethodPtr("UnityEngine", "AudioClip", "GetName", 0, "UnityEngine.AudioModule"));
        work &= (aGetName != 0);

        GetMainCamera = (UnityEngine_Camera__get_main)(GetMethodPtr("UnityEngine", "Camera", "get_main", 0, "UnityEngine.CoreModule"));
        work &= (GetMainCamera != 0);

        ArrayListCtor = (System_Collections_ArrayList___ctor)(signature("E8 ? ? ? ? 48 85 FF 0F 84 ? ? ? ? 48 8B 17 48 8B CF 48 8B 82 ? ? ? ? 48 8B 92 ? ? ? ? FF D0 48 8B F8 66 0F 1F 44 00 ? 48 8B 0D ? ? ? ? 39 B1 ? ? ? ?").resolveRelativeAddr(1, 5));
        work &= (ArrayListCtor != 0);

        _Add = (System_Collections_ArrayList__Add)(GetMethodPtr("System.Collections", "ArrayList", "Add", 1, "mscorlib"));
        work &= (_Add != 0);

        TargettedRPC = (Photon_Pun_PhotonView__RPC_6500903728)(signature("E8 ? ? ? ? 48 8B 05 ? ? ? ? 48 8B 88 ? ? ? ? 48 8B 01 48 85 C0 0F 84 ? ? ? ? 40 38 B0 ? ? ? ? 74 33 48 8B 0D ? ? ? ?").resolveRelativeAddr(1, 5));
        work &= (TargettedRPC != 0);

        Array_Add = (System_Array__System_Collections_IList_Add)(GetMethodPtr("System", "Array", "System.Collections.IList.Add", 1, "mscorlib"));
        work &= (Array_Add != 0);

        _CreatePrimitive = (UnityEngine_GameObject__CreatePrimitive)(GetMethodPtr("UnityEngine", "GameObject", "CreatePrimitive", 1, "UnityEngine.CoreModule"));
        work &= (_CreatePrimitive != 0);

        _SetParent = (UnityEngine_Transform__set_parent)(GetMethodPtr("UnityEngine", "Transform", "set_parent", 1, "UnityEngine.CoreModule"));
        work &= (_SetParent != 0);

        LightSetColor = (UnityEngine_Light__set_color)(GetMethodPtr("UnityEngine", "Light", "set_color", 1, "UnityEngine.CoreModule"));
        work &= (LightSetColor != 0);

        LightSetIntensity = (UnityEngine_Light__set_intensity)(GetMethodPtr("UnityEngine", "Light", "set_intensity", 1, "UnityEngine.CoreModule"));
        work &= (LightSetIntensity != 0);

        _SetRange = (UnityEngine_Light__set_range)(GetMethodPtr("UnityEngine", "Light", "set_range", 1, "UnityEngine.CoreModule"));
        work &= (_SetRange != 0);

        _SetAcceleration = (UnityEngine_AI_NavMeshAgent__set_acceleration)(GetMethodPtr("UnityEngine.AI", "NavMeshAgent", "set_acceleration", 1, "UnityEngine.AIModule"));
        work &= (_SetAcceleration != 0);

        _SetIsKinematic = (UnityEngine_Rigidbody__set_isKinematic)(GetMethodPtr("UnityEngine", "Rigidbody", "set_isKinematic", 1, "UnityEngine.PhysicsModule"));
        work &= (_SetIsKinematic != 0);

        _AddForce = (UnityEngine_Rigidbody__AddForce)(GetMethodPtr("UnityEngine", "Rigidbody", "AddForce", 2, "UnityEngine.PhysicsModule"));
        work &= (_AddForce != 0);

        ////-------------------AI stuff--------------------//
        
        _StartKilling = (Player__StartKillingPlayer)(GetMethodPtr("", "Player", "StartKillingPlayer", 0));
        work &= (_StartKilling != 0);

        _Kill = (Player__KillPlayer)(GetMethodPtr("", "Player", "KillPlayer", 1));
        work &= (_Kill != 0);

        _Revive = (Player__RevivePlayer)(GetMethodPtr("", "Player", "RevivePlayer", 0));
        work &= (_Revive != 0);

        _SetGhostModel = (GhostAI__SetGhostModel_6465062688)signature("40 53 55 41 54 48 83 EC 20 80 3D ? ? ? ? ? 45 0F B6 E0 48 8B EA 48 8B D9").GetPointer();
        work &= (_SetGhostModel != 0);

        _SetGhostModelInt = (GhostAI__SetGhostModel)signature("48 83 EC 28 45 84 C0 75 46 48 8B 41 38 48 85 C0 74 56 44 38 40 44 74 26").GetPointer();
        work &= (_SetGhostModelInt != 0);

        _ColliderSetEnabled = (UnityEngine_Collider__set_enabled)(GetMethodPtr("UnityEngine", "Collider", "set_enabled", 1, "UnityEngine.PhysicsModule"));
        work &= (_ColliderSetEnabled != 0);

        _GetComponent = (UnityEngine_GameObject__GetComponent)(GetMethodPtr("UnityEngine", "GameObject", "GetComponent", 1, "UnityEngine.CoreModule"));
        work &= (_GetComponent != 0);

        _GetComponents = (UnityEngine_GameObject__GetComponents)(GetMethodPtr("UnityEngine", "GameObject", "GetComponents", 1, "UnityEngine.CoreModule"));
        work &= (_GetComponents != 0);

        _SetUseGravity = (UnityEngine_Rigidbody__set_useGravity)(GetMethodPtr("UnityEngine", "Rigidbody", "set_useGravity", 1, "UnityEngine.PhysicsModule"));
        work &= (_SetUseGravity != 0);

        _GetInstanceID = (UnityEngine_Object__GetInstanceID)(GetMethodPtr("UnityEngine", "Object", "GetInstanceID", 0, "UnityEngine.CoreModule"));
        work &= (_GetInstanceID != 0);

        GetColliderByInstanceID = (UnityEngine_Physics__GetColliderByInstanceID)(GetMethodPtr("UnityEngine", "Physics", "GetColliderByInstanceID", 1, "UnityEngine.PhysicsModule"));
        work &= (GetColliderByInstanceID != 0);

        _GetRigidBody = (UnityEngine_Collider__get_attachedRigidbody)(GetMethodPtr("UnityEngine", "Collider", "get_attachedRigidbody", 0, "UnityEngine.PhysicsModule"));
        work &= (_GetRigidBody != 0);

        _SetBounds = (UnityEngine_Renderer__set_localBounds)(GetMethodPtr("UnityEngine", "Renderer", "set_localBounds", 1, "UnityEngine.CoreModule"));
        work &= (_SetBounds != 0);

        _GetBounds = (UnityEngine_Renderer__get_bounds)(GetMethodPtr("UnityEngine", "Renderer", "get_bounds", 0, "UnityEngine.CoreModule"));
        work &= (_GetBounds != 0);

        _FlashAppear = (GhostAI__FlashAppear)(GetMethodPtr("", "GhostAI", "FlashAppear", 0));
        work &= (_FlashAppear != 0);

        _AnimatorSetSpeed = (UnityEngine_Animator__set_speed)(GetMethodPtr("UnityEngine", "Animator", "set_speed", 1, "UnityEngine.AnimationModule"));
        work &= (_AnimatorSetSpeed != 0);

        _SetSpeed = (UnityEngine_AI_NavMeshAgent__set_speed)(GetMethodPtr("UnityEngine.AI", "NavMeshAgent", "set_speed", 1, "UnityEngine.AIModule"));
        work &= (_SetSpeed != 0);

        _GetSpeed = (UnityEngine_AI_NavMeshAgent__get_speed)(GetMethodPtr("UnityEngine.AI", "NavMeshAgent", "get_speed", 0, "UnityEngine.AIModule"));
        work &= (_GetSpeed != 0);

        _CopyFrom = (UnityEngine_Camera__CopyFrom)(GetMethodPtr("UnityEngine", "Camera", "CopyFrom", 1, "UnityEngine.CoreModule"));
        work &= (_CopyFrom != 0);

        MouseLookRotation = (MouseLook__LookRotation)(GetMethodPtr("", "MouseLook", "LookRotation", 2, "Assembly-CSharp-firstpass"));
        work &= (MouseLookRotation != 0);

        _SetEnabled = (UnityEngine_Behaviour__set_enabled)(GetMethodPtr("UnityEngine", "Behaviour", "set_enabled", 1, "UnityEngine.CoreModule"));
        work &= (_SetEnabled != 0);

        GameObjConstruct = (UnityEngine_GameObject___ctor)signature("E8 ? ? ? ? 48 85 FF 0F 84 ? ? ? ? 45 33 C0 B2 01 48 8B CF E8 ? ? ? ?").resolveRelativeAddr(1, 5);
        work &= (GameObjConstruct != 0);

        ObjectDestroy = (UnityEngine_Object__Destroy)(GetMethodPtr("UnityEngine", "Object", "Destroy", 1, "UnityEngine.CoreModule"));
        work &= (ObjectDestroy != 0);

        _SetTag = (UnityEngine_GameObject__set_tag)(GetMethodPtr("UnityEngine", "GameObject", "set_tag", 1, "UnityEngine.CoreModule"));//signature("E8 ? ? ? ? E9 ? ? ? ? 3D ? ? ? ? 0F 86 ? ? ? ? 3D ? ? ? ? 75 30 45 33 C0").resolveRelativeAddr(1, 5);
        work &= (_SetTag != 0);

        _DontDestroyOnLoad = (UnityEngine_Object__DontDestroyOnLoad)(GetMethodPtr("UnityEngine", "Object", "DontDestroyOnLoad", 1, "UnityEngine.CoreModule"));
        work &= (_DontDestroyOnLoad != 0);
        
        _SetHideFlags = (UnityEngine_Object__set_hideFlags)(GetMethodPtr("UnityEngine", "Object", "set_hideFlags", 1, "UnityEngine.CoreModule"));
        work &= (_SetHideFlags != 0);
       
        _GetHideFlags = (UnityEngine_Object__get_hideFlags)(GetMethodPtr("UnityEngine", "Object", "get_hideFlags", 0, "UnityEngine.CoreModule"));
        work &= (_GetHideFlags != 0);
        
        _AddComponent = (UnityEngine_GameObject__AddComponent)(GetMethodPtr("UnityEngine", "GameObject", "AddComponent", 1, "UnityEngine.CoreModule"));
        work &= (_AddComponent != 0);
       
        GetTypeByName = (System_Type__GetType_6498422912)signature("40 53 48 83 EC 30 80 3D ? ? ? ? ? 48 8B D9 75 13 48 8D 0D ? ? ? ? E8 ? ? ? ? C6 05 ? ? ? ? ? 48 8B 0D ? ? ? ? C7 44 24 ? ? ? ? ? 83 B9 ? ? ? ? ? 75 05 E8 ? ? ? ?").GetPointer();
        work &= (GetTypeByName != 0);

        SystemStringCtor = (System_String__Ctor_6497373952)signature("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 80 3D ? ? ? ? ? 41 8B D8 48 63 FA 48 8B F1 75 13 48 8D 0D ? ? ? ? E8 ? ? ? ? C6 05 ? ? ? ? ?").GetPointer();
        work &= (SystemStringCtor != 0);

        GetInput = (FirstPersonController__GetInput)(GetMethodPtr("", "FirstPersonController", "GetInput", 0, "Assembly-CSharp-firstpass"));
        work &= (GetInput != 0);


        //------------------------------------------------//


        _GetRoot = (UnityEngine_Transform__GetRoot)(GetMethodPtr("UnityEngine", "Transform", "GetRoot", 0, "UnityEngine.CoreModule"));
        work &= (_GetRoot != 0);

        _LookAt = (UnityEngine_Transform__LookAt)(GetMethodPtr("UnityEngine", "Transform", "LookAt", 2, "UnityEngine.CoreModule"));
        work &= (_LookAt != 0);

        _GetRotation = (UnityEngine_Transform__get_rotation)(signature("E8 ? ? ? ? 48 85 FF 74 23 0F 10 00 45 33 C0 48 8D 54 24 ? 48 8B CF 0F 29 44 24 ? E8 ? ? ? ? 48 8B 7C 24 ? ").resolveRelativeAddr(1, 5));
        work &= (_GetRotation != 0);

        _SetRotation = (UnityEngine_Transform__set_rotation)(signature("E8 ? ? ? ? FF CB 83 FB FF 0F 8F ? ? ? ? 4C 8D 9C 24 ? ? ? ? 49 8B 5B 28").resolveRelativeAddr(1, 5));
        work &= (_SetRotation != 0);

        GetGameObject = (UnityEngine_Component__get_gameObject)(GetMethodPtr("UnityEngine", "GameObject", "get_gameObject", 0, "UnityEngine.CoreModule"));
        work &= (GetGameObject != 0);

        _SetActive = (UnityEngine_GameObject__SetActive)(GetMethodPtr("UnityEngine", "GameObject", "SetActive", 1, "UnityEngine.CoreModule"));
        work &= (_SetActive != 0);

        _GetTransform = (UnityEngine_Component__get_transform)(GetMethodPtr("UnityEngine", "Component", "get_transform", 0, "UnityEngine.CoreModule"));
        work &= (_GetTransform != 0);

        _ObjectGetTransform = (UnityEngine_GameObject__get_transform)(GetMethodPtr("UnityEngine", "GameObject", "get_transform", 0, "UnityEngine.CoreModule"));
        work &= (_ObjectGetTransform != 0);

        _GetForwardVector = (UnityEngine_Transform__get_forward)signature("E8 ? ? ? ? F3 0F 10 5F ? F2 0F 10 20").resolveRelativeAddr(1, 5);
        work &= (_GetForwardVector != 0);

        _GetRightVector = (UnityEngine_Transform__get_right)(GetMethodPtr("UnityEngine", "Transform", "get_right", 0, "UnityEngine.CoreModule"));
        work &= (_GetRightVector != 0);

        _SetPosition = (UnityEngine_Transform__set_position)signature("E8 ? ? ? ? 44 0F 28 4C 24 ? 48 8B BC 24 ? ? ? ?").resolveRelativeAddr(1, 5);
        work &= (_SetPosition != 0);

        _GetPosition = (UnityEngine_Transform__get_position)signature("E8 ? ? ? ? F2 0F 10 00 8B 48 08 EB 31").resolveRelativeAddr(1, 5);
        work &= (_GetPosition != 0);

        Teleport = (Player__Teleport)GetMethodPtr("", "Player", "Teleport", 1);
        work &= (Teleport != 0);

        _Appear = (GhostAI_Appear)GetMethodPtr("", "GhostAI", "Appear", 1);
        work &= (_Appear != 0);

        gepPlaySound = (GhostEventPlayer__PlaySound)GetMethodPtr("", "GhostEventPlayer", "PlaySound", 1);
        work &= (gepPlaySound != 0);

        nPlaySound = (Noise__PlaySound)GetMethodPtr("", "Noise", "PlaySound", 4);
        work &= (nPlaySound != 0);

        _PlaySound = (GhostAudio__PlaySound)GetMethodPtr("", "GhostAudio", "PlaySound", 1);
        work &= (_PlaySound != 0);

        Interact = (GhostActivity__Interact)GetMethodPtr("", "GhostActivity", "Interact", 0);
        work &= (Interact != 0);

        GetPropToThrow = (GhostActivity__GetPropToThrow)GetMethodPtr("", "GhostActivity", "GetPropToThrow", 0);
        work &= (GetPropToThrow != 0);

        ForceInteract = (GhostActivity__ForceInteractWithProp)GetMethodPtr("", "GhostActivity", "ForceInteractWithProp", 1);
        work &= (ForceInteract != 0);

        InteractWithRandomProp = (GhostActivity__InteractWithARandomProp)GetMethodPtr("", "GhostActivity", "InteractWithARandomProp", 2);
        work &= (InteractWithRandomProp != 0);

        SpawnFootstep = (GhostInteraction_____SpawnFootstep____6465324256)signature("E8 ? ? ? ? 0F 2F 7B 4C 76 70 48 8B 43 20").resolveRelativeAddr(1, 5);
        work &= (SpawnFootstep != 0);

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

        LookAtPlayer = (GhostAI__LookAtPlayer)GetMethodPtr("", "GhostAI", "LookAtPlayer", 1);
        work &= (LookAtPlayer != 0);

        NetworkGetInstance = (Network__get_Instance)signature("E8 ? ? ? ? 48 85 C0 74 66 48 8B 0D ? ? ? ? 48 8B 78 60 E8 ? ? ? ? ").resolveRelativeAddr(1, 5);
        work &= (NetworkGetInstance != 0);

        TurnOnOrOffAppearSource = (GhostAudio__TurnOnOrOffAppearSource)GetMethodPtr("", "GhostAudio", "TurnOnOrOffAppearSource", 2);
        work &= (TurnOnOrOffAppearSource != 0);

        PlayOrStopAppearSource = (GhostAudio__PlayOrStopAppearSource)GetMethodPtr("", "GhostAudio", "PlayOrStopAppearSource", 1);
        work &= (PlayOrStopAppearSource != 0);

        _UnAppear = (GhostAI__UnAppear)GetMethodPtr("", "GhostAI", "UnAppear", 0);
        work &= (_UnAppear != 0);

        tFunc = (spawnCursedItem)signature("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 40 48 8B 79 68 48 8B D9 48 85 FF 0F 84 ? ? ? ? 8B 57 18 45 33 C0 33 C9 E8 ? ? ? ? 3B 47 18 0F 83 ? ? ? ? 48 8B 4B 30 48 98 48 8B 7C C7 ? 48 85 C9 0F 84 ? ? ? ?").GetPointer(4);
        work &= (tFunc != 0);

        oFunc = (spawnCursedItem)signature("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 40 48 8B 79 58 48 8B D9 48 85 FF 0F 84 ? ? ? ? 8B 57 18 45 33 C0 33 C9 E8 ? ? ? ? 3B 47 18").GetPointer(5);
        work &= (oFunc != 0);

        mFunc = (spawnCursedItem)signature("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 40 48 8B 79 78 48 8B D9 48 85 FF 0F 84 ? ? ? ? 8B 57 18 45 33 C0 33 C9 E8 ? ? ? ? 3B 47 18 0F 83 ? ? ? ?").GetPointer(7);
        work &= (mFunc != 0);

        mbFunc = (spawnCursedItem)signature("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 40 48 8B 79 60 48 8B D9 48 85 FF 0F 84 ? ? ? ? 8B 57 18 45 33 C0 33 C9 E8 ? ? ? ? 3B 47 18 0F 83 ? ? ? ?").GetPointer(2);
        work &= (mbFunc != 0);

        cFunc = (spawnCursedItem)signature("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 40 48 8B 79 70 48 8B D9 48 85 FF 0F 84 ? ? ? ? 8B 57 18 45 33 C0 33 C9 E8 ? ? ? ?").GetPointer(2);
        work &= (cFunc != 0);

        vFunc = (spawnCursedItem)signature("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 40 48 8B B9 ? ? ? ? 48 8B D9 48 85 FF 0F 84 ? ? ? ? 8B 57 18 45 33 C0 33 C9 E8 ? ? ? ? 3B 47 18 0F 83 ? ? ? ? 48 8B 4B 48 48 98 48 8B 7C C7 ? 48 85 C9 0F 84 ? ").GetPointer(4);
        work &= (vFunc != 0);

        pFunc = (spawnCursedItem)signature("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 40 48 8B B9 ? ? ? ? 48 8B D9 48 85 FF 0F 84 ? ? ? ? 8B 57 18 45 33 C0 33 C9 E8 ? ? ? ? 3B 47 18 0F 83 ? ? ? ?").GetPointer(2);
        work &= (pFunc != 0);
        return work;
	}
}