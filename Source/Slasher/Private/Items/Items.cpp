// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Items.h"
#include "Slasher/DebugMacros.h"
#include "Slasher/Slasher.h"

AItems::AItems()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;

}

void AItems::BeginPlay()
{
	Super::BeginPlay();
	

	//DRAW_SPHERE(Location); //semicolon not needed - used only for indentation
	//DRAW_LINE(Location, Location + Forward * 100.f);
	//DRAW_POINT(Location + Forward * 100.f);
	//DRAW_VECTOR(Location, EndLocation);

}

float AItems::TransformedSin()
{

	return Amplitude * FMath::Sin(RunningTime * TimeConstant); //period = 2pi/K
}

float AItems::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);;
}

void AItems::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	float MovementRate = 50.f;
	float RotationRate = 45.f;
	RunningTime += DeltaTime;
	
	//float DeltaZ = Amplitude * FMath::Sin(Value * TimeConstant);

	FVector StartLocation = GetActorLocation();
	FVector EndLocation = StartLocation + GetActorForwardVector() * 100.f;

	//AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, DeltaZ));
	AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));
	DRAW_SPHERE_SingleFrame(StartLocation);
	DRAW_VECTOR_SingleFrame(StartLocation, EndLocation);

	FVector AvgVector = Avg<FVector>(GetActorLocation(), FVector::ZeroVector);
	DRAW_POINT_SingleFrame(AvgVector);
	
}

