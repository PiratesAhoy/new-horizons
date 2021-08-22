//#include "DIALOGS\Agent_crewman_dialog.h"
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
	ref old_ship_location;
	string old_ship_location_name, old_ship_town;
	
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

			dialog.text = DLG_TEXT[0] + GetAddressForm(ADDR_POLITE, GetServedNation(), PChar.sex == "woman");
			link.l1 = DLG_TEXT[2];
			link.l1.go = "Exit";
		break;

		case "dismiss_ship":
			old_ship_location = LocationFromID(PChar.quest.agentquest.original_location_from_sea);
			old_ship_town = GetTownIDFromLocID(PChar.quest.agentquest.original_location_from_sea);
			if (HasSubStr(old_ship_location.id.label, "town_name")) old_ship_location_name =  FindTownName(old_ship_town);
			else old_ship_location_name = TranslateString("", old_ship_location.id.label);
			PChar.quest.agentquest.old_ship_location_name = old_ship_location_name;
			dialog.text = DLG_TEXT[0] + GetAddressForm(ADDR_POLITE, GetServedNation(), PChar.sex == "woman");
			link.l1 = DLG_TEXT[3] + GetCharacterAddressForm(NPChar, ADDR_CIVIL, false, true) + DLG_TEXT[4] + FindTownName(PChar.quest.agentquest.original_town) + DLG_TEXT[5];
			link.l1.go = "exit";
		break;

		case "smuggler_meet":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7] + GetMyFullName(PChar) + DLG_TEXT[8] + FindTownName(PChar.quest.agentquest.original_town) + DLG_TEXT[9];
			link.l1.go = "smuggler_pay_me";
		break;

		case "smuggler_pay_me":
			dialog.text = DLG_TEXT[10];
			if (sti(PChar.quest.agentquest.smuggler_fare) == 0) link.l1 = DLG_TEXT[11];
			else link.l1 = DLG_TEXT[12] + PChar.quest.agentquest.smuggler_fare + DLG_TEXT[13] + FindTownName(PChar.quest.agentquest.original_town) + DLG_TEXT[14];
			link.l1.go = "smuggler_no_pay";
		break;

		case "smuggler_no_pay":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "smuggler_lets_go";
		break;

		case "smuggler_lets_go":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			AddDialogExitQuest("AgentQuest_smuggler_depart");
			link.l1.go = "exit";
		break;

		case "smuggler_pay_up":
			dialog.text = DLG_TEXT[19] + PChar.quest.agentquest.smuggler_fare + DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "smuggler_warning";
		break;

		case "smuggler_warning":
			Diag.TempNode = "smuggler_warning2";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
		break;

		case "smuggler_warning2":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
		break;

		case "smuggler_payoff":
			Diag.TempNode = "smuggler_till_next_time";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -1 * sti(PChar.quest.agentquest.smuggler_fare));
			PChar.quest.agentquest.smuggler_fare = 0;
			int govnation;
			if (CheckAttribute(CharacterFromID(PChar.quest.agentquest.governor), "nation")) govnation = sti(GetAttribute(CharacterFromID(PChar.quest.agentquest.governor), "nation"));
			else govnation = GetServedNation();
			dialog.text = DLG_TEXT[26] + XI_ConvertString(GetNationDescByType(govnation)) + DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";
		break;

		case "smuggler_till_next_time":
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "exit";
		break;
	}
}