// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MultiplayerEduGameMode.generated.h"

UCLASS(minimalapi)
class AMultiplayerEduGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMultiplayerEduGameMode();

	UFUNCTION(BlueprintCallable, Category = "MultiplayerEduGameMode")
	void HostLanGame();

	UFUNCTION(BlueprintCallable, Category = "MultiplayerEduGameMode")
	void JoinLanGame();
};



