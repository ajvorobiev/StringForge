class ItemCore;
class InventoryMuzzleItem_Base_F;
class InventoryFlashLightItem_Base_F;
class optic_LRPS;
class optic_Holosight;
class optic_Hamr;
class acc_pointer_IR;
class muzzle_snds_H;

///bipurds
class rhsusf_acc_harris_bipod : acc_pointer_IR
{
	Author_Macro
	scope=2;
	//model = "\A3\Weapons_F\Acc\accu_bipod_01_blk_F.p3d";
	model = "\rhsusf\addons\rhsusf_weapons\acc\bipods\harris\harris";
	picture = "\rhsusf\addons\rhsusf_weapons\gear_acc\rhs_harrisBipod_icon_ca.paa";

	displayName = "Harris Bipod";
	descriptionShort = "Standard US-Army Harris Bipod.";

	class ItemInfo
	{
		scope = 0;
		deployedPivot = "bipod";
		hasBipod = 1;
		mass = 10;
		type = 302;
	};
	inertia = 0.2;
	type = 131072;
};

class rhs_acc_at4_handler : acc_pointer_IR
{
	Author_Macro
	scope=2;

	model = "\A3\Weapons_f\empty";
	//picture = "";
	picture = "\A3\Weapons_F\Data\clear_empty.paa"; //- turned off for now

	displayName = AT-4 Peep hole handler;
	descriptionUse = "Use optics mode key (/ on numpad) to change mode";
	descriptionShort = "Use optics mode key (/ on numpad) to change mode";

	class ItemInfo: InventoryFlashLightItem_Base_F
	{
		mass = 0;
		class Pointer {};
		class FlashLight {};
	};
	inertia = 0;
};

///! Lasers
class rhsusf_acc_anpeq15A : acc_pointer_IR
{
	Author_Macro
	displayName = $STR_RHSUSF_ACC_PEQ15A;
	scope=2;

	inertia = 0.1;
};

class rhsusf_acc_anpeq15 : acc_pointer_IR
{
	Author_Macro
	displayName = $STR_RHSUSF_ACC_PEQ15SURE_Laser;
	scope=2;
	weaponInfoType = "RHS_Flashlight";
	descriptionShort = "IR Laser. Press CTRL+C (next CM key) to change IR/Light mode";
	descriptionUse = "<t color='#9cf953'>Use: </t>press L Turn ON/OFF, CTRL+C (next CM key) to change IR/Light mode";

	model = "\rhsusf\addons\rhsusf_weapons\acc\lasers\ANPEQ15\PEQ15_A3_top";
	class ItemInfo: InventoryFlashLightItem_Base_F
		{
			RMBhint="IR Laser";
			mass = 8;
			class Pointer
			{
				irLaserPos = "laser pos";
				irLaserEnd = "laser dir";
				irDistance = 5;
			};
			class FlashLight{

			};
		};

	inertia = 0.2;
};

class rhsusf_acc_anpeq15_light : rhsusf_acc_anpeq15
{
	Author_Macro
	displayName = $STR_RHSUSF_ACC_PEQ15SURE_Light;
	descriptionShort = "Weapon mounted light. Press CTRL+C (next CM key) to change IR/Light mode";
	class ItemInfo: ItemInfo
	{
			RMBhint="Flashlight";
			mass = 8;
			class Pointer
			{
			};
			class FlashLight{

				color[]={25,22,20};
				ambient[]={0.001,0.001,0.001};
				position="flash dir";
				direction="flash";
				size=1;
				innerAngle=50;
				outerAngle=120;
				coneFadeCoef=10;
				intensity=330;
				useFlare=1;
				dayLight=1;
				FlareSize=0.7;
				onlyInNvg=0;
				class Attenuation
				{
					start=0;
					constant=2;
					linear=1;
					quadratic=75;
				};
				scale[]={0};
			};
	};
	inertia = 0.2;
};

class rhsusf_acc_anpeq15side : acc_pointer_IR
{
	Author_Macro
	displayName = $STR_RHSUSF_ACC_PEQ15;
	scope=2;
	model = "\rhsusf\addons\rhsusf_weapons\acc\lasers\ANPEQ15\PEQ15_A3_side";
	class ItemInfo: InventoryFlashLightItem_Base_F
		{
			mass = 8;
			class Pointer
			{
				irLaserPos = "laser pos";
				irLaserEnd = "laser dir";
				irDistance = 5;
			};
			class FlashLight{};
		};
	inertia = 0.1;
};

