//#include "DIALOGS\baldewyn coffier_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

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
	
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;
	if(!CheckAttribute(NPChar, "quest.item_date")) NPChar.quest.item_date = NPChar.quest.meeting;
	Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy

	
	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "Sit_Right_Strong_Yes";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_stay1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Right_Dialog_1";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\BACO\BACO001";
			Preprocessor_Add("monsieur", GetCharacterAddressForm(NPChar, ADDR_CIVIL, false, false));
			Dialog.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
			if (npchar.quest.hire == "arno")
			{
				Link.l1 = pcharrepphrase(DLG_TEXT[2] + GetMyFullName(NPChar) + DLG_TEXT[3], DLG_TEXT[4] + GetMyFullName(NPChar) + DLG_TEXT[5]);
				Link.l1.go = "line_one";
			}
			if (npchar.quest.hire == "0" || npchar.quest.hire == "arno_denied") //Fix:Storekeeper;19.09
			{
				Link.l1 = pcharrepphrase(DLG_TEXT[6], DLG_TEXT[7]);
				Link.l1.go = "line_two";
			}
			if (npchar.quest.hire == "question_1_done")
			{
				link.l1 = DLG_TEXT[8];
				link.l1.go = "line_one_5";
			}
			if (npchar.quest.hire == "question_1_not_done")
			{
				link.l1 = DLG_TEXT[9];
				link.l1.go = "line_one_7";
			}
			if (npchar.quest.hire == "not_money_3")
			{
				link.l1 = DLG_TEXT[10];
				link.l1.go = "line_one_8";
			}
			if (npchar.quest.hire == "almost_done")
			{
				link.l1 = DLG_TEXT[11];
				link.l1.go = "work";
			}
			if (npchar.quest.hire == "almost_done_1")
			{
				link.l1 = DLG_TEXT[12] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[13])]) + DLG_TEXT[14];
				link.l1.go = "work_3";
				link.l2 = DLG_TEXT[12] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[13])]) + DLG_TEXT[15];
				link.l2.go = "hire_denied";
			}
			if (npchar.quest.hire == "money_31")
			{
				link.l1 = DLG_TEXT[16];
				link.l1.go = "work_3";
			}
			if (npchar.quest.hire == "hire_denied")
			{
				dialog.snd = "Voice\BACO\BACO002";
				dialog.text = DLG_TEXT[17];
				link.l1 = DLG_TEXT[18];
				link.l1.go = "work_2";
			}
			if (npchar.quest.hire == "wait_month") //PW Baldewyn stallholder and month not up
			{
				dialog.snd = "Voice\BACO\BACO002";
				dialog.text = DLG_TEXT[141] ;
				link.l1 = DLG_TEXT[146];
				link.l1.go = "trader";
			}
			if (npchar.quest.hire == "trader") //PW Baldewyn stallholder and repaid loan after month.
			{
				dialog.snd = "Voice\BACO\BACO002";
				dialog.text = DLG_TEXT[147] ;
				link.l1 = DLG_TEXT[148];
				link.l1.go = "trader";
			}
			
			if (npchar.quest.hire == "money_3") //PW Baldewyn stallholder and month up so repay loan
			{
				dialog.snd = "Voice\BACO\BACO002";
				dialog.text = GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[138];
				link.l1 = DLG_TEXT[20];
				link.l1.go = "line_money";
			}
			if ((!npchar.quest.hire == "wait_month") && (!npchar.quest.hire == "money_3"))
			{	
			link.l2 = pcharrepphrase(DLG_TEXT[21], DLG_TEXT[22]);
			link.l2.go = "exit";
			NextDiag.TempNode = "First time";
			}
		break;

		case "hire_denied":
			dialog.snd = "Voice\BACO\BACO003";
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit";
			npchar.quest.hire = "hire_denied";
		break;

		case "line_two":
			dialog.snd = "Voice\BACO\BACO004";
			dialog.text = DLG_TEXT[25];
			link.l1 = pcharrepphrase(DLG_TEXT[26], DLG_TEXT[27]);
			link.l1.go = "line_two_1";
			link.l2 = pcharrepphrase(DLG_TEXT[28], DLG_TEXT[29]);
			link.l2.go = "exit";
		break;

		case "line_two_1":
			dialog.snd = "Voice\BACO\BACO005";
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(PChar))); // DeathDaisy
			dialog.text = DLG_TEXT[30];
			link.l1 = pcharrepphrase(DLG_TEXT[31], DLG_TEXT[32]);
			link.l1.go = "line_two_2";
			link.l2 = pcharrepphrase(DLG_TEXT[33], DLG_TEXT[34]);
			link.l2.go = "exit";
		break;

		case "line_two_2":
			dialog.snd = "Voice\BACO\BACO006";
			dialog.text = DLG_TEXT[35] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[36];
			link.l1 = pcharrepphrase(DLG_TEXT[37], DLG_TEXT[38]);
			link.l1.go = "line_two_3";
		break;

		case "line_two_3":
			dialog.snd = "Voice\BACO\BACO007";
			dialog.text = DLG_TEXT[39];
			link.l1 = pcharrepphrase(DLG_TEXT[40], DLG_TEXT[41]);
			link.l1.go = "line_two_4";
			link.l2 = pcharrepphrase(DLG_TEXT[42], DLG_TEXT[43]);
			link.l2.go = "exit";
		break;

		case "line_two_4":
			dialog.snd = "Voice\BACO\BACO008";
			dialog.text = DLG_TEXT[44] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[45])]) + DLG_TEXT[47] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[48])]) + DLG_TEXT[49];
			link.l1 = pcharrepphrase(DLG_TEXT[50], DLG_TEXT[51]);
			link.l1.go = "line_two_5";
			link.l2 = pcharrepphrase(DLG_TEXT[52], DLG_TEXT[53]);
			link.l2.go = "exit";
		break;

		case "line_two_5":
			if (makeint(pchar.reputation) > 40 )
			{
				dialog.snd = "Voice\BACO\BACO009";
				dialog.text = DLG_TEXT[54] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[55] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[56])]) + DLG_TEXT[57];
				if (makeint(pchar.money) >= 10000)
				{
					link.l1 = DLG_TEXT[58];
					link.l1.go = "money";
				}
				link.l2 = DLG_TEXT[59];
				link.l2.go = "work";
				link.l3 = DLG_TEXT[60];
				link.l3.go = "exit";
			}
			else
			{
				dialog.snd = "Voice\BACO\BACO010";
				dialog.text = DLG_TEXT[61] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[62];
				link.l1 = pcharrepphrase(DLG_TEXT[63], DLG_TEXT[64]);
				link.l1.go = "exit";
			}
		break;

		case "line_one":
			dialog.snd = "Voice\BACO\BACO011";
			dialog.text = DLG_TEXT[65];
			link.l1 = pcharrepphrase(DLG_TEXT[66] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[67])]) + DLG_TEXT[68], DLG_TEXT[69]);
			link.l1.go = "line_one_2";
		break;

		case "line_one_2":
			dialog.snd = "Voice\BACO\BACO012";
			dialog.text = DLG_TEXT[70];
			link.l1 = pcharrepphrase(GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[71])]) + DLG_TEXT[72], DLG_TEXT[73] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[74])]) + DLG_TEXT[75]);
			link.l1.go = "line_one_3";
		break;

		case "line_one_3":
			dialog.snd = "Voice\BACO\BACO013";
			dialog.text = DLG_TEXT[76] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[77];
			if (makeint(pchar.reputation) > 40)
			{
				link.l1 = DLG_TEXT[78];
				link.l1.go = "line_one_4";
			}
			link.l2 = pcharrepphrase(DLG_TEXT[79] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[80])]) + DLG_TEXT[81], DLG_TEXT[82]);
			link.l2.go = "line_one_7";
		break;

		case "line_one_4":
			dialog.snd = "Voice\BACO\BACO014";
			dialog.text = DLG_TEXT[83] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "exit";
			npchar.quest.hire = "question_1";
		break;

		case "line_one_5":
			dialog.snd = "Voice\BACO\BACO015";
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[87] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[88])]) + DLG_TEXT[89];
			link.l1.go = "line_one_6";
			link.l2 = pcharrepphrase(DLG_TEXT[90], DLG_TEXT[91] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[92])]) + DLG_TEXT[93]);
			link.l2.go = "line_one_8";
		break;

		case "line_one_6":
			dialog.snd = "Voice\BACO\BACO016";
			dialog.text = DLG_TEXT[94] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[95])]) + DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "exit";
			npchar.quest.hire =  "not_money_3";
		break;

		case "line_one_7":
			dialog.snd = "Voice\BACO\BACO017";
			dialog.text = DLG_TEXT[98] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[99];
			link.l1 = pcharrepphrase(DLG_TEXT[100], DLG_TEXT[101]);
			link.l1.go = "exit";
			npchar.quest.hire =  "not_money_2";
		break;

		case "line_one_8":
			if (makeint(pchar.reputation) > 40 )
			{
				dialog.snd = "Voice\BACO\BACO018";
				dialog.text = DLG_TEXT[102] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[103] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[104])]) + DLG_TEXT[105];
				if (makeint(pchar.money) >= 10000)
				{
					link.l1 = DLG_TEXT[106];
					link.l1.go = "money";
				}
				//link.l2 = DLG_TEXT[107];
				//link.l2.go = "work";
				link.l3 = DLG_TEXT[108];
				link.l3.go = "exit"; //Fix:Storekeeper;19.09
				npchar.quest.hire =  "not_money"; //Fix:Storekeeper;19.09
			}
			else
			{
				dialog.snd = "Voice\BACO\BACO019";
				dialog.text = DLG_TEXT[109] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[110];
				link.l1 = pcharrepphrase(DLG_TEXT[111], DLG_TEXT[112]);
				link.l1.go = "exit";
				npchar.quest.hire =  "not_money"; //Fix:Storekeeper;19.09
			}
		break;

		case "work":
			if(npchar.quest.hire == "almost_done")
			{
				dialog.snd = "Voice\BACO\BACO020";
				dialog.text = DLG_TEXT[113] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[114];
				link.l1 = DLG_TEXT[115];
				link.l1.go = "exit";
				npchar.quest.hire = "trader";
				
			}
			else
			{
				dialog.snd = "Voice\BACO\BACO021";
				dialog.text = DLG_TEXT[117] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[118] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[119])]) + DLG_TEXT[120];
				if (makeint(pchar.money) > 2500)
				{
					link.l1 = DLG_TEXT[121];
					link.l1.go = "work_1";
				}
				link.l2 = DLG_TEXT[122];
				link.l2.go = "exit";
				npchar.quest.hire =  "not_money_3";
			}
		break;

		case "money":
			dialog.snd = "Voice\BACO\BACO022";
			dialog.text = DLG_TEXT[123] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[124];
			link.l1 = DLG_TEXT[125];
			link.l1.go = "exit";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -10000);
			ChangeCharacterReputation(pchar, 2);
			AddDialogExitQuest("baldewyn_wait_month");
			if (characters[GetCharacterIndex("Sabine Matton")].quest.hire == "0") Characters[GetCharacterIndex("Sabine Matton")].location = "Falaise_De_Fleur_store";
		break;

		case "work_1":
			dialog.snd = "Voice\BACO\BACO023";
			dialog.text = DLG_TEXT[126] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[127] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[128])]) + DLG_TEXT[129];
			link.l1 = DLG_TEXT[130];
			link.l1.go = "exit";
