// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Camera/CameraPawn.h"
#include "GameFramework/PlayerController.h"
#include "TeraNovaPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TERANOVA_API ATeraNovaPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ATeraNovaPlayerController(const FObjectInitializer& ObjectInitializer);

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	ACameraPawn* CameraPawn;

	bool bRightMouseButtonPressed = false;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
	// End PlayerController interface

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();

	void OnRMBPressed();
	void OnRMBReleased();

	void MouseXAxis(float value);
	void MouseYAxis(float value);

private:
	struct MousePosition{
		int x = 0;
		int y = 0;
	};

	FViewport* ViewPort;

	MousePosition MousePos;
	
};
