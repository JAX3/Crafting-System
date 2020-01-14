// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Inventory_craftGameMode.h"
#include "Inventory_craftCharacter.h"
#include "UObject/ConstructorHelpers.h"

AInventory_craftGameMode::AInventory_craftGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
