class CfgMovesBasic
{
	class Default;
	class DefaultDie;
 
 	class ManActions
 	{    
		RHS_GestureReloadAR15="RHS_GestureReloadAR15";
		RHS_GestureReloadM14= "RHS_GestureReloadM14";
		RHS_GestureReloadSR25= "RHS_GestureReloadSR25";
		RHS_GestureReloadM2010 = "RHS_GestureReloadM2010";
		RHS_GestureRechamberM2010 = "RHS_GestureReloadM2010";
 	};

	class Actions 
	{
	    class NoActions : ManActions 
	    {
			RHS_GestureReloadAR15[] = {"RHS_GestureReloadAR15", "Gesture"};
			RHS_GestureReloadM14[] = {"RHS_GestureReloadM14", "Gesture"};
			RHS_GestureReloadSR25[] = {"RHS_GestureReloadSR25", "Gesture"};
			RHS_GestureReloadM2010[] = { "RHS_GestureReloadM2010", "Gesture" };
			RHS_GestureRechamberM2010[] = { "RHS_GestureRechamberM2010", "Gesture" };
		};
		class RifleBaseStandActions;
		class RifleProneActions: RifleBaseStandActions
		{
			RHS_GestureReloadAR15[] = {"RHS_GestureReloadAR15_Prone", "Gesture"};
			RHS_GestureReloadM14[] = {"RHS_GestureReloadM14_Prone", "Gesture"};
			RHS_GestureReloadSR25[] = {"RHS_GestureReloadSR25_Prone", "Gesture"};
			RHS_GestureReloadM2010[] = { "RHS_GestureReloadM2010_Prone", "Gesture" };
			RHS_GestureRechamberM2010[] = { "RHS_GestureRechamberM2010_Prone", "Gesture" };
		};
		class RifleAdjustProneBaseActions;
		class RifleAdjustRProneActions: RifleAdjustProneBaseActions
		{

			RHS_GestureReloadAR15[] = {"RHS_GestureReloadAR15_Context", "Gesture"};
			RHS_GestureReloadM14[] = {"RHS_GestureReloadM14_Context", "Gesture"};
			RHS_GestureReloadSR25[] = {"RHS_GestureReloadSR25_Context", "Gesture"};
			RHS_GestureReloadM2010[] = { "RHS_GestureReloadM2010_Context", "Gesture" };
			RHS_GestureRechamberM2010[] = { "RHS_GestureRechamberM2010_Context", "Gesture" };
		};
		class RifleAdjustLProneActions: RifleAdjustProneBaseActions
		{

			RHS_GestureReloadAR15[] = {"RHS_GestureReloadAR15_Context", "Gesture"};
			RHS_GestureReloadM14[] = {"RHS_GestureReloadM14_Context", "Gesture"};
			RHS_GestureReloadSR25[] = {"RHS_GestureReloadSR25_Context", "Gesture"};
			RHS_GestureReloadM2010[] = { "RHS_GestureReloadM2010_Context", "Gesture" };
			RHS_GestureRechamberM2010[] = { "RHS_GestureRechamberM2010_Context", "Gesture" };
		};
		class RifleAdjustFProneActions: RifleAdjustProneBaseActions
		{
			RHS_GestureReloadAR15[] = {"RHS_GestureReloadAR15", "Gesture"};
			RHS_GestureReloadM14[] = {"RHS_GestureReloadM14", "Gesture"};
			RHS_GestureReloadSR25[] = {"RHS_GestureReloadSR25", "Gesture"};
			RHS_GestureReloadM2010[] = { "RHS_GestureReloadM2010", "Gesture" };
			RHS_GestureRechamberM2010[] = { "RHS_GestureRechamberM2010", "Gesture" };
		};
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class RHSUSF_flashbang_cover: Default
		{
			file = "\a3\anims_f\data\Anim\sdr\cts\cts_CrouchingCoveringRifle01";
			speed = 0.058571;
			looped = 0;
			headBobStrength = -1;
			actions = "RifleKneelActions";
			disableWeapons = 1;
			weaponIK = 1;
			canPullTrigger = 0;
			canReload = 0;
			rightHandIKCurve[] = {0,1,0.01754,0,0.97453,0,1,1};
			leftHandIKCurve[] = {0,1,0.01754,0,0.97453,0,1,1};
			connectFrom[]={"AmovPknlMstpSrasWrflDnon",0.02};
			ConnectTo[] = {"AmovPknlMstpSrasWrflDnon",0.2};
			InterpolateTo[] = {"Unconscious",0.1};
		};
	};
};

