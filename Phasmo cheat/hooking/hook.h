#pragma once
#include "pch.h"
#include <string>
#include "MinHook.h"
#include "vars.h"

#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")


//uintptr_t GetMethodFromName{};
//uintptr_t GetClassFromName{};
typedef HRESULT(__stdcall* ID3DPresent)(IDXGISwapChain* this_, UINT sync, UINT flags);


typedef void(__stdcall* Player_Update)(Player_o*, MethodInfo*);
typedef void(__stdcall* GhostAI_Update)(GhostAI_o*, MethodInfo*);
typedef void(__stdcall* GhostController__Update)(GhostController_o* _this, const MethodInfo* method);
typedef void(__stdcall* GhostEventPlayer__Update)(GhostEventPlayer_o* _this, const MethodInfo* method);
typedef void(__stdcall* OuijaBoard______PlayMessageSequence___6472225264)(OuijaBoard_o* _this, System_String_o* message, const MethodInfo* method);


typedef bool(__stdcall* UnityEngine_AI_NavMeshAgent__SetDestination)(UnityEngine_AI_NavMeshAgent_o* _this, UnityEngine_Vector3_o* target, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_AI_NavMeshAgent__SetDestination2)(UnityEngine_AI_NavMeshAgent_o* _this, UnityEngine_Vector3_o* target, const MethodInfo* method);

typedef void(__stdcall* UnityEngine_Animator__SetBoolString)(UnityEngine_Animator_o* _this, System_String_o* name, bool value, const MethodInfo* method);
typedef void(__stdcall* UnityEngine_Animator__SetIntegerString)(UnityEngine_Animator_o* _this, System_String_o* name, int32_t value, const MethodInfo* method);

typedef void(__stdcall* FirstPersonController__Update)(FirstPersonController_o* _this, const MethodInfo* method);
typedef void(__stdcall* FirstPersonController__FixedUpdate)(FirstPersonController_o* _this, const MethodInfo* method);

typedef System_Text_RegularExpressions_RegexCharClass_SingleRange_o(__stdcall* System_Collections_Generic_List_RegexCharClass_SingleRange___get_Item)(System_Collections_Generic_List_RegexCharClass_SingleRange__o* _this, int32_t index, void* method);

typedef void(__stdcall* CursedItemsController______testing____25110576)(CursedItemsController_o* _this, const MethodInfo* method);

namespace HOOK
{
	inline bool Hook(void* target, void* hFunc, void** outOriginal)
	{
		MH_STATUS stat = MH_CreateHook(target, hFunc, outOriginal);

		if (stat == MH_OK)
		{
			stat = MH_EnableHook(target);

			if (stat == MH_OK)
			{
				printf("Hook Created: %p\n", target);
				return true;
			}
			else
				printf("Couldnt enable hook: %d\n", stat);
		}
		else
			printf("couldnt create hook %d\n", stat);

		return false;
	}
	inline bool getSwapChain(IDXGISwapChain** swapChain, ID3D11Device** device) {
		DXGI_SWAP_CHAIN_DESC desc;
		ZeroMemory(&desc, sizeof(desc));
		desc.BufferCount = 1;
		desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		desc.OutputWindow = GetForegroundWindow();
		desc.SampleDesc.Count = 1;
		desc.Windowed = TRUE;
		desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

		bool succ = false;

		HRESULT res = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_WARP, nullptr, 0, nullptr, 0, D3D11_SDK_VERSION,
			&desc, swapChain, device, nullptr, nullptr);

		if (!SUCCEEDED(res))
			return false;

		return true;
	}
	inline ID3DPresent getPresent() {
		IDXGISwapChain* swapChain;
		ID3D11Device* device;

		if (getSwapChain(&swapChain, &device)) {

			void** vTable = *(void***)swapChain;

			if (swapChain) { swapChain->Release(); swapChain = nullptr; }
			if (device) { device->Release(); device = nullptr; }

			return (ID3DPresent)vTable[8];
		}

		return NULL;
	}

	//Hook declarations
	HRESULT PresentHook(IDXGISwapChain* __this, UINT sync, UINT flags);
	static LRESULT WINAPI WndProc_Hook(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	void OnPlayerUpdate(Player_o* _this, MethodInfo* mInfo);
	void OnGhostUpdate(GhostAI_o* _this, MethodInfo* mInfo);
	void RPCFunc(Photon_Pun_PhotonView_o* _this, System_String_o* methodName, int32_t target, System_Object_array* parameters, const MethodInfo* method);
	void OnGhostControllerUpdate(GhostController_o* _this, const MethodInfo* method);
	void OnGhostEventPlayerUpdate(GhostEventPlayer_o* _this, const MethodInfo* method);
	void OnPlayMessageSequence(OuijaBoard_o* _this, System_String_o* message, const MethodInfo* method);

	void OnFPCUpdate(FirstPersonController_o* _this, MethodInfo* mInfo);
	void OnFixedUpdateFPC(FirstPersonController_o* _this, MethodInfo* mInfo);
	bool SetDestination(UnityEngine_AI_NavMeshAgent_o* _this, UnityEngine_Vector3_o* target, const MethodInfo* method);
	void SetDestination2(UnityEngine_AI_NavMeshAgent_o* _this, UnityEngine_Vector3_o* target, const MethodInfo* method);

	void GhostController_CreateGhost(GhostController_o* _this, const MethodInfo* method);

	void SetBoolHk(UnityEngine_Animator_o* _this, System_String_o* name, bool value, const MethodInfo* method);
	void SetIntHk(UnityEngine_Animator_o* _this, System_String_o* name, int value, const MethodInfo* method);

	System_Text_RegularExpressions_RegexCharClass_SingleRange_o GetSpawnCursedItemHk(System_Collections_Generic_List_RegexCharClass_SingleRange__o* _this, int32_t index, void* method);
	void SpawnCursedItemHk(CursedItemsController_o* _this, const MethodInfo* method);

	inline WNDPROC oWndProc{};
	inline ID3DPresent oPresent{};



	inline Player_Update oUpdatePlayer{};
	inline GhostAI_Update oUpdateGhost{};
	inline GhostController__Update oUpdateGhostController{};
	inline GhostEventPlayer__Update oUpdateGhostEventPlayer{};
	inline OuijaBoard______PlayMessageSequence___6472225264 oPlayMessageSequence{};


	inline FirstPersonController__Update oUpdateFPC{};
	inline FirstPersonController__FixedUpdate oFixedUpdateFPC{};

	inline UnityEngine_AI_NavMeshAgent__SetDestination _SetDestination{};
	inline UnityEngine_AI_NavMeshAgent__SetDestination2 _SetDestination2{};

	inline UnityEngine_Animator__SetIntegerString _SetInteger{};
	inline UnityEngine_Animator__SetBoolString _SetBool{};
	inline System_Collections_Generic_List_RegexCharClass_SingleRange___get_Item GetSpawnCursedItemHook{};
	inline CursedItemsController______testing____25110576 oSpawnCursedItem{};
}
