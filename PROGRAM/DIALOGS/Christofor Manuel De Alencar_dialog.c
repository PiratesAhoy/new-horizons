void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar = GetMainCharacter();

	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			dialog.snd = "Voice\CHMA\CHMA001";
			dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4];
			Link.l1.go = "node_1";
			NextDiag.TempNode = "First time";
		break;

		case "node_1":
			dialog.snd = "Voice\CHMA\CHMA003";
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_CIVIL, false, false)); // KK
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "quests";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "node_2";
		break;

		case "node_2":
			dialog.snd = "Voice\CHMA\CHMA004";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
		break;

		case "quests":
			dialog.snd = "Voice\CHMA\CHMA005";
			dialog.text = DLG_TEXT[13] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";

// Ardent "Imperial Escort" quest" --->
			if (CheckCharacterItem(PChar, "AdmiralLetter") && CheckQuestAttribute("imperial_escort.spy_search", "find_spy"))
			{
				link.l3 = DLG_TEXT[98] + GetMyFullName(CharacterFromID("Jusepe Guimaraes")) + DLG_TEXT[99];
				link.l3.go = "ardent_imperial_escort_what_your_purpose";
			}
		break;
// <--- Ardent "Imperial Escort" quest"


// Ardent "Imperial Escort" quest" --->
		case "ardent_imperial_escort_what_your_purpose":
			dialog.text = DLG_TEXT[100];
			link.l1 = "...";
			link.l1.go = "ardent_imperial_escort_what_your_purpose2";
		break;

		case "ardent_imperial_escort_what_your_purpose2":
			dialog.text = DLG_TEXT[101];
			link.l1 = DLG_TEXT[102] + GetMyFullName(CharacterFromID("Uasco Mazinho")) + DLG_TEXT[103];
			link.l1.go = "ardent_imperial_escort_smart_as_weevil";
		break;

		case "ardent_imperial_escort_smart_as_weevil":
			dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105] + GetMySimpleName(CharacterFromID("Uasco Mazinho")) + DLG_TEXT[106] + GetMyFullName(CharacterFromID("Uasco Mazinho")) + DLG_TEXT[107];
			link.l1.go = "ardent_imperial_escort_choose_method";
		break;

		case "ardent_imperial_escort_choose_method":
			dialog.text = DLG_TEXT[108];
			link.l1 = DLG_TEXT[109] + GetMySimpleName(CharacterFromID("Uasco Mazinho")) + DLG_TEXT[110];
			link.l1.go = "ardent_imperial_escort_get_him_on_ship";
			link.l2 = DLG_TEXT[111] + GetMySimpleName(CharacterFromID("Uasco Mazinho")) + DLG_TEXT[112];
			link.l2.go = "ardent_imperial_escort_get_him_in_port";
		break;

		case "ardent_imperial_escort_get_him_on_ship":
			dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[114] + DLG_TEXT[115];
			AddDialogExitQuest("imperial_escort_prepare_lure_spy_aboard");
			link.l1.go = "exit";
		break;

		case "ardent_imperial_escort_get_him_in_port":
			dialog.text = DLG_TEXT[116];
			link.l1 = DLG_TEXT[117] + DLG_TEXT[115];
			AddDialogExitQuest("imperial_escort_prepare_bring_uasco_ashore");
			link.l1.go = "exit";
		break;

		case "ardent_imperial_escort_after_spy":
			dialog.text = DLG_TEXT[118] + XI_ConvertString(GetRankName(PChar, sti(NPChar.nation))) + DLG_TEXT[119];
			if (CheckQuestAttribute("imperial_escort.spy_search", "spy_dead_aboard")) link.l1 = DLG_TEXT[120];
			else link.l1 = DLG_TEXT[121];
			link.l1.go = "ardent_imperial_escort_no_interrogation";
		break;

		case "ardent_imperial_escort_no_interrogation":
			dialog.text = DLG_TEXT[122];
			link.l1 = DLG_TEXT[123];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[124];
			link.l2.go = "quests";
		break;
// <--- Ardent "Imperial Escort" quest"

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
