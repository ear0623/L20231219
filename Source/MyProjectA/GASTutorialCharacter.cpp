// Fill out your copyright notice in the Description page of Project Settings.


#include "GASTutorialCharacter.h"
#include "AbilitySystemComponent.h"
#include "PlainAttributeSet.h"

// Sets default values
AGASTutorialCharacter::AGASTutorialCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize the Ability System Component
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<UPlainAttributeSet>(TEXT("AttributeSet"));

}

// Called when the game starts or when spawned
void AGASTutorialCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (AbilitySystemComponent)
	{
		AttributeSet = AbilitySystemComponent->GetSet<UPlainAttributeSet>();
		// Initialize abilities and effects here if needed
		//AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}

	/*UAbilitySystemComponent* APlaneCharacter::GetAbilitySystemComponent() const {
		return AbilitySystemComponent;
	}*/
}

// Called every frame
void AGASTutorialCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGASTutorialCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* AGASTutorialCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}

