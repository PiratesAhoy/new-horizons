// ccc Dialog for civilian in fort 

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
	ref commander = (characterFromID(lcn.townsack + " Commander"));	// the fortcommander of this town

	AddMoneyToCharacter(Npchar, 1000 + rand(9000));	// gives NPC between 1000 and 10000 gold



	switch(Dialog.CurrentNode)
	{
		case "First time":
			NextDiag.TempNode = "fight";		// next time dialog starts there
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			dialog.text = LinkRandPhrase(DLG_TEXT[0], DLG_TEXT[1], DLG_TEXT[2]) ;

			Link.l1 = LinkRandPhrase(DLG_TEXT[3], DLG_TEXT[4], DLG_TEXT[5]);
			Link.l1.go = "exit";

// KK -->
			if (GetCurrentLocationNation() != PERSONAL_NATION) {
				link.l2 = DLG_TEXT[6];
				if(rand(100)< FORT_RAIDSUCCESS + (sti(pchar.skill.Sneak))*3) {Link.l2.go = "continue";}
				else{Link.l2.go = "fight";}
	
				link.l3 = LinkRandPhrase(DLG_TEXT[7], DLG_TEXT[8], DLG_TEXT[9]);
				if(rand(100)< FORT_RAIDSUCCESS + (sti(pchar.skill.Fencing))*3) {Link.l3.go = "continue";}
				else{Link.l3.go = "fight";}
	
				link.l4 = DLG_TEXT[10];
				if(rand(100)< FORT_RAIDSUCCESS + (sti(pchar.skill.leadership))*3) {Link.l4.go = "continue";}
				else{Link.l4.go = "fight";}
			} else {
			// when that's our fort...
			}
// <-- KK
		break;


		case "continue":
			dialog.text = LinkRandPhrase(DLG_TEXT[11], DLG_TEXT[12], DLG_TEXT[13]);
			Link.l1 = LinkRandPhrase(DLG_TEXT[14], DLG_TEXT[15], DLG_TEXT[16]);
			if(lcn.filespath.models == "locations\Inside\LargeStore")
			{
				Link.l1.go = "armory";	
			}
			else
			{
				switch(rand(4) )
				{
					case 0: Link.l1.go = "clerk"; break;
					case 1: Link.l1.go = "fort"; break;
					case 2: Link.l1.go = "officer"; break;
					case 3: Link.l1.go = "crimp"; break;
					case 4: Link.l1.go = "supply"; break;
				}
			}
			Link.l2 = LinkRandPhrase(DLG_TEXT[3], DLG_TEXT[4], DLG_TEXT[5]);
			Link.l2.go = "exit";
		break;


		case "Fort":
			dialog.text = DLG_TEXT[17];

			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "warning";

			Link.l2 = DLG_TEXT[19];
			Link.l2.go = "purse";

			Link.l3 = DLG_TEXT[20];
			Link.l3.go = "amnesty";

			Link.l4 = LinkRandPhrase(DLG_TEXT[3], DLG_TEXT[4], DLG_TEXT[5]);
			Link.l4.go = "exit";
		break;


		case "warning":
			Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
			dialog.text = DLG_TEXT[21];
			if (isEnabledTownCapture(lcn.townsack))
			{
				Link.l1 = DLG_TEXT[22];
				if (rand(100)< FORT_RAIDSUCCESS/2 )		//  chance that...
				{
					Link.l1.go = "capture";	// ... the town surrenders...
				}
				else
				{
					Link.l1.go = "fight";		// ... or you get another fight
				}
			}

			if (ProfessionalNavyNation() == UNKNOWN_NATION || !isEnabledTownCapture(lcn.townsack))
			{
				Link.l2 = DLG_TEXT[23];
				Link.l2.go = "purse";

				Link.l3 = DLG_TEXT[24];
				Link.l3.go = "amnesty";
			}

			Link.l4 = LinkRandPhrase(DLG_TEXT[3], DLG_TEXT[4], DLG_TEXT[5]);
			Link.l4.go = "exit";
		break;

		case "fight":
			dialog.text = LinkRandPhrase(DLG_TEXT[25], DLG_TEXT[26], DLG_TEXT[27]);
			Link.l1 = RandSwear() + DLG_TEXT[28];
			Link.l1.go = "exit_fight";
		break;


		case "capture":
			PlayStereoOGG("music_ship_victory"); 		// fanfare
			if(GetRMRelation(PChar, sti(commander.nation)) > REL_WAR)
			{
				SetRMRelation(pchar, sti(commander.nation), REL_WAR);
				LooseLetterOfMarque(sti(commander.nation)); // KK
			}
			LAi_Fade("", "");

			dialog.text = DLG_TEXT[29];
			if (ProfessionalNavyNation() == UNKNOWN_NATION || ProfessionalNavyNation() == PORTUGAL)
			{
				Link.l2 = DLG_TEXT[30];
				Link.l2.go = "portugal";
			}

			if (ProfessionalNavyNation() == UNKNOWN_NATION || ProfessionalNavyNation() == HOLLAND)
			{
				Link.l1 = DLG_TEXT[31];
				Link.l1.go = "dutch";
			}

			if (ProfessionalNavyNation() == UNKNOWN_NATION || ProfessionalNavyNation() == ENGLAND)
			{
				Link.l3 = DLG_TEXT[32];
				Link.l3.go = "britain";
			}

			if (ProfessionalNavyNation() == UNKNOWN_NATION || ProfessionalNavyNation() == FRANCE)
			{
				Link.l4 = DLG_TEXT[33] + GetNationRoyalByType(FRANCE) + DLG_TEXT[34];
				Link.l4.go = "france";
			}

			if (ProfessionalNavyNation() == UNKNOWN_NATION || ProfessionalNavyNation() == SPAIN)
			{
				Link.l5 = DLG_TEXT[35] + GetNationRoyalByType(SPAIN) + DLG_TEXT[36];
				Link.l5.go = "spain";
			}

			if (GetCurrentPeriod() >= PERIOD_REVOLUTIONS)
			{
				if (ProfessionalNavyNation() == UNKNOWN_NATION || ProfessionalNavyNation() == AMERICA)
				{
					Link.l6 = DLG_TEXT[37];
					Link.l6.go = "america";
				}
			}

			if (SWEDEN_ALLOWED && GetCurrentPeriod() >= PERIOD_THE_SPANISH_MAIN && GetCurrentPeriod() <= PERIOD_COLONIAL_POWERS)
			{
				if (ProfessionalNavyNation() == UNKNOWN_NATION || ProfessionalNavyNation() == SWEDEN)
				{
					Link.l6 = DLG_TEXT[38] + GetNationRoyalByType(SWEDEN) + DLG_TEXT[39];
					Link.l6.go = "sweden";
				}
			}

			if (GetServedNation() == PIRATE || PChar.nation == PIRATE)
			{
				link.l7 = DLG_TEXT[40];
				link.l7.go = "pirate";
			}

			if (ProfessionalNavyNation() == UNKNOWN_NATION)
			{
				Link.l8 = DLG_TEXT[41];
				Link.l8.go = "ransack";
			}
		break;


		case "portugal":
			PlayStereoSound("voice\" + LanguageGetLanguage() + "\por_m_a_038.wav");
			LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);

			ChangeTownNation (lcn.townsack, PORTUGAL);
			if (GetRMRelation(PChar, PORTUGAL) < 0)
			{
				SetRMRelation(GetMainCharacter(), PORTUGAL, REL_NEUTRAL);
				ReceiveLetterOfMarque(PORTUGAL); // KK
			}

			if(AUTO_SKILL_SYSTEM) { AddCharacterExpChar(pchar, "Leadership", 5000); }
			else { AddCharacterExp(pchar, 5000); }
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "dutch":
			PlayStereoSound("voice\" + LanguageGetLanguage() + "\dut_m_a_040.wav");
			LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);

			ChangeTownNation (lcn.townsack, HOLLAND);
			if (GetRMRelation(PChar, HOLLAND) < 0)
			{
				SetRMRelation(GetMainCharacter(), HOLLAND, REL_NEUTRAL);
				ReceiveLetterOfMarque(HOLLAND); // KK
			}

			if(AUTO_SKILL_SYSTEM) { AddCharacterExpChar(pchar, "Leadership", 5000); }
			else { AddCharacterExp(pchar, 5000); }
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "britain":
			PlayStereoSound("voice\" + LanguageGetLanguage() + "\eng_m_a_051.wav");
			LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);

			ChangeTownNation (lcn.townsack, ENGLAND);
			if (GetRMRelation(PChar, ENGLAND) < 0)
			{
				SetRMRelation(GetMainCharacter(), ENGLAND, REL_NEUTRAL);
				ReceiveLetterOfMarque(ENGLAND); // KK
			}

			if(AUTO_SKILL_SYSTEM) { AddCharacterExpChar(pchar, "Leadership", 5000); }
			else { AddCharacterExp(pchar, 5000); }
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;


		case "france":
			PlayStereoSound("voice\" + LanguageGetLanguage() + "\fre_m_a_042.wav");
			LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);

			ChangeTownNation (lcn.townsack, FRANCE);
			if (GetRMRelation(PChar, FRANCE) < 0)
			{
				SetRMRelation(GetMainCharacter(), FRANCE, REL_NEUTRAL);
				ReceiveLetterOfMarque(FRANCE); // KK
			}

			if(AUTO_SKILL_SYSTEM) { AddCharacterExpChar(pchar, "Leadership", 5000); }
			else { AddCharacterExp(pchar, 5000); }
			LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "spain":
			PlayStereoSound("voice\" + LanguageGetLanguage() + "\spa_m_a_039.wav");
			LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);

			ChangeTownNation (lcn.townsack, SPAIN);
			if (GetRMRelation(PChar, SPAIN) < 0)
			{
				SetRMRelation(GetMainCharacter(), SPAIN, REL_NEUTRAL);
				ReceiveLetterOfMarque(SPAIN); // KK
			}

			if(AUTO_SKILL_SYSTEM) { AddCharacterExpChar(pchar, "Leadership", 5000); }
			else { AddCharacterExp(pchar, 5000); }
			LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "america":
			PlayStereoSound("voice\" + LanguageGetLanguage() + "\Eng_m_c_047.wav");
			LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);

			ChangeTownNation (lcn.townsack, AMERICA);
			if (GetRMRelation(PChar, AMERICA) < 0)
			{
				SetRMRelation(GetMainCharacter(), AMERICA, REL_NEUTRAL);
				ReceiveLetterOfMarque(AMERICA); // KK
			}

			if(AUTO_SKILL_SYSTEM) { AddCharacterExpChar(pchar, "Leadership", 5000); }
			else { AddCharacterExp(pchar, 5000); }
			LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "sweden":
			PlayStereoSound("voice\" + LanguageGetLanguage() + "\Eng_m_c_045.wav");
			LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);

			ChangeTownNation (lcn.townsack, SWEDEN);
			if (GetRMRelation(PChar, SWEDEN) < 0)
			{
				SetRMRelation(GetMainCharacter(), SWEDEN, REL_NEUTRAL);
				ReceiveLetterOfMarque(SWEDEN); // KK
			}

			if(AUTO_SKILL_SYSTEM) { AddCharacterExpChar(pchar, "Leadership", 5000); }
			else { AddCharacterExp(pchar, 5000); }
			LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "pirate":
			PlayStereoSound("voice\" + LanguageGetLanguage() + "\Eng_m_c_045.wav");
			LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);

			ChangeTownNation (lcn.townsack, PIRATE);
			if (GetRMRelation(PChar, PIRATE) < 0)
			{
				SetRMRelation(GetMainCharacter(), PIRATE, REL_NEUTRAL);
			}
			SetServedNation(PIRATE);

			if(AUTO_SKILL_SYSTEM) { AddCharacterExpChar(pchar, "Leadership", 5000); }
			else { AddCharacterExp(pchar, 5000); }
			LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "ransack":
			PlayStereoOGG("music_ship_victory"); 		// fanfare
			if(GetRMRelation(PChar, sti(commander.nation)) > REL_WAR)
			{
				SetRMRelation(pchar, sti(commander.nation), REL_WAR);
				LooseLetterOfMarque(sti(commander.nation)); // KK
			}
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			LaunchFortCapture(commander);	// towncapture
		break;

		case "purse":
			dialog.text =  RandSwear() + LinkRandPhrase(DLG_TEXT[42], DLG_TEXT[43], DLG_TEXT[44]) + npchar.money + DLG_TEXT[45];
			Link.l1 = LinkRandPhrase(DLG_TEXT[46], DLG_TEXT[47], DLG_TEXT[48]);
			Link.l1.go = "exit";

			LAi_group_SetRelation( LAI_GROUP_GUARDS, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, sti(npchar.money));
			AddMoneyToCharacter(Npchar, - sti(npchar.money));

		break;

		case "bombs":
			LAi_group_SetRelation( LAI_GROUP_GUARDS, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			AddCharacterGoods(pchar, GOOD_BOMBS, makeint(200 + rand(500)) );
			LAi_SetActorType(NPchar);
			LAi_ActorRunToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "arms":
			LAi_group_SetRelation( LAI_GROUP_GUARDS, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
     			 // ccc special weapons, SW assembly kit must be installed !
			TakenItems(Pchar, "pistolbbuss", rand(2));	
			TakenItems(Pchar, "bladeX1", rand(1));	
			TakenItems(Pchar, "bladeX2", rand(1));	
			TakenItems(Pchar, "bladeX3", rand(1));	
			TakenItems(Pchar, "pistolpdart", rand(3));
			TakenItems(Pchar, "pistolgrenade", rand(3));
			TakenItems(Pchar, "pistolgas", rand(3));
			TakenItems(Pchar, "pistolrock", rand(3));
			TakenItems(Pchar, "pistolstink", rand(3));
			LAi_SetActorType(NPchar);
			LAi_ActorRunToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "amnesty":
			LAi_group_SetRelation(LAI_GROUP_PLAYER, LAI_GROUP_GUARDS, LAI_GROUP_NEUTRAL);
			LAi_group_SetRelation(LAI_GROUP_PLAYER, LAI_DEFAULT_GROUP, LAI_GROUP_NEUTRAL);
			SetRMRelation(pchar, sti(commander.nation), REL_NEUTRAL);	// gives you LOM of the fort NATION, based on NK's RM mod
			ReceiveLetterOfMarque(sti(commander.nation)); // KK
			if(AUTO_SKILL_SYSTEM) { AddCharacterExpChar(pchar, "Leadership", 5000); }
			else { AddCharacterExp(pchar, 5000); }
			LAi_SetActorType(NPchar);
			LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "clerk":
			dialog.text = DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[51];
			Link.l2.go = "purse";

		break;


		case "armory":
			dialog.text = DLG_TEXT[52];
			Link.l1 = DLG_TEXT[53];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[54];
			Link.l2.go = "bombs";

			Link.l3 = DLG_TEXT[55];
			Link.l3.go = "arms";
		break;


		case "crimp":
			dialog.text = DLG_TEXT[56];

			if(IsBrothelEnabled())
			{
				Link.l1 = DLG_TEXT[57];
				Link.l1.go = "exit";
			}
			else
			{
				Link.l1 = DLG_TEXT[70];
				Link.l1.go = "exit";
			}

			Link.l2 = DLG_TEXT[58];
			Link.l2.go = "Exit_crew";

			Link.l3 = DLG_TEXT[59];
			Link.l3.go = "purse";
		break;


		case "Exit_crew":
			AddCharacterCrew(pchar,makeint(50 + rand(50) ));
			LAi_SetActorType(NPchar);
			LAi_ActorRunToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;



		case "supply":
			dialog.text = DLG_TEXT[60];

			Link.l1 = DLG_TEXT[61];
			Link.l1.go = "exit";

			Link.l2 = DLG_TEXT[62];
			Link.l2.go = "Exit_buy";

			Link.l3 = DLG_TEXT[63];
			Link.l3.go = "purse";
		break;

		case "Exit_buy":
			AddCharacterGoods(pchar, GOOD_WHEAT, makeint(15 + rand(20)) );
			AddCharacterGoods(pchar, GOOD_PLANKS, makeint(40 + rand(30)) );
			AddCharacterGoods(pchar, GOOD_SAILCLOTH, makeint(40 + rand(30)) );
			AddCharacterGoods(pchar, GOOD_RUM, makeint(15 + rand(20)) );
			LAi_SetActorType(NPchar);
			LAi_ActorRunToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;


		case "officer":
			dialog.text = DLG_TEXT[64];
			Link.l1 = DLG_TEXT[65];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[66];
			Link.l2.go = "purse";

			if(sti(GetStorylineVar(FindCurrentStoryline(), "NO_CREW_OR_OFFICERS")) < 1 && !CheckAttribute(PChar, "isnotcaptain"))
			{
				Link.l3 = DLG_TEXT[67];
				Link.l3.go = "enlist_me";
			}
		break;


		case "enlist_me":
			// NK let you hire these people
			NPChar.Dialog.Filename = "Enc_Officer_dialog.c";
			dialog.Text = DLG_TEXT[68];
			Link.l1 = DLG_TEXT[69];
			Link.l1.go = "exit_change_dlg";
			NPChar.offgen = true;
			NPChar.officer = true;
			NPChar.quest.officertype = OFFIC_TYPE_BOATSWAIN;
			LAi_Create_Officer(rand(5), &NPChar); //so that these officers are better than tavern ones.

			Pchar.quest.HiringOfficerIDX = GetCharacterIndex(NPChar.id);
			AddDialogExitQuest("LandEnc_OfficerHired");
			NPChar.quest.meeting = NPC_Meeting;

		break;


		case "exit_change_dlg":
			NextDiag.CurrentNode = "hired";
			DialogExit();
		break;
		// NK <--

		case "exit":
			LAi_SetActorType(NPchar);
			LAi_ActorRunToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "exit_fight":
		// PB: To prevent the fight from starting before the dialog is closed
			PlaySound("voice\" + LanguageGetLanguage() + "\Eng_m_a_067.wav");
			if(GetRMRelation(PChar, sti(commander.nation)) > REL_WAR)
			{
				SetRMRelation(pchar, sti(commander.nation), REL_WAR);
				LooseLetterOfMarque(sti(commander.nation)); // KK
			}
			Ambush("Soldiers", 8, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "");

			LAi_SetActorType(NPchar);
			LAi_ActorRunToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}

// ccc <--
