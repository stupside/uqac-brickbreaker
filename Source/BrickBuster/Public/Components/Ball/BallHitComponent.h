// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "BallHitComponent.generated.h"

struct FHitResult;
class UNiagaraSystem;

/**
 * 
 */
UCLASS()
class BRICKBUSTER_API UBallHitComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physics")
	TMap<TSubclassOf<AActor>, USoundBase*> SoundMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Physics")
	UNiagaraSystem* NiagaraEffect; 

	void HandleOnHit(const AActor* Actor, const FHitResult& HitResult) const;
};
