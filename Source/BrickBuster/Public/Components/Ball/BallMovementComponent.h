// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "BallMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class BRICKBUSTER_API UBallMovementComponent : public UProjectileMovementComponent
{
	GENERATED_BODY()

public:
	UBallMovementComponent();

protected:

	virtual FVector ComputeBounceResult(const FHitResult& Hit, float TimeSlice, const FVector& MoveDelta) override;
};
