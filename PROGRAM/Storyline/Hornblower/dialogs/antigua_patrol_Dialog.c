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
//			NPChar.quest.meeting = NPC_Meeting;
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

			if(CheckQuestAttribute("Players_rank", "Midshipman"))
			{				
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1] + GetMyName(PChar) + Pchar.lastname + DLG_TEXT[2] + GetMyShipNameShow(PChar) + ".";
				link.l1.go = "Continue Chatter Mishipman";
			}
			if(CheckQuestAttribute("Players_rank", "Lieutenant"))
			{				
				dialog.text = DLG_TEXT[3];
				link.l1 = DLG_TEXT[4] + GetMyName(PChar) + Pchar.lastname + DLG_TEXT[2] + GetMyShipNameShow(PChar) + ".";
				link.l1.go = "Continue Chatter Lieutenant";
			}
			if(CheckQuestAttribute("Players_rank", "Commander"))
			{
				dialog.text = DLG_TEXT[18];
				link.l1 = DLG_TEXT[19] + GetMyName(PChar) + Pchar.lastname + DLG_TEXT[2] + GetMyShipNameShow(PChar) + ".";
				link.l1.go = "Continue Chatter Commander";
			}
		break;

		case "Continue Chatter Commander":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[8];
			link.l2.go = "directions";
		break;

		case "Continue Chatter Lieutenant":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[8];
			link.l2.go = "directions";
		break;

		case "Continue Chatter Mishipman":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[8];
			link.l2.go = "directions";
		break;

		case "directions":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Naval Yard";
			link.l2 = DLG_TEXT[12];
			link.l2.go = "Store";
			link.l3 = DLG_TEXT[14];
			link.l3.go = "Naval HQ";
		break;

		case "Naval Yard":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[12];
			link.l2.go = "Store";
			link.l3 = DLG_TEXT[14];
			link.l3.go = "Naval HQ";
		break;

		case "Store":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[14];
			link.l2.go = "Naval HQ";
			link.l3 = DLG_TEXT[10];
			link.l3.go = "Naval Yard";
		break;

		case "Naval HQ":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[12];
			link.l2.go = "Store";
			link.l3 = DLG_TEXT[10];
			link.l3.go = "Naval Yard";
		break;

	
	}
}
