// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRocket.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AMyRocket::AMyRocket()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Box= CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;
	Rocket = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rocket"));
	Rocket->SetupAttachment(Box);

	Box->AddLocalRotation(FRotator(0.0f, 90.0f, 0.0f));

	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	Movement->ProjectileGravityScale = 0;
	Movement->InitialSpeed = 2000.0f;

}

// Called when the game starts or when spawned
void AMyRocket::BeginPlay()
{
	Super::BeginPlay();

	SetLifeSpan(3.0f);
	OnActorBeginOverlap.AddDynamic(this, &AMyRocket::ProcessActorBeginOverlap);
	OnActorBeginOverlap.RemoveAll(this);

}

// Called every frame
void AMyRocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyRocket::ProcessActorBeginOverlap(AActor* OverlappedActor, AActor* otherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("other %s"),*otherActor->GetName());
	CPPToCallBp(10);
}

void AMyRocket::ExistCPPToCallBp_Implementation(int64 Damage)
{
	UE_LOG(LogTemp, Warning, TEXT("Blueprint"), Damage);
}

