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

			if(Rand(1)==0)
			{
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}
			else
			{
				if(GetAttribute(NPChar, "quest.meeting") != "1")
				{
					dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + ".";
					link.l1.go = "intro_done";
				}
				else
				{
					dialog.text = DLG_TEXT[6] + GetMyLastName(PChar) + "?";
					link.l1 = DLG_TEXT[7];
					link.l1.go = "colony";
					link.l2 = LinkRandPhrase(DLG_TEXT[10], DLG_TEXT[11], DLG_TEXT[12]);
					link.l2.go = "town";
					link.l3 = DLG_TEXT[28];
					link.l3.go = "info";
				}
			}
		break;

		case "intro_done":
			NPChar.quest.meeting = "1";
			dialog.text = DLG_TEXT[4] + GetMySimpleName(NPChar) + DLG_TEXT[5];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "colony";
			link.l2 = LinkRandPhrase(DLG_TEXT[10], DLG_TEXT[11], DLG_TEXT[12]);
			link.l2.go = "town";
			link.l3 = DLG_TEXT[28];
			link.l3.go = "info";
		break;

		case "colony":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
		break;

		case "town":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			dialog.Text = RandPhrase(DLG_TEXT[13], DLG_TEXT[14], DLG_TEXT[15], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			if(GetAttribute(NPChar, "quest.gate") != "done")
			{
				link.l1 = DLG_TEXT[16];
				link.l1.go = "town_tavern";
			}
			else
			{
				link.l1 = DLG_TEXT[17];
				link.l1.go = "town_tavern2";
			}
			link.l2 = DLG_TEXT[18];
			link.l2.go = "town_store";
			link.l3 = DLG_TEXT[1];
			link.l3.go = "exit";
		break;

		case "town_tavern":
			NPChar.quest.gate = "done";
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[26] + DLG_TEXT[27];
			link.l2.go = "First time";		
		break;

		case "town_tavern2":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[25] + DLG_TEXT[27];
			link.l2.go = "First time";	
		break;

		case "town_store":
			if(GetMySimpleOldName(NPChar) == "Bryan the Disgruntled") Preprocessor_Add("other", GetMySimpleName(CharacterFromID("Bloody Norm Kidd")));
			else Preprocessor_Add("other", GetMySimpleName(CharacterFromID("Bryan the Disgruntled")));
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[26] + DLG_TEXT[27];
			link.l2.go = "First time";
		break;

		case "info":
			dialog.text = DLG_TEXT[29];
			link.l1 = GetMyFullName(CharacterFromID("Eugene Martin")) + DLG_TEXT[30];
			link.l1.go = "localtrader";
			link.l2 = GetMyFullName(CharacterFromID("Florentin Destot")) + DLG_TEXT[31];
			link.l2.go = "tavernkeeper";
			link.l3 = DLG_TEXT[1];
			link.l3.go = "exit";
		break;

		case "localtrader":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
			if (makeint(PChar.money) >= 1)
			{
				link.l2 = DLG_TEXT[34];
				link.l2.go = "info_pay1";
			}
			if (makeint(PChar.money) >= 100)
			{
				link.l3 = DLG_TEXT[35];
				link.l3.go = "info_pay100";
			}
		break;

		case "info_pay1":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -1);
			AddMoneyToCharacter(NPChar, 1);
			dialog.text = GetMyFullName(CharacterFromID("Eugene Martin")) + DLG_TEXT[36];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[26] + DLG_TEXT[27];
			link.l2.go = "First time";
		break;

		case "info_pay100":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -100);
			AddMoneyToCharacter(NPChar, 100);
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "info_pay100_2";
		break;

		case "info_pay100_2":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40] + GetMySimpleName(NPchar) + "!";
			link.l1.go = "exit";
		break;

		case "tavernkeeper":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[20] + DLG_TEXT[27];
			link.l2.go = "First time";
		break;
	}
}