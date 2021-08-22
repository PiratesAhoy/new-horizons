// ccc Buildingset, new file	
/*
ccc Dec06:
Unlike most other files in this folder this one contains not only a textarray but code and English text merged.

The buildingset has recently been messed up by the attempt to localize my original all-English dialogfiles. 
Instead of spending weeks with fixing and testing the new files I restored my original files. 
However, the localization project has changed the structure of PotC for good : 
Upon loading a  "x-dialog.c" codefile the program now automatically includes a  "x-dialog.h" text array file from the dialogs\english subfolder(or from the Russian folder if you use that language). 
There the dialogtext is supposed to be.

However, I prefer to have code AND plain text in one file, for 3 reasons:
-It is much easier to write
-You have much less bugs with not matching texts
-It is much easier to read and understand the file for debuggers and people who would like to change it
The last point is especially important for me cause the Buildingset is supposed to be a tool for people who want to start modding.
That's why I stick to the original "code plus English text" dialogfiles.

As a concession to the localization project I put these files NOT into the \dialogs rootfolder but into the \dialogs\English subfolder.
So if you want to translate this dialog you can simply copy the "code plus English text" into the subfolder for your language and translate the English text there.
That will certainly be less work and trouble than messing up my files again. 
Not mention the work and trouble that the debuging always causes.
*/
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

	
			Dialog.text =  "A simple box, half buried in the ground. Serves as obstruction and can be boobytrapped by means of a grenade.";

			link.l1 = "That thing is just a useless nuisance. Boatswain! Clear this away. And put the planks into our store.";
			link.l1.go = "dismantle";

			if(!CheckCharacterItem(NPChar,"pistolgrenade") && CheckCharacterItem(PChar,"pistolgrenade") )
			{
					link.l21 = "Just the place for a boobytrap. A grenade with a flintlock wired to the lid will be a nice surprise for any nosey guy. And hardly anyone will resist the temptation...";
					link.l21.go = "grenade";

			}
			Link.l4 = "I'd better leave that thing alone...";
			Link.l4.go = "exit";

			link.l9 = "Hey, you there in front of the keyboard! This is a building that YOU created, so how about creating your own dialog as well? Just use Notepad to open the file program\dialogs\" + NPchar.dialog.filename + " and overwrite this text with your own. Then follow the instructions in the comments.";
			link.l9.go = "your_dialog"; //this is the case that runs if you choose the dialogoption l9. It is right below.
		
		break;
                
		case "your_dialog":
			Dialog.text = "Overwrite this with the dialogtext of the NPC." ;

			link.l1 = "Text of the player dialogoption link.l1 which ends the dialog ";
			link.l1.go = "exit";	// link l1 exits the dialog

			link.l2 = "Text of the player dialogoption link.l2 which leads to another exchange ";
			link.l2.go = "your_dialog2";	// l2 leads to the case your_dialog2
		break;	// end of case "your_dialog"
                
		case "your_dialog2":
			Dialog.text = "Overwrite this with the dialogtext of the NPC." ;

			link.l1 = "Text of the player dialogoption link.l1 which ends the dialog";
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
			TakeItemFromCharacter(pchar, "pistolgrenade" );
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
