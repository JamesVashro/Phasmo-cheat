#include "pch.h"
#include "../hook.h"

#include <locale>
#include <codecvt>

void HOOK::RPCFunc(Photon_Pun_PhotonView_o* _this, System_String_o* methodName, int32_t target, System_Object_array* parameters, const MethodInfo* method)
{
	std::wstring wStr = std::wstring(methodName->fields.buffer);

	std::string outStr(wStr.begin(), wStr.end());
	if (smile::vars->rpcCalls.size() >= 23)
		smile::vars->rpcCalls.erase(smile::vars->rpcCalls.begin(), smile::vars->rpcCalls.begin() + 1);

	smile::vars->rpcCalls.push_back(outStr);
	
	return oRpc(_this, methodName, target, parameters, method);
}