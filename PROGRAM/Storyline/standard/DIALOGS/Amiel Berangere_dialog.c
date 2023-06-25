//#include "DIALOGS\Amiel Berangere_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча

	
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			//--------Запись в журнал
			AddQuestRecord("Story_1stTaskReceived", 8);
			//--------Получение предмета			//--------Постановка Вирджила Буна в первый порт Фале де Флер
			ChangeCharacterAddressGroup(characterFromID("Virgile Boon"), "Falaise_de_Fleur_port_01", "goto", "goto1");
			SetCharacterShipLocation(characterFromID("Virgile Boon"),"Falaise_de_Fleur_port_01");
		break;
		
		case "exit2":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	
		case "Fight_exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("blaze_fighting_with_amiel_berangere");
		break;

		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			
			PChar.quest.Story_AskAboutBerangere = "2";
			//Characters[GetCharacterIndex("Amiel Berangere")].act.immortal = false;

			Pchar.quest.Story_ReturnToFFPortToFindBoon.win_condition.l1 = "location";
			Pchar.quest.Story_ReturnToFFPortToFindBoon.win_condition.l1.location = "Falaise_de_Fleur_port_01";
			Pchar.quest.Story_ReturnToFFPortToFindBoon.win_condition = "Story_ReturnToFFPortToFindBoon";


			Diag.TempNode = "Second time";
			
			dialog.snd = "Voice\AMBE\AMBE001";
			d.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, Pchar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
			Link.l1 = GetMyName(PChar) + DLG_TEXT[2];
			Link.l1.go = "Node_1";
		break;

		case "Node_1":
			dialog.snd = "Voice\AMBE\AMBE002";
			d.Text = GetMyName(NPChar) + DLG_TEXT[3] + GetMyName(Pchar) + DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "Node_2";
		break;

		case "Node_2":
			dialog.snd = "Voice\AMBE\AMBE003";
			d.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "node_3";
		break;

		case "Node_3":
			dialog.snd = "Voice\AMBE\AMBE004";
			d.Text = DLG_TEXT[8]; 
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "Node_4";
			Link.l2 = DLG_TEXT[10];
			Link.l2.go = "Node_5";
			Link.l3 = DLG_TEXT[11];
			Link.l3.go = "Node_6";
		break;

		case "Node_4":
			dialog.snd = "Voice\AMBE\AMBE005";
			d.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "Fight_exit";
			Link.l2 = DLG_TEXT[14];
			Link.l2.go = "Node_5";
		break;

		case "Node_5":
			dialog.snd = "Voice\AMBE\AMBE006";
			d.Text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "node_7";
		break;
	
		case "Node_6":
			dialog.snd = "Voice\AMBE\AMBE007";
			d.Text = DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "node_8";
		break;
	
		case "Node_7":
			dialog.snd = "Voice\AMBE\AMBE008";
			d.Text = DLG_TEXT[19];
			if(makeint(PChar.money) >= 3000)
			{
				Link.l1 = DLG_TEXT[20];
				Link.l1.go = "Node_9";
				Link.l2 = DLG_TEXT[21];
				Link.l2.go = "Node_10";
			}
			else
			{
				Link.l1 = DLG_TEXT[22];
				Link.l1.go = "Node_10";
				
			}
		break;

		case "Node_8":
			if(CalcCharacterSkill(PChar,SKILL_LEADERSHIP) >= 3) // NK
			{
				dialog.snd = "Voice\AMBE\AMBE009";
				d.Text = DLG_TEXT[23];
				Link.l1 = DLG_TEXT[24];
				Link.l1.go = "Node_11";
				if(CalcCharacterSkill(PChar,SKILL_LEADERSHIP) >= 5) // NK
				{
					Link.l2 = DLG_TEXT[25];
					Link.l2.go = "Node_work";
				}
			}
			else
			{
				dialog.snd = "Voice\AMBE\AMBE010";
				d.Text = DLG_TEXT[26] + GetMyName(Pchar) + DLG_TEXT[27];
				Link.l1 = DLG_TEXT[28];
				Link.l1.go = "Node_4";
				Link.l2 = DLG_TEXT[29];
				Link.l2.go = "Node_5";
			}
		break;

		case "Node_9":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, -3000);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1000);
				AddPartyExpChar(pchar, "Sneak", 10);
			}
			else { AddPartyExp(pchar, 1000); }
			dialog.snd = "Voice\AMBE\AMBE011";
			d.Text = DLG_TEXT[30];
			Link.l1 = DLG_TEXT[31];
			Link.l1.go = "Node_11";
		break;

		case "Node_10":
			dialog.snd = "Voice\AMBE\AMBE012";
			d.Text = DLG_TEXT[32] + GetMyName(Pchar) + DLG_TEXT[33];
			Link.l1 = DLG_TEXT[34];
			Link.l1.go = "Node_4";
			Link.l2 = DLG_TEXT[35];
			Link.l2.go = "Node_6";
		break;

		case "Node_11":
			GiveItem2Character(Pchar,"Story_Gramota");
			dialog.snd = "Voice\AMBE\AMBE013";
			d.Text = DLG_TEXT[36] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[37])]) + DLG_TEXT[38] + Characters[GetCharacterIndex(DLG_TEXT[39])].lastname + DLG_TEXT[40];
			Link.l1 = DLG_TEXT[41];
			Link.l1.go = "node_12";
			Link.l1 = DLG_TEXT[42];
			Link.l1.go = "node_13";
			Link.l1 = DLG_TEXT[43];
			Link.l1.go = "exit";
			AddDialogExitQuest("amiel_go_away");
		break;

		case "Node_12":
			dialog.snd = "Voice\AMBE\AMBE014";
			d.Text = DLG_TEXT[44];
			Link.l1 = DLG_TEXT[45] + GetMyName(NPChar) + DLG_TEXT[46];
			Link.l1.go = "Exit";
		break;

		case "Node_13":
			dialog.snd = "Voice\AMBE\AMBE015";
			d.Text = DLG_TEXT[47];
			Link.l1 = DLG_TEXT[48] + GetMyName(NPChar) + DLG_TEXT[49];
			Link.l1.go = "Exit";
		break;

		case "Node_work":
			dialog.snd = "Voice\AMBE\AMBE016";
			d.Text = DLG_TEXT[50];
			Link.l1 = DLG_TEXT[51];
			Link.l1.go = "Node_work_1";
		break;

		case "Node_work_1":
			dialog.snd = "Voice\AMBE\AMBE017";
			d.Text = DLG_TEXT[52];
			Link.l1 = DLG_TEXT[53];
			Link.l1.go = "Node_work_2";
		break;

		case "Node_work_2":
			dialog.snd = "Voice\AMBE\AMBE018";
			d.Text = DLG_TEXT[54];
			if(makeint(PChar.money) >= 10000)
			{
				Link.l1 = DLG_TEXT[55];
				Link.l1.go = "Node_work_3";
				Link.l2 = DLG_TEXT[56] + GetMyName(NPChar) + DLG_TEXT[57];
				Link.l2.go = "Node_10";
			}
			else
			{
				Link.l1 = DLG_TEXT[58];
				Link.l1.go = "Node_10";
			}
		break;

		case "Node_work_3":
			dialog.snd = "Voice\AMBE\AMBE019";
		    PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, -10000);
			d.Text = DLG_TEXT[59] + GetMyName(Pchar) + DLG_TEXT[60];
			Link.l1 = DLG_TEXT[61];
			Link.l1.go = "Node_work_4";
		break;

		case "Node_work_4":
			dialog.snd = "Voice\AMBE\AMBE020";
			d.Text = DLG_TEXT[62] + NPChar.lastname + DLG_TEXT[63] + Characters[GetCharacterIndex(DLG_TEXT[64])].lastname + DLG_TEXT[65]; 
			Link.l1 = DLG_TEXT[66] + GetMyName(NPChar) + DLG_TEXT[67];
			Link.l1.go = "exit2";
			AddDialogExitQuest("Ewan_sunk_Boon");
		break;

		case "Second time":
			dialog.snd = "Voice\AMBE\AMBE021";
			d.Text = DLG_TEXT[68] + GetMyName(Pchar) + DLG_TEXT[69];
			Link.l1 = DLG_TEXT[70];
			Link.l1.go = "Second time_2";
		break;
		
		case "Second time_2":
			dialog.snd = "Voice\AMBE\AMBE022";
			Preprocessor_Add("lad", GetMyAddressForm(NPChar, PChar, ADDR_INFORMAL, false, false)); // DeathDaisy
			d.Text = DLG_TEXT[71];
			Link.l1 = DLG_TEXT[72];
			Link.l1.go = "exit";
		break;

		}
}

