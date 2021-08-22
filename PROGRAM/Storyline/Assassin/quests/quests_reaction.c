void QuestComplete(string sQuestName)
{
	ref PChar, sld;
	int iPassenger;
	PChar = GetMainCharacter();
	float locx;
	float locy;
	float locz;
	int iColony;
	int iTradeGoods, iQuantityGoods, iTradeNation;
	string homelocation, homegroup, homelocator, tavernfriend;
// KK -->
	int cc, n;
	int canQty = 0;
	int crewQty = 0;
	ref port;
// <-- KK
	float x, y, z;// MAXIMUS
	string nearloc;// MAXIMUS
	aref arship; // PB

	switch(sQuestName)
	{
		case "Partida":
			chrEnableReloadLocator("Redmond_town_04", "door_9", 0);
			chrEnableReloadLocator("Greenford_town", "reload5", 0);
			chrEnableReloadLocator("Conceicao_town", "reload15", 0);
			chrEnableReloadLocator("Hit_houseB", "Reload2", 0);
			chrEnableReloadLocator("Hit_study", "Reload1", 0); 
			chrEnableReloadLocator("Hit_study", "Reload2_back", 0); 
			chrEnableReloadLocator("Hit_passage", "Reload10", 0);
			GiveModel2Player("Assassin2",false);			
		
			AddCharacterGoods(pchar, GOOD_ALE, 600);		
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor15", "goto", "goto6");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.dialog.filename = "Divers_dialog.c";
			sld.dialog.currentnode = "begin_1";			
			sld.id = "ETLINGCREW";
            LAi_SetActorType(characterfromID("ETLINGCREW"));						
			LAi_ActorDialog(characterfromID("ETLINGCREW"), pchar, "", 6.0, 1.0);
		break;

		case "embora":
			ChangeCharacterAddress(characterFromID("Horacio de la Vega"), "none", "");
			LAi_LocationFightDisable(&Locations[FindLocation("Havana_House_03")], true);			
			SetQuestHeader("Departure");
			AddQuestRecord("Departure", "1");
                        LAi_SetActorType(characterfromID("ETLINGCREW"));
			LAi_ActorRunToLocation(characterfromID("ETLINGCREW"), "reload", "reload2_back", "none", "", "", "", 20.0);
			PChar.quest.salgada = "encontro";
			Pchar.quest.salgada.win_condition.l1 = "location";
			Pchar.quest.salgada.win_condition.l1.location = "Cuba_shore_04";
			PChar.quest.salgada.win_condition = "meetsalgada";
		break;
		
		case "meetsalgada":
            ChangeCharacterAddressGroup(CharacterFromID("Baltasar Salgada"), "Cuba_shore_04", "goto", "locator27");
            LAi_SetActorType(characterFromID("Baltasar Salgada"));
			LAi_ActorDialog(characterFromID("Baltasar Salgada"), pchar, "", 10.0, 1.0);			
		break;
		
		case "loadale":	
			LAi_Fade("discussao", "");
		break;

		case "discussao":
			RemoveCharacterGoods(pchar, GOOD_ALE, 600);		
			Characters[GetCharacterIndex("Baltasar Salgada")].dialog.currentnode = "begin_2";		
            LAi_SetActorType(characterFromID("Baltasar Salgada"));
			LAi_ActorDialog(characterFromID("Baltasar Salgada"), pchar, "", 2.0, 1.0);	
		break;

		case "assassinover":		
			LAi_SetActorType(characterFromID("Baltasar Salgada"));
			LAi_ActorRunToLocation(characterFromID("Baltasar Salgada"), "reload", "reload2_back", "none", "", "", "", 20.0);
			CloseQuestHeader("Departure");					
		break;
				
		case "fightsalgada":
			LAi_ActorAttack(CharacterFromID("Baltasar Salgada"), Pchar, "");

			pchar.quest.salgada_died.win_condition.l1 = "NPC_Death";
			pchar.quest.salgada_died.win_condition.l1.character = "Baltasar Salgada";
			pchar.quest.salgada_died.win_condition = "vientsoldado";
		break;

		case "vientsoldado":
			Locations[FindLocation("Cuba_shore_04")].reload.l1.disable = true;
			Locations[FindLocation("Cuba_shore_04")].reload.l2.disable = true;
			Locations[FindLocation("Cuba_shore_04")].reload.l3.disable = true;
		
            ChangeCharacterAddressGroup(CharacterFromID("Enrique Padilla"), "Cuba_shore_04", "goto", "locator27");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "locator27");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDATS");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, characterFromID("Enrique Padilla"), "", 10.0);
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "locator27");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDATS");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, characterFromID("Enrique Padilla"), "", 10.0);			
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "goto", "locator27");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDATS");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, characterFromID("Enrique Padilla"), "", 10.0);			

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa5_16", "goto", "locator27");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDATS");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, characterFromID("Enrique Padilla"), "", 10.0);			

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa6_16", "goto", "locator27");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDATS");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, characterFromID("Enrique Padilla"), "", 10.0);			

			LAi_SetActorType(characterFromID("Enrique Padilla"));
			Characters[GetCharacterIndex("Enrique Padilla")].dialog.currentnode = "begin_1";
			LAi_ActorDialog(characterFromID("Enrique Padilla"), pchar, "", 10.0, 1.0);
		break;

		case "gocell":
			DoQuestReloadToLocation("Havana_prison", "goto", "goto9","gocell2");		
			Locations[FindLocation("Cuba_shore_04")].reload.l1.disable = false;
			Locations[FindLocation("Cuba_shore_04")].reload.l2.disable = false;
			Locations[FindLocation("Cuba_shore_04")].reload.l3.disable = false;
		
			LAi_SetPlayerType(pchar);	
			GiveItem2Character(Pchar, "pistolrock");   
			EquipCharacterByItem(Pchar, "pistolrock");
			WaitDate("", 0,0,3,0,0);		
		break;

		case "gocell2":
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);		
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);		
            ChangeCharacterAddressGroup(CharacterFromID("Enrique Padilla"), "Havana_prison", "goto", "goto23");
			LAi_SetActorType(characterFromID("Enrique Padilla"));
			Characters[GetCharacterIndex("Enrique Padilla")].dialog.currentnode = "begin_3";
			LAi_ActorDialog(characterFromID("Enrique Padilla"), pchar, "", 2.0, 1.0);		
		break;

		case "meetadmiral":		
			DoQuestReloadToLocation("Havana_House_03", "goto", "goto4","meetadmiral2");			
		break;
		
		case "meetadmiral2":
			RemoveCharacterEquip(pchar, "pistolrock");		
            ChangeCharacterAddressGroup(CharacterFromID("Enrique Padilla"), "Havana_House_03", "goto", "goto1");
			LAi_SetActorType(characterFromID("Enrique Padilla"));
			Characters[GetCharacterIndex("Enrique Padilla")].dialog.currentnode = "begin_6";
			LAi_ActorDialog(characterFromID("Enrique Padilla"), pchar, "", 4.0, 1.0);			
		break;

		case "meetadmiral3":
			Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_1";
            LAi_SetOfficerType(characterFromID("Enrique Padilla"));
			locations[FindLocation("Havana_House_03")].reload.l2.disable = 1;			
			DisableFastTravel(true);
			DisableMenuLaunch(true);			
		break;
		
		case "voirdamski":		
			AddQuestRecord("Departure", "2");		
			locations[FindLocation("Havana_House_03")].reload.l2.disable = 0;
			EnableEquip(pchar, BLADE_ITEM_TYPE, true);
			EnableEquip(pchar, GUN_ITEM_TYPE, true);
            ChangeCharacterAddressGroup(CharacterFromID("Captain Damski"), "Havana_Shipyard", "goto", "goto6");
			Characters[GetCharacterIndex("Captain Damski")].dialog.currentnode = "begin_1";
//			SetRMRelation(PChar, SPAIN, REL_AFTERATTACK); // GR: Not hostile anymore
		break;
		
		case "meetcois":
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "Cuba_port", "reload", "sea_1");
			Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_1";
			GiveShip2Character(pchar,"XebecAS","El Diablo",-1,SPAIN,true,true);
			HoistFlag(SPAIN); // GR
			SetCharacterShipLocation(Pchar, "Cuba_port");
		break;

		case "spycayman":
			ChangeCharacterAddress(characterFromID("Captain Damski"), "none", "");		
			AddQuestRecord("Departure", "3");		
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			LAi_SetActorType(characterFromID("Chico Cois"));
			LAi_SetImmortal(CharacterFromID("Chico Cois"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Chico Cois"), "", 60.0);
			CloseQuestHeader("Departure");

			pchar.quest.verscayman.win_condition.l1 = "location";
			pchar.quest.verscayman.win_condition.l1.location = "Cayman_Port";
			pchar.quest.verscayman.win_condition = "spyhouse";			
		break;

		case "spyhouse":
			LAi_SetActorType(characterFromID("Chico Cois"));
			Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_4";
			LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 2.0, 1.0);
		break;

		case "spyhousebis":
			LAi_SetActorType(characterFromID("Chico Cois"));
			LAi_ActorFollowEverywhere(characterFromID("Chico Cois"), "", 60.0);		
			SetQuestHeader("Apprenticeship");
			AddQuestRecord("Apprenticeship", "1");
			Locations[FindLocation("Outskirts_House")].vcskip = true;			
			
			pchar.quest.versmaison.win_condition.l1 = "location";
			pchar.quest.versmaison.win_condition.l1.location = "Outskirts_House";
			pchar.quest.versmaison.win_condition = "nobodyhouse";					
		break;

		case "nobodyhouse":
			Locations[FindLocation("Cayman_Jungle_02")].vcskip = true;
			LAi_SetActorType(characterFromID("Chico Cois"));
			Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_5";
			LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 2.0, 1.0);			
		break;

		case "comespy":
            DoQuestReloadToLocation("Cayman_Jungle_02", "reload", "reload3", "comespybis");
		break;

		case "comespybis":
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "Cayman_Jungle_02", "goto", "locator7");		
            ChangeCharacterAddressGroup(CharacterFromID("Dominico Cuellar"), "Cayman_Jungle_02", "reload", "reload1");
			LAi_SetActorType(characterFromID("Dominico Cuellar"));
			Characters[GetCharacterIndex("Dominico Cuellar")].dialog.currentnode = "begin_1";
			LAi_ActorDialog(characterFromID("Dominico Cuellar"), pchar, "", 5.0, 1.0);		   
		break;
		
		case "buscareport":
            LAi_ActorRunToLocation(characterFromID("Dominico Cuellar"), "reload", "reload3", "none", "", "", "", 10.0);
			LAi_SetActorType(characterFromID("Chico Cois"));
			LAi_ActorFollowEverywhere(characterFromID("Chico Cois"), "", 60.0);
			
			pchar.quest.retourcasa.win_condition.l1 = "location";
			pchar.quest.retourcasa.win_condition.l1.location = "Outskirts_House";
			pchar.quest.retourcasa.win_condition = "dareport";					
		break;

		case "dareport":	
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "Outskirts_House", "goto", "goto1");
            ChangeCharacterAddressGroup(CharacterFromID("Dominico Cuellar"), "Outskirts_House", "goto", "goto2");
			LAi_SetActorType(characterFromID("Dominico Cuellar"));
			Characters[GetCharacterIndex("Dominico Cuellar")].dialog.currentnode = "begin_3";
			LAi_ActorDialog(characterFromID("Dominico Cuellar"), pchar, "", 2.0, 1.0);			
		break;

		case "dareportbis":
			Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_8";			
			LAi_SetActorType(characterFromID("Chico Cois"));
			LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 2.0, 1.0);
		break;		

		case "capitaoingles":
			DeleteAttribute(&Locations[FindLocation("Cayman_Jungle_02")],"vcskip");		
			AddQuestRecord("Apprenticeship", "2");		
	         TakenItems(Pchar, "pistolpdart", 2);
             EquipCharacterbyItem(Pchar, "pistolpdart");

			pchar.quest.verscentre.win_condition.l1 = "location";
			pchar.quest.verscentre.win_condition.l1.location = "Grand_Cayman_town";
			pchar.quest.verscentre.win_condition = "esperacaptain";				 
		break;
		
		case "esperacaptain":
            LAi_QuestDelay("seguircaptain", 28.0);		
		break;

		case "seguircaptain":
            ChangeCharacterAddressGroup(CharacterFromID("Harold Flesher"), "Grand_Cayman_town", "reload", "reload9");

			pchar.quest.captain_died.win_condition.l1 = "NPC_Death";
			pchar.quest.captain_died.win_condition.l1.character = "Harold Flesher";
			pchar.quest.captain_died.win_condition = "mortecaptain";

            LAi_QuestDelay("seguircaptainbis", 50.0);          	
		break;
		
		case "seguircaptainbis":
			LAi_SetImmortal(CharacterFromID("Harold Flesher"), 1);		
			LAi_SetActorType(CharacterFromID("Harold Flesher"));
			LAi_ActorGoToLocation(CharacterFromID("Harold Flesher"), "reload", "reload15", "none", "", "", "", 35.0);
		break;		

		case "mortecaptain":
			AddQuestRecord("Apprenticeship", 3);
			LAi_SetCitizenType(characterFromID("Dominico Cuellar"));
			Characters[GetCharacterIndex("Dominico Cuellar")].dialog.currentnode = "begin_9";			
		break;

		case "voltarhavana":
			LAi_SetActorType(characterFromID("Chico Cois"));
			LAi_ActorFollowEverywhere(characterFromID("Chico Cois"), "", 60.0);
			Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_16";
			LAi_SetCitizenType(characterFromID("spanish_soldat_01"));
			LAi_SetCitizenType(characterFromID("Enrique Padilla"));			
			AddQuestRecord("Apprenticeship", "4");		
		break;
		
		case "viagem_timer1":
			PChar.quest.viagem_timer1.win_condition.l1 = "Timer";
			PChar.quest.viagem_timer1.win_condition.l1.date.day = GetAddingDataDay(0, 0, 30);
			PChar.quest.viagem_timer1.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 30);
			PChar.quest.viagem_timer1.win_condition.l1.date.year = GetAddingDataYear(0, 0, 30);
			PChar.quest.viagem_timer1.win_condition = "viagem_fin_timer";
		break;

		case "spyoxbay":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 10000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 10000); }		

            ChangeCharacterAddressGroup(CharacterFromID("Pelagius Lizarraga"), "Dungeon 1", "reload", "reloadc3");
	        LAi_SetPoorType(characterfromID("Pelagius Lizarraga"));
			Characters[GetCharacterIndex("Pelagius Lizarraga")].dialog.currentnode = "begin_1";
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Chico Cois"));
			AddQuestRecord("Apprenticeship", "5");
            LAi_QuestDelay("viagem_timer2", 0.0);				
		break;		

		case "viagem_timer2":
			PChar.quest.viagem_timer2.win_condition.l1 = "Timer";
			PChar.quest.viagem_timer2.win_condition.l1.date.day = GetAddingDataDay(0, 0, 60);
			PChar.quest.viagem_timer2.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 60);
			PChar.quest.viagem_timer2.win_condition.l1.date.year = GetAddingDataYear(0, 0, 60);
			PChar.quest.viagem_timer2.win_condition = "viagem_fin_timer";
		break;

		case "viagem_fin_timer":
			RemovePassenger(pchar, characterFromID("Chico Cois"));
			RemoveCharacterCompanion(pchar, characterFromID("Chico Cois"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Chico Cois"));		
			Characters[GetCharacterIndex("Chico Cois")].Location = "none";
			SetRMRelation(PChar, SPAIN, REL_WAR);
			SetQuestHeader("Failure");
			AddQuestRecord("Failure", "1");
			CloseQuestHeader("Failure");			
			
			pchar.quest.fimvida.win_condition.l1 = "location";
			pchar.quest.fimvida.win_condition.l1.location = "Cuba";
			pchar.quest.fimvida.win_condition = "ultimavez";			
		break;
		
		case "takepelagius":
			LAi_SetActorType(characterFromID("Pelagius Lizarraga"));
			LAi_ActorFollowEverywhere(characterFromID("Pelagius Lizarraga"), "", 60.0);
			LAi_SetImmortal(characterFromID("Pelagius Lizarraga"), true);			
			Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_22";			
			AddQuestRecord("Apprenticeship", "6");

			pchar.quest.maumeet.win_condition.l1 = "location";
			pchar.quest.maumeet.win_condition.l1.location = "Oxbay_town";
			pchar.quest.maumeet.win_condition = "encontro_ingles";			
		break;

		case "encontro_ingles":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Offic_eng_16", "goto", "goto21");
			LAi_SetHP(sld, 100.0, 100.0);
			sld.dialog.filename = "Divers_dialog.c";
			sld.dialog.currentnode = "begin_2";
			sld.id = "capitao ingles";

            LAi_SetActorType(characterFromID("capitao ingles"));
			LAi_ActorDialog(characterFromID("capitao ingles"), pchar, "", 6.0, 1.0);
		break;

		case "combatingles":
			LAi_ActorAttack(CharacterFromID("capitao ingles"), PChar, "");
	        LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);			
			SetRMRelation(PChar, ENGLAND, REL_WAR);					 
		break;

		case "spypop":
			LAi_SetStayType(characterFromID("Pelagius Lizarraga"));		
			AddQuestRecord("Apprenticeship", "7");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 10000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 10000); }

			pchar.quest.chicofora.win_condition.l1 = "location";
			pchar.quest.chicofora.win_condition.l1.location = "Havana_Town_01";
			pchar.quest.chicofora.win_condition = "stinkpot_manual";			
		break;
		
		case "stinkpot_manual":
			ChangeCharacterAddress(characterFromID("Pelagius Lizarraga"), "none", "");		
			LAi_SetActorType(characterFromID("Chico Cois"));
			Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_11";
			LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 3.0, 1.0);		
		break;
		
		case "spypopbis":
			LAi_SetOfficerType(characterFromID("Chico Cois"));
			AddQuestRecord("Apprenticeship", "8");
            LAi_QuestDelay("viagem_timer1", 0.0);
            ChangeCharacterAddressGroup(CharacterFromID("Gabriel Brugera"), "PoPrince_fakefort2", "rld", "aloc3");

			pchar.quest.spanish_died.win_condition.l1 = "NPC_Death";
			pchar.quest.spanish_died.win_condition.l1.character = "Gabriel Brugera";
			pchar.quest.spanish_died.win_condition = "espiao_morto";
		break;

		case "espiao_morto":
			AddQuestRecord("Apprenticeship", "9");
			Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_28";			
		break;
		
		case "retourAdmiral":
			CloseQuestHeader("Apprenticeship");
			SetQuestHeader("Alliance");
			AddQuestRecord("Alliance", "1");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 10000);
				AddPartyExpChar(pchar, "Sneak", 100);
			}
			else { AddPartyExp(pchar, 10000); }
			
			PChar.Flags.Personal = 6; // PB: Amsterdam Skull Flag
			PChar.Flags.Personal.texture = 1;
			ChangeRMRelation(pchar, SPAIN, 10.0);			
			Locations[FindLocation("Marigot_HouseInsideR11(03)")].vcskip = true;				
            ChangeCharacterAddressGroup(CharacterFromID("Tello Basadre"), "Marigot_HouseInsideR11(03)", "reload", "reload2");				
			Characters[GetCharacterIndex("Tello Basadre")].dialog.currentnode = "begin_1";				
		break;
		
		case "viagem_timer3":
			PChar.quest.viagem_timer3.win_condition.l1 = "Timer";
			PChar.quest.viagem_timer3.win_condition.l1.date.day = GetAddingDataDay(0, 0, 9);
			PChar.quest.viagem_timer3.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 9);
			PChar.quest.viagem_timer3.win_condition.l1.date.year = GetAddingDataYear(0, 0, 9);
			PChar.quest.viagem_timer3.win_condition = "viagem_fin3_timer";
		break;

		case "viagem_fin3_timer":
			Group_SetAddressNone("Aurelien_Ship");
			Pchar.quest.foug_marti.over = "yes";			
			RemovePassenger(pchar, characterFromID("Chico Cois"));
			RemoveCharacterCompanion(pchar, characterFromID("Chico Cois"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Chico Cois"));		
			Characters[GetCharacterIndex("Chico Cois")].Location = "none";
			SetRMRelation(PChar, SPAIN, REL_WAR);
			SetQuestHeader("Alliance");
			AddQuestRecord("Alliance", "10");
			CloseQuestHeader("Alliance");			
			
			pchar.quest.fimvida.win_condition.l1 = "location";
			pchar.quest.fimvida.win_condition.l1.location = "Cuba";
			pchar.quest.fimvida.win_condition = "ultimavez";			
		break;		

		case "versmarti":
			AddQuestRecord("Alliance", "2");
			Group_CreateGroup("Aurelien_Ship"); 
    		Group_AddCharacter("Aurelien_Ship", "Aurelien Bergerat");
    		Group_SetGroupCommander("Aurelien_Ship", "Aurelien Bergerat");
     		Group_SetAddress("Aurelien_Ship", "FalaiseDeFleur", "reload_1","Ship_5");
			characters[GetCharacterIndex("Aurelien Bergerat")].nosurrender = 2;
			Character_SetAbordageEnable(characterFromID("Aurelien Bergerat"), false);
			Pchar.quest.foug_marti.win_condition.l1 = "location";
			Pchar.quest.foug_marti.win_condition.l1.location = "Falaise_de_fleur_port_01";
			PChar.quest.foug_marti.win_condition = "fougconfirm";
		break;

		case "fougconfirm":
            Pchar.quest.viagem_timer3.over = "yes";			
			AddQuestRecord("Alliance", "3");
			PChar.quest.infofoug = "meetavernier";
		break;

		case "quoifaire":
			Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_14";			
			LAi_SetActorType(characterFromID("Chico Cois"));
			LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 2.0, 1.0);
		break;

		case "quoifairebis":
            Locations[FindLocation("Falaise_de_fleur_port_01")].vcskip = true;
            Locations[FindLocation("Falaise_de_fleur_location_02")].vcskip = true;
			
            LAi_SetOfficerType(characterFromID("Chico Cois"));
			Pchar.quest.mairie.win_condition.l1 = "location";
			Pchar.quest.mairie.win_condition.l1.location = "Falaise_de_fleur_location_03";
			PChar.quest.mairie.win_condition = "planmairie";			
		break;

		case "planmairie":
			Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_15";			
			LAi_SetActorType(characterFromID("Chico Cois"));
			LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 2.0, 1.0);	
		break;

		case "infilmairie":
			RemovePassenger(pchar, characterFromID("Chico Cois"));
			RemoveCharacterCompanion(pchar, characterFromID("Chico Cois"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Chico Cois"));			
			DisableFastTravel(true);
			DisableMenuLaunch(true);		
            SetCurrentTime(23, 0);
            GiveModel2Player("Johan_Elting_b", true);
			locations[FindLocation("Falaise_de_fleur_port_01")].reload.l2.disable = 1;
			locations[FindLocation("Falaise_de_fleur_port_01")].reload.l4.disable = 1;			
			DoQuestReloadToLocation("Falaise_de_fleur_port_01", "reload", "sea","infilmairie2");
		break;

		case "infilmairie2":
			pchar.quest.cherche.win_condition.l1 = "locator";
			pchar.quest.cherche.win_condition.l1.location = "Falaise_de_fleur_location_02";
			pchar.quest.cherche.win_condition.l1.locator_group = "reload";
			pchar.quest.cherche.win_condition.l1.locator = "Falaise_de_fleur_location_02_03";
			pchar.quest.cherche.win_condition = "infilmairie3";
		break;		
		
		case "infilmairie3":			
			DoQuestReloadToLocation("Quest_FDF_townhall", "goto", "goto5","searchdoc");
		break;

		case "searchdoc":
			PostVideoAndQuest("Assassin\Townhall",1, "dansmairie");
		break;
		
		case "dansmairie":
            DeleteAttribute(&Locations[FindLocation("Falaise_de_fleur_port_01")],"vcskip");
            DeleteAttribute(&Locations[FindLocation("Falaise_de_fleur_location_02")],"vcskip");
					
			pchar.quest.cherche.win_condition.l1 = "locator";
			pchar.quest.cherche.win_condition.l1.location = "Quest_FDF_townhall";
			pchar.quest.cherche.win_condition.l1.locator_group = "goto";
			pchar.quest.cherche.win_condition.l1.locator = "goto10";
			pchar.quest.cherche.win_condition = "findoc";
		break;

		case "findoc":
			LAi_SetPlayerType(pchar); 		
		    GiveItem2Character(Pchar, "order");
			AddQuestRecord("Alliance", "4");	
			SetNationRelationBoth(FRANCE,  PORTUGAL, RELATION_FRIEND);
			pchar.quest.saut.win_condition.l1 = "locator";
			pchar.quest.saut.win_condition.l1.location = "Quest_FDF_townhall";
			pchar.quest.saut.win_condition.l1.locator_group = "goto";
			pchar.quest.saut.win_condition.l1.locator = "goto5";
			pchar.quest.saut.win_condition = "cabina";		 
	break;

	case "cabina":
            DoQuestReloadToLocation("Cabin_small", "goto", "goto2", "cabinabis");
	break;

	case "cabinabis":
			locations[FindLocation("Falaise_de_fleur_port_01")].reload.l2.disable = 0;
			locations[FindLocation("Falaise_de_fleur_port_01")].reload.l4.disable = 0;
			
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "Cabin_small", "goto", "goto3");      
	        LAi_SetActorType(characterFromID("Chico Cois"));
	        Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_19";
	        LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 1.0, 1.0);
	break;

	case "buscaptain":
			SetModelfromArray(&pchar, GetModelIndex("Johan_Elting"));	
			WaitDate("", 0,0,1,0,0);	
            SetCurrentTime(10, 0);
            DoQuestReloadToLocation("Falaise_de_fleur_port_01", "goto", "goto10", "infocap");			
	break;
	
	case "infocap":		
			AddQuestRecord("Alliance", "5");			
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "Falaise_de_fleur_port_01", "reload", "Falaise_de_fleur_location_01_02");
	        LAi_SetActorType(characterFromID("Chico Cois"));
	        Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_22";
	        LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 20.0, 1.0);			
	break;

	case "infocap2":
			LAi_Fade("caporto", "caportobis");			
	break;
	
	case "tiresoldats":
			ChangeCharacterAddress(characterFromID("SoldatF1"), "none", "");
			ChangeCharacterAddress(characterFromID("SoldatF2"), "none", "");			
	break;	
	
	case "caporto":
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "Falaise_de_fleur_port_01", "goto", "goto8");	
            ChangeCharacterAddressGroup(CharacterFromID("Aurelien Bergerat"), "Falaise_de_fleur_port_01", "officers", "sea_3");
            ChangeCharacterAddressGroup(CharacterFromID("SoldatF1"), "Falaise_de_fleur_port_01", "reload", "sea_back");
            ChangeCharacterAddressGroup(CharacterFromID("SoldatF2"), "Falaise_de_fleur_port_01", "officers", "sea_1");
			LAi_SetActorType(characterFromID("SoldatF1"));
			LAi_ActorFollow(characterFromID("SoldatF1"), characterFromID("Aurelien Bergerat"), "", 60.0);
			LAi_SetActorType(characterFromID("SoldatF2"));
			LAi_ActorFollow(characterFromID("SoldatF2"), characterFromID("Aurelien Bergerat"), "", 60.0);
	break;

	case "caportobis":
	        LAi_SetActorType(characterFromID("Chico Cois"));
	        Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_25";
	        LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 5.0, 1.0);			
	break;

	case "caportosuit":
			LAi_SetActorType(CharacterFromID("Aurelien Bergerat"));
            LAi_ActorGoToLocation(characterFromID("Aurelien Bergerat"), "reload", "werf_back", "none", "", "", "tiresoldats", 0.0);				
			LAi_ActorFollowEverywhere(characterFromID("Chico Cois"), "", 60.0);
			Pchar.quest.lieuun.win_condition.l1 = "location";
			Pchar.quest.lieuun.win_condition.l1.location = "Falaise_de_fleur_port_02";
			PChar.quest.lieuun.win_condition = "caportosuit2";				
	break;

	case "caportosuit2":	
            ChangeCharacterAddressGroup(CharacterFromID("Aurelien Bergerat"), "Falaise_de_fleur_port_02", "goto", "locator28");
            ChangeCharacterAddressGroup(CharacterFromID("SoldatF1"), "Falaise_de_fleur_port_02", "officers", "Falaise_de_fleur_location_01_05_3");
            ChangeCharacterAddressGroup(CharacterFromID("SoldatF2"), "Falaise_de_fleur_port_02", "officers", "Falaise_de_fleur_location_01_05_2");
			LAi_SetActorType(characterFromID("SoldatF1"));
			LAi_ActorFollow(characterFromID("SoldatF1"), characterFromID("Aurelien Bergerat"), "", 60.0);
			LAi_SetActorType(characterFromID("SoldatF2"));
			LAi_ActorFollow(characterFromID("SoldatF2"), characterFromID("Aurelien Bergerat"), "", 60.0);
			LAi_SetActorType(CharacterFromID("Aurelien Bergerat"));
            LAi_ActorGoToLocation(characterFromID("Aurelien Bergerat"), "reload", "Falaise_de_fleur_location_01_05", "none", "", "", "tiresoldats", 0.0);
			Pchar.quest.lieudeux.win_condition.l1 = "location";
			Pchar.quest.lieudeux.win_condition.l1.location = "Falaise_de_fleur_location_05";
			PChar.quest.lieudeux.win_condition = "caportosuit3";				
	break;

	case "caportosuit3":	
            ChangeCharacterAddressGroup(CharacterFromID("Aurelien Bergerat"), "Falaise_de_fleur_location_05", "goto", "locator23");
            ChangeCharacterAddressGroup(CharacterFromID("SoldatF1"), "Falaise_de_fleur_location_05", "officers", "locator8_2");
            ChangeCharacterAddressGroup(CharacterFromID("SoldatF2"), "Falaise_de_fleur_location_05", "officers", "locator8_3");
			LAi_SetActorType(characterFromID("SoldatF1"));
			LAi_ActorFollow(characterFromID("SoldatF1"), characterFromID("Aurelien Bergerat"), "", 60.0);
			LAi_SetActorType(characterFromID("SoldatF2"));
			LAi_ActorFollow(characterFromID("SoldatF2"), characterFromID("Aurelien Bergerat"), "", 60.0);
			LAi_SetActorType(CharacterFromID("Aurelien Bergerat"));
            LAi_ActorGoToLocation(characterFromID("Aurelien Bergerat"), "reload", "Falaise_de_fleur_location_05_04", "none", "", "", "tiresoldats", 0.0);
			Pchar.quest.lieutrois.win_condition.l1 = "location";
			Pchar.quest.lieutrois.win_condition.l1.location = "Falaise_de_fleur_location_04";
			PChar.quest.lieutrois.win_condition = "caportosuit4";				
	break;

	case "caportosuit4":
            ChangeCharacterAddressGroup(CharacterFromID("SoldatF1"), "Falaise_de_fleur_location_04", "reload", "locator21");
            ChangeCharacterAddressGroup(CharacterFromID("SoldatF2"), "Falaise_de_fleur_location_04", "goto", "citizen03");
			LAi_SetGuardianType(characterFromID("SoldatF1"));
			LAi_SetGuardianType(characterFromID("SoldatF2"));
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "Falaise_de_fleur_location_04", "goto", "locator10");			
	        LAi_SetActorType(characterFromID("Chico Cois"));
	        Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_29";
	        LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(PChar, characterFromID("SoldatF2"));			
            LAi_QuestDelay("caportosuit5", 3.0);			
		break;				

		case "caportosuit5":			
			LAi_ActorGoToLocator(PChar, "goto", "citizen04", "falacois", 10.0);			
    	break;				

	case "falacois":
	        LAi_SetPlayerType(pchar);	
	        LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 3.0, 1.0);			
	break;

	case "gopreteur":
            Locations[FindLocation("Quest_FDF_Center")].vcskip = true; 			
            DoQuestReloadToLocation("Quest_FDF_Center", "officers", "home3_2", "beforebomb");			
	break;

		case "beforebomb":
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "Quest_FDF_Center", "goto", "locator16");
			
			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "Old_man2", "goto", "locator10");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "Fuyant1";			
			LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
			
			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "Towngirl1_1", "goto", "locator9");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "Fuyant2";				
			LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
			
			LAi_SetActorType(characterFromID("Chico Cois"));
	        Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_30";			
	        LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 0.0, 1.0);			  	
		break;

		case "faseum":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "locator14", "fasedois", 10.0);			
		break;

		case "fasedois":
			LAi_ActorTurnToCharacter(PChar, characterFromID("Chico Cois"));			
            LAi_QuestDelay("piege", 5.0);			
		break;				

		case "piege":
            ChangeCharacterAddressGroup(CharacterFromID("Aurelien Bergerat"), "Quest_FDF_Center", "reload", "Falaise_de_fleur_location_03_04");
			LAi_SetActorType(characterFromID("Aurelien Bergerat"));
			LAi_ActorGoToLocator(characterFromID("Aurelien Bergerat"), "goto", "locator15", "bombe", 10.0);
			LAi_ActorTurnToCharacter(PChar, characterFromID("Aurelien Bergerat"));
            LAi_QuestDelay("verchico", 1.0);			
		break;
		
		case "verchico":
			LAi_ActorTurnToCharacter(PChar, characterFromID("Chico Cois"));
            LAi_ActorRunToLocation(characterFromID("Chico Cois"), "reload", "Falaise_de_fleur_townhall", "none", "", "", "", 0.0);
            ChangeCharacterAddressGroup(CharacterFromID("SoldatF1"), "Quest_FDF_Center", "reload", "Falaise_de_fleur_location_03_04");
            ChangeCharacterAddressGroup(CharacterFromID("SoldatF2"), "Quest_FDF_Center", "reload", "Falaise_de_fleur_location_03_04");
			LAi_SetActorType(characterFromID("SoldatF1"));
			LAi_ActorFollow(characterFromID("SoldatF1"), characterFromID("Aurelien Bergerat"), "", 60.0);
			LAi_SetActorType(characterFromID("SoldatF2"));
			LAi_ActorFollow(characterFromID("SoldatF2"), characterFromID("Aurelien Bergerat"), "", 60.0);			
		break;			

		case "bombe":
			CreateParticleSystemX("blast_inv", -9.5, 18.5, 2.41, -1.57, 0.0, 0.0,0);	
			CreateParticleSystemX("cancloud", -9.5, 18.5, 2.41, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -9.5, 18.5, -3.41, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");
            LAi_QuestDelay("bombe2", 0.2);
		break;

		case "bombe2":
			LAi_ActorSetLayMode(characterFromID("Aurelien Bergerat"));
            ChangeCharacterAddressGroup(characterFromID("Aurelien Bergerat"), "Quest_FDF_Center", "goto", "locator39");
			LAi_KillCharacter(characterFromID("SoldatF1"));
			LAi_KillCharacter(characterFromID("SoldatF2"));
            LAi_QuestDelay("bombefin", 3.5);			
		break;

		case "bombefin":
			LAi_ActorGoToLocator(PChar, "reload", "home5", "dansigreja", 10.0);
			
			LAi_SetActorType(CharacterFromID("Fuyant1"));
			LAi_ActorRunToLocation(characterFromID("Fuyant1"), "reload", "Falaise_de_Fleur_location_03_02", "none", "", "", "", 0.0);
			LAi_SetActorType(CharacterFromID("Fuyant2"));
			LAi_ActorRunToLocation(characterFromID("Fuyant2"), "reload", "Falaise_de_Fleur_location_03_02", "none", "", "", "", 0.0);						
		break;
		
		case "dansigreja":
            DoQuestReloadToLocation("Quest_FDF_Church", "reload", "reload3", "dansigreja2");
            Locations[FindLocation("Quest_FDF_CenterB")].models.always.general = "DeadGeneral";
            Locations[FindLocation("Quest_FDF_CenterB")].models.always.general .locator.group = "goto";
            Locations[FindLocation("Quest_FDF_CenterB")].models.always.general .locator.name = "locator45";			
		break;			

		case "dansigreja2":
	        LAi_SetPlayerType(pchar);			
			AddQuestRecord("Alliance", "6");
			Pchar.quest.vergente.win_condition.l1 = "location";
			Pchar.quest.vergente.win_condition.l1.location = "Quest_FDF_CenterB";
			PChar.quest.vergente.win_condition = "gente";				
		break;

		case "gente":
			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "fatman2", "officers", "home5_1");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");

			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "man4", "officers", "home5_2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");

			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "Old_man2", "officers", "home5_3");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
			
			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "Towngirl1_1", "officers", "Falaise_de_Fleur_Townhall_1");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "FRANCE_CITIZENS");
			
			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m1, "goto", "sitizen06");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m2, "goto", "locator14");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "soldier03");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "officers", "Falaise_de_Fleur_location_03_04_3");
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m5, "officers", "home3_2"); 
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");

            ChangeCharacterAddressGroup(CharacterFromID("SoldatF1"), "Quest_FDF_CenterB", "goto", "sitizen02");
			LAi_SetActorType(characterFromID("SoldatF1"));
			LAi_ActorSetLayMode(characterFromID("SoldatF1"));
            ChangeCharacterAddressGroup(CharacterFromID("SoldatF2"), "Quest_FDF_CenterB", "goto", "locator15");						
			LAi_SetActorType(characterFromID("SoldatF2"));
			LAi_ActorSetLayMode(characterFromID("SoldatF2"));
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(PChar, "officers", "Falaise_de_Fleur_Townhall_2", "emborafc", 10.0);			
		break;

		case "emborafc":
        	SetCharacterShipLocation(Pchar, "Falaise_de_fleur_shore");	
	        LAi_SetPlayerType(pchar);			
			AddQuestRecord("Alliance", "7");
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "Falaise_de_fleur_shore", "goto", "locator8");
	        LAi_SetStayType(CharacterFromID("Chico Cois"));
	        Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_32";				
		break;
		
	case "novela":
			DisableFastTravel(false);
			DisableMenuLaunch(false);		
			WaitDate("", 0,0,1,0,0);	
            SetCurrentTime(10, 0);		
            DoQuestReloadToLocation("Cabin_small", "goto", "goto2", "novelabis");
	break;

	case "novelabis":
			Group_SetAddressNone("Aurelien_Ship");	
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "Cabin_small", "goto", "goto3");      
	        LAi_SetActorType(characterFromID("Chico Cois"));
	        Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_36";
	        LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 1.0, 1.0);
	break;

	case "manovela":
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Chico Cois"));	
			QuestToSeaLogin_PrepareLoc("FalaiseDeFleur", "reload", "reload_2", true);
			QuestToSeaLogin_Launch();
			AddQuestRecord("Alliance", "8");			

