//#include "DIALOGS\Smuggler_OnShore_dialog.h"
void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;	
	int shit;
	//float chance_get_caught = getCoastGuardEncounterChance();
	string questname = "smuggle&number="+Pchar.amount_smuggleruns; //Set a questname
	
	LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false); // ccc you can fight again
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча

// ccc Stormy Start: added "doublecross" and "buy" options >

		case "Finish_exit":
			AddPartyExpChar(pchar, SKILL_COMMERCE, 50*makeint(PChar.rank));
			AddPartyExpChar(pchar, SKILL_SNEAK, 10*makeint(PChar.rank));
		    PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, makeint(Pchar.quest.Contraband.sum));

			d.Text = DLG_TEXT[53];
			Link.l1 = DLG_TEXT[54];
			Link.l1.go = "Leave_goods";
			Link.l2 = DLG_TEXT[55];
			Link.l2.go = "Exit_betray";			
		break;

		case "No_ship_1":
			Dialog.snd = "voice\SMSH\SMSH004";
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "Exit";							
		break;



		case "Leave_goods":
			int total_smuggle = 0;
			int goods_index = FindFirstContrabandGoods(Pchar);
			if(goods_index != -1 && !CheckAttribute(Pchar,"quest.Contraband.Skip1")) 
			{
				total_smuggle = total_smuggle + GetSquadronGoods(Pchar,goods_index);
				RemoveCharacterGoods(Pchar, goods_index, GetSquadronGoods(Pchar, goods_index));
			}
			goods_index = FindNextContrabandGoods(Pchar);
			if(goods_index != -1 && !CheckAttribute(Pchar,"quest.Contraband.Skip2")) 
			{
				total_smuggle = total_smuggle + GetSquadronGoods(Pchar,goods_index);
				RemoveCharacterGoods(Pchar, goods_index, GetSquadronGoods(Pchar, goods_index));
			}
			goods_index = FindNextContrabandGoods(Pchar);
			if(goods_index != -1 && !CheckAttribute(Pchar,"quest.Contraband.Skip3")) 
			{
				total_smuggle = total_smuggle + GetSquadronGoods(Pchar,goods_index);
				RemoveCharacterGoods(Pchar, goods_index, GetSquadronGoods(Pchar, goods_index));
			}
			goods_index = FindNextContrabandGoods(Pchar);
			if(goods_index != -1 && !CheckAttribute(Pchar,"quest.Contraband.Skip4")) 
			{
				total_smuggle = total_smuggle + GetSquadronGoods(Pchar,goods_index);
				RemoveCharacterGoods(Pchar, goods_index, GetSquadronGoods(Pchar, goods_index));
			}

			// ccc AddMoneyToCharacter(Pchar, makeint(Pchar.quest.Contraband.sum));
			addIslandSmugglingAmount(&Islands[GetCharacterCurrentIsland(Pchar)], total_smuggle);
			addPlayerSmugglingAmount(pchar, total_smuggle);
			ChangeSmugglerLiking(pchar, makeint(round(sqrt(total_smuggle)/10))); //Add liking
			d.Text = DLG_TEXT[56];
			Link.l1 = DLG_TEXT[57];
			Link.l1.go = "Exit_Complete";
			Link.l2 = DLG_TEXT[58];
			Link.l2.go = "Buy";
		break;


		case "Buy":
			d.Text = DLG_TEXT[59];
			Link.l1 = DLG_TEXT[60];
			Link.l1.go = "Exit_buy";
			Link.l2 = DLG_TEXT[61];
			Link.l2.go = "Exit_Complete";				
		break;

		case "Exit_buy":
			//Levis coastguard will always try to get you -->
			AddQuestRecord(questname, 5);
			AddDialogExitQuest("Made First Smuggling Report");
			/*if(Rand(100)<=chance_get_caught)
			{
				if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"Contraband transfer was interrupted by Coastal Guards"));
				AddDialogExitQuest("Rand_ContrabandInterruption");
			}
			else
			{
				CloseQuestHeader(questname);
			}*/
			//Coastguard will always try to get you
			AddCharacterGoods(pchar, GOOD_PLANKS, makeint(10 + rand(30)) );
			AddCharacterGoods(pchar, GOOD_SAILCLOTH, makeint(5 + rand(30)) );
			AddCharacterGoods(pchar, GOOD_RUM, makeint(5 + rand(30)) );
			AddCharacterGoods(pchar, GOOD_WHEAT, makeint(5 + rand(30)) );
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, -1000 );

			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();

			DeleteAttribute(Pchar, "quest.Contraband.active");
			DeleteAttribute(Pchar, "quest.Contraband.counter");
			DeleteAttribute(Pchar, "quest.Contraband.price1");
			DeleteAttribute(Pchar, "quest.Contraband.price2");
			DeleteAttribute(Pchar, "quest.Contraband.price3");
			DeleteAttribute(Pchar, "quest.Contraband.price4");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX1");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX2");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX3");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX4");
			DeleteAttribute(Pchar, "quest.Contraband.sum");
			DeleteAttribute(Pchar, "quest.Contraband.Skip1");
			DeleteAttribute(Pchar, "quest.Contraband.Skip2");
			DeleteAttribute(Pchar, "quest.Contraband.Skip3");
			DeleteAttribute(Pchar, "quest.Contraband.Skip4");

			Pchar.quest.Rand_Smuggling.over = "yes";
			RemoveSmugglersFromShore();
		break;
