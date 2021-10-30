
void ProcessDialogEvent()
{
	ref NPChar,sld;
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
			
			dialog.snd = "Voice\BEGU\BEGU001";
			if (!checkAttribute(Pchar,"quest.poker.started"))
			{
				PlaySound("VOICE\ENGLISH\pir_capR1.wav");
				dialog.text = DLG_TEXT[31];
				link.l1 = DLG_TEXT[32];
				link.l1.go = "Argument";			
			}
			else
			{	
				PlaySound("VOICE\ENGLISH\pir_capR12.wav");
				dialog.text = DLG_TEXT[0];
				if (!checkAttribute(PChar,"quest.poker.winner"))
				{
					link.l1 = DLG_TEXT[1];
					link.l1.go = "Fake 1";
				}
				else
				{
					link.l1 = DLG_TEXT[2];
					link.l1.go = "Fake 2";
				}
			}
		break;

		case "Fake 1":
			PlaySound("VOICE\ENGLISH\pir_capR5.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Fake_reload";
			
		break;
		
		case "Fake 2":
			PlaySound("VOICE\ENGLISH\Eden_so.wav");
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "Fake_reload";
		break;
		
		case "Fake_reload":
			if (!checkAttribute(PChar,"quest.poker.winner"))
				{
				locations[FindLocation(Pchar.location)].image = "poker_invite1.tga";
				TakeItemFromCharacter(pchar, "poker_invite1");//take poker_invite
				}
				else
				{
				locations[FindLocation(Pchar.location)].image = "poker_invite2.tga";
				TakeItemFromCharacter(pchar, "poker_invite2");//take poker_invite
				}
			DoQuestReloadToLocation( "Turks_poker_entre", "goto", "desk","Instructions");	
		break;
		
		case "Argument":
			PlaySound("VOICE\ENGLISH\pir_capR3.wav");
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "Argument2";
		break;
		
		case "Argument2":
			PlaySound("VOICE\ENGLISH\pir_capR11.wav");
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Exit";
		break;
		
		case "Instructions1":
			PlaySound("VOICE\ENGLISH\blaze_3.wav");
			dialog.text = DLG_TEXT[7];
			link.l1.go = "Instructions2";
		break;
		
		case "Instructions2":
			PlaySound("VOICE\ENGLISH\pir_capA.wav");
			dialog.text = DLG_TEXT[8];
			link.l1.go = "Instructions3";
		break;
		
		case "Instructions3":
			PlaySound("VOICE\ENGLISH\Eden_so.wav");
			dialog.text = DLG_TEXT[9];
			link.l1.go = "Instructions4";
		break;
		
		case "Instructions4":
			PlaySound("VOICE\ENGLISH\pir_capR3.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Onward 2";
		break;
		
		case "Onward 2":
			PlaySound("VOICE\ENGLISH\Eden_time_go.wav");
			AddMoneyToCharacter(pchar, -1 * 20000);//take 20000
			
			AddQuestRecord("Poker_Tournament", 2);
			PChar.quest.poker.started = true;
			Locations[FindLocation("Turks_poker_entre")].reload.l1.disable = true;//close entre exit to port
			Locations[FindLocation("Turks_poker_room")].reload.l1.disable = true;//close cardroom exit to entre
			Locations[FindLocation("Turks_poker_entre")].reload.l3.disable = 0;	//open to cardroom
			AddDialogExitQuest("Competition_Day_One_Start2");
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Exit";
		break;
		
		case "Ronnie speaks":
			PlaySound("VOICE\ENGLISH\pir_capR10.wav");
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Ronnie speaks2";
		break;
		
		case "Ronnie speaks2":
			PlaySound("VOICE\ENGLISH\blaze_1.wav");
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Gambling";
			Locations[FindLocation("Turks_poker_room")].reload.l1.disable = false;//open cardroom exit to entre
			Locations[FindLocation("Turks_poker_entre")].reload.l3.disable = true;//close cardroom
			Locations[FindLocation("Turks_poker_entre")].reload.l1.disable = false;//open entre exit to port
			
		break;
		
		case "Gambling":
		PChar.quest.friend_in_tavern = characterFromID("Gambler 1");
			ChangeCharacterAddressGroup(pchar, "Turks_poker_room", "sit", "sit1");
		
			DialogExit();
			sld = &characters[GetCharacterIndex("Gambler 1")];
						
			ChangeCharacterAddressGroup(characterFromID("Ron_L"), "Turks_poker_room", "goto", "goto7");
			ChangeCharacterAddressGroup(characterFromID("Reg_L"), "Turks_poker_room", "goto", "goto15");
			
			
			LAi_SetPlayerType(Pchar);
			LaunchGambling(sld, "Poker");
		break;
			
		case "Day one end":
			PlaySound("VOICE\ENGLISH\Eden_time_go.wav");
			AddDialogExitQuest("Competition_Day_One_Timer");
			
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Exit";
		break;
		
		case "Day two":
			PlaySound("VOICE\ENGLISH\blaze_2.wav");
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Gambling1";
			Locations[FindLocation("Turks_poker_room")].reload.l1.disable = false;//open exit to entre
			Locations[FindLocation("Turks_poker_entre")].reload.l3.disable = true;//close cardroom
		break;
		
		case "Gambling1":
		PChar.quest.friend_in_tavern = characterFromID("Gambler 2");
		
			
			ChangeCharacterAddressGroup(pchar, "Turks_poker_room", "sit", "sit1");
		
			
			sld = &characters[GetCharacterIndex("Gambler 2")];
			ChangeCharacterAddressGroup(characterFromID("Ron_L"), "Turks_poker_room", "goto", "goto5");
			ChangeCharacterAddressGroup(characterFromID("Reg_L"), "Turks_poker_room", "goto", "goto15");
			deleteAttribute(Pchar, "quest.Day_Expired");
			deleteAttribute(Pchar, "quest.Day_Noreturn");
			Characters[GetCharacterIndex("Reg_L")].dialog.CurrentNode  = "Day two end";
			
			LAi_SetPlayerType(Pchar);
			DialogExit();
			
			LaunchGambling(sld, "Poker");	
		
		break;
		
		case "Day two end":
			PlaySound("VOICE\ENGLISH\Eden_time_go.wav");
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit"; 
			AddDialogExitQuest("Competition_Day_Two_Timer");//dialog exit 1 day timer
	
		break;
		
		case "Day three":
			PlaySound("VOICE\ENGLISH\blaze_3.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Gambling2";
			Locations[FindLocation("Turks_poker_room")].reload.l1.disable = false;//open exit to entre
			Locations[FindLocation("Turks_poker_entre")].reload.l3.disable = true;//close cardroom
		break;
		
		case "Gambling2":
			PChar.quest.friend_in_tavern = characterFromID("Gambler 3");		

			ChangeCharacterAddressGroup(pchar, "Turks_poker_room", "sit", "sit1");		

			sld = &characters[GetCharacterIndex("Gambler 3")];
			ChangeCharacterAddressGroup(characterFromID("Ron_L"), "Turks_poker_room", "goto", "goto14");
			ChangeCharacterAddressGroup(characterFromID("Reg_L"), "Turks_poker_room", "goto", "goto15");
			deleteAttribute(Pchar, "quest.Day_Expired");
			deleteAttribute(Pchar, "quest.Day_Noreturn");
			GiveItem2Character(characterFromID("Ron_L"), "bladetrophy");//PW set Ron with trophy to present
			EquipCharacterByItem(characterFromID("Ron_L"), "bladetrophy");
			Characters[GetCharacterIndex("Reg_L")].dialog.CurrentNode  = "Day Three End";

			LAi_SetPlayerType(Pchar);
			DialogExit();

			LaunchGambling(sld, "Poker");	
		break;
		
		case "Day three end":
			AddDialogExitQuest("Competition Winner");
			if (Pchar.quest.poker.winner == "Blaze")
			{
				PlaySound("VOICE\ENGLISH\pir_capR2.wav");
				dialog.text = DLG_TEXT[24];
			}
			else
			{
				PlaySound("VOICE\ENGLISH\pir_capA.wav");
				dialog.text = DLG_TEXT[37];	
			}
		
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Exit";
			Lai_ActorRunToLocator(pchar, "goto", "goto18", "", 3);//pw was 17
		break;
		
		case "Day three presentation":
			PlaySound("VOICE\ENGLISH\pir_capR10.wav");
			if (Pchar.quest.poker.winner == "Blaze")dialog.text = DLG_TEXT[38] + " " + DLG_TEXT[26];
			else dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Exit";
			LAi_SetPlayerType(Pchar);
			AddDialogExitQuest("Competition_New_Comp_Timer");
			
		break;
		
		case "Exit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

		break;
	}
}
