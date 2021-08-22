// NK Characters
// First in Build 10.0
void CreateNKCharacters(ref n)
{	
	object chobj;
	ref ch;
	int i;

	makeref(ch, chobj);

	// These folks are never used, so let's not take up the space. 05-07-17
	/*for(i = 0; i < 10; i++) // create port ship chars
	{
		ch.old.name = "First";
		ch.old.lastname = "Last";
		ch.name 	= "First";
		ch.lastname 	= "Last";
		ch.id		= "PortShipsChar"+i;
		ch.model	= "storeman2"; 
		ch.sex = "man";
		ch.location = "none";
		ch.location.group = "goto";
		ch.location.locator = "none";
		ch.dialog.filename = "";
		ch.nation = ENGLAND;
		ch.rank 	= 1;
		ch.reputation = "None";
		ch.experience = "0";
		LAi_SetActorType(ch);
		
		AddGameCharacter(n, ch);
	}*/

	for(i = 0; i < TOWNS_QUANTITY; i++) // create governors' neices/daughters // KK
	{
		ch.old.name = "First";
		ch.old.lastname = "Last";
		ch.name 	= "First";
		ch.lastname 	= "Last";
		ch.id		= "GovRel"+i;
		ch.model = "towngirl1";
		ch.sex = "woman";
		ch.sound_type = "female_citizen";
		ch.talkpoints = 0; // RM
		ch.married = 0; // RM
		ch.pcounter = 1; // RM
		ch.location	= "none";
		ch.location.group = "goto";
		ch.location.locator = "none";
		ch.Dialog.Filename = "Gov MR_dialog.c";
		ch.rank 	= 1;
		ch.reputation = "60";
		ch.experience = "0";
		ch.skill.Leadership = "1";
		ch.skill.Fencing = "1";
		ch.skill.Sailing = "1";
		ch.skill.Accuracy = "1";
		ch.skill.Cannons = "1";
		ch.skill.Grappling = "1";
		ch.skill.Repair = "1";
		ch.skill.Defence = "1";
		ch.skill.Commerce = "3";
		ch.skill.Sneak = "1";
		ch.money = "500";
		ch.quest.meeting = "0";
		LAi_SetCitizenType(ch); //LAi_SetStayType(ch);
		LAi_SetLoginTime(ch, 3.0, 23.0);
		LAi_SetHP(ch, 40.0, 40.0);
		//ch.greeting = "Gr_Arabella Silehard";
		AddGameCharacter(n, ch);
	}

// ccc CR ->
	string islandstr;
	int j;

// KK -->
	for(i = 0; i < ISLANDS_QUANTITY; i++) // create coastraiders, select island 7 to 14 by screwface
	{
		if (CheckAttribute(Islands[i], "skipCR") == true && sti(Islands[i].skipCR) == true) continue;
		islandstr = Islands[i].id;
		/*switch(i)
		{
			case 0: islandstr ="Conceicao"; break;
			case 1: islandstr ="Douwesen"; break;
			case 2: islandstr ="FalaiseDeFleur"; break;
			case 3: islandstr ="IslaMuelle"; break;
			case 4: islandstr ="Oxbay"; break;
			case 5: islandstr ="Redmond"; break;
			case 6: islandstr ="QuebradasCostillas"; break;
			// screwface -->
			case 7: islandstr ="Hispaniola"; break;
			case 8: islandstr ="Cuba"; break;
			case 9: islandstr ="Guadeloupe"; break;
			case 10: islandstr ="SaintMartin"; break;
			case 11: islandstr ="Cayman"; break;
			case 12: islandstr ="Turks"; break;
			case 13: islandstr ="Antigua"; break;
			// screwface <--
		}*/

		for(j = 1; j < 7; j++)	// create 6 chr for each island
		{
			if(GetCharacterIndex("Cr"+islandstr + j) != -1) break;

			ch.old.name = "";
			ch.old.lastname = "";
			ch.name 	= "";
			ch.lastname = "";
			ch.id = "Cr"+islandstr + j;
			ch.model = "man" + j;
			ch.sex = "man";
			GiveItem2Character(ch, "blade4");
			ch.equip.blade = "blade4";
			ch.location	= "None";
			ch.location.group = "";
			ch.location.locator = "";
			ch.Dialog.Filename = "";
			ch.reputation = "50";
			ch.experience = 0;
			ch.Ship.Stopped = false;
			LAi_SetGuardianType(ch);
			LAi_SetLoginTime(ch, 0.0, 24.0);
			LAi_SetHP(ch, 80.0, 80.0);
			AddGameCharacter(n, ch);
		}
	}
	// ccc CR <-
// <-- KK

	// ccc Building Kit treasure keeper
	ch.old.name = "Ye Keeper";
	ch.old.lastname = "o' ye Hoarde";
	ch.name 	= TranslateString("","Ye Keeper");
	ch.lastname 	= TranslateString("","o' ye Hoarde");
	ch.id		= "B_keeper";
	ch.model	= "admiral";
	ch.sex = "man";
	ch.act.type = "citizen";
	ch.location = "none";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.dialog.filename = "B_hoardkeeper.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "9";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "6";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "7";
	ch.skill.Sneak = "8";
	ch.money = "10";
	LAi_SetStayType(ch);
	LAi_SetHP(ch, 200.0, 200.0);
	AddGameCharacter(n, ch);
}
