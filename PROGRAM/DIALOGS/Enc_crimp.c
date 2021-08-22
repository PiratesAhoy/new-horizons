// ccc Dialog for crimp you meet in inn 

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	int NPC_Meeting;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];	// determines where you are
	Npchar.crimpgold = GetMaxCrewQuantity(pchar)*10;

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

			dialog.text = DLG_TEXT[0];

			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "leadership";

			Link.l2 = DLG_TEXT[2];
			Link.l2.go = "fencing";

			Link.l3 = DLG_TEXT[3];
			Link.l3.go = "sailing";

			Link.l5 = DLG_TEXT[4] + Npchar.crimpgold + DLG_TEXT[5];
			Link.l5.go = "purse";

			Link.l4 = DLG_TEXT[6];
			Link.l4.go = "exit";
		break;

		case "leadership":
			Npchar.crimp = sti(pchar.skill.leadership)*10;
			dialog.text = DLG_TEXT[7] + Npchar.crimp + DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "Exit_crew";
			Link.l4 = DLG_TEXT[10];
			Link.l4.go = "exit";
		break;

		case "Fencing":
			Npchar.crimp = sti(pchar.skill.Fencing)*5;
			dialog.text = DLG_TEXT[7] + Npchar.crimp + DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "Exit_crew";
			Link.l4 = DLG_TEXT[10];
			Link.l4.go = "exit";
		break;

		case "sailing":
			Npchar.crimp = sti(pchar.skill.sailing)*7;
			dialog.text = DLG_TEXT[7] + Npchar.crimp + DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "Exit_crew";
			Link.l4 = DLG_TEXT[10];
			Link.l4.go = "exit";
		break;

		case "purse":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -sti(Npchar.crimpgold) );
			if (rand(100)<70)
			{
			dialog.text = Npchar.crimpgold + DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "exit_crew_full";
			}
			else
			{
			AddMoneyToCharacter(Npchar, sti(Npchar.crimpgold));
			dialog.text = Npchar.crimpgold + DLG_TEXT[13];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "Exit_run";
			}
		break;

		case "Exit_crew":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -100);
			AddCharacterCrew(pchar, sti(Npchar.crimp));
			LAi_SetActorType(NPchar);
			LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
			DialogExit();
		break;

		case "exit_crew_full":
			SetCrewQuantity(&pchar, GetMaxCrewQuantity(&pchar));
			LAi_SetActorType(NPchar);
			LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
			DialogExit();
		break;

		case "Exit_run":
			LAi_SetActorType(NPchar);
			LAi_ActorRunToLocation(NPchar, "reload", "reload1", "none", "", "", "", 25.0);
			DialogExit();
		break;

		case "exit":
			LAi_SetActorType(NPchar);
			LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
			DialogExit();
		break;
	}
}

// ccc <--
