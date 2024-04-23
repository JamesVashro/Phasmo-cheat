#pragma once
#include "../hooking/hooks/funcs.h"

typedef void(*Il2CppMethodPointer)();

struct MethodInfo;

enum CursedItem
{
	NONE = 0,
	TAROT,
	OUIJA,
	MIRROR,
	MUSIC,
	CIRCLE,
	VOODOO,
	PAW
};

struct VirtualInvokeData
{
	Il2CppMethodPointer methodPtr;
	const MethodInfo* method;
};

struct Il2CppType
{
	void* data;
	unsigned int bits;
};

struct Il2CppClass;
struct Il2CppRuntimeInterfaceOffsetPair
{
	Il2CppClass* interfaceType;
	int32_t offset;
};

struct Il2CppClass_1
{
	void* image;
	void* gc_desc;
	const char* name;
	const char* namespaze;
	Il2CppType byval_arg;
	Il2CppType this_arg;
	Il2CppClass* element_class;
	Il2CppClass* castClass;
	Il2CppClass* declaringType;
	Il2CppClass* parent;
	void* generic_class;
	void* typeMetadataHandle;
	void* interopData;
	Il2CppClass* klass;
	void* fields;
	void* events;
	void* properties;
	void* methods;
	Il2CppClass** nestedTypes;
	Il2CppClass** implementedInterfaces;
	Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
};


struct Il2CppClass_2
{
	Il2CppClass** typeHierarchy;
	void* unity_user_data;
	uint32_t initializationExceptionGCHandle;
	uint32_t cctor_started;
	uint32_t cctor_finished;
	size_t cctor_thread;
	void* genericContainerHandle;
	uint32_t instance_size;
	uint32_t actualSize;
	uint32_t element_size;
	int32_t native_size;
	uint32_t static_fields_size;
	uint32_t thread_static_fields_size;
	int32_t thread_static_fields_offset;
	uint32_t flags;
	uint32_t token;
	uint16_t method_count;
	uint16_t property_count;
	uint16_t field_count;
	uint16_t event_count;
	uint16_t nested_type_count;
	uint16_t vtable_count;
	uint16_t interfaces_count;
	uint16_t interface_offsets_count;
	uint8_t typeHierarchyDepth;
	uint8_t genericRecursionDepth;
	uint8_t rank;
	uint8_t minimumAlignment;
	uint8_t naturalAligment;
	uint8_t packingSize;
	uint8_t bitflags1;
	uint8_t bitflags2;
};

union Il2CppRGCTXData
{
	void* rgctxDataDummy;
	const MethodInfo* method;
	const Il2CppType* type;
	Il2CppClass* klass;
};

struct Il2CppClass
{
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	VirtualInvokeData vtable[255];
};

struct Il2CppObject
{
	Il2CppClass* klass;
	void* monitor;
};

typedef uintptr_t il2cpp_array_size_t;
typedef int32_t il2cpp_array_lower_bound_t;
struct Il2CppArrayBounds
{
	il2cpp_array_size_t length;
	il2cpp_array_lower_bound_t lower_bound;
};

typedef void (*InvokerMethod)(Il2CppMethodPointer, const MethodInfo*, void*, void**, void*);
struct MethodInfo
{
	Il2CppMethodPointer methodPointer;
	Il2CppMethodPointer virtualMethodPointer;
	InvokerMethod invoker_method;
	const char* name;
	Il2CppClass* klass;
	const Il2CppType* return_type;
	const Il2CppType** parameters;
	union
	{
		const Il2CppRGCTXData* rgctx_data;
		const void* methodMetadataHandle;
	};
	union
	{
		const void* genericMethod;
		const void* genericContainerHandle;
	};
	uint32_t token;
	uint16_t flags;
	uint16_t iflags;
	uint16_t slot;
	uint8_t parameters_count;
	uint8_t bitflags;
};

struct __declspec(align(8)) _Module__Fields {
};
struct _Module__c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	VirtualInvokeData vtable[32];
};
struct _Module__o {
	_Module__c* klass;
	void* monitor;
	_Module__Fields fields;
};

struct __declspec(align(8)) UnityEngine_Object_Fields {
	intptr_t m_CachedPtr;
};

struct UnityEngine_Component_Fields : UnityEngine_Object_Fields {
};

struct UnityEngine_Behaviour_Fields : UnityEngine_Component_Fields {
};

struct UnityEngine_MonoBehaviour_Fields : UnityEngine_Behaviour_Fields {
	struct System_Threading_CancellationTokenSource_o* m_CancellationTokenSource;
};

struct Photon_Pun_MonoBehaviourPun_Fields : UnityEngine_MonoBehaviour_Fields {
	struct Photon_Pun_PhotonView_o* pvCache;
};

struct Photon_Pun_MonoBehaviourPunCallbacks_Fields : Photon_Pun_MonoBehaviourPun_Fields {
};

struct UnityEngine_Transform_Fields : UnityEngine_Component_Fields {
};

struct UnityEngine_GameObject_Fields : UnityEngine_Object_Fields {
};

struct UnityEngine_Vector2_Fields {
	float x;
	float y;
};
struct UnityEngine_Vector2_o {
	UnityEngine_Vector2_Fields fields;
};
struct UnityEngine_Vector3_Fields {
	float x;
	float y;
	float z;
};
struct UnityEngine_Vector3_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_Equals;
	VirtualInvokeData _5_ToString;
};
struct UnityEngine_Vector3_c {
	Il2CppClass_1 _1;
	struct UnityEngine_Vector3_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Vector3_VTable vtable;
};
struct UnityEngine_Vector3_o {
	UnityEngine_Vector3_Fields fields;

	UnityEngine_Vector3_o operator+(UnityEngine_Vector3_o other)
	{
		UnityEngine_Vector3_o ret{};
		ret.fields.x = this->fields.x + other.fields.x;
		ret.fields.y = this->fields.y + other.fields.y;
		ret.fields.z = this->fields.z + other.fields.z;
		return ret;
	}

	UnityEngine_Vector3_o operator*(int mult)
	{
		UnityEngine_Vector3_o ret{};
		ret.fields.x = this->fields.x * mult;
		ret.fields.y = this->fields.y * mult;
		ret.fields.z = this->fields.z * mult;
		return ret;
	}
};

struct System_Text_RegularExpressions_RegexCharClass_SingleRange_Fields {
	uint16_t First;
	uint16_t Last;
};

struct System_Text_RegularExpressions_RegexCharClass_SingleRange_o {
	System_Text_RegularExpressions_RegexCharClass_SingleRange_Fields fields;
};

struct __declspec(align(8)) System_Collections_Generic_List_RegexCharClass_SingleRange__Fields {
	struct System_Text_RegularExpressions_RegexCharClass_SingleRange_array* _items;
	int32_t _size;
	int32_t _version;
	Il2CppObject* _syncRoot;
};
struct System_Collections_Generic_List_RegexCharClass_SingleRange__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_set_Item;
	VirtualInvokeData _6_IndexOf;
	VirtualInvokeData _7_Insert;
	VirtualInvokeData _8_unknown;
	VirtualInvokeData _9_unknown;
	VirtualInvokeData _10_System_Collections_Generic_ICollection_T__get_IsReadOnly;
	VirtualInvokeData _11_Add;
	VirtualInvokeData _12_unknown;
	VirtualInvokeData _13_Contains;
	VirtualInvokeData _14_CopyTo;
	VirtualInvokeData _15_Remove;
	VirtualInvokeData _16_System_Collections_Generic_IEnumerable_T__GetEnumerator;
	VirtualInvokeData _17_System_Collections_IEnumerable_GetEnumerator;
	VirtualInvokeData _18_System_Collections_IList_get_Item;
	VirtualInvokeData _19_System_Collections_IList_set_Item;
	VirtualInvokeData _20_System_Collections_IList_Add;
	VirtualInvokeData _21_System_Collections_IList_Contains;
	VirtualInvokeData _22_Clear;
	VirtualInvokeData _23_System_Collections_IList_get_IsReadOnly;
	VirtualInvokeData _24_System_Collections_IList_get_IsFixedSize;
	VirtualInvokeData _25_System_Collections_IList_IndexOf;
	VirtualInvokeData _26_System_Collections_IList_Insert;
	VirtualInvokeData _27_System_Collections_IList_Remove;
	VirtualInvokeData _28_RemoveAt;
	VirtualInvokeData _29_System_Collections_ICollection_CopyTo;
	VirtualInvokeData _30_unknown;
	VirtualInvokeData _31_System_Collections_ICollection_get_SyncRoot;
	VirtualInvokeData _32_System_Collections_ICollection_get_IsSynchronized;
	VirtualInvokeData _33_get_Item;
	VirtualInvokeData _34_get_Count;
};
struct System_Collections_Generic_List_RegexCharClass_SingleRange__c {
	Il2CppClass_1 _1;
	struct System_Collections_Generic_List_RegexCharClass_SingleRange__StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Collections_Generic_List_RegexCharClass_SingleRange__VTable vtable;
};
struct System_Collections_Generic_List_RegexCharClass_SingleRange__o {
	System_Collections_Generic_List_RegexCharClass_SingleRange__c* klass;
	void* monitor;
	System_Collections_Generic_List_RegexCharClass_SingleRange__Fields fields;
};

struct UnityEngine_Bounds_Fields {
	struct UnityEngine_Vector3_o m_Center;
	struct UnityEngine_Vector3_o m_Extents;
};

struct UnityEngine_Bounds_o {
	UnityEngine_Bounds_Fields fields;
};

struct UnityEngine_Quaternion_Fields {
	float x;
	float y;
	float z;
	float w;
};
struct UnityEngine_Quaternion_o {
	UnityEngine_Quaternion_Fields fields;
};

struct UnityEngine_Transform_o {
	struct UnityEngine_Transform_c* klass;
	void* monitor;
	UnityEngine_Transform_Fields fields;

	UnityEngine_Vector3_o GetPosition()
	{
		UnityEngine_Vector3_o pos{};
		_GetPosition(&pos, this, 0);

		return pos;
	}

	UnityEngine_Vector3_o GetForwardVector()
	{
		UnityEngine_Vector3_o forward{};
		_GetForwardVector(&forward, this, 0);

		return forward;
	}

	UnityEngine_Vector3_o GetRightVector()
	{
		UnityEngine_Vector3_o right{};
		_GetRightVector(&right, this, 0);

		return right;
	}

	void SetPosition(UnityEngine_Vector3_o pos)
	{
		_SetPosition(this, &pos, 0);
	}

	void SetRotation(float pitch, float yaw, float roll, float w)
	{
		UnityEngine_Quaternion_o quat{};
		quat.fields.x = pitch;
		quat.fields.y = yaw;
		quat.fields.z = roll;
		quat.fields.w = w;

		_SetRotation(this, &quat, 0);
	}

	void SetRotation(UnityEngine_Quaternion_o quat)
	{
		_SetRotation(this, &quat, 0);
	}

	UnityEngine_Quaternion_o GetRotation()
	{
		UnityEngine_Quaternion_o ret{};

		_GetRotation(&ret, this, 0);

		return ret;
	}

	void LookAt(UnityEngine_Transform_o* look)
	{
		UnityEngine_Vector3_o worldUp{};
		worldUp.fields.x = 1;
		worldUp.fields.y = 0;
		worldUp.fields.z = 0;

		_LookAt(this, look, &worldUp, 0);
	}

	UnityEngine_Transform_o* GetRoot()
	{
		return _GetRoot(this, 0);
	}

	void SetParent(UnityEngine_Transform_o parent)
	{
		_SetParent(this, &parent, 0);
	}
};


struct UnityEngine_Object_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct UnityEngine_Object_c {
	Il2CppClass_1 _1;
	struct UnityEngine_Object_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Object_VTable vtable;
};
struct UnityEngine_Object_o {
	UnityEngine_Object_c* klass;
	void* monitor;
	UnityEngine_Object_Fields fields;

	void SetHideFlags(int value)
	{
		_SetHideFlags(this, value, 0);
	}

	int GetHideFlags()
	{
		_GetHideFlags(this, 0);
	}

	void DontDestroyOnLoad()
	{
		_DontDestroyOnLoad(this, 0);
	}

	int GetInstanceID()
	{
		return _GetInstanceID(this, 0);
	}
};
struct UnityEngine_Object_StaticFields {
	int32_t OffsetOfInstanceIDInCPlusPlusObject;
};

struct UnityEngine_LayerMask_Fields {
	int32_t m_Mask;
};
struct UnityEngine_LayerMask_o {
	UnityEngine_LayerMask_Fields fields;
};

struct UnityEngine_Component_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct UnityEngine_Component_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Component_VTable vtable;
};
struct UnityEngine_Component_o {
	UnityEngine_Component_c* klass;
	void* monitor;
	UnityEngine_Component_Fields fields;

	UnityEngine_Transform_o* GetTransform()
	{
		return _GetTransform(this, 0);
	}
};

