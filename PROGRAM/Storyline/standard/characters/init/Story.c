void CreateStoryCharacters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

	//Vincent Bethune - убийца, нанятый губернатором.
	ch.old.name = "Vincent";
	ch.old.lastname = "Bethune";
	ch.name = TranslateString("","Vincent");
	ch.lastname = LanguageConvertString("","Bethune");
	ch.id		= "Vincent Bethune";
	ch.model	= "killer";
	ch.sound_type = "pirate";
	ch.sex = "man";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	GiveItem2Character(ch, "bladeC33");
	ch.equip.blade = "bladeC33";
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "none";
	ch.Dialog.Filename = "Vincent Bethune_dialog.c";
	ch.greeting = "Gr_Vincent Bethune";
	ch.rank 	= 6;
	ch.reputation = "40";
	ch.experience = "240000";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "8";
	ch.money = "10";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	//Командующий английской эскадрой в архипелаге.
	ch.old.name = "Waulter";
	ch.old.lastname = "Tomlison";
	ch.name = TranslateString("","Waulter");
	ch.lastname = TranslateString("","Tomlison");
	ch.id		= "Waulter Tomlison";
	ch.nation	= ENGLAND;
	ch.model	= Nations[ENGLAND].fantomModel.m0; // PB
	ch.act.rebirth = 0;
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC12");
	ch.equip.blade = "bladeC12";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 1;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "10";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "10";
	ch.skill.Accuracy = "10";
	ch.skill.Cannons = "10";
	ch.skill.Grappling = "10";
	ch.skill.Repair = "10";
	ch.skill.Defence = "10";
	ch.skill.Commerce = "10";
	ch.skill.Sneak = "10";
	ch.money = QUEST_CHAR_MONEY; // PB
	ch.Ship.Name = "Vengeance";
//	ch.Ship.Type = "Battleship3"; // PRS3 // KK
	ch.Ship.Type = "Battleship4"; // GR - the AoP battleship is back!
	ch.Ship.Stopped = true;
	ch.nosurrender = 1;
	ch.skipRM = true; // PB: Skip Relations Mod
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS24;
	ch.FaceId = 31;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";
	ch.quest.killed.pirates = "0";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);


			//Капитаны Французских кораблей, захвативших Оксбэй (капитан батлшипа).
	ch.old.name = "Remy";
	ch.old.lastname = "Gatien";
	ch.name = TranslateString("","Remy");
	ch.lastname = TranslateString("","Gatien");
	ch.id		= "Remy Gatien";
	ch.nation	= FRANCE;
	ch.model	= "Shkiper";
	ch.act.rebirth = 0;
	ch.sex = "man";
// KK -->
	GiveItem2Character(ch, "bladeC33"); // was "blade4"
	ch.equip.blade = "bladeC33";
	GiveItem2Character(ch, "pistol5+1"); // didn't have any pistol
	ch.equip.gun = "pistol5+1";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
// <-- KK
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 8;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "4";
	ch.skill.Defence = "6";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = QUEST_CHAR_MONEY; // PB
	ch.nosurrender = 2; // TIH: wont give up easily
	ch.Ship.Name = "Belette";
	ch.Ship.Type = "HMS_Centurion"; // Armada
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.perks.list.BasicBattleState = true;
	ch.perks.list.AdvancedBattleState = true;
	ch.perks.list.ShipDefenceProfessional = true;
	ch.perks.list.StormProfessional = true;
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Капитаны Французских кораблей, захвативших Оксбэй (Капитан фрегата).
	ch.old.name = "Yves";
	ch.old.lastname = "Giner";
	ch.name = TranslateString("","Yves");
	ch.lastname = TranslateString("","Giner");
	ch.id		= "Yves Giner";
	ch.nation	= FRANCE;
	ch.model	= "Man3";
	ch.act.rebirth = 0;
	ch.sex = "man";
// KK -->
	GiveItem2Character(ch, "blade11"); // was "blade4"
	ch.equip.blade = "blade11";
	GiveItem2Character(ch, "pistol2"); // didn't have any pistol
	ch.equip.gun = "pistol2";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
