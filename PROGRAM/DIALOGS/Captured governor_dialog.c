void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar = GetMainCharacter();
	int i, iNation;
	string tempstr = "";

	if (strlen(Dialog.CurrentNode) > 11 && strcut(Dialog.CurrentNode, 0, 10) == "new_nation_") {
		iNation = sti(strcut(Dialog.CurrentNode, 11, strlen(Dialog.CurrentNode) - 1));

		if (iNation != PIRATE)
			Dialog.Text = DLG_TEXT[9] + XI_ConvertString(GetNationDescByType(iNation)) + ".";
		else
			Dialog.Text = DLG_TEXT[10];
		Link.l1 = DLG_TEXT[11];
		Link.l1.go = "capture_colony_exit";

		PChar.colony_capture.nation = iNation;

		return;
	}

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
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

			RestoreAlwaysRunState();

			NPChar.nBooty = makeint(makefloat(GetTownGold(NPChar.town)) * TOWN_GOLD_SACK_SCALAR * (0.75 + frand(0.25) + makefloat(GetShipSkill(PChar, SKILL_SNEAK)/20.0)));

			PChar.colony_capture.town = NPChar.town;
			PChar.colony_capture.govidx = GetCharacterIndex(NPChar.id);

			Dialog.Text = DLG_TEXT[0];
			if(ProfessionalNavyNation() == UNKNOWN_NATION || !isEnabledTownCapture(NPChar.town))
			{
				Link.l1 = DLG_TEXT[1] + NPChar.nBooty + DLG_TEXT[2];
				Link.l1.go = "Colony_Ransomed";
			}
			if (isEnabledTownCapture(NPChar.town)) {
				Link.l2 = DLG_TEXT[3];
				Link.l2.go = "Select_New_Government";
			}
			Diag.TempNode = "first time";
		break;

		case "Colony_Ransomed":
			RansomColony(PChar.colony_capture.town, sti(NPChar.nBooty));
			DeleteAttribute(PChar, "colony_capture");
			EndQuestMovie();

			DialogExit();
			Diag.TempNode = "Exit";
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "Select_New_Government":
			Dialog.Text = DLG_TEXT[4];
			iNation = sti(NPChar.nation);
			for (i = 0; i < NATIONS_QUANTITY; i++)
			{
				if (i == iNation) continue;
				tempstr = "l" + (i + 1);
				if(ProfessionalNavyNation() == UNKNOWN_NATION || i == ProfessionalNavyNation())
				{
					Link.(tempstr) = DLG_TEXT[5] + XI_ConvertString("4"+GetNationDescByType(i)) + DLG_TEXT[6];
					Link.(tempstr).go = "new_nation_" + i;
				}
			}
//			i = makeint(GetTownGovernorIndex(NPChar.town) > -1) + GetTownNumForts(NPChar.town);
			i = GetTownNumForts(NPChar.town) + 1;							// GR: simplified, if (makeint(GetTownGovernorIndex(NPChar.town) > -1) is false then original line sets i to wrong value
			if (GetTownGovernorIndex(NPChar.town) > -1 && GetPassengersQuantity(PChar) >= i && ProfessionalNavyNation() == UNKNOWN_NATION)
			{
				Link.l10 = DLG_TEXT[7];
				Link.l10.go = "capture_for_blaze";
			}
			Link.l99 = DLG_TEXT[8];
			Link.l99.go = "First time";
		break;

		case "capture_for_blaze":
			DialogExit();
			Diag.TempNode = "Exit";
			Diag.CurrentNode = Diag.TempNode;

			EndQuestMovie();
			if (GetTownGovernorIndex(NPChar.town) != -1 || GetTownNumForts(NPChar.town) > 0) {
				LaunchCaptureColony(PChar, NPChar.town);
			} else {
				CaptureColony(NPChar.town, PERSONAL_NATION);
				DeleteAttribute(PChar, "colony_capture");
			}
		break;

		case "capture_colony_exit":
			AddDialogExitQuest("ColonyCapture_Capture");
			EndQuestMovie();

			DialogExit();
			Diag.TempNode = "Exit";
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
