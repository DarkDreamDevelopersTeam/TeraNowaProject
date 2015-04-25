// Fill out your copyright notice in the Description page of Project Settings.

#include "TeraNova.h"
#include "Camera/CameraPawn.h"
#include "Characters/CharacterV1.h"
#include "TeraNovaPlayerController.h"

ATeraNovaPlayerController::ATeraNovaPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bShowMouseCursor = true;
	bBlockInput = false;
	//bEnableMouseOverEvents = false;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ATeraNovaPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}
}

void ATeraNovaPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ATeraNovaPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &ATeraNovaPlayerController::OnSetDestinationReleased);

	InputComponent->BindAction("RightMouseButton", IE_Pressed, this, &ATeraNovaPlayerController::OnRMBPressed);
	InputComponent->BindAction("RightMouseButton", IE_Released, this, &ATeraNovaPlayerController::OnRMBReleased);

	InputComponent->BindAxis("MouseXAxis", this, &ATeraNovaPlayerController::MouseXAxis);
	InputComponent->BindAxis("MouseYAxis", this, &ATeraNovaPlayerController::MouseYAxis);
}

void ATeraNovaPlayerController::MoveToMouseCursor()
{
	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(Hit.ImpactPoint);
	}
}

void ATeraNovaPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void ATeraNovaPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	TArray<AActor*> FoundPawns;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACharacterV1::StaticClass(), FoundPawns);

	for (auto Actor : FoundPawns){
		APawn* Pawn = Cast<APawn>(Actor);

		if (Pawn)
		{
			UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
			float const Distance = FVector::Dist(DestLocation, Pawn->GetActorLocation());

			// We need to issue move command only if far enough in order for walk animation to play correctly
			if (NavSys && (Distance > 120.0f))
			{
				NavSys->SimpleMoveToLocation(Pawn->GetController(), DestLocation);
			}
		}
	}
}

void ATeraNovaPlayerController::BeginPlay(){
	Super::BeginPlay();
	TArray<AActor*> FoundActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraPawn::StaticClass(), FoundActors);
	if (FoundActors.Num() != 0){
		CameraPawn = Cast<ACameraPawn>(FoundActors[0]);
	}
	ViewPort = CastChecked<ULocalPlayer>(this->Player)->ViewportClient->Viewport;
}

void ATeraNovaPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void ATeraNovaPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}


void ATeraNovaPlayerController::OnRMBPressed()
{
	if (CameraPawn){
		CameraPawn->RightMouseButtonPressed();
	}
	if (ViewPort){
		MousePos.x = ViewPort->GetMouseX();
		MousePos.y = ViewPort->GetMouseY();
	}
	bRightMouseButtonPressed = true;
}

void ATeraNovaPlayerController::OnRMBReleased()
{
	if (CameraPawn){
		CameraPawn->RightMouseButtonReleased();
	}
	bRightMouseButtonPressed = false;
}

void ATeraNovaPlayerController::MouseXAxis(float value)
{
	if (bRightMouseButtonPressed){
		if (ViewPort){
			ViewPort->SetMouse(MousePos.x, MousePos.y);
		}
		if (CameraPawn){
			CameraPawn->MouseXAxis(value);
		}
	}
}

void ATeraNovaPlayerController::MouseYAxis(float value)
{
	if (bRightMouseButtonPressed){
		if (ViewPort){
			ViewPort->SetMouse(MousePos.x, MousePos.y);
		}
		if (CameraPawn){
			CameraPawn->MouseYAxis(-value);
		}
	}
}