struct __declspec(align(8)) __________16_Fields {
	int32_t cursedItemIndex;
	int32_t _1__________;
};
struct __________16_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct __________16_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	__________16_VTable vtable;
};
struct __________16_o {
	__________16_c* klass;
	void* monitor;
	__________16_Fields fields;
};

struct __________16_array {
	Il2CppObject obj;
	Il2CppArrayBounds* bounds;
	il2cpp_array_size_t max_length;
	__________16_Fields m_Items[1];
};

struct __declspec(align(8)) System_Collections_Generic_List____________Fields {
	struct __________16_array* _items;
	int32_t _size;
	int32_t _version;
	Il2CppObject* _syncRoot;
};
struct System_Collections_Generic_List____________VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_set_Item;
	VirtualInvokeData _6_IndexOf;
	VirtualInvokeData _7_Insert;
	VirtualInvokeData _8_unknown;
	VirtualInvokeData _9_unknown;
	VirtualInvokeData _10_System_Collections_Generic_ICollection_T__get_IsReadOnly;
	VirtualInvokeData _11_Add;
	VirtualInvokeData _12_unknown;
	VirtualInvokeData _13_Contains;
	VirtualInvokeData _14_CopyTo;
	VirtualInvokeData _15_Remove;
	VirtualInvokeData _16_System_Collections_Generic_IEnumerable_T__GetEnumerator;
	VirtualInvokeData _17_System_Collections_IEnumerable_GetEnumerator;
	VirtualInvokeData _18_System_Collections_IList_get_Item;
	VirtualInvokeData _19_System_Collections_IList_set_Item;
	VirtualInvokeData _20_System_Collections_IList_Add;
	VirtualInvokeData _21_System_Collections_IList_Contains;
	VirtualInvokeData _22_Clear;
	VirtualInvokeData _23_System_Collections_IList_get_IsReadOnly;
	VirtualInvokeData _24_System_Collections_IList_get_IsFixedSize;
	VirtualInvokeData _25_System_Collections_IList_IndexOf;
	VirtualInvokeData _26_System_Collections_IList_Insert;
	VirtualInvokeData _27_System_Collections_IList_Remove;
	VirtualInvokeData _28_RemoveAt;
	VirtualInvokeData _29_System_Collections_ICollection_CopyTo;
	VirtualInvokeData _30_unknown;
	VirtualInvokeData _31_System_Collections_ICollection_get_SyncRoot;
	VirtualInvokeData _32_System_Collections_ICollection_get_IsSynchronized;
	VirtualInvokeData _33_get_Item;
	VirtualInvokeData _34_get_Count;
};
struct System_Collections_Generic_List____________c {
	Il2CppClass_1 _1;
	struct System_Collections_Generic_List____________StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Collections_Generic_List____________VTable vtable;
};
struct System_Collections_Generic_List____________o {
	System_Collections_Generic_List____________c* klass;
	void* monitor;
	System_Collections_Generic_List____________Fields fields;
};

struct UnityEngine_GameObject_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct UnityEngine_GameObject_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_GameObject_VTable vtable;
};
struct UnityEngine_GameObject_o {
	UnityEngine_GameObject_c* klass;
	void* monitor;
	UnityEngine_GameObject_Fields fields;

	static UnityEngine_GameObject_o* CreatePrimitive(int type)
	{
		return _CreatePrimitive(type, 0);
	}

	void SetTag(const char* tag)
	{
		System_String_o* str = SystemStringCtor(tag, 0, strlen(tag), 0);

		_SetTag(this, str, 0);
	}

	UnityEngine_Component_o* AddComponent(const char* compName)
	{
		System_String_o* str = SystemStringCtor(compName, 0, strlen(compName), 0);
		System_Type_o* type = GetTypeByName(str, 0);

		return _AddComponent(this, type, 0);
	}

	UnityEngine_Component_array* GetComponents(const char* typeName)
	{
		System_String_o* typeStr = SystemStringCtor(typeName, 0, strlen(typeName), 0);
		System_Type_o* type = GetTypeByName(typeStr, 0);
		return _GetComponents(this, type, 0);
	}

	UnityEngine_Component_o* GetComponent(const char* typeName)
	{
		System_String_o* typeStr = SystemStringCtor(typeName, 0, strlen(typeName), 0);
		System_Type_o* type = GetTypeByName(typeStr, 0);
		return _GetComponent(this, type, 0);
	}
};

struct UnityEngine_Collider_Fields : UnityEngine_Component_Fields {
};
struct UnityEngine_Collider_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct UnityEngine_Collider_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Collider_VTable vtable;
};
struct UnityEngine_Collider_o {
	UnityEngine_Collider_c* klass;
	void* monitor;
	UnityEngine_Collider_Fields fields;

	UnityEngine_Rigidbody_o* GetRigidBody()
	{
		return _GetRigidBody(this, 0);
	}

	void SetEnabled(bool val)
	{
		_ColliderSetEnabled(this, val, 0);
	}
};

struct System_Object_array {
	Il2CppObject obj;
	Il2CppArrayBounds* bounds;
	il2cpp_array_size_t max_length;
	Il2CppObject* m_Items[65535];
};

struct UnityEngine_Color_Fields {
	float r;
	float g;
	float b;
	float a;
};

struct UnityEngine_Color_o {
	UnityEngine_Color_Fields fields;
};

struct UnityEngine_Light_Fields : UnityEngine_Behaviour_Fields {
	int32_t m_BakedIndex;
};
struct UnityEngine_Light_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct UnityEngine_Light_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Light_VTable vtable;
};
struct UnityEngine_Light_o {
	UnityEngine_Light_c* klass;
	void* monitor;
	UnityEngine_Light_Fields fields;

	void SetRange(float range)
	{
		_SetRange(this, range, 0);
	}

	void SetColor(float r, float g, float b, float a)
	{
		UnityEngine_Color_o color{};
		color.fields.r = r;
		color.fields.g = g;
		color.fields.b = b;
		color.fields.a = a;
		LightSetColor(this, &color, 0);
	}

	void SetIntensity(float val)
	{
		LightSetIntensity(this, val, 0);
	}
};

struct UnityEngine_Renderer_Fields : UnityEngine_Component_Fields {
};
struct UnityEngine_Renderer_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct UnityEngine_Renderer_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Renderer_VTable vtable;
};
struct UnityEngine_Renderer_o {
	UnityEngine_Renderer_c* klass;
	void* monitor;
	UnityEngine_Renderer_Fields fields;

	UnityEngine_Bounds_o GetBounds()
	{
		UnityEngine_Bounds_o ret{};
		_GetBounds(&ret, this, 0);
		return ret;
	}

	void SetBounds(UnityEngine_Bounds_o bounds)
	{
		_SetBounds(this, &bounds, 0);
	}
};

struct UnityEngine_Animator_Fields : UnityEngine_Behaviour_Fields {
};
struct UnityEngine_Animator_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct UnityEngine_Animator_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Animator_VTable vtable;
};
struct UnityEngine_Animator_o {
	UnityEngine_Animator_c* klass;
	void* monitor;
	UnityEngine_Animator_Fields fields;

	void SetSpeed(float speed)
	{
		_AnimatorSetSpeed(this, speed, 0);
	}
};

struct __declspec(align(8)) Photon_Pun_PhotonNetwork_Fields {
};
struct Photon_Pun_PhotonNetwork_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct Photon_Pun_PhotonNetwork_c {
	Il2CppClass_1 _1;
	struct Photon_Pun_PhotonNetwork_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Photon_Pun_PhotonNetwork_VTable vtable;
};
struct Photon_Pun_PhotonNetwork_o {
	Photon_Pun_PhotonNetwork_c* klass;
	void* monitor;
	Photon_Pun_PhotonNetwork_Fields fields;
};

struct Photon_Pun_PhotonView_Fields : UnityEngine_MonoBehaviour_Fields {
	uint8_t Group;
	int32_t prefixField;
	struct System_Object_array* instantiationDataField;
	struct System_Collections_Generic_List_object__o* lastOnSerializeDataSent;
	struct System_Collections_Generic_List_object__o* syncValues;
	struct System_Object_array* lastOnSerializeDataReceived;
	int32_t Synchronization;
	bool mixedModeIsReliable;
	int32_t OwnershipTransfer;
	int32_t observableSearch;
	struct System_Collections_Generic_List_Component__o* ObservedComponents;
	struct UnityEngine_MonoBehaviour_array* RpcMonoBehaviours;
	bool _IsMine_k__BackingField;
	struct Photon_Realtime_Player_o* _Controller_k__BackingField;
	int32_t _CreatorActorNr_k__BackingField;
	bool _AmOwner_k__BackingField;
	struct Photon_Realtime_Player_o* _Owner_k__BackingField;
	int32_t ownerActorNr;
	int32_t controllerActorNr;
	int32_t sceneViewId;
	int32_t viewIdField;
	int32_t InstantiationId;
	bool isRuntimeInstantiated;
	bool removedFromLocalViewList;
	struct System_Collections_Generic_Queue_PhotonView_CallbackTargetChange__o* CallbackChangeQueue;
	struct System_Collections_Generic_List_IOnPhotonViewPreNetDestroy__o* OnPreNetDestroyCallbacks;
	struct System_Collections_Generic_List_IOnPhotonViewOwnerChange__o* OnOwnerChangeCallbacks;
	struct System_Collections_Generic_List_IOnPhotonViewControllerChange__o* OnControllerChangeCallbacks;
};
struct Photon_Pun_PhotonView_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct Photon_Pun_PhotonView_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Photon_Pun_PhotonView_VTable vtable;
};

struct Photon_Pun_PhotonView_o {
	Photon_Pun_PhotonView_c* klass;
	void* monitor;
	Photon_Pun_PhotonView_Fields fields;

	void SendRPC(const char* rpcName, System_Object_array* params, int target = 0)
	{
		System_String_o* rpcStr = SystemStringCtor(rpcName, 0, strlen(rpcName), 0);
		oRpc(this, rpcStr, target, params, 0);
	}

	void SendTargettedRPC(const char* rpcName, System_Object_array* params)
	{
		System_String_o* rpcStr = SystemStringCtor(rpcName, 0, strlen(rpcName), 0);
		TargettedRPC(this, rpcStr, this->fields._Owner_k__BackingField, params, 0);
	}

	void SendWRPC(const char* rpcName, System_Object_array* params, void* player)
	{
		System_String_o* rpcStr = SystemStringCtor(rpcName, 0, strlen(rpcName), 0);
		TargettedRPC(this, rpcStr, (Photon_Realtime_Player_o*)player, params, 0);
	}
};

struct Network_Fields : Photon_Pun_MonoBehaviourPunCallbacks_Fields {
	struct Player_o* _1__________;
	struct System_Collections_Generic_List_Network_PlayerSpot__o* _2_players;
	struct UnityEngine_Color_array* _3__________;
	struct UnityEngine_Color_array* _4__________;
	struct UnityEngine_Events_UnityEvent_o* _5__________;
	struct UnityEngine_Events_UnityEvent_o* _6__________;
	struct UnityEngine_Events_UnityEvent_o* _7__________;
	struct UnityEngine_Events_UnityEvent_o* _8__________;
	struct Network___________o* _9__________;
	struct Network___________o* _10__________;
	struct Network___________o* _11__________;
	struct Network___________o* _12__________;
	struct UnityEngine_Events_UnityEvent_o* _13__________;
	struct UnityEngine_Events_UnityEvent_o* _14__________;
	struct UnityEngine_Events_UnityEvent_Color__int__o* _15__________;
	struct __________127_o* _16__________;
	bool _17__________;
};
struct Network_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_unknown;
	VirtualInvokeData _7_unknown;
	VirtualInvokeData _8_unknown;
	VirtualInvokeData _9_unknown;
	VirtualInvokeData _10_unknown;
	VirtualInvokeData _11_unknown;
	VirtualInvokeData _12_unknown;
	VirtualInvokeData _13_unknown;
	VirtualInvokeData _14_unknown;
	VirtualInvokeData _15_unknown;
	VirtualInvokeData _16_unknown;
	VirtualInvokeData _17_unknown;
	VirtualInvokeData _18_unknown;
	VirtualInvokeData _19_unknown;
	VirtualInvokeData _20_unknown;
	VirtualInvokeData _21_unknown;
	VirtualInvokeData _22_unknown;
	VirtualInvokeData _23_unknown;
	VirtualInvokeData _24_unknown;
	VirtualInvokeData _25_unknown;
	VirtualInvokeData _26_unknown;
	VirtualInvokeData _27_unknown;
	VirtualInvokeData _28_OnEnable;
	VirtualInvokeData _29_OnDisable;
	VirtualInvokeData _30_OnConnected;
	VirtualInvokeData _31_OnLeftRoom;
	VirtualInvokeData _32_OnMasterClientSwitched;
	VirtualInvokeData _33_OnCreateRoomFailed;
	VirtualInvokeData _34_OnJoinRoomFailed;
	VirtualInvokeData _35_OnCreatedRoom;
	VirtualInvokeData _36_OnJoinedLobby;
	VirtualInvokeData _37_OnLeftLobby;
	VirtualInvokeData _38_OnDisconnected;
	VirtualInvokeData _39_OnRegionListReceived;
	VirtualInvokeData _40_OnRoomListUpdate;
	VirtualInvokeData _41_OnJoinedRoom;
	VirtualInvokeData _42_OnPlayerEnteredRoom;
	VirtualInvokeData _43_OnPlayerLeftRoom;
	VirtualInvokeData _44_OnJoinRandomFailed;
	VirtualInvokeData _45_OnConnectedToMaster;
	VirtualInvokeData _46_OnRoomPropertiesUpdate;
	VirtualInvokeData _47_OnPlayerPropertiesUpdate;
	VirtualInvokeData _48_OnFriendListUpdate;
	VirtualInvokeData _49_OnCustomAuthenticationResponse;
	VirtualInvokeData _50_OnCustomAuthenticationFailed;
	VirtualInvokeData _51_OnWebRpcResponse;
	VirtualInvokeData _52_OnLobbyStatisticsUpdate;
	VirtualInvokeData _53_OnErrorInfo;
};
struct Network_c {
	Il2CppClass_1 _1;
	struct Network_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Network_VTable vtable;
};
struct Network_o {
	Network_c* klass;
	void* monitor;
	Network_Fields fields;
};

