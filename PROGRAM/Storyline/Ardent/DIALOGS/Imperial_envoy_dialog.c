//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	string PCname;
	if (CheckAttribute(PChar,"title")) PCname = GetMyRespectfullyName(PChar);
	else PCname = XI_ConvertString(GetRankName(PChar, SPAIN)) + " " + GetMyLastName(PChar);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Äèàëîã ïåðâûé - ïåðâàÿ âñòðå÷à
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
		break;
		
		case "exit_keep_galleon":
			AddDialogExitQuest("imperial_escort_keep_galleon");
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
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
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;

		case "On_ship":
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "exit";
		break;

		case "envoy_intro":
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[5] + GetMyLastName(CharacterFromID("Imperial_Captain")) + DLG_TEXT[6];
			link.l1.go = "exit";
		break;

		case "no_offence":
			dialog.text = "";
			link.l1 = DLG_TEXT[7];
			link.l1.go = "call_me_lady";
		break;

		case "call_me_lady":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
		break;

		case "Santo_Domingo_residence_safe":
			dialog.text = DLG_TEXT[10] + GetMyLastName(CharacterFromID("Imperial_Captain")) + DLG_TEXT[11] + GetMyLastName(PChar) + ".";
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
		break;

		case "Santo_Domingo_residence_safe2":
			dialog.text = DLG_TEXT[13] + GetMyFullName(GetTownGovernor("Santo Domingo")) + ".";
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "outside_cave_after_ether":
			dialog.text = DLG_TEXT[14] + GetMyLastName(PChar) + DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "outside_cave_you_dunnit";
		break;

		case "outside_cave_no_ether":
			dialog.text = DLG_TEXT[41] + GetMyLastName(PChar) + DLG_TEXT[42];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "outside_cave_you_dunnit";
		break;

		case "outside_cave_you_dunnit":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			if(Characters[GetCharacterIndex("Jaime Lezcano")].location == PChar.location) link.l1.go = "outside_cave_why_he_here";
			else link.l1.go = "outside_cave_why_believe_you";
		break;

		case "outside_cave_why_he_here":
			dialog.text = DLG_TEXT[19];
			if(CheckQuestAttribute("imperial_escort.cave_result", "negotiation_evil1") || CheckQuestAttribute("imperial_escort.cave_result", "negotiation_evil2")) link.l1 = DLG_TEXT[21];
			else link.l1 = DLG_TEXT[20];
			link.l1.go = "outside_cave_he_must_face_justice";
		break;

		case "outside_cave_he_must_face_justice":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23] + GetMyFullName(CharacterFromID("Emiliano de Guzmán")) + DLG_TEXT[24];
			link.l1.go = "outside_cave_why_believe_you";
		break;

		case "outside_cave_why_believe_you":
			dialog.text = DLG_TEXT[25] + GetMyLastName(PChar) + "?";
			if(GetAttribute(PChar, "quest.imperial_escort.agent_shiptype") == GetAttribute(PChar, "quest.imperial_escort.shiptype"))
			{
				link.l1 = DLG_TEXT[26] + DLG_TEXT[28] + GetMyFullName(CharacterfromID("Imperial_Captain")) + "?";
				link.l1.go = "outside_cave_where_captain";
			}
			else
			{
				link.l1 = DLG_TEXT[26] + DLG_TEXT[27];
				link.l1.go = "outside_cave_walk_to_beach";
			}
		break;

		case "outside_cave_where_captain":
			dialog.text = DLG_TEXT[29] + PChar.quest.imperial_escort.shipname + DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "outside_cave_where_captain2";
		break;

		case "outside_cave_where_captain2":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "outside_cave_walk_to_beach";
		break;

		case "outside_cave_walk_to_beach":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
		break;

		case "inside_cave_what_next":
			dialog.text = DLG_TEXT[43] + GetMyLastName(PChar) + DLG_TEXT[44];
			link.l1 = DLG_TEXT[45] + GetMyFullName(CharacterFromID("Javier Balboa")) + DLG_TEXT[46];
			link.l1.go = "inside_cave_what_next2";
		break;

		case "inside_cave_what_next2":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48] + GetMyFullName(CharacterFromID("Javier Balboa")) + DLG_TEXT[49];
			link.l1.go = "inside_cave_kidnappers_mistake";
		break;

		case "inside_cave_what_next1a":
			dialog.text = DLG_TEXT[54] + GetMyLastName(PChar) + DLG_TEXT[55];
			link.l1 = DLG_TEXT[56] + GetMyFullName(CharacterFromID("Javier Balboa")) + DLG_TEXT[57];
			link.l1.go = "inside_cave_what_next2a";
		break;

		case "inside_cave_what_next2a":
			dialog.text = DLG_TEXT[25] + GetMyLastName(PChar) + "?";
			if(GetAttribute(PChar, "quest.imperial_escort.agent_shiptype") == GetAttribute(PChar, "quest.imperial_escort.shiptype"))
			{
				link.l1 = DLG_TEXT[26] + DLG_TEXT[28] + GetMyFullName(CharacterfromID("Imperial_Captain")) + "?";
				link.l1.go = "inside_cave_where_captain";
			}
			else
			{
				link.l1 = DLG_TEXT[26];
				link.l1.go = "inside_cave_kidnappers_mistake";
			}
		break;

		case "inside_cave_where_captain":
			dialog.text = DLG_TEXT[29] + PChar.quest.imperial_escort.shipname + DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "inside_cave_kidnappers_mistake";
		break;

		case "inside_cave_kidnappers_mistake":
			dialog.text = DLG_TEXT[50] + GetMySimpleName(CharacterFromID("Emiliano de Guzmán")) + DLG_TEXT[51];
			link.l1 = DLG_TEXT[52] + GetMySimpleName(CharacterFromID("Emiliano de Guzmán")) + DLG_TEXT[53];
			link.l1.go = "exit";
		break;

		case "santiago_guard":
			Preprocessor_Add("person", PChar.sex);
			dialog.text = DLG_TEXT[58] + GetMyFullName(NPChar) + DLG_TEXT[59];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "santiago_guard2":
			dialog.text = DLG_TEXT[60];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "santiago_on_to_townhall":
			dialog.text = DLG_TEXT[61] + GetMyFullName(CharacterFromID("Emiliano de Guzmán")) + DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "exit";
		break;

		case "santiago_townhall_approach":
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65] + GetMyFullName(CharacterFromID("Emiliano de Guzmán")) + DLG_TEXT[66];
			link.l1.go = "santiago_townhall_approach2";
		break;

		case "santiago_townhall_approach2":
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "exit";
		break;

		case "believe_ardent":
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(PChar)));
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(PChar)));
//			if (PChar.sex == "man") Preprocessor_Add("pronoun3", XI_ConvertString("his"));
//			else Preprocessor_Add("pronoun3", XI_ConvertString("her"));
			Preprocessor_Add("pronoun3", XI_ConvertString(GetMyPronounPossessive(PChar)));
			dialog.text = DLG_TEXT[69] + GetRankName(CharacterFromID("Jusepe Guimaraes"), sti(Characters[GetCharacterIndex("Jusepe Guimaraes")].nation)) + DLG_TEXT[70] + GetMyLastName(PChar) + DLG_TEXT[71] + GetMyLastName(PChar) + DLG_TEXT[72] + GetMyFullName(CharacterFromID("Emiliano de Guzmán")) + DLG_TEXT[73];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "demand_justice":
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(PChar)));
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(PChar)));
//			if (PChar.sex == "man") Preprocessor_Add("pronoun3", XI_ConvertString("his"));
//			else Preprocessor_Add("pronoun3", XI_ConvertString("her"));
			Preprocessor_Add("pronoun3", XI_ConvertString(GetMyPronounPossessive(PChar)));
			string finally = "";
			if(!LAi_IsDead(CharacterFromID("Emiliano de Guzmán"))) finally = DLG_TEXT[77] + GetMyFullName(CharacterFromID("Emiliano de Guzmán")) + DLG_TEXT[78];
			dialog.text = DLG_TEXT[74] + GetMyLastName(PChar) + DLG_TEXT[75] + GetMyLastName(PChar) + DLG_TEXT[76] + finally;
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "keep_galleon":
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(PChar)));
			dialog.text = DLG_TEXT[79] + PCname + DLG_TEXT[80] + PChar.quest.imperial_escort.ship_name + DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "exit_keep_galleon";
			link.l2 = DLG_TEXT[83] + PChar.quest.imperial_escort.ship_name + DLG_TEXT[84];
			link.l2.go = "decline_galleon";
		break;

		case "decline_galleon":
			PChar.quest.imperial_escort.keep_galleon = false;
			dialog.text = DLG_TEXT[90] + PCname + DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			AddDialogExitQuest("imperial_escort_admiral_restores_ships");
			link.l1.go = "exit";
		break;

		case "report_admiral_good":
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(PChar)));
			dialog.text = GetRankName(CharacterFromID("Jusepe Guimaraes"), sti(Characters[GetCharacterIndex("Jusepe Guimaraes")].nation)) + DLG_TEXT[85] + PCname + DLG_TEXT[86];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "report_admiral_bad":
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(PChar)));
			dialog.text = DLG_TEXT[87] + PCname + DLG_TEXT[88] + PCname + DLG_TEXT[89];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "farewell":
			dialog.text = DLG_TEXT[90] + PCname + DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "exit";
		break;

		case "guzman_dead_goto_havana":
			dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[94] + GetMyFullName(CharacterFromID("Emiliano de Guzmán")) + DLG_TEXT[95];
			link.l1.go = "guzman_dead_goto_havana2";
		break;

		case "guzman_dead_goto_havana2":
			dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "exit";
		break;
	}
}