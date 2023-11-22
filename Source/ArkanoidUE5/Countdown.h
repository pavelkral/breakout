// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Components/TextRenderComponent.h>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Countdown.generated.h"


UCLASS()
class ARKANOIDUE5_API ACountdown : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACountdown();

	/// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/// (disabled) Called every frame
	virtual void Tick(float DeltaSeconds) override;

	/// Called when count get to zero
	UFUNCTION(BlueprintNativeEvent)
	void CountdownHasFinished();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Assets")
	UTextRenderComponent* CountdownText = nullptr;

private:
	/// How long, in seconds, the countdown will run
	UPROPERTY(EditAnywhere)
	int32 CountdownTime = 60;

	/// C++ default implementation (if no implementation given by Blueprint) Can be called from Blueprint using "Parent: CountdownHasFinished"
	virtual void CountdownHasFinished_Implementation();

	FTimerHandle CountdownTimerHandle;

	void UpdateTimerDisplay();

	void AdvanceTimer();
};