#include "RotatingPlatform.h"

ARotatingPlatform::ARotatingPlatform()
{
	RootScene = CreateDefaultSubobject<USceneComponent>("RootScene");
	SetRootComponent(RootScene);
	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(RootScene);
	
	PrimaryActorTick.bCanEverTick = true;
	
	LoopTime = 3.f;
}

void ARotatingPlatform::SetRotateSpeed(float NewRotateSpeed)
{
	RotateSpeed = NewRotateSpeed;
}

void ARotatingPlatform::InitRandomVal()
{
	RotateSpeed = FMath::RandRange(0.f, 90.f);
	LoopTime = FMath::RandRange(2.f, 4.f);
}

void ARotatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(VisibleTimer,
		this, &ARotatingPlatform::ToggleVisible, LoopTime, true);
}

void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotateSpeed))
	{
		AddActorLocalRotation(FRotator(0, RotateSpeed * DeltaTime, 0));	
	}
}

void ARotatingPlatform::ToggleVisible()
{
	bool bIsVisible = StaticMeshComponent->IsVisible();
	StaticMeshComponent->SetVisibility(!bIsVisible);
}

