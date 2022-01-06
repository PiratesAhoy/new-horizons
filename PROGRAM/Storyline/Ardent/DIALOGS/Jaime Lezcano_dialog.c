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
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
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

			dialog.text = DLG_TEXT[0] + GetMyName(PChar) + ".";
			link.l1 = DLG_TEXT[1] + GetMyName(NPChar) + ".";
			link.l1.go = "Exit";
		break;

		case "imperial_escort_arrest1":
			dialog.text = DLG_TEXT[2] + GetMySimpleName(PChar) + DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "imperial_escort_arrest2";
		break;

		case "imperial_escort_arrest2":
			dialog.text = DLG_TEXT[5] + GetMyFullName(NPChar) + DLG_TEXT[6] + GetMyFullName(CharacterfromID("Jusepe Guimaraes")) + DLG_TEXT[7] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[8];
			link.l1 = DLG_TEXT[9] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[10];
			link.l1.go = "imperial_escort_arrest3";
		break;

		case "imperial_escort_arrest3":
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(characterFromID("Imperial_envoy"))));
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12] + GetMyLastName(NPChar) + "!";
			link.l1.go = "exit";
		break;

		case "imperial_escort_ambush_surrender":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "imperial_escort_explain1";
		break;

		case "imperial_escort_explain1":
			dialog.text = DLG_TEXT[15] + GetMyFullName(CharacterfromID("Jusepe Guimaraes")) + DLG_TEXT[16];
			link.l1 = DLG_TEXT[17] + GetMyLastName(CharacterFromID("Javier Balboa")) + DLG_TEXT[18];
			link.l1.go = "imperial_escort_explain2";
		break;

		case "imperial_escort_explain2":
			dialog.text = GetMySimpleName(CharacterfromID("Javier Balboa")) + DLG_TEXT[19] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[20] + GetMySimpleName(CharacterfromID("Javier Balboa")) + DLG_TEXT[21] + GetMyFullName(CharacterFromID("Emiliano de Guzmán")) + DLG_TEXT[22];
			link.l1 = DLG_TEXT[23] + GetMyFullName(CharacterFromID("Imperial_envoy")) + "!";
			link.l1.go = "imperial_escort_explain3";
		break;

		case "imperial_escort_explain3":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25] + GetMyFullName(CharacterFromID("Emiliano de Guzmán")) + DLG_TEXT[26];
			link.l1.go = "imperial_escort_explain4";
		break;

		case "imperial_escort_explain4":
			dialog.text = DLG_TEXT[27] + GetMyFullName(CharacterFromID("Emiliano de Guzmán")) + DLG_TEXT[28] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "imperial_escort_explain5";
		break;

		case "imperial_escort_explain5":
			if(CheckQuestAttribute("imperial_escort.status", "ship_missing")) dialog.text = DLG_TEXT[31] + DLG_TEXT[32];
			else dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "imperial_escort_agents_fate";
		break;

		case "imperial_escort_agents_fate":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
		break;

		case "imperial_escort_negotations_in_cave":
			dialog.text = DLG_TEXT[36] + GetMyLastName(PChar) + DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "imperial_escort_negotations_in_cave2";
		break;

		case "imperial_escort_negotations_in_cave2":
			dialog.text = DLG_TEXT[39] + GetMyFullName(NPChar) + DLG_TEXT[40] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "imperial_escort_negotations_in_cave3";
		break;

		case "imperial_escort_negotations_in_cave3":
			dialog.text = DLG_TEXT[43] + GetMySimpleName(CharacterfromID("Javier Balboa")) + DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "imperial_escort_negotations_in_cave4";
		break;

		case "imperial_escort_negotations_in_cave4":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[48];
			link.l1.go = "imperial_escort_negotations_in_cave5";
		break;

		case "imperial_escort_negotations_in_cave5":
			dialog.text = DLG_TEXT[49];
			if(CheckQuestAttribute("alignment", "good"))
			{
				link.l1 = DLG_TEXT[50];
				link.l1.go = "imperial_escort_negotations_in_cave6_good";
			}
			if(CheckQuestAttribute("alignment", "evil"))
			{
				link.l1 = DLG_TEXT[54];
				link.l1.go = "imperial_escort_negotations_in_cave6_evil";
			}
		break;

		case "imperial_escort_negotations_in_cave6_good":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "imperial_escort_negotations_in_cave7_good";
		break;

		case "imperial_escort_negotations_in_cave7_good":
			PChar.quest.imperial_escort.cave_result = "negotiation_good1";
			AddDialogExitQuest("imperial_escort_agent_to_tortuga");
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "imperial_escort_negotiations_in_cave8";
		break;

		case "imperial_escort_negotations_in_cave6_evil":
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "imperial_escort_negotations_in_cave7_evil";
		break;

		case "imperial_escort_negotations_in_cave7_evil":
			Preprocessor_AddQuestData("agent", GetMyFullName(CharacterFromID("Jaime Lezcano")));
			Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			AddQuestRecord("Imperial Escort", 26);
			Preprocessor_Remove("envoy");
			Preprocessor_Remove("agent");
			PChar.quest.imperial_escort.cave_result = "negotiation_evil1";
			AddDialogExitQuest("imperial_escort_agent_joins_crew");
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "imperial_escort_negotiations_in_cave8";
		break;

		case "imperial_escort_negotiations_in_cave8":
			dialog.text = DLG_TEXT[59] + GetMyFullName(CharacterFromID("Emiliano de Guzmán")) + ".";
			link.l1 = DLG_TEXT[60];
			AddDialogExitQuest("imperial_escort_leave_cave");
			link.l1.go = "exit";
		break;

		case "imperial_escort_deception_in_cave1":
			dialog.text = DLG_TEXT[65] + GetMyLastName(PChar) + DLG_TEXT[66];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "imperial_escort_deception_in_cave2";
		break;

		case "imperial_escort_deception_in_cave2":
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			AddDialogExitQuest("imperial_escort_leave_cave_for_negotiation");
			link.l1.go = "exit";
		break;

		case "imperial_escort_negotiations_outside_cave1":
			dialog.text = DLG_TEXT[69] + GetMyFullName(NPChar) + DLG_TEXT[70] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[71];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "imperial_escort_negotiations_outside_cave2";
		break;

		case "imperial_escort_negotiations_outside_cave2":
			dialog.text = DLG_TEXT[43] + GetMySimpleName(CharacterfromID("Javier Balboa")) + DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "imperial_escort_negotations_outside_cave3";
		break;

		case "imperial_escort_negotations_outside_cave3":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[72] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[73];
			link.l1.go = "imperial_escort_negotations_outside_cave4";
		break;

		case "imperial_escort_negotations_outside_cave4":
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "imperial_escort_negotations_outside_cave5";
		break;

		case "imperial_escort_negotations_outside_cave5":
			dialog.text = DLG_TEXT[76];
			if(sti(PChar.money) >= 100000)
			{
				link.l1 = DLG_TEXT[77];
				link.l1.go = "imperial_escort_negotations_outside_cave6";
			}
			link.l2 = DLG_TEXT[87];
			link.l2.go = "exit_fight_agent";
		break;

		case "imperial_escort_negotations_outside_cave6":
			dialog.text = DLG_TEXT[78];
			if(CheckQuestAttribute("alignment", "good"))
			{
				PChar.quest.imperial_escort.cave_result = "negotiation_good2";
				AddDialogExitQuest("imperial_escort_agent_to_tortuga");
				link.l1 = DLG_TEXT[79];
			}
			if(CheckQuestAttribute("alignment", "evil"))
			{
				PChar.quest.imperial_escort.cave_result = "negotiation_evil2";
				link.l1 = DLG_TEXT[80];
			}
			link.l1.go = "imperial_escort_negotations_outside_cave7";
		break;

		case "imperial_escort_negotations_outside_cave7":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -100000);
			if(PChar.quest.imperial_escort.cave_result == "negotiation_good2") dialog.text = DLG_TEXT[81];
			else dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "imperial_escort_negotations_outside_cave8";
		break;

		case "imperial_escort_negotations_outside_cave8":
			dialog.text = DLG_TEXT[84] + GetMyFullName(CharacterFromID("Emiliano de Guzmán")) + DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			AddDialogExitQuest("imperial_escort_agent_returns_to_cave");
			link.l1.go = "exit";
		break;

		case "imperial_escort_return_from_cave":
			dialog.text = DLG_TEXT[90] + GetMyLastName(PChar) + DLG_TEXT[91];
			if(PChar.quest.imperial_escort.cave_result == "negotiation_good2")
			{
				link.l1 = DLG_TEXT[92];
				AddDialogExitQuest("imperial_escort_agent_to_tortuga");
			}
			else
			{
				link.l1 = DLG_TEXT[93];
				Preprocessor_AddQuestData("agent", GetMyFullName(CharacterFromID("Jaime Lezcano")));
				Preprocessor_AddQuestData("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
				AddQuestRecord("Imperial Escort", 37);
				Preprocessor_Remove("envoy");
				Preprocessor_Remove("agent");
				AddDialogExitQuest("imperial_escort_agent_joins_crew");
			}
			link.l1.go = "exit";
		break;

		case "imperial_escort_tortuga_arrival":
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "imperial_escort_tortuga_arrival2";
		break;

		case "imperial_escort_tortuga_arrival2":
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "exit";
		break;

		case "fight_in_progress":
			dialog.text = DLG_TEXT[88];
			link.l1 = DLG_TEXT[89];
			link.l1.go = "exit";
			Diag.TempNode = "fight_in_progress";
		break;

		case "exit_fight_agent":
			Diag.CurrentNode = "fight_in_progress";
			AddDialogExitQuest("imperial_escort_fight_agent");
			DialogExit();
		break;
	}
}