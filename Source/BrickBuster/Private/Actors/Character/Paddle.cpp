// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Character/Paddle.h"

#include "Actors/Ball.h"
#include "Components/Paddle/PaddleMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "States/MainGameState.h"

// Sets default values
APaddle::APaddle()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Paddle Floating Pawn Movement"));

	StaticMeshComponent = CreateDefaultSubobject<UPaddleMeshComponent>(TEXT("Paddle Mesh Component"));

	if (RootComponent)
		StaticMeshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

float APaddle::GetAngleRefractionFactorRelative(const FVector& Location) const
{
	const auto PaddleHitLocation = GetTransform().InverseTransformPosition(Location);

	const auto PaddleWidth = StaticMeshComponent->Bounds.BoxExtent.X;

	const auto Factor = PaddleHitLocation.X / (PaddleWidth / 2);

	return -Factor;
}

void APaddle::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved,
	FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	if (Other->IsA(ABall::StaticClass()))
	{
		const auto World = GetWorld();

		const auto GameState = Cast<AMainGameState>(World->GetGameState());

		GameState->Possession = this;
	}
}