struct UnityEngine_Renderer_array {
	Il2CppObject obj;
	Il2CppArrayBounds* bounds;
	il2cpp_array_size_t max_length;
	UnityEngine_Renderer_o* m_Items[65535];
};

struct System_String_Fields {
	int32_t _stringLength;
	wchar_t buffer[256];
};
struct System_String_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_CompareTo;
	VirtualInvokeData _5_System_Collections_IEnumerable_GetEnumerator;
	VirtualInvokeData _6_System_Collections_Generic_IEnumerable_System_Char__GetEnumerator;
	VirtualInvokeData _7_CompareTo;
	VirtualInvokeData _8_Equals;
	VirtualInvokeData _9_GetTypeCode;
	VirtualInvokeData _10_System_IConvertible_ToBoolean;
	VirtualInvokeData _11_System_IConvertible_ToChar;
	VirtualInvokeData _12_System_IConvertible_ToSByte;
	VirtualInvokeData _13_System_IConvertible_ToByte;
	VirtualInvokeData _14_System_IConvertible_ToInt16;
	VirtualInvokeData _15_System_IConvertible_ToUInt16;
	VirtualInvokeData _16_System_IConvertible_ToInt32;
	VirtualInvokeData _17_System_IConvertible_ToUInt32;
	VirtualInvokeData _18_System_IConvertible_ToInt64;
	VirtualInvokeData _19_System_IConvertible_ToUInt64;
	VirtualInvokeData _20_System_IConvertible_ToSingle;
	VirtualInvokeData _21_System_IConvertible_ToDouble;
	VirtualInvokeData _22_System_IConvertible_ToDecimal;
	VirtualInvokeData _23_System_IConvertible_ToDateTime;
	VirtualInvokeData _24_ToString;
	VirtualInvokeData _25_System_IConvertible_ToType;
	VirtualInvokeData _26_Clone;
};
struct System_String_c {
	Il2CppClass_1 _1;
	struct System_String_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_String_VTable vtable;
};
struct System_String_o {
	System_String_c* klass;
	void* monitor;
	System_String_Fields fields;
};

struct __declspec(align(8)) System_Collections_Generic_List_Network_PlayerSpot__Fields {
	struct Network_PlayerSpot_array* _items;
	int32_t _size;
	int32_t _version;
	Il2CppObject* _syncRoot;
};
struct System_Collections_Generic_List_Network_PlayerSpot__VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_set_Item;
	VirtualInvokeData _6_IndexOf;
	VirtualInvokeData _7_Insert;
	VirtualInvokeData _8_unknown;
	VirtualInvokeData _9_unknown;
	VirtualInvokeData _10_System_Collections_Generic_ICollection_T__get_IsReadOnly;
	VirtualInvokeData _11_Add;
	VirtualInvokeData _12_unknown;
	VirtualInvokeData _13_Contains;
	VirtualInvokeData _14_CopyTo;
	VirtualInvokeData _15_Remove;
	VirtualInvokeData _16_System_Collections_Generic_IEnumerable_T__GetEnumerator;
	VirtualInvokeData _17_System_Collections_IEnumerable_GetEnumerator;
	VirtualInvokeData _18_System_Collections_IList_get_Item;
	VirtualInvokeData _19_System_Collections_IList_set_Item;
	VirtualInvokeData _20_System_Collections_IList_Add;
	VirtualInvokeData _21_System_Collections_IList_Contains;
	VirtualInvokeData _22_Clear;
	VirtualInvokeData _23_System_Collections_IList_get_IsReadOnly;
	VirtualInvokeData _24_System_Collections_IList_get_IsFixedSize;
	VirtualInvokeData _25_System_Collections_IList_IndexOf;
	VirtualInvokeData _26_System_Collections_IList_Insert;
	VirtualInvokeData _27_System_Collections_IList_Remove;
	VirtualInvokeData _28_RemoveAt;
	VirtualInvokeData _29_System_Collections_ICollection_CopyTo;
	VirtualInvokeData _30_unknown;
	VirtualInvokeData _31_System_Collections_ICollection_get_SyncRoot;
	VirtualInvokeData _32_System_Collections_ICollection_get_IsSynchronized;
	VirtualInvokeData _33_get_Item;
	VirtualInvokeData _34_get_Count;
};
struct System_Collections_Generic_List_Network_PlayerSpot__c {
	Il2CppClass_1 _1;
	struct System_Collections_Generic_List_Network_PlayerSpot__StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Collections_Generic_List_Network_PlayerSpot__VTable vtable;
};
struct System_Collections_Generic_List_Network_PlayerSpot__o {
	System_Collections_Generic_List_Network_PlayerSpot__c* klass;
	void* monitor;
	System_Collections_Generic_List_Network_PlayerSpot__Fields fields;
};

struct __declspec(align(8)) System_Collections_ArrayList_Fields {
	struct System_Object_array* _items;
	int32_t _size;
	int32_t _version;
	Il2CppObject* _syncRoot;
};
struct System_Collections_ArrayList_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_unknown;
	VirtualInvokeData _7_unknown;
	VirtualInvokeData _8_unknown;
	VirtualInvokeData _9_unknown;
	VirtualInvokeData _10_unknown;
	VirtualInvokeData _11_unknown;
	VirtualInvokeData _12_unknown;
	VirtualInvokeData _13_unknown;
	VirtualInvokeData _14_unknown;
	VirtualInvokeData _15_unknown;
	VirtualInvokeData _16_unknown;
	VirtualInvokeData _17_unknown;
	VirtualInvokeData _18_unknown;
	VirtualInvokeData _19_unknown;
	VirtualInvokeData _20_unknown;
	VirtualInvokeData _21_set_Capacity;
	VirtualInvokeData _22_get_Count;
	VirtualInvokeData _23_get_IsFixedSize;
	VirtualInvokeData _24_get_IsReadOnly;
	VirtualInvokeData _25_get_IsSynchronized;
	VirtualInvokeData _26_get_SyncRoot;
	VirtualInvokeData _27_get_Item;
	VirtualInvokeData _28_set_Item;
	VirtualInvokeData _29_Add;
	VirtualInvokeData _30_AddRange;
	VirtualInvokeData _31_Clear;
	VirtualInvokeData _32_Clone;
	VirtualInvokeData _33_Contains;
	VirtualInvokeData _34_CopyTo;
	VirtualInvokeData _35_CopyTo;
	VirtualInvokeData _36_CopyTo;
	VirtualInvokeData _37_GetEnumerator;
	VirtualInvokeData _38_IndexOf;
	VirtualInvokeData _39_Insert;
	VirtualInvokeData _40_InsertRange;
	VirtualInvokeData _41_Remove;
	VirtualInvokeData _42_RemoveAt;
	VirtualInvokeData _43_RemoveRange;
	VirtualInvokeData _44_Sort;
	VirtualInvokeData _45_Sort;
	VirtualInvokeData _46_ToArray;
	VirtualInvokeData _47_ToArray;
};
struct System_Collections_ArrayList_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	System_Collections_ArrayList_VTable vtable;
};
struct System_Collections_ArrayList_o {
	System_Collections_ArrayList_c* klass;
	void* monitor;
	System_Collections_ArrayList_Fields fields;

	void Construct()
	{
		ArrayListCtor(this, 0);
	}

	int Add(Il2CppObject* obj)
	{
		return _Add(this, obj, 0);
	}

	template<typename T>
	void AddItem(T value, Il2CppClass* TypeInfo)
	{
		Il2CppObject* boxedValue = il2cppValueBox(TypeInfo, &value);
		Add(boxedValue);
	}

	System_Object_array* GetObjArray()
	{
		this->fields._items->max_length = this->fields._size;
		return this->fields._items;
	}
};

struct UnityEngine_Behaviour_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct UnityEngine_Behaviour_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Behaviour_VTable vtable;
};
struct UnityEngine_Behaviour_o {
	UnityEngine_Behaviour_c* klass;
	void* monitor;
	UnityEngine_Behaviour_Fields fields;

	void SetEnabled(bool value)
	{
		_SetEnabled(this, value, 0);
	}
};

struct UnityEngine_MonoBehaviour_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct UnityEngine_MonoBehaviour_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_MonoBehaviour_VTable vtable;
};
struct UnityEngine_MonoBehaviour_o {
	UnityEngine_MonoBehaviour_c* klass;
	void* monitor;
	UnityEngine_MonoBehaviour_Fields fields;
};

struct UnityEngine_Vector3_StaticFields {
	struct UnityEngine_Vector3_o zeroVector;
	struct UnityEngine_Vector3_o oneVector;
	struct UnityEngine_Vector3_o upVector;
	struct UnityEngine_Vector3_o downVector;
	struct UnityEngine_Vector3_o leftVector;
	struct UnityEngine_Vector3_o rightVector;
	struct UnityEngine_Vector3_o forwardVector;
	struct UnityEngine_Vector3_o backVector;
	struct UnityEngine_Vector3_o positiveInfinityVector;
	struct UnityEngine_Vector3_o negativeInfinityVector;
};

struct Photon_Pun_PhotonMessageInfo_Fields {
	int32_t timeInt;
	struct Photon_Realtime_Player_o* Sender;
	struct Photon_Pun_PhotonView_o* photonView;
};

struct Photon_Pun_PhotonMessageInfo_o {
	Photon_Pun_PhotonMessageInfo_Fields fields;
};

struct UnityEngine_AI_NavMeshAgent_Fields : UnityEngine_Behaviour_Fields {
};
struct UnityEngine_AI_NavMeshAgent_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct UnityEngine_AI_NavMeshAgent_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_AI_NavMeshAgent_VTable vtable;
};
struct UnityEngine_AI_NavMeshAgent_o {
	UnityEngine_AI_NavMeshAgent_c* klass;
	void* monitor;
	UnityEngine_AI_NavMeshAgent_Fields fields;

	void SetSpeed(float speed)
	{
		_SetSpeed(this, speed, 0);
	}

	float GetSpeed()
	{
		return _GetSpeed(this, 0);
	}

	void SetAccel(float val)
	{
		_SetAcceleration(this, val, 0);
	}
};

struct __________70_Fields {
	int32_t _________;
	int32_t _1__________;
	struct System_Collections_Generic_List____________o* _2__________;
	struct System_Collections_Generic_List____________o* _3__________;
	int32_t _4__________;
	bool _5__________;
	struct System_String_o* _6__________;
	int32_t _7__________;
	int32_t _8__________;
	bool _9__________;
	int32_t _10__________;
	int32_t _11__________;
	bool _12__________;
};
struct __________70_o {
	__________70_Fields fields;
};

struct GhostController___________Fields {
	int32_t _________;
	int32_t _1__________;
	float _2__________;
	float _3__________;
	float _4__________;
};

struct GhostController___________o {
	GhostController___________Fields fields;
};

