// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ArkanoidUE5GameModeBase.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChanged, int32, TotalPoints);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLivesCountChanged, int32, LivesCount);

UCLASS()
class ARKANOIDUE5_API AArkanoidUE5GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	int32 TotalPoints = 0;

	UPROPERTY(VisibleAnywhere)
	int32 NumberOfLives = 0;

	UPROPERTY(EditAnywhere)
	int32 MaxLives = 3;

	UPROPERTY(EditAnywhere, Category = "Config")
	TSubclassOf<UUserWidget> GameHudClass;

	UPROPERTY(EditAnywhere, Category = "Config")
	TArray<AActor*> Bricks;

	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
	class UGameHud* GameHud;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegates")
	FOnScoreChanged OnScoreChanged;

	UFUNCTION()
	void UpdateScore();

	UFUNCTION()
	void RemoveBrick(AActor * brick);

protected:
	virtual void BeginPlay() override;
};
