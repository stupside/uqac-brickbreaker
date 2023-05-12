// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Ball/BallHitComponent.h"

#include "NiagaraFunctionLibrary.h"

#include "Kismet/GameplayStatics.h"

void UBallHitComponent::HandleOnHit(const AActor* Actor, const FHitResult& HitResult) const
{
	for(const auto& Sound: SoundMap)
	{
		if(Actor->IsA(Sound.Key))
		{
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), Sound.Value, HitResult.Location);
		}
	}

	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), NiagaraEffect, HitResult.Location, HitResult.Normal.Rotation());
}
