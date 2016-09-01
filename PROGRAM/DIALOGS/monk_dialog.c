void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

    string blade;
    string gun;

	PChar.NoSave.ThisMonk = NPChar.id;
	if (CheckAttribute(PChar,"NoSave.LastMonk") && PChar.NoSave.LastMonk != PChar.NoSave.ThisMonk )
	{
//---> PW once monks have got to relic choice case skip early dialogue / shared dialogue file
		if (CheckAttribute(PChar,"NoSave.CarryRelic") && PChar.NoSave.CarryRelic != "none")
		{
			NextDiag.CurrentNode = "Next time after select_relic";
		}
		if (CheckAttribute(PChar,"NoSave.CarryRelic") && PChar.NoSave.CarryRelic == "none")
		{
			NextDiag.CurrentNode = "Next time after reject_relic";
		}
	}
  // <--- PW end - once monks have got to relic case skip early dialogue / shared dialogue file	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			Dialog.defAni     = "dialog_stay1";
			Dialog.defCam     = "1";
			Dialog.defSnd     = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani        = "dialog_stay2";
			Dialog.cam        = "1";
			Dialog.snd        = "voice\PAVA\PAVA001";

			NextDiag.TempNode = "First time";        
			Dialog.Text = DLG_TEXT[0];
// --> SJG
			if (CheckQuestAttribute("henry_talk", "henry_quest_gotidols"))
			{
				LAi_SetActorType(characterFromID("Yusuf Rais"));
				Link.L1 = DLG_TEXT[80];
				link.l1.go = "Beckett found second time";
			}
			if (CheckQuestAttribute("henry_talk", "henry_quest_chat2"))  
			{
				Link.L1 = DLG_TEXT[57];
				link.l1.go = "Beckett found";
			}								
			if (!CheckQuestAttribute("henry_talk", "henry_quest_chat2") && !CheckQuestAttribute("henry_talk", "henry_quest_gotidols"))  // <-- SJG                                                       
			{
				Link.l1     = DLG_TEXT[1];
				Link.l1.go  = "how_should_a_monk_look_like";
				Link.l2     = DLG_TEXT[2];
				Link.l2.go  = "exit_pay";
			}
		break;

        case "how_should_a_monk_look_like":
			Dialog.Text = DLG_TEXT[3];
            Link.l1     = DLG_TEXT[4];
            Link.l1.go  = "look_like_answer_ok";
            Link.l2     = DLG_TEXT[5];
            Link.l2.go  = "look_like_answer_uncertain";
            Link.l3     = DLG_TEXT[6];
            Link.l3.go  = "look_like_answer_dull";
		break;

        case "look_like_answer_uncertain":
			NextDiag.TempNode = "Next time after look_like_answer_uncertain";
			Dialog.Text = DLG_TEXT[7];
            Link.l1     = DLG_TEXT[8];
            Link.l1.go  = "exit";
		break;

        case "Next time after look_like_answer_uncertain":
			NextDiag.TempNode = "Next time after look_like_answer_uncertain";
			Dialog.Text = DLG_TEXT[9];
            Link.l1     = DLG_TEXT[4];
            Link.l1.go  = "look_like_answer_ok";
            Link.l2     = DLG_TEXT[10];
            Link.l2.go  = "look_like_answer_uncertain";
            Link.l3     = DLG_TEXT[6];
            Link.l3.go  = "look_like_answer_dull";
		break;

        case "look_like_answer_dull":
			NextDiag.TempNode = "Next time after look_like_answer_dull";
			Dialog.Text = DLG_TEXT[11];
            Link.l1     = DLG_TEXT[12];
            Link.l1.go  = "exit";
            if(GetCharacterEquipByGroup(&PChar, BLADE_ITEM_TYPE) != "bladeX4") // PB: Can't threaten monk with fists equiped (and can't have them stolen)
            {
				Link.l2     = DLG_TEXT[13];
				Link.l2.go  = "answer_dull_steal_weapon_1";
            }

		break;

        case "Next time after look_like_answer_dull":
			Dialog.Text = DLG_TEXT[14];
            Link.l1     = DLG_TEXT[15];
            Link.l1.go  = "apologizes_accepted";
		break;

        case "apologizes_accepted":

		// ccc fix oct06, give weapons back
		if (IsCharacterEquipByGroup(NPChar,BLADE_ITEM_TYPE))
		{
			blade = GetCharacterEquipByGroup(NPChar,BLADE_ITEM_TYPE);
			RemoveCharacterEquip(NPChar, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(NPChar, blade);
			GiveItem2Character(PChar, blade);
			EquipCharacterByItem(PChar, blade);
		}
		if (IsCharacterEquipByGroup(NPChar,GUN_ITEM_TYPE))
		{
			gun = GetCharacterEquipByGroup(NPChar,GUN_ITEM_TYPE);
			RemoveCharacterEquip(NPChar, GUN_ITEM_TYPE);
			TakeItemFromCharacter(NPChar, gun);
			GiveItem2Character(PChar, gun);
			EquipCharacterByItem(PChar, gun);
			// ccc, returning of ammo left out deliberately, the ammostealing never worked in the first place anyway
		}
		// ccc end

			Dialog.Text = DLG_TEXT[16];
            Link.l1     = DLG_TEXT[4];
            Link.l1.go  = "look_like_answer_ok";
            Link.l2     = DLG_TEXT[5];
            Link.l2.go  = "look_like_answer_uncertain";
		break;

        case "answer_dull_steal_weapon_1":
			Dialog.Text = DLG_TEXT[17];
            Link.l1     = DLG_TEXT[18];
            Link.l1.go  = "answer_dull_steal_weapon_2";
		break;

        case "answer_dull_steal_weapon_2":
            if (IsCharacterEquipByGroup(PChar,BLADE_ITEM_TYPE))
            {
                blade = GetCharacterEquipByGroup(PChar,BLADE_ITEM_TYPE);
                RemoveCharacterEquip(PChar, BLADE_ITEM_TYPE);
                TakeItemFromCharacter(PChar, blade);
    		    GiveItem2Character(NPChar, blade);
    		    EquipCharacterByItem(NPChar, blade);
            }
            if (IsCharacterEquipByGroup(PChar,GUN_ITEM_TYPE))
            {
                gun = GetCharacterEquipByGroup(PChar,GUN_ITEM_TYPE);
                RemoveCharacterEquip(PChar, GUN_ITEM_TYPE);
                TakeItemFromCharacter(PChar, gun);
    		    GiveItem2Character(NPChar, gun);
    		    EquipCharacterByItem(NPChar, gun);

				//JRH ammo mod -->
				if (ENABLE_AMMOMOD) {	// LDH change
					if(gun == "pistolmket")
					{
						TakenItems(NPChar, "gunpowder", 2 + rand(2));
						TakenItems(NPChar, "musketbullets", 1 + rand(1));
					}
					if(gun == "pistolbbuss" || gun == "pistolmtoon" || gun == "pistol3")
					{
						TakenItems(NPChar, "gunpowder", 2 + rand(2));
						TakenItems(NPChar, "pistolgrapes", 2 + rand(2));
					}
					if(gun == "pistol1" || gun == "pistol2" || gun == "pistol4" || gun == "pistol5" || gun == "pistol6" || gun == "pistol7" || gun == "pistol8" || gun == "pistol9")
					{
						TakenItems(NPChar, "gunpowder", 1 + rand(2));
						TakenItems(NPChar, "pistolbullets", 1 + rand(2));
					}
				}
  				//JRH ammo mod <--

    	    }
			NextDiag.TempNode = "Next time after look_like_answer_dull";
			Dialog.Text = DLG_TEXT[19];
            Link.l1     = DLG_TEXT[20];
            Link.l1.go  = "exit";
		break;

        case "look_like_answer_ok":
			Dialog.Text = DLG_TEXT[21];
            Link.l1     = DLG_TEXT[22];
            Link.l1.go  = "answer_ok_answer_dull";
            Link.l2     = DLG_TEXT[23];
            Link.l2.go  = "answer_ok_answer_clever";
            Link.l3     = DLG_TEXT[24];
            Link.l3.go  = "answer_ok_answer_ok_1";
		break;

        case "answer_ok_answer_dull":
			NextDiag.TempNode = "Next time after answer_ok_answer_not_ok";
			Dialog.Text = DLG_TEXT[25];
            Link.l1     = DLG_TEXT[26];
            Link.l1.go  = "exit";
		break;

        case "Next time after answer_ok_answer_not_ok":
			Dialog.Text = DLG_TEXT[27];
            Link.l1     = DLG_TEXT[22];
            Link.l1.go  = "answer_ok_answer_dull";
            Link.l2     = DLG_TEXT[23];
            Link.l2.go  = "answer_ok_answer_clever";
            Link.l3     = DLG_TEXT[24];
            Link.l3.go  = "answer_ok_answer_ok_1";
		break;

        case "answer_ok_answer_clever":
			NextDiag.TempNode = "Next time after answer_ok_answer_not_ok";
			Dialog.Text = DLG_TEXT[28];
            Link.l1     = DLG_TEXT[29];
            Link.l1.go  = "exit";
		break;

        case "answer_ok_answer_ok_1":
			Dialog.Text = DLG_TEXT[30];
            Link.l1     = DLG_TEXT[31];
            Link.l1.go  = "answer_ok_answer_ok_2";
		break;

        case "answer_ok_answer_ok_2":
			Dialog.Text = DLG_TEXT[32];
            Link.l1     = DLG_TEXT[33];
            Link.l1.go  = "answer_ok_answer_ok_3";
		break;

        case "answer_ok_answer_ok_3":
			Dialog.Text = DLG_TEXT[34];
            Link.l1     = DLG_TEXT[35];
            Link.l1.go  = "select_relic";
		break;

        case "select_relic":
			Dialog.Text = DLG_TEXT[36];
            Link.l1     = DLG_TEXT[37];
            Link.l1.go  = "select_relic_skills";
            Link.l2     = DLG_TEXT[38];
            Link.l2.go  = "select_relic_health";
            Link.l3     = DLG_TEXT[39];// PW choice re-enabled
            Link.l3.go  = "select_relic_help";// PW choice re-enabled
            Link.l4     = DLG_TEXT[40];
            Link.l4.go  = "reject_relic";
		break;


		case "select_relic_skills":
			NextDiag.TempNode = "Next time after select_relic";
			GiveItem2Character(PChar, "holycross1");
			PChar.NoSave.CarryRelic = "copper";
			PChar.NoSave.ReleaseMonkLocation = GetRandomLocation(NPChar.town);
			Dialog.Text = DLG_TEXT[41] + PChar.NoSave.ReleaseMonkLocation + ".";
			Link.l1     = DLG_TEXT[42];
			Link.l1.go  = "exit";
		break;

        case "select_relic_health":
			NextDiag.TempNode = "Next time after select_relic";
            GiveItem2Character(PChar, "holycross2");
            PChar.NoSave.CarryRelic = "silver";
			// NK 05-07-03
            PChar.NoSave.HealthPoint = PChar.chr_ai.hp_max;
			ChangeHPBonus(PChar, sti(PChar.NoSave.HealthPoint));
			// NK <--
            PChar.NoSave.ReleaseMonkLocation = GetRandomLocation(NPChar.town);
			Dialog.Text = DLG_TEXT[41] + PChar.NoSave.ReleaseMonkLocation + ".";
            Link.l1     = DLG_TEXT[42];
            Link.l1.go  = "exit";
		break;

        case "select_relic_help":
			NextDiag.TempNode = "Next time after select_relic";
            GiveItem2Character(PChar, "holycross3");
            PChar.NoSave.CarryRelic = "gold";
            PChar.NoSave.ReleaseMonkLocation = GetRandomLocation(NPChar.town);
			Dialog.Text = DLG_TEXT[41] + PChar.NoSave.ReleaseMonkLocation + ".";
            Link.l1     = DLG_TEXT[42];
            Link.l1.go  = "exit";
		break;

        case "reject_relic":
			NextDiag.TempNode = "Next time after reject_relic";
			Dialog.Text = DLG_TEXT[43];
            Link.l1     = DLG_TEXT[44];
            Link.l1.go  = "exit";
		break;

        case "Next time after reject_relic":
            if (CheckAttribute(NPChar,"faced") && NPChar.faced == true)
            {
                Dialog.Text = DLG_TEXT[45];
            }
            else
            {
                Dialog.Text = DLG_TEXT[46];
            }
            Link.l1     = DLG_TEXT[37];
            Link.l1.go  = "select_relic_skills";
            Link.l2     = DLG_TEXT[38];
            Link.l2.go  = "select_relic_health";
			Link.l3     = DLG_TEXT[39];// PW choice re-enabled
            Link.l3.go  = "select_relic_help";// PW choice re-enabled
            Link.l4     = DLG_TEXT[40];
            Link.l4.go  = "reject_relic";
		break;

        case "Next time after select_relic":
			if(PChar.NoSave.ReleaseMonkLocation == NPChar.town)
			{
				NextDiag.TempNode = "Next time after select_relic";
				NPChar.faced = true;
				PChar.NoSave.LastMonk = NPChar.id;

                Dialog.Text = DLG_TEXT[47];
                Link.l1     = DLG_TEXT[48];
                Link.l1.go  = "remove_relic";
                Link.l2     = DLG_TEXT[49];
                Link.l2.go  = "exit";
            }
            else
            {
				NextDiag.TempNode = "Next time after select_relic";
                Dialog.Text = DLG_TEXT[50] + PChar.NoSave.ReleaseMonkLocation + ".";
                Link.l1     = DLG_TEXT[51];
                Link.l1.go  = "exit";
            }
		break;

        case "remove_relic":
			NextDiag.TempNode = "Next time after reject_relic";
	        if (!CheckAttribute(PChar,"NoSave.CarryRelic"))
            {
                PChar.NoSave.CarryRelic = "none");
            }
			switch(PChar.NoSave.CarryRelic)
			{
                case "copper":
                    TakeItemFromCharacter(PChar, "holycross1");
              	break;
                  		 
                case "silver":
                    TakeItemFromCharacter(PChar, "holycross2");
					// NK 05-07-03
					ChangeHPBonus(PChar, -sti(PChar.NoSave.HealthPoint));
           	        // NK <--
              	break;
                  		 
                case "gold":
                    TakeItemFromCharacter(PChar, "holycross3");
              	break;
            }
            PChar.NoSave.CarryRelic = "none";
			Dialog.Text = DLG_TEXT[52];
            Link.l1     = DLG_TEXT[53];
            Link.l1.go  = "exit";
            Link.l2     = DLG_TEXT[54];
            Link.l2.go  = "exit";
            Link.l3     = DLG_TEXT[55];
            Link.l3.go  = "exit";
		break;
