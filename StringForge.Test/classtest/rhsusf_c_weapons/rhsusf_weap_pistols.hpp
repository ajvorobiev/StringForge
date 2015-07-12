class hgun_ACPC2_F;

class rhsusf_weap_m1911a1: hgun_ACPC2_F
{
	Author_Macro
  scope = 2;
  displayName = "$STR_RHS_CFGWEAPONS_PISTOL_M1911A1";
  model = "\rhsusf\addons\rhsusf_weapons\pistols\M1911A1\rhs_m1911a1";
  modelOptics = "-";
  picture = "\rhsusf\addons\rhsusf_weapons\icons\p_m1911a1_ca.paa";
  minRange = 5;
  minRangeProbab = 0.3;
  midRange = 25;
  midRangeProbab = 0.6;
  maxRange = 50;
  maxRangeProbab = 0.1;
  aiRateOfFire = 2;
  aiRateOfFireDistance = 25;
  optics = 1;
  distanceZoomMin = 50;
  distanceZoomMax = 50;
  inertia = 0.2;
  dexterity = 1.8;
  initSpeed = 280;
  begin1[] = {"A3\Sounds_F\arsenal\weapons\Pistols\Acpc2\acpc2_01",1.2589254,1,1400};
  soundBegin[] = {"begin1",1};


  class WeaponSlotsInfo
  {
    mass=8;
    class CowsSlot{};
    class MuzzleSlot{};
    class PointerSlot {};
  };

  magazines[] = {"rhsusf_mag_7x45acp_MHP"};
  dispersion = 0.02;
  reloadTime = 0.13;
  ffCount = 1;
};