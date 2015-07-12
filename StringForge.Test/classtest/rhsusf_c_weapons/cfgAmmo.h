class CfgAmmo
{
	class BulletBase; 
	class RocketBase;
	class F_40mm_White;
	class F_40mm_Green;
	class F_40mm_Red;
	
	///! Rifle bullets
/*
MK 248 MOD 1 .300 (14.26 g)
*/
	class rhsusf_B_300winmag: BulletBase
	{
		hit = 18.5;
		indirectHit = 0;
		indirectHitRange = 0;
		cost = 1;
		airFriction = -0.0007034;
		caliber = 0.79;
		model = "\A3\Weapons_f\Data\bullettracer\tracer_yellow";
		tracerScale = 1;
		tracerStartTime = 0.05;
		tracerEndTime = 1;
		typicalSpeed = 869;
	};

	class rhsusf_M33_Ball_M107: BulletBase
	{
		hit = 48.58;
		indirectHit = 0.0;
		indirectHitRange = 0;
		cost = 1;
		airFriction = -0.0005685999999999694;
		caliber = 0.85;
		model = "\A3\Weapons_f\Data\bullettracer\tracer_yellow";
		tracerScale = 1;
		tracerStartTime = 0.05;
		tracerEndTime = 1;
		typicalSpeed = 853;
	};

	class B_556x45_Ball;
	class rhs_ammo_556x45_M855A1_Ball : B_556x45_Ball
	{
		hit = 9;
		typicalSpeed = 960;
		airFriction = -0.000772;
		caliber = 0.65;
		deflecting = 21;
		visibleFire = 3;
		audibleFire = 7;
		model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
	};
	class rhs_ammo_556x45_M855A1_Ball_Red : rhs_ammo_556x45_M855A1_Ball
	{
		model = "\A3\Weapons_f\Data\bullettracer\tracer_red";
		nvgOnly = 0;
	};
	class rhs_ammo_556x45_M855A1_Ball_Green : rhs_ammo_556x45_M855A1_Ball_Red
	{
		model = "\A3\Weapons_f\Data\bullettracer\tracer_green";
	};
	class rhs_ammo_556x45_M855A1_Ball_Yellow : rhs_ammo_556x45_M855A1_Ball_Red
	{
		model = "\A3\Weapons_f\Data\bullettracer\tracer_yellow";
	};

	class rhs_ammo_556x45_Mk318_Ball : B_556x45_Ball 
	{
		hit = 9.55;
		typicalSpeed = 950;
		airFriction = -0.00076;
		caliber = 0.64;
		deflecting = 17;
		visibleFire = 3;
		audibleFire = 5.5;
	};
	class rhs_ammo_556x45_Mk262_Ball : B_556x45_Ball 
	{
		hit = 10.3;
		typicalSpeed = 838.2;
		airFriction = -0.00066;
		caliber = 0.677;
		deflecting = 15;
		visibleFire = 2.5;
		audibleFire = 5;
	};
	//http://www.gunshopfinder.com/springfield-m1a-ballistics.html
	//http://www.inetres.com/gp/military/infantry/rifle/762mm_ammo.html
	//worth to note that army is currently upgrading to M80A1
	class rhs_ammo_556x45_blank : B_556x45_Ball 
	{
		hit = 0;
		typicalSpeed = 0.1;
		airFriction = -0.00066;
		caliber = 0.677;
		deflecting = 15;
		visibleFire = 0;
		visiblefiretime = 0;
		audibleFire = 0;
		cost = 0.1;
		bulletfly[] = {};
		hitMan[] = {};
		hitarmor[] = {};
		hitbuilding[] = {};
		hitconcrete[] = {};
		hitdefault[] = {};
		hitfoliage[] = {};
		hitglass[] = {};
		hitglassarmored[] = {};
		hitgroundhard[] = {};
		hitgroundsoft[] = {};
		hitiron[] = {};
		hitmetal[] = {};
		hitmetalplate[] = {};
		hitplastic[] = {};
		hitrubber[] = {};
		hitwood[] = {};
		hitground[] = {};
		class HitEffects
		{
			hit_blood = "";
			hit_concrete = "";
			hit_foliage = "";
			hit_foliage_green = "";
			hit_glass = "";
			hit_glass_thin = "";
			hit_metal = "";
			hit_plaster = "";
			hit_rubber = "";
			hit_wood = "";
		};
		
	};
	class rhs_ammo_762x51_M80_Ball: BulletBase
	{
		//Ball
		//9.5 g
		hit=11.55;
		indirectHit=0;
		indirectHitRange=0;
		cartridge="FxCartridge_762";
		visibleFire=22;
		audibleFire=18;
		visibleFireTime=3;
		cost = 1.2;
		airLock=1;

		//4mm at 300m
		caliber=0.45;
		
		model="\A3\Weapons_f\Data\bullettracer\tracer_red";
		tracerScale=1.2;
		tracerStartTime = 0.075; // seconds
		tracerEndTime = 1; // seconds

		airFriction = -0.0006814;
		typicalSpeed = 838;
	};
	class rhs_ammo_762x51_M80A1EPR_Ball: rhs_ammo_762x51_M80_Ball
	{
		//Ball
		//7.97 g
		hit=9.98;	
		//3.5mm at 300m
		caliber=0.55;
		airFriction = -0.0007114;
		typicalSpeed = 803;
	};
	class rhs_ammo_762x51_M118_Special_Ball: rhs_ammo_762x51_M80_Ball
	{
		//Full Metal Jacket Boat Tail
		//11.2 g
		caliber=0.52; //5mm at 300m
		typicalSpeed = 805;
		airFriction = -0.0007474;
	};
	class rhs_ammo_762x51_M993_Ball: rhs_ammo_762x51_M80_Ball
	{
		//8.2 g
		//7mm at 500m
		caliber=0.72;
		typicalSpeed = 910;
	};
	//shotgun
	class B_12Gauge_Pellets;
	class rhs_ammo_m576_buckshot: B_12Gauge_Pellets
	{
		hit = 8;
		indirectHit = 0;
		indirectHitRange = 0.6;
	};

	// 00 Buck
	class rhs_ammo_12g_00buckshot: B_12Gauge_Pellets
	{
		hit = 3.75;
		indirectHit = 0;
		indirectHitRange = 0;
		caliber = 0.24;

		typicalSpeed = 403.86;
		airFriction = -0.00634;

		class HitEffects
		{
			Hit_Foliage_green = "ImpactLeavesGreen";
			Hit_Foliage_Dead = "ImpactLeavesDead";
			Hit_Foliage_Green_big = "ImpactLeavesGreenBig";
			Hit_Foliage_Palm = "ImpactLeavesPalm";
			Hit_Foliage_Pine = "ImpactLeavesPine";
			hitFoliage = "ImpactLeaves";
			hitGlass = "ImpactGlass";
			hitGlassArmored = "ImpactGlassThin";
			hitWood = "ImpactWood";
			hitMetal = "ImpactMetal";
			hitMetalPlate = "ImpactMetal";
			hitBuilding = "ImpactPlaster";
			hitPlastic = "ImpactPlastic";
			hitRubber = "ImpactRubber";
			hitConcrete = "ImpactConcrete";
			hitMan = "ImpactEffectsBlood";
			hitGroundSoft = "ImpactEffectsSmall";
			hitGroundHard = "ImpactEffectsHardGround";
			hitWater = "ImpactEffectsWater";
			hitVirtual = "ImpactMetal";
		};
	};
	class rhs_ammo_doomsday_buckshot: B_12Gauge_Pellets
	{
		hit = 9;
		indirectHit = 9;
		indirectHitRange = 0.6;
	};

	class B_12Gauge_Slug;
	// 437 Grain slug
	class rhs_ammo_12g_slug: B_12Gauge_Slug
	{
		hit = 34.51;
		indirectHit = 0;
		indirectHitRange = 0;
		caliber = 0.3048;

		typicalSpeed = 475.49;
		airFriction = -0.002042;
		
	};

	// HE FRAG
	class rhs_ammo_12g_FRAG : B_12Gauge_Slug
	{
		hit = 6;
		indirectHit = 1.143;
		indirectHitRange = 1.972;
		caliber = 0.2;

		typicalSpeed = 150;
		airFriction = -0.0069;

		timeToLive = 5;

		deflecting = 0;
		explosive = 1;

		explosionEffects = "RHSUSF_12gExplosion";
		CraterEffects = "";

		dangerRadiusBulletClose = 16;
		dangerRadiusHit = 40;
		suppressionRadiusBulletClose = 15;
		suppressionRadiusHit = 14;

		soundHit1[] = { "A3\Sounds_F\weapons\Explosion\gr_explosion_1", 1.6, 1, 1200 };
		soundHit3[] = { "A3\Sounds_F\weapons\Explosion\gr_explosion_3", 1.6, 1, 1200 };
		soundHit4[] = { "A3\Sounds_F\weapons\Explosion\gr_explosion_4", 1.6, 1, 1200 };
		soundHit6[] = { "A3\Sounds_F\weapons\Explosion\gr_explosion_6", 1.6, 1, 1200 };
		multiSoundHit[] = { "soundHit1", 0.25, "soundHit3", 0.25, "soundHit4", 0.25, "soundHit6", 0.25 };
		explosionSoundEffect = "DefaultExplosion";

		class CamShakeExplode
		{
			power = "(9*0.2)";
			duration = "((round (9^0.5))*0.2 max 0.2)";
			frequency = 20;
			distance = "((1 + 9^0.5)*8)";
		};
		class CamShakeHit
		{
			power = 9;
			duration = "((round (9^0.25))*0.2 max 0.2)";
			frequency = 20;
			distance = 1;
		};
	};

	// HE AP ~ 10mm RHA EPF
	class rhs_ammo_12g_HE : rhs_ammo_12g_FRAG
	{
		ais_ce_penetrators[] = { "rhs_ammo_12gHEAP_penetrator" };

		hit = 1.575;
		indirectHit = 1.143;
		indirectHitRange = 0.986;
		caliber = 0.1;

		typicalSpeed = 150;
		airFriction = -0.0074;

		deflecting = 0;
	};
	class rhs_ammo_12gHEAP_penetrator : BulletBase
	{
		hit = 10;
		indirectHit = 0;
		deflecting = 0;
		RHA(13, 1000)

		model = "\A3\Weapons_f\Data\bullettracer\tracer_yellow";
		class HitEffects
		{
			hitMetal = "ImpactMetalSabotSmall";
			hitMetalPlate = "ImpactMetalSabotSmall";
			hitBuilding = "ImpactConcreteSabotSmall";
			hitConcrete = "ImpactConcreteSabotSmall";
			hitGroundSoft = "ImpactEffectsGroundSabot";
			hitGroundHard = "ImpactEffectsGroundSabot";
			Hit_Foliage_green = "ImpactLeavesGreen";
			Hit_Foliage_Dead = "ImpactLeavesDead";
			Hit_Foliage_Green_big = "ImpactLeavesGreenBig";
			Hit_Foliage_Palm = "ImpactLeavesPalm";
			Hit_Foliage_Pine = "ImpactLeavesPine";
			hitFoliage = "ImpactLeaves";
			hitGlass = "ImpactGlass";
			hitGlassArmored = "ImpactGlassThin";
			hitWood = "ImpactWood";
			hitPlastic = "ImpactPlastic";
			hitRubber = "ImpactRubber";
			hitMan = "ImpactEffectsBlood";
			hitWater = "ImpactEffectsWater";
			default_mat = "ImpactEffectsGroundSabot";
		};
	};
	
	/// Pistol Rounds
	class rhs_ammo_45ACP_MHP: BulletBase
 	{
 		scope = 2;
  		hit = 5.146859392;
  		indirectHit = 0;
  		indirectHitRange = 0;
  		suppressionRadiusBulletClose = 2;
  		cartridge = "FxCartridge_9mm";
  		model = "\A3\Weapons_f\Data\bullettracer\tracer_green";
  		caliber = 2.680965147;
  		deflecting = 30;
  		visibleFire = 5;
  		audibleFire = 9;
 		cost = 100;
  		typicalSpeed = 280;
  		airFriction = -0.0018;  		
 	};

	///! Rockets
//heat
	class rhsusf_ammo_basic_penetrator;
	class rhs_ammo_M136_rocket : RocketBase
	{
		ais_ce_penetrators[] = { "rhs_ammo_M136_penetrator" };

		model="\rhsusf\addons\rhsusf_weapons\M136\at4_rocket";
		hit = 235;
		indirectHit = 11;
		indirectHitRange = 1.1;
		cost = 200;
		explosive = 0.65;
		
		//airFriction = -0.00009;
		airFriction = 0.3;
		sideAirFriction = 0.01;
		simulationStep = 0.01;
		maxSpeed = 219;
		initTime = 0.1;
		thrustTime = 0.00;
		thrust = 10;
		fuseDistance = 5;
		
		visibleFire = 28;
		audibleFire = 16;
		whistleDist = 4;
		timeToLive = 12;
		
		CraterEffects = "ATRocketCrater";
		explosionEffects = "ATRocketExplosion";
		effectsMissileInit = "RocketBackEffectsRPG";
		effectsMissile = "missile3";
		
		class CamShakeFire
		{
			power = 10;
			duration = 0.5;
			frequency = 20;
			distance = 30;
		};
		class CamShakePlayerFire
		{
			power = 5;
			duration = 0.1;
			frequency = 20;
		};
	};
	class rhs_ammo_M136_penetrator : rhsusf_ammo_basic_penetrator
	{
		hit = 335;
		RHA(400,1000)
	};
	class rhs_ammo_M136_hp_rocket : rhs_ammo_M136_rocket
	{
		ais_ce_penetrators[] = { "rhs_ammo_M136_hp_penetrator" };

		hit = 285;
	};
	class rhs_ammo_M136_hp_penetrator : rhs_ammo_M136_penetrator
	{
		hit = 345;
		RHA(550,1000)
	};
	
	class rhs_ammo_M136_hedp_rocket : rhs_ammo_M136_rocket
	{
		ais_ce_penetrators[] = { "rhs_ammo_M136_hedp_penetrator" };

		hit = 235;
		indirectHit = 31;
		indirectHitRange = 4.1;
		cost = 200;
		explosive = 0.65;
	};
	class rhs_ammo_M136_hedp_penetrator : rhs_ammo_M136_penetrator
	{
		hit = 235;
		RHA(150,1000)
	};

	class M_Titan_AA;
	class rhsammo_fim92_missile : M_Titan_AA
	{
		model=\rhsusf\addons\rhsusf_weapons\FIM92\Stinger_Rocket;
		hit=70;indirectHit=50;indirectHitRange=8; //3kg high explosive, hit-to-kill impact fuse
		maneuvrability=14;
		simulationStep = 0.002; // for high speed and maneuverability we need extremely small step
		trackOversteer = 0.85;
		trackLead = 0;
		airLock = 2;
		irLock = true;
		cost=1000; 
		timeToLive = 15; // 17 +/- 2
		sideAirFriction = 0.75;
		maxSpeed = 750; // m/s
		initTime = 0.250000;
		thrustTime = 2;
		thrust = 1050;
		fuseDistance = 50;
		CraterEffects = "AAMissileCrater";
		explosionEffects = "AAMissileExplosion";
//		smokeTrail = 3;
		effectsMissile = "missile3";
		whistleDist = 16;
	};

	class M_Titan_AT;
	class rhs_ammo_M_fgm148_AT: M_Titan_AT
	{
		ais_ce_penetrators[] = { "rhs_ammo_M_fgm148_AT_penetrator" };

		model = "\rhsusf\addons\rhsusf_weapons\FGM148\fgm148_missile";
		
		//hit = 850;
		hit = 250;
		indirectHit = 40;
		indirectHitRange = 4;
		explosive = 0.65;
		
		
		irLock = 1;
		laserLock = 1;
		nvLock = 0;
		airLock = 0;
		lockSeekRadius = 3;
		autoSeekTarget = 0;
		//lockType = [0];
		allowAgainstInfantry = 0;
		
		airFriction = 0.2;
		sideAirFriction = 0.1;
		trackOversteer = 1;
		trackLead = 1;
		maxSpeed = 460;
		manualControl = 0;
		maneuvrability = 32;
		maxControlRange = 4000;
		
		fuseDistance = 30; //Distance until armed (Not working?)
		thrust = 75;
		thrustTime = 25;
		initTime = 0.5; //Time till engine start after launch
		
		timeToLive = 60;
		whistleDist = 4;
		deflecting = 0;
		simulationStep = 0.001;
		cmImmunity = 0.9;
		cost = 1000;
	};
	class rhs_ammo_M_fgm148_AT_penetrator : rhsusf_ammo_basic_penetrator
	{
		hit = 380;
		RHA(970,1000)
	};

	///! Explosives

	class PipeBombBase;

	class rhsusf_m112_ammo: PipeBombBase
	{
		hit = 1000;
		indirectHit = 1000;
		indirectHitRange = 3;
		model = "\rhsusf\addons\rhsusf_weapons\explosives\M112x1";
		mineModelDisabled = "\A3\Weapons_F\explosives\c4_charge_small_d";
		soundHit[] = {"A3\Sounds_F\weapons\Mines\mine_debris_5",3.1622777,1,1500};
		defaultMagazine = "rhsusf_m112_ammo_mag";
		ExplosionEffects = "MineNondirectionalExplosionSmall";
		CraterEffects = "MineNondirectionalCraterSmall";
		whistleDist = 32;
		mineInconspicuousness = 5;
		mineTrigger = "RemoteTrigger";
		triggerWhenDestroyed = 0;
	};
	class rhsusf_m112_ammo_scripted: rhsusf_m112_ammo
	{
		triggerWhenDestroyed = 1;
	};

	class rhsusf_m112x4_ammo: PipeBombBase
	{
		hit = 3000;
		indirectHit = 3000;
		indirectHitRange = 5;
		model = "\rhsusf\addons\rhsusf_weapons\explosives\M112x4";
		mineModelDisabled = "\A3\Weapons_F\Explosives\satchel_d";
		defaultMagazine = "rhsusf_m112x4_ammo_mag";
		soundHit[] = {"A3\Sounds_F\weapons\Mines\mine_debris_2",3.1622777,1,1500};
		ExplosionEffects = "MineNondirectionalExplosion";
		CraterEffects = "MineNondirectionalCrater";
		whistleDist = 32;
		mineInconspicuousness = 5;
		mineTrigger = "RemoteTrigger";
		triggerWhenDestroyed = 0;
	};
	class rhsusf_m112x4_ammo_scripted: rhsusf_m112x4_ammo
	{
		triggerWhenDestroyed = 1;
	};


	///! Mines
	
	class MineBase;
	
	class rhsusf_mine_m19_ammo: MineBase
	{
		hit = 2200;
		indirectHit = 1250;
		indirectHitRange = 2;
		model = "\rhsusf\addons\rhsusf_weapons\mines\M19";
		mineModelDisabled = "\rhsusf\addons\rhsusf_weapons\mines\M19";
		icon = "iconExplosiveAP";
		
		defaultMagazine = "rhsusf_mine_m19_mag";
		
		soundHit[] = {"A3\Sounds_F\weapons\mines\mine_debris_2",3.1622777,1,2000};

		explosionEffects = "ATMineExplosion";
		CraterEffects = "ATMineCrater";
		whistleDist = 8;
		cost = 200;
		mineInconspicuousness = 30;
		//mineTrigger = "RangeTriggerShort";
		mineTrigger = "rhs_M19_Trigger";
	};
	
	class rhsusf_40mm_white : F_40mm_White
	{
		brightness = 25; // def 12
		timeToLive = 60; // def 25
		intensity = 100000;
	};
	
	class rhsusf_40mm_red : F_40mm_Red
	{
		brightness = 25; // def 12
		timeToLive = 60; // def 25
		intensity = 100000;
	};
	
	class rhsusf_40mm_green : F_40mm_Green
	{
		brightness = 25; // def 12
		timeToLive = 60; // def 25
		intensity = 100000;
	};
	
	class GrenadeHand;
	class rhs_ammo_m67: GrenadeHand
	{
		model = "\rhsusf\addons\rhsusf_weapons\grenades_thrown\m67\m67_frag";
	};

	class GrenadeHand_stone;
	class rhs_ammo_m69: GrenadeHand_stone
	{
		model = "\rhsusf\addons\rhsusf_weapons\grenades_thrown\m69\m69_practice";
	};

	class rhs_ammo_m84: GrenadeHand
	{
		model = "\rhsusf\addons\rhsusf_weapons\grenades_thrown\m84\m84_flash";
		hit = 0.1;
		indirectHit = 0.1;
		indirectHitRange = 8;
		ExplosionEffects = "RHSUSF_flashbang_15";
		explosionTime = 1.5;
		cost = 10;
	};

	class SmokeShell;

	class rhs_ammo_an_m14_th3: SmokeShell
	{
		//effectsSmoke = "IncinerateShell";
		effectsSmoke = "RHS_Incendenary_Grenade";
		model = "\rhsusf\addons\rhsusf_weapons\grenades_thrown\an-m14_th3\an-m14_th3";
	};
	
	class rhs_ammo_m7a3_cs: GrenadeHand
	{
		hit = 0.1;
		indirectHit = 0.1;
		indirectHitRange = 8;
		ExplosionEffects = "RHS_flashbang_15";
		explosionTime = 1.5;
		cost = 10;
		model = "\rhsusf\addons\rhsusf_weapons\grenades_thrown\m7a3_cs\m7a3_cs";
	};

	class rhs_ammo_mk3a2: GrenadeHand
	{
		model = "\rhsusf\addons\rhsusf_weapons\grenades_thrown\mk3a2\mk3a2";
	};

	class rhs_ammo_an_m8hc: SmokeShell
	{
		model = "\rhsusf\addons\rhsusf_weapons\grenades_thrown\an-m8hc\an-m8hc";		
	};
	class rhs_ammo_m18_green: SmokeShell
	{
		smokeColor[] = {0.2125,0.6258,0.4891,1};
		model = "rhsusf\addons\rhsusf_weapons\grenades_thrown\m18\m18_smoke";
	};	

	class rhs_ammo_m18_purple: rhs_ammo_m18_green
	{
		smokeColor[] = {0.4341,0.1388,0.4144,1};
		model = "rhsusf\addons\rhsusf_weapons\grenades_thrown\m18\m18_smoke_purple";
	};	

	class rhs_ammo_m18_red: rhs_ammo_m18_green
	{
		smokeColor[] = {0.8438,0.1383,0.1353,1};
		model = "rhsusf\addons\rhsusf_weapons\grenades_thrown\m18\m18_smoke_red";
	};	

	class rhs_ammo_m18_yellow: rhs_ammo_m18_green
	{
		smokeColor[] = {0.9883,0.8606,0.0719,1};
		model = "rhsusf\addons\rhsusf_weapons\grenades_thrown\m18\m18_smoke_yellow";
	};	
	
};