class CfgGesturesMale
{
    	class Default;
	class States
     	{
		class RHS_GestureReloadAR15_Prone: Default
		{
			file="\rhsusf\addons\rhsusf_c_weapons\anims\gestures\reload_ar15_prone.rtm";
			looped=0;
			speed=0.25;
			mask="handsWeapon";
			// mask="empty";
			headBobStrength=0.05;
			headBobMode=2;
			leftHandIKBeg = true;
			leftHandIKCurve[] = {0, 1, 0.07, 0, 0.81, 0, 0.86, 1};
			leftHandIKEnd = true;
			rightHandIKBeg = true;
			rightHandIKCurve[] = {0,1,0.08,0,0.14, 0, 0.17, 1,0.57,1,0.68,0,0.78,1};
			rightHandIKEnd = true;
		};


		class RHS_GestureReloadAR15: Default
		{
			file="\rhsusf\addons\rhsusf_c_weapons\anims\gestures\reload_ar15.rtm";
			looped=0;
			speed=0.25;
			mask="handsWeapon";
			// mask="empty";
			headBobStrength=0.05;
			headBobMode=2;
			leftHandIKBeg = true;
			leftHandIKCurve[] = {0, 1, 0.07, 0, 0.81, 0, 0.86, 1};
			leftHandIKEnd = true;
			rightHandIKBeg = true;
			rightHandIKCurve[] = {0,1,0.08,0,0.14, 0, 0.17, 1,0.57,1,0.68,0,0.78,1};
			rightHandIKEnd = true;
		};
		class RHS_GestureReloadAR15_Context: RHS_GestureReloadAR15
		{
			mask = "handsWeapon_context";
		};


		class RHS_GestureReloadSR25_Prone: Default
		{
			file="\rhsusf\addons\rhsusf_c_weapons\anims\gestures\reload_SR25_prone.rtm";
			looped=0;
			speed=0.25;
			mask="handsWeapon";
			// mask="empty";
			headBobStrength=0.05;
			headBobMode=2;
			leftHandIKBeg = true;
			leftHandIKCurve[] = {0, 1, 0.07, 0, 0.81, 0, 0.86, 1};
			leftHandIKEnd = true;
			rightHandIKBeg = true;
			rightHandIKCurve[] = {0,1,0.08,0,0.14, 0, 0.17, 1,0.57,1,0.68,0,0.78,1};
			rightHandIKEnd = true;
		};


		class RHS_GestureReloadSR25: Default
		{
			file="\rhsusf\addons\rhsusf_c_weapons\anims\gestures\reload_SR25.rtm";
			looped=0;
			speed=0.25;
			mask="handsWeapon";
			// mask="empty";
			headBobStrength=0.05;
			headBobMode=2;
			leftHandIKBeg = true;
			leftHandIKCurve[] = {0, 1, 0.07, 0, 0.81, 0, 0.86, 1};
			leftHandIKEnd = true;
			rightHandIKBeg = true;
			rightHandIKCurve[] = {0,1,0.08,0,0.14, 0, 0.17, 1,0.57,1,0.68,0,0.78,1};
			rightHandIKEnd = true;
		};
		class RHS_GestureReloadSR25_Context: RHS_GestureReloadSR25
		{
			mask = "handsWeapon_context";
		};

		class RHS_GestureReloadM2010_Prone : Default
		{
			file = "\rhsusf\addons\rhsusf_c_weapons\anims\gestures\reload_m2010_prone.rtm";
			looped = 0;
			speed = 0.15;
			mask = "handsWeapon";
			// mask="empty";
			headBobStrength = 0.05;
			headBobMode = 2;
			leftHandIKBeg = true;
			leftHandIKCurve[] = { 0, 1, 0.08, 1, 0.12, 0, 0.89, 0, 0.925, 1 };
			leftHandIKEnd = true;
			rightHandIKBeg = true;
			rightHandIKCurve[] = { 0, 1, 0.02, 0, 0.845, 0, 0.87, 1 };
			rightHandIKEnd = true;
		};


