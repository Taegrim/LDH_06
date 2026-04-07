#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class LDH_06_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	AObstacle();
	
	void SetStartLocation(FVector NewStartLocation);
	void SetMoveSpeed(FVector NewMoveSpeed);
	void SetMaxRange(float NewMaxRange);
	
	void InitRandomVal();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Obstacle|Components")
	USceneComponent* RootScene;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstacle|Components")
	UStaticMeshComponent* StaticMeshComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstacle|Components")
	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstacle|Components")
	FVector MoveSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Obstacle|Components")
	float MaxRange;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	FVector Velocity;
	float Time;
};