struct GhostController_Fields : UnityEngine_MonoBehaviour_Fields {
	struct Photon_Pun_PhotonView_o* view;
	struct __________70_o _2__________;
	bool _3__________;
	struct GhostEventPlayer_o* ghostEventPlayer;
	struct LevelController_o* levelController;
	struct GameController_o* gameController;
	struct SetupPhaseController_o* setupPhaseController;
	struct GhostAI_o* ghost;
	struct UnityEngine_Material_o* _9__________;
	struct UnityEngine_Material_o* _10__________;
	int32_t _11__________;
	bool _12__________;
	float _13__________;
	struct GhostController___________o _14__________;
};
struct GhostController_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_OnPlayerEnteredRoom;
	VirtualInvokeData _5_OnPlayerLeftRoom;
	VirtualInvokeData _6_OnRoomPropertiesUpdate;
	VirtualInvokeData _7_OnPlayerPropertiesUpdate;
	VirtualInvokeData _8_OnMasterClientSwitched;
	VirtualInvokeData _9_OnFriendListUpdate;
	VirtualInvokeData _10_OnCreatedRoom;
	VirtualInvokeData _11_OnCreateRoomFailed;
	VirtualInvokeData _12_OnJoinedRoom;
	VirtualInvokeData _13_OnJoinRoomFailed;
	VirtualInvokeData _14_OnJoinRandomFailed;
	VirtualInvokeData _15_OnLeftRoom;
	VirtualInvokeData _16__________;
	VirtualInvokeData _17__________;
	VirtualInvokeData _18__________;
	VirtualInvokeData _19__________;
	VirtualInvokeData _20__________;
	VirtualInvokeData _21__________;
	VirtualInvokeData _22__________;
	VirtualInvokeData _23__________;
	VirtualInvokeData _24__________;
	VirtualInvokeData _25__________;
	VirtualInvokeData _26__________;
	VirtualInvokeData _27__________;
	VirtualInvokeData _28__________;
	VirtualInvokeData _29__________;
	VirtualInvokeData _30__________;
	VirtualInvokeData _31__________;
	VirtualInvokeData _32__________;
	VirtualInvokeData _33__________;
	VirtualInvokeData _34__________;
	VirtualInvokeData _35__________;
	VirtualInvokeData _36__________;
	VirtualInvokeData _37__________;
	VirtualInvokeData _38__________;
	VirtualInvokeData _39__________;
	VirtualInvokeData _40__________;
	VirtualInvokeData _41__________;
	VirtualInvokeData _42__________;
	VirtualInvokeData _43__________;
	VirtualInvokeData _44__________;
	VirtualInvokeData _45__________;
	VirtualInvokeData _46__________;
	VirtualInvokeData _47__________;
	VirtualInvokeData _48__________;
	VirtualInvokeData _49__________;
	VirtualInvokeData _50__________;
	VirtualInvokeData _51__________;
	VirtualInvokeData _52__________;
	VirtualInvokeData _53__________;
	VirtualInvokeData _54__________;
	VirtualInvokeData _55__________;
	VirtualInvokeData _56__________;
	VirtualInvokeData _57__________;
	VirtualInvokeData _58__________;
	VirtualInvokeData _59__________;
	VirtualInvokeData _60__________;
	VirtualInvokeData _61__________;
	VirtualInvokeData _62__________;
	VirtualInvokeData _63__________;
	VirtualInvokeData _64__________;
	VirtualInvokeData _65__________;
	VirtualInvokeData _66__________;
	VirtualInvokeData _67__________;
	VirtualInvokeData _68__________;
	VirtualInvokeData _69__________;
	VirtualInvokeData _70__________;
	VirtualInvokeData _71__________;
	VirtualInvokeData _72__________;
	VirtualInvokeData _73__________;
	VirtualInvokeData _74__________;
	VirtualInvokeData _75__________;
	VirtualInvokeData _76__________;
	VirtualInvokeData _77__________;
	VirtualInvokeData _78__________;
	VirtualInvokeData _79__________;
	VirtualInvokeData _80__________;
	VirtualInvokeData _81__________;
	VirtualInvokeData _82__________;
	VirtualInvokeData _83__________;
	VirtualInvokeData _84__________;
	VirtualInvokeData _85__________;
	VirtualInvokeData _86__________;
	VirtualInvokeData _87__________;
	VirtualInvokeData _88__________;
	VirtualInvokeData _89__________;
	VirtualInvokeData _90__________;
	VirtualInvokeData _91__________;
	VirtualInvokeData _92__________;
};
struct GhostController_c {
	Il2CppClass_1 _1;
	struct GhostController_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	GhostController_VTable vtable;
};
struct GhostController_o {
	GhostController_c* klass;
	void* monitor;
	GhostController_Fields fields;
};


struct GameController_Fields : Photon_Pun_MonoBehaviourPunCallbacks_Fields {
	struct UnityEngine_Events_UnityEvent_o* _1__________;
	struct UnityEngine_Events_UnityEvent_o* _2__________;
	struct UnityEngine_Events_UnityEvent_o* _3__________;
	struct UnityEngine_Events_UnityEvent_o* _4__________;
	struct UnityEngine_Events_UnityEvent_o* _5__________;
	struct __________65_o* _6__________;
	struct UnityEngine_Events_UnityEvent_o* _7__________;
	struct UnityEngine_Events_UnityEvent_o* _8__________;
	struct __________67_o* _9__________;
	struct __________68_o* _10__________;
	struct __________69_o* _11__________;
	float _12__________;
	struct SpeechRecognitionController_o* _13__________;
	struct LevelController_o* _14__________;
	struct MultiplayerController_o* _15__________;
	bool _16__________;
	int32_t _17__________;
	struct UnityEngine_Material_o* _18__________;
	bool _19_HighPriestestDrawn;
	struct Recognissimo_Components_SpeechRecognizer_o* _20__________;
};
struct GameController_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4_unknown;
	VirtualInvokeData _5_unknown;
	VirtualInvokeData _6_unknown;
	VirtualInvokeData _7_unknown;
	VirtualInvokeData _8_unknown;
	VirtualInvokeData _9_unknown;
	VirtualInvokeData _10_unknown;
	VirtualInvokeData _11_unknown;
	VirtualInvokeData _12_unknown;
	VirtualInvokeData _13_unknown;
	VirtualInvokeData _14_unknown;
	VirtualInvokeData _15_unknown;
	VirtualInvokeData _16_unknown;
	VirtualInvokeData _17_unknown;
	VirtualInvokeData _18_unknown;
	VirtualInvokeData _19_unknown;
	VirtualInvokeData _20_unknown;
	VirtualInvokeData _21_unknown;
	VirtualInvokeData _22_unknown;
	VirtualInvokeData _23_unknown;
	VirtualInvokeData _24_unknown;
	VirtualInvokeData _25_unknown;
	VirtualInvokeData _26_unknown;
	VirtualInvokeData _27_unknown;
	VirtualInvokeData _28_OnEnable;
	VirtualInvokeData _29_OnDisable;
	VirtualInvokeData _30_OnConnected;
	VirtualInvokeData _31_OnLeftRoom;
	VirtualInvokeData _32_OnMasterClientSwitched;
	VirtualInvokeData _33_OnCreateRoomFailed;
	VirtualInvokeData _34_OnJoinRoomFailed;
	VirtualInvokeData _35_OnCreatedRoom;
	VirtualInvokeData _36_OnJoinedLobby;
	VirtualInvokeData _37_OnLeftLobby;
	VirtualInvokeData _38_OnDisconnected;
	VirtualInvokeData _39_OnRegionListReceived;
	VirtualInvokeData _40_OnRoomListUpdate;
	VirtualInvokeData _41_OnJoinedRoom;
	VirtualInvokeData _42_OnPlayerEnteredRoom;
	VirtualInvokeData _43_OnPlayerLeftRoom;
	VirtualInvokeData _44_OnJoinRandomFailed;
	VirtualInvokeData _45_OnConnectedToMaster;
	VirtualInvokeData _46_OnRoomPropertiesUpdate;
	VirtualInvokeData _47_OnPlayerPropertiesUpdate;
	VirtualInvokeData _48_OnFriendListUpdate;
	VirtualInvokeData _49_OnCustomAuthenticationResponse;
	VirtualInvokeData _50_OnCustomAuthenticationFailed;
	VirtualInvokeData _51_OnWebRpcResponse;
	VirtualInvokeData _52_OnLobbyStatisticsUpdate;
	VirtualInvokeData _53_OnErrorInfo;
};
struct GameController_c {
	Il2CppClass_1 _1;
	struct GameController_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	GameController_VTable vtable;
};
struct GameController_o {
	GameController_c* klass;
	void* monitor;
	GameController_Fields fields;
};
struct GameController_StaticFields {
	struct GameController_o* _________;
};

struct LevelController_Fields : Photon_Pun_MonoBehaviourPun_Fields {
	struct LevelController_SmallMapVariation_array* _1__________;
	struct LevelRoom_o* _2__________;
	struct LevelRoom_o* _3__________;
	struct GhostAI_o* _4__________;
	struct Door_array* _5_doorArray1;
	struct LevelRoom_array* _6__________;
	struct LevelRoom_array* _7__________;
	struct UnityEngine_Transform_array* _8__________;
	struct UnityEngine_Transform_array* _9__________;
	struct LevelRoom_o* _10__________;
	bool _11__________;
	struct FuseBox_o* _12__________;
	struct System_Collections_Generic_List_JournalController__o* _13__________;
	struct GameController_o* _14__________;
	struct SoundController_o* soundController;
	struct ItemSpawner_o* _16__________;
	struct Door_array* _17_doorArray2;
	struct LevelArea_array* _18__________;
	struct System_Collections_Generic_List_Crucifix__o* _19__________;
	struct System_Collections_Generic_List_FireSource__o* _20__________;
	struct System_Collections_Generic_List_PhotonObjectInteract__o* _21__________;
	struct System_String_array* _22__________;
	struct System_String_array* _23__________;
	struct System_String_array* _24__________;
	struct Key_o* _25__________;
	struct BlockedZone_array* _26__________;
	int32_t intermediateZonesBlocked;
	int32_t proZonesBlocked;
	int32_t nightmareZonesBlocked;
	struct Obi_ObiSolver_o* _30__________;
	struct UnityEngine_Transform_array* _31__________;
	struct System_Collections_Generic_List_float__o* _32__________;
};
struct LevelController_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct LevelController_c {
	Il2CppClass_1 _1;
	struct LevelController_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	LevelController_VTable vtable;
};
struct LevelController_o {
	LevelController_c* klass;
	void* monitor;
	LevelController_Fields fields;
};

struct Prop_Fields : UnityEngine_MonoBehaviour_Fields {
	struct PhotonObjectInteract_o* _________;
	bool kinematicOnStart;
	bool hostOnlyPhysics;
	float requiredImpactForce;
	bool _4__________;
	struct UnityEngine_AudioClip_array* impactClips;
	struct UnityEngine_Events_UnityEvent_Collision__o* OnImpact;
};

struct UnityEngine_Ray_Fields {
	struct UnityEngine_Vector3_o m_Origin;
	struct UnityEngine_Vector3_o m_Direction;
};

struct UnityEngine_RaycastHit_Fields {
	struct UnityEngine_Vector3_o m_Point;
	struct UnityEngine_Vector3_o m_Normal;
	uint32_t m_FaceID;
	float m_Distance;
	struct UnityEngine_Vector2_o m_UV;
	int32_t m_Collider;
};

struct UnityEngine_Ray_o {
	UnityEngine_Ray_Fields fields;
};

struct UnityEngine_RaycastHit_o {
	UnityEngine_RaycastHit_Fields fields;
};

struct UnityEngine_RaycastHit_array {
	Il2CppObject obj;
	Il2CppArrayBounds* bounds;
	il2cpp_array_size_t max_length;
	UnityEngine_RaycastHit_o m_Items[65535];
};

struct Equipment_Fields : Prop_Fields {
	struct StoreItem_o* _________;
	bool _1__________;
	bool _2__________;
	bool _3__________;
	bool _4__________;
	struct UnityEngine_Vector3_o _5__________;
	struct UnityEngine_Vector3_o _6__________;
	struct UnityEngine_LayerMask_o _8__________;
	float _9__________;
	float _10__________;
	bool _11__________;
	struct UnityEngine_Transform_o* _12__________;
	struct UnityEngine_Transform_o* _13__________;
	struct UnityEngine_Transform_o* _14__________;
	struct UnityEngine_Renderer_array* _15__________;
	struct UnityEngine_Vector3_o _16__________;
	struct UnityEngine_Vector3_o _17__________;
	bool _18__________;
	bool _19__________;
	bool _20__________;
	bool _21__________;
	struct Tripod_o* _22__________;
	bool _23__________;
	bool _24__________;
	bool _25__________;
	struct Noise_o* _26__________;
	struct UnityEngine_AudioClip_o* _27__________;
	struct UnityEngine_AudioClip_o* _28__________;
	bool _29__________;
	bool _30__________;
	bool _31__________;
	bool _32__________;
	struct DG_Tweening_Sequence_o* _33__________;
	bool _34__________;
	float _35__________;
	struct TierSocket_o* _36__________;
	struct UnityEngine_Ray_o _37__________;
	struct UnityEngine_RaycastHit_o _38__________;
	struct System_String_o* _39__________;
	struct System_String_o* _40__________;
};

struct CursedItem_Fields : Equipment_Fields {
	bool _________;
	bool _1__________;
	bool _2__________;
};

