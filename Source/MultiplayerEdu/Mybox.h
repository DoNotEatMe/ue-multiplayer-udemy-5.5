// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mybox.generated.h"

UCLASS()
class MULTIPLAYEREDU_API AMybox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMybox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(ReplicatedUsing= OnRep_ReplicatedVar, BlueprintReadWrite)
	float ReplicatedVar;

	UFUNCTION(BlueprintCallable)
	void OnRep_ReplicatedVar();
	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	void DecreaseReplicatedVar();	
	FTimerHandle TestTimer;

	UFUNCTION(NetMulticast, Reliable,BlueprintCallable)
	void MulticastRPCExplode();

	UPROPERTY(EditAnywhere)
	class UParticleSystem* ExplosionEffect;
	
};


