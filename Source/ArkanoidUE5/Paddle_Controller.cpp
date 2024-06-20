// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle_Controller.h"

#include "Paddle.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "utils/Logs.h"
#include "Paddle.h"
#include "Ball.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>
#include "GameFramework/GameUserSettings.h"
#include "MainGameInstance.h"
//#include "GameSettings.h"

APaddle_Controller::APaddle_Controller()
{
}
void APaddle_Controller::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> CameraActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);
	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}

	///FString s = "start game";
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *s);
	//print("start");
	SpawnNewBall();
	Launch();
}

void APaddle_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent)) {

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APaddle_Controller::MoveHorizontal);
		EnhancedInputComponent->BindAction(LunchAction, ETriggerEvent::Triggered, this, &APaddle_Controller::Launch);
		EnhancedInputComponent->BindAction(QuitAction, ETriggerEvent::Triggered, this, &APaddle_Controller::QuitApp);
		EnhancedInputComponent->BindAction(SaveAction, ETriggerEvent::Triggered, this, &APaddle_Controller::SaveApp);
		EnhancedInputComponent->BindAction(ChangeAction, ETriggerEvent::Triggered, this, &APaddle_Controller::ChangeApp);
	}

}
void APaddle_Controller::QuitApp()
{
	UWorld* World = GetWorld();

	if (World)
	{
		//UKismetSystemLibrary::ExecuteConsoleCommand(World, TEXT("quit"));
		UGameplayStatics::OpenLevel(World, TEXT("MainMenu"));
	}
}
void APaddle_Controller::SaveApp()
{
	print("save");

	UMainGameInstance* GameInstance = Cast<UMainGameInstance>(GetGameInstance());
	if (GameInstance)
	{
		GameInstance->SaveGame();
	}	

}
void APaddle_Controller::MoveHorizontal(const FInputActionValue& Value)
{
	APaddle* MyPawn = Cast<APaddle>(GetPawn());

	if (MyPawn)
	{
		FVector2D MovementVector = Value.Get<FVector2D>();
		MyPawn->MoveHorizontal(MovementVector.X);
	}
}

void APaddle_Controller::Launch()
{
	FString s = "lunch";
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *s);
	///print("lunch");
	MyBall->Launch();

	
}

void APaddle_Controller::ChangeApp()
{
	print("change");

	UGameUserSettings* GameSettings = GEngine->GetGameUserSettings();

	if (GameSettings)
	{

		if (bIsEpic)
		{
			GameSettings->SetOverallScalabilityLevel(2);

			GameSettings->ApplySettings(true);
			GameSettings->SaveSettings();
			bIsEpic = false;

		}
		else {
			GameSettings->SetOverallScalabilityLevel(3);

			GameSettings->ApplySettings(true);
			GameSettings->SaveSettings();
			bIsEpic = true;

			/*GameSettings->SetTextureQuality(3);
			GameSettings->SetShadowQuality(3);
			GameSettings->SetAntiAliasingQuality(3);
			GameSettings->SetScreenResolution(100);
			GameSettings->SetVisualEffectQuality(3);*/


		}




	}

}

void APaddle_Controller::SpawnNewBall()
{
	if (!MyBall)
		MyBall = nullptr;

	if (BallObj) {

		MyBall = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocation, SpawnRotation, SpawnInfo);

	}

}