//			Characters[GetCharacterIndex("Aurelien Bergerat")].nation = PERSONAL_NATION;	// GR: If you're hostile to Portugal, the fort attacks this ship
			Characters[GetCharacterIndex("Aurelien Bergerat")].nation = PRIVATEER_NATION;	// PRIVATEER_NATIOn uses Personal flag but isn't you, so can have different relations
			SetNationRelationBoth(PORTUGAL, PRIVATEER_NATION, RELATION_NEUTRAL);
			SetNationRelationBoth(FRANCE, PRIVATEER_NATION, RELATION_NEUTRAL);
			SetNationRelationBoth(SPAIN, PRIVATEER_NATION, RELATION_NEUTRAL);
			Characters[GetCharacterIndex("Aurelien Bergerat")].ship.name = "A Desconhecida";			
			Group_CreateGroup("Aurelien_Ship"); 
			Group_AddCharacter("Aurelien_Ship", "Aurelien Bergerat");
			Group_SetGroupCommander("Aurelien_Ship", "Aurelien Bergerat");
			Group_SetAddress("Aurelien_Ship", "Conceicao", "Quest_ships","quest_ship_7");
			characters[GetCharacterIndex("Aurelien Bergerat")].nosurrender = 2;
			Character_SetAbordageEnable(characterFromID("Aurelien Bergerat"), false);
			
			Pchar.quest.foug_grenada.win_condition.l1 = "location";
			Pchar.quest.foug_grenada.win_condition.l1.location = "Conceicao_port";
			PChar.quest.foug_grenada.win_condition = "fougornot";
		break;

		case "fougornot":
			LAi_QuestDelay("fougornot2", 2.0);
		break;

		case "fougornot2":
			LAi_SetActorType(characterFromID("Chico Cois"));
			Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_38";
			LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 2.0, 1.0);
		break;

		case "portavern":
	        LAi_SetOfficerType(characterFromID("Chico Cois"));
			DisableFastTravel(true);
			DisableMenuLaunch(true);			
			
			Pchar.quest.foug_grenada.win_condition.l1 = "location";
			Pchar.quest.foug_grenada.win_condition.l1.location = "Conceicao_town";
			PChar.quest.foug_grenada.win_condition = "FrenchGrenada";			
		break;				

		case "FrenchGrenada":		
			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m1, "goto", "goto18");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade2");
			EquipCharacterByItem(sld, "blade2");
			sld.dialog.filename = "French_dialog.c";
			sld.dialog.currentnode = "First time";		
	        LAi_SetCitizenType(sld);			 
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m2, "goto", "goto1");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade2");
			EquipCharacterByItem(sld, "blade2");
			sld.dialog.filename = "French_dialog.c";
			sld.dialog.currentnode = "First time";					
	        LAi_SetCitizenType(sld);			 
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "goto", "goto1");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade2");
			EquipCharacterByItem(sld, "blade2");
			sld.dialog.filename = "French_dialog.c";
			sld.dialog.currentnode = "First time";				
	        LAi_SetCitizenType(sld);			 
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");
			
			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "goto", "goto4");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade2");
			EquipCharacterByItem(sld, "blade2");
			sld.dialog.filename = "French_dialog.c";
			sld.dialog.currentnode = "First time";					
            LAi_SetStayType(sld);			 
			LAi_group_MoveCharacter(sld, "FRANCE_SOLDIERS");

			Pchar.quest.taberna.win_condition.l1 = "location";
			Pchar.quest.taberna.win_condition.l1.location = "Conceicao_Tavern";
			PChar.quest.taberna.win_condition = "taberna2";			
		break;

		case "taberna2":
			LAi_QuestDelay("tabernabis", 3.0);
        break;

		case "tabernabis":
			LAi_Fade("taberna3", "taberna31");
		break;
		
		case "taberna3":
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			ChangeCharacterAddressGroup(pchar, "Conceicao_Tavern", "sit", "sit4");
			LAi_SetActorType(characterFromID("Chico Cois"));			
            LAi_SetSitType(characterFromID("Chico Cois"));
			ChangeCharacterAddressGroup(characterFromID("Chico Cois"), "Conceicao_Tavern", "sit", "sit8");			
		break;

		case "taberna31":
	        Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_40";		
			LAi_ActorWaitDialog(CharacterFromID("Chico Cois"), Pchar); 
			LAi_ActorDialog(pchar, characterFromID("Chico Cois"),"", 10.0, 10.0);
		break;

	case "antesmissao":	
            SetCurrentTime(23, 0);
			LAi_SetStayType(characterFromID("Chico Cois"));
			RemovePassenger(pchar, characterFromID("Chico Cois"));
			RemoveCharacterCompanion(pchar, characterFromID("Chico Cois"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Chico Cois"));			
            DoQuestReloadToLocation("ShipDeck5", "goto", "goto4", "antesmissaovez");
	break;

	case "antesmissaovez":
            StoreOfficers(pchar.id);
			LAi_SetPlayerType(pchar);	
			SetModelfromArray(&pchar, GetModelIndex("Johan_Elting_b"));	
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "ShipDeck5", "goto", "goto2");      
	        LAi_SetActorType(characterFromID("Chico Cois"));
	        Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_48";
	        LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 2.0, 1.0);
	break;

	case "antesmissaobis":	
            DoQuestReloadToLocation("Quest_ShipDeck2", "rld", "startloc", "comecar");
	break;

	case "comecar":
			PostVideoAndQuest("Assassin\lineship",1, "comecar2");
	break;
	
	case "comecar2":
	         TakenItems(Pchar, "pistolpdart", 5);
             EquipCharacterbyItem(Pchar, "pistolpdart");			 

	        LAi_SetCheckMinHP(Pchar, LAi_GetCharacterHP(Pchar)-1.0, true, "frenchattack");
	        LAi_group_SetRelation("SHIP_FRENCH_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);

			Pchar.quest.upper.win_condition.l1 = "location";
			Pchar.quest.upper.win_condition.l1.location = "Quest_Deck1";
			PChar.quest.upper.win_condition = "upperdeck";					
        break;
		
        case "upperdeck":
	     Locations[FindLocation("Quest_Deck1")].reload.l3.disable = 1;
	     Locations[FindLocation("Quest_Deck1")].reload.l1.disable = 1;
			
			pchar.quest.soldier_died.win_condition.l1 = "NPC_Death";
			pchar.quest.soldier_died.win_condition.l1.character = "Lineship_soldier_5";
			pchar.quest.soldier_died.win_condition = "posebombe";			
        break;

        case "posebombe":
			pchar.quest.poser.win_condition.l1 = "locator";
			pchar.quest.poser.win_condition.l1.location = "Quest_Deck1";
			pchar.quest.poser.win_condition.l1.locator_group = "reload";
			pchar.quest.poser.win_condition.l1.locator = "reload4";
			pchar.quest.poser.win_condition = "posereussi";
        break;

        case "posereussi":
			TakeItemFromCharacter(pchar, "time_bomb");
    	    Locations[FindLocation("Quest_Deck1")].reload.l3.disable = 0;
			
			Pchar.quest.main.win_condition.l1 = "location";
			Pchar.quest.main.win_condition.l1.location = "Quest_Deck3";
			PChar.quest.main.win_condition = "maindeck";			
        break;
		
        case "maindeck":
	     Locations[FindLocation("Quest_Deck3")].reload.l3.disable = 1;
	     Locations[FindLocation("Quest_Deck3")].reload.l2.disable = 1;
			
			pchar.quest.soldier_died.win_condition.l1 = "NPC_Death";
			pchar.quest.soldier_died.win_condition.l1.character = "Lineship_soldier_6";
			pchar.quest.soldier_died.win_condition = "decksuivant";			
        break;		

        case "decksuivant":
	     Locations[FindLocation("Quest_Deck3")].reload.l3.disable = 0;

			Pchar.quest.hold.win_condition.l1 = "location";
			Pchar.quest.hold.win_condition.l1.location = "Quest_Hold1";
			PChar.quest.hold.win_condition = "holddeck";			 
        break;

        case "holddeck":
	     LAi_RemoveCheckMinHP(Pchar);
         LAi_SetImmortal(Pchar, false);		
	     Locations[FindLocation("Quest_Hold1")].reload.l1.disable = 1;
			
			pchar.quest.soldier_died.win_condition.l1 = "NPC_Death";
			pchar.quest.soldier_died.win_condition.l1.character = "Lineship_soldier_7";
			pchar.quest.soldier_died.win_condition = "posedeuxbombe";			
        break;

        case "posedeuxbombe":
			pchar.quest.posedeux.win_condition.l1 = "locator";
			pchar.quest.posedeux.win_condition.l1.location = "Quest_Hold1";
			pchar.quest.posedeux.win_condition.l1.locator_group = "box";
			pchar.quest.posedeux.win_condition.l1.locator = "gunpowder_1";
			pchar.quest.posedeux.win_condition = "posebreussi";
        break;

        case "posebreussi":
			TakeItemFromCharacter(pchar, "time_bomb");
            LAi_QuestDelay("voltabarco", 2.0);		
        break;
		
        case "voltabarco":
			// PB: Why does this need to be done AGAIN? -->
			Group_CreateGroup("Aurelien_Ship"); 
    		Group_AddCharacter("Aurelien_Ship", "Aurelien Bergerat");
    		Group_SetGroupCommander("Aurelien_Ship", "Aurelien Bergerat");
     		Group_SetAddress("Aurelien_Ship", "Conceicao", "Quest_ships","quest_ship_7");
			// PB: Why does this need to be done AGAIN? <--
			QuestToSeaLogin_PrepareLoc("Conceicao", "reload", "reload_1", true);
			QuestToSeaLogin_Launch();
			DoQuestCheckDelay("couler", 5.0);			
        break;

        case "couler":
            SeaAI_SailToCharacter(GetCharacterIndex("Aurelien Bergerat"));		
            Ship_Detonate(characterFromID("Aurelien Bergerat"), true, true);
			SetModelfromArray(&pchar, GetModelIndex("Johan_Elting"));
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Chico Cois"));
            RestoreOfficers(pchar.id);			
			DoQuestCheckDelay("coulerbis", 12.0);		
        break;

        case "coulerbis":
			characters[GetCharacterindex("Aurelien Bergerat")].ship.hp = 0;
			AddQuestRecord("Alliance", "9");
			DisableFastTravel(false);
			DisableMenuLaunch(false);				
			Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_35";				
        break;

        case "frenchattack":
         PlaySound("Ambient\Sea\bell8_0400_0800_1200.wav");
	     LAi_group_FightGroups("SHIP_FRENCH_SOLDIERS", LAI_GROUP_PLAYER, true);
	     LAi_RemoveCheckMinHP(Pchar);
         LAi_SetImmortal(Pchar, false);
		 
	     Locations[FindLocation("Quest_ShipDeck2")].reload.l3.disable = 1;
	     Locations[FindLocation("Quest_Deck1")].reload.l3.disable = 1;
	     Locations[FindLocation("Quest_Deck1")].reload.l1.disable = 1;		 
	     Locations[FindLocation("Quest_Deck3")].reload.l2.disable = 1;
	     Locations[FindLocation("Quest_Deck3")].reload.l3.disable = 1;		 
	     Locations[FindLocation("Quest_Hold1")].reload.l1.disable = 1;
        break;
		
	//modified Hitman
	
		case "meet_thug3":
			CloseQuestHeader("Alliance");
			SetNationRelationBoth(SPAIN, FRANCE, RELATION_NEUTRAL); // GR
			SetQuestHeader("Hitman");
			AddQuestRecord("Hitman", "1");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			
			ChangeRMRelation(pchar, SPAIN, 10.0);			
			ChangeCharacterAddressGroup(CharacterFromID("Thug3"), "Tortuga_tavern", "sit", "sit7"); // PB
			LAi_SetSitType(characterFromID("Thug3"));
			Characters[GetCharacterIndex("Thug3")].dialog.currentnode = "begin_1";			
		break;

		case "meet_mateus":
			LAi_Fade("sairtavern", "");
        break;

		case "sairtavern":
			ChangeCharacterAddress(characterFromID("Thug3"), "none", "");
			PlaceCharacter(characterFromID("Thug3"), "goto");
			LAi_SetActorType(characterFromID("Thug3"));
			LAi_ActorFollowEverywhere(characterFromID("Thug3"), "", 60.0);
			AddQuestRecord("Hitman", "22");
			
			pchar.quest.versmateus.win_condition.l1 = "location";
			pchar.quest.versmateus.win_condition.l1.location = "Redmond_town_04";
			pchar.quest.versmateus.win_condition = "suivrethug";			
        break;

		case "suivrethug":
			LAi_SetActorType(characterFromID("Thug3"));
			Characters[GetCharacterIndex("Thug3")].dialog.currentnode = "begin_7";
			LAi_ActorDialog(characterFromID("Thug3"), pchar, "", 2.0, 1.0);
        break;
		
		case "showhouse":
			LAi_ActorGoToLocation(characterFromID("Thug3"), "reload", "door_9", "none", "", "", "Hit_start1", 0.0);
        break;
		
		case "Hit_start1":
			chrEnableReloadLocator("Redmond_town_04", "door_9", 1);
			
			pchar.quest.versantos.win_condition.l1 = "location";
			pchar.quest.versantos.win_condition.l1.location = "Hit_houseB";
			pchar.quest.versantos.win_condition = "Hit_start12";			
        break;		
			
		case "Hit_start12":
			Characters[GetCharacterIndex("Mateus Santos")].dialog.currentnode = "start";			
			ChangeCharacterAddressGroup(CharacterFromID("Thug3"), "Hit_houseB", "goto", "goto5");
			LAi_SetStayType(characterFromID("Thug3"));			

			LAi_group_MoveCharacter(CharacterFromID("Thug2"), "santos_group");
			LAi_group_MoveCharacter(CharacterFromID("Thug3"), "santos_group");			
			LAi_group_MoveCharacter(CharacterFromID("Thug4"), "santos_group"); //SCM
			LAi_group_MoveCharacter(CharacterFromID("Thug5"), "santos_group"); //SCM
			LAi_group_MoveCharacter(CharacterFromID("Thug6"), "santos_group"); //SCM
			LAi_group_MoveCharacter(CharacterFromID("Thug7"), "santos_group"); //SCM
			LAi_group_MoveCharacter(CharacterFromID("Thug8"), "santos_group"); //SCM

			LAi_group_SetRelation("santos_group", "santos_group", LAI_GROUP_FRIEND);			
		break;

		case "Hit_END":
			Characters[GetCharacterIndex("Ambroz Bricenos")].Location = "none";
			Characters[GetCharacterIndex("Mateus Santos")].Location = "none";
			Characters[GetCharacterIndex("Thug2")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Thug4")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Thug5")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Thug6")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Thug7")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Thug8")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Thug9")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Pris1")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Pris2")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Pris3")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Pris4")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Camille Leone")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Geffrey Bampfylde")].Location = "none";
			Characters[GetCharacterIndex("Bucho")].Location = "none";
			Characters[GetCharacterIndex("Pepin Bertillon")].Location = "none";
			Characters[GetCharacterIndex("Bertillon's guard1")].Location = "none";
			Characters[GetCharacterIndex("Bertillon's guard2")].Location = "none";
			Characters[GetCharacterIndex("Amerigo Vieira")].Location = "none";
			Characters[GetCharacterIndex("Vito Leone")].Location = "none";

			chrEnableReloadLocator("Redmond_town_04", "door_9", 0);
			chrEnableReloadLocator("Greenford_town", "reload5", 0);
			chrEnableReloadLocator("Conceicao_town", "reload15", 0);

			PChar.quest.Hitman = "end";
			PChar.quest.Hitman.over = "yes";
			CloseQuestHeader("Hitman");
		break;

		case "Hit_END_timer":
			Characters[GetCharacterIndex("Ambroz Bricenos")].Location = "none";
			Characters[GetCharacterIndex("Mateus Santos")].Location = "none";
			Characters[GetCharacterIndex("Desiree' Muerte")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Thug2")].Location = "none";
			Characters[GetCharacterIndex("Thug3")].Location = "none";
			Characters[GetCharacterIndex("Thug4")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Thug5")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Thug6")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Thug7")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Thug8")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Thug9")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Camille Leone")].Location = "none"; //SCM
			Characters[GetCharacterIndex("Geffrey Bampfylde")].Location = "none";
			Characters[GetCharacterIndex("Bucho")].Location = "none";
			Characters[GetCharacterIndex("Pepin Bertillon")].Location = "none";
			Characters[GetCharacterIndex("Bertillon's guard1")].Location = "none";
			Characters[GetCharacterIndex("Bertillon's guard2")].Location = "none";
			Characters[GetCharacterIndex("Amerigo Vieira")].Location = "none";
			Characters[GetCharacterIndex("Vito Leone")].Location = "none";

			chrEnableReloadLocator("Redmond_town_04", "door_9", 0);
			chrEnableReloadLocator("Greenford_town", "reload5", 0);
			chrEnableReloadLocator("Conceicao_town", "reload15", 0);

			PChar.quest.Hitman = "end";

			AddQuestRecord("Hitman", "21");
			CloseQuestHeader("Hitman");
		break;

		case "Hit_timer1":
			PChar.quest.Hit_timer1.win_condition.l1 = "Timer";
			PChar.quest.Hit_timer1.win_condition.l1.date.day = GetAddingDataDay(0, 3, 0);
			PChar.quest.Hit_timer1.win_condition.l1.date.month = GetAddingDataMonth(0, 3, 0);
			PChar.quest.Hit_timer1.win_condition.l1.date.year = GetAddingDataYear(0, 3, 0);
			PChar.quest.Hit_timer1.win_condition = "Hit_END_timer";
		break;

		case "Hit_timer2":
			PChar.quest.Hit_timer2.win_condition.l1 = "Timer";
			PChar.quest.Hit_timer2.win_condition.l1.date.day = GetAddingDataDay(0, 3, 0);
			PChar.quest.Hit_timer2.win_condition.l1.date.month = GetAddingDataMonth(0, 3, 0);
			PChar.quest.Hit_timer2.win_condition.l1.date.year = GetAddingDataYear(0, 3, 0);
			PChar.quest.Hit_timer2.win_condition = "Hit_END_timer";
		break;

		case "Hit_timer3":
			PChar.quest.Hit_timer3.win_condition.l1 = "Timer";
			PChar.quest.Hit_timer3.win_condition.l1.date.day = GetAddingDataDay(0, 3, 0);
			PChar.quest.Hit_timer3.win_condition.l1.date.month = GetAddingDataMonth(0, 3, 0);
			PChar.quest.Hit_timer3.win_condition.l1.date.year = GetAddingDataYear(0, 3, 0);
			PChar.quest.Hit_timer3.win_condition = "Hit_END_timer";
		break;

		case "Hit_timer4":
			PChar.quest.Hit_timer4.win_condition.l1 = "Timer";
			PChar.quest.Hit_timer4.win_condition.l1.date.day = GetAddingDataDay(0, 3, 0);
			PChar.quest.Hit_timer4.win_condition.l1.date.month = GetAddingDataMonth(0, 3, 0);
			PChar.quest.Hit_timer4.win_condition.l1.date.year = GetAddingDataYear(0, 3, 0);
			PChar.quest.Hit_timer4.win_condition = "Hit_END_timer";
		break;

		case "Hit_timer5":
			PChar.quest.Hit_timer5.win_condition.l1 = "Timer";
			PChar.quest.Hit_timer5.win_condition.l1.date.day = GetAddingDataDay(0, 3, 0);
			PChar.quest.Hit_timer5.win_condition.l1.date.month = GetAddingDataMonth(0, 3, 0);
			PChar.quest.Hit_timer5.win_condition.l1.date.year = GetAddingDataYear(0, 3, 0);
			PChar.quest.Hit_timer5.win_condition = "Hit_END_timer";
		break;

		case "Hit_refused_Mateus":
			EndQuestMovie();TrackQuestMovie("end","Hit_refused_Mateus");
			bDisableFastReload = 1;

			LAi_SetPlayerType(PChar);

			LAi_warrior_DialogEnable(CharacterFromID("Mateus Santos"), 0);
			LAi_warrior_DialogEnable(CharacterFromID("Desiree' Muerte"), 4); //SCM
			LAi_warrior_DialogEnable(CharacterFromID("Thug2"), 0);
			LAi_warrior_DialogEnable(CharacterFromID("Thug3"), 0);
			LAi_warrior_DialogEnable(CharacterFromID("Thug4"), 0); //SCM
			LAi_warrior_DialogEnable(CharacterFromID("Thug5"), 0); //SCM
			LAi_warrior_DialogEnable(CharacterFromID("Thug6"), 0); //SCM
			LAi_warrior_DialogEnable(CharacterFromID("Thug7"), 0); //SCM
			LAi_warrior_DialogEnable(CharacterFromID("Thug8"), 0); //SCM
			LAi_warrior_DialogEnable(CharacterFromID("Thug9"), 0); //SCM
			LAi_warrior_DialogEnable(CharacterFromID("Camille Leone"), 0); //SCM

			PChar.quest.Hit_refused_Mateus_end.win_condition.l1 = "location";
			PChar.quest.Hit_refused_Mateus_end.win_condition.l1.character = PChar.id;
			PChar.quest.Hit_refused_Mateus_end.win_condition.l1.location = "Redmond_town_04";
			PChar.quest.Hit_refused_Mateus_end.win_condition = "Hit_refused_Mateus_end";
		break;

		case "Hit_refused_Mateus_end":
			bDisableFastReload = 0;
			LAi_QuestDelay("Hit_END", 0.0);
			AddQuestRecord("Hitman", "20");
		break;

		case "Hit_die":
			EndQuestMovie();TrackQuestMovie("end","Hit_die");
			LAi_SetPlayerType(PChar);
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Hit_die");
			bDisableFastReload = 1;

			LAi_LocationFightDisable(&Locations[FindLocation("Hit_houseB")], 0); //SCM Fight ok

			LAi_SetImmortal(CharacterFromID("Mateus Santos"), 1);
			LAi_SetImmortal(CharacterFromID("Desiree' Muerte"), 1); //SCM
			LAi_SetImmortal(CharacterFromID("Thug2"), 1);
			LAi_SetImmortal(CharacterFromID("Thug3"), 1);

			LAi_SetActorType(CharacterFromID("Mateus Santos"));
			LAi_SetActorType(CharacterFromID("Desiree' Muerte")); //SCM
			LAi_SetActorType(CharacterFromID("Thug2"));
			LAi_SetActorType(CharacterFromID("Thug3"));
			LAi_SetActorType(CharacterFromID("Thug4")); //SCM
			LAi_SetActorType(CharacterFromID("Thug5")); //SCM
			LAi_SetActorType(CharacterFromID("Thug6")); //SCM
			LAi_SetActorType(CharacterFromID("Thug7")); //SCM
			LAi_SetActorType(CharacterFromID("Thug8")); //SCM
			LAi_SetActorType(CharacterFromID("Thug9")); //SCM
			LAi_SetActorType(CharacterFromID("Camille Leone")); //SCM

			LAi_ActorAttack(CharacterFromID("Mateus Santos"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Desiree' Muerte"), PChar, "");//SCM
			LAi_ActorAttack(CharacterFromID("Thug2"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Thug3"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Thug4"), PChar, ""); //SCM
			LAi_ActorAttack(CharacterFromID("Thug5"), PChar, ""); //SCM
			LAi_ActorAttack(CharacterFromID("Thug6"), PChar, ""); //SCM
			LAi_ActorAttack(CharacterFromID("Thug7"), PChar, ""); //SCM
			LAi_ActorAttack(CharacterFromID("Thug8"), PChar, ""); //SCM
		break;

		case "Hit_mark_Ambroz":
			AddQuestRecord("Hitman", "2");		
			ChangeCharacterAddressGroup(CharacterFromID("Ambroz Bricenos"), "Hispaniola_shore_01", "goto", "goto7");			
			Characters[GetCharacterIndex("Ambroz Bricenos")].dialog.currentnode = "begin";
			LAi_SetImmortal(CharacterFromID("Ambroz Bricenos"), 0);
			LAi_SetCheckMinHP(CharacterFromID("Ambroz Bricenos"), 0.0, 0, "Hit_killed_Ambroz");
			LAi_QuestDelay("Hit_timer1", 0.0);
		break;

		case "Hit_kill_Ambroz":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Hit_kill_Ambroz");
			bDisableFastReload = 1;
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(CharacterFromID("Ambroz Bricenos"));
			LAi_ActorAttack(CharacterFromID("Ambroz Bricenos"), PChar, "");
		break;

		case "Hit_killed_Ambroz":
			EndQuestMovie();TrackQuestMovie("end","Hit_killed_Ambroz");
			bDisableFastReload = 0;
			PChar.quest.Hitman = "hit_ambroz";
			Characters[GetCharacterIndex("Ambroz Bricenos")].Location = "none";
			Pchar.quest.Hit_timer1.over = "yes";
			AddQuestRecord("Hitman", "3");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 2500); }
			else { AddPartyExp(pchar, 2500); }
		break;

		case "Hit_spared_Ambroz":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Hit_spared_Ambroz");
			bDisableFastReload = 1;
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(CharacterFromID("Ambroz Bricenos"));
			LAi_ActorRunToLocation(CharacterFromID("Ambroz Bricenos"), "reload", "reload2", "none", "", "", "Hit_spared_Ambroz_end", 17.0);
		break;

		case "Hit_spared_Ambroz_end":
			EndQuestMovie();TrackQuestMovie("end","Hit_spared_Ambroz_end");
			bDisableFastReload = 0;
			LAi_QuestDelay("Hit_END", 0.0);
			Pchar.quest.Hit_timer1.over = "yes";
			AddQuestRecord("Hitman", "4");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 2500); }
			else { AddPartyExp(pchar, 2500); }
		break;

		case "Hit_mark_Geffrey":
			PChar.quest.Hitman = "mark_geffrey";

			PChar.quest.Hit_Geffrey.win_condition.l1 = "location";
			PChar.quest.Hit_Geffrey.win_condition.l1.character = PChar.id;
			PChar.quest.Hit_Geffrey.win_condition.l1.location = "Hit_house1";
			PChar.quest.Hit_Geffrey.win_condition = "Hit_Geffrey";

			chrEnableReloadLocator("Greenford_town", "reload5", 1);
			LAi_QuestDelay("Hit_timer2", 0.0);
			AddQuestRecord("Hitman", "5");
		break;

		case "Hit_Geffrey":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Hit_Geffrey");
			bDisableFastReload = 1;
			LAi_LocationFightDisable(&Locations[FindLocation("Hit_house1")], 1);
			LAi_SetActorType(PChar);
			LAi_SetActorType(CharacterFromID("Bucho"));
			LAi_ActorTurnToCharacter(CharacterFromID("Bucho"), PChar);
			LAi_ActorDialog(PChar, CharacterFromID("Geffrey Bampfylde"), "", 2.0, -1);
		break;

		case "Hit_talk_to_Bucho":
			LAi_SetPlayerType(PChar);
			LAi_ActorDialog(CharacterFromID("Bucho"), PChar, "", 1.0, -1);
		break;

		case "Hit_kill_Bucho":
			LAi_LocationFightDisable(&Locations[FindLocation("Hit_house1")], 0);
			LAi_SetImmortal(CharacterFromID("Bucho"), 0);
			LAi_ActorAttack(CharacterFromID("Bucho"), PChar, "");
			LAi_SetCheckMinHP(CharacterFromID("Bucho"), 0.0, 0, "Hit_killed_Bucho");
		break;

		case "Hit_killed_Bucho":
			Characters[GetCharacterIndex("Bucho")].Location = "none";
			Characters[GetCharacterIndex("Geffrey Bampfylde")].dialog.currentnode = "plea";
			LAi_SetActorType(CharacterFromID("Geffrey Bampfylde"));
			LAi_SetStayType(PChar);
			LAi_SetPlayerType(PChar);
			LAi_ActorDialog(CharacterFromID("Geffrey Bampfylde"), PChar, "", 4.0, -1);

			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 1750); }
			else { AddPartyExp(pchar, 1750); }
		break;

		case "Hit_spare_Geffrey":
			LAi_ActorRunToLocation(CharacterFromID("Geffrey Bampfylde"), "reload", "reload1", "none", "", "", "Hit_spared_Geffrey", 4.0);
		break;

		case "Hit_spared_Geffrey":
			EndQuestMovie();TrackQuestMovie("end","Hit_spared_Geffrey");
			bDisableFastReload = 0;
			LAi_QuestDelay("Hit_END", 0.0);
			Pchar.quest.Hit_timer2.over = "yes";
			AddQuestRecord("Hitman", "7");

			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 3000); }
			else { AddPartyExp(pchar, 3000); }
		break;

		case "Hit_kill_Geffrey":
			LAi_CharacterDisableDialog(CharacterFromID("Geffrey Bampfylde"));
			LAi_SetImmortal(CharacterFromID("Geffrey Bampfylde"), 0);
			GiveItem2Character(CharacterFromId("Geffrey Bampfylde"), "blade5");
			EquipCharacterByItem(CharacterFromId("Geffrey Bampfylde"), "blade5");

			LAi_ActorAttack(CharacterFromID("Geffrey Bampfylde"), PChar, "");
			LAi_SetCheckMinHP(CharacterFromID("Geffrey Bampfylde"), 0.0, 0, "Hit_killed_Geffrey");
		break;

		case "Hit_killed_Geffrey":
			EndQuestMovie();TrackQuestMovie("end","Hit_killed_Geffrey");
			bDisableFastReload = 0;
			PChar.quest.Hitman = "hit_geffrey";
			Characters[GetCharacterIndex("Geffrey Bampfylde")].Location = "none";
			ChangeCharacterAddressGroup(CharacterFromID("Thug7"), "Hit_passage", "goto", "goto16"); //SCM

			Pchar.quest.Hit_timer2.over = "yes";
			AddQuestRecord("Hitman", "6");

			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 3000); }
			else { AddPartyExp(pchar, 3000); }
		break;

		case "Hit_mark_Pepin":
			PChar.quest.Hitman = "mark_pepin";

			ChangeCharacterAddressGroup(CharacterFromID("Pepin Bertillon"), "Turks_port", "goto", "P_goto12");		//JRH: new Turks, was goto12
			ChangeCharacterAddressGroup(CharacterFromID("Bertillon's guard1"), "Turks_port", "goto", "P_character11");	//JRH: new Turks, was character11
			ChangeCharacterAddressGroup(CharacterFromID("Bertillon's guard2"), "Turks_port", "goto", "P_character12");	//JRH: new Turks, was character12

			LAi_SetImmortal(CharacterFromID("Pepin Bertillon"), 0);
			LAi_SetImmortal(CharacterFromID("Bertillon's guard1"), 0);
			LAi_SetImmortal(CharacterFromID("Bertillon's guard2"), 0);

			LAi_SetWarriorType(CharacterFromID("Pepin Bertillon"));
			LAi_SetWarriorType(CharacterFromID("Bertillon's guard1"));
			LAi_SetWarriorType(CharacterFromID("Bertillon's guard2"));

			LAi_warrior_DialogEnable(CharacterFromID("Pepin Bertillon"), 1);
			LAi_warrior_DialogEnable(CharacterFromID("Bertillon's guard1"), 1);
			LAi_warrior_DialogEnable(CharacterFromID("Bertillon's guard2"), 1);

			LAi_group_MoveCharacter(CharacterFromID("Pepin Bertillon"), "Bertillon_Group");
			LAi_group_MoveCharacter(CharacterFromID("Bertillon's guard1"), "Bertillon_Group");
			LAi_group_MoveCharacter(CharacterFromID("Bertillon's guard2"), "Bertillon_Group");

			PChar.quest.Hit_goto_QC_port.win_condition.l1 = "location";
			PChar.quest.Hit_goto_QC_port.win_condition.l1.character = PChar.id;
			PChar.quest.Hit_goto_QC_port.win_condition.l1.location = "Turks_port";
			PChar.quest.Hit_goto_QC_port.win_condition = "Hit_goto_QC_port";

			AddQuestRecord("Hitman", "8");
		break;

		case "Hit_goto_QC_port":
			Pchar.dialog.CurrentNode = "ship_pepin";		
			LAi_warrior_SetCommander(CharacterFromID("Bertillon's guard1"), CharacterFromID("Pepin Bertillon"));
			LAi_warrior_SetCommander(CharacterFromID("Bertillon's guard2"), CharacterFromID("Pepin Bertillon"));

			LAi_group_SetCheck("Bertillon_Group", "Hit_killed_Pepin");
			LAi_SetActorType(PChar);
			LAi_ActorSelfDialog(PChar, "Hit_goto_QC_port1");
		break;

		case "Hit_goto_QC_port1":
			LAi_SetPlayerType(PChar);
		break;

		case "Hit_spare_Pepin":
			LAi_SetImmortal(CharacterFromID("Pepin Bertillon"), 1);
			LAi_SetImmortal(CharacterFromID("Bertillon's guard1"), 1);
			LAi_SetImmortal(CharacterFromID("Bertillon's guard2"), 1);

			LAi_SetActorType(CharacterFromID("Pepin Bertillon"));
			LAi_SetActorType(CharacterFromID("Bertillon's guard1"));
			LAi_SetActorType(CharacterFromID("Bertillon's guard2"));

			LAi_ActorGoToLocation(CharacterFromID("Pepin Bertillon"), "reload", "reload2", "none", "", "", "", 7.0);
			LAi_ActorGoToLocation(CharacterFromID("Bertillon's guard1"), "reload", "reload2", "none", "", "", "", 7.0);
			LAi_ActorGoToLocation(CharacterFromID("Bertillon's guard2"), "reload", "reload2", "none", "", "", "", 7.0);

			LAi_QuestDelay("Hit_spared_Pepin", 0.0);
		break;

		case "Hit_spared_Pepin":
			LAi_QuestDelay("Hit_END", 0.0);
			Pchar.quest.Hit_timer3.over = "yes";
			AddQuestRecord("Hitman", "10");

			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 2000); }
			else { AddPartyExp(pchar, 2000); }
		break;

		case "Hit_kill_Pepin":
			LAi_warrior_DialogEnable(CharacterFromID("Pepin Bertillon"), 0);
			LAi_warrior_DialogEnable(CharacterFromID("Bertillon's guard1"), 0);
			LAi_warrior_DialogEnable(CharacterFromID("Bertillon's guard2"), 0);

			LAi_group_FightGroups("Bertillon_Group", LAI_GROUP_PLAYER, 1);
		break;

		case "Hit_killed_Pepin":
			EndQuestMovie();TrackQuestMovie("end","Hit_killed_Pepin");
			PChar.quest.Hitman = "hit_pepin";

			Characters[GetCharacterIndex("Pepin Bertillon")].Location = "none";
			Characters[GetCharacterIndex("Bertillon's guard1")].Location = "none";
			Characters[GetCharacterIndex("Bertillon's guard2")].Location = "none";

			ChangeCharacterAddressGroup(CharacterFromID("Thug8"), "Hit_passage", "goto", "goto14"); //SCM
			Pchar.quest.Hit_timer3.over = "yes";
			AddQuestRecord("Hitman", "9");

			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 4500); }
			else { AddPartyExp(pchar, 4500); }
		break;

		case "Hit_mark_Amerigo":
			PChar.quest.Hitman = "mark_amerigo";

			PChar.quest.Hit_Amerigo.win_condition.l1 = "location";
			PChar.quest.Hit_Amerigo.win_condition.l1.character = PChar.id;
			PChar.quest.Hit_Amerigo.win_condition.l1.location = "Hit_house2";
			PChar.quest.Hit_Amerigo.win_condition = "Hit_Amerigo";

			chrEnableReloadLocator("Conceicao_town", "reload15", 1);
			AddQuestRecord("Hitman", "11");
		break;

		case "Hit_Amerigo":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Hit_Amerigo");
			bDisableFastReload = 1;
			LAi_SetActorType(PChar);
			LAi_ActorDialog(PChar, CharacterFromID("Amerigo Vieira"), "", 4.0, -1);
		break;

		case "Hit_kill_Amerigo":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(CharacterFromID("Amerigo Vieira"));
			LAi_SetImmortal(CharacterFromID("Amerigo Vieira"), 0);
			LAi_ActorAttack(CharacterFromID("Amerigo Vieira"), PChar, "");
			LAi_SetCheckMinHP(CharacterFromID("Amerigo Vieira"), 0.0, 0, "Hit_killed_Amerigo");
		break;

		case "Hit_killed_Amerigo":
			EndQuestMovie();TrackQuestMovie("end","Hit_killed_Amerigo");
			bDisableFastReload = 0;
			PChar.quest.Hitman = "hit_amerigo";
			Characters[GetCharacterIndex("Amerigo Vieira")].Location = "none";

			ChangeCharacterAddressGroup(CharacterFromID("Thug2"), "Hit_passage", "goto", "goto17"); //SCM
			Pchar.quest.Hit_timer4.over = "yes";
			AddQuestRecord("Hitman", "12");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 6000); }
			else { AddPartyExp(pchar, 6000); }
		break;

		case "Hit_spare_Amerigo":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(CharacterFromID("Amerigo Vieira"));
			LAi_ActorRunToLocation(CharacterFromID("Amerigo Vieira"), "reload", "reload1", "none", "", "", "Hit_spared_Amerigo", 3.0);
		break;

		case "Hit_spared_Amerigo":
			EndQuestMovie();TrackQuestMovie("end","Hit_spared_Amerigo");
			bDisableFastReload = 0;
			LAi_QuestDelay("Hit_END", 0.0);

			Pchar.quest.Hit_timer4.over = "yes";
			AddQuestRecord("Hitman", "13");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 4000); }
			else { AddPartyExp(pchar, 4000); }
		break;

		case "Hit_join_Amerigo":
			EndQuestMovie();TrackQuestMovie("end","Hit_join_Amerigo");
			bDisableFastReload = 0;
			PChar.quest.Hitman = "hit_amerigo";  //SCM
			LAi_SetPlayerType(PChar);
			LAi_SetOfficerType(CharacterFromID("Amerigo Vieira"));
			LAi_SetImmortal(CharacterFromID("Amerigo Vieira"), 0);
			AddPassenger(Pchar, characterFromID("Amerigo Vieira"), 0);   //BT May 09
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Amerigo Vieira"));
			GiveItem2Character(CharacterFromId("Amerigo Vieira"), "blade7");   			

			Pchar.quest.Hit_timer4.over = "yes";
			AddQuestRecord("Hitman", "14");

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2500);
				AddPartyExpChar(pchar, "Sneak", 1500);
			}
			else { AddPartyExp(pchar, 5000); }
		break;

		case "Hit_mark_Vito":
			PChar.quest.Hitman = "mark_vito";
			LAi_SetStayType(CharacterFromID("Vito Leone"));

			ChangeCharacterAddressGroup(CharacterFromID("Vito Leone"), "PaP_church", "goto", "goto1");
			AddQuestRecord("Hitman", "15");
		break;

		case "Hit_kill_Vito":
			bDisableFastReload = 1;
			LAi_LocationFightDisable(&Locations[FindLocation("PaP_church")], 0);

			LAi_SetActorType(CharacterFromID("Vito Leone"));
			LAi_SetImmortal(CharacterFromID("Vito Leone"), 0);
			LAi_CharacterDisableDialog(CharacterFromID("Vito Leone"));

			LAi_SetCheckMinHP(CharacterFromID("Vito Leone"), 0.0, 0, "Hit_killed_Vito");
		break;

		case "Hit_killed_Vito":
			PChar.quest.Hitman = "hit_vito";
			bDisableFastReload = 0;
			LAi_LocationFightDisable(&Locations[FindLocation("PaP_church")], 1);
			Characters[GetCharacterIndex("Vito Leone")].Location = "none";

			Pchar.quest.Hit_timer5.over = "yes";
			AddQuestRecord("Hitman", "16");

			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 7000); }
			else { AddPartyExp(pchar, 7000); }
		break;

		case "Hit_spare_Vito":
			bDisableFastReload = 1;
			LAi_CharacterDisableDialog(CharacterFromID("Vito Leone"));
			LAi_SetActorType(CharacterFromID("Vito Leone"));			
			LAi_ActorRunToLocation(characterFromID("Vito Leone"), "reload", "reload1", "none", "", "", "", 15.0);

			PChar.quest.Hit_spared_Vito.win_condition.l1 = "location";
			PChar.quest.Hit_spared_Vito.win_condition.l1.character = PChar.id;
			PChar.quest.Hit_spared_Vito.win_condition.l1.location = "Guadeloupe_Port";
			PChar.quest.Hit_spared_Vito.win_condition = "Hit_spared_Vito";

			LAi_group_SetRelation("santos_group", "santos_group", LAI_GROUP_ENEMY); //SCM
		break;

		case "Hit_spared_Vito":
			bDisableFastReload = 0;

			LAi_QuestDelay("Hit_END", 0.0);

			Pchar.quest.Hit_timer5.over = "yes";
			AddQuestRecord("Hitman", "17");

			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 4000); }
			else { AddPartyExp(pchar, 4000); }
		break;

		case "Hit_mark_Mateus":
			PChar.quest.Hitman = "mark_mateus";
			Characters[GetCharacterIndex("Mateus Santos")].Location = "none"; //SCM
			ChangeCharacterAddressGroup(CharacterFromID("Mateus Santos"), "Hit_houseB", "reload", "reload2");
			LAi_SetWarriorType(CharacterFromID("Mateus Santos")); //SCM
			LAi_warrior_DialogEnable(CharacterFromID("Mateus Santos"), 1);//SCM

			LAi_SetHuberStayType(characterFromID("Mateus Santos")); //SCM

			LAi_group_FightGroups("Santos_Group", LAI_GROUP_PLAYER, 1);

			LAi_SetStayType(CharacterFromID("Desiree' Muerte")); //SCM
			ChangeCharacterAddressGroup(CharacterFromID("Desiree' Muerte"), "Hit_passage", "goto", "goto16"); //SCM

			LAi_SetStayType(CharacterFromID("Thug3")); //SCM
			ChangeCharacterAddressGroup(CharacterFromID("Thug3"), "Hit_passage", "goto", "goto14"); //SCM

			PChar.quest.Hit_Mateus.win_condition.l1 = "location";
			PChar.quest.Hit_Mateus.win_condition.l1.character = PChar.id;
			PChar.quest.Hit_Mateus.win_condition.l1.location = "Hit_houseB";
			PChar.quest.Hit_Mateus.win_condition = "Hit_Mateus";

			Pchar.quest.Hit_timer5.over = "yes";
			AddQuestRecord("Hitman", "18");
		break;

		case "Hit_Mateus":
			bDisableFastReload = 1;
			LAi_group_MoveCharacter(CharacterFromID("Thug3"), "santos_no_group");				
			LAi_SetActorType(PChar);
			LAi_ActorDialog(PChar, CharacterFromID("Mateus Santos"), "", 4.0, -1); //SCM		
		break;

		case "Hit_kill_Mateus":
			LAi_LocationFightDisable(&Locations[FindLocation("Hit_houseB")], 0); //Fight ok SCM
			LAi_SetPlayerType(PChar);
			ChangeCharacterAddressGroup(CharacterFromID("Mateus Santos"), "Hit_study", "goto", "goto1");
			chrEnableReloadLocator("Hit_houseB", "Reload1", 0); //SCM
			chrEnableReloadLocator("Hit_study", "Reload1", 0); //SCM for testing

			LAi_SetImmortal(CharacterFromID("Thug2"), 0); //SCM
			LAi_group_FightGroups("santos_group", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("santos_group", "Hit_kill_Mateusbis");			
		break;
		
		case "Hit_kill_Mateusbis":
			chrEnableReloadLocator("Hit_houseB", "Reload2", 1); //SCM
			
			PChar.quest.Hit_Mateusb.win_condition.l1 = "location";
			PChar.quest.Hit_Mateusb.win_condition.l1.character = PChar.id;
			PChar.quest.Hit_Mateusb.win_condition.l1.location = "Hit_study";
			PChar.quest.Hit_Mateusb.win_condition = "Hit_kill_Mateusbis2";			
		break;
		
		case "Hit_kill_Mateusbis2":			
			LAi_SetActorType(CharacterFromID("Mateus Santos")); //SCM
			LAi_SetImmortal(CharacterFromID("Mateus Santos"), 0); //SCM
			LAi_ActorAttack(CharacterFromID("Mateus Santos"), PChar, ""); //SCM
			LAi_SetCheckMinHP(CharacterFromID("Mateus Santos"), 0.0, 0, "Hit_killed_Mateus"); //SCM
		break;		

		case "Hit_killed_Mateus":
			chrEnableReloadLocator("Hit_study", "Reload2_back", 1); //SCM
			chrEnableReloadLocator("Hit_passage", "Reload10", 1); //SCM			
			PChar.quest.Hitman = "hit_mateus";

			Characters[GetCharacterIndex("Mateus Santos")].Location = "none"; //SCM

			GiveItem2Character(pchar, "Santos_Ring"); //SCM
			GiveItem2Character(pchar, "Santos_Keys"); //SCM
			GiveItem2Character(pchar, "Santos_Journal1"); //SCM
			GiveItem2Character(pchar, "Santos_Journal2"); //SCM

			LAi_SetStayType(CharacterFromID("Vito Leone")); //SCM
			ChangeCharacterAddressGroup(CharacterFromID("Vito Leone"), "Redmond_church", "reload", "reload2"); //SCM

			LAi_SetStayType(CharacterFromID("Desiree' Muerte")); //SCM
			ChangeCharacterAddressGroup(CharacterFromID("Desiree' Muerte"), "Redmond_church", "goto", "goto4"); //SCM

			LAi_SetStayType(CharacterFromID("Thug3")); //SCM
			ChangeCharacterAddressGroup(CharacterFromID("Thug3"), "Redmond_church", "goto", "goto5"); //SCM
			Characters[GetCharacterIndex("Thug9")].dialog.currentnode = "begin_1";

			PChar.quest.Hit_congrats.win_condition.l1 = "location";
			PChar.quest.Hit_congrats.win_condition.l1.character = PChar.id;
			PChar.quest.Hit_congrats.win_condition.l1.location = "Redmond_church";
			PChar.quest.Hit_congrats.win_condition = "Hit_congrats";

			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 7000); }
			else { AddPartyExp(pchar, 7000); }

			LAi_SetWarriorType(CharacterfromID("Thug2"));				// Without these lines,
			LAi_SetWarriorType(CharacterfromID("Thug7"));				// three thugs in dungeon
			LAi_SetWarriorType(CharacterfromID("Thug8"));				// all cower in terror
			LAi_group_MoveCharacter(CharacterfromID("Thug2"), LAI_GROUP_MONSTERS);
			LAi_group_MoveCharacter(CharacterfromID("Thug7"), LAI_GROUP_MONSTERS);
			LAi_group_MoveCharacter(CharacterfromID("Thug8"), LAI_GROUP_MONSTERS);
		break;

		case "Hit_congrats":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Hit_congrats");
			LAi_SetActorType(PChar);
			LAi_ActorDialog(PChar, CharacterFromID("Vito Leone"), "", 4.0, -1);
		break;

		case "Hit_complete":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(CharacterFromID("Vito Leone"));
			LAi_ActorGoToLocation(CharacterFromID("Vito Leone"), "reload", "reload1", "none", "", "", "Hit_complete_end", 3.0); //SCM
			LAi_SetActorType(CharacterFromID("Desiree' Muerte")); //SCM
			LAi_ActorGoToLocation(CharacterFromID("Desiree' Muerte"), "reload", "reload1", "none", "", "", "", 3.0); //SCM
			LAi_SetActorType(CharacterFromID("Thug3")); //SCM
			LAi_ActorGoToLocation(CharacterFromID("Thug3"), "reload", "reload1", "none", "", "", "", 3.0); //SCM
			LAi_SetHuberStayType(characterFromID("Thug9")); //SCM
			ChangeCharacterAddressGroup(CharacterFromID("Thug9"), "Redmond_church", "reload", "reload3");
			LAi_SetActorType(CharacterFromID("Thug9"));  //SCM
			LAi_ActorRunToLocation(CharacterFromID("Thug9"), "reload", "reload1", "none", "", "", "", 2.0); //SCM
		break;

		case "Hit_complete_end":
			EndQuestMovie();TrackQuestMovie("end","Hit_complete_end");
			bDisableFastReload = 0;
			AddQuestRecord("Hitman", "19");
			ItemSetPrice("Santos_Keys", 1);		// Keys can now be dumped in ship's chest.
			Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_47";			
		break;
		
		case "Hit_complete_end2":
			PChar.quest.kidnapping = "governor";
			SetQuestHeader("kidnapping");
			AddQuestRecord("kidnapping", "1");	
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 5000);
				AddPartyExpChar(pchar, "Sneak", 100);
			}
			else { AddPartyExp(pchar, 5000); }
			ChangeRMRelation(pchar, SPAIN, 10.0);			
			LAi_QuestDelay("Hit_END", 0.0);				
		break;