struct OuijaBoard_Fields : CursedItem_Fields {
	struct System_Collections_Generic_List____________o* _________;
	struct UnityEngine_Transform_o* _1__________;
	struct System_Collections_Generic_List_Transform__o* _2__________;
	struct System_Collections_Generic_List_string__o* _3__________;
	struct UnityEngine_Renderer_o* rend;
	struct Evidence_o* evidence;
	struct UnityEngine_Color_o glowColor;
	struct UnityEngine_MeshRenderer_array* brokenPieces;
	struct UnityEngine_ParticleSystem_o* breakParticles;
	struct UnityEngine_AudioClip_o* breakSound;
	struct UnityEngine_AudioClip_o* moveSound;
	struct DG_Tweening_Sequence_o* _11__________;
	struct System_String_o* _12__________;
	struct System_String_o* _13__________;
	struct System_String_o* _14__________;
	bool _15__________;
	bool _16__________;
	struct VoiceRecognitionUI_o* pcVoiceRecognitionUI;
	struct VoiceRecognitionUI_o* vrVoiceRecognitionUI;
	struct VoiceRecognitionUI_o* _19__________;
	bool _20__________;
	bool _21__________;
};
struct OuijaBoard_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4__________;
	VirtualInvokeData _5__________;
	VirtualInvokeData _6_SecondaryUse;
	VirtualInvokeData _7__________;
	VirtualInvokeData _8__________;
	VirtualInvokeData _9__________;
	VirtualInvokeData _10__________;
	VirtualInvokeData _11__________;
	VirtualInvokeData _12__________;
	VirtualInvokeData _13_Awake;
	VirtualInvokeData _14__________;
	VirtualInvokeData _15__________;
	VirtualInvokeData _16__________;
	VirtualInvokeData _17__________;
	VirtualInvokeData _18__________;
	VirtualInvokeData _19__________;
	VirtualInvokeData _20__________;
	VirtualInvokeData _21__________;
	VirtualInvokeData _22__________;
	VirtualInvokeData _23__________;
	VirtualInvokeData _24__________;
	VirtualInvokeData _25__________;
	VirtualInvokeData _26__________;
	VirtualInvokeData _27__________;
	VirtualInvokeData _28__________;
	VirtualInvokeData _29__________;
	VirtualInvokeData _30__________;
	VirtualInvokeData _31__________;
	VirtualInvokeData _32__________;
	VirtualInvokeData _33__________;
	VirtualInvokeData _34__________;
	VirtualInvokeData _35__________;
	VirtualInvokeData _36__________;
	VirtualInvokeData _37__________;
	VirtualInvokeData _38__________;
	VirtualInvokeData _39__________;
	VirtualInvokeData _40__________;
	VirtualInvokeData _41_Start;
	VirtualInvokeData _42__________;
	VirtualInvokeData _43__________;
	VirtualInvokeData _44__________;
	VirtualInvokeData _45__________;
	VirtualInvokeData _46__________;
	VirtualInvokeData _47__________;
	VirtualInvokeData _48__________;
	VirtualInvokeData _49__________;
	VirtualInvokeData _50__________;
	VirtualInvokeData _51_Grabbed;
	VirtualInvokeData _52__________;
	VirtualInvokeData _53__________;
	VirtualInvokeData _54__________;
	VirtualInvokeData _55__________;
	VirtualInvokeData _56_UseUnpress;
	VirtualInvokeData _57__________;
	VirtualInvokeData _58_IsHolding;
	VirtualInvokeData _59__________;
	VirtualInvokeData _60__________;
	VirtualInvokeData _61__________;
	VirtualInvokeData _62__________;
	VirtualInvokeData _63__________;
	VirtualInvokeData _64__________;
	VirtualInvokeData _65__________;
	VirtualInvokeData _66__________;
	VirtualInvokeData _67__________;
	VirtualInvokeData _68__________;
	VirtualInvokeData _69__________;
	VirtualInvokeData _70__________;
	VirtualInvokeData _71__________;
	VirtualInvokeData _72__________;
	VirtualInvokeData _73__________;
	VirtualInvokeData _74__________;
	VirtualInvokeData _75__________;
	VirtualInvokeData _76__________;
	VirtualInvokeData _77_SecondaryUseUnpress;
	VirtualInvokeData _78__________;
	VirtualInvokeData _79__________;
	VirtualInvokeData _80__________;
	VirtualInvokeData _81__________;
	VirtualInvokeData _82__________;
	VirtualInvokeData _83__________;
	VirtualInvokeData _84_Update;
	VirtualInvokeData _85__________;
	VirtualInvokeData _86__________;
	VirtualInvokeData _87_OnDisable;
	VirtualInvokeData _88__________;
	VirtualInvokeData _89__________;
	VirtualInvokeData _90__________;
	VirtualInvokeData _91_OnEnable;
	VirtualInvokeData _92_Use;
	VirtualInvokeData _93__________;
	VirtualInvokeData _94__________;
	VirtualInvokeData _95__________;
	VirtualInvokeData _96__________;
	VirtualInvokeData _97__________;
	VirtualInvokeData _98__________;
	VirtualInvokeData _99__________;
	VirtualInvokeData _100__________;
	VirtualInvokeData _101__________;
	VirtualInvokeData _102__________;
	VirtualInvokeData _103__________;
	VirtualInvokeData _104__________;
	VirtualInvokeData _105__________;
	VirtualInvokeData _106__________;
	VirtualInvokeData _107__________;
	VirtualInvokeData _108__________;
	VirtualInvokeData _109__________;
	VirtualInvokeData _110__________;
	VirtualInvokeData _111__________;
	VirtualInvokeData _112__________;
	VirtualInvokeData _113__________;
	VirtualInvokeData _114__________;
	VirtualInvokeData _115__________;
	VirtualInvokeData _116__________;
	VirtualInvokeData _117__________;
	VirtualInvokeData _118_PlacingInSocket;
	VirtualInvokeData _119__________;
	VirtualInvokeData _120__________;
	VirtualInvokeData _121__________;
	VirtualInvokeData _122__________;
	VirtualInvokeData _123__________;
	VirtualInvokeData _124__________;
	VirtualInvokeData _125__________;
	VirtualInvokeData _126__________;
	VirtualInvokeData _127__________;
	VirtualInvokeData _128__________;
	VirtualInvokeData _129_PlaceOnTripodNetworked;
	VirtualInvokeData _130__________;
	VirtualInvokeData _131__________;
	VirtualInvokeData _132__________;
	VirtualInvokeData _133__________;
	VirtualInvokeData _134__________;
	VirtualInvokeData _135_GhostUse;
	VirtualInvokeData _136__________;
	VirtualInvokeData _137__________;
	VirtualInvokeData _138__________;
	VirtualInvokeData _139__________;
	VirtualInvokeData _140__________;
	VirtualInvokeData _141__________;
	VirtualInvokeData _142__________;
	VirtualInvokeData _143__________;
	VirtualInvokeData _144__________;
	VirtualInvokeData _145__________;
	VirtualInvokeData _146__________;
	VirtualInvokeData _147__________;
	VirtualInvokeData _148__________;
	VirtualInvokeData _149__________;
	VirtualInvokeData _150__________;
	VirtualInvokeData _151__________;
	VirtualInvokeData _152__________;
	VirtualInvokeData _153__________;
	VirtualInvokeData _154__________;
	VirtualInvokeData _155__________;
	VirtualInvokeData _156__________;
	VirtualInvokeData _157__________;
	VirtualInvokeData _158__________;
	VirtualInvokeData _159__________;
	VirtualInvokeData _160__________;
	VirtualInvokeData _161__________;
	VirtualInvokeData _162__________;
	VirtualInvokeData _163__________;
	VirtualInvokeData _164__________;
	VirtualInvokeData _165__________;
	VirtualInvokeData _166__________;
	VirtualInvokeData _167__________;
	VirtualInvokeData _168__________;
	VirtualInvokeData _169_PlaceNetworked;
	VirtualInvokeData _170__________;
	VirtualInvokeData _171__________;
	VirtualInvokeData _172__________;
	VirtualInvokeData _173__________;
	VirtualInvokeData _174__________;
	VirtualInvokeData _175__________;
	VirtualInvokeData _176__________;
	VirtualInvokeData _177__________;
	VirtualInvokeData _178__________;
	VirtualInvokeData _179__________;
	VirtualInvokeData _180__________;
	VirtualInvokeData _181_GrabNetworked;
	VirtualInvokeData _182__________;
	VirtualInvokeData _183__________;
	VirtualInvokeData _184__________;
	VirtualInvokeData _185__________;
	VirtualInvokeData _186__________;
	VirtualInvokeData _187__________;
	VirtualInvokeData _188__________;
	VirtualInvokeData _189__________;
	VirtualInvokeData _190__________;
	VirtualInvokeData _191__________;
	VirtualInvokeData _192__________;
	VirtualInvokeData _193__________;
	VirtualInvokeData _194__________;
	VirtualInvokeData _195_PlaceInSocketNetworked;
	VirtualInvokeData _196__________;
	VirtualInvokeData _197__________;
	VirtualInvokeData _198__________;
	VirtualInvokeData _199__________;
	VirtualInvokeData _200__________;
	VirtualInvokeData _201__________;
	VirtualInvokeData _202_ChangeMixer;
	VirtualInvokeData _203__________;
	VirtualInvokeData _204__________;
	VirtualInvokeData _205__________;
	VirtualInvokeData _206__________;
	VirtualInvokeData _207__________;
	VirtualInvokeData _208__________;
	VirtualInvokeData _209_GhostUseNetworked;
	VirtualInvokeData _210__________;
	VirtualInvokeData _211__________;
	VirtualInvokeData _212__________;
	VirtualInvokeData _213__________;
	VirtualInvokeData _214__________;
	VirtualInvokeData _215__________;
	VirtualInvokeData _216__________;
	VirtualInvokeData _217__________;
	VirtualInvokeData _218__________;
	VirtualInvokeData _219__________;
	VirtualInvokeData _220_UseNetworked;
	VirtualInvokeData _221__________;
	VirtualInvokeData _222__________;
	VirtualInvokeData _223__________;
	VirtualInvokeData _224__________;
	VirtualInvokeData _225__________;
	VirtualInvokeData _226__________;
	VirtualInvokeData _227__________;
	VirtualInvokeData _228__________;
	VirtualInvokeData _229__________;
	VirtualInvokeData _230__________;
	VirtualInvokeData _231__________;
	VirtualInvokeData _232__________;
	VirtualInvokeData _233_UseUnpressNetworked;
	VirtualInvokeData _234__________;
	VirtualInvokeData _235__________;
	VirtualInvokeData _236_PlaceInSocket;
	VirtualInvokeData _237__________;
	VirtualInvokeData _238__________;
	VirtualInvokeData _239__________;
	VirtualInvokeData _240__________;
	VirtualInvokeData _241__________;
	VirtualInvokeData _242__________;
	VirtualInvokeData _243__________;
	VirtualInvokeData _244__________;
	VirtualInvokeData _245__________;
	VirtualInvokeData _246__________;
	VirtualInvokeData _247__________;
	VirtualInvokeData _248__________;
	VirtualInvokeData _249__________;
	VirtualInvokeData _250__________;
	VirtualInvokeData _251__________;
	VirtualInvokeData _252__________;
	VirtualInvokeData _253__________;
	VirtualInvokeData _254__________;
	VirtualInvokeData _255_BreakItem;
	VirtualInvokeData _256__________;
	VirtualInvokeData _257__________;
	VirtualInvokeData _258__________;
	VirtualInvokeData _259__________;
	VirtualInvokeData _260__________;
	VirtualInvokeData _261__________;
	VirtualInvokeData _262__________;
	VirtualInvokeData _263__________;
	VirtualInvokeData _264__________;
	VirtualInvokeData _265__________;
	VirtualInvokeData _266__________;
	VirtualInvokeData _267__________;
	VirtualInvokeData _268__________;
	VirtualInvokeData _269__________;
	VirtualInvokeData _270__________;
	VirtualInvokeData _271__________;
	VirtualInvokeData _272__________;
	VirtualInvokeData _273__________;
	VirtualInvokeData _274__________;
	VirtualInvokeData _275_InitNetworked;
	VirtualInvokeData _276__________;
	VirtualInvokeData _277__________;
	VirtualInvokeData _278__________;
	VirtualInvokeData _279__________;
	VirtualInvokeData _280__________;
	VirtualInvokeData _281__________;
	VirtualInvokeData _282__________;
	VirtualInvokeData _283__________;
	VirtualInvokeData _284__________;
	VirtualInvokeData _285__________;
	VirtualInvokeData _286__________;
	VirtualInvokeData _287__________;
	VirtualInvokeData _288__________;
	VirtualInvokeData _289__________;
	VirtualInvokeData _290__________;
	VirtualInvokeData _291__________;
	VirtualInvokeData _292__________;
	VirtualInvokeData _293__________;
	VirtualInvokeData _294__________;
	VirtualInvokeData _295__________;
	VirtualInvokeData _296__________;
	VirtualInvokeData _297__________;
	VirtualInvokeData _298__________;
	VirtualInvokeData _299__________;
	VirtualInvokeData _300__________;
	VirtualInvokeData _301__________;
	VirtualInvokeData _302__________;
	VirtualInvokeData _303__________;
	VirtualInvokeData _304__________;
	VirtualInvokeData _305__________;
	VirtualInvokeData _306__________;
	VirtualInvokeData _307__________;
	VirtualInvokeData _308__________;
	VirtualInvokeData _309__________;
	VirtualInvokeData _310__________;
	VirtualInvokeData _311__________;
};
struct OuijaBoard_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	OuijaBoard_VTable vtable;
};
struct OuijaBoard_o {
	OuijaBoard_c* klass;
	void* monitor;
	OuijaBoard_Fields fields;
};

