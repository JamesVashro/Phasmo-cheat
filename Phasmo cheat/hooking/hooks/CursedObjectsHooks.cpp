#include "pch.h"
#include "../hook.h"
#include <intrin.h>

#pragma intrinsic(_ReturnAddress)

using namespace smile;

//48 8B AF ? ? ? ? E8 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 48 8B 40 30 48 85 C0 0F 84 ? ? ? ? 48 8B 80 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 3B 58 18 0F 83 ? ? ? ? 48 85 ED - 0x1A5
void HOOK::testHk(CursedItemsController_o* _this, const MethodInfo* method) //This is the func that creates cursed item
{
	printf("creating cursed item\n");
	using tarotFunc = void(__stdcall*)(CursedItemsController_o* _this, const MethodInfo* method);
	tarotFunc tFunc = (tarotFunc)signature("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 40 48 8B 79 68 48 8B D9 48 85 FF 0F 84 ? ? ? ? 8B 57 18 45 33 C0 33 C9 E8 ? ? ? ? 3B 47 18 0F 83 ? ? ? ? 48 8B 4B 30 48 98 48 8B 7C C7 ? 48 85 C9 0F 84 ? ? ? ?").GetPointer(4);

	tFunc(_this, 0);
	return;
	return test(_this, method);
}

//This funcs purpose is to find the right func the game uses to actually spawn a cursed item, because there is like 10 of them, im assuming the devs did this to make it harder
//to make this kind of feature? or im schizo idk
System_Text_RegularExpressions_RegexCharClass_SingleRange_o HOOK::SpawnCursedItemHk(System_Collections_Generic_List_RegexCharClass_SingleRange__o* _this, int32_t index, void* method)
{
	static bool hasBeenHooked = false;

	if (vars->forceCursedItem)
	{
		if (!vars->cursedICClass)
			return SpawnCursedItemHook(_this, index, method);

		if (!vars->cursedICClass->static_fields)
			return SpawnCursedItemHook(_this, index, method);

		if (!vars->cursedICClass->static_fields->_________)
			return SpawnCursedItemHook(_this, index, method);

		if ((void*)_this == (void*)vars->cursedICClass->static_fields->_________->fields._15_listEnum) //if the list being querried is the cursed items spawn list, return the item we want to spawn
		{

			test = (CursedItemsController______testing____25110576)((void*)((uintptr_t)_ReturnAddress() - 0x267));
			if (Hook((void*)test, testHk, (void**)&test))
			{
				hasBeenHooked = true;
			}
		}
	}
	return SpawnCursedItemHook(_this, index, method);
}

void HOOK::OnPlayMessageSequence(OuijaBoard_o* _this, System_String_o* message, const MethodInfo* method)
{
	if (smile::vars->bInterceptOuijaMessage)
	{
		System_String_o* newstr = SystemStringCtor(smile::vars->interceptOuijaMessage.c_str(), 0, strlen(smile::vars->interceptOuijaMessage.c_str()), 0);
		return oPlayMessageSequence(_this, newstr, method);
	}


	return oPlayMessageSequence(_this, message, method);
}