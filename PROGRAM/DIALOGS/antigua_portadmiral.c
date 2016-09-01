void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];

	Npchar.nation = Characters[getCharacterIndex("St John's Commander")].nation;
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\PADI\PADI001";

			if (CheckQuestAttribute("Firstcontact", "search"))
			{
				dialog.snd = "Voice\CLLA\CLLA001";
				dialog.text = DLG_TEXT[101];
				link.l1 = DLG_TEXT[102];
				link.l1.go = "begin";
			}
			else
			{
				Dialog.text =  DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
				link.l2 = DLG_TEXT[2] + GetMyFullName(PChar) + DLG_TEXT[3];
				link.l2.go = "sorry";
			}
		break;

		case "sorry":
			if(GetRMRelation(Pchar, sti(NPChar.nation) ) <= REL_WAR )
			{
				Dialog.text = GetMyFullName(PChar) +DLG_TEXT[4];
				link.l1 = Randswear();
				link.l1.go = "fight";
			}
			else
			{
				if(IsInServiceOf(ENGLAND))
				{
					Dialog.text = DLG_TEXT[5];
					link.l2 = DLG_TEXT[21];
					link.l2.go = "convoy";
				}
				else
				{
					Preprocessor_Add("nation_desc", GetNationDescByType(Npchar.nation));
					Dialog.text = DLG_TEXT[23];
					link.l2 = DLG_TEXT[24];
					link.l2.go = "exit";
				}
			}
		break;

		case "convoy":
			Dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[7];
			link.l2.go = "convoy2";
			if (CheckQuestAttribute("veralmirante", "inicio"))
			{
			    link.l3 = DLG_TEXT[117];
				link.l3.go = "insist_admiral";
			}
		break;
		
		case "convoy2":
			string iDay, iMonth;
			iDay = environment.date.day;
			iMonth = environment.date.month;
			string lastspeak_date = iday + " " + iMonth;
			npchar.work = lastspeak_date;

			if (GetCompanionIndex(pchar,1) != -1 && GetCompanionIndex(pchar,2) != -1 && GetCompanionIndex(pchar,3) != -1)
			{
				dialog.text = DLG_TEXT[8];
				link.l1 = DLG_TEXT[9];
				link.l1.go = "Exit";
			}
			else
			{
				if (CheckQuestAttribute("generate_convoy_quest_progress", "begin"))
				{
					dialog.text = DLG_TEXT[10];
					link.l1 = DLG_TEXT[11];
					link.l1.go = "Exit";
				}
				else
				{
					dialog.text = DLG_TEXT[12]+pchar.lastname+DLG_TEXT[13];
					link.l1 = DLG_TEXT[14];
					link.l1.go = "Exit";
					ChangeRMRelation(pchar, sti(NPChar.nation), 3.0)
					pchar.quest.generate_convoy_quest.destination = "Conceicao";
					AddDialogExitQuest("prepare_for_convoy_quest");
				}
			}
		break;

		case "harbour":
			Dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";

			link.l3 = DLG_TEXT[17];
			link.l3.go = "provisions";
		break;

		case "provisions":
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[20];
			link.l2.go = "harbour";
		break;

		case "begin":
			dialog.snd = "Voice\CLLA\CLLA003";
			dialog.text = DLG_TEXT[103];
			link.l1 = DLG_TEXT[104];
			link.l1.go = "begin_2";
		break;

		case "begin_2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[106];
			link.l1.go = "begin_3";
		break;

		case "begin_3":
			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[107];
			link.l1 = DLG_TEXT[108];
			link.l1.go = "begin_4";
		break;

		case "begin_4":
			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[109];
			link.l1 = DLG_TEXT[110];
			link.l1.go = "begin_5";
		break;

		case "begin_5":
			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[112];
			link.l1.go = "exit";
			AddQuestRecord("Contact", "3");
			PChar.quest.Firstcontact = "nosearch";
			Pchar.quest.philips_port.win_condition.l1 = "location";
			Pchar.quest.philips_port.win_condition.l1.location = "Philipsburg_port";
			PChar.quest.philips_port.win_condition = "Contact_arendt";
		break;

		case "contact_return1":
			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[114];
			link.l1.go = "contact_return2";
		break;

		case "contact_return2":
			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[115];
			link.l1 = DLG_TEXT[116];
			link.l1.go = "exit";
			AddDialogExitQuest("Contact_NoLuck");
		break;

		case "insist_admiral":
			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[118];
			link.l1 = DLG_TEXT[119];
			link.l1.go = "insist_admiral2";
		break;

		case "insist_admiral2":
			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[120];
			link.l1 = DLG_TEXT[121];
			link.l1.go = "insist_admiral3";
		break;

		case "insist_admiral3":
			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[122];
			link.l1 = DLG_TEXT[123];
			link.l1.go = "exit";
			AddDialogExitQuest("FrenchPinnace");
		break;

// --------------------- exits -----------------
		case "exit":
//			Diag.CurrentNode = Diag.TempNode;
//			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "fight":
			PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_039.wav");
			LAi_group_SetRelation(NPchar.chr_ai.group, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			Ambush("Soldiers", 3, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, ""); // GR: was "navy"
//			Diag.CurrentNode = Diag.TempNode;
//			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}
