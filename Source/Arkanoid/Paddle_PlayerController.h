// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Paddle_PlayerController.generated.h"

// class ABall;

UCLASS()
class ARKANOID_API APaddle_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
	APaddle_PlayerController();

	UFUNCTION()
	virtual void SetupInputComponent() override;

protected:
	virtual void BeginPlay() override;
	void MoveHorizontal(float AxisValue);
};