//modified Hitman

		case "search_envoy":
			AddQuestRecord("kidnapping", "2");
			locations[FindLocation("Hispaniola_passage")].reload.l1.disable = 0;
			locations[FindLocation("Hispaniola_passage")].reload.l2.disable = 0;
            Locations[FindLocation("Hispaniola_shore_05")].models.always.general = "SP_Galeon50";
            Locations[FindLocation("Hispaniola_shore_05")].models.always.general.locator.group = "ships_other";
            Locations[FindLocation("Hispaniola_shore_05")].models.always.general.locator.name = "ship_1";
			
			ChangeCharacterAddress(characterFromID("spanish_soldier_01"), "Hispaniola_shore_05", "locator12");
			ChangeCharacterAddress(characterFromID("spanish_soldier_02"), "Hispaniola_shore_05", "citizen04");
			ChangeCharacterAddressGroup(CharacterFromID("spanish_soldier_03"), "Hispaniola_shore_05", "officers", "reload1_1");
			
			LAi_SetActorType(characterFromID("spanish_soldier_02"));
			LAi_ActorSetLayMode(characterFromID("spanish_soldier_02"));
			LAi_SetActorType(characterFromID("spanish_soldier_01"));
			LAi_ActorSetLayMode(characterFromID("spanish_soldier_01"));
			LAi_SetActorType(characterFromID("spanish_soldier_03"));
			LAi_ActorSetLayMode(characterFromID("spanish_soldier_03"));			
			
			Pchar.quest.find_survivor.win_condition.l1 = "location";
			Pchar.quest.find_survivor.win_condition.l1.location = "Hispaniola_shore_05";
			PChar.quest.find_survivor.win_condition = "sunken_ship";			
		break;
		
		case "sunken_ship":
			LAi_SetActorType(Pchar);
			LAi_ActorGoToLocator(PChar, "goto", "locator25", "sunken_ship2", 10.0);
		break;		

		case "sunken_ship2":
			LAi_SetPlayerType(Pchar);		
			Characters[GetCharacterIndex("spanish_soldier_03")].dialog.currentnode = "begin_1";			
			LAi_ActorWaitDialog(characterFromID("spanish_soldier_03"), pchar);
			LAi_ActorDialog(pchar, characterFromID("spanish_soldier_03"), "", 4.0, 1.0);
		break;

		case "leave_beach":	
			LAi_Fade("allisfine", "");
		break;

		case "allisfine":
			LAi_SetStayType(characterFromID("spanish_soldier_03"));		
	        Characters[GetCharacterIndex("spanish_soldier_03")].dialog.currentnode = "begin_3";		
            LAi_SetActorType(characterFromID("spanish_soldier_03"));
			LAi_ActorDialog(characterFromID("spanish_soldier_03"), pchar, "", 2.0, 1.0);	
		break;

		case "voltarSD":
			PChar.quest.kidnapping = "announce";
			AddQuestRecord("kidnapping", "3");			
			LAi_ActorFollowEverywhere(characterFromID("spanish_soldier_03"), "", 60.0);
		break;
		
		case "reverVA":
			LAi_SetStayType(characterFromID("spanish_soldier_03"));			
			Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_53";
			AddQuestRecord("kidnapping", "4");			
		break;
		
		case "chegabutcher":
			LAi_Fade("chegabutcher2", "");		
		break;
		
		case "chegabutcher2":
			ChangeCharacterAddress(characterFromID("spanish_soldier_03"), "none", "");		
			ChangeCharacterAddressGroup(CharacterFromID("Nicholas Butcher"), "Havana_House_03", "reload", "reload1");		
	        Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_1";		
            LAi_SetActorType(characterFromID("Nicholas Butcher"));
			LAi_ActorDialog(characterFromID("Nicholas Butcher"), pchar, "", 3.0, 1.0);	
		break;
		
		case "chegabutcher3":
			Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_60";		
            LAi_SetActorType(characterFromID("Salvadore Benavides"));
			LAi_ActorDialog(characterFromID("Salvadore Benavides"), pchar, "", 3.0, 1.0);	
		break;		

		case "irplantation":
         	LAi_SetHuberType(characterFromID("Salvadore Benavides"));		
			LAi_ActorFollowEverywhere(characterFromID("Nicholas Butcher"), "", 60.0);
            SetCompanionIndex(Pchar, -1, GetCharacterIndex("Nicholas Butcher"));			
			SetCharacterRemovable(characterFromID("Nicholas Butcher"), false);
			ChangeCharacterAddressGroup(CharacterFromID("Renouart Baumont"), "Guadeloupe_Plantation", "goto", "goto11");					
			Characters[GetCharacterIndex("Renouart Baumont")].dialog.currentnode = "begin_1";
			AddQuestRecord("kidnapping", "5");					
		break;

		case "irlady":			
			Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_4";			
			LAi_SetActorType(characterfromID("Nicholas Butcher"));
			LAi_ActorDialog(characterfromID("Nicholas Butcher"), PChar, "", 2.0, 1.0);				
		break;
		
		case "irladybis":
			Locations[FindLocation("Charlestown_House_03")].vcskip = true;			
			Locations[FindLocation("Charlestown_port")].reload.l12.disable = true;		
			ChangeCharacterAddressGroup(CharacterFromID("Lady Gaga"), "Charlestown_Brothel", "reload", "reload1_back");					
			Characters[GetCharacterIndex("Lady Gaga")].dialog.currentnode = "begin_1";
			AddQuestRecord("kidnapping", "6");
			LAi_ActorFollowEverywhere(characterFromID("Nicholas Butcher"), "", 60.0);			
		break;		
		
		case "irfora":
			AddQuestRecord("kidnapping", "7");
			
			Pchar.quest.bordel.win_condition.l1 = "location";
			Pchar.quest.bordel.win_condition.l1.location = "Charlestown_port";
			PChar.quest.bordel.win_condition = "ladyplan";			
		break;	

		case "ladyplan":
			Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_5";			
			LAi_SetActorType(characterfromID("Nicholas Butcher"));
			LAi_ActorDialog(characterfromID("Nicholas Butcher"), PChar, "", 2.0, 1.0);
		break;

		case "ladyplanbis":
			LAi_Fade("porta", "");
		break;

		case "porta":
			ChangeCharacterAddressGroup(CharacterFromID("Nicholas Butcher"), "Charlestown_port", "goto", "goto18");
			Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_7";				
			LAi_SetActorType(characterfromID("Nicholas Butcher"));
			LAi_ActorDialog(characterfromID("Nicholas Butcher"), PChar, "", 6.0, 1.0);			
		break;
		
		case "garafa":
			Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_49";				
			LAi_SetActorType(characterfromID("Chico Cois"));
			LAi_ActorDialog(characterfromID("Chico Cois"), PChar, "", 2.0, 1.0);	
		break;		
		
		case "portabis":
			LAi_SetOfficerType(characterFromID("Chico Cois"));
            StoreOfficers(pchar.id);			
			DoQuestReloadToLocation("Charlestown_port", "reload", "reload4_back","antesgaga");
		break;

		case "antesgaga":		
			ChangeCharacterAddressGroup(CharacterFromID("Nicholas Butcher"), "Charlestown_port", "goto", "goto18");
	        TakenItems(Pchar, "pistolgas", 2);   
			EquipCharacterByItem(Pchar, "pistolgas");			
			Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_9";			
			LAi_SetActorType(characterfromID("Nicholas Butcher"));
			LAi_ActorDialog(characterfromID("Nicholas Butcher"), PChar, "", 10.0, 1.0);				
		break;		

		case "seguirlady":
			LAi_ActorGoToLocator(characterFromID("Nicholas Butcher"), "goto", "goto3", "_", 50.0);		
            ChangeCharacterAddressGroup(CharacterFromID("Lady Gaga"), "Charlestown_port", "reload", "housePirate");
			GiveItem2Character(CharacterFromId("Lady Gaga"), "Piratesdagger");   
			EquipCharacterByItem(CharacterFromId("Lady Gaga"), "Piratesdagger");			
			LAi_SetCitizenType(characterFromID("Lady Gaga"));
			GiveItem2Character(CharacterFromId("Lady Gaga"), "Gaga_Keys");
   			
			pchar.quest.lady_died.win_condition.l1 = "NPC_Death";
			pchar.quest.lady_died.win_condition.l1.character = "Lady Gaga";
			pchar.quest.lady_died.win_condition = "mortelady";

			DoQuestCheckDelay("seguirladybis", 50.0);          	
		break;
		
		case "seguirladybis":
			if (!CheckCharacterItem(CharacterFromId("Lady Gaga"),"Gaga_Keys"))
			{	
			Locations[FindLocation("Charlestown_port")].reload.l12.disable = false;
			Locations[FindLocation("Charlestown_port")].reload.l12.close_for_night = 0; // GR
			
			pchar.quest.trouver.win_condition.l1 = "locator";
			pchar.quest.trouver.win_condition.l1.location = "Charlestown_House_03";
			pchar.quest.trouver.win_condition.l1.locator_group = "box";
			pchar.quest.trouver.win_condition.l1.locator = "box1";
			pchar.quest.trouver.win_condition = "lettergaga";			
			}
			else
			{
			Pchar.quest.lady_died.over = "yes";			
			LAi_SetImmortal(CharacterFromID("Lady Gaga"), 1);		
			LAi_SetActorType(CharacterFromID("Lady Gaga"));
			LAi_ActorGoToLocation(CharacterFromID("Lady Gaga"), "reload", "houseSp3", "none", "", "", "", 60.0);
			AddQuestRecord("kidnapping", "8");			
            }			
		break;		

		case "mortelady":
			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "goto", "goto10");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade13");
			EquipCharacterByItem(sld, "blade13");
			sld.dialog.filename = "Divers_dialog.c";
			sld.dialog.currentnode = "begin_6";
			sld.id = "ingles";
			LAi_SetActorType(characterfromID("ingles"));
			LAi_ActorDialog(characterfromID("ingles"), PChar, "", 10.0, 1.0);
		break;

		case "lettergaga":
			Pchar.quest.lady_died.over = "yes";
		    GiveItem2Character(Pchar, "Roche_letter");				
			ChangeCharacterAddress(characterFromID("Lady Gaga"), "none", "");			
			ChangeCharacterAddressGroup(CharacterFromID("Nicholas Butcher"), "Charlestown_House_03", "reload", "reload1");
			Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_10";			
			LAi_SetActorType(characterfromID("Nicholas Butcher"));
			LAi_ActorDialog(characterfromID("Nicholas Butcher"), PChar, "", 3.0, 1.0);			
		break;

		case "ircuracao":
			PChar.quest.kidnapping = "taberna";		
			LAi_ActorFollowEverywhere(characterFromID("Nicholas Butcher"), "", 60.0);	
			AddQuestRecord("kidnapping", "9");
            RestoreOfficers(pchar.id);			
		break;

		case "iraldeia":
			AddQuestRecord("kidnapping", "10");			
			Locations[FindLocation("Curacao_village")].reload.l2.disable = true;		
			ChangeCharacterAddressGroup(CharacterFromID("Roche_guard_01"), "Curacao_village", "officers", "reload2_2");
			ChangeCharacterAddressGroup(CharacterFromID("Roche_guard_02"), "Curacao_village", "officers", "reload2_1");
			
			Pchar.quest.village.win_condition.l1 = "location";
			Pchar.quest.village.win_condition.l1.location = "Curacao_village";
			PChar.quest.village.win_condition = "verguard";				
		break;
		
		case "verguard":
			Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_13";			
			ChangeCharacterAddressGroup(CharacterFromID("Nicholas Butcher"), "Curacao_village", "goto", "character4");
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(CharacterFromID("Nicholas Butcher"), Pchar);		
			LAi_ActorDialog(PChar, CharacterFromID("Nicholas Butcher"), "", 8.0, 1);			
		break;

		case "verguardbis":
			LAi_ActorTurnToCharacter(PChar, characterFromID("Roche_guard_02"));			
            LAi_QuestDelay("verguardbis2", 3.0);			
		break;

		case "verguardbis2":
			Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_14";
			LAi_ActorWaitDialog(CharacterFromID("Nicholas Butcher"), Pchar);			
			LAi_ActorDialog(PChar, CharacterFromID("Nicholas Butcher"), "", 2.0, 1);			
		break;

		case "irinkeeper":
			LAi_SetPlayerType(PChar);
			LAi_ActorFollowEverywhere(characterFromID("Nicholas Butcher"), "", 60.0);
			ChangeCharacterAddressGroup(CharacterFromID("Hans Delorme"), "Village_Tavern", "goto", "goto6");
			Characters[GetCharacterIndex("Hans Delorme")].dialog.currentnode = "begin_1";			
		break;

		case "falaButcher":
			Locations[FindLocation("Curacao_village")].vcskip = true;		
			Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_16";
            LAi_SetActorType(characterFromID("Nicholas Butcher"));			
			LAi_ActorDialog(characterfromID("Nicholas Butcher"), PChar, "", 3.0, 1.0);				
		break;

		case "foravillage":
			SetCurrentTime(23, 0);
			Locations[FindLocation("Curacao_village")].reload.l1.disable = true;
			Locations[FindLocation("Curacao_village")].reload.l7.disable = true;			
			DoQuestReloadToLocation("Curacao_village", "reload", "reload6","antesop");			
		break;

		case "antesop":
			Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_18";		
			ChangeCharacterAddressGroup(CharacterFromID("Nicholas Butcher"), "Curacao_village", "goto", "goto8");
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(CharacterFromID("Nicholas Butcher"), Pchar);			
			LAi_ActorDialog(PChar, CharacterFromID("Nicholas Butcher"), "", 2.0, 1);				
		break;

		case "antesopbis":
			Locations[FindLocation("Village_House_01")].vcskip = true;
			LAi_SetImmortal(CharacterFromID("Roche_guard_01"), false); 
			LAi_SetImmortal(CharacterFromID("Roche_guard_02"), false); 			
			DisableFastTravel(true);
			DisableMenuLaunch(true);		
			LAi_SetPlayerType(PChar);
            LAi_SetOfficerType(characterFromID("Nicholas Butcher"));
			LAi_group_FightGroups("ROCHE_HOUSE", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("ROCHE_HOUSE", "afterataque");			
		break;

		case "afterataque":
            LAi_SetActorType(characterFromID("Nicholas Butcher"));
			LAi_ActorGoToLocator(CharacterFromID("Nicholas Butcher"), "officers", "reload2_2", "_", 15.0);	
			Locations[FindLocation("Curacao_village")].reload.l2.disable = false;			
			ChangeCharacterAddressGroup(CharacterFromID("Cesario de Rosas"), "Village_House_01", "goto", "goto7");
			Characters[GetCharacterIndex("Cesario de Rosas")].dialog.currentnode = "begin_1";			
			ChangeCharacterAddressGroup(CharacterFromID("Roche_guard_03"), "Village_House_01", "goto", "goto3");
	        LAi_group_SetRelation("ROCHE_GARDAS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);			
		break;

		case "leavealdeia":
			LAi_SetActorType(characterFromID("Cesario de Rosas"));
			LAi_ActorFollowEverywhere(characterFromID("Cesario de Rosas"), "", 60.0);
			
			Pchar.quest.aldeia_men.win_condition.l1 = "location";
			Pchar.quest.aldeia_men.win_condition.l1.location = "Curacao_village";
			PChar.quest.aldeia_men.win_condition = "cesariogo";				
		break;

		case "cesariogo":
			Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_19";
			LAi_ActorDialog(characterfromID("Nicholas Butcher"), PChar, "", 4.0, 1.0);					
		break;

		case "cesariogobis":
			LAi_SetActorType(characterFromID("Nicholas Butcher"));
			LAi_ActorRunToLocation(characterFromID("Nicholas Butcher"), "reload", "reload1", "none", "", "", "", 5.0);
			LAi_SetActorType(characterFromID("Cesario de Rosas"));
			LAi_ActorRunToLocation(characterFromID("Cesario de Rosas"), "reload", "reload1", "none", "", "", "", 5.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat4", "reload", "reload9");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ROCHE_GARDAS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat5", "reload", "reload9");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ROCHE_GARDAS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat6", "reload", "reload9");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ROCHE_GARDAS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat7", "reload", "reload9");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ROCHE_GARDAS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat8", "reload", "reload9");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ROCHE_GARDAS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat9", "reload", "reload9");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ROCHE_GARDAS");

			LAi_group_FightGroups("ROCHE_GARDAS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("ROCHE_GARDAS", "batalha");			
		break;			

		case "batalha":
			ChangeCharacterAddress(characterFromID("Hans Delorme"), "none", "");			
			RemoveCharacterCompanion(Pchar, characterFromID("Nicholas Butcher"));
			SetCharacterRemovable(characterFromID("Nicholas Butcher"), true);		
			Locations[FindLocation("Curacao_village")].reload.l1.disable = false;
			Locations[FindLocation("Curacao_village")].reload.l7.disable = false;
			DisableFastTravel(false);
			DisableMenuLaunch(false);
            DeleteAttribute(&Locations[FindLocation("Curacao_village")],"vcskip");
			AddQuestRecord("kidnapping", "11");
            LAi_QuestDelay("rocheship", 0.0);			
		break;

		case "rocheship":
            switch(rand(15))
{
      case 0: 
    			Group_CreateGroup("Roche_Ship"); 
    			Group_AddCharacter("Roche_Ship", "Roche Brasiliano");
    			Group_SetGroupCommander("Roche_Ship", "Roche Brasiliano");
     			Group_SetAddress("Roche_Ship", "QuebradasCostillas", "Quest_Ships","Quest_Ship_9");

			Pchar.quest.Meet_Rocheship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Rocheship.win_condition.l1.character = "Roche Brasiliano";
			Pchar.quest.Meet_Rocheship.win_condition = "capture_roche";						
      break;
	  
      case 1: 
    			Group_CreateGroup("Roche_Ship"); 
    			Group_AddCharacter("Roche_Ship", "Roche Brasiliano");
    			Group_SetGroupCommander("Roche_Ship", "Roche Brasiliano");
     			Group_SetAddress("Roche_Ship", "FalaiseDeFleur", "Quest_Ships","Quest_Ship_9");

			Pchar.quest.Meet_Rocheship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Rocheship.win_condition.l1.character = "Roche Brasiliano";
			Pchar.quest.Meet_Rocheship.win_condition = "capture_roche";						
      break;
	  
      case 2: 
    			Group_CreateGroup("Roche_Ship"); 
    			Group_AddCharacter("Roche_Ship", "Roche Brasiliano");
    			Group_SetGroupCommander("Roche_Ship", "Roche Brasiliano");
     			Group_SetAddress("Roche_Ship", "Aruba", "Quest_Ships","Quest_Ship_8");

			Pchar.quest.Meet_Rocheship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Rocheship.win_condition.l1.character = "Roche Brasiliano";
			Pchar.quest.Meet_Rocheship.win_condition = "capture_roche";						
      break;
	  
      case 3: 
    			Group_CreateGroup("Roche_Ship"); 
    			Group_AddCharacter("Roche_Ship", "Roche Brasiliano");
    			Group_SetGroupCommander("Roche_Ship", "Roche Brasiliano");
     			Group_SetAddress("Roche_Ship", "Eleuthera", "Quest_Ships","Quest_Ship_9");

			Pchar.quest.Meet_Rocheship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Rocheship.win_condition.l1.character = "Roche Brasiliano";
			Pchar.quest.Meet_Rocheship.win_condition = "capture_roche";						
      break;
	  
      case 4: 
    			Group_CreateGroup("Roche_Ship"); 
    			Group_AddCharacter("Roche_Ship", "Roche Brasiliano");
    			Group_SetGroupCommander("Roche_Ship", "Roche Brasiliano");
     			Group_SetAddress("Roche_Ship", "Turks", "Quest_Ships","Quest_Ship_9");

			Pchar.quest.Meet_Rocheship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Rocheship.win_condition.l1.character = "Roche Brasiliano";
			Pchar.quest.Meet_Rocheship.win_condition = "capture_roche";						
      break;
	  
      case 5: 
    			Group_CreateGroup("Roche_Ship"); 
    			Group_AddCharacter("Roche_Ship", "Roche Brasiliano");
    			Group_SetGroupCommander("Roche_Ship", "Roche Brasiliano");
     			Group_SetAddress("Roche_Ship", "Antigua", "Quest_Ships","Quest_Ship_9");

			Pchar.quest.Meet_Rocheship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Rocheship.win_condition.l1.character = "Roche Brasiliano";
			Pchar.quest.Meet_Rocheship.win_condition = "capture_roche";						
      break;
	  
      case 6: 
    			Group_CreateGroup("Roche_Ship"); 
    			Group_AddCharacter("Roche_Ship", "Roche Brasiliano");
    			Group_SetGroupCommander("Roche_Ship", "Roche Brasiliano");
     			Group_SetAddress("Roche_Ship", "SaintMartin", "Quest_Ships","Quest_Ship_9");	
				
			Pchar.quest.Meet_Rocheship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Rocheship.win_condition.l1.character = "Roche Brasiliano";
			Pchar.quest.Meet_Rocheship.win_condition = "capture_roche";						
      break;

      case 7: 
    			Group_CreateGroup("Roche_Ship"); 
    			Group_AddCharacter("Roche_Ship", "Roche Brasiliano");
    			Group_SetGroupCommander("Roche_Ship", "Roche Brasiliano");
     			Group_SetAddress("Roche_Ship", "Guadeloupe", "Quest_Ships","Quest_Ship_9");

			Pchar.quest.Meet_Rocheship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Rocheship.win_condition.l1.character = "Roche Brasiliano";
			Pchar.quest.Meet_Rocheship.win_condition = "capture_roche";						
      break;
	  
      case 8: 
    			Group_CreateGroup("Roche_Ship"); 
    			Group_AddCharacter("Roche_Ship", "Roche Brasiliano");
    			Group_SetGroupCommander("Roche_Ship", "Roche Brasiliano");
     			Group_SetAddress("Roche_Ship", "Hispaniola", "Quest_Ships","Quest_Ship_9");

			Pchar.quest.Meet_Rocheship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Rocheship.win_condition.l1.character = "Roche Brasiliano";
			Pchar.quest.Meet_Rocheship.win_condition = "capture_roche";						
      break;
	  
      case 9: 
    			Group_CreateGroup("Roche_Ship"); 
    			Group_AddCharacter("Roche_Ship", "Roche Brasiliano");
    			Group_SetGroupCommander("Roche_Ship", "Roche Brasiliano");
     			Group_SetAddress("Roche_Ship", "Cayman", "Quest_Ships","Quest_Ship_9");

			Pchar.quest.Meet_Rocheship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Rocheship.win_condition.l1.character = "Roche Brasiliano";
			Pchar.quest.Meet_Rocheship.win_condition = "capture_roche";						
      break;
	  
      case 10: 
    			Group_CreateGroup("Roche_Ship"); 
    			Group_AddCharacter("Roche_Ship", "Roche Brasiliano");
    			Group_SetGroupCommander("Roche_Ship", "Roche Brasiliano");
     			Group_SetAddress("Roche_Ship", "KhaelRoa", "Quest_Ships","Quest_Ship_8");

			Pchar.quest.Meet_Rocheship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Rocheship.win_condition.l1.character = "Roche Brasiliano";
			Pchar.quest.Meet_Rocheship.win_condition = "capture_roche";						
      break;

      case 11: 
    			Group_CreateGroup("Roche_Ship"); 
    			Group_AddCharacter("Roche_Ship", "Roche Brasiliano");
    			Group_SetGroupCommander("Roche_Ship", "Roche Brasiliano");
     			Group_SetAddress("Roche_Ship", "Douwesen", "Quest_Ships","Quest_Ship_9");

			Pchar.quest.Meet_Rocheship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Rocheship.win_condition.l1.character = "Roche Brasiliano";
			Pchar.quest.Meet_Rocheship.win_condition = "capture_roche";						
      break;
	  
      case 12: 
    			Group_CreateGroup("Roche_Ship"); 
    			Group_AddCharacter("Roche_Ship", "Roche Brasiliano");
    			Group_SetGroupCommander("Roche_Ship", "Roche Brasiliano");
     			Group_SetAddress("Roche_Ship", "Conceicao", "Quest_Ships","Quest_Ship_9");

			Pchar.quest.Meet_Rocheship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Rocheship.win_condition.l1.character = "Roche Brasiliano";
			Pchar.quest.Meet_Rocheship.win_condition = "capture_roche";						
      break;
	  
      case 13: 
    			Group_CreateGroup("Roche_Ship"); 
    			Group_AddCharacter("Roche_Ship", "Roche Brasiliano");
    			Group_SetGroupCommander("Roche_Ship", "Roche Brasiliano");
     			Group_SetAddress("Roche_Ship", "Oxbay", "Quest_Ships","Quest_Ship_9");

			Pchar.quest.Meet_Rocheship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Rocheship.win_condition.l1.character = "Roche Brasiliano";
			Pchar.quest.Meet_Rocheship.win_condition = "capture_roche";						
      break;
	  
      case 14: 
    			Group_CreateGroup("Roche_Ship"); 
    			Group_AddCharacter("Roche_Ship", "Roche Brasiliano");
    			Group_SetGroupCommander("Roche_Ship", "Roche Brasiliano");
     			Group_SetAddress("Roche_Ship", "IslaMuelle", "Quest_Ships","Quest_Ship_9");

			Pchar.quest.Meet_Rocheship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Rocheship.win_condition.l1.character = "Roche Brasiliano";
			Pchar.quest.Meet_Rocheship.win_condition = "capture_roche";						
      break;

      case 15: 
    			Group_CreateGroup("Roche_Ship"); 
    			Group_AddCharacter("Roche_Ship", "Roche Brasiliano");
    			Group_SetGroupCommander("Roche_Ship", "Roche Brasiliano");
     			Group_SetAddress("Roche_Ship", "Redmond", "Quest_Ships","Quest_Ship_9");

			Pchar.quest.Meet_Rocheship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Rocheship.win_condition.l1.character = "Roche Brasiliano";
			Pchar.quest.Meet_Rocheship.win_condition = "capture_roche";						
      break;
}
		break;

		case "capture_roche":
			AddQuestRecord("kidnapping", "12");		
		
			pchar.quest.arrest.win_condition.l1 = "location";
			pchar.quest.arrest.win_condition.l1.location = "Cuba";
			pchar.quest.arrest.win_condition = "capture_rocheB";
		break;			

		case "capture_rocheB":
			DisableFastTravel(true);
			DisableMenuLaunch(true);
            DoQuestCheckDelay("capture_rocheB3", 5.0);		
		break;
		
		case "capture_rocheB3":			
			DoReloadFromSeaToLocation("Quest_Havana_fort", "rld", "loc3");
            ChangeCharacterAddressGroup(CharacterFromID("Rock Braziliano"), "Quest_Havana_fort", "rld", "loc0");			
			LAi_SetStayType(characterFromID("Rock Braziliano"));			
            ChangeCharacterAddressGroup(CharacterFromID("Salvadore Benavides"), "Quest_Havana_fort", "rld", "aloc9");			
			LAi_SetStayType(characterFromID("Salvadore Benavides"));
            ChangeCharacterAddressGroup(CharacterFromID("Felipe Cisneros"), "Quest_Havana_fort", "rld", "aloc2");			
			LAi_SetStayType(characterFromID("Felipe Cisneros"));			
			
			pchar.quest.havana_fort.win_condition.l1 = "location";
			pchar.quest.havana_fort.win_condition.l1.location = "Quest_Havana_fort";
			pchar.quest.havana_fort.win_condition = "soldados_forte";
		break;
		
		case "soldados_forte":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "rld", "character_1");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDATS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "rld", "character_3");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDATS");	
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "rld", "aloc3");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDATS");	

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa5_16", "rld", "loc6");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "CUBAN_SOLDATS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "animists2", "rld", "character_2");
			LAi_SetHP(sld, 80.0, 80.0);
  			LAi_group_MoveCharacter(sld, "CUBAN_SOLDATS");
			TakeItemFromCharacter(sld, GetCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld,"bladeaxe1");										
			EquipCharacterByItem(sld,"bladeaxe1");
          	SetCharacterShipLocation(Pchar, "Cuba_port");
			Characters[GetCharacterIndex("Rock Braziliano")].dialog.currentnode = "begin_1";				
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(CharacterFromID("Rock Braziliano"), Pchar);			
			LAi_ActorDialog(PChar, CharacterFromID("Rock Braziliano"), "", 2.0, 1);			
		break;

		case "Benavides_forte":
			Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_61";		
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(CharacterFromID("Salvadore Benavides"), Pchar);			
			LAi_ActorDialog(PChar, CharacterFromID("Salvadore Benavides"), "", 3.0, 1);
		break;

		case "Governador_forte":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Felipe Cisneros"));
			Characters[GetCharacterIndex("Felipe Cisneros")].dialog.currentnode = "gov_1";
			LAi_ActorDialog(characterFromID("Felipe Cisneros"), pchar, "", 4.0, 1.0);
		break;

		case "BenavidesBis_forte":
			LAi_SetActorType(characterFromID("Salvadore Benavides"));
			Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_63";
			LAi_ActorDialog(characterFromID("Salvadore Benavides"), pchar, "", 2.0, 1.0);
		break;

		case "voltarporto":
            Build_at("Cuba_port", "roche", "", 77.03, 21.5, -115.2, -0.1, "");			
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			DoQuestReloadToLocation("Cuba_port", "reload", "sea_1","voltarportobis");			
		break;

		case "voltarportobis":
            GiveModel2Player("Johan_Elting_c", false);		
            ChangeCharacterAddressGroup(CharacterFromID("Salvadore Benavides"), "Havana_House_03", "sit", "sit1");			
			LAi_SetHuberType(characterFromID("Salvadore Benavides"));
            ChangeCharacterAddressGroup(CharacterFromID("Felipe Cisneros"), "Havana_townhall", "sit", "sit1");			
			LAi_SetHuberType(characterFromID("Felipe Cisneros"));
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			ChangeRMRelation(pchar, SPAIN, 10.0);
            LAi_QuestDelay("practice_timer1", 0.0);			
		break;

		case "practice_timer1":
			PChar.quest.practice_timer1.win_condition.l1 = "Timer";
			PChar.quest.practice_timer1.win_condition.l1.date.day = GetAddingDataDay(0, 0, 30);
			PChar.quest.practice_timer1.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 30);
			PChar.quest.practice_timer1.win_condition.l1.date.year = GetAddingDataYear(0, 0, 30);
			PChar.quest.practice_timer1.win_condition = "practice_fin_timer";
		break;

		case "practice_fin_timer":
			AddQuestRecord("kidnapping", "13");			
			CloseQuestHeader("kidnapping");
			Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_65";			
		break;

		case "irAntigua":
			SetQuestHeader("Cannons");
			AddQuestRecord("Cannons", "1");
            ChangeCharacterAddressGroup(CharacterFromID("Pelagius Lizarraga"), "Antigua_port", "officers", "reload7_2");			
			Characters[GetCharacterIndex("Pelagius Lizarraga")].dialog.currentnode = "begin_5";			
		break;

		case "irAntiguaAlmirante":		
            PChar.quest.veralmirante = "inicio";
			LAi_SetActorType(characterFromID("Pelagius Lizarraga"));
			LAi_ActorRunToLocation(characterfromID("Pelagius Lizarraga"), "reload", "reload7_back", "none", "", "", "", 10.0);			
		break;
		
		case "FrenchPinnace":
			AddQuestRecord("Cannons", "2");		
     		Characters[GetCharacterIndex("antigua_portadmiral")].dialog.filename = "Divers_dialog.c";				
    			Group_CreateGroup("Rabel_Ship"); 
    			Group_AddCharacter("Rabel_Ship", "Rabel Chardon");
    			Group_SetGroupCommander("Rabel_Ship", "Rabel Chardon");
     			Group_SetAddress("Rabel_Ship", "Guadeloupe", "Quest_Ships","Quest_Ship_9");

			Pchar.quest.French_Pinnace.win_condition.l1 = "NPC_Death";
			Pchar.quest.French_Pinnace.win_condition.l1.character = "Rabel Chardon";
			Pchar.quest.French_Pinnace.win_condition = "voltantigua";			
		break;

		case "voltantigua":
			AddQuestRecord("Cannons", "3");			
			Characters[GetCharacterIndex("antigua_portadmiral")].dialog.currentnode = "begin_7";				
		break;

		case "vertrigger":
            ChangeCharacterAddressGroup(CharacterFromID("Jeremy Tripper"), "Antigua_mansion_study", "reload", "reload1");			
			Characters[GetCharacterIndex("Jeremy Tripper")].dialog.currentnode = "begin_1";
			LAi_SetActorType(characterFromID("Jeremy Tripper"));
			LAi_ActorDialog(characterFromID("Jeremy Tripper"), pchar, "", 5.0, 1.0);			
		break;

		case "leave_antigua":
			AddQuestRecord("Cannons", "4");		
			LAi_SetImmortal(CharacterFromID("Jeremy Tripper"), 1);		
            SetCompanionIndex(Pchar, -1, GetCharacterIndex("Jeremy Tripper"));			
		//	SetCharacterRemovable(characterFromID("Jeremy Tripper"), false);

			pchar.quest.khael_shore.win_condition.l1 = "location";
			pchar.quest.khael_shore.win_condition.l1.location = "KhaelRoa_port";
			pchar.quest.khael_shore.win_condition = "explorar_start";			
		break;

		case "explorar_start":
            ChangeCharacterAddressGroup(CharacterFromID("Jeremy Tripper"), "KhaelRoa_port", "goto", "goto3");
			Characters[GetCharacterIndex("Jeremy Tripper")].dialog.currentnode = "begin_4";
			LAi_SetActorType(characterFromID("Jeremy Tripper"));
			LAi_ActorDialog(characterFromID("Jeremy Tripper"), pchar, "", 5.0, 1.0);				
		break;

		case "leave_khaelshore":
        	Build_at("temple", "hut", "", -26.38, 15.76, 18.75, -2.89, "building");
        	Build_at("temple", "hut", "", -23.74, 16.31, -4.26, -1.61, "building");
            Locations[FindLocation("temple")].townsack = "Falaise de Fleur";
            Locations[FindLocation("temple")].models.always.general = "hutFlag";
            Locations[FindLocation("temple")].models.always.general .locator.group = "goto";
            Locations[FindLocation("temple")].models.always.general .locator.name = "goto9";
			
			LAi_SetActorType(characterFromID("Jeremy Tripper"));
			LAi_ActorFollowEverywhere(characterFromID("Jeremy Tripper"), "", 60.0);
			Locations[FindLocation("temple")].locators_radius.goto.goto9 = 12.0;			
			
			pchar.quest.find_camp.win_condition.l1 = "locator";
			pchar.quest.find_camp.win_condition.l1.location = "temple";
			pchar.quest.find_camp.win_condition.l1.locator_group = "goto";
			pchar.quest.find_camp.win_condition.l1.locator = "goto9";
			pchar.quest.find_camp.win_condition = "encontra_campo";			
		break;

		case "encontra_campo":
			Characters[GetCharacterIndex("Jeremy Tripper")].dialog.currentnode = "begin_6";
			LAi_SetActorType(characterFromID("Jeremy Tripper"));
			LAi_ActorDialog(characterFromID("Jeremy Tripper"), pchar, "", 5.0, 1.0);	
		break;

		case "entrar_temple":
			Locations[FindLocation("temple")].locators_radius.goto.goto9 = 1.0;
			LAi_SetActorType(characterFromID("Jeremy Tripper"));
            LAi_SetOfficerType(characterFromID("Jeremy Tripper"));

			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m1, "reload", "reload2");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");		 
			LAi_group_MoveCharacter(sld, "TEMPLE_SOLDIERS");

			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m2, "reload", "reload2");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");		 
			LAi_group_MoveCharacter(sld, "TEMPLE_SOLDIERS");

			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m3, "reload", "reload2");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");		 
			LAi_group_MoveCharacter(sld, "TEMPLE_SOLDIERS");
			

			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m4, "reload", "reload2");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");		 
			LAi_group_MoveCharacter(sld, "TEMPLE_SOLDIERS");

			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m5, "reload", "reload2");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");		 
			LAi_group_MoveCharacter(sld, "TEMPLE_SOLDIERS");

			 sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[FRANCE].fantomModel.m6, "reload", "reload2");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");		 
			LAi_group_MoveCharacter(sld, "TEMPLE_SOLDIERS");

			LAi_group_FightGroups("TEMPLE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("TEMPLE_SOLDIERS", "depois_combate");						
		break;

		case "depois_combate":
			Locations[FindLocation("temple")].locators_radius.goto.goto9 = 1.0;		
			Characters[GetCharacterIndex("Jeremy Tripper")].dialog.currentnode = "begin_10";
			LAi_SetActorType(characterFromID("Jeremy Tripper"));
			LAi_ActorDialog(characterFromID("Jeremy Tripper"), pchar, "", 5.0, 1.0);	
		break;
		
        case "French_Ship_Khael":		
         	SetCharacterRelationBoth(GetCharacterIndex("Clement Bossicar"),GetMainCharacterIndex(),RELATION_ENEMY);
			
			Group_CreateGroup("Clement Bossicar");
			Group_AddCharacter("Clement Bossicar", "Clement Bossicar");
			Group_SetGroupCommander("Clement Bossicar", "Clement Bossicar");
			Group_SetPursuitGroup("Clement Bossicar", PLAYER_GROUP);
			Group_SetTaskAttack("Clement Bossicar", PLAYER_GROUP, true);
			Group_LockTask("Clement Bossicar");
			Group_SetAddress("Clement Bossicar", "KhaelRoa", "Quest_ships", "Quest_ship_12");
			characters[GetCharacterIndex("Clement Bossicar")].nosurrender = 2;

			SetRMRelation(PChar, FRANCE, REL_WAR);
			QuestToSeaLogin_PrepareLoc("KhaelRoa", "reload", "reload_1", true);
			QuestToSeaLogin_Launch();		
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal("KhaelRoa", false);		

			Pchar.quest.Meet_Bossicarship.win_condition.l1 = "NPC_Death";
			Pchar.quest.Meet_Bossicarship.win_condition.l1.character = "Clement Bossicar";
			Pchar.quest.Meet_Bossicarship.win_condition = "Capture_Bossicarship";		
		break;
		
        case "Capture_Bossicarship":
			bQuestDisableMapEnter = false;
			Island_SetReloadEnableGlobal("KhaelRoa", true);				
			Pchar.quest.Meet_Bossicarship.over = "yes";
			AddQuestRecord("Cannons","5");
			
			pchar.quest.rever_pela.win_condition.l1 = "location";
			pchar.quest.rever_pela.win_condition.l1.location = "Antigua_port";
			pchar.quest.rever_pela.win_condition = "news_pelagius";				
		break;

        case "news_pelagius":
            ChangeCharacterAddressGroup(CharacterFromID("Pelagius Lizarraga"), "Antigua_port", "goto", "goto24");
			Characters[GetCharacterIndex("Pelagius Lizarraga")].dialog.currentnode = "begin_12";
			LAi_SetActorType(characterFromID("Pelagius Lizarraga"));
			LAi_ActorDialog(characterFromID("Pelagius Lizarraga"), pchar, "", 25.0, 1.0);
		break;

        case "rever_Portadmiral":
			Characters[GetCharacterIndex("antigua_portadmiral")].dialog.currentnode = "begin_12";            
			LAi_SetActorType(characterFromID("Pelagius Lizarraga"));
			LAi_ActorRunToLocation(characterfromID("Pelagius Lizarraga"), "reload", "reload4_back", "none", "", "", "", 20.0);	
		break;

        case "ver_Larner":
			AddQuestRecord("Cannons", "6");		
			RemoveCharacterCompanion(Pchar, characterFromID("Jeremy Tripper"));
			setCharacterShipLocation(characterFromID("Jeremy Tripper"), "none");
            ChangeCharacterAddress(characterFromID("Jeremy Tripper"), "none", "");			
            ChangeCharacterAddressGroup(CharacterFromID("Wilfred Larner"), "Antigua_port", "reload", "sea_2");
			Characters[GetCharacterIndex("Wilfred Larner")].dialog.currentnode = "begin_1";			
		break;

		case "ir_mona":
			PChar.quest.disable_rebirth = true;
			Locations[FindLocation("IslaMona_port")].models.always.fort = "fortress";
			Locations[FindLocation("IslaMona_port")].models.always.fort .locator.group = "ships_other";
			Locations[FindLocation("IslaMona_port")].models.always.fort .locator.name = "ship_8";
			SetCharacterShipLocation(characterFromID("Randolf Blecher"), "IslaMona_port");

			Characters[GetCharacterIndex("Randolf Blecher")].nation = ENGLAND;
			Characters[GetCharacterIndex("Wilfred Burman")].nation = ENGLAND;
			SetModelFromID(CharacterFromID("Wilfred Burman"), "Offic_Eng_16");
			for(n = 1; n <=20; n++)
			{
				sld = characterFromID("Mona_patrol_" + n);
				sld.nation = ENGLAND;
				SetModelFromID(sld, "Soldier_Eng"+(rand(4)+2)+"_16");
			}		
			
			Island_SetReloadEnableLocal("IslaMona", "reload_1", true);		
			Islands[FindIsland("IslaMona")].reload.l1.goto_enable = true;
			
            		SetCompanionIndex(Pchar, -1, GetCharacterIndex("Wilfred Larner"));			
			SetCharacterRemovable(characterFromID("Wilfred Larner"), false);
			AddCharacterGoods(characterFromID("Wilfred Larner"), GOOD_FRUITS, 100);
			AddCharacterGoods(characterFromID("Wilfred Larner"), GOOD_SUGAR, 50);
			AddCharacterGoods(characterFromID("Wilfred Larner"), GOOD_TOBACCO, 50);
			AddCharacterGoods(characterFromID("Wilfred Larner"), GOOD_RUM, 100);
			AddCharacterGoods(characterFromID("Wilfred Larner"), GOOD_FOOD, 300);			

			pchar.quest.larner_died.win_condition.l1 = "NPC_Death";
			pchar.quest.larner_died.win_condition.l1.character = "Wilfred Larner";
			pchar.quest.larner_died.win_condition = "died_larner";
			
			Pchar.quest.islamona_shore.win_condition.l1 = "location";
			Pchar.quest.islamona_shore.win_condition.l1.location = "IslaMona_port";
			Pchar.quest.islamona_shore.win_condition = "arrived_islamona";			
		break;

		case "died_larner":
			Island_SetReloadEnableLocal("IslaMona", "reload_1", false);
			Islands[FindIsland("IslaMona")].reload.l1.goto_enable = false;
		break;

		case "arrived_islamona":
			if (!isOfficer(characterFromID("Chico Cois")))
			{
				LAi_SetActorType(characterFromID("Chico Cois"));	// GR: necessary to make him appear
           			ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "IslaMona_port", "officers", "reload3_3");
				LAi_SetOfficerType(characterFromID("Chico Cois"));	// GR: must be *after* 'ChangeCharacterAddressGroup'
			}

        		SetCurrentTime(17.00, 0);		
			Locations[FindLocation("IslaMona_port")].reload.l1.disable = 1;
			Locations[FindLocation("IslaMona_port")].reload.l3.disable = 1;
			Locations[FindLocation("IslaMona_port")].reload.l6.disable = 1;			
			Locations[FindLocation("IslaMona_port_exit")].reload.l2.disable = 1;
			Locations[FindLocation("IslaMona_port_exit")].reload.l4.disable = 1;				
			pchar.quest.larner_died.over = "yes";
           		ChangeCharacterAddressGroup(CharacterFromID("Wilfred Larner"), "IslaMona_port", "goto", "goto2");
			Characters[GetCharacterIndex("Wilfred Larner")].dialog.currentnode = "begin_4";
			LAi_SetActorType(characterFromID("Wilfred Larner"));
			LAi_ActorDialog(characterFromID("Wilfred Larner"), pchar, "", 15.0, 1.0);			
		break;

		case "ver_IMPA":
			if (!isOfficer(characterFromID("Chico Cois")))
			{
				SetOfficersIndex(Pchar, 3, GetCharacterIndex("Chico Cois"));
//				LAi_SetOfficerType(characterFromID("Chico Cois"));
			}
			Locations[FindLocation("IslaMona_Headport_house")].vcskip = true;
			RemoveCharacterCompanion(Pchar, characterFromID("Wilfred Larner"));				
            		LAi_SetActorType(characterfromID("Wilfred Larner"));
			LAi_ActorRunToLocation(characterfromID("Wilfred Larner"), "reload", "reload6", "none", "", "", "", 25.0);
			LAi_SetActorType(characterFromID("Chico Cois"));
			Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_51";			
			LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 5.0, 2.0);			
		break;

		case "cois_fort":
			Characters[GetCharacterIndex("Randolf Blecher")].dialog.currentnode = "begin_1";		
			RemovePassenger(pchar, characterFromID("Chico Cois"));
			RemoveCharacterCompanion(pchar, characterFromID("Chico Cois"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Chico Cois"));		
            LAi_SetActorType(characterfromID("Chico Cois"));
			LAi_ActorRunToLocation(characterfromID("Chico Cois"), "reload", "reload1_back", "none", "", "", "tirar_chico", 13.0);		
		break;
		
		case "tirar_chico":
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "IslaMona_residence", "goto", "goto1");
		break;		
		
		case "go_IMtavern":
            DoQuestReloadToLocation("IslaMona_Tavern", "candles", "sit3", "go_IMtavernbis");
		break;				
		
		case "go_IMtavernbis":
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Where_Chico";
			LAi_ActorSelfDialog(pchar, "");			
		break;

		case "go_outside_IMtavern":
			LAi_Fade("go_outside_IMtavernbis", "");
		break;
		
		case "go_outside_IMtavernbis":
			LAi_SetPlayerType(pchar);		
			ChangeCharacterAddressGroup(pchar, "IslaMona_tavern", "goto", "goto5");
			
			Pchar.quest.ver_guarda.win_condition.l1 = "location";
			Pchar.quest.ver_guarda.win_condition.l1.location = "IslaMona_port";
			Pchar.quest.ver_guarda.win_condition = "news_cois";				
		break;

		case "news_cois":
            sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "goto", "goto24");
			LAi_SetHP(sld, 100.0, 100.0);
			sld.dialog.filename = "Divers_dialog.c";
			sld.dialog.currentnode = "begin_19";
			sld.id = "soldato ingles";

            LAi_SetActorType(characterFromID("soldato ingles"));
			LAi_ActorDialog(characterFromID("soldato ingles"), pchar, "", 6.0, 1.0);
		break;

		case "news_coisbis":
			Locations[FindLocation("IslaMona_port")].reload.l1.disable = 0;
			Locations[FindLocation("IslaMona_port")].reload.l3.disable = 0;
			Locations[FindLocation("IslaMona_port_exit")].reload.l4.disable = 0; // GR
			Characters[GetCharacterIndex("Wilfred Burman")].dialog.currentnode = "begin_1";
			LAi_ActorRunToLocation(characterfromID("soldato ingles"), "reload", "reload2", "none", "", "", "", 10.0);
		break;

		case "return_IMtavern":
			LAi_SetActorType(characterFromID("Chico Cois"));
			LAi_ActorFollowEverywhere(characterFromID("Chico Cois"), "", 60.0);

			Pchar.quest.ponto_situacao.win_condition.l1 = "location";
			Pchar.quest.ponto_situacao.win_condition.l1.location = "IslaMona_port_exit";
			Pchar.quest.ponto_situacao.win_condition = "outside_commander";
		break;

		case "outside_commander":
			LAi_SetActorType(characterFromID("Chico Cois"));
			Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_53";			
			LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 6.0, 1.0);	
		break;

		case "antes_IMfort":
            DoQuestReloadToLocation("IslaMona_Tavern", "candles", "sit3", "antes_IMfortbis");
		break;

		case "antes_IMfortbis":
        	SetCurrentTime(23.05, 0);		
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			ChangeCharacterAddressGroup(characterFromID("Chico Cois"), "IslaMona_tavern", "sit", "sit4");			
			LAi_SetActorType(characterFromID("Chico Cois"));
			LAi_ActorSetSitMode(characterFromID("Chico Cois"));
			Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_56";
			LAi_ActorWaitDialog(CharacterFromID("Chico Cois"), Pchar); 
			LAi_ActorDialog(pchar, characterFromID("Chico Cois"),"", 10.0, 10.0);			
		break;

		case "antes_IMfortbis2":		
            DoQuestReloadToLocation("IslaMona_warehouse", "goto", "goto3", "antes_IMfortbis3");
		break;
		
		case "antes_IMfortbis3":
			LAi_SetPlayerType(pchar);
			SetModelfromArray(&pchar, GetModelIndex("Johan_Elting_b"));
	        TakenItems(Pchar, "pistolpdart", 15);
	        TakenItems(Pchar, "time_bomb", 2);			
            EquipCharacterbyItem(Pchar, "pistolpdart");				
			Locations[FindLocation("IslaMona_port")].reload.l5.disable = 1;
			Locations[FindLocation("IslaMona_port")].reload.l2.disable = 1;			
			Locations[FindLocation("IslaMona_port_exit")].reload.l2.disable = 0;
			Locations[FindLocation("IslaMona_port_exit")].reload.l4.disable = 0;			
			Locations[FindLocation("IslaMona_passage")].vcskip = true;
	        LAi_SetCheckMinHP(Pchar, LAi_GetCharacterHP(Pchar)-1.0, true, "englishattack");

			pchar.quest.IMsoldat_died.win_condition.l1 = "NPC_Death";
			pchar.quest.IMsoldat_died.win_condition.l1.character = "Mona_patrol_17";
			pchar.quest.IMsoldat_died.win_condition = "deposer_bombe";		
		break;
		
        case "deposer_bombe":		
			pchar.quest.near_cannon.win_condition.l1 = "locator";
			pchar.quest.near_cannon.win_condition.l1.location = "IslaMona_fort";
			pchar.quest.near_cannon.win_condition.l1.locator_group = "rld";
			pchar.quest.near_cannon.win_condition.l1.locator = "loc11";
			pchar.quest.near_cannon.win_condition = "deposer_bombebis";
		break;

        case "deposer_bombebis":
			TakeItemFromCharacter(pchar, "time_bomb");
			
			pchar.quest.near_cannonb.win_condition.l1 = "locator";
			pchar.quest.near_cannonb.win_condition.l1.location = "IslaMona_fort";
			pchar.quest.near_cannonb.win_condition.l1.locator_group = "rld";
			pchar.quest.near_cannonb.win_condition.l1.locator = "loc10";
			pchar.quest.near_cannonb.win_condition = "deposer_bombebis2";			
		break;

        case "deposer_bombebis2":
			TakeItemFromCharacter(pchar, "time_bomb");
            LAi_QuestDelay("jump_fromfort", 2.0);				
		break;

		case "jump_fromfort":
			PostVideoAndQuest("Assassin\Cannons",1, "fuir_IslaMona");
		break;

		case "fuir_IslaMona":
            DoQuestReloadToLocation("Cabin_small", "goto", "goto3", "fuir_IslaMonabis");
    	break;

    	case "fuir_IslaMonabis":
			PChar.quest.disable_rebirth = false;
			Island_SetReloadEnableLocal("IslaMona", "reload_1", false);
			Islands[FindIsland("IslaMona")].reload.l1.goto_enable = false;		
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "Cabin_small", "goto", "goto2");      
	        LAi_SetActorType(characterFromID("Chico Cois"));
	        Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_60";
	        LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 1.0, 1.0);
    	break;

    	case "fuir_IslaMonabis2":
          	LAi_RemoveCheckMinHP(Pchar);
            LAi_SetImmortal(Pchar, false);
			SetModelfromArray(&pchar, GetModelIndex("Johan_Elting"));			
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Chico Cois"));	
			QuestToSeaLogin_PrepareLoc("IslaMona", "reload", "reload_1", true);
			QuestToSeaLogin_Launch();
			AddQuestRecord("Cannons", "7");
			Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_74";
			Characters[GetCharacterIndex("antigua_portadmiral")].dialog.currentnode = "begin_23"; 			
 		break;		

        case "englishattack":
           PlaySound("Ambient\Sea\bell8_0400_0800_1200.wav");
   	       LAi_group_FightGroups("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, true);
    	   LAi_RemoveCheckMinHP(Pchar);
           LAi_SetImmortal(Pchar, false);

			Locations[FindLocation("Fort_Entry")].reload.l3.disable = 1;		   
			Locations[FindLocation("IslaMona_port")].reload.l1.disable = 1;
			Locations[FindLocation("IslaMona_port")].reload.l3.disable = 1;
			Locations[FindLocation("IslaMona_port")].reload.l6.disable = 1;			
			Locations[FindLocation("IslaMona_port_exit")].reload.l2.disable = 1;
			Locations[FindLocation("IslaMona_port_exit")].reload.l4.disable = 1;
			Locations[FindLocation("IslaMona_passage")].reload.l3.disable = 1;
			Locations[FindLocation("IslaMona_passage")].reload.l4.disable = 1;			
        break;
		
    	case "bataille_naval":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			ChangeRMRelation(pchar, SPAIN, 10.0);		
			AddQuestRecord("Cannons", "8");

			Pchar.quest.find_Couronne.win_condition.l1 = "location";
			Pchar.quest.find_Couronne.win_condition.l1.location = "KhaelRoa";
			PChar.quest.find_Couronne.win_condition = "bataille_navalbis";			
		break;
		
    	case "bataille_navalbis":
			pchar.battle.ship.type   = pchar.ship.type;
			pchar.battle.ship.name   = pchar.ship.name;
			
    		Group_CreateGroup("French_Captain1_Ship"); 
    		Group_AddCharacter("French_Captain1_Ship", "French_Captain1");
    		Group_SetGroupCommander("French_Captain1_Ship", "French_Captain1");
			Group_SetPursuitGroup("French_Captain1_Ship", PLAYER_GROUP);
			Group_SetTaskAttack("French_Captain1_Ship", "Jeremy Tripper", true);
			Group_LockTask("French_Captain1_Ship");
			characters[GetCharacterIndex("French_Captain1")].nosurrender = 2;			
        	Group_SetAddress("French_Captain1_Ship", "KhaelRoa", "Quest_ships","quest_ship_8");

    		Group_CreateGroup("French_Captain2_Ship"); 
    		Group_AddCharacter("French_Captain2_Ship", "French_Captain2");
    		Group_SetGroupCommander("French_Captain2_Ship", "French_Captain2");
			Group_SetPursuitGroup("French_Captain2_Ship", PLAYER_GROUP);
			Group_SetTaskAttack("French_Captain2_Ship", "English_Captain3", true);
			Group_LockTask("French_Captain2_Ship");			
			characters[GetCharacterIndex("French_Captain2")].nosurrender = 2;			
        	Group_SetAddress("French_Captain2_Ship", "KhaelRoa", "Quest_ships","quest_ship_8");

    		Group_CreateGroup("French_Captain3_Ship"); 
    		Group_AddCharacter("French_Captain3_Ship", "French_Captain3");
    		Group_SetGroupCommander("French_Captain3_Ship", "French_Captain3");
			Group_SetPursuitGroup("French_Captain3_Ship", PLAYER_GROUP);
			Group_SetTaskAttack("French_Captain3_Ship", "English_Captain4", true);
			Group_LockTask("French_Captain3_Ship");				
			characters[GetCharacterIndex("French_Captain3")].nosurrender = 2;			
        	Group_SetAddress("French_Captain3_Ship", "KhaelRoa", "Quest_ships","quest_ship_8");
						
    		Group_CreateGroup("Tripper_Ship"); 
    		Group_AddCharacter("Tripper_Ship", "Jeremy Tripper");
    		Group_SetGroupCommander("Tripper_Ship", "Jeremy Tripper");
			Group_SetPursuitGroup("Tripper_Ship", PLAYER_GROUP);
			Group_SetTaskAttack("Tripper_Ship", "French_Captain1", true);
			Group_LockTask("Tripper_Ship");					
			characters[GetCharacterIndex("Jeremy Tripper")].nosurrender = 2;			
        	Group_SetAddress("Tripper_Ship", "KhaelRoa", "Quest_ships","quest_ship_8");
			
    		Group_CreateGroup("English_Captain2_Ship"); 
    		Group_AddCharacter("English_Captain2_Ship", "English_Captain2");
    		Group_SetGroupCommander("English_Captain2_Ship", "English_Captain2");
			Group_SetPursuitGroup("English_Captain2_Ship", PLAYER_GROUP);
			Group_SetTaskAttack("English_Captain2_Ship", "French_Captain1", true);
			Group_LockTask("English_Captain2_Ship");				
			characters[GetCharacterIndex("English_Captain2")].nosurrender = 2;			
        	Group_SetAddress("English_Captain2_Ship", "KhaelRoa", "Quest_ships","quest_ship_8");

    		Group_CreateGroup("English_Captain3_Ship"); 
    		Group_AddCharacter("English_Captain3_Ship", "English_Captain3");
    		Group_SetGroupCommander("English_Captain3_Ship", "English_Captain3");
			Group_SetPursuitGroup("English_Captain3_Ship", PLAYER_GROUP);
			Group_SetTaskAttack("English_Captain3_Ship", "French_Captain1", true);
			Group_LockTask("English_Captain3_Ship");				
			characters[GetCharacterIndex("English_Captain3")].nosurrender = 2;			
        	Group_SetAddress("English_Captain3_Ship", "KhaelRoa", "Quest_ships","quest_ship_8");

    		Group_CreateGroup("English_Captain4_Ship"); 
    		Group_AddCharacter("English_Captain4_Ship", "English_Captain4");
    		Group_SetGroupCommander("English_Captain4_Ship", "English_Captain4");
			Group_SetPursuitGroup("English_Captain4_Ship", PLAYER_GROUP);
			Group_SetTaskAttack("English_Captain4_Ship", "French_Captain1", true);
			Group_LockTask("English_Captain4_Ship");				
			characters[GetCharacterIndex("English_Captain4")].nosurrender = 2;			
        	Group_SetAddress("English_Captain4_Ship", "KhaelRoa", "Quest_ships","quest_ship_8");

			Pchar.quest.seize_couronne.win_condition.l1 = "NPC_Death";
			Pchar.quest.seize_couronne.win_condition.l1.character = "French_Captain1";
			Pchar.quest.seize_couronne.win_condition.l2 = "NPC_Death";
			Pchar.quest.seize_couronne.win_condition.l2.character = "French_Captain1";
			Pchar.quest.seize_couronne.win_condition.l3 = "NPC_Death";
			Pchar.quest.seize_couronne.win_condition.l3.character = "French_Captain1";
			Pchar.quest.seize_couronne.win_condition = "capture_couronne";			
        break;

    	case "capture_couronne":
			if (characters[GetCharacterindex("French_Captain1")].ship.hp >= 1) 
			{
			AddQuestRecord("Cannons", "9");
			Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_84";			
			}		
        break;				

    	case "acaba_mona":
            GiveShip2Character(pchar,pchar.battle.ship.type,pchar.battle.ship.name,-1,SPAIN,true,true);		
			CloseQuestHeader("Cannons");		
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 10000);
				AddPartyExpChar(pchar, "Sneak", 100);
			}
			else { AddPartyExp(pchar, 10000); }
			ChangeRMRelation(pchar, SPAIN, 5.0);
			Group_SetAddressNone("French_Captain1_Ship");
			Group_SetAddressNone("French_Captain2_Ship");
			Group_SetAddressNone("French_Captain3_Ship");
			Group_SetAddressNone("Tripper_Ship");
			Group_SetAddressNone("English_Captain2_Ship");
			Group_SetAddressNone("English_Captain3_Ship");
			Group_SetAddressNone("English_Captain4_Ship");

			Group_DeleteGroup("French_Captain1_Ship");
			Group_DeleteGroup("French_Captain2_Ship");
			Group_DeleteGroup("French_Captain3_Ship")
			Group_DeleteGroup("Tripper_Ship");
			Group_DeleteGroup("English_Captain2_Ship");
			Group_DeleteGroup("English_Captain3_Ship");
			Group_DeleteGroup("English_Captain4_Ship");;

            ChangeCharacterAddressGroup(characterFromID("spanish_soldat_09"), "Havana_House_03", "reload", "reload1");			
	        LAi_SetActorType(characterFromID("spanish_soldat_09"));
	        Characters[GetCharacterIndex("spanish_soldat_09")].dialog.currentnode = "begin_24";
	        LAi_ActorDialog(characterFromID("spanish_soldat_09"), pchar, "", 2.0, 1.0);
			
			Islands[FindIsland("IslaMona")].smuggling_nation = SPAIN; // GR: Meanwhile, Spain has reclaimed Isla Mona
        break;

