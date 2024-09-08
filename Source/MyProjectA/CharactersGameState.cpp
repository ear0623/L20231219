// Fill out your copyright notice in the Description page of Project Settings.


#include "CharactersGameState.h"
#include "Kismet/GameplayStatics.h"
#include "CharactersController.h"

ACharactersGameState::ACharactersGameState()
{

}


ACharactersController* ACharactersGameState::GetCharacterController()
{
	//APlayerController 
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
	{
		return PlayerController = Cast<ACharactersController>(PC);
	}
	
	return nullptr;
}