///! Muzzle accessories

class rhsusf_silencer_base : muzzle_snds_H
{
	scope = 0;
	displayName=$STR_RHSUSF_ACC_M2010S;

	picture="\rhsusf\addons\rhsusf_weapons\gear_acc\rhs_rotex5_grey_icon_ca.paa";
	model = "\rhsusf\addons\rhsusf_weapons\acc\silencers\M2010\M2010silencer";

	class ItemInfo: InventoryMuzzleItem_Base_F
	{
		mass=7;
		class MagazineCoef
		{
			initSpeed = 1;
		};

		class AmmoCoef
		{
			hit=0.8;
			visibleFire=0.2;
			audibleFire=0.4;
			visibleFireTime=0.5;
			audibleFireTime=1.0;
			cost = 1.0;
			typicalSpeed= 0.8;
			airFriction = 1.0;
		};
		class MuzzleCoef
		{
			dispersionCoef="0.8f";
			artilleryDispersionCoef="1.0f";
			fireLightCoef="0.1f";
			recoilCoef="1.0f";
			recoilProneCoef="1.0f";
			minRangeCoef="1.0f";
			minRangeProbabCoef="1.0f";
			midRangeCoef="1.0f";
			midRangeProbabCoef="1.0f";
			maxRangeCoef="1.0f";
			maxRangeProbabCoef="1.0f";
		};

		muzzleEnd = "zaslehPoint"; // memory point in muzzle supressor's model
		alternativeFire = "Zasleh2";  // class in cfgWeapons with model of muzzle flash

		soundTypeIndex = 1;
		inertia=0.2;
	};
};

class rhsusf_acc_M2010S : rhsusf_silencer_base
{
	Author_Macro
	scope = 2;
};
class rhsusf_acc_SR25S : rhsusf_silencer_base
{
	Author_Macro
	scope = 2;
	displayName="SR-25 Rifle Suppressor";
	picture="\rhsusf\addons\rhsusf_weapons\sr25\Data\gear\gear_sr25_suppressor_x_ca.paa";
	model = "\rhsusf\addons\rhsusf_weapons\sr25\sr25_suppressor";
};

class rhsusf_acc_rotex5_grey : rhsusf_silencer_base
{
	scope = 2;
	Author_Macro
	displayName=$STR_RHSUSF_ACC_Rotex5_grey;
	picture="\rhsusf\addons\rhsusf_weapons\gear_acc\rhs_rotex5_grey_icon_ca.paa";
	model = "\rhsusf\addons\rhsusf_weapons\acc\silencers\rotex5\rotex5_grey.p3d";
};

class rhsusf_acc_rotex5_tan : rhsusf_acc_rotex5_grey
{
	scope = 2;
	Author_Macro
	displayName=$STR_RHSUSF_ACC_Rotex5_tan;
	picture="\rhsusf\addons\rhsusf_weapons\gear_acc\rhs_rotex5_tan_icon_ca.paa";
	model = "\rhsusf\addons\rhsusf_weapons\acc\silencers\rotex5\rotex5_tan.p3d";
};

class rhsusf_acc_nt4_black : rhsusf_silencer_base
{
	scope = 2;
	Author_Macro
	displayName=$STR_RHSUSF_ACC_NT4_BLACK;
	picture="\rhsusf\addons\rhsusf_weapons\gear_acc\rhs_nt4_black_icon_ca.paa";
	model = "rhsusf\addons\rhsusf_weapons\acc\silencers\nt4\nt4_black.p3d";

	inertia = 0.1;
};


class rhsusf_acc_nt4_tan : rhsusf_acc_nt4_black
{
	scope = 2;
	Author_Macro
	displayName=$STR_RHSUSF_ACC_NT4_TAN;
	picture="\rhsusf\addons\rhsusf_weapons\gear_acc\rhs_nt4_tan_icon_ca.paa";
	model = "rhsusf\addons\rhsusf_weapons\acc\silencers\nt4\nt4_tan.p3d";
};

class rhsusf_acc_muzzleFlash_SF: ItemCore
{
	scope = 2;
	Author_Macro
	//path to custom flash, it's same muzzle flash p3d as used on zasleh proxy in ak74
	model = "a3\data_f\proxies\muzzle_flash\muzzle_flash_rifle_trg20.p3d";

