//class Rifle;

class RHSUSF_HeatHaze
{
    class RHSUSF_HeatHaze
    {
        simulation = "particles";
        type = "RHSUSF_HeatHaze";
        position[] = {0,0,0};
        intensity = 1;
        interval = 1;
        lifeTime = 0.05;
    };
};

class Pistol_Base_F;
class Rifle_Base_F;
class Rifle_Long_Base_F;
class WeaponSlotsInfo;
class GunParticles;
class UGL_F;
class srifle_EBR_F;
class Launcher;
class Launcher_Base_F : Launcher
{
	class WeaponSlotsInfo;
};

class rhs_weap_M320_Base_F: Pistol_Base_F
{
	magazines[] =
	{
		"rhs_mag_M441_HE",
		"rhs_mag_M433_HEDP",
		"rhs_mag_M4009",
		"rhs_mag_m576",
		"rhs_mag_M585_white",
		"rhs_mag_M661_green",
		"rhs_mag_M662_red",
		"rhs_mag_M713_red",
		"rhs_mag_M714_white",
		"rhs_mag_M715_green",
		"rhs_mag_M716_yellow",

		//bis compatibility
		"1Rnd_HE_Grenade_shell",
		"UGL_FlareWhite_F",
		"UGL_FlareGreen_F",
		"UGL_FlareRed_F",
		"UGL_FlareYellow_F",
		"UGL_FlareCIR_F",
		"1Rnd_Smoke_Grenade_shell",
		"1Rnd_SmokeRed_Grenade_shell",
		"1Rnd_SmokeGreen_Grenade_shell",
		"1Rnd_SmokeYellow_Grenade_shell",
		"1Rnd_SmokePurple_Grenade_shell",
		"1Rnd_SmokeBlue_Grenade_shell",
		"1Rnd_SmokeOrange_Grenade_shell",
		"3Rnd_HE_Grenade_shell",
		"3Rnd_UGL_FlareWhite_F",
		"3Rnd_UGL_FlareGreen_F",
		"3Rnd_UGL_FlareRed_F",
		"3Rnd_UGL_FlareYellow_F",
		"3Rnd_UGL_FlareCIR_F",
		"3Rnd_Smoke_Grenade_shell",
		"3Rnd_SmokeRed_Grenade_shell",
		"3Rnd_SmokeGreen_Grenade_shell",
		"3Rnd_SmokeYellow_Grenade_shell",
		"3Rnd_SmokePurple_Grenade_shell",
		"3Rnd_SmokeBlue_Grenade_shell",
		"3Rnd_SmokeOrange_Grenade_shell"

	};

	// TODO: Librbary description required
	class Library
	{
		libTextDesc = "";
	};

	optics = 0;

	maxRecoilSway = 0.0125;
	swayDecaySpeed = 1.25;

	class GunParticles: GunParticles
	{
		class SecondEffect
		{
			positionName = "Nabojnicestart";
			directionName = "Nabojniceend";
			effectName = "RifleAssaultCloud";
		};
	};

	weaponInfoType = "RscWeaponZeroing";
	discreteDistance[] = {100, 200, 300, 400};
	discreteDistanceInitIndex = 1;

	opticsZoomMin = 0.375;
	opticsZoomMax = 1.1;
	opticsZoomInit = 0.75;
	distanceZoomMin = 300;
	distanceZoomMax = 300;


	class WeaponSlotsInfo: WeaponSlotsInfo
	{
		class CowsSlot {};
	};

	reloadAction = "GestureReloadMX";
	descriptionShort = $STR_A3_CfgWeapons_XM_base_F0;
	handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m320.rtm"};

	dexterity = 1.8;
	caseless[] = {"",1,1,1};

	soundBullet[] = {"caseless",1};
	modes[] = {"Single","single_medium_optics1","single_far_optics2"};

	class Single: Mode_SemiAuto
	{
		sounds[]={"StandardSound"};
		class StandardSound
		{
			weaponSoundEffect="DefaultRifle";

			begin1[] = {"A3\sounds_f\weapons\M320\M320_st_1",1.4125376,1,1200};
			begin2[] = {"A3\sounds_f\weapons\M320\M320_st_2",1.4125376,1,1200};
			soundBegin[] = {"begin1",0.5,"begin2",0.5};

			closure1[] = {"A3\sounds_f\weapons\closure\closure_rifle_6.wss",3.1622777,1,300};
			closure2[] = {"A3\sounds_f\weapons\closure\closure_rifle_7.wss",3.1622777,1,300};
			soundClosure[] = {"closure1",0.5,"closure2",0.5};
		};
		reloadTime = 0.1;
		recoil = "recoil_single_mx";
		recoilProne = "recoil_single_prone_mx";
		dispersion = 0.00093;
		minRange = 2;
		minRangeProbab = 0.3;
		midRange = 250;
		midRangeProbab = 0.7;
		maxRange = 400;
		maxRangeProbab = 0.04;
	};
	class single_medium_optics1: Single
	{
		requiredOpticType = 1;
		showToPlayer = 0;
		minRange = 2;
		minRangeProbab = 0.2;
		midRange = 550;
		midRangeProbab = 0.7;
		maxRange = 700;
		maxRangeProbab = 0.1;
		aiRateOfFire = 6;
		aiRateOfFireDistance = 600;
	};
	class single_far_optics2: single_medium_optics1
	{
		requiredOpticType = 2;
	};

	aiDispersionCoefY = 10;
	aiDispersionCoefX = 8;
	drySound[] = {"A3\sounds_f\weapons\Other\dry_1",0.01,1};

	reloadMagazineSound[] = {"A3\sounds_f\weapons\M320\M320_reload",0.1,1,30};

	hiddenSelections[] = {""};
	hiddenSelectionsTextures[] = {""};
	//type=2;

};

class rhs_weap_M320 : rhs_weap_M320_Base_F
{
	scope = 2;

	Author_Macro
	displayName= $STR_RHS_CFGWEAPONS_RIFLE_M320;
	descriptionShort = ;

	model = "\rhsusf\addons\rhsusf_weapons\m320\M320standalone.p3d";

	picture = "\rhsusf\addons\rhsusf_weapons\icons\m320standalone_ca.paa";

	UiPicture = "\A3\weapons_f\data\UI\icon_regular_CA.paa";

	//modes[] = {"this"};

	weaponInfoType = "RscWeaponZeroing";
	cameraDir = "gl_look";
	discreteDistance[] = {50, 100, 150, 200, 250, 300, 350};
	discreteDistanceCameraPoint[] = {"gl_eye_50m", "gl_eye_100m", "gl_eye_150m", "gl_eye_200m", 				"gl_eye_250m", "gl_eye_300m", "gl_eye_350m"};
	discreteDistanceInitIndex = 0;

	class WeaponSlotsInfo: WeaponSlotsInfo
	{
		mass = 37.4;
	};

	class ItemInfo
	{
		priority = 1;
		RMBhint = "AK-74M";
		onHoverText = "TODO AK-74M DSS";
	};

};

class rhs_weap_XM2010_Base_F: Rifle_Base_F
{
	magazines[] = {"rhsusf_5Rnd_300winmag_xm2010"};

	// TODO: Librbary description required
	class Library
	{
		libTextDesc = "";
	};

	optics = 0;

	reloadAction = "RHS_GestureReloadM2010";
	maxRecoilSway = 0.0125;
	swayDecaySpeed = 1.25;

	class GunParticles : GunParticles
	{
		class SecondEffect
		{
			positionName = "Nabojnicestart";
			directionName = "Nabojniceend";
			effectName = "RifleAssaultCloud";
		};
		class RHSUSF_BarrelRefract
		{
			positionName = "usti hlavne";
			directionName = "usti hlavne up";
			effectName = "RHSUSF_BarrelRefract";
		};
	};

	weaponInfoType = "RscWeaponZeroing";
	discreteDistance[] = {100,200,400,600,800,1000,1200,1400};
	discreteDistanceInitIndex = 0;

 	class WeaponSlotsInfo: WeaponSlotsInfo
	{
		class MuzzleSlot: SlotInfo
		{
			linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";
			compatibleItems[] = {"rhsusf_acc_M2010S"};
		};
		class CowsSlot: rhs_western_rifle_scopes_slot_long {};
		class PointerSlot: rhs_western_rifle_laser_slot {};
		class UnderBarrelSlot: rhs_western_rifle_underbarrel_slot {};
	};

	opticsZoomMin = 0.375;
	opticsZoomMax = 1.1;
	opticsZoomInit = 0.75;
	distanceZoomMin = 300;
	distanceZoomMax = 300;

	descriptionShort = $STR_A3_CfgWeapons_XM_base_F0;
	handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_mk12.rtm"};
	dexterity = 1.8;
	caseless[] = {"",1,1,1};

	soundBullet[] = {"caseless",1};
	modes[]=
	{
		"Single",
		"far_optic1",
		"medium_optic2",
		"far_optic2"
	};

	class Single: Mode_SemiAuto
	{
		sounds[]={"StandardSound"};
		class StandardSound
		{
			weaponSoundEffect="DefaultRifle";

