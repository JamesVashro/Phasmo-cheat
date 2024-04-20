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
	
	if (outStr == "Hunting")
	{

		printf("%p\n", parameters->obj.klass);
		
		smile::vars->object_TypeInfo = parameters->obj.klass;
	}
	return oRpc(_this, methodName, target, parameters, method);
}