// <-- KK
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 6;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "10";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "7";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "1";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = QUEST_CHAR_MONEY; // PB
	ch.nosurrender = 1; // TIH: wont give up easily
	ch.Ship.Name = "Clйopвtre";
	ch.Ship.Type = "FR_Frigate"; // Armada
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS24;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";
	ch.quest.killed.pirates = "0";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.perks.list.BasicBattleState = true;
	ch.perks.list.AdvancedBattleState = true;
	ch.perks.list.ShipDefenceProfessional = true;
	ch.perks.list.StormProfessional = true;
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Капитаны Французских кораблей, захвативших Оксбэй (капитан брига).
	ch.old.name = "Begon";
	ch.old.lastname = "Monchaty";
	ch.name = TranslateString("","Begon");
	ch.lastname = TranslateString("","Monchaty");
	ch.id		= "Begon Monchaty";
	ch.nation	= FRANCE;
	ch.model	= "man6";
	ch.act.rebirth = 0;
	ch.sex = "man";
// KK -->
	GiveItem2Character(ch, "blade6"); // was "blade4"
	ch.equip.blade = "blade6";
	GiveItem2Character(ch, "pistol2"); // didn't have any pistol
	ch.equip.gun = "pistol2";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
// <-- KK
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 5;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "6";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = QUEST_CHAR_MONEY; // PB
	ch.nosurrender = 1; // TIH: wont give up easily
	ch.Ship.Name = "Sйmillante";
	ch.Ship.Type = "RN_Corvette"; // Armada
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS16;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";
	ch.quest.killed.pirates = "0";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.perks.list.BasicBattleState = true;
	ch.perks.list.AdvancedBattleState = true;
	ch.perks.list.ShipDefenceProfessional = true;
	ch.perks.list.StormProfessional = true;
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// KK -->
			// Replacement for Belette.
	ch.old.name = "Isaac";
	ch.old.lastname = "Razilly";
	ch.name = TranslateString("","Isaac");
	ch.lastname = TranslateString("","Razilly");
	ch.id		= "Isaac Razilly";
	ch.nation	= FRANCE;
	ch.model	= "Shkiper";
	ch.act.rebirth = 0;
	ch.sex = "man";
// KK -->
	GiveItem2Character(ch, "bladeC12");
	ch.equip.blade = "bladeC12";
	GiveItem2Character(ch, "pistol5");
	ch.equip.gun = "pistol5";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
// <-- KK
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 8;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "4";
	ch.skill.Defence = "6";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = QUEST_CHAR_MONEY; // PB
	ch.nosurrender = 1; // TIH: wont give up easily
	ch.Ship.Name = "Soleil Royal";
	ch.Ship.Type = "FR_SoleilRoyal"; // PRS3
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.perks.list.BasicBattleState = true;
	ch.perks.list.AdvancedBattleState = true;
	ch.perks.list.ShipDefenceProfessional = true;
	ch.perks.list.StormProfessional = true;
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// Replacement for Cleopatre.
	ch.old.name = "Jacques";
	ch.old.lastname = "Belmondo";
	ch.name = TranslateString("","Jacques");
	ch.lastname = TranslateString("","Belmondo");
	ch.id		= "Jacques Belmondo";
	ch.nation	= FRANCE;
	ch.model	= "Man3";
	ch.act.rebirth = 0;
	ch.sex = "man";
// KK -->
	GiveItem2Character(ch, "blade20+2");
	ch.equip.blade = "blade20+2";
	GiveItem2Character(ch, "pistol5");
	ch.equip.gun = "pistol5";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
// <-- KK
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 6;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "10";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "7";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "1";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = QUEST_CHAR_MONEY; // PB
	ch.nosurrender = 1; // TIH: wont give up easily
	ch.Ship.Name = "Arsinoe";
	ch.Ship.Type = "FR_WarGalleon"; // Thomas the Terror
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS24;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";
	ch.quest.killed.pirates = "0";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.perks.list.BasicBattleState = true;
	ch.perks.list.AdvancedBattleState = true;
	ch.perks.list.ShipDefenceProfessional = true;
	ch.perks.list.StormProfessional = true;
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// Replacement for Semillante.
	ch.old.name = "Pierre";
	ch.old.lastname = "Leverrier";
	ch.name = TranslateString("","Pierre");
	ch.lastname = TranslateString("","Leverrier");
	ch.id		= "Pierre Leverrier";
	ch.nation	= FRANCE;
	ch.model	= "man6";
	ch.act.rebirth = 0;
	ch.sex = "man";
// KK -->
	GiveItem2Character(ch, "blade19");
	ch.equip.blade = "blade19";
	GiveItem2Character(ch, "pistol5");
	ch.equip.gun = "pistol5";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
