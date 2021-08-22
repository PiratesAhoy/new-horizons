//#include "DIALOGS\andre juliao_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	int iTest;
	ref PChar;
	PChar = GetMainCharacter();

	int smuggle_cargo, smuggle_amount, smuggle_cargo2, smuggle_amount2;

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "Sit_Left_Strong_Yes";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_stay1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Left_Dialog_1";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\ANJU\ANJU001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			
			iTest = 0;

			if ((characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers == "find")&&(iTest <QUEST_COUNTER))
			{
				dialog.snd = "Voice\ANJU\ANJU002";
				Dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "find";
				iTest = iTest + 1;
			}
			if ((characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers == "search")&&(iTest <QUEST_COUNTER))
			{
				dialog.snd = "Voice\ANJU\ANJU003";
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "search_1";
				iTest = iTest + 1;
			}
			if ((characters[GetCharacterIndex("Thomas O'Reily")].quest.contraband == "boarding")&&(iTest < QUEST_COUNTER))
			{
				smuggle_cargo = sti(Characters[GetCharacterIndex("Thomas O'Reily")].smuggle_cargo);
				smuggle_amount = sti(Characters[GetCharacterIndex("Thomas O'Reily")].smuggle_amount);
				smuggle_cargo2 = sti(Characters[GetCharacterIndex("Thomas O'Reily")].smuggle_cargo2);
				smuggle_amount2 = sti(Characters[GetCharacterIndex("Thomas O'Reily")].smuggle_amount2);
				if (GetSquadronGoods(pchar, smuggle_cargo) >= smuggle_amount && GetSquadronGoods(pchar, smuggle_cargo2) >= smuggle_amount2)
				{
					Preprocessor_Add("nation", GetNationDescByType(GetTownNation("Redmond")));
					link.l2 = pcharrepphrase(DLG_TEXT[6], DLG_TEXT[7]);
					link.l2.go = "contraband";
					iTest = iTest + 1;
				}
			}
			NextDiag.TempNode = "First time";
		break;

		case "contraband":
			dialog.snd = "Voice\ANJU\ANJU004";
			dialog.text = DLG_TEXT[8];
			link.l1 = pcharrepphrase(GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[9])]) + DLG_TEXT[11], DLG_TEXT[12] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[13])]) + DLG_TEXT[15]);
			link.l1.go = "contraband_1";
		break;
		
		case "contraband_1":
			dialog.snd = "Voice\ANJU\ANJU005";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "contraband_2";
//			AddQuestRecord("Thomas_OReily_contraband", 5);
		break;

		case "contraband_2":
			dialog.snd = "Voice\ANJU\ANJU006";
			dialog.text = DLG_TEXT[18];
			link.l1 = pcharrepphrase(DLG_TEXT[19], DLG_TEXT[20]);
			link.l1.go = "exit";
			smuggle_cargo = sti(Characters[GetCharacterIndex("Thomas O'Reily")].smuggle_cargo);
			smuggle_amount = sti(Characters[GetCharacterIndex("Thomas O'Reily")].smuggle_amount);
			smuggle_cargo2 = sti(Characters[GetCharacterIndex("Thomas O'Reily")].smuggle_cargo2);
			smuggle_amount2 = sti(Characters[GetCharacterIndex("Thomas O'Reily")].smuggle_amount2);
			RemoveCharacterGoods(GetMainCharacter(), smuggle_cargo2, smuggle_amount2); //NK Remove goods
			RemoveCharacterGoods(GetMainCharacter(), smuggle_cargo, smuggle_amount);
			characters[GetCharacterIndex("Thomas O'Reily")].quest.contraband = "almost_done";

			Preprocessor_AddQuestData("Andre Juliao", GetMyFullName(NPChar));
			Preprocessor_AddQuestData("Andre", GetMyName(NPChar));
			Preprocessor_AddQuestData("Thomas", GetMyName(CharacterFromID("Thomas O'Reily")));
			AddQuestRecord("Thomas_OReily_contraband", 4);
			Preprocessor_Remove("Thomas");
			Preprocessor_Remove("Andre");
			Preprocessor_Remove("Andre Juliao");

			if (Characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers == "0") Characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers = "1"; // NK
		break;

		case "find":
			dialog.snd = "Voice\ANJU\ANJU007";
			Dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "find_1";
		break;

		case "find_1":
			dialog.snd = "Voice\ANJU\ANJU008";
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "fight";
			link.l2 = DLG_TEXT[25];
			link.l2.go = "find_2";
			link.l3 = DLG_TEXT[26];
			link.l3.go = "exit";
			characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers = "teodoro";
		break;

		case "find_2":
			dialog.snd = "Voice\ANJU\ANJU009";
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "fight";
			link.l2 = DLG_TEXT[29];
			link.l2.go = "exit";
			characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers = "teodoro";
		break;

		case "fight":
			dialog.snd = "Voice\ANJU\ANJU010";
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "fight_1";
			link.l2 = DLG_TEXT[32];
			link.l2.go = "exit";
		break;

		case "fight_1":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("andre_juliao_fight_1");
		break;

		case "search_1":
			dialog.snd = "Voice\ANJU\ANJU011";
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "right";
			link.l2 = DLG_TEXT[35];
			link.l2.go = "wrong";
		break;

		case "wrong":
			dialog.snd = "Voice\ANJU\ANJU012";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "wrong_1";
		break;

		case "wrong_1":
			dialog.snd = "Voice\ANJU\ANJU013";
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers = "teodoro";
		break;

		case "right":
			dialog.snd = "Voice\ANJU\ANJU014";
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "right_1";
		break;

		case "right_1":
			dialog.snd = "Voice\ANJU\ANJU015";
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "right_2";
		break;

		case "right_2":
			dialog.snd = "Voice\ANJU\ANJU016";
			dialog.text = DLG_TEXT[44] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[45])]) + DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "right_3";
		break;

		case "right_3":
			dialog.snd = "Voice\ANJU\ANJU017";
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Raoul Calmes")].quest.visit = "2";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
