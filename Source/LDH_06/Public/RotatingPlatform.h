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
	
	void SetRotateSpeed(float NewRotateSpeed);
	void InitRandomVal();
	
protected:
	// 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Rotating Platform|Components")
	USceneComponent* RootScene;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotating Platform|Components")
	UStaticMeshComponent* StaticMeshComponent;

	// 플랫폼 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotating Platform|Components")
	float RotateSpeed;
	
	// 타이머 관련
	FTimerHandle VisibleTimer;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotating Platform|Components")
	float LoopTime;
	
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
private:
	void ToggleVisible();
};
