#include "pch.h"
#include "../hook.h"
using namespace smile;

void HOOK::GhostController_CreateGhost(GhostController_o* _this, const MethodInfo* method)
{
	printf("Creating ghost!\n");
	return oCreateGhost(_this, method);
}