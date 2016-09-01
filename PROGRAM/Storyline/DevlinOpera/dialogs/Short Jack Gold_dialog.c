
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	switch(Dialog.CurrentNode)
	{
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1] + GetMyFullName(Pchar);
			link.l1.go = "Exit";
			
			if (pchar.quest.Bonnie_talk == "Sailing_for_Turks")
			{
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "First_orders2";
			}

		break;

		case "First_orders2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "First_orders3";
		break;

		case "First_orders3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "First_orders4";
		break;

		case "First_orders4":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "First_orders5";
		break;

		case "First_orders5":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "First_orders6";
		break;

		case "First_orders6":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "First_orders7";
		break;

		case "First_orders7":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "First_orders8";
		break;
		
		case "First_orders8":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "First_orders9";
		break;

		case "First_orders9":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "First_orders10";
		break;

		case "First_orders10":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit_First_orders";
		break;
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Fight_Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("The Captain Arrives");
		break;

		case "ExitForWar":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("At_War_with_France_Again");
		break;		
		
		case "Exit_First_Orders":
			pchar.quest.Mings_contract = "open";
			pchar.quest.Catalina_contract = "open";
			pchar.quest.CCC_contract = "open";
			pchar.quest.Armada_contract = "open";
			pchar.quest.Merciless_contract = "open";
			pchar.quest.Maximus_contract = "open";
			pchar.quest.Petros_contract = "open";
			pchar.quest.ThomasT_contract = "open";
			pchar.quest.NathanK_contract = "open";
			pchar.quest.Bonnie_talk = "Needing_some_help";
			pchar.quest.Morgan_talk = "no_dialog";
			DialogExit();
			NextDiag.CurrentNode = "First time";
		break;
	}
}
