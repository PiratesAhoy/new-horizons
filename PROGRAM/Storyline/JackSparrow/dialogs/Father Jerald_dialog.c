//#include "DIALOGS\Father Jerald_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	int DonationSize, iTest;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	Preprocessor_Add("Father", GetMyFirstNames(NPChar, false));
	if (PChar.sex == "man") Preprocessor_Add("addr", XI_ConvertString("my son"));
	else Preprocessor_Add("addr", XI_ConvertString("my child"));//PW this could be taken out for JS but..
	
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
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			

			if(NPChar.quest.meeting == "0")
			{
				dialog.snd = "Voice\FATJ\FATJ001";
				d.Text = TimeGreeting() + DLG_TEXT[0];
				Link.l1 = DLG_TEXT[1] + GetMyFullName(PChar) + DLG_TEXT[2] + GetMyShipNameShow(PChar) + DLG_TEXT[3];
				Link.l1.go = "meeting";
				NPC_Meeting = "1"; 
			}
			else
			{
				dialog.snd1 = "Voice\FATJ\FATJ002";
				dialog.snd2 = "Voice\FATJ\FATJ003";
				dialog.snd3 = "Voice\FATJ\FATJ004";
				d.Text = RandPhrase(DLG_TEXT[4] + GetMyName(Pchar) + DLG_TEXT[5], DLG_TEXT[6] + GetMyName(Pchar) + DLG_TEXT[7], DLG_TEXT[8], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = GetMyFullName(NPChar) + DLG_TEXT[9];
				Link.l1.go = "donation";
				Link.l2 = DLG_TEXT[10];
				Link.l2.go = "quest lines";
				Link.l3 = DLG_TEXT[11];
				Link.l3.go = "exit";
			}
		break;

		case "Meeting":
			dialog.snd = "Voice\FATJ\FATJ005";
				d.Text = DLG_TEXT[12] + GetMyFullName(NPChar) + DLG_TEXT[13];
				Link.l1 = DLG_TEXT[14];
				Link.l1.go = "donation";
				Link.l2 = DLG_TEXT[15];
				Link.l2.go = "quest lines";
				Link.l3 = DLG_TEXT[16];
				Link.l3.go = "exit";
		break;

		case "quest lines":
			dialog.snd = "Voice\FATJ\FATJ006";
				d.Text = DLG_TEXT[17];
			if (GetAttribute(pchar, "Church_Help") == "met_Ammand"){	
				if (characters[GetCharacterIndex("Father Bernard")].quest.church_help == "to_greenford" || characters[GetCharacterIndex("Father Bernard")].quest.church_help == "after_traktir")
				{
					link.l1 = DLG_TEXT[18];	
					link.l1.go = "to_greenford";
				}
				if (characters[GetCharacterIndex("Father Bernard")].quest.church_help == "letters_1")
				{
					link.l1 = DLG_TEXT[19];
					link.l1.go = "letters_1";
				}
				if (characters[GetCharacterIndex("Father Bernard")].quest.church_help == "letters_2" || characters[GetCharacterIndex("Father Bernard")].quest.church_help == "after_off")
				{
					link.l1 = DLG_TEXT[20];
					link.l1.go = "letters_2";
				}
			}
				Link.l99 = DLG_TEXT[21]);
				Link.l99.go = "no quest";
		break;

		case "letters_1":
			dialog.snd = "Voice\FATJ\FATJ007";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "letters_1_2";
		break;

		case "letters_1_2":
			dialog.snd = "Voice\FATJ\FATJ008";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "letters_2_2";
		break;

		case "letters_2":
			dialog.snd = "Voice\FATJ\FATJ009";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "letters_2_2";
		break;

		case "letters_2_2":
			dialog.snd = "Voice\FATJ\FATJ010";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "letters_2_3";
		break;

		case "letters_2_3":
			dialog.snd = "Voice\FATJ\FATJ011";
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "letters_2_4";
		break;

		case "letters_2_4":
			dialog.snd = "Voice\FATJ\FATJ012";
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "letters_2_4_exit";
			link.l2 = DLG_TEXT[34];
			link.l2.go = "letters_2_5";
		break;

		case "letters_2_4_exit":
			AddQuestRecord("Ammand", 4);
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "letters_2_5":
			dialog.snd = "Voice\FATJ\FATJ013";
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "letters_2_6";
		break;

		case "letters_2_6":
			if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) > 4)
			{
				dialog.snd = "Voice\FATJ\FATJ014";
				dialog.text = DLG_TEXT[37];
				link.l1 = DLG_TEXT[38];
				link.l1.go = "letters_2_7";
			}
			else
			{
				dialog.snd = "Voice\FATJ\FATJ015";
				dialog.text = DLG_TEXT[39];
				link.l1 = DLG_TEXT[40];
				link.l1.go = "exit";
			}
		break;

		case "letters_2_7":
			dialog.snd = "Voice\FATJ\FATJ016";
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "letters_2_9";
			link.l2 = DLG_TEXT[43];
			link.l2.go = "letters_2_8";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 2000);
			pchar.help_church = "blackmail";
		break;

		case "letters_2_8":
			dialog.snd = "Voice\FATJ\FATJ017";
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "exit";
			AddQuestRecord("Ammand", 5);
		break;

		case "letters_2_9":
			AddQuestRecord("Ammand", 6);
			characters[GetCharacterIndex("Father Bernard")].quest.church_help = "without_letters";
			TakeItemFromCharacter(PChar, "pornushka");
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "to_greenford":
			dialog.snd = "Voice\FATJ\FATJ018";
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[48])]) + DLG_TEXT[50];
			link.l1.go = "to_greenford_2";
		break;

		case "to_greenford_2":
			dialog.snd = "Voice\FATJ\FATJ019";
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "to_greenford_3";
		break;

		case "to_greenford_3":
			dialog.snd = "Voice\FATJ\FATJ020";
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Father Bernard")].quest.church_help = "speak_with_jerald";
		break;

		case "No quest":
			dialog.snd = "Voice\FATJ\FATJ021";
				d.Text = DLG_TEXT[55];
				Link.l1 = DLG_TEXT[56];
				Link.l1.go = "donation";
				Link.l2 = DLG_TEXT[57];
				Link.l2.go = "exit";
		break;

		case "donation":
			dialog.snd = "Voice\FATJ\FATJ022";
			d.Text = DLG_TEXT[58];
			Link.l1 = DLG_TEXT[59];
			Link.l1.go = "No donation";