// <-- KK
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 5;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "6";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "5";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = QUEST_CHAR_MONEY; // PB
	ch.nosurrender = 1; // TIH: wont give up easily
	ch.Ship.Name = "l'Entreprise";
	ch.Ship.Type = "FR_Derfflinger";
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS16;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";
	ch.quest.killed.pirates = "0";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.perks.list.BasicBattleState = true;
	ch.perks.list.AdvancedBattleState = true;
	ch.perks.list.ShipDefenceProfessional = true;
	ch.perks.list.StormProfessional = true;
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
// <-- KK

			//Капитаны Французских кораблей, захвативших Оксбэй (капитан шхуны).
	ch.old.name = "Abelard";
	ch.old.lastname = "Tarnaud";
	ch.name = TranslateString("","Abelard");
	ch.lastname = TranslateString("","Tarnaud");
	ch.id		= "Abelard Tarnaud";
	ch.nation	= FRANCE;
	ch.model	= "Corsair1";
	ch.act.rebirth = 0;
	ch.sex = "man";
	GiveItem2Character(ch, "blade6");
	ch.equip.blade = "blade6";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 5;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "6";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = QUEST_CHAR_MONEY; // PB
	ch.Ship.Name = "Alouette";
	ch.Ship.Type = "Schooner1"; // PRS3
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS12;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";
	ch.quest.killed.pirates = "0";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.perks.list.BasicBattleState = true;
	ch.perks.list.AdvancedBattleState = true;
	ch.perks.list.ShipDefenceProfessional = true;
	ch.perks.list.StormProfessional = true;
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);


			//Капитаны Французских кораблей, захвативших Оксбэй (капитан шлюпа).
	ch.old.name = "Wigayn";
	ch.old.lastname = "Ratel";
	ch.name = TranslateString("","Wigayn");
	ch.lastname = TranslateString("","Ratel");
	ch.id		= "Wigayn Ratel";
	ch.nation	= FRANCE;
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.act.rebirth = 0;
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 4;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = QUEST_CHAR_MONEY; // PB
	ch.Ship.Name = "Friponne";
	ch.Ship.Type = "Lugger1"; // PRS3
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS12;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";
	ch.quest.killed.pirates = "0";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.perks.list.BasicBattleState = true;
	ch.perks.list.AdvancedBattleState = true;
	ch.perks.list.ShipDefenceProfessional = true;
	ch.perks.list.StormProfessional = true;
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				//Рауль Реймс
	ch.old.name = "Raoul";
	ch.old.lastname = "Rheims";
	ch.name = TranslateString("","Raoul");
	ch.lastname = TranslateString("","Rheims");
	ch.id		= "Raoul Rheims";
	ch.model	= "50_Raoul"; // was "man3"
	ch.sound_type = "male_citizen";
	ch.sex = "man";
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Raoul Rheims_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Raoul Rheims";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);


				//Валентин Массони - офицер, которого Блэйз спаивает для получения сведений о французской эскадре
	ch.old.name = "Valentin";
	ch.old.lastname = "Massoni";
	ch.name = TranslateString("","Valentin");
	ch.lastname = TranslateString("","Massoni");
	ch.id		= "Valentin Massoni";
	ch.nation	= FRANCE;
	ch.model	= Nations[FRANCE].fantomModel.m0; // PB
	ch.sound_type = "soldier";
	ch.activity_begin = "0";
	ch.activity_end = "24";
	ch.sex = "man";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Valentin Massoni_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "2";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.ship.name = "Aurora";
	ch.money = "10";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Valentin Massoni";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				//Эмиль Беранжере, капитан брига, который должен сопровождать барк "Ойсу" на Оксбэй
	ch.old.name = "Amiel";
	ch.old.lastname = "Berangere";
	ch.name = TranslateString("","Amiel");
	ch.lastname = TranslateString("","Berangere");
	ch.id		= "Amiel Berangere";
	ch.nation	= FRANCE;
	ch.model	= "Corsair2";
	ch.sound_type = "pirate";
	ch.act.rebirth = 0;
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Amiel Berangere_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Amiel Berangere";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				//Фауст Гаске - матрос с барка "Ойсу". Ждет Блэйза в порту, чтобы начать с ним разговор.
	ch.old.name = "Faust";
	ch.old.lastname = "Gasquet";
	ch.name = TranslateString("","Faust");
	ch.lastname = TranslateString("","Gasquet");
	ch.id		= "Faust Gasquet";
	ch.nation	= FRANCE;
	ch.model	= "fisherman";
	ch.sound_type = "seaman";
	ch.sex = "man";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Faust Gasquet_dialog.c";
	ch.greeting = "Gr_Faust Gasquet";
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//капитан барка Oiseau
	ch.old.name = "Virgile";
	ch.old.lastname = "Boon";
	ch.name = TranslateString("","Virgile");
	ch.lastname = TranslateString("","Boon");
	ch.id		= "Virgile Boon";
	ch.nation	= FRANCE;
	ch.model	= "corsair1";
	ch.sound_type = "pirate";
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC33");
	ch.equip.blade = "bladeC33";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.nosurrender = true;
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Virgile Boon_dialog.c";
	ch.greeting = "Gr_Virgile Boon";
	ch.rank 	= 4;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = QUEST_CHAR_MONEY; // PB
	ch.quest.guard_protection = true; // PB
	ch.Ship.Name = "Oiseau";
	ch.Ship.Type = "Barque1"; // PRS3
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS12;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";
	ch.quest.killed.pirates = "0";
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			// Агент перевозимый Дэниель в захваченный Оксбэй
	ch.old.name = "Tobias";
	ch.old.lastname = "";
	ch.name = TranslateString("","Tobias");
	ch.lastname = "";
	ch.id		= "Counterspy";
	ch.model	= Nations[FRANCE].fantomModel.m0; // PB
	ch.sound_type = "soldier";
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Counterspy_dialog.c";
	ch.greeting = "Gr_Counterspy";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "0";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "5";
	ch.skill.Sneak = "7";
	ch.money = "10";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//капитан шлюпа Albion
	ch.old.name = "Ewan";
	ch.old.lastname = "Glover";
	ch.name = TranslateString("","Ewan");
	ch.lastname = TranslateString("","Glover");
	ch.id		= "Ewan Glover";
	ch.nation	= ENGLAND;
	ch.sound_type = "seaman";
	ch.model	= "Will_2";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Ewan Glover_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "9";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = QUEST_CHAR_MONEY; // PB
	ch.Ship.Name = "Albion";
	ch.Ship.Type = "BrigRoyal"; // PRS3
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS12;
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Ewan Glover";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//местный житель, который должен провести игрока к пещере на Оксбэе.
	ch.old.name = "Wilfred";
	ch.old.lastname = "";
	ch.name = TranslateString("","Wilfred");
	ch.lastname = "";
	ch.id		= "Wilfred";
	ch.nation	= ENGLAND;
	ch.model	= "brodyaga";
	ch.sound_type = "male_citizen";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Wilfred_dialog.c";
	ch.greeting = "Gr_Wilfred";
	ch.rank 	= 4;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "0";
	ch.skill.Sneak = "1";
	ch.money = QUEST_CHAR_MONEY; // PB
	LAi_SetActorType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);

			//Английские солдаты, высадившиеся на Оксбэе вместе с Блэйзом
	ch.old.name = "English Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","English Soldier");
	ch.lastname = "";
	ch.id		= "Eng_land_soldier_01";
	ch.model	= Nations[ENGLAND].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "Story_EngLandSoldier_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Английские солдаты, высадившиеся на Оксбэе вместе с Блэйзом
	ch.old.name = "English Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","English Soldier");
	ch.lastname = "";
	ch.id		= "Eng_land_soldier_02";
	ch.model	= Nations[ENGLAND].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "Story_EngLandSoldier_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Английские солдаты, высадившиеся на Оксбэе вместе с Блэйзом
	ch.old.name = "English Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","English Soldier");
	ch.lastname = "";
	ch.id		= "Eng_land_soldier_03";
	ch.model	= Nations[ENGLAND].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "Story_EngLandSoldier_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Английские солдаты, высадившиеся на Оксбэе вместе с Блэйзом
	ch.old.name = "English Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","English Soldier");
	ch.lastname = "";
	ch.id		= "Eng_land_soldier_04";
	ch.model	= Nations[ENGLAND].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "Story_EngLandSoldier_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Английские солдаты, высадившиеся на Оксбэе вместе с Блэйзом
	ch.old.name = "English Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","English Soldier");
	ch.lastname = "";
	ch.id		= "Eng_land_soldier_05";
	ch.model	= Nations[ENGLAND].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "Story_EngLandSoldier_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Английские солдаты, высадившиеся на Оксбэе вместе с Блэйзом
	ch.old.name = "English Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","English Soldier");
	ch.lastname = "";
	ch.id		= "Eng_land_soldier_06";
	ch.model	= Nations[ENGLAND].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "Story_EngLandSoldier_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, LAI_GROUP_PLAYER);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);


			//Французский патруль, нападающий на игрока на месте высадки
	ch.old.name = "French Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","French Soldier");
	ch.lastname = "";
	ch.id		= "Fra_patrolman_01";
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Французский патруль, нападающий на игрока на месте высадки
	ch.old.name = "French Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","French Soldier");
	ch.lastname = "";
	ch.id		= "Fra_patrolman_02";
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Французский патруль, нападающий на игрока на месте высадки
	ch.old.name = "French Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","French Soldier");
	ch.lastname = "";
	ch.id		= "Fra_patrolman_03";
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Французский патруль, нападающий на игрока на месте высадки
	ch.old.name = "French Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","French Soldier");
	ch.lastname = "";
	ch.id		= "Fra_patrolman_04";
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Французский патруль, нападающий на игрока на месте высадки
	ch.old.name = "French Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","French Soldier");
	ch.lastname = "";
	ch.id		= "Fra_patrolman_05";
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Французский патруль, нападающий на игрока на месте высадки
	ch.old.name = "French Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","French Soldier");
	ch.lastname = "";
	ch.id		= "Fra_patrolman_06";
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);


			//Солдаты, пытающиеся арестовать игрока и шпиона
	ch.old.name = "French Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","French Soldier");
	ch.lastname = "";
	ch.id		= "Fra_arrester_01";
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "French_Arrester_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 40.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_French_arrester";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Солдаты, пытающиеся арестовать игрока и шпиона
	ch.old.name = "French Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","French Soldier");
	ch.lastname = "";
	ch.id		= "Fra_arrester_02";
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "French_Arrester_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 40.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_French_arrester";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Солдаты, пытающиеся арестовать игрока и шпиона
	ch.old.name = "French Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","French Soldier");
	ch.lastname = "";
	ch.id		= "Fra_arrester_03";
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "French_Arrester_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 40.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_French_arrester";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Вторая группа солдат, зашедшая в верфь.
	ch.old.name = "French Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","French Soldier");
	ch.lastname = "";
	ch.id		= "Fra_arrester_04";
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "French_Arrester_2_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_French_arrester_2";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Вторая группа солдат, зашедшая в верфь.
	ch.old.name = "French Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","French Soldier");
	ch.lastname = "";
	ch.id		= "Fra_arrester_05";
	ch.model	= Nations[FRANCE].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "French_Arrester_2_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_French_arrester_2";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);


			//Вторая группа солдат, зашедшая в верфь.
	ch.old.name = "French Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","French Soldier");
	ch.lastname = "";
	ch.id		= "Fra_arrester_06";
	ch.model	= Nations[FRANCE].fantomModel.m2; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "French_Arrester_2_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetPatrolType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_French_arrester_2";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Французский офицер, готовый продать свой корабль.
	ch.old.name = "Rabel";
	ch.old.lastname = "Yverneau";
	ch.name = TranslateString("","Rabel");
	ch.lastname = TranslateString("","Yverneau");
	ch.id		= "Rabel Iverneau";
	ch.model	= Nations[FRANCE].fantomModel.m0; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC12");
	ch.equip.blade = "bladeC12";
	ch.Dialog.Filename = "Rabel Yverneau_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.Ship.Name = "La Boussole"; // Seb
	ch.Ship.Type = "FR_Boussole"; // Seb
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS12;
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Rabel Yverneau";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//персонаж для временного хранения корабля.
	ch.old.name = "";
	ch.old.lastname = "";
	ch.name = "";
	ch.lastname = "";
	ch.id		= "Ship Storage";
	ch.model	= "";
	ch.sex = "man";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.Dialog.Filename = "";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.Ship.Name = "";
	ch.Ship.Type = "Tartane1"; // PS - SHIP_TARTANE;
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_NONECANNON;

	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				//Anacleto Rui Sa Pinto
	ch.old.name = "Anacleto";
	ch.old.middlename 	= "Rui Sa";
	ch.old.lastname = "Pinto";
	ch.name = TranslateString("","Anacleto");
	ch.middlename 	= TranslateString("","Rui Sa");
	ch.lastname = TranslateString("","Pinto");
	ch.id		= "Anacleto Rui Sa Pinto";
	ch.model	= "old_man1";
	ch.sound_type = "pirate";
	ch.nation = SPAIN;
	ch.sex = "man";
	GiveItem2Character(ch, "pistol1");
	ch.equip.gun = "pistol1";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	GiveItem2Character(ch, "blade10");
	ch.equip.blade = "blade10";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "sit";
	ch.location.locator = "sit4";
	ch.Dialog.Filename = "Anacleto Rui Sa Pinto_dialog.c";
	ch.rank 	= 6;
	ch.reputation = "40";
	ch.experience = "240000";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "8";
	ch.money = "10";
	ch.Ship.Name = "Amorale";
	ch.Ship.Type = "Pinnace2"; // PRS3
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS12;
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Anacleto Rui Sa Pinto";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Недруг того пирата, что отдал Блэйзу шебеку
	ch.old.name = "Sidonio";
	ch.old.lastname = "Ogarrio";
	ch.name = TranslateString("","Sidonio");
	ch.lastname = TranslateString("","Ogarrio");
	ch.id		= "Sidonio Ogarrio";
	ch.model	= "Storeman";
	ch.sex = "man";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.sound_type = "pirate";
	ch.location	= "Sidonio Ogarrio House";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.Dialog.Filename = "Sidonio Ogarrio_dialog.c";
	ch.greeting = "Gr_Sidonio Ogarrio";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetmerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Солдат, дежурящий на маяке после ареста изобретателя.
	ch.old.name = "English Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","English Soldier");
	ch.lastname = "";
	ch.id		= "Lighthouse_guard_01";
	ch.model	= Nations[ENGLAND].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.Dialog.Filename = "Researcher_captured_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "LIGHTHOUSE_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Researcher_Captured";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Солдат, дежурящий на маяке после ареста изобретателя.
	ch.old.name = "English Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","English Soldier");
	ch.lastname = "";
	ch.id		= "Lighthouse_guard_02";
	ch.model	= Nations[ENGLAND].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.Dialog.Filename = "Researcher_captured_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "LIGHTHOUSE_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Researcher_Captured";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Солдат, дежурящий на маяке после ареста изобретателя.
	ch.old.name = "English Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","English Soldier");
	ch.lastname = "";
	ch.id		= "Lighthouse_guard_03";
	ch.model	= Nations[ENGLAND].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "Researcher_captured_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "LIGHTHOUSE_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Researcher_Captured";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Солдат, дежурящий на маяке после ареста изобретателя.
	ch.old.name = "English Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("","English Soldier");
	ch.lastname = "";
	ch.id		= "Lighthouse_guard_04";
	ch.model	= Nations[ENGLAND].fantomModel.m1; // PB
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.Dialog.Filename = "Researcher_captured_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "LIGHTHOUSE_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Researcher_Captured";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Солдат, дежурящий на маяке после ареста изобретателя.
	ch.old.name = "Lieutenant";
	ch.old.lastname = "Harris";
	ch.name = TranslateString("","Lieutenant");
	ch.lastname = TranslateString("","Harris");
	ch.id		= "Lighthouse_officer";
	ch.model	= Nations[ENGLAND].fantomModel.m0; // PB
	ch.nation = ENGLAND;
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.Dialog.CurrentNode = "Talk_With_Blaze";
	ch.Dialog.Filename = "Researcher_captured_dialog.c";
	ch.nation = ENGLAND;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "9";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetGuardianType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "LIGHTHOUSE_SOLDIERS");
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Researcher_Captured";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Капитаны Английской эскадры, штурмующей Гринфорд
	ch.old.name = "Malcolm";
	ch.old.lastname = "Hart";
	ch.name = TranslateString("","Malcolm");
	ch.lastname = TranslateString("","Hart");
	ch.id		= "Malcolm Hart";
	ch.nation	= ENGLAND;
	ch.model	= Nations[ENGLAND].fantomModel.m0; // PB
	ch.sex = "man";
	GiveItem2Character(ch, "blade19");
	ch.equip.blade = "blade19";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 8;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "4";
	ch.skill.Defence = "6";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = QUEST_CHAR_MONEY; // PB
	ch.Ship.Name = "Desperate";
	ch.Ship.Type = "RN_Battleship"; // Thomas the Terror
	ch.Ship.Stopped = true;
	ch.nosurrender = 1;
	ch.skipRM = true; // PB: Skip Relations Mod
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Капитаны Английской эскадры, штурмующей Гринфорд
	ch.old.name = "Henry";
	ch.old.lastname = "Banfield";
	ch.name = TranslateString("","Henry");
	ch.lastname = TranslateString("","Banfield");
	ch.id		= "Henry Banfield";
	ch.nation	= ENGLAND;
	ch.model	= Nations[ENGLAND].fantomModel.m0; // PB
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC33");
	ch.equip.blade = "bladeC33";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 8;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "4";
	ch.skill.Defence = "6";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = QUEST_CHAR_MONEY; // PB
	ch.Ship.Name = "Monarch";
