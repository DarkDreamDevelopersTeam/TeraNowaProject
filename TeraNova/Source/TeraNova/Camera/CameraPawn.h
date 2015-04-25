// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "CameraPawn.generated.h"

UCLASS()
class TERANOVA_API ACameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACameraPawn(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Camera)
		USphereComponent* CamerColisionComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Camera)
		UCameraComponent* CameraComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Camera)
		USpringArmComponent* SpirngArmComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Camera)
		UStaticMeshComponent* StaticMeshComponent;

	UFUNCTION(BlueprintImplementableEvent, Category = MouseEvent)
		void RightMouseButtonPressed();

	UFUNCTION(BlueprintImplementableEvent, Category = MouseEvent)
		void RightMouseButtonReleased();

	UFUNCTION(BlueprintImplementableEvent, Category = MouseEvent)
		void MouseXAxis(float value);

	UFUNCTION(BlueprintImplementableEvent, Category = MouseEvent)
		void MouseYAxis(float value);

};