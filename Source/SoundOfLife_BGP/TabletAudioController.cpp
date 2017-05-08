// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundOfLife_BGP.h"
#include "TabletAudioController.h"


// Sets default values for this component's properties
UTabletAudioController::UTabletAudioController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	/*static ConstructorHelpers::FObjectFinder<USoundCue> sound(TEXT("/Game/Audio/SoundEffects/ljuddesign_sol_-_scratch1_16bit.ljuddesign_sol_-_scratch1_16bit"));
	if (sound.Succeeded())
		test = sound.Object;*/
	// ...
}


// Called when the game starts
void UTabletAudioController::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTabletAudioController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	for (int i = 0; i < currentSpectrums.Num(); i++)
	{
		currentSpectrums[i].time += DeltaTime;
		if (currentSpectrums[i].time >= currentSpectrums[i].timeline.Last().timestamp)
		{
			currentSpectrums.RemoveAt(i);
			i--;
		}
	}
}

SpectrumData UTabletAudioController::GetSpectrumData(WaveSpectrum waveSelection, AVictimLocation* owner)
{
	SpectrumData data;
	data.owner = owner;
	//data.spectrum = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	data.spectrum = { 0.95f, 1.0f, 0.9f, 0.6f, 0.7f, 0.5f, 0.3f, 0.2f, 0.1f, 0.0f };
	data.timeline.Add({ 0.00f, 0.0f });
	data.timeline.Add({ 0.11f, 0.0f });
	data.timeline.Add({ 0.12f, 1.0f });
	data.timeline.Add({ 0.19f, 0.8f });
	data.timeline.Add({ 0.61f, 0.1f });
	data.timeline.Add({ 0.62f, 0.6f });
	data.timeline.Add({ 0.64f, 0.5f });
	data.timeline.Add({ 0.65f, 0.1f });
	data.timeline.Add({ 0.94f, 0.0f });
	data.timeline.Add({ 0.95f, 0.7f });
	data.timeline.Add({ 0.98f, 0.6f });
	data.timeline.Add({ 0.99f, 0.2f });
	data.timeline.Add({ 1.49f, 0.0f });
	data.timeline.Add({ 1.50f, 0.5f });
	data.timeline.Add({ 1.52f, 0.4f });
	data.timeline.Add({ 1.53f, 0.1f });
	data.timeline.Add({ 1.96f, 0.0f });
	data.timeline.Add({ 1.97f, 0.5f });
	data.timeline.Add({ 1.98f, 0.4f });
	data.timeline.Add({ 1.99f, 0.1f });
	data.timeline.Add({ 2.36f, 0.0f });
	data.timeline.Add({ 2.37f, 0.4f });
	data.timeline.Add({ 2.39f, 0.3f });
	data.timeline.Add({ 2.40f, 0.1f });
	data.timeline.Add({ 2.92f, 0.0f });


	switch (waveSelection)
	{
	case Cough1:
		/*data.spectrum = { 0.95f, 1.0f, 0.9f, 0.6f, 0.7f, 0.5f, 0.3f, 0.2f, 0.1f, 0.0f };
		data.timeline.Add({ 0.11f, 0.0f });
		data.timeline.Add({ 0.12f, 1.0f });
		data.timeline.Add({ 0.19f, 0.8f });
		data.timeline.Add({ 0.61f, 0.1f });
		data.timeline.Add({ 0.62f, 0.6f });
		data.timeline.Add({ 0.64f, 0.5f });
		data.timeline.Add({ 0.65f, 0.1f });
		data.timeline.Add({ 0.94f, 0.0f });
		data.timeline.Add({ 0.95f, 0.7f });
		data.timeline.Add({ 0.98f, 0.6f });
		data.timeline.Add({ 0.99f, 0.2f });
		data.timeline.Add({ 1.49f, 0.0f });
		data.timeline.Add({ 1.50f, 0.5f });
		data.timeline.Add({ 1.52f, 0.4f });
		data.timeline.Add({ 1.53f, 0.1f });
		data.timeline.Add({ 1.96f, 0.0f });
		data.timeline.Add({ 1.97f, 0.5f });
		data.timeline.Add({ 1.98f, 0.4f });
		data.timeline.Add({ 1.99f, 0.1f });
		data.timeline.Add({ 2.36f, 0.0f });
		data.timeline.Add({ 2.37f, 0.4f });
		data.timeline.Add({ 2.39f, 0.3f });
		data.timeline.Add({ 2.40f, 0.1f });
		data.timeline.Add({ 2.92f, 0.0f });*/
		break;
	case Cough2:
		break;
	case Cough3:
		break;
	case Cough4:
		break;
	case Cough5:
		break;
	case Cough6:
		break;
	case Pound1:
		break;
	case Pound2:
		break;
	case Pound3:
		break;
	case Pound4:
		break;
	case Pound5:
		break;
	case Scratch1:
		break;
	case Scratch2:
		break;
	case Scratch3:
		break;
	default:
		break;
	}
	return data;
}