//	ch.Ship.Type = "RN_Essex"; // Thomas the Terror
	ch.Ship.Type = "RN_Battleship"; // GR: "RN_Essex" belongs to "Napoleonic" period, so "Monarch" is another basic battleship
	ch.Ship.Stopped = true;
	ch.nosurrender = 1;
	ch.skipRM = true; // PB: Skip Relations Mod
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Капитаны Английской эскадры, штурмующей Гринфорд
	ch.old.name = "Wauter";
	ch.old.lastname = "Keech";
	ch.name = TranslateString("","Wauter");
	ch.lastname = TranslateString("","Keech");
	ch.id		= "Wauter Keech";
	ch.nation	= ENGLAND;
	ch.model	= Nations[ENGLAND].fantomModel.m0; // PB
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC12");
	ch.equip.blade = "bladeC12";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 8;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "4";
	ch.skill.Defence = "6";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = QUEST_CHAR_MONEY; // PB
	ch.Ship.Name = "Black Prince";
	ch.Ship.Type = "RN_Corvette"; // Thomas the Terror
	ch.skipRM = true; // PB: Skip Relations Mod
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS24;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);


			//Капитаны Английской эскадры, штурмующей Гринфорд
	ch.old.name = "Lewellyn";
	ch.old.lastname = "Belt";
	ch.name = TranslateString("","Lewellyn");
	ch.lastname = TranslateString("","Belt");
	ch.id		= "Lewellyn Belt";
	ch.nation	= ENGLAND;
	ch.model	= Nations[ENGLAND].fantomModel.m0; // PB
	ch.sex = "man";
	GiveItem2Character(ch, "bladeC6");
	ch.equip.blade = "bladeC6";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 8;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "4";
	ch.skill.Defence = "6";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = QUEST_CHAR_MONEY; // PB
	ch.Ship.Name = "Meleager";
