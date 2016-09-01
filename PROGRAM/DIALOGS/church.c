void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	string iDay, iMonth, cargoid;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;
	
	switch(Dialog.CurrentNode)
	{
		//Levis find telescope -->
		case "donation paid_5000":
			if(!CheckAttribute(PChar,"quest.telescope_quest.church") && !CheckAttribute(PChar,"quest.telescope_quest.returned_cross")) 		// Didn't start the search nor finish it
			{
				dialog.Text = dialog.Text + DLG_TEXT[3];
				Link.l1 = DLG_TEXT[4];
				Link.l1.go = "start telescope";
			}
		break;
		
		case "donation paid_2500":
			if(!CheckAttribute(PChar,"quest.telescope_quest.church") && !CheckAttribute(PChar,"quest.telescope_quest.returned_cross")) 		// Didn't start the search nor finish it
			{
				dialog.Text = dialog.Text + DLG_TEXT[3];
				Link.l1 = DLG_TEXT[4];
				Link.l1.go = "start telescope";
			}
		break;
		
		case "donation paid_500":
			if(!CheckAttribute(PChar,"quest.telescope_quest.church") && !CheckAttribute(PChar,"quest.telescope_quest.returned_cross"))		// Didn't start the search nor finish it
			{
				dialog.Text = dialog.Text + DLG_TEXT[3];
				Link.l1 = DLG_TEXT[4];
				Link.l1.go = "start telescope";
			}
		break;
		
		case "First time":
			if(!CheckAttribute(PChar,"quest.telescope_quest.finished"))																		// Quest not yet finished
			{
				if(CheckAttribute(PChar,"quest.telescope_quest.church") && !CheckAttribute(PChar,"quest.telescope_quest.returned_cross"))	// Started the search, but did not finish it
				{
					if(GetAttribute(pchar, "quest.telescope_quest.church") == pchar.location)												// Right location
					{
						if (CheckCharacterItem(Pchar,"jewelry9"))																			// Have the item
						{
							Link.l1 = DLG_TEXT[12];
							Link.l1.go = "bring cross";
						}
					}
				}
				if(CheckAttribute(PChar,"quest.telescope_quest.foundbook"))																	// Found the book
				{
					Link.l2 = DLG_TEXT[0];
					if(CheckAttribute(PChar,"quest.telescope_quest.returned_cross"))														// Already given the cross and received the telescope
					{
						Link.l2.go = "get explanation";
					}
					else																													// Still need to find the telescope
					{
						Link.l2.go = "donate first";
					}
				}
			}
		break;
		
		case "donate first":
			dialog.Text = DLG_TEXT[1];
			Link.l1 = DLG_TEXT[2];
			Link.l1.go = "donation";
		break;
		
		case "start telescope":
			dialog.Text = DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "next telescope";
		break;
		
		case "next telescope":
			dialog.Text = DLG_TEXT[7];
			Link.l1 = DLG_TEXT[8];
			Link.l1.go = "accept fetch";
			Link.l2 = DLG_TEXT[9];
			Link.l2.go = "exit";
		break;
		
		case "accept fetch":
			dialog.Text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "exit";
			AddDialogExitQuest("telescope agreed fetch");
		break;
		
		case "bring cross":
			TakeItemFromCharacter(Pchar,"jewelry9");
			pchar.quest.telescope_quest.returned_cross = true;																				// PB: Mark this as completed!
			dialog.Text = DLG_TEXT[13];
			if(CheckAttribute(PChar,"quest.telescope_quest.foundbook"))																		// Just returned the cross and already found the book
			{
				Link.l1 = DLG_TEXT[18];
				Link.l1.go = "get explanation";																								// Finish quest
			}
			else
			{
				Link.l1 = DLG_TEXT[14];
				Link.l1.go = "info location";																								// Start search for book
			}
			GiveItem2Character(pchar, "telescope");																							// Give the telescope
		break;
		
		case "info location":
			dialog.Text = DLG_TEXT[15] + FindTownName("Greenford") + DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17];
			Link.l1.go = "exit";
			AddDialogExitQuest("telescope find book");
		break;
		
		case "get explanation":
			dialog.Text = DLG_TEXT[19];
			Link.l1 = DLG_TEXT[20];
			Link.l1.go = "exit";
			AddDialogExitQuest("telescope finish");
		break;
		
		//Levis find telescope <--
	}
}