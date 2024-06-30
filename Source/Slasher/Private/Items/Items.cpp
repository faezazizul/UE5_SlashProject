// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Items.h"
#include "Slasher/DebugMacros.h"
#include "Slasher/Slasher.h"

AItems::AItems()
{
 	
	PrimaryActorTick.bCanEverTick = true;

}

void AItems::BeginPlay()
{
	Super::BeginPlay();
	

	UWorld* World = GetWorld();
	FVector Location = GetActorLocation();
	FVector Forward = GetActorForwardVector();
	FVector EndLocation = Location + Forward * 100.f;
		
	DRAW_SPHERE(Location); //semicolon not needed - used only for indentation
	//DRAW_LINE(Location, Location + Forward * 100.f);
	//DRAW_POINT(Location + Forward * 100.f);
	DRAW_VECTOR(Location, EndLocation);

}

void AItems::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}

