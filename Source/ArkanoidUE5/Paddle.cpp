// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"
#include  "Components/StaticMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include <EnhancedInputSubsystems.h>
#include <EnhancedInputComponent.h>
#include "utils/Logs.h"
// Sets default values
APaddle::APaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PaddleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_paddle"));
	RootComponent = PaddleMesh;
	PaddleMesh->SetEnableGravity(false);
//	PaddleMesh->SetConstraintMode(EDOFMode::XZPlane);
	PaddleMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	PaddleMesh->SetCollisionProfileName(TEXT("PhysicsActor"));
	
	FloatingMovment = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingMovement"));
	//FloatingMovment->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Display, TEXT("Your 8message"));	
	print("start");
	//print_k(1,"ok");
}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APaddle::MoveHorizontal(float AxisValue)
{
	AddMovementInput(FVector(AxisValue,0.0f,0.0f),1.0f,false);
}

