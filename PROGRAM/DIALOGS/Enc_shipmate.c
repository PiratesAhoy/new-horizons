// ccc Dialog for 'old shipmate' officer that you meet in inns 

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

			if (rand(100)<25)
			{
				dialog.text = LinkRandPhrase(DLG_TEXT[0] + pchar.lastname + DLG_TEXT[1], pchar.lastname + DLG_TEXT[2], DLG_TEXT[3] + pchar.lastname + DLG_TEXT[4]) ;
 				link.l1 = RandSwear() + " " + LinkRandPhrase(DLG_TEXT[5], DLG_TEXT[6], DLG_TEXT[7]);
				link.l1.go = "exit_fight";
			}
			else
			{
			dialog.text = LinkRandPhrase(DLG_TEXT[0] + GetMyName(Pchar) + DLG_TEXT[8], GetMyName(PChar) + DLG_TEXT[9], DLG_TEXT[10] + GetMyName(Pchar) + DLG_TEXT[11]) ;
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "officer";
			Link.l2 = DLG_TEXT[13];
			Link.l2.go = "fight";
			Link.l3 = LinkRandPhrase(DLG_TEXT[14], DLG_TEXT[15], DLG_TEXT[16]);
			Link.l3.go = "exit";
			}
		break;

		case "fight":
			dialog.text =  RandSwear() + DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "exit_fight";
			ChangeCharacterReputation(pchar, 3);
		break;

		case "clerk":
			dialog.text = DLG_TEXT[19];
			Link.l1 = DLG_TEXT[20];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[21];
			Link.l2.go = "purse";

		break;

		case "officer":
			ChangeCharacterReputation(pchar, -3);
			dialog.text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[23];
			Link.l1.go = "exit";

			if(sti(GetStorylineVar(FindCurrentStoryline(), "NO_CREW_OR_OFFICERS")) < 1 && !CheckAttribute(PChar, "isnotcaptain"))
			{
				Link.l3 = DLG_TEXT[24];
				Link.l3.go = "enlist_me";
			}
		break;

		case "enlist_me":
			// NK let you hire these people
			NPChar.Dialog.Filename = "Enc_Officer_dialog.c";
			NPChar.offgen = true;
			NPChar.officer = true;
			NPChar.quest.officertype = OFFIC_TYPE_BOATSWAIN;
			LAi_Create_Officer(rand(5), &NPChar); //so that these officers are better than tavern ones.
			ChangeCharacterReputation(Npchar, -30);

			Pchar.quest.HiringOfficerIDX = GetCharacterIndex(NPChar.id);
			AddDialogExitQuest("LandEnc_OfficerHired");
			NPChar.quest.meeting = NPC_Meeting;
			NextDiag.CurrentNode = "hired";
			DialogExit();
		break;

		case "exit_change_dlg":
			NextDiag.CurrentNode = "hired";
			DialogExit();
		break;
		// NK <--

		case "exit_fight":
			Lai_SetWarriorType(NPChar);
			NPChar.chr_ai.group = "mate";
			LAi_group_SetRelation("mate", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			DialogExit();
			LAi_group_FightGroups("mate", LAI_GROUP_PLAYER, true);
			Log_SetStringToLog(NPChar.chr_ai.group + " AI group");
		break;

		case "exit":
			LAi_SetActorType(NPchar);
			LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
			DialogExit();
		break;
	}
}

// ccc <--
