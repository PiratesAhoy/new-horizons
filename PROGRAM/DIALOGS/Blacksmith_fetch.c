void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	string iDay, iMonth, cargoid, questbookname;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;
	ref ctown = GetCurrentTown();
	
	
	switch(Dialog.CurrentNode)
	{
		//Fetch Quest -->
		case "fetch quest":
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			Preprocessor_Add("gender", GetCharacterAddressForm(PChar, ADDR_GENDER, false, false)); // DeathDaisy
			d.Text = DLG_TEXT[1] + NPChar.fetch_quest.amount + " " + XI_ConvertString(Goods[sti(NPChar.fetch_quest.good)].name)+ DLG_TEXT[2] + NPChar.fetch_quest.money + DLG_TEXT[3]  + NPChar.fetch_quest.expire;
			Link.l1 = DLG_TEXT[4];
			Link.l1.go = "agree fetch";
			Link.l2 = DLG_TEXT[5];
			Link.l2.go = "decline fetch";
		break;
		
		case "fetch quest more runs":
			d.Text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "save goods for me";
			Link.l2 = DLG_TEXT[16];
			Link.l2.go = "exit";
		break;
		
		case "save goods for me":
			RemoveCharacterGoods(PChar,sti(NPChar.fetch_quest.good),sti(NPChar.temp_amount));
			NPChar.fetch_quest.already_received = NPChar.temp_amount;
			DeleteAttribute(NPChar,"temp_amount");
			Diag.CurrentNode = Diag.TempNode;
			questbookname = "fetch&number="+NPChar.fetch_quest.cargoid+NPChar.index; //Set a questname
			AddQuestRecord(questbookname, 2);
			DialogExit();
		break;
		
		case "fetch quest complete":
			//succes
			d.Text = DLG_TEXT[13];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "exit";
			//reward etc
			AddMoneyToCharacter(PChar,sti(NPChar.fetch_quest.money));
			ChangeCharacterReputation(PChar, 2);
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Commerce", 100*makeint(PChar.rank)); }
			else { AddPartyExp(pchar, 100*makeint(PChar.rank)); }
			RemoveCharacterGoods(PChar,sti(NPChar.fetch_quest.good),sti(NPChar.fetch_quest.amount));
			//Levis Unlock Perk
			//if(CheckCharacterPerkLocked("BasicCommerce")) UnlockPerkCharacter("BasicCommerce");
			//Questbook
			questbookname = "fetch&number="+NPChar.fetch_quest.cargoid+NPChar.index; //Set a questname
			AddQuestRecord(questbookname, 3);
			CloseQuestHeader(questbookname);
			//Clean up stuff
			//removeCargoFromIsland(Islands[FindIsland(ctown.island)], NPChar.fetch_quest.cargoid); //For some stupid reason this doesnt work so have to do it manuall
			aref cargos; makearef(cargos,Islands[FindIsland(ctown.island)].cargos);
			DeleteAttribute(cargos,NPChar.fetch_quest.cargoid);
			DeleteAttribute(NPChar,"fetch_quest");
			DeleteAttribute(NPChar,"fetch_quest_active");
			if(!CheckAttribute(PChar,"fetchquestcompleted")) PChar.fetchquestcompleted = 0;
			PChar.fetchquestcompleted = sti(PChar.fetchquestcompleted) + 1;
			if(!CheckAttribute(PChar,"fetchquestcompleted_blacksmith")) PChar.fetchquestcompleted_blacksmith = 0;
			PChar.fetchquestcompleted_blacksmith = sti(PChar.fetchquestcompleted_blacksmith) + 1;
			PChar.quest.(questbookname).over = "yes"; // GR: cancel quest fail timer
		break;
		
		case "fetch quest failed":
			//to late
			d.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "exit";
			//Questbook
			questbookname = "fetch&number="+NPChar.fetch_quest.cargoid+NPChar.index; //Set a questname
			AddQuestRecord(questbookname, 4);
			CloseQuestHeader(questbookname);
			//Clean Up
			DeleteAttribute(NPChar,"fetch_quest");
			DeleteAttribute(NPChar,"fetch_quest_active");
			if(!CheckAttribute(PChar,"fetchquestfailed")) PChar.fetchquestfailed = 0;
			PChar.fetchquestfailed = sti(PChar.fetchquestfailed) + 1;
		break;
		
		case "decline fetch":
			Dialog.snd = "voice\ROMU\ROMU005";
			d.Text = DLG_TEXT[6] + NPChar.fetch_quest.expire;
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "exit";
		break;
		
		case "agree fetch":
			d.Text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "exit";
			if(!CheckAttribute(PChar,"fetchquestactive")) PChar.fetchquestactive = 0;
			/*WriteNewLogEntry(("Helping the blacksmith of "+ctown.name), ("The blacksmith of "+ctown.name+" asked me to get "+NPChar.fetch_quest.amount+" "+ Goods[sti(NPChar.fetch_quest.good)].name +" from somewhere and deliver it back to him to get "+NPChar.fetch_quest.money+" gold coins. But I have to deliver it before "+NPChar.fetch_quest.expire+" or i will receive nothing."), "Personal", true);
			Logit("Ships Log Updated");
			AddMsgToCharacter(PChar,MSGICON_LOGBOOK);
			PlaySound("INTERFACE\notebook.wav");*/
			//Questbook
			Preprocessor_AddQuestData("town",ctown.name);
			Preprocessor_AddQuestData("type",XI_ConvertString("blacksmith"));
			Preprocessor_AddQuestData("amount",sti(NPChar.fetch_quest.amount));
			Preprocessor_AddQuestData("good",XI_ConvertString(Goods[sti(NPChar.fetch_quest.good)].name));
			Preprocessor_AddQuestData("money",sti(NPChar.fetch_quest.money));
			Preprocessor_AddQuestData("pronoun2",XI_ConvertString(GetMyPronounObj(NPChar)));
			Preprocessor_AddQuestData("date",NPChar.fetch_quest.expire);
			questbookname = "fetch&number="+NPChar.fetch_quest.cargoid+NPChar.index; //Set a questname
			SetQuestHeader(questbookname);
			AddQuestRecord(questbookname, 1);
			Preprocessor_Remove("town");
			Preprocessor_Remove("type");
			Preprocessor_Remove("amount");
			Preprocessor_Remove("good");
			Preprocessor_Remove("money");
			Preprocessor_Remove("pronoun2");
			Preprocessor_Remove("date");
			PChar.fetchquestactive = sti(PChar.fetchquestactive) +1;
			NPChar.fetch_quest_active = TRUE;
			setFetchQuestExpireQuest(Islands[FindIsland(ctown.island)], NPChar.fetch_quest.cargoid, questbookname, NPChar.id); //Levis: Add expire quest
		break;
		
		case "SelectFix":
			cargoid = getFetchQuestCargo("blacksmith",ctown);
			if(cargoid != "")
			{
				if(!CheckAttribute(NPChar,"fetch_quest_active"))
				{
					//There is a fetchquest cargo set for this character
					Link.l2 = DLG_TEXT[0];
					Link.l2.go = "fetch quest";
					if(!CheckAttribute(NPChar,"fetch_quest")) 
					{
						NPChar.fetch_quest.cargoid = cargoid;
						NPChar.fetch_quest.amount = getCargoAmount(Islands[FindIsland(ctown.island)], cargoid);
						NPChar.fetch_quest.good = getCargoGood(Islands[FindIsland(ctown.island)], cargoid);
						NPChar.fetch_quest.expire = getFetchQuestExpireDate(Islands[FindIsland(ctown.island)], cargoid);
						NPChar.fetch_quest.money = getFetchQuestReward(sti(NPChar.fetch_quest.amount), sti(NPChar.fetch_quest.good), ctown);
						//SetCharacterGoods(PChar,sti(NPChar.fetch_quest.good),NPChar.fetch_quest.amount); //Debug Code
					}
				}
				else
				{
					int amount = GetCargoGoods(PChar, sti(NPChar.fetch_quest.good));
					if(CheckAttribute(NPChar,"fetch_quest.already_received")) amount += sti(NPChar.fetch_quest.already_received); //more then 1 run
					for(int i=1; i<COMPANION_MAX; i++)
					{
						if(GetCompanionIndex(Pchar, i) != -1)
						{
							amount += GetCargoGoods(&Characters[getCompanionIndex(Pchar, i)], sti(NPChar.fetch_quest.good));
						}
					}
					if (amount >= sti(NPChar.fetch_quest.amount))
					{
						Link.l2 = DLG_TEXT[10];
						Link.l2.go = "fetch quest complete";
					}
					else
					{
						if(amount > 0)
						{
							NPChar.temp_amount = amount;
							Link.l2 = DLG_TEXT[14];
							Link.l2.go = "fetch quest more runs";
						}
					}
				}
			}
			else
			{
				if(CheckAttribute(NPChar,"fetch_quest_active"))
				{
					Link.l2 = DLG_TEXT[11];
					Link.l2.go = "fetch quest failed";
				}
			}
		break;
		//Fetch Quest <--
	}
}