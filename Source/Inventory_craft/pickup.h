// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Interactable.h"
#include "pickup.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_CRAFT_API APickup : public AInteractable
{

	GENERATED_BODY()

 public: 

	APickup();

 protected:

	UPROPERTY(EditAnywhere)
    UStaticMeshComponent* PickupMesh;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FName ItemID;

};
