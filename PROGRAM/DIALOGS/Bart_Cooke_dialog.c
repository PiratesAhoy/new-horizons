//#include "DIALOGS\Bart_Cooke_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag, NextDiag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	makearef(NextDiag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
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

			if(NPChar.quest.meeting == "0")
			{
				Dialog.snd = "voice\STBO\STBO002";
				d.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1] + GetMyFullName(PChar) + DLG_TEXT[2];
				Link.l1 = pcharrepphrase(DLG_TEXT[3], DLG_TEXT[4]);
				Link.l1.go = "meeting";
				NPC_Meeting = "1"; 
			}
			else
			{
				Dialog.snd = "voice\STBO\STBO003";
				d.Text = DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				Link.l1.go = "meeting";
			}
			Diag.TempNode = "First Time";
		break;

		case "Meeting":
			if (pchar.location.from_sea == "Redmond_shore_02")
			{
				Dialog.snd = "voice\STBO\STBO006";
				dialog.text = DLG_TEXT[7] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[8])]) + DLG_TEXT[9];
				link.l1 = pcharrepphrase(DLG_TEXT[10], DLG_TEXT[11]);
				link.l1.go = "node_1";
				//Levis: Let's give you the option to side with them; though the smugglers do need to like you a bit to do it
				if(CheckSmugglerLiking(pchar) >= 50)
				{
					link.l2 = DLG_TEXT[17];
					link.l2.go = "help smugglers";
				}
				LAi_QuestDelay("Thomas interest for smugglers",0);
			}
			else
			{
				Dialog.snd = "voice\STBO\STBO007";
				dialog.text = DLG_TEXT[12];
				link.l1 = pcharrepphrase(DLG_TEXT[13], DLG_TEXT[14]);
				link.l1.go = "exit";
			}
		break;

		case "node_1":
			Preprocessor_Add("pronoun", GetMyPronounObj(PChar));
			Dialog.snd = "voice\STBO\STBO008";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
			AddDialogExitQuest("bill_jellybones_attack");
			characters[GetCharacterIndex("Thomas O'Reily")].quest.contraband = "after_fight";
		break;
		
		case "help smugglers":
			AddDialogExitQuest("sided with smugglers instead of Thomas");
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
		break;
	}
}

