#include "pch.h"
#include "../hook.h"
using namespace smile;

void HOOK::OnFixedUpdateFPC(FirstPersonController_o* _this, MethodInfo* mInfo)
{
	if (vars->controllingGhost)
		return;

	return oFixedUpdateFPC(_this, mInfo);
}

void HOOK::OnFPCUpdate(FirstPersonController_o* _this, MethodInfo* mInfo)
{
	if (vars->controllingGhost && vars->ghostCam)
	{
		auto ghostFootPos = vars->currentGhost->GetPosition();
		auto forward = vars->currentGhost->GetForward();
		auto rotation = vars->currentGhost->GetTransform()->GetRotation();

		ghostFootPos.fields.y += 1.5f;
		UnityEngine_Vector3_o finalPos = ghostFootPos + (forward * 0.9f);

		vars->ghostCam->GetTransform()->SetPosition(&finalPos);
		vars->ghostCam->GetTransform()->SetRotation(rotation);


		MouseLookRotation(_this->fields.m_MouseLook, vars->currentGhost->GetTransform(), vars->ghostCam->GetTransform(), 0);
		return;
	}


	return oUpdateFPC(_this, mInfo);
}