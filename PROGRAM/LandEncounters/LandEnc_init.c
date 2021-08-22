int InitLandEncTemplates()
{
	int n;

	n = 0;

	LandEncTemplate[n].id = "port";
	LandEncTemplate[n].quantity = 0;

	LandEncTemplate[n].enc1.type = "ENC_BANDITS";
	LandEncTemplate[n].enc1.chance = 0.2;
	LandEncTemplate[n].enc1.StartTime = 22;
	LandEncTemplate[n].enc1.EndTime = 6;

	LandEncTemplate[n].enc2.type = "ENC_POORMAN";
	LandEncTemplate[n].enc2.chance = 0.1;
	LandEncTemplate[n].enc2.StartTime = 0;
	LandEncTemplate[n].enc2.EndTime = 24;

	LandEncTemplate[n].enc3.type = "ENC_LATEWALKER";
	LandEncTemplate[n].enc3.chance = 0.2;
	LandEncTemplate[n].enc3.StartTime = 22;
	LandEncTemplate[n].enc3.EndTime = 6;

	LandEncTemplate[n].enc4.type = "ENC_PATROL";
	LandEncTemplate[n].enc4.chance = 0.1;
	LandEncTemplate[n].enc4.StartTime = 22;
	LandEncTemplate[n].enc4.EndTime = 6;

//Keemo -->
	LandEncTemplate[n].enc5.type = "ENC_DEADMAN";
	LandEncTemplate[n].enc5.chance = 0;
	LandEncTemplate[n].enc5.StartTime = 22;
	LandEncTemplate[n].enc5.EndTime = 6;
//Keemo <--

	n = n + 1;

//---------------------------------------------------------------------------------------------

	LandEncTemplate[n].id = "town";
	LandEncTemplate[n].quantity = 0;


	LandEncTemplate[n].enc1.type = "ENC_BANDITS";
	LandEncTemplate[n].enc1.chance = 0.2;
	LandEncTemplate[n].enc1.StartTime = 22;
	LandEncTemplate[n].enc1.EndTime = 6;

	LandEncTemplate[n].enc2.type = "ENC_POORMAN";
	LandEncTemplate[n].enc2.chance = 0.1;
	LandEncTemplate[n].enc2.StartTime = 0;
	LandEncTemplate[n].enc2.EndTime = 24;

	LandEncTemplate[n].enc3.type = "ENC_LATEWALKER";
	LandEncTemplate[n].enc3.chance = 0.2;
	LandEncTemplate[n].enc3.StartTime = 22;
	LandEncTemplate[n].enc3.EndTime = 6;

	LandEncTemplate[n].enc4.type = "ENC_PATROL";
	LandEncTemplate[n].enc4.chance = 0.1;
	LandEncTemplate[n].enc4.StartTime = 22;
	LandEncTemplate[n].enc4.EndTime = 6;

//Keemo -->
	LandEncTemplate[n].enc5.type = "ENC_DEADMAN";
	LandEncTemplate[n].enc5.chance = 0;
	LandEncTemplate[n].enc5.StartTime = 22;
	LandEncTemplate[n].enc5.EndTime = 6;
//Keemo <--
	
	LandEncTemplate[n].enc6.type = "ENC_RAPERS";
	LandEncTemplate[n].enc6.StartTime = 22;
	LandEncTemplate[n].enc6.EndTime = 6;
	LandEncTemplate[n].enc6.chance = 0.2;

	LandEncTemplate[n].enc7.type = "ENC_DEFECTOR";
	LandEncTemplate[n].enc7.StartTime = 22;
	LandEncTemplate[n].enc7.EndTime = 6;
	LandEncTemplate[n].enc7.chance = 0.1;

	n = n + 1;

//---------------------------------------------------------------------------------------------

/*	LandEncTemplate[n].id = "town_exit";

	LandEncTemplate[n].enc1.type = "ENC_RAIDERS";
	LandEncTemplate[n].enc1.chance = 0.1;
	LandEncTemplate[n].enc1.StartTime = 0;
	LandEncTemplate[n].enc1.EndTime = 24;

	LandEncTemplate[n].enc2.type = "ENC_CONVICTS";
	LandEncTemplate[n].enc2.chance = 0.1;
	LandEncTemplate[n].enc2.StartTime = 0;
	LandEncTemplate[n].enc2.EndTime = 24;

	LandEncTemplate[n].enc3.type = "ENC_LATEWALKER";
	LandEncTemplate[n].enc3.chance = 0.2;
	LandEncTemplate[n].enc3.StartTime = 22;
	LandEncTemplate[n].enc3.EndTime = 6;

	LandEncTemplate[n].enc4.type = "ENC_PATROL";
	LandEncTemplate[n].enc4.chance = 0.1;
	LandEncTemplate[n].enc4.StartTime = 22;
	LandEncTemplate[n].enc4.EndTime = 6;

//Keemo -->
	LandEncTemplate[n].enc5.type = "ENC_DEADMAN";
	LandEncTemplate[n].enc5.chance = 0;
	LandEncTemplate[n].enc5.StartTime = 22;
	LandEncTemplate[n].enc5.EndTime = 6;
//Keemo <--

	LandEncTemplate[n].enc6.type = "ENC_RAPERS";
	LandEncTemplate[n].enc6.chance = 0.2;
	LandEncTemplate[n].enc6.StartTime = 22;
	LandEncTemplate[n].enc6.EndTime = 6;

	n = n + 1;*/

//---------------------------------------------------------------------------------------------
// Viper - Rapers MOD Begin
	LandEncTemplate[n].id = "jungle";
	LandEncTemplate[n].quantity = 3;


	LandEncTemplate[n].enc1.type = "ENC_RAIDERS";
	LandEncTemplate[n].enc1.chance = 0.3; // Levis: original was 0.2 - PB: was 0.4 in Beta 3.4
	LandEncTemplate[n].enc1.StartTime = 0;
	LandEncTemplate[n].enc1.EndTime = 24;

	LandEncTemplate[n].enc2.type = "ENC_RAPERS";
	LandEncTemplate[n].enc2.StartTime = 16;
	LandEncTemplate[n].enc2.EndTime = 6;
	LandEncTemplate[n].enc2.chance = 0.1;

	LandEncTemplate[n].enc3.type = "ENC_DEFECTOR";
	LandEncTemplate[n].enc3.StartTime = 16;
	LandEncTemplate[n].enc3.EndTime = 6;
	LandEncTemplate[n].enc3.chance = 0.08;
	
	n = n + 1;
// Viper - Rapers MOD End

//---------------------------------------------------------------------------------------------

	LandEncTemplate[n].id = "seashore";
	LandEncTemplate[n].quantity = 0;

	LandEncTemplate[n].enc1.type = "ENC_SMUGGLERS";
	LandEncTemplate[n].enc1.chance = 0.2;
	LandEncTemplate[n].enc1.StartTime = 0;
	LandEncTemplate[n].enc1.EndTime = 24;

	LandEncTemplate[n].enc2.type = "ENC_CONVICTS";
	LandEncTemplate[n].enc2.chance = 0.2;
	LandEncTemplate[n].enc2.StartTime = 0;
	LandEncTemplate[n].enc2.EndTime = 24;

	LandEncTemplate[n].enc3.type = "ENC_SURVIVOR";
	LandEncTemplate[n].enc3.chance = 0.2;
	LandEncTemplate[n].enc3.StartTime = 22;
	LandEncTemplate[n].enc3.EndTime = 6;

	n = n + 1;


//---------------------------------------------------------------------------------------------

	LandEncTemplate[n].id = "tavern";
	LandEncTemplate[n].quantity = 1;

//NK -->
	LandEncTemplate[n].enc1.type = "ENC_OFFICER";
	LandEncTemplate[n].enc1.chance = 0.5;
// NK <-- 
	LandEncTemplate[n].enc1.StartTime = 0;
	LandEncTemplate[n].enc1.EndTime = 24;

	n++; // NK
	return n;

}


