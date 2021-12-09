//#include "DIALOGS\researcher_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar, PChar, d; 
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------ƒиалог первый - перва€ встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\REDI\REDI001";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (pchar.quest.main_line == "resque_researcher_good")
			{
				Dialog.snd = "voice\REDI\REDI002";
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit";
			}
			if (pchar.quest.main_line == "resque_researcher_bad")
			{
				Dialog.snd = "voice\REDI\REDI003";
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "exit";
			}
			if (pchar.quest.main_line == "resque_researcher_complete")
			{
				Dialog.snd = "voice\REDI\REDI004";
				Dialog.Text = DLG_TEXT[6] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[7];
				Link.l1 = DLG_TEXT[8];
				Link.l1.go = "to_oxbay_by_prisoner_escape_researcher_2";
			}
			if (pchar.quest.main_line == "meet_in_lighthouse")
			{
				Dialog.snd = "voice\REDI\REDI005";
				dialog.text = DLG_TEXT[9];
				link.l1 = DLG_TEXT[10];
				link.l1.go = "exit";
				AddDialogExitQuest("first_speak_with_danielle_in_lighthouse")
			}
			if (pchar.quest.main_line == "blaze_search_danielle_again" || pchar.quest.main_line == "blaze_search_danielle_again_10")
			{
				Dialog.snd = "voice\REDI\REDI006";
				Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromID("Danielle"))));
				dialog.text = DLG_TEXT[11] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[12])]) + DLG_TEXT[13];
				link.l1 = DLG_TEXT[14];
				link.l1.go = "blaze_search_danielle_again_2";
			}
			if (pchar.quest.main_line == "without_ship")
			{
				Dialog.snd = "voice\REDI\REDI007";
				dialog.text = DLG_TEXT[15] + GetMyName(Pchar) + DLG_TEXT[16];
				link.l1 = DLG_TEXT[17];
				link.l1.go = "without_ship";
			}
			if (pchar.quest.main_line == "see_yaht")
			{
				Dialog.snd = "voice\REDI\REDI008";
				dialog.text = DLG_TEXT[18];
				link.l1 = DLG_TEXT[19];
				link.l1.go = "see_yaht_2";
			}
			Diag.TempNode = "first time";
		break;


		case "see_yaht_2":
			Dialog.snd = "voice\REDI\REDI009";
			dialog.text = DLG_TEXT[20] + GetMyName(Pchar) + DLG_TEXT[21];
			link.l1 = DLG_TEXT[22] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[23])]) + DLG_TEXT[24];
			link.l1.go = "see_yaht_exit";
		break;

		case "see_yaht_exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
			Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromID("Danielle"))));
			Preprocessor_AddQuestData("pronoun2", XI_ConvertString(GetMyPronounObj(characterFromID("Danielle"))));
			AddQuestRecord("Where_are_i", 12);
			Preprocessor_Remove("pronoun2");
			Preprocessor_Remove("pronoun");
			Preprocessor_Remove("Danielle");
		break;
		
		case "without_ship":
			Dialog.snd = "voice\REDI\REDI010";
			if (Characters[GetCharacterIndex("Danielle")].sex == "woman") Preprocessor_Add("pronoun3", XI_ConvertString("her"));
			else Preprocessor_Add("pronoun3", XI_ConvertString("his"));
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[27])]) + DLG_TEXT[28];
			link.l1.go = "without_ship_2";
		break;

		case "without_ship_2":
			Dialog.snd = "voice\REDI\REDI011";
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(characterFromID("Danielle"))));
			if (Characters[GetCharacterIndex("Danielle")].sex == "woman") Preprocessor_Add("girl", XI_ConvertString("girl"));
			else Preprocessor_Add("girl", XI_ConvertString("lad"));
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "without_ship_3";
		break;

		case "without_ship_3":
			Dialog.snd = "voice\REDI\REDI012";
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "without_ship_4";
		break;

		case "without_ship_4":
			Dialog.snd = "voice\REDI\REDI013";
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "without_ship_exit";
		break;

		case "without_ship_exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("without_ship_complete");
		break;

		case "blaze_search_danielle_again_2":
			if (pchar.quest.main_line != "blaze_search_danielle_again_10")
			{
				Preprocessor_AddQuestData("Danielle", GetMyName(CharacterFromID("Danielle")));
				Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromID("Danielle"))));
				Preprocessor_AddQuestData("pronoun2", XI_ConvertString(GetMyPronounObj(characterFromID("Danielle"))));
				AddQuestRecord("Where_are_i", 11);
				Preprocessor_Remove("pronoun2");
				Preprocessor_Remove("pronoun");
				Preprocessor_Remove("Danielle");
				AddDialogExitQuest("prepare_for_storm");
			}
			Dialog.snd = "voice\REDI\REDI014";
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromID("Danielle"))));
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(characterFromID("Danielle"))));
			if (Characters[GetCharacterIndex("Danielle")].sex == "woman") Preprocessor_Add("girl", XI_ConvertString("girl"));
			else Preprocessor_Add("girl", XI_ConvertString("lad"));
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "exit";
		break;

		case "to_oxbay_by_prisoner_escape_researcher_2":
			Dialog.snd = "voice\REDI\REDI015";
			Dialog.Text = DLG_TEXT[37];
			Link.l1 = DLG_TEXT[38] + GetMyFullName(PChar) + DLG_TEXT[39];
			Link.l1.go = "to_oxbay_by_prisoner_escape_researcher_3";
		break;

		case "to_oxbay_by_prisoner_escape_researcher_3":
			Dialog.snd = "voice\REDI\REDI016";
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "exit_from_greenford";
		break;

		case "exit_from_greenford":
			AddQuestRecord("resque_researcher", 8);
			CloseQuestHeader("resque_researcher");
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("blaze_with_researcher_to_lighthouse");
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "Danger_exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();

	/*		
			//------------------TEMPORARY--------------------///
			RemovePassenger(Pchar, &Characters[getCharacterIndex("Researcher")]);
			RemovePassenger(Pchar, &Characters[getCharacterIndex("Danielle")]);
			ChangeCharacterAddressGroup(&Characters[getCharacterIndex("Danielle")], "Labirint_1", "reload", "reload27");
			ChangeCharacterAddressGroup(&Characters[getCharacterIndex("Researcher")], "Labirint_1", "reload", "reload27");

			Pchar.quest.Story_TEMPQUEST.win_condition.l1 = "location";
			Pchar.quest.Story_TEMPQUEST.win_condition.l1.character = PChar.id;
			Pchar.quest.Story_TEMPQUEST.win_condition.l1.location = "Labirint_1";
			Pchar.quest.Story_TEMPQUEST.win_condition = "Story_TEMPQUEST";
			Pchar.quest.Story_TEMPQUEST.fail_condition = "Story_TEMPQUEST";*/

		break;

		case "AlreadyTranslated_exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			AddPassenger(Pchar, characterFromID("Researcher"), false);
			DoQuestCheckDelay("Story_VoyageToKhaelRoaBegan", 2.0);
		break;

		case "Translation_exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			//StartQuestMovie(true,true,true);
			AddDialogExitQuest("Story_MovingToLighthouse");
			//DoQuestCheckDelay("Story_MovingToLighthouse", 1.0);
		break;

		case "NeedSomeTime_Exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			DoQuestCheckDelay("Story_LighthouseSpeakWithDanielle", 1.0);
		break;

		case "TempleWillBlast_exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();

			//«десь надо включить ролик убегани€ из храма.
			
		break;

		case "TempleWillBlast":
			Dialog.snd = "voice\REDI\REDI017";
			d.Text = DLG_TEXT[42];
			Link.l1 = DLG_TEXT[43];
			Link.l1.go = "TempleWillBlast_1";
		break;
		
		case "TempleWillBlast_1":
			Dialog.snd = "voice\REDI\REDI017";
			d.Text = DLG_TEXT[44];
			Link.l1 = DLG_TEXT[45];
			Link.l1.go = "TempleWillBlast_2";
		break;
		
		case "TempleWillBlast_2":
			Dialog.snd = "voice\REDI\REDI017";
			d.Text = DLG_TEXT[46];
			Link.l1 = DLG_TEXT[47];
			Link.l1.go = "TempleWillBlast_3";
		break;

		case "TempleWillBlast_3":
			Dialog.snd = "voice\REDI\REDI018";
			d.Text = DLG_TEXT[125];
			Link.l1 = DLG_TEXT[126];
			Link.l1.go = "TempleWillBlast_exit";
			
			Diag.Tempnode = "Home_again";
			AddDialogExitQuest("Story_LeavingKhaelRoa");
			AddQuestRecord("After_Final", 5);
			pchar.quest.leave_kr = "true";
		break;

		case "I go to the right":
			Dialog.snd = "voice\REDI\REDI020";
			Preprocessor_Add("Pronoun_upper", FirstLetterUp(XI_ConvertString(GetMyPronounSubj(CharacterFromID("Danielle")))));
			d.Text = DLG_TEXT[48];
			Link.l1 = DLG_TEXT[49];
			Link.l1.go = "I go to the right_1";
		break;

		case "I go to the right_1":
			Dialog.snd = "voice\REDI\REDI021";
			if (Characters[GetCharacterIndex("Danielle")].sex == "woman") Preprocessor_Add("pronoun3", XI_ConvertString("her"));
			else Preprocessor_Add("pronoun3", XI_ConvertString("his"));
			d.Text = DLG_TEXT[50] + GetMyName(Pchar) + DLG_TEXT[51];
			Link.l1 = DLG_TEXT[52];
			Link.l1.go = "exit";
			AddDialogExitQuest("researcher_I_go_to_the_right_exit");
		break;

		case "Split":
			Dialog.snd = "voice\REDI\REDI022";
			d.Text = DLG_TEXT[53];
			Link.l1 = DLG_TEXT[54];
			Link.l1.go = "Split_1";
		break;

		case "Split_1":
			Dialog.snd = "voice\REDI\REDI023";
			d.Text = DLG_TEXT[55];
			Link.l1 = DLG_TEXT[56];
			Link.l1.go = "exit";
			AddDialogExitQuest("researcher_Split_exit");
		break;


		case "Danger":
			Diag.TempNode = "Gogogo";
			Dialog.snd = "voice\REDI\REDI024";
			d.Text = DLG_TEXT[57];
			Link.l1 = DLG_TEXT[58];
			Link.l1.go = "Danger_1";
		break;

		case "Danger_1":
			Dialog.snd = "voice\REDI\REDI025";
			d.Text = DLG_TEXT[59];
			Link.l1 = DLG_TEXT[60];
			Link.l1.go = "Danger_2";
		break;

		case "Danger_2":
			Dialog.snd = "voice\REDI\REDI026";
			d.Text = DLG_TEXT[61];
			Link.l1 = DLG_TEXT[62];
			if (makeint(environment.time) < 7.0 || makeint(environment.time) > 18.0)
			{
				link.l1.go = "danger_3";
			}
			else
			{
				Link.l1.go = "Danger_exit";
			}
		break;

		case "danger_3":
			Dialog.snd = "voice\REDI\REDI027";
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			Link.l1.go = "exit";
			AddDialogExitQuest("researcher_danger_wait_exit");
		break;

		case "Gogogo":
			Dialog.snd = "voice\REDI\REDI028";
			d.Text = DLG_TEXT[65];
			Link.l1 = DLG_TEXT[66];
			Link.l1.go = "Exit";
		break;


		case "Translation":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\REDI\REDI029";

			d.Text = DLG_TEXT[67] + GetMyName(Pchar) + DLG_TEXT[68];
			Link.l1 = DLG_TEXT[69];
			Link.l1.go = "Translation_1";
		break;

		case "Translation_1":
			Dialog.snd = "voice\REDI\REDI030";
			d.Text = DLG_TEXT[70];
			Link.l1 = DLG_TEXT[71] + GetMyName(NPChar) + DLG_TEXT[72];
			Link.l1.go = "Translation_2";
		break;

		case "Translation_2":
			Dialog.snd = "voice\REDI\REDI031";
			d.Text = DLG_TEXT[73];
			Link.l1 = DLG_TEXT[74];
			Link.l1.go = "Translation_3";
		break;

		case "Translation_3":
			Dialog.snd = "voice\REDI\REDI032";
			d.Text = DLG_TEXT[75];
			Link.l1 = DLG_TEXT[76];
			Link.l1.go = "Translation_exit";
		break;

		case "NeedSomeTime":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\REDI\REDI033";

			d.Text = DLG_TEXT[77];
			Link.l2 = DLG_TEXT[78];
			Link.l2.go = "NeedSomeTime_1";
		break;

		case "NeedSomeTime_1":
			Dialog.snd = "voice\REDI\REDI034";
			d.Text = DLG_TEXT[79];
			Link.l1 = DLG_TEXT[80];
			Link.l1.go = "NeedSomeTime_2";
			
		break;

		case "NeedSomeTime_2":
			Dialog.snd = "voice\REDI\REDI035";
			d.Text = DLG_TEXT[81] + GetMyName(Pchar) + DLG_TEXT[82];
			Link.l1 = DLG_TEXT[83];
			Link.l1.go = "NeedSomeTime_3";
		break;

		case "NeedSomeTime_3":
			Dialog.snd = "voice\REDI\REDI036";
			d.Text = DLG_TEXT[84];
			Link.l1 = DLG_TEXT[85];
			Link.l1.go = "NeedSomeTime_4";
		break;

		case "NeedSomeTime_4":
			Dialog.snd = "voice\REDI\REDI037";
			d.Text = DLG_TEXT[86] + GetMyName(Pchar) + DLG_TEXT[87];
			Link.l1 = DLG_TEXT[88];
			Link.l1.go = "NeedSomeTime_5";
		break;

		case "NeedSomeTime_5":
			Dialog.snd = "voice\REDI\REDI038";
			d.Text = DLG_TEXT[89];
			Link.l1 = DLG_TEXT[90];
			Link.l1.go = "NeedSomeTime_Exit";
		break;

		case "AlreadyTranslated":
			Dialog.snd = "voice\REDI\REDI039";
			d.Text = DLG_TEXT[91];
			Link.l1 = DLG_TEXT[92];
			Link.l1.go = "AlreadyTranslated_1";
		break;

		case "AlreadyTranslated_1":
			Dialog.snd = "voice\REDI\REDI040";
			d.Text = DLG_TEXT[93];
			Link.l1 = DLG_TEXT[94];
			Link.l1.go = "AlreadyTranslated_2";
		break;

		case "AlreadyTranslated_2":
			Dialog.snd = "voice\REDI\REDI041";
			d.Text = DLG_TEXT[95];
			Link.l1 = DLG_TEXT[96];
			Link.l1.go = "AlreadyTranslated_3";
		break;

		case "AlreadyTranslated_3":
			Dialog.snd = "voice\REDI\REDI042";
			d.Text = DLG_TEXT[97];
			Link.l1 = DLG_TEXT[98];
			Link.l1.go = "AlreadyTranslated_4";
		break;

		case "AlreadyTranslated_4":
			Dialog.snd = "voice\REDI\REDI043";
			d.Text = DLG_TEXT[99];
			Link.l1 = DLG_TEXT[100] + Characters[GetCharacterIndex(DLG_TEXT[101])].lastname + DLG_TEXT[102];
			Link.l1.go = "AlreadyTranslated_5";
		break;

		case "AlreadyTranslated_5":
			Dialog.snd = "voice\REDI\REDI044";
			Diag.TempNode = "I'll translate that";
			d.Text = DLG_TEXT[103];
			Link.l1 = DLG_TEXT[104];
			Link.l1.go = "AlreadyTranslated_exit";
		break;

		case "I'll translate that":
			Dialog.snd = "voice\REDI\REDI045";
			Diag.TempNode = "I'll translate that";
			d.Text = DLG_TEXT[105];
			Link.l1 = DLG_TEXT[106];
			Link.l1.go = "Exit";
		break;

		case "Alcove_talk":			
			Dialog.snd = "voice\REDI\REDI046";
			d.Text = DLG_TEXT[107];
			Link.l1 = DLG_TEXT[108];
			Link.l1.go = "Alcove_talk_1";
		break;

		case "Alcove_talk_1":			
			Dialog.snd = "voice\REDI\REDI047";
			d.Text = DLG_TEXT[109];
			Link.l1 = DLG_TEXT[110];
			Link.l1.go = "Alcove_talk_2";
		break;

		case "Alcove_talk_2":			
			Dialog.snd = "voice\REDI\REDI048";
			d.Text = DLG_TEXT[111];
			Link.l1 = DLG_TEXT[112];
			Link.l1.go = "exit";
			AddDialogExitQuest("Story_ResearcherReadsDanielleTalks");			
		break;

		case "ItsATrap":			
			Dialog.snd = "voice\REDI\REDI049";
			d.Text = DLG_TEXT[113];
			Link.l1 = DLG_TEXT[114];
			Link.l1.go = "ItsATrap_1";
		break;

		case "ItsATrap_1":			
			Dialog.snd = "voice\REDI\REDI050";
			d.Text = DLG_TEXT[115];
			Link.l1 = DLG_TEXT[116];
			Link.l1.go = "ItsATrap_2";
		break;

		case "ItsATrap_2":			
			Dialog.snd = "voice\REDI\REDI051";
			d.Text = DLG_TEXT[117];
			Link.l1 = DLG_TEXT[118];
			Link.l1.go = "ItsATrap_3";
		break;

		case "ItsATrap_3":			
			Dialog.snd = "voice\REDI\REDI052";
			d.Text = DLG_TEXT[119];
			Link.l1 = DLG_TEXT[120];
			Link.l1.go = "ItsATrap_4";
		break;

		case "ItsATrap_4":			
			Dialog.snd = "voice\REDI\REDI053";
			d.Text = DLG_TEXT[121];
			Link.l1 = DLG_TEXT[122];
			Link.l1.go = "ItsATrap_5";
		break;

		case "ItsATrap_5":		
			Dialog.snd = "voice\REDI\REDI054";
			AddDialogExitQuest("Story_LeavingTheTemple");
			d.Text = DLG_TEXT[123];
			Link.l1 = DLG_TEXT[124];
			Link.l1.go = "Exit";
		break;
		
		case "Home_again":
			if (checkquestattribute("leave_kr", "true"))
			{
				d.Text = DLG_TEXT[129];
				Link.l1 = DLG_TEXT[130];
				Link.l1.go = "Home_again2";
			}
			else
			{
				d.Text = DLG_TEXT[127];
				Link.l1 = DLG_TEXT[128];
				Link.l1.go = "exit";
			}
		break;

		case "Home_again2":
			d.Text = DLG_TEXT[131];
			Link.l1 = DLG_TEXT[132];
			Link.l1.go = "Home_again3";
		break;
		
		case "Home_again3":
			d.Text = DLG_TEXT[133];
			Link.l1 = DLG_TEXT[134];
			Link.l1.go = "Home_again4";
		break;
		
		case "Home_again4":
			d.Text = DLG_TEXT[135];
			Link.l1 = DLG_TEXT[136];
			Link.l1.go = "exit";
			AddDialogExitQuest("Story_Take_Clement_Home3");
			Diag.TempNode = "Second time";
		break;
		
		case "Second time":
			d.Text = DLG_TEXT[135];
			Link.l1 = DLG_TEXT[136];
			Link.l1.go = "exit";
			Diag.TempNode = "Second time";
		break;

		case "Take_Me_Home_Repeat":
			Dialog.snd = "voice\REDI\REDI018";
			d.Text = DLG_TEXT[137] + GetMyFirstNames(PChar, false) + DLG_TEXT[138];
			Link.l1 = DLG_TEXT[139];
			Link.l1.go = "exit";			
			Diag.Tempnode = "Take_Me_Home_Repeat";
		break;
	}
}


