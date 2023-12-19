// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

class UInputMappingContext;
/**
 * 
 */
UCLASS()
class MYPROJECTA_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay()override;
	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category="Input")
	TObjectPtr< UInputMappingContext> InputContext;
};
