void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

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
			Dialog.snd = "voice\TOOR\TOOR001";

			dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "exit";

			if (npchar.quest.daughter == "")
			{
				Dialog.snd = "voice\TOOR\TOOR002";
				dialog.text = DLG_TEXT[3];
				link.l1 = DLG_TEXT[4];
				link.l1.go = "exit";
				link.l2 = DLG_TEXT[5];
				link.l2.go = "daughter";
			}
			if (npchar.quest.daughter == "help_denied")
			{
				Dialog.snd = "voice\TOOR\TOOR003";
				dialog.text = DLG_TEXT[6];
				link.l1 = DLG_TEXT[7];
				link.l1.go = "exit";
				link.l2 = DLG_TEXT[8];
				link.l2.go = "daughter_8";
			}
			if (npchar.quest.daughter == "bad_2_complete" || npchar.quest.daughter == "good_2_complete")
			{
				Dialog.snd = "voice\TOOR\TOOR004";
				dialog.text = DLG_TEXT[9];
				link.l1 = DLG_TEXT[10];
				link.l1.go = "saber";
			}
			diag.tempnode = "first time";
		break;

		case "saber":
			Dialog.snd = "voice\TOOR\TOOR005";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
			npchar.location = "none";
			Preprocessor_AddQuestData("ToffOremans", GetMySimpleName(CharacterFromID("Toff Oremans")));
			AddQuestRecord("daughter", 6);
			Preprocessor_Remove("ToffOremans");
			if (npchar.quest.daughter == "bad_2_complete")
			{
				npchar.quest.daughter = "complete";
				closeQuestHeader("daughter");
			}
			else
			{
				if (characters[GetCharacterIndex("Toff Oremans")].quest.daughter == "almost_2_complete")
				{
					closeQuestHeader("daughter");
				}
				else
				{
					npchar.quest.daughter = "almost_complete";
				}
			}
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 3500);
				AddPartyExpChar(pchar, "Sneak", 35);
			}
			else { AddPartyExp(pchar, 3500); }
			ChangeCharacterReputation(pchar, 1);
			OfficersReaction("good");
			if(ENABLE_WEAPONSMOD == 1) // PB: Give a worn Saber of Nicolas Sharp (if weapons mod on)
			{GiveItem2Character(pchar, "blade18-1");}
			else
			{GiveItem2Character(pchar, "blade18");}
		break;

		case "daughter":
			Dialog.snd = "voice\TOOR\TOOR006";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[15];
			link.l2.go = "daughter_2";
		break;

		case "daughter_2":
			Dialog.snd = "voice\TOOR\TOOR007";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "daughter_3";
		break;

		case "daughter_3":
			if (makeint(pchar.reputation >50))
			{
				Dialog.snd = "voice\TOOR\TOOR008";
				dialog.text = DLG_TEXT[18];
				link.l1 = DLG_TEXT[19];
				link.l1.go = "daughter_4";
			}
			else
			{
				Dialog.snd = "voice\TOOR\TOOR009";
				dialog.text = DLG_TEXT[20];
				link.l1 = DLG_TEXT[21];
				link.l1.go = "exit";
			}
		break;

		case "daughter_4":
			Dialog.snd = "voice\TOOR\TOOR010";
			dialog.text = DLG_TEXT[22] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[23])]) + DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "daughter_5";
			SetCharacterShipLocation(CharacterFromID("Bernardo Gamboa"), "Douwesen_port");
			SetRumourState("Toff", false); // NK
		break;

		case "daughter_5":
			Dialog.snd = "voice\TOOR\TOOR011";
			dialog.text = DLG_TEXT[26] + GetCharacterFullName(DLG_TEXT[27]) + DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "daughter_6";
		break;

		case "daughter_6":
			Dialog.snd = "voice\TOOR\TOOR012";
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[32];
			link.l2.go = "daughter_7";
			npchar.quest.daughter = "help_denied";
		break;

		case "daughter_7":
			Dialog.snd = "voice\TOOR\TOOR013";
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "exit";
			Preprocessor_AddQuestData("Toff", GetMyFirstNames(CharacterFromID("Toff Oremans"), false));
			Preprocessor_AddQuestData("ToffOremans", GetMySimpleName(CharacterFromID("Toff Oremans")));
			SetQuestheader("daughter");
			AddQuestRecord("daughter", 1);
			Preprocessor_Remove("Toff");
			Preprocessor_Remove("ToffOremans");
			npchar.quest.daughter = "help_begin";
			pchar.quest.to_ship_of_Bernardo_Gamboa.win_condition.l1 = "location";
			pchar.quest.to_ship_of_Bernardo_Gamboa.win_condition.l1.location = "douwesen_port";
			pchar.quest.to_ship_of_Bernardo_Gamboa.win_condition = "to_ship_of_Bernardo_Gamboa";
		break;

		case "daughter_8":
			Dialog.snd = "voice\TOOR\TOOR014";
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[37];
			link.l2.go = "daughter_7";
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}
