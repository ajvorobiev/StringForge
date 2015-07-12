

class rhs_weap_M136 : Launcher_Base_F
{
	scope = 2;
	Author_Macro
	displayName = "M136 (HEAT)";
	descriptionShort = "84mm, single-shot weapon.";
	picture = "\rhsusf\addons\rhsusf_weapons\icons\w_m136_launcher_ca.paa";

	rhs_disposable=1;
	magazineReloadTime=1;

	model = "rhsusf\addons\rhsusf_weapons\M136\at4";
	modelOptics = "-";

	class GunParticles
	{
		class effect1
		{
			positionName = "konec hlavne";
			directionName = "usti hlavne";
			effectName = "RHS_Fired_M136HEAT";
		};
	};

	magazines[] = {rhs_m136_mag};
	reloadAction = "ReloadRPG";
	handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_m136.rtm"};

	 sounds[] = {StandardSound};
	 class StandardSound
	 {
		weaponSoundEffect = "DefaultRifle";
		begin1[] = {"A3\Sounds_F\weapons\Launcher\rpg32",1.99526,1,900};
		soundBegin[]={"begin1",1};
	};
	drySound[] = {"A3\sounds_f\weapons\other\dry6",0.0316228,1,10};
	reloadMagazineSound[] = {"A3\sounds_f\weapons\rockets\titan_reload_final",0.562341,1,50};
	soundFly[] = {"A3\sounds_f\weapons\rockets\rocket_fly_1",0.316228,1.5,700};

	recoil = "recoil_single_law";
	minRange = 10;
	minRangeProbab = 0.9;
	midRange = 200;
	midRangeProbab = 0.7;
	maxRange = 300;
	maxRangeProbab = 0.1;
	aiRateOfFire = 7;
	aiRateOfFireDistance = 300;

	weaponInfoType = "rhs_rscOptics_at4";

	optics=1;
	class OpticsModes
	{
		class ironsight
		{
			opticsID=2;
			opticsPPEffects[]=
			{
				"OpticsCHAbera1",
				"OpticsBlur1"
			};
			useModelOptics=0;
			opticsFlare=0;
			opticsDisablePeripherialVision=0;
			opticsZoomMin=0.35;
			opticsZoomMax=0.6;
			opticsZoomInit=0.6;
			visionMode="";
			discreteDistanceInitIndex=0;
			discreteDistance[] = {100,150,200,250,300,350,400};
			discreteDistanceCameraPoint[] = {"eye","OP_eye1","OP_eye2","OP_eye3","OP_eye4","OP_eye5","OP_eye6"};
			cameraDir="op_look";
			distanceZoomMin=100;
			distanceZoomMax=100;
		};
	};

	class Library
	{
		libTextDesc = "The M136 is a Swedish disposable anti-tank rocket launcher licensed and manufactured by the United States.";
	};
	class WeaponSlotsInfo : WeaponSlotsInfo
	{
		mass = 130;
		class PointerSlot
		{
			linkProxy = "\A3\data_f\proxies\weapon_slots\Side";
			compatibleItems[] = {"rhs_acc_at4_handler"};
		};
	};
	class ItemInfo
	{
		priority = 3;
		RMBhint = "M136";
		onHoverText = "M136";
	};
};

class rhs_weap_M136_hedp :  rhs_weap_M136
{
	Author_Macro
	displayName = "M136 (HEDP)";
	magazines[] = {rhs_m136_hedp_mag};
	class GunParticles
	{
		class effect1
		{
			positionName = "konec hlavne";
			directionName = "usti hlavne";
			effectName = "RHS_Fired_M136HEDP";
		};
	};
};
class rhs_weap_M136_hp :  rhs_weap_M136
{
	Author_Macro
	displayName = "M136 (HP)";
	magazines[] = {rhs_m136_hp_mag};
	class GunParticles
	{
		class effect1
		{
			positionName = "konec hlavne";
			directionName = "usti hlavne";
			effectName = "RHS_Fired_M136HP";
		};
	};
};

class rhs_weap_M136_used : rhs_weap_M136
{
	scope=1;
	descriptionshort = "Used launcher tube";
	displayname = "M136 HEAT (used)";
	magazines[]={rhs_launcher_dummy_mag};
};
class rhs_weap_M136_hedp_used : rhs_weap_M136_used
{
	displayname = "M136 HEDP (used)";
};
class rhs_weap_M136_hp_used : rhs_weap_M136_used
{
	displayname = "M136 HP (used)";
};