			begin1[] = {"A3\sounds_f\weapons\M320\M320_st_1",1.4125376,1,1200};
			begin2[] = {"A3\sounds_f\weapons\M320\M320_st_2",1.4125376,1,1200};
			soundBegin[] = {"begin1",0.5,"begin2",0.5};

			closure1[] = {"A3\sounds_f\weapons\closure\closure_rifle_6.wss",3.1622777,1,300};
			closure2[] = {"A3\sounds_f\weapons\closure\closure_rifle_7.wss",3.1622777,1,300};
			soundClosure[] = {"closure1",0.5,"closure2",0.5};
		};
		reloadTime = 1.6;
		recoil="recoil_single_gm6";
		recoilProne="recoil_single_prone_gm6";
		//MOA <=1
		dispersion = 0.0002909;
		minRange = 2;
		minRangeProbab = 0.3;
		midRange = 250;
		midRangeProbab = 0.7;
		maxRange = 400;
		maxRangeProbab = 0.04;
	};
	class far_optic1: Single
	{
		showToPlayer=0;
		minRange=150;
		minRangeProbab=0.1;
		midRange=500;
		midRangeProbab=0.7;
		maxRange=1000;
		maxRangeProbab=0.3;
		aiRateOfFire=5;
		aiRateOfFireDistance=700;
		requiredOpticType=1;
	};
	class medium_optic2: Single
	{
		showToPlayer=0;
		minRange=250;
		minRangeProbab=0.1;
		midRange=750;
		midRangeProbab=0.7;
		maxRange=1000;
		maxRangeProbab=0.3;
		aiRateOfFire=6;
		aiRateOfFireDistance=1000;
		requiredOpticType=2;
	};
	class far_optic2: far_optic1
	{
		minRange=500;
		minRangeProbab=0.1;
		midRange=1050;
		midRangeProbab=0.7;
		maxRange=2000;
		maxRangeProbab=0.3;
		aiRateOfFire=8;
		aiRateOfFireDistance=2000;
		requiredOpticType=2;
	};

	aiDispersionCoefY = 10;
	aiDispersionCoefX = 8;
	drySound[] = {"A3\sounds_f\weapons\Other\dry_1",0.01,1};

	reloadMagazineSound[] = {"A3\sounds_f\weapons\M320\M320_reload",0.1,1,30};
	hiddenSelections[] = {"Camo"};
	hiddenSelectionsTextures[] = {"\rhsusf\addons\rhsusf_weapons\XM2010\Data\XM2010_co.paa"};

};

class rhs_weap_XM2010 : rhs_weap_XM2010_Base_F
{
	scope = 2;

	Author_Macro
	displayName = $STR_RHS_CFGWEAPONS_RIFLE_xm2010;
	descriptionShort = ;

	model = "\rhsusf\addons\rhsusf_weapons\XM2010\xm2010.p3d";

	picture = "\rhsusf\addons\rhsusf_weapons\icons\w_xm2010_ca.paa";

	UiPicture = "\A3\weapons_f\data\UI\icon_regular_CA.paa";
	handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_mk12.rtm"};

	//weaponInfoType = "rhs_m2010_handler";
	discreteDistance[] = {100,200,300,400,500,600};
	discreteDistanceInitIndex = 0;

	class WeaponSlotsInfo: WeaponSlotsInfo
	{
		mass = 121;
	};

	class ItemInfo
	{
		priority = 1;
		RMBhint = "M2010 ESR";
		onHoverText = "M2010";
	};

};

class rhs_weap_XM2010_d : rhs_weap_XM2010
{
	Author_Macro
    	displayName = $STR_RHS_CFGWEAPONS_RIFLE_xm2010_d;
	picture = "\rhsusf\addons\rhsusf_weapons\icons\w_xm2010d_ca.paa";

	hiddenSelections[] = {"Camo"};
	hiddenSelectionsTextures[] = {"\rhsusf\addons\rhsusf_weapons\XM2010\Data\XM2010_d_co.paa"};
};

class rhs_weap_XM2010_wd : rhs_weap_XM2010
{
	Author_Macro
	displayName = $STR_RHS_CFGWEAPONS_RIFLE_xm2010_wd;
	picture = "\rhsusf\addons\rhsusf_weapons\icons\w_xm2010wd_ca.paa";

	hiddenSelections[] = {"Camo"};
	hiddenSelectionsTextures[] = {"\rhsusf\addons\rhsusf_weapons\XM2010\Data\XM2010_wd_co.paa"};
};

class rhs_weap_XM2010_sa : rhs_weap_XM2010
{
	Author_Macro
	displayName = $STR_RHS_CFGWEAPONS_RIFLE_xm2010_sa;
	picture = "\rhsusf\addons\rhsusf_weapons\icons\w_xm2010sa_ca.paa";

	hiddenSelections[] = {"Camo"};
	hiddenSelectionsTextures[] = {"\rhsusf\addons\rhsusf_weapons\XM2010\Data\XM2010_sa_co.paa"};
};

class arifle_MX_Base_F: Rifle_Base_F {};
class rhs_weap_m4_Base : arifle_MX_Base_F
{
	scope = 0;
	UiPicture = "\A3\weapons_f\data\UI\icon_regular_CA.paa";
	magazines[] =
	{
		//rhs mags
		"rhs_mag_30Rnd_556x45_Mk318_Stanag",
		"rhs_mag_30Rnd_556x45_Mk262_Stanag",
		"rhs_mag_30Rnd_556x45_M855A1_Stanag",
		"rhs_mag_30Rnd_556x45_M855A1_Stanag_No_Tracer",
		"rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Red",
		"rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Green",
		"rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Yellow",
		"rhs_mag_30Rnd_556x45_M200_Stanag",

		//bis mags compatibility
		"30Rnd_556x45_Stanag",
		"30Rnd_556x45_Stanag_Tracer_Red",
		"30Rnd_556x45_Stanag_Tracer_Green",
		"30Rnd_556x45_Stanag_Tracer_Yellow"
	};

	reloadAction = "RHS_GestureReloadAR15";

	maxRecoilSway = 0.0125;
	swayDecaySpeed = 1.25;
	opticsZoomMin=0.375;
	opticsZoomMax=1.1;
	opticsZoomInit=0.75;
	distanceZoomMin=300;
	distanceZoomMax=300;
	aiDispersionCoefY = 6.0;
	aiDispersionCoefX = 4.0;
	dexterity = 1.8;

	discreteDistance[]={200,300,400,450,500,550,600};

	descriptionShort="Assault rifle<br/>Caliber: 5.56 mm";
	class Library
	{
		libTextDesc = "TEMPORARY DESCRIPTION";
	};

	class ItemInfo
	{
		priority = 1;
		RMBhint = "M4";
		onHoverText = "TODO M4 DSS";
	};

	class GunParticles: GunParticles
	{
		class SecondEffect
		{
			positionName = "Nabojnicestart";
			directionName = "Nabojniceend";
			effectName = "CaselessAmmoCloud";
		};
		class RHSUSF_BarrelRefract
		{
			positionName = "usti hlavne";
			directionName = "usti hlavne up";
			effectName = "RHSUSF_BarrelRefract";
		};
	};

	class WeaponSlotsInfo
	{
		mass = 60;
		allowedSlots[] = {901};
		class UnderBarrelSlot: rhs_western_rifle_underbarrel_slot {};
		class CowsSlot: rhs_western_rifle_scopes_slot_short {};
		class PointerSlot: rhs_western_rifle_laser_slot_top {};
		class MuzzleSlot: rhs_western_rifle_muzzle_slot {};
	};

	bullet1[] = {"A3\sounds_f\weapons\shells\5_56\metal_556_01.wss", 0.1, 1, 15};
	bullet2[] = {"A3\sounds_f\weapons\shells\5_56\metal_556_02.wss", 0.1, 1, 15};
	bullet3[] = {"A3\sounds_f\weapons\shells\5_56\metal_556_03.wss", 0.177828, 1, 15};
	bullet4[] = {"A3\sounds_f\weapons\shells\5_56\metal_556_04.wss", 0.177828, 1, 15};
	bullet5[] = {"A3\sounds_f\weapons\shells\5_56\asphlat_556_01.wss", 0.1, 1, 15};
	bullet6[] = {"A3\sounds_f\weapons\shells\5_56\asphlat_556_02.wss", 0.1, 1, 15};
	bullet7[] = {"A3\sounds_f\weapons\shells\5_56\asphlat_556_03.wss", 0.1, 1, 15};
	bullet8[] = {"A3\sounds_f\weapons\shells\5_56\asphlat_556_04.wss", 0.1, 1, 15};
	bullet9[] = {"A3\sounds_f\weapons\shells\5_56\grass_556_01.wss", 0.01, 1, 15};
	bullet10[] = {"A3\sounds_f\weapons\shells\5_56\grass_556_02.wss", 0.01, 1, 15};
	bullet11[] = {"A3\sounds_f\weapons\shells\5_56\grass_556_03.wss", 0.01, 1, 15};
	bullet12[] = {"A3\sounds_f\weapons\shells\5_56\grass_556_04.wss", 0.01, 1, 15};
	soundBullet[] = {"bullet1", 0.083, "bullet2", 0.083, "bullet3", 0.083, "bullet4", 0.083, "bullet5", 0.083, "bullet6", 0.083, "bullet7", 0.083, "bullet8", 0.083, "bullet9", 0.083, "bullet10", 0.083, "bullet11", 0.083, "bullet12", 0.083};


