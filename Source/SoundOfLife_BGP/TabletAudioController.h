// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TabletAudioController.generated.h"

UENUM(BlueprintType)
enum class SoundGroup : uint8
{
	VE_Cough		UMETA(DisplayName = "Cough"),
	VE_Pound		UMETA(DisplayName = "Pound"),
	VE_Scratch		UMETA(DisplayName = "Scratch")
};

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
	AmplitudeAtTimestamp(float inAmplitude, float inTimestamp)
	{
		amplitude = inAmplitude;
		timestamp = inTimestamp;
	};
	float amplitude;
	float timestamp;
};

struct SpectrumData
{
	TArray<float> spectrum;
	TArray<AmplitudeAtTimestamp> timeline;
	float time = .0f;
	float volume = .0f;
	
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SOUNDOFLIFE_BGP_API UTabletAudioController : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTabletAudioController();
	UPROPERTY(EditDefaultsOnly)
	TArray<USoundWave*> coughWaves;
	UPROPERTY(EditDefaultsOnly)
	TArray<USoundWave*> scratchWaves;
	UPROPERTY(EditDefaultsOnly)
	TArray<USoundWave*> poundWaves;
	UPROPERTY(EditDefaultsOnly)
	USoundWave* cryWave;
	UPROPERTY(EditDefaultsOnly)
	USoundWave* breathWave;
	UPROPERTY(EditDefaultsOnly)
	USoundWave* staticNoiseWave;
	TArray<SpectrumData> currentSpectrums;



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	static SpectrumData GetSpectrumData(WaveSpectrum waveSelection);
	UFUNCTION(BlueprintCallable)
	TArray<float> GetFullSpectrum(float timeToAdd = .0f);
	UFUNCTION(BlueprintCallable)
	USoundWave* FetchAudio(SoundGroup soundGroup);
};
