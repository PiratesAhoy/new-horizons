void SideQuestComplete(string sQuestName)
{
	ref PChar, sld, NPChar, lcn;
// KK -->
	int iPassenger, cidx, i, j, n, indianid;
	float locx, locy, locz, parx, pary, parz;
	float x1,x2,y1,y2,z1,z2,x,y,z;
	string homelocation, homegroup, homelocator, attr, locatorName, deck, shipname, temp;
// <-- KK
	ref ch;
	int limit;
	PChar = GetMainCharacter();

	switch(sQuestName)
	{
///////////////////////////////////////////////////////////////
///// OFFICER TUTORIAL
///////////////////////////////////////////////////////////////

		case "OT_Captain_enter_location":
			NPChar = CharacterFromID("Officer_Tutorial_Captain");
			ChangeCharacterAddressGroup(NPChar, PChar.location, "reload", "reload1");
			LAi_SetActorType(NPChar);
			LAi_SetActorType(PChar);
			NPChar.dialog.currentnode = "talk in tavern";
			LAi_ActorDialog(NPChar,Pchar,"",10.0,1.0);
			PChar.quest.Officer_Tutorial_Expire.win_condition.l1 = "Timer";
			PChar.quest.Officer_Tutorial_Expire.win_condition.l1.date.day = GetAddingDataDay(0, 3, 0);
			PChar.quest.Officer_Tutorial_Expire.win_condition.l1.date.month = GetAddingDataMonth(0, 3, 0);
			PChar.quest.Officer_Tutorial_Expire.win_condition.l1.date.year = GetAddingDataYear(0, 3, 0);
			PChar.quest.Officer_Tutorial_Expire.win_condition = "OT_Expired";
			LAi_SetPlayerType(PChar);
		break;
		
		case "OT_Go_Visit":
			NPChar = CharacterFromID("Officer_Tutorial_Captain");
			SetQuestHeader("Officer_Tutorial");
			AddQuestRecord("Officer_Tutorial", 1);
			PChar.quest.Officer_Tutorial.TalkedtoOfficer = true;
			LAi_ActorRunToLocator(NPChar,"reload","reload1","OT_Captain_leaves_location",40);
		break;
		
		case "OT_Captain_leaves_location":
			NPChar = CharacterFromID("Officer_Tutorial_Captain");
			ChangeCharacterAddressGroup(NPChar, "Oranjestad_Port_Captain_House", "goto", "goto2");
			LAi_SetStayType(NPChar);
			NPChar.dialog.currentnode = "Officer_Tutorial_Start";
		break;
		
		case "OT_Finish":
			AddQuestRecord("Officer_Tutorial", 2);
			CloseQuestHeader("Officer_Tutorial");
			AddXP(pchar, "Leadership", 150, XP_GROUP_OFFIC);
		break;
		
		case "OT_Expired":
			CloseQuestHeader("Officer_Tutorial");
		break;

///////////////////////////////////////////////////////////////
///// Smugglers Guild
///////////////////////////////////////////////////////////////
		
		case "learn about smugglers":
			//Levis you've heard about smugglers so let the player know:
			if(!CheckAttribute(pchar,"quest.smuggling_guild.have_met"))
			{
				SetQuestHeader("smuggleguild");
				AddQuestRecord("smuggleguild", 1);
				pchar.quest.smuggling_guild.have_met = true;

				PChar.quest.smugglebook_timeout2.win_condition.l1 = "Timer";
				PChar.quest.smugglebook_timeout2.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
				PChar.quest.smugglebook_timeout2.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
				PChar.quest.smugglebook_timeout2.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
				PChar.quest.smugglebook_timeout2.win_condition = "smugglebook_timeout";
			}
		break;
		
		case "Smugglers First Meeting":
			GiveItem2Character(Pchar,"smugglingbook");
			Pchar.quest.smuggling_got_book = true;
			if(!CheckAttribute(pchar,"quest.smuggling_guild.have_met"))
			{
				SetQuestHeader("smuggleguild");
				AddQuestRecord("smuggleguild", 1);
				pchar.quest.smuggling_guild.have_met = true;
			}
			AddQuestRecord("smuggleguild", 2);

			PChar.quest.smugglebook_timeout.win_condition.l1 = "Timer";
			PChar.quest.smugglebook_timeout.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.smugglebook_timeout.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.smugglebook_timeout.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			PChar.quest.smugglebook_timeout.win_condition = "smugglebook_timeout";
		break;

		case "smugglebook_timeout":
			PChar.quest.smugglebook_timeout.over = "yes";
			PChar.quest.smugglebook_timeout2.over = "yes";
			CloseQuestHeader("smuggleguild");
		break;

		case "Read_Smuggling_Book":
			CloseQuestHeader("smuggleguild");
			PChar.quest.smugglebook_timeout.over = "yes";
		break;
		
		case "Smuggler Paid for relation":
			pchar.quest.smuggling_guild.liking = 25;
			if(!CheckAttribute(pchar,"quest.smuggling_guild.have_met"))
			{
				SetQuestHeader("smuggleguild");
				AddQuestRecord("smuggleguild", 1);
				pchar.quest.smuggling_guild.have_met = true;
			}
			if(!CheckAttribute(pchar,"quest.smuggling_guild.times_payed"))
			{
				AddQuestRecord("smuggleguild", 3);
				pchar.quest.smuggling_guild.times_payed = 0;
			}
			pchar.quest.smuggling_guild.times_payed = sti(pchar.quest.smuggling_guild.times_payed) + 1;
		break;
		
		case "Smuggler Guild Refused Governor":
			if(!CheckAttribute(pchar,"quest.smuggling_guild.have_met"))
			{
				SetQuestHeader("smuggleguild");
				AddQuestRecord("smuggleguild", 1);
				pchar.quest.smuggling_guild.have_met = true;
			}
		break;
		
		case "Smuggler Guild Accepted Governor":
			if(!CheckAttribute(pchar,"quest.smuggling_guild.have_met"))
			{
				SetQuestHeader("smuggleguild");
				AddQuestRecord("smuggleguild", 1);
				pchar.quest.smuggling_guild.have_met = true;
			}
			ref gov_town = GetCurrentTown();
			if (!CheckAttribute(PChar,"quest.smuggling_guild.governor_quest"))
			{
				PChar.quest.smuggling_guild.governor_quest = true;
				PChar.quest.smuggling_guild.governor_quest.town = gov_town.id;
				PChar.quest.smuggling_guild.governor_quest.nation = gov_town.nation;
			}
			NPChar = GetTownGovernor(gov_town.id);
			PChar.quest.smuggling_guild.governor_smuggling = "accepted";
			PChar.quest.smuggling_guild.governor_smuggling.town = gov_town.id;
			PChar.quest.smuggling_guild.governor_smuggling.nation = gov_town.nation;
			PChar.quest.smuggling_guild.governor_smuggling.island = FindIslandByLocation(PChar.location);
			PChar.quest.smuggling_guild.governor_smuggling.governor = GetTownGovernorID(gov_town.id);
			PChar.quest.smuggling_guild.governor_smuggling.goods = NPChar.quest.smuggle.goods;
			PChar.quest.smuggling_guild.governor_smuggling.amount = NPChar.quest.smuggle.amount;
			GiveItem2Character(PChar,"smuggling_papers");
			AddCharacterGoods(PChar, sti(PChar.quest.smuggling_guild.governor_smuggling.goods), sti(PChar.quest.smuggling_guild.governor_smuggling.amount));

			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID(PChar.quest.smuggling_guild.governor_smuggling.governor)));
			Preprocessor_AddQuestData("town", FindTownName(PChar.quest.smuggling_guild.governor_smuggling.town));
			Preprocessor_AddQuestData("island", FindIslandName(PChar.quest.smuggling_guild.governor_smuggling.island));
			Preprocessor_AddQuestData("amount", PChar.quest.smuggling_guild.governor_smuggling.amount);
			Preprocessor_AddQuestData("cargo", Goods[sti(PChar.quest.smuggling_guild.governor_smuggling.goods)].name);
//			if (!CheckAttribute(PChar,"QuestInfo.governor_smuggling")) 
			SetQuestHeader("governor_smuggling");
			Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounSubj(NPChar)));
			Preprocessor_AddQuestData("pronoun2", XI_ConvertString(GetMyPronounObj(NPChar)));
			Preprocessor_AddQuestData("pronoun3", XI_ConvertString(GetMyPronounPossessive(NPChar)));
			Preprocessor_AddQuestData("pronoun1U", FirstLetterUp(XI_ConvertString(GetMyPronounSubj(NPChar))));
			AddQuestRecord("governor_smuggling", 1);
			Preprocessor_Remove("pronoun1U");
			Preprocessor_Remove("pronoun3");
			Preprocessor_Remove("pronoun2");
			Preprocessor_Remove("pronoun");
			Preprocessor_Remove("cargo");
			Preprocessor_Remove("amount");
			Preprocessor_Remove("island");
			Preprocessor_Remove("town");
			Preprocessor_Remove("governor");

			PChar.quest.governor_smuggling_time_up.win_condition.l1 = "Timer";
			PChar.quest.governor_smuggling_time_up.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.governor_smuggling_time_up.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.governor_smuggling_time_up.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			PChar.quest.governor_smuggling_time_up.win_condition = "governor_smuggling_time_up";
		break;

		case "governor_smuggling_time_up":
			if(CheckCharacterItem(PChar,"smuggling_first_report")) TakeItemFromCharacter(PChar,"smuggling_first_report");
			if(CheckCharacterItem(PChar,"smuggling_papers")) TakeItemFromCharacter(PChar,"smuggling_papers");	// GR: these documents are worthless now, so dump them
			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID(PChar.quest.smuggling_guild.governor_smuggling.governor)));
			Preprocessor_AddQuestData("nation", GetNationOfficialNameByType(sti(PChar.quest.smuggling_guild.governor_smuggling.nation)));
			AddQuestRecord("governor_smuggling", 9);
			CloseQuestHeader("governor_smuggling");
			Preprocessor_Remove("nation");
			Preprocessor_Remove("governor");
			LeaveService(PChar, sti(PChar.quest.smuggling_guild.governor_smuggling.nation), true);
			DeleteAttribute(PChar, "quest.smuggling_guild.governor_smuggling");
		break;
		
		case "Smugglers Opium Discovery":
			if(!CheckAttribute(PChar,"quest.smuggling_guild.have_met"))
			{
				SetQuestHeader("smuggleguild");
				AddQuestRecord("smuggleguild", 1);
				PChar.quest.smuggling_guild.have_met = true;
			}
			if(!CheckAttribute(PChar,"quest.smuggling_guild.opium_explain"))
			{
				if (!CheckAttribute(PChar,"QuestInfo.opium_smuggling")) SetQuestHeader("opium_smuggling");
				AddQuestRecord("opium_smuggling", 1);
			}
		break;
		
		case "Smugglers Opium Explain":
			pchar.quest.smuggling_guild.opium_explain = true;
			int NumMembers = 3+rand(3);
			GetSmugglingGuildMembers(NumMembers, "OpiumBuyers", "OpiumBuyer.c");
			//Get the opiumlist item
			ref opiumlist;
			string client="";
			//TODO: do this trough translate string
			string booktext="";
			makeref(opiumlist,Items[GetItemIndex("opiumlist")]);
			//Make a nice list
			aref Clients; makearef(Clients,pchar.quest.smuggling_guild.people.OpiumBuyers);
			for(i=0;i<GetAttributesNum(Clients);i++)
			{
				//TODO: add a check to see if the buyer is to close to the opium den and exclude that from the list.
				client = GetAttributeName(GetAttributeN(Clients,i));
				booktext += "Name: "+pchar.quest.smuggling_guild.people.OpiumBuyers.(client).name+GlobalStringConvert("newline");
				booktext += "Location: "+pchar.quest.smuggling_guild.people.OpiumBuyers.(client).location+GlobalStringConvert("newline");
				booktext += "Island: "+pchar.quest.smuggling_guild.people.OpiumBuyers.(client).island+GlobalStringConvert("newline");
				booktext += GlobalStringConvert("newline");
			}
			//Add the text to the book
			opiumlist.OpiumList = booktext;
			opiumlist.persistent = true; //makes sure the attribute is stored from now on.
			GiveItem2Character(pchar,"opiumlist");
			GiveItem2Character(pchar,"smugglingbook2");
			if(!CheckAttribute(pchar,"quest.smuggling_guild.have_met"))
			{
				SetQuestHeader("smuggleguild");
				AddQuestRecord("smuggleguild", 1);
				pchar.quest.smuggling_guild.have_met = true;
			}
			if (!CheckAttribute(PChar,"QuestInfo.opium_smuggling")) SetQuestHeader("opium_smuggling");
			AddQuestRecord("opium_smuggling", 2);
			if(CheckAttribute(pchar,"quest.smuggling_guild.governor_quest"))
			{
				AddQuestRecord("opium_smuggling", 3);
			}
		break;
		
		case "Smugglers Opium Effects Explain":
			AddQuestRecord("opium_smuggling", 10);
		break;
		
		case "First Encounter Opium Guard":
			pchar.quest.opium_smuggling.Encountered_Opium_Guard = true;
			AddQuestRecord("opium_smuggling", 5);
		break;

		case "arrest_smugglers_fight":
			PChar.quest.arrest_smugglers_fight_over.win_condition.l1 = "NPC_Death";
			PChar.quest.arrest_smugglers_fight_over.win_condition.l1.character = "Rand_Smug01";
			PChar.quest.arrest_smugglers_fight_over.win_condition.l2 = "NPC_Death";
			PChar.quest.arrest_smugglers_fight_over.win_condition.l2.character = "Rand_Smug02";
			PChar.quest.arrest_smugglers_fight_over.win_condition.l3 = "NPC_Death";
			PChar.quest.arrest_smugglers_fight_over.win_condition.l3.character = "Rand_Smug03";
			PChar.quest.arrest_smugglers_fight_over.win_condition = "arrest_smugglers_fight_over";

			PChar.quest.arrest_smugglers_fight_over.fail_condition.l1 = "ExitFromLocation";
			PChar.quest.arrest_smugglers_fight_over.fail_condition.l1.location = PChar.location;
			PChar.quest.arrest_smugglers_fight_over.fail_condition = "arrest_smugglers_ran_away";
		break;

		case "arrest_smugglers_fight_over":
			PChar.quest.smuggling_guild.governor_smuggling.arrested = "kill";
			AddQuestRecord("governor_smuggling", 5);
			GiveItem2Character(PChar,"smuggling_first_report");
			PChar.quest.smuggling_guild.governor_quest.made_first_report = true;
			PChar.quest.smuggling_guild.governor_smuggling = "report_made";
		break;

		case "arrest_smugglers_ran_away":
			ChangeSmugglerLiking(PChar, -40); //Add liking - you didn't kill them all so now they know you're a government agent
			AddQuestRecord("governor_smuggling", 6);
			GiveItem2Character(PChar,"smuggling_first_report");
			PChar.quest.smuggling_guild.governor_quest.made_first_report = true;
			PChar.quest.smuggling_guild.governor_smuggling = "report_made";
		break;
		
		case "Made First Smuggling Report":
//			if(CheckAttribute(pchar,"quest.smuggling_guild.governor_quest"))
//			if(CheckAttribute(PChar,"quest.smuggling_guild.governor_smuggling") && sti(GetAttribute(PChar, "quest.smuggling_guild.governor_smuggling.nation")) == GetSmugglingNation())
//			{
//				if(!CheckAttribute(pchar,"quest.smuggling_guild.governor_quest.made_first_report"))
				if(!CheckCharacterItem(PChar,"smuggling_first_report") && CheckAttribute(PChar, "quest.smuggling_guild.governor_smuggling.contact_made"))
				{
					GiveItem2Character(pchar,"smuggling_first_report");
					AddQuestRecord("governor_smuggling", 2);
					pchar.quest.smuggling_guild.governor_quest.made_first_report = true;
					PChar.quest.smuggling_guild.governor_smuggling = "report_made";
				}
//			}
		break;
		
		case "Hand in First Smuggling Report":
//			ChangeRMRelation(PChar, sti(PChar.quest.smuggling_guild.governor_quest.nation), 5);			// GR: Rewards now handled in "governor.c" depending on what you did to smugglers
//			AddMoneyToCharacter(PChar, 2500);
//			AddXP(PChar, SKILL_SNEAK, 1000, XP_GROUP_OFFIC);
			PChar.quest.governor_smuggling_time_up.over = "yes";							// GR: cancel timer
			TakeItemFromCharacter(PChar,"smuggling_first_report");
			if(CheckCharacterItem(PChar,"smuggling_papers")) TakeItemFromCharacter(PChar,"smuggling_papers");	// GR: take away the papers so you can't keep using them.  If you want them again, ask the governor for another job!
			PChar.quest.smuggling_guild.governor_quest.gave_first_report = true;
			PChar.quest.smuggling_guild.governor_smuggling = "report_handed_in";
			if (!CheckAttribute(PChar, "quest.governor_smuggling.recover_cargo") && !CheckAttribute(PChar, "quest.governor_smuggling.recover_money"))
			{
				Preprocessor_AddQuestData("pronoun", GetMyPronounSubj(CharacterFromID(PChar.quest.smuggling_guild.governor_smuggling.governor)));
				AddQuestRecord("governor_smuggling", 3);
				Preprocessor_Remove("pronoun");
				LAi_QuestDelay("close_governor_smuggling", 0.0);
			}
		break;

		case "close_governor_smuggling":
			NPChar = CharacterFromID(PChar.quest.smuggling_guild.governor_smuggling.governor); 
			if (CheckAttribute(NPChar, "original_TempNode"))	// GR: attribute set by "governor.c" if you owed cargo or money
			{
				NPChar.Dialog.TempNode = NPChar.original_TempNode;
				NPChar.Dialog.CurrentNode = NPChar.original_TempNode;
				DeleteAttribute(NPChar, "original_TempNode");
			}
			CloseQuestHeader("governor_smuggling");
			PChar.quest.delete_governor_smuggling.win_condition.l1 = "MapEnter";
			PChar.quest.delete_governor_smuggling.win_condition.l2 = "Timer";
			PChar.quest.delete_governor_smuggling.win_condition.l2.date.day   = GetAddingDataDay  (0, 0, 3);
			PChar.quest.delete_governor_smuggling.win_condition.l2.date.month = GetAddingDataMonth(0, 0, 3);
			PChar.quest.delete_governor_smuggling.win_condition.l2.date.year  = GetAddingDataYear (0, 0, 3);
			PChar.quest.delete_governor_smuggling.win_condition = "delete_governor_smuggling";
		break;

		case "delete_governor_smuggling":
			DeleteQuestHeader("governor_smuggling");
			DeleteAttribute(PChar, "quest.smuggling_guild.governor_smuggling");
		break;

		case "governor_smuggling_recover_cargo":
			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID(PChar.quest.governor_smuggling.recover_cargo.governor)));
			Preprocessor_AddQuestData("amount", PChar.quest.governor_smuggling.recover_cargo.amount);
			Preprocessor_AddQuestData("cargo", Goods[sti(PChar.quest.governor_smuggling.recover_cargo.goods)].name);
			Preprocessor_AddQuestData("deadline", GetHumanDate(GetAddingDataYear(0, 1, 0), GetAddingDataMonth(0, 1, 0), GetAddingDataDay(0, 1, 0)));
			Preprocessor_AddQuestData("nation", GetNationOfficialNameByType(sti(PChar.quest.smuggling_guild.governor_smuggling.nation)));
			AddQuestRecord("governor_smuggling", 7);
			Preprocessor_Remove("nation");
			Preprocessor_Remove("deadline");
			Preprocessor_Remove("cargo");
			Preprocessor_Remove("amount");
			Preprocessor_Remove("governor");
			PChar.quest.governor_smuggling_time_up_cargo.win_condition.l1 = "Timer";
			PChar.quest.governor_smuggling_time_up_cargo.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.governor_smuggling_time_up_cargo.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.governor_smuggling_time_up_cargo.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			PChar.quest.governor_smuggling_time_up_cargo.win_condition = "governor_smuggling_time_up_cargo";
		break;

		case "governor_smuggling_recover_money":
			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID(PChar.quest.governor_smuggling.recover_money.governor)));
			Preprocessor_AddQuestData("money", PChar.quest.governor_smuggling.recover_money.amount);
			Preprocessor_AddQuestData("deadline", GetHumanDate(GetAddingDataYear(0, 1, 0), GetAddingDataMonth(0, 1, 0), GetAddingDataDay(0, 1, 0)));
			Preprocessor_AddQuestData("nation", GetNationOfficialNameByType(sti(PChar.quest.smuggling_guild.governor_smuggling.nation)));
			AddQuestRecord("governor_smuggling", 8);
			Preprocessor_Remove("nation");
			Preprocessor_Remove("deadline");
			Preprocessor_Remove("money");
			Preprocessor_Remove("governor");
			PChar.quest.governor_smuggling_time_up_money.win_condition.l1 = "Timer";
			PChar.quest.governor_smuggling_time_up_money.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.governor_smuggling_time_up_money.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.governor_smuggling_time_up_money.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			PChar.quest.governor_smuggling_time_up_money.win_condition = "governor_smuggling_time_up_money";
		break;

		case "governor_smuggling_time_up_cargo":
			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID(PChar.quest.governor_smuggling.recover_cargo.governor)));
			AddQuestRecord("governor_smuggling", 10);
			Preprocessor_Remove("governor");
			LeaveService(PChar, sti(PChar.quest.governor_smuggling.recover_cargo.nation), true);
			DeleteQuestAttribute("governor_smuggling");
			CloseQuestHeader("governor_smuggling");
		break;

		case "governor_smuggling_time_up_money":
			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID(PChar.quest.governor_smuggling.recover_money.governor)));
			AddQuestRecord("governor_smuggling", 11);
			Preprocessor_Remove("governor");
			LeaveService(PChar, sti(PChar.quest.governor_smuggling.recover_money.nation), true);
			DeleteQuestAttribute("governor_smuggling");
			CloseQuestHeader("governor_smuggling");
		break;
		
		case "Hand in Buyers List":
			ChangeRMRelation(pchar, sti(pchar.quest.smuggling_guild.governor_quest.nation), 5);
			AddMoneyToCharacter(pchar, 1500);
			AddXP(pchar, SKILL_SNEAK, 500, XP_GROUP_OFFIC);
			AddQuestRecord("opium_smuggling", 7);
			pchar.quest.smuggling_guild.governor_quest.gave_buyers_list = true;
		break;
		
		case "Made Second Smuggling Report":
			if(CheckAttribute(pchar,"quest.smuggling_guild.governor_quest"))
			{
				if(!CheckAttribute(pchar,"quest.smuggling_guild.governor_quest.made_second_report"))
				{
					GiveItem2Character(pchar,"smuggling_second_report");
					AddQuestRecord("opium_smuggling", 6);
					pchar.quest.smuggling_guild.governor_quest.made_second_report = true;
				}
			}
		break;
		
		case "Hand in Second Smuggling Report":
			ChangeRMRelation(pchar, sti(pchar.quest.smuggling_guild.governor_quest.nation), 5);
			AddMoneyToCharacter(pchar, 3500);
			AddXP(pchar, SKILL_SNEAK, 1200, XP_GROUP_OFFIC);
			TakeItemFromCharacter(pchar,"smuggling_second_report");
			AddQuestRecord("opium_smuggling", 8);
			pchar.quest.smuggling_guild.governor_quest.gave_second_report = true;
		break;
		
		case "Hand in Final Smuggling Report":
			//ChangeRMRelation(pchar, sti(pchar.quest.smuggling_guild.governor_quest.nation), 5);
			SetRMRelation(pchar, sti(pchar.quest.smuggling_guild.governor_quest.nation), RequiredNextRankDirect(GetRank(pchar, sti(pchar.quest.smuggling_guild.governor_quest.nation))+1) );
			AddMoneyToCharacter(pchar, 2500);
			AddXP(pchar, SKILL_SNEAK, 1200, XP_GROUP_OFFIC);
			AddQuestRecord("opium_smuggling", 9);
			CloseQuestHeader("opium_smuggling");     // TALISMAN - added to close Header at Current end of Quest
			pchar.quest.smuggling_guild.governor_quest.final_report = true;
		break;
		
///////////////////////////////////////////////////////////////
///// The mysterious plants
///////////////////////////////////////////////////////////////

		case "Learned About Apothecary":
			//SetQuestHeader("plants");
			//AddQuestRecord("plants", 1);
			pchar.quest.mysterious_plants.learned = true;
		break;
		
		case "Accept Donate Apothecary":
			AddQuestRecord("plants", 9);
			//Incase you changed your mind.
			if(CheckAttribute(pchar,"quest.meet_church_people"))
			{
				DeleteAttribute(&pchar,"quest.meet_church_people")
			}
			pchar.quest.mysterious_plants.donate = true;
		break;
		
		case "Decline Donate Apothecary":
			DeleteAttribute(&PChar,"quest.mysterious_plants.donate");
			pchar.quest.mysterious_plants.declined = true;


			if (!CheckAttribute(pchar,"quest.mysterious_plants.pay_church"))
			{
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			
			Locations[FindLocation("Greenford_town")].vcskip = true; //Added to make sure the questscene works
			pchar.quest.meet_church_people.win_condition.l1 = "ExitFromLocation";
			pchar.quest.meet_church_people.win_condition.l1.location = "apothecary";
			pchar.quest.meet_church_people.win_condition = "Meet Church People";
			}
		break;
		
		case "Meet Church People":
			DeleteAttribute(&Locations[FindLocation("Greenford_town")],"vcskip");
			AddQuestRecord("plants", 3);
			//Make sure you can't escape the mob
			LAi_SetActorType(PChar);
			LAi_ActorRunToLocator(PChar, "officers", "reload13_3", "", -1);
			//Lock the apothecary so you can't reload back in
			locations[FindLocation("Greenford_town")].reload.l18.disable = 1;
			//Generate a mob
			String IDXname;
			sld = LAi_CreateFantomCharacterExOt(false, OFFIC_TYPE_CIVILIAN, GetRandomRank(true, OFFIC_TYPE_CIVILIAN, 0), true, 0.75, "monk", "reload", "reload15");
			sld.Dialog.Filename = "apothecary_quest.c";
			sld.Dialog.CurrentNode = "Mob Leader";
			//GiveItem2Character(sld,"albatross"); //Just some fun and in case the apothecary gets closed you can practise how to get rid of it
			Pchar.quest.mysterious_plants.mob.priest = sld.index;
			LAi_SetActorType(sld);
			LAi_group_MoveCharacter(sld, "Mob");
			LAi_ActorRunToLocator(sld, "officers", "reload13_3", "Walk to Priest Apothecary", 7.0);
			LAi_QuestDelay("mob part 2",1); //So the priest will always be in front
			//Let's make sure your officers aren't blocking the path
			for(i=0; i < GetPassengersQuantity(PChar); i++)
			{
				cidx = GetPassenger(PChar, i);
				if (IsOfficer(Characters[cidx]))
				{
					LAi_SetActorType(Characters[cidx]);
				}
			}
		break;
		
		case "mob part 2":
			int nummob = GetDifficulty() + 2 + Rand(3);
			if((nummob + LAi_numloginedcharacters) > (MAX_LOGINED_CHARACTERS_IN_LOCATION-1))
			{
				trace("MADE MOB SMALLER TO KEEP SLOTS FREE");
				nummob = LAi_numloginedcharacters-(MAX_LOGINED_CHARACTERS_IN_LOCATION-2);
			}
			for (i = 0; i <= nummob; i++)
			{
				IDXname = "Mob"+i;
				sld = LAi_CreateFantomCharacterExOt(false, OFFIC_TYPE_CIVILIAN, GetRandomRank(true, OFFIC_TYPE_CIVILIAN, 0), true, 0.75, GetRandomModelForTypeExSubCheck(1, "lower_citizens", "man", GetCurrentLocationNation()), "reload", "reload15");
				Pchar.quest.mysterious_plants.mob.(IDXname) = sld.index;
				LAi_SetActorType(sld);
				LAi_group_MoveCharacter(sld, "Mob");
				LAi_ActorRunToLocator(sld, "goto", "goto27", "", -1);
			}
		break;
		
		case "Walk to Priest Apothecary":
			//Talk to the priest in charge
			sld = &characters[sti(Pchar.quest.mysterious_plants.mob.priest)];
			//LAi_ActorFollow(sld, pchar, "", 3.0);
			LAi_ActorWaitDialog(PChar, sld);
			LAi_ActorDialog(sld, Pchar, "", 1.0, 0);
		break;
		
		case "Apothecary Fight Mob"://PW third dialogue branch
			//We fight the mob
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "Mob", true);
			LAi_SetPlayerType(Pchar);
			for(i=0; i < GetPassengersQuantity(PChar); i++)
			{
				cidx = GetPassenger(PChar, i);
				if (IsOfficer(Characters[cidx]))
				{
					LAi_SetOfficerType(Characters[cidx]);
				}
			}
			PChar.locationLock = true;
			ChangeRMRelation(pchar, GetCurrentLocationNation(), -20);//PW loss of relations for fighting citizens (even a lynch mob!!)
			AddQuestRecord("plants", 4);
			PChar.quest.apothecary_fight_mob.win_condition.l1 = "Group_Death";
			PChar.quest.apothecary_fight_mob.win_condition.l1.group = "Mob";
			PChar.quest.apothecary_fight_mob.win_condition = "Steven Comes Outside";
		break;
		
		case "Steven Comes Outside":
			locations[FindLocation("Greenford_town")].reload.l18.disable = 1;
			sld = &characters[GetCharacterIndex("Apothecary")];
			ChangeCharacterAddressGroup(sld,pchar.location,"reload","reload13");
			LAi_SetActorType(sld);
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(PChar, sld);
			sld.Dialog.CurrentNode = "Killed Mob";
			LAi_ActorDialog(sld, Pchar, "", 1.0, 0);
		break;
		
		case "Officiant helps steven":
			sld = GetTownOfficiant("Greenford");
			ChangeCharacterAddressGroup(sld,"Greenford_town","goto","goto15");
			sld.Dialog.Filename = "apothecary_quest.c";
			sld.Dialog.CurrentNode = "Help Steven Leave";
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(Pchar,"goto","goto15");
			LAi_ActorWaitDialog(PChar, sld);
			LAi_ActorDialog(sld,pchar,"",1.0,0);
		break;
		
		case "Steven Leaves":
			if(CheckCharacterPerkLocked(Pchar, "ImprovePotions")) UnlockPerkCharacter(PChar ,"ImprovePotions");
			AddQuestRecord("plants", 8);
			CloseQuestHeader("plants");
			LAi_ActorTurnToLocator(Pchar,"reload","reload13");
			sld = &characters[GetCharacterIndex("Apothecary")];
			LAi_ActorRunToLocation(sld, "reload", "reload13", "none", "", "", "", 45.0);
			sld = GetTownOfficiant("Greenford");
			LAi_type_actor_Reset(sld);
			LAi_ActorRunToLocator(sld, "reload", "reload13", "", -1);
			pchar.quest.plants.steven_left = true;//PW not used (so far) shortened to plants to persist after quest
			pchar.quest.plants.officiant_buys_albatros = true;
			DeleteAttribute(&Stores[GREENFORD_STORE],"apothecary"); //Remove from array so fetchquest wont pick it anymore
			DeleteAttribute(&PChar,"quest.mysterious_plants");//PW tidy up all attributes in tree
			LAi_QuestDelay("Reset Officiant",3);
		break;
		
		case "Reset Officiant":
			sld = GetTownOfficiant("Greenford");
			LAi_SetWaitressType(sld);
			ChangeCharacterAddressGroup(sld,"Greenford_tavern","waitress","barmen");
			sld.Dialog.Filename = "eng_officiant_dialog.c";
			sld.Dialog.CurrentNode = "First time";
			LAi_SetPlayerType(Pchar);
			DisableFastTravel(false);
			DisableMenuLaunch(false);
		break;
		
		case "Apothecary Pay"://PW second dialogue branch - originally not available if pchar less than 1000 coins
			LAi_SetPlayerType(Pchar);
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			for(i=0; i < GetPassengersQuantity(PChar); i++)
			{
				cidx = GetPassenger(PChar, i);
				if (IsOfficer(Characters[cidx]))
				{
					LAi_SetOfficerType(Characters[cidx]);
				}
			}
			locations[FindLocation("Greenford_town")].reload.l18.disable = 0;
			//PChar.quest.mysterious_plants.donate = 1000;//PW dialogue change to intention to donate in case PChar doesn't have 1000 - you have to return and talk to apothecary to continue
			//PW originally if had less than 1000 didn't get this option so apothecary going to close either other way you could proceed.
			sld = &characters[sti(Pchar.quest.mysterious_plants.mob.priest)];
			LAi_type_actor_Reset(sld);
			LAi_ActorRunToLocation(sld, "reload", "reload15", "none", "", "", "Remove Mob", 45.0);
			aref mob; makearef(mob,Pchar.quest.mysterious_plants.mob);
			for(i=1;i<GetAttributesNum(mob);i++)
			{
				sld = &characters[sti(GetAttributeValue(GetAttributeN(mob,i)))];
				LAi_type_actor_Reset(sld);
				LAi_ActorRunToLocator(sld, "officers", "reload15_3", "", -1);
			}
			AddQuestRecord("plants", 5);
			pchar.quest.mysterious_plants.pay_church = true;//PW seems not used = now used to prevent mob again in second branch (loop round donate or not)
		break;
		
		case "Remove Mob":
			if(pchar.location == "Greenford_town") //Incase we leave
			{
				aref mobr; makearef(mobr,Pchar.quest.mysterious_plants.mob);
				for(i=0;i<GetAttributesNum(mobr);i++)
				{
					sld = &characters[sti(GetAttributeValue(GetAttributeN(mobr,i)))];
					ChangeCharacterAddressGroup(sld,"none","","");
				}
			}
		break;
		
		case "Apothecary BOOM"://PW first dialogue branch
			LAi_ActorRunToLocator(pchar, "officers", "reload13_3", "Enter Apothecary", -1);
		break;
		
		case "Enter Apothecary":
			AddQuestRecord("plants", 6);
			PlayStereoSound("OBJECTS\ABORDAGE\abordage_wining.wav");
			LAi_ActorTurnToLocator(Pchar, "reload", "reload13");
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			for(i=0; i < GetPassengersQuantity(PChar); i++)
			{
				cidx = GetPassenger(PChar, i);
				if (IsOfficer(Characters[cidx]))
				{
					LAi_SetOfficerType(Characters[cidx]);
				}
			}
			sld = &characters[sti(Pchar.quest.mysterious_plants.mob.priest)];
			LAi_type_actor_Reset(sld);
			LAi_ActorRunToLocation(sld, "reload", "reload13", "none", "", "", "Remove Mob", 45.0);
			aref mobb; makearef(mobb,Pchar.quest.mysterious_plants.mob);
			for(i=1;i<GetAttributesNum(mobb);i++)
			{
				sld = &characters[sti(GetAttributeValue(GetAttributeN(mobb,i)))];
				LAi_type_actor_Reset(sld);
				//LAi_ActorFollow(sld, &characters[sti(Pchar.quest.mysterious_plants.mob.priest)], "", 10);
				LAi_ActorRunToLocator(sld, "reload", "reload13", "", -1);

			}
			LAi_QuestDelay("Apothecary fight",3);
			ChangeCharacterReputation(PChar, -5);// PW hit on reputation for just standing aside 
			pchar.quest.mysterious_plants.pillage = true;
			//PW this timer is for next day, OK if you are hit by blast and out of it (or leave location) but too late if you weren't
			//PW placed immediate questbook update if not hit by blast and stop timer to prevent duplicate entry later in "officiant Leaves"
			PChar.quest.Steven_dead.win_condition.l1 = "Timer";
			PChar.quest.Steven_dead.win_condition.l1.date.day = GetAddingDataDay(0, 0, 1);
			PChar.quest.Steven_dead.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			PChar.quest.Steven_dead.win_condition.l1.date.year = GetAddingDataYear(0, 0, 1);
			PChar.quest.Steven_dead.win_condition = "Apothecary Steven Dead";
		break;
		
		case "Apothecary fight":
			if(pchar.location == "Greenford_town")
			{
				PlayStereoSound("OBJECTS\ABORDAGE\abordage1.wav");
				LAi_QuestDelay("Apothecary fight 2",2);
			}
		break;
		
		case "Apothecary fight 2":
			if(pchar.location == "Greenford_town") //Incase we leave
			{
				parx = stf(loadedLocation.locators.reload.reload13.x);
				pary = stf(loadedLocation.locators.reload.reload13.y);
				parz = stf(loadedLocation.locators.reload.reload13.z);
				CreateParticleSystem("smoke_short" , parx, pary+1, parz, 5.1, 4.0, 0.0, 20);
				CreateParticleSystem("smoke_short" , parx+1, pary+2, parz, 5.1, 4.0, 0.0, 20);
				LAi_QuestDelay("Apothecary fight 3",3);
			}
		break;
		
		case "Apothecary fight 3":
			if(pchar.location == "Greenford_town") //Incase we leave
			{
				parx = stf(loadedLocation.locators.reload.reload13.x);
				pary = stf(loadedLocation.locators.reload.reload13.y);
				parz = stf(loadedLocation.locators.reload.reload13.z);
				CreateParticleSystem("smoke_short" , parx+1, pary+2, parz, 5.1, 4.0, 0.0, 20);
				CreateParticleSystem("smoke_short" , parx-1, pary+2, parz, 5.1, 4.0, 0.0, 20);
				LAi_QuestDelay("Apothecary does boom",3);
			}
			LAi_SetPlayerType(PChar);
		break;
		
		case "Apothecary does boom":
			if(pchar.location == "Greenford_town") //Incase we leave
			{
				parx = stf(loadedLocation.locators.reload.reload13.x);
				pary = stf(loadedLocation.locators.reload.reload13.y);
				parz = stf(loadedLocation.locators.reload.reload13.z);
				CreateParticleSystemX("blast", parx, pary, parz, -1.57, 0.0, 0.0,0);
				PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
				GetCharacterPos(PChar, &locx, &locy, &locz);
				float distance = GetDistance2D(locx, locz, parx, parz);
				if(distance < 2.0)
				{
					LAi_QuestDelay("Apothecary blown away by blast",0);//PW close to explosion branch
				}
				else
				{
					LAi_QuestDelay("Apothecary leave",1);//PW not close enough to blast for PChar knockout branch
				}
			}
		break;
		
		case "Apothecary blown away by blast"://PW close to explosion branch
			LAi_SetLayType(Pchar);
			LAi_fade("Apothecary Move to Tavern", "");
			WaitDate("", 0,0,1,0,0);
			DeleteAttribute(&PChar,"quest.mysterious_plants.mob");
		break;
		
		case "Apothecary Move to Tavern":
			ResurrectingOfficiant = GetTownOfficiant("Greenford");
			ResurrectingOfficiant.resurrection.location
			if (Resurrectingofficiant.id == "Eleuthera_officiant")
			{
				ChangeCharacterAddressGroup(ResurrectingOfficiant, ResurrectingOfficiant.resurrection.location, "goto", "stab");
				DoReloadCharacterToLocation(ResurrectingOfficiant.resurrection.location, "goto", "goto3");
			}
			else
			{
				ChangeCharacterAddressGroup(ResurrectingOfficiant, ResurrectingOfficiant.resurrection.location, "goto", "goto3");
				DoReloadCharacterToLocation(ResurrectingOfficiant.resurrection.location, "goto", "goto2");
			}
			ResurrectingOfficiant.Dialog.Filename = "apothecary_quest.c";
			ResurrectingOfficiant.Dialog.CurrentNode = "Hit by Blast";
			SetSkillCharMod(PChar, "Fencing", -2, "BlowDamage", "A large explosion hit you"); //Levis
			SetSkillCharMod(PChar, "Defence", -1, "BlowDamage", "A large explosion hit you"); //Levis
			//PW (Note) No further hit on reputation because you tried to go back in to stop the mob			
			LAi_QuestDelay("ResurrectionEvent_BlazeWakes",0);
			DisableFastTravel(true);
			pchar.quest.Reset_Officiant_after_Boom.win_condition.l1 = "ExitFromLocation";
			pchar.quest.Reset_Officiant_after_Boom.win_condition.l1.location = ResurrectingOfficiant.resurrection.location;
			pchar.quest.Reset_Officiant_after_Boom.win_condition = "Reset Officiant";
		break;
		
		case "Apothecary leave"://PW not close enough to blast for PChar knockout branch
			if(pchar.location == "Greenford_town") //Incase we leave
			{
				PlayStereoSound("OBJECTS\ABORDAGE\abordage_loosing.wav");
				parx = stf(loadedLocation.locators.reload.reload13.x);
				pary = stf(loadedLocation.locators.reload.reload13.y);
				parz = stf(loadedLocation.locators.reload.reload13.z);
				CreateParticleSystem("smoke" , parx+0.5, pary+2, parz, 5.1, 4.0, 0.0, 20);
				CreateParticleSystem("smoke" , parx-0.3, pary+2.5, parz, 5.1, 4.0, 0.0, 20);
				LAi_QuestDelay("Priest leaves Apothecary",3);
			}
		break;
		
		case "Priest leaves Apothecary":
			if(pchar.location == "Greenford_town") //Incase we leave
			{
				sld = &characters[sti(Pchar.quest.mysterious_plants.mob.priest)];
				ChangeCharacterAddressGroup(sld,pchar.location,"reload","reload13");
				parx = stf(loadedLocation.locators.reload.reload13.x);
				pary = stf(loadedLocation.locators.reload.reload13.y);
				parz = stf(loadedLocation.locators.reload.reload13.z)+0.43;
				//check if a buildingslot is free
				lcn = &Locations[FindLocation(pchar.location)];
				int nr = -1;
				for(i = 1; i<=MAXBUILDINGS; i++)
				{
					attr = "building."+i+".building";
					if( !CheckAttribute(lcn,attr) && nr < 0)
					{
						nr = i;
					}
				}
				attr = "building."+nr+".building";

				Build(attr, "roche", "", parx, pary, parz, PI, "buildings");
				LAi_ActorRunToLocation(sld, "reload", "reload15", "none", "", "", "", 45.0);
				LAi_QuestDelay("Officiant turns up",3);//PW added 2 cases so officiant can tell you about albatross
			}
			DeleteAttribute(&PChar,"quest.mysterious_plants.mob");
			
		break;
		
		case "Officiant turns up"://PW new case if PChar not hit by blast so officiant can tell you about albatross
			sld = GetTownOfficiant("Greenford");
			ChangeCharacterAddressGroup(sld,"Greenford_town","goto","goto15");
			sld.Dialog.Filename = "apothecary_quest.c";
			sld.Dialog.CurrentNode = "officiant Leave";
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(Pchar,"goto","goto15");
			LAi_ActorWaitDialog(PChar, sld);
			LAi_ActorDialog(sld,pchar,"",1.0,0);
		break;

		case "officiant Leaves"://PW new case if PChar not hit by blast so officiant can tell you about albatross
			AddQuestRecord("plants",50);
			ChangeCharacterReputation(PChar, -5);//PW hit on reputation for standing aside and not going to help
			CloseQuestHeader("plants");
			PChar.quest.plants.steven_dead = true;
			LAi_ActorTurnToLocator(Pchar,"reload","reload13");
			sld = GetTownOfficiant("Greenford");
			LAi_type_actor_Reset(sld);
			LAi_ActorRunToLocator(sld, "reload", "reload13", "", -1);
			pchar.quest.plants.officiant_buys_albatros = true;
			DeleteAttribute(&Stores[GREENFORD_STORE],"apothecary"); //Remove from array so fetchquest wont pick it anymore
			DeleteAttribute(&PChar,"quest.mysterious_plants");//PW tidy up all attributes in tree
			DeleteAttribute(&PChar,"quest.Steven_dead.win_condition");//PW stop timer from calling "Apothecary Steven Dead":
			LAi_QuestDelay("Reset Officiant",3);
		break;

		case "Apothecary Steven Dead":
			AddQuestRecord("plants", 7);
			//ChangeCharacterReputation(PChar, -5);//PW No added hit on reputation you went back to try and intervene
			CloseQuestHeader("plants");
			PChar.quest.plants.steven_dead = true;
			pchar.quest.plants.officiant_buys_albatros = true;
			DeleteAttribute(&Stores[GREENFORD_STORE],"apothecary"); //Remove from array so fetchquest wont pick it anymore
			DeleteAttribute(&PChar,"quest.mysterious_plants");//PW tidy up all attributes in tree

		break;
		
		case "Apothecary Talk Business":
			if(CheckCharacterPerkLocked(Pchar, "ImprovePotions")) UnlockPerkCharacter(PChar ,"ImprovePotions");
			AddQuestRecord("plants", 10);
			PChar.quest.mysterious_plants.heard_job = "explain";
		break;
		
		case "Apothecary Decline Business":
			AddQuestRecord("plants", 11);
			CloseQuestHeader("plants");
			DeleteAttribute(&PChar,"quest.mysterious_plants");//PW tidy up all attributes in tree
			Pchar.quest.plants = "done";//PW check that quest "done"for no further re=loop dialogs
		break;
		
		case "Talk Business Accept":
			//Create a crewmember to talk to the captain
			AddXP(pchar, SKILL_COMMERCE, 1000, XP_GROUP_OFFIC);
			sld = LAi_CreateFantomCharacterExOt(true, GetBoardingCrewType(PChar), sti(pchar.rank), true, 0.0, LAi_GetBoardingModel(PChar, ""), "reload", "reload1");
			LAi_StoreFantom(sld);
			EquipFromLocker(sld);
			CheckCharacterCurse(sld);
			LAi_SetActorType(sld);
			LAi_SetActorType(PChar);
			sld.Dialog.Filename = "apothecary_quest.c";
			sld.Dialog.CurrentNode = "Crew Spotted Natives";
			LAi_ActorWaitDialog(PChar,sld);
			LAi_ActorDialog(sld, PChar, "", 1.0, 0);
			PChar.quest.mysterious_plants.guard_ship = true;
			PChar.quest.mysterious_plants.crewmember = sld.index;
			Pchar.quest.Apothecary_Guard_Ship.win_condition.l1 = "location";
			Pchar.quest.Apothecary_Guard_Ship.win_condition.l1.character = PChar.id;
			Pchar.quest.Apothecary_Guard_Ship.win_condition.l1.location = "Greenford_port";
			Pchar.quest.Apothecary_Guard_Ship.win_condition = "Ship Guarded";
			DisableFastTravel(true); //prevent leaving
		break;
		
		case "Apothecary Discuss Guards":
			sld = &characters[sti(PChar.quest.mysterious_plants.crewmember)];
			LAi_ActorRunToLocation(sld, "reload", "reload1", "none", "", "", "", 45.0);
			sld = &characters[GetCharacterIndex("Apothecary")];
			LAi_SetActorType(sld);
			LAi_ActorSetSitMode(sld);
			LAi_ActorWaitDialog(PChar, sld);
			sld.Dialog.CurrentNode = "Discuss Guarded";
			LAi_ActorDialog(sld, Pchar, "", 1.0, 0);
			Locations[FindLocation("Greenford_town")].vcskip = true; //Added to make sure the questscene works
			pchar.quest.meet_church_people.win_condition.l1 = "ExitFromLocation";
			pchar.quest.meet_church_people.win_condition.l1.location = "apothecary";
			pchar.quest.meet_church_people.win_condition = "Apothecary Crewmember Kill";
		break;
		
		case "Prepare Apothecary Voyage":
			PChar.quest.mysterious_plants.prepare_voyage = true;
			AddQuestRecord("plants", 12);
			LAi_SetPlayerType(PChar);
			LAi_SetSitType(&characters[GetCharacterIndex("Apothecary")]);
			Pchar.quest.Smugglers_Request.win_condition.l1 = "location";
			Pchar.quest.Smugglers_Request.win_condition.l1.character = PChar.id;
			Pchar.quest.Smugglers_Request.win_condition.l1.location = "Greenford_port";
			Pchar.quest.Smugglers_Request.win_condition = "Smugglers Request Collector";
		break;
		
		case "Apothecary Crewmember Kill":
			DeleteAttribute(&Locations[FindLocation("Greenford_town")],"vcskip");
			ChangeCharacterAddressGroup(&characters[sti(PChar.quest.mysterious_plants.crewmember)],pchar.location,"goto","goto38");
			indianid = 1+rand(2);
			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, false, 1.0, "indian"+indianid, "goto", "goto30");
			TakeItemFromCharacter(sld,"tomahawk");//PW kills crewmember too quickly with this
			GiveItem2Character(sld,"pistolbow");//PW make sure he has bow for collector since weapons now false
			GiveItem2Character(sld,"blade5");//PW indian will (eventually) win the fight with this if pchar does not help
			LAi_SetWarriorType(sld);
			LAi_SetWarriorType(&characters[sti(PChar.quest.mysterious_plants.crewmember)]);
			LAi_group_MoveCharacter(&characters[sti(PChar.quest.mysterious_plants.crewmember)], "crewmember");
			LAi_group_MoveCharacter(sld, "IndianGuards1");
			LAi_group_FightGroups("IndianGuards1","crewmember",true);
			LAi_group_FightGroups("IndianGuards1",LAI_GROUP_PLAYER,true);
			LAi_type_warrior_Attacked(sld, &characters[sti(PChar.quest.mysterious_plants.crewmember)]);
			//Kill indian
			Pchar.quest.Killed_Indian_Ambush.win_condition.l1 = "NPC_Death";
			Pchar.quest.Killed_Indian_Ambush.win_condition.l1.character = sld.id;
			Pchar.quest.Killed_Indian_Ambush.win_condition = "Apothecary Killed Indian Ambush";
		break;
		
		case "Apothecary Killed Indian Ambush":
			i = sti(GetAttribute(Pchar,"quest.mysterious_plants.indians.killed")) + 1;
			Pchar.quest.mysterious_plants.indians.killed = i;
			sld = &characters[sti(PChar.quest.mysterious_plants.crewmember)];
			if(LAi_IsDead(sld))
			{
				pchar.ship.crew.quantity = sti(pchar.ship.crew.quantity) - 1;
				pchar.ship.crew.morale = sti(pchar.ship.crew.morale) - 10; //Drop in morale
				AddQuestRecord("plants", 13);
				PChar.quest.mysterious_plants.crewmembers_killed_by_indians = sti(GetAttribute(PChar,"quest.mysterious_plants.crewmembers_killed_by_indians")) + 1;
				PChar.quest.mysterious_plants.crewmember.killed = true;
				
				AddXP(pchar, SKILL_FENCING, 500, XP_GROUP_OFFIC);
			}
			else
			{
				LAi_SetActorType(sld);
				LAi_SetActorType(PChar);
				sld.Dialog.CurrentNode = "Saved from Natives";
				LAi_ActorWaitDialog(PChar,sld);
				LAi_ActorDialog(sld, PChar, "", 1.0, 0);
				PChar.quest.mysterious_plants.crewmember.killed = false;
				AddXP(pchar, SKILL_LEADERSHIP, 1500, XP_GROUP_OFFIC);
				AddXP(pchar, SKILL_FENCING, 500, XP_GROUP_OFFIC);
			}
			PChar.quest.mysterious_plants.crewmember.attacked_tell_steven = true;
			LAi_UnStoreFantom(sld);
			DisableFastTravel(false);
			PChar.quest.Indian_Attack_Expired.win_condition.l1 = "Timer";
			PChar.quest.Indian_Attack_Expired.win_condition.l1.date.day = GetAddingDataDay(0, 0, 1);
			PChar.quest.Indian_Attack_Expired.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			PChar.quest.Indian_Attack_Expired.win_condition.l1.date.year = GetAddingDataYear(0, 0, 1);
			PChar.quest.Indian_Attack_Expired.win_condition = "Crewmember Attack Expired for Guards";
		break;
		
		case "Crewmember Attack Expired for Guards":
			PChar.quest.mysterious_plants.crewmember_killed.expired = true;
			DeleteAttribute(&PChar,"quest.mysterious_plants.crewmember.attacked_tell_steven");//PW if day passed too late for steven too
			PChar.quest.mysterious_plants.reported_crime = false;//PW to skip crewmember_killed tests to allow warehouse related tests in GreenfordCommander dialogue
		break;
		
		case "Apothecary Crewmember goes to ship":
			LAi_SetPlayerType(PChar);
			AddQuestRecord("plants", 14);
			LAi_ActorRunToLocation(&characters[sti(PChar.quest.mysterious_plants.crewmember)], "reload", "reload1", "none", "", "", "", 45.0);
			//DeleteAttribute(&PChar,"quest.mysterious_plants.crewmember");
		break;
		
		case "Reported Indians to guards":
			AddQuestRecord("plants", 15);
			AddXP(pchar, SKILL_LEADERSHIP, 500, XP_GROUP_OFFIC);
			ChangeRMRelation(PChar, GetCurrentLocationNation(), 1);
			PChar.quest.mysterious_plants.reported_crime = true;
		break;
		
		case "Ship Guarded":
			If (CheckAttribute(PChar,"quest.mysterious_plants.guard_ship"))//PW else truce in place now so no indians
			{	
				for (i = 0; i <= 4; i++)
				{
					if(CheckAttribute(PChar,"quest.Kill_Indian_Guards"+i))
					DeleteAttribute(PChar,"quest.Kill_Indian_Guards"+i);
				}
				int numindians = 2+rand(2);
				int level = 10;
				for (i = 0; i <= numindians; i++)
				{
					indianid = 1+rand(2);
					if(GetAttribute(Pchar,"quest.mysterious_plants.indians.killed") > 6)
					{
						level = 10 + 6-sti(GetAttribute(Pchar,"quest.mysterious_plants.indians.killed"))*2; //The level will increase at some point so this isn't an infinite XP farm
					}
					sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", level, true, 1.0, "indian"+indianid, "goto", LAi_FindRandomLocator("goto"));
					//GiveItem2Character(sld,"tomahawk");//PW make doubly sure they are always armed!!

					if(rand(99>50) || GetAttribute(Pchar,"quest.mysterious_plants.indians.killed") > 3)
					{
						//LAi_SetWarriorType(sld);
						//LAi_warrior_SetStay(sld, 1);
						LAi_SetCivilianGuardianType(sld);
					}
					else
					{
						LAi_SetPoorType(sld);
					}
					sld.Dialog.Filename = "Indian Guard.c";
					sld.Dialog.CurrentNode = "First time";
					LAi_group_MoveCharacter(sld, "IndianGuards"+i);
					LAi_group_SetRelation("IndianGuards"+i, LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
					//LAi_group_SetAlarmReaction("IndianGuards"+i, LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL, LAI_GROUP_ENEMY);

					if(GetAttribute(Pchar,"quest.mysterious_plants.indians.killed") > 8) 
					{
						LAi_group_FightGroups("IndianGuards"+i, LAI_GROUP_PLAYER,true);
						LAi_group_FightGroups(LAI_GROUP_PLAYER, "IndianGuards"+i,true);
						if(!CheckAttribute(pchar,"quest.mysterious_plants.indians.onsight"))
						{
							AddQuestRecord("plants",32);
							pchar.quest.mysterious_plants.indians.onsight = true;
						}
					}

					if(GetAttribute(Pchar,"quest.mysterious_plants.indians.killed") > 30) //Killing all ambushes and doing the smugglers quest will still not get you over this number. So if you do you are just killing them for fun and/or XP so you deserve to get punished
					{
						LAi_SetImmortal(sld,true); //You asked for it
					}
					string conditioncase = "Kill_Indian_Guards"+i;

					Pchar.quest.(conditioncase).win_condition.l1 = "NPC_Death";
					Pchar.quest.(conditioncase).win_condition.l1.character = sld.id;
					Pchar.quest.(conditioncase).win_condition = "Kill Indian Guard";
				}
				for (i = 0; i <= numindians; i++)
				{
					for (j = 0; j <= numindians; j++)
					{
						LAi_group_SetRelation("IndianGuards"+i, "IndianGuards"+j, LAI_GROUP_NEUTRAL);
						//LAi_group_SetAlarmReaction("IndianGuards"+i, "IndianGuards"+j, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY);
					}
				}

				pchar.quest.Apothecary_Guard_Ship_reset.win_condition.l1 = "ExitFromLocation";
				pchar.quest.Apothecary_Guard_Ship_reset.win_condition.l1.location = "Greenford_port";
				pchar.quest.Apothecary_Guard_Ship_reset.win_condition = "Set Guard Again";
			}
		break;
		
		case "Set Guard Again":
			//Also clear kill conditions
			DeleteAttribute(&pchar,"quest.Kill_Indian_Guards0");
			DeleteAttribute(&pchar,"quest.Kill_Indian_Guards1");
			DeleteAttribute(&pchar,"quest.Kill_Indian_Guards2");
			DeleteAttribute(&pchar,"quest.Kill_Indian_Guards3");
			if(CheckAttribute(PChar,"quest.mysterious_plants.guard_ship"))
			{
				Pchar.quest.Apothecary_Guard_Ship.win_condition.l1 = "location";
				Pchar.quest.Apothecary_Guard_Ship.win_condition.l1.character = PChar.id;
				Pchar.quest.Apothecary_Guard_Ship.win_condition.l1.location = "Greenford_port";
				Pchar.quest.Apothecary_Guard_Ship.win_condition = "Ship Guarded";
			}
		break;
		
		case "Kill Indian Guard":
			if(PChar.location == "Greenford_port")
			{
				i = sti(GetAttribute(Pchar,"quest.mysterious_plants.indians.killed")) + 1;
				Pchar.quest.mysterious_plants.indians.killed = i;
			}
		break;
		
		case "Apothecary Meet In Tavern":
			AddQuestRecord("plants", 16);
			pchar.quest.mysterious_plants.heard_job = "talk to captain";
			//DisableFastTravel(true);
			//DisableMenuLaunch(true);
			Pchar.quest.Apothecary_Meet_Tavern.win_condition.l1 = "location";
			Pchar.quest.Apothecary_Meet_Tavern.win_condition.l1.character = PChar.id;
			Pchar.quest.Apothecary_Meet_Tavern.win_condition.l1.location = "Greenford_tavern";
			Pchar.quest.Apothecary_Meet_Tavern.win_condition = "Apothecary Set Up Meeting Captain";
		break;
		
		case "Apothecary Set Up Meeting Captain":
			indianid = 1+rand(2);
			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "indian"+indianid, "goto", "goto8");
			//sld.id = "IndianSpy";
			GiveItem2Character(sld,"tomahawk");//PW make doubly sure they are always armed!!
			Pchar.quest.mysterious_plants.indianspy = sld.index;
			LAi_SetStayType(sld);
			LAi_StoreFantom(sld);
			sld.Dialog.Filename = "Indian Guard.c";
			sld.Dialog.CurrentNode = "First time";
			//pchar.quest.apothecary_killed_spy.win_condition.l1 = "NPC_Death";//PW moved from case Apothecary indian left
		//	pchar.quest.apothecary_killed_spy.win_condition.l1.character = sld.id;
			//pchar.quest.apothecary_killed_spy.win_condition.l1.character = "Apothecary Killed Indian Spy";
			sld = characterFromID("Robert Cook");
			LAi_SetStayType(sld);
			ChangeCharacterAddressGroup(sld,pchar.location,"goto","goto2");
			sld.Dialog.Filename = "apothecary_quest.c";
			sld.Dialog.CurrentNode = "Talk about plan";
		break;
		
		case "Apothecary Meet At Lighthouse":
			LAi_SetActorType(pchar);
			sld = characterFromID("Robert Cook");
			LAi_SetActorType(sld);
			LAi_ActorRunToLocation(sld,"reload","reload1","Oxbay_Lighthouse","goto","goto1","Apothecary Trigger Indian",10);
			SetCharacterShipLocation(sld, "Oxbay_Lighthouse");
			pchar.quest.Arrived_At_Lighthouse.win_condition.l1 = "location";
			pchar.quest.Arrived_At_Lighthouse.win_condition.l1.location = "Oxbay_Lighthouse";
			pchar.quest.Arrived_At_Lighthouse.win_condition = "Prepare Apothecary Ambush Lighthouse";
		break;
		
		case "Apothecary Trigger Indian":
			locations[FindLocation("Greenford_suburb")].reload.l8.disable = 1;//PW lock warehouse to stop you going ahead before the indian once you know where
			locations[FindLocation("Greenford_suburb")].reload.l13.disable = 1;//PW lock warehouse to stop you going ahead before the indian once you know where
			LAi_ActorTurnToLocator(pchar,"goto","goto8");
			sld = &characters[sti(Pchar.quest.mysterious_plants.indianspy)];
			LAi_SetActorType(sld);
			LAi_QuestDelay("turn_to_indianspy",1);
			LAi_ActorRunToLocation(sld,"reload","reload1","none","","","Apothecary Indian Left",10);
			LAi_QuestDelay("turn_to_indianspy",2);		//JRH: see what that indian's up to
			LAi_QuestDelay("turn_to_indianspy",3);
			LAi_QuestDelay("turn_to_indianspy",4);
			//LAi_QuestDelay("turn_to_indianspy",5);
			//LAi_QuestDelay("turn_to_indianspy",6);
			//LAi_QuestDelay("turn_to_indianspy",7);
			//LAi_QuestDelay("turn_to_indianspy",8);
			//LAi_QuestDelay("turn_to_indianspy",9);
		break;
	//JRH -->
		case "turn_to_indianspy":
			sld = &characters[sti(Pchar.quest.mysterious_plants.indianspy)];
			LAi_ActorTurnToCharacter(PChar, sld);
		break;
	//<-- JRH
		case "Apothecary Indian Left":
			LAi_SetPlayerType(pchar);
			AddQuestRecord("plants", 17);
			Locations[FindLocation("Greenford_town")].vcskip = true; //Added to make sure the questscene works
			pchar.quest.apothecary_follow_indian.win_condition.l1 = "ExitFromLocation";
			pchar.quest.apothecary_follow_indian.win_condition.l1.location = "Greenford_tavern";
			pchar.quest.apothecary_follow_indian.win_condition = "Apothecary Follow Indian";
			pchar.quest.killed_spy.win_condition.l1 = "NPC_Death";//PW doesn't currently work?
			PChar.quest.killed_spy.win_condition.l1.character = &characters[sti(Pchar.quest.mysterious_plants.indianspy)].id;
			pchar.quest.killed_spy.win_condition.l1.character = "Apothecary Killed Indian Spy";
		break;
		
		case "Apothecary Found Follow"://PW called from indian guard dialog
			DeleteAttribute(&Locations[FindLocation("Greenford_town")],"vcskip");
			//DeleteAttribute(&pchar,"quest.mysterious_plants.indianspy");
			//LAi_UnStoreFantom(&characters[sti(Pchar.quest.mysterious_plants.indianspy)]);
			AddQuestRecord("plants", 18);
			//locations[FindLocation("Greenford_suburb")].reload.l8.disable = 0;//PW unlock warehouse now
			//locations[FindLocation("Greenford_suburb")].reload.l13.disable = 0;//PW unlock warehouse now
		break;
	

		case "Apothecary Killed Indian Spy":
			DeleteAttribute(&Locations[FindLocation("Greenford_town")],"vcskip");
			DeleteAttribute(&Locations[FindLocation("Greenford_suburb")],"vcskip");//PW could have reached here before killed
			
			LAi_UnStoreFantom(&characters[sti(Pchar.quest.mysterious_plants.indianspy)]);
			DeleteAttribute(&pchar,"quest.mysterious_plants.indianspy");
			i = sti(GetAttribute(Pchar,"quest.mysterious_plants.indians.killed")) + 1;
			Pchar.quest.mysterious_plants.indians.killed = i;
			PChar.quest.mysterious_plants.spy.killed = true;//PW attribute for conversation with steven to setup warehouse etc
			AddQuestRecord("plants", 41);
			//if(!pchar.location == "Greenford_suburb")
			
			DeleteAttribute(pchar,"quest.Apothecary_indian_detour");//PW stop blockade indian so not set twice depending where you killed spy
			//StopBlockadeCheck("Greenford_suburb");
		//	Building_delete(&Locations[FindLocation("Greenford_suburb")], pchar.quest.mysterious_plants.baricade.l1);
		//	Building_delete(&Locations[FindLocation("Greenford_suburb")], pchar.quest.mysterious_plants.baricade.l2);
		//	Building_delete(&Locations[FindLocation("Greenford_suburb")], pchar.quest.mysterious_plants.baricade.l3);
		//	Building_delete(&Locations[FindLocation("Greenford_suburb")], pchar.quest.mysterious_plants.baricade.l4);
			locations[FindLocation("Greenford_suburb")].reload.l8.disable = 0;//PW unlock warehouse now
			locations[FindLocation("Greenford_suburb")].reload.l13.disable = 0;//PW unlock warehouse now
		break;
		
		case "Apothecary Follow Indian":
			if(pchar.location == "Greenford_town") //PW To check you left tavern after indian(not went up to room or fast travel to ship)
			{
				if(CheckAttribute(pchar,"quest.mysterious_plants.indianspy"))
				{
					//ChangeCharacterAddressGroup(&characters[sti(Pchar.quest.mysterious_plants.indianspy)],"Greenford_town","reload","reload7");
					ChangeCharacterAddressGroup(&characters[sti(Pchar.quest.mysterious_plants.indianspy)],"Greenford_town","goto","goto14");
					
					LAi_ActorRunToLocator(&characters[sti(Pchar.quest.mysterious_plants.indianspy)],"goto","goto30","",20);
					sld = &characters[sti(Pchar.quest.mysterious_plants.indianspy)];
					LAi_SetActorType(sld);		
					sld.Dialog.Filename = "Indian Guard.c";
					sld.Dialog.CurrentNode = "Following";
					SetCharacterTask_None(sld);
					LAi_SetActorType(sld);
					LAi_ActorDialog(sld, Pchar, "Apothecary Follow Indian 2",10, 0);
				}
			}
			else  //PW stuff to set warehouse scene if you didn't follow indian
			{
					pchar.quest.mysterious_plants.No_Follow = true;//PW Setting attribute opens dialogue line with Steven - reset done through that otherwise not reset
			}
		break;
		
		case "Apothecary Follow Indian 2":
			if(CheckAttribute(pchar,"quest.mysterious_plants.indianspy"))
			{
				LAi_type_actor_Reset(&characters[sti(Pchar.quest.mysterious_plants.indianspy)]);
				LAi_ActorRunToLocator(&characters[sti(Pchar.quest.mysterious_plants.indianspy)],"goto","goto33","",8);
				LAi_QuestDelay("Apothecary Follow Indian 3",7);
			}
		break;
		
		case "Apothecary Follow Indian 3":
			if(CheckAttribute(pchar,"quest.mysterious_plants.indianspy"))
			{
				LAi_type_actor_Reset(&characters[sti(Pchar.quest.mysterious_plants.indianspy)]);
				LAi_ActorRunToLocation(&characters[sti(Pchar.quest.mysterious_plants.indianspy)],"reload","reload19","none","","","",20);
			}
			LAi_QuestDelay("Apothecary Build Obstacles",0);
			Locations[FindLocation("Greenford_suburb")].vcskip = true; //Added to make sure the questscene works
			pchar.quest.apothecary_follow_indian.win_condition.l1 = "ExitFromLocation";
			pchar.quest.apothecary_follow_indian.win_condition.l1.location = "Greenford_town";
			pchar.quest.apothecary_follow_indian.win_condition = "Apothecary Follow Indian 5";
		break;
		
		case "Apothecary Build Obstacles"://PW blockade to stop direct access to warehouse rear
			lcn = &Locations[FindLocation("Greenford_suburb")];
			cidx = -1;
			for(i = 1; i<=MAXBUILDINGS; i++)
			{
				attr = "building."+i+".building";
				if( !CheckAttribute(lcn,attr) && cidx < 0)
				{
					cidx = i;
				}
			}
			string buildingid = ""+cidx;
			pchar.quest.mysterious_plants.baricade.l1 = buildingid;
			lcn.building.(buildingid).building = "box";
			lcn.building.(buildingid).interior = "";
			lcn.building.(buildingid).x = -27.167;
			lcn.building.(buildingid).y =  1;
			lcn.building.(buildingid).z = 34.291;
			lcn.building.(buildingid).ay = 0;
			lcn.building.(buildingid).aigroup = "blockade";
			cidx += 1;
			buildingid = ""+cidx;
			pchar.quest.mysterious_plants.baricade.l2 = buildingid;
			lcn.building.(buildingid).building = "box";
			lcn.building.(buildingid).interior = "";
			lcn.building.(buildingid).x = -28.296;
			lcn.building.(buildingid).y = 1;
			lcn.building.(buildingid).z = 33.846;
			lcn.building.(buildingid).ay = 0;
			lcn.building.(buildingid).aigroup = "blockade";
			cidx += 1;
			buildingid = ""+cidx;
			pchar.quest.mysterious_plants.baricade.l3 = buildingid;
			lcn.building.(buildingid).building = "bale";
			lcn.building.(buildingid).interior = "";
			lcn.building.(buildingid).x = -27.458;
			lcn.building.(buildingid).y = 1;
			lcn.building.(buildingid).z = 33.549;
			lcn.building.(buildingid).ay = 0;
			lcn.building.(buildingid).aigroup = "blockade";
			cidx += 1;
			buildingid = ""+cidx;
			pchar.quest.mysterious_plants.baricade.l4 = buildingid;
			lcn.building.(buildingid).building = "bale";
			lcn.building.(buildingid).interior = "";
			lcn.building.(buildingid).x = -27.963;
			lcn.building.(buildingid).y = 1;
			lcn.building.(buildingid).z = 34.571;
			lcn.building.(buildingid).ay = 0;
			lcn.building.(buildingid).aigroup = "blockade";
			//TraceAndLog("blockade");
			If ((CheckAttribute(PChar,"quest.mysterious_plants.No_Follow"))  || (CheckAttribute(PChar,"quest.mysterious_plants.spy.killed")))
				{
				LAi_QuestDelay("Setup Warehouse",0);
				DeleteAttribute(&pchar, "quest.mysterious_plants.No_Follow");
				DeleteAttribute(&pchar, "quest.mysterious_plants.spy.killed");
				//TraceAndLog("blockade2");
				}
		break;
		
		case "Apothecary Follow Indian 5":
			LAi_type_actor_Reset(&characters[sti(Pchar.quest.mysterious_plants.indianspy)]);
			DeleteAttribute(&Locations[FindLocation("Greenford_town")],"vcskip");// PW restore NPCs in town area
			
			sld = &characters[sti(Pchar.quest.mysterious_plants.indianspy)];
				if(LAi_IsDead(sld))//PW in case you kill the indian "spy" in greenford town (condition didn't seem to work?)
				{
					LAi_QuestDelay("Apothecary Killed Indian Spy",0);
				}
			if(pchar.location == "Greenford_suburb" && CheckAttribute(pchar,"quest.mysterious_plants.indianspy"))
			//PW called on exit from greenford town activates if you followed indian to suburb (ie first exit you use from town during follow)
			{
				
				
					LAi_type_actor_Reset(&characters[sti(Pchar.quest.mysterious_plants.indianspy)]);
					ChangeCharacterAddressGroup(&characters[sti(Pchar.quest.mysterious_plants.indianspy)],"Greenford_suburb","reload","door_3");//PW was reload_3_3_back
					LAi_ActorRunToLocator(&characters[sti(Pchar.quest.mysterious_plants.indianspy)],"goto","goto14","",20);
					LAi_QuestDelay("Apothecary Follow Indian 6",10);
					//StartBlockadeCheck("Greenford_suburb");//PW moved to next case since get reduction in response due to running check
				
					pchar.quest.Apothecary_indian_detour.win_condition.l1 = "locator";
					pchar.quest.Apothecary_indian_detour.win_condition.l1.location = pchar.location;
					pchar.quest.Apothecary_indian_detour.win_condition.l1.locator_group = "reload";
					pchar.quest.Apothecary_indian_detour.win_condition.l1.locator = "door_15";
					pchar.quest.Apothecary_indian_detour.win_condition = "Apothecary Not This Way";
			}
			else
			{
			//PW stuff to reset warehouse scene if you lost the indian by entering some other location than suburb 
			//PW Setting attribute opens dialogue line with Steven - reset done through that otherwise not reset
			//PW blockade should already be set (but not checked)
			
			PChar.quest.mysterious_plants.Lost_Indian = true;
			//TraceAndLog("lost indian");
			//AddQuestRecord("plants", 18);
			}


		break;
		
		case "Apothecary Follow Indian 6":
			if(CheckAttribute(pchar,"quest.mysterious_plants.indianspy"))
			{
				LAi_type_actor_Reset(&characters[sti(Pchar.quest.mysterious_plants.indianspy)]);
				LAi_ActorRunToLocator(&characters[sti(Pchar.quest.mysterious_plants.indianspy)],"goto","goto22","",20);
				LAi_QuestDelay("Apothecary Follow Indian 7",15);
			}
			StartBlockadeCheck("Greenford_suburb");//PW moved from previous case
			pchar.quest.mysterious_plants.blockade = "set";
		break;
		
		case "Apothecary Follow Indian 7":
			if(CheckAttribute(pchar,"quest.mysterious_plants.indianspy"))
			{
				LAi_type_actor_Reset(&characters[sti(Pchar.quest.mysterious_plants.indianspy)]);
				LAi_ActorRunToLocator(&characters[sti(Pchar.quest.mysterious_plants.indianspy)],"goto","goto44","",20);
				LAi_QuestDelay("Apothecary Follow Indian 8",12);
			}
		break;
		
		case "Apothecary Follow Indian 8":
			if(CheckAttribute(pchar,"quest.mysterious_plants.indianspy"))
			{
				LAi_type_actor_Reset(&characters[sti(Pchar.quest.mysterious_plants.indianspy)]);
				LAi_ActorRunToLocator(&characters[sti(Pchar.quest.mysterious_plants.indianspy)],"officers","door_1_3","",10);
				LAi_QuestDelay("Apothecary Follow Indian 9",1);
			}
		break;
		
		case "Apothecary Follow Indian 9":
			if(CheckAttribute(pchar,"quest.mysterious_plants.indianspy"))
			{
				LAi_type_actor_Reset(&characters[sti(Pchar.quest.mysterious_plants.indianspy)]);
				LAi_ActorRunToLocation(&characters[sti(Pchar.quest.mysterious_plants.indianspy)],"reload","door_1","none","","","Apothecary Follow Indian End",20);
			}
			locations[FindLocation("Greenford_suburb")].reload.l8.disable = 0;//PW unlock warehouse now
			locations[FindLocation("Greenford_suburb")].reload.l13.disable = 0;//PW unlock warehouse now
		break;
		
		case "Apothecary Follow Indian End":
			
			DeleteAttribute(&Locations[FindLocation("Greenford_suburb")],"vcskip");//PW restore NPCs in suburb now
			DoQuickSave();			//JRH: as it crashes in the warehouse sometimes
			sld = &characters[sti(Pchar.quest.mysterious_plants.indianspy)];
			if(LAi_IsDead(sld))//PW in case you kill the indian "spy" in Greenford_suburb (condition didn't seem to work?)
			{
				LAi_QuestDelay("Apothecary Killed Indian Spy",0);
			}
			else
			{
			AddQuestRecord("plants", 19);
			AddXP(pchar, SKILL_ACCURACY, 500, XP_GROUP_OFFIC);
			AddXP(pchar, SKILL_SNEAK, 750, XP_GROUP_OFFIC);
			Locations[FindLocation("greenford_warehouse")].vcskip = true;
			
			Pchar.quest.mysterious_plants.setwarehouse = true;
			Pchar.quest.Apothecary_Enter_Warehouse.win_condition.l1 = "location";
			Pchar.quest.Apothecary_Enter_Warehouse.win_condition.l1.character = PChar.id;
			Pchar.quest.Apothecary_Enter_Warehouse.win_condition.l1.location = "greenford_warehouse";
			Pchar.quest.Apothecary_Enter_Warehouse.win_condition = "Apothecary entered warehouse";
			}
		break;
		

				
		case "Setup Warehouse"://PW setup warehouse (after dialog with steven) if you lost,killed or didn't follow indian 
			pchar.quest.Apothecary_indian_detour.win_condition.l1 = "locator";
			pchar.quest.Apothecary_indian_detour.win_condition.l1.location = "Greenford_suburb";
			pchar.quest.Apothecary_indian_detour.win_condition.l1.locator_group = "reload";
			pchar.quest.Apothecary_indian_detour.win_condition.l1.locator = "door_15";
			pchar.quest.Apothecary_indian_detour.win_condition = "Apothecary Not This Way";

			Pchar.quest.Apothecary_Enter_Warehouse.win_condition.l1 = "location";
			Pchar.quest.Apothecary_Enter_Warehouse.win_condition.l1.character = PChar.id;
			Pchar.quest.Apothecary_Enter_Warehouse.win_condition.l1.location = "greenford_warehouse";
			Pchar.quest.Apothecary_Enter_Warehouse.win_condition = "Apothecary entered warehouse";
			
			AddQuestRecord("plants", 42);
			DeleteAttribute(&Locations[FindLocation("Greenford_town")],"vcskip");// PW restore NPCs in town area
			locations[FindLocation("Greenford_suburb")].reload.l8.disable = 0;//PW unlock warehouse now
			locations[FindLocation("Greenford_suburb")].reload.l13.disable = 0;//PW unlock warehouse now
			Locations[FindLocation("Greenford_suburb")].vcskip = true;
			Locations[FindLocation("greenford_warehouse")].vcskip = true;
			//PW use below attribute to prevent you telling greenford commander you followed indian to warehouse
			//will wipe when enter the warehouse (you then would have something to report)
			Pchar.quest.apothecary_no_follow_indian.win_condition.l1 = "location";
			Pchar.quest.apothecary_no_follow_indian.win_condition.l1.character = PChar.id;
			Pchar.quest.apothecary_no_follow_indian.win_condition.l1.location = "greenford_warehouse";
			Pchar.quest.apothecary_no_follow_indian.win_condition = "Setup Warehouse3";
					
//PW I think blockade check has to be set when in the location to function properly	
			pchar.quest.blockade.win_condition.l1 = "location";
			Pchar.quest.blockade.win_condition.l1.character = PChar.id;
			pchar.quest.blockade.win_condition.l1.location = "Greenford_suburb";
			pchar.quest.blockade.win_condition = "Reset Blockade";
			
		break;

		case "Reset Blockade"://PW I think it has to be set when in the location to function properly
			if (!CheckAttribute (pchar,"quest.mysterious_plants.blockade"))
			{
				StartBlockadeCheck("Greenford_suburb");
		
				//TraceAndLog("test blockade");
			}
		break;

		case "Setup Warehouse3"://PW 
			//PW just do something here really to do with removing apothecary_no_follow_indian.win_condition
			DeleteAttribute(&pchar, "quest.mysterious_plants.Lost_Indian");
		break;


		case "Reported Indians in Warehouse"://Report to Greenford commander clears warehouse scenes
			DeleteAttribute(&Pchar,"quest.Apothecary_Enter_Warehouse");
			
			LAi_QuestDelay("Apothecary Remove Baricade",0);
			PChar.quest.mysterious_plants.indians.safe = true;
			PChar.quest.mysterious_plants.reported_crime.inwarehouse = true;
			ChangeRMRelation(PChar, GetCurrentLocationNation(), 4);
			AddQuestRecord("plants", 28);
			AddXP(pchar, SKILL_LEADERSHIP, 1000, XP_GROUP_OFFIC);
		break;
		
		case "Apothecary Not This Way"://PW indian guarding warehouse rear
			LAi_SetActorType(Pchar);
			if(!CheckAttribute(Pchar,"quest.mysterious_plants.guardwarehouse"))
			{
				indianid = 1+rand(2);
				sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 1, true, 1.0, "indian"+indianid, "reload", "reload_1");
				GiveItem2Character(sld,"tomahawk");//PW make doubly sure they are always armed!!
				Pchar.quest.mysterious_plants.guardwarehouse = sld.index;
				LAi_StoreFantom(sld);
			}
			else
			{
				sld = &characters[sti(Pchar.quest.mysterious_plants.guardwarehouse)];
				ChangeCharacterAddressGroup(sld,pchar.location,"reload","reload_1");
			}
			sld.Dialog.Filename = "Indian Guard.c";
			sld.Dialog.CurrentNode = "Spotted warehouse";
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(Pchar,"reload","reload_1");
			LAi_ActorWaitDialog(PChar, sld);
			LAi_ActorDialog(sld,pchar,"",1.0,0);
		break;
		
		case "Apothecary seen by guard warehouse"://PW indian guarding warehouse rear
			LAi_ActorRunToLocator(PChar,"reload","reload_1","Apothecary let's try it again",-1);
			sld = &characters[sti(Pchar.quest.mysterious_plants.guardwarehouse)];
			LAi_ActorRunToLocator(sld,"reload","door_14","",-1);
		break;
		
		case "Apothecary let's try it again"://PW indian guarding warehouse rear
			sld = &characters[sti(Pchar.quest.mysterious_plants.guardwarehouse)];
			ChangeCharacterAddressGroup(sld,"none","","");
			LAi_SetPlayerType(PChar);
			if(!CheckAttribute(Pchar,"quest.mysterious_plants.seenbywarehouseguard"))
			{
				AddQuestRecord("plants", 20);
				Pchar.quest.mysterious_plants.seenbywarehouseguard = true;
			}
			pchar.quest.Apothecary_indian_detour.win_condition.l1 = "locator";
			pchar.quest.Apothecary_indian_detour.win_condition.l1.location = pchar.location;
			pchar.quest.Apothecary_indian_detour.win_condition.l1.locator_group = "reload";
			pchar.quest.Apothecary_indian_detour.win_condition.l1.locator = "door_15";
			pchar.quest.Apothecary_indian_detour.win_condition = "Apothecary Not This Way";
		break;
		
		case "Apothecary entered warehouse":
			//First check trough which door we came
			StopBlockadeCheck ("Greenford_suburb");
			DeleteAttribute(&Locations[FindLocation("greenford_warehouse")],"vcskip");
			if(PChar.location.locator == "reload1")
			{
				//Front Door: This means ambush time
				//Lock the doors

				Locations[FindLocation(PChar.location)].reload.l1.disable = true;
				Locations[FindLocation(PChar.location)].reload.l2.disable = true;//PW was duplicate l1
				//Make the ambush 12 8 7 6
				indianid = 1+rand(2);
				sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 20, true, 1.0, "indian"+indianid, "goto", "goto2");
				GiveItem2Character(sld,"indian_treasure_note");
				GiveItem2Character(sld,"tomahawk");//PW make doubly sure they are always armed!!
				LAi_group_MoveCharacter(sld, "Indian Ambush");
				Pchar.quest.mysterious_plants.indianambush.indian0 = sld.index;
				indianid = 1+rand(2);
				sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 20, true, 1.0, "indian"+indianid, "goto", "goto12");
				GiveItem2Character(sld,"tomahawk");//PW make doubly sure they are always armed!!
				LAi_group_MoveCharacter(sld, "Indian Ambush");
				Pchar.quest.mysterious_plants.indianambush.indian1 = sld.index;
				indianid = 1+rand(2);
				sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 20, true, 1.0, "indian"+indianid, "goto", "goto8");
				GiveItem2Character(sld,"tomahawk");//PW make doubly sure they are always armed!!
				LAi_group_MoveCharacter(sld, "Indian Ambush");
				Pchar.quest.mysterious_plants.indianambush.indian2 = sld.index;
				indianid = 1+rand(2);
				sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 20, true, 1.0, "indian"+indianid, "goto", "goto7");
				GiveItem2Character(sld,"tomahawk");//PW make doubly sure they are always armed!!
				LAi_group_MoveCharacter(sld, "Indian Ambush");
				Pchar.quest.mysterious_plants.indianambush.indian3 = sld.index;
				indianid = 1+rand(2);
				sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 20, true, 1.0, "indian"+indianid, "goto", "goto6");
				GiveItem2Character(sld,"tomahawk");//PW make doubly sure they are always armed!!
				LAi_group_MoveCharacter(sld, "Indian Ambush");
				Pchar.quest.mysterious_plants.indianambush.indian4 = sld.index;
				//Only get help if you saved your crewmember
				if(GetAttribute(Pchar,"quest.mysterious_plants.crewmember.killed") == false)
				{
					LAi_QuestDelay("PreProcess Cavalry Apothecary",0); //Let's generate the characters already
					LAi_QuestDelay("Apothecary enter the Cavalry",20); //You have to survive 20 seconds
				}
				//Start fighting
				LAi_group_FightGroups(LAI_GROUP_PLAYER, "Indian Ambush", true);
				LAi_QuestDelay("Hide Indian Treasure Random",0);
				PChar.quest.apothecary_fight_mob.win_condition.l1 = "Group_Death";
				PChar.quest.apothecary_fight_mob.win_condition.l1.group = "Indian Ambush";
				PChar.quest.apothecary_fight_mob.win_condition = "Apothecary Defeated Ambush";
				AddQuestRecord("plants", 21);
			}
			
			if(PChar.location.locator == "reload2")
			{
				//Back Door: This means we can overhear them talk but first let's get to a safe location.
				LAi_QuestDelay("Apothecary Sneak in Warehouse",0);
				sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 20, true, 1.0, "indian1", "goto", "goto1");
				GiveItem2Character(sld,"indian_treasure_note");
				GiveItem2Character(sld,"tomahawk");//PW make doubly sure they are always armed!!
				LAi_SetActorType(sld);
				LAi_ActorTurnToLocator(sld,"reload","reload1");
				sld.Dialog.Filename = "apothecary_quest.c";
				Pchar.quest.mysterious_plants.indianambush.indian0 = sld.index;
				LAi_group_MoveCharacter(sld, "Indian Ambush");
				indianid = 1+rand(2);
				sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 20, true, 1.0, "indian2", "goto", "goto2");
				GiveItem2Character(sld,"tomahawk");//PW make doubly sure they are always armed!!
				LAi_ActorTurnToLocator(sld,"goto","goto1");
				Pchar.quest.mysterious_plants.indianambush.indian1 = sld.index;
				sld.Dialog.Filename = "apothecary_quest.c";
				LAi_SetActorType(sld);
				LAi_group_MoveCharacter(sld, "Indian Ambush");
			}
			LAi_QuestDelay("Apothecary Remove Baricade",0);
			DeleteAttribute(&PChar,"quest.mysterious_plants.crewmember.killed");//PW moved here so .Killed can persist up to here if you want to tell Greenford_commander up to here
			pchar.quest.mysterious_plants.reported_crime = false;//PW so that attribute exists if you didn't report before now you don't report the crewmember attack but either their use of the warehouse or conversation.
		break;
		
		case "PreProcess Cavalry Apothecary":
			for (i = 0; i <= 8; i++)//PW some comments that warehouse far too crowded was 15 now 8
			{
				sld = LAi_CreateFantomCharacterExOt(true, GetBoardingCrewType(PChar), sti(pchar.rank), false, 0.0, LAi_GetBoardingModel(PChar, ""), "goto", "goto11");
				EquipFromLocker(sld);
				CheckCharacterCurse(sld);
				ChangeCharacterAddressGroup(sld,"none","","");
				Pchar.quest.mysterious_plants.crewhelp = i;
				string crewhelpid = "crewmember"+i;
				Pchar.quest.mysterious_plants.crewhelp.(crewhelpid) = sld.index;
			}
		break;
		
		case "Apothecary enter the Cavalry":
			//This should help you survive the battle
			AddXP(pchar, SKILL_LEADERSHIP, 1000, XP_GROUP_OFFIC);
			if(!CheckAttribute(Pchar,"quest.mysterious_plants.won_ambush"))
			{
				for (i = 0; i <= sti(Pchar.quest.mysterious_plants.crewhelp); i++)
				{
					string crewhelpid2 = "crewmember"+i;
					sld = &characters[sti(Pchar.quest.mysterious_plants.crewhelp.(crewhelpid2))];
					ChangeCharacterAddressGroup(sld,Pchar.location,"reload","reload1");
					LAi_SetWarriorType(sld);
					LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);
					LAi_SetImmortal(sld,true); //We set them to immortal first untill the dialog is done
				}
				LAi_SetImmortal(Pchar,true);
				sld.Dialog.Filename = "apothecary_quest.c";
				sld.Dialog.CurrentNode = "Help During Ambush";
				LAi_SetActorType(Pchar);
				LAi_SetActorType(sld);
				LAi_ActorTurnToLocator(Pchar,"reload","reload1");
				LAi_ActorWaitDialog(PChar, sld);
				LAi_ActorDialog(sld,pchar,"",1.0,0);
				PlayStereoSound("OBJECTS\ABORDAGE\abordage_wining.wav");
				//Also the indians are set to immortal untill the dialog is done
				for (i = 0; i < 5; i++)
				{
					crewhelpid2 = "indian"+i;
					sld = &characters[sti(Pchar.quest.mysterious_plants.indianambush.(crewhelpid2))];
					LAi_SetImmortal(sld,true); //We set them to immortal first untill the dialog is done
				}
			}
			Pchar.quest.mysterious_plants.crewmembers_helped_ambush = true;
		break;
		
		case "Continue Apothecary Ambush":
			//Set everyone mortal again
			//If you are playing on a lower difficulty we keep your crew immortal so they are a better help here
			for (i = 0; i < 5; i++)
			{
				string crewhelpid3 = "indian"+i;
				sld = &characters[sti(Pchar.quest.mysterious_plants.indianambush.(crewhelpid3))];
				LAi_SetImmortal(sld,false);
			}
			if(GetDifficulty() >= DIFFICULTY_SEADOG)
			{
				for (i = 0; i <= sti(Pchar.quest.mysterious_plants.crewhelp); i++)
				{
					crewhelpid3 = "crewmember"+i;
					sld = &characters[sti(Pchar.quest.mysterious_plants.crewhelp.(crewhelpid3))];
					LAi_SetImmortal(sld,false);
					string conditioncase2 = "CrewMember_Killed_In_Ambush"+i;
					Pchar.quest.(conditioncase2).win_condition.l1 = "NPC_Death";
					Pchar.quest.(conditioncase2).win_condition.l1.character = sld.id;
					Pchar.quest.(conditioncase2).win_condition = "Apothecary Defeated Ambush";
				}
				//We keep the one crew member immortal because that one has to talk to us again once we've won.
				LAi_SetWarriorType(sld);
				LAi_SetImmortal(sld,true);
			}
			else
			{
				//Still need to set the one who talked to us back to warrior type
				crewhelpid3 = "crewmember"+8;//PW changed to match earlier loop number change was 15 now 8
				sld = &characters[sti(Pchar.quest.mysterious_plants.crewhelp.(crewhelpid3))];
				LAi_SetWarriorType(sld);
			}
			//Set Pchar again
			LAi_SetPlayerType(Pchar);
			LAi_SetFightMode(PChar, true); 
			LAi_QuestDelay("Continue Apothecary Ambush 2",2); //Give the player a little bit of time to look at the situation before he gets damage again.
		break;
		
		case "Continue Apothecary Ambush 2":
			LAi_SetImmortal(Pchar,false);
		break;
		
		case "Crewmember defeated during ambush":
			pchar.ship.crew.quantity = sti(pchar.ship.crew.quantity) - 1;
			if(sti(pchar.ship.crew.quantity) < 1)
			{
				pchar.ship.crew.quantity = 1; //There is at least 1 crewmember back at the ship
			}
			PChar.quest.mysterious_plants.crewmembers_killed_by_indians = sti(GetAttribute(PChar,"quest.mysterious_plants.crewmembers_killed_by_indians")) + 1;
		break;
		
		case "Apothecary Defeated Ambush":
			i = sti(GetAttribute(Pchar,"quest.mysterious_plants.indians.killed")) + 5;
			Pchar.quest.mysterious_plants.indians.killed = i;
			Pchar.quest.mysterious_plants.won_ambush = true;
			//Have dialog with crewmember again
			if(CheckAttribute(Pchar,"quest.mysterious_plants.crewmembers_helped_ambush"))
			{
				string crewhelpid6 = "crewmember"+8;//PW match loop size was 15 now 8
				sld = &characters[sti(Pchar.quest.mysterious_plants.crewhelp.(crewhelpid6))];
				sld.Dialog.CurrentNode = "Won Ambush";
				LAi_SetActorType(Pchar);
				LAi_SetActorType(sld);
				LAi_ActorWaitDialog(PChar, sld);
				LAi_ActorDialog(sld,pchar,"",5.0,0);
				AddQuestRecord("plants", 23);
			}
			else
			{
				AddQuestRecord("plants", 22);
			}
			//Delete Kill conditions
			for (i = 0; i <= sti(Pchar.quest.mysterious_plants.crewhelp); i++)
			{
				DeleteAttribute(&pchar,"quest.CrewMember_Killed_In_Ambush"+i);
			}
			//Unlock Doors Again
			Locations[FindLocation(PChar.location)].reload.l1.disable = false;
			Locations[FindLocation(PChar.location)].reload.l2.disable = false;//PW was duplicate l1
			//Some cleanup
			DeleteAttribute(&Locations[FindLocation("greenford_warehouse")],"vcskip");
			pchar.quest.Apothecary_Exit_Warehouse.win_condition.l1 = "ExitFromLocation";
			pchar.quest.Apothecary_Exit_Warehouse.win_condition.l1.location = Pchar.location;
			pchar.quest.Apothecary_Exit_Warehouse.win_condition = "Apothecary Exit Warehouse 3";
		break;
		
		case "Apothecary Exit Warehouse":
			LAi_SetPlayerType(Pchar);
			for (i = 0; i <= sti(Pchar.quest.mysterious_plants.crewhelp); i++)
			{
				string crewhelpid4 = "crewmember"+i;
				sld = &characters[sti(Pchar.quest.mysterious_plants.crewhelp.(crewhelpid4))];
				LAi_SetActorType(sld);
				LAi_ActorRunToLocator(sld,"reload","reload1","",-1);
			}
			LAi_QuestDelay("Apothecary Exit Warehouse 2",5);
		break;
		
		case "Apothecary Exit Warehouse 2":
			for (i = 0; i <= sti(Pchar.quest.mysterious_plants.crewhelp); i++)
			{
				string crewhelpid5 = "crewmember"+i;
				sld = &characters[sti(Pchar.quest.mysterious_plants.crewhelp.(crewhelpid5))];
				ChangeCharacterAddressGroup(sld,"none","","");
			}
		break;
		
		case "Apothecary Exit Warehouse 3":
			DeleteAttribute(&Pchar,"quest.mysterious_plants.crewhelp");
			DeleteAttribute(&Pchar,"quest.mysterious_plants.indianambush");
			DeleteAttribute(&Locations[FindLocation("greenford_warehouse")],"vcskip");
			PChar.quest.mysterious_plants.indians.safe = true;
		break;
		
		case "Apothecary Sneak in Warehouse":
			LAi_SetActorType(Pchar);
			LAi_ActorRunToLocator(Pchar,"goto","goto17","Apothecary Sneak in Warehouse 2",-1);
		break;
		
		case "Apothecary Sneak in Warehouse 2":
			LAi_ActorRunToLocator(Pchar,"goto","goto7","Apothecary Sneak in Warehouse 3",-1);
			sld = &characters[sti(Pchar.quest.mysterious_plants.indianambush.indian0)];
			LAi_ActorTurnToLocator(sld,"goto","goto2");
			sld = &characters[sti(Pchar.quest.mysterious_plants.indianambush.indian1)];
			LAi_ActorRunToLocator(sld,"goto","goto1","",-1);
		break;

		case "Apothecary Sneak in Warehouse 3":
			PChar.quest.mysterious_plants.talkingindian = "indian1";
			PChar.quest.mysterious_plants.node = "Indians Talk 1";
			sld = &characters[sti(Pchar.quest.mysterious_plants.indianambush.indian1)];
			sld.Dialog.CurrentNode = PChar.quest.mysterious_plants.node;
			LAi_type_actor_Reset(sld);
			LAi_ActorSetStayMode(sld);
			LAi_ActorSetSitMode(PChar);
			LAi_ActorWaitDialog(sld, PChar);
			LAi_ActorDialogNow(PChar,sld,"",-1);
		break;
		
		case "Apothecary Sneak in Warehouse Dialog":
			if(PChar.quest.mysterious_plants.talkingindian == "indian1")
			{
				PChar.quest.mysterious_plants.talkingindian = "indian0"
			}
			else
			{
				PChar.quest.mysterious_plants.talkingindian = "indian1"
			}
			string talkingindian = PChar.quest.mysterious_plants.talkingindian;
			sld = &characters[sti(Pchar.quest.mysterious_plants.indianambush.(talkingindian))];
			sld.Dialog.CurrentNode = PChar.quest.mysterious_plants.node;
			
			LAi_type_actor_Reset(sld);
			LAi_ActorSetStayMode(sld);
			LAi_ActorWaitDialog(sld, PChar);
			LAi_ActorDialogNow(PChar,sld,"",-1);
		break;
		
		case "Apothecary Sneak in Warehouse Fight":
			for (i = 0; i < 2; i++)
			{
				string crewhelpid7 = "indian"+i;
				sld = &characters[sti(Pchar.quest.mysterious_plants.indianambush.(crewhelpid7))];
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "Indian Ambush");
			}
			LAi_SetPlayerType(Pchar);
			LAi_SetFightMode(PChar, true); 
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "Indian Ambush", true);
			AddQuestRecord("plants", 25);
			DeleteAttribute(&Pchar,"quest.mysterious_plants.indianambush");
			DeleteAttribute(&Locations[FindLocation("greenford_warehouse")],"vcskip");
			Pchar.quest.Killed_Indian_Ambush.win_condition.l1 = "NPC_Death";
			Pchar.quest.Killed_Indian_Ambush.win_condition.l1.character = sld.id;
			Pchar.quest.Killed_Indian_Ambush.win_condition = "Apothecary Killed Indians Afterall";
		break;
		
		case "Apothecary Sneak in Warehouse Spotted":
			for (i = 0; i < 2; i++)
			{
				string crewhelpid8 = "indian"+i;
				sld = &characters[sti(Pchar.quest.mysterious_plants.indianambush.(crewhelpid8))];
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "Indian Ambush");
			}
			LAi_SetPlayerType(Pchar);
			LAi_SetFightMode(PChar, true); 
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "Indian Ambush", true);
			AddQuestRecord("plants", 27);
			DeleteAttribute(&Pchar,"quest.mysterious_plants.indianambush");
			DeleteAttribute(&Locations[FindLocation("greenford_warehouse")],"vcskip");
			Pchar.quest.Killed_Indian_Ambush.win_condition.l1 = "NPC_Death";
			Pchar.quest.Killed_Indian_Ambush.win_condition.l1.character = sld.id;
			Pchar.quest.Killed_Indian_Ambush.win_condition = "Apothecary Killed Indians Afterall";
		break;
		
		case "Apothecary Killed Indians Afterall":
			PChar.quest.mysterious_plants.indians.safe = true;
		break;
		
		case "Apothecary Sneak in Warehouse Away":
			LAi_type_actor_Reset(PChar);
			LAi_ActorRunToLocator(Pchar,"reload","reload2","Apothecary Sneak in Warehouse Away 2",-1);
			AddQuestRecord("plants", 26);
		break;
		
		case "Apothecary Sneak in Warehouse Away 2":
			LAi_SetPlayerType(Pchar);
			DoQuestReloadToLocation("Greenford_suburb", "reload", "door_14", "");
			DeleteAttribute(&Pchar,"quest.mysterious_plants.indianambush");
			DeleteAttribute(&Locations[FindLocation("greenford_warehouse")],"vcskip");
			PChar.quest.mysterious_plants.indians.safe = true;
			PChar.quest.mysterious_plants.indians.overheard = true;
			AddXP(pchar, SKILL_SNEAK, 1500, XP_GROUP_OFFIC);
		break;
		
		case "Reported Indians without Proof":
			PChar.quest.mysterious_plants.reported_crime.withoutproof = true;
			ChangeRMRelation(PChar, GetCurrentLocationNation(), 9);
			AddQuestRecord("plants", 29);
			AddXP(pchar, SKILL_LEADERSHIP, 500, XP_GROUP_OFFIC);
		break;
		
		case "Reported Indians with Proof":
			TakenItems(pchar,"vegetal",-10);
			PChar.quest.mysterious_plants.reported_crime.withproof = true;
			ChangeRMRelation(PChar, GetCurrentLocationNation(), 14);
			AddQuestRecord("plants", 30);
			AddQuestRecord("indian_treasure", 8);
			CloseQuestHeader("indian_treasure");
			AddXP(pchar, SKILL_LEADERSHIP, 1500, XP_GROUP_OFFIC);
		break;
		
		case "Apothecary Remove Baricade":
			DeleteAttribute(pchar,"quest.Apothecary_indian_detour");
			StopBlockadeCheck("Greenford_suburb");
			Building_delete(&Locations[FindLocation("Greenford_suburb")], pchar.quest.mysterious_plants.baricade.l1);
			Building_delete(&Locations[FindLocation("Greenford_suburb")], pchar.quest.mysterious_plants.baricade.l2);
			Building_delete(&Locations[FindLocation("Greenford_suburb")], pchar.quest.mysterious_plants.baricade.l3);
			Building_delete(&Locations[FindLocation("Greenford_suburb")], pchar.quest.mysterious_plants.baricade.l4);
		break;
		
		case "Prepare Apothecary Ambush Lighthouse":
			//Incase you leave we need to set it again
			pchar.quest.Arrived_At_Lighthouse.win_condition.l1 = "ExitFromLocation";
			pchar.quest.Arrived_At_Lighthouse.win_condition.l1.location = "Oxbay_Lighthouse";
			pchar.quest.Arrived_At_Lighthouse.win_condition = "Set Prepare Ambush Again";
			//Set Captain okay again
			sld = characterFromID("Robert Cook");
			LAi_SetStayType(sld);
			sld.Dialog.Filename = "apothecary_quest.c";
			if(isDay())
			{
				sld.Dialog.CurrentNode = "Arrived at Lighthouse during day";
			}
			else
			{
				if(pchar.location.from_sea == "Oxbay_Lighthouse")
				{
					sld.Dialog.CurrentNode = "Arrived at Lighthouse by sea";
				}
				else
				{
					sld.Dialog.CurrentNode = "Arrived at Lighthouse";
				}
			}
			//Generate the ambush already
			for (i = 0; i < 8; i++)
			{
				indianid = 1+rand(2);
				sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 20, true, 1.0, "indian"+indianid, "goto", "goto8");
				GiveItem2Character(sld,"tomahawk");//PW make doubly sure they are always armed!!
				attr = "indian"+i;
				pchar.quest.mysterious_plants.indianambush.(attr) = sld.index;
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "Indian Ambush");
				ChangeCharacterAddressGroup(sld,"none","",""); //hide them untill you talked with the captain
			}
		break;
		
		case "Set Prepare Ambush Again":
			pchar.quest.Arrived_At_Lighthouse.win_condition.l1 = "location";
			pchar.quest.Arrived_At_Lighthouse.win_condition.l1.location = "Oxbay_Lighthouse";
			pchar.quest.Arrived_At_Lighthouse.win_condition = "Prepare Apothecary Ambush Lighthouse";
		break;
		
		case "Apothecary Arrived at Lighthouse":
			//Some cleanup if you didn't follow the indian
			DeleteAttribute(&PChar,"quest.mysterious_plants.No_Follow");//PW added attributes
			DeleteAttribute(&PChar,"quest.mysterious_plants.Lost_Indian");//PW added attributes
			DeleteAttribute(&Locations[FindLocation("Greenford_warehouse")],"vcskip");
			LAi_QuestDelay("Apothecary Remove Baricade",0);
			//Let's see how you did
			if(CheckAttribute(PChar,"quest.mysterious_plants.indians.safe") && !isDay() && pchar.location.from_sea != "Oxbay_Lighthouse")
			{
				sld = characterFromID("Robert Cook");
				sld.Dialog.CurrentNode = "Depart To Columbia";
				LAi_SetActorType(sld);
				LAi_SetActorType(pchar);
				LAi_ActorWaitDialog(sld, PChar);
				LAi_ActorDialogNow(PChar,sld,"",-1);
			}
			else
			{
				LAi_SetActorType(pchar);
				LAi_ActorTurnToLocator(pchar,"ships_other","ship_1");
				Ship_Detonate(characterFromID("Robert Cook"), false, false);
				Ship_Serious_Boom(1, 1, 1);
				LAi_QuestDelay("Apothecary Explosion Again",2);
				LAi_QuestDelay("Apothecary Seen Ship Blow Up",4);
			}
		break;
		
		case "Apothecary Explosion Again":
			Ship_Detonate(characterFromID("Robert Cook"), false, false);
			Ship_Serious_Boom(1, 1, 1);
		break;
		
		case "Apothecary Seen Ship Blow Up":
			sld = characterFromID("Robert Cook");
			sld.Dialog.CurrentNode = "Ship Blow Up";
			LAi_ActorWaitDialog(sld, PChar);
			LAi_ActorDialogNow(PChar,sld,"",-1);
		break;
		
		case "Apothecary Indians Attack at Lighthouse":
			LAi_SetPlayerType(PChar);
			sld = characterFromID("Robert Cook");
			LAi_SetImmortal(sld,true); //We don't want armada get killed by some natives.
			LAi_SetActorType(sld);
			LAi_ActorRunToLocation(sld,"reload","reload1","none","","","Apothecary Lighthouse Give Up",45.0);
			for (i = 0; i < 8; i++)
			{
				attr = "indian"+i;
				sld = &characters[sti(pchar.quest.mysterious_plants.indianambush.(attr))];
				LAi_SetWarriorType(sld);
				if(rand(99) > 50)
				{
					TakeNItems(sld,"curare",1+rand(4));
				}
				else
				{
					TakeNItems(sld,"tar",1+rand(4));
				}
				ChangeCharacterAddressGroup(sld,pchar.location,"goto","goto8");
				LAi_group_MoveCharacter(sld, "Indian Ambush");
			}
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "Indian Ambush", true);
		break;
		
		case "Apothecary Lighthouse Give Up":
			AddQuestRecord("plants", 31);
			PChar.quest.mysterious_plants.give_up = "true";
			DeleteAttribute(&PChar,"quest.Apothecary_Enter_Warehouse");//PW remove added attributes so no dialogue with Steven about warehouse
		break;
		
		case "At Steven while Giving Up 1":
			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD, "isIndian","","", 20, true, 1.0, "indian1", "reload", "reload1");
			GiveItem2Character(sld,"tomahawk");
			LAi_StoreFantom(sld);
			LAi_SetActorType(sld);
			LAi_SetActorType(PChar);
			PChar.quest.mysterious_plants.give_up.indian = sld.index;
			sld.Dialog.Filename = "apothecary_quest.c";
			sld.Dialog.CurrentNode = "Give Up 2";
			LAi_ActorWaitDialog(PChar,sld);
			LAi_ActorDialog(sld, PChar, "", 1.0, 0);
		break;
		
		case "At Steven while Giving Up 2":
			sld = &characters[GetCharacterIndex("Apothecary")];
			LAi_SetActorType(sld);
			LAi_ActorSetSitMode(sld);
			LAi_ActorWaitDialog(PChar, sld);
			sld.Dialog.CurrentNode = "Give Up 3";
			LAi_ActorDialog(sld, Pchar, "", 1.0, 0);
		break;
		
		case "At Steven while Giving Up 3":
			sld = &characters[sti(PChar.quest.mysterious_plants.give_up.indian)];
			LAi_type_actor_Reset(sld);
			LAi_ActorSetStayMode(sld);
			LAi_ActorWaitDialog(sld, PChar);
			sld.Dialog.CurrentNode = "Give Up 4";
			LAi_ActorDialogNow(PChar,sld,"",-1);
		break;
		
		case "Given Up End at Steven":
			sld = &characters[sti(PChar.quest.mysterious_plants.give_up.indian)];
			LAi_UnStoreFantom(sld);
			LAi_ActorRunToLocation(sld, "reload", "reload1", "none", "", "", "", 45.0);
			LAi_SetPlayerType(pchar);
			AddQuestRecord("plants",33);
			CloseQuestHeader("plants");
			//---> PW set Dusty for continued hotel puzzle
			Characters[GetCharacterIndex("Dusty_Broome")].dialog.CurrentNode  = "dusty_repeat";//PW return dialog about ghosts done yet
			
			if (CheckAttribute(pchar,"quest.chair_45_check")) 
			{
			ChangeCharacterAddressGroup(characterFromID("Dusty_Broome"),"Cartagena Hotel", "goto", "character2");
			}
			else
			{
			ChangeCharacterAddressGroup(characterFromID("Dusty_Broome"),"none", "", "");
			}
			DeleteAttribute(&pchar,"quest.mysterious_plants");//PW tidy up all attributes in tree

			Pchar.quest.plants = "done";//PW prevent repeat start dialogs

		//JRH-->
			sld = &characters[GetCharacterIndex("Apothecary")];	
			LAi_SetSitType(sld);						//dialog wasn't possible
			pchar.quest.mysterious_plants.give_up = "false";	//dialog repeated give up thing //PW keep attribute for extended opium fetch
		//<--JRH
		break;
		
		case "Payback Indians after give up at Steven":
			Preprocessor_AddQuestData("amount", PChar.quest.mysterious_plants.give_up.amount);
			Preprocessor_AddQuestData("time", PChar.quest.mysterious_plants.give_up.time);
			AddQuestRecord("plants", 34);
			Preprocessor_Remove("amount");
			Preprocessor_Remove("time");
			PChar.quest.Indians_Attack_No_Opium.win_condition.l1 = "Timer";
			PChar.quest.Indians_Attack_No_Opium.win_condition.l1.date.day = GetAddingDataDay(0,sti(PChar.quest.mysterious_plants.give_up.time),0);
			PChar.quest.Indians_Attack_No_Opium.win_condition.l1.date.month = GetAddingDataMonth(0,sti(PChar.quest.mysterious_plants.give_up.time),0);
			PChar.quest.Indians_Attack_No_Opium.win_condition.l1.date.year = GetAddingDataYear(0,sti(PChar.quest.mysterious_plants.give_up.time),0);
			PChar.quest.Indians_Attack_No_Opium.win_condition = "Failed To Deliver Opium To Indians";
			sld = &characters[sti(PChar.quest.mysterious_plants.give_up.indian)];
			LAi_ActorRunToLocation(sld, "reload", "reload1", "none", "", "", "Indian left steven for Cartagena", 45.0);
			//PW-->
			sld = &characters[GetCharacterIndex("Apothecary")];	
			LAi_SetSitType(sld);						//dialog wasn't possible
			pchar.quest.mysterious_plants.give_up = "false";	//PW dialog repeated give up but want to leave give up extension fetch opium effects
			// ---> PW clear some dialogue control attributes
			DeleteAttribute(pchar,"quest.mysterious_plants.setwarehouse");
			DeleteAttribute(pchar,"quest.mysterious_plants.No_Follow");
			DeleteAttribute(pchar,"quest.mysterious_plants.Lost_Indian");
			DeleteAttribute(pchar,"quest.mysterious_plants.spy.killed");
			// <---------- PW cleared dialogue control attributes before compensation paid ends quest

			DeleteAttribute(&pchar,"quest.mysterious_plants.guard_ship");
			//DeleteAttribute(pchar,"quest.mysterious_plants.heard_job");//PW for payback dialog in Cartagena to work

		//<--PW
		break;

		
		case "Indian left steven for Cartagena":
			LAi_SetPlayerType(pchar);
			DeleteAttribute(&pchar,"quest.mysterious_plants.guard_ship");
			LAi_QuestDelay("Place Indian In Hotel Again",0);
		break;
		
		case "Prepare Payback Indians with Opium":
			sld = &characters[sti(PChar.quest.mysterious_plants.give_up.indian)];
			ChangeCharacterAddressGroup(sld,"Cartagena Hotel", "goto", "goto1");
			LAi_SetStayType(sld);
			sld.Dialog.CurrentNode = "Bring Opium";
			pchar.quest.Add_Native_In_Hotel.win_condition.l1 = "ExitFromLocation";
			pchar.quest.Add_Native_In_Hotel.win_condition.l1.location = "Cartagena Hotel";
			pchar.quest.Add_Native_In_Hotel.win_condition = "Place Indian In Hotel Again";
		break;
		
		case "Place Indian In Hotel Again":
			if(sti(GetAttribute(PChar,"quest.mysterious_plants.give_up.amount"))>0)
			{
				sld = &characters[sti(PChar.quest.mysterious_plants.give_up.indian)];
				ChangeCharacterAddressGroup(sld,"none", "", "");
				pchar.quest.Add_Native_In_Hotel_again.win_condition.l1 = "location";
				pchar.quest.Add_Native_In_Hotel_again.win_condition.l1.location = "Cartagena Hotel";
				pchar.quest.Add_Native_In_Hotel_again.win_condition = "Prepare Payback Indians with Opium";
			}
		break;
		
		case "Failed To Deliver Opium To Indians":
			//Place Indian Ambush
			pchar.vcskip = true;
			pchar.quest.prepare_to_die_by_indians.win_condition.l1 = "ExitFromLocation";
			pchar.quest.prepare_to_die_by_indians.win_condition.l1.location = pchar.location;
			pchar.quest.prepare_to_die_by_indians.win_condition = "Indians will slay you now!";
		break;
		
		case "Indians will slay you now!":
/* -->PW this code in abeyance until impact across storylines better evaluated
			for (i = 0; i < 1; i++)
			{
				indianid = 1+rand(2);
				sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 20, true, 1.0, "indian"+indianid, "reload",LAi_FindRandomLocator("reload")); 				
				GiveItem2Character(sld,"tomahawk");//PW make doubly sure they are always armed!!
				LAi_FindRandomLocator("reload"));
				if(rand(99) > 50)
				{
					TakeNItems(sld,"curare",1+rand(4));
				}
				else
				{
					TakeNItems(sld,"tar",1+rand(4));
				}
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "Indian Ambush");
			}
			//Lock all locators
			aref reloads; makearef(reloads,Locations[FindLocation(pchar.location)].reload);
			for(i=0;i<GetAttributesNum(reloads);i++)
			{
				aref lx = GetAttributeN(reloads,i);
				if(!CheckAttribute(lx,"disable")) lx.disabledbylock = true;
				lx.disable = true;
			}
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "Indian Ambush", true);
// <--PW this code in abeyance until impact across storylines better evaluated
*/
			DeleteAttribute(&pchar,"quest.Add_Native_In_Hotel");//PW remove payback indian from Cartagena Hotel
			sld = &characters[sti(PChar.quest.mysterious_plants.give_up.indian)];//PW remove payback indian from Cartagena Hotel
			ChangeCharacterAddressGroup(sld,"none", "", "");	//PW remove payback indian from Cartagena Hotel
			LAi_UnStoreFantom(sld);//PW remove payback indian from Cartagena Hotel
			LAi_SetPlayerType(pchar);

			DeleteAttribute(&pchar,"vcskip");
			DeleteAttribute(&pchar,"quest.mysterious_plants");//PW tidy up all attributes in tree
			AddQuestRecord("plants",40);// PW should be 36 if Indian Ambush is active (final attack if no opium delivery)
			CloseQuestHeader("plants");
			Pchar.quest.plants = "done";
						
			
/*
// --> PW this code in abeyance until impact across storylines better evaluated
			PChar.quest.wow_you_won_from_ambush.win_condition.l1 = "Group_Death";
			PChar.quest.wow_you_won_from_ambush.win_condition.l1.group = "Indian Ambush";
			PChar.quest.wow_you_won_from_ambush.win_condition = "Release Location from Indian Ambush";
// <--PW this code in abeyance until impact across storylines better evaluated
*/ 
		break;
		
		case "Release Location from Indian Ambush":
			aref reloads2; makearef(reloads2,Locations[FindLocation(pchar.location)].reload);
			for(i=0;i<GetAttributesNum(reloads2);i++)
			{
				aref lx2 = GetAttributeN(reloads2,i);
				if(CheckAttribute(lx2,"disabledbylock")) DeleteAttribute(&lx2,"disable");
			}
		break;
		
		case "Give Up Completed in Cartagena"://given opium compensation
			sld = &characters[sti(PChar.quest.mysterious_plants.give_up.indian)];
			LAi_SetActorType(sld);
			TakeNItems(Pchar, "opium", -(sti(GetAttribute(PChar,"quest.mysterious_plants.give_up.amount"))));
			LAi_ActorRunToLocation(sld, "reload", "reload1", "none", "", "", "", 45.0);//PW remove indian

			LAi_UnStoreFantom(sld);
			LAi_SetPlayerType(pchar);
			AddQuestRecord("plants",35);
			CloseQuestHeader("plants");
			DeleteAttribute(&pchar,"quest.mysterious_plants");//PW tidy up all attributes in tree
			pchar.mysterious_plants.give_up = "false";// PW except add this back in case puzzle still set so dusty not replaced at chair_45
			Pchar.quest.plants = "done";//PW avoid repeat start quest dialog
			DeleteAttribute(&pchar,"quest.Indians_Attack_No_Opium");
			DisableFastTravel(false);// PW unblock fast travel in case still set
		break;
		
		case "Depart To Columbia for Apothecary":
			//LAi_type_actor_Reset(pchar);
			//LAi_type_actor_Reset(characterFromID("Robert Cook"));
			LAi_ActorRunToLocator(pchar,"officers","reload3_2","",-1);
			LAi_ActorRunToLocator(characterFromID("Robert Cook"),"officers","reload3_2","",-1);
			LAi_QuestDelay("Depart To Columbia Fade",6);
		break;
		
		case "Depart To Columbia Fade":
			Locations[FindLocation("Cartagena_port")].vcskip = true; // NK
			LAi_Fade("Sail To Cartagena for Apothecary", "");
		break;
		
		case "Sail To Cartagena for Apothecary":
			DoQuestReloadToLocation("Cartagena_port","reload","reload1","_");
			DisableFastTravel(true);// PW block fast travel to ships
			//StoreCharacterShip(pchar);//PW included in loop for companions (so their crew don't starve either)
			shipname = GetMyShipName(PChar);
			for (i = 0; i < COMPANION_MAX; i++) {
				limit = GetCompanionIndex(PChar, i);
				if (limit < 0) continue;
				ch = GetCharacter(limit);
				StoreCharacterShip(ch);
			}	
			Pchar.Ship.Name	= shipname;
			WaitDate("", 0,0,20,12,0);// PW AFTER we have stored the ship(s), + 12 hours so daytime
			sld = characterFromID("Robert Cook");
			SetCharacterShipLocation(sld, "Cartagena_port");
			LAi_type_actor_Reset(sld);
			ChangeCharacterAddressGroup(sld,"Cartagena_port","goto","goto11");
			sld.Dialog.CurrentNode = "Arrived at Cartagena";
			LAi_ActorWaitDialog(PChar,sld);
			LAi_ActorDialog(sld, PChar, "", 2.0, 0);
			AddXP(pchar, SKILL_SAILING, 500, XP_GROUP_OFFIC);
		break;
		
		case "Start Cartagena Exploration for Apothecary":
			LAi_SetPlayerType(pchar);
			sld = characterFromID("Robert Cook");
			LAi_SetStayType(sld);
			sld.Dialog.CurrentNode = "Return To Greenford";
			AddQuestRecord("plants",37);
			pchar.quest.mysterious_plants.heard_job = "Find hotel";
			//Create Beggars
			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 5, true, 1.0, "indian3", "", "");
			ChangeCharacterAddressGroup(sld,"none","","");
			sld.quest.indians.liking = 75 - (GetDifficulty()*10)-rand(30);
			GiveItem2Character(sld,"hotel_flyer");
		//	GiveItem2Character(sld,"ayahuasca");		//JRH at the hotel instead
			sld.Dialog.Filename = "apothecary_quest.c";
			sld.Dialog.CurrentNode = "Beggar In Cartagena";
			LAi_StoreFantom(sld);
			Pchar.quest.mysterious_plants.indianbeggars.indian0 = sld.index;
			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 5, true, 1.0, "indian3", "", "");
			ChangeCharacterAddressGroup(sld,"none","","");
			sld.quest.indians.liking = 75 - (GetDifficulty()*10)-rand(30);
			GiveItem2Character(sld,"hotel_flyer");
		//	GiveItem2Character(sld,"ayahuasca");		//JRH at the hotel instead
			sld.Dialog.Filename = "apothecary_quest.c";
			sld.Dialog.CurrentNode = "Beggar In Cartagena";
			LAi_StoreFantom(sld);
			Pchar.quest.mysterious_plants.indianbeggars.indian1 = sld.index;
			pchar.quest.Place_Beggar_At_Cartagena.win_condition.l1 = "location";
			pchar.quest.Place_Beggar_At_Cartagena.win_condition.l1.location = "Cartagena_Center";
			pchar.quest.Place_Beggar_At_Cartagena.win_condition = "Place Beggar in Cartagena";
			pchar.quest.Place_Beggar_At_Cartagena2.win_condition.l1 = "location";
			pchar.quest.Place_Beggar_At_Cartagena2.win_condition.l1.location = "Cartagena_town_02";
			pchar.quest.Place_Beggar_At_Cartagena2.win_condition = "Place Beggar in Cartagena2";
		break
		
		case "Return to Greenford for Apothecary":
			LAi_QuestDelay("Finish Beggar Find",0);
			
			//Locations[FindLocation("Greenford_port")].reload.l1.disable = 0;
			DisableFastTravel(false);// PW remove block on fast travel (to ships)
			//RestoreCharacterShip(pchar);//PW not used here to reduce food use and possible deaths and mutiny
			sld = characterFromID("Robert Cook");
			SetCharacterShipLocation(sld, "Greenford_port");
			ChangeCharacterAddressGroup(sld,"Greenford_port","goto","goto21");
			SetCharacterShipLocation(Pchar, "Greenford_port");			//JRH pchar ship not there?
			WaitDate("", 0,0,20,0,0);
			DoQuestReloadToLocation("Greenford_port","reload","reload1","Returned in Greenford for Apothecary Arive");
		break;
		
		case "Returned in Greenford for Apothecary Arive":
			
			//WaitDate("", 0,0,20,0,0);//PW moved earlier case
			sld = characterFromID("Robert Cook");
			LAi_SetActorType(sld);
			LAi_SetActorType(pchar);
			sld.Dialog.CurrentNode = "Arrived back in Greenford";
			LAi_ActorWaitDialog(PChar,sld);
			LAi_ActorDialog(sld, PChar, "", 2.0, 0);
			AddXP(pchar, SKILL_SAILING, 500, XP_GROUP_OFFIC);
		break;
//pär
		case "Returned in Greenford for Apothecary":
			//RestoreCharacterShip(pchar);//PW moved to reduce food use and possible deaths and mutiny and in loop
			for (i = 0; i < COMPANION_MAX; i++) {//PW now loop for whole pchar fleet
				limit = GetCompanionIndex(PChar, i);
				if (limit < 0) continue;
				ch = GetCharacter(limit);
				RestoreCharacterShip(ch);
			}		
			sld = characterFromID("Robert Cook");
			LAi_type_actor_Reset(sld);
			LAi_SetPlayerType(pchar);
			SetCharacterShipLocation(sld, "none");
			LAi_ActorRunToLocation(sld,"reload","reload4","none","","","",-1);
			pchar.quest.mysterious_plants.heard_job = "Returned";
			AddQuestRecord("plants",43);
			LAi_QuestDelay("dusty_plants",2);
		break;

		case "dusty_plants":
			if (CheckAttribute(pchar,"quest.mysterious_plants.ghosts"))//PW check if puzzle solved
			{
			LAi_SetActorType(CharacterFromID("Dusty_Broome"));
			LAi_ActorDialog(characterFromID("Dusty_Broome"), pchar, "", 0.0, 0.0);
			LAi_ActorWaitDialog(Pchar, characterFromID("Dusty_Broome"));
			Characters[GetCharacterIndex("Dusty_Broome")].dialog.CurrentNode  = "dusty_plants";
			TakeItemFromCharacter(pchar, "hotel_keys");//PW moved from previous case
			}
			else
			{
			Characters[GetCharacterIndex("Dusty_Broome")].dialog.CurrentNode  = "dusty_repeat";
			}
		break;
		
		case "Place Beggar in Cartagena":
			if(GetAttribute(pchar,"quest.mysterious_plants.heard_job") == "Find hotel")
			{
				sld = &characters[sti(Pchar.quest.mysterious_plants.indianbeggars.indian0)];
				ChangeCharacterAddressGroup(sld,"Cartagena_Center","goto", "goto30");
				LAi_SetPoorType(sld);
				pchar.quest.Place_Beggar_At_Cartagena_again.win_condition.l1 = "ExitFromLocation";
				pchar.quest.Place_Beggar_At_Cartagena_again.win_condition.l1.location = "Cartagena_Center";
				pchar.quest.Place_Beggar_At_Cartagena_again.win_condition = "Place Beggar in Cartagena again";
				Pchar.quest.Killed_Beggar_Cartagena.win_condition.l1 = "NPC_Death";
				Pchar.quest.Killed_Beggar_Cartagena.win_condition.l1.character = sld.id;
				Pchar.quest.Killed_Beggar_Cartagena.win_condition = "Kill Indian Beggar";
			}
		break;
		
		case "Place Beggar in Cartagena2":
			if(GetAttribute(pchar,"quest.mysterious_plants.heard_job") == "Find hotel")
			{
				sld = &characters[sti(Pchar.quest.mysterious_plants.indianbeggars.indian1)];
				ChangeCharacterAddressGroup(sld,"Cartagena_town_02","goto", "locator8");
				LAi_SetPoorType(sld);
				pchar.quest.Place_Beggar_At_Cartagena_again2.win_condition.l1 = "ExitFromLocation";
				pchar.quest.Place_Beggar_At_Cartagena_again2.win_condition.l1.location = "Cartagena_town_02";
				pchar.quest.Place_Beggar_At_Cartagena_again2.win_condition = "Place Beggar in Cartagena again2";
				Pchar.quest.Killed_Beggar_Cartagena.win_condition.l1 = "NPC_Death";
				Pchar.quest.Killed_Beggar_Cartagena.win_condition.l1.character = sld.id;
				Pchar.quest.Killed_Beggar_Cartagena.win_condition = "Kill Indian Beggar";
			}
		break;
		
		case "Place Beggar in Cartagena again":
			if(GetAttribute(pchar,"quest.mysterious_plants.heard_job") == "Find hotel")
			{
				sld = &characters[sti(Pchar.quest.mysterious_plants.indianbeggars.indian0)];
				ChangeCharacterAddressGroup(sld,"none","","");
				pchar.quest.Place_Beggar_At_Cartagena.win_condition.l1 = "location";
				pchar.quest.Place_Beggar_At_Cartagena.win_condition.l1.location = "Cartagena_Center";
				pchar.quest.Place_Beggar_At_Cartagena.win_condition = "Place Beggar in Cartagena";
			}
		break;
		
		case "Place Beggar in Cartagena again2":
			if(GetAttribute(pchar,"quest.mysterious_plants.heard_job") == "Find hotel")
			{
				sld = &characters[sti(Pchar.quest.mysterious_plants.indianbeggars.indian1)];
				ChangeCharacterAddressGroup(sld,"none","","");
				pchar.quest.Place_Beggar_At_Cartagena2.win_condition.l1 = "location";
				pchar.quest.Place_Beggar_At_Cartagena2.win_condition.l1.location = "Cartagena_town_02";
				pchar.quest.Place_Beggar_At_Cartagena2.win_condition = "Place Beggar in Cartagena2";
			}
		break;
		
		case "Kill Indian Beggar":
			if(PChar.location == "Cartagena_Center" || PChar.location == "Cartagena_town_02")
			{
				i = sti(GetAttribute(Pchar,"quest.mysterious_plants.indians.killed")) + 1;
				Pchar.quest.mysterious_plants.indians.killed = i;
				ChangeCharacterReputation(PChar, -5);	//JRH
			}
			pchar.quest.Find_Hotel_Flyer.win_condition.l1 = "item";
			pchar.quest.Find_Hotel_Flyer.win_condition.l1.character = pchar.id;
			pchar.quest.Find_Hotel_Flyer.win_condition.l1.item = "hotel_flyer";
			pchar.quest.Find_Hotel_Flyer.win_condition = "Got Hotel Flyer";
		break;
		
		case "Got information from Indian Beggar":
			AddQuestRecord("plants",38);
			GiveItem2Character(pchar,"hotel_flyer");
			DeleteAttribute(&Pchar,"quest.Killed_Beggar_Cartagena");//PW prevent qb entry "you killed..."
			AddXP(pchar, SKILL_LEADERSHIP, 500, XP_GROUP_OFFIC);
			AddXP(pchar, SKILL_SNEAK, 800, XP_GROUP_OFFIC);
			LAi_QuestDelay("Finish Beggar Find",0);
			LAi_QuestDelay("Cartagena_hotel_plants_start",0);
		break;
//pär
		case "Got Hotel Flyer":
			AddQuestRecord("plants",39);
			LAi_QuestDelay("Finish Beggar Find",0);
			LAi_QuestDelay("Cartagena_hotel_plants_start",0);
		break;

		case "Cartagena_hotel_plants_start":
			ChangeCharacterAddressGroup(characterFromID("Dusty_Broome"),"Cartagena Hotel", "goto", "goto8");
			locations[FindLocation("Cartagena Hotel")].type = "Poe_home";	//when cursed
			int ghosts_gone = 0;
			Pchar.quest.ghosts_gone = ghosts_gone;

			pchar.quest.fall_to_private.win_condition.l1 = "locator";
			pchar.quest.fall_to_private.win_condition.l1.location = "Cartagena_hotel_room2";
			pchar.quest.fall_to_private.win_condition.l1.locator_group = "goto";
			pchar.quest.fall_to_private.win_condition.l1.locator = "hatch";
			pchar.quest.fall_to_private.win_condition = "fall_to_private";
		break;

		case "Finish Beggar Find":
			if(CheckAttribute(Pchar,"quest.mysterious_plants.indianbeggars"))
			{
				pchar.quest.mysterious_plants.heard_job = "Find Indian Traders";
				DeleteAttribute(pchar,"quest.Place_Beggar_At_Cartagena_again2");
				DeleteAttribute(pchar,"quest.Place_Beggar_At_Cartagena_again");
				DeleteAttribute(pchar,"quest.Place_Beggar_At_Cartagena");
				DeleteAttribute(pchar,"quest.Place_Beggar_At_Cartagena2");
				sld = &characters[sti(Pchar.quest.mysterious_plants.indianbeggars.indian0)];
				LAi_UnStoreFantom(sld);
				sld = &characters[sti(Pchar.quest.mysterious_plants.indianbeggars.indian1)];
				LAi_UnStoreFantom(sld);
				DeleteAttribute(Pchar,"quest.mysterious_plants.indianbeggars");
			}
		break;
	
		case "chair_45_check":
			//if(CheckCharacterItem(Pchar,"chair_45"))
			//{
				//PW check if quest complete/abandoned then don't move Dusty half way through puzzle just remove him
				
				if(!CheckAttribute(Pchar,"quest.mysterious_plants.give_up")) 
				{
				ChangeCharacterAddressGroup(characterFromID("Dusty_Broome"), "Cartagena Hotel", "goto", "goto2");
				}
				else
				{
				ChangeCharacterAddressGroup(characterFromID("Dusty_Broome"), "none", "", "");
				}
				TakeItemFromCharacter(pchar, "chair_45");
				PlaySound("PEOPLE\wood1.wav");
				SetLocatorRadius(locations[FindLocation(Pchar.location)], "reload", "reload2", 0.7);	
				Locations[FindLocation("Cartagena_hotel_office")].locators_radius.reload.reload2 = 0.7;	//to hotel corridor
				Locations[FindLocation("Cartagena Hotel")].reload.l5.disable = false;			//to office
				Locations[FindLocation("Cartagena Hotel")].locators_radius.reload.reload8 = 0.4;	//window
				
//		ChangeCharacterAddressGroup(characterFromID("Dusty_Broome"), "Cartagena Hotel", "goto", "goto2");
		//	}
		//	else LAi_QuestDelay("chair_45_check", 0.5);//loop check

		break;
	
		case "fall_to_private":
			PlaySound("INTERFACE\step_path.wav");
			LAi_QuestDelay("fall_to_private1",0.7);
		break;

		case "fall_to_private1":
			DoQuestReloadToLocation("Cartagena_hotel_private","goto","air","fall_to_private2");
		break;

		case "fall_to_private2":
			if(Pchar.sex == "man") {PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav");}
			else{PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom5.wav");}
			LAi_QuestDelay("fall_to_private3",0.5);
		break;

		case "fall_to_private3":
			float Php = LAi_GetCharacterHP(Pchar);
			int Php3;
			Php3 = Php/3;
			LAi_ApplyCharacterDamage(Pchar, Php3);
			PlaySound("PEOPLE\jump.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorSetLayMode(Pchar);
			LAi_QuestDelay("fall_to_private4",2);
		break;

		case "fall_to_private4":
			LAi_SetPoorType(Pchar);
			float u, v, w;
			GetCharacterPos(Pchar, &u, &v, &w);
			CreateParticleSystem("stars_short" , u, v+1, w, 0.0, 0.0, 0.0, sti(20) );
			if(Pchar.sex == "man") {PlaySound("OBJECTS\VOICES\DEAD\male\dead4.wav");}
			else{PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom6.wav");}
			LAi_QuestDelay("fall_to_private5",3);
		break;

		case "fall_to_private5":
			LAi_SetPlayerType(Pchar);

			pchar.quest.fall_to_private.win_condition.l1 = "locator";
			pchar.quest.fall_to_private.win_condition.l1.location = "Cartagena_hotel_room2";
			pchar.quest.fall_to_private.win_condition.l1.locator_group = "goto";
			pchar.quest.fall_to_private.win_condition.l1.locator = "hatch";
			pchar.quest.fall_to_private.win_condition = "fall_to_private";
		break;

		case "unlock_hotel_private":
			//from itemlogic

			Locations[FindLocation("Cartagena_hotel_private")].locators_radius.box.box5 = 0.0001;
			Locations[FindLocation("Cartagena_hotel_private")].locators_radius.reload.reload1 = 0.7;
			Locations[FindLocation("Cartagena Hotel")].reload.l2.disable = 0;
			DoQuestReloadToLocation("Cartagena Hotel", "reload", "reload2", "_");
		break;

		case "dusty_info_ghosts":
			DoQuickSave();
			Locations[FindLocation("Cartagena Hotel")].reload.l3.disable = 0;	//room 3
			AddQuestRecord("plants",44);		//start ghosts

			LAi_SetStayType(Pchar);
			LAi_SetActorType(CharacterFromID("Dusty_Broome"));
			Lai_ActorRunToLocator(characterFromID("Dusty_Broome"), "goto", "character2", "dusty_at_window", 6.0);
			Characters[GetCharacterIndex("Dusty_Broome")].dialog.CurrentNode  = "dusty_repeat";
			TakeItemFromCharacter(Pchar, "hotel_flyer" );
		
			//LAi_QuestDelay("chair_45_check", 0);	
			pchar.quest.chair_45_check.win_condition.l1 = "item";
            		pchar.quest.chair_45_check.win_condition.l1.character = pchar.id;
            		pchar.quest.chair_45_check.win_condition.l1.item = "chair_45";
            		pchar.quest.chair_45_check.win_condition = "chair_45_check";

			pchar.quest.ghost2.win_condition.l1 = "location";
			pchar.quest.ghost2.win_condition.l1.location = "Cartagena_hotel_office";
			pchar.quest.ghost2.win_condition = "ghost2";

			pchar.quest.ghost3.win_condition.l1 = "location";
			pchar.quest.ghost3.win_condition.l1.location = "Cartagena_hotel_room1";
			pchar.quest.ghost3.win_condition = "ghost3";

			pchar.quest.ghost6.win_condition.l1 = "location";
			pchar.quest.ghost6.win_condition.l1.location = "Cartagena_hotel_room2";
			pchar.quest.ghost6.win_condition = "ghost6";

			pchar.quest.ghost7.win_condition.l1 = "location";
			pchar.quest.ghost7.win_condition.l1.location = "Cartagena_hotel_room3";
			pchar.quest.ghost7.win_condition = "ghost7";

			pchar.quest.ghost8.win_condition.l1 = "location";
			pchar.quest.ghost8.win_condition.l1.location = "Cartagena_hotel_room4";
			pchar.quest.ghost8.win_condition = "ghost8";
		break;

		case "dusty_at_window":
			LAi_SetPlayerType(Pchar);
			ChangeCharacterAddressGroup(characterFromID("Dusty_Broome"), "Cartagena Hotel", "goto", "character2");
			LAi_SetStayType(CharacterFromID("Dusty_Broome"));
		break;

		//-----------------------------------------------------------------------------------------
		case "ghost2":	
			LAi_SetActorType(CharacterFromID("hotel_ghost2"));
			LAi_ActorDialog(characterFromID("hotel_ghost2"), pchar, "", 0.0, 0.0);
			LAi_ActorWaitDialog(Pchar, characterFromID("hotel_ghost2"));
		break;

		case "ghost2_restart":
			LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_hotel_office")], true);		//reset
			ChangeCharacterAddressGroup(characterFromID("hotel_ghost2"), "Cartagena_hotel_office", "sit", "sit1");
			LAi_SetSitType(CharacterFromID("hotel_ghost2"));
			Characters[GetCharacterIndex("hotel_ghost2")].dialog.CurrentNode  = "deliver_or_die";

			pchar.quest.ghost2.win_condition.l1 = "location";
			pchar.quest.ghost2.win_condition.l1.location = "Cartagena_hotel_office";
			pchar.quest.ghost2.win_condition = "ghost2";
		break;

		case "ghost2_disappears":
			if(CheckAttribute(Pchar,"hotel_surgery") && Pchar.hotel_surgery == "on") 
			{PlaySound("INTERFACE\small_door_locked.wav");}

			if(CheckAttribute(Pchar,"hotel_bandages") && Pchar.hotel_bandages == "on") 
			{PlaySound("PEOPLE\clothes1.wav");}			

			LAi_QuestDelay("ghost2_disappears1", 1);
		break;

		case "ghost2_disappears1":
			GetCharacterPos(CharacterFromID("hotel_ghost2"), &u, &v, &w);
			PlaySound("OBJECTS\DUEL\censer.wav");
			PlaySound("OBJECTS\DUEL\censer.wav");
			PlaySound("OBJECTS\DUEL\censer.wav");
			PlaySound("OBJECTS\DUEL\censer.wav");
			CreateParticleSystemX("blast_dirt", u, v+1, w, u, v+1, w, 10);
			ChangeCharacterAddressGroup(CharacterFromID("hotel_ghost2"),"none","","");

			Pchar.quest.ghosts_gone = makeint(Pchar.quest.ghosts_gone)+1;
			if(CheckAttribute(Pchar,"quest.ghosts_gone") && Pchar.quest.ghosts_gone == 5)
			{
				LAi_QuestDelay("hotel_ghosts_gone", 2);
			}
		break;

		case "ghost2_sittype":
			LAi_SetSitType(CharacterFromID("hotel_ghost2"));
		break;

		//-----------------------------------------------------------------------------------------
		case "ghost3":
			LAi_SetActorType(CharacterFromID("hotel_ghost3"));
			LAi_ActorDialog(characterFromID("hotel_ghost3"), pchar, "", 0.0, 0.0);
			LAi_ActorWaitDialog(Pchar, characterFromID("hotel_ghost3"));
		break;

		case "ghost3_restart":
			LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_hotel_room1")], true);		//reset
			LAi_SetStayType(CharacterFromID("hotel_ghost3"));
			Characters[GetCharacterIndex("hotel_ghost3")].dialog.CurrentNode  = "deliver_or_die";

			pchar.quest.ghost3.win_condition.l1 = "location";
			pchar.quest.ghost3.win_condition.l1.location = "Cartagena_hotel_room1";
			pchar.quest.ghost3.win_condition = "ghost3";
		break;

		case "ghost3_disappears":
			if(CheckAttribute(Pchar,"hotel_crucifix") && Pchar.hotel_crucifix == "on") 
			{PlaySound("INTERFACE\took_item.wav");}

			if(CheckAttribute(Pchar,"hotel_bible") && Pchar.hotel_bible == "on") 
			{PlaySound("INTERFACE\book_close.wav");}		

			LAi_QuestDelay("ghost3_disappears1", 1);
		break;

		case "ghost3_disappears1":
			GetCharacterPos(CharacterFromID("hotel_ghost3"), &u, &v, &w);
			PlaySound("OBJECTS\DUEL\censer.wav");
			PlaySound("OBJECTS\DUEL\censer.wav");
			PlaySound("OBJECTS\DUEL\censer.wav");
			PlaySound("OBJECTS\DUEL\censer.wav");
			CreateParticleSystemX("blast_dirt", u, v+1, w, u, v+1, w, 10);
			ChangeCharacterAddressGroup(CharacterFromID("hotel_ghost3"),"none","","");

			Pchar.quest.ghosts_gone = makeint(Pchar.quest.ghosts_gone)+1;
			if(CheckAttribute(Pchar,"quest.ghosts_gone") && Pchar.quest.ghosts_gone == 5)
			{
				LAi_QuestDelay("hotel_ghosts_gone", 2);
			}
		break;

		//-----------------------------------------------------------------------------------------
		case "ghost6":
			LAi_SetActorType(CharacterFromID("hotel_ghost6"));
			LAi_ActorDialog(characterFromID("hotel_ghost6"), pchar, "", 0.0, 0.0);
			LAi_ActorWaitDialog(Pchar, characterFromID("hotel_ghost6"));
		break;

		case "ghost6_restart":
			LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_hotel_room2")], true);		//reset
			LAi_SetStayType(CharacterFromID("hotel_ghost6"));
			Characters[GetCharacterIndex("hotel_ghost6")].dialog.CurrentNode  = "deliver_or_die";

			pchar.quest.ghost6.win_condition.l1 = "location";
			pchar.quest.ghost6.win_condition.l1.location = "Cartagena_hotel_room2";
			pchar.quest.ghost6.win_condition = "ghost6";
		break;

		case "ghost6_disappears":
			if(CheckAttribute(Pchar,"hotel_spyglass") && Pchar.hotel_spyglass == "on") 
			{PlaySound("PEOPLE\spyglass.wav");}

			if(CheckAttribute(Pchar,"hotel_megaphone") && Pchar.hotel_megaphone == "on") 
			{PlaySound("OBJECTS\SHIPCHARGE\CannonReload-002.wav");}			

			LAi_QuestDelay("ghost6_disappears1", 1);
		break;

		case "ghost6_disappears1":
			GetCharacterPos(CharacterFromID("hotel_ghost6"), &u, &v, &w);
			PlaySound("OBJECTS\DUEL\censer.wav");
			PlaySound("OBJECTS\DUEL\censer.wav");
			PlaySound("OBJECTS\DUEL\censer.wav");
			PlaySound("OBJECTS\DUEL\censer.wav");
			CreateParticleSystemX("blast_dirt", u, v+1, w, u, v+1, w, 10);
			ChangeCharacterAddressGroup(CharacterFromID("hotel_ghost6"),"none","","");

			Pchar.quest.ghosts_gone = makeint(Pchar.quest.ghosts_gone)+1;
			if(CheckAttribute(Pchar,"quest.ghosts_gone") && Pchar.quest.ghosts_gone == 5)
			{
				LAi_QuestDelay("hotel_ghosts_gone", 2);
			}
		break;

		//-----------------------------------------------------------------------------------------
		case "ghost7":
			LAi_SetActorType(CharacterFromID("hotel_ghost7"));
			LAi_ActorDialog(characterFromID("hotel_ghost7"), pchar, "", 0.0, 0.0);
			LAi_ActorWaitDialog(Pchar, characterFromID("hotel_ghost7"));
		break;

		case "ghost7_restart":
			LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_hotel_room3")], true);		//reset
			LAi_SetStayType(CharacterFromID("hotel_ghost7"));
			Characters[GetCharacterIndex("hotel_ghost7")].dialog.CurrentNode  = "deliver_or_die";

			pchar.quest.ghost7.win_condition.l1 = "location";
			pchar.quest.ghost7.win_condition.l1.location = "Cartagena_hotel_room3";
			pchar.quest.ghost7.win_condition = "ghost7";
		break;

		case "ghost7_disappears":
			if(CheckAttribute(Pchar,"hotel_whistle") && Pchar.hotel_whistle == "on") 
			{PlaySound("OBJECTS\SHIPCHARGE\whistle_the_side.wav");}

			if(CheckAttribute(Pchar,"hotel_grappling") && Pchar.hotel_grappling == "on") 
			{PlaySound("PEOPLE\blade_kling.wav");}			

			LAi_QuestDelay("ghost7_disappears1", 1);
		break;

		case "ghost7_disappears1":
			LAi_SetPlayerType(Pchar);

			GetCharacterPos(CharacterFromID("hotel_ghost7"), &u, &v, &w);
			PlaySound("OBJECTS\DUEL\censer.wav");
			PlaySound("OBJECTS\DUEL\censer.wav");
			PlaySound("OBJECTS\DUEL\censer.wav");
			PlaySound("OBJECTS\DUEL\censer.wav");
			CreateParticleSystemX("blast_dirt", u, v+1, w, u, v+1, w, 10);
			ChangeCharacterAddressGroup(CharacterFromID("hotel_ghost7"),"none","","");

			Pchar.quest.ghosts_gone = makeint(Pchar.quest.ghosts_gone)+1;
			if(CheckAttribute(Pchar,"quest.ghosts_gone") && Pchar.quest.ghosts_gone == 5)
			{
				LAi_QuestDelay("hotel_ghosts_gone", 2);
			}
		break;

		//-----------------------------------------------------------------------------------------
		case "ghost8":
			LAi_SetActorType(CharacterFromID("hotel_ghost8"));
			LAi_ActorDialog(characterFromID("hotel_ghost8"), pchar, "", 0.0, 0.0);
			LAi_ActorWaitDialog(Pchar, characterFromID("hotel_ghost8"));
		break;

		case "ghost8_restart":
			LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_hotel_room4")], true);		//reset
			LAi_SetStayType(CharacterFromID("hotel_ghost8"));
			Characters[GetCharacterIndex("hotel_ghost8")].dialog.CurrentNode  = "deliver_or_die";

			pchar.quest.ghost8.win_condition.l1 = "location";
			pchar.quest.ghost8.win_condition.l1.location = "Cartagena_hotel_room4";
			pchar.quest.ghost8.win_condition = "ghost8";
		break;

		case "ghost8_disappears":
			if(CheckAttribute(Pchar,"hotel_sextant") && Pchar.hotel_sextant == "on") 
			{PlaySound("INTERFACE\pinion_take.wav");}

			if(CheckAttribute(Pchar,"hotel_drawing") && Pchar.hotel_drawing == "on") 
			{PlaySound("INTERFACE\collection_box.wav");}			

			LAi_QuestDelay("ghost8_disappears1", 1);
		break;

		case "ghost8_disappears1":
			GetCharacterPos(CharacterFromID("hotel_ghost8"), &u, &v, &w);
			PlaySound("OBJECTS\DUEL\censer.wav");
			PlaySound("OBJECTS\DUEL\censer.wav");
			PlaySound("OBJECTS\DUEL\censer.wav");
			PlaySound("OBJECTS\DUEL\censer.wav");
			CreateParticleSystemX("blast_dirt", u, v+1, w, u, v+1, w, 10);
			ChangeCharacterAddressGroup(CharacterFromID("hotel_ghost8"),"none","","");

			Pchar.quest.ghosts_gone = makeint(Pchar.quest.ghosts_gone)+1;
			if(CheckAttribute(Pchar,"quest.ghosts_gone") && Pchar.quest.ghosts_gone == 5)
			{
				LAi_QuestDelay("hotel_ghosts_gone", 2);
			}
		break;

		//-----------------------------------------------------------------------------------------
		case "hotel_ghosts_gone":
			
			//PW --> different log and no quest record update if quest over/abandoned but have later done puzzle
			if (!CheckAttribute(pchar,"quest.mysterious_plants.give_up")) 
				{
				Log_SetStringToLog(TranslateString("","Yes! That was the last ghost. Maybe the indian wants to talk to me now..."));
				AddQuestRecord("plants",45);		//end ghosts
				
				} 
				else 
				{
				Log_SetStringToLog(TranslateString("","Yes! That was the last ghost."));
				ChangeCharacterAddressGroup(characterFromID("Dusty_Broome"), "none", "", "");//PW remove Dusty to avoid plants dialogues- (could extend at this point if quest failed, puzzle set but still do puzzle later)
				}
				


			if(Pchar.sex == "man") {PlaySound("OBJECTS\DUEL\man_attack6.wav");}
			else{PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom4.wav");}
			LAi_SetStayType(CharacterFromID("Dusty_Broome"));
			Characters[GetCharacterIndex("Dusty_Broome")].dialog.CurrentNode  = "dusty_ghosts_gone";
			Pchar.quest.mysterious_plants.ghosts = "gone";//PW attribute to check if puzzle done on return to Greenford
			
			locations[FindLocation("Cartagena Hotel")].type = "house";
			locations[FindLocation("Cartagena_hotel_room1")].type = "house";
			locations[FindLocation("Cartagena_hotel_room2")].type = "house";
			locations[FindLocation("Cartagena_hotel_room3")].type = "house";
			locations[FindLocation("Cartagena_hotel_room4")].type = "house";
			locations[FindLocation("Cartagena_hotel_office")].type = "house";
			locations[FindLocation("Cartagena_hotel_private")].type = "house";

			LAi_QuestDelay("hotel_ghosts_gone1", 1);

			pchar.quest.dusty_officer.win_condition.l1 = "locator";
			pchar.quest.dusty_officer.win_condition.l1.location = "Cartagena Hotel";
			pchar.quest.dusty_officer.win_condition.l1.locator_group = "goto";
			pchar.quest.dusty_officer.win_condition.l1.locator = "goto5";
			pchar.quest.dusty_officer.win_condition = "dusty_officer";
		break;

		case "hotel_ghosts_gone1":
			PauseAllSounds();//stops music
			PostEvent("LoadSceneSound", 2000);
		break;
		
		case "dusty_officer":
			LAi_SetActorType(CharacterFromID("Dusty_Broome"));
			LAi_ActorDialog(characterFromID("Dusty_Broome"), pchar, "", 0.0, 0.0);
			LAi_ActorWaitDialog(Pchar, characterFromID("Dusty_Broome"));
			Characters[GetCharacterIndex("Dusty_Broome")].dialog.CurrentNode  = "dusty_ghosts_gone";
		break;
	
		case "dusty_reset":
			ChangeCharacterAddressGroup(characterFromID("Dusty_Broome"), "Cartagena Hotel", "goto", "goto6");
			Characters[GetCharacterIndex("Dusty_Broome")].dialog.CurrentNode  = "dusty_reset";
			AddPassenger(Pchar, characterFromID("Dusty_Broome"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Dusty_Broome"));
			LAi_SetStayType(CharacterFromID("Dusty_Broome"));	
			AddQuestRecord("plants",46);		//Dusty_Broome officer

			pchar.quest.dusty_officertype.win_condition.l1 = "locator";
			pchar.quest.dusty_officertype.win_condition.l1.location = "Cartagena Hotel";
			pchar.quest.dusty_officertype.win_condition.l1.locator_group = "reload";
			pchar.quest.dusty_officertype.win_condition.l1.locator = "reload1";
			pchar.quest.dusty_officertype.win_condition = "dusty_officertype";
		break;

		case "dusty_officertype":
			LAi_SetOfficerType(CharacterFromID("Dusty_Broome"));
		break;

		case "plants_from_dusty":
			//from dusty last dialog

			TakeNItems(characterFromID("Dusty_Broome"), "ayahuasca", -4);
			TakeNItems(Pchar, "ayahuasca", 4);
			AddQuestRecord("plants",48);		//to Steven
			LAi_SetPlayerType(Pchar);
			for(i=1; i<4; i++) RemoveOfficersIndex(GetMainCharacter(), GetOfficersIndex(GetMainCharacter(), i));
			RemovePassenger(Pchar, characterFromID("Dusty_Broome"));
			Characters[GetCharacterIndex("Dusty_Broome")].dialog.CurrentNode  = "dusty_leaving";

			LAi_SetCitizenType(characterFromID("Dusty_Broome"));

			pchar.quest.dusty_gone.win_condition.l1 = "ExitFromLocation";
			pchar.quest.dusty_gone.win_condition.l1.location = "Greenford_port";
			pchar.quest.dusty_gone.win_condition = "dusty_gone";
		break;

		case "dusty_feel_free":
			Characters[GetCharacterIndex("Dusty_Broome")].dialog.CurrentNode  = "dusty_leaving";
		break;

		case "dusty_gone":
			ChangeCharacterAddressGroup(characterFromID("Dusty_Broome"), "none", "", "");
		break;

		case "Plants_end":
			Pchar.quest.mysterious_plants.heard_job = "finished_now";//PW not used??
			AddQuestRecord("plants",49);
			CloseQuestHeader("plants");
			TakeNItems(Pchar, "ayahuasca", -4);
			TakeNItems(Pchar, "doctortoolkit", 1);
			AddXP(pchar, SKILL_SNEAK, 10000, XP_GROUP_OFFIC);
			DeleteAttribute(&pchar,"quest.mysterious_plants");//PW tidy up all attributes in tree
			Pchar.quest.plants = "done";//PW prevent repeat dialogs (restart)
			
           		
		break;
//pär

///////////////////////////////////////////////////////////////
///// Smugglers: Thomas O Reily is annoying
///////////////////////////////////////////////////////////////

		case "Set up Meeting Beach Thomas":
			PChar.quest.Thomas_See_Deal_expire.win_condition.l1 = "Timer";
			PChar.quest.Thomas_See_Deal_expire.win_condition.l1.date.day = GetAddingDataDay(0,0,2);
			PChar.quest.Thomas_See_Deal_expire.win_condition.l1.date.month = GetAddingDataMonth(0,0,2);
			PChar.quest.Thomas_See_Deal_expire.win_condition.l1.date.year = GetAddingDataYear(0,0,2);
			PChar.quest.Thomas_See_Deal_expire.win_condition = "Failed to See Thomas make Deal";
			LAi_QuestDelay("Set Up Meeting Beach Thomas Again",0);
			PChar.quest.smuggling_guild.quests.see_thomas_make_deal = false;
			PChar.quest.smuggling_guild.quests.see_thomas_make_deal.meet_at_beach = true;
		break;
		
		case "Thomas Makes Deal Natives":
			if(CheckAttribute(PChar,"quest.smuggling_guild.quests.see_thomas_make_deal.meet_at_beach"))//PW check if Failed because of 2 day timer without this would happen if onshore at night later since set
			{
				if(!isDay())
				{
					if(PChar.location.locator == "reload1")
					{
						ChangeCharacterAddressGroup(PChar,"Oxbay_shore_02","goto","citizen06");
					}
	
					ChangeCharacterAddressGroup(CharacterFromID("Thomas O'Reily"),"Oxbay_shore_02","goto","citizen07");
					LAi_SetActorType(CharacterFromID("Thomas O'Reily"));
					LAi_ActorTurnToLocator(CharacterFromID("Thomas O'Reily"),"goto","goto08");
					sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "indian1", "goto", "citizen08");
					PChar.quest.smuggling_guild.quests.see_thomas_make_deal.indian = sld.index;
					LAi_SetActorType(sld);
					LAi_ActorTurnToLocator(sld,"goto","goto07");
					LAi_SetActorType(pchar);
					PChar.quest.smuggling_guild.quests.see_thomas_make_deal = true;
					LAi_QuestDelay("Thomas Makes Deal Natives 2",3);
				}
				else
				{
					LAi_QuestDelay("Set Up Meeting Beach Thomas Again",0);
				}
			}
		break;
		
		case "Thomas Makes Deal Natives 2":
			LAi_ActorRunToLocation(&characters[sti(PChar.quest.smuggling_guild.quests.see_thomas_make_deal.indian)],"reload","reload2_back","none","","","",45.0);
			LAi_ActorWaitDialog(PChar, &characters[GetCharacterIndex("Thomas O'Reily")]);
			characters[GetCharacterIndex("Thomas O'Reily")].Dialog.Filename.Apothecary_Quest = "apothecary_quest.c";
			characters[GetCharacterIndex("Thomas O'Reily")].Dialog.CurrentNode = "Thomas Spotted";
			LAi_ActorDialog(&characters[GetCharacterIndex("Thomas O'Reily")],pchar,"",3,0);
		break;
		
		case "Thomas Makes Deal Natives 3":
			LAi_QuestDelay("Thomas interest for smugglers",0);
			LAi_type_actor_Reset(&characters[GetCharacterIndex("Thomas O'Reily")]);
			LAi_ActorRunToLocation(&characters[GetCharacterIndex("Thomas O'Reily")],"reload","reload2_back","Redmond_Store","sit","sit1","Thomas Makes Deal Natives 4",45.0);
		break;
		
		case "Thomas Makes Deal Natives 4":
			LAi_SetPlayerType(pchar);
			DeleteAttribute(&characters[GetCharacterIndex("Thomas O'Reily")],"Dialog.Filename.Apothecary_Quest");
			LAi_SetMerchantType(&characters[GetCharacterIndex("Thomas O'Reily")]);
		break;
		
		case "Set up Meeting Beach Thomas Again":
			if(CheckAttribute(PChar,"quest.smuggling_guild.quests.see_thomas_make_deal.meet_at_beach"))
			{
				pchar.quest.See_Thomas_Make_Deal.win_condition.l1 = "location";
				pchar.quest.See_Thomas_Make_Deal.win_condition.l1.location = "Oxbay_shore_02";
				pchar.quest.See_Thomas_Make_Deal.win_condition = "Thomas Makes Deal Natives";
			}
		break;
		
		case "Failed to See Thomas make Deal":
			DeleteAttribute(&pchar,"quest.smuggling_guild.quests.see_thomas_make_deal.meet_at_beach");
		break;
		
		case "Thomas interest for smugglers":
			CheckAttribute(characters[GetCharacterIndex("Thomas O'Reily")],"quest.contraband")
			{
				if(CheckAttribute(PChar,"quest.smuggling_guild.quests.see_thomas_make_deal"))
				{
					SetQuestHeader("smuggle_ThomasOReily");
					AddQuestRecord("smuggle_ThomasOReily", 1);
					pchar.quest.smuggling_guild.quests.see_thomas_make_deal.time_to_report = true;
				}
			}
		break;
		
		case "Reported Thomas to Smugglers":
			AddQuestRecord("smuggle_ThomasOReily", 2);
			CloseQuestHeader("smuggle_ThomasOReily");
			ChangeSmugglerLiking(pchar,10);
			TakeNItems(PChar, "meds1", 1);//PW now get first med as "reward"
			DeleteAttribute(pchar,"quest.smuggling_guild.quests.see_thomas_make_deal.time_to_report");
			AddXP(pchar, SKILL_LEADERSHIP, 400, XP_GROUP_OFFIC);
			AddXP(pchar, SKILL_SNEAK, 400, XP_GROUP_OFFIC);
		break;
		
///////////////////////////////////////////////////////////////
///// Smugglers: The Collector
///////////////////////////////////////////////////////////////

		case "Smugglers Request Collector":
			LAi_QuestDelay("learn about smugglers", 0.0);
			if(PChar.location.locator == "reload4")
			{
			sld = &characters[GetCharacterIndex("Greenford_Smuggler")];
			ChangeCharacterAddressGroup(sld,"Greenford_port","goto","goto4");
			sld.Dialog.CurrentNode = "Request for Collector 1";
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar,"goto","goto4");
			LAi_SetActorType(sld);
			LAi_ActorWaitDialog(PChar, sld);
			LAi_ActorDialog(sld,pchar,"",0.5,0);
			}			
			if(PChar.location.locator == "reload1")//PW via fast travel to your ship then shore
			{
			sld = &characters[GetCharacterIndex("Greenford_Smuggler")];
			ChangeCharacterAddressGroup(sld,"Greenford_port","goto","goto21");
			sld.Dialog.CurrentNode = "Request for Collector 1";
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar,"goto","goto20");
			LAi_SetActorType(sld);
			LAi_ActorWaitDialog(PChar, sld);
			LAi_ActorDialog(sld,pchar,"",0.5,0);
			}	
			PChar.quest.mysterious_plants.met_smuggler = true;
			PChar.quest.smuggle_collector.made_offer_collector = true;
			Locations[FindLocation(PChar.location)].reload.l2.disable = true;		//JRH: temp disabled to avoid too quick reload back to town (getting stuck)
		break;
		
		case "Smugglers Collector Meet in Tavern":
			
			if(PChar.location.locator == "reload4")
			{
			sld = &characters[GetCharacterIndex("Greenford_Smuggler")];
			LAi_ActorRunToLocator(sld,"reload","reload4","Smugglers Collector Meet in Tavern 2",3.0);
			LAi_ActorRunToLocator(PChar,"goto","goto4","",20);
			}
			if(PChar.location.locator == "reload1")
			{
			sld = &characters[GetCharacterIndex("Greenford_Smuggler")];
			LAi_ActorRunToLocator(sld,"goto","goto4","Smugglers Collector Meet in Tavern 2",3.0);
			LAi_ActorRunToLocator(PChar,"goto","goto20","",20);
			}
			SetQuestHeader("smuggle_collector");
			AddQuestRecord("smuggle_collector", 1);
		break;
		
		case "Smugglers Collector Meet in Tavern 2":
			Locations[FindLocation(PChar.location)].reload.l2.disable = false;		//JRH: enabled back to town now
			sld = &characters[GetCharacterIndex("Greenford_Smuggler")];
			ChangeCharacterAddressGroup(sld,"greenford_tavern","Sit","Sit8");
			LAi_SetSitType(sld);
			LAi_SetPlayerType(Pchar);
			PChar.quest.smuggle_collector_expire.win_condition.l1 = "Timer";
			PChar.quest.smuggle_collector_expire.win_condition.l1.date.day = GetAddingDataDay(0,0,2);
			PChar.quest.smuggle_collector_expire.win_condition.l1.date.month = GetAddingDataMonth(0,0,2);
			PChar.quest.smuggle_collector_expire.win_condition.l1.date.year = GetAddingDataYear(0,0,2);
			PChar.quest.smuggle_collector_expire.win_condition = "Smugglers Collector Didn't Meet";
		break;
		
		case "Smugglers Collector Didn't Meet":
			AddQuestRecord("smuggle_collector", 2);
			CloseQuestHeader("smuggle_collector");
			DeleteAttribute(PChar,"quest.smuggle_collector.made_offer_collector");
		break;
		
		case "Decline Collectors Offer":
			AddQuestRecord("smuggle_collector", 4);
			CloseQuestHeader("smuggle_collector");
			DeleteAttribute(PChar,"quest.smuggle_collector.made_offer_collector");
			DeleteAttribute(PChar,"quest.smuggle_collector_expire");
		break;
		
		case "Accept Collectors Offer":
			AddQuestRecord("smuggle_collector", 5);
			AddXP(pchar, SKILL_COMMERCE, 1000, XP_GROUP_OFFIC);
			DeleteAttribute(PChar,"quest.smuggle_collector.made_offer_collector");
			PChar.quest.smuggle_collector.collect_bows = true;
			DeleteAttribute(PChar,"quest.smuggle_collector_expire");
			PChar.quest.smuggle_collector_expire.win_condition.l1 = "Timer";
			PChar.quest.smuggle_collector_expire.win_condition.l1.date.day = GetAddingDataDay(0,2,0);
			PChar.quest.smuggle_collector_expire.win_condition.l1.date.month = GetAddingDataMonth(0,2,0);
			PChar.quest.smuggle_collector_expire.win_condition.l1.date.year = GetAddingDataYear(0,2,0);
			PChar.quest.smuggle_collector_expire.win_condition = "Failed Collectors Offer";
		break;
		
		case "Failed Collectors Offer":
			AddQuestRecord("smuggle_collector", 6);
			CloseQuestHeader("smuggle_collector");
			DeleteAttribute(PChar,"quest.smuggle_collector.collect_bows");
			ChangeSmugglerLiking(pchar, -20);
		break;
		
		case "Smugglers Set Collector":
			Preprocessor_AddQuestData("name", pchar.quest.smuggling_guild.people.Collector.Collector0.name);
			Preprocessor_AddQuestData("location", pchar.quest.smuggling_guild.people.Collector.Collector0.location);
			Preprocessor_AddQuestData("island", pchar.quest.smuggling_guild.people.Collector.Collector0.island);
			AddQuestRecord("smuggle_collector", 7);
			Preprocessor_Remove("name");
			Preprocessor_Remove("location");
			Preprocessor_Remove("island");
			DeleteAttribute(PChar,"quest.smuggle_collector.collect_bows");
			PChar.quest.smuggle_collector.meet_buyer = true;
		break;
		
		case "Finish Collector Quest Smugglers":
			ChangeSmugglerLiking(pchar, 10);//PW was 5 but this is a crappy deal you accepted so they should be more pleased
			// so you gained 15 overall, could have lost 10 on rejecting quest at all or 15 if accepted and then ignored/failed
			TakeNItems(PChar, "pistolbow", -10);
			TakeNItems(PChar, "meds2", 1);//PW get 2nd med rather than 5 tar (so ammo mod off covered)
			AddMoneyToCharacter(pchar, 500);
			AddQuestRecord("smuggle_collector", 8);

			if(CheckAttribute(Pchar,"quest.mysterious_plants.guard_ship"))//PW if plants not finished
			{
				AddQuestRecord("smuggle_collector", 9);		//JRH: hint return to apothecary
			}
			CloseQuestHeader("smuggle_collector");
			DeleteAttribute(PChar,"quest.smuggle_collector.meet_buyer");
			pchar.quest.smuggling_guild.quests.collector = true;
			AddXP(pchar, SKILL_COMMERCE, 2500, XP_GROUP_OFFIC);
			AddXP(pchar, SKILL_SNEAK, 1000, XP_GROUP_OFFIC);
			DeleteAttribute(PChar, "quest.smuggle_collector_expire");	// PW stop timer from calling "Failed Collectors Offer"
		break;
///////////////////////////////////////////////////////////////
///// Indian Treasure Side Quest
///////////////////////////////////////////////////////////////
		
		case "Found Treasure Note":
			AddQuestRecord("indian_treasure", 2);
		break;
		
		case "Hide Indian Treasure Random":
			//First decide which of the area's we are going to take
			//We take the highest of the y values so it's always above ground
			switch(rand(0))
			{
				case 0:
					x1 = -9.0952; y1 = 0.0201; z1 = 44.266;
					x2 = -13.324; y2 = -0.38841; z2 = 70.357;
					GetRandom3DPosInRange(x1, x2, y1, y1, z1, z2, &x, &y, &z)
				break;
				
				case 1:
					x1 = -6.3867; y1 = 0.42929; z1 = 69.24;
					x2 = 18.156; y2 = 2.0086; z2 = 73.173;
					GetRandom3DPosInRange(x1, x2, y2, y2, z1, z2, &x, &y, &z)
				break;
				
				case 2:
					x1 = 14.305; y1 = 1.968; z1 = 70.127;
					x2 = 15.786; y2 = 0.94652; z2 = 43.087;
					GetRandom3DPosInRange(x1, x2, y1, y1, z1, z2, &x, &y, &z)
				break;
				
				case 3:
					x1 = 13.236; y1 = 1.419; z1 = 50.838;
					x2 = -1.2856; y2 = 0.0201; z2 = 44.577;
					GetRandom3DPosInRange(x1, x2, y1, y1, z1, z2, &x, &y, &z)
				break;
			}
			HideTreasureAtLocation("Greenford_suburb", x, y, z, "Minersspade", "Open Indian Treasure");
			AddItemToTreasureAtLocation("Greenford_suburb", "vegetal", 10);
			if (ENABLE_AMMOMOD) AddItemToTreasureAtLocation("Greenford_suburb", "quiver", 1);//won't get if ammo off?
			AddItemToTreasureAtLocation("Greenford_suburb", "meds3", 1);//PW med3 rather than curare (so ammo mod off covered)
			AddItemToTreasureAtLocation("Greenford_suburb", "indian14", 1);
		break;
		
		case "Hide Indian Treasure":
			x = 17.455; y=2.0268; z=72.565;
			HideTreasureAtLocation("Greenford_suburb", x, y, z, "Minersspade", "Open Indian Treasure");
			AddItemToTreasureAtLocation("Greenford_suburb", "vegetal", 10);
			if (ENABLE_AMMOMOD) AddItemToTreasureAtLocation("Greenford_suburb", "quiver", 1);
			AddItemToTreasureAtLocation("Greenford_suburb", "meds3", 1);//PW med3 rather than curare (so ammo mod off covered)
			AddItemToTreasureAtLocation("Greenford_suburb", "indian14", 1);
		break;
		
		case "Open Indian Treasure":
			AddQuestRecord("indian_treasure", 4);
			if(CheckAttribute(PChar,"quest.mysterious_plants.steven_dead") || CheckAttribute(PChar,"quest.mysterious_plants.steven_left"))
			{
				CloseQuestHeader("indian_treasure");
			}
			else
			{
				AddQuestRecord("indian_treasure", 5);
			}
			PChar.quest.found_vegetal = true;
		break;
		
		case "Finish Indian Treasure Quest":
			AddQuestRecord("indian_treasure", 6);
			CloseQuestHeader("indian_treasure");
			DeleteAttribute(pchar,"quest.found_vegetal");
			AddXP(pchar, SKILL_ACCURACY, 1000, XP_GROUP_OFFIC);
		break;

///////////////////////////////////////////////////////////////
///// Church Protection (telescope)
///////////////////////////////////////////////////////////////

		case "Telescope_Found_Book":
			// There are two ways to start the quest, by finding the book first, or ...
			if(!CheckAttribute(PChar,"quest.telescope_quest.foundbook")) // PB: Only do this ONCE!
			{
				SetQuestHeader("telescope");
				AddQuestRecord("telescope", 3);
				AddXP(pchar, SKILL_SNEAK, 1000, XP_GROUP_OFFIC);
				pchar.quest.telescope_quest.foundbook = true;
			}
		break;
		
		case "telescope agreed fetch":
			// ... by helping the church first
			SetQuestHeader("telescope");
			pchar.quest.telescope_quest.church = Locations[FindLocation(pchar.location)].id; //save so we know where to return the cross
			AddQuestRecord("telescope", 1);
		break;
		
		case "telescope find book":
			AddQuestRecord("telescope", 2);
			AddXP(pchar, SKILL_SNEAK, 1200, XP_GROUP_PARTY);
		break;
		
		case "telescope finish":
			AddQuestRecord("telescope", 4);
			CloseQuestHeader("telescope");
			AddXP(pchar, SKILL_SNEAK, 1000, XP_GROUP_PARTY);
			AddXP(pchar, SKILL_DEFENCE, 500, XP_GROUP_PARTY);
			AddXP(pchar, SKILL_LEADERSHIP, 500, XP_GROUP_PARTY);
			AddXP(pchar, SKILL_ACCURACY, 500, XP_GROUP_PARTY);
			pchar.quest.telescope_quest.finished = true;
			TakeItemFromCharacter(pchar, "book_exorcist"); // PB: Remove superfluous item
			TakeNItems(PChar, "meds4", 1);//PW get 4th med as swap
		break

///////////////////////////////////////////////////////////////
///// SAVING TOFF'S DAUGHTER
///////////////////////////////////////////////////////////////

		case "to_ship_of_Bernardo_Gamboa":
			LAi_SetActorType(pchar);
			pchar.dialog.currentnode = "to_ship_of_Bernardo_Gamboa";
			LAi_ActorSelfDialog(pchar, "player_back");
		break;

		case "not_to_the_ship":
			LAi_SetPlayerType(pchar);
			pchar.quest.not_to_the_ship_2.win_condition.l1 = "ExitFromLocation";
			pchar.quest.not_to_the_ship_2.win_condition.l1.location = "Douwesen_port";
			pchar.quest.not_to_the_ship_2.win_condition = "not_to_the_ship_2";
		break;

		case "not_to_the_ship_2":
			pchar.quest.to_ship_of_Bernardo_Gamboa.win_condition.l1 = "location";
			pchar.quest.to_ship_of_Bernardo_Gamboa.win_condition.l1.location = "douwesen_port";
			pchar.quest.to_ship_of_Bernardo_Gamboa.win_condition = "to_ship_of_Bernardo_Gamboa";
		break;

		case "to_the_ship":
			DoQuestReloadToLocation("Gamboa_ship", "reload", "locator2", "to_the_ship_2");
		break;

		case "to_the_ship_2":
			LAi_SetActorType(pchar);
// KK -->
			if (!CharacterIsDead(characterFromID("Bernardo Gamboa"))) {
				LAi_SetActorType(characterFromID("Bernardo Gamboa"));
				LAi_ActorFollow(pchar, characterFromID("Bernardo Gamboa"), "", 1.5);
				LAi_ActorFollow(characterFromID("Bernardo Gamboa"), pchar, "to_the_ship_3", 1.5);
			} else {
				LAi_SetActorType(characterFromID("Corentin Lucay"));
				LAi_ActorFollow(pchar, characterFromID("Corentin Lucay"), "", 1.5);
				LAi_ActorFollow(characterFromID("Corentin Lucay"), pchar, "to_the_ship_3", 1.5);
			}
// <-- KK
		break;
		
		case "to_the_ship_3":
			LAi_type_actor_Reset(pchar);
// KK -->
			if (!CharacterIsDead(characterFromID("Bernardo Gamboa"))) {			
				LAi_ActorWaitDialog(pchar, characterFromID("Bernardo Gamboa"));
				LAi_ActorDialog(characterFromID("Bernardo Gamboa"), pchar, "", 2.0, 1.0);
			} else {
				LAi_ActorWaitDialog(pchar, characterFromID("Corentin Lucay"));
				LAi_ActorDialog(characterFromID("Corentin Lucay"), pchar, "", 2.0, 1.0);
			}
// <-- KK
		break;

		case "from_the_ship":
			DoQuestReloadToLocation("Douwesen_port", "reload", "reload2", "not_to_the_ship");
		break;

		case "back_to_the_port":
			DoQuestReloadToLocation("Douwesen_port", "reload", "reload2", "player_back");
		break;

		case "bad_fight_in_ship":
// KK -->
			PChar.quest.BlazeKilledFightingWithGamboa.win_condition.l1 = "NPC_Death";
			PChar.quest.BlazeKilledFightingWithGamboa.win_condition.l1.character = PChar.id;
			PChar.quest.BlazeKilledFightingWithGamboa.win_condition = "BlazeKilledFightingWithGamboa";
// <-- KK
			LAi_SetPlayerType(pchar);
			LAi_group_MoveCharacter(characterFromID("Bernardo Gamboa"), "PIRATES_ON_GAMBOA_SHIP");
			LAi_group_MoveCharacter(characterFromID("Corentin Lucay"), "PIRATES_ON_GAMBOA_SHIP");
			LAi_group_FightGroups("PIRATES_ON_GAMBOA_SHIP", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("PIRATES_ON_GAMBOA_SHIP", "kill_him_all_in_gamboa_ship_complete");
		break;

// KK -->
		case "BlazeKilledFightingWithGamboa":
			pchar.quest.to_ship_of_Bernardo_Gamboa.win_condition.l1 = "location";
			pchar.quest.to_ship_of_Bernardo_Gamboa.win_condition.l1.location = "douwesen_port";
			pchar.quest.to_ship_of_Bernardo_Gamboa.win_condition = "to_ship_of_Bernardo_Gamboa";
			LAi_group_RemoveCheck("PIRATES_ON_GAMBOA_SHIP");
			if (CharacterIsDead(characterFromID("Bernardo Gamboa"))) {
				ChangeCharacterAddressGroup(characterFromID("Corentin Lucay"), "Gamboa_ship", "goto", "goto4");
				characters[GetCharacterIndex("Corentin Lucay")].Dialog.Filename = "Bernardo Gamboa_dialog.c";
				characters[GetCharacterIndex("Corentin Lucay")].Dialog.CurrentNode = "you_again";
			} else {
				LAi_group_MoveCharacter(characterFromID("Bernardo Gamboa"), "QC_CITIZENS");
				characters[GetCharacterIndex("Bernardo Gamboa")].Dialog.CurrentNode = "you_again";
			}
			if (!CharacterIsDead(characterFromID("Corentin Lucay"))) LAi_group_MoveCharacter(characterFromID("Corentin Lucay"), "QC_CITIZENS");
			characters[GetCharacterIndex("Toff Oremans")].quest.daughter = "help_begin";
		break;
// <-- KK

		case "kill_him_all_in_gamboa_ship_complete":
			PChar.quest.BlazeKilledFightingWithGamboa.over = "yes";
			LAi_QuestDelay("kill_him_all_in_gamboa_ship_2_complete", 2.0);
		break;

		case "kill_him_all_in_gamboa_ship_2_complete":
			AddQuestRecord("daughter", 3);
			LAi_SetActorType(pchar);
			pchar.dialog.currentnode = "Teneken_in_the_ship";
			LAi_ActorSelfDialog(pchar, "player_back");
		break;

		case "teneken_in_the_ship":
			LAi_fade("teneken_in_the_ship_2", "");
		break;

		case "teneken_in_the_ship_2":
			ChangeCharacterAddress(characterFromID("Tanneken Oremans"), "Gamboa_ship", "goto2");
			LAi_SetActorType(characterFromID("Tanneken Oremans"));
			LAi_SetActorType(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Tanneken Oremans"));
			LAi_ActorDialog(characterFromID("Tanneken Oremans"), pchar, "player_back", 2.0, 1.0);
		break;

		case "talk_in_gamboa_ship":
			LAi_Type_Actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Corentin Lucay"));
			LAi_SetActorType(characterFromID("Corentin Lucay"));
			LAi_ActorDialog(characterFromID("Corentin Lucay"), pchar, "", 2.0, 1.0);
		break;

		case "second_talk_in_gamboa_ship":
			LAi_Type_Actor_Reset(pchar);
			LAi_ActorWaitDialog(pchar, characterFromID("Bernardo Gamboa"));
			LAi_ActorDialog(characterFromID("Bernardo Gamboa"), pchar, "", 2.0, 1.0);
		break;

		case "gamboa_died":
			LAi_SetPlayerType(pchar);
			LAi_group_MoveCharacter(characterFromID("Bernardo Gamboa"), "PIRATES_ON_GAMBOA_SHIP");
			LAi_group_MoveCharacter(characterFromID("Corentin Lucay"), LAI_GROUP_PLAYER);
			LAi_group_FightGroups("PIRATES_ON_GAMBOA_SHIP", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("PIRATES_ON_GAMBOA_SHIP", "gamboa_died_complete");
		break;

		case "gamboa_died_complete":
			LAi_QuestDelay("gamboa_died_2_complete", 1.0);
		break;

		case "gamboa_died_2_complete":
			if (!LAi_isDead(characterFromID("Corentin Lucay")))
			{
				characters[GetCharacterIndex("Corentin Lucay")].dialog.currentnode = "three";
				LAi_SetActorType(characterFromID("Corentin Lucay"));
				LAi_SetActorType(pchar);
				LAi_ActorWaitDialog(pchar, characterFromID("Corentin Lucay"));
				LAi_ActorDialog(characterFromID("Corentin Lucay"), pchar, "player_back", 2.0, 1.0);
				AddQuestRecord("daughter", 4);
			}
			else
			{
				LAi_QuestDelay("teneken_in_the_ship", 1.0);
			}
		break;


///////////////////////////////////////////////////////////////
///// RYS BLOOM QUEST
///////////////////////////////////////////////////////////////

		case "rys_becomes_officer":
			PlayerLostMoney(characterFromID("Rys Bloom"), 500);//MAXIMUS: new function located in Dialog_func.c
			characters[getCharacterIndex("Rys bloom")].quest.officertype = OFFIC_TYPE_FIRSTMATE;//MAXIMUS
			AddPassenger(Pchar, characterFromID("Rys Bloom"), 0);
			LAi_SetOfficerType(characterFromID("Rys Bloom"));
			characters[getCharacterIndex("Rys bloom")].location = "none";
			characters[GetCharacterIndex("Rys Bloom")].Dialog.Filename = "Enc_Officer_dialog.c"; // KK
			characters[GetCharacterIndex("Rys Bloom")].Dialog.CurrentNode = "Hired"; // KK
		break;


///////////////////////////////////////////////////////////////
///// BALDEWYN COFFIER & ARNAUD MATTON
///////////////////////////////////////////////////////////////

		case "hire_baldewyn":
			LAi_Fade("", "hire_baldewyn_2");
		break;

		case "hire_baldewyn_2":
			ChangeCharacterAddress(characterFromID("Baldewyn Coffier"), "none", "");
			Characters[GetCharacterIndex("Baldewyn Coffier")].dialog.Filename = "Enc_Officer_dialog.c"; // GR
			Characters[GetCharacterIndex("Baldewyn Coffier")].dialog.CurrentNode = "hired"; // GR
		break;

		case "baldewyn_wait_month":
			//characters[GetCharacterIndex("Baldewyn Coffier")].quest.hire = "wait_month";
			if (Checkattribute(CharacterFromID("Baldewyn Coffier"), "quest.arno") && characters[GetCharacterIndex("Baldewyn Coffier")].quest.arno == "accepted") //Fix:Storekeeper:19.09
			{
				characters[GetCharacterIndex("Baldewyn Coffier")].quest.hire = "money_2";
			}
			else
			{
				characters[GetCharacterIndex("Baldewyn Coffier")].quest.hire = "wait_month";
			}
			PChar.quest.baldewyn_wait_month_timer.win_condition.l1 = "Timer";
			PChar.quest.baldewyn_wait_month_timer.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.baldewyn_wait_month_timer.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.baldewyn_wait_month_timer.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			PChar.quest.baldewyn_wait_month_timer.win_condition = "baldewyn_wait_month_timer_complete";
		
			PChar.quest.baldewyn_wait_day_timer.win_condition.l1 = "Timer";
			PChar.quest.baldewyn_wait_day_timer.win_condition.l1.date.day = GetAddingDataDay(0, 0, 1);
			PChar.quest.baldewyn_wait_day_timer.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			PChar.quest.baldewyn_wait_day_timer.win_condition.l1.date.year = GetAddingDataYear(0, 0, 1);
			PChar.quest.baldewyn_wait_day_timer.win_condition = "baldewyn_wait_day_timer_complete";
			
		break;

		case "baldewyn_wait_month_timer_complete":
			characters[GetCharacterIndex("Baldewyn Coffier")].quest.hire =  "money_3"; //Fix:Storekeeper:19.09
		break;

		case "baldewyn_wait_day_timer_complete"://PW timer to place BC on stall
			ChangeCharacterAddressGroup(characterFromID("Baldewyn Coffier"), "Falaise_De_Fleur_Location_03", "merchant", "merchant3");
			LAi_SetMerchantType(characterFromID("Baldewyn Coffier"));
			LAi_SetLoginTime(characterFromID("Baldewyn Coffier"), 6.0, 22.0);
			ChangeCharacterAddressGroup(characterFromID("FF_Street_merchant_1"),"none","","");
			
		break;
///////////////////////////////////////////////////////////////
///// SINK THE PIRATE CORVETTE
///////////////////////////////////////////////////////////////

		case "joseph_claude_le_mougne_english_war_ship":
			characters[GetCharacterIndex("joseph claude le moigne")].quest.english_war_ship = "1";

			SetCharacterRelation(GetCharacterIndex("Eng Captain Near FdF"),GetMainCharacterIndex(),RELATION_ENEMY);
			SetCharacterRelation(GetCharacterIndex("FalaiseDeFleur Commander"),GetCharacterIndex("Eng Captain Near FdF"),RELATION_ENEMY);
			
			Group_CreateGroup("Eng Captain Near FdF");
			Group_AddCharacter("Eng Captain Near FdF", "Eng Captain Near FdF");
			Group_SetGroupCommander("Eng Captain Near FdF", "Eng Captain Near FdF");
			Group_SetAddress("Eng Captain Near FdF", "FalaiseDeFleur", "Quest_Ships","Quest_Ship_12");
			Group_SetTaskAttack("Eng Captain Near FdF", PLAYER_GROUP, true);

			UpdateRelations();

			Preprocessor_AddQuestData("Joseph Claude Le Moigne", GetMyFullName(CharacterFromID("Joseph Claude Le Moigne")));
			Preprocessor_AddQuestData("French", GetNationDescByType(GetTownNation("Falaise de Fleur")));
			SetQuestHeader("Hire_by_france_for_defeat_england_corvette");
			AddQuestRecord("Hire_by_france_for_defeat_england_corvette", 1);
			Preprocessor_Remove("French");
			Preprocessor_Remove("Joseph Claude Le Moigne");

			pchar.quest.killing_pirate_near_fdf.win_condition.l1 = "NPC_death";
			pchar.quest.killing_pirate_near_fdf.win_condition.l1.character = "Eng Captain Near FdF";
			pchar.quest.killing_pirate_near_fdf.win_condition = "killing_pirate_near_fdf";
		break;

		case "killing_pirate_near_fdf":
			characters[getCharacterindex("Joseph Claude Le Moigne")].quest.english_war_ship = "2";
		break;


///////////////////////////////////////////////////////////////
// ESCORT VIGILA MENDES' SHIP + ZAID MURRO'S PROBLEM
// Rewritten by PB for improved reliability
///////////////////////////////////////////////////////////////

		case "Mendes_go_away_from_muelle_store":
			pchar.quest.death_of_vigila_mendes.win_condition.l1 = "NPC_death";
			pchar.quest.death_of_vigila_mendes.win_condition.l1.character = "Vigila Mendes";
			pchar.quest.death_of_vigila_mendes.win_condition = "death_of_vigila_mendes_complete";
			
			LAi_SetActorType(characterFromID("Vigila Mendes"));
			Lai_ActorGoToLocator(characterFromID("Vigila Mendes"), "reload", "locator2", "Mendes_Leaves", 2.0);

			SetCompanionIndex(pchar,-1, GetCharacterIndex("Vigila Mendes"));
			SetCharacterRemovable(characterFromID("Vigila Mendes"), false);
			AddCharacterGoods(CharacterFromID("Vigila Mendes"), GOOD_EBONY, 500);

			pchar.quest.Mendes_go_away_from_muelle_store_complete.win_condition.l1 = "location";
			pchar.quest.Mendes_go_away_from_muelle_store_complete.win_condition.l1.location = "Falaise_De_Fleur_Store";
			pchar.quest.Mendes_go_away_from_muelle_store_complete.win_condition = "Mendes_go_away_from_muelle_store_complete";
		break;

		case "Mendes_go_away_from_muelle_store_complete":
			//ChangeCharacterAddress(CharacterFromID("Zaid Murro"), "none", "none"); //NK disabled 1
			ChangeCharacterAddress(characterFromID("Vigila Mendes"), "Falaise_De_Fleur_Store", "goto5");
			LAi_ActorWaitDialog(characterFromID("Vigila Mendes"), pchar);
		break;

		case "Mendes_go_away_from_falaise_de_fleur_store":
			Lai_ActorGoToLocator(characterFromID("Vigila Mendes"), "reload", "reload1", "Mendes_Leaves", 2.0);

			RemoveCharacterGoods(characterFromID("Vigila Mendes"), GOOD_EBONY, 500);
			AddCharacterGoods(characterFromID("Vigila Mendes"), GOOD_LINEN, 500);

			pchar.quest.Mendes_go_away_from_falaise_de_fleur_store_complete.win_condition.l1 = "location";
			pchar.quest.Mendes_go_away_from_falaise_de_fleur_store_complete.win_condition.l1.location = "Muelle_store";
			pchar.quest.Mendes_go_away_from_falaise_de_fleur_store_complete.win_condition = "Mendes_go_away_from_falaise_de_fleur_store_complete";
		break;

		case "Mendes_Leaves":
			ChangeCharacterAddress(characterFromID("Vigila Mendes"), "None", "");
		break;

		case "vigila_to_muelle_tavern":
			Lai_ActorWaitDialog(characterFromID("Vigila Mendes"), pchar);
		break;

		case "Mendes_go_away_from_falaise_de_fleur_store_complete":
			ChangeCharacterAddress(characterFromID("Vigila Mendes"), "Muelle_store", "locator5");
			LAi_ActorWaitDialog(characterFromID("Vigila Mendes"), pchar);
		break;

		case "death_of_vigila_mendes_complete":
			//ChangeCharacterAddress(CharacterFromID("Zaid Murro"), "none", "none"); //NK disabled 2
			AddQuestRecord("mendes", 4);
			CloseQuestHeader("mendes");
			ChangeCharacterReputation(pchar, -2);
		break;
		
		case "mendes_away_forewer":
			LAi_SetActorType(characterFromID("Vigila Mendes"));
			LAi_ActorGoToLocation(characterFromID("Vigila Mendes"), "reload", "locator2", "none", "", "", "", 3.0);
			//ZAID MURRO - çàêðûâàåì âîçìîæíîñòü ïðîõîäèòü ýòîò êâåñò
			//ChangeCharacterAddress(characterFromID("Zaid Murro"), "none", ""); //NK disable this (dunno why it's here but it breaks Zaid)
		break;

		case "zaid_to_muelle_town":
			LAi_ActorGoToLocator(characterFromID("Zaid Murro"),"reload", "reload2", "zaid_to_muelle_town_complete", 2.0);
		break;

		case "zaid_to_muelle_town_complete":
			ChangeCharacterAddress(CharacterFromID("Zaid Murro"), "Muelle_town_01", "goto4");
			LAi_SetStayType(CharacterFromID("Zaid Murro"));
		break;

		case "revenge_for_bandits":
			ChangeCharacterAddress(CharacterFromID("danielle_quests_corsair_1"), "Muelle_town_exit", "locator9");
			ChangeCharacterAddress(CharacterFromID("danielle_quests_corsair_2"), "Muelle_town_exit", "citizen01");
// NK -->
			Characters[GetCharacterIndex("danielle_quests_corsair_1")].greeting = "Gr_isla muelle soldier";
			Characters[GetCharacterIndex("danielle_quests_corsair_2")].greeting = "Gr_isla muelle soldier";
			Characters[GetCharacterIndex("danielle_quests_corsair_3")].greeting = "Gr_isla muelle soldier";
			Characters[GetCharacterIndex("danielle_quests_corsair_4")].greeting = "Gr_isla muelle soldier"; // Julian
			Characters[GetCharacterIndex("danielle_quests_corsair_5")].greeting = "Gr_isla muelle soldier"; // Julian
			LAi_SetActorType(CharacterFromID("danielle_quests_corsair_1"));
			Lai_ActorWaitDialog(characterFromID("danielle_quests_corsair_1"), pchar);
			LAi_SetActorType(CharacterFromID("danielle_quests_corsair_2")); // Julian
			Lai_ActorWaitDialog(characterFromID("danielle_quests_corsair_2"), pchar); // Julian
// NK <--
		break;

		case "fight_with_bandits_in_muelle_town_exit":
			AddQuestrecord("murro", 2);
			LAi_group_MoveCharacter(characterFromID("danielle_quests_corsair_1"), "BANDITS");
			LAi_group_MoveCharacter(characterFromID("danielle_quests_corsair_2"), "BANDITS");
			LAi_group_FightGroups("BANDITS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("BANDITS", "fight_with_other_bandits_in_muelle_town_exit"); //NK fix
		break;

		case "fight_with_other_bandits_in_muelle_town_exit":
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			DoQuestCheckDelay("fight_with_other_bandits_in_muelle_town_exit_2", 3.0);
		break;

		case "fight_with_other_bandits_in_muelle_town_exit_2":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			AddQuestrecord("murro", 3);
			ReanimateCharacter("danielle_quests_corsair_1");
			ReanimateCharacter("danielle_quests_corsair_2");
			ReanimateCharacter("danielle_quests_corsair_3");
// Julian -->
			ChangeCharacterAddressGroup(CharacterFromID("danielle_quests_corsair_4"), "none", "reload", "reload1");
			ChangeCharacterAddressGroup(CharacterFromID("danielle_quests_corsair_5"), "none", "reload", "reload1");
			LAi_SetActorType(CharacterFromID("danielle_quests_corsair_4"));
			LAi_SetActorType(CharacterFromID("danielle_quests_corsair_5"));
			ChangeCharacterAddressGroup(CharacterFromID("danielle_quests_corsair_3"), "Muelle_town_exit", "reload", "reload1");
			ChangeCharacterAddressGroup(CharacterFromID("danielle_quests_corsair_4"), "Muelle_town_exit", "reload", "reload1");
			ChangeCharacterAddressGroup(CharacterFromID("danielle_quests_corsair_5"), "Muelle_town_exit", "reload", "reload1");
			LAi_ActorFollow(CharacterFromID("danielle_quests_corsair_4"), CharacterFromID("danielle_quests_corsair_3"), "", 20);
			LAi_ActorFollow(CharacterFromID("danielle_quests_corsair_5"), CharacterFromID("danielle_quests_corsair_3"), "", 30);
			characters[GetCharacterIndex("Zaid Murro")].quest.bandits = "2";
			LAi_SetActorType(CharacterFromID("danielle_quests_corsair_3"));
			LAi_ActorDialog(CharacterFromID("danielle_quests_corsair_3"), pchar, "", 4.0, 1.0);
// Julian <--
		break;

		case "fight_with_other_bandits_in_muelle_town_exit_3":
			LAi_group_MoveCharacter(characterFromID("danielle_quests_corsair_3"), "BANDITS"); // Julian
			LAi_group_MoveCharacter(characterFromID("danielle_quests_corsair_4"), "BANDITS"); // Julian
			LAi_group_MoveCharacter(characterFromID("danielle_quests_corsair_5"), "BANDITS"); // Julian
			LAi_group_FightGroups("BANDITS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("BANDITS", "fight_with_other_bandits_in_muelle_town_exit_4"); //NK fix
		break;

		case "fight_with_other_bandits_in_muelle_town_exit_4":
			AddQuestrecord("murro", 4);
			Characters[GetCharacterIndex("Zaid Murro")].quest.bandits = "3";
			Characters[GetCharacterIndex("danielle_quests_corsair_1")].location = "none";	// Remove dead bandits
			Characters[GetCharacterIndex("danielle_quests_corsair_2")].location = "none";
			Characters[GetCharacterIndex("danielle_quests_corsair_3")].location = "none";
			Characters[GetCharacterIndex("danielle_quests_corsair_4")].location = "none";
			Characters[GetCharacterIndex("danielle_quests_corsair_5")].location = "none";
		break;



/////////////////////////////////////////////////////////////////////////////
// Raoul Calmes fight scene (moved from "standard" quest code by Grey Roger)
/////////////////////////////////////////////////////////////////////////////

		case "raoul_calmes_fight":
			LAi_LocationFightDisable(&Locations[FindLocation("house_of_smuggler_in_FiF")], false);
			LAi_SetActorType(CharacterFromID("raoul calmes"));
			LAi_ActorAttack(CharacterfromID("raoul calmes"), pchar, "");
			Characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers = "letters_1";
		break;

///////////////////////////////////////////////////////////////
// HELP THE BOATSWAIN + HELP THE LADY (CatalinaThePirate FB Quest)
///////////////////////////////////////////////////////////////
		
		case "story_fred_bob_fired":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Fred Bob"));
			RemovePassenger(pchar, characterFromID("Fred Bob"));
			LAi_ActorGoToLocation(characterFromID("Fred Bob"), "Muelle_port", "goto", "goto9", "", "", "", 25.0);
			LAi_QuestDelay("story_fred_bob_fired2", 25.0);
		break;	

		case "story_fred_bob_fired2":
			ChangeCharacterAddress(characterFromID("Fred Bob"), "Muelle_port", "goto9");
			LAi_SetCitizenType(characterFromID("Fred Bob"));
			Characters[GetCharacterIndex("Fred Bob")].Dialog.CurrentNode = "come_back_fredbob";
		break;
		
		case "story_fred_bob_fired3":
			Characters[GetCharacterIndex("Fred Bob")].Dialog.CurrentNode = "come_back_fredbob2";
		break;
		
		case "Story_gotoQC":
			ChangeCharacterAddressGroup(characterFromID("Armand Delacroix"), "QC_tavern", "Sit", "Sit8");
			pchar.quest.estrella_qc = "here";
		break;

		case "Story_SitAndDrinkWithDelacroix":
			LAi_Fade("Story_SitAndDrinkWithDelacroix_2", "Story_DelacroixStartTalkingInTavern");
		break;
		
		case "Story_SitAndDrinkWithDelacroix_2":
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			ChangeCharacterAddressGroup(pchar, "QC_tavern", "sit", "sit4");
		break
		
		case "Story_DelacroixStartTalkingInTavern":
			SetCurrentTime(23, 0);
			LAi_ActorDialogNow(Pchar, characterFromID("Armand Delacroix"), "", -1);
		break;
		
		case "Story_SitAndDrinkWithDelacroix3":
			LAi_Fade("Story_SitAndDrinkWithDelacroix_4", "Story_DelacroixGiddy");
		break;

		case "Story_SitAndDrinkWithDelacroix_4":
			LAi_SetActorType(characterFromID("Armand Delacroix"));
			ChangeCharacterAddress(characterFromID("Armand Delacroix"), "QC_port", "goto19");
			DoQuestReloadToLocation("QC_port", "goto", "goto18", "Story_DelacroixGiddy");
		break

		case "Story_DelacroixGiddy":
			SetCurrentTime(4, 0);
			LAi_ActorTurnToCharacter(characterFromID("Armand Delacroix"), PChar);
			LAi_ActorDialog(characterfromID("Armand Delacroix"), pchar, "", 1.0, 1.0);
			Characters[GetCharacterIndex("Armand Delacroix")].Dialog.CurrentNode = "giddy";	
		break;
		
		case "Story_Exit_StageLeft":
			DeleteQuestAttribute("estrella_qc");
			LAi_ActorRunToLocation(characterFromID("Armand Delacroix"), "reload", "reload3", "none", "", "", "", 45.0);
		break;

		case "Story_Estrella_Reload_to_IMGate":
			ChangeCharacterAddressGroup(characterFromID("Estrella De Alencar"), "none", "none", "none");	
			SetCurrentTime(1, 0);
			Locations[FindLocation("Muelle_town_03")].vcskip = true; // NK
			StoreOfficers(pchar.id); // KK
			DoQuestReloadToLocation("Muelle_town_01", "reload", "reload14", "Story_Estrella_Afraid");
		break;
		
		case "Story_Estrella_Afraid":
			LAi_SetActorType(characterFromID("Estrella Disguised"));
			LAi_ActorWaitDialog(Pchar, characterFromID("Estrella Disguised"));
			LAi_ActorDialog(characterFromID("Estrella Disguised"), Pchar, "", 7.0, 0);
		break;
		
		case "Story_EstrellaBecomesOfficer":
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Estrella Disguised"));	
			characters[GetCharacterIndex("Estrella Disguised")].dialog.currentnode = "reunited";
			Locations[FindLocation("Muelle_shore")].vcskip = true;
// KK -->
			homelocation = Characters[GetCharacterIndex("spain_soldier_05")].location;
			homegroup = Characters[GetCharacterIndex("spain_soldier_05")].location.group;
			homelocator = Characters[GetCharacterIndex("spain_soldier_05")].location.locator;

			pchar.quest.Story_stop_estrella.win_condition.l1 = "locator";
			pchar.quest.Story_stop_estrella.win_condition.l1.location = homelocation;
			pchar.quest.Story_stop_estrella.win_condition.l1.locator_group = homegroup;
			pchar.quest.Story_stop_estrella.win_condition.l1.locator = homelocator;
			pchar.quest.Story_stop_estrella.win_condition = "Story_stop_estrella";

			Locations[FindLocation(homelocation)].locators_radius.(homegroup).(homelocator).old = Locations[FindLocation(homelocation)].locators_radius.(homegroup).(homelocator);
			Locations[FindLocation(homelocation)].locators_radius.(homegroup).(homelocator) = 5.0;
// <-- KK
		break;
		
		case "Story_stop_estrella":
			LAi_SetActorType(characterFromID("spain_soldier_05"));
			characters[GetCharacterIndex("spain_soldier_05")].dialog.currentnode = "stop_estrella";
			LAi_ActorWaitDialog(Pchar, characterFromID("spain_soldier_05"));
			LAi_ActorDialogNow(characterFromID("spain_soldier_05"), pchar, "Story_stop_estrella1", -1);
		break;

		case "Story_stop_estrella1":
// KK -->
			homelocation = Characters[GetCharacterIndex("spain_soldier_05")].location;
			homegroup = Characters[GetCharacterIndex("spain_soldier_05")].location.group;
			homelocator = Characters[GetCharacterIndex("spain_soldier_05")].location.locator;
			Locations[FindLocation(homelocation)].locators_radius.(homegroup).(homelocator) = Locations[FindLocation(homelocation)].locators_radius.(homegroup).(homelocator).old;
			DeleteAttribute(&Locations[FindLocation(homelocation)], "locators_radius." + homegroup + "." +homelocator + ".old");
// <-- KK
			LAi_SetGuardianType(characterFromID("spain_soldier_05"));
			LAi_group_MoveCharacter(characterFromID("spain_soldier_05"), "SPAIN_SOLDIERS");
			Pchar.quest.Story_EstrellaReunited.win_condition.l1 = "location";
			Pchar.quest.Story_EstrellaReunited.win_condition.l1.location = "Muelle_town_exit";
			Pchar.quest.Story_EstrellaReunited.win_condition = "estrella_disguised_exit_run";
		break;
			
		case "estrella_disguised_exit_run":		
			LAi_SetActorType(characterFromID("Estrella Disguised"));
			LAi_ActorWaitDialog(Pchar, characterFromID("Estrella Disguised"));
			characters[GetCharacterIndex("Estrella Disguised")].dialog.currentnode = "close_call";
			LAi_ActorDialog(characterFromID("Estrella Disguised"), Pchar, "", 1.0, 0);
			ChangeCharacterAddress(characterFromID("Armand Delacroix"), "Muelle_shore", "goto8");
		break;
		
		case "estrella_disguised_exit_run1":	
			LAi_SetOfficerType(characterFromID("Estrella Disguised"));
			Pchar.quest.Story_EstrellaReunited.win_condition.l1 = "location";
			Pchar.quest.Story_EstrellaReunited.win_condition.l1.location = "Muelle_shore";
			Pchar.quest.Story_EstrellaReunited.win_condition = "estrella_disguised_exit_run2";		
		break;
	
		case "estrella_disguised_exit_run2":
			LAi_SetActorType(characterFromID("Estrella Disguised"));
			LAi_ActorWaitDialog(Pchar, characterFromID("Estrella Disguised"));
			characters[GetCharacterIndex("Estrella Disguised")].dialog.currentnode = "reunited";
			LAi_ActorDialog(characterFromID("Estrella Disguised"), Pchar, "", 4.0, 0);
		break;

		case "estrella_disguised_attack1":
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			DeleteAttribute(&Locations[FindLocation("Muelle_town_03")],"vcskip");
			LAi_group_Register("FBQ_SPAIN_SOLDIERS");
			LAi_group_Register("FBQ_Armand");
			LAi_group_MoveCharacter(characterFromID("Armand Delacroix"), "FBQ_Armand");
			LAi_group_SetRelation("FBQ_SPAIN_SOLDIERS", "FBQ_Armand", LAI_GROUP_NEUTRAL);
			LAi_QuestDelay("estrella_disguised_attack2", 1.0);
		break;	
			
		case "estrella_disguised_attack2":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto7"); // PB
			LAi_group_MoveCharacter(sld, "FBQ_SPAIN_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto7"); // PB
			LAi_group_MoveCharacter(sld, "FBQ_SPAIN_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto7"); // PB
			LAi_group_MoveCharacter(sld, "FBQ_SPAIN_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto7"); // PB
			LAi_group_MoveCharacter(sld, "FBQ_SPAIN_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto7"); // PB
			LAi_group_MoveCharacter(sld, "FBQ_SPAIN_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "goto", "goto7"); // PB
			LAi_group_MoveCharacter(sld, "FBQ_SPAIN_SOLDIERS");
			
			LAi_group_FightGroups("FBQ_SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_QuestDelay("estrella_disguised_attack3", 1.0);
		break;

		case "estrella_disguised_attack3":	
			characters[GetCharacterIndex("Estrella Disguised")].dialog.currentnode = "reunited2";
			LAi_SetActorType(characterFromID("Estrella Disguised"));
			LAi_ActorWaitDialog(Pchar, characterFromID("Estrella Disguised"));
			LAi_ActorDialog(characterFromID("Estrella Disguised"), Pchar, "", 4.0, 0);
			DeleteAttribute(&Locations[FindLocation("Muelle_shore")],"vcskip");
		break;

		case "estrella_disguised_attack4":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto7"); // PB
			LAi_group_MoveCharacter(sld, "FBQ_SPAIN_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto7"); // PB
			LAi_group_MoveCharacter(sld, "FBQ_SPAIN_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto7"); // PB
			LAi_group_MoveCharacter(sld, "FBQ_SPAIN_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto7"); // PB
			LAi_group_MoveCharacter(sld, "FBQ_SPAIN_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto7"); // PB
			LAi_group_MoveCharacter(sld, "FBQ_SPAIN_SOLDIERS");
			
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "goto", "goto7"); // PB
			LAi_group_MoveCharacter(sld, "FBQ_SPAIN_SOLDIERS");
			
			LAi_group_FightGroups("FBQ_SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_SetOfficerType(characterFromID("Estrella Disguised"));

			LAi_QuestDelay("estrella_disguised_attack5", 6.0);
		break;
		
		case "estrella_disguised_attack5":
			LAi_group_SetRelation("FBQ_SPAIN_SOLDIERS", "FBQ_Armand", LAI_GROUP_ENEMY);
			LAi_group_FightGroups("FBQ_SPAIN_SOLDIERS", "FBQ_Armand", true);
			LAi_QuestDelay("Story_Reunited2", 3.0);
		break;	
		
		case "Story_Reunited2":
			LAi_group_SetCheck("FBQ_SPAIN_SOLDIERS", "Story_Reunited3");
		break;		
		
		case "Story_Reunited3":
			characters[GetCharacterIndex("Armand Delacroix")].dialog.currentnode = "reunited_flight";
			LAi_SetActorType(characterFromID("Armand Delacroix"));
			LAi_ActorWaitDialog(Pchar, characterFromID("Armand Delacroix"));
			LAi_ActorDialog(characterFromID("Armand Delacroix"), Pchar, "", 20.0, 0);
		break;		

		case "Story_estrella_farewell":	
			characters[GetCharacterIndex("Estrella Disguised")].dialog.currentnode = "estrella_farewell";
			LAi_SetActorType(characterFromID("Estrella Disguised"));
			LAi_ActorWaitDialog(Pchar, characterFromID("Estrella Disguised"));
			LAi_ActorDialog(characterFromID("Estrella Disguised"), Pchar, "", 4.0, 0);
		break;	
		
		case "Story_Exit_StageRight":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Estrella Disguised"));
			RemovePassenger(pchar, characterFromID("Estrella Disguised"));
			RestoreOfficers(pchar.id); // KK
			LAi_SetActorType(characterFromID("Armand Delacroix"));
			LAi_SetActorType(characterFromID("Estrella Disguised"));
			LAi_ActorRunToLocation(characterFromID("Armand Delacroix"), "goto", "goto11", "none", "", "", "", 20.0);
			LAi_ActorRunToLocation(characterFromID("Estrella Disguised"), "goto", "goto11", "none", "", "", "", 20.0);
			LAi_QuestDelay("Story_Armand_and_Estrella_Escape", 20.0);
		break;	
		
		case "Story_Armand_and_Estrella_Escape":
			ChangeCharacterAddress(characterFromID("Armand Delacroix"), "", "");
			ChangeCharacterAddress(characterFromID("Estrella Disguised"), "", "");
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
			LAi_group_SetRelation("FBQ_SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
			LAi_group_FightGroups("FBQ_SPAIN_SOLDIERS", LAI_GROUP_PLAYER, false);
		break;	
		
		case "Story_Armand_refused":
			LAi_SetPlayerType(Pchar);
			ChangeCharacterAddress(pchar, "qc_tavern", "goto5");
		break;

///////////////////////////////////////////////////////////////
// Hitman Edited by SCM
///////////////////////////////////////////////////////////////

		case "Hit_start":
			SetEnterLocationQuest("Conceicao_tavern", "Hit_start_check", 0);
			chrEnableReloadLocator("Muelle_town_01", "Reload21", 0);
			chrEnableReloadLocator("Greenford_town", "reload5", 0);
			chrEnableReloadLocator("Conceicao_town", "reload15", 0);
			chrEnableReloadLocator("Hit_house", "Reload2", 0); //SCM
			chrEnableReloadLocator("Hit_study", "Reload1", 0); //SCM
			chrEnableReloadLocator("Hit_study", "Reload2_back", 0); //SCM
			chrEnableReloadLocator("Hit_passage", "Reload10", 0); //SCM
			// NK -->
			PChar.quest.Hit_Rumor.win_condition.l1 = "rank";
			PChar.quest.Hit_Rumor.win_condition.l1.character = Pchar.id;
			PChar.quest.Hit_Rumor.win_condition.l1.value = 5;
			PChar.quest.Hit_Rumor.win_condition.l1.operation = ">=";
			PChar.quest.Hit_Rumor.win_condition = "Hit_Rumor";
		break;

		case "Hit_Rumor":
			SetRumourState("Hitman_start", true); // NK <--
		break;

		case "Hit_start_check":
			if(makeint(PChar.rank) >= 5)
			{
				SetRumourState("Hitman_start", false); // NK
				StartQuestMovie(true, false, false);TrackQuestMovie("start","Hit_start_check");

				bDisableFastReload = 1;

				ChangeCharacterAddressGroup(CharacterFromID("Ambroz Bricenos"), "Conceicao_tavern", "goto", "goto4");
				ChangeCharacterAddressGroup(CharacterFromID("Mateus Santos"), "Hit_house", "goto", "goto7"); //SCM
				ChangeCharacterAddressGroup(CharacterFromID("Desiree' Muerte"), "Hit_house", "goto", "goto3"); //SCM
				ChangeCharacterAddressGroup(CharacterFromID("Thug2"), "Hit_house", "goto", "goto4"); //SCM
				ChangeCharacterAddressGroup(CharacterFromID("Thug3"), "Hit_house", "goto", "goto5"); //SCM
				ChangeCharacterAddressGroup(CharacterFromID("Thug4"), "Hit_house", "goto", "goto1"); //SCM
				ChangeCharacterAddressGroup(CharacterFromID("Thug5"), "Hit_house", "goto", "goto9"); //SCM
				ChangeCharacterAddressGroup(CharacterFromID("Thug6"), "Hit_house", "goto", "goto6"); //SCM
				ChangeCharacterAddressGroup(CharacterFromID("Thug7"), "Hit_house", "goto", "goto2"); //SCM
				ChangeCharacterAddressGroup(CharacterFromID("Thug8"), "Hit_house", "goto", "goto8"); //SCM
				ChangeCharacterAddressGroup(CharacterFromID("Thug9"), "Hit_passage", "sit", "sit1"); //SCM
				ChangeCharacterAddressGroup(CharacterFromID("Camille Leone"), "Hit_passage", "goto", "goto9"); //SCM
				ChangeCharacterAddressGroup(CharacterFromID("Pris1"), "Hit_passage", "goto", "goto1"); //SCM
				ChangeCharacterAddressGroup(CharacterFromID("Pris2"), "Hit_passage", "goto", "goto2"); //SCM
				ChangeCharacterAddressGroup(CharacterFromID("Pris3"), "Hit_passage", "goto", "goto3"); //SCM
				ChangeCharacterAddressGroup(CharacterFromID("Pris4"), "Hit_passage", "goto", "goto4"); //SCM
				ChangeCharacterAddressGroup(CharacterFromID("Geffrey Bampfylde"), "Hit_house1", "goto", "goto6"); //SCM
				ChangeCharacterAddressGroup(CharacterFromID("Bucho"), "Hit_house1", "goto", "goto1"); //SCM
				ChangeCharacterAddressGroup(CharacterFromID("Amerigo Vieira"), "Hit_house2", "goto", "goto4");

				LAi_SetImmortal(CharacterFromID("Ambroz Bricenos"), 1);
				LAi_SetImmortal(CharacterFromID("Mateus Santos"), 1);
				LAi_SetImmortal(CharacterFromID("Desiree' Muerte"), 1); //SCM
				LAi_SetImmortal(CharacterFromID("Thug2"), 1);
				LAi_SetImmortal(CharacterFromID("Thug3"), 1);
				LAi_SetImmortal(CharacterFromID("Thug9"), 1);
				LAi_SetImmortal(CharacterFromID("Camille Leone"), 1);
				LAi_SetImmortal(CharacterFromID("Geffrey Bampfylde"), 1);
				LAi_SetImmortal(CharacterFromID("Bucho"), 1);
				LAi_SetImmortal(CharacterFromID("Pepin Bertillon"), 1);
				LAi_SetImmortal(CharacterFromID("Bertillon's guard1"), 1);
				LAi_SetImmortal(CharacterFromID("Bertillon's guard2"), 1);
				LAi_SetImmortal(CharacterFromID("Amerigo Vieira"), 1);
				LAi_SetImmortal(CharacterFromID("Vito Leone"), 1);

				LAi_SetWarriorType(CharacterFromID("Mateus Santos"));
				LAi_SetWarriorType(CharacterFromID("Desiree' Muerte")); //SCM
				LAi_SetWarriorType(CharacterFromID("Thug2"));
				LAi_SetWarriorType(CharacterFromID("Thug3")); //SCM
				LAi_SetWarriorType(CharacterFromID("Thug4")); //SCM
				LAi_SetWarriorType(CharacterFromID("Thug5")); //SCM
				LAi_SetWarriorType(CharacterFromID("Thug6")); //SCM
				LAi_SetWarriorType(CharacterFromID("Thug7")); //SCM
				LAi_SetWarriorType(CharacterFromID("Thug8")); //SCM

				LAi_warrior_SetStay(CharacterFromID("Mateus Santos"), 1);
				LAi_warrior_SetStay(CharacterFromID("Desiree' Muerte"), 1); //SCM
				LAi_warrior_SetStay(CharacterFromID("Thug2"), 1);
				LAi_warrior_SetStay(CharacterFromID("Thug3"), 1); //SCM
				LAi_warrior_SetStay(CharacterFromID("Thug4"), 1); //SCM
				LAi_warrior_SetStay(CharacterFromID("Thug5"), 1); //SCM
				LAi_warrior_SetStay(CharacterFromID("Thug6"), 1); //SCM
				LAi_warrior_SetStay(CharacterFromID("Thug7"), 1); //SCM
				LAi_warrior_SetStay(CharacterFromID("Thug8"), 1); //SCM
				LAi_warrior_SetStay(CharacterFromID("Camille Leone"), 1); //SCM

				LAi_warrior_DialogEnable(CharacterFromID("Mateus Santos"), 1);
				LAi_warrior_DialogEnable(CharacterFromID("Desiree' Muerte"), 1); //SCM
				LAi_warrior_DialogEnable(CharacterFromID("Thug2"), 1);
				LAi_warrior_DialogEnable(CharacterFromID("Thug3"), 1); //SCM
				LAi_warrior_DialogEnable(CharacterFromID("Thug4"), 1); //SCM
				LAi_warrior_DialogEnable(CharacterFromID("Thug5"), 1); //SCM
				LAi_warrior_DialogEnable(CharacterFromID("Thug6"), 1); //SCM
				LAi_warrior_DialogEnable(CharacterFromID("Thug7"), 1); //SCM
				LAi_warrior_DialogEnable(CharacterFromID("Thug8"), 1); //SCM
				LAi_warrior_DialogEnable(CharacterFromID("Thug9"), 1); //SCM
				LAi_warrior_DialogEnable(CharacterFromID("Camille Leone"), 1); //SCM

				//LAi_group_MoveCharacter(CharacterFromID("Mateus Santos"), "santos_group");
				//LAi_group_MoveCharacter(CharacterFromID("Desiree' Muerte"), "santos_group"); //SCM
				LAi_group_MoveCharacter(CharacterFromID("Thug2"), "santos_group");
				//LAi_group_MoveCharacter(CharacterFromID("Thug3"), "santos_group");
				LAi_group_MoveCharacter(CharacterFromID("Thug4"), "santos_group"); //SCM
				LAi_group_MoveCharacter(CharacterFromID("Thug5"), "santos_group"); //SCM
				LAi_group_MoveCharacter(CharacterFromID("Thug6"), "santos_group"); //SCM
				LAi_group_MoveCharacter(CharacterFromID("Thug7"), "santos_group"); //SCM
				LAi_group_MoveCharacter(CharacterFromID("Thug8"), "santos_group"); //SCM

				LAi_group_SetRelation("santos_group", "santos_group", LAI_GROUP_FRIEND);
				LAi_SetHuberType(characterfromID("Thug9")); //SCM
				LAi_SetActorType(CharacterFromID("Ambroz Bricenos"));
				Characters[GetCharacterIndex("Ambroz Bricenos")].dialog.currentnode = "wetjob";
				LAi_ActorDialog(CharacterFromID("Ambroz Bricenos"), PChar, "", 15.0, -1);
			}
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

			chrEnableReloadLocator("Muelle_town_01", "Reload21", 0);
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

			chrEnableReloadLocator("Muelle_town_01", "Reload21", 0);
			chrEnableReloadLocator("Greenford_town", "reload5", 0);
			chrEnableReloadLocator("Conceicao_town", "reload15", 0);

			PChar.quest.Hitman = "end";

			//Add journal entry
			AddQuestRecord("Hitman", 21);
			CloseQuestHeader("Hitman");
		break;

		case "Hit_timer1":
			PChar.quest.Hit_timer1.win_condition.l1 = "Timer";
			PChar.quest.Hit_timer1.win_condition.l1.date.day = GetAddingDataDay(0, 3, 0);	//TALISMAN was 0,1,0 which closes quest when player exits Santos house right after being given task
			PChar.quest.Hit_timer1.win_condition.l1.date.month = GetAddingDataMonth(0, 3, 0);
			PChar.quest.Hit_timer1.win_condition.l1.date.year = GetAddingDataYear(0, 3, 0);	//TALISMAN was 0,1,0 which closes quest when player exits Santos house right after being given task
			PChar.quest.Hit_timer1.win_condition = "Hit_END_timer";
		break;

		case "Hit_timer2":
			PChar.quest.Hit_timer2.win_condition.l1 = "Timer";
			PChar.quest.Hit_timer2.win_condition.l1.date.day = GetAddingDataDay(0, 3, 0);	 //TALISMAN was 0,1,0 which closes quest when player exits Santos house right after being given task
			PChar.quest.Hit_timer2.win_condition.l1.date.month = GetAddingDataMonth(0, 3, 0);
			PChar.quest.Hit_timer2.win_condition.l1.date.year = GetAddingDataYear(0, 3, 0);	 //TALISMAN was 0,1,0 which closes quest when player exits Santos house right after being given task
			PChar.quest.Hit_timer2.win_condition = "Hit_END_timer";
		break;

		case "Hit_timer3":
			PChar.quest.Hit_timer3.win_condition.l1 = "Timer";
			PChar.quest.Hit_timer3.win_condition.l1.date.day = GetAddingDataDay(0, 3, 0);	 //TALISMAN was 0,1,0 which closes quest when player exits Santos house right after being given task
			PChar.quest.Hit_timer3.win_condition.l1.date.month = GetAddingDataMonth(0, 3, 0);
			PChar.quest.Hit_timer3.win_condition.l1.date.year = GetAddingDataYear(0, 3, 0);	 //TALISMAN was 0,1,0 which closes quest when player exits Santos house right after being given task
			PChar.quest.Hit_timer3.win_condition = "Hit_END_timer";
		break;

		case "Hit_timer4":
			PChar.quest.Hit_timer4.win_condition.l1 = "Timer";
			PChar.quest.Hit_timer4.win_condition.l1.date.day = GetAddingDataDay(0, 3, 0);	 //TALISMAN was 0,1,0 which closes quest when player exits Santos house right after being given task
			PChar.quest.Hit_timer4.win_condition.l1.date.month = GetAddingDataMonth(0, 3, 0);
			PChar.quest.Hit_timer4.win_condition.l1.date.year = GetAddingDataYear(0, 3, 0);	 //TALISMAN was 0,1,0 which closes quest when player exits Santos house right after being given task
			PChar.quest.Hit_timer4.win_condition = "Hit_END_timer";
		break;

		case "Hit_timer5":
			PChar.quest.Hit_timer5.win_condition.l1 = "Timer";
			PChar.quest.Hit_timer5.win_condition.l1.date.day = GetAddingDataDay(0, 3, 0);	 //TALISMAN was 0,1,0 which closes quest when player exits Santos house right after being given task
			PChar.quest.Hit_timer5.win_condition.l1.date.month = GetAddingDataMonth(0, 3, 0);
			PChar.quest.Hit_timer5.win_condition.l1.date.year = GetAddingDataYear(0, 3, 0);	 //TALISMAN was 0,1,0 which closes quest when player exits Santos house right after being given task
			PChar.quest.Hit_timer5.win_condition = "Hit_END_timer";
		break;

		case "Hit_refused_Ambroz":
		// dialog exit from Ambroz
			// PB: Allow starting the quest again -->
			characters[GetCharacterIndex("Ambroz Bricenos")].dialog.currentnode = "wetjob2";
			LAi_SetCitizenType(characterFromID("Ambroz Bricenos"));
			EndQuestMovie();TrackQuestMovie("end","Hit_refused_Ambroz_end");
			bDisableFastReload = 0;
			// PB: Allow starting the quest again <--
			
			DeleteEnterLocationQuest("Conceicao_tavern", "Hit_start_check");
		/*	LAi_ActorGoToLocation(CharacterFromID("Ambroz Bricenos"), "reload", "reload1", "none", "", "", "Hit_refused_Ambroz_end", 3.0);
		break;

		case "Hit_refused_Ambroz_end":
			EndQuestMovie();TrackQuestMovie("end","Hit_refused_Ambroz_end");
			bDisableFastReload = 0;

			//END QUEST
			LAi_QuestDelay("Hit_END", 0.0);*/
		break;

		case "Hit_start1":
		// dialog exit from Ambroz
			DeleteEnterLocationQuest("Conceicao_tavern", "Hit_start_check");
			PChar.quest.Hitman = "goto_mateus";
			LAi_SetActorType(CharacterFromID("Ambroz Bricenos"));
			LAi_ActorGoToLocation(CharacterFromID("Ambroz Bricenos"), "reload", "reload1", "Conceicao_shore_02", "goto", "citizen06", "Hit_start2", 10.0);
			chrEnableReloadLocator("Muelle_town_01", "reload21", 1);

			//Add journal entry
			SetQuestHeader("Hitman");
			AddQuestRecord("Hitman", 1);
		break;

		case "Hit_start2":
			EndQuestMovie();TrackQuestMovie("end","Hit_start2");

			bDisableFastReload = 0;

			LAi_SetWarriorType(CharacterFromID("Ambroz Bricenos"));
			LAi_warrior_SetStay(CharacterFromID("Ambroz Bricenos"), 1);
			LAi_warrior_DialogEnable(CharacterFromID("Ambroz Bricenos"), 1);

			PChar.quest.Hit_start3.win_condition.l1 = "location";
			PChar.quest.Hit_start3.win_condition.l1.location = "Hit_house";
			PChar.quest.Hit_start3.win_condition = "Hit_start3";
		break;

		case "Hit_start3":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Hit_start3");
			LAi_SetActorType(PChar);
			Characters[GetCharacterIndex("Mateus Santos")].dialog.currentnode = "start";
			LAi_ActorDialog(PChar, CharacterFromID("Mateus Santos"), "", 10.0, -1);
		break;

		case "Hit_refused_Mateus":
		// dialog exit from Mateus
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
			PChar.quest.Hit_refused_Mateus_end.win_condition.l1.location = "Muelle_town_01";
			PChar.quest.Hit_refused_Mateus_end.win_condition = "Hit_refused_Mateus_end";
		break;

		case "Hit_refused_Mateus_end":
			bDisableFastReload = 0;

			//END QUEST
			LAi_QuestDelay("Hit_END", 0.0);

			//Add journal entry
			AddQuestRecord("Hitman", 20);
		break;

		case "Hit_die":
		// dialog exit from Mateus
			EndQuestMovie();TrackQuestMovie("end","Hit_die");
			LAi_SetPlayerType(PChar);
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Hit_die");

			bDisableFastReload = 1;

			LAi_LocationFightDisable(&Locations[FindLocation("Hit_house")], 0); //SCM Fight ok

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
		// dialog exit from Mateus
			EndQuestMovie();TrackQuestMovie("end","Hit_mark_Ambroz");
			LAi_SetPlayerType(PChar);
			PChar.quest.Hitman = "mark_ambroz";
			LAi_SetImmortal(CharacterFromID("Ambroz Bricenos"), 0);
			LAi_SetCheckMinHP(CharacterFromID("Ambroz Bricenos"), 0.0, 0, "Hit_killed_Ambroz");

			//TIMER 1
			LAi_QuestDelay("Hit_timer1", 0.0);

			//Add journal entry
			AddQuestRecord("Hitman", 2);
			LAi_LocationFightDisable(&Locations[FindLocation("Hit_house")], 1); //Stops fight SCM
			LAi_SetHuberType(characterfromID("Mateus Santos")); //SCM
			ChangeCharacterAddressGroup(CharacterFromID("Mateus Santos"), "Hit_house", "sit", "sit1");//SCM
		break;

		case "Hit_kill_Ambroz":
		// dialog exit from Ambroz
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

			//KILL TIMER 1
			Pchar.quest.Hit_timer1.over = "yes";

			//Add journal entry
			AddQuestRecord("Hitman", 3);

			//Give XP
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 2500); }
			else { AddPartyExp(pchar, 2500); }
		break;

		case "Hit_spared_Ambroz":
		// dialog exit from Ambroz
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Hit_spared_Ambroz");

			bDisableFastReload = 1;

			LAi_SetPlayerType(PChar);
			LAi_SetActorType(CharacterFromID("Ambroz Bricenos"));
			LAi_ActorRunToLocation(CharacterFromID("Ambroz Bricenos"), "reload", "locator3", "none", "", "", "Hit_spared_Ambroz_end", 7.0);
		break;

		case "Hit_spared_Ambroz_end":
			EndQuestMovie();TrackQuestMovie("end","Hit_spared_Ambroz_end");

			bDisableFastReload = 0;

			//END QUEST
			LAi_QuestDelay("Hit_END", 0.0);

			//KILL TIMER 1
			Pchar.quest.Hit_timer1.over = "yes";

			//Add journal entry
			AddQuestRecord("Hitman", 4);

			//Give XP
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 2500); }
			else { AddPartyExp(pchar, 2500); }
		break;

		case "Hit_mark_Geffrey":
		// dialog exit from Mateus
			PChar.quest.Hitman = "mark_geffrey";

			PChar.quest.Hit_Geffrey.win_condition.l1 = "location";
			PChar.quest.Hit_Geffrey.win_condition.l1.character = PChar.id;
			PChar.quest.Hit_Geffrey.win_condition.l1.location = "Hit_house1";
			PChar.quest.Hit_Geffrey.win_condition = "Hit_Geffrey";

			chrEnableReloadLocator("Greenford_town", "reload5", 1);

			//TIMER 2
			LAi_QuestDelay("Hit_timer2", 0.0);

			//Add journal entry
			Preprocessor_AddQuestData("Geffrey Bampfylde", GetMyFullName(CharacterFromID("Geffrey Bampfylde")));
			AddQuestRecord("Hitman", 5);
			Preprocessor_Remove("Geffrey Bampfylde");
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
		// dialog exit from Geffrey
			LAi_SetPlayerType(PChar);
			LAi_ActorDialog(CharacterFromID("Bucho"), PChar, "", 1.0, -1);
		break;

		case "Hit_kill_Bucho":
		// dialog exit from Bucho
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

			//Give XP
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 1750); }
			else { AddPartyExp(pchar, 1750); }
		break;

		case "Hit_spare_Geffrey":
		// dialog exit from Geffrey
			LAi_ActorRunToLocation(CharacterFromID("Geffrey Bampfylde"), "reload", "reload1", "none", "", "", "Hit_spared_Geffrey", 4.0);
		break;

		case "Hit_spared_Geffrey":
			EndQuestMovie();TrackQuestMovie("end","Hit_spared_Geffrey");

			bDisableFastReload = 0;

			//END QUEST
			LAi_QuestDelay("Hit_END", 0.0);

			//KILL TIMER
			Pchar.quest.Hit_timer2.over = "yes";

			//Add journal entry
			Preprocessor_AddQuestData("Bampfylde", GetMyLastName(CharacterFromID("Geffrey Bampfylde")));
			AddQuestRecord("Hitman", 7);
			Preprocessor_Remove("Bampfylde");

			//Give XP
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 3000); }
			else { AddPartyExp(pchar, 3000); }
		break;

		case "Hit_kill_Geffrey":
		// dialog exit from Geffrey
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

			//KILL TIMER
			Pchar.quest.Hit_timer2.over = "yes";

			//Add journal entry
			AddQuestRecord("Hitman", 6);

			//Give XP
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 3000); }
			else { AddPartyExp(pchar, 3000); }
		break;

		case "Hit_mark_Pepin":
		// dialog exit from Mateus
			PChar.quest.Hitman = "mark_pepin";

			ChangeCharacterAddressGroup(CharacterFromID("Pepin Bertillon"), "QC_port", "goto", "goto12");
			ChangeCharacterAddressGroup(CharacterFromID("Bertillon's guard1"), "QC_port", "goto", "character11");
			ChangeCharacterAddressGroup(CharacterFromID("Bertillon's guard2"), "QC_port", "goto", "character12");

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
			PChar.quest.Hit_goto_QC_port.win_condition.l1.location = "QC_port";
			PChar.quest.Hit_goto_QC_port.win_condition = "Hit_goto_QC_port";

			//TIMER 3
			//LAi_QuestDelay("Hit_timer3", 0.0); //SCM

			//Add journal entry
			Preprocessor_AddQuestData("Bampfylde", GetMyLastName(CharacterFromID("Geffrey Bampfylde")));
			AddQuestRecord("Hitman", 8);
			Preprocessor_Remove("Bampfylde");
		break;

		case "Hit_goto_QC_port":
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
		// dialog exit from Pepin
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
			//END QUEST
			LAi_QuestDelay("Hit_END", 0.0);

			//KILL TIMER
			Pchar.quest.Hit_timer3.over = "yes";

			//Add journal entry
			AddQuestRecord("Hitman", 10);

			//Give XP
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 2000); }
			else { AddPartyExp(pchar, 2000); }
		break;

		case "Hit_kill_Pepin":
		// dialog exit from Pepin

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

			//KILL TIMER
			Pchar.quest.Hit_timer3.over = "yes";

			//Add journal entry
			AddQuestRecord("Hitman", 9);

			//Give XP
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 4500); }
			else { AddPartyExp(pchar, 4500); }
		break;

		case "Hit_mark_Amerigo":
		// dialog exit from Mateus
			PChar.quest.Hitman = "mark_amerigo";

			PChar.quest.Hit_Amerigo.win_condition.l1 = "location";
			PChar.quest.Hit_Amerigo.win_condition.l1.character = PChar.id;
			PChar.quest.Hit_Amerigo.win_condition.l1.location = "Hit_house2";
			PChar.quest.Hit_Amerigo.win_condition = "Hit_Amerigo";

			chrEnableReloadLocator("Conceicao_town", "reload15", 1);

			//TIMER 4
			//LAi_QuestDelay("Hit_timer4", 0.0); //SCM

			//Add journal entry
			AddQuestRecord("Hitman", 11);
		break;

		case "Hit_Amerigo":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Hit_Amerigo");

			bDisableFastReload = 1;

			LAi_SetActorType(PChar);
			LAi_ActorDialog(PChar, CharacterFromID("Amerigo Vieira"), "", 4.0, -1);
		break;

		case "Hit_kill_Amerigo":
		// dialog exit from Amerigo
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

			//KILL TIMER
			Pchar.quest.Hit_timer4.over = "yes";

			//Add journal entry
			AddQuestRecord("Hitman", 12);

			//Give XP
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 6000); }
			else { AddPartyExp(pchar, 6000); }
		break;

		case "Hit_spare_Amerigo":
		// dialog exit from Amerigo
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(CharacterFromID("Amerigo Vieira"));
			LAi_ActorRunToLocation(CharacterFromID("Amerigo Vieira"), "reload", "reload1", "none", "", "", "Hit_spared_Amerigo", 3.0);
		break;

		case "Hit_spared_Amerigo":
			EndQuestMovie();TrackQuestMovie("end","Hit_spared_Amerigo");

			bDisableFastReload = 0;

			//END QUEST
			LAi_QuestDelay("Hit_END", 0.0);

			//KILL TIMER
			Pchar.quest.Hit_timer4.over = "yes";

			//Add journal entry
			AddQuestRecord("Hitman", 13);

			//Give XP
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 4000); }
			else { AddPartyExp(pchar, 4000); }
		break;

		case "Hit_join_Amerigo":
		// dialog exit from Amerigo
			EndQuestMovie();TrackQuestMovie("end","Hit_join_Amerigo");

			bDisableFastReload = 0;

			PChar.quest.Hitman = "hit_amerigo";  //SCM
			LAi_SetPlayerType(PChar);
			LAi_SetOfficerType(CharacterFromID("Amerigo Vieira"));
			LAi_SetImmortal(CharacterFromID("Amerigo Vieira"), 0);
			AddPassenger(Pchar, characterFromID("Amerigo Vieira"), 0);   //BT May 09
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Amerigo Vieira"));
			Characters[GetCharacterIndex("Amerigo Vieira")].dialog.Filename = "Enc_Officer_dialog.c"; // GR
			Characters[GetCharacterIndex("Amerigo Vieira")].dialog.CurrentNode = "hired"; // GR

			//END QUEST
			//LAi_QuestDelay("Hit_END", 0.0);

			//KILL TIMER
			Pchar.quest.Hit_timer4.over = "yes";

			//Add journal entry
			AddQuestRecord("Hitman", 14);

			//Give XP
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2500);
				AddPartyExpChar(pchar, "Sneak", 1500);
			}
			else { AddPartyExp(pchar, 5000); }
		break;

		case "Hit_mark_Vito":
		// dialog exit from Mateus
			PChar.quest.Hitman = "mark_vito";
			LAi_SetStayType(CharacterFromID("Vito Leone"));
			ChangeCharacterAddressGroup(CharacterFromID("Vito Leone"), "Conceicao_church", "goto", "goto7");

			//TIMER 5
			//LAi_QuestDelay("Hit_timer5", 0.0); //SCM

			//Add journal entry
			AddQuestRecord("Hitman", 15);
		break;

		case "Hit_kill_Vito":
		// dialog exit from Vito

			bDisableFastReload = 1;

			LAi_LocationFightDisable(&Locations[FindLocation("Conceicao_church")], 0);

			LAi_SetActorType(CharacterFromID("Vito Leone"));
			LAi_SetImmortal(CharacterFromID("Vito Leone"), 0);
			LAi_CharacterDisableDialog(CharacterFromID("Vito Leone"));

			LAi_SetCheckMinHP(CharacterFromID("Vito Leone"), 0.0, 0, "Hit_killed_Vito");
		break;

		case "Hit_killed_Vito":
			PChar.quest.Hitman = "hit_vito";

			bDisableFastReload = 0;
			LAi_LocationFightDisable(&Locations[FindLocation("Conceicao_church")], 1);
			Characters[GetCharacterIndex("Vito Leone")].Location = "none";

			//KILL TIMER
			Pchar.quest.Hit_timer5.over = "yes";

			//Add journal entry
			AddQuestRecord("Hitman", 16);

			//Give XP
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 7000); }
			else { AddPartyExp(pchar, 7000); }
		break;

		case "Hit_spare_Vito":
		// dialog exit from Vito
			bDisableFastReload = 1;

			LAi_CharacterDisableDialog(CharacterFromID("Vito Leone"));

			Characters[GetCharacterIndex("Vito Leone")].Location = "none";

			PChar.quest.Hit_spared_Vito.win_condition.l1 = "location";
			PChar.quest.Hit_spared_Vito.win_condition.l1.character = PChar.id;
			PChar.quest.Hit_spared_Vito.win_condition.l1.location = "Conceicao_town";
			PChar.quest.Hit_spared_Vito.win_condition = "Hit_spared_Vito";

			LAi_group_SetRelation("santos_group", "santos_group", LAI_GROUP_ENEMY); //SCM
		break;

		case "Hit_spared_Vito":
			bDisableFastReload = 0;

			//END QUEST
			LAi_QuestDelay("Hit_END", 0.0);

			//KILL TIMER
			Pchar.quest.Hit_timer5.over = "yes";

			//Add journal entry
			AddQuestRecord("Hitman", 17);

			//Give XP
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 4000); }
			else { AddPartyExp(pchar, 4000); }
		break;

		case "Hit_mark_Mateus":
		// dialog exit from Vito
			PChar.quest.Hitman = "mark_mateus";
			Characters[GetCharacterIndex("Mateus Santos")].Location = "none"; //SCM
			ChangeCharacterAddressGroup(CharacterFromID("Mateus Santos"), "Hit_house", "goto", "goto3"); //SCM
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
			PChar.quest.Hit_Mateus.win_condition.l1.location = "Hit_house";
			PChar.quest.Hit_Mateus.win_condition = "Hit_Mateus";

			//KILL TIMER
			Pchar.quest.Hit_timer5.over = "yes";

			//Add journal entry
			Preprocessor_AddQuestData("person", XI_ConvertString(PChar.sex));
			AddQuestRecord("Hitman", 18);
			Preprocessor_Remove("person");
		break;

		case "Hit_Mateus":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Hit_Mateus");

			bDisableFastReload = 1;

			LAi_SetActorType(PChar);
			LAi_ActorDialog(PChar, CharacterFromID("Mateus Santos"), "", 4.0, -1); //SCM
		break;

		case "Hit_kill_Mateus":
		// dialog exit from Mateus
			LAi_LocationFightDisable(&Locations[FindLocation("Hit_house")], 0); //Fight ok SCM

			LAi_SetPlayerType(PChar);
			LAi_SetActorType(CharacterFromID("Mateus Santos")); //SCM
			LAi_SetImmortal(CharacterFromID("Mateus Santos"), 0); //SCM
			LAi_ActorAttack(CharacterFromID("Mateus Santos"), PChar, ""); //SCM
			LAi_SetCheckMinHP(CharacterFromID("Mateus Santos"), 0.0, 0, "Hit_killed_Mateus"); //SCM

			chrEnableReloadLocator("Hit_house", "Reload2", 1); //SCM
			chrEnableReloadLocator("Hit_house", "Reload1", 0); //SCM
			chrEnableReloadLocator("Hit_study", "Reload1", 0); //SCM for testing
			chrEnableReloadLocator("Hit_study", "Reload2_back", 1); //SCM
			chrEnableReloadLocator("Hit_passage", "Reload10", 1); //SCM

			LAi_SetImmortal(CharacterFromID("Thug2"), 0); //SCM
		break;

		case "Hit_killed_Mateus":
			EndQuestMovie();TrackQuestMovie("end","Hit_killed_Mateus");
			PChar.quest.Hitman = "hit_mateus";
			Characters[GetCharacterIndex("Mateus Santos")].Location = "none"; //SCM

			GiveItem2Character(pchar, "Santos_Ring"); //SCM
			GiveItem2Character(pchar, "Santos_Keys"); //SCM
			GiveItem2Character(pchar, "Santos_Journal1"); //SCM
			GiveItem2Character(pchar, "Santos_Journal2"); //SCM

			LAi_SetStayType(CharacterFromID("Vito Leone")); //SCM
			ChangeCharacterAddressGroup(CharacterFromID("Vito Leone"), "Muelle_church", "goto", "goto9"); //SCM

			LAi_SetStayType(CharacterFromID("Desiree' Muerte")); //SCM
			ChangeCharacterAddressGroup(CharacterFromID("Desiree' Muerte"), "Muelle_church", "goto", "goto4"); //SCM

			LAi_SetStayType(CharacterFromID("Thug3")); //SCM
			ChangeCharacterAddressGroup(CharacterFromID("Thug3"), "Muelle_church", "goto", "goto5"); //SCM

			PChar.quest.Hit_congrats.win_condition.l1 = "location"; // GR: was "locator", which doesn't work if 'win_condition.l1.locator' is commented out
			PChar.quest.Hit_congrats.win_condition.l1.location = "Muelle_church";
			// PChar.quest.Hit_congrats.win_condition.l1.locator_group = "goto";
			//PChar.quest.Hit_congrats.win_condition.l1.locator = "goto7"; //SCM
			PChar.quest.Hit_congrats.win_condition.l1.character = PChar.id;
			PChar.quest.Hit_congrats.win_condition = "Hit_congrats";

			//Give XP
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 7000); }
			else { AddPartyExp(pchar, 7000); }
		break;

		case "Hit_congrats":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Hit_congrats");
			LAi_SetActorType(PChar);
			LAi_ActorDialog(PChar, CharacterFromID("Vito Leone"), "", 4.0, -1);
		break;

		case "Hit_complete":
		// dialog exit from Vito
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(CharacterFromID("Vito Leone"));
			LAi_ActorGoToLocation(CharacterFromID("Vito Leone"), "reload", "reload2", "none", "", "", "Hit_complete_end", 3.0); //SCM
			LAi_SetActorType(CharacterFromID("Desiree' Muerte")); //SCM
			LAi_ActorGoToLocation(CharacterFromID("Desiree' Muerte"), "reload", "reload2", "none", "", "", "", 3.0); //SCM
			LAi_SetActorType(CharacterFromID("Thug3")); //SCM
			LAi_ActorGoToLocation(CharacterFromID("Thug3"), "reload", "reload2", "none", "", "", "", 3.0); //SCM
			LAi_SetHuberStayType(characterFromID("Thug9")); //SCM
			ChangeCharacterAddressGroup(CharacterFromID("Thug9"), "Muelle_church", "goto", "goto1"); //SCM
			LAi_SetActorType(CharacterFromID("Thug9"));  //SCM
			LAi_ActorRunToLocation(CharacterFromID("Thug9"), "reload", "reload1", "none", "", "", "", 2.0); //SCM
		break;

		case "Hit_complete_end":
			EndQuestMovie();TrackQuestMovie("end","Hit_complete_end");
			bDisableFastReload = 0;

			//END QUEST
			LAi_QuestDelay("Hit_END", 0.0);

			//Add journal entry
			AddQuestRecord("Hitman", 19);
			CloseQuestHeader("Hitman");
			ItemSetPrice("Santos_Keys", 1);		// Keys can now be dumped in ship's chest.
		break;

		// GR: Easter Egg if you have a "Black Pearl" or variant -->
		case "Hit_Sparrow_runs_away":
			ch = CharacterFromID("Thug9");
			LAi_SetActorType(ch);
			ChangeCharacterAddressGroup(ch, "Hit_passage", "goto", "goto14");
			LAi_ActorRunToLocation(ch, "reload", "Reload10", "none", "", "", "", 20.0);
			ch.nation = PIRATE;
			ch.flags.pirate = 6;
			ch.flags.pirate.texture = 0;
			GiveShip2Character(ch,GetCharacterShipID(PChar),PChar.Ship.Name,-1,PIRATE,true,true);
			GiveShip2Character(PChar,"HMS_Interceptor","Interceptor",-1,ENGLAND,true,true);
			SetCharacterShipLocation(ch, "Muelle_port");
			ShipsTypes[GetShipIndex(GetCharacterShipID(ch))].jetty = false;	// Otherwise stolen Pearl appears moored at jetty
			ch.sailaway = true;
			PChar.quest.Hit_Steal_Ship.win_condition.l1 = "location";
			PChar.quest.Hit_Steal_Ship.win_condition.l1.location = GetCharacterShipLocation(PChar);
			PChar.quest.Hit_Steal_Ship.win_condition = "Hit_Steal_Ship";
		break;

		case "Hit_Steal_Ship":
			ch = CharacterFromID("Thug9");
			ChangeCharacterAddress(ch, "none", "");
			SetCharacterShipLocation(ch, "none");

			LAi_SetActorType(PChar);
			PChar.dialog.currentnode = "Sparrow_steals_ship";
			LAi_ActorSelfDialog(PChar, "player_back");
		break;
		// <-- GR: Easter Egg if you have a "Black Pearl" or variant

///////////////////////////////////////////////////////////////
// Peter Blood by Bartolomeu o Portugues
///////////////////////////////////////////////////////////////

		//Bartolomeu
		case "Bart_start":
			SetEnterLocationQuest("Grand_Cayman_Tavern", "Bart_start_check", 0);
		break;

		case "Bart_start_check":
			if(makeint(PChar.rank) >= 1)
			{
				ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu o Portugues"), "Grand_Cayman_Tavern", "goto", "goto1");
			}
		break;

		case "Bart_search_refused":
			PChar.quest.Bartolomeu = "refused";
			SetQuestHeader("Bartolomeu");
			AddQuestRecord("Bartolomeu", 11);
			DeleteEnterLocationQuest("Grand_Cayman_Tavern", "Bart_start_check");
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			LAi_ActorGoToLocation(CharacterFromID("Bartolomeu o Portugues"), "reload", "reload1", "none", "", "", "adeus", 5.0);
		break;

		case "adeus":
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].Location = "none";
			PChar.quest.Bartolomeu = "end";
			PChar.quest.Bartolomeu.over = "yes";
			CloseQuestHeader("Bartolomeu");
		break;

		case "Bart_start_search":
			PChar.quest.Bartolomeu = "search";

			DeleteEnterLocationQuest("Grand_Cayman_Tavern", "Bart_start");
			Locations[FindLocation("Cuba_port")].reload.l1.disable = true;
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			LAi_SetImmortal(CharacterFromID("Bartolomeu o Portugues"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Bartolomeu o Portugues"), "", 60.0);
//			DisableFastTravel(true);
//			DisableMenuLaunch(true);
//			bSuppressResurrection = true;
			SetQuestHeader("Bartolomeu");
			AddQuestRecord("Bartolomeu", 1);
			Pchar.quest.Bartolomeu.win_condition.l1 = "location";
			Pchar.quest.Bartolomeu.l1.character = "Bartolomeu o Portugues";
			Pchar.quest.Bartolomeu.win_condition.l1.location = "Cuba_shore_01";
			PChar.quest.Bartolomeu.win_condition = "essai";
		break;

		case "essai":
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			bSuppressResurrection = true;
			SetCurrentTime(12, 0);
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "came";
			LAi_ActorDialog(characterFromID("Bartolomeu o Portugues"), pchar, "", 0.0, 1.0);
		break;

		case "fight":
			locations[FindLocation("Cuba_shore_01")].reload.l1.disable = 1;
			locations[FindLocation("Cuba_shore_01")].reload.l2.disable = 1;
			locations[FindLocation("Cuba_shore_01")].reload.l3.disable = 1;
			LAi_SetOfficerType(characterFromID("Bartolomeu o Portugues"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "reload", "reload2"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "reload", "reload2"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "reload", "reload2"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "reload", "reload2"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "reload", "reload2"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "reload", "reload2"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			LAi_group_FightGroups("SHORE_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("SHORE_SOLDIERS", "essai_2");
		break;

		case "essai_2":
			AddQuestRecord("Bartolomeu", 2);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2500);
				AddPartyExpChar(pchar, "Sneak", 1000);
			}
			else { AddPartyExp(pchar, 2500); }
			LAi_SetStayType(pchar);
			locations[FindLocation("Cuba_shore_01")].reload.l1.disable = 0;
			locations[FindLocation("Cuba_shore_01")].reload.l2.disable = 0;
			locations[FindLocation("Cuba_shore_01")].reload.l3.disable = 0;

			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "in_shore";
			LAi_ActorDialog(characterFromID("Bartolomeu o Portugues"), pchar, "", 2.0, 1.0);
		break;

		case "bartfollow":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			LAi_SetImmortal(CharacterFromID("Bartolomeu o Portugues"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Bartolomeu o Portugues"), "", 60.0);

			PChar.quest.Bartolomeu = "crew";
			Pchar.quest.Bartolomeu.win_condition.l1 = "location";
			Pchar.quest.Bartolomeu.l1.character = "Bartolomeu o Portugues";
			Pchar.quest.Bartolomeu.win_condition.l1.location = "Havana_town_05";
			PChar.quest.Bartolomeu.win_condition = "outhavana";
		break;

		case "outhavana":
			Locations[FindLocation("Havana_town_05")].reload.l3.disable = true;
			Locations[FindLocation("Havana_town_05")].reload.l21.disable = true;
			Locations[FindLocation("Havana_town_05")].reload.l4.disable = true;
			Locations[FindLocation("Havana_town_05")].reload.l22.disable = true;

			LAi_SetPlayerType(pchar);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto_24"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			sld.dialog.filename = "Bartolomeu o Portugues_dialog.c";
			sld.dialog.currentnode = "guarda";
			sld.id = "soldat";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto_43"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetActorType(sld);
			LAi_ActorFollow (sld, pchar, "", 10);
			sld.id = "soldat1";
			LAi_group_MoveCharacter(sld, "GATE_SOLDIERS");
			LAi_SetActorType(characterfromID("soldat"));
			LAi_ActorDialog(characterfromID("soldat"), PChar, "", 0.5, 10);
		break;

		case "fight_2":
			LAi_SetWarriorType(characterfromID("soldat"));
			LAi_SetWarriorType(characterfromID("soldat1"));
			LAi_group_MoveCharacter(characterFromID("soldat"), "GATE_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("soldat1"), "GATE_SOLDIERS");
			LAi_group_SetCheck("GATE_SOLDIERS", "hurry");
			LAi_group_FightGroups("GATE_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_SetOfficerType(characterFromID("Bartolomeu o Portugues"));
		break;

		case "hurry":
			LAi_SetStayType(pchar);
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "savecrew";
			LAi_ActorDialog(characterFromID("Bartolomeu o Portugues"), pchar, "", 1.0, 1.0);
			AddQuestRecord("Bartolomeu", 3);
		break;

		case "goverplace":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			LAi_SetImmortal(CharacterFromID("Bartolomeu o Portugues"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Bartolomeu o Portugues"), "", 60.0);

			Locations[FindLocation("Havana_town_05")].reload.l3.disable = false;
			Locations[FindLocation("Havana_town_05")].reload.l21.disable = false;
			Locations[FindLocation("Havana_town_05")].reload.l4.disable = false;
			Locations[FindLocation("Havana_town_05")].reload.l22.disable = false;
			Locations[FindLocation("Havana_town_02")].vcskip = true;

			PChar.quest.Bartolomeu = "hang";
			Pchar.quest.Bartolomeu.win_condition.l1 = "location";
			Pchar.quest.Bartolomeu.l1.character = "Bartolomeu o Portugues";
			Pchar.quest.Bartolomeu.win_condition.l1.location = "Havana_town_02";
			PChar.quest.Bartolomeu.win_condition = "discours";
		break;

		case "discours":
			Locations[FindLocation("Havana_town_02")].reload.l1.disable = true;
			Locations[FindLocation("Havana_town_02")].reload.l2.disable = true;
			Locations[FindLocation("Havana_town_02")].reload.l3.disable = true;
			Locations[FindLocation("Havana_town_02")].reload.l4.disable = true;
			Locations[FindLocation("Havana_town_02")].reload.l5.disable = true;
			Locations[FindLocation("Havana_town_02")].reload.l7.disable = true;
			Locations[FindLocation("Havana_town_02")].reload.l8.disable = true;
			Locations[FindLocation("Havana_town_02")].reload.l10.disable = true;
			Locations[FindLocation("Havana_town_02")].reload.l11.disable = true;			
			
			DeleteAttribute(&Locations[FindLocation("Havana_town_02")],"vcskip");

			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_01"), "Havana_town_02", "goto", "goto30");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_02"), "Havana_town_02", "goto", "goto31");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_03"), "Havana_town_02", "goto", "goto32");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_04"), "Havana_town_02", "goto", "goto33");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_05"), "Havana_town_02", "goto", "goto34");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_06"), "Havana_town_02", "goto", "goto35");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto36"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto37"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto38"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto39"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto40"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "goto", "goto41"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SOLDATOS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "animists2", "goto", "goto42");
			LAi_SetHP(sld, 80.0, 80.0);
  			LAi_group_MoveCharacter(sld, "SOLDATOS");
			sld.dialog.filename = "Bartolomeu o Portugues_dialog.c";
			sld.dialog.currentnode = "devil";
			sld.id = "bourreau";
			// PB: Hangman should use axe -->
			TakeItemFromCharacter(sld, GetCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));	// Takes hangman's random blade away
			TakeItemFromCharacter(sld, GetCharacterEquipByGroup(sld, GUN_ITEM_TYPE));	// Takes hangman's random gun away
			GiveItem2Character(sld,"bladeaxe1");										// Gives hangman an axe
			EquipCharacterByItem(sld,"bladeaxe1");										// Equips the axe
			// PB: Hangman should use axe <--

            LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "goto44", "beforevent", 38.0);
		break;

		case "beforevent":
			//LAi_ActorTurnToCharacter(pchar, characterFromID("bourreau"));useless line now!!
			LAi_SetStayType(pchar);
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "before";
			LAi_ActorDialog(characterFromID("Bartolomeu o Portugues"), pchar, "", 9.0, 1.0);
		break;

		case "commandant":
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			LAi_SetImmortal(CharacterFromID("Bartolomeu o Portugues"), 1);
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "goto43", "talkhangman", 21.0)
		break ;

		case "talkhangman" :
			LAi_SetStayType(pchar);
			LAi_SetActorType(characterFromID("bourreau"));
			LAi_ActorDialog(characterfromID("bourreau"), PChar, "", 1, 1.0);
		break;

		case "combat":
			LAi_ActorAttack(CharacterFromID("bourreau"), PChar, "");
			LAi_SetPlayerType(Pchar);
			LAi_QuestDelay("fight_4", 2.0);
		break;

		case "fight_4":
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			LAi_SetOfficerType(characterFromID("Bartolomeu o Portugues"));
			LAi_group_FightGroups("SOLDATOS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SOLDATOS", "fuite");
		break;

		case "fuite":
			LAi_KillCharacter(characterFromID("bourreau"));
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			LAi_SetImmortal(CharacterFromID("Bartolomeu o Portugues"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Bartolomeu o Portugues"), "", 60.0);
			LAi_SetActorType(characterFromID("bart_pirate_01"));
			LAi_SetImmortal(CharacterFromID("bart_pirate_01"), 1);
			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_01"), "", 60.0);
			LAi_SetActorType(characterFromID("bart_pirate_02"));
			LAi_SetImmortal(CharacterFromID("bart_pirate_02"), 1);
			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_02"), "", 60.0);
			LAi_SetActorType(characterFromID("bart_pirate_03"));
			LAi_SetImmortal(CharacterFromID("bart_pirate_03"), 1);
			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_03"), "", 60.0);
			LAi_SetActorType(characterFromID("bart_pirate_04"));
			LAi_SetImmortal(CharacterFromID("bart_pirate_04"), 1);
			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_04"), "", 60.0);
			LAi_SetActorType(characterFromID("bart_pirate_05"));
			LAi_SetImmortal(CharacterFromID("bart_pirate_05"), 1);
			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_05"), "", 60.0);
			LAi_SetActorType(characterFromID("bart_pirate_06"));
			LAi_SetImmortal(CharacterFromID("bart_pirate_06"), 1);
			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_06"), "", 60.0);
			LAi_SetStayType(pchar);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2500);
				AddPartyExpChar(pchar, "Sneak", 1000);
			}
			else { AddPartyExp(pchar, 2500); }
			LAi_QuestDelay("rencontre", 4.0);
		break;

		case "rencontre":
			PChar.quest.Bartolomeu = "rencontrer";
			LAi_SetActorType(characterFromID("bart_pirate_06"));
			characters[GetCharacterIndex("bart_pirate_06")].dialog.currentnode = "First time";
			LAi_ActorDialog(characterfromID("bart_pirate_06"), PChar, "", 1.0, 1.0);
		break;

		case "rencontrebc":
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "bartpirat";
			LAi_ActorDialog(characterFromID("Bartolomeu o Portugues"), PChar, "", 1.0, 1.0);
		break;

		case "bartmoi":
			Locations[FindLocation("Havana_town_02")].reload.l1.disable = false;
			Locations[FindLocation("Havana_town_02")].reload.l2.disable = false;
			Locations[FindLocation("Havana_town_02")].reload.l3.disable = false;
			Locations[FindLocation("Havana_town_02")].reload.l4.disable = false;
			Locations[FindLocation("Havana_town_02")].reload.l5.disable = false;
			Locations[FindLocation("Havana_town_02")].reload.l7.disable = false;
			Locations[FindLocation("Havana_town_02")].reload.l8.disable = false;
			Locations[FindLocation("Havana_town_02")].reload.l10.disable = false;
			Locations[FindLocation("Havana_town_02")].reload.l11.disable = false;			

			LAi_ActorFollowEverywhere(characterFromID("bart_pirate_06"), "", 60.0);
			DoReloadCharacterToLocation("Havana_Outskirts", "goto", "goto9");
			Locations[FindLocation("Havana_Outskirts")].reload.l1.disable = true;
			ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu O Portugues"), "Havana_Outskirts", "goto", "goto8");
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "outcity";
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			LAi_ActorWaitDialog(CharacterFromID("Bartolomeu O Portugues"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Bartolomeu O Portugues"), "", 10.0, 1.0);
			AddQuestRecord("Bartolomeu", 4);
		break;

		case "fight_5":
			LAi_SetPlayerType (Pchar);
			LAi_SetOfficerType(characterFromID("Bartolomeu o Portugues"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "reload", "reload1"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPANISHS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "reload", "reload1"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPANISHS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "reload", "reload1"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPANISHS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "reload", "reload1"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPANISHS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "reload", "reload1"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPANISHS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "reload", "reload1"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SPANISHS");

			LAi_group_FightGroups("SPANISHS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("SPANISHS", "evasion_2");
		break;

		case "evasion_2":
			LAi_SetStayType(pchar);
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			Locations[FindLocation("Havana_Outskirts")].reload.l1.disable = false;
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "avantplage";
			LAi_ActorDialog(characterFromID("Bartolomeu o Portugues"), PChar, "", 0.0, 1.0);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2500);
				AddPartyExpChar(pchar, "Sneak", 1000);
			}
			else { AddPartyExp(pchar, 2500); }
		break;

		case "evasion_3":
			AddQuestRecord("Bartolomeu", 5);
			PChar.quest.Bartolomeu = "evas";
			LAi_SetPlayerType (Pchar);
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			LAi_ActorFollowEverywhere(characterFromID("Bartolomeu o Portugues"), "", 60.0);
			Pchar.quest.Bartolomeu.win_condition.l1 = "location";
			Pchar.quest.Bartolomeu.l1.character = "Bartolomeu o Portugues";
			Pchar.quest.Bartolomeu.win_condition.l1.location = "Cuba_shore_01";
			PChar.quest.Bartolomeu.win_condition = "plage";
		break;

		case "plage":
			Locations[FindLocation("Cuba_shore_01")].reload.l3.disable = true;
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "locator26", "plage_1", 10.0)
			ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu o Portugues"), "Cuba_shore_01", "reload", "reload2");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_01"), "Cuba_shore_01", "reload", "reload2");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_02"), "Cuba_shore_01", "reload", "reload2");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_03"), "Cuba_shore_01", "reload", "reload2");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_04"), "Cuba_shore_01", "reload", "reload2");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_05"), "Cuba_shore_01", "reload", "reload2");
			ChangeCharacterAddressGroup(CharacterFromID("bart_pirate_06"), "Cuba_shore_01", "reload", "reload2");
		break;

		case "plage_1":
			LAi_SetStayType(pchar);
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "second";
			LAi_ActorDialog(characterFromID("Bartolomeu o Portugues"), PChar, "", 4.0, 1.0);
			LAi_SetOfficerType(characterFromID("bart_pirate_01"));
			LAi_SetOfficerType(characterFromID("bart_pirate_02"));
			LAi_SetOfficerType(characterFromID("bart_pirate_03"));
			LAi_SetOfficerType(characterFromID("bart_pirate_04"));
			LAi_SetOfficerType(characterFromID("bart_pirate_05"));
			LAi_SetOfficerType(characterFromID("bart_pirate_06"));
		break;

		case "embarquer":
			PChar.quest.Bartolomeu = "contact";
			LAi_SetPlayerType (Pchar);
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			ChangeCharacterAddressGroup(CharacterFromID("Juan Hernandez"), "Santiago_port", "goto", "goto24");
			LAi_SetCitizenType(CharacterFromID("Juan Hernandez"));
			ChangeCharacterAddress(characterFromID("bart_pirate_01"), "none", "");
			ChangeCharacterAddress(characterFromID("bart_pirate_02"), "none", "");
			ChangeCharacterAddress(characterFromID("bart_pirate_03"), "none", "");
			ChangeCharacterAddress(characterFromID("bart_pirate_04"), "none", "");
			ChangeCharacterAddress(characterFromID("bart_pirate_05"), "none", "");
			ChangeCharacterAddress(characterFromID("bart_pirate_06"), "none", "");
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "crewship";
			LAi_ActorDialog(characterFromID("Bartolomeu o Portugues"), PChar, "", 1.0, 1.0);
			AddQuestRecord("Bartolomeu", 6);

			DisableFastTravel(false);
			DisableMenuLaunch(false);
			bSuppressResurrection = false;
		break;

		case "walkcrew":
			PChar.quest.Bartolomeu = "blackcorsair";
			ChangeCharacterAddressGroup(CharacterFromID("Emilio Soares"), "Santiago_town_exit2", "goto", "locator9");
			LAi_SetCitizenType(CharacterFromID("Emilio Soares"));
			AddQuestRecord("Bartolomeu", 7);
		break;

		case "quitcuba":
			Locations[FindLocation("Cuba_shore_01")].reload.l3.disable = false;
			LAi_SetOfficerType(characterFromID("Juan Hernandez"));
			ChangeCharacterAddress(characterFromID("Juan Hernandez"), "none", "");
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "horscuba";
			LAi_ActorDialog(characterFromID("Bartolomeu o Portugues"), PChar, "", 0.0, 1.0);
		break;

		case "directredmond":
			AddQuestRecord("Bartolomeu", 8);
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			LAi_ActorFollowEverywhere(characterFromID("Bartolomeu o Portugues"), "", 60.0);
			LAi_SetActorType(characterFromID("Emilio Soares"));
			LAi_SetImmortal(characterFromID("Emilio Soares"), true);
			LAi_ActorFollowEverywhere(characterFromID("Emilio Soares"), "", 60.0);
			PChar.quest.Bartolomeu = "dernier";
			Pchar.quest.Bartolomeu.win_condition.l1 = "location";
			Pchar.quest.Bartolomeu.l1.character = "Bartolomeu o Portugues";
			Pchar.quest.Bartolomeu.win_condition.l1.location = "Redmond_Town_01";
			PChar.quest.Bartolomeu.win_condition = "mercenaires";
			Locations[FindLocation("Redmond_Town_01")].vcskip = true;
		break;

		case "mercenaires":
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			bSuppressResurrection = true;

			Locations[FindLocation("Redmond_Town_01")].reload.l1.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l2.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l3.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l5.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l6.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l8.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l9.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l10.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l11.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l12.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l13.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l14.disable = true;
			Locations[FindLocation("Redmond_Town_01")].reload.l15.disable = true;

			LAi_SetOfficerType(characterFromID("Emilio Soares"));
			ChangeCharacterAddress(characterFromID("Emilio Soares"), "none", "");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Man3", "goto", "goto16");
			LAi_SetHP(sld, 120.0, 120.0);
			sld.dialog.filename = "Bartolomeu o Portugues_dialog.c";
			sld.dialog.currentnode = "lafin";
			sld.id = "chef";

			LAi_SetActorType(characterFromID("chef"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Pirat8", "goto", "goto17");
			LAi_SetHP(sld, 120.0, 120.0);
			LAi_group_MoveCharacter(sld, "mercenary");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Pirat9", "goto", "goto18");
			LAi_SetHP(sld, 120.0, 120.0);
			LAi_group_MoveCharacter(sld, "mercenary");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Pirat13", "goto", "goto19");
			LAi_SetHP(sld, 120.0, 120.0);
			LAi_group_MoveCharacter(sld, "mercenary");

			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "goto15", "dispute_2", 20.0);
		break;

		case "dispute_2":
			LAi_SetPlayerType (Pchar);
			LAi_SetActorType(characterFromID("chef"));
			LAi_ActorDialog(characterFromID("chef"), PChar, "", 0.0, 1.0);
		break;

		case "dispute_3":
			LAi_ActorAttack(CharacterFromID("chef"), PChar, "");
			LAi_QuestDelay("dispute_4", 2.0);
		break;

		case "dispute_4":
			LAi_SetOfficerType(characterFromID("Bartolomeu o Portugues"));
			LAi_group_FightGroups("mercenary", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("mercenary", "findefin");
		break;

		case "findefin":
			DeleteAttribute(&Locations[FindLocation("Redmond_Town_01")],"vcskip");
			Locations[FindLocation("Redmond_Town_01")].reload.l1.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l2.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l3.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l5.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l6.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l8.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l9.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l10.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l11.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l12.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l13.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l14.disable = false;
			Locations[FindLocation("Redmond_Town_01")].reload.l15.disable = false;
			Locations[FindLocation("Cuba_port")].reload.l1.disable = false;

			bSuppressResurrection = false;
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			LAi_KillCharacter(characterFromID("chef"));
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "lafin_2";
			LAi_ActorDialog(characterFromID("Bartolomeu O Portugues"), PChar, "", 0.0, 1.0);
		break;

		case "bartofficer":
			PChar.Quest.Bartolomeu = "1";
			AddQuestRecord("Bartolomeu", 9);
			CloseQuestHeader("Bartolomeu");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			LAi_SetImmortal(characterFromID("Bartolomeu O Portugues"), false);
			AddPassenger(Pchar, characterFromID("Bartolomeu O Portugues"), 0);
			SetOfficersIndex(Pchar, 9, getCharacterIndex("Bartolomeu O Portugues"));
			LAi_SetOfficerType(characterFromID("Bartolomeu O Portugues"));
			SetCrewQuantity(pchar, makeint(GetCrewQuantity(pchar) + 7));
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.filename = "Enc_Officer_dialog.c";
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.CurrentNode = "hired";
		break;

		case "bartbye":
			AddQuestRecord("Bartolomeu", 10);
			CloseQuestHeader("Bartolomeu");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			LAi_SetImmortal(characterFromID("Bartolomeu O Portugues"), false);
			LAi_ActorGoToLocator(characterFromID("Bartolomeu O Portugues"), "goto", "goto24", "disparu", 40.0);
		break;

		case "disparu":
			LAi_SetOfficerType(characterFromID("Bartolomeu O Portugues"));
			ChangeCharacterAddress(characterFromID("Bartolomeu O Portugues"), "none", "");
		break;


///////////////////////////////////////////////////////////////
// Turks Help by Bartolomeu o Portugues
///////////////////////////////////////////////////////////////

		case "Turks_start":
			SetEnterLocationQuest("Turks_Tavern", "Turks_start_check", 0);
		break;

		case "Turks_start_check":
			if(makeint(PChar.rank) >= 10)
			{
				ChangeCharacterAddressGroup(CharacterFromID("Pieter Boelen"), "Turks_Tavern", "goto", "goto6");
			}
		break;

		case "Turks_search_refused":
			PChar.quest.Turkshelp = "refused";
			DeleteEnterLocationQuest("Turks_Tavern", "Turks_start_check");
			LAi_SetActorType(characterFromID("Pieter Boelen"));
			LAi_ActorGoToLocation(characterFromID("Pieter Boelen"), "reload", "reload1", "none", "", "", "", 0.0);

			SetQuestHeader("Turkshelp");
			AddQuestRecord("Turkshelp", 7);
			CloseQuestHeader("Turkshelp");
		break;

		case "Turks_start_search":
			PChar.quest.Turkshelp = "search";
			DeleteEnterLocationQuest("Turks_Tavern", "Turks_start_check");
			LAi_SetImmortal(CharacterFromID("Pieter Boelen"), 1);
			bSuppressResurrection = true;
			SetQuestHeader("Turkshelp");
			AddQuestRecord("Turkshelp", 1);
			ChangeCharacterAddressGroup(CharacterFromID("Diego Cordoba"), "Santiago_Tavern", "goto", "goto3");

			LAi_QuestDelay("Turks_timer1", 0.0);
		break;

		case "meetboca":
			DoReloadCharacterToLocation("Cuba_shore_02", "goto", "goto11");
			LAi_SetStayType(pchar);
			ChangeCharacterAddressGroup(CharacterFromID("Diego Cordoba"), "Cuba_shore_02", "goto", "goto16");
			locations[FindLocation("Cuba_shore_02")].reload.l2.disable = 1;
			locations[FindLocation("Cuba_shore_02")].reload.l1.disable = 1;
			pchar.location.from_sea = "Cuba_shore_02";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK
			Characters[GetCharacterIndex("Diego Cordoba")].dialog.currentnode = "begin_4";
			LAi_SetActorType(characterFromID("Diego Cordoba"));
			Pchar.quest.Turks_timer1.over = "yes";
			LAi_QuestDelay("parle", 1.0);
		break;

		case "parle":
			LAi_ActorDialog(characterFromID("Diego Cordoba"), pchar, "", 0.0, 2.0);
		break;

		case "fightboca":
			LAi_SetPlayerType(pchar);
			LAi_SetImmortal(CharacterFromID("Diego Cordoba"), 1);
			LAi_ActorAttack(CharacterFromID("Diego Cordoba"), PChar, "");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto12"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto12"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto12"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto12"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			LAi_group_FightGroups("SHORE_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("SHORE_SOLDIERS", "diegosurrender");
		break;

		case "diegosurrender":
			LAi_SetActorType(characterFromID("Diego Cordoba"));
			Characters[GetCharacterIndex("Diego Cordoba")].dialog.currentnode = "begin_8";
			LAi_ActorDialog(characterFromID("Diego Cordoba"), pchar, "", 1.0, 1.0);
		break;

		case "gototurks":
			LAi_SetActorType(characterFromID("Diego Cordoba"));
			LAi_ActorRunToLocation(characterFromID("Diego Cordoba"), "reload", "reload3", "none", "", "", "diegoship", 0.0);
		break;

		case "diegoship":
			locations[FindLocation("Cuba_shore_02")].reload.l2.disable = 0;
			locations[FindLocation("Cuba_shore_02")].reload.l1.disable = 0;

			AddQuestRecord("Turkshelp", 2);
			PChar.quest.Turkshelp = "news";
			Pchar.quest.Turkshelp.win_condition.l1 = "location";
			Pchar.quest.Turkshelp.win_condition.l1.location = "Turks_Tavern";
			PChar.quest.Turkshelp.win_condition = "givenews";
			LAi_QuestDelay("Turks_timer2", 0.0);
		break;

		case "givenews":
			Characters[GetCharacterIndex("Pieter Boelen")].dialog.currentnode = "begin_8";
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Pieter Boelen"));
			LAi_ActorWaitDialog(CharacterFromID("Pieter Boelen"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Pieter Boelen"), "", 10.0, 1.0);
			Pchar.quest.Turks_timer2.over = "yes";
		break;

		case "guetteur":
			LAi_SetPlayerType (Pchar);
			ChangeCharacterAddressGroup(CharacterFromID("lookout"), "Turks_Tavern", "goto", "goto5");
			Characters[GetCharacterIndex("lookout")].dialog.currentnode = "First time";
			LAi_SetActorType(characterFromID("lookout"));
			LAi_ActorDialog(characterFromID("lookout"), pchar, "", 1.0, 1.0);
		break;

		case "turtleplage":
			LAi_SetActorType(characterFromID("Pieter Boelen"));
			Characters[GetCharacterIndex("Pieter Boelen")].dialog.currentnode = "begin_10";
			LAi_ActorDialog(characterFromID("Pieter Boelen"), pchar, "", 1.0, 1.0);
			AddQuestRecord("Turkshelp", 3);
			locations[FindLocation("Turks_port")].reload.l2.disable = 1;	//JRH: new Turks, locked to sea now instead
		break;

		case "depart":
			LAi_SetActorType(characterFromID("Pieter Boelen"));
			LAi_ActorRunToLocation(characterFromID("Pieter Boelen"), "reload", "reload1", "none", "", "", "", 0.0);
			LAi_ActorRunToLocation(characterFromID("lookout"), "reload", "reload1", "none", "", "", "", 0.0);
			LAi_QuestDelay("Turks_timer3", 0.0);
			setCharacterShipLocation(characterFromID("Captain"), "Turks_Lighthouse");
			
			PChar.quest.Turkshelp = "marche";
			Pchar.quest.Turkshelp.win_condition.l1 = "location";			
			Pchar.quest.Turkshelp.win_condition.l1 = "location";
			Pchar.quest.Turkshelp.win_condition.l1.location = "Turks_Lighthouse";
			PChar.quest.Turkshelp.win_condition = "fightturtle";
			
			locations[FindLocation("Turks_port")].reload.l5.disable = 1;	//JRH: new Turks shipyard
			locations[FindLocation("Turks_port")].reload.l3.disable = 1;	//JRH: new Turks townhall
			locations[FindLocation("Turks_port")].reload.l10.disable = 1;	//JRH: new Turks store
			locations[FindLocation("Turks_port")].reload.l13.disable = 1;	//JRH: new Turks blacksmith
			locations[FindLocation("Turks_port")].reload.l14.disable = 1;	//JRH: new Turks library
			locations[FindLocation("Turks_port")].reload.l15.disable = 1;	//JRH: new Turks tailor
		break;

		case "fightturtle":
			Pchar.quest.Turks_timer3.over = "yes";

			locations[FindLocation("Turks_Lighthouse")].reload.l3.disable = 1;
			locations[FindLocation("Turks_Lighthouse")].reload.l1.disable = 1;
			locations[FindLocation("Turks_Lighthouse")].reload.l2.disable = 1;
			locations[FindLocation("Turks_Lighthouse")].reload.l5.disable = 1;

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "reload", "reload3"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "reload", "reload3"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "reload", "reload3"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "reload", "reload3"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "reload", "reload3"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "reload", "reload3"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "reload", "reload3"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "reload", "reload3"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "reload", "reload3"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "reload", "reload3"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "reload", "reload3"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "reload", "reload3"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_SOLDIERS");

			LAi_group_FightGroups("SHORE_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("SHORE_SOLDIERS", "stoplanding");
		break;

		case "stoplanding":
			locations[FindLocation("Turks_Lighthouse")].reload.l1.disable = 0;
			locations[FindLocation("Turks_Lighthouse")].reload.l2.disable = 0;
			locations[FindLocation("Turks_Lighthouse")].reload.l5.disable = 0;
			locations[FindLocation("Turks_Lighthouse")].reload.l3.disable = 0;

			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2500);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 2500); }
			AddQuestRecord("Turkshelp", 4);
			PChar.quest.Turkshelp = "ville";
			Pchar.quest.Turkshelp.win_condition.l1 = "location";
			Pchar.quest.Turkshelp.win_condition.l1.location = "Turks_port";						//JRH: new Turks
			PChar.quest.Turkshelp.win_condition = "horsville";
		break;

		case "horsville":
			ChangeCharacterAddressGroup(CharacterFromID("Pieter Boelen"), "Turks_port", "quest", "quest2");		//JRH: new Turks
			Characters[GetCharacterIndex("Pieter Boelen")].dialog.currentnode = "begin_12";
			LAi_SetActorType(characterFromID("Pieter Boelen"));
			LAi_ActorDialog(characterFromID("Pieter Boelen"), pchar, "", 1.0, 1.0);
		break;

		case "gotoport":
			AddQuestRecord("Turkshelp", 5);
			setCharacterShipLocation(characterFromID("Captain"), "none");
			LAi_ActorFollowEverywhere(characterFromID("Pieter Boelen"), "", 60.0);
			locations[FindLocation("Turks_port")].reload.l5.disable = 0;		//JRH: new Turks shipyard

			locations[FindLocation("Turks_port")].reload.l3.disable = 0;		//JRH: new Turks townhall
			locations[FindLocation("Turks_port")].reload.l10.disable = 0;		//JRH: new Turks store
			locations[FindLocation("Turks_port")].reload.l13.disable = 0;		//JRH: new Turks blacksmith
			locations[FindLocation("Turks_port")].reload.l14.disable = 0;		//JRH: new Turks library
			locations[FindLocation("Turks_port")].reload.l15.disable = 0;		//JRH: new Turks tailor

			locations[FindLocation("Turks_port")].reload.l2.disable = false;	//JRH: new Turks, unlocked to sea now instead
			PChar.quest.Turkshelp = "Tortuga";
			Pchar.quest.Turkshelp.win_condition.l1 = "location";
			Pchar.quest.Turkshelp.win_condition.l1.location = "Tortuga_port";
			PChar.quest.Turkshelp.win_condition = "finalstory";
			LAi_QuestDelay("Turks_timer4", 0.0);
		break;

		case "finalstory":
		    ChangeCharacterAddressGroup(CharacterFromID("Pieter Boelen"), "Tortuga_port", "goto", "goto31");
			LAi_SetActorType(characterFromID("Pieter Boelen"));
			Characters[GetCharacterIndex("Pieter Boelen")].dialog.currentnode = "begin_15";
			LAi_ActorDialog(characterFromID("Pieter Boelen"), pchar, "", 1.0, 1.0);
			Pchar.quest.Turks_timer4.over = "yes";
		break;

		case "aurevoir":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 15000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 15000); }
			bSuppressResurrection = false;
			AddMoneyToCharacter(pchar, 40000);
			AddQuestRecord("Turkshelp", 6);
			CloseQuestHeader("Turkshelp");
			LAi_SetActorType(characterFromID("Pieter Boelen"));
			LAi_ActorRunToLocation(characterFromID("Pieter Boelen"), "reload", "reload3", "none", "", "", "Pieter_at_Douwesen", 30.0);

			if (GetRMRelation(PChar, PIRATE) < REL_AFTERATTACK) SetRMRelation(PChar, PIRATE, REL_AFTERATTACK);	// GR: You helped a pirate settlement
		break;

		case "Turks_fin_timer":
			Characters[GetCharacterIndex("Pieter Boelen")].Location = "none";
			LAi_SetCivilianGuardianType(CharacterFromID("Pieter Boelen"));	// GR: otherwise he may follow you forever
			Characters[GetCharacterIndex("Diego Cordoba")].Location = "none";
			PChar.quest.Turkshelp = "end";
			PChar.quest.Turkshelp.over = "yes";

			AddQuestRecord("Turkshelp", 8);
			CloseQuestHeader("Turkshelp");

			// PB: Open up all locations, just in case -->
			locations[FindLocation("Hispaniola_shore_01")].reload.l2.disable = 0;
			locations[FindLocation("Hispaniola_shore_01")].reload.l3.disable = 0;
			locations[FindLocation("Turks_Lighthouse")].reload.l1.disable = 0;
			locations[FindLocation("Turks_Lighthouse")].reload.l2.disable = 0;
			locations[FindLocation("Turks_Lighthouse")].reload.l5.disable = 0;
			locations[FindLocation("Turks_Lighthouse")].reload.l3.disable = 0;
			locations[FindLocation("Turks_port")].reload.l5.disable = 0;		//JRH: new Turks shipyard

			locations[FindLocation("Turks_port")].reload.l3.disable = 0;		//JRH: new Turks townhall
			locations[FindLocation("Turks_port")].reload.l10.disable = 0;		//JRH: new Turks store
			locations[FindLocation("Turks_port")].reload.l13.disable = 0;		//JRH: new Turks blacksmith
			locations[FindLocation("Turks_port")].reload.l14.disable = 0;		//JRH: new Turks library
			locations[FindLocation("Turks_port")].reload.l15.disable = 0;		//JRH: new Turks tailor

			locations[FindLocation("Turks_port")].reload.l2.disable = false;	//JRH: new Turks, unlocked to sea now instead
			// PB: Open up all locations, just in case -->
		break;

		case "Turks_timer1":
			PChar.quest.Turks_timer1.win_condition.l1 = "Timer";
			PChar.quest.Turks_timer1.win_condition.l1.date.day = GetAddingDataDay(0, 0, 15);
			PChar.quest.Turks_timer1.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 15);
			PChar.quest.Turks_timer1.win_condition.l1.date.year = GetAddingDataYear(0, 0, 15);
			PChar.quest.Turks_timer1.win_condition = "Turks_fin_timer";
		break;

		case "Turks_timer2":
			PChar.quest.Turks_timer2.win_condition.l1 = "Timer";
			PChar.quest.Turks_timer2.win_condition.l1.date.day = GetAddingDataDay(0, 0, 15);
			PChar.quest.Turks_timer2.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 15);
			PChar.quest.Turks_timer2.win_condition.l1.date.year = GetAddingDataYear(0, 0, 15);
			PChar.quest.Turks_timer2.win_condition = "Turks_fin_timer";
		break;

		case "Turks_timer3":
			PChar.quest.Turks_timer3.win_condition.l1 = "Timer";
			PChar.quest.Turks_timer3.win_condition.l1.date.day = GetAddingDataDay(0, 0, 1);
			PChar.quest.Turks_timer3.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 1);
			PChar.quest.Turks_timer3.win_condition.l1.date.year = GetAddingDataYear(0, 0, 1);
			PChar.quest.Turks_timer3.win_condition = "Turks_fin_timer";
		break;

		case "Turks_timer4":
			PChar.quest.Turks_timer4.win_condition.l1 = "Timer";
			PChar.quest.Turks_timer4.win_condition.l1.date.day = GetAddingDataDay(0, 0, 7);
			PChar.quest.Turks_timer4.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 7);
			PChar.quest.Turks_timer4.win_condition.l1.date.year = GetAddingDataYear(0, 0, 7);
			PChar.quest.Turks_timer4.win_condition = "Turks_fin_timer";
		break;

		case "Pieter_at_Douwesen":
			LAi_SetImmortal(CharacterFromID("Pieter Boelen"), 0);
         	ChangeCharacterAddressGroup(CharacterFromID("Pieter Boelen"), "Douwesen_Tavern", "goto", "goto2");
			LAi_SetCitizenType(characterFromID("Pieter Boelen"));
			Characters[GetCharacterIndex("Pieter Boelen")].dialog.filename = "Pieter at Douwesen_dialog.c";
		break;


///////////////////////////////////////////////////////////////
// Missing Man by Bartolomeu o Portugues
///////////////////////////////////////////////////////////////

		case "Missing_start":
			SetEnterLocationQuest("PoPrince_town", "Missing_start_check", 0);
		break;

		case "Missing_start_check":
			if(makeint(PChar.rank) >= 15)
			{
				ChangeCharacterAddressGroup(CharacterFromID("Angelique Moulin"), "PoPrince_town", "goto", "goto17");
			}
		break;

		case "Missing_search_refused":
			PChar.quest.Missingman = "refused";
			DeleteEnterLocationQuest("PoPrince_town", "Missing_start_check");
			LAi_SetActorType(characterFromID("Angelique Moulin"));
			LAi_ActorGoToLocation(characterFromID("Angelique Moulin"), "reload", "reload19", "none", "", "", "", 0.0);
			SetQuestHeader("Moulin");
			AddQuestRecord("Moulin", 9);
			CloseQuestHeader("Moulin");
		break;

		case "Missing_start_search":
			LAi_SetCitizenType(CharacterFromID("Angelique Moulin"));
			PChar.quest.Missingman = "search";
			DeleteEnterLocationQuest("PoPrince_town", "Missing_start_check");
			bSuppressResurrection = true;
			SetQuestHeader("Moulin");
			AddQuestRecord("Moulin", 1);
			ChangeCharacterAddressGroup(CharacterFromID("Robert Durand"), "Buccaneers_Camp", "goto", "goto16");
			ChangeCharacterAddressGroup(CharacterFromID("Buccaneer_01"), "Buccaneers_Camp", "goto", "goto42");
			ChangeCharacterAddressGroup(CharacterFromID("Buccaneer_02"), "Buccaneers_Camp", "goto", "goto12");
			ChangeCharacterAddressGroup(CharacterFromID("Buccaneer_03"), "Buccaneers_Camp", "goto", "goto15");
			Characters[GetCharacterIndex("Robert Durand")].dialog.currentnode = "First time";
		break;

		case "moulinplage":
			PChar.quest.Missingman = "voirmoulin";
			AddQuestRecord("Moulin", 2);
			LAi_SetPlayerType (Pchar);
			LAi_SetActorType(characterFromID("Robert Durand"));
			LAi_ActorGoToLocation(characterFromID("Robert Durand"), "reload", "reload6", "none", "", "", "", 0.0);
			setCharacterShipLocation(characterFromID("Pieter Boelen"), "Hispaniola_shore_02");
			ChangeCharacterAddressGroup(CharacterFromID("Francois Moulin"), "Hispaniola_shore_02", "goto", "locator12");
		break;

		case "directionlefort":
			PChar.quest.Missingman = "voirchamfort";
			AddQuestRecord("Moulin", 3);
			LAi_SetOfficerType(characterFromID("Robert Durand"));
			ChangeCharacterAddress(characterFromID("Robert Durand"), "none", "");
			ChangeCharacterAddressGroup(CharacterFromID("Antoine Chamfort"), "PoPrince_fakefort3", "reload", "reloadc4");
		break;

		case "antoinefort":
			locations[FindLocation("PoPrince_fakefort3")].reload.l1.disable = 1;
			locations[FindLocation("PoPrince_fakefort3")].reload.l2.disable = 1;
			locations[FindLocation("PoPrince_fakefort3")].reload.l3.disable = 1;
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocation(PChar, "reload", "reload2", "none", "", "", "", 50);
			LAi_QuestDelay("coupbas", 1.0);
		break;

		case "coupbas":
			LAi_SetPlayerType (Pchar);
			LAi_SetActorType(characterFromID("Antoine Chamfort"));
			LAi_ActorAttack(CharacterFromID("Antoine Chamfort"), PChar, "");
			pchar.quest.killing_chamfort.win_condition.l1 = "NPC_Death";
			pchar.quest.killing_chamfort.win_condition.l1.character = "Antoine Chamfort";
			pchar.quest.killing_chamfort.win_condition = "killing_chamfort";
		break;

		case "killing_chamfort":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2500);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 2500); }
			locations[FindLocation("PoPrince_fakefort3")].reload.l1.disable = 0;
			locations[FindLocation("PoPrince_fakefort3")].reload.l2.disable = 0;
			locations[FindLocation("PoPrince_fakefort3")].reload.l3.disable = 0;
			LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_SetAlarm("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, 0.0);
			AddQuestRecord("Moulin", 4);
			setCharacterShipLocation(characterFromID("Pieter Boelen"), "none");
			Characters[GetCharacterIndex("Francois Moulin")].dialog.currentnode = "begin_9";
			ChangeCharacterAddressGroup(CharacterFromID("Francois Moulin"), "Buccaneers_Camp", "goto", "goto37");
			ChangeCharacterAddress(characterFromID("Antoine Chamfort"), "none", "");

		break;

		case "retourprince":
			Preprocessor_AddQuestData("AntoineChamfort", GetMySimpleName(CharacterFromID("Antoine Chamfort")));
			AddQuestRecord("Moulin", 5);
			Preprocessor_Remove("AntoineChamfort");
			LAi_SetActorType(characterFromID("Francois Moulin"));
			LAi_ActorFollowEverywhere(characterFromID("Francois Moulin"), "", 60.0);
			Characters[GetCharacterIndex("Angelique Moulin")].dialog.currentnode = "begin_6";
		break;

		case "recompense":
			Characters[GetCharacterIndex("Francois Moulin")].dialog.currentnode = "begin_12";
			LAi_SetActorType(characterFromID("Francois Moulin"));
			LAi_ActorDialog(characterFromID("Francois Moulin"), pchar, "", 1.0, 1.0);
		break;

		case "justebijou":
			LAi_SetOfficerType(characterFromID("Buccaneer_01"));
			ChangeCharacterAddress(characterFromID("Buccaneer_01"), "none", "");
			LAi_SetOfficerType(characterFromID("Buccaneer_02"));
			ChangeCharacterAddress(characterFromID("Buccaneer_02"), "none", "");
			LAi_SetOfficerType(characterFromID("Buccaneer_03"));
			ChangeCharacterAddress(characterFromID("Buccaneer_03"), "none", "");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 12500);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 12500); }
			bSuppressResurrection = false;
			AddQuestRecord("Moulin", 6);
			CloseQuestHeader("Moulin");
			GiveItem2Character(pchar, "jewelry2");
			LAi_SetActorType(characterFromID("Francois Moulin"));
			LAi_ActorGoToLocation(characterFromID("Francois Moulin"), "reload", "reload19", "none", "", "", "", 0.0);
			LAi_SetActorType(characterFromID("Angelique Moulin"));
			LAi_ActorGoToLocation(characterFromID("Angelique Moulin"), "reload", "reload19", "none", "", "", "", 0.0);
		break;

		case "lesdeuxchoses":
			LAi_SetOfficerType(characterFromID("Buccaneer_01"));
			ChangeCharacterAddress(characterFromID("Buccaneer_01"), "none", "");
			LAi_SetOfficerType(characterFromID("Buccaneer_02"));
			ChangeCharacterAddress(characterFromID("Buccaneer_02"), "none", "");
			LAi_SetOfficerType(characterFromID("Buccaneer_03"));
			ChangeCharacterAddress(characterFromID("Buccaneer_03"), "none", "");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 12500);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 12500); }
   			bSuppressResurrection = false;
			GiveItem2Character(pchar, "jewelry2");
			if (GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS)
			{
				GiveItem2Character(pchar, "old_journal2");
				AddQuestRecord("Moulin", 10);
			}
			else
			{
				AddQuestRecord("Moulin", 7);
				GiveItem2Character(pchar, "old_journal");
			}
			LAi_SetActorType(characterFromID("Francois Moulin"));
			LAi_ActorGoToLocation(characterFromID("Francois Moulin"), "reload", "reload19", "none", "", "", "", 0.0);
			LAi_SetActorType(characterFromID("Angelique Moulin"));
			LAi_ActorGoToLocation(characterFromID("Angelique Moulin"), "reload", "reload19", "none", "", "", "", 0.0);

			if (GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS)
			{
				Locations[FindLocation("Cuba_Jungle_03")].locators_radius.goto.citizen010 = 2.0;				
				
				pchar.quest.epeeperdue.win_condition.l1 = "locator";
				pchar.quest.epeeperdue.win_condition.l1.location = "Cuba_Jungle_03";
				pchar.quest.epeeperdue.win_condition.l1.locator_group = "goto";
				pchar.quest.epeeperdue.win_condition.l1.locator = "citizen010";
				pchar.quest.epeeperdue.win_condition = "cachette";
			}
			else
			{
				Locations[FindLocation("Antigua_Jungle_01")].locators_radius.goto.citizen010 = 2.0;				
				
				pchar.quest.epeeperdue.win_condition.l1 = "locator";
				pchar.quest.epeeperdue.win_condition.l1.location = "Antigua_Jungle_01";
				pchar.quest.epeeperdue.win_condition.l1.locator_group = "goto";
				pchar.quest.epeeperdue.win_condition.l1.locator = "citizen010";
				pchar.quest.epeeperdue.win_condition = "cachette";
			}
		break;

		case "cachette":
			LAi_SetActorType(PChar);
			PChar.Temp.self.dialog = PChar.dialog.currentnode;
			PChar.dialog.currentnode = "Francis_sword";
			LAi_ActorSelfDialog(PChar, "player_back");
			if (GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS) ItemSetPrice("old_journal2", 1);
			else ItemSetPrice("old_journal", 1);
		break;

		case "jelaifini":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 15000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 15000); }
			if (GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS)
			{
    			Locations[FindLocation("Cuba_Jungle_03")].locators_radius.goto.citizen010 = 0.6;				
				AddQuestRecord("Moulin", 11);
				GiveItem2Character(pchar, "blangel");	// Grey Roger: Angel sword instead because Drake is using his own sword
			}
			else
			{
    			Locations[FindLocation("Antigua_Jungle_01")].locators_radius.goto.citizen010 = 0.6;				
				AddQuestRecord("Moulin", 8);
				GiveItem2Character(pchar, "bladeFD");	// KevAtl update for new SLiB blades 09-07-2007
			}
			CloseQuestHeader("Moulin");
		break;


///////////////////////////////////////////////////////////////
// Santiago by Bartolomeu o Portugues
///////////////////////////////////////////////////////////////

		case "Santiago_start":
			SetEnterLocationQuest("Guadeloupe_Port", "Santiago_start_check", 0);
		break;

		case "Santiago_start_check":
			if (makeint(pchar.rank) >= 14 && FindFellowTravellers(PChar, CharacterFromId("Bartolomeu O Portugues")) == FELLOWTRAVEL_OFFICER && PChar.Quest.Bartolomeu == "1")
			{
				LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
				LAi_ActorRunToLocator(characterFromID("Bartolomeu O Portugues"), "reload", "reload6_back", "Barto_store", 20.0);
				LAi_SetActorType(Pchar);
				Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
				Pchar.dialog.currentnode = "Bart_court";
				LAi_ActorSelfDialog(Pchar, "player_back");
			}
		break;

		case "Barto_store":
			DeleteEnterLocationQuest("Guadeloupe_Port", "Santiago_start_check");
			ChangeCharacterAddress(characterFromID("Bartolomeu O Portugues"), "none", "");
			LAi_SetOfficerType(characterFromID("Bartolomeu o Portugues"));
 			PChar.quest.santiago = "depart";
			Pchar.quest.Santiago.win_condition.l1 = "location";
			Pchar.quest.Santiago.win_condition.l1.location = "Pointe_a_pitre_store";
			PChar.quest.Santiago.win_condition = "Santiago_start_check_1";
		break;

		case "Santiago_start_check_1":
			ChangeCharacterAddressGroup(CharacterFromID("Francisco Cruz"), "Pointe_a_pitre_store", "goto", "goto5");
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.filename = "Bartolomeu o Portugues_dialog.c";
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "begin_44";
			LAi_ActorDialog(characterFromID("Bartolomeu o Portugues"), pchar, "", 0.0, 1.0);
		break;

		case "Santiago_search_refused":
			PChar.quest.santiago = "refused";
			LAi_SetActorType(characterFromID("Francisco Cruz"));
			LAi_ActorGoToLocation(characterFromID("Francisco Cruz"), "reload", "reload1", "none", "", "", "", 0.0);
			LAi_SetOfficerType(characterFromID("Bartolomeu o Portugues"));
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.filename = "Enc_Officer_dialog.c";
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.CurrentNode = "hired";
			SetQuestHeader("Santiago");
			AddQuestRecord("Santiago", 11);
			CloseQuestHeader("Santiago");
		break;

		case "Santiago_start_search":
			PChar.quest.santiago = "search";
			bSuppressResurrection = true;
			locations[FindLocation("Guadeloupe_Port")].reload.l11.disable = 1;
			locations[FindLocation("Guadeloupe_Jungle_03")].reload.l3.disable = 1;
			locations[FindLocation("Guadeloupe_Jungle_03")].reload.l5.disable = 1;
			locations[FindLocation("PaP_Guardhouse")].reload.l2.disable = 1;
			locations[FindLocation("Guadeloupe_Port")].reload.l1.disable = 1;
			pchar.location.from_sea = "Guadeloupe_Port";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar");
		break;

		case "Sailorbye":
			LAi_SetActorType(characterFromID("Francisco Cruz"));
			LAi_ActorGoToLocation(characterFromID("Francisco Cruz"), "reload", "reload1", "none", "", "", "", 0.0);
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "begin_51";
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			LAi_ActorWaitDialog(CharacterFromID("Bartolomeu O Portugues"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Bartolomeu O Portugues"), "", 10.0, 1.0);
		break;

		case "directbrothel":
			SetQuestHeader("Santiago");
			AddQuestRecord("Santiago", 1);
			LAi_SetPlayerType(pchar);
			LAi_SetOfficerType(characterFromID("Bartolomeu o Portugues"));
			LAi_SetImmortal(characterFromID("Bartolomeu O Portugues"), true);
			ChangeCharacterAddressGroup(CharacterFromID("Jean Dusac"), "Guadeloupe_Port", "officers", "houseS2_1");
		break;

		case "directstonehouse":
			AddQuestRecord("Santiago", 2);
			PChar.quest.santiago = "madame";
			ChangeCharacterAddressGroup(CharacterFromID("Cecile Bienbonne"), "StoneHouse", "reload", "reload1");
			Locations[FindLocation("StoneHouse")].vcskip = true;
		break;

		case "directjail":
			AddQuestRecord("Santiago", 3);
			PChar.quest.santiago = "jail";
			Pchar.quest.Santiago.win_condition.l1 = "location";
			Pchar.quest.Santiago.win_condition.l1.location = "Guadeloupe_Port";
			PChar.quest.Santiago.win_condition = "anyinfo";
		break;

		case "anyinfo":
			PChar.quest.santiago = "jail_2";
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "begin_52";
			LAi_ActorDialog(characterFromID("Bartolomeu o Portugues"), pchar, "", 0.0, 1.0);
 			ChangeCharacterAddressGroup(CharacterFromID("Etienne Dupuis"), "PaP_Guardhouse", "reload", "reload1");
		break;

		case "txikimoi":
			ChangeCharacterAddressGroup(CharacterFromID("Etienne Dupuis"), "PaP_Prison", "goto", "goto17");
			ChangeCharacterAddressGroup(CharacterFromID("Txiki Pijuan"), "PaP_Prison", "goto", "goto9");
		break;

		case "plusinfo":
			ChangeCharacterAddressGroup(CharacterFromID("Bartolomeu o Portugues"), "Guadeloupe_Port", "goto", "goto8");
			SetEnterLocationQuest("Guadeloupe_Port", "plusinfo_2", 0);
		break;

		case "plusinfo_2":
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			LAi_ActorFollow(characterFromID("Bartolomeu O Portugues"), PChar, "plusinfo_3", 1.5);
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "begin_53";
		break;

		case "plusinfo_3":
			LAi_ActorWaitDialog(PChar, characterFromID("Bartolomeu o Portugues"));
			LAi_ActorDialog(characterFromID("Bartolomeu o Portugues"), pchar, "", 0.0, 1.0);
			DeleteEnterLocationQuest("Guadeloupe_Port", "plusinfo_2");
		break;

		case "txikilibre":
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "begin_56";
			LAi_ActorDialog(characterFromID("Bartolomeu o Portugues"), pchar, "", 0.0, 1.0);
		break;

		case "txikilibre_2":
			ChangeCharacterAddressGroup(CharacterFromID("Txiki Pijuan"), "PAP_Arsenal", "reload", "reload2");
			Characters[GetCharacterIndex("Txiki Pijuan")].dialog.currentnode = "begin_14";
		break;

		case "infobarto":
			AddQuestRecord("Santiago", 7);
			PChar.quest.santiago = "payertavernier";
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Txiki Pijuan"));
			LAi_ActorRunToLocation(characterFromID("Txiki Pijuan"), "reload", "reload1", "none", "", "", "", 0.0);
		break;

		case "directavernier":
			PChar.quest.santiago = "payerhum";
			SetCurrentTime(23, 0);
			DoReloadCharacterToLocation("Guadeloupe_Port", "reload", "reload4_back");
			characters[GetCharacterIndex("Cecile Bienbonne")].location = "none";
			characters[GetCharacterIndex("Jean Dusac")].location = "none";
			characters[GetCharacterIndex("Etienne Dupuis")].location = "none";
			LAi_QuestDelay("justeinfo", 0.5);
		break;

		case "justeinfo":
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "begin_57";
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			LAi_ActorWaitDialog(CharacterFromID("Bartolomeu O Portugues"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Bartolomeu O Portugues"), "", 0.0, 1.0);
		break;

		case "newverif":
			LAi_type_actor_Reset(characterFromID("Txiki Pijuan"));
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "goto15", "", 7.0);
			LAi_QuestDelay("jelesvois", 7.0);
		break;

		case "jelesvois":
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(pchar, characterFromID("Guadeloupe_guard_2"));
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat1", "goto", "goto19");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "soulard1";
			LAi_SetActorType(characterFromID("soulard1"));
			LAi_ActorRunToLocation(characterFromID("soulard1"), "reload", "reload4_back", "none", "", "", "", 13.0);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat2", "goto", "goto19");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "soulard2";
			LAi_SetActorType(characterFromID("soulard2"));
			LAi_ActorRunToLocation(characterFromID("soulard2"), "reload", "reload4_back", "none", "", "", "", 13.0);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat3", "goto", "goto19");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "soulard3";
			LAi_SetActorType(characterFromID("soulard3"));
			LAi_ActorRunToLocation(characterFromID("soulard3"), "reload", "reload4_back", "none", "", "", "", 13.0);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat4", "goto", "goto19");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "soulard4";
			LAi_SetActorType(characterFromID("soulard4"));
 			LAi_ActorRunToLocation(characterFromID("soulard4"), "reload", "reload4_back", "none", "", "", "", 13.0);
			LAi_QuestDelay("rejointpijuan", 14.0);
		break;

		case "rejointpijuan":
			locations[FindLocation("Guadeloupe_Port")].reload.l6.disable = 1;
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "begin_58";
			LAi_ActorWaitDialog(CharacterFromID("Bartolomeu O Portugues"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Bartolomeu O Portugues"), "", 0.0, 1.0);
		break;

		case "pijuanplantation":
			AddQuestRecord("Santiago", 8);
			LAi_SetCivilianGuardianType(characterFromID("Txiki Pijuan"));
			setCharacterShipLocation(characterFromID("Txiki Pijuan"), "Guadeloupe_shore_01");
			ChangeCharacterAddressGroup(CharacterFromID("Txiki Pijuan"), "Guadeloupe_Jungle_03", "goto", "goto8");
			GiveItem2Character(characterFromID("Txiki Pijuan"),"bladeC12");
			EquipCharacterByItem(characterFromID("Txiki Pijuan"),"bladeC12");
			GiveItem2Character(CharacterFromId("Txiki Pijuan"),"pistol3");
			EquipCharacterByItem(CharacterFromId("Txiki Pijuan"), "pistol3");
			//JRH ammo mod -->
			if (ENABLE_AMMOMOD) {	// LDH change
				TakenItems(CharacterFromId("Txiki Pijuan"), "gunpowder", 6);
				TakenItems(CharacterFromId("Txiki Pijuan"), "pistolgrapes", 6);
			}
			//JRH ammo mod <--

			Characters[GetCharacterIndex("Txiki Pijuan")].dialog.currentnode = "begin_17";
			PChar.quest.santiago = "rencgarda";
			Pchar.quest.Santiago.win_condition.l1 = "location";			
			Pchar.quest.Santiago.win_condition.l1 = "location";
			Pchar.quest.Santiago.win_condition.l1.location = "Guadeloupe_shore_01";
			PChar.quest.Santiago.win_condition = "ansegardes";
		break;

		case "ansegardes":
			locations[FindLocation("Guadeloupe_shore_01")].reload.l1.disable = 1;
			locations[FindLocation("Guadeloupe_shore_01")].reload.l3.disable = 1;
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat1", "goto", "locator10");
			sld.dialog.filename = "garda_dialog.c";
			sld.id = "garda1";
			LAi_SetGuardianType(characterFromID("garda1"));
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_GARDAS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat2", "goto", "citizen07");
			sld.dialog.filename = "garda_dialog.c";
			sld.id = "garda2";
			LAi_SetGuardianType(characterFromID("garda2"));
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "SHORE_GARDAS");
		break;

		case "directbarco":
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "begin_59";
			LAi_ActorDialog(characterFromID("Bartolomeu o Portugues"), pchar, "", 2.0, 1.0);
		break;

		case "directbarco1":
			DoQuestReloadToLocation("Santiago_ship", "reload", "locator2", "directbarco2");
		break;

		case "directbarco2":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(pchar, "goto", "goto9", "directbarco3", 14.0);
		break;

		case "directbarco3":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat3", "goto", "goto4");
			sld.dialog.filename = "garda_dialog.c";
			sld.id = "garda3";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "BARCO_GARDAS");
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("garda3"));
			Characters[GetCharacterIndex("garda3")].dialog.currentnode = "begin_3";
			LAi_ActorWaitDialog(CharacterFromID("garda3"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("garda3"), "", 0.0, 1.0);
		break;

		case "directbarco4":
			LAi_SetActorType(characterFromID("garda3"));
			LAi_ActorAttack(CharacterFromID("garda3"), PChar, "");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat4", "reload", "locator2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "BARCO_GARDAS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat5", "reload", "locator2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "BARCO_GARDAS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat6", "reload", "locator2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "BARCO_GARDAS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat7", "reload", "locator2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "BARCO_GARDAS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat8", "reload", "locator2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "BARCO_GARDAS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat9", "reload", "locator2");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "BARCO_GARDAS");

			LAi_group_FightGroups("BARCO_GARDAS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("BARCO_GARDAS", "directbarco5");
		break;

		case "directbarco5":
			LAi_KillCharacter(characterFromID("garda3"));
			LAi_QuestDelay("directbarco6", 1.0);
		break;

		case "directbarco6":
			ChangeCharacterAddressGroup(CharacterFromID("Pedro Rivera"), "Santiago_ship", "reload", "locator2");
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Pedro Rivera"));
			Characters[GetCharacterIndex("Pedro Rivera")].Dialog.CurrentNode = "begin_13";
			LAi_ActorWaitDialog(CharacterFromID("Pedro Rivera"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Pedro Rivera"), "", 0.0, 1.0);
		break;

		case "directbarco7":
			LAi_SetImmortal(characterFromID("Pedro Rivera"), true);
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "begin_62";
			LAi_ActorWaitDialog(CharacterFromID("Bartolomeu O Portugues"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Bartolomeu O Portugues"), "", 0.0, 1.0);
		break;

		case "directbarco8":
			LAi_SetActorType(characterFromID("Pedro Rivera"));
			Characters[GetCharacterIndex("Pedro Rivera")].dialog.currentnode = "begin_17";
			LAi_ActorWaitDialog(CharacterFromID("Pedro Rivera"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Pedro Rivera"), "", 0.0, 1.0);
		break;

		case "directbarco9":
			LAi_SetActorType(characterFromID("Pedro Rivera"));
			LAi_ActorAttack(CharacterFromID("Pedro Rivera"), CharacterFromID("Bartolomeu O Portugues"), "");
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			LAi_ActorAttack(CharacterFromID("Bartolomeu O Portugues"), CharacterFromID("Pedro Rivera"), "");
			LAi_SetPlayerType(pchar);
			LAi_QuestDelay("directbarco10", 15.0);
		break;

		case "directbarco10":
			pchar.location.from_sea = "Guadeloupe_shore_01";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar");
			LAi_KillCharacter(characterFromID("Pedro Rivera"));
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Bartolomeu O Portugues"));
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.currentnode = "begin_63";
			LAi_ActorWaitDialog(CharacterFromID("Bartolomeu O Portugues"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Bartolomeu O Portugues"), "", 0.0, 1.0);
			break;

			case "directbarco11":
			DoQuestReloadToLocation("Guadeloupe_shore_01", "reload", "reload_3", "Pijuanofficer");
			LAi_SetImmortal(characterFromID("Bartolomeu O Portugues"), false);
		break;

		case "Pijuanofficer":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 25000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 25000); }

			bSuppressResurrection = false;
			locations[FindLocation("Guadeloupe_Port")].reload.l6.disable = 0;
			locations[FindLocation("Guadeloupe_shore_01")].reload.l1.disable = 0;
			locations[FindLocation("Guadeloupe_shore_01")].reload.l3.disable = 0;
			locations[FindLocation("Guadeloupe_Port")].reload.l11.disable = 0;
			locations[FindLocation("PaP_Guardhouse")].reload.l2.disable = 0;
			locations[FindLocation("Guadeloupe_Port")].reload.l1.disable = 0;
			ChangeCharacterAddressGroup(CharacterFromID("Txiki Pijuan"), "Guadeloupe_shore_01", "goto", "locator11");
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Txiki Pijuan"));
			Characters[GetCharacterIndex("Txiki Pijuan")].dialog.currentnode = "begin_20";
			LAi_ActorWaitDialog(CharacterFromID("Txiki Pijuan"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Txiki Pijuan"), "", 0.0, 1.0);
			SetCompanionIndex(pchar, -1, getcharacterIndex("Txiki Pijuan"));
			SetCharacterRemovable(characterFromID("Txiki Pijuan"), true);
			LAi_SetOfficerType(characterFromID("Txiki Pijuan"));
			LAi_SetImmortal(characterFromID("Txiki Pijuan"), false); // PB
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.filename = "Enc_Officer_dialog.c";
			Characters[GetCharacterIndex("Bartolomeu o Portugues")].dialog.CurrentNode = "hired";
			AddQuestRecord("Santiago", 10);
			CloseQuestHeader("Santiago");
		break;


///////////////////////////////////////////////////////////////
// First Contact by Bartolomeu o Portugues
///////////////////////////////////////////////////////////////

		case "Contact_start":
			SetEnterLocationQuest("Grand_Cayman_townhall", "Contact_start_check", 0);
		break;

		case "Contact_start_check":
			if(makeint(PChar.rank) >= 6)
			{
				PChar.quest.Firstcontact = "debut";
			}
		break;

		case "Contact_start_search":
			PChar.quest.Firstcontact = "search";
			DeleteEnterLocationQuest("Grand_Cayman_townhall", "Contact_start_check");
			bSuppressResurrection = true;
			SetQuestHeader("Contact");
			AddQuestRecord("Contact", 1);
		break;

		case "Contact_arendt":
			PChar.quest.Firstcontact = "search2";
			AddQuestRecord("Contact", 9);
		break;

		case "searchdebris":
			PChar.quest.Firstcontact = "chest";
			AddQuestRecord("Contact", 5);

			Pchar.quest.find_dead.win_condition.l1 = "location";
			Pchar.quest.find_dead.win_condition.l1.location = "SaintMartin_shore_02";
			PChar.quest.find_dead.win_condition = "crewmemberdead";
		break;

		case "crewmemberdead":
			StartQuestMovie(true, false, false);
			DisableFastTravel(true);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "citizen07"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			LAi_SetImmortal(sld,true);
			sld.dialog.filename = "Octave Fabre_dialog.c";
			sld.dialog.currentnode = "Smallchest";
			LAi_ActorWaitDialog(sld, pchar);			//CTM
			LAi_ActorDialog(pchar, sld, "", 4.0, 1.0);	//CTM
		break;

		case "jela":
			DisableFastTravel(false);
			EndQuestMovie();
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 1500); }
			PChar.quest.Firstcontact = "oldadmiral";
			GiveItem2Character(pchar, "small_chest");
			ChangeCharacterAddressGroup(CharacterFromID("Octave Fabre"), "PaP_Academy", "sit", "sit1");
			ChangeCharacterAddress(characterFromID("Reynoud Verheugen"), "none", "");
			AddQuestRecord("Contact", 6);
		break;

		case "pap_storm":
			PChar.quest.Firstcontact = "warning";
			Pchar.quest.davycrew.win_condition.l1 = "location";
			Pchar.quest.davycrew.win_condition.l1.location = "Guadeloupe_Port";
			PChar.quest.davycrew.win_condition = "pap_storm1";
			DisableFastTravel(true);
			DisableMenuLaunch(true);
		break;

		case "pap_storm1":
			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "pap_storm";
			LAi_ActorSelfDialog(Pchar, "player_back");
		break;

		case "davywarning":
			ChangeCharacterAddressGroup(CharacterFromID("Davycrew_01"), "Guadeloupe_Port", "goto", "goto24");
			ChangeCharacterAddressGroup(CharacterFromID("Davycrew_02"), "Guadeloupe_Port", "goto", "goto3");
			LAi_SetActorType(CharacterFromID("Davycrew_02"));
			LAi_ActorFollow(CharacterFromID("Davycrew_02"), pchar, "", 10);
			LAi_SetActorType(characterfromID("davycrew_01"));
			LAi_ActorDialog(characterfromID("davycrew_01"), PChar, "", 0.5, 10);
		break;

		case "Contact_antigua":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			ChangeCharacterAddressGroup(CharacterFromID("Davycrew_01"), "", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Davycrew_02"), "", "", "");
			Characters[GetCharacterIndex("antigua_portadmiral")].dialog.CurrentNode = "contact_return1";
			AddQuestRecord("Contact", 10);
		break;

		case "Contact_NoLuck":
			Characters[GetCharacterIndex("antigua_portadmiral")].dialog.CurrentNode = "First time";
			PChar.quest.Firstcontact = "prepare_davyencounter";
			AddQuestRecord("Contact", 11);
			Group_CreateGroup("FlyingDutchman");
			Group_AddCharacter("FlyingDutchman", "Davy Jones");
			Group_SetGroupCommander("FlyingDutchman", "Davy Jones");
			Group_SetPursuitGroup("FlyingDutchman", PLAYER_GROUP);
			Group_SetTaskAttack("FlyingDutchman", PLAYER_GROUP, true);
			Group_SetAddress("FlyingDutchman", "Cayman", "Quest_ships", "Quest_ship_12");
			Group_LockTask("FlyingDutchman");
			UpdateRelations();
			characters[GetCharacterIndex("Davy Jones")].nosurrender = 2;
			Characters[GetCharacterIndex("Davy Jones")].recognized = true;
			Character_SetAbordageEnable(CharacterFromID("Davy Jones"), false);

			NPChar = CharacterFromID("Davy Jones");
			NPChar.perks.list.BasicDamageControl = true;	// Give Jones some ship-based perks - don't trust the levelling system to assign or keep them
			NPChar.perks.list.AdvancedDamageControl = true;
			NPChar.perks.list.Rigging = true;
			NPChar.perks.list.RiggingAdvance = true;
			NPChar.perks.list.HullDamageUp = true;
			NPChar.perks.list.FastReload = true;
			NPChar.perks.list.SailsDamageUp = true;
			NPChar.perks.list.CrewDamageUp = true;
			NPChar.perks.list.CriticalShoot = true;
			NPChar.perks.list.LongRangeShoot = true;
			NPChar.perks.list.CannonProfessional = true;
			NPChar.perks.list.IronWill = true;
			NPChar.ship.stats.maxcrew = 1280;		// Boost Flying Dutchman's crew, normal crew of 420 is insufficient for 100000 HP.
			SetCrewQuantity(NPChar, 1280);
// KK -->
			PChar.quest.PrepareDavyEncounter.win_condition.l1 = "MapEnter";
			PChar.quest.PrepareDavyEncounter.win_condition = "PrepareDavyEncounter";
// <-- KK
		break;

// KK -->
		case "PrepareDavyEncounter":
			SetNextWeather("Day Storm");
			PChar.quest.StartDavyEncounter.win_condition.l1 = "SeaEnter";
			PChar.quest.StartDavyEncounter.win_condition = "StartDavyEncounter";
		break;

		case "StartDavyEncounter":
			PChar.quest.voirdavy.win_condition.l1 = "location";
			PChar.quest.voirdavy.win_condition.l1.location = GetCharacterShipQDeck(PChar);
			PChar.quest.voirdavy.win_condition = "voirdavy";

			bQuestDisableAllCommands = true;
			Sea_DeckStartNow(GetMainCharacterIndex(), GetCharacterShipQDeck(PChar));
		break;
// <-- KK

		case "voirdavy":
			//ChangeCharacterAddressGroup(CharacterFromID("Davycrew_01"), PChar.location, "rld", "loc0");
			SetCharacterToNearLocatorFromMe("Davy Jones", 3);
			//SetCharacterToNearLocatorFromMe("Davycrew_01", 10);

			LAi_type_actor_Reset(characterFromID("Davycrew_02"));
			//ChangeCharacterAddressGroup(CharacterFromID("Davy Jones"), PChar.location, "rld", "loc2");
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Davy Jones"));
			LAi_ActorWaitDialog(CharacterFromID("Davy Jones"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Davy Jones"), "", 10.0, 1.0);
		break;

		case "davy_leave":
			ChangeCharacterAddressGroup(CharacterFromID("Davycrew_01"), "", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Davy Jones"), "", "", "");
			LAi_QuestDelay("meetdaughter", 1.0);
		break;

		case "meetdaughter":
			PChar.quest.Firstcontact = "daughter";
			ChangeCharacterAddress(characterFromID("Octave Fabre"), "none", "");
			SetCharacterToNearLocatorFromMe("Elizabeth Shaw", 3);
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Elizabeth Shaw"));
			LAi_ActorWaitDialog(CharacterFromID("Elizabeth Shaw"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Elizabeth Shaw"), "", 10.0, 1.0);
		break;

		case "sailtocayman":
			bQuestDisableAllCommands = false; // PB
			PChar.quest.Firstcontact = "gotocayman";
			AddQuestRecord("Contact", 7);
			ChangeCharacterAddressGroup(CharacterFromID("Edmund Christobel Shaw"), "Grand_Cayman_townhall", "goto", "goto6");
			LAi_SetCivilianGuardianType(characterFromID("Edmund Christobel Shaw"));

			Characters[GetCharacterIndex("Edmund Christobel Shaw")].dialog.CurrentNode = "gov_6";

			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Elizabeth Shaw"));
			LAi_ActorFollowEverywhere(characterFromID("Elizabeth Shaw"), "", 60.0);
			SetCharacterRelationBoth(GetCharacterIndex("Davy Jones"),GetMainCharacterIndex(),RELATION_ENEMY);
			SetCharacterRelationBoth(GetCharacterIndex("Grand Cayman Commander"),GetCharacterIndex("Davy Jones"),RELATION_FRIEND);
			SetCharacterRelationBoth(GetCharacterIndex("Grand Cayman Commander"),GetMainCharacterIndex(),RELATION_FRIEND);
		break;

		case "goportcayman":
			LAi_SetPlayerType(pchar);
			LAi_type_actor_Reset(characterFromID("Elizabeth Shaw"));

			DisableFastTravel(true);
			DisableMenuLaunch(true);
			Pchar.quest.find_davy.win_condition.l1 = "locator";
			Pchar.quest.find_davy.win_condition.l1.location = "Grand_Cayman_townhall";
			pchar.quest.find_davy.win_condition.l1.locator_group = "reload";
			pchar.quest.find_davy.win_condition.l1.locator = "reload1";
			PChar.quest.find_davy.win_condition = "gotoseedavy";
		break;

		case "gotoseedavy":
			SetNextWeather("Black Pearl Fight");
			DoQuestReloadToLocation("Quest_Grand_Cayman_town", "reload", "reload15", "_");
			locations[FindLocation("Quest_Grand_Cayman_town")].reload.l1.disable = 1;
		break;

		case "davy_townfight1":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "goto", "goto28"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			LAi_SetImmortal(sld,true);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "goto29"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			LAi_SetImmortal(sld,true);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "goto14"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			LAi_SetImmortal(sld,true);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "goto1"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			LAi_SetImmortal(sld,true);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "goto2"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			LAi_SetImmortal(sld,true);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "officers", "reload13_3"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			LAi_SetImmortal(sld,true);

			// -------------------

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy1", "goto", "goto1");
			sld.name = TranslateString("", "Angler");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy2", "goto", "goto3");
			sld.name = TranslateString("", "Ogilvey");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Maccus", "goto", "goto4");
			sld.name = TranslateString("", "Maccus");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy4", "goto", "goto5");
			sld.name = TranslateString("", "Clanker");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Hadras", "goto", "goto6");
			sld.name = TranslateString("", "Hadras");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy1", "goto", "goto7");
			sld.name = TranslateString("", "Urchin");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy2", "goto", "goto8");
			sld.name = TranslateString("", "Wheelback");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy3", "goto", "goto9");
			sld.name = TranslateString("", "Wyvern");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy4", "goto", "goto10");
			sld.name = TranslateString("", "Quittance");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Penrod", "goto", "goto30");
			sld.name = TranslateString("", "Penrod");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			LAi_group_FightGroups("DAVY_CREW", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("DAVY_CREW", "davy_townfight2");
		break;

		case "davy_townfight2":
			//ChangeCharacterAddressGroup(characterFromID("Davy Jones"), "Quest_Cayman_Port", "officers", "sea_3");
			ChangeCharacterAddressGroup(characterFromID("Davy Jones"), "Quest_Cayman_Port", "goto", "goto8");
			LAi_SetCivilianGuardianType(characterFromID("Davy Jones"));
			ChangeCharacterAddressGroup(CharacterFromID("Davycrew_01"), "Quest_Cayman_Port", "goto", "soldier_01");
			ChangeCharacterAddressGroup(CharacterFromID("Davycrew_02"), "Quest_Cayman_Port", "goto", "goto3");
			Characters[GetCharacterIndex("Davy Jones")].dialog.CurrentNode = "begin_14";

			locations[FindLocation("Quest_Grand_Cayman_town")].reload.l1.disable = 0;
			setCharacterShipLocation(characterFromID("Davy Jones"), "Quest_Cayman_Port");
			Pchar.quest.davymeet.win_condition.l1 = "location";
			Pchar.quest.davymeet.win_condition.l1.location = "Quest_Cayman_Port";
			PChar.quest.davymeet.win_condition = "davyonshore";

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy1", "reload", "reload9");
			sld.name = TranslateString("", "Angler");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy2", "officers", "reload9_1");
			sld.name = TranslateString("", "Ogilvey");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Maccus", "officers", "reload9_2");
			sld.name = TranslateString("", "Maccus");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy4", "officers", "reload9_3");
			sld.name = TranslateString("", "Clanker");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Hadras", "goto", "goto1");
			sld.name = TranslateString("", "Hadras");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy1", "goto", "goto2");
			sld.name = TranslateString("", "Urchin");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy2", "goto", "goto3");
			sld.name = TranslateString("", "Wheelback");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy3", "reload", "reload8");
			sld.name = TranslateString("", "Wyvern");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "davy4", "officers", "reload8_1");
			sld.name = TranslateString("", "Quittance");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Penrod", "officers", "reload8_2");
			sld.name = TranslateString("", "Penrod");
			sld.lastname = "";
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "DAVY_CREW");

			LAi_group_FightGroups("DAVY_CREW", LAI_GROUP_PLAYER, true);
		break;

		case "davyonshore":
			PChar.quest.Firstcontact = "davytalks";
			Characters[GetCharacterIndex("Davycrew_01")].dialog.CurrentNode = "begin_5";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat3", "goto", "locator28");
			LAi_SetHP(sld, 80.0, 80.0);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "goto", "goto1"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "officers", "sea_1"); // PB
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			LAi_SetActorType(characterfromID("davycrew_01"));
			LAi_ActorDialog(characterfromID("davycrew_01"), PChar, "", 0.5, 10);
		break;

		case "davyonshore2":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(PChar, "goto", "goto5", "davyonshore3", 10.0);
		break;

		case "davyonshore3":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Davy Jones"));
			LAi_ActorWaitDialog(CharacterFromID("Davy Jones"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Davy Jones"), "", 10.0, 1.0);
		break;

		case "pushdavy":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Davy Jones"));
			LAi_ActorAnimation(pchar, "attack_2", "davywater", 0.0);
			PlaySound("OBJECTS\duel\punch1.wav");
		break;

		case "davywater":
			//ChangeCharacterAddressGroup(characterFromID("Davy Jones"), "Quest_Cayman_Port", "reload", "sea");
			ChangeCharacterAddressGroup(characterFromID("Davy Jones"), "Quest_Cayman_Port", "goto", "goto7");
			LAi_SetActorType(characterFromID("Davy Jones"));
			LAi_ActorAnimation(characterFromID("Davy Jones"), "Ground_StandUp", "davyinwater", 3.0);
		break;

		case "davyinwater":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Davy Jones"));
			Characters[GetCharacterIndex("Davy Jones")].dialog.currentnode = "begin_16";
			LAi_ActorWaitDialog(CharacterFromID("Davy Jones"), Pchar);
			LAi_ActorDialog(PChar, characterFromID("Davy Jones"), "", 0.0, 1.0);
		break;

		case "davyshootsme":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Davy Jones"));
			LAi_ActorAttack(characterFromID("Davy Jones"), pchar, "");
			LAi_QuestDelay("davyhurtme", 2.7);
		break;

		case "davyhurtme":
			bSuppressResurrection = true;
			LAi_SetStayType(CharacterFromID("Davy Jones"));
			Lai_KillCharacter(pchar);
			LAi_QuestDelay("preroomcayman", 3.0);
			LAi_QuestDelay("goroomcayman", 6.0);
		break;

		case "preroomcayman":
			ChangeCharacterAddress(characterFromID("Davy Jones"), "none", "");
		break;

		case "goroomcayman":
			DoQuestReloadToLocation("Grand_Cayman_Tavern_upstairs", "goto", "goto4", "_");
			locations[FindLocation("Grand_Cayman_Tavern_upstairs")].reload.l1.disable = 1;
			LAi_SetPlayerType(pchar);
			LAi_SetCurHP(pchar, LAi_GetCharacterMaxHP(pchar)); // PB: To heal character
			ChangeCharacterAddressGroup(CharacterFromID("Elizabeth Shaw"), "Grand_Cayman_Tavern_upstairs", "goto", "goto7");
			Characters[GetCharacterIndex("Elizabeth Shaw")].dialog.CurrentNode = "begin_4";
			LAi_SetActorType(characterfromID("Elizabeth Shaw"));
			LAi_ActorDialog(characterfromID("Elizabeth Shaw"), PChar, "", 0.5, 10);
			bSuppressResurrection = false;
		break;

		case "goresidencecayman":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			SetNextWeather("Blue Sky");
			locations[FindLocation("Grand_Cayman_Tavern_upstairs")].reload.l1.disable = 0;
			LAi_SetActorType(characterFromID("Elizabeth Shaw"));
			LAi_ActorGoToLocation(characterFromID("Elizabeth Shaw"), "reload", "reload1", "none", "", "", "", 0.0);
			Characters[GetCharacterIndex("Edmund Christobel Shaw")].dialog.CurrentNode = "gov_8";
			ChangeCharacterAddressGroup(CharacterFromID("Edmund Christobel Shaw"), "Grand_Cayman_townhall", "sit", "sit2");
			LAi_SetHuberType(characterfromID("Edmund Christobel Shaw"));
			Group_SetAddressNone("FlyingDutchman");
		break;

		case "beaufinal":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 25000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 25000); }

			bSuppressResurrection = false;
			AddMoneyToCharacter(pchar, 40000);
			AddQuestRecord("Contact", 8);
			CloseQuestHeader("Contact");
			ItemSetPrice("small_chest", 1);		// GR: can now dump chest into a chest
		break;


///////////////////////////////////////////////////////////////
// Jackpot by Bartolomeu o Portugues
///////////////////////////////////////////////////////////////

		case "Jackpot_start":
			if(GetMySimpleOldName(PChar) != "Will Turner") SetEnterLocationQuest("Tortuga_tavern", "Jackpot_start_check", 0);
		break;

		case "Jackpot_start_check":
			if(makeint(PChar.rank) >= 12)
			{
				PChar.quest.Jackpot = "debuter";
			}
		break;

		case "Jackpot_start_search":
			PChar.quest.Jackpot = "search";
			DeleteEnterLocationQuest("Tortuga_tavern", "Jackpot_start_check");
			SetQuestHeader("Jackpot");
			AddQuestRecord("Jackpot", 1);
		//	locations[FindLocation("Tortuga_town_01")].reload.l6.disable = 0;
			locations[FindLocation("Tortuga_port")].reload.l18.disable = 0;			//JRH: moved Will Turner's house
			// PB -->
			SetModelFromID(CharacterFromID("Elizabeth Swann"), "lizswann");			//GR: use new pirate Elizabeth Swann model
			GiveItem2Character(CharacterFromID("Elizabeth Swann"), "blade6");
			GiveItem2Character(CharacterFromID("Elizabeth Swann"), "pistol7");
			EquipCharacterByItem(CharacterFromID("Elizabeth Swann"), "blade6");
			EquipCharacterByItem(CharacterFromID("Elizabeth Swann"), "pistol7");
			Characters[GetCharacterIndex("Elizabeth Swann")].nation	= PIRATE;
			// PB <--
			ChangeCharacterAddressGroup(CharacterFromID("Will Turner"), "Will_Turner_house_inside", "goto", "goto2");
			ChangeCharacterAddressGroup(CharacterFromID("Elizabeth Swann"), "Will_Turner_house_inside", "goto", "goto1");
			Pchar.quest.meetturner.win_condition.l1 = "location";
			Pchar.quest.meetturner.win_condition.l1.location = "Will_Turner_house_inside";
			PChar.quest.meetturner.win_condition = "MeetTurner";
			locations[FindLocation("Will_Turner_house_inside")].vcskip = true;
		break;

		case "MeetTurner":
 			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorWaitDialog(CharacterFromID("Will Turner"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Will Turner"), "", 10.0, 1.0);
		break;

		case "talktoswann":
 			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Elizabeth Swann"));
			LAi_ActorWaitDialog(CharacterFromID("Elizabeth Swann"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Elizabeth Swann"), "", 10.0, 1.0);
		break;

		case "leavetortuga":
			PChar.quest.Jackpot = "gobattlerocks";
			bSuppressResurrection = true;
			AddQuestRecord("Jackpot", 2);
			LAi_SetPlayerType(pchar);
			LAi_SetCitizenType(characterFromID("Will Turner"));
			LAi_SetCitizenType(characterFromID("Elizabeth Swann"));
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Will Turner"));
			SetCharacterRemovable(characterFromID("Will Turner"), false);

			Island_SetReloadEnableLocal("Battle_Rocks", "reload_2", true);
			Islands[FindIsland("Battle_Rocks")].reload.l1.goto_enable = true; // PB

			locations[FindLocation("Battle_Rocks_Jungle_01")].vcskip = true;
			locations[FindLocation("Battle_Rocks_Jungle_02")].vcskip = true;
			locations[FindLocation("Spanish_Camp")].vcskip = true;
			locations[FindLocation("Battle_Rocks_Jungle_03")].vcskip = true;
			locations[FindLocation("Battle_Rocks_Jungle_04")].vcskip = true;
			locations[FindLocation("Battle_Rocks_Jungle_05")].vcskip = true;

			pchar.quest.todevilcreek.win_condition.l1 = "location";
			pchar.quest.todevilcreek.win_condition.l1.location = "Devil_Creek";
			pchar.quest.todevilcreek.win_condition = "to_Devil_Creek";
		break;

		case "jackpotrefused":
			PChar.quest.Jackpot = "fin";
			AddQuestRecord("Jackpot", 3);
			CloseQuestHeader("Jackpot");
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorGoToLocation(characterFromID("Will Turner"), "reload", "reload1", "none", "", "", "", 0.0);
			LAi_SetActorType(characterFromID("Elizabeth Swann"));
			LAi_ActorGoToLocation(characterFromID("Elizabeth Swann"), "reload", "reload1", "none", "", "", "", 0.0);
		break;

		case "to_Devil_Creek":
			LAi_SetCivilianGuardianType(characterFromID("Will Turner"));
			LAi_SetCivilianGuardianType(characterFromID("Elizabeth Swann"));
			ChangeCharacterAddressGroup(CharacterFromID("Will Turner"), "Devil_Creek", "goto", "locator10");
			ChangeCharacterAddressGroup(CharacterFromID("Elizabeth Swann"), "Devil_Creek", "goto", "citizen07");
			Characters[GetCharacterIndex("Will Turner")].dialog.CurrentNode = "begin_11";
 			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorWaitDialog(CharacterFromID("Will Turner"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Will Turner"), "", 10.0, 1.0);
		break;

		case "meetindians":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_SetImmortal(CharacterFromID("Will Turner"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Will Turner"), "", 60.0);
			LAi_SetActorType(characterFromID("Elizabeth Swann"));
			LAi_SetImmortal(CharacterFromID("Elizabeth Swann"), 1);
			LAi_ActorFollowEverywhere(characterFromID("Elizabeth Swann"), "", 60.0);
			pchar.quest.meet_indians.win_condition.l1 = "location";
			pchar.quest.meet_indians.win_condition.l1.location = "Battle_Rocks_Jungle_04";
			pchar.quest.meet_indians.win_condition = "fightindians";
		break;

		case "fightindians":
			locations[FindLocation("Battle_Rocks_Jungle_04")].reload.l3.disable = 1;
			locations[FindLocation("Battle_Rocks_Jungle_04")].reload.l4.disable = 1;
			LAi_SetOfficerType(characterFromID("Will Turner"));
			LAi_SetOfficerType(characterFromID("Elizabeth Swann"));

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "goto", "goto2");
			LAi_group_MoveCharacter(sld, "JUNGLE_INDIANS");

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "goto", "goto2");
			LAi_group_MoveCharacter(sld, "JUNGLE_INDIANS");

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "goto", "goto2");
			LAi_group_MoveCharacter(sld, "JUNGLE_INDIANS");

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "goto", "goto2");
			LAi_group_MoveCharacter(sld, "JUNGLE_INDIANS");

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "goto", "goto2");
			LAi_group_MoveCharacter(sld, "JUNGLE_INDIANS");

			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", 10, true, 1.0, "Native", "goto", "goto2");
			LAi_group_MoveCharacter(sld, "JUNGLE_INDIANS");

			LAi_group_FightGroups("JUNGLE_INDIANS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("JUNGLE_INDIANS", "leaveindians");
		break;

		case "leaveindians":
			locations[FindLocation("Battle_Rocks_Jungle_04")].reload.l4.disable = 0;
			locations[FindLocation("Battle_Rocks_Jungle_04")].reload.l3.disable = 0;
			LAi_SetActorType(characterFromID("Elizabeth Swann"));
			Characters[GetCharacterIndex("Elizabeth Swann")].dialog.currentnode = "begin_4";
			LAi_ActorDialog(characterFromID("Elizabeth Swann"), pchar, "", 50.0, 10.0);
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorFollowEverywhere(characterFromID("Will Turner"), "", 60.0);
			AddQuestRecord("Jackpot", 4);
		break;

		case "meetprisoner":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Elizabeth Swann"));
			LAi_ActorFollowEverywhere(characterFromID("Elizabeth Swann"), "", 60.0);
			LAi_SetImmortal(characterFromID("Konrad Kulczycki"), true);
			ChangeCharacterAddress(CharacterFromID("Konrad Kulczycki"), "Battle_Rocks_Jungle_02", "goto8");
			LAi_SetPoorType(characterfromID("Konrad Kulczycki"));
			locations[FindLocation("Battle_Rocks_Jungle_02")].reload.l4.disable = 1;
		break;

		case "opinionturner":
			LAi_SetActorType(characterFromID("Will Turner"));
			Characters[GetCharacterIndex("Will Turner")].dialog.currentnode = "begin_12";
			LAi_ActorDialog(characterFromID("Will Turner"), pchar, "", 2.0, 1.0);
		break;

		case "gospanishcamp":
			LAi_SetActorType(characterFromID("Konrad Kulczycki"));
			Characters[GetCharacterIndex("Konrad Kulczycki")].dialog.currentnode = "begin_7";
			LAi_ActorDialog(characterFromID("Konrad Kulczycki"), pchar, "", 2.0, 1.0);
		break;

		case "gospanishcamp2":
			locations[FindLocation("Battle_Rocks_Jungle_02")].reload.l4.disable = 0;
			AddQuestRecord("Jackpot", 5);
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorFollowEverywhere(characterFromID("Will Turner"), "", 60.0);
			LAi_SetActorType(characterFromID("Konrad Kulczycki"));
			LAi_ActorRunToLocation(characterFromID("Konrad Kulczycki"), "reload", "reload1", "none", "", "", "", 0.0);
			pchar.quest.meet_spaniards.win_condition.l1 = "location";
			pchar.quest.meet_spaniards.win_condition.l1.location = "spanish_camp";
			pchar.quest.meet_spaniards.win_condition = "fightspaniards";
		break;

		case "fightspaniards":
			locations[FindLocation("spanish_camp")].reload.l4.disable = 1;
			locations[FindLocation("spanish_camp")].reload.l5.disable = 1;
			locations[FindLocation("spanish_camp")].reload.l6.disable = 1;
			ChangeCharacterAddressGroup(characterFromID("Konrad Kulczycki"), "spanish_camp", "officers", "reload2_1");
			ChangeCharacterAddressGroup(characterFromID("Will Turner"), "spanish_camp", "officers", "reload2_2");
			ChangeCharacterAddressGroup(characterFromID("Elizabeth Swann"), "spanish_camp", "officers", "reload2_3");
			GiveItem2Character(characterFromID("Konrad Kulczycki"),"blade7");
			EquipCharacterByItem(characterFromID("Konrad Kulczycki"),"blade7");
			GiveItem2Character(CharacterFromId("Konrad Kulczycki"),"pistol3");
			EquipCharacterByItem(CharacterFromId("Konrad Kulczycki"), "pistol3");
			//JRH ammo mod -->
			if (ENABLE_AMMOMOD) {	// LDH change
				TakenItems(CharacterFromId("Konrad Kulczycki"), "gunpowder", 6);
				TakenItems(CharacterFromId("Konrad Kulczycki"), "pistolgrapes", 6);
			}
			//JRH ammo mod <--

			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "Spaniardsattack";
			LAi_ActorSelfDialog(Pchar, "player_back");
		break;

		case "fightspaniards2":
			LAi_SetPlayerType(pchar);
			LAi_SetOfficerType(characterFromID("Will Turner"));
			LAi_SetOfficerType(characterFromID("Elizabeth Swann"));
			LAi_SetOfficerType(characterFromID("Konrad Kulczycki"));
			LAi_QuestDelay("fightspaniards3", 1.5);
			PlayStereoSound("OBJECTS\SHIPCHARGE\hurrah.wav");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto5"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CAMP_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto5"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CAMP_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto5"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CAMP_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto5"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CAMP_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto5"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CAMP_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "goto", "goto5"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CAMP_SOLDIERS");

			LAi_group_FightGroups("CAMP_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("CAMP_SOLDIERS", "gomine");
		break;

		case "fightspaniards3":
			CreateParticleSystemX("blast_inv", -26.95, 0.00, 11.17, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -26.95, 0.00, 11.17, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -21.95, 0.00, 11.17, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -26.95, 0.00, 16.17, -1.57, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", -26.95, 0.00, 6.17, -1.57, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
			PlaySound("OBJECTS\shipcharge\hit_torock.wav");
		break;

		case "gomine":
			LAi_SetActorType(characterFromID("Elizabeth Swann"));
			LAi_ActorFollowEverywhere(characterFromID("Elizabeth Swann"), "", 60.0);
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorFollowEverywhere(characterFromID("Will Turner"), "", 60.0);
			LAi_SetActorType(characterFromID("Konrad Kulczycki"));
			Characters[GetCharacterIndex("Konrad Kulczycki")].dialog.currentnode = "begin_9";
			LAi_ActorDialog(characterFromID("Konrad Kulczycki"), pchar, "", 50.0, 10.0);
		break;

		case "gomine2":
			locations[FindLocation("spanish_camp")].reload.l5.disable = 0;
			locations[FindLocation("spanish_camp")].reload.l6.disable = 0;
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Konrad Kulczycki"));
			LAi_ActorRunToLocation(characterFromID("Konrad Kulczycki"), "reload", "reload3", "none", "", "", "", 0.0);
			pchar.quest.meet_friends.win_condition.l1 = "location";
			pchar.quest.meet_friends.win_condition.l1.location = "Battle_Rocks_Jungle_01";
			pchar.quest.meet_friends.win_condition = "minefight";
		break;

		case "minefight":
			ChangeCharacterAddressGroup(characterFromID("Konrad Kulczycki"), "Battle_Rocks_Jungle_01", "goto", "goto10");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "officers", "reload1_2"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "MINE_SOLDATOS");
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "officers", "reload1_3"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
  			LAi_group_MoveCharacter(sld, "MINE_SOLDATOS");
			sld.dialog.filename = "Konrad Kulczycki_dialog.c";
			sld.dialog.currentnode = "begin_11";
			sld.id = "futurmort";
			LAi_SetActorType(pchar);
 			LAi_ActorGoToLocator(PChar, "goto", "goto7", "minefightbis", 20.0);
		break;

		case "minefightbis":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("futurmort"));
			LAi_ActorWaitDialog(CharacterFromID("futurmort"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("futurmort"), "", 10.0, 10.0);
		break;

		case "minefight2":
			LAi_SetPlayerType(pchar);
			LAi_SetOfficerType(characterFromID("Will Turner"));
			LAi_SetOfficerType(characterFromID("Elizabeth Swann"));
			LAi_SetOfficerType(characterFromID("Konrad Kulczycki"));
  			LAi_group_MoveCharacter(characterFromID("futurmort"), "MINE_SOLDATOS");
			LAi_group_FightGroups("MINE_SOLDATOS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("MINE_SOLDATOS", "entrermine");
		break;

		case "entrermine":
			pchar.quest.meet_friend.win_condition.l1 = "location";
			pchar.quest.meet_friend.win_condition.l1.location = "Battle_Rocks_Mine";
			pchar.quest.meet_friend.win_condition = "talktofriends";
			LAi_SetActorType(characterFromID("Konrad Kulczycki"));
			LAi_ActorFollowEverywhere(characterFromID("Konrad Kulczycki"), "", 60.0);
		break;

		case "talktofriends":
			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "Brodyag1", "goto", "goto1");
			LAi_SetHP(sld, 80.0, 80.0);
  			LAi_group_MoveCharacter(sld, "MINE_FRIENDS");
			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "man4", "goto", "goto10");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "mineami";
			sld.dialog.filename = "Konrad Kulczycki_dialog.c";
			sld.dialog.currentnode = "begin_12";
			LAi_SetCivilianGuardianType(characterFromID("mineami"));
		break;

		case "allerport":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Konrad Kulczycki"));
			Characters[GetCharacterIndex("Konrad Kulczycki")].dialog.currentnode = "begin_16";
			LAi_ActorWaitDialog(CharacterFromID("Konrad Kulczycki"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Konrad Kulczycki"), "", 10.0, 10.0);
		break;

		case "allerport2":
			AddQuestRecord("Jackpot", 6);
			setCharacterShipLocation(characterFromID("Silver"), "Battle_Rocks_port");
			locations[FindLocation("spanish_camp")].reload.l4.disable = 0;
			locations[FindLocation("Battle_Rocks_port")].reload.l3.disable = 1;
			LAi_SetPlayerType(pchar);
			DoReloadCharacterToLocation("Battle_Rocks_port", "goto", "locator10");
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorFollowEverywhere(characterFromID("Will Turner"), "", 60.0);
			LAi_SetActorType(characterFromID("Konrad Kulczycki"));
			LAi_ActorFollowEverywhere(characterFromID("Konrad Kulczycki"), "", 60.0);
			ChangeCharacterAddressGroup(characterFromID("Elizabeth Swann"), "Battle_Rocks_port", "goto", "citizen04");
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Elizabeth Swann"));
			Characters[GetCharacterIndex("Elizabeth Swann")].dialog.currentnode = "begin_5";
			LAi_ActorWaitDialog(CharacterFromID("Elizabeth Swann"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Elizabeth Swann"), "", 10.0, 10.0);
		break;

		case "seesoldier":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "citizen01"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "PRAIA_SOLDATOS");
			sld.id = "fuyard";
			LAi_ActorTurnToCharacter(pchar, characterFromID("fuyard"));
			LAi_SetActorType(characterFromID("fuyard"));
			LAi_ActorRunToLocation(characterFromID("fuyard"), "reload", "reload2", "none", "", "", "", 0.0);
			LAi_QuestDelay("attraperfuyard", 2.5);
		break;

		case "attraperfuyard":
			LAi_SetActorType(pchar);
 			LAi_ActorGoToLocator(PChar, "goto", "citizen07", "fuyardparti", 20.0);
			LAi_SetActorType(characterFromID("Elizabeth Swann"));
			LAi_ActorFollowEverywhere(characterFromID("Elizabeth Swann"), "", 60.0);
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorFollowEverywhere(characterFromID("Will Turner"), "", 60.0);

		break;

		case "fuyardparti":
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Will Turner"));
			Characters[GetCharacterIndex("Will Turner")].dialog.currentnode = "begin_13";
			LAi_ActorDialog(characterFromID("Will Turner"), pchar, "", 20.0, 10.0);
		break;

		case "gosilvertrain":
			locations[FindLocation("Battle_Rocks_port")].reload.l3.disable = 0;

			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorFollowEverywhere(characterFromID("Will Turner"), "", 60.0);
			pchar.quest.meet_friend.win_condition.l1 = "location";
			pchar.quest.meet_friend.win_condition.l1.location = "Battle_Rocks_Jungle_03";
			pchar.quest.meet_friend.win_condition = "joinsilvertrain";
		break;

		case "joinsilvertrain":
			locations[FindLocation("Battle_Rocks_Jungle_03")].reload.l4.disable = 1;
			locations[FindLocation("Battle_Rocks_Jungle_03")].reload.l5.disable = 1;
			ChangeCharacterAddressGroup(characterFromID("Konrad Kulczycki"), "Battle_Rocks_Jungle_03", "officers", "reload1_3");
			ChangeCharacterAddressGroup(characterFromID("Will Turner"), "Battle_Rocks_Jungle_03", "officers", "reload1_1");
			ChangeCharacterAddressGroup(characterFromID("Elizabeth Swann"), "Battle_Rocks_Jungle_03", "officers", "reload1_2");

			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "Chelovek", "goto", "goto7");
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_SetPoorType(sld);
  			LAi_group_MoveCharacter(sld, "CONVOY_FRIENDS");
			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "Fatman", "goto", "goto8");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetPoorType(sld);
  			LAi_group_MoveCharacter(sld, "CONVOY_FRIENDS");
			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "Brodyag1", "goto", "goto4");
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetPoorType(sld);
  			LAi_group_MoveCharacter(sld, "CONVOY_FRIENDS");
			sld = LAi_CreateFantomCharacter(false, 0, false, false, 0.25, "man1", "goto", "goto3");
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "convoyami";
			sld.dialog.filename = "Konrad Kulczycki_dialog.c";
			sld.dialog.currentnode = "begin_17";
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto2"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			sld.id = "fuyard";
			LAi_ActorTurnToCharacter(pchar, characterFromID("fuyard"));
			LAi_SetActorType(characterFromID("fuyard"));
			LAi_ActorRunToLocation(characterFromID("fuyard"), "goto", "goto5", "none", "", "", "joinsilvertrain2", 0.0);
			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "Spanishrunaway";
			LAi_ActorSelfDialog(Pchar, "player_back");
		break;

		case "joinsilvertrain2":
			LAi_SetOfficerType(characterFromID("Will Turner"));
			LAi_SetOfficerType(characterFromID("Elizabeth Swann"));
			LAi_SetOfficerType(characterFromID("Konrad Kulczycki"));

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto6"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto6"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m3, "goto", "goto6"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m4, "goto", "goto6"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m5, "goto", "goto6"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m6, "goto", "goto6"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m1, "goto", "goto6"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[SPAIN].fantomModel.m2, "goto", "goto6"); // PB
			LAi_SetHP(sld, 100.0, 100.0);
			LAi_group_MoveCharacter(sld, "CONVOY_SOLDIERS");

			LAi_group_FightGroups("CONVOY_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("CONVOY_SOLDIERS", "joinsilvertrain3");
		break;

		case "joinsilvertrain3":
			LAi_SetActorType(characterFromID("Elizabeth Swann"));
			LAi_ActorFollowEverywhere(characterFromID("Elizabeth Swann"), "", 60.0);
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorFollowEverywhere(characterFromID("Will Turner"), "", 60.0);
			LAi_SetActorType(characterFromID("Konrad Kulczycki"));
			LAi_ActorFollowEverywhere(characterFromID("Konrad Kulczycki"), "", 60.0);
			LAi_SetCivilianGuardianType(characterFromID("convoyami"));
		break;

		case "leavebattle":
			locations[FindLocation("Battle_Rocks_Jungle_03")].reload.l4.disable = 0;
			locations[FindLocation("Battle_Rocks_Jungle_03")].reload.l5.disable = 0;
			LAi_SetActorType(characterFromID("Will Turner"));
			Characters[GetCharacterIndex("Will Turner")].dialog.currentnode = "begin_15";
			LAi_ActorDialog(characterFromID("Will Turner"), pchar, "", 20.0, 10.0);
		break;

		case "leavedevilcreek":
			LAi_SetCivilianGuardianType(characterFromID("Elizabeth Swann"));
			DoReloadCharacterToLocation("Devil_Creek", "goto", "locator10");
			ChangeCharacterAddressGroup(characterFromID("Elizabeth Swann"), "Devil_Creek", "goto", "citizen02");
			LAi_SetActorType(characterFromID("Will Turner"));
			LAi_ActorFollowEverywhere(characterFromID("Will Turner"), "", 60.0);

			LAi_SetActorType(pchar);
			LAi_SetActorType(characterFromID("Elizabeth Swann"));
			Characters[GetCharacterIndex("Elizabeth Swann")].dialog.currentnode = "begin_6";
			LAi_ActorWaitDialog(CharacterFromID("Elizabeth Swann"), Pchar);
			LAi_ActorDialog(pchar, characterFromID("Elizabeth Swann"), "", 10.0, 10.0);
		break;

		case "leavedevilcreek2":
			AddQuestRecord("Jackpot", 7);
			pchar.quest.sail_tortuga.win_condition.l1 = "location";
			pchar.quest.sail_tortuga.win_condition.l1.location = "Tortuga_port";
			pchar.quest.sail_tortuga.win_condition = "meetshopkeeper";
			LAi_SetPlayerType(pchar);
			LAi_SetActorType(characterFromID("Elizabeth Swann"));
			LAi_ActorFollowEverywhere(characterFromID("Elizabeth Swann"), "", 60.0);
			setCharacterShipLocation(characterFromID("Silver"), "none");
		break;

		case "meetshopkeeper":
			LAi_SetActorType(characterFromID("Will Turner"));
			Characters[GetCharacterIndex("Will Turner")].dialog.currentnode = "begin_16";
			LAi_ActorDialog(characterFromID("Will Turner"), pchar, "", 20.0, 10.0);
		break;

		case "leaveturner":
			LAi_SetActorType(characterFromID("Konrad Kulczycki"));
			Characters[GetCharacterIndex("Konrad Kulczycki")].dialog.currentnode = "begin_18";
			LAi_ActorDialog(characterFromID("Konrad Kulczycki"), pchar, "", 20.0, 10.0);
		break;

		case "leaveKonradKulczycki":
			LAi_SetActorType(characterFromID("Elizabeth Swann"));
			Characters[GetCharacterIndex("Elizabeth Swann")].dialog.currentnode = "begin_7";
			LAi_ActorDialog(characterFromID("Elizabeth Swann"), pchar, "", 20.0, 10.0);
		break;

		case "leaveswann":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Leadership", 25000);
				AddPartyExpChar(PChar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 25000); }

			bSuppressResurrection = false;
			AddMoneyToCharacter(pchar, 60000);
			AddQuestRecord("Jackpot", 8);
			CloseQuestHeader("Jackpot");
			LAi_ActorRunToLocation(characterFromID("Konrad Kulczycki"), "reload", "reload5_back", "none", "", "", "", 5.0);
			SetCharacterRemovable(CharacterFromID("Elizabeth Swann"), true);
			LAi_SetImmortal(CharacterFromID("Elizabeth Swann"), false);
			SetOfficersIndex(CharacterFromID("Will Turner"),1, GetCharacterIndex("Elizabeth Swann"));
			LAi_SetActorType(CharacterFromID("Elizabeth Swann"));
			LAi_ActorRunToLocation(CharacterFromID("Elizabeth Swann"), "reload", "gate", "none", "", "", "", 5.0);
			LAi_ActorRunToLocation(CharacterFromID("Will Turner"), "reload", "gate", "none", "", "", "", 5.0);
			RemoveCharacterCompanion(PChar, characterFromID("Will Turner"));
			setCharacterShipLocation(CharacterFromID("Will Turner"), "none");
			SetCharacterRemovable(CharacterFromID("Will Turner"), true);
			LAi_SetImmortal(CharacterFromID("Will Turner"), false);
		break;


///////////////////////////////////////////////////////////////
// Church Help and Strange Things in the Archipelago Edited by CTM
///////////////////////////////////////////////////////////////

		// PB: Deprecated Code -->
/*		case "Church_help":
			SetEnterLocationQuest("redmond_church", "church_start_check", 0);
		break;

		case "church_start_check":
			if(makeint(PChar.rank) >= 1)
			{
				characters[GetCharacterIndex("Father Bernard")].quest.church_help = "";
			}
		break;*/
		// PB: Deprecated Code <--

		case "Yedam_kinne_attack":
			AddQuestRecord("church_help", 11);
			LAi_group_MoveCharacter(characterFromID("Yedam Kinne"), "YedamKine");
			LAi_SetActorType(characterFromID("Yedam Kinne"));
			LAi_ActorAttack(characterFromID("Yedam Kinne"), pchar, "");
			characters[GetCharacterIndex("Father bernard")].quest.church_help = "bad_dautch";
		break;

		case "exit_from_douwesen_townhall_complete":
			LAi_SetActorType(CharacterFromID("Lisebet Schefold"));
			LAi_ActorDialog(CharacterFromID("Lisebet Schefold"), pchar, "",  2.0, 1.0);
		break;

		case "to_muelle_for_letter":
			bQuestDisableAllCommands = true; // KK
			pchar.location.from_sea = "Muelle_shore";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			DoQuestCheckDelay("to_muelle_for_letter_2", 3.0);
		break;

		// --> Swindler 050927
		// Here's a syntax error:
		// case "to_muelle_for_letter_2": 04.06.2003 14:43
		case "to_muelle_for_letter_2":
		// Swindler <--
			DoReloadFromSeaToLocation("Muelle_shore", "reload", "reload2");
			Locations[FindLocation("Muelle_shore")].reload.l2.disable = 1;
			pchar.quest.mystery_men_meeting_us.win_condition.l1 = "location";
			pchar.quest.mystery_men_meeting_us.win_condition.l1.location = "Muelle_shore";
			pchar.quest.mystery_men_meeting_us.win_condition = "mystery_men_meeting_us";
		break;

		case "mystery_men_meeting_us":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			bQuestDisableAllCommands = false; // KK
			LAi_SetHP(characterFromID("Mystery_Man_01"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_Man_02"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_Man_03"), 80.0, 80.0);
			ChangeCharacterAddress(characterFromID("Mystery_Man_01"), "Muelle_shore", "goto12");
			ChangeCharacterAddressGroup(characterFromID("Mystery_Man_02"), "Muelle_shore", "reload", "reload3");
			ChangeCharacterAddressGroup(characterFromID("Mystery_Man_03"), "Muelle_shore", "reload", "reload3");
			LAi_SetStayType(pchar);
			LAi_SetActorType(characterFromID("Mystery_Man_01"));
			LAi_SetActorType(characterFromID("Mystery_Man_02"));
			LAi_SetActorType(characterFromID("Mystery_Man_03"));
			LAi_ActorDialog(characterFromID("Mystery_Man_01"), pchar, "player_back", 3.0, 1.0);
			LAi_ActorFollow(characterFromID("Mystery_Man_02"), pchar, "", 3.0);
			LAi_ActorFollow(characterFromID("Mystery_Man_03"), pchar, "", 3.0);
			AddQuestRecord("animists", 9);
		break;

		case "fight_with_mystery_mens_in_muelle_shore":
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_01"), "ANIMISTS_IN_SHORE");
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_02"), "ANIMISTS_IN_SHORE");
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_03"), "ANIMISTS_IN_SHORE");
			LAi_group_FightGroups("ANIMISTS_IN_SHORE", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("ANIMISTS_IN_SHORE", "kill_all_animists_in_muelle_shore");
		break;

		case "kill_all_animists_in_muelle_shore":
			Locations[FindLocation("Muelle_shore")].reload.l2.disable = 0;
			GiveItem2Character(pchar, "animists_amulet");
			AddQuestRecord("animists", 10);
		break;

		case "i_give_first_letter_to_animists":
			pchar.quest.animists = "letter_to_domingues_opened";
			AddMoneyToCharacter(pchar, 1000);
			OfficersReaction("bad");
			Locations[FindLocation("Muelle_shore")].reload.l2.disable = 0;
			characters[GetCharacterIndex("Mystery_Man_01")].location = "none";
			characters[GetCharacterIndex("Mystery_Man_02")].location = "none";
			characters[GetCharacterIndex("Mystery_Man_03")].location = "none";
			AddQuestRecord("animists", 11);
		break;

		case "prepare_for_barkue":
			AddQuestRecord("animists", 14);
			pchar.quest.to_greenford_for_montanez.win_condition.l1 = "location";
			pchar.quest.to_greenford_for_montanez.win_condition.l1.location = "Oxbay";
			pchar.quest.to_greenford_for_montanez.win_condition = "to_greenford_for_montanez_complete";

		//	LAi_SetHP(characterFromID("Mystery_man_01"), 80.0, 80.0);
		//	LAi_SetHP(characterFromID("Mystery_man_02"), 80.0, 80.0);

			//SetCharacterRelation(GetCharacterIndex("Mergildo Hurtado"),GetMainCharacterIndex(), RELATION_FRIEND);
			//SetCharacterRelation(GetCharacterIndex("Mystery_Man_01"),GetMainCharacterIndex(), RELATION_ENEMY);

			Group_CreateGroup("Mergildo Hurtado");
			Group_AddCharacter("Mergildo Hurtado", "Mergildo Hurtado");
			Group_SetGroupCommander("Mergildo Hurtado", "Mergildo Hurtado");
			Group_SetPursuitGroup("Mergildo Hurtado", PLAYER_GROUP);
			// boal -->
			//Group_SetAddress("Mergildo Hurtado", "Oxbay", "", "");
			LAi_SetHP(characterFromID("Mergildo Hurtado"), 80.0, 80.0);
			Group_SetAddress("Mergildo Hurtado", "Oxbay", "Quest_ships", "Quest_ship_12");

            // boal <--
			Group_CreateGroup("animists");
			Group_AddCharacter("animists", "Mystery_Man_04");
			Group_AddCharacter("animists", "Mystery_Man_05");
//			Characters[GetCharacterIndex("Dark Mystery_Man_04")].recognized = true; // PB: Ensure they're hostile!
//			Characters[GetCharacterIndex("Dark Mystery_Man_05")].recognized = true; // PB: Ensure they're hostile!
			Characters[GetCharacterIndex("Mystery_Man_04")].recognized = true;	// GR: Who is "Dark Mystery_Man_04"?
			Characters[GetCharacterIndex("Mystery_Man_05")].recognized = true;	// GR: Who is "Dark Mystery_Man_05"?
            // boal -->
            LAi_SetHP(characterFromID("Mystery_man_04"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_man_05"), 80.0, 80.0);
			SetCharacterRelation(GetCharacterIndex("Mergildo Hurtado"),GetMainCharacterIndex(), RELATION_FRIEND);
			SetCharacterRelation(GetCharacterIndex("Mystery_Man_04"),GetMainCharacterIndex(), RELATION_ENEMY);
            // boal <--
			Group_SetGroupCommander("animists", "Mystery_man_04");
			Group_SetPursuitGroup("animists", PLAYER_GROUP);
			// boal -->
			//Group_SetAddress("animists", "Oxbay", "", "");
			Group_SetAddress("animists", "Oxbay", "Quest_ships", "Quest_ship_12");
			// boal <--

			Group_LockTask("animists");
			Group_LockTask("Mergildo Hurtado");
			Group_SetTaskAttack("animists", "Mergildo Hurtado", true);
			Group_SetTaskRunAway("Mergildo Hurtado");
			UpdateRelations();
		break;

		case "to_greenford_for_montanez_complete":
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal("Oxbay", false);// TIH typo fix Oct31'06

            // boal -->
            LAi_SetHP(characterFromID("Mystery_man_04"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_man_05"), 80.0, 80.0);
            // boal <--

			pchar.quest.saints_barkue_drown.win_condition.l1 = "NPC_Death";
			pchar.quest.saints_barkue_drown.win_condition.l1.character = "Mergildo Hurtado";
			pchar.quest.saints_barkue_drown.win_condition = "saints_barkue_drown_complete";

			pchar.quest.animists_drown.win_condition.l1 = "NPC_Death";
			pchar.quest.animists_drown.win_condition.l1.character = "Mystery_Man_04";
			pchar.quest.animists_drown.win_condition.l2 = "NPC_Death";
			pchar.quest.animists_drown.win_condition.l2.character = "Mystery_Man_05";
// KK -->
			pchar.quest.animists_drown.win_condition.l3 = "SeaEnter";
			//pchar.quest.animists_drown.win_condition.l3 = "location"; // different condition added PW
			//pchar.quest.animists_drown.win_condition.l3.location = "Oxbay"; // different condition added PW
// <-- KK
			pchar.quest.animists_drown.win_condition = "animists_drown_complete";
		break;

		case "saints_barkue_drown_complete":
			pchar.quest.animists_drown.over = "yes";
			Group_LockTask("animists");
			Group_SetTaskRunAway("animists");
			bQuestDisableMapEnter = false;
			Island_SetReloadEnableGlobal("Oxbay", true);
			pchar.quest.animists = "barkue_drown";
			AddQuestRecord("animists", 15);
		break;

		case "animists_drown_complete":
			bQuestDisableAllCommands = true; // KK
			DoQuestCheckDelay("animists_drown_complete_2", 5.0);
			AddQuestRecord("animists", 16);
		break;

		case "animists_drown_complete_2":
			bQuestDisableMapEnter = false;
			Island_SetReloadEnableGlobal("Oxbay", true);
			if (GetNationRelation2MainCharacter(GetTownNation("Greenford")) == RELATION_ENEMY) // PB: was hardcoded for ENGLAND
			{
				pchar.location.from_sea = "Oxbay_lighthouse";
			}
			else
			{
				pchar.location.from_sea = "Greenford_port";
			}
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			PlaceFleetNearShore(pchar.location.from_sea); // KK
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			bQuestDisableAllCommands = false;
			Group_SetAddress("Mergildo Hurtado", "none", "", "");
			DoQuestReloadToLocation("Greenford_tavern", "candles", "sit3", "speak_with_Mergilo");
			ChangeCharacterAddressGroup(characterFromID("Mergildo Hurtado"), "Greenford_tavern", "sit", "sit4");
		break;

		case "speak_with_Mergilo":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			LAi_SetSitType(characterFromID("Mergildo Hurtado"));
			LAi_ActorDialogNow(pchar, characterFromID("Mergildo Hurtado"), "", 1.0);
		break;

		case "to_barkue_complete":
			// boal -->
			//AddQuestRecord("animists", 18);
			// boal <--
			DoQuestReloadToLocation(pchar.location.from_sea, "reload", "reload1", "_");
			LAi_SetPlayerType(pchar);
			characters[GetCharacterIndex("Mergildo Hurtado")].location = "Greenford_tavern";
			ChangeCharacterAddress(characterFromID("Mergildo Hurtado"), "none", "");
		break;

		case "to_barkue_too_many_ships":		// GR: if you have too many ships, stand up so you can go to shipyard to dispose of one
			ChangeCharacterAddressGroup(PChar, "Greenford_tavern", "goto", "goto5");
			LAi_SetPlayerType(PChar);
			Characters[GetCharacterIndex("Mergildo Hurtado")].dialog.currentnode = "too_many_ships_recheck";
		break;

		case "oops_ANIMISTS_want_letter_again":
			DisableFastTravel(true);
			pchar.quest.animists_again_meeting_us.win_condition.l1 = "location";
			pchar.quest.animists_again_meeting_us.win_condition.l1.location = "Muelle_town_01"; // CTM
			pchar.quest.animists_again_meeting_us.win_condition = "animists_again_meeting_us_complete";
		break;

		case "animists_again_meeting_us_complete":
// CTM -->
			LAi_SetStayType(pchar);
			LAi_SetHP(characterFromID("Mystery_Man_06"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_Man_07"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_Man_08"), 80.0, 80.0);
			//PlaceCharacter(characterFromID("Mystery_Man_06"), "goto");
			//PlaceCharacter(characterFromID("Mystery_Man_07"), "goto");
			//PlaceCharacter(characterFromID("Mystery_Man_08"), "goto");

			changeCharacterAddressGroup(characterFromID("Mystery_Man_06"), "Muelle_town_01", "goto", "goto74");
			changeCharacterAddressGroup(characterFromID("Mystery_Man_07"), "Muelle_town_01", "goto", "goto76");
			changeCharacterAddressGroup(characterFromID("Mystery_Man_08"), "Muelle_town_01", "goto", "goto73");

			Locations[FindLocation("Muelle_town_01")].vcskip = true;
			//Locations[FindLocation("Muelle_town_04")].vcskip = true;
// CTM <--
			LAi_SetActorType(CharacterFromID("Mystery_Man_06"));
			LAi_SetActorType(CharacterFromID("Mystery_Man_07"));
			LAi_SetActorType(CharacterFromID("Mystery_Man_08"));
			LAi_ActorDialog(characterFromID("Mystery_Man_06"), pchar, "player_back", 2.0, 1.0);
			LAi_ActorFollow(characterFromID("Mystery_Man_07"), pchar, "", 3.0);
			LAi_ActorFollow(characterFromID("Mystery_Man_08"), pchar, "", 3.0);
		break;

		case "second_fight_with_animists":
			LAi_QuestDelay("second_fight_with_animists_begin", 0.0); // KK
		break;

		case "second_fight_with_animists_begin":
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_06"), "ANIMISTS_IN_MUELLE");
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_07"), "ANIMISTS_IN_MUELLE");
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_08"), "ANIMISTS_IN_MUELLE");
			LAi_group_MoveCharacter(characterFromID("second_spaniard_priest"), "PRIESTS");
			LAi_group_FightGroups("ANIMISTS_IN_MUELLE", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("ANIMISTS_IN_MUELLE", "kill_all_animists_in_muelle_town");
		break;

		case "kill_all_animists_in_muelle_town":
			LAi_QuestDelay("kill_all_animists_in_muelle_town_complete", 2.0);
		break;

		case "kill_all_animists_in_muelle_town_complete":
			AddQuestRecord("animists", 21);
			DeleteAttribute(Locations[FindLocation("Muelle_town_01")], "vcskip"); // CTM
			changeCharacterAddress(characterfromID("padre Domingues"), "none", "");
			changeCharacterAddress(characterfromID("second_spaniard_priest"), "Muelle_church", "goto11");
			DoQuestReloadToLocation("Muelle_church", "goto", "goto7", "to_the_muelle_church_with_letter");  // <-- Cat
		break;

		case "to_the_muelle_church_with_letter":
			LAi_SetActorType(pchar);
			pchar.dialog.currentnode = "letter_to_father_bernard";
			LAi_ActorSelfDialog(pchar, "player_back");
			LAi_QuestDelay("to_the_muelle_church_with_letter2", 4.0);
		break;

		case "to_the_muelle_church_with_letter2":
			DisableFastTravel(false);
			characters[GetCharacterIndex("second_spaniard_priest")].dialog.currentnode = "First time";
			LAi_SetActorType(characterFromID("second_spaniard_priest"));
			LAi_ActorWaitDialog(Pchar, characterFromID("second_spaniard_priest"));
			LAi_ActorDialog(characterFromID("second_spaniard_priest"), Pchar, "player_back", 2.0, 1.0);
		break;  //  <-- Cat

		case "father_Gareth_stopping_us":
			Locations[FindLocation("Muelle_church")].reload.l1.go = "Muelle_town_01"; //CTM
			Locations[FindLocation("Muelle_church")].reload.l1.emerge = "reload4";
			pchar.quest.animists = "before_knight";
			TakeItemFromCharacter(pchar, "letter_to_bernard");
			GiveItem2Character(characterFromID("father Gareth"), "blade5");
			EquipCharacterByItem(characterFromID("father Gareth"), "blade5");

			LAi_SetImmortal(characterFromID("father Gareth"), false);
			LAi_SetImmortal(characterFromID("father Bernard"), true);

			LAi_SetActorType(characterFromID("father Gareth"));

			if (characters[GetCharacterIndex("father Gareth")].location == "Redmond_church")
			{
				LAi_ActorDialog(characterFromID("father Gareth"), pchar, "", 2.0, 1.0);
			}
			else
			{
				ChangeCharacterAddressGroup(characterfromid("Father Gareth"), "Redmond_church", "reload", "reload1");
				LAi_ActorDialog(characterFromID("father Gareth"), pchar, "", 2.0, 1.0);
			}
		break;

		case "fight_with_animists_in_church":
			Preprocessor_AddQuestData("FatherGareth", GetMySimpleName(CharacterFromID("Father Gareth")));
			AddQuestRecord("animists", 22);
			Preprocessor_Remove("FatherGareth");
			LAi_LocationFightDisable(&locations[FindLocation("redmond_church")], false);

			LAi_SetHP(characterFromID("Mystery_Man_09"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_Man_10"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Mystery_Man_11"), 80.0, 80.0);
			ChangeCharacterAddressGroup(characterFromID("Mystery_Man_09"), "Redmond_Church", "reload", "reload1");
			ChangeCharacterAddressGroup(characterFromID("Mystery_Man_10"), "Redmond_Church", "reload", "reload1");
			ChangeCharacterAddressGroup(characterFromID("Mystery_Man_11"), "Redmond_Church", "reload", "reload1");

			LAi_group_MoveCharacter(characterFromID("Mystery_Man_09"), "ANIMISTS_IN_CHURCH");
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_10"), "ANIMISTS_IN_CHURCH");
			LAi_group_MoveCharacter(characterFromID("Mystery_Man_11"), "ANIMISTS_IN_CHURCH");
			LAi_group_MoveCharacter(characterFromID("father Gareth"), "ANIMISTS_IN_CHURCH");
			LAi_group_FightGroups("ANIMISTS_IN_CHURCH", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("ANIMISTS_IN_CHURCH", "kill_all_ANIMISTS_in_church_complete");
		break;

		case "kill_all_ANIMISTS_in_church_complete":
			ChangeCharacterAddress(characterFromID("Mystery_Man_09"), "none", "");
			ChangeCharacterAddress(characterFromID("Mystery_Man_10"), "none", "");
			ChangeCharacterAddress(characterFromID("Mystery_Man_11"), "none", "");
			ChangeCharacterAddress(characterFromID("father Gareth"), "none", "");
			LAi_LocationFightDisable(&locations[FindLocation("redmond_church")], true);
			pchar.quest.ANIMISTS = "kill_all_ANIMISTS_in_church";
			LAi_SetActorType(characterFromID("father Bernard"));
			LAi_ActorDialog(characterFromID("father Bernard"), pchar, "", 2.0, 1.0);
			LAi_ActorWaitDialog(Pchar, characterFromID("father Bernard"));
			characters[GetCharacterIndex("father Bernard")].dialog.currentnode = "kill_all_ANIMISTS_in_churcha";
		break;

		case "meeting_with_Jaoquin_De_Masse":
			ChangeCharacterAddressGroup(characterFromID("Jaoquin de masse"), "Redmond_church", "reload", "reload1");
			LAi_SetActorType(characterFromID("Jaoquin de masse"));
			LAi_ActorDialog(characterFromID("Jaoquin de masse"), pchar, "", 2.0, 1.0);
		break;

		case "masse_becomes_officer":
			AddQuestRecord("ANIMISTS", 24);
			AddPassenger(pchar, characterFromID("Jaoquin de masse"), 0);
			Characters[getCharacterIndex("Jaoquin de masse")].location = "none";
			Characters[GetCharacterIndex("Jaoquin de masse")].dialog.Filename = "Enc_Officer_dialog.c"; // PB
			Characters[GetCharacterIndex("Jaoquin de masse")].dialog.CurrentNode = "hired"; // PB
			LAi_SetStayType(characterFromID("father Bernard"));
		break;

		case "speak_with_jordano":
			AddQuestRecord("ANIMISTS", 25);
			Locations[FindLocation("Muelle_town_01")].vcskip = true; // NK
			ChangeCharacterAddress(characterFromID("Jordano"), "Muelle_town_01", "goto18");
			LAi_SetActorType(characterFromID("Jordano"));
			LAi_ActorDialog(characterFromID("Jordano"), pchar, "", 5.0, 1.0);
		break;

		case "speak_with_jordano2":  // --> edited by Cat for Animists Quest fix
			DoQuestCheckDelay("speak_with_jordano3", 25.0);
		break;

		case "speak_with_jordano3":
			ChangeCharacterAddress(characterFromID("Jordano"), "none", "");
		break;  // <-- edited by Cat for Animists Quest fix

		case "Story_freedom_letter":
			ChangeCharacterAddress(characterFromID("Teacher"), "", "");
			pchar.quest.with_teacher_to_muelle.win_condition.l1 = "location";
			pchar.quest.with_teacher_to_muelle.win_condition.l1.location = "IslaMuelle";
			pchar.quest.with_teacher_to_muelle.win_condition = "with_teacher_to_muelle";
		break;   // <--Cat

		case "wait_in_church_for_letters":
			pchar.quest.ANIMISTS = "to_prison_for_teacher_2";
			LAi_Fade("", "");
			LAi_SetActorType(characterFromID("father Bernard"));
			LAi_ActorDialog(characterFromID("father Bernard"), pchar, "bernard_back_to_stay_type", 2.0, 1.0);
		break;

		case "bernard_back_to_stay_type":
			LAi_SetStayType(characterFromID("father Bernard"));
		break;

		case "mystery_man_to_prison":
			//RestoreCharacter(characterFromID("Teacher")); // KK
			LAi_SetStayType(characterFromID("Teacher"));
			LAi_SetHP(characterFromID("Teacher"), 80.0, 80.0);
			ChangeCharacterAddress(characterFromID("Teacher"), "Greenford_prison", "goto9");
		break;

		case "teacher_died":
			Island_SetReloadEnableLocal("IslaMuelle", "reload_2", true);
			LAi_KillCharacter(characterFromID("Teacher"));
			//ChangeCharacterAddressGroup(characterFromID("Teacher"), "none", "", "");
			//characterFromID("Teacher").location = "none";	//CTM
			//Locations[FindLocation("muelle_ANIMISTS")].locators_radius.goto.goto37 = 2.2;	//CTM
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1 = "locator";
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1.location = "Muelle_ANIMISTS";
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1.locator_group = "goto";
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1.locator = "goto37";
			pchar.quest.final_battle_with_dark_teacher.win_condition = "final_battle_with_dark_teacher";
			LAi_group_FightGroups("ANIMISTS_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_QuestDelay("Story_Domingues_to_cave", 0.0); //CTM
		break;

		case "exit_from_prison_with_teacher":
			cidx = GetTownNation("Greenford");
			LeaveService(PChar, cidx, false); // RM
			homegroup = GetSoldiersGroup(cidx);
			LAi_group_FightGroups(homegroup, LAI_GROUP_PLAYER, true);
		break;

		case "prison_commander_captured":
			pchar.quest.ANIMISTS = "force_freedom";
			LAi_SetStayType(characterFromID("Teacher"));
			LAi_SetHP(characterFromID("Teacher"), 80.0, 80.0);
			ChangeCharacterAddress(characterFromID("Teacher"), "Greenford_prison", "goto9");
		break;

		case "with_teacher_to_muelle":
			// PW --> if warden killed: sour relations with England
			// Grey Roger: If Early Explorers, it's not England
			if (CheckQuestAttribute("ANIMISTS", "with_teacher_to_muelle") && LAi_IsDead(characterFromID("Greenford Prison Commendant")))
			{
		       cidx = GetTownNation("Greenford");
		       LeaveService(PChar, cidx, false); // RM
		       homegroup = GetSoldiersGroup(cidx);
			}
			// --> PW relations change if warden dead

			//PW --> check if Teacher killed in prison after Viper patch if yes skip onboard and tavern scenes
			if (CheckQuestAttribute("ANIMISTS", "with_teacher_to_muelle") && LAi_IsDead(characterFromID("Teacher")))
			{
				pchar.quest.destroy_ANIMISTS.win_condition.l1 = "location";
				pchar.quest.destroy_ANIMISTS.win_condition.l1.location = "IslaMuelle";
				pchar.quest.destroy_ANIMISTS.win_condition = "to_ANIMISTS";
			}
			 else
			{
			//<-- PW Teacher killed skip ends
				ChangeCharacterAddress(characterFromID("Teacher"), "denielle_deck", "goto1");
				DoQuestCheckDelay("with_teacher_to_muelle_2", 1.0);
				DisableFastTravel(true);
				DisableMenuLaunch(true);
			}
		break;

		case "with_teacher_to_muelle_2":
			DoQuestReloadToLocation("denielle_deck", "reload", "locator2", "with_teacher_to_muelle_21");
		break;

		case "with_teacher_to_muelle_21":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Teacher"));
			ChangeCharacterAddress(characterFromID("Teacher"), "denielle_deck", "goto6");
			LAi_SetActorType(characterFromID("Teacher"));
			LAi_ActorDialog(characterFromID("Teacher"), pchar, "with_teacher_to_muelle_3", 2.0, 1.0);
		break;

		case "with_teacher_to_muelle_3":
			pchar.quest.ANIMISTS = "with_teacher_in_tavern";
			ChangeCharacterAddress(characterFromID("Teacher"), "Muelle_tavern_upstairs", "goto4");
			DoQuestReloadToLocation("Muelle_tavern_upstairs", "goto", "goto3", "with_teacher_to_muelle_4");
			if (GetNationRelation2MainCharacter(SPAIN) != RELATION_ENEMY)
			{
				pchar.location.from_sea = "Muelle_port";
			}
			else
			{
				pchar.location.from_sea = "Muelle_shore";
			}
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			PlaceFleetNearShore(pchar.location.from_sea);
		break;

		case "with_teacher_to_muelle_4":
			LAi_ActorDialog(characterFromID("Teacher"), pchar, "with_teacher_to_muelle_5", 2.0, 1.0);
		break;

		case "with_teacher_to_muelle_5":
			LAi_LocationFightDisable("Muelle_tavern_upstairs", false);
			LAi_ActorAttack(characterFromID("Teacher"), pchar, "");
			Lai_SetPlayerType(pchar);
			pchar.quest.destroy_ANIMISTS.win_condition.l1 = "NPC_Death";
			pchar.quest.destroy_ANIMISTS.win_condition.l1.character = "Teacher";
			pchar.quest.destroy_ANIMISTS.win_condition = "to_ANIMISTS";
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "ANIMISTS_SOLDIERS", true);
			Locations[FindLocation("muelle_ANIMISTS")].locators_radius.goto.goto37 = 2.2;
		break;

		case "to_ANIMISTS":
			Island_SetReloadEnableLocal("IslaMuelle", "reload_2", true);
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1 = "locator";
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1.location = "muelle_ANIMISTS";
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1.locator_group = "goto";
			pchar.quest.final_battle_with_dark_teacher.win_condition.l1.locator = "goto37";
			pchar.quest.final_battle_with_dark_teacher.win_condition = "final_battle_with_dark_teacher";
			LAi_group_FightGroups("ANIMISTS_SOLDIERS", LAI_GROUP_PLAYER, true);

			LAi_QuestDelay("Story_Domingues_to_cave", 0.0); //CTM
		break;

		case "final_battle_with_dark_teacher":
// Attempted fix for game crashing if player disables WEAPONSMOD during game -->
			ch = CharacterFromID("Dark teacher");
			if (!ENABLE_WEAPONSMOD)
			{
				if (GetCharacterEquipByGroup(ch, BLADE_ITEM_TYPE) == "" || GetCharacterEquipByGroup(ch, BLADE_ITEM_TYPE) == "bladeC36+2")
				GiveItem2Character(ch, "bladeC36");	// Katana
				EquipCharacterByItem(ch, "bladeC36");
			}
// <-- Attempted fix for game crashing if player disables WEAPONSMOD during game

			LAi_SetStayType(pchar);
			LAi_SetActorType(characterFromID("Dark teacher"));
			LAi_ActorDialogNow(characterFromID("Dark teacher"), pchar, "player_back", 1.0);
			pchar.quest.destroy_ANIMISTS_complete.win_condition.l1 = "NPC_Death";
			pchar.quest.destroy_ANIMISTS_complete.win_condition.l1.character = "Dark Teacher";
			pchar.quest.destroy_ANIMISTS_complete.win_condition = "destroy_ANIMISTS_complete";
		break;

		case "dark_teacher_WANT_kill_YOU":
			LAi_SetWarriorType(characterFromID("Dark teacher"));
			LAi_group_MoveCharacter(characterFromID("Dark teacher"), "LURKING_BOSS");
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "LURKING_BOSS", true);
			//LAi_ActorAttack(characterFromID("Dark teacher"), pchar, "");
		break;

		case "destroy_ANIMISTS_complete":
			pchar.quest.ANIMISTS = "completed";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 50000);
				AddPartyExpChar(pchar, "Sneak", 5000);
			}
			else { AddPartyExp(pchar, 50000); }
			ChangeCharacterReputation(pchar, 10);
			//pchar.reputation = makeint(pchar.reputation) +10;
//			GiveItem2Character(pchar, "blade20+2");	// GR: why?  Possibly to reward players who disabled corpse looting?  If so...
			if(CORPSEMODE < 2)			// ... give the Teacher's equipment to the player only if corpse looting disabled
			{
				if (ENABLE_WEAPONSMOD) GiveItem2Character(ch, "bladeC36+2");
				else GiveItem2Character(ch, "bladeC36");
				GiveItem2Character(ch, "commonarmor");
			}
			LAi_QuestDelay("destroy_ANIMISTS_complete_2", 6.0);
		break;

		case "destroy_ANIMISTS_complete_2":
//			pchar.quest.ANIMISTS = "domingues_dialog";
			LAi_SetActorType(pchar);
			pchar.dialog.currentnode = "Animists_killed";
			LAi_ActorSelfDialog(pchar, "player_back");

			pchar.quest.fight_with_mefisto.win_condition.l1 = "location";
			pchar.quest.fight_with_mefisto.win_condition.l1.location = "IslaMuelle";
			pchar.quest.fight_with_mefisto.win_condition = "fight_with_mefisto";
			AddQuestRecord("ANIMISTS", 36);
		break;

		case "fight_with_mefisto":
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal("IslaMuelle", false);

			Group_CreateGroup("Mefisto");
			Group_AddCharacter("Mefisto", "Dark Captain");
			Group_SetGroupCommander("Mefisto", "Dark Captain");
			Group_SetPursuitGroup("Mefisto", PLAYER_GROUP);
			Group_SetTaskAttack("Mefisto", PLAYER_GROUP, true);
			Group_SetAddress("Mefisto", Characters[GetMainCharacterIndex()].location, "", "");
			Group_LockTask("Mefisto");

			Characters[GetCharacterIndex("Dark Captain")].recognized = true; // PB: Ensure they're hostile!

			pchar.quest.destroy_mefisto_complete.win_condition.l1 = "NPC_Death";
			pchar.quest.destroy_mefisto_complete.win_condition.l1.character = "Dark Captain";
			pchar.quest.destroy_mefisto_complete.win_condition = "destroy_mefisto_complete";
			AddQuestRecord("ANIMISTS", 37);
		break;

		case "destroy_mefisto_complete":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 15000);
				AddPartyExpChar(pchar, "Sailing", 5000);
				AddPartyExpChar(pchar, "Sneak", 500);
			}
			else { AddPartyExp(pchar, 15000); }
			ChangeCharacterReputation(pchar, 10);
			bQuestDisableMapEnter = false
			Island_SetReloadEnableGlobal("IslaMuelle", true);
			AddQuestRecord("ANIMISTS", 42);
			ItemSetPrice("animists_amulet", 1);	// GR: can now dump Animist amulet into a chest
//			CloseQuestHeader("ANIMISTS");

// CTM -->
			pchar.quest.return_priest_complete.win_condition.l1 = "location";
			pchar.quest.return_priest_complete.win_condition.l1.location = "Muelle_Port";
			pchar.quest.return_priest_complete.win_condition = "return_priest_complete";

			pchar.quest.return_priest_complete1.win_condition.l1 = "location";
			pchar.quest.return_priest_complete1.win_condition.l1.location = "Muelle_Shore";
			pchar.quest.return_priest_complete1.win_condition = "return_priest_complete1";
// CTM <--
		break;

		case "womens_leave_town":
			if(GetMusicScheme() == "Hearts")
			{
				PauseAllSounds();
				PlayStereoOGG("Dawn_at_the_Bay");
			}

			ChangeCharacterReputation(pchar, 4);
			LAi_SetActorType(characterFromID("Rian Dekkers"));
			LAi_SetActorType(characterFromID("Janneke Blinkerhof"));
			LAi_SetActorType(characterFromID("Lisebet Schefold"));
			LAi_ActorGoToLocation(characterFromID("Rian Dekkers"), "reload", "reload9", "none", "", "", "", 60.0);			// GR: The women have just been told their children are in port,
			LAi_ActorGoToLocation(characterFromID("Janneke Blinkerhof"), "reload", "reload9", "none", "", "", "", 60.0);		// GR: so make them go to the port, and give them time to get there.
			LAi_ActorGoToLocation(characterFromID("Lisebet Schefold"), "reload", "reload9", "none", "", "", "", 60.0);
			PChar.quest.womens_left_town.win_condition.l1 = "ExitFromLocation";							// GR: When you leave the town area, make the women disappear
			PChar.quest.womens_left_town.win_condition.l1.location = PChar.location;						// GR: so they aren't still walking to the port if you leave the island
			PChar.quest.womens_left_town.win_condition = "womens_left_town";							// GR: and then return later.
		break;

		case "womens_left_town":
			LAi_SetStayType(CharacterFromID("Rian Dekkers"));
			LAi_SetStayType(CharacterFromID("Janneke Blinkerhof"));
			LAi_SetStayType(CharacterFromID("Lisebet Schefold"));
			changeCharacterAddress(CharacterFromID("Rian Dekkers"), "none", "");
			changeCharacterAddress(CharacterFromID("Janneke Blinkerhof"), "none", "");
			changeCharacterAddress(CharacterFromID("Lisebet Schefold"), "none", "");
		break;

// --> CatalinaThePirate Fix for Animist Quest
		case "Story_Gareth_deception":
			LAi_SetActorType(characterFromID("father Gareth"));
			LAi_ActorDialog(characterFromID("father Gareth"), pchar, "", 2.0, 1.0);
			LAi_ActorWaitDialog(Pchar, characterFromID("father Gareth"));
			characters[GetCharacterIndex("father Gareth")].dialog.currentnode = "letter_to_domingues";
		break;

		case "Story_Gareth_deception2":
			LAi_SetActorType(characterFromID("Father Bernard"));
			LAi_ActorDialog(characterFromID("Father Bernard"), pchar, "", 2.0, 1.0);
			LAi_ActorWaitDialog(Pchar, characterFromID("Father Bernard"));
			characters[GetCharacterIndex("Father Bernard")].dialog.currentnode = "ANIMISTS_letters_5";
		break;

		case "Story_Domingues_to_cave":
			ChangeCharacterAddress(characterFromID("padre Domingues"), "Muelle_ANIMISTS", "goto21");

			Locations[FindLocation("muelle_ANIMISTS")].locators_radius.goto.goto21 = 5.0;
			pchar.quest.domingues_in_cell.win_condition.l1 = "locator";
			pchar.quest.domingues_in_cell.win_condition.l1.location = "Muelle_ANIMISTS";
			pchar.quest.domingues_in_cell.win_condition.l1.locator_group = "goto";
			pchar.quest.domingues_in_cell.win_condition.l1.locator = "goto21";
			pchar.quest.domingues_in_cell.win_condition = "domingues_in_cell";
		break;

		case "domingues_in_cell":
			LAi_SetActorType(characterFromID("padre Domingues"));
			LAi_ActorDialog(characterFromID("padre Domingues"), pchar, "", 2.0, 1.0);
			LAi_ActorWaitDialog(characterFromID("padre Domingues"), PChar); //CTM
			characters[GetCharacterIndex("padre Domingues")].dialog.currentnode = "Domingues_in_cave";
		break;

		case "Domingues_warning":
			pchar.quest.Domingues_warning2.win_condition.l1 = "NPC_Death";
			pchar.quest.Domingues_warning2.win_condition.l1.character = "Dark Teacher";
			pchar.quest.Domingues_warning2.win_condition = "Domingues_warning2";
		break;

		case "Domingues_warning2":
			Locations[FindLocation("muelle_ANIMISTS")].locators_radius.goto.goto21 = 5.0;
			pchar.quest.Domingues_warning3.win_condition.l1 = "locator";
			pchar.quest.Domingues_warning3.win_condition.l1.location = "Muelle_ANIMISTS";
			pchar.quest.Domingues_warning3.win_condition.l1.locator_group = "goto";
			pchar.quest.Domingues_warning3.win_condition.l1.locator = "goto21";
			pchar.quest.Domingues_warning3.win_condition = "Domingues_warning3";
		break;

		case "Domingues_warning3":
			LAi_SetActorType(characterFromID("padre Domingues"));
			LAi_ActorDialog(characterFromID("padre Domingues"), pchar, "", 2.0, 1.0);
			LAi_ActorWaitDialog(characterFromID("padre Domingues"), PChar); //CTM
			characters[GetCharacterIndex("padre Domingues")].dialog.currentnode = "Domingues_in_cave2";
		break;

		case "Story_Domingues_released":
			LAi_QuestDelay("Story_Domingues_released2", 20.0);
		break;

		case "Story_Domingues_released2":
			changeCharacterAddress(characterfromID("second_spaniard_priest"), "none", ""); // KK
			changeCharacterAddress(characterfromID("padre Domingues"), "none", "");
		break;
		// NK <--

		// CTM -->
		case "return_priest_complete":
			LAi_QuestDelay("return_priest_complete2", 1.0);

			pchar.quest.return_priest_complete1.over = "yes";
		break;

		case "return_priest_complete1":
			LAi_QuestDelay("return_priest_complete2", 1.0);

			pchar.quest.return_priest_complete.over = "yes";
		break;

		case "return_priest_complete2":
			DoReloadCharacterToLocation("Muelle_Church", "reload", "reload1");
			changeCharacterAddressGroup(characterfromID("padre Domingues"), "Muelle_Church", "goto", "goto1");	// GR: if you didn't return to Animist cave cell to release Domingues, he appears
			changeCharacterAddress(characterfromID("second_spaniard_priest"), "none", "");						// here anyway but Padre Robano is not removed. Do it now instead.
			LAi_SetActorType(characterFromID("padre Domingues"));
			LAi_ActorDialog(characterFromID("padre Domingues"), pchar, "", 0.0, 0.0);
			characters[GetCharacterIndex("padre Domingues")].dialog.currentnode = "Thank_You";

			pchar.quest.return_priest_complete.over = "yes";

			Locations[FindLocation("Muelle_church")].reload.l1.go = "Muelle_town_04";							//GR: put church exit back to normal
			Locations[FindLocation("Muelle_church")].reload.l1.emerge = "reload4";
		break;

		case "return_priest_complete3":
			AddQuestRecord("ANIMISTS", 41);

			pchar.quest.return_priest_complete4.win_condition.l1 = "ExitFromLocation";
			pchar.quest.return_priest_complete4.win_condition.l1.location = "Muelle_Church";
			pchar.quest.return_priest_complete4.win_condition = "return_priest_complete4";
		break;

		case "return_priest_complete4":
			changeCharacterAddress(characterfromID("padre Domingues"), "Muelle_church", "goto11");
			LAi_SetStayType(characterFromID("padre Domingues"));
			Characters[GetCharacterIndex("padre Domingues")].dialog.CurrentNode  = "First time";
		break;
		// CTM <--


///////////////////////////////////////////////////////////////
// FIND THE MISSING SON OF THE SPANISH ADMIRAL (Lucas Da Saldanha quest)
///////////////////////////////////////////////////////////////

		case "Luc_start":
			SetEnterLocationQuest("Muelle_residence", "Luc_start_check", 0);
		break;

		case "Luc_start_check":
			if(makeint(PChar.rank) >= 4)
			{
				ChangeCharacterAddressGroup(CharacterFromID("Joaquin Da Saldanha"), "Muelle_Residence", "goto", "goto6");
			}
		break;

		case "Lucas_search_refused":
			PChar.quest.Lucas = "refused";

			DeleteEnterLocationQuest("Muelle_residence", "Luc_start_check");
		break;

		case "Lucas_search_start":
			PChar.quest.Lucas = "search";

			DeleteEnterLocationQuest("Muelle_residence", "Luc_start_check");

			//JOURNAL
			SetQuestHeader("Lucas");
			AddQuestRecord("Lucas", 1);
		break;

		case "Lucas_search1":
			PChar.quest.Lucas = "search1";

			ChangeCharacterAddressGroup(CharacterFromID("Arabella Silehard"), "Redmond_jungle_01", "goto", "goto9");
			ChangeCharacterAddressGroup(CharacterFromID("Arabella's guard 1"), "Redmond_jungle_01", "goto", "goto10");
			ChangeCharacterAddressGroup(CharacterFromID("Arabella's guard 2"), "Redmond_jungle_01", "goto", "goto11");
			LAi_group_MoveCharacter(CharacterFromID("Arabella Silehard"), "ARABELLA");
			LAi_group_MoveCharacter(CharacterFromID("Arabella's guard 1"), "ARABELLA");
			LAi_group_MoveCharacter(CharacterFromID("Arabella's guard 2"), "ARABELLA");
			LAi_SetImmortal(CharacterFromID("Arabella Silehard"), true);
			LAi_SetImmortal(CharacterFromID("Arabella's guard 1"), true);
			LAi_SetImmortal(CharacterFromID("Arabella's guard 2"), true);
			LAi_group_SetRelation("ARABELLA", "ARABELLA", LAI_GROUP_FRIEND);
			LAi_group_SetAlarmReaction("ARABELLA", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL, LAI_GROUP_NEUTRAL);

			//JOURNAL
			AddQuestRecord("Lucas", 2);
		break;

		case "Lucas_search2":
			PChar.quest.Lucas = "search2";

			//JOURNAL
			AddQuestRecord("Lucas", 3);

			pchar.quest.Lucas_ArabellaLeave.win_condition.l1 = "ExitFromLocation";
			pchar.quest.Lucas_ArabellaLeave.win_condition.l1.location = pchar.location;
			pchar.quest.Lucas_ArabellaLeave.win_condition = "Lucas_ArabellaLeave";
		break;

		case "Lucas_ArabellaLeave":
			ChangeCharacterAddressGroup(CharacterFromID("Arabella Silehard"), "None", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Arabella's guard 1"), "None", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Arabella's guard 2"), "None", "", "");
		break;

		case "Lucas_ransom_refused":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Lucas_ransom_refused");
			bDisableFastReload = 1;

			LAi_SetActorType(CharacterFromID("Joaquin Da Saldanha"));
			LAi_CharacterDisableDialog(CharacterFromID("Joaquin Da Saldanha"));
			LAi_ActorGoToLocation(CharacterFromID("Joaquin Da Saldanha"), "reload", "reload1", "none", "", "", "Lucas_ransom_refused1", 3.0);

			//JOURNAL
			AddQuestRecord("Lucas", 4);
			CloseQuestHeader("Lucas");
		break;

		case "Lucas_ransom_refused1":
			EndQuestMovie();TrackQuestMovie("end","Lucas_ransom_refused1");
			bDisableFastReload = 0;
		break;

		case "Lucas_ransom_start":
			PChar.quest.Lucas = "ransom";

			AddMoneyToCharacter(PChar, 20000);

			ChangeCharacterAddressGroup(CharacterFromID("Billy Brock"), "Falaise_de_fleur_tavern", "goto", "goto3");
			ChangeCharacterAddressGroup(CharacterFromID("Snorri Baldursson"), "Falaise_de_fleur_tavern", "goto", "goto2");
			ChangeCharacterAddressGroup(CharacterFromID("Francis Snake"), "Ransom_house_f2", "goto", "goto1");
			ChangeCharacterAddressGroup(CharacterFromID("Lucas Da Saldanha"), "Ransom_house_f2", "goto", "goto4");
			Locations[FindLocation("Falaise_De_Fleur_location_03")].reload.l12.close_for_night = 0;
			Locations[FindLocation("Falaise_De_Fleur_location_03")].reload.l12.label = "Kidnappers' Hideout";
			Locations[FindLocation("Falaise_de_fleur_tavern")].vcskip = true; // NK

			PChar.quest.Lucas_ransom_deadline.win_condition.l1 = "Timer";
			PChar.quest.Lucas_ransom_deadline.win_condition.l1.date.day = GetAddingDataDay(0, 1, 0);
			PChar.quest.Lucas_ransom_deadline.win_condition.l1.date.month = GetAddingDataMonth(0, 1, 0);
			PChar.quest.Lucas_ransom_deadline.win_condition.l1.date.year = GetAddingDataYear(0, 1, 0);
			PChar.quest.Lucas_ransom_deadline.win_condition = "Lucas_ransom_deadline";

			PChar.quest.Lucas_ransom_delivery.win_condition.l1 = "location";
			PChar.quest.Lucas_ransom_delivery.win_condition.l1.character = PChar.id;
			PChar.quest.Lucas_ransom_delivery.win_condition.l1.location = "Falaise_de_fleur_tavern";
			PChar.quest.Lucas_ransom_delivery.win_condition = "Lucas_ransom_delivery";

			//JOURNAL
			AddQuestRecord("Lucas", 5);
		break;

		case "Lucas_ransom_deadline":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			// unneeded if(GetRMRelation(PChar, SPAIN) > REL_AFTERATTACK) SetRMRelation(PChar, SPAIN, REL_AFTERATTACK); // RM - SetNationRelation2MainCharacter(SPAIN, RELATION_ENEMY);
			LeaveService(PChar, SPAIN, false); // RM

			ChangeCharacterAddressGroup(CharacterFromID("Joaquin Da Saldanha"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Arabella Silehard"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Arabella's guard 1"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Arabella's guard 2"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Billy Brock"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Snorri Baldursson"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Francis Snake"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Lucas Da Saldanha"), "none", "", "");

			//JOURNAL
			AddQuestRecord("Lucas", 14);
			CloseQuestHeader("Lucas");
		break;

		case "Lucas_ransom_delivery":
			if(CheckQuestAttribute("gambling_with_girl", "to_FDF")) // GR: Check if "Girl Won in Card Game" is ready to enter tavern
			{
				PChar.quest.Lucas = "sign"; // GR: Billy Brock is in "Guardian" mode so you can talk to him. This attribute means he'll talk about ransom
				break;
			}
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Lucas_ransom_delivery");
			bDisableFastReload = 1;

			LAi_SetActorType(CharacterFromID("Billy Brock"));
			LAi_SetActorType(CharacterFromID("Snorri Baldursson"));

			LAi_ActorTurnToCharacter(CharacterFromID("Billy Brock"), CharacterFromID("Snorri Baldursson"));
			LAi_ActorTurnToCharacter(CharacterFromID("Snorri Baldursson"), CharacterFromID("Billy Brock"));

			LAi_SetActorType(PChar);
			pchar.dialog.currentnode = "Lucas"; // CTM
			LAi_ActorSelfDialog(PChar, "");
		break;

		case "Lucas_ransom_delivery1":
		//dialog exit from self
			LAi_ActorGoToLocator(PChar, "goto", "goto6", "Lucas_ransom_delivery2", 3.0);
		break;

		case "Lucas_ransom_delivery2":
			Pchar.dialog.CurrentNode = "Eavesdrop1";
			LAi_ActorTurnToCharacter(PChar, CharacterFromID("Billy Brock"));
			LAi_ActorSelfDialog(PChar, "");
		break;

		case "Lucas_sign1":
		//dialog exit from Self
			PChar.quest.Lucas = "sign";
			LAi_SetPlayerType(PChar);
			LAi_ActorDialog(CharacterFromID("Billy Brock"), PChar, "", 4.0, -1);
		break;

		case "Lucas_sign2":
		//dialog exit from Brock
			LAi_SetActorType(CharacterFromID("Billy Brock"));
			LAi_ActorGoToLocation(CharacterFromID("Billy Brock"), "reload", "reload1", "Falaise_de_fleur_location_03", "goto", "sitizen04", "Lucas_sign3", 5.0);
		break;

		case "Lucas_sign3":
			EndQuestMovie();TrackQuestMovie("end","Lucas_sign3");
			PChar.quest.Lucas_sign4.win_condition.l1 = "location";
			PChar.quest.Lucas_sign4.win_condition.l1.character = PChar.id;
			PChar.quest.Lucas_sign4.win_condition.l1.location = "Falaise_de_fleur_location_03";
			PChar.quest.Lucas_sign4.win_condition = "Lucas_sign4";
		break;

		case "Lucas_sign4":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Lucas_sign4");
			LAi_ActorGoToLocation(CharacterFromID("Billy Brock"), "reload", "home7", "Ransom_house_f1", "goto", "goto3", "Lucas_sign5", 10.0);
		break;

		case "Lucas_sign5":
			EndQuestMovie();TrackQuestMovie("end","Lucas_sign5");
			bDisableFastReload = 0;
			PChar.quest.Lucas_sign6.win_condition.l1 = "location";
			PChar.quest.Lucas_sign6.win_condition.l1.character = PChar.id;
			PChar.quest.Lucas_sign6.win_condition.l1.location = "Ransom_house_f1";
			PChar.quest.Lucas_sign6.win_condition = "Lucas_sign6";
			Locations[FindLocation("Ransom_house_f1")].vcskip = true; // NK
		break;

		case "Lucas_sign6":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Lucas_sign6");
			bDisableFastReload = 1;
			LAi_LocationFightDisable(&Locations[FindLocation("Ransom_house_f1")], 1);
			PChar.quest.Lucas = "sign1";
			LAi_ActorDialog(CharacterFromID("Billy Brock"), PChar, "", 4.0, -1);
		break;

		case "Lucas_sign7":
		//dialog exit from Brock
			PChar.quest.Lucas = "sign2";
			LAi_ActorGoToLocation(CharacterFromID("Billy Brock"), "reload", "reload2", "none", "", "", "Lucas_sign8", 10.0);
		break;

		case "Lucas_sign8":
			LAi_QuestDelay("Lucas_sign9", 3.0);
		break;

		case "Lucas_sign9":
			DeleteAttribute(&Locations[FindLocation("Falaise_de_fleur_tavern")],"vcskip"); // NK
			ChangeCharacterAddressGroup(CharacterFromID("Francis Snake"), "Ransom_house_f1", "reload", "reload2");
			LAi_SetActorType(CharacterFromID("Francis Snake"));
			LAi_ActorGoToLocator(CharacterFromID("Francis Snake"), "goto", "goto2", "Lucas_sign9_1", 10.0);

			LAi_QuestDelay("Lucas_sign10", 2.5);
		break;

		case "Lucas_sign9_1":
			LAi_ActorTurnToCharacter(CharacterFromID("Francis Snake"), PChar);
		break;


		case "Lucas_sign10":
			ChangeCharacterAddressGroup(CharacterFromID("Lucas Da Saldanha"), "Ransom_house_f1", "reload", "reload2");
			LAi_SetActorType(CharacterFromID("Lucas Da Saldanha"));
			LAi_ActorGoToLocator(CharacterFromID("Lucas Da Saldanha"), "goto", "goto1", "Lucas_sign10_1", 10.0);

			LAi_QuestDelay("Lucas_sign11", 2.5);
		break;

		case "Lucas_sign10_1":
			LAi_ActorTurnToCharacter(CharacterFromID("Lucas Da Saldanha"), PChar);
		break;

		case "Lucas_sign11":
			ChangeCharacterAddressGroup(CharacterFromID("Billy Brock"), "Ransom_house_f1", "reload", "reload2");
			LAi_ActorGoToLocator(CharacterFromID("Billy Brock"), "goto", "goto3", "Lucas_sign12", 10.0);
		break;

		case "Lucas_sign12":
			EndQuestMovie();TrackQuestMovie("end","Lucas_sign12");

			LAi_ActorDialog(CharacterFromID("Billy Brock"), PChar, "", 3.0, -1);
			DeleteAttribute(&Locations[FindLocation("Ransom_house_f1")],"vcskip"); // NK
		break;

		case "Lucas_kill":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Lucas_kill");

			LAi_LocationFightDisable(&Locations[FindLocation("Ransom_house_f1")], 0);

			LAi_KillCharacter(CharacterFromID("Lucas Da Saldanha"));

			LAi_SetWarriorType(CharacterFromID("Billy Brock"));
			LAi_SetWarriorType(CharacterFromID("Francis Snake"));

			LAi_group_MoveCharacter(CharacterFromID("Billy Brock"), "kidnappers");
			LAi_group_MoveCharacter(CharacterFromID("Francis Snake"), "kidnappers");

			LAi_group_FightGroups("kidnappers", LAI_GROUP_PLAYER, 1);

			LAi_group_SetCheck("kidnappers", "Lucas_killed");
		break;

		case "Lucas_killed":
			EndQuestMovie();TrackQuestMovie("end","Lucas_killed");

			DisableFastTravel(true);
			DisableMenuLaunch(true);

			DoQuestCheckDelay("Lucas_ransom_deadline", 3.0);
		break;

		case "Lucas_sign13":
		//dialog exit from Brock
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Lucas_sign13");

			AddMoneyToCharacter(PChar, -20000);
			LAi_type_actor_Reset(CharacterFromID("Billy Brock"));
			LAi_type_actor_Reset(CharacterFromID("Francis Snake"));
			LAi_ActorGoToLocation(CharacterFromID("Billy Brock"), "reload", "reload1", "none", "", "", "", 3.0);
			LAi_ActorGoToLocation(CharacterFromID("Francis Snake"), "reload", "reload1", "none", "", "", "Lucas_talk1", 4.0);
			ChangeCharacterAddressGroup(CharacterFromID("Snorri Baldursson"), "none", "", "");
		break;

		case "Lucas_talk1":
			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "free";
			LAi_type_actor_Reset(CharacterFromID("Lucas Da Saldanha"));
			LAi_ActorDialog(CharacterFromID("Lucas Da Saldanha"), PChar, "", 3.0, -1);
		break;

		case "Lucas_talk1_1":
		//dialog exit from Lucas
			EndQuestMovie();TrackQuestMovie("end","Lucas_talk1_1");

			PChar.quest.Lucas = "return";

			GiveItem2Character(CharacterFromId("Lucas Da Saldanha"), "bladeC6");
			GiveItem2Character(CharacterFromId("Lucas Da Saldanha"),"pistol3");
			EquipCharacterByItem(CharacterFromId("Lucas Da Saldanha"), "bladeC6");
			EquipCharacterByItem(CharacterFromId("Lucas Da Saldanha"), "pistol3");

		     //JRH ammo mod -->
			if (ENABLE_AMMOMOD) {	// LDH change
				TakenItems(CharacterFromId("Lucas Da Saldanha"), "gunpowder", 6);
				TakenItems(CharacterFromId("Lucas Da Saldanha"), "pistolgrapes", 6);
			}
		     //JRH ammo mod <--

			LAi_SetImmortal(CharacterFromID("Lucas Da Saldanha"), 1);

			LAi_ActorFollowEverywhere(CharacterFromID("Lucas Da Saldanha"), "", 0.0);

			PChar.quest.Lucas_talk2.win_condition.l1 = "location";
			PChar.quest.Lucas_talk2.win_condition.l1.character = PChar.id;
			PChar.quest.Lucas_talk2.win_condition.l1.location = "Falaise_de_fleur_location_03";
			PChar.quest.Lucas_talk2.win_condition = "Lucas_talk2";

			//JOURNAL
			AddQuestRecord("Lucas", 7);
		break;

		case "Lucas_talk2":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Lucas_talk2");

			LAi_LocationFightDisable(&Locations[FindLocation("Ransom_house_f1")], 0);
			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "free1";

			LAi_ActorDialog(CharacterFromID("Lucas Da Saldanha"), PChar, "", 2.0, -1);
		break;

		case "Lucas_talk2_1":
			EndQuestMovie();TrackQuestMovie("end","Lucas_talk2_1");

			bDisableFastReload = 0;

			LAi_ActorFollowEverywhere(CharacterFromID("Lucas Da Saldanha"), "", 0.0);

			PChar.quest.Lucas_return.win_condition.l1 = "location";
			PChar.quest.Lucas_return.win_condition.l1.character = PChar.id;
			PChar.quest.Lucas_return.win_condition.l1.location = "Muelle_Residence";
			PChar.quest.Lucas_return.win_condition = "Lucas_return";

			PChar.quest.Lucas_ransom_deadline.over = "yes";
		break;

		case "Lucas_return":
			StartQuestMovie(true, false, false);TrackQuestMovie("start","Lucas_return");

			LAi_Type_Actor_Reset(CharacterFromID("Lucas Da Saldanha"));

			LAi_SetActorType(characterFromID("Joaquin Da Saldanha"));

			LAi_SetActorType(PChar);

			LAi_ActorGoToLocator(PChar, "goto", "goto7", "Lucas_return1", 1.0);

			LAi_ActorGoToLocator(CharacterFromID("Lucas Da Saldanha"), "goto", "goto9", "Lucas_return_1", 2.0);

			LAi_SetImmortal(CharacterFromID("Lucas Da Saldanha"), 0);
		break;

		case "Lucas_return_1":
			LAi_ActorTurnToCharacter(CharacterFromID("Joaquin Da Saldanha"), CharacterFromID("Lucas Da Saldanha"));
			LAi_ActorTurnToCharacter(CharacterFromID("Lucas Da Saldanha"), CharacterFromID("Joaquin Da Saldanha"));

			LAi_QuestDelay("Lucas_return1", 1.0);
		break;

		case "Lucas_return1":
			LAi_ActorTurnToCharacter(PChar, CharacterFromID("Joaquin Da Saldanha"));

			LAi_QuestDelay("Lucas_return1_1", 1.0);
		break;

		case "Lucas_return1_1":
		//dialog exit from self
			LAi_SetPlayerType(PChar);

			LAi_ActorDialog(CharacterFromID("Joaquin Da Saldanha"), PChar, "", 2.0, -1);
		break;

		case "Lucas_end":

		//dialog exit from Joaquin
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			ChangeCharacterReputation(pchar, 20);

			if(GetRMRelation(PChar, SPAIN) < REL_AMNESTY) SetRMRelation(PChar, SPAIN, REL_AMNESTY); // RM

			AddMoneyToCharacter(PChar, +10000);

			LAi_CharacterDisableDialog(CharacterFromID("Joaquin Da Saldanha"));
			LAi_Type_Actor_Reset(CharacterFromID("Joaquin Da Saldanha"));
			LAi_ActorGoToLocation(CharacterFromID("Joaquin Da Saldanha"), "reload", "reload1", "none", "", "", "", 3.0);

			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "join";
			LAi_ActorDialog(CharacterFromID("Lucas Da Saldanha"), PChar, "", 2.0, -1);

			//JOURNAL
			AddQuestRecord("Lucas", 9);
			CloseQuestHeader("Lucas");
		break;

		case "Lucas_join":
		//dialog exit from Lucas

			EndQuestMovie();TrackQuestMovie("end","Lucas_join");

			LAi_Type_Actor_Reset(CharacterFromID("Lucas Da Saldanha"));
			SetOfficersIndex(PChar, 3, GetCharacterIndex("Lucas Da Saldanha")); // NK was -1
		break;

		case "Lucas_no_join":
		//dialog exit from Lucas
			LAi_ActorGoToLocator(CharacterFromID("Lucas Da Saldanha"), "goto", "goto4", "Lucas_no_join1", 3.0);
		break;

		case "Lucas_no_join1":
			EndQuestMovie();TrackQuestMovie("end","Lucas_no_join1");

			ChangeCharacterAddressGroup(CharacterFromID("Lucas Da Saldanha"), "Muelle_Residence", "goto", "goto4");

			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "join_loop";

			LAi_SetStayType(CharacterFromID("Lucas Da Saldanha"));
		break;

		case "Lucas_officer":
			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.Filename = "Enc_Officer_dialog.c"; // PB
			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "hired";
		break;


///////////////////////////////////////////////////////////////
// SMUGGLING FOR THOMAS O'REILY
///////////////////////////////////////////////////////////////

		case "thomas_contraband_exit":
			LAi_SetHP(characterFromID("Bart Cooke"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Wally Cutty"), 80.0, 80.0);
			LAi_SetHP(characterFromID("Bill Jellybones"), 80.0, 80.0);
			LAi_SetCheckMinHP(characterFromID("Bart Cooke"), LAi_GetCharacterHP(characterFromID("Bart Cooke"))-1.0, false, "bill_jellybones_attack"); // KK
			LAi_SetCheckMinHP(characterFromID("Wally Cutty"), LAi_GetCharacterHP(characterFromID("Wally Cutty"))-1.0, false, "bill_jellybones_attack"); // KK
			LAi_SetCheckMinHP(characterFromID("Bill Jellybones"), LAi_GetCharacterHP(characterFromID("Bill Jellybones"))-1.0, false, "bill_jellybones_attack"); // KK
			ChangeCharacterAddress(characterFromID("Bart Cooke"), "Redmond_Shore_02", "goto4");
			ChangeCharacterAddress(characterFromID("Wally Cutty"), "Redmond_Shore_02", "goto6");
			ChangeCharacterAddress(characterFromID("Bill Jellybones"), "Redmond_Shore_02", "goto5");
			string smuggle_goods = Goods[sti(Characters[GetCharacterIndex("Thomas O'Reily")].smuggle_cargo)].name);
			string smuggle_goods2 = Goods[sti(Characters[GetCharacterIndex("Thomas O'Reily")].smuggle_cargo2)].name);

			Preprocessor_AddQuestData("Thomas O'Reily", GetMyFullName(CharacterFromID("Thomas O'Reily")));
			Preprocessor_AddQuestData("Thomas", GetMyName(CharacterFromID("Thomas O'Reily")));
			Preprocessor_AddQuestData("Andre Juliao", GetMyFullName(CharacterFromID("Andre Juliao")));
			Preprocessor_AddQuestData("smuggle_goods", TranslateString("", smuggle_goods));
			Preprocessor_AddQuestData("smuggle_goods2", TranslateString("", smuggle_goods2));
			SetQuestHeader("Thomas_OReily_contraband");
			AddQuestRecord("Thomas_OReily_contraband", 1);
			Preprocessor_Remove("smuggle_goods2");
			Preprocessor_Remove("smuggle_goods");
			Preprocessor_Remove("Andre Juliao");
			Preprocessor_Remove("Thomas");
			Preprocessor_Remove("Thomas O'Reily");

			LAi_QuestDelay("learn about smugglers", 0.0);
		break;

		case "thomas_contraband_12_exit":
			Preprocessor_AddQuestData("Thomas", GetMyName(CharacterFromID("Thomas O'Reily")));
			AddQuestRecord("Thomas_OReily_contraband", 3);
			Preprocessor_Remove("Thomas");
			AddCharacterGoods(characterFromID("Pirate Captain 04"), sti(Characters[GetCharacterIndex("Thomas O'Reily")].smuggle_cargo), sti(Characters[GetCharacterIndex("Thomas O'Reily")].smuggle_amount));
			pchar.quest.thomas_contraband_12_exit_2.win_condition.l1 = "location";
			pchar.quest.thomas_contraband_12_exit_2.win_condition.l1.location = "Redmond";
			pchar.quest.thomas_contraband_12_exit_2.win_condition = "thomas_contraband_12_exit_2";
		break;

		case "thomas_contraband_12_exit_2":
			bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal("Redmond", false);

			NPChar = CharacterFromID("Pirate Captain 04");
			NPChar.recognized = true;
			NPChar.nation = PRIVATEER_NATION;
			SetNationRelationBoth(ENGLAND, PRIVATEER_NATION, RELATION_NEUTRAL);
			SetNationRelationBoth(PERSONAL_NATION, PRIVATEER_NATION, RELATION_ENEMY);
			if(sti(GetAttribute(PChar, "flags.personal")) == 6 && sti(GetAttribute(PChar, "flags.personal.texture")) == 1)
			{
				NPChar.flags.personal = 1;
				NPChar.flags.personal.texture = 2;
			}
			else
			{
				NPChar.flags.personal = 6;
				NPChar.flags.personal.texture = 1;
			}
			NPChar.skipRM = true;
			NPChar.nosurrender = 1;

			Group_CreateGroup("Smugglers_squadron2");
			Group_AddCharacter("Smugglers_squadron2", "Pirate Captain 04");
			Group_SetGroupCommander("Smugglers_squadron2", "Pirate Captain 04");

			Group_SetPursuitGroup("Smugglers_squadron2", PLAYER_GROUP);
			Group_SetTaskAttack("Smugglers_squadron2", PLAYER_GROUP, true);
			Group_SetAddress("Smugglers_squadron2", Characters[GetMainCharacterIndex()].location, "", "");

			SetCharacterRelation(GetCharacterIndex("Pirate Captain 04"),GetMainCharacterIndex(),RELATION_ENEMY);

			UpdateRelations();

			pchar.quest.boarding_smuggler_ship.win_condition.l1 = "Character_Capture";
			pchar.quest.boarding_smuggler_ship.win_condition.l1.character = "Pirate Captain 04";
			pchar.quest.boarding_smuggler_ship.win_condition = "boarding_smuggler_ship";

			pchar.quest.sink_smuggler_ship.win_condition.l1 = "NPC_Death";
			pchar.quest.sink_smuggler_ship.win_condition.l1.character = "Pirate Captain 04";
// KK -->
			pchar.quest.sink_smuggler_ship.win_condition.l2 = "location";
			pchar.quest.sink_smuggler_ship.win_condition.l2.location = PChar.location;
// <-- KK
			pchar.quest.sink_smuggler_ship.win_condition = "sink_smuggler_ship";
		break;

		case "boarding_smuggler_ship":
			bQuestDisableMapEnter = false;
			Island_SetReloadEnableGlobal("Redmond", true);
			characters[GetCharacterIndex("Thomas O'Reily")].quest.contraband = "boarding";
		break;

		case "sink_smuggler_ship":
			bQuestDisableMapEnter = false;
			Island_SetReloadEnableGlobal("Redmond", true);
			ChangeSmugglerLiking(pchar, -20); //Add liking
		break;

		case "bill_jellybones_attack":
			LAi_RemoveCheckMinHP(characterFromID("Bart Cooke"));
			LAi_RemoveCheckMinHP(characterFromID("Wally Cutty"));
			LAi_RemoveCheckMinHP(characterFromID("Bill Jellybones"));

			LAi_SetActorType(characterFromID("Bart Cooke"));
			LAi_SetActorType(characterFromID("Wally Cutty"));
			LAi_SetActorType(characterFromID("Bill Jellybones"));

			Preprocessor_AddQuestData("Thomas", GetMyName(CharacterFromID("Thomas O'Reily")));
			AddQuestRecord("Thomas_OReily_contraband", 2);
			Preprocessor_Remove("Thomas");
			ChangeSmugglerLiking(pchar, -20); //Add liking
			LAi_ActorAttack(characterFromID("Bart Cooke"), pchar, "");
			LAi_ActorAttack(characterFromID("Wally Cutty"), pchar, "");
			LAi_ActorAttack(characterFromID("Bill Jellybones"), pchar, "");
			pchar.quest.exit_from_redmond_shore_02.win_condition.l1 = "location";
			pchar.quest.exit_from_redmond_shore_02.win_condition.l1.location = "Redmond";
			pchar.quest.exit_from_redmond_shore_02.win_condition = "quest_exit_from_redmond_shore_02_complete";
			characters[GetCharacterIndex("Thomas O'Reily")].quest.contraband = "after_fight";
		break;
		
		case "sided with smugglers instead of Thomas":
			LAi_RemoveCheckMinHP(characterFromID("Bart Cooke"));
			LAi_RemoveCheckMinHP(characterFromID("Wally Cutty"));
			LAi_RemoveCheckMinHP(characterFromID("Bill Jellybones"));
			ChangeSmugglerLiking(pchar, 10);
			characters[GetCharacterIndex("Thomas O'Reily")].quest.contraband = "done";
			Preprocessor_AddQuestData("Thomas", GetMyName(CharacterFromID("Thomas O'Reily")));
			AddQuestRecord("Thomas_OReily_contraband", 7);
			Preprocessor_Remove("Thomas");
			CloseQuestHeader("Thomas_OReily_contraband");
			pchar.quest.exit_from_redmond_shore_02.win_condition.l1 = "location";
			pchar.quest.exit_from_redmond_shore_02.win_condition.l1.location = "Redmond";
			pchar.quest.exit_from_redmond_shore_02.win_condition = "remove smugglers from beach Thomas";
		break;
		
		case "remove smugglers from beach Thomas":
			ChangeCharacterAddress(characterFromID("Bart Cooke"), "none", "");
			ChangeCharacterAddress(characterFromID("Wally Cutty"), "none", "");
			ChangeCharacterAddress(characterFromID("Bill Jellybones"), "none", "");
		break;

		case "quest_exit_from_redmond_shore_02_complete":
			Group_CreateGroup("Smugglers_squadron");
			Group_AddCharacter("Smugglers_squadron", "Pirate Captain 01");
			Group_AddCharacter("Smugglers_squadron", "Pirate Captain 02");
			Group_AddCharacter("Smugglers_squadron", "Pirate Captain 03");
			Group_SetGroupCommander("Smugglers_squadron", "Pirate Captain 01");

			Group_SetPursuitGroup("Smugglers_squadron", PLAYER_GROUP);
			Group_SetTaskAttack("Smugglers_squadron", PLAYER_GROUP, true);
			Group_SetAddress("Smugglers_squadron", Characters[GetMainCharacterIndex()].location, "", "");

			SetCharacterRelation(GetCharacterIndex("Pirate Captain 01"),GetMainCharacterIndex(),RELATION_ENEMY);

			UpdateRelations();
		break;

		case "prepare_thierry_bosquet_fight":
			LAi_SetActorType(characterFromID("thierry bosquet"));
			LAi_SetActorType(characterFromID("France_bukaner_01"));
			ChangeCharacterAddress(characterFromID("thierry bosquet"), "Falaise_de_Fleur_jungle", "locator5");
			ChangeCharacterAddress(characterFromID("France_bukaner_01"), "Falaise_de_Fleur_jungle", "locator6");
			LAi_ActorDialog(characterFromID("thierry bosquet"), pchar, "", 3.0, 1.0);
			LAi_ActorFollow(characterFromID("France_bukaner_01"), pchar, "", 5.0);
			LAi_SetCheckMinHP(characterFromID("thierry bosquet"), LAi_GetCharacterHP(characterFromID("thierry bosquet"))-1.0, false, "thierry_bosquet_fight"); // KK
			LAi_SetCheckMinHP(characterFromID("France_bukaner_01"), LAi_GetCharacterHP(characterFromID("France_bukaner_01"))-1.0, false, "thierry_bosquet_fight"); // KK
		break;

		case "thierry_bosquet_fight":
			LAi_RemoveCheckMinHP(characterFromID("thierry bosquet"));
			LAi_RemoveCheckMinHP(characterFromID("France_bukaner_01"));
			LAi_group_MoveCharacter(characterFromID("thierry bosquet"), "FRANCE_BUKANERS");
			LAi_group_MoveCharacter(characterFromID("France_bukaner_01"), "FRANCE_BUKANERS");
			LAi_group_FightGroups("FRANCE_BUKANERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FRANCE_BUKANERS", "thierry_bosquet_fight_completed");
		break;

		case "thierry_bosquet_fight_completed":
			GiveItem2Character(pchar, "blade7");
		break;


///////////////////////////////////////////////////////////////
///// PATRIC AND THE IDOLS
///////////////////////////////////////////////////////////////

		case "lucient_bescanceny_fight":
			LAi_setActorType(CharacterFromID("Lucien Bescanceny"));
			LAi_ActorAttack(CharacterFromID("Lucien Bescanceny"), PChar, "");
			Characters[GetCharacterIndex("Patric Cardone")].quest.teodoro = "5";// NK thanks to Taghmon
			Preprocessor_AddQuestData("Lucien", GetMyName(CharacterFromID("Lucien Bescanceny")));
			Preprocessor_AddQuestData("Patric", GetMyName(CharacterFromID("Patric Cardone")));
			AddQuestRecord("Patric", 5); // NK
			Preprocessor_Remove("Patric");
			Preprocessor_Remove("Lucien");
		break;

		case "andre_juliao_fight_1":
			LAi_Fade("andre_find_locator", "andre_juliao_fight_2");
		break;

		case "andre_find_locator":
			PlaceCharacter(characterFromID("andre juliao"), "goto");
			LAi_SetWarriorType(characterFromID("andre juliao"));
		break;

		case "andre_juliao_fight_2":
			LAi_LocationFightDisable(&Locations[FindLocation("Falaise_de_fleur_tavern")], false);
			LAi_group_MoveCharacter(characterFromID("andre juliao"), "FALAISE_SMUGGLER");
			LAi_group_FightGroups("FALAISE_SMUGGLER", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("FALAISE_SMUGGLER", "andre_juliao_fight_3");
		break;

		case "andre_juliao_fight_3":
			LAi_SetActorType(pchar);
			LAi_LocationFightDisable(&Locations[FindLocation("Falaise_de_fleur_tavern")], true);
			LAi_SetPlayerType(pchar);
		break;


///////////////////////////////////////////////////////////////
///// ARTOIS VOYSEY AND NIGEL BLYTHE
///////////////////////////////////////////////////////////////

//Artois Voysey
// KK -->
		case "Install_Voysey_And_Blythe":
			ChangeCharacterAddressGroup(CharacterFromID("Nigel Blythe"), "QC_town", "goto", "character4");
			ChangeCharacterAddressGroup(CharacterFromID("Artois Voysey"), "QC_town", "goto", "goto5");
			PChar.quest.Install_Voysey_And_Blythe = "1";

			// Artois Voysey and Nigel Blythe quest
			PChar.quest.Story_Artois_Nigel.win_condition.l1 = "location";
			PChar.quest.Story_Artois_Nigel.win_condition.l1.character = PChar.id;
			PChar.quest.Story_Artois_Nigel.win_condition.l1.location = "QC_town";
			PChar.quest.Story_Artois_Nigel.win_condition = "Story_Artois";
			Locations[FindLocation("QC_town")].vcskip = true;
		break;
// <-- KK

		case "Story_Artois":
			if (CheckQuestAttribute("main_line", "ines_info_denied"))
			{
				LAi_QuestDelay("Story_Artois", 4.0);
			}
			else
			{
				PChar.quest.Install_Voysey_And_Blythe.over = "yes"; // KK
				DeleteAttribute(&Locations[FindLocation("QC_Town")],"vcskip"); // NK
				LAi_SetHP(characterFromID("Artois Voysey"), 50.0, 50.0);
				LAi_SetHP(characterFromID("Nigel Blythe"), 50.0, 50.0);
				LAi_SetActorType(CharacterFromID("Artois Voysey"));
				LAi_SetActorType(CharacterFromID("Nigel Blythe"));
				LAi_group_MoveCharacter(CharacterFromID("Artois Voysey"), "Artois");
				LAi_group_MoveCharacter(CharacterFromID("Nigel Blythe"), "Nigel");
				LAi_SetImmortal(CharacterFromID("Nigel Blythe"), true);
				LAi_ActorAttack(characterFromID("Nigel Blythe"), characterFromID("Artois Voysey"), "");
				LAi_ActorAttack(characterFromID("Artois Voysey"), characterFromID("Nigel Blythe"), "");
				LAi_SetCheckMinHP(characterFromID("Artois Voysey"), 0.4*LAi_GetCharacterHP(characterFromID("Artois Voysey")), true, "Story_Artois_2"); // KK
				StartQuestMovie(true, false, true);TrackQuestMovie("start","Story_Artois");
				LAi_SetActorType(pchar);
				LAi_ActorFollow(pchar, characterFromID("Nigel Blythe"), "Story_Artois_2", -1);
			}
		break;

		case "Story_Artois_2":
			LAi_RemoveCheckMinHP(CharacterFromID("Artois Voysey")); // CTM //added here ARF to hunt the "unkillable artois"
			LAi_SetStayType(pchar);
			LAi_type_actor_Reset(characterFromID("Artois Voysey"));
			LAi_type_actor_Reset(characterFromID("Nigel Blythe"));
			LAi_ActorDialog(characterFromID("Nigel Blythe"), pchar, "", -1, -1);
		break;

		case "saving_artois":
// KK -->
			PChar.quest.BlazeKilledFightingWithNigel.win_condition.l1 = "NPC_Death";
			PChar.quest.BlazeKilledFightingWithNigel.win_condition.l1.character = PChar.id;
			PChar.quest.BlazeKilledFightingWithNigel.win_condition = "BlazeKilledFightingWithNigel";
// <-- KK

			EndQuestMovie();TrackQuestMovie("end","saving_artois");
			LAi_SetImmortal(characterFromID("Artois Voysey"), true);	// GR: prevent accidentally killing Artois
			LAi_SetImmortal(characterFromID("Nigel Blythe"), false);
			LAi_SetPlayerType (Pchar);
			LAi_group_MoveCharacter(CharacterFromID("Nigel Blythe"), "nigel_2");
			//LAi_group_MoveCharacter(CharacterFromID("Artois Voysey"), "Artois");
			LAi_group_FightGroups("nigel_2", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("nigel_2", "Artois_saved");
		break;

// KK -->
		case "BlazeKilledFightingWithNigel":
			bSuppressResurrection = true;
			LAi_SetActorType(CharacterFromID("Nigel Blythe"));
			SendMessage(&locCamera, "li", MSG_CAMERA_SETTARGET, CharacterFromID("Nigel Blythe"));
			locCameraFollow();

			SendMessage(&Characters[GetCharacterIndex("Nigel Blythe")],"lsl", MSG_CHARACTER_EX_MSG , "SetFightMode", true);
			LAi_SetImmortal(characterFromID("Artois Voysey"), false);
			LAi_SetImmortal(characterFromID("Nigel Blythe"), false);
			LAi_ActorAnimation(CharacterFromID("Artois Voysey"), "afraid","", 10);
			LAi_ActorAttack(CharacterFromID("Nigel Blythe"), CharacterFromID("Artois Voysey"), "Artois_kill_after_Blaze");
		break;

		case "Artois_kill_after_Blaze":
			LAi_ActorGoToLocation(CharacterFromID("Nigel Blythe"), "reload", "reload1", "none", "", "", "AfterKillingBlazeAndArtois", 100);
		break;

		case "AfterKillingBlazeAndArtois":
			EndQuestMovie();TrackQuestMovie("end","AfterKillingBlazeAndArtois");
			bSuppressResurrection = false;
			PostEvent("LAi_event_GameOver", 0, "s", "land");
		break;
// <-- KK

		case "Artois_saved":
			EndQuestMovie();TrackQuestMovie("end","Artois_saved");
			PChar.quest.BlazeKilledFightingWithNigel.over = "yes"; // KK
			SetQuestHeader("Artois");
			AddQuestRecord("artois", 1);
			LAi_SetActorType(pchar);
			LAi_SetActorType(CharacterFromID("Artois Voysey"));
			LAi_ActorWaitDialog(CharacterFromID("Artois Voysey"), PChar);
			LAi_ActorDialog(PChar, CharacterFromID("Artois Voysey"), "", 2.0, 1.0);
// added by MAXIMUS --> // KK -->
			//characters[GetCharacterIndex("Artois Voysey")].quest.officerprice = makeint((sti(Pchar.rank) * 2 + 10)*100) - 330 + rand(40)*15 + rand(10);
			LAi_NPC_Equip(characterFromID("Artois Voysey"), sti(Pchar.rank), true, 0.5);
// added by MAXIMUS <-- // <-- KK
		break;

		case "Voysey_listed":
			LAi_SetImmortal(characterFromID("Artois Voysey"), false);

			Pchar.quest.Artois_Voysey.win_condition.l1 = "location";
			Pchar.quest.Artois_Voysey.win_condition.l1.character = "Artois Voysey";
			Pchar.quest.Artois_Voysey.win_condition.l1.location = "Conceicao_port";
			PChar.quest.Artois_Voysey.win_condition = "Artois_missed";
//NK --> fix for Artois quest repeating
			pchar.quest.Voysey_lost = "0";
//NK <--

			LAi_SetPlayerType(Pchar);
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Artois Voysey")); // NK was -1
			LAi_SetOfficerType(characterFromID("Artois Voysey"));
			characters[GetCharacterIndex("Artois Voysey")].Dialog.Filename = "Enc_Officer_dialog.c"; // KK
			characters[GetCharacterIndex("Artois Voysey")].Dialog.CurrentNode = "Hired"; // KK

			PChar.quest.Artois_dead.win_condition.l1 = "NPC_Death";
			PChar.quest.Artois_dead.win_condition.l1.character = "Artois Voysey";
			PChar.quest.Artois_dead.win_condition = "Artois_dead";
		break;

		case "Voysey_listed_2":
			LAi_SetImmortal(characterFromID("Artois Voysey"), false);

			LAi_SetPlayerType(PChar);
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Artois Voysey"));
			AddPassenger(PChar, characterFromID("Artois Voysey"), 0);	// GR: make sure he joins you if you have a full set of officers already
			characters[GetCharacterIndex("Artois Voysey")].Dialog.Filename = "Enc_Officer_dialog.c"; // KK
			characters[GetCharacterIndex("Artois Voysey")].Dialog.CurrentNode = "Hired"; // KK

			PChar.quest.Artois_dead.over = "yes";
		break;

		case "Artois_dead":
			Pchar.quest.Artois_Voysey.over = "yes";
			pchar.quest.shoot_in_artois.over = "yes";
			pchar.quest.shoot_in_artois1.over = "yes";
			pchar.quest.shoot_in_artois2.over = "yes";
			pchar.quest.shoot_in_artois3.over = "yes";
			pchar.quest.shoot_in_artois4.over = "yes";
			pchar.quest.shoot_in_artois5.over = "yes";
			AddQuestRecord("artois", 21);
			CloseQuestHeader("Artois");
		break;

		case "Artois_missed":
//NK -->
			if(!CheckAttribute(PChar,"quest.Voysey_lost") || PChar.quest.Voysey_lost != "0") break;
//NK <--
			if(FindFellowTravellers(PChar, CharacterFromId("Artois Voysey")) == FELLOWTRAVEL_OFFICER || FindFellowTravellers(PChar, CharacterFromId("Artois Voysey")) == FELLOWTRAVEL_PASSENGER)
			{
				LAi_LocationMonstersGen(&locations[FindLocation("Conceicao_town_exit")], false);
				pchar.quest.Voysey_lost = "1";
				RemovePassenger(pchar, characterFromID("Artois Voysey"));

				LAi_SetActorType(Pchar);
				Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
				Pchar.dialog.currentnode = "Artois_lost";
				LAi_ActorSelfDialog(Pchar, "player_back");
				AddQuestRecord("artois", 4);
				// KK characters[GetCharacterIndex("Artois Voysey")].location = "Redmond_store";
				ChangeCharacterAddress(characterFromID("Artois Voysey"), "none", "");
			}
		break;

		case "artois_before_room_on_second_floor":
			AddQuestRecord("artois", 5);
			Locations[FindLocation("Conceicao_tavern")].reload.l2.disable = false;
			Pchar.quest.Blaze_arrest.win_condition.l1 = "location";
			Pchar.quest.Blaze_arrest.win_condition.l1.location = "Conceicao_tavern_upstairs";
			PChar.quest.Blaze_arrest.win_condition = "Blaze_arrest";
			pchar.quest.Voysey_lost = "2";
		break;

		case "Blaze_arrest":
			AddQuestRecord("artois", 6);
			Locations[FindLocation("Conceicao_tavern")].reload.l2.disable = true;
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "brodyaga", "goto", "goto4");
			sld.dialog.filename = "anacleto_dialog.c";
			sld.dialog.currentnode = "ask_about_artois";
			LAi_SetActorType(sld);
			LAi_ActorSetLayMode(sld);
			LAi_ActorWaitDialog(sld, pchar);
			LAi_SetActorType(pchar);
			LAi_ActorDialog(pchar, sld, "", 4.0, 1.0);
	  	break;

		case "Blaze_cop_dialog":
			Locations[FindLocation("Conceicao_tavern_upstairs")].reload.l1.disable = true;
			LAi_SetPlayerType(pchar);
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[GetCurrentLocationNation()].fantomModel.m1, "reload", "reload1"); // PB
			sld.Dialog.Filename = "Cops_dialog.c";
			sld.dialog.currentnode = "First time";
			sld.id = "solja";

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[GetCurrentLocationNation()].fantomModel.m1, "reload", "reload1"); // PB
			LAi_SetActorType(sld);
			LAi_ActorFollow (sld, pchar, "", 10);
			sld.id = "solja1";
			LAi_group_MoveCharacter(sld, "CONCEICAO_SOLDIERS");

			LAi_SetActorType(characterfromID("solja"));
			LAi_ActorDialog(characterfromID("solja"), PChar, "", 10, 10);
			LAi_SetPlayerType(Pchar);
		break;

		case "artois_fight_in_tavern_upstairs":
			LAi_SetWarriorType(characterfromID("solja"));
			LAi_SetWarriorType(characterfromID("solja1"));
			LAi_group_MoveCharacter(characterFromID("solja"), "CONCEICAO_SOLDIERS");
			LAi_group_MoveCharacter(characterFromID("solja1"), "CONCEICAO_SOLDIERS");
			LAi_group_SetCheck("CONCEICAO_SOLDIERS", "Open_Locators");
			LAi_group_FightGroups("CONCEICAO_SOLDIERS", LAI_GROUP_PLAYER, true);

			// unneeded if(GetRMRelation(PChar, PORTUGAL) > REL_AFTERATTACK) SetRMRelation(PChar, PORTUGAL, REL_AFTERATTACK); // RM - SetNationRelation2MainCharacter(PORTUGAL, RELATION_ENEMY);
			LeaveService(PChar, PORTUGAL, false); // RM
			AddQuestRecord("artois", 7);
		break;

		case "Open_Locators":
			Locations[FindLocation("Conceicao_tavern_upstairs")].reload.l1.disable = false;

			Pchar.quest.fight.win_condition.l1 = "location";
			Pchar.quest.fight.win_condition.l1.location = "Conceicao_town";
			PChar.quest.fight.win_condition = "Blaze_fight_the_world";

			Pchar.quest.artois_captured.win_condition.l1 = "location";
			Pchar.quest.artois_captured.win_condition.l1.location = "Conceicao_town_exit";
			PChar.quest.artois_captured.win_condition = "artois_captured";
		break;

		case "Blaze_fight_the_world":
			pchar.quest.escape_from_conceicao.win_condition.l1 = "location";
			pchar.quest.escape_from_conceicao.win_condition.l1.location = "conceicao";
			pchar.quest.escape_from_conceicao.win_condition = "escape_from_conceicao";

			Locations[FindLocation("Conceicao_town")].reload.l3.disable = true;

			if (CalcCharacterSkill(pchar, SKILL_SNEAK) < 3)
			{
				/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[PORTUGAL].fantomModel.m1, "goto", "goto3"); // PB
				LAi_SetActorType(sld);
				LAi_group_MoveCharacter(sld, "CONCEICAO_SOLDIERS");

				/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[PORTUGAL].fantomModel.m2, "goto", "goto5"); // PB
				LAi_group_MoveCharacter(sld, "CONCEICAO_SOLDIERS");

				/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[PORTUGAL].fantomModel.m3, "goto", "goto5"); // PB
				LAi_group_MoveCharacter(sld, "CONCEICAO_SOLDIERS");

				/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[PORTUGAL].fantomModel.m4, "goto", "goto3"); // PB
				LAi_group_MoveCharacter(sld, "CONCEICAO_SOLDIERS");

				LAi_group_FightGroups("CONCEICAO_SOLDIERS", LAI_GROUP_PLAYER, true);
			}
		break;

		case "escape_from_conceicao":
			Locations[FindLocation("Conceicao_town")].reload.l3.disable = false;

			PChar.quest.possible_for_resque_artois.win_condition.l1 = "Timer";
			PChar.quest.possible_for_resque_artois.win_condition.l1.date.day = GetAddingDataDay(0,0,4);
			PChar.quest.possible_for_resque_artois.win_condition.l1.date.month = GetAddingDataMonth(0,0,4);
			PChar.quest.possible_for_resque_artois.win_condition.l1.date.year = GetAddingDataYear(0,0,4);
			PChar.quest.possible_for_resque_artois.win_condition = "possible_for_resque_artois";
		break;

		case "possible_for_resque_artois":
			pchar.quest.artois_captured.over = "yes";
			ChangeCharacterAddress(CharacterFromID("Artois Voysey"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Pirates_1"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Pirates_2"), "none", "");
			ChangeCharacterAddress(CharacterFromID("Pirates_3"), "none", "");
			CloseQuestHeader("Artois");
		break;

		case "artois_captured":
			LAi_SetImmortal(characterFromID("Artois Voysey"), true);
			ChangeCharacterAddress(CharacterFromID("Artois Voysey"), "Conceicao_town_exit", "goto14");
			characters[GetCharacterIndex("Artois Voysey")].Dialog.Filename = "Artois Voysey_dialog.c"; // KK
			characters[GetCharacterIndex("Artois Voysey")].dialog.currentnode = "Captured";
			LAi_SetActorType(characterfromID("Artois Voysey"));
			LAi_ActorSetLayMode(characterfromID("Artois Voysey"));
			characters[GetCharacterIndex("Pirates_1")].dialog.filename = "anacleto_dialog.c";
			characters[GetCharacterIndex("Pirates_1")].dialog.currentnode = "artois_lay";
			characters[GetCharacterIndex("Pirates_2")].dialog.filename = "anacleto_dialog.c";
			characters[GetCharacterIndex("Pirates_2")].dialog.currentnode = "artois_lay";
			characters[GetCharacterIndex("Pirates_3")].dialog.filename = "anacleto_dialog.c";
			characters[GetCharacterIndex("Pirates_3")].dialog.currentnode = "artois_lay";
			ChangeCharacterAddress(CharacterFromID("Pirates_1"), "Conceicao_town_exit", "goto8");
			ChangeCharacterAddress(CharacterFromID("Pirates_2"), "Conceicao_town_exit", "goto9");
			ChangeCharacterAddress(CharacterFromID("Pirates_3"), "Conceicao_town_exit", "goto10");
			LAi_SetActorType(CharacterFromID("Pirates_1"));
			LAi_SetActorType(CharacterFromID("Pirates_2"));
			LAi_SetActorType(CharacterFromID("Pirates_3"));
			LAi_ActorFollow(CharacterFromID("Pirates_1"), CharacterFromID("Artois Voysey"), "reset_pirates", 7.0);
			LAi_ActorFollow(CharacterFromID("Pirates_2"), CharacterFromID("Artois Voysey"), "reset_pirates", 7.0);
			LAi_ActorFollow(CharacterFromID("Pirates_3"), CharacterFromID("Artois Voysey"), "reset_pirates", 7.0);
			//LAi_QuestDelay("go_to_artois", 20.0);
			DeleteAttribute(pchar, "quest.voysey_lost");
			LAi_SetHP(CharacterFromID("Pirates_1"), 80.0, 80.0);
			LAi_SetHP(CharacterFromID("Pirates_2"), 80.0, 80.0);
			LAi_SetHP(CharacterFromID("Pirates_3"), 80.0, 80.0);
			LAi_SetCheckMinHP(CharacterFromID("Pirates_1"), LAi_GetCharacterHP(characterFromID("Pirates_1"))-1.0, false, "fight_for_artois_with_child_of_giens"); // KK
			LAi_SetCheckMinHP(CharacterFromID("Pirates_2"), LAi_GetCharacterHP(characterFromID("Pirates_2"))-1.0, false, "fight_for_artois_with_child_of_giens"); // KK
			LAi_SetCheckMinHP(CharacterFromID("Pirates_3"), LAi_GetCharacterHP(characterFromID("Pirates_3"))-1.0, false, "fight_for_artois_with_child_of_giens"); // KK
			Locations[FindLocation("Conceicao_town_exit")].vcskip = true; // PB
		break;

		case "reset_pirates":
			LAi_SetStayType(CharacterFromID("Pirates_1"));
			LAi_SetStayType(CharacterFromID("Pirates_2"));
			LAi_SetStayType(CharacterFromID("Pirates_3"));
			AddQuestRecord("artois", 10);
		break;

		case "fight_for_artois_with_child_of_giens":
			LAi_RemoveCheckMinHP(CharacterFromID("Pirates_1"));
			LAi_RemoveCheckMinHP(CharacterFromID("Pirates_2"));
			LAi_RemoveCheckMinHP(CharacterFromID("Pirates_3"));
			LAi_SetPlayerType(pchar);
			LAi_group_MoveCharacter(characterFromID("Pirates_1"), "CHILD_OF_GIEN");
			LAi_group_MoveCharacter(characterFromID("Pirates_2"), "CHILD_OF_GIEN");
			LAi_group_MoveCharacter(characterFromID("Pirates_3"), "CHILD_OF_GIEN");
			LAi_group_FightGroups("CHILD_OF_GIEN", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("CHILD_OF_GIEN", "Artois_resque_in_jungles");
			pchar.quest.possible_for_resque_artois.over = "yes";
			DeleteAttribute(&Locations[FindLocation("Conceicao_town_exit")],"vcskip"); // PB
		break;

		case "portugal_becomes_neutral":
			if(GetRMRelation(PChar, GetTownNation("Conceicao")) < REL_AMNESTY) SetRMRelation(PChar, GetTownNation("Conceicao"), REL_AMNESTY); // RM - SetNationRelation2MainCharacter(PORTUGAL, RELATION_NEUTRAL);
			LAi_group_SetRelation(GetTownSoldierGroup("Conceicao"), LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
		break;

		case "Artois_resque_in_jungles":
			pchar.quest.artois_line = "resqued";
			LAi_fade("Artois_resque_in_jungles_2", "Artois_resque_in_jungles_3");
		break;

		case "Artois_resque_in_jungles_2":
			LAi_ActorSetStayMode(characterFromID("Artois Voysey"));
			LAi_ActorWaitDialog(characterFromID("Artois Voysey"), pchar);
		break;

		case "Artois_resque_in_jungles_3":
			LAi_SetActorType(pchar);
			LAi_ActorDialog(pchar, characterFromID("Artois Voysey"), "player_back", 5.0, 1.0);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 5000); }
			else { AddPartyExp(pchar, 5000); }
		break;

		case "pause":
			AddQuestRecord("artois", 8);
			Locations[FindLocation("Conceicao_townhall")].reload.l1.disable = 1;
			if(GetDayTime() == DAY_TIME_NIGHT)
			{
				WaitDate("", 0, 0, 1, 0, 0);
				SetCurrentTime(10, 0);
			}
			DoQuestReloadToLocation ("Conceicao_townhall", "goto", "goto7", "pause2");
		break;

		case "pause2":
			Locations[FindLocation("Conceicao_tavern_upstairs")].reload.l1.disable = false;
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[PORTUGAL].fantomModel.m5, "goto", "goto8"); // PB
			LAi_SetActorType(sld);

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[PORTUGAL].fantomModel.m1, "goto", "goto1"); // PB
			LAi_SetActorType(sld);
			sld.id = "guard";

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "man6", "goto", "goto2");
			LAi_SetActorType(sld);
			sld.id = "witness";
			sld.Dialog.Filename = "witness-dialog.c";
			LAi_SetActorType(CharacterFromID("Jacinto Arcibaldo Barreto"));
			LAi_ActorSetSitMode(CharacterFromID("Jacinto Arcibaldo Barreto"));
			characters[GetCharacterIndex("Jacinto Arcibaldo Barreto")].dialog.currentnode = "j_day";
			LAi_ActorDialog(characterfromID("Jacinto Arcibaldo Barreto"), PChar, "", 2.0, 1.0);
		break;

		case "ex_dialog":
			LAi_ActorDialog(characterfromID("witness"), PChar, "", 1.0, 1.0);
			LAi_ActorGoToLocator(CharacterFromID("guard"), "goto", "goto9", "ex_dialog2_3", 3.0);
		break;

		case "ex_dialog2_3":
			//LAi_SetActorType(characterfromID("Jacinto Arcibaldo Barreto"));
			LAi_ActorWaitDialog(characterfromID("Jacinto Arcibaldo Barreto"), characterfromID("guard"));
			LAi_ActorDialog(characterfromID("guard"), characterfromID("Jacinto Arcibaldo Barreto"), "ex_dialog2_4", 1.0, 2.0);
		break;

		case "ex_dialog2_4":
			LAi_ActorGoToLocator(CharacterFromID("guard"), "goto", "goto1", "ex_dialog2_5", 3.0);
		break;

		case "ex_dialog2_5":
			LAi_ActorDialog(characterfromID("Jacinto Arcibaldo Barreto"), PChar, "acrcibaldo_back_to_hub_type", 1.0, 1.0);
			Pchar.quest.artois_captured.win_condition.l1 = "location";
			Pchar.quest.artois_captured.win_condition.l1.location = "Conceicao_town_exit";
			PChar.quest.artois_captured.win_condition = "artois_captured";

			PChar.quest.possible_for_resque_artois.win_condition.l1 = "Timer";
			PChar.quest.possible_for_resque_artois.win_condition.l1.date.day = GetAddingDataDay(0,0,4);
			PChar.quest.possible_for_resque_artois.win_condition.l1.date.month = GetAddingDataMonth(0,0,4);
			PChar.quest.possible_for_resque_artois.win_condition.l1.date.year = GetAddingDataYear(0,0,4);
			PChar.quest.possible_for_resque_artois.win_condition = "possible_for_resque_artois";
			AddQuestRecord("artois", 9);
		break;

		case "acrcibaldo_back_to_hub_type":
			Locations[FindLocation("Conceicao_townhall")].reload.l1.disable = 0;
			LAi_SetHuberType(characterfromID("Jacinto Arcibaldo Barreto"));
		break;

		case "prepare_shoot_in_artois":
			LAi_SetImmortal(characterFromID("Artois Voysey"), false);

			LAi_SetPlayerType(Pchar);
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Artois Voysey")); // NK was -1

			Officersreaction("good");
			pchar.quest.shoot_in_artois.win_condition.l1 = "location";
			pchar.quest.shoot_in_artois.win_condition.l1.location = "QC_port";
			pchar.quest.shoot_in_artois.win_condition = "shoot_in_artois";

			pchar.quest.shoot_in_artois1.win_condition.l1 = "location";
			pchar.quest.shoot_in_artois1.win_condition.l1.location = "Redmond_port";
			pchar.quest.shoot_in_artois1.win_condition = "shoot_in_artois";

			pchar.quest.shoot_in_artois2.win_condition.l1 = "location";
			pchar.quest.shoot_in_artois2.win_condition.l1.location = "Greenford_port";
			pchar.quest.shoot_in_artois2.win_condition = "shoot_in_artois";

			if (pchar.location != "Oxbay_port" && !CheckAttribute(PChar, "Quest.Story_OxbayCaptured"))
			{
				pchar.quest.shoot_in_artois3.win_condition.l1 = "location";
				pchar.quest.shoot_in_artois3.win_condition.l1.location = "Oxbay_port";
				pchar.quest.shoot_in_artois3.win_condition = "shoot_in_artois";
			}

			pchar.quest.shoot_in_artois4.win_condition.l1 = "location";
			pchar.quest.shoot_in_artois4.win_condition.l1.location = "Douwesen_port";
			pchar.quest.shoot_in_artois4.win_condition = "shoot_in_artois";

			pchar.quest.shoot_in_artois5.win_condition.l1 = "location";
			pchar.quest.shoot_in_artois5.win_condition.l1.location = "Muelle_port";
			pchar.quest.shoot_in_artois5.win_condition = "shoot_in_artois";

			characters[GetCharacterIndex("Artois Voysey")].dialog.currentnode = "officer_Artois"; // PB
		break;

		case "shoot_in_artois":
			if (!checkquestattribute("generate_convoy_quest_progress", "begin") && !checkquestattribute("generate_convoy_quest_progress", "completed")) {
// KK -->
				for (cidx = 1; cidx < 4; cidx++)
				{
					iPassenger = GetOfficersIndex(Pchar, cidx);
					if (iPassenger > 0 && Characters[iPassenger].id == "Artois Voysey")
						pchar.quest.shoot_in_artois_complete = "complete";
				}
// <-- KK
				if (CheckQuestAttribute("shoot_in_artois_complete", "complete"))
				{
					pchar.quest.shoot_in_artois.over = "yes";
					pchar.quest.shoot_in_artois1.over = "yes";
					pchar.quest.shoot_in_artois2.over = "yes";
					pchar.quest.shoot_in_artois3.over = "yes";
					pchar.quest.shoot_in_artois4.over = "yes";
					pchar.quest.shoot_in_artois5.over = "yes";

					GetCharacterPos(pchar, &locx, &locy, &locz);
					homelocator = LAi_FindFarLocator("goto", locx, locy, locz);
					/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "corsair1", "goto", homelocator);
					sld.id = "gunman";

					LAi_QuestDelay("shooting_in_artois_begin", 2.0);
					pchar.quest.location = pchar.location;
					pchar.quest.locator = pchar.location.locator;
				}
				else
				{
					pchar.quest.shoot_in_artois.win_condition.l1 = "location";
					pchar.quest.shoot_in_artois.win_condition.l1.location = "QC_port";
					pchar.quest.shoot_in_artois.win_condition = "shoot_in_artois";

					pchar.quest.shoot_in_artois1.win_condition.l1 = "location";
					pchar.quest.shoot_in_artois1.win_condition.l1.location = "Redmond_port";
					pchar.quest.shoot_in_artois1.win_condition = "shoot_in_artois";

					pchar.quest.shoot_in_artois2.win_condition.l1 = "location";
					pchar.quest.shoot_in_artois2.win_condition.l1.location = "Greenford_port";
					pchar.quest.shoot_in_artois2.win_condition = "shoot_in_artois";

					pchar.quest.shoot_in_artois3.win_condition.l1 = "location";
					pchar.quest.shoot_in_artois3.win_condition.l1.location = "Oxbay_port";
					pchar.quest.shoot_in_artois3.win_condition = "shoot_in_artois";

					pchar.quest.shoot_in_artois4.win_condition.l1 = "location";
					pchar.quest.shoot_in_artois4.win_condition.l1.location = "Douwesen_port";
					pchar.quest.shoot_in_artois4.win_condition = "shoot_in_artois";

					pchar.quest.shoot_in_artois5.win_condition.l1 = "location";
					pchar.quest.shoot_in_artois5.win_condition.l1.location = "Muelle_port";
					pchar.quest.shoot_in_artois5.win_condition = "shoot_in_artois";
				}
			}
			else
			{
				LAi_QuestDelay("shoot_in_artois", 3.0);
			}
		break;

		case "shooting_in_artois_begin":
			GetCharacterPos(PChar, &locx, &locy, &locz);
			homelocator = LAi_FindFarLocator("goto", locx, locy, locz);
			homelocation = pchar.location;
			CreateParticleSystemOnLocator(homelocation, homelocator, "gunfire");
			LAi_SetActorType(characterFromID("Artois Voysey"));
			LAi_ActorAnimation(characterFromID("Artois Voysey"), "death_1", "almost_killed_artois", 4.0);
			Play3DSound("pistol_shot_original", locx, locy, locz);	// LDH 23Mar09	// was "pistol_shot" but that just goes "click"
		break;

		case "almost_killed_artois":
			GetCharacterPos(PChar, &locx, &locy, &locz);
			homelocator = LAi_FindFarLocator("reload", locx, locy, locz);
			LAi_SetActorType(characterFromID("gunman"));
			LAi_ActorRunToLocation(characterFromID("gunman"), "reload", homelocator, "none", "", "", "", 10.0);
			LAi_ActorAnimation(characterFromID("Artois Voysey"), "lay_2", "", 4.0);
			LAi_SetActorType(Pchar);
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			Pchar.dialog.currentnode = "artois_shooted";
			LAi_ActorSelfDialog(Pchar, "player_back");
			AddQuestRecord("artois", 14);
		break;

		case "to_tavern_with_almost_dead_artois":
			RemoveOfficersIndex(pchar, GetCharacterIndex("Artois Voysey"));
			RemovePassenger(pchar, characterFromID("Artois Voysey"));
			ChangeCharacterAddress(characterFromID("Artois Voysey"), "none", "");
			DoQuestReloadToLocation("Muelle_tavern_upstairs", "goto", "goto2", "talk_with_doctor");
		break;

		case "talk_with_doctor":
			GetCharacterPos(PChar, &locx, &locy, &locz);
			homelocator = LAi_FindNearestFreeLocator("goto", locx, locy, locz);
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "fatman2", "goto", homelocator);
			sld.id = "doctor";
			sld.dialog.filename = "anacleto_dialog.c";
			sld.dialog.currentnode = "doctor";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, pchar, "", 2.0, 1.0);
			LAi_SetStayType(pchar);
		break;

		case "exit_doctor_bad":
			AddQuestRecord("artois", 15);
			CloseQuestHeader("artois");
			homelocation = pchar.quest.location;
			homelocator = pchar.quest.locator;
			DoQuestReloadToLocation(homelocation, "reload", homelocator, "player_back");
			Officersreaction("bad");
			ChangeCharacterReputation(pchar, -2);
		break;

		case "exit_doctor_good":
//			environment.date.day = GetAddingDataDay(0,0,14);	// GR: this does not change the date on the worldmap so going
//			environment.date.month = GetAddingDataMonth(0,0,14);	//     to worldmap puts the date back before the 14 day wait
//			environment.date.year = GetAddingDataYear(0,0,14);
			AddDataToCurrent(0, 0, 14, false);			// GR: use proper function.  Updates disabled so the crew doesn't starve
			AddQuestRecord("artois", 16);
			homelocation = pchar.quest.location;
			homelocator = pchar.quest.locator;
			DoQuestReloadToLocation(homelocation, "reload", homelocator, "final_talk_with_artois");
			Officersreaction("good");
			ChangeCharacterReputation(pchar, 2);
		break;

		case "final_talk_with_artois":
			LAi_SetPlayerType(pchar);
			PlaceCharacter(characterFromID("Artois Voysey"), "goto");
			LAi_SetActorType(characterFromID("Artois Voysey"));
			LAi_type_actor_Reset(characterFromID("Artois Voysey"));
			Characters[GetCharacterIndex("Artois Voysey")].dialog.currentnode = "Artois Voysey_dialog.c"; // PB
			Characters[GetCharacterIndex("Artois Voysey")].dialog.currentnode = "final_talk";
			LAi_ActorDialog(characterFromID("Artois Voysey"), pchar, "Voysey_listed_2", 3.0, 1.0);

			pchar.quest.treasure_found.win_condition.l1 = "locator";
			pchar.quest.treasure_found.win_condition.l1.location = "Douwesen_Shore_ship";
			pchar.quest.treasure_found.win_condition.l1.locator_group = "randitem";
			pchar.quest.treasure_found.win_condition.l1.locator = "randitem1";
			pchar.quest.treasure_found.win_condition = "treasure_found";
			AddQuestRecord("artois", 17);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 5000); }
			else { AddPartyExp(pchar, 5000); }
			//AddPassenger(Pchar, characterFromID("Artois Voysey"), 0);
		break;

		case "treasure_found":
			AddMoneyToCharacter(PChar, 50000);
			Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE4"));
			AddQuestRecord("artois", 18);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 15000); }
			else { AddPartyExp(pchar, 15000); }
			if (CheckQuestAttribute("artois_line", "completed"))
			{
				PChar.quest.Wait_For_donate.win_condition.l1 = "Timer";
				PChar.quest.Wait_For_donate.win_condition.l1.date.day = GetAddingDataDay(0,1,0);
				PChar.quest.Wait_For_donate.win_condition.l1.date.month = GetAddingDataMonth(0,1,0);
				PChar.quest.Wait_For_donate.win_condition.l1.date.year = GetAddingDataYear(0,1,0);
				PChar.quest.Wait_For_donate.win_condition = "Wait_For_donate";
				pchar.quest.artois_line = "found_gold";
			}
			else
			{
				CloseQuestHeader("artois");
			}
		break;

		case "Wait_For_donate":
			OfficersReaction("bad");
			ChangeCharacterReputation(pchar, -2);
			pchar.quest.artois_line = "final_state";
			AddQuestRecord("artois", 20);
			CloseQuestHeader("artois");
		break;

		case "artois_donate_done":
			pchar.quest.Wait_For_donate.over = "yes";
			OfficersReaction("good");
			ChangeCharacterReputation(pchar, 4);
			AddMoneyToCharacter(PChar, -4000);
			AddQuestRecord("artois", 19);
			CloseQuestHeader("artois");
			DeleteQuestAttribute("artois_line"); // NK
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 7000); }
			else { AddPartyExp(pchar, 7000); }
		break;

	//Nigel Blythe
		case "voysey_No_Fight":
			LAi_ActorAttack(CharacterFromID("Pirates_1"), CharacterFromID("Artois Voysey"), "");
		break;

		case "voysey_Fight":
			LAi_ActorAttack(CharacterFromID("Pirates_1"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Pirates_2"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Pirates_3"), PChar, "");
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l1 = "NPC_Death";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l1.character = "Pirates_1";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l2 = "NPC_Death";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l2.character = "Pirates_2";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l3 = "NPC_Death";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l3.character = "Pirates_3";
			PChar.quest.Story_KillNygelBlythe4.win_condition = "Voysey_death";
		break;

		case "voysey_found_treasure":
			pchar.quest.treasure_found.win_condition.l1 = "locator";
			pchar.quest.treasure_found.win_condition.l1.location = "Douwesen_Shore_ship";
			pchar.quest.treasure_found.win_condition.l1.locator_group = "randitem";
			pchar.quest.treasure_found.win_condition.l1.locator = "randitem1";
			pchar.quest.treasure_found.win_condition = "treasure_found";
		break;

		case "Leave_Voysey":
			LAi_SetPlayerType(PChar);
			LAi_SetCitizenType(CharacterFromID("Artois Voysey"));
		break;

		case "Leave_Nigel":
			AddQuestRecord("nigel", 3);
			//CloseQuestHeader("nigel");
			LAi_SetPlayerType(PChar);
			LAi_SetCitizenType(CharacterFromID("Nigel Blythe"));
		break;

		case "change_Maxwell_adress":
			AddQuestrecord("nigel", 24);
			characters[GetCharacterIndex("Friedrich Maxwell")].Dialog.Filename = "Maxwell_dialog.c";
			Pchar.quest.Nigel_Blythe6.win_condition.l1 = "location";
			Pchar.quest.Nigel_Blythe6.win_condition.l1.location = "QC_tavern";
			Pchar.quest.Nigel_Blythe6.win_condition = "Maxwell_talk";
		break;

		case "voysey_final_nofight":
			LAi_ActorAttack(CharacterFromID("Pirates_1"), CharacterFromID("Artois Voysey"), "");
		break;

		case "voysey_final_fight":
			LAi_ActorAttack(CharacterFromID("Pirates_1"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Pirates_2"), PChar, "");
			LAi_ActorAttack(CharacterFromID("Pirates_3"), PChar, "");
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l1 = "NPC_Death";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l1.character = "Pirates_1";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l2 = "NPC_Death";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l2.character = "Pirates_2";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l3 = "NPC_Death";
			Pchar.quest.Story_KillNygelBlythe4.win_condition.l3.character = "Pirates_3";
			PChar.quest.Story_KillNygelBlythe4.win_condition = "Voysey_death";
		break;

		case "change_clauss_adress":
			AddMoneyToCharacter(Pchar, -5000);
			SetCharacterToNearLocatorFromMe("Florens Clauss", 3);
			ChangeCharacterAddressGroup(CharacterFromID("Friedrich Maxwell"), "", "sit", "sit12");
		break;

		case "Artois_kill":
			SetQuestHeader("nigel");
			AddQuestRecord("nigel", 1);
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(CharacterFromID("Nigel Blythe"));
			LAi_ActorDialog(CharacterFromID("Nigel Blythe"), PChar, "", 2.0, 1.0);
			EndQuestMovie();TrackQuestMovie("end","Artois_kill");
		break;

		case "Artois_Blythe":
			SendMessage(&Characters[GetCharacterIndex("Nigel Blythe")],"lsl", MSG_CHARACTER_EX_MSG , "SetFightMode", true);
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(CharacterFromID("Nigel Blythe"), PChar);
			LAi_ActorDialog(PChar, CharacterFromID("Nigel Blythe"), "", 10, 10);
		break;

		case "killing_artois":
			//LAi_RemoveCheckMinHP(CharacterFromID("Artois Voysey")); // CTM // ARF moved to case "Story_Artois_2"
			LAi_SetImmortal(characterFromID("Artois Voysey"), false);
			LAi_SetImmortal(characterFromID("Nigel Blythe"), false);
			LAi_SetActorType(pchar);
			LAi_ActorTurnToCharacter(pchar, characterFromID("Nigel Blythe"));
			LAi_ActorAnimation(CharacterFromID("Artois Voysey"), "afraid","", 10);
			LAi_ActorAttack(CharacterFromID("Nigel Blythe"), CharacterFromID("Artois Voysey"), "Artois_kill");
		break;

		case "Nigel_Adventure":
			if (!LAi_IsDead(characterFromID("Nigel Blythe"))) // Levis: 16-10-13 Oxbay capture removed as requirement
			{
				if(FindFellowTravellers(PChar, CharacterFromID("Nigel Blythe")) == FELLOWTRAVEL_PASSENGER || FindFellowTravellers(PChar, CharacterFromID("Nigel Blythe")) == FELLOWTRAVEL_OFFICER)
				{
					AddQuestRecord("nigel", 4);
					Pchar.quest.Nigel_Blythe1.win_condition.l1 = "location";
					Pchar.quest.Nigel_Blythe1.win_condition.l1.location = "Redmond_tavern";	//Petros ... was Oxbay_Tavern
					Pchar.quest.Nigel_Blythe1.win_condition = "Blythe_Setup";
					pchar.quest.Nigel_lost = "1";

					LAi_SetActorType(Pchar);
					Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
					Pchar.dialog.currentnode = "nigel_lost";
					LAi_ActorSelfDialog(Pchar, "player_back");
					RemoveOfficersIndex(pchar, GetCharacterIndex("Nigel Blythe"));
					RemovePassenger(pchar, characterFromID("Nigel Blythe"));
					LAi_SetActorType(CharacterFromID("Nigel Blythe"));
					LAi_SetSitType(CharacterFromID("Nigel Blythe"));
					ChangeCharacterAddressGroup(CharacterFromID("Nigel Blythe"), "Redmond_tavern", "sit", "sit8");	// Petros ... was Oxbay_Tavern
				}
			}
		break;

		case "Nigel_Adventure_Conc":
			if (!CharacterIsDead(&characters[GetCharacterIndex("Nigel Blythe")]))
			{
				if(FindFellowTravellers(PChar, CharacterFromId("Nigel Blythe")) == FELLOWTRAVEL_PASSENGER || FindFellowTravellers(PChar, CharacterFromId("Nigel Blythe")) == FELLOWTRAVEL_OFFICER)
				{
					AddQuestRecord("nigel", 10);
					Pchar.quest.Nigel_Blythe5.win_condition.l1 = "location";
					Pchar.quest.Nigel_Blythe5.win_condition.l1.location = "Conceicao_Tavern";
					Pchar.quest.Nigel_Blythe5.win_condition = "Blythe_Setup_Conc";
					pchar.quest.Nigel_lost = "1";

					LAi_SetActorType(Pchar);
					Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
					Pchar.dialog.currentnode = "nigel_lost";
					LAi_ActorSelfDialog(Pchar, "player_back");
					RemoveOfficersIndex(pchar, GetCharacterIndex("Nigel Blythe"));
					RemovePassenger(pchar, characterFromID("Nigel Blythe"));
					LAi_SetSitType(CharacterFromID("Nigel Blythe"));
					ChangeCharacterAddressGroup(CharacterFromID("Nigel Blythe"), "Conceicao_tavern", "sit", "sit4"); //skull
				}
			}
		break;

		case "Blythe_Setup":
			characters[GetCharacterIndex("Nigel Blythe")].dialog.currentnode = "Setup1";
			pchar.quest.Nigel_lost = "0";
			LAi_QuestDelay("learn about smugglers", 0.0);
		break;

		case "Blythe_Setup_Conc":
			characters[GetCharacterIndex("Nigel Blythe")].dialog.currentnode = "Setup2";
			pchar.quest.Nigel_lost = "0";
		break;

		case "Blythe_Battle":
			if (characters[GetCharacterIndex("Nigel Blythe")].ship.type != SHIP_NOTUSED_TYPE_NAME && (FindFellowTravellers(PChar, CharacterFromId("Nigel Blythe")) == FELLOWTRAVEL_COMPANION)) // PS
			{
				RemoveCharacterCompanion(PChar, characterFromID("Nigel Blythe"));
				SetCharacterRemovable(CharacterFromID("Nigel Blythe"), true); // NK
				LAi_group_MoveCharacter(CharacterFromID("Nigel Blythe"), "SPAIN_CITIZENS");	// GR: necessary to prevent CTD due to Blythe being in LAI_GROUP_PLAYER

				AddQuestrecord("nigel", 16);
				bQuestDisableMapEnter = true;
				Island_SetReloadEnableGlobal(PChar.location, false);
				PChar.quest.blythebattlelockedisland = PChar.location;// TIH store what island was locked Oct31'06

				Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE5"));

				SetCharacterRelationBoth(GetCharacterIndex("Nigel Blythe"),GetMainCharacterIndex(),RELATION_FRIEND);
				SetCharacterRelationBoth(GetCharacterIndex("Nigel Blythe"),GetCharacterIndex("Pirates_7"),RELATION_ENEMY);

				Group_CreateGroup("Nigel Blythe");
				Group_AddCharacter("Nigel Blythe", "Nigel Blythe");				// GR: if Blythe is in LAI_GROUP_PLAYER, this fails
				Group_SetGroupCommander("Nigel Blythe", "Nigel Blythe");
				Group_SetTaskAttack("Nigel Blythe", "Smugglers_corvette", true);
				Group_SetPursuitGroup("Nigel Blythe", PLAYER_GROUP);
				Group_SetAddress("Nigel Blythe", "Douwesen", "quest_ships", "quest_ship_2");
				Group_LockTask("Nigel Blythe");

				Group_CreateGroup("Smugglers_corvette");
				Group_AddCharacter("Smugglers_corvette", "Pirates_7");
				Group_SetGroupCommander("Smugglers_corvette", "Pirates_7");
				Group_SetTaskAttack("Smugglers_corvette", "Nigel Blythe", true);
				Group_LockTask("Smugglers_corvette");
				Group_SetPursuitGroup("Smugglers_corvette", PLAYER_GROUP);
				Group_SetAddress("Smugglers_corvette", "Douwesen", "quest_ships", "quest_ship_1");


				Pchar.quest.Battle.win_condition.l1 = "NPC_Death";
				Pchar.quest.Battle.win_condition.l1.character = "Pirates_7";
				PChar.quest.Battle.win_condition = "Finish_battle";

				Pchar.quest.Battle1.win_condition.l1 = "NPC_Death";
				Pchar.quest.Battle1.win_condition.l1.character = "Nigel Blythe";
				PChar.quest.Battle1.win_condition = "Finish_battle";
			}
			else
			{
				Pchar.quest.Nigel_Blythe_third_encounter_recharge.win_condition.l1 = "ExitFromLocation";
				Pchar.quest.Nigel_Blythe_third_encounter_recharge.win_condition.l1.location = "Douwesen";
				Pchar.quest.Nigel_Blythe_third_encounter_recharge.win_condition = "Nigel_Blythe_third_encounter_recharge";
			}
		break;

		case "Nigel_Blythe_third_encounter_recharge":
			Pchar.quest.Nigel_Blythe6.win_condition.l1 = "location";
			Pchar.quest.Nigel_Blythe6.win_condition.l1.location = "Douwesen";
			Pchar.quest.Nigel_Blythe6.win_condition = "Blythe_Battle";
		break;

		case "Finish_battle":
			bQuestDisableMapEnter = false;
			// TIH --> have it open up the island it locked before or open where the player currently is Oct31'06
			if (CheckAttribute(PChar, "quest.blythebattlelockedisland"))
				{ Island_SetReloadEnableGlobal(PChar.quest.blythebattlelockedisland, true); DeleteAttribute(PChar,"quest.blythebattlelockedisland"); }
			else
				{ Island_SetReloadEnableGlobal(PChar.location, true); }
			//Island_SetReloadEnableGlobal(PChar.location, true);
			// TIH <--

			if (!LAi_IsDead(characterFromID("Nigel Blythe")))
			{
				//SetCompanionIndex(Pchar, -1, GetCharacterIndex("Nigel Blythe"));
				Pchar.quest.Battle2.win_condition.l1 = "location";
				Pchar.quest.Battle2.win_condition.l1.location = "Douwesen_port";
				Pchar.quest.Battle2.win_condition = "Smugglers_vs_Blythe";
				AddQuestrecord("nigel", 18);
			}
			else
			{
				bQuestDisableMapEnter = false;
				AddQuestrecord("nigel", 17);
	  			CloseQuestHeader("nigel");
			}
			pchar.quest.Battle.over = "yes";
			pchar.quest.Battle1.over = "yes";
		break;

		case "Smugglers_vs_Blythe":
			pchar.quest.Battle1.over = "yes";
			//RemoveCharacterCompanion(Pchar, characterFromID("Nigel Blythe"));
			ChangeCharacterAddress(CharacterFromID("Nigel Blythe"), "Douwesen_port", "goto1");
			LAi_SetActorType(characterFromID("nigel blythe"));

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "corsair1", "goto", "goto2");
			LAi_SetActorType(sld);
			sld.id = "offended_sm1";

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "corsair1_1", "goto", "goto1");
			LAi_SetActorType(sld);
			sld.id = "offended_sm";
			sld.Dialog.Filename = "Smugglers_vs_Blythe.c";

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "corsair1_2", "goto", "goto3");
			LAi_SetActorType(sld);
			sld.id = "offended_sm2";

			LAi_ActorDialog(CharacterFromID("offended_sm"), PChar, "", 10.0, 1.0);
			LAi_ActorFollow(CharacterFromID("offended_sm1"), pchar, "", 5.0);
			LAi_ActorFollow(CharacterFromID("offended_sm2"), pchar, "", 5.0);
	  break;

	  case "nigel_answer_to_smuggler":
	  	LAi_SetActorType(characterFromID("Nigel Blythe"));
	  	characters[GetCharacterIndex("Nigel Blythe")].dialog.currentnode = "smugglers";
	  	LAi_ActorDialog(characterFromID("Nigel Blythe"), pchar, "", 1.0, 1.0);
	  break;

	  case "nigel_smugglers_fight_prepare":
	  	characters[GetCharacterIndex("offended_sm")].dialog.currentnode = "nigel_fight";
	  	LAi_ActorDialog(characterFromID("offended_sm"), pchar, "", 1.0, 1.0);
	  break;

	  case "nigel_fight_with_smugglers":
	  	OfficersReaction("bad");
	  	RemoveCharacterCompanion(Pchar, characterFromID("Nigel Blythe"));
		SetCharacterRemovable(characterFromID("Nigel Blythe"), true); // NK
		RemoveOfficersIndex(pchar, GetCharacterIndex("Nigel Blythe"));
	  	LAi_ActorAttack(characterFromID("offended_sm"), characterFromID("nigel blythe"), "");
	  	LAi_ActorAttack(characterFromID("offended_sm1"), characterFromID("nigel blythe"), "");
	  	LAi_ActorAttack(characterFromID("offended_sm2"), characterFromID("nigel blythe"), "");
	 	LAi_ActorAttack(characterFromID("nigel blythe"), characterFromID("offended_sm"), "");
	 	LAi_group_MoveCharacter(characterFromID("offended_sm"), "SMUGGLERS_IN_CONCEICAO_PORT");
	  	LAi_group_MoveCharacter(characterFromID("offended_sm1"), "SMUGGLERS_IN_CONCEICAO_PORT");
	  	LAi_group_MoveCharacter(characterFromID("offended_sm2"), "SMUGGLERS_IN_CONCEICAO_PORT");
	  	LAi_group_MoveCharacter(characterFromID("Nigel Blythe"), "NIGEL");
	 	LAi_QuestDelay("nigel_killed", 1.0);
	  break;

	  case "nigel_killed":
	  	LAi_KillCharacter(characterFromID("nigel blythe"));
	  	Characters[GetCharacterIndex("Nigel Blythe")].location = "none";
	  	AddQuestrecord("nigel", 20);
	  	CloseQuestHeader("nigel");
	break;

	case "we_and_nigel_fight_with_smugglers":
		ChangeSmugglerLiking(pchar,-10);
		LAi_group_MoveCharacter(characterFromID("offended_sm"), "SMUGGLERS_IN_CONCEICAO_PORT");
	  	LAi_group_MoveCharacter(characterFromID("offended_sm1"), "SMUGGLERS_IN_CONCEICAO_PORT");
	  	LAi_group_MoveCharacter(characterFromID("offended_sm2"), "SMUGGLERS_IN_CONCEICAO_PORT");

	  	LAi_group_MoveCharacter(characterFromID("Nigel Blythe"), LAI_GROUP_PLAYER);

	  	LAi_group_FightGroups("SMUGGLERS_IN_CONCEICAO_PORT", LAI_GROUP_PLAYER, true);
	  	LAi_group_SetCheck("SMUGGLERS_IN_CONCEICAO_PORT", "nigel_after_fight_with_smugglers_in_conceicao_port");
	break;

	case "nigel_after_fight_with_smugglers_in_conceicao_port":
		if (!LAi_IsDead(characterFromID("Nigel Blythe")))
	  	{
	  		LAi_SetActorType(characterFromID("Nigel Blythe"));
	  		characters[GetCharacterIndex("Nigel Blythe")].dialog.currentnode = "smugglers_thanks";
	  		LAi_ActorDialog(characterFromID("Nigel Blythe"), pchar, "", 1.0, 1.0);
			ChangeSmugglerLiking(pchar, -20); //Smugglers like you less cause you killed some
	  	}
	  	else
	  	{
	  		AddQuestrecord("nigel", 20);
	  		CloseQuestHeader("nigel");
	  	}
	  	AddQuestrecord("nigel", 19);
	break;

	  	case "we_and_nigel_smugglers_fight_prepare":
	  		characters[GetCharacterIndex("offended_sm")].dialog.currentnode = "we_and_nigel_fight";
	  		LAi_ActorDialog(characterFromID("offended_sm"), pchar, "", 1.0, 1.0);
	  	break;


		case "Blythe_gone_ship":
			if ((GetCharacterShipClass(CharacterFromID("Nigel Blythe")) < 7) && (GetCharacterShipClass(CharacterFromID("Nigel Blythe")) != -1)) // CTM
			{
				AddQuestrecord("nigel", 21);
				RemoveCharacterCompanion(Pchar, &Characters[GetCharacterIndex("Nigel Blythe")]);
				RemoveOfficersIndex(pchar, GetCharacterIndex("Nigel Blythe"));

				//characters[GetCharacterIndex("Claudio Murena")].Dialog.Filename = "Murena_dialog.c";
				//ChangeCharacterAddressGroup(CharacterFromID("Claudio Murena"), "Muelle_tavern", "sit", "sit13");
				//LAi_SetSitType(CharacterFromID("Claudio Murena"));
				characters[GetCharacterIndex("Ermegildo Caminero")].Dialog.Filename = "Caminero_dialog.c";
				pchar.quest.nigel_away_for_ship = "begin";
				Log_SetStringToLog(GlobalStringConvert("QUEST_MESSAGE6"));
				Pchar.quest.Nigel_Blythe1.win_condition.l1 = "location";
				Pchar.quest.Nigel_Blythe1.win_condition.l1.location = "Muelle_port";
				Pchar.quest.Nigel_Blythe1.win_condition = "Muelle_Blythe";
			}
			else
			{
				Pchar.quest.Nigel_Blythe_fourth_encounter_recharge.win_condition.l1 = "ExitFromLocation";
				Pchar.quest.Nigel_Blythe_fourth_encounter_recharge.win_condition.l1.location = "IslaMuelle";
				Pchar.quest.Nigel_Blythe_fourth_encounter_recharge.win_condition = "nigel_fourth_encounter";
			}
		break;

		case "Muelle_Blythe":
			if ((GetOfficersIndex(Pchar, 1) == -1) && (GetOfficersIndex(Pchar, 2) == -1) && (GetOfficersIndex(Pchar, 3) == -1))
			{
				/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "corsair2", "goto", "goto10");
				LAi_SetActorType(sld);
				sld.id = "offended_sm3";
				sld.id = "to_say";
				sld.Dialog.Filename = "to_say.c";

				LAi_ActorDialog(characterfromID("to_say"), pchar, "", 10.0, 10.0);
			}
			if (GetOfficersIndex(Pchar, 1) != -1)
			{
				sld = &Characters[GetOfficersIndex(Pchar, 1)];
				Pchar.Temp.Officer.dialog = sld.Dialog.Filename;
				Pchar.Temp.Officer.dialognode = characters[GetOfficersIndex(Pchar, 1)].dialog.currentnode;
				sld.Dialog.Filename = "to_say.c";
				characters[GetOfficersIndex(Pchar, 1)].dialog.currentnode = "First time";
				LAi_SetActorType(sld);
				LAi_ActorDialog(&Characters[GetOfficersIndex(Pchar, 1)], pchar, "", 10.0, 10.0);
				LAi_QuestDelay("Muelle_Blythe2", 10.0);
			}
			else
			{
				if (GetOfficersIndex(Pchar, 2) != -1)
				{
					sld = &Characters[GetOfficersIndex(Pchar, 2)];
					Pchar.Temp.Officer.dialog = sld.Dialog.Filename;
					Pchar.Temp.Officer.dialognode = characters[GetOfficersIndex(Pchar, 2)].dialog.currentnode;
					sld.Dialog.Filename = "to_say.c";
					characters[GetOfficersIndex(Pchar, 2)].dialog.currentnode = "First time";
					LAi_SetActorType(sld);
					LAi_ActorDialog(&Characters[GetOfficersIndex(Pchar, 2)], pchar, "", 10.0, 10.0);
					LAi_QuestDelay("Muelle_Blythe3", 4.0);
				}
				else
				{
					if (GetOfficersIndex(Pchar, 3) != -1)
					{
						sld = &Characters[GetOfficersIndex(Pchar, 3)];
						Pchar.Temp.Officer.dialog = sld.Dialog.Filename;
						Pchar.Temp.Officer.dialognode = characters[GetOfficersIndex(Pchar, 3)].dialog.currentnode;
						sld.Dialog.Filename = "to_say.c";
						characters[GetOfficersIndex(Pchar, 3)].dialog.currentnode = "First time";
						LAi_SetActorType(sld);
						LAi_ActorDialog(&Characters[GetOfficersIndex(Pchar, 3)], pchar, "", 10.0, 10.0);
						LAi_QuestDelay("Muelle_Blythe4", 4.0);
					}
				}
			}
			AddQuestrecord("nigel", 22);
		break;

		case "Muelle_Blythe2":
			sld = &Characters[GetOfficersIndex(Pchar, 1)];
			sld.Dialog.Filename = Pchar.Temp.Officer.dialog;
			characters[GetOfficersIndex(Pchar, 1)].dialog.currentnode = Pchar.Temp.Officer.dialognode;
			LAi_SetOfficerType(sld);
		break;

		case "Muelle_Blythe3":
			sld = &Characters[GetOfficersIndex(Pchar, 2)];
			sld.Dialog.Filename = Pchar.Temp.Officer.dialog;
			characters[GetOfficersIndex(Pchar, 1)].dialog.currentnode = Pchar.Temp.Officer.dialognode;
			LAi_SetOfficerType(sld);
		break;

		case "Muelle_Blythe4":
			sld = &Characters[GetOfficersIndex(Pchar, 3)];
			sld.Dialog.Filename = Pchar.Temp.Officer.dialog;
			characters[GetOfficersIndex(Pchar, 1)].dialog.currentnode = Pchar.Temp.Officer.dialognode;
			LAi_SetOfficerType(sld);
		break;


		case "Maxwell_talk":
			PlaceCharacter(characterFromID("Friedrich Maxwell"), "goto");
			LAi_SetActorType(CharacterFromID("Friedrich Maxwell"));
			LAi_ActorDialog(CharacterFromID("Friedrich Maxwell"), pchar, "", 3.0, 1.0);
		break;

		case "Maxwell_talk2":
			//characters[GetCharacterIndex("Lambrecht Fobes")].dialog.currentnode = "continue";
			LAi_ActorDialog (characterfromID("Friedrich Maxwell"), PChar, "", 1.0, 1.0);
		break;

		case "Pirates_vs_Blaze":
			StartQuestMovie(true, true, false);TrackQuestMovie("start","Pirates_vs_Blaze");

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "corsair1", "goto", "goto23");
			sld.id = "offended_pirate1";
			// NK -sld.skill.Fencing = "1";
			LAi_SetActorType(CharacterFromID("offended_pirate1"));

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "corsair1_1", "goto", "character3");
			sld.id = "offended_pirate2";
			// NK - sld.skill.Fencing = "1";
			sld.Dialog.Filename = "Pirates_vs_Blaze.c";
			LAi_SetActorType(CharacterFromID("offended_pirate2"));

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "bocman4", "goto", "goto19");
			sld.id = "offended_pirate3";
			// NK -sld.skill.Fencing = "1";
			LAi_SetActorType(CharacterFromID("offended_pirate3"));

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "bocman", "goto", "goto33");
			sld.id = "offended_pirate5";
			// NK - sld.skill.Fencing = "1";
			LAi_SetActorType(CharacterFromID("offended_pirate5"));

			LAi_ActorDialog(characterfromID("offended_pirate2"), PChar, "", 10.0, 1.0);
		break;


		case "Voysey_death":
			characters[GetCharacterIndex("Artois Voysey")].dialog.currentnode = "continue3";
		break;

		case "Nigel_listed":
			AddQuestRecord("nigel", 2);
			Pchar.quest.Nigel_Blythe.win_condition.l1 = "location";
			Pchar.quest.Nigel_Blythe.win_condition.l1.location = "REDMOND_PORT";	// Petros ... was Oxbay_Port
			PChar.quest.Nigel_Blythe.win_condition = "Nigel_Adventure";

			AddMoneyToCharacter(PChar, -3000);
			LAi_SetPlayerType(pchar);
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Nigel Blythe")); // NK was -1
			LAi_SetOfficerType(CharacterFromID("Nigel Blythe"));
		break;

		case "Nigel_listed2":
			AddQuestRecord("nigel", 2);
			Pchar.quest.Nigel_Blythe.win_condition.l1 = "location";
			Pchar.quest.Nigel_Blythe.win_condition.l1.location = "REDMOND_PORT";	// Petros ... was Oxbay_Port
			PChar.quest.Nigel_Blythe.win_condition = "Nigel_Adventure";

			AddMoneyToCharacter(PChar, -300);
			LAi_SetPlayerType(pchar);
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Nigel Blythe")); // NK was -1
			LAi_SetOfficerType(CharacterFromID("Nigel Blythe"));
		break;

		case "nigel_second_encounter":
			Pchar.quest.Nigel_Blythe2.win_condition.l1 = "location";
			Pchar.quest.Nigel_Blythe2.win_condition.l1.location = "Conceicao_port";
			Pchar.quest.Nigel_Blythe2.win_condition = "Nigel_Adventure_Conc";
		break;

		case "nigel_third_encounter":
			Pchar.quest.Nigel_Blythe6.win_condition.l1 = "location";
			Pchar.quest.Nigel_Blythe6.win_condition.l1.location = "Douwesen";
			Pchar.quest.Nigel_Blythe6.win_condition = "Blythe_Battle";
		break;

		case "nigel_fourth_encounter":
			Pchar.quest.Nigel_Blythe3.win_condition.l1 = "location";
			Pchar.quest.Nigel_Blythe3.win_condition.l1.location = "IslaMuelle";
			Pchar.quest.Nigel_Blythe3.win_condition = "Blythe_gone_ship";
		break;

		case "Nigel_Blythe_prepare_removal":
			PChar.quest.Nigel_Blythe_removal.win_condition.l1 = "ExitFromLocation";
			PChar.quest.Nigel_Blythe_removal.win_condition.l1.location = PChar.location;
			PChar.quest.Nigel_Blythe_removal.win_condition = "Nigel_Blythe_removal";
		break;

		case "Nigel_Blythe_removal":
			ChangeCharacterAddress(characterFromID("Nigel Blythe"), "none", "");
		break;

		case "Nigel_dissmissed":
			AddQuestRecord("nigel", 5);
			CloseQuestheader("nigel");
			ChangeCharacterReputation(pchar, -1);
			//RemovePassenger(pchar, characterFromID("Nigel Blythe"));
			LAi_fade("Nigel_dissmissed_2", "");
		break;

		case "Nigel_dissmissed_2":
			homelocation = characters[GetCharacterIndex("Nigel Blythe")].homelocation;
			homegroup = characters[GetCharacterIndex("Nigel Blythe")].homelocation.group;
			homelocator = characters[GetCharacterIndex("Nigel Blythe")].homelocation.locator;
			ChangeCharacterAddressGroup(characterFromID("Nigel Blythe"), homelocation, homegroup, homelocator);
			characters[GetCharacterIndex("Nigel Blythe")].dialog.currentnode = "Fired";
		break;

		case "Nigel_cargo_off":
			AddQuestRecord("nigel", 6);
			characters[GetCharacterIndex("Nigel Blythe")].loyality = makeint(characters[GetCharacterIndex("Nigel Blythe")].loyality) - 1;
			ChangeCharacterReputation(pchar, -2);
			AddPassenger(Pchar, characterFromID("Nigel Blythe"), 0);
			characters[GetCharacterIndex("nigel blythe")].Dialog.CurrentNode = "officer_Nig";
		break;

		case "con_parri_off":
			characters[GetCharacterIndex("Nigel Blythe")].loyality = makeint(characters[GetCharacterIndex("Nigel Blythe")].loyality) - 1;
			ChangeCharacterReputation(pchar, -2);
			//SetOfficersIndex(Pchar, -1, GetCharacterIndex("Nigel Blythe"));
			AddPassenger(Pchar, characterFromID("Nigel Blythe"), 0);
			characters[GetCharacterIndex("nigel blythe")].Dialog.CurrentNode = "officer_Nig";
		break;

		case "con_parri_prepare":
			AddPassenger(Pchar, characterFromID("Nigel Blythe"), 0);
			characters[GetCharacterIndex("nigel blythe")].Dialog.CurrentNode = "officer_Nig";

			characters[GetCharacterIndex("Ethilrede Claar")].name = "Shuggy";
			characters[GetCharacterIndex("Ethilrede Claar")].lastname = "Garry";

			pchar.quest.exit_to_conceicao_sea.win_condition.l1 = "location";
			pchar.quest.exit_to_conceicao_sea.win_condition.l1.location = "Conceicao";
			pchar.quest.exit_to_conceicao_sea.win_condition = "exit_to_conceicao_sea";

			pchar.quest.nigel_con_parri_checker = "begin";
			pchar.quest.con_parri.win_condition.l1 = "NPC_Death";
			pchar.quest.con_parri.win_condition.l1.character = "Ethilrede Claar";
			pchar.quest.con_parri.win_condition = "con_parri";

			PChar.quest.con_parri_expired.win_condition.l1 = "Timer";
			PChar.quest.con_parri_expired.win_condition.l1.date.day = GetAddingDataDay(0,0,30);	// GR: was (0,30,0) which is 30 months!
			PChar.quest.con_parri_expired.win_condition.l1.date.month = GetAddingDataMonth(0,0,30);
			PChar.quest.con_parri_expired.win_condition.l1.date.year = GetAddingDataYear(0,0,30);
			PChar.quest.con_parri_expired.win_condition = "con_parri_expired";
		break;

		case "exit_to_conceicao_sea":
			Group_CreateGroup("Ethilrede Claar");
			Group_AddCharacter("Ethilrede Claar", "Ethilrede Claar");
			Group_SetGroupCommander("Ethilrede Claar", "Ethilrede Claar");
			Group_SetTaskAttack("Ethilrede Claar", PLAYER_GROUP, true);
			//Group_SetPursuitGroup("Nigel Blythe", "PLAYER_GROUP");
			Group_SetAddress("Ethilrede Claar", "Conceicao", "quest_ships", "quest_ship_2");
			Group_LockTask("Ethilrede Claar");
		break;

		case "con_parri_expired":
			PChar.quest.nigel_con_parri_checker = "failed";
			ChangeCharacterReputation(pchar, -2);
			AddQuestrecord("nigel", 13);
		break;

		case "con_parri":
			if (CheckQuestAttribute("nigel_con_parri_checker", "failed"))
			{
				pchar.quest.nigel_con_parri_checker = "win";
			}
			else
			{
				pchar.quest.nigel_con_parri_checker = "win_win";
			}
			AddQuestrecord("nigel", 14);
		break;

		case "nigel_first_cargo_on":
			PChar.quest.nigel_first_cargo_on_expired.win_condition.l1 = "Timer";
			PChar.quest.nigel_first_cargo_on_expired.win_condition.l1.date.day = GetAddingDataDay(0,1,0);
			PChar.quest.nigel_first_cargo_on_expired.win_condition.l1.date.month = GetAddingDataMonth(0,1,0);
			PChar.quest.nigel_first_cargo_on_expired.win_condition.l1.date.year = GetAddingDataYear(0,1,0);
			PChar.quest.nigel_first_cargo_on_expired.win_condition = "nigel_first_cargo_on_expired";
			pchar.quest.nigel_first_cargo_checker = "begin";
			AddPassenger(Pchar, characterFromID("Nigel Blythe"), 0);
			characters[GetCharacterIndex("nigel blythe")].Dialog.CurrentNode = "officer_Nig";
			AddQuestRecord("nigel", 7);
		break;

		case "nigel_first_cargo_on_expired":
			ChangeCharacterReputation(pchar, -2);
			pchar.quest.nigel_first_cargo_checker = "failed";
			AddQuestRecord("nigel", 8);
			LAi_QuestDelay("nigel_second_encounter", 1.0);
		break;

		case "clauss_to_tavern":
			AddQuestrecord("nigel", 26);
			pchar.quest.clauss_to_tavern_complete.win_condition.l1 = "location";
			pchar.quest.clauss_to_tavern_complete.win_condition.l1.location = "QC_tavern";
			pchar.quest.clauss_to_tavern_complete.win_condition = "clauss_to_tavern_complete";
		break;

		case "clauss_to_tavern_complete":
			PlaceCharacter(characterFromID("Florens Clauss"), "goto");
			LAi_SetStayType(characterFromID("Florens Clauss"));
		break;

		case "prepare_for_final_fight_with_nigel":
			AddQuestrecord("nigel", 27);
			pchar.quest.nigel_treasure_found.win_condition.l1 = "location";
			pchar.quest.nigel_treasure_found.win_condition.l1.location = "Douwesen_Shore_ship";
			pchar.quest.nigel_treasure_found.win_condition = "nigel_treasure_found";
			AddPassenger(Pchar, characterFromID("Florens Clauss"), 0);
			LAi_LocationMonstersGen(&locations[FindLocation("Douwesen_Shore_ship")], false);
		break;

		case "nigel_treasure_found":
			LAi_SetImmortal(characterFromID("nigel Blythe"), false); // PB: Make sure you can kill him
			ChangeCharacterAddressGroup(characterFromID("nigel Blythe"), "Douwesen_Shore_ship", "monsters", "monster1");
			LAi_group_MoveCharacter(characterFromID("nigel Blythe"), "NIGEL");
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "corsair1", "monsters", "monster2");
			LAi_group_MoveCharacter(sld, "NIGEL");
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "corsair2", "monsters", "monster3");
			LAi_group_MoveCharacter(sld, "NIGEL");
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "corsair3", "monsters", "monster4");
			LAi_group_MoveCharacter(sld, "NIGEL");
			LAi_group_FightGroups("NIGEL", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("NIGEL", "nigel_treasure_found_complete");
		break;

		case "nigel_treasure_found_complete":
			AddMoneyToCharacter(PChar, 50000);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 25000); }
			else { AddPartyExp(pchar, 25000); }
			AddQuestrecord("nigel", 28);
			CloseQuestHeader("nigel");
			SetCharacterRemovable(CharacterFromID("Florens Clauss"), true);
			Characters[GetCharacterIndex("Florens Clauss")].dialog.Filename = "Enc_Officer_dialog.c"; // GR
			Characters[GetCharacterIndex("Florens Clauss")].dialog.CurrentNode = "hired";
		break;

		///////////////////////////////////////////////////////////////
		// CLAIRE LARROUSE
		///////////////////////////////////////////////////////////////

		case "to_oxbay_mines_with_larrouse_complete":
			// --> Swindler 050927: don't generate vags then, would break the quest
			locations[FindLocation("Oxbay_canyon")].vcskip = true;
			// Swindler <--
			characters[GetCharacterIndex("Claire Larrouse")].dialog.currentnode = "in_canyon";
			pchar.quest.to_canvoy_with_larouse.win_condition.l1 = "location";
			pchar.quest.to_canvoy_with_larouse.win_condition.l1.location = "Oxbay_canyon";
			pchar.quest.to_canvoy_with_larouse.win_condition = "to_oxbay_mines_with_larrouse_3_complete";
			DisableFastTravel(true);
			DisableMenuLaunch(true);
			DoQuestCheckDelay("to_oxbay_mines_with_larrouse_complete_2", 2.0);
		break;

		case "to_oxbay_mines_with_larrouse_complete_2":
			switch(LanguageGetLanguage())
			{
				case "SPANISH": temp = TranslateString("","Crewmember of") + " " + GetMyName(PChar); break;
				case "RUSSIAN":
					if(strright(GetMyName(PChar),1) == "ü") temp = strleft(GetMyName(PChar), strlen(GetMyName(PChar))-1);
					else temp = GetMyName(PChar);
					temp = TranslateString("","Crewmember of") + " " + temp + "à";
				break;
				temp = GetMyName(PChar) + TranslateString("","'s crewmember");
			}
			for(n=1; n<=3; n++)
			{
				Characters[GetCharacterIndex("Blaze_Crewmember_0"+n)].name = temp;
			}

			if(GetOfficersIndex(Pchar, 1) == -1)
			{
				Pchar.Temp.Officer.idx1 = GetCharacterIndex("Blaze_Crewmember_01");
				SetOfficersIndex(pchar, 1, GetCharacterIndex("Blaze_Crewmember_01"));
			}
			else
			{
				Pchar.Temp.Officer.idx1 = getOfficersIndex(Pchar, 1);
			}
			if(GetOfficersIndex(Pchar, 2) == -1)
			{
				Pchar.Temp.Officer.idx2 = GetCharacterIndex("Blaze_Crewmember_02");
				SetOfficersIndex(pchar, 2, GetCharacterIndex("Blaze_Crewmember_02"));
			}
			else
			{
				Pchar.Temp.Officer.idx2 = getOfficersIndex(Pchar, 2);
			}
			if(GetOfficersIndex(Pchar, 3) == -1)
			{
				Pchar.Temp.Officer.idx3 = GetCharacterIndex("Blaze_Crewmember_03");
				SetOfficersIndex(pchar, 3, GetCharacterIndex("Blaze_Crewmember_03"));
			}
			else
			{
				Pchar.Temp.Officer.idx3 = getOfficersIndex(Pchar, 3);
			}
			DoReloadFromSeaToLocation("Oxbay_canyon", "reload", "reload6");
		break;

		case "to_oxbay_mines_with_larrouse_3_complete":
			DisableFastTravel(false);
			DisableMenuLaunch(false);
			pchar.quest.remove_faked_officers.win_condition.l1 = "location";
			pchar.quest.remove_faked_officers.win_condition.l1.location = "Oxbay_shore_02";
			pchar.quest.remove_faked_officers.win_condition = "remove_faked_officers";
// PB -->
				for (cidx = 1; cidx < 4; cidx++)
				{
					iPassenger = GetOfficersIndex(Pchar, cidx);
					if (iPassenger > 0) LAi_SetOfficerType(&characters[getOfficersIndex(Pchar, cidx)]);
				}
// PB <--
			locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 1;
			locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 1;
			locations[FindLocation("Oxbay_canyon")].reload.l3.disable = 1;
			locations[FindLocation("Oxbay_canyon")].reload.l4.disable = 1;

			RestoreCharacter(characterFromID("Larrouse_pirate_01")); // KK // TALISMAN was quest_pirate_01
			LAi_SetHP(characterFromID("Larrouse_pirate_01"), 80.0, 80.0); // TALISMAN was quest_pirate_01
			LAi_SetHP(characterFromID("Larrouse_smuggler_01"), 80.0, 80.0); // TALISMAN was quest_smuggler_01
			ChangeCharacterAddress(characterFromID("Larrouse_pirate_01"), "Oxbay_canyon", "goto24"); // TALISMAN was quest_pirate_01
			ChangeCharacterAddress(characterFromID("Larrouse_smuggler_01"), "Oxbay_canyon", "goto28"); // TALISMAN was quest_smuggler_01
			ChangeCharacterAddress(characterFromID("Claire Larrouse"), "Oxbay_canyon", "goto26");
// KK -->
			characters[GetCharacterIndex("Larrouse_pirate_01")].dialog.filename = "quest_pirate_01_dialog.c";  // TALISMAN was quest_pirate_01
			characters[GetCharacterIndex("Larrouse_pirate_01")].dialog.currentnode = "mines";  // TALISMAN was quest_pirate_01
			characters[GetCharacterIndex("Larrouse_smuggler_01")].dialog.filename = "quest_pirate_01_dialog.c";  // TALISMAN was quest_smuggler_01
			characters[GetCharacterIndex("Larrouse_smuggler_01")].dialog.currentnode = "mines";  // TALISMAN was quest_smuggler_01
			characters[GetCharacterIndex("Blaze_Crewmember_01")].dialog.filename = "quest_pirate_01_dialog.c";
			characters[GetCharacterIndex("Blaze_Crewmember_01")].dialog.currentnode = "mines";
			characters[GetCharacterIndex("Blaze_Crewmember_02")].dialog.filename = "quest_pirate_01_dialog.c";
			characters[GetCharacterIndex("Blaze_Crewmember_02")].dialog.currentnode = "mines";
			characters[GetCharacterIndex("Blaze_Crewmember_03")].dialog.filename = "quest_pirate_01_dialog.c";
			characters[GetCharacterIndex("Blaze_Crewmember_03")].dialog.currentnode = "mines";
// <-- KK
			Locations[FindLocation("Oxbay_canyon")].reload.l4.disable = true;

			LAi_SetOfficerType(characterFromID("Larrouse_pirate_01")); // TALISMAN was quest_pirate_01
			LAi_SetOfficerType(characterFromID("Larrouse_smuggler_01"));  // TALISMAN was quest_smuggler_01

			LAi_SetImmortal(characterfromID("Claire Larrouse"), true);
			LAi_SetActorType(characterfromID("Claire Larrouse"));

			LAi_ActorDialog(characterFromID("Claire Larrouse"), pchar, "", 3.0, 1.0);
		break;

		case "remove_faked_officers":
			// --> Swindler 050927: reset vags in canyon after quest is complete
			DeleteAttribute(&Locations[FindLocation("Oxbay_canyon")],"vcskip");
			// Swindler <--
			iPassenger = makeint(Pchar.Temp.Officer.idx1);
			if(FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_OFFICER || FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_PASSENGER)
			{
				if (characters[iPassenger].id == "Blaze_Crewmember_01" || characters[iPassenger].id == "Blaze_Crewmember_02" || characters[iPassenger].id == "Blaze_Crewmember_03")
				{
					RemovePassenger(pchar, &characters[iPassenger]);
				}
			}
			iPassenger = makeint(Pchar.Temp.Officer.idx2);
			if(FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_OFFICER || FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_PASSENGER)
			{
				if (characters[iPassenger].id == "Blaze_Crewmember_01" || characters[iPassenger].id == "Blaze_Crewmember_02" || characters[iPassenger].id == "Blaze_Crewmember_03")
				{
					RemovePassenger(pchar, &characters[iPassenger]);
				}
			}
			iPassenger = makeint(Pchar.Temp.Officer.idx3);

			if(FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_OFFICER || FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_PASSENGER)
			{
				if (characters[iPassenger].id == "Blaze_Crewmember_01" || characters[iPassenger].id == "Blaze_Crewmember_02" || characters[iPassenger].id == "Blaze_Crewmember_03")
				{
					RemovePassenger(pchar, &characters[iPassenger]);
				}
			}

// KK -->
			characters[GetCharacterIndex("Blaze_Crewmember_01")].dialog.currentnode = "first time";
			characters[GetCharacterIndex("Blaze_Crewmember_02")].dialog.currentnode = "first time";
			characters[GetCharacterIndex("Blaze_Crewmember_03")].dialog.currentnode = "first time";
			characters[GetCharacterIndex("Larrouse_smuggler_01")].dialog.filename = "quest_smuggler_01_dialog.c";  // TALISMAN was quest_smuggler_01
			characters[GetCharacterIndex("Larrouse_smuggler_01")].dialog.currentnode = "First time";  // TALISMAN was quest_smuggler_01
			characters[GetCharacterIndex("Larrouse_pirate_01")].dialog.filename = "quest_pirate_01_dialog.c";  // TALISMAN was quest_pirate_01
			characters[GetCharacterIndex("Larrouse_pirate_01")].dialog.currentnode = "First time";  // TALISMAN was quest_pirate_01
// <-- KK
			ChangeCharacterAddress(characterFromID("Larrouse_pirate_01"), "none", "");  // TALISMAN was quest_pirate_01
			ChangeCharacterAddress(characterFromID("Larrouse_smuggler_01"), "none", "");  // TALISMAN was quest_smuggler_01
		break;

		case "to_the_gold_for_fight":
			LAi_NoRebirthEnable(characterFromID("mine_soldier_05"));
			LAi_NoRebirthEnable(characterFromID("mine_soldier_06"));
			// 1 enemy soldier
			LAi_SetOfficerType(characterFromID("Claire Larrouse"));

			n = GetTownNation("Greenford");
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[n].fantomModel.m1, "goto", "goto9"); // PB
			// NK - LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");
			sld.nation = n;
			SetRandomNameToCharacter(sld);

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[n].fantomModel.m2, "goto", "goto9"); // PB
			// NK - LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");
			sld.nation = n;
			SetRandomNameToCharacter(sld);

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[n].fantomModel.m3, "goto", "goto9"); // PB
			// NK - LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");
			sld.nation = n;
			SetRandomNameToCharacter(sld);

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[n].fantomModel.m4, "goto", "goto9"); // PB
			// NK - LAi_SetHP(sld, 80.0, 80.0);
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");
			sld.nation = n;
			SetRandomNameToCharacter(sld);

			LAi_group_MoveCharacter(characterFromID("mine_soldier_05"), "MINE_KEEPERS");
			LAi_group_MoveCharacter(characterFromID("mine_soldier_06"), "MINE_KEEPERS");

			LAi_group_FightGroups("MINE_KEEPERS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("MINE_KEEPERS", "abording_mines_with_larrouse_complete");
		break;

		case "abording_mines_with_larrouse_complete":
			LAi_SetActorType(pchar);
			LAi_SetActorType(characterfromID("Claire Larrouse"));
			characters[GetCharacterIndex("Claire Larrouse")].dialog.currentnode = "abording_mine";
			LAi_ActorFollow(pchar, characterfromID("Claire Larrouse"), "", 1.0);
			LAi_ActorFollow(characterfromID("Claire Larrouse"), pchar, "abording_mines_with_larrouse_complete_2", 1.0);
		break;

		case "abording_mines_with_larrouse_complete_2":
			LAi_SetPlayerType(pchar);
			LAi_ActorDialog(characterfromID("Claire Larrouse"), pchar, "", 3.0, 1.0);
		break;

		case "abording_bad_fight_exit":
			LAi_SetImmortal(characterfromID("Claire Larrouse"), false);
			LAi_group_MoveCharacter(characterfromID("Claire Larrouse"), "LARROUSE");
			LAi_group_MoveCharacter(characterfromID("Larrouse_pirate_01"), "LARROUSE");  // TALISMAN was quest_pirate_01
			LAi_group_MoveCharacter(characterfromID("Larrouse_smuggler_01"), "LARROUSE");  // TALISMAN was quest_smuggler_01
			SetCharacterRelation(GetCharacterIndex("Clair Larrouse"),GetMainCharacterIndex(),RELATION_ENEMY);
			Group_CreateGroup("Clair Larrouse");
			Group_AddCharacter("Clair Larrouse", "Clair Larrouse");
			Group_SetGroupCommander("Clair Larrouse", "Clair Larrouse");
			Group_SetPursuitGroup("Clair Larrouse", PLAYER_GROUP);
			Group_SetTaskAttack("Clair Larrouse", PLAYER_GROUP, true);
			Group_LockTask("Clair Larrouse");

			if (pchar.location == "Oxbay_shore_02")
			{
				iPassenger = makeint(characters[GetCharacterIndex("Claire Larrouse")].quest.goldmine)*10000;
				AddMoneyToCharacter(characterFromID("Claire Larrouse"), iPassenger);
				pchar.quest.run_from_clair_in_sea.win_condition.l1 = "MapEnter";
				pchar.quest.run_from_clair_in_sea.win_condition = "Clair_quest_ended";
				Group_SetAddress("Clair Larrouse", "Oxbay", "", "");
			}
			else
			{
				pchar.quest.run_from_clair_in_sea.win_condition.l1 = "MapEnter";
				pchar.quest.run_from_clair_in_sea.win_condition = "Clair_quest_ended1";
				Group_SetAddress("Clair Larrouse", "Oxbay", "", "");
			}
			LAi_group_FightGroups("LARROUSE", LAI_GROUP_PLAYER, true);
			LAi_SetHP(characterFromID("Claire Larrouse"), 80.0, 80.0);
			RemoveCharacterCompanion(Pchar, &Characters[GetCharacterIndex("Claire Larrouse")]);
			SetCharacterRemovable(characterFromID("Claire Larrouse"), true); // NK

			UpdateRelations();

			pchar.quest.killing_clair_in_sea.win_condition.l1 = "NPC_Death";
			pchar.quest.killing_clair_in_sea.win_condition.l1.character = "Clair Larrouse";
			pchar.quest.killing_clair_in_sea.win_condition = "killing_clair_in_sea_complete";

			Locations[FindLocation("Oxbay_canyon")].reload.l4.disable = false;
			LAi_group_SetCheck("LARROUSE", "fight_with_larrouse_complete");
		break;

		case "fight_with_larrouse_complete":
			pchar.quest.exit_from_oxbay_to_sea.win_condition.l1 = "location";
			pchar.quest.exit_from_oxbay_to_sea.win_condition.l1.location = "Oxbay";
			pchar.quest.exit_from_oxbay_to_sea.win_condition = "exit_from_oxbay_to_sea_complete";
			if (pchar.location == "Oxbay_shore_02")
			{
				//iPassenger = makeint(characters[GetCharacterIndex("Claire Larrouse")].quest.goldmine)*10000/2;
				//AddMoneyToCharacter(pchar, iPassenger);
				OfficersReaction("bad");
				AddQuestRecord("larrouse", 12);
				if(AUTO_SKILL_SYSTEM)
				{
					AddPartyExpChar(pchar, "Leadership", 5000);
					AddPartyExpChar(pchar, "Sneak", 50);
				}
				else { AddPartyExp(pchar, 5000); }
			}
			else
			{
				AddQuestRecord("larrouse", 5);
				if(AUTO_SKILL_SYSTEM)
				{
					AddPartyExpChar(pchar, "Leadership", 2500);
					AddPartyExpChar(pchar, "Sneak", 25);
				}
				else { AddPartyExp(pchar, 2500); }
			}
		break;

		case "exit_from_oxbay_to_sea_complete":
			iPassenger = makeint(Pchar.Temp.Officer.idx1);
			if (characters[iPassenger].id == "Blaze_Crewmember_01" || characters[iPassenger].id == "Blaze_Crewmember_02" || characters[iPassenger].id == "Blaze_Crewmember_03")
			{
				RemovePassenger(pchar, &characters[iPassenger]);
			}
			iPassenger = makeint(Pchar.Temp.Officer.idx2);
			if (characters[iPassenger].id == "Blaze_Crewmember_01" || characters[iPassenger].id == "Blaze_Crewmember_02" || characters[iPassenger].id == "Blaze_Crewmember_03")
			{
				RemovePassenger(pchar, &characters[iPassenger]);
			}
			iPassenger = makeint(Pchar.Temp.Officer.idx3);
			if (characters[iPassenger].id == "Blaze_Crewmember_01" || characters[iPassenger].id == "Blaze_Crewmember_02" || characters[iPassenger].id == "Blaze_Crewmember_03")
			{
				RemovePassenger(pchar, &characters[iPassenger]);
			}

			

			//bQuestDisableMapEnter = true;
			Island_SetReloadEnableGlobal("Oxbay", false);// TIH typo fix Oct31'06

		break;

		case "killing_clair_in_sea_complete":
			AddQuestRecord("larrouse", 6);
			pchar.quest.run_from_clair_in_sea.over = "yes";
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 5000); }
			else { AddPartyExp(pchar, 5000); }
			Island_SetReloadEnableGlobal("Oxbay", true); // PB: was 'false'???
			locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 0;
			locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 0;
			locations[FindLocation("Oxbay_canyon")].reload.l3.disable = 0; 
			locations[FindLocation("Oxbay_canyon")].reload.l4.disable = 0;
			CloseQuestHeader("larrouse");

			LAi_group_MoveCharacter(CharacterFromID("mine_soldier_05"), GetTownSoldierGroup("Greenford"));
			LAi_group_MoveCharacter(CharacterFromID("mine_soldier_06"), GetTownSoldierGroup("Greenford"));
			LAi_NoRebirthDisable(characterFromID("mine_soldier_05"));
			LAi_NoRebirthDisable(characterFromID("mine_soldier_06"));
		break;

		case "Clair_quest_ended":

			AddQuestRecord("larrouse", 15);
			pchar.quest.killing_clair_in_sea.over = "yes";
			group_DeleteGroup("Clair Larrouse");
			ChangeCharacterAddressGroup(CharacterFromID("Clair Larrouse"), "None", "", "");
			Island_SetReloadEnableGlobal("Oxbay", true); // PB: was 'false'???
			locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 0;
			locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 0;
			locations[FindLocation("Oxbay_canyon")].reload.l3.disable = 0; 
			locations[FindLocation("Oxbay_canyon")].reload.l4.disable = 0;
			CloseQuestHeader("larrouse");
			
			LAi_group_MoveCharacter(CharacterFromID("mine_soldier_05"), GetTownSoldierGroup("Greenford"));
			LAi_group_MoveCharacter(CharacterFromID("mine_soldier_06"), GetTownSoldierGroup("Greenford"));
			LAi_NoRebirthDisable(characterFromID("mine_soldier_05"));
			LAi_NoRebirthDisable(characterFromID("mine_soldier_06"));
		break;

		case "Clair_quest_ended1":

			AddQuestRecord("larrouse", 16);
			pchar.quest.killing_clair_in_sea.over = "yes";
			group_DeleteGroup("Clair Larrouse");
			ChangeCharacterAddressGroup(CharacterFromID("Clair Larrouse"), "None", "", "");
			Island_SetReloadEnableGlobal("Oxbay", true); // PB: was 'false'???
			locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 0;
			locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 0;
			locations[FindLocation("Oxbay_canyon")].reload.l3.disable = 0; 
			locations[FindLocation("Oxbay_canyon")].reload.l4.disable = 0;
			CloseQuestHeader("larrouse");
			
			LAi_group_MoveCharacter(CharacterFromID("mine_soldier_05"), GetTownSoldierGroup("Greenford"));
			LAi_group_MoveCharacter(CharacterFromID("mine_soldier_06"), GetTownSoldierGroup("Greenford"));
			LAi_NoRebirthDisable(characterFromID("mine_soldier_05"));
			LAi_NoRebirthDisable(characterFromID("mine_soldier_06"));
			
			LAi_QuestDelay("Clair_quest_ended2", 1.0);
		break;

		case "larrouse_becomes_officer":
			LAi_ActorFollowEverywhere(characterFromID("Claire Larrouse"), "", 60.0);
			AddQuestRecord("larrouse", 7);
		break;

		case "to_gold_konvoy_complete":
			Locations[FindLocation("Oxbay_canyon")].reload.l4.disable = false;

			LAi_LocationMonstersGen(&locations[FindLocation("Oxbay_jungle_02")], false);
			LAi_SetOfficerType(characterFromID("Claire Larrouse"));
			LAi_SetOfficerType(characterFromID("Larrouse_pirate_01"));  // TALISMAN was quest_pirate_01
			LAi_SetOfficerType(characterFromID("Larrouse_smuggler_01"));  // TALISMAN was quest_smuggler_01
			AddQuestRecord("larrouse", 8);
			locations[FindLocation("Oxbay_jungle_02")].reload.l1.disable = 1;
			locations[FindLocation("Oxbay_jungle_02")].reload.l2.disable = 1;
			locations[FindLocation("Oxbay_jungle_02")].reload.l3.disable = 1;

			n = GetTownNation("Greenford");
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[n].fantomModel.m1, "goto", "citizen03"); // PB
			sld.id = "soldier1";
			sld.nation = n;
			SetRandomNameToCharacter(sld);
			LAi_SetActorType(sld);
			// NK - LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1.0, false, "fight_in_jungles"); // NK
			pchar.quest.kill_konvoyer_01.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_konvoyer_01.win_condition.l1.character = "soldier1";
			pchar.quest.kill_konvoyer_01.win_condition = "kill_konvoyer_01";

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[n].fantomModel.m2, "goto", "citizen08"); // PB
			sld.id = "soldier2";
			sld.nation = n;
			SetRandomNameToCharacter(sld);
			LAi_SetActorType(sld);
			// NK - LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1.0, false, "fight_in_jungles"); // NK
			pchar.quest.kill_konvoyer_02.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_konvoyer_02.win_condition.l1.character = "soldier2";
			pchar.quest.kill_konvoyer_02.win_condition = "kill_konvoyer_02";

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[n].fantomModel.m3, "goto", "citizen07"); // PB
			sld.id = "soldier3";
			sld.nation = n;
			SetRandomNameToCharacter(sld);
			LAi_SetActorType(sld);
			// NK - LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1.0, false, "fight_in_jungles"); // NK
			pchar.quest.kill_konvoyer_03.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_konvoyer_03.win_condition.l1.character = "soldier3";
			pchar.quest.kill_konvoyer_03.win_condition = "kill_konvoyer_03";

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[n].fantomModel.m4, "goto", "citizen04"); // PB
			sld.id = "soldier4";
			sld.nation = n;
			SetRandomNameToCharacter(sld);
			LAi_SetActorType(sld);
			// NK - LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1.0, false, "fight_in_jungles"); // NK
			pchar.quest.kill_konvoyer_04.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_konvoyer_04.win_condition.l1.character = "soldier4";
			pchar.quest.kill_konvoyer_04.win_condition = "kill_konvoyer_04";

			characters[GetCharacterIndex("Claire Larrouse")].dialog.currentnode = "kill_konvoy";
			LAi_SetActorType(characterFromID("Claire Larrouse"));
			LAi_ActorDialog(characterFromID("Claire Larrouse"), pchar, "", 2.0, 1.0);
		break;

		case "fight_in_jungles":
			LAi_RemoveCheckMinHP(characterFromID("soldier1"));
			LAi_RemoveCheckMinHP(characterFromID("soldier2"));
			LAi_RemoveCheckMinHP(characterFromID("soldier3"));
			LAi_RemoveCheckMinHP(characterFromID("soldier4"));

			LAi_group_MoveCharacter(characterfromID("soldier1"), "KONVOYERS");
			LAi_group_MoveCharacter(characterfromID("soldier2"), "KONVOYERS");
			LAi_group_MoveCharacter(characterfromID("soldier3"), "KONVOYERS");
			LAi_group_MoveCharacter(characterfromID("soldier4"), "KONVOYERS");

			LAi_group_FightGroups("KONVOYERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("KONVOYERS", "wait_for_kill");
		break;

		case "konvoy_go_away":
			LAi_SetOfficerType(characterFromID("Claire Larrouse"));
			LAi_QuestDelay("konvoy_go_away_2", 8.5);
		break;

		case "konvoy_go_away_2":
			pchar.quest.konvoyers = 0;
			LAi_ActorGoToLocator(characterFromID("soldier1"), "reload", "reload2", "konvoyer_01_exit", 30.0);
			LAi_ActorGoToLocator(characterFromID("soldier2"), "reload", "reload2", "konvoyer_02_exit", 30.0);
			LAi_ActorGoToLocator(characterFromID("soldier3"), "reload", "reload2", "konvoyer_03_exit", 30.0);
			LAi_ActorGoToLocator(characterFromID("soldier4"), "reload", "reload2", "konvoyer_04_exit", 30.0);
		break;

		case "konvoyer_01_exit":
			pchar.quest.kill_konvoyer_01.over = "yes";
			ChangeCharacterAddress(characterFromID("soldier1"), "none", "");
			pchar.quest.konvoyers = makeint(pchar.quest.konvoyers) + 1;
			if (makeint(pchar.quest.konvoyers) == 4)
			{
				characters[GetCharacterIndex("Claire Larrouse")].dialog.currentnode = "konvoy_away";
				LAi_SetActorType(characterFromID("Claire Larrouse"));
				LAi_SetActorType(pchar);
				LAi_ActorWaitDialog(pchar, characterFromID("Claire Larrouse"));
				LAi_SetActorType(characterFromID("Claire Larrouse"));
				LAi_ActorDialog(characterFromID("Claire Larrouse"), pchar, "player_back", 2.0, 1.0);
			}
		break;

		case "konvoyer_02_exit":
			pchar.quest.kill_konvoyer_02.over = "yes";
			ChangeCharacterAddress(characterFromID("soldier2"), "none", "");
			pchar.quest.konvoyers = makeint(pchar.quest.konvoyers) + 1;
			if (makeint(pchar.quest.konvoyers) == 4)
			{
				characters[GetCharacterIndex("Claire Larrouse")].dialog.currentnode = "konvoy_away";
				LAi_SetActorType(pchar);
				LAi_ActorWaitDialog(pchar, characterFromID("Claire Larrouse"));
				LAi_SetActorType(characterFromID("Claire Larrouse"));
				LAi_ActorDialog(characterFromID("Claire Larrouse"), pchar, "player_back", 2.0, 1.0);
			}
		break;

		case "konvoyer_03_exit":
			pchar.quest.kill_konvoyer_03.over = "yes";
			ChangeCharacterAddress(characterFromID("soldier3"), "none", "");
			pchar.quest.konvoyers = makeint(pchar.quest.konvoyers) + 1;
			if (makeint(pchar.quest.konvoyers) == 4)
			{
				characters[GetCharacterIndex("Claire Larrouse")].dialog.currentnode = "konvoy_away";
				LAi_SetActorType(pchar);
				LAi_ActorWaitDialog(pchar, characterFromID("Claire Larrouse"));
				LAi_SetActorType(characterFromID("Claire Larrouse"));
				LAi_ActorDialog(characterFromID("Claire Larrouse"), pchar, "player_back", 2.0, 1.0);
			}
		break;

		case "konvoyer_04_exit":
			pchar.quest.kill_konvoyer_04.over = "yes";
			ChangeCharacterAddress(characterFromID("soldier4"), "none", "");
			pchar.quest.konvoyers = makeint(pchar.quest.konvoyers) + 1;
			if (makeint(pchar.quest.konvoyers) == 4)
			{
				characters[GetCharacterIndex("Claire Larrouse")].dialog.currentnode = "konvoy_away";
				LAi_SetActorType(pchar);
				LAi_ActorWaitDialog(pchar, characterFromID("Claire Larrouse"));
				LAi_SetActorType(characterFromID("Claire Larrouse"));
				LAi_ActorDialog(characterFromID("Claire Larrouse"), pchar, "player_back", 2.0, 1.0);
			}
		break;

		case "Clair_away":
			AddQuestRecord("larrouse", 9);
			CloseQuestHeader("larrouse");
			LAi_ActorRunToLocation(characterFromID("Claire Larrouse"), "reload", "reload1", "Muelle_tavern", "sit", "sit6", "clair_to_muelle", 20.0);

			pchar.quest.clair_away.win_condition.l1 = "location";
			pchar.quest.clair_away.win_condition.l1.location = "Oxbay";
			pchar.quest.clair_away.win_condition = "clair_to_muelle";
			locations[FindLocation("Oxbay_jungle_02")].reload.l1.disable = 0;
			locations[FindLocation("Oxbay_jungle_02")].reload.l2.disable = 0;
			locations[FindLocation("Oxbay_jungle_02")].reload.l3.disable = 0;
			locations[FindLocation("Oxbay_jungle_03")].reload.l1.disable = 0;
			locations[FindLocation("Oxbay_jungle_03")].reload.l2.disable = 0;
			locations[FindLocation("Oxbay_jungle_03")].reload.l3.disable = 0;
			LAi_LocationMonstersGen(&locations[FindLocation("Oxbay_jungle_02")], true);
			//pchar.reputation = makeint(pchar.reputation) - 5;
			ChangeCharacterReputation(pchar, -10);
			LAi_group_MoveCharacter(CharacterFromID("mine_soldier_05"), GetTownSoldierGroup("Greenford"));
			LAi_group_MoveCharacter(CharacterFromID("mine_soldier_06"), GetTownSoldierGroup("Greenford"));
			LAi_NoRebirthDisable(characterFromID("mine_soldier_05"));
			LAi_NoRebirthDisable(characterFromID("mine_soldier_06"));
			LAi_SetImmortal(characterfromID("Claire Larrouse"), false);
		break;

		case "kill_konvoyer_01":
			characters[GetCharacterIndex("Claire Larrouse")].quest.goldmine = makeint(characters[GetCharacterIndex("Claire Larrouse")].quest.goldmine) + 1;
		break;

		case "kill_konvoyer_02":
			characters[GetCharacterIndex("Claire Larrouse")].quest.goldmine = makeint(characters[GetCharacterIndex("Claire Larrouse")].quest.goldmine) + 1;
		break;

		case "kill_konvoyer_03":
			characters[GetCharacterIndex("Claire Larrouse")].quest.goldmine = makeint(characters[GetCharacterIndex("Claire Larrouse")].quest.goldmine) + 1;
		break;

		case "kill_konvoyer_04":
			characters[GetCharacterIndex("Claire Larrouse")].quest.goldmine = makeint(characters[GetCharacterIndex("Claire Larrouse")].quest.goldmine) + 1;
		break;

		case "wait_for_kill":
			pchar.quest.kill_konvoyer_01.over = "yes";
			pchar.quest.kill_konvoyer_02.over = "yes";
			pchar.quest.kill_konvoyer_03.over = "yes";
			pchar.quest.kill_konvoyer_04.over = "yes";

			locations[FindLocation("Oxbay_jungle_02")].reload.l1.disable = 1;
			locations[FindLocation("Oxbay_jungle_02")].reload.l2.disable = 1;
			locations[FindLocation("Oxbay_jungle_02")].reload.l3.disable = 1;
			locations[FindLocation("Oxbay_jungle_03")].reload.l1.disable = 1;
			locations[FindLocation("Oxbay_jungle_03")].reload.l2.disable = 1;
			locations[FindLocation("Oxbay_jungle_03")].reload.l3.disable = 1;
			
			PlaceFleetNearShore("Oxbay_shore_02"); 

			characters[GetCharacterIndex("Claire Larrouse")].dialog.currentnode = "konvoy_killed";
			LAi_SetActorType(characterFromID("Claire Larrouse"));
			LAi_SetStayType(pchar);
			LAi_ActorDialog(characterFromID("Claire Larrouse"), pchar, "larrouse_follow_us_again", 4.0, 1.0);
			AddQuestRecord("larrouse", 10);
		break;

		case "escape_to_shore":
			locations[FindLocation("Oxbay_jungle_02")].reload.l1.disable = 0;
			locations[FindLocation("Oxbay_jungle_02")].reload.l2.disable = 0;
			locations[FindLocation("Oxbay_jungle_02")].reload.l3.disable = 0;
			locations[FindLocation("Oxbay_jungle_03")].reload.l1.disable = 0;
			locations[FindLocation("Oxbay_jungle_03")].reload.l2.disable = 0;
			locations[FindLocation("Oxbay_jungle_03")].reload.l3.disable = 0;
			locations[FindLocation("Oxbay_shore_02")].reload.l1.disable = 1;
			locations[FindLocation("Oxbay_shore_02")].reload.l2.disable = 1;
			locations[FindLocation("Oxbay_shore_02")].reload.l3.disable = 1;
			locations[FindLocation("Oxbay_shore_02")].reload.l4.disable = 1;

			characters[GetCharacterIndex("Claire Larrouse")].dialog.currentnode = "escape_to_shore";
			LAi_SetActorType(characterFromID("Claire Larrouse"));
			LAi_ActorDialog(characterFromID("Claire Larrouse"), pchar, "", 2.0, 1.0);
		break;

		case "larrouse_follow_us_again":
			LAi_SetPlayerType(pchar);
			LAi_ActorFollowEverywhere(characterFromID("Claire Larrouse"), "", 60.0);
		break;

		case "fighting_in_shore":
			LAi_SetOfficerType(characterFromID("Claire Larrouse"));
			LAi_QuestDelay("fighting_in_shore_2", 5.0);
		break;

		case "fighting_in_shore_2":
			n = GetTownNation("Greenford");
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[n].fantomModel.m1, "reload", "reload2_back"); // PB
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");
			sld.nation = n;
			SetRandomNameToCharacter(sld);

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[n].fantomModel.m2, "reload", "reload2_back"); // PB
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");
			sld.nation = n;
			SetRandomNameToCharacter(sld);

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[n].fantomModel.m3, "reload", "reload2_back"); // PB
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");
			sld.nation = n;
			SetRandomNameToCharacter(sld);

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[n].fantomModel.m4, "reload", "reload2_back"); // PB
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");
			sld.nation = n;
			SetRandomNameToCharacter(sld);

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[n].fantomModel.m5, "reload", "reload2_back"); // PB
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");
			sld.nation = n;
			SetRandomNameToCharacter(sld);

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[n].fantomModel.m6, "reload", "reload2_back"); // PB
			LAi_group_MoveCharacter(sld, "MINE_KEEPERS");
			sld.nation = n;
			SetRandomNameToCharacter(sld);

			LAi_group_FightGroups("MINE_KEEPERS", LAI_GROUP_PLAYER, true);

			LAi_group_SetCheck("MINE_KEEPERS", "fight_in_shore_completed");
		break;

		case "fight_in_shore_completed":
			DeleteAttribute(&Locations[FindLocation("Oxbay_jungle_02")],"vcskip"); // PB
			LAi_QuestDelay("fight_in_shore_completed_almost", 4.0);
		break;

		case "fight_in_shore_completed_almost":
			locations[FindLocation("Oxbay_shore_02")].reload.l1.disable = 0;
			locations[FindLocation("Oxbay_shore_02")].reload.l2.disable = 0;
			locations[FindLocation("Oxbay_shore_02")].reload.l3.disable = 0;
			locations[FindLocation("Oxbay_shore_02")].reload.l4.disable = 0;
//			DoQuestReloadToLocation("Oxbay_shore_02", "reload", "reload2_back", "fight_in_shore_2_completed");
			LAi_QuestDelay("fight_in_shore_2_completed", 5.0);
		break;

		case "fight_in_shore_2_completed":
			LAi_SetStayType(pchar);
			Preprocessor_AddQuestData("nation", GetNationDescByType(GetTownNation("Greenford")));
			AddQuestRecord("larrouse", 11);
			Preprocessor_Remove("nation");
			characters[GetCharacterIndex("Claire Larrouse")].dialog.currentnode = "fight_in_shore_completed";
			LAi_SetActorType(characterFromID("Claire Larrouse"));
			LAi_ActorDialog(characterFromID("Claire Larrouse"), pchar, "player_back", 4.0, 1.0);
			LAi_SetImmortal(characterfromID("Claire Larrouse"), false);
		break;

		case "clair_to_muelle":
			LAi_SetSitType(characterFromID("Claire Larrouse"));
			characters[getCharacterIndex("Claire Larrouse")].location	= "Muelle_tavern";
			characters[getCharacterIndex("Claire Larrouse")].location.group = "sit";
			characters[getCharacterIndex("Claire Larrouse")].location.locator = "sit6";
			characters[getCharacterIndex("Claire Larrouse")].dialog.currentnode = "for_hire";
		break;

		case "from_shore_to_ship":
			iPassenger = makeint(Pchar.Temp.Officer.idx1);

			if(FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_OFFICER || FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_PASSENGER)
			{
				if (characters[iPassenger].id == "Blaze_Crewmember_01" || characters[iPassenger].id == "Blaze_Crewmember_02" || characters[iPassenger].id == "Blaze_Crewmember_03")
				{
					RemovePassenger(pchar, &characters[iPassenger]);
				}
			}
			iPassenger = makeint(Pchar.Temp.Officer.idx2);
			if(FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_OFFICER || FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_PASSENGER)
			{
				if (characters[iPassenger].id == "Blaze_Crewmember_01" || characters[iPassenger].id == "Blaze_Crewmember_02" || characters[iPassenger].id == "Blaze_Crewmember_03")
				{
					RemovePassenger(pchar, &characters[iPassenger]);
				}
			}
			iPassenger = makeint(Pchar.Temp.Officer.idx3);
			if(FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_OFFICER || FindFellowTravellers(PChar, &characters[iPassenger]) == FELLOWTRAVEL_PASSENGER)
			{
				if (characters[iPassenger].id == "Blaze_Crewmember_01" || characters[iPassenger].id == "Blaze_Crewmember_02" || characters[iPassenger].id == "Blaze_Crewmember_03")
				{
					RemovePassenger(pchar, &characters[iPassenger]);
				}
			}
			CloseQuestHeader("larrouse");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 20000);
				AddPartyExpChar(pchar, "Sneak", 200);
			}
			else { AddPartyExp(pchar, 20000); }
			LAi_SetOfficerType(characterFromID("Claire Larrouse"));
			characters[GetCharacterIndex("Claire Larrouse")].location = "none";
			//pchar.reputation = makeint(pchar.reputation) + 1;
			ChangeCharacterReputation(pchar, -5);
			LAi_group_MoveCharacter(CharacterFromID("mine_soldier_05"), GetTownSoldierGroup("Greenford"));
			LAi_group_MoveCharacter(CharacterFromID("mine_soldier_06"), GetTownSoldierGroup("Greenford"));
			LAi_NoRebirthDisable(characterFromID("mine_soldier_05"));
			LAi_NoRebirthDisable(characterFromID("mine_soldier_06"));
		break;

		case "Claire_hired":
			Characters[GetCharacterIndex("Claire Larrouse")].dialog.Filename = "Enc_Officer_dialog.c"; // GR
			Characters[GetCharacterIndex("Claire Larrouse")].dialog.CurrentNode = "hired";
		break;

		/////////////////////////////////////////////////////////////////////////
		//           EDGAR ATTWOOD QUEST
		/////////////////////////////////////////////////////////////////////////

		case "Set_Edgar_Free":
			AddMoneyToCharacter(Pchar,-5000);

			ChangeCharacterAddressGroup(CharacterFromID("Jack Greenfield"), "", "sit", "sit12");
			ChangeCharacterAddressGroup(CharacterFromID("Martin Warner"), "", "sit", "sit13");
			PChar.quest.Story_Artois.win_condition.l1 = "location";
			PChar.quest.Story_Artois.win_condition.l1.location = "Redmond_town_04";
			PChar.quest.Story_Artois.win_condition = "Let_my_edgar_go";
		break;

		case "Small_Pause_Before_Convoy":
			WaitDate("", 0, 0, 0, 0, 3);
			LAi_ActorSetStayMode(CharacterFromID("Jack Greenfield"));
			ChangeCharacterAddressGroup(CharacterFromID("Jack Greenfield"), "", "sit", "sit10");
// NK -->
			pchar.quest.Attwood1.leave = 1;
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -2000);
			LAi_QuestDelay("stand_up", 1.0);
			LAi_QuestDelay("convoy", 2.0);
// NK <--
		break;

		case "Attwood_Adventure": //NK reenable Attwood quests -->
			if(FindFellowTravellers(PChar, CharacterFromId("Edgar Attwood")) == FELLOWTRAVEL_OFFICER)
			{
				Locations[FindLocation("Greenford_tavern")].vcskip = true; // NK
				LAi_SetActorType(Pchar);
				Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
				Pchar.dialog.currentnode = "Attwood_lost";
				LAi_ActorSelfDialog(Pchar, "player_back");
				RemovePassenger(pchar, &characters[GetCharacterIndex("Edgar Attwood")]);
				ChangeCharacterAddressGroup(CharacterFromID("Edgar Attwood"), "Greenford_tavern", "goto", "goto5");
				Pchar.quest.Attwood_fight.win_condition.l1 = "location";
				Pchar.quest.Attwood_fight.win_condition.l1.character = "Blaze";
				Pchar.quest.Attwood_fight.win_condition.l1.location = "Greenford_tavern";
				PChar.quest.Attwood_fight.win_condition = "Attwood_fight";
			}
		break;

		case "Attwood_fight":
			DeleteAttribute(&Locations[FindLocation("Greenford_tavern")],"vcskip"); // NK
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "bocman", "goto", "goto17");
			sld.id = "guy_in_tavern";
			// NK -sld.skill.Fencing = "1";
			LAi_SetActorType(CharacterFromID("guy_in_tavern"));

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "bocman3", "goto", "goto6");
			sld.id = "guy_in_tavern1";
			// NK - sld.skill.Fencing = "1";
			LAi_SetActorType(CharacterFromID("guy_in_tavern1"));

			LAi_SetActorType(CharacterFromID("Edgar Attwood"));
			LAi_SetActorType(PChar);
			LAi_ActorWaitDialog(CharacterFromID("Edgar Attwood"), PChar);
			Characters[GetCharacterIndex("Edgar Attwood")].Dialog.Filename = "Edgar Attwood_dialog.c";
			Characters[GetCharacterIndex("Edgar Attwood")].dialog.currentnode = "Setup1";
			LAi_ActorDialog(PChar, CharacterFromID("Edgar Attwood"), "", 10, 10);

		break;

		case "Attwood_fight1":
			LAi_QuestDelay("Attwood_fight2", 0.01);
			characters[GetCharacterIndex("Edgar Attwood")].dialog.currentnode = "First time"; // NK
		break;

		case "Attwood_fight2":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false); // NK
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Edgar Attwood")); // NK was -1
			LAi_SetOfficerType(CharacterFromID("Edgar Attwood"));
			LAi_SetPlayerType(PChar);
			LAi_group_Register("bandits");
			LAi_group_MoveCharacter(CharacterFromID("guy_in_tavern"), "bandits");
			LAi_group_MoveCharacter(CharacterFromID("guy_in_tavern1"), "bandits");
			LAi_group_MoveCharacter(CharacterFromID("Edgar Attwood"), LAI_GROUP_PLAYER);
			LAi_group_FightGroups("bandits", LAI_GROUP_PLAYER, true);
// NK -->
			LAi_group_SetCheck("bandits", "Attwood_fight3");
		break;

		case "Attwood_fight3":
			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], true);
		break;
// NK <--

		case "Smugglers_fight1":
			LAi_QuestDelay("Smugglers_fight2", 0.01);
		break;

		case "Smugglers_fight2":
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Edgar Attwood")); // NK was -1
			LAi_SetOfficerType(CharacterFromID("Edgar Attwood"));
			LAi_SetPlayerType(PChar);
			LAi_group_Register("bandits");
			LAi_group_MoveCharacter(CharacterFromID("offended_sm"), "bandits");
			LAi_group_MoveCharacter(CharacterFromID("offended_sm1"), "bandits");
			LAi_group_MoveCharacter(CharacterFromID("offended_sm2"), "bandits");
			LAi_group_MoveCharacter(CharacterFromID("offended_sm3"), "bandits");
			LAi_group_MoveCharacter(CharacterFromID("Edgar Attwood"), LAI_GROUP_PLAYER);
			LAi_group_FightGroups("bandits", LAI_GROUP_PLAYER, true);
		break;

		case "Smugglers_fight3":
			LAi_QuestDelay("Smugglers_fight4", 0.01);
		break;

		case "Smugglers_fight4":
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Edgar Attwood")); // NK was -1
			LAi_SetOfficerType(CharacterFromID("Edgar Attwood"));
			LAi_SetPlayerType(PChar);
			LAi_group_Register("bandits");
			LAi_group_MoveCharacter(CharacterFromID("offended_sm"), "bandits");
			LAi_group_MoveCharacter(CharacterFromID("offended_sm1"), "bandits");
			LAi_group_MoveCharacter(CharacterFromID("offended_sm2"), "bandits");
			LAi_group_MoveCharacter(CharacterFromID("offended_sm3"), "bandits");
			LAi_group_MoveCharacter(CharacterFromID("Edgar Attwood"), "Good_boys");
			LAi_group_FightGroups("bandits", "Good_boys", true);
			ChangeSmugglerLiking(pchar, -20); //Smugglers like you less cause you killed some
		break;

		case "Pirates_fight1":
			LAi_QuestDelay("Pirates_fight2", 0.01);
		break;

		case "Pirates_fight2":
			LAi_SetPlayerType(PChar);
			LAi_group_Register("bandits");
			LAi_group_MoveCharacter(CharacterFromID("offended_pirate1"), "bandits");
			LAi_group_MoveCharacter(CharacterFromID("offended_pirate2"), "bandits");
			LAi_group_MoveCharacter(CharacterFromID("offended_pirate3"), "bandits");
			LAi_group_MoveCharacter(CharacterFromID("offended_pirate5"), "bandits");
			LAi_group_FightGroups("bandits", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("bandits", "Come_to_papa");
		break;

		case "Attwood_win":
			EndQuestMovie();TrackQuestMovie("end","Attwood_win");
		break;

		case "Attwood_listed":
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Edgar Attwood")); // NK was -1
			LAi_SetOfficerType(CharacterFromID("Edgar Attwood"));
		break;

		case "redmond_Attwood":
			if (!CharacterIsDead(&characters[GetCharacterIndex("Edgar Attwood")]))
			{
				if(FindFellowTravellers(PChar, CharacterFromId("Edgar Attwood")) == FELLOWTRAVEL_OFFICER)
				{
					RemovePassenger(pchar, &characters[GetCharacterIndex("Edgar Attwood")]);
// NK -->
					characters[GetCharacterIndex("Edgar Attwood")].blade = "";
					characters[GetCharacterIndex("Edgar Attwood")].location = "Redmond_store";
					ChangeCharacterAddress(characterFromID("Edgar Attwood"), "none", "");
					ChangeCharacterAddressGroup(CharacterFromID("Jack Greenfield"), "Redmond_tavern", "sit", "sit12");
					ChangeCharacterAddressGroup(CharacterFromID("Martin Warner"), "Redmond_tavern", "sit", "sit13");
// NK <--
					LAi_CharacterDisableDialog(CharacterFromID("Martin Warner"));
					characters[GetCharacterIndex("Redmond prison commendant")].dialog.currentnode = "continue2";
// NK -->
					ChangeCharacterAddressGroup(CharacterFromID("Roger Hayes"), "Redmond_tavern", "sit", "sit5");
					LAi_LocationFightDisable(&Locations[FindLocation("redmond_prison")], true);
					ChangeCharacterAddress(characterFromID("Redmond prison commendant"), "Redmond_prison", "sit1");
					characters[GetCharacterIndex("Redmond prison commendant")].location = "Redmond_prison";
					characters[GetCharacterIndex("Redmond prison commendant")].location.group = "sit";
					characters[GetCharacterIndex("Redmond prison commendant")].location.locator = "sit1";
					LAi_SetActorType(CharacterFromID("Redmond prison commendant"));
					LAi_SetSitType(CharacterFromID("Redmond prison commendant"));
// NK <--

// NK -->
					/*NK*/ sld = LAi_CreateFantomCharacter(true, 0, true, true, 0.25, "corsair2", "goto", "goto_43");
					LAi_SetActorType(sld);
					sld.id = "to_say1";
					sld.Dialog.Filename = "to_say1.c";
					LAi_ActorDialog(characterfromID("to_say1"), pchar, "", 10, 40);
// NK <--
				}
			}
		break;

		case "Let_my_edgar_go":
			SetCharacterToNearLocatorFromMe("Edgar Attwood", 10);
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Edgar Attwood")); // NK was -1
			LAi_SetOfficerType(CharacterFromID("Edgar Attwood"));
			ChangeCharacterAddress(characterFromID("Jack Greenfield"), "none", "");
			ChangeCharacterAddress(characterFromID("Martin Warner"), "none", "");
			Characters[GetCharacterIndex("Edgar Attwood")].dialog.Filename = "Enc_Officer_dialog.c"; // PB
			Characters[GetCharacterIndex("Edgar Attwood")].dialog.CurrentNode = "hired";
		break;

// NK -->
		case "Att_resit":
			LAi_Fade("Att_resit1", "Att_resit2");
		break;

		case "Att_resit1":
			ChangeCharacterAddressGroup(Pchar, "Redmond_tavern", "candles", "sit2");
			LAi_SetActorType(Pchar);
			LAi_ActorSetSitMode(Pchar);
		break;

		case "Att_resit2":
			LAi_ActorWaitDialog(CharacterFromID("Martin Warner"), Pchar);
			LAi_ActorDialog(Pchar, CharacterFromID("Martin Warner"), "", 0.001, 0.001);
		break;
// NK <--

		case "soldier_in_tavern0":
			LAi_QuestDelay("soldier_in_tavern", 0.01);
		break;

		case "soldier_in_tavern":
			LAi_ActorDialog(Pchar, CharacterFromID("Jack Greenfield"), "", 10, 4);
			LAi_Fade("soldier_in_tavern0.51", "soldier_in_tavern0.52");
		break;

		case "soldier_in_tavern0.51":
			ChangeCharacterAddressGroup(Pchar, "Redmond_tavern", "candles", "sit2"); // NK
			LAi_SetActorType(Pchar);
			LAi_SetActorType(CharacterFromID("Jack Greenfield"));
			LAi_ActorSetSitMode(CharacterFromID("Jack Greenfield"));
			LAi_SetActorType(CharacterFromID("Martin Warner"));
			LAi_ActorSetSitMode(CharacterFromID("Martin Warner"));
			LAi_ActorSetSitMode(Pchar); // NK
		break;

		case "soldier_in_tavern0.52":
			//LAi_ActorSetSitMode(Pchar); // NK
			LAi_ActorWaitDialog(CharacterFromID("Jack Greenfield"), Pchar);
			LAi_ActorDialog(Pchar, CharacterFromID("Jack Greenfield"), "", 10, 4);
		break;

		case "soldier_in_tavern1":
			LAi_QuestDelay("soldier_in_tavern2", 2);
		break;

		case "soldier_in_tavern2":
			LAi_ActorWaitDialog(CharacterFromID("Martin Warner"), Pchar);
			LAi_ActorDialog(Pchar, CharacterFromID("Martin Warner"), "", 10, 4);
		break;

		case "soldier_in_tavern3":
			LAi_ActorWaitDialog(CharacterFromID("Jack Greenfield"), Pchar);
			LAi_ActorDialog(Pchar, CharacterFromID("Jack Greenfield"), "", 10, 4);
		break;

		case "soldier_in_tavern4":
			LAi_ActorWaitDialog(CharacterFromID("Martin Warner"), Pchar);
			LAi_ActorDialog(Pchar, CharacterFromID("Martin Warner"), "", 10, 4);
	 	break;

		case "convoy":
			LAi_Fade("fight_with_convoy", "convoy_fight1");
		break;

		case "fight_with_convoy":
			ChangeCharacterAddressGroup(CharacterFromID("Jack Greenfield"), "none", "sit", "sit10");
			ChangeCharacterAddressGroup(CharacterFromID("Martin Warner"), "none", "sit", "sit5");

			DoQuestReloadToLocation("redmond_port", "goto", "goto_2", "_");
		break;

		case "convoy_fight1":
// NK -->
			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "goto_54"); // PB
			LAi_SetActorType(sld);
			sld.id = "sold1";

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "goto_51"); // PB
			LAi_SetActorType(sld);
			sld.id = "sold2";

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m4, "goto", "goto_50"); // PB
			LAi_SetActorType(sld);
			sld.id = "sold3";

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m5, "goto", "goto_53"); // PB
			LAi_SetActorType(sld);
			sld.id = "sold4";

			/*NK*/ sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[ENGLAND].fantomModel.m6, "goto", "goto_52"); // PB
			LAi_SetActorType(sld);
			sld.id = "sold5";

			LAi_SetActorType(CharacterFromID("Edgar Attwood"));
			LAi_SetActorType(CharacterFromID("zek"));
			LAi_SetActorType(CharacterFromID("zek2"));
			ChangeCharacterAddressGroup(CharacterFromID("Edgar Attwood"), "Redmond_port", "goto", "goto_53");
			ChangeCharacterAddressGroup(CharacterFromID("zek2"), "Redmond_port", "goto", "goto_51");
			ChangeCharacterAddressGroup(CharacterFromID("zek"), "Redmond_port", "goto", "goto_50");
// NK <--

			LAi_ActorGoToLocator(CharacterFromID ("Edgar Attwood"), "goto", "goto_34", "Edgar_is_on_board", -1);
			LAi_ActorGoToLocator(CharacterFromID ("zek2"), "goto", "goto_34", "Edgar_is_on_board", -1);
			LAi_ActorGoToLocator(CharacterFromID ("zek"), "goto", "goto_34", "Edgar_is_on_board", -1);
			LAi_ActorGoToLocator(CharacterFromID ("sold5"), "goto", "goto_34", "Edgar_is_on_board", -1);
			LAi_ActorGoToLocator(CharacterFromID ("sold4"), "goto", "goto_34", "Edgar_is_on_board", -1);
			LAi_ActorGoToLocator(CharacterFromID ("sold3"), "goto", "goto_34", "Edgar_is_on_board", -1);
			LAi_ActorGoToLocator(CharacterFromID ("sold2"), "goto", "goto_34", "Edgar_is_on_board", -1);
			LAi_ActorGoToLocator(CharacterFromID ("sold1"), "goto", "goto_34", "Edgar_is_on_board", -1);

			LAi_group_MoveCharacter(CharacterFromID ("sold5"), "convoy");
			LAi_group_MoveCharacter(CharacterFromID ("sold4"), "convoy");
			LAi_group_MoveCharacter(CharacterFromID ("sold3"), "convoy");
			LAi_group_MoveCharacter(CharacterFromID ("sold2"), "convoy");

			LAi_SetActorType(Pchar);
			LAi_QuestDelay("make_player", 1);
		break;

		case "make_player":
			LAi_SetPlayerType(Pchar);

			LAi_SetCheckMinHP(CharacterFromID ("sold1"), 0.875*LAi_GetCharacterHP(characterFromID("sold1")), false, "convoy_is_angry"); // KK
			LAi_SetCheckMinHP(CharacterFromID ("sold2"), 0.875*LAi_GetCharacterHP(characterFromID("sold2")), false, "convoy_is_angry"); // KK
			LAi_SetCheckMinHP(CharacterFromID ("sold3"), 0.875*LAi_GetCharacterHP(characterFromID("sold3")), false, "convoy_is_angry"); // KK
			LAi_SetCheckMinHP(CharacterFromID ("sold4"), 0.875*LAi_GetCharacterHP(characterFromID("sold4")), false, "convoy_is_angry"); // KK
			LAi_SetCheckMinHP(CharacterFromID ("sold5"), 0.875*LAi_GetCharacterHP(characterFromID("sold5")), false, "convoy_is_angry"); // KK
		break;

		case "Edgar_is_on_board":
			WaitDate("", 0, 0, 0, 0, 1);
			pchar.location.from_sea = "Redmond_port";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
			PlaceFleetNearShore(pchar.location.from_sea); // KK

			Group_CreateGroup("Jack Greenfield");
			Group_AddCharacter("Jack Greenfield", "Jack Greenfield");
			characters[GetCharacterIndex("Jack Greenfield")].nosurrender = 2; // 05-07-06 no surrender at sea. Makes life easier. // KK
			Group_SetGroupCommander("Jack Greenfield", "Jack Greenfield");
			Group_SetTaskMove("Jack Greenfield", 10000, 10000);
			Group_SetPursuitGroup("Jack Greenfield", PLAYER_GROUP);
			Group_SetAddress("Jack Greenfield", "redmond", "", "");

			TeleportCharacterFromCurLocationToLocation("sea_1_back", "", "");

			Pchar.quest.Battle.win_condition.l1 = "NPC_Death";
			Pchar.quest.Battle.win_condition.l1.character = "Jack Greenfield";
			PChar.quest.Battle.win_condition = "list_Attwood";
		break;

		case "list_Attwood":
//			if (characters[GetCharacterIndex("Jack Greenfield")].Killer.status == KILL_BY_ABORDAGE)  //TALISMAN - remove to enable Edgar Attwood to be rescued from Prison Ship
//			{  //TALISMAN - remove to enable Edgar Attwood to be rescued from Prison Ship
// NK -->
			Log_SetStringToLog(TranslateString("","You rescued Edgar Attwood!"));
			SetCharacterShipLocation(CharacterFromID("Jack Greenfield"), "none" );
// NK <--
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Edgar Attwood")); // NK was -1
			LAi_SetOfficerType(CharacterFromID("Edgar Attwood"));
			Characters[GetCharacterIndex("Edgar Attwood")].dialog.Filename = "Enc_Officer_dialog.c"; // PB
			Characters[GetCharacterIndex("Edgar Attwood")].dialog.CurrentNode = "hired";
//			}  //TALISMAN - remove to enable Edgar Attwood to be rescued from Prison Ship
		break;

		case "convoy_is_angry":
			LAi_group_MoveCharacter(CharacterFromID ("sold5"), "convoy");
			LAi_group_MoveCharacter(CharacterFromID ("sold4"), "convoy");
			LAi_group_MoveCharacter(CharacterFromID ("sold3"), "convoy");
			LAi_group_MoveCharacter(CharacterFromID ("sold2"), "convoy");
			LAi_group_MoveCharacter(CharacterFromID ("sold1"), "convoy");
			LAi_type_actor_Reset(CharacterFromID ("sold2"));
			LAi_type_actor_Reset(CharacterFromID ("sold1"));
			LAi_type_actor_Reset(CharacterFromID ("sold3"));
			LAi_type_actor_Reset(CharacterFromID ("sold4"));
			LAi_type_actor_Reset(CharacterFromID ("sold5"));
			LAi_RemoveCheckMinHP(CharacterFromID ("sold1"));
			LAi_RemoveCheckMinHP(CharacterFromID ("sold2"));
			LAi_RemoveCheckMinHP(CharacterFromID ("sold3"));
			LAi_RemoveCheckMinHP(CharacterFromID ("sold4"));
			LAi_RemoveCheckMinHP(CharacterFromID ("sold5"));
			LAi_type_actor_Reset(CharacterFromID ("Edgar Attwood"));
			LAi_type_actor_Reset(CharacterFromID ("zek"));
			LAi_type_actor_Reset(CharacterFromID ("zek2"));
			LAi_group_FightGroups("convoy", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("convoy", "list_Attwood2");

			Pchar.quest.attwood_remove_zeks.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.attwood_remove_zeks.win_condition.l1.location = pchar.location;
			Pchar.quest.attwood_remove_zeks.win_condition = "attwood_remove_zeks";
		break;

		case "attwood_remove_zeks":
			ChangeCharacterAddress(characterFromID("zek"), "none", "");
			ChangeCharacterAddress(characterFromID("zek2"), "none", "");
		break;

		case "list_Attwood2":
// NK -->
			SetCharacterShipLocation(CharacterFromID("Jack Greenfield"), "none" );
			Log_SetStringToLog(TranslateString("","You rescued Edgar Attwood!"));
// NK <--
			SetOfficersIndex(Pchar, 3, GetCharacterIndex("Edgar Attwood")); // NK was -1
			LAi_SetOfficerType(CharacterFromID("Edgar Attwood"));
			Characters[GetCharacterIndex("Edgar Attwood")].dialog.Filename = "Enc_Officer_dialog.c"; // PB
			Characters[GetCharacterIndex("Edgar Attwood")].dialog.CurrentNode = "hired";
		break; //NK <--


///////////////////////////////////////////////////////////////
///// SINKING THE VOGELSTRUIJS
///////////////////////////////////////////////////////////////

		case "birdwatch":
			AddMoneyToCharacter(PChar, 2500);
			SetQuestHeader("Vogelstruijs");
			AddQuestRecord("Vogelstruijs", 1);
			pchar.quest.birdwatch2.win_condition.l1 = "location";
			pchar.quest.birdwatch2.win_condition.l1 = "location";
			pchar.quest.birdwatch2.win_condition.l1.location = "Douwesen_port";
			pchar.quest.birdwatch2.win_condition = "birdwatch2";
			Characters[GetCharacterIndex("Contre-Amirale")].birdwatch2 = true; // PB: Avoid this quest being given again
		break;

		case "birdwatch2":
           	ChangeCharacterAddressGroup(characterFromID("Docker"), "Douwesen_port", "goto", "goto15");
			LAi_SetActorType(characterFromID("Docker"));
			Characters[GetCharacterIndex("Docker")].dialog.currentnode = "question";
			LAi_ActorDialog(characterFromID("Docker"),PChar,"",5.0,5.0);
		break;

		case "birdsearch":
			AddQuestRecord("Vogelstruijs", 2);
			Locations[FindLocation("Dutch_Smuggler_Home")].vcskip = true;
			Locations[FindLocation("Douwesen_town")].reload.l12.disable = false;
			pchar.quest.birdsearch1.win_condition.l1 = "location";
			pchar.quest.birdsearch1.win_condition.l1 = "location";
			pchar.quest.birdsearch1.win_condition.l1.location = "Dutch_Smuggler_Home";
			pchar.quest.birdsearch1.win_condition = "birdsearch1";
		break;

		case "birdsearch1":
			Pchar.Temp.self.dialog = Pchar.dialog.currentnode;
			LAi_SetActorType(pchar);
			Pchar.dialog.filename = "LaCroix_dialog.c";
			Pchar.dialog.currentnode = "logbook";
			LAi_ActorSelfDialog(Pchar, "player_back");
		//	LAi_QuestDelay("learn about smugglers", 0.0); //Levis, GR: Disabled this here
		break;

		case "birdsearch2":
			LAi_SetActorType(pchar);
			LAi_ActorGoToLocator(pchar, "goto", "goto2", "birdsearch3", 2.0);
		break;

		case "birdsearch3":
			AddQuestRecord("Vogelstruijs", 3);
			GiveItem2Character(Pchar, "SpanishLetter");
			LAi_SetActorType(pchar);
			Pchar.dialog.filename = "LaCroix_dialog.c";
			Pchar.dialog.currentnode = "logbook2";
			LAi_ActorSelfDialog(Pchar, "player_back");
		break;

		case "birdsearch4":
			LAi_SetPlayerType(pchar);
           	ChangeCharacterAddressGroup(characterFromID("Skipper Wife"), "Dutch_Smuggler_Home", "reload", "reload2");
			LAi_SetActorType(characterFromID("Skipper Wife"));
			LAi_ActorGoToLocator(CharacterFromID("Skipper Wife"), "goto", "goto3", "busted", 10.0);
		break;

		case "busted":
			LAi_SetActorType(characterFromID("Skipper Wife"));
			Characters[GetCharacterIndex("Skipper Wife")].dialog.currentnode = "what_are_you_doing";
			LAi_ActorDialog(characterFromID("Skipper Wife"), pchar, "", 10.0, 10.0);
		break;

		case "callguards":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[GetCurrentLocationNation()].fantomModel.m4, "reload", "reload1"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetGuardianType(sld);
			LAi_group_MoveCharacter(sld, "HOLLAND_GUARDS");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[GetCurrentLocationNation()].fantomModel.m5, "reload", "reload1"); // PB
			LAi_SetHP(sld, 80.0, 80.0);
			LAi_SetGuardianType(sld);
			LAi_group_MoveCharacter(sld, "HOLLAND_GUARDS");

			LAi_group_SetRelation("HOLLAND_GUARDS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("HOLLAND_GUARDS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("HOLLAND_GUARDS", "toadmiral");

			LAi_SetActorType(characterFromID("Skipper Wife"));
			LAi_ActorRunToLocator(CharacterFromID("Skipper Wife"), "reload", "reload2", "", 10.0);
			ChangeCharacterAddressGroup(characterFromID("Skipper Wife"), "none", "", "");
			SetRMRelation(PChar, HOLLAND, REL_WAR);
			AddQuestRecord("Vogelstruijs", 4);
		break;

		case "lovertrouble":
           	ChangeCharacterAddressGroup(characterFromID("Cheater"), "Dutch_Smuggler_Home", "reload", "reload2");
			LAi_SetActorType(characterFromID("Cheater"));
			LAi_ActorGoToLocator(CharacterFromID("Cheater"), "goto", "goto3", "lovertrouble2", 2.0);
		break;

		case "lovertrouble2":
			LAi_SetActorType(characterFromID("Cheater"));
			Characters[GetCharacterIndex("Cheater")].dialog.currentnode = "lover";
			LAi_ActorDialog(characterFromID("Cheater"), pchar, "", 10.0, 1.0);
		break;

		case "killerattack":
			LAi_SetActorType(characterFromID("Skipper Wife"));
			LAi_ActorRunToLocator(CharacterFromID("Skipper Wife"), "reload", "reload2", "", 2.0);
           	ChangeCharacterAddressGroup(characterFromID("Skipper Wife"), "none", "", "");
			LAi_ActorAttack(CharacterFromID("Cheater"), Pchar, "");
			pchar.quest.toadmiral.win_condition.l1 = "NPC_Death";
			pchar.quest.toadmiral.win_condition.l1.character = "Cheater";
			pchar.quest.toadmiral.win_condition = "toadmiral";
			AddQuestRecord("Vogelstruijs", 5);
		break;

		case "killher":
			ChangeCharacterReputation(pchar, -10);
			LAi_ActorAttack(CharacterFromID("Skipper Wife"), Pchar, "");
			pchar.quest.toadmiral.win_condition.l1 = "NPC_Death";
			pchar.quest.toadmiral.win_condition.l1.character = "Skipper Wife";
			pchar.quest.toadmiral.win_condition = "toadmiral";
			AddQuestRecord("Vogelstruijs", 6);
		break;

		case "gold":
			ChangeCharacterReputation(pchar, -5);
			AddMoneyToCharacter(PChar, 500);
			GiveItem2Character(Pchar, "jewelry1");
			GiveItem2Character(Pchar, "jewelry10");
			GiveItem2Character(Pchar, "jewelry14");
			pchar.quest.toadmiral.win_condition.l1 = "location";
			pchar.quest.toadmiral.win_condition.l1 = "location";
			pchar.quest.toadmiral.win_condition.l1.location = "Douwesen_town";
			pchar.quest.toadmiral.win_condition = "toadmiral";
			AddQuestRecord("Vogelstruijs", 7);
		break;

		case "toadmiral":
			AddQuestRecord("Vogelstruijs", 8);
			Characters[GetCharacterIndex("Contre-Amirale")].dialog.CurrentNode = "letter";
		break;

		case "birdhunt":
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Havana"), "PoPrince_town", "reload", "reload13");
			Characters[GetCharacterIndex("Crewmember_Havana")].dialog.CurrentNode = "what_shall_we_do";
			
			pchar.quest.birdhunt_start.win_condition.l1 = "location";
			pchar.quest.birdhunt_start.win_condition.l1.location = "PoPrince_town";
			pchar.quest.birdhunt_start.win_condition = "birdhunt_start";
		break;

		case "birdhunt_start":
			LAi_SetActorType(CharacterFromID("Crewmember_Havana"));
			LAi_ActorFollow(CharacterFromID("Crewmember_Havana"), PChar, "birdhunt2", -1);
		break;

		case "birdhunt2":
			LAi_ActorDialog(characterFromID("Crewmember_Havana"), PChar, "", -1, 0.0);
		break;

		case "birdhunt3":
			bQuestDisableMapEnter = true;
		//	UpdateRelations(); // PB: Doesn't do anything
			Group_CreateGroup("Skipper1");
			Group_AddCharacter("Skipper1", "Skipper1");
			Group_SetGroupCommander("Skipper1", "Skipper1");
			Group_SetTaskNone("Skipper1");
			Group_LockTask("Skipper1");
			Group_SetAddress("Skipper1", "Hispaniola", "Quest_ships", "quest_ship_6");
			Sea_LoginGroupNow("Skipper1");
			characters[GetCharacterIndex("Skipper")].nosurrender = 2;
		//	SetCharacterRelationBoth(GetCharacterIndex("Skipper1"),GetMainCharacterIndex(),RELATION_ENEMY); // PB: Doesn't do anything
		//	if(GetRMRelation(PChar, HOLLAND) > REL_WAR) SetRMRelation(PChar, HOLLAND, REL_WAR);
			Character_SetAbordageEnable(characterFromID("Skipper1"), false);

			Pchar.quest.birdboarding.win_condition.l1 = "Ship_HP";
			Pchar.quest.birdboarding.win_condition.l1.character = "Skipper1";
			Pchar.quest.birdboarding.win_condition.l1.quantity = 3500;
			Pchar.quest.birdboarding.win_condition.l1.operation = "<";
			Pchar.quest.birdboarding.win_condition = "birdboarding";
			PChar.QuestsCheck = true; // PB: Enable checking quest status every minute at sea
		break;

		case "birdboarding":
			ChangeCharacterAddressGroup(CharacterFromID("Crewmember_Havana"), "VogelStruijs", "rld", "aloc3");
			ChangeCharacterAddressGroup(CharacterFromID("Skipper"), "VogelStruijs", "rld", "loc1");
			DoQuestReloadToLocation("VogelStruijs", "rld", "aloc2","birdboarding1-2");
			bQuestDisableMapEnter = false; //CTM
			DeleteAttribute(PChar, "QuestsCheck"); // PB: Stop the check again for performance reasons
		break;

		case "birdboarding1-2":
			Characters[GetCharacterIndex("Crewmember_Havana")].dialog.CurrentNode = "blow_up";
			LAi_SetActorType(characterFromID("Crewmember_Havana"));
			LAi_ActorDialog(characterFromID("Crewmember_Havana"), pchar, "", 3.0, 1.0);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor", "rld", "aloc12");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor1", "rld", "aloc14");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "will_2", "rld", "aloc9");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor2", "rld", "aloc4");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "sailor5", "rld", "aloc5");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "Sailor16", "rld", "aloc8");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, LAI_GROUP_PLAYER);

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "rabWhite", "rld", "loc12");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, "CREW_VOGEL");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat6", "rld", "loc14");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, "CREW_VOGEL");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "pirat9", "rld", "loc9");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, "CREW_VOGEL");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "man6", "rld", "loc4");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, "CREW_VOGEL");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "man1_2", "rld", "loc5");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, "CREW_VOGEL");

			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "fatman", "rld", "loc8");
			LAi_SetHP(sld, 180.0, 180.0);
			LAi_group_MoveCharacter(sld, "CREW_VOGEL");

			LAi_group_FightGroups("CREW_VOGEL", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("CREW_VOGEL", "birdboarding3");
		break;

		case "birdboarding3":
			LAi_SetActorType(characterFromID("Skipper"));
			Characters[GetCharacterIndex("Skipper")].dialog.CurrentNode = "how";
			LAi_ActorDialog(characterFromID("Skipper"), pchar, "", 10.0, 10.0);
		break;

		case "birdboarding4":
			LAi_ActorAttack(CharacterFromID("Skipper"), Pchar, "");
			pchar.quest.toadmiral.win_condition.l1 = "NPC_Death";
			pchar.quest.toadmiral.win_condition.l1.character = "Skipper";
			pchar.quest.toadmiral.win_condition = "birdhold";
		break;

		case "birdhold":
			ChangeSmugglerLiking(pchar, -20);
			DoQuestReloadToLocation("VogelStruijs_Hold", "reload", "reload1","birdblow");
		break;

		case "birdblow":
			LAi_SetActorType(pchar);
			Pchar.dialog.filename = "LaCroix_dialog.c";
			Pchar.dialog.currentnode = "blow_it";
			LAi_ActorSelfDialog(Pchar, "player_back");
			pchar.quest.birdblow2.win_condition.l1 = "locator";
			pchar.quest.birdblow2.win_condition.l1.location = "VogelStruijs_Hold";
			pchar.quest.birdblow2.win_condition.l1.locator_group = "box";
			pchar.quest.birdblow2.win_condition.l1.locator = "gunpowder_1";
			pchar.quest.birdblow2.win_condition = "birdblow2";
		break;

		case "birdblow2":
			PlayStereoSound("NATURE\fireplace1.wav");
			CreateParticleSystemX("fireball", -1.68, 12.04, -8.04, -1.57, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", -1.68, 12.04, -8.04, -1.57, 0.0, 0.0,0);
			LAi_SetActorType(pchar);
			Pchar.dialog.filename = "LaCroix_dialog.c";
			Pchar.dialog.currentnode = "run";
			LAi_ActorSelfDialog(Pchar, "player_back");
		break;

		case "birdfly":
			QuestToSeaLogin_PrepareLoc("Hispaniola", "reload", "reload_2", true);
			QuestToSeaLogin_Launch();
			DoQuestCheckDelay("birdfly2", 5.0);
        break;

        case "birdfly2":
            SeaAI_SailToCharacter(GetCharacterIndex("Skipper1"));
            Ship_Detonate(characterFromID("Skipper1"), true, true);
            RestoreOfficers(pchar.id);
			DoQuestCheckDelay("birdsinks", 12.0);
        break;

        case "birdsinks":
			characters[GetCharacterindex("Skipper1")].ship.hp = 0;
			AddQuestRecord("Vogelstruijs", 9);
			Characters[GetCharacterIndex("Contre-Amirale")].dialog.currentnode = "weldone1";
        break;

		case "free_to_go":
			AddMoneyToCharacter(PChar, 2500);
			AddQuestRecord("Vogelstruijs", 10);
			CloseQuestHeader("Vogelstruijs");
			Characters[GetCharacterIndex("Contre-Amirale")].dialog.currentnode = "nothing";
			ItemSetPrice("SpanishLetter", 1);	// GR: can now dump letter into a chest

			Pchar.quest.Remove_Amirale.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.Remove_Amirale.win_condition.l1.location = pchar.location;
			Pchar.quest.Remove_Amirale.win_condition = "Remove_Amirale";
		break;

		case "Remove_Amirale":
			ChangeCharacterAddress(characterFromID("Contre-Amirale"), "none", "");
		break;

///////////////////////////////////////////////////////////////
///// Job at Martinique Shipyard
///////////////////////////////////////////////////////////////
		case "martinique_shipyard_work":
			PlayStereoSound("AMBIENT\SHIPYARD\saw.wav");
			waitdate("", 0, 0, 3, 0, 0);
			SetCurrentTime(10.00, 0);
			LAi_Fade("", "");
			Logit(TranslateString("","Three days later..."));
			if(AUTO_SKILL_SYSTEM) AddPartyExpChar(pchar, "Repair", 500);
			else AddPartyExp(pchar, 500);
			Characters[GetCharacterIndex("Jean Filaut")].dialog.currentnode = "job_done";
		break;

		case "danielle_end_exit": //PW new case to allow Sabine to exit from store after female pchar allows her on ship

			LAi_SetActorType(CharacterFromID("Sabine Matton")); // PW Sabine to leave
			LAi_ActorRunToLocation(CharacterFromID("Sabine Matton"), "Reload", "Reload1", "None", "", "", "", 120); // PW Sabine leaves
		break;

		case "Sabines_new_outfit": //GR: Sabine Matton is now your officer and gets shipboard clothes
			if (GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS)
			{
				SetModelfromID(CharacterFromID("Sabine Matton"), "SabineM3");
				GiveModel2Player("towngirl1_2", false); // GR: Get original dress as well
			}
			else
			{
				SetModelfromID(CharacterFromID("Sabine Matton"), "SabineM2");
				GiveModel2Player("towngirl1", false); // GR: Get Sabine's original dress as well
			}
		break;

///////////////////////////////////////////////////////////////////////
// The Kapitein of Kralendijk
// By Grey Roger
// Based very loosely on the real life story of the Captain of Köpenick
///////////////////////////////////////////////////////////////////////
		case "Kapitein_follow_proposer_upstairs":
			ChangeCharacterAddressGroup(characterFromID("Willem Voigt"), "Philipsburg_tavern", "tables", "table5");
			LAi_SetActorType(characterFromID("Willem Voigt"));
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocation(CharacterFromID("Willem Voigt"), "reload", "reload2", "none", "", "", "", 10.0);
			LAi_QuestDelay("Kapitein_follow_proposer_upstairs2", 1.0);
		break;

		case "Kapitein_follow_proposer_upstairs2":
			LAi_ActorGoToLocation(PChar, "reload", "reload2", "none", "", "", "Kapitein_in_room_with_proposer", 5.0);
		break;

		case "Kapitein_in_room_with_proposer":
			locations[FindLocation("Philipsburg_tavern_upstairs")].reload.l1.disable = 1;
			DisableFastTravel(true);
			DoQuestReloadToLocation("Philipsburg_tavern_upstairs", "reload", "reload1", "Kapitein_in_room_with_proposer2");
		break;
		
		case "Kapitein_in_room_with_proposer2":
			LAi_SetActorType(characterFromID("Willem Voigt"));
			ChangeCharacterAddressGroup(characterFromID("Willem Voigt"), "Philipsburg_tavern_upstairs", "goto", "goto4");
			LAi_ActorFollow(pchar, characterFromID("Willem Voigt"), "Kapitein_in_room_with_proposer3", 2.0);
		break;

		case "Kapitein_in_room_with_proposer3":
			LAi_SetPlayerType(PChar);
			Characters[GetCharacterIndex("Willem Voigt")].dialog.CurrentNode = "propose_job";
			LAi_ActorDialog(characterFromID("Willem Voigt"), PChar, "Kapitein_open_upstairs_door",1.0,1.0);	// Exits to "Kapitein_job_accepted" or "Kapitein_permanent_refusal"
		break;

		case "Kapitein_open_upstairs_door":
			LAi_SetStayType(characterFromID("Willem Voigt"));
			locations[FindLocation(PChar.location)].reload.l1.disable = 0;
			DisableFastTravel(false);
		break;

		case "Kapitein_setup_proposer_leaves":	// Triggered by dialog with Willem Voigt
			Pchar.quest.Kapitein_proposer_vanishes.win_condition.l1 = "ExitFromLocation";
			PChar.quest.Kapitein_proposer_vanishes.win_condition.l1.location = PChar.location;
			Pchar.quest.Kapitein_proposer_vanishes.win_condition = "Kapitein_proposer_vanishes";
		break;

		case "Kapitein_proposer_vanishes":
			DisableFastTravel(false);
			AddQuestRecord("fleece", 2);
			CloseQuestHeader("fleece");
			ChangeCharacterAddress(characterFromID("Willem Voigt"), "None", "");
		break;

		case "Kapitein_job_accepted":		// Triggered by dialog with Willem Voigt
			DisableFastTravel(true);
			Pchar.quest.Kapitein_proposer_vanishes.over = "yes";
			LAi_SetActorType(characterFromID("Willem Voigt"));
			LAi_ActorFollowEverywhere(CharacterFromID("Willem Voigt"), "", 1.0);
			LAi_SetImmortal(characterfromID("Willem Voigt"), true);
			pchar.quest.Kapitein_land_exit.win_condition.l1 = "location";
			pchar.quest.Kapitein_land_exit.win_condition.l1.location = "Philipsburg_exit";
			pchar.quest.Kapitein_land_exit.win_condition = "Kapitein_gate_exit";
			pchar.quest.Kapitein_port_exit.win_condition.l1 = "location";
			pchar.quest.Kapitein_port_exit.win_condition.l1.location = "Philipsburg_port";
			pchar.quest.Kapitein_port_exit.win_condition = "Kapitein_gate_exit";
			pchar.quest.Kapitein_dungeon_entrance.win_condition.l1 = "locator";
			pchar.quest.Kapitein_dungeon_entrance.win_condition.l1.location = "Philipsburg_town";
			pchar.quest.Kapitein_dungeon_entrance.win_condition.l1.locator_group = "reload";
			pchar.quest.Kapitein_dungeon_entrance.win_condition.l1.locator = "Reload10";
			pchar.quest.Kapitein_dungeon_entrance.win_condition = "Kapitein_dungeon_entrance";
		break;

		case "Kapitein_gate_exit":
			pchar.quest.Kapitein_land_exit.over = "yes";
			pchar.quest.Kapitein_port_exit.over = "yes";
			pchar.quest.Kapitein_dungeon_entrance.over = "yes";
			StartQuestMovie(true, true, false);
			if (PChar.location == "Philipsburg_port") sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[HOLLAND].fantomModel.m0, "goto", "goto1");
			else sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, Nations[HOLLAND].fantomModel.m0, "goto", "locator5");
			GiveSoldierWeapon(sld, HOLLAND);
			sld.id = "Laurens-Jan Revenboer";
			sld.nation = HOLLAND;
			sld.name 	= "Laurens-Jan";
			sld.lastname 	= "Revenboer";

			LAi_SetImmortal(characterfromID("Laurens-Jan Revenboer"), true);
			LAi_SetActorType(characterFromID("Laurens-Jan Revenboer"));
			Characters[GetCharacterIndex("Laurens-Jan Revenboer")].dialog.Filename = "kapitein_guards_dialog.c";
			Characters[GetCharacterIndex("Laurens-Jan Revenboer")].dialog.CurrentNode = "arrest_willem";
			LAi_ActorDialog(characterFromID("Laurens-Jan Revenboer"),PChar,"kapitein_arrest_willem_answers",5.0,5.0);
		break;

		case "kapitein_arrest_willem_answers":
			LAi_SetPlayerType(PChar);
			Characters[GetCharacterIndex("Willem Voigt")].dialog.CurrentNode = "confirm_story";
			LAi_ActorDialog(characterFromID("Willem Voigt"), PChar, "Kapitein_officer_knows_scam",1.0,1.0);
		break;

		case "Kapitein_officer_knows_scam":
			Characters[GetCharacterIndex("Laurens-Jan Revenboer")].dialog.CurrentNode = "know_about_scam";
			LAi_ActorDialog(characterFromID("Laurens-Jan Revenboer"),PChar,"kapitein_willem_arrested",5.0,5.0);
		break;

		case "kapitein_willem_arrested":
			EndQuestMovie();
			if (PChar.location == "Philipsburg_port")
			{
				LAi_ActorGoToLocation(CharacterFromID("Laurens-Jan Revenboer"), "reload", "reload4", "none", "", "", "", 30);
				LAi_ActorGoToLocation(CharacterFromID("Willem Voigt"), "reload", "reload4", "none", "", "", "", 30);
			}
			else
			{
				LAi_ActorGoToLocation(CharacterFromID("Laurens-Jan Revenboer"), "reload", "reload2", "none", "", "", "", 30);
				LAi_ActorGoToLocation(CharacterFromID("Willem Voigt"), "reload", "reload2", "none", "", "", "", 30);
			}
			AddQuestRecord("fleece", 4);
			CloseQuestHeader("fleece");
			PChar.quest.kapitein = "willem_arrested";
			LAi_QuestDelay("kapitein_should_I_do_it", 2.0);
			Pchar.quest.Kapitein_remove_proposer.win_condition.l1 = "ExitFromLocation";
			PChar.quest.Kapitein_remove_proposer.win_condition.l1.location = PChar.location;
			Pchar.quest.Kapitein_remove_proposer.win_condition = "Kapitein_remove_proposer";
		break;

		case "Kapitein_dungeon_entrance":
			LAi_SetActorType(characterFromID("Willem Voigt"));
			Characters[GetCharacterIndex("Willem Voigt")].dialog.CurrentNode = "not_going_in";
			LAi_ActorDialogNow(characterFromID("Willem Voigt"), PChar, "Kapitein_resume_following",1.0);
			Pchar.quest.Kapitein_in_dungeon.win_condition.l1 = "Location";
			PChar.quest.Kapitein_in_dungeon.win_condition.l1.location = "Philipsburg_dungeon";
			Pchar.quest.Kapitein_in_dungeon.win_condition = "Kapitein_in_dungeon";
		break;

		case "Kapitein_resume_following":
			LAi_SetActorType(characterFromID("Willem Voigt"));
			LAi_ActorFollowEverywhere(CharacterFromID("Willem Voigt"), "", 10.0);
		break;

		case "Kapitein_in_dungeon":
			pchar.quest.Kapitein_land_exit.over = "yes";
			pchar.quest.Kapitein_port_exit.over = "yes";
			PChar.quest.kapitein = "willem_dungeon";
			AddQuestRecord("fleece", 6);
			CloseQuestHeader("fleece");
			LAi_SetCitizenType(characterFromID("Willem Voigt"));
			ChangeCharacterAddress(characterFromID("Willem Voigt"), "None", "");
			LAi_QuestDelay("kapitein_should_I_do_it", 2.0);
		break;

		case "Kapitein_remove_proposer":
			ChangeCharacterAddress(characterFromID("Willem Voigt"), "None", "");
		break;

		case "kapitein_should_I_do_it":
			DisableFastTravel(false);
			PChar.dialog.filename = "blaze_dialog.c";
			Pchar.dialog.CurrentNode = "kapitein_decision";
			LAi_SetActorType(PChar);
			LAi_ActorSelfDialog(PChar, "player_back");	// Exits to "kapitein_start_quest" if you want to go ahead, otherwise just exits
		break;

		case "kapitein_start_quest":
			LAi_SetPlayerType(PChar);
			SetQuestHeader("kapitein");
			if (CheckQuestAttribute("kapitein", "willem_arrested")) AddQuestRecord("kapitein", 1);
			if (CheckQuestAttribute("kapitein", "willem_dungeon")) AddQuestRecord("kapitein", 2);
			AddQuestRecord("kapitein", 3);
			PChar.quest.kapitein = "start";		// Attribute will be recognised by Dutch tavern guards
		break;

		case "Kapitein_with_soldier_to_room":
			string kapitein_location = PChar.location;
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -150);
			PChar.quest.kapitein = "start";
			DoQuestReloadToLocation(kapitein_location + "_upstairs", "goto", "goto2", "Kapitein_with_soldier_to_room2");
		break;

		case "Kapitein_with_soldier_to_room2":
			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, PChar.quest.kapitein.soldier_model, "goto", "goto4");	// Create drunk soldier in uniform
//			sld = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "man5", "goto", "goto4");					// Create drunk soldier without uniform, you've stolen it
			LAi_SetLayType(sld);
			sld.name = PChar.quest.kapitein.soldier_name;
			sld.lastname = PChar.quest.kapitein.soldier_last_name;
			sld.id = "Drunken soldier";
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "goto", "goto4");
			LAi_QuestDelay("Kapitein_with_soldier_to_room3", 1.0);
		break;

		case "Kapitein_with_soldier_to_room3":
			PChar.dialog.filename = "blaze_dialog.c";
			Pchar.dialog.CurrentNode = "kapitein_steal_uniform";
			LAi_SetActorType(PChar);
			LAi_ActorSelfDialog(PChar, "Kapitein_take_uniform");
		break;

		case "Kapitein_take_uniform":
			if (CheckAttribute(PChar, "clothes." + PChar.quest.kapitein.soldier_model)) PChar.quest.kapitein_already_got_uniform = "true";
			else GiveModel2Player(PChar.quest.kapitein.soldier_model, false);
			SetModelfromID(CharacterFromID("Drunken soldier"), "man5");
			LAi_SetPlayerType(PChar);
			PChar.quest.kapitein = "tailor";
			AddQuestRecord("kapitein", 4);
		break;

		case "Kapitein_need_papers":		// Triggered by dialog with Kralendijk tailor
			PChar.quest.kapitein = "need_papers";
			if (checkquestattribute("church_help", "Yedam") && !LAi_IsDead(characterFromID("Yedam Kinne"))) 
			{
				Characters[GetCharacterIndex("Yedam Kinne")].dialog.currentnode = "return_visit";				
				AddQuestRecord("kapitein", 5);
			}
			else
			{
				if (CheckAttribute(CharacterFromID("Pablo Escriva"), "already_met")) AddQuestRecord("kapitein", 6);
				else AddQuestRecord("kapitein", 7);
			}
		break;

		case "kapitein_wait_for_papers":	// Triggered by dialog with Yedam Kinne - quicker than Pablo Escriva because Yedam is from Kralendijk
			PChar.quest.kapitein_yedam_papers_ready.win_condition.l1 = "Timer";
			PChar.quest.kapitein_yedam_papers_ready.win_condition.l1.date.day = GetAddingDataDay(0,0,1);
			PChar.quest.kapitein_yedam_papers_ready.win_condition.l1.date.month = GetAddingDataMonth(0,0,1);
			PChar.quest.kapitein_yedam_papers_ready.win_condition.l1.date.year = GetAddingDataYear(0,0,1);
			PChar.quest.kapitein_yedam_papers_ready.win_condition = "kapitein_yedam_papers_ready";
		break;

		case "kapitein_yedam_papers_ready":
			Preprocessor_AddQuestData("forger", GetMySimpleName(CharacterFromID("Yedam Kinne")));
			AddQuestRecord("kapitein", 8);
			Preprocessor_Remove("forger");
			Characters[GetCharacterIndex("Yedam Kinne")].dialog.CurrentNode = "kapitein_document_done";
		break;

		case "kapitein_prepare_forger":		// Triggered by dialog with Florentin Destot, Buccaneer Camp tavernkeeper
			Characters[GetCharacterIndex("Pablo Escriva")].dialog.currentNode = "ask_for_document";
			Locations[FindLocation("Buccaneers_Camp")].reload.l4.disable = 0;
		break;

		case "kapitein_wait_three_days":	// Triggered by dialog with Pablo Escriva
			PChar.quest.kapitein_Pablo_papers_ready.win_condition.l1 = "Timer";
			PChar.quest.kapitein_Pablo_papers_ready.win_condition.l1.date.day = GetAddingDataDay(0,0,3);
			PChar.quest.kapitein_Pablo_papers_ready.win_condition.l1.date.month = GetAddingDataMonth(0,0,3);
			PChar.quest.kapitein_Pablo_papers_ready.win_condition.l1.date.year = GetAddingDataYear(0,0,3);
			PChar.quest.kapitein_Pablo_papers_ready.win_condition = "kapitein_Pablo_papers_ready";
		break;

		case "kapitein_Pablo_papers_ready":
			Preprocessor_AddQuestData("forger", GetMySimpleName(CharacterFromID("Pablo Escriva")));
			AddQuestRecord("kapitein", 8);
			Preprocessor_Remove("forger");
			Characters[GetCharacterIndex("Pablo Escriva")].dialog.CurrentNode = "kapitein_document_done";
		break;

		case "kapitein_got_papers":
			PChar.quest.kapitein = "got_papers";
			AddQuestRecord("kapitein", 9);
		break;

		case "Kapitein_wait_for_tailor":	// Triggered by dialog with Kralendijk tailor
			if (CheckAttribute(PChar, "quest.kapitein_already_got_uniform")) DeleteAttribute(PChar, "quest.kapitein_already_got_uniform");
			else DeleteAttribute(PChar, "clothes." + PChar.quest.kapitein.soldier_model);
			PChar.quest.kapitein = "waiting";
			AddQuestRecord("kapitein", 10);
			PChar.quest.kapitein_uniform_ready.win_condition.l1 = "Timer";
			PChar.quest.kapitein_uniform_ready.win_condition.l1.date.day = GetAddingDataDay(0,0,1);
			PChar.quest.kapitein_uniform_ready.win_condition.l1.date.month = GetAddingDataMonth(0,0,1);
			PChar.quest.kapitein_uniform_ready.win_condition.l1.date.year = GetAddingDataYear(0,0,1);
			PChar.quest.kapitein_uniform_ready.win_condition = "kapitein_uniform_ready";
		break;

		case "kapitein_uniform_ready":
			PChar.quest.kapitein = "uniform_ready";
			AddQuestRecord("kapitein", 11);
		break;

		case "kapitein_buy_uniform":
			GiveModel2Player(Nations[HOLLAND].fantomModel.m0, false);
			AddQuestRecord("kapitein", 12);
			PChar.quest.kapitein = "got_uniform";
		break;

		case "kapitein_leave_tavern_with_soldier":
			PChar.quest.kapitein = "got_soldier";
			Characters[GetCharacterIndex(PChar.quest.kapitein.soldier_id2)].dialog.filename = "kapitein_guards_dialog.c";
			Characters[GetCharacterIndex(PChar.quest.kapitein.soldier_id2)].dialog.CurrentNode = "follow_me";
			StorePassengers(PChar.id);
			Pchar.quest.kapitein_outside_tavern.win_condition.l1 = "Location";
			PChar.quest.kapitein_outside_tavern.win_condition.l1.location = "Douwesen_town";
			Pchar.quest.kapitein_outside_tavern.win_condition = "kapitein_outside_tavern";
		break;

		case "kapitein_outside_tavern":
			AddQuestRecord("kapitein", 14);
			DisableFastTravel(true);
			for (i=1; i<12; i++)
			{
				if (i!=7)
				{
					attr = "l" + i;
					Locations[FindLocation("Douwesen_town")].reload.(attr).disable = 1;
				}
			}

			sld = CharacterFromID("Dou_soldier_1");					// Borrow one of the port guards
			sld.original_name = sld.name;
			sld.original_lastname = sld.lastname;
			sld.original_model = sld.model;
			sld.greeting = "Gr_Dutch Officer";
			sld.name = PChar.quest.kapitein.soldier_name2;
			sld.lastname = PChar.quest.kapitein.soldier_last_name2;
			SetModelfromID(sld, PChar.quest.kapitein.soldier_model2);
			SetCharacterToNearLocatorFromMe("Dou_soldier_1", 3);			// 'SetCharacterToNearLocatorFromMe' takes character ID
			sld.dialog.filename = "kapitein_guards_dialog.c";
			sld.dialog.currentNode = "to_the_townhall";
			LAi_SetActorType(characterFromID("Dou_soldier_1"));
			LAi_ActorDialog(sld, PChar, "kapitein_soldier_follow_to_townhall",5.0,5.0);
		break;

		case "kapitein_soldier_follow_to_townhall":
			LAi_SetActorType(characterFromID("Dou_soldier_1"));
			LAi_ActorFollowEverywhere(CharacterFromID("Dou_soldier_1"), "", 1.0);
			Pchar.quest.kapitein_arrest_governor.win_condition.l1 = "Location";
			PChar.quest.kapitein_arrest_governor.win_condition.l1.location = "Douwesen_townhall";
			Pchar.quest.kapitein_arrest_governor.win_condition = "kapitein_arrest_governor";
		break;

		case "kapitein_arrest_governor":
			PChar.quest.kapitein = "arrest_governor";
			Locations[FindLocation("Douwesen_townhall")].reload.l1.disable = 1;	// Lock townhall exit
			for (i=1; i<12; i++)
			{
				if (i!=7)
				{
					attr = "l" + i;
					Locations[FindLocation("Douwesen_town")].reload.(attr).disable = 0;
				}
			}
			Locations[FindLocation("Douwesen_town")].reload.l7.disable = 1;		// Lock townhall entrance
			NPChar = CharacterFromID("Reynard Grueneveldt");
			NPChar.quest.old_dialog_file = NPChar.dialog.filename;			// Store governor's dialog status
			NPChar.quest.old_dialog_currentnode = NPChar.dialog.currentNode;
			NPChar.dialog.filename = "Reynard Grueneveldt_dialog.c";
			NPChar.dialog.currentNode = "kapitein_arrest1";
		break;

		case "kapitein_busted":		// Triggered by dialog with Reynard Grueneveldt if you tried to arrest him while not wearing uniform
			pchar.quest.disable_rebirth = true;
			PostEvent("LAi_event_GameOver", 0, "s", "mutiny");
		break;

		case "kapitein_goto_chest":		// Triggered by dialog with Reynard Grueneveldt
			LAi_SetActorType(characterFromID("Reynard Grueneveldt"));
			LAi_SetActorType(characterFromID("Dou_soldier_1"));
			Characters[GetCharacterIndex("Dou_soldier_1")].dialog.CurrentNode = "youre_witness";
			LAi_ActorDialogNow(characterFromID("Dou_soldier_1"), PChar, "kapitein_get_money",1.0);
		break;

		case "kapitein_get_money":
			pchar.quest.kapitein_get_money.win_condition.l1 = "locator";
			pchar.quest.kapitein_get_money.win_condition.l1.location = "Douwesen_townhall";
			pchar.quest.kapitein_get_money.win_condition.l1.locator_group = "box";
			pchar.quest.kapitein_get_money.win_condition.l1.locator = "box1";
			pchar.quest.kapitein_get_money.win_condition = "kapitein_get_money2";
		break;

		case "kapitein_get_money2":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 35574);		// About 10 times the number of Marks that the real Captain of Köpenick got.
			PChar.quest.kapitein = "got_money";
			LAi_SetActorType(characterFromID("Dou_soldier_1"));
			Characters[GetCharacterIndex("Dou_soldier_1")].dialog.CurrentNode = "keep_them_here";
			LAi_ActorDialogNow(characterFromID("Dou_soldier_1"), PChar, "kapitein_getaway",1.0);
		break;

		case "kapitein_getaway":
			AddQuestRecord("kapitein", 15);
			LAi_SetActorType(characterFromID("Dou_soldier_1"));
			LAi_ActorGoToLocator(CharacterFromID("Dou_soldier_1"), "reload", "reload1", "kapitein_guard_posted", 5.0);
			RestorePassengers(PChar.id);
			Locations[FindLocation("Douwesen_townhall")].reload.l1.disable = 0;
			Pchar.quest.kapitein_leave_townhall.win_condition.l1 = "Location";
			PChar.quest.kapitein_leave_townhall.win_condition.l1.location = "Douwesen_town";
			Pchar.quest.kapitein_leave_townhall.win_condition = "kapitein_leave_townhall";
		break;

		case "kapitein_guard_posted":
			LAi_SetGuardianType(CharacterFromID("Dou_soldier_1"));
		break;

		case "kapitein_leave_townhall":
			DisableFastTravel(false);
			AddQuestRecord("kapitein", 16);
			sld = CharacterFromID("Dou_soldier_1")		// Restore port guard
			ChangeCharacterAddressGroup(sld, "Douwesen_port", "goto", "goto16");
			sld.name = sld.original_name;
			sld.lastname = sld.original_lastname;
			sld.greeting = "Gr_Douwesen Soldier";
			SetModelfromID(sld, sld.original_model);
			DeleteAttribute(sld, "original_name");
			DeleteAttribute(sld, "original_lastname");
			DeleteAttribute(sld, "original_model");
			sld.Dialog.Filename = "Douwesen soldier_dialog.c";
			sld.dialog.currentNode = "First time";

			NPChar = CharacterFromID("Reynard Grueneveldt"); // Restore governor to normal
			NPChar.dialog.filename = NPChar.quest.old_dialog_file;
			NPChar.dialog.currentNode = NPChar.quest.old_dialog_currentnode;
			DeleteAttribute(NPChar, "quest.old_dialog_file");
			DeleteAttribute(NPChar, "quest.old_dialog_currentnode");
			LAi_SetHuberStayType(NPChar);
			LAi_SetStayHuberPointMap(NPChar, "goto", "goto4");
			LAi_SetStayHuberPointWindow(NPChar, "goto", "goto6");

			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Sneak", 20000); }
			else { AddPartyExp(pchar, 20000); }
			if(GetCharacterReputation(PChar) > REPUTATION_SWINDLER) ChangeCharacterReputation(PChar, -5);	// Reputation loss, but only to "Swindler" - this doesn't involve murder

			Pchar.quest.kapitein_escape_to_sea.win_condition.l1 = "MapEnter";
			Pchar.quest.kapitein_escape_to_sea.win_condition = "kapitein_escape_to_sea";
		break;

		case "kapitein_escape_to_sea":
			Locations[FindLocation("Douwesen_town")].reload.l7.disable = 0;					// Unlock townhall entrance
			PChar.quest.kapitein = "on_the_run";
			if (LANDCREWMEMBERS) Locations[FindLocation("Douwesen_town")].vcskip = true;			// Extra crew ashore plus extra encounters can prevent arresting soldiers from spawning
			PChar.quest.kapitein_arrest.win_condition.l1 = "Timer";
			PChar.quest.kapitein_arrest.win_condition.l1.date.day = GetAddingDataDay(0,0,14);
			PChar.quest.kapitein_arrest.win_condition.l1.date.month = GetAddingDataMonth(0,0,14);
			PChar.quest.kapitein_arrest.win_condition.l1.date.year = GetAddingDataYear(0,0,14);
			Pchar.quest.kapitein_arrest.win_condition.l2 = "Location";
			PChar.quest.kapitein_arrest.win_condition.l2.location = "Douwesen_town";
			PChar.quest.kapitein_arrest.win_condition = "kapitein_arrest";
		break;

		case "kapitein_arrest":
			DeleteAttribute(&Locations[FindLocation("Douwesen_town")],"vcskip");
			StartQuestMovie(true, true, false);
			DisableFastTravel(true);
			for (i=1; i<4; i++)
			{
				attr = "m" + i;
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[HOLLAND].fantomModel.(attr), "reload", "reload5");
				LAi_group_MoveCharacter(sld, "DOUWESEN_SOLDIERS");
				GiveSoldierWeapon(sld, HOLLAND);
				sld.id = "arrester_" + i;
				sld.nation = HOLLAND;
				SetRandomNameToCharacter(sld);
				LAi_SetActorType(sld);
				LAi_ActorFollow(sld, PChar, "", 25.0);
			}
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[HOLLAND].fantomModel.m0, "reload", "reload5");
			LAi_group_MoveCharacter(sld, "DOUWESEN_SOLDIERS");
			GiveSoldierWeapon(sld, HOLLAND);
			sld.id = "arrester_officer";
			sld.nation = HOLLAND;
			SetRandomNameToCharacter(sld);
			SetCharacterToNearLocatorFromMe("arrester_officer", 3);
			LAi_SetActorType(sld);
			sld.dialog.filename = "kapitein_guards_dialog.c";
			sld.dialog.currentNode = "youre_nicked";
			LAi_ActorDialog(sld, PChar, "",3.0,3.0);	// Exits to "kapitein_trial" or "kapitein_resist_arrest"
		break;

		case "kapitein_resist_arrest":
			LAi_group_MoveCharacter(characterFromID("arrester_officer"), "DOUWESEN_SOLDIERS");
			for (i=1; i<4; i++)
			{
				LAi_group_MoveCharacter(characterFromID("arrester_" + i), "DOUWESEN_SOLDIERS");
			}
			LAi_group_SetRelation("DOUWESEN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("DOUWESEN_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("DOUWESEN_SOLDIERS", "kapitein_resistance_successful");
		break;

		case "kapitein_resistance_successful":
			AddQuestRecord("kapitein", 18);
			CloseQuestHeader("kapitein");
			DisableFastTravel(false);
			EndQuestMovie();
			LeaveService(PChar, HOLLAND, true);
			if(GetRMRelation(PChar, HOLLAND) > REL_WAR) SetRMRelation(PChar, HOLLAND, REL_WAR);	// Holland now regards you as a wanted criminal
		break;

		case "kapitein_trial":
			LAi_SetActorType(characterFromID("Reynard Grueneveldt"));
			Characters[GetCharacterIndex("Reynard Grueneveldt")].greeting = "Gr_Reynard Grueneveldt_hostile";
			DoQuestReloadToLocation("Douwesen_townhall", "reload", "reload1", "kapitein_trial2");
		break;

		case "kapitein_trial2":
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[HOLLAND].fantomModel.m1, "goto", "goto2");
			LAi_group_MoveCharacter(sld, "DOUWESEN_SOLDIERS");
			GiveSoldierWeapon(sld, HOLLAND);
			sld.id = "drunk_soldier";
			sld.name = PChar.quest.kapitein.soldier_name;
			sld.lastname = PChar.quest.kapitein.soldier_last_name;
			sld.dialog.filename = "kapitein_guards_dialog.c";
			SetModelfromID(sld, PChar.quest.kapitein.soldier_model);
			sld.nation = HOLLAND;

			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[HOLLAND].fantomModel.m1, "goto", "goto6");
			LAi_group_MoveCharacter(sld, "DOUWESEN_SOLDIERS");
			GiveSoldierWeapon(sld, HOLLAND);
			sld.id = "assisting_soldier";
			sld.name = PChar.quest.kapitein.soldier_name2;
			sld.lastname = PChar.quest.kapitein.soldier_last_name2;
			sld.dialog.filename = "kapitein_guards_dialog.c";
			SetModelfromID(sld, PChar.quest.kapitein.soldier_model2);
			sld.nation = HOLLAND;

			LAi_SetActorType(PChar);
			LAi_ActorFollow(PChar, characterFromID("Reynard Grueneveldt"), "kapitein_trial3", 10.0);
		break;

		case "kapitein_trial3":
			LAi_SetPlayerType(PChar);
			Locations[FindLocation("Douwesen_townhall")].reload.l1.disable = 1;	// Lock townhall exit
			NPChar = CharacterFromID("Reynard Grueneveldt");
			NPChar.quest.old_dialog_file = NPChar.dialog.filename;			// Store governor's dialog status
			NPChar.quest.old_dialog_currentnode = NPChar.dialog.currentNode;
			NPChar.dialog.filename = "Reynard Grueneveldt_dialog.c";
			NPChar.dialog.currentNode = "kapitein_trial1";
			LAi_SetActorType(NPChar);
			LAi_ActorDialogNow(NPChar, PChar, "kapitein_trial4",1.0);
		break;

		case "kapitein_trial4":
			LAi_SetActorType(characterFromID("drunk_soldier"));
			Characters[GetCharacterIndex("drunk_soldier")].dialog.CurrentNode = "trial_witness1";
			LAi_ActorDialogNow(characterFromID("drunk_soldier"), PChar, "kapitein_trial5",1.0);
		break;

		case "kapitein_trial5":
			LAi_SetActorType(characterFromID("Reynard Grueneveldt"));
			Characters[GetCharacterIndex("Reynard Grueneveldt")].dialog.CurrentNode = "kapitein_trial3";
			LAi_ActorDialogNow(characterFromID("Reynard Grueneveldt"), PChar, "kapitein_trial6",1.0);
		break;

		case "kapitein_trial6":
			LAi_SetActorType(characterFromID("assisting_soldier"));
			Characters[GetCharacterIndex("assisting_soldier")].dialog.CurrentNode = "trial_witness2";
			LAi_ActorDialogNow(characterFromID("assisting_soldier"), PChar, "kapitein_trial7",1.0);
		break;

		case "kapitein_trial7":
			LAi_SetActorType(characterFromID("Reynard Grueneveldt"));
			Characters[GetCharacterIndex("Reynard Grueneveldt")].dialog.CurrentNode = "kapitein_trial4";
			LAi_ActorDialogNow(characterFromID("Reynard Grueneveldt"), PChar, "kapitein_to_prison",1.0);
		break;

		case "kapitein_to_prison":
			LeaveService(PChar, HOLLAND, false);
			Locations[FindLocation("Douwesen_townhall")].reload.l1.disable = 0;	// Unlock townhall exit
			Locations[FindLocation("PaP_prison")].vcskip = true;			// Use Guadeloupe prison because Kralendijk doesn't have one
			Locations[FindLocation("PaP_prison")].reload.l1.disable = 1;
			ChangeCharacterAddressGroup(characterfromID("Willem Voigt"), "PaP_prison", "goto", "goto9");
			StorePassengers(PChar.id);
			DoQuestReloadToLocation("PaP_prison", "goto", "goto24", "kapitein_in_prison");
		break;

		case "kapitein_in_prison":
			AddQuestRecord("kapitein", 17);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[HOLLAND].fantomModel.m1, "goto", "goto16");
			LAi_group_MoveCharacter(sld, "DOUWESEN_SOLDIERS");
			GiveSoldierWeapon(sld, HOLLAND);
			sld.id = "prison_guard1";
			LAi_SetPatrolType(sld);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[HOLLAND].fantomModel.m2, "goto", "goto17");
			LAi_group_MoveCharacter(sld, "DOUWESEN_SOLDIERS");
			GiveSoldierWeapon(sld, HOLLAND);
			sld.id = "prison_guard2";
			LAi_SetPatrolType(sld);

			LAi_SetActorType(characterFromID("Willem Voigt"));
			Characters[GetCharacterIndex("Willem Voigt")].dialog.CurrentNode = "they_got_you_too";
			LAi_ActorDialogNow(characterFromID("Willem Voigt"), PChar, "kapitein_in_prison2",1.0);
		break;

		case "kapitein_in_prison2":
			LAi_SetActorType(characterFromID("Willem Voigt"));
			LAi_Fade("kapitein_wait_two_months", "kapitein_reset_prison");
		break;

		case "kapitein_wait_two_months":
			AddDataToCurrent(0, 2, 0, false);
			SetCurrentTime(10.00, 0);
			LAi_Fade("", "");
			logit(TranslateString("", "Two months later..."));
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(PChar, "goto", "goto9", "", 10.0);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[HOLLAND].fantomModel.m0, "goto", "goto22");
			sld.id = "Dutch Prison Commander";
			sld.greeting = "Gr_Redmond Commendant";
			LAi_SetActorType(sld);
			LAi_ActorGoToLocator(sld, "reload", "reload12", "kapitein_release", 30.0);
		break;

		case "kapitein_reset_prison":
			DeleteAttribute(&Locations[FindLocation("PaP_prison")],"vcskip");
			Locations[FindLocation("PaP_prison")].reload.l1.disable = 0;
		break;

		case "kapitein_release":
			LAi_type_actor_Reset(PChar);
			LAi_ActorWaitDialog(PChar, characterFromID("Dutch Prison Commander"));
			LAi_SetActorType(characterFromID("Dutch Prison Commander"));
			Characters[GetCharacterIndex("Dutch Prison Commander")].Dialog.Filename = "kapitein_guards_dialog.c";
			Characters[GetCharacterIndex("Dutch Prison Commander")].dialog.CurrentNode = "kapitein_goto_governor";
			LAi_ActorDialogNow(characterFromID("Dutch Prison Commander"),PChar,"kapitein_back_to_governor",1.0);
		break;

		case "kapitein_back_to_governor":
			RestorePassengers(PChar.id);
			LAi_SetPlayerType(PChar);
			DoQuestReloadToLocation("Douwesen_townhall", "reload", "reload1", "kapitein_back_to_governor2");
		break;

		case "kapitein_back_to_governor2":
			ChangeCharacterAddress(characterFromID("Willem Voigt"), "None", "");
			LAi_SetActorType(PChar);
			LAi_ActorFollow(PChar, characterFromID("Reynard Grueneveldt"), "kapitein_back_to_governor3", 10.0);
		break;

		case "kapitein_back_to_governor3":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Reynard Grueneveldt"));
			Characters[GetCharacterIndex("Reynard Grueneveldt")].dialog.CurrentNode = "kapitein_pardon";
			LAi_ActorDialogNow(characterFromID("Reynard Grueneveldt"), PChar, "kapitein_released",1.0);
		break;

		case "kapitein_released":
			DisableFastTravel(false);
			EndQuestMovie();
			AddQuestRecord("kapitein", 19);
			CloseQuestHeader("kapitein");
			string fame_name = "extra_fame" + HOLLAND;
			x = stf(GetAttribute(PChar, fame_name));
			if (x < 0) PChar.(fame_name) = 50.0;	// You just became famous because your exploits have been noticed by very important people and made all the news
			else PChar.(fame_name) = x + 50.0;
			if(GetCharacterReputation(PChar) > REPUTATION_BASTARD) ChangeCharacterReputation(PChar, -5);	// Reputation loss, but not to "Horror of the High Seas"
			Pchar.quest.kapitein_reset_governor.win_condition.l1 = "MapEnter";
			Pchar.quest.kapitein_reset_governor.win_condition = "kapitein_reset_governor";
		break;

		case "kapitein_reset_governor":
			LAi_SetHuberStayType(CharacterFromID("Reynard Grueneveldt"));
			LAi_SetStayHuberPointMap(CharacterFromID("Reynard Grueneveldt"), "goto", "goto4");
			LAi_SetStayHuberPointWindow(CharacterFromID("Reynard Grueneveldt"), "goto", "goto6");
			NPChar = CharacterFromID("Reynard Grueneveldt"); // Restore governor to normal
			NPChar.dialog.filename = NPChar.quest.old_dialog_file;
			NPChar.dialog.currentNode = NPChar.quest.old_dialog_currentnode;
			NPChar.greeting = "Gr_Reynard Grueneveldt";
			DeleteAttribute(NPChar, "quest.old_dialog_file");
			DeleteAttribute(NPChar, "quest.old_dialog_currentnode");
		break;
///////////////////////////////////////////////////////////////////////
// The Kapitein of Kralendijk - end
///////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// Hornblower sidequests
// By Grey Roger
// Based very loosely on incidents in the film "Captain Horatio Hornblower R.N."
////////////////////////////////////////////////////////////////////////////////
		case "Hornblower_initiate_Natividad":	// Triggered by dialog with governor when Hornblower is promoted to rank 6
			SetQuestHeader("Natividad");
			AddQuestRecord("Natividad", 1);
			setCharacterShipLocation(CharacterFromID("Sir Edward Pellew"), "Greenford_port");
			Characters[GetCharacterIndex("Sir Edward Pellew")].Dialog.Filename = "Sir Edward Pellew_freeplay_dialog.c";
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "First time";
		break;

		case "hornblower_place_el_supremo":	// Triggered by dialog with Sir Edward Pellew
			if (!CheckAttribute(PChar, "QuestInfo.Natividad")) SetQuestHeader("Natividad");
			Preprocessor_AddQuestData("briefing_officer", GetMyFullName(CharacterFromID("Sir Edward Pellew")));
			AddQuestRecord("Natividad", 2);
			Preprocessor_Remove("briefing_officer");
			ChangeCharacterAddressGroup(characterfromID("El Supremo"), "Dining_Room", "goto", "goto2");
			Characters[GetCharacterIndex("El Supremo")].dialog.CurrentNode = "meet_Hornblower";

			Locations[FindLocation("Cuba_Shore_04")].reload.l4.label = "Rebel Shore";
			Locations[FindLocation("Prison_Shore")].id.label = "Rebel Shore";
			Locations[FindLocation("Prison_Shore")].reload.l2.label = "Rebel Fort";
			Locations[FindLocation("Prison_Shore")].vcskip = true;
			locations[FindLocation("Havana_fakefort4")].id.label = "Rebel Fort";
			Locations[FindLocation("Havana_fakefort4")].models.always.locators = "fort1_l_GR";
			Build_at("Havana_fakefort4", "Gallows", "", 1.0, 0.0, 12.6, 0.0, "building");
			Locations[FindLocation("Dining_Room")].models.always.locators = "Res05_l_GR";
			locations[FindLocation("Dining_Room")].id.label = "Don Julian Alvarado's Quarters";
			Locations[FindLocation("Prison_Shore")].reload.l2.disable = 1;

			PChar.quest.hornblower_cuba_arrival.win_condition.l1 = "Location";
			PChar.quest.hornblower_cuba_arrival.win_condition.l1.location = "Cuba";
			PChar.quest.hornblower_cuba_arrival.win_condition = "hornblower_cuba_arrival";

			PChar.quest.Killed_at_Prison.over = "yes";	// Remove "Hornblower" storyline check on crossing blown bridge
		break;

		case "hornblower_cuba_arrival":
			SetNextWeather("Clear");
			AddDataToCurrent(0, 0, 1, true);
			SetCurrentTime(10, 0);
			Locations[FindLocation("ShipDeck1")].models.always.locators = "qdeck_ld_gr";
			Locations[FindLocation("Cabin_medium")].models.always.locators = "capmd_l_GR";
			SetCharacterShipLocation(characterFromID("Jose Hernandez"), "ShipDeck1");
//			characters[GetCharacterIndex("Jose Hernandez")].sailaway = true;
			SetCharacterShipLocation(PChar, "Cuba_Shore_04");
			PChar.location.from_sea = "Cuba_Shore_04";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar");
			StartQuestMovie(true, true, false);
//			ChangeCharacterAddressGroup(CharacterFromID("Lt. William Bush"), GetCharacterShipQDeck(PChar), "rld", "startloc");
//			DoReloadFromSeaToLocation(GetCharacterShipQDeck(PChar), "rld", "reload1");
			ChangeCharacterAddressGroup(CharacterFromID("Lt. William Bush"), "ShipDeck1", "goto", "goto4");
			DoReloadFromSeaToLocation("ShipDeck1", "rld", "loc2");
			LAi_QuestDelay("hornblower_cuba_arrival2", 0.1);
		break;

		case "hornblower_cuba_arrival2":
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "goto", "goto5");
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			GiveSoldierWeapon(sld, ENGLAND);
			sld.id = "ship_guard1";
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "goto", "goto2");
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "goto10");
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			GiveSoldierWeapon(sld, ENGLAND);
			sld.id = "ship_guard2";
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "goto", "goto2");
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "goto9");
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			GiveSoldierWeapon(sld, ENGLAND);
			sld.id = "ship_guard3";
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "goto", "goto2");
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "reload", "boatl");
			LAi_QuestDelay("hornblower_cuba_arrival3", 2.0);
		break;

		case "hornblower_cuba_arrival3":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "A rum lot";
			LAi_ActorDialog(characterFromID("Lt. William Bush"), PChar, "hornblower_hernandez_boards",5.0,5.0);
		break;

		case "hornblower_hernandez_boards":
			LAi_SetOfficerType(CharacterFromID("Lt. William Bush"));
			DeleteAttribute(characterFromID("Jose Hernandez"), "sailaway");
			ChangeCharacterAddressGroup(CharacterFromID("Jose Hernandez"), "ShipDeck1", "reload", "boatl");
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, "fisherman1", "reload", "boatl");
			GiveItem2Character(sld, "blade7");
			EquipCharacterByItem(sld, "blade7");
			sld.id = "hernadez_guard";
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, characterFromID("Jose Hernandez"), "", 25.0);
			LAi_SetActorType(characterFromID("Jose Hernandez"));
			LAi_ActorGoToLocator(characterFromID("Jose Hernandez"), "goto", "goto2", "hornblower_hernandez_boards2", 10.0);
		break;

		case "hornblower_hernandez_boards2":
			LAi_SetActorType(characterFromID("Jose Hernandez"));
			Characters[GetCharacterIndex("Jose Hernandez")].Dialog.Filename = "Jose Hernandez_dialog.c";
			Characters[GetCharacterIndex("Jose Hernandez")].dialog.CurrentNode = "Hernandez_comes_aboard";
			LAi_ActorDialog(characterFromID("Jose Hernandez"), PChar, "hornblower_bush_take_command",5.0,5.0);
		break;

		case "hornblower_bush_take_command":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "If not back";
			LAi_ActorDialog(characterFromID("Lt. William Bush"), PChar, "hornblower_follow_hernandez",5.0,5.0);
		break;

		case "hornblower_follow_hernandez":
			AddQuestRecord("Natividad", 3);
			SetCharacterShipLocation(characterFromID("Jose Hernandez"), "Cuba_Shore_04");
			ChangeCharacterAddressGroup(CharacterFromID("Jose Hernandez"), "Cuba_Shore_04", "goto", "locator8");
			StorePassengers(PChar.id);
			DoQuestReloadToLocation("Cuba_Shore_04", "reload", "reload1", "hornblower_follow_hernandez2");
		break;

		case "hornblower_follow_hernandez2":
			bQuestDisableSeaEnter = true;
			DisableFastTravel(true);
			LAi_SetActorType(characterFromID("Jose Hernandez"));
			Characters[GetCharacterIndex("Jose Hernandez")].dialog.CurrentNode = "Hernandez_warns_about_paths";
			LAi_ActorDialog(characterFromID("Jose Hernandez"), PChar, "hornblower_follow_hernandez3",5.0,5.0);
		break;

		case "hornblower_follow_hernandez3":
			EndQuestMovie();
			Locations[FindLocation("Cuba_Shore_04")].reload.l3.disable = 1;
			LAi_SetActorType(characterFromID("Jose Hernandez"));
			LAi_ActorGoToLocation(CharacterFromID("Jose Hernandez"), "reload", "reload3", "Prison_Shore", "goto", "goto15", "", 30);
			PChar.quest.hornblower_with_hernandez_to_fort.win_condition.l1 = "Location";
			PChar.quest.hornblower_with_hernandez_to_fort.win_condition.l1.location = "Prison_Shore";
			PChar.quest.hornblower_with_hernandez_to_fort.win_condition = "hornblower_with_hernandez_to_fort";
		break;

		case "hornblower_with_hernandez_to_fort":
			ChangeCharacterAddressGroup(CharacterFromID("Jose Hernandez"), "Prison_Shore", "goto", "goto15");
			LAi_SetActorType(characterFromID("Jose Hernandez"));
			LAi_ActorGoToLocation(CharacterFromID("Jose Hernandez"), "reload", "reload1_back", "Havana_fakefort4", "rld", "aloc1", "hornblower_fort_opens", 540);
			PChar.quest.hornblower_with_hernandez_to_fort2.win_condition.l1 = "Location";
			PChar.quest.hornblower_with_hernandez_to_fort2.win_condition.l1.location = "Havana_fakefort4";
			PChar.quest.hornblower_with_hernandez_to_fort2.win_condition = "hornblower_with_hernandez_to_fort2";

			pchar.quest.hornblower_fort_closed.win_condition.l1 = "locator";
			pchar.quest.hornblower_fort_closed.win_condition.l1.location = "Prison_Shore";
			pchar.quest.hornblower_fort_closed.win_condition.l1.locator_group = "reload";
			pchar.quest.hornblower_fort_closed.win_condition.l1.locator = "reload1_back";
			pchar.quest.hornblower_fort_closed.win_condition = "hornblower_fort_closed";
		break;

		case "hornblower_fort_closed":
			logit(TranslateString("", "The fort gate is closed. Wait for Admiral Hernandez to open it."));
		break;

		case "hornblower_fort_opens":
			Locations[FindLocation("Prison_Shore")].reload.l2.disable = 0;
			pchar.quest.hornblower_fort_closed.over = "yes";
		break;

		case "hornblower_with_hernandez_to_fort2":
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, "fisherman", "goto", "goto8");
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.id = "rebel_guard1";
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "goto", "goto6");
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, "fisherman", "goto", "goto9");
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "goto", "goto7");
			sld.id = "rebel_guard2";
			sld = LAi_CreateFantomCharacter(false, 1, true, false, 0.0, "prison_3", "goto", "goto6");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			sld.id = "prisoner1";
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "goto", "goto6");
			sld = LAi_CreateFantomCharacter(false, 1, true, false, 0.0, "bb_Pell_prisoner", "goto", "goto7");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "goto", "goto7");
			sld.id = "prisoner2";
			Locations[FindLocation("Havana_fakefort4")].reload.l1.disable = 1;
			ChangeCharacterAddressGroup(CharacterFromID("Jose Hernandez"), "Havana_fakefort4", "rld", "aloc1");
			LAi_SetActorType(characterFromID("Jose Hernandez"));
			LAi_ActorGoToLocation(CharacterFromID("Jose Hernandez"), "reload", "reloadC5", "Dining_Room", "goto", "goto7", "", 30);
			PChar.quest.hornblower_meet_el_supremo.win_condition.l1 = "Location";
			PChar.quest.hornblower_meet_el_supremo.win_condition.l1.location = "Dining_Room";
			PChar.quest.hornblower_meet_el_supremo.win_condition = "hornblower_meet_el_supremo";
		break;

		case "hornblower_meet_el_supremo":
			ChangeCharacterAddressGroup(CharacterFromID("Jose Hernandez"), "Dining_Room", "goto", "goto7");
			LAi_SetGuardianTypeNoGroup(characterFromID("Jose Hernandez"));
			Characters[GetCharacterIndex("Jose Hernandez")].dialog.CurrentNode = "Hernandez_respect_El_Supremo";
			Locations[FindLocation("Cuba_Shore_04")].reload.l3.disable = 0;
			Locations[FindLocation("Havana_fakefort4")].reload.l1.disable = 0;
			Characters[GetCharacterIndex("El Supremo")].dialog.CurrentNode = "introduction"; 
		break;

		case "Hornblower_Hernandez_shuts_up":		// Triggered by dialog with Jose Hernandez in El Supremo's room
			LAi_SetActorType(characterFromID("Jose Hernandez"));
		break;

		case "Hornblower_El_Supremo_checks_window":
			LAi_SetActorType(characterFromID("El Supremo"));
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(characterFromID("El Supremo"), "goto", "goto10", "", 10.0);
			LAi_QuestDelay("Hornblower_El_Supremo_back_to_place", 2.0);
		break;

		case "Hornblower_El_Supremo_back_to_place":
			LAi_ActorGoToLocator(characterFromID("El Supremo"), "goto", "goto2", "Hornblower_El_Supremo_allies", 10.0);
		break;


		case "Hornblower_El_Supremo_allies":	// Triggered by dialog with "El Supremo"
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("El Supremo"));
			Characters[GetCharacterIndex("El Supremo")].dialog.CurrentNode = "we_are_allies";
			LAi_ActorDialog(characterFromID("El Supremo"), PChar, "Hornblower_supplies_from_Hernandez",5.0,5.0);
		break;

		case "Hornblower_supplies_from_Hernandez":
			LAi_SetActorType(characterFromID("Jose Hernandez"));
			Characters[GetCharacterIndex("Jose Hernandez")].dialog.CurrentNode = "Supply_order";
			LAi_ActorDialog(characterFromID("Jose Hernandez"), PChar, "hornblower_supremo_burning_city",5.0,5.0);
		break;

		case "hornblower_supremo_burning_city":
			LAi_SetActorType(characterFromID("El Supremo"));
			Characters[GetCharacterIndex("El Supremo")].dialog.CurrentNode = "next_move";
			LAi_ActorDialog(characterFromID("El Supremo"), PChar, "hornblower_natividad_messenger",5.0,5.0);
		break;

		case "hornblower_natividad_messenger":
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, "fisherman1", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			sld.id = "rebel_messenger";
			LAi_SetActorType(sld);
			LAi_ActorRunToLocator(CharacterFromID("rebel_messenger"), "goto", "goto10", "hornblower_natividad_messenger_speaks", 10.0)
		break;

		case "hornblower_natividad_messenger_speaks":
			LAi_SetActorType(characterFromID("rebel_messenger"));
			Characters[GetCharacterIndex("rebel_messenger")].Dialog.Filename = "Hornblower_quest_minors_dialog.c";
			Characters[GetCharacterIndex("rebel_messenger")].dialog.CurrentNode = "Natividad_announcement";
			LAi_ActorDialogNow(characterFromID("rebel_messenger"), PChar, "Hornblower_El_Supremo_Natividad",1.0);
		break;

		case "Hornblower_El_Supremo_Natividad":
			LAi_SetActorType(characterFromID("El Supremo"));
			Characters[GetCharacterIndex("El Supremo")].dialog.CurrentNode = "Natividad_announced";
			LAi_ActorDialogNow(characterFromID("El Supremo"), PChar, "",1.0);
			PChar.quest.hornblower_back_into_fort.win_condition.l1 = "Location";
			PChar.quest.hornblower_back_into_fort.win_condition.l1.location = "Havana_fakefort4";
			PChar.quest.hornblower_back_into_fort.win_condition = "hornblower_back_into_fort";
		break;

		case "hornblower_back_into_fort":
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, "fisherman", "rld", "loc9");
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			sld.id = "rebel_guard1";
			LAi_SetPatrolType(sld);
			sld.Dialog.Filename = "Hornblower_quest_minors_dialog.c";
			sld.dialog.CurrentNode = "rebel_guard";
			sld.dialog.TempNode = "rebel_guard";
			sld.greeting = "Gr_isla muelle soldier";
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, "fisherman", "rld", "loc10");
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			GiveItem2Character(sld, "blade4");
			EquipCharacterByItem(sld, "blade4");
			LAi_SetPatrolType(sld);
			sld.Dialog.Filename = "Hornblower_quest_minors_dialog.c";
			sld.dialog.CurrentNode = "rebel_guard";
			sld.dialog.TempNode = "rebel_guard";
			sld.greeting = "Gr_isla muelle soldier";
			sld.id = "rebel_guard2";

			Locations[FindLocation("Prison_Shore")].reload.l2.disable = 1;
			Locations[FindLocation("Cuba_Shore_04")].reload.l2.disable = 1;
			pchar.quest.hornblower_board_for_supplies_and_lookout.win_condition.l1 = "locator";
			pchar.quest.hornblower_board_for_supplies_and_lookout.win_condition.l1.location = "Cuba_Shore_04";
			pchar.quest.hornblower_board_for_supplies_and_lookout.win_condition.l1.locator_group = "reload";
			pchar.quest.hornblower_board_for_supplies_and_lookout.win_condition.l1.locator = "boat";
			pchar.quest.hornblower_board_for_supplies_and_lookout.win_condition = "hornblower_board_for_supplies_and_lookout";
		break;

		case "hornblower_board_for_supplies_and_lookout":
			RestorePassengers(PChar.id);
			Locations[FindLocation("Cuba_Shore_04")].reload.l2.disable = 0;
			StartQuestMovie(true, true, false);
			Locations[FindLocation("ShipDeck1")].reload.l4.go = "Cuba_Shore_04";
			Locations[FindLocation("ShipDeck1")].reload.l4.emerge = "boat";
			DoQuestReloadToLocation("ShipDeck1", "reload", "boatl", "hornblower_board_for_supplies_and_lookout2");
		break;

		case "hornblower_board_for_supplies_and_lookout2":
			ChangeCharacterAddressGroup(CharacterFromID("Lt. William Bush"), "ShipDeck1", "rld", "loc2");
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "goto", "goto5");
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			GiveSoldierWeapon(sld, ENGLAND);
			sld.id = "ship_guard1";
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "reload", "boatl");
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "goto10");
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			GiveSoldierWeapon(sld, ENGLAND);
			sld.id = "ship_guard2";
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "reload", "boatl");
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "goto9");
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			GiveSoldierWeapon(sld, ENGLAND);
			sld.id = "ship_guard3";
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "reload", "boatl");
			PlaySound("OBJECTS\shipcharge\Eng_the_side.wav");
			LAi_QuestDelay("hornblower_board_for_supplies_and_lookout3", 1.0);
		break;

		case "hornblower_board_for_supplies_and_lookout3":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Provisions and cargo";
			LAi_ActorDialog(characterFromID("Lt. William Bush"), PChar, "Hornblower_Natividad_sighted",15.0,15.0);
		break;

		case "Hornblower_exchange_weapons_for_supplies":	// Triggered by dialog with Lt. William Bush
			AddQuestRecord("Natividad", 5);
			AddCharacterGoods(PChar, GOOD_GUNPOWDER, -1*makeint(PChar.quest.powder_needed));
			TakeNItems(PChar, "pistolmketB", -1*makeint(PChar.quest.muskets_needed));
			int free_food_space = GetGoodQuantityByWeight(GOOD_WHEAT, GetCargoFreeSpace(PChar));
			AddCharacterGoods(PChar, GOOD_WHEAT, makeint(free_food_space * 0.6));
			AddCharacterGoods(PChar, GOOD_RUM, makeint(free_food_space * 0.3));
		break;

		case "Hornblower_Natividad_sighted":
			SetNextWeather("Clear");
			SetCurrentTime(22.8, 0);
			DoQuestReloadToLocation("ShipDeck1", "rld", "loc2", "Hornblower_Natividad_sighted2");
		break;

		case "Hornblower_Natividad_sighted2":
			ChangeCharacterAddressGroup(CharacterFromID("Lt. William Bush"), "ShipDeck1", "goto", "goto4");
			PlaceCharacter(CharacterFromID("Lieutenant Gerard"), "goto");
			PlaceCharacter(CharacterFromID("Midshipman Longley"), "goto");
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Natividad sighted";
			LAi_ActorDialog(characterFromID("Lt. William Bush"), PChar, "Hornblower_Natividad_sighted3",15.0,15.0);
		break;

		case "Hornblower_Natividad_sighted3":
			SetNextWeather("Clear");
			SetCurrentTime(23.9, 0);
			DoQuestReloadToLocation("Cabin_medium", "rld", "startloc", "Hornblower_evening_meal");
		break;

		case "Hornblower_evening_meal":
			ChangeCharacterAddressGroup(CharacterFromID("Lt. William Bush"), "Cabin_medium", "rld", "aloc0");
			PlaceCharacter(CharacterFromID("Lieutenant Gerard"), "rld");
			PlaceCharacter(CharacterFromID("Midshipman Longley"), "rld");
			LAi_SetActorType(CharacterFromID("Lieutenant Gerard"));
			LAi_ActorFollow(CharacterFromID("Lieutenant Gerard"), CharacterFromID("Lt. William Bush"), "", 25.0);
			LAi_SetActorType(CharacterFromID("Midshipman Longley"));
			LAi_ActorFollow(CharacterFromID("Midshipman Longley"), CharacterFromID("Lt. William Bush"), "", 25.0);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, "47_Blaze_brtlt", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			sld.id = "reporting_crewman";
			sld.name = "Lieutenant";
			sld.lastname = "Crystal";
			sld.Dialog.Filename = "Hornblower_quest_minors_dialog.c";
			sld.dialog.CurrentNode = "Natividad_approaches";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, PChar, "Hornblower_cut_for_deal",10.0,10.0);
		break;

		case "Hornblower_cut_for_deal":
			LAi_SetActorType(characterFromID("Midshipman Longley"));
			Characters[GetCharacterIndex("Midshipman Longley")].dialog.CurrentNode = "cut_for_deal";
			LAi_ActorDialogNow(characterFromID("Midshipman Longley"), PChar, "Hornblower_Natividad_anchored",1.0);
		break;

		case "Hornblower_Natividad_anchored":
			SetNextWeather("Clear");
			AddDataToCurrent(0, 0, 1, true);
			SetCurrentTime(2, 0);
			ChangeCharacterAddressGroup(CharacterFromID("Lt. William Bush"), "Cabin_medium", "rld", "aloc2");
			Locations[FindLocation("Cabin_medium")].models.always.locators = "capmd_l_GR";
			DoQuestReloadToLocation("Cabin_medium", "sit", "sit2", "Hornblower_Natividad_anchored2");
		break;

		case "Hornblower_Natividad_anchored2":
//			ChangeCharacterAddressGroup(CharacterFromID("Lt. William Bush"), "Cabin_medium", "rld", "aloc2");
			LAi_SetActorType(CharacterFromID("Lieutenant Gerard"));
			LAi_ActorFollow(CharacterFromID("Lieutenant Gerard"), CharacterFromID("Lt. William Bush"), "", 25.0);
			LAi_SetActorType(CharacterFromID("Midshipman Longley"));
			LAi_ActorFollow(CharacterFromID("Midshipman Longley"), CharacterFromID("Lt. William Bush"), "", 25.0);
			LAi_SetActorType(PChar);
			LAi_ActorSetSitMode(Pchar);
			LAi_QuestDelay("Hornblower_Natividad_anchored3", 1.0);
		break;

		case "Hornblower_Natividad_anchored3":
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, "47_Blaze_brtlt", "reload", "reload1");
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			sld.id = "reporting_crewman";
			sld.name = "Lieutenant";
			sld.lastname = "Crystal";
			sld.Dialog.Filename = "Hornblower_quest_minors_dialog.c";
			sld.dialog.CurrentNode = "Natividad_anchored";
			LAi_SetActorType(sld);
			LAi_ActorWaitDialog(PChar, sld);
			LAi_ActorDialogNow(sld, PChar, "",1.0);
		break;

		case "Hornblower_Natividad_anchored4":	// Triggered by dialog from fake Lt. Crystal
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.Filename = "Lt. William Bush_dialog.c";
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Natividad gamble";
			LAi_SetActorType(CharacterFromID("Lt. William Bush"));
			LAi_ActorWaitDialog(PChar, CharacterFromID("Lt. William Bush"));
			LAi_ActorDialogNow(CharacterFromID("Lt. William Bush"), PChar, "",1.0);
		break;

		case "Hornblower_Natividad_plan":	// Triggered by dialog from Lt. William Bush
			Characters[GetCharacterIndex("Midshipman Longley")].dialog.Filename = "Midshipman Longley_dialog.c";
			Characters[GetCharacterIndex("Midshipman Longley")].dialog.CurrentNode = "evening_swim";
			LAi_SetActorType(CharacterFromID("Midshipman Longley"));
			LAi_ActorWaitDialog(PChar, CharacterFromID("Midshipman Longley"));
			LAi_ActorDialogNow(CharacterFromID("Midshipman Longley"), PChar, "Hornblower_to_shore_for_Natividad",1.0);
		break;

		case "Hornblower_to_shore_for_Natividad":
			LAi_SetPlayerType(PChar);
			EndQuestMovie();
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			LAi_SetImmortal(characterfromID("Lt. William Bush"), true);
			if (SetOfficersIndex(Pchar, -1, GetCharacterIndex("Lt. William Bush")) == GetCharacterIndex("Lt. William Bush"))
			{
				SetOfficersIndex(Pchar, 1, GetCharacterIndex("Lt. William Bush"));
				SetCharacterRemovable(characterFromID("Lt. William Bush"), false);
			}
			if (SetOfficersIndex(Pchar, -1, GetCharacterIndex("Midshipman Longley")) == GetCharacterIndex("Midshipman Longley"))
			{
				SetOfficersIndex(Pchar, 3, GetCharacterIndex("Midshipman Longley"));
				SetCharacterRemovable(characterFromID("Midshipman Longley"), false);
			}
			DoQuestReloadToLocation("Cuba_Shore_04", "reload", "reload1", "Hornblower_walk_to_Punta_de_Maisi");
		break;

		case "Hornblower_walk_to_Punta_de_Maisi":
			ChangeCharacterAddressGroup(CharacterFromID("Matthews"), "Cuba_Shore_04", "goto", "locator9");
			LAi_SetActorType(CharacterFromID("Matthews"));
			LAi_ActorFollowEverywhere(CharacterFromID("Matthews"), "", 1.0);
			GiveItem2Character(CharacterFromID("Matthews"), "PiratesPistol");
			EquipCharacterByItem(CharacterFromID("Matthews"),"PiratesPistol");
			if (ENABLE_AMMOMOD) {	// LDH change
				TakenItems(CharacterFromID("Matthews"), "gunpowder", 1 + rand(2));
				TakenItems(CharacterFromID("Matthews"), "pistolbullets", 1 + rand(2));
			}
			LAi_group_MoveCharacter(CharacterFromID("Matthews"), LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(CharacterFromID("Styles"), "Cuba_Shore_04", "goto", "locator12");
			LAi_SetActorType(CharacterFromID("Styles"));
			LAi_ActorFollowEverywhere(CharacterFromID("Styles"), "", 1.0);
			GiveItem2Character(CharacterFromID("Styles"), "PiratesPistol");
			EquipCharacterByItem(CharacterFromID("Styles"),"PiratesPistol");
			if (ENABLE_AMMOMOD) {	// LDH change
				TakenItems(CharacterFromID("Styles"), "gunpowder", 1 + rand(2));
				TakenItems(CharacterFromID("Styles"), "pistolbullets", 1 + rand(2));
			}
			LAi_group_MoveCharacter(CharacterFromID("Styles"), LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(CharacterFromID("Perrin"), "Cuba_Shore_04", "goto", "locator23");
			LAi_SetActorType(CharacterFromID("Perrin"));
			LAi_ActorFollowEverywhere(CharacterFromID("Perrin"), "", 1.0);
			GiveItem2Character(CharacterFromID("Perrin"), "PiratesPistol");
			EquipCharacterByItem(CharacterFromID("Perrin"),"PiratesPistol");
			if (ENABLE_AMMOMOD) {	// LDH change
				TakenItems(CharacterFromID("Perrin"), "gunpowder", 1 + rand(2));
				TakenItems(CharacterFromID("Perrin"), "pistolbullets", 1 + rand(2));
			}
			LAi_group_MoveCharacter(CharacterFromID("Perrin"), LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(CharacterFromID("Oldroyd"), "Cuba_Shore_04", "goto", "locator24");
			LAi_SetActorType(CharacterFromID("Oldroyd"));
			LAi_ActorFollowEverywhere(CharacterFromID("Oldroyd"), "", 1.0);
			GiveItem2Character(CharacterFromID("Oldroyd"), "PiratesPistol");
			EquipCharacterByItem(CharacterFromID("Oldroyd"),"PiratesPistol");
			if (ENABLE_AMMOMOD) {	// LDH change
				TakenItems(CharacterFromID("Oldroyd"), "gunpowder", 1 + rand(2));
				TakenItems(CharacterFromID("Oldroyd"), "pistolbullets", 1 + rand(2));
			}
			LAi_group_MoveCharacter(CharacterFromID("Oldroyd"), LAI_GROUP_PLAYER);
//			ChangeCharacterAddressGroup(CharacterFromID("Marsh"), "Cuba_Shore_04", "goto", "locator25");
//			LAi_SetActorType(CharacterFromID("Marsh"));
//			LAi_ActorFollowEverywhere(CharacterFromID("Marsh"), "", 1.0);
//			GiveItem2Character(CharacterFromID("Marsh"), "PiratesPistol");
//			EquipCharacterByItem(CharacterFromID("Marsh"),"PiratesPistol");
//			if (ENABLE_AMMOMOD) {	// LDH change
//				TakenItems(CharacterFromID("Marsh"), "gunpowder", 1 + rand(2));
//				TakenItems(CharacterFromID("Marsh"), "pistolbullets", 1 + rand(2));
//			}
//			LAi_group_MoveCharacter(CharacterFromID("Marsh"), LAI_GROUP_PLAYER);
			SetCharacterShipLocation(characterFromID("Natividad_captain"), "Cuba_Shore_03");

			LAi_SetActorType(characterFromID("Midshipman Longley"));
			Characters[GetCharacterIndex("Midshipman Longley")].dialog.CurrentNode = "which_way";
			LAi_ActorDialog(characterFromID("Midshipman Longley"), PChar, "Hornblower_walk_to_Punta_de_Maisi2",10.0,10.0);
		break;

		case "Hornblower_walk_to_Punta_de_Maisi2":
			LAi_SetOfficerType(characterFromID("Midshipman Longley"));
			LAi_SetActorType(characterFromID("Perrin"));
			Characters[GetCharacterIndex("Perrin")].dialog.Filename = "Hornblower_quest_minors_dialog.c";
			Characters[GetCharacterIndex("Perrin")].dialog.CurrentNode = "I_know_the_way";
			LAi_ActorDialog(characterFromID("Perrin"), PChar, "Hornblower_walk_to_Punta_de_Maisi3",10.0,10.0);
		break;

		case "Hornblower_walk_to_Punta_de_Maisi3":
			LAi_SetActorType(CharacterFromID("Perrin"));
			LAi_ActorFollowEverywhere(CharacterFromID("Perrin"), "", 1.0);
			Locations[FindLocation("Cuba_Shore_04")].reload.l2.disable = 0;
			PChar.vcskip = true;
			PChar.quest.Hornblower_board_Natividad.win_condition.l1 = "locator";
			PChar.quest.Hornblower_board_Natividad.win_condition.l1.location = "Cuba_Shore_03";
			PChar.quest.Hornblower_board_Natividad.win_condition.l1.locator_group = "reload";
			PChar.quest.Hornblower_board_Natividad.win_condition.l1.locator = "boat";
			PChar.quest.Hornblower_board_Natividad.win_condition = "Hornblower_board_Natividad";

			PChar.quest.hornblower_jungle_ambush.win_condition.l1 = "Location";
			PChar.quest.hornblower_jungle_ambush.win_condition.l1.location = "Cuba_Jungle_01";
			PChar.quest.hornblower_jungle_ambush.win_condition = "Hornblower_jungle_ambush";			
		break;

		case "Hornblower_jungle_ambush":
			Rapid_Raid("Soldiers", 5, SPAIN, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "", "Patrol soldier", OFFIC_TYPE_GUARD, 3, true, "blade_mKnife", "pistolmket");
			PChar.quest.hornblower_havana_ambush.win_condition.l1 = "Location";
			PChar.quest.hornblower_havana_ambush.win_condition.l1.location = "Havana_Outskirts";
			PChar.quest.hornblower_havana_ambush.win_condition = "Hornblower_havana_ambush";
		break;

		case "Hornblower_havana_ambush":
			Rapid_Raid("Soldiers", 5, SPAIN, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "", "Patrol soldier", OFFIC_TYPE_GUARD, 3, true, "blade_mKnife", "pistolmket");
			PChar.quest.hornblower_jungle_ambush.win_condition.l1 = "Location";
			PChar.quest.hornblower_jungle_ambush.win_condition.l1.location = "Cuba_Jungle_01";
			PChar.quest.hornblower_jungle_ambush.win_condition = "Hornblower_jungle_ambush";
		break;

		case "Hornblower_board_Natividad":
			PChar.quest.hornblower_jungle_ambush.over = "yes";
			PChar.quest.hornblower_havana_ambush.over = "yes";
			DoQuestReloadToLocation("ShipDeck2", "reload", "boatl", "Hornblower_board_Natividad2");
		break;

		case "Hornblower_board_Natividad2":
			ChangeCharacterAddressGroup(CharacterFromID("Matthews"), "ShipDeck2", "rld", "loc14");
			LAi_SetWarriorType(CharacterFromID("Matthews"));
			LAi_group_MoveCharacter(CharacterFromID("Matthews"), LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(CharacterFromID("Styles"), "ShipDeck2", "goto", "goto1");
			LAi_SetWarriorType(CharacterFromID("Styles"));
			LAi_group_MoveCharacter(CharacterFromID("Styles"), LAI_GROUP_PLAYER);
			LAi_SetWarriorType(CharacterFromID("Perrin"));
			ChangeCharacterAddressGroup(CharacterFromID("Perrin"), "ShipDeck2", "rld", "loc13");
			LAi_group_MoveCharacter(CharacterFromID("Perrin"), LAI_GROUP_PLAYER);
			ChangeCharacterAddressGroup(CharacterFromID("Oldroyd"), "ShipDeck2", "goto", "goto2");
			LAi_SetWarriorType(CharacterFromID("Oldroyd"))
			LAi_group_MoveCharacter(CharacterFromID("Oldroyd"), LAI_GROUP_PLAYER);
//			ChangeCharacterAddressGroup(CharacterFromID("Marsh"), "ShipDeck2", "rld", "loc12");
//			LAi_SetWarriorType(CharacterFromID("Marsh"));
//			LAi_group_MoveCharacter(CharacterFromID("Marsh"), LAI_GROUP_PLAYER);
			LAi_SetImmortal(CharacterFromID("Styles"), true);
			LAi_SetImmortal(CharacterFromID("Matthews"), true);
/*			PChar.quest.Hornblower_Natividad_alarm1.win_condition.l1 = "locator";
			PChar.quest.Hornblower_Natividad_alarm1.win_condition.l1.location = "ShipDeck2";
			PChar.quest.Hornblower_Natividad_alarm1.win_condition.l1.locator_group = "rld";
			PChar.quest.Hornblower_Natividad_alarm1.win_condition.l1.locator = "loc1";
			PChar.quest.Hornblower_Natividad_alarm1.win_condition = "Hornblower_Natividad_alarm";

			PChar.quest.Hornblower_Natividad_alarm2.win_condition.l1 = "locator";
			PChar.quest.Hornblower_Natividad_alarm2.win_condition.l1.location = "ShipDeck2";
			PChar.quest.Hornblower_Natividad_alarm2.win_condition.l1.locator_group = "rld";
			PChar.quest.Hornblower_Natividad_alarm2.win_condition.l1.locator = "loc2";
			PChar.quest.Hornblower_Natividad_alarm2.win_condition = "Hornblower_Natividad_alarm"; */
			ChangeCharacterAddressGroup(CharacterFromID("Lt. William Bush"), "ShipDeck2", "goto", "goto1");
			if (!LAi_IsDead(characterFromID("Midshipman Longley")))
			{
				ChangeCharacterAddressGroup(CharacterFromID("Midshipman Longley"), "ShipDeck2", "goto", "goto2");
				LAi_SetActorType(characterFromID("Midshipman Longley"));
				LAi_ActorRunToLocator(characterFromID("Midshipman Longley"), "rld", "loc1", "", 10.0);
			}
			LAi_SetActorType(PChar);
			LAi_ActorRunToLocator(PChar, "rld", "loc2", "Hornblower_Natividad_alarm", 10.0);
		break;

		case "Hornblower_Natividad_alarm":
			LAi_ActorTurnToLocator(PChar, "rld", "loc8");
			LAi_QuestDelay("Hornblower_turns_round", 1.0);
		break;

		case "Hornblower_turns_round":
			LAi_SetPlayerType(PChar);
			if (LAi_IsDead(characterFromID("Midshipman Longley"))) LAi_QuestDelay("Hornblower_Natividad_alarm2", 0.1);
			else
			{
				LAi_SetActorType(characterFromID("Midshipman Longley"));
				Characters[GetCharacterIndex("Midshipman Longley")].dialog.CurrentNode = "wake_them_up";
				LAi_ActorDialog(characterFromID("Midshipman Longley"), PChar, "Hornblower_Longley_alarm",5.0,5.0);
			}
		break;

		case "Hornblower_Longley_alarm":
			LAi_SetActorType(characterFromID("Midshipman Longley"));
			LAi_ActorGoToLocator(characterFromID("Midshipman Longley"), "rld", "loc1", "Hornblower_Natividad_alarm2", 10.0);
		break;

		case "Hornblower_Natividad_alarm2":
			if (!LAi_IsDead(characterFromID("Midshipman Longley")))
			{
				LAi_SetOfficerType(characterFromID("Midshipman Longley"));
				SetCharacterRemovable(characterFromID("Midshipman Longley"), true);
			}
           		PlaySound("Ambient\Sea\bell6_0300_0700_1100.wav");
			LAi_QuestDelay("Hornblower_Natividad_deck_battle", 2.0);
		break;

		case "Hornblower_Natividad_deck_battle":
			PlaySound("OBJECTS\abordage\abordage2.wav");
			for (i=1; i<5; i++)
			{
				attr = "m" + i;
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[SPAIN].fantomModel.(attr),  "reload", "reload1");
				TakeItemFromCharacter(sld, CheckCharacterEquipByGroup(sld, BLADE_ITEM_TYPE));
				TakeItemFromCharacter(sld, FindCharacterItemByGroup(sld, GUN_ITEM_TYPE));
				GiveItem2Character(sld, "blade4");
				EquipCharacterByItem(sld, "blade4");
				GiveItem2Character(sld, "PiratesPistol");
				EquipCharacterByItem(sld,"PiratesPistol");
				if (ENABLE_AMMOMOD) {	// LDH change
					TakenItems(sld, "gunpowder", 1 + rand(2));
					TakenItems(sld, "pistolbullets", 1 + rand(2));
				}
				sld.id = "Natividad guard " + i;
				sld.nation = SPAIN;
				SetRandomNameToCharacter(sld);
				LAi_SetWarriorType(sld);
				LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
				LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
				LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			}
			NPChar = CharacterFromID("Natividad_captain");
			ChangeCharacterAddressGroup(NPChar, "ShipDeck2", "rld", "startloc");
			LAi_SetHP(NPChar, 800.0, 800.0);
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "rld", "startloc");
			LAi_QuestDelay("Hornblower_Natividad_captain_attacks", 1.0);
		break;

		case "Hornblower_Natividad_captain_attacks":
			LAi_SetPlayerType(PChar);
			NPChar = CharacterFromID("Natividad_captain");
			LAi_SetActorType(NPChar);
			LAi_ActorAttack(NPChar, PChar, "");
	        	LAi_SetCheckMinHP(NPChar, LAi_GetCharacterHP(NPChar)*0.25, false, "Hornblower_Natividad_surrender");
		break;

		case "Hornblower_Natividad_surrender":
			LAi_LocationFightDisable(&Locations[FindLocation("ShipDeck2")], true);
			LAi_SetFightMode(PChar, false);
			DeleteAttribute(&PChar,"vcskip");
			LAi_SetActorType(CharacterFromID("Natividad_captain"));
			Characters[GetCharacterIndex("Natividad_captain")].dialog.CurrentNode = "Natividad_captain_surrender";
			LAi_ActorDialog(characterFromID("Natividad_captain"), PChar, "Hornblower_put_them_in_irons",5.0,5.0);
		break;

		case "Hornblower_put_them_in_irons":
			if (!LAi_IsDead(characterFromID("Midshipman Longley")))
			{
				LAi_SetActorType(characterFromID("Midshipman Longley"));
				LAi_ActorGoToLocator(characterFromID("Midshipman Longley"), "rld", "loc1", "", 30.0);
			}
			LAi_SetActorType(CharacterFromID("Lt. William Bush"));
			LAi_ActorRunToLocator(characterFromID("Lt. William Bush"), "rld", "loc0", "Hornblower_put_them_in_irons2", 30.0);
		break;

		case "Hornblower_put_them_in_irons2":
			if (!LAi_IsDead(characterFromID("Midshipman Longley"))) LAi_SetOfficerType(characterFromID("Midshipman Longley"));
			LAi_SetActorType(CharacterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "put_them_in_irons";
			LAi_ActorDialog(characterFromID("Lt. William Bush"), PChar, "Hornblower_Natividad_captain_protests",10.0,10.0);
		break;

		case "Hornblower_Natividad_captain_protests":
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			LAi_SetActorType(CharacterFromID("Natividad_captain"));
			Characters[GetCharacterIndex("Natividad_captain")].dialog.CurrentNode = "Natividad_rules_of_war";
			LAi_ActorDialog(characterFromID("Natividad_captain"), PChar, "Hornblower_Natividad_captured",5.0,5.0);
		break;

		case "Hornblower_Natividad_captured":
			Preprocessor_AddQuestData("our_ship", PChar.ship.name);
			AddQuestRecord("Natividad", 6);
			Preprocessor_Remove("our_ship");
			PChar.quest.oldship.name = PChar.ship.name;
			ExchangeCharacterShip(PChar, characterFromID("El Supremo"));
			ExchangeCharacterShip(PChar, characterFromID("Natividad_captain"));
			SetCurrentTime(7, 0);
			SetNextWeather("Clear");
			Locations[FindLocation("ShipDeck2")].models.always.locators = "udeck_ld_gr";
			DoQuestReloadToLocation("ShipDeck2", "rld", "loc0", "Hornblower_Natividad_captured2");
		break;

		case "Hornblower_Natividad_captured2":
			ChangeCharacterAddress(characterFromID("Natividad_captain"), "None", "");
			ChangeCharacterAddressGroup(CharacterFromID("Lt. William Bush"), "ShipDeck2", "rld", "loc2");
			ChangeCharacterAddress(characterFromID("Midshipman Longley"), "None", "");
			SetCharacterRemovable(characterFromID("Midshipman Longley"), false);
			RemoveOfficersIndex(pchar, GetCharacterIndex("Midshipman Longley"));
//			if (!LAi_IsDead(characterFromID("Midshipman Longley"))) ChangeCharacterAddressGroup(CharacterFromID("Midshipman Longley"), "ShipDeck2", "rld", "loc1");
			LAi_SetActorType(CharacterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "shes_a_beauty";
			LAi_ActorDialog(characterFromID("Lt. William Bush"), PChar, "",5.0,5.0);
//			LAi_QuestDelay("Hornblower_11_gun_salute", 5.0);
		break;

		case "Hornblower_Natividad_handover":	// Triggered by dialog with Lt. William Bush
			SetCharacterShipLocation(characterFromID("Jose Hernandez"), "ShipDeck2");
			DoQuestReloadToLocation("ShipDeck2", "rld", "loc0", "Hornblower_Natividad_handover2");
		break;

		case "Hornblower_Natividad_handover2":
			ChangeCharacterAddressGroup(CharacterFromID("Lt. William Bush"), "ShipDeck2", "rld", "loc2");
			ChangeCharacterAddressGroup(CharacterFromID("Matthews"), "ShipDeck2", "reload", "reload1");
			ChangeCharacterAddressGroup(CharacterFromID("Styles"), "ShipDeck2", "reload", "reload1");
			ChangeCharacterAddressGroup(CharacterFromID("Perrin"), "ShipDeck2", "reload", "reload1");
			ChangeCharacterAddressGroup(CharacterFromID("Oldroyd"), "ShipDeck2", "reload", "reload1");
			ChangeCharacterAddressGroup(CharacterFromID("Marsh"), "ShipDeck2", "reload", "reload1");
			ChangeCharacterAddressGroup(CharacterFromID("Midshipman Longley"), "ShipDeck2", "reload", "reload1");
			for (i=1; i<5; i++)
			{
				attr = "m" + i;
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.(attr), "rld", "loc" + (i+2));
				LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
				GiveSoldierWeapon(sld, ENGLAND);
				sld.id = "ship_guard1";
				LAi_SetActorType(sld);
				LAi_ActorTurnToLocator(sld, "reload", "boatl");
			}
//			if (!LAi_IsDead(characterFromID("Midshipman Longley")))
//			{
//				ChangeCharacterAddressGroup(CharacterFromID("Midshipman Longley"), "ShipDeck2", "rld", "loc1");
//				LAi_SetOfficerType(characterFromID("Midshipman Longley"));
//			}
			LAi_SetActorType(CharacterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "El_Supremo_boarding";
			LAi_ActorDialog(characterFromID("Lt. William Bush"), PChar, "",5.0,5.0);
		break;

		case "Hornblower_11_gun_salute":	// Triggered by dialog with Lt. William Bush
			LAi_SetOfficerType(characterFromID("Lt. William Bush"));
			ChangeCharacterAddressGroup(CharacterFromID("El Supremo"), "ShipDeck2", "reload", "boatl");
			ChangeCharacterAddressGroup(CharacterFromID("Jose Hernandez"), "ShipDeck2", "reload", "boatl");
			LAi_ActorFollow(CharacterFromID("Jose Hernandez"), CharacterFromID("El Supremo"), "", 10.0);

			PChar.quest.cannon_number = 1;
			for (i=0; i<11; i++)
			{
				LAi_QuestDelay("Hornblower_fire_salute_cannon", i * 1.0);
			}
			LAi_QuestDelay("Hornblower_El_Supremo_wants_more_guns", 11.5);
		break;

		case "Hornblower_fire_salute_cannon":
			j = iclamp(1,11,sti(PChar.quest.cannon_number));
			PChar.quest.cannon_number = j + 1;
			locatorName = "cannon" + (100 + j);
			ReadLocatorCoordinates("cannon", locatorName, &x1, &y1, &z1);
			CreateParticleSystemX("blast_inv", x1, y1, z1, -0.8768, 0.0, 0.0,0);
			CreateParticleSystemX("cancloud", x1, y1, z1, -0.8768, 0.0, 0.0,20);
			CreateParticleSystemX("cancloud", x1, y1, z1, -0.8768, 0.0, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire1.wav");
		break;

		case "Hornblower_El_Supremo_wants_more_guns":
			LAi_SetActorType(characterFromID("Jose Hernandez"));
			LAi_ActorFollow(characterFromID("Jose Hernandez"), characterFromID("El Supremo"), "", 25.0);
			LAi_SetActorType(characterFromID("El Supremo"));
			LAi_ActorGoToLocator(characterFromID("El Supremo"), "rld", "loc1", "Hornblower_El_Supremo_wants_more_guns2", 15.0);
		break;

		case "Hornblower_El_Supremo_wants_more_guns2":
			LAi_SetActorType(characterFromID("El Supremo"));
			Characters[GetCharacterIndex("El Supremo")].dialog.CurrentNode = "wrong_signal";
			LAi_ActorDialog(characterFromID("El Supremo"), PChar, "Hornblower_El_Supremo_inspects_crew",5.0,5.0);
		break;

		case "Hornblower_El_Supremo_inspects_crew":
			LAi_SetActorType(characterFromID("El Supremo"));
			LAi_ActorTurnToLocator(characterFromID("El Supremo"), "rld", "aloc8");
			LAi_QuestDelay("Hornblower_El_Supremo_inspects_crew2", 2.0);
		break;

		case "Hornblower_El_Supremo_inspects_crew2":
			LAi_SetActorType(characterFromID("El Supremo"));
			Characters[GetCharacterIndex("El Supremo")].dialog.CurrentNode = "you_did_not_kill_many";
			LAi_ActorDialog(characterFromID("El Supremo"), PChar, "Hornblower_return_to_own_ship",5.0,5.0);
		break;

		case "Hornblower_return_to_own_ship":
			LAi_SetActorType(CharacterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "return_to_ship";
			LAi_ActorDialog(characterFromID("Lt. William Bush"), PChar, "Hornblower_return_to_own_ship2",10.0,10.0);
		break;

		case "Hornblower_return_to_own_ship2":
			ChangeCharacterAddress(characterFromID("Midshipman Longley"), "None", "");
			SetCharacterRemovable(characterFromID("Lt. William Bush"), true);
			LAi_SetImmortal(characterfromID("Lt. William Bush"), false);
			LAi_SetImmortal(CharacterFromID("Styles"), false);
			LAi_SetImmortal(CharacterFromID("Matthews"), false);
			bQuestDisableSeaEnter = false;
			DisableFastTravel(false);

			ExchangeCharacterShip(PChar, characterFromID("El Supremo"));
//			PChar.ship.name = PChar.quest.oldship.name;
			DeleteQuestAttribute("oldship.name");
			DeleteQuestAttribute("oldship");
			DeleteQuestAttribute("cannon_number");
			AddQuestRecord("Natividad", 7);

			Characters[GetCharacterIndex("El Supremo")].Flags.Personal = 0;
			Characters[GetCharacterIndex("El Supremo")].Flags.Personal.texture = 5;
            		Characters[GetCharacterIndex("El Supremo")].nation = PERSONAL_NATION;
			PChar.quest.Natividad_Group = Group_CreateGroup("Natividad_El_Supremo");
			Group_AddCharacter("Natividad_El_Supremo", "El Supremo");
			Group_SetGroupCommander("Natividad_El_Supremo", "El Supremo");

			Group_SetPursuitGroup("Natividad_El_Supremo", PLAYER_GROUP);
			Group_SetAddress("Natividad_El_Supremo", "Cuba", "Quest_ships", "quest_ship_7");
			Sea_LoginGroupNow("Natividad_El_Supremo");

			QuestToSeaLogin_PrepareLoc("Cuba", "reload", "reload_9", false);
			QuestToSeaLogin_Launch();

			LAi_LocationFightDisable(&Locations[FindLocation("ShipDeck2")], false);
			ChangeCharacterAddress(CharacterFromID("Jose Hernandez"), "None", "");

			PChar.quest.Hornblower_Muelle_arrival.win_condition.l1 = "location";
			PChar.quest.Hornblower_Muelle_arrival.win_condition.l1.location = "IslaMuelle";
			PChar.quest.Hornblower_Muelle_arrival.win_condition = "Hornblower_Muelle_arrival";
			PChar.quest.Hornblower_prepare_for_lugger_captain.win_condition.l1 = "location";
			PChar.quest.Hornblower_prepare_for_lugger_captain.win_condition.l1.location = "IslaMuelle";
			PChar.quest.Hornblower_prepare_for_lugger_captain.win_condition = "Hornblower_Bush_reports_lugger";
		break;

		case "Hornblower_Muelle_arrival":
			PChar.quest.Spanish_Lugger_Group = Group_CreateGroup("Spanish lugger");
			Group_AddCharacter("Spanish lugger", "Spanish_lugger_captain");
			Group_SetGroupCommander("Spanish lugger", "Spanish_lugger_captain");

			Group_SetPursuitGroup("Spanish lugger", PLAYER_GROUP);
			Group_SetAddress("Spanish lugger", "IslaMuelle", "Quest_ships", "quest_ship_1");
//			Sea_LoginGroupNow("Spanish lugger");
		break;

		case "Hornblower_prepare_for_lugger_captain":
			PlaySound("INTERFACE\_EvEnemy1.wav");
			LAi_QuestDelay("Hornblower_to_deck_for_lugger_captain", 5.0);
		break;

		case "Hornblower_Bush_reports_lugger":
			PlaySound("INTERFACE\_EvEnemy1.wav");
			SetNationRelationBoth(ENGLAND, SPAIN, RELATION_FRIEND);
			SetNationRelationBoth(SPAIN, FRANCE, RELATION_ENEMY);
			SetNationRelationBoth(ENGLAND, FRANCE, RELATION_ENEMY);	// Just in case random relations have put them at peace by now
			if (GetNationRelation2MainCharacter(SPAIN) == RELATION_ENEMY) SetRMRelation(PChar, SPAIN, REL_NEUTRAL);
			StartQuestMovie(true, true, false);
			ChangeCharacterAddressGroup(CharacterFromID("Lt. William Bush"), "Cabin_medium", "reload", "reload1");
			DoReloadFromSeaToLocation("Cabin_medium", "rld", "startloc");
			LAi_QuestDelay("Hornblower_Bush_reports_lugger2", 0.1);
		break;

		case "Hornblower_Bush_reports_lugger2":
			LAi_SetActorType(CharacterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "lugger_report";
			LAi_ActorDialog(characterFromID("Lt. William Bush"), PChar, "Hornblower_to_deck_for_lugger_captain",5.0,5.0);
		break;

		case "Hornblower_to_deck_for_lugger_captain":
			ChangeCharacterAddressGroup(CharacterFromID("Lt. William Bush"), "ShipDeck1", "goto", "goto3");
			ChangeCharacterAddressGroup(CharacterFromID("Lieutenant Gerard"), "ShipDeck1", "rld", "loc4");
			ChangeCharacterAddressGroup(CharacterFromID("Matthews"), "ShipDeck1", "goto", "goto2");
			ChangeCharacterAddressGroup(CharacterFromID("Styles"), "ShipDeck1", "goto", "goto1");
			ChangeCharacterAddressGroup(CharacterFromID("Oldroyd"), "ShipDeck1", "goto", "goto11");
			ChangeCharacterAddressGroup(CharacterFromID("Marsh"), "ShipDeck1", "goto", "goto12");
			LAi_SetCitizenTypeNoGroup(CharacterFromID("Matthews"));
			LAi_SetCitizenTypeNoGroup(CharacterFromID("Styles"));
			LAi_SetCitizenTypeNoGroup(CharacterFromID("Oldroyd"));
			LAi_SetCitizenTypeNoGroup(CharacterFromID("Marsh"));
			SetCharacterShipLocation(characterFromID("Spanish_lugger_captain"), "ShipDeck1");
			DoQuestReloadToLocation("ShipDeck1", "rld", "loc2", "Hornblower_Gerard_reports_women");
//			DoReloadFromSeaToLocation("ShipDeck1", "rld", "loc2");
//			LAi_QuestDelay("Hornblower_to_deck_for_lugger_captain2", 0.1);
		break;

		case "Hornblower_Gerard_reports_women":
			if (!LAi_IsDead(characterFromID("Midshipman Longley")))
			{
				ChangeCharacterAddressGroup(CharacterFromID("Midshipman Longley"), "ShipDeck1", "goto", "goto1");
				LAi_SetActorType(characterFromID("Midshipman Longley"));
				LAi_ActorTurnToLocator(characterFromID("Midshipman Longley"), "reload", "boatl");
			}
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "goto", "goto5");
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			GiveSoldierWeapon(sld, ENGLAND);
			sld.id = "ship_guard1";
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "goto", "goto2");
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "goto10");
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			GiveSoldierWeapon(sld, ENGLAND);
			sld.id = "ship_guard2";
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "goto", "goto2");
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "goto9");
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			GiveSoldierWeapon(sld, ENGLAND);
			sld.id = "ship_guard3";
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "goto", "goto2");
			LAi_SetActorType(CharacterFromID("Lieutenant Gerard"));
			Characters[GetCharacterIndex("Lieutenant Gerard")].dialog.CurrentNode = "women_aboard";
			LAi_ActorDialog(characterFromID("Lieutenant Gerard"), PChar, "Hornblower_to_deck_for_lugger_captain2",5.0,5.0);
		break;

		case "Hornblower_to_deck_for_lugger_captain2":
			LAi_SetOfficerType(CharacterFromID("Lt. William Bush"));
			LAi_SetOfficerType(CharacterFromID("Lieutenant Gerard"));
			PlaySound("OBJECTS\shipcharge\Eng_the_side.wav");
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "reload", "boatl");
			LAi_QuestDelay("Hornblower_to_deck_for_lugger_captain3", 2.0);
		break;

		case "Hornblower_to_deck_for_lugger_captain3":
			LAi_SetPlayerType(PChar);
			ChangeCharacterAddressGroup(CharacterFromID("Spanish_lugger_captain"), "ShipDeck1", "reload", "boatl");
			LAi_SetActorType(characterFromID("Spanish_lugger_captain"));
			LAi_ActorGoToLocator(characterFromID("Spanish_lugger_captain"), "goto", "goto2", "Hornblower_lugger_captain_boards2", 10.0);
		break;

		case "Hornblower_lugger_captain_boards2":
			LAi_SetActorType(characterFromID("Spanish_lugger_captain"));
			Characters[GetCharacterIndex("Spanish_lugger_captain")].dialog.CurrentNode = "introductions";
			LAi_ActorDialog(characterFromID("Spanish_lugger_captain"), PChar, "Hornblower_Bush_to_get_prisoners",5.0,5.0);
		break;

		case "Hornblower_Bush_to_get_prisoners":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "Bring the prisoners";
			LAi_ActorDialog(characterFromID("Lt. William Bush"), PChar, "Hornblower_lugger_captain_continues",5.0,5.0);
		break;

		case "Hornblower_Bush_to_get_prisoners2":	// Triggered by dialog with Lt. William Bush
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			LAi_ActorGoToLocation(CharacterFromID("Lt. William Bush"), "reload", "reload1", "none", "", "", "", 30);
		break;

		case "Hornblower_lugger_captain_continues":
			LAi_SetActorType(characterFromID("Spanish_lugger_captain"));
			Characters[GetCharacterIndex("Spanish_lugger_captain")].dialog.CurrentNode = "new king";
			LAi_ActorDialog(characterFromID("Spanish_lugger_captain"), PChar, "Hornblower_prisoners_arrive",5.0,5.0);
		break;

		case "Hornblower_prisoners_arrive":
			ChangeCharacterAddressGroup(CharacterFromID("Lt. William Bush"), "ShipDeck1", "reload", "reload1");
			LAi_SetOfficerType(CharacterFromID("Lt. William Bush"));
			ChangeCharacterAddressGroup(CharacterFromID("Natividad_captain"), "ShipDeck1", "reload", "reload3");
			LAi_SetActorType(characterFromID("Spanish_lugger_captain"));
			LAi_ActorGoToLocator(characterFromID("Spanish_lugger_captain"), "goto", "goto15", "Spanish_lugger_captain_turns", 10.0);
			LAi_SetActorType(characterFromID("Natividad_captain"));
			LAi_ActorGoToLocator(characterFromID("Natividad_captain"), "goto", "goto16", "", 10.0);
//			LAi_ActorFollow(characterFromID("Natividad_captain"), characterFromID("Spanish_lugger_captain"), "", 25.0);
			LAi_QuestDelay("Hornblower_prisoners_arrive2", 2.0);
		break;

		case "Spanish_lugger_captain_turns":
			LAi_SetActorType(characterFromID("Spanish_lugger_captain"));
			LAi_ActorTurnToLocator(characterFromID("Spanish_lugger_captain"), "reload", "reload3");
		break;

		case "Hornblower_prisoners_arrive2":
			for (i=0; i<3; i++)
			{
				attr = "m" + i;
				locatorName = "reload3_" + (i+1);
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[SPAIN].fantomModel.(attr), "reload", "reload3");
				sld.id = "Spanish_prisoner" + i;
				TakeItemFromCharacter(sld, FindCharacterItemByGroup(sld, BLADE_ITEM_TYPE));
				TakeItemFromCharacter(sld, FindCharacterItemByGroup(sld, GUN_ITEM_TYPE));
				LAi_SetActorType(sld);
				LAi_ActorGoToLocator(sld, "reload", locatorName, "", 10.0);
			}
			LAi_QuestDelay("Hornblower_prisoners_arrive3", 1.0);
			LAi_QuestDelay("Hornblower_read_letter", 2.0);
			LAi_QuestDelay("Hornblower_Lady_Barbara_arrives", 3.0);
		break;

		case "Hornblower_prisoners_arrive3":
			for (i=0; i<3; i++)
			{
				sld = CharacterFromID("Spanish_prisoner" + i);
				LAi_SetActorType(sld);
				LAi_ActorFollow(sld, characterFromID("Natividad_captain"), "", 25.0);
			}
		break;

		case "Hornblower_read_letter":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "rld", "startloc");
			LAi_QuestDelay("Hornblower_read_letter2", 0.5);
			LAi_SetActorType(CharacterFromID("Lieutenant Gerard"));
			LAi_ActorGoToLocator(characterFromID("Lieutenant Gerard"), "goto", "goto4", "", 30.0);
		break;

		case "Hornblower_read_letter2":
			PChar.dialog.filename = "blaze_dialog.c";
			Pchar.dialog.CurrentNode = "sidequest_Admiralty_letter";
			LAi_SetActorType(PChar);
			LAi_ActorSelfDialog(PChar, "Hornblower_Lady_Barbara_arrives2");
		break;

		case "Hornblower_Lady_Barbara_arrives":
			ChangeCharacterAddressGroup(CharacterFromID("Lady Barbara Wellesley"), "ShipDeck1", "reload", "boatl");
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			LAi_ActorGoToLocator(characterFromID("Lady Barbara Wellesley"), "goto", "goto2", "", 10.0);
		break;

		case "Hornblower_Lady_Barbara_arrives2":
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			Characters[GetCharacterIndex("Lady Barbara Wellesley")].dialog.CurrentNode = "welcome_aboard";
			LAi_ActorDialog(characterFromID("Lady Barbara Wellesley"), PChar, "Hornblower_Hebe_arrives",5.0,5.0);
		break;

		case "Hornblower_Hebe_arrives":
			ChangeCharacterAddressGroup(CharacterFromID("Hebe"), "ShipDeck1", "reload", "boatl");
			if (!LAi_IsDead(characterFromID("Midshipman Longley")))
			{
//				NPChar = CharacterFromID("Midshipman Longley");
				PChar.quest.Hornblower_officer = "Midshipman Longley";
			}
			else
			{
//				NPChar = CharacterFromID("Lieutenant Gerard");
//				NPChar.dialog.Filename = "Midshipman Longley_dialog.c";
				PChar.quest.Hornblower_officer = "Lieutenant Gerard";
			}
			NPChar = CharacterFromID(PChar.quest.Hornblower_officer);
			NPChar.dialog.Filename = "Midshipman Longley_dialog.c";
			LAi_SetActorType(NPChar);
			NPChar.dialog.CurrentNode = "what_is_screaming";
			LAi_ActorDialogNow(NPChar, PChar, "Hornblower_Ladies_want_passage",1.0);
		break;

		case "Hornblower_Ladies_want_passage":
			LAi_SetActorType(characterFromID("Hebe"));
			LAi_ActorGoToLocator(characterFromID("Hebe"), "goto", "goto2", "Hornblower_Hebe_follows_Barbara", 10.0);
//			LAi_ActorGoToLocation(CharacterFromID("Hebe"), "reload", "reload2", "none", "", "", "", 30);
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			Characters[GetCharacterIndex("Lady Barbara Wellesley")].dialog.CurrentNode = "require_passage";
			LAi_ActorDialog(characterFromID("Lady Barbara Wellesley"), PChar, "Hornblower_lugger_captain_protests",5.0,5.0);
		break;

		case "Hornblower_Hebe_follows_Barbara":
			LAi_ActorFollow(characterFromID("Hebe"), characterFromID("Lady Barbara Wellesley"), "", 25.0);
		break;

		case "Hornblower_lugger_captain_protests":
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			LAi_ActorTurnToLocator(characterFromID("Lady Barbara Wellesley"), "ships", "ship_1");
			LAi_SetActorType(characterFromID("Spanish_lugger_captain"));
			Characters[GetCharacterIndex("Spanish_lugger_captain")].dialog.CurrentNode = "gave_away_Natividad";
			LAi_ActorDialog(characterFromID("Spanish_lugger_captain"), PChar, "Hornblower_ladies_cant_stay",5.0,5.0);
		break;

		case "Hornblower_ladies_cant_stay":
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			Characters[GetCharacterIndex("Lady Barbara Wellesley")].dialog.CurrentNode = "you_cant_stay_aboard";
			LAi_ActorDialog(characterFromID("Lady Barbara Wellesley"), PChar, "Hornblower_adios_lugger_captain",5.0,5.0);
		break;

		case "Hornblower_adios_lugger_captain":
			NPChar = CharacterFromID(PChar.quest.Hornblower_officer);
			LAi_SetActorType(NPChar);
			LAi_ActorGoToLocator(NPChar, "reload", "reload3", "", 30.0);
			LAi_SetActorType(characterFromID("Spanish_lugger_captain"));
			Characters[GetCharacterIndex("Spanish_lugger_captain")].dialog.CurrentNode = "adios";
			LAi_ActorDialog(characterFromID("Spanish_lugger_captain"), PChar, "Hornblower_cabin_moves1",5.0,5.0);
		break;

		case "Hornblower_cabin_moves1":
			LAi_SetActorType(characterFromID("Spanish_lugger_captain"));
			LAi_ActorGoToLocation(CharacterFromID("Spanish_lugger_captain"), "reload", "boatl", "none", "", "", "", 60);
			LAi_SetActorType(characterFromID("Natividad_captain"));
			LAi_ActorGoToLocation(CharacterFromID("Natividad_captain"), "reload", "boatl", "none", "", "", "", 60);
			for (i=0; i<3; i++)
			{
				sld = CharacterFromID("Spanish_prisoner" + i);
				LAi_ActorGoToLocation(sld, "reload", "boatl", "none", "", "", "", 60);
			}

			NPChar = CharacterFromID(PChar.quest.Hornblower_officer);
			NPChar.dialog.Filename = "Midshipman Longley_dialog.c";
			LAi_SetActorType(NPChar);
			NPChar.dialog.CurrentNode = "cabin_moves";
			LAi_ActorDialog(NPChar, PChar, "Hornblower_cabin_moves2",15.0,15.0);
		break;

		case "Hornblower_cabin_moves2":
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			Characters[GetCharacterIndex("Lady Barbara Wellesley")].dialog.CurrentNode = "regret_insistence";
			LAi_ActorDialog(characterFromID("Lady Barbara Wellesley"), PChar, "Hornblower_cabin_scene1",5.0,5.0);
		break;

		case "Hornblower_cabin_scene1":
			AddPassenger(Pchar, characterFromID("Lady Barbara Wellesley"), 0);
			Characters[GetCharacterIndex("Lady Barbara Wellesley")].quest.officertype = OFFIC_TYPE_DOCTOR;
			SetCharacterRemovable(characterFromID("Lady Barbara Wellesley"), false);
			DoQuestReloadToLocation("Cabin_medium", "reload", "reload1", "Hornblower_becomes_Longley_for_cabin_scene2");
		break;

		case "Hornblower_becomes_Longley_for_cabin_scene2":
			ChangeCharacterAddress(characterFromID("Spanish_lugger_captain"), "None", "");
			ChangeCharacterAddress(characterFromID("Natividad_captain"), "None", "");
			PChar.quest.old_model = PChar.model;
			PChar.quest.old_name = PChar.name;
			PChar.quest.old_lastname = PChar.lastname;
			SetModelFromID(PChar, "brtmds3_18");
			PChar.name = "Midshipman";
			PChar.lastname = GetMyLastName(CharacterFromID(PChar.quest.Hornblower_officer));
			LAi_SetActorType(PChar);
			ChangeCharacterAddressGroup(CharacterFromID("Lady Barbara Wellesley"), "Cabin_medium", "reload", "reload1");
			LAi_SetActorType(CharacterFromID("Lady Barbara Wellesley"));
			LAi_ActorGoToLocator(CharacterFromID("Lady Barbara Wellesley"), "rld", "aloc0", "", 10.0);
			LAi_QuestDelay("Hornblower_cabin_scene3", 0.2);
		break;

		case "Hornblower_cabin_scene3":
			LAi_ActorGoToLocator(PChar, "rld", "aloc2", "Hornblower_cabin_scene4", 10.0);
		break;

		case "Hornblower_cabin_scene4":
			ChangeCharacterAddressGroup(CharacterFromID("Hebe"), "Cabin_medium", "reload", "reload1");
			LAi_SetActorType(CharacterFromID("Hebe"));
			LAi_ActorGoToLocator(CharacterFromID("Hebe"), "rld", "aloc1", "", 10.0);
			LAi_SetPlayerType(PChar);
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			Characters[GetCharacterIndex("Lady Barbara Wellesley")].dialog.CurrentNode = "not_disturbing";
			LAi_ActorDialog(characterFromID("Lady Barbara Wellesley"), PChar, "Hornblower_second_opinion",5.0,5.0);
		break;

		case "Hornblower_second_opinion":
			ChangeCharacterAddressGroup(CharacterFromID("Oldroyd"), "Cabin_medium", "reload", "reload1");
			LAi_SetActorType(characterFromID("Oldroyd"));			
			Characters[GetCharacterIndex("Oldroyd")].dialog.Filename = "Hornblower_quest_minors_dialog.c";
			Characters[GetCharacterIndex("Oldroyd")].dialog.CurrentNode = "second_opinion";
			LAi_ActorDialog(characterFromID("Oldroyd"), PChar, "Hornblower_yelling_from_deck",5.0,5.0);
		break;

		case "Hornblower_yelling_from_deck":
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			Characters[GetCharacterIndex("Lady Barbara Wellesley")].dialog.CurrentNode = "not_so_gentle";
			LAi_ActorDialog(characterFromID("Lady Barbara Wellesley"), PChar, "Hornblower_back_to_muelle_sea",5.0,5.0);
		break;

		case "Hornblower_back_to_muelle_sea":
			AddQuestRecord("Natividad", 8);
			SetModelFromID(PChar, PChar.quest.old_model);
			PChar.name = PChar.quest.old_name;
			PChar.lastname = PChar.quest.old_lastname;
			DeleteQuestAttribute("old_model");
			DeleteQuestAttribute("old_name");
			DeleteQuestAttribute("old_lastname");
			DeleteQuestAttribute("hornblower_officer");
			SetCharacterShipLocation(characterFromID("Spanish_lugger_captain"), "None");
			DoQuestReloadToLocation("ShipDeck1", "rld", "loc2", "Hornblower_back_to_muelle_sea2");
		break;

		case "Hornblower_back_to_muelle_sea2":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			Characters[GetCharacterIndex("Lt. William Bush")].dialog.CurrentNode = "still_ship_of_war";
			LAi_ActorDialog(characterFromID("Lt. William Bush"), PChar, "Hornblower_back_to_muelle_sea3",5.0,5.0);
		break;

		case "Hornblower_back_to_muelle_sea3":
			EndQuestMovie();
			LAi_SetOfficerType(CharacterFromID("Lt. William Bush"));
			LAi_SetOfficerType(CharacterFromID("Lieutenant Gerard"));
			LAi_SetOfficerType(CharacterFromID("Midshipman Longley"));
			Group_SetPursuitGroup("Spanish lugger", PLAYER_GROUP);
			Group_SetAddress("Spanish lugger", "IslaMuelle", "Quest_ships", "quest_ship_1");
//			Sea_LoginGroupNow("Spanish lugger");
			QuestToSeaLogin_PrepareLoc("IslaMuelle", "Quest_ships", "quest_ship_1", false);
			QuestToSeaLogin_Launch();

			PChar.quest.Hornblower_Natividad_battle.win_condition.l1 = "location";
			PChar.quest.Hornblower_Natividad_battle.win_condition.l1.location = "Cuba";
			PChar.quest.Hornblower_Natividad_battle.win_condition = "Hornblower_Natividad_battle";
		break;

		case "Hornblower_Natividad_battle":
			PChar.quest.Natividad_Group = Group_CreateGroup("Natividad_El_Supremo");
			Group_AddCharacter("Natividad_El_Supremo", "El Supremo");
			Group_SetGroupCommander("Natividad_El_Supremo", "El Supremo");
			Characters[GetCharacterIndex("El Supremo")].recognized = true;
			Characters[GetCharacterIndex("El Supremo")].skipRM = true;
			characters[GetCharacterIndex("El Supremo")].nosurrender = 2;

			if (ENABLE_WEAPONSMOD)
			{
				GiveItem2Character(characterFromID("El Supremo"), "blade14+1");
				GiveItem2Character(characterFromID("El Supremo"), "pistol8+1");
			}
			else
			{
				GiveItem2Character(characterFromID("El Supremo"), "blade14");
				GiveItem2Character(characterFromID("El Supremo"), "pistol8");
			}
			EquipCharacterByItem(characterFromID("El Supremo"), "blade14");
			EquipCharacterByItem(characterFromID("El Supremo"), "pistol8");
			if (ENABLE_AMMOMOD) {	// LDH change
				TakenItems(characterFromID("El Supremo"), "gunpowder", 1 + rand(2));
				TakenItems(characterFromID("El Supremo"), "pistolbullets", 1 + rand(2));
			}

			Group_SetPursuitGroup("Natividad_El_Supremo", PLAYER_GROUP);
			Group_SetAddress("Natividad_El_Supremo", "Cuba", "Quest_ships", "quest_ship_7");
			Sea_LoginGroupNow("Natividad_El_Supremo");

			pchar.quest.Hornblower_Natividad_battle_over.win_condition.l1 = "NPC_Death";
			pchar.quest.Hornblower_Natividad_battle_over.win_condition.l1.character = "El Supremo";
			pchar.quest.Hornblower_Natividad_battle_over.win_condition.l2 = "SeaEnter";
			pchar.quest.Hornblower_Natividad_battle_over.win_condition = "Hornblower_Natividad_battle_over";
		break;

		case "Hornblower_Natividad_battle_over":
			SetCharacterShipLocation(PChar, "Cuba_shore_02");
			PChar.location.from_sea = "Cuba_shore_02";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar");
//			ChangeCharacterAddressGroup(CharacterFromID("Lt. William Bush"), "ShipDeck1", "goto", "goto4");
			ChangeCharacterAddressGroup(CharacterFromID("Midshipman Longley"), "Seadogs", "sleep", "bed1");
			LAi_SetLayType(CharacterFromID("Midshipman Longley"));
			ChangeCharacterAddressGroup(CharacterFromID("Lady Barbara Wellesley"), "Seadogs", "rld", "aloc2");
			ChangeCharacterAddressGroup(CharacterFromID("Oldroyd"), "ShipDeck1", "goto", "goto16");
//			Locations[FindLocation("Seadogs")].vcskip = true;

			Pchar.quest.Hornblower_return_to_barbados.win_condition.l1 = "Location";
			PChar.quest.Hornblower_return_to_barbados.win_condition.l1.location = "Oxbay";
			PChar.quest.Hornblower_return_to_barbados.win_condition = "Hornblower_return_to_barbados";

			PostEvent("EventSeaToLocation", 5000, "ssss", "ShipDeck1", "goto", "goto15", "Hornblower_Natividad_battle_over2");
		break;

		case "Hornblower_Natividad_battle_over2":
			PChar.quest.Hornblower_to_deck_after_Natividad_battle.win_condition.l1 = "location";
			PChar.quest.Hornblower_to_deck_after_Natividad_battle.win_condition.l1.location = "ShipDeck1";
			PChar.quest.Hornblower_to_deck_after_Natividad_battle.win_condition = "Hornblower_to_deck_after_Natividad_battle";
		break;

		case "Hornblower_to_deck_after_Natividad_battle":
			ChangeCharacterAddress(CharacterFromID("El Supremo"), "None", "");
//			SetCharacterToNearLocatorFromMe("Oldroyd", 3);
			LAi_SetActorType(characterFromID("Oldroyd"));			
			Characters[GetCharacterIndex("Oldroyd")].dialog.Filename = "Hornblower_quest_minors_dialog.c";
			Characters[GetCharacterIndex("Oldroyd")].dialog.CurrentNode = "how_she_settling";
			LAi_ActorDialog(characterFromID("Oldroyd"), PChar, "Hornblower_Lady_Barbara_Longley",5.0,5.0);
		break;

		case "Hornblower_Lady_Barbara_Longley":
			DoQuestReloadToLocation("Seadogs", "reload", "reload2", "Hornblower_Lady_Barbara_Longley2");
		break;

		case "Hornblower_Lady_Barbara_Longley2":
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			LAi_ActorGoToLocator(CharacterFromID("Lady Barbara Wellesley"), "rld", "loc2", "Hornblower_Lady_Barbara_turns_to_Longley", 10.0);
			PChar.quest.Hornblower_Lady_Barbara_Longley3.win_condition.l1 = "locator";
			PChar.quest.Hornblower_Lady_Barbara_Longley3.win_condition.l1.location = "Seadogs";
			PChar.quest.Hornblower_Lady_Barbara_Longley3.win_condition.l1.locator_group = "rld";
			PChar.quest.Hornblower_Lady_Barbara_Longley3.win_condition.l1.locator = "loc2";
			PChar.quest.Hornblower_Lady_Barbara_Longley3.win_condition = "Hornblower_Lady_Barbara_Longley3";
		break;

		case "Hornblower_Lady_Barbara_turns_to_Longley":
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			LAi_ActorTurnToCharacter(characterFromID("Lady Barbara Wellesley"), CharacterFromID("Midshipman Longley"));
		break;

		case "Hornblower_Lady_Barbara_Longley3":
			LAi_SetActorType(characterFromID("Midshipman Longley"));
			LAi_ActorSetLayMode(characterFromID("Midshipman Longley"));
			Characters[GetCharacterIndex("Midshipman Longley")].dialog.CurrentNode = "came_back_to_mother";
			LAi_ActorDialogNow(characterFromID("Midshipman Longley"), PChar, "Hornblower_Lady_Barbara_to_Longley1",1.0);
		break;

		case "Hornblower_Lady_Barbara_to_Longley1":
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			Characters[GetCharacterIndex("Lady Barbara Wellesley")].dialog.CurrentNode = "answer_longley1";
			LAi_ActorDialogNow(characterFromID("Lady Barbara Wellesley"), PChar, "Hornblower_Longley_final_speech2",1.0);
		break;

		case "Hornblower_Longley_final_speech2":
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			LAi_ActorTurnToCharacter(characterFromID("Lady Barbara Wellesley"), CharacterFromID("Midshipman Longley"));
			LAi_SetActorType(characterFromID("Midshipman Longley"));
			LAi_ActorSetLayMode(characterFromID("Midshipman Longley"));
			Characters[GetCharacterIndex("Midshipman Longley")].dialog.CurrentNode = "did_you_miss_me";
			LAi_ActorDialogNow(characterFromID("Midshipman Longley"), PChar, "Hornblower_Lady_Barbara_to_Longley2",1.0);
		break;

		case "Hornblower_Lady_Barbara_to_Longley2":
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			Characters[GetCharacterIndex("Lady Barbara Wellesley")].dialog.CurrentNode = "answer_longley2";
			LAi_ActorDialogNow(characterFromID("Lady Barbara Wellesley"), PChar, "Hornblower_Longley_final_speech3",1.0);
		break;

		case "Hornblower_Longley_final_speech3":
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			LAi_ActorTurnToCharacter(characterFromID("Lady Barbara Wellesley"), CharacterFromID("Midshipman Longley"));
			LAi_SetActorType(characterFromID("Midshipman Longley"));
			LAi_ActorSetLayMode(characterFromID("Midshipman Longley"));
			Characters[GetCharacterIndex("Midshipman Longley")].dialog.CurrentNode = "kiss_me_mother";
			LAi_ActorDialogNow(characterFromID("Midshipman Longley"), PChar, "Hornblower_Lady_Barbara_to_Longley3",1.0);
		break;

		case "Hornblower_Lady_Barbara_to_Longley3":
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			Characters[GetCharacterIndex("Lady Barbara Wellesley")].dialog.CurrentNode = "not_know_how_to_kiss";
			LAi_ActorDialogNow(characterFromID("Lady Barbara Wellesley"), PChar, "Hornblower_Longley_final_speech4",1.0);
		break;

		case "Hornblower_Longley_final_speech4":
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			LAi_ActorTurnToCharacter(characterFromID("Lady Barbara Wellesley"), CharacterFromID("Midshipman Longley"));
			LAi_SetActorType(characterFromID("Midshipman Longley"));
			LAi_ActorSetLayMode(characterFromID("Midshipman Longley"));
			Characters[GetCharacterIndex("Midshipman Longley")].dialog.CurrentNode = "goodnight";
			LAi_ActorDialogNow(characterFromID("Midshipman Longley"), PChar, "Hornblower_goodnight_Longley",1.0);
		break;

		case "Hornblower_goodnight_Longley":
			AddQuestRecord("Natividad", 9);
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			Characters[GetCharacterIndex("Lady Barbara Wellesley")].dialog.CurrentNode = "how_did_you_know";
			LAi_ActorDialog(characterFromID("Lady Barbara Wellesley"), PChar, "",5.0,5.0);
			SetCharacterRemovable(characterFromID("Midshipman Longley"), true);
			RemoveOfficersIndex(PChar, GetCharacterIndex("Midshipman Longley"));
			RemovePassenger(PChar, characterFromID("Midshipman Longley"));
			bQuestDisableAllCommands = false;
			bQuestDisableSeaEnter = false;
			DisableFastTravel(false);
		break;

		case "Hornblower_return_to_barbados":
			DeleteQuestAttribute("natividad_group");
			DeleteQuestAttribute("spanish_lugger_group");
			SetNextWeather("Clear");
			AddDataToCurrent(0, 0, 1, true);
			SetCurrentTime(10, 0);
			SetCharacterShipLocation(PChar, "Greenford_port");
			PChar.location.from_sea = "Greenford_port";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "pchar");
			StartQuestMovie(true, true, false);
			ChangeCharacterAddressGroup(CharacterFromID("Lt. William Bush"), "ShipDeck1", "rld", "loc3");
			ChangeCharacterAddressGroup(CharacterFromID("Lieutenant Gerard"), "ShipDeck1", "rld", "loc4");
			DoReloadFromSeaToLocation("ShipDeck1", "rld", "loc2");
			PChar.quest.Hornblower_return_to_barbados2.win_condition.l1 = "location";
			PChar.quest.Hornblower_return_to_barbados2.win_condition.l1.location = "ShipDeck1";
			PChar.quest.Hornblower_return_to_barbados2.win_condition = "Hornblower_return_to_barbados2";
		break;

		case "Hornblower_return_to_barbados2":
			LAi_SetCitizenTypeNoGroup(CharacterFromID("Oldroyd"));
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.m1, "goto", "goto5");
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			GiveSoldierWeapon(sld, ENGLAND);
			sld.id = "ship_guard1";
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "goto", "goto2");
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.m2, "goto", "goto10");
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			GiveSoldierWeapon(sld, ENGLAND);
			sld.id = "ship_guard2";
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "goto", "goto2");
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, Nations[ENGLAND].fantomModel.m3, "goto", "goto9");
			LAi_group_MoveCharacter(sld, "ENGLAND_SOLDIERS");
			GiveSoldierWeapon(sld, ENGLAND);
			sld.id = "ship_guard3";
			LAi_SetActorType(sld);
			LAi_ActorTurnToLocator(sld, "goto", "goto2");

			ChangeCharacterAddressGroup(CharacterFromID("Sir Rodney Leighton"), "ShipDeck1", "reload", "boatl");
			LAi_SetActorType(characterFromID("Sir Rodney Leighton"));
			LAi_ActorGoToLocator(characterFromID("Sir Rodney Leighton"), "goto", "goto2", "Hornblower_leighton_boards", 10.0);
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(PChar, "goto", "goto15", "", 10.0);
		break;

		case "Hornblower_leighton_boards":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToCharacter(PChar, CharacterFromID("Sir Rodney Leighton"));
			LAi_ActorWaitDialog(PChar, CharacterFromID("Sir Rodney Leighton"));
			LAi_SetActorType(characterFromID("Sir Rodney Leighton"));
			Characters[GetCharacterIndex("Sir Rodney Leighton")].dialog.CurrentNode = "bridgetown_intro";
			LAi_ActorDialog(characterFromID("Sir Rodney Leighton"), PChar, "Hornblower_barbara_to_join_leighton",5.0,5.0);
		break;

		case "Hornblower_barbara_to_join_leighton":
			LAi_SetPlayerType(PChar);
			ChangeCharacterAddressGroup(CharacterFromID("Lady Barbara Wellesley"), "ShipDeck1", "reload", "reload1");
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			LAi_ActorGoToLocator(characterFromID("Lady Barbara Wellesley"), "reload", "reload3_3", "Hornblower_barbara_to_leighton", 20.0);
		break;

		case "Hornblower_barbara_to_leighton":
			LAi_SetActorType(characterFromID("Sir Rodney Leighton"));
			LAi_ActorTurnToCharacter(CharacterFromID("Sir Rodney Leighton"), CharacterFromID("Lady Barbara Wellesley"));
			LAi_ActorFollow(characterFromID("Lady Barbara Wellesley"), characterFromID("Sir Rodney Leighton"), "Hornblower_leighton_to_barbara", 10.0);
//			LAi_QuestDelay("Hornblower_leighton_to_barbara", 1.0);
		break;

		case "Hornblower_leighton_to_barbara":
			LAi_SetActorType(characterFromID("Sir Rodney Leighton"));
			Characters[GetCharacterIndex("Sir Rodney Leighton")].dialog.CurrentNode = "here_you_are_my_dear";
			LAi_ActorDialog(characterFromID("Sir Rodney Leighton"), PChar, "Hornblower_barbara_to_leighton2",5.0,5.0);
		break;

		case "Hornblower_barbara_to_leighton2":
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			Characters[GetCharacterIndex("Lady Barbara Wellesley")].dialog.CurrentNode = "sweet_leighton";
			LAi_ActorDialogNow(characterFromID("Lady Barbara Wellesley"), PChar, "Hornblower_leighton_to_barbara2",1.0);
		break;

		case "Hornblower_leighton_to_barbara2":
			LAi_SetActorType(characterFromID("Sir Rodney Leighton"));
			Characters[GetCharacterIndex("Sir Rodney Leighton")].dialog.CurrentNode = "families";
			LAi_ActorDialog(characterFromID("Sir Rodney Leighton"), PChar, "Hornblower_goodbye_lady_barbara",5.0,5.0);
		break;

		case "Hornblower_goodbye_lady_barbara":
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			Characters[GetCharacterIndex("Lady Barbara Wellesley")].dialog.CurrentNode = "goodbye_hornblower";
			LAi_ActorDialog(characterFromID("Lady Barbara Wellesley"), PChar, "Hornblower_leighton_and_barbara_leave",5.0,5.0);
		break;

		case "Hornblower_leighton_and_barbara_leave":
			LAi_SetActorType(characterFromID("Sir Rodney Leighton"));
			LAi_ActorGoToLocation(CharacterFromID("Sir Rodney Leighton"), "reload", "boatl", "Greenford_Station", "goto", "goto6", "Hornblower_arrive_Barbados", 60);
			LAi_SetActorType(characterFromID("Lady Barbara Wellesley"));
			LAi_ActorGoToLocation(CharacterFromID("Lady Barbara Wellesley"), "reload", "boatl", "none", "", "", "", 60);
		break;

		case "Hornblower_arrive_Barbados":
			EndQuestMovie();
			ChangeCharacterAddress(characterFromID("Lady Barbara Wellesley"), "None", "");
			SetCharacterRemovable(characterFromID("Lady Barbara Wellesley"), true);
			RemovePassenger(pchar, characterFromID("Lady Barbara Wellesley"));
			PChar.location.from_sea = "Greenford_port";
			SetFleetInTown(GetTownIDFromLocID(pchar.location.from_sea), "PChar");
			LAi_QuestDelay("Hornblower_arrive_Barbados2", 2.0);
		break;

		case "Hornblower_arrive_Barbados2":
			AddQuestRecord("Natividad", 10);
			DoQuestReloadToLocation("Greenford_port", "reload", "reload1", "_");
			ChangeCharacterAddressGroup(CharacterFromID("Captain Keene"), "Greenford_Station", "goto", "goto4");
			ChangeCharacterAddressGroup(CharacterFromID("Sir Edward Pellew"), "Greenford_Station", "goto", "goto7");
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.Filename = "Sir Edward Pellew_freeplay_dialog.c";
			Characters[GetCharacterIndex("Sir Edward Pellew")].dialog.CurrentNode = "great_report";

			PChar.quest.Hornblower_report_to_Admiralty.win_condition.l1 = "location";
			PChar.quest.Hornblower_report_to_Admiralty.win_condition.l1.character = PChar.id;
			Pchar.quest.Hornblower_report_to_Admiralty.win_condition.l1.location = "Greenford Naval HQ";
			Pchar.quest.Hornblower_report_to_Admiralty.win_condition = "Hornblower_report_to_Admiralty";
		break;

		case "Hornblower_report_to_Admiralty":
			SetModelfromID(CharacterFromID("Captain Keene"), "KeeneAD_18");
			if(GetCharacterIndex("Lt. Eccleston") == -1)
			{
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, "EcclestonH", "sit", "sit1");
				sld.id = "Lt. Eccleston";
				sld.name = "Lieutenant";
				sld.lastname = "Eccleston";
			}
			else
			{
				sld = CharacterFromID("Lt. Eccleston");
				ChangeCharacterAddressGroup(sld, "Greenford Naval HQ", "sit", "sit1");
			}
			sld.Dialog.Filename = "Hornblower_quest_minors_dialog.c";
			LAi_SetActorType(sld);
			sld.dialog.CurrentNode = "admirals_upstairs";
			LAi_ActorDialog(sld, PChar, "Hornblower_report_to_Admiralty2", 10.0, 10.0);
		break;

		case "Hornblower_report_to_Admiralty2":
			PChar.quest.Hornblower_admirals_meeting.win_condition.l1 = "location";
			PChar.quest.Hornblower_admirals_meeting.win_condition.l1.location = "Greenford_Station";
			PChar.quest.Hornblower_admirals_meeting.win_condition = "Hornblower_admirals_meeting";
		break;

		case "Hornblower_Eccleston_sits":	// Triggered by dialog with Lt. Eccleston
			LAi_ActorSetSitMode(characterFromID("Lt. Eccleston"));
		break;

		case "Hornblower_admirals_meeting":
			Locations[FindLocation("Greenford_Station")].reload.l1.disable = 1;	// Lock door so you can't leave, re-enter, and see admirals facing the wrong way
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, "brtadm1_18", "goto", "goto8");
			sld.id = "Admiral Boulton";
			sld.name = "Rear Admiral";
			sld.lastname = "Boulton";
			sld.Dialog.Filename = "Hornblower_quest_minors_dialog.c";
			LAi_SetActorType(sld);
			LAi_SetActorType(CharacterFromID("Captain Keene"));
			LAi_ActorTurnToCharacter(CharacterFromID("Sir Rodney Leighton"), CharacterFromID("Sir Edward Pellew"));
			LAi_ActorTurnToCharacter(CharacterFromID("Captain Keene"), CharacterFromID("Sir Rodney Leighton"));
			LAi_ActorTurnToCharacter(CharacterFromID("Admiral Boulton"), CharacterFromID("Sir Edward Pellew"));
		break;

		case "Hornblower_get_Sutherland":
			Locations[FindLocation("Greenford_Station")].reload.l1.disable = 0;	// Unlock door to get out
			Locations[FindLocation("Greenford Naval HQ")].reload.l2.disable = 1;	// Lock other side of door to prevent getting back in
			Preprocessor_AddQuestData("old_ship", PChar.ship.name);
			AddQuestRecord("Natividad", 11);
			Preprocessor_Remove("old_ship");
			CloseQuestHeader("Natividad");
			GiveShip2Character(PChar,"RN_Superbe","Sutherland",-1,FRANCE,true,true);
			PChar.quest.Hornblower_reset_Greenford_HQ.win_condition.l1 = "Location";
			PChar.quest.Hornblower_reset_Greenford_HQ.win_condition.l1.location = "Oxbay";
			PChar.quest.Hornblower_reset_Greenford_HQ.win_condition = "Hornblower_reset_Greenford_HQ";
		break;

		case "Hornblower_reset_Greenford_HQ":
			Locations[FindLocation("Greenford Naval HQ")].reload.l2.disable = 0;
			ChangeCharacterAddress(CharacterFromID("Sir Rodney Leighton"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Captain Keene"), "None", "");
			ChangeCharacterAddress(CharacterFromID("Sir Edward Pellew"), "None", "");
		break;

// Arrival at port: 1:11:30 in video
// Return home: 1:14:50
// Report to Admiralty: 1:18:42
// Admirals: Leighton, Elliot, Boulton, McCartney (Hornblower was one of McCartney's midshipmen, recognises Hornblower, makes improper comment about girls at sea)
// Signal from flagship, captains come aboard: 1:21:15.  Bush on starboard stair to upper deck, Hornblower centre-rear of main deck
// Return to ship: 1:23:43

/*		case "Hornblower_restore_sea_and_fasttravel":
			bQuestDisableSeaEnter = false;
			DisableFastTravel(false);
			LAi_LocationFightDisable(&Locations[FindLocation("ShipDeck2")], false);
		break; */

		case "Hornblower_execution":	// Triggered by dialog with "El Supremo" if you fail to deliver weapons or capture "Natividad", or by dialog with Sir Rodney Leighton if you don't reach a checkpoint in time
			PChar.quest.disable_rebirth = true;
			PostEvent("LAi_event_GameOver", 0, "s", "mutiny");
		break;
///////////////////////////////////////////////////////////////////////
// Hornblower sidequests - end
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// The Quest for the Crystal Skull
///////////////////////////////////////////////////////////////////////
		case "crysskull_initiate":
			SetQuestHeader("crystal_skull");
			Preprocessor_AddQuestData("researcher", GetMyFullName(CharacterFromID("Skull_Researcher")));
			AddQuestRecord("crystal_skull", 1);
			Preprocessor_Remove("researcher");
			ChangeCharacterAddressGroup(characterfromID("Carib_Chief"), "Guadeloupe_Indian_House", "goto", "goto3");
			ChangeCharacterAddressGroup(characterfromID("Carib_Warrior"), "Guadeloupe_Indian_House", "goto", "goto6");
			Locations[FindLocation("Guadeloupe_Jungle_02")].locators_radius.goto.goto7 = 5.0;
			Locations[FindLocation("Guadeloupe_Jungle_02")].vcskip = true;
			PChar.quest.crysskull_Carib_ambush.win_condition.l1 = "locator";
			PChar.quest.crysskull_Carib_ambush.win_condition.l1.location = "Guadeloupe_Jungle_02";
			PChar.quest.crysskull_Carib_ambush.win_condition.l1.locator_group = "goto";
			PChar.quest.crysskull_Carib_ambush.win_condition.l1.locator = "goto7";
			PChar.quest.crysskull_Carib_ambush.win_condition = "crysskull_Carib_ambush";
		break;

		case "crysskull_Carib_ambush":
			Locations[FindLocation("Guadeloupe_Jungle_02")].locators_radius.goto.goto7 = 1.0;
			DeleteAttribute(&Locations[FindLocation("Guadeloupe_Jungle_02")],"vcskip");
			for (i=1; i<5; i++)
			{
				sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", GetRandomRank(false, OFFIC_TYPE_GUARD, 0), true, 1.0, "Native", "monsters", "monster" + i);
				sld.id = "Carib" + i;
				sld.name = "Carib";
				sld.lastname = i;
				LAi_group_MoveCharacter(sld, LAi_monsters_group);
			}
			LAi_group_FightGroups(LAi_monsters_group, LAI_GROUP_PLAYER, true);
			LAi_QuestDelay("crysskull_to_chiefs_hut", 8.0);
		break;

		case "crysskull_to_chiefs_hut":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, SKILL_LEADERSHIP, 1500);
				AddPartyExpChar(PChar, SKILL_SNEAK, 200);
			}
			else { AddPartyExp(PChar, 1500); }
			Locations[FindLocation("Guadeloupe_Jungle_02")].models.always.locators = "jungle01_l_GR";
			StartQuestMovie(true, false, false);
			DisableFastTravel(true);
			LAi_SetStayType(CharacterFromID("Carib_Warrior"));
			LAi_SetStayType(CharacterFromID("Carib_Chief"));

			sld = characterFromID("Carib_Warrior");
			TakenItems(sld, "bladearrows", 3);
			GiveItem2Character(sld, "pistolbow");
			GiveItem2Character(sld, "tomahawk");
			EquipCharacterByItem(sld, "pistolbow");

			Locations[FindLocation("Guadeloupe_Indian_House")].vcskip = true;
			DoQuestReloadToLocation("Guadeloupe_Indian_House", "reload", "reload1_back", "crysskull_to_chiefs_hut2");
		break;

		case "crysskull_to_chiefs_hut2":
			for (i=1; i<5; i++)
			{
				if(i > 2) j = i + 4;
				else j = i;
				sld = LAi_CreateFantomCharacterExOtAt(true, OFFIC_TYPE_GUARD,"isIndian","","", GetRandomRank(false, OFFIC_TYPE_GUARD, 0), true, 1.0, "Native", "goto", "goto" + j);
				sld.id = "Carib" + i;
				sld.name = "Carib";
				sld.lastname = "Warrior";
				LAi_SetActorType(sld);
			}
			LAi_SetActorType(characterFromID("Carib_Chief"));
			Characters[GetCharacterIndex("Carib_Chief")].dialog.CurrentNode = "introductions";
			LAi_ActorDialog(characterFromID("Carib_Chief"), PChar, "crysskull_set_ultimatum",5.0,5.0);
		break;

		case "crysskull_set_ultimatum":
			if (PChar.quest.crysskull.ultimatum == "hostage")
			{

				cidx = sti(PChar.quest.crysskull.hostage);
				sld = GetCharacter(cidx);
				if (HasSubStr(sld.id, "Enc_Officer")) LAi_StoreFantom(sld); // Prevent character from being overwritten by another "Enc_Officer"
				RemoveOfficersIndex(PChar, cidx);
				RemovePassenger(PChar, sld);
				LAi_SetActorType(sld);
				LAi_ActorGoToLocator(sld, "goto", "goto6", "", 20.0);
/*				PChar.quest.crysskull_execute_hostage.win_condition.l1 = "Timer";
				PChar.quest.crysskull_execute_hostage.win_condition.l1.date.day = GetAddingDataDay(0,2,0);
				PChar.quest.crysskull_execute_hostage.win_condition.l1.date.month = GetAddingDataMonth(0,2,0);
				PChar.quest.crysskull_execute_hostage.win_condition.l1.date.year = GetAddingDataYear(0,2,0);
				PChar.quest.crysskull_execute_hostage.win_condition = "crysskull_execute_hostage"; */
			}
			if (PChar.quest.crysskull.ultimatum == "poison")
			{
				PChar.quest.crysskull_poison_player.win_condition.l1 = "Timer";
				PChar.quest.crysskull_poison_player.win_condition.l1.date.day = GetAddingDataDay(0,2,0);
				PChar.quest.crysskull_poison_player.win_condition.l1.date.month = GetAddingDataMonth(0,2,0);
				PChar.quest.crysskull_poison_player.win_condition.l1.date.year = GetAddingDataYear(0,2,0);
				PChar.quest.crysskull_poison_player.win_condition = "crysskull_poison_player";
			}
			LAi_QuestDelay("crysskull_warrior_joins", 0.2);
		break;

		case "crysskull_warrior_joins":
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			Characters[GetCharacterIndex("Carib_Warrior")].dialog.CurrentNode = "join_you";
			LAi_ActorDialog(characterFromID("Carib_Warrior"), PChar, "crysskull_warrior_joins2",5.0,5.0);
		break;

		case "crysskull_warrior_joins2":
			SetOfficersIndex(PChar, -1, GetCharacterIndex("Carib_Warrior"));
			AddPassenger(PChar, CharacterFromID("Carib_Warrior"), 0);
			SetCharacterRemovable(characterFromID("Carib_Warrior"), false);
			LAi_SetImmortal(characterfromID("Carib_Warrior"), true);
			DisableFastTravel(false);
			EndQuestMovie();
			PChar.quest.crys_skull_status = "go_to_Martinique";

			Preprocessor_AddQuestData("warrior", GetMyFullName(CharacterFromID("Carib_Warrior")));
			if (PChar.quest.crysskull.ultimatum == "hostage")
			{
				NPChar = GetCharacter(sti(PChar.quest.crysskull.hostage));
				Preprocessor_AddQuestData("hostage", GetMyFullName(NPChar));
				Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounObj(NPChar)));
				AddQuestRecord("crystal_skull", 2);
				Preprocessor_Remove("pronoun");
				Preprocessor_Remove("hostage");
			}
			else
			{
				Preprocessor_AddQuestData("person", XI_ConvertString(PChar.sex));
				AddQuestRecord("crystal_skull", 3);
				Preprocessor_Remove("person");
			}
			Preprocessor_Remove("warrior");
			AddQuestRecord("crystal_skull", 4);

			SetCharacterShipLocation(characterFromID("Archaeologist_captain"), "Falaise_de_fleur_shore");
			Locations[FindLocation("Falaise_de_fleur_port_01")].dangerous = true;
			Locations[FindLocation("Falaise_de_fleur_port_02")].dangerous = true;
			Locations[FindLocation("Falaise_de_fleur_port_01")].reload.l1.disable = 1;
			Locations[FindLocation("Falaise_de_fleur_port_02")].reload.l1.disable = 1;
			Locations[FindLocation("Falaise_de_fleur_shore")].reload.l1.disable = 1;
			Locations[FindLocation("Falaise_de_fleur_shore")].reload.l3.disable = 1;
			ChangeCharacterAddressGroup(CharacterFromID("Falaise De Fleur Soldier 04"), "Falaise_de_fleur_port_02", "goto", "soldier_02");
			ChangeCharacterAddressGroup(CharacterFromID("Falaise De Fleur Soldier 05"), "Falaise_de_fleur_port_02", "goto", "soldier_01");
			PChar.quest.crysskull_ffsoldier1_talks.win_condition.l1 = "locator";
			PChar.quest.crysskull_ffsoldier1_talks.win_condition.l1.location = "Falaise_de_fleur_port_01";
			PChar.quest.crysskull_ffsoldier1_talks.win_condition.l1.locator_group = "reload";
			PChar.quest.crysskull_ffsoldier1_talks.win_condition.l1.locator = "Falaise_de_fleur_location_01_02";
			PChar.quest.crysskull_ffsoldier1_talks.win_condition = "crysskull_ffsoldier1_talks";
			PChar.quest.crysskull_ffsoldier4_talks.win_condition.l1 = "locator";
			PChar.quest.crysskull_ffsoldier4_talks.win_condition.l1.location = "Falaise_de_fleur_port_02";
			PChar.quest.crysskull_ffsoldier4_talks.win_condition.l1.locator_group = "reload";
			PChar.quest.crysskull_ffsoldier4_talks.win_condition.l1.locator = "Falaise_de_fleur_location_01_05";
			PChar.quest.crysskull_ffsoldier4_talks.win_condition = "crysskull_ffsoldier4_talks";

			PChar.quest.crysskull_Carib_warrior_on_ship.win_condition.l1 = "location";
			PChar.quest.crysskull_Carib_warrior_on_ship.win_condition.l1.location = "Guadeloupe";
			PChar.quest.crysskull_Carib_warrior_on_ship.win_condition = "crysskull_Carib_warrior_on_ship";

			PChar.quest.crysskull_beach_arrival.win_condition.l1 = "location";
			PChar.quest.crysskull_beach_arrival.win_condition.l1.location = "Falaise_de_fleur_shore";
			PChar.quest.crysskull_beach_arrival.win_condition = "crysskull_beach_arrival";

			PChar.quest.crysskull_port_arrival.win_condition.l1 = "location";
			PChar.quest.crysskull_port_arrival.win_condition.l1.location = "Falaise_de_fleur_port_01";
			PChar.quest.crysskull_port_arrival.win_condition = "crysskull_port_arrival";
		break;

		case "crysskull_Carib_warrior_on_ship":
			RemoveOfficersIndex(PChar, GetCharacterIndex("Carib_Warrior"));
			ChangeCharacterAddress(characterFromID("Carib_Warrior"), "None", "");
		break;

		case "crysskull_ffsoldier1_talks":
			LAi_SetActorType(characterFromID("Falaise De Fleur Soldier 01"));
			Characters[GetCharacterIndex("Falaise De Fleur Soldier 01")].dialog.CurrentNode = "crysskull_get_lost";
			LAi_ActorDialog(characterFromID("Falaise De Fleur Soldier 01"), PChar, "crysskull_reset_ffsoldiers",5.0,5.0);
		break;

		case "crysskull_ffsoldier4_talks":
			LAi_SetActorType(characterFromID("Falaise De Fleur Soldier 04"));
			Characters[GetCharacterIndex("Falaise De Fleur Soldier 04")].dialog.CurrentNode = "crysskull_get_lost";
			LAi_ActorDialog(characterFromID("Falaise De Fleur Soldier 04"), PChar, "crysskull_reset_ffsoldiers",5.0,5.0);
		break;

		case "crysskull_reset_ffsoldiers":
			LAi_SetGuardianType(characterFromID("Falaise De Fleur Soldier 01"));
			LAi_SetGuardianType(characterFromID("Falaise De Fleur Soldier 04"));
		break;

		case "crysskull_reset_falaise_de_fleur":
			DeleteAttribute(&Locations[FindLocation("Falaise_de_fleur_port_01")],"dangerous");
			DeleteAttribute(&Locations[FindLocation("Falaise_de_fleur_port_02")],"dangerous");
			Locations[FindLocation("Falaise_de_fleur_port_01")].reload.l1.disable = 0;
			Locations[FindLocation("Falaise_de_fleur_port_02")].reload.l1.disable = 0;
			Locations[FindLocation("Falaise_de_fleur_shore")].reload.l1.disable = 0;
			Locations[FindLocation("Falaise_de_fleur_shore")].reload.l3.disable = 0;
			ChangeCharacterAddressGroup(CharacterFromID("Falaise De Fleur Soldier 04"), "Falaise_de_fleur_location_02", "goto", "locator33");
			ChangeCharacterAddressGroup(CharacterFromID("Falaise De Fleur Soldier 05"), "Falaise_de_fleur_location_02", "goto", "locator32");
			PChar.quest.crysskull_ffsoldier1_talks.over = "yes";
			PChar.quest.crysskull_ffsoldier4_talks.over = "yes";
		break;

		case "crysskull_poison_player":
			if(IsEntity(&worldMap))
			{
				PChar.quest.crysskull_delay_poison_sea.win_condition.l1 = "SeaEnter";
				PChar.quest.crysskull_delay_poison_sea.win_condition = "crysskull_delay_poison_sea";
			}
			else
			{ 
				logit(TranslateString("", "You succumb to the Carib poison."));
				LAi_KillCharacter(PChar);
			}
		break;

		case "crysskull_delay_poison_sea":
			LAi_QuestDelay("crysskull_poison_player", 0.2);	// Might not get you right away as quests aren't checked continuously at sea.  Should get you eventually, though
		break;

		case "crysskull_execute_hostage":
			cidx = sti(PChar.quest.crysskull.hostage);
			sld = GetCharacter(cidx);
			logit(GetMyFullName(sld) + " " + TranslateString("", "has been executed."));
			if (HasSubStr(sld.id, "Enc_Officer")) LAi_UnStoreFantom(sld); // Cancel protection
			LAi_KillCharacter(sld);
		break;

		case "crysskull_port_arrival":
			if (LAi_IsCapturedLocation)	// If you've destroyed the fort, nobody is going to object to you bringing a Carib into town!
			{				
				LAi_QuestDelay("crysskull_reset_falaise_de_fleur", 0.1);
			}
			else
			{
				ChangeCharacterAddressGroup(CharacterFromID("Carib_Warrior"), "Falaise_de_fleur_port_01", "officers", "sea_3");
				if (SetOfficersIndex(PChar, -1, GetCharacterIndex("Carib_Warrior")) == GetCharacterIndex("Carib_Warrior"))
				{
					if (CheckAttribute(PChar, "quest.crysskull.hostage.slot")) i = sti(PChar.quest.crysskull.hostage.slot);
					else i = OFFICER_MAX - 1;
					SetOfficersIndex(PChar, i, GetCharacterIndex("Carib_Warrior"));
				}
				LAi_SetActorType(characterFromID("Carib_Warrior"));
				Characters[GetCharacterIndex("Carib_Warrior")].dialog.CurrentNode = "should_be_on_beach";
				LAi_ActorDialog(characterFromID("Carib_Warrior"), PChar, "crysskull_reset_carib_warrior",5.0,5.0);
			}
		break;

		case "crysskull_beach_arrival":
			PChar.quest.crysskull_port_arrival.over = "yes";
			if (!isofficer(characterFromID("Carib_Warrior")))
			{
				ChangeCharacterAddressGroup(CharacterFromID("Carib_Warrior"), "Falaise_de_fleur_shore", "officers", "reload1_3");
				if (SetOfficersIndex(PChar, -1, GetCharacterIndex("Carib_Warrior")) == GetCharacterIndex("Carib_Warrior"))
				{
					if (CheckAttribute(PChar, "quest.crysskull.hostage.slot")) i = sti(PChar.quest.crysskull.hostage.slot);
					else
					{
						i = OFFICER_MAX - 1;
						cidx = SetOfficersIndex(PChar, i, GetCharacterIndex("Carib_Warrior"));
						PChar.quest.crysskull.replaced_officer.id = cidx;
						PChar.quest.crysskull.replaced_officer.slot = OFFICER_MAX - 1;
					}
				}
			}
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			Characters[GetCharacterIndex("Carib_Warrior")].dialog.CurrentNode = "follow_me1";
			LAi_ActorDialog(characterFromID("Carib_Warrior"), PChar, "crysskull_warrior_goes_to_cave",5.0,5.0);
		break;

		case "crysskull_warrior_goes_to_cave":
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			LAi_ActorGoToLocator(characterFromID("Carib_Warrior"), "reload", "reload3_back", "", 300.0);
			PChar.quest.crysskull_cave_arrival.win_condition.l1 = "location";
			PChar.quest.crysskull_cave_arrival.win_condition.l1.location = "FalaiseDeFleur_Grot";
			PChar.quest.crysskull_cave_arrival.win_condition = "crysskull_cave_arrival";
		break;

		case "crysskull_cave_arrival":
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			Characters[GetCharacterIndex("Carib_Warrior")].dialog.CurrentNode = "bridge_warning";
			LAi_ActorDialog(characterFromID("Carib_Warrior"), PChar, "crysskull_reset_carib_warrior",5.0,5.0);
			PChar.quest.crysskull_bridge_arrival.win_condition.l1 = "location";
			PChar.quest.crysskull_bridge_arrival.win_condition.l1.location = "FalaiseDeFleur_Bridge";
			PChar.quest.crysskull_bridge_arrival.win_condition = "crysskull_bridge_arrival";
		break;

		case "crysskull_reset_carib_warrior":
			LAi_SetOfficerType(CharacterFromID("Carib_Warrior"));
		break;

		case "crysskull_bridge_arrival":
			DisableFastTravel(true);
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			Characters[GetCharacterIndex("Carib_Warrior")].dialog.CurrentNode = "walk_to_side";
			LAi_ActorDialog(characterFromID("Carib_Warrior"), PChar, "crysskull_carib_warrior_shows_bridge_way",5.0,5.0);

/*			PChar.quest.crysskull_bridge_trap1.win_condition.l1 = "locator";	// Now set in "Periods.c"
			PChar.quest.crysskull_bridge_trap1.win_condition.l1.location = "FalaiseDeFleur_Bridge";
			PChar.quest.crysskull_bridge_trap1.win_condition.l1.locator_group = "goto";
			PChar.quest.crysskull_bridge_trap1.win_condition.l1.locator = "goto30";
			PChar.quest.crysskull_bridge_trap1.win_condition = "crysskull_bridge_trap";
			PChar.quest.crysskull_bridge_trap2.win_condition.l1 = "locator";
			PChar.quest.crysskull_bridge_trap2.win_condition.l1.location = "FalaiseDeFleur_Bridge";
			PChar.quest.crysskull_bridge_trap2.win_condition.l1.locator_group = "goto";
			PChar.quest.crysskull_bridge_trap2.win_condition.l1.locator = "goto40";
			PChar.quest.crysskull_bridge_trap2.win_condition = "crysskull_bridge_trap"; */

			PChar.quest.crysskull_jungle_arrival.win_condition.l1 = "location";
			PChar.quest.crysskull_jungle_arrival.win_condition.l1.location = "FalaiseDeFleur_jungle_01";
			PChar.quest.crysskull_jungle_arrival.win_condition = "crysskull_jungle_arrival";
		break;

		case "crysskull_bridge_trap":
			Lai_KillCharacter(PChar);
			LAi_QuestDelay("crysskull_bridge_trap_game_over", 5.0);
		break;

		case "crysskull_bridge_trap_game_over":
			PChar.quest.disable_rebirth = true;
			PostEvent("LAi_event_GameOver", 0, "s", "sea");
		break;

		case "crysskull_carib_warrior_shows_bridge_way":
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			LAi_ActorGoToLocator(characterFromID("Carib_Warrior"), "goto", "goto31", "crysskull_carib_warrior_shows_bridge_way2", 20.0);
		break;

		case "crysskull_carib_warrior_shows_bridge_way2":
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			LAi_ActorGoToLocator(characterFromID("Carib_Warrior"), "goto", "goto41", "crysskull_carib_warrior_shows_bridge_way3", 20.0);
		break;

		case "crysskull_carib_warrior_shows_bridge_way3":
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			LAi_ActorGoToLocator(characterFromID("Carib_Warrior"), "reload", "reload4", "", 20.0);
		break;


		case "crysskull_jungle_arrival":
			LAi_SetOfficerType(CharacterFromID("Carib_Warrior"));
			PChar.quest.crysskull_jungle2_arrival.win_condition.l1 = "location";
			PChar.quest.crysskull_jungle2_arrival.win_condition.l1.location = "FalaiseDeFleur_jungle_02";
			PChar.quest.crysskull_jungle2_arrival.win_condition = "crysskull_jungle_arrival2";
		break;

		case "crysskull_jungle_arrival2":
			StartQuestMovie(true, false, false);
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			Characters[GetCharacterIndex("Carib_Warrior")].dialog.CurrentNode = "search_for_skull";
			LAi_ActorDialog(characterFromID("Carib_Warrior"), PChar, "crysskull_carib_warrior_searches",5.0,5.0);
		break;

		case "crysskull_carib_warrior_searches":
			LAi_SetCitizenTypeNoGroup(CharacterFromID("Carib_Warrior"));
			LAi_QuestDelay("crysskull_carib_warrior_searches2", 10.0);
		break;

		case "crysskull_carib_warrior_searches2":
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			LAi_ActorGoToLocator(characterFromID("Carib_Warrior"), "goto", "goto1", "crysskull_carib_warrior_finds_skull", 30.0);
		break;

		case "crysskull_carib_warrior_finds_skull":
			characters[GetCharacterindex("Carib_Warrior")].nodisarm = 1;
			GiveItem2Character(characterFromID("Carib_Warrior"), "cryskull");
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			Characters[GetCharacterIndex("Carib_Warrior")].dialog.CurrentNode = "found_skull";
			LAi_ActorDialog(characterFromID("Carib_Warrior"), PChar, "crysskull_time_to_go_back",15.0,15.0);
		break;

		case "crysskull_time_to_go_back":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, SKILL_LEADERSHIP, 1500);
				AddPartyExpChar(PChar, SKILL_SNEAK, 200);
			}
			else { AddPartyExp(PChar, 1500); }
			Preprocessor_AddQuestData("warrior", GetMyFullName(CharacterFromID("Carib_Warrior")));
			AddQuestRecord("crystal_skull", 6);
			Preprocessor_Remove("warrior");
			LAi_SetOfficerType(CharacterFromID("Carib_Warrior"));
			EndQuestMovie();

			Characters[GetCharacterIndex("Skull_Researcher")].dialog.CurrentNode = "welcome_back";

			PChar.quest.crysskull_you_stole_skull.win_condition.l1 = "item";
			PChar.quest.crysskull_you_stole_skull.win_condition.l1.item = "cryskull";
			PChar.quest.crysskull_you_stole_skull.win_condition = "crysskull_you_stole_skull";

			PChar.quest.crysskull_jungle1_return.win_condition.l1 = "location";
			PChar.quest.crysskull_jungle1_return.win_condition.l1.location = "FalaiseDeFleur_jungle_01";
			PChar.quest.crysskull_jungle1_return.win_condition = "crysskull_jungle1_return";
		break;

		case "crysskull_you_stole_skull":
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			Characters[GetCharacterIndex("Carib_Warrior")].dialog.CurrentNode = "skull_stolen";
			LAi_ActorDialog(characterFromID("Carib_Warrior"), PChar, "crysskull_carib_warrior_angry",5.0,5.0);
		break;

		case "crysskull_carib_warrior_angry":
			sld = characterFromID("Carib_Warrior");
			RemoveOfficersIndex(PChar, GetCharacterIndex("Carib_Warrior"));
			RemovePassenger(PChar, sld);
			LAi_SetImmortal(sld, false);
			TakenItems(sld, "bladearrows", 1 + rand(2));
			GiveItem2Character(sld, "pistolbow");
			GiveItem2Character(sld, "tomahawk");
			EquipCharacterByItem(sld, "pistolbow");
			StartQuestMovie(true, false, false);
			LAi_group_MoveCharacter(sld, LAi_monsters_group);
			LAi_group_FightGroups(LAi_monsters_group, LAI_GROUP_PLAYER, true);
			PChar.quest.crysskull_you_killed_carib_warrior.win_condition.l1 = "NPC_Death";
			PChar.quest.crysskull_you_killed_carib_warrior.win_condition.l1.character = "Carib_Warrior";
			PChar.quest.crysskull_you_killed_carib_warrior.win_condition = "crysskull_you_killed_carib_warrior";
		break;

		case "crysskull_you_killed_carib_warrior":
			EndQuestMovie();
			LAi_QuestDelay("crysskull_reset_falaise_de_fleur", 0.1);
			PChar.quest.crysskull_carib_in_santo_domingo.over = "yes";
			if (CheckAttribute(PChar, "quest.crysskull.replaced_officer"))
			{
				PChar.quest.crysskull_return_replaced_officer.win_condition.l1 = "location";
				PChar.quest.crysskull_return_replaced_officer.win_condition.l1.location = "FalaiseDeFleur";
				PChar.quest.crysskull_return_replaced_officer.win_condition = "crysskull_return_replaced_officer";
			}
		break;

		case "crysskull_jungle1_return":
			StartQuestMovie(true, false, false);
			for (i=1; i<6; i++)
			{
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, "pirat" + (rand(5) + 1), "reload", "reload2_back");
				sld.id = "pirate" + i;
				sld.nation = PIRATE;
				SetRandomNameToCharacter(sld);
				LAi_group_MoveCharacter(sld, LAi_monsters_group);
			}
			LAi_group_SetRelation(LAi_monsters_group, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAi_monsters_group, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(LAi_monsters_group, "crysskull_jungle_ambush_over");
		break;

		case "crysskull_jungle_ambush_over":
			EndQuestMovie();
			AddQuestRecord("crystal_skull", 7);
			PChar.quest.crysskull_bridge_return.win_condition.l1 = "location";
			PChar.quest.crysskull_bridge_return.win_condition.l1.location = "FalaiseDeFleur_Bridge";
			PChar.quest.crysskull_bridge_return.win_condition = "crysskull_bridge_return";
		break;

		case "crysskull_bridge_return":
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			Characters[GetCharacterIndex("Carib_Warrior")].dialog.CurrentNode = "second_bridge_warning";
			LAi_ActorDialog(characterFromID("Carib_Warrior"), PChar, "crysskull_carib_warrior_shows_way_back",5.0,5.0);

			Locations[FindLocation("FalaiseDeFleur_Grot")].locators_radius.officers.reload1_1 = 2.0;
			ChangeCharacterAddressGroup(CharacterFromID("Archaeologist_captain"), "FalaiseDeFleur_Grot", "officers", "reload2_2");

			PChar.quest.crysskull_cave_return.win_condition.l1 = "location";
			PChar.quest.crysskull_cave_return.win_condition.l1.location = "FalaiseDeFleur_Grot";
			PChar.quest.crysskull_cave_return.win_condition = "crysskull_cave_return";
		break;

		case "crysskull_carib_warrior_shows_way_back":
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			LAi_ActorGoToLocator(characterFromID("Carib_Warrior"), "goto", "goto41", "crysskull_carib_warrior_shows_way_back2", 20.0);
		break;

		case "crysskull_carib_warrior_shows_way_back2":
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			LAi_ActorGoToLocator(characterFromID("Carib_Warrior"), "goto", "goto31", "crysskull_carib_warrior_shows_way_back3", 20.0);
		break;

		case "crysskull_carib_warrior_shows_way_back3":
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			LAi_ActorGoToLocator(characterFromID("Carib_Warrior"), "reload", "reload1_back", "", 20.0);
		break;

		case "crysskull_cave_return":
			LAi_SetOfficerType(CharacterFromID("Carib_Warrior"));
			StartQuestMovie(true, false, false);
			LAi_SetFightMode(PChar, false);
			LAi_LocationFightDisable(&Locations[FindLocation("FalaiseDeFleur_Grot")], true);
			PChar.quest.crysskull_enemy_captain_speaks.win_condition.l1 = "locator";
			PChar.quest.crysskull_enemy_captain_speaks.win_condition.l1.location = "FalaiseDeFleur_Grot";
			PChar.quest.crysskull_enemy_captain_speaks.win_condition.l1.locator_group = "officers";
			PChar.quest.crysskull_enemy_captain_speaks.win_condition.l1.locator = "reload1_1";
			PChar.quest.crysskull_enemy_captain_speaks.win_condition = "crysskull_enemy_captain_speaks";
		break;

		case "crysskull_enemy_captain_speaks":
			Locations[FindLocation("FalaiseDeFleur_Grot")].locators_radius.officers.reload1_1 = 1.0;
			LAi_SetActorType(characterFromID("Archaeologist_captain"));
			Characters[GetCharacterIndex("Archaeologist_captain")].dialog.CurrentNode = "introduction";
			LAi_ActorDialog(characterFromID("Archaeologist_captain"), PChar, "",5.0,5.0);	// Exits to "crysskull_carib_warrior_refuses_skull", or straight to "crysskull_enemy_captain_leaves" if "Carib_Warrior" is dead
		break;

		case "crysskull_carib_warrior_refuses_skull":
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			Characters[GetCharacterIndex("Carib_Warrior")].dialog.CurrentNode = "give_him_skull";
			LAi_ActorDialog(characterFromID("Carib_Warrior"), PChar, "crysskull_carib_warrior_surrenders_skull1",5.0,5.0);
		break;

		case "crysskull_carib_warrior_surrenders_skull1":
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			LAi_ActorFollow(characterFromID("Carib_Warrior"), characterFromID("Archaeologist_captain"), "", 3.0);
			LAi_SetActorType(characterFromID("Archaeologist_captain"));
			LAi_ActorTurnToCharacter(CharacterFromID("Archaeologist_captain"), CharacterFromID("Carib_Warrior"));
			LAi_QuestDelay("crysskull_carib_warrior_surrenders_skull2", 3.0);
		break;

		case "crysskull_carib_warrior_surrenders_skull2":
			PlayStereoSound("INTERFACE\important_item.wav");
			TakeItemFromCharacter(characterFromID("Carib_Warrior"), "cryskull");
			GiveItem2Character(characterFromID("Archaeologist_captain"), "cryskull");
			PChar.quest.crysskull_you_stole_skull.over = "yes";
			LAi_SetOfficerType(CharacterFromID("Carib_Warrior"));
			LAi_SetActorType(characterFromID("Archaeologist_captain"));
			Characters[GetCharacterIndex("Archaeologist_captain")].dialog.CurrentNode = "wise_choice";
			LAi_ActorDialog(characterFromID("Archaeologist_captain"), PChar, "",5.0,5.0);	// Exits to "crysskull_enemy_captain_leaves"
		break;

		case "crysskull_enemy_captain_leaves":
			LAi_SetActorType(characterFromID("Archaeologist_captain"));
			LAi_ActorGoToLocation(characterFromID("Archaeologist_captain"), "reload", "reload2_back", "none", "", "", "crysskull_prepare_cannon", 5.0);
		break;

		case "crysskull_prepare_cannon":
			LAi_QuestDelay("crysskull_fire_cannon", 1.0);
		break;

		case "crysskull_fire_cannon":
			logit(TranslateString("", "Sorry, but I can't take the chance that you'll make good on your threat to take back the amber skull... FIRE!"));
			LAi_QuestDelay("crysskull_bang", 1.0);
		break;

		case "crysskull_bang":
			CreateParticleSystemX("blast_inv", 11.9, -0.7, 1.5, 0, 0.8768, 0.0,0);
			CreateParticleSystemX("cancloud", 11.9, -0.7, 1.5, 0, 0.8768, 0.0,20);
			CreateParticleSystemX("cancloud", 11.9, -0.7, 1.5, 0, 0.8768, 0.0,20);
			PlayStereoSound("OBJECTS\SHIPCHARGE\cannon_fire_02.wav");
			LAi_QuestDelay("crysskull_rockfall", 1.0);
		break;

		case "crysskull_rockfall":
			Build_at("FalaiseDeFleur_Grot", "boulder", "", 11.2, -2.0, 1.5, 0.0, "building");
			DoQuestReloadToLocation("FalaiseDeFleur_Grot", "reload", "reload3", "crysskull_rockfall2");
		break;

		case "crysskull_rockfall2":
			Preprocessor_AddQuestData("enemy_captain", GetMyFullName(CharacterFromID("Archaeologist_captain")));
			AddQuestRecord("crystal_skull", 8);
			Preprocessor_Remove("enemy_captain");
			PlayStereoSound("OBJECTS\boulder_start.wav");
			if (!LAi_isDead(characterFromID("Carib_Warrior")))
			{
				PChar.quest.crysskull_rock_mover = "Carib_Warrior";
				LAi_SetActorType(characterFromID("Carib_Warrior"));
				Characters[GetCharacterIndex("Carib_Warrior")].dialog.CurrentNode = "trapped";
				LAi_ActorDialog(characterFromID("Carib_Warrior"), PChar, "crysskull_reset_rock_mover",5.0,5.0);
			}
			else
			{	string speaker = "";
				for (i=1; i<OFFICER_MAX; i++)
				{
					if(GetOfficersIndex(PChar, i) != -1)
					{
						speaker = Characters[GetOfficersIndex(PChar, i)].id;
						break;
					}
				}
				if (speaker != "")
				{
					PChar.quest.crysskull_rock_mover = speaker;
					NPChar = CharacterFromID(speaker);
					NPChar.quest.original_dialog_filename = NPChar.Dialog.Filename;
					NPChar.quest.original_dialog_CurrentNode = NPChar.dialog.CurrentNode;
					NPChar.dialog.filename = "Carib_Warrior_dialog.c";
					NPChar.dialog.CurrentNode = "trapped_without_warrior";
					LAi_SetActorType(characterFromID(speaker));
					LAi_ActorDialog(characterFromID(speaker), PChar, "crysskull_reset_rock_mover",5.0,5.0);
				}
				else
				{
					LAi_SetActorType(PChar);
					PChar.dialog.currentnode = "crysskull_stuck_in_cave";
					LAi_ActorSelfDialog(PChar, "player_back");
					EndQuestMovie();
					Locations[FindLocation("FalaiseDeFleur_Grot")].reload.l2.disable = 1;
				}
			}
		break;

		case "crysskull_reset_rock_mover":
			NPChar = CharacterFromID(PChar.quest.crysskull_rock_mover);
			LAi_SetOfficerType(NPChar);
			if (CheckAttribute(NPChar, "quest.original_dialog_filename"))
			{
				NPChar.Dialog.Filename = NPChar.quest.original_dialog_filename;
				NPChar.dialog.CurrentNode = NPChar.quest.original_dialog_CurrentNode;
				DeleteAttribute(NPChar, "quest.original_dialog_filename");
				DeleteAttribute(NPChar, "quest.original_dialog_CurrentNode");
			}
			DeleteAttribute(PChar, "quest.crysskull_rock_mover");
		break;

		case "crysskull_move_rock":					// Triggered by dialog with either "Carib_Warrior" or an officer
			lcn = &Locations[FindLocation("FalaiseDeFleur_Grot")];	// Remove rock so it can be placed at new spot
			for(i = 1; i<=MAXBUILDINGS; i++)
			{
				if( CheckAttribute(lcn,"building."+i+".building") )
				{
					Building_delete(lcn, "" + i);
				}
			}
			Build_at("FalaiseDeFleur_Grot", "boulder", "", 10.6, -2.0, -1.2, 0, "building");
			DoQuestReloadToLocation("FalaiseDeFleur_Grot", "reload", "reload2", "crysskull_move_rock2");
		break;

		case "crysskull_move_rock2":
			Preprocessor_AddQuestData("enemy_captain", GetMyFullName(CharacterFromID("Archaeologist_captain")));
			AddQuestRecord("crystal_skull", 9);
			Preprocessor_Remove("enemy_captain");
			PlayStereoSound("OBJECTS\boulder_roll.wav");
			EndQuestMovie();
			DisableFastTravel(false);
			LAi_LocationFightDisable(&Locations[FindLocation("FalaiseDeFleur_Grot")], false);

			PChar.quest.crysskull_seafight_setup.win_condition.l1 = "location";
			PChar.quest.crysskull_seafight_setup.win_condition.l1.location = "FalaiseDeFleur";
			PChar.quest.crysskull_seafight_setup.win_condition = "crysskull_seafight_setup";
		break;

		case "crysskull_seafight_setup":
			Group_CreateGroup("Archaeologist_ship");
			Group_AddCharacter("Archaeologist_ship", "Archaeologist_captain");
			Group_SetGroupCommander("Archaeologist_ship", "Archaeologist_captain");

			Group_SetPursuitGroup("Archaeologist_ship", PLAYER_GROUP);
			Group_SetTaskAttack("Archaeologist_ship",  PLAYER_GROUP, true);
			Group_LockTask("Archaeologist_ship");
			Group_SetAddress("Archaeologist_ship", "FalaiseDeFleur", "Quest_ships", "quest_ship_22");
			Sea_LoginGroupNow("Archaeologist_ship");
			Characters[GetCharacterIndex("Archaeologist_captain")].nosurrender = 2;
			Characters[GetCharacterIndex("Archaeologist_captain")].recognized = true;

			PChar.quest.crysskull_ship_captured.win_condition.l1 = "Character_Capture";
			PChar.quest.crysskull_ship_captured.win_condition.l1.character = "Archaeologist_captain";
			PChar.quest.crysskull_ship_captured.win_condition.l2 = "SeaEnter";
			PChar.quest.crysskull_ship_captured.win_condition = "crysskull_ship_captured";
			PChar.quest.crysskull_ship_sunk.win_condition.l1 = "NPC_Death";
			PChar.quest.crysskull_ship_sunk.win_condition.l1.character = "Archaeologist_captain";
			PChar.quest.crysskull_ship_sunk.win_condition.l2 = "SeaEnter";
			PChar.quest.crysskull_ship_sunk.win_condition = "crysskull_ship_sunk";

			if (!LAi_isDead(characterFromID("Carib_Warrior")))
			{
				PChar.quest.crysskull_carib_in_santo_domingo.win_condition.l1 = "location";
				PChar.quest.crysskull_carib_in_santo_domingo.win_condition.l1.character = "Carib_Warrior";
				PChar.quest.crysskull_carib_in_santo_domingo.win_condition.l1.location = "Santo_Domingo_town";
				PChar.quest.crysskull_carib_in_santo_domingo.win_condition = "crysskull_carib_in_santo_domingo";
			}

			Locations[FindLocation("Guadeloupe_Jungle_02")].vcskip = true;
			PChar.quest.crysskull_return_to_caribs.win_condition.l1 = "location";
			PChar.quest.crysskull_return_to_caribs.win_condition.l1.location = "Guadeloupe_Jungle_02";
			PChar.quest.crysskull_return_to_caribs.win_condition = "crysskull_return_to_caribs";
		break;

		case "crysskull_ship_captured":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, SKILL_LEADERSHIP, 3000);
				AddPartyExpChar(PChar, SKILL_SAILING, 500);
			}
			else { AddPartyExp(PChar, 3000); }
			PChar.quest.crysskull_ship_sunk.over = "yes";
			setCharacterShipLocation(characterFromID("Archaeologist_captain"), "none");
			if (CheckCharacterItem(PChar, "cryskull"))
			{
				if (PChar.quest.crysskull.ultimatum == "hostage")
				{
					Preprocessor_AddQuestData("hostage", GetMyFullName(GetCharacter(sti(PChar.quest.crysskull.hostage))));
					AddQuestRecord("crystal_skull", 10);
					Preprocessor_Remove("officer");
				}
				else AddQuestRecord("crystal_skull", 11);
			}
			else
			{
				SetCharacterShipLocation(PChar, "Falaise_de_Fleur_shore");
				PChar.location.from_sea = "Falaise_de_Fleur_shore";
				SetFleetInTown(GetTownIDFromLocID(PChar.location.from_sea), "PChar");
				PChar.quest.crys_skull_status = "skull_found_by_crew";
				deck = GetCharacterShipQDeck(PChar);
				bQuestDisableAllCommands = true;
				Sea_DeckStartNow(GetMainCharacterIndex(), GetCharacterShipQDeck(PChar));
				PChar.quest.crysskull_deck_scene.win_condition.l1 = "location";
				PChar.quest.crysskull_deck_scene.win_condition.l1.location = deck;
				PChar.quest.crysskull_deck_scene.win_condition = "crysskull_deck_scene";
			}
		break;

		case "crysskull_ship_sunk":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, SKILL_LEADERSHIP, 3000);
				AddPartyExpChar(PChar, SKILL_SAILING, 500);
			}
			else { AddPartyExp(PChar, 3000); }
			setCharacterShipLocation(characterFromID("Archaeologist_captain"), "none");
			SetCharacterShipLocation(PChar, "Falaise_de_Fleur_shore");
			PChar.location.from_sea = "Falaise_de_Fleur_shore";
			SetFleetInTown(GetTownIDFromLocID(PChar.location.from_sea), "PChar");
			PChar.quest.crys_skull_status = "ship_sunk";
			deck = GetCharacterShipQDeck(PChar);
			bQuestDisableAllCommands = true;
			Sea_DeckStartNow(GetMainCharacterIndex(), GetCharacterShipQDeck(PChar));
			PChar.quest.crysskull_deck_scene.win_condition.l1 = "location";
			PChar.quest.crysskull_deck_scene.win_condition.l1.location = deck;
			PChar.quest.crysskull_deck_scene.win_condition = "crysskull_deck_scene";
		break;

		case "crysskull_deck_scene":
			DisableFastTravel(true);
			StartQuestMovie(true, false, false);
			SetCharacterToNearLocatorFromMe("Carib_Warrior", 2);
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.25, "Sailor16",  "reload", "reload1");
			if(GetServedNation() == PERSONAL_NATION) sld.nation = PChar.nation;
			else sld.nation = GetServedNation();
			SetRandomNameToCharacter(sld);
			sld.Dialog.Filename = "Carib_Warrior_dialog.c";
			LAi_SetActorType(sld);
			if (PChar.quest.crys_skull_status == "ship_sunk") sld.dialog.CurrentNode = "diver_found_skull";
			else sld.dialog.CurrentNode = "found_skull_in_chest";
			LAi_ActorDialog(sld, PChar, "crysskull_get_skull",5.0,5.0);
		break;

		case "crysskull_get_skull":
			GiveItem2Character(PChar, "cryskull");
			PlayStereoSound("INTERFACE\important_item.wav");
			if (PChar.quest.crysskull.ultimatum == "hostage")
			{
				Preprocessor_AddQuestData("hostage", GetMyFullName(GetCharacter(sti(PChar.quest.crysskull.hostage))));
				AddQuestRecord("crystal_skull", 10);
				Preprocessor_Remove("officer");
			}
			else AddQuestRecord("crystal_skull", 11);
			bQuestDisableAllCommands = false;
			EndQuestMovie();
			DisableFastTravel(false);
		break;

		case "crysskull_carib_in_santo_domingo":
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			Characters[GetCharacterIndex("Carib_Warrior")].dialog.CurrentNode = "not_Karoukera";
			LAi_ActorDialog(characterFromID("Carib_Warrior"), PChar, "crysskull_carib_warrior_angry",5.0,5.0);
		break;

		case "crysskull_return_to_caribs":
			DeleteAttribute(&Locations[FindLocation("Guadeloupe_Jungle_02")],"vcskip");
			LAi_LocationFightDisable(&Locations[FindLocation("Guadeloupe_Jungle_02")], true);
			LAi_SetFightMode(PChar, false);
			DisableFastTravel(true);
			StartQuestMovie(true, false, false);
			TakenItems(characterFromID("Carib_Chief"), "bladearrows", 3);
			GiveItem2Character(characterFromID("Carib_Chief"), "pistolbow");
			GiveItem2Character(characterFromID("Carib_Chief"), "tomahawk");
			EquipCharacterByItem(characterFromID("Carib_Chief"), "pistolbow");
			ChangeCharacterAddressGroup(characterfromID("Carib_Chief"), "Guadeloupe_Jungle_02", "goto", "goto4");
			LAi_SetActorType(characterFromID("Carib_Chief"));
			LAi_ActorTurnToCharacter(CharacterFromID("Carib_Chief"), PChar);
			for (i=1; i<4; i++)
			{
				sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", GetRandomRank(false, OFFIC_TYPE_GUARD, 0), true, 1.0, "Native", "monsters", "monster" + i);
				sld.id = "Carib" + i;
				sld.name = "Carib";
				sld.lastname = i;
			}
			if (PChar.quest.crysskull.ultimatum == "hostage") ChangeCharacterAddressGroup(GetCharacter(sti(PChar.quest.crysskull.hostage)), "Guadeloupe_Jungle_02", "monsters", "monster5");
			LAi_QuestDelay("crysskull_return_to_caribs2", 0.1);
		break;

		case "crysskull_return_to_caribs2":
			LAi_SetStayType(CharacterFromID("Carib_Chief"));
			Characters[GetCharacterIndex("Carib_Chief")].dialog.CurrentNode = "return_with_skull";
			sld = characterFromID("Carib_Warrior");
			RemoveOfficersIndex(PChar, GetCharacterIndex("Carib_Warrior"));
			RemovePassenger(PChar, sld);
			LAi_SetImmortal(sld, false);
			TakenItems(sld, "bladearrows", 1 + rand(2));
			GiveItem2Character(sld, "pistolbow");
			GiveItem2Character(sld, "tomahawk");
			EquipCharacterByItem(sld, "pistolbow");
			LAi_SetActorType(sld);
			LAi_ActorFollow(sld, characterFromID("Carib_Chief"), "", 30.0);
			LAi_QuestDelay("crysskull_reset_falaise_de_fleur", 0.1);
			PChar.quest.crysskull_carib_in_santo_domingo.over = "yes";

			if (CheckAttribute(PChar, "quest.crysskull.replaced_officer") && !isofficer(Characters[sti(PChar.quest.crysskull.replaced_officer.id)]))
			{
				PChar.quest.crysskull_return_replaced_officer.win_condition.l1 = "location";
				PChar.quest.crysskull_return_replaced_officer.win_condition.l1.location = "Guadeloupe";
				PChar.quest.crysskull_return_replaced_officer.win_condition = "crysskull_return_replaced_officer";
			}
		break;

		case "crysskull_return_replaced_officer":
			SetOfficersIndex(PChar, sti(PChar.quest.crysskull.replaced_officer.slot), sti(PChar.quest.crysskull.replaced_officer.id));
			DeleteQuestAttribute("crysskull.replaced_officer");
		break;

		case "crysskull_Carib_Warrior_reports":		// Triggered by dialog with "Carib_Chief" if "Carib_Warrior" is alive to make the report
			LAi_SetActorType(characterFromID("Carib_Warrior"));
			Characters[GetCharacterIndex("Carib_Warrior")].dialog.CurrentNode = "report_to_chief";
			LAi_ActorDialog(characterFromID("Carib_Warrior"), PChar, "crysskull_Carib_Chief_accepts_report",5.0,5.0);
		break;

		case "crysskull_Carib_Chief_accepts_report":
			LAi_SetActorType(characterFromID("Carib_Chief"));
			Characters[GetCharacterIndex("Carib_Chief")].dialog.CurrentNode = "warrior_likes_you";
			LAi_ActorDialog(characterFromID("Carib_Chief"), PChar, "",5.0,5.0);	// Exits to "crysskull_Carib_trade" or "crysskull_final_fight_Caribs"
		break;

		case "crysskull_Carib_trade":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, SKILL_LEADERSHIP, 5000);
				AddPartyExpChar(PChar, SKILL_SNEAK, 500);
			}
			else { AddPartyExp(PChar, 5000); }
			PlayStereoSound("INTERFACE\important_item.wav");
			TakeItemFromCharacter(PChar, "cryskull");
			PChar.quest.crys_skull_status = "traded";
			ChangeCharacterReputation(PChar, 3);
			OfficersReaction("good");
			if (PChar.quest.crysskull.ultimatum == "hostage")
			{
				cidx = sti(PChar.quest.crysskull.hostage);
				i = sti(PChar.quest.crysskull.hostage.slot);
				NPChar = GetCharacter(cidx);
				SetOfficersIndex(PChar, i, cidx);
				if (HasSubStr(NPChar.id, "Enc_Officer")) LAi_UnStoreFantom(NPChar); // Cancel protection
				DeleteQuestAttribute("crysskull.hostage");
				PChar.quest.crysskull_execute_hostage.over = "yes";
			}
			else
			{
				PlayStereoSound("INTERFACE\drink.wav");
				PChar.quest.crysskull_poison_player.over = "yes";
			}
			EndQuestMovie();
			DisableFastTravel(false);
			LAi_QuestDelay("crysskull_Carib_Chief_fetches_reward", 0.1);
			PChar.quest.crysskull_remove_Caribs.win_condition.l1 = "ExitFromLocation";
			PChar.quest.crysskull_remove_Caribs.win_condition.l1.location = PChar.location;
			PChar.quest.crysskull_remove_Caribs.win_condition = "crysskull_remove_Caribs";
		break;

		case "crysskull_Carib_Chief_fetches_reward":
			LAi_SetActorType(characterFromID("Carib_Chief"));
			LAi_ActorGoToLocation(characterFromID("Carib_Chief"), "reload", "reload3", "none", "", "", "crysskull_Carib_Chief_fetches_reward2", 60.0);
		break;

		case "crysskull_Carib_Chief_fetches_reward2":
			if (PChar.location == "Guadeloupe_Jungle_02") LAi_QuestDelay("crysskull_Carib_Chief_fetches_reward3", 3.0);
		break;

		case "crysskull_Carib_Chief_fetches_reward3":
			ChangeCharacterAddressGroup(characterfromID("Carib_Chief"), "Guadeloupe_Jungle_02", "reload", "reload3");
			LAi_SetActorType(characterFromID("Carib_Chief"));
			Characters[GetCharacterIndex("Carib_Chief")].dialog.CurrentNode = "here_is_reward";
			LAi_ActorDialog(characterFromID("Carib_Chief"), PChar, "",60.0,60.0);
		break;

		case "crysskull_remove_Caribs":
			PChar.quest.crysskull_Carib_Chief_fetches_reward3.over = "yes";
			Locations[FindLocation("Guadeloupe_Jungle_02")].models.always.locators = "jungle01_l";	// Put locators back to normal so "reload3" does not exist and can't be used by random encounters
			LAi_LocationFightDisable(&Locations[FindLocation("Guadeloupe_Jungle_02")], false);
			ChangeCharacterAddress(characterFromID("Carib_Chief"), "None", "");
			ChangeCharacterAddress(characterFromID("Carib_Warrior"), "None", "");
		break;

		case "crysskull_final_fight_Caribs":
			PChar.quest.crys_skull_status = "fought_Caribs";
			EndQuestMovie();				// Exits cleared, fast travel enabled
			DisableFastTravel(false);			// You can run away if you like but you won't get antidote or rescue your officer
			LAi_LocationFightDisable(&Locations[FindLocation("Guadeloupe_Jungle_02")], false);

			for (i=1; i<4; i++)
			{
				LAi_group_MoveCharacter(CharacterFromID("Carib" + i), LAi_monsters_group);
			}
			LAi_group_MoveCharacter(characterFromID("Carib_Chief"), LAi_monsters_group);
			LAi_group_MoveCharacter(characterFromID("Carib_Warrior"), LAi_monsters_group);

			if (PChar.quest.crysskull.ultimatum == "hostage")
			{
				cidx = sti(PChar.quest.crysskull.hostage);	// Hostage will join in fight on player's side
				NPChar = GetCharacter(cidx);
				LAi_group_MoveCharacter(NPChar, LAI_GROUP_PLAYER);
			}

			PChar.quest.crysskull_remove_Caribs_and_hostage.win_condition.l1 = "ExitFromLocation";
			PChar.quest.crysskull_remove_Caribs_and_hostage.win_condition.l1.location = PChar.location;
			PChar.quest.crysskull_remove_Caribs_and_hostage.win_condition = "crysskull_remove_Caribs_and_hostage";

			LAi_group_SetRelation(LAi_monsters_group, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups(LAi_monsters_group, LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck(LAi_monsters_group, "crysskull_final_fight_over");
		break;

		case "crysskull_remove_Caribs_and_hostage":
			PChar.quest.crysskull_final_fight_over.over = "yes";
			ChangeCharacterAddress(characterFromID("Carib_Chief"), "None", "");
			ChangeCharacterAddress(characterFromID("Carib_Warrior"), "None", "");
			if (PChar.quest.crysskull.ultimatum == "hostage")
			{
				cidx = sti(PChar.quest.crysskull.hostage);
				sld = GetCharacter(cidx);
				logit(TranslateString("", "You failed to rescue") + " " + GetMyFullName(sld) + ".");
				if (HasSubStr(sld.id, "Enc_Officer")) LAi_UnStoreFantom(sld); // Cancel protection
				LAi_KillCharacter(sld);
				ChangeCharacterAddress(sld, "None", "");
				PChar.quest.crysskull_execute_hostage.over = "yes";
				Preprocessor_AddQuestData("hostage", GetMyFullName(sld));
				AddQuestRecord("crystal_skull", 20);
				Preprocessor_Remove("hostage");
			}
			else AddQuestRecord("crystal_skull", 21);
		break;

		case "crysskull_final_fight_over":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, SKILL_LEADERSHIP, 5000);
				AddPartyExpChar(PChar, SKILL_FENCING, 500);
			}
			else { AddPartyExp(PChar, 5000); }
			PChar.quest.crys_skull_status = "defeated_Caribs";
			PChar.quest.crysskull_remove_Caribs_and_hostage.over = "yes";
			if (PChar.quest.crysskull.ultimatum == "hostage")
			{
				cidx = sti(PChar.quest.crysskull.hostage);
				i = sti(PChar.quest.crysskull.hostage.slot);
				NPChar = GetCharacter(cidx);
				if (!LAi_isDead(NPChar))
				{
					SetOfficersIndex(PChar, i, cidx);
					for (j = 0; j < GetPassengersQuantity(PChar); j++)	// Everyone rated for "loyality" gets an increase because you put yourself at risk to save an officer
					{
						iPassenger = GetPassenger(PChar, j);
						if(iPassenger != -1)
						{
							sld = GetCharacter(iPassenger);
							if(CheckAttribute(sld, "loyality")) sld.loyality = sti(sld.loyality) + 1;
						}
					}
					Preprocessor_AddQuestData("hostage", GetMyFullName(NPChar));
					AddQuestRecord("crystal_skull", 18);
					Preprocessor_Remove("hostage");
				}
				else
				{
					Preprocessor_AddQuestData("hostage", GetMyFullName(NPChar));
					AddQuestRecord("crystal_skull", 19);
					Preprocessor_Remove("hostage");
				}
				if (HasSubStr(NPChar.id, "Enc_Officer")) LAi_UnStoreFantom(NPChar); // Cancel protection
				DeleteQuestAttribute("crysskull.hostage");
				PChar.quest.crysskull_execute_hostage.over = "yes";
			}
			else
			{
				PlayStereoSound("INTERFACE\drink.wav");
				PChar.quest.crysskull_poison_player.over = "yes";
				AddQuestRecord("crystal_skull", 17);
			}
		break;

		case "crysskull_researcher_fetches_antidote":
			LAi_SetActorType(characterFromID("Skull_Researcher"));
			LAi_ActorGoToLocation(characterFromID("Skull_Researcher"), "reload", "reload2", "none", "", "", "crysskull_researcher_fetches_antidote2", 30.0);
		break;

		case "crysskull_researcher_fetches_antidote2":
			if (PChar.location == "Santo_Domingo_Historian_House") LAi_QuestDelay("crysskull_researcher_fetches_antidote3", 3.0);
			else
			{
				Characters[GetCharacterIndex("Skull_Researcher")].dialog.CurrentNode = "here_is_antidote";
				ChangeCharacterAddressGroup(characterfromID("Skull_Researcher"), "Santo_Domingo_Historian_House", "goto", "goto3");
				LAi_SetCitizenType(characterfromID("Skull_Researcher"));
			}
		break;

		case "crysskull_researcher_fetches_antidote3":
			ChangeCharacterAddressGroup(characterfromID("Skull_Researcher"), "Santo_Domingo_Historian_House", "reload", "reload2");
			LAi_SetActorType(characterFromID("Skull_Researcher"));
			Characters[GetCharacterIndex("Skull_Researcher")].dialog.CurrentNode = "here_is_antidote";
			LAi_ActorDialog(characterFromID("Skull_Researcher"), PChar, "",30.0,30.0);
		break;

		case "crysskull_officer_betrayed":
			OfficersReaction("bad");
			ChangeCharacterReputation(PChar, -3);
			if (CheckAttribute(PChar, "quest.crysskull.hostage"))
			{
				cidx = sti(PChar.quest.crysskull.hostage);
				i = sti(PChar.quest.crysskull.hostage.slot);
				NPChar = GetCharacter(cidx);
				if (!LAi_isDead(NPChar)) LAi_KillCharacter(sld);
				if (HasSubStr(NPChar.id, "Enc_Officer")) LAi_UnStoreFantom(NPChar); // Cancel protection
				DeleteQuestAttribute("crysskull.hostage");
			}
			PChar.quest.crysskull_execute_hostage.over = "yes";
		break;
///////////////////////////////////////////////////////////////////////
// The Quest for the Crystal Skull - end
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// Colombian Silver
///////////////////////////////////////////////////////////////////////
		case "colombian_silver_start":
			SetEnterLocationQuest("Smugglers_Tavern", "colombian_silver_start_check", 0);
		break;

		case "colombian_silver_start_check":
			if (GetLetterOfMarqueQuantity() == 0 && GetServedNation() == PIRATE && !HaveLetterOfMarque(PIRATE))	// Only intended for pirates who don't want to join the Brotherhood
			{
				if (sti(PChar.rank) >= 12)
				{
					ChangeCharacterAddressGroup(CharacterFromID("Meredith Byrom"), "Smugglers_Tavern", "candles", "sit3");
// Move to "goto","goto5", or "tables","table1" when he stands up
					LAi_SetSitType(CharacterFromID("Meredith Byrom"));
					Characters[GetCharacterIndex("Meredith Byrom")].dialog.currentnode = "intro";
				}
			}
			else LAi_QuestDelay("colombian_silver_cancel_check", 0.1);
		break;

		case "colombian_silver_cancel_check":
			DeleteEnterLocationQuest("Smugglers_Tavern", "colombian_silver_start_check");
			ChangeCharacterAddress(CharacterFromID("Meredith Byrom"), "None", "");
		break;

		case "colombian_silver_hire_byrom":
			NPChar = CharacterFromID("Meredith Byrom");
			ChangeCharacterAddressGroup(NPChar, "Smugglers_Tavern", "tables", "table1");
			LAi_SetOfficerType(NPChar);
			AddPassenger(PChar, NPChar, 0);
			if (SetOfficersIndex(PChar, -1, GetCharacterIndex("Meredith Byrom")) == GetCharacterIndex("Meredith Byrom"))
			{
				for (i=1; i<OFFICER_MAX; i++)
				{
					ch = GetCharacter(GetOfficersIndex(PChar, i));
					if (GetRemovable(ch))
					{
						SetOfficersIndex(PChar, i, GetCharacterIndex("Meredith Byrom"));
						break;
					}
				}
			}
			if (isofficer(NPChar)) SetCharacterRemovable(NPChar, false);
			else
			{
				LAi_SetActorType(NPChar);
				LAi_ActorFollowEverywhere(NPChar, "", 60.0);
				PChar.quest.colombian_silver_byrom_boards.win_condition.l1 = "location";
				PChar.quest.colombian_silver_byrom_boards.win_condition.l1.location = "Conceicao";
				PChar.quest.colombian_silver_byrom_boards.win_condition = "colombian_silver_byrom_boards";
			}

			SetQuestHeader("colombian_silver");
			Preprocessor_AddQuestData("name", GetMyFullName(NPChar));
			Preprocessor_AddQuestData("percent", PChar.quest.colombian_silver.byrom_price);
			AddQuestRecord("colombian_silver", 22);
			Preprocessor_Remove("percent");
			Preprocessor_Remove("name");

			LAi_QuestDelay("colombian_silver_prepare_taverns", 0.1);
		break;

		case "colombian_silver_byrom_boards":
			NPChar = CharacterFromID("Meredith Byrom");
			ChangeCharacterAddress(NPChar, "None", "");
			LAi_SetActorType(NPChar);
			LAi_type_Actor_Reset(NPChar);
		break;

		case "colombian_silver_prepare_taverns":		// Triggered by "Gov MR_dialog.c" or "Meredith Byrom_dialog.c"
			DeleteEnterLocationQuest("Smugglers_Tavern", "colombian_silver_start_check");
			PChar.quest.colombian_silver.status = "start";
			Locations[FindLocation("Cartagena_tavern")].vcskip = true;
			SetRandomNameToCharacter(CharacterFromID("CS_soldier_01"));
			ChangeCharacterAddressGroup(CharacterFromID("CS_soldier_01"), "Cartagena_tavern", "sit", "sit17");
			LAi_SetSitType(CharacterFromID("CS_soldier_01"));
			SetRandomNameToCharacter(CharacterFromID("CS_soldier_02"));
			ChangeCharacterAddressGroup(CharacterFromID("CS_soldier_02"), "Cartagena_tavern", "sit", "sit19");
			LAi_SetSitType(CharacterFromID("CS_soldier_02"));
			SetRandomNameToCharacter(CharacterFromID("CS_soldier_03"));
			ChangeCharacterAddressGroup(CharacterFromID("CS_soldier_03"), "Cartagena_tavern", "sit", "sit22");
			LAi_SetSitType(CharacterFromID("CS_soldier_03"));
			SetRandomNameToCharacter(CharacterFromID("CS_soldier_04"));
			ChangeCharacterAddressGroup(CharacterFromID("CS_soldier_04"), "Cartagena_tavern", "sit", "sit23");
			LAi_SetSitType(CharacterFromID("CS_soldier_04"));
			SetRandomNameToCharacter(CharacterFromID("CS_soldier_05"));
			ChangeCharacterAddressGroup(CharacterFromID("CS_soldier_05"), "Cartagena_tavern2", "goto", "goto4");
			LAi_SetCivilianPatrolType(CharacterFromID("CS_soldier_05"));
			GiveSoldierWeapon(CharacterFromID("CS_soldier_05"), SPAIN);
			SetRandomNameToCharacter(CharacterFromID("CS_tavern_officer"));
			ChangeCharacterAddressGroup(CharacterFromID("CS_tavern_officer"), "Cartagena_tavern2", "sit", "sit4");
			LAi_SetSitType(CharacterFromID("CS_tavern_officer"));

			Group_CreateGroup("Cartagena Silver Fleet");
			Group_AddCharacter("Cartagena Silver Fleet", "CS_Spanish_Captain1");
			Group_AddCharacter("Cartagena Silver Fleet", "CS_Spanish_Captain2");
			Group_AddCharacter("Cartagena Silver Fleet", "CS_Spanish_Captain3");
			Group_AddCharacter("Cartagena Silver Fleet", "CS_Spanish_Captain4");
			Group_SetGroupCommander("Cartagena Silver Fleet", "CS_Spanish_Captain1");
			Group_SetAddress("Cartagena Silver Fleet", "Colombia", "Quest_Ships","Quest_ship_11");
			Group_CreateGroup("Cartagena Silver Fleet2");
			Group_AddCharacter("Cartagena Silver Fleet2", "CS_Spanish_Captain5");
			Group_SetGroupCommander("Cartagena Silver Fleet2", "CS_Spanish_Captain5");
			Group_SetAddress("Cartagena Silver Fleet2", "Colombia", "Quest_Ships","Quest_ship_2");
			SetCharacterShipLocation(CharacterFromID("CS_Spanish_Captain1"), "Cartagena_port");
			SetCharacterShipLocation(CharacterFromID("CS_Spanish_Captain2"), "Cartagena_port");
			SetCharacterShipLocation(CharacterFromID("CS_Spanish_Captain3"), "Cartagena_port");
			SetCharacterShipLocation(CharacterFromID("CS_Spanish_Captain4"), "Cartagena_port");
		break;

		case "colombian_silver_reject_quest":		// Triggered by "Gov MR_dialog.c"
			SetQuestHeader("colombian_silver");
			if(GetRMRelation(PChar, SPAIN) >= REL_AMNESTY) AddQuestRecord("colombian_silver", 20);
			else AddQuestRecord("colombian_silver", 19);
			CloseQuestHeader("colombian_silver");
			PChar.quest.colombian_silver.status = "reject";
			PChar.quest.colombian_silver_reset_quest.win_condition.l1 = "Timer";
			PChar.quest.colombian_silver_reset_quest.win_condition.l1.date.day = GetAddingDataDay(1,0,0);
			PChar.quest.colombian_silver_reset_quest.win_condition.l1.date.month = GetAddingDataMonth(1,0,0);
			PChar.quest.colombian_silver_reset_quest.win_condition.l1.date.year = GetAddingDataYear(1,0,0);
			PChar.quest.colombian_silver_reset_quest.win_condition = "colombian_silver_reset_quest";
		break;

		case "colombian_silver_reset_quest":
			DeleteQuestAttribute("colombian_silver");	// Wipe "PChar.quest.colombian_silver" so that "Gov MR_dialog.c" can trigger the quest again
			DeleteQuestHeader("colombian_silver");		// Wipe the questbook too, so that it can be restarted
		break;

		case "colombian_silver_join_soldier":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -2);
			LAi_Fade("colombian_silver_join_soldier2", "colombian_silver_talk_soldier");
		break;
		
		case "colombian_silver_join_soldier2":
			LAi_SetActorType(PChar);
			LAi_ActorSetSitMode(PChar);
			switch(PChar.quest.colombian_silver.tavern1_friend)
			{
				case "CS_soldier_01": ChangeCharacterAddressGroup(PChar, "Cartagena_tavern", "sit", "sit20"); break;
				case "CS_soldier_02": ChangeCharacterAddressGroup(PChar, "Cartagena_tavern", "sit", "sit18"); break;
				case "CS_soldier_03": ChangeCharacterAddressGroup(PChar, "Cartagena_tavern", "sit", "sit24"); break;
				case "CS_soldier_04": ChangeCharacterAddressGroup(PChar, "Cartagena_tavern", "sit", "sit21"); break;
				ChangeCharacterAddressGroup(PChar, "Cartagena_tavern", "sit", "sit20");
			}
		break;

		case "colombian_silver_talk_soldier":
			sld = CharacterFromID(PChar.quest.colombian_silver.tavern1_friend);
			sld.dialog.CurrentNode = "why_are_you_here";
			LAi_ActorDialogNow(PChar, sld, "", -1);
		break;

		case "colombian_silver_leave_soldier":
			LAi_SetPlayerType(PChar);
			switch(PChar.quest.colombian_silver.tavern1_friend)
			{
				case "CS_soldier_01": ChangeCharacterAddressGroup(PChar, "Cartagena_tavern", "tables", "table5"); break;
				case "CS_soldier_02": ChangeCharacterAddressGroup(PChar, "Cartagena_tavern", "tables", "table5"); break;
				case "CS_soldier_03": ChangeCharacterAddressGroup(PChar, "Cartagena_tavern", "tables", "table6"); break;
				case "CS_soldier_04": ChangeCharacterAddressGroup(PChar, "Cartagena_tavern", "tables", "table6"); break;
				ChangeCharacterAddressGroup(PChar, "Cartagena_tavern", "tables", "table5");
			}
		break;

		case "colombian_silver_join_officer":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -2);
			LAi_Fade("colombian_silver_join_officer2", "colombian_silver_talk_officer");
		break;
		
		case "colombian_silver_join_officer2":
			LAi_SetActorType(PChar);
			LAi_ActorSetSitMode(PChar);
			ChangeCharacterAddressGroup(PChar, "Cartagena_tavern2", "sit", "sit5");
		break;

		case "colombian_silver_talk_officer":
			sld = CharacterFromID("CS_tavern_officer");
			sld.dialog.CurrentNode = "generous";
			LAi_ActorDialogNow(PChar, sld, "", -1);	// Triggers "colombian_silver_tavern2_soldier_leaves", also sets "colombian_silver.status" to either "arrest_inside" or "arrest_outside" depending on whether you choose to leave
		break;

		case "colombian_silver_tavern2_soldier_leaves":
			sld = CharacterFromID("CS_soldier_05");
			LAi_SetActorType(sld);
			LAi_ActorGoToLocation(sld, "reload", "reload1", "none", "", "", "colombian_silver_soldier_left_tavern", 10.0);
			if (CheckQuestAttribute("colombian_silver.status", "arrest_outside"))	// You chose to end the conversation with the officer prematurely
			{
//				LAi_QuestDelay("colombian_silver_leave_officer", 0.1);		// Stand up
				LAi_SetPlayerType(PChar);
				ChangeCharacterAddressGroup(PChar, "Cartagena_tavern2", "tables", "table4");
				LAi_QuestDelay("colombian_silver_jimena_talks", 0.1);		// Jimena tries to talk to you before you leave
				Locations[FindLocation("Cartagena_Center")].vcskip = true;
				PChar.quest.colombian_silver_exit_tavern2.win_condition.l1 = "location";
				PChar.quest.colombian_silver_exit_tavern2.win_condition.l1.location = "Cartagena_Center";
				PChar.quest.colombian_silver_exit_tavern2.win_condition = "colombian_silver_exit_tavern2";
			}
			else LAi_QuestDelay("colombian_silver_talk_officer2", 0.1);
		break;

		case "colombian_silver_talk_officer2":
			sld = CharacterFromID("CS_tavern_officer");
			sld.dialog.CurrentNode = "delay_for_squad";
			LAi_ActorDialogNow(PChar, sld, "", -1);
		break;

//		case "colombian_silver_leave_officer":
//			LAi_SetPlayerType(PChar);
//			ChangeCharacterAddressGroup(PChar, "Cartagena_tavern2", "tables", "table4");
//		break;

		case "colombian_silver_soldier_left_tavern":
			PChar.quest.colombian_silver.soldier_left_tavern = "true";
		break;

		case "colombian_silver_exit_tavern2":
			LAi_QuestDelay("colombian_silver_reset_tavern1", 0.1);
			DeleteAttribute(&Locations[FindLocation("Cartagena_Center")],"vcskip");
			if(CheckQuestAttribute("colombian_silver.soldier_left_tavern", "true"))
			{
				DisableFastTravel(true);
				LAi_QuestDelay("colombian_silver_fight_outside_tavern", 0.0);
				LAi_QuestDelay("colombian_silver_officer_joins_fight", 2.0);
			}
			else
			{
				LAi_SetGuardianType(CharacterFromID("CS_soldier_05"));
			}
			ChangeCharacterAddress(CharacterFromID("CS_soldier_05"), "None", "");

			NPChar = CharacterFromID("Cartagena_officiant2");		// Jimena tried to talk to you about buying wine before you left
			NPChar.Dialog.Filename = "eng_officiant_dialog.c";		// so reset her to normal tavern girl dialog and movement
			NPChar.dialog.CurrentNode = "First time";
			LAi_SetWaitressType(NPChar);
			if(!CheckQuestAttribute("colombian_silver.status", "buy_wine"))	// If you left the tavern before Jimena talked to you, set her up to try again
			{
				Locations[FindLocation("Cartagena_tavern2")].reload.l1.disable = 1;
				PChar.quest.colombian_silver_jimena_talks.win_condition.l1 = "location";
				PChar.quest.colombian_silver_jimena_talks.win_condition.l1.location = "Cartagena_tavern2";
				PChar.quest.colombian_silver_jimena_talks.win_condition = "colombian_silver_jimena_talks";
			}
		break;

		case "colombian_silver_arrest_inside":
			DisableFastTravel(true);
			LAi_QuestDelay("colombian_silver_reset_tavern1", 0.1);
			LAi_SetPlayerType(PChar);
			ChangeCharacterAddressGroup(PChar, "Cartagena_tavern2", "goto", "goto4");

			sld = CharacterFromID("CS_tavern_officer");
			ChangeCharacterAddressGroup(sld, "Cartagena_tavern2", "tables", "table4");
			LAi_SetActorType(sld);
			LAi_ActorAttack(sld, PChar, "");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");

			sld = CharacterFromID("CS_soldier_05");
			ChangeCharacterAddressGroup(sld, "Cartagena_tavern2", "reload", "reload1");
			LAi_SetActorType(sld);
			LAi_ActorAttack(sld, PChar, "");
			LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");

			LAi_SetImmortal(CharacterfromID("Cartagena_officiant2"), true);		// Prevent Jimena from being killed in the fight as she's needed for the next bit
			for (i=1; i<=4; i++)
			{
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.0, Nations[SPAIN].fantomModel.m1, "reload", "reload1");
				sld.id = "CS_Ambusher" +i;
				sld.nation = SPAIN;
				SetRandomNameToCharacter(sld);
				GiveSoldierWeapon(sld, SPAIN);
				LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			}
			Locations[FindLocation("Cartagena_tavern2")].reload.l1.disable = 1;
			DisableFastTravel(true);
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SPAIN_SOLDIERS", "colombian_silver_fight_inside_tavern_over");
		break;

		case "colombian_silver_fight_inside_tavern_over":
			PChar.quest.colombian_silver.status = "arrest_defeated";
			Locations[FindLocation("Cartagena_tavern2")].reload.l1.disable = 1;
			LAi_QuestDelay("colombian_silver_jimena_talks", 0.1);
		break;

		case "colombian_silver_reset_tavern1":
			DeleteAttribute(&Locations[FindLocation("Cartagena_tavern")],"vcskip");
			ChangeCharacterAddress(CharacterFromID("CS_soldier_01"), "None", "");
			ChangeCharacterAddress(CharacterFromID("CS_soldier_02"), "None", "");
			ChangeCharacterAddress(CharacterFromID("CS_soldier_03"), "None", "");
			ChangeCharacterAddress(CharacterFromID("CS_soldier_04"), "None", "");
		break;

		case "colombian_silver_fight_outside_tavern":
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.0, Nations[SPAIN].fantomModel.m1, "officers", "reload4_1");
			sld.id = "CS_Ambusher1";
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.0, Nations[SPAIN].fantomModel.m2, "officers", "reload4_2");
			sld.id = "CS_Ambusher2";
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.0, Nations[SPAIN].fantomModel.m3, "officers", "reload4_3");
			sld.id = "CS_Ambusher3";
			sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.0, Nations[SPAIN].fantomModel.m4, "goto", "goto27");
			sld.id = "CS_Ambusher4";
			for (i=1; i<=4; i++)
			{
				sld = CharacterFromID("CS_Ambusher" + i);
				sld.nation = SPAIN;
				SetRandomNameToCharacter(sld);
				GiveSoldierWeapon(sld, SPAIN);
				LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
				attr = "l"+i;
				PChar.quest.colombian_silver_fight_outside_tavern_over.win_condition.(attr) = "NPC_Death";
				PChar.quest.colombian_silver_fight_outside_tavern_over.win_condition.(attr).character = "CS_Ambusher" + i;
			}
			PChar.quest.colombian_silver_fight_outside_tavern_over.win_condition = "colombian_silver_fight_outside_tavern_over";

			StartQuestMovie(true, false, false);
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
		break;

		case "colombian_silver_officer_joins_fight":
			sld = CharacterFromID("CS_tavern_officer");
			ChangeCharacterAddressGroup(sld, "Cartagena_Center", "reload", "reload5");
			LAi_SetActorType(sld);
			LAi_ActorAttack(sld, PChar, "");
		break;

		case "colombian_silver_fight_outside_tavern_over":
			EndQuestMovie();
			DisableFastTravel(false);
			PChar.quest.colombian_silver.status = "arrest_defeated";
		break;

		case "colombian_silver_jimena_talks":
			DisableFastTravel(true);
			LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_tavern2")], true);
			LAi_SetFightMode(PChar, false);
			NPChar = CharacterFromID("Cartagena_officiant2");
			LAi_SetImmortal(NPChar, false);
			NPChar.Dialog.Filename = "CS_Jimena_dialog.c";
			NPChar.dialog.CurrentNode = "overheard";
			LAi_SetActorType(NPChar);
			LAi_ActorDialog(NPChar, PChar, "",20.0,20.0);
		break;

		case "colombian_silver_after_talk_jimena":	// Triggered by dialog with Jimena Lopez
			PChar.quest.colombian_silver.status = "buy_wine";
			Locations[FindLocation("Cartagena_tavern2")].reload.l1.disable = 0;
			LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_tavern2")], false);
			DisableFastTravel(false);
			NPChar = CharacterFromID("Cartagena_officiant2");
			NPChar.Dialog.Filename = "eng_officiant_dialog.c";
			NPChar.dialog.CurrentNode = "First time";
			LAi_SetWaitressType(NPChar);
		break;

		case "colombian_silver_prepare_jimena_for_room":
			PChar.quest.colombian_silver_jimena_in_room.win_condition.l1 = "location";
			PChar.quest.colombian_silver_jimena_in_room.win_condition.l1.location = "Cartagena_upstairs2";
			PChar.quest.colombian_silver_jimena_in_room.win_condition = "colombian_silver_prepare_jimena_for_room2";
		break;

		case "colombian_silver_prepare_jimena_for_room2":
			LAi_SetActorType(PChar);
			LAi_ActorGoToLocator(PChar, "goto", "goto4", "colombian_silver_jimena_in_room", 5.0);
		break;

		case "colombian_silver_jimena_in_room":
			DisableFastTravel(true);
			NPChar = CharacterFromID("Cartagena_officiant2");
			LAi_ActorWaitDialog(PChar, NPChar);
			ChangeCharacterAddressGroup(NPChar, "Cartagena_upstairs2", "reload", "reload1");
			NPChar.Dialog.Filename = "CS_Jimena_dialog.c";
			switch(GetAttribute(PChar, "quest.colombian_silver.status"))
			{
				case "buy_wine": NPChar.dialog.CurrentNode = "talk_privately"; break;
				case "got_medicine": NPChar.dialog.CurrentNode = "you_have_medicine"; break;
				NPChar.dialog.CurrentNode = "talk_privately"; break;
			}
			LAi_SetActorType(NPChar);
			LAi_ActorDialog(NPChar, PChar, "colombian_silver_after_jimena_in_room",5.0,5.0);
		break;

		case "colombian_silver_after_jimena_in_room":
			NPChar = CharacterFromID("Cartagena_officiant2");
			LAi_SetActorType(NPChar);
			LAi_ActorGoToLocation(NPChar, "reload", "reload1", "none", "", "", "", 10.0);
			LAi_SetPlayerType(PChar);
			DisableFastTravel(false);
			PChar.quest.colombian_silver_after_jimena_in_room2.win_condition.l1 = "ExitFromLocation";
			PChar.quest.colombian_silver_after_jimena_in_room2.win_condition.l1.location = PChar.location;
			PChar.quest.colombian_silver_after_jimena_in_room2.win_condition = "colombian_silver_after_jimena_in_room2";
		break;

		case "colombian_silver_after_jimena_in_room2":
			LAi_QuestDelay("colombian_silver_reset_tavern1", 0.1);
			NPChar = CharacterFromID("Cartagena_officiant2");
			NPChar.Dialog.Filename = "eng_officiant_dialog.c";
			NPChar.Dialog.CurrentNode = "First time";
			NPChar.Dialog.TempNode = "First time";
			ChangeCharacterAddressGroup(NPChar, "Cartagena_tavern2", "goto", "goto3");
			LAi_SetWaitressType(NPChar);
		break;

		case "colombian_silver_check_return_with_medicine":	// Triggered by dialog with Jimena in tavern room
			NPChar = CharacterFromID("Cartagena_officiant2");
			Preprocessor_AddQuestData("name", GetMyFullName(NPChar));
			Preprocessor_AddQuestData("firstname", GetMyName(NPChar));
			AddQuestRecord("colombian_silver", 2);
			Preprocessor_Remove("firstname");
			Preprocessor_Remove("name");
			PChar.quest.colombian_silver_to_tavern_with_medicine.win_condition.l1 = "party_goods";
			PChar.quest.colombian_silver_to_tavern_with_medicine.win_condition.l1.goods = GOOD_TREATMENT;
			PChar.quest.colombian_silver_to_tavern_with_medicine.win_condition.l1.operation = ">=";
			PChar.quest.colombian_silver_to_tavern_with_medicine.win_condition.l1.quantity = 100;
			PChar.quest.colombian_silver_to_tavern_with_medicine.win_condition.l2 = "location";
			PChar.quest.colombian_silver_to_tavern_with_medicine.win_condition.l2.location = "Cartagena_tavern2";
			PChar.quest.colombian_silver_to_tavern_with_medicine.win_condition = "colombian_silver_to_tavern_with_medicine";
		break;

		case "colombian_silver_to_tavern_with_medicine":
			PChar.quest.colombian_silver.status = "got_medicine";
			NPChar = CharacterFromID("Cartagena_officiant2");
			NPChar.Dialog.Filename = "CS_Jimena_dialog.c";
			NPChar.Dialog.TempNode = "too_busy_to_talk";
			NPChar.Dialog.CurrentNode = "too_busy_to_talk";
		break;

		case "colombian_silver_jimena_sets_up_deal":		// Triggered by dialog with Jimena in tavern room
			Preprocessor_AddQuestData("name", GetMyFullName(CharacterFromID("Cartagena_officiant2")));
			AddQuestRecord("colombian_silver", 3);
			Preprocessor_Remove("name");
			PChar.quest.colombian_silver_meet_indians_on_beach.win_condition.l1 = "Timer";
			PChar.quest.colombian_silver_meet_indians_on_beach.win_condition.l1.date.day = GetAddingDataDay(0,0,2);
			PChar.quest.colombian_silver_meet_indians_on_beach.win_condition.l1.date.month = GetAddingDataMonth(0,0,2);
			PChar.quest.colombian_silver_meet_indians_on_beach.win_condition.l1.date.year = GetAddingDataYear(0,0,2);
			PChar.quest.colombian_silver_meet_indians_on_beach.win_condition.l2 = "location";
			PChar.quest.colombian_silver_meet_indians_on_beach.win_condition.l2.location = "Colombia_shore";
			PChar.quest.colombian_silver_meet_indians_on_beach.win_condition = "colombian_silver_meet_indians_on_beach";
		break;

		case "colombian_silver_meet_indians_on_beach":
			LAi_LocationFightDisable(&Locations[FindLocation("Colombia_shore")], true);
			LAi_SetFightMode(PChar, false);
			DisableFastTravel(true);
			StartQuestMovie(false, false, false);
			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", GetRandomRank(false, OFFIC_TYPE_GUARD, 0), true, 1.0, "Indian1_1", "goto", "locator27");
			sld.id = "Shore Indian 1";
			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", GetRandomRank(false, OFFIC_TYPE_GUARD, 0), true, 1.0, "Indian1_2", "goto", "goto35");
			sld.id = "Shore Indian 2";
			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", GetRandomRank(false, OFFIC_TYPE_GUARD, 0), true, 1.0, "Indian1_3", "goto", "goto41");
			sld.id = "Shore Indian 3";
			sld = LAi_CreateFantomCharacterExOtAt(false, OFFIC_TYPE_GUARD,"isIndian","","", GetRandomRank(false, OFFIC_TYPE_GUARD, 0), true, 1.0, "Indian2", "goto", "goto42");
			sld.id = "Shore Indian 4";
			for (i=1; i<=4; i++)
			{
				sld = CharacterFromID("Shore Indian " + i);
				sld.name = "Shore";
				sld.lastname = "Indian";
				LAi_group_MoveCharacter(sld, "SPAIN_CITIZENS");
				LAi_SetActorType(sld);
				LAi_ActorTurnToCharacter(sld, PChar);
			}
			sld = CharacterFromID("Columbian_Indian1");
			ChangeCharacterAddressGroup(sld, "Colombia_shore", "goto", "goto14");
			LAi_SetActorType(sld);
			LAi_ActorTurnToCharacter(sld, PChar);
			LAi_SetStayType(sld);
			sld.Dialog.Filename = "CS_Indian_dialog.c";
			sld.Dialog.CurrentNode = "have_you_medicine";
		break;

		case "colombian_silver_reset_indians1":			// Triggered by dialog with Indian on shore if your ship is not at the shore
			LAi_LocationFightDisable(&Locations[FindLocation("Colombia_shore")], false);
			DisableFastTravel(false);
			EndQuestMovie();
			PChar.quest.colombian_silver_reset_indians2.win_condition.l1 = "location";
			PChar.quest.colombian_silver_reset_indians2.win_condition.l1.location = "Colombia";
			PChar.quest.colombian_silver_reset_indians2.win_condition = "colombian_silver_reset_indians2";
		break;

		case "colombian_silver_reset_indians2":
			PChar.quest.colombian_silver_meet_indians_on_beach.win_condition.l1 = "location";
			PChar.quest.colombian_silver_meet_indians_on_beach.win_condition.l1.location = "Colombia_shore";
			PChar.quest.colombian_silver_meet_indians_on_beach.win_condition = "colombian_silver_meet_indians_on_beach";
		break;

		case "colombian_silver_unload_medicine":	// Triggered by dialog with Indian on shore
			PChar.quest.colombian_silver.status = "unloaded_medicine";
			RemoveCharacterGoods(PChar, GOOD_TREATMENT, 100);
			WaitDate("", 0, 0, 0, 1, rand(30));
			DoQuestReloadToLocation("Colombia_shore", "reload", "reload1", "colombian_silver_medicine_unloaded");
		break;

		case "colombian_silver_medicine_unloaded":
			AddQuestRecord("colombian_silver", 4);
			sld = CharacterFromID("Columbian_Indian1");
			ChangeCharacterAddressGroup(sld, "Colombia_shore", "goto", "goto18");
			sld.Dialog.CurrentNode = "follow_me";
			LAi_SetActorType(sld);
			LAi_ActorDialog(sld, PChar, "",5.0,5.0);
		break;

		case "colombian_silver_indians_leave_shore":	// Triggered by dialog with "Columbian_Indian1" if you admit to not having enough medicine
			AddQuestRecord("colombian_silver", 21);
			CloseQuestHeader("colombian_silver");
			LAi_LocationFightDisable(&Locations[FindLocation("Colombia_shore")], false);
			EndQuestMovie();
			LAi_SetActorType(CharacterFromID("Columbian_Indian1"));
			LAi_ActorGoToLocation(CharacterFromID("Columbian_Indian1"), "reload", "reload2_back", "none", "", "", "", 60.0);
			for (i=1; i<=4; i++)
			{
				sld = CharacterFromID("Shore Indian " + i);
				LAi_SetActorType(sld);
				LAi_ActorGoToLocation(sld, "reload", "reload2_back", "none", "", "", "", 60.0);
			}

			NPChar = CharacterFromID("Meredith Byrom");
			if (IsOfficer(NPChar) || IsPassenger(NPChar))
			{
				if (NPChar.location != PChar.location) PlaceCharacter(NPChar, "goto");
				LAi_SetActorType(NPChar);
				NPChar.Dialog.CurrentNode = "you_goofed";
				LAi_ActorDialog(NPChar, PChar, "", 20.0, 20.0);	// Triggers "colombian_silver_fight_byrom"
			}

			PChar.quest.colombian_silver_reset_indian1.win_condition.l1 = "ExitFromLocation";
			PChar.quest.colombian_silver_reset_indian1.win_condition.l1.location = PChar.location;
			PChar.quest.colombian_silver_reset_indian1.win_condition = "colombian_silver_reset_indian1";
		break;

		case "colombian_silver_reset_indian1":
			sld = CharacterFromID("Columbian_Indian1");
			ChangeCharacterAddressGroup(sld, "Colombian_Indian_Village", "goto", "goto7");
			sld.Dialog.Filename = "Enc_Walker.c";
			LAi_SetWarriorTypeNoGroup(sld);
			LAi_warrior_DialogEnable(sld, true);
		break;

		case "colombian_silver_follow_indian1":
			if(CheckQuestAttribute("colombian_silver.status", "not_unloaded_medicine"))
			{
				if(GetSquadronGoods(PChar, GOOD_TREATMENT) >= 100) AddQuestRecord("colombian_silver", 5);
				else AddQuestRecord("colombian_silver", 6);
			}
			LAi_LocationFightDisable(&Locations[FindLocation("Colombia_shore")], false);
			EndQuestMovie();
			LAi_SetActorType(CharacterFromID("Columbian_Indian1"));
			LAi_ActorGoToLocator(CharacterFromID("Columbian_Indian1"), "reload", "reload2_back", "", 60.0);

			NPChar = CharacterFromID("Meredith Byrom");
			if (IsOfficer(NPChar) || IsPassenger(NPChar))
			{
				if (NPChar.location != PChar.location) PlaceCharacter(NPChar, "goto");
				LAi_SetActorType(NPChar);
				NPChar.Dialog.CurrentNode = "join_after_indians";
				LAi_ActorDialog(NPChar, PChar, "", 20.0, 20.0);
			}

			Locations[FindLocation("Colombia_Jungle_04")].vcskip = true;
			PChar.quest.colombian_silver_to_jungle04.win_condition.l1 = "location";
			PChar.quest.colombian_silver_to_jungle04.win_condition.l1.location = "Colombia_Jungle_04";
			PChar.quest.colombian_silver_to_jungle04.win_condition = "colombian_silver_to_jungle04";
		break;

		case "colombian_silver_byrom_follows":	// Triggered by dialog with Meredith Byrom
			NPChar = CharacterFromID("Meredith Byrom");
			if (!IsOfficer(NPChar))
			{
				LAi_SetActorType(NPChar);
				LAi_ActorFollowEverywhere(NPChar, "", 10.0);
			}
			else LAi_SetOfficerType(NPChar);
		break;

		case "colombian_silver_to_jungle04":
			sld = CharacterFromID("Columbian_Indian1");
			ChangeCharacterAddressGroup(sld, "Colombia_Jungle_04", "reload", "reload3");
			LAi_SetActorType(sld);
			LAi_type_actor_Reset(sld);
			LAi_ActorGoToLocator(sld, "goto", "citizen07", "colombian_silver_to_jungle04_2", 25.0);
			DeleteAttribute(&Locations[FindLocation("Colombia_Jungle_04")],"vcskip");
			Locations[FindLocation("Colombia_Jungle_04")].reload.l5.disable = 1;
			Locations[FindLocation("Colombia_Jungle_04")].reload.l6.disable = 1;
			Locations[FindLocation("Colombia_Jungle_01")].vcskip = true;
			PChar.quest.colombian_silver_to_jungle01.win_condition.l1 = "location";
			PChar.quest.colombian_silver_to_jungle01.win_condition.l1.location = "Colombia_Jungle_01";
			PChar.quest.colombian_silver_to_jungle01.win_condition = "colombian_silver_to_jungle01";
		break;

		case "colombian_silver_to_jungle04_2":		// Two-stage goto needed because going directly to "reload2_back" takes Indian on an odd route
			sld = CharacterFromID("Columbian_Indian1");
			LAi_SetActorType(sld);
			LAi_type_actor_Reset(sld);
			LAi_ActorGoToLocator(sld, "reload", "reload2_back", "", 90.0);
		break;

		case "colombian_silver_to_jungle01":
			sld = CharacterFromID("Columbian_Indian1");
			ChangeCharacterAddressGroup(sld, "Colombia_Jungle_01", "reload", "reload1");
			LAi_SetActorType(sld);
			LAi_type_actor_Reset(sld);
			LAi_ActorGoToLocator(sld, "reload", "reload3_back", "", 60.0);
			Locations[FindLocation("Colombia_Jungle_04")].reload.l5.disable = 0;
			Locations[FindLocation("Colombia_Jungle_04")].reload.l6.disable = 0;
			DeleteAttribute(&Locations[FindLocation("Colombia_Jungle_01")],"vcskip");
			Locations[FindLocation("Colombia_swamp")].vcskip = true;
			Locations[FindLocation("Colombia_Jungle_01")].reload.l3.disable = 1;
			Locations[FindLocation("Colombia_Jungle_01")].reload.l4.disable = 1;
			PChar.quest.colombian_silver_to_swamp.win_condition.l1 = "location";
			PChar.quest.colombian_silver_to_swamp.win_condition.l1.location = "Colombia_swamp";
			PChar.quest.colombian_silver_to_swamp.win_condition = "colombian_silver_to_swamp";
		break;

		case "colombian_silver_to_swamp":
			Locations[FindLocation("Colombia_Jungle_01")].reload.l3.disable = 0;
			Locations[FindLocation("Colombia_Jungle_01")].reload.l4.disable = 0;
			StartQuestMovie(true, false, false);
			sld = CharacterFromID("Columbian_Indian1");
			LAi_type_actor_Reset(sld);
			ChangeCharacterAddressGroup(sld, "Colombia_swamp", "reload", "reload2");
			LAi_ActorGoToLocator(sld, "reload", "reload1_back", "", 60.0);
			DeleteAttribute(&Locations[FindLocation("Colombia_swamp")],"vcskip");
			LAi_QuestDelay("colombian_silver_bitten", 10.0);
		break;

		case "colombian_silver_bitten":
			if(Pchar.sex == "man") {PlaySound("OBJECTS\DUEL\man_hit5.wav");}
			else{PlaySound("OBJECTS\DUEL\woman_hit3.wav");}
			LAi_SetActorType(PChar);
			LAi_ActorAnimation(PChar, "death_1", "colombian_silver_bitten2", 2.0);
		break;

		case "colombian_silver_bitten2":
			LAi_ActorAnimation(PChar, "Lay_1", "", -1);
			LAi_QuestDelay("colombian_silver_bitten3", 2.0);
		break;

		case "colombian_silver_bitten3":
			AddQuestRecord("colombian_silver", 7);
			cidx = -1;
			for(i = OFFICER_MAX; i>=1; i--)
			{
				if(GetOfficersIndex(PChar, i) > 0)
				{
					cidx = GetOfficersIndex(PChar, i);
					PChar.quest.colombian_silver.medicine_getter.slot = i;
				}
			}
			if (cidx > 0)
			{
				NPChar = GetCharacter(cidx);
				RemoveOfficersIndex(PChar, cidx);
				ChangeCharacterAddressGroup(NPChar, "Colombian_Indian_Village", "goto", "goto42");
			}
			PChar.quest.colombian_silver.medicine_getter = cidx;
			Locations[FindLocation("Colombian_Indian_Village")].reload.l1.disable = 1;
			Locations[FindLocation("Colombian_Indian_Village")].reload.l2.disable = 1;
			DoQuestReloadToLocation("Colombian_Indian_Village", "goto", "goto39", "colombian_silver_prepare_to_heal");
		break;

		case "colombian_silver_prepare_to_heal":
			sld = CharacterFromID("Columbian_Indian1");
			ChangeCharacterAddressGroup(sld, "Colombian_Indian_Village", "goto", "goto7");
			LAi_SetWarriorTypeNoGroup(sld);
			LAi_warrior_DialogEnable(sld, true);
			LAi_SetPlayerType(PChar);
			cidx = sti(PChar.quest.colombian_silver.medicine_getter);
			if(sti(cidx) > 0)
			{
				NPChar = GetCharacter(cidx);
				SetOfficersIndex(PChar, sti(PChar.quest.colombian_silver.medicine_getter.slot), cidx);
			}
			else
			{
				NPChar = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "sailor15", "goto", "goto42");
				NPChar.id = "medicine_getter";
				NPChar.nation = PChar.nation;
				SetRandomNameToCharacter(NPChar);
			}
			EndQuestMovie();

			NPChar = CharacterFromID("Columbian_Indian6");
			ChangeCharacterAddressGroup(NPChar, "Colombian_Indian_Village", "goto", "character8");
			NPChar.Dialog.Filename = "CS_Indian_dialog.c";
			NPChar.Dialog.CurrentNode = "bitten";
			LAi_SetActorType(NPChar);
			LAi_ActorDialog(NPChar, PChar, "",5.0,5.0);	// Triggers "colombian_silver_heal_from_bite", "colombian_silver_order_medicine" or "colombian_silver_poisoned"
		break;							// depending on whether you have already delivered medicine or how much you have

		case "colombian_silver_order_medicine":
			cidx = sti(PChar.quest.colombian_silver.medicine_getter);
			if(cidx > 0)
			{
				NPChar = GetCharacter(cidx);
				StoreDialog(NPChar);
			}
			else NPChar = CharacterFromID("medicine_getter");
			NPChar.Dialog.Filename = "CS_crew_dialog.c";
			NPChar.Dialog.CurrentNode = "order_medicine";
			LAi_SetActorType(NPChar);
			LAi_ActorDialog(NPChar, PChar, "colombian_silver_order_medicine2",5.0,5.0);
		break;

		case "colombian_silver_order_medicine2":
			cidx = sti(PChar.quest.colombian_silver.medicine_getter);
			if(cidx > 0) NPChar = GetCharacter(cidx);
			else NPChar = CharacterFromID("medicine_getter");
			LAi_SetActorType(NPChar);
			LAi_ActorGoToLocation(NPChar, "reload", "reload1", "none", "", "", "", 10.0);
			LAi_QuestDelay("colombian_silver_order_medicine3", 10.0);
		break;

		case "colombian_silver_order_medicine3":
			WaitDate("", 0, 0, 0, 1, rand(30));
			cidx = sti(PChar.quest.colombian_silver.medicine_getter);
			if(cidx > 0)
			{
				NPChar = GetCharacter(cidx);
				RestoreDialog(NPChar);
			}
			LAi_Fade("colombian_silver_order_medicine4", "colombian_silver_heal_from_bite");
		break;

		case "colombian_silver_order_medicine4":
			if(GetSquadronGoods(PChar, GOOD_TREATMENT) >= 100)
			{
				AddQuestRecord("colombian_silver", 8);
				PChar.quest.colombian_silver.status = "unloaded_medicine";
				RemoveCharacterGoods(PChar, GOOD_TREATMENT, 100);
			}
			if(PChar.quest.colombian_silver.status == "paid_difference")
			{
				AddQuestRecord("colombian_silver", 9);
				RemoveCharacterGoods(PChar, GOOD_TREATMENT, sti(GetSquadronGoods(PChar, GOOD_TREATMENT)));
			}
		break;

		case "colombian_silver_poisoned":
			LAi_KillCharacter(PChar);
			LAi_QuestDelay("colombian_silver_poisoned_game_over", 5.0);
		break;

		case "colombian_silver_poisoned_game_over":
			PChar.quest.disable_rebirth = true;
			PostEvent("LAi_event_GameOver", 0, "s", "land");
		break;

		case "colombian_silver_heal_from_bite":
			cidx = sti(GetAttribute(PChar, "quest.colombian_silver.medicine_getter"));
			if(cidx > 0)
			{
				NPChar = GetCharacter(cidx);
				RemoveOfficersIndex(PChar, cidx);
			}
			DoQuestReloadToLocation("Colombian_Indian_Village", "goto", "goto39", "colombian_silver_heal_from_bite2");
		break;

		case "colombian_silver_heal_from_bite2":
			cidx = sti(GetAttribute(PChar, "quest.colombian_silver.medicine_getter"));
			if(cidx > 0)
			{
				NPChar = GetCharacter(cidx);
				ChangeCharacterAddressGroup(NPChar, "Colombian_Indian_Village", "goto", "goto42");
				SetOfficersIndex(PChar, sti(PChar.quest.colombian_silver.medicine_getter.slot), cidx);
			}

			Locations[FindLocation("Colombian_Indian_Village")].reload.l1.disable = 0;
			Locations[FindLocation("Colombian_Indian_Village")].reload.l2.disable = 0;

			sld = CharacterFromID("Columbian_Indian1");
			LAi_SetActorType(sld);
			if(CheckQuestAttribute("colombian_silver.status", "unloaded_medicine") || CheckQuestAttribute("colombian_silver.status", "paid_difference"))
			{
				sld.Dialog.CurrentNode = "go_to_Spanish";
				Build_at("Colombia_Jungle_02", "Totem3", "", -26.0, 0.0, -18.5, 0.0, "");	// Indians like you, so mark the way back to the village
			}
			else
			{
				AddQuestRecord("colombian_silver", 10);
				sld.Dialog.CurrentNode = "back_to_jungle";
			}
			LAi_ActorDialog(sld, PChar, "colombian_silver_leave_indian_village",5.0,5.0);
		break;

		case "colombian_silver_leave_indian_village":
			LAi_SetActorType(CharacterFromID("Columbian_Indian1"));
			LAi_ActorGoToLocator(CharacterFromID("Columbian_Indian1"), "reload", "reload1", "", 30.0);

			Locations[FindLocation("Colombia_Jungle_02")].vcskip = true;
			PChar.quest.colombian_silver_to_jungle02.win_condition.l1 = "location";
			PChar.quest.colombian_silver_to_jungle02.win_condition.l1.location = "Colombia_Jungle_02";
			PChar.quest.colombian_silver_to_jungle02.win_condition = "colombian_silver_to_jungle02";
		break;

		case "colombian_silver_to_jungle02":
			DeleteAttribute(&Locations[FindLocation("Colombia_Jungle_02")],"vcskip");
			Locations[FindLocation("Colombia_swamp")].vcskip = true;
			sld = CharacterFromID("Columbian_Indian1");
			ChangeCharacterAddressGroup(sld, "Colombia_Jungle_02", "reload", "reload1");
			LAi_SetActorType(sld);
			LAi_type_actor_Reset(sld);
			if(CheckQuestAttribute("colombian_silver.status", "unloaded_medicine") || CheckQuestAttribute("colombian_silver.status", "paid_difference"))
			{
				LAi_ActorGoToLocator(sld, "reload", "reload3_back", "", 60.0);
				Locations[FindLocation("Colombia_Jungle_02")].reload.l1.disable = 0;	// Indians are your friends now, so you can return to the village
				Locations[FindLocation("Colombia_Jungle_02")].reload.l2.disable = 0;
				Locations[FindLocation("Colombia_Jungle_02")].reload.l3.disable = 1;
				Locations[FindLocation("Colombia_Jungle_02")].reload.l4.disable = 1;
				Locations[FindLocation("Colombia_swamp")].vcskip = true;
				PChar.quest.colombian_silver_return_swamp.win_condition.l1 = "location";
				PChar.quest.colombian_silver_return_swamp.win_condition.l1.location = "Colombia_swamp";
				PChar.quest.colombian_silver_return_swamp.win_condition = "colombian_silver_return_swamp";
			}
			else
			{
				sld.Dialog.CurrentNode = "go_away";
				LAi_ActorDialog(sld, PChar, "colombian_silver_indian_returns_to_village",5.0,5.0);
				if (Characters[GetCharacterIndex("Meredith Byrom")].location == PChar.location) LAi_QuestDelay("colombian_silver_fight_byrom", 0.5);
			}
		break;

		case "colombian_silver_indian_returns_to_village":
			sld = CharacterFromID("Columbian_Indian1");
			LAi_SetActorType(sld);
			LAi_type_actor_Reset(sld);
			LAi_ActorGoToLocation(sld, "reload1_back", "reload1", "none", "", "", "", 10.0);
			PChar.quest.colombian_silver_reset_indian1.win_condition.l1 = "ExitFromLocation";
			PChar.quest.colombian_silver_reset_indian1.win_condition.l1.location = PChar.location;
			PChar.quest.colombian_silver_reset_indian1.win_condition = "colombian_silver_reset_indian1";
		break;

		case "colombian_silver_return_swamp":
			Locations[FindLocation("Colombia_Jungle_02")].reload.l3.disable = 0;
			Locations[FindLocation("Colombia_Jungle_02")].reload.l4.disable = 0;
			Locations[FindLocation("Colombia_swamp")].reload.l1.disable = 0;
			Locations[FindLocation("Colombia_swamp")].reload.l2.disable = 0;
			Locations[FindLocation("Colombia_swamp")].reload.l3.disable = 1;
			Locations[FindLocation("Colombia_swamp")].reload.l4.disable = 1;
			Locations[FindLocation("Colombia_swamp")].reload.l5.disable = 1;
			Locations[FindLocation("Colombia_swamp")].reload.l6.disable = 1;
			sld = CharacterFromID("Columbian_Indian1");
			LAi_type_actor_Reset(sld);
			ChangeCharacterAddressGroup(sld, "Colombia_swamp", "reload", "reload3");
			LAi_ActorGoToLocator(sld, "reload", "reload1_back", "", 60.0);
			DeleteAttribute(&Locations[FindLocation("Colombia_swamp")],"vcskip");
			Locations[FindLocation("Colombia_Jungle_03")].models.always.locators = "Jungle07_l_GR";
			Locations[FindLocation("Colombia_Jungle_03")].vcskip = true;
			Locations[FindLocation("Colombia_Jungle_03")].locators_radius.goto.citizen013 = 4.0;
			PChar.quest.colombian_silver_arrive_jungle_03.win_condition.l1 = "location";
			PChar.quest.colombian_silver_arrive_jungle_03.win_condition.l1.location = "Colombia_Jungle_03";
			PChar.quest.colombian_silver_arrive_jungle_03.win_condition = "colombian_silver_arrive_jungle_03";
		break;

		case "colombian_silver_arrive_jungle_03":
			Locations[FindLocation("Colombia_swamp")].reload.l3.disable = 0;
			Locations[FindLocation("Colombia_swamp")].reload.l4.disable = 0;
			Locations[FindLocation("Colombia_swamp")].reload.l5.disable = 0;
			Locations[FindLocation("Colombia_swamp")].reload.l6.disable = 0;
//			Locations[FindLocation("Colombia_Jungle_03")].reload.l1.disable = 1;
//			Locations[FindLocation("Colombia_Jungle_03")].reload.l2.disable = 1;
			sld = CharacterFromID("Columbian_Indian1");
			LAi_type_actor_Reset(sld);
			ChangeCharacterAddressGroup(sld, "Colombia_Jungle_03", "goto", "citizen09");
			sld.Dialog.CurrentNode = "go_away_friend";
			LAi_ActorDialog(sld, PChar, "colombian_silver_prepare_ambush",5.0,5.0);
		break;

		case "colombian_silver_prepare_ambush":
			AddQuestRecord("colombian_silver", 11);
			SetCharacterShipLocation(CharacterFromID("CS_Spanish_Captain5"), "Colombia_shore");	// Put a Spanish ship near the beach
			sld = CharacterFromID("Columbian_Indian1");
			LAi_SetActorType(sld);
			LAi_type_actor_Reset(sld);
			LAi_ActorGoToLocation(sld, "reload1_back", "reload1", "none", "", "", "", 5.0);
			WaitDate("", 0, 0, 0, 2, rand(30));
			DoQuestReloadToLocation("Colombia_Jungle_03", "reload", "reload1", "colombian_silver_prepare_ambush2");
		break;

		case "colombian_silver_prepare_ambush2":
			ChangeCharacterAddressGroup(CharacterFromID("CS_soldier_01"), "Colombia_Jungle_03", "goto", "goto3");
			ChangeCharacterAddressGroup(CharacterFromID("CS_soldier_02"), "Colombia_Jungle_03", "goto", "goto3");
			LAi_SetActorType(CharacterFromID("CS_soldier_01"));
			LAi_ActorGoToLocator(CharacterFromID("CS_soldier_01"), "reload", "reload2_back", "", 60.0);
			LAi_SetActorType(CharacterFromID("CS_soldier_02"));
			LAi_ActorGoToLocator(CharacterFromID("CS_soldier_02"), "reload", "reload2_back", "", 60.0);

			PChar.quest.colombian_silver_advance_guard_spotted1.win_condition.l1 = "locator";
			PChar.quest.colombian_silver_advance_guard_spotted1.win_condition.l1.location = "Colombia_Jungle_03";
			PChar.quest.colombian_silver_advance_guard_spotted1.win_condition.l1.locator_group = "goto";
			PChar.quest.colombian_silver_advance_guard_spotted1.win_condition.l1.locator = "citizen013";
			PChar.quest.colombian_silver_advance_guard_spotted1.win_condition = "colombian_silver_advance_guard_spotted1";

			LAi_QuestDelay("colombian_silver_reset_indian1", 0.0);
			LAi_QuestDelay("colombian_silver_advance_guard_spotted1", 10.0);
		break;

		case "colombian_silver_advance_guard_spotted1":
			if(!CheckQuestAttribute("colombian_silver.status", "advance_guard_spotted"))
			{
				LAi_SetActorType(PChar);
				cidx = -1;
				for(i = OFFICER_MAX; i>=1; i--)
				{
					if(GetOfficersIndex(PChar, i) > 0)
					{
						cidx = GetOfficersIndex(PChar, i);
						PChar.quest.colombian_silver.ambush_officer.slot = i;
					}
				}
				if(cidx > 0)
				{
					NPChar = GetCharacter(cidx);
					PChar.quest.colombian_silver.ambush_officer = NPChar.id;
					StoreDialog(NPChar);
					NPChar.Dialog.Filename = "CS_crew_dialog.c";
					NPChar.Dialog.CurrentNode = "first_sighting";
					LAi_ActorWaitDialog(PChar, NPChar);
					LAi_SetActorType(NPChar);
					LAi_ActorDialog(NPChar, PChar, "colombian_silver_advance_guard_spotted2",5.0,5.0);
				}
				else
				{
					PChar.dialog.currentnode = "colombian_silver_first_sighting";
					LAi_ActorSelfDialog(PChar, "colombian_silver_advance_guard_spotted2");
				}
				PChar.quest.colombian_silver.status = "advance_guard_spotted";
				PChar.quest.colombian_silver_advance_guard_spotted1.over = "yes";
			}
		break;

		case "colombian_silver_advance_guard_spotted2":
			if(CheckAttribute(PChar, "quest.colombian_silver.ambush_officer"))
			{
				NPChar = CharacterFromID(PChar.quest.colombian_silver.ambush_officer);
				LAi_SetOfficerType(NPChar);
				RestoreDialog(NPChar);
			}
			LAi_SetPlayerType(PChar);
			Locations[FindLocation("Colombia_Jungle_03")].models.always.donkey1 = "donkey_loaded";
			Locations[FindLocation("Colombia_Jungle_03")].models.always.donkey1.locator.group = "goto";
			Locations[FindLocation("Colombia_Jungle_03")].models.always.donkey1.locator.name = "goto4";
			Locations[FindLocation("Colombia_Jungle_03")].models.always.donkey2 = "donkey_loaded";
			Locations[FindLocation("Colombia_Jungle_03")].models.always.donkey2.locator.group = "goto";
			Locations[FindLocation("Colombia_Jungle_03")].models.always.donkey2.locator.name = "goto5";
			Locations[FindLocation("Colombia_Jungle_03")].models.always.donkey3 = "donkey_loaded";
			Locations[FindLocation("Colombia_Jungle_03")].models.always.donkey3.locator.group = "goto";
			Locations[FindLocation("Colombia_Jungle_03")].models.always.donkey3.locator.name = "goto6";
			Locations[FindLocation("Colombia_Jungle_03")].models.always.donkey4 = "donkey_loaded";
			Locations[FindLocation("Colombia_Jungle_03")].models.always.donkey4.locator.group = "goto";
			Locations[FindLocation("Colombia_Jungle_03")].models.always.donkey4.locator.name = "goto7";

			for(i=10; i<=14; i++)
			{
				attr = "goto" + i;
				Locations[FindLocation("Colombia_Jungle_03")].locators_radius.goto.(attr) = 12.0;
			}

			DoQuestReloadToLocation("Colombia_Jungle_03", "reload", "reload4", "colombian_silver_advance_guard_spotted3");
		break;

		case "colombian_silver_advance_guard_spotted3":
			LAi_SetGuardianType(CharacterFromID("CS_soldier_01"));
			LAi_SetGuardianType(CharacterFromID("CS_soldier_02"));

			for(i=1; i<=8; i++)
			{
				if(i == 8) attr = "m" + (i-7);
				else attr = "m" + (i-1);
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.0, Nations[SPAIN].fantomModel.(attr), "goto", "goto" + (i+7));
				sld.id = "CS_Silver" + i;
				sld.nation = SPAIN;
				SetRandomNameToCharacter(sld);
				GiveSoldierWeapon(sld, SPAIN);
				LAi_SetGuardianType(sld);
				LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			}

			if(CheckAttribute(PChar, "quest.colombian_silver.ambush_officer"))
			{
				NPChar = CharacterFromID(PChar.quest.colombian_silver.ambush_officer)
				StoreDialog(NPChar);
				NPChar.Dialog.Filename = "CS_crew_dialog.c";
				NPChar.Dialog.CurrentNode = "second_sighting";
				LAi_SetActorType(PChar);
				LAi_ActorWaitDialog(PChar, NPChar);
				LAi_SetActorType(NPChar);
				LAi_ActorDialog(NPChar, PChar, "colombian_silver_set_ambush_triggers",5.0,5.0);
			}
			else LAi_QuestDelay("colombian_silver_set_ambush_triggers", 0.0);
		break;

		case "colombian_silver_set_ambush_triggers":
			if(CheckAttribute(PChar, "quest.colombian_silver.ambush_officer"))
			{
				NPChar = CharacterFromID(PChar.quest.colombian_silver.ambush_officer);
				LAi_SetOfficerType(NPChar);
				RestoreDialog(NPChar);
				LAi_SetPlayerType(PChar);
			}

			for(i=1; i<=5; i++)
			{
				attr = "colombian_silver_ambush_loctrigger" + i;
				PChar.quest.(attr).win_condition.l1 = "locator";
				PChar.quest.(attr).win_condition.l1.location = "Colombia_Jungle_03";
				PChar.quest.(attr).win_condition.l1.locator_group = "goto";
				PChar.quest.(attr).win_condition.l1.locator = "goto" + (i+9);
				PChar.quest.(attr).win_condition = "colombian_silver_ambush";
			}

			for(i=1; i<=8; i++)
			{
				sld = CharacterFromID("CS_Silver" + i);
				LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1.0, false, "colombian_silver_ambush");
			}
		break;

		case "colombian_silver_ambush":
			PChar.quest.colombian_silver_ambush_loctrigger1.over = "yes";
			PChar.quest.colombian_silver_ambush_loctrigger2.over = "yes";
			PChar.quest.colombian_silver_ambush_loctrigger3.over = "yes";
			PChar.quest.colombian_silver_ambush_loctrigger4.over = "yes";
			PChar.quest.colombian_silver_ambush_loctrigger5.over = "yes";
			for(i=8; i<=15; i++)
			{
				attr = "goto" + i;
				Locations[FindLocation("Colombia_Jungle_03")].locators_radius.goto.(attr) = 1.0;
			}

			for(i=1; i<=8; i++)
			{
				LAi_RemoveCheckMinHP(CharacterFromID("CS_Silver" + i));
			}

			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SPAIN_SOLDIERS", "colombian_silver_convoy_ambush_over");

			PChar.quest.colombian_silver_ambush_failed.win_condition.l1 = "ExitFromLocation";
			PChar.quest.colombian_silver_ambush_failed.win_condition.l1.location = PChar.location;
			PChar.quest.colombian_silver_ambush_failed.win_condition = "colombian_silver_ambush_failed";

			PChar.quest.colombian_silver_return_to_beach.win_condition.l1 = "location";
			PChar.quest.colombian_silver_return_to_beach.win_condition.l1.location = "Colombia_shore";
			PChar.quest.colombian_silver_return_to_beach.win_condition = "colombian_silver_return_to_beach";

			DeleteAttribute(&Locations[FindLocation("Colombia_Jungle_03")],"vcskip");

			SetCharacterShipLocation(CharacterFromID("CS_Spanish_Captain5"), "Colombia_shore");
			PChar.quest.colombian_silver.fleet_ready = "true";
		break;

		case "colombian_silver_ambush_failed":
			LAi_group_RemoveCheck("SPAIN_SOLDIERS");
			AddQuestRecord("colombian_silver", 13);
			ChangeCharacterAddress(CharacterFromID("CS_soldier_01"), "None", "");
			ChangeCharacterAddress(CharacterFromID("CS_soldier_02"), "None", "");
			PChar.quest.colombian_silver.status = "ambush_failed";
			for(i=1; i<=4; i++)
			{
				attr = "models.always.donkey" + i;
				DeleteAttribute(Locations[FindLocation("Colombia_Jungle_03")], attr);		// Remove donkeys from "Colombia_Jungle_03"
			}
			if (Characters[GetCharacterIndex("Meredith Byrom")].location == PChar.location) LAi_QuestDelay("colombian_silver_fight_byrom", 0.5);
		break;

		case "colombian_silver_convoy_ambush_over":
			PChar.quest.colombian_silver_ambush_failed.over = "yes";
			PChar.quest.colombian_silver.got_silver = "true";
			AddQuestRecord("colombian_silver", 12);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Sneak", 2000);
				AddPartyExpChar(PChar, "", 200);
			}
			else { AddPartyExp(PChar, 2000); }
			for(i = OFFICER_MAX; i>=1; i--)
			{
				if(GetOfficersIndex(PChar, i) > 0)
				{
					cidx = GetOfficersIndex(PChar, i);
					PChar.quest.colombian_silver.ambush_officer.slot = i;
				}
			}
			LAi_SetActorType(PChar);
			if(cidx > 0)
			{
				NPChar = GetCharacter(cidx);
				PChar.quest.colombian_silver.ambush_officer = NPChar.id;
				StoreDialog(NPChar);
				NPChar.Dialog.Filename = "CS_crew_dialog.c";
				NPChar.Dialog.CurrentNode = "battle_over";
				LAi_ActorWaitDialog(PChar, NPChar);
				LAi_SetActorType(NPChar);
				LAi_ActorDialog(NPChar, PChar, "colombian_silver_convoy_ambush_over2",5.0,5.0);
			}
			else
			{
				DeleteAttribute(PChar, "quest.colombian_silver.ambush_officer");
				PChar.dialog.currentnode = "colombian_silver_battle_over";
				LAi_ActorSelfDialog(PChar, "colombian_silver_convoy_ambush_over2");
			}
		break;

		case "colombian_silver_convoy_ambush_over2":
			if(CheckAttribute(PChar, "quest.colombian_silver.ambush_officer"))
			{
				NPChar = CharacterFromID(PChar.quest.colombian_silver.ambush_officer);
				LAi_SetOfficerType(NPChar);
				RestoreDialog(NPChar);
			}
			LAi_SetPlayerType(PChar);

			Locations[FindLocation("Colombia_Jungle_03")].models.always.locators = "Jungle07_l";
			Locations[FindLocation("Colombia_Jungle_04")].models.always.locators = "Jungle02_l_GR2";
			for(i=1; i<=4; i++)
			{
				attr = "models.always.donkey" + i;
				DeleteAttribute(Locations[FindLocation("Colombia_Jungle_03")], attr);		// Remove donkeys from "Colombia_Jungle_03"
				Locations[FindLocation("Colombia_Jungle_04")].(attr) = "donkey_loaded";		// Set up donkeys in "Colombia_Jungle_04" ready for next battle scene
				Locations[FindLocation("Colombia_Jungle_04")].(attr).locator.group = "goto";
				Locations[FindLocation("Colombia_Jungle_04")].(attr).locator.name = "goto" + (i+1);
			}
			DeleteAttribute(&Locations[FindLocation("Colombia_Jungle_03")],"vcskip");
//			Locations[FindLocation("Colombia_Jungle_03")].reload.l1.disable = 0;
//			Locations[FindLocation("Colombia_Jungle_03")].reload.l2.disable = 0;
			DoQuestReloadToLocation("Colombia_Jungle_04", "reload", "reload4", "colombian_silver_counterattack_setup");
		break;

		case "colombian_silver_counterattack_setup":
			for(i=1; i<=6; i++)
			{
				attr = "m" + (i-1);
				sld = LAi_CreateFantomCharacter(false, 1, true, true, 0.0, Nations[SPAIN].fantomModel.(attr), "reload", "reload1_back");
				sld.id = "CS_Silver2_" + i;
				sld.nation = SPAIN;
				SetRandomNameToCharacter(sld);
				GiveSoldierWeapon(sld, SPAIN);
				LAi_SetGuardianType(sld);
				LAi_group_MoveCharacter(sld, "SPAIN_SOLDIERS");
			}
			LAi_SetActorType(PChar);
			LAi_QuestDelay("colombian_silver_convoy_turn_to_counterattack", 0.0);
		break;

		case "colombian_silver_convoy_turn_to_counterattack":
			LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_FightGroups("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SPAIN_SOLDIERS", "colombian_silver_convoy_counterattack_over");

			LAi_ActorTurnToLocator(PChar, "reload", "reload1_back");
			LAi_QuestDelay("colombian_silver_convoy_counterattack2", 0.5);
		break;

		case "colombian_silver_convoy_counterattack2":
			LAi_SetPlayerType(PChar);
			PChar.quest.colombian_silver_ran_from_counterattack.win_condition.l1 = "ExitFromLocation";
			PChar.quest.colombian_silver_ran_from_counterattack.win_condition.l1.location = PChar.location;
			PChar.quest.colombian_silver_ran_from_counterattack.win_condition = "colombian_silver_ran_from_counterattack";
		break;

		case "colombian_silver_ran_from_counterattack":
			LAi_group_RemoveCheck("SPAIN_SOLDIERS");
			AddQuestRecord("colombian_silver", 15);
			PChar.quest.colombian_silver.status = "counterattack_succeeded";
			DeleteQuestAttribute("colombian_silver.got_silver");
			LAi_QuestDelay("colombian_silver_remove_jungle_04_donkeys", 0.0);
			if (Characters[GetCharacterIndex("Meredith Byrom")].location == PChar.location) LAi_QuestDelay("colombian_silver_fight_byrom", 0.5);
		break;

		case "colombian_silver_convoy_counterattack_over":
			AddQuestRecord("colombian_silver", 14);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, "Fencing", 2000);
				AddPartyExpChar(PChar, "", 200);
			}
			else { AddPartyExp(PChar, 2000); }
			PChar.quest.colombian_silver_ran_from_counterattack.over = "yes";
			PChar.quest.colombian_silver.status = "counterattack_defeated";
			LAi_QuestDelay("colombian_silver_remove_jungle_04_donkeys", 0.0);
		break;

		case "colombian_silver_remove_jungle_04_donkeys":
			for(i=1; i<=4; i++)
			{
				attr = "models.always.donkey" + i;
				DeleteAttribute(&Locations[FindLocation("Colombia_Jungle_04")], attr);		// Remove donkeys from "Colombia_Jungle_04"
			}
		break;

		case "colombian_silver_return_to_beach":
			DisableFastTravel(false);
			if(CheckQuestAttribute("colombian_silver.got_silver", "true") && CheckQuestAttribute("colombian_silver.status", "counterattack_defeated"))
			{
				for(i = OFFICER_MAX; i>=1; i--)
				{
					if(GetOfficersIndex(PChar, i) > 0)
					{
						cidx = GetOfficersIndex(PChar, i);
					}
				}
				if(cidx > 0)
				{
					LAi_SetActorType(PChar);
					NPChar = GetCharacter(cidx);
					PChar.quest.colombian_silver.beach_officer = NPChar.id;
					StoreDialog(NPChar);
					NPChar.Dialog.Filename = "CS_crew_dialog.c";
					NPChar.Dialog.CurrentNode = "on_shore";
					LAi_ActorWaitDialog(PChar, NPChar);
					LAi_SetActorType(NPChar);
					LAi_ActorDialog(NPChar, PChar, "colombian_silver_convoy_reset_beach_officer",5.0,5.0);
				}

				AddQuestRecord("colombian_silver", 16);
				AddCharacterGoods(PChar, GOOD_SILVER, 600);
				AddCharacterGoods(CharacterFromID("CS_Spanish_Captain1"), GOOD_SILVER, 300);
				if(AUTO_SKILL_SYSTEM)					// Extra XP if you succeeded in bringing back the silver
				{
					AddPartyExpChar(PChar, "Leadership", 5000);
					AddPartyExpChar(PChar, "", 500);
				}
				else {AddPartyExp(PChar, 5000);}
			}
			else
			{
				for(i = 1; i <= 3; i++)
				{
					sld = CharacterFromID("CS_Spanish_Captain"+i);
					AddCharacterGoods(sld, GOOD_SILVER, 300);
				}
			}
			if(AUTO_SKILL_SYSTEM)					// Basic XP for making it back to the beach
			{
				AddPartyExpChar(PChar, "Leadership", 5000);
				AddPartyExpChar(PChar, "", 500);
			}
			else {AddPartyExp(PChar, 5000);}

			if(CheckQuestAttribute("colombian_silver.fleet_ready", "true"))
			{
				sld = CharacterFromID("CS_Spanish_Captain5");	// In case this ship was already in a battle
				DeleteAttribute(sld, "surrendered");
				sld.nation = SPAIN;
				sld.Ship.crew.morale = 70;
				AddQuestRecord("colombian_silver", 17);
				PChar.quest.colombian_silver_sea_battle.win_condition.l1 = "location";
				PChar.quest.colombian_silver_sea_battle.win_condition.l1.location = "Colombia";
				PChar.quest.colombian_silver_sea_battle.win_condition = "colombian_silver_sea_battle";
			}

			PChar.quest.colombian_silver_escaped_to_sea.win_condition.l1 = "MapEnter";
			PChar.quest.colombian_silver_escaped_to_sea.win_condition = "colombian_silver_escaped_to_sea";
		break;

		case "colombian_silver_convoy_reset_beach_officer":
			NPChar = CharacterFromID(PChar.quest.colombian_silver.beach_officer);
			LAi_SetOfficerType(NPChar);
			RestoreDialog(NPChar);
			LAi_SetPlayerType(PChar);

			NPChar = CharacterFromID("Meredith Byrom");
			if (IsOfficer(NPChar) || IsPassenger(NPChar))
			{
				if (NPChar.location != PChar.location) PlaceCharacter(NPChar, "goto");
				LAi_SetActorType(NPChar);
				NPChar.Dialog.CurrentNode = "want_share";
				LAi_ActorDialog(NPChar, PChar, "", 20.0, 20.0);
			}
		break;

		case "colombian_silver_rehire_byrom":
			NPChar = CharacterFromID("Meredith Byrom");
			LAi_SetOfficerType(NPChar);
			if (!IsOfficer(NPChar)) NPChar.location = "none";
			NPChar.dialog.Filename = "Enc_Officer_dialog.c";
			NPChar.dialog.CurrentNode = "hired";
			SetCharacterRemovable(NPChar, true);
		break;

		case "colombian_silver_byrom_leaves":
			NPChar = CharacterFromID("Meredith Byrom");
			NPChar.location = "none";
			SetCharacterRemovable(NPChar, true);
			if (IsOfficer(NPChar)) RemoveOfficersIndex(PChar, GetCharacterIndex("Meredith Byrom"));
			LAi_SetActorType(NPChar);
			LAi_ActorGoToLocation(NPChar, "reload", "reload2_back", "none", "", "", "", 20.0);
		break;

		case "colombian_silver_sea_battle":
			i = Group_FindGroup("Cartagena Silver Fleet");
			if (i >= 0) Group_DeleteGroupIndex(i);

			i = Group_FindGroup("Cartagena Silver Fleet2");
			if (i >= 0) Group_DeleteGroupIndex(i);

			Group_CreateGroup("Cartagena Silver Fleet");
			Group_AddCharacter("Cartagena Silver Fleet", "CS_Spanish_Captain1");
			Group_AddCharacter("Cartagena Silver Fleet", "CS_Spanish_Captain2");
			Group_AddCharacter("Cartagena Silver Fleet", "CS_Spanish_Captain3");
			Group_AddCharacter("Cartagena Silver Fleet", "CS_Spanish_Captain4");
			Group_SetGroupCommander("Cartagena Silver Fleet", "CS_Spanish_Captain1");
			Group_SetAddress("Cartagena Silver Fleet", "Colombia", "Quest_Ships","Quest_ship_11");
			Characters[GetCharacterIndex("CS_Spanish_Captain1")].recognized = true;
			Characters[GetCharacterIndex("CS_Spanish_Captain2")].recognized = true;
			Characters[GetCharacterIndex("CS_Spanish_Captain3")].recognized = true;
			Characters[GetCharacterIndex("CS_Spanish_Captain4")].recognized = true;
			Group_SetTaskAttack("Cartagena Silver Fleet",  PLAYER_GROUP, true);
			Group_LockTask("Cartagena Silver Fleet");

			Group_CreateGroup("Cartagena Silver Fleet2");
			Group_AddCharacter("Cartagena Silver Fleet2", "CS_Spanish_Captain5");
			Group_SetGroupCommander("Cartagena Silver Fleet2", "CS_Spanish_Captain5");
			Group_SetAddress("Cartagena Silver Fleet2", "Colombia", "Quest_Ships","Quest_ship_2");
			Characters[GetCharacterIndex("CS_Spanish_Captain5")].recognized = true;
			Group_SetPursuitGroup("Cartagena Silver Fleet2", PLAYER_GROUP);
			Group_SetTaskAttack("Cartagena Silver Fleet2",  PLAYER_GROUP, true);
			Group_LockTask("Cartagena Silver Fleet2");

			Characters[GetCharacterIndex("CS_Spanish_Captain1")].Ship.crew.morale = 85;
			Characters[GetCharacterIndex("CS_Spanish_Captain2")].Ship.crew.morale = 75;
			Characters[GetCharacterIndex("CS_Spanish_Captain3")].Ship.crew.morale = 75;
			Characters[GetCharacterIndex("CS_Spanish_Captain4")].Ship.crew.morale = 75;
			Characters[GetCharacterIndex("CS_Spanish_Captain5")].Ship.crew.morale = 75;

			sld = characterFromID("Cartagena Commander");
			sld.PlayerNation = PIRATE;
			sld.PlayerShip = GetCharacterShipModel(PChar);
		break;

		case "colombian_silver_escaped_to_sea":
			if(GetRMRelation(PChar, SPAIN) > REL_WAR) SetRMRelation(PChar, SPAIN, REL_WAR);
			CloseQuestHeader("colombian_silver");
			i = Group_FindGroup("Cartagena Silver Fleet");
			if (i >= 0) Group_DeleteGroupIndex(i);

			i = Group_FindGroup("Cartagena Silver Fleet2");
			if (i >= 0) Group_DeleteGroupIndex(i);
			for(i=1; i<=5; i++)
			{
				ChangeCharacterAddress(CharacterFromID("CS_Spanish_Captain"+i), "None", "");
			}
		break;

		case "colombian_silver_fight_byrom":	// Triggered by dialog with Meredith Byrom if he thinks you betrayed him
			NPChar = CharacterFromID("Meredith Byrom");
			SetCharacterRemovable(NPChar, true);
			if (IsOfficer(NPChar)) RemoveOfficersIndex(PChar, GetCharacterIndex("Meredith Byrom"));
			LAi_SetImmortal(NPChar, false);
			LAi_NoRebirthEnable(NPChar);
			LAi_SetActorType(NPChar);
			LAi_ActorAttack(NPChar, PChar, "");
			NPChar.location = "none";			
		break;
///////////////////////////////////////////////////////////////////////
// Colombian Silver - end
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
// Captain Murphy tribute
	// This music used here is by Flannery, originally for the game "Buccaneers" and included in "New Horizons"
	// with his permission.  Republishing or uploading these tracks is strictly prohibited.
///////////////////////////////////////////////////////////////////////
		case "Murphy_tribute_activate":
			ref tmpref; makeref(tmpref, Music_Alias);
			aref aSailingMusic;
			makearef(aSailingMusic, Music_Alias.music_day_sailing);
			n = GetAttributesNum(aSailingMusic);
			attr = "f" + (n+1);
			tmpref.music_day_sailing.(attr).name = "MUSIC\Final Salute.ogg";
			makearef(aSailingMusic, Music_Alias.music_night_sailing);
			n = GetAttributesNum(aSailingMusic);
			attr = "f" + (n+1);
			tmpref.music_night_sailing.(attr).name = "MUSIC\Final Salute.ogg";
			Locations[FindLocation("Turks_port")].reload.l18.label = "Captain Murphy's House";
			Locations[FindLocation("Capt_Murphy_house")].id.label = "Captain Murphy's House";
		break;
///////////////////////////////////////////////////////////////////////
// Captain Murphy tribute
///////////////////////////////////////////////////////////////////////

		PChar.questnotfound = true; // PB: Testing
	}
}

#event_handler("EventSeaToLocation", "EventSeaToLocation");
void EventSeaToLocation()
{
trace("EVENT: EventSeaToLocation triggered");
	string location = GetEventData();
	string group = GetEventData();
	string locator = GetEventData();
	string questname = GetEventData();
	bQuestDisableAllCommands = true;
//	DoReloadFromSeaToLocation(location, group, locator);
//	LAi_QuestDelay(questname, 0.1);
	DoQuestReloadToLocation(location, group, locator, questname);
//	Sea_DeckStartNow(GetMainCharacterIndex(), location);
}