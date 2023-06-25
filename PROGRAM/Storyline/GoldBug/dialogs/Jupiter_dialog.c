
void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\PADI\PADI001";
			

			if(CheckAttribute(Pchar,"quest.Jupiter_sits") && Pchar.quest.Jupiter_sits == "yes")
			{	
				PlaySound("VOICE\ENGLISH\guncrew_3.wav");
				Dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "exit_sit";
			}
			else
			{
				if(CheckAttribute(Pchar,"quest.Jupiter_sits") && Pchar.quest.Jupiter_sits == "bartender")
				{
					PlaySound("VOICE\ENGLISH\gm_crew7.wav");
					Dialog.text = DLG_TEXT[87];
					link.l1 = DLG_TEXT[86];
					link.l1.go = "exit_stay";
				}
			}
			else
			{
				PlaySound("VOICE\ENGLISH\guncrew_3.wav");
				Dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				if(CheckAttribute(Pchar,"quest.plank_gate") && Pchar.quest.plank_gate == "ready")
				{
					link.l1.go = "exit_stay";
				}
				else link.l1.go = "exit_officer";
			}

			Diag.TempNode = "first time";
		break;

		case "hunting_birds":
			PlaySound("VOICE\ENGLISH\Jupiter_1.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("hunting_birds3");
		break;

		case "home_via_wreck":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("through_the_wreck");
		break;

		case "stop_goldbug_nothing":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit_stay";
			AddDialogExitQuest("end_stop_goldbug_nothing");
		break;

		case "stop_goldbug_seen":
			PlaySound("VOICE\ENGLISH\guncrew_3.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("end_stop_goldbug_seen");
		break;

		case "what_is_it":
			PlaySound("VOICE\ENGLISH\guncrew_3.wav");
			Dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit_officer";
		break;

		case "chimney_smoke":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "chimney_smoke1";
		break;

		case "chimney_smoke1":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("chimney_smoke_done");
		break;

		case "take_guns":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("take_guns_done");
		break;

		case "who_are_you":
			PlaySound("VOICE\ENGLISH\pir_capP.wav");
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit_stay";
			AddDialogExitQuest("who_are_you_done");
		break;
	
		case "goldbug":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit_stay";
			AddDialogExitQuest("Jupiter_goldbug_done");
		break;

		case "supper":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit_stay";
			AddDialogExitQuest("supper_done");
		break;

		case "sleep":
			PlaySound("PEOPLE\yawn.wav");
			Dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "sleep1";
		break;
		
		case "sleep1":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			Dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit_stay";
			AddDialogExitQuest("sleep_done");
		break;

		case "wake_up_Jup":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "wake_up_Jup1";
		break;

		case "wake_up_Jup1":
			PlaySound("VOICE\ENGLISH\pir_capMMM.wav");
			Dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "exit_stay";
			AddDialogExitQuest("wake_up_Jup_done");
		break;

		case "Jup_mission2":
			PlaySound("VOICE\ENGLISH\guncrew_3.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Jup_mission2_A";
		break;

		case "Jup_mission2_A":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			Dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Jup_mission2_B";
		break;

		case "Jup_mission2_B":
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			Dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit_stay";
			AddDialogExitQuest("Jup_mission2_done");
		break;

		case "Jup_takes_sack_in_kitchen":
			PlaySound("VOICE\ENGLISH\gm_crew21A.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("second_placing_woodsack5");
		break;

		case "Legrand_to_fort":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Legrand_to_fort1";
		break;

		case "Legrand_to_fort1":
			Dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "Legrand_to_fort2";
		break;

		case "Legrand_to_fort2":
			PlaySound("VOICE\ENGLISH\guncrew_3.wav");
			Dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "Legrand_to_fort3";
		break;

		case "Legrand_to_fort3":
			PlaySound("VOICE\ENGLISH\guncrew_3.wav");
			Dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "Legrand_to_fort4";
		break;

		case "Legrand_to_fort4":
			PlaySound("VOICE\ENGLISH\pir_capMMM.wav");
			Dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("Legrand_to_fort_done");
		break;

		case "Charleston_too_early":
			PlaySound("VOICE\ENGLISH\Jupiter_1.wav");
			Dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("Charleston_too_early_done");
		break;

		case "Charleston_too_late":
			PlaySound("VOICE\ENGLISH\Jupiter_1.wav");
			Dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("Charleston_too_late_done");
		break;

		case "Poe_house_where":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look_r1");

			PlaySound("VOICE\ENGLISH\guncrew_3.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "Poe_house_where1";
		break;

		case "Poe_house_where1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look_r1");
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			Dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "Poe_house_where2";
		break;

		case "Poe_house_where2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "look_r1");
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			Dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "Exit_officer";
			AddDialogExitQuest("Poe_house_where_done");
		break;

		case "Jupiter_degree":
			ChangeCharacterAddressGroup(NPchar, "Poe_bedroom", "goto", "stay3");
			PlaySound("VOICE\ENGLISH\pir_capMMM.wav");
			Dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "exit_stay";
			AddDialogExitQuest("Poe_leaves_bedroom");
		break;

		case "Bessop_plantation_info":
			PlaySound("VOICE\ENGLISH\guncrew_3.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "Bessop_plantation_info1";
		break;

		case "Bessop_plantation_info1":
			PlaySound("VOICE\ENGLISH\pir_capMMM.wav");
			Dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "Bessop_plantation_info2";
		break;

		case "Bessop_plantation_info2":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			Dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "Exit_officer";
			AddDialogExitQuest("Bessop_plantation_info_done");
		break;


		case "how_to_enter_plantation":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "lookR2");
			PlaySound("VOICE\ENGLISH\pir_capT.wav");
			Dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "how_to_enter_plantation1";
		break;

		case "how_to_enter_plantation1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "lookR2");
			PlaySound("VOICE\ENGLISH\guncrew_3.wav");
			Dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "how_to_enter_plantation2";
		break;

		case "how_to_enter_plantation2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "lookR2");
			PlaySound("VOICE\ENGLISH\blaze_hah.wav");
			Dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "how_to_enter_plantation3";
		break;

		case "how_to_enter_plantation3":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "lookR2");
			PlaySound("VOICE\ENGLISH\Jupiter_2.wav");
			Dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("how_to_enter_plantation_done");
		break;

		case "Jup_outside_nitre":
			PlaySound("VOICE\ENGLISH\guncrew_3.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit_officer";
		break;

		case "we_do_the_job":
			PlaySound("VOICE\ENGLISH\blaze_hah.wav");
			Dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("gp_standard_3");
		break;

		case "we_do_the_job_yes":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			Dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("gp_standard_5");
		break;

		case "ingredients":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "ingredients1";
		break;
	//---------------------------------------------------------------
		case "last_ingredients":
			PlaySound("VOICE\ENGLISH\blaze_heard_something.wav");
			Dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "ingredients1";
		break;
	//---------------------------------------------------------------
		case "ingredients1":
			PlaySound("VOICE\ENGLISH\Jupiter_2.wav");

			if(makefloat(Pchar.quest.lost_charcoal) > 0 && makefloat(Pchar.quest.lost_nitre) > 0 && makefloat(Pchar.quest.lost_sulfur) > 0)
			{
				Dialog.text = DLG_TEXT[81];

			}
			else
			{
				if(makefloat(Pchar.quest.lost_charcoal) > 0 && makefloat(Pchar.quest.lost_nitre) > 0)
				{
					Dialog.text = DLG_TEXT[78];
				}
			}
			else
			{
				if(makefloat(Pchar.quest.lost_charcoal) > 0 && makefloat(Pchar.quest.lost_sulfur) > 0)
				{
					Dialog.text = DLG_TEXT[79];
				}
			}
			else
			{
				if(makefloat(Pchar.quest.lost_nitre) > 0 && makefloat(Pchar.quest.lost_sulfur) > 0)
				{
					Dialog.text = DLG_TEXT[80];
				}
			}
			else
			{
				if(makefloat(Pchar.quest.lost_charcoal) > 0)
				{
					Dialog.text = DLG_TEXT[75];
				}
			}
			else
			{
				if(makefloat(Pchar.quest.lost_nitre) > 0)
				{
					Dialog.text = DLG_TEXT[76];
				}
			}
			else
			{
				if(makefloat(Pchar.quest.lost_sulfur) > 0)
				{
					Dialog.text = DLG_TEXT[77];
				}
			}

			link.l1 = DLG_TEXT[82];
		
			if(CheckAttribute(Pchar,"quest.need_barrels") && Pchar.quest.need_barrels == "yes")
			{
				link.l1.go = "need_barrels";
			}
			else
			{
				link.l1.go = "exit_stay";
				AddDialogExitQuest("Jup_with_ingredients_done");
			}
		break;
		
		case "need_barrels":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");

			RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "pistolbarrel_gpS" );
			RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(Pchar, "bladebarrel_gpS" );

			GiveItem2Character(Pchar, "bladebarrel_gp0");
			EquipCharacterByItem(Pchar, "bladebarrel_gp0");
			GiveItem2Character(Pchar, "pistolbarrel_gp0");
			EquipCharacterByItem(Pchar, "pistolbarrel_gp0");

			Dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "exit_stay";
			AddDialogExitQuest("Jup_with_ingredients_done");
		break;
	//--------------------------------------------------------------------------
	//plantation
		case "climb":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[88];
			link.l1 = DLG_TEXT[89];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("climb_done");
		break;

		case "wait_climb_until_dark":
			PlaySound("VOICE\ENGLISH\guncrew_3.wav");
			Dialog.text = DLG_TEXT[98];
			link.l1 = DLG_TEXT[99];
			link.l1.go = "Exit_officer";
			AddDialogExitQuest("wait_climb_until_dark_done");
		break;

		case "slave_barracks":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "mountain1");
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "goto", "mountain1_jup");

			PlaySound("VOICE\ENGLISH\jupiter_mm.wav");
			Dialog.text = DLG_TEXT[90];
			link.l1 = DLG_TEXT[91];
			link.l1.go = "slave_barracks1";
		break;

		case "slave_barracks1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "tower2");
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "goto", "tower2");

			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			Dialog.text = DLG_TEXT[92];
			link.l1 = DLG_TEXT[93];
			link.l1.go = "slave_barracks2";
		break;
		
		case "slave_barracks2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "mountain1");
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "goto", "mountain1_jup");

			PlaySound("VOICE\ENGLISH\jupiter_aha.wav");
			Dialog.text = DLG_TEXT[94];
			link.l1 = DLG_TEXT[95];
			link.l1.go = "slave_barracks3";
		break;

		case "slave_barracks3":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "tower1");
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "goto", "tower1");

			PlaySound("VOICE\ENGLISH\jupiter_mm.wav");
			Dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "Exit_officer";
			AddDialogExitQuest("slave_barracks_done");
		break;

		case "patrol_yes":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "mountain2");
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "goto", "mountain2_jup");
	
			LAi_SetPoorType(Pchar);
			LAi_SetPoorType(NPchar);

			PlaySound("VOICE\ENGLISH\jupiter_aha.wav");
			Dialog.text = DLG_TEXT[100];
			link.l1 = DLG_TEXT[247];
			link.l1.go = "patrol_yes1";
		break;

		case "patrol_yes1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "mountain2");
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "goto", "mountain2_jup");
	
			LAi_SetPoorType(Pchar);
			LAi_SetPoorType(NPchar);

			PlaySound("VOICE\ENGLISH\jupiter_mm.wav");
			Dialog.text = DLG_TEXT[248];
			link.l1 = DLG_TEXT[101];
			link.l1.go = "Exit_officer";
			AddDialogExitQuest("patrol_yes_done");
		break;

		case "wait_for_fireworks":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "wait_for_fireworks1";
		break;

		case "wait_for_fireworks1":
			PlaySound("VOICE\ENGLISH\jupiter_aha.wav");
			Dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];
			link.l1.go = "wait_for_fireworks2";
		break;

		case "wait_for_fireworks2":
			PlaySound("AMBIENT\man_laughter.wav");
			Dialog.text = DLG_TEXT[249];
			link.l1 = DLG_TEXT[250];
			link.l1.go = "Exit_stay";
			AddDialogExitQuest("wait_for_fireworks_done");
		break;

		case "kungfu":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto4");
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[106];
			link.l1 = DLG_TEXT[107];
			link.l1.go = "Exit_stay";
			AddDialogExitQuest("jup_kungfu_done");
		break;

		case "stop_gate1":
			PlaySound("VOICE\ENGLISH\guncrew_4.wav");
			Dialog.text = DLG_TEXT[108];
			link.l1 = DLG_TEXT[109];
			link.l1.go = "stop_gate2";
		break;

		case "stop_gate2":
			PlaySound("VOICE\ENGLISH\jupiter_2.wav");
			Dialog.text = DLG_TEXT[110];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "Exit_stay";
			AddDialogExitQuest("stop_gate3");
		break;

		case "stop_gate12":
			PlaySound("VOICE\ENGLISH\jupiter_1.wav");
			Dialog.text = DLG_TEXT[112];
			link.l1 = DLG_TEXT[113];
			link.l1.go = "Exit_stay";
			AddDialogExitQuest("stop_gate13");
		break;

		case "unlock_the_gate":
			PlaySound("VOICE\ENGLISH\guncrew_4.wav");
			Dialog.text = DLG_TEXT[114];
			link.l1 = DLG_TEXT[115];
			link.l1.go = "Exit_stay";
			AddDialogExitQuest("jup_unlock_the_gate2");
		break;

		case "I_do_the_talking":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("maroon1"));

			PlaySound("VOICE\ENGLISH\jupiter_2.wav");
			Dialog.text = DLG_TEXT[116];
			link.l1 = DLG_TEXT[117];
			link.l1.go = "I_do_the_talking1";
		break;

		case "I_do_the_talking1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("maroon1"));

			PlaySound("VOICE\ENGLISH\jupiter_mm.wav");
			Dialog.text = DLG_TEXT[118];
			link.l1 = DLG_TEXT[119];
			link.l1.go = "Exit_officer";
			AddDialogExitQuest("maroon_prep2");
		break;

		case "return1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("maroon1"));

			PlaySound("VOICE\ENGLISH\jupiter_aha.wav");
			Dialog.text = DLG_TEXT[120];
			link.l1 = DLG_TEXT[121];
			link.l1.go = "Exit_officer";
			AddDialogExitQuest("maroon_stop2");
		break;

		case "shopping_1A":
			PlaySound("VOICE\ENGLISH\guncrew_3.wav");
			Dialog.text = DLG_TEXT[122];
			link.l1 = DLG_TEXT[123];
			link.l1.go = "shopping_1B";
		break;

		case "shopping_1B":
			PlaySound("VOICE\ENGLISH\jupiter_aha.wav");
			Dialog.text = DLG_TEXT[124];
			link.l1 = DLG_TEXT[125];
			link.l1.go = "shopping_1C";
		break;

		case "shopping_1C":
			PlaySound("VOICE\ENGLISH\jupiter_mm.wav");
			Dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[127];
			link.l1.go = "Exit_officer";
			AddDialogExitQuest("shopping_1D");
		break;

		case "shopping_1E":
			PlaySound("VOICE\ENGLISH\jupiter_1.wav");
			Dialog.text = DLG_TEXT[128];
			link.l1 = DLG_TEXT[129];
			link.l1.go = "Exit_officer";
			AddDialogExitQuest("shopping_1F");
		break;

		case "shopping_1J":
			PlaySound("VOICE\ENGLISH\jupiter_aha.wav");
			Dialog.text = DLG_TEXT[130];
			link.l1 = DLG_TEXT[131];
			link.l1.go = "Exit_officer";
			AddDialogExitQuest("shopping_1K");
		break;

		case "Jup_has_spyglass":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			Dialog.text = DLG_TEXT[132];
			link.l1 = DLG_TEXT[133];
			link.l1.go = "Jup_has_spyglass1";
		break;

		case "Jup_has_spyglass1":
			PlaySound("VOICE\ENGLISH\jupiter_aha.wav");
			Dialog.text = DLG_TEXT[134];
			link.l1 = DLG_TEXT[135];
			link.l1.go = "Exit_officer";
			AddDialogExitQuest("meeting_at_Poes6");
		break;

		case "Jup_has_idea":
			PlaySound("VOICE\ENGLISH\jupiter_mm.wav");
			Dialog.text = DLG_TEXT[136];
			link.l1 = DLG_TEXT[137];
			link.l1.go = "Jup_has_idea1";
		break;

		case "Jup_has_idea1":
			PlaySound("VOICE\ENGLISH\jupiter_aha.wav");
			Dialog.text = DLG_TEXT[138];
			link.l1 = DLG_TEXT[139];
			link.l1.go = "Exit_officer";
			AddDialogExitQuest("Jup_has_idea_done");
		break;

		case "Jup_need_plank":
			PlaySound("VOICE\ENGLISH\jupiter_aha.wav");
			Dialog.text = DLG_TEXT[140];
			link.l1 = DLG_TEXT[141];
			link.l1.go = "Jup_need_plank1";
		break;

		case "Jup_need_plank1":
			PlaySound("VOICE\ENGLISH\jupiter_1.wav");
			Dialog.text = DLG_TEXT[142];
			link.l1 = DLG_TEXT[143];
			link.l1.go = "Jup_need_plank2";
		break;

		case "Jup_need_plank2":
			PlaySound("VOICE\ENGLISH\blaze_hah.wav");
			Dialog.text = DLG_TEXT[144];
			link.l1 = DLG_TEXT[145];
			link.l1.go = "Jup_need_plank3";
		break;
	
		case "Jup_need_plank3":
			PlaySound("VOICE\ENGLISH\blaze_lets_go.wav");
			Dialog.text = DLG_TEXT[146];
			link.l1 = DLG_TEXT[147];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("Jup_need_plank_done");
		break;

		case "raft_talk":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[148];
			link.l1 = DLG_TEXT[149];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("raft_talk_done");
		break;

		case "raft_better_view":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "4A_look");
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "goto", "4_look");

			PlaySound("VOICE\ENGLISH\jupiter_aha.wav");
			Dialog.text = DLG_TEXT[150];
			link.l1 = DLG_TEXT[151];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("raft_better_view_done");
		break;

		case "Jup_takes_boom":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "ships_other", "ships_1");

			PlaySound("VOICE\ENGLISH\jupiter_aha.wav");
			Dialog.text = DLG_TEXT[152];
			link.l1 = DLG_TEXT[153];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("Jup_takes_boom_done");
		break;
//----------------------------------------------------------------------------------
		case "Jup_climbs_tree1A":
			PlaySound("OBJECTS\duel\man_hit1.wav");
			Dialog.text = DLG_TEXT[154];
			link.l1 = DLG_TEXT[155];
			link.l1.go = "Jup_climbs_tree1B";
		break;

		case "Jup_climbs_tree1B":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			Dialog.text = DLG_TEXT[156];
			link.l1 = DLG_TEXT[157];
			link.l1.go = "Exit";
			AddDialogExitQuest("Jup_climbs_tree1B_done");
		break;
//----------------------------------------------------------------------------------
		case "Jup_climbs_tree2A":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			Dialog.text = DLG_TEXT[158];
			link.l1 = DLG_TEXT[159];
			link.l1.go = "Exit";
			AddDialogExitQuest("Jup_climbs_tree_animation10");
		break;
//----------------------------------------------------------------------------------
		case "Jup_climbs_tree3A":
			PlaySound("OBJECTS\VOICES\DEAD\male\Death_NPC_01.wav");
			Dialog.text = DLG_TEXT[160];
			link.l1 = DLG_TEXT[161];
			link.l1.go = "Jup_climbs_tree3B";
		break;

		case "Jup_climbs_tree3B":
			PlaySound("OBJECTS\VOICES\DEAD\male\Death_NPC_08.wav");
			Dialog.text = DLG_TEXT[162];
			link.l1 = DLG_TEXT[163];
			link.l1.go = "Jup_climbs_tree3C";
		break;

		case "Jup_climbs_tree3C":
			PlaySound("VOICE\ENGLISH\blaze_5.wav");
			Dialog.text = DLG_TEXT[164];
			link.l1 = DLG_TEXT[165];
			link.l1.go = "exit";
			AddDialogExitQuest("Jup_climbs_tree_animation14");
		break;
//----------------------------------------------------------------------------------
		case "Jup_climbs_tree4C":
			PlaySound("OBJECTS\VOICES\DEAD\male\Death_NPC_07.wav");
			Dialog.text = DLG_TEXT[166];
			link.l1 = DLG_TEXT[167];
			link.l1.go = "Jup_climbs_tree4D";
		break;

		case "Jup_climbs_tree4D":
			PlaySound("OBJECTS\VOICES\DEAD\male\Death_NPC_02.wav");
			Dialog.text = DLG_TEXT[168];
			link.l1 = DLG_TEXT[169];
			link.l1.go = "exit";
			AddDialogExitQuest("Jup_climbs_tree5A");
		break;
//----------------------------------------------------------------------------------
		case "Jup_climbs_tree6B":
			PlaySound("OBJECTS\VOICES\DEAD\male\Death_NPC_08.wav");
			Dialog.text = DLG_TEXT[170];
			link.l1 = DLG_TEXT[171];
			link.l1.go = "Jup_climbs_tree6C";
		break;

		case "Jup_climbs_tree6C":
			PlaySound("VOICE\ENGLISH\blaze_scream.wav");
			Dialog.text = DLG_TEXT[172];
			link.l1 = DLG_TEXT[173];
			link.l1.go = "Jup_climbs_tree6D";
		break;

		case "Jup_climbs_tree6D":
			PlaySound("OBJECTS\VOICES\DEAD\male\Death_NPC_02.wav");
			Dialog.text = DLG_TEXT[174];
			link.l1 = DLG_TEXT[175];
			link.l1.go = "Jup_climbs_tree6E";
		break;

		case "Jup_climbs_tree6E":
			PlaySound("OBJECTS\VOICES\DEAD\male\Death_NPC_01.wav");
			Dialog.text = DLG_TEXT[176];
			link.l1 = DLG_TEXT[177];
			link.l1.go = "exit";
			AddDialogExitQuest("Jup_climbs_tree7");
		break;

		case "sneak_around_maroons":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[182];
			link.l1 = DLG_TEXT[183];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("sneak_around_maroons_done");
		break;

		case "Jup_whispers_plan":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("maroon1"));

			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[178];
			link.l1 = DLG_TEXT[179];
			link.l1.go = "exit";
			AddDialogExitQuest("hidden_maroons7");
		break;

		case "Jup_hurry_to_the_raft":
			PlaySound("VOICE\ENGLISH\Jupiter_1.wav");
			Dialog.text = DLG_TEXT[180];
			link.l1 = DLG_TEXT[181];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("Jup_stops_maroons11");
		break;

		case "raft_to_passage":
			PlaySound("VOICE\ENGLISH\Jupiter_2.wav");
			Dialog.text = DLG_TEXT[184];
			link.l1 = DLG_TEXT[185];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("raft_to_passage3");
		break;

		case "kungfu_hint":
			PlaySound("VOICE\ENGLISH\blaze_dont_leave_me.wav");
			Dialog.text = DLG_TEXT[186];
			link.l1 = DLG_TEXT[187];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("kungfu_hint_done");
		break;

		case "maroons_at_passage":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "goto", "m7");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "m7");

			PlaySound("VOICE\ENGLISH\blaze_dont_leave_me.wav");
			Dialog.text = DLG_TEXT[188];
			link.l1 = DLG_TEXT[189];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("raft_to_passage5");
		break;

		case "passage_empty":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			Dialog.text = DLG_TEXT[190];
			link.l1 = DLG_TEXT[191];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("passage_empty_done");
		break;

		case "I_get_the_boat":
			ChangeCharacterAddressGroup(NPchar, "poe_bedroom", "goto", "stay1");	

			PlaySound("VOICE\ENGLISH\Jupiter_aha.wav");
			Dialog.text = DLG_TEXT[192];
			link.l1 = DLG_TEXT[193];
			link.l1.go = "I_get_the_boat1";
		break;

		case "I_get_the_boat1":
			PlaySound("VOICE\ENGLISH\Jupiter_mm.wav");
			Dialog.text = DLG_TEXT[194];
			link.l1 = DLG_TEXT[195];
			link.l1.go = "exit_stay";
			AddDialogExitQuest("last_Poe_bedroom11A");
		break;

		case "I_got_the_boat":
			PlaySound("VOICE\ENGLISH\Jupiter_1.wav");
			Dialog.text = DLG_TEXT[196];
			link.l1 = DLG_TEXT[197];
			link.l1.go = "I_got_no_shots";
		break;

		case "I_got_no_shots":
			PlaySound("VOICE\ENGLISH\Jupiter_2.wav");
			Dialog.text = DLG_TEXT[198];
			link.l1 = DLG_TEXT[199];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("I_got_nails");
		break;

		case "Jup_climbs_tree_again":
			PlaySound("VOICE\ENGLISH\Jupiter_mm.wav");
			Dialog.text = DLG_TEXT[200];
			link.l1 = DLG_TEXT[201];
			link.l1.go = "Jup_climbs_tree_again1";
		break;

		case "Jup_climbs_tree_again1":
			PlaySound("PEOPLE\clothes1.wav");
			SetModel(Pchar, "William Legrand", pchar.model.animation, pchar.sex, stf(pchar.model.height), true);
			TakeItemFromCharacter(Pchar, "fort_rope" );

			Dialog.text = DLG_TEXT[202];
			link.l1 = DLG_TEXT[203];
			link.l1.go = "Jup_climbs_tree_again2";
		break;

		case "Jup_climbs_tree_again2":
			PlaySound("VOICE\ENGLISH\Jupiter_1.wav");
			Dialog.text = DLG_TEXT[204];
			link.l1 = DLG_TEXT[205];
			link.l1.go = "exit";
			AddDialogExitQuest("Jup_prepare_to_climb_again");
		break;

		case "Jup_heavy_bug":
			PlaySound("OBJECTS\VOICES\DEAD\male\Death_NPC_02.wav");
			Dialog.text = DLG_TEXT[206];
			link.l1 = DLG_TEXT[207];
			link.l1.go = "Jup_heavy_bug1";
		break;

		case "Jup_heavy_bug1":
			PlaySound("OBJECTS\VOICES\DEAD\male\Death_NPC_08.wav");
			Dialog.text = DLG_TEXT[208];
			link.l1 = DLG_TEXT[209];
			link.l1.go = "Jup_heavy_bug2";
		break;

		case "Jup_heavy_bug2":
			PlaySound("OBJECTS\VOICES\DEAD\male\Death_NPC_01.wav");
			Dialog.text = DLG_TEXT[210];
			link.l1 = DLG_TEXT[211];
			link.l1.go = "exit";
			AddDialogExitQuest("Jup_continues_to_skull");
		break;

		case "Jup_at_the_skull":
			PlaySound("OBJECTS\VOICES\DEAD\male\Death_NPC_08.wav");
			Dialog.text = DLG_TEXT[212];
			link.l1 = DLG_TEXT[213];
			link.l1.go = "exit";
			AddDialogExitQuest("Jup_skull_rope_delay");
		break;

		case "Jup_sinks_rope":
			PlaySound("OBJECTS\VOICES\DEAD\male\Death_NPC_02.wav");
			Dialog.text = DLG_TEXT[214];
			link.l1 = DLG_TEXT[215];
			link.l1.go = "Jup_sinks_rope1";
		break;

		case "Jup_sinks_rope1":
			PlaySound("OBJECTS\VOICES\DEAD\male\Death_NPC_08.wav");
			Dialog.text = DLG_TEXT[216];
			link.l1 = DLG_TEXT[217];
			link.l1.go = "exit";
			AddDialogExitQuest("BH_rope_down");
		break;

		case "Jup_takes_spade":
			PlaySound("OBJECTS\DUEL\man_hit1.wav");
			Dialog.text = DLG_TEXT[218];
			link.l1 = DLG_TEXT[219];
			link.l1.go = "exit";
			AddDialogExitQuest("Jup_digs_hole1");
		break;

		case "new_beeline":
			PlaySound("VOICE\ENGLISH\Jupiter_aha.wav");
			Dialog.text = DLG_TEXT[220];
			link.l1 = DLG_TEXT[213];
			link.l1.go = "exit";
			AddDialogExitQuest("new_beeline1");
		break;

		case "skeletons_found1":
			PlaySound("VOICE\ENGLISH\Jupiter_aha.wav");
			Dialog.text = DLG_TEXT[221];
			link.l1 = DLG_TEXT[222];
			link.l1.go = "exit";
			AddDialogExitQuest("skeletons_found2");
		break;

		case "prepare_tour2":
			PlaySound("OBJECTS\DUEL\man_hit1.wav");
			Dialog.text = DLG_TEXT[223];
			link.l1 = DLG_TEXT[224];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("where_are_the_maroons");
		break;

		case "prepare_tour3":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			Dialog.text = DLG_TEXT[225];
			link.l1 = DLG_TEXT[226];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("prepare_tour3_done");
		break;

		case "where_are_the_maroons1":
			PlaySound("VOICE\ENGLISH\jupiter_2.wav");
			Dialog.text = DLG_TEXT[227];
			link.l1 = DLG_TEXT[228];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("prepare_tour2_done");
		break;

		case "rope_to_raft":
			PlaySound("OBJECTS\DUEL\man_hit1.wav");
			Dialog.text = DLG_TEXT[229];
			link.l1 = DLG_TEXT[230];
			link.l1.go = "exit_stay";
			AddDialogExitQuest("rope_to_raft_done");
		break;

		case "Hero_my_cousin4":
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			Dialog.text = DLG_TEXT[231];
			link.l1 = DLG_TEXT[232];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("Hero_my_cousin5");
		break;

		case "maroons_defeated_again":
			PlaySound("VOICE\ENGLISH\Jupiter_1.wav");
			Dialog.text = DLG_TEXT[233];
			link.l1 = DLG_TEXT[234];
			link.l1.go = "exit_officer";
			AddDialogExitQuest("maroons_defeated_again1");
		break;

		case "last_treasuresack":
			PlaySound("VOICE\ENGLISH\Jupiter_1.wav");
			Dialog.text = DLG_TEXT[235];
			link.l1 = DLG_TEXT[236];
			link.l1.go = "exit";
			AddDialogExitQuest("last_treasuresack1");
		break;

		case "good_night4":
			PlaySound("VOICE\ENGLISH\Jupiter_aha.wav");
			Dialog.text = DLG_TEXT[237];
			link.l1 = DLG_TEXT[238];
			link.l1.go = "exit";
			AddDialogExitQuest("good_night5");
		break;

		case "attic_treasure":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
			Dialog.text = DLG_TEXT[239];
			link.l1 = DLG_TEXT[240];
			link.l1.go = "attic_treasure1";
		break;

		case "attic_treasure1":
			PlaySound("OBJECTS\DUEL\man_attack6.wav");
			Dialog.text = DLG_TEXT[241];
			link.l1 = DLG_TEXT[242];
			link.l1.go = "exit";
			AddDialogExitQuest("attic_treasure2");
		break;

		case "skeletons_talk":
			PlaySound("VOICE\ENGLISH\Jupiter_2.wav");
			Dialog.text = DLG_TEXT[243];
			link.l1 = DLG_TEXT[244];
			link.l1.go = "exit";
			AddDialogExitQuest("skeletons_talk1");
		break;

		case "poe_tired":
			PlaySound("VOICE\ENGLISH\Jupiter_aha.wav");
			Dialog.text = DLG_TEXT[245];
			link.l1 = DLG_TEXT[246];
			link.l1.go = "exit_stay";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "Exit_sit":
			LAi_SetSitType(NPchar);
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
		
		case "Exit_stay":
			LAi_SetSTayType(NPchar);
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "Exit_officer":
			if(IsOfficer(NPChar)) LAi_SetOfficerType(NPchar);
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
