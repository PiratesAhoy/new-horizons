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
				Dialog.Text = "If I were you, captain " + GetMyFullName(PChar) + ", I'd return immediately to my ship and sail far away from these shores!";
				Link.l1 = "And why should I do that?";
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
					text = "Dear friend ! You're always the welcome in this colony ! How are you and what wind lead you on this shore.";
					text = text + " Can i hope that you bring us some smuggling's goods you have taken to our enemies and you want to donate to our town.";
					text = text + " Of course we'll pay you a good sum to assume your war damages. Our governor will be proud to be our friend ! believe me.";
					text = text + " You could become a honour citizen of the town ! What do you think about that captain ? ";
					Dialog.Text = text;
					if(CheckAttribute(Pchar, "quest.Contraband.Active") && Pchar.quest.Contraband.Active == true)
					{
						Link.l2 = "Sorry but I have other engagements to honour.";
						Link.l2.go = "exit";						
					}
					else
					{
						if(FindFirstContrabandGoods(PChar) != -1)
						{
							Link.l1 = "I have this kind of goods in my hold. What's your proposition ?";
							Link.l1.go = "Price";
							Link.l2 = "Sorry but i'm not interested.";
							Link.l2.go = "exit";
						}
						else
						{
							Link.l1 = "Sorry but i haven't this kind of goods in my hold.";
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
								Dialog.Text = "You ! You'll never leave this island alive mate !";
								Link.l1 = "We are recognized  !";
							}
							else
							{
								Dialog.Text = "Damned ! That's you ! You'll never leave this island alive ! Alert ! Guards ! Guards !";
								Link.l1 = "We are recognized  !";
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
								Dialog.Text = "Captain "  + GetMyFullName(PChar) + " i presume ! you are " + nationme + ". I don't like " + nationme + " bastards ! I'll wait for you on sea ! Farewell !";
								Link.l1 = "It will be your end.";
								Link.l1.go = "exit";
								Diag.TempNode = "exit";
								SetCoastalEnemy(Npchar.model, Npchar.sex, GetMyName(NPChar), Npchar.lastname);
							}
							else
							{
								if(makeint(NPchar.nation) != PIRATE)
								{
									text = "Captain " + GetMyFullName(PChar) + " i presume ! Our local governor is ready to close his eyes about some of your actions against our nation that we could called Piracy actions.";
									text = text + " Our colony need some type of goods to grow and prosper. Perhap's have you captured some smuggling's goods during your actions.";
									text = text + " If you accepted to sell its to our town with a cheap price, our governor could speak in your favour and improve your relations towards the crown.";
									text = text + " People would look you more like a merchant instead of an... enemy ! What do you think about that captain ? ";
									Dialog.Text = text;
									if(CheckAttribute(Pchar, "quest.Contraband.Active") && Pchar.quest.Contraband.Active == true)
									{
										Link.l2 = "Sorry but i have other engagements to honour.";
										Link.l2.go = "exit";								
									}
									else
									{
										if(FindFirstContrabandGoods(PChar) != -1)
										{
											Link.l1 = "I have this kind of goods in my hold. What's your proposition ?";
											Link.l1.go = "Price";
											Link.l2 = "Sorry but i'm not interested.";
											Link.l2.go = "exit";
										}
										else
										{
											Link.l1 = "Sorry but i haven't this kind of goods in my hold.";
											Link.l1.go = "exit";
										}
									}
									Diag.TempNode = "first time";
								}
								else
								{
									Dialog.Text = "Captain " + GetMyFullName(PChar) + "! What winds led you on this cutthroat island?";
									Link.l1 = "Some personal business..";
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
							Dialog.Text = "Your nation is enemy of mine captain ! I'll wait for you on sea ! Farewell";
							Link.l1 = "It will be your end.";
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
								Dialog.Text = "Don't..disturb...me mate ! I don't want to talk !";
								Link.l1 = "keep sleeping matey..";
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
										text = "You seems to be a captain ! Our governor is always glad to offer his favors to able captains who can offer their help to our colony.";
										text = text + " Our town need some type of goods to grow and prosper. Perhap's have you captured some smuggling's goods to our enemies during your actions.";
										text = text + " If you accepted to sell its to our town with a cheap price, our governor could speak in your favour and improve your relations towards the crown.";
										text = text + " People would look you more like a merchant instead of an... enemy ! What do you think about that captain ? ";
										Dialog.Text = text;
										if(CheckAttribute(Pchar, "quest.Contraband.Active") && Pchar.quest.Contraband.Active == true)
										{
											Link.l2 = "Sorry but i have other engagements to honour.";
											Link.l2.go = "exit";								
										}
										else
										{
											if(FindFirstContrabandGoods(PChar) != -1)
											{
												Link.l1 = "I have this kind of goods in my hold. What's your proposition ?";
												Link.l1.go = "Price";
												Link.l2 = "Sorry but i'm not interested.";
												Link.l2.go = "exit";
											}
											else
											{
												Link.l1 = "Sorry but i haven't this kind of goods in my hold.";
												Link.l1.go = "exit";
											}
										}
										Diag.TempNode = "first time";
									}
									else	
									{
										Dialog.Text = "Yes ? What do you want captain ?";
										link.l1 = "It seems you are sitting to our table ! That's a problem between us ! Are you captain of a ship ? We could solve it at sea ! How about a challenge ?";
										link.l1.go = "defi";
										link.l2 = "Sorry for disturbing captain !";
										link.l2.go = "exit";
									}
								}
								else
								{
									Dialog.Text = "Good day captain ! What wind lead you on this cutthroat island ?";
									Link.l1 = "Some personnal buisness..";
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
				Dialog.Text = "I'm the captain of a good ship and i will never be in peace as long as you will on these earth ! I promise ! I'll see you on the sea Captain ! Farewell !";
				Link.l1 = "We'll see !";
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
				Dialog.Text = "We can offer you the sum of " + sum + " gold in exchange of all the smuggling's goods you have in your hold !";
				Link.l1 = "Well. If that can improve relations between me and your country, why not ?";
				Link.l1.go = "accept";
				Link.l2 = "Sorry but for this sum, i prefer to keep my goods ! Farewell !";
				Link.l2.go = "exit";
				Npchar.money = sum;
		break;

		case "accept":
				Dialog.Text = "That's good captain ! The governor will be satisfied with this news and believe well that he will be grateful for that ! Here's your money !";
				Link.l1 = "Thanks.";
				Link.l1.go = "exit";
				sum = Npchar.money;
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(pchar, sti(sum));
				AddMoneyToCharacter(Npchar, -sti(sum));
				float points = stf(sum/4000);
				ChangeRMRelation(pchar, sti(Npchar.nation), -points); // PB: was UpdateRMRelation

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
				Dialog.Text = "Yes, i'm the captain of a good ship ! You can see her in the port and I serve the crown of this colony.";
				Link.l1 = "Your governor will see your body hanged on my mast from the shore ! I'll wait you on sea captain ! Farewell !";
				Link.l1.go = "defi2";
				Link.l2 = "Sorry for disturbing captain !";
				Link.l2.go = "exit";
		break;

		case "defi2":
				if(rand(2)==0)
				{
					Dialog.Text = "I'm a corsar of the king and i accept your challenge mister ! You'll regret what you said.";
					Link.l1 = "Ha ! I'll sink you with pleasure !";
					Link.l1.go = "exit";
					SetCoastalEnemy(Npchar.model, Npchar.sex, GetMyName(NPChar), Npchar.lastname);
					Diag.TempNode = "exit";
				}
				else
				{
					Dialog.Text = "But i'm only a single merchant who just want to drink in peace ! Why do you want to kill me ? Help ! Help ! Is there somedy to help me ?";
					Link.l1 = "Shut up coward !";
					Link.l1.go = "exit";
					if(rand(5)==0){LAi_LocationFightDisable(&locations[FindLocation(Pchar.location)], false);Random_Raid("soldiers",5,makeint(NPchar.nation),LAI_GROUP_ENEMY,LAI_GROUP_NEUTRAL,"");}
					Diag.TempNode = "exit";
				}					
		break;


	}
}
