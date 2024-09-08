// Fill out your copyright notice in the Description page of Project Settings.


#include "PlainAttributeSet.h"
#include "GameplayEffectExtension.h"


UPlainAttributeSet::UPlainAttributeSet()
    : Health(100.0f), Mana(100.0f)
{

}

void UPlainAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    // 속성 변경 처리 (예: 체력을 최대 값으로 고정)
    Super::PostGameplayEffectExecute(Data);

    if ( Data.EvaluatedData.Attribute == GetHealthAttribute())
    {
        Health.SetCurrentValue(FMath::Clamp(Health.GetCurrentValue(), 0.0f, Health.GetBaseValue()));
    }
}
