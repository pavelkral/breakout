// Fill out your copyright notice in the Description page of Project Settings.


#include "Logs.h"
DEFINE_LOG_CATEGORY(MDebugLog);

void Logs::printOnScreen(const FString& DebugMessage)
{
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, DebugMessage, false);
}

void Logs::Log(const FString& DebugMessage)
{
	UE_LOG(MDebugLog, Warning, TEXT("%s"), *DebugMessage);
}
