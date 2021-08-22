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

		case "exit_avoid_delay":
			PChar.quest.colombian_silver.status = "arrest_outside";
			Diag.CurrentNode = Diag.TempNode;
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

			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false));
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
			if (CheckQuestAttribute("colombian_silver.status", "start") || CheckQuestAttribute("colombian_silver.status", "talked_to_tavernkeeper"))
			{
				if(sti(PChar.money) >= 2)
				{
					link.l2 = DLG_TEXT[2];
					link.l2.go = "join_me";
				}
			}
		break;

		case "join_me":
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			AddDialogExitQuest("colombian_silver_join_officer");
			link.l1.go = "exit";
		break;

		case "generous":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "set_trap";
		break;

		case "set_trap":
			PChar.quest.colombian_silver.status = "arrest_inside";
			dialog.text = DLG_TEXT[7];
			AddDialogExitQuest("colombian_silver_tavern2_soldier_leaves");
			link.l1 = DLG_TEXT[8];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[9];
			link.l2.go = "exit_avoid_delay";
		break;

		case "delay_for_squad":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "delay_for_squad2";
		break;

		case "delay_for_squad2":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			AddDialogExitQuest("colombian_silver_arrest_inside");
			link.l1.go = "exit";
		break;
	}
}