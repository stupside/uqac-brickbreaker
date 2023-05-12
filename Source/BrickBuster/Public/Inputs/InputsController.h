// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "InputMappingContext.h"
#include "GameFramework/PlayerController.h"

#include "InputsController.generated.h"

class UGameInputs;
class UPaddleInputs;

struct FInputActionInstance;
class UEnhancedInputComponent;

/**
 * 
 */
UCLASS()
class BRICKBUSTER_API AInputsController : public APlayerController
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	UGameInputs* GameInputs;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	UPaddleInputs* PaddleInputs;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enhanced Input")
	UInputMappingContext* InputMappingContext;

protected:
	virtual void SetupInputComponent() override;

	void OnPause(const FInputActionInstance& Instance);
	void OnMove(const FInputActionInstance& Instance);

	virtual void BeginPlay() override;
};
