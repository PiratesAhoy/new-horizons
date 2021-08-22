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
			NextDiag.TempNode = "first time";
			dialog.text = "Now, young " + GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false) + ", whose rash voice resonates in these so venerable vaults, state your desire with the manners of a noble " + GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false) + ", or let silence rule o'er ancient walls once more. Walls, once hung with tapestries of silk and velvet, once seeing regal feasts and regal battles.. and regal treachery and murder! Now silence is this ruin's royalty, these cold stone's only veil, for cent'ries past, and cent'ries come. Silence of peace? Silence of death? Which it shall be for you is not yet written in the scriptures.";
			link.l1 = "Huh? Wha.. I didn't hear any door.. Where do you come from so suddenly and stealthy?";
			link.l1.go = "help_2";
			link.l4 = "So you are supposed to be the famous guardian of treasures? How can I be sure that you don't embezzle my stuff, eh?";
			link.l4.go = "help_3";
			link.l2 = "(Darned, where is my 'Shakespeare for Elemantary School'? Ah, here..) Ehem.. Here I stand, humbled in the face of age and wisdom, wishing to entrust you, treasured trustee, my humble trove, though knowing it amounts to nought before these eyes and stones which witnessed so much greater treasure. And so much greater men!";
			link.l2.go = "items";
			link.l3 = "Oh, please, can't we just get down to the safekeeping business?";
			link.l3.go = "items1";
		break;

		case "help_2":
			dialog.text = "Who else but me, haunting these ancient walls so long as to resemble mortar holding stone and stone together, brittle, yes, but still standing upright and proud, who else should better know the hidden ways that men now long forgotten build here once, a vain attempt to hide their wicked ways. Vain as all their wickedness, alas, did nothing to avert their fatal fate. Their fate, will it be yours as well? Who knows that now? Who'll know when hit it will? Who will know, once it has hit, of you? No one, nevermore!";
			link.l1 = "Oh so right you are, o Olde Keeper, out of dust we become only to become dust once again! But what we in between achieve is what makes us men or mice. To be rich and famous, or not to be at all, THAT is the question. ";
			link.l1.go = "items";
		break;

		case "help_3":
			dialog.text = "Don't you, knave, question my blood's hounour! My house served kings and counts and barons for cent'ries without fail. One of my blood kept Lionheart's ransom, and not a copper spent but for his liege lords freedom. One of my blood, Londinum's royal Tower's keeper when the Third Richard kept in chains his very brother's sons, could not condone the cruel crime his oath of office forced him to partake in. But rather than betray his master, depraved as he might be, he chose to end his life in honour. But not before performing the sad act sealing the poor princelings' fate. A heinous act, for sure, and hurting my forefather's soul as much as his poor victims' bodies. But always did he hold his duty higher than his welfare, than his salvation even, yes! And so will I, as long as I can breathe!";
			link.l1 = "So save your breathe then, most faithful Keeper, as to be so much the longer able to perform your burd'ning duty. As for the knavish kings and barons, the plague on all their houses!";
			link.l1.go = "items";
		break;

		case "items":
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Sneak", 100 ); }
			else { AddPartyExp(PChar, 100 ); }
			WaitDate("", 0, 0, 0, 2, 0);
			dialog.text = "How dare you, yokel! Don't you mock The Bard, mimicking words of beauty with stumbling a tongue, sooting the sooth of his venerable verse with vain wit! Here, hear his true text, truant, and may his very words win you a hundred cents of wisdom! (Keeper recites Hamlet... for two hours) But halt, enough of idle words, time is out of joint already! Now will I open the Domesday Book of what your wicked designs and vainglorious schemes won you?";
			link.l1 = "Err.. yes, PLEASE! All's well that ends well, eh?";
			link.l1.go = "items1";
		break;

		case "items1":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LaunchCharacterItemChange(NPChar);

			ChangeCharacterAddress(NPChar, "none", "");
			Logit("The Keeper disappears without word or sound, as if the ancient walls swallowed him...")
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			ChangeCharacterAddress(NPChar, "none", "");
			Logit("The Keeper disappears without word or sound, as if the ancient walls had swallowed him...")
		break;
	}
}
