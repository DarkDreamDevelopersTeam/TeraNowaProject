// Fill out your copyright notice in the Description page of Project Settings.

#include "TeraNova.h"
#include "CharacterV1.h"


// Sets default values
ACharacterV1::ACharacterV1()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterV1::BeginPlay()
{
	Super::BeginPlay();

} 

// Called every frame
void ACharacterV1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterV1::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

