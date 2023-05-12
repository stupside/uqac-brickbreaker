// Fill out your copyright notice in the Description page of Project Settings.


#include "Inputs/InputsController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

#include "Inputs/PaddleInputs.h"
#include "Inputs/GameInputs.h"

void AInputsController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	const auto& EnhancedInput = Cast<UEnhancedInputComponent>(InputComponent.Get());

	ensureAlwaysMsgf(EnhancedInput, TEXT("Enhanced input components is null"));

	if(ensureAlwaysMsgf(PaddleInputs, TEXT("Paddle Input configuration is null")))
	{
		EnhancedInput->BindAction(PaddleInputs->InputMove, ETriggerEvent::Triggered, this, &AInputsController::OnMove);
	}

	if(ensureAlwaysMsgf(GameInputs, TEXT("Game Input configuration is null")))
	{
		EnhancedInput->BindAction(GameInputs->InputPause, ETriggerEvent::Triggered, this, &AInputsController::OnPause);
	}
	
	EnableInput(this);	
}

void AInputsController::OnPause(const FInputActionInstance& Instance)
{
	
}

void AInputsController::OnMove(const FInputActionInstance& Instance)
{
	const auto& InputActionValue = Instance.GetValue();

	const auto& InputDirection = InputActionValue.Get<float>();
	
	GetPawn()->AddMovementInput(FVector(1, 0, 0), InputDirection);
}

void AInputsController::BeginPlay()
{
	Super::BeginPlay();
	
	const auto& LocalPlayer = GetLocalPlayer();
	
	const auto& EnhancedInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	EnhancedInputSubsystem->AddMappingContext(InputMappingContext, 0);
}