	modes[]=
	{
		"Single",
		"Burst",
		"single_medium_optics1",
		"single_far_optics2"
	};
	class Single: Mode_SemiAuto
	{
		sounds[]=
		{
			"StandardSound",
			"SilencedSound"
		};
		class BaseSoundModeType
		{
			weaponSoundEffect="DefaultRifle";
			closure1[]={"A3\sounds_f\weapons\closure\closure_rifle_6",0.70794576,1,10};
			closure2[]={"A3\sounds_f\weapons\closure\closure_rifle_7",0.70794576,1,10};
			soundClosure[]=	{"closure1",0.5,"closure2",0.5};
		};
		class StandardSound: BaseSoundModeType
		{
			begin1[]={"A3\sounds_f\weapons\MX\mx-st-full-1",1,1,1200};
			begin2[]={"A3\sounds_f\weapons\MX\mx-st-full-2",1,1,1200};
			soundBegin[]={"begin1",0.5,"begin2",0.5};
		};
		class SilencedSound: BaseSoundModeType
		{
			begin1[]={"A3\sounds_f\weapons\silenced\silent-18",0.79432821,1,100};
			begin2[]={"A3\sounds_f\weapons\silenced\silent-19",0.79432821,1,100};
			begin3[]={"A3\sounds_f\weapons\silenced\silent-11",0.79432821,1,100};
			soundBegin[]={"begin1",0.333,"begin2",0.333,"begin3",0.333};
		};
		//
		reloadTime = 0.095;


		dispersion=0.0008727; //2 MOA?
		//dispersion=0.0022;
		//
		recoil="recoil_single_mx";
		recoilProne="recoil_single_prone_mx";
		//
		minRange = 2;
		minRangeProbab = 0.5;
		//
		midRange = 250;
		midRangeProbab = 0.7;
		//
		maxRange = 500;
		maxRangeProbab = 0.2;
	};

	class Burst : Mode_Burst
	{
		sounds[]=
		{
			"StandardSound",
			"SilencedSound"
		};
		class BaseSoundModeType
		{
			weaponSoundEffect="DefaultRifle";
			closure1[]={"A3\sounds_f\weapons\closure\closure_rifle_6",0.70794576,1,10};
			closure2[]={"A3\sounds_f\weapons\closure\closure_rifle_7",0.70794576,1,10};
			soundClosure[]=	{"closure1",0.5,"closure2",0.5};
		};
		class StandardSound: BaseSoundModeType
		{
			begin1[]={"A3\sounds_f\weapons\MX\mx-st-full-1",1,1,1200};
			begin2[]={"A3\sounds_f\weapons\MX\mx-st-full-2",1,1,1200};
			soundBegin[]={"begin1",0.5,"begin2",0.5};
		};
		class SilencedSound: BaseSoundModeType
		{
			begin1[]={"A3\sounds_f\weapons\silenced\silent-18",0.79432821,1,100};
			begin2[]={"A3\sounds_f\weapons\silenced\silent-19",0.79432821,1,100};
			begin3[]={"A3\sounds_f\weapons\silenced\silent-11",0.79432821,1,100};
			soundBegin[]={"begin1",0.333,"begin2",0.333,"begin3",0.333};
		};
		//
		reloadTime = 0.095;
		dispersion=0.0022;
		//
		recoil="recoil_auto_mx";
		recoilProne="recoil_auto_prone_mx";
		//
		minRange = 1;
		minRangeProbab = 0.7;
		//
		midRange = 60;
		midRangeProbab = 0.8;
		//
		maxRange = 120;
		maxRangeProbab = 0.2;
	};

	class FullAuto : Mode_FullAuto
	{
		sounds[]=
		{
			"StandardSound",
			"SilencedSound"
		};
		class BaseSoundModeType
		{
			weaponSoundEffect="DefaultRifle";
			closure1[]={"A3\sounds_f\weapons\closure\closure_rifle_6",0.70794576,1,10};
			closure2[]={"A3\sounds_f\weapons\closure\closure_rifle_7",0.70794576,1,10};
			soundClosure[]=	{"closure1",0.5,"closure2",0.5};
		};
		class StandardSound: BaseSoundModeType
		{
			begin1[]={"A3\sounds_f\weapons\MX\mx-st-full-1",1,1,1200};
			begin2[]={"A3\sounds_f\weapons\MX\mx-st-full-2",1,1,1200};
			soundBegin[]={"begin1",0.5,"begin2",0.5};
		};
		class SilencedSound: BaseSoundModeType
		{
			begin1[]={"A3\sounds_f\weapons\silenced\silent-18",0.79432821,1,100};
			begin2[]={"A3\sounds_f\weapons\silenced\silent-19",0.79432821,1,100};
			begin3[]={"A3\sounds_f\weapons\silenced\silent-11",0.79432821,1,100};
			soundBegin[]={"begin1",0.333,"begin2",0.333,"begin3",0.333};
		};
		//
		reloadTime = 0.095;
		dispersion=0.0022;
		//
		recoil="recoil_auto_mx";
		recoilProne="recoil_auto_prone_mx";
		//
		minRange = 0;
		minRangeProbab = 0.9;
		//
		midRange = 15;
		midRangeProbab = 0.7;
		//
		maxRange = 30;
		maxRangeProbab = 0.1;
		//
		aiRateOfFire = 1e-006;
	};
	class single_medium_optics1: Single
	{
		requiredOpticType=1;
		showToPlayer=0;
		minRange=2;
		minRangeProbab=0.2;
		midRange=550;
		midRangeProbab=0.69;
		maxRange=700;
		maxRangeProbab=0.1;
		aiRateOfFire=6;
		aiRateOfFireDistance=600;
	};
	class single_far_optics2: single_medium_optics1
	{
		requiredOpticType=2;
	};
	class fullauto_medium: FullAuto
	{
		showToPlayer=0;
		burst=3;
		minRange=2;
		minRangeProbab=0.5;
		midRange=75;
		midRangeProbab=0.69;
		maxRange=150;
		maxRangeProbab=0.05;
		aiRateOfFire=2;
	};

	class M203_GL: UGL_F
	{
		displayName = "M203 grenade launcher";
		descriptionShort = "M203";
		useModelOptics = false;
		useExternalOptic = false;
		magazines[] =
		{
			"rhs_mag_M441_HE",
			"rhs_mag_M433_HEDP",
			"rhs_mag_M4009",
			"rhs_mag_m576",
			"rhs_mag_M585_white",
			"rhs_mag_M661_green",
			"rhs_mag_M662_red",
			"rhs_mag_M713_red",
			"rhs_mag_M714_white",
			"rhs_mag_M715_green",
			"rhs_mag_M716_yellow",

			//bis compatibility
			"1Rnd_HE_Grenade_shell",
			"UGL_FlareWhite_F",
			"UGL_FlareGreen_F",
			"UGL_FlareRed_F",
			"UGL_FlareYellow_F",
			"UGL_FlareCIR_F",
			"1Rnd_Smoke_Grenade_shell",
			"1Rnd_SmokeRed_Grenade_shell",
			"1Rnd_SmokeGreen_Grenade_shell",
			"1Rnd_SmokeYellow_Grenade_shell",
			"1Rnd_SmokePurple_Grenade_shell",
			"1Rnd_SmokeBlue_Grenade_shell",
			"1Rnd_SmokeOrange_Grenade_shell",
			"3Rnd_HE_Grenade_shell",
			"3Rnd_UGL_FlareWhite_F",
			"3Rnd_UGL_FlareGreen_F",
			"3Rnd_UGL_FlareRed_F",
			"3Rnd_UGL_FlareYellow_F",
			"3Rnd_UGL_FlareCIR_F",
			"3Rnd_Smoke_Grenade_shell",
			"3Rnd_SmokeRed_Grenade_shell",
			"3Rnd_SmokeGreen_Grenade_shell",
			"3Rnd_SmokeYellow_Grenade_shell",
			"3Rnd_SmokePurple_Grenade_shell",
			"3Rnd_SmokeBlue_Grenade_shell",
			"3Rnd_SmokeOrange_Grenade_shell"
		};
		cameraDir = "gl_look";
		discreteDistance[] = {50, 100, 150, 200, 250};
		discreteDistanceCameraPoint[] = {"gl_eye_50m", "gl_eye_100m", "gl_eye_150m", "gl_eye_200m", "gl_eye_250m" };
		discreteDistanceInitIndex = 1; /// 100 is the default zero
	};

