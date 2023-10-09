//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode; //"First time";
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
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;

		case "saw_sanjuan_abduction":
			if (PChar.sex == "man") Preprocessor_Add("person", XI_ConvertString("woman"));
			else Preprocessor_Add("person", XI_ConvertString("man"));
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "saw_sanjuan_abduction2";
		break;

		case "saw_sanjuan_abduction2":
			if (PChar.sex == "man")
			{
				Preprocessor_Add("pronoun", XI_ConvertString("she"));
				Preprocessor_Add("pronoun2", XI_ConvertString("her"));
			}
			else
			{
				Preprocessor_Add("pronoun", XI_ConvertString("he"));
				Preprocessor_Add("pronoun2", XI_ConvertString("him"));
			}
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "saw_sanjuan_abduction3";
		break;

		case "saw_sanjuan_abduction3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
		break;

		case "port_royale_dungeon":
			Preprocessor_Add("merchant", GetMyLastName(characterfromID("Gilbert Downing")));
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "port_royale_dungeon2";
		break;

		case "port_royale_dungeon2":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "port_royale_dungeon3";
		break;

		case "port_royale_dungeon3":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			if (CheckQuestAttribute("ardent_kidnap.status", "no_wine")) link.l1.go = "port_royale_dungeon4a";
			else link.l1.go = "port_royale_dungeon4";
		break;

		case "port_royale_dungeon4":
			Preprocessor_AddQuestData("villain", GetMySimpleName(characterfromID(PChar.quest.villain)));
			Preprocessor_AddQuestData("romance", GetMySimpleName(characterfromID(PChar.quest.romance)));
			AddQuestRecord("Abduction", 16);
			Preprocessor_Remove("romance");
			Preprocessor_Remove("villain");
			if (PChar.sex == "man") Preprocessor_Add("person", XI_ConvertString("woman"));
			else Preprocessor_Add("person", XI_ConvertString("man"));
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
		break;

		case "port_royale_dungeon4a":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
		break;

		case "abduction_tavern":
			if (PChar.sex == "man") Preprocessor_Add("person", XI_ConvertString("woman"));
			else Preprocessor_Add("person", XI_ConvertString("man"));
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "abduction_tavern2";
		break;

		case "abduction_tavern2":
			if (PChar.sex == "man")
			{
				Preprocessor_Add("pronoun", XI_ConvertString("her"));
				Preprocessor_Add("pronoun2", XI_ConvertString("she"));
			}
			else
			{
				Preprocessor_Add("pronoun", XI_ConvertString("him"));
				Preprocessor_Add("pronoun2", XI_ConvertString("he"));
			}
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			AddDialogExitQuest("abduction_officer_tavern_reset");
			link.l1.go = "exit";
		break;

		case "hunt_philipsburg_citizen":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			Preprocessor_Add("villain", GetMySimpleName(characterfromID(PChar.quest.villain)));
			Preprocessor_Add("ship", Characters[GetCharacterIndex(PChar.quest.villain)].Ship.Name);
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(CharacterFromId(PChar.quest.villain))));
			dialog.text = TimeGreeting() + DLG_TEXT[22] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + "?";
			link.l1 = DLG_TEXT[24];
			link.l1.go = "hunt_philipsburg_citizen2";
		break;

		case "hunt_philipsburg_citizen2":
			Preprocessor_Add("ship", Characters[GetCharacterIndex(PChar.quest.villain)].Ship.Name);
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "hunt_philipsburg_citizen3";
		break;

		case "hunt_philipsburg_citizen3":
			Preprocessor_Add("villain", GetMySimpleName(characterfromID(PChar.quest.villain)));
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromId(PChar.quest.villain))));
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(CharacterFromId(PChar.quest.villain))));
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "hunt_philipsburg_citizen4";
		break;

		case "hunt_philipsburg_citizen4":
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromId(PChar.quest.villain))));
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			AddDialogExitQuest("hunt_try_marigot");
			link.l1.go = "exit";
		break;

		case "hunt_marigot_citizen":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			dialog.text = TimeGreeting() + DLG_TEXT[31] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + "?";
			link.l1 = DLG_TEXT[32];
			link.l1.go = "hunt_marigot_citizen2";
		break;

		case "hunt_marigot_citizen2":
			Preprocessor_Add("villain", GetMySimpleName(characterfromID(PChar.quest.villain)));
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(CharacterFromId(PChar.quest.villain))));
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "hunt_marigot_citizen3";
		break;

		case "hunt_marigot_citizen3":
			Preprocessor_Add("villain", GetMySimpleName(characterfromID(PChar.quest.villain)));
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(CharacterFromId(PChar.quest.villain))));
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "hunt_marigot_citizen4";
		break;

		case "hunt_marigot_citizen4":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "hunt_marigot_citizen5";
		break;

		case "hunt_marigot_citizen5":
			Preprocessor_Add("ship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			AddDialogExitQuest("hunt_seen_battleship");
			link.l1.go = "exit";
		break;
	}
}