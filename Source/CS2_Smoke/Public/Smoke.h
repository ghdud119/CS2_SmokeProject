// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Smoke.generated.h"

UCLASS()
class CS2_SMOKE_API ASmoke : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASmoke();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SixWayTrace(const AActor* Actor, int Depth);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Smoke|Voxel")
	TSubclassOf<AActor> VoxelClass;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Smoke|Voxel")
	float VoxelSize;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Smoke|Voxel")
	int Radius;

	UPROPERTY(EditAnywhere, Category = "Smoke|Collision")
	TEnumAsByte<ECollisionChannel> SmokeCollisionChannel;
	
	TArray<TObjectPtr<AActor>> Voxels;
private:
	void SpawnVoxel(FVector Start, FVector Direction, int Depth);


};
