// Fill out your copyright notice in the Description page of Project Settings.

#include "Brick.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Ball.h"
#include "utils/Logs.h"
#include "ArkanoidUE5GameModeBase.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Box_Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	Box_Collision->SetBoxExtent(FVector(25.0f, 10.0f, 10.0f));
	RootComponent = SM_Brick;
	Box_Collision->SetupAttachment(SM_Brick);
}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	Box_Collision->OnComponentBeginOverlap.AddDynamic(this, &ABrick::OnOverlapBegin);
}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABrick::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndexType, bool bFromSweep,
	const FHitResult& SweepResult)
{

	if (OtherActor->ActorHasTag("Ball")) {

		ABall* MyBall = Cast<ABall>(OtherActor);
		const FVector Location = GetActorLocation();
		FVector BallVelocity = MyBall->GetVelocity();
		BallVelocity *= (SpeedModifierOnBounce - 1.0f);
		MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);
		UWorld* World = GetWorld();

		if (World)
		{
			AGameModeBase* GameMode = World->GetAuthGameMode();
			if (GameMode)
			{
				AArkanoidUE5GameModeBase * mode = Cast<AArkanoidUE5GameModeBase>(GameMode);
				mode->UpdateScore();
				UGameplayStatics::SpawnEmitterAtLocation(World, DeathParticleSystem, Location);
				UGameplayStatics::PlaySoundAtLocation(GetWorld(), OverlapSound, GetActorLocation());

			}
		}
		FString s = "cplision";
		//Logs::printOnScreen(*BallVelocity.ToString());
		//Logs::printOnScreen(s);
		FTimerHandle UnusedHandle;
		float timeTudestroy = 0.5f;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABrick::DestroyBrick, timeTudestroy, false);


	}

}

void ABrick::DestroyBrick()
{
	this->Destroy();
}

