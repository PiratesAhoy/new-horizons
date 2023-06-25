//#include "DIALOGS\Pierre Delacroix_dialog.h"

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
		// -----------------------------------Диалог первый - первая встреча
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
			link.l1 = DLG_TEXT[1];
			link.l1.go = "begin_1";

			if(ENABLE_CHEATMODE)
			{
				link.l2 = DLG_TEXT[12];
				link.l2.go = "Bart_part2";
				link.l3 = DLG_TEXT[13];
				link.l3.go = "Bart_part3";
				link.l4 = DLG_TEXT[14];
				link.l4.go = "Bart_part4";
				link.l5 = DLG_TEXT[15];
				link.l5.go = "Bart_part5";
				link.l6 = DLG_TEXT[16];
				link.l6.go = "Bart_part6";
				link.l7 = DLG_TEXT[17];
				link.l7.go = "Bart_part7";
				link.l8 = DLG_TEXT[18];
				link.l8.go = "Bart_part8";
				link.l9 = DLG_TEXT[19];
				link.l9.go = "Bart_part9";				
				link.l10 = DLG_TEXT[20];
				link.l10.go = "Bart_part10";
				link.l11 = DLG_TEXT[21];
				link.l11.go = "Bart_part11";
				link.l12 = DLG_TEXT[22];
				link.l12.go = "Bart_part12";					
				link.l13 = DLG_TEXT[23];
				link.l13.go = "Bart_part13";
			}
		break;

		case "Bart_part2":
            ChangeCharacterAddressGroup(CharacterFromID("PoPrince_soldier_05"), "PoPrince_town", "goto", "goto21");
			LAi_SetGuardianType(CharacterFromID("PoPrince_soldier_05"));
			LAi_group_MoveCharacter(CharacterFromID("PoPrince_soldier_05"), "FRANCE_SOLDIERS");
	        setCharacterShipLocation(characterFromID("Portuguese Captain"), "none");			
			locations[FindLocation("PoPrince_town")].reload.l2.disable = 0;
            characters[GetCharacterIndex("Eugene Martin")].nation = FRANCE; // KK
            LAi_group_MoveCharacter(CharacterFromID("Eugene Martin"), "FRANCE_CITIZENS"); // KK
			
			GiveShip2Character(pchar,"Barque3_50","La Chanceuse",-1,PIRATE,true,true);
			SetCharacterShipLocation(Pchar, "Hispaniola_shore_02");
			PlaceFleetNearShore("Hispaniola_shore_02"); // KK	

			AddQuestRecord("ArrivedatPOP", "6");
			CloseQuestHeader("ArrivedatPOP");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }

			GiveItem2Character(PChar, "map");
        	TakeNItems(PChar, "mapDouwesen", 1);			
			ChangeCharacterAddressGroup(CharacterFromID("Pierre Delacroix"), "none", "", "");
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Emilio Soares"));			
            DoQuestReloadToLocation("Buccaneers_Camp", "reload", "reload6", "_");
			
            AddDialogExitQuest("rencrox");			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;			
		break;		
		
		case "Bart_part3":
            ChangeCharacterAddressGroup(CharacterFromID("PoPrince_soldier_05"), "PoPrince_town", "goto", "goto21");
			LAi_SetGuardianType(CharacterFromID("PoPrince_soldier_05"));
			LAi_group_MoveCharacter(CharacterFromID("PoPrince_soldier_05"), "FRANCE_SOLDIERS");
	        setCharacterShipLocation(characterFromID("Portuguese Captain"), "none");			
			locations[FindLocation("PoPrince_town")].reload.l2.disable = 0;
            characters[GetCharacterIndex("Eugene Martin")].nation = FRANCE; // KK
            LAi_group_MoveCharacter(CharacterFromID("Eugene Martin"), "FRANCE_CITIZENS"); // KK
			
			GiveShip2Character(pchar,"Barque3_50","La Chanceuse",-1,PIRATE,true,true);
			SetCharacterShipLocation(Pchar, "Conceicao_port");
            GiveModel2Player("GypsyCaptn_3", true);			
            DoQuestReloadToLocation("Conceicao_townhall", "reload", "reload1", "_");

			CloseQuestHeader("ArrivedatPOP");
			SetQuestHeader("Expedition");			
			AddQuestRecord("Expedition", "3");
			CloseQuestHeader("Expedition");			
			
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
		
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Emilio Soares"));
			
			GiveItem2Character(PChar, "map");
        	TakeNItems(PChar, "mapDouwesen", 1);
			SetRMRelation(PChar, SPAIN, REL_WAR);		
            Build_at("Santiago_port", "Sign", "", 18.86, 6.13, 25.9, 1.7, "building");
            Locations[FindLocation("Santiago_Town_01")].dangerous = true;
			pchar.quest.BadBlaze = "debut";
			
			ChangeCharacterAddressGroup(CharacterFromID("Pierre Delacroix"), "none", "", "_");
			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;			
		break;

		case "Bart_part4":
            ChangeCharacterAddressGroup(CharacterFromID("PoPrince_soldier_05"), "PoPrince_town", "goto", "goto21");
			LAi_SetGuardianType(CharacterFromID("PoPrince_soldier_05"));
			LAi_group_MoveCharacter(CharacterFromID("PoPrince_soldier_05"), "FRANCE_SOLDIERS");
	        setCharacterShipLocation(characterFromID("Portuguese Captain"), "none");			
			locations[FindLocation("PoPrince_town")].reload.l2.disable = 0;
            characters[GetCharacterIndex("Eugene Martin")].nation = FRANCE; // KK
            LAi_group_MoveCharacter(CharacterFromID("Eugene Martin"), "FRANCE_CITIZENS"); // KK
			
			GiveShip2Character(pchar,"Ketch","l'Insouciante",-1,PIRATE,true,true);
			SetCharacterShipLocation(Pchar, "Hispaniola_shore_02");
            DoQuestReloadToLocation("Buccaneers_Camp", "reload", "reload6", "_");
            GiveModel2Player("GypsyCaptn_3", true); 			

			CloseQuestHeader("ArrivedatPOP");
			SetQuestHeader("Bad_Blaze");			
			AddQuestRecord("Bad_Blaze", "9");
			CloseQuestHeader("Bad_Blaze");				
			
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }

			AddMoneyToCharacter(pchar, 40000);			
			GiveItem2Character(Pchar, "bladeBP");
			GiveItem2Character(PChar, "map");
        	TakeNItems(PChar, "mapDouwesen", 1);
			SetRMRelation(PChar, SPAIN, REL_WAR);		
            Build_at("Santiago_port", "Sign", "", 18.86, 6.13, 25.9, 1.7, "building");
            Locations[FindLocation("Santiago_Town_01")].dangerous = true;

			Pchar.quest.find_ketch.win_condition.l1 = "location";
			Pchar.quest.find_ketch.win_condition.l1.location = "Hispaniola_shore_02";
			PChar.quest.find_ketch.win_condition = "gocuba_1";			
			
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Emilio Soares"));			
			ChangeCharacterAddressGroup(CharacterFromID("Pierre Delacroix"), "none", "", "");
			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;			
		break;
		
		case "Bart_part5":
            ChangeCharacterAddressGroup(CharacterFromID("PoPrince_soldier_05"), "PoPrince_town", "goto", "goto21");
			LAi_SetGuardianType(CharacterFromID("PoPrince_soldier_05"));
			LAi_group_MoveCharacter(CharacterFromID("PoPrince_soldier_05"), "FRANCE_SOLDIERS");
	        setCharacterShipLocation(characterFromID("Portuguese Captain"), "none");			
			locations[FindLocation("PoPrince_town")].reload.l2.disable = 0;
            characters[GetCharacterIndex("Eugene Martin")].nation = FRANCE; // KK
            LAi_group_MoveCharacter(CharacterFromID("Eugene Martin"), "FRANCE_CITIZENS"); // KK
			
            GiveShip2Character(pchar,"PO_Fleut50","Anaconda",-1,SPAIN,true,true);	
			SetCharacterShipLocation(Pchar, "Santo_Domingo_port");	
			QuestToSeaLogin_PrepareLoc("Hispaniola", "reload", "reload_4", true);
			QuestToSeaLogin_Launch();				
			
			CloseQuestHeader("ArrivedatPOP");
			SetQuestHeader("Anaconda_Capture");			
			AddQuestRecord("Anaconda_Capture","6");
			CloseQuestHeader("Anaconda_Capture");
			
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }

			GiveItem2Character(Pchar, "bladeBP");
			AddMoneyToCharacter(pchar, 40000);
			GiveItem2Character(PChar, "map");
        	TakeNItems(PChar, "mapDouwesen", 1);			
			ChangeCharacterAddressGroup(CharacterFromID("Pierre Delacroix"), "none", "", "");
            GiveModel2Player("GypsyCaptn_3", true);

			SetRMRelation(PChar, SPAIN, REL_WAR);		
            Build_at("Santiago_port", "Sign", "", 18.86, 6.13, 25.9, 1.7, "building");
            Locations[FindLocation("Santiago_Town_01")].dangerous = true;			
			
            AddDialogExitQuest("gokhael");
			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;			
		break;

		case "Bart_part6":
            ChangeCharacterAddressGroup(CharacterFromID("PoPrince_soldier_05"), "PoPrince_town", "goto", "goto21");
			LAi_SetGuardianType(CharacterFromID("PoPrince_soldier_05"));
			LAi_group_MoveCharacter(CharacterFromID("PoPrince_soldier_05"), "FRANCE_SOLDIERS");
	        setCharacterShipLocation(characterFromID("Portuguese Captain"), "none");			
			locations[FindLocation("PoPrince_town")].reload.l2.disable = 0;
            characters[GetCharacterIndex("Eugene Martin")].nation = FRANCE; // KK
            LAi_group_MoveCharacter(CharacterFromID("Eugene Martin"), "FRANCE_CITIZENS"); // KK

			SetNextWeather("Day storm");				
			
			CloseQuestHeader("ArrivedatPOP");
			SetQuestHeader("Bad_Luck");			
			AddQuestRecord("Bad_Luck","1");
			
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }

			GiveItem2Character(Pchar, "bladeBP");
			AddMoneyToCharacter(pchar, 40000);
			GiveItem2Character(PChar, "map");
        	TakeNItems(PChar, "mapDouwesen", 1);			
			ChangeCharacterAddressGroup(CharacterFromID("Pierre Delacroix"), "none", "", "");
            GiveModel2Player("GypsyCaptn_3", true);

			SetRMRelation(PChar, SPAIN, REL_WAR);		
            Build_at("Santiago_port", "Sign", "", 18.86, 6.13, 25.9, 1.7, "building");
            Locations[FindLocation("Santiago_Town_01")].dangerous = true;			
			
            AddDialogExitQuest("ouragan2");
			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;			
		break;
		
		case "Bart_part7":
            ChangeCharacterAddressGroup(CharacterFromID("PoPrince_soldier_05"), "PoPrince_town", "goto", "goto21");
			LAi_SetGuardianType(CharacterFromID("PoPrince_soldier_05"));
			LAi_group_MoveCharacter(CharacterFromID("PoPrince_soldier_05"), "FRANCE_SOLDIERS");
	        setCharacterShipLocation(characterFromID("Portuguese Captain"), "none");			
			locations[FindLocation("PoPrince_town")].reload.l2.disable = 0;
            characters[GetCharacterIndex("Eugene Martin")].nation = FRANCE; // KK
            LAi_group_MoveCharacter(CharacterFromID("Eugene Martin"), "FRANCE_CITIZENS"); // KK
			
            GiveShip2Character(pchar,"LuggerVML","Fancy",-1,ENGLAND,true,true);	
			SetCharacterShipLocation(Pchar, "Guadeloupe_Port");	

			SetRMRelation(PChar, SPAIN, REL_WAR);		
            Build_at("Santiago_port", "Sign", "", 18.86, 6.13, 25.9, 1.7, "building");
            Locations[FindLocation("Santiago_Town_01")].dangerous = true;			

            Build_at("Cuba_port", "Sign", "", 76.75, 17.03, -115.38, 1.7, "building");
            Locations[FindLocation("Havana_town_02")].dangerous = true;
    		Locations[FindLocation("Cuba_port")].dangerous = true;  
    		Locations[FindLocation("Santiago_port")].dangerous = true;
    		ChangeRMRelation(pchar, SPAIN, -20.0);			
			
			CloseQuestHeader("ArrivedatPOP");						
			
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
		
			GiveItem2Character(Pchar, "bladeBP");
			AddMoneyToCharacter(pchar, 40000);
			GiveItem2Character(PChar, "map");
        	TakeNItems(PChar, "mapDouwesen", 1);			
			ChangeCharacterAddressGroup(CharacterFromID("Pierre Delacroix"), "none", "", "");
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Emilio Soares"));
            DoQuestReloadToLocation("Guadeloupe_Port", "reload", "reload2_back", "MySantiago_start");
			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;			
		break;

		case "Bart_part8":
            ChangeCharacterAddressGroup(CharacterFromID("PoPrince_soldier_05"), "PoPrince_town", "goto", "goto21");
			LAi_SetGuardianType(CharacterFromID("PoPrince_soldier_05"));
			LAi_group_MoveCharacter(CharacterFromID("PoPrince_soldier_05"), "FRANCE_SOLDIERS");
	        setCharacterShipLocation(characterFromID("Portuguese Captain"), "none");			
			locations[FindLocation("PoPrince_town")].reload.l2.disable = 0;
            characters[GetCharacterIndex("Eugene Martin")].nation = FRANCE; // KK
            LAi_group_MoveCharacter(CharacterFromID("Eugene Martin"), "FRANCE_CITIZENS"); // KK
			
            GiveShip2Character(pchar,"FastCaravel","Santiago",-1,PIRATE,true,true);				
			SetCharacterShipLocation(Pchar, "Guadeloupe_shore_01");	

			SetRMRelation(PChar, SPAIN, REL_WAR);		
            Build_at("Santiago_port", "Sign", "", 18.86, 6.13, 25.9, 1.7, "building");
            Locations[FindLocation("Santiago_Town_01")].dangerous = true;			

            Build_at("Cuba_port", "Sign", "", 76.75, 17.03, -115.38, 1.7, "building");
            Locations[FindLocation("Havana_town_02")].dangerous = true;
    		Locations[FindLocation("Cuba_port")].dangerous = true;  
    		Locations[FindLocation("Santiago_port")].dangerous = true;
    		ChangeRMRelation(pchar, SPAIN, -20.0);
            GiveModel2Player("GypsyCaptn_4", true);					
			
			CloseQuestHeader("ArrivedatPOP");
			
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
		
			GiveItem2Character(Pchar, "bladeBP");
			AddMoneyToCharacter(pchar, 40000);
			GiveItem2Character(PChar, "map");
        	TakeNItems(PChar, "mapDouwesen", 1);			
			ChangeCharacterAddressGroup(CharacterFromID("Pierre Delacroix"), "none", "", "");
			DoQuestReloadToLocation("Guadeloupe_shore_01", "goto", "citizen03", "_");			
			SetOfficersIndex(PChar, 1, GetCharacterIndex("Emilio Soares"));				
			SetOfficersIndex(PChar, 2, GetCharacterIndex("Txiki Pijuan"));				
            AddDialogExitQuest("directmuellebis2");
			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;			
		break;
		
		case "Bart_part9":
            PChar.quest.Jackpot = "debuter";			
            ChangeCharacterAddressGroup(CharacterFromID("PoPrince_soldier_05"), "PoPrince_town", "goto", "goto21");
			LAi_SetGuardianType(CharacterFromID("PoPrince_soldier_05"));
			LAi_group_MoveCharacter(CharacterFromID("PoPrince_soldier_05"), "FRANCE_SOLDIERS");
	        setCharacterShipLocation(characterFromID("Portuguese Captain"), "none");			
			locations[FindLocation("PoPrince_town")].reload.l2.disable = 0;
            characters[GetCharacterIndex("Eugene Martin")].nation = FRANCE; // KK
            LAi_group_MoveCharacter(CharacterFromID("Eugene Martin"), "FRANCE_CITIZENS"); // KK
			
            GiveShip2Character(pchar,"FastCaravel","Santiago",-1,PIRATE,true,true);				
			SetCharacterShipLocation(Pchar, "Tortuga_port");	

			SetRMRelation(PChar, SPAIN, REL_WAR);		
            Build_at("Santiago_port", "Sign", "", 18.86, 6.13, 25.9, 1.7, "building");
            Locations[FindLocation("Santiago_Town_01")].dangerous = true;			

            Build_at("Cuba_port", "Sign", "", 76.75, 17.03, -115.38, 1.7, "building");
            Locations[FindLocation("Havana_town_02")].dangerous = true;
    		Locations[FindLocation("Cuba_port")].dangerous = true;  
    		Locations[FindLocation("Santiago_port")].dangerous = true;
    		ChangeRMRelation(pchar, SPAIN, -20.0);
            GiveModel2Player("GypsyCaptn_5", true);					
			
			CloseQuestHeader("ArrivedatPOP");
			
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
		
			GiveItem2Character(Pchar, "bladeBP");
			AddMoneyToCharacter(pchar, 40000);
			GiveItem2Character(PChar, "map");
        	TakeNItems(PChar, "mapDouwesen", 1);			
			ChangeCharacterAddressGroup(CharacterFromID("Pierre Delacroix"), "none", "", "");
			DoQuestReloadToLocation("Tortuga_port", "reload", "reload2_back", "_");			
			SetOfficersIndex(PChar, 1, GetCharacterIndex("Emilio Soares"));				
			SetOfficersIndex(PChar, 2, GetCharacterIndex("Txiki Pijuan"));
			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;			
		break;		

		case "Bart_part10":
            ChangeCharacterAddressGroup(CharacterFromID("PoPrince_soldier_05"), "PoPrince_town", "goto", "goto21");
			LAi_SetGuardianType(CharacterFromID("PoPrince_soldier_05"));
			LAi_group_MoveCharacter(CharacterFromID("PoPrince_soldier_05"), "FRANCE_SOLDIERS");
	        setCharacterShipLocation(characterFromID("Portuguese Captain"), "none");			
			locations[FindLocation("PoPrince_town")].reload.l2.disable = 0;
            characters[GetCharacterIndex("Eugene Martin")].nation = FRANCE; // KK
            LAi_group_MoveCharacter(CharacterFromID("Eugene Martin"), "FRANCE_CITIZENS"); // KK
			
            GiveShip2Character(pchar,"FastCaravel","Santiago",-1,PIRATE,true,true);				
			SetCharacterShipLocation(Pchar, "Oxbay_port");	

			SetRMRelation(PChar, SPAIN, REL_WAR);		
            Build_at("Santiago_port", "Sign", "", 18.86, 6.13, 25.9, 1.7, "building");
            Locations[FindLocation("Santiago_Town_01")].dangerous = true;			

            Build_at("Cuba_port", "Sign", "", 76.75, 17.03, -115.38, 1.7, "building");
            Locations[FindLocation("Havana_town_02")].dangerous = true;
    		Locations[FindLocation("Cuba_port")].dangerous = true;  
    		Locations[FindLocation("Santiago_port")].dangerous = true;
    		ChangeRMRelation(pchar, SPAIN, -20.0);
			
            GiveModel2Player("GypsyCaptn_5", true);					
			CloseQuestHeader("ArrivedatPOP");				
			
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
		
			GiveItem2Character(Pchar, "bladeBP");
			AddMoneyToCharacter(pchar, 40000);
			GiveItem2Character(PChar, "map");
        	TakeNItems(PChar, "mapDouwesen", 1);			
			ChangeCharacterAddressGroup(CharacterFromID("Pierre Delacroix"), "none", "", "");		
			SetOfficersIndex(PChar, 1, GetCharacterIndex("Emilio Soares"));				
			SetOfficersIndex(PChar, 2, GetCharacterIndex("Txiki Pijuan"));

			DoQuestReloadToLocation("Oxbay_port", "reload", "reload2", "Envoy_OxbayPort");			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;			
		break;

		case "Bart_part11":
            ChangeCharacterAddressGroup(CharacterFromID("PoPrince_soldier_05"), "PoPrince_town", "goto", "goto21");
			LAi_SetGuardianType(CharacterFromID("PoPrince_soldier_05"));
			LAi_group_MoveCharacter(CharacterFromID("PoPrince_soldier_05"), "FRANCE_SOLDIERS");
	        setCharacterShipLocation(characterFromID("Portuguese Captain"), "none");			
			locations[FindLocation("PoPrince_town")].reload.l2.disable = 0;
            characters[GetCharacterIndex("Eugene Martin")].nation = FRANCE; // KK
            LAi_group_MoveCharacter(CharacterFromID("Eugene Martin"), "FRANCE_CITIZENS"); // KK
			
            GiveShip2Character(pchar,"FastCaravel","Santiago",-1,PIRATE,true,true);				
			SetCharacterShipLocation(Pchar, "Tortuga_port");
		    Characters[GetCharacterIndex("Bertrand Ogeron")].dialog.currentnode = "gov_1";			  
            SetCharacterShipLocation(characterFromID("Daniel Montbars"), "Tortuga_port");			

			SetRMRelation(PChar, SPAIN, REL_WAR);		
            Build_at("Santiago_port", "Sign", "", 18.86, 6.13, 25.9, 1.7, "building");
            Locations[FindLocation("Santiago_Town_01")].dangerous = true;			

            Build_at("Cuba_port", "Sign", "", 76.75, 17.03, -115.38, 1.7, "building");
            Locations[FindLocation("Havana_town_02")].dangerous = true;
    		Locations[FindLocation("Cuba_port")].dangerous = true;  
    		Locations[FindLocation("Santiago_port")].dangerous = true;
    		ChangeRMRelation(pchar, SPAIN, -20.0);			

            GiveModel2Player("GypsyCaptn_5", true);					
			CloseQuestHeader("ArrivedatPOP");
			SetQuestHeader("Hunter");			
			AddQuestRecord("Hunter", "13");				
			
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
		
			GiveItem2Character(Pchar, "bladeBP");
			AddMoneyToCharacter(pchar, 40000);
			GiveItem2Character(PChar, "map");
        	TakeNItems(PChar, "mapDouwesen", 1);			
			ChangeCharacterAddressGroup(CharacterFromID("Pierre Delacroix"), "none", "", "");
			DoQuestReloadToLocation("Tortuga_port", "reload", "reload2_back", "_");			
			SetOfficersIndex(PChar, 1, GetCharacterIndex("Emilio Soares"));				
			SetOfficersIndex(PChar, 2, GetCharacterIndex("Txiki Pijuan"));
			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;			
		break;

		case "Bart_part12":
            ChangeCharacterAddressGroup(CharacterFromID("PoPrince_soldier_05"), "PoPrince_town", "goto", "goto21");
			LAi_SetGuardianType(CharacterFromID("PoPrince_soldier_05"));
			LAi_group_MoveCharacter(CharacterFromID("PoPrince_soldier_05"), "FRANCE_SOLDIERS");
	        setCharacterShipLocation(characterFromID("Portuguese Captain"), "none");			
			locations[FindLocation("PoPrince_town")].reload.l2.disable = 0;
            characters[GetCharacterIndex("Eugene Martin")].nation = FRANCE; // KK
            LAi_group_MoveCharacter(CharacterFromID("Eugene Martin"), "FRANCE_CITIZENS"); // KK
			
            GiveShip2Character(pchar,"FastCaravel","Santiago",-1,PIRATE,true,true);				
			SetCharacterShipLocation(Pchar, "Redmond_port");
         	ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Redmond_Residence", "goto", "goto5");
			LAi_SetImmortal(CharacterFromID("Henry Morgan"), 1);			
			LAi_SetCitizenType(characterFromID("Henry Morgan"));
            SetCharacterShipLocation(characterFromID("Henry Morgan"), "Redmond_port");			
            Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_18";			

			SetRMRelation(PChar, SPAIN, REL_WAR);		
            Build_at("Santiago_port", "Sign", "", 18.86, 6.13, 25.9, 1.7, "building");
            Locations[FindLocation("Santiago_Town_01")].dangerous = true;			

            Build_at("Cuba_port", "Sign", "", 76.75, 17.03, -115.38, 1.7, "building");
            Locations[FindLocation("Havana_town_02")].dangerous = true;
    		Locations[FindLocation("Cuba_port")].dangerous = true;  
    		Locations[FindLocation("Santiago_port")].dangerous = true;
    		ChangeRMRelation(pchar, SPAIN, -20.0);			

            GiveModel2Player("GypsyCaptn_5", true);					
			CloseQuestHeader("ArrivedatPOP");
			SetQuestHeader("Aguadilla");				
			AddQuestRecord("Aguadilla", "9");
            CloseQuestHeader("Aguadilla");				
			
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
		
			GiveItem2Character(Pchar, "bladeBP");
			AddMoneyToCharacter(pchar, 40000);
			GiveItem2Character(PChar, "map");
        	TakeNItems(PChar, "mapDouwesen", 1);			
			ChangeCharacterAddressGroup(CharacterFromID("Pierre Delacroix"), "none", "", "");
			DoQuestReloadToLocation("Redmond_Residence", "reload", "reload1", "_");			
			SetOfficersIndex(PChar, 1, GetCharacterIndex("Emilio Soares"));				
			SetOfficersIndex(PChar, 2, GetCharacterIndex("Txiki Pijuan"));
			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;			
		break;

		case "Bart_part13":
            ChangeCharacterAddressGroup(CharacterFromID("PoPrince_soldier_05"), "PoPrince_town", "goto", "goto21");
			LAi_SetGuardianType(CharacterFromID("PoPrince_soldier_05"));
			LAi_group_MoveCharacter(CharacterFromID("PoPrince_soldier_05"), "FRANCE_SOLDIERS");
	        setCharacterShipLocation(characterFromID("Portuguese Captain"), "none");
			locations[FindLocation("PoPrince_town")].reload.l2.disable = 0;
            characters[GetCharacterIndex("Eugene Martin")].nation = FRANCE; // KK
            LAi_group_MoveCharacter(CharacterFromID("Eugene Martin"), "FRANCE_CITIZENS"); // KK
			
            GiveShip2Character(pchar,"FastCaravel","Santiago",-1,PIRATE,true,true);				
			SetCharacterShipLocation(Pchar, "Redmond_port");	

			SetRMRelation(PChar, SPAIN, REL_WAR);		
            Build_at("Santiago_port", "Sign", "", 18.86, 6.13, 25.9, 1.7, "building");
            Locations[FindLocation("Santiago_Town_01")].dangerous = true;			

            Build_at("Cuba_port", "Sign", "", 76.75, 17.03, -115.38, 1.7, "building");
            Locations[FindLocation("Havana_town_02")].dangerous = true;
    		Locations[FindLocation("Cuba_port")].dangerous = true;  
    		Locations[FindLocation("Santiago_port")].dangerous = true;
    		ChangeRMRelation(pchar, SPAIN, -20.0);			

            GiveModel2Player("GypsyCaptn_8", true);					
			CloseQuestHeader("ArrivedatPOP");
			SetQuestHeader("Aztec_Treasure");				
			AddQuestRecord("Aztec_Treasure", "9");
            CloseQuestHeader("Aztec_Treasure");				
			
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
		
			GiveItem2Character(Pchar, "bladeBP");
			EquipCharacterByItem(Pchar, "bladeBP");			
			GiveItem2Character(CharacterFromId("Txiki Pijuan"), "blade6");
			EquipCharacterByItem(CharacterFromId("Txiki Pijuan"), "blade6");
			GiveItem2Character(CharacterFromId("Txiki Pijuan"),"pistol2");
			EquipCharacterByItem(CharacterFromId("Txiki Pijuan"), "pistol2");
			
			AddMoneyToCharacter(pchar, 150000);   			
        	TakeNItems(PChar, "map", 1);
        	TakeNItems(PChar, "mapDouwesen", 1);			
			ChangeCharacterAddressGroup(CharacterFromID("Pierre Delacroix"), "none", "", "");
			DoQuestReloadToLocation("Redmond_port", "reload", "Sea_2_back", "_");			
			SetOfficersIndex(PChar, 1, GetCharacterIndex("Emilio Soares"));				
			SetOfficersIndex(PChar, 2, GetCharacterIndex("Txiki Pijuan"));
			Characters[GetCharacterIndex("Txiki Pijuan")].dialog.filename = "Enc_Officer_dialog.c";
			Characters[GetCharacterIndex("Txiki Pijuan")].dialog.CurrentNode = "hired";			
			GiveShip2Character(characterFromID("Elting"),"XebecAS","El Diablo",-1,SPAIN,true,true);			
			
			Pchar.quest.emiliotortue.win_condition.l1 = "location";
			Pchar.quest.emiliotortue.win_condition.l1.location = "Tortuga_port";
			PChar.quest.emiliotortue.win_condition = "mutin";					
			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;			
		break;	
			
                case "begin_1":
  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "begin_2";
			
		break;			    

                case "begin_2":
  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "begin_3";
               break;

                case "begin_3":
  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "begin_4";
               break;

                
                case "begin_4":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "begin_5";
                    
		break;

                case "begin_5":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
                       AddDialogExitQuest("renceug");

		break;

               case "Exit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		

                       break;



	}
}
