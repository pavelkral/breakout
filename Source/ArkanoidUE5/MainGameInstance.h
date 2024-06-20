// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MainSaveGame.h"
#include "MainGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOIDUE5_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UMainGameInstance();

	UPROPERTY(BlueprintReadOnly)
	FString SaveGameSlotName;

	UPROPERTY(BlueprintReadWrite, Category = "Settings")
	UMainSaveGame* SaveGameObject;

	UFUNCTION(BlueprintCallable, Category = "Game Manager")
	void LoadGame();

	UFUNCTION(BlueprintCallable, Category = "Game Manager")
	void SaveGame();

private:
	void LogIfGameWasSavedOrNot(const bool IsSaved);
};