struct FirstPersonController_Fields : UnityEngine_MonoBehaviour_Fields {
	bool canMove;
	bool canTurn;
	bool m_IsWalking;
	bool canSprint;
	float m_RunstepLenghten;
	float m_StickToGroundForce;
	float m_GravityMultiplier;
	struct MouseLook_o* m_MouseLook;
	bool m_UseFovKick;
	struct UnityStandardAssets_Utility_FOVKick_o* m_FovKick;
	bool m_UseHeadBob;
	bool m_ToggleSprint;
	struct UnityStandardAssets_Utility_CurveControlledBob_o* m_HeadBob;
	float m_StepInterval;
	struct UnityEngine_Camera_o* m_Camera;
	struct UnityEngine_Vector2_o m_Input;
	struct UnityEngine_Vector3_o m_MoveDir;
	struct UnityEngine_CharacterController_o* m_CharacterController;
	int32_t m_CollisionFlags;
	float m_StepCycle;
	float m_NextStep;
	bool m_Crouching;
	bool wasWalking;
	float currentSpeed;
	struct UnityEngine_Vector3_o desiredMove;
	struct UnityEngine_RaycastHit_o hitInfo;
	struct UnityEngine_Events_UnityEvent_o* OnStartSprint;
	struct UnityEngine_Events_UnityEvent_o* OnStartWalk;
};

struct FirstPersonController_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};

struct FirstPersonController_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	FirstPersonController_VTable vtable;
};

struct FirstPersonController_o {
	FirstPersonController_c* klass;
	void* monitor;
	FirstPersonController_Fields fields;
};

struct __declspec(align(8)) Network_PlayerSpot_Fields {
	bool playerReady;
	int32_t playerCharacterIndex;
	struct Photon_Realtime_Player_o* photonPlayer;
	struct System_String_o* unityPlayerID;
	int32_t experience;
	int32_t level;
	int32_t prestige;
	struct Player_o* player;
	float playerVolume;
	struct System_String_o* accountName;
	bool isKicked;
	bool isHacker;
	bool isBlocked;
	struct __________72_array* roleBadges;
	int32_t role;
	int32_t prestigeIndex;
	bool prestigeTheme;
	struct Contract_o* votedContract;
	int32_t platformType;
	int32_t legacyLevel;
	int32_t legacyAccent;
	int32_t legacyBackground;
	int32_t legacyColour;
	struct System_Collections_Generic_List_PlayerEquipment__o* playerEquipment;
	bool hasBroughtItems;
	int32_t totalEquipmentCost;
};

struct Network_PlayerSpot_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};

struct Network_PlayerSpot_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Network_PlayerSpot_VTable vtable;
};

struct Network_PlayerSpot_o {
	Network_PlayerSpot_c* klass;
	void* monitor;
	Network_PlayerSpot_Fields fields;
};

struct Network_PlayerSpot_array {
	Il2CppObject obj;
	Il2CppArrayBounds* bounds;
	il2cpp_array_size_t max_length;
	Network_PlayerSpot_o* m_Items[65535];
};

struct UnityEngine_Camera_Fields : UnityEngine_Behaviour_Fields {
};
struct UnityEngine_Camera_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct UnityEngine_Camera_c {
	Il2CppClass_1 _1;
	struct UnityEngine_Camera_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	UnityEngine_Camera_VTable vtable;
};
struct UnityEngine_Camera_o {
	UnityEngine_Camera_c* klass;
	void* monitor;
	UnityEngine_Camera_Fields fields;

	void CopyTo(UnityEngine_Camera_o* copyTo)
	{
		_CopyFrom(this, copyTo, 0);
	}

	void SetActive(bool bActive)
	{
		UnityEngine_GameObject_o* gameObj = GetGameObject((UnityEngine_Component_o*)this, 0);
		_SetActive(gameObj, bActive, 0);
	}

	UnityEngine_Transform_o* GetTransform()
	{
		return _ObjectGetTransform((UnityEngine_GameObject_o*)this, 0);
	}
};

struct GhostModel_Fields : Photon_Pun_MonoBehaviourPun_Fields {
	struct GhostAI_o* _________;
	struct UnityEngine_Renderer_array* myRends;
	struct System_Collections_Generic_List_Material__o* _2__________;
	struct UnityEngine_Animator_o* _3_animator;
	struct UnityEngine_AudioClip_o* _4__________;
	struct UnityEngine_AudioClip_o* _5__________;
	struct System_Collections_Generic_List_AudioClip__o* _6__________;
	struct UnityEngine_Transform_o* _7__________;
	struct System_String_o* _8__________;
	bool _9__________;
	bool _10__________;
	struct PhotoValues_o* _11__________;
	struct UnityEngine_ParticleSystem_o* _12__________;
	struct DG_Tweening_Sequence_o* _13__________;
	struct DOTSSignal_o* _14__________;
};
struct GhostModel_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct GhostModel_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	GhostModel_VTable vtable;
};
struct GhostModel_o {
	GhostModel_c* klass;
	void* monitor;
	GhostModel_Fields fields;
};

struct GhostModel_array {
	Il2CppObject obj;
	Il2CppArrayBounds* bounds;
	il2cpp_array_size_t max_length;
	GhostModel_o* m_Items[65535];
};

struct LevelRoom_Fields : UnityEngine_MonoBehaviour_Fields {
	struct System_Collections_Generic_List_Player__o* _________;
	struct System_Collections_Generic_List_LightSwitch__o* _1__________;
	struct Door_array* _2__________;
	struct System_Collections_Generic_List_Collider__o* roomColliders;
	struct UnityEngine_Transform_o* _4__________;
	struct UnityEngine_AudioReverbZone_o* audioReverbZone;
	int32_t _6__________;
	struct UnityEngine_BoxCollider_o* _7__________;
	int32_t _8__________;
	struct System_String_o* _9__________;
	float _10__________;
	float _11__________;
	float _12__________;
	float _17__________;
	bool _18__________;
	bool _19__________;
	bool _20__________;
	bool _21__________;
};
struct LevelRoom_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct LevelRoom_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	LevelRoom_VTable vtable;
};
struct LevelRoom_o {
	LevelRoom_c* klass;
	void* monitor;
	LevelRoom_Fields fields;
};

struct GhostInteraction_Fields : UnityEngine_MonoBehaviour_Fields {
	struct GhostAI_o* ghostAI;
	struct Photon_Pun_PhotonView_o* view;
	struct System_Collections_Generic_List_AudioClip__o* throwingNoises;
	struct System_Collections_Generic_List_AudioClip__o* _________;
	struct System_Collections_Generic_List_AudioClip__o* _4__________;
	float _5__________;
	float _6__________;
	struct UnityEngine_Transform_o* footstepSpawnPoint;
	bool _8__________;
	float _9__________;
	int32_t _10__________;
	struct System_String_o* _11__________;
};
struct GhostInteraction_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct GhostInteraction_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	GhostInteraction_VTable vtable;
};
struct GhostInteraction_o {
	GhostInteraction_c* klass;
	void* monitor;
	GhostInteraction_Fields fields;
};

struct GhostActivity_Fields : UnityEngine_MonoBehaviour_Fields {
	struct System_Collections_Generic_List_PhotonObjectInteract__o* objectsToInteractWith;
	struct System_Collections_Generic_List_PhotonObjectInteract__o* _________;
	struct GhostAI_o* ghostAI;
	float _3__________;
	bool _4__________;
	struct LevelController_o* _5__________;
	struct SetupPhaseController_o* _6__________;
	struct SoundController_o* _7__________;
	struct UnityEngine_BoxCollider_o* boxCollider;
	struct UnityEngine_Vector3_o _9__________;
	float _10__________;
};
struct GhostActivity_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct GhostActivity_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	GhostActivity_VTable vtable;
};
struct GhostActivity_o {
	GhostActivity_c* klass;
	void* monitor;
	GhostActivity_Fields fields;
};

struct GhostAI_Fields : UnityEngine_MonoBehaviour_Fields {
	struct __________55_o* _________;
	int32_t _1_state; //state
	struct Photon_Pun_PhotonView_o* _2_view;
	struct GhostInfo_o* _3__________;
	struct UnityEngine_AI_NavMeshAgent_o* _4_NavMeshAgent;
	struct GhostAudio_o* _5_audio;
	struct GhostInteraction_o* _6_interaction;
	struct GhostActivity_o* _7_activity;
	struct GhostModel_o* _8_model;
	struct GhostModel_o* eventModel;
	struct GhostModel_array* _10__________;
	struct GhostModel_array* _11__________;
	bool _12_b1;
	int32_t _13__________;
	struct System_Collections_Generic_List_Vector3__o* _14__positions;
	float _15_float1;
	struct SanityDrainer_o* _16_sanityDrainer;
	bool _17_appearing;
	struct UnityEngine_LayerMask_o _18__________;
	struct UnityEngine_Transform_o* _19__________;
	struct UnityEngine_Transform_o* _20__________;
	struct UnityEngine_Transform_o* _21__________;
	float _22_ghostSpeed;
	float _23_float3;
	float _24_float4;
	bool _25_b3;
	bool _26_b4;
	struct UnityEngine_Vector3_o _27__________;
	struct UnityEngine_GameObject_o* _28__________;
	bool _29_b5;
	bool _30_b6;
	bool _31_b7;
	bool _32_b8;
	struct WhiteSage_o* _33_whiteSage;
	float _34_float5;
	bool _35_b9;
	bool _36_b10;
	bool _37_b11;
	struct Player_o* _38__________;
	int32_t _39__________;
	struct UnityEngine_Vector3_o _40__________; //fc
	struct System_Single_array* _41__________;
	struct System_Single_array* _42__________;
	struct System_Single_array* _43__________;
	int32_t _44__________;
	int32_t _45__________;
	int32_t _46__________;
	int32_t _47__________;
	int32_t _48__________;
	struct System_Single_array* _49__________;
	struct System_Single_array* _50__________;
	struct System_Single_array* _51__________;
	float _52_float6;
	struct System_Int32_array* _53__________;
	struct System_Int32_array* _54__________;
	struct System_Int32_array* _55__________;
	struct System_Int32_array* _56__________;
};

struct GhostAI_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct GhostAI_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	GhostAI_VTable vtable;
};

struct GhostAI_o {
	GhostAI_c* klass;
	void* monitor;
	GhostAI_Fields fields;

	void Appear()
	{
		_Appear(this, 4, 0);
	}

	void UnAppear()
	{
		_UnAppear(this, 0);
	}

	void FlashAppear()
	{
		_FlashAppear(this, 0);
	}

	UnityEngine_Transform_o* GetTransform()
	{
		return _GetTransform((UnityEngine_Component_o*)this, 0);
	}

	UnityEngine_Vector3_o GetPosition()
	{
		UnityEngine_Transform_o* transform = _GetTransform((UnityEngine_Component_o*)this, 0);

		return transform->GetPosition();
	}

	UnityEngine_Vector3_o GetForward()
	{
		UnityEngine_Transform_o* transform = _GetTransform((UnityEngine_Component_o*)this, 0);

		return transform->GetForwardVector();
	}

	void SetActive(bool bActive)
	{
		UnityEngine_GameObject_o* gameObj = GetGameObject((UnityEngine_Component_o*)this, 0);
		_SetActive(gameObj, bActive, 0);
	}

	void SetModel(GhostModel_o* model)
	{
		_SetGhostModel(this, model, true, 0);
	}

	void SetModelInt(int model)
	{
		_SetGhostModelInt(this, model, true, 0);
	}
};

