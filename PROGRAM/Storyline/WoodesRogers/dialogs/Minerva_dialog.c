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
	ref lcn = &Locations[FindLocation(PChar.location)];
	
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
	
			PlaySound("VOICE\ENGLISH\Fre_f_a_002.wav");	

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			if(CheckAttribute(Pchar, "quest.distillery_items") && Pchar.quest.distillery_items == "open")
			{
				if(CheckAttribute(Pchar, "quest.apparatus_hint") && Pchar.quest.apparatus_hint == "yes")
				{
					link.l2 = DLG_TEXT[2];
					link.l2.go = "apparatus";
				}
				
				if(CheckAttribute(Pchar, "quest.process_hint") && Pchar.quest.process_hint == "yes")
				{
					link.l3 = DLG_TEXT[3];
					link.l3.go = "process";
				}
			}

			if(CheckAttribute(Pchar, "quest.Minerva_copper") && Pchar.quest.Minerva_copper == "info")
			{
				link.l4 = DLG_TEXT[4];
				link.l4.go = "solve_copper";
			}

			if(CheckAttribute(Pchar, "quest.Minerva_silver") && Pchar.quest.Minerva_silver == "info")
			{
				link.l5 = DLG_TEXT[17];
				link.l5.go = "solve_silver";
			}
		
			if(CheckAttribute(Pchar, "quest.Minerva_gold") && Pchar.quest.Minerva_gold == "info")
			{
				link.l6 = DLG_TEXT[21];
				link.l6.go = "solve_gold";
			}
		
			Diag.TempNode = "first time";
		break;

		case "apparatus":
			if(CheckAttribute(Pchar,"quest.qbook_apparatus_items") && Pchar.quest.qbook_apparatus_items == "done")
			{
					
			}
			else
			{
				Pchar.quest.qbook_apparatus_items = "done";				
				AddQuestRecord("Alchemy_apparatus", "3");
			}

			PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
			Dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
		break;

		case "process":
			if(CheckAttribute(Pchar,"quest.qbook_process_picture") && Pchar.quest.qbook_process_picture == "done")
			{
					
			}
			else
			{
				Pchar.quest.qbook_process_picture = "done";				
				AddQuestRecord("Alchemy_tutorial", "2");
			}

			PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
			Dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "exit";
		break;

		case "solve_copper":
			if(CheckCharacterItem(Pchar,"book48"))
			{
				if(CheckCharacterItem(Pchar,"book45") && CheckCharacterItem(Pchar,"book42"))
				{
					if(CheckCharacterItem(Pchar,"pistolcopperas"))
					{
						if(CheckCharacterItem(Pchar,"bladebottle_CT2_sulf_w"))
						{
							//done!
							PlaySound("VOICE\ENGLISH\Fre_f_a_006.wav");
							Dialog.text = DLG_TEXT[14];
							link.l1 = DLG_TEXT[15];
							link.l1.go = "exit";
						}
						else
						{
							if(CheckCharacterItem(Pchar,"bladebottle_CT1_sulf"))
							{
								//almost there
								PlaySound("VOICE\ENGLISH\Fre_f_a_005.wav");
								Dialog.text = DLG_TEXT[16];
								link.l1 = DLG_TEXT[18];
								link.l1.go = "exit";
							}
							else
							{
								//make H2SO4!
								PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
								Dialog.text = DLG_TEXT[19];
								link.l1 = DLG_TEXT[25];
								link.l1.go = "exit";
							}
						}
					}
					else
					{
						PlaySound("VOICE\ENGLISH\Fre_f_a_007.wav");
						Dialog.text = DLG_TEXT[13];
						link.l1 = DLG_TEXT[6];
						link.l1.go = "exit";				
					}
				}
				else
				{
					PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
					Dialog.text = DLG_TEXT[9];
					link.l1 = DLG_TEXT[10];
					link.l1.go = "exit";
				}
			}
			else
			{
				PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
				Dialog.text = DLG_TEXT[11];
				link.l1 = DLG_TEXT[12];
				link.l1.go = "exit";
			}
		break;

		case "solve_silver":
			if(CheckCharacterItem(Pchar,"book49") && CheckCharacterItem(Pchar,"book42"))
			{
				if(CheckCharacterItem(Pchar,"pistolnitre"))
				{
					if(CheckCharacterItem(Pchar,"bladebottle_CT2_nitr_w"))
					{
						//done!
						PlaySound("VOICE\ENGLISH\Fre_f_a_006.wav");
						Dialog.text = DLG_TEXT[14];
						link.l1 = DLG_TEXT[15];
						link.l1.go = "exit";
					}
					else
					{
						if(CheckCharacterItem(Pchar,"bladebottle_CT1_nitr"))
						{
							//almost there
							PlaySound("VOICE\ENGLISH\Fre_f_a_005.wav");
							Dialog.text = DLG_TEXT[16];
							link.l1 = DLG_TEXT[18];
							link.l1.go = "exit";
						}
						else
						{
							if(CheckCharacterItem(Pchar,"bladebottle_CT1_sulf"))
							{
								//make HNO3
								PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
								Dialog.text = DLG_TEXT[20];
								link.l1 = DLG_TEXT[25];
								link.l1.go = "exit";
							}
							else
							{
								//make H2SO4!
								PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
								Dialog.text = DLG_TEXT[19];
								link.l1 = DLG_TEXT[25];
								link.l1.go = "exit";
							}
						}
					}
				}
				else
				{
					PlaySound("VOICE\ENGLISH\Fre_f_a_007.wav");
					Dialog.text = DLG_TEXT[13];
					link.l1 = DLG_TEXT[6];
					link.l1.go = "exit";				
				}
			}
			else
			{
				PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
				Dialog.text = DLG_TEXT[9];
				link.l1 = DLG_TEXT[10];
				link.l1.go = "exit";
			}
		break;

		case "solve_gold":
			if(CheckCharacterItem(Pchar,"book49") && CheckCharacterItem(Pchar,"book42") && CheckCharacterItem(Pchar,"book47"))
			{
				if(CheckCharacterItem(Pchar,"pistolsalt"))
				{
					if(CheckCharacterItem(Pchar,"bladebottle_CA2"))
					{
						//done!
						PlaySound("VOICE\ENGLISH\Fre_f_a_006.wav");
						Dialog.text = DLG_TEXT[14];
						link.l1 = DLG_TEXT[15];
						link.l1.go = "exit";
					}
					else
					{
						if(CheckCharacterItem(Pchar,"bladebottle_CT2_hydr"))
						{						
							if(CheckCharacterItem(Pchar,"bladebottle_CT1_nitr"))
							{
								//almost there
								PlaySound("VOICE\ENGLISH\Fre_f_a_005.wav");
								Dialog.text = DLG_TEXT[16];
								link.l1 = DLG_TEXT[18];
								link.l1.go = "exit";
							}
							else
							{
								if(CheckCharacterItem(Pchar,"bladebottle_CT1_sulf"))
								{
									//make HNO3
									PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
									Dialog.text = DLG_TEXT[20];
									link.l1 = DLG_TEXT[25];
									link.l1.go = "exit";
								}
								else
								{
									//make H2SO4!
									PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
									Dialog.text = DLG_TEXT[19];
									link.l1 = DLG_TEXT[25];
									link.l1.go = "exit";
								}
							}
						}
						else
						{
							if(CheckCharacterItem(Pchar,"bladebottle_CT1_sulf"))
							{
								//make HCl!
								PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
								Dialog.text = DLG_TEXT[22];
								link.l1 = DLG_TEXT[25];
								link.l1.go = "exit";
							}
							else
							{
								//make H2SO4!
								PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
								Dialog.text = DLG_TEXT[19];
								link.l1 = DLG_TEXT[25];
								link.l1.go = "exit";
							}
						}
					}
				}
				else
				{
					PlaySound("VOICE\ENGLISH\Fre_f_a_007.wav");
					Dialog.text = DLG_TEXT[13];
					link.l1 = DLG_TEXT[6];
					link.l1.go = "exit";				
				}
			}
			else
			{
				PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
				Dialog.text = DLG_TEXT[9];
				link.l1 = DLG_TEXT[10];
				link.l1.go = "exit";
			}
		break;
	//.................................................................
		case "assemble_apparatus":
			PlaySound("VOICE\ENGLISH\Fre_f_a_004.wav");
			Dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			Diag.TempNode = "first time";
			AddDialogExitQuest("unlock_from_alchemy2");
		break;

		case "boat_is_here":
			PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
			Dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit";
			AddDialogExitQuest("boat_to_prizeships2");
		break;

		case "distill_explosion":
			PlaySound("VOICE\ENGLISH\Fre_f_a_009.wav");
			Dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "distill_explosion1";
		break;

		case "distill_explosion1":
			if(CheckAttribute(Pchar,"quest.cauldron") && Pchar.quest.cauldron == "water")
			{
				if(CheckAttribute(Pchar,"quest.retort_was_empty") && Pchar.quest.retort_was_empty == "yes")
				{
					//check 2
					PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
					Dialog.text = DLG_TEXT[39];
					link.l1 = DLG_TEXT[38];
					link.l1.go = "exit";
					AddDialogExitQuest("after_alchemy_glass_explosion");

					if(CheckAttribute(Pchar,"quest.qbook_retort") && Pchar.quest.qbook_retort == "done")
					{
					
					}
					else
					{
						Pchar.quest.qbook_retort = "done";				
						AddQuestRecord("Alchemy_tutorial", "5");
					}				
				}
				else
				{
					//check 3
					PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
					Dialog.text = DLG_TEXT[40];
					link.l1 = DLG_TEXT[6];
					link.l1.go = "exit";
					AddDialogExitQuest("after_alchemy_glass_explosion");

					if(CheckAttribute(Pchar,"quest.qbook_oxygen") && Pchar.quest.qbook_oxygen == "done")
					{
					
					}
					else
					{
						Pchar.quest.qbook_oxygen = "done";				
						AddQuestRecord("Alchemy_tutorial", "6");
					}
				}
			}
			else
			{
				//check 1
				PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
				Dialog.text = DLG_TEXT[37];
				link.l1 = DLG_TEXT[38];
				link.l1.go = "exit";
				AddDialogExitQuest("after_alchemy_glass_explosion");

				if(CheckAttribute(Pchar,"quest.qbook_cauldron") && Pchar.quest.qbook_cauldron == "done")
				{
					
				}
				else
				{
						Pchar.quest.qbook_cauldron = "done";				
						AddQuestRecord("Alchemy_apparatus", "2");
						CloseQuestHeader("Alchemy_apparatus");
				}
			}
		break;

		case "back_to_Rogers":
			PlaySound("VOICE\ENGLISH\Fre_f_a_006.wav");
			Dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "back_to_Rogers1";
		break;

		case "back_to_Rogers1":
			PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
			Dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
			AddDialogExitQuest("goodbye_Vane_Pchar5A");
		break;

		case "thanks_for_the_shop":
			PlaySound("VOICE\ENGLISH\Fre_f_a_005.wav");
			LAi_SetActorType(CharacterFromID("Minerva"));
			LAi_ActorTurnToCharacter(characterFromID("Minerva"), characterFromID("grandma"));
			Dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_future_plans9");
		break;

		case "monkey":
			PlaySound("VOICE\ENGLISH\Fre_f_a_006.wav");
			Dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_monkey15");
		break;

	//---------------------------------------------------------------------------------------	
		
		case "welcome":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto8");
			PlaySound("VOICE\ENGLISH\fre_f_a_004.wav");
			Dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "welcome1";
		break;

		case "welcome1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto8");
			PlaySound("VOICE\ENGLISH\fre_f_a_001.wav");
			Dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "welcome2";
		break;

		case "welcome2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto8");
			PlaySound("VOICE\ENGLISH\fre_f_a_009.wav");
			Dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "exit";
			Diag.TempNode = "first time";
			AddDialogExitQuest("Minerva3");
		break;

	//---------------------------------------------------------------------------------------	
	
		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
