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
			link.l1.go = "Exit";
		break;

		case "soldier":
			if (PChar.model == "Ardent_S")
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3] + GetMyFullName(Characters[GetCharacterIndex("Havana Prison Commandant")])+".";
				link.l1.go = "soldier2";
			}
			else
			{
				logit(TranslateString("","HINT: The captain will be more willing to talk to someone who looks like a soldier."));
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				AddDialogExitQuest("tavern_for_payroll2");
				link.l1.go = "Exit";
			}
		break;

		case "soldier2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			PChar.quest.payroll_ship_known = "yes";
			AddDialogExitQuest("tavern_for_payroll2");
			link.l1.go = "Exit";
		break;

		case "senorita":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "senorita2";
		break;

		case "senorita2":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "senorita3";
		break;

		case "senorita3":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			PChar.quest.payroll_ship_known = "yes";
			AddDialogExitQuest("tavern_for_payroll2");
			link.l1.go = "exit";
		break;

	}
}