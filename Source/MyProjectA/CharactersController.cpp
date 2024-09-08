// Fill out your copyright notice in the Description page of Project Settings.


#include "CharactersController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

ACharactersController::ACharactersController()
    :InputMappingContext(nullptr), Subsystem(nullptr)
{
   
}

void ACharactersController::BeginPlay()
{
	Super::BeginPlay();

    if (ConstructerHelperGetLocalSubSystem() == true)
    {
        // Add the Input Mapping Context
        if (InputMappingContext)
        {
            Subsystem->AddMappingContext(InputMappingContext, 0);
        }
    }
}

void ACharactersController::ChangeMappingContext(UInputMappingContext* MappingContext)
{
    if (ConstructerHelperGetLocalSubSystem()==true)
    {
        // Add the Input Mapping Context
        if (MappingContext)
        {
            Subsystem->AddMappingContext(MappingContext, 0);
        }
    }
}

bool ACharactersController::ConstructerHelperGetLocalSubSystem()
{
    if (Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        return true;
    }
    else
    {
        return false;
    }
}
