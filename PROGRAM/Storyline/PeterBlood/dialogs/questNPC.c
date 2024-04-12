void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
    string sLocator, sTemp;
    int iTime, n, iChar;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{

		// ----------------------------------- Диалог первый - первая встреча
		case "Exit":
            NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

        case "Exit_Away":

            LAi_SetActorType(npchar);
            LAi_ActorGoToLocation(npchar, "reload", Pchar.questTemp.sLocator, "none", "", "", "", sti(Pchar.questTemp.iTime));
            NextDiag.CurrentNode = NextDiag.TempNode;
            DialogExit();
        break;

        case "Exit_RunAway":

            LAi_SetActorTypeNoGroup(npchar);
            LAi_ActorRunToLocation(npchar, "reload", Pchar.questTemp.sLocator, "none", "", "", "", sti(Pchar.questTemp.iTime));
            NextDiag.CurrentNode = NextDiag.TempNode;
            DialogExit();
        break;



        case "sfight":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
            LAi_group_Attack(NPChar, Pchar);

		break;

        case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
   	        LAi_SetWarriorTypeNoGroup(NPChar);
			LAi_group_Attack(NPChar, Pchar);
            AddDialogExitQuest("MainHeroFightModeOn");
			chrDisableReloadToLocation = false;
            LAi_CharacterPlaySound(npchar, "toArm");

		break;

        case "Qfight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
   	        LAi_SetWarriorType(NPChar);
            LAi_group_MoveCharacter(NPChar, "TmpEnemy");
			LAi_group_FightGroups("TmpEnemy", LAI_GROUP_PLAYER, true);
			LAi_group_FightGroups(GetNationNameByType(ENGLAND) + "_citizens", LAI_GROUP_PLAYER, true);
			AddDialogExitQuest("MainHeroFightModeOn");
			chrDisableReloadToLocation = true;
			//#20190120-03
			LAi_group_SetCheck("TmpEnemy", "OpenTheDoors");

		break;

		case "Finish":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			RestoreBridgetown();
			initMainCharacterItem();
            ref mc = GetMainCharacter();
            mc.Ship.Type = GenerateShip(SHIP_ARABELLA, true);
            mc.Ship.name=DLG_TEXT_QB[0];
            SetBaseShipData(mc);
            mc.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS32;
            SetCrewQuantityFull(mc);

            SetCharacterGoods(mc,GOOD_FOOD,2000);
        	SetCharacterGoods(mc,GOOD_BALLS,2000);//2000);
            SetCharacterGoods(mc,GOOD_GRAPES,300);//700);
            SetCharacterGoods(mc,GOOD_KNIPPELS,400);//700);
            SetCharacterGoods(mc,GOOD_BOMBS,2000);//1500);
            SetCharacterGoods(mc,GOOD_POWDER,2000);
            SetCharacterGoods(mc,GOOD_PLANKS,10);
            SetCharacterGoods(mc,GOOD_RUM,40);//600);
            SetCharacterGoods(mc,GOOD_WEAPON,2000);//2000);
            DoReloadCharacterToLocation(Pchar.HeroParam.Location, Pchar.HeroParam.Group, Pchar.HeroParam.Locator);
		break;

        case "Man_FackYou":
			dialog.text = LinkRandPhrase(DLG_TEXT_QB[1], DLG_TEXT_QB[2], DLG_TEXT_QB[3]);
			link.l1 = LinkRandPhrase(DLG_TEXT_QB[4], DLG_TEXT_QB[5], DLG_TEXT_QB[6]);
			link.l1.go = "Qfight";
		break;

        case "Draguns_0":
			dialog.text = LinkRandPhrase(DLG_TEXT_QB[7], DLG_TEXT_QB[8], DLG_TEXT_QB[9]);
			link.l1 = LinkRandPhrase(DLG_TEXT_QB[10], DLG_TEXT_QB[11], DLG_TEXT_QB[12]);
			link.l1.go = "Draguns_1";
 		     NextDiag.TempNode = "Draguns_0";
		break;

        case "Draguns_1":

            LAi_group_FightGroups("TmpEnemy", LAI_GROUP_PLAYER, true);
            NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

		break;

		case "First time":
        	dialog.text = DLG_TEXT_QB[13];
            link.l1 = "...";
            link.l1.go = "Exit";


            if (CheckAttribute(npchar, "CityType") && npchar.CityType == "soldier")
            {

                if(Pchar.questTemp.CapBloodLine.stat == "PrepareToEscape2_1")
                {
                    dialog.text = DLG_TEXT_QB[14];
					link.l1 = DLG_TEXT_QB[15];
					link.l1.go = "SQStep_0";
					Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape2_2";
				    break;
                }

               	if (GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY || ChangeCharacterNationReputation(pchar, sti(NPChar.nation), 0) <= -15)
                {

    				dialog.text = RandPhraseSimple(DLG_TEXT_QB[16], DLG_TEXT_QB[17]);
    				link.l1 = RandPhraseSimple(DLG_TEXT_QB[18], DLG_TEXT_QB[19]);
    				link.l1.go = "sfight";
    				break;
				}

        		switch (rand(5))
					{
						case 0: ////////////////////////////////////////
							dialog.text = DLG_TEXT_QB[20];
							link.l1 = DLG_TEXT_QB[21];
							link.l1.go = "exit";
						break;

						case 1:
							dialog.text = DLG_TEXT_QB[22];
							link.l1 = DLG_TEXT_QB[23];
							link.l1.go = "exit";
						break;

						case 2: ///////////////////////////////////////////
							dialog.text = DLG_TEXT_QB[24];
							link.l1 = DLG_TEXT_QB[25];
							link.l1.go = "exit";
						break;

						case 3:
							dialog.text = DLG_TEXT_QB[26];
							link.l1 = DLG_TEXT_QB[27];
							link.l1.go = "exit";
						break;

						case 4: ///////////////////////////////////////////
							dialog.text = DLG_TEXT_QB[28];
							link.l1 = DLG_TEXT_QB[29];
							link.l1.go = "exit";
						break;



						case 5: ////////////////////////////////////////////
							dialog.text = DLG_TEXT_QB[30];
							link.l1 = DLG_TEXT_QB[31];
							link.l1.go = "exit";
						break;


					}
    		}

    		if (CheckAttribute(npchar, "CityType") && npchar.CityType == "citizen")
    		{
            	dialog.text = TimeGreeting() + DLG_TEXT_QB[32];
        		link.l1 = DLG_TEXT_QB[33];
        		link.l1.go = "Exit";
        		if( Pchar.questTemp.CapBloodLine.stat == "WakerOffer")
        		{
                    link.l2 = RandPhraseSimple(DLG_TEXT_QB[34], DLG_TEXT_QB[35]);
                    link.l2.go = "Citizen_0";
                }
                if(CheckAttribute(Pchar, "questTemp.CapBloodLine.ShipForJack") && Pchar.questTemp.CapBloodLine.ShipForJack == true)
                {
                    Link.l2 = RandPhraseSimple(DLG_TEXT_QB[36], DLG_TEXT_QB[37]);
    				Link.l2.go = "Citizen_1";
                }
    		}

    		if (CheckAttribute(npchar, "CityType") && npchar.CityType == "citizen" && npchar.location.group == "merchant")
    		{
                if(findsubstr(Pchar.questTemp.CapBloodLine.stat, "PrepareToEscape" , 0) != -1)
                {
                        if (CheckAttribute(npchar, "quest.bGoodMerch") && sti(Pchar.reputation) >= 55)
                        {
                            dialog.text = DLG_TEXT_QB[38]+NPCharSexPhrase(NPChar, " ", DLG_TEXT_QB[39])+DLG_TEXT_QB[40];
                            link.l1 = DLG_TEXT_QB[41]+NPCharSexPhrase(NPChar, DLG_TEXT_QB[42], DLG_TEXT_QB[43])+DLG_TEXT_QB[44];
                            link.l1.go = "Merchant_0";
                            break;
                        }
                }
                if (CheckAttribute(npchar, "quest.bGoodMerch"))
                {
                    dialog.text = TimeGreeting() + DLG_TEXT_QB[45];
                    link.l1 = DLG_TEXT_QB[46];
                }
                else
                {
                    dialog.text = DLG_TEXT_QB[47];
                    link.l1 = DLG_TEXT_QB[48];
                }
        		link.l1.go = "Exit";
    		}
    		//Рабы на плантациях - постоянный диалог
    		if (CheckAttribute(npchar, "CityType") && npchar.CityType == "citizen" && findsubstr(npchar.id, "Slave_" , 0) != -1)
    		{
			    dialog.text = RandPhraseSimple(RandPhraseSimple(DLG_TEXT_QB[49], DLG_TEXT_QB[50]), RandPhraseSimple(DLG_TEXT_QB[51], DLG_TEXT_QB[52]));
				link.l1 = RandPhraseSimple(DLG_TEXT_QB[53], DLG_TEXT_QB[54]);
				link.l1.go = "exit";

    		}

    		if (npchar.id == "Bridgetown_Poorman")
    		{
            	dialog.text = DLG_TEXT_QB[55];
        		link.l1 = DLG_TEXT_QB[56];
        		link.l1.go = "Exit";
    		}

    		if (npchar.id == "QuestCitiz_Bridgetown")
    		{
            	dialog.text = TimeGreeting() + DLG_TEXT_QB[57];
        		link.l1 = DLG_TEXT_QB[58];
        		link.l1.go = "Exit";
    		}

    		if (npchar.id == "SolderTakeBlades")
    		{
                dialog.text = RandPhraseSimple(DLG_TEXT_QB[59], DLG_TEXT_QB[60]);
        		link.l1 = RandPhraseSimple(DLG_TEXT_QB[61], DLG_TEXT_QB[62]);
        		link.l1.go = "STBStep_0";
    		}

    		if (npchar.id == "Winterwood")
    		{

                if(npchar.location == "Bridgetown_Brothel_room")
                {
                    dialog.text = DLG_TEXT_QB[63];
                    link.l1 = DLG_TEXT_QB[64];
                    link.l1.go = "WWStep_7";
                    break;
                }
                dialog.text = DLG_TEXT_QB[65];
        		link.l1 = DLG_TEXT_QB[66];
        		link.l1.go = "WWStep_0";
    		}

    		if (npchar.id == "Quest_Habitue")
    		{
				dialog.text = DLG_TEXT_QB[67];
				link.l1 = DLG_TEXT_QB[68];
				link.l1.go = "exit";
    		}

    		if (npchar.id == "Weston")
    		{
				dialog.text = DLG_TEXT_QB[69];
				link.l1 = DLG_TEXT_QB[70];
				link.l1.go = "exit";
    		}

    		if (npchar.id == "MoneySpy")
    		{
                if(npchar.quest.meeting == "1")
                {
                    dialog.text = DLG_TEXT_QB[71];
    				link.l1 = DLG_TEXT_QB[72];
    				link.l1.go = "exit";
                }
                else
                {
                    npchar.quest.meeting = "1";
                    dialog.text = DLG_TEXT_QB[73];
    				link.l1 = DLG_TEXT_QB[74];
    				link.l1.go = "MSStep_0";
    				link.l2 = DLG_TEXT_QB[75];
    				link.l2.go = "MSStep_1";
                }
    		}

    		if (npchar.id == "Fisherman")
    		{
                dialog.text = DLG_TEXT_QB[76];
    			link.l1 = DLG_TEXT_QB[77];
                link.l1.go = "exit";
    		}

    		if (npchar.id == "QStranger")
    		{
                dialog.text = DLG_TEXT_QB[78];
    			link.l1 = DLG_TEXT_QB[79];
                link.l1.go = "QSTStep_0";
    			link.l2 = DLG_TEXT_QB[80];
                link.l2.go = "QSTStep_1";
    			link.l3 = DLG_TEXT_QB[81];
                link.l3.go = "QSTStep_2";
    		}


		break;


		case "Citizen_0":

            if (!CheckAttribute(npchar, "quest.btmp"))
            {
                npchar.quest.btmp = true;
                if(rand(3)==2)
                {
                    dialog.text = LinkRandPhrase(DLG_TEXT_QB[82], DLG_TEXT_QB[83], DLG_TEXT_QB[84]);
                    link.l1 = DLG_TEXT_QB[85];
                    link.l1.go = "Exit";
                }
                else
                {
                    dialog.text = RandPhraseSimple(RandPhraseSimple(DLG_TEXT_QB[86], DLG_TEXT_QB[87]), RandPhraseSimple(DLG_TEXT_QB[88], DLG_TEXT_QB[89]));
                    link.l1 = DLG_TEXT_QB[90];
                    link.l1.go = "Exit";
                }

            }
            else
            {
                dialog.text = DLG_TEXT_QB[91];
                link.l1 = DLG_TEXT_QB[92];
                link.l1.go = "Exit";
            }

		break;

		case "Citizen_1":

            dialog.text = LinkRandPhrase(DLG_TEXT_QB[93], DLG_TEXT_QB[94], DLG_TEXT_QB[95]);
            link.l1 = DLG_TEXT_QB[96];
            link.l1.go = "Exit";

		break;

		case "Merchant_0":

        	dialog.text = DLG_TEXT_QB[97];
    		link.l1 = DLG_TEXT_QB[98];
    		link.l1.go = "Merchant_1";

		break;

		case "Merchant_1":

        	dialog.text = DLG_TEXT_QB[99];
    		link.l1 = DLG_TEXT_QB[100];
    		link.l1.go = "Exit";
            NextDiag.TempNode = "Merchant_2";
            if (Pchar.questTemp.CapBloodLine.stat == "PrepareToEscape") Pchar.questTemp.CapBloodLine.stat = "ReadyToEscape";//fix чтоб не сбивать уже начатые варианты
            GiveItem2Character(Pchar, "Weapon_for_escape");
            AddQuestRecord("WeaponsForEscape", "10");
    		CloseQuestHeader("WeaponsForEscape");

		break;

		case "Merchant_2":

        	dialog.text = DLG_TEXT_QB[101];
    		link.l1 = DLG_TEXT_QB[102];
    		link.l1.go = "Exit";
    		NextDiag.TempNode = "Merchant_2";

		break;


		// ==> Забираем клинки, пистоли.
		case "STBStep_0":
        	dialog.text = DLG_TEXT_QB[103];
    		link.l1 = DLG_TEXT_QB[104];
    		link.l1.go = "STBStep_1";
            link.l2 = DLG_TEXT_QB[105];
            link.l2.go = "fight";
		break;

		case "STBStep_1":

                dialog.text = DLG_TEXT_QB[106];
                link.l1.go = "Exit_Away";
                Pchar.questTemp.sLocator = "reload1_back";
                Pchar.questTemp.iTime = 40;
                RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
                RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
                while (FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE) != "" && FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE) != "blade5")
                {
                    TakeItemFromCharacter(pchar, FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE));

                }
                while (FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE) != "")
                {
                    TakeItemFromCharacter(pchar, FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE));
                }
                //GiveItem2Character(Pchar, "unarmed");
                //EquipCharacterByItem(Pchar, "unarmed");
                SetNewModelToChar(Pchar);
                //свободен
                pchar.quest.CapBloodDetectBlades1.over = "yes";
                pchar.quest.CapBloodDetectBlades2.over = "yes";
                chrDisableReloadToLocation = false;

		break;

		case "STBStep_2":
        	dialog.text = DLG_TEXT_QB[107];
    		link.l1 = DLG_TEXT_QB[108];
            link.l1.go = "Exit_Away";
            //link.l1.go = "finish";
            Pchar.questTemp.sLocator = "gate1_back";
            Pchar.questTemp.iTime = -1;

            chrDisableReloadToLocation = false;
            pchar.quest.CapBloodEscape2.win_condition.l1          = "location";
            pchar.quest.CapBloodEscape2.win_condition.l1.location = "Bridgetown_Plantation";
            pchar.quest.CapBloodEscape2.function                  = "ReturnToPlantation2";

            sld = characterFromID("Hugtorp");
            sld.Dialog.CurrentNode = "HTStep_14";
            ChangeCharacterAddressGroup(sld, "BridgeTown_Plantation", "goto", "goto18");
		break;

		//замечение по обнаженному оружию
		case "SoldierNotBlade":

            if (Pchar.questTemp.CapBUnarmed == false )
            {
                dialog.text = LinkRandPhrase(DLG_TEXT_QB[109], DLG_TEXT_QB[110], DLG_TEXT_QB[111]);
                link.l1 = LinkRandPhrase(DLG_TEXT_QB[112], DLG_TEXT_QB[113], DLG_TEXT_QB[114]);
    			link.l1.go = "exit";
                link.l2 = LinkRandPhrase(DLG_TEXT_QB[115], DLG_TEXT_QB[116], DLG_TEXT_QB[117]);
                link.l2.go = "fight";
			}
            else
            {
                dialog.text = RandPhraseSimple(DLG_TEXT_QB[118], DLG_TEXT_QB[119])+DLG_TEXT_QB[120];
                link.l1 = DLG_TEXT_QB[121];
                link.l1.go = "SoldierNotBladeEx";
                link.l2 = DLG_TEXT_QB[122];
                link.l2.go = "fight";
            }
			npchar.greeting = "soldier_common";
			NextDiag.TempNode = "First Time";
		break;

		case "SoldierNotBladeEx":

                RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
                RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
                while (FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE) != "" )
                {
                    TakeItemFromCharacter(pchar, FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE));

                }
                while (FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE) != "")
                {
                    TakeItemFromCharacter(pchar, FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE));
                }
                //свободен
                pchar.quest.CapBloodDetectBlades1.over = "yes";
                pchar.quest.CapBloodDetectBlades2.over = "yes";

                iChar = GetCharacterIndex("SolderTakeBlades");
                if (iChar != -1)
                {
                    sld = &characters[iChar];
                    LAi_ActorGoToLocation(sld, "reload", "reload1_back", "none", "", "", "", -1);
                    chrDisableReloadToLocation = false;
                }
                NextDiag.CurrentNode = NextDiag.TempNode;
                DialogExit();

		break;


        // --> Квестовый солдат


 		case "SQStep_0":

            dialog.text = DLG_TEXT_QB[123];
        	link.l1 = DLG_TEXT_QB[124];
            link.l1.go = "SQStep_1";
		break;

 		case "SQStep_1":

            dialog.text = DLG_TEXT_QB[125];
        	link.l1 = DLG_TEXT_QB[126];
            link.l1.go = "Exit_RunAway";
            Pchar.questTemp.sLocator = "houseSp2";
            Pchar.questTemp.iTime = 20;
            sld = characterFromID("CPBQuest_Solder");
            sld.dialog.filename = "Quest\CapBloodLine\questNPC.c";
            sld.SaveItemsForDead = true;
            sld.DontClearDead = true;
            LAi_SetActorTypeNoGroup(sld);
            LAi_ActorSetLayMode(sld);
            LAi_SetImmortal(sld, true);
			ChangeCharacterAddressGroup(sld, "CommonFlamHouse", "reload","reload3");

            sld = &characters[GetCharacterIndex("Griffin")];
            ChangeCharacterAddressGroup(sld, "CommonRoom_MH4", "barmen","bar1");
            LAi_SetActorTypeNoGroup(sld);
            LAi_ActorTurnToLocator(sld, "goto","goto2");
            LAi_SetStayTypeNoGroup(sld);
            sld = &characters[GetCharacterIndex("Spain_spy")];
            ChangeCharacterAddressGroup(sld, "CommonRoom_MH4", "goto","goto2");
            sld.dialog.currentnode = "SSStep_3";
            LAi_SetActorType(sld);
            LAi_ActorDialog(sld, pchar, "", 0, 0);
            LocatorReloadEnterDisable("BridgeTown_town", "houseSp2", false);

            pchar.quest.PrepareToEscape2_3.win_condition.l1          = "location";
            pchar.quest.PrepareToEscape2_3.win_condition.l1.location = "CommonFlamHouse";
            pchar.quest.PrepareToEscape2_3.function                  = "_DeadSolder";

            Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape2_3";
            DoQuestFunctionDelay("SpainSpyAttack", 20.0);

		break;
        // --> Квестовый раб

        case "SLQStep_0":

            dialog.text = DLG_TEXT_QB[127];
            if (GetCharacterItem(pchar,"migraine_potion") > 0)
            {
           	    link.l0 = DLG_TEXT_QB[128];
                link.l0.go = "SLQStep_3";
            }
        	link.l1 = DLG_TEXT_QB[129];
            link.l1.go = "SLQStep_1";

        break;

        case "SLQStep_1":

            dialog.text = DLG_TEXT_QB[130];
        	link.l1 = DLG_TEXT_QB[131];
            link.l1.go = "Exit";
           	NextDiag.TempNode = "SLQStep_2";

        break;

        case "SLQStep_2":

            dialog.text = DLG_TEXT_QB[132];
            if (GetCharacterItem(pchar,"migraine_potion") > 0)
            {
            	link.l1 = DLG_TEXT_QB[133];
                link.l1.go = "SLQStep_3";
           		link.l2 = DLG_TEXT_QB[134];
                link.l2.go = "Exit";
             }
             else
             {
            	link.l1 = DLG_TEXT_QB[135];
                link.l1.go = "Exit";
             }
           	NextDiag.TempNode = "SLQStep_2";

        break;

        case "SLQStep_3":

            dialog.text = DLG_TEXT_QB[136];
        	link.l1 = DLG_TEXT_QB[137];
            link.l1.go = "SLQStep_4";
            TakeItemFromCharacter(Pchar, "migraine_potion");
            GiveItem2Character(Pchar, "blade5");

        break;


        case "SLQStep_4":

            dialog.text = DLG_TEXT_QB[138];
        	link.l1 = DLG_TEXT_QB[139];
            link.l1.go = "Exit";
            NPChar.talker = 0;
           	NextDiag.TempNode = "First time";

        break;


        // --> Уинтервуд

        case "WWStep_0":

            dialog.text = DLG_TEXT_QB[140];
        	link.l1 = DLG_TEXT_QB[141];
            link.l1.go = "WWStep_1";

        break;

        case "WWStep_1":

            dialog.text = DLG_TEXT_QB[142];
        	link.l1 = DLG_TEXT_QB[143];
            link.l1.go = "WWStep_2";

        break;

        case "WWStep_2":

            dialog.text = DLG_TEXT_QB[144];
        	link.l1 = DLG_TEXT_QB[145];
            link.l1.go = "WWStep_3";

        break;

       	case "WWStep_3":
		Dialog.Text = DLG_TEXT_QB[146];
		link.l1 = DLG_TEXT_QB[147];
		link.l1.go = "WWStep_4";
        break;

		//что ж, пойдем выйдем
	case "WWStep_4":

        PChar.quest.CapBloodLineTimer_3.win_condition.l1            = "Timer";
        PChar.quest.CapBloodLineTimer_3.win_condition.l1.date.hour  = sti(GetTime() + 1);
        PChar.quest.CapBloodLineTimer_3.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 0);
        PChar.quest.CapBloodLineTimer_3.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
        PChar.quest.CapBloodLineTimer_3.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
        PChar.quest.CapBloodLineTimer_3.function = "WinterwoodDuel";

		NextDiag.CurrentNode = "WWStep_5";
		DialogExit();
    break;

    case "WWStep_5":

		Dialog.Text = DLG_TEXT_QB[148];
		link.l1 = DLG_TEXT_QB[149];
		link.l1.go = "WWStep_5_1";
		link.l2 = DLG_TEXT_QB[150];
		link.l2.go = "Exit";
		NextDiag.TempNode = "WWStep_5";
        break;

    case "WWStep_5_1":
		Dialog.Text = DLG_TEXT_QB[151];
		link.l1 = DLG_TEXT_QB[152];
		link.l1.go = "WWStep_6";
    break;

	case "talk_off_town":
		Dialog.Text = DLG_TEXT_QB[153];
		link.l1 = DLG_TEXT_QB[154];
		link.l1.go = "WWStep_6";
		GiveItem2Character(Pchar, "blade7");
        EquipCharacterByItem(Pchar, "blade7");
        chrDisableReloadToLocation = false;
    break;

	//дуэли быть!
	case "WWStep_6":
	    AddDialogExitQuestFunction("Winterwood_Prepare_Fight");
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();

	break;

    case "WWStep_7":

        dialog.text = DLG_TEXT_QB[155];
    	link.l1 = DLG_TEXT_QB[156];
        link.l1.go = "WWStep_8";

    break;

    case "WWStep_8":

        dialog.text = DLG_TEXT_QB[157];
    	link.l1 = DLG_TEXT_QB[158];
        link.l1.go = "WWStep_3";
        n = FindLocation("Bridgetown_Brothel");
        locations[n].reload.l2.disable = true;

    break;

    // --> Алкаш

    case "QHStep_0":

		dialog.text = DLG_TEXT_QB[159];
		link.l1 = DLG_TEXT_QB[160];
		link.l1.go = "exit";
		link.l2 = DLG_TEXT_QB[161];
		link.l2.go = "QHStep_1";
		NextDiag.TempNode = "QHStep_0";

    break;

	case "QHStep_1":
		NextDiag.TempNode = "begin_sit";
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		pchar.questTemp.friend_in_tavern = npchar.id;
		AddDialogExitQuest("alc");
	break;

	case "begin_sit":
		NextDiag.TempNode = "first time";
		dialog.text = DLG_TEXT_QB[162];
		link.l1 = DLG_TEXT_QB[163];
		link.l1.go = "QHStep_2";
	break;

	case "QHStep_2":
		WaitDate("",0,0,0, 0, 30);
		dialog.text = LinkRandPhrase(DLG_TEXT_QB[164],
		                             DLG_TEXT_QB[165],
									 DLG_TEXT_QB[166]);
		link.l1 = DLG_TEXT_QB[167];
		link.l1.go = "QHStep_3";
	break;

	case "QHStep_3":
		dialog.text = DLG_TEXT_QB[168];
		link.l1 = DLG_TEXT_QB[169];
		link.l1.go = "exit_sit";
		NextDiag.TempNode = "First time";

		if (CheckNationLicence(ENGLAND)) TakeNationLicence(ENGLAND);
		sTemp = NationShortName(ENGLAND)+"TradeLicence";
		ref rItem = ItemsFromID(sTemp);
		SaveCurrentNpcQuestDateParam(rItem, "Action_date");
		rItem.Action_date = GetCurrentDate();
		rItem.Validity = FindRussianDaysString(60);
		rItem.Validity.QtyDays = 60;

       // pchar.GenQuestBox.CommonStoneHouse = true;
       // pchar.GenQuestBox.CommonStoneHouse.stay = true;

        n = FindLocation("CommonStoneHouse");
        locations[n].private1.items.indian1 = 1;
        locations[n].private1.items.EngTradeLicence = 1;
        locations[n].private1.money = 6000;
        //#20190120-02
        LocatorReloadEnterDisable("BridgeTown_town", "houseS3", false);

       // pchar.GenQuestBox.CommonStoneHouse.box1.money = 6000;
       // pchar.GenQuestBox.CommonStoneHouse.box1.items.EngTradeLicence = 1;
       // pchar.GenQuestBox.CommonStoneHouse.box1.items.indian1 = 1;

        //Чарльз Вестон
       	sld = characterFromID("Weston");
       	sTemp = GetNationNameByType(ENGLAND) + "_citizens";
        LAi_group_MoveCharacter(sld, sTemp);
        LAi_SetOwnerTypeNoGroup(sld);
        ChangeCharacterAddressGroup(sld, "CommonStoneHouse", "barmen","stay");

        pchar.quest.MoneyForDieke.win_condition.l1 = "item";
        pchar.quest.MoneyForDieke.win_condition.l1.item= "EngTradeLicence";
        pchar.quest.MoneyForDieke.function = "MoneyForDieke";
        AddQuestRecord("DiekeQuest", "3");

	break;

	case "exit_sit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddDialogExitQuest("exit_sit");
	break;

    //Шпион

    case "MSStep_0":

        dialog.text = DLG_TEXT_QB[172];
    	link.l1 = "";
        link.l1.go = "Exit";

    break;

    case "MSStep_1":

        dialog.text = DLG_TEXT_QB[173];
    	link.l1 = DLG_TEXT_QB[174];
        link.l1.go = "MSStep_2";
       	link.l2 = DLG_TEXT_QB[175];
        link.l2.go = "MSStep_3";
       	link.l3 = DLG_TEXT_QB[176];
        link.l3.go = "MSStep_4";

    break;

    case "MSStep_2":

        dialog.text = DLG_TEXT_QB[177];
    	link.l1 = "...";
        link.l1.go = "exit";

    break;

    case "MSStep_3":

        dialog.text = DLG_TEXT_QB[178];
    	link.l1 = DLG_TEXT_QB[179];
        link.l1.go = "MSStep_5";
       	link.l2 = DLG_TEXT_QB[180];
        link.l2.go = "MSStep_6";

    break;

    case "MSStep_4":

        dialog.text = DLG_TEXT_QB[181];
    	link.l1 = "...";
        link.l1.go = "exit";

    break;

    case "MSStep_5":

        dialog.text = DLG_TEXT_QB[182];
    	link.l1 = DLG_TEXT_QB[183];
        link.l1.go = "MSStep_7";
       	link.l2 = DLG_TEXT_QB[184];
        link.l2.go = "MSStep_8";

    break;

    case "MSStep_6":

        dialog.text = DLG_TEXT_QB[185];
    	link.l1 = "...";
        link.l1.go = "exit";

    break;

    case "MSStep_7":

        dialog.text = DLG_TEXT_QB[186];
    	link.l1 = "...";
        link.l1.go = "exit";

    break;

    case "MSStep_8":

        dialog.text = DLG_TEXT_QB[187];
    	link.l1 = DLG_TEXT_QB[188];
        link.l1.go = "MSStep_9";
       	link.l2 = DLG_TEXT_QB[189];
        link.l2.go = "MSStep_10";
       	link.l3 = DLG_TEXT_QB[190];
        link.l3.go = "MSStep_11";

    break;

    case "MSStep_9":

        dialog.text = DLG_TEXT_QB[191];
    	link.l1 = "...";
        link.l1.go = "exit";

    break;

    case "MSStep_10":

        dialog.text = DLG_TEXT_QB[192];
    	link.l1 = "...";
        link.l1.go = "exit";

    break;

    case "MSStep_11":

        dialog.text = DLG_TEXT_QB[193];
    	link.l1 = DLG_TEXT_QB[194];
        link.l1.go = "MSStep_12";
       	link.l2 = DLG_TEXT_QB[195];
        link.l2.go = "MSStep_13";
       	link.l3 = DLG_TEXT_QB[196];
        link.l3.go = "MSStep_14";

    break;

    case "MSStep_12":

        dialog.text = DLG_TEXT_QB[197];
    	link.l1 = "...";
        link.l1.go = "exit";

    break;

    case "MSStep_13":

        dialog.text = DLG_TEXT_QB[198];
    	link.l1 = "...";
        link.l1.go = "exit";

    break;

    case "MSStep_14":

        dialog.text = DLG_TEXT_QB[199];
    	link.l1 = "...";
        link.l1.go = "exit";
        AddMoneyToCharacter(pchar, 1000);
        AddCharacterExpToSkill(pchar, "Sneak", 80);
        AddCharacterExpToSkill(pchar, "Fortune", 30);
    break;

    case "FStep_1":

        dialog.text = DLG_TEXT_QB[200];
        if(makeint(Pchar.money) >=4 )
        {
            link.l1 = DLG_TEXT_QB[201];
            link.l1.go = "FStep_1_2";
        }
       	link.l2 = DLG_TEXT_QB[202];
        link.l2.go = "FStep_1_3";

    break;

   	case "FStep_1_2":
		NextDiag.TempNode = "FStep_2";
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		pchar.questTemp.friend_in_tavern = npchar.id;
		AddDialogExitQuest("alc");
	break;

	case "FStep_1_3":
		NextDiag.TempNode = "FStep_3";
		NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		pchar.questTemp.friend_in_tavern = npchar.id;
		AddDialogExitQuest("alc");
	break;


    case "FStep_2":

        AddMoneyToCharacter(pchar, -2);
        dialog.text = DLG_TEXT_QB[203];
    	link.l1 = DLG_TEXT_QB[204];
        link.l1.go = "FStep_4";

    break;

    case "FStep_3":
        dialog.text = DLG_TEXT_QB[205];
    	link.l1 = DLG_TEXT_QB[206];
        link.l1.go = "FStep_5";
    break;

    case "FStep_4":

        AddMoneyToCharacter(pchar, -2);
        dialog.text = DLG_TEXT_QB[207];
    	link.l1 = DLG_TEXT_QB[208];
        link.l1.go = "FStep_6";

    break;

    case "FStep_5":

        dialog.text = DLG_TEXT_QB[209];
    	link.l1 = DLG_TEXT_QB[210];
        link.l1.go = "FStep_7";

    break;

    case "FStep_6":

        dialog.text = DLG_TEXT_QB[211];
    	link.l1 = "...";
        link.l1.go = "FStep_8";
       	link.l2 = DLG_TEXT_QB[212];
        link.l2.go = "FStep_Fail";

    break;

    case "FStep_7":

        dialog.text = DLG_TEXT_QB[213];
    	link.l1 = "...";
        link.l1.go = "FStep_8";
       	link.l2 = DLG_TEXT_QB[214];
        link.l2.go = "FStep_Fail";

    break;

    case "FStep_8":

        Pchar.questTemp.CapBloodLine.fishplace = DLG_TEXT_QB[215];
        dialog.text = DLG_TEXT_QB[216]+Pchar.questTemp.CapBloodLine.fishplace;
    	link.l1 = DLG_TEXT_QB[217];
        link.l1.go = "exit_sit";
        NextDiag.TempNode = "First time";
        AddQuestRecord("FishermanQuest", "2");

    break;

    case "FStep_Fail":

        dialog.text = DLG_TEXT_QB[218];
    	link.l1 = DLG_TEXT_QB[219];
        link.l1.go = "exit_sit";
        NextDiag.TempNode = "First time";

    break;

    case "QSTStep_0":

        dialog.text = DLG_TEXT_QB[220];
    	link.l1 = DLG_TEXT_QB[221];
        link.l1.go = "Exit_Away";
        Pchar.questTemp.sLocator = "reload1_back";
        if(npchar.location == "CommonRoom_MH7") Pchar.questTemp.sLocator = "reload1"
        Pchar.questTemp.iTime = -1;
   		CloseQuestHeader("UsurerQuest");

    break;

    case "QSTStep_1":

        dialog.text = DLG_TEXT_QB[222];
    	link.l1 = DLG_TEXT_QB[223];
        link.l1.go = "QSTStep_3";

    break;


    case "QSTStep_2":

        dialog.text = DLG_TEXT_QB[224];
    	link.l1 = DLG_TEXT_QB[225];
        link.l1.go = "QSTStep_6";

    break;

    case "QSTStep_3":

        dialog.text = DLG_TEXT_QB[226];
    	link.l1 = DLG_TEXT_QB[227];
        link.l1.go = "QSTStep_4";

    break;

    case "QSTStep_4":

        dialog.text = DLG_TEXT_QB[228];
    	link.l1 = DLG_TEXT_QB[229];
        link.l1.go = "QSTStep_5";

    break;

    case "QSTStep_5":

        PChar.quest.QUsurer.win_condition.l1            = "Timer";
        PChar.quest.QUsurer.win_condition.l1.date.hour  = 0;
        PChar.quest.QUsurer.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
        PChar.quest.QUsurer.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
        PChar.quest.QUsurer.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
        PChar.quest.QUsurer.function = "QUsurerLate";

        AddMoneyToCharacter(pchar, 55000);
        ChangeCharacterReputation(PChar, -10);
        AddCharacterExpToSkill(pchar, "Leadership", 30);
        dialog.text = DLG_TEXT_QB[230];
    	link.l1 = DLG_TEXT_QB[231];
        link.l1.go = "Exit_Away";
        Pchar.questTemp.sLocator = "reload1_back";
        if(npchar.location == "CommonRoom_MH7") Pchar.questTemp.sLocator = "reload1";
        Pchar.questTemp.iTime = -1;
        AddQuestRecord("UsurerQuest", "3");

    break;

    case "QSTStep_6":

        PChar.quest.QUsurer.win_condition.l1            = "Timer";
        PChar.quest.QUsurer.win_condition.l1.date.hour  = 0;
        PChar.quest.QUsurer.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
        PChar.quest.QUsurer.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
        PChar.quest.QUsurer.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
        PChar.quest.QUsurer.function = "QUsurerLate";

        AddMoneyToCharacter(pchar, 30000);
        dialog.text = DLG_TEXT_QB[232];
    	link.l1 = DLG_TEXT_QB[233];
        link.l1.go = "Exit_Away";
        Pchar.questTemp.sLocator = "reload1_back";
        if(npchar.location == "CommonRoom_MH7") Pchar.questTemp.sLocator = "reload1"
        Pchar.questTemp.iTime = -1;
        AddQuestRecord("UsurerQuest", "4");

    break;

    //Жак Соловей

    case "JSTStep_0":

        dialog.text = DLG_TEXT_QB[234];
    	link.l1 = DLG_TEXT_QB[235];
        link.l1.go = "JSTStep_1";

    break;

    case "JSTStep_1":

        dialog.text = DLG_TEXT_QB[236];
    	link.l1 = DLG_TEXT_QB[237];
        link.l1.go = "JSTStep_2";

    break;

    case "JSTStep_2":

        dialog.text = DLG_TEXT_QB[238];
    	link.l1 = DLG_TEXT_QB[239];
        link.l1.go = "JSTStep_3";

    break;

    case "JSTStep_3":

        dialog.text = DLG_TEXT_QB[240];
    	link.l1 = DLG_TEXT_QB[241];
        link.l1.go = "JSTStep_4";
       	link.l2 = DLG_TEXT_QB[242];
        link.l2.go = "JSTStep_5";

    break;

    case "JSTStep_4":

        dialog.text = DLG_TEXT_QB[243];
    	link.l1 = DLG_TEXT_QB[244];
        link.l1.go = "JSTStep_6";

    break;

    case "JSTStep_5":

        dialog.text = DLG_TEXT_QB[245];
    	link.l1 = DLG_TEXT_QB[246];
        link.l1.go = "JSTStep_6";

    break;

    case "JSTStep_6":

        dialog.text = DLG_TEXT_QB[247];
    	link.l1 = DLG_TEXT_QB[248];
        link.l1.go = "JSTStep_7";

    break;

    case "JSTStep_7":

        dialog.text = DLG_TEXT_QB[249];
    	link.l1 = DLG_TEXT_QB[250];
        link.l1.go = "JSTStep_8";

    break;

    case "JSTStep_8":

        dialog.text = DLG_TEXT_QB[251];
    	link.l1 = DLG_TEXT_QB[252];
        link.l1.go = "JSTStep_9";

    break;

    case "JSTStep_9":

        dialog.text = DLG_TEXT_QB[253];
    	link.l1 = DLG_TEXT_QB[254];
        link.l1.go = "JSTStep_10";
       	link.l2 = DLG_TEXT_QB[255];
        link.l2.go = "Exit_Away";
        Pchar.questTemp.sLocator = "reload1_back";
        Pchar.questTemp.iTime = -1;

    break;

    case "JSTStep_10":

        dialog.text = DLG_TEXT_QB[256];
    	link.l1 = DLG_TEXT_QB[257];
        link.l1.go = "Exit_Away";
        Pchar.questTemp.sLocator = "reload1_back";
        Pchar.questTemp.iTime = -1;
        AddQuestRecord("PirateQuest", "1");
        Pchar.questTemp.CapBloodLine.ShipForJack = true;
       	sld = characterFromID("Bridgetown_trader");
   	    LAi_RemoveLoginTime(sld);

    break;

    case "JSTStep_11":

        dialog.text = DLG_TEXT_QB[258];
    	link.l1 = DLG_TEXT_QB[259];
        link.l1.go = "JSTStep_12";

    break;

    case "JSTStep_12":

        dialog.text = DLG_TEXT_QB[260];
    	link.l1 = DLG_TEXT_QB[261];
        link.l1.go = "JSTStep_13";

    break;

    case "JSTStep_13":

        dialog.text = DLG_TEXT_QB[262];
    	link.l1 = DLG_TEXT_QB[263];
        link.l1.go = "JSTStep_14";

    break;

    case "JSTStep_14":

        dialog.text = DLG_TEXT_QB[264];
    	link.l1 = DLG_TEXT_QB[265];
        link.l1.go = "Exit";
        AddMoneyToCharacter(pchar, 1500);
        AddQuestRecord("PirateQuest", "5");
        CloseQuestHeader("PirateQuest");
        NextDiag.TempNode = "JSTStep_15";
        NPChar.lifeDay = 0;

    break;

    case "JSTStep_15":

        dialog.text = DLG_TEXT_QB[266];
    	link.l1 = DLG_TEXT_QB[267];
        link.l1.go = "Exit";
        NextDiag.TempNode = "JSTStep_15";

    break;

    //Джон Майнер

    case "MNStep_0":

        dialog.text = DLG_TEXT_QB[268];
    	link.l1 = DLG_TEXT_QB[269];
        link.l1.go = "MNStep_1";

    break;

    case "MNStep_1":

        dialog.text = DLG_TEXT_QB[270];
    	link.l1 = DLG_TEXT_QB[271];
        link.l1.go = "MNStep_2";
       	link.l2 = DLG_TEXT_QB[272];
        link.l2.go = "MNStep_3";
       	link.l3 = DLG_TEXT_QB[273];
        link.l3.go = "MNStep_4";

    break;

    case "MNStep_2":

        dialog.text = DLG_TEXT_QB[274];
    	link.l1 = DLG_TEXT_QB[275];
        link.l1.go = "MNStep_5";

    break;

    case "MNStep_3":

        dialog.text = DLG_TEXT_QB[276];
    	link.l1 = DLG_TEXT_QB[277];
        link.l1.go = "MNStep_Exit";

    break;


    case "MNStep_4":

        dialog.text = DLG_TEXT_QB[278];
    	link.l1 = DLG_TEXT_QB[279];
        link.l1.go = "MNStep_6";

    break;

    case "MNStep_5":

        dialog.text = DLG_TEXT_QB[280];
    	link.l1 = DLG_TEXT_QB[281];
        link.l1.go = "MNStep_Exit";
        AddCharacterExpToSkill(pchar, "Sneak", 50);

    break;

    case "MNStep_6":

        dialog.text = DLG_TEXT_QB[282];
    	link.l1 = DLG_TEXT_QB[283];
        link.l1.go = "MNStep_Exit";

    break;

   	case "MNStep_Exit":

            AddQuestRecord("PirateQuest", "4");
            sld = characterFromID("Jack");
            sld.Dialog.CurrentNode = "JSTStep_11";
            LAi_SetSitTypeNoGroup(sld);
            ChangeCharacterAddressGroup(sld, "Bridgetown_tavern", "sit","sit4");
            LAi_SetActorType(npchar);
 			LAi_ActorGoToLocation(npchar, "reload", "reload1", "none", "", "", "", -1);
            NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
	break;


    //Служанка Арабеллы

    case "ASStep_0":

        dialog.text = DLG_TEXT_QB[284];
    	link.l1 = DLG_TEXT_QB[285];
        link.l1.go = "ASStep_1";
        ChangeCharacterReputation(pchar, 5);

    break;

    case "ASStep_1":

        dialog.text = DLG_TEXT_QB[286];
    	link.l1 = DLG_TEXT_QB[287];
        link.l1.go = "ASStep_2";

    break;

    case "ASStep_2":

        dialog.text = DLG_TEXT_QB[288];
    	link.l1 = DLG_TEXT_QB[289];
        Pchar.questTemp.CapBloodLine.SpainInBridgetown = true;
        Pchar.questTemp.sLocator = "gate1_back";
        Pchar.questTemp.iTime = -1;
        link.l1.go = "Exit_RunAway";
        AddQuestRecord("EscapeFormBarbados", "3");

    break;


	}
}