TArray<float> UTabletAudioController::GetFullSpectrum()
{
	TArray<float> spectrum = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < currentSpectrums.Num(); i++)
	{
		float amplitude = 0.0f;
		if (currentSpectrums[i].volume <= .0f)
		{
			continue;
		}
		for (int j = 0; j < currentSpectrums[i].timeline.Num(); j++)
		{
			if (j < currentSpectrums[i].timeline.Num() - 1 && currentSpectrums[i].time >= currentSpectrums[i].timeline[j].timestamp && currentSpectrums[i].time < currentSpectrums[i].timeline[j + 1].timestamp)
			{
				float timeFrame = currentSpectrums[i].timeline[j + 1].timestamp - currentSpectrums[i].timeline[j].timestamp;
				float timeInFrame = currentSpectrums[i].time - currentSpectrums[i].timeline[j].timestamp;
				amplitude = FMath::Lerp(currentSpectrums[i].timeline[j].amplitude, currentSpectrums[i].timeline[j + 1].amplitude, timeInFrame / timeFrame);
				break;
			}	
		}
		for (int j = 0; j < spectrum.Num(); j++)
		{
			spectrum[j] = FMath::Max(spectrum[j], currentSpectrums[i].spectrum[j] * amplitude * currentSpectrums[i].volume);
		}
	}
	
	return spectrum;
}

USoundCue* UTabletAudioController::FetchAudio(SoundGroup soundGroup, AVictimLocation* owner)
{
	USoundCue* victimCue = coughWaves[0];
	WaveSpectrum spectrum = WaveSpectrum::Cough1;
	int val = 0;;
	switch (soundGroup)
	{
	case SoundGroup::VE_Cough:
		val = FMath::Rand() % 6;
		switch (val)
		{
		case 0:
			spectrum = WaveSpectrum::Cough1;
			break;
		case 1:
			spectrum = WaveSpectrum::Cough2;
			break;
		case 2:
			spectrum = WaveSpectrum::Cough3;
			break;
		case 3:
			spectrum = WaveSpectrum::Cough4;
			break;
		case 4:
			spectrum = WaveSpectrum::Cough5;
			break;
		case 5:
			spectrum = WaveSpectrum::Cough6;
			break;
		default:
			break;
		}
		currentSpectrums.Add(GetSpectrumData(spectrum, owner));
		victimCue = coughWaves[val];
		break;
	case SoundGroup::VE_Pound:
		val = FMath::Rand() % 5;
		switch (val)
		{
		case 0:
			spectrum = WaveSpectrum::Pound1;
			break;
		case 1:
			spectrum = WaveSpectrum::Pound2;
			break;
		case 2:
			spectrum = WaveSpectrum::Pound3;
			break;
		case 3:
			spectrum = WaveSpectrum::Pound4;
			break;
		case 4:
			spectrum = WaveSpectrum::Pound5;
			break;
		default:
			break;
		}
		currentSpectrums.Add(GetSpectrumData(spectrum, owner));
		victimCue = poundWaves[val];
		break;
	case SoundGroup::VE_Scratch:
		val = FMath::Rand() % 3;
		switch (val)
		{
		case 0:
			spectrum = WaveSpectrum::Scratch1;
			break;
		case 1:
			spectrum = WaveSpectrum::Scratch2;
			break;
		case 2:
			spectrum = WaveSpectrum::Scratch3;
			break;
		default:
			break;
		}
		currentSpectrums.Add(GetSpectrumData(spectrum, owner));
		victimCue = scratchWaves[val];
		break;
	default:
		break;
	}
	return victimCue;
}

void UTabletAudioController::SetVolume(AVictimLocation* owner, float volume)
{
	for (int i = 0; i < currentSpectrums.Num(); i++)
	{
		if (currentSpectrums[i].owner == owner)
		{
			currentSpectrums[i].volume = volume;
		}
	}
}

void UTabletAudioController::ClearSpectrum()
{
	while (currentSpectrums.Num() != 0)
	{
		currentSpectrums.RemoveAt(0);
	}
}