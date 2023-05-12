// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Pawn.h"

#include "Paddle.generated.h"

class UNiagaraSystem;
class UFloatingPawnMovement;

UCLASS()
class BRICKBUSTER_API APaddle : public APawn
{
	
	GENERATED_BODY()

public:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Paddle")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Paddle")
	UFloatingPawnMovement* FloatingPawnMovement;
	
	APaddle();

protected:
	virtual void BeginPlay() override;

public:

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	float GetAngleRefractionFactorRelative(const FVector& Location) const;

	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved,
		FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
};
