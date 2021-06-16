// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddlePawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APaddlePawn::APaddlePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_PaddlePawn = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM PaddlePawn"));
	RootComponent = SM_PaddlePawn;

	SM_PaddlePawn -> SetEnableGravity(false);
	SM_PaddlePawn -> SetConstraintMode(EDOFMode::XZPlane);
	SM_PaddlePawn -> SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_PaddlePawn -> SetCollisionProfileName(TEXT("PhysicsActor"));

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));
}

// Called when the game starts or when spawned
void APaddlePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaddlePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APaddlePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APaddlePawn::MoveHorizontal(float AxisValue) 
{
	AddMovementInput(FVector(AxisValue, 0.0f, 0.0f), 1.0f, false);
}

