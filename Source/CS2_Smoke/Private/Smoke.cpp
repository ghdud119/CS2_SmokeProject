// Fill out your copyright notice in the Description page of Project Settings.


#include "Smoke.h"

#include "SmokeVoxel.h"

// Sets default values
ASmoke::ASmoke()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ASmoke::SixWayTrace(const AActor* Actor, int Depth)
{
	if(!Actor)
	{
		UE_LOG(LogTemp, Error, TEXT("%s : Actor is InVaild"), *AActor::StaticClass()->GetName());
	}

	// 액터의 위치
	FVector ActorLocation = Actor->GetActorLocation();

	// 액터의 방향
	FVector ActorForward = Actor->GetActorForwardVector();
	FVector ActorRight = Actor->GetActorRightVector();
	FVector ActorUp = Actor->GetActorUpVector();

	SpawnVoxel(ActorLocation, ActorForward, Depth);	//전방
	SpawnVoxel(ActorLocation, ActorForward * -1, Depth);	//후방
	SpawnVoxel(ActorLocation, ActorRight, Depth);	//우측
	SpawnVoxel(ActorLocation, ActorRight * -1, Depth);	//좌측
	SpawnVoxel(ActorLocation, ActorUp, Depth);	//위
	SpawnVoxel(ActorLocation, ActorUp * -1, Depth);	//아래
}

// Called when the game starts or when spawned
void ASmoke::BeginPlay()
{
	Super::BeginPlay();
	SixWayTrace(this,0);
}

void ASmoke::SpawnVoxel(FVector Start, FVector Direction, int Depth)
{
	if(Depth < Radius)
	{
		FVector End = Start + VoxelSize * Direction;
		FHitResult HitResult;
		UWorld* World = GetWorld();
		if(World)
		{
			if(!World->LineTraceSingleByChannel(HitResult, Start, End, SmokeCollisionChannel))
			{
				AActor* voxel = World->SpawnActor<AActor>(VoxelClass, End, FRotator(0.f, 0.f, 0.f));
				if(voxel)
				{
					Voxels.Push(voxel);
					SixWayTrace(voxel, ++Depth);
				}
				else
				{
					UE_LOG(LogTemp, Error, TEXT("%s class Spawn Faild"), *voxel->GetName());
				}
			}
			else
			{
				//UE_LOG(LogTemp, Error, TEXT("HitResult : %s"), *HitResult.GetActor()->GetName());
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("World Invalid"));
		}
	}
}

// Called every frame
void ASmoke::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



