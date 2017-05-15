// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SoundType.h"
#include "GameFramework/Actor.h"
#include "VictimLocation.generated.h"

UCLASS()
class SOUNDOFLIFE_BGP_API AVictimLocation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVictimLocation();
	UPROPERTY(VisibleAnywhere)
	USphereComponent* collisionSphere;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UAudioComponent* audioComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	SoundGroup soundGroup;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	Survivor survivor;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float delayTime = .0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	void SetVolume(float volume);
	UFUNCTION(BlueprintCallable)
	void SetSoundCue(USoundCue* cue, float postDelay);
};
