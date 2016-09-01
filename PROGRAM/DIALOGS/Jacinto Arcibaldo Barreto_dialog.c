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
			npchar.quest.meeting = "1";
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
			dialog.text = DLG_TEXT[13] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[14];		// changed from .spa to .por by KAM
			if (CheckQuestAttribute("nigel_con_parri_checker", "win_win") || CheckQuestAttribute("nigel_con_parri_checker", "win"))
			{
				link.l2 = DLG_TEXT[15];
				link.l2.go = "garri";
			}
 			if (CheckQuestAttribute("BadBlaze", "debut"))
			{
				dialog.Text = DLG_TEXT[91];
				link.l1 = DLG_TEXT[92];
				link.l1.go = "gov_1";
			}
 			if (CheckQuestAttribute("Hunter", "debut"))
			{
				dialog.Text = DLG_TEXT[141];
				link.l1 = DLG_TEXT[142];
				link.l1.go = "gov_25";
			}
			link.l99 = DLG_TEXT[16];
			link.l99.go = "exit";
		break;

		case "garri":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "garri_2";
		break;

		case "garri_2":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			if (CheckQuestAttribute("nigel_con_parri_checker", "win_win"))
			{
				link.l1.go = "garri_3";
			}
			else
			{
				link.l1.go = "exit";
			}
			AddQuestrecord("nigel", 15);
			DeleteAttribute(PChar, "quest.nigel_con_parri_checker");
			PChar.quest.con_parri_expired.over = "yes";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 3000);
			ChangeCharacterReputation(pchar, 1);
			AddDialogExitQuest("nigel_third_encounter");
		break;

		case "garri_3":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "garri_4";
		break;

		case "garri_4":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 6000);
			ChangeCharacterReputation(pchar, 1);
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "j_day":
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_CIVIL, false, false)); // KK
			dialog.text = GetMyFullName(PChar) + DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "continue1";
		break;

		case "continue1":
			LAi_QuestDelay("ex_dialog", 2);
			DialogExit();
			NextDiag.CurrentNode = "j_day2";
		break;

		case "j_day2":
			dialog.text = GetMyFullName(PChar) + DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";
		break;

		case "gov_1":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "gov_2";
		break;

		case "gov_2":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];
			link.l1.go = "gov_3";
		break;

		case "gov_3":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "gov_4";
		break;

		case "gov_4":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[100];
			link.l1.go = "gov_5";
		break;

		case "gov_5":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[101];
			link.l1 = DLG_TEXT[102];
			link.l1.go = "gov_6";
		break;

		case "gov_6":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[103];
			link.l1 = DLG_TEXT[104];
			link.l1.go = "gov_7";
		break;

		case "gov_7":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[106];
			link.l1.go = "gov_8";
		break;

		case "gov_8":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[107];
			link.l1 = DLG_TEXT[108];
			link.l1.go = "gov_9";
		break;

		case "gov_9":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[109];
			link.l1 = DLG_TEXT[110];
			link.l1.go = "gov_10";
		break;

		case "gov_10":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[112];
			link.l1.go = "gov_11";
		break;

		case "gov_11":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[114];
			link.l1.go = "gov_12";
		break;

		case "gov_12":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[115];
			link.l1 = DLG_TEXT[116];
			link.l1.go = "gov_13";
		break;

		case "gov_13":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[117];
			link.l1 = DLG_TEXT[118];
			link.l1.go = "gov_14";
		break;

		case "gov_14":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[119];
			link.l1 = DLG_TEXT[120];
			link.l1.go = "gov_15";
		break;

		case "gov_15":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[121];
			link.l1 = DLG_TEXT[122];
			link.l1.go = "gov_16";
		break;

		case "gov_16":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[123];
			link.l1 = DLG_TEXT[124];
			link.l1.go = "exit";
			pchar.quest.BadBlaze = "partir";
			AddDialogExitQuest("debutquete");
		break;

		case "gov_17":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[125];
			link.l1 = DLG_TEXT[126];
			link.l1.go = "gov_18";
		break;

		case "gov_18":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[127];
			link.l1 = DLG_TEXT[128];
			link.l1.go = "gov_19";
		break;

		case "gov_19":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[129];
			link.l1 = DLG_TEXT[130];
			link.l1.go = "gov_20";
		break;

		case "gov_20":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[131];
			link.l1 = DLG_TEXT[132];
			link.l1.go = "gov_21";
		break;

		case "gov_21":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[133];
			link.l1 = DLG_TEXT[134];
			link.l1.go = "gov_22";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 40000);
		break;

		case "gov_22":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[135];
			link.l1 = DLG_TEXT[136];
			link.l1.go = "gov_23";
		break;

		case "gov_23":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[137];
			link.l1 = DLG_TEXT[138];
			link.l1.go = "gov_24";
			PlayStereoSound("INTERFACE\took_item.wav");
			GiveItem2Character(Pchar, "bladeBP");
		break;

		case "gov_24":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[139];
			link.l1 = DLG_TEXT[140];
			link.l1.go = "exit";
			Pchar.quest.back_emilio.win_condition.l1 = "location";
			Pchar.quest.back_emilio.win_condition.l1.location = "Conceicao_town";
			PChar.quest.back_emilio.win_condition = "natconceicao4";
		break;

		case "gov_25":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[143];
			link.l1 = DLG_TEXT[144];
			link.l1.go = "gov_26";
		break;

		case "gov_26":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[145];
			link.l1 = DLG_TEXT[146];
			link.l1.go = "gov_27";
		break;

		case "gov_27":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[147];
			link.l1 = DLG_TEXT[148];
			link.l1.go = "gov_28";
		break;

		case "gov_28":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[149];
			link.l1 = DLG_TEXT[150];
			link.l1.go = "gov_29";
		break;

		case "gov_29":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[151];
			link.l1 = DLG_TEXT[152];
			link.l1.go = "gov_30";
		break;

		case "gov_30":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[153];
			link.l1 = DLG_TEXT[154];
			link.l1.go = "gov_31";
		break;

		case "gov_31":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[155];
			link.l1 = DLG_TEXT[156];
			link.l1.go = "gov_32";
		break;

		case "gov_32":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[157];
			link.l1 = DLG_TEXT[158];
			link.l1.go = "gov_33";
		break;

		case "gov_33":
			dialog.snd = "Voice\REGR\REGR008";
			if(IsInServiceOf(PORTUGAL)) {
				dialog.text = DLG_TEXT[159];
			}else{
				dialog.text = DLG_TEXT[229];
				SetRank(PChar, PORTUGAL, GetOldRank(PChar, PORTUGAL));
			}
			link.l1 = DLG_TEXT[160];
			link.l1.go = "exit";
			pchar.quest.Hunter = "partir";
			AddDialogExitQuest("Meet_Queiroz");
		break;

		case "gov_34":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[161];
			link.l1 = DLG_TEXT[162];
			link.l1.go = "gov_35";
		break;

		case "gov_35":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[163];
			link.l1 = DLG_TEXT[164];
			link.l1.go = "gov_36";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 50000);
		break;

		case "gov_36":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[165];
			link.l1 = DLG_TEXT[166];
			link.l1.go = "gov_37";
		break;

		case "gov_37":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[167];
			link.l1 = DLG_TEXT[168];
			link.l1.go = "gov_38";
		break;

		case "gov_38":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[169];
			link.l1 = DLG_TEXT[170];
			link.l1.go = "gov_39";
		break;

		case "gov_39":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[171];
			link.l1 = DLG_TEXT[172];
			link.l1.go = "gov_40";
		break;

		case "gov_40":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[173];
			link.l1 = DLG_TEXT[174];
			link.l1.go = "gov_41";
		break;

		case "gov_41":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[175];
			link.l1 = DLG_TEXT[176];
			link.l1.go = "gov_42";
		break;

		case "gov_42":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[177];
			link.l1 = DLG_TEXT[178];
			link.l1.go = "gov_43";
		break;

		case "gov_43":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[179];
			link.l1 = DLG_TEXT[180];
			link.l1.go = "gov_44";
		break;

		case "gov_44":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[181];
			link.l1 = DLG_TEXT[182];
			link.l1.go = "gov_45";
		break;

		case "gov_45":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[183];
			link.l1 = DLG_TEXT[184];
			link.l1.go = "gov_46";
			GiveItem2Character(Pchar, "Letter_Spy");
		break;

		case "gov_46":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[185];
			link.l1 = DLG_TEXT[186];
			link.l1.go = "exit";
			AddDialogExitQuest("Meet_Corrales");
		break;

		case "gov_47":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[187];
			link.l1 = DLG_TEXT[188];
			link.l1.go = "gov_48";
		break;

		case "gov_48":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[189];
			link.l1 = DLG_TEXT[190];
			link.l1.go = "gov_49";
		break;

		case "gov_49":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[191];
			link.l1 = DLG_TEXT[192];
			link.l1.go = "gov_50";
		break;

		case "gov_50":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[193];
			link.l1 = DLG_TEXT[194];
			link.l1.go = "gov_51";
		break;

		case "gov_51":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[195];
			link.l1 = DLG_TEXT[196];
			link.l1.go = "gov_52";
		break;

		case "gov_52":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[197];
			link.l1 = DLG_TEXT[198];
			link.l1.go = "gov_53";
		break;

		case "gov_53":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[199];
			link.l1 = DLG_TEXT[200];
			link.l1.go = "gov_54";
		break;

		case "gov_54":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[201];
			link.l1 = DLG_TEXT[202];
			link.l1.go = "gov_55";
		break;

		case "gov_55":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[203];
			link.l1 = DLG_TEXT[204];
			link.l1.go = "gov_56";
		break;

		case "gov_56":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[205];
			link.l1 = DLG_TEXT[206];
			link.l1.go = "gov_57";
		break;

		case "gov_57":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[207];
			link.l1 = DLG_TEXT[208];
			link.l1.go = "exit";
			AddDialogExitQuest("recevoir_lettre");
		break;

		case "gov_58":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[209];
			link.l1 = DLG_TEXT[210];
			link.l1.go = "gov_59";
		break;

		case "gov_59":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[211];
			link.l1 = DLG_TEXT[212];
			link.l1.go = "gov_60";
		break;

		case "gov_60":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[213];
			link.l1 = DLG_TEXT[214];
			link.l1.go = "gov_61";
		break;

		case "gov_61":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[215];
			link.l1 = DLG_TEXT[216];
			link.l1.go = "gov_62";
		break;

		case "gov_62":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[217];
			link.l1 = DLG_TEXT[218];
			link.l1.go = "gov_63";
		break;

		case "gov_63":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[219];
			link.l1 = DLG_TEXT[220];
			link.l1.go = "exit";
		    GiveItem2Character(Pchar, "Letter_King");
			AddDialogExitQuest("retrouve_queiroz");
		break;

		case "gov_64":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[221];
			link.l1 = DLG_TEXT[222];
			link.l1.go = "gov_65";
		break;

		case "gov_65":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[223];
			link.l1 = DLG_TEXT[224];
			link.l1.go = "gov_66";
		break;

		case "gov_66":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[225];
			link.l1 = DLG_TEXT[226];
			link.l1.go = "gov_67";
		break;

		case "gov_67":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[227];
			link.l1 = DLG_TEXT[228];
			link.l1.go = "exit";
			AddDialogExitQuest("back_grenade16");
		break;
	}
}
