void ProcessDialogEvent()
{
	ref NPChar;
	
	DeleteAttribute(&Dialog,"Links");
	aref Link, NextDiag;
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		// живет в доме в локации, где находятся ларьки.
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
			link.l1.go = "exit";
			if (npchar.quest.visit == "1")
			{
				Dialog.Text = DLG_TEXT[2];
				Link.l1 = DLG_TEXT[3] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[4])]) + DLG_TEXT[5];
				Link.l1.go = "node_1";
			}
			if (npchar.quest.visit == "2")
			{
				int i = rand(1);
				if ( i == 1)
				{
					dialog.text = DLG_TEXT[6];
					link.l1 = DLG_TEXT[7];
					link.l1.go = "fight";
				}
				else
				{
					Dialog.text = DLG_TEXT[8];
					link.l1 = DLG_TEXT[9];
					link.l1.go = "paren";
				}
			}
			npchar.quest.visit = "done";
			NextDiag.tempNode = "First time";
		break;

		case "node_1":
			dialog.text = DLG_TEXT[10] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[11])]) + DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "node_2";
		break;

		case "node_2":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[16])]) + DLG_TEXT[17];
			link.l1.go = "node_3";
		break;

		case "node_3":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "node_4";
		break;

		case "node_4":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "node_5";
		break;

		case "node_5":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "node_6";
		break;

		case "node_6":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "node_7";
		break;

		case "node_7":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27] + GetMyFullName(PChar) + DLG_TEXT[28];
			link.l1.go = "node_8";
		break;

		case "node_8":
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "node_9";
		break;

		case "node_9":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "node_10";
		break;

		case "node_10":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "node_11";
		break;

		case "node_11":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "exit";
//			characters[GetCharacterIndex("Patric Cardone")].quest.teodoro = "5";
			Preprocessor_AddQuestData("Raoul Calmes", GetMyFullName(NPChar));
			if (characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers != "0")
			{
				characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers = "letters_1";
				AddQuestRecord("Patric", 7); // NK
			}
			else
			{
				characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers = "letters";
				AddQuestRecord("Patric", 8); // NK
			}
			Preprocessor_Remove("Raoul Calmes");
		break;

		case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("raoul_calmes_fight");
		break;

		case "paren":
			Dialog.text = DLG_TEXT[37] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[38])]) + DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "wrong";
			link.l2 = DLG_TEXT[41];
			link.l2.go = "right";
		break;

		case "wrong":
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "wrong_2";
		break;

		case "wrong_2":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[46];
			link.l2.go = "fight";
		break;

		case "right":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "right_1";
		break;

		case "right_1":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "right_2";
		break;

		case "right_2":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "wrong";
			link.l2 = DLG_TEXT[53];
			link.l2.go = "right_3";
		break;

		case "right_3":
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "right_4";
		break;

		case "right_4":
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "right_5";
		break;

		case "right_5":
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "right_6";
		break;

		case "right_6":
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "right_7";
		break;

		case "right_7":
			dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63] + GetMyFullName(PChar) + DLG_TEXT[64];
			link.l1.go = "right_8";
		break;

		case "right_8":
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "right_9";
		break;

		case "right_9":
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "right_10";
		break;

		case "right_10":
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers = "letters_1";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
		break;
	}
}

