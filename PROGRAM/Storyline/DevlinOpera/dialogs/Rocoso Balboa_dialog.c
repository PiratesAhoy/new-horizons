//#include "DIALOGS\Rocoso Balboa_Dialog.h"
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
	Preprocessor_Add("Senor", GetAddressForm(ADDR_CIVIL, SPAIN, false));
	Preprocessor_Add("Senorita", GetAddressForm(ADDR_CIVIL, SPAIN, true));
	
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

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "Beatrice":
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Beatrice2";
		break;

		case "Beatrice2":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Beatrice3";
		break;

		case "Beatrice3":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5] + GetMyShipNameShow(PChar) + DLG_TEXT[6];
			link.l1.go = "Beatrice4";
		break;

		case "Beatrice4":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Beatrice5";
		break;

		case "Beatrice5":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Beatrice6";
		break;

		case "Beatrice6":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "Beatrice7";
		break;

		case "Beatrice7":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "exit_find5men";
			link.l2 = DLG_TEXT[15];
			link.l2.go = "BeatriceDescr";
			AddQuestRecord("El Navegante", 6);
		break;

		case "BeatriceDescr":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "exit_find5men";
			AddQuestRecord("El Navegante", 7);
		break;

		case "exit_find5men":
			AddDialogExitQuest("Sailor_search_start");

			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
		break;

		case "workinprogress":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "exit_progress";
		break;

		case "exit_progress":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();

			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "workinprogress";
		break;

		case "Beatrice_found_Sailors":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Beatrice_found_Sailors2";
		break;

		case "Beatrice_found_Sailors2":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Beatrice_found_Sailors3";
		break;

		case "Beatrice_found_Sailors3":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
			AddDialogExitQuest("Beatrice_returns_Santiago");
		break;

		case "Bonnie":
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "Bonnie2";
		break;

		case "Bonnie2":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Bonnie3";
		break;

		case "Bonnie3":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			AddDialogExitQuest("Bonnie_joins_Balboa_table");
		break;

		case "notyet_drunk":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "notyet_drunk2";
		break;

		case "notyet_drunk2":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "notyet_drunk3";
		break;

		case "notyet_drunk3":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "notyet_drunk4";
		break;

		case "notyet_drunk4":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
			AddDialogExitQuest("Bonnie_joins_Balboa_table_4");
		break;

		case "slightly_drunk":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "slightly_drunk2";
		break;

		case "slightly_drunk2":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
			AddDialogExitQuest("Bonnie_joins_Balboa_table_6");
		break;

		case "clearly_drunk":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "clearly_drunk2";
		break;

		case "clearly_drunk2":
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "exit";
			AddDialogExitQuest("Bonnie_and_Balboa_on_the_town");
		break;

		case "extrem_drunk":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "extrem_drunk2";
		break;

		case "extrem_drunk2":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "exit_Balboa_caught";
			link.l2 = DLG_TEXT[48];
			link.l2.go = "exit_Balboa_hides";
		break;

		case "exit_Balboa_caught":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
			AddDialogExitQuest("Balboa_caught");
		break;

		case "exit_Balboa_hides":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
			AddDialogExitQuest("Balboa_hides");
		break;

		case "survived":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "survived2";
		break;

		case "survived2":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "survived3";
		break;

		case "survived3":
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "survived4";
		break;

		case "survived4":
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "exit";
			AddDialogExitQuest("Bonnie_returns_Santiago_saved");
			AddDialogExitQuest("Switch_to_Beatrice");
		break;

		case "Balboa_is_inside_shipyard":
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "Balboa_is_inside_shipyard2";
		break;

		case "Balboa_is_inside_shipyard2":
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "Balboa_is_inside_shipyard3";
		break;

		case "Balboa_is_inside_shipyard3":
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "exit_checksafe";
			AddQuestRecord("El Navegante", 18);
		break;

		case "exit_checksafe":
			AddDialogExitQuest("Bonnie_look_if_safe");

			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
		break;

		case "crying":
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "exit_crying";
		break;

		case "exit_crying":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();

			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "crying";
		break;

		case "Coast_clear":
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "Coast_clear2";
		break;

		case "Coast_clear2":
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "Coast_clear3";
		break;

		case "Coast_clear3":
			dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "exit";
			AddDialogExitQuest("Bonnie_returns_Santiago_sneaked");
			AddDialogExitQuest("Switch_to_Beatrice");
		break;

		case "Ready_for_robe":
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "Ready_for_robe2";
		break;

		case "Ready_for_robe2":
			dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "Ready_for_robe3";
		break;

		case "Ready_for_robe3":
			dialog.text = DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "exit";
			AddDialogExitQuest("Balboa_is_changing");
		break;

		case "Balboa_now_changed":
			dialog.text = DLG_TEXT[75];
			link.l1 = DLG_TEXT[76];
			link.l1.go = "exit";
			AddDialogExitQuest("Balboa_disguised");
		break;

		case "Balboa_undercover":
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "exit_undercover";
		break;

		case "exit_undercover":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();

			Characters[GetCharacterIndex("Rocoso Balboa")].Dialog.CurrentNode = "Balboa_undercover";
		break;

		case "Robie_saved":
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "Robie_saved2";
		break;

		case "Robie_saved2":
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "exit";
			AddDialogExitQuest("Bonnie_returns_Santiago_sneaked");
			AddDialogExitQuest("Switch_to_Beatrice");
		break;

//-----------------------------------------------

		case "Blaze":
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "Blaze2";
		break;

		case "Blaze2":
			dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "Blaze3";
		break;

		case "Blaze3":
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "Blaze4";
		break;

		case "Blaze4":
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "Blaze5";
		break;

		case "Blaze5":
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "Blaze6";
		break;

		case "Blaze6":
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "exit";
			AddDialogExitQuest("Setting_up_Duel");
		break;

		case "Balboa_challenge":
			dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "Balboa_challenge2";
		break;

		case "Balboa_challenge2":
			dialog.text = DLG_TEXT[95] + GetNationRoyalByType(SPAIN) + DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "exit";
			AddDialogExitQuest("Duel_Blaze_Balboa");
		break;

		case "NOPE":
			dialog.text = DLG_TEXT[98];
			link.l1 = DLG_TEXT[99];
			link.l1.go = "exit";
		break;

		case "Bandits_ded_now":
			dialog.text = DLG_TEXT[100];
			link.l1 = DLG_TEXT[101];
			link.l1.go = "dednow2";
		break;

		case "dednow2":
			dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "dednow3";
		break;

		case "dednow3":
			dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];
			link.l1.go = "exit_spare";
			link.l2 = DLG_TEXT[106];
			link.l2.go = "exit_killhim";
		break;

		case "exit_spare":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
			AddDialogExitQuest("Blaze_spared_Balboa");
		break;

		case "exit_killhim":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
			AddDialogExitQuest("Blaze_killed_Balboa");
		break;

	}
}