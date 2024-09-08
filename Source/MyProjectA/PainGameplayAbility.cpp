// Fill out your copyright notice in the Description page of Project Settings.


#include "PainGameplayAbility.h"

void UPainGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
    if (CommitAbility(Handle, ActorInfo, ActivationInfo))
    {
        // Ability logic here
        // For example, modify attributes, apply effects, etc.

        // End the ability
        EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
    }
}
