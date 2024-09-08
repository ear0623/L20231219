// Fill out your copyright notice in the Description page of Project Settings.


#include "PlainGameplayEffect.h"
#include "PlainAttributeSet.h"

UPlainGameplayEffect::UPlainGameplayEffect()
{
    // Constructor logic for initializing the effect
    DurationPolicy = EGameplayEffectDurationType::Instant; // Example setting for an instant effect

    // Define any modifiers for this effect, e.g., change health
    FGameplayModifierInfo ModifierInfo;
    ModifierInfo.Attribute = UPlainAttributeSet::GetHealthAttribute(); // Assuming HealthAttribute is defined correctly
    ModifierInfo.ModifierOp = EGameplayModOp::Additive;
    ModifierInfo.ModifierMagnitude = FScalableFloat(10.0f); // Example magnitude
    Modifiers.Add(ModifierInfo);
}
