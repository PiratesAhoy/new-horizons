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
/*
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
*/	
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

	
			Dialog.text =  "Una verdadera selva: densa vegetación, hierbas extrañas y helechos creciendo por todas partes.";

			link.l1 = "Me vendría bien algo de madera y después de despejarlo, este terreno sería un buen solar de construcción. ¡Contramaestre! ¡Reúne un grupo de leñadores! Espero que hayáis despejado este terreno para mañana. Almacenad las tablas en nuestra bodega. Y poned centinelas, puede que haya salvajes rondando por la selva.";
			if(rand(100)>50) {Link.l1.go = "Akellani";}
			else{Link.l1.go = "dismantle";}

			Link.l4 = "Un lugar perfecto para una emboscada... Será mejor salir de aquí...";
			if(rand(100)>70) {Link.l4.go = "Akellani";}
			else{Link.l4.go = "exit";}
		break;

		case "Akellani":
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }
			Ambush("natives", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			DialogExit();
		break;

		case "dismantle":
			DialogExit();
			WaitDate("", 0, 0, 1, 0, 0);
			LAi_Fade("", "");
			PlaySound("ambient\shipyard\axe.wav");
			PlaySound("ambient\shipyard\vehicle.wav");
			PlaySound("ambient\shipyard\saw.wav");
			PlaySound("ambient\shipyard\hammer.wav");

			ChangeCharacterAddress(NPChar, "none", "");
			Building_delete(lcn, nr);

			AddCharacterGoods(pchar, GOOD_PLANKS, 20 + makeint(rand(20)) );
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
