// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Ball.h"
#include "Components/Ball/BallHitComponent.h"
#include "Components/Ball/BallMeshComponent.h"
#include "Components/Ball/BallMovementComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABall::ABall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UBallMeshComponent>(TEXT("Ball Mesh Component"));

	if (RootComponent)
		StaticMeshComponent->SetupAttachment(RootComponent);

	ProjectileMovementComponent = CreateDefaultSubobject<UBallMovementComponent>(TEXT("Ball Movement Component"));

	ProjectileMovementComponent->SetUpdatedComponent(StaticMeshComponent);

	BallHitComponent = CreateDefaultSubobject<UBallHitComponent>(TEXT("Ball Hit Component"));
}

void ABall::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved,
                      FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	BallHitComponent->HandleOnHit(Other, Hit);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();

	const auto World = GetWorld();

	if(const auto PlayerController = World->GetFirstPlayerController())
	{
		const auto BallLocation = StaticMeshComponent->GetComponentLocation();

		if(const auto PlayerPawn = PlayerController->GetPawn())
		{
			const auto PlayerLocation = PlayerPawn->GetActorLocation();

			// TODO: ball should fire in direction of player. Works for now.
			const auto Direction = PlayerLocation - BallLocation;

			ProjectileMovementComponent->Velocity = Direction * ProjectileMovementComponent->InitialSpeed;
		}
	}
}
