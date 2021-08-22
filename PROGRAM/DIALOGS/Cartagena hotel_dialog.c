
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

	int iNation = GetTownNation(GetCurrentTownID()); // KK
	int Relation = GetRMRelation(PChar, iNation);
	
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
		//logit("First time");	
			switch(NPChar.id)
			{
				//was fake_seacole
				case "Dusty_Broome":
					PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "dusty_info";
				break;
			
				case "hotel_ghost2":
					PlaySound("VOICE\ENGLISH\zombie2.wav");
					
					if(CheckCharacterItem(Pchar,"hotel_surgery"))
					{
						Pchar.hotel_surgery = "on";
						TakeItemFromCharacter(Pchar, "hotel_surgery" );
						GiveItem2Character(characterFromID("hotel_ghost2"), "hotel_surgery");

						if(CheckCharacterItem(Pchar,"hotel_bandages"))
						{
							Pchar.hotel_bandages = "on";
							TakeItemFromCharacter(Pchar, "hotel_bandages" );
							GiveItem2Character(characterFromID("hotel_ghost2"), "hotel_bandages");
							Dialog.text = DLG_TEXT[66];
							link.l1 = DLG_TEXT[23];
						}
						else
						{
							Dialog.text = DLG_TEXT[64];
							link.l1 = DLG_TEXT[23];
						}

						if(CheckCharacterItem(characterFromID("hotel_ghost2"),"hotel_bandages"))
						{
							link.l1.go = "exit";
							AddDialogExitQuest("ghost2_disappears"); 
						}
						else link.l1.go = "ghost_warning";
					}
					else
					{
						if(CheckCharacterItem(Pchar,"hotel_bandages"))
						{
							Pchar.hotel_bandages = "on";
							TakeItemFromCharacter(Pchar, "hotel_bandages" );
							GiveItem2Character(characterFromID("hotel_ghost2"), "hotel_bandages");
							Dialog.text = DLG_TEXT[65];
							link.l1 = DLG_TEXT[23];

							if(CheckCharacterItem(characterFromID("hotel_ghost2"),"hotel_surgery"))
							{
								link.l1.go = "exit";
								AddDialogExitQuest("ghost2_disappears"); 
							}
							else link.l1.go = "ghost_warning";
						}
						else 
						{
							Dialog.text = DLG_TEXT[18];
							link.l1 = DLG_TEXT[19];
							link.l1.go = "ghost_warning";
						}
					} 
				break;

				case "hotel_ghost3":
					PlaySound("VOICE\ENGLISH\zombie3.wav");
					
					if(CheckCharacterItem(Pchar,"hotel_crucifix"))
					{
						Pchar.hotel_crucifix = "on";
						TakeItemFromCharacter(Pchar, "hotel_crucifix" );
						GiveItem2Character(characterFromID("hotel_ghost3"), "hotel_crucifix");

						if(CheckCharacterItem(Pchar,"hotel_bible"))
						{
							Pchar.hotel_bible = "on";
							TakeItemFromCharacter(Pchar, "hotel_bible" );
							GiveItem2Character(characterFromID("hotel_ghost3"), "hotel_bible");
							Dialog.text = DLG_TEXT[57];
							link.l1 = DLG_TEXT[23];
						}
						else
						{
							Dialog.text = DLG_TEXT[55];
							link.l1 = DLG_TEXT[23];
						}

						if(CheckCharacterItem(characterFromID("hotel_ghost3"),"hotel_bible"))
						{
							link.l1.go = "exit";
							AddDialogExitQuest("ghost3_disappears"); 
						}
						else link.l1.go = "ghost_warning";
					}
					else
					{
						if(CheckCharacterItem(Pchar,"hotel_bible"))
						{
							Pchar.hotel_bible = "on";
							TakeItemFromCharacter(Pchar, "hotel_bible" );
							GiveItem2Character(characterFromID("hotel_ghost3"), "hotel_bible");
							Dialog.text = DLG_TEXT[56];
							link.l1 = DLG_TEXT[23];

							if(CheckCharacterItem(characterFromID("hotel_ghost3"),"hotel_crucifix"))
							{
								link.l1.go = "exit";
								AddDialogExitQuest("ghost3_disappears"); 
							}
							else link.l1.go = "ghost_warning";
						}
						else 
						{
							Dialog.text = DLG_TEXT[18];
							link.l1 = DLG_TEXT[19];
							link.l1.go = "ghost_warning";
						}
					} 
				break;

				case "hotel_ghost6":
					PlaySound("VOICE\ENGLISH\zombie4.wav");
					
					if(CheckCharacterItem(Pchar,"hotel_megaphone"))
					{
						Pchar.hotel_megaphone = "on";
						TakeItemFromCharacter(Pchar, "hotel_megaphone" );
						GiveItem2Character(characterFromID("hotel_ghost6"), "hotel_megaphone");

						if(CheckCharacterItem(Pchar,"hotel_spyglass"))
						{
							Pchar.hotel_spyglass = "on";
							TakeItemFromCharacter(Pchar, "hotel_spyglass" );
							GiveItem2Character(characterFromID("hotel_ghost6"), "hotel_spyglass");
							Dialog.text = DLG_TEXT[63];
							link.l1 = DLG_TEXT[23];
						}
						else
						{
							Dialog.text = DLG_TEXT[62];
							link.l1 = DLG_TEXT[23];
						}

						if(CheckCharacterItem(characterFromID("hotel_ghost6"),"hotel_spyglass"))
						{
							link.l1.go = "exit";
							AddDialogExitQuest("ghost6_disappears"); 
						}
						else link.l1.go = "ghost_warning";
					}
					else
					{
						if(CheckCharacterItem(Pchar,"hotel_spyglass"))
						{
							Pchar.hotel_spyglass = "on";
							TakeItemFromCharacter(Pchar, "hotel_spyglass" );
							GiveItem2Character(characterFromID("hotel_ghost6"), "hotel_spyglass");
							Dialog.text = DLG_TEXT[61];
							link.l1 = DLG_TEXT[23];

							if(CheckCharacterItem(characterFromID("hotel_ghost6"),"hotel_megaphone"))
							{
								link.l1.go = "exit";
								AddDialogExitQuest("ghost6_disappears"); 
							}
							else link.l1.go = "ghost_warning";
						}
						else 
						{
							Dialog.text = DLG_TEXT[18];
							link.l1 = DLG_TEXT[19];
							link.l1.go = "ghost_warning";
						}
					} 
				break;

				case "hotel_ghost7":
					PlaySound("VOICE\ENGLISH\zombie5.wav");
					
					if(CheckCharacterItem(Pchar,"hotel_whistle"))
					{
						Pchar.hotel_whistle = "on";
						TakeItemFromCharacter(Pchar, "hotel_whistle" );
						GiveItem2Character(characterFromID("hotel_ghost7"), "hotel_whistle");

						if(CheckCharacterItem(Pchar,"hotel_grappling"))
						{
							Pchar.hotel_grappling = "on";
							TakeItemFromCharacter(Pchar, "hotel_grappling" );
							GiveItem2Character(characterFromID("hotel_ghost7"), "hotel_grappling");
							Dialog.text = DLG_TEXT[54];
							link.l1 = DLG_TEXT[23];
						}
						else
						{
							Dialog.text = DLG_TEXT[53];
							link.l1 = DLG_TEXT[23];
						}

						LAi_SetActorType(Pchar);
						LAi_ActorTurnToLocator(Pchar, "barmen", "bar2");
					
						if(CheckCharacterItem(characterFromID("hotel_ghost7"),"hotel_grappling"))
						{
							link.l1.go = "exit";
							AddDialogExitQuest("ghost7_disappears"); 
						}
						else link.l1.go = "ghost_warning";
					}
					else
					{
						if(CheckCharacterItem(Pchar,"hotel_grappling"))
						{
							Pchar.hotel_grappling = "on";
							TakeItemFromCharacter(Pchar, "hotel_grappling" );
							GiveItem2Character(characterFromID("hotel_ghost7"), "hotel_grappling");

							LAi_SetActorType(Pchar);
							LAi_ActorTurnToLocator(Pchar, "barmen", "bar2");
							Dialog.text = DLG_TEXT[52];
							link.l1 = DLG_TEXT[23];

							if(CheckCharacterItem(characterFromID("hotel_ghost7"),"hotel_whistle"))
							{
								link.l1.go = "exit";
								AddDialogExitQuest("ghost7_disappears"); 
							}
							else link.l1.go = "ghost_warning";
						}
						else 
						{
							Dialog.text = DLG_TEXT[18];
							link.l1 = DLG_TEXT[19];
							link.l1.go = "ghost_warning";
						}
					} 
				break;

				case "hotel_ghost8":
					PlaySound("VOICE\ENGLISH\zombie6.wav");
					
					if(CheckCharacterItem(Pchar,"hotel_sextant"))
					{
						Pchar.hotel_sextant = "on";
						TakeItemFromCharacter(Pchar, "hotel_sextant" );
						GiveItem2Character(characterFromID("hotel_ghost8"), "hotel_sextant");

						if(CheckCharacterItem(Pchar,"hotel_drawing"))
						{
							Pchar.hotel_drawing = "on";
							TakeItemFromCharacter(Pchar, "hotel_drawing" );
							GiveItem2Character(characterFromID("hotel_ghost8"), "hotel_drawing");
							Dialog.text = DLG_TEXT[60];
							link.l1 = DLG_TEXT[23];
						}
						else
						{
							Dialog.text = DLG_TEXT[58];
							link.l1 = DLG_TEXT[23];
						}

						if(CheckCharacterItem(characterFromID("hotel_ghost8"),"hotel_drawing"))
						{
							link.l1.go = "exit";
							AddDialogExitQuest("ghost8_disappears"); 
						}
						else link.l1.go = "ghost_warning";
					}
					else
					{
						if(CheckCharacterItem(Pchar,"hotel_drawing"))
						{
							Pchar.hotel_drawing = "on";
							TakeItemFromCharacter(Pchar, "hotel_drawing" );
							GiveItem2Character(characterFromID("hotel_ghost8"), "hotel_drawing");
							Dialog.text = DLG_TEXT[59];
							link.l1 = DLG_TEXT[23];

							if(CheckCharacterItem(characterFromID("hotel_ghost8"),"hotel_sextant"))
							{
								link.l1.go = "exit";
								AddDialogExitQuest("ghost8_disappears"); 
							}
							else link.l1.go = "ghost_warning";
						}
						else 
						{
							Dialog.text = DLG_TEXT[18];
							link.l1 = DLG_TEXT[19];
							link.l1.go = "ghost_warning";
						}
					} 
				break;

			}
		break;

		case "dusty_info":
			PlaySound("VOICE\ENGLISH\Fre_m_a_001.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "dusty_info1";
		break;

		case "dusty_info1":
			PlaySound("VOICE\ENGLISH\Fre_m_a_002.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "dusty_info2";
		break;

		case "dusty_info2":
			PlaySound("VOICE\ENGLISH\Fre_m_a_018.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "dusty_info3";
		break;

		case "dusty_info3":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead0.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "dusty_info4";
		break;

		case "dusty_info4":
			PlaySound("VOICE\ENGLISH\Fre_m_a_003.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "dusty_info5";
		break;

		case "dusty_info5":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			Dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
			AddDialogExitQuest("dusty_info_ghosts"); 
		break;

		case "dusty_repeat":
			PlaySound("VOICE\ENGLISH\Fre_m_a_007.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			Diag.TempNode = "dusty_repeat";
		break;

	//-------------------------------------------------------------

		case "dusty_ghosts_gone":
			PlaySound("VOICE\ENGLISH\Fre_m_a_007.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "dusty_ghosts_gone1";
		break;

		case "dusty_ghosts_gone1":
			PlaySound("VOICE\ENGLISH\Fre_m_a_072.wav");
			Dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "dusty_ghosts_gone2";
		break;

		case "dusty_ghosts_gone2":
			PlaySound("VOICE\ENGLISH\Fre_m_a_073.wav");
			Dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "dusty_ghosts_gone3";
		break;

		case "dusty_ghosts_gone3":
			PlaySound("VOICE\ENGLISH\Fre_m_a_075.wav");
			Dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "dusty_ghosts_gone4";
		break;

		case "dusty_ghosts_gone4":
			PlaySound("VOICE\ENGLISH\Fre_m_a_001.wav");
			Dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "dusty_ghosts_gone5";
		break;

		case "dusty_ghosts_gone5":
			PlaySound("VOICE\ENGLISH\Fre_m_a_008.wav");
			Dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
			AddDialogExitQuest("dusty_reset"); 
		break;

		case "dusty_reset":
			PlaySound("VOICE\ENGLISH\Fre_m_a_003.wav");
			Dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "exit";
			Diag.TempNode = "dusty_reset";
		break;

		case "dusty_plants":
			PlaySound("VOICE\ENGLISH\Fre_m_a_020.wav");
			Dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "exit";
			AddDialogExitQuest("plants_from_dusty"); 
		break;

		case "dusty_leaving":
			PlaySound("VOICE\ENGLISH\Fre_m_a_004.wav");
			Dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "exit";
			AddDialogExitQuest("dusty_feel_free"); 
		break;

		case "ghost_warning":	
	//logit("ghost_warning");	
			
			switch(NPChar.id)
			{
				case "hotel_ghost2":
					LAi_SetStayType(characterFromID("hotel_ghost2"));

					if(CheckAttribute(Pchar,"hotel_surgery") && Pchar.hotel_surgery == "on") 
					{PlaySound("INTERFACE\small_door_locked.wav");}

					if(CheckAttribute(Pchar,"hotel_bandages") && Pchar.hotel_bandages == "on") 
					{PlaySound("PEOPLE\clothes1.wav");}
										
					pchar.quest.ghost2_restart.win_condition.l1 = "ExitFromLocation";
					pchar.quest.ghost2_restart.win_condition.l1.location = "Cartagena_hotel_office";
					pchar.quest.ghost2_restart.win_condition = "ghost2_restart";
				break;

				case "hotel_ghost3":
					LAi_SetStayType(characterFromID("hotel_ghost3"));

					if(CheckAttribute(Pchar,"hotel_crucifix") && Pchar.hotel_crucifix == "on") 
					{PlaySound("INTERFACE\took_item.wav");}

					if(CheckAttribute(Pchar,"hotel_bible") && Pchar.hotel_bible == "on") 
					{PlaySound("INTERFACE\book_close.wav");}
					
					pchar.quest.ghost3_restart.win_condition.l1 = "ExitFromLocation";
					pchar.quest.ghost3_restart.win_condition.l1.location = "Cartagena_hotel_room1";
					pchar.quest.ghost3_restart.win_condition = "ghost3_restart";
				break;

				case "hotel_ghost6":
					LAi_SetStayType(characterFromID("hotel_ghost6"));
					
					if(CheckAttribute(Pchar,"hotel_spyglass") && Pchar.hotel_spyglass == "on") 
					{PlaySound("PEOPLE\spyglass.wav");}

					if(CheckAttribute(Pchar,"hotel_megaphone") && Pchar.hotel_megaphone == "on") 
					{PlaySound("OBJECTS\SHIPCHARGE\CannonReload-002.wav");}
			
					pchar.quest.ghost6_restart.win_condition.l1 = "ExitFromLocation";
					pchar.quest.ghost6_restart.win_condition.l1.location = "Cartagena_hotel_room2";
					pchar.quest.ghost6_restart.win_condition = "ghost6_restart";
				break;

				case "hotel_ghost7":
					LAi_SetPlayerType(Pchar);
					LAi_SetStayType(characterFromID("hotel_ghost7"));
					
					if(CheckAttribute(Pchar,"hotel_whistle") && Pchar.hotel_whistle == "on") 
					{PlaySound("OBJECTS\SHIPCHARGE\whistle_the_side.wav");}

					if(CheckAttribute(Pchar,"hotel_grappling") && Pchar.hotel_grappling == "on") 
					{PlaySound("PEOPLE\blade_kling.wav");}

					pchar.quest.ghost7_restart.win_condition.l1 = "ExitFromLocation";
					pchar.quest.ghost7_restart.win_condition.l1.location = "Cartagena_hotel_room3";
					pchar.quest.ghost7_restart.win_condition = "ghost7_restart";
				break;

				case "hotel_ghost8":
					LAi_SetStayType(characterFromID("hotel_ghost8"));
					
					if(CheckAttribute(Pchar,"hotel_sextant") && Pchar.hotel_sextant == "on") 
					{PlaySound("INTERFACE\pinion_take.wav");}

					if(CheckAttribute(Pchar,"hotel_drawing") && Pchar.hotel_drawing == "on") 
					{PlaySound("INTERFACE\collection_box.wav");}

					pchar.quest.ghost8_restart.win_condition.l1 = "ExitFromLocation";
					pchar.quest.ghost8_restart.win_condition.l1.location = "Cartagena_hotel_room4";
					pchar.quest.ghost8_restart.win_condition = "ghost8_restart";
				break;
			}

			Pchar.hotel_surgery = "off";
			Pchar.hotel_bandages = "off";
			Pchar.hotel_crucifix = "off";
			Pchar.hotel_bible = "off";
			Pchar.hotel_spyglass = "off";
			Pchar.hotel_megaphone = "off";
			Pchar.hotel_grappling = "off";
			Pchar.hotel_whistle = "off";
			Pchar.hotel_sextant = "off";
			Pchar.hotel_drawing = "off";

			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			if(NPchar.id == "hotel_ghost2") AddDialogExitQuest("ghost2_sittype"); 
		break;

		case "deliver_or_die":
	//logit("deliver_or_die");
			switch(NPChar.id)
			{
				case "hotel_ghost2":
					if(CheckCharacterItem(Pchar,"hotel_surgery"))
					{
						PlaySound("VOICE\ENGLISH\zombie2.wav");

						Pchar.hotel_surgery = "on";
						TakeItemFromCharacter(Pchar, "hotel_surgery" );
						GiveItem2Character(characterFromID("hotel_ghost2"), "hotel_surgery");

						if(CheckCharacterItem(Pchar,"hotel_bandages"))
						{
							Pchar.hotel_bandages = "on";
							TakeItemFromCharacter(Pchar, "hotel_bandages" );
							GiveItem2Character(characterFromID("hotel_ghost2"), "hotel_bandages");
							Dialog.text = DLG_TEXT[66];
							link.l1 = DLG_TEXT[23];
						}
						else
						{
							Dialog.text = DLG_TEXT[64];
							link.l1 = DLG_TEXT[23];
						}

						if(CheckCharacterItem(characterFromID("hotel_ghost2"),"hotel_bandages"))
						{
							link.l1.go = "exit";
							AddDialogExitQuest("ghost2_disappears"); 
						}
						else link.l1.go = "ghost_warning";
					}
					else
					{
						if(CheckCharacterItem(Pchar,"hotel_bandages"))
						{
							PlaySound("VOICE\ENGLISH\zombie2.wav");

							Pchar.hotel_bandages = "on";
							TakeItemFromCharacter(Pchar, "hotel_bandages" );
							GiveItem2Character(characterFromID("hotel_ghost2"), "hotel_bandages");
							Dialog.text = DLG_TEXT[65];
							link.l1 = DLG_TEXT[23];

							if(CheckCharacterItem(characterFromID("hotel_ghost2"),"hotel_surgery"))
							{
								link.l1.go = "exit";
								AddDialogExitQuest("ghost2_disappears"); 
							}
							else link.l1.go = "ghost_warning";
						}
						else 
						{
							DialogExit();
							Diag.CurrentNode = Diag.TempNode;

							PlaySound("VOICE\ENGLISH\zombie_die.wav");
							LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_hotel_office")], false);
							LAi_SetActorType(characterFromID("hotel_ghost2"));
							LAi_ActorAttack(CharacterFromID("hotel_ghost2"), Pchar, "");
							ChangeCharacterAddressGroup(characterFromID("hotel_ghost2"), "Cartagena_hotel_office", "goto", "goto5");

							pchar.quest.ghost2_restart.win_condition.l1 = "ExitFromLocation";
							pchar.quest.ghost2_restart.win_condition.l1.location = "Cartagena_hotel_office";
							pchar.quest.ghost2_restart.win_condition = "ghost2_restart";
						}
					} 
				break;

				case "hotel_ghost3":
					if(CheckCharacterItem(Pchar,"hotel_crucifix"))
					{
						PlaySound("VOICE\ENGLISH\zombie3.wav");

						Pchar.hotel_crucifix = "on";
						TakeItemFromCharacter(Pchar, "hotel_crucifix" );
						GiveItem2Character(characterFromID("hotel_ghost3"), "hotel_crucifix");

						if(CheckCharacterItem(Pchar,"hotel_bible"))
						{
							Pchar.hotel_bible = "on";
							TakeItemFromCharacter(Pchar, "hotel_bible" );
							GiveItem2Character(characterFromID("hotel_ghost3"), "hotel_bible");
							Dialog.text = DLG_TEXT[57];
							link.l1 = DLG_TEXT[23];
						}
						else
						{
							Dialog.text = DLG_TEXT[55];
							link.l1 = DLG_TEXT[23];
						}

						if(CheckCharacterItem(characterFromID("hotel_ghost3"),"hotel_bible"))
						{
							link.l1.go = "exit";
							AddDialogExitQuest("ghost3_disappears"); 
						}
						else link.l1.go = "ghost_warning";
					}
					else
					{
						if(CheckCharacterItem(Pchar,"hotel_bible"))
						{
							PlaySound("VOICE\ENGLISH\zombie3.wav");

							Pchar.hotel_bible = "on";
							TakeItemFromCharacter(Pchar, "hotel_bible" );
							GiveItem2Character(characterFromID("hotel_ghost3"), "hotel_bible");
							Dialog.text = DLG_TEXT[56];
							link.l1 = DLG_TEXT[23];

							if(CheckCharacterItem(characterFromID("hotel_ghost3"),"hotel_crucifix"))
							{
								link.l1.go = "exit";
								AddDialogExitQuest("ghost3_disappears"); 
							}
							else link.l1.go = "ghost_warning";
						}
						else 
						{
							DialogExit();
							Diag.CurrentNode = Diag.TempNode;

							PlaySound("VOICE\ENGLISH\zombie_die.wav");
							LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_hotel_room1")], false);
							LAi_SetActorType(characterFromID("hotel_ghost3"));
							LAi_ActorAttack(CharacterFromID("hotel_ghost3"), Pchar, "");

							pchar.quest.ghost3_restart.win_condition.l1 = "ExitFromLocation";
							pchar.quest.ghost3_restart.win_condition.l1.location = "Cartagena_hotel_room1";
							pchar.quest.ghost3_restart.win_condition = "ghost3_restart";
						}
					} 
				break;

				case "hotel_ghost6":
					if(CheckCharacterItem(Pchar,"hotel_megaphone"))
					{
						PlaySound("VOICE\ENGLISH\zombie4.wav");

						Pchar.hotel_megaphone = "on";
						TakeItemFromCharacter(Pchar, "hotel_megaphone" );
						GiveItem2Character(characterFromID("hotel_ghost6"), "hotel_megaphone");

						if(CheckCharacterItem(Pchar,"hotel_spyglass"))
						{
							Pchar.hotel_spyglass = "on";
							TakeItemFromCharacter(Pchar, "hotel_spyglass" );
							GiveItem2Character(characterFromID("hotel_ghost6"), "hotel_spyglass");
							Dialog.text = DLG_TEXT[63];
							link.l1 = DLG_TEXT[23];
						}
						else
						{
							Dialog.text = DLG_TEXT[62];
							link.l1 = DLG_TEXT[23];
						}

						if(CheckCharacterItem(characterFromID("hotel_ghost6"),"hotel_spyglass"))
						{
							link.l1.go = "exit";
							AddDialogExitQuest("ghost6_disappears"); 
						}
						else link.l1.go = "ghost_warning";
					}
					else
					{
						if(CheckCharacterItem(Pchar,"hotel_spyglass"))
						{
							PlaySound("VOICE\ENGLISH\zombie4.wav");

							Pchar.hotel_spyglass = "on";
							TakeItemFromCharacter(Pchar, "hotel_spyglass" );
							GiveItem2Character(characterFromID("hotel_ghost6"), "hotel_spyglass");
							Dialog.text = DLG_TEXT[61];
							link.l1 = DLG_TEXT[23];

							if(CheckCharacterItem(characterFromID("hotel_ghost6"),"hotel_megaphone"))
							{
								link.l1.go = "exit";
								AddDialogExitQuest("ghost6_disappears"); 
							}
							else link.l1.go = "ghost_warning";
						}
						else 
						{
							DialogExit();
							Diag.CurrentNode = Diag.TempNode;

							PlaySound("VOICE\ENGLISH\zombie_die.wav");
							LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_hotel_room2")], false);
							LAi_SetActorType(characterFromID("hotel_ghost6"));
							LAi_ActorAttack(CharacterFromID("hotel_ghost6"), Pchar, "");

							pchar.quest.ghost6_restart.win_condition.l1 = "ExitFromLocation";
							pchar.quest.ghost6_restart.win_condition.l1.location = "Cartagena_hotel_room2";
							pchar.quest.ghost6_restart.win_condition = "ghost6_restart";
						}
					} 
				break;

				case "hotel_ghost7":
					if(CheckCharacterItem(Pchar,"hotel_whistle"))
					{
						PlaySound("VOICE\ENGLISH\zombie5.wav");

						Pchar.hotel_whistle = "on";
						TakeItemFromCharacter(Pchar, "hotel_whistle" );
						GiveItem2Character(characterFromID("hotel_ghost7"), "hotel_whistle");

						if(CheckCharacterItem(Pchar,"hotel_grappling"))
						{
							Pchar.hotel_grappling = "on";
							TakeItemFromCharacter(Pchar, "hotel_grappling" );
							GiveItem2Character(characterFromID("hotel_ghost7"), "hotel_grappling");
							Dialog.text = DLG_TEXT[54];
							link.l1 = DLG_TEXT[23];
						}
						else
						{
							Dialog.text = DLG_TEXT[53];
							link.l1 = DLG_TEXT[23];
						}

						LAi_SetActorType(Pchar);
						LAi_ActorTurnToLocator(Pchar, "barmen", "bar2");
					
						if(CheckCharacterItem(characterFromID("hotel_ghost7"),"hotel_grappling"))
						{
							link.l1.go = "exit";
							AddDialogExitQuest("ghost7_disappears"); 
						}
						else link.l1.go = "ghost_warning";
					}
					else
					{
						if(CheckCharacterItem(Pchar,"hotel_grappling"))
						{
							PlaySound("VOICE\ENGLISH\zombie5.wav");

							Pchar.hotel_grappling = "on";
							TakeItemFromCharacter(Pchar, "hotel_grappling" );
							GiveItem2Character(characterFromID("hotel_ghost7"), "hotel_grappling");

							LAi_SetActorType(Pchar);
							LAi_ActorTurnToLocator(Pchar, "barmen", "bar2");
							Dialog.text = DLG_TEXT[52];
							link.l1 = DLG_TEXT[23];

							if(CheckCharacterItem(characterFromID("hotel_ghost7"),"hotel_whistle"))
							{
								link.l1.go = "exit";
								AddDialogExitQuest("ghost7_disappears"); 
							}
							else link.l1.go = "ghost_warning";
						}
						else 
						{
							DialogExit();
							Diag.CurrentNode = Diag.TempNode;

							PlaySound("VOICE\ENGLISH\zombie_die.wav");
							LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_hotel_room3")], false);
							LAi_SetActorType(characterFromID("hotel_ghost7"));
							LAi_ActorAttack(CharacterFromID("hotel_ghost7"), Pchar, "");

							pchar.quest.ghost7_restart.win_condition.l1 = "ExitFromLocation";
							pchar.quest.ghost7_restart.win_condition.l1.location = "Cartagena_hotel_room3";
							pchar.quest.ghost7_restart.win_condition = "ghost7_restart";
						}
					} 
				break;

				case "hotel_ghost8":
					if(CheckCharacterItem(Pchar,"hotel_sextant"))
					{
						PlaySound("VOICE\ENGLISH\zombie6.wav");

						Pchar.hotel_sextant = "on";
						TakeItemFromCharacter(Pchar, "hotel_sextant" );
						GiveItem2Character(characterFromID("hotel_ghost8"), "hotel_sextant");

						if(CheckCharacterItem(Pchar,"hotel_drawing"))
						{
							Pchar.hotel_drawing = "on";
							TakeItemFromCharacter(Pchar, "hotel_drawing" );
							GiveItem2Character(characterFromID("hotel_ghost8"), "hotel_drawing");
							Dialog.text = DLG_TEXT[60];
							link.l1 = DLG_TEXT[23];
						}
						else
						{
							Dialog.text = DLG_TEXT[58];
							link.l1 = DLG_TEXT[23];
						}

						if(CheckCharacterItem(characterFromID("hotel_ghost8"),"hotel_drawing"))
						{
							link.l1.go = "exit";
							AddDialogExitQuest("ghost8_disappears"); 
						}
						else link.l1.go = "ghost_warning";
					}
					else
					{
						if(CheckCharacterItem(Pchar,"hotel_drawing"))
						{
							PlaySound("VOICE\ENGLISH\zombie6.wav");

							Pchar.hotel_drawing = "on";
							TakeItemFromCharacter(Pchar, "hotel_drawing" );
							GiveItem2Character(characterFromID("hotel_ghost8"), "hotel_drawing");
							Dialog.text = DLG_TEXT[59];
							link.l1 = DLG_TEXT[23];

							if(CheckCharacterItem(characterFromID("hotel_ghost8"),"hotel_sextant"))
							{
								link.l1.go = "exit";
								AddDialogExitQuest("ghost8_disappears"); 
							}
							else link.l1.go = "ghost_warning";
						}
						else 
						{
							DialogExit();
							Diag.CurrentNode = Diag.TempNode;

							PlaySound("VOICE\ENGLISH\zombie_die.wav");
							LAi_LocationFightDisable(&Locations[FindLocation("Cartagena_hotel_room4")], false);
							LAi_SetActorType(characterFromID("hotel_ghost8"));
							LAi_ActorAttack(CharacterFromID("hotel_ghost8"), Pchar, "");

							pchar.quest.ghost8_restart.win_condition.l1 = "ExitFromLocation";
							pchar.quest.ghost8_restart.win_condition.l1.location = "Cartagena_hotel_room4";
							pchar.quest.ghost8_restart.win_condition = "ghost8_restart";
						}
					} 
				break;
			}
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
