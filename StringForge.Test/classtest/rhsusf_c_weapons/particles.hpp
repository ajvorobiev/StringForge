
class CfgCloudlets
{
	class Default;
	class RocketBackfireRPGNT;
	class RocketBacksmokeRPGNT;
	class RHS_RocketBackfireRPGNT : RocketBackfireRPGNT
	{

	};
	class RHS_Fired_M136HEAT : RHS_RocketBackfireRPGNT
	{
		interval = 0.265;
		lifeTime = 0.001;
		lifeTimeVar = 0;
		beforeDestroyScript = "rhsusf\addons\rhsusf_c_weapons\scripts\rhs_eh_m136heat.sqf";
	};
	class RHS_Fired_M136HEDP : RHS_Fired_M136HEAT
	{
		beforeDestroyScript = "rhsusf\addons\rhsusf_c_weapons\scripts\rhs_eh_m136hedp.sqf";
	};
	class RHS_Fired_M136HP : RHS_Fired_M136HEAT
	{
		beforeDestroyScript = "rhsusf\addons\rhsusf_c_weapons\scripts\rhs_eh_m136hp.sqf";
	};

	class RHS_CS_Gas : Default
	{
		interval = 0.265;
		circleRadius = 0;
		circleVelocity[] = { 0, 0, 0 };
		angle = 0;
		angleVar = 360;
		animationName = "";
		particleType = "Billboard";
		lifeTime = 0.05;
		moveVelocity[] = { 0, 0, 0 };
		rotationVelocity = 0;
		animationSpeed[] = { 1000 };
		randomDirectionPeriod = 0.01;
		randomDirectionIntensity = 1;

		timerPeriod = 0.05;
		onTimerScript = "";
		beforeDestroyScript = "rhsusf\addons\rhsusf_c_weapons\scripts\rhs_cs_gas.sqf";

		lifeTimeVar = 0;
		positionVar[] = { 0, 0, 0 };
		MoveVelocityVar[] = { 0, 0, 0 };
		rotationVelocityVar = 0;
		sizeVar = 0;
	};
	class ObjectDestructionFire1Small;
	class rhs_IncinerateFire : ObjectDestructionFire1Small
	{
		coreIntensity = 3.75;
		coreDistance = 2;
		damageTime = 0.1;
		constantDistance = 1;
		damageType = "Fire";

		size[] = { "1.2 * 0.15 + 1", "0.1 * 0.15 + 0.2" };
		animationSpeedCoef = 1;
		sizeCoef = 1;
		animationSpeed[] = { 1 };

	};
	/*
	another copy in rhsafrf!
	*/
	class RHSUSF_flashbang_10 : Default
	{
		interval = 0.265;
		circleRadius = 0;
		circleVelocity[] = { 0, 0, 0 };
		angle = 0;
		angleVar = 360;
		animationName = "";
		particleType = "Billboard";
		lifeTime = 0.05;
		moveVelocity[] = { 0, 0, 0 };
		rotationVelocity = 0;
		animationSpeed[] = { 1000 };
		randomDirectionPeriod = 0.01;
		randomDirectionIntensity = 1;

		timerPeriod = 0.05;
		onTimerScript = "";
		beforeDestroyScript = "rhsusf\addons\rhsusf_c_weapons\scripts\rhs_flashbang_10m.sqf";

