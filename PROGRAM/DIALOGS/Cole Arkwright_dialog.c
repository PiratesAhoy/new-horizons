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
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[2];		// changed from .spa to .por by KAM
			Link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4];
			Link.l1.go = "node_1";
			NextDiag.TempNode = "First time";
		break;

		case "node_1":
			dialog.text = DLG_TEXT[8];
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_CIVIL, false, false)); // KK
			link.l1 = DLG_TEXT[9];
			link.l1.go = "quests";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "node_2";
		break;

		case "node_2":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
		break;

		case "quests":
			if (CheckQuestAttribute("Eleuthera", "Roxanne"))
			{
				dialog.snd = "Voice\REGR\REGR007";
				dialog.Text = DLG_TEXT[70];
				link.l1 = DLG_TEXT[71];
				link.l1.go = "gov_6";
			}
			link.l99 = DLG_TEXT[13];
			link.l99.go = "exit";
		break;

		case "gov_6":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "gov_7";
		break;

		case "gov_7":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "gov_8";
		break;

		case "gov_8":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "gov_9";
		break;

		case "gov_9":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79];
			link.l1.go = "gov_10";
		break;

		case "gov_10":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[80];
			link.l1 = DLG_TEXT[81];
			link.l1.go = "exit";
			pchar.quest.eleuthera = "Alice";
			AddDialogExitQuest("messenger_done");
		break;

		case "gov_11":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "gov_12";
		break;

		case "gov_12":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "gov_13";
		break;

		case "gov_13":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[87];
			link.l1.go = "gov_14";
		break;

		case "gov_14":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[88];
			link.l1 = DLG_TEXT[89];
			link.l1.go = "exit";
			AddDialogExitQuest("roxanne_in_jail");
		break;

		case "j_day":
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_CIVIL, false, false)); // KK
			dialog.text = GetMyFullName(PChar) + DLG_TEXT[90];
			link.l1 = DLG_TEXT[91];
			link.l1.go = "continue1";
		break;

		case "continue1":
			LAi_QuestDelay("ex_dialog", 2);
			DialogExit();
			NextDiag.CurrentNode = "j_day2";
		break;

		case "j_day2":
			dialog.text = GetMyFullName(PChar) + DLG_TEXT[92];
			link.l1 = DLG_TEXT[93];
			link.l1.go = "exit";
		break;
		
		case "gov_15":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[94];
			link.l1 = DLG_TEXT[95];
			link.l1.go = "gov_16";
		break;

		case "gov_16":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "gov_17";
		break;

		case "gov_17":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[98];
			link.l1 = DLG_TEXT[99];
			link.l1.go = "gov_18";
		break;

		case "gov_18":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[100];
			link.l1 = DLG_TEXT[101];
			link.l1.go = "gov_19";
		break;

		case "gov_19":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "gov_20";
		break;

		case "gov_20":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];
			link.l1.go = "gov_21";
		break;

		case "gov_21":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[106];
			link.l1 = DLG_TEXT[107];
			link.l1.go = "gov_22";
		break;

		case "gov_22":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[108];
			link.l1 = DLG_TEXT[109];
			link.l1.go = "gov_23";
		break;

		case "gov_23":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[110];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "gov_24";
			link.l2 = DLG_TEXT[112];
			link.l2.go = "abandon_quest";			
		break;

		case "gov_24":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[114];
			link.l1.go = "gov_25";
		break;

		case "gov_25":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[115];
			link.l1 = DLG_TEXT[116];
			link.l1.go = "gov_26";
		break;

		case "gov_26":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[117];
			link.l1 = DLG_TEXT[118];
			link.l1.go = "exit";
			GiveItem2Character(Pchar, "Letter_Lafitte");			
			AddDialogExitQuest("meet_lafitte");			
		break;
		
		case "gov_27":
			RemovePassenger(pchar, characterFromID("Jean Lafitte"));
			RemoveCharacterCompanion(pchar, characterFromID("Jean Lafitte"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Jean Lafitte"));			
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[119];
			link.l1 = DLG_TEXT[120];
			link.l1.go = "gov_28";
		break;

		case "gov_28":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[121];
			link.l1 = DLG_TEXT[122];
			link.l1.go = "gov_29";
		break;

		case "gov_29":
			ChangeCharacterAddressGroup(characterFromID("Jean Lafitte"), "Eleuthera_Port", "goto", "goto25");		
            PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 25000);
			ChangeRMRelation(pchar, AMERICA, 20.0);				
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[123];
			link.l1 = DLG_TEXT[124];
			link.l1.go = "gov_30";
		break;

		case "gov_30":	
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[125];
			link.l1 = DLG_TEXT[126];
			link.l1.go = "exit";
			AddDialogExitQuest("leave_governor_eleuthera");			
		break;			

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
