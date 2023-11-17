// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameHud.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOIDUE5_API UGameHud : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* PointsCount;


	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* LivesCount;

	virtual void NativeConstruct() override;
public:
	void setup();

	UFUNCTION(BlueprintCallable)
	void UpdateScore(int32 score);
};
