// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiplayerEduGameMode.h"
#include "MultiplayerEduCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMultiplayerEduGameMode::AMultiplayerEduGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AMultiplayerEduGameMode::HostLanGame()
{
	GetWorld()->ServerTravel("/Game/ThirdPerson/Maps/ThirdPersonMap?listen"); 
}

void AMultiplayerEduGameMode::JoinLanGame()
{
	APlayerController* PC = GetGameInstance()->GetFirstLocalPlayerController();
	if (PC)
	{
		PC->ClientTravel("192.168.1.68",ETravelType::TRAVEL_Absolute);
	}
}
