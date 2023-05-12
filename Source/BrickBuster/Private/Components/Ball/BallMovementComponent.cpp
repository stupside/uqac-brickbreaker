// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Ball/BallMovementComponent.h"

#include "Actors/Character/Paddle.h"

UBallMovementComponent::UBallMovementComponent()
	: UProjectileMovementComponent()
{
	Bounciness = 1;
	bShouldBounce = true;

	Friction = 0;

	ProjectileGravityScale = 0;

	MaxSpeed = InitialSpeed;

	bSweepCollision = true;

	bRotationFollowsVelocity = true;

	bConstrainToPlane = true;

	Velocity = FVector::ZeroVector;

	PlaneConstraintNormal = FVector(0, 0, 1);
}

FVector UBallMovementComponent::ComputeBounceResult(const FHitResult& Hit, float TimeSlice, const FVector& MoveDelta)
{
	auto Direction = Super::ComputeBounceResult(Hit, TimeSlice, MoveDelta);

	const auto& HitActor = Hit.GetActor();

	if (const auto& Paddle = Cast<APaddle>(HitActor))
	{
		const auto Factor = Paddle->GetAngleRefractionFactorRelative(Hit.Location);
		
		Direction = Direction.RotateAngleAxis(Factor * 90, FVector(0, 0, 1));
	}

	if(!Direction.Y)
		Direction.Y = FMath::RandRange(1, 100);

	return Direction;
}