	class M320_GL: M203_GL
	{
		displayName = "M320 GLM";
		descriptionShort = "M320";
		useModelOptics = false;
		useExternalOptic = false;
		magazines[] =
		{
			"rhs_mag_M441_HE",
			"rhs_mag_M433_HEDP",
			"rhs_mag_M4009",
			"rhs_mag_m576",
			"rhs_mag_M585_white",
			"rhs_mag_M661_green",
			"rhs_mag_M662_red",
			"rhs_mag_M713_red",
			"rhs_mag_M714_white",
			"rhs_mag_M715_green",
			"rhs_mag_M716_yellow",

			//bis compatibility
			"1Rnd_HE_Grenade_shell",
			"UGL_FlareWhite_F",
			"UGL_FlareGreen_F",
			"UGL_FlareRed_F",
			"UGL_FlareYellow_F",
			"UGL_FlareCIR_F",
			"1Rnd_Smoke_Grenade_shell",
			"1Rnd_SmokeRed_Grenade_shell",
			"1Rnd_SmokeGreen_Grenade_shell",
			"1Rnd_SmokeYellow_Grenade_shell",
			"1Rnd_SmokePurple_Grenade_shell",
			"1Rnd_SmokeBlue_Grenade_shell",
			"1Rnd_SmokeOrange_Grenade_shell",
			"3Rnd_HE_Grenade_shell",
			"3Rnd_UGL_FlareWhite_F",
			"3Rnd_UGL_FlareGreen_F",
			"3Rnd_UGL_FlareRed_F",
			"3Rnd_UGL_FlareYellow_F",
			"3Rnd_UGL_FlareCIR_F",
			"3Rnd_Smoke_Grenade_shell",
			"3Rnd_SmokeRed_Grenade_shell",
			"3Rnd_SmokeGreen_Grenade_shell",
			"3Rnd_SmokeYellow_Grenade_shell",
			"3Rnd_SmokePurple_Grenade_shell",
			"3Rnd_SmokeBlue_Grenade_shell",
			"3Rnd_SmokeOrange_Grenade_shell"
		};
		cameraDir = "gl_look";
		discreteDistance[] = {50, 100, 150, 200, 250, 300, 350};
		discreteDistanceCameraPoint[] = {"gl_eye_50m", "gl_eye_100m", "gl_eye_150m", "gl_eye_200m", "gl_eye_250m", "gl_eye_300m", "gl_eye_350m"};
		discreteDistanceInitIndex = 1; /// 100 is the default zero
	};

	changeFiremodeSound[] = {"A3\sounds_f\weapons\closure\firemode_changer_2",0.551189,1,5};
};

	class rhs_weap_m4 : rhs_weap_m4_Base
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4ris_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4_ris.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1.rtm"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 60;
		};
	};

	class rhs_weap_m4_carryhandle : rhs_weap_m4_Base
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4_carry;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4carryhandle_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4_ris_carryhandle.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1.rtm"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 63;
		};
	};


	class rhs_weap_m4_carryhandle_pmag : rhs_weap_m4_Base
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4_carryp;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4carryhandle_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4_ris_carryhandle_pmag.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1.rtm"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 63;
		};
	};

	class rhs_weap_m4a1 : rhs_weap_m4_Base
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4A1;
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4a1_ris.p3d";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4ris_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1.rtm"};

		modes[] =
		{
			"Single",
			"FullAuto",
			"single_medium_optics1",
			"single_far_optics2"
		};

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 60;
		};
	};

	class rhs_weap_m4a1_carryhandle : rhs_weap_m4_Base
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4A1_carryhandle;
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4a1_ris_carryhandle.p3d";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4ris_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1.rtm"};

		modes[] =
		{
			"Single",
			"FullAuto",
			"single_medium_optics1",
			"single_far_optics2"
		};

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 60;
		};
	};

	class rhs_weap_m4a1_carryhandle_pmag : rhs_weap_m4_Base
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4A1_carryp;
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4a1_ris_carryhandle_pmag.p3d";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4ris_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1.rtm"};

		modes[] =
		{
			"Single",
			"FullAuto",
			"single_medium_optics1",
			"single_far_optics2"
		};

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 60;
		};
	};

	class rhs_weap_m4a1_blockII : rhs_weap_m4a1
	{
		scope = 1;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4A1BLII;
		model = "\rhsusf\addons\rhsusf_weapons\M4BII\m4a1_blockII.p3d";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4b2_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1.rtm"};

		modes[] =
		{
			"Single",
			"FullAuto",
			"single_medium_optics1",
			"single_far_optics2"
		};

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 64;
		};
	};

	class rhs_weap_m4a1_blockII_KAC : rhs_weap_m4a1_blockII
	{
		scope = 1;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4A1BLII_KAC;
		model = "\rhsusf\addons\rhsusf_weapons\M4BII\m4a1_blockII_KACSTOCK.p3d";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4b2_ca.paa";
	};

	class rhs_weap_m4a1_blockII_grip2 : rhs_weap_m4a1_blockII
	{
		scope = 1;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4A1BLII_afg;
		model = "\rhsusf\addons\rhsusf_weapons\M4BII\m4a1_blockII_grip2.p3d";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4b2afg_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1_afg.rtm"};

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 64;
			class UnderBarrelSlot {};
		};
		inertia = 0.4;
		dexterity = 1.6;
	};

	class rhs_weap_m4a1_blockII_grip2_KAC : rhs_weap_m4a1_blockII_grip2
	{
		scope = 1;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4A1BLII_afg_kac;
		model = "\rhsusf\addons\rhsusf_weapons\M4BII\m4a1_blockII_grip2_KACSTOCK.p3d";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4b2afg_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1_afg.rtm"};
	};

	class rhs_weap_mk18 : rhs_weap_m4a1
	{
		scope = 1;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_MK18;
		model = "\rhsusf\addons\rhsusf_weapons\M4BII\MK18.p3d";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_mk18_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1.rtm"};

		modes[] =
		{
			"Single",
			"FullAuto",
			"single_medium_optics1",
			"single_far_optics2"
		};

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 59.7;
		};
	};

	class rhs_weap_mk18_KAC : rhs_weap_mk18
	{
		scope = 1;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_MK18_KAC;
		model = "\rhsusf\addons\rhsusf_weapons\M4BII\MK18_KACSTOCK.p3d";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_mk18_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1.rtm"};
	};

	class rhs_weap_mk18_grip2 : rhs_weap_mk18
	{
		scope = 1;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_MK18_afg;
		model = "\rhsusf\addons\rhsusf_weapons\M4BII\MK18_grip2.p3d";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_mk18afg_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1_afg.rtm"};

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 59.9;
			class UnderBarrelSlot {};
		};
		inertia = 0.4;
		dexterity = 1.6;
	};

	class rhs_weap_mk18_grip2_KAC : rhs_weap_mk18_grip2
	{
		scope = 1;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_MK18_afg_kac;
		model = "\rhsusf\addons\rhsusf_weapons\M4BII\MK18_grip2_KACSTOCK.p3d";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_mk18afg_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1_afg.rtm"};
	};

	class rhs_weap_m4_grip : rhs_weap_m4_Base
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4_foreg;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4carryhandlegrip_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4_ris_grip1.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m16a4.rtm"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 61;
			class UnderBarrelSlot {};
		};
	};

	class rhs_weap_m4_grip2 : rhs_weap_m4_Base
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4_afg;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4carryhandlegrip_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4_ris_grip2.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1_afg.rtm"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 61;
			class UnderBarrelSlot {};
		};
	};

	class rhs_weap_m4_bipod : rhs_weap_m4
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4_BIPOD;
		class LinkedItems
		{
			class LinkedItemsUnder
			{
				item = "rhsusf_acc_harris_bipod";
				slot = "UnderBarrelSlot";
			};
		};
	};

////////////M4A1 GRIPPOD VARIANTS////////

	class rhs_weap_m4a1_grip : rhs_weap_m4a1
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4A1_foreg;

		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4carryhandlegrip_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4a1_ris_grip1.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m16a4"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 65;
			class UnderBarrelSlot {};
		};
		baseWeapon="rhs_weap_m4a1_grip";
	};
	class rhs_weap_m4a1_carryhandle_grip : rhs_weap_m4a1_grip
	{
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4A1_CARRYHANDLE_foreg;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4carryhandlegrip_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4a1_ris_carryhandle_grip1.p3d";
		baseWeapon="rhs_weap_m4a1_carryhandle_grip";
	};
	class rhs_weap_m4a1_grip2 : rhs_weap_m4a1
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4A1_afg;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4carryhandlegrip_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4a1_ris_grip2.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1_afg.rtm"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 65;
			class UnderBarrelSlot {};
		};
		baseWeapon="rhs_weap_m4a1_grip2";
	};

	class rhs_weap_m4a1_carryhandle_grip2 : rhs_weap_m4a1_grip2
	{
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4A1_carryhandle_afg;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4carryhandlegrip_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4a1_ris_carryhandle_grip2.p3d";
		baseWeapon="rhs_weap_m4a1_carryhandle_grip2";
	};

	class rhs_weap_m4a1_bipod : rhs_weap_m4a1
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4A1_bipod;
		class LinkedItems
		{
			class LinkedItemsUnder
			{
				item = "rhsusf_acc_harris_bipod";
				slot = "UnderBarrelSlot";
			};
		};
	};
	class rhs_weap_m4a1_carryhandle_bipod : rhs_weap_m4a1_carryhandle
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4A1_BIPOD_CARRYHANDLE;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4carryhandlegrip_ca.paa";
		class LinkedItems
		{
			class LinkedItemsUnder
			{
				item = "rhsusf_acc_harris_bipod";
				slot = "UnderBarrelSlot";
			};
		};
	};