// --> SJG
		case "Beckett found":
			Dialog.Text = DLG_TEXT[56] + GetMySimpleName(PChar);
			Link.l1 = DLG_TEXT[60];
			Link.l1.go = "Beckett found2";
		break;

		case "Beckett found2":
			Dialog.Text = DLG_TEXT[58];
			Link.l1 = DLG_TEXT[59];
			Link.l1.go = "Beckett found3";
		break;

		case "Beckett found3":
			LAi_Fade("Beckett found3","");
			LAi_SetActorType(pchar);
			LAi_ActorSetSitMode(pchar);
			ChangeCharacterAddressGroup(pchar, "Conceicao_tavern", "sit", "sit8");
			Dialog.Text = DLG_TEXT[78];
			Link.l1 = DLG_TEXT[79];
			Link.l1.go = "Beckett found4";
		break;

		case "Beckett found4":
			Dialog.Text = DLG_TEXT[61];
			Link.l1 = DLG_TEXT[62];
			Link.l1.go = "Beckett found5";
		break;

		case "Beckett found5":
			Dialog.Text = DLG_TEXT[63];
			Link.l1 = DLG_TEXT[64];
			Link.l1.go = "Beckett found6";
		break;

		case "Beckett found6":
			Dialog.Text = DLG_TEXT[65] + pchar.lastname + DLG_TEXT[66];
			Link.l1 = DLG_TEXT[67];
			Link.l1.go = "Beckett found7";
		break;

		case "Beckett found7":
			Dialog.Text = DLG_TEXT[68];
			Link.l1 = DLG_TEXT[69];
			Link.l1.go = "Beckett found8";
		break;

		case "Beckett found8":
			Dialog.Text = DLG_TEXT[70];
			Link.l1 = DLG_TEXT[71];
			Link.l1.go = "Beckett found9";
		break;

		case "Beckett found9":
			Dialog.Text = DLG_TEXT[72];
			Link.l1 = DLG_TEXT[73];
			Link.l1.go = "Beckett found10";
		break;

		case "Beckett found10":
			Dialog.Text = DLG_TEXT[74];
			Link.l1 = DLG_TEXT[75];
			Link.l1.go = "Beckett found11";
			if (!CheckCharacterItem(Pchar,"Map_Doc_1"))
			{
				GiveItem2Character(Pchar,"Map_Doc_1");
			}
		break;

		case "Beckett found11":
			Lai_SetPlayerType(pchar);
			Dialog.Text = DLG_TEXT[76];
			Link.l1 = DLG_TEXT[77];
			Link.l1.go = "Beckettfoundexit";
		break;

		case "Beckettfoundexit":
			AddQuestRecord("And_now_Beckett_and_Beckett", 2);
			LAi_Fade("Beckettfoundexit","");
			ChangeCharacterAddressGroup(pchar, "Conceicao_tavern", "goto", "goto6");
			NextDiag.CurrentNode = "First time";
			DialogExit();			
		break;

		case "Beckett found second time":
			Dialog.Text = DLG_TEXT[81];
			Link.l1 = DLG_TEXT[82];
			Link.l1.go = "Beckett found second time2";
		break;
	

		case "Beckett found second time2":
			Dialog.Text = DLG_TEXT[83];
			Link.l1 = DLG_TEXT[84];
			Link.l1.go = "Beckett found second time3";
		break;

		case "Beckett found second time3":
			Dialog.Text = DLG_TEXT[85];
			Link.l1 = DLG_TEXT[86];
			Link.l1.go = "Beckett found second time4";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, +5000);
		break;

		case "Beckett found second time4":
			AddQuestRecord("And_now_Beckett_and_Beckett", 4);
			Dialog.Text = DLG_TEXT[87];
			Link.l1 = DLG_TEXT[88];
			Link.l1.go = "exit";
		break;

// <-- SJG

	   case "exit":
	        NPChar.faced = true;
            PChar.NoSave.LastMonk = NPChar.id;

			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

	   case "exit_pay":
		    PlayStereoSound("INTERFACE\took_item.wav");
	        AddMoneyToCharacter(PChar, -100);
	        AddMoneyToCharacter(NPChar, 100);
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
    }
}
