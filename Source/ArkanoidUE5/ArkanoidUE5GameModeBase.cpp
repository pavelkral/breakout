// Copyright Epic Games, Inc. All Rights Reserved.


#include "ArkanoidUE5GameModeBase.h"


#include "GameHud.h"
#include "Blueprint/UserWidget.h"
#include "Components/ArrowComponent.h"
#include "Kismet/GameplayStatics.h"



void AArkanoidUE5GameModeBase::BeginPlay()

{

	GameHud = Cast<UGameHud>(CreateWidget(GetWorld(), GameHudClass));
	check(GameHud);

	GameHud->setup();
	GameHud->AddToViewport();
	//UpdateScore();
	
	//GameHud->PointsCount->SetText(FText::AsNumber(0));
}
void AArkanoidUE5GameModeBase::UpdateScore()
{
	TotalPoints++;
	GameHud->UpdateScore(TotalPoints);
}