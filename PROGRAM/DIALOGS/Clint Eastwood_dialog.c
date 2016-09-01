void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();


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
			Dialog.snd = "voice\THDI\THDI001";

			Dialog.mood = "angry";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit_fight";

			if(getCharacterIndex("Bootstrap Bill Turner") > -1 && GetOfficersIndex(Pchar, 2) == getCharacterIndex("Bootstrap Bill Turner"))
			{
				dialog.snd = "Voice\BIBR\BIBR002";
				Dialog.Text = DLG_TEXT[2];
				Link.l1 = DLG_TEXT[3];
				Link.l1.go = "The_diamond_exchange";
			}
			if(getCharacterIndex("Bootstrap Bill Turner") > -1 && GetOfficersIndex(Pchar, 3) == getCharacterIndex("Bootstrap Bill Turner"))
			{
				dialog.snd = "Voice\BIBR\BIBR003";
				Dialog.Text = DLG_TEXT[4];
				Link.l1 = DLG_TEXT[5];
				Link.l1.go = "Do_the_deal";
			}

		break;

		case "The_diamond_exchange":
			int tmpdiamond = GetCharacterItem(pChar, "jewelry2");
			dialog.snd = "Voice\BIBR\BIBR005";
			Dialog.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			if (tmpdiamond <= 0)
			{
			Link.l1.go = "The_diamond_exchange2";
			}
			if ((tmpdiamond >= 1) && (tmpdiamond <= 5))
			{
			Link.l1.go = "The_diamond_exchange3";
			}
			if ((tmpdiamond >= 6) && (tmpdiamond <= 100))
			{
			Link.l1.go = "The_diamond_exchange4";
			}
		break;

		case "The_diamond_exchange2":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Exit";
		break;

		case "The_diamond_exchange3":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "Rebuff";
		break;

		case "The_diamond_exchange4":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "Answer_one";
		break;

		case "Rebuff":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "Rebuff2";
		break;

		case "Rebuff2":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "The_diamond_exchange2";
		break;

		case "Answer_one":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "Answer_two";
		break;

		case "Answer_two":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17];
			Link.l1.go = "Exit";
		break;		

		case "Do_the_deal":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[18];
			Link.l1 = DLG_TEXT[19];
			Link.l1.go = "Do_the_deal2";
		break;

		case "Do_the_deal2":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "Do_the_deal3";
		break;

		case "Do_the_deal3":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[23];
			Link.l1.go = "Do_the_deal4";
		break;
		
		case "Do_the_deal4":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "Do_the_deal5";
		break;

		case "Do_the_deal5":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "Do_the_deal6";
			TakeItemFromCharacter(Pchar,"jewelry2");
			TakeItemFromCharacter(Pchar,"jewelry2");
			TakeItemFromCharacter(Pchar,"jewelry2");
			TakeItemFromCharacter(Pchar,"jewelry2");
			TakeItemFromCharacter(Pchar,"jewelry2");
			TakeItemFromCharacter(Pchar,"jewelry2");			
			AddMoneyToCharacter(pchar, +20000);
			GiveItem2Character(Pchar,"Map_Doc_3");

			if (GetAttribute(pchar, "Aztec") != "1")
			{
				SetQuestHeader("Aztec");
				pchar.aztec = "1";
			}
			AddQuestRecord("Aztec", 2);
		break;		

		case "Do_the_deal6":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[28];
			Link.l1 = DLG_TEXT[29];
			Link.l1.go = "Exit_Do_the_deal";
			RemoveOfficersIndex(pchar, GetCharacterIndex("Bootstrap Bill Turner"));
			RemovePassenger(pchar, characterFromID("Bootstrap Bill Turner"));			
		break;		
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_Do_the_deal":		
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Bootstrap Bill Turner"));
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Finished_with_Eastwood");			
		break;

		case "Exit_fight":
			LAi_SetWarriorType(NPChar);
			LAi_group_MoveCharacter(NPChar, "DEVIL_BOSS");
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "DEVIL_BOSS", true);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
