// JRH fake dialog for mutineers

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

	string guardid;
	guardid = NPChar.id;

	if(NPChar.id == "mutineer_15" || NPChar.id == "mutineer_20" || NPChar.id == "buried_skeleton")
	{

	}
	else
	{
		LAi_SetActorType(NPChar);
		LAi_ActorTurnToCharacter(NPChar, PChar);
	}

	switch(guardid)
	{
		case "buried_skeleton":
			PlaySound("AMBIENT\CRYPT\wind2.wav");
		break;

		case "mutineer_1":
			PlaySound("VOICE\ENGLISH\Spa_m_a_045.wav");
		break;

		case "mutineer_2":
			PlaySound("AMBIENT\TAVERN\GAMBLE\b_loose.wav");
		break;

		case "mutineer_3":
			PlaySound("VOICE\ENGLISH\Desmond Ray Beltrop.wav");
		break;

		case "mutineer_4":
			PlaySound("VOICE\ENGLISH\Por_m_a_028.wav");
		break;

		case "mutineer_5":
			PlaySound("VOICE\ENGLISH\Dut_m_a_033.wav");
		break;

		case "mutineer_6":
			PlaySound("VOICE\ENGLISH\Fre_m_b_040.wav");
		break;

		case "mutineer_7":
			PlaySound("VOICE\ENGLISH\Eng_m_a_053.wav");
		break;

		case "mutineer_8":
			PlaySound("VOICE\ENGLISH\blaze_drunk1.wav");
		break;

		case "mutineer_9":
			PlaySound("VOICE\ENGLISH\Spa_m_a_029.wav");
		break;

		case "mutineer_10":
			PlaySound("VOICE\ENGLISH\Dut_m_a_044.wav");
		break;

		case "mutineer_11":
			PlaySound("VOICE\ENGLISH\Eng_m_a_059.wav");
		break;

		case "mutineer_12":
			PlaySound("VOICE\ENGLISH\guncrew_3.wav");
		break;

		case "mutineer_13":
			PlaySound("VOICE\ENGLISH\Fre_m_a_049.wav");
		break;

		case "mutineer_14":
			PlaySound("VOICE\ENGLISH\Dut_m_a_047.wav");
		break;

		case "mutineer_15":
			PlaySound("VOICE\ENGLISH\Eng_m_b_056.wav");
		break;

		case "mutineer_16":
			PlaySound("VOICE\ENGLISH\Spa_m_b_027.wav");
		break;

		case "mutineer_17":
			PlaySound("AMBIENT\TAVERN\man5.wav");
		break;

		case "mutineer_18":
			PlaySound("VOICE\ENGLISH\Spa_m_a_024.wav");		
		break;

		case "mutineer_19":
			PlaySound("VOICE\ENGLISH\Dut_m_a_049.wav");
		break;

		case "mutineer_20":
			PlaySound("VOICE\ENGLISH\Fre_m_c_052.wav");
		break;

		case "mutineer_21":
			PlaySound("VOICE\ENGLISH\Dut_m_a_070.wav");
		break;

		case "mutineer_22":
			PlaySound("VOICE\ENGLISH\windem_drunk.wav");
		break;

		case "mutineer_23":
			PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
		break;

		case "mutineer_24":
			PlaySound("VOICE\ENGLISH\Dut_m_a_043.wav");
		break;

		case "mutineer_25":
			PlaySound("VOICE\ENGLISH\blaze_drunk2.wav");
		break;

		case "mutineer_26":
			PlaySound("VOICE\ENGLISH\Larry.wav");
		break;

		case "mutineer_27":
			PlaySound("VOICE\ENGLISH\Vassal Bethune.wav");
		break;

		case "mutineer_31":
			PlaySound("VOICE\ENGLISH\Spa_m_a_030.wav");
		break;
	}

	if(Pchar.location == "mutiny_deckWR") { AddDialogExitQuest("mutineer_dialog_over"); }
	DialogExit();
}