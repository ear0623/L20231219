// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "CharactersGameState.generated.h"

class ACharactersController;

/**
 * 
 */
UCLASS()
class MYPROJECTA_API ACharactersGameState : public AGameState
{
	GENERATED_BODY()
	
	ACharactersGameState();

protected:

	UFUNCTION(BlueprintCallable)
	ACharactersController* GetCharacterController();

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Hellper", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<ACharactersController> PlayerController;
};