//	ch.Ship.Type = "RN_Essex"; // Thomas the Terror
	ch.Ship.Type = "Frigate1"; // "RN_Essex" belongs to "Napoleonic" period, so use a "Kreyser" class instead
	ch.Ship.Stopped = true;
	ch.skipRM = true; // PB: Skip Relations Mod
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS24;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Пираты, перехватывающие игрока у Каэль Роа.
	ch.old.name = "Thomas";
	ch.old.lastname = "Norton";
	ch.name = TranslateString("","Thomas");
	ch.lastname = TranslateString("","Norton");
	ch.id		= "Thomas Norton";
	ch.nation	= ENGLAND;
	ch.model	= "korsar";
	ch.sex = "man";
	GiveItem2Character(ch, "blade11");
	ch.equip.blade = "blade11";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 8;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "10";
	ch.skill.Fencing = "9";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "10";
	ch.skill.Repair = "4";
	ch.skill.Defence = "6";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = QUEST_CHAR_MONEY; // PB
	ch.Ship.Name = "Tremendous";
//	ch.Ship.Type = "RN_Brig"; // Thomas the Terror
	ch.Ship.Type = "BrigSW1"; // GR: all the other pirates now have piratey ships so give this guy the scary pirate brig
	ch.Ship.Stopped = true;
	ch.skipRM = true; // PB: Skip Relations Mod
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);

			//Пираты, перехватывающие игрока у Каэль Роа.
	ch.old.name = "Brian";
	ch.old.lastname = "The Slayer";
	ch.name = TranslateString("","Brian");
	ch.lastname = TranslateString("","The Slayer");
	ch.id		= "Brian The Slayer";
	ch.nation	= PIRATE;
	ch.model	= "Man3";
	ch.sex = "man";
	GiveItem2Character(ch, "blade10");
	ch.equip.blade = "blade10";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = " ";
	ch.rank 	= 8;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "10";
	ch.skill.Fencing = "9";
	ch.skill.Sailing = "8";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "8";
	ch.skill.Repair = "4";
	ch.skill.Defence = "6";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = QUEST_CHAR_MONEY; // PB
	ch.Ship.Name = "Bato";
