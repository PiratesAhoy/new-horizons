
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];

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

			Dialog.mood = "angry";

			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Exit";
		break;

		case "First_orders":
			PlaySound("VOICE\ENGLISH\simpson01.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "First_orders2XX";
		break;

		case "First_orders2XX":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "First_orders2";
		break;

		case "First_orders2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "First_orders3";
		break;

		case "First_orders3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_First_orders";
		break;

		case "Attack_Hornblower":
			dialog.text = DLG_TEXT[8] + pchar.lastname + DLG_TEXT[12];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Exit_Attack_Hornblower";
		break;

		case "Fight_at_Charlestown":
			PlaySound("VOICE\ENGLISH\simpson01.wav");
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "Fight_at_Charlestown2";
		break;

		case "Fight_at_Charlestown2":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "Exit_Fight_at_Charlestown";
		break;

		case "Run_in_number_two":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "Exit_Run_in_number_two";
		break;

		case "Run_in_on_the_beach":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Exit_Run_in_on_the_beach";
		break;

		case "lies_and_more_lies":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "Exit_lies_and_more_lies";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "Exit_First_orders":
			pchar.quest.My_First_ship = "the captain arrives";
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Simpson_Swordfight");
		break;

		case "Exit_Attack_Hornblower":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Upstairs_room_fight");
		break;

		case "Exit_Fight_at_Charlestown":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Get_back_to_the_ship");
		break;

		case "Exit_Run_in_number_two":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Keene_interupts_Simpson");
		break;

		case "Exit_Run_in_on_the_beach":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Clayton_interupts_Simpson");
		break;

		case "Exit_lies_and_more_lies":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Bush_back_to_the_ship");
		break;
	}
}