		lifeTimeVar = 0;
		positionVar[] = { 0, 0, 0 };
		MoveVelocityVar[] = { 0, 0, 0 };
		rotationVelocityVar = 0;
		sizeVar = 0;
	};
	class RHSUSF_flashbang_15 : RHSUSF_flashbang_10
	{
		beforeDestroyScript = "rhsusf\addons\rhsusf_c_weapons\scripts\rhs_flashbang_15m.sqf";
	};
	class RHSUSF_flashbang_20 : RHSUSF_flashbang_10
	{
		beforeDestroyScript = "rhsusf\addons\rhsusf_c_weapons\scripts\rhs_flashbang_20m.sqf";
	};
	class RHSUSF_flashbang_smoke : Default
	{
		circleVelocity[] = { 0, 0, 0 };
		moveVelocity[] = { 0, 0, 1 };
		size[] = { 0.5, 1 };
		color[] = { { 0.1, 0.1, 0.1, 0.8 }, { 0.25, 0.25, 0.25, 0.5 }, { 0.5, 0.5, 0.5, 0 }, { 0.9, 1, 0.83, 0 } };
		animationSpeed[] = { 0.02 };
		positionVar[] = { 1.2, 0.6, 1.2 };
		MoveVelocityVar[] = { 0, 0, 1 };
		colorVar[] = { 0, 0, 0, 0.1 };
		interval = 0.01;
		circleRadius = 0;
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 8;
		particleFSLoop = 0;
		angleVar = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 2;
		rotationVelocity = 0;
		weight = 0.053;
		volume = 0.04;
		rubbing = 0.15;
		randomDirectionPeriod = 0.01;
		randomDirectionIntensity = 1;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 1;
		rotationVelocityVar = 0.1;
		sizeVar = 0.3;
		randomDirectionPeriodVar = 0.01;
		randomDirectionIntensityVar = 0.02;
	};
	class RHSUSF_HeatHaze : Default
	{
		interval = 0.07;
		circleRadius = 0;
		circleVelocity[] = { 0, 0, 0 };
		particleShape = "\A3\data_f\ParticleEffects\Universal\Refract";
		particleFSNtieth = 1;
		particleFSIndex = 0;
		particleFSFrameCount = 1;
		particleFSLoop = 0;
		angleVar = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1.1;
		lifeTime = 1.5;
		moveVelocity[] = { "-0.012*directionX", "-0.012*directionY", "-0.012*directionZ" };
		rotationVelocity = 1;
		weight = 1.25;
		volume = 1;
		rubbing = 0.1;
		size[] = { 0.07, 0.12 };
		color[] = { { 0.06, 0.06, 0.06, 0.30 }, { 0.3, 0.3, 0.3, 0.27 }, { 0.3, 0.3, 0.3, 0.24 }, { 0.3, 0.3, 0.3, 0.21 }, { 0.3, 0.3, 0.3, 0.1 } };
		colorCoef[] = { 1, 1, 1, 1 };
		animationSpeed[] = { 2, 1 };
		randomDirectionPeriod = 0.1;
		randomDirectionIntensity = 0.03;
		onTimerScript = "";
		beforeDestroyScript = "";
		destroyOnWaterSurface = 1;
		blockAIVisibility = 0;
		sizeCoef = 0.5;
		animationSpeedCoef = 1;
		position[] = { "positionX", "positionY", "positionZ" };
		lifeTimeVar = 0;
		positionVar[] = { 0, 0, 0 };
		MoveVelocityVar[] = { 0, 0, 0 };
		rotationVelocityVar = 5;
		sizeVar = 0.05;
		colorVar[] = { 0, 0, 0, 0 };
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class RHSUSF_HeatHaze1 : RHSUSF_HeatHaze 
	{
		interval = 0.03;
		weight = 1.24;
		size[] = { 0.1, 0.15 };
		randomDirectionIntensity = 0.05;
		rubbing = 0.2;
	};
	class RHSUSF_12gExplo_Smoke :Default
	{
		interval = 0.004;
		circleRadius = 0;
		circleVelocity[] = { 0, 0, 0 };
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 8;
		particleFSLoop = 0;
		angleVar = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 3;
		lifeTime = 1;
		moveVelocity[] = { "surfNormalX * 10", "surfNormalY * 10", "surfNormalZ * 10" };
		rotationVelocity = 1;
		weight = 1.28;
		volume = 1;
		rubbing = 0.5;
		size[] = { 0.7, 0.9 };
		sizeCoef = 1;
		color[] = { { 0.3, 0.3, 0.3, 0.5 }, { 0.4, 0.4, 0.4, 0.25 }, { 0.5, 0.5, 0.5, 0.15 }, { 0.6, 0.6, 0.6, 0.07 }, { 0.8, 0.8, 0.8, 0 } };
		colorCoef[] = { 1, 1, 1, 1 };
		animationSpeed[] = { 1 };
		animationSpeedCoef = 1;
		randomDirectionPeriod = 0.1;
		randomDirectionIntensity = 0.05;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 1;
		position[] = { 0, 0, 0 };
		positionVar[] = { 0.4, 0.4, 0.4 };
		moveVelocityVar[] = { 1.5, 1.5, 1.5 };
		rotationVelocityVar = 2;
		sizeVar = 0.2;
		colorVar[] = { 0.05, 0.05, 0.05, 0.3 };
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class MachineGunCartridge;
	class MachineGunCartridge2;
	class RHSUSF_762Cartridge : MachineGunCartridge2
	{
		particleShape = "\A3\weapons_f\ammo\cartridge_762.p3d";
		size[] = { 1 };
		moveVelocity[] = { "-directionX * 4", "-directionY * 4", "-directionZ * 4" }; // < Edit each tailing number to edit speed
	};
};

class CfgLights
{
	class RHSUSF_flashbang_light
	{
		color[] = { 11, 11, 9 };
		ambient[] = { 0.4, 0.45, 0.45 };
		brightness = 1;
		intensity = 1090;
		diffuse[] = { 0, 0, 0 };
		position[] = { 0, 0, 0 };
		class Attenuation
		{
			start = 0.05;
			constant = 0;
			linear = 0;
			quadratic = 40;
			hardLimitStart = 2;
			hardLimitEnd = 4;
		};
	};
};

class RHSUSF_762Cartridge
{
	class RHSUSF_762Cartridge
	{
		simulation = "particles";
		type = "RHSUSF_762Cartridge";
		position[] = { 0, 0, 0 };
		intensity = 1;
		interval = 1;
		lifeTime = 0.05;
		qualityLevel = 2;
	};
	class RHSUSF_762CartridgeMed
	{
		simulation = "particles";
		type = "RHSUSF_762Cartridge";
		position[] = { 0, 0, 0 };
		intensity = 1;
		interval = 1;
		lifeTime = 0.05;
		qualityLevel = 1;
	};
};

class RHSUSF_BarrelRefract
{
	class RHSUSF_HeatHaze
	{
		simulation = "particles";
		type = "RHSUSF_HeatHaze";
		position[] = { 0, 0, 0 };
		intensity = 1;
		interval = 1;
		lifeTime = 5;
	};
};
class RHSUSF_BarrelRefractHeavy
{
	class RHSUSF_HeatHaze1
	{
		simulation = "particles";
		type = "RHSUSF_HeatHaze1";
		position[] = { 0, 0, 0 };
		intensity = 1;
		interval = 1;
		lifeTime = 5;
	};
};

class RHSUSF_12gExplosion
{
	class FiredLightMed
	{
		simulation = "light";
		type = "FiredLightMed";
		position[] = { 0, 0, 0 };
		intensity = 0;
		interval = 1;
		lifeTime = 0.1;
	};
	class ExploAmmoFlash
	{
		simulation = "particles";
		type = "ExploAmmoFlash";
		position[] = { 0, 0, 0 };
		intensity = 0.02;
		interval = 1;
		lifeTime = 1;
	};
	class RHSUSF_12gExplo_Smoke
	{
		simulation = "particles";
		type = "RHSUSF_12gExplo_Smoke";
		position[] = { 0, 0, 0 };
		intensity = 0.01;
		interval = 1;
		lifeTime = 1;
	};
	class ImpactSparks
	{
		simulation = "particles";
		type = "ImpactSparks0";
		position[] = { 0, 0, 0 };
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
};

class RHSUSF_flashbang_10
{
	class Smoke1
	{
		position[] = { 0, 0, 0 };
		simulation = "particles";
		type = "RHSUSF_flashbang_10";
		intensity = 0.5;
		interval = 1;
		lifeTime = 1;
	};
	class Smoke2 : Smoke1
	{
		position[] = { 0, 0, 0 };
		simulation = "particles";
		type = "RHSUSF_flashbang_smoke";
		intensity = 0.5;
		interval = 1;
		lifeTime = 1;
	};
	class Light
	{
		position[] = { 0, 0, 0 };
		simulation = "light";
		type = "RHSUSF_flashbang_light";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
};
class RHSUSF_flashbang_15 : RHSUSF_flashbang_10
{
	class Smoke1 : Smoke1
	{
		type = "RHSUSF_flashbang_15";
	};
};
class RHSUSF_flashbang_20 : RHSUSF_flashbang_10
{
	class Smoke1 : Smoke1
	{
		type = "RHSUSF_flashbang_20";
	};
};

class RHS_CS_Grenade
{
	class Smoke1
	{
		position[] = { 0, 0, 0 };
		simulation = "particles";
		type = "RHS_CS_Gas";
		intensity = 0.5;
		interval = 1;
		lifeTime = 1;
	};
	class SmokeShellWhite
	{
		simulation = "particles";
		type = "SmokeShellWhite";
		position[] = { 0, 0, 0 };
		intensity = 1;
		interval = 1;
	};
	class SmokeShellWhite2
	{
		simulation = "particles";
		type = "SmokeShellWhite2";
		position[] = { 0, 0, 0 };
		intensity = 1;
		interval = 1;
	};
	class SmokeShellWhiteUW
	{
		simulation = "particles";
		type = "SmokeShellWhiteUW";
		position[] = { 0, 0, 0 };
		intensity = 1;
		interval = 1;
	};
	class SmokeShellWhite2UW
	{
		simulation = "particles";
		type = "SmokeShellWhite2UW";
		position[] = { 0, 0, 0 };
		intensity = 1;
		interval = 1;
	};
};
class RHS_Incendenary_Grenade
{
	class SmokeShellWhite
	{
		simulation = "particles";
		type = "SmokeShellWhite";
		position[] = { 0, 0, 0 };
		intensity = 1;
		interval = 1;
	};
	class Fire1
	{
		simulation = "particles";
		type = "rhs_IncinerateFire";
		position[] = { 0, 0, 0 };
		intensity = 1;
		interval = 1;
	};
};

class RHS_Fired_M136HEAT
{
	class RocketBackfire1
	{
		simulation = "particles";
		type = "RocketBackfireRPGNT";
		intensity = 1;
		interval = 0.1;
		lifeTime = 0.03;
	};
	class RocketBacksmoke2
	{
		simulation = "particles";
		type = "RocketBacksmokeRPGNT";
		intensity = 1;
		interval = 0.1;
		lifeTime = 0.1;
	};
	class RocketFrontsmoke
	{
		simulation = "particles";
		type = "RocketFrontsmokeRPGNT";
		intensity = 1;
		interval = 0.1;
		lifeTime = 0.2;
	};
	class Script
	{
		simulation = "particles";
		type = "RHS_fired_M136HEAT";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
};

class RHS_Fired_M136HEDP : RHS_Fired_M136HEAT
{
	class Script : Script
	{
		type = "RHS_fired_M136HEDP";
	};
};
class RHS_Fired_M136HP : RHS_Fired_M136HEAT
{
	class Script : Script
	{
		type = "RHS_fired_M136HP";
	};
};
