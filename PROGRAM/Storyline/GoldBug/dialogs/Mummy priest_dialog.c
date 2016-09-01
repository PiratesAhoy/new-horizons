
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

			if(CheckCharacterItem(Pchar,"knitting_basket") || CheckCharacterItem(Pchar,"knitting") || CheckCharacterItem(Pchar,"yarn")
			|| CheckCharacterItem(Pchar,"needles") || CheckCharacterItem(Pchar,"needles2") || CheckCharacterItem(Pchar,"magnet2"))
			{
				if(CheckCharacterItem(Pchar,"book61A") || CheckCharacterItem(Pchar,"book61B") || CheckCharacterItem(Pchar,"book61C1")
				|| CheckCharacterItem(Pchar,"book61C2") || CheckCharacterItem(Pchar,"book61D"))
				{
					if(CheckCharacterItem(Pchar,"key22"))
					{
						//no more hints
					}		
					else
					{
						//hint key
						PlaySound("AMBIENT\CRYPT\daemon2.wav");
						Dialog.text = DLG_TEXT[0];
						link.l1 = DLG_TEXT[1];
						link.l1.go = "exit";
						AddDialogExitQuest("Poe_ooh");
					}
				}		
				else
				{
					//hint altar
					PlaySound("AMBIENT\CRYPT\daemon1.wav");
					Dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "exit";
					AddDialogExitQuest("Poe_look");
				}
			}
			else
			{
				//hint basket
				PlaySound("AMBIENT\CRYPT\background.wav");
				Dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "exit";
				AddDialogExitQuest("Poe_and");
			}

			Diag.TempNode = "First time";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "sit", "sit13");

			LAi_QuestDelay("leave_confessional_box", 1.0);
		break;
	}
}
