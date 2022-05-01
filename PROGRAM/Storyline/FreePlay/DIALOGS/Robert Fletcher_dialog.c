void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("characters_names.txt");
	ref NPChar;
	aref Link, NextDiag;
	string boarder_blade = BOARDER_SPAREBLADE;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

// PB -->
	ref TutDeck = &Locations[FindLocation("Tutorial_Deck")];
// PB <--
	
	switch(Dialog.CurrentNode)
	{
		case "start":
			switch(CharPlayerType)
			{
				case PLAYER_TYPE_NAVAL_OFFICER:
					dialog.text = DLG_TEXT[240] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, true) + DLG_TEXT[241];
					link.l1 = DLG_TEXT[242];
					link.l1.go = "naval_part2";
				break;

				case PLAYER_TYPE_ROGUE:
					dialog.text = DLG_TEXT[247];
					if(PChar.sex == "woman") link.l1 = DLG_TEXT[264];
					else link.l1 = DLG_TEXT[248];
					link.l1.go = "stormystart";
					link.l2 = DLG_TEXT[265];
					link.l2.go = "no_duel";
				break;

				case PLAYER_TYPE_GAMBLER:
					dialog.text = DLG_TEXT[249];
					link.l1 = DLG_TEXT[250];
					link.l1.go = "stormystart";
					link.l2 = DLG_TEXT[265];
					link.l2.go = "no_duel";
				break;

				case PLAYER_TYPE_AGENT:
					dialog.text = DLG_TEXT[251];
					link.l1 = DLG_TEXT[252];
					link.l1.go = "agent_start2";
				break;

				case PLAYER_TYPE_SMUGGLER:
					dialog.text = DLG_TEXT[253];
					link.l1 = DLG_TEXT[254];
					link.l1.go = "stormystart";
					switch (GetMySimpleOldName(PChar))
					{
						case "Anamaria":
							dialog.text = DLG_TEXT[290] + GetMyShipNameShow(PChar) + DLG_TEXT[291];
							if (GetCharacterShipID(PChar) == "Tartane50") link.l1 = DLG_TEXT[292];
							else link.l1 = DLG_TEXT[293];
							AddDialogExitQuest("rename_PoTC");
						break;
					}
				break;

				case PLAYER_TYPE_CURSED:
					if(CheckCharacterItem(PChar, "Davy_Chest"))
					{
						dialog.text = DLG_TEXT[255];
						link.l1 = DLG_TEXT[256];
						
					}
					else
					{
						dialog.text = DLG_TEXT[257];
						link.l1 = DLG_TEXT[258];
					}
					link.l1.go = "stormystart";
					if(CheckCharacterItem(PChar, "Devil_Contract"))
					{
						if (PChar.sex == "man") Preprocessor_Add("child", XI_ConvertString("my son"));
						else Preprocessor_Add("child", XI_ConvertString("my child"));
						dialog.text = DLG_TEXT[266];
						link.l1 = DLG_TEXT[267];
						link.l1.go = "DevilCursed1";
						
					}
				break;

				case PLAYER_TYPE_CORSAIR:
					dialog.text = DLG_TEXT[259];
					if (GetNationRelation2MainCharacter(GetTownNation("Tortuga")) == RELATION_ENEMY)
						link.l1 = DLG_TEXT[260];
					else
						link.l1 = DLG_TEXT[261];
					link.l1.go = "stormystart";
				break;

				case PLAYER_TYPE_CASTAWAY:
					dialog.text = DLG_TEXT[262];
					link.l1 = DLG_TEXT[263];
					link.l1.go = "stormystart";
				break;

				case PLAYER_TYPE_REBEL:
					switch(GetMySimpleOldName(PChar))
					{
						case "Dark Teacher":
    							dialog.text = DLG_TEXT[296];
    							link.l1 = DLG_TEXT[297];
    							link.l1.go = "stormystart";
						break;
						dialog.text = DLG_TEXT[0];
						link.l1 = DLG_TEXT[1];
						link.l1.go = "intro2";
						link.l2 = DLG_TEXT[2];
						link.l2.go = "start1";
						link.l3 = DLG_TEXT[3];
						link.l3.go = "stormystart";
					}
				break;

				case PLAYER_TYPE_SWORD_MASTER:
					switch(GetMySimpleOldName(PChar))
					{
						case "Will Turner":
							if (PChar.model == "will")
							{
	    							dialog.text = DLG_TEXT[294];
    								link.l1 = DLG_TEXT[295];
							}
							else
							{
	    							dialog.text = DLG_TEXT[298];
    								link.l1 = DLG_TEXT[299];
							}
							AddDialogExitQuest("rename_PoTC");
    							link.l1.go = "stormystart";
						break;
					}
				break;

				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "intro2";
				link.l2 = DLG_TEXT[2];
				link.l2.go = "start1";
				link.l3 = DLG_TEXT[3];
				link.l3.go = "stormystart";
			}
			PChar.vcskip = true;
		break;

		case "DevilCursed1":
			dialog.text = DLG_TEXT[268];
			link.l1 = DLG_TEXT[269];
			link.l1.go = "DevilCursed2";
		break;
		
		case "DevilCursed2":
			dialog.text = DLG_TEXT[270] + GetMyName(Pchar) + DLG_TEXT[281] + DLG_TEXT[271];
			link.l1 = DLG_TEXT[272];
			link.l1.go = "DevilCursed3";
		break;
		
		case "DevilCursed3":
			dialog.text = DLG_TEXT[273] + GetMyName(Pchar) + DLG_TEXT[281] + DLG_TEXT[274] + GetMyName(Pchar) + DLG_TEXT[275] + DLG_TEXT[276];
			link.l1 = DLG_TEXT[277];
			link.l1.go = "DevilCursed4";
		break;
		
		case "DevilCursed4":
			dialog.text = DLG_TEXT[278];
			link.l1 = DLG_TEXT[279];
			link.l1.go = "DevilCursed5";
		break;
		
		case "DevilCursed5":
			dialog.text = DLG_TEXT[280] + GetMyFullName(PChar) + DLG_TEXT[281] + DLG_TEXT[282];
			link.l1 ="";
			link.l1.go = "stormystart";
		break;
		
		case "intro2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "intro3";
		break;

		case "intro3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "intro4";
		break;

		case "intro4":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			Link.l1.go = "start1";
		break;

		case "start1":
			BLI_UpdateOfficers();
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "start2";
			link.l2 = DLG_TEXT[12];
			link.l2.go = "Skip_tutorial";
			link.l3 = DLG_TEXT[13];
			link.l3.go = "stormystart";
		break;

		case "start2":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "start3";
		break;

		case "start3":
			dialog.text = DLG_TEXT[16] + DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "start4";
		break;

		case "start4":
			addDialogExitQuest("Tut_TakeStuff");
			NextDiag.TempNode = "TakeWeapon";
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Exit";
		break;
		
		case "TakeWeapon":
			if(FindCharacterItemByGroup(PChar, BLADE_ITEM_TYPE) == "" || FindCharacterItemByGroup(PChar, SPYGLASS_ITEM_TYPE) == "")
			{	
				NextDiag.TempNode = "TakeWeapon";
				dialog.text = DLG_TEXT[21];
				link.l1 = DLG_TEXT[22];
				link.l1.go = "Exit";
			}
			else
			{
				if(CheckAttribute(PChar,"equip."+BLADE_ITEM_TYPE) && GetCharacterEquipByGroup(PChar,SPYGLASS_ITEM_TYPE) != "") // PB
				{
					if (WEAPONSLOCKER == 1) 
					{
						if (GET_WEAPONS_BACK == 1)
							Dialog.text = DLG_TEXT[23] + DLG_TEXT[24] + DLG_TEXT[26];
						else
							Dialog.text = DLG_TEXT[23] + DLG_TEXT[25] + DLG_TEXT[26];
							link.l1 = DLG_TEXT[18];
							link.l1.go = "Weaponslocker";
					} 
					else 
					{
						dialog.text = DLG_TEXT[27];
						link.l1 = DLG_TEXT[28];
						link.l1.go = "Swordplay";
						link.l2 = DLG_TEXT[29];
						link.l2.go = "OutOfThisShip";
						link.l3 = DLG_TEXT[30];
						link.l3.go = "Skip_tutorial";
					}
				}
				else
				{
				//	addDialogExitQuest("Tut_EquipWeapon");	// PB: Doesn't exist?
					NextDiag.TempNode = "EquipWeapon";
					dialog.text = DLG_TEXT[31] + DLG_TEXT[32];
					link.l1 = DLG_TEXT[33];
					link.l1.go = "Exit";
				}
			}
		break;

		case "EquipWeapon":
			if(FindCharacterItemByGroup(PChar, BLADE_ITEM_TYPE) == "" || FindCharacterItemByGroup(PChar, SPYGLASS_ITEM_TYPE) == "")
			{
				NextDiag.TempNode = "TakeWeapon";
				dialog.text = DLG_TEXT[21];
				link.l1 = DLG_TEXT[22];
				link.l1.go = "Exit";
			}
			else
			{
				if(CheckAttribute(PChar,"equip."+BLADE_ITEM_TYPE) && GetCharacterEquipByGroup(PChar,SPYGLASS_ITEM_TYPE) != "") // PB
				{
					if(GetCharacterEquipByGroup(PChar,BLADE_ITEM_TYPE)=="bladeX4")
					{
						Dialog.TempNode = "EquipWeapon";
						dialog.text = DLG_TEXT[34];
						link.l1 = DLG_TEXT[35];
						link.l1.go = "Exit";
					}
					else
					{
						if (WEAPONSLOCKER == 1) 
						{
							if (GET_WEAPONS_BACK == 1)
								Dialog.text = DLG_TEXT[23] + DLG_TEXT[24] + DLG_TEXT[26];
							else
								Dialog.text = DLG_TEXT[23] + DLG_TEXT[25] + DLG_TEXT[26];
								link.l1 = DLG_TEXT[18];
								link.l1.go = "Weaponslocker";
						}
						else
						{
							dialog.text = DLG_TEXT[27];
							link.l1 = DLG_TEXT[28];
							link.l1.go = "Swordplay";
						}
					}
				}
				else
				{
					Dialog.TempNode = "EquipWeapon";
					dialog.text = DLG_TEXT[31];
					link.l1 = DLG_TEXT[38];
					link.l1.go = "Exit";
				}
				link.l2 = DLG_TEXT[29];
				link.l2.go = "OutOfThisShip";
				link.l3 = DLG_TEXT[30];
				link.l3.go = "Skip_tutorial";
			}
		break;

		case "Weaponslocker":
			Dialog.text = DLG_TEXT[39] + GetItemNameByID(boarder_blade) + DLG_TEXT[40];
			Link.l1 = DLG_TEXT[41];
			Link.l1.go = "EquipWeaponslocker";
			Link.l2 = DLG_TEXT[42];
			Link.l2.go = "SkipWeaponslocker";
		break;

		case "EquipWeaponslocker":
			DeleteAttribute(TutDeck, "WeaponsLocker.items");	// LDH 01May09
			TakenItems(Pchar, boarder_blade, 12);
			NextDiag.TempNode = "EquipWeaponslocker_1";
			NextDiag.CurrentNode = NextDiag.Tempnode;
			DialogExit();
		break;

		case "EquipWeaponslocker_1":
			if (CheckAttribute(TutDeck, "WeaponsLocker.items." + boarder_blade) == false || TutDeck.WeaponsLocker.items.(boarder_blade) < 12)
				{
					NextDiag.TempNode = "EquipWeaponslocker_1";
					Dialog.text = DLG_TEXT[43];
					Link.l1 = DLG_TEXT[44];
					Link.l1.go = "Exit";
				}
			else 
				{
					dialog.text = DLG_TEXT[27];
					link.l1 = DLG_TEXT[28];
					link.l1.go = "Swordplay";
					link.l2 = DLG_TEXT[29];
					link.l2.go = "OutOfThisShip";
					link.l3 = DLG_TEXT[30];
					link.l3.go = "Skip_tutorial";
				}
		break;

		case "SkipWeaponslocker":
			TutDeck.WeaponsLocker.items.(boarder_blade) = 12;
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "Swordplay";
			link.l2 = DLG_TEXT[29];
			link.l2.go = "OutOfThisShip";
			link.l3 = DLG_TEXT[30];
			link.l3.go = "Skip_tutorial";
		break;

		case "Swordplay":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "Swordplay_1";
		break;

		case "Swordplay_1":
			addDialogExitQuest("Tut_WalkToSwordplayPlace");
			NextDiag.Tempnode = "NowHitMe";
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "Exit";
		break;

		case "NowHitMe":
			AddDialogExitQuest("Tut_FirstMeleeFight");
			NextDiag.Tempnode = "WhatAreYouWaitingFor";
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "NowHitMe_1";
		break;

		case "NowHitMe_1":
			NextDiag.Tempnode = "WhatAreYouWaitingFor";
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "Exit";
		break;

		case "WhatAreYouWaitingFor":
			NextDiag.Tempnode = "WhatAreYouWaitingFor";
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "Continue_ToSeriousFight";
			link.l2 = DLG_TEXT[55];
			link.l2.go = "WhatAreYouWaitingFor_1";
			link.l3 = DLG_TEXT[56];
			link.l3.go = "Skip_tutorial";
		break;

		case "HurtEnough":
			AddDialogExitQuest("player_back");
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "Continue_ToSeriousFight";
			link.l2 = DLG_TEXT[59];
			link.l2.go = "WhatAreYouWaitingFor_1";
			link.l3 = DLG_TEXT[56];
			link.l3.go = "Skip_tutorial";
		break;

		case "WhatAreYouWaitingFor_1":
			AddDialogExitQuest("Tut_FirstMeleeFight");
			NextDiag.Tempnode = "WhatAreYouWaitingFor";
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "Exit";
		break;

		case "Continue_ToSeriousFight":
			AddDialogExitQuest("Tut_StartSeriousFight");
			NextDiag.Tempnode = "WhatAreYouWaitingFor";
			dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "Exit";
		break;

		case "SeriousStopped":
			if(LAi_GetCharacterHP(Pchar) >= (LAi_GetCharacterHP(CharacterFromID("Malcolm Hatcher"))+50))
				{
					dialog.text = DLG_TEXT[64];
					link.l1 = DLG_TEXT[65];
					link.l1.go = "OutOfThisShip";
					link.l2 = DLG_TEXT[66];
					link.l2.go = "OnceAgain";
					link.l3 = DLG_TEXT[67];
					link.l3.go = "Skip_Tutorial";
				}
			else
				{
					dialog.text = DLG_TEXT[68];
					link.l1 = DLG_TEXT[69];
					link.l1.go = "OnceAgain";
					link.l2 = DLG_TEXT[70];
					link.l2.go = "OutOfThisShip";
					link.l3 = DLG_TEXT[71];
					link.l3.go = "Skip_Tutorial";
				}
		break;

		case "OnceAgain":
			AddDialogExitQuest("Tut_StartSeriousFightAgain");
			dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "Exit";
		break;

		case "SeriousStoppedAgain":
			if(LAi_GetCharacterHP(Pchar) >= (LAi_GetCharacterHP(CharacterFromID("Malcolm Hatcher"))+50))
				{
					dialog.text = DLG_TEXT[74];
					link.l1 = DLG_TEXT[75];
					link.l1.go = "OutOfThisShip";
					link.l2 = DLG_TEXT[76];
					link.l2.go = "OnceAgain";
					link.l3 = DLG_TEXT[77];
					link.l3.go = "Skip_Tutorial";
				}
			else
				{
					dialog.text = DLG_TEXT[78];
					link.l1 = DLG_TEXT[79];
					link.l1.go = "OnceAgain";
					link.l2 = DLG_TEXT[80];
					link.l2.go = "OutOfThisShip";
					link.l3 = DLG_TEXT[67];
					link.l3.go = "Skip_Tutorial";
				}
		break;

		case "OutOfThisShip":
			if (AUTO_SKILL_SYSTEM == 0)
				{
					dialog.text = DLG_TEXT[81];
					link.l1 = DLG_TEXT[82];
					link.l1.go = "DistributePoints";
				} 
			else 
				{
					dialog.text = DLG_TEXT[83];
					link.l1 = DLG_TEXT[84];
					link.l1.go = "EarnPoints";
				}
			link.l2 = DLG_TEXT[85];
			link.l2.go = "SkillDescription";
			link.l3 = DLG_TEXT[86];
			link.l3.go = "FuckTheSkillsLetsGo";
		break;

		case "DistributePoints":
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "DistributePoints_1";
			link.l2 = DLG_TEXT[89];
			link.l2.go = "FuckTheSkillsLetsGo";
			link.l3 = DLG_TEXT[85];
			link.l3.go = "SkillDescription";
		break;

		case "DistributePoints_1":
			NextDiag.TempNode = "ContinueAfterSkills";
			AddDialogExitQuest("Tut_PlayerDistributeSkills");
			dialog.text = DLG_TEXT[90];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Exit";
		break;

		case "EarnPoints":
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "ELeadership";
			link.l2 = DLG_TEXT[93];
			link.l2.go = "EMelee Combat";
			link.l3 = DLG_TEXT[94];
			link.l3.go = "ESailing";
			link.l4 = DLG_TEXT[95];
			link.l4.go = "EAccuracy";
			link.l5 = DLG_TEXT[96];
			link.l5.go = "ECannons";
			link.l6 = DLG_TEXT[97];
			link.l6.go = "EGrappling";
			link.l7 = DLG_TEXT[98];
			link.l7.go = "ERepair";
			link.l8 = DLG_TEXT[99];
			link.l8.go = "EDefense";
			link.l9 = DLG_TEXT[100];
			link.l9.go = "ECommerce";
			link.l10 = DLG_TEXT[101];
			link.l10.go = "Eluck";
		break;

		case "ELeadership":
			dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "EarnPoints";
			link.l2 = DLG_TEXT[85];
			link.l2.go = "SkillDescription";
			link.l3 = DLG_TEXT[104];
			link.l3.go = "FuckTheSkillsLetsGo";	
		break;

		case "EMelee Combat":
			dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "EarnPoints";
			link.l2 = DLG_TEXT[85];
			link.l2.go = "SkillDescription";
			link.l3 = DLG_TEXT[104];
			link.l3.go = "FuckTheSkillsLetsGo";	
		break;

		case "ESailing":
			dialog.text = DLG_TEXT[106];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "EarnPoints";
			link.l2 = DLG_TEXT[85];	
			link.l2.go = "SkillDescription";
			link.l3 = DLG_TEXT[104];
			link.l3.go = "FuckTheSkillsLetsGo";	
		break;

		case "EAccuracy":
			dialog.text = DLG_TEXT[107];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "EarnPoints";
			link.l2 = DLG_TEXT[85];
			link.l2.go = "SkillDescription";
			link.l3 = DLG_TEXT[104];
			link.l3.go = "FuckTheSkillsLetsGo";
		break;

		case "ECannons":
			dialog.text = DLG_TEXT[108];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "EarnPoints";
			link.l2 = DLG_TEXT[85];
			link.l2.go = "SkillDescription";
			link.l3 = DLG_TEXT[104];
			link.l3.go = "FuckTheSkillsLetsGo";
		break;

		case "EGrappling":
			dialog.text = DLG_TEXT[109];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "EarnPoints";
			link.l2 = DLG_TEXT[85];
			link.l2.go = "SkillDescription";
			link.l3 = DLG_TEXT[104];
			link.l3.go = "FuckTheSkillsLetsGo";
		break;

		case "ERepair":
			dialog.text = DLG_TEXT[110];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "EarnPoints";
			link.l2 = DLG_TEXT[85];
			link.l2.go = "SkillDescription";
			link.l3 = DLG_TEXT[104];
			link.l3.go = "FuckTheSkillsLetsGo";
		break;

		case "EDefense":
			dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "EarnPoints";
			link.l2 = DLG_TEXT[85];
			link.l2.go = "SkillDescription";
			link.l3 = DLG_TEXT[104];
			link.l3.go = "FuckTheSkillsLetsGo";
		break;

		case "ECommerce":
			dialog.text = DLG_TEXT[112];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "EarnPoints";
			link.l2 = DLG_TEXT[85];
			link.l2.go = "SkillDescription";
			link.l3 = DLG_TEXT[104];
			link.l3.go = "FuckTheSkillsLetsGo";
		break;

		case "Eluck":
			dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "EarnPoints";
			link.l2 = DLG_TEXT[85];
			link.l2.go = "SkillDescription";
			link.l3 = DLG_TEXT[104];
			link.l3.go = "FuckTheSkillsLetsGo";	
		break;

		case "ContinueAfterSkills":
			NextDiag.TempNode = "ContinueAfterSkills";
			dialog.text = DLG_TEXT[114];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "DistributePoints_1";
			link.l2 = DLG_TEXT[89];
			link.l2.go = "FuckTheSkillsLetsGo";
			link.l3 = DLG_TEXT[85];
			link.l3.go = "SkillDescription";
		break;

		case "SkillDescription":
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "Leadership";
			link.l2 = DLG_TEXT[93];
			link.l2.go = "Melee Combat";
			link.l3 = DLG_TEXT[94];
			link.l3.go = "Sailing";
			link.l4 = DLG_TEXT[95];
			link.l4.go = "Accuracy";
			link.l5 = DLG_TEXT[96];
			link.l5.go = "Cannons";
			link.l6 = DLG_TEXT[97];
			link.l6.go = "Grappling";
			link.l7 = DLG_TEXT[98];
			link.l7.go = "Repair";
			link.l8 = DLG_TEXT[99];
			link.l8.go = "Defence";
			link.l9 = DLG_TEXT[100];
			link.l9.go = "Commerce";
			link.l10 = DLG_TEXT[101];
			link.l10.go = "Luck";
		break;

		case "Leadership":
			dialog.text = DLG_TEXT[115];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "SkillDescription";
			link.l2 = DLG_TEXT[104];
			link.l2.go = "FuckTheSkillsLetsGo";
			if (AUTO_SKILL_SYSTEM == 0)
				{
					link.l3 = DLG_TEXT[116];
					link.l3.go = "DistributePoints_1";
				}
			else
				{
					link.l3 = DLG_TEXT[84];
					link.l3.go = "EarnPoints";
				}
		break;

		case "Melee Combat":
			dialog.text = DLG_TEXT[117];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "SkillDescription";
			link.l2 = DLG_TEXT[104];
			link.l2.go = "FuckTheSkillsLetsGo";
			if (AUTO_SKILL_SYSTEM == 0) 
				{
					link.l3 = DLG_TEXT[116];
					link.l3.go = "DistributePoints_1";
				}
			else 
				{
					link.l3 = DLG_TEXT[84];
					link.l3.go = "EarnPoints";
				}
		break;

		case "Sailing":
			dialog.text = DLG_TEXT[118];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "SkillDescription";
			link.l2 = DLG_TEXT[104];
			link.l2.go = "FuckTheSkillsLetsGo";
			if (AUTO_SKILL_SYSTEM == 0) 
				{
					link.l3 = DLG_TEXT[116];
					link.l3.go = "DistributePoints_1";
				}
			else
				{
					link.l3 = DLG_TEXT[84];
					link.l3.go = "EarnPoints";
				}
		break;

		case "Accuracy":
			dialog.text = DLG_TEXT[119];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "SkillDescription";
			link.l2 = DLG_TEXT[104];
			link.l2.go = "FuckTheSkillsLetsGo";
			if (AUTO_SKILL_SYSTEM == 0) 
				{
					link.l3 = DLG_TEXT[116];
					link.l3.go = "DistributePoints_1";
				}
			else 
				{
					link.l3 = DLG_TEXT[84];
					link.l3.go = "EarnPoints";
				}
		break;

		case "Cannons":
			dialog.text = DLG_TEXT[120];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "SkillDescription";
			link.l2 = DLG_TEXT[104];
			link.l2.go = "FuckTheSkillsLetsGo";
			if (AUTO_SKILL_SYSTEM == 0)
				{
					link.l3 = DLG_TEXT[116];
					link.l3.go = "DistributePoints_1";
				}
			else 
				{
					link.l3 = DLG_TEXT[84];
					link.l3.go = "EarnPoints";
				}
		break;

		case "Grappling":
			dialog.text = DLG_TEXT[121];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "SkillDescription";
			link.l2 = DLG_TEXT[104];
			link.l2.go = "FuckTheSkillsLetsGo";
			if (AUTO_SKILL_SYSTEM == 0)
				{
					link.l3 = DLG_TEXT[116];
					link.l3.go = "DistributePoints_1";
				}
			else 
				{
					link.l3 = DLG_TEXT[84];
					link.l3.go = "EarnPoints";
				}
		break;

		case "Repair":
			dialog.text = DLG_TEXT[122];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "SkillDescription";
			link.l2 = DLG_TEXT[104];
			link.l2.go = "FuckTheSkillsLetsGo";
			if (AUTO_SKILL_SYSTEM == 0)
				{
					link.l3 = DLG_TEXT[116];
					link.l3.go = "DistributePoints_1";
				}
			else
				{
					link.l3 = DLG_TEXT[84];
					link.l3.go = "EarnPoints";
				}
		break;

		case "Defence":
			dialog.text = DLG_TEXT[123];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "SkillDescription";
			link.l2 = DLG_TEXT[104];
			link.l2.go = "FuckTheSkillsLetsGo";
			if (AUTO_SKILL_SYSTEM == 0) 
				{
					link.l3 = DLG_TEXT[116];
					link.l3.go = "DistributePoints_1";
				}
			else 
				{
					link.l3 = DLG_TEXT[84];
					link.l3.go = "EarnPoints";
				}
		break;

		case "Commerce":
			dialog.text = DLG_TEXT[124];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "SkillDescription";
			link.l2 = DLG_TEXT[104];
			link.l2.go = "FuckTheSkillsLetsGo";
			if (AUTO_SKILL_SYSTEM == 0)
				{
					link.l3 = DLG_TEXT[116];
					link.l3.go = "DistributePoints_1";
				}
			else 
				{
					link.l3 = DLG_TEXT[84];
					link.l3.go = "EarnPoints";
				}
		break;

		case "Luck":
			dialog.text = DLG_TEXT[125];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "SkillDescription";
			link.l2 = DLG_TEXT[104];
			link.l2.go = "FuckTheSkillsLetsGo";
			if (AUTO_SKILL_SYSTEM == 0)
				{
					link.l3 = DLG_TEXT[116];
					link.l3.go = "DistributePoints_1";
				}
			else 
				{
					link.l3 = DLG_TEXT[84];
					link.l3.go = "EarnPoints";
				}
		break;

		case "FuckTheSkillsLetsGo":
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[127];
			link.l1.go = "TutorialTasks";
		break;

		case "TutorialTasks":
			dialog.text = DLG_TEXT[128];
			link.l1 = DLG_TEXT[129];
			link.l1.go = "TutorialTasks_1";
		break;

		case "TutorialTasks_1":
			dialog.text = DLG_TEXT[130];
			if (GetCurrentFlag() == ENGLAND) dialog.text = dialog.text + "\n" + DLG_TEXT[131];
			link.l1 = DLG_TEXT[132];
			if (PChar.location == "Tutorial_Deck")
				{
					addDialogExitQuest("Tut_WalkThroughQDeck");
					link.l1.go = "Exit";
				}
			else
				{
					addDialogExitQuest("Tut_ReloadToOxbayPort");
					link.l1.go = "Exit";
				}
		break;

		case "NowLetsBuyASpyglass":
			dialog.text = DLG_TEXT[133];
			link.l1 = DLG_TEXT[134];
			link.l1.go = "GuideToSpyglass";
			link.l2 = DLG_TEXT[135];
			link.l2.go = "ContinueWithoutSpyglass";
			link.l3 = DLG_TEXT[136];
			link.l3.go = "Skip_TutorialInPort";
		break;

		case "ToFdFCenter":
			dialog.text = DLG_TEXT[137];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "ToTheTown_1";
			link.l2 = DLG_TEXT[136];
			link.l2.go = "ToTheTown_2";
		break;

		case "ToQCTown":
			dialog.text = DLG_TEXT[138];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "ToTheTown_1";
			link.l2 = DLG_TEXT[136];
			link.l2.go = "ToTheTown_2";
		break;

		case "ToTheTown_1":
			AddDialogExitQuest("Tut_GuideToSpyglass");
			DialogExit();
		break;

		case "ToTheTown_2":
			AddDialogExitQuest("Tut_SkipTutorialInPort");
			DialogExit();
		break;

		case "NoStallsOnQC":
			dialog.text = DLG_TEXT[139];
			link.l1 = DLG_TEXT[134];
			link.l1.go = "GuideToSpyglass";
			link.l2 = DLG_TEXT[135];
			link.l2.go = "ContinueWithoutSpyglass";
			link.l3 = DLG_TEXT[136];
			link.l3.go = "Skip_TutorialInPort";
		break;

		case "GuideToSpyglass":
			if (GetCurrentFlag() != FRANCE && GetCurrentFlag() != PIRATE)
				AddDialogExitQuest("Tut_GuideToSpyglass");
			else
				AddDialogExitQuest("Tut_ToTheTown");
				dialog.text = DLG_TEXT[140];
				link.l1 = DLG_TEXT[141];
				link.l1.go = "Exit";
		break;

		case "HereAretheTraders":
			addDialogExitQuest("Tut_SoBuyTheFuckingGlass");
			NextDiag.TempNode = "SoBuyTheFuckingGlass";
			dialog.text = DLG_TEXT[142];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Exit";
		break;

		case "SoBuyTheFuckingGlass":
			if(CheckCharacterItem(Pchar, "spyglass2"))
			{
				dialog.text = DLG_TEXT[143];
				link.l1 = DLG_TEXT[144];
				if (GetCurrentFlag() == PIRATE)
					link.l1.go = "NowGoTotheStore_1";
				else
				{
					if (GetCurrentFlag() == AMERICA)
						link.l1.go = "NowGoTotheStore";
					else
						link.l1.go = "GoToStore";
				}
				link.l2 = DLG_TEXT[145];
				link.l2.go = "Skip_TutorialInPort";
			}
			else
			{
				NextDiag.TempNode = "SoBuyTheFuckingGlass";
				dialog.text = DLG_TEXT[146];
				link.l1 = DLG_TEXT[147];
				link.l1.go = "Exit";
				link.l2 = DLG_TEXT[148];
				link.l2.go = "ContinueWithoutSpyglass";
				link.l3 = DLG_TEXT[149];
				link.l3.go = "Skip_TutorialInPort";
			}
		break;

		case "ContinueWithoutSpyglass":
			dialog.text = DLG_TEXT[150];
			link.l1 = DLG_TEXT[144];
			if (GetCurrentFlag() == PIRATE)
			{
				PChar.quest.ContinueWithoutSpyglass = "1";
				link.l1.go = "NowGoTotheStore_1";
			} 
			else 
			{
				if (GetCurrentFlag() == AMERICA)
					link.l1.go = "NowGoTotheStore";
				else
					link.l1.go = "GoToStore";
			}
			link.l2 = DLG_TEXT[145];
			link.l2.go = "Skip_TutorialInPort";
		break;

		case "GoToStore":
			AddDialogExitQuest("Tut_ReloadToOxbay");
			if (GetCurrentFlag() == FRANCE)
				dialog.text = DLG_TEXT[151];
			else
				dialog.text = DLG_TEXT[152];
				link.l1 = DLG_TEXT[35];
				link.l1.go = "Exit";
		break;

		case "NowGoTotheStore":
			dialog.text = DLG_TEXT[153];
			link.l1 = DLG_TEXT[154];
			link.l1.go = "NowGoTotheStore_1";
			link.l2 = DLG_TEXT[155];
			link.l2.go = "Skip_tutorialInTown";
		break;

		case "NowGoTotheStore_1":
			AddDialogExitQuest("Tut_MalcolmShowsTheStore");
			dialog.text = DLG_TEXT[156];
			link.l1 = DLG_TEXT[132];
			link.l1.go = "Exit";
		break;

		case "MoreDetailsOnTrade":
			AddDialogExitQuest("Tut_StartTrading");
			if (GetCurrentFlag() != PIRATE || CheckQuestAttribute("ContinueWithoutSpyglass", "1"))
				dialog.text = DLG_TEXT[157];
			else
				dialog.text = DLG_TEXT[159];
			if (GetCargoGoods(Pchar, CharGood1) != 0) dialog.text = dialog.text + XI_ConvertString(Goods[CharGood1].name);
			if (GetCargoGoods(Pchar, CharGood2) != 0 && CharGood2 != CharGood1) dialog.text = dialog.text + DLG_TEXT[158] + XI_ConvertString(Goods[CharGood2].name);
			if (GetCurrentFlag() != PIRATE || CheckQuestAttribute("ContinueWithoutSpyglass", "1"))
				dialog.text = dialog.text + DLG_TEXT[160];
			else
				DeleteQuestAttribute("ContinueWithoutSpyglass");
				dialog.text = dialog.text + DLG_TEXT[161];
				link.l1 = DLG_TEXT[162];
				link.l1.go = "MoreDetailsOnTrade_1";
				link.l2 = DLG_TEXT[163];
				link.l2.go = "MoreDetailsOnTrade_2";
		break;

		case "MoreDetailsOnTrade_1":
			dialog.text = DLG_TEXT[164];
			link.l1 = DLG_TEXT[165];
			link.l1.go = "MoreDetailsOnTrade_2";
		break;

		case "MoreDetailsOnTrade_2":
			if (AUTO_SKILL_SYSTEM == 0)
			{
				dialog.text = DLG_TEXT[166];
			}
			else 
			{
				dialog.text = DLG_TEXT[167];
			}
			link.l1 = DLG_TEXT[168];
			link.l1.go = "exit";
		break;
		
		case "GoodsSoldInStore":
			if(GetCargoGoods(Pchar, CharGood1) != 0 || GetCargoGoods(Pchar, CharGood2) != 0) // KK
				{
					dialog.text = DLG_TEXT[169];
					link.l1 = DLG_TEXT[170];
					link.l1.go = "GoodsSoldInStore_1";
					link.l2 = DLG_TEXT[171];
					link.l2.go = "Skip_TutorialInTown";
				}
			else
				{
					dialog.text = DLG_TEXT[172];
					link.l1 = DLG_TEXT[35];
					link.l1.go = "GoodsSoldInStore_1";
					link.l2 = DLG_TEXT[171];
					link.l2.go = "Skip_TutorialInTown";
				}
			if (GetCurrentFlag() == FRANCE) dialog.text = dialog.text + DLG_TEXT[295];
		break;

		case "GoodsSoldInStore_1":
			AddDialogExitQuest("Tut_MalcolmLeadsToTavern");
			dialog.text = DLG_TEXT[173];
			link.l1 = DLG_TEXT[174];
			link.l1.go = "exit";
		break;

		case "CrewHiringInTavern":
			dialog.text = DLG_TEXT[175];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "CrewHiringInTavern_1";
		break;

		case "CrewHiringInTavern_1":
			addDialogExitQuest("Tut_MalcolmLeavesTavern");
			dialog.text = DLG_TEXT[176];
			link.l1 = DLG_TEXT[177];
			link.l1.go = "exit";
		break;

		case "CrewHiredintavern":
			if(GetMaxCrewQuantity(Pchar) == GetCrewQuantity(Pchar))
				{
					dialog.text = DLG_TEXT[178];
					link.l1 = DLG_TEXT[179];
					link.l1.go = "CrewHiredintavern_1";
					link.l2 = DLG_TEXT[180];
					link.l2.go = "Skip_TutorialInTown";
				}
			else
				{
					dialog.text = DLG_TEXT[181];
					link.l1 = DLG_TEXT[179];
					link.l1.go = "CrewHiredintavern_1";
					link.l2 = DLG_TEXT[180];
					link.l2.go = "Skip_TutorialInTown";
				}
		break;

		case "CrewHiredintavern_1":
			AddDialogExitQuest("Tut_BooGoForShipyard");
			dialog.text = DLG_TEXT[182];
			link.l1 = DLG_TEXT[183];
			link.l1.go = "exit";
		break;

		case "ShipRepairing":
			dialog.text = DLG_TEXT[184];
			link.l1 = DLG_TEXT[185];
			link.l1.go = "ShipRepairing_1";
			link.l2 = DLG_TEXT[186];
			link.l2.go = "ShipRepairing_2";
		break;

		case "ShipRepairing_1":
			dialog.text = DLG_TEXT[187];
			link.l1 = DLG_TEXT[188];
			link.l1.go = "ShipRepairing_2";
		break;

		case "ShipRepairing_2":
			AddDialogExitQuest("Tut_MalcolmLeavesShipyard");
			dialog.text = DLG_TEXT[189];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
		break;

		case "FinalStage":
			DeleteAttribute(&PChar,"vcskip"); // NK 04-06
			if (GetCharacterShipCabin(PChar) != "Cabin_none")
				dialog.text = DLG_TEXT[190];
			else
				dialog.text = DLG_TEXT[191];
				link.l1 = DLG_TEXT[192];
				link.l1.go = "FinalStage_1";
		break;

		case "FinalStage_1":
			dialog.text = DLG_TEXT[193];
			link.l1 = DLG_TEXT[194];
			link.l1.go = "Suggestions";
			link.l2 = DLG_TEXT[195];
			link.l2.go = "Ship_sailing";
			link.l3 = DLG_TEXT[196];
			link.l3.go = "CannonFire";
			link.l4 = DLG_TEXT[197];
			link.l4.go = "BoardingShips";
			link.l5 = DLG_TEXT[198];
			link.l5.go = "Salary";
			link.l6 = DLG_TEXT[199];
			link.l6.go = "Direct_Sailing";
			link.l7 = DLG_TEXT[200];
			link.l7.go = "Morale";
			link.l8 = DLG_TEXT[201];
			link.l8.go = "Flags";
			link.l9 = DLG_TEXT[202];
			link.l9.go = "Final_Goodbye";
		break;

		case "Suggestions":
			string good1 = "";
			string good2 = "";
			string colony1 = "";
			string colony2 = "";
			FindProfitableRoute(&good1, &colony1, &good2, &colony2);
			string aboutColony = good2 + DLG_TEXT[203] + colony2;
			if(colony1 == "nowhere") colony1 = "";
			if(colony2 == "nowhere") aboutColony = "..";
			if (colony1 != "")
				dialog.text = DLG_TEXT[204] + good1 + DLG_TEXT[158] + good2 + DLG_TEXT[205] + colony1 + DLG_TEXT[206] + good1 + DLG_TEXT[207] + aboutColony + ".";
			else
				dialog.text = DLG_TEXT[208];
				link.l1 = DLG_TEXT[195];
				link.l1.go = "Ship_sailing";
				link.l2 = DLG_TEXT[196];
				link.l2.go = "CannonFire";
				link.l3 = DLG_TEXT[197];
				link.l3.go = "BoardingShips";
				link.l4 = DLG_TEXT[198];
				link.l4.go = "Salary";
				link.l5 = DLG_TEXT[199];
				link.l5.go = "Direct_Sailing";
				link.l6 = DLG_TEXT[200];
				link.l6.go = "Morale";
				link.l7 = DLG_TEXT[201];
				link.l7.go = "Flags";
				link.l8 = DLG_TEXT[202];
				link.l8.go = "Final_Goodbye";
		break;

		case "Skip_tutorial":
			dialog.text = DLG_TEXT[209];
			link.l1 = DLG_TEXT[127];
			link.l1.go = "Skip_tutorial_1";
		break;

		case "Skip_tutorial_1":
			dialog.text = DLG_TEXT[128];
			link.l1 = DLG_TEXT[129];
			link.l1.go = "Skip_tutorial_2";
		break;

		case "Skip_tutorial_2":
			bDisableFastReload = 0;
			addDialogExitQuest("Tut_SkipTutorialOnShip");
			NextDiag.Tempnode = "Questions";
			dialog.text = DLG_TEXT[210];
