// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnimInstance.h"
#include "ThirdPersonCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (TryGetPawnOwner())
	{
		Player = Cast<AThirdPersonCharacter>(TryGetPawnOwner());
		
		PlayerMovementComponent = Player ? Player->GetCharacterMovement() : nullptr;
		
	}
}

void UPlayerAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	APawn* CurrentPawn = TryGetPawnOwner();
	if(CurrentPawn != Player || !IsValid(PlayerMovementComponent))
	{
		Player = Cast<AThirdPersonCharacter>(CurrentPawn);
		
		PlayerMovementComponent = Player ? Player->GetCharacterMovement() : nullptr;
	}

	if (!Player || !PlayerMovementComponent)
	{
		return;
	}

	const FVector Velocity = Player->GetVelocity();
	Speed = Velocity.Size2D();
	
	bIsInAir = PlayerMovementComponent ? PlayerMovementComponent->IsFalling() : false;
	
	bIsAccelerating = PlayerMovementComponent->GetCurrentAcceleration().SizeSquared() > KINDA_SMALL_NUMBER;

	bIsMoving = Speed > 0.0f;

	bIsJumping = Player->bPressedJump;

	bIsAttacking = Player->bIsAttacking;
}