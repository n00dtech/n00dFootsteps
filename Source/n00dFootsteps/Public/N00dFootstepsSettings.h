// Copyright (c) Developed by Josh (db) Debelec - Published by n00dbeaver Studios 2022 - All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"

#include "N00dFootstepsSettings.generated.h"

/**
 * Settings object used to hold both config settings and editable ones in one place
 * To ensure the settings are saved to the specified config file make sure to add
 * props using the globalconfig or config meta.
 */

UCLASS(config = Game, defaultconfig) // specify the name of the config file to use
class N00DFOOTSTEPS_API UN00dFootstepsSettings : public UObject
{

	GENERATED_BODY()

public:

		UN00dFootstepsSettings(const FObjectInitializer& ObjectInitializer);

	/////////////////////////////////////////////// PROPERTIES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


	///////////////////////////////
	//	DEBUG
	///////////////////////////////

	// Enabling this will print and activate any various debugging info relevant to n00dFootsteps
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Debug)
		bool DebugFootsteps;
	// Don't use this component for any reason in particular 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Debug)
		bool DisableFootsteps;
	// Only works if the component is in debug mode 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Debug)
		bool PrintActiveFootstepSounds;
	// Let us know if there are any decals missing for the current surface 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Debug)
		bool PrintNullFootstepDecals;

	///////////////////////////////
	//	CONFIG
	///////////////////////////////


	// Surfaces and their relevant effects 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Data, meta = (RequiredAssetDataTags = "RowStructure=FN00dFootstepsEffectMap"))
		TSoftObjectPtr<class UDataTable> FootstepSurfaces;
	// The MasterCUE is where the system sets parameters such as Foley, but you can use your own instead if desired.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
		class USoundCue* MasterSound;
	// User defined speeds and their values 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Data)
		TMap<struct FGameplayTag, float> GlobalFootstepsVolume;
	// Default Footprint
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Data)
		FGameplayTag DefaultFootprint;
	// Default Speed
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Data)
		FGameplayTag DefaultSpeed;
	// Should we use the foley feature by default
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Data)
		bool ShouldFoley;
	// The foley to use by default
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Data)
		FGameplayTag DefaultFoley;
	// For each tag we define (i.e. Armour), allocate foley for that definition 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Data)
		TMap<struct FGameplayTag, struct FN00dFootstepsWavesVolume> FoleySounds;



};
