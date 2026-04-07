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

void AObstacle::SetStartLocation(FVector NewStartLocation)
{
	StartLocation = NewStartLocation;
}

void AObstacle::SetMoveSpeed(FVector NewMoveSpeed)
{
	MoveSpeed = NewMoveSpeed;	
}

void AObstacle::SetMaxRange(float NewMaxRange)
{
	MaxRange = NewMaxRange;
}

void AObstacle::InitRandomVal()
{
	// 속도
	FVector Speed(FMath::RandRange(-100.f, 100.f), FMath::RandRange(-100.f, 100.f),
		FMath::RandRange(-100.f, 100.f));
	MoveSpeed = Speed;
		
	// 범위
	float Range = FMath::RandRange(500.f, 1000.f);
	MaxRange = Range;
	
	StartLocation = GetActorLocation();
}

void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!FMath::IsNearlyZero(MaxRange))
	{
		Time += DeltaTime;
		float Frequency = PI * MoveSpeed.Size() / MaxRange;	// 주기 = PI * 속도 / 최대 범위
		float Alpha = (1.f - FMath::Cos(Time * Frequency)) * 0.5f;	// 0~1 정규화
		FVector NewLocation = StartLocation + (Alpha * MaxRange * MoveSpeed.GetSafeNormal());
	
		SetActorLocation(NewLocation);
	}
}

