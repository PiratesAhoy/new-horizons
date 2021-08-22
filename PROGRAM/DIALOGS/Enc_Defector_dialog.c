//#include "DIALOGS\Enc_RapersGirl_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	string gemtype;
	int i;
	
	// DeathDaisy: Persuasion tags for the skill checks, if enabled
	string PersuasionSuccess = "";
	string PersuasionFailure = "";
	if(PERSUASION_TAGS){ 
		PersuasionSuccess = XI_ConvertString("Persuasion_Success") + " ";
		PersuasionFailure = XI_ConvertString("Persuasion_Failure") + " ";
	}
	
	
	switch(Dialog.CurrentNode)
	{
		case "exit_1":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();			
		break;
		case "Node_1":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			d.Text = RandPhrase(DLG_TEXT[0], DLG_TEXT[1], DLG_TEXT[2], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = LinkRandPhrase(DLG_TEXT[3], DLG_TEXT[4], DLG_TEXT[5]);
			Link.l1.go = "Node_2";			
		break;

		case "Node_2":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			d.Text = RandPhrase(DLG_TEXT[6], DLG_TEXT[7], DLG_TEXT[8], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "exit_1";	
			AddDialogExitQuest("LandEnc_Defector_PursuersTalk");		
		break;

		case "ThanksForHelp":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			Preprocessor_Add("sir2", GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false)); // DeathDaisy
			d.Text = RandPhrase(DLG_TEXT[10], DLG_TEXT[11], DLG_TEXT[12], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "ThanksForHelp_1";			
		break;
		
		case "ThanksForHelp_1":
			Diag.TempNode = "ThanksAgain";
			i = rand(2) + 1;							// Standard - choice of cases 1-3
			if(makeint(PChar.reputation) >= REPUTATION_VERYGOOD) i = rand(3) + 1;	// Dashing - choice of cases 1-4
			if(makeint(PChar.reputation) >= REPUTATION_HERO) i = rand(2) + 2;	// Hero - choice of cases 2-4
//			if(makeint(PChar.reputation) < REPUTATION_SWINDLER) i = rand(3);	// Possibly give low reputation characters a case 0, not currently defined

			switch(i)
			{
				case 1:					// Reputation boost			
					string PCharGentle;		// DeathDaisy ->
					if(PChar.sex == "woman")	PCharGentle = XI_ConvertString("gentlewoman");
					else	PCharGentle = XI_ConvertString("gentleman");
					Preprocessor_Add("gentleman", PCharGentle);
					// DeathDaisy <-
					d.Text = DLG_TEXT[16];
					Link.l1 = DLG_TEXT[17];
					int repch2 = 3;
					if(makeint(Pchar.reputation) >= 60) repch2 = 2;
					if(makeint(Pchar.reputation) >= 70) repch2 = 1;
					ChangeCharacterReputation(pchar, repch2); // NK
					Link.l1.go = "exit_1";
				break;

				case 2:					// Gem
					gemtype = "jewelry" + (rand(3) + 1);
					Preprocessor_Add("gem", GetItemNameByID(gemtype));
					PlayStereoSound("INTERFACE\important_item.wav");
					GiveItem2Character(PChar, gemtype);
					PChar.quest.defector_gemtype = gemtype;
					PChar.quest.defector_island = FindIslandByLocation(PChar.location);
					d.Text = DLG_TEXT[14];
					Link.l1 = DLG_TEXT[15];
					Link.l1.go = "Exit_1";
				break;

				case 3:					// Criminal tools
					PlayStereoSound("INTERFACE\important_item.wav");
					GiveItem2Character(PChar, "bladex3");
					GiveItem2Character(PChar, "lockpick");
					TakenItems(PChar, "pistolpdart", 1 + rand(4));
					TakenItems(PChar, "pistolgas", 1 + rand(4));
					d.Text = DLG_TEXT[18];
					Link.l1 = DLG_TEXT[19];
					Link.l1.go = "exit_1";
				break;

				case 4:					// Officer
					NPChar.Dialog.Filename = "Enc_Officer_dialog.c";
					d.Text = DLG_TEXT[20] + GetMyFullName(PChar) + DLG_TEXT[21];
					Link.l1 = DLG_TEXT[22];
					Link.l1.go = "exit_change_dlg";
					NPChar.offgen = true;
					NPChar.officer = true;
					NPChar.quest.officertype = GetRandomOfficerType(); //Levis let's use a global function so we can easily add types later.
					LAi_Create_Officer(rand(5), &NPChar); //so that these officers are better than
				break;
			}
			AddDialogExitQuest("LandEnc_Char1_Leaves");
		break;

		case "ThanksAgain":



		break;

		case "enlist_me":
			// NK let you hire these people
			d.Text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "exit_change_dlg";
			NPChar.Dialog.Filename = "Enc_Officer_dialog.c";
			NPChar.offgen = true;
			NPChar.officer = true;
			NPChar.quest.officertype = GetRandomOfficerType(); //Levis let's use a global function so we can easily add types later.
			LAi_Create_Officer(rand(5), &NPChar); //so that these officers are better than tavern ones.
			Pchar.quest.HiringOfficerIDX = GetCharacterIndex(NPChar.id);
			AddDialogExitQuest("LandEnc_OfficerHired");
		break;

		case "exit_change_dlg":
			Diag.CurrentNode = "Node_1";
			DialogExit();
			PChar.quest.hire_enc_walker = NPChar.id;
			AddDialogExitQuest("LandEnc Talk to player about hireing");
			DeleteAttribute(PChar,"newofficerid");//MAXIMUS
		break;
	}
}