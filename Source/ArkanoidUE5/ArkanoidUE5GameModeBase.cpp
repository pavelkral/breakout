// Copyright Epic Games, Inc. All Rights Reserved.


#include "ArkanoidUE5GameModeBase.h"


#include "GameHud.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/ArrowComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Brick.h"
#include "utils/Logs.h"

void AArkanoidUE5GameModeBase::BeginPlay()

{

	GameHud = Cast<UGameHud>(CreateWidget(GetWorld(), GameHudClass));
	check(GameHud);

	GameHud->setup();
	GameHud->AddToViewport();

	OnScoreChanged.AddDynamic(GameHud, &UGameHud::UpdateScore);


	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABrick::StaticClass(), Bricks);
	
	for (auto Child : Bricks)
	{
		if (IsValid(Child))
		{
			//Child->Destroy();
			UE_LOG(LogTemp, Warning, TEXT("%s"), *Child->GetName());
		}
	}
	//UpdateScore();
	
	//GameHud->PointsCount->SetText(FText::AsNumber(0));
}
void AArkanoidUE5GameModeBase::UpdateScore()
{
	TotalPoints++;
	//GameHud->UpdateScore(TotalPoints);
	OnScoreChanged.Broadcast(TotalPoints);
}
void AArkanoidUE5GameModeBase::UpdateFps(int32 fps)
{
	GameHud->UpdateFps(fps);
}
void AArkanoidUE5GameModeBase::RemoveBrick(AActor* brick)
{
	Bricks.Remove(brick);
}
