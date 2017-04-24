// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundOfLife_BGP.h"
#include "Sensor.h"
#include "VictimLocation.h"


// Sets default values
ASensor::ASensor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USphereComponent* sphere = CreateDefaultSubobject<USphereComponent>(TEXT("DetectionSphere"));
	RootComponent = sphere;
	sphere->InitSphereRadius(500.0f);
	detectionSphere = sphere;

	UStaticMeshComponent* staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	staticMesh->SetupAttachment(RootComponent);
	mesh = staticMesh;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> staticMeshAsset(TEXT("StaticMesh'/Game/Meshes/StaticMeshes/Sensor_LP.Sensor_LP'"));
	if (staticMeshAsset.Succeeded())
	{
		staticMesh->SetStaticMesh(staticMeshAsset.Object);
	}

	audioParent = CreateDefaultSubobject<USceneComponent>(TEXT("AudioParent"));
	audioParent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASensor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASensor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

TArray<TPair<float, USoundCue*>> ASensor::GetAudio()
{
	TArray<TPair<float, USoundCue*>> audioList;
	for (int i = 0; i < victimsWithinProximity.Num(); i++)
	{
		TPair<float, USoundCue*> pair;
		pair.Key = (detectionSphere->GetComponentLocation() - victimsWithinProximity[i]->GetActorLocation()).Size();
		pair.Value = ((AVictimLocation*)victimsWithinProximity[i])->GetAudio();
		audioList.Add(pair);
	}
	TPair<float, USoundCue*> pair;
	pair.Key = .0f;
	pair.Value = backgroundNoise;
	audioList.Add(pair);
	return audioList;
}

void ASensor::PlayAudio(float volume)
{
	audioList = GetAudio();
	for (int i = 0; i < audioList.Num(); i++)
	{
		FString string = FString::Printf(TEXT("AudioSource %i"), i);
		UAudioComponent* audioComponent = NewObject<UAudioComponent>(this, FName(*string));
		audioComponent->SetSound(audioList[i].Value);
		float amplitude = volume * (1.0f - (audioList[i].Key / detectionSphere->GetUnscaledSphereRadius()));
		audioComponent->FadeIn(0, amplitude, 0);
		audioComponent->AttachTo(audioParent);
	}
}

void ASensor::StopAudio()
{
	while (audioParent->GetNumChildrenComponents() > 0)
	{
		UAudioComponent* audioComponent = (UAudioComponent*)audioParent->GetChildComponent(0);
		audioComponent->Stop();
		audioComponent->DestroyComponent();
	}
}

void ASensor::VictimScan()
{
	TArray<AActor*> overlappingActors;
	detectionSphere->GetOverlappingActors(overlappingActors, AActor::StaticClass());
	for (int i = 0; i < overlappingActors.Num(); i++)
	{
		if (overlappingActors[i]->IsA(AVictimLocation::StaticClass()))
		{
			AVictimLocation* victimLocation = (AVictimLocation*)overlappingActors[i];
			bool isNew = true;
			for (int j = 0; j < victimsWithinProximity.Num(); j++)
			{
				if (victimLocation == victimsWithinProximity[j])
				{
					isNew = false;
					break;
				}
			}
			if (isNew)
				victimsWithinProximity.Add(victimLocation);
		}
	}
}