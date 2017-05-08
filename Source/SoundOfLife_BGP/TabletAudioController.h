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
	Scratch3
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
	USoundCue* staticNoiseWave;
	TArray<SpectrumData> currentSpectrums;



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
