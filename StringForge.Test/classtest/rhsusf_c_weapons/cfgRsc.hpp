
class RscOpticsText;
class RscOpticsValue;
class RscText;
class RscPicture;
class RscControlsGroup;
class HScrollbar;
class VScrollbar;

class RscInGameUI
{
	class RscUnitInfo;

	class RHS_Flashlight
	{
		idd=3005;
		onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); call rhs_fnc_accCombo";
	};
	class RscWeaponZeroing;
	class rhs_rscOptics_at4: RscWeaponZeroing
	{
		onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); _this call RHS_fnc_at4_peep;_this call RHS_fnc_disposable_load";

	};
	class rhs_acog_pip_handler: RscWeaponZeroing
	{
		onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); [_this select 0,4,'acog']  call RHS_fnc_pip_handler";

	};
	class rhs_elcan_pip_handler: RscWeaponZeroing
	{
		onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); [_this select 0,3.4,'elcan'] call RHS_fnc_pip_handler";

	};
	class rhs_m2010_handler: RscWeaponZeroing
	{
		onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); [_this select 0,'m2010'] call RHS_fnc_m2010_handler";

	};




	class rhs_gui_optic_rangemaster1200_rangefinder: RscUnitInfo
	{
		idd = 300;

		onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); _this call RHS_fnc_leica_rf";

		controls[] = {"CA_IGUI_elements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			x="0 * 		(0.01875 * SafezoneH) + 		(SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y="0 * 		(0.025 * SafezoneH) + 		(SafezoneY)";
			w="53.5 * 		(0.01875 * SafezoneH)";
			h="40 * 		(0.025 * SafezoneH)";
			idc = 170;
			class VScrollbar
			{
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
				color[] = {1,1,1,0};
				width = 0.001;
			};
			class HScrollbar
			{
				color[] = {1,1,1,0};
				height = 0.001;
			};
			class Controls
			{
				class CA_Distance: RscOpticsValue
				{
					idc = 151;
					style = 1;
					shadow = 0;
					colorText[] = {0.94,0.26,0.28,0.9};
					font="rhs_digital_font";
					sizeEx = "0.049*SafezoneH";
					x =17.95 *   (0.01875 * Safezoneh);
					y =17.45 *   (0.025 * SafezoneH);
					//w="12.9 *   (0.01875 * SafezoneH)";
					//h="12.9 *   (0.025 * SafezoneH)";
					w="0";
					h="0";
				};
				class RHS_Distance: CA_Distance
				{
					idc = 4;
					text="";
					w="12.9 *   (0.01875 * SafezoneH)";
					h="12.9 *   (0.025 * SafezoneH)";
				};

			};
		};
		/*

(uiNamespace getVariable "RHS_LeicaLRF_Ctrl" displayCtrl 4) ctrlSetPosition [17.95 *   (0.01875 * Safezoneh),17.45 *   (0.025 * SafezoneH),12.9 *   (0.01875 * SafezoneH),12.9 *   (0.025 * SafezoneH)];(uiNamespace getVariable "RHS_LeicaLRF_Ctrl"    displayCtrl 4) ctrlCommit 1;
 

		*/


	};


};
