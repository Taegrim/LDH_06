#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActorFactory.generated.h"

class ARotatingPlatform;
class AObstacle;
class UBoxComponent;

UCLASS()
class LDH_06_API AMyActorFactory : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyActorFactory();

protected:
	// 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyActorFactory|Components")
	USceneComponent* RootScene;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MyActorFactory|Components")
	UBoxComponent* BoxComponent;
	
	// 생성할 클래스
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MyActorFactory|Components")
	TSubclassOf<ARotatingPlatform> PlatformClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MyActorFactory|Components")
	TSubclassOf<AObstacle> ObstacleClass;
	
	// 개수, 범위
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "MyActorFactory|Components")
	int32 PlatformCount;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "MyActorFactory|Components")
	int32 ObstacleCount;
	
	
	virtual void BeginPlay() override;
};
