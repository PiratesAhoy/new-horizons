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

	if(PChar.sex == "woman") NPChar.quest.my_fake_name = "Clementine Arguelles";
	else NPChar.quest.my_fake_name = "Clement Arguelles";
	
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

			dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + ".";
			NPChar.quest.my_name = GetMyFullName(PChar);
			Link.l1 = DLG_TEXT[2] + NPChar.quest.my_name + ".";
			Link.l1.go = "imperial_escort_offer_service";
			if(GetRMRelation(PChar, FRANCE) <= REL_WAR)
			{
				if(PChar.sex == "woman") NPChar.quest.my_name = "Clementine Arguelles";
				else NPChar.quest.my_name = "Clement Arguelles";
				Link.l1 = DLG_TEXT[2] + NPChar.quest.my_name + ".";
				Link.l1.go = "imperial_escort_rumbled";
			}
			if(PChar.model == "ArdentM_2" || PChar.model == "ArdentF_2") Link.l1.go = "imperial_escort_offer_service";
			if(PChar.model == "Ardent_Fr" || PChar.model == "Ardent_FrF") Link.l1.go = "imperial_escort_soldier";
			Diag.TempNode = "First time";
		break;

		case "imperial_escort_rumbled":
			PChar.quest.imperial_escort.disguise = "failed";
			dialog.text = DLG_TEXT[4] + GetMySimpleName(PChar) + DLG_TEXT[5] + XI_ConvertString(PChar.sex) + "!";
			link.l1 = DLG_TEXT[6];
			AddDialogExitQuest("imperial_escort_PoP_townhall_arrest");
			AddDialogExitQuest("imperial_escort_prepare_for_PoP_ambush");
			link.l1.go = "exit";
			Diag.TempNode = "imperial_escort_get_out";
		break;

		case "imperial_escort_get_out":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
		break;

		case "imperial_escort_soldier":
			PChar.quest.imperial_escort.disguise = "soldier";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9] + GetMyFullName(CharacterFromID("Joseph Claude Le Moigne")) + DLG_TEXT[10] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[11];
			link.l1.go = "imperial_escort_le_moigne_mistaken";
		break;

		case "imperial_escort_le_moigne_mistaken":
			dialog.text = GetMyFullName(CharacterFromID("Joseph Claude Le Moigne")) + DLG_TEXT[12] + DLG_TEXT[13] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[14] + "\n" + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "imperial_escort_i_run_hispaniola";
		break;

		case "imperial_escort_i_run_hispaniola":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18] + GetMyFullName(CharacterFromID("Joseph Claude Le Moigne")) + DLG_TEXT[19];
			AddDialogExitQuest("imperial_escort_prepare_for_PoP_ambush");
			Diag.TempNode = "imperial_escort_nothing_else";
			link.l1.go = "exit";
		break;

		case "imperial_escort_nothing_else":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
		break;

		case "imperial_escort_offer_service":
			if(PChar.model == "ArdentM_2" || PChar.model == "ArdentF_2") PChar.quest.imperial_escort.disguise = "disguise";
			else PChar.quest.imperial_escort.disguise = "none";
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "imperial_escort_offer_job";
		break;

		case "imperial_escort_offer_job":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "imperial_escort_introduce_spy";
		break;

		case "imperial_escort_introduce_spy":
			dialog.text = DLG_TEXT[26] + GetMyFullName(CharacterFromID("Gilles Clouzot")) + DLG_TEXT[27];
			link.l1 = "";
			AddDialogExitQuest("imperial_escort_spy_intro");
			link.l1.go = "exit";
		break;

		case "imperial_escort_what_use_is_he":
			dialog.text = "";
			link.l1 = DLG_TEXT[28];
			link.l1.go = "imperial_escort_spy_disguise";
		break;

		case "imperial_escort_spy_disguise":
			dialog.text = DLG_TEXT[29] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[30] + GetMyFullName(CharacterFromID("Gilles Clouzot")) + DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "imperial_escort_goto_muelle";
		break;

		case "imperial_escort_goto_muelle":
			dialog.text = DLG_TEXT[33] + GetMyFullName(CharacterFromID("Gilles Clouzot")) + DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			Diag.TempNode = "imperial_escort_nothing_else";
			link.l1.go = "exit";
		break;

		case "imperial_escort_return_from_muelle":
			if(GetRMRelation(PChar, FRANCE) <= REL_WAR && PChar.model != "ArdentM_2" && PChar.model != "ArdentF_2")
			{
				dialog.text = DLG_TEXT[36] + GetMySimpleName(PChar) + DLG_TEXT[5] + XI_ConvertString(PChar.sex) + "!";
				link.l1 = DLG_TEXT[6];
				AddDialogExitQuest("imperial_escort_PoP_townhall_arrest");
				AddDialogExitQuest("imperial_escort_prepare_for_PoP_ambush");
				link.l1.go = "exit";
				Diag.TempNode = "imperial_escort_get_out";
			}
			else
			{
				dialog.text = DLG_TEXT[37] + NPChar.quest.my_name + DLG_TEXT[38] + Characters[GetCharacterIndex("Gilles Clouzot")].old.name + " " + Characters[GetCharacterIndex("Gilles Clouzot")].old.lastname + DLG_TEXT[39];
				link.l1 = DLG_TEXT[40] + GetMyFullName(CharacterFromID("Uasco Mazinho")) + DLG_TEXT[41] + Characters[GetCharacterIndex("Gilles Clouzot")].old.name + " " + Characters[GetCharacterIndex("Gilles Clouzot")].old.lastname + DLG_TEXT[42];
				link.l1.go = "imperial_escort_reward";
			}
		break;

		case "imperial_escort_reward":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, 5000);
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			if(NPChar.quest.my_name == GetMyFullName(PChar)) link.l1.go = "imperial_escort_you_took_envoy";
			else link.l1.go = "imperial_escort_ardent_took_envoy";
		break;

		case "imperial_escort_you_took_envoy":
			Preprocessor_Add("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "imperial_escort_not_your_ship";
		break;

		case "imperial_escort_not_your_ship":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "imperial_escort_agents_report1";
		break;

		case "imperial_escort_agents_report1":
			Preprocessor_Add("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
//			if(CheckQuestAttribute("imperial_escort.status", "ship_missing")) dialog.text = DLG_TEXT[49] + DLG_TEXT[50];
			if(GetCharacterShipModel(CharacterfromID("Pelayo Nunez")) == GetAttribute(PChar, "quest.imperial_escort.shiptype")) dialog.text = DLG_TEXT[49] + DLG_TEXT[50];
			else dialog.text = DLG_TEXT[49] + DLG_TEXT[51];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "imperial_escort_mission_to_cuba";
		break;

		case "imperial_escort_ardent_took_envoy":
			Preprocessor_Add("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(PChar)));
			dialog.text = DLG_TEXT[52] + GetMySimpleName(PChar) + DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "imperial_escort_agents_report2";
		break;

		case "imperial_escort_agents_report2":
			Preprocessor_Add("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			Preprocessor_Add("pronoun3", XI_ConvertString(GetMyPronounPossessive(PChar)));
//			if(CheckQuestAttribute("imperial_escort.status", "ship_missing")) dialog.text = DLG_TEXT[55] + GetMySimpleName(PChar) + DLG_TEXT[56] + DLG_TEXT[50];
			if(GetCharacterShipModel(CharacterfromID("Pelayo Nunez")) == GetAttribute(PChar, "quest.imperial_escort.shiptype")) dialog.text = DLG_TEXT[55] + GetMySimpleName(PChar) + DLG_TEXT[56] + DLG_TEXT[50];
			else dialog.text =  dialog.text = DLG_TEXT[55] + GetMySimpleName(PChar) + DLG_TEXT[56] + DLG_TEXT[51];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "imperial_escort_mission_to_cuba";
		break;

		case "imperial_escort_mission_to_cuba":
			Preprocessor_Add("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "imperial_escort_hostage";
		break;

		case "imperial_escort_hostage":
			Preprocessor_Add("envoy", GetMyFullName(CharacterFromID("Imperial_envoy")));
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			AddDialogExitQuest("imperial_escort_governor_says_cuba");
			link.l1.go = "exit";
		break;
	}
}