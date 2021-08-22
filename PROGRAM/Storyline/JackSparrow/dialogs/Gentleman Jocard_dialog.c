//#include "DIALOGS\Artois Voysey_dialog.h"

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
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = "Second Time";
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit1":
			AddDialogExitQuest("Leave_Voysey");
			Diag.CurrentNode = "continue2";
			DialogExit();
			AddQuestRecord("Jocard", 3);
		break;

		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
		
			dialog.snd = "Voice\ARVO\ARVO001";
		if(NPChar.quest.meeting == "0")
			{
				d.Text = DLG_TEXT[31];
				Link.l1 = DLG_TEXT[33];
				Link.l1.go = "kill_Art";
				Link.l2 = DLG_TEXT[32];
				Link.l2.go = "cont";
				NPC_meeting = "1";
			}
			else
			{
				d.Text = DLG_TEXT[0];
				Link.l1 = DLG_TEXT[1];
				Link.l1.go = "continue";
			}
		break;
		
		case "second time":
			d.Text = DLG_TEXT[42];
			Link.l1 = DLG_TEXT[43];
			Link.l1.go = "exit";
		break;

/*		case "After_death":		
			dialog.snd = "Voice\ARVO\ARVO001";
			d.Text = DLG_TEXT[0];
			//if (PChar.sex == "man")
			//{
				Link.l1 = DLG_TEXT[1]; 
			//}
			//else 
			//{
			//	Link.l1 = DLG_TEXT[2]; 
			//}
			Link.l1.go = "continue";
		break;*/

		case "kill_Art":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			AddDialogExitQuest("killing_artois");
		break;

		case "cont":
			AddDialogExitQuest("saving_artois");
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
		
		case "continue":
			dialog.snd = "Voice\ARVO\ARVO002";
			d.Text = DLG_TEXT[3];
			Link.l1 = PCharPhrase (DLG_TEXT[4], DLG_TEXT[5] + GetMyName(Pchar) + DLG_TEXT[6]);
			Link.l1.go = "continue2";
		break;

		case "continue2":
			dialog.snd = "Voice\ARVO\ARVO003";
			d.Text = DLG_TEXT[7];
			Link.l99 = DLG_TEXT[8];
			Link.l99.go = "exit1";
			Link.l2 = DLG_TEXT[9];
			Link.l2.go = "listed";
		break;

		case "listed":
			AddDialogExitQuest("Voysey_listed");
			AddQuestRecord("Jocard", 2);
			Diag.CurrentNode = "officer_Artois";
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "officer_Artois":
			dialog.snd1 = "Voice\ARVO\ARVO004";
			dialog.snd2 = "Voice\ARVO\ARVO005";
			dialog.snd3 = "Voice\ARVO\ARVO006";
			Diag.TempNode = "officer_Artois";
			d.Text = RandPhrase (DLG_TEXT[10], DLG_TEXT[11], DLG_TEXT[12], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "exit";
		break;

		case "Captured":
			dialog.snd = "Voice\ARVO\ARVO007";
			if(GetAttribute(pchar, "Jocard") == "Bonaire")
			{
				d.Text = DLG_TEXT[34];
			}
			else
			{
				d.Text = DLG_TEXT[14];
			}
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "continue4";
		break;

		case "continue4":
			dialog.snd = "Voice\ARVO\ARVO008";
			if(GetAttribute(pchar, "Jocard") == "Bonaire")
			{
				d.Text = DLG_TEXT[16];
			}
			else
			{
				d.Text = DLG_TEXT[17];
			}
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "continue5";
		break;

		case "continue5":
			dialog.snd = "Voice\ARVO\ARVO009";
			
			pchar.quest.shore_ship.win_condition.l1 = "location";
			pchar.quest.shore_ship.win_condition.l1.character = "Gentleman Jocard";
			pchar.quest.shore_ship.win_condition.l1.location = "Douwesen_shore_ship";
			
			pchar.quest.shore_ship.win_condition.l2 = "location";
			pchar.quest.shore_ship.win_condition.l2.character = "Bos'un";
			pchar.quest.shore_ship.win_condition.l2.location = "Douwesen_shore_ship";

			pchar.quest.shore_ship.win_condition = "shore_ship";

			pchar.quest.before_shore_ship.win_condition.l1 = "location";
			pchar.quest.before_shore_ship.win_condition.l1.location = "Douwesen_town_exit";
			pchar.quest.before_shore_ship.win_condition = "before_shore_ship";

			if (GetAttribute(pchar, "Bosun") == "Cursed")
			{
				Characters[GetCharacterIndex("Bos'un")].name = TranslateString("","Nigel");
				Characters[GetCharacterIndex("Bos'un")].lastname = TranslateString("","the Slave");
				Characters[GetCharacterIndex("Bos'un")].model = "Ancient";
				Characters[GetCharacterIndex("Bos'un")].headmodel = "h_Ancient";
			}

			Locations[FindLocation("Douwesen_shore_ship")].vcskip = true; // PB
			
			NPChar.loyality = makeint(NPChar.loyality) - 2;	
			Link.l1 = DLG_TEXT[20];
			if (GetNationRelation2MainCharacter(ENGLAND) == RELATION_ENEMY)
			{
				link.l1.go = "continue7";
			}
			else
			{
				Link.l1.go = "exit";
			}
			OfficersReaction("bad");
			if(GetAttribute(pchar, "Jocard") == "Bonaire")
			{
				d.Text = DLG_TEXT[35];
				AddDialogExitQuest("Artois_resque_in_tavern");
			}
			else
			{
				d.Text = DLG_TEXT[19];
				AddQuestRecord("Jocard", 11);
			}
			AddDialogExitQuest("Voysey_listed_2");
		break;
		
		case "continue6":
			dialog.snd = "Voice\ARVO\ARVO010";
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];

		break;
		
		case "continue7":
			dialog.snd = "Voice\ARVO\ARVO011";
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "continue_8";
		break;
		
		case "continue_8":
			dialog.snd = "Voice\ARVO\ARVO012";
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "exit";
			AddDialogExitQuest("portugal_becomes_neutral");
			AddQuestRecord("Jocard", 12);
		break;
		
		case "Jocard_Request":
			dialog.snd = "Voice\ARVO\ARVO013";
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "Jocard_Request2";
		break;
		
		case "Jocard_Request2":
			dialog.snd = "Voice\ARVO\ARVO014";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Jocard_Request3";
			
			GiveItem2Character(pchar, "Sparrow_Ring1");
			PlayStereoSound("INTERFACE\took_item.wav");

			//Characters[GetCharacterIndex("Gentleman Jocard")].model = "9JC";
			//Characters[GetCharacterIndex("Gentleman Jocard")].headmodel = "h_9JC";
			Characters[GetCharacterIndex("Gentleman Jocard")].name = TranslateString("", "Gentleman");
			Characters[GetCharacterIndex("Gentleman Jocard")].lastname = TranslateString("", "Jocard");
		break;
		
		case "Jocard_Request3":
			dialog.snd = "Voice\ARVO\ARVO014";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "Jocard_Request4";			
		break;
		
		case "Jocard_Request4":
			dialog.snd = "Voice\ARVO\ARVO014";
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "Jocard_Request5";			
		break;
		
		case "Jocard_Request5":
			dialog.snd = "Voice\ARVO\ARVO014";
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "exit";
			
			AddQuestRecord("Jocard", 15);
			AddQuestRecord("Pirate Lord", 10);

			AddDialogExitQuest("Eleuthera_Options");
		break;

		case "knock out":
			dialog.snd = "Voice\ARVO\ARVO014";
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "exit";

			AddDialogExitQuest("Slaver_knock4");
		break;

		case "In Tavern":
			dialog.snd = "Voice\ARVO\ARVO014";
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			AddDialogExitQuest("Jocard_follow");
			link.l1.go = "exit";
		break;

		case "On_Deck":
			dialog.snd = "Voice\ARVO\ARVO014";
			dialog.text = DLG_TEXT[48];
			if (GetAttribute(pchar, "Bosun") == "Cursed")
			{
				link.l1 = DLG_TEXT[54];
			}
			else
			{
				link.l1 = DLG_TEXT[49];
			}
			link.l1.go = "exit";

			AddDialogExitQuest("Jocard_Deck3");
		break;

		case "On_Deck2":
			dialog.snd = "Voice\ARVO\ARVO014";
			if (GetAttribute(pchar, "Bosun") == "Cursed")
			{
				dialog.text = DLG_TEXT[55];
				link.l1 = DLG_TEXT[56];
			}
			else
			{
				dialog.text = DLG_TEXT[50];
				link.l1 = DLG_TEXT[51];
			}
			link.l1.go = "exit";

			AddDialogExitQuest("Jocard_Deck4");
		break;

		case "On_Deck3":
			dialog.snd = "Voice\ARVO\ARVO014";
			if (GetAttribute(pchar, "Bosun") == "Cursed")
			{
				dialog.text = DLG_TEXT[57];
				link.l1 = DLG_TEXT[58];
			}
			else
			{
				dialog.text = DLG_TEXT[52];
				link.l1 = DLG_TEXT[53];
			}
			link.l1.go = "exit";

			AddDialogExitQuest("Jocard_Deck6");
		break;

		case "guards_dead":
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "be_a_pirate";
		break;

		case "be_a_pirate":
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "be_a_lord";
		break;

		case "be_a_lord":
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "need_a_ship";
		break;

		case "need_a_ship":
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "now_youre_jocard";
		break;

		case "now_youre_jocard":
			dialog.text = DLG_TEXT[67]
			link.l1 = DLG_TEXT[68];
			AddDialogExitQuest("slaves_run");
			AddDialogExitQuest("reset_slave5");
			link.l1.go = "exit";
		break;
	}
}
