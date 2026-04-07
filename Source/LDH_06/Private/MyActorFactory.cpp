#include "MyActorFactory.h"
#include "RotatingPlatform.h"
#include "Obstacle.h"
#include "Components/BoxComponent.h"

AMyActorFactory::AMyActorFactory()
{
	RootScene = CreateDefaultSubobject<USceneComponent>("RootScene");
	SetRootComponent(RootScene);
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawn Extent"));
	BoxComponent->SetupAttachment(RootScene);
	
	PrimaryActorTick.bCanEverTick = true;
	
	BoxComponent->SetBoxExtent(FVector(500.f, 500.f, 500.f));
}

void AMyActorFactory::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}
	
	// 박스 컴포넌트를 이용해 스폰 위치 범위 구하기
	FVector Origin = BoxComponent->GetComponentLocation();
	FVector Extent = BoxComponent->GetScaledBoxExtent();
	FBox SpawnBox(Origin - Extent, Origin + Extent);
	
	if (PlatformClass)
	{
		for (int32 i = 0; i < PlatformCount; ++i)
		{
			// 랜덤 위치
			FVector SpawnLocation = FMath::RandPointInBox(SpawnBox);
			FTransform SpawnTransform(FRotator::ZeroRotator, SpawnLocation);
			
			// BeginPlay에서 타이머 세팅하므로 지연 생성
			auto Platform = World->SpawnActorDeferred<ARotatingPlatform>(PlatformClass, SpawnTransform);
		
			if (Platform)
			{
				Platform->InitRandomVal();
				Platform->FinishSpawning(SpawnTransform);	
			}	
		}
	}
	
	if (ObstacleClass)
	{
		for (int32 i = 0; i < ObstacleCount; ++i)
		{
			// 랜덤 위치
			FVector SpawnLocation = FMath::RandPointInBox(SpawnBox);
			auto Obstacle = World->SpawnActor<AObstacle>(ObstacleClass, SpawnLocation, FRotator::ZeroRotator);
		
			if (Obstacle)
			{
				Obstacle->InitRandomVal();
			}
		}
	}
}

