// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Sensor.generated.h"

UCLASS()
class SOUNDOFLIFE_BGP_API ASensor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASensor();
	UPROPERTY(EditAnywhere)
	USphereComponent* detectionSphere;
	UPROPERTY(VisibleAnywhere)
	TArray<AActor*> victimsWithinProximity;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundCue* backgroundNoise;
	USceneComponent* audioParent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	TArray<TPair<float, USoundCue*>> audioList;
	TArray<TPair<float, USoundCue*>> GetAudio();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	void PlayAudio(float volume);
	UFUNCTION(BlueprintCallable)
	void StopAudio();
	UFUNCTION(BlueprintCallable)
	void VictimScan();
};
