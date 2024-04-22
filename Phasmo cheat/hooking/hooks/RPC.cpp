#include "pch.h"
#include "../hook.h"

#include <locale>
#include <codecvt>

std::vector<std::string> skippedRpcs
{
	"SpawnFootstepNetworked",
	"Use",
	"CompleteObjectiveRPC",
	"PlayOrStopAppearSourceSync",
	"TurnOnOrOffAppearSourceSync",
	"SyncWalk",
	"Display",
	"UpdatePlayerTier"
};

void HOOK::RPCFunc(Photon_Pun_PhotonView_o* _this, System_String_o* methodName, int32_t target, System_Object_array* parameters, const MethodInfo* method)
{
	std::wstring wStr = std::wstring(methodName->fields.buffer);

	std::string outStr(wStr.begin(), wStr.end());

	for (int i = 0; i < skippedRpcs.size(); i++)
	{
		if (outStr == skippedRpcs[i])
			return oRpc(_this, methodName, target, parameters, method);
	}

	if (smile::vars->rpcCalls.size() >= 23)
		smile::vars->rpcCalls.erase(smile::vars->rpcCalls.begin(), smile::vars->rpcCalls.begin() + 1);

	smile::vars->rpcCalls.push_back(outStr);
	
	/*if (outStr == "CreateGhost")
	{
		printf("intercepting\n");
		Il2CppClass* boolTypeInfo = FUNCS::GetClass("mscorlib", "System", "Boolean");
		Il2CppClass* intTypeInfo = FUNCS::GetClass("mscorlib", "System", "Int32");
		Il2CppClass* genericList = FUNCS::GetClass("mscorlib", "System.Collections", "ArrayList");

		System_Collections_ArrayList_o* genArray = (System_Collections_ArrayList_o*)il2cppObjectNew((__int64)genericList);
		genArray->Construct();

		genArray->AddItem<bool>(false, boolTypeInfo);
		genArray->AddItem<int>(3, intTypeInfo);
		genArray->AddItem<bool>(false, boolTypeInfo);

		return oRpc(_this, methodName, target, genArray->GetObjArray(), method);
	}*/
	return oRpc(_this, methodName, target, parameters, method);
}