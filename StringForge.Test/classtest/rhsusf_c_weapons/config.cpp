#include "script_component.hpp"
#include "script_config.hpp"

class CfgPatches {
	class rhsusf_c_weapons {
		units[] = 
		{
			rhsusf_weapons_crate,
			rhsusf_ammo_crate


		};
		weapons[] = {"rhsusf_weap_XM2010"};
		requiredVersion= 1.32;
		requiredAddons[] = 		{
			"A3_Weapons_F_Acc",
			"A3_Functions_F_Bootcamp",
			"A3_Weapons_F",
			"A3_Weapons_F_Explosives",
			"A3_Weapons_F_Ammoboxes",
			"A3_Weapons_F_beta",
			"A3_Weapons_F_EBR",
			"A3_Weapons_F_Machineguns_M200"
		};
		version = VERSION;

	};
};

class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class GrenadeLauncher;
class SlotInfo;
class CowsSlot;
class PointerSlot;
class UnderBarrelSlot;

#include "cfgRsc.hpp"
#include "particles.hpp"

//asdg JR support
class asdg_SlotInfo;
class asdg_OpticRail;
class asdg_OpticRail1913: asdg_OpticRail
{
	linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
	displayName="$STR_A3_CowsSlot0";
	class compatibleItems
	{
		optic_Nightstalker=1;
		optic_tws=1;
		optic_tws_mg=1;
		optic_NVS=1;
		optic_SOS=1;
		optic_MRCO=1;
		optic_Arco=1;
		optic_aco=1;
		optic_ACO_grn=1;
		optic_aco_smg=1;
		optic_ACO_grn_smg=1;
		optic_hamr=1;
		optic_Holosight=1;
		optic_Holosight_smg=1;
		optic_DMS=1;
		optic_LRPS=1;
		optic_AMS=1;
		optic_AMS_khk=1;
		optic_AMS_snd=1;
		optic_KHS_blk=1;
		optic_KHS_hex=1;
		optic_KHS_old=1;
		optic_KHS_tan=1;

		rhsusf_acc_LEUPOLDMK4=1;
		rhsusf_acc_LEUPOLDMK4_2=1;
		rhsusf_acc_EOTECH=1;
		rhsusf_acc_eotech_552=1;
		rhsusf_acc_compm4=1;
		rhsusf_acc_ELCAN=1;
		rhsusf_acc_ELCAN_PIP=1;
		rhsusf_acc_ACOG=1;
		rhsusf_acc_ACOG2=1;
		rhsusf_acc_ACOG3=1;
		rhsusf_acc_ACOG_USMC=1;
		rhsusf_acc_ACOG2_USMC=1;
		rhsusf_acc_ACOG3_USMC=1;
		rhsusf_acc_ACOG_PIP=1;
	};
};
class asdg_OpticRail1913_short: asdg_OpticRail1913
{
	class compatibleItems: compatibleItems
	{
		rhsusf_acc_LEUPOLDMK4=0;
		rhsusf_acc_LEUPOLDMK4_2=0;
	};
};
class asdg_OpticRail1913_long: asdg_OpticRail1913
{
};
class asdg_UnderSlot: asdg_SlotInfo
{
	class compatibleItems;
};
//because of arsenal limitation weapons need to be listed twice
class rhs_western_rifle_scopes_slot_short: asdg_OpticRail1913_short{};
class rhs_western_rifle_scopes_slot_long: asdg_OpticRail1913_long {};
class rhs_western_rifle_underbarrel_slot_bis: UnderBarrelSlot{};


