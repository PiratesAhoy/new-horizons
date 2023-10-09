// MT: Sailors of a particular nation only spawn in taverns belonging to that nation, and no sailors of other nationalities spawn there.

void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	int loc_id = FindLocation(PChar.location);
	string nationme, nationhim;

	int maxCrewquantity = GetMaxCrewQuantity(PChar);
	int maxcrew = GetMaxLandCrew(sti(PChar.Ship.Crew.Quantity));

	switch(Dialog.CurrentNode)
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "first time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\PADI\PADI001";

			// ccc Dec 05 You are recognized for your pirating actions
			if(GetServedNation() == PIRATE && GetCurrentLocationNation() != PIRATE)	// MT: If serving the pirates and in a non-pirate location, then:
			{
				if(frnd()<makefloat(GetRank(pchar, sti(NPChar.nation)))/12.0) //MT: Meant to make you easier to detect as a pirate as you go up in pirate rank
				{
					Dialog.Text = DLG_TEXT[0] + GetMyFullName(PChar) + DLG_TEXT[1];
					Link.l1 = RandSwear() + DLG_TEXT[29];
					if(TAVERNBRAWL_FROMDIALOG)	Link.l1.go = "exit_soldiers"; //MT: If the possibility of tavernbrawls is turned on in internalsettings:
					else						Link.l1.go = "exit";
					switch(makeint(Npchar.nation)) //MT: note absence of PIRATE
					{
						case ENGLAND : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_057.wav");}break;
						case FRANCE  : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_c_018.wav");}break;
						case SPAIN   : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_b_037.wav");}break;
						case HOLLAND : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_008.wav");}break;
						case PORTUGAL: if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_a_038.wav");}break;
						case AMERICA : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_057.wav");}break;
					}
					Diag.TempNode = "exit";
				}
				else //MT: Not recognised as pirate.
				{
					Dialog.Text = DLG_TEXT[19];
					Link.l1 = DLG_TEXT[20];
					Link.l1.go = "exit";
					switch(makeint(Npchar.nation)) //MT: note absence of PIRATE
					{
						case ENGLAND : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_010.wav");}break;
						case FRANCE  : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_a_010.wav");}break;
						case SPAIN   : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_b_029.wav");}break;
						case HOLLAND : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_008.wav");}break;
						case PORTUGAL: if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_a_007.wav");}break;
						case AMERICA : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_010.wav");}break;
					}
					Diag.TempNode = "first time";
				}
			}
			else //MT: You don't serve the pirates or you are in a pirate location, or both. (note: friendly does not neccesarily mean serving!) Triggers when serving pirates and in pirate location as well.
			{
				if (GetFlagRMRelation(sti(Npchar.nation)) == RELATION_ENEMY) //MT: using flag that is hostile. Includes personal flag, which implies personal hostility as well
				{
					if (GetNationRelation(PERSONAL_NATION, sti(Npchar.nation)) != RELATION_ENEMY) //MT: not personally hostile, but using a flag that is hostile
					{
						Dialog.Text = DLG_TEXT[17];
						Link.l1 = DLG_TEXT[18];
						if(TAVERNBRAWL_FROMDIALOG)	Link.l1.go = "exit_brawl"; //MT: If the possibility of tavernbrawls is turned on in internalsettings:
						else						Link.l1.go = "exit";
						switch(makeint(Npchar.nation))
						{
							case ENGLAND : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_056.wav");}break;
							case FRANCE  : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_a_048.wav");}break;
							case SPAIN   : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_b_042.wav");}break;
							case PIRATE  : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_b_052.wav");}break;
							case HOLLAND : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_043.wav");}break;
							case PORTUGAL: if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_b_042.wav");}break;
							case AMERICA : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_056.wav");}break;
						}
						Diag.TempNode = "exit";
					}
					else
					{
						Dialog.Text = DLG_TEXT[7];
						Link.l1 = DLG_TEXT[8] + XI_ConvertString(GetNationDescByType(sti(NPChar.nation))) + DLG_TEXT[9];
						if(TAVERNBRAWL_FROMDIALOG)	Link.l1.go = "exit_brawl"; //MT: If the possibility of tavernbrawls is turned on in internalsettings:
						else						Link.l1.go = "exit";
						switch(makeint(Npchar.nation))
						{
							case ENGLAND : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_056.wav");}break;
							case FRANCE  : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_a_048.wav");}break;
							case SPAIN   : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_b_042.wav");}break;
							case PIRATE  : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_b_052.wav");}break;
							case HOLLAND : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_043.wav");}break;
							case PORTUGAL: if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_b_042.wav");}break;
							case AMERICA : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_056.wav");}break;
						}
						Diag.TempNode = "exit";
					}
				}
				else //MT: the flag you're using is not hostile
				{
					if (GetNationRelation(PERSONAL_NATION, sti(Npchar.nation)) == RELATION_ENEMY && frnd() < GetChanceDetectFalseFlag()) //MT: at war with the nation the sailor belongs to, but using false flag, with detection chance.
					{
						switch(makeint(Npchar.nation))
						{
							case ENGLAND : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_070.wav");}break;
							case FRANCE  : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_c_048.wav");}break;
							case SPAIN   : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_b_043.wav");}break;
							case PIRATE  : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_a_044.wav");}break;
							case HOLLAND : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_058.wav");}break;
							case PORTUGAL: if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_a_053.wav");}break;
							case AMERICA : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_070.wav");}break;
						}
						Dialog.Text = DLG_TEXT[12] + XI_ConvertString(GetNationDescByType(sti(NPChar.nation))) + DLG_TEXT[13] + XI_ConvertString(GetNationDescByType(sti(PChar.nation))) + DLG_TEXT[14];
						Link.l1 = DLG_TEXT[15] + XI_ConvertString(GetNationDescByType(sti(NPChar.nation))) + DLG_TEXT[16];
						if(TAVERNBRAWL_FROMDIALOG) //MT: If the possibility of tavernbrawls is turned on in internalsettings:
						{
							if (makeint(NPchar.nation)==PIRATE)	Link.l1.go = "exit_brawl";
							else								Link.l1.go = "exit_soldiers";
						}
						else
						{
							Link.l1.go = "exit";
						}
						Diag.TempNode = "exit";
					}
					else //MT: The sailor has no reason to go hostile
					{
						if (frnd()>0.8) //MT: Random chance for people to ignore you
						{
							Dialog.Text = DLG_TEXT[19];
							Link.l1 = DLG_TEXT[20];
							Link.l1.go = "exit";
							switch(makeint(Npchar.nation))
							{
								case ENGLAND : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_010.wav");}break;
								case FRANCE  : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_a_010.wav");}break;
								case SPAIN   : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_b_029.wav");}break;
								case PIRATE  : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_b_038.wav");}break;
								case HOLLAND : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_008.wav");}break;
								case PORTUGAL: if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_a_007.wav");}break;
								case AMERICA : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_010.wav");}break;
							}
							Diag.TempNode = "exit";
						}
						else
						{
							if (frnd()<makefloat(GetRank(pchar, sti(NPChar.nation)))/12.0 || frnd()<makefloat(GetRankFromPoints(GetScore(PChar)))/12.0) //MT: high-ranking officer with a nation or famous
							{
								Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
								Dialog.Text = DLG_TEXT[2]; //MT: all dialogues with Dialog.Text in front are the sailor's opening line
							}
							else //MT: if not famous
							{
								if (IsInServiceOf(sti(Npchar.nation))) //MT: You serve the nation of whoever you're talking to, either through navy or LoM
								{
									Dialog.Text = DLG_TEXT[3];
								}
								else //MT: not in service
								{
									Dialog.Text = DLG_TEXT[30];
								}
							}
							if(Pchar.Ship.Crew.Quantity<maxCrewquantity)
							{
								Link.l1 = DLG_TEXT[4];
								Link.l1.go = "engage"; //MT: activates crew hiring options; see bottom of file
								Link.l2 = DLG_TEXT[5];
								Link.l2.go = "exit";
							}
							else
							{
								Link.l1 = DLG_TEXT[6];
								Link.l1.go = "exit";
							}
							switch(makeint(Npchar.nation))
							{
								case ENGLAND : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_b_080.wav");}break;
								case FRANCE  : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_c_073.wav");}break;
								case SPAIN   : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_b_004.wav");}break;
								case PIRATE  : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_a_062.wav");}break;
								case HOLLAND : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_068.wav");}break;
								case PORTUGAL: if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_b_062.wav");}break;
								case AMERICA : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_b_080.wav");}break;
							}
							Diag.TempNode = "first time";
						}
					}
				}
			}
		break;

		case "exit_brawl":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			PChar.TAVERNBRAWL = true; //MT: deletes the group's weapons, if enabled in internalsettings
			LAi_LocationFightDisable(&locations[FindLocation(Pchar.location)], false);
			Random_Raid("smugglers", 5, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, LanguageConvertString(tmpLangFileID,"TAVERNBRAWL") + "!!!");
			DeleteAttribute(PChar,"TAVERNBRAWL"); //MT: resets tavernbrawl attribute so enemies won't always spawn with fists afterwards.
		break;

		case "exit_soldiers":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			LAi_LocationFightDisable(&locations[FindLocation(Pchar.location)], false);
			Random_Raid("Soldiers", 1, sti(NPchar.nation), LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "");
		break;

		case "engage":
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			Dialog.Text = DLG_TEXT[23];
			if(MAX_CREWMEMBERS<maxcrew && MAX_CREWMEMBERS<10)
			{
				Link.l1 = DLG_TEXT[24];
				Link.l1.go = "follow";
			}
			Link.l2 = DLG_TEXT[25];
			Link.l2.go = "Dontfollow";
		break;

		case "follow":
			Dialog.Text = DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "exit";
			LAi_group_MoveCharacter(Npchar, LAI_GROUP_PLAYER);
			LAi_SetOfficerType(Npchar);
			AddCharacterCrew(Pchar,1);
			MAX_CREWMEMBERS++;
			ref crew = characterFromID("Treas_Crewmember_" + MAX_CREWMEMBERS);
			if(Lai_IsDead(crew))
			{
				RemoveCharacterCrew(Pchar,1);
				if(MAX_CREWMEMBERS>0){MAX_CREWMEMBERS = MAX_CREWMEMBERS-1;}
				crew.location = "";
				crew.location.group = "";
				crew.location.locator = "";
			}
			crew.model=Npchar.model;
			crew.sex=Npchar.sex;
			crew.ani=Npchar.ani;
			Facemaker(crew);
			crew.nation=Npchar.nation;
			NPChar.Dialog.Filename = "permanent_crewmember_dialog.c";
			//Diag.TempNode = "exit";
		break;

		case "Dontfollow":
			Dialog.Text = DLG_TEXT[28];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "exit";
			LAi_group_MoveCharacter(Npchar, LAI_GROUP_PLAYER);
			AddCharacterCrew(Pchar,1);
			Diag.TempNode = "exit";
		break;
	}
	LanguageCloseFile(tmpLangFileID);
}
