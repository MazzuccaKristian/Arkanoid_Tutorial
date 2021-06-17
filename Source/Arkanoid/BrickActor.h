// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BrickActor.generated.h"

class UBoxComponent;

UCLASS()
class ARKANOID_API ABrickActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrickActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* SM_Brick;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent* BoxCollision;

	float SpeedModifierOnBounce = 1.0f;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComponente, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweep, const FHitResult& SweepResult);
	
	void DestoyBrick();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
