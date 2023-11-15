// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle_Controller.h"

#include "Paddle.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

#include "Paddle.h"
#include "Ball.h"
#include "Logger.h"

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
	InputComponent->BindAxis("MoveHorizontal",this,&APaddle_Controller::MoveHorizontal);
	InputComponent->BindAction("Launch", IE_Pressed, this, &APaddle_Controller::Launch);
}
void APaddle_Controller::MoveHorizontal(float AxisValue)
{
	auto MyPawn =Cast<APaddle>(GetPawn());
	if (MyPawn)
	{
		MyPawn->MoveHorizontal(AxisValue);
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
