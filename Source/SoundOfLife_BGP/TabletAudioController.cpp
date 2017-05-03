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