// Taghmon -->
			if (!Checkattribute(npchar, "quest.arno")) //Fix:Storekeeper;19.09
			{
				npchar.quest.hire = "money_4"; 
			}
			else
			{
				npchar.quest.hire =  "money_1"; 
			}
// Taghmon <--
		break;

		case "work_2":
			dialog.snd = "Voice\BACO\BACO024";
			dialog.text = DLG_TEXT[131];
			link.l1 = DLG_TEXT[132] + GetMyShipNameShow(PChar) + DLG_TEXT[133];
			link.l1.go = "exit";
			//PlayStereoSound("INTERFACE\took_item.wav");
			//AddMoneyToCharacter(pchar,-2500); //Fix:Storekeeper;19.09
			AddPassenger(pchar, npchar, 0);
			npchar.quest.hire = "hired";
			AddDialogExitQuest("hire_baldewyn");
		break;

		case "work_3":
			dialog.snd = "Voice\BACO\BACO025";
			dialog.text = DLG_TEXT[134];
			link.l1 = DLG_TEXT[135] + GetMyShipNameShow(PChar) + DLG_TEXT[136];
			link.l1.go = "exit";
			//PlayStereoSound("INTERFACE\took_item.wav");
			//AddMoneyToCharacter(pchar, -2500); //Fix:Storekeeper;19.09
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1000);
				AddPartyExpChar(pchar, "Sneak", 10);
			}
			else { AddPartyExp(pchar, 1000); }
			AddPassenger(pchar, npchar, 0);
			npchar.quest.hire = "hired";
			AddDialogExitQuest("hire_baldewyn");
		break;

		case "trader"://PW Baldewyn stallholder
			dialog.snd = "Voice\BACO\BACO025";
			dialog.text = DLG_TEXT[142];
		
		/*
		if ((characters[GetCharacterIndex("Sabine Matton")].quest.hire == "enemy_forever")
			(
			//PW intend to have Baldewyn stock basic provisions at his stall if Arnaud wont trade (until he is replaced by Baldewyn)
			//but stealing the store interface is tricky WIP
			Link.l1 = DLG_TEXT[144];
			Link.l1.go = "Baldewyn_provisions";
			)
			else
			(
		*/
			Link.l2 = DLG_TEXT[143];
			Link.l2.go = "Baldewyn_Items";	
			Link.l3 = DLG_TEXT[145];
			Link.l3.go = "exit";
		//)
		break;
		
		case "Baldewyn_Items"://
		if (!CheckAttribute(npchar, "quest.item_date") || npchar.quest.item_date != lastspeak_date)
				// PB: Prevent error
				{
					GiveItemToTrader(npchar);
					npchar.quest.item_date = lastspeak_date;
				}
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchItemsTrade(NPChar);
		break; 
		
		case "Baldewyn_provisions":
		//call up the store interface or subset of that with first 8 provisions only
		break;
		
		case "line_money":
			dialog.snd = "Voice\BACO\BACO026";
			dialog.text = DLG_TEXT[137] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) ;
			link.l1 = DLG_TEXT[139];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[140];
			link.l2.go = "work";
			npchar.quest.hire =  "almost_done";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 15000);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Commerce", 750);
				AddPartyExpChar(pchar, "Sneak", 8);
			}
			else { AddPartyExp(pchar, 750); }
			//ChangeCharacterReputation(pchar, 2);// PW you got this when you lent the money
			
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