////////////M16A4////////
	class rhs_weap_m16a4 : rhs_weap_m4_Base
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M16A4;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m16a4ris_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M16\M16A4_ris.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1.rtm"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 71.72;
		};
		baseWeapon="rhs_weap_m16a4";
	};

	class rhs_weap_m16a4_carryhandle : rhs_weap_m16a4
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M16A4_carry;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m16a4riscarryhandle_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M16\M16A4_ris_carryhandle.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1.rtm"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 73.72;
		};
		baseWeapon="rhs_weap_m16a4_carryhandle";
	};

	class rhs_weap_m16a4_carryhandle_pmag : rhs_weap_m16a4
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M16A4_carryp;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m16a4riscarryhandle_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M16\M16A4_ris_carryhandle_pmag.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1.rtm"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 73.72;
		};
		baseWeapon="rhs_weap_m16a4_carryhandle_pmag";
	};

	class rhs_weap_m16a4_bipod : rhs_weap_m16a4
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M16A4_bipod;
		class LinkedItems
		{
			class LinkedItemsUnder
			{
				item = "rhsusf_acc_harris_bipod";
				slot = "UnderBarrelSlot";
			};
		};
	};

	class rhs_weap_m16a4_carryhandle_bipod : rhs_weap_m16a4_carryhandle
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M16A4_carry_bipod;
		class LinkedItems
		{
			class LinkedItemsUnder
			{
				item = "rhsusf_acc_harris_bipod";
				slot = "UnderBarrelSlot";
			};
		};
	};

	class rhs_weap_m16a4_grip : rhs_weap_m16a4
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M16A4_foreg;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m16a4risgrip_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M16\M16A4_ris_grip1.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m16a4"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 73.72;
		};
		baseWeapon="rhs_weap_m16a4_grip";
	};

	class rhs_weap_m16a4_carryhandle_grip : rhs_weap_m16a4
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M16A4_carry_foreg;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m16a4risgrip_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M16\M16A4_ris_carryhandle_grip1.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m16a4"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 73.72;
		};
		baseWeapon="rhs_weap_m16a4_carryhandle_grip";
	};

	class rhs_weap_m16a4_carryhandle_grip_pmag : rhs_weap_m16a4
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M16A4_carryp_foreg;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m16a4risgrip_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M16\M16A4_ris_carryhandle_pmag_grip1.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m16a4"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 73.72;
		};
		baseWeapon="rhs_weap_m16a4_carryhandle_grip_pmag";
	};

	class rhs_weap_m16a4_carryhandle_M203 : rhs_weap_m16a4
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M16A4_carry_M203;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m16a4riscarryhandle_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M16\M16A4_ris_carryhandle_M203.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m16a4_m203.rtm"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 73.72;
			class UnderBarrelSlot {};
		};
		muzzles[] = {"this","M203_GL"};
		inertia = 0.6;
		dexterity = 1.4;
		baseWeapon="rhs_weap_m16a4_carryhandle_M203";
	};



	class rhs_weap_m4_m320 : rhs_weap_m4_Base
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4_M320;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4m320_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4_ris_m320.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1_m320.rtm"};
		muzzles[] = {"this","M320_GL"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 103.72;
			class UnderBarrelSlot {};
		};
		inertia = 0.6;
		dexterity = 1.4;
		baseWeapon="rhs_weap_m4_m320";
	};
	class rhs_m4_m320 : rhs_weap_m4_m320
	{
		Author_Macro
		scope=1;
	};

	class rhs_weap_m4a1_m320 : rhs_weap_m4_Base
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4A1_M320;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4m320_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4a1_ris_m320.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1_m320.rtm"};

		modes[] =
		{
			"Single",
			"FullAuto",
			"single_medium_optics1",
			"single_far_optics2"
		};

		muzzles[] = {"this","M320_GL"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 98;
			class UnderBarrelSlot {};
		};
		inertia = 0.6;
		dexterity = 1.4;
		baseWeapon="rhs_weap_m4a1_m320";
	};
	class rhs_m4a1_m320 : rhs_weap_m4a1_m320
	{
		scope = 1;
		Author_Macro
	};

	class rhs_weap_mk18_m320 : rhs_weap_m4_Base
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_MK18_M320;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4m320_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M4BII\MK18_m320.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m4a1_m320.rtm"};

		modes[] =
		{
			"Single",
			"FullAuto",
			"single_medium_optics1",
			"single_far_optics2"
		};

		muzzles[] = {"this","M320_GL"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 98;
			class UnderBarrelSlot {};
		};
		inertia = 0.6;
		dexterity = 1.4;
	};

	class rhs_weap_m4_m203 : rhs_weap_m4_Base
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4_M203;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4m320_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4_ris_m203.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m16a4_m203.rtm"};
		muzzles[] = {"this","M203_GL"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 103.72;
			class UnderBarrelSlot {};
		};
		inertia = 0.6;
		dexterity = 1.4;
	};


	class rhs_weap_m4_m203S : rhs_weap_m4_Base
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4_M203S;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4m320_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4_ris_m203s.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m16a4_m203.rtm"};
		muzzles[] = {"this","M203_GL"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 103.72;
			class UnderBarrelSlot {};
		};
		inertia = 0.6;
		dexterity = 1.4;
	};

	class rhs_weap_m4a1_m203 : rhs_weap_m4_m203
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4A1_M203;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4m320_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4a1_ris_m203.p3d";

		modes[] =
		{
			"Single",
			"FullAuto",
			"single_medium_optics1",
			"single_far_optics2"
		};

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 98;
			class UnderBarrelSlot {};
		};
		inertia = 0.6;
		dexterity = 1.4;
	};

	class rhs_weap_m4a1_m203s : rhs_weap_m4_m203
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4A1_M203S;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4m320_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4a1_ris_m203s.p3d";

		modes[] =
		{
			"Single",
			"FullAuto",
			"single_medium_optics1",
			"single_far_optics2"
		};

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 98;
			class UnderBarrelSlot {};
		};
		inertia = 0.6;
		dexterity = 1.4;
	};

	class rhs_weap_m4a1_carryhandle_m203 : rhs_weap_m4_m203
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4A1_carryhandle_M203;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4m320_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4a1_ris_carryhandle_m203.p3d";

		modes[] =
		{
			"Single",
			"FullAuto",
			"single_medium_optics1",
			"single_far_optics2"
		};

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 98;
			class UnderBarrelSlot {};
		};
		inertia = 0.6;
		dexterity = 1.4;
	};

	class rhs_weap_m4a1_carryhandle_m203S : rhs_weap_m4_m203
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4A1_carryhandle_M203S;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4m320_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M4\m4a1_ris_carryhandle_m203s.p3d";

		modes[] =
		{
			"Single",
			"FullAuto",
			"single_medium_optics1",
			"single_far_optics2"
		};

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 98;
			class UnderBarrelSlot {};
		};
		inertia = 0.6;
		dexterity = 1.4;
	};

	class rhs_weap_m4a1_blockII_M203 : rhs_weap_m4_m203
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_M4A1BLII_M203;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m4m320_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M4BII\m4a1_blockII_M203.p3d";

		modes[] =
		{
			"Single",
			"FullAuto",
			"single_medium_optics1",
			"single_far_optics2"
		};

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 98;
			class UnderBarrelSlot {};
		};
		inertia = 0.6;
		dexterity = 1.4;
	};