class launch_O_Titan_F;
	class rhs_weap_fim92 : launch_O_Titan_F
	{
		scope = 2;
		displayName="FIM-92F";
		Author_Macro
		model = "\rhsusf\addons\rhsusf_weapons\FIM92\stinger_launcher";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\w_fim92_ca.paa";
		modelOptics = "-";
		magazines[]={rhs_fim92_mag};

	shotPos = "usti hlavne";
	shotEnd = "konec hlavne";
	cmimmunity=0.96;

		handAnim[]={"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\rhs_hand_fim92.rtm"};

	 	sounds[] = {StandardSound};
	 	class StandardSound
	 	{
			weaponSoundEffect = "DefaultRifle";
			begin1[] = {"A3\Sounds_F\weapons\Launcher\rpg32",1.99526,1,900};
			soundBegin[]={"begin1",1};
		};
		drySound[] = {"A3\sounds_f\weapons\other\dry6",0.0316228,1,10};
		reloadMagazineSound[] = {"A3\sounds_f\weapons\rockets\titan_reload_final",0.562341,1,50};
		soundFly[] = {"A3\sounds_f\weapons\rockets\rocket_fly_1",0.316228,1.5,700};

	class OpticsModes
	{
		class StepScope
		{
			opticsID = 1;
			useModelOptics = 1;
			opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
			opticsFlare = 1;
			opticsZoomMin = 0.375;
			opticsZoomMax = 1.1;
			opticsZoomInit = 0.75;
			distanceZoomMin = 300;
			distanceZoomMax = 300;
			memoryPointCamera = "eye";
			cameraDir = "";
			visionMode[] = {"Normal"};
			thermalMode[] = {};
			opticsDisablePeripherialVision = 1;
		};
	};

		value = 20;
		canLock=2;
		recoil = "recoil_single_law";
		reloadAction = "ReloadRPG";

		minRange=10;minRangeProbab=0.30;
		midRange=2500;midRangeProbab=0.8;
		maxRange=4800;maxRangeProbab=0.10;
		aiRateOfFire=5.0;
		aiRateOfFireDistance=2500;

	weaponInfoType = "RscWeaponZeroing";


		class Library {libTextDesc = "The FIM-92 Stinger is a personal portable infrared homing surface-to-air missile (SAM), which can be adapted to fire from ground vehicles or helicopters (as an AAM), developed in the United States and entered into service in 1981.";};
		descriptionShort = "Stinger";
	};


	class rhs_weap_fgm148: launch_O_Titan_F
	{
		scope = 2;
		AGM_enableTopDownAttack = 1;
		Author_Macro
		displayName = "FGM-148 Javelin";
		descriptionShort = "SHORT DESCRIPTION";
		picture = "\rhsusf\addons\rhsusf_weapons\FGM148\data\UI\w_fgm148_ca.paa";
		
		model = "\rhsusf\addons\rhsusf_weapons\FGM148\fgm148_clu_loaded";
		handAnim[] = {"OFP2_ManSkeleton","\rhsusf\addons\rhsusf_c_weapons\anims\anim_fgm148.rtm"};
		
		magazines[] = {rhs_fgm148_magazine_AT};
		magazineReloadTime = 12;
		reloadTime = 0.5;
		initSpeed = 10;
		autoReload = 0;
		
		shotPos = "usti hlavne";
		shotEnd = "konec hlavne";

		ffMagnitude = 0.1;
		ffFrequency = 1;
		ffCount = 1;


		dexterity = 1.7;

/////////////////////////////////////////////////////////////////////////////
		class Library
		{
			libTextDesc = "LONG DESCRIPTION FOR THE MISSILE LAUNCHER";
		};
		class ItemInfo
		{
			priority = 3;
			RMBhint = "FGM-148";
			onHoverText = "TODO FGM148 DSS";
		};

		optics = 1;
		forceoptics = 0;
		lockAcquire = 0;
		autoAimEnabled = 0;
		canLock = 2;
		weaponLockDelay = 2.5;
		//weaponLockSystem = [0-15];
		opticsZoomMin = 0.025;
		opticsZoomMax = 0.95;
		opticsZoomInit = 0.42;
		opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};

		/*modelOptics = "\rhsusf\addons\rhsusf_weapons\FGM148\fgm148_interface";
		class OpticsModes
		{
			class StepScope
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsFlare = 0;
				opticsDisablePeripherialVision = 1;
				opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
				//
				opticsZoomMin = 0.08333;
				opticsZoomMax = 0.04167;
				//
				opticsZoomInit = 0.08333;
				//
				discretefov[] = {0.08333,0.04167};
				discreteInitIndex = 0;
				//
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				//
				memoryPointCamera = "eye";
				cameraDir = "look";
				//
				visionMode[] = {"Normal","NVG","Ti"};
				thermalMode[] = {0,1};
			};
		};*/

		aiRateOfFire = 10.0;
		aiRateOfFireDistance = 500;
		minRange = 65;
		minRangeProbab = 0.30;
		midRange = 1000;
		midRangeProbab = 0.58;
		maxRange = 2500;
		maxRangeProbab = 0.04;
	};