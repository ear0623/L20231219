// Fill out your copyright notice in the Description page of Project Settings.


#include "ClientConnect.h"
#include "Engine/Engine.h"
#include "Misc/OutputDeviceNull.h"

// Sets default values
AClientConnect::AClientConnect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ClientSocket = nullptr;
}

// Called when the game starts or when spawned
void AClientConnect::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AClientConnect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AClientConnect::ConnectToServer()
{
    if (!InitializeSocket())
    {
        return;
    }

    FString PublicIp = TEXT("192.168.200.254");
    int32 Port = 65432;
    FIPv4Address IPAddress;
    if (!FIPv4Address::Parse(PublicIp, IPAddress))
    {
        UE_LOG(LogTemp, Error, TEXT("Invalid IP address format: %s"), *PublicIp);
        return;
    }
#pragma region Legercy

    /*TArray<FString> AddressParts;
    ServerAddress.ParseIntoArray(AddressParts, TEXT("."), true);

    if (AddressParts.Num() != 4)
    {
        UE_LOG(LogTemp, Error, TEXT("Invalid IP address format."));
        return;
    }
     uint8 IP[4];
    for (int32 i = 0; i < 4; ++i)
    {
        IP[i] = FCString::Atoi(*AddressParts[i]);
    }

    RemoteAddress = FIPv4Endpoint(FIPv4Address(IP[0], IP[1], IP[2], IP[3]), Port);
    bool bConnected = ClientSocket->Connect(*RemoteAddress.ToInternetAddr());

    if (bConnected)
    {
        UE_LOG(LogTemp, Log, TEXT("Successfully connected to server."));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to connect to server."));
    }*/
#pragma endregion

    RemoteAddress = FIPv4Endpoint(IPAddress, Port);
    bool bConnected = ClientSocket->Connect(*RemoteAddress.ToInternetAddr());
    if (bConnected)
    {
        UE_LOG(LogTemp, Log, TEXT("Successfully connected to server at %s:%d"), *PublicIp, Port);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to connect to server at %s:%d"), *PublicIp, Port);
    }
   
}

void AClientConnect::SendMessage(const FString& Message)
{
    if (!ClientSocket) return;

    FTCHARToUTF8 Converted(*Message);
    int32 Size = Converted.Length();
    int32 Sent = 0;


    bool bSent = ClientSocket->Send((uint8*)Converted.Get(), Size, Sent);

    if (bSent)
    {
        UE_LOG(LogTemp, Log, TEXT("Message sent successfully."));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to send message."));
    }
}

void AClientConnect::CloseConnection()
{
    ShutdownSocket();
}

bool AClientConnect::InitializeSocket()
{
    ClientSocket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);

    if (!ClientSocket)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to create socket."));
        return false;
    }

    return true;
}

void AClientConnect::ShutdownSocket()
{
    if (ClientSocket)
    {
        ClientSocket->Close();
        ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ClientSocket);
        ClientSocket = nullptr;
    }
}

