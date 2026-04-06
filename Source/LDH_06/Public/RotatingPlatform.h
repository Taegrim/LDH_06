#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class LDH_06_API ARotatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingPlatform();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rotating Platform|Components")
	USceneComponent* RootScene;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotating Platform|Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotating Platform|Components")
	float RotateSpeed;
	
	FTimerHandle VisibleTimer;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotating Platform|Components")
	float LoopTime;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
private:
	void ToggleVisible();
};
