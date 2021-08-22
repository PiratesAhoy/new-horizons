
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
	int iTest;

	ref lcn = &Locations[FindLocation(PChar.location)];
	if(CheckAttribute(pchar,"lasttownsack") ) lcn.townsack = pchar.lasttownsack;

	ref chr;
	string NPC_Meeting;
	
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
			
			dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1];
			link.l1 = DLG_TEXT[2] + GetMyFullName(PChar) + DLG_TEXT[3];
			link.l1.go = "second time";
			NextDiag.TempNode = "second time";
		break;

		case "second time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			NPC_Meeting = "1";		

			if (rand(100)<30 && NPChar.quest.meeting == "0")
			{
  			dialog.text = DLG_TEXT[4] + pchar.lastname + DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				link.l1.go = "officer";
  			link.l2 = DLG_TEXT[7];
  			link.l2.go = "officer";				
			}
			else
			{
			dialog.text = DLG_TEXT[8];
			link.l2 = LinkRandPhrase(DLG_TEXT[9], DLG_TEXT[10], DLG_TEXT[11]);
			link.l2.go = "crew";
			link.l3 = LinkRandPhrase(DLG_TEXT[12], DLG_TEXT[13], DLG_TEXT[14]);
			link.l3.go = "room";
			link.l4 = LinkRandPhrase(DLG_TEXT[52], DLG_TEXT[53], DLG_TEXT[54]);
			link.l4.go = "room";
			link.l5 = LinkRandPhrase(DLG_TEXT[46], DLG_TEXT[47], DLG_TEXT[48]);
			link.l5.go = "gather_information";	
			link.l6 = DLG_TEXT[15];
			link.l6.go = "exit";
			}
		break;

		case "officer":
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			chr = LAi_CreateFantomCharacterEx(false, 0, true, true, 0.0, GetRandomModelForType(1, "Mates"), "reload", "reload2");	
			chr.dialog.filename = "Enc_shipmate.c";
			chr.dialog.CurrentNode = "First time";
			LAi_SetHP(chr, 300.0, 300.0);
			Lai_SetActorType(chr);
			LAi_ActorDialog(chr, pchar, "", 12.0, 4.0);
		break;

		case "gather_information":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			LaunchNews();
		break;
		
		case "room":
			string roomWait = "";
			dialog.text = DLG_TEXT[16];
			if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 6.0)
			{
				roomWait = "eveningwait";
				link.l1 = DLG_TEXT[17];
				link.l1.go = "room_day";
			}
			else
			{
				roomWait = "daywait";
				link.l1 = DLG_TEXT[18];
				link.l1.go = "room_night";
			}
			link.l2 = XI_ConvertString("Until tomorrow") + " " + XI_ConvertString(roomWait) + ".";
			link.l2.go = "room_24";
		break;

		case "room_24":
			dialog.snd = "Voice\ANLE\ANLE014";
			Dialog.text = DLG_TEXT[19];
			link.l1 = LinkRandPhrase(DLG_TEXT[20], DLG_TEXT[21], DLG_TEXT[22]);
			link.l1.go = "hall_24_wait";
			link.l2 = DLG_TEXT[23];
			link.l2.go = "exit";
		break;

		case "hall_24_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			LAi_Fade("", "");
			WaitDate("",0,0,0,24,1);
			RecalculateJumpTable();
		break;

		case "room_day":
			Dialog.text = DLG_TEXT[19];
			link.l1 = LinkRandPhrase(DLG_TEXT[20], DLG_TEXT[21], DLG_TEXT[22]);
			link.l2.go = "hall_day_wait";
			link.l2 = DLG_TEXT[23];
			link.l3.go = "exit";
		break;

		case "room_night":
			Dialog.text = DLG_TEXT[19];
			link.l1 = LinkRandPhrase(DLG_TEXT[20], DLG_TEXT[21], DLG_TEXT[22]);
			link.l2.go = "hall_night_wait";
			link.l2 = DLG_TEXT[23];
			link.l3.go = "exit";
		break;

		case "hall_night_wait":
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			TavernWaitDate("wait_night");
		break;

		case "hall_day_wait":
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			TavernWaitDate("wait_day");
		break;

		case "crew":
			if (NPChar.quest.meeting == "0")
			{
				dialog.text = DLG_TEXT[24];
				link.l1 = DLG_TEXT[25];
				link.l1.go = "Exit_crimp";
			}
			else
			{
				dialog.text = DLG_TEXT[26];
				link.l1 = DLG_TEXT[27];
				link.l1.go = "Exit";
			}
		break;

		case "Exit_crimp":
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			chr = LAi_CreateFantomCharacterEx(false, 0, true, true, 0.0, GetRandomModelForType(1, "sailors"), "reload", "reload1");	
			chr.dialog.filename = "Enc_crimp.c";
			chr.dialog.CurrentNode = "First time";
			LAi_SetHP(chr, 20.0, 20.0);
			Lai_SetActorType(chr);
			LAi_ActorDialog(chr, pchar, "", 12.0, 4.0);
		break;

		case "Exit":
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

	}
}
