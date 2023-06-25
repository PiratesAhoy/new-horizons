//#include "DIALOGS\Oxbay Cutler_Beckett_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	int Itest;

	int iNation;
	string sNation;
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iDay + " " + iMonth;

	string stemp = "";
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	trace ("----------------------------------" + Dialog.CurrentNode);	
	switch(Dialog.CurrentNode)

	{
		// -----------------------------------Диалог первый - первая встреча
			
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Dialog_stay2";
			Dialog.cam = "1";

			Dialog.mood = "normal";
			PlaySound("VOICE\ENGLISH\Beckett02.wav");
			
			d.Text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "First Time_talk";
			if (CheckQuestAttribute("Beckett", "start")) AddDialogExitQuest("Beckett_talk_1"); // KK
//			if(CheckQuestAttribute("Beckett", "Beckett_first_time_Redmond"))
			if(CheckQuestAttribute("Beckett", "Payment_for_Escort"))
			{
				Locations[FindLocation("EITC_Office")].reload.l1.disable = 1;
				dialog.text = DLG_TEXT[44] + Pchar.lastname + DLG_TEXT[42];
				link.l1 = DLG_TEXT[63];
				link.l1.go = "And_now_an_Offer";
			}
			if(CheckQuestAttribute("Beckett", "First_mission_reckoning"))
			{
				//Locations[FindLocation("EITC_Office")].reload.l1.disable = 0;
				dialog.text = DLG_TEXT[44] + Pchar.lastname + DLG_TEXT[45];;
				Link.l1 = DLG_TEXT[46];
				Link.l1.go = "The_First_Reckoning";
			}
			if(CheckQuestAttribute("Beckett", "Beckett_on_the_beach"))
			{
				dialog.text = DLG_TEXT[85] + pchar.lastname + DLG_TEXT[177];
				Link.l1 = DLG_TEXT[178];
				Link.l1.go = "Meeting_in_Greenford_Tavern";
			}
			if(CheckQuestAttribute("Beckett", "Talk_about_Africa_run"))
			{
				dialog.text = DLG_TEXT[44] + pchar.lastname + DLG_TEXT[187];
				Link.l1 = DLG_TEXT[188];
				Link.l1.go = "Talk_about_Africa_run2";
				iTest = iTest + 1;
			}
			if(CheckQuestAttribute("henry_talk", "not_taking_Interceptor"))
			{
				dialog.text = DLG_TEXT[22] + " " + pchar.lastname + DLG_TEXT[235];
				link.l1 = DLG_TEXT[236];
				link.l1.go = "talk_of_war";
			}
		break;

		case "First Time_talk":
			SetQuestHeader("Beckett");
			d.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4];
			Link.l1.go = "Beckett_talk_2";
		break;

		case "Beckett_talk_2":
			d.Text = DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "Beckett_talk_3";
		break;
			
		case "Beckett_talk_3":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Beckett_talk_4";
		break;

		case "Beckett_talk_4":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Beckett_talk_5";
		break;

		case "Beckett_talk_5":
			dialog.text = DLG_TEXT[11] + Pchar.lastname + DLG_TEXT[12];
			link.l1 = DLG_TEXT[13] + GetMyFullName(PChar) + DLG_TEXT[14];
			link.l1.go = "Beckett_talk_6"; // will go
			Link.l2 = DLG_TEXT[23];
			Link.l2.go = "Beckett_talk_10"; // wont go
		break;

		case "Beckett_talk_6": // will go
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "Beckett_talk_7";
		break;

		case "Beckett_talk_7":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "Beckett_talk_8";
		break;

		case "Beckett_talk_8":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Beckett_talk_9";
		break;

		case "Beckett_talk_9":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "Exit_Joined_EITC";
		break;

		case "Exit_Joined_EITC":
			pchar.quest.Jacks_early_days = "Jacks_first_run_Beckett";
			SetQuestHeader("Beckett");
			AddQuestRecord("Beckett",2);
			ChangeCharacterReputation(pchar, +5);
			AddMoneyToCharacter(pchar, +10000);
			DialogExit();
			AddDialogExitQuest("Beckett_Leaves_Oxbay");
		break;

		case "Beckett_talk_10": // wont go
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Exit_not_joining";
		break;

		case "Exit_not_joining":
			SetQuestHeader("Beckett");
			AddQuestRecord("Beckett",1);
			DialogExit();
			AddDialogExitQuest("Beckett_Leaves_Oxbay_NOT_Joining");
		break;

		case "And_now_an_Offer":
			AddMoneyToCharacter(pchar, +5000);
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "And_now_an_Offer2";
			link.l2 = DLG_TEXT[49];
			link.l2.go = "DISMISSED";
		break;

		case "DISMISSED":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Exit_DISMISSED";
		break;

		case "Exit_DISMISSED":
			AddQuestRecord("Beckett",9);
			LAi_SetSitType(characterfromID("Silas Simpkins"));
			Locations[FindLocation("EITC_Office")].reload.l1.disable = 0;
			Diag.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("On_my_own_no_EITC");
		break;

		case "And_now_an_Offer2":
			pchar.originalmoney = pchar.money; // PB: Actual profit required
			AddMoneyToCharacter(pchar, +10000);
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "And_now_an_Offer3";
		break;

		case "And_now_an_Offer3":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "And_now_an_Offer4";
		break;

		case "And_now_an_Offer4":
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "Exit_And_now_an_Offer";
		break;

		case "Exit_And_now_an_Offer":
			AddQuestRecord("Beckett",12);
			Locations[FindLocation("EITC_Office")].reload.l1.disable = 0;
			Diag.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("Doing_the_First_Mission");
		break;		
		
		case "The_First_Reckoning":
			PlayStereoSound("INTERFACE\took_item.wav");
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			// PB: Actual profit required -->
			if (sti(pchar.money) - sti(pchar.originalmoney) >= 50000)
				link.l1.go = "Reckoning_best_result";
			if (sti(pchar.money) - sti(pchar.originalmoney) <= 49999 && sti(pchar.money) - sti(pchar.originalmoney) >= 15000)
				link.l1.go = "Reckoning_second_result";
			if (sti(pchar.money) - sti(pchar.originalmoney) <= 14999 && sti(pchar.money) - sti(pchar.originalmoney) >= 12000)
				link.l1.go = "Reckoning_third_result";
			if (sti(pchar.money) - sti(pchar.originalmoney) <= 11999)
				link.l1.go = "Reckoning_Failure";
			// PB: Actual profit required <--
		break;

		case "Reckoning_best_result":
			ChangeCharacterReputation(pchar, +6);
			AddMoneyToCharacter(pchar, -50000);
			if(HasThisShip("Black Pearl"))
			{
				dialog.text = DLG_TEXT[275];
				link.l1 = DLG_TEXT[276];
				link.l1.go = "Reckoning_best_result2_no_ship";
			}
			else
			{
				dialog.text = DLG_TEXT[62];
				link.l1 = DLG_TEXT[61];
				link.l1.go = "Reckoning_best_result2";
			}
		break;

		case "Reckoning_best_result2":
			dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "Reckoning_best_result3";
		break;

		case "Reckoning_best_result2_no_ship":
			dialog.text = DLG_TEXT[274];
			link.l1 = DLG_TEXT[277];
			link.l1.go = "Reckoning_best_result3";
		break;

		case "Reckoning_best_result3":
			AddMoneyToCharacter(pchar, +5000);
			GiveItem2Character(Pchar,"EITC_Passport");
			PlayStereoSound("INTERFACE\took_item.wav");
			dialog.text = DLG_TEXT[98];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "Reckoning_best_result4";
		break;

		case "Reckoning_best_result4":
			dialog.text = DLG_TEXT[81] + Pchar.lastname + DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "Exit_the_best_Reckoning";
		break;

		case "Exit_the_best_Reckoning":
			LAi_SetSitType(characterfromID("Silas Simpkins"));
			Diag.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("prepare_for_Antigua_run");
		break;

		case "Reckoning_second_result":
			ChangeCharacterReputation(pchar, +3);
			AddMoneyToCharacter(pchar, -15000);
			dialog.text = DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "Reckoning_second_result2";
		break;

		case "Reckoning_second_result2":
			dialog.text = DLG_TEXT[75];
			link.l1 = DLG_TEXT[76];
			link.l1.go = "Reckoning_second_result3";
		break;

		case "Reckoning_second_result3":
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[79];
			link.l1.go = "Reckoning_second_result4";
		break;

		case "Reckoning_second_result4":
			AddMoneyToCharacter(pchar, +4000);
			dialog.text = DLG_TEXT[80];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "Exit_Reckoning_second";
		break;

		case "Exit_Reckoning_second":
			AddQuestRecord("Beckett",13);
			LAi_SetSitType(characterfromID("Silas Simpkins"));
			Locations[FindLocation("EITC_Office")].reload.l1.disable = 0;
			Diag.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("Doing_the_Rescue_Mission");
		break;

		case "Reckoning_third_result":
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "Reckoning_third_result2";
		break;		

		case "Reckoning_third_result2":
			dialog.text = DLG_TEXT[88];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "Exit_third_result";
		break;

		case "Exit_third_result":
			pchar.money = 10000;
			LAi_SetSitType(characterfromID("Silas Simpkins"));
			Locations[FindLocation("EITC_Office")].reload.l1.disable = 0;
			Diag.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("Doing_the_First_Mission");
		break;
		
		case "Reckoning_Failure":
			ChangeCharacterReputation(pchar, -5);
			dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "Reckoning_Failure2";
		break;

		case "Reckoning_Failure2":
			dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[107];
			link.l1.go = "Exit_Failure";
		break;

		case "Muelle Reckoning and ship":
			AddMoneyToCharacter(pchar, 10000);
			dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "Reckoning_best_result2";
		break;

		case "Exit_Failure":
			pchar.money = 1000;
			LAi_SetSitType(characterfromID("Silas Simpkins"));
			Locations[FindLocation("EITC_Office")].reload.l1.disable = 0;
			Diag.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("Failed_the_Mission");
		break;

		case "Lazy_Captured_on_Oxbay":
			dialog.text = DLG_TEXT[220] + GetMyFullName(Pchar) + DLG_TEXT[221];
			link.l1 = DLG_TEXT[222];
			link.l1.go = "Lazy_Captured_on_Oxbay2";
		break;

		case "Lazy_Captured_on_Oxbay2":
			dialog.text = DLG_TEXT[262];
			link.l1 = DLG_TEXT[226];
			link.l1.go = "Lazy_Captured_on_Oxbay3";
		break;

		case "Lazy_Captured_on_Oxbay3":
			dialog.text = DLG_TEXT[263];
			link.l1 = DLG_TEXT[264];
			link.l1.go = "Exit_Lazy_Captured";
		break;

		case "Captured_on_Oxbay2":
			dialog.text = DLG_TEXT[210] + pchar.lastname + DLG_TEXT[211];
			Link.l1 = DLG_TEXT[212];
			Link.l1.go = "Captured_on_Oxbay3";
		break;

		case "Captured_on_Oxbay3":
			dialog.text = DLG_TEXT[213];
			Link.l1 = DLG_TEXT[214];
			Link.l1.go = "Captured_on_Oxbay4";
		break;

		case "Captured_on_Oxbay4":
			dialog.text = DLG_TEXT[215];
			Link.l1 = DLG_TEXT[216];
			Link.l1.go = "exit_captured_on_Oxbay";
		break;

		case "Captured_on_Oxbay5":
			locCameraRight(NPChar); // a simple virtual sailor
			Ship_Detonate(pchar, true, false);
			Ship_Detonate(pchar, true, false);
			Ship_Detonate(pchar, true, false);
			Ship_Detonate(pchar, true, false);
			dialog.text = DLG_TEXT[220] + GetMyName(PChar) + DLG_TEXT[221];
			Link.l1 = DLG_TEXT[222];
			Link.l1.go = "Captured_on_Oxbay6";
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
		break;

		case "Captured_on_Oxbay6":
			dialog.text = DLG_TEXT[223];
			Link.l1 = DLG_TEXT[224];
			Link.l1.go = "Captured_on_Oxbay7";
		break;

		case "Captured_on_Oxbay7":
			dialog.text = DLG_TEXT[225];
			Link.l1 = DLG_TEXT[226];
			Link.l1.go = "Captured_on_Oxbay9";
		break;

		case "Captured_on_Oxbay9":
			dialog.text = DLG_TEXT[227];
			Link.l1 = DLG_TEXT[228];
			Link.l1.go = "Captured_on_Oxbay10";
		break;

		case "Captured_on_Oxbay10":
			dialog.text = DLG_TEXT[229];
			Link.l1 = DLG_TEXT[230];
			Link.l1.go = "Captured_on_Oxbay2";
		break;

		case "talk_of_war":
			dialog.text = DLG_TEXT[237];
			Link.l1 = DLG_TEXT[238];
			Link.l1.go = "talk_of_war2";
			Link.l2 = DLG_TEXT[239];
			Link.l2.go = "fight_talk_of_war";
		break;

		case "fight_talk_of_war":
			dialog.text = DLG_TEXT[240];
			Link.l1 = DLG_TEXT[241];
			Link.l1.go = "exit_talk_of_war";
		break;

		case "talk_of_war2":
			dialog.text = DLG_TEXT[242];
			Link.l1 = DLG_TEXT[243];
			Link.l1.go = "talk_of_war3";
		break;

		case "talk_of_war3":
			dialog.text = DLG_TEXT[244];
			Link.l1 = DLG_TEXT[245];
			Link.l1.go = "talk_of_war4";
		break;

		case "talk_of_war4":
			dialog.text = DLG_TEXT[246] + PChar.lastname + DLG_TEXT[247];
			Link.l1 = DLG_TEXT[248];
			Link.l1.go = "talk_of_war5";
		break;

		case "talk_of_war5":
			dialog.text = DLG_TEXT[249];
			Link.l1 = DLG_TEXT[250];
			Link.l1.go = "talk_of_war6";
		break;

		case "talk_of_war6":
			dialog.text = DLG_TEXT[251];
			Link.l1 = DLG_TEXT[252];
			Link.l1.go = "talk_of_war7";
		break;

		case "talk_of_war7":
			dialog.text = DLG_TEXT[253];
			Link.l1 = DLG_TEXT[254];
			Link.l1.go = "exit_Norrington_talk_of_French";
		break;

		case "Oxbay_meet_after_Brin":
			PlaySound("VOICE\ENGLISH\Beckett02.wav");
			//SetQuestHeader("Beckett");
			d.Text = DLG_TEXT[0];
			pchar.quest.Jacks_early_days = "Jacks_first_run_Beckett";
			if (GetAttribute(PChar, "Beckett") == "Join_later")
			{
				link.l1 = DLG_TEXT[271];
				link.l1.go = "Oxbay_meet_after_Mings3";
			}
			else
			{
				link.l1 = DLG_TEXT[1];
				link.l1.go = "Oxbay_meet_after_Brin2";
			}
		break;

		case "Oxbay_meet_after_Brin2":
			SetQuestHeader("Beckett");
			d.Text = DLG_TEXT[2];
			link.l1 = Link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4];
			link.l1.go = "Oxbay_meet_after_Mings3";
		break;

		case "Oxbay_meet_after_Mings":
			SetQuestHeader("Beckett");
			d.Text = DLG_TEXT[26] + GetMyFullName(PChar) + DLG_TEXT[27];
			link.l1 = DLG_TEXT[28] + GetMyFullName(PChar) + DLG_TEXT[29];
			link.l1.go = "Oxbay_meet_after_Mings2";
		break;

		case "Oxbay_meet_after_Mings2":
			d.Text = DLG_TEXT[30];
			Link.l1 = DLG_TEXT[31];
			Link.l1.go = "Oxbay_meet_after_Mings3";	
		break;

		case "Oxbay_meet_after_Mings3":
			d.Text = DLG_TEXT[32];
			Link.l1 = DLG_TEXT[33];
			Link.l1.go = "Oxbay_meet_after_Mings4";	
		break;

		case "Oxbay_meet_after_Mings4":
			dialog.text = DLG_TEXT[34];
			Link.l1 = DLG_TEXT[35];
			Link.l1.go = "Oxbay_meet_after_Mings5";
		break;

		case "Oxbay_meet_after_Mings5":
			dialog.text = DLG_TEXT[36];
			Link.l1 = DLG_TEXT[37];
			Link.l1.go = "Oxbay_meet_after_Mings6";
		break;

		case "Oxbay_meet_after_Mings6":
			dialog.text = DLG_TEXT[38];
			Link.l1 = DLG_TEXT[39];
			Link.l1.go = "exitto_Jamaica_Escort";
		break;

		case "exitto_Jamaica_Escort":
			if (GetAttribute(PChar, "Beckett") == "Join_later")
			{
				AddQuestRecord("Beckett",19);
			}
			else
			{
				AddQuestRecord("Beckett",6);
			}
			HoistFlag(PERSONAL_NATION); // PB: To show Beckett EITC flag
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Cutler Beckett"));
			SetCharacterRemovable(characterFromID("Cutler Beckett"), false);
			setCharacterShipLocation(characterFromID("Cutler Beckett"), "Oxbay_port");
			NPChar.quest.meeting = lastspeak_date;
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("First_run_Jamaica_with_Beckett");
		break;

		case "Redmond_meet_after_Mings":
			RemoveCharacterCompanion(pchar, characterFromID("Cutler Beckett"));  // TALISMAN to remove Becketts Ship as Companion at P Royale after escort
			PlaySound("VOICE\ENGLISH\Beckett02.wav");
			dialog.text = DLG_TEXT[40];
			Link.l1 = DLG_TEXT[41];
			Link.l1.go = "Exit_Redmond_meet_after_Mings";
		break;

		case "Exit_Redmond_meet_after_Mings":
			DialogExit();
			AddDialogExitQuest("Beckett_to_make_payment");
		break;		

		case "Redmond_meet_after_Mings2":
			AddMoneyToCharacter(pchar, 3000);
			dialog.text = DLG_TEXT[95];
			Link.l1 = DLG_TEXT[65];
			Link.l1.go = "Redmond_meet_after_Mings3";
			Link.l2 = DLG_TEXT[32];
			Link.l2.go = "Redmond_meet_after_Mings_OVER";
		break;

		case "Redmond_meet_after_Mings3":
			if(HasThisShip("Black Pearl"))
			{
				dialog.text = DLG_TEXT[274];
			}
			else
			{
				GiveShip2Character(pchar, "WickedWench", "Wicked Wench",-1,ENGLAND,true,true);
				PChar.quest.wench_given_by = "Beckett";
				dialog.text = DLG_TEXT[96];
			}
			Link.l1 = DLG_TEXT[97];
			Link.l1.go = "Redmond_meet_after_Mings4";
		break;

		case "Redmond_meet_after_Mings4":
			AddMoneyToCharacter(pchar, 50000);
			dialog.text = DLG_TEXT[98];
			Link.l1 = DLG_TEXT[78];
			Link.l1.go = "Redmond_meet_after_Mings5";
		break;

		case "Redmond_meet_after_Mings5":
			dialog.text = DLG_TEXT[40] + GetMyFullName(Pchar) + DLG_TEXT[41];
			Link.l1 = DLG_TEXT[80];
			Link.l1.go = "Redmond_meet_after_Mings6";
		break;

		case "Redmond_meet_after_Mings6":
			GiveItem2Character(Pchar,"EITC_Passport");
			dialog.text = DLG_TEXT[259];
			Link.l1 = DLG_TEXT[195];
			Link.l1.go = "Redmond_meet_after_Mings7";
		break;

		case "Redmond_meet_after_Mings7":
			dialog.text = DLG_TEXT[88];
			Link.l1 = DLG_TEXT[83];
			Link.l1.go = "Exit_Redmond_meet_after_Mings";
		break;

		case "Redmond_meet_after_Mings_OVER":
			dialog.text = DLG_TEXT[35];
			Link.l1 = DLG_TEXT[42];
			Link.l1.go = "Exit_Redmond_not_go_after_Mings";
		break;

		case "False Colours":
			dialog.text = DLG_TEXT[266];
			Link.l1 = DLG_TEXT[267];
			Link.l1.go = "False Colours2";
		break;

		case "False Colours2":
			dialog.text = DLG_TEXT[268];
			Link.l1 = DLG_TEXT[269];
			Link.l1.go = "False Colours3";
		break;

		case "False Colours3":
			dialog.text = DLG_TEXT[270];
			Link.l1.go = "exit";
			AddDialogExitQuest("Mercer_False_die_talk3");
		break;

		// PB -->
		case "On_your_way":
			dialog.text = DLG_TEXT[272];
			link.l1 = DLG_TEXT[273];
			Link.l1.go = "exit_on_your_way";
		break;

		case "exit_on_your_way":
			Diag.CurrentNode = "On_your_way";
			DialogExit();
		break;
		// PB <--

