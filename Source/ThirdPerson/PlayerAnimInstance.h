// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

class AThirdPersonCharacter;
class UCharacterMovementComponent;
/**
 * 
 */
UCLASS()
class THIRDPERSON_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
	virtual void NativeInitializeAnimation() override;

	UFUNCTION(BlueprintCallable, Category = "AnimationProperties")
	void UpdateAnimationProperties(float DeltaTime);

private:
	UPROPERTY(Transient, VisibleAnywhere, BlueprintReadOnly, Category = "AnimationProperties", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AThirdPersonCharacter> Player = nullptr;

	UPROPERTY(Transient)
	TObjectPtr<UCharacterMovementComponent> PlayerMovementComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimationProperties", meta = (AllowPrivateAccess = "true"))
	bool bIsInAir = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimationProperties", meta = (AllowPrivateAccess = "true"))
	bool bIsAccelerating = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimationProperties", meta = (AllowPrivateAccess = "true"))
	bool bIsMoving = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimationProperties", meta = (AllowPrivateAccess = "true"))
	float Speed = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimationProperties", meta = (AllowPrivateAccess = "true"))
	bool bIsJumping = false;
};
