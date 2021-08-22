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
	
	string natname = GetNationNameByType(sti(npchar.nation));

	switch(natname)
	{
	case "portugal":
		PlayStereoSound("voice\ENGLISH\por_m_a_038.wav");
		break;

	case "holland":
		PlayStereoSound("voice\ENGLISH\dut_m_a_040.wav");
		break;

	case "britain":
		PlayStereoSound("voice\ENGLISH\eng_m_a_051.wav");
		break;

	case "france":
		PlayStereoSound("voice\ENGLISH\fre_m_a_042.wav");
		break;

	case "spain":
		PlayStereoSound("voice\ENGLISH\spa_m_a_039.wav");
		break;
	}

	npchar.bribe = (sti(pchar.skill.fencing)+sti(pchar.skill.leadership)+sti(pchar.skill.accuracy))*1000;
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
		dialog.text = "Ah, my dearest "+ GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname +  "! Finally do I meet in person the hero whom I have heard of so often! Only the most favourable tales, of course. Word of your heroic deeds reached the highest circles at the court of " + natname + ", which were so impressed by your character that even " + GetNationRoyalByType(sti(npchar.nation)) + " expressed His desire to overcome the.. err.. little misunderstandings that have.. err.. cast a shadow on the relationship between " + natname + " and you. So let's forget the past and sail into a bright common future. If you are willing to fight for our proud -and generous- nation we'll grant you an amnesty and a Royal Letter of Marquee. And in consideration of your leadership and fighting SKILLS we even offer you a sum of " + npchar.bribe + " Gold!";

		if(sti(pchar.money)>sti(npchar.bribe))
		{
			link.l1 = "What? You think you can buy me? Who do you think I am? I don't need your dirty bribemoney, I scorn such petty sums. Here, take " + npchar.bribe + " Goldpieces from ME, take them to your Majesty and tell him to shove them up his royal arse. I am sure you'll find a diplomatic way to do that, eh? And now get out of my eyes!";
			link.l1.go = "exit_reput";
		}

		link.l2 = "What? You think you can buy me? Who do you think I am? A traitor? A gun for hire? Well, you have come to the right " + XI_ConvertString(PChar.sex) + " then. Thanks a lot for the money, and kind regards to " + GetNationRoyalByType(sti(npchar.nation)) + ". Tell him I'll sink some ships especially for him. Goodbye.";
		link.l2.go = "exit_change";

		link.l3 = "Umm, I'm afraid that my current employ.. err.. my beloved mothercountry, I mean, won't be pleased if I switch sides. And I can't afford to have " + GetNationNameByType(GetServedNation()) + " as enemy. And I have to think of my reputation as well. So no deal today, sorry. ";
		link.l3.go = "exit";
		break;


	case "exit":
		LAi_SetActorType(NPchar);
		LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		break;

	case "exit_reput":
		PlayStereoSound("INTERFACE\took_item.wav");
		AddMoneyToCharacter(pchar, -sti(npchar.bribe));
		ChangeCharacterReputation(pchar, 3);
		if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", sti(npchar.bribe)/10/2 ); AddPartyExpChar(PChar, "Sneak", sti(npchar.bribe)/10/2 ); }
		else { AddPartyExp(PChar, sti(npchar.bribe)/10 ); }

		LAi_SetActorType(NPchar);
		LAi_ActorRunToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		break;

	case "exit_change":

		switch(natname)
		{
		case "portugal":
			PlayStereoSound("voice\ENGLISH\por_m_a_038.wav");
			break;

		case "holland":
			PlayStereoSound("voice\ENGLISH\dut_m_a_040.wav");
			break;

		case "britain":
			PlayStereoSound("voice\ENGLISH\eng_m_a_051.wav");
			break;

		case "france":
			PlayStereoSound("voice\ENGLISH\fre_m_a_042.wav");
			break;

		case "spain":
			PlayStereoSound("voice\ENGLISH\spa_m_a_039.wav");
			break;
		}

		SetRelationsAsNation(Npchar.nation); // ccc Dec 06
		ReceiveLetterOfMarque(Npchar.nation);

		PlayStereoSound("INTERFACE\took_item.wav");
		AddMoneyToCharacter(pchar, sti(npchar.bribe));
		ChangeCharacterReputation(pchar, -6);
		if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", sti(npchar.bribe)/10/2 ); AddPartyExpChar(PChar, "Sneak", sti(npchar.bribe)/10/2 ); }
		else { AddPartyExp(PChar, sti(npchar.bribe)/10 ); }

		LAi_SetActorType(NPchar);
		LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		break;

	}
}
