class Rangefinder;
class binocular;

class lerca_1200_black: Rangefinder
{
		author = "Red Hammer Studios";
		_generalMacro = "Rangefinder";
		scope = 2;
		displayName = "$STR_RHSUSF_MISC_LERCA_BLACK";
		class Library
		{
			libTextDesc = "$STR_A3_cfgWeapons_Rangefinder_Library0";
		};
		descriptionShort = "Lerca Rangefinder";
		model = "\rhsusf\addons\rhsusf_weapons\misc\lerca1200\rhs_lerca_1200_black.p3d";
		modelOptics = "\rhsusf\addons\rhsusf_weapons\misc\lerca1200\rhs_lerca_reticle.p3d";
		picture = "\rhsusf\addons\rhsusf_weapons\misc\lerca1200\data\lerca1200black_logo.paa";
		opticsZoomMin = 0.01;
		opticsZoomMax = 0.05;
		opticsZoomInit = 0.01;
		distanceZoomMin = 15;
		distanceZoomMax = 1097;
		weaponInfoType = "rhs_gui_optic_rangemaster1200_rangefinder";
		visionMode[] = {"Normal"};
		class WeaponSlotsInfo
		{
			mass = 20;
		};
};

class lerca_1200_tan: Rangefinder
{
		author = "Red Hammer Studios";
		_generalMacro = "Rangefinder";
		scope = 2;
		displayName = "$STR_RHSUSF_MISC_LERCA_TAN";
		class Library
		{
			libTextDesc = "$STR_A3_cfgWeapons_Rangefinder_Library0";
		};
		descriptionShort = "Lerca Rangefinder";
		model = "\rhsusf\addons\rhsusf_weapons\misc\lerca1200\rhs_lerca_1200_tan.p3d";
		modelOptics = "\rhsusf\addons\rhsusf_weapons\misc\lerca1200\rhs_lerca_reticle.p3d";
		picture = "\rhsusf\addons\rhsusf_weapons\misc\lerca1200\data\lerca1200tan_logo.paa";
		opticsZoomMin = 0.01;
		opticsZoomMax = 0.05;
		opticsZoomInit = 0.01;
		distanceZoomMin = 15;
		distanceZoomMax = 1097;
		weaponInfoType = "rhs_gui_optic_rangemaster1200_rangefinder";
		visionMode[] = {"Normal"};
		class WeaponSlotsInfo
		{
			mass = 20;
		};

};
	class Leupold_Mk4: binocular
{
		author = "Red Hammer Studios";
		scope = 2;
		displayName = "$STR_RHSUSF_MISC_LEUPOLD_SPOTTER";
		class Library
		{
			libTextDesc = "$STR_A3_cfgWeapons_Rangefinder_Library0";
		};
		descriptionShort = "Leupold_spotting Scope";
		model = "\rhsusf\addons\rhsusf_weapons\misc\LeupoldMk4\Rhs_Spotter_mk4.p3d";
		modelOptics = "\rhsusf\addons\rhsusf_weapons\misc\LeupoldMk4\Rhs_Spotter_reticle.p3d";
		picture = "\rhsusf\addons\rhsusf_weapons\misc\LeupoldMk4\Data\Rhs_mk4_icon.paa";
		opticsZoomMin = 0.05;
		opticsZoomMax = 0.05;
		opticsZoomInit = 0.05;
		distanceZoomMin = 1097;
		distanceZoomMax = 1097;
		visionMode[] = {"Normal"};
		class WeaponSlotsInfo
		{
			mass = 20;
		};
};