////////////M249 VARIANTS////////
	class LMG_Mk200_F;
	class rhs_M249_base : LMG_Mk200_F
	{
		hasBipod = 1;
		scope = 0;
		UiPicture = "\A3\weapons_f\data\UI\icon_mg_CA.paa";
		magazines[] =
		{
			//rhs m249 mags
			"rhsusf_100Rnd_556x45_soft_pouch",
			"rhsusf_200Rnd_556x45_soft_pouch",
			"rhsusf_100Rnd_556x45_M200_soft_pouch",

			//rhs STANAG mags
			"rhs_mag_30Rnd_556x45_Mk318_Stanag",
			"rhs_mag_30Rnd_556x45_Mk262_Stanag",
			"rhs_mag_30Rnd_556x45_M855A1_Stanag",
			"rhs_mag_30Rnd_556x45_M855A1_Stanag_No_Tracer",
			"rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Red",
			"rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Green",
			"rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Yellow",
			"rhs_mag_30Rnd_556x45_M200_Stanag",

			//bis mags compatibility
			"30Rnd_556x45_Stanag",
			"30Rnd_556x45_Stanag_Tracer_Red",
			"30Rnd_556x45_Stanag_Tracer_Green",
			"30Rnd_556x45_Stanag_Tracer_Yellow"
		};
		reloadAction = "GestureReloadM200";


		cursor = "mg";
		cursorAim = "EmptyCursor";
		nameSound = "Mgun";

		maxRecoilSway = 0.0150;
		swayDecaySpeed = 1.25;
		opticsZoomMin = 0.375;
		opticsZoomMax = 1;
		opticsZoomInit = 0.75;
		distanceZoomMin = 300;
		distanceZoomMax = 300;
		dexterity = 2.8;

		discreteDistance[] = {100,200,300,400,500,600,700,800,900};
		discreteDistanceInitIndex = 2;

		descriptionShort = "M249 Squad automatic weapon";
		class Library
		{
			libTextDesc = "The M249 provides infantry squads with the heavy volume of fire of a machine gun combined with accuracy and portability approaching that of a rifle.";
		};
		class ItemInfo
		{
			priority = 1;
			RMBhint = "M249";
			onHoverText = "TODO M249 DSS";
		};

		class WeaponSlotsInfo
		{
			mass=165;
			allowedSlots[] = {901};
			class CowsSlot: rhs_western_rifle_scopes_slot_short {};
			class PointerSlot: rhs_western_rifle_laser_slot {};
		};

		class GunParticles : GunParticles
		{
			class M249_AmmoBeltLinkEject
			{
				positionName = "ammobeltlinks_start";
				directionName = "ammobeltlinks_end";
				effectName = "MachineGunEject2";
			};
			class M249_AmmoBeltCaseEject
			{
				positionName = "shelleject_start";
				directionName = "shelleject_end";
				//effectName = "RHSUSF_762Cartridge";
				effectName = "MachineGunCartridge2";
			};
			class M249_WhiteGas
			{
        		positionName = "usti hlavne";
        		directionName = "konec hlavne";
        		effectName = "MachineGunCloud";
        	};
			class M249_RHSUSF_BarrelRefract
			{
				positionName = "usti hlavne";
				directionName = "usti hlavne up";
				effectName = "RHSUSF_BarrelRefract";
			};
		};

		bullet1[] = {"A3\sounds_f\weapons\shells\5_56\metal_556_01.wss", 0.1, 1, 15};
		bullet2[] = {"A3\sounds_f\weapons\shells\5_56\metal_556_02.wss", 0.1, 1, 15};
		bullet3[] = {"A3\sounds_f\weapons\shells\5_56\metal_556_03.wss", 0.177828, 1, 15};
		bullet4[] = {"A3\sounds_f\weapons\shells\5_56\metal_556_04.wss", 0.177828, 1, 15};
		bullet5[] = {"A3\sounds_f\weapons\shells\5_56\asphlat_556_01.wss", 0.1, 1, 15};
		bullet6[] = {"A3\sounds_f\weapons\shells\5_56\asphlat_556_02.wss", 0.1, 1, 15};
		bullet7[] = {"A3\sounds_f\weapons\shells\5_56\asphlat_556_03.wss", 0.1, 1, 15};
		bullet8[] = {"A3\sounds_f\weapons\shells\5_56\asphlat_556_04.wss", 0.1, 1, 15};
		bullet9[] = {"A3\sounds_f\weapons\shells\5_56\grass_556_01.wss", 0.01, 1, 15};
		bullet10[] = {"A3\sounds_f\weapons\shells\5_56\grass_556_02.wss", 0.01, 1, 15};
		bullet11[] = {"A3\sounds_f\weapons\shells\5_56\grass_556_03.wss", 0.01, 1, 15};
		bullet12[] = {"A3\sounds_f\weapons\shells\5_56\grass_556_04.wss", 0.01, 1, 15};
		soundBullet[] = {"bullet1", 0.083, "bullet2", 0.083, "bullet3", 0.083, "bullet4", 0.083, "bullet5", 0.083, "bullet6", 0.083, "bullet7", 0.083, "bullet8", 0.083, "bullet9", 0.083, "bullet10", 0.083, "bullet11", 0.083, "bullet12", 0.083};

		drySound[] = {"A3\sounds_f\weapons\Other\dry_1",0.01,1};
		reloadMagazineSound[] = {"A3\sounds_f\weapons\reloads\new_MX",0.1,1,30};

		modes[]=
		{
			"FullAuto",
			"close",
			"short",
			"medium",
			"far_optic1",
			"far_optic2"
		};
		class FullAuto: Mode_FullAuto
		{
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="DefaultRifle";
				closure1[] = {"A3\sounds_f\weapons\closure\sfx7",1.4125376,1,40};
				closure2[] = {"A3\sounds_f\weapons\closure\sfx8",1.4125376,1,40};
				soundClosure[]=	{"closure1",0.5,"closure2",0.5};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[]={"A3\sounds_f\weapons\M200\Mk200_st_4a",1,1,1200};
				begin2[]={"A3\sounds_f\weapons\M200\Mk200_st_5a",1,1,1200};
				begin3[]={"A3\sounds_f\weapons\M200\Mk200_st_6a",1,1,1200};
				soundBegin[]={"begin1",0.333,"begin2",0.333,"begin3",0.333};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"A3\sounds_f\weapons\silenced\silent-18",0.79432821,1,100};
				begin2[]={"A3\sounds_f\weapons\silenced\silent-19",0.79432821,1,100};
				begin3[]={"A3\sounds_f\weapons\silenced\silent-11",0.79432821,1,100};
				soundBegin[]={"begin1",0.333,"begin2",0.333,"begin3",0.333};
			};
			//
			reloadTime = 0.075;
			dispersion = 0.00101;
			//
			recoil="recoil_auto_mk200";
			recoilProne="recoil_auto_prone_mk200";
			//
			minRange = 0;
			minRangeProbab = 0.3;
			midRange = 5;
			midRangeProbab = 0.7;
			maxRange = 10;
			maxRangeProbab = 0.04;
		};
		class close: FullAuto
		{
			burst=10;
			aiRateOfFire=0.5;
			aiRateOfFireDistance=50;
			minRange=0;
			minRangeProbab=0.05;
			midRange=30;
			midRangeProbab=0.69;
			maxRange=50;
			maxRangeProbab=0.039;
			showToPlayer=0;
		};
		class short: close
		{
			burst=8;
			aiRateOfFire=2;
			aiRateOfFireDistance=300;
			minRange=50;
			minRangeProbab=0.05;
			midRange=150;
			midRangeProbab=0.69;
			maxRange=300;
			maxRangeProbab=0.039;
		};
		class medium: close
		{
			burst=5;
			aiRateOfFire=4;
			aiRateOfFireDistance=600;
			minRange=200;
			minRangeProbab=0.05;
			midRange=400;
			midRangeProbab=0.60000002;
			maxRange=600;
			maxRangeProbab=0.1;
		};
		class far_optic1: close
		{
			requiredOpticType=1;
			showToPlayer=0;
			burst=3;
			aiRateOfFire=9;
			aiRateOfFireDistance=900;
			minRange=350;
			minRangeProbab=0.039;
			midRange=550;
			midRangeProbab=0.5;
			maxRange=700;
			maxRangeProbab=0.0098;
		};
		class far_optic2: far_optic1
		{
			requiredOpticType=2;
			autoFire=0;
			burst=1;
			minRange=400;
			minRangeProbab=0.05;
			midRange=800;
			midRangeProbab=0.5;
			maxRange=1000;
			maxRangeProbab=0.0098;
		};
		inertia=0.8;
	};

	class rhs_weap_m249_pip: rhs_M249_base
	{
		scope = 2;
		Author_Macro
		displayName = "M249 PIP";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m249.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M249\m249_pip.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_mk12.rtm"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 155;
		};
	};

	class weap_m240_base : rhs_M249_base
	{
		scope = 0;
		model="\rhsusf\addons\rhsusf_weapons\M240\M240B.p3d";
		picture="";
		UiPicture="";
		displayName = "M240B";

		cursor = "mg";
		cursorAim = "EmptyCursor";
		nameSound = "Mgun";

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=100;
			class PointerSlot {};
		};

		class GunParticles : GunParticles
		{
			class M240_AmmoBeltLinkEject
			{
				positionName = "ammobeltlinks_start";
				directionName = "ammobeltlinks_end";
				effectName = "MachineGunEject2";
			};
			class M240_AmmoBeltCaseEject
			{
				positionName = "shelleject_start";
				directionName = "shelleject_end";
				//effectName = "RHSUSF_762Cartridge";
				effectName = "MachineGunCartridge1";
			};
			class M240_WhiteGas
			{
        		positionName = "usti hlavne";
        		directionName = "konec hlavne";
        		effectName = "MachineGunCloud";
        	};
			class M240_RHSUSF_BarrelRefract
			{
				positionName = "usti hlavne";
				directionName = "usti hlavne up";
				effectName = "RHSUSF_BarrelRefractHeavy";
			};
		};

		modes[]=
		{
			"manual",
			"close",
			"short",
			"medium",
			"far"
		};

		class manual: Mode_FullAuto
		{
			// reloadTime = 0.0075;
			recoil = "recoil_auto_machinegun_8outof10";
			recoilProne = "recoil_auto_machinegun_prone_5outof10";
			dispersion=0.0008; // 0.0038;


			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="DefaultRifle";
				closure1[] = {"A3\sounds_f\weapons\closure\sfx7",1.4125376,1,40};
				closure2[] = {"A3\sounds_f\weapons\closure\sfx8",1.4125376,1,40};
				soundClosure[]=	{"closure1",0.5,"closure2",0.5};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[]={"A3\sounds_f\weapons\M200\Mk200_st_4a",1,1,1200};
				begin2[]={"A3\sounds_f\weapons\M200\Mk200_st_5a",1,1,1200};
				begin3[]={"A3\sounds_f\weapons\M200\Mk200_st_6a",1,1,1200};
				soundBegin[]={"begin1",0.333,"begin2",0.333,"begin3",0.333};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"A3\sounds_f\weapons\silenced\silent-18",0.79432821,1,100};
				begin2[]={"A3\sounds_f\weapons\silenced\silent-19",0.79432821,1,100};
				begin3[]={"A3\sounds_f\weapons\silenced\silent-11",0.79432821,1,100};
				soundBegin[]={"begin1",0.333,"begin2",0.333,"begin3",0.333};
			};

			soundContinuous = 0;
			soundBurst = false;
			minRange=0;minRangeProbab=0.30;
			midRange=5;midRangeProbab=0.58;
			maxRange=10;maxRangeProbab=0.04;
			showToPlayer = true;
		};

		class close: manual
		{
			burst = 10;
			aiRateOfFire = 0.5;
			aiRateOfFireDistance = 50;
			minRange=10;minRangeProbab=0.05;
			midRange=20;midRangeProbab=0.58;
			maxRange=50;maxRangeProbab=0.04;
			showToPlayer = false;
		};

		class short: close
		{
			burst = 8; //Rg 6;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 300; //Rg 200;
			minRange=50;minRangeProbab=0.05;
			midRange=150;midRangeProbab=0.58; //Rg 100;
			maxRange=300;maxRangeProbab=0.04; //Rg 200;
		};

		class medium: close
		{
			burst = 12; //Rg 8;
			aiRateOfFire = 3; //Rg 4;
			aiRateOfFireDistance = 600; //Rg 400;
			minRange=200;minRangeProbab=0.05;
			midRange=400;midRangeProbab=0.58; //Rg 300;
			maxRange=600;maxRangeProbab=0.04; //Rg 400;
		};

		class far: close
		{
			burst = 16; //Rg 7;
			aiRateOfFire = 5; //Rg 7;
			aiRateOfFireDistance = 1000; //Rg 600;
			minRange=400;minRangeProbab=0.05;
			midRange=600;midRangeProbab=0.4; //Rg 500;
			maxRange=900;maxRangeProbab=0.01; //Rg 600;
		};
		aiDispersionCoefY=21.0;
		aiDispersionCoefX=21.0;

		inertia=0.9;
		dexterity = 0.51;

		magazines[]=
		{
			rhsusf_50Rnd_762x51,
			rhsusf_50Rnd_762x51_m993,
			rhsusf_50Rnd_762x51_m80a1epr,
			rhsusf_100Rnd_762x51,
			rhsusf_100Rnd_762x51_m993,
			rhsusf_100Rnd_762x51_m80a1epr
		};

		descriptionShort = "M240B General Purpose Machine Gun";
		class Library
		{
			libTextDesc = "The M240 is the US military designation for the FN MAG, a family of belt-fed, gas-operated medium machine guns.";
		};
	};

	class rhs_weap_m240B : weap_m240_base
	{
		scope = 2;
		Author_Macro
		displayName = "M240B";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m240_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M240\M240B.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m240.rtm"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 275;
		};
	};

	class rhs_weap_m240G : rhs_weap_m240B
	{
		scope = 2;
		Author_Macro
		displayName = "M240G";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m240_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M240\M240G.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m240.rtm"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 275;
		};
	};

	class rhs_weap_m240B_CAP : rhs_weap_m240B
	{
		scope = 2;
		Author_Macro
		displayName = "M240B (CAP)";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m240_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\M240\m240B_CAP.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m240.rtm"};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 275;
		};
	};

	class rhs_weap_m14ebrri : srifle_EBR_F
	{
		scope = 2;
		Author_Macro
		displayName = "M14 EBR-RI";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m14ebr_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\MK14\MK14.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_mk12.rtm"};

		magazines[] = {rhsusf_20Rnd_762x51_m118_special_Mag,rhsusf_20Rnd_762x51_m993_Mag};

		 htMin = 1;
		htMax = 420;
		afMax = 0;
		mfMax = 0;
		mFact = 1;
		tBody = 100;

		dexterity = 1.53;
		reloadTime=2;
		//backgroundReload = 1;
		reloadAction="RHS_GestureReloadM14";
		modes[] =
		{
			"Single",
			"single_close_optics1",
			"single_medium_optics1",
			"single_far_optics1"
		};

		class GunParticles : GunParticles
		{
			class SecondEffect
			{
				positionName = "Nabojnicestart";
				directionName = "Nabojniceend";
				effectName = "RifleAssaultCloud";
			};
			class RHSUSF_BarrelRefract
			{
				positionName = "usti hlavne";
				directionName = "usti hlavne up";
				effectName = "RHSUSF_BarrelRefract";
			};
		};

		class WeaponSlotsInfo
		{
			mass = 112;
			allowedSlots[] = {901};
			class CowsSlot: rhs_western_rifle_scopes_slot_long {};
			class PointerSlot: rhs_western_rifle_laser_slot {};
			class UnderBarrelSlot: rhs_western_rifle_underbarrel_slot {};
		};

		class Single: Mode_SemiAuto
		{
			sounds[]={"StandardSound"};
			class StandardSound
			{
				weaponSoundEffect="DefaultRifle";

				closure1[] = {"A3\sounds_f\weapons\closure\ebr-3",1.1220185,1.2,30};
				closure2[] = {"A3\sounds_f\weapons\closure\ebr-3",1.1220185,1,30};
				soundClosure[]=	{"closure1",0.5,"closure2",0.5};

				begin1[]={"A3\sounds_f\weapons\EBR\EBR_st_4",1,1,1200};
				begin2[]={"A3\sounds_f\weapons\EBR\EBR_st_5",1,1,1200};
				begin3[]={"A3\sounds_f\weapons\EBR\EBR_st_6",1,1,1200};
				soundBegin[]=	{"begin1",0.34,"begin2",0.33,"begin3",0.33};
			};
			dispersion=0.00045;
			recoil="recoil_single_ebr";
			recoilProne="recoil_single_prone_ebr";
			minRange=2;
			minRangeProbab=0.3;
			midRange=350;
			midRangeProbab=0.7;
			maxRange=500;
			maxRangeProbab=0.05;
			displayName = "";

		};
		class single_close_optics1: Single
		{
			requiredOpticType=1;
			showToPlayer=0;
			minRange=2;
			minRangeProbab=0.05;
			midRange=300;
			midRangeProbab=0.8;
			maxRange=500;
			maxRangeProbab=0.01;
			aiRateOfFire=2;
			aiRateOfFireDistance=300;
		};
		class single_medium_optics1: single_close_optics1
		{
			minRange=300;
			minRangeProbab=0.05;
			midRange=500;
			midRangeProbab=0.7;
			maxRange=700;
			maxRangeProbab=0.05;
			aiRateOfFire=2;
			aiRateOfFireDistance=500;
		};
		class single_far_optics1: single_medium_optics1
		{
			requiredOpticType=2;
			minRange=300;
			minRangeProbab=0.05;
			midRange=600;
			midRangeProbab=0.4;
			maxRange=900;
			maxRangeProbab=0.05;
			aiRateOfFire=4;
			aiRateOfFireDistance=600;
		};
	};
	class rhs_weap_sr25 : rhs_weap_m14ebrri
	{
		Author_Macro
		displayName = $STR_RHS_CFGWEAPONS_RIFLE_SR25M;
		descriptionShort="Sniper rifle <br/>Caliber: 7.62x51 mm NATO";
		class Library
		{
			libTextDesc="An SR 25 rifle manufactured by Knights Armament company";
		};

		model="\rhsusf\addons\rhsusf_weapons\sr25\SR25.p3d";
		picture="\rhsusf\addons\rhsusf_weapons\SR25\Data\gear\sr25_x_ca.paa";

		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_mk12.rtm"};
		reloadAction="RHS_GestureReloadSR25";

		magazines[] = {rhsusf_20Rnd_762x51_m118_special_Mag,rhsusf_20Rnd_762x51_m993_Mag};

		dexterity = 1.53;
		reloadTime=2;

		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass = 107;
			class CowsSlot: rhs_western_rifle_scopes_slot_long {};
			class PointerSlot: rhs_western_rifle_laser_slot {};
			class MuzzleSlot: SlotInfo
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]=
				{
					"rhsusf_acc_sr25S"
				};
			};
		};


		class Single: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="DefaultRifle";
				closure1[]={"A3\sounds_f\weapons\closure\closure_rifle_6",0.40794575,1,10};
				closure2[]={"A3\sounds_f\weapons\closure\closure_rifle_7",0.40794575,1,10};
				soundClosure[]={"closure1",	0.5,"closure2",0.5};
			};
			class StandardSound
			{
				weaponSoundEffect="DefaultRifle";
				soundClosure[]=	{};

				begin1[]={"rhsusf\addons\rhsusf_sounds\m14\M14_1",2.3,1,1400};
				begin2[]={"rhsusf\addons\rhsusf_sounds\m14\M14_2",2.3,1,1400};
				soundBegin[]={"begin1",0.5,"begin2",0.5};
			};
			class SilencedSound: BaseSoundModeType
			{
				begin1[]={"rhsusf\addons\rhsusf_weapons\sr25\Data\sounds\suppressed",1.6,	1,400};
				soundBegin[]={"begin1",0.333};
			};
			reloadTime=0.096;
			dispersion=0.00028;
			recoil="recoil_single_ebr";
			recoilProne="recoil_single_prone_ebr";
			minRange=2;
			minRangeProbab=0.3;
			midRange=350;
			midRangeProbab=0.7;
			maxRange=500;
			maxRangeProbab=0.05;
			displayName = "";

		};
		class single_close_optics1: Single
		{
			requiredOpticType=1;
			showToPlayer=0;
			minRange=2;
			minRangeProbab=0.05;
			midRange=300;
			midRangeProbab=0.8;
			maxRange=500;
			maxRangeProbab=0.01;
			aiRateOfFire=2;
			aiRateOfFireDistance=300;
		};
		class single_medium_optics1: single_close_optics1
		{
			minRange=300;
			minRangeProbab=0.05;
			midRange=500;
			midRangeProbab=0.7;
			maxRange=700;
			maxRangeProbab=0.05;
			aiRateOfFire=2;
			aiRateOfFireDistance=500;
		};
		class single_far_optics1: single_medium_optics1
		{
			requiredOpticType=2;
			minRange=300;
			minRangeProbab=0.05;
			midRange=600;
			midRangeProbab=0.4;
			maxRange=900;
			maxRangeProbab=0.05;
			aiRateOfFire=4;
			aiRateOfFireDistance=600;
		};
	};
