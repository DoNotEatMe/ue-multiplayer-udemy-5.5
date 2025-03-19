// Fill out your copyright notice in the Description page of Project Settings.


#include "Mybox.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AMybox::AMybox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//bReplicates = true;
	ReplicatedVar = 100;
	
}

// Called when the game starts or when spawned
void AMybox::BeginPlay()
{
	Super::BeginPlay();
	SetReplicates(true);
	
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

