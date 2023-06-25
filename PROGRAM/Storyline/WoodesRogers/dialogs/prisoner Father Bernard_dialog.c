//#include "DIALOGS\prisoner Father Bernard_dialog.h"

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

			PlaySound("VOICE\ENGLISH\Eng_m_a_073.wav");

			if (Pchar.location == "wr_chapel")
			{
				Dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}
			else
			{
				if (Pchar.location == "Redmond_church")
				{
					Dialog.text = DLG_TEXT[28];
					link.l1 = DLG_TEXT[27];
					link.l1.go = "exit";
				}
			}
			else
			{
				Dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit";
			}

			Diag.TempNode = "first time";
		break;
	
		case "music":
			PlaySound("VOICE\ENGLISH\Eng_m_a_075.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "music1";
		break;
	
		case "music1":
			PlaySound("VOICE\ENGLISH\Eng_m_a_072.wav");
			PlaySound("VOICE\ENGLISH\Eng_m_a_072.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			if(CheckCharacterItem(Pchar,"blade1") || CheckCharacterItem(Pchar,"pistol2"))
			{
				link.l1.go = "music2";
			}
			else link.l1.go = "music4";
		break;
	
		case "music2":
			//weapons 1
			PlaySound("VOICE\ENGLISH\Eng_m_a_073.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "music3";
		break;

		case "music3":
			//weapons 2
			TakeNItems(Pchar,"blade1-2", -8);
			TakeNItems(Pchar,"pistol2", -8);
			if(!IsEquipCharacterByItem(Pchar, "pistol20"))
			{
				RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE); 
				EquipCharacterbyItem(Pchar, "pistol20");
				TakeItemFromCharacter(Pchar, "ammobag1");
				GiveItem2Character(Pchar, "ammobag2");
				EquipCharacterbyItem(Pchar, "ammobag2");
			}
			PlaySound("OBJECTS\DUEL\sword_fallen.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "music4";
		break;
	
		case "music4":
			//both
			PlaySound("VOICE\ENGLISH\Eng_m_a_074.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "music4_sample";
		//	link.l1.go = "music5";
		break;




		case "music4_sample":
			//both

			Dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "music5";


			PlaySound("PEOPLE\clothes1.wav");
			if(IsEquipCharacterByItem(Pchar, "ammobag2"))
			{
				SetModel(PChar, "PriestRedM_a", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
			}
			else
			{
				if(IsEquipCharacterByItem(Pchar, "pistol20"))
				{
					SetModel(PChar, "PriestRedM_b", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				}
			}
			else
			{
				SetModel(PChar, "PriestRedM", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
			}
		break;








		case "music5":
			//both
			PlaySound("VOICE\ENGLISH\Eng_m_a_076.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			AddDialogExitQuest("choir_search_violin");
			Diag.TempNode = "music5_repeat";
		break;
	
		case "music5_repeat":
			PlaySound("VOICE\ENGLISH\Eng_m_a_076.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			Diag.TempNode = "music5_repeat";
		break;
	
		case "crypt":
			PlaySound("VOICE\ENGLISH\Eng_m_a_072.wav");
			PlaySound("VOICE\ENGLISH\Eng_m_a_072.wav");
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			if(CheckCharacterItem(Pchar,"fake_chalice") || CheckCharacterItem(Pchar,"fake_censer")
			|| CheckCharacterItem(Pchar,"jewelcross") || CheckCharacterItem(Pchar,"fake_reliquary") 
			|| CheckCharacterItem(Pchar,"fake_candelabre"))
			{
				link.l1.go = "crypt0";
			}
			else 
			{
				link.l1.go = "exit";
				AddDialogExitQuest("not_ready_for_crypt_yet");
			}
		break;
	//.................................................................
		case "crypt0":
			PlaySound("INTERFACE\coins8.wav");
			int gold;
			gold = GetCharacterMoney(Pchar);
			AddMoneyToCharacter(Pchar,-gold);

			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "crypt2";
		break;
	
		case "crypt1":
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "crypt2";
		break;
	//.................................................................
		case "crypt2":
			PlaySound("VOICE\ENGLISH\Eng_m_a_074.wav");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "crypt3";
		break;

		case "crypt3":
			PlaySound("VOICE\ENGLISH\Eng_m_a_077.wav");
			Dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "crypt4";
		break;

		case "crypt4":
			PlaySound("VOICE\ENGLISH\Eng_m_a_078.wav");
			Dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "crypt5";
		break;

		case "crypt5":
			PlaySound("VOICE\ENGLISH\Eng_m_a_076.wav");
			Dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			AddDialogExitQuest("ready_for_crypt");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
