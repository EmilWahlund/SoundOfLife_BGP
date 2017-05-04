// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TabletAudioController.generated.h"

struct SpectrumData
{
	USoundWave* wave;
	TArray<float> spectrum;
	TArray<TPair<float, float>> amplitudeAtTimestamp;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SOUNDOFLIFE_BGP_API UTabletAudioController : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTabletAudioController();
	UPROPERTY(VisibleAnywhere)
	TArray<USoundWave*> coughWaves;
	UPROPERTY(VisibleAnywhere)
	TArray<USoundWave*> scratchWaves;
	UPROPERTY(VisibleAnywhere)
	TArray<USoundWave*> poundWaves;
	UPROPERTY(VisibleAnywhere)
	USoundWave* cryWave;
	UPROPERTY(VisibleAnywhere)
	USoundWave* breathWave;
	UPROPERTY(VisibleAnywhere)
	USoundWave* staticNoiseWave;



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
