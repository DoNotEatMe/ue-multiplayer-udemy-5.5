// Fill out your copyright notice in the Description page of Project Settings.


#include "Mybox.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AMybox::AMybox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ReplicatedVar = 100;
	
}

// Called when the game starts or when spawned
void AMybox::BeginPlay()
{
	Super::BeginPlay();
	SetReplicates(true);
	SetReplicateMovement(true);

	if (HasAuthority())
	{
		GetWorld()->GetTimerManager().SetTimer(TestTimer,this,&AMybox::MulticastRPCExplode, 2.f,false);
	}
	
}

// Called every frame
void AMybox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMybox::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMybox, ReplicatedVar);
}



void AMybox::OnRep_ReplicatedVar()
{
	if (HasAuthority())
	{
		FVector NewLocation = GetActorLocation() + FVector(0, 0, 100);
		SetActorLocation(NewLocation);
		
		//GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Green,"Server OnRep_ReplicatedVar");
	} else
	{
		// GEngine->AddOnScreenDebugMessage(-1,15.f,FColor::Yellow,
		// 	FString::Printf(TEXT("Client %d OnRep_ReplicatedVar"), UE::GetPlayInEditorID()));
	}
}

void AMybox::DecreaseReplicatedVar()
{
	if (HasAuthority())
	{
		ReplicatedVar -= 1.0f;
		OnRep_ReplicatedVar();
		if (ReplicatedVar > 0)
		{
			GetWorld()->GetTimerManager().SetTimer(TestTimer,this,&AMybox::DecreaseReplicatedVar, 2.f,false);
		}
	}
}

void AMybox::MulticastRPCExplode_Implementation()
{
	if (HasAuthority()){
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Red,
		FString::Printf(TEXT("Server %d MulticastRPCFunction_Implementation"), UE::GetPlayInEditorID()));
		GetWorld()->GetTimerManager().SetTimer(TestTimer,this,&AMybox::MulticastRPCExplode, 2.f,false);
		
	} else
	{
		GEngine->AddOnScreenDebugMessage(-1,3.f,FColor::Green,
		FString::Printf(TEXT("Client %d MulticastRPCFunction_Implementation"), UE::GetPlayInEditorID()));
	}

	
	
}
