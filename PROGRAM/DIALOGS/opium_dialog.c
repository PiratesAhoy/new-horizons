//#include "DIALOGS\tavern fightingman_dialog.h"

void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	int PlayerMoney = sti(Pchar.wealth);


	
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
			Dialog.snd = "voice\TAFI\TAFI001";
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "choose_tatt";
			link.l2 = DLG_TEXT[2];
			link.l2.go = "exit";
			
			NextDiag.TempNode = "first time";
		break;

		case "choose_tatt":
			dialog.text = DLG_TEXT[3];
			if(!CheckCharacterItem(Pchar,"tatt1")) // PB: Itemcheck, so you can't get more than one of each tattoo
			{
				link.l1 = DLG_TEXT[4];
				link.l1.go = "tatt1";
			}

			if(!CheckCharacterItem(Pchar,"tatt2")) // PB: Itemcheck, so you can't get more than one of each tattoo
			{
			link.l2 = DLG_TEXT[5];
			link.l2.go = "tatt2";
			}

			if(!CheckCharacterItem(Pchar,"tatt3")) // PB: Itemcheck, so you can't get more than one of each tattoo
			{
				link.l3 = DLG_TEXT[6];
				link.l3.go = "tatt3";
			}

			if(!CheckCharacterItem(Pchar,"tatt4")) // PB: Itemcheck, so you can't get more than one of each tattoo
			{
				link.l4 = DLG_TEXT[7];
				link.l4.go = "tatt4";
			}

			if(!CheckCharacterItem(Pchar,"tatt5")) // PB: Itemcheck, so you can't get more than one of each tattoo
			{
				link.l5 = DLG_TEXT[8];
				link.l5.go = "tatt5";
			}

			if(CheckCharacterItem(Pchar,"tatt1") && CheckCharacterItem(Pchar,"tatt2") && CheckCharacterItem(Pchar,"tatt3") && CheckCharacterItem(Pchar,"tatt4") && CheckCharacterItem(Pchar,"tatt5")) // PB: Itemcheck for when you have all tattoos already
			{
				link.l6 = DLG_TEXT[9];
				link.l6.go = "exit";
			}
			else
			{
				link.l7 = DLG_TEXT[10];
				link.l7.go = "exit";
			}


		break;

		case "tatt1":
			dialog.text = DLG_TEXT[11];
			if(makeint(pchar.wealth) >= 400)
			{
				link.l1 = DLG_TEXT[12];
				if (rand(100) + makeint(pchar.skill.Sneak) >= 45) Link.l1.go = "good_tatt1";
				else Link.l1.go = "bad_tatt1";
			}
			link.l2 = DLG_TEXT[13];
			link.l2.go = "exit";
		break;

		case "good_tatt1":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			pchar.chr_ai.hp_max = sti(pchar.chr_ai.hp_max) - 2;
			LAi_Fade("", "");
			WaitDate("", 0,0,1,0,0);
			if(Pchar.skill.Fencing < 10)// Swindler: not to increase to 11
			{
				Pchar.skill.Fencing = makeint(Pchar.skill.Fencing) + 1;  // Petros to makes this a permanent increase
			}
			RecalculateJumpTable();
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Your new tattoo looks splendid and inspiring!"));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"But it took a bit of life out of you..."));
			Log_SetStringToLog("-2 HP");
			PlayerMoney -= 400;
			PChar.wealth = PlayerMoney;
			GiveItem2Character(Pchar,"tatt1");
		break;

		case "bad_tatt1":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			if(makeint(environment.time) < 22.0 && makeint(environment.time) >= 10.0) TavernWaitDate2("wait_day"); // NK to catch if not night
			TavernWaitDate("wait_day"); // NK so there is a fade
			if(Pchar.skill.Fencing < 10) // Swindler: not to increase to 11
			{
				Pchar.skill.Fencing = makeint(Pchar.skill.Fencing) + 1;  // Petros to makes this a permanent increase
			}
			pchar.chr_ai.poison = 20 + rand(50 -sti(PChar.skill.Sneak) -sti(PChar.skill.defence) );
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
			pchar.chr_ai.hp_max = sti(pchar.chr_ai.hp_max) - 3;
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Your new tattoo looks nice, but..."));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"the infected needle made you sick!"));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Plus the procedure took some life out of you..."));
			Log_SetStringToLog("-3 HP");							
			PlayerMoney -= 400;
			PChar.wealth = PlayerMoney;		
			GiveItem2Character(Pchar,"tatt1");
		break;

		case "tatt2":
			dialog.text = DLG_TEXT[14];
			if(makeint(pchar.wealth) >= 500)
			{
				link.l1 = DLG_TEXT[12];
				if(rand(100) + makeint(pchar.skill.Sneak) >= 45) Link.l1.go = "good_tatt2";
				else Link.l1.go = "bad_tatt2";
			}
			link.l2 = DLG_TEXT[13];
			link.l2.go = "exit";
		break;

		case "good_tatt2":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			pchar.chr_ai.hp_max = sti(pchar.chr_ai.hp_max) - 2;
			LAi_Fade("", "");
			WaitDate("", 0,0,1,0,0);
			if(Pchar.skill.Sailing < 10) // Swindler: not to increase to 11
			{
				Pchar.skill.Sailing = makeint(Pchar.skill.Sailing) + 1;  // Petros to makes this a permanent increase
			}
			RecalculateJumpTable();
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Your new tattoo looks splendid and inspiring!"));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"But it took a bit of life out of you..."));
			Log_SetStringToLog("-2 HP");
			PlayerMoney -= 500;
			PChar.wealth = PlayerMoney;
			GiveItem2Character(Pchar,"tatt2");
		break;

		case "bad_tatt2":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			if (makeint(environment.time) < 22.0 && makeint(environment.time) >= 10.0) TavernWaitDate2("wait_day"); // NK to catch if not night
			TavernWaitDate("wait_day"); // NK so there is a fade
			if(Pchar.skill.Sailing < 10) // Swindler: not to increase to 11
			{
				Pchar.skill.Sailing = makeint(Pchar.skill.Sailing) + 1;  // Petros to makes this a permanent increase
			}
			pchar.chr_ai.poison = 20 + rand(50 -sti(PChar.skill.Sneak) -sti(PChar.skill.defence) );
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
			pchar.chr_ai.hp_max = sti(pchar.chr_ai.hp_max) - 3;
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Your new tattoo looks nice, but..."));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"the infected needle made you sick!"));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Plus the procedure took some life out of you..."));
			Log_SetStringToLog("-3 HP");
			PlayerMoney -= 500;
			PChar.wealth = PlayerMoney;
			GiveItem2Character(Pchar,"tatt2");
		break;

		case "tatt3":
			dialog.text = DLG_TEXT[14];
			if (makeint(pchar.wealth) >= 600)
			{
				link.l1 = DLG_TEXT[12];
				if(rand(100) + makeint(pchar.skill.Sneak) >= 45) Link.l1.go = "good_tatt3";
				else Link.l1.go = "bad_tatt3";
			}
			link.l2 = DLG_TEXT[13];
			link.l2.go = "exit";
		break;

		case "good_tatt3":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			pchar.chr_ai.hp_max = sti(pchar.chr_ai.hp_max) - 2;
			LAi_Fade("", "");
			WaitDate("", 0,0,1,0,0);
			if(Pchar.skill.Leadership < 10) // Swindler: not to increase to 11
			{
				Pchar.skill.Leadership = makeint(Pchar.skill.Leadership) + 1;  // Petros to makes this a permanent increase
			}
			RecalculateJumpTable();
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Your new tattoo looks splendid and inspiring!"));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"But it took a bit of life out of you..."));
			Log_SetStringToLog("-2 HP");
			PlayerMoney -= 600;
			PChar.wealth = PlayerMoney;
			GiveItem2Character(Pchar,"tatt3");
		break;

		case "bad_tatt3":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			if (makeint(environment.time) < 22.0 && makeint(environment.time) >= 10.0) TavernWaitDate2("wait_day"); // NK to catch if not night
			TavernWaitDate("wait_day"); // NK so there is a fade
			if(Pchar.skill.Leadership < 10) // Swindler: not to increase to 11
			{
				Pchar.skill.Leadership = makeint(Pchar.skill.Leadership) + 1;  // Petros to makes this a permanent increase
			}
			pchar.chr_ai.poison = 20 + rand(50 -sti(PChar.skill.Sneak) -sti(PChar.skill.defence) );
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
			pchar.chr_ai.hp_max = sti(pchar.chr_ai.hp_max) - 3;
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Your new tattoo looks nice, but..."));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"the infected needle made you sick!"));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Plus the procedure took some life out of you..."));
			Log_SetStringToLog("-3 HP");
			PlayerMoney -= 600;
			PChar.wealth = PlayerMoney;
			GiveItem2Character(Pchar,"tatt3");
		break;

		case "tatt4":
			dialog.text = DLG_TEXT[14];
			if (makeint(pchar.wealth) >= 700)
			{
				link.l1 = DLG_TEXT[12];
				if (rand(100) + makeint(pchar.skill.Sneak) >= 45) Link.l1.go = "good_tatt4";
				else Link.l1.go = "bad_tatt4";
			}
			link.l2 = DLG_TEXT[13];
			link.l2.go = "exit";
		break;

		case "good_tatt4":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			pchar.chr_ai.hp_max = sti(pchar.chr_ai.hp_max) - 2;
			LAi_Fade("", "");
			WaitDate("", 0,0,1,0,0);
			if (Pchar.skill.Defence < 10) // Swindler: not to increase to 11
			{
				Pchar.skill.Defence = makeint(Pchar.skill.Defence) + 1;  // Petros to makes this a permanent increase
			}
			RecalculateJumpTable();
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Your new tattoo looks splendid and inspiring!"));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"But it took a bit of life out of you..."));
			Log_SetStringToLog("-2 HP");
			PlayerMoney -= 700;
			PChar.wealth = PlayerMoney;
			GiveItem2Character(Pchar,"tatt4");
		break;

		case "bad_tatt4":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			if (makeint(environment.time) < 22.0 && makeint(environment.time) >= 10.0) TavernWaitDate2("wait_day"); // NK to catch if not night
			TavernWaitDate("wait_day"); // NK so there is a fade
			if(Pchar.skill.Defence < 10) // Swindler: not to increase to 11
			{
				Pchar.skill.Defence = makeint(Pchar.skill.Defence) + 1;  // Petros to makes this a permanent increase
			}
			pchar.chr_ai.poison = 20 + rand(50 -sti(PChar.skill.Sneak) -sti(PChar.skill.defence) );
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
			pchar.chr_ai.hp_max = sti(pchar.chr_ai.hp_max) - 3;
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Your new tattoo looks nice, but..."));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"the infected needle made you sick!"));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Plus the procedure took some life out of you..."));
			Log_SetStringToLog("-3 HP");
			PlayerMoney -= 700;
			PChar.wealth = PlayerMoney;
			GiveItem2Character(Pchar,"tatt4");
		break;

		case "tatt5":
			dialog.text = DLG_TEXT[14];
			if (makeint(pchar.wealth) >= 800)
			{
				link.l1 = DLG_TEXT[12];
				if (rand(100) + makeint(pchar.skill.Sneak) >= 45) Link.l1.go = "good_tatt5";
				else Link.l1.go = "bad_tatt5";
			}
			link.l2 = DLG_TEXT[13];
			link.l2.go = "exit";
		break;

		case "good_tatt5":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			pchar.chr_ai.hp_max = sti(pchar.chr_ai.hp_max) - 2;
			LAi_Fade("", "");
			WaitDate("", 0,0,1,0,0);
			if(Pchar.skill.Sneak < 10) // Swindler: not to increase to 11
			{
				Pchar.skill.Sneak = makeint(Pchar.skill.Sneak) + 1;  // Petros to makes this a permanent increase
			}
			RecalculateJumpTable();
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Your new tattoo looks splendid and inspiring!"));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"But it took a bit of life out of you..."));
			Log_SetStringToLog("-2 HP");
			PlayerMoney -= 800;
			PChar.wealth = PlayerMoney;
			GiveItem2Character(Pchar,"tatt5");
		break;

		case "bad_tatt5":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			if (makeint(environment.time) < 22.0 && makeint(environment.time) >= 10.0) TavernWaitDate2("wait_day"); // NK to catch if not night
			TavernWaitDate("wait_day"); // NK so there is a fade
			if(Pchar.skill.Sneak < 10) // Swindler: not to increase to 11
			{
				Pchar.skill.Sneak = makeint(Pchar.skill.Sneak) + 1;  // Petros to makes this a permanent increase
			}
			pchar.chr_ai.poison = 20 + rand(50 -sti(PChar.skill.Sneak) -sti(PChar.skill.defence) );
			PlaySound("AMBIENT\RESIDENCE\some1.wav");
			pchar.chr_ai.hp_max = sti(pchar.chr_ai.hp_max) - 3;
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Your new tattoo looks nice, but..."));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"the infected needle made you sick!"));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Plus the procedure took some life out of you..."));
			Log_SetStringToLog("-3 HP");
			PlayerMoney -= 800;
			PChar.wealth = PlayerMoney;
			GiveItem2Character(Pchar,"tatt5");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
	LanguageCloseFile(tmpLangFileID);
}