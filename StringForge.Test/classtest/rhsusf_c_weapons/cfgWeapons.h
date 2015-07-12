class CfgWeapons
{
	class InventoryOpticsItem_Base_F;
	
		
	#include "rhsusf_weap_rifles.hpp"
	#include "rhsusf_weap_launchers.hpp"
	#include "rhsusf_weap_acc.hpp"
	#include "rhsusf_weap_AI.hpp"
	#include "rhsusf_weap_pistols.hpp"
	#include "rhsusf_misc.hpp"
	
		///! mines + explosives

	class Default;
	class Put: Default
	{
		muzzles[] += {"Rhsusf_MineMuzzle","rhsusf_m112_muzzle","rhsusf_m112x4_muzzle"};
		class PutMuzzle: Default {};
		class Rhsusf_MineMuzzle: PutMuzzle
		{
			magazines[] = {"rhs_mine_M19_mag"};
		};

		class rhsusf_m112_muzzle: PutMuzzle
		{
			autoreload = 0;
			displayName = "M112 charge";
			magazines[] = {"rhsusf_m112_mag"};
			enableAttack = 1;
			showToPlayer = 0;
		};
		class rhsusf_m112x4_muzzle: PutMuzzle
		{
			autoreload = 0;
			displayName = "M112 x4 charge pack";
			magazines[] = {"rhsusf_m112x4_mag"};
			enableAttack = 1;
			showToPlayer = 0;
		};
	};


	class GrenadeLauncher;
	class Throw: GrenadeLauncher
	{
		muzzles[] += {
			Rhsusf_Throw_Flash,
			Rhsusf_Throw_Grenade, 
			Rhsusf_Throw_Incendenary,
			Rhsusf_Throw_CS,
			Rhsusf_Throw_Smoke_white,
			Rhsusf_Throw_Smoke_green,
			Rhsusf_Throw_Smoke_red,
			Rhsusf_Throw_Smoke_yellow,
			Rhsusf_Throw_Smoke_purple
		};
		class ThrowMuzzle: GrenadeLauncher {};
		class Rhsusf_Throw_Flash: ThrowMuzzle
		{
			magazines[] = 
			{
				"rhs_mag_mk84"
			};
		};
		class Rhsusf_Throw_Incendenary: ThrowMuzzle
		{
			magazines[] = 
			{
				"rhs_mag_an_m14_th3"
			};
		};
		class Rhsusf_Throw_CS: ThrowMuzzle
		{
			magazines[] = 
			{
				"rhs_mag_m7a3_cs"
			};
		};
		class Rhsusf_Throw_Smoke_white: ThrowMuzzle
		{
			magazines[] = 
			{
				"rhs_mag_an_m8hc"
			};
		};
		class Rhsusf_Throw_Smoke_green: ThrowMuzzle
		{
			magazines[] = 
			{
				"rhs_mag_m18_green"
			};
		};
		class Rhsusf_Throw_Smoke_red: ThrowMuzzle
		{
			magazines[] = 
			{
				"rhs_mag_m18_red"
			};
		};
		class Rhsusf_Throw_Smoke_purple: ThrowMuzzle
		{
			magazines[] = 
			{
				"rhs_mag_m18_purple"
			};
		};
		class Rhsusf_Throw_Smoke_yellow: ThrowMuzzle
		{
			magazines[] = 
			{
				"rhs_mag_m18_yellow"
			};
		};
		class Rhsusf_Throw_Grenade: ThrowMuzzle
		{
			magazines[] = 
			{
				"rhs_mag_mk3a2",
				"rhs_mag_m67",
				"rhs_mag_m69"
			};
		};
	};
};