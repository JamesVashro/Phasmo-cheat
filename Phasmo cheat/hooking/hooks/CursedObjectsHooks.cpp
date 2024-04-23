#include "pch.h"
#include "../hook.h"
#include <intrin.h>

#pragma intrinsic(_ReturnAddress)

using namespace smile;

//48 8B AF ? ? ? ? E8 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 48 8B 40 30 48 85 C0 0F 84 ? ? ? ? 48 8B 80 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? 3B 58 18 0F 83 ? ? ? ? 48 85 ED - 0x1A5
void HOOK::SpawnCursedItemHk(CursedItemsController_o* _this, const MethodInfo* method) //This is the func that creates cursed item
{
	//printf("creating cursed item\n");
	if (!vars->forceCursedItem)
		return oSpawnCursedItem(_this, method);

	switch (vars->forcedCursedItem)
	{
	case CursedItem::TAROT:
		tFunc(_this, 0);
		break;
	case CursedItem::OUIJA:
		oFunc(_this, 0);
		break;
	case CursedItem::MIRROR:
		mFunc(_this, 0);
		break;
	case CursedItem::MUSIC:
		mbFunc(_this, 0);
		break;
	case CursedItem::CIRCLE:
		cFunc(_this, 0);
		break;
	case CursedItem::VOODOO:
		vFunc(_this, 0);
		break;
	case CursedItem::PAW:
		pFunc(_this, 0);
		break;
	default:
		printf("oopsie");

		break;
	}
	
}

//This funcs purpose is to find the right func the game uses to actually spawn a cursed item, because there is like 10 of them, im assuming the devs did this to make it harder
//to make this kind of feature? or im schizo idk
System_Text_RegularExpressions_RegexCharClass_SingleRange_o HOOK::GetSpawnCursedItemHk(System_Collections_Generic_List_RegexCharClass_SingleRange__o* _this, int32_t index, void* method)
{
	static bool hasBeenHooked = false;

	if (vars->forceCursedItem)
	{
		if (!vars->cursedICClass)
			return GetSpawnCursedItemHook(_this, index, method);

		if (!vars->cursedICClass->static_fields)
			return GetSpawnCursedItemHook(_this, index, method);

		if (!vars->cursedICClass->static_fields->_________)
			return GetSpawnCursedItemHook(_this, index, method);

		if ((void*)_this == (void*)vars->cursedICClass->static_fields->_________->fields._15_listEnum) //if the list being querried is the cursed items spawn list, return the item we want to spawn
		{

			oSpawnCursedItem = (CursedItemsController______testing____25110576)((void*)((uintptr_t)_ReturnAddress() - 0x267));
			if (Hook((void*)oSpawnCursedItem, SpawnCursedItemHk, (void**)&oSpawnCursedItem))
			{
				hasBeenHooked = true;
			}
		}
	}
	return GetSpawnCursedItemHook(_this, index, method);
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