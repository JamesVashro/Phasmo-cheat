#include "pch.h"
#include "../hook.h"


void HOOK::OnPlayMessageSequence(OuijaBoard_o* _this, System_String_o* _, Photon_Pun_PhotonMessageInfo_o* a3, const MethodInfo* method)
{
	if (smile::vars->bInterceptOuijaMessage)
	{
		wprintf(L"intercepting message: %ls\n", _->fields.buffer);
		System_String_o* newstr = SystemStringCtor(smile::vars->interceptOuijaMessage.c_str(), 0, strlen(smile::vars->interceptOuijaMessage.c_str()), 0);
		return oPlayMessageSequence(_this, newstr, a3, method);
	}


	return oPlayMessageSequence(_this, _, a3, method);
}