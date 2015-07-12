class CfgMagazines
{
	class CA_Magazine;
	class CA_LauncherMagazine;
	class FakeMagazine;
	class 30Rnd_556x45_Stanag; 
	
	class rhs_mag_30Rnd_556x45_M855A1_Stanag : 30Rnd_556x45_Stanag
	{
		initSpeed = 960;
		ammo = "rhs_ammo_556x45_M855A1_Ball";
		Author_Macro
		displayName = $STR_RHSUSF_30RND_556x45_DISPLAY_NAME;
		descriptionShort = $STR_RHSUSF_30RND_556x45_DESCRIPTION_SHORT;
		tracersEvery = 0;
		lastRoundsTracer = 4;
		model = "\rhsusf\addons\rhsusf_weapons\magazines\rhs_stanag_mag";

		/*
			oh you bis, why u not make stuff working
			magazineGroup[] = {"rhs_556x45_Stanag"};
		*/
	};
	
	class rhs_mag_30Rnd_556x45_M855A1_Stanag_No_Tracer : rhs_mag_30Rnd_556x45_M855A1_Stanag
	{
		ammo = "rhs_ammo_556x45_M855A1_Ball";
		Author_Macro
		displayName = $STR_RHSUSF_30RND_556x45_NO_TRACER_DISPLAY_NAME;
		descriptionShort = $STR_RHSUSF_30RND_556x45_NO_TRACER_DESCRIPTION_SHORT;
		lastRoundsTracer = 0;
	};
	
	class rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Red : rhs_mag_30Rnd_556x45_M855A1_Stanag
	{
		ammo = "rhs_ammo_556x45_M855A1_Ball_Red";
		Author_Macro
		displayName = $STR_RHSUSF_30RND_556x45_TRACER_RED_DISPLAY_NAME;
		descriptionShort = $STR_RHSUSF_30RND_556x45_TRACER_RED_DESCRIPTION_SHORT;
		tracersEvery = 1;

		picture = "\A3\weapons_F\data\UI\m_30stanag_red_ca.paa";
	};

	class rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Green : rhs_mag_30Rnd_556x45_M855A1_Stanag
	{
		ammo = "rhs_ammo_556x45_M855A1_Ball_Green";
		Author_Macro
		displayName = $STR_RHSUSF_30RND_556x45_TRACER_GREEN_DISPLAY_NAME;
		descriptionShort = $STR_RHSUSF_30RND_556x45_TRACER_GREEN_DESCRIPTION_SHORT;
		tracersEvery = 1;

		picture = "\A3\weapons_F\data\UI\m_30stanag_green_ca.paa";
	};

	class rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Yellow : rhs_mag_30Rnd_556x45_M855A1_Stanag
	{
		ammo = "rhs_ammo_556x45_M855A1_Ball_Yellow";
		Author_Macro
		displayName = $STR_RHSUSF_30RND_556x45_TRACER_YELLOW_DISPLAY_NAME;
		descriptionShort = $STR_RHSUSF_30RND_556x45_TRACER_YELLOW_DESCRIPTION_SHORT;
		tracersEvery = 1;

		picture = "\A3\weapons_F\data\UI\m_30stanag_yellow_CA.paa";
	};

	class rhs_mag_30Rnd_556x45_Mk318_Stanag : rhs_mag_30Rnd_556x45_M855A1_Stanag
	{
		ammo = "rhs_ammo_556x45_Mk318_Ball";
		initSpeed = 950.3664;
		Author_Macro
		displayName = $STR_RHSUSF_30RND_556x45_MK318_DISPLAY_NAME;
		descriptionShort = $STR_RHSUSF_30RND_556x45_MK318_DESCRIPTION_SHORT;
	};

	class rhs_mag_30Rnd_556x45_Mk262_Stanag : rhs_mag_30Rnd_556x45_M855A1_Stanag
	{
		ammo = "rhs_ammo_556x45_Mk262_Ball";
		initSpeed = 838.2;
		Author_Macro
		displayName = $STR_RHSUSF_30RND_556x45_MK262_DISPLAY_NAME;
		descriptionShort = $STR_RHSUSF_30RND_556x45_MK262_DESCRIPTION_SHORT;
	};

	
	class rhs_mag_30Rnd_556x45_M200_Stanag : rhs_mag_30Rnd_556x45_M855A1_Stanag
	{
		ammo = "rhs_ammo_556x45_blank";
		initSpeed = 2;
		Author_Macro
		displayName = $STR_RHSUSF_30RND_556x45_BLANK_DISPLAY_NAME;
		descriptionShort = $STR_RHSUSF_30RND_556x45_BLANK_DESCRIPTION_SHORT;
		lastRoundsTracer = 0;
	};
	//M203/320 grenades

	class 1Rnd_HE_Grenade_shell;
 	class rhs_mag_M441_HE: 1Rnd_HE_Grenade_shell 
	{
		Author_Macro
		ammo = "G_40mm_HE";
		displayName = "M441 HE Grenade Round";
		displaynameshort = "HE Grenade";
		descriptionshort = "Type: High Explosive Grenade Round<br />Caliber: 40 mm<br />Rounds: 1<br />Used in: M203/M320/M79";
		//magazineGroup[] = {"rhs_40mm_ugl"};
	};
 	class rhs_mag_M433_HEDP: rhs_mag_M441_HE
	{
		Author_Macro
		displayName = "M433 HEDP Grenade Round";
		displaynameshort = "HEDP Grenade";
		ammo = "G_40mm_HEDP";
	};
	//flashbang
 	class rhs_mag_m4009: rhs_mag_M441_HE
	{
		Author_Macro
		displayName = "GL Stun Grenade Round";
		displaynameshort = "Stun Grenade";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\m576_buckshot_ca.paa";
		ammo = "rhs_g_vg40sz";
	};
	//buckshot
 	class rhs_mag_m576: rhs_mag_M441_HE
	{
		Author_Macro
		displayName = "M576 Buckshot Grenade";
		displaynameshort = "Buckshot";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\m576_buckshot_ca.paa";
		ammo = "rhs_ammo_m576_buckshot";
	};

	//flare
 	class rhs_mag_M585_white: rhs_mag_M441_HE
	{
		Author_Macro
		displayName = "M585 White Flare Round";
		displaynameshort = "White Flare";
		ammo = "rhsusf_40mm_white";
		picture="\A3\Weapons_F\Data\UI\gear_UGL_Flare_CA.paa";
	};
 	class rhs_mag_m661_green: rhs_mag_M585_white
	{
		Author_Macro
		displayName = "M661 Green Flare Round";
		displaynameshort = "Green Flare";
		ammo = "rhsusf_40mm_green";
		picture="\A3\Weapons_F\Data\UI\gear_UGL_Flare_green_CA.paa";
	};
 	class rhs_mag_m662_red: rhs_mag_M585_white
	{
		Author_Macro
		displayName = "M662 Red Flare Round";
		displaynameshort = "Red Flare";
		ammo = "rhsusf_40mm_red";
		picture="\A3\Weapons_F\Data\UI\gear_UGL_Flare_Red_CA.paa";
	};
	//smoke
 	class rhs_mag_m713_Red: rhs_mag_M441_HE
	{
		Author_Macro
		displayName = "M713 Red Smoke Round";
		displaynameshort = "Red Smoke";
		descriptionShort = "Type: Smoke Grenade - Red<br />Caliber: 40 mm<br /><br />Rounds: 1<br />Used in: M203/M320/M79";
		picture="\A3\Weapons_f\Data\UI\gear_UGL_Smokeshell_red_CA.paa";
		ammo = "SmokeShellRed";
	};
 	class rhs_mag_m714_White: rhs_mag_m713_Red
	{
		Author_Macro
		displayName = "M714 White Smoke Round";
		displaynameshort = "White Smoke";
		descriptionShort = "Type: Smoke Grenade - White<br />Caliber: 40 mm<br /><br />Rounds: 1<br />Used in: M203/M320/M79";
		picture="\A3\Weapons_f\Data\UI\gear_UGL_Smokeshell_white_CA.paa";
		ammo = "SmokeShell";
	};
 	class rhs_mag_m715_Green: rhs_mag_m713_Red
	{
		Author_Macro
		displayName = "M715 Green Smoke Round";
		displaynameshort = "Green Smoke";
		descriptionShort = "Type: Smoke Grenade - Green<br />Caliber: 40 mm<br /><br />Rounds: 1<br />Used in: M203/M320/M79";
		picture="\A3\Weapons_f\Data\UI\gear_UGL_Smokeshell_green_CA.paa";
		ammo = "SmokeShellGreen";
	};
 	class rhs_mag_m716_yellow: rhs_mag_m713_Red
	{
		Author_Macro
		displayName = "M716 Yellow Smoke Round";
		displaynameshort = "Yellow Smoke";
		descriptionShort = "Type: Smoke Grenade - Green<br />Caliber: 40 mm<br /><br />Rounds: 1<br />Used in: M203/M320/M79";
		picture="\A3\Weapons_f\Data\UI\gear_UGL_Smokeshell_yellow_CA.paa";
		ammo = "SmokeShellYellow";
	};


	///! Rifle Mags
	class rhsusf_5Rnd_300winmag_xm2010 : CA_Magazine
	{
		scope = 2;
		Author_Macro
		displayName = $STR_rhsusf_5Rnd_300winmag_xm2010;
		model = "\rhsusf\addons\rhsusf_weapons\magazines\rhs_win_mag";
		picture = "\A3\Weapons_F_EPA\Data\ui\M_5rnd_127x108_ball_CA.paa";
		ammo = "rhsusf_B_300winmag";
		count = 5;
		initSpeed = 869;
		tracersEvery = 0;
		lastRoundsTracer = 0;
		descriptionShort = $STR_rhsusf_5Rnd_300winmag_xm2010;
		mass = 	13;
	};

	class 10Rnd_RHS_50BMG_Box : CA_Magazine 
	{
		Author_Macro
		scope = 2;
		value = 1;
		displayName = "";
		model = "\A3\weapons_F\ammo\mag_univ.p3d";
		picture = "";
		modelSpecial = "";
		useAction = false;
		useActionTitle = "";
		reloadAction = "";
		ammo = "rhsusf_M33_Ball_M107";
		count = 10;
		type = 256;
		initSpeed = 853;
		selectionFireAnsim = "zasleh";
		nameSound = "magazine";
		maxLeadSpeed = 23;	// max estimated speed km/h
		weaponpoolavailable = 1;
		mass = 8;
	};

	class rhsusf_10Rnd_STD_50BMG_M107 : 10Rnd_RHS_50BMG_Box
	{
		initSpeed = 853;
		displayName = "10RD .50BMG STD Box";
		descriptionShort = "10RD .50BMG Barrett STD Box";
		tracersEvery = 0;
		lastRoundsTracer = 1;
		model = "\rhsusf\addons\rhsusf_weapons\magazines\rhs_50cal_box_mag";

		/*
			oh you bis, why u not make stuff working
			magazineGroup[] = {"RHS_50BMG_Box"};
		*/
	};
	
	class rhsusf_5Rnd_00Buck : CA_Magazine
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHSUSF_5RND_12G_00BUCKSHOT_DISPLAY_NAME;

		picture = "\rhsusf\addons\rhsusf_weapons\icons\m_12g_buck.paa";
		model = "\rhsusf\addons\rhsusf_weapons\magazines\12g\12g_buckshot";
		ammo = "rhs_ammo_12g_00buckshot";

		count = 5;
		mass = 	5;

		initSpeed = 336;
	};
	class rhsusf_8Rnd_00Buck : rhsusf_5Rnd_00Buck
	{
		displayName = $STR_RHSUSF_8RND_12G_00BUCKSHOT_DISPLAY_NAME;

		count = 8;
		mass = 	8;

		initSpeed = 403;
	};

	class rhsusf_5Rnd_Slug : CA_Magazine
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHSUSF_5RND_12G_SLUG_DISPLAY_NAME;

		picture = "\rhsusf\addons\rhsusf_weapons\icons\m_12g_slug.paa";
		model = "\rhsusf\addons\rhsusf_weapons\magazines\12g\12g_slug";
		ammo = "rhs_ammo_12g_slug";

		count = 5;
		mass = 	5;

		initSpeed = 395;
	};
	class rhsusf_8Rnd_Slug : rhsusf_5Rnd_Slug
	{
		displayName = $STR_RHSUSF_8RND_12G_SLUG_DISPLAY_NAME;

		count = 8;
		mass = 	8;

		initSpeed = 475;
	};

	class rhsusf_5Rnd_HE : rhsusf_8Rnd_Slug
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHSUSF_5RND_12G_HEEP_DISPLAY_NAME;

		picture = "\rhsusf\addons\rhsusf_weapons\icons\m_12g_heep.paa";
		model = "\rhsusf\addons\rhsusf_weapons\magazines\12g\12g_he";
		ammo = "rhs_ammo_12g_HE";

		count = 5;
		mass = 	5;

		typicalSpeed = 125;
	};
	class rhsusf_8Rnd_HE : rhsusf_5Rnd_HE
	{
		displayName = $STR_RHSUSF_8RND_12G_HEEP_DISPLAY_NAME;

		count = 8;
		mass = 	8;

		typicalSpeed = 150;
	};

	class rhsusf_5Rnd_FRAG : rhsusf_8Rnd_HE
	{
		scope = 2;
		Author_Macro
		displayName = $STR_RHSUSF_5RND_12G_FRAG_DISPLAY_NAME;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\m_12g_frag.paa";
		model = "\rhsusf\addons\rhsusf_weapons\magazines\12g\12g_frag";
		ammo = "rhs_ammo_12g_FRAG";
		count = 5;
		mass = 	5;

		typicalSpeed = 125;
	};
	class rhsusf_8Rnd_FRAG : rhsusf_5Rnd_FRAG
	{
		displayName = $STR_RHSUSF_8RND_12G_FRAG_DISPLAY_NAME;

		count = 8;
		mass = 	8;

		typicalSpeed = 150;
	};
	
	class rhsusf_5Rnd_doomsday_Buck : rhsusf_5Rnd_00Buck
	{
		Author_Macro
		displayName = "5Rnd 12g Doosmday Buckshot";
		ammo = "rhs_ammo_doomsday_buckshot";
		count = 5;
	};
	class rhsusf_8Rnd_doomsday_Buck : rhsusf_5Rnd_doomsday_Buck
	{
		scope = 2;
		Author_Macro
		displayName = "8Rnd 12g Doosmday Buckshot";
		ammo = "rhs_ammo_doomsday_buckshot";
		count = 8;
		mass = 	15;
	};
	
	
	class rhsusf_100Rnd_556x45_soft_pouch : rhs_mag_30Rnd_556x45_M855A1_Stanag
	{
		ammo = "rhs_ammo_556x45_M855A1_Ball_Red";
		count = 100;
		
		Author_Macro
		displayName = "100Rnd Belt Mag (5.56x45 M855A1)";
		model = "\rhsusf\addons\rhsusf_weapons\magazines\rhs_softpouch_mag";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\m_m245_ca.paa";
		
		descriptionShort = "Caliber: 5.56x45 mm STANAG<br />Rounds: 100<br />Used in: M249";
		class Library
		{
			libTextDesc = "100rnd M249 soft pouch magazine.";
		};
		mass = 38;
		tracersEvery = 4;
		lastRoundsTracer = 10;
		//initSpeed = 915;
		//magazineGroup[] = {"rhs_556x45_soft_pouch"};
	};
	
	class rhsusf_100Rnd_556x45_M200_soft_pouch : rhs_mag_30Rnd_556x45_M200_Stanag
	{
		ammo = "rhs_ammo_556x45_blank";
		count = 100;
		
		Author_Macro
		displayName = "100Rnd Belt Mag (5.56x45 M200)";
		model = "\A3\weapons_F\ammo\mag_univ.p3d";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\m_m245_ca.paa";
		
		descriptionShort = "Caliber: 5.56x45 mm M200 STANAG<br />Rounds: 100<br />Used in: M249";
		class Library
		{
			libTextDesc = "100rnd M249 soft pouch magazine (M200)";
		};
		mass = 30;
		tracersEvery = 0;
		lastRoundsTracer = 0;
		//initSpeed = 915;
	};
	
	class rhsusf_200Rnd_556x45_soft_pouch : rhsusf_100Rnd_556x45_soft_pouch
	{
		count = 200;
		
		Author_Macro
		displayName = "200Rnd Belt Mag (5.56x45 M855A1)";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\m_m245_ca.paa";
		
		descriptionShort = "Caliber: 5.56x45 mm STANAG<br />Rounds: 200<br />Used in: M249";
		class Library
		{
			libTextDesc = "200rnd M249 soft pouch magazine.";
		};
		mass = 58;
	};

	class rhsusf_50Rnd_762x51 : CA_Magazine
	{
		scope = 2;
		Author_Macro
		displayName = "50Rnd Belt Mag (7.62x51 M80)";
		model = "\rhsusf\addons\rhsusf_weapons\magazines\rhs_m240_mag";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\m_m245_ca.paa";
		
		descriptionShort = "Caliber: 7.62x51 NATO<br />Rounds: 50<br />Used in: M240";
		count=50;
		type = 2*WeaponSlotItem;
		ammo = "rhs_ammo_762x51_M80_Ball";
		initSpeed = 838;
		tracersEvery = 4;
		lastRoundsTracer = 4;
		mass = 24;
		//magazineGroup[] = {"rhs_762x51_box"};
	};
	class rhsusf_50Rnd_762x51_m80a1epr : rhsusf_50Rnd_762x51
	{
		displayName = "50Rnd Belt Mag (7.62x51 M80A1EPR)";
		ammo = "rhs_ammo_762x51_M80A1EPR_Ball";
		initSpeed = 803;
	};
	class rhsusf_50Rnd_762x51_m993 : rhsusf_50Rnd_762x51
	{
		displayName = "50Rnd Belt Mag (7.62x51 M993)";
		ammo = "rhs_ammo_762x51_M993_Ball";
		initSpeed = 910;
	};
	
	class rhsusf_100Rnd_762x51 : rhsusf_50Rnd_762x51
	{
		displayName = "100Rnd Belt Mag (7.62x51 M80)";
		//model = "\rhsusf\addons\rhsusf_weapons\magazines\rhs_m240_mag";
		//picture = "\rhsusf\addons\rhsusf_weapons\icons\m_m245_ca.paa";
		
		descriptionShort = "Caliber: 7.62x51 NATO<br />Rounds: 100<br />Used in: M240";
		count=100;
		initSpeed = 838;
		mass = 48;
		//magazineGroup[] = {"rhs_762x51_box"};
	};
	class rhsusf_100Rnd_762x51_m80a1epr : rhsusf_50Rnd_762x51_m80a1epr
	{
		displayName = "100Rnd Belt Mag (7.62x51 M80A1EPR)";
		count=100;
		mass = 48;
	};
	class rhsusf_100Rnd_762x51_m993 : rhsusf_50Rnd_762x51_m993
	{
		displayName = "100Rnd Belt Mag (7.62x51 M993)";
		count=100;
		mass = 48;
	};
	
	class rhsusf_20Rnd_762x51_m118_special_Mag: CA_Magazine
	{
		Author_Macro
		scope = 2;
		displayName = "7.62mm M118 20Rnd Mag";
		picture = "\A3\weapons_f\data\UI\M_20Rnd_762x51_CA.paa";
		model = "\rhsusf\addons\rhsusf_weapons\magazines\rhs_m14_mag";
		count = 20;
		ammo = "rhs_ammo_762x51_M118_Special_Ball";
		mass = 12;
		initSpeed = 805;
		descriptionShort = "Caliber: 7.62x51 mm NATO<br />Rounds: 20<br />Used in: Mk14 EBR";
		magazineGroup[] = {"rhs_762x51_20rnd"};
	};
	class rhsusf_20Rnd_762x51_m993_Mag: rhsusf_20Rnd_762x51_m118_special_Mag
	{
		Author_Macro
		scope = 2;
		displayName = "7.62mm M993 20Rnd Mag";
		ammo = "rhs_ammo_762x51_M993_Ball";
		mass = 12;
		initSpeed = 910;		
		descriptionShort = "Caliber: 7.62x51 mm NATO<br />Rounds: 20<br />Used in: Mk14 EBR";
	};

	// Pistol Mags
	class rhsusf_mag_7x45acp_MHP: CA_Magazine
	{
		scope = 2;
		type = 16;
		displayName = "$STR_RHSUSF_7RND_45ACP_DISPLAY_NAME";
		//displayName = "7Rnds. 45ACP";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\mag_45acp_ca.paa";
		ammo = "rhs_ammo_45ACP_MHP";
		count = 7;
		initSpeed = 280;
		descriptionShort = "$STR_RHSUSF_7RND_45ACP_DESCRIPTION_SHORT";
	};
	
	///! Rocket Mags
	
	class rhs_m136_mag : CA_LauncherMagazine
	{
		allowedSlots[] = {701,901};
		scope = 1;
		Author_Macro
		displayName = "M136 HEAT";
		descriptionShort = "";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\m_m136_ca.paa";
		model = "";
		ammo = rhs_ammo_M136_rocket;
		type = 6 * 		256;
		initSpeed = 290;
		mass = 7;
	};

	class rhs_dummy_mag : FakeMagazine
	{
		allowedSlots[] = {701,901};
		scope = 1;
		Author_Macro
		displayName = "M136 HEAT";
		descriptionShort = "";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\m_m136_ca.paa";
		model = "";
		ammo = rhs_ammo_M136_rocket;
		type = 6 * 		256;
		initSpeed = 290;
		mass = 7;
	};

	class rhs_launcher_dummy_mag : rhs_dummy_mag
	{
		scope = 1;
		count = 0;
	};

	class rhs_m136_hedp_mag : rhs_m136_mag
	{
		Author_Macro
		displayName = "M136 HEDP";
		ammo = rhs_ammo_M136_hedp_rocket;
	};
	class rhs_m136_hp_mag : rhs_m136_mag
	{
		Author_Macro
		displayName = "M136 HP";
		ammo = rhs_ammo_M136_hp_rocket;
	};
	
	class rhs_fim92_mag : CA_LauncherMagazine
	{
		allowedSlots[] = {701,901};
		scope = 2;
		mass = 120;
		displayName = "FIM-92F";
		ammo=rhsammo_fim92_missile;
		type = 6 * WeaponSlotItem;
		picture="\rhsusf\addons\rhsusf_weapons\icons\m_stinger_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\FIM92\Stinger_proxy";
		initSpeed = 40;
		maxLeadSpeed=320;  //  let AA soldiers attack chopers in cruise speed
	};

	class rhs_fgm148_magazine_AT: CA_LauncherMagazine
	{
		scope = 2;
		displayName = "Javelin AT";
		descriptionShort = "FGM-148 Javelin AT Missile tube";
		picture = "\rhsusf\addons\rhsusf_weapons\FGM148\data\UI\m_fgm148_ca.paa";
		
		model = "\rhsusf\addons\rhsusf_weapons\FGM148\fgm148_tube_ammo";
		//modelSpecial = "\rhsusf\addons\rhsusf_weapons\FGM148\fgm148_clu_loaded";
		
		count = 1;
		ammo = "rhs_ammo_M_fgm148_AT";
		initSpeed = 10;
		maxLeadSpeed = 350;
		mass = 150;
	};
	
	///! GL Mags