class rhs_weap_sr25_ec : rhs_weap_sr25
{
	displayName = $STR_RHS_CFGWEAPONS_RIFLE_SR25EC;
	class Library
	{
		libTextDesc="An SR 25 EC rifle manufactured by Knights Armament company";
	};
	model="\rhsusf\addons\rhsusf_weapons\sr25\SR25_ec.p3d";
	picture="\rhsusf\addons\rhsusf_weapons\sr25\Data\gear\sr25ec_x_ca.paa";
	handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_mk12.rtm"};
};

class rhs_weap_m110: rhs_weap_sr25
{
	displayName = $STR_RHS_CFGWEAPONS_RIFLE_M110;
	scope = 1;
};

class rhs_weap_M107_Base_F: Rifle_Base_F
{
	magazines[] = {"rhsusf_10Rnd_STD_50BMG_M107"};

	// TODO: Librbary description required
	class Library
	{
		libTextDesc = "";
	};

	optics = 0;

	reloadAction = "GestureReloadLRR";
	maxRecoilSway = 0.0125;
	swayDecaySpeed = 1.25;

	class GunParticles : GunParticles
	{
		class SecondEffect
		{
			positionName = "Nabojnicestart";
			directionName = "Nabojniceend";
			effectName = "RifleAssaultCloud";
		};
		class RHSUSF_BarrelRefract
		{
			positionName = "usti hlavne";
			directionName = "usti hlavne up";
			effectName = "RHSUSF_BarrelRefract";
		};
	};

