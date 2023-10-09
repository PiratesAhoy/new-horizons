//#include "DIALOGS\Navy Portugal_dialog.h"

void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	int i;
	
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

			if (makeint(pchar.rank) > 4) 
			{
				dialog.snd = "Voice\CLLA\CLLA001";
				dialog.text = DLG_TEXT[2] + Pchar.name + DLG_TEXT[0];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "begin";
			}
			else
			{
				dialog.snd = "Voice\CLLA\CLLA002";
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "exit";
			
			}

		break;

		case "begin":
			dialog.snd = "Voice\HAAU\HAAU003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "begin_2";
		break;

		case "begin_2":
			dialog.snd = "Voice\HAAU\HAAU004";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "begin_3";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "exit_3";
		break;

		case "begin_3":
			dialog.snd = "Voice\HAAU\HAAU005";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "begin_4";
		break;

		case "begin_4":
			dialog.snd = "Voice\HAAU\HAAU006";
			dialog.text = DLG_TEXT[13] + (makeint(Npchar.rank)*5000) + DLG_TEXT[48];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "begin_6";
			link.l2 = DLG_TEXT[15];
			link.l2.go = "exit_3";
		break;

		case "begin_6":
			dialog.snd = "Voice\HAAU\HAAU007";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "begin_7";
		break;

		case "begin_7":
			dialog.snd = "Voice\HAAU\HAAU008";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit_2";
			npchar.location="Portuguese_Navy";
			npchar.location.group = "goto";
			npchar.location.locator = "goto2";
			SetCompanionIndex(pchar, -1, getcharacterIndex(npchar.id));
			SetCharacterRemovable(npchar, false);
			LAi_SetWarriorType(npchar);
			LAi_warrior_DialogEnable(npchar, true);
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			GiveItem2Character(Pchar, "navy_papers");
			AddPassenger(Pchar, characterFromID("Manuel Sousa"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Manuel Sousa"));			
			LAi_SetOfficerType(characterFromID("Manuel Sousa"));
			HoistFlag(PORTUGAL);
		break;

		case "in_house":
			dialog.snd = "Voice\HAAU\HAAU009";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "wait_time";
			link.l2 = DLG_TEXT[22];
			link.l2.go = "exit_2";
			link.l3 = DLG_TEXT[23];
			link.l3.go = "separation";
		break;
		
		case "wait_time":
			dialog.Text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "wait_1";
			Link.l2 = DLG_TEXT[26];
			Link.l2.go = "wait_2";
			Link.l3 = DLG_TEXT[27];
			Link.l3.go = "exit_2";
		break;

		case "wait_1":
			NextDiag.CurrentNode = "in_house";
			DialogExit();
			WaitDate("", 0,0,1,0,0);
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You spend 1 day in") + " " + FindTownName(GetCurrentTownID()) + "."); // KK
			AddCharacterGoods(Npchar, GOOD_BALLS, 60);
			if(!USE_REAL_CANNONS) AddCharacterGoods(Npchar, GOOD_BOMBS, 60);// TIH toggle fix 7-7-06
			if(CANNONPOWDER_MOD) {AddCharacterGoods(Npchar, GOOD_GUNPOWDER, 1000);}			
			AddCharacterGoods(Npchar, GOOD_SAILCLOTH, 10);
			AddCharacterGoods(Npchar, GOOD_PLANKS, 10);
			AddCharacterGoods(Npchar, GOOD_GRAPES, 40);
			AddCharacterGoods(Npchar, GOOD_KNIPPELS, 40);
		break;

		case "wait_2":
			NextDiag.CurrentNode = "in_house";
			DialogExit();
			AddCharacterGoods(Npchar, GOOD_BALLS, 300);
			if(!USE_REAL_CANNONS) AddCharacterGoods(Npchar, GOOD_BOMBS, 300);// TIH toggle fix 7-7-06
			if(CANNONPOWDER_MOD) {AddCharacterGoods(Npchar, GOOD_GUNPOWDER, 5000);}				
			AddCharacterGoods(Npchar, GOOD_SAILCLOTH, 50);
			AddCharacterGoods(Npchar, GOOD_PLANKS, 50);
			AddCharacterGoods(Npchar, GOOD_GRAPES, 200);
			AddCharacterGoods(Npchar, GOOD_KNIPPELS, 200);
			for(i = 0; i < 5; i++)
			{
				WaitDate("", 0,0,1,0,0);
			}
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You wait here 5 days") + ".");
		break;
		
		case "separation":
			dialog.Text = DLG_TEXT[28];
			Link.l1 = DLG_TEXT[29];
			Link.l1.go = "partage";
			Link.l2 = DLG_TEXT[30];
			Link.l2.go = "death";
			Link.l3 = DLG_TEXT[31];
			Link.l3.go = "exit_2";
		break;
		
		case "partage":
			int loot_part;
			if (makeint(PChar.money) >= (makeint(Npchar.rank)*5000))
			{
				loot_part = makeint(Pchar.money) / 2;
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(Pchar,-loot_part);
				AddMoneyToCharacter(npchar,loot_part);
				dialog.Text = loot_part + DLG_TEXT[49] + loot_part + DLG_TEXT[50] + DLG_TEXT[32];
				Link.l1 = DLG_TEXT[33];
				Link.l1.go = "exit_3";
				RemoveCharacterCompanion(Pchar, npchar);
				npchar.dialog.currentnode = "hire_again";
				npchar.location = "Portuguese_Navy";
				npchar.location.group = "goto";
				npchar.location.locator = "goto2";
				LAi_group_MoveCharacter(npchar, "CONCEICAO_CITIZENS");
                                TakeItemFromCharacter(pchar, "navy_papers");
			        RemovePassenger(pchar, characterFromID("Manuel Sousa"));
			        RemoveCharacterCompanion(pchar, characterFromID("Manuel Sousa"));
			        RemoveOfficersIndex(pchar, GetCharacterIndex("Manuel Sousa"));
			}
			else
			{
				dialog.Text = DLG_TEXT[44];
				Link.l1 = DLG_TEXT[45];
				Link.l1.go = "death";
			}
		break;

		case "death":
			dialog.Text = DLG_TEXT[34];
			Link.l1 = DLG_TEXT[35];
			Link.l1.go = "exit_5";
			RemovePassenger(pchar, characterFromID("Manuel Sousa"));
			RemoveCharacterCompanion(pchar, characterFromID("Manuel Sousa"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Manuel Sousa"));
			SetRMRelation(PChar, PORTUGAL, REL_WAR);
 			
		break;
		
		case "hire_again":
			dialog.snd = "Voice\HAAU\HAAU004";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit_3";
			link.l2 = DLG_TEXT[38];
			link.l2.go = "confirm";
		break;

		case "confirm":
			dialog.snd = "Voice\HAAU\HAAU005";
			dialog.text = DLG_TEXT[39] + (makeint(Npchar.rank)*5000) + DLG_TEXT[51];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "partnership";
			link.l2 = DLG_TEXT[41];
			link.l2.go = "exit_3";
		break;

		case "partnership":
			dialog.snd = "Voice\HAAU\HAAU006";
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "exit_2";
			SetCompanionIndex(pchar, -1, getcharacterIndex(npchar.id));
			SetCharacterRemovable(npchar, false);
			npchar.location = "Portuguese_Navy";
			npchar.location.group = "goto";
			npchar.location.locator = "goto2";
			LAi_group_MoveCharacter(npchar, LAI_GROUP_PLAYER);
			LAi_SetWarriorType(npchar);
			LAi_warrior_DialogEnable(npchar, true);
			npchar.dialog.currentnode = "in_house";
			GiveItem2Character(Pchar, "navy_papers");
			AddPassenger(Pchar, characterFromID("Manuel Sousa"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Manuel Sousa"));			
			LAi_SetOfficerType(characterFromID("Manuel Sousa"));
			HoistFlag(PORTUGAL);
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_2":
			DialogExit();
			NextDiag.CurrentNode = "in_house";
		break;

		case "Exit_3":
			DialogExit();
			NextDiag.CurrentNode = "hire_again";
		break;

		case "Exit_4":
			DialogExit();
			NextDiag.TempNode = "first time";
			LAi_group_MoveCharacter(NPchar, LAI_GROUP_MONSTERS);
		break;

		case "Exit_5":
			DialogExit();
			NextDiag.CurrentNode = "in_house";
			LAi_group_MoveCharacter(NPchar, LAI_GROUP_MONSTERS);
		break;
	}
	LanguageCloseFile(tmpLangFileID);
}