	inertia = 0;
};

class rhsusf_m4muzzlebreak_base : rhsusf_silencer_base
{
	scope = 0;
	Author_Macro
	picture="\rhsusf\addons\rhsusf_weapons\gear_acc\rhs_m4muzzle_icon_ca.paa";

	inertia = 0;
};

class rhsusf_acc_SF3P556 : rhsusf_m4muzzlebreak_base
{
	scope = 2;

	displayName="$STR_RHSUSF_ACC_SF3P";
	Author_Macro
	model = "\rhsusf\addons\rhsusf_weapons\acc\silencers\surefirebrakes\SF3P556.p3d";

	class ItemInfo: ItemInfo
	{
		soundTypeIndex = 0;
		inertia=0.05;
		class AmmoCoef
		{
			hit=1;
			visibleFire=0.8;
			audibleFire=0.95;
			visibleFireTime=0.95;
			audibleFireTime=1.0;
			cost = 1.0;
			typicalSpeed= 1;
			airFriction = 1.0;
		};
		class MuzzleCoef
		{
			dispersionCoef="1.0f";
			artilleryDispersionCoef="1.0f";
			fireLightCoef="0.1f";
			recoilCoef="1.0f";
			recoilProneCoef="1.0f";
			minRangeCoef="1.0f";
			minRangeProbabCoef="1.0f";
			midRangeCoef="1.0f";
			midRangeProbabCoef="1.0f";
			maxRangeCoef="1.0f";
			maxRangeProbabCoef="1.0f";
		};
		alternativeFire = "rhsusf_acc_muzzleFlash_SF";  // out custom muzzle flash
	};
};

class rhsusf_acc_SFMB556 : rhsusf_acc_SF3P556
{
	displayName="$STR_RHSUSF_ACC_SFMB";
	Author_Macro
	model = "\rhsusf\addons\rhsusf_weapons\acc\silencers\surefirebrakes\SFMB556.p3d";
};

///! Scopes
class rhsusf_acc_sniper_base: ItemCore
{
	scope = 0;
	Author_Macro
	displayName = $STR_RHSUSF_ACC_LEUPOLDMK401;
	descriptionShort = $STR_RHSUSF_ACC_LEUPOLDMK4_SD;

	picture="\rhsusf\addons\rhsusf_weapons\gear_acc\rhs_leo_icon_ca.paa";
	model = "\rhsusf\addons\rhsusf_weapons\acc\scopes\leupoldmk4\leupoldmk4";

	weaponInfoType = "RscWeaponZeroing";
	class ItemInfo: InventoryOpticsItem_Base_F
	{
		opticType = 2;
		mass = 4;
		RMBhint = "Optical Sniper Sight";
		optics = 1;

		modelOptics = "\rhsusf\addons\rhsusf_weapons\acc\scopes\optics\rhsusf_leu_mildot";
		class OpticsModes
		{
			///! 3.5-10X MAGNIFICATION -> 0.2492/4
			class pso1_scope
			{
				opticsID = 2;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
 				discreteDistanceInitIndex = 1;
				opticsZoomMax = 0.35/3.5;
				opticsZoomMin = 0.35/10;
				opticsZoomInit = 0.35/3.5;
				discretefov[] = {0.35/3.5,0.35/10};
 				discreteInitIndex = 0;
 				modelOptics[] = {"\rhsusf\addons\rhsusf_weapons\acc\scopes\optics\rhsusf_leu_mildot3_5", "\rhsusf\addons\rhsusf_weapons\acc\scopes\optics\rhsusf_leu_mildot10"};
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				distanceZoomMin = 100;
				distanceZoomMax = 1000;
				cameraDir = "";
			};
		};
	};

	inertia = 0.2;
};

class rhsusf_acc_compm4 : ItemCore
{
	scope=2;
	Author_Macro
	displayName = "$STR_RHSUSF_ACC_M68";

	picture="\rhsusf\addons\rhsusf_weapons\gear_acc\acc_m68cco_ca.paa";
	model = "\rhsusf\addons\rhsusf_weapons\acc\scopes\compM4\compm4";

	descriptionShort = $STR_RHS_ACC_PKAS_SD;

	class ItemInfo: InventoryOpticsItem_Base_F
	{
		opticType = 1;
		mass = 4;
		RMBhint = "Optical Sight";
		optics = 1;

