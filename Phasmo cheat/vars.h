#pragma once
#include "SDK/il2cpp.h"
#include <vector>

namespace smile
{
	class Vars {
	public:
		Vars();
		~Vars();

		System_Boolean_c* bool_TypeInfo{};
		System_Int32_c* int_TypeInfo{};
		Il2CppClass* object_TypeInfo{};

		GhostAI_o* currentGhost = nullptr;
		Player_o* localPlayer = nullptr;
		GhostController_o* ghostController = nullptr;
		GhostEventPlayer_o* ghostEventPlayer = nullptr;


		int ghostState = -1;

		bool ghostInfoOverlay = true;
		bool menuOpened = false;
		bool showGhost = false;

		int32_t lastLockedState = -1;

		bool waitinForEject = false;

		std::vector<std::string> rpcCalls{};
	};
	inline Vars* vars{};
}