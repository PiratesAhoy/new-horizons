void CreateQuebradasCostillasCharacters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

//JRH -->
				//MISTRESS
	ch.old.name = "Celestine";
	ch.old.lastname = "Maupassant";
	ch.name = TranslateString("","Celestine");
	ch.lastname = TranslateString("","Maupassant");
	ch.id		= "Mistress";
//	ch.model	= "Liza";
	ch.model	= "girlpatch";
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
	ch.location	= "QC_brothel";
	ch.location.group = "goto";
	ch.location.locator = "goto6";
	ch.Dialog.Filename = "mistress_JRH_dialog.c";
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
//	LAi_SetWaitressType(ch);
	LAi_SetOfficerType(ch);			//JRH so sheґs following you
	LAi_SetLoginTime(ch, 0.0, 24.0);	//JRH
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.questchar = true;
	AddGameCharacter(n, ch);

			// WENCH 1
	ch.old.name = "Natalia";
	ch.old.lastname = "Decoteau";
	ch.name = TranslateString("","Natalia");
	ch.lastname = TranslateString("","Decoteau");
	ch.id		= "wench1";
//	ch.model	= "towngirl2";
	ch.model	= "w1_Natalia";
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
	ch.location	= "QC_brothel";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.Dialog.Filename = "wench_dialog.c";
	ch.nation = PIRATE;
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
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.questchar = true;
	AddGameCharacter(n, ch);

			// WENCH 2
	ch.old.name = "Serena";
	ch.old.lastname = "Tisserand";
	ch.name = TranslateString("","Serena");
	ch.lastname = TranslateString("","Tisserand");
	ch.id		= "wench2";
//	ch.model	= "towngirl6";
	ch.model	= "w2_Serena";
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
	ch.location	= "QC_brothel";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "wench_dialog.c";
	ch.nation = PIRATE;
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
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.questchar = true;
	AddGameCharacter(n, ch);

			// WENCH 3
	ch.old.name = "Caroline";
	ch.old.lastname = "K";
	ch.name = TranslateString("","Caroline");
	ch.lastname = TranslateString("","K");
	ch.id		= "wench3";
	ch.model	= "Caroline_K";			//JRH
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
//	ch.location	= "QC_brothel";
//	ch.location.group = "goto";
//	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Caroline K_dialog.c";	//JRH
//	ch.greeting = "Gr_Wench3";			//try off
	ch.nation = PIRATE;
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
	ch.perks.list.Gunman = true;
	ch.money = "0";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	//LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.questchar = true;
	AddGameCharacter(n, ch);

				//BARTENDER
	ch.old.name = "Valentina";
	ch.old.lastname = "Malter";
	ch.name = TranslateString("","Valentina");
	ch.lastname = TranslateString("","Malter");
	ch.id		= "QCbartender";
//	ch.model	= "towngirl3";
	ch.model	= "w5_barwench";
	ch.sex = "woman";
	ch.location	= "QC_brothel";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "barwench_dialog.c";
	ch.greeting = "Gr_Woman_English Citizen";
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
	ch.work = "";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.questchar = true;
	AddGameCharacter(n, ch);

			// WENCH 4
	ch.old.name = "Celia";
	ch.old.lastname = "Hilder";
	ch.name = TranslateString("","Celia");
	ch.lastname = TranslateString("","Hilder");
	ch.id		= "wench4";
//	ch.model	= "towngirl3_1";
	ch.model	= "w4_Celia";
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
	ch.location	= "QC_brothel";
	ch.location.group = "goto";
	ch.location.locator = "goto21";		//JRH was goto3
	ch.Dialog.Filename = "wench_dialog.c";
	ch.nation = PIRATE;
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
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	ch.questchar = true;
	AddGameCharacter(n, ch);
//<-- JRH
}
