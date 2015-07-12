class CfgVehicles
{
	class MineBase;
	class rhsusf_mine_M19: MineBase
	{
		scope = 2;
		ammo = "rhsusf_mine_m19_ammo";
		
		displayName = "M19";
		icon = "iconExplosiveAP";
		picture = "\A3\Weapons_F\Data\clear_empty.paa";
		descriptionShort = "$STR_A3_cfgMagazines_ClassicMineRangeMagazine1";
		
		class Library
		{
			libTextDesc = "The design of anti-tank mines has not changed much during the last 50 years. An AT mine is the strongest ground mine manufactured today. They are triggered only by vehicles.";
		};
	};
	
	class Box_NATO_Wps_F;
	
	/* Ammo boxes */

	class rhsusf_weapons_crate: Box_NATO_Wps_F
	{
		displayName = "RHSUSF Weapons Crate (Virtual)";
		scope = 2;
		
		// TODO: change icon
		icon = "iconCrateLarge";
		
		transportMaxWeapons = 40;
		transportMaxMagazines = 20;
		
		/*
			all weapons data is now stored in
			rhs_c_weapons\scripts\virtualAmmoBox.sqf 

			please add new weapons/items in that place
		*/

		class EventHandlers
		{
			init = "[_this select 0,0] call rhs_fnc_virtualAmmoBoxUSA;";
		};

		class TransportWeapons {};
		class TransportMagazines {};
		class TransportItems {};
		
	
	};
	
	class Box_NATO_Ammo_F;
	class rhsusf_ammo_crate:  Box_NATO_Ammo_F
	{
		displayName = "RHSUSF Ammo Crate (Virtual)";
		scope = 2;
		
		// TODO: change icon
		icon = "iconCrateLarge";
		
		transportMaxWeapons = 40;
		transportMaxMagazines = 20;

		class EventHandlers
		{
			init = "[_this select 0,1] call rhs_fnc_virtualAmmoBoxUSA;";
		};
		
		class TransportWeapons {};
		class TransportMagazines {};
		class TransportItems {};
		
	};

	
	/* WEAPONS */
	// Weapons that can be spawned as an object both in the editor and in Zeus

	class Weapon_Base_F;

	// Macro that determines which weapon 
	#define WeaponMacro(classname,strname) class TransportWeapons \
	  	{ \
	   		class ##classname## \
	   		{ \
	    		weapon = "##classname##"; \
	    		count = 1; \
	   		}; \
	  	}; \
	  	displayName= "##strname##";

	// Macro that determines which magazine will appear in the weapon when spawn.
	#define MagazineMacro(magazineclass) class TransportMagazines \
	  	{ \
	   		class ##magazineclass## \
	   		{ \
	    		magazine = "##magazineclass##"; \
	   			count = 1; \
	  	 	}; \
	  	}; 

	class rhs_weapon_base : Weapon_Base_F
	{
		scope = 1;
	    scopeCurator = 1;

	    Author_Macro

	  	vehicleClass = "WeaponsPrimary";	  	
	};

	class rhs_weapon_M320 : rhs_weapon_base
	{
		scope = 2;
	    scopeCurator = 2;
	    
		WeaponMacro(rhs_weap_M320,$STR_RHS_CFGWEAPONS_RIFLE_M320)

		MagazineMacro(rhs_mag_M433_HEDP)

		vehicleClass = "WeaponsSecondary";
	};

	// M2010
	class rhs_weapon_XM2010 : rhs_weapon_base
	{
		scope = 2;
	    scopeCurator = 2;

	    WeaponMacro(rhs_weap_XM2010,$STR_RHS_CFGWEAPONS_RIFLE_xm2010)

		MagazineMacro(rhsusf_5Rnd_300winmag_xm2010)
	};

	class rhs_weapon_XM2010_d : rhs_weapon_XM2010
	{	    
	    WeaponMacro(rhs_weap_XM2010_d,$STR_RHS_CFGWEAPONS_RIFLE_xm2010_d)
	};

	class rhs_weapon_XM2010_wd : rhs_weapon_XM2010
	{	    
	    WeaponMacro(rhs_weap_XM2010_wd,$STR_RHS_CFGWEAPONS_RIFLE_xm2010_wd)
	};

	class rhs_weapon_XM2010_sa : rhs_weapon_XM2010
	{	        
	    WeaponMacro(rhs_weap_XM2010_sa,$STR_RHS_CFGWEAPONS_RIFLE_xm2010_sa)
	};

	// M4
	class rhs_weapon_m4 : rhs_weapon_base
	{
		scope = 2;
	    scopeCurator = 2;

	    WeaponMacro(rhs_weap_m4,$STR_RHS_CFGWEAPONS_RIFLE_M4)

		MagazineMacro(rhs_mag_30Rnd_556x45_M855A1_Stanag)
	};

	class rhs_weapon_m4_carryhandle : rhs_weapon_m4
	{
	    WeaponMacro(rhs_weap_m4_carryhandle,$STR_RHS_CFGWEAPONS_RIFLE_M4_carry)
	};

	class rhs_weapon_m4_carryhandle_pmag : rhs_weapon_m4
	{
	    WeaponMacro(rhs_weap_m4_carryhandle_pmag,$STR_RHS_CFGWEAPONS_RIFLE_M4_carryp)
	};

	class rhs_weapon_m4_grip : rhs_weapon_m4
	{
	    WeaponMacro(rhs_weap_m4_grip,$STR_RHS_CFGWEAPONS_RIFLE_M4_foreg)
	};

	class rhs_weapon_m4_grip2 : rhs_weapon_m4
	{
	    WeaponMacro(rhs_weap_m4_grip2,$STR_RHS_CFGWEAPONS_RIFLE_M4_afg)
	};

	class rhs_weapon_m4_m320 : rhs_weapon_m4
	{
	    WeaponMacro(rhs_weap_m4_m320,$STR_RHS_CFGWEAPONS_RIFLE_M4_M320)
	};

	class rhs_weapon_m4_m203 : rhs_weapon_m4
	{
	    WeaponMacro(rhs_weap_m4_m203,$STR_RHS_CFGWEAPONS_RIFLE_M4_M203)
	};

	class rhs_weapon_m4_m203S : rhs_weapon_m4
	{
	    WeaponMacro(rhs_weap_m4_m203S,$STR_RHS_CFGWEAPONS_RIFLE_M4_M203S)
	};

	// M4A1
	class rhs_weapon_m4a1 : rhs_weapon_m4
	{
	    WeaponMacro(rhs_weap_m4a1,$STR_RHS_CFGWEAPONS_RIFLE_M4A1)
	};

	class rhs_weapon_m4a1_carryhandle : rhs_weapon_m4a1
	{
	    WeaponMacro(rhs_weap_m4a1_carryhandle,$STR_RHS_CFGWEAPONS_RIFLE_M4A1_carryhandle)
	};

	class rhs_weapon_m4a1_carryhandle_pmag : rhs_weapon_m4a1
	{
	    WeaponMacro(rhs_weap_m4a1_carryhandle_pmag,$STR_RHS_CFGWEAPONS_RIFLE_M4A1_carryp)
	};
	class rhs_weapon_m4a1_grip : rhs_weapon_m4a1
	{
	    WeaponMacro(rhs_weap_m4a1_grip,$STR_RHS_CFGWEAPONS_RIFLE_M4A1_foreg)
	};

	class rhs_weapon_m4a1_carryhandle_grip : rhs_weapon_m4a1
	{
	    WeaponMacro(rhs_weap_m4a1_carryhandle_grip,$STR_RHS_CFGWEAPONS_RIFLE_M4A1_CARRYHANDLE_foreg)
	};

	class rhs_weapon_m4a1_grip2 : rhs_weapon_m4a1
	{
	    WeaponMacro(rhs_weap_m4a1_grip2,$STR_RHS_CFGWEAPONS_RIFLE_M4A1_afg)
	};

	class rhs_weapon_m4a1_carryhandle_grip2 : rhs_weapon_m4a1
	{
	    WeaponMacro(rhs_weap_m4a1_carryhandle_grip2,$STR_RHS_CFGWEAPONS_RIFLE_M4A1_carryhandle_afg)
	};
	class rhs_weapon_m4a1_m320 : rhs_weapon_m4a1
	{
	    WeaponMacro(rhs_weap_m4a1_m320,$STR_RHS_CFGWEAPONS_RIFLE_M4A1_M320)
	};

	class rhs_weapon_m4a1_m203 : rhs_weapon_m4a1
	{
	    WeaponMacro(rhs_weap_m4a1_m203,$STR_RHS_CFGWEAPONS_RIFLE_M4A1_M203)
	};

	class rhs_weapon_m4a1_m203s : rhs_weapon_m4a1
	{
	    WeaponMacro(rhs_weap_m4a1_m203s,$STR_RHS_CFGWEAPONS_RIFLE_M4A1_M203S)
	};

	class rhs_weapon_m4a1_carryhandle_m203 : rhs_weapon_m4a1
	{
	    WeaponMacro(rhs_weap_m4a1_carryhandle_m203,$STR_RHS_CFGWEAPONS_RIFLE_M4A1_carryhandle_M203)
	};

	class rhs_weapon_m4a1_carryhandle_m203S : rhs_weapon_m4a1
	{
	    WeaponMacro(rhs_weap_m4a1_carryhandle_m203S,$STR_RHS_CFGWEAPONS_RIFLE_M4A1_carryhandle_M203S)
	};

	// M4A1 Bk II
	class rhs_weapon_m4a1_blockII : rhs_weapon_m4
	{
		scope = 2;
	    scopeCurator = 2;

	    WeaponMacro(rhs_weap_m4a1_blockII,$STR_RHS_CFGWEAPONS_RIFLE_M4A1BLII)
	};

	class rhs_weapon_m4a1_blockII_KAC : rhs_weapon_m4a1_blockII
	{
	    WeaponMacro(rhs_weap_m4a1_blockII_KAC,$STR_RHS_CFGWEAPONS_RIFLE_M4A1BLII_KAC)
	};

	class rhs_weapon_m4a1_blockII_grip2 : rhs_weapon_m4a1_blockII
	{
	    WeaponMacro(rhs_weap_m4a1_blockII_grip2,$STR_RHS_CFGWEAPONS_RIFLE_M4A1BLII_afg)
	};

	class rhs_weapon_m4a1_blockII_grip2_KAC : rhs_weapon_m4a1_blockII
	{
	    WeaponMacro(rhs_weap_m4a1_blockII_grip2_KAC,$STR_RHS_CFGWEAPONS_RIFLE_M4A1BLII_afg_kac)
	};

	class rhs_weapon_m4a1_blockII_M203 : rhs_weapon_m4a1_blockII
	{
	    WeaponMacro(rhs_weap_m4a1_blockII_M203,$STR_RHS_CFGWEAPONS_RIFLE_M4A1BLII_M203)
	};

	// Mk18
	class rhs_weapon_mk18 : rhs_weapon_m4
	{
		scope = 2;
	    scopeCurator = 2;

	    WeaponMacro(rhs_weap_mk18,$STR_RHS_CFGWEAPONS_RIFLE_MK18)
	};
	
	class rhs_weapon_mk18_KAC : rhs_weapon_mk18
	{
	    WeaponMacro(rhs_weap_mk18_KAC,$STR_RHS_CFGWEAPONS_RIFLE_MK18_KAC)
	};
	
	class rhs_weapon_mk18_grip2 : rhs_weapon_mk18
	{
	    WeaponMacro(rhs_weap_mk18_grip2,$STR_RHS_CFGWEAPONS_RIFLE_MK18_afg)
	};

	class rhs_weapon_mk18_grip2_KAC : rhs_weapon_mk18
	{
	    WeaponMacro(rhs_weap_mk18_grip2_KAC,$STR_RHS_CFGWEAPONS_RIFLE_MK18_afg_kac)
	};

	class rhs_weapon_mk18_m320 : rhs_weapon_mk18
	{
	    WeaponMacro(rhs_weap_mk18_m320,$STR_RHS_CFGWEAPONS_RIFLE_MK18_M320)
	};

	// M16A4
	class rhs_weapon_m16a4 : rhs_weapon_m4
	{
		scope = 2;
	    scopeCurator = 2;

	    WeaponMacro(rhs_weap_m16a4,$STR_RHS_CFGWEAPONS_RIFLE_M16A4)
	};

	class rhs_weapon_m16a4_carryhandle : rhs_weapon_m16a4
	{
		scope = 2;
	    scopeCurator = 2;

	    WeaponMacro(rhs_weap_m16a4_carryhandle,$STR_RHS_CFGWEAPONS_RIFLE_M16A4_carry)
	};

	class rhs_weapon_m16a4_carryhandle_pmag : rhs_weapon_m16a4
	{
	    WeaponMacro(rhs_weap_m16a4_carryhandle_pmag,$STR_RHS_CFGWEAPONS_RIFLE_M16A4_carryp)
	};


	class rhs_weapon_m16a4_grip : rhs_weapon_m16a4
	{
	    WeaponMacro(rhs_weap_m16a4_grip,$STR_RHS_CFGWEAPONS_RIFLE_M16A4_foreg)
	};


	class rhs_weapon_m16a4_carryhandle_grip : rhs_weapon_m16a4
	{
	    WeaponMacro(rhs_weap_m16a4_carryhandle_grip,$STR_RHS_CFGWEAPONS_RIFLE_M16A4_carry_foreg)
	};

	class rhs_weapon_m16a4_carryhandle_grip_pmag : rhs_weapon_m16a4
	{
	    WeaponMacro(rhs_weap_m16a4_carryhandle_grip_pmag,$STR_RHS_CFGWEAPONS_RIFLE_M16A4_carryp_foreg)
	};

	class rhs_weapon_m16a4_carryhandle_M203 : rhs_weapon_m16a4
	{
	    WeaponMacro(rhs_weap_m16a4_carryhandle_M203,$STR_RHS_CFGWEAPONS_RIFLE_M16A4_carry_M203)
	};

	// M249
	class rhs_weapon_m249_pip : rhs_weapon_base
	{
		scope = 2;
	    scopeCurator = 2;

	    WeaponMacro(rhs_weap_m249_pip,M249 PIP)

		MagazineMacro(rhsusf_100Rnd_556x45_soft_pouch)
	};

	// M240
	class rhs_weapon_m240B : rhs_weapon_base
	{
		scope = 2;
	    scopeCurator = 2;

	    WeaponMacro(rhs_weap_m240B,M240B)

		MagazineMacro(rhsusf_50Rnd_762x51)
	};

	class rhs_weapon_m240B_CAP : rhs_weapon_base
	{
	    WeaponMacro(rhs_weap_m240B_CAP,M240B)	
	};

	class rhs_weapon_m240G : rhs_weapon_base
	{

	    WeaponMacro(rhs_weap_m240G,M240B)
	};

	// M14 EBR
	class rhs_weapon_m14ebrri : rhs_weapon_base
	{
		scope = 2;
	    scopeCurator = 2;

	    WeaponMacro(rhs_weap_m14ebrri,M14 EBR-RI)

		MagazineMacro(rhsusf_20Rnd_762x51_m993_Mag)
	};

	// SR25
	class rhs_weapon_sr25 : rhs_weapon_base
	{
		scope = 2;
	    scopeCurator = 2;

	    WeaponMacro(rhs_weap_sr25,SR-25)

		MagazineMacro(rhsusf_20Rnd_762x51_m993_Mag)
	};

	class rhs_weapon_sr25_ec : rhs_weapon_sr25
	{
	    WeaponMacro(rhs_weap_sr25_ec,SR-25 EC)
	};

	// M107
	class rhs_weapon_M107 : rhs_weapon_base
	{
		scope = 0;
	    scopeCurator = 0;

	    WeaponMacro(rhs_weap_M107,M107)

		MagazineMacro(rhsusf_10Rnd_STD_50BMG_M107)
	};

	// M590
	class rhs_weapon_M590_5RD : rhs_weapon_base
	{
		scope = 2;
	    scopeCurator = 2;

	    WeaponMacro(rhs_weap_M590_5RD,M590A1 (Short))

	    MagazineMacro(rhsusf_5Rnd_00Buck)
	};

	class rhs_weapon_M590_8RD : rhs_weapon_M590_5RD
	{
	    WeaponMacro(rhs_weap_M590_8RD,M590A1 (Long))

	    MagazineMacro(rhsusf_8Rnd_00Buck)
	};

	// M1911
	class rhsusf_weapon_m1911a1 : rhs_weapon_base
	{
		scope = 2;
	    scopeCurator = 2;

	    WeaponMacro(rhsusf_weap_m1911a1,$STR_RHS_CFGWEAPONS_PISTOL_M1911A1)

	    MagazineMacro(rhsusf_mag_7x45acp_MHP)

	    vehicleClass = "WeaponsHandguns";
	};

	// M136
	class rhs_weapon_M136 : rhs_weapon_base
	{
		scope = 2;
	    scopeCurator = 2;

	    WeaponMacro(rhs_weap_M136,M136 (HEAT))

	    MagazineMacro(rhs_m136_mag)

	    vehicleClass = "WeaponsSecondary";
	};

	class rhs_weapon_M136_hedp : rhs_weapon_M136
	{
		scope = 2;
	    scopeCurator = 2;

	    WeaponMacro(rhs_weap_M136_hedp,M136 (HEDP))

	    MagazineMacro(rhs_m136_hedp_mag)
	};

	class rhs_weapon_M136_hp : rhs_weapon_M136
	{
		scope = 2;
	    scopeCurator = 2;

	    WeaponMacro(rhs_weap_M136_hp,M136 (HP))

	    MagazineMacro(rhs_m136_hp_mag)
	};

	// Javelin
	class rhs_weapon_fgm148 : rhs_weapon_base
	{
		scope = 2;
	    scopeCurator = 2;

	    WeaponMacro(rhs_weap_fgm148,FGM-148 Javelin)

	    MagazineMacro(rhs_fgm148_magazine_AT)

	    vehicleClass = "WeaponsSecondary";
	};

	// Stinger
	class rhs_weapon_fim92 : rhs_weapon_base
	{
		scope = 2;
	    scopeCurator = 2;

	    WeaponMacro(rhs_weap_fim92,FIM-92F)

	    MagazineMacro(rhs_fim92_mag)

	    vehicleClass = "WeaponsSecondary";
	};

	/* ITEMS */

	class WeaponHolder_Single_limited_weapon_F;    

    class rhsusf_lerca1200_black: WeaponHolder_Single_limited_weapon_F
    {
        scope = 2;
        scopeCurator = 2;     
        simulation = "thing";
        displayName = "Lerca 1200 Rangefinder (Black)";

		Author_Macro
		picture = "\rhsusf\addons\rhsusf_weapons\misc\lerca1200\data\lerca1200black_logo.paa";
        model = "\rhsusf\addons\rhsusf_weapons\misc\lerca1200\rhs_lerca_1200_black.p3d";
        vehicleClass = "Items";
        submerged = 0;
        submergeSpeed = 0;
        timetolive = 0;
        disappearAtContact = 0;
        airFriction2[] = {0.01,0.01,0.01};
        airFriction1[] = {0.01,0.01,0.01};
        airFriction0[] = {0.01,0.01,0.01};
        airFriction = 0.09;
        airRotation = 0;
        gravityFactor = 1;        
         
        class TransportWeapons
        {
           class _xx_lerca_1200_black
            {
                weapon = "lerca_1200_black";
                count = 1;
            };
        }; 
    };

    class rhsusf_lerca1200_tan: rhsusf_lerca1200_black
    {
        scope = 2;
        scopeCurator = 2;     

        displayName = "Lerca 1200 Rangefinder (Tan)";
		
        picture = "\rhsusf\addons\rhsusf_weapons\misc\lerca1200\data\lerca1200tan_logo.paa";
        model = "\rhsusf\addons\rhsusf_weapons\misc\lerca1200\rhs_lerca_1200_tan.p3d";

         
        class TransportWeapons
        {
           class _xx_lerca_1200_tan
            {
                weapon = "lerca_1200_tan";
                count = 1;
            };
        }; 
    };

    /* MODULES */

	class Module_F;
	class Site_Minefield: Module_F
	{
		class Arguments
		{
			class minesType
			{
				class values
				{
					class rhsusf_m19_Mine
					{
						name = "M19 AT Mine";
						value = "rhsusf_mine_M19";
						default = 0;
					};
				};
			};
		};
	};
};