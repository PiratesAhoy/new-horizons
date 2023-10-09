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
		// -----------------------------------Диалог первый - первая встреча
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

			if(checkquestattribute("Smuggler", "With_Smugglers_To_Tortuga"))
			{
				dialog.text = DLG_TEXT[12];
				link.l1 = DLG_TEXT[13] + GetMyFullName(Pchar) + DLG_TEXT[14];
				link.l1.go = "Smuggler Talk2";
			}
			if(checkquestattribute("Beckett", "Smugglers_Arrived_Tortuga"))
			{
				dialog.text = DLG_TEXT[19];
				link.l1 = DLG_TEXT[20];
				link.l1.go = "Exit Smuggler Tortuga";
			}
			else{
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "Exit";
			}
		break;

		case "inprison_blackpearlattack":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Jail Talk";
		break;

		case "Jail Talk":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Exit Jail Talk";
		break;

		case "Exit Jail Talk":
			ChangeCharacterAddress(characterFromID("Eng_soldier_5"), "none", "");
			AddDialogExitQuest("waiting_for_Turner");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Smuggler Talk":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13] + GetMyFullName(PChar) + DLG_TEXT[14];
			link.l1.go = "Smuggler Talk2";
		break;

		case "Smuggler Talk2":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "Smuggler Talk3";
		break;

		case "Smuggler Talk3":
			GiveItem2character(PChar, "blade1");
			EquipCharacterByItem(pchar, "blade1");
			//AddQuestRecord("Hector Barbossa",5);
			AddQuestRecord("Stolen", 3);
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "Exit"; //"Exit Smuggler Talk";
		break;

		case "Exit Smuggler Tortuga":
			RemovePassenger(pchar, characterFromID("quest_smuggler_01"));
			RemoveCharacterCompanion(pchar, characterFromID("quest_smuggler_01"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("quest_smuggler_01"));
			if (GetAttribute(pchar, "Chevalle") == "Mutiny")
			{
				AddDialogExitQuest("Tortuga_Get_ready_for_Film1");
			}
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "under arrest":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "under arrest2";
		break;

		case "under arrest2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "under arrest3";
		break;

		case "under arrest3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit under arrest";
		break;

		case "Kill_the_EITC_Sparrow":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "Kill_the_EITC_Sparrow2";
		break;

		case "Kill_the_EITC_Sparrow2":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "Exit_Kill_the_EITC_Sparrow";
		break;

		case "the Hanging":
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "Exit_the_Hanging";
		break;

		case "Exit_the_Hanging":
			AddDialogExitQuest("hung at dawn");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit under arrest":
			AddDialogExitQuest("into_position_Cayman2");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_Kill_the_EITC_Sparrow":
			AddDialogExitQuest("Muelle_plan_of_action3");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "opening_scene":
			Change_Mood("angry");
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "Exit_opening";
		break;

		case "Exit_opening":
			Change_Mood("normal");
			AddDialogExitQuest("Sparrow_reload");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
