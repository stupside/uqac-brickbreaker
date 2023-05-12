// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Paddle/PaddleMeshComponent.h"

UPaddleMeshComponent::UPaddleMeshComponent()
	: UStaticMeshComponent()
{
	UPrimitiveComponent::SetSimulatePhysics(true);

	UPrimitiveComponent::SetEnableGravity(false);
	
	UStaticMeshComponent::SetCollisionProfileName(FName("PhysicsActor"));

	// UPrimitiveComponent::SetConstraintMode(EDOFMode::XYPlane);
}
