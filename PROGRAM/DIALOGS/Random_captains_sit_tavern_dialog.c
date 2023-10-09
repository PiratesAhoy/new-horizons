void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");
	int Shit, price;
	int sum = 0;

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	string text;
	PChar = GetMainCharacter();
	int loc_id = FindLocation(PChar.location);
	string nationme, nationhim;

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
			if(GetServedNation() == PIRATE && GetCurrentLocationNation() != PIRATE)	// PB: Link this to acting as a pirate
			{
				Dialog.Text = DLG_TEXT[0] + GetMyFullName(PChar) + DLG_TEXT[1];
				Link.l1 = DLG_TEXT[2];
				Link.l1.go = "why";
				switch(makeint(Npchar.nation))
				{
					case 0 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_b_042.wav");}break;
					case 1 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_c_046.wav");}break;
					case 2 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_a_037.wav");}break;
					case 3 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_a_052.wav");}break;
					case 4 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_042.wav");}break;
					case 5 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_a_038.wav");}break;
				}
				Diag.TempNode = "exit";
			}
			else
			{
				if (HaveLetterOfMarque(sti(Npchar.nation)))
				{
					text = DLG_TEXT[3];
					text = text + DLG_TEXT[4];
					text = text + DLG_TEXT[5];
					text = text + DLG_TEXT[6];
					Dialog.Text = text;
					if(CheckAttribute(Pchar, "quest.Contraband.Active") && Pchar.quest.Contraband.Active == true)
					{
						Link.l2 = DLG_TEXT[7];
						Link.l2.go = "exit";						
					}
					else
					{
						if(FindFirstContrabandGoods(PChar) != -1)
						{
							Link.l1 = DLG_TEXT[8];
							Link.l1.go = "Price";
							Link.l2 = DLG_TEXT[9];
							Link.l2.go = "exit";
						}
						else
						{
							Link.l1 = DLG_TEXT[10];
							Link.l1.go = "exit";
						}
					}
					switch(makeint(Npchar.nation))
					{
						case 0 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_b_080.wav");}break;
						case 1 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_c_073.wav");}break;
						case 2 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_b_004.wav");}break;
						case 3 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_a_062.wav");}break;
						case 4 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_068.wav");}break;
						case 5 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_b_062.wav");}break;
					}
					Diag.TempNode = "first time";
				}
				else
				{
					if (frnd() < GetChanceDetectFalseFlag() && rand(1)==0)
					{
						int MyNation = PERSONAL_NATION;
						int MyFlag = GetCurrentFlag();
						if(GetRMRelation(PChar, sti(Npchar.nation)) <= REL_WAR)
						{
							if(Makeint(NPchar.nation) == PIRATE)
							{
								Dialog.Text = DLG_TEXT[11];
								Link.l1 = DLG_TEXT[12];
							}
							else
							{
								Dialog.Text = DLG_TEXT[13];
								Link.l1 = DLG_TEXT[14];
							}
							link.l1.go = "exit";
							switch(makeint(Npchar.nation))
							{
								case 0 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_067.wav");}break;
								case 1 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_c_065.wav");}break;
								case 2 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_b_056.wav");}break;
								case 3 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_a_053.wav");}break;
								case 4 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_058.wav");}break;
								case 5 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_a_054.wav");}break;
							}
							SetCoastalEnemy(Npchar.model, Npchar.sex, GetMyName(NPChar), Npchar.lastname);
							LAi_LocationFightDisable(&locations[FindLocation(Pchar.location)], false);
							Random_Raid("soldiers", 5, makeint(NPchar.nation), LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "");
							Diag.TempNode = "exit";
						}
						else
						{
							Mynation = GetServedNation();
							if(GetFlagRMRelation(sti(Npchar.nation)) <= REL_WAR && makeint(NPchar.nation)!=3)
							{
								switch(mynation)
								{
									case ENGLAND : nationme="english";break;
									case FRANCE : nationme="french";break;
									case SPAIN : nationme="spanish";break;
									case PIRATE : nationme="pirate";break;
									case HOLLAND : nationme="dutch";break;
									case PORTUGAL : nationme="portuguese";break;
									case PERSONAL_NATION : nationme="pirate";break;
								}
								LAi_LocationFightDisable(&locations[FindLocation(Pchar.location)], false);
								switch(makeint(Npchar.nation))
								{
									case 0 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_010.wav");}nationhim="english";break;
									case 1 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_a_010.wav");}nationhim="french";break;
									case 2 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_b_029.wav");}nationhim="spanish";break;
									case 4 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_008.wav");}nationhim="dutch";break;
									case 5 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_a_007.wav");}nationhim="portuguese";break;
								}
								Dialog.Text = DLG_TEXT[15] + GetMyFullName(PChar) + DLG_TEXT[16] + nationme + DLG_TEXT[17] + nationme + DLG_TEXT[18];
								Link.l1 = DLG_TEXT[19];
								Link.l1.go = "exit";
								Diag.TempNode = "exit";
								SetCoastalEnemy(Npchar.model, Npchar.sex, GetMyName(NPChar), Npchar.lastname);
							}
							else
							{
								if(makeint(NPchar.nation) != PIRATE)
								{
									text = DLG_TEXT[20] + GetMyFullName(PChar) + DLG_TEXT[21];
									text = text + DLG_TEXT[22];
									text = text + DLG_TEXT[23];
									text = text + DLG_TEXT[24];
									Dialog.Text = text;
									if(CheckAttribute(Pchar, "quest.Contraband.Active") && Pchar.quest.Contraband.Active == true)
									{
										Link.l2 = DLG_TEXT[25];
										Link.l2.go = "exit";								
									}
									else
									{
										if(FindFirstContrabandGoods(PChar) != -1)
										{
											Link.l1 = DLG_TEXT[26];
											Link.l1.go = "Price";
											Link.l2 = DLG_TEXT[27];
											Link.l2.go = "exit";
										}
										else
										{
											Link.l1 = DLG_TEXT[28];
											Link.l1.go = "exit";
										}
									}
									Diag.TempNode = "first time";
								}
								else
								{
									Dialog.Text = DLG_TEXT[29] + GetMyFullName(PChar) + DLG_TEXT[30];
									Link.l1 = DLG_TEXT[31];
									Link.l1.go = "exit";
									Diag.TempNode = "first time";
								}
								switch(makeint(Npchar.nation))
								{
									case 0 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_b_080.wav");}break;
									case 1 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_c_073.wav");}break;
									case 2 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_b_004.wav");}break;
									case 3 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_a_062.wav");}break;
									case 4 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_068.wav");}break;
									case 5 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_b_062.wav");}break;
								}
							}
						}
					}
					else
					{
						MyFlag = GetCurrentFlag();
						if(GetFlagRMRelation(sti(Npchar.nation)) <= REL_WAR && rand(10)>8)
						{
							Dialog.Text = DLG_TEXT[32];
							Link.l1 = DLG_TEXT[33];
							Link.l1.go = "exit";
							switch(makeint(Npchar.nation))
							{
								case 0 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_010.wav");}break;
								case 1 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_a_010.wav");}break;
								case 2 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_b_029.wav");}break;
								case 3 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_b_038.wav");}break;
								case 4 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_008.wav");}break;
								case 5 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_a_007.wav");}break;
							}
							SetCoastalEnemy(Npchar.model, Npchar.sex, GetMyName(NPChar), Npchar.lastname);
							Diag.TempNode = "exit";
						}
						else
						{
							if(rand(10)>8)
							{
								Dialog.Text = DLG_TEXT[34];
								Link.l1 = DLG_TEXT[35];
								Link.l1.go = "exit";
								switch(makeint(Npchar.nation))
								{
									case 0 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_010.wav");}break;
									case 1 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_a_010.wav");}break;
									case 2 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_b_029.wav");}break;
									case 3 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_b_038.wav");}break;
									case 4 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_008.wav");}break;
									case 5 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_a_007.wav");}break;
								}
								Diag.TempNode = "exit";
							}
							else
							{
								if(makeint(NPchar.nation) != PIRATE)
								{
									if(rand(10)>7)
									{
										text = DLG_TEXT[36];
										text = text + DLG_TEXT[37];
										text = text + DLG_TEXT[38];
										text = text + DLG_TEXT[39];
										Dialog.Text = text;
										if(CheckAttribute(Pchar, "quest.Contraband.Active") && Pchar.quest.Contraband.Active == true)
										{
											Link.l2 = DLG_TEXT[40];
											Link.l2.go = "exit";								
										}
										else
										{
											if(FindFirstContrabandGoods(PChar) != -1)
											{
												Link.l1 = DLG_TEXT[41];
												Link.l1.go = "Price";
												Link.l2 = DLG_TEXT[42];
												Link.l2.go = "exit";
											}
											else
											{
												Link.l1 = DLG_TEXT[43];
												Link.l1.go = "exit";
											}
										}
										Diag.TempNode = "first time";
									}
									else	
									{
										Dialog.Text = DLG_TEXT[44];
										link.l1 = DLG_TEXT[45];
										link.l1.go = "defi";
										link.l2 = DLG_TEXT[46];
										link.l2.go = "exit";
									}
								}
								else
								{
									Dialog.Text = DLG_TEXT[47];
									Link.l1 = DLG_TEXT[48];
									Link.l1.go = "exit";
									Diag.TempNode = "first time";
								}
								switch(makeint(Npchar.nation))
								{
									case 0 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_b_080.wav");}break;
									case 1 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_c_073.wav");}break;
									case 2 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_b_004.wav");}break;
									case 3 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_a_062.wav");}break;
									case 4 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_068.wav");}break;
									case 5 : if(Npchar.sex=="man"){PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_b_062.wav");}break;
								}
							}
						}
					}
				}
			}
		break;


		case "why":
				Dialog.Text = DLG_TEXT[49];
				Link.l1 = DLG_TEXT[50];
				Link.l1.go = "exit";
				SetCoastalEnemy(Npchar.model, Npchar.sex, GetMyName(NPChar), Npchar.lastname);
				if(rand(5)==0){LAi_LocationFightDisable(&locations[FindLocation(Pchar.location)], false);Random_Raid("soldiers",5,makeint(NPchar.nation),LAI_GROUP_ENEMY,LAI_GROUP_NEUTRAL,"");}
		break;

		case "price":
				Diag.TempNode = "exit";
				
				if(FindFirstContrabandGoods(Pchar) != -1) 
				{
					price = makeint(GetCurrentIslandGoodsPrice(FindFirstContrabandGoods(Pchar))*1.5);
					price = makeint(price)*GetSquadronGoods(Pchar,makeint(FindFirstContrabandGoods(Pchar)));
					sum = price;
				 }
				shit = FindNextContrabandGoods(Pchar);
				if(shit != -1) 
				{
					price = makeint(GetCurrentIslandGoodsPrice(shit)*1.5);
					price = makeint(price)*GetSquadronGoods(Pchar,makeint(shit));
					sum = sum + price;
				}
				shit = FindNextContrabandGoods(Pchar);
				if(shit != -1) 
				{
					price = makeint(GetCurrentIslandGoodsPrice(shit)*1.5);
					price = makeint(price)*GetSquadronGoods(Pchar,makeint(shit));
					sum = sum + price;		
				}
				shit = FindNextContrabandGoods(Pchar);
				if(shit != -1) 
				{
					price = makeint(GetCurrentIslandGoodsPrice(shit)*1.5);
					price = makeint(price)*GetSquadronGoods(Pchar,makeint(shit));
					sum = sum + price;
				}
				sum = Makeint(sum/2);
				Dialog.Text = DLG_TEXT[51] + sum + DLG_TEXT[52];
				Link.l1 = DLG_TEXT[53];
				Link.l1.go = "accept";
				Link.l2 = DLG_TEXT[54];
				Link.l2.go = "exit";
				Npchar.money = sum;
		break;

		case "accept":
				Dialog.Text = DLG_TEXT[55];
				Link.l1 = DLG_TEXT[56];
				Link.l1.go = "exit";
				sum = Npchar.money;
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(pchar, sti(sum));
				AddMoneyToCharacter(Npchar, -sti(sum));
				float points = stf(sum/4000);
				ChangeRMRelation(pchar, sti(Npchar.nation), points); // PB: was UpdateRMRelation

				if(FindFirstContrabandGoods(Pchar) != -1) 
				{
					RemoveCharacterGoods(Pchar, makeint(FindFirstContrabandGoods(Pchar)), GetCargoGoods(Pchar, makeint(FindFirstContrabandGoods(Pchar))));
					if(GetCompanionIndex(Pchar, 1) != -1)
					{
						RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 1)], makeint(FindFirstContrabandGoods(Pchar)), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 1)], makeint(FindFirstContrabandGoods(Pchar))));
					}
					if(GetCompanionIndex(Pchar, 2) != -1)
					{
						RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 2)], makeint(FindFirstContrabandGoods(Pchar)), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 2)], makeint(FindFirstContrabandGoods(Pchar))));
					}
					if(GetCompanionIndex(Pchar, 3) != -1)
					{
						RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 3)], makeint(FindFirstContrabandGoods(Pchar)), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 3)], makeint(FindFirstContrabandGoods(Pchar))));
					}
				 }
				shit = FindNextContrabandGoods(Pchar);
				if(shit != -1) 
				{
					RemoveCharacterGoods(Pchar, makeint(shit), GetCargoGoods(Pchar, makeint(shit)));
					if(GetCompanionIndex(Pchar, 1) != -1)
					{
						RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 1)], makeint(shit), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 1)], makeint(shit)));
					}
					if(GetCompanionIndex(Pchar, 2) != -1)
					{
						RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 2)], makeint(shit), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 2)], makeint(shit)));
					}
					if(GetCompanionIndex(Pchar, 3) != -1)
					{
						RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 3)], makeint(shit), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 3)], makeint(shit)));
					}
				}
				shit = FindNextContrabandGoods(Pchar);
				if(shit != -1) 
				{
					RemoveCharacterGoods(Pchar, makeint(shit), GetCargoGoods(Pchar, makeint(shit)));
					if(GetCompanionIndex(Pchar, 1) != -1)
					{
						RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 1)], makeint(shit), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 1)], makeint(shit)));
					}
					if(GetCompanionIndex(Pchar, 2) != -1)
					{
						RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 2)], makeint(shit), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 2)], makeint(shit)));
					}
					if(GetCompanionIndex(Pchar, 3) != -1)
					{
						RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 3)], makeint(shit), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 3)], makeint(shit)));
					}
				}
				shit = FindNextContrabandGoods(Pchar);
				if(shit != -1) 
				{
					RemoveCharacterGoods(Pchar, makeint(shit), GetCargoGoods(Pchar, makeint(shit)));
					if(GetCompanionIndex(Pchar, 1) != -1)
					{
						RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 1)], makeint(shit), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 1)], makeint(shit)));
					}
					if(GetCompanionIndex(Pchar, 2) != -1)
					{
						RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 2)], makeint(shit), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 2)], makeint(shit)));
					}
					if(GetCompanionIndex(Pchar, 3) != -1)
					{
						RemoveCharacterGoods(&Characters[getCompanionIndex(Pchar, 3)], makeint(shit), GetCargoGoods(&Characters[getCompanionIndex(Pchar, 3)], makeint(shit)));
					}
				}
				Diag.TempNode = "exit";
		break;

		case "defi":
				Dialog.Text = DLG_TEXT[57];
				Link.l1 = DLG_TEXT[58];
				Link.l1.go = "defi2";
				Link.l2 = DLG_TEXT[59];
				Link.l2.go = "exit";
		break;

		case "defi2":
				if(rand(2)==0)
				{
					Preprocessor_Add("ladlass", XI_ConvertString(GetAddressForm(ADDR_INFORMAL, ENGLAND, GetAttribute(PChar, "sex") == "woman")));
					Dialog.Text = DLG_TEXT[64];
					if (sti(NPChar.nation) == GetCurrentFlag())
					{
						Preprocessor_Add("nation", XI_ConvertString(GetNationDescByType(sti(NPChar.nation))));
						Dialog.Text = Dialog.Text + DLG_TEXT[65];
					}
					else
					{
						Preprocessor_Add("nation", XI_ConvertString(GetNationNameByType(sti(NPChar.nation))));
						Dialog.Text = Dialog.Text + DLG_TEXT[66];
					}
					Dialog.Text = Dialog.Text + DLG_TEXT[67];
					Link.l1 = DLG_TEXT[68];
					Link.l1.go = "exit";
					Link.l2 = DLG_TEXT[69];
					Link.l2.go = "defi3";
					Diag.TempNode = "exit";
				}
				else
				{
					Dialog.Text = DLG_TEXT[62];
					Link.l1 = DLG_TEXT[63];
					Link.l1.go = "exit";
					if(rand(5)==0){LAi_LocationFightDisable(&locations[FindLocation(Pchar.location)], false);Random_Raid("soldiers",5,makeint(NPchar.nation),LAI_GROUP_ENEMY,LAI_GROUP_NEUTRAL,"");}
					Diag.TempNode = "exit";
				}					
		break;

		case "defi3":
				Preprocessor_Add("mister", XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false)));
				Dialog.Text = DLG_TEXT[60];
				Link.l1 = DLG_TEXT[61];
				Link.l1.go = "exit";
				SetCoastalEnemy(Npchar.model, Npchar.sex, GetMyName(NPChar), Npchar.lastname);
				Diag.TempNode = "exit";
		break;
	}
}
