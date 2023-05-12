// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Brick.h"

#include "States/MainGameState.h"
#include "States/MainPlayerState.h"

void ABrick::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved,
	FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	
	if (CurrentResistance <= 0) return;

	for (const auto CanBeDamagedByObject : CanBeDamagedByObjects)
	{
		if (Other->IsA(CanBeDamagedByObject))
		{
			CurrentResistance--;

			const auto World = GetWorld();

			const auto GameState = Cast<AMainGameState>(World->GetGameState());

			if (const auto Possession = GameState->Possession)
			{
				const auto PlayerState = Cast<AMainPlayerState>(Possession->GetPlayerState());

				PlayerState->SetScore(PlayerState->GetScore() + 1);
			}

			if (CurrentResistance <= 0)
				Destroy();

			break;
		}
	}
}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();

	CurrentResistance = DefaultResistance;
}