	weaponInfoType = "RscWeaponZeroing";
	discreteDistance[] = {100,200,400,600,800,1000,1200,1400};
	discreteDistanceInitIndex = 0;

 	class WeaponSlotsInfo: WeaponSlotsInfo
	{
		class CowsSlot: rhs_western_rifle_scopes_slot_long {};
	};

	opticsZoomMin = 0.375;
	opticsZoomMax = 1.1;
	opticsZoomInit = 0.75;
	distanceZoomMin = 300;
	distanceZoomMax = 300;

	descriptionShort = $STR_A3_CfgWeapons_XM_base_F0;
	handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_M107.rtm"};
	dexterity = 1.8;
	caseless[] = {"",1,1,1};

	soundBullet[] = {"caseless",1};
	modes[]=
	{
		"Single",
		"far_optic1",
		"medium_optic2",
		"far_optic2"
	};

	class Single: Mode_SemiAuto
	{
		sounds[]={"StandardSound"};
		class StandardSound
		{
			weaponSoundEffect="DefaultRifle";

			begin1[] = {"A3\sounds_f\weapons\M320\M320_st_1",1.4125376,1,1200};
			begin2[] = {"A3\sounds_f\weapons\M320\M320_st_2",1.4125376,1,1200};
			soundBegin[] = {"begin1",0.5,"begin2",0.5};

			closure1[] = {"A3\sounds_f\weapons\closure\closure_rifle_6.wss",3.1622777,1,300};
			closure2[] = {"A3\sounds_f\weapons\closure\closure_rifle_7.wss",3.1622777,1,300};
			soundClosure[] = {"closure1",0.5,"closure2",0.5};
		};
		reloadTime = 1.6;
		recoil="recoil_single_gm6";
		recoilProne="recoil_single_prone_gm6";
		//MOA <=1
		dispersion = 0.0002909;
		minRange = 2;
		minRangeProbab = 0.3;
		midRange = 250;
		midRangeProbab = 0.7;
		maxRange = 400;
		maxRangeProbab = 0.04;
	};
	class far_optic1: Single
	{
		showToPlayer=0;
		minRange=150;
		minRangeProbab=0.1;
		midRange=500;
		midRangeProbab=0.7;
		maxRange=1000;
		maxRangeProbab=0.3;
		aiRateOfFire=5;
		aiRateOfFireDistance=700;
		requiredOpticType=1;
	};
	class medium_optic2: Single
	{
		showToPlayer=0;
		minRange=250;
		minRangeProbab=0.1;
		midRange=750;
		midRangeProbab=0.7;
		maxRange=1000;
		maxRangeProbab=0.3;
		aiRateOfFire=6;
		aiRateOfFireDistance=1000;
		requiredOpticType=2;
	};
	class far_optic2: far_optic1
	{
		minRange=500;
		minRangeProbab=0.1;
		midRange=1050;
		midRangeProbab=0.7;
		maxRange=2000;
		maxRangeProbab=0.3;
		aiRateOfFire=8;
		aiRateOfFireDistance=2000;
		requiredOpticType=2;
	};

	aiDispersionCoefY = 10;
	aiDispersionCoefX = 8;
	drySound[] = {"A3\sounds_f\weapons\Other\dry_1",0.01,1};

	reloadMagazineSound[] = {"A3\sounds_f\weapons\M320\M320_reload",0.1,1,30};
	hiddenSelections[] = {"Camo"};
	hiddenSelectionsTextures[] = {"\rhsusf\addons\rhsusf_weapons\M107\Data\M107_co.paa"};

};

class rhs_weap_M107 : rhs_weap_M107_Base_F
	{
		scope = 0;
		displayName = "M107";
		class Library
		{
			libTextDesc="An SR 25 EC rifle manufactured by Knights Armament company";
		};

		model="\rhsusf\addons\rhsusf_weapons\M107\M107.p3d";
		picture="\rhsusf\addons\rhsusf_weapons\sr25\Data\gear\gear_sr25ec_x_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_M107.rtm"};
	};

// Shotguns
	class rhs_weap_M590_5RD : Rifle_Base_F
	{
		scope = 2;
		model = "\rhsusf\addons\rhsusf_weapons\M590A1\M590_5MAG";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m590.rtm"};
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m590s_ca.paa";
		magazines[] = {rhsusf_5Rnd_00Buck,rhsusf_5rnd_doomsday_buck,rhsusf_5Rnd_Slug,rhsusf_5Rnd_HE,rhsusf_5Rnd_FRAG};
		optics = 1;
		modelOptics = "-";
		displayname = "M590A1 (Short)";
		Author_Macro
		modes[] = {"Single"};
		distanceZoomMin=50;
		distanceZoomMax=50;

		class Single: Mode_SemiAuto
		{
			sounds[]={"StandardSound"};
			class StandardSound
			{
				weaponSoundEffect="DefaultRifle";

				closure1[] = {"A3\sounds_f\weapons\closure\ebr-3",1.1220185,1.2,30};
				closure2[] = {"A3\sounds_f\weapons\closure\ebr-3",1.1220185,1,30};
				soundClosure[]=	{"closure1",0.5,"closure2",0.5};

				begin1[]={"A3\sounds_f\weapons\EBR\EBR_st_4",1,1,1200};
				begin2[]={"A3\sounds_f\weapons\EBR\EBR_st_5",1,1,1200};
				begin3[]={"A3\sounds_f\weapons\EBR\EBR_st_6",1,1,1200};
				soundBegin[]=	{"begin1",0.34,"begin2",0.33,"begin3",0.33};
			};
			reloadTime=0.5;
		};
		inertia = 0.5;
		dexterity = 1.5;
		fireSpreadAngle=0.95;
		class WeaponSlotsInfo
		{
			allowedSlots[] = {901};
			mass = 97;
		};
	};

	class rhs_weap_M590_8RD : rhs_weap_M590_5RD
	{
		model = "\rhsusf\addons\rhsusf_weapons\M590A1\M590_8MAG";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m590L_ca.paa";
		magazines[] = {rhsusf_8Rnd_00Buck,rhsusf_8rnd_doomsday_buck,rhsusf_8Rnd_Slug,rhsusf_8Rnd_HE,rhsusf_8Rnd_FRAG};
		displayname = "M590A1 (Long)";
		Author_Macro

		class Single: Single {};
		inertia = 0.6;
		dexterity = 1.4;
	};