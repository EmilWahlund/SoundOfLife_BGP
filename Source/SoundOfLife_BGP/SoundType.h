// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

UENUM(BlueprintType)
enum class SoundGroup : uint8
{
	VE_Cough		UMETA(DisplayName = "Cough"),
	VE_Pound		UMETA(DisplayName = "Pound"),
	VE_Scratch		UMETA(DisplayName = "Scratch"),
	VE_Breath		UMETA(DisplayName = "Breath"),
	VE_Cry			UMETA(DisplayName = "Cry")
};