// Fill out your copyright notice in the Description page of Project Settings.


#include "BrickActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "BallActor.h"

// Sets default values
ABrickActor::ABrickActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	SM_Brick -> SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision -> SetBoxExtent(FVector(25.0f, 10.0f, 10.0f));

	RootComponent = BoxCollision;
}

// Called when the game starts or when spawned
void ABrickActor::BeginPlay()
{
	Super::BeginPlay();
	
	BoxCollision -> OnComponentBeginOverlap.AddDynamic(this, &ABrickActor::OnOverlapBegin);
}

// Called every frame
void ABrickActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABrickActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweep, const FHitResult& SweepResult) 
{
	if(OtherActor -> ActorHasTag("Ball")){
		ABallActor* MyBall = Cast<ABallActor>(OtherActor);

		FVector BallVelocity = MyBall -> GetVelocity();
		BallVelocity *= (SpeedModifierOnBounce - 1.0f);
		MyBall -> GetBall() -> SetPhysicsLinearVelocity(BallVelocity, true);

		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABrickActor::DestoyBrick, 0.001f, false);
	}
}

void ABrickActor::DestoyBrick() 
{
	this -> Destroy();
}