// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Block.h"

#include "Brick.generated.h"

UCLASS()
class BRICKBUSTER_API ABrick : public ABlock
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Actor")
	int DefaultResistance = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Actor")
	int CurrentResistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Actor")
	TArray<TSubclassOf<UObject>> CanBeDamagedByObjects;

	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved,
	                       FVector HitLocation, FVector HitNormal, FVector NormalImpulse,
	                       const FHitResult& Hit) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