		class RHS_GestureReloadM2010 : Default
		{
			file = "\rhsusf\addons\rhsusf_c_weapons\anims\gestures\reload_m2010_standing.rtm";
			looped = 0;
			speed = 0.15;
			mask = "handsWeapon";
			// mask="empty";
			headBobStrength = 0.05;
			headBobMode = 2;
			leftHandIKBeg = true;
			leftHandIKCurve[] = { 0, 1, 0.08, 1, 0.12, 0, 0.89, 0, 0.925, 1 };
			leftHandIKEnd = true;
			rightHandIKBeg = true;
			rightHandIKCurve[] = { 0, 1, 0.08, 0, 0.13, 0, 0.15, 1, 0.715, 1, 0.735, 0, 0.84, 0, 0.865, 1 };
			rightHandIKEnd = true;
		};
		class RHS_GestureReloadM2010_Context : RHS_GestureReloadM2010
		{
			mask = "handsWeapon_context";
		};
		class RHS_GestureRechamberM2010_Prone : Default
		{
			file = "\rhsusf\addons\rhsusf_c_weapons\anims\gestures\rechamber_m2010_prone.rtm";
			looped = 0;
			speed = 0.6;
			mask = "handsWeapon";
			// mask="empty";
			headBobStrength = 0.05;
			headBobMode = 2;
			leftHandIKBeg = true;
			leftHandIKCurve[] = {1};
			leftHandIKEnd = true;
			rightHandIKBeg = true;
			rightHandIKCurve[] = { 0, 1, 0.01666667, 0, 0.7912, 0, 0.953, 1 };
			rightHandIKEnd = true;
			enableOptics = 1;
		};


		class RHS_GestureRechamberM2010 : Default
		{
			enableOptics = 1;
			file = "\rhsusf\addons\rhsusf_c_weapons\anims\gestures\rechamber_m2010_standing.rtm";
			looped = 0;
			speed = 0.6;
			mask = "handsWeapon";
			// mask="empty";
			headBobStrength = 0.05;
			headBobMode = 2;
            		disableWeapons = 0;
			leftHandIKBeg = true;
			leftHandIKCurve[] = { 1 };
			leftHandIKEnd = true;
			rightHandIKBeg = true;
			rightHandIKCurve[] = { 0, 1, 0.01666667, 0, 0.7912, 0, 0.953, 1 };
			rightHandIKEnd = true;
		};
		class RHS_GestureRechamberM2010_Context : RHS_GestureRechamberM2010
		{
			mask = "handsWeapon_context";
		};
		class RHS_GestureReloadM14:Default
		{
			file="\rhsusf\addons\rhsusf_c_weapons\anims\gestures\reload_m14_standing.rtm";
			speed=0.23;
			looped = false;
			mask = "handsWeapon";
			headBobStrength=0.2;
			headBobMode=2;
			rightHandIKCurve[] = {0, 1,0.59,1,0.615384,0,0.7538 ,0,0.84615,1 };
			leftHandIKBeg = true;
			leftHandIKEnd = true;
			leftHandIKCurve[] = {0, 1, 0.04166666, 0, 0.58416, 0, 0.615384, 1};
		};
		class RHS_GestureReloadM14_Prone:Default
		{
			file="\rhsusf\addons\rhsusf_c_weapons\anims\gestures\reload_m14_prone.rtm";
			speed=0.23;
			looped = false;
			mask = "handsWeapon";
			headBobStrength=0.2;
			headBobMode=2;
			rightHandIKCurve[] = {1};
			leftHandIKBeg = true;
			leftHandIKEnd = true;
			leftHandIKCurve[] = {0, 1, 0.04166666, 0, 0.86666, 0, 0.9, 1};
		};
		class RHS_GestureReloadM14_Context: RHS_GestureReloadM14
		{
			mask = "handsWeapon_context";
		};
	};
};