
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
			Dialog.snd = "voice\PADI\PADI001";

			PlaySound("VOICE\ENGLISH\Odel_who_you_are.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "2";
		break;
	
		case "2":
			PlaySound("VOICE\ENGLISH\Odel_no.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			if(IsOfficer(CharacterFromID("Hands")) || IsOfficer(CharacterFromID("Caesar")) 
			|| IsOfficer(CharacterFromID("Pell"))) 
			{
				link.l1.go = "2_A";
			}
			else link.l1.go = "3";
		break;

		case "2_A":
			PlaySound("VOICE\ENGLISH\Odel_fine.wav");
			Dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "3";
		break;

		case "3":
			PlaySound("VOICE\ENGLISH\Odel_yourself_again.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "4";
		break;

		case "4":
			PlaySound("VOICE\ENGLISH\Odel_otherwise.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "5";
		break;


		case "5":
			PlaySound("OBJECTS\DUEL\man_attack5.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "6";
		break;

		case "6":
			PlaySound("VOICE\ENGLISH\Odel_get_started.wav");
			Dialog.text = DLG_TEXT[21];
			if(!IsOfficer(CharacterFromID("Hands"))) 
			{
				link.l1 = DLG_TEXT[9];
				link.l1.go = "Hands";
			}
			link.l2 = DLG_TEXT[10];
			link.l2.go = "Richards";
			link.l3 = DLG_TEXT[11];
			link.l3.go = "Johnson";
			if(IsOfficer(CharacterFromID("Caesar"))) 
			{
				link.l4 = DLG_TEXT[38];
				link.l4.go = "Caesar";
			}
			else
			{
				link.l4 = DLG_TEXT[12];
				link.l4.go = "Caesar";
			}
		break;
		
		case "new_question":
			PlaySound("VOICE\ENGLISH\Odel_what_you_want.wav");
			Dialog.text = DLG_TEXT[15];
			if(!CheckAttribute(Pchar,"Odel_Hands") || Pchar.Odel_Hands != "done")
			{
				if(!IsOfficer(CharacterFromID("Hands"))) 
				{
					link.l1 = DLG_TEXT[9];
					link.l1.go = "Hands";
				}
			}
			if(!CheckAttribute(Pchar,"Odel_Richards") || Pchar.Odel_Richards != "done")
			{
				link.l2 = DLG_TEXT[10];
				link.l2.go = "Richards";
			}
			if(!CheckAttribute(Pchar,"Odel_Johnson") || Pchar.Odel_Johnson != "done")
			{
				link.l3 = DLG_TEXT[11];
				link.l3.go = "Johnson";
			}
			if(!CheckAttribute(Pchar,"Odel_Caesar") || Pchar.Odel_Caesar != "done")
			{
				if(IsOfficer(CharacterFromID("Caesar"))) 
				{
					link.l4 = DLG_TEXT[38];
					link.l4.go = "Caesar";
				}
				else
				{
					link.l4 = DLG_TEXT[12];
					link.l4.go = "Caesar";
				}
			}
		break;

		case "Hands":
			Pchar.Odel_Hands = "done";
			PlaySound("VOICE\ENGLISH\Odel_fine.wav");
			Dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "new_question";
		break;

		case "Richards":
			Pchar.Odel_Richards = "done";
			PlaySound("VOICE\ENGLISH\Odel_no.wav");
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "new_question";
		break;

		case "Johnson":
			Pchar.Odel_Johnson = "done";
			PlaySound("VOICE\ENGLISH\Odel_no.wav");
			Dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "new_question";
		break;

		case "Caesar":
			Pchar.Odel_Caesar = "done";
			PlaySound("VOICE\ENGLISH\Odel_very_good.wav");
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Caesar1";
		break;

		case "Caesar1":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			Dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Caesar2";
		break;

		case "Caesar2":
			PlaySound("VOICE\ENGLISH\Odel_fine.wav");
			Dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Caesar3";
		break;

		case "Caesar3":
			PlaySound("VOICE\ENGLISH\Odel_no.wav");
			Dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			AddDialogExitQuest("Teach_sloop");
		break;
	//-------------------------------------------------------
		case "end":
			PlaySound("VOICE\ENGLISH\Odel_yourself_again.wav");
			Dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "end1";
		break;

		case "end1":
			PlaySound("VOICE\ENGLISH\Odel_otherwise.wav");
			Dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "end2";
		break;

		case "end2":
			PlaySound("VOICE\ENGLISH\Odel_fine.wav");
			Dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "end3";
		break;

		case "end3":
			PlaySound("VOICE\ENGLISH\Odel_very_good.wav");
			Dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "end4";
		break;

		case "end4":
			PlaySound("VOICE\ENGLISH\Odel_no.wav");
			Dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
			AddDialogExitQuest("Odel_dialog_end_done");
		break;




		case "neutral":
			PlaySound("VOICE\ENGLISH\Odel_yourself_again.wav");
			Dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit_neutral";
		break;
		
		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "Exit_neutral":
			DialogExit();
			Diag.CurrentNode = "neutral";
		break;
	}
}
