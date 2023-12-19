// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPawn.h"
#include "MyPlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{
	UE_LOG(LogTemp, Warning, TEXT("게임모드"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Green, TEXT("OnGameMode"));
	}

	DefaultPawnClass = AMyPawn::StaticClass();//classname apawn name 문법적으로는 자식
	PlayerControllerClass = AMyPlayerController::StaticClass();
	
}