int InitLandEncounters()
{
	int n;

	n = 0;

	LandEncounters[n].id = "ENC_RAIDERS";

	LandEncounters[n].StartingQuest1 = "LandEnc_RaidersLogin";
	LandEncounters[n].StartingQuest1.QuestType = "Location";
	LandEncounters[n].StartingQuest2 = "LandEnc_RaidersStart";
	LandEncounters[n].StartingQuest2.QuestType  = "Locator";

	LAi_group_Register("ENC_RAIDERS_GROUP");

	/*LandEncounters[n].char1.modelQuantity = 14;
	LandEncounters[n].char1.model1 = "sailor1";
	LandEncounters[n].char1.model1.ani = "man";
	LandEncounters[n].char1.model2 = "sailor2";
	LandEncounters[n].char1.model2.ani = "man";
	LandEncounters[n].char1.model3 = "sailor3";
	LandEncounters[n].char1.model3.ani = "man";
	LandEncounters[n].char1.model4 = "sailor4";
	LandEncounters[n].char1.model4.ani = "man";
	LandEncounters[n].char1.model5 = "chelovek";
	LandEncounters[n].char1.model5.ani = "man";
	LandEncounters[n].char1.model6 = "chelovek1";
	LandEncounters[n].char1.model6.ani = "man";
	LandEncounters[n].char1.model7 = "fisherman";
	LandEncounters[n].char1.model7.ani = "man";
	LandEncounters[n].char1.model8 = "fisherman1";
	LandEncounters[n].char1.model8.ani = "man";
	LandEncounters[n].char1.model9 = "man5_1";
	LandEncounters[n].char1.model9.ani = "man";
	LandEncounters[n].char1.model9 = "bocman4";
	LandEncounters[n].char1.model9.ani = "man";
	LandEncounters[n].char1.model10 = "sailor5";
	LandEncounters[n].char1.model10.ani = "man";
	LandEncounters[n].char1.model11 = "Mask";
	LandEncounters[n].char1.model11.ani = "man";
	LandEncounters[n].char1.model12 = "Mask_2";
	LandEncounters[n].char1.model12.ani = "man";
	LandEncounters[n].char1.model13 = "Mask_3";
	LandEncounters[n].char1.model13.ani = "man";
	LandEncounters[n].char1.model14 = "Mask_4";
	LandEncounters[n].char1.model14.ani = "man";*/
	LandEncounters[n].char1.modelQuantity = 1;
	LandEncounters[n].char1.model1 = "Raiders";
	LandEncounters[n].char1.model1.sex = "Man";
	LandEncounters[n].char1.cont = true;
	LandEncounters[n].char1.pistol = 0.5; // NK
	LandEncounters[n].char1.sword = true;
	LandEncounters[n].char1.type = "warrior";
	LandEncounters[n].char1.Dialog = "Enc_Raiders_dialog.c";


	/*LandEncounters[n].char2.modelQuantity = 14;
	LandEncounters[n].char2.model1 = "sailor1";
	LandEncounters[n].char2.model1.ani = "man";
	LandEncounters[n].char2.model2 = "sailor2";
	LandEncounters[n].char2.model2.ani = "man";
	LandEncounters[n].char2.model3 = "sailor3";
	LandEncounters[n].char2.model3.ani = "man";
	LandEncounters[n].char2.model4 = "sailor4";
	LandEncounters[n].char2.model4.ani = "man";
	LandEncounters[n].char2.model5 = "chelovek";
	LandEncounters[n].char2.model5.ani = "man";
	LandEncounters[n].char2.model6 = "chelovek1";
	LandEncounters[n].char2.model6.ani = "man";
	LandEncounters[n].char2.model7 = "fisherman";
	LandEncounters[n].char2.model7.ani = "man";
	LandEncounters[n].char2.model8 = "fisherman1";
	LandEncounters[n].char2.model8.ani = "man";
	LandEncounters[n].char2.model9 = "man5_1";
	LandEncounters[n].char2.model9.ani = "man";
	LandEncounters[n].char2.model9 = "bocman4";
	LandEncounters[n].char2.model9.ani = "man";
	LandEncounters[n].char2.model10 = "sailor5";
	LandEncounters[n].char2.model10.ani = "man";
	LandEncounters[n].char2.model11 = "Mask";
	LandEncounters[n].char2.model11.ani = "man";
	LandEncounters[n].char2.model12 = "Mask_2";
	LandEncounters[n].char2.model12.ani = "man";
	LandEncounters[n].char2.model13 = "Mask_3";
	LandEncounters[n].char2.model13.ani = "man";
	LandEncounters[n].char2.model14 = "Mask_4";
	LandEncounters[n].char2.model14.ani = "man";*/
	LandEncounters[n].char2.modelQuantity = 1;
	LandEncounters[n].char2.model1 = "Raiders";
	LandEncounters[n].char2.model1.sex = "Man";
	LandEncounters[n].char2.cont = true;
	LandEncounters[n].char2.pistol = 0.5; // NK
	LandEncounters[n].char2.sword = true;
	LandEncounters[n].char2.type = "warrior";
	LandEncounters[n].char2.Dialog = "Enc_Raiders_dialog.c";


	/*LandEncounters[n].char3.modelQuantity = 14;
	LandEncounters[n].char3.model1 = "sailor1";
	LandEncounters[n].char3.model1.ani = "man";
	LandEncounters[n].char3.model2 = "sailor2";
	LandEncounters[n].char3.model2.ani = "man";
	LandEncounters[n].char3.model3 = "sailor3";
	LandEncounters[n].char3.model3.ani = "man";
	LandEncounters[n].char3.model4 = "sailor4";
	LandEncounters[n].char3.model4.ani = "man";
	LandEncounters[n].char3.model5 = "chelovek";
	LandEncounters[n].char3.model5.ani = "man";
	LandEncounters[n].char3.model6 = "chelovek1";
	LandEncounters[n].char3.model6.ani = "man";
	LandEncounters[n].char3.model7 = "fisherman";
	LandEncounters[n].char3.model7.ani = "man";
	LandEncounters[n].char3.model8 = "fisherman1";
	LandEncounters[n].char3.model8.ani = "man";
	LandEncounters[n].char3.model9 = "man5_1";
	LandEncounters[n].char3.model9.ani = "man";
	LandEncounters[n].char3.model9 = "bocman4";
	LandEncounters[n].char3.model9.ani = "man";
	LandEncounters[n].char3.model10 = "sailor5";
	LandEncounters[n].char3.model10.ani = "man";
	LandEncounters[n].char3.model11 = "Mask";
	LandEncounters[n].char3.model11.ani = "man";
	LandEncounters[n].char3.model12 = "Mask_2";
	LandEncounters[n].char3.model12.ani = "man";
	LandEncounters[n].char3.model13 = "Mask_3";
	LandEncounters[n].char3.model13.ani = "man";
	LandEncounters[n].char3.model14 = "Mask_4";
	LandEncounters[n].char3.model14.ani = "man";*/
	LandEncounters[n].char3.modelQuantity = 1;
	LandEncounters[n].char3.model1 = "Raiders";
	LandEncounters[n].char3.model1.sex = "Man";
	LandEncounters[n].char3.cont = true;
	LandEncounters[n].char3.pistol = 0.5; // NK
	LandEncounters[n].char3.sword = true;
	LandEncounters[n].char3.type = "warrior";
	LandEncounters[n].char3.Dialog = "Enc_Raiders_dialog.c";


	/*LandEncounters[n].char4.modelQuantity = 14;
	LandEncounters[n].char4.model1 = "sailor1";
	LandEncounters[n].char4.model1.ani = "man";
	LandEncounters[n].char4.model2 = "sailor2";
	LandEncounters[n].char4.model2.ani = "man";
	LandEncounters[n].char4.model3 = "sailor3";
	LandEncounters[n].char4.model3.ani = "man";
	LandEncounters[n].char4.model4 = "sailor4";
	LandEncounters[n].char4.model4.ani = "man";
	LandEncounters[n].char4.model5 = "chelovek";
	LandEncounters[n].char4.model5.ani = "man";
	LandEncounters[n].char4.model6 = "chelovek1";
	LandEncounters[n].char4.model6.ani = "man";
	LandEncounters[n].char4.model7 = "fisherman";
	LandEncounters[n].char4.model7.ani = "man";
	LandEncounters[n].char4.model8 = "fisherman1";
	LandEncounters[n].char4.model8.ani = "man";
	LandEncounters[n].char4.model9 = "man5_1";
	LandEncounters[n].char4.model9.ani = "man";
	LandEncounters[n].char4.model9 = "bocman4";
	LandEncounters[n].char4.model9.ani = "man";
	LandEncounters[n].char4.model10 = "sailor5";
	LandEncounters[n].char4.model10.ani = "man";
	LandEncounters[n].char4.model11 = "Mask";
	LandEncounters[n].char4.model11.ani = "man";
	LandEncounters[n].char4.model12 = "Mask_2";
	LandEncounters[n].char4.model12.ani = "man";
	LandEncounters[n].char4.model13 = "Mask_3";
	LandEncounters[n].char4.model13.ani = "man";
	LandEncounters[n].char4.model14 = "Mask_4";
	LandEncounters[n].char4.model14.ani = "man";*/
	LandEncounters[n].char4.modelQuantity = 1;
	LandEncounters[n].char4.model1 = "Raiders";
	LandEncounters[n].char4.model1.sex = "Man";
	LandEncounters[n].char4.cont = false;
	LandEncounters[n].char4.pistol = 0.5; // NK
	LandEncounters[n].char4.sword = true;
	LandEncounters[n].char4.type = "warrior";
	LandEncounters[n].char4.Dialog = "Enc_Raiders_dialog.c";

	n = n + 1;

//----------------------------------------------------------------------------------------------

// Viper - Rapers MOD Begin
	LandEncounters[n].id = "ENC_RAPERS";
	LandEncounters[n].StartingQuest1 = "LandEnc_RapersLogin";
	LandEncounters[n].StartingQuest1.QuestType = "Location";
	LAi_group_Register("ENC_RAPERS_GROUP");
// Viper - Rapers MOD End

	/*LandEncounters[n].char1.modelQuantity = 9;
	LandEncounters[n].char1.model1 = "towngirl1";
	LandEncounters[n].char1.model1.ani = "woman";
	LandEncounters[n].char1.model2 = "towngirl1_1";
	LandEncounters[n].char1.model2.ani = "woman";
	LandEncounters[n].char1.model3 = "towngirl2";
	LandEncounters[n].char1.model3.ani = "woman";
	LandEncounters[n].char1.model4 = "towngirl2_1";
	LandEncounters[n].char1.model4.ani = "woman";
	LandEncounters[n].char1.model5 = "towngirl3";
	LandEncounters[n].char1.model5.ani = "woman";
	LandEncounters[n].char1.model6 = "towngirl3_1";
	LandEncounters[n].char1.model6.ani = "woman";
	LandEncounters[n].char1.model7 = "towngirl4";
	LandEncounters[n].char1.model7.ani = "woman";
	LandEncounters[n].char1.model8 = "towngirl5";
	LandEncounters[n].char1.model8.ani = "woman";
	LandEncounters[n].char1.model9 = "towngirl6";
	LandEncounters[n].char1.model9.ani = "woman";
	LandEncounters[n].char1.model9 = "towngirl7";
	LandEncounters[n].char1.model9.ani = "woman";*/
	LandEncounters[n].char1.modelQuantity = 1;
	LandEncounters[n].char1.model1 = "Jungle_Women";
	LandEncounters[n].char1.model1.sex = "woman";
	LandEncounters[n].char1.friend = true;
	LandEncounters[n].char1.cont = true;
	LandEncounters[n].char1.pistol = false;
	LandEncounters[n].char1.sword = false;
	LandEncounters[n].char1.iscombat = -1; // could be false. NK 05-07-27
	LandEncounters[n].char1.type = "actor";
	LandEncounters[n].char1.Dialog = "Enc_RapersGirl_dialog.c";


	/*LandEncounters[n].char2.modelQuantity = 10;
	LandEncounters[n].char2.model1 = "sailor1";
	LandEncounters[n].char2.model1.ani = "man";
	LandEncounters[n].char2.model2 = "sailor2";
	LandEncounters[n].char2.model2.ani = "man";
	LandEncounters[n].char2.model3 = "sailor3";
	LandEncounters[n].char2.model3.ani = "man";
	LandEncounters[n].char2.model4 = "sailor4";
	LandEncounters[n].char2.model4.ani = "man";
	LandEncounters[n].char2.model5 = "chelovek";
	LandEncounters[n].char2.model5.ani = "man";
	LandEncounters[n].char2.model6 = "chelovek1";
	LandEncounters[n].char2.model6.ani = "man";
	LandEncounters[n].char2.model7 = "fisherman";
	LandEncounters[n].char2.model7.ani = "man";
	LandEncounters[n].char2.model8 = "fisherman1";
	LandEncounters[n].char2.model8.ani = "man";
	LandEncounters[n].char2.model9 = "man5_1";
	LandEncounters[n].char2.model9.ani = "man";
	LandEncounters[n].char2.model9 = "bocman4";
	LandEncounters[n].char2.model9.ani = "man";
	LandEncounters[n].char2.model10 = "sailor5";
	LandEncounters[n].char2.model10.ani = "man";*/
	LandEncounters[n].char2.modelQuantity = 1;
	LandEncounters[n].char2.model1 = "Raiders";
	LandEncounters[n].char2.model1.sex = "Man";
	LandEncounters[n].char2.cont = true;
	LandEncounters[n].char2.pistol = 0.5; // NK
	LandEncounters[n].char2.sword = true;
	LandEncounters[n].char2.type = "actor";
	LandEncounters[n].char2.Dialog = "Enc_Rapers_dialog.c";


	/*LandEncounters[n].char3.modelQuantity = 10;
	LandEncounters[n].char3.model1 = "sailor1";
	LandEncounters[n].char3.model1.ani = "man";
	LandEncounters[n].char3.model2 = "sailor2";
	LandEncounters[n].char3.model2.ani = "man";
	LandEncounters[n].char3.model3 = "sailor3";
	LandEncounters[n].char3.model3.ani = "man";
	LandEncounters[n].char3.model4 = "sailor4";
	LandEncounters[n].char3.model4.ani = "man";
	LandEncounters[n].char3.model5 = "chelovek";
	LandEncounters[n].char3.model5.ani = "man";
	LandEncounters[n].char3.model6 = "chelovek1";
	LandEncounters[n].char3.model6.ani = "man";
	LandEncounters[n].char3.model7 = "fisherman";
	LandEncounters[n].char3.model7.ani = "man";
	LandEncounters[n].char3.model8 = "fisherman1";
	LandEncounters[n].char3.model8.ani = "man";
	LandEncounters[n].char3.model9 = "man5_1";
	LandEncounters[n].char3.model9.ani = "man";
	LandEncounters[n].char3.model9 = "bocman4";
	LandEncounters[n].char3.model9.ani = "man";
	LandEncounters[n].char3.model10 = "sailor5";
	LandEncounters[n].char3.model10.ani = "man";*/
	LandEncounters[n].char3.modelQuantity = 1;
	LandEncounters[n].char3.model1 = "Raiders";
	LandEncounters[n].char3.model1.sex = "Man";
	LandEncounters[n].char3.cont = true;
	LandEncounters[n].char3.pistol = 0.5; // NK
	LandEncounters[n].char3.sword = true;
	LandEncounters[n].char3.type = "actor";
	LandEncounters[n].char3.Dialog = "Enc_Rapers_dialog.c";


	/*LandEncounters[n].char4.modelQuantity = 10;
	LandEncounters[n].char4.model1 = "sailor1";
	LandEncounters[n].char4.model1.ani = "man";
	LandEncounters[n].char4.model2 = "sailor2";
	LandEncounters[n].char4.model2.ani = "man";
	LandEncounters[n].char4.model3 = "sailor3";
	LandEncounters[n].char4.model3.ani = "man";
	LandEncounters[n].char4.model4 = "sailor4";
	LandEncounters[n].char4.model4.ani = "man";
	LandEncounters[n].char4.model5 = "chelovek";
	LandEncounters[n].char4.model5.ani = "man";
	LandEncounters[n].char4.model6 = "chelovek1";
	LandEncounters[n].char4.model6.ani = "man";
	LandEncounters[n].char4.model7 = "fisherman";
	LandEncounters[n].char4.model7.ani = "man";
	LandEncounters[n].char4.model8 = "fisherman1";
	LandEncounters[n].char4.model8.ani = "man";
	LandEncounters[n].char4.model9 = "man5_1";
	LandEncounters[n].char4.model9.ani = "man";
	LandEncounters[n].char4.model9 = "bocman4";
	LandEncounters[n].char4.model9.ani = "man";
	LandEncounters[n].char4.model10 = "sailor5";
	LandEncounters[n].char4.model10.ani = "man";*/
	LandEncounters[n].char4.modelQuantity = 1;
	LandEncounters[n].char4.model1 = "Raiders";
	LandEncounters[n].char4.model1.sex = "Man";
	LandEncounters[n].char4.cont = false;
	LandEncounters[n].char4.pistol = 0.5; // NK
	LandEncounters[n].char4.sword = true;
	LandEncounters[n].char4.type = "actor";
	LandEncounters[n].char4.Dialog = "Enc_Rapers_dialog.c";


	n = n + 1;

//----------------------------------------------------------------------------------------------

	LandEncounters[n].id = "ENC_DEFECTOR";
	LandEncounters[n].StartingQuest1 = "LandEnc_DefectorLogin";
	LandEncounters[n].StartingQuest1.QuestType = "Location";
	LAi_group_Register("ENC_DEFECTORS_GROUP");


	LandEncounters[n].char1.modelQuantity = 1;
	LandEncounters[n].char1.model1 = "Jungle_Defector";
//	LandEncounters[n].char1.model1.sex = "woman";
	LandEncounters[n].char1.friend = true;
	LandEncounters[n].char1.cont = true;
	LandEncounters[n].char1.pistol = false;
	LandEncounters[n].char1.sword = false;
	LandEncounters[n].char1.iscombat = -1; // could be false. NK 05-07-27
	LandEncounters[n].char1.type = "actor";
	LandEncounters[n].char1.Dialog = "Enc_Defector_dialog.c";



	LandEncounters[n].char2.modelQuantity = 1;
	LandEncounters[n].char2.model1 = "Raiders";
	LandEncounters[n].char2.model1.sex = "Man";
	LandEncounters[n].char2.cont = true;
	LandEncounters[n].char2.pistol = 0.5; // NK
	LandEncounters[n].char2.sword = true;
	LandEncounters[n].char2.type = "actor";
	LandEncounters[n].char2.Dialog = "Enc_DefectorPursuer_dialog.c";



	LandEncounters[n].char3.modelQuantity = 1;
	LandEncounters[n].char3.model1 = "Raiders";
	LandEncounters[n].char3.model1.sex = "Man";
	LandEncounters[n].char3.cont = true;
	LandEncounters[n].char3.pistol = 0.5; // NK
	LandEncounters[n].char3.sword = true;
	LandEncounters[n].char3.type = "actor";
	LandEncounters[n].char3.Dialog = "Enc_DefectorPursuer_dialog.c";



	LandEncounters[n].char4.modelQuantity = 1;
	LandEncounters[n].char4.model1 = "Raiders";
	LandEncounters[n].char4.model1.sex = "Man";
	LandEncounters[n].char4.cont = false;
	LandEncounters[n].char4.pistol = 0.5; // NK
	LandEncounters[n].char4.sword = true;
	LandEncounters[n].char4.type = "actor";
	LandEncounters[n].char4.Dialog = "Enc_DefectorPursuer_dialog.c";

	n = n + 1;

//----------------------------------------------------------------------------------------------

/*	LandEncounters[n].id = "ENC_CONVICTS";

	LandEncounters[n].char1.modelQuantity = 5;
	LandEncounters[n].char1.model1 = "rabwhite1";
	LandEncounters[n].char1.model1.ani = "man";
	LandEncounters[n].char1.model2 = "rabwhite";
	LandEncounters[n].char1.model2.ani = "man";
	LandEncounters[n].char1.model3 = "rabblack";
	LandEncounters[n].char1.model3.ani = "man";
	LandEncounters[n].char1.model4 = "fatman";
	LandEncounters[n].char1.model4.ani = "man";
	LandEncounters[n].char1.model5 = "rabblack_1";
	LandEncounters[n].char1.model5.ani = "man";
	LandEncounters[n].char1.cont = true;


	LandEncounters[n].char2.modelQuantity = 5;
	LandEncounters[n].char2.model1 = "rabwhite1";
	LandEncounters[n].char2.model1.ani = "man";
	LandEncounters[n].char2.model2 = "rabwhite";
	LandEncounters[n].char2.model2.ani = "man";
	LandEncounters[n].char2.model3 = "rabblack";
	LandEncounters[n].char2.model3.ani = "man";
	LandEncounters[n].char2.model4 = "fatman";
	LandEncounters[n].char2.model4.ani = "man";
	LandEncounters[n].char2.model5 = "rabblack_1";
	LandEncounters[n].char2.model5.ani = "man";
	LandEncounters[n].char2.cont = true;


	LandEncounters[n].char3.modelQuantity = 5;
	LandEncounters[n].char3.model1 = "rabwhite1";
	LandEncounters[n].char3.model1.ani = "man";
	LandEncounters[n].char3.model2 = "rabwhite";
	LandEncounters[n].char3.model2.ani = "man";
	LandEncounters[n].char3.model3 = "rabblack";
	LandEncounters[n].char3.model3.ani = "man";
	LandEncounters[n].char3.model4 = "fatman";
	LandEncounters[n].char3.model4.ani = "man";
	LandEncounters[n].char3.model5 = "rabblack_1";
	LandEncounters[n].char3.model5.ani = "man";
	LandEncounters[n].char3.cont = true;


	LandEncounters[n].char4.modelQuantity = 5;
	LandEncounters[n].char4.model1 = "rabwhite1";
	LandEncounters[n].char4.model1.ani = "man";
	LandEncounters[n].char4.model2 = "rabwhite";
	LandEncounters[n].char4.model2.ani = "man";
	LandEncounters[n].char4.model3 = "rabblack";
	LandEncounters[n].char4.model3.ani = "man";
	LandEncounters[n].char4.model4 = "fatman";
	LandEncounters[n].char4.model4.ani = "man";
	LandEncounters[n].char4.model5 = "rabblack_1";
	LandEncounters[n].char4.model5.ani = "man";
	LandEncounters[n].char4.cont = false;

	n = n + 1;

	//----------------------------------------------------------------------------------------------

	LandEncounters[n].id = "ENC_POORMAN";

	LandEncounters[n].char1.modelQuantity = 5;
	LandEncounters[n].char1.model1 = "rabwhite1";
	LandEncounters[n].char1.model1.ani = "man";
	LandEncounters[n].char1.model2 = "rabwhite";
	LandEncounters[n].char1.model2.ani = "man";
	LandEncounters[n].char1.model3 = "rabblack";
	LandEncounters[n].char1.model3.ani = "man";
	LandEncounters[n].char1.model4 = "brodyaga";
	LandEncounters[n].char1.model4.ani = "man";
	LandEncounters[n].char1.model5 = "rabblack_1";
	LandEncounters[n].char1.model5.ani = "man";
	LandEncounters[n].char1.cont = false;

	n = n + 1;

	//----------------------------------------------------------------------------------------------

	LandEncounters[n].id = "ENC_BANDITS";

	LandEncounters[n].StartingQuest = "LandEnc_BanditsStart";
	LandEncounters[n].QuestType = "locator";

	LandEncounters[n].char1.modelQuantity = 10;
	LandEncounters[n].char1.model1 = "sailor1";
	LandEncounters[n].char1.model1.ani = "man";
	LandEncounters[n].char1.model2 = "sailor2";
	LandEncounters[n].char1.model2.ani = "man";
	LandEncounters[n].char1.model3 = "sailor3";
	LandEncounters[n].char1.model3.ani = "man";
	LandEncounters[n].char1.model4 = "sailor4";
	LandEncounters[n].char1.model4.ani = "man";
	LandEncounters[n].char1.model5 = "chelovek";
	LandEncounters[n].char1.model5.ani = "man";
	LandEncounters[n].char1.model6 = "chelovek1";
	LandEncounters[n].char1.model6.ani = "man";
	LandEncounters[n].char1.model7 = "fisherman";
	LandEncounters[n].char1.model7.ani = "man";
	LandEncounters[n].char1.model8 = "fisherman1";
	LandEncounters[n].char1.model8.ani = "man";
	LandEncounters[n].char1.model9 = "man5_1";
	LandEncounters[n].char1.model9.ani = "man";
	LandEncounters[n].char1.model9 = "bocman4";
	LandEncounters[n].char1.model9.ani = "man";
	LandEncounters[n].char1.model10 = "sailor5";
	LandEncounters[n].char1.model10.ani = "man";
	LandEncounters[n].char1.cont = true;


	LandEncounters[n].char2.modelQuantity = 10;
	LandEncounters[n].char2.model1 = "sailor1";
	LandEncounters[n].char2.model1.ani = "man";
	LandEncounters[n].char2.model2 = "sailor2";
	LandEncounters[n].char2.model2.ani = "man";
	LandEncounters[n].char2.model3 = "sailor3";
	LandEncounters[n].char2.model3.ani = "man";
	LandEncounters[n].char2.model4 = "sailor4";
	LandEncounters[n].char2.model4.ani = "man";
	LandEncounters[n].char2.model5 = "chelovek";
	LandEncounters[n].char2.model5.ani = "man";
	LandEncounters[n].char2.model6 = "chelovek1";
	LandEncounters[n].char2.model6.ani = "man";
	LandEncounters[n].char2.model7 = "fisherman";
	LandEncounters[n].char2.model7.ani = "man";
	LandEncounters[n].char2.model8 = "fisherman1";
	LandEncounters[n].char2.model8.ani = "man";
	LandEncounters[n].char2.model9 = "man5_1";
	LandEncounters[n].char2.model9.ani = "man";
	LandEncounters[n].char2.model9 = "bocman4";
	LandEncounters[n].char2.model9.ani = "man";
	LandEncounters[n].char2.model10 = "sailor5";
	LandEncounters[n].char2.model10.ani = "man";
	LandEncounters[n].char2.cont = true;

	LandEncounters[n].char3.modelQuantity = 10;
	LandEncounters[n].char3.model1 = "sailor1";
	LandEncounters[n].char3.model1.ani = "man";
	LandEncounters[n].char3.model2 = "sailor2";
	LandEncounters[n].char3.model2.ani = "man";
	LandEncounters[n].char3.model3 = "sailor3";
	LandEncounters[n].char3.model3.ani = "man";
	LandEncounters[n].char3.model4 = "sailor4";
	LandEncounters[n].char3.model4.ani = "man";
	LandEncounters[n].char3.model5 = "chelovek";
	LandEncounters[n].char3.model5.ani = "man";
	LandEncounters[n].char3.model6 = "chelovek1";
	LandEncounters[n].char3.model6.ani = "man";
	LandEncounters[n].char3.model7 = "fisherman";
	LandEncounters[n].char3.model7.ani = "man";
	LandEncounters[n].char3.model8 = "fisherman1";
	LandEncounters[n].char3.model8.ani = "man";
	LandEncounters[n].char3.model9 = "man5_1";
	LandEncounters[n].char3.model9.ani = "man";
	LandEncounters[n].char3.model9 = "bocman4";
	LandEncounters[n].char3.model9.ani = "man";
	LandEncounters[n].char3.model10 = "sailor5";
	LandEncounters[n].char3.model10.ani = "man";
	LandEncounters[n].char3.cont = true;

	LandEncounters[n].char4.modelQuantity = 10;
	LandEncounters[n].char4.model1 = "sailor1";
	LandEncounters[n].char4.model1.ani = "man";
	LandEncounters[n].char4.model2 = "sailor2";
	LandEncounters[n].char4.model2.ani = "man";
	LandEncounters[n].char4.model3 = "sailor3";
	LandEncounters[n].char4.model3.ani = "man";
	LandEncounters[n].char4.model4 = "sailor4";
	LandEncounters[n].char4.model4.ani = "man";
	LandEncounters[n].char4.model5 = "chelovek";
	LandEncounters[n].char4.model5.ani = "man";
	LandEncounters[n].char4.model6 = "chelovek1";
	LandEncounters[n].char4.model6.ani = "man";
	LandEncounters[n].char4.model7 = "fisherman";
	LandEncounters[n].char4.model7.ani = "man";
	LandEncounters[n].char4.model8 = "fisherman1";
	LandEncounters[n].char4.model8.ani = "man";
	LandEncounters[n].char4.model9 = "man5_1";
	LandEncounters[n].char4.model9.ani = "man";
	LandEncounters[n].char4.model9 = "bocman4";
	LandEncounters[n].char4.model9.ani = "man";
	LandEncounters[n].char4.model10 = "sailor5";
	LandEncounters[n].char4.model10.ani = "man";
	LandEncounters[n].char4.cont = false;

	n = n + 1;

	//----------------------------------------------------------------------------------------------
*/
	LandEncounters[n].id = "ENC_OFFICER";

	LandEncounters[n].char1.modelQuantity = 8;
	LandEncounters[n].char1.model1 = OFFIC_TYPE_BOATSWAIN;
	LandEncounters[n].char1.model2 = OFFIC_TYPE_CANNONEER;
	LandEncounters[n].char1.model3 = OFFIC_TYPE_QMASTER;
	LandEncounters[n].char1.model4 = OFFIC_TYPE_NAVIGATOR;
	LandEncounters[n].char1.model5 = OFFIC_TYPE_FIRSTMATE;
// MAXIMUS officers -->
	LandEncounters[n].char1.model6 = OFFIC_TYPE_CARPENTER;
	LandEncounters[n].char1.model7 = OFFIC_TYPE_DOCTOR;
	LandEncounters[n].char1.model8 = OFFIC_TYPE_ABORDAGE;
// MAXIMUS officers <--
	LandEncounters[n].char1.friend = true;
	LandEncounters[n].char1.isOfficer = true;
	LandEncounters[n].char1.cont = false;
	LandEncounters[n].char1.pistol = true;
	LandEncounters[n].char1.sword = true;
	LandEncounters[n].char1.type = "sit";
	LandEncounters[n].char1.Dialog = "Enc_Officer_dialog.c";


	n = n + 1; // NK uncommented

	return n;

}