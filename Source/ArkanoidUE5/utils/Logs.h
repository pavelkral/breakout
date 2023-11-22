// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
template <typename ObjClass>
static FORCEINLINE ObjClass* LoadAssetFromPath(const FName& Path)
{
	if (Path == NAME_None) return NULL;
	if (Path.ToString().Contains("None")) return NULL;
	return Cast<ObjClass>(StaticLoadObject(ObjClass::StaticClass(), NULL, *Path.ToString()));
}


class ARKANOIDUE5_API Logs
{
public:
	Logs();
	~Logs();
	static void printOnScreen(const FString& DebugMessage);
	static void Log(const FString& DebugMessage);
};

#define print(Text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::White, TEXT(Text), false) 
#define print_k(Key, Text) if (GEngine) GEngine->AddOnScreenDebugMessage(Key, 2.f, FColor::White, TEXT(Text)) 

#define printf(Format, ...) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::White, FString::Printf(TEXT(Format), ##__VA_ARGS__ ), false)
#define printf_k(Key, Format, ...) if (GEngine) GEngine->AddOnScreenDebugMessage(Key, 2.f, FColor::White, FString::Printf(TEXT(Format), ##__VA_ARGS__ ))

#define warn(Text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT(Text), false) 
#define warn_k(Key, Text) if (GEngine) GEngine->AddOnScreenDebugMessage(Key, 2.f, FColor::Yellow, TEXT(Text)) 
//#define warnf Format ... if (GEngine) GEngine- ddOnScreenDebugMessagei -1 2.f FColor::Yellow FStrin ::Printf TEXT(Format), ##__VA_ARGS__ ) ,false)
#define warnf_k(Key, Format, ...) if (GEngine) GEngine->AddOnScreenDebugMessage(Key, 2.f, FColor::Yellow, FString::Printf(TEXT(Format), ##__VA_ARGS__))  

#define printc(Text, Color) if (GEngine) GEngine->AddOnScreenDebugMessage( -1, 2.f, Color, TEXT(Text), false) 