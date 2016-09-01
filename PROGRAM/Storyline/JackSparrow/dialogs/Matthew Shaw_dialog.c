void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");
	// RM -->
	int iNation;
	string sNation;
	// RM <--
	string stemp = ""; // KK

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	// PG -->
	if(GetMusicScheme() == "PGMUS") { // KK
		iNation = sti(NPChar.nation);
		sNation = iNation;
		if(musicName != "music_govreward")
		{
			if(GetRMRelation(PChar,iNation) >= REL_AMNESTY) SetMusicNoPause("music_govfriend");
			else SetMusicNoPause("music_govenemy");
		}
	}
	// PG <--

	
	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- |иалог первый - первая встреча
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

			ref lcn = &Locations[FindLocation(pchar.location)]
			if(lcn.id == "Grand_Cayman_townhall")
//			if(CheckAttribute(locations[FindLocation(Pchar.location)],"Grand_Cayman_townhall"))
			{
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "Exit_father_Teague";
			}
			else
			{
				dialog.text = DLG_TEXT[27];
				link.l1 = DLG_TEXT[28];
				link.l1.go = "Exit";
			}
		break;

		case "Exit_father_Teague":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("More_dialogue_from_Teague");
		break;

		case "A_background_discussion":
			PlaySound("VOICE\ENGLISH\Eng_m_c_007.wav");
			dialog.text = DLG_TEXT[2] + Pchar.name + DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "discussion2";
		break;

		case "discussion2":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "discussion3";
		break;

		case "discussion3":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "discussion4";
		break;

		case "discussion4":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "discussion5";
		break;

		case "discussion5":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "discussion6";
		break;

		case "discussion6":
			dialog.text = DLG_TEXT[13] + Pchar.name + DLG_TEXT[14];
			link.l1 = DLG_TEXT[15] + Pchar.name + DLG_TEXT[16];
			link.l1.go = "discussion7";
		break;

		case "discussion7":
			dialog.text = DLG_TEXT[17] + Pchar.name + DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "discussion8";
		break;

		case "discussion8":
			dialog.text = DLG_TEXT[20] + Pchar.name + DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "discussion10";
		break;

		case "discussion10":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "Exit_discussion";
		break;

		case "Arrest at Cayman":
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "Exit_arrest";
		break;

		case "Exit_discussion":
			GiveItem2Character(Pchar,"blade42");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Matthew_the_governor_leaves");
		break;

		case "Exit_arrest":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("present myself");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

	}
}