struct Player_Fields : UnityEngine_MonoBehaviour_Fields {
	struct Photon_Pun_PhotonView_o* _view;
	bool _1_dead;
	bool _2__________;
	int32_t _3__________;
	struct PlayerCharacter_o* _4_playerCharacter;
	struct ClosetZone_o* _5_closestZone;
	struct UnityEngine_GameObject_o* _6__________;
	struct UnityEngine_Transform_o* _7__________;
	struct System_Collections_Generic_List_KeyInfo__o* _8__________;
	struct UnityEngine_Camera_o* _9__________;
	struct LevelRoom_o* _10_levelRoom;
	struct UnityEngine_Transform_o* _11__________;
	struct PhotonObjectInteract_o* _12__________;
	struct PhotonObjectInteract_o* _13__________;
	struct UnityEngine_GameObject_array* _14__________;
	struct UnityEngine_GameObject_o* _15__________;
	struct UnityEngine_LayerMask_o _16__________;
	struct HeadMountedSocket_o* _17__________;
	struct UnityEngine_Transform_o* _18__________;
	struct UnityEngine_Transform_o* _19__________;
	struct UnityEngine_GameObject_o* _20__________;
	struct DeadPlayer_o* _21_deadPlayer;
	struct PlayerSanity_o* _22_playerSanity;
	struct PlayerStats_o* _23_playerStats;
	struct FootstepController_o* _24_footstepController;
	struct JournalController_o* _25_journalController;
	struct UnityEngine_Renderer_array* _26__________;
	bool _27__________;
	struct PlayerAudio_o* _28_playerAudio;
	struct PlayerGraphics_o* _29_playerGraphics;
	struct PlayerStamina_o* _30_playerStamina;
	float _31__________;
	bool _32__________;
	struct UnityEngine_CharacterController_o* _33_characterController;
	struct UnityEngine_AudioListener_o* _34__________;
	struct FirstPersonController_o* _35_firstPersonController;
	struct PCPropGrab_o* _36_propGrab;
	struct DragRigidbodyUse_o* _37_dragRigidBodyUse;
	struct PCCanvas_o* _38__________;
	struct PCCrouch_o* _39_PCcrouch;
	struct PCMenu_o* _40__________;
	struct PCControls_o* _41__________;
	struct PCFlashlight_o* _42_PCflashlight;
	struct UnityEngine_Animator_o* _43__________;
	struct UnityEngine_InputSystem_PlayerInput_o* _44__________;
	struct PCItemSway_o* _45__________;
	struct PCItemSway_o* _46__________;
	struct UnityEngine_Transform_o* _47__________;
	struct UnityEngine_XR_Interaction_Toolkit_XRBaseInteractor_o* _48__________;
	struct UnityEngine_XR_Interaction_Toolkit_XRBaseInteractor_o* _49__________;
	struct UnityEngine_Transform_o* _50__________;
	struct VRMovementSettings_o* _51__________;
	struct VRBelt_o* _52__________;
	struct UnityEngine_XR_Interaction_Toolkit_XRSocketInteractor_o* _53__________;
	struct UnityEngine_XR_Interaction_Toolkit_XRSocketInteractor_o* _54__________;
	struct TrailerCamera_o* _55__________;
	struct VRLoading_o* _56__________;
};
struct Player_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct Player_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	Player_VTable vtable;
};

struct Player_o {
	Player_c* klass;
	void* monitor;
	Player_Fields fields;

	UnityEngine_Transform_o* GetTransform()
	{
		return _GetTransform((UnityEngine_Component_o*)this, 0);
	}

	UnityEngine_Vector3_o GetPosition()
	{
		UnityEngine_Transform_o* transform = _GetTransform((UnityEngine_Component_o*)this, 0);

		return transform->GetPosition();
	}

	void SetCamera(UnityEngine_Camera_o* newCam)
	{
		this->fields._9__________ = newCam;
	}

	UnityEngine_Vector3_o GetCameraPosition()
	{
		UnityEngine_Transform_o* transform = _GetTransform((UnityEngine_Component_o*)this->fields._9__________, 0);

		return transform->GetPosition();
	}

	void SetCameraPosition(UnityEngine_Vector3_o pos)
	{
		UnityEngine_Transform_o* transform = _GetTransform((UnityEngine_Component_o*)this->fields._9__________, 0);

		transform->SetPosition(pos);
	}

	void SetCameraRotation(UnityEngine_Quaternion_o rot)
	{
		UnityEngine_Transform_o* transform = _GetTransform((UnityEngine_Component_o*)this->fields._9__________, 0);

		transform->SetRotation(rot.fields.x, rot.fields.y, rot.fields.z, rot.fields.w);
	}

	UnityEngine_Vector3_o GetForward()
	{
		UnityEngine_Transform_o* transform = _GetTransform((UnityEngine_Component_o*)this->fields._9__________, 0);

		return transform->GetForwardVector();
	}

	UnityEngine_Vector3_o GetRight()
	{
		UnityEngine_Transform_o* transform = _GetTransform((UnityEngine_Component_o*)this->fields._9__________, 0);

		return transform->GetRightVector();
	}

	UnityEngine_Vector3_o GetMoveDir()
	{
		return this->fields._35_firstPersonController->fields.desiredMove;
	}

	LevelRoom_o* GetCurrentRoom()
	{
		return this->fields._10_levelRoom;
	}

	void Revive()
	{
		_Revive(this, 0);
	}

	void StartKilling()
	{
		const char* mName = "StartKillingPlayerNetworked";
		System_String_o* StartKillingPlayerNetworked = SystemStringCtor(mName, 0, strlen(mName), 0);

		Il2CppClass* boolTypeInfo = FUNCS::GetClass("mscorlib", "System", "Boolean");
		Il2CppClass* intTypeInfo = FUNCS::GetClass("mscorlib", "System", "Int32");

		Il2CppClass* genericList = FUNCS::GetClass("mscorlib", "System.Collections", "ArrayList");
		System_Collections_ArrayList_o* genArray = (System_Collections_ArrayList_o*)il2cppObjectNew((__int64)genericList);
		genArray->Construct();

		if (genArray)
		{
			bool b1 = false;
			bool b2 = false;

			genArray->AddItem<bool>(b1, boolTypeInfo);
			genArray->AddItem<bool>(b2, boolTypeInfo);

			this->fields._view->SendTargettedRPC("StartKillingPlayerNetworked", genArray->GetObjArray());
		}
		//_StartKilling(this, 0);
	}

	void KillFast()
	{
		/*Il2CppClass* boolTypeInfo = FUNCS::GetClass("mscorlib", "System", "Boolean");
		Il2CppClass* genericList = FUNCS::GetClass("mscorlib", "System.Collections", "ArrayList");
		System_Collections_ArrayList_o* genArray = (System_Collections_ArrayList_o*)il2cppObjectNew((__int64)genericList);
		genArray->Construct();

		if (genArray)
		{
			bool b1 = false;

			genArray->AddItem<bool>(b1, boolTypeInfo);

			this->fields._view->SendRPC("Dead", genArray->GetObjArray());
		}*/
		_Kill(this, true, 0);
	}
};

struct PhotonObjectInteract_Fields : UnityEngine_MonoBehaviour_Fields {
	struct Photon_Pun_PhotonView_o* _________;
	struct Photon_Pun_PhotonTransformView_o* _1__________;
	struct VRGrabbable_o* _2__________;
	struct UnityEngine_Rigidbody_o* _3__________;
	bool _4__________;
	bool _5__________;
	bool _6__________;
	bool _7__________;
	bool _8__________;
	bool _9__________;
	bool _10__________;
	struct Drawer_o* _11__________;
	struct Door_o* _12__________;
	struct UnityEngine_Collider_array* _13__________;
	struct UnityEngine_Collider_array* _14__________;
	struct UnityEngine_Collider_array* _15__________;
	float _16__________;
	struct UnityEngine_Transform_o* _17__________;
	struct UnityEngine_Events_UnityEvent_o* _18__________;
	struct UnityEngine_Events_UnityEvent_o* _19__________;
	struct UnityEngine_Events_UnityEvent_o* _20__________;
	struct UnityEngine_Events_UnityEvent_o* _21__________;
	struct UnityEngine_Events_UnityEvent_o* _22__________;
	struct UnityEngine_Events_UnityEvent_o* _23__________;
	struct UnityEngine_Events_UnityEvent_o* _24__________;
	struct UnityEngine_Events_UnityEvent_o* _25__________;
	struct UnityEngine_Events_UnityEvent_o* _26__________;
	bool _27__________;
	bool _28__________;
	bool _29__________;
	struct UnityEngine_GameObject_o* _30__________;
	struct System_Collections_Generic_List_GameObject__o* myLeftHandModels;
	struct UnityEngine_GameObject_o* _32__________;
	struct System_Collections_Generic_List_GameObject__o* myRightHandModels;
	struct UnityEngine_Vector3_o _34__________;
	struct UnityEngine_Quaternion_o _35__________;
	struct UnityEngine_Vector3_o _36__________;
	struct UnityEngine_Vector3_o _37__________;
	bool _38__________;
	bool _39__________;
	struct UnityEngine_GameObject_o* _40__________;
	struct UnityEngine_GameObject_o* _41__________;
	struct UnityEngine_Transform_o* _42__________;
};
struct PhotonObjectInteract_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct PhotonObjectInteract_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	PhotonObjectInteract_VTable vtable;
};
struct PhotonObjectInteract_o {
	PhotonObjectInteract_c* klass;
	void* monitor;
	PhotonObjectInteract_Fields fields;
};

struct TarotCard_Fields : Photon_Pun_MonoBehaviourPun_Fields {
	struct TarotCards_o* cards;
	struct UnityEngine_MeshFilter_o* meshFilter;
	struct UnityEngine_MeshRenderer_o* meshRend;
	struct UnityEngine_ParticleSystem_o* smoke;
	struct UnityEngine_ParticleSystem_o* sparks;
	struct UnityEngine_Mesh_array* allCardMeshes;
	struct UnityEngine_Color_o foolColor;
	struct UnityEngine_Color_o wheelGoodColor;
	struct UnityEngine_Color_o wheelBadColor;
	struct UnityEngine_Color_o towerColor;
	struct UnityEngine_Color_o devilColor;
	struct UnityEngine_Color_o deathColor;
	struct UnityEngine_Color_o hermitColor;
	struct UnityEngine_Color_o moonColor;
	struct UnityEngine_Color_o sunColor;
	struct UnityEngine_Color_o priestessColor;
	struct UnityEngine_Color_o hangedManColor;
	struct UnityEngine_ParticleSystem_o* foolParticles;
	struct UnityEngine_AudioClip_o* foolClip;
	struct UnityEngine_Color_o brightColor;
	struct PhotonObjectInteract_o* _________;
	struct UnityEngine_Color_o _21__________;
	int32_t _22__________;
	struct UnityEngine_Transform_o* _23__________;
	struct UnityEngine_Vector3_o _24__________;
	struct DG_Tweening_Sequence_o* _25__________;
};
struct TarotCard_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct TarotCard_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	TarotCard_VTable vtable;
};
struct TarotCard_o {
	TarotCard_c* klass;
	void* monitor;
	TarotCard_Fields fields;
};

