// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundOfLife_BGP.h"
#include "TabletAudioController.h"


// Sets default values for this component's properties
UTabletAudioController::UTabletAudioController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	/*static ConstructorHelpers::FObjectFinder<USoundWave> sound(TEXT("/Game/Audio/SoundEffects/ljuddesign_sol_-_scratch1_16bit.ljuddesign_sol_-_scratch1_16bit"));
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

	// ...
}

SpectrumData UTabletAudioController::GetSpectrumData(WaveSpectrum waveSelection)
{
	SpectrumData data;
	data.spectrum = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	switch (waveSelection)
	{
	case Cough1:
		data.spectrum = { 0.95f, 1.0f, 0.9f, 0.6f, 0.7f, 0.5f, 0.3f, 0.2f, 0.1f, 0.0f };
		data.timeline.Add({ 0, 0 });
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

