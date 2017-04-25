// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundOfLife_BGP.h"
#include "Sensor.h"
#include "VictimLocation.h"


// Sets default values
ASensor::ASensor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UStaticMeshComponent* staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = staticMesh;
	mesh = staticMesh;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> staticMeshAsset(TEXT("StaticMesh'/Game/Meshes/StaticMeshes/Sensor_LP.Sensor_LP'"));
	if (staticMeshAsset.Succeeded())
	{
		staticMesh->SetStaticMesh(staticMeshAsset.Object);
	}
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