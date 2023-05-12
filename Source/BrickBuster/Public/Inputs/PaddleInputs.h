// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "InputAction.h"

#include "PaddleInputs.generated.h"

/**
 * 
 */
UCLASS()
class BRICKBUSTER_API UPaddleInputs : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	UInputAction* InputMove;
};