		modelOptics="\A3\Weapons_F\empty";
		class OpticsModes
		{
			class ACO
			{
				opticsID=1;
				useModelOptics=0;
				opticsZoomMin=0.375;
				opticsZoomMax=1.1;
				opticsZoomInit=0.75;
				memoryPointCamera="opticview";
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
				distanceZoomMin=100;
				distanceZoomMax=100;
				cameraDir="";
				visionMode[]={};
				opticsPPEffects[]=
				{
					"OpticsBlur1"
				};
			};
		};
	};

	inertia = 0.1;
};

class rhsusf_acc_eotech_552 : rhsusf_acc_compm4
{
	Author_Macro
	displayName = "$STR_RHSUSF_ACC_M552";

	picture="\rhsusf\addons\rhsusf_weapons\gear_acc\acc_m552cco_ca.paa";
	model = "\rhsusf\addons\rhsusf_weapons\acc\scopes\eotech\Eotech552";

	descriptionShort = $STR_RHS_ACC_PKAS_SD;

	inertia = 0;
};

class rhsusf_acc_LEUPOLDMK4 : rhsusf_acc_sniper_base
{
	scope=2;
};

class rhsusf_acc_ELCAN: rhsusf_acc_sniper_base
{
	scope = 2;
	Author_Macro
	displayName = "$STR_RHSUSF_ACC_M145";
	descriptionShort =  "$STR_RHSUSF_ACC_M145";

	picture="\rhsusf\addons\rhsusf_weapons\gear_acc\rhs_elcan_icon_ca.paa";
	model = "\rhsusf\addons\rhsusf_weapons\acc\scopes\elcan\elcan";

	weaponInfoType = "RscWeaponZeroing";
	class ItemInfo: InventoryOpticsItem_Base_F
	{
		opticType = 2;
		mass = 4;
		RMBhint = "Machine Gun Optic";
		optics = 1;

		modelOptics = "\rhsusf\addons\rhsusf_weapons\acc\scopes\optics\rhsusf_elcan";
		class OpticsModes
		{
			///! 3.5-10X MAGNIFICATION -> 0.2492/4
			class elcan_scope
			{
				opticsID = 2;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
				discreteDistance[] = {100};
 				discreteDistanceInitIndex = 0;
				opticsZoomMax = 0.2492/3.4;
				opticsZoomMin = 0.2492/3.4;
				opticsZoomInit = 0.2492/3.4;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				distanceZoomMin = 200;
				distanceZoomMax = 1000;
				cameraDir = "direction";
			};
			class alternative_view
			{
				opticsID = 1;
				useModelOptics = 0;
				opticsPPEffects[] = {""};
				opticsZoomMin = 0.375;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.75;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				cameraDir = "";
			};
		};
	};

	inertia = 0.1;
};

class rhsusf_acc_ELCAN_pip: rhsusf_acc_ELCAN
{
	Author_Macro
	displayName = "$STR_RHSUSF_ACC_M145_3D";
	descriptionShort =  "$STR_RHSUSF_ACC_M145_3D";

	model = "\rhsusf\addons\rhsusf_weapons\acc\scopes\elcan\elcan_pip";

	weaponInfoType = "rhs_elcan_pip_handler";
	class ItemInfo: ItemInfo
	{
		class OpticsModes: OpticsModes
		{
			class elcan_scope
			{
				opticsID=1;
				useModelOptics=0;
				opticsZoomMin=0.275;
				opticsZoomMax=1.1;
				opticsZoomInit=0.75;
				memoryPointCamera="pip_view";
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
				distanceZoomMin=100;
				distanceZoomMax=100;
				cameraDir="";
				visionMode[]={};
				opticsPPEffects[]=
				{

				};
			};
			class alternative_view: alternative_view {};
		};
	};
};

class rhsusf_acc_ACOG: rhsusf_acc_sniper_base
{
	scope = 2;
	Author_Macro
	displayName = "$STR_RHSUSF_ACC_M150";
	descriptionShort =  "$STR_RHSUSF_ACC_M150";

	picture="\rhsusf\addons\rhsusf_weapons\gear_acc\rhs_acog_icon_ca.paa";
	model = "\rhsusf\addons\rhsusf_weapons\acc\scopes\acog\acog";opticsDisablePeripherialVision = 0;

