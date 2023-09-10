//#include "DIALOGS\bartender_dialog.h"
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
			Dialog.snd = "voice\THDI\THDI001";

			PlaySound("VOICE\ENGLISH\Dut_m_a_031.wav");

			dialog.text = DLG_TEXT[28] + GetMyFullName(NPChar) + DLG_TEXT[29];
			link.l1 = pcharrepphrase(DLG_TEXT[30] + GetMyFullName(PChar) + DLG_TEXT[31], DLG_TEXT[32] + GetMyFullName(PChar) + DLG_TEXT[33]);
			link.l1.go = "second time";
		
			NextDiag.TempNode = "second time";
		break;
		
		case "second time":
			dialog.text = DLG_TEXT[35];

			if(CheckAttribute(Pchar,"quest.Jupiter_bug_mission") && Pchar.quest.Jupiter_bug_mission == "on")
			{
				if(CheckAttribute(Pchar,"quest.Jupiter_lutG_hint") && Pchar.quest.Jupiter_lutG_hint == "yes")
				{
					link.l1 = DLG_TEXT[37];
					link.l1.go = "lut_G";
				}
			}
		
			if(CheckAttribute(Pchar,"quest.Jupiter_fish_sold") && Pchar.quest.Jupiter_fish_sold == "no")
			{
				link.l2 = DLG_TEXT[34];
				link.l2.go = "papers";
			}
			//fler alternativ hдr

			link.l3 = DLG_TEXT[3];
			link.l3.go = "rum";
			link.l4 = DLG_TEXT[4];
			link.l4.go = "wine";
			link.l5 = DLG_TEXT[5];
			link.l5.go = "beer";
			link.l6 = DLG_TEXT[6];
			link.l6.go = "water";

			//sound scheme ....
			if(CheckAttribute(Pchar,"quest.bar_status") && Pchar.quest.bar_status == "0")
			{
				PlaySound("VOICE\ENGLISH\Dut_m_a_025.wav");
			}
			if(CheckAttribute(Pchar,"quest.bar_status") && Pchar.quest.bar_status == "no_rum")
			{
				PlaySound("OBJECTS\DUEL\man_hit6.wav");
			}

			if(CheckAttribute(Pchar,"quest.bar_status") && Pchar.quest.bar_status == "bought_wine")
			{
				PlaySound("INTERFACE\button2.flac");
				PlaySound("INTERFACE\button2.flac");
			}
			if(CheckAttribute(Pchar,"quest.bar_status") && Pchar.quest.bar_status == "drank_beer")
			{
				PlaySound("AMBIENT\TAVERN\man5.wav");
			}
		break;	

		case "lut_G":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "Exit";
			AddQuestRecord("Jupiters_Moultrie_mission","11");
		break;

		case "papers":
			if(CheckCharacterItem(Pchar,"bladefish"))
			{
				if(!IsEquipCharacterByItem(Pchar, "bladefish"))
				{
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "bladefish");
				}

				dialog.text = DLG_TEXT[36];
				link.l1 = DLG_TEXT[23];
				link.l1.go = "sell_fish";
			}
			else
			{
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "Exit";
			}
		break;

		case "sell_fish":
			Dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "sell_fish1";
		break;	

		case "sell_fish1":
			Dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			AddDialogExitQuest("sell_fish_done");
		break;	

		case "rum":
			Pchar.quest.bar_status = "no_rum";
			Pchar.quest.bar_rum = "1";
			Dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "second time";
		break;	

		case "wine":
			Dialog.text = DLG_TEXT[9];
			if (makeint(pchar.money) >= 250)
			{
				link.l1 = DLG_TEXT[10];
				link.l1.go = "wine1";
				link.l2 = DLG_TEXT[13];
				link.l2.go = "second time";	//wine option remains
			}
			else
			{
				Pchar.quest.bar_wine = "1";	//means no more wine option
				link.l1 = DLG_TEXT[8];
				link.l1.go = "second time";
			}
		break;

		case "wine1":
			Pchar.quest.bar_status = "bought_wine";
			Pchar.quest.bar_wine = "1";
			Log_SetStringToLog("Wonder what kind of import that is!");
			GiveItem2Character(Pchar, "potionwine2");
			AddMoneyToCharacter(pchar, -250);
			PlaySound("INTERFACE\coins7.wav");
			Dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "second time";	
		break;	

		case "beer":
			Dialog.text = DLG_TEXT[14];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[15];
				link.l1.go = "beer1";
				link.l2 = DLG_TEXT[18];
				link.l2.go = "second time";	//beer option remains
			}
			else
			{
				Pchar.quest.bar_status = "drank_no_beer";
				Pchar.quest.bar_beer = "2";	//means no more beer option
				link.l1 = DLG_TEXT[8];
				link.l1.go = "second time";
			}
		break;
	
		case "beer1":
			PlaySound("AMBIENT\TAVERN\man6.wav");
			Pchar.quest.bar_status = "drank_beer";
			AddMoneyToCharacter(pchar, -5);
			AddpartyExp(pchar, 10);
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "second time";
		break;

		case "water":
			Dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "exit";
		break;
	
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
