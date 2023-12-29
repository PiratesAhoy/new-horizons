//#include "DIALOGS\Greenford Soldier_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d; 
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

	
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			int iPhrase = rand(10);
			
			switch (iPhrase)
			{
				case 0:
					dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "exit";
				break;
				
				case 1:
					dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "exit";
				break;
				
				case 2:
					dialog.text = DLG_TEXT[4];
					link.l1 = DLG_TEXT[5];
					link.l1.go = "exit";
				break;
				
				case 3:
					dialog.text = DLG_TEXT[6];
					link.l1 = DLG_TEXT[7];
					link.l1.go = "exit";
				break;
				
				case 4:
					dialog.text = DLG_TEXT[8];
					link.l1 = DLG_TEXT[9];
					link.l1.go = "exit";
				break;
				
				case 5:
					dialog.text = DLG_TEXT[10];
					link.l1 = DLG_TEXT[11];
					link.l1.go = "exit";
				break;
				
				case 6:
					dialog.text = DLG_TEXT[12];
					link.l1 = DLG_TEXT[13];
					link.l1.go = "exit";
				break;
				
				case 7:
					dialog.text = DLG_TEXT[14];
					link.l1 = DLG_TEXT[15];
					link.l1.go = "exit";
				break;
				
				case 8:
					dialog.text = DLG_TEXT[16];
					link.l1 = DLG_TEXT[17];
					link.l1.go = "exit";
				break;
				
				case 9:
					dialog.text = DLG_TEXT[18];
					link.l1 = DLG_TEXT[19];
					link.l1.go = "exit";
				break;
				
				case 10:
					dialog.text = DLG_TEXT[20];
					link.l1 = DLG_TEXT[21];
					link.l1.go = "exit";
				break;
			}
			
			if (pchar.quest.main_line == "resque_researcher_good")
			{
				link.l2 = DLG_TEXT[22];
				link.l2.go = "researcher_2";
			}
			if (pchar.quest.main_line == "return_idol_from_greenford_soldier")
			{
				link.l2 = DLG_TEXT[23];
				link.l2.go = "return_idol_from_greenford_soldier_2";
			}			
			Diag.TempNode = "first time";
		break;

		case "return_idol_from_greenford_soldier_2":
			dialog.snd = "Voice\GRSO\GRSO005";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "return_idol_from_greenford_soldier_3";
		break;

		case "return_idol_from_greenford_soldier_3":
			dialog.snd = "Voice\GRSO\GRSO006";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "return_idol_from_greenford_soldier_4";
		break;

		case "return_idol_from_greenford_soldier_4":
			dialog.snd = "Voice\GRSO\GRSO007";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "return_idol_from_greenford_soldier_5";
		break;

		case "return_idol_from_greenford_soldier_5":
			dialog.snd = "Voice\GRSO\GRSO008";
			dialog.text = DLG_TEXT[30] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "return_idol_from_greenford_soldier_6";
		break;

		case "return_idol_from_greenford_soldier_6":
			dialog.snd = "Voice\GRSO\GRSO009";
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "return_idol_from_greenford_soldier_7";
		break;

		case "return_idol_from_greenford_soldier_7":
			dialog.snd = "Voice\GRSO\GRSO010";
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "return_idol_from_greenford_soldier_8";
		break;

		case "return_idol_from_greenford_soldier_8":
			dialog.snd = "Voice\GRSO\GRSO011";
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "return_idol_from_greenford_soldier_10";
		break;

		case "return_idol_from_greenford_soldier_10":
			dialog.snd = "Voice\GRSO\GRSO012";
			Preprocessor_Add("pronoun3", XI_ConvertString(GetMyPronounPossessive(CharacterFromID("Danielle"))));
			if (Characters[GetCharacterIndex("Danielle")].sex == "woman")
			{
				dialog.text = DLG_TEXT[39];
			}
			else
			{
				dialog.text = DLG_TEXT[87];
			}
			link.l1 = DLG_TEXT[40];
			link.l1.go = "return_idol_from_greenford_soldier_11";
		break;

		case "return_idol_from_greenford_soldier_11":
			dialog.snd = "Voice\GRSO\GRSO013";
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(CharacterFromID("Danielle"))));
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "return_idol_from_greenford_soldier_12";
		break;

		case "return_idol_from_greenford_soldier_12":
			dialog.snd = "Voice\GRSO\GRSO014";
			if (Characters[GetCharacterIndex("Danielle")].sex == "woman") Preprocessor_Add("girl", XI_ConvertString("girl"));
			else Preprocessor_Add("girl", XI_ConvertString("lad"));
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(CharacterFromID("Danielle"))));
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "return_idol_from_greenford_soldier_13";
		break;

		case "return_idol_from_greenford_soldier_13":
			dialog.snd = "Voice\GRSO\GRSO015";
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(CharacterFromID("Danielle"))));
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "return_idol_from_greenford_soldier_14";
		break;

		case "return_idol_from_greenford_soldier_14":
			dialog.snd = "Voice\GRSO\GRSO016";
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "return_idol_from_greenford_soldier_15";
		break;

		case "return_idol_from_greenford_soldier_15":
			dialog.snd = "Voice\GRSO\GRSO017";
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "exit";
			pchar.quest.main_line = "return_idol_from_greenford";
			AddQuestRecord("Revenge_for_Silehard", 5);
		break;

		case "researcher_2":
			dialog.snd = "Voice\GRSO\GRSO018";
			dialog.text = DLG_TEXT[51] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "researcher_3";
		break;

		case "researcher_3":
			dialog.snd = "Voice\GRSO\GRSO019";
			dialog.text = DLG_TEXT[54] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "researcher_4";
		break;

		case "researcher_4":
			dialog.snd = "Voice\GRSO\GRSO020";
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "researcher_5";
		break;

		case "researcher_5":
			dialog.snd = "Voice\GRSO\GRSO021";
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "researcher_6";
		break;

		case "researcher_6":
			dialog.snd = "Voice\GRSO\GRSO022";
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "researcher_7";
		break;

		case "researcher_7":
			dialog.snd = "Voice\GRSO\GRSO023";
			dialog.text = DLG_TEXT[63] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[64];
			if (makeint(pchar.money) >= 1200)
			{
				link.l1 = DLG_TEXT[65];
				link.l1.go = "researcher_money";
			}
			if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) >= 5)
			{
				link.l2 = DLG_TEXT[66];
				link.l2.go = "researcher_leadership";
			}
			link.l3 = DLG_TEXT[67];
			link.l3.go = "exit";
		break;

		case "researcher_money":
			dialog.snd = "Voice\GRSO\GRSO024";
			dialog.text = DLG_TEXT[68] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "researcher_money_2";
			link.l2 = DLG_TEXT[71];
			link.l2.go = "exit";
		break;

		case "researcher_money_2":
			dialog.snd = "Voice\GRSO\GRSO025";
			AddQuestRecord("resque_researcher", 6);
			dialog.text = DLG_TEXT[72] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "research_exit";
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, -1200);
		break;

		case "researcher_leadership":
			dialog.snd = "Voice\GRSO\GRSO026";
			dialog.text = DLG_TEXT[75] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "research_leadership_2";
		break;

		case "research_leadership_2":
			dialog.snd = "Voice\GRSO\GRSO027";
			AddQuestRecord("resque_researcher", 7);
			dialog.text = DLG_TEXT[78] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "research_exit";
		break;

		case "research_exit":
			DialogExit();
			AddDialogExitQuest("soldier_help_us_resque_researher");
		break;

		case "drink":
			Diag.TempNode = "first time";
	
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay1";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\GRSO\GRSO071";
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "drink_2";
		break;

		case "drink_2":
			dialog.snd = "Voice\GRSO\GRSO072";
			dialog.text = DLG_TEXT[83] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "drink_exit";
			link.l2 = DLG_TEXT[86];
			link.l2.go = "fight_exit";
		break;

		case "drink_exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			npchar.location = "none";
		break;

		case "fight_exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogexitQuest("fight_with_soldier_for_drink");
		break;

	}
}
