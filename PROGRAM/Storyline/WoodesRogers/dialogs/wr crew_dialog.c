// JRH fake dialog for wr guards without talking heads

void ProcessDialogEvent()
{
	aref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makearef(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	LAi_SetActorType(NPChar);
	LAi_ActorTurnToCharacter(NPChar, PChar);

	string guardid;
	guardid = NPChar.id;
	switch(guardid)
	{
		case "wr_raoul":
			PlaySound("VOICE\ENGLISH\Fre_m_c_074.wav");
		break;

		case "wr_omat1":
			PlaySound("VOICE\ENGLISH\Spa_m_a_032.wav");
		break;

		case "wr_prt7":
			PlaySound("VOICE\ENGLISH\Dut_m_a_010.wav");
		break;

		case "wr_rabbl":
			PlaySound("VOICE\ENGLISH\Fre_m_a_061.wav");
		break;

		case "wr_blcor":
			PlaySound("VOICE\ENGLISH\Dut_m_a_035.wav");
		break;

		case "wr_sail4":
			PlaySound("VOICE\ENGLISH\Eng_m_c_042.wav");
		break;

		case "wr_sail7":
			PlaySound("VOICE\ENGLISH\Fre_m_a_038.wav");
		break;

		case "wr_snav":
			PlaySound("VOICE\ENGLISH\Eng_m_c_022.wav");
		break;

		case "wr_oman1":
			PlaySound("VOICE\ENGLISH\Dut_m_a_033.wav");
		break;

		case "wr_boc1":
			PlaySound("VOICE\ENGLISH\Dut_m_a_055.wav");
		break;

		case "wr_boc4":
			PlaySound("VOICE\ENGLISH\Eng_m_c_066.wav");
		break;

		case "wr_cha":
			PlaySound("VOICE\ENGLISH\Fre_m_a_040.wav");
		break;

		case "wr_cor1":
			PlaySound("VOICE\ENGLISH\Eng_m_a_041.wav");
		break;

		case "wr_cor3":
			PlaySound("VOICE\ENGLISH\Spa_m_a_042.wav");
		break;

		case "wr_fat2":
			PlaySound("VOICE\ENGLISH\Spa_m_b_008.wav");
		break;

		case "wr_fralut":
			PlaySound("VOICE\ENGLISH\Dut_m_a_071.wav");
		break;

		case "wr_fsh":
			PlaySound("VOICE\ENGLISH\Spa_m_b_010.wav");
		break;

		case "wr_hubspa":
			PlaySound("VOICE\ENGLISH\Spa_m_b_053.wav");		
		break;

		case "wr_kor":
			PlaySound("VOICE\ENGLISH\Dut_m_a_008.wav");
		break;

		case "wr_mong":
			PlaySound("VOICE\ENGLISH\Dut_m_a_042.wav");
		break;

		case "wr_nap":
			PlaySound("VOICE\ENGLISH\Fre_m_a_009.wav");
		break;

		case "wr_grey":
			PlaySound("VOICE\ENGLISH\Eng_m_c_060.wav");		
		break;

		case "wr_pir2":
			PlaySound("VOICE\ENGLISH\Eng_m_a_042.wav");
		break;

		case "wr_pir4":
			PlaySound("VOICE\ENGLISH\Por_m_a_032.wav");
		break;

		case "wr_fatj":
			PlaySound("VOICE\ENGLISH\Eng_m_a_039.wav");
		break;

		case "wr_pir7":
			PlaySound("VOICE\ENGLISH\Dut_m_a_050.wav");
		break;

		case "wr_wll3":
			PlaySound("VOICE\ENGLISH\Dut_m_a_053.wav");
		break;

		case "wr_sol6f77":
			PlaySound("VOICE\ENGLISH\Fre_m_a_010.wav");		
		break;

		case "wr_solhol":
			PlaySound("VOICE\ENGLISH\Eng_m_c_056.wav");		
		break;

		case "wr_boc3":
			PlaySound("VOICE\ENGLISH\Eng_m_b_055.wav");
		break;

		case "wr_bry1":
			PlaySound("VOICE\ENGLISH\Eng_m_a_066.wav");
		break;

		case "wr_chv1":
			PlaySound("VOICE\ENGLISH\Spa_m_a_029.wav");
		break;

		case "wr_cor1_1":
			PlaySound("VOICE\ENGLISH\Fre_m_a_040.wav");
		break;

		case "wr_cor1_3":
			PlaySound("VOICE\ENGLISH\Eng_m_b_041.wav");
		break;

		case "wr_fsh1":
			PlaySound("VOICE\ENGLISH\Spa_m_b_030.wav");
		break;

		case "wr_fwn":
			PlaySound("VOICE\ENGLISH\Dut_m_a_007.wav");
		break;

		case "wr_kor1":
			PlaySound("VOICE\ENGLISH\Eng_m_b_058.wav");
		break;

		case "wr_man2":
			//bartender
		break;

		case "wr_man3":
			PlaySound("VOICE\ENGLISH\Fre_m_b_012.wav");
		break;

		case "wr_oman2":
			PlaySound("VOICE\ENGLISH\Eng_m_c_061.wav");
		break;

		case "wr_pir5":
			PlaySound("VOICE\ENGLISH\Eng_m_b_061.wav");
		break;

		case "wr_sail1":
			PlaySound("VOICE\ENGLISH\Eng_m_b_054.wav");
		break;

		case "wr_hubport":
			PlaySound("VOICE\ENGLISH\Spa_m_a_033.wav");
		break;

		case "wr_kill":
			PlaySound("VOICE\ENGLISH\Dut_m_a_049.wav");
		break;

		case "wr_18_1":
			PlaySound("VOICE\ENGLISH\por_m_a_007.wav");
		break;

		case "wr_hubspa5":
			PlaySound("VOICE\ENGLISH\Fre_m_c_053.wav");
		break;

		case "wr_solspa4":
			PlaySound("VOICE\ENGLISH\Por_m_a_010.wav");
		break;

		case "wr_vito":
			PlaySound("VOICE\ENGLISH\Dut_m_a_044.wav");
		break;

		case "wr_9SNat":
			PlaySound("VOICE\ENGLISH\Eng_m_a_040.wav");		
		break;

		case "wr_evl2":
			PlaySound("VOICE\ENGLISH\Eng_m_b_012.wav");
		break;

		case "wr_blm":
			PlaySound("VOICE\ENGLISH\Eng_m_c_064.wav");
		break;

		case "wr_Ron":
			PlaySound("VOICE\ENGLISH\Eng_m_b_053.wav");
		break;

		case "wr_ltnorr":
			PlaySound("VOICE\ENGLISH\Dut_m_a_045.wav");
		break;

		case "wr_man4":
			PlaySound("VOICE\ENGLISH\Dut_m_a_054.wav");
		break;

		case "wr_man5_1":
			PlaySound("VOICE\ENGLISH\Dut_m_a_046.wav");
		break;

		case "wr_pir9":
			PlaySound("VOICE\ENGLISH\Fre_m_c_051.wav");
		break;

		case "wr_bucc1":
			PlaySound("VOICE\ENGLISH\Spa_m_a_008.wav");
		break;

		case "wr_boc16":
			PlaySound("VOICE\ENGLISH\Dut_m_a_049.wav");
		break;
	}

	AddDialogExitQuest("wr_crew_dialog_over");
	//LAi_SetGuardianType(NPChar);
	NPChar.dlgover = true;
	DialogExit();
}