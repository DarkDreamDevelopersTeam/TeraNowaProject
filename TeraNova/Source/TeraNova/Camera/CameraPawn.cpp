// Fill out your copyright notice in the Description page of Project Settings.

#include "TeraNova.h"
#include "CameraPawn.h"


// Sets default values
ACameraPawn::ACameraPawn(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CamerColisionComponent = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("CamerColisionComponent"));
	StaticMeshComponent = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("StaticMeshComponent"));
	CameraComponent = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("CameraComponent"));
	SpirngArmComponent = ObjectInitializer.CreateDefaultSubobject<USpringArmComponent>(this, TEXT("SpringArmComponent"));

	RootComponent = StaticMeshComponent;
	SpirngArmComponent->AttachTo(StaticMeshComponent);
	CameraComponent->AttachTo(SpirngArmComponent);
	CamerColisionComponent->AttachTo(CameraComponent);
}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

