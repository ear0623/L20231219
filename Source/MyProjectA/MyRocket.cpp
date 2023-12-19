// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRocket.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMyRocket::AMyRocket()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Rocket = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rocket"));
	RootComponent = Rocket;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MS_Rocket(TEXT("/Script/Engine.StaticMesh'/Game/FBX/Missile/SM_Rocket.SM_Rocket'"));
	if (MS_Rocket.Succeeded())
	{
		Rocket->SetStaticMesh(MS_Rocket.Object);
	}

}

// Called when the game starts or when spawned
void AMyRocket::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyRocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

