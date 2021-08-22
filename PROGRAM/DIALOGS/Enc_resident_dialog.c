// ccc -->
// NK added rand phrases, and a tweak to remember meeting status
//#include "DIALOGS\Enc_Resident_dialog.h"

void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar;
	aref Link, NextDiag;
	int NPC_Meeting;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	int grgbonus = 0;

	
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
			
			if(makeint(PChar.reputation) >= 40) // NK so the occ. doesn't greet you politely then kick you out; now they _just_ kick you out.
			{
				if(NPchar.sex == "man") {PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_c_002.wav");}
				else {PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_f_a_001.wav");}
				dialog.text = LinkRandPhrase(DLG_TEXT[0], DLG_TEXT[1], DLG_TEXT[2]) + GetMyFullName(NPChar) + ".";
				Link.l1 = DLG_TEXT[3] + " " + GetMyFullName(PChar) + ".";
				Link.l1.go = "second time";
			}
			else
			{
				if(NPchar.sex == "man") {PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_c_008.wav");}
				else {PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_f_a_006.wav");}
				dialog.text =  LinkRandPhrase(DLG_TEXT[29], DLG_TEXT[31], DLG_TEXT[33]); // NK
				Link.l1 = LinkRandPhrase(DLG_TEXT[30], DLG_TEXT[32], DLG_TEXT[34]); // NK
				Link.l1.go = "exit";
			}
		break;

		case "second time":
			NextDiag.TempNode = "second time";
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			if (makeint(PChar.reputation) >= 40) // NK so they talk at start of game.
			{
				// NK -->
				string tmp;
				bool met = false;
				ref lcn = &Locations[FindLocation(PChar.location)];
				bool house = lcn.type == "house";
				met = CheckAttribute(NPChar,"quest.meeting");
				if(met) met = sti(NPChar.quest.meeting);
				NPChar.quest.meeting = 1;
				if(house && CheckAttribute(lcn,"lastentermonth"))
				{
					if(CheckAttribute(lcn,"vag.meeting") && sti(lcn.vag.meeting)) { met = true; }
					lcn.vag.meeting = 1;
				}

				if(CheckAttribute(pchar,"chr_ai.poison") && pchar.chr_ai.poison > 0)
				{
					if(NPchar.sex == "man") {PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_c_005.wav");}
					else {PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_f_a_009.wav");}
					Dialog.text = DLG_TEXT[13];
					Link.l1 = LinkRandPhrase(DLG_TEXT[14], DLG_TEXT[15], DLG_TEXT[16]);
					Link.l1.go = "infected";
				}
				else
				{
					if(met)
					 {
						tmp = DLG_TEXT[6];
						if(NPchar.sex == "man") {PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_c_079.wav");}
						else {PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_f_a_004.wav");}
					 }
					else { tmp = DLG_TEXT[5]; }
					dialog.text = tmp + GetMyName(PChar) + DLG_TEXT[7];
					// NK so you do need high rep for something
					if (makeint(PChar.reputation) >= 50 )
					{
						Link.l2 = DLG_TEXT[8];
						Link.l2.go = "heal";
						if(NPChar.location.group != "reload" )
						{
						Link.l7 =  LinkRandPhrase(DLG_TEXT[80], DLG_TEXT[81], DLG_TEXT[82]);
						Link.l7.go = "burglar";
						}
					}
					Link.l6 = DLG_TEXT[69];
					Link.l6.go = "bribe";
					Link.l3 = LinkRandPhrase(DLG_TEXT[9], DLG_TEXT[10], DLG_TEXT[11]); // NK
					Link.l3.go = "chat";
					Link.l4 = DLG_TEXT[52];
					Link.l4.go = "extort1";
					Link.l5 = DLG_TEXT[12];
					Link.l5.go = "exit";
				}
			}
			else
			{
				if(NPchar.sex == "man") {PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_c_008.wav");}
				else {PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_f_a_006.wav");}
				dialog.text =  LinkRandPhrase(DLG_TEXT[29], DLG_TEXT[31], DLG_TEXT[33]); // NK
				Link.l1 = LinkRandPhrase(DLG_TEXT[30], DLG_TEXT[32], DLG_TEXT[34]); // NK
				Link.l1.go = "exit";
			}
		break;

		case "bribe":
			dialog.text = DLG_TEXT[70];
			Link.l4 = DLG_TEXT[71];
			Link.l4.go = "exit";
			Link.l1 = DLG_TEXT[72];
			Link.l1.go = "bribe0";
			Link.l2 = DLG_TEXT[73];
			Link.l2.go = "bribe0";
		break;

		case "bribe0":
			dialog.text = DLG_TEXT[74];
			Link.l4 = DLG_TEXT[75];
			Link.l4.go = "exit";
			Link.l1 = DLG_TEXT[76];
			Link.l1.go = "bribe1";
		break;

		case "bribe1":
			LAi_Fade("", "");
			dialog.text = DLG_TEXT[77];
			Link.l1 = DLG_TEXT[78];
			Link.l1.go = "bribe2";
		break;

		case "bribe2":
			LAi_group_SetAlarm(LAI_DEFAULT_GROUP, LAI_GROUP_PLAYER, 0.0);
			LAi_group_SetRelation(LAI_DEFAULT_GROUP, LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
			LAi_group_SetAlarm(LAI_DEFAULT_GROUP, LAI_GROUP_MONSTERS, 0.0);
			LAi_group_SetRelation(LAI_DEFAULT_GROUP, LAI_GROUP_MONSTERS, LAI_GROUP_NEUTRAL);

			string IslandID;
			int jopa;

			jopa = GetCharacterCurrentIsland(Pchar);
			IslandID = Islands[jopa].id;

			switch(IslandID)
			{
			case "FalaiseDeFleur":
		LAi_group_SetAlarm("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, 0.0);
		LAi_group_SetAlarm("FRANCE_CITIZENS", LAI_GROUP_PLAYER, 0.0);
		LAi_group_SetRelation("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
		LAi_group_SetRelation("FRANCE_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
		LAi_group_SetAlarmReaction("FRANCE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
		break;

		case "Redmond":
		LAi_group_SetAlarm("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, 0.0);
		LAi_group_SetAlarm("ENGLAND_CITIZENS", LAI_GROUP_PLAYER, 0.0);
		LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
		LAi_group_SetRelation("ENGLAND_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
		LAi_group_SetAlarmReaction("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
		break;

		case "Conceicao":
		LAi_group_SetAlarm("CONCEICAO_SOLDIERS", LAI_GROUP_PLAYER, 0.0);
		LAi_group_SetAlarm("CONCEICAO_CITIZENS", LAI_GROUP_PLAYER, 0.0);
		LAi_group_SetRelation("CONCEICAO_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
		LAi_group_SetRelation("CONCEICAO_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
		LAi_group_SetAlarmReaction("CONCEICAO_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);

		LAi_group_SetAlarm("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, 0.0);
		LAi_group_SetAlarm("SMUGGLERS_CITIZENS", LAI_GROUP_PLAYER, 0.0);
		LAi_group_SetRelation("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
		LAi_group_SetRelation("SMUGGLERS_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
		LAi_group_SetAlarmReaction("SMUGGLERS_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
		break;

		case "Oxbay":
		LAi_group_SetAlarm("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, 0.0);
		LAi_group_SetAlarm("ENGLAND_CITIZENS", LAI_GROUP_PLAYER, 0.0);
		LAi_group_SetRelation("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
		LAi_group_SetRelation("ENGLAND_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
		LAi_group_SetAlarmReaction("ENGLAND_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
		break;

		case "IslaMuelle":
		LAi_group_SetAlarm("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, 0.0);
		LAi_group_SetAlarm("SPAIN_CITIZENS", LAI_GROUP_PLAYER, 0.0);
		LAi_group_SetRelation("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
		LAi_group_SetRelation("SPAIN_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
		LAi_group_SetAlarmReaction("SPAIN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
		break;

		case "Douwesen":
		LAi_group_SetAlarm("DOUWESEN_SOLDIERS", LAI_GROUP_PLAYER, 0.0);
		LAi_group_SetAlarm("DOUWESEN_CITIZENS", LAI_GROUP_PLAYER, 0.0);
		LAi_group_SetRelation("DOUWESEN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
		LAi_group_SetRelation("DOUWESEN_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
		LAi_group_SetAlarmReaction("DOUWESEN_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);

		LAi_group_SetAlarm("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_PLAYER, 0.0);
		LAi_group_SetAlarm("DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_PLAYER, 0.0);
		LAi_group_SetRelation("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
		LAi_group_SetRelation("DOUWESEN_PIRATE_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
		LAi_group_SetAlarmReaction("DOUWESEN_PIRATE_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
		break;

		case "QuebradasCostillas":
		LAi_group_SetAlarm("QC_SOLDIERS", LAI_GROUP_PLAYER, 0.0);
		LAi_group_SetAlarm("QC_CITIZENS", LAI_GROUP_PLAYER, 0.0);
		LAi_group_SetRelation("QC_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
		LAi_group_SetRelation("QC_CITIZENS", LAI_GROUP_PLAYER, LAI_GROUP_NEUTRAL);
		LAi_group_SetAlarmReaction("QC_SOLDIERS", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
		break;

		case "KhaelRoa":

		break;
		}
		    PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -100);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "burglar":
			dialog.text =  LinkRandPhrase(DLG_TEXT[83], DLG_TEXT[84], DLG_TEXT[85]);
			Link.l4 = DLG_TEXT[12];
			Link.l4.go = "exit";
			Link.l1 =  LinkRandPhrase(DLG_TEXT[86], DLG_TEXT[87], DLG_TEXT[88]);
			Link.l1.go = "burglarwait";
		break;

		case "burglarwait":
			NextDiag.CurrentNode = "burglardawn";
			DialogExit();			
			if (makeint(environment.time) < 22.0 && makeint(environment.time) >= 10.0) TavernWaitDate2("wait_day"); 
			TavernWaitDate("wait_day");
			PlaySound("AMBIENT\SHOP\sigh2.wav");
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You you stand guard for hours."));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"It may be time to claim your reward."));	
		break;

		case "burglardawn":

			dialog.text =  LinkRandPhrase(DLG_TEXT[89], DLG_TEXT[90], DLG_TEXT[91]);
			if (rand(100)>= 50)
			{
				Link.l1 = DLG_TEXT[92];
				Link.l1.go = "burglarreward";
			}
			else
			{
				PlaySound("AMBIENT\TOWN\dog.wav");
				Link.l1 = DLG_TEXT[92];
				Link.l1.go = "burglarfight";
			}
		break;

		case "burglarreward":
			dialog.text = DLG_TEXT[93];
			Link.l1 = DLG_TEXT[98];
			Link.l1.go = "burglaritem";
			Link.l2 = DLG_TEXT[99];
			Link.l2.go = "burglarrep";
			break;

		case "burglaritem":
			GiveItem2Character(pchar, "jewelry" + (1 + rand(15)));
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "burglarrep":
			ChangeCharacterReputation(pchar, 2); //Changed to 2 for balancing -Levis
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "burglarfight":
			dialog.text =  LinkRandPhrase(DLG_TEXT[94], DLG_TEXT[95], DLG_TEXT[96]);
			PlaySound("AMBIENT\TOWN\dog2.wav");
			PlaySound("AMBIENT\SHIPYARD\saw.wav");
			PlaySound("AMBIENT\TOWN\dog.wav");
			Link.l1 = DLG_TEXT[97];
			Link.l1.go = "burglarfight2";
		break;

		case "burglarfight2":
			PlaySound("OBJECTS\DUEL\sword_fallen.wav");
			ref chr;
			int bmax = 1 + ((sti(Pchar.rank)-1) / 2);
			if(bmax > 3) bmax=3;
			for(int i = 0; i < bmax; i++)
			{
			string sound = "OBJECTS\DUEL\man_attack" + (6-i) + ".wav");
			PlaySound(sound);
			chr = LAi_CreateFantomCharacter(false, 0, true, true, 0.25, "mask_" + (i+2), LAI_GROUP_MONSTERS, "");
			LAi_SetWarriorType(chr);
			LAi_group_MoveCharacter(chr,  LAI_GROUP_MONSTERS);
			LAi_group_SetRelation(LAI_GROUP_PLAYER, LAI_GROUP_MONSTERS, LAI_GROUP_ENEMY);
			string homelocation = pchar.location;
			PlaceCharacter(chr, "reload");
			float mx,my,mz;
			GetCharacterPos(chr, &mx, &my, &mz);
			TeleportCharacterToPos(chr, mx, i + my, mz);
			}
			LAi_group_SetRelation(LAI_DEFAULT_GROUP, LAI_GROUP_PLAYER, LAI_GROUP_FRIEND);
			LAi_group_SetAlarmReaction(LAI_DEFAULT_GROUP, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY, LAI_GROUP_FRIEND);
			DialogExit();
			NextDiag.CurrentNode = "burglardawn";
		break;


		case "chat":

			dialog.text = DLG_TEXT[17];
			Link.l4 = DLG_TEXT[12];
			Link.l4.go = "exit";
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "chat2";
		break;

		case "chat2":
			dialog.text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) );

			if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 10.0)
			{
				Link.l1 = DLG_TEXT[22];
				Link.l1.go = "hall_day_wait";
			}
			else
			{
				Link.l1 = DLG_TEXT[23];
				Link.l1.go = "hall_night_wait";
			}
		break;

		case "heal":
			Dialog.text = DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			if (rand(100) + makeint(pchar.skill.Sneak) >= 35) {Link.l1.go = "exit recovered";}
			else {Link.l1.go = "exit infected";}
			Link.l3 = DLG_TEXT[24];
			Link.l3.go = "exit";
		break;

		case "infected":
			Dialog.text = LinkRandPhrase(DLG_TEXT[25], DLG_TEXT[26], DLG_TEXT[27]); 
			int winlink = rand(100);
			if (winlink >= 50) 
			{
				Link.l1 = LinkRandPhrase(DLG_TEXT[38], DLG_TEXT[39], DLG_TEXT[40]);
				Link.l1.go = "exit recovered";
			}
			Link.l2 = LinkRandPhrase(DLG_TEXT[41], DLG_TEXT[42], DLG_TEXT[43]);
			Link.l2.go = "exit infected";
			Link.l3 = LinkRandPhrase(DLG_TEXT[44], DLG_TEXT[45], DLG_TEXT[46]);
			Link.l3.go = "exit infected";
			if (winlink < 50) 
			{
				Link.l4 = LinkRandPhrase(DLG_TEXT[38], DLG_TEXT[39], DLG_TEXT[40]);
				Link.l4.go = "exit recovered"
			}
			Link.l5 = DLG_TEXT[47];
			Link.l5.go = "exit";
		break;


		case "hall_day_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			TavernWaitDate("wait_day");
			PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_013.wav");
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You chat on for hours and learn a lot") + " " + LanguageConvertString(tmpLangFileID,"about the town."));
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 50+(sti(PChar.skill.Leadership)*10)+Rand(50)); }
			else { AddPartyExp(pchar, 50+(sti(PChar.skill.Leadership)*10)+Rand(50)); }
		break;

		case "hall_night_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			TavernWaitDate("wait_night");
			PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_014.wav");
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You chat on for hours and learn a lot") + " " + LanguageConvertString(tmpLangFileID,"about the town."));
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Leadership", 50+(sti(PChar.skill.Leadership)*10)+Rand(50)); }
			else { AddPartyExp(pchar, 50+(sti(PChar.skill.Leadership)*10)+Rand(50)); }
		break;

		case "exit recovered":
			Dialog.text = DLG_TEXT[48];
			Link.l1 = LinkRandPhrase(DLG_TEXT[49], DLG_TEXT[50], DLG_TEXT[51]);
			Link.l1.go = "exit recovered2";
		break;

		case "exit recovered2":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			pchar.chr_ai.poison = 0;
			/*pchar.chr_ai.hp_max = sti(pchar.chr_ai.hp_max) + 1;
			LAi_SetCurHPMax(pchar);*/
			// NK new HP code 05-07-08 -->
			ChangeHPBonus(PChar, 1);
			// NK <--
			LAi_Fade("", "");
			WaitDate("", 0,0,1,0,0);
			RecalculateJumpTable();
			PlaySound("AMBIENT\SHOP\sigh2.wav");
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"After 24hrs are you fit again, even stronger than before."));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"+ 1 max HP"));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You have learned a lot about woundtreatment."));
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(pchar, "Defence", 50+(sti(PChar.skill.Defence)*10)+Rand(50) + grgbonus ); }
			else { AddPartyExp(pchar, 50+(sti(PChar.skill.Defence)*10)+Rand(50) + grgbonus ); }
		break;

		case "exit infected":
			Dialog.text = DLG_TEXT[48];
			Link.l1 = LinkRandPhrase(DLG_TEXT[49], DLG_TEXT[50], DLG_TEXT[51]);
			Link.l1.go = "exit infected2";
		break;

		case "exit infected2":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			if (makeint(environment.time) < 22.0 && makeint(environment.time) >= 10.0) TavernWaitDate2("wait_day"); // NK to catch if not night
			TavernWaitDate("wait_day"); // NK so there is a fade
			pchar.chr_ai.poison = 20 + rand(50 -sti(PChar.skill.Sneak) -sti(PChar.skill.defence) );
			grgbonus = 200+Rand(200);
			PlaySound("OBJECTS\DUEL\man_hit6.wav");
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You wake up feeling feverish."));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Your wounds burn like fire!"));
		break;

		case "extort1":
			dialog.text = LinkRandPhrase(DLG_TEXT[53], DLG_TEXT[54], DLG_TEXT[55]);
			Link.l1 = LinkRandPhrase(DLG_TEXT[56], DLG_TEXT[57], DLG_TEXT[58]);
			Link.l1.go = "extort2";
		break;

		case "extort2":
			dialog.text = LinkRandPhrase(DLG_TEXT[63], DLG_TEXT[64], GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[65]);
			Link.l2 = DLG_TEXT[62];
			Link.l2.go = "exit";
			Link.l1 = LinkRandPhrase(DLG_TEXT[66], DLG_TEXT[67], DLG_TEXT[68]);
			if (rand(100)+sti(PChar.skill.Leadership)>= 60) {Link.l1.go = "extorted";}
			else  {Link.l1.go = "extort1";}
		break;

		case "extorted":
			if (rand(100)+sti(PChar.skill.Leadership)>= 50)
			{
				dialog.text = DLG_TEXT[59];
				Link.l1 = DLG_TEXT[60];
				Link.l1.go = "exit";
				int prot = rand(650)+300;
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(pchar, prot);
				ChangeCharacterReputation(pchar, -2);
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Your victim produces") + " " + prot + " " + XI_ConvertString("gold."));
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Your conduct didn't improve your reputation"));
			}
			else
			{
				dialog.text = DLG_TEXT[61];
				Link.l2 = DLG_TEXT[34];
				Link.l2.go = "exit";
				pchar.reputation = 35;
			}
		break;



		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
	LanguageCloseFile(tmpLangFileID);
}
// ccc <--
