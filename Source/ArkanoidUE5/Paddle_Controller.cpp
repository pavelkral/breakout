// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle_Controller.h"

#include "Paddle.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

#include "Paddle.h"
#include "Ball.h"
#include "Logger.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>

APaddle_Controller::APaddle_Controller()
{
}
void APaddle_Controller::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),ACameraActor::StaticClass(),CameraActors);
	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0],Params);

//	if (APlayerController* PlayerController = Cast<APlayerController>(GetController())
//	{
		//PlayerController1 = PlayerController;

		//PlayerController->SetInputMode(FInputModeGameOnly());

		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	//}
	FString s = "start";
	UE_LOG(LogTemp, Warning, TEXT("%s"), *s);
	print("start");
	SpawnNewBall();
	Launch();
}

void APaddle_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnableInput(this);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent)) {

		
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APaddle_Controller::MoveHorizontal);
		EnhancedInputComponent->BindAction(LunchAction, ETriggerEvent::Triggered, this, &APaddle_Controller::Launch);

	}

}
void APaddle_Controller::MoveHorizontal(const FInputActionValue& Value)
{
	auto MyPawn =Cast<APaddle>(GetPawn());
	if (MyPawn)
	{
		FVector2D MovementVector = Value.Get<FVector2D>();
		MyPawn->MoveHorizontal(MovementVector.X);
	}
}

void APaddle_Controller::Launch()
{
	FString s = "lunch";
	UE_LOG(LogTemp, Warning, TEXT("%s"), *s);
	print("lunch");
	MyBall->Launch();
}

void APaddle_Controller::SpawnNewBall()
{
	if (!MyBall)
		MyBall = nullptr;

	if (BallObj) {

		MyBall = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocation, SpawnRotation, SpawnInfo);

	}

}
