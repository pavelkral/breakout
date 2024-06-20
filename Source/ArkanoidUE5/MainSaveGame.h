// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
//#include "UObject/ObjectMacros.h"
#include "MainSaveGame.generated.h"


UENUM(BlueprintType)
enum class EPlayerStatus : uint8
{
	PS_Alive        UMETA(DisplayName = "Alive"),
	PS_Dead         UMETA(DisplayName = "Dead")
};
/**
 *
 */
UCLASS()
class ARKANOIDUE5_API UMainSaveGame : public USaveGame
{
	GENERATED_BODY()

public:

	UMainSaveGame();

	UPROPERTY(BlueprintReadWrite, Category = "Player Info")
	FString PlayerName;

	UPROPERTY(BlueprintReadWrite, Category = "Player Info")
	int32 PlayerAge;

	UPROPERTY(BlueprintReadWrite, Category = "Player Info")
	EPlayerStatus PlayerStatus;

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	int32 PlayerScore;

	UPROPERTY(VisibleAnywhere, Category = "SaveGameData")
	FVector PlayerPosition;
};
