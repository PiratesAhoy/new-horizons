// ccc Buildingset, new file

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
	ref lcn = &Locations[FindLocation(PChar.location)];

	string nr = NPChar.lastname;

	string buildingstr = NPChar.equip.blade;
	aref buildingref;
	Items_FindItem(buildingstr,&buildingref);

	string interiorstr = "simple furniture";
	if(CheckAttribute(Npchar,"equip.gun"))
	{
	interiorstr = NPChar.equip.gun;
	aref interiorref;
	Items_FindItem(interiorstr,&interiorref);
	}

	int planks = 0;
	int money = 0;
	int crew = 0;
	
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

	
			Dialog.text = DLG_TEXT[0];

			link.l1 = DLG_TEXT[1];
			link.l1.go = "dismantle";

			if(!CheckCharacterItem(NPChar,"pistolgrenade") && CheckCharacterItem(PChar,"pistolgrenade"))
			{
					link.l21 = DLG_TEXT[2];
					link.l21.go = "grenade";

			}
			Link.l4 = DLG_TEXT[3];
			Link.l4.go = "exit";

			link.l9 = DLG_TEXT[4] + NPchar.dialog.filename + DLG_TEXT[5];
			link.l9.go = "your_dialog"; // this is the case that runs if you choose the dialogoption l9. It is right below.
		
		break;
                
		case "your_dialog":
			Dialog.text = DLG_TEXT[6];

			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";	// link l1 exits the dialog

			link.l2 = DLG_TEXT[8];
			link.l2.go = "your_dialog2";	// l2 leads to the case your_dialog2
		break;	// end of case "your_dialog"
                
		case "your_dialog2":
			Dialog.text = DLG_TEXT[6];

			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";	// link l1 exits the dialog

			// Here are some codelines that give you gold, items, goods or experience. To activate them delete the comment slashes '//' in front of the code. You can change the amounts to your liking.

			// AddMoneyToCharacter(Pchar, 1000);

			// GiveItem2Character(Pchar, "Spyglass3");
			// GiveItem2Character(Pchar, "Jewelry5");
			// GiveItem2Character(Pchar, "Mineral3");
			// TakenItems(Pchar, "potion1", 3);

 			// AddCharacterGoods(pchar, GOOD_SANDAL, 10 );
			// AddCharacterGoods(pchar, GOOD_SILK, 10 );
			// AddCharacterGoods(pchar, GOOD_RUM, 20 );
			// AddCharacterGoods(pchar, GOOD_WHEAT, 20 );

			// AddPartyExp(PChar, 100 );


		break;	// end of case "your_dialog2"

                
		case "grenade":
			TakeItemFromCharacter(pchar, "pistolgrenade");
			GiveItem2Character(NPchar, "pistolgrenade");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "dismantle":
			DialogExit();
			planks += sti(buildingref.building.planks);
			crew += sti(buildingref.building.crew);

			if(CheckAttribute(Npchar,"equip.gun"))
			{
				planks += sti(interiorref.building.planks);
				crew += sti(interiorref.building.crew);
			}
			AddCharacterGoods(pchar, GOOD_PLANKS, planks);
			AddCharacterCrew(pchar, crew);   // ccc mar06
			Lai_KillCharacter(npchar);
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}