class asdg_MuzzleSlot;
class asdg_MuzzleSlot_556: asdg_MuzzleSlot
{
        displayName = "$str_a3_cfgweapons_abr_base_f_weaponslotsinfo_muzzleslot0";
	linkProxy = "\A3\data_f\proxies\weapon_slots\MUZZLE";
	class compatibleItems
	{
		rhsusf_acc_rotex5_grey=1;
		rhsusf_acc_rotex5_tan=1;
		rhsusf_acc_SF3P556=1;
		rhsusf_acc_SFMB556=1;
		rhsusf_acc_nt4_black=1;
		rhsusf_acc_nt4_tan=1;
	};
};
class rhs_western_rifle_muzzle_slot: asdg_MuzzleSlot_556
{
	class compatibleItems: compatibleItems
	{
		muzzle_snds_M=0;
	};
};

class rhs_western_rifle_underbarrel_slot: asdg_UnderSlot
{
	linkProxy="\a3\data_f_mark\proxies\weapon_slots\underbarrel";
    iconPicture = "\A3\Weapons_F_Mark\Data\UI\attachment_under.paa";
    iconPinpoint = "Bottom";
	displayName="$STR_A3_CowsSlot0";
	class compatibleItems: compatibleItems
	{
		bipod_01_F_snd=1;
		bipod_01_F_blk=1;
		bipod_01_F_mtp=1;
		bipod_02_F_blk=1;
		bipod_02_F_tan=1;
		bipod_02_F_hex=1;
		bipod_03_F_blk=1;
		bipod_03_F_oli=1;
		rhsusf_acc_harris_bipod=1;
	};
};

//this one is now used only to get data to russian virtual ammobox 
//expect proper script to get from new array one day
class rhs_western_rifle_scopes_slot: CowsSlot
{
	compatibleItems[] = 
	{
		"rhsusf_acc_LEUPOLDMK4",
		"rhsusf_acc_LEUPOLDMK4_2",
		"rhsusf_acc_EOTECH",
		"rhsusf_acc_eotech_552",
		"rhsusf_acc_compm4",
		"rhsusf_acc_ELCAN",
		"rhsusf_acc_ELCAN_PIP",
		"rhsusf_acc_ACOG",
		"rhsusf_acc_ACOG2",
		"rhsusf_acc_ACOG3",
		"rhsusf_acc_ACOG_USMC",
		"rhsusf_acc_ACOG2_USMC",
		"rhsusf_acc_ACOG3_USMC",
		"rhsusf_acc_ACOG_PIP"
	};
};


class asdg_FrontSideRail: asdg_SlotInfo
{
	linkProxy = "\a3\data_f\proxies\weapon_slots\side";
	displayName = "$STR_A3_PointerSlot0";
	class compatibleItems
	{
		acc_flashlight=1;
		acc_pointer_IR=1;
		///rhs
		rhsusf_acc_anpeq15A=1;
		rhsusf_acc_anpeq15=1;
		rhsusf_acc_anpeq15side=1;
		rhsusf_acc_anpeq15_light=1;
	};
};
//top & side rail
class rhs_western_rifle_laser_slot_top: asdg_FrontSideRail {};
//only side rail
class rhs_western_rifle_laser_slot: rhs_western_rifle_laser_slot_top
{
	class compatibleItems: compatibleItems
	{
		acc_flashlight=1;
		acc_pointer_IR=1;
		rhsusf_acc_anpeq15A=1;
		rhsusf_acc_anpeq15side=1;
		rhsusf_acc_anpeq15=0;
		rhsusf_acc_anpeq15_light=0;
	};
};


class CfgMineTriggers
{
	class WireTrigger;
	class rhs_M19_Trigger: WireTrigger
	{
		mineTriggerRange = 0;
		mineTriggerMass = 136;
		//dunno what magnetic means in that case?
		mineMagnetic = 0;
		mineWireStart[] = {0,0,0};
		mineWireEnd[] = {0,1,0};
		restrictZoneCenter[] = {0,0,0};
		restrictZoneRadius = 5;
	};
};

#include "cfgAmmo.h"
#include "cfgMagazines.h"
#include "cfgWeapons.h"

#include "cfgFunctions.hpp"
#include "CfgMovesBasic.hpp"

#include "cfgVehicles.h"



