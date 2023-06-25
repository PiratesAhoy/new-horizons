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
		//	AddDialogExitQuest("grandma_future_plans9");
			AddDialogExitQuest("grandma_farm_sloop");
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

		case "alchemy_part2":
			PlaySound("VOICE\ENGLISH\Fre_f_a_006.wav");
			Dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "alchemy_part2_A";
		break;

		case "alchemy_part2_A":
			PlaySound("VOICE\ENGLISH\Fre_f_a_007.wav");
			Dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "alchemy_part2_B";
		break;

		case "alchemy_part2_B":
			SetModel(PChar, "Howard_Pyle", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
			RemoveCharacterEquip(Pchar, POUCH_ITEM_TYPE );
			RemoveCharacterEquip(Pchar, BELT_ITEM_TYPE );
			RemoveCharacterEquip(Pchar, EQUIP3_ITEM_TYPE );
			TakeItemFromCharacter(Pchar, "ammobag2" );
			TakeItemFromCharacter(Pchar, "pistolbelt" );
			TakeItemFromCharacter(Pchar, "BB_hatA2" );
			PlaySound("PEOPLE\clothes1.wav");

			PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
			Dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "alchemy_part2_C";
		break;

		case "alchemy_part2_C":
			PlaySound("INTERFACE\glass2.wav");
			GiveItem2Character(Pchar, "bladebottle_CV1_sc");
			GiveItem2Character(Pchar, "bladebottle_CT1_nitr");
			GiveItem2Character(Pchar, "bladebottle_BS2_LH");

			PlaySound("VOICE\ENGLISH\Fre_f_a_005.wav");
			Dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "alchemy_part2_D";
		break;

		case "alchemy_part2_D":
			PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
			Dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "exit";
			AddDialogExitQuest("Minerva_alchemy2_done");
		break;

	//---------------------------------------------------------------------------------------

		case "Minerva_Q2":
			PlaySound("VOICE\ENGLISH\Fre_f_a_006.wav");
			Dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "alchemy_Q2";
		break;

		case "alchemy_Q2":
			PlaySound("VOICE\ENGLISH\Fre_f_a_002.wav");
			Dialog.text = DLG_TEXT[57];
			
			if(GetAttribute(Pchar, "smugglers_lair") == "info")
			{
				//don't repeat this question - it's in the questbook
			}
			else
			{
				if(GetAttribute(Pchar, "newspaper3") == "read")
				{
					Pchar.smugglers_lair = "info";
					link.l0 = DLG_TEXT[96];
					link.l0.go = "smugglers_lair";
				}
			}
			link.l1 = DLG_TEXT[80];
			link.l1.go = "trismegistus";
			link.l2 = DLG_TEXT[86];
			link.l2.go = "ingredients";
			link.l3 = DLG_TEXT[98];
			link.l3.go = "sulfuric_acid";
			link.l4 = DLG_TEXT[58];
			link.l4.go = "crucible";
			link.l5 = DLG_TEXT[63];
			link.l5.go = "grinding";
			link.l6 = DLG_TEXT[64];
			link.l6.go = "filtration";
			link.l7 = DLG_TEXT[90];
			link.l7.go = "mixing";
			link.l8 = DLG_TEXT[92];
			link.l8.go = "secret";
			link.l9 = DLG_TEXT[94];
			link.l9.go = "advice";
			link.l10 = DLG_TEXT[88];
			link.l10.go = "exit";
			Diag.TempNode = "alchemy_Q2";
		break;

		case "smugglers_lair":
			PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
			Dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			Diag.TempNode = "alchemy_Q2";
			AddQuestRecord("Blackbeards_crew", "4");
		break;

		case "secret":
			PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
			Dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			Diag.TempNode = "alchemy_Q2";
		break;

		case "trismegistus":
			PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
			Dialog.text = DLG_TEXT[81];
			if(CheckCharacterItem(Pchar,"book70_start") || CheckCharacterItem(Pchar,"book70") || CheckCharacterItem(Pchar,"book70_0")
			|| CheckCharacterItem(Pchar,"book70_2") || CheckCharacterItem(Pchar,"book70_4") || CheckCharacterItem(Pchar,"book70_6")
			|| CheckCharacterItem(Pchar,"book70_8") || CheckCharacterItem(Pchar,"book70_10"))
			{
				link.l1 = DLG_TEXT[69];
				link.l1.go = "exit";
			}
			else
			{
				link.l2 = DLG_TEXT[82];
				link.l2.go = "trismegistus_search";
			}
			Diag.TempNode = "alchemy_Q2";
		break;

		case "trismegistus_search":
			PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
			Dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			Diag.TempNode = "alchemy_Q2";
		break;

		case "ingredients":
			PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
			Dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			Diag.TempNode = "alchemy_Q2";
		break;

		case "sulfuric_acid":
			PlaySound("VOICE\ENGLISH\Fre_f_a_005.wav");
			Dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			Diag.TempNode = "alchemy_Q2";
		break;

		case "crucible":
			PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
			Dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "crucible_fill";
			link.l2 = DLG_TEXT[65];
			link.l2.go = "crucible_firewood";
			link.l3 = DLG_TEXT[66];
			link.l3.go = "crucible_wheel";
			link.l4 = DLG_TEXT[67];
			link.l4.go = "crucible_receiver";
			Diag.TempNode = "alchemy_Q2";
		break;

		case "crucible_fill":
			PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
			Dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			Diag.TempNode = "alchemy_Q2";
		break;

		case "crucible_firewood":
			PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
			Dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";

			if(CheckCharacterItem(Pchar,"book70_start") || CheckCharacterItem(Pchar,"book70") || CheckCharacterItem(Pchar,"book70_0")
			|| CheckCharacterItem(Pchar,"book70_2") || CheckCharacterItem(Pchar,"book70_4") || CheckCharacterItem(Pchar,"book70_6")
			|| CheckCharacterItem(Pchar,"book70_8") || CheckCharacterItem(Pchar,"book70_10"))
			{

			}
			else
			{
				link.l2 = DLG_TEXT[89];
				link.l2.go = "firewood_book";
			}
			Diag.TempNode = "alchemy_Q2";
		break;

		case "firewood_book":
			PlaySound("VOICE\ENGLISH\Fre_f_a_007.wav");
			Dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			Diag.TempNode = "alchemy_Q2";
		break;

		case "crucible_wheel":
			PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
			Dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			Diag.TempNode = "alchemy_Q2";
		break;

		case "crucible_receiver":
			PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
			Dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[84];
			link.l2.go = "crucible_funnel";
			Diag.TempNode = "alchemy_Q2";
		break;

		case "crucible_funnel":
			PlaySound("VOICE\ENGLISH\Fre_f_a_007.wav");
			Dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			Diag.TempNode = "alchemy_Q2";
		break;

		case "grinding":
			PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
			Dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "grinding_fill";
			link.l2 = DLG_TEXT[74];
			link.l2.go = "grinding_crank";
			link.l3 = DLG_TEXT[75];
			link.l3.go = "grinding_receiver";
		break;

		case "grinding_fill":
			PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
			Dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			Diag.TempNode = "alchemy_Q2";
		break;

		case "grinding_crank":
			PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
			Dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			Diag.TempNode = "alchemy_Q2";
		break;

		case "grinding_receiver":
			PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
			Dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			Diag.TempNode = "alchemy_Q2";
		break;

		case "filtration":
			PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
			Dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[84];
			link.l2.go = "filtration_filter";
			Diag.TempNode = "alchemy_Q2";
		break;

		case "filtration_filter":
			PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
			Dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			Diag.TempNode = "alchemy_Q2";
		break;

		case "mixing":
			PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
			Dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			Diag.TempNode = "alchemy_Q2";
		break;

		case "secret":
			PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
			Dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			Diag.TempNode = "alchemy_Q2";
		break;

		case "advice":
			PlaySound("VOICE\ENGLISH\Fre_f_a_003.wav");
			Dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			Diag.TempNode = "alchemy_Q2";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
