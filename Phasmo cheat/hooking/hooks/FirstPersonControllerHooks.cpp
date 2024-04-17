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
		GetInput(_this, 0i64);
		if (_this->fields.canTurn)
		{
			MouseLookRotation(_this->fields.m_MouseLook, vars->currentGhost->GetTransform(), vars->ghostCam->GetTransform(), 0i64);
		}

		UnityEngine_Bounds_o gBounds{};

		if (vars->currentGhost->fields._8_model->fields.myRends->max_length == 1)
			gBounds = vars->currentGhost->fields._8_model->fields.myRends->m_Items[0]->GetBounds();
		else
			gBounds = vars->currentGhost->fields._8_model->fields.myRends->m_Items[1]->GetBounds();


		UnityEngine_Vector3_o center = gBounds.fields.m_Center;
		center.fields.y += gBounds.fields.m_Extents.fields.y;

		UnityEngine_Vector3_o gPos = center;
		UnityEngine_Vector3_o gForward = vars->currentGhost->GetForward();

		UnityEngine_Vector3_o finalPos = gPos + (gForward * -1);
		UnityEngine_Quaternion_o gQuat = vars->currentGhost->GetTransform()->GetRotation();

		vars->ghostCam->GetTransform()->SetPosition(finalPos);
		vars->ghostCam->GetTransform()->SetRotation(gQuat);

		return;
	}
	return oUpdateFPC(_this, mInfo);
}