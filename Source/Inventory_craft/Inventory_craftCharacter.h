// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DataTableEditor/Private/SRowEditor.h"
#include "Engine/DataTable.h"
#include "Inventory_craftCharacter.generated.h"



USTRUCT(BlueprintType)
struct FCraftingInfo : public FTableRowBase
{
	GENERATED_BODY()

public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ComponentID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ProductID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool DestroyItemA;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool DestroyItemB;
	
	
};








USTRUCT(BlueprintType)
struct FInventoryItem : public FTableRowBase
{
	GENERATED_BODY()
	
public:

	FInventoryItem()
	{
		Name = FText::FromString("Item");
		Action = FText::FromString("User");
		Description = FText::FromString("Please enter a description for the item");
		Value = 10;
		
	}




	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	  FName ItemID;
	
	 UPROPERTY(EditAnywhere, BlueprintReadWrite)
	  TSubclassOf<class APickup>  ItemPickup;
	
	 UPROPERTY(EditAnywhere, BlueprintReadWrite)
	  FText Name;
	
	 UPROPERTY(EditAnywhere, BlueprintReadWrite)
	  FText Action;
	
	 UPROPERTY(EditAnywhere, BlueprintReadWrite)
	  int32 Value;
	
	 UPROPERTY(EditAnywhere, BlueprintReadWrite)
	  UTexture2D* Thumbnail;
	
	 UPROPERTY(EditAnywhere, BlueprintReadWrite)
	  FText Description;
	
	 UPROPERTY(EditAnywhere, BlueprintReadWrite)
	 TArray<FCraftingInfo> CraftCombinations;
	 
	
	 UPROPERTY(EditAnywhere, BlueprintReadWrite)
	  bool bCanBeUSed;
	

	bool operator ==(const FInventoryItem& Item) const
	{
		if (ItemID == Item.ItemID)
			return true;
		else return false;
	}
	
	
};

UCLASS(config=Game)
class AInventory_craftCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AInventory_craftCharacter();
	virtual  void Tick(float DeltaTime)override;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

protected:

	void CheckforInteractables();
	
	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

