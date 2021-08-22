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

			dialog.snd = "Voice\ARGU\ARGU001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";

			Dialog.mood = "normal";

			if(checkquestattribute("Jacks_early_days", "And_now_Konrad"))
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];			
				link.l1.go = "Exit_for_choice";
			}
		break;

		case "Exit_for_choice":
			pchar.quest.Jacks_early_days = "Second_time_Petros";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Petros_talk_two");
		break;

		case "Stratergy_talk":
			dialog.text = DLG_TEXT[4] + getmyname(pchar);
			link.l1 = DLG_TEXT[5];			
			link.l1.go = "Exit_for_Petros3";
		break;
	
		case "Exit_for_Petros3":
			pchar.quest.Jacks_early_days = "Third_time_Petros";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("KK_and_Willemous_leave");
		break;

		case "Unfolding_the_Wicked_Wench_plan":
			dialog.text = DLG_TEXT[6] + getmyname(pchar) + DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];			
			link.l1.go = "Unfolding_the_Wicked_Wench_plan2";
		break;

		case "Unfolding_the_Wicked_Wench_plan2":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];			
			link.l1.go = "Unfolding_the_Wicked_Wench_plan3";
		break;

		case "Unfolding_the_Wicked_Wench_plan3":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];			
			link.l1.go = "Unfolding_the_Wicked_Wench_plan4";
		break;
		
		case "Unfolding_the_Wicked_Wench_plan4":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];			
			link.l1.go = "Unfolding_the_Wicked_Wench_plan5";
		break;		

		case "Unfolding_the_Wicked_Wench_plan5":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];			
			link.l1.go = "Unfolding_the_Wicked_Wench_plan6";
		break;

		case "Unfolding_the_Wicked_Wench_plan6":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];			
			link.l1.go = "Unfolding_the_Wicked_Wench_plan7";
		break;

		case "Unfolding_the_Wicked_Wench_plan7":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];			
			link.l1.go = "Unfolding_the_Wicked_Wench_plan8";
		break;

		case "Unfolding_the_Wicked_Wench_plan8":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];			
			link.l1.go = "Unfolding_the_Wicked_Wench_plan9";
		break;

		case "Unfolding_the_Wicked_Wench_plan9":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];			
			link.l1.go = "Exit_Wicked_Wench_plan4";
		break;

		case "Exit_Wicked_Wench_plan4":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("And_now_the_other_option");
		break;
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
