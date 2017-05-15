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

UENUM(BlueprintType)
enum class Survivor : uint8
{
	VE_Girl			UMETA(DisplayName = "Girl"),
	VE_Dad			UMETA(DisplayName = "Dad"),
	VE_Bartender	UMETA(DisplayName = "Bartender"),
	Ve_Actress		UMETA(DisplayName = "Actress"),
	VE_None			UMETA(DisplayName = "None")
};