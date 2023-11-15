// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class ARKANOIDUE5_API Logs
{
public:
	Logs();
	~Logs();
	static void printOnScreen(const FString& DebugMessage);
};