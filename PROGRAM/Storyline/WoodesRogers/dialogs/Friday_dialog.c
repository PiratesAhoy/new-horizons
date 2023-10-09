
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

			PlaySound("VOICE\ENGLISH\gr_Friday3.wav");

			if(CheckAttribute(Pchar,"quest.med_Friday") && Pchar.quest.med_Friday == "medicine")
			{
				RemoveCharacterEquip(NPchar, GUN_ITEM_TYPE);
				TakeNItems(NPChar, "pistolrock", -2);
				RemoveCharacterEquip(NPchar, BLADE_ITEM_TYPE);
				TakeItemFromCharacter(NPchar, "bladeaxe1");
		
				if(CheckCharacterItem(Pchar,"medicine_leaves"))
				{					
					ChangeCharacterAddressGroup(characterFromID("Selkirk"), "wr_booty", "goto", "goto6");
					LAi_SetStayType(CharacterFromID("Selkirk"));
					SetLocatorRadius(locations[FindLocation(Pchar.location)], "goto", "goto6", 1.7);
				}

				Dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "cannabis";
			}
			else
			{
				Dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}

			Diag.TempNode = "First time";
		break;

		case "cannabis":
			DialogExit();
			Diag.TempNode = "First time";
			
			AddMoneyToCharacter(NPChar,-10000);
			LaunchCharacterItemChange(NPChar);
		break;
	
		case "erotica":
			PlaySound("VOICE\ENGLISH\gr_friday2.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			AddDialogExitQuest("friday_erotica1_A");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