// ccc Stormy Start <-


		case "Exit_fight":
			//Levis coastguard will always try to get you -->
			AddQuestRecord(questname, 7);
			/*if(Rand(100)<=chance_get_caught)
			{
				if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"Contraband transfer was interrupted by Coastal Guards"));
				AddDialogExitQuest("Rand_ContrabandInterruption");
			}
			else
			{
				CloseQuestHeader(questname);
			}*/
			//Coastguard will always try to get you.
			ChangeSmugglerLiking(pchar, -20); //Add liking
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();

			DeleteAttribute(Pchar, "quest.Contraband.active");
			DeleteAttribute(Pchar, "quest.Contraband.counter");
			DeleteAttribute(Pchar, "quest.Contraband.price1");
			DeleteAttribute(Pchar, "quest.Contraband.price2");
			DeleteAttribute(Pchar, "quest.Contraband.price3");
			DeleteAttribute(Pchar, "quest.Contraband.price4");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX1");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX2");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX3");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX4");
			DeleteAttribute(Pchar, "quest.Contraband.sum");
			DeleteAttribute(Pchar, "quest.Contraband.Skip1");
			DeleteAttribute(Pchar, "quest.Contraband.Skip2");
			DeleteAttribute(Pchar, "quest.Contraband.Skip3");
			DeleteAttribute(Pchar, "quest.Contraband.Skip4");

			Pchar.quest.Rand_Smuggling.over = "yes";
			RemoveSmugglersFromShore();

			LAi_group_FightGroups(LAI_GROUP_PLAYER, "Smugglers", true);
		break;
		
		case "Exit_betray":
			//Levis coastguard will always try to get you -->
			AddQuestRecord(questname, 9);
			/*if(Rand(80)<=chance_get_caught) //If you betray them there is a larger chance the coastguard finds you
			{
				if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"Contraband transfer was interrupted by Coastal Guards"));
				AddDialogExitQuest("Rand_ContrabandInterruption");
			}
			else
			{
				CloseQuestHeader(questname);
			}*/
			//Coastguard will always try to get you.
			ChangeSmugglerLiking(pchar, -35); //Add liking
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();

			DeleteAttribute(Pchar, "quest.Contraband.active");
			DeleteAttribute(Pchar, "quest.Contraband.counter");
			DeleteAttribute(Pchar, "quest.Contraband.price1");
			DeleteAttribute(Pchar, "quest.Contraband.price2");
			DeleteAttribute(Pchar, "quest.Contraband.price3");
			DeleteAttribute(Pchar, "quest.Contraband.price4");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX1");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX2");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX3");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX4");
			DeleteAttribute(Pchar, "quest.Contraband.sum");
			DeleteAttribute(Pchar, "quest.Contraband.Skip1");
			DeleteAttribute(Pchar, "quest.Contraband.Skip2");
			DeleteAttribute(Pchar, "quest.Contraband.Skip3");
			DeleteAttribute(Pchar, "quest.Contraband.Skip4");

			Pchar.quest.Rand_Smuggling.over = "yes";
			RemoveSmugglersFromShore();

			LAi_group_FightGroups(LAI_GROUP_PLAYER, "Smugglers", true);
		break;

		case "Exit_Cancel":
			//Levis coastguard will always try to get you -->
			AddQuestRecord(questname, 8);
			/*if(Rand(150)<=chance_get_caught) //If you cancel there is a higher chance they wont find you.
			{
				if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"Contraband transfer was interrupted by Coastal Guards"));
				AddDialogExitQuest("Rand_ContrabandInterruption");
			}
			else
			{
				CloseQuestHeader(questname);
			}*/
			//Coastguard will always try to get you.
			ChangeSmugglerLiking(pchar, -5); //Add liking
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();

			DeleteAttribute(Pchar, "quest.Contraband.active");
			DeleteAttribute(Pchar, "quest.Contraband.counter");
			DeleteAttribute(Pchar, "quest.Contraband.price1");
			DeleteAttribute(Pchar, "quest.Contraband.price2");
			DeleteAttribute(Pchar, "quest.Contraband.price3");
			DeleteAttribute(Pchar, "quest.Contraband.price4");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX1");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX2");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX3");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX4");
			DeleteAttribute(Pchar, "quest.Contraband.sum");
			DeleteAttribute(Pchar, "quest.Contraband.Skip1");
			DeleteAttribute(Pchar, "quest.Contraband.Skip2");
			DeleteAttribute(Pchar, "quest.Contraband.Skip3");
			DeleteAttribute(Pchar, "quest.Contraband.Skip4");

			Pchar.quest.Rand_Smuggling.over = "yes";
			RemoveSmugglersFromShore();
		break;
		
		case "Exit_Complete":
			//Levis coastguard will always try to get you -->
			AddQuestRecord(questname, 5);
			/*if(Rand(100)<=chance_get_caught)
			{
				if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"Contraband transfer was interrupted by Coastal Guards"));
				AddDialogExitQuest("Rand_ContrabandInterruption");
			}
			else
			{
				CloseQuestHeader(questname);
			}*/
			//Coastguard will always try to get you.
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();

			DeleteAttribute(Pchar, "quest.Contraband.active");
			DeleteAttribute(Pchar, "quest.Contraband.counter");
			DeleteAttribute(Pchar, "quest.Contraband.price1");
			DeleteAttribute(Pchar, "quest.Contraband.price2");
			DeleteAttribute(Pchar, "quest.Contraband.price3");
			DeleteAttribute(Pchar, "quest.Contraband.price4");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX1");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX2");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX3");
			DeleteAttribute(Pchar, "quest.Contraband.goodsIDX4");
			DeleteAttribute(Pchar, "quest.Contraband.sum");
			DeleteAttribute(Pchar, "quest.Contraband.Skip1");
			DeleteAttribute(Pchar, "quest.Contraband.Skip2");
			DeleteAttribute(Pchar, "quest.Contraband.Skip3");
			DeleteAttribute(Pchar, "quest.Contraband.Skip4");

			Pchar.quest.Rand_Smuggling.over = "yes";
			RemoveSmugglersFromShore();
		break;
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "First time":	
			Diag.TempNode = "first time";
			int paper_caught_chance = -1;
			if(CheckAttribute(PChar,"quest.smuggling_guild.governor_quest.usedpaper"))
			{
				paper_caught_chance = makeint(80-(CalcCharacterSkill(PChar,SKILL_SNEAK)*5));
			}
			if(paper_caught_chance >= rand(100))
			{
				d.Text = DLG_TEXT[66];
				Link.l1 = DLG_TEXT[67];
				Link.l1.go = "Exit_fight";
			}
			else
			{
				if(paper_caught_chance > 1) AddPartyExpChar(pchar, "Sneak", 25);
				if(CheckAttribute(PChar, "quest.Contraband.active"))
				{
					Dialog.snd = "voice\SMSH\SMSH001";
					d.Text = DLG_TEXT[0];
					Link.l1 = PcharPhrase(DLG_TEXT[1], DLG_TEXT[2]);
					if(Pchar.Location == Pchar.location.from_sea)
					{
						Link.l1.go = "Exchange";
					}
					else
					{
						Link.l1.go = "No_Ship";
					}
				}
				else
				{
					Dialog.snd = "voice\SMSH\SMSH002";
					d.Text = DLG_TEXT[3];
					Link.l1 = PcharPhrase(DLG_TEXT[4], DLG_TEXT[5]);
					Link.l1.go = "Exit_fight";
					Link.l2 = DLG_TEXT[6];
					Link.l2.go = "Exit";
				}
			}
		break;

		case "No_Ship":
			Dialog.snd = "voice\SMSH\SMSH003";
			d.Text = DLG_TEXT[7];
			Link.l1 = PcharPhrase(DLG_TEXT[8], DLG_TEXT[9]);
			Link.l1.go = "No_ship_1";
			Link.l2 = DLG_TEXT[10];
			Link.l2.go = "Cancellation";				
		break;

		case "No_ship_1":
			Dialog.snd = "voice\SMSH\SMSH004";
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "Exit";							
		break;

		case "Cancellation":
			Dialog.snd = "voice\SMSH\SMSH005";
			d.Text = DLG_TEXT[13];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "Cancellation_1";				
		break;

		case "Cancellation_1":
			if( makeint(Pchar.rank) <= 3 || CalcCharacterSkill(PChar,SKILL_FENCING) <= 5 || CalcCharacterSkill(PChar,SKILL_LEADERSHIP) <= 5 ) // NK
			{
				if(Rand(2) == 1) 
				{
					Dialog.snd = "voice\SMSH\SMSH006";
					d.Text = DLG_TEXT[15];
					Link.l1 = DLG_TEXT[16];
					Link.l1.go = "Exit_fight";			
				}
				else
				{
					Dialog.snd = "voice\SMSH\SMSH007";
					d.Text = DLG_TEXT[17];
					Link.l1 = DLG_TEXT[18];
					Link.l1.go = "Exit_cancel";			
				}
			}	
			else
			{
				Dialog.snd = "voice\SMSH\SMSH008";
				d.Text = DLG_TEXT[19];
				Link.l1 = DLG_TEXT[20];
				Link.l1.go = "Exit_cancel";			
			}	
		break;

		case "Exchange":
			Pchar.quest.Contraband.Counter = 0;
			//Levis add smuggle perk
			float price_multiplier = 1.1;
			if(CheckCharacterPerk(Pchar,"AdvanceSmuggling"))
			{
				price_multiplier = price_multiplier*1.15;
			}
			//End edit
			//Moved coastguard caught to exit statements.
			//Levis let liking influence price -->
			price_multiplier = price_multiplier*(1+((CheckSmugglerLiking(Pchar)-50)*SMUGGLING_PRICE_INC_PER_LIKE));
			//<-- Levis let liking influence price
			shit = FindFirstContrabandGoods(Pchar);
			if(shit != -1) 
			{
				Pchar.quest.Contraband.goodsIDX1 = shit;
				Pchar.quest.Contraband.price1 = makeint(GetCurrentIslandGoodsPrice(shit)*price_multiplier); //changed 1.5 to price_multiplier -Levis
				Pchar.quest.Contraband.Counter = makeint(Pchar.quest.Contraband.Counter) + 1;
				if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"FIRST CONTRABAND GOOD SELECTED TO TRADE IS:") + " " + goods[sti(Pchar.quest.Contraband.goodsIDX1)].name);
				if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"FIRST CONTRABAND GOOD PRICE IS:") + " " + Pchar.quest.Contraband.price1);
				if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"CONTRABAND ONBOARD COUNTER HAS VALUE:") + " " + Pchar.quest.Contraband.Counter); 
			}
			shit = FindNextContrabandGoods(Pchar);
			if(shit != -1) 
			{
				Pchar.quest.Contraband.goodsIDX2 = shit;
				Pchar.quest.Contraband.price2 = makeint(GetCurrentIslandGoodsPrice(shit)*price_multiplier); //changed 1.5 to price_multiplier -Levis
				Pchar.quest.Contraband.Counter = makeint(Pchar.quest.Contraband.Counter) + 1;
				if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"NEXT CONTRABAND GOOD SELECTED TO TRADE IS:") + " " + goods[sti(Pchar.quest.Contraband.goodsIDX1)].name);
				if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"NEXT CONTRABAND GOOD PRICE IS:") + " " + Pchar.quest.Contraband.price1);
				if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"CONTRABAND ONBOARD COUNTER HAS VALUE:") + " " + Pchar.quest.Contraband.Counter); 
			}
			shit = FindNextContrabandGoods(Pchar);
			if(shit != -1) 
			{
				Pchar.quest.Contraband.goodsIDX3 = shit;
				Pchar.quest.Contraband.price3 = makeint(GetCurrentIslandGoodsPrice(shit)*price_multiplier); //changed 1.5 to price_multiplier -Levis
				Pchar.quest.Contraband.Counter = makeint(Pchar.quest.Contraband.Counter) + 1;		
				if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"NEXT CONTRABAND GOOD SELECTED TO TRADE IS:") + " " + goods[sti(Pchar.quest.Contraband.goodsIDX1)].name);
				if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"NEXT CONTRABAND GOOD PRICE IS:") + " " + Pchar.quest.Contraband.price1);
				if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"CONTRABAND ONBOARD COUNTER HAS VALUE:") + " " + Pchar.quest.Contraband.Counter); 
			}
			shit = FindNextContrabandGoods(Pchar);
			if(shit != -1) 
			{
				Pchar.quest.Contraband.goodsIDX4 = shit;
				Pchar.quest.Contraband.price4 = makeint(GetCurrentIslandGoodsPrice(shit)*price_multiplier); //changed 1.5 to price_multiplier -Levis
				Pchar.quest.Contraband.Counter = makeint(Pchar.quest.Contraband.Counter) + 1;
				if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"NEXT CONTRABAND GOOD SELECTED TO TRADE IS:") + " " + goods[sti(Pchar.quest.Contraband.goodsIDX1)].name);
				if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"NEXT CONTRABAND GOOD PRICE IS:") + " " + Pchar.quest.Contraband.price1);
				if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"CONTRABAND ONBOARD COUNTER HAS VALUE:") + " " + Pchar.quest.Contraband.Counter); 
			}
			if(FindFirstContrabandGoods(Pchar) != -1)
			{
				if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"QUANTITY OF FIRST CONTRABAND GOOD ONBOARD:") + " " + GetCargoGoods(Pchar,makeint(Pchar.quest.Contraband.goodsIDX1)));
				if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"INDEX OF FIRST CONTRABAND IS:") + " " + Pchar.quest.Contraband.goodsIDX1);
				Pchar.quest.Contraband.Sum = makeint(Pchar.quest.Contraband.price1)*GetSquadronGoods(Pchar,makeint(Pchar.quest.Contraband.goodsIDX1));
				Dialog.snd = "voice\SMSH\SMSH009";
				d.Text = DLG_TEXT[21] + GetSquadronGoods(Pchar,FindFirstContrabandGoods(Pchar)) + " " + XI_ConvertString(Goods[makeint(Pchar.quest.Contraband.goodsIDX1)].name) + DLG_TEXT[22] + Pchar.quest.Contraband.price1 + DLG_TEXT[23] + pchar.quest.contraband.sum + DLG_TEXT[24];
				Link.l1 = DLG_TEXT[25];
				setContrabandCurPrice(&Islands[GetCharacterCurrentIsland(Pchar)], sti(Pchar.quest.Contraband.goodsIDX1), sti(Pchar.quest.Contraband.price1)) //Levis Traderbook Addon
				Pchar.quest.Contraband.Counter = makeint(Pchar.quest.Contraband.Counter) - 1; 
				if(Pchar.quest.Contraband.Counter != "0")
				{
					if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"THERE ARE SOME MORE CONTRABAND GOODS"));
					Link.l1.go = "SecondGoods";
					Link.l2 = DLG_TEXT[62];
					Link.l2.go = "Skip1";					
				}
				else
				{
					if(DEBUG_SMUGGLING>2) trace(LanguageConvertString(tmpLangFileID,"ONLY ONE CONTRABAND GOOD IS AVAILABLE"));
					Link.l1.go = "Finish";
				}
				Link.l3 = DLG_TEXT[26];
				Link.l3.go = "Cancellation";
			}
			else
			{
				Dialog.snd = "voice\SMSH\SMSH010";
				d.Text = DLG_TEXT[27];
				Link.l1 = DLG_TEXT[28];
				Link.l1.go = "NoGoods";				
			}
			
		break;

		case "SecondGoods":
			Dialog.snd = "voice\SMSH\SMSH012";
			Pchar.quest.Contraband.Sum = makeint(Pchar.quest.Contraband.Sum) + makeint(Pchar.quest.Contraband.price2)*GetSquadronGoods(Pchar,makeint(Pchar.quest.Contraband.goodsIDX2));
			d.Text = DLG_TEXT[29] + GetSquadronGoods(Pchar, FindNextContrabandGoods(Pchar)) + " " + XI_ConvertString(Goods[makeint(Pchar.quest.Contraband.goodsIDX2)].name) + DLG_TEXT[30] + Pchar.quest.Contraband.price2 + DLG_TEXT[31] + pchar.quest.contraband.sum + DLG_TEXT[32];
			Link.l1 = DLG_TEXT[33];
			setContrabandCurPrice(&Islands[GetCharacterCurrentIsland(Pchar)], sti(Pchar.quest.Contraband.goodsIDX2), sti(Pchar.quest.Contraband.price2)) //Levis Traderbook Addon
			Pchar.quest.Contraband.Counter = makeint(Pchar.quest.Contraband.Counter) - 1; 
			if(Pchar.quest.Contraband.Counter != "0")
			{
				Link.l1.go = "ThirdGoods";				
			}
			else
			{
				Link.l1.go = "Finish";
			}
			Link.l2 = DLG_TEXT[62];
			Link.l2.go = "Skip2";
			Link.l3 = DLG_TEXT[34];
			Link.l3.go = "Cancellation";
		break;

		case "ThirdGoods":
			Dialog.snd = "voice\SMSH\SMSH013";
			Pchar.quest.Contraband.Sum = makeint(Pchar.quest.Contraband.Sum) + makeint(Pchar.quest.Contraband.price3)*GetSquadronGoods(Pchar,makeint(Pchar.quest.Contraband.goodsIDX3));
			d.Text = DLG_TEXT[35] + GetSquadronGoods(Pchar,FindNextContrabandGoods(Pchar)) + " " + XI_ConvertString(Goods[makeint(Pchar.quest.Contraband.goodsIDX3)].name) + DLG_TEXT[36] + Pchar.quest.Contraband.price3 + DLG_TEXT[37] + pchar.quest.contraband.sum + DLG_TEXT[38];
			Link.l1 = DLG_TEXT[39];
			setContrabandCurPrice(&Islands[GetCharacterCurrentIsland(Pchar)], sti(Pchar.quest.Contraband.goodsIDX3), sti(Pchar.quest.Contraband.price3)) //Levis Traderbook Addon
			Pchar.quest.Contraband.Counter = makeint(Pchar.quest.Contraband.Counter) - 1; 
			if(Pchar.quest.Contraband.Counter != "0")
			{
				Link.l1.go = "FourthGoods";				
			}
			else
			{
				Link.l1.go = "Finish";
			}
			Link.l2 = DLG_TEXT[62];
			Link.l2.go = "Skip3";
			Link.l3 = DLG_TEXT[40];
			Link.l3.go = "Cancellation";
		break;

		case "FourthGoods":
			Dialog.snd = "voice\SMSH\SMSH014";
			Pchar.quest.Contraband.Sum = makeint(Pchar.quest.Contraband.Sum) + makeint(Pchar.quest.Contraband.price4)*GetSquadronGoods(Pchar,makeint(Pchar.quest.Contraband.goodsIDX4));
			Pchar.quest.Contraband.Counter = "0";
			d.Text = DLG_TEXT[41] + GetSquadronGoods(Pchar,FindNextContrabandGoods(Pchar)) + " " + XI_ConvertString(Goods[makeint(Pchar.quest.Contraband.goodsIDX4)].name) + DLG_TEXT[42] + Pchar.quest.Contraband.price4 + DLG_TEXT[43] + pchar.quest.contraband.sum + DLG_TEXT[44];
			setContrabandCurPrice(&Islands[GetCharacterCurrentIsland(Pchar)], sti(Pchar.quest.Contraband.goodsIDX4), sti(Pchar.quest.Contraband.price4)) //Levis Traderbook Addon
			Link.l1 = DLG_TEXT[45];
			Link.l1.go = "Finish";
			Link.l2 = DLG_TEXT[62];
			Link.l2.go = "Skip4";
			Link.l3 = DLG_TEXT[46];
			Link.l3.go = "Cancellation";
		break;
		
		//Added by Levis -->
		case "Skip1":
			Pchar.quest.Contraband.Sum = makeint(Pchar.quest.Contraband.Sum) - makeint(Pchar.quest.Contraband.price1)*GetSquadronGoods(Pchar,makeint(Pchar.quest.Contraband.goodsIDX1));
			Pchar.quest.Contraband.Skip1 = TRUE;
			if(Pchar.quest.Contraband.Counter != "0")
			{
				d.Text = DLG_TEXT[63];
				Link.l1 = DLG_TEXT[64];
				Link.l1.go = "SecondGoods";				
			}
			else
			{
				if(sti(Pchar.quest.Contraband.Sum) > 0)
				{
					d.Text = DLG_TEXT[63];
					Link.l1 = DLG_TEXT[64];
					Link.l1.go = "Finish";
				}
				else
				{
					d.Text = DLG_TEXT[65];
					Link.l1 = DLG_TEXT[64];
					Link.l1.go = "Cancellation";
				}
			}
		break;
		
		case "Skip2":
			Pchar.quest.Contraband.Sum = makeint(Pchar.quest.Contraband.Sum) - makeint(Pchar.quest.Contraband.price2)*GetSquadronGoods(Pchar,makeint(Pchar.quest.Contraband.goodsIDX2));
			Pchar.quest.Contraband.Skip2 = TRUE;
			if(Pchar.quest.Contraband.Counter != "0")
			{
				d.Text = DLG_TEXT[63];
				Link.l1 = DLG_TEXT[64];
				Link.l1.go = "ThirdGoods";				
			}
			else
			{
				if(sti(Pchar.quest.Contraband.Sum) > 0)
				{
					d.Text = DLG_TEXT[63];
					Link.l1 = DLG_TEXT[64];
					Link.l1.go = "Finish";
				}
				else
				{
					d.Text = DLG_TEXT[65];
					Link.l1 = DLG_TEXT[64];
					Link.l1.go = "Cancellation";
				}
			}
		break;
		
		case "Skip3":
			Pchar.quest.Contraband.Sum = makeint(Pchar.quest.Contraband.Sum) - makeint(Pchar.quest.Contraband.price3)*GetSquadronGoods(Pchar,makeint(Pchar.quest.Contraband.goodsIDX3));
			Pchar.quest.Contraband.Skip3 = TRUE;
			if(Pchar.quest.Contraband.Counter != "0")
			{
				d.Text = DLG_TEXT[63];
				Link.l1 = DLG_TEXT[64];
				Link.l1.go = "FourthGoods";				
			}
			else
			{
				if(sti(Pchar.quest.Contraband.Sum) > 0)
				{
					d.Text = DLG_TEXT[63];
					Link.l1 = DLG_TEXT[64];
					Link.l1.go = "Finish";
				}
				else
				{
					d.Text = DLG_TEXT[65];
					Link.l1 = DLG_TEXT[64];
					Link.l1.go = "Cancellation";
				}
			}
		break;
		
		case "Skip4":
			Pchar.quest.Contraband.Sum = makeint(Pchar.quest.Contraband.Sum) - makeint(Pchar.quest.Contraband.price4)*GetSquadronGoods(Pchar,makeint(Pchar.quest.Contraband.goodsIDX4));
			Pchar.quest.Contraband.Skip4 = TRUE;
			if(sti(Pchar.quest.Contraband.Sum) > 0)
			{
				d.Text = DLG_TEXT[63];
				Link.l1 = DLG_TEXT[64];
				Link.l1.go = "Finish";
			}
			else
			{
				d.Text = DLG_TEXT[65];
				Link.l1 = DLG_TEXT[64];
				Link.l1.go = "Cancellation";
			}
		break;
		//Added by Levis <--
		
		case "NoGoods":
			Dialog.snd = "voice\SMSH\SMSH015";
			d.Text = DLG_TEXT[47];
			Link.l1 = DLG_TEXT[48];
			Link.l1.go = "Exit_Cancel";				
		break; 
			
		case "Finish":		
			Dialog.snd = "voice\SMSH\SMSH016";
			d.Text = DLG_TEXT[49] + Pchar.quest.Contraband.Sum + DLG_TEXT[50];
			Link.l1 = DLG_TEXT[51];
			Link.l1.go = "Finish_exit";
			Link.l2 = DLG_TEXT[52];
			Link.l2.go = "Cancellation";
		break;

	}
	LanguageCloseFile(tmpLangFileID);
}