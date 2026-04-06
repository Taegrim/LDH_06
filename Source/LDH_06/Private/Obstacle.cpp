#include "Obstacle.h"

#include "VectorTypes.h"

AObstacle::AObstacle()
{
	RootScene = CreateDefaultSubobject<USceneComponent>("RootScene");
	SetRootComponent(RootScene);
	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(RootScene);
	
	PrimaryActorTick.bCanEverTick = true;
	
	Velocity = MoveSpeed;
	MaxRange = 1000.f;
	Time = 0.f;
}

void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	Time += DeltaTime;
	float Frequency = PI * MoveSpeed.Size() / MaxRange;	// 주기 = PI * 속도 / 최대 범위
	float Alpha = (1.f - FMath::Cos(Time * Frequency)) * 0.5f;	// 0~1 정규화
	FVector NewLocation = StartLocation + (Alpha * MaxRange * MoveSpeed.GetSafeNormal());
	
	SetActorLocation(NewLocation);
}

