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
			dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[2];		// changed from .spa to .por by KAM
			link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4];
			link.l1.go = "node_1";
		break;

		case "node_1":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "node_2";
		break;

		case "node_2":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "exit";
		break;

		case "arrest":
			PChar.quest.imperial_escort.guards_join_guzman = false;
			dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[2];
			link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[9] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[10];
			link.l1.go = "arrest2";
		break;

		case "arrest2":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[14] + GetMyFullName(CharacterFromID("Jaime Lezcano")) + DLG_TEXT[16] + GetMyFullName(CharacterFromID("Jusepe Guimaraes")) + DLG_TEXT[17];
			link.l1.go = "finest_swordsman";
		break;

		case "revenge":
			PChar.quest.imperial_escort.guards_join_guzman = true;
			dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[2];
			link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[9] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[11];
			link.l1.go = "revenge2";
		break;

		case "revenge2":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14] + GetMyFullName(CharacterFromID("Jaime Lezcano")) + DLG_TEXT[15];
			link.l1.go = "finest_swordsman";
		break;

		case "finest_swordsman":
			dialog.text = DLG_TEXT[18] + GetRankName(PChar, sti(NPChar.nation)) + DLG_TEXT[19];
			if (PChar.sex == "woman")
			{
				link.l1 = DLG_TEXT[21];
				link.l1.go = "technicality";
			}
			else
			{
				link.l1 = DLG_TEXT[20];
				link.l1.go = "your_loss";
			}
			link.l2 = DLG_TEXT[22];
			link.l2.go = "fencers";
		break;

		case "your_loss":
			dialog.text = DLG_TEXT[23] + DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			AddDialogExitQuest("imperial_escort_fight_guzman");
			link.l1.go = "exit";
		break;

		case "technicality":
			dialog.text = DLG_TEXT[24] + DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			AddDialogExitQuest("imperial_escort_fight_guzman");
			link.l1.go = "exit";
		break;

		case "fencers":
			dialog.text = DLG_TEXT[25] + "\n" + DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			AddDialogExitQuest("imperial_escort_fight_guzman");
			link.l1.go = "exit";
		break;


	}
}