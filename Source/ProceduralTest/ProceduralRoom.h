// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralRoom.generated.h"

UCLASS()
class PROCEDURALTEST_API AProceduralRoom : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProceduralRoom();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Floor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Room", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor>StairsClass;

	void SpawnItem(UClass* ItemToSpawn);
	
	void CreateGrid();

		float SquareWidth;
		float GridHeight;
		float RoomLenght;
		float RoomWidth;

		FVector TopLeft;
		FVector ButtomRight;
		int32 GridSizeX;
		int32 GridSizeY;

	FVector GetRandomPointInSquare(const FVector& UpperLeft, const FVector& LowerRight);

	void PlacePointOnGrid();

	float Radius;
};