	weaponInfoType = "RscWeaponZeroing";
	class ItemInfo: InventoryOpticsItem_Base_F
	{
		opticType = 2;
		mass = 4;
		RMBhint = "Rifle Combat Optic";
		optics = 1;

		modelOptics = "\rhsusf\addons\rhsusf_weapons\acc\scopes\optics\rhsusf_acog";
		class OpticsModes
		{
			class elcan_scope
			{
				opticsID = 2;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
				//top of arrow is pointing at 100m, rest of range adjustments is performed with
				//help of recticle markings
				discreteDistance[] = {100};
 				discreteDistanceInitIndex = 0;
				opticsZoomMin = 0.35/4;
				opticsZoomMax = 0.35/4;
				opticsZoomInit = 0.35/4;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				distanceZoomMin = 100;
				distanceZoomMax = 1000;
				cameraDir = "";
			};

			class alternative_view
			{
				opticsID = 1;
				useModelOptics = 0;
				opticsPPEffects[] = {""};
				opticsZoomMin = 0.375;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.75;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				cameraDir = "";
			};
		};
	};

	inertia = 0.1;
};

class rhsusf_acc_ACOG_pip: rhsusf_acc_ACOG
{
	Author_Macro
	displayName = "$STR_RHSUSF_ACC_M150_3D";
	descriptionShort =  "$STR_RHSUSF_ACC_M150_3D";

	model = "\rhsusf\addons\rhsusf_weapons\acc\scopes\acog\acog_pip";

	weaponInfoType = "rhs_acog_pip_handler";
	class ItemInfo: ItemInfo
	{

		class OpticsModes: OpticsModes
		{
			class elcan_scope
			{
				opticsID=1;
				useModelOptics=0;
				opticsZoomMin=0.275;
				opticsZoomMax=1.1;
				opticsZoomInit=0.75;
				memoryPointCamera="opticview";
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
				distanceZoomMin=100;
				distanceZoomMax=100;
				cameraDir="";
				visionMode[]={};
				opticsPPEffects[]=
				{

				};
			};
			class alternative_view: alternative_view {};
		};
	};
};

class rhsusf_acc_ACOG2: rhsusf_acc_ACOG
{
	Author_Macro
	displayName = "$STR_RHSUSF_ACC_M150_ARD";
	descriptionShort =  "$STR_RHSUSF_ACC_M150_ARD";

	model = "\rhsusf\addons\rhsusf_weapons\acc\scopes\acog\acog_glarehider";

	weaponInfoType = "RscWeaponZeroing";
	class ItemInfo: ItemInfo
	{
		opticType = 2;
		mass = 4;
		RMBhint = "Rifle Combat Optic";
		optics = 1;

		modelOptics = "\rhsusf\addons\rhsusf_weapons\acc\scopes\optics\rhsusf_acog_hex";
		class OpticsModes: OpticsModes
		{
			class elcan_scope: elcan_scope
			{
				opticsFlare = 0;
			};
			class alternative_view: alternative_view {};
		};
	};
};

class rhsusf_acc_ACOG3: rhsusf_acc_ACOG
{
	Author_Macro
	displayName = "$STR_RHSUSF_ACC_M150_ARD_L";
	descriptionShort =  "$STR_RHSUSF_ACC_M150_ARD_L";

	picture="\rhsusf\addons\rhsusf_weapons\gear_acc\rhs_acog_icon_ca.paa";
	model = "\rhsusf\addons\rhsusf_weapons\acc\scopes\acog\acog_glarehider_lenscover";

	class ItemInfo: ItemInfo
	{

		modelOptics = "\rhsusf\addons\rhsusf_weapons\acc\scopes\optics\rhsusf_acog_hex";
	};
};

class rhsusf_acc_ACOG_USMC: rhsusf_acc_sniper_base
{
	scope = 2;
	Author_Macro
	displayName = "$STR_RHSUSF_ACC_31A";
	descriptionShort =  "$STR_RHSUSF_ACC_31A";

	picture="\rhsusf\addons\rhsusf_weapons\gear_acc\rhs_acog_icon_ca.paa";
	model = "\rhsusf\addons\rhsusf_weapons\acc\scopes\acog\acog";

	weaponInfoType = "RscWeaponZeroing";
	class ItemInfo: InventoryOpticsItem_Base_F
	{
		opticType = 2;
		mass = 4;
		RMBhint = "Rifle Combat Optic";
		optics = 1;

