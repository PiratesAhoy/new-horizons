//#include "DIALOGS\Rene Dutruel_dialog.h"
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
			Dialog.snd = "voice\REDU\REDU001";

			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "exit";

			if ( CheckQuestAttribute("FindMysteriousTablet","ReneDutruel_Talk") )
			{
				Dialog.snd = "voice\REDU\REDU002";
				d.Text = DLG_TEXT[2];
				Link.l1 = DLG_TEXT[3];
				Link.l1.go = "node_1";
			}
			/*if ( CheckQuestAttribute("FindMysteriousTablet","ReneDutruel_Talk2") )
			{
				d.Text = "Вот эта девчонка, которая разнюхивала информацию о сокровищах";
				Link.l1 = "Ах ты мерзавец. Ты сдал меня этим уродам, ну держись.";
				Link.l1.go = "exit";
			}*/
			if ( CheckQuestAttribute("FindMysteriousTablet","ReneDutruelGiveNotes") )
			{
				Dialog.snd = "voice\REDU\REDU003";
				d.Text = DLG_TEXT[4];
				Link.l1 = DLG_TEXT[5];
				Link.l1.go = "node_3";
			}
		break;

		case "node_1":
			Dialog.snd = "voice\REDU\REDU004";
			d.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "node_2";
		break;

		case "node_2":
			Dialog.snd = "voice\REDU\REDU005";
			d.Text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "exit";
			PChar.quest.FindMysteriousTablet = "ReneDutruel_Talk2";
		break;

		case "node_3":
			Dialog.snd = "voice\REDU\REDU006";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			GiveItem2Character(PChar,"legend_notes");
		break;
	}
}
