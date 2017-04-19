// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundOfLife_BGP.h"
#include "VictimLocation.h"


// Sets default values
AVictimLocation::AVictimLocation()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USphereComponent* sphere = CreateDefaultSubobject<USphereComponent>(TEXT("DetectionSphere"));
	RootComponent = sphere;
	sphere->InitSphereRadius(50.0f);
	collisionSphere = sphere;

	USoundCue* audio = CreateDefaultSubobject<USoundCue>(TEXT("VictimAudio"));
	victimAudio = audio;
}

// Called when the game starts or when spawned
void AVictimLocation::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AVictimLocation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

USoundCue* AVictimLocation::GetAudio()
{
	return victimAudio;
}