//	ch.Ship.Type = "FastGalleon2"; // KK
	ch.Ship.Type = "CrimsonBlood"; // GR - "FastGalleon2" should not exist in this time period, use pirate version of corvette instead
	ch.Ship.Stopped = true;
	ch.skipRM = true; // PB: Skip Relations Mod
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS24;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				//Ferro Cerezo
	ch.old.name = "Ferro";
	ch.old.lastname = "Cerezo";
	ch.name = TranslateString("","Ferro");
	ch.lastname = TranslateString("","Cerezo");
	ch.id		= "Ferro Cerezo";
	ch.model	= "man3";
	ch.sound_type = "seaman";
	ch.sex = "man";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "none";
	ch.location.group = "goto";
	ch.location.locator = "goto6";
	ch.Dialog.Filename = "Ferro Cerezo_dialog.c";
	ch.Ship.Name = "Demetra";
	ch.Ship.Type = "Pinnace2"; // PRS3
	ch.Ship.Stopped = true;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS16;
	ch.rank 	= 1;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "4";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Ferro Cerezo";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

			//Barbossa.
	ch.old.name = "Hector";//MAXIMUS: we know his name now ;)
	ch.old.lastname = "Barbossa";
	ch.name = TranslateString("","Hector");//MAXIMUS: we know his name now ;)
	ch.lastname = TranslateString("","Barbossa");
	ch.id		= "Barbossa";
	ch.nation	= PIRATE;
	ch.model	= "Barbossa"; // SCM
	ch.sex = "man";
	GiveItem2Character(ch, "blade34");
	ch.equip.blade = "blade34";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "";
	ch.rank 	= 20;
	ch.reputation = "1";
	ch.experience = "0";
	ch.skill.Leadership = "10";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "10";
	ch.skill.Accuracy = "10";
	ch.skill.Cannons = "10";
	ch.skill.Grappling = "10";
	ch.skill.Repair = "10";
	ch.skill.Defence = "10";
	ch.skill.Commerce = "10";
	ch.skill.Sneak = "10";
	ch.money = QUEST_CHAR_MONEY; // PB
	ch.sinktenpercent = false;
	ch.Ship.Name = "Black Pearl";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.Flags.Pirate = 0; // PB: Jack Rackham Pirate Flag
	ch.Flags.Pirate.texture = 0;
	ch.Flags.Personal = 2;
	ch.Flags.Personal.texture = 0;
	ch.Ship.Type = SHIP_CURSED; // Kazeite
	ch.Ship.Stopped = true;
	ch.skipRM = true; // PB: Skip Relations Mod
	ch.nosurrender = 3; // KK
	ch.boardingmodels = "Skeletons";
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS32;
	ch.FaceId = 31;
	ch.ShipSlot1.Type=SHIP_NOTUSED;
	ch.ShipSlot1.Name="NoName";
	ch.ShipSlot2.Type=SHIP_NOTUSED;
	ch.ShipSlot2.Name="NoName";
	ch.ShipSlot3.Type=SHIP_NOTUSED;
	ch.ShipSlot3.Name="NoName";
	ch.quest.killed.pirates = "0";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	Lai_SetImmortal(ch, true);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	//Robert Christopher Silehard
	ch.old.name = "Robert";
	ch.old.middlename = "Christopher";
	ch.old.lastname = "Silehard";
	ch.name = TranslateString("","Robert");
	ch.middlename = TranslateString("","Christopher");
	ch.lastname = TranslateString("","Silehard");
	ch.id		= "Robert Christopher Silehard";
	ch.model	= "huber_eng";
	ch.sex = "man";
	ch.nation = ENGLAND;
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Robert Christopher Silehard_dialog.c";
	ch.Dialog.Filename.GroupDialog = "governor.c"; // GR
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "10";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "0";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "10";
	ch.skill.Sneak = "0";
	ch.Ship.Name = "Sovereign of the Seas";
	ch.Ship.Type = "Manowar1";
	ch.Ship.Stopped = true;
	ch.skipRM = true; // PB: Skip Relations Mod
	ch.nosurrender = -1;
	// KNB ch.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS24;
	ch.money = QUEST_CHAR_MONEY; // PB
	LAi_SetHuberStayType(ch);
	LAi_SetStayHuberPointWindow(ch, "goto", "goto10");
	LAi_SetStayHuberPointMap(ch, "goto", "goto9");
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.greeting = "Gr_Robert Christopher Silehard";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
}
