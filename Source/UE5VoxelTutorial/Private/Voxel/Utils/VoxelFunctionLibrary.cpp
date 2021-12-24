// Fill out your copyright notice in the Description page of Project Settings.


#include "Voxel/Utils/VoxelFunctionLibrary.h"

FIntVector UVoxelFunctionLibrary::WorldToLocalBlockPosition(const FVector& Position, const int Size)
{	

	
	return FIntVector(Position) / 100 - WorldToChunkPosition(Position, Size);
}

FIntVector UVoxelFunctionLibrary::WorldToChunkPosition(const FVector& Position, const int Size)
{
	FIntVector Result;

	const int Factor = Size * 100;
	const auto IntPosition = FIntVector(Position);

	if (IntPosition.X < 0) {
		if (IntPosition.X % Factor == 0) {
			Result.X = (int)(Position.X / Factor);
		} else {
			Result.X = (int)(Position.X / Factor) - 1;
		}
	} else Result.X = (int)(Position.X / Factor);

	if (IntPosition.Y < 0) {
		if (IntPosition.Y % Factor == 0) {
			Result.Y = (int)(Position.Y / Factor);
		} else {
			Result.Y = (int)(Position.Y / Factor) - 1;
		}
	} else Result.Y = (int)(Position.Y / Factor);

	if (IntPosition.Z < 0) {
		if (IntPosition.Z % Factor == 0) {
			Result.Z = (int)(Position.Z / Factor);
		} else {
			Result.Z = (int)(Position.Z / Factor) - 1;
		}
	} else Result.Z = (int)(Position.Z / Factor);
	
	return Result;
}
