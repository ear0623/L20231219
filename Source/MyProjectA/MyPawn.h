// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "MyPawn.generated.h"

class UStaticMeshCompoenet;
class UInputAction;


UCLASS()
class MYPROJECTA_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	//
	UPROPERTY(BlueprintReadOnly,VisibleAnywhere,Category="Component")
	TObjectPtr<UStaticMeshComponent> Body;
	UPROPERTY(BlueprintReadOnly,VisibleAnywhere,Category = "Conponent")
	TObjectPtr<UStaticMeshComponent> Propeller_R;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Conponent")
	TObjectPtr<UStaticMeshComponent> Propeller_L;
	UPROPERTY(BlueprintReadOnly,VisibleAnywhere,Category="Component")
	TObjectPtr<class USpringArmComponent> SpringArm;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Component")
	TObjectPtr<class UCameraComponent> Camera;
	UPROPERTY(BlueprintReadOnly,VisibleAnywhere,Category="Component")
	TObjectPtr<class UBoxComponent> Box;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Component")
	TObjectPtr<class UArrowComponent>Arrow;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Component")
	TObjectPtr<class UFloatingPawnMovement> FloatingPawnMovement;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Data")
	TObjectPtr<UInputAction> FireAction;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Data")
	TObjectPtr<UInputAction> PitchAndRollAction;

	TObjectPtr<class URotateComponent> Rotate;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Data")
	TSubclassOf<AMyRocket> RocketTemplate;
	
	//
	void Fire(const FInputActionValue& Value);
	void PitchAndRoll(const FInputActionValue& Value);
	void Pitch(float Value);
	void Roll(float Value);

	
};
