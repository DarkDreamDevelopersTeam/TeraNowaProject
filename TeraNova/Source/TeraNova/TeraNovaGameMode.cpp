// Fill out your copyright notice in the Description page of Project Settings.

#include "TeraNova.h"
#include "TeraNovaGameMode.h"


ATeraNovaGameMode::ATeraNovaGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDownBP/Blueprints/TerraNovaPlayerController"));

	if (PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}

