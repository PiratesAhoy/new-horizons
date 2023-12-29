//#include "DIALOGS\Leborio Drago_dialog.h"

/* 
TIH -->
	The 'pismena' quest progression helper, explained:

	The progression of the main quest with this character can be a pain in the ass if you do not
	follow the steps of the quest precisely. If you deviate and try doing another main quest
	before you get to the tavern after rescueing/talking to leborio, you can really become
	confused on how to continue with the search for danielle.

	What this helper does, is set an outside attribute that the tavern keeper will use if it is
	set to "begin". This will make him mention danielle and start the next step of the quest.
	It will then set the attribute to 'end' so that it is no longer used (thus not re-starting
	the same quest step).

	The helper attribute is set below in three places where the quest should be allowed to
	progress after dealing with leborio in the various ways you can. Even if you "fight" him
	when he asks to join you, the progression of the main quest will continue. You do NOT have
	to hire him to progress the quest. He is useless really.

	When the 'pismena' attribute is set to 'end', that quest step is now dead and closed. Thus,
	why the setting of that attribute will only occur if it has NOT been set to 'end'.

	If that makes any sense.
TIH <--
*/

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
			Dialog.snd = "dialogs\0\009";
			
			if (npchar.location == "Oxbay_mine")
			{
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit";
			}

			if (pchar.quest.main_line == "slave_in_oxbay_mine_begin")
			{
				Dialog.Text = DLG_TEXT[4];
				Link.l1 = DLG_TEXT[5];
				Link.l1.go = "node_2";
			}
			if (pchar.quest.main_line == "talk_with_Liborio")
			{
				Dialog.Text = DLG_TEXT[6];
				Link.l1 = DLG_TEXT[7];
				Link.l1.go = "learn";
			}
			if (pchar.quest.main_line == "resque_leborio")
			{
				dialog.text = DLG_TEXT[8];
				link.l1 = DLG_TEXT[9];
				link.l1.go = "bad_story";
			}
			if (pchar.quest.main_line == "resque_leborio_bad")
			{
				dialog.text = DLG_TEXT[10];
				link.l1 = DLG_TEXT[11];
				link.l1.go = "hire";
			}
			if (pchar.quest.main_line == "resque_leborio_denied")
			{
				dialog.text = DLG_TEXT[12];
				link.l1 = DLG_TEXT[13];
				link.l1.go = "exit";
				link.l2 = DLG_TEXT[14];
				link.l2.go = "learn_4";
			}
			if (npchar.quest.hire == "not_hired" && pchar.location == "Falaise_De_Fleur_tavern")
			{
				dialog.text = DLG_TEXT[15];
				link.l1 = DLG_TEXT[16];
				link.l1.go = "hire_4";
				link.l2 = DLG_TEXT[17];
				link.l2.go = "exit";
			}
			if (pchar.quest.main_line == "resque_from_mines_denied")
			{
				dialog.text = DLG_TEXT[18];
				link.l1 = DLG_TEXT[19];
				link.l1.go = "resque_from_mines_denied_2";
			}
			if (pchar.quest.main_line == "lets_go_mines")
			{
				dialog.text = DLG_TEXT[20];
				link.l1 = DLG_TEXT[21];
				link.l1.go = "lets_go_exit";
			}
			if (pchar.quest.main_line == "after_speak_with_leborio" && npchar.quest.hire == "ask_for_hire")
			{
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];
				link.l1.go = "passenger_exit";
				link.l2 = DLG_TEXT[24];
				link.l2.go = "fight";
				if (!CheckQuestAttribute("pismena","end")) { pchar.quest.pismena = "begin"; } // TIH quest progression helper attr Nov1'06
			}
			if (pchar.quest.main_line == "talk_with_Liborio_2")
			{
				Dialog.Text = DLG_TEXT[25];
				Link.l1 = DLG_TEXT[26];
				Link.l1.go = "knowlege";
			}
			if( CheckQuestAttribute("FindMysteriousTablet","TabletBroken") )
			{
				Dialog.Text = DLG_TEXT[27];
				link.l1 = DLG_TEXT[28];
				link.l1.go = "Tablet_copy_1";
			}
			if( CheckQuestAttribute("FindMysteriousTablet","ToMine") )
			{
				Dialog.Text = DLG_TEXT[29];
				link.l1 = DLG_TEXT[30];
				link.l1.go = "knowlege";
			}
			NextDiag.TempNode = "first time";
		break;

		case "Tablet_copy_1":
			Dialog.Text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "exit";
		break;

		case "knowlege":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "learn_4";
			link.l2 = DLG_TEXT[35];
			link.l2.go = "bad_learn";
		break;

		case "passenger_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogexitQuest("leborio_drago_passenger_exit");
		break;

		case "fight":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit";
			AddDialogExitQuest("leborio_drago_fight_exit");
		break;

		case "lets_go_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("lets_go_begin");
		break;

		case "resque_from_mines_denied_2":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "resque_from_mines_denied_3";
		break;
		
		case "resque_from_mines_denied_3":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "resque_from_mines_denied_4";
		break;

		case "resque_from_mines_denied_4":
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "resque_from_mines_denied_5";
		break;

		case "resque_from_mines_denied_5":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "resque_from_mines_denied_6";
		break;

		case "resque_from_mines_denied_6":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "resque_from_mines_denied_7";
		break;

		case "resque_from_mines_denied_7":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "resque_from_mines_denied_8";
		break;

		case "resque_from_mines_denied_8":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "resque_from_mines_denied_9";
		break;

		case "resque_from_mines_denied_9":
			if (PChar.sex == "woman") dialog.text = DLG_TEXT[112];
			else dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "resque_from_mines_denied_10";
		break;

		case "resque_from_mines_denied_10":
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "resque_from_mines_denied_11";
		break;

		case "resque_from_mines_denied_11":
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "resque_from_mines_denied_exit";
			AddQuestRecord("search_danielle", 15);
		break;

		case "resque_from_mines_denied_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("wait_for_resque_from_mines");
		break;

		case "learn":
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "learn_2";
		break;

		case "learn_2":
			dialog.text = DLG_TEXT[60] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[61])]) + DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "learn_3";
			link.l2 = DLG_TEXT[65];
			link.l2.go = "bad_learn";
		break; 

		case "learn_3":
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "learn_4";
			link.l2 = DLG_TEXT[68];
			link.l2.go = "bad_learn";
		break;

		case "learn_4":
			dialog.text = DLG_TEXT[69];
			pchar.quest.main_line = "ask_for_resque_leborio";
			link.l1 = DLG_TEXT[70];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[71];
			link.l2.go = "bad_learn";
