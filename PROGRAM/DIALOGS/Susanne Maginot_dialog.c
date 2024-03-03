
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
		//----------------------------------- Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";			

			Dialog.snd = "voice\SAMA\SAMA001";
			Dialog.Text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1];
			Link.l1 = pcharrepphrase(DLG_TEXT[2] + GetMyName(NPChar) + DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4], DLG_TEXT[5] + GetMyFullName(PChar) + DLG_TEXT[6] + GetMyName(PChar) + DLG_TEXT[7]);
			Link.l1.go = "exit"; 
			npchar.quest.meeting = "1";
			NextDiag.TempNode = "Second time"; 
		break;

		case "Second Time":
			Dialog.snd = "voice\SAMA\SAMA002";
			Dialog.Text = DLG_TEXT[8] + pchar.name + DLG_TEXT[9];
			if (makeint(pchar.rank) > 3)
			{
				Dialog.snd = "voice\SAMA\SAMA003";
				Dialog.text = Dialog.text + DLG_TEXT[10];
			}
			Link.l1 = pcharrepphrase(DLG_TEXT[11], DLG_TEXT[12]);
			Link.l1.go = "exit";
		break;

		case "smuggler_line":
			if (npchar.quest.meeting == "0")
			{
				dialog.text = DLG_TEXT[15];
				link.l1 = DLG_TEXT[16] + DLG_TEXT[21] + DLG_TEXT[23];
			}
			else
			{
				dialog.text = DLG_TEXT[17] + GetMyName(PChar) + DLG_TEXT[18];
				link.l1 = DLG_TEXT[19] + GetMyName(NPChar) + DLG_TEXT[20] + DLG_TEXT[21] + DLG_TEXT[22];
			}
			link.l1.go = "fourth_mission_to_marigot";
		break;

		case "fourth_mission_to_marigot":
			if (npchar.quest.meeting == "0")
			{
				dialog.text = DLG_TEXT[24] + GetMyFullName(NPChar) + DLG_TEXT[25];
				npchar.quest.meeting = "1";
			}
			else dialog.text = DLG_TEXT[26];
			if (CheckCharacterItem(pchar, "Jean_ring"))
			{
				link.l1 = DLG_TEXT[27];
				link.l1.go = "fourth_mission_ring";
			}
			link.l2 = DLG_TEXT[28];
			link.l2.go = "fourth_mission_to_Jean";
		break;

		case "fourth_mission_to_Jean":
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "exit";
			AddDialogExitQuest("fourth_mission_to_jean");
		break;

		case "fourth_mission_ring":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "fourth_mission_ring_wrong";
			link.l2 = DLG_TEXT[33];
			link.l2.go = "fourth_mission_ring_right";
		break;

		case "fourth_mission_ring_wrong":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "fourth_mission_to_Jean";
		break;

		case "fourth_mission_ring_right":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "fourth_mission_ring_right_2";
		break;

		case "fourth_mission_ring_right_2":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "fourth_mission_ring_right_3";
		break;

		case "fourth_mission_ring_right_3":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "fourth_mission_ring_right_4";
		break;

		case "fourth_mission_ring_right_4":
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "fourth_mission_ring_right_5";
		break;

		case "fourth_mission_ring_right_5":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "fourth_mission_ring_right_6";
		break;

		case "fourth_mission_ring_right_6":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "exit";
			AddDialogExitQuest("fourth_mission_capture_susanne");
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
