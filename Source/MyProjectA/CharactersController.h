// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CharactersController.generated.h"

class UInputMappingContext;
class UEnhancedInputLocalPlayerSubsystem;
/**
 * 
 */
UCLASS()
class MYPROJECTA_API ACharactersController : public APlayerController
{
	GENERATED_BODY()
	
	ACharactersController();

protected:
	 virtual void BeginPlay() override;

	 UFUNCTION(BlueprintCallable)
	 void ChangeMappingContext(UInputMappingContext* MappingContext);

	 bool ConstructerHelperGetLocalSubSystem();

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> InputMappingContext;

	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> Subsystem;
};
