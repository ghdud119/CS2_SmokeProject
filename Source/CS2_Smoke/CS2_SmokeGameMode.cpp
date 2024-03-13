// Copyright Epic Games, Inc. All Rights Reserved.

#include "CS2_SmokeGameMode.h"
#include "CS2_SmokeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACS2_SmokeGameMode::ACS2_SmokeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
