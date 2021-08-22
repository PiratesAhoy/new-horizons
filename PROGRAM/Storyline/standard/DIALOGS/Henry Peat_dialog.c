//#include "DIALOGS\Henry Peat_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	Preprocessor_Add("lad", GetMyAddressForm(NPChar, PChar, ADDR_INFORMAL, false, false)); // DeathDaisy
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;


		case "First time":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";


			Pchar.quest.Carpenter.win_condition.l1 = "location";
			Pchar.quest.Carpenter.win_condition.l1.character = "Blaze";
			Pchar.quest.Carpenter.win_condition.l1.location = "Falaise_de_fleur_port_01";
			Pchar.quest.Carpenter.win_condition = "about_ruby";

			Pchar.quest.Carpenter1.win_condition.l1 = "location";
			Pchar.quest.Carpenter1.win_condition.l1.character = "Blaze";
			Pchar.quest.Carpenter1.win_condition.l1.location = "Falaise_de_fleur_Jungle";
			Pchar.quest.Carpenter1.win_condition = "about_ruby";
			
			Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy

			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "meeting";		
		break;

		case "Meeting":
			d.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "continue";
		break;

		case "continue":
			d.Text = DLG_TEXT[4];
			Link.l99 = DLG_TEXT[5];
			Link.l99.go = "continue1";
		break;

		case "continue1":
			d.Text = DLG_TEXT[6];
			Link.l99 = DLG_TEXT[7];
			Link.l99.go = "continue2";
		break;

		case "continue2":
			d.Text = DLG_TEXT[8];
			Link.l99 = DLG_TEXT[9];
			Link.l99.go = "continue3";
		break;

		case "continue3":
			AddDialogExitQuest("Story_CursedCoinsPeatSilent")
			d.Text = DLG_TEXT[10];
			Link.l99 = DLG_TEXT[11];
			Link.l99.go = "exit";
		break;
	}
}