// ccc Dialog for dead maltese

void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	int tmpNameFileID = LanguageOpenFile("characters_names.txt");
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
	string cryptstring = " " + LanguageConvertString(tmpLangFileID,"below the FLOORSLABS of this church") + " ";
	int fightchance = 20;

	if(lcn.id == "Greenford_M_crypt") // PB
	{
		AddMoneyToCharacter(Npchar, 500 + rand(2000));
		fightchance = 50;
		cryptstring = " " + LanguageConvertString(tmpLangFileID,"here") + " ";
	}

	if(lcn.id == "Greenford_M_undercroft")
	{
		cryptstring = " " + LanguageConvertString(tmpLangFileID,"south of this undercroft, behind the halfcollapsed passage") + " ";
	}

	float x,y,z;
	GetCharacterPos(NPChar, &x, &y, &z);
	if(USE_PARTICLES>1) CreateParticleSystemX("artifact", x, y+1.5, z, x, y+2, z,2);	// ccc Dec05 tweak added
	//MAXIMUS -->
	//Log_SetActiveAction("Nothing");
	//BLI_RefreshCommandMenu();
	//MAXIMUS <--

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

		//MAXIMUS: temporary added (fix for missed 'purged' attribute) --> // KK -->
		if (CheckAttribute(lcn, "abbey") == true && sti(lcn.abbey) == true) {
			if(!CheckAttribute(lcn,"purged")) lcn.purged = 1;
		}
		//MAXIMUS: temporary added (fix for missed 'purged' attribute) <-- // <-- KK
		if(!LAi_group_IsActivePlayerAlarm() && lcn.purged == 0 )
		{
			lcn.purged = 1;
			PlayStereoSound("ambient\church\bell.wav");
			ChangeCharacterReputation(pchar, 1);
			if(AUTO_SKILL_SYSTEM) { AddCharacterExpChar(pchar, "Sneak", 5000); }
			else { AddCharacterExp(pchar, 5000); }
			PlayStereoSound("interface\ship_dead1.wav");
			PlayStereoSound("interface\took_item.flac");

			dialog.text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "exit";

		}else{
			 if (rand(100)< fightchance )
			{
				if (rand(100)> 20 )
				{
				PlaySound("OBJECTS\DUEL\skeleton_attack2.wav");
				dialog.text = DLG_TEXT[2];
				Link.l1 = RandSwear() + LinkRandPhrase(DLG_TEXT[3], DLG_TEXT[4], DLG_TEXT[5]);
				Link.l1.go = "exitfight";
				}else{
				PlaySound("voice\" + LanguageGetLanguage() + "\Eng_m_a_022.wav");
				dialog.text = RandSwear() + DLG_TEXT[6];
				Link.l1 = DLG_TEXT[7];
				Link.l1.go = "run";
				}
			}else{
			PlayStereoSound("ambient\church\bell.wav");
			PlayStereoSound("trep\priest_bead.wav");
			dialog.text = DLG_TEXT[8];
			Link.l1 = LinkRandPhrase(DLG_TEXT[9], DLG_TEXT[10], DLG_TEXT[11]);
			Link.l1.go = "exit";

			if(lcn.id == "Greenford_M_crypt") // PB
			{
				link.l4 = DLG_TEXT[12];
				Link.l4.go = "crypt";
			}

			link.l2 = RandSwear() + DLG_TEXT[13];
			Link.l2.go = "continue";
			link.l3 = DLG_TEXT[14];
			Link.l3.go = "exitrep";
			}
		}
		break;

		case "crypt":
			dialog.text = DLG_TEXT[15];
			link.l2 = DLG_TEXT[16];
			Link.l2.go = "crypt1-1";
			Link.l1 = DLG_TEXT[17];
			Link.l1.go = "exit";
		break;

		case "crypt1-1":
			dialog.text = DLG_TEXT[39];
			Link.l2.go = "crypt2";
		break;

		case "crypt2":
			dialog.text = DLG_TEXT[18];
			link.l2 = DLG_TEXT[19];
			Link.l2.go = "crypt3";
			Link.l1 = DLG_TEXT[20];
			Link.l1.go = "exit";
		break;

		case "crypt3":
			dialog.text = DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "exit";
		break;

		case "continue":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			Link.l1.go = "continue2";
			Link.l2 = DLG_TEXT[25];
			Link.l2.go = "exit";
		break;

		case "continue2":
			CreateParticleSystemX("fire_medium", x, y+1, z, x, y+2, z,4);	// effects at that pos
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			Link.l1.go = "continue3";
		break;

		case "continue3":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			Link.l1.go = "continue4";
		break;

		case "continue4":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			Link.l1.go = "continue5";
		break;

		case "continue5":
			dialog.text = DLG_TEXT[32] + cryptstring + DLG_TEXT[33];
			Link.l1 = DLG_TEXT[34];
			Link.l1.go = "exit";
		break;

		case "run":
			dialog.text = DLG_TEXT[35];
			Link.l1 = DLG_TEXT[36] + RandSwear();
			Link.l1.go = "run2";
		break;

		case "run2":
			dialog.text = DLG_TEXT[37];
			Link.l1 = RandSwear() + DLG_TEXT[38];
			Link.l1.go = "exitrun";
		break;

		case "exit":
			if(lcn.id == "Greenford_M_crypt") // PB
			{
				GiveItem2Character(pchar, "jewelry"+ makeint(1 + rand(13)) );
				GiveItem2Character(pchar, "Mineral7" );
			}else{
				GiveItem2Character(pchar, "potion"+ makeint(1 + rand(3)) );
				GiveItem2Character(pchar, "jewelry9");
			}
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, sti(npchar.money));
			GiveItem2Character(pchar, "blade8" );
			if(AUTO_SKILL_SYSTEM) { AddCharacterExpChar(pchar, "Sneak", 200); }
			else { AddCharacterExp(pchar, 200); }

			if(CORPSEMODE==4) { DialogCorpseExit(NPchar); }
			else { DialogExit(); }
			NextDiag.CurrentNode = NextDiag.TempNode;

			If(USE_PARTICLES>0) CreateParticleSystemX("artifact", x, y+1.5, z, x, y+2, z,2);	// ccc Dec05 tweak added

			if(CORPSEMODE==4) { LAi_CharacterLogoff(NPChar); CharacterExitFromLocation(NPChar); }//MAXIMUS
			ChangeCharacterAddress(NPChar, "none", "");
			PlayStereoSound("NATURE\doves.wav");
			PlayStereoSound("NATURE\wind_sea4.wav");
			Logit(LanguageConvertString(tmpLangFileID,"The warriormonk disappears... like the smoke of a long forgotten pyre..."));
		break;

		case "exitrep":
			ChangeCharacterReputation(pchar, 1);
			if(CORPSEMODE==4) { DialogCorpseExit(NPchar); }
			else { DialogExit(); }
			NextDiag.CurrentNode = NextDiag.TempNode;

			If(USE_PARTICLES>0) CreateParticleSystemX("artifact", x, y+1.5, z, x, y+2, z,2);	// ccc Dec05 tweak added

			if(CORPSEMODE==4) { LAi_CharacterLogoff(NPChar); CharacterExitFromLocation(NPChar); }//MAXIMUS
			ChangeCharacterAddress(NPChar, "none", "");
			PlayStereoSound("NATURE\doves.wav");
			PlayStereoSound("NATURE\wind_sea4.wav");
			Logit(LanguageConvertString(tmpLangFileID,"The warriormonk disappears... like the smoke of a long forgotten pyre..."));
		break;

		case "exitfight":
			if(CORPSEMODE==4) { DialogCorpseExit(NPchar); }
			else { DialogExit(); }
			NextDiag.CurrentNode = NextDiag.TempNode;

			if(CORPSEMODE!=4) { ChangeCharacterAddress(NPChar, "none", ""); }//MAXIMUS

			CreateParticleSystemX("fire_medium", x, y+2, z, x, y+2, z,2);	// effects at that pos
			If(USE_PARTICLES>1) CreateParticleSystemX("artifact", x, y+1.5, z, x, y+2, z,2);	// ccc Dec05 tweak added
			PlaySound("OBJECTS\DUEL\skeleton_attack1.wav");
			PlayStereoSound("AMBIENT\INCA TEMPLE\teleporter.wav");
			If(USE_PARTICLES>1) PlayStereoSound("NATURE\wind_tornado.wav");	// ccc Dec05 tweak added

			ref corpse = NPChar;
			if(CORPSEMODE!=4) { corpse = LAi_CreateFantomCharacterEx(false, 0, true, false, 0.0, "skel2", "", ""); TeleportCharacterToPos(corpse, x,y,z); }//MAXIMUS
			GiveItem2Character(corpse, "blade8");
			EquipCharacterByItem(corpse, "blade8");
			LAi_SetWarriorType(corpse);
			LAi_group_MoveCharacter(corpse, LAI_GROUP_MONSTERS);
			// LAi_group_SetRelation(LAI_GROUP_PLAYER, LAI_GROUP_MONSTERS, LAI_GROUP_ENEMY);
			corpse.name = LanguageConvertString(tmpNameFileID,"Maltese");
			corpse.lastname = LanguageConvertString(tmpNameFileID,"Knight");
			LAi_SetImmortal(corpse, false);

		break;

		case "exitrun":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(Npchar, 1000 + rand(5000));
			AddMoneyToCharacter(Npchar, sti(pchar.money));
			pchar.money = 0;
			Npchar.name = LanguageConvertString(tmpNameFileID,"Thievish");
			GiveItem2Character(Npchar, "blade8");
			EquipCharacterByItem(Npchar, "blade8");
			LAi_group_MoveCharacter(Npchar, "runner");
			LAi_group_SetRelation("runner", LAI_GROUP_MONSTERS, LAI_GROUP_ENEMY);
			LAi_SetHP(NPchar, 20.0,  20.0);
			LAi_SetImmortal(NPchar, false);


			LAi_SetActorType(NPchar);
			string locator = LAi_FindFarFreeLocator("reload", x, y, z);
			LAi_ActorRunToLocation(NPchar, "reload", locator, "none", "", "", "", 25.0);
			if(CORPSEMODE==4) { DialogCorpseExit(NPchar); }
			else { DialogExit(); }
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
	LanguageCloseFile(tmpLangFileID);
	LanguageCloseFile(tmpNameFileID);
}

// ccc <--
