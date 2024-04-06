#include "vars.h"

namespace smile
{
	Vars::Vars() {
		vars = this;
	}

	Vars::~Vars() {
		currentGhost = nullptr;
		localPlayer = nullptr;
	}
}
