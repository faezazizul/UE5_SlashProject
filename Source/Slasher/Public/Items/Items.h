// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items.generated.h"

UCLASS()
class SLASHER_API AItems : public AActor
{
	GENERATED_BODY()
	
public:	
	AItems();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float Amplitude = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float TimeConstant = 10.f;

	UFUNCTION(BlueprintPure)
	float TransformedSin();

	UFUNCTION(BlueprintPure)
	float TransformedCos();
	
	template<typename T>
	T Avg(T First, T Second);

private:
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly,meta = (AllowPrivateAccess = "true"))
	float RunningTime;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;

};

template<typename T>
inline T AItems::Avg(T First, T Second)
{
	return T(First + Second)/ 2;
}
