void ProcessDialogEvent()
{
	ref NPChar, PChar, d; 
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
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

			string crewid;
			crewid = NPChar.id;
			switch(crewid)
			{
				case "WR_beggar1": PlaySound("VOICE\ENGLISH\gr_Hgold2.wav"); break;
				case "WR_beggar2": PlaySound("VOICE\ENGLISH\gr_friday4.wav"); break;
				case "WR_beggar3": PlaySound("VOICE\ENGLISH\Beggar_01.wav"); break;
				case "WR_beggar4": PlaySound("VOICE\ENGLISH\pir_capB.wav"); break;
				case "WR_beggar5": PlaySound("VOICE\ENGLISH\gm_crew7.wav"); break;
				case "WR_beggar6": PlaySound("VOICE\ENGLISH\pir_capP.wav"); break;
				case "WR_beggar7": PlaySound("VOICE\ENGLISH\Beggar_spa.wav"); break;
				case "WR_beggar8": PlaySound("VOICE\ENGLISH\mystery_monk.wav"); break;
			}

			int iPhrase = rand(9);
			
			switch (iPhrase)
			{
				case 0:
					dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "exit";
				break;
				
				case 1:
					dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "exit";
				break;
				
				case 2:
					dialog.text = DLG_TEXT[4];
					link.l1 = DLG_TEXT[5];
					link.l1.go = "exit";
				break;
				
				case 3:
					dialog.text = DLG_TEXT[6];
					link.l1 = DLG_TEXT[7];
					link.l1.go = "exit";
				break;
				
				case 4:
					dialog.text = DLG_TEXT[8];
					link.l1 = DLG_TEXT[9];
					link.l1.go = "exit";
				break;
				
				case 5:
					dialog.text = DLG_TEXT[10];
					link.l1 = DLG_TEXT[11];
					link.l1.go = "exit";
				break;
				
				case 6:
					dialog.text = DLG_TEXT[12];
					link.l1 = DLG_TEXT[13];
					link.l1.go = "exit";
				break;
				
				case 7:
					dialog.text = DLG_TEXT[14];
					link.l1 = DLG_TEXT[15];
					link.l1.go = "exit";
				break;
				
				case 8:
					dialog.text = DLG_TEXT[16];
					link.l1 = DLG_TEXT[17];
					link.l1.go = "exit";
				break;
				
				case 9:
					dialog.text = DLG_TEXT[18];
					link.l1 = DLG_TEXT[19];
					link.l1.go = "exit";
				break;
			}

			crewid = NPChar.id;
			switch(crewid)
			{
				case "WR_beggar1": 
					if(!CheckAttribute(Pchar,"beggar1") || Pchar.beggar1 != "done")
					{ AddDialogExitQuest("are_you_Hands_delay"); }
					Pchar.beggar1 = "done";	
				break;

				case "WR_beggar2":
					if(!CheckAttribute(Pchar,"beggar2") || Pchar.beggar2 != "done")
					{ AddDialogExitQuest("are_you_Hands_delay"); }
					Pchar.beggar2 = "done";	
				break;

				case "WR_beggar3":
					if(!CheckAttribute(Pchar,"beggar3") || Pchar.beggar3 != "done")
					{ AddDialogExitQuest("are_you_Hands_delay"); }
					Pchar.beggar3 = "done";	
				break;

				case "WR_beggar4":  
					if(!CheckAttribute(Pchar,"beggar4") || Pchar.beggar4 != "done")
					{ AddDialogExitQuest("are_you_Hands_delay"); }
					Pchar.beggar4 = "done";	
				break;

				case "WR_beggar5":  
					if(!CheckAttribute(Pchar,"beggar5") || Pchar.beggar5 != "done")
					{ AddDialogExitQuest("are_you_Hands_delay"); }
					Pchar.beggar5 = "done";	
				break;

				case "WR_beggar6":  
					if(!CheckAttribute(Pchar,"beggar6") || Pchar.beggar6 != "done")
					{ AddDialogExitQuest("are_you_Hands_delay"); }
					Pchar.beggar6 = "done";	
				break;

				case "WR_beggar7":  
					if(!CheckAttribute(Pchar,"beggar7") || Pchar.beggar7 != "done")
					{ AddDialogExitQuest("are_you_Hands_delay"); }
					Pchar.beggar7 = "done";	
				break;

				case "WR_beggar8":  
					if(!CheckAttribute(Pchar,"beggar8") || Pchar.beggar8 != "done")
					{ AddDialogExitQuest("are_you_Hands_delay"); }
					Pchar.beggar8 = "done";	
				break;
			}
		break;
	
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}
