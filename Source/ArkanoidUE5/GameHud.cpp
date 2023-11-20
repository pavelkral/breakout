// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHud.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "ArkanoidUE5GameModeBase.h"
#include "utils/Logs.h"

void UGameHud::NativeConstruct()
{
	
}

void UGameHud::setup()
{
	UWorld* World = GetWorld();

	if (World)
	{
		AGameModeBase* GameMode = World->GetAuthGameMode();

		if (GameMode)
		{
			AArkanoidUE5GameModeBase* mode = Cast<AArkanoidUE5GameModeBase>(GameMode);
			//mode->UpdateScore();
			//mode->OnScoreChanged.AddDynamic(this, &UGameHud::UpdateScore);
			FString s = "delegate";
			Logs::printOnScreen(s);
			UE_LOG(LogTemp, Warning, TEXT("%s"), *s);
			//UGameplayStatics::SpawnEmitterAtLocation(World, DeathParticleSystem, Location);
			//UGameplayStatics::PlaySoundAtLocation(GetWorld(), OverlapSound, GetActorLocation());

		}
	}
	LivesCount->SetText(FText::AsNumber(3));
	TimerText->SetText(FText::AsNumber(60));
}

void UGameHud::UpdateScore(const int32 score)
{
	PointsCount->SetText(FText::AsNumber(score));
}