//			AddQuestRecord("search_danielle", 17); // Too soon, this point can lead to either making the deal or threatening Leborio.
		break;

		case "bad_learn":
			if (PChar.sex == "woman") dialog.text = DLG_TEXT[114];
			else dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "bad_story";
		break;

		case "bad_story":
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "bad_story_2";
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromID("Danielle"))));
			if (pchar.quest.main_line == "resque_leborio") AddQuestRecord("search_danielle", 17);
			else AddQuestRecord("search_danielle", 18);
			Preprocessor_Remove("pronoun");
			Preprocessor_Remove("Danielle");
			NextDiag.tempnode = "first time";
		break;

		case "bad_story_2":
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "bad_story_3";
		break;

		case "bad_story_3":
			dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79];
			if (pchar.id == "Blaze")
			{
				link.l1.go = "bad_story_4";
			}
			else
			{
				pchar.quest.FindMysteriousTablet = "FindCopy";
				if (npchar.location == "Oxbay_mine")
				{
					link.l1.go = "exit";
					pchar.quest.main_line = "bad_story";
				}
				else
				{
					link.l1.go = "hire";
				}
			}
		break;

		case "bad_story_4":
			dialog.text = DLG_TEXT[80];
			link.l1 = DLG_TEXT[81];
			link.l1.go = "bad_story_5";
		break;

		case "bad_story_5":
			if (PChar.sex == "woman") dialog.text = DLG_TEXT[113];
			else dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			if (pchar.quest.main_line == "resque_leborio")
			{
				link.l1.go = "hire";
				pchar.quest.main_line = "hire_leborio";
			}
			else
			{
				link.l1.go = "exit";
				pchar.quest.main_line = "after_speak_with_leborio";
				if (!CheckQuestAttribute("pismena","end")) { pchar.quest.pismena = "begin"; } // TIH quest progression helper attr Nov1'06
			}
		break;

		case "hire":
			dialog.text = DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "hire_2";
			OfficersReaction("good");
			if (!CheckQuestAttribute("pismena","end")) { pchar.quest.pismena = "begin"; } // TIH quest progression helper attr Nov1'06
		break;

		case "hire_2":
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[87];
			link.l1.go = "hire_3";
		break;

		case "hire_3":
			dialog.text = DLG_TEXT[88];
			link.l1 = DLG_TEXT[89];
			link.l1.go = "hire_4";
			link.l2 = DLG_TEXT[90];
			link.l2.go = "hire_denied";
		break;

		case "hire_4":
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "hire_5";
		break;

		case "hire_5":
			dialog.text = DLG_TEXT[93];
			if (makeint(pchar.money) >= 1500)
			{
				link.l1 = DLG_TEXT[94];
				link.l1.go = "hire_6";
			}
			link.l2 = DLG_TEXT[95];
			link.l2.go = "hire_denied";
			if(pchar.id == "Blaze")
			{
				pchar.quest.main_line = "to_isla_muelle";
			}
		break;
		
		case "hire_6":
			dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97] + GetMyShipNameShow(PChar) + DLG_TEXT[98];
			link.l1.go = "exit";
			npchar.quest.hire = "hired";
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, -1500);
			AddPassenger(pchar, npchar, -1);
			GiveItem2Character(npchar, "blade4");
			EquipCharacterByItem(npchar, "blade4");	
			npchar.dialog.currentnode = "hired";		
		break;

		case "hire_denied":
			dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[100];
			link.l1.go = "exit";
			AddDialogExitQuest("leborio_hire_denied");
			npchar.quest.hire = "not_hired";
		break;

		case "node_2":
			dialog.text = DLG_TEXT[101];
			link.l1 = DLG_TEXT[102];
			link.l1.go = "node_3";
		break;

		case "node_3":
			dialog.text = DLG_TEXT[103];
			link.l1 = DLG_TEXT[104];
			link.l1.go = "node_4";
		break;

		case "node_4":
			dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[106];
			link.l1.go = "node_5";
			pchar.quest.main_line = "slave_in_oxbay_mine_begin_1";
			link.l2 = DLG_TEXT[107];
			link.l2.go = "node_5";
			AddQuestRecord("search_danielle", 12);
		break;

		case "node_5":
			dialog.text = DLG_TEXT[108];
			link.l1 = DLG_TEXT[109];
			link.l1.go = "exit";
			AddDialogExitQuest("miner_again_kick_exit");
		break;

		case "Exit_2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			pchar.quest.main_line = "blaze_in_mine";
			EndQuestMovie();TrackQuestMovie("end","Leborio Drago_dialog.c -> Exit_2");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			EndQuestMovie();TrackQuestMovie("end","Leborio Drago_dialog.c -> Exit");
		break;
		
		case "hired":
			Dialog.text = DLG_TEXT[110];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "exit";
		break;
	}
}