		modelOptics = "\rhsusf\addons\rhsusf_weapons\acc\scopes\optics\rhsusf_acog2";
		class OpticsModes
		{
			class elcan_scope
			{
				opticsID = 2;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
				//top of arrow is pointing at 100m, rest of range adjustments is performed with
				//help of recticle markings
				discreteDistance[] = {100};
 				discreteDistanceInitIndex = 0;
				opticsZoomMin = 0.35/4;
				opticsZoomMax = 0.35/4;
				opticsZoomInit = 0.35/4;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				distanceZoomMin = 100;
				distanceZoomMax = 1000;
				cameraDir = "";
			};

			class alternative_view
			{
				opticsID = 1;
				useModelOptics = 0;
				opticsPPEffects[] = {""};
				opticsZoomMin = 0.375;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.75;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				cameraDir = "";
			};
		};
	};

	inertia = 0.1;
};

class rhsusf_acc_ACOG2_USMC: rhsusf_acc_ACOG
{
	Author_Macro
	displayName = "$STR_RHSUSF_ACC_31A_ARD";
	descriptionShort =  "$STR_RHSUSF_ACC_31A_ARD";

	model = "\rhsusf\addons\rhsusf_weapons\acc\scopes\acog\acog_glarehider";

	weaponInfoType = "RscWeaponZeroing";
	class ItemInfo: ItemInfo
	{
		opticType = 2;
		mass = 4;
		RMBhint = "Rifle Combat Optic";
		optics = 1;

		modelOptics = "\rhsusf\addons\rhsusf_weapons\acc\scopes\optics\rhsusf_acog2_hex";
		class OpticsModes: OpticsModes
		{
			class elcan_scope: elcan_scope
			{
				opticsFlare = 0;
			};
			class alternative_view: alternative_view {};
		};
	};
};

class rhsusf_acc_ACOG3_USMC: rhsusf_acc_ACOG
{
	Author_Macro
	displayName = "$STR_RHSUSF_ACC_31A_ARD_L";
	descriptionShort =  "$STR_RHSUSF_ACC_31A_ARD_L";

	picture="\rhsusf\addons\rhsusf_weapons\gear_acc\rhs_acog_icon_ca.paa";
	model = "\rhsusf\addons\rhsusf_weapons\acc\scopes\acog\acog_glarehider_lenscover";

	class ItemInfo: ItemInfo
	{

		modelOptics = "\rhsusf\addons\rhsusf_weapons\acc\scopes\optics\rhsusf_acog2_hex";
	};
};

class rhsusf_acc_LEUPOLDMK4_2 : rhsusf_acc_sniper_base
{
	displayName = $STR_RHSUSF_ACC_LEUPOLDMK402;
	scope=2;
	Author_Macro
	weaponInfoType = "RscWeaponZeroing";
	model = "\rhsusf\addons\rhsusf_weapons\acc\scopes\leupoldmk4\leupoldmk4_2";

	class ItemInfo: InventoryOpticsItem_Base_F
	{
		opticType = 2;
		mass = 4;
		RMBhint = "Optical Sniper Sight";
		optics = 1;

		modelOptics = "\rhsusf\addons\rhsusf_weapons\acc\scopes\optics\rhsusf_leu_H58";
		class OpticsModes
		{
			///! 3.5-10X MAGNIFICATION -> 0.2492/4
			class pso1_scope
			{
				opticsID = 2;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
 				discreteDistanceInitIndex = 1;
				opticsZoomMax = 0.35/6.5;
				opticsZoomMin = 0.35/20;
				opticsZoomInit = 0.35/6.5;
				discretefov[] = {0.35/6.5,0.35/20};
 				discreteInitIndex = 0;
 				modelOptics[] = {"\rhsusf\addons\rhsusf_weapons\acc\scopes\optics\rhsusf_leu_H58", "\rhsusf\addons\rhsusf_weapons\acc\scopes\optics\rhsusf_leu_H58_20"};

				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				distanceZoomMin = 200;
				distanceZoomMax = 1000;
				cameraDir = "";
			};
		};
	};
};

class rhsusf_acc_EOTECH : optic_Holosight
{
	displayName = $STR_RHSUSF_ACC_EOTECH;
	scope=2;

	inertia = 0;
};

