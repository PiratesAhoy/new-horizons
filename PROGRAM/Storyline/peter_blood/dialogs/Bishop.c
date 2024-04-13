void ProcessDialogEvent()
{
	ref NPChar, sld;
	aref Link, NextDiag;
    string sLocator;
    int iTime, n;
    string sTemp;

	DeleteAttribute(&Dialog,"Links");
ref PChar;
PChar = GetMainCharacter();
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

/*
	switch(Pchar.questTemp.CapBloodLine.stat)
    {
  		case "1":
            Dialog.CurrentNode = "First Bishop";
		break;

		case "2":
            Dialog.CurrentNode = "First Guard";
		break;

		case "3":
            Dialog.CurrentNode = "First Stid";
		break;

		case "4":
            Dialog.CurrentNode = "First MsStid";
		break;

    }
    */


	switch(Dialog.CurrentNode)
	{
	    // --> Бишоп
		// ----------------------------------- Диалог первый - первая встреча
		case "Exit":
            NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

        case "Exit_Away":

            LAi_SetActorTypeNoGroup(npchar);
            LAi_ActorGoToLocation(npchar, "reload", Pchar.questTemp.CapBloodLine.sLocator, "none", "", "", "", sti(Pchar.questTemp.CapBloodLine.iTime));
            NextDiag.CurrentNode = NextDiag.TempNode;
            DialogExit();
			LAi_SetPlayerType(Pchar);
        break;

        case "Exit_RunAway":
			LAi_SetPlayerType(Pchar);
            LAi_SetActorTypeNoGroup(npchar);
            LAi_ActorRunToLocation(npchar, "reload", Pchar.questTemp.CapBloodLine.sLocator, "none", "", "", "", sti(Pchar.questTemp.CapBloodLine.iTime));
            NextDiag.CurrentNode = NextDiag.TempNode;
            DialogExit();
        break;

        case "GFight":
		            AddDialogExitQuest("Blood14");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

        case "fight1":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
   	        LAi_SetWarriorType(NPChar);
            LAi_group_MoveCharacter(NPChar, "TmpEnemy");
            LAi_group_FightGroups("TmpEnemy", LAI_GROUP_PLAYER, true)
			AddDialogExitQuest("MainHeroFightModeOn");
			//Spain_spyDie("");
			AddQuestRecord("WeaponsForEscape", "5");

		break;

        case "fight":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
   	        LAi_SetWarriorType(NPChar);
            LAi_group_MoveCharacter(NPChar, "TmpEnemy");
            LAi_group_FightGroups("TmpEnemy", LAI_GROUP_PLAYER, true);
			AddDialogExitQuest("MainHeroFightModeOn");

		break;

		case "Finish":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		//	RestoreBridgetown();
		//	initMainCharacterItem();
            ref mc = GetMainCharacter();
           /*  mc.Ship.Type = GenerateShip(SHIP_ARABELLA, true);
            mc.Ship.name=DLG_TEXT_BL1[0];
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
            DoReloadCharacterToLocation(Pchar.HeroParam.Location, Pchar.HeroParam.Group, Pchar.HeroParam.Locator); */
		break;

        case "Man_FackYou":
			dialog.text = LinkRandPhrase(DLG_TEXT_BL1[1], DLG_TEXT_BL1[2], DLG_TEXT_BL1[3]);
			link.l1 = LinkRandPhrase(DLG_TEXT_BL1[4], DLG_TEXT_BL1[5], DLG_TEXT_BL1[6]);
			link.l1.go = "fight_owner";
		break;
		case "fight_owner":
            LAi_SetCitizenTypeNoGroup(Npchar);
			LAi_group_Attack(NPChar, Pchar);
			//if (rand(3) != 1) SetNationRelation2MainCharacter(sti(npchar.nation), RELATION_ENEMY);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "NextQuest":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			Pchar.questTemp.CapBloodLine.stat = "";
		break;






		case "First time":
        	dialog.text = DLG_TEXT_BL1[7];
            link.l1 = "...";
            link.l1.go = "Exit";
            npchar.quest.meeting = "1";

            if (npchar.id == "Pitt")
            {
     			if (bBettaTestMode)
                {
			        link.l0 = DLG_TEXT_BL1[8];
			        link.l0.go = "Finish";
                }

                if (Pchar.questTemp.CapBloodLine.stat == "Begining")
                {
                    dialog.text = DLG_TEXT_BL1[9];
            		link.l1 = DLG_TEXT_BL1[10];
                    link.l1.go = "Exit_Away";
                    Pchar.questTemp.CapBloodLine.sLocator = "goto1";
                    Pchar.questTemp.CapBloodLine.iTime = -1;
           			if (bBettaTestMode)
                    {
				        link.l3 = DLG_TEXT_BL1[11];
				        link.l3.go = "NextQuest";
                    }
            		break;
        		}

                if (Pchar.questTemp.CapBloodLine.stat == "CureMisStid")
                {
                    dialog.text = DLG_TEXT_BL1[12];
            		link.l1 = DLG_TEXT_BL1[13];
            		link.l1.go = "Exit";
            		break;
        		}
                if (Pchar.questTemp.CapBloodLine.stat == "WakerOfferComplited")
                {
                    dialog.text = DLG_TEXT_BL1[14];
            		link.l1 = DLG_TEXT_BL1[15];
            		link.l1.go = "PStep_0";
            		break;
        		}

                dialog.text = DLG_TEXT_BL1[16];
        		link.l1 = DLG_TEXT_BL1[17];
        		link.l1.go = "Exit";

    		}

            if (npchar.id == "Beyns")
            {
                dialog.text = DLG_TEXT_BL1[18];
        		link.l1 = DLG_TEXT_BL1[19];
        		link.l1.go = "EBStep_0";
    		}

            if (npchar.id == "CapGobart")
            {
                dialog.text = DLG_TEXT_BL1[20];
        		link.l1 = DLG_TEXT_BL1[21];
        		link.l1.go = "CGStep_1";
        	//	DragunInvansion4();
    		}

            if (npchar.id == "Bridgetown_Mayor" )
            {
                if( Pchar.questTemp.CapBloodLine.stat == "CureMisStid" )
                {
                    dialog.text = DLG_TEXT_BL1[22];
            		link.l1 = DLG_TEXT_BL1[23];
            		link.l1.go = "SStep_0";
            		link.l2 = DLG_TEXT_BL1[24];
            		link.l2.go = "SStep_1";
            		break;
                }

                if( Pchar.questTemp.CapBloodLine.stat == "PrepareToEscape3" )
                {
                    dialog.text = DLG_TEXT_BL1[25];
            		link.l1 = DLG_TEXT_BL1[26];
            		link.l1.go = "SStep_9";
            		break;
                }
                dialog.text = DLG_TEXT_BL1[27];
          		link.l1 = DLG_TEXT_BL1[28];
          		link.l1.go = "Exit";
 		         NextDiag.TempNode = "First time";
    		}

    		if (npchar.id == "MisStid" && Pchar.questTemp.CapBloodLine.stat == "CureMisStid")
    		{
            	dialog.text = DLG_TEXT_BL1[29];
        		link.l1 = DLG_TEXT_BL1[30];
        		link.l1.go = "MSStep_0";
    		}

    		if (npchar.id == "Nettl" ) // && Pchar.questTemp.CapBloodLine.stat == "CureMisStid"
    		{
            	dialog.text = DLG_TEXT_BL1[31];
	            if( Pchar.questTemp.CapBloodLine.stat == "needMoney")
                {
                	link.l1 = DLG_TEXT_BL1[32];
                    link.l1.go = "NStep_6";
                }
                else
                {
            		link.l1 = DLG_TEXT_BL1[33];
            		link.l1.go = "NStep_0";
                }
    		}

    		if (npchar.id == "Waker")
    		{
                if(Pchar.questTemp.CapBloodLine.stat == "CureMisStid")
                {
                	dialog.text = DLG_TEXT_BL1[34];
            		link.l1 = DLG_TEXT_BL1[35] ;
            		link.l1.go = "WStep_0";
            		link.l2 = DLG_TEXT_BL1[36];
            		link.l2.go = "WStep_1";
                }

                if(Pchar.questTemp.CapBloodLine.stat == "WakerOffer")
                {
                	dialog.text = DLG_TEXT_BL1[37];
            		link.l1 = DLG_TEXT_BL1[38] ;
            		link.l1.go = "WStep_3";

                }
    		}

    		if (npchar.id == "Den")
    		{
            	dialog.text = DLG_TEXT_BL1[39];
        		link.l1 = DLG_TEXT_BL1[40] ;
        		link.l1.go = "DStep_0";
    			if (GetCharacterItem(pchar,"migraine_potion") > 0)
    			{
            			link.l2 = DLG_TEXT_BL1[41];
            			link.l2.go = "DStep_1";
    			}
        		link.l3 = DLG_TEXT_BL1[42];
        		link.l3.go = "DStep_2";
    		}


    		if (npchar.id == "Griffin")
    		{
                if(Pchar.questTemp.CapBloodLine.stat == "PrepareToEscape1")
                {
                	dialog.text = DLG_TEXT_BL1[43];
            		link.l1 = DLG_TEXT_BL1[44];
            		link.l1.go = "GRStep_0";
            		break;
                }

                if(Pchar.questTemp.CapBloodLine.stat == "PrepareToEscape")
                {

                    dialog.text = DLG_TEXT_BL1[45];
            		link.l1 = DLG_TEXT_BL1[46] ;
            		link.l1.go = "GRStep_10";
            		break;

                }

                dialog.text = DLG_TEXT_BL1[47];
                link.l1 = DLG_TEXT_BL1[48] ;
                link.l1.go = "Exit";
    		}

    		if (npchar.id == "Hells")
    		{
                if(Pchar.questTemp.CapBloodLine.stat == "PrepareToEscape1_1")
                {
                	dialog.text = DLG_TEXT_BL1[49];
            		link.l1 = DLG_TEXT_BL1[50];
            		link.l1.go = "HStep_0";
            		link.l2 = DLG_TEXT_BL1[51];
            		link.l2.go = "fight1";
            		break;
                }

                if(Pchar.questTemp.CapBloodLine.stat == "needMoney" && !CheckAttribute(Pchar, "questTemp.CapBloodLine.fishplace"))
                {
                	dialog.text = DLG_TEXT_BL1[52];
            		link.l1 = DLG_TEXT_BL1[53];
            		link.l1.go = "HStep_5";
            		break;
                }

                dialog.text = DLG_TEXT_BL1[54];
                link.l1 = DLG_TEXT_BL1[55] ;
                link.l1.go = "Exit";
    		}

    		if (npchar.id == "Quest_Smuggler")
    		{
                if(Pchar.questTemp.CapBloodLine.stat == "PrepareToEscape" && sti(Pchar.reputation) >= 50)
                {
                	dialog.text = DLG_TEXT_BL1[56];
            		link.l1 = DLG_TEXT_BL1[57];
            		link.l1.go = "QSStep_0";
            		break;
                }

                dialog.text = DLG_TEXT_BL1[58];
                link.l1 = DLG_TEXT_BL1[59] ;
                link.l1.go = "Exit";
    		}

    		if (npchar.id == "Spain_spy" )
    		{
            	dialog.text = DLG_TEXT_BL1[60];
        		link.l1 = DLG_TEXT_BL1[61];
        		link.l1.go = "SSStep_0";
    		}

    		 if(npchar.id == "Hugtorp")
    		 {
                if(Pchar.questTemp.CapBloodLine.statcrew == "find")
                {
                    dialog.text = DLG_TEXT_BL1[62];
                    link.l1 = DLG_TEXT_BL1[63];
                    link.l1.go = "HTStep_1";
              		break;
                }
                dialog.text = DLG_TEXT_BL1[64];
                link.l1 = DLG_TEXT_BL1[65];
                link.l1.go = "Exit";

    		 }

    		 if(npchar.id == "Dieke")
    		 {
                if(Pchar.questTemp.CapBloodLine.statcrew == "find")
                {
                    dialog.text = DLG_TEXT_BL1[66];
                    link.l1 = DLG_TEXT_BL1[67];
                    link.l1.go = "DKStep_0";
              		break;
                }
                dialog.text = DLG_TEXT_BL1[68];
                link.l1 = DLG_TEXT_BL1[69];
                link.l1.go = "Exit";
    		 }

    		 if(npchar.id == "Ogl")
    		 {
                if(Pchar.questTemp.CapBloodLine.statcrew == "find")
                {
                    dialog.text = TimeGreeting() + DLG_TEXT_BL1[70];
                    link.l1 = DLG_TEXT_BL1[71];
                    link.l1.go = "OGLStep_0";
              		break;
                }
                dialog.text = TimeGreeting() + DLG_TEXT_BL1[72];
                link.l1 = DLG_TEXT_BL1[73];
                link.l1.go = "Exit";
    		 }



		break;


		case "First Bishop":
            if(NPChar.quest.meeting == "0")
            {
            	dialog.text = DLG_TEXT_BL1[74];
                link.l1 = DLG_TEXT_BL1[75];
                link.l1.go = "BStep_0";
                npchar.quest.meeting = "1";
            }
            else
            {
           	    dialog.text = DLG_TEXT_BL1[76];
                link.l1 = DLG_TEXT_BL1[77];
                link.l1.go = "Exit";
            }
		break;

		case "BStep_0":
        	dialog.text = DLG_TEXT_BL1[78];
    		link.l1 = DLG_TEXT_BL1[79];
    		link.l1.go = "Bishop_Away";
            LAi_LockFightMode(pchar, false);
            chrDisableReloadToLocation = false;
            LAi_LocationFightDisable(loadedLocation, false);
            Pchar.questTemp.CapBloodLine.stat = "CureMisStid";
            NextDiag.TempNode = "First Bishop";
             //#20190120-02
            LocatorReloadEnterDisable("BridgeTown_town", "reload3_back", false); //_Townhall
            //сроки 4 часа
            PChar.quest.CapBloodLineTimer_1.win_condition.l1            = "Timer";
            PChar.quest.CapBloodLineTimer_1.win_condition.l1.date.hour  = 4;
            PChar.quest.CapBloodLineTimer_1.win_condition.l1.date.day   = GetAddingDataDay(0, 0, 1);
            PChar.quest.CapBloodLineTimer_1.win_condition.l1.date.month = GetAddingDataMonth(0, 0, 0);
            PChar.quest.CapBloodLineTimer_1.win_condition.l1.date.year  = GetAddingDataYear(0, 0, 0);
            PChar.quest.CapBloodLineTimer_1.function = "CapBloodLine_q1_Late";
            AddQuestRecord("CapBloodLine_q1", "1");

		break;

		case "BStep_1":
        	dialog.text = DLG_TEXT_BL1[80];
            link.l1 = DLG_TEXT_BL1[81];
            link.l1.go = "Exit";
            NextDiag.TempNode = "BStep_1";
		break;

		case "BStep_2":
        	dialog.text = DLG_TEXT_BL1[82];
            link.l1 = DLG_TEXT_BL1[83];
            link.l1.go = "BStep_3";
		break;

		case "BStep_3":
        	dialog.text = DLG_TEXT_BL1[84];
            link.l1 = DLG_TEXT_BL1[85];
            link.l1.go = "BStep_4";
		break;


		case "BStep_4":
        	dialog.text = DLG_TEXT_BL1[86];
            link.l1 = DLG_TEXT_BL1[87];
            link.l1.go = "BStep_5";
		break;

		case "BStep_5":
        	dialog.text = DLG_TEXT_BL1[88];
            link.l1 = DLG_TEXT_BL1[89];
            link.l1.go = "Exit";
            NextDiag.TempNode = "BStep_1";
            sld = characterFromID("Quest_Habitue");
            sld.Dialog.CurrentNode = "QHStep_0";
            AddQuestRecord("DiekeQuest", "2");

		break;

		case "Bishop_Away":

            LAi_SetActorTypeNoGroup(npchar);
            LAi_ActorGoToLocation(npchar, "reload", "houseSp1", "Plantation_Sp1", "goto", "goto1", "BishopOnHouse", -1);
            NextDiag.CurrentNode = NextDiag.TempNode;
            DialogExit()
		break;

		// -->Эндрю Бейнс

		case "EBStep_0":

            dialog.text = DLG_TEXT_BL1[90];
        	link.l1 = DLG_TEXT_BL1[91];
            link.l1.go = "Exit_RunAway";
            Pchar.questTemp.CapBloodLine.sLocator = "Reload4";
            Pchar.questTemp.CapBloodLine.iTime = -1;

		break;

		case "EBStep_1":

            dialog.text = DLG_TEXT_BL1[92];
        	link.l1 = DLG_TEXT_BL1[93];
            link.l1.go = "Exit";
            NextDiag.TempNode = "EBStep_2";
			AddDialogExitQuest("Blood3")
		break;

		case "EBStep_2":

            dialog.text = DLG_TEXT_BL1[94];
        	link.l1 = DLG_TEXT_BL1[95];
            link.l1.go = "Exit";
            NextDiag.TempNode = "EBStep_3";
			AddDialogExitQuest("Blood8")

		break;

		case "EBStep_3":

            dialog.text = DLG_TEXT_BL1[96];
        	link.l1 = DLG_TEXT_BL1[97];
            link.l1.go = "Exit";
            NextDiag.TempNode = "EBStep_3";

		break;

		//--> капитан Гобард

		case "CGStep_1":
        	dialog.text = DLG_TEXT_BL1[98];
    		link.l1 = DLG_TEXT_BL1[99];
    		link.l1.go = "CGStep_2";

		break;

		case "CGStep_2":
        	dialog.text = DLG_TEXT_BL1[100];
    		link.l1 = DLG_TEXT_BL1[101];
    		link.l1.go = "CGStep_3";

		break;

		case "CGStep_3":
        	dialog.text = DLG_TEXT_BL1[102];
    		link.l1 = DLG_TEXT_BL1[103];
    		link.l1.go = "CGStep_4";

		break;

		case "CGStep_4":
        	dialog.text = DLG_TEXT_BL1[104];
    		link.l1 = DLG_TEXT_BL1[105];
    		link.l1.go = "CGStep_5";

		break;

		case "CGStep_5":
        	dialog.text = DLG_TEXT_BL1[106];
    		link.l1 = DLG_TEXT_BL1[107];
    		link.l1.go = "CGStep_6";

		break;

		case "CGStep_6":
        	dialog.text = DLG_TEXT_BL1[108];
    		link.l1 = DLG_TEXT_BL1[109];
    		link.l1.go = "CGStep_7";
		break;

		case "CGStep_7":
        	dialog.text = DLG_TEXT_BL1[110];
    		link.l1 = DLG_TEXT_BL1[111];
    		link.l1.go = "CGStep_8";
		break;

		case "CGStep_8":
        	dialog.text = DLG_TEXT_BL1[112];
    		link.l1 = DLG_TEXT_BL1[113];
    		link.l1.go = "GFight";
    		NextDiag.TempNode = "CGStep_9";
		break;

        case "CGStep_9":
			dialog.text = LinkRandPhrase(DLG_TEXT_BL1[114], DLG_TEXT_BL1[115], DLG_TEXT_BL1[116]);
			link.l1 = LinkRandPhrase(DLG_TEXT_BL1[117], DLG_TEXT_BL1[118], DLG_TEXT_BL1[119]);
			link.l1.go = "Exit";
			NextDiag.TempNode = "CGStep_9";
		break;


		// -->Стражник на входе

		case "First Guard":
        	dialog.text = DLG_TEXT_BL1[120];
    		link.l1 = DLG_TEXT_BL1[121];
    		link.l1.go = "GStep_0";

		break;

		case "GStep_0":

            dialog.text = DLG_TEXT_BL1[122];
        	link.l1 = DLG_TEXT_BL1[123];
            link.l1.go = "Exit";
            LocatorReloadEnterDisable("BridgeTown_town", "reload3_back", false);//отпираем резеденцию
            //LocatorReloadEnterDisable("BridgeTown_town", "reload3_back", false);
            LocatorReloadEnterDisable("BridgeTown_town", "reloadR1", false);
            //солдата на место
            LAi_SetLoginTime(npchar, 6.0, 23.0);
            npchar.protector = false;
            npchar.protector.CheckAlways = 0;
            npchar.dialog.filename = "Quest\CapBloodLine\questNPC.c";

		break;

		case "GStep_1":

            dialog.text = DLG_TEXT_BL1[124];
            if (GetCharacterItem(pchar,"migraine_potion") > 0)
            {
       	        link.l1 = DLG_TEXT_BL1[125];
                link.l1.go = "Exit";
                LocatorReloadEnterDisable("BridgeTown_town", "reload3_back", false);//отпираем резеденцию
                //LocatorReloadEnterDisable("BridgeTown_town", "reload3_back", false);
                LocatorReloadEnterDisable("BridgeTown_town", "reloadR1", false);
                //солдата на место
                npchar.protector = false;
                npchar.protector.CheckAlways = 0;
                npchar.dialog.filename = "Quest\CapBloodLine\questNPC.c";

            }
            else
            {
           	    link.l1 = DLG_TEXT_BL1[126];
                link.l1.go = "GStep_2";
            }

		break;

 		case "GStep_2":

            dialog.text = DLG_TEXT_BL1[127];
        	link.l1 = DLG_TEXT_BL1[128];
            link.l1.go = "Exit";
            NextDiag.TempNode = "GStep_3";
            AddQuestRecord("WeaponsForEscape", "12");
		break;

		case "GStep_3":

            dialog.text = DLG_TEXT_BL1[129];
            if (GetCharacterItem(pchar,"migraine_potion") > 0)
            {
       	        link.l1 = DLG_TEXT_BL1[130];
                link.l1.go = "Exit";
                LocatorReloadEnterDisable("BridgeTown_town", "reload3_back", false);//отпираем резеденцию
                //LocatorReloadEnterDisable("BridgeTown_town", "reload3_back", false);
                LocatorReloadEnterDisable("BridgeTown_town", "reloadR1", false);
                //солдата на место
                npchar.protector = false;
                npchar.protector.CheckAlways = 0;
                npchar.dialog.filename = "Quest\CapBloodLine\questNPC.c";
                NextDiag.TempNode = "First time";

            }
            else
            {
            	link.l1 = DLG_TEXT_BL1[131];
                link.l1.go = "Exit";
                NextDiag.TempNode = "GStep_3";
            }

		break;

        // --> Стид


 		case "SStep_0":

            ChangeCharacterReputation(PChar, 5);
            dialog.text = DLG_TEXT_BL1[132];
        	link.l1 = DLG_TEXT_BL1[133];
            link.l1.go = "SStep_2";
		break;

 		case "SStep_1":

            dialog.text = DLG_TEXT_BL1[134];
        	link.l1 = DLG_TEXT_BL1[135];
            link.l1.go = "SStep_2";
		break;

 		case "SStep_2":

            dialog.text = DLG_TEXT_BL1[136];
            link.l1.go = "Exit";
            NextDiag.TempNode = "SStep_3";

			/*sld = GetCharacter(NPC_GenerateCharacter("MisStid", "AnnaDeLeiva", "woman", "towngirl2", 10, ENGLAND, 3, false));
            sld.dialog.filename = "Quest\CapBloodLine\Bishop.c";
			sld.name = DLG_TEXT_BL1[137];
			sld.lastname = DLG_TEXT_BL1[138];
			sld.greeting = "Gr_Dama";
			sTemp = GetNationNameByType(ENGLAND) + "_citizens";
            LAi_group_MoveCharacter(sld, sTemp);
			LAi_SetStayTypeNoGroup(sld);
			ChangeCharacterAddressGroup(sld, "CommonBedroom", "goto","goto5"); */
			AddQuestRecord("CapBloodLine_q1", "2");
		break;


		case "SStep_3":

            sld = &characters[GetCharacterIndex("MisStid")];
            if (sld.quest.meeting != "1")
            {
                dialog.text = DLG_TEXT_BL1[139];
                link.l1 = DLG_TEXT_BL1[140];
                link.l1.go = "Exit";
            }
            else
            {
                dialog.text = DLG_TEXT_BL1[141];
                link.l1 = DLG_TEXT_BL1[142];
                link.l1.go = "SStep_4";

                link.l2 = DLG_TEXT_BL1[143];
                link.l2.go = "SStep_5";
            }
		break;

		case "SStep_4":

            dialog.text = DLG_TEXT_BL1[144];
            link.l1 = DLG_TEXT_BL1[145];
            link.l1.go = "Exit";
            NextDiag.TempNode = "SStep_4";

		break;

		case "SStep_5":

            dialog.text = DLG_TEXT_BL1[146];
            link.l1 = DLG_TEXT_BL1[147];
            link.l1.go = "SStep_6";
            link.l2 = DLG_TEXT_BL1[148];
            link.l2.go = "SStep_7";
            link.l3 = DLG_TEXT_BL1[149];
            link.l3.go = "SStep_8";

		break;

		case "SStep_6":

            AddMoneyToCharacter(pchar, 500);
            dialog.text = DLG_TEXT_BL1[150];
            link.l1 = DLG_TEXT_BL1[151];
            link.l1.go = "Exit";
            NextDiag.TempNode = "SStep_4";
            AddQuestRecord("CapBloodLine_q1", "4");
         //   AddQuestUserData("CapBloodLine_q1", "iMoney", 500);

		break;

		case "SStep_7":

            AddMoneyToCharacter(pchar, 1000);
            dialog.text = DLG_TEXT_BL1[152];
            link.l1 = DLG_TEXT_BL1[153];
            link.l1.go = "Exit";
            NextDiag.TempNode = "SStep_4";
            AddQuestRecord("CapBloodLine_q1", "4");
           // AddQuestUserData("CapBloodLine_q1", "iMoney", 1000);

		break;

		case "SStep_8":

            AddMoneyToCharacter(pchar, 2500);
            dialog.text = DLG_TEXT_BL1[154];
            link.l1 = DLG_TEXT_BL1[155];
            link.l1.go = "Exit";
            NextDiag.TempNode = "SStep_4";
            AddQuestRecord("CapBloodLine_q1", "5");


		break;

		case "SStep_9":

            dialog.text = DLG_TEXT_BL1[156];
            link.l1 = DLG_TEXT_BL1[157];
            link.l1.go = "Exit";
            NextDiag.TempNode = "First time";
            LocatorReloadEnterDisable("Bridgetown_Townhall", "reload3", false);
            LocatorReloadEnterDisable("BridgeTown_town", "reloadR1", false);
            Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape3_1";

		break;

        //--> Миссис Стид

        case "MSStep_0":

            dialog.text = DLG_TEXT_BL1[158];
        	link.l1 = DLG_TEXT_BL1[159];
            link.l1.go = "Exit";
            NextDiag.TempNode = "MSStep_1";

           /*  sld = GetCharacter(NPC_GenerateCharacter("Waker", "usurer_5", "man", "man", 7, ENGLAND, 3, false));
            sld.dialog.filename = "Quest\CapBloodLine\Bishop.c";
            sld.name = DLG_TEXT_BL1[160];
            sld.lastname = DLG_TEXT_BL1[161];
            sld.greeting 	=  "Gr_medic";
            sTemp = GetNationNameByType(ENGLAND) + "_citizens";
            LAi_group_MoveCharacter(sld, sTemp);
			ChangeCharacterAddressGroup(sld, "CommonPirateHouse", "goto","goto6");
            LAi_SetActorTypeNoGroup(sld);
            LAi_ActorDialog(sld, pchar, "", 2.0, 0); */

            pchar.quest.CureMisStid.win_condition.l1 = "item";
			pchar.quest.CureMisStid.win_condition.l1.item= "migraine_potion";
			pchar.quest.CureMisStid.function = "CapBloodLine_q1_End";

			sld = ItemsFromID("migraine_potion");
			sld.shown = true;
			sld.startLocation = "CommonPirateHouse";
			sld.startLocator = "item1";

			AddQuestRecord("CapBloodLine_q1", "3");


		break;

        case "MSStep_1":

            dialog.text = DLG_TEXT_BL1[162];
            if(Pchar.questTemp.CapBloodLine.stat == "CureMisStid_Complite")
            {
                link.l1 = DLG_TEXT_BL1[163];
                link.l1.go = "MSStep_2";
                TakeItemFromCharacter(Pchar, "migraine_potion");

            }
            else
            {
                link.l1 = DLG_TEXT_BL1[164];
                link.l1.go = "Exit";
            }

		break;

        case "MSStep_2":

        NextDiag.CurrentNode = NextDiag.TempNode;
		DialogExit();
		//Вывести экран в темноту, выполнить квест questFadeOut, вернуть всё обратно, выполнить квест questFadeIn
        //LAi_Fade("", "CapBloodLine_q1_Complited");
   //     CapBloodLine_q1_Complited("");

		break;

        case "MSStep_3":

            dialog.text = DLG_TEXT_BL1[165];
        	link.l1 = DLG_TEXT_BL1[166];
            link.l1.go = "MSStep_4";
            DeleteAttribute(npchar, "talker");

		break;

        case "MSStep_4":

            dialog.text = DLG_TEXT_BL1[167];
        	link.l1 = DLG_TEXT_BL1[168];
            link.l1.go = "MSStep_5";
           	link.l1 = DLG_TEXT_BL1[169];
            link.l1.go = "MSStep_5";

		break;

        case "MSStep_5":

            dialog.text = DLG_TEXT_BL1[170];
        	link.l1 = DLG_TEXT_BL1[171];
            link.l1.go = "MSStep_6";

		break;

        case "MSStep_6":

            dialog.text = DLG_TEXT_BL1[172];
        	link.l1 = DLG_TEXT_BL1[173];
            link.l1.go = "MSStep_7";

		break;

        case "MSStep_7":

            dialog.text = DLG_TEXT_BL1[174];
        	link.l1 = DLG_TEXT_BL1[175];
            TakeItemFromCharacter(Pchar, "migraine_potion");
            AddQuestRecord("WeaponsForEscape", "15");
            link.l1.go = "Exit";
            NextDiag.TempNode = "MSStep_8";


		break;

        case "MSStep_8":

            dialog.text = DLG_TEXT_BL1[176];
        	link.l1 = DLG_TEXT_BL1[177];
            link.l1.go = "Exit";
            NextDiag.TempNode = "MSStep_8";
		break;



        //--> Нэтталл

        case "NStep_0":

            dialog.text = DLG_TEXT_BL1[178];
        	link.l1 = DLG_TEXT_BL1[179];
            link.l1.go = "Nettl_Away";
            NextDiag.TempNode = "NStep_1";
            Pchar.questTemp.CapBloodLine.TalkWithNettl = true;
		break;

        case "NStep_1":

            dialog.text = DLG_TEXT_BL1[180];
            if( Pchar.questTemp.CapBloodLine.stat == "needMoney")
            {
                link.l1 = DLG_TEXT_BL1[181];
                link.l1.go = "NStep_2";
            }
            else
            {
                link.l1 = DLG_TEXT_BL1[182];
                link.l1.go = "Exit";
                NextDiag.TempNode = "NStep_1";
            }
		break;

        case "NStep_2":

            dialog.text = DLG_TEXT_BL1[183];
            if(makeint(pchar.money) >= 25000)
            {
                link.l1 = DLG_TEXT_BL1[184];
                link.l1.go = "NStep_3";
            }
            else
            {
                link.l1 = DLG_TEXT_BL1[185];
                link.l1.go = "Exit";
                NextDiag.TempNode = "NStep_5";
            }
		break;

        case "NStep_3":

            AddMoneyToCharacter(pchar, -25000);
            dialog.text = DLG_TEXT_BL1[186];
        	link.l1 = DLG_TEXT_BL1[187];
            link.l1.go = "Exit";
            NextDiag.TempNode = "NStep_4";
            NPChar.lifeDay = 0;
       		CloseQuestHeader("CapBloodLine_q2");
   //         CapBloodLine_q3_Complited();

		break;

        case "NStep_4":

            dialog.text = DLG_TEXT_BL1[188];
        	link.l1 = DLG_TEXT_BL1[189];
            link.l1.go = "Exit";
            NextDiag.TempNode = "NStep_4";
		break;

        case "NStep_5":

            dialog.text = DLG_TEXT_BL1[190];
            if(makeint(pchar.money) >= 25000)
            {
                link.l1 = DLG_TEXT_BL1[191];
                link.l1.go = "NStep_3";
            }
            else
            {
               	link.l1 = DLG_TEXT_BL1[192];
                link.l1.go = "Exit";
                NextDiag.TempNode = "NStep_5";
            }
		break;

		case "Nettl_Away":

            LAi_SetActorTypeNoGroup(npchar);
            LAi_ActorGoToLocation(npchar, "reload", "reload4_back", "none", "", "", "NettlOnTavern", -1);
            NextDiag.CurrentNode = NextDiag.TempNode;
            DialogExit();
		break;

        case "NStep_6":

            dialog.text = DLG_TEXT_BL1[193];
        	link.l1 = DLG_TEXT_BL1[194];
            link.l1.go = "Nettl_Away";
            NextDiag.TempNode = "NStep_5";
            Pchar.questTemp.CapBloodLine.TalkWithNettl = true;
		break;

        //--> Вакер

        case "WStep_0":

            //AddCharacterExpToSkill(pchar, "Sneak", 50);
            dialog.text = DLG_TEXT_BL1[195];
        	link.l1 = DLG_TEXT_BL1[196];
            link.l1.go = "WStep_2";

		break;

        case "WStep_1":

            dialog.text = DLG_TEXT_BL1[197];
        	link.l1 = DLG_TEXT_BL1[198];
            link.l1.go = "WStep_2";

		break;

        case "WStep_2":

            dialog.text = DLG_TEXT_BL1[199];
        	link.l1 = DLG_TEXT_BL1[200];
            link.l1.go = "Exit_Away";
            Pchar.questTemp.CapBloodLine.sLocator = "reload1";
            Pchar.questTemp.CapBloodLine.iTime = 5;

          /*   sld = GetCharacter(NPC_GenerateCharacter("Den", "usurer_1", "man", "man", 7, ENGLAND, 3, false));
            sld.dialog.filename = "Quest\CapBloodLine\Bishop.c";
            sld.name = DLG_TEXT_BL1[201];
            sld.lastname = DLG_TEXT_BL1[202];
            sld.greeting 	=  "Gr_medic";
            sTemp = GetNationNameByType(ENGLAND) + "_citizens";
            LAi_group_MoveCharacter(sld, sTemp);
			ChangeCharacterAddressGroup(sld, "BridgeTown_town", "goto","goto3");
            LAi_SetActorTypeNoGroup(sld);
            LAi_ActorDialog(sld, pchar, "", 2.0, 0); */
            AddQuestRecord("CapBloodLine_q2", "1");

		break;
		//Предложение Вакера - вторая встреча
        case "WStep_3":

            dialog.text = DLG_TEXT_BL1[203];
        	link.l1 = DLG_TEXT_BL1[204];
            link.l1.go = "WStep_4";

		break;

        case "WStep_4":

            dialog.text = DLG_TEXT_BL1[205];
        	link.l1 = DLG_TEXT_BL1[206];
            link.l1.go = "WStep_5";

		break;

        case "WStep_5":

            dialog.text = DLG_TEXT_BL1[207];
        	link.l1 = DLG_TEXT_BL1[208];
            link.l1.go = "WStep_6";

		break;

        case "WStep_6":

            dialog.text = DLG_TEXT_BL1[209];
        	link.l1 = DLG_TEXT_BL1[210];
            link.l1.go = "WStep_7";
           	link.l2 = DLG_TEXT_BL1[211];
            link.l2.go = "WStep_8";

		break;

        case "WStep_7":

            dialog.text = DLG_TEXT_BL1[212];
        	link.l1 = DLG_TEXT_BL1[213];
            link.l1.go = "WStep_9";

		break;

        case "WStep_8":

            dialog.text = DLG_TEXT_BL1[214];
        	link.l1 = DLG_TEXT_BL1[215];
            link.l1.go = "WStep_9";

		break;

        case "WStep_9":

            dialog.text = DLG_TEXT_BL1[216];
        	link.l1 = DLG_TEXT_BL1[217];
            link.l1.go = "Exit";
            n = FindLocation("Bridgetown_tavern");
            locations[n].reload.l2.disable = true;
            Pchar.questTemp.CapBloodLine.stat = "WakerOfferComplited";
            AddQuestRecord("CapBloodLine_q2", "4");
            NextDiag.TempNode = "WStep_10";

		break;

        case "WStep_10":

            dialog.text = DLG_TEXT_BL1[218];
        	link.l1 = DLG_TEXT_BL1[219];
            link.l1.go = "Exit";
            NextDiag.TempNode = "WStep_10";

		break;

		//Предложение Вакера - заключение

        case "WStep_11":

            dialog.text = DLG_TEXT_BL1[220];
        	link.l1 = DLG_TEXT_BL1[221];
            link.l1.go = "WStep_12";

		break;

        case "WStep_12":

            dialog.text = DLG_TEXT_BL1[222];
        	link.l1 = DLG_TEXT_BL1[223];
            link.l1.go = "WStep_13";
            AddMoneyToCharacter(pchar, 18000);

		break;

        case "WStep_13":

            dialog.text = DLG_TEXT_BL1[224];
            if(Pchar.questTemp.CapBloodLine.TalkWithNettl == false)
            {
            	link.l1 = DLG_TEXT_BL1[225];
                link.l1.go = "WStep_14";
            }
            else
            {
            	link.l1 = DLG_TEXT_BL1[226];
                link.l1.go = "WStep_15";
            }

		break;

        case "WStep_14":

            dialog.text = DLG_TEXT_BL1[227];
        	link.l1 = DLG_TEXT_BL1[228];
            link.l1.go = "Exit";
            NextDiag.TempNode = "WStep_16";
            n = FindLocation("Bridgetown_tavern");
            locations[n].reload.l2.disable = true;
            Pchar.questTemp.CapBloodLine.stat = "needMoney";
            AddQuestRecord("CapBloodLine_q2", "7");

		break;

        case "WStep_15":

            dialog.text = DLG_TEXT_BL1[229];
        	link.l1 = DLG_TEXT_BL1[230];
            link.l1.go = "Exit";
            NextDiag.TempNode = "WStep_16";
            n = FindLocation("Bridgetown_tavern");
            locations[n].reload.l2.disable = true;
            Pchar.questTemp.CapBloodLine.stat = "needMoney";
            AddQuestRecord("CapBloodLine_q2", "7");

		break;

        case "WStep_16":

            dialog.text = DLG_TEXT_BL1[231];
        	link.l1 = DLG_TEXT_BL1[232];
            link.l1.go = "Exit";
            NextDiag.TempNode = "WStep_16";

		break;

        //--> Мистер Дэн

        case "DStep_0":

            dialog.text = DLG_TEXT_BL1[233];
        	link.l1 = DLG_TEXT_BL1[234];
            link.l1.go = "Exit_Away";
            GiveItem2Character(Pchar, "migraine_potion");
            Pchar.questTemp.CapBloodLine.sLocator = "houseSp1";
            Pchar.questTemp.CapBloodLine.iTime = -1;

		break;

        case "DStep_1":

            dialog.text = DLG_TEXT_BL1[235];
        	link.l1 = DLG_TEXT_BL1[236];
            link.l1.go = "Exit_Away";
            ChangeCharacterReputation(PChar, 5);
            Pchar.questTemp.CapBloodLine.sLocator = "houseSp1";
            Pchar.questTemp.CapBloodLine.iTime = -1;

		break;

        case "DStep_2":

            dialog.text = DLG_TEXT_BL1[237];
        	link.l1 = DLG_TEXT_BL1[238];
            link.l1.go = "Exit_Away";
            Pchar.questTemp.CapBloodLine.sLocator = "houseSp1";
            Pchar.questTemp.CapBloodLine.iTime = -1;

		break;

        case "DStep_3":

            dialog.text = DLG_TEXT_BL1[239];
        	link.l1 = DLG_TEXT_BL1[240];
            link.l1.go = "DStep_4";

		break;

        case "DStep_4":

            dialog.text = DLG_TEXT_BL1[241];
        	link.l1 = DLG_TEXT_BL1[242];
            link.l1.go = "Exit";
            GiveItem2Character(Pchar, "migraine_potion");
            NextDiag.TempNode = "DStep_5";
            AddQuestRecord("WeaponsForEscape", "13");

		break;

        case "DStep_5":

            dialog.text = DLG_TEXT_BL1[243];
        	link.l1 = DLG_TEXT_BL1[244];
            link.l1.go = "Exit";
            NextDiag.TempNode = "DStep_5";

		break;

		//--> Джереми Питт

		 case "PStep_0":

            dialog.text = DLG_TEXT_BL1[245];
        	link.l1 = DLG_TEXT_BL1[246];
            link.l1.go = "PStep_1";

		break;

        case "PStep_1":

            dialog.text = DLG_TEXT_BL1[247];
        	link.l1 = DLG_TEXT_BL1[248];
        	link.l1.go = "PStep_2";  //(+ небольшой % авторитета)
        	link.l2 = DLG_TEXT_BL1[249];
        	link.l2.go = "PStep_3";

		break;

        case "PStep_2":

            dialog.text = DLG_TEXT_BL1[250];
        	link.l1 = DLG_TEXT_BL1[251];
            link.l1.go = "Exit";
            //AddCharacterExpToSkill(pchar, "LeaderShip", 50);
            NextDiag.TempNode = "PStep_4";
            Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape";
            Pchar.questTemp.CapBloodLine.statcrew = "find";
            Pchar.questTemp.CapBloodLine.Officer = 0;
            AddQuestRecord("CapBloodLine_q2", "5");
            AddQuestRecord("WeaponsForEscape", "1");

		break;

        case "PStep_3":

            dialog.text = DLG_TEXT_BL1[252];
        	link.l1 = DLG_TEXT_BL1[253];
            link.l1.go = "Exit";
            NextDiag.TempNode = "PStep_4";
            Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape";
            Pchar.questTemp.CapBloodLine.statcrew = "find";
            AddQuestRecord("CapBloodLine_q2", "5");
            AddQuestRecord("WeaponsForEscape", "1");
		break;

        case "PStep_4":

            if(CheckAttribute(Pchar, "questTemp.CapBloodLine.Officer") && Pchar.questTemp.CapBloodLine.Officer == 3 && Pchar.questTemp.CapBloodLine.stat == "ReadyToEscape")
            {
                dialog.text = DLG_TEXT_BL1[254];
                link.l1 = DLG_TEXT_BL1[255];
                link.l1.go = "PStep_9";
                while (GetCharacterItem(pchar,"Weapon_for_escape") > 0)//homo fix 06/02/08 отбираем все квестовое оружие
                {
                    TakeItemFromCharacter(Pchar, "Weapon_for_escape");
                }
                //link.l10 = DLG_TEXT_BL1[256];
                //link.l10.go = "finish";
                NextDiag.TempNode = "PStep_10";
                break;

            }
            dialog.text = DLG_TEXT_BL1[257];
        	link.l1 = DLG_TEXT_BL1[258];
            link.l1.go = "Exit";
            NextDiag.TempNode = "PStep_4";
		break;

        case "PStep_5":

            dialog.text = DLG_TEXT_BL1[259];
        	link.l1 = DLG_TEXT_BL1[260];
            link.l1.go = "PStep_6";
            //NextDiag.TempNode = "SStep_4";

		break;

        case "PStep_6":

            dialog.text = DLG_TEXT_BL1[261];
        	link.l1 = DLG_TEXT_BL1[262];
            link.l1.go = "Exit_RunAway";
			//кладем ключ на стол
			sld = ItemsFromID("key_pitt");
			sld.shown = true;
			sld.startLocation = "Estate";
			sld.startLocator = "item1";

            Pchar.questTemp.CapBloodLine.sLocator = "reload2";
            Pchar.questTemp.CapBloodLine.iTime = 5;
            AddDialogExitQuest("Blood9");
		break;

        case "PStep_7":

            dialog.text = DLG_TEXT_BL1[263];
        	link.l1 = DLG_TEXT_BL1[264];
            link.l1.go = "PStep_8";
        break;

        case "PStep_8":
            dialog.text = DLG_TEXT_BL1[265];
        	link.l1 = DLG_TEXT_BL1[266];
            link.l1.go = "Exit_Away";
            Pchar.questTemp.CapBloodLine.sLocator = "reload1";
            Pchar.questTemp.CapBloodLine.iTime = -1;
            NextDiag.TempNode = "First time";
            Pchar.questTemp.CapBloodLine.stat = "";
            chrDisableReloadToLocation = false;
            //AddDialogExitQuestFunction("ChangePIRATES");
		break;

        case "PStep_9":

            NextDiag.CurrentNode = NextDiag.TempNode;
            DialogExit();
       //     CapBloodLine_q2_Complited();

		break;

        case "PStep_10":

            dialog.text = DLG_TEXT_BL1[267];
        	link.l1 = DLG_TEXT_BL1[268];
            link.l1.go = "Exit";
            NextDiag.TempNode = "PStep_10";

		break;

        case "PStep_11":

            dialog.text = DLG_TEXT_BL1[269];
        	link.l1 = DLG_TEXT_BL1[270];
            link.l1.go = "PStep_12";

		break;

        case "PStep_12":

            dialog.text = DLG_TEXT_BL1[271];
        	link.l1 = DLG_TEXT_BL1[272];
            link.l1.go = "PStep_13";

		break;

        case "PStep_13":

            dialog.text = DLG_TEXT_BL1[273];
        	link.l1 = DLG_TEXT_BL1[274];
            link.l1.go = "PStep_14";

		break;

        case "PStep_14":

            dialog.text = DLG_TEXT_BL1[275];
        	link.l1 = DLG_TEXT_BL1[276];
            link.l1.go = "Exit";
            NextDiag.TempNode = "PStep_15";
            chrDisableReloadToLocation = false;
           	LAi_group_SetHearRadius("TmpEnemy", LAI_GROUP_GRD_HEAR - 3);
   	        LAi_group_SetSayRadius("TmpEnemy", LAI_GROUP_GRD_SAY - 1);
   	        LAi_group_SetLookRadius("TmpEnemy", LAI_GROUP_GRD_LOOK - 1);
            AddQuestRecord("EscapeFormBarbados", "2");

		break;

        case "PStep_15":

            dialog.text = DLG_TEXT_BL1[277];
        	link.l1 = DLG_TEXT_BL1[278];
            link.l1.go = "Exit";
            NextDiag.TempNode = "PStep_15";

		break;

        case "PStep_16":

            dialog.text = DLG_TEXT_BL1[279];
        	link.l1 = DLG_TEXT_BL1[280];
            link.l1.go = "PStep_17";

		break;

        case "PStep_17":

            dialog.text = DLG_TEXT_BL1[281];
        	link.l1 = DLG_TEXT_BL1[282];
            link.l1.go = "PStep_18";

		break;

        case "PStep_18":

            dialog.text = DLG_TEXT_BL1[283];
        	link.l1 = DLG_TEXT_BL1[284];
            link.l1.go = "PStep_19";

		break;

        case "PStep_19":

            dialog.text = DLG_TEXT_BL1[285];
        	link.l1 = "";
            link.l1.go = "Exit_RunAway";
            Pchar.questTemp.CapBloodLine.sLocator = "reloadShip";
            Pchar.questTemp.CapBloodLine.iTime = 3;

        	NPChar.Money   = 0;
        	NPChar.Payment = true;
       		NPChar.DontClearDead = true;

            AddPassenger(pchar, NPChar, false);

         /*    Pchar.Ship.Type = GenerateShip(SHIP_ARABELLA, true);
            Pchar.Ship.name=DLG_TEXT_BL1[286];
            SetBaseShipData(Pchar);
            Pchar.Ship.Cannons.Type = CANNON_TYPE_CANNON_LBS32;
            SetCrewQuantity(Pchar, GetMinCrewQuantity(Pchar));

            SetCharacterGoods(Pchar,GOOD_FOOD,70);
        	SetCharacterGoods(Pchar,GOOD_BALLS,300);//2000);
            SetCharacterGoods(Pchar,GOOD_GRAPES,100);//700);
            SetCharacterGoods(Pchar,GOOD_KNIPPELS,100);//700);
            SetCharacterGoods(Pchar,GOOD_BOMBS,200);//1500);
            SetCharacterGoods(Pchar,GOOD_POWDER,500);
//            SetCharacterGoods(Pchar,GOOD_PLANKS,10);
//            SetCharacterGoods(Pchar,GOOD_RUM,40);//600);
            SetCharacterGoods(Pchar,GOOD_WEAPON,50);//2000);

            n = FindLocation("Bridgetown_town");

            locations[n].reload.ship1.name = "reloadShip";
            locations[n].reload.ship1.go = "Barbados";
            locations[n].reload.ship1.emerge = "reload_1";
            locations[n].reload.ship1.autoreload = "1";
            locations[n].reload.ship1.label = "Sea";

            Pchar.location.from_sea = "Bridgetown_town";
            setWDMPointXZ("Bridgetown_town");

            string sQuest = "CapBloodLaspEpisode";
            pchar.quest.(sQuest).win_condition.l1 = "EnterToSea";
            pchar.quest.(sQuest).win_condition = "CapBloodLaspEpisode";
            pchar.quest.(sQuest).function = "CapBloodLaspEpisode"; */

            //AddDialogExitQuestFunction("SpaCrewAtack");


		break;

		//-->оружейние Гриффин

        case "GRStep_0":

            dialog.text = DLG_TEXT_BL1[287];
        	link.l1 = DLG_TEXT_BL1[288];
            link.l1.go = "GRStep_1";

		break;

        case "GRStep_1":

            dialog.text = DLG_TEXT_BL1[289];
        	link.l1 = DLG_TEXT_BL1[290];
            link.l1.go = "GRStep_2";
        	link.l2 = DLG_TEXT_BL1[291];
            link.l2.go = "GRStep_3";
		break;

        case "GRStep_2":

            AddQuestRecord("WeaponsForEscape", "4");
            dialog.text = DLG_TEXT_BL1[292];
            link.l1.go = "Exit";
            pchar.quest.PrepareToEscape2.win_condition.l1          = "location";
            pchar.quest.PrepareToEscape2.win_condition.l1.location = "Bridgetown_town";
            pchar.quest.PrepareToEscape2.function                  = "LoginSpain_spy";
        	Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape2";

		break;
        case "GRStep_3":

            dialog.text = DLG_TEXT_BL1[293];
        	link.l1 = DLG_TEXT_BL1[294];
            link.l1.go = "GRStep_2";
            NextDiag.TempNode = "GRStep_2";
           	link.l2 = DLG_TEXT_BL1[295];
            link.l2.go = "GRStep_4";

		break;
        case "GRStep_4":

            dialog.text = DLG_TEXT_BL1[296];
        	link.l1 = DLG_TEXT_BL1[297];
            link.l1.go = "GRStep_5";

		break;

        case "GRStep_5":

            dialog.text = DLG_TEXT_BL1[298];
        	link.l1 = DLG_TEXT_BL1[299];
            link.l1.go = "GRStep_6";

		break;

        case "GRStep_6":

            dialog.text = DLG_TEXT_BL1[300];
        	link.l1 = DLG_TEXT_BL1[301];
            link.l1.go = "GRStep_7_1";
           	link.l2 = DLG_TEXT_BL1[302];
            link.l2.go = "GRStep_7_2";

           /*  sld = GetCharacter(NPC_GenerateCharacter("Spain_spy", "shipowner_13", "man", "man", 7, ENGLAND, -1, false));
            sld.dialog.filename = "Quest\CapBloodLine\Bishop.c";
            sld.name = "";
            sld.lastname = DLG_TEXT_BL1[303];
            GiveItem2Character(sld, "Griffins_Weapon");
            sld.SaveItemsForDead = true; // сохранять на трупе вещи
            sld.DontClearDead = true;
            LAi_SetActorTypeNoGroup(sld);
            LAi_ActorSetLayMode(sld);
            LAi_SetImmortal(sld, true);
			ChangeCharacterAddressGroup(sld, "CommonRoom_MH2", "goto","goto2");
            //#20190120-02
            LocatorReloadEnterDisable("BridgeTown_town", "houseF1", false);
            sld = &characters[GetCharacterIndex("Hells")];
            LAi_SetActorTypeNoGroup(sld);
            LAi_ActorDialog(sld, pchar, "", 1.0, 0); */

		break;

        case "GRStep_7_1":

            dialog.text = DLG_TEXT_BL1[304];
        	link.l1 = DLG_TEXT_BL1[305];
            link.l1.go = "Exit";
            Pchar.questTemp.CapBloodLine.iMoney = 1500;
            NextDiag.TempNode = "GRStep_8";
			Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape1_1";
            AddQuestRecord("WeaponsForEscape", "3");
       //     AddQuestUserData("WeaponsForEscape", "iMoney", 1500);

		break;

        case "GRStep_7_2":

            dialog.text = DLG_TEXT_BL1[306];
        	link.l1 = DLG_TEXT_BL1[307];
            link.l1.go = "Exit";
            Pchar.questTemp.CapBloodLine.iMoney = 1000;
            NextDiag.TempNode = "GRStep_8";
			Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape1_1";
            AddQuestRecord("WeaponsForEscape", "3");
          //  AddQuestUserData("WeaponsForEscape", "iMoney", 1000);

		break;

        case "GRStep_8":

            dialog.text = DLG_TEXT_BL1[308];
            if (GetCharacterItem(pchar,"Griffins_Weapon") > 0)
            {
            	link.l1 = DLG_TEXT_BL1[309];
                link.l1.go = "GRStep_9";
                TakeItemFromCharacter(Pchar, "Griffins_Weapon");
            }
            else
            {
            	link.l1 = DLG_TEXT_BL1[310];
                link.l1.go = "Exit";
                NextDiag.TempNode = "GRStep_8";
            }

		break;

        case "GRStep_9":

            dialog.text = DLG_TEXT_BL1[311];
            if (makeint(pchar.money) >= sti(Pchar.questTemp.CapBloodLine.iMoney))
            {
           	    link.l1 = DLG_TEXT_BL1[312];
                link.l1.go = "Exit";
                AddMoneyToCharacter(pchar, (-sti(Pchar.questTemp.CapBloodLine.iMoney)));
                Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape1_3";
                NextDiag.TempNode = "GRStep_12";
            }
            else
            {
           	    link.l1 = DLG_TEXT_BL1[313];
                link.l1.go = "Exit";
                NextDiag.TempNode = "GRStep_13";
            }
            //Pchar.questTemp.CapBloodLine.GriffinTime = GetHour();
            SaveCurrentQuestDateParam("questTemp.CapBloodLine.GriffinTime");
            AddQuestRecord("WeaponsForEscape", "6");

		break;

        case "GRStep_10":

            dialog.text = DLG_TEXT_BL1[314];
        	link.l1 = DLG_TEXT_BL1[315];
            link.l1.go = "GRStep_11";

		break;

        case "GRStep_11":

            dialog.text = DLG_TEXT_BL1[316];
        	link.l1 = "";
            link.l1.go = "Exit";
            pchar.quest.PrepareToEscape2.win_condition.l1          = "location";
            pchar.quest.PrepareToEscape2.win_condition.l1.location = "Bridgetown_town";
            pchar.quest.PrepareToEscape2.function                  = "LoginSpain_spy";
        	Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape2";


		break;

        case "GRStep_12":

            if (Pchar.questTemp.CapBloodLine.stat == "PrepareToEscape1_3" && GetQuestPastTimeParam("questTemp.CapBloodLine.GriffinTime") >= 1)
            {
                dialog.text = DLG_TEXT_BL1[317];
                link.l1 = DLG_TEXT_BL1[318];
                link.l1.go = "Exit";
                GiveItem2Character(Pchar, "Weapon_for_escape");
                NextDiag.TempNode = "First time";
          		CloseQuestHeader("WeaponsForEscape");
                Pchar.questTemp.CapBloodLine.stat = "ReadyToEscape";
            }
            else
            {
                dialog.text = DLG_TEXT_BL1[319];
                link.l1 = DLG_TEXT_BL1[320];
                link.l1.go = "Exit";
                NextDiag.TempNode = "GRStep_12";

            }

		break;

        case "GRStep_13":

            dialog.text = DLG_TEXT_BL1[321];
            if (makeint(pchar.money) >= sti(Pchar.questTemp.CapBloodLine.iMoney))
            {
                link.l1 = DLG_TEXT_BL1[322];
                link.l1.go = "Exit";
                NextDiag.TempNode = "GRStep_12";
                AddMoneyToCharacter(pchar, (-sti(Pchar.questTemp.CapBloodLine.iMoney)));
                Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape1_3";
            }
            else
            {
           	    link.l1 = DLG_TEXT_BL1[323];
                link.l1.go = "Exit";
                NextDiag.TempNode = "GRStep_13";
            }


		break;

        case "GRStep_14":

            dialog.text = DLG_TEXT_BL1[324];
        	link.l1 = DLG_TEXT_BL1[325];
            link.l1.go = "GRStep_15";

		break;

        case "GRStep_15":

            dialog.text = DLG_TEXT_BL1[326];
        	link.l1 = DLG_TEXT_BL1[327];
            link.l1.go = "GRStep_16";

		break;

        case "GRStep_16":

            dialog.text = DLG_TEXT_BL1[328];
        	link.l1 = DLG_TEXT_BL1[329];
            link.l1.go = "GRStep_17";

		break;

        case "GRStep_17":

            dialog.text = DLG_TEXT_BL1[330];
        	link.l1 = DLG_TEXT_BL1[331];
            link.l1.go = "Exit";

            GiveItem2Character(Pchar, "Weapon_for_escape");
            AddQuestRecord("WeaponsForEscape", "9");
       		CloseQuestHeader("WeaponsForEscape");
            Pchar.questTemp.CapBloodLine.stat = "ReadyToEscape";
            NextDiag.TempNode = "First time";

		break;


        //-->рыбак Хелльс

        case "HStep_0":

            dialog.text = DLG_TEXT_BL1[332];
        	link.l1 = DLG_TEXT_BL1[333];
            link.l1.go = "HStep_1";

		break;

        case "HStep_1":

            dialog.text = DLG_TEXT_BL1[334];
        	link.l1 = DLG_TEXT_BL1[335];
            link.l1.go = "HStep_2";

		break;

        case "HStep_2":

            dialog.text = DLG_TEXT_BL1[336];
        	link.l1 = DLG_TEXT_BL1[337];
            link.l1.go = "HStep_3";

		break;

        case "HStep_3":

            dialog.text = DLG_TEXT_BL1[338];
        	link.l1 = DLG_TEXT_BL1[339];
            link.l1.go = "HStep_4";
            NextDiag.TempNode = "First time";
            Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape1_2";
		break;

        case "HStep_4":

            NextDiag.CurrentNode = NextDiag.TempNode;
            sTemp = GetNationNameByType(ENGLAND) + "_citizens";
            LAi_group_MoveCharacter(NPChar, sTemp);
            LAi_SetCitizenTypeNoGroup(Npchar);
            DialogExit();
         //   Spain_spyDie("");
		break;

        case "HStep_5":

            dialog.text = DLG_TEXT_BL1[340];
        	link.l1 = DLG_TEXT_BL1[341];
            link.l1.go = "HStep_6";

		break;

        case "HStep_6":

            dialog.text = DLG_TEXT_BL1[342];
        	link.l1 = DLG_TEXT_BL1[343];
            link.l1.go = "HStep_7";
           	link.l2 = DLG_TEXT_BL1[344];
            link.l2.go = "Exit";
            NextDiag.TempNode = "HStep_8";
		break;

        case "HStep_7":

            AddQuestRecord("FishermanQuest", "1");
            sld = &characters[GetCharacterIndex("Fisherman")];
            sld.dialog.currentnode = "FStep_1";
            NextDiag.TempNode = "HStep_9";
            NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

		break;

        case "HStep_8":

            dialog.text = DLG_TEXT_BL1[345];
        	link.l1 = DLG_TEXT_BL1[346];
            link.l1.go = "HStep_7";
           	link.l2 = DLG_TEXT_BL1[347];
            link.l2.go = "Exit";
            NextDiag.TempNode = "HStep_8";

		break;

        case "HStep_9":

            dialog.text = DLG_TEXT_BL1[348];
            if(CheckAttribute(Pchar, "questTemp.CapBloodLine.fishplace"))
            {
            	link.l1 = DLG_TEXT_BL1[349];
                link.l1.go = "HStep_10";
            }
            else
            {
            	link.l1 = DLG_TEXT_BL1[350];
                link.l1.go = "Exit";
                NextDiag.TempNode = "HStep_9";
            }

		break;

        case "HStep_10":

            dialog.text = DLG_TEXT_BL1[351];
        	link.l1 = DLG_TEXT_BL1[352];//+Pchar.questTemp.CapBloodLine.fishplace;
            link.l1.go = "HStep_11";

		break;

        case "HStep_11":

            dialog.text = DLG_TEXT_BL1[353];
        	link.l1 = DLG_TEXT_BL1[354];
            link.l1.go = "Exit";
            NextDiag.TempNode = "First time";
            AddMoneyToCharacter(pchar, 2000);
       		CloseQuestHeader("FishermanQuest");
		break;


        //-->Испанский шпион

        case "SSStep_0":

            dialog.text = DLG_TEXT_BL1[355];
        	link.l1 = DLG_TEXT_BL1[356];
            link.l1.go = "SSStep_1";
           	link.l2 = DLG_TEXT_BL1[357];
            link.l2.go = "SSStep_2";
            Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape2_1";
            chrDisableReloadToLocation = false;
            LocatorReloadEnterDisable("BridgeTown_town", "houseSp2", true);

		break;

        case "SSStep_1":

            dialog.text = DLG_TEXT_BL1[358];
        	link.l1 = "";
            link.l1.go = "Exit_Away";
            Pchar.questTemp.CapBloodLine.sLocator = "houseSp2";
            Pchar.questTemp.CapBloodLine.iTime = 20;
            AddQuestRecord("WeaponsForEscape", "7");

		break;

        case "SSStep_2":

            dialog.text = DLG_TEXT_BL1[359];
        	link.l1 = DLG_TEXT_BL1[360];
            link.l1.go = "Exit_Away";
            Pchar.questTemp.CapBloodLine.sLocator = "houseSp2";
            Pchar.questTemp.CapBloodLine.iTime = 20;
            AddQuestRecord("WeaponsForEscape", "7");

		break;

        case "SSStep_3":

            dialog.text = DLG_TEXT_BL1[361];
        	link.l1 = DLG_TEXT_BL1[362];
            link.l1.go = "SSStep_4";
		break;

        case "SSStep_4":

            dialog.text = DLG_TEXT_BL1[363];
        	link.l1 = DLG_TEXT_BL1[364];
            link.l1.go = "fight";
            sld = &characters[GetCharacterIndex("Griffin")];
            sld.dialog.currentnode = "GRStep_14";

		break;

		//--> Контрабандист

        case "QSStep_0":

            dialog.text = DLG_TEXT_BL1[365];
        	link.l1 = DLG_TEXT_BL1[366];
            link.l1.go = "QSStep_1";
		break;

        case "QSStep_1":

            dialog.text = DLG_TEXT_BL1[367];
        	link.l1 = DLG_TEXT_BL1[368];
            link.l1.go = "QSStep_2";
		break;

        case "QSStep_2":

            dialog.text = DLG_TEXT_BL1[369];
        	link.l1 = DLG_TEXT_BL1[370];
            link.l1.go = "QSStep_3";

		break;

        case "QSStep_3":

            dialog.text = DLG_TEXT_BL1[371];
        	link.l1 = DLG_TEXT_BL1[372];
            link.l1.go = "QSStep_4";

		break;

        case "QSStep_4":

            dialog.text = DLG_TEXT_BL1[373];
        	link.l1 = DLG_TEXT_BL1[374];
            link.l1.go = "QSStep_5";

		break;

        case "QSStep_5":

            dialog.text = DLG_TEXT_BL1[375];
        	link.l1 = DLG_TEXT_BL1[376];
            link.l1.go = "Exit";
            NextDiag.TempNode = "QSStep_6";

            sld = &characters[GetCharacterbyLocation("Bridgetown_town", "soldiers", "soldier2")];
            sld.dialog.filename = "Quest\CapBloodLine\Bishop.c";
            sld.Dialog.CurrentNode = "GStep_1";
            sld.protector = true;
            sld.protector.CheckAlways = 1 ;
            LocatorReloadEnterDisable("BridgeTown_town", "reload3_back", true);
            LocatorReloadEnterDisable("Bridgetown_Townhall", "reload3", true);
            LocatorReloadEnterDisable("BridgeTown_town", "reloadR1", true);

            sld = characterFromID("MisStid");
            sld.Dialog.CurrentNode = "MSStep_3";
        	sld.talker = 10;
            ChangeCharacterAddressGroup(sld, "Bridgetown_TownhallRoom", "barmen","bar1");

            sld = characterFromID("Den");
            LAi_SetCitizenTypeNoGroup(sld);
            sld.Dialog.CurrentNode = "DStep_3";
			ChangeCharacterAddressGroup(sld, "CommonPirateHouse", "goto","goto6");

            sld = ItemsFromID("MsStid_ring");
			sld.shown = true;
			sld.startLocation = "Bridgetown_TownhallRoom";
			sld.startLocator = "item1";

            pchar.quest.PrepareToEscape3.win_condition.l1          = "location";
            pchar.quest.PrepareToEscape3.win_condition.l1.location = "Bridgetown_TownhallRoom";
            pchar.quest.PrepareToEscape3.function                  = "FindMsStid_ring";
			AddQuestRecord("WeaponsForEscape", "11");
            Pchar.questTemp.CapBloodLine.stat = "PrepareToEscape3";

		break;


        case "QSStep_6":

            if (GetCharacterItem(pchar,"MsStid_ring") > 0)
			{
                dialog.text = DLG_TEXT_BL1[377];
                link.l1 = DLG_TEXT_BL1[378];
    			link.l1.go = "QSStep_7";
                link.l2 = DLG_TEXT_BL1[379];
    			link.l2.go = "QSStep_12";
			}
			else
			{
                dialog.text = DLG_TEXT_BL1[380];
            	link.l1 = DLG_TEXT_BL1[381];
                link.l1.go = "Exit";
                NextDiag.TempNode = "QSStep_6";
            }

		break;

        case "QSStep_7":

            dialog.text = DLG_TEXT_BL1[382];
        	link.l1 = DLG_TEXT_BL1[383];
            link.l1.go = "QSStep_8";

		break;

        case "QSStep_8":

            dialog.text = DLG_TEXT_BL1[384];
        	link.l1 = DLG_TEXT_BL1[385];
            link.l1.go = "QSStep_10";

		break;

        case "QSStep_10":

            dialog.text = DLG_TEXT_BL1[386];
        	link.l1 = DLG_TEXT_BL1[387];
            link.l1.go = "QSStep_11";
            TakeItemFromCharacter(Pchar, "MsStid_ring");

		break;

        case "QSStep_11":

            dialog.text = DLG_TEXT_BL1[388];
        	link.l1 = DLG_TEXT_BL1[389];
            link.l1.go = "Exit";
            NextDiag.TempNode = "First time";
            GiveItem2Character(Pchar, "Weapon_for_escape");
            NextDiag.TempNode = "First time";
       		CloseQuestHeader("WeaponsForEscape");
            AddMoneyToCharacter(pchar, 3000);
            AddQuestRecord("WeaponsForEscape", "16");
            CloseQuestHeader("WeaponsForEscape");
            Pchar.questTemp.CapBloodLine.stat = "ReadyToEscape";

		break;

        case "QSStep_12":

            dialog.text = DLG_TEXT_BL1[390];
        	link.l1 = DLG_TEXT_BL1[391];
            link.l1.go = "Exit";
            NextDiag.TempNode = "First time";
            GiveItem2Character(Pchar, "Weapon_for_escape");
            NextDiag.TempNode = "First time";
       		CloseQuestHeader("WeaponsForEscape");
            AddMoneyToCharacter(pchar, 3000);
            TakeItemFromCharacter(Pchar, "MsStid_ring");
            AddQuestRecord("WeaponsForEscape", "16");
            CloseQuestHeader("WeaponsForEscape");
            Pchar.questTemp.CapBloodLine.stat = "ReadyToEscape";

		break;

        //--> Натаниэль Хагторп

        case "HTStep_0":

            dialog.text = DLG_TEXT_BL1[392];
        	link.l1 = DLG_TEXT_BL1[393];
            link.l1.go = "HTStep_1";

		break;

        case "HTStep_1":

            dialog.text = DLG_TEXT_BL1[394];
        	link.l1 = DLG_TEXT_BL1[395];
            link.l1.go = "HTStep_2";

		break;

        case "HTStep_2":

            dialog.text = DLG_TEXT_BL1[396];
        	link.l1 = DLG_TEXT_BL1[397];
            link.l1.go = "HTStep_3";

		break;

        case "HTStep_3":

            dialog.text = DLG_TEXT_BL1[398];
        	link.l1 = DLG_TEXT_BL1[399];
            link.l1.go = "HTStep_4";

		break;

        case "HTStep_4":

            dialog.text = DLG_TEXT_BL1[400];
        	link.l1 = DLG_TEXT_BL1[401];
            link.l1.go = "HTStep_5";

		break;

        case "HTStep_5":

            dialog.text = DLG_TEXT_BL1[402];
        	link.l1 = DLG_TEXT_BL1[403];
            link.l1.go = "HTStep_13";
            NextDiag.TempNode = "HTStep_10";
        	link.l2 = DLG_TEXT_BL1[404];
            link.l2.go = "HTStep_6";
		break;

        case "HTStep_6":

            dialog.text = DLG_TEXT_BL1[405];
        	link.l1 = DLG_TEXT_BL1[406];
            link.l1.go = "HTStep_7";

		break;

        case "HTStep_7":

            dialog.text = DLG_TEXT_BL1[407];
        	link.l1 = DLG_TEXT_BL1[408];
            link.l1.go = "HTStep_13";
           	link.l2 = DLG_TEXT_BL1[409];
            link.l2.go = "HTStep_8";
            NextDiag.TempNode = "HTStep_10";

		break;

        case "HTStep_8":

            dialog.text = DLG_TEXT_BL1[410];
            if(Pchar.SPECIAL.Charisma >= 5)
            {
            	link.l0 = DLG_TEXT_BL1[411];
                link.l0.go = "HTStep_9";
            }
            else
            {
        //        AddCharacterExpToSkill(pchar, "LeaderShip", 50);
            }
           	link.l1 = DLG_TEXT_BL1[412];
            link.l1.go = "HTStep_13";

		break;

        case "HTStep_9":

            dialog.text = DLG_TEXT_BL1[413];
        	link.l1 = DLG_TEXT_BL1[414];
            link.l1.go = "Exit";
          //  AddCharacterExpToSkill(pchar, "LeaderShip", 150);
            NextDiag.TempNode = "HTStep_12";
            Pchar.questTemp.CapBloodLine.Hugtorp = true;
            Pchar.questTemp.CapBloodLine.Officer = sti(Pchar.questTemp.CapBloodLine.Officer)+1;
            AddQuestRecord("HugtorpTrouble", "2");
            CloseQuestHeader("HugtorpTrouble");

		break;
        case "HTStep_10":

            dialog.text = DLG_TEXT_BL1[415];
            if (GetCharacterItem(pchar,"DOjeronRing") > 0)
            {
                link.l1 = DLG_TEXT_BL1[416];
                link.l1.go = "HTStep_11";
                TakeItemFromCharacter(Pchar, "DOjeronRing");
       //         ref itm = ItemsFromID("DOjeronRing"); //возвращаем все как было
          //      BackItemName("DOjeronRing");
           //     BackItemDescribe("DOjeronRing");
         //       itm.picIndex = 2;
         //       itm.picTexture = "ITEMS_9";
            }
            else
            {
                link.l1 = DLG_TEXT_BL1[417];
                link.l1.go = "Exit";
                NextDiag.TempNode = "HTStep_10";
            }
		break;

        case "HTStep_11":

            dialog.text = DLG_TEXT_BL1[418];
        	link.l1 = DLG_TEXT_BL1[419];
            link.l1.go = "Exit";
            NextDiag.TempNode = "HTStep_12";
            Pchar.questTemp.CapBloodLine.Hugtorp = true;
            Pchar.questTemp.CapBloodLine.Officer = sti(Pchar.questTemp.CapBloodLine.Officer)+1;
            AddQuestRecord("HugtorpTrouble", "4");
            CloseQuestHeader("HugtorpTrouble");

		break;

        case "HTStep_12":

            dialog.text = DLG_TEXT_BL1[420];
        	link.l1 = DLG_TEXT_BL1[421];
            link.l1.go = "Exit";
            NextDiag.TempNode = "HTStep_12";

		break;

        case "HTStep_13":

       //     LoginWinterwood();
            AddQuestRecord("HugtorpTrouble", "1");
            NextDiag.CurrentNode = "HTStep_10";
			DialogExit();

		break;

        case "HTStep_14":

            dialog.text = DLG_TEXT_BL1[422];
        	link.l1 = DLG_TEXT_BL1[423];
            link.l1.go = "HTStep_15";
            chrDisableReloadToLocation = false;

		break;

        case "HTStep_15":

            dialog.text = DLG_TEXT_BL1[424];
        	link.l1 = DLG_TEXT_BL1[425];
            link.l1.go = "HTStep_16";



		break;

        case "HTStep_16":

            dialog.text = DLG_TEXT_BL1[426];
        	link.l1 = DLG_TEXT_BL1[427];
            link.l1.go = "HTStep_17";

		break;

        case "HTStep_17":

            dialog.text = DLG_TEXT_BL1[428];
        	link.l1 = DLG_TEXT_BL1[429];
            link.l1.go = "Exit";
            //AddDialogExitQuestFunction("ReturnToPlantation3");
            AddQuestRecord("EscapeFormBarbados", "1");

		break;

        case "HTStep_18":

            dialog.text = DLG_TEXT_BL1[430];
            if(Pchar.questTemp.CapBloodLine.SpainInBridgetown == false)
            {
               	link.l1 = DLG_TEXT_BL1[431];
                link.l1.go = "HTStep_19";
            }
            else
            {
               	link.l1 = DLG_TEXT_BL1[432];
                link.l1.go = "HTStep_20";
            }
		break;

        case "HTStep_19":

            dialog.text = DLG_TEXT_BL1[433];
        	link.l1 = DLG_TEXT_BL1[434];
            link.l1.go = "HTStep_20";
            AddQuestRecord("EscapeFormBarbados", "3");

		break;

        case "HTStep_20":

            dialog.text = DLG_TEXT_BL1[435];
        	link.l1 = DLG_TEXT_BL1[436];
            link.l1.go = "HTStep_21";

		break;

        case "HTStep_21":

            dialog.text = DLG_TEXT_BL1[437];
        	link.l1 = DLG_TEXT_BL1[438];
            link.l1.go = "HTStep_22";

		break;

        case "HTStep_22":

            dialog.text = DLG_TEXT_BL1[439];
        	link.l1 = DLG_TEXT_BL1[440];
            link.l1.go = "Exit";
            //AddDialogExitQuestFunction("CapBloodOfficers");
            AddQuestRecord("EscapeFormBarbados", "4");
            NextDiag.TempNode = "HTStep_22b";

		break;

        case "HTStep_22b":

            dialog.text = DLG_TEXT_BL1[441];
        	link.l1 = DLG_TEXT_BL1[442];
            link.l1.go = "Exit";
            NextDiag.TempNode = "HTStep_22b";
            //AddDialogExitQuestFunction("CapBloodOfficers");

		break;

        case "HTStep_23":

            dialog.text = DLG_TEXT_BL1[443];
        	link.l1 = DLG_TEXT_BL1[444];
            link.l1.go = "HTStep_22";

		break;

        case "HTStep_24":

            dialog.text = DLG_TEXT_BL1[445];
        	link.l1 = DLG_TEXT_BL1[446];
            link.l1.go = "HTStep_25";

		break;

        case "HTStep_25":

            dialog.text = DLG_TEXT_BL1[447];
        	link.l1 = DLG_TEXT_BL1[448];
            link.l1.go = "Exit_RunAway";
            Pchar.questTemp.CapBloodLine.sLocator = "reloadShip";
            Pchar.questTemp.CapBloodLine.iTime = 3;

		break;

        //--> Николас Дайк

        case "DKStep_0":

            dialog.text = DLG_TEXT_BL1[449];
        	link.l1 = DLG_TEXT_BL1[450];
            link.l1.go = "DKStep_1";

		break;

        case "DKStep_1":

            dialog.text = DLG_TEXT_BL1[451];
        	link.l1 = DLG_TEXT_BL1[452];
            link.l1.go = "exit";
            NextDiag.TempNode = "DKStep_2";
            sld = characterFromID("Bishop");
            sld.Dialog.CurrentNode = "BStep_2";
            AddQuestRecord("DiekeQuest", "1");
		break;

        case "DKStep_2":

            dialog.text = DLG_TEXT_BL1[453];
        	link.l1 = DLG_TEXT_BL1[454];
            link.l1.go = "exit";
            NextDiag.TempNode = "DKStep_2";
		break;

        case "DKStep_3":

            dialog.text = DLG_TEXT_BL1[455];
        	link.l1 = DLG_TEXT_BL1[456];
            link.l1.go = "exit";
            Pchar.questTemp.CapBloodLine.Dieke = true;
            Pchar.questTemp.CapBloodLine.Officer = sti(Pchar.questTemp.CapBloodLine.Officer)+1;
            NextDiag.TempNode = "DKStep_4";
            CloseQuestHeader("DiekeQuest");

		break;

        case "DKStep_4":

            dialog.text = DLG_TEXT_BL1[457];
        	link.l1 = DLG_TEXT_BL1[458];
            link.l1.go = "exit";
            NextDiag.TempNode = "DKStep_4";

		break;

        case "DKStep_5":

            dialog.text = DLG_TEXT_BL1[459];
        	link.l1 = DLG_TEXT_BL1[460];
            link.l1.go = "DKStep_6";

		break;

        case "DKStep_6":

            dialog.text = DLG_TEXT_BL1[461];
        	link.l1 = DLG_TEXT_BL1[462];
            link.l1.go = "Exit_RunAway";
            Pchar.questTemp.CapBloodLine.sLocator = "reloadShip";
            Pchar.questTemp.CapBloodLine.iTime = 3;

		break;

        //--> Нед Огл

        case "OGLStep_0":

            dialog.text = DLG_TEXT_BL1[463];
        	link.l1 = DLG_TEXT_BL1[464];
            link.l1.go = "OGLStep_1";

		break;

        case "OGLStep_1":

            dialog.text = DLG_TEXT_BL1[465];
        	link.l1 = DLG_TEXT_BL1[466];
            link.l1.go = "OGLStep_2";
		break;

        case "OGLStep_2":

            dialog.text = DLG_TEXT_BL1[467];
        	link.l1 = DLG_TEXT_BL1[468];
            link.l1.go = "OGLStep_3";
		break;

        case "OGLStep_3":

            dialog.text = DLG_TEXT_BL1[469];
        	link.l1 = DLG_TEXT_BL1[470];
            link.l1.go = "OGLStep_4";
		break;

        case "OGLStep_4":

            dialog.text = DLG_TEXT_BL1[471];
        	link.l1 = DLG_TEXT_BL1[472];
            link.l1.go = "OGLStep_5";
		break;

        case "OGLStep_5":

            dialog.text = DLG_TEXT_BL1[473];
        	link.l1 = DLG_TEXT_BL1[474];
            link.l1.go = "OGLStep_6";
		break;


        case "OGLStep_6":

            dialog.text = DLG_TEXT_BL1[475];
        	link.l1 = DLG_TEXT_BL1[476];
            link.l1.go = "OGLStep_7";
		break;

        case "OGLStep_7":

            dialog.text = DLG_TEXT_BL1[477];
        	link.l1 = DLG_TEXT_BL1[478];
            link.l1.go = "Exit";
            NextDiag.TempNode = "OGLStep_8";
            Pchar.questTemp.CapBloodLine.Ogl = false;
            AddQuestRecord("OglQuest", "1");

		break;

        case "OGLStep_8":

            if(CheckAttribute(Pchar, "questTemp.CapBloodLine.Ogl") && Pchar.questTemp.CapBloodLine.Ogl == true)
            {
                dialog.text = DLG_TEXT_BL1[479];
            	link.l1 = DLG_TEXT_BL1[480];
                link.l1.go = "OGLStep_9";
            }
            else
            {
                NextDiag.TempNode = "OGLStep_8";
                dialog.text = DLG_TEXT_BL1[481];
            	link.l1 = DLG_TEXT_BL1[482];
                link.l1.go = "Exit";
                NextDiag.TempNode = "OGLStep_8";
            }
		break;

        case "OGLStep_9":

            dialog.text = DLG_TEXT_BL1[483];
        	link.l1 = DLG_TEXT_BL1[484];
            link.l1.go = "exit";
            Pchar.questTemp.CapBloodLine.Ogl = true;
            Pchar.questTemp.CapBloodLine.Officer = sti(Pchar.questTemp.CapBloodLine.Officer)+1;
            NextDiag.TempNode = "OGLStep_10";
            AddQuestRecord("OglQuest", "3");
            CloseQuestHeader("OglQuest");

		break;

        case "OGLStep_10":

            dialog.text = DLG_TEXT_BL1[485];
        	link.l1 = DLG_TEXT_BL1[486];
            link.l1.go = "exit";
            NextDiag.TempNode = "OGLStep_10";

		break;

        case "OGLStep_11":

            dialog.text = DLG_TEXT_BL1[487];
        	link.l1 = DLG_TEXT_BL1[488];
            link.l1.go = "OGLStep_12";

		break;

        case "OGLStep_12":

            dialog.text = DLG_TEXT_BL1[489];
        	link.l1 = DLG_TEXT_BL1[490];
            link.l1.go = "OGLStep_13";

		break;

        case "OGLStep_13":

            dialog.text = DLG_TEXT_BL1[491];
        	link.l1 = DLG_TEXT_BL1[492];
            link.l1.go = "Exit_RunAway";
            Pchar.questTemp.CapBloodLine.sLocator = "reloadShip";
            Pchar.questTemp.CapBloodLine.iTime = 3;

        	NPChar.Money   = 0;
        	NPChar.Payment = true;
       		NPChar.DontClearDead = true;

            AddPassenger(pchar, NPChar, false);
            //AddDialogExitQuestFunction("OglAdd");

		break;

	}
}