// EXITS: >>
		case "exit":
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Silehardtypeexit":
			DialogExit();
			AddDialogExitQuest("Return_with_idols_to_Beckett");
		break;

		case "canyonexit":
			DialogExit();
			AddDialogExitQuest("Beckett_Canyon_walkoff");
		break;

		case "Inprisonexit":
			DialogExit();
			AddDialogExitQuest("Beckett_Goodbye");
		break;

		case "originalredmondexit":
			DialogExit();
			AddDialogExitQuest("Beckett_Goodbye");
		break;

		case "decisiontimeexit":
			DialogExit();
			AddDialogExitQuest("DecisionTime");
		break;

		case "deliverquestexit":
			DialogExit();
			AddDialogExitQuest("More_Gold_ready");
		break;

		case "exitafterdeliveringidols":
			Diag.CurrentNode = "First time";
			DialogExit();
			AddDialogExitQuest("get_ready_for_Africa");
		break;

		case "exittosave the slaves":
			NPChar.quest.meeting = lastspeak_date;
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("Save_the_Slaves");
		break;

		case "Exit_Redmond_not_go_after_Mings":
			DialogExit();
			AddDialogExitQuest("Not_ready_to_sail_to_Antigua");
		break;

		case "go see governor exit":
			DialogExit();
			AddDialogExitQuest("Going_to_Governor");
		break;

		case "Beckett_troop_escort_exit":
			DialogExit();
			AddDialogExitQuest("going_to_Governor_escort");
		break;

		case "deliver gold exit":
			DialogExit();
			AddDialogExitQuest("Beckett_Goodbye");
		break;

		case "lostgoldexitwar":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("lost_gold_exit_war");
		break;

		case "lostgoldexit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("lost_gold_exit");
		break;

		case "originalOxbay_exit":
			DialogExit();
			AddDialogExitQuest("Beckett_Leaves_Oxbay");
		break;

		case "exit_talk_of_war":
			DialogExit();
			AddDialogExitQuest("Beckett_Norrington_fight");
		break;

		case "exit_Norrington_talk_of_French":
			DialogExit();
			AddDialogExitQuest("Norrington_splutters");
		break;

		case "exit_captured_on_Oxbay":
			Pchar.quest.sunk_wench.win_condition.l1 = "ExitFromLocation";
			Pchar.quest.sunk_wench.win_condition.l1.location = "Oxbay_lighthouse";
			Pchar.quest.sunk_wench.win_condition = "sunk_wench";
			DialogExit();
			AddDialogExitQuest("before_storm");
		break;

		case "Exit_Lazy_Captured":
			DialogExit();
			AddDialogExitQuest("Deserters Jail");
		break;
	}
}
