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
			//Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			//Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			//Dialog.snd = "voice\TOOR\TOOR001";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (GetAttribute(characterFromID("Sumbhajee Aid1"), "quest.Sumbhajee") == "help_begin" && GetAttribute(pchar, "spain") == "1")
			{
				link.l1 = DLG_TEXT[2];
				link.l1.go = "brother_1";
			}
			if (GetAttribute(characterFromID("Sumbhajee Aid1"), "quest.Sumbhajee") == "good_2_complete" || GetAttribute(characterFromID("Sumbhajee Aid1"), "quest.Sumbhajee") == "almost_complete")
			{
				dialog.text = DLG_TEXT[3];
				link.l1 = DLG_TEXT[4];
				link.l1.go = "brother_5";
			}
			if (GetAttribute(PChar, "spain") == "done")
			{
				dialog.text = DLG_TEXT[17];
				link.l1 = DLG_TEXT[18];
				link.l1.go = "brother_5";
			}
		break;

		case "brother_1":
			Dialog.snd = "voice\REGR\REGR008";
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "brother_2";
		break;

		case "brother_2":
			Dialog.snd = "voice\REGR\REGR009";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "brother_3";
		break;

		case "brother_3":
			Dialog.snd = "voice\REGR\REGR010";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "brother_4";
		break;

		case "brother_4":
			Dialog.snd = "voice\REGR\REGR011";
			Preprocessor_Add("addr", GetCharacterAddressForm(NPChar, ADDR_TITLE, false, false)); // KK
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
			characters[getcharacterindex("Sumbhajee Aid1")].quest.Sumbhajee = "governor";
			AddQuestRecord("Sumbhajee", 2);
		break;

		case "brother_5":
			GiveModel2Player("Jack", true);
			Dialog.snd = "voice\REGR\REGR012";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "brother_6";
		break;

		case "brother_6":
			Dialog.snd = "voice\REGR\REGR014";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
			//AddQuestRecord("Sumbhajee", 5);
			pchar.spain = "done";
			if (GetAttribute(characterFromID("Sumbhajee Aid1"), "quest.Sumbhajee") == "almost_complete")
			{
				//closeQuestHeader("Sumbhajee");
				characters[getcharacterindex("Sumbhajee Aid1")].quest.Sumbhajee = "almost_2_complete";
			}
			characters[getcharacterindex("Sumbhajee Aid1")].quest.Sumbhajee = "bad_2_complete";
			addDialogExitQuest("kill_Commendant");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 4500);
				AddPartyExpChar(pchar, "Sneak", 45);
			}
			else { AddPartyExp(pchar, 4500); }
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}
