//#include "DIALOGS\Divers_dialog.h"

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

			dialog.snd = "Voice\CLLA\CLLA001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;

		case "begin_1":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "ass_part1";
			PlayStereoSound("VOICE\ENGLISH\Dut_m_a_003.wav");
		// PB -->
			if(ENABLE_CHEATMODE)
			{
				link.l2 = DLG_TEXT[57];
				link.l2.go = "ass_part4";
				link.l3 = DLG_TEXT[58];
				link.l3.go = "ass_part5";
				link.l4 = DLG_TEXT[59];
				link.l4.go = "ass_fire";
				link.l5 = DLG_TEXT[60];
				link.l5.go = "back_diablo";
				link.l6 = DLG_TEXT[61];
				link.l6.go = "El_Morro";						
			}
		break;

		case "ass_part1":
			AddDialogExitQuest("embora");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "ass_part4":
			ChangeCharacterAddress(characterFromID("Horacio de la Vega"), "none", "");
			LAi_LocationFightDisable(&Locations[FindLocation("Havana_House_03")], true);
			ChangeCharacterAddressGroup(CharacterFromID("Enrique Padilla"), "Havana_House_03", "goto", "goto1");
			LAi_SetCitizenType(characterFromID("Enrique Padilla")); 
			GiveShip2Character(pchar,"XebecAS","El Diablo",-1,SPAIN,true,true);
			SetCharacterShipLocation(Pchar, "Cuba_port");
			HoistFlag(PERSONAL_NATION);
			PChar.Flags.Personal = 6; // PB: Amsterdam Skull Flag
			PChar.Flags.Personal.texture = 1;
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Chico Cois"));
			SetQuestHeader("Hitman");
			AddQuestRecord("Hitman", "19");
			Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_47";
			DoQuestReloadToLocation("Havana_House_03", "reload", "reload1" ,"_");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "ass_part5":
			ChangeCharacterAddress(characterFromID("Horacio de la Vega"), "none", "");
			LAi_LocationFightDisable(&Locations[FindLocation("Havana_House_03")], true);
			ChangeCharacterAddressGroup(CharacterFromID("Enrique Padilla"), "Havana_House_03", "goto", "goto1");
			LAi_SetCitizenType(characterFromID("Enrique Padilla")); 
			GiveShip2Character(pchar,"XebecAS","El Diablo",-1,SPAIN,true,true);
			SetCharacterShipLocation(Pchar, "Cuba_port");
			DoQuestReloadToLocation("Havana_House_03", "reload", "reload1" ,"_");
			HoistFlag(PERSONAL_NATION);
			PChar.Flags.Personal = 6; // PB: Amsterdam Skull Flag
			PChar.Flags.Personal.texture = 1;
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Chico Cois"));
			Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_65";

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "ass_fire":
			ChangeCharacterAddress(characterFromID("Horacio de la Vega"), "none", "");
			LAi_LocationFightDisable(&Locations[FindLocation("Havana_House_03")], true);
			ChangeCharacterAddressGroup(CharacterFromID("Enrique Padilla"), "Havana_House_03", "goto", "goto1");
			LAi_SetCitizenType(characterFromID("Enrique Padilla")); 
			GiveShip2Character(pchar,"XebecAS","El Diablo",-1,SPAIN,true,true);
			SetCharacterShipLocation(Pchar, "Cuba_port");
			DoQuestReloadToLocation("Havana_House_03", "reload", "reload1" ,"_");
			HoistFlag(PERSONAL_NATION);
			PChar.Flags.Personal = 6; // PB: Amsterdam Skull Flag
			PChar.Flags.Personal.texture = 1;
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Chico Cois"));
			Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_86";

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "back_diablo":		
			ChangeCharacterAddress(characterFromID("Horacio de la Vega"), "none", "");
			LAi_LocationFightDisable(&Locations[FindLocation("Havana_House_03")], true);
			GiveShip2Character(pchar,"Tartane1","The Mischievous",-1,ENGLAND,true,true);				
			SetCharacterShipLocation(Pchar, "Douwesen_port");
			DoQuestReloadToLocation("Douwesen_port", "reload", "reload1" ,"pardon_douwesen");
			HoistFlag(PERSONAL_NATION);
			PChar.Flags.Personal = 6; // PB: Amsterdam Skull Flag
			PChar.Flags.Personal.texture = 1;

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "El_Morro":
            ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Redmond_residence", "goto", "goto2");
            Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_1";				
			ChangeCharacterAddress(characterFromID("Horacio de la Vega"), "none", "");
			LAi_LocationFightDisable(&Locations[FindLocation("Havana_House_03")], true);
			GiveShip2Character(pchar,"XebecAS","El Diablo",-1,SPAIN,true,true);				
			SetCharacterShipLocation(Pchar, "REDMOND_PORT");
			DoQuestReloadToLocation("Redmond_Residence", "reload", "reload1" ,"_");
			HoistFlag(PERSONAL_NATION);
			PChar.Flags.Personal = 6; // PB: Amsterdam Skull Flag
			PChar.Flags.Personal.texture = 1;

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;				
		// PB <--

		case "begin_2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "begin_3";
                       PlayStereoSound("VOICE\ENGLISH\Eng_m_b_006.wav");
		break;


		case "begin_3":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "begin_4";

		break;

		case "begin_4":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "begin_5";

		break;
		
		case "begin_5":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[10];
			link.l1.go = "exit";
                       AddDialogExitQuest("combatingles");
		break;
		
		case "begin_6":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[11];
			link.l1.go = "exit";
                      PlayStereoSound("VOICE\ENGLISH\Eng_m_b_006.wav");			
                       AddDialogExitQuest("final_infeliz");
		break;

		case "begin_7":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "begin_8";

		break;

		case "begin_8":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "begin_9";
                        PlayStereoSound("INTERFACE\took_item.flac");
            			AddMoneyToCharacter(pchar, 20000);	
		break;

		case "begin_9":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "begin_10";

		break;

		case "begin_10":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "begin_11";

		break;

		case "begin_11":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[0];
			link.l1.go = "exit";
                       AddDialogExitQuest("vertrigger");			
		break;
		
		case "begin_12":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "begin_13";

		break;

		case "begin_13":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "begin_14";
                        PlayStereoSound("INTERFACE\took_item.flac");
            			AddMoneyToCharacter(pchar, 20000);			

		break;

		case "begin_14":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "begin_15";

		break;

		case "begin_15":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "begin_16";

		break;

		case "begin_16":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "begin_17";

		break;

		case "begin_17":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "begin_18";

		break;

		case "begin_18":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "exit";
		       GiveItem2Character(Pchar, "Pass");			
                       AddDialogExitQuest("ver_Larner");			
		break;

		case "begin_19":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "begin_20";
                       PlayStereoSound("VOICE\ENGLISH\Eng_m_c_003.wav");
		break;

		case "begin_20":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "begin_21";

		break;

		case "begin_21":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "begin_22";

		break;

		case "begin_22":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "exit";		
                       AddDialogExitQuest("news_coisbis");			
		break;

		case "begin_23":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[0];
			link.l1.go = "exit";		
                       AddDialogExitQuest("final_infeliz");			
		break;

		case "begin_24":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "exit";		
                       AddDialogExitQuest("Cuban_village");			
		break;

		case "begin_25":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "exit";		
                       AddDialogExitQuest("Cuban_villagebis2");			
		break;

		case "begin_26":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "exit";
            PlayStereoSound("VOICE\ENGLISH\Spa_m_a_001.wav");			
                       AddDialogExitQuest("Fort_Captain2");			
		break;

		case "begin_27":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "exit";		
                       AddDialogExitQuest("batalha_praiabis2");			
		break;

		case "begin_28":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "exit";		
                       AddDialogExitQuest("morro_topl");			
		break;

		case "begin_29":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "begin_30";

		break;

		case "begin_30":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "exit";		
                       AddDialogExitQuest("morro_down11");			
		break;		
       
               case "Exit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		
               break;
	}
}
