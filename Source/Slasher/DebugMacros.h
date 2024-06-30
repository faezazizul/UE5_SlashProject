#pragma once
#include "DrawDebugHelpers.h"

#define DRAW_SPHERE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 24, FColor::Red, true);
#define DRAW_LINE(StartLocation, EndLocation) if(GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f);
#define DRAW_POINT(EndLocation) if (GetWorld()) DrawDebugPoint(GetWorld(), EndLocation, 25.f, FColor::Red, true);
#define DRAW_VECTOR(StartLocation, EndLocation) if (GetWorld())\
DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f);\
DrawDebugPoint(GetWorld(), EndLocation, 25.f, FColor::Red, true);\