// NK -->
			// TIH --> do once, and only up to a certain level due to limitations on game Aug29'06
			int iRepRank = 150;
			if (sti(PChar.rank) < 50) { iRepRank = makeint(sqrt(sqrt(sti(PChar.rank)^5))); }
			if(sti(PChar.money)>=500 * iRepRank)
			{
				Link.l2 = DLG_TEXT[75] + (500 * iRepRank) + DLG_TEXT[76];
				Link.l2.go = "donation paid_500";
			}
			if(sti(PChar.money)>=2500 * iRepRank)
			{
				Link.l3 = DLG_TEXT[77] + (2500 * iRepRank) + DLG_TEXT[79];
				Link.l3.go = "donation paid_2500";
			}
			if(sti(PChar.money)>=5000 * iRepRank)
			{
				Link.l4 = DLG_TEXT[78] + (5000 * iRepRank) + DLG_TEXT[79];
				Link.l4.go = "donation paid_5000";
			}
			/* prior method, broken
			if(makeint(PChar.money)>=500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))))
			{	
				Link.l2 = DLG_TEXT[75] + (500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)))) + DLG_TEXT[76];
				Link.l2.go = "donation paid_500";
			}
			if(makeint(PChar.money)>=2500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))))
			{
				Link.l3 = DLG_TEXT[77] + (2500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)))) + DLG_TEXT[79];
				Link.l3.go = "donation paid_2500";
			}
			if(makeint(PChar.money)>=5000 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))))
			{	
				Link.l4 = DLG_TEXT[78] + (5000 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)))) + DLG_TEXT[79];
				Link.l4.go = "donation paid_5000";
			}
			*/
			// TIH <--
		break;

		case "No donation":
			dialog.snd = "Voice\FATB\FATB045";
			d.Text = DLG_TEXT[63];
			Link.l1 = DLG_TEXT[64];
			Link.l1.go = "quest lines";
			Link.l2 = DLG_TEXT[65];
			Link.l2.go = "exit";
		break;

		case "donation paid_500":
			dialog.snd = "Voice\FATB\FATB046";
		    	PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))));
			pchar.quest.donate = makeint(pchar.quest.donate) + 500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)));
			dialog.text = DLG_TEXT[66];

			if(CheckAttribute(PChar,"quest.mysterious_plants.donate") && sti(GetAttribute(PChar,"quest.mysterious_plants.donate")) < 1000)  //PW mysterious plants specific
			{
				Link.l1 = DLG_TEXT[84]
				Link.l1.go = "donation paid_apothecary";
			}
			Link.l2 = DLG_TEXT[67];
			Link.l2.go = "quest lines";
			Link.l3 = DLG_TEXT[68];
			Link.l3.go = "exit";
			AddDialogExitQuest("donation");
		break;
		
		case "donation paid_2500":
			dialog.snd = "Voice\FATB\FATB046";
		    	PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -2500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))));
			pchar.quest.donate = makeint(pchar.quest.donate) + 2500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)));
			d.Text = DLG_TEXT[69];
			if(CheckAttribute(PChar,"quest.mysterious_plants.donate") && sti(GetAttribute(PChar,"quest.mysterious_plants.donate")) < 1000)  //PW mysterious plants specific
			{
				Link.l1 = DLG_TEXT[84]
				Link.l1.go = "donation paid_apothecary";
			}
			Link.l2 = DLG_TEXT[70];
			Link.l2.go = "quest lines";
			Link.l3 = DLG_TEXT[71];
			Link.l3.go = "exit";
			AddDialogExitQuest("donation");
		break;
		
		case "donation paid_5000":
			dialog.snd = "Voice\FATB\FATB046";
		    	PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -5000 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))));
			pchar.quest.donate = makeint(pchar.quest.donate) + 5000 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)));
			d.Text = DLG_TEXT[72];

			if(CheckAttribute(PChar,"quest.mysterious_plants.donate") && sti(GetAttribute(PChar,"quest.mysterious_plants.donate")) < 1000)  //PW mysterious plants specific
			{
				Link.l1 = DLG_TEXT[84]
				Link.l1.go = "donation paid_apothecary";
			}
			Link.l2 = DLG_TEXT[73];
			Link.l2.go = "quest lines";
			Link.l3 = DLG_TEXT[74];
			Link.l3.go = "exit";
			AddDialogExitQuest("donation");
// NK <--
		break;

		case "donation paid_apothecary":
			dialog.snd = "Voice\FATB\FATB046";
			d.Text = DLG_TEXT[85];
			Link.l1 = DLG_TEXT[86];
			if(!CheckAttribute(PChar,"quest.telescope_quest.church") && !CheckAttribute(PChar,"quest.telescope_quest.returned_cross"))
			{
				Link.l1.go = "start telescope";
			}
			else
			{
				Link.l1.go = "exit";
			}
		break;


		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
		
	}
}
