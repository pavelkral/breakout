// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHud.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UGameHud::NativeConstruct()
{
}

void UGameHud::setup()
{
	LivesCount->SetText(FText::AsNumber(0));
}

void UGameHud::UpdateScore(int32 score)
{
	PointsCount->SetText(FText::AsNumber(score));
}
