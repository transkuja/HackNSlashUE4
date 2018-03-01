// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "HackNSlashGameMode.h"
#include "HackNSlashPlayerController.h"
#include "HackNSlashCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/HUD.h"

AHackNSlashGameMode::AHackNSlashGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AHackNSlashPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FObjectFinder<UClass> HUDBPClass(TEXT("/Game/Blueprints/HUD_BP"));
	HUDClass = (UClass*)HUDBPClass.Object;
}