// Oranjestad' siege
		
		case "Cuban_village":		
	        LAi_SetActorType(characterFromID("Salvadore Benavides"));
	        Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_87";
	        LAi_ActorDialog(characterFromID("Salvadore Benavides"), pchar, "", 2.0, 1.0);			
		break;	

		case "Cuban_villagebis":		
	        LAi_SetActorType(characterFromID("spanish_soldat_09"));
	        Characters[GetCharacterIndex("spanish_soldat_09")].dialog.currentnode = "begin_25";
	        LAi_ActorDialog(characterFromID("spanish_soldat_09"), pchar, "", 1.0, 1.0);			
		break;

		case "Cuban_villagebis2":		
	        LAi_SetActorType(characterFromID("Salvadore Benavides"));
	        Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_88";
	        LAi_ActorDialog(characterFromID("Salvadore Benavides"), pchar, "", 1.0, 0.0);			
		break;			
		
		case "Cuban_villagebis3":
		PChar.quest.disable_rebirth = true;		
             DoQuestReloadToLocation("Smugglers_Fort", "reload", "reload1", "Cuban_village_fight");		
		break;

		case "Cuban_village_fight":	
           ChangeCharacterAddressGroup(characterFromID("Enrique Padilla"), "Smugglers_Fort", "goto", "goto17");
           LAi_group_MoveCharacter(characterFromID("Enrique Padilla"), "VILLAGE_SOLDIERS");		   
		
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "goto", "goto19");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "VILLAGE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto20");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "VILLAGE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto21");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "VILLAGE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol5_16", "goto", "goto50");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DUTCH_SOLDIERS");	

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol4_16", "goto", "goto39");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DUTCH_SOLDIERS");	

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol_16", "goto", "goto42");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DUTCH_SOLDIERS");	

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol2_16", "goto", "goto28");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DUTCH_SOLDIERS");	

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol3_16", "goto", "goto9");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DUTCH_SOLDIERS");

			LAi_group_FightGroups("DUTCH_SOLDIERS", "VILLAGE_SOLDIERS", true);
			LAi_group_SetCheck("DUTCH_SOLDIERS", "village_fight_fim");			
		break;

		case "village_fight_fim":		
	        LAi_SetActorType(characterFromID("Enrique Padilla"));
	        Characters[GetCharacterIndex("Enrique Padilla")].dialog.currentnode = "begin_7";
	        LAi_ActorDialog(characterFromID("Enrique Padilla"), pchar, "", 3.0, 2.0);			
		break;

		case "Dutch_Sabana":
    	    SetQuestHeader("Siege");		
    		AddQuestRecord("Siege", "1");			
	        LAi_SetActorType(characterFromID("Enrique Padilla"));
            LAi_ActorFollowEverywhere(characterFromID("Enrique Padilla"), "", 60.0);
            SetCharacterShipLocation(characterFromID("Dutch Captain"), "Cuba_Shore_04");

            Pchar.quest.Dutch_playa.win_condition.l1 = "location";
			Pchar.quest.Dutch_playa.win_condition.l1.location = "Cuba_Shore_04";
			PChar.quest.Dutch_playa.win_condition = "Dutch_Sabanabis";			
		break;

		case "Dutch_Sabanabis":
            LAi_SetOfficerType(characterFromID("Enrique Padilla"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol5_16", "goto", "locator8");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DUTCH_SABANA");	

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol4_16", "goto", "locator9");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DUTCH_SABANA");	

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol_16", "goto", "locator10");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DUTCH_SABANA");	

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol2_16", "goto", "citizen04");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DUTCH_SABANA");

			LAi_group_FightGroups("DUTCH_SABANA", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("DUTCH_SABANA", "sabana_fight_fim");			
		break;
		
		case "sabana_fight_fim":
            ChangeCharacterAddressGroup(characterFromID("spanish_soldat_09"), "none", "", "");
            LAi_SetHuberType(characterFromID("Salvadore Benavides"));			
	        LAi_SetActorType(characterFromID("Enrique Padilla"));
	        Characters[GetCharacterIndex("Enrique Padilla")].dialog.currentnode = "begin_9";
	        LAi_ActorDialog(characterFromID("Enrique Padilla"), pchar, "", 3.0, 2.0);			
		break;

		case "back_residence":
		PChar.quest.disable_rebirth = false;		
            DoQuestReloadToLocation("Havana_House_03", "reload", "reload1","back_residencebis");		
		break;	

		case "back_residencebis":		
           ChangeCharacterAddressGroup(characterFromID("Enrique Padilla"), "Havana_House_03", "goto", "goto1");
           LAi_SetCitizenType(characterFromID("Enrique Padilla"));
           SetCharacterShipLocation(characterFromID("Dutch Captain"), "none");
           Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_89";		   
		break;

		case "see_cuban_governor":		
            DoQuestReloadToLocation("Havana_townhall", "reload", "reload1","see_cuban_governorbis");		
		break;

		case "see_cuban_governorbis":		
            ChangeCharacterAddressGroup(characterFromID("Salvadore Benavides"), "Havana_townhall", "goto", "goto1");
            Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_90";
			WaitDate("", 0,0,3,0,0);			
			LAi_SetActorType(pchar); 
			LAi_SetActorType(characterFromID("Salvadore Benavides"));
			LAi_ActorWaitDialog(CharacterFromID("Salvadore Benavides"), Pchar); 	                       
			LAi_ActorDialog(pchar, characterFromID("Salvadore Benavides"), "", 10.0, 1.0);		
		break;

		case "going_bonaire":
    		AddQuestRecord("Siege", "2");			
			LAi_SetPlayerType(pchar); 
			
            Pchar.quest.Cois_Bonaire.win_condition.l1 = "location";
			Pchar.quest.Cois_Bonaire.win_condition.l1.location = "Douwesen";
			PChar.quest.Cois_Bonaire.win_condition = "chico_instructions";			
		break;
		
    	case "chico_instructions":
            DoReloadFromSeaToLocation("ShipDeck5","goto", "goto4");
			RemovePassenger(pchar, characterFromID("Chico Cois"));
			RemoveCharacterCompanion(pchar, characterFromID("Chico Cois"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Chico Cois"));
            ChangeCharacterAddressGroup(CharacterFromID("Salvadore Benavides"), "Havana_House_03", "sit", "sit1");
            LAi_SetHuberType(characterFromID("Salvadore Benavides"));	 			
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "ShipDeck5", "goto", "goto2");      
	        LAi_SetActorType(characterFromID("Chico Cois"));
	        Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_62";
	        LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 5.0, 5.0);
    	break;

		case "chico_returnfrom_bonaire":
            DoQuestReloadToLocation("Cabin_small", "goto", "goto2", "cabine_chico");
    	break;

    	case "cabine_chico":			
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "Cabin_small", "goto", "goto3");      
	        LAi_SetActorType(characterFromID("Chico Cois"));
	        Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_65";
	        LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 1.0, 1.0);
    	break;

		case "waiting_for_berend":
            SetCurrentTime(10, 0);
            Locations[FindLocation("Douwesen_Jungle_01")].vcskip = true;			
            DoQuestReloadToLocation("Douwesen_Jungle_01", "reload", "reload1", "where_berend");
    	break;

		case "where_berend":
			WaitDate("", 0,0,1,0,0);		
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "Douwesen_Jungle_01", "goto", "citizen011");
	        LAi_SetActorType(characterFromID("Chico Cois"));
	        Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_68";
	        LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 4.0, 1.0);            
    	break;

		case "talk_to_berend":
			LAi_SetOfficerType(characterFromID("Chico Cois"));
            ChangeCharacterAddressGroup(CharacterFromID("Berend de Voor"), "Douwesen_Jungle_01", "goto", "citizen03");
            Characters[GetCharacterIndex("Berend de Voor")].dialog.currentnode = "begin_1";			
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol_16", "goto", "citizen04");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "Berend_1";
			LAi_group_MoveCharacter(sld, "BEREND_SOLDIERS");	

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol2_16", "goto", "citizen04");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "Berend_2";
			LAi_group_MoveCharacter(sld, "BEREND_SOLDIERS");

			LAi_SetActorType(characterFromID("Berend_1"));
			LAi_ActorFollow(characterFromID("Berend_1"), characterFromID("Berend de Voor"), "", 60.0);
			LAi_SetActorType(characterFromID("Berend_2"));
			LAi_ActorFollow(characterFromID("Berend_2"), characterFromID("Berend de Voor"), "", 60.0);			
    	break;

		case "fight_berend":
			LAi_SetStayType(characterFromID("Berend_1"));
			LAi_SetStayType(characterFromID("Berend_2"));
			LAi_group_MoveCharacter(characterFromID("Berend_1"), "BEREND_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("Berend_2"), "BEREND_SOLDIERS");			
			LAi_SetActorType(characterFromID("Berend de Voor"));		
            LAi_ActorAttack(CharacterFromID("Berend de Voor"), Pchar, "");		
			LAi_group_FightGroups("BEREND_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("BEREND_SOLDIERS", "berend_fight_fim");		
    	break;

		case "berend_fight_fim":
			LAi_SetActorType(characterFromID("Berend de Voor"));
			Characters[GetCharacterIndex("Berend de Voor")].dialog.currentnode = "begin_7";
			LAi_ActorDialog(characterFromID("Berend de Voor"), pchar, "", 2.0, 2.0);
		break;

		case "berend_on_ship":
			DeleteAttribute(&Locations[FindLocation("Douwesen_Jungle_01")],"vcskip");
            DoQuestReloadToLocation("ShipDeck5", "goto", "goto4", "berend_on_shipbis");
    	break;

    	case "berend_on_shipbis":	
            ChangeCharacterAddressGroup(CharacterFromID("Berend de Voor"), "ShipDeck5", "goto", "goto2");
			RemoveCharacterEquip(CharacterFromID("Berend de Voor"), BLADE_ITEM_TYPE);		
			EnableEquip(CharacterFromID("Berend de Voor"), BLADE_ITEM_TYPE, false);
			RemoveCharacterEquip(CharacterFromID("Berend de Voor"), GUN_ITEM_TYPE);			
			EnableEquip(CharacterFromID("Berend de Voor"), GUN_ITEM_TYPE, false);				
	        LAi_SetActorType(characterFromID("Berend de Voor"));
	        Characters[GetCharacterIndex("Berend de Voor")].dialog.currentnode = "begin_8";
	        LAi_ActorDialog(characterFromID("Berend de Voor"), pchar, "", 2.0, 1.0);
    	break;
		
		case "berend_hold":
            DoQuestReloadToLocation("Cabin_small", "goto", "goto3", "berend_holdbis");
    	break;

    	case "berend_holdbis":
            SetCharacterShipLocation(Pchar, "Quest_Douwesen_shore");		
            SetCurrentTime(23, 0);		
            ChangeCharacterAddressGroup(CharacterFromID("Berend de Voor"), "none", "", "");		
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "Cabin_small", "goto", "goto2");			
	        LAi_SetActorType(characterFromID("Chico Cois"));
	        Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_69";
	        LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 2.0, 1.0);
    	break;

		case "shore_berend":
            DoQuestReloadToLocation("Quest_Douwesen_shore", "goto", "locator4", "shore_berendbis");
    	break;

		case "shore_berendbis":
            ChangeCharacterAddressGroup(CharacterFromID("Berend de Voor"), "Quest_Douwesen_shore", "goto", "citizen04");
            LAi_SetActorType(characterfromID("Berend de Voor"));
			LAi_ActorRunToLocation(characterfromID("Berend de Voor"), "reload", "reload2_back", "none", "", "", "", 20.0);
			LAi_SetActorType(pchar);
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "berend_running";
			LAi_ActorSelfDialog(pchar, "");						
    	break;

    	case "leaving_bonaire":
            Locations[FindLocation("Indian_Village")].vcskip = true;		
            Characters[GetCharacterIndex("Chief_Indian1")].dialog.filename = "Arawak chief_dialog.c";		
            Characters[GetCharacterIndex("Chief_Indian1")].dialog.currentnode = "begin_1";			
            SetOfficersIndex(PChar, -1, GetCharacterIndex("Chico Cois"));
			LAi_SetOfficerType(characterFromID("Chico Cois"));			
            LAi_SetPlayerType(pchar);	
			QuestToSeaLogin_PrepareLoc("Douwesen", "reload", "reload_2", true);
			QuestToSeaLogin_Launch();
    		AddQuestRecord("Siege", "3");				
  		break;

    	case "see_another_chief":		
            DoQuestReloadToLocation("Indian_Village", "reload", "reload2","meet_chief");	
  		break;

    	case "meet_chief":
            Characters[GetCharacterIndex("Indian Chief")].dialog.currentnode = "begin_1";			

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "goto", "goto3");
            LAi_SetImmortal(sld, true);

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "goto", "goto4");
            LAi_SetImmortal(sld, true);
  		break;

    	case "leave_aruba":
           Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_98";		
			QuestToSeaLogin_PrepareLoc("Aruba", "reload", "reload_3", true);
			QuestToSeaLogin_Launch();
    		AddQuestRecord("Siege", "4");				
  		break;

    	case "attendre_info":
    		AddQuestRecord("Siege", "5");			
		
			PChar.quest.viagem_timer5.win_condition.l1 = "Timer";
			PChar.quest.viagem_timer5.win_condition.l1.date.day = GetAddingDataDay(0, 0, 30);
			PChar.quest.viagem_timer5.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 30);
			PChar.quest.viagem_timer5.win_condition.l1.date.year = GetAddingDataYear(0, 0, 30);
			PChar.quest.viagem_timer5.win_condition = "viagem_fin_timer5";
  		break;

    	case "viagem_fin_timer5":
    	   AddQuestRecord("Siege", "8");			
           ChangeCharacterAddressGroup(CharacterFromID("Enrique Padilla"), "none", "", "");		
           Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_102";		
  		break;

    	case "fleet_towards_aruba":
    		AddQuestRecord("Siege", "6");			
            ChangeCharacterAddressGroup(CharacterFromID("Indian Chief"), "Indian_Village", "goto", "goto6");				
			SetCompanionIndex(Pchar, 1, GetCharacterIndex("Enrique Padilla"));
			SetCharacterRemovable(characterFromID("Enrique Padilla"), false);
			SetCompanionIndex(Pchar, 2, GetCharacterIndex("Spanish Captain3"));
			SetCharacterRemovable(characterFromID("Spanish Captain3"), false);
			SetCompanionIndex(Pchar, 3, GetCharacterIndex("Spanish Captain1"));
			SetCharacterRemovable(characterFromID("Spanish Captain1"), false);

            Pchar.quest.land_aruba.win_condition.l1 = "location";
			Pchar.quest.land_aruba.win_condition.l1.location = "Aruba";
			PChar.quest.land_aruba.win_condition = "revoir_chef";				
  		break;

    	case "revoir_chef":
            DoReloadFromSeaToLocation("Indian_Village","reload", "reload2");
			
            Pchar.quest.talk_chief.win_condition.l1 = "location";
			Pchar.quest.talk_chief.win_condition.l1.location = "Indian_Village";
			PChar.quest.talk_chief.win_condition = "revoir_chefbis";				
 		break;

    	case "revoir_chefbis":
            Characters[GetCharacterIndex("Indian Chief")].dialog.currentnode = "begin_9";			
            SetCurrentTime(21, 0);		
            Locations[FindLocation("Quest_Oranjestad_exit")].vcskip = true;			
		
			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "goto", "goto7");
            LAi_SetImmortal(sld, true);

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "goto", "goto4");
            LAi_SetImmortal(sld, true);
			
            LAi_SetActorType(Pchar);
			LAi_ActorWaitDialog(CharacterFromID("Indian Chief"), Pchar); 
			LAi_ActorDialog(pchar, characterFromID("Indian Chief"),"", 6.0, 1.0);			
 		break;

		case "rejoindre_battle":
            LAi_SetPlayerType(Pchar);		
            ChangeCharacterAddressGroup(CharacterFromID("Enrique Padilla"), "Quest_Oranjestad_exit", "goto", "goto1");
            LAi_SetStayType(CharacterFromID("Enrique Padilla"));			
            Characters[GetCharacterIndex("Enrique Padilla")].dialog.currentnode = "begin_11";				
            DoQuestReloadToLocation("Quest_Oranjestad_exit", "reload", "reload1","rejoindre_battlebis");		
		break;

		case "rejoindre_battlebis":
        	CreateParticleSystemX("fireball", -7.1654, 0.6386, 16.221, -1.57, 0.0, 0.0,0);
        	CreateParticleSystemX("fireball", 3.3295, 0.89944, 18.109, -1.57, 0.0, 0.0,0);
        	CreateParticleSystemX("fireball", -6.9223, 8, 27.842, -1.57, 0.0, 0.0,0);
            CreateParticleSystemX("fireball", 7.797, 7, 22.301, -1.57, 0.0, 0.0,0);			
		break;
		
		case "placer_battlefield":
            LAi_QuestDelay("debut_battlebis", 10.0);			
		break;
		
		case "debut_battlebis":
			CreateParticleSystemX("cancloud", 6.702, 1, -13.099, -1.57, 0.0, 0.0,20);
			PlaySound("OBJECTS\shipcharge\cannon_fire_01.wav");			
    		LAi_QuestDelay("premier_impact", 1.0);					
		break;			

		case "premier_impact":			
        	CreateParticleSystem("ball_impact", -6.9223, 8, 27.842, 0.0, 0.0, 0.0, 0);
        	CreateParticleSystem("splinters2", -6.9223, 8, 27.842, 0.0, 0.0, 0.0, 0);
        	CreateParticleSystem("splinters3", -6.9223, 8, 27.842, 0.0, 0.0, 0.0, 0);
        	CreateParticleSystem("flyers", -6.9223, 8, 27.842, 0.0, 0.0, 0.0, 0);
        	CreateParticleSystem("flyers2", -6.9223, 8, 27.842, 0.0, 0.0, 0.0, 0);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_001.wav");			
    		LAi_QuestDelay("debut_battlebis2", 3.0);			
		break;
		
		case "debut_battlebis2":
			CreateParticleSystemX("cancloud", -18.738, 1, -10.576, -1.57, 0.0, 0.0,20);
			PlaySound("OBJECTS\shipcharge\cannon_fire_01.wav");				
    		LAi_QuestDelay("deuxieme_impact", 1.0);					
		break;			
		
		case "deuxieme_impact":		
        	CreateParticleSystem("ball_impact", 7.797, 7, 22.301, 0.0, 0.0, 0.0, 0);	
        	CreateParticleSystem("splinters2", 7.797, 7, 22.301, 0.0, 0.0, 0.0, 0);	
        	CreateParticleSystem("splinters3", 7.797, 7, 22.301, 0.0, 0.0, 0.0, 0);	
        	CreateParticleSystem("flyers", 7.797, 7, 22.301, 0.0, 0.0, 0.0, 0);
        	CreateParticleSystem("flyers2", 7.797, 7, 22.301, 0.0, 0.0, 0.0, 0);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_001.wav");			
    		LAi_QuestDelay("debut_battlebis3", 3.0);			
		break;
		
		case "debut_battlebis3":
			CreateParticleSystemX("cancloud", 6.702, 1, -13.099, -1.57, 0.0, 0.0,20);
			PlaySound("OBJECTS\shipcharge\cannon_fire_01.wav");				
    		LAi_QuestDelay("premier_impactbis", 1.0);					
		break;			

		case "premier_impactbis":			
        	CreateParticleSystem("ball_impact", -6.9223, 8, 27.842, 0.0, 0.0, 0.0, 0);
        	CreateParticleSystem("splinters2", -6.9223, 8, 27.842, 0.0, 0.0, 0.0, 0);
        	CreateParticleSystem("splinters3", -6.9223, 8, 27.842, 0.0, 0.0, 0.0, 0);
        	CreateParticleSystem("flyers", -6.9223, 8, 27.842, 0.0, 0.0, 0.0, 0);
        	CreateParticleSystem("flyers2", -6.9223, 8, 27.842, 0.0, 0.0, 0.0, 0);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_001.wav");			
    		LAi_QuestDelay("debut_battlebis4", 3.0);			
		break;
		
		case "debut_battlebis4":
			CreateParticleSystemX("cancloud", -18.738, 1, -10.576, -1.57, 0.0, 0.0,20);
			PlaySound("OBJECTS\shipcharge\cannon_fire_01.wav");				
    		LAi_QuestDelay("deuxieme_impactbis", 1.0);					
		break;			
		
		case "deuxieme_impactbis":		
        	CreateParticleSystem("ball_impact", 7.797, 7, 22.301, 0.0, 0.0, 0.0, 0);	
        	CreateParticleSystem("splinters2", 7.797, 7, 22.301, 0.0, 0.0, 0.0, 0);	
        	CreateParticleSystem("splinters3", 7.797, 7, 22.301, 0.0, 0.0, 0.0, 0);	
        	CreateParticleSystem("flyers", 7.797, 7, 22.301, 0.0, 0.0, 0.0, 0);
        	CreateParticleSystem("flyers2", 7.797, 7, 22.301, 0.0, 0.0, 0.0, 0);
			PlaySound("OBJECTS\shipcharge\vzriv_pogreb_001.wav");			
    		LAi_QuestDelay("sortie_dutch", 3.0);			
		break;

		case "sortie_dutch":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol5_16", "reload", "reload3");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ORANJESTAD_SOLDIERS");	

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol4_16", "reload", "reload3");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ORANJESTAD_SOLDIERS");	

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol_16", "reload", "reload3");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ORANJESTAD_SOLDIERS");	

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol2_16", "reload", "reload3");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ORANJESTAD_SOLDIERS");	

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol3_16", "reload", "reload3");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ORANJESTAD_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol2_16", "reload", "reload3");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "ORANJESTAD_SOLDIERS");			

			LAi_group_FightGroups("ORANJESTAD_SOLDIERS", "SIEGE_SOLDIERS", true);
    		LAi_QuestDelay("indian_attack", 3.0);				
		break;

		case "indian_attack":		
			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "reload", "reload2");
			LAi_group_MoveCharacter(sld, "ORANJESTAD_INDIANS");	

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "reload", "reload2");
			LAi_group_MoveCharacter(sld, "ORANJESTAD_INDIANS");	

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "reload", "reload2");
			LAi_group_MoveCharacter(sld, "ORANJESTAD_INDIANS");	

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "reload", "reload2");
			LAi_group_MoveCharacter(sld, "ORANJESTAD_INDIANS");	

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "reload", "reload2");
			LAi_group_MoveCharacter(sld, "ORANJESTAD_INDIANS");

			LAi_group_FightGroups("ORANJESTAD_SOLDIERS", "ORANJESTAD_INDIANS", true);			
            LAi_group_SetCheck("ORANJESTAD_SOLDIERS", "aldeia_fim");				
		break;

		case "aldeia_fim":		
            LAi_SetActorType(characterfromID("Enrique Padilla"));
            LAi_ActorRunToLocation(characterfromID("Enrique Padilla"), "reload", "reload3", "none", "", "", "", 15.0);		
            LAi_SetActorType(characterfromID("spanish_soldat_02"));
            LAi_ActorRunToLocation(characterfromID("spanish_soldat_02"), "reload", "reload3", "none", "", "", "", 15.0);		
            LAi_SetActorType(characterfromID("spanish_soldat_03"));
            LAi_ActorRunToLocation(characterfromID("spanish_soldat_03"), "reload", "reload3", "none", "", "", "", 15.0);
            LAi_SetActorType(characterfromID("spanish_soldat_04"));
            LAi_ActorRunToLocation(characterfromID("spanish_soldat_04"), "reload", "reload3", "none", "", "", "", 15.0);				
            LAi_SetActorType(characterfromID("spanish_soldat_05"));
            LAi_ActorRunToLocation(characterfromID("spanish_soldat_05"), "reload", "reload3", "none", "", "", "", 15.0);		
            LAi_SetActorType(characterfromID("spanish_soldat_06"));
            LAi_ActorRunToLocation(characterfromID("spanish_soldat_06"), "reload", "reload3", "none", "", "", "", 15.0);		
            LAi_SetActorType(characterfromID("spanish_soldat_07"));
            LAi_ActorRunToLocation(characterfromID("spanish_soldat_07"), "reload", "reload3", "none", "", "", "", 15.0);
    		LAi_QuestDelay("open_oranjestad", 15.0);	
		break;

		case "open_oranjestad":
            Locations[FindLocation("Quest_Oranjestad_town")].vcskip = true;			
			locations[FindLocation("Quest_Oranjestad_exit")].reload.l3.disable = 0;
			Locations[FindLocation("Quest_Oranjestad_town")].locators_radius.goto.goto20 = 3.0;					
			
            Pchar.quest.entrer_oranjestad.win_condition.l1 = "location";
			Pchar.quest.entrer_oranjestad.win_condition.l1.location = "Quest_Oranjestad_town";
			PChar.quest.entrer_oranjestad.win_condition = "inside_oranjestad";					
		break;

		case "inside_oranjestad":
			locations[FindLocation("Quest_Oranjestad_town")].reload.l1.disable = 1;		
        	CreateParticleSystemX("fireball", 6.7788, 0.78361, -0.50264, -1.57, 0.0, 0.0,0);
        	CreateParticleSystemX("fireball", 3.121, 4, 5.494, -1.57, 0.0, 0.0,0);
        	CreateParticleSystemX("fireball", 11.619, 4, 6.187, -1.57, 0.0, 0.0,0);
            CreateParticleSystemX("fireball", 7.596, 1.364, 16.389, -1.57, 0.0, 0.0,0);
            CreateParticleSystemX("fireball", -10.661, 3, 3.52, -1.57, 0.0, 0.0,0);		
            CreateParticleSystemX("fireball", -5.849, -0.153, 20.381, -1.57, 0.0, 0.0,0);
            CreateParticleSystemX("fireball", -11.363, 0.57, 9.757, -1.57, 0.0, 0.0,0);		
            CreateParticleSystemX("fireball", -2.435, 0.15, 4.065, -1.57, 0.0, 0.0,0);
            CreateParticleSystemX("fireball", 9.388, 5, -4.781, -1.57, 0.0, 0.0,0);	
            ChangeCharacterAddressGroup(CharacterFromID("Enrique Padilla"), "Quest_Oranjestad_town", "goto", "goto21");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol5_16", "goto", "goto18");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");
            LAi_SetActorType(sld);				
            LAi_ActorSetLayMode(sld);			
			LAi_SetHP(sld, 80.0, 80.0);	

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol4_16", "goto", "goto17");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");
            LAi_SetActorType(sld);			
            LAi_ActorSetLayMode(sld);					
			LAi_SetHP(sld, 80.0, 80.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa5_16", "goto", "goto5");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);	

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "goto", "goto26");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");
            sld.id = "criminel";			
			LAi_SetHP(sld, 80.0, 80.0);
			
			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "Chelovek", "goto", "character5");
            sld.id = "innocent";			
			LAi_SetHP(sld, 20.0, 20.0);
            LAi_SetActorType(CharacterFromID("innocent"));
            LAi_ActorAnimation(CharacterFromID("innocent"), "afraid","", 10);			
			
			pchar.quest.find_crime.win_condition.l1 = "locator";
			pchar.quest.find_crime.win_condition.l1.location = "Quest_Oranjestad_town";
			pchar.quest.find_crime.win_condition.l1.locator_group = "goto";
			pchar.quest.find_crime.win_condition.l1.locator = "goto20";
			pchar.quest.find_crime.win_condition = "voir_crime";					 			
		break;

		case "voir_crime":
            LAi_SetStayType(CharacterFromID("innocent"));		
            LAi_SetActorType(CharacterFromID("criminel"));		
			LAi_ActorAttack(CharacterFromID("criminel"), CharacterFromID("innocent"), "");
	        LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(PChar, characterFromID("criminel"));					

			Pchar.quest.civilian_died.win_condition.l1 = "NPC_Death";
			Pchar.quest.civilian_died.win_condition.l1.character = "innocent";
			Pchar.quest.civilian_died.win_condition = "voir_crimebis";			
        break;
		
		case "voir_crimebis":
            LAi_QuestDelay("voir_crimebis2", 3.5);	
        break;		

		case "voir_crimebis2":
		   RemoveCharacterCompanion(Pchar, characterFromID("Enrique Padilla"));
		   SetCharacterRemovable(characterFromID("Enrique Padilla"), true);	
		   RemoveCharacterCompanion(Pchar, characterFromID("Spanish Captain3"));
		   SetCharacterRemovable(characterFromID("Spanish Captain3"), true);	
		   RemoveCharacterCompanion(Pchar, characterFromID("Spanish Captain1"));
		   SetCharacterRemovable(characterFromID("Spanish Captain1"), true);				
           Characters[GetCharacterIndex("Enrique Padilla")].dialog.currentnode = "begin_17";				
           LAi_SetActorType(Pchar);
		   LAi_ActorWaitDialog(CharacterFromID("Enrique Padilla"), Pchar); 
		   LAi_ActorDialog(pchar, characterFromID("Enrique Padilla"),"", 5.0, 1.0);
        break;

		case "quitter_oranjestad":
            CaptureTownForNation("Oranjestad", SPAIN);		
	        LAi_SetPlayerType(pchar);
            Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_105";		
			QuestToSeaLogin_PrepareLoc("Aruba", "reload", "reload_1", true);
			QuestToSeaLogin_Launch();
    		AddQuestRecord("Siege", "7");				
		break;

// Bartolomeu’s trap		
		
		case "join_butcher":
			CloseQuestHeader("Siege");		
    	    SetQuestHeader("Trap");		
    		AddQuestRecord("Trap", "1");		
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 10000);
				AddPartyExpChar(pchar, "Sneak", 100);
			}
			else { AddPartyExp(pchar, 10000); }
			ChangeRMRelation(pchar, SPAIN, 5.0);			
            ChangeCharacterAddressGroup(CharacterFromID("Leonardo Corrales"), "Muelle_town_01", "goto", "goto36");				
            ChangeCharacterAddressGroup(CharacterFromID("Nicholas Butcher"), "Muelle_town_04", "goto", "goto21");
            LAi_SetCitizenType(CharacterFromID("Nicholas Butcher"));			
            Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_21";			
		break; 

		case "aller_nevis":
    		AddQuestRecord("Trap", "2");		
	        LAi_SetActorType(characterFromID("Nicholas Butcher"));		
			LAi_ActorFollowEverywhere(characterFromID("Nicholas Butcher"), "", 60.0);
            SetCompanionIndex(Pchar, -1, GetCharacterIndex("Nicholas Butcher"));			
			SetCharacterRemovable(characterFromID("Nicholas Butcher"), false);		
            ChangeCharacterAddressGroup(CharacterFromID("Andrew Parson"), "QC_Tavern", "goto", "goto2");		
            Characters[GetCharacterIndex("Andrew Parson")].dialog.currentnode = "begin_1";			
		break;

		case "Bart_grenada":
            ChangeCharacterAddressGroup(CharacterFromID("Leonardo Corrales"), "none", "", "");
            Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_25";
	        LAi_ActorDialog(characterFromID("Nicholas Butcher"), pchar, "", 2.0, 1.0);			
		break;

		case "Bart_grenadabis":
    		AddQuestRecord("Trap", "3");		
			pchar.quest.trap = "grenada";		
	        LAi_SetActorType(characterFromID("Nicholas Butcher"));		
			LAi_ActorFollowEverywhere(characterFromID("Nicholas Butcher"), "", 60.0);
		break;
		
		case "Bart_grenadabis2":
			pchar.quest.trap = "boarding";
            Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_26";
	        LAi_ActorDialog(characterFromID("Nicholas Butcher"), pchar, "", 2.0, 1.0);				
		break;

		case "Bart_grenadabis3":
			Pchar.quest.saojorge.win_condition.l1 = "location";
			Pchar.quest.saojorge.win_condition.l1.location = "conceicao_town";
			PChar.quest.saojorge.win_condition = "Bart_grenadabis4";
	        LAi_SetActorType(characterFromID("Nicholas Butcher"));		
			LAi_ActorFollowEverywhere(characterFromID("Nicholas Butcher"), "", 60.0);			
		break;

		case "Bart_grenadabis4":
            Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_27";
	        LAi_ActorDialog(characterFromID("Nicholas Butcher"), pchar, "", 2.0, 1.0);				
		break;		

		case "board_santiago":
			RemovePassenger(pchar, characterFromID("Chico Cois"));
			RemoveCharacterCompanion(pchar, characterFromID("Chico Cois"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Chico Cois"));			
            SetCurrentTime(23, 0);		
			PostVideoAndQuest("Assassin\boarding",1, "crew_arrested");
		break;

		case "crew_arrested":
            ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Santiago_ship", "goto", "goto3");			
            DoQuestReloadToLocation("Santiago_ship", "rld", "loc6","check_capture");		
		break;

		case "check_capture":		
			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "pirat1", "rld", "aloc7");
            LAi_SetActorType(sld);
			LAi_ActorAnimation(sld, "hands up", "", 1.0);	           			
			LAi_SetHP(sld, 40.0, 40.0);

			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "pirat2", "rld", "aloc5");
            LAi_SetActorType(sld);
			LAi_ActorAnimation(sld, "hands up", "", 1.0);	            			
			LAi_SetHP(sld, 40.0, 40.0);	

			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "pirat3", "rld", "aloc4");
            LAi_SetActorType(sld);
			LAi_ActorAnimation(sld, "hands up", "", 1.0);	             			
			LAi_SetHP(sld, 40.0, 40.0);	

			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "pirat4", "rld", "aloc6");
            LAi_SetActorType(sld);
			LAi_ActorAnimation(sld, "hands up", "", 1.0);	           			
			LAi_SetHP(sld, 40.0, 40.0);

            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "Santiago_ship", "rld", "loc5");
			LAi_SetActorType(characterFromID("Chico Cois"));
			Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_70";
			LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 2.0, 1.0);			
		break;
		
		case "check_capturebis":
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_1";		
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(CharacterFromID("Emilio Soares"), Pchar);		
			LAi_ActorDialog(PChar, CharacterFromID("Emilio Soares"), "", 4.0, 1);	
		break;

		case "check_capturebis2":
			Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_73";		
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(CharacterFromID("Chico Cois"), Pchar);		
			LAi_ActorDialog(PChar, CharacterFromID("Chico Cois"), "", 4.0, 1);	
		break;

		case "quitter_saojorge":			
 			LAi_SetPlayerType(PChar);
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Chico Cois"));
			AddPassenger(Pchar, characterFromID("Chico Cois"), 0);		// GR: in case you have a full set of officers so Chico can't be assigned as officer
			LAi_SetOfficerType(characterFromID("Chico Cois"));
	        LAi_SetActorType(characterFromID("Nicholas Butcher"));		
			LAi_ActorFollowEverywhere(characterFromID("Nicholas Butcher"), "", 60.0);
			Locations[FindLocation("cuba_port")].vcskip = true;			
			
			Pchar.quest.emilio_havana.win_condition.l1 = "location";
			Pchar.quest.emilio_havana.win_condition.l1.location = "cuba_port";
			PChar.quest.emilio_havana.win_condition = "send_emilio_jail";

			QuestToSeaLogin_PrepareLoc("Conceicao", "reload", "reload_1", true);
			QuestToSeaLogin_Launch();
    		AddQuestRecord("Trap", "4");			
		break;
		
		case "send_emilio_jail":
            ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "cuba_port", "goto", "goto_34");
			LAi_SetActorType(characterFromID("Emilio Soares"));
			Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_7";
			LAi_ActorDialog(characterFromID("Emilio Soares"), pchar, "", 3.0, 1.0);				
		break;

		case "send_emilio_jailbis":
			LAi_SetActorType(characterFromID("Nicholas Butcher"));
			Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_31";
			LAi_ActorDialog(characterFromID("Nicholas Butcher"), pchar, "", 3.0, 1.0);				
		break;

		case "rejoindre_benavides":
			DeleteAttribute(&Locations[FindLocation("cuba_port")],"vcskip");		
            DoQuestReloadToLocation("Havana_House_03", "reload", "reload1","rejoindre_benavidesbis");		
		break;

		case "rejoindre_benavidesbis":
		   Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_117";		
           ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Havana_prison", "goto", "goto9");
           ChangeCharacterAddressGroup(CharacterFromID("Nicholas Butcher"), "Havana_Town_01", "goto", "goto10");			   
		break;

		case "Governor_Puerto":
			Pchar.quest.butcher_havana.win_condition.l1 = "location";
			Pchar.quest.butcher_havana.win_condition.l1.location = "Havana_Town_01";
			PChar.quest.butcher_havana.win_condition = "Governor_Puertobis";		           		
		break;

		case "Governor_Puertobis":
			LAi_SetActorType(characterFromID("Nicholas Butcher"));
			Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_32";
			LAi_ActorDialog(characterFromID("Nicholas Butcher"), pchar, "", 5.0, 1.0);	           		
		break;

		case "Governor_Puertobis2":
    		AddQuestRecord("Trap", "5");		
	        LAi_SetActorType(characterFromID("Nicholas Butcher"));		
			LAi_ActorFollowEverywhere(characterFromID("Nicholas Butcher"), "", 60.0);
			pchar.quest.Eleuthera = "Roxanne";			
		break;

		case "messenger_done":			
            DoQuestReloadToLocation("Eleuthera_Port", "goto", "goto17","messenger_donebis");		
		break;

		case "messenger_donebis":			
			LAi_SetActorType(characterFromID("Nicholas Butcher"));
			Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_34";
			LAi_ActorDialog(characterFromID("Nicholas Butcher"), pchar, "", 6.0, 1.0);		
		break;

		case "direct_alice":
    		AddQuestRecord("Trap", "6");		
            Characters[GetCharacterIndex("Roxanne Lalliere")].nation = HOLLAND;		
			SetCharacterShipLocation(CharacterFromID("Roxanne Lalliere"), "Quest_Alice");		
            ChangeCharacterAddressGroup(CharacterFromID("William Cotter"), "Alice_Port", "goto", "goto23");
			Characters[GetCharacterIndex("William Cotter")].dialog.currentnode = "begin_1";			
	        LAi_SetActorType(characterFromID("Nicholas Butcher"));		
			LAi_ActorFollowEverywhere(characterFromID("Nicholas Butcher"), "", 60.0);	
		break;

		case "wait_roxanne":		
            DoQuestReloadToLocation("Quest_Alice", "goto", "goto17","wait_roxannebis");		
		break;

		case "wait_roxannebis":
			ChangeCharacterAddress(characterFromID("William Cotter"), "none", "");		
			LAi_SetActorType(characterFromID("Nicholas Butcher"));
			Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_35";
			LAi_ActorDialog(characterFromID("Nicholas Butcher"), pchar, "", 6.0, 1.0);	         	
		break;

		case "Butcher_Roxanne":		
            ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Quest_Alice", "reload", "reload4_back");
            ChangeCharacterAddressGroup(CharacterFromID("Guibert Daudet"), "Quest_Alice", "reload", "reload4_back");
			LAi_SetActorType(characterfromID("Guibert Daudet"));
			LAi_ActorFollow(characterFromID("Guibert Daudet"), characterFromID("Roxanne Lalliere"), "", 60.0);
			LAi_group_MoveCharacter(CharacterFromID("Roxanne Lalliere"), "ROXY");
			LAi_group_MoveCharacter(CharacterFromID("Guibert Daudet"), "ROXY");
			LAi_ActorTurnToCharacter(characterFromID("Nicholas Butcher"), characterFromID("Roxanne Lalliere"));	
            LAi_QuestDelay("Butcher_Roxanne2", 5.0);			
		break;

		case "Butcher_Roxanne2":
			Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_36";		
			LAi_ActorDialog(characterFromID("Nicholas Butcher"), pchar, "", 2.0, 1.0);	
		break;

		case "Butcher_Roxanne3":
            LAi_SetImmortal(CharacterFromID("Roxanne Lalliere"), 1);
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_1";			
			LAi_SetOfficerType(characterFromID("Nicholas Butcher"));
		break;

		case "fight_roxy":
            LAi_SetImmortal(CharacterFromID("Roxanne Lalliere"), 0);
    	    LAi_group_FightGroups("ROXY", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("ROXY", "Win_Roxy");			
		break;

		case "Win_Roxy":
            SetCurrentTime(19, 0);		
			LAi_SetActorType(characterFromID("Nicholas Butcher"));
			Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_37";
			LAi_ActorDialog(characterFromID("Nicholas Butcher"), pchar, "", 3.0, 1.0);			
		break;

		case "Roxanne_captive":
            DoQuestReloadToLocation("Eleuthera_townhall", "goto", "goto8","Roxanne_captive2");			
		break;

		case "Roxanne_captive2":		
            ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Eleuthera_townhall", "goto", "goto7");
			LAi_SetStayType(characterFromID("Roxanne Lalliere"));			
			GiveItem2Character(CharacterFromId("Roxanne Lalliere"), "bladex4");   
			EquipCharacterByItem(CharacterFromId("Roxanne Lalliere"), "bladex4");
			GiveItem2Character(CharacterFromId("Roxanne Lalliere"), "pistolrock");   
			EquipCharacterByItem(CharacterFromId("Roxanne Lalliere"), "pistolrock");			
			Characters[GetCharacterIndex("Cole Arkwright")].dialog.currentnode = "gov_11";			
		break;
		
		case "roxanne_in_jail":
            DoQuestReloadToLocation("Fort_prison", "goto", "goto23","roxanne_in_jail2");
		break;

		case "roxanne_in_jail2":
            ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Fort_prison", "goto", "goto9");
            ChangeCharacterAddressGroup(CharacterFromID("Nicholas Butcher"), "Fort_prison", "reload", "reload13_back");			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "offic_spa_16", "goto", "goto13");
            sld.dialog.filename = "Divers_dialog.c";			
			GiveItem2Character(sld, "bladec30");
			TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, "bladec30"));
			EquipCharacterByItem(sld, "bladec30");
			sld.id = "fort captain";
			LAi_SetActorType(characterFromID("Roxanne Lalliere"));
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_2";
			LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 2.0, 1.0);				
		break;

		case "Fort_Captain":
			LAi_SetActorType(characterFromID("fort captain"));			
			Characters[GetCharacterIndex("fort captain")].dialog.currentnode = "begin_26";
			LAi_ActorDialog(characterFromID("fort captain"), pchar, "", 4.0, 1.0);				
		break;

		case "Fort_Captain2":
			LAi_SetActorType(characterFromID("Nicholas Butcher"));			
			Characters[GetCharacterIndex("Nicholas Butcher")].dialog.currentnode = "begin_38";
			LAi_ActorDialog(characterFromID("Nicholas Butcher"), pchar, "", 3.0, 1.0);				
		break;

		case "Fort_Captain3":
			RemovePassenger(pchar, characterFromID("Chico Cois"));
			RemoveCharacterCompanion(pchar, characterFromID("Chico Cois"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Chico Cois"));		
			Characters[GetCharacterIndex("Chico Cois")].Location = "none";		
            DoQuestReloadToLocation("Eleuthera_tavern", "sit", "sit3","Elting_Tavern");
		break;

		case "Elting_Tavern":
			WaitDate("", 0,0,2,0,0);			
            StoreOfficers(pchar.id);		
            SetCurrentTime(23, 0);		
			RemoveCharacterCompanion(Pchar, characterFromID("Nicholas Butcher"));
			SetCharacterRemovable(characterFromID("Nicholas Butcher"), true);
			ChangeCharacterAddress(characterFromID("Nicholas Butcher"), "none", "");				
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Back_Roxanne";
			LAi_ActorSelfDialog(pchar, "");			
		break;
			
		case "fort_eleuthera":			
            DoQuestReloadToLocation("Quest_FortVRight", "goto", "goto61","fort_attacked");		
		break;

		case "fort_attacked":
            ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Quest_Fort_prison", "goto", "goto9");
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Quest_Fort_prison", "goto", "goto23");					
			LAi_SetPlayerType(pchar);			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "soldiers", "protector1");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");
            LAi_SetActorType(sld);
            LAi_ActorSetLayMode(sld);			
			LAi_SetHP(sld, 80.0, 80.0);	

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa5_16", "goto", "goto80");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");
            LAi_SetActorType(sld);
            LAi_ActorSetLayMode(sld);			
			LAi_SetHP(sld, 80.0, 80.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto01");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");
            LAi_SetActorType(sld);
            LAi_ActorSetLayMode(sld);			
			LAi_SetHP(sld, 80.0, 80.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "goto", "goto11");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");
            LAi_SetActorType(sld);
            LAi_ActorSetLayMode(sld);			
			LAi_SetHP(sld, 80.0, 80.0);	

            LAi_QuestDelay("fort_attacked2", 5.0);			
		break;

		case "fort_attacked2":
			LAi_SetActorType(pchar);
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Check_fort";
			LAi_ActorSelfDialog(pchar, "");			
		break;

		case "fort_attacked3":		
			LAi_SetPlayerType(pchar);
		    Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_1";			
		break;

        case "fight_bartolomeu":
			LAi_SetActorType(characterFromID("Bartolomeu"));		
			LAi_ActorAttack(CharacterFromID("Bartolomeu"), PChar, "");
			
			Pchar.quest.tuer_Bartolomeu.win_condition.l1 = "NPC_Death";
			Pchar.quest.tuer_Bartolomeu.win_condition.l1.character = "Bartolomeu";
			Pchar.quest.tuer_Bartolomeu.win_condition = "ver_padilla";			
        break;

        case "ver_padilla":
			Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_9";		
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(CharacterFromID("Roxanne Lalliere"), Pchar);			
			LAi_ActorDialog(PChar, CharacterFromID("Roxanne Lalliere"), "", 2.0, 1);
        break;

        case "ver_padilla2":
			LAi_SetPlayerType(Pchar);			
            ChangeCharacterAddressGroup(CharacterFromID("Enrique Padilla"), "Quest_Fort_prison", "goto", "goto13");		
			LAi_Fade("ver_padilla3", "");
        break;

        case "ver_padilla3":
			Locations[FindLocation("Eleuthera_Port")].vcskip = true;
			SetCharacterShipLocation(characterFromID("Enrique Padilla"), "Eleuthera_Port");			
			LAi_SetActorType(characterFromID("Enrique Padilla"));			
			Characters[GetCharacterIndex("Enrique Padilla")].dialog.currentnode = "begin_25";
			LAi_ActorDialog(characterFromID("Enrique Padilla"), pchar, "", 3.0, 1.0);	
        break;

        case "retourner_eleuthera":
           DoQuestReloadToLocation("Eleuthera_Port", "goto", "goto1","retourner_eleutherabis");		
        break;

        case "retourner_eleutherabis":
            ChangeCharacterAddressGroup(CharacterFromID("Enrique Padilla"), "Eleuthera_Port", "goto", "goto7");
			SetCompanionIndex(Pchar, 1, GetCharacterIndex("Enrique Padilla"));
			SetCharacterRemovable(characterFromID("Enrique Padilla"), false);
			Characters[GetCharacterIndex("Enrique Padilla")].dialog.currentnode = "begin_29";			
			LAi_SetActorType(characterFromID("Enrique Padilla"));
			LAi_ActorDialog(characterFromID("Enrique Padilla"), pchar, "", 3.0, 1.0);		
        break;

        case "retourner_eleutherabis2":
			DeleteAttribute(&Locations[FindLocation("Eleuthera_Port")],"vcskip");			
            LAi_SetActorType(characterFromID("Enrique Padilla"));			
			LAi_ActorRunToLocation(characterFromID("Enrique Padilla"), "reload", "reload1", "none", "", "", "revenir_havana", 12.0);
        break;
		
    	case "revenir_havana":
            RestoreOfficers(pchar.id);			
			AddQuestRecord("Trap", "11");
			Locations[FindLocation("cuba_port")].vcskip = true;		
		
            Pchar.quest.revoir_benavides.win_condition.l1 = "location";
			Pchar.quest.revoir_benavides.win_condition.l1.location = "Cuba_port";
			PChar.quest.revoir_benavides.win_condition = "recevoir_recompense";			
		break;
		
		case "recevoir_recompense":
            ChangeCharacterAddressGroup(characterFromID("Salvadore Benavides"), "Havana_townhall", "goto", "goto1");
            ChangeCharacterAddressGroup(characterFromID("Felipe Cisneros"), "Havana_townhall", "goto", "goto2");
			LAi_SetStayType(characterFromID("Felipe Cisneros"));			
			PlaceCharacter(characterFromID("Enrique Padilla"), "goto");         
			Characters[GetCharacterIndex("Enrique Padilla")].dialog.currentnode = "begin_31";			
			LAi_SetActorType(characterFromID("Enrique Padilla"));
			LAi_ActorDialog(characterFromID("Enrique Padilla"), pchar, "", 6.0, 1.0);			
		break;				

		case "recevoir_recompensebis":
    		RemoveCharacterCompanion(Pchar, characterFromID("Enrique Padilla"));
    		SetCharacterRemovable(characterFromID("Enrique Padilla"), true);
            LAi_SetActorType(characterFromID("Enrique Padilla"));			
			LAi_ActorRunToLocation(characterFromID("Enrique Padilla"), "reload", "sea_2", "none", "", "", "", 5.0);			
			
            Pchar.quest.revoir_benavidesbis.win_condition.l1 = "location";
			Pchar.quest.revoir_benavidesbis.win_condition.l1.location = "Havana_Townhall";
			PChar.quest.revoir_benavidesbis.win_condition = "recevoir_recompensebis2";				
		break;

		case "recevoir_recompensebis2":
	 		DeleteAttribute(&Locations[FindLocation("cuba_port")],"vcskip");	
            ChangeCharacterAddressGroup(characterFromID("Enrique Padilla"), "Havana_House_03", "goto", "goto1");
            LAi_SetCitizenType(characterFromID("Enrique Padilla"));			
            Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_127";			
			LAi_SetActorType(pchar); 
			LAi_SetActorType(characterFromID("Salvadore Benavides"));
			LAi_ActorWaitDialog(CharacterFromID("Salvadore Benavides"), Pchar); 	                       
			LAi_ActorDialog(pchar, characterFromID("Salvadore Benavides"), "", 10.0, 1.0);		
		break;

		case "recevoir_recompensebis3":		
            Characters[GetCharacterIndex("Felipe Cisneros")].dialog.currentnode = "gov_2";			
			LAi_SetActorType(pchar); 
			LAi_SetActorType(characterFromID("Felipe Cisneros"));
			LAi_ActorWaitDialog(CharacterFromID("Felipe Cisneros"), Pchar); 	                       
			LAi_ActorDialog(pchar, characterFromID("Felipe Cisneros"), "", 4.0, 1.0);		
		break;
				
		case "recevoir_recompensebis4":	
			DoQuestReloadToLocation("Cuba_port", "reload", "sea_1","findelaquete");			
		break;

		case "findelaquete":
			LAi_SetPlayerType(pchar); 		
            ChangeCharacterAddressGroup(CharacterFromID("Salvadore Benavides"), "Havana_House_03", "sit", "sit1");			
			LAi_SetHuberType(characterFromID("Salvadore Benavides"));
            ChangeCharacterAddressGroup(CharacterFromID("Felipe Cisneros"), "Havana_townhall", "sit", "sit1");			
			LAi_SetHuberType(characterFromID("Felipe Cisneros"));
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			ChangeRMRelation(pchar, SPAIN, 10.0);
			AddQuestRecord("Trap", "12");
			CloseQuestHeader("Trap");				
		break;		

        case "sortir_prison":
			Locations[FindLocation("Eleuthera_Jungle4")].vcskip = true;		
			SetOfficersIndex(PChar, 1, GetCharacterIndex("Bartolomeu"));
			SetOfficersIndex(PChar, 2, GetCharacterIndex("Roxanne Lalliere"));
			GiveItem2Character(CharacterFromId("Roxanne Lalliere"), "blade10");
			EquipCharacterByItem(CharacterFromId("Roxanne Lalliere"), "pistol1a");
			EquipCharacterByItem(CharacterFromId("Roxanne Lalliere"), "blade10");
            DoQuestReloadToLocation("Eleuthera_Jungle4", "reload", "reload2", "meet_enrique");			
        break;

        case "meet_enrique":
            ChangeCharacterAddressGroup(CharacterFromID("Enrique Padilla"), "Eleuthera_Jungle4", "goto", "goto8");
			LAi_group_MoveCharacter(CharacterFromID("Enrique Padilla"), "PADILLA_SOLDIERS");	
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "goto", "goto7");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "PADILLA_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto4");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "PADILLA_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto3");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "PADILLA_SOLDIERS");

		    Characters[GetCharacterIndex("Enrique Padilla")].dialog.currentnode = "begin_21";			  
            LAi_SetActorType(characterFromID("Enrique Padilla"));
    		LAi_ActorDialog(characterFromID("Enrique Padilla"), pchar, "", 3.5, 1.0);			
        break;
		
        case "info_bartolomeu":
		     Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_16_1";			  
             LAi_SetActorType(characterFromID("Bartolomeu"));
    		 LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 2.0, 1.0);	
        break;

        case "provoke_padilla":
             LAi_SetOfficerType(characterFromID("Bartolomeu"));
		     Characters[GetCharacterIndex("Enrique Padilla")].dialog.currentnode = "begin_22";			  
             LAi_SetActorType(characterFromID("Enrique Padilla"));
    		 LAi_ActorDialog(characterFromID("Enrique Padilla"), pchar, "", 1.0, 1.0);				
        break;		
		
        case "fight_padilla":
			LAi_ActorAttack(characterFromID("Enrique Padilla"), pchar, "");	
			LAi_group_FightGroups("PADILLA_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("PADILLA_SOLDIERS", "Padilla_morto");
        break;

        case "Padilla_morto":
		     Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_18";			  
             LAi_SetActorType(characterFromID("Bartolomeu"));
    		 LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 4.0, 10.0);	
        break;

        case "join_guibert":
			AddQuestRecord("Trap", "7");		
            LAi_SetOfficerType(characterFromID("Bartolomeu"));
            ChangeCharacterAddressGroup(CharacterFromID("Guibert Daudet"), "Alice_Port", "goto", "goto21");
            LAi_SetStayType(characterFromID("Guibert Daudet"));
            ChangeCharacterAddressGroup(CharacterFromID("Enrique Padilla"), "none", "", "");				
        break;

        case "infoemilio":
             DeleteAttribute(&Locations[FindLocation("Eleuthera_Jungle4")],"vcskip");		
		     Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_19";			  
             LAi_SetActorType(characterFromID("Bartolomeu"));
    		 LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 2.0, 1.0);				
        break;

        case "infoemiliobis":
            LAi_SetOfficerType(characterFromID("Bartolomeu"));
			AddQuestRecord("Trap", "8");		   
			RemovePassenger(pchar, characterFromID("Roxanne Lalliere"));
			RemoveCharacterCompanion(pchar, characterFromID("Roxanne Lalliere"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Roxanne Lalliere"));
            LAi_SetActorType(characterFromID("Roxanne Lalliere"));			
			LAi_ActorRunToLocation(characterFromID("Roxanne Lalliere"), "reload", "reload61_back", "none", "", "", "quitter_alicebis", 10.0);
            LAi_SetActorType(characterFromID("Guibert Daudet"));			
			LAi_ActorRunToLocation(characterFromID("Guibert Daudet"), "reload", "reload61_back", "none", "", "", "", 9.0);
        break;

	case "quitter_alicebis":
			GiveShip2Character(pchar,"FastCaravel","Santiago",-1,PIRATE,true,true);
			HoistFlag(PORTUGAL);
			SetCharacterShipLocation(Pchar, "Alice_Port");			
			RestoreOfficers(pchar.id);	  
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Roxanne Lalliere"));
			SetCharacterRemovable(characterFromID("Roxanne Lalliere"), false);
			
			pchar.quest.parabahia.win_condition.l1 = "location";
			pchar.quest.parabahia.win_condition.l1.location = "Cuba_shore_01";
			pchar.quest.parabahia.win_condition = "chegada_antonio";
	break;

	case "chegada_antonio":
			ChangeCharacterAddressGroup(CharacterFromID("Roxanne Lalliere"), "Cuba_shore_01", "goto", "goto13");
			LAi_SetStayType(characterFromID("Roxanne Lalliere"));	  
			Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_21";			  
			LAi_SetActorType(characterFromID("Bartolomeu"));
			LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 2.0, 1.0);				
	break;	   

	case "free_emilio":
			Locations[FindLocation("Havana_town_05")].vcskip = true;			  
			RemovePassenger(pchar, characterFromID("Bartolomeu"));
			RemoveCharacterCompanion(pchar, characterFromID("Bartolomeu"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Bartolomeu"));	  
            SetCurrentTime(23.00, 0);
			DisableFastTravel(true);
			DisableMenuLaunch(true);			
            Locations[FindLocation("Havana_town_05")].reload.l4.disable = 1;			
            DoQuestReloadToLocation("Havana_town_05", "goto", "goto_35", "free_emiliobis");	
       break;
	   
      case "free_emiliobis":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "goto", "soldier01");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "soldier02");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "soldier03");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			sld.dialog.filename = "Spaniards_dialog.c";
			sld.dialog.currentnode = "begin_1";
			sld.id = "soldadinho";
            LAi_SetStayType(characterfromID("soldadinho"));			
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
					
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Havana_town_05", "goto", "goto_7");
			GiveItem2Character(CharacterFromId("Bartolomeu"), "bladex4");   
			EquipCharacterByItem(CharacterFromId("Bartolomeu"), "bladex4");
			GiveItem2Character(CharacterFromId("Bartolomeu"), "pistolrock");   
			EquipCharacterByItem(CharacterFromId("Bartolomeu"), "pistolrock");			
		    Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_22";			  
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 4.0, 1.0);				
       break;
	   
      case "free_emiliobis2":
			LAi_ActorFollowEverywhere(characterFromID("Bartolomeu"), "", 60.0);
       break;	  
	   
      case "entrar_havana_jail":
            Locations[FindLocation("Havana_town_05")].reload.l4.disable = 0;			
            ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Havana_prison", "goto", "goto9");
			LAi_SetStayType(characterFromID("Emilio Soares"));			
		    Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_8";			
       break;

      case "tuerdansprison":
			Locations[FindLocation("Havana_prison")].vcskip = true;		  
            DoQuestReloadToLocation("Havana_prison", "goto", "goto18", "tuerdansprisonbis");	
       break;

      case "tuerdansprisonbis":
            ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Havana_prison", "goto", "goto19");
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Havana_prison", "goto", "goto17");			
		    Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_25";			  
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 5.0, 1.0);				
       break;
	   
		case "climb_residence":		
            DoQuestReloadToLocation("Quest_Havana_Town_01", "goto", "goto60","start1bis");		
		break;	

		case "start1bis":
			SetModelfromArray(&pchar, GetModelIndex("Johan_Elting_d"));
		    GiveItem2Character(Pchar, "fougasse");				
            LAi_SetActorType(Pchar);
			LAi_ActorAnimation(Pchar, "Lay_1", "start2", 1.2);		
		break;			
		
		case "start2":
			ChangeCharacterAddressGroup(Pchar, "Quest_Havana_Town_01", "goto", "goto61");
            LAi_ActorAnimation(Pchar, "Lay_2", "start3", 1.2);			
		break;	

		case "start3":
			ChangeCharacterAddressGroup(Pchar, "Quest_Havana_Town_01", "goto", "goto62");			
			LAi_ActorAnimation(Pchar, "Lay_1", "start4", 1.2);		
		break;	

		case "start4":
			ChangeCharacterAddressGroup(Pchar, "Quest_Havana_Town_01", "goto", "goto63");			
			LAi_ActorAnimation(Pchar, "Lay_2", "start5", 1.2);		
		break;

		case "start5":
			ChangeCharacterAddressGroup(Pchar, "Quest_Havana_Town_01", "goto", "goto64");			
			LAi_ActorAnimation(Pchar, "Lay_1", "start6", 1.2);		
		break;	

		case "start6":
			ChangeCharacterAddressGroup(Pchar, "Quest_Havana_Town_01", "goto", "goto65");        
		    LAi_ActorAnimation(Pchar, "Lay_2", "start7", 1.2);     						
		break;	

		case "start7":
			ChangeCharacterAddressGroup(Pchar, "Quest_Havana_Town_01", "goto", "goto66");
			LAi_ActorAnimation(Pchar, "Lay_1", "start8", 1.2);				
		break;	

		case "start8":
			ChangeCharacterAddressGroup(Pchar, "Quest_Havana_Town_01", "goto", "goto67");
			LAi_ActorAnimation(Pchar, "Lay_2", "start9", 1.2);     		
		break;

		case "start9":
			ChangeCharacterAddressGroup(Pchar, "Quest_Havana_Town_01", "goto", "goto68");			
			LAi_ActorAnimation(Pchar, "Lay_1", "start10", 1.2);     		
		break;	

		case "start10":
			ChangeCharacterAddressGroup(Pchar, "Quest_Havana_Town_01", "goto", "goto69");		
			LAi_ActorAnimation(Pchar, "Lay_2", "start11", 1.2);     			
		break;	

		case "start11":
			ChangeCharacterAddressGroup(Pchar, "Quest_Havana_Town_01", "goto", "goto70");			
			LAi_ActorAnimation(Pchar, "Lay_1", "start12", 1.2);     			
		break;	

		case "start12":
			ChangeCharacterAddressGroup(Pchar, "Quest_Havana_Town_01", "goto", "goto71");			
			LAi_ActorAnimation(Pchar, "Lay_2", "start13", 1.2);     	
		break;

		case "start13":
			ChangeCharacterAddressGroup(Pchar, "Quest_Havana_Town_01", "goto", "goto72");			
			LAi_ActorAnimation(Pchar, "Lay_1", "start14", 1.2);     	
		break;

		case "start14":
			ChangeCharacterAddressGroup(Pchar, "Quest_Havana_Town_01", "goto", "goto73");			
			LAi_ActorAnimation(Pchar, "Lay_2", "start15", 1.2);     		
		break;

		case "start15":
			ChangeCharacterAddressGroup(Pchar, "Quest_Havana_Town_01", "goto", "goto74");			
			LAi_ActorAnimation(Pchar, "Lay_1", "bomba_residence", 1.2);     		
		break;

		case "bomba_residence":		
            DoQuestReloadToLocation("Quest_Havana_House_03", "reload", "reload2","bomba_residence2");		
		break;

		case "bomba_residence2":		
			SetModelfromArray(&pchar, GetModelIndex("Johan_Elting"));
            LAi_SetPlayerType(Pchar);
			
			pchar.quest.posebomba.win_condition.l1 = "locator";
			pchar.quest.posebomba.win_condition.l1.location = "Quest_Havana_House_03";
			pchar.quest.posebomba.win_condition.l1.locator_group = "reload";
			pchar.quest.posebomba.win_condition.l1.locator = "reload1";
			pchar.quest.posebomba.win_condition = "poserbomba";
        break;

        case "poserbomba":
			TakeItemFromCharacter(pchar, "fougasse");
			
			pchar.quest.sairjanela.win_condition.l1 = "locator";
			pchar.quest.sairjanela.win_condition.l1.location = "Quest_Havana_House_03";
			pchar.quest.sairjanela.win_condition.l1.locator_group = "reload";
			pchar.quest.sairjanela.win_condition.l1.locator = "reload2";
			pchar.quest.sairjanela.win_condition = "emilio_denovo";		
        break;			
	   
      case "emilio_denovo":
			Locations[FindLocation("Quest_Havana_Town_01")].vcskip = true;		  
            SetCurrentTime(7.00, 0);	  
            DoQuestReloadToLocation("Quest_Havana_Town_01", "goto", "goto30", "revient_elting");				 
       break;
	   
      case "revient_elting":
            DeleteAttribute(&Locations[FindLocation("Havana_town_05")],"vcskip");	  
            DeleteAttribute(&Locations[FindLocation("Havana_prison")],"vcskip");	  
            ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Cuba_shore_01", "goto", "goto13");
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Quest_Havana_Town_01", "goto", "goto59");
            SetModelfromArray(CharacterFromID("Bartolomeu"), GetModelIndex("GypsyCaptn_7"));			
		    Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_34";
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(CharacterFromID("Bartolomeu"), Pchar);			
			LAi_ActorDialog(PChar, CharacterFromID("Bartolomeu"), "", 3.0, 1);				
       break;

		case "Benavides_arrival":
			LAi_ActorGoToLocator(PChar, "goto", "goto15", "Benavides_arrivalbis", 6.0);
		break;	   

		case "Benavides_arrivalbis":
            LAi_SetActorType(Pchar);		
			LAi_ActorTurnToCharacter(PChar, characterFromID("Quest_Havana_soldier_02"));			
            ChangeCharacterAddressGroup(CharacterFromID("Salvadore Benavides"), "Quest_Havana_Town_01", "reload", "reload_2_3");
            ChangeCharacterAddressGroup(CharacterFromID("Quest_Havana_soldier_05"), "Quest_Havana_Town_01", "reload", "reload_2_3");
            ChangeCharacterAddressGroup(CharacterFromID("Quest_Havana_soldier_06"), "Quest_Havana_Town_01", "reload", "reload_2_3");
			LAi_SetActorType(characterFromID("Quest_Havana_soldier_05"));
			LAi_ActorFollow(characterFromID("Quest_Havana_soldier_05"), characterFromID("Salvadore Benavides"), "", 60.0);
			LAi_SetActorType(characterFromID("Quest_Havana_soldier_06"));
			LAi_ActorFollow(characterFromID("Quest_Havana_soldier_06"), characterFromID("Salvadore Benavides"), "", 60.0);
			LAi_SetActorType(CharacterFromID("Salvadore Benavides"));
            LAi_ActorGoToLocation(characterFromID("Salvadore Benavides"), "reload", "door_5", "none", "", "", "explose_mansion", 30.0);
		break;
		
		case "explose_mansion":
			CreateParticleSystemX("blast", -35.536, 0.00, 3.5, -1.57, 0.0, 0.0,0);	
			CreateParticleSystemX("fort_fire", -35.536, 1.00, 3.5, -1.57, 0.0, 0.0,20);			
			CreateParticleSystemX("blast", -33.987, 0.00, -2.8622, -1.57, 0.0, 0.0,0);	
			CreateParticleSystemX("fort_fire", -33.987, 1.00, -2.8622, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("blast", -35.434, 0.00, 10.042, -1.57, 0.0, 0.0,0);	
			CreateParticleSystemX("fort_fire", -35.434, 1.00, 10.042, -1.57, 0.0, 0.0,20);

			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");
			LAi_ActorSetLayMode(characterFromID("Salvadore Benavides"));
			LAi_KillCharacter(characterFromID("Quest_Havana_soldier_05"));
			LAi_KillCharacter(characterFromID("Quest_Havana_soldier_06"));
			LAi_KillCharacter(characterFromID("Quest_Havana_soldier_01"));
			LAi_KillCharacter(characterFromID("Quest_Havana_soldier_02"));				
            ChangeCharacterAddressGroup(characterFromID("Salvadore Benavides"), "Quest_Havana_Town_01", "goto", "goto58");
            LAi_Stunned_StunCharacter(characterFromID("Quest_Havana_soldier_03"), 100, true, STUN_STARS, false);
            LAi_Stunned_StunCharacter(characterFromID("Quest_Havana_soldier_04"), 100, true, STUN_STARS, false);
            LAi_SetPlayerType(Pchar);			
            LAi_QuestDelay("confirmar_morta", 10.0);			
		break;
		
		case "confirmar_morta":	
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			LAi_ActorFollowEverywhere(characterFromID("Bartolomeu"), "", 60.0);					
            DoQuestReloadToLocation("Cuba_shore_01", "reload", "reload1", "revenir_bahiabis");				
		break;
		
		case "revenir_bahiabis":
    		 ChangeRMRelation(pchar, SPAIN, -50.0);
             SetModelfromArray(characterFromID("Bartolomeu"), GetModelIndex("GypsyCaptn_5"));		 
    		 Characters[GetCharacterIndex("Roxanne Lalliere")].dialog.currentnode = "begin_8";
             LAi_SetActorType(characterFromID("Roxanne Lalliere"));
    		 LAi_ActorDialog(characterFromID("Roxanne Lalliere"), pchar, "", 3.0, 1.0);
		break;
		
		case "partir_bahia":
			Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_35";
			LAi_SetActorType(characterFromID("Bartolomeu"));
			LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 3.0, 1.0);		
			LAi_SetActorType(CharacterFromID("Roxanne Lalliere"));
			LAi_ActorFollowEverywhere(characterFromID("Roxanne Lalliere"), "", 60.0);
			LAi_SetActorType(CharacterFromID("Emilio Soares"));
			LAi_ActorFollowEverywhere(characterFromID("Emilio Soares"), "", 60.0);
		break;
		
		case "partir_bahia2":
			LAi_ActorFollowEverywhere(characterFromID("Bartolomeu"), "", 60.0);			
			AddQuestRecord("Trap", "9");

			pchar.quest.para_redmond.win_condition.l1 = "location";
			pchar.quest.para_redmond.win_condition.l1.location = "redmond_port";
			pchar.quest.para_redmond.win_condition = "Enfin_PortRoyal";
		break;		

		case "Enfin_PortRoyal":				
			Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_37";
			LAi_SetActorType(characterFromID("Bartolomeu"));
			LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 4.0, 1.0);
		break;

		case "Enfin_PortRoyal2":
			pchar.quest.para_douwesen.win_condition.l1 = "location";
			pchar.quest.para_douwesen.win_condition.l1.location = "Douwesen_port";
			pchar.quest.para_douwesen.win_condition = "pardon_douwesen";

			GiveShip2Character(pchar,"Tartane50","The Mischievous",-1,ENGLAND,true,true);
			AddQuestRecord("Trap", "10");
			CloseQuestHeader("Trap");

			LeaveService(PChar, SPAIN, true);	// Spain knows you double-crossed them and is out for revenge!
			HoistFlag(HOLLAND);

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }	  		
		
			LAi_SetActorType(CharacterFromID("Roxanne Lalliere"));
			LAi_ActorRunToLocation(characterFromID("Roxanne Lalliere"), "reload", "sea_1", "none", "", "", "", 6.0);
			RemoveCharacterCompanion(Pchar, characterFromID("Roxanne Lalliere"));
			setCharacterShipLocation(characterFromID("Roxanne Lalliere"), "none");
			LAi_SetActorType(CharacterFromID("Emilio Soares"));
			LAi_ActorRunToLocation(characterFromID("Emilio Soares"), "reload", "sea_1", "none", "", "", "", 6.0);			

			LAi_SetActorType(CharacterFromID("Bartolomeu"));
			LAi_ActorRunToLocation(characterFromID("Bartolomeu"), "reload", "sea_1", "none", "", "", "", 6.0);			
		break;

// El Diablo's coming back		
		
		case "pardon_douwesen":
            Characters[GetCharacterIndex("Reynard Grueneveldt")].dialog.filename = "Reynard Grueneveldt_quest_dialog.c"; // GR
            ChangeCharacterAddressGroup(CharacterFromID("Berend de Voor"), "Douwesen_port", "goto", "goto6");
            Characters[GetCharacterIndex("Berend de Voor")].dialog.currentnode = "begin_12";			
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol_16", "goto", "goto6");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "Berend_1B";
			LAi_group_MoveCharacter(sld, "BEREND_SOLDADO");	

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_hol2_16", "goto", "goto6");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "Berend_2B";
			LAi_group_MoveCharacter(sld, "BEREND_SOLDADO");

			LAi_SetActorType(characterFromID("Berend_1B"));
			LAi_ActorFollow(characterFromID("Berend_1B"), characterFromID("Berend de Voor"), "", 60.0);
			LAi_SetActorType(characterFromID("Berend_2B"));
			LAi_ActorFollow(characterFromID("Berend_2B"), characterFromID("Berend de Voor"), "", 60.0);	

            LAi_SetActorType(characterFromID("Berend de Voor"));
    		LAi_ActorDialog(characterFromID("Berend de Voor"), pchar, "", 5.0, 1.0);				
        break;

		case "pardon_douwesenbis":	
			DoQuestReloadToLocation("Douwesen_townhall", "reload", "reload1","mairie_douwesen");	
        break;

		case "mairie_douwesen":		
            ChangeCharacterAddressGroup(CharacterFromID("Berend de Voor"), "Douwesen_townhall", "goto", "goto8");
		    Characters[GetCharacterIndex("Reynard Grueneveldt")].dialog.currentnode = "gov_1";				
        break;
		
		case "douw_jail":	
			DoQuestReloadToLocation("Quest_Fort_prison", "goto", "goto9","douw_jailbis");			
        break;

		case "douw_jailbis":
			GiveItem2Character(Pchar, "pistolrock");   
			EquipCharacterByItem(Pchar, "pistolrock");
			WaitDate("", 0,0,3,0,0);		
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);		
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
			ChangeCharacterAddress(characterFromID("Berend de Voor"), "none", "");
			LAi_SetActorType(pchar);
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Douwesen_Prison";
			LAi_ActorSelfDialog(pchar, "");			
        break;
		
		case "douw_jailbis2":	
			DoQuestReloadToLocation("Douwesen_townhall", "reload", "reload1","meet_again_governor");	
        break;
		
		case "meet_again_governor":
			RemoveCharacterEquip(pchar, "pistolrock");
		    Characters[GetCharacterIndex("Reynard Grueneveldt")].dialog.currentnode = "gov_10";
			LAi_SetActorType(pchar);		
			LAi_ActorWaitDialog(CharacterFromID("Reynard Grueneveldt"), Pchar); 
			LAi_ActorDialog(pchar, characterFromID("Reynard Grueneveldt"),"", 5.0, 1.0);					
        break;

		case "townhall_berend":
			LAi_SetPlayerType(pchar);
            LAi_SetActorType(characterFromID("Reynard Grueneveldt"));			
            ChangeCharacterAddressGroup(CharacterFromID("Berend de Voor"), "Douwesen_townhall", "reload", "reload1");
	        Characters[GetCharacterIndex("Berend de Voor")].dialog.currentnode = "begin_14";		
            LAi_SetActorType(characterFromID("Berend de Voor"));
			LAi_ActorDialog(characterFromID("Berend de Voor"), pchar, "", 1.5, 1.0);			
        break;

		case "townhall_berendbis":
	        Characters[GetCharacterIndex("Reynard Grueneveldt")].dialog.currentnode = "gov_13";
			LAi_ActorDialog(characterFromID("Reynard Grueneveldt"), pchar, "", 2.0, 1.0);			
        break;

		case "agent_confirms":
			ChangeCharacterAddress(characterFromID("Berend de Voor"), "none", "");			
			DoQuestReloadToLocation("Douwesen_townhall", "reload", "reload1","agent_confirmsbis");	
        break;
		
		case "agent_confirmsbis":
			WaitDate("", 0,0,1,0,0);		
        	LAi_SetHuberStayType(characterFromID("Reynard Grueneveldt"));		
		    Characters[GetCharacterIndex("Reynard Grueneveldt")].dialog.currentnode = "gov_21";
			LAi_SetActorType(pchar);		
			LAi_ActorWaitDialog(CharacterFromID("Reynard Grueneveldt"), Pchar); 
			LAi_ActorDialog(pchar, characterFromID("Reynard Grueneveldt"),"", 5.0, 1.0);					
        break;		

		case "batalha_praia":	
			DoQuestReloadToLocation("Douwesen_shore_02", "goto", "goto8","batalha_praiabis");	
        break;

		case "batalha_praiabis":
			LAi_SetPlayerType(pchar);		
            ChangeCharacterAddressGroup(CharacterFromID("SoldatD1"), "Douwesen_shore_02", "goto", "goto6");
            ChangeCharacterAddressGroup(CharacterFromID("SoldatD2"), "Douwesen_shore_02", "goto", "goto6");
			LAi_SetActorType(characterFromID("SoldatD1"));
			LAi_ActorFollowEverywhere(characterFromID("SoldatD1"), "", 60.0);
    		Characters[GetCharacterIndex("SoldatD2")].dialog.currentnode = "begin_27";
            LAi_SetActorType(characterFromID("SoldatD2"));
    		LAi_ActorDialog(characterFromID("SoldatD2"), pchar, "", 8.0, 1.0);			
        break;

		case "batalha_praiabis2":
            LAi_SetOfficerType(characterFromID("SoldatD1"));
            LAi_SetOfficerType(characterFromID("SoldatD2"));			
		
                        sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat1", "goto", "goto2");
            GiveItem2Character(sld,"blade10");					
            EquipCharacterByItem(sld,"blade10");								
			LAi_SetHP(sld, 100.0, 100.0);
                        LAi_SetStayType(sld);
			LAi_group_MoveCharacter(sld, "SOLDIER_CHICO");
                        sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat2", "goto", "goto2");
            GiveItem2Character(sld,"blade10");					
            EquipCharacterByItem(sld,"blade10");								
			LAi_SetHP(sld, 100.0, 100.0);
                        LAi_SetStayType(sld);
			LAi_group_MoveCharacter(sld, "SOLDIER_CHICO");						
                        sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat3", "goto", "goto2");
            GiveItem2Character(sld,"blade10");					
            EquipCharacterByItem(sld,"blade10");								
			LAi_SetHP(sld, 100.0, 100.0);
                        LAi_SetStayType(sld);						
			LAi_group_MoveCharacter(sld, "SOLDIER_CHICO");
                        sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat4", "goto", "goto2");
            GiveItem2Character(sld,"blade10");					
            EquipCharacterByItem(sld,"blade10");								
			LAi_SetHP(sld, 100.0, 100.0);
                        LAi_SetStayType(sld);						
			LAi_group_MoveCharacter(sld, "SOLDIER_CHICO");
		
			LAi_group_FightGroups("SOLDIER_CHICO", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SOLDIER_CHICO", "nouv_vague");		
		break;

		case "nouv_vague":
            LAi_SetOfficerType(characterFromID("SoldatD1"));
            LAi_SetOfficerType(characterFromID("SoldatD2"));			
		
                        sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat1", "goto", "goto2");
            GiveItem2Character(sld,"blade10");					
            EquipCharacterByItem(sld,"blade10");								
			LAi_SetHP(sld, 100.0, 100.0);
                        LAi_SetStayType(sld);
			LAi_group_MoveCharacter(sld, "SOLDIER_CHICO_2");
                        sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat2", "goto", "goto2");
            GiveItem2Character(sld,"blade10");					
            EquipCharacterByItem(sld,"blade10");								
			LAi_SetHP(sld, 100.0, 100.0);
                        LAi_SetStayType(sld);
			LAi_group_MoveCharacter(sld, "SOLDIER_CHICO_2");						
                        sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat3", "goto", "goto2");
            GiveItem2Character(sld,"blade10");					
            EquipCharacterByItem(sld,"blade10");								
			LAi_SetHP(sld, 100.0, 100.0);
                        LAi_SetStayType(sld);						
			LAi_group_MoveCharacter(sld, "SOLDIER_CHICO_2");
                        sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat4", "goto", "goto2");
            GiveItem2Character(sld,"blade10");					
            EquipCharacterByItem(sld,"blade10");								
			LAi_SetHP(sld, 100.0, 100.0);
                        LAi_SetStayType(sld);						
			LAi_group_MoveCharacter(sld, "SOLDIER_CHICO_2");
			
                        sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "soldier_hol_16", "reload", "reload2");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");								
			LAi_SetHP(sld, 100.0, 100.0);
                        LAi_SetStayType(sld);
			LAi_group_MoveCharacter(sld, "SOLDIER_GOVERNOR");
                        sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "soldier_hol2_16", "reload", "reload2");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");								
			LAi_SetHP(sld, 100.0, 100.0);
                        LAi_SetStayType(sld);
			LAi_group_MoveCharacter(sld, "SOLDIER_GOVERNOR");						
                        sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "soldier_hol3_16", "reload", "reload2");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");								
			LAi_SetHP(sld, 100.0, 100.0);
                        LAi_SetStayType(sld);						
			LAi_group_MoveCharacter(sld, "SOLDIER_GOVERNOR");
                        sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "soldier_hol4_16", "reload", "reload2");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");								
			LAi_SetHP(sld, 100.0, 100.0);
                        LAi_SetStayType(sld);						
			LAi_group_MoveCharacter(sld, "SOLDIER_GOVERNOR");
			
            ChangeCharacterAddressGroup(CharacterFromID("Berend de Voor"), "Douwesen_shore_02", "reload", "reload2");			
			LAi_group_MoveCharacter(CharacterFromID("Berend de Voor"), "SOLDIER_GOVERNOR");
			
            LAi_group_MoveCharacter(Pchar, "SOLDIER_GOVERNOR");			
            LAi_group_FightGroups("SOLDIER_CHICO_2", "SOLDIER_GOVERNOR", true);
			LAi_group_SetCheck("SOLDIER_CHICO_2", "fimdabatalha");					
		break;
		
		case "fimdabatalha":
            SetCharacterShipLocation(characterFromID("Diablo"), "Douwesen_shore_01");		
            Characters[GetCharacterIndex("Berend de Voor")].dialog.currentnode = "begin_18";
            LAi_SetActorType(characterFromID("Berend de Voor"));
    		LAi_ActorDialog(characterFromID("Berend de Voor"), pchar, "", 5.0, 1.0);				
		break;

		case "Diablo_Douwesen":	
			pchar.quest.para_diablo.win_condition.l1 = "location";
			pchar.quest.para_diablo.win_condition.l1.location = "Douwesen_shore_01";
			pchar.quest.para_diablo.win_condition = "Diablo_Douwesenbis";
			
			SetQuestHeader("Diablo");
			AddQuestRecord("Diablo", "1");
			LAi_SetActorType(characterFromID("Berend de Voor"));
			LAi_ActorFollowEverywhere(characterFromID("Berend de Voor"), "", 60.0);			
        break;

		case "Diablo_Douwesenbis":	
            Characters[GetCharacterIndex("Berend de Voor")].dialog.currentnode = "begin_20";
            LAi_SetActorType(characterFromID("Berend de Voor"));
    		LAi_ActorDialog(characterFromID("Berend de Voor"), pchar, "", 5.0, 1.0);			
        break;

		case "Onboard_Diablo":
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "Quest_ShipDeck5", "goto", "goto3"); 		
			DoQuestReloadToLocation("Quest_ShipDeck5", "goto", "goto4","Onboard_Diablobis");	
        break;

		case "Onboard_Diablobis":
			LAi_SetImmortal(CharacterFromID("Chico Cois"), 0);		
	        LAi_SetActorType(characterFromID("Chico Cois"));
	        Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_75";
	        LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 2.0, 1.0);
        break;

		case "fight_diablo":
			LAi_SetActorType(characterFromID("Chico Cois"));
			LAi_ActorAttack(CharacterFromID("Chico Cois"), Pchar, "");

			pchar.quest.chico_died.win_condition.l1 = "NPC_Death";
			pchar.quest.chico_died.win_condition.l1.character = "Chico Cois";
			pchar.quest.chico_died.win_condition = "fight_diablobis";			
		break;

		case "fight_diablobis":	
            LAi_QuestDelay("fight_diablobis1", 3.0);
		break;
		
		case "fight_diablobis1":
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "Quest_ShipDeck5", "goto", "goto2"); 		
			DoQuestReloadToLocation("Quest_ShipDeck5", "goto", "goto4","fight_diablobis2");	
        break;		

		case "fight_diablobis2":
			GiveItem2Character(CharacterFromId("Chico Cois"), "bladex4");   
			EquipCharacterByItem(CharacterFromId("Chico Cois"), "bladex4");
			GiveItem2Character(CharacterFromId("Chico Cois"), "pistolrock");   
			EquipCharacterByItem(CharacterFromId("Chico Cois"), "pistolrock");

            LAi_SetActorType(characterFromID("Chico Cois"));
			LAi_ActorAnimation(characterFromID("Chico Cois"), "Ground_StandUp", "fight_diablobis3", 3.0);		
		break;

		case "fight_diablobis3":
	        LAi_SetActorType(characterFromID("Chico Cois"));
	        Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_83";
	        LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 2.0, 1.0);
        break;
		
		case "adieu_douwesen":
			ChangeCharacterAddress(characterFromID("SoldatD1"), "none", "");
			ChangeCharacterAddress(characterFromID("SoldatD2"), "none", "");
            SetCharacterShipLocation(characterFromID("Diablo"), "none");				
			
			GiveShip2Character(pchar,"XebecAS","El Diablo",-1,SPAIN,true,true);
            SetCharacterShipLocation(Pchar, "Douwesen_port");			
			DoQuestReloadToLocation("Douwesen_townhall", "reload", "reload1","adieu_douwesenbis");	
        break;

		case "adieu_douwesenbis":		
            ChangeCharacterAddressGroup(CharacterFromID("Berend de Voor"), "Douwesen_townhall", "goto", "goto8");
		    Characters[GetCharacterIndex("Reynard Grueneveldt")].dialog.currentnode = "gov_24";
			LAi_SetActorType(pchar);		
			LAi_ActorWaitDialog(CharacterFromID("Reynard Grueneveldt"), Pchar); 
			LAi_ActorDialog(pchar, characterFromID("Reynard Grueneveldt"),"", 5.0, 1.0);			
        break;

		case "Chico_Cuba":
           		Characters[GetCharacterIndex("Reynard Grueneveldt")].dialog.filename = "Reynard Grueneveldt_dialog.c"; // GR
			pchar.quest.chico_beach.win_condition.l1 = "location";
			pchar.quest.chico_beach.win_condition.l1.location = "Cuba_shore_01";
			pchar.quest.chico_beach.win_condition = "Chico_Cubabis";

			AddQuestRecord("Diablo", "2");		
			LAi_SetPlayerType(pchar);			
        break;

		case "Chico_Cubabis":
            ChangeCharacterAddressGroup(CharacterFromID("Chico Cois"), "Cuba_shore_01", "goto", "goto2");
            Characters[GetCharacterIndex("Chico Cois")].dialog.currentnode = "begin_84";
            LAi_SetActorType(characterFromID("Chico Cois"));
    		LAi_ActorDialog(characterFromID("Chico Cois"), pchar, "", 5.0, 1.0);					
        break;

		case "Chico_Adeus":
			AddQuestRecord("Diablo", "3");			
			ChangeCharacterAddress(characterFromID("Berend de Voor"), "none", "");
			ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Redmond_residence", "goto", "goto2");
            Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_1";
			LAi_ActorRunToLocation(characterFromID("Chico Cois"), "reload", "reload2", "none", "", "", "", 0);		
        break;
		
		case "Morgan_Tavern":
			CloseQuestHeader("Diablo");	
			DoQuestReloadToLocation("Redmond_tavern", "sit", "sit4","Morgan_Tavernbis");	
		break;	

		case "Morgan_Tavernbis":
            Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_7";			
            ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Redmond_tavern", "sit", "sit5");		
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			LAi_SetActorType(CharacterFromID("Henry Morgan"));
			LAi_ActorSetSitMode(CharacterFromID("Henry Morgan"));
			
			LAi_ActorWaitDialog(CharacterFromID("Henry Morgan"), Pchar); 
			LAi_ActorDialog(pchar, characterFromID("Henry Morgan"),"", 10.0, 10.0);
		break;

		case "Morgan_Tavernbis2":
			LAi_Fade("Laisser_Morgan", "");
        break;

		case "Laisser_Morgan":
            Pchar.quest.para_vera.win_condition.l1 = "location";
			Pchar.quest.para_vera.win_condition.l1.location = "KhaelRoa";
			PChar.quest.para_vera.win_condition = "arrival_veracruz";			
		
            ChangeCharacterAddressGroup(Pchar, "Redmond_tavern", "goto", "goto5");
            ChangeCharacterAddress(characterFromID("Henry Morgan"), "none", "");			
			LAi_SetPlayerType(pchar);

			SetQuestHeader("Aztec_throne");
			AddQuestRecord("Aztec_throne", "1");			
		break;

		case "arrival_veracruz":
            SetCurrentTime(10, 0);		
			SetCharacterShipLocation(Pchar, "Vera_Cruz_Port");
			SetCharacterShipLocation(CharacterFromID("Spanish Captain2"), "Vera_Cruz_Port");	
			SetCharacterShipLocation(CharacterFromID("Spanish Captain3"), "Vera_Cruz_Port");	
			SetCharacterShipLocation(CharacterFromID("Spanish Captain1"), "Vera_Cruz_Port");
			SetCharacterShipLocation(CharacterFromID("Spanish Captain4"), "Vera_Cruz_Port");

			DisableFastTravel(true);
			DisableMenuLaunch(true);
            DoQuestCheckDelay("arrival_veracruzbis", 3.0);					
		break;
		
		case "arrival_veracruzbis":
		   Locations[FindLocation("Vera_Cruz_01")].reload.l11.disable = true;			
           ChangeCharacterAddressGroup(characterFromID("Emilio Soares"), "Vera_Cruz_01", "goto", "goto89");
		   LAi_SetStayType(characterFromID("Emilio Soares"));		   
           Characters[GetCharacterIndex("Emilio Soares")].dialog.currentnode = "begin_10";		   
           DoReloadFromSeaToLocation("Vera_Cruz_Port", "reload", "sea");
		   AddQuestRecord("Aztec_throne", "2");			   
		break;

		case "Bart_Vera":
            ChangeCharacterAddressGroup(characterFromID("Bartolomeu"), "Vera_Cruz_Tavern", "sit", "sit4");
            SetModelfromArray(CharacterFromID("Bartolomeu"), GetModelIndex("GypsyCaptn_8"));				
			LAi_SetActorType(CharacterFromID("Bartolomeu"));
			LAi_ActorSetSitMode(CharacterFromID("Bartolomeu"));			
			Locations[FindLocation("Vera_Cruz_01")].reload.l11.disable = false;
            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_41";				
            LAi_SetActorType(CharacterFromID("Emilio Soares"));		
			LAi_ActorRunToLocation(characterFromID("Emilio Soares"), "reload", "reload14", "none", "", "", "Bart_Verabis", 10.0);		
		break;

		case "Bart_Verabis":		
			Pchar.quest.barti_tavern.win_condition.l1 = "location";
			Pchar.quest.barti_tavern.win_condition.l1.location = "Vera_Cruz_Tavern";
			PChar.quest.barti_tavern.win_condition = "barto_tavern";
        break;

		case "barto_tavern":
			LAi_QuestDelay("barto_tavernbis", 3.0);

        break;

		case "barto_tavernbis":
			LAi_Fade("barto_tavern3", "barto_tavern31");
		break;
		
		case "barto_tavern3":
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			ChangeCharacterAddressGroup(pchar, "Vera_Cruz_Tavern", "candles", "sit3");
		break;

		case "barto_tavern31":
            WaitDate("", 0,0,1,0,0);		
            SetCurrentTime(5, 0);
			
			LAi_ActorWaitDialog(CharacterFromID("Bartolomeu"), Pchar); 
			LAi_ActorDialog(pchar, characterFromID("Bartolomeu"),"", 10.0, 10.0);
		break;

		case "wait_for_barto":
			DoQuestReloadToLocation("Vera_Cruz_01", "goto", "goto91","wait_for_bartobis");
		break;

		case "wait_for_bartobis":
			LAi_SetActorType(pchar);
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Jump_Bartolomeu";
			LAi_ActorSelfDialog(pchar, "");					
		break;			
		
    	case "plaza_jump":
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Vera_Cruz_01", "goto", "goto107");
            LAi_SetStayType(CharacterFromID("Bartolomeu"));	
			LAi_SetImmortal(CharacterFromID("Bartolomeu"), true); //Added by levis 22-11-13	
            LAi_QuestDelay("plaza_jump11", 1.0);				 
        break;
		
    	case "plaza_jump11":
	        LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(PChar, characterFromID("Bartolomeu"));			 
            LAi_QuestDelay("plaza_jump2", 2.0);
        break;		

    	case "plaza_jump2":
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Vera_Cruz_01", "goto", "goto106");				
            LAi_SetActorType(CharacterFromID("Bartolomeu"));
            LAi_QuestDelay("plaza_jump2B", 0.5);
        break;			

    	case "plaza_jump2B":
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Vera_Cruz_01", "goto", "goto105");			
            LAi_ActorAnimation(CharacterFromID("Bartolomeu"), "jump", "stop_the_animation", 1.1);
        break;
		
        case "stop_the_animation":
            PlaySound("PEOPLE\jump.wav");		
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Vera_Cruz_01", "goto", "goto108");
            LAi_ActorSetLayMode(characterFromID("Bartolomeu"));
            LAi_QuestDelay("relever_bart", 1.0);			
        break;		

        case "relever_bart":
			LAi_ActorAnimation(characterFromID("Bartolomeu"), "Ground_StandUp", "relever_bart2", 3.0);	
        break;

        case "relever_bart2":
		LAi_SetPlayerType(Pchar);
		LAi_SetOfficerType(CharacterFromID("Bartolomeu"));
		if (!CheckCharacterItem(CharacterFromID("Bartolomeu"), "bladeBP")) GiveItem2Character(CharacterFromID("Bartolomeu"), "bladeBP");
		EquipCharacterByItem(CharacterFromID("Bartolomeu"), "bladeBP");

		LAi_group_FightGroups("VERA_SOLDIERS", LAI_GROUP_PLAYER, true);
		LAi_group_SetCheck("VERA_SOLDIERS", "relever_bart3");				  
        break;

        case "relever_bart3":
            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_58";
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 5.0, 1.0);	             				  
        break;

        case "outside_vera":
			SetCharacterShipLocation(Pchar, "Vera_Cruz_Beach");
			SetCharacterShipLocation(characterFromID("Bartolomeu"), "Vera_Cruz_Beach"); 			
			DoQuestReloadToLocation("Vera_Cruz_Beach", "goto", "citizen07","outside_verabis");             				  
        break;

        case "outside_verabis":
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Vera_Cruz_Beach", "goto", "locator10");   		
            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_59";
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 5.0, 1.0);	            				  
        break;

		case "leave_vera":
			PostVideoAndQuest("Assassin\pursuit",1, "chegar_cozumel");
		break;

        case "chegar_cozumel":
			SetCharacterShipLocation(Pchar, "KhaelRoa_port");
			SetCharacterShipLocation(characterFromID("Bartolomeu"), "KhaelRoa_port"); 			
			DoQuestReloadToLocation("KhaelRoa_port", "goto", "goto2","chegar_cozumelbis");             				  
        break;

        case "chegar_cozumelbis":
			DisableFastTravel(false);
			DisableMenuLaunch(false);		
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "KhaelRoa_port", "goto", "goto3");   		
            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_68";
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 5.0, 1.0);	            				  
        break;

		case "fleet_havana":
			Pchar.quest.flota_havana.win_condition.l1 = "location";
			Pchar.quest.flota_havana.win_condition.l1.location = "Cuba";
			PChar.quest.flota_havana.win_condition = "fleet_havanabis";

			SetCompanionIndex(Pchar, 1, GetCharacterIndex("Bartolomeu"));
			SetCharacterRemovable(characterFromID("Bartolomeu"), false);			
			LAi_ActorFollowEverywhere(characterFromID("Bartolomeu"), "", 60.0);
			
			AddQuestRecord("Aztec_throne", "3");				
		break;

		case "fleet_havanabis":
			PostVideoAndQuest("Assassin\fleet",1, "news_to_morgan");
		break;

		case "news_to_morgan":
			AddQuestRecord("Aztec_throne", "4");			
            ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Redmond_residence", "goto", "goto2");
            LAi_SetStayType(characterFromID("Henry Morgan"));			
            Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_25";	
		break;
		
		case "news_to_morganbis":
            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_70";
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 2.0, 1.0);	
		break;

		case "news_to_morganbis2":
            Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_28";
            LAi_SetActorType(characterFromID("Henry Morgan"));
    		LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 2.0, 1.0);			
		break;		

		case "morgan_to_havana":
			Pchar.quest.morgan_havana.win_condition.l1 = "location";
			Pchar.quest.morgan_havana.win_condition.l1.location = "Cuba";
			PChar.quest.morgan_havana.win_condition = "morgan_to_havanabis";

			SetCompanionIndex(Pchar, 2, GetCharacterIndex("Henry Morgan"));
			SetCharacterRemovable(characterFromID("Henry Morgan"), false);
			SetCharacterShipLocation(characterFromID("Henry Morgan"), "redmond_port");

            LAi_SetActorType(characterfromID("Henry Morgan"));
			LAi_ActorRunToLocation(characterfromID("Henry Morgan"), "reload", "reload1", "none", "", "", "", 6.0);
			LAi_ActorFollowEverywhere(characterFromID("Bartolomeu"), "", 60.0);

			AddQuestRecord("Aztec_throne", "5");				
		break;

		case "morgan_to_havanabis":
            ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Quest_Cabin2", "rld", "aloc2");
            LAi_SetStayType(characterFromID("Henry Morgan"));			
            Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_29";
			SetCharacterShipLocation(Pchar, "Cuba_shore_04");
			SetCharacterShipLocation(characterFromID("Bartolomeu"), "Cuba_shore_04");
			SetCharacterShipLocation(characterFromID("Henry Morgan"), "Cuba_shore_04");			
            DoReloadFromSeaToLocation("Quest_Cabin2", "reload", "reload1");	
		break;

		case "Priest_Clothes":
            DoQuestReloadToLocation("Cabin_small", "goto", "goto3", "Priest_Clothesbis");
		break;

		case "Priest_Clothesbis":
            SetCurrentTime(21, 0);		
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Cabin_small", "goto", "goto2");
            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_71";
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 1.0, 1.0);			
		break;
		
		case "Priest_Clothesbis2":
            DoQuestReloadToLocation("Cuba_shore_04", "goto", "citizen08", "Priest_Clothesbis3");
		break;		

		case "Priest_Clothesbis3":
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Cuba_shore_04", "goto", "citizen06");
            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_74";
			
            SetModelfromArray(&pchar, GetModelIndex("Animists2"));
            SetModelfromArray(characterFromID("Bartolomeu"), GetModelIndex("Animistse"));
			
			GiveItem2Character(Pchar, "bladelead");   
			EquipCharacterByItem(Pchar, "bladelead");
			GiveItem2Character(Pchar, "pistolrock");   
			EquipCharacterByItem(Pchar, "pistolrock");			
			GiveItem2Character(CharacterFromId("Bartolomeu"), "bladex4");   
			EquipCharacterByItem(CharacterFromId("Bartolomeu"), "bladex4");
			GiveItem2Character(CharacterFromId("Bartolomeu"), "pistolrock");   
			EquipCharacterByItem(CharacterFromId("Bartolomeu"), "pistolrock");
			
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 2.0, 1.0);			
		break;

		case "Damski_Havana":
			AddQuestRecord("Aztec_throne", "6");			
			LAi_ActorFollowEverywhere(characterFromID("Bartolomeu"), "", 60.0);		
            ChangeCharacterAddressGroup(CharacterFromID("Captain Damski"), "Damski_House", "goto", "goto1");
			locations[FindLocation("Havana_Town_01")].reload.l14.disable = 0;
            Characters[GetCharacterIndex("Captain Damski")].dialog.currentnode = "begin_13";			
		break;

		case "Bart_suggestion":
			LAi_SetStayType(characterFromID("Captain Damski"));		
            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_78";
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 2.0, 1.0);						
		break;

		case "Bart_suggestionbis":		
            Characters[GetCharacterIndex("Captain Damski")].dialog.currentnode = "begin_21";
            LAi_SetActorType(characterFromID("Captain Damski"));
    		LAi_ActorDialog(characterFromID("Captain Damski"), pchar, "", 2.0, 1.0);						
		break;
		
		case "Bart_suggestionbis2":	
            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_79";
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 2.0, 1.0);						
		break;

		case "Bart_suggestionbis3":
            SetCurrentTime(10, 0);		
            Characters[GetCharacterIndex("Captain Damski")].dialog.currentnode = "begin_24";
            LAi_SetActorType(characterFromID("Captain Damski"));
    		LAi_ActorDialog(characterFromID("Captain Damski"), pchar, "", 2.0, 1.0);						
		break;		

		case "Villalobos_church":
            WaitDate("", 0,0,1,0,0);		
            DoQuestReloadToLocation("Havana_town_02", "goto", "goto46", "Villalobos_churchbis");
		break;

		case "Villalobos_churchbis":
            ChangeCharacterAddressGroup(CharacterFromID("Captain Damski"), "Havana_town_02", "goto", "goto45");
            Characters[GetCharacterIndex("Captain Damski")].dialog.currentnode = "begin_26";
            LAi_SetActorType(characterFromID("Captain Damski"));
    		LAi_ActorDialog(characterFromID("Captain Damski"), pchar, "", 5.0, 1.0);				
		break;

		case "Villalobos_churchbis2":
            LAi_SetActorType(characterfromID("Captain Damski"));
			LAi_ActorRunToLocation(characterfromID("Captain Damski"), "reload", "reload10_back", "none", "", "", "", 20.0);
		
            ChangeCharacterAddressGroup(CharacterFromID("Captain Villalobos"), "Havana_town_02", "goto", "goto47");
            ChangeCharacterAddressGroup(CharacterFromID("VillaSoldat1"), "Havana_town_02", "goto", "goto47");
            ChangeCharacterAddressGroup(CharacterFromID("VillaSoldat2"), "Havana_town_02", "goto", "goto47");
			LAi_SetCitizenType(characterFromID("Captain Villalobos"));
            Characters[GetCharacterIndex("Captain Villalobos")].dialog.currentnode = "begin_6";			
			LAi_SetActorType(characterFromID("VillaSoldat1"));
			LAi_ActorFollow(characterFromID("VillaSoldat1"), characterFromID("Captain Villalobos"), "", 60.0);
			LAi_SetActorType(characterFromID("VillaSoldat2"));
        	LAi_ActorFollow(characterFromID("VillaSoldat2"), characterFromID("Captain Villalobos"), "", 60.0);			
		break;
		
		case "Villalobos_churchbis3":
			ChangeCharacterAddress(characterFromID("Pries_Havana"), "none", "");		
            DoQuestReloadToLocation("Havana_church", "goto", "goto11", "Villalobos_churchbis4");
		break;		

		case "Villalobos_churchbis4":
			LAi_LocationFightDisable(&Locations[FindLocation("Havana_church")], false);
			
            ChangeCharacterAddressGroup(CharacterFromID("Captain Villalobos"), "Havana_church", "reload", "reload1");
            ChangeCharacterAddressGroup(CharacterFromID("VillaSoldat1"), "Havana_church", "reload", "reload1");
            ChangeCharacterAddressGroup(CharacterFromID("VillaSoldat2"), "Havana_church", "reload", "reload1");
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Havana_church", "reload", "reload3");
			
            Characters[GetCharacterIndex("Captain Villalobos")].dialog.currentnode = "begin_10";
            LAi_SetActorType(characterFromID("Captain Villalobos"));
    		LAi_ActorDialog(characterFromID("Captain Villalobos"), pchar, "", 5.0, 1.0);			
		break;

		case "Villalobos_churchbis5":
            LAi_Fade("Villalobos_churchbis6", "");
			ChangeCharacterAddress(characterFromID("Bartolomeu"), "none", "");
			ChangeCharacterAddress(characterFromID("VillaSoldat1"), "none", "");
			ChangeCharacterAddress(characterFromID("VillaSoldat2"), "none", "");			
		break;
				
		case "Villalobos_churchbis6":
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE));
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE));
			
            LAi_ActorAttack(CharacterFromID("Captain Villalobos"), Pchar, "");	

			pchar.quest.villa_died.win_condition.l1 = "NPC_Death";
			pchar.quest.villa_died.win_condition.l1.character = "Captain Villalobos";
			pchar.quest.villa_died.win_condition = "villalobos_fight_end";
		break;
		
		case "villalobos_fight_end":
            LAi_Fade("villalobos_fight_endbis", "");
		break;			
		
		case "villalobos_fight_endbis":
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Havana_church", "reload", "reload3");
			EquipCharacterByItem(characterFromID("Bartolomeu"), "bladeBP");
 			EquipCharacterByItem(characterFromID("Bartolomeu"), "pistol2");			
            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_81";
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 3.0, 1.0);	
		break;

		case "villalobos_on_deck":			
            DoQuestReloadToLocation("Morgan_ShipDeck", "reload", "boatl", "villalobos_on_deckbis");
		break;

		case "villalobos_on_deckbis":
            SetModelfromArray(&pchar, GetModelIndex("Johan_Elting"));
            SetModelfromArray(characterFromID("Bartolomeu"), GetModelIndex("GypsyCaptn_8"));
			
            ChangeCharacterAddressGroup(CharacterFromID("Captain Villalobos"), "Morgan_ShipDeck", "rld", "loc12");
            SetModelfromArray(characterFromID("Captain Villalobos"), GetModelIndex("Animists1"));	     			
			LAi_SetActorType(characterFromID("Captain Villalobos"));
			LAi_ActorSetLayMode(characterFromID("Captain Villalobos"));
			GiveItem2Character(CharacterFromId("Captain Villalobos"), "bladex4");   
			EquipCharacterByItem(CharacterFromId("Captain Villalobos"), "bladex4");
			
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Morgan_ShipDeck", "rld", "loc10");
            ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Morgan_ShipDeck", "rld", "loc13");

            Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_31";
            LAi_SetActorType(characterFromID("Henry Morgan"));
    		LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 2.0, 1.0);					
		break;

		case "back_for_plan":
            ChangeCharacterAddressGroup(CharacterFromID("Pries_Havana"), "Havana_church", "goto", "goto11");		
            DoQuestReloadToLocation("Quest_Cabin2", "reload", "reload1", "back_for_planbis");
		break;

		case "back_for_planbis":		
            ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Quest_Cabin2", "rld", "aloc2");
            Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_34";
            LAi_SetActorType(characterFromID("Henry Morgan"));
    		LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 2.0, 1.0);				
		break;

		case "back_for_planbis2":			
             LAi_Fade("back_for_planbis3", "");     
		break;

		case "back_for_planbis3":
			WaitDate("", 0,0,1,0,0);
            SetCurrentTime(13, 0);			
            ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Quest_Cabin2", "rld", "aloc2");
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Quest_Cabin2", "rld", "aloc1");			
            Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_39";			
            LAi_SetStayType(CharacterFromID("Henry Morgan"));			
            LAi_SetActorType(Pchar);
			LAi_ActorWaitDialog(CharacterFromID("Henry Morgan"), Pchar); 
			LAi_ActorDialog(pchar, characterFromID("Henry Morgan"),"", 6.0, 1.0);				
		break;

		case "ElMorro_video":
			Locations[FindLocation("Morro_Fort")].locators_radius.goto.goto52 = 2.0;
			Locations[FindLocation("Morro_Fort")].locators_radius.goto.goto53 = 2.0;
			Locations[FindLocation("Morro_Fort")].locators_radius.goto.goto54 = 2.0;
			
            SetNextWeather("Blue Sky");		
            SetCurrentTime(1, 0);			
			SetCharacterShipLocation(CharacterFromID("Sneak barque"), "Morro_Fort");
			
			PostVideoAndQuest("Assassin\El Morro",1, "ElMorro_assault");
		break;

		case "ElMorro_assault":
            DoQuestReloadToLocation("Morro_Fort", "goto", "goto30", "ElMorro_assault2");
		break;

		case "ElMorro_assault2":
           ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_03"), "Morro_Fort", "goto", "goto32");			
           ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Morro_Fort", "goto", "goto31");
	       LAi_SetActorType(pchar);
		   LAi_ActorTurnToCharacter(PChar, characterFromID("Quest_Morro_soldier_11"));			
           LAi_QuestDelay("ElMorro_assault3", 3.0);
		break;		   

		case "ElMorro_assault3":		   
           ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_02"), "Morro_Fort", "goto", "goto29");
	       LAi_SetActorType(pchar);
		   LAi_ActorTurnToCharacter(PChar, characterFromID("elting_pirate_02"));		   
           LAi_SetActorType(CharacterFromID("elting_pirate_02"));		   
		   LAi_ActorRunToLocator(characterFromID("elting_pirate_02"), "goto", "goto47", "ElMorro_assault3b", 10.0);		   
		break;
		
		case "ElMorro_assault3b":		   
           LAi_SetActorType(CharacterFromID("elting_pirate_02"));		   
		   LAi_ActorRunToLocator(characterFromID("elting_pirate_02"), "goto", "goto48", "ElMorro_assault3b2", 10.0);		   
		break;

		case "ElMorro_assault3b2":
	       LAi_SetPlayerType(pchar);		
           LAi_SetActorType(CharacterFromID("elting_pirate_02"));		   
		   LAi_ActorRunToLocator(characterFromID("elting_pirate_02"), "goto", "goto49", "ElMorro_assault3b3", 10.0);		   
		break;

		case "ElMorro_assault3b3":
            ChangeCharacterAddress(characterFromID("Quest_Morro_soldier_11"), "none", "");			
            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_83";
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 0.0, 0.0);				
		break;
		
		case "ElMorro_assault6":			
             LAi_Fade("ElMorro_assault7", "");    
		break;

		case "ElMorro_assault7":
            ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_02"), "Morro_Fort", "goto", "goto33");		
            ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_04"), "Morro_Fort", "goto", "goto50");
            ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_05"), "Morro_Fort", "goto", "goto51");				
            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_84";
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 0.0, 0.0);				
		break;

		case "ElMorro_assault7bis":			
            DoQuestReloadToLocation("Morro_Fort", "goto", "goto30", "ElMorro_assault7bis2");               
		break;

    	case "ElMorro_assault7bis2":
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Morro_Fort", "goto", "goto47");
            LAi_SetActorType(CharacterFromID("Bartolomeu"));		   
    		LAi_ActorRunToLocator(characterFromID("Bartolomeu"), "goto", "goto48", "ElMorro_assault7bis3", 5.0);				
		break;		

		case "ElMorro_assault7bis3":
            LAi_SetActorType(CharacterFromID("Bartolomeu"));		   
    		LAi_ActorRunToLocator(characterFromID("Bartolomeu"), "goto", "goto49", "ElMorro_assault7bis4", 5.0);				
		break;
		
		case "ElMorro_assault7bis4":				
            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_86";
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 0.0, 0.0);				
		break;		
		
		case "ElMorro_assault8":		
			SetModelfromArray(&pchar, GetModelIndex("Johan_Elting_b"));
     	    LAi_SetCheckMinHP(Pchar, LAi_GetCharacterHP(Pchar)-1.0, true, "attaquesoldatos");
	        LAi_group_SetRelation("MORRO_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);			
            LAi_QuestDelay("ElMorro_assault8bis", 1.0);			
		break;			

		case "ElMorro_assault8bis":		
            DoQuestReloadToLocation("Morro_Fort", "goto", "goto34", "ElMorro_assault9");			
		break;
		
		case "ElMorro_assault9":
	        TakenItems(Pchar, "pistolpdart", 10);
            EquipCharacterbyItem(Pchar, "pistolpdart");			
	        TakenItems(Pchar, "time_bomb", 3);
			AddQuestRecord("Aztec_throne", "7");			
			LAi_group_SetCheck("MORRO_SOLDIERS", "posar_bomba");				
		break;		

        case "attaquesoldatos":
            PlaySound("Ambient\Sea\bell8_0400_0800_1200.wav");
    	    LAi_group_FightGroups("MORRO_SOLDIERS", LAI_GROUP_PLAYER, true);
    	    LAi_RemoveCheckMinHP(Pchar);
            LAi_SetImmortal(Pchar, false);
            LAi_QuestDelay("fuir_morro", 8.0);			
        break;

        case "fuir_morro":		
			QuestToSeaLogin_PrepareLoc("Cuba", "reload", "reload_9", true);
			QuestToSeaLogin_Launch();
			AddQuestRecord("Aztec_throne", "11");
            CloseQuestHeader("Aztec_throne");			
        break;			
		
        case "posar_bomba":
			AddQuestRecord("Aztec_throne", "8");
		
			pchar.quest.perto_cannon.win_condition.l1 = "locator";
			pchar.quest.perto_cannon.win_condition.l1.location = "Morro_Fort";
			pchar.quest.perto_cannon.win_condition.l1.locator_group = "goto";
			pchar.quest.perto_cannon.win_condition.l1.locator = "goto52";
			pchar.quest.perto_cannon.win_condition = "posar_bombebis";
		break;

        case "posar_bombebis":
			TakeItemFromCharacter(pchar, "time_bomb");
			
			pchar.quest.perto_cannonb.win_condition.l1 = "locator";
			pchar.quest.perto_cannonb.win_condition.l1.location = "Morro_Fort";
			pchar.quest.perto_cannonb.win_condition.l1.locator_group = "goto";
			pchar.quest.perto_cannonb.win_condition.l1.locator = "goto53";
			pchar.quest.perto_cannonb.win_condition = "posar_bombebis2";			
		break;
		
        case "posar_bombebis2":
			TakeItemFromCharacter(pchar, "time_bomb");
			
			pchar.quest.perto_cannonc.win_condition.l1 = "locator";
			pchar.quest.perto_cannonc.win_condition.l1.location = "Morro_Fort";
			pchar.quest.perto_cannonc.win_condition.l1.locator_group = "goto";
			pchar.quest.perto_cannonc.win_condition.l1.locator = "goto54";
			pchar.quest.perto_cannonc.win_condition = "posar_bombebis3";			
		break;		

        case "posar_bombebis3":
			TakeItemFromCharacter(pchar, "time_bomb");		
            LAi_QuestDelay("canoes_explosao", 6.0);				
		break;

        case "canoes_explosao":
    		CreateParticleSystemX("cancloud", 77.019, 24.267, -218.54, -1.57, 0.0, 0.0,20);			
			CreateParticleSystemX("cancloud", 22.421, 32.504, -154.62, -1.57, 0.0, 0.0,20);	
    		CreateParticleSystemX("cancloud", 100.58, 30.348, -142.78, -1.57, 0.0, 0.0,20);			
            PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
            ref morro;		
		    morro = &Locations[FindLocation("Morro_Fort")];
			DeleteAttribute(morro,"building");				
			
            LAi_QuestDelay("rever_morgan", 4.0);				
		break;			

		case "rever_morgan":
        	Build_at("Morro_Fort", "jungle", "", 92.747, 7.1396, -437.42, -1.2798, "Building");
            Build_at("Morro_Fort", "tent", "", 121.41, 26.644, -179.63, -1.5, "Building");
            Build_at("Morro_Fort", "tent", "", 87.05, 29.605, -180, -1.5, "Building");
            Build_at("Morro_Fort", "tent", "", 49.927, 31.178, -182.62, -1.5, "Building");
            Build_at("Morro_Fort", "tent", "", 15.903, 31.439, -186.09, -1.5, "Building");
            Build_at("Morro_Fort", "tent", "", -0.324, 33.099, -140.59, -1.5, "Building");
            Build_at("Morro_Fort", "tent", "", 31.049, 33.156, -130.62, -1.5, "Building");
            Build_at("Morro_Fort", "tent", "", 72.548, 32.47, -117.27, -1.5, "Building");
            Build_at("Morro_Fort", "tent", "", 106.96, 31.443, -110.27, -1.5, "Building");
            Build_at("Morro_Fort", "pit", "", 92.347, 30.826, -143.51, 0, "Building");
            Build_at("Morro_Fort", "pit", "", 30.594, 32.449, -155.09, 0, "Building");			
            Build_at("Morro_Fort", "Field_Cannon_broken", "", 22.421, 32.504, -154.62, -1.5, "Building");
            Build_at("Morro_Fort", "Field_Cannon_broken", "", 100.58, 30.348, -142.78, -1.5, "Building");
			
			ChangeCharacterAddress(characterFromID("Quest_Morro_soldier_01"), "none", "");			
			ChangeCharacterAddress(characterFromID("Quest_Morro_soldier_02"), "none", "");	
			ChangeCharacterAddress(characterFromID("Quest_Morro_soldier_03"), "none", "");	
			ChangeCharacterAddress(characterFromID("Quest_Morro_soldier_04"), "none", "");	
			ChangeCharacterAddress(characterFromID("Quest_Morro_soldier_05"), "none", "");
			ChangeCharacterAddress(characterFromID("Quest_Morro_soldier_06"), "none", "");
			ChangeCharacterAddress(characterFromID("Quest_Morro_soldier_07"), "none", "");
			ChangeCharacterAddress(characterFromID("Quest_Morro_soldier_08"), "none", "");	
			ChangeCharacterAddress(characterFromID("Quest_Morro_soldier_09"), "none", "");
			ChangeCharacterAddress(characterFromID("Quest_Morro_soldier_10"), "none", "");				
				
            DoQuestReloadToLocation("Morro_Fort", "goto", "goto17", "rever_morganb");	
        break;			

		case "rever_morganb":
			SetModelfromArray(&pchar, GetModelIndex("Johan_Elting"));		
	        LAi_RemoveCheckMinHP(Pchar);
            LAi_SetImmortal(Pchar, false);
            Build_at("Morro_Fort", "ladder", "", -15.065, 34.671, 32.661, 0.506, "");
            Build_at("Morro_Fort", "ladder", "", -9.33, 34.791, 23.014, 1.377, "");
            Build_at("Morro_Fort", "grapnel", "", -31.308, 34.215, -65.473, -1.595, "");
			
            ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Morro_Fort", "goto", "goto18");
            ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_01"), "Morro_Fort", "goto", "goto19");
            ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_02"), "Morro_Fort", "goto", "goto20");
            ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_03"), "Morro_Fort", "goto", "goto21");
            ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_04"), "Morro_Fort", "goto", "goto22");
            ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_05"), "Morro_Fort", "goto", "goto23");
            ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_06"), "Morro_Fort", "goto", "goto24");
            ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_07"), "Morro_Fort", "goto", "goto55");
			
            Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_44";
            LAi_SetActorType(characterFromID("Henry Morgan"));
    		LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 1.0, 0.0);				
        break;

		case "juntar_elting":
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Morro_Fort", "goto", "goto57");		
            DoQuestReloadToLocation("Morro_Fort", "goto", "goto56", "juntar_eltingb");		
        break;
		
		case "juntar_eltingb":
            ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_06"), "Morro_Fort", "goto", "goto58");		
            ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_04"), "Morro_Fort", "goto", "goto59");
            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_91";
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 0.5, 0.0);					
        break;

		case "juntar_eltingc":	
			LAi_Fade("juntar_eltingc2", "");
		break;

		case "juntar_eltingc2":
			ChangeCharacterAddressGroup(pchar, "Morro_Fort", "goto", "goto61");		
            ChangeCharacterAddressGroup(CharacterFromID("Quest_Morro_soldier_11"), "Morro_Fort", "goto", "goto60");			
			LAi_SetActorType(characterFromID("Quest_Morro_soldier_11"));
			LAi_ActorSetLayMode(characterFromID("Quest_Morro_soldier_11"));			
            ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_01"), "Morro_Fort", "goto", "goto63");		
            ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_02"), "Morro_Fort", "goto", "goto36");
            ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_03"), "Morro_Fort", "goto", "goto37");
            ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_05"), "Morro_Fort", "goto", "goto62");			
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Morro_Fort", "goto", "goto38");

            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_93";
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 1.0, 0.0);			
		break;

		case "trepar1":
			ChangeCharacterAddress(characterFromID("elting_pirate_01"), "none", "");				
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_01c"), "Morro_Fort", "goto", "goto65");
            LAi_SetActorType(CharacterFromID("elting_pirate_01c"));			
            LAi_ActorAnimation(CharacterFromID("elting_pirate_01c"), "Lay_1", "trepar2", 0.0);			
		break;	

		case "trepar2":
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_01c"), "Morro_Fort", "goto", "goto66");			
			LAi_ActorAnimation(CharacterFromID("elting_pirate_01c"), "Lay_2", "trepar3", 0.0);		
		break;

		case "trepar3":
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_01c"), "Morro_Fort", "goto", "goto67");
            LAi_ActorAnimation(CharacterFromID("elting_pirate_01c"), "Lay_1", "trepar4", 0.0);			
		break;	

		case "trepar4":
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_01c"), "Morro_Fort", "goto", "goto68");			
			LAi_ActorAnimation(CharacterFromID("elting_pirate_01c"), "Lay_2", "trepar5", 0.0);		
		break;

		case "trepar5":
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_01c"), "Morro_Fort", "goto", "goto69");
            LAi_ActorAnimation(CharacterFromID("elting_pirate_01c"), "Lay_1", "trepar6", 0.0);			
		break;	

		case "trepar6":
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_01c"), "Morro_Fort", "goto", "goto70");			
			LAi_ActorAnimation(CharacterFromID("elting_pirate_01c"), "Lay_2", "treparfim", 0.0);		
		break;

		case "treparfim":
			ChangeCharacterAddress(characterFromID("elting_pirate_01c"), "none", "");			
    		LAi_QuestDelay("treparfimb", 1.0);	
		break;		

		case "treparfimb":		
			ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_01"), "Morro_Fort", "goto", "goto64");
    		LAi_QuestDelay("neartower", 2.0);			
		break;

		case "neartower":		
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto72");
			LAi_SetHP(sld, 80.0, 80.0);
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");			
			LAi_group_MoveCharacter(sld, "FORT_SOLDATS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto74");
			LAi_SetHP(sld, 80.0, 80.0);
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");				
			LAi_group_MoveCharacter(sld, "FORT_SOLDATS");		
			
			LAi_Fade("neartowerb", "");
		break;
		
		case "neartowerb":
			ChangeCharacterAddressGroup(pchar, "Morro_Fort", "goto", "goto71");			
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Morro_Fort", "goto", "goto73");
            LAi_SetOfficerType(characterFromID("Bartolomeu"));
            PlayStereoSound("VOICE\ENGLISH\spa_m_a_008.wav");			
			LAi_group_FightGroups("FORT_SOLDATS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FORT_SOLDATS", "neartowerc");				
		break;
		
		case "neartowerc":	
            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_94";
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 1.0, 0.0);			
		break;

		case "morro_top":
			Locations[FindLocation("Quest_Morro_fort2")].locators_radius.reload.reload1 = 2.0;
			Locations[FindLocation("Quest_Morro_fort2")].locators_radius.reload.reload2 = 2.5;
			Locations[FindLocation("Quest_Morro_fort2")].locators_radius.reload.reload3 = 5.0;			
			
            DoQuestReloadToLocation("Quest_Morro_fort2", "goto", "goto1", "morro_topb");		
        break;

		case "morro_topb":
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Quest_Morro_fort2", "goto", "goto2");
			GiveItem2Character(characterfromID("Bartolomeu"), "blade5");   
			EquipCharacterByItem(characterfromID("Bartolomeu"), "blade5");
			GiveItem2Character(characterfromID("Bartolomeu"), "pistolrock");   
			EquipCharacterByItem(characterfromID("Bartolomeu"), "pistolrock");					

            ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_06"), "Quest_Morro_fort2", "goto", "goto3");
            LAi_SetActorType(CharacterFromID("elting_pirate_06"));
			LAi_ActorAnimation(CharacterFromID("elting_pirate_06"), "hands up", "", 1.0);

            ChangeCharacterAddressGroup(CharacterFromID("elting_pirate_04"), "Quest_Morro_fort2", "goto", "goto4");				
            LAi_SetActorType(CharacterFromID("elting_pirate_04"));
			LAi_ActorAnimation(CharacterFromID("elting_pirate_04"), "hands up", "", 1.0);

			GiveItem2Character(CharacterFromId("elting_pirate_04"), "bladex4");
			EquipCharacterByItem(CharacterFromId("elting_pirate_04"), "bladex4");
			GiveItem2Character(CharacterFromId("elting_pirate_04"), "pistolrock");
			EquipCharacterByItem(CharacterFromId("elting_pirate_04"), "pistolrock");
			
			GiveItem2Character(CharacterFromId("elting_pirate_06"), "bladex4"); 			
			EquipCharacterByItem(CharacterFromId("elting_pirate_06"), "bladex4");
			GiveItem2Character(CharacterFromId("elting_pirate_06"), "pistolrock");
			EquipCharacterByItem(CharacterFromId("elting_pirate_06"), "pistolrock");   			
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto10");
            sld.id = "soldatseul";				
			LAi_SetHP(sld, 15.0, 15.0);		
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");			
			LAi_group_MoveCharacter(sld, "FORTI_SOLDATS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto6");
			LAi_SetHP(sld, 80.0, 80.0);
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");				
			LAi_group_MoveCharacter(sld, "FORTI_SOLDATS");		

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "goto", "goto7");
			LAi_SetHP(sld, 80.0, 80.0);
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");			
			LAi_group_MoveCharacter(sld, "FORTI_SOLDATS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa5_16", "goto", "goto8");
			LAi_SetHP(sld, 80.0, 80.0);
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");				
			LAi_group_MoveCharacter(sld, "FORTI_SOLDATS");		

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa6_16", "goto", "goto9");
            sld.id = "soldatforbart";				
			LAi_SetHP(sld, 80.0, 80.0);
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");			
			LAi_group_MoveCharacter(sld, "FORTI_SOLDATS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "goto", "goto5");
			LAi_SetHP(sld, 80.0, 80.0);
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");				
			LAi_group_MoveCharacter(sld, "FORTI_SOLDATS");

            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_95";
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 0.0, 0.0);			
        break;
		
		case "morro_topc":
			pchar.quest.ver_bart.win_condition.l1 = "locator";
			pchar.quest.ver_bart.win_condition.l1.location = "Quest_Morro_fort2";
			pchar.quest.ver_bart.win_condition.l1.locator_group = "reload";
			pchar.quest.ver_bart.win_condition.l1.locator = "reload1";
			pchar.quest.ver_bart.win_condition = "morro_topd";			
		
			LAi_Fade("morro_topc2", "");			
        break;
		
		case "morro_topc2":
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Quest_Morro_fort2", "goto", "goto12");		
        break;

		case "morro_topd":		
			LAi_ActorAttack(CharacterFromID("Bartolomeu"), CharacterFromID("soldatseul"), "");

			pchar.quest.seul_died.win_condition.l1 = "NPC_Death";
			pchar.quest.seul_died.win_condition.l1.character = "soldatseul";
			pchar.quest.seul_died.win_condition = "morro_tope";
        break;

		case "morro_tope":
			pchar.quest.rescapes.win_condition.l1 = "locator";
			pchar.quest.rescapes.win_condition.l1.location = "Quest_Morro_fort2";
			pchar.quest.rescapes.win_condition.l1.locator_group = "reload";
			pchar.quest.rescapes.win_condition.l1.locator = "reload2";
			pchar.quest.rescapes.win_condition = "morro_topg";		

			LAi_SetActorType(PChar);			
			characters[GetCharacterIndex("Blaze")].dialog.CurrentNode = "Morro_Attack";
			LAi_ActorSelfDialog(pchar, "");			
        break;

		case "morro_topf":
			EquipCharacterByItem(CharacterFromId("Bartolomeu"), "bladeBP");
			EquipCharacterByItem(CharacterFromId("Bartolomeu"), "pistol2");			
			LAi_SetPlayerType(PChar);		
        break;

		case "morro_topg":
			pchar.quest.rescapesb.win_condition.l1 = "locator";
			pchar.quest.rescapesb.win_condition.l1.location = "Quest_Morro_fort2";
			pchar.quest.rescapesb.win_condition.l1.locator_group = "reload";
			pchar.quest.rescapesb.win_condition.l1.locator = "reload3";
			pchar.quest.rescapesb.win_condition = "morro_topi";	
		
            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_99";
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 0.0, 0.0);			
		break;

		case "morro_toph":		
           LAi_SetOfficerType(characterFromID("Bartolomeu"));		
        break;

		case "morro_topi":		
            PlayStereoSound("VOICE\ENGLISH\spa_m_b_057.wav");
            LAi_QuestDelay("morro_topj", 2.0);			
        break;
		
		case "morro_topj":		
			LAi_group_FightGroups("FORTI_SOLDATS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FORTI_SOLDATS", "morro_topk");
        break;

		case "morro_topk":
            LAi_SetActorType(CharacterFromID("elting_pirate_06"));
            LAi_SetStayType(CharacterFromID("elting_pirate_04"));
			
            Characters[GetCharacterIndex("elting_pirate_06")].dialog.currentnode = "begin_28";
            LAi_SetActorType(characterFromID("elting_pirate_06"));
    		LAi_ActorDialog(characterFromID("elting_pirate_06"), pchar, "", 0.0, 0.0);				
        break;

		case "morro_topl":			
            PlayStereoSound("OBJECTS\ABORDAGE\abordage.wav");
            LAi_QuestDelay("morro_topm", 5.0);			
        break;

		case "morro_topm":	 
            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_100";
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 0.0, 0.0);
        break;

		case "morro_topn":		
            DoQuestReloadToLocation("Quest_Morro_fort1", "goto", "goto7", "morro_down");		
        break;

		case "morro_down":
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Quest_Morro_fort1", "goto", "goto6");
            ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Quest_Morro_fort1", "rld", "aloc4");			
			LAi_group_MoveCharacter(CharacterFromID("Henry Morgan"), "MORGAN_PIRATES");
			LAi_SetImmortal(CharacterFromID("Henry Morgan"), true);				
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "rld", "aloc0");
            sld.id = "soldatspain1";				
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetImmortal(CharacterFromID("soldatspain1"), true);			
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");			
			LAi_group_MoveCharacter(sld, "FORTE_SOLDATS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "rld", "aloc5");
            sld.id = "soldatspain2";				
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetImmortal(CharacterFromID("soldatspain2"), true);					
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");				
			LAi_group_MoveCharacter(sld, "FORTE_SOLDATS");		

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "rld", "loc4");
            sld.id = "soldatspain3";				
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetImmortal(CharacterFromID("soldatspain3"), true);				
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");			
			LAi_group_MoveCharacter(sld, "FORTE_SOLDATS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa5_16", "rld", "loc9");
            sld.id = "soldatspain4";				
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetImmortal(CharacterFromID("soldatspain4"), true);					
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");				
			LAi_group_MoveCharacter(sld, "FORTE_SOLDATS");		

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa6_16", "rld", "aloc2");
            sld.id = "soldatspain5";				
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetImmortal(CharacterFromID("soldatspain5"), true);					
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");			
			LAi_group_MoveCharacter(sld, "FORTE_SOLDATS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat1", "rld", "aloc10");
            sld.id = "morganpirate1";			
            GiveItem2Character(sld,"blade10");					
            EquipCharacterByItem(sld,"blade10");				
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetImmortal(CharacterFromID("morganpirate1"), true);			
			LAi_group_MoveCharacter(sld, "MORGAN_PIRATES");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat2", "rld", "loc10");
            sld.id = "morganpirate2";				
            GiveItem2Character(sld,"blade10");					
            EquipCharacterByItem(sld,"blade10");				
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetImmortal(CharacterFromID("morganpirate2"), true);				
			LAi_group_MoveCharacter(sld, "MORGAN_PIRATES");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat3", "rld", "loc3");
            sld.id = "morganpirate3";				
            GiveItem2Character(sld,"blade10");					
            EquipCharacterByItem(sld,"blade10");				
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetImmortal(CharacterFromID("morganpirate3"), true);				
			LAi_group_MoveCharacter(sld, "MORGAN_PIRATES");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat4", "rld", "aloc3");
            sld.id = "morganpirate4";				
            GiveItem2Character(sld,"blade10");					
            EquipCharacterByItem(sld,"blade10");				
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetImmortal(CharacterFromID("morganpirate4"), true);				
			LAi_group_MoveCharacter(sld, "MORGAN_PIRATES");	

			LAi_group_FightGroups("FORTE_SOLDATS", "MORGAN_PIRATES", true);

            LAi_QuestDelay("morro_down2", 5.0);				
        break;

		case "morro_down2":	 
            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_101";
            LAi_SetActorType(characterFromID("Bartolomeu"));
    		LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 0.0, 0.0);
        break;

		case "morro_down3":
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Quest_Morro_fort1", "goto", "goto1");
			
            LAi_SetActorType(characterFromID("Bartolomeu"));
            LAi_ActorAnimation(characterFromID("Bartolomeu"), "jump", "stop_animationB", 1.8);
            LAi_QuestDelay("morro_down4", 1.2);
        break;

        case "morro_down4":
            PlaySound("PEOPLE\jump.wav");
            LAi_QuestDelay("morro_down5", 1.0);
        break;

        case "morro_down5":
			LAi_Fade("morro_down6", "");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "rld", "loc0");
            sld.id = "soldatspain6";				
			LAi_SetHP(sld, 80.0, 80.0);					
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");
			LAi_group_MoveCharacter(sld, "FORTEB_SOLDATS");			

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "rld", "aloc9");
            sld.id = "soldatspain7";				
			LAi_SetHP(sld, 80.0, 80.0);					
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");
			LAi_group_MoveCharacter(sld, "FORTEB_SOLDATS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "rld", "aloc6");				
			LAi_SetHP(sld, 80.0, 80.0);					
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");
            LAi_SetActorType(sld);			
			LAi_ActorSetLayMode(sld);			
        break;

        case "morro_down6":
            ChangeCharacterAddressGroup(Pchar, "Quest_Morro_fort1", "goto", "goto4");
            LAi_SetActorType(Pchar);
            LAi_ActorAnimation(pchar, "jump", "stop_animation", 1.8);
            LAi_QuestDelay("morro_down7", 1.2);			
        break;

        case "morro_down7":
            PlaySound("PEOPLE\jump.wav");		
        break;
 
        case "morro_down8": 
			LAi_SetImmortal(CharacterFromID("morganpirate4"), false);
			LAi_SetImmortal(CharacterFromID("morganpirate3"), false);
			LAi_SetImmortal(CharacterFromID("morganpirate2"), false);
			LAi_SetImmortal(CharacterFromID("morganpirate1"), false);

			LAi_SetImmortal(CharacterFromID("soldatspain5"), false);
			LAi_SetImmortal(CharacterFromID("soldatspain4"), false);	
			LAi_SetImmortal(CharacterFromID("soldatspain3"), false);	
			LAi_SetImmortal(CharacterFromID("soldatspain2"), false);
			LAi_SetImmortal(CharacterFromID("soldatspain1"), false);

			LAi_group_SetCheck("FORTE_SOLDATS", "morro_down9");			
        break;
		
        case "morro_down9": 
            DoQuestReloadToLocation("Quest_Morro_fort1", "rld", "aloc4", "morro_down10");	
        break;

        case "morro_down10": 
            ChangeCharacterAddressGroup(CharacterFromID("Capitan Caceres"), "Quest_Morro_fort1", "rld", "loc10");
            ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Quest_Morro_fort1", "goto", "goto8");
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Quest_Morro_fort1", "goto", "goto11");			
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat3", "goto", "goto9");				
            GiveItem2Character(sld,"blade10");					
            EquipCharacterByItem(sld,"blade10");				
			LAi_SetHP(sld, 80.0, 80.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat4", "goto", "goto10");				
            GiveItem2Character(sld,"blade10");					
            EquipCharacterByItem(sld,"blade10");				
			LAi_SetHP(sld, 80.0, 80.0);

            Characters[GetCharacterIndex("Capitan Caceres")].dialog.currentnode = "begin_29";
            LAi_SetActorType(characterFromID("Capitan Caceres"));
    		LAi_ActorDialog(characterFromID("Capitan Caceres"), pchar, "", 0.5, 0.0);			
        break;

        case "morro_down11": 
			LAi_ActorAttack(CharacterFromID("Capitan Caceres"), Pchar, "");

			pchar.quest.caceres_died.win_condition.l1 = "NPC_Death";
			pchar.quest.caceres_died.win_condition.l1.character = "Capitan Caceres";
			pchar.quest.caceres_died.win_condition = "morro_down12";
        break;

		case "morro_down12":	 
            Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_46";
            LAi_SetActorType(characterFromID("Henry Morgan"));
    		LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 0.0, 0.0);
        break;

		case "morro_entrepot":
			Locations[FindLocation("Morro_warehouse")].locators_radius.goto.goto7 = 3.0;		
            DoQuestReloadToLocation("Morro_warehouse", "reload", "reload1", "morro_entrepot2");           
        break;

		case "morro_entrepot2":
            ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Morro_warehouse", "goto", "goto5");
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Morro_warehouse", "goto", "goto9");
			LAi_SetOfficerType(characterFromID("Henry Morgan"));
			LAi_SetOfficerType(characterFromID("Bartolomeu"));			
		
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa_16", "goto", "goto7");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "WAREINSIDE_SOLDADOS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa2_16", "goto", "goto6");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "WAREINSIDE_SOLDADOS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa4_16", "goto", "goto2");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "WAREINSIDE_SOLDADOS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto3");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "WAREINSIDE_SOLDADOS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Soldier_spa3_16", "goto", "goto8");
            GiveItem2Character(sld,"blade2");					
            EquipCharacterByItem(sld,"blade2");					
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "WAREINSIDE_SOLDADOS");				
			
			LAi_group_FightGroups("WAREINSIDE_SOLDADOS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("WAREINSIDE_SOLDADOS", "morro_entrepot3");
        break;

		case "morro_entrepot3":
			pchar.quest.ver_trone.win_condition.l1 = "locator";
			pchar.quest.ver_trone.win_condition.l1.location = "Morro_warehouse";
			pchar.quest.ver_trone.win_condition.l1.locator_group = "goto";
			pchar.quest.ver_trone.win_condition.l1.locator = "goto7";
			pchar.quest.ver_trone.win_condition = "morro_entrepot5";
		
            Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_47";
            LAi_SetActorType(characterFromID("Henry Morgan"));
    		LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 0.0, 0.0);
        break;

		case "morro_entrepot4":
			DeleteAttribute(&Locations[FindLocation("Morro_Fort")],"building");
			
			LAi_SetOfficerType(characterFromID("Bartolomeu"));			
            LAi_ActorGoToLocator(characterFromID("Henry Morgan"), "goto", "goto10", "_", 18.0);
        break;

		case "morro_entrepot5":
           Build_at("Morro_Fort", "box", "", -10.675, 1.9298, -419.53, 1.5, "Building");
           Build_at("Morro_Fort", "box", "", -15.121, 1.5015, -418.98, 1.5, "Building");
           Build_at("Morro_Fort", "box", "", -16.949, 1.5398, -426.9, 1.5, "Building");
           Build_at("Morro_Fort", "jungle", "", 92.747, 7.1396, -437.42, -1.2798, "Building");
           Build_at("Morro_Fort", "shipyard", "", -28.739, 1.0908, -446, -0.77, "Building");
           Build_at("Morro_Fort", "barracks", "", -10.054, 1.427, -396.47, -1.6468, "Building");
		   
		   SetCharacterShipLocation(CharacterFromID("Sneak barque"), "Morro_Fort");	
		   SetCharacterShipLocation(CharacterFromID("Sneak barque2"), "Morro_Fort");				
		
           Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_48";
           LAi_SetActorType(characterFromID("Henry Morgan"));
    	   LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 0.0, 0.0);
       break;

		case "morro_beach":
            DoQuestReloadToLocation("Morro_Fort", "goto", "goto75", "morro_beach2");  
       break;

		case "morro_beach2":
            ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Morro_Fort", "goto", "goto76");
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Morro_Fort", "goto", "goto77");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat3", "goto", "goto78");				
            GiveItem2Character(sld,"blade10");					
            EquipCharacterByItem(sld,"blade10");				
			LAi_SetHP(sld, 80.0, 80.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat4", "goto", "goto79");				
            GiveItem2Character(sld,"blade10");					
            EquipCharacterByItem(sld,"blade10");				
			LAi_SetHP(sld, 80.0, 80.0);
			
           Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_50";
           LAi_SetActorType(characterFromID("Henry Morgan"));
    	   LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 0.0, 0.0);			
       break;

		case "leave_morro":
			Pchar.quest.allerpr.win_condition.l1 = "location";
			Pchar.quest.allerpr.win_condition.l1.location = "Redmond";
			PChar.quest.allerpr.win_condition = "reach_PortRoyal";	
		
			QuestToSeaLogin_PrepareLoc("Cuba", "reload", "reload_9", true);
			QuestToSeaLogin_Launch();
			AddQuestRecord("Aztec_throne", "9");			
       break;

		case "reach_PortRoyal":
			Characters[GetCharacterIndex("John Clifford Brin")].dialog.currentnode = "gov_1";		
            ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Redmond_Residence", "goto", "goto9");
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Redmond_Residence", "goto", "goto10");		
			DoReloadFromSeaToLocation("Redmond_Residence", "reload", "reload1");
       break;

		case "Morro_loot":
            DoQuestReloadToLocation("Redmond_store", "goto", "goto4", "Morro_loot2"); 
       break;

		case "Morro_loot2":		
            ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Redmond_store", "goto", "goto5");
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Redmond_store", "goto", "goto2");		
            Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_51";
            LAi_SetActorType(characterFromID("Henry Morgan"));
        	LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 1.0, 0.0);
       break;

		case "Morro_loot3":
            DoQuestReloadToLocation("Redmond_Town_01", "goto", "goto18", "Morro_loot4"); 
       break;

		case "Morro_loot4":
			SetCharacterShipLocation(Pchar, "redmond_port");			
            ChangeCharacterAddressGroup(CharacterFromID("Henry Morgan"), "Redmond_Town_01", "goto", "goto10");
            ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu"), "Redmond_Town_01", "reload", "door_5");		
            Characters[GetCharacterIndex("Henry Morgan")].dialog.currentnode = "begin_58";
            LAi_SetOfficerType(characterFromID("Bartolomeu"));			
            LAi_SetActorType(characterFromID("Henry Morgan"));
        	LAi_ActorDialog(characterFromID("Henry Morgan"), pchar, "", 2.0, 0.0);
       break;

		case "Morro_loot5":		
            LAi_SetActorType(characterfromID("Henry Morgan"));
			LAi_ActorRunToLocation(characterfromID("Henry Morgan"), "reload", "reload_1_3", "none", "", "", "", 10.0);		
            Characters[GetCharacterIndex("Bartolomeu")].dialog.currentnode = "begin_102";			
            LAi_SetActorType(characterFromID("Bartolomeu"));
        	LAi_ActorDialog(characterFromID("Bartolomeu"), pchar, "", 1.0, 0.0);
       break;

		case "Morro_loot6":
			RemoveCharacterCompanion(Pchar, characterFromID("Henry Morgan"));
			setCharacterShipLocation(characterFromID("Henry Morgan"), "none");
			RemoveCharacterCompanion(Pchar, characterFromID("Bartolomeu"));
			setCharacterShipLocation(characterFromID("Bartolomeu"), "none");
			
			ChangeRMRelation(pchar, SPAIN, -20.0);		
			AddQuestRecord("Aztec_throne", "10");
			CloseQuestHeader("Aztec_throne");				
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			
            LAi_SetActorType(characterfromID("Bartolomeu"));
			LAi_ActorRunToLocation(characterfromID("Bartolomeu"), "reload", "reload_2_4", "none", "", "", "", 15.0);					
       break;			

        case "stop_animation":
            Lai_SetPlayerType(pchar);
            LAi_SetOfficerType(characterFromID("Bartolomeu"));
    	    LAi_group_FightGroups("FORTEB_SOLDATS", LAI_GROUP_PLAYER, true);			
			LAi_group_SetCheck("FORTEB_SOLDATS", "morro_down8");			
        break;

        case "stop_animationB":
            Lai_SetStayType(characterFromID("Bartolomeu"));     
        break;		
		
		case "ultimavez":
			DisableFastTravel(true);
			DisableMenuLaunch(true);
            DoQuestCheckDelay("ultimavezbis", 5.0);		
		break;

		case "ultimavezbis":
			DoReloadFromSeaToLocation("Havana_House_03", "reload", "reload1");
			locations[FindLocation("Havana_House_03")].reload.l2.disable = 1;			
            ChangeCharacterAddressGroup(CharacterFromID("Salvadore Benavides"), "Havana_House_03", "goto", "goto3");
			LAi_SetActorType(characterFromID("Salvadore Benavides"));
			Characters[GetCharacterIndex("Salvadore Benavides")].dialog.currentnode = "begin_99";
			LAi_ActorDialog(characterFromID("Salvadore Benavides"), pchar, "", 4.0, 1.0);             
		break;			
		
		case "final_infeliz":	
			GameOverOrg("mutiny");
		break;

		PChar.questnotfound = true; // PB: Testing
	}
}
