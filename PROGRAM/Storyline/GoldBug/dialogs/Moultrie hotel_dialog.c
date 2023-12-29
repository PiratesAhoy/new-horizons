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
	int iTest, NPC_Meeting;
	
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------|иалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\FRCO\FRCO001";
			dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1];
			link.l1 = pcharrepphrase(DLG_TEXT[2] + GetMyFullName(PChar) + DLG_TEXT[3], DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[5]);
			link.l1.go = "second time";
		
			Diag.TempNode = "second time";
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
			
			dialog.snd = "Voice\FRCO\FRCO002";
			dialog.text = DLG_TEXT[6];
		
			if(CheckAttribute(Pchar,"quest.Jupiter_paper_mission") && Pchar.quest.Jupiter_paper_mission == "on")
			{
				if(!CheckCharacterItem(Pchar,"key21"))
				{
					link.l1 = DLG_TEXT[49];
					link.l1.go = "papers";
				}
			}	
			if(CheckAttribute(Pchar,"quest.Jupiter_paper_mission") && Pchar.quest.Jupiter_paper_mission == "off")
			{
				if(Pchar.model == "William Legrand") 	link.l3 = DLG_TEXT[10];
				if(Pchar.model == "Jupiter") 		link.l3 = DLG_TEXT[11];
				link.l3.go = "room";
			}
			link.l5 = DLG_TEXT[60];
			link.l5.go = "exit";
		break;

		case "papers":
			dialog.snd = "Voice\FRCO\FRCO003";
			dialog.text = DLG_TEXT[50];

			if(CheckCharacterItem(Pchar,"bladefish"))
			{
				if(!IsEquipCharacterByItem(Pchar, "bladefish"))
				{
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "bladefish");
				}

				link.l1 = DLG_TEXT[51];
				link.l1.go = "papers1";
			}
			else
			{
				if(CheckCharacterItem(Pchar,"bladebottle_CB2"))
				{
					if(!IsEquipCharacterByItem(Pchar, "bladebottle_CB2"))
					{
						RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
						EquipCharacterByItem(Pchar, "bladebottle_CB2");
					}

					link.l1 = DLG_TEXT[53];
					link.l1.go = "papers1";
				}
			}
			else
			{
				if(CheckCharacterItem(Pchar,"pistolbedlinen"))
				{
					if(!IsEquipCharacterByItem(Pchar, "pistolbedlinen"))
					{
						RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
						EquipCharacterByItem(Pchar, "pistolbedlinen");
					}

					link.l1 = DLG_TEXT[55];
					link.l1.go = "linen";
				}
			}
			else
			{
				link.l1 = DLG_TEXT[28];
				link.l1.go = "exit";
			}
		break;

		case "papers1":
			dialog.snd = "Voice\FRCO\FRCO003";
			if(CheckCharacterItem(Pchar,"bladefish"))
			{
				dialog.text = DLG_TEXT[52];
			}

			if(CheckCharacterItem(Pchar,"bladebottle_CB2"))
			{
				dialog.text = DLG_TEXT[54];
			}

			link.l99 = DLG_TEXT[12];
			link.l99.go = "exit";
			AddDialogExitQuest("paper_linen_info");
		break;

		case "linen":
			dialog.snd = "Voice\FRCO\FRCO003";
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "linen2";
		break;

		case "linen2":
			dialog.snd = "Voice\FRCO\FRCO003";
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			AddDialogExitQuest("linen_sold");
		break;

		case "key":
			dialog.snd = "Voice\FRCO\FRCO003";
			GiveItem2Character(Pchar, "key21");
			PlaySound("INTERFACE\took_item.flac");
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "exit";
			AddDialogExitQuest("room_key");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "room":
			dialog.snd = "Voice\FRCO\FRCO018";
			dialog.text = DLG_TEXT[21];
			string roomWait = "";
			if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 10.0)
			{
				roomWait = "eveningwait";
				link.l1 = DLG_TEXT[22];
				link.l1.go = "room_day";
			}
			else
			{
				roomWait = "daywait";
				link.l1 = DLG_TEXT[23];
				link.l1.go = "room_night";
			}
			link.l2 = XI_ConvertString("Until tomorrow") + " " + XI_ConvertString(roomWait) + ".";
			link.l2.go = "room_24";
		break;

		case "room_day":
			dialog.snd = "Voice\FRCO\FRCO019";
			Dialog.text = DLG_TEXT[24];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[25];
				link.l1.go = "room_day_wait";
			}
			if(Pchar.model == "William Legrand") 	link.l2 = DLG_TEXT[26];
			if(Pchar.model == "Jupiter") 		link.l2 = DLG_TEXT[27];
			link.l2.go = "hall_day_wait";
			link.l3 = DLG_TEXT[28];
			link.l3.go = "exit";
		break;

		case "room_night":
			dialog.snd = "Voice\FRCO\FRCO019";
			Dialog.text = DLG_TEXT[29];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[30];
				link.l1.go = "room_night_wait";
			}
			if(Pchar.model == "William Legrand") 	link.l2 = DLG_TEXT[31];
			if(Pchar.model == "Jupiter") 		link.l2 = DLG_TEXT[32];
			link.l2.go = "hall_night_wait";
			link.l3 = DLG_TEXT[33];
			link.l3.go = "exit";
		break;

		case "room_24":
			dialog.snd = "Voice\ANLE\ANLE014";
			Dialog.text = DLG_TEXT[29];
			if (makeint(pchar.money) >= 5)
			{
				link.l1 = DLG_TEXT[30];
				link.l1.go = "room_24_wait";
			}
			if(Pchar.model == "William Legrand") 	link.l2 = DLG_TEXT[31];
			if(Pchar.model == "Jupiter") 		link.l2 = DLG_TEXT[32];
			link.l2.go = "hall_24_wait";
			link.l3 = DLG_TEXT[33];
			link.l3.go = "exit";
		break;

		case "room_night_wait":
			DialogExit();
			Diag.CurrentNode =  Diag.TempNode;
			AddMoneyToCharacter(pchar, -5);
			DoQuestReloadToLocation("Moultrie_hotel_room2", "goto", "sleep", "restore_hp_Moultrie");
			AddDialogExitQuest("lock_room2");
			TavernWaitDate2("wait_night");
		break;

		case "hall_night_wait":
			DialogExit();
			Diag.CurrentNode =  Diag.TempNode;
			TavernWaitDate("wait_night");
		break;

		case "room_day_wait":
			DialogExit();
			Diag.CurrentNode =  Diag.TempNode;
			AddMoneyToCharacter(pchar, -5);
			DoQuestReloadToLocation("Moultrie_hotel_room2", "goto", "sleep", "restore_hp_Moultrie");
			AddDialogExitQuest("lock_room2");
			TavernWaitDate2("wait_day");
		break;

		case "hall_day_wait":
			DialogExit();
			Diag.CurrentNode =  Diag.TempNode;
			TavernWaitDate("wait_day");
		break;

		case "room_24_wait":
			DialogExit();
			Diag.CurrentNode =  Diag.TempNode;
			AddMoneyToCharacter(pchar, -5);
			DoQuestReloadToLocation("Moultrie_hotel_room2", "goto", "sleep", "restore_hp_Moultrie");
			AddDialogExitQuest("lock_room2");
			WaitDate("",0,0,0,24,1);
			RecalculateJumpTable();
		break;

		case "hall_24_wait":
			DialogExit();
			Diag.CurrentNode =  Diag.TempNode;
			LAi_Fade("", "");
			WaitDate("",0,0,0,24,1);
			RecalculateJumpTable();
		break;

		case "tavern_keeper":
			Diag.TempNode = "second time";
			
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\FRCO\FRCO020";
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit_sit";
		break;

		case "exit_sit":
			Diag.CurrentNode = Diag.TempNode;
			//NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			AddDialogExitQuest("exit_sit");
		break;
	}
}
