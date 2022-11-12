// ccc jul05 corpse
// This pseudo dialog only opens the itemexchange interface for looting corpses
// one could also add dialogchoices for reawakening or burial


void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar = GetMainCharacter();
	int iNation = sti(NPChar.nation);
	
	Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
	Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
	Preprocessor_Add("gendersubj", FirstLetterUp(XI_ConvertString(GetMyPronounSubj(PChar)))); // DeathDaisy
	Preprocessor_Add("genderobj", XI_ConvertString(GetMyPronounObj(PChar))); // DeathDaisy

	switch(Dialog.CurrentNode)
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "exit_soldiers":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			LAi_group_SetRelation(LAI_GROUP_GUARDS, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			LAi_group_SetRelation(GetSoldiersGroup(sti(NPChar.nation)), LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
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
			if(GetServedNation() == PIRATE && GetCurrentLocationNation() != PIRATE && iNation != PERSONAL_NATION)	// PB: Link this to acting as a pirate
			{
				Dialog.Text = DLG_TEXT[0] + GetMySimpleName(PChar) + DLG_TEXT[1];
				Link.l1 = RandSwear() + DLG_TEXT[2];
				Link.l1.go = "exit_soldiers";
				switch(iNation)
				{
					case ENGLAND : PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_068.wav"); break;
					case FRANCE  : PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_c_056.wav"); break;
					case SPAIN   : PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_b_057.wav"); break;
					case HOLLAND : PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_061.wav"); break;
					case PORTUGAL: PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_b_056.wav"); break;
					case AMERICA : PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_068.wav"); break;
					case PERSONAL_NATION : PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_b_068.wav"); break;
				}
				SetCoastalEnemy("","","","");
			}
			else
			{
				if (HaveLetterOfMarque(sti(NPChar.nation)) || iNation == PERSONAL_NATION)
				{
					if (iNation == PERSONAL_NATION)
					{
						Dialog.Text = DLG_TEXT[28] + GetMySimpleName(PChar) + DLG_TEXT[29];
						Link.l1 = DLG_TEXT[30];
					}
					else
					{
						Dialog.Text = DLG_TEXT[3] + GetMySimpleName(PChar) + DLG_TEXT[4];
						Link.l1 = DLG_TEXT[5];
					}
					Link.l1.go = "exit";
				}
				else
				{
					if (frnd() < GetChanceDetectFalseFlag())
					{
						if(GetRMRelation(PChar, sti(NPChar.nation)) <= REL_WAR)
						{
							switch(iNation)
							{
								case ENGLAND : PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_067.wav"); break;
								case FRANCE  : PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_c_065.wav"); break;
								case SPAIN   : PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_b_050.wav"); break;
								case HOLLAND : PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_058.wav"); break;
								case PORTUGAL: PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_b_053.wav"); break;
								case AMERICA : PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_067.wav"); break;
								case PERSONAL_NATION : PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_b_067.wav"); break;
							}
							Dialog.Text = DLG_TEXT[6] + GetMySimpleName(PChar) + DLG_TEXT[7];
							Link.l1 = DLG_TEXT[8] + GetNationDescByType(sti(NPChar.nation)) + DLG_TEXT[9];
							Link.l1.go = "exit_soldiers";
						}
						else
						{
							if(GetFlagRMRelation(sti(NPChar.nation)) == RELATION_ENEMY)
							{
								switch(sti(NPChar.nation))
								{
									case ENGLAND : PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_067.wav"); break;
									case FRANCE  : PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_c_065.wav"); break;
									case SPAIN   : PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_b_050.wav"); break;
									case HOLLAND : PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_058.wav"); break;
									case PORTUGAL: PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_b_053.wav"); break;
									case AMERICA : PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_067.wav"); break;
									case PERSONAL_NATION : PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_b_067.wav"); break;
								}
								Dialog.Text = DLG_TEXT[10] + GetNationDescByType(sti(NPChar.nation)) + DLG_TEXT[11] + GetNationDescByType(GetServedNation()) + DLG_TEXT[12];
								Link.l1 = DLG_TEXT[8] + GetNationDescByType(sti(NPChar.nation)) + DLG_TEXT[9];
								Link.l1.go = "exit_soldiers";
							}
							else
							{
								Dialog.Text = DLG_TEXT[13];
								Link.l1 = DLG_TEXT[14];
								Link.l1.go = "exit";
							}
						}
					}
					else
					{
						if(GetFlagRMRelation(sti(NPChar.nation)) == RELATION_ENEMY && rand(10)>8)
						{
							switch(makeint(NPChar.nation))
							{
								case ENGLAND : PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_068.wav"); break;
								case FRANCE  : PlaySound("VOICE\" + LanguageGetLanguage() + "\Fre_m_c_056.wav"); break;
								case SPAIN   : PlaySound("VOICE\" + LanguageGetLanguage() + "\Spa_m_b_057.wav"); break;
								case HOLLAND : PlaySound("VOICE\" + LanguageGetLanguage() + "\Dut_m_a_061.wav"); break;
								case PORTUGAL: PlaySound("VOICE\" + LanguageGetLanguage() + "\Por_m_b_056.wav"); break;
								case AMERICA : PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_068.wav"); break;
								case PERSONAL_NATION : PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_b_068.wav"); break;
							}
							Dialog.Text = DLG_TEXT[15] + GetNationDescByType(GetCurrentFlag()) + DLG_TEXT[16];
							Link.l1 = DLG_TEXT[17];
							Link.l1.go = "exit_soldiers";
						}
						else
						{
							if(GetCurrentFlag() == sti(NPChar.nation))
							{
								Dialog.Text = DLG_TEXT[18];
								Link.l1 = DLG_TEXT[19];
								Link.l1.go = "exit";
							}
							else
							{
								Dialog.Text = DLG_TEXT[13];
								Link.l1 = DLG_TEXT[14];
								Link.l1.go = "exit";
							}
						}
					}
				}
			}	
			Diag.TempNode = "first time";
		break;

	}
}
