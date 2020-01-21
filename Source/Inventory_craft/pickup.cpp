// Fill out your copyright notice in the Description page of Project Settings.

#include "pickup.h"
#include "Inventory_craft.h"

APickup::APickup()
{

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");
	 

	ItemID = FName("Please enter an ID");
}