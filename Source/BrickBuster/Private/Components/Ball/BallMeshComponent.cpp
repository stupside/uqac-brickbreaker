// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Ball/BallMeshComponent.h"

UBallMeshComponent::UBallMeshComponent()
	: UStaticMeshComponent()
{
	UPrimitiveComponent::SetSimulatePhysics(false);
	
	UPrimitiveComponent::SetEnableGravity(false);
	
	/*
	UPrimitiveComponent::SetConstraintMode(EDOFMode::XZPlane);
	UStaticMeshComponent::SetCollisionProfileName(FName("PhysicsActor"));
	*/
}
