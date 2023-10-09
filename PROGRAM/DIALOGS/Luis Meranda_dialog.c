//#include "DIALOGS\Luis Meranda_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	PChar.storekeeper.Idx = -1;//MAXIMUS
	aref Link, Diag;
	string NPC_Meeting;
	
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
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "trade":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			PChar.storekeeper.Idx = sti(NPChar.index);//MAXIMUS
			LaunchStore(OXBAY_STORE);
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

			if (pchar.quest.Voysey_lost == "1")
			{
			if(NPChar.quest.meeting == "0")
			{
				d.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false);
				Link.l2 = DLG_TEXT[1];
				Link.l2.go = "meeting";
				NPC_Meeting = "1"; 
			}
			else
			{
				d.Text = DLG_TEXT[2];
				Link.l3 = DLG_TEXT[3];
				Link.l3.go = "exit";
			}
			}
			else 
			{
				d.Text = DLG_TEXT[4];
				Link.l4 = DLG_TEXT[5];
				Link.l4.go = "exit";
				NPC_Meeting = "0"; 
			}
		break;

		case "Meeting":
				d.Text = DLG_TEXT[6];
				Link.l1 = DLG_TEXT[7];
				Link.l1.go = "exit";
		break;
	}
}