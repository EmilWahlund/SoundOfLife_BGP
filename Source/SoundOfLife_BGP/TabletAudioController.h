// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VictimLocation.h"
#include "Components/ActorComponent.h"
#include "TabletAudioController.generated.h"

enum WaveSpectrum
{
	Cough1,
	Cough2,
	Cough3,
	Cough4,
	Cough5,
	Cough6,
	Pound1,
	Pound2,
	Pound3,
	Pound4,
	Pound5,
	Scratch1,
	Scratch2,
	Scratch3,
	Breath,
	Cry,
	Pipes1,
	Pipes2,
	Pipes3,
	Pipes4,
	Waves
};

struct AmplitudeAtTimestamp
{
	AmplitudeAtTimestamp(float inTimestamp, float inAmplitude)
	{
		timestamp = inTimestamp;
		amplitude = inAmplitude;
	};
	float timestamp;
	float amplitude;
};

struct SpectrumData
{
	TArray<float> spectrum;
	TArray<AmplitudeAtTimestamp> timeline;
	float time = .0f;
	float volume = .0f;
	AVictimLocation* owner;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SOUNDOFLIFE_BGP_API UTabletAudioController : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTabletAudioController();
	UPROPERTY(EditAnywhere)
	TArray<USoundCue*> coughWaves;
	UPROPERTY(EditAnywhere)
	TArray<USoundCue*> scratchWaves;
	UPROPERTY(EditAnywhere)
	TArray<USoundCue*> poundWaves;
	UPROPERTY(EditAnywhere)
	USoundCue* cryWave;
	UPROPERTY(EditAnywhere)
	USoundCue* breathWave;
	UPROPERTY(EditAnywhere)
	TArray<USoundCue*> pipeWaves;
	UPROPERTY(EditAnywhere)
	USoundCue* wavesWaves;
	TArray<SpectrumData> currentSpectrums;
	UPROPERTY()
	TArray<float> noiseSpectrumV0;
	UPROPERTY()
	TArray<float> noiseSpectrumV1;
	UPROPERTY(EditAnywhere)
	FVector2D noiseMinMax = { 0.1f, 0.3f };
	UPROPERTY(EditAnywhere)
	FVector2D noiseDelayRange = { 0.05f, 0.1f };
	UPROPERTY()
	float noiseDelayTime;
	UPROPERTY()
	float noiseDelay;



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	static SpectrumData GetSpectrumData(WaveSpectrum waveSelection, AVictimLocation* owner);
	UFUNCTION(BlueprintCallable)
	TArray<float> GetFullSpectrum();
	UFUNCTION(BlueprintCallable)
	USoundCue* FetchAudio(SoundGroup soundGroup, AVictimLocation* owner);
	UFUNCTION(BlueprintCallable)
	void SetVolume(AVictimLocation* owner, float volume);
	UFUNCTION(BlueprintCallable)
	void ClearSpectrum();
	UFUNCTION(BlueprintCallable)
	void RemoveFromSpectrum(AVictimLocation* owner);
};
