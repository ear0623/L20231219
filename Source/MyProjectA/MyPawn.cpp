// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "RotateComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/FloatingPawnMovement.h"




// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Box);

	Propeller_L = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Propeller_L"));
	Propeller_L->SetupAttachment(Body);

	Propeller_R = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Propeller_R"));
	Propeller_R->SetupAttachment(Body);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Box);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(Body);

	FloatingPawnMovement= CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
	Rotate = CreateDefaultSubobject<URotateComponent>(TEXT("Rotate"));
	//
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MS_Body(TEXT("/Script/Engine.StaticMesh'/Game/FBX/P38/SM_P38_Body.SM_P38_Body'"));
	if (MS_Body.Succeeded())
	{
		Body->SetStaticMesh(MS_Body.Object);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Not exist pass_Body"));
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MS_Propeller(TEXT("/Script/Engine.StaticMesh'/Game/FBX/P38/SM_P38_Propeller.SM_P38_Propeller'"));
	if (MS_Propeller.Succeeded())
	{
		Propeller_L->SetStaticMesh(MS_Propeller.Object);
		Propeller_R->SetStaticMesh(MS_Propeller.Object);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Not exist pass_Propeller"));
	}
	//
	Propeller_L->AddLocalOffset(FVector(37.0f, -21.0f, 0.0f));
	Propeller_R->AddLocalOffset(FVector(37.0f, 21.0f, 0.0f));
	Arrow->AddLocalOffset(FVector(100.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 150.0f;
	SpringArm->bEnableCameraLag = true;
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();

	Rotate->Components.Add(Propeller_L);
	Rotate->Components.Add(Propeller_R);
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddMovementInput(GetActorForwardVector());

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &AMyPawn::Fire);
	PlayerInputComponent->BindAxis(TEXT("Pitch"), this, &AMyPawn::Pitch);
	PlayerInputComponent->BindAxis(TEXT("Roll"), this, &AMyPawn::Roll);

}

void AMyPawn::Fire()
{
	GetWorld()->SpawnActor<AMyPawn>(this->GetClass(),Arrow->K2_GetComponentLocation(),Arrow->K2_GetComponentRotation());
}

void AMyPawn::Pitch(float Value)
{
	if (Value != 0)
	{
		AddActorLocalRotation(FRotator(UGameplayStatics::GetWorldDeltaSeconds(GetWorld()) * 60 * Value, 0.0f, 0.0f));
	}
}

void AMyPawn::Roll(float Value)
{
	if (Value != 0)
	{
		AddActorLocalRotation(FRotator(0.0f,0.0f,UGameplayStatics::GetWorldDeltaSeconds(GetWorld()) * 60 * Value));
	}
}