/* 		class rhsusf_1Rnd_40mm_HE : CA_Magazine
	{
		scope = 2;
		Author_Macro
		displayName = $STR_rhsusf_1Rnd_40mm_HE;
		picture = "";
		ammo = "rhsusf_B_300winmag";
		count = 1;
		initSpeed = 880;
		tracersEvery = 0;
		lastRoundsTracer = 4;
		descriptionShort = $STR_rhsusf_5Rnd_300winmag_xm2010;
	}; */

	///! Explosives

	/*
	class SatchelCharge_Remote_Mag: CA_Magazine
	{
		scope = 2;
		displayName = "$STR_A3_cfgMagazines_PipeBomb0";
		picture = "\A3\Weapons_f\data\UI\gear_satchel_CA.paa";
		model = "\A3\Weapons_F\Explosives\satchel_i";
		descriptionShort = "$STR_A3_cfgMagazines_PipeBomb1";
		class Library
		{
			libTextDesc = "$STR_A3_cfgMagazines_PipeBomb_Library0";
		};
		descriptionUse = "$STR_A3_use_charge";
		type = "2*		256";
		allowedSlots[] = {901};
		value = 5;
		ammo = "SatchelCharge_Remote_Ammo";
		mass = 80;
		count = 1;
		initSpeed = 0;
		maxLeadSpeed = 0;
		nameSoundWeapon = "satchelcharge";
		nameSound = "satchelcharge";
		weaponPoolAvailable = 1;
		useAction = 1;
		useActionTitle = "$STR_ACTION_PUTBOMB";
		sound[] = {"A3\sounds_f\dummysound",0.00031622776,1,10};
	};
	class DemoCharge_Remote_Mag: SatchelCharge_Remote_Mag
	{
		scope = 2;
		mass = 20;
		displayName = "$STR_A3_cfgMagazines_DemoCharge0";
		picture = "\A3\Weapons_F\Data\UI\gear_c4_charge_small_CA.paa";
		model = "\A3\Weapons_F\Explosives\c4_charge_small";
		ammo = "DemoCharge_Remote_Ammo";
		descriptionShort = "$STR_A3_cfgMagazines_DemoCharge1";
		class Library
		{
			libTextDesc = "$STR_A3_cfgMagazines_DemoCharge_Library0";
		};
		allowedSlots[] = {901,701};
	};
	*/

	class rhsusf_m112_mag: CA_Magazine
	{
		scope = 2;
		displayName = "M112 charge";
		picture = "\A3\Weapons_F\Data\UI\gear_c4_charge_small_CA.paa";
		model = "\rhsusf\addons\rhsusf_weapons\explosives\M112x1";
		descriptionShort = "$STR_A3_cfgMagazines_PipeBomb1";
		class Library
		{
			libTextDesc = "$STR_A3_cfgMagazines_PipeBomb_Library0";
		};
		descriptionUse = "$STR_A3_use_charge";
		type = "2*		256";
		allowedSlots[] = {901};
		value = 5;
		ammo = "rhsusf_m112_ammo";
		mass = 20;
		count = 1;
		initSpeed = 0;
		maxLeadSpeed = 0;
		nameSoundWeapon = "satchelcharge";
		nameSound = "satchelcharge";
		weaponPoolAvailable = 1;
		useAction = 1;
		useActionTitle = "$STR_ACTION_PUTBOMB";
		sound[] = {"A3\sounds_f\dummysound",0.00031622776,1,10};
	};

	class rhsusf_m112x4_mag: rhsusf_m112_mag
	{
		scope = 2;
		mass = 80;
		displayName = "M112 x4 charge pack";
		picture = "\A3\Weapons_F\Data\UI\gear_c4_charge_small_CA.paa";
		model = "\rhsusf\addons\rhsusf_weapons\explosives\M112x4";
		ammo = "rhsusf_m112x4_ammo";
		descriptionShort = "$STR_A3_cfgMagazines_DemoCharge1";
		class Library
		{
			libTextDesc = "$STR_A3_cfgMagazines_DemoCharge_Library0";
		};
		allowedSlots[] = {901,701};
	};
	
	///! Mines
	
	class ATMine_Range_Mag;
	
	
	class rhs_mine_M19_mag: ATMine_Range_Mag
	{
		mass = 120; //12.7kg
		ammo = "rhsusf_mine_m19_ammo";
		
		picture = "\A3\Weapons_F\Data\UI\gear_mine_AT_CA.paa";
		
		Author_Macro
		displayName = "M19"; //FIX LATER
		model = "\A3\Weapons_F\explosives\mine_ap_i";
		descriptionShort = "M19 Anti-tank Mine"; //FIX LATER
		
		class Library
		{
			libTextDesc = "$STR_A3_cfgMagazines_ClassicMineRangeMagazine_Library0";
		};
		
		descriptionUse = "$STR_A3_use_mine";
	};


	class HandGrenade;
	
	class rhs_mag_m67: HandGrenade
	{
		Author_Macro
		ammo = "rhs_ammo_m67";
		displayName = $STR_RHSUSF_1Rnd_M67;
		//displayNameShort = "Frag Grenade";
		descriptionShort = $STR_RHSUSF_1Rnd_M67_DESCRIPTION_SHORT;
		mass = 4;
		model = "\rhsusf\addons\rhsusf_weapons\grenades\m67\m67_frag";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\g_m67_ca.paa";
	};	
	class rhs_mag_m69: HandGrenade
	{
		Author_Macro
		ammo = "rhs_ammo_m69";
		displayName = $STR_RHSUSF_1Rnd_M69;
		//displayNameShort = "Practice Grenade";
		descriptionShort = $STR_RHSUSF_1Rnd_M69_DESCRIPTION_SHORT;
		mass = 4;
		model = "\rhsusf\addons\rhsusf_weapons\grenades\m69\m69_practice";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\g_m69_ca.paa";
	};	
	
	class rhs_mag_mk84: HandGrenade
	{
		Author_Macro
		ammo = "rhs_ammo_m84";
		displayName = $STR_RHSUSF_1Rnd_MK84;
		//displayNameShort = "Stun Grenade";
		descriptionShort = $STR_RHSUSF_1Rnd_MK84_DESCRIPTION_SHORT;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\g_m84_flash_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\grenades\m84\m84_flash";
		mass = 4;
	};

	class rhs_mag_an_m8hc: HandGrenade
	{
		Author_Macro
		ammo = "rhs_ammo_an_m8hc";
		displayName = $STR_RHSUSF_1Rnd_M8HC;
		//displayNameShort = "White Smoke";
		descriptionShort = $STR_RHSUSF_1Rnd_M8HC_DESCRIPTION_SHORT;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\g_an_m8hc_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\grenades\an-m8hc\an-m8hc";		
		mass = 4;
	};

	class rhs_mag_an_m14_th3: HandGrenade
	{
		Author_Macro
		ammo = "rhs_ammo_an_m14_th3";
		displayName = $STR_RHSUSF_1Rnd_ANM14_TH3;
		//displayNameShort = "Incendenary Grenade";
		descriptionShort = $STR_RHSUSF_1Rnd_ANM14_TH3_DESCRIPTION_SHORT;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\g_an_m14_th3_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\grenades\an-m14_th3\an-m14_th3";
		mass = 4;
	};	

	class rhs_mag_m7a3_cs: HandGrenade
	{
		Author_Macro
		ammo = "rhs_ammo_m7a3_cs";
		displayName = $STR_RHSUSF_1Rnd_M7A3_CS;
		//displayNameShort = "CS Gas Grnd.";
		descriptionShort = $STR_RHSUSF_1Rnd_M7A3_CS_DESCRIPTION_SHORT;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\g_m7a3_cs_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\grenades\m7a3_cs\m7a3_cs";
		mass = 4;
	};	

	class rhs_mag_mk3a2: HandGrenade
	{
		Author_Macro
		ammo = "rhs_ammo_mk3a2";
		displayName = $STR_RHSUSF_1Rnd_MK3A2;
		//displayNameShort = "Concussions Grnd.";
		descriptionShort = $STR_RHSUSF_1Rnd_MK3A2_DESCRIPTION_SHORT;
		picture = "\rhsusf\addons\rhsusf_weapons\icons\g_mk3a2_ca.paa";
		model = "\rhsusf\addons\rhsusf_weapons\grenades\mk3a2\mk3a2";
		mass = 4;
	};	

	class rhs_mag_m18_smoke_base: HandGrenade
	{
		Author_Macro		
		//placeholder
		model = "\rhsusf\addons\rhsusf_weapons\grenades\m18\m18_smoke";
		mass = 4;
		scope = 0;
		descriptionShort = $STR_RHSUSF_1Rnd_M18_COLORGRENADE_DESCRIPTION_SHORT;
		hiddenSelections[] = {"Grenade"};
	};

	class rhs_mag_m18_green: rhs_mag_m18_smoke_base
	{
		Author_Macro
		ammo = "rhs_ammo_m18_green";
		displayName = $STR_RHSUSF_1Rnd_M18_GREEN;
		//displayNameShort = "Green Smoke";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\g_m18_green_ca.paa";
		scope = 2;
		hiddenSelectionsTextures[] = {"\rhsusf\addons\rhsusf_weapons\grenades\m18\data\m18_green_ca.cpp"};
	};

	class rhs_mag_m18_purple: rhs_mag_m18_smoke_base
	{
		Author_Macro
		ammo = "rhs_ammo_m18_purple";
		displayName = $STR_RHSUSF_1Rnd_M18_PURPLE;
		//displayNameShort = "Purple Smoke";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\g_m18_purple_ca.paa";
		scope = 2;
		hiddenSelectionsTextures[] = {"\rhsusf\addons\rhsusf_weapons\grenades\m18\data\m18_purple_ca.cpp"};
	};

	class rhs_mag_m18_red: rhs_mag_m18_smoke_base
	{
		Author_Macro
		ammo = "rhs_ammo_m18_red";
		displayName = $STR_RHSUSF_1Rnd_M18_RED;
		//displayNameShort = "Red Smoke";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\g_m18_red_ca.paa";
		scope = 2;
		hiddenSelectionsTextures[] = {"\rhsusf\addons\rhsusf_weapons\grenades\m18\data\m18_red_ca.cpp"};
	};

	class rhs_mag_m18_yellow: rhs_mag_m18_smoke_base
	{
		Author_Macro
		ammo = "rhs_ammo_m18_yellow";
		displayName = $STR_RHSUSF_1Rnd_M18_YELLOW;
		//displayNameShort = "Yellow Smoke";
		picture = "\rhsusf\addons\rhsusf_weapons\icons\g_m18_yellow_ca.paa";
		scope = 2;
		hiddenSelectionsTextures[] = {"\rhsusf\addons\rhsusf_weapons\grenades\m18\data\m18_yellow_ca.cpp"};
	};
};