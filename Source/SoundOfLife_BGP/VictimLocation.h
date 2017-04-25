// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "VictimLocation.generated.h"

UCLASS()
class SOUNDOFLIFE_BGP_API AVictimLocation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVictimLocation();
	UPROPERTY(VisibleAnywhere)
	USphereComponent* collisionSphere;
	UPROPERTY(VisibleAnywhere)
	UAudioComponent* audioComponent;
	UPROPERTY(EditAnywhere)
	USoundCue* victimSound;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	void SetVolume(float volume);
};
