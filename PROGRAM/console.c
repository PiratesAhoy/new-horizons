// Jerry-rigged console file.
//put code under ExecuteConsole() below.
//NK 04-08-28
// not needed I think extern void InitShips();
#include "SDK\LocatorWrite.c"
#include "Upgrade.c";
extern void InitItems();
extern void InitCannons();


void ExecuteConsole()
{
	ref pchar = GetMainCharacter();
	ref ch;
	int i;
	int limit;
											// Case 0 = Enable reload (useful when you get stuck on boarding) + Set player type (if you cannot move anymore)
	switch(0)								// Case 1 = Various test and cheat codes
	{										// Case 2 = Location coordinate information

		GiveItem2Character(PChar, "map_maltese_crypt");

		case 1:								// Case 3 = Automatic instant cheats in port
											// Case 4 = Instant teleport to Hendrick Vanderdecken

		// Give ship
		// ------------------
		/*	for (i = 0; i < COMPANION_MAX; i++) {
				limit = GetCompanionIndex(PChar, i);
				if (limit < 0) continue;
				ch = GetCharacter(limit);
				GiveShip2Character(ch,ch.ship.type,ch.ship.name,-1,ch.ship.stats.nation,true,true);
			}*/
		//	GiveShip2Character(pchar,"NL_Amsterdam","Amsterdam",-1,HOLLAND,true,true);
		//	GiveShip2Character(pchar,"CursedDutchman","Flying Dutchman",-1,PIRATE,true,true);
		//	GiveShip2Character(pchar,"QueenAnnesRevenge","Queen Anne's Revenge",-1,PIRATE,true,true);
		//	GiveShip2Character(pchar,"RN_SteamFrigate","Astrea",-1,ENGLAND,true,true);
		//	CrimsonBlood_ModifyShip()
		//	GiveShip2Character(pchar,SHIP_CURSED,PreprocessText("#scursed_ship#"),-1,PIRATE,true,true);
		/*
			if (PreprocessText("#scursed_ship#") == "Black Pearl")
				GiveShip2Character(pchar,"BlackPearl",PreprocessText("#scursed_ship#"),-1,PIRATE,true,true);
			else
			{
				GiveShip2Character(pchar,"CrimsonBlood",PreprocessText("#scursed_ship#"),-1,PIRATE,true,true);
				pchar.EmblemedSails.normalTex = "Ships\Sails\sail_Petros_black_red.tga"; // PB
				pchar.EmblemedSails.nationFileName = "Ships\Sails\sail_Petros_black_red.tga"; // PB
			}
		*/
		/*
			if(!Checkattribute(pchar,"cheatship")) Pchar.cheatship = 0;
			int con = sti(Pchar.cheatship);
			if(con<SHIP_TYPES_QUANTITY)
			{
				GiveShip2Character(pchar,ShipsTypes[con].id,"Test Ship",-1,ENGLAND,true,true);
				Pchar.cheatship = con +1;
			}
			TraceAndLog("*************************** Ship : " + ShipsTypes[con].id + " , Index : " + con + " ");
		*/
		// Give items
		// ------------------
		/*
			GiveItem2Character(PChar, "compass3");
			EquipCharacterByItem(pchar, "compass3");
			GiveItem2Character(pchar, "spyglass4");
			EquipCharacterByItem(pchar, "spyglass4");
			GiveItem2Character(pchar, "clock2");
			EquipCharacterByItem(pchar, "clock2");
			GiveItem2Character(pchar,"blade26+3");
			EquipCharacterByItem(pchar, "blade26+3");
			GiveItem2Character(pchar,"pistol3_14");
			EquipCharacterByItem(pchar, "pistol3_14");
			GiveItem2Character(pchar, "sextant");
			GiveItem2Character(pchar, "Trident_Neptune");

			GiveItem2Character(pchar, "mapKhaelRoa");
			GiveItem2Character(pchar, "mapAntigua");
			GiveItem2Character(pchar, "mapCayman");
			GiveItem2Character(pchar, "mapConceicao");
			GiveItem2Character(pchar, "mapCuba");
			GiveItem2Character(pchar, "mapDouwesen");
			GiveItem2Character(pchar, "mapFalaiseDeFleur");
			GiveItem2Character(pchar, "mapGuadeloupe");
			GiveItem2Character(pchar, "mapHispaniola");
			GiveItem2Character(pchar, "mapIslaMuelle");
			GiveItem2Character(pchar, "mapOxbay");
			GiveItem2Character(pchar, "mapQuebradasCostillas");
			GiveItem2Character(pchar, "mapRedmond");
			GiveItem2Character(pchar, "mapSaintMartin");
			GiveItem2Character(pchar, "mapTurks");
			GiveItem2Character(pchar, "mapAruba");
			GiveItem2Character(pchar, "mapCuracao");
			GiveItem2Character(pchar, "mapEleuthera");
			GiveItem2Character(pchar, "mapRedmond_Dungeon");
			GiveItem2Character(pchar, "mapOxbay_Dungeon");
			GiveItem2Character(pchar, "mapOxbay_Cave");
			GiveItem2Character(pchar, "mapDouwesen_Cave");
			GiveItem2Character(pchar, "mapKhaelRoa_TempleGround");
			GiveItem2Character(pchar, "mapKhaelRoa_TempleUpper");
		*/

		/*
			GiveItem2Character(Pchar, "skull_ring");
			GiveItem2Character(Pchar, "moccasins");
			GiveItem2Character(Pchar, "mayan_compass");
			GiveItem2Character(Pchar, "empty_pipe");
			GiveItem2Character(Pchar, "dried_mushrooms");
			GiveItem2Character(Pchar, "bladeflint");
			GiveItem2Character(Pchar, "pistolsteel");
		*/

		// Models and Times (for screenshot-making)
		// ------------------
		//	GiveModel2Player("Jack",true);
		//	SetNextWeather("Clear");
		//	SetCurrentTime(00.00, 0); // NIGHT1.COL
		//	SetCurrentTime(06.00, 0); // EVENING3.COL
		//	SetCurrentTime(12.00, 0); // DAY1.COL
		//	SetCurrentTime(20.00, 0); // MORNING1.COL
		//	CycleThroughTexturedModels("Town_Redmond\Town_04");
		//	ReloadToTexturedModel("Town_Redmond\Town_03", "ENGLAND");

		// Reload to location
		// ------------------
		//	DoQuestReloadToLocation("Redmond_port", "reload", "Sea_2_back" ,"_");
		//	PlaceFleetNearShore("Redmond_port");
		//	DoQuestReloadToLocation("Oxbay_Port", "reload", "reload1" ,"_");
		//	PlaceFleetNearShore("Oxbay_Port");

		// Capture Colony
		// ------------------
		/*	if(!CheckAttribute(PChar, "officers"))
			{
				ch = CreateOfficer_Cheat(OFFIC_TYPE_QMASTER, "Jack", 0, PIRATE, false);
				ch.name = "Jack";
				ch.lastname = "Sparrow";

				ch = CreateOfficer_Cheat(OFFIC_TYPE_CANNONEER, "bocman5", 0, PIRATE, false);
				ch.name = "Joshamee";
				ch.lastname = "Gibbs";

				ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Barbossa", 3, PIRATE, false);
				ch.name = "Hector";
				ch.lastname = "Barbossa";

				ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPNAVY, "Conorrington", 3, ENGLAND, false);
				ch.name = "James";
				ch.lastname = "Norrington";
				PChar.officers = true;
			}
			pchar.colony_capture = true;
			LaunchCaptureColony(pchar, "Douwesen");*/

		//	DEBUG = 1;

		/*	object obj_var;
			ref refobj; makeref(refobj, sea);
			trace("obj_var attributes:");
			DumpAttributes(refobj);
		*/
		//	ch = GetCharacter(GetCompanionIndex(pchar, sti(1)));
		/*	aref aref_var; makearef(aref_var, PChar);
			trace("aref_var attributes:");
			DumpAttributes(aref_var);
		*/
		break;

		case 2:
			if (!bSeaActive) {
				float x,y,z,ay,xx,zz,xz,zx;
				GetCharacterPos(GetMainCharacter(), &x, &y, &z);
				GetCharacterAy(pchar, &ay);
				xx = -sin(ay - PId2);
				zz = xx;
				xz = -cos(ay - PId2);
				zx = -xz;
				Logit("Location id: "+pchar.location);
				Logit("Your Coords x: " + x+"  y: "+y+"  z: "+z );
				Logit("Viewangle ay: "+ay+"; xx= "+xx+" xz= "+xz+" zx= "+zx+" zz= "+zz);
				Logit("Curlocator: "+chrWaitReloadLocator);
			//	trace("rld,loc," +xx+",0,"+xz+",0,1,0,"+zx+",0,"+zz+","+x+","+y+","+z+",1,0,0,0,0,0,0,0,0,");
			//	trace("rld,aloc,"+xx+",0,"+xz+",0,1,0,"+zx+",0,"+zz+","+x+","+y+","+z+",1,0,0,0,0,0,0,0,0,");
			} else {
				Logit("Ship position: x="+pchar.ship.pos.x+", z="+pchar.ship.pos.z);
			}
			//Logit("Ship position: x="+worldMap.playerShipX+", z="+worldMap.playerShipZ);
		break;

		case 3:
			if (hasSubStr(pchar.location, "_port")) {
				GiveShip2Character(pchar, "HMS_Dauntless","Dauntless",-1,ENGLAND,true,true);

				ChangeCharacterReputation(pchar, 60);

				GiveItem2Character(PChar, "compass3");
				EquipCharacterByItem(pchar, "compass3");
				GiveItem2Character(pchar, "spyglass4");
				EquipCharacterByItem(pchar, "spyglass4");
				GiveItem2Character(pchar, "blade13+1");
				EquipCharacterByItem(pchar, "blade13+1");
				GiveItem2Character(Pchar, "pistol5+2");
				EquipCharacterByItem(pchar, "pistol5+2");
				GiveItem2Character(pchar, "commonarmor");
				EquipCharacterByItem(pchar, "commonarmor");
				GiveItem2Character(pchar, "Trident_Neptune");
				PChar.rank = 40;
				pchar.experience = CalculateExperienceFromRank(sti(PChar.rank));
				ResetHP(pchar);
				LAi_SetImmortal(pchar, true);

				ch = CreateOfficer_Cheat(OFFIC_TYPE_QMASTER, "Jack", 0, PIRATE, false);
				ch.name = "Jack";
				ch.lastname = "Sparrow";
				SetOfficersIndex(pchar, -1, GetCharacterIndex(ch.id));

				ch = CreateOfficer_Cheat(OFFIC_TYPE_CANNONEER, "bocman5", 0, PIRATE, false);
				ch.name = "Joshamee";
				ch.lastname = "Gibbs";
				SetOfficersIndex(pchar, -1, GetCharacterIndex(ch.id));

				ch = CreateOfficer_Cheat(OFFIC_TYPE_NAVIGATOR, "Conorrington", 3, ENGLAND, false);
				ch.name = "James";
				ch.lastname = "Norrington";
				SetOfficersIndex(pchar, -1, GetCharacterIndex(ch.id));

			/*	ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPPIRATE, "Barbossa", 3, PIRATE, false);
				ch.name = "Hector";
				ch.lastname = "Barbossa";
				GiveShip2Character(ch,SHIP_CURSED,"Black Pearl",-1,PIRATE,true,true);
				SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
				RemovePassenger  (pchar,     CharacterFromID  (ch.id));

				ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPPIRATE, "DavyJones", 0, PIRATE, false);
				ch.name = "Davy";
				ch.lastname = "Jones";
				GiveShip2Character(ch, "CursedDutchman","Flying Dutchman",-1,PIRATE,true,true);
				SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
				RemovePassenger  (pchar,     CharacterFromID  (ch.id));

				ch = CreateOfficer_Cheat(OFFIC_TYPE_CAPPIRATE, "Blackbeard", 3, PIRATE, false);
				ch.name = "Edward";
				ch.lastname = "Teach";
				GiveShip2Character(ch, "QueenAnnesRevenge","Queen Anne's Revenge",-1,PIRATE,true,true);
				SetCompanionIndex(pchar, -1, GetCharacterIndex(ch.id));
				RemovePassenger  (pchar,     CharacterFromID  (ch.id));*/

				int idx = GetMainCharacterIndex();
				aref arPerksRoot; makearef(arPerksRoot,ChrPerksList.list);
				int chrPerksQ = GetAttributesNum(arPerksRoot);
				//For Passengers
				int s,p;
				string skillname,perkName;
				for (i = 0; i <= GetPassengersQuantity(PChar); i++) {
					if (i > 0) {
						idx = GetPassenger(PChar, i - 1);
						if (idx < 0) continue;

						GiveItem2Character(GetCharacter(idx), "blade13+1");
						EquipCharacterByItem(GetCharacter(idx), "blade13+1");
						GiveItem2Character(GetCharacter(idx), "pistol5+2");
						EquipCharacterByItem(GetCharacter(idx), "pistol5+2");
						GiveItem2Character(GetCharacter(idx), "commonarmor");
						EquipCharacterByItem(GetCharacter(idx), "commonarmor");
						TakeNItems(GetCharacter(idx), "gunpowder", 6);
						TakeNItems(GetCharacter(idx), "pistolbullets", 6);
					}

					for (s = 0; s < 10; s++) {
						skillname = GetSkillName(s);
						characters[idx].Skill.(skillname) = 10;
					}

					for (p = 0; p < chrPerksQ; p++)
					{
						perkName = GetAttributeName(GetAttributeN(arPerksRoot, p));
						characters[idx].perks.list.(perkName) = true;
					}
				}
				//For companions
				for(i=0; i < 4; i++)
				{
					if (i > 0) {
						idx = GetCompanionIndex(PChar, i - 1);
						if (idx < 0) continue;

						GiveItem2Character(GetCharacter(idx), "blade13+1");
						EquipCharacterByItem(GetCharacter(idx), "blade13+1");
						GiveItem2Character(GetCharacter(idx), "pistol5+2");
						EquipCharacterByItem(GetCharacter(idx), "pistol5+2");
						GiveItem2Character(GetCharacter(idx), "commonarmor");
						EquipCharacterByItem(GetCharacter(idx), "commonarmor");
						TakeNItems(GetCharacter(idx), "gunpowder", 6);
						TakeNItems(GetCharacter(idx), "pistolbullets", 6);
					}

					for (s = 0; s < 10; s++) {
						skillname = GetSkillName(s);
						characters[idx].Skill.(skillname) = 10;
					}

					for (p = 0; p < chrPerksQ; p++)
					{
						perkName = GetAttributeName(GetAttributeN(arPerksRoot, p));
						characters[idx].perks.list.(perkName) = true;
					}
				}
			}
		break;

		case 4:
			if(!CheckCharacterItem(PChar, "aztec_compass")) GiveItem2Character(PChar, "aztec_compass");
			CreateIslaDeMuerte();
			DoQuestReloadToLocation("IslaDeMuerte_Cabin", "reload", "reload1" ,"_");
			PlaceFleetNearShore("IslaDeMuerte_shore_02");
		break;

		case 5:
			if (IsEntity(&Artifact)) DeleteClass(&Artifact);
			else
			{
				CreateEntity(&artifact, "shiplamp");
				LayerAddObject(SEA_REALIZE, &artifact, -1);
			}
		break;

		case 6:
			if(Pchar.location != "Temple")
			{
				Pchar.quest.JRH_rain = "Clear";
				SetNextWeather("Clear");
				pchar.quest.effectnr = "2";
				Logit("effectnr = " + pchar.quest.effectnr);
				DoQuestReloadToLocation("Temple", "goto", "goto4" ,"_");
			}
			else
			{
			    if(CheckAttribute(pchar,"quest.effectnr")) 
			    {
					switch (pchar.quest.effectnr)
					{
					    case "2": CreateParticleSystem("smoke" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "3": CreateParticleSystem("smoke_short" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
				
					    case "4": CreateParticleSystem("smoke_inv" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
				
					    case "5": CreateParticleSystem("smoke_inv_short" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "6": CreateParticleSystem("fire" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "7": CreateParticleSystem("fire_medium" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "8": CreateParticleSystem("cancloud" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "9": CreateParticleSystem("cancloud_stock" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "10": CreateParticleSystem("cancloud_grey" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "11": CreateParticleSystem("KNBcancloud" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
				
					    case "12": CreateParticleSystem("KNBcancloud2" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
				
					    case "13": CreateParticleSystem("MMcancloud" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "14": CreateParticleSystem("MMcancloud2" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "15": CreateParticleSystem("MMcancloud_Light" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "16": CreateParticleSystem("MMcancloud2_Light" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "17": CreateParticleSystem("pearlfog" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "18": CreateParticleSystem("canfire" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "19": CreateParticleSystem("canfire2" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "20": CreateParticleSystem("cannon_embers" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "21": CreateParticleSystem("ball_impact_enhanced" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "22": CreateParticleSystem("splinters_enhanced" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "23": CreateParticleSystem("splinters2_enhanced" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
				
					    case "24": CreateParticleSystem("ball_impact" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "25": CreateParticleSystem("splinters" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "26": CreateParticleSystem("splinters2" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "27": CreateParticleSystem("splinters3" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "28": CreateParticleSystem("flyers" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "29": CreateParticleSystem("flyers2" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "30": CreateParticleSystem("blast_dirt" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "31": CreateParticleSystem("blast_dirt_small" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
				
					    case "32": CreateParticleSystem("blast_dirt_black" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "33": CreateParticleSystem("blast_dirt_gray" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
				
					    case "34": CreateParticleSystem("blast_newsmoke" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
				
					    case "35": CreateParticleSystem("blast" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "36": CreateParticleSystem("blast_inv" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "37": CreateParticleSystem("watersplash" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "38": CreateParticleSystem("whitewater" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "39": CreateParticleSystem("blast_smoke" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "40": CreateParticleSystem("waterfall" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "41": CreateParticleSystem("waterfall2" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
				
					    case "42": CreateParticleSystem("waterfall3" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
				
					    case "43": CreateParticleSystem("fountain" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "44": CreateParticleSystem("sparkle_cloud" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "45": CreateParticleSystem("sparkle_emitter" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "46": CreateParticleSystem("seafoam" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "47": CreateParticleSystem("seafoam2" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "48": CreateParticleSystem("seafoam_front" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "49": CreateParticleSystem("dutchman_submerge" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "50": CreateParticleSystem("dutchman_emerge" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "51": CreateParticleSystem("ball_splash" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
				
					    case "52": CreateParticleSystem("sink" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
				
					    case "53": CreateParticleSystem("gunfire" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "54": CreateParticleSystem("gunfire_small" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "55": CreateParticleSystem("bomb_smoke" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "56": CreateParticleSystem("candle" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "57": CreateParticleSystem("candle_mix" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "58": CreateParticleSystem("torch" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "59": CreateParticleSystem("fire_mix" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "60": CreateParticleSystem("waterfog" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "61": CreateParticleSystem("waterfog_short" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "62": CreateParticleSystem("waterfog_light" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "63": CreateParticleSystem("waterfog_yellow_light" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
				
					    case "64": CreateParticleSystem("waterfog_fall" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
			            case "65": CreateParticleSystem("gunfire_red" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "66": CreateParticleSystem("gunfire_revolver" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "67": CreateParticleSystem("gunfire_black" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "68": CreateParticleSystem("fireball" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "69": CreateParticleSystem("stars" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "70": CreateParticleSystem("stars_short" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "71": CreateParticleSystem("stars_fire" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
				
					    case "72": CreateParticleSystem("fort_smoke" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
				
					    case "73": CreateParticleSystem("fort_gray_smoke" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "74": CreateParticleSystem("fort_fire" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "75": CreateParticleSystem("ship_smoke" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "76": CreateParticleSystem("ship_fire" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "77": CreateParticleSystem("qar_fire" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "78": CreateParticleSystem("steamer_smoke" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "79": CreateParticleSystem("steamer_wake" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "80": CreateParticleSystem("steamer_smoke2" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "81": CreateParticleSystem("tentacle_appears" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "82": CreateParticleSystem("stern_light" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
	
					    case "83": CreateParticleSystem("shiplamp" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = sti(pchar.quest.effectnr) + 1; break;
				
					    case "84": CreateParticleSystem("artifact" , -66.6, 9.0, 48.7, 5.1, 4.0, 0.0, sti(20) );
							Logit("effectnr = " + pchar.quest.effectnr); pchar.quest.effectnr = "2"; break;
					}
			    }
			}
		break;

		case 7:	//JRH Boulder Test
			ChangeCharacterAddressGroup(characterFromID("boulder"), "boulder_tunnel", "reload", "reload3");
			DoQuestReloadToLocation("boulder_tunnel", "goto", "skel27" ,"_");

			pchar.quest.boulder_start.win_condition.l1 = "locator";
			pchar.quest.boulder_start.win_condition.l1.location = "boulder_tunnel";
			pchar.quest.boulder_start.win_condition.l1.locator_group = "goto";
			pchar.quest.boulder_start.win_condition.l1.locator = "goto3";
			pchar.quest.boulder_start.win_condition = "boulder_start";
		break;

		case 8:	// JRH Indian Weapons Test
			LAi_SetImmortal(pchar, true);
			Pchar.quest.JRH_rain = "Clear";
			SetNextWeather("Clear");
			DoQuestReloadToLocation("Labirint_1", "officers", "reload27_2" ,"maquahuitl_test");

		//	SetModel(PChar, "Mayan_warrior", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
		
		//	GiveItem2Character(Pchar, "halberd-1");
		//	EquipCharacterByItem(Pchar, "halberd-1");	
		//	GiveItem2Character(Pchar, "blade5");
		//	GiveItem2Character(Pchar, "blade1-2");	
		//	GiveItem2Character(Pchar, "pistol2");
		//	GiveItem2Character(Pchar, "pistol3-1");
		//	GiveItem2Character(Pchar, "shield_back");
		//	EquipCharacterByItem(Pchar, "shield_back");
		//	GiveItem2Character(Pchar, "blowgun");	
		//	EquipCharacterByItem(Pchar, "blowgun");
		//	TakenItems(Pchar, "bladearrows", 2);
		//	TakenItems(Pchar, "arrows2", 6);
		//	TakenItems(Pchar, "gunpowder", 12);
		//	TakenItems(Pchar, "pistolbullets", 12);
		//	TakenItems(Pchar, "medical1", -2);
		//	TakenItems(Pchar, "calabash", 12);
		//	TakenItems(Pchar, "herbs", 12);
		//	GiveItem2Character(Pchar, "pistolbow");
		//	GiveItem2Character(Pchar, "pistolmaquahuitl");
		//	EquipCharacterByItem(Pchar, "pistolmaquahuitl");
		
			GiveItem2Character(Pchar, "pistolrocket");
			EquipCharacterByItem(Pchar, "pistolrocket");

	
			ChangeCharacterAddressGroup(characterFromID("maquahuitl_enemy1"), "Labirint_1", "goto", "goto2");
			ChangeCharacterAddressGroup(characterFromID("maquahuitl_enemy2"), "Labirint_1", "goto", "goto3");
			ChangeCharacterAddressGroup(characterFromID("maquahuitl_enemy3"), "Labirint_1", "goto", "goto11");
		break;

		case 9:	//JRH Indian Medicals test
			Pchar.quest.JRH_rain = "Clear";
			SetNextWeather("Clear");
			Locations[FindLocation("Labirint_1")].models.always.locators = "lab1_l_test";

			DoQuestReloadToLocation("Labirint_1", "officers", "reload27_2" ,"maquahuitl_test");
			
			GiveItem2Character(Pchar, "potion1");
			GiveItem2Character(Pchar, "potion3");
			GiveItem2Character(Pchar, "sewing_kit");
			GiveItem2Character(Pchar, "tobacco");
			GiveItem2Character(Pchar, "medical2");
			GiveItem2Character(Pchar, "medical1");
		
			pchar.quest.antidote_test.win_condition.l1 = "locator";
			pchar.quest.antidote_test.win_condition.l1.location = "Labirint_1";
			pchar.quest.antidote_test.win_condition.l1.locator_group = "goto";
			pchar.quest.antidote_test.win_condition.l1.locator = "goto1";
			pchar.quest.antidote_test.win_condition = "antidote_test";
		break;

		case 10:	// JRH Indian Weapons Test outside in the dark
			LAi_SetImmortal(pchar, true);
			Pchar.quest.JRH_rain = "Clear";
			SetNextWeather("Clear");

			SetCurrentTime(2.00, 0);
			DoQuestReloadToLocation("Quest_FortVRight", "reload", "reload2" ,"maquahuitl_test");

		//	GiveItem2Character(Pchar, "halberd-1");
		//	EquipCharacterByItem(Pchar, "halberd-1");	
		//	GiveItem2Character(Pchar, "blade5");
		//	GiveItem2Character(Pchar, "blade1-2");	
		//	GiveItem2Character(Pchar, "pistol2");
		//	GiveItem2Character(Pchar, "pistol3-1");
		//	GiveItem2Character(Pchar, "shield_back");
		//	EquipCharacterByItem(Pchar, "shield_back");
		//	GiveItem2Character(Pchar, "blowgun");	
		//	EquipCharacterByItem(Pchar, "blowgun");
		//	TakenItems(Pchar, "bladearrows", 2);
		//	TakenItems(Pchar, "arrows2", 6);
		//	TakenItems(Pchar, "gunpowder", 12);
		//	TakenItems(Pchar, "pistolbullets", 12);
		//	TakenItems(Pchar, "medical1", -2);
		//	TakenItems(Pchar, "calabash", 12);
		//	TakenItems(Pchar, "herbs", 12);
		//	GiveItem2Character(Pchar, "pistolbow");
		//	GiveItem2Character(Pchar, "pistolmaquahuitl");
		//	EquipCharacterByItem(Pchar, "pistolmaquahuitl");

			GiveItem2Character(Pchar, "pistolrocket");
			EquipCharacterByItem(Pchar, "pistolrocket");
			GiveItem2Character(Pchar, "powderflask");
			EquipCharacterByItem(Pchar, "powderflask");
			GiveItem2Character(Pchar, "powderbarrel");
			TakenItems(Pchar, "gunpowder", 24);
			GiveItem2Character(Pchar, "rocket_bag");
			EquipCharacterByItem(Pchar, "rocket_bag");
			TakenItems(Pchar, "rockets", 8);

	
			ChangeCharacterAddressGroup(characterFromID("rocket_enemy1"), "Quest_FortVRight", "goto", "goto51");
			ChangeCharacterAddressGroup(characterFromID("rocket_enemy2"), "Quest_FortVRight", "patrol", "patrol41");
			ChangeCharacterAddressGroup(characterFromID("rocket_enemy3"), "Quest_FortVRight", "goto", "goto11");
		break;

		if (bAbordageStarted && !ownDeckStarted())
		{
			LAi_EnableReload();			// To fix being unable to proceed during boardings
		}
		if (!bSeaActive || bAbordageStarted)
		{
			LAi_SetPlayerType(pchar);	// If you end up stuck, unable to move
		}
	}
	LogIt("Executed Console");
}
