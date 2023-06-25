
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
			Dialog.snd = "voice\PADI\PADI001";
	
			if(CheckAttribute(Pchar,"quest.Poe_home") && Pchar.quest.Poe_home == "yes")
			{
				PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
				Dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}
			else
			{
				if(CheckAttribute(Pchar,"quest.Poe_home") && Pchar.quest.Poe_home == "private")
				{
					PlaySound("VOICE\ENGLISH\Fre_f_a_013.wav");
					Dialog.text = DLG_TEXT[4];
					link.l1 = DLG_TEXT[5];
					link.l1.go = "exit";
				}
			}
			else
			{
				PlaySound("VOICE\ENGLISH\Fre_f_a_002.wav");
				Dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit";
			}

			Diag.TempNode = "First time";
		break;
	
		case "Exit":
			LAi_SetStayType(NPChar);
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
