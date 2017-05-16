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
	for (int i = 0; i < 10; i++)
	{
		noiseSpectrumV0.Add(FMath::FRandRange(noiseMinMax.X, noiseMinMax.Y));
	}
	for (int i = 0; i < 10; i++)
	{
		noiseSpectrumV1.Add(FMath::FRandRange(noiseMinMax.X, noiseMinMax.Y));
	}
	noiseDelay = FMath::FRandRange(noiseDelayRange.X, noiseDelayRange.Y);
	noiseDelayTime = .0f;
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

	noiseDelayTime += DeltaTime;
	if (noiseDelayTime >= noiseDelay)
	{
		noiseSpectrumV0 = noiseSpectrumV1;
		noiseSpectrumV1.Empty();
		for (int i = 0; i < 10; i++)
		{
			noiseSpectrumV1.Add(FMath::FRandRange(noiseMinMax.X, noiseMinMax.Y));
		}
		noiseDelayTime = .0f;
		noiseDelay = FMath::FRandRange(noiseDelayRange.X, noiseDelayRange.Y);
	}
}

SpectrumData UTabletAudioController::GetSpectrumData(WaveSpectrum waveSelection, AVictimLocation* owner)
{
	SpectrumData data;
	data.owner = owner;
	data.spectrum = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	data.timeline.Add({ 0.0f, 0.0f });
	switch (waveSelection)
	{
	case Cough1:
		data.spectrum = { 0.95f, 1.0f, 0.9f, 0.6f, 0.7f, 0.5f, 0.3f, 0.2f, 0.1f, 0.0f };
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
		data.timeline.Add({ 2.40f, 0.0f });
		break;
	case Cough2:
		data.spectrum = { 1.0f, 0.8f, 0.95f, 0.5f, 0.6f, 0.5f, 0.35f, 0.3f, 0.1f, 0.0f };
		data.timeline.Add({ 0.07f, 0.0f });
		data.timeline.Add({ 0.08f, 0.9f });
		data.timeline.Add({ 0.10f, 0.7f });
		data.timeline.Add({ 0.12f, 0.1f });
		data.timeline.Add({ 0.14f, 0.0f });
		data.timeline.Add({ 0.64f, 0.0f });
		data.timeline.Add({ 0.65f, 0.8f });
		data.timeline.Add({ 0.68f, 0.7f });
		data.timeline.Add({ 0.69f, 0.1f });
		data.timeline.Add({ 0.70f, 0.0f });
		data.timeline.Add({ 1.05f, 0.0f });
		data.timeline.Add({ 1.06f, 0.8f });
		data.timeline.Add({ 1.08f, 1.0f });
		data.timeline.Add({ 1.09f, 0.0f });
		break;
	case Cough3:
		data.spectrum = { 0.9f, 1.0f, 0.85f, 0.7f, 0.5f, 0.6f, 0.7f, 0.4f, 0.2f, 0.1f };
		data.timeline.Add({ 0.14f, 0.0f });
		data.timeline.Add({ 0.16f, 1.0f });
		data.timeline.Add({ 0.19f, 0.3f });
		data.timeline.Add({ 0.51f, 0.1f });
		data.timeline.Add({ 0.52f, 0.2f });
		data.timeline.Add({ 0.54f, 0.0f });
		data.timeline.Add({ 0.89f, 0.0f });
		data.timeline.Add({ 0.91f, 0.8f });
		data.timeline.Add({ 0.93f, 0.2f });
		data.timeline.Add({ 1.29f, 0.0f });
		data.timeline.Add({ 1.30f, 0.5f });
		data.timeline.Add({ 1.32f, 0.1f });
		data.timeline.Add({ 1.59f, 0.0f });
		break;
	case Cough4:
		data.spectrum = { 0.7f, 1.0f, 0.9f, 0.6f, 0.7f, 0.55f, 0.45f, 0.4f, 0.2f, 0.0f };
		data.timeline.Add({ 0.12f, 0.0f });
		data.timeline.Add({ 0.15f, 1.0f });
		data.timeline.Add({ 0.19f, 0.4f });
		data.timeline.Add({ 0.33f, 0.1f });
		data.timeline.Add({ 0.36f, 0.3f });
		data.timeline.Add({ 0.38f, 0.0f });
		data.timeline.Add({ 0.76f, 0.0f });
		data.timeline.Add({ 0.78f, 1.0f });
		data.timeline.Add({ 0.80f, 0.2f });
		data.timeline.Add({ 1.01f, 0.0f });
		break;
	case Cough5:
		data.spectrum = { 0.65f, 1.0f, 0.9f, 0.8f, 0.3f, 0.4f, 0.35f, 0.2f, 0.0f, 0.0f };
		data.timeline.Add({ 0.11f, 0.0f });
		data.timeline.Add({ 0.13f, 0.7f });
		data.timeline.Add({ 0.15f, 0.6f });
		data.timeline.Add({ 0.34f, 0.1f });
		data.timeline.Add({ 0.35f, 0.4f });
		data.timeline.Add({ 0.37f, 0.0f });
		data.timeline.Add({ 0.74f, 0.0f });
		data.timeline.Add({ 0.76f, 1.0f });
		data.timeline.Add({ 0.77f, 0.1f });
		data.timeline.Add({ 1.12f, 0.0f });
		break;
	case Cough6:
		data.spectrum = { 0.9f, 0.9f, 0.7f, 0.5f, 0.5f, 0.6f, 0.3f, 0.4f, 0.0f, 0.0f };
		data.timeline.Add({ 0.12f, 0.0f });
		data.timeline.Add({ 0.14f, 0.8f });
		data.timeline.Add({ 0.15f, 0.1f });
		data.timeline.Add({ 0.42f, 0.0f });
		data.timeline.Add({ 0.44f, 0.6f });
		data.timeline.Add({ 0.45f, 0.1f });
		data.timeline.Add({ 0.86f, 0.0f });
		data.timeline.Add({ 0.87f, 0.6f });
		data.timeline.Add({ 0.89f, 0.0f });
		break;
	case Pound1:
		data.spectrum = { 1.0f, 0.9f, 0.8f, 0.7f, 0.65f, 0.6f, 0.4f, 0.3f, 0.1f, 0.0f };
		data.timeline.Add({ 0.02f, 0.0f });
		data.timeline.Add({ 0.03f, 1.0f });
		data.timeline.Add({ 0.51f, 0.0f });
		break;
	case Pound2:
		data.spectrum = { 1.0f, 0.75f, 0.9f, 0.7f, 0.6f, 0.55f, 0.35f, 0.3f, 0.2f, 0.1f };
		data.timeline.Add({ 0.02f, 0.0f });
		data.timeline.Add({ 0.03f, 1.0f });
		data.timeline.Add({ 0.60f, 0.0f });
		data.timeline.Add({ 0.61f, 0.0f });
		data.timeline.Add({ 0.61f, 0.4f });
		data.timeline.Add({ 0.99f, 0.0f });
		break;
	case Pound3:
		data.spectrum = { 0.9f, 0.7f, 0.5f, 0.6f, 0.6f, 0.4f, 0.25f, 0.3f, 0.1f, 0.0f };
		data.timeline.Add({ 0.02f, 0.0f });
		data.timeline.Add({ 0.03f, 0.7f });
		data.timeline.Add({ 0.60f, 0.0f });
		data.timeline.Add({ 0.61f, 0.7f });
		data.timeline.Add({ 0.99f, 0.0f });
		break;
	case Pound4:
		data.spectrum = { 1.0f, 0.9f, 0.6f, 0.7f, 0.5f, 0.6f, 0.3f, 0.4f, 0.2f, 0.1f };
		data.timeline.Add({ 0.04f, 0.0f });
		data.timeline.Add({ 0.05f, 0.8f });
		data.timeline.Add({ 0.84f, 0.0f });
		break;
	case Pound5:
		data.spectrum = { 0.9f, 0.7f, 0.6f, 0.2f, 0.5f, 0.5f, 0.4f, 0.1f, 0.2f, 0.0f };
		data.timeline.Add({ 0.04f, 0.0f });
		data.timeline.Add({ 0.05f, 1.0f });
		data.timeline.Add({ 0.35f, 0.0f });
		break;
	case Scratch1:
		data.spectrum = { 1.0f, 0.9f, 0.95f, 0.85f, 0.8f, 0.7f, 0.65f, 0.6f, 0.5f, 0.4f };
		data.timeline.Add({ 0.06f, 0.0f });
		data.timeline.Add({ 0.27f, 0.8f });
		data.timeline.Add({ 0.42f, 0.0f });
		data.timeline.Add({ 0.57f, 0.0f });
		data.timeline.Add({ 0.64f, 0.7f });
		data.timeline.Add({ 0.69f, 0.7f });
		data.timeline.Add({ 0.82f, 0.0f });
		break;
	case Scratch2:
		data.spectrum = { 0.8f, 1.0f, 0.8f, 0.75f, 0.8f, 0.7f, 0.5f, 0.4f, 0.35f, 0.0f };
		data.timeline.Add({ 0.15f, 0.6f });
		data.timeline.Add({ 0.26f, 0.0f });
		break;
	case Scratch3:
		data.spectrum = { 1.0f, 0.8f, 0.8f, 0.9f, 0.7f, 0.6f, 0.55f, 0.4f, 0.4f, 0.35f };
		data.timeline.Add({ 0.32f, 0.5f });
		data.timeline.Add({ 0.55f, 0.0f });
		break;
	case Breath:
		data.spectrum = { 1.0f, 0.85f, 0.8f, 0.6f, 0.5f, 0.45f, 0.4f, 0.25f, 0.2f, 0.1f };
		data.timeline.Add({ 0.48f, 0.9f });
		data.timeline.Add({ 0.72f, 0.1f });
		data.timeline.Add({ 1.82f, 0.1f });
		data.timeline.Add({ 2.22f, 0.9f });
		data.timeline.Add({ 2.46f, 0.2f });
		data.timeline.Add({ 3.67f, 0.2f });
		data.timeline.Add({ 4.05f, 0.8f });
		data.timeline.Add({ 4.33f, 0.1f });
		data.timeline.Add({ 5.00f, 0.3f });
		data.timeline.Add({ 5.56f, 0.0f });
		data.timeline.Add({ 6.00f, 1.0f });
		data.timeline.Add({ 6.20f, 0.2f });
		data.timeline.Add({ 7.35f, 0.0f });
		data.timeline.Add({ 7.83f, 0.7f });
		data.timeline.Add({ 8.04f, 0.4f });
		data.timeline.Add({ 8.99f, 0.2f });
		data.timeline.Add({ 9.22f, 1.0f });
		data.timeline.Add({ 9.62f, 0.9f });
		data.timeline.Add({ 9.78f, 0.2f });
		data.timeline.Add({ 10.96f, 0.1f });
		data.timeline.Add({ 11.47f, 0.8f });
		data.timeline.Add({ 11.76f, 0.0f });
		data.timeline.Add({ 12.13f, 0.6f });
		data.timeline.Add({ 12.91f, 0.1f });
		data.timeline.Add({ 13.40f, 0.9f });
		data.timeline.Add({ 13.71f, 0.1f });
		data.timeline.Add({ 14.12f, 0.4f });
		data.timeline.Add({ 14.79f, 0.0f });
		data.timeline.Add({ 15.16f, 0.8f });
		data.timeline.Add({ 15.53f, 0.0f });
		data.timeline.Add({ 15.92f, 0.3f });
		data.timeline.Add({ 16.74f, 0.1f });
		data.timeline.Add({ 17.25f, 0.7f });
		data.timeline.Add({ 17.59f, 0.1f });
		data.timeline.Add({ 18.34f, 0.4f });
		data.timeline.Add({ 18.83f, 0.1f });
		data.timeline.Add({ 19.30f, 0.8f });
		data.timeline.Add({ 19.73f, 0.1f });
		data.timeline.Add({ 19.92f, 0.2f });
		data.timeline.Add({ 21.12f, 0.0f });
		break;
	case Cry:
		data.spectrum = { 0.9f, 0.7f, 0.75f, 0.6f, 0.7f, 0.5f, 0.4f, 0.35f, 0.2f, 0.0f };
		data.timeline.Add({ 0.15f, 0.0f });
		data.timeline.Add({ 0.16f, 0.4f });
		data.timeline.Add({ 0.57f, 0.1f });
		data.timeline.Add({ 0.72f, 0.0f });
		data.timeline.Add({ 0.73f, 0.5f });
		data.timeline.Add({ 0.90f, 0.0f });
		data.timeline.Add({ 1.32f, 0.0f });
		data.timeline.Add({ 1.33f, 0.1f });
		data.timeline.Add({ 1.57f, 0.1f });
		data.timeline.Add({ 1.58f, 0.0f });
		data.timeline.Add({ 1.82f, 0.0f });
		data.timeline.Add({ 1.87f, 0.5f });
		data.timeline.Add({ 1.98f, 0.0f });
		data.timeline.Add({ 2.48f, 0.0f });
		data.timeline.Add({ 2.63f, 0.4f });
		data.timeline.Add({ 3.10f, 0.2f });
		data.timeline.Add({ 3.11f, 0.0f });
		data.timeline.Add({ 3.35f, 0.0f });
		data.timeline.Add({ 3.36f, 0.4f });
		data.timeline.Add({ 3.75f, 0.5f });
		data.timeline.Add({ 3.76f, 0.0f });
		data.timeline.Add({ 4.10f, 0.0f });
		data.timeline.Add({ 4.11f, 0.6f });
		data.timeline.Add({ 4.26f, 0.2f });
		data.timeline.Add({ 4.28f, 0.9f });
		data.timeline.Add({ 4.36f, 0.0f });
		data.timeline.Add({ 4.74f, 0.0f });
		data.timeline.Add({ 4.75f, 0.2f });
		data.timeline.Add({ 5.23f, 0.2f });
		data.timeline.Add({ 5.25f, 0.4f });
		data.timeline.Add({ 5.29f, 0.0f });
		data.timeline.Add({ 5.39f, 0.0f });
		data.timeline.Add({ 5.40f, 1.0f });
		data.timeline.Add({ 5.45f, 0.1f });
		data.timeline.Add({ 5.61f, 0.0f });
		data.timeline.Add({ 5.63f, 0.5f });
		data.timeline.Add({ 5.68f, 0.0f });
		data.timeline.Add({ 5.75f, 0.0f });
		data.timeline.Add({ 5.77f, 0.5f });
		data.timeline.Add({ 5.81f, 0.0f });
		data.timeline.Add({ 6.28f, 0.0f });
		data.timeline.Add({ 6.31f, 0.4f });
		data.timeline.Add({ 6.35f, 0.0f });
		data.timeline.Add({ 6.43f, 0.0f });
		data.timeline.Add({ 6.45f, 0.5f });
		data.timeline.Add({ 6.52f, 0.5f });
		data.timeline.Add({ 6.60f, 0.0f });
		data.timeline.Add({ 6.76f, 0.0f });
		data.timeline.Add({ 6.77f, 0.2f });
		data.timeline.Add({ 6.92f, 0.0f });
		data.timeline.Add({ 6.94f, 0.2f });
		data.timeline.Add({ 7.12f, 0.0f });
		data.timeline.Add({ 7.34f, 0.0f });
		data.timeline.Add({ 7.53f, 0.5f });
		data.timeline.Add({ 8.15f, 0.0f });
		data.timeline.Add({ 8.34f, 0.4f });
		data.timeline.Add({ 8.82f, 0.1f });
		data.timeline.Add({ 8.86f, 0.8f });
		data.timeline.Add({ 8.93f, 0.0f });
		data.timeline.Add({ 9.29f, 0.0f });
		data.timeline.Add({ 9.32f, 0.9f });
		data.timeline.Add({ 9.33f, 0.0f });
		data.timeline.Add({ 10.21f, 0.0f });
		data.timeline.Add({ 10.29f, 0.4f });
		data.timeline.Add({ 10.49f, 0.1f });
		data.timeline.Add({ 10.52f, 0.3f });
		data.timeline.Add({ 10.56f, 0.0f });
		data.timeline.Add({ 10.84f, 0.0f });
		data.timeline.Add({ 10.87f, 0.4f });
		data.timeline.Add({ 11.00f, 0.4f });
		data.timeline.Add({ 11.09f, 0.6f });
		data.timeline.Add({ 11.10f, 0.3f });
		data.timeline.Add({ 11.25f, 0.1f });
		data.timeline.Add({ 11.26f, 1.0f });
		data.timeline.Add({ 11.34f, 0.0f });
		data.timeline.Add({ 11.70f, 0.0f });
		data.timeline.Add({ 11.76f, 0.5f });
		data.timeline.Add({ 12.34f, 0.1f });
		data.timeline.Add({ 12.38f, 0.3f });
		data.timeline.Add({ 12.46f, 0.0f });
		data.timeline.Add({ 12.54f, 0.0f });
		data.timeline.Add({ 12.56f, 0.6f });
		data.timeline.Add({ 12.63f, 0.0f });
		data.timeline.Add({ 13.35f, 0.0f });
		data.timeline.Add({ 13.47f, 0.5f });
		data.timeline.Add({ 13.55f, 0.4f });
		data.timeline.Add({ 14.09f, 0.1f });
		data.timeline.Add({ 14.17f, 0.2f });
		data.timeline.Add({ 14.97f, 0.0f });
		data.timeline.Add({ 16.02f, 0.0f });
		data.timeline.Add({ 16.12f, 0.4f });
		data.timeline.Add({ 16.89f, 0.4f });
		data.timeline.Add({ 16.94f, 0.0f });
		data.timeline.Add({ 17.05f, 0.0f });
		data.timeline.Add({ 17.09f, 0.5f });
		data.timeline.Add({ 17.28f, 0.0f });
		data.timeline.Add({ 17.29f, 0.9f });
		data.timeline.Add({ 17.31f, 0.3f });
		data.timeline.Add({ 17.34f, 0.6f });
		data.timeline.Add({ 17.35f, 0.0f });
		data.timeline.Add({ 17.51f, 0.0f });
		data.timeline.Add({ 17.58f, 0.8f });
		data.timeline.Add({ 17.59f, 0.0f });
		break;
	case Pipes1:
		data.spectrum = { 1.0f, 0.4f, 0.35f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
		data.timeline.Add({ 0.06f, 0.0f });
		data.timeline.Add({ 0.20f, 1.0f });
		data.timeline.Add({ 0.25f, 0.8f });
		data.timeline.Add({ 0.28f, 0.9f });
		data.timeline.Add({ 0.44f, 0.2f });
		data.timeline.Add({ 0.60f, 0.2f });
		data.timeline.Add({ 0.67f, 0.3f });
		data.timeline.Add({ 0.83f, 0.2f });
		data.timeline.Add({ 3.10f, 0.0f });
		break;
	case Pipes2:
		data.spectrum = { 1.0f, 0.2f, 0.4f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
		data.timeline.Add({ 0.03f, 0.0f });
		data.timeline.Add({ 0.18f, 0.5f });
		data.timeline.Add({ 0.26f, 1.0f });
		data.timeline.Add({ 0.47f, 0.8f });
		data.timeline.Add({ 0.73f, 0.4f });
		data.timeline.Add({ 1.57f, 0.1f });
		data.timeline.Add({ 2.47f, 0.2f });
		data.timeline.Add({ 4.71f, 0.0f });
		break;
	case Pipes3:
		data.spectrum = { 1.0f, 0.4f, 0.1f, 0.0f, 0.3f, 0.0f, 0.2f, 0.0f, 0.0f, 0.0f };
		data.timeline.Add({ 0.05f, 0.0f });
		data.timeline.Add({ 0.14f, 0.9f });
		data.timeline.Add({ 0.22f, 0.5f });
		data.timeline.Add({ 0.39f, 0.3f });
		data.timeline.Add({ 0.47f, 0.4f });
		data.timeline.Add({ 2.90f, 0.0f });
		break;
	case Pipes4:
		data.spectrum = { 1.0f, 0.8f, 0.1f, 0.2f, 0.0f, 0.3f, 0.0f, 0.0f, 0.0f, 0.0f };
		data.timeline.Add({ 0.05f, 0.0f });
		data.timeline.Add({ 0.16f, 0.8f });
		data.timeline.Add({ 0.26f, 0.5f });
		data.timeline.Add({ 0.45f, 0.4f });
		data.timeline.Add({ 3.85f, 0.0f });
		break;
	default:
		break;
	};
	return data;
}

TArray<float> UTabletAudioController::GetFullSpectrum()
{
	TArray<float> spectrum;
	spectrum.Init(.0f, 10);
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
	for (int i = 0; i < 10; i++)
	{
		spectrum[i] += FMath::Lerp(noiseSpectrumV0[i], noiseSpectrumV1[i], noiseDelayTime / noiseDelay);
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
		victimCue = scratchWaves[val];
		break;
	case SoundGroup::VE_Breath:
		spectrum = WaveSpectrum::Breath;
		victimCue = breathWave;
		break;
	case SoundGroup::VE_Cry:
		spectrum = WaveSpectrum::Cry;
		victimCue = cryWave;
		break;
	case SoundGroup::VE_Pipes:
		val = FMath::Rand() % 4;
		switch (val)
		{
		case 0:
			spectrum = WaveSpectrum::Pipes1;
			break;
		case 1:
			spectrum = WaveSpectrum::Pipes2;
			break;
		case 2:
			spectrum = WaveSpectrum::Pipes3;
			break;
		case 3:
			spectrum = WaveSpectrum::Pipes4;
			break;
		default:
			break;
		}
		victimCue = pipeWaves[val];
		break;
	default:
		break;
	}
	currentSpectrums.Add(GetSpectrumData(spectrum, owner));
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

void UTabletAudioController::RemoveFromSpectrum(AVictimLocation* owner)
{
	for (int i = 0; i < currentSpectrums.Num(); i++)
	{
		if (currentSpectrums[i].owner == owner)
		{
			currentSpectrums.RemoveAt(i);
			i--;
		}
	}
}