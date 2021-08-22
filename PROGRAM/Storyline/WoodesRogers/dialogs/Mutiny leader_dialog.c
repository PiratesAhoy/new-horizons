//#include "DIALOGS\Thug_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();


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
			Dialog.snd = "voice\THDI\THDI001";

			if(NPChar.id == "Fletcher Christian")
			{
				PlaySound("VOICE\ENGLISH\pir_capQ.wav");
				dialog.text = DLG_TEXT[12];
				link.l1 = DLG_TEXT[13];
				link.l1.go = "Exit";
			} 
		
			if(NPChar.id == "Constable Mills")
			{
				PlaySound("VOICE\ENGLISH\Mutineer_Mills.wav");
				dialog.text = DLG_TEXT[16];
				link.l1 = DLG_TEXT[17];
				link.l1.go = "Exit";
			} 

			if(NPChar.id == "Midshipman Young")
			{
				PlaySound("VOICE\ENGLISH\pir_capEE.wav");
				dialog.text = DLG_TEXT[14];
				link.l1 = DLG_TEXT[15];
				link.l1.go = "Exit";
			} 

			NextDiag.TempNode = "First time";
		break;


		case "Young":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload1");
			PlaySound("VOICE\ENGLISH\Mutineer_Young.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("mutiny_cabin3");
		break;

		case "Mills":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto8");
			PlaySound("VOICE\ENGLISH\Mutineer_Mills.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("mutiny_cabin4");
		break;

		case "Christian":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload1");
			PlaySound("VOICE\ENGLISH\Mutineer_Christian.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("mutiny_cabin5");
		break;

		case "Christian2":
			PlaySound("VOICE\ENGLISH\pir_capM.wav");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit";
			AddDialogExitQuest("mutiny_officers2");
		break;

		case "Young2":
			PlaySound("VOICE\ENGLISH\pir_capC.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Exit";
	//	NextDiag.TempNode = "First time";
			AddDialogExitQuest("mutiny_officers4");
		break;
		
		case "Mills2":
			PlaySound("VOICE\ENGLISH\gm_crew16B.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Exit";
	//	NextDiag.TempNode = "First time";
			AddDialogExitQuest("mutiny_officers6");
		break;
	//-----------------------------------------------------------
		case "Mills3":
			PlaySound("VOICE\ENGLISH\Mutineer_Mills.wav");
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("mutiny_officers9");
		break;

		case "Young3":
			PlaySound("VOICE\ENGLISH\pir_capEE.wav");
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("mutiny_officers10");
		break;

		case "Christian3":
			PlaySound("VOICE\ENGLISH\pir_capQ.wav");
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("mutiny_officers11");
		break;
	//-----------------------------------------------------------
	//careen shore
	//Christian
		case "careen_mutineers1":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "randitem", "randitem42");
			PlaySound("VOICE\ENGLISH\Mutineer_Christian.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("careen_mutineers2");
		break;

	//Mills
		case "careen_mutineers2":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "randitem", "randitem42");
			PlaySound("VOICE\ENGLISH\gm_crew16B.wav");
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("careen_mutineers3");
		break;

	//Young
		case "careen_mutineers3":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "randitem", "randitem42");
			PlaySound("VOICE\ENGLISH\Mutineer_Young.wav");
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("careen_mutineers5");
		break;

	//Christian
		case "careen_mutineers5":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "randitem", "randitem42");
			PlaySound("VOICE\ENGLISH\pir_capQ.wav");
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("careen_mutineers6");
		break;

	//Mills
		case "careen_mutineers6":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "randitem", "randitem42");
			PlaySound("VOICE\ENGLISH\Mutineer_Mills.wav");
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("careen_mutineers7");
		break;

	//Young
		case "careen_mutineers7":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "randitem", "randitem42");
			PlaySound("VOICE\ENGLISH\pir_capEE.wav");
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("careen_mutineers8");
		break;

	//Christian
		case "careen_mutineers17_A":
			PlaySound("VOICE\ENGLISH\pir_capKK.wav");
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("careen_mutineers17_B");
		break;

	//mutineer_32
		case "careen_mutineers17_B":
			PlaySound("VOICE\ENGLISH\Dupin_no_no.wav");
			LAi_ActorTurnToCharacter(characterFromID("mutineer_32"), characterFromID("Fletcher Christian"));
			LAi_ActorTurnToCharacter(characterFromID("Fletcher Christian"), characterFromID("mutineer_32"));

			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("careen_mutineers17_C");
		break;

	//mutineer_32
		case "careen_mutineers25":
			PlaySound("VOICE\ENGLISH\Dupin_good_work.wav");
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "Exit";
			AddDialogExitQuest("careen_mutineers25_A");
		break; 

	//mutineer_8
		case "careen_mutineers25_A":
			PlaySound("VOICE\ENGLISH\blaze_drunk1.wav");
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "Exit";
			AddDialogExitQuest("careen_mutineers25_B");
		break;

	//mutineer_32
		case "careen_mutineers25_B":
			PlaySound("VOICE\ENGLISH\Dupin_no_no.wav");
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "Exit";
			AddDialogExitQuest("careen_mutineers25_C");
		break;  

	//mutineer_11
		case "careen_mutineers25_C":
			PlaySound("VOICE\ENGLISH\Eng_m_a_059.wav");
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "Exit";
			AddDialogExitQuest("careen_mutineers25_D");
		break; 

	//mutineer_20
		case "careen_mutineers25_F":
			PlaySound("VOICE\ENGLISH\Fre_m_c_052.wav");
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "Exit";
			AddDialogExitQuest("careen_mutineers25_G");
		break;

	//mutineer_12
		case "careen_mutineers25_G":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "Exit";
			AddDialogExitQuest("careen_mutineers25_H");
		break;

	//mutineer_32
		case "careen_mutineers25_H":
			PlaySound("VOICE\ENGLISH\Dupin_splendid.wav");
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "Exit";
			AddDialogExitQuest("careen_mutineers26");	//to greetings serie
		break;

	//mutineer_32
		case "careen_corvette_returns3":
			PlaySound("VOICE\ENGLISH\Dupin_no_no.wav");
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "Exit";
			AddDialogExitQuest("careen_corvette_returns4");
		break;

	//mutineer_32
		case "corvette_boats":
			PlaySound("VOICE\ENGLISH\Dupin_good_day.wav");
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "corvette_boats1";
		break;

		case "corvette_boats1":
			RemoveCharacterEquip(NPchar, GUN_ITEM_TYPE);
			TakeItemFromCharacter(NPchar, "pistolcannon");
			GiveItem2Character(Pchar, "pistolcannon");			
			EquipCharacterByItem(Pchar, "pistolcannon");
			
		PlaySound("OBJECTS\DUEL\pistol_out1original.wav");
		PlaySound("OBJECTS\DUEL\pistol_out1original.wav");
			PlaySound("VOICE\ENGLISH\Dupin_get_to_work.wav");
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "Exit";
			AddDialogExitQuest("Pell_to_cliff");
		break;
	
	//mutineer_32
		case "to_the_blockhouse":
			PlaySound("OBJECTS\SHIPCHARGE\gunner_warning.wav");
			LAi_SetActorType(characterFromID("mutineer_32"));
			LAi_ActorTurnToLocator(characterFromID("mutineer_32"), "ships_other", "ship_4");

			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "exit";
			AddDialogExitQuest("prepare_withdraw");
		break;

	//mutineer_32
		case "no_ammo":
			PlaySound("VOICE\ENGLISH\Dupin_no_no.wav");
			dialog.text = DLG_TEXT[60];
			if(CheckCharacterItem(Pchar,"pistol3"))
			{
				link.l1 = DLG_TEXT[84];
			}
			else link.l1 = DLG_TEXT[61];
			link.l1.go = "exit";
			AddDialogExitQuest("pchar_to_blockhouse19");
		break;

	//mutineer_32
		case "what_now":
			PlaySound("VOICE\ENGLISH\Dupin_splendid.wav");
			dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "what_now1";
		break;

		case "what_now1":
			PlaySound("VOICE\ENGLISH\Dupin_no_no.wav");
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "what_now2";
		break;

		case "what_now2":
			PlaySound("VOICE\ENGLISH\Dupin_pardon.wav");
			PlaySound("VOICE\ENGLISH\Dupin_pardon.wav");
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "exit";
			AddDialogExitQuest("careen_shore_fight_end3");
		break;

	//mutineer_19
		case "swim":
			PlaySound("VOICE\ENGLISH\Dut_m_a_049.wav");
			dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "exit";
			AddDialogExitQuest("careen_shore_fight_end7");
		break;

	//mutineer_32
		case "shackels":
			PlaySound("VOICE\ENGLISH\Dupin_pardon.wav");
			PlaySound("VOICE\ENGLISH\Dupin_pardon.wav");
			dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
			AddDialogExitQuest("careen_shore_fight_end7_A");
		break;

	//mutineer_19
		case "lockpick":
			PlaySound("VOICE\ENGLISH\Dut_m_a_047.wav");
			dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "exit";
			AddDialogExitQuest("careen_shore_fight_end9");
		break;

	//mutineer_23
		case "crimson_pirate":
			PlaySound("VOICE\ENGLISH\gr_wench3_pos.wav");
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "crimson_pirate1";
		break;

		case "crimson_pirate1":
			PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "crimson_pirate2";
		break;

		case "crimson_pirate2":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79];
			link.l1.go = "crimson_pirate3";
		break;

		case "crimson_pirate3":
			PlaySound("VOICE\ENGLISH\gr_wench3.wav");
			dialog.text = DLG_TEXT[80];
			link.l1 = DLG_TEXT[81];
			link.l1.go = "exit";
			AddDialogExitQuest("careen_shore_fight_end13");
		break;

		case "school":
			PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
			dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "exit";
			AddDialogExitQuest("careen_shore_fight_end15");
		break;

	//mutineers in blockhouse
		case "blockhouse":
			if(NPChar.id == "mutineer_31") { PlaySound("VOICE\ENGLISH\Spa_m_a_030.wav"); }
			if(NPChar.id == "mutineer_10") { PlaySound("VOICE\ENGLISH\Dut_m_a_044.wav"); }
			if(NPChar.id == "mutineer_20") { PlaySound("VOICE\ENGLISH\Fre_m_c_052.wav"); }
			if(NPChar.id == "mutineer_4") { PlaySound("VOICE\ENGLISH\Por_m_a_028.wav"); }
			if(NPChar.id == "mutineer_32") { PlaySound("VOICE\ENGLISH\Dupin_no_no.wav"); }

			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "exit";
			NextDiag.TempNode = "blockhouse";
		break;

	//mutineer_32
		case "succeed":
			PlaySound("VOICE\ENGLISH\Dupin_splendid.wav");
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "succeed1";
		break;

		case "succeed1":
			PlaySound("VOICE\ENGLISH\Dupin_pardon.wav");
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "exit";
			AddDialogExitQuest("careen_shore_fight_end20");
		break;

		case "signal_how":
			PlaySound("VOICE\ENGLISH\Dupin_alright.wav");
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "exit";
			AddDialogExitQuest("careen_shore_fight_end23");
		break;

		case "neutral_crimson_pirate":
			PlaySound("VOICE\ENGLISH\gr_wench3_sigh.wav");
			dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "exit";
			NextDiag.TempNode = "neutral_crimson_pirate";
		break;

		case "neutral_king_david":
			PlaySound("AMBIENT\JAIL\sigh.wav");
			PlaySound("AMBIENT\JAIL\sigh.wav");
			dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];
			link.l1.go = "exit";
			NextDiag.TempNode = "neutral_king_david";
		break;

	//mutineer_23
		case "lockpick_shackles":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "exit";
			NextDiag.TempNode = "neutral_crimson_pirate";
			AddDialogExitQuest("explore_corvette22_A");
		break;

		case "swim_to_shore":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[100];
			link.l1.go = "exit";
			NextDiag.TempNode = "neutral_crimson_pirate";
			AddDialogExitQuest("explore_corvette30_A");
		break;

	//mutineer_19
		case "plan_corvette_fight":
			PlaySound("VOICE\ENGLISH\Dut_m_a_002.wav");
			dialog.text = DLG_TEXT[101];
			link.l1 = DLG_TEXT[102];
			link.l1.go = "exit";
			NextDiag.TempNode = "neutral_king_david";
			AddDialogExitQuest("explore_corvette32_B");
		break;

		case "no_slavers":
			PlaySound("VOICE\ENGLISH\Dut_m_a_007.wav");
			dialog.text = DLG_TEXT[103];
			link.l1 = DLG_TEXT[104];
			link.l1.go = "exit";
			NextDiag.TempNode = "neutral_king_david";
			AddDialogExitQuest("explore_corvette33_A");
		break;

	//mutineer_32
		case "no_doctor":
			PlaySound("VOICE\ENGLISH\Dupin_splendid.wav");
			dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[106];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_wdeck16");
		break;

	//mutineer_23
		case "doctors_face":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("car_convict6"));
			PlaySound("VOICE\ENGLISH\gr_wench3_pos.wav");
			dialog.text = DLG_TEXT[109];
			link.l1 = DLG_TEXT[110];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_wdeck22");
		break;

	//mutineer_32
		case "Isla_Mona":
			PlaySound("VOICE\ENGLISH\Dupin_jungle.wav");
			dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[112];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_wdeck27");
		break;


		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