//			if (GetCurrentFlag() == ENGLAND && GetServedNation() != ENGLAND) dialog.text = dialog.text + "\n" + DLG_TEXT[211];
			dialog.text = dialog.text + DLG_TEXT[212];
			link.l1 = DLG_TEXT[213];
			link.l1.go = "Exit";
		break;

		case "Skip_TutorialInPort":
			addDialogExitQuest("Tut_SkipTutorialInPort");
			dialog.text = DLG_TEXT[214];
			link.l1 = DLG_TEXT[192];
			link.l1.go = "Skip_TutorialInPort_1";
		break

		case "Skip_TutorialInPort_1":
			dialog.text = DLG_TEXT[193];
			link.l1 = DLG_TEXT[215];
			link.l1.go = "Suggestions";
			link.l2 = DLG_TEXT[195];
			link.l2.go = "Ship_sailing";
			link.l3 = DLG_TEXT[196];
			link.l3.go = "CannonFire";
			link.l4 = DLG_TEXT[197];
			link.l4.go = "BoardingShips";
			link.l5 = DLG_TEXT[198];
			link.l5.go = "Salary";
			link.l6 = DLG_TEXT[199];
			link.l6.go = "Direct_Sailing";
			link.l7 = DLG_TEXT[200];
			link.l7.go = "Morale";
			link.l8 = DLG_TEXT[201];
			link.l8.go = "Flags";
			link.l9 = DLG_TEXT[202];
			link.l9.go = "Final_Goodbye";
		break;

		case "Skip_TutorialInTown":
			bDisableFastReload = 0;
			addDialogExitQuest("Tut_SkipTutorialInTown");
			dialog.text = DLG_TEXT[214];
			link.l1 = DLG_TEXT[192];
			link.l1.go = "Skip_TutorialInTown_1";
		break;

		case "Skip_TutorialInTown_1":
			dialog.text = DLG_TEXT[193];
			link.l1 = DLG_TEXT[215];
			link.l1.go = "Suggestions";
			link.l2 = DLG_TEXT[195];
			link.l2.go = "Ship_sailing";
			link.l3 = DLG_TEXT[196];
			link.l3.go = "CannonFire";
			link.l4 = DLG_TEXT[197];
			link.l4.go = "BoardingShips";
			link.l5 = DLG_TEXT[198];
			link.l5.go = "Salary";
			link.l6 = DLG_TEXT[199];
			link.l6.go = "Direct_Sailing";
			link.l7 = DLG_TEXT[200];
			link.l7.go = "Morale";
			link.l8 = DLG_TEXT[201];
			link.l8.go = "Flags";
			link.l9 = DLG_TEXT[202];
			link.l9.go = "Final_Goodbye";
		break;

		case "Ship_sailing":
			dialog.text = DLG_TEXT[216];
			link.l1 = DLG_TEXT[196];
			link.l1.go = "CannonFire";
			link.l2 = DLG_TEXT[197];
			link.l2.go = "BoardingShips";
			link.l3 = DLG_TEXT[198];
			link.l3.go = "Salary";
			link.l4 = DLG_TEXT[199];
			link.l4.go = "Direct_Sailing";
			link.l5 = DLG_TEXT[200];
			link.l5.go = "Morale";
			link.l6 = DLG_TEXT[201];
			link.l6.go = "Flags";
			link.l7 = DLG_TEXT[202];
			link.l7.go = "Final_Goodbye";
		break;

		case "CannonFire":
			dialog.text = DLG_TEXT[217];
			link.l1 = DLG_TEXT[197];
			link.l1.go = "BoardingShips";
			link.l2 = DLG_TEXT[198];
			link.l2.go = "Salary";
			link.l3 = DLG_TEXT[199];
			link.l3.go = "Direct_Sailing";
			link.l4 = DLG_TEXT[200];
			link.l4.go = "Morale";
			link.l5 = DLG_TEXT[201];
			link.l5.go = "Flags";
			link.l6 = DLG_TEXT[195];
			link.l6.go = "Ship_sailing";
			link.l7 = DLG_TEXT[202];
			link.l7.go = "Final_Goodbye";
		break;

		case "BoardingShips":
			dialog.text = DLG_TEXT[218];
			link.l1 = DLG_TEXT[198];
			link.l1.go = "Salary";
			link.l2 = DLG_TEXT[199];
			link.l2.go = "Direct_Sailing";
			link.l3 = DLG_TEXT[200];
			link.l3.go = "Morale";
			link.l4 = DLG_TEXT[201];
			link.l4.go = "Flags";
			link.l5 = DLG_TEXT[195];
			link.l5.go = "Ship_sailing";
			link.l6 = DLG_TEXT[196];
			link.l6.go = "CannonFire";
			link.l7 = DLG_TEXT[202];
			link.l7.go = "Final_Goodbye";
		break;
		
		case "Salary":
			dialog.text = DLG_TEXT[219];
			link.l1 = DLG_TEXT[220];
			link.l1.go = "Salary_1";
		break;
		
		case "Salary_1":
			dialog.text = DLG_TEXT[222];
			link.l1 = DLG_TEXT[221];
			link.l1.go = "Salary_2";
		break;

		case "Salary_2":
			dialog.text = DLG_TEXT[223];
			link.l1 = DLG_TEXT[199];
			link.l1.go = "Direct_Sailing";
			link.l2 = DLG_TEXT[200];
			link.l2.go = "Morale";
			link.l3 = DLG_TEXT[201];
			link.l3.go = "Flags";
			link.l4 = DLG_TEXT[195];
			link.l4.go = "Ship_sailing";
			link.l5 = DLG_TEXT[196];
			link.l5.go = "CannonFire";
			link.l6 = DLG_TEXT[197];
			link.l6.go = "BoardingShips";
			link.l7 = DLG_TEXT[202];
			link.l7.go = "Final_Goodbye";
		break;

		case "Direct_Sailing":
			dialog.text = DLG_TEXT[224];
			link.l1 = DLG_TEXT[200];
			link.l1.go = "Morale";
			link.l2 = DLG_TEXT[201];
			link.l2.go = "Flags";
			link.l3 = DLG_TEXT[195];
			link.l3.go = "Ship_sailing";
			link.l4 = DLG_TEXT[196];
			link.l4.go = "CannonFire";
			link.l5 = DLG_TEXT[197];
			link.l5.go = "BoardingShips";
			link.l6 = DLG_TEXT[198];
			link.l6.go = "Salary";
			link.l7 = DLG_TEXT[202];
			link.l7.go = "Final_Goodbye";
		break;

		case "Morale":
			dialog.text = DLG_TEXT[225];
			link.l1 = DLG_TEXT[201];
			link.l1.go = "Flags";
			link.l2 = DLG_TEXT[195];
			link.l2.go = "Ship_sailing";
			link.l3 = DLG_TEXT[196];
			link.l3.go = "CannonFire";
			link.l4 = DLG_TEXT[197];
			link.l4.go = "BoardingShips";
			link.l5 = DLG_TEXT[198];
			link.l5.go = "Salary";
			link.l6 = DLG_TEXT[199];
			link.l6.go = "Direct_Sailing";
			link.l7 = DLG_TEXT[202];
			link.l7.go = "Final_Goodbye";
		break;

		case "Flags":
			dialog.text = DLG_TEXT[226];
			link.l1 = DLG_TEXT[195];
			link.l1.go = "Ship_sailing";
			link.l2 = DLG_TEXT[196];
			link.l2.go = "CannonFire";
			link.l3 = DLG_TEXT[197];
			link.l3.go = "BoardingShips";
			link.l4 = DLG_TEXT[198];
			link.l4.go = "Salary";
			link.l5 = DLG_TEXT[199];
			link.l5.go = "Direct_Sailing";
			link.l6 = DLG_TEXT[200];
			link.l6.go = "Morale";
			link.l7 = DLG_TEXT[202];
			link.l7.go = "Final_Goodbye";
		break;

		case "Final_Goodbye":
			if (Locations[FindLoadedLocation()].type != "tavern") AddDialogExitQuest("Tut_SkipTutorialInTown");
			NextDiag.Tempnode = "Questions";
			string locTavern = DLG_TEXT[227];
			if(Locations[FindLoadedLocation()].type != "tavern") locTavern += DLG_TEXT[212];
			dialog.text = locTavern;
			if (GetCurrentFlag() == ENGLAND) dialog.text = dialog.text + "\n" + DLG_TEXT[211];
			link.l1 = DLG_TEXT[228];
			link.l1.go = "Exit";
		break;

		case "Questions":
			dialog.text = DLG_TEXT[229];
			link.l1 = DLG_TEXT[215];
			link.l1.go = "Suggestions";
			link.l2 = DLG_TEXT[195];
			link.l2.go = "Ship_sailing";
			link.l3 = DLG_TEXT[196];
			link.l3.go = "CannonFire";
			link.l4 = DLG_TEXT[197];
			link.l4.go = "BoardingShips";
			link.l5 = DLG_TEXT[198];
			link.l5.go = "Salary";
			link.l6 = DLG_TEXT[199];
			link.l6.go = "Direct_Sailing";
			link.l7 = DLG_TEXT[200];
			link.l7.go = "Morale";
			link.l8 = DLG_TEXT[201];
			link.l8.go = "Flags";
			link.l9 = DLG_TEXT[202];
			link.l9.go = "Goodbye";
		break;
		
		case "Goodbye":
			NextDiag.Tempnode = "Questions";
			locTavern = DLG_TEXT[227];
			if(Locations[FindLoadedLocation()].type != "tavern") locTavern += DLG_TEXT[212];
			dialog.text = locTavern;
			link.l1 = DLG_TEXT[228];
			link.l1.go = "Exit";
		break;

		case "stormystart":
			PlayStereoSound("sails_up");
			addDialogExitQuest("stormystart");
			DialogExit();
			bChangeNation = true;
		break;

		case "no_duel":
			PlayStereoSound("sails_up");
			AddDialogExitQuest("no_duel");
			DialogExit();
			bChangeNation = true;
		break;

		case "OnMalcolmShip":
			dialog.text = DLG_TEXT[230] + XI_ConvertString(GetShipTypeName(PChar)) + DLG_TEXT[231] + GetMyShipNameShow(PChar) + DLG_TEXT[232];
			link.l1 = DLG_TEXT[233] + XI_ConvertString(GetShipTypeName(NPChar)) + ", '" + NPChar.ship.name + "'" + DLG_TEXT[141];
			link.l1.go = "OnMalcolmShip_1";
			link.l2 = DLG_TEXT[234];
			link.l2.go = "stormystart";
		break;

		case "OnMalcolmShip_1":
			dialog.text = DLG_TEXT[235];
			link.l1 = DLG_TEXT[236];
			link.l1.go = "OnMalcolmShip_2";
			link.l2 = DLG_TEXT[237];
			link.l2.go = "Skip_tutorial";
		break;

		case "OnMalcolmShip_2":
			addDialogExitQuest("Tut_TakeStuff");
			NextDiag.TempNode = "TakeWeapon";
			dialog.text = DLG_TEXT[238];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "Exit";
		break;

		case "SkipTutorialOnShip":
			NextDiag.TempNode = "SkipTutorialOnShip";
			dialog.text = DLG_TEXT[239];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Exit";
		break;

		case "naval_part2":
			dialog.text = DLG_TEXT[243];
			link.l1 = DLG_TEXT[244];
			link.l1.go = "naval_part3";
		break;

		case "naval_part3":
			dialog.text = DLG_TEXT[245] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, true) + ".";
			link.l1 = DLG_TEXT[246];
			link.l1.go = "stormystart";
		break;

		case "agent_start2":
			ref agent = CharacterFromID("TQ_Char1");
			if (rand(100) < FEMALE_OFFICER_PERCENTAGE) agent.sex = "woman";
			else agent.sex = "man";
			// First set contact's real name according to real nation
			agent.nation = NPChar.nation;
			SetRandomNameToCharacter(agent);
			agent.old.name = agent.name;
			if (CheckAttribute(agent, "middlename")) agent.old.middlename = agent.middlename;
			agent.old.lastname = agent.lastname;

			// Now set contact's fake nation and name
			agent.nation = FindEnemyNation2Nation(sti(NPChar.nation));
			SetRandomNameToCharacter(agent);
			PChar.quest.agent_start.officername = GetMyFullName(NPChar);

			dialog.text = DLG_TEXT[283] + GetMySimpleName(agent) + DLG_TEXT[284] + FirstLetterUp(XI_ConvertString(GetMyPronounPossessive(agent))) + DLG_TEXT[285] + GetMySimpleOldName(agent) + DLG_TEXT[286] + GetMyPronounSubj(agent) + DLG_TEXT[287] + FirstLetterUp(GetMyPronounSubj(agent)) + DLG_TEXT[288];
			link.l1 = DLG_TEXT[289];
			link.l1.go = "stormystart";
		break;
		
		case "exit":
			NextDiag.CurrentNode = NextDiag.Tempnode;
			DialogExit();
		break;
	}
}