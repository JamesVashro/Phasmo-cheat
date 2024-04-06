#include "pch.h"
#include "../hook.h"


void HOOK::OnGhostEventPlayerUpdate(GhostEventPlayer_o* _this, const MethodInfo* method)
{
	smile::vars->ghostEventPlayer = _this;

	return oUpdateGhostEventPlayer(_this, method);
}