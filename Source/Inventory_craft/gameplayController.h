// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "gameplayController.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_CRAFT_API AgameplayController : public APlayerController
{
	GENERATED_BODY()


public:
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere)
	class AInteractable* CurrentInteractable;
	
	
};
