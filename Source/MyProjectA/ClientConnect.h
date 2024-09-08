// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Networking.h"
#include "IPAddress.h" // Add this line#include "TCPClient.generated.h"
#include "ClientConnect.generated.h"


UCLASS()
class MYPROJECTA_API AClientConnect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AClientConnect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void ConnectToServer();

	UFUNCTION(BlueprintCallable)
	void SendMessage(const FString& Message);
	
	UFUNCTION(BlueprintCallable)
	void CloseConnection();

private:
	bool InitializeSocket();
	void ShutdownSocket();

	FSocket* ClientSocket;
	FIPv4Endpoint RemoteAddress;

};
