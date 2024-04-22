#include "pch.h"
#include "../hook.h"


void HOOK::OnPlayMessageSequence(OuijaBoard_o* _this, System_String_o* message, const MethodInfo* method)
{
	if (smile::vars->bInterceptOuijaMessage)
	{
		System_String_o* newstr = SystemStringCtor(smile::vars->interceptOuijaMessage.c_str(), 0, strlen(smile::vars->interceptOuijaMessage.c_str()), 0);
		return oPlayMessageSequence(_this, newstr, method);
	}


	return oPlayMessageSequence(_this, message, method);
}