
class CfgFunctions
{
	class RHS
	{
		tag = "RHS";
		class functions
		{
			class virtualAmmoBoxUSA
			{
				file = "\rhsusf\addons\rhsusf_c_weapons\scripts\virtualAmmoBox.sqf";
				description = "[nameOfObject,type (type number: 0 - all gear, 1 - ammo only)] call rhs_fnc_virtualAmmoBoxUSA, make a object virtual ammo box with american gear inside";
			};
			class accCombo
			{
				file = "\rhsusf\addons\rhsusf_c_weapons\scripts\acc_combo.sqf";
				description = "Handling of surefire/ir laser combo";
			};
			class disposable_usf
			{
				file = "\rhsusf\addons\rhsusf_c_weapons\scripts\rhs_disposable.sqf";
				description = "Handling of surefire/ir laser combo";
			};
			class disposable_load
			{
				file = "\rhsusf\addons\rhsusf_c_weapons\scripts\rhs_disposable_load.sqf";
				description = "Handling of surefire/ir laser combo";
			};
			class at4_peep
			{
				file = "\rhsusf\addons\rhsusf_c_weapons\scripts\rhs_at4_peep.sqf";
				description = "Handling of AT4 Peephole";
			};
			class pip_handler
			{
				file = "\rhsusf\addons\rhsusf_c_weapons\scripts\rhs_pip_handler.sqf";
				description = "Handling of AT4 Peephole";
			};
			class m2010_handler
			{
				file = "\rhsusf\addons\rhsusf_c_weapons\scripts\rhs_m2010_handler.sqf";
				description = "Handling of AT4 Peephole";
			};
			class leica_rf
			{
				file = "\rhsusf\addons\rhsusf_c_weapons\scripts\rhs_leica_rf.sqf";
				description = "Leica Rangemaster 1200 LRF handler";
			};
			class usf_flashbang
			{
				file = "\rhsusf\addons\rhsusf_c_weapons\scripts\rhs_flashbang.sqf";
				description = "flashbang handler";
			};
			class usf_flashbang_effect
			{
				file = "\rhsusf\addons\rhsusf_c_weapons\scripts\rhs_flashbang_effect.sqf";
				description = "flashbang effect";
			};
		};
	};
};


class CfgSounds
{
	class RHSUSF_Flashbang
	{
		name="Flashbang explosion";
		sound[]=
		{
			"\rhsusf\addons\rhsusf_c_weapons\sounds\flashbang.ogg",
			1,
			1
		};
		titles[]={};
	};
};