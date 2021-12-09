void ProcessDialogEvent()
{
	ref NPChar, PChar;
	PChar = GetMainCharacter();
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
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
			Dialog.snd = "dialogs\0\009";


			dialog.text = DLG_TEXT[0] + GetMyName(NPChar) + DLG_TEXT[1];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "wench";
			link.l2 = DLG_TEXT[3];
			link.l2.go = "exit";
			link.l2 = DLG_TEXT[4];
			link.l2.go = "about";

			Diag.TempNode = "first time";
		break;

		case "about":
			Dialog.Text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "wench";
			link.l2 = DLG_TEXT[7];
			link.l2.go = "exit";
		break;

		case "wench":
			Dialog.Text = DLG_TEXT[8];
			if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 6.0)
			{
				link.l1 = DLG_TEXT[9];
				link.l1.go = "wench_day";
			}
			else
			{
				link.l1 = DLG_TEXT[10];
				link.l1.go = "wench_night";
			}
		break;

		case "wench_night":
			Dialog.text = DLG_TEXT[11];//talking cost
			if (makeint(pchar.money) >= 50)
			{
				link.l1 = DLG_TEXT[12];//agreeing
				link.l1.go = "room_night_wait";
			}
			link.l2 = DLG_TEXT[13];//too much
			link.l2.go = "exit";
		break;

		case "wench_day":
			Dialog.text = DLG_TEXT[14];//talking cost
			if (makeint(pchar.money) >= 50)
			{
				link.l1 = DLG_TEXT[15];//agreeing
				link.l1.go = "room_day_wait";
			}
			link.l2 = DLG_TEXT[16];//too much
			link.l2.go = "exit";
		break;

		case "exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;//this is why the first thing is said
		break;

		case "room_night_wait":
			if (PChar.location == "QC_brothel")
			{
				ChangeCharacterAddress(CharacterFromID("wench1U"), "None", "");	// Clear all upstairs girls, then place the correct one for current time.
				ChangeCharacterAddress(CharacterFromID("wench2U"), "None", ""); // Can't be done by login time because you spawn in upstairs room at 22:00.
				ChangeCharacterAddress(CharacterFromID("wench3U"), "None", "");
				ChangeCharacterAddress(CharacterFromID("wench4U"), "None", "");
				if(GetTime() >= 6.0 && GetTime() < 12.0) ChangeCharacterAddressGroup(CharacterfromID("wench4U"), "QC_brothel_upstairs", "goto", "goto3");
				if(GetTime() >= 12.0 && GetTime() < 18.0) ChangeCharacterAddressGroup(CharacterfromID("wench1U"), "QC_brothel_upstairs", "goto", "goto5");
				if(GetTime() >= 18.0 && GetTime() < 24.0) ChangeCharacterAddressGroup(CharacterfromID("wench3U"), "QC_brothel_upstairs", "goto", "goto7");
			}
			GotSlut("night");//MAXIMUS
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "room_day_wait":
			if (PChar.location == "QC_brothel")
			{
				ChangeCharacterAddress(CharacterFromID("wench1U"), "None", "");	// Clear all upstairs girls, then place the correct one for current time.
				ChangeCharacterAddress(CharacterFromID("wench2U"), "None", ""); // Can't be done by login time because you spawn in upstairs room at 10:00.
				ChangeCharacterAddress(CharacterFromID("wench3U"), "None", "");
				ChangeCharacterAddress(CharacterFromID("wench4U"), "None", "");
				if(GetTime() >= 18.0 && GetTime() < 24.0) ChangeCharacterAddressGroup(CharacterfromID("wench3U"), "QC_brothel_upstairs", "goto", "goto7");
				if(GetTime() >= 0.0 && GetTime() < 6.0) ChangeCharacterAddressGroup(CharacterfromID("wench2U"), "QC_brothel_upstairs", "goto", "goto2");
			}
			GotSlut("day");//MAXIMUS
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
