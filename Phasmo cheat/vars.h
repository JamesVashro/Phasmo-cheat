#pragma once
#include "SDK/il2cpp.h"
#include <vector>


//TODO: 
// Fix fast footsteps to work better
// Spawn foostep audio behind player far away that speeds up as it gets closer
// make ghost yoink player and move somewhere? 
// control ghost?


namespace smile
{
	class Vars {
	public:
		Vars();
		~Vars();

		System_Boolean_c* bool_TypeInfo{};
		System_Int32_c* int_TypeInfo{};
		Il2CppClass* object_TypeInfo{};
		GameController_o* gameController = nullptr;

		GhostAI_o* currentGhost = nullptr;
		Player_o* localPlayer = nullptr;
		GhostController_o* ghostController = nullptr;
		GhostEventPlayer_o* ghostEventPlayer = nullptr;
		Network_o* network = nullptr;

		UnityEngine_Camera_o* ghostCam;
		UnityEngine_Camera_o* cachedCam;
		UnityEngine_GameObject_o* ghostLight;

		Player_o* spookPlayer = nullptr;
		UnityEngine_Vector3_o spookPos{};
		UnityEngine_Vector3_o spookRayStartPos{};
		std::string interceptOuijaMessage;
		bool bInterceptOuijaMessage = false;

		int ghostState = -1;

		bool ghostInfoOverlay = true;
		bool showRPCs = true;
		bool menuOpened = false;

		bool showGhost = false;
		bool unAppearGhost = false;

		float ghostSpeed = 1.7f;
		bool randomSpook = true;
		bool spookingPlayer = false;
		int spookSoundEffect = 0;
		int spookFrequency = 10;

		bool controllingGhost = false;
		int controlGhostWalkType = 0;
		UnityEngine_Vector3_o ghostPOS{};
		UnityEngine_Quaternion_o ghostQUAT{};

		int32_t lastLockedState = -1;

		bool waitinForEject = false;

		bool useCustom = false;
		float x = 0.f;
		float y = 0.f;
		float z = 0.f;

		float x1 = 0.f;
		float y1 = 0.f;
		float z1 = 0.f;
		float w = 0.f;

		std::vector<std::string> rpcCalls{};
	};
	inline Vars* vars{};
}