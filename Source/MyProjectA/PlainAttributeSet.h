// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "PlainAttributeSet.generated.h"

// 加己 立辟磊
#define ATRIBUTE_ACCESSORS(ClassName,ProperTyName)\
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, ProperTyName)\
GAMEPLAYATTRIBUTE_VALUE_GETTER(ProperTyName)\
GAMEPLAYATTRIBUTE_VALUE_SETTER(ProperTyName)\
GAMEPLAYATTRIBUTE_VALUE_INITTER(ProperTyName)
//GAMEPLAYATTRIBUTE_PROPERTY_GETTER(UPlainAttributeSet, Mana);
//GAMEPLAYATTRIBUTE_VALUE_GETTER(Health);
//GAMEPLAYATTRIBUTE_VALUE_GETTER(Mana);
/**
 * 
 */
UCLASS()
class MYPROJECTA_API UPlainAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	

public:
	UPlainAttributeSet();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Health;
	ATRIBUTE_ACCESSORS(UPlainAttributeSet, Health);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayAttributeData Mana;
	ATRIBUTE_ACCESSORS(UPlainAttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Speed;
	ATRIBUTE_ACCESSORS(UPlainAttributeSet, Speed);


	// 加己 函版 贸府
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

};
