// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ArenaCharacter.generated.h"

class APickableItemBase;

class APickableWeapon;

class UBoxComponent;

UCLASS()
class GLADIATOR_API AArenaCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AArenaCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		bool bIsAttacking = false;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		bool bIsAlive = true;

	bool PickShield(APickableItemBase* pickedShield);

	bool PickWeapon(APickableWeapon* pickedWeapon);

	APickableItemBase* Shield;
	APickableWeapon* Weapon;

	UBoxComponent* WeaponCollider;

	virtual void Attack();

	UFUNCTION()
		virtual void OnWeaponBeginOverlap(UPrimitiveComponent* OverlapComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bSweepFrom,
			const FHitResult& SweepResult);

	bool bDisableAttack;
	bool bCanDetectColliison;


	UPROPERTY(BlueprintReadOnly)
		float Health = 100.f;

	virtual bool ApplyDamage();


};