struct TarotCards_Fields : CursedItem_Fields {
	struct Evidence_o* tarotEvidence;
	struct TarotCard_o* tarotCard;
	struct UnityEngine_Animator_o* leftHandAnim;
	struct UnityEngine_Animator_o* rightHandAnim;
	struct UnityEngine_AudioClip_array* cardDrawClips;
	struct System_Collections_Generic_List_GameObject__o* _________;
	struct TarotCard_o* vrTarotCard;
	struct UnityEngine_Collider_o* vrTarotCardCollider;
};
struct TarotCards_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
	VirtualInvokeData _4__________;
	VirtualInvokeData _5__________;
	VirtualInvokeData _6_SecondaryUse;
	VirtualInvokeData _7__________;
	VirtualInvokeData _8__________;
	VirtualInvokeData _9__________;
	VirtualInvokeData _10__________;
	VirtualInvokeData _11__________;
	VirtualInvokeData _12__________;
	VirtualInvokeData _13_Awake;
	VirtualInvokeData _14__________;
	VirtualInvokeData _15__________;
	VirtualInvokeData _16__________;
	VirtualInvokeData _17__________;
	VirtualInvokeData _18__________;
	VirtualInvokeData _19__________;
	VirtualInvokeData _20__________;
	VirtualInvokeData _21__________;
	VirtualInvokeData _22__________;
	VirtualInvokeData _23__________;
	VirtualInvokeData _24__________;
	VirtualInvokeData _25__________;
	VirtualInvokeData _26__________;
	VirtualInvokeData _27__________;
	VirtualInvokeData _28__________;
	VirtualInvokeData _29__________;
	VirtualInvokeData _30__________;
	VirtualInvokeData _31__________;
	VirtualInvokeData _32__________;
	VirtualInvokeData _33__________;
	VirtualInvokeData _34__________;
	VirtualInvokeData _35__________;
	VirtualInvokeData _36__________;
	VirtualInvokeData _37__________;
	VirtualInvokeData _38__________;
	VirtualInvokeData _39__________;
	VirtualInvokeData _40__________;
	VirtualInvokeData _41_Start;
	VirtualInvokeData _42__________;
	VirtualInvokeData _43__________;
	VirtualInvokeData _44__________;
	VirtualInvokeData _45__________;
	VirtualInvokeData _46__________;
	VirtualInvokeData _47__________;
	VirtualInvokeData _48__________;
	VirtualInvokeData _49__________;
	VirtualInvokeData _50__________;
	VirtualInvokeData _51_Grabbed;
	VirtualInvokeData _52__________;
	VirtualInvokeData _53__________;
	VirtualInvokeData _54__________;
	VirtualInvokeData _55__________;
	VirtualInvokeData _56_UseUnpress;
	VirtualInvokeData _57__________;
	VirtualInvokeData _58_IsHolding;
	VirtualInvokeData _59__________;
	VirtualInvokeData _60__________;
	VirtualInvokeData _61__________;
	VirtualInvokeData _62__________;
	VirtualInvokeData _63__________;
	VirtualInvokeData _64__________;
	VirtualInvokeData _65__________;
	VirtualInvokeData _66__________;
	VirtualInvokeData _67__________;
	VirtualInvokeData _68__________;
	VirtualInvokeData _69__________;
	VirtualInvokeData _70__________;
	VirtualInvokeData _71__________;
	VirtualInvokeData _72__________;
	VirtualInvokeData _73__________;
	VirtualInvokeData _74__________;
	VirtualInvokeData _75__________;
	VirtualInvokeData _76__________;
	VirtualInvokeData _77_SecondaryUseUnpress;
	VirtualInvokeData _78__________;
	VirtualInvokeData _79__________;
	VirtualInvokeData _80__________;
	VirtualInvokeData _81__________;
	VirtualInvokeData _82__________;
	VirtualInvokeData _83__________;
	VirtualInvokeData _84_Update;
	VirtualInvokeData _85__________;
	VirtualInvokeData _86__________;
	VirtualInvokeData _87_OnDisable;
	VirtualInvokeData _88__________;
	VirtualInvokeData _89__________;
	VirtualInvokeData _90__________;
	VirtualInvokeData _91_OnEnable;
	VirtualInvokeData _92_Use;
	VirtualInvokeData _93__________;
	VirtualInvokeData _94__________;
	VirtualInvokeData _95__________;
	VirtualInvokeData _96__________;
	VirtualInvokeData _97__________;
	VirtualInvokeData _98__________;
	VirtualInvokeData _99__________;
	VirtualInvokeData _100__________;
	VirtualInvokeData _101__________;
	VirtualInvokeData _102__________;
	VirtualInvokeData _103__________;
	VirtualInvokeData _104__________;
	VirtualInvokeData _105__________;
	VirtualInvokeData _106__________;
	VirtualInvokeData _107__________;
	VirtualInvokeData _108__________;
	VirtualInvokeData _109__________;
	VirtualInvokeData _110__________;
	VirtualInvokeData _111__________;
	VirtualInvokeData _112__________;
	VirtualInvokeData _113__________;
	VirtualInvokeData _114__________;
	VirtualInvokeData _115__________;
	VirtualInvokeData _116__________;
	VirtualInvokeData _117__________;
	VirtualInvokeData _118_PlacingInSocket;
	VirtualInvokeData _119__________;
	VirtualInvokeData _120__________;
	VirtualInvokeData _121__________;
	VirtualInvokeData _122__________;
	VirtualInvokeData _123__________;
	VirtualInvokeData _124__________;
	VirtualInvokeData _125__________;
	VirtualInvokeData _126__________;
	VirtualInvokeData _127__________;
	VirtualInvokeData _128__________;
	VirtualInvokeData _129_PlaceOnTripodNetworked;
	VirtualInvokeData _130__________;
	VirtualInvokeData _131__________;
	VirtualInvokeData _132__________;
	VirtualInvokeData _133__________;
	VirtualInvokeData _134__________;
	VirtualInvokeData _135_GhostUse;
	VirtualInvokeData _136__________;
	VirtualInvokeData _137__________;
	VirtualInvokeData _138__________;
	VirtualInvokeData _139__________;
	VirtualInvokeData _140__________;
	VirtualInvokeData _141__________;
	VirtualInvokeData _142__________;
	VirtualInvokeData _143__________;
	VirtualInvokeData _144__________;
	VirtualInvokeData _145__________;
	VirtualInvokeData _146__________;
	VirtualInvokeData _147__________;
	VirtualInvokeData _148__________;
	VirtualInvokeData _149__________;
	VirtualInvokeData _150__________;
	VirtualInvokeData _151__________;
	VirtualInvokeData _152__________;
	VirtualInvokeData _153__________;
	VirtualInvokeData _154__________;
	VirtualInvokeData _155__________;
	VirtualInvokeData _156__________;
	VirtualInvokeData _157__________;
	VirtualInvokeData _158__________;
	VirtualInvokeData _159__________;
	VirtualInvokeData _160__________;
	VirtualInvokeData _161__________;
	VirtualInvokeData _162__________;
	VirtualInvokeData _163__________;
	VirtualInvokeData _164__________;
	VirtualInvokeData _165__________;
	VirtualInvokeData _166__________;
	VirtualInvokeData _167__________;
	VirtualInvokeData _168__________;
	VirtualInvokeData _169_PlaceNetworked;
	VirtualInvokeData _170__________;
	VirtualInvokeData _171__________;
	VirtualInvokeData _172__________;
	VirtualInvokeData _173__________;
	VirtualInvokeData _174__________;
	VirtualInvokeData _175__________;
	VirtualInvokeData _176__________;
	VirtualInvokeData _177__________;
	VirtualInvokeData _178__________;
	VirtualInvokeData _179__________;
	VirtualInvokeData _180__________;
	VirtualInvokeData _181_GrabNetworked;
	VirtualInvokeData _182__________;
	VirtualInvokeData _183__________;
	VirtualInvokeData _184__________;
	VirtualInvokeData _185__________;
	VirtualInvokeData _186__________;
	VirtualInvokeData _187__________;
	VirtualInvokeData _188__________;
	VirtualInvokeData _189__________;
	VirtualInvokeData _190__________;
	VirtualInvokeData _191__________;
	VirtualInvokeData _192__________;
	VirtualInvokeData _193__________;
	VirtualInvokeData _194__________;
	VirtualInvokeData _195_PlaceInSocketNetworked;
	VirtualInvokeData _196__________;
	VirtualInvokeData _197__________;
	VirtualInvokeData _198__________;
	VirtualInvokeData _199__________;
	VirtualInvokeData _200__________;
	VirtualInvokeData _201__________;
	VirtualInvokeData _202_ChangeMixer;
	VirtualInvokeData _203__________;
	VirtualInvokeData _204__________;
	VirtualInvokeData _205__________;
	VirtualInvokeData _206__________;
	VirtualInvokeData _207__________;
	VirtualInvokeData _208__________;
	VirtualInvokeData _209_GhostUseNetworked;
	VirtualInvokeData _210__________;
	VirtualInvokeData _211__________;
	VirtualInvokeData _212__________;
	VirtualInvokeData _213__________;
	VirtualInvokeData _214__________;
	VirtualInvokeData _215__________;
	VirtualInvokeData _216__________;
	VirtualInvokeData _217__________;
	VirtualInvokeData _218__________;
	VirtualInvokeData _219__________;
	VirtualInvokeData _220_UseNetworked;
	VirtualInvokeData _221__________;
	VirtualInvokeData _222__________;
	VirtualInvokeData _223__________;
	VirtualInvokeData _224__________;
	VirtualInvokeData _225__________;
	VirtualInvokeData _226__________;
	VirtualInvokeData _227__________;
	VirtualInvokeData _228__________;
	VirtualInvokeData _229__________;
	VirtualInvokeData _230__________;
	VirtualInvokeData _231__________;
	VirtualInvokeData _232__________;
	VirtualInvokeData _233_UseUnpressNetworked;
	VirtualInvokeData _234__________;
	VirtualInvokeData _235__________;
	VirtualInvokeData _236_PlaceInSocket;
	VirtualInvokeData _237__________;
	VirtualInvokeData _238__________;
	VirtualInvokeData _239__________;
	VirtualInvokeData _240__________;
	VirtualInvokeData _241__________;
	VirtualInvokeData _242__________;
	VirtualInvokeData _243__________;
	VirtualInvokeData _244__________;
	VirtualInvokeData _245__________;
	VirtualInvokeData _246__________;
	VirtualInvokeData _247__________;
	VirtualInvokeData _248__________;
	VirtualInvokeData _249__________;
	VirtualInvokeData _250__________;
	VirtualInvokeData _251__________;
	VirtualInvokeData _252__________;
	VirtualInvokeData _253__________;
	VirtualInvokeData _254__________;
	VirtualInvokeData _255_BreakItem;
	VirtualInvokeData _256__________;
	VirtualInvokeData _257__________;
	VirtualInvokeData _258__________;
	VirtualInvokeData _259__________;
	VirtualInvokeData _260__________;
	VirtualInvokeData _261__________;
	VirtualInvokeData _262__________;
	VirtualInvokeData _263__________;
	VirtualInvokeData _264__________;
	VirtualInvokeData _265__________;
	VirtualInvokeData _266__________;
	VirtualInvokeData _267__________;
	VirtualInvokeData _268__________;
	VirtualInvokeData _269__________;
	VirtualInvokeData _270__________;
	VirtualInvokeData _271__________;
	VirtualInvokeData _272__________;
	VirtualInvokeData _273__________;
	VirtualInvokeData _274__________;
	VirtualInvokeData _275_InitNetworked;
	VirtualInvokeData _276__________;
	VirtualInvokeData _277__________;
	VirtualInvokeData _278__________;
	VirtualInvokeData _279__________;
	VirtualInvokeData _280__________;
	VirtualInvokeData _281__________;
	VirtualInvokeData _282__________;
	VirtualInvokeData _283__________;
	VirtualInvokeData _284__________;
	VirtualInvokeData _285__________;
	VirtualInvokeData _286__________;
	VirtualInvokeData _287__________;
	VirtualInvokeData _288__________;
	VirtualInvokeData _289__________;
	VirtualInvokeData _290__________;
	VirtualInvokeData _291__________;
	VirtualInvokeData _292__________;
	VirtualInvokeData _293__________;
	VirtualInvokeData _294__________;
	VirtualInvokeData _295__________;
	VirtualInvokeData _296__________;
	VirtualInvokeData _297__________;
	VirtualInvokeData _298__________;
	VirtualInvokeData _299__________;
	VirtualInvokeData _300__________;
	VirtualInvokeData _301__________;
	VirtualInvokeData _302__________;
	VirtualInvokeData _303__________;
	VirtualInvokeData _304__________;
	VirtualInvokeData _305__________;
	VirtualInvokeData _306__________;
	VirtualInvokeData _307__________;
	VirtualInvokeData _308__________;
	VirtualInvokeData _309__________;
	VirtualInvokeData _310__________;
	VirtualInvokeData _311__________;
};
struct TarotCards_c {
	Il2CppClass_1 _1;
	void* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	TarotCards_VTable vtable;
};
struct TarotCards_o {
	TarotCards_c* klass;
	void* monitor;
	TarotCards_Fields fields;
};

struct CursedItemsController_Fields : UnityEngine_MonoBehaviour_Fields {
	struct OuijaBoard_o* _1__________;
	struct MusicBox_o* musicBox;
	struct TarotCards_o* _3__________;
	struct SummoningCircle_o* _4__________;
	struct HauntedMirror_o* hauntedMirror;
	struct VoodooDoll_o* voodooDoll;
	struct MonkeyPaw_o* _7__________;
	struct UnityEngine_Transform_array* ouijaBoardSpawnSpots;
	struct UnityEngine_Transform_array* musicBoxSpawnSpots;
	struct UnityEngine_Transform_array* tarotCardsSpawnSpots;
	struct UnityEngine_Transform_array* summoningCircleSpawnSpots;
	struct UnityEngine_Transform_array* hauntedMirrorSpawnSpots;
	struct UnityEngine_Transform_array* voodooDollSpawnSpots;
	struct UnityEngine_Transform_array* monkeyPawSpawnSpots;
	struct System_Collections_Generic_List____________o* _15_listEnum;
};
struct CursedItemsController_VTable {
	VirtualInvokeData _0_Equals;
	VirtualInvokeData _1_Finalize;
	VirtualInvokeData _2_GetHashCode;
	VirtualInvokeData _3_ToString;
};
struct CursedItemsController_c {
	Il2CppClass_1 _1;
	struct CursedItemsController_StaticFields* static_fields;
	Il2CppRGCTXData* rgctx_data;
	Il2CppClass_2 _2;
	CursedItemsController_VTable vtable;
};
struct CursedItemsController_o {
	CursedItemsController_c* klass;
	void* monitor;
	CursedItemsController_Fields fields;
};
struct CursedItemsController_StaticFields {
	struct CursedItemsController_o* _________;
};