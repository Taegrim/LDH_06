#include "RotatingPlatform.h"

ARotatingPlatform::ARotatingPlatform()
{
	RootScene = CreateDefaultSubobject<USceneComponent>("RootScene");
	SetRootComponent(RootScene);
	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(RootScene);
	
	PrimaryActorTick.bCanEverTick = true;
	
	RotateSpeed = 90.f;
	LoopTime = 3.f;
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

	AddActorLocalRotation(FRotator(0, RotateSpeed * DeltaTime, 0));
}

void ARotatingPlatform::ToggleVisible()
{
	bool bIsVisible = StaticMeshComponent->IsVisible();
	StaticMeshComponent->SetVisibility(!bIsVisible);
}

