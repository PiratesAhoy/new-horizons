//#include "DIALOGS\Arabella's guard_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();


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
			dialog.snd = "Voice\ARGU\ARGU001";

			if(NPChar.id == "pir_cap3") PlaySound("VOICE\ENGLISH\pir_capCCC.wav");//Williams
			if(NPChar.id == "pir_cap20") PlaySound("VOICE\ENGLISH\pir_capJ.wav");//Condent

			if(CheckAttribute(Pchar,"quest.pircap_perks") && Pchar.quest.pircap_perks == "start")
			{
				if(CheckAttribute(Pchar,"quest.Bperks") && Pchar.quest.Bperks >= 1)
				{
					if(CheckCharacterPerk(Pchar, "Trustworthy") && CheckCharacterPerk(Pchar, "BasicLandOwner"))
					{
						//Williams or Condent
						Dialog.text = DLG_TEXT[0];
						link.l1 = DLG_TEXT[1];
						link.l1.go = "exit";	
					}
					else
					{
						if(NPChar.id == "pir_cap3")
						{ 
							LAi_SetStayType(CharacterFromID("pir_cap3"));
							LAi_SetActorType(CharacterFromID("pir_cap3"));
							LAi_ActorTurnToCharacter(characterFromID("pir_cap3"), Pchar);
						}
				
						if(NPChar.id == "pir_cap20")
						{ 
							LAi_SetStayType(CharacterFromID("pir_cap20"));
							LAi_SetActorType(CharacterFromID("pir_cap20"));
							LAi_ActorTurnToCharacter(characterFromID("pir_cap20"), Pchar);
						}

						if(CheckCharacterPerk(Pchar, "AdvancedCommerce") && CheckCharacterPerk(Pchar, "BasicLandOwner"))
						{
							Dialog.text = DLG_TEXT[12];
							link.l1 = DLG_TEXT[17];
							link.l1.go = "exit_Trustworthy";
							link.l2 = DLG_TEXT[18];
							link.l2.go = "exit_no";
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "Trustworthy"))
							{
								Dialog.text = DLG_TEXT[11];
								link.l1 = DLG_TEXT[17];
								link.l1.go = "exit_BasicLandOwner";
								link.l2 = DLG_TEXT[18];
								link.l2.go = "exit_no";
							}
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "AdvancedCommerce"))
							{
								Dialog.text = DLG_TEXT[7];
								link.l1 = DLG_TEXT[15];
								link.l1.go = "exit_BasicLandOwner";
								link.l2 = DLG_TEXT[16];
								link.l2.go = "exit_Trustworthy";
								link.l3 = DLG_TEXT[18];
								link.l3.go = "exit_no";
							}
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "BasicLandOwner"))
							{
								Dialog.text = DLG_TEXT[9];
								link.l1 = DLG_TEXT[13];
								link.l1.go = "exit_AdvancedCommerce";
								link.l2 = DLG_TEXT[18];
								link.l2.go = "exit_no";
							}
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "BasicCommerce"))
							{
								Dialog.text = DLG_TEXT[5];
								link.l1 = DLG_TEXT[13];
								link.l1.go = "exit_AdvancedCommerce";
								link.l2 = DLG_TEXT[15];
								link.l2.go = "exit_BasicLandOwner";
								link.l3 = DLG_TEXT[18];
								link.l3.go = "exit_no";
							}
						}
						else
						{
							Dialog.text = DLG_TEXT[10];
							link.l1 = DLG_TEXT[14];
							link.l1.go = "exit_BasicCommerce";
							link.l2 = DLG_TEXT[18];
							link.l2.go = "exit_no";
						}
					}
				}
				else
				{
					//Williams or Condent
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "exit";	
				}
			}
			else
			{
				if(CheckAttribute(Pchar,"quest.pircap_perks") && Pchar.quest.pircap_perks == "coins_instead")
				{
					if(CheckAttribute(Pchar,"quest.coin_hints") && Pchar.quest.coin_hints == 6)
					{
						Dialog.text = DLG_TEXT[23];
						link.l1 = DLG_TEXT[24];
						link.l1.go = "exit";
					}
					else
					{
						if(CheckAttribute(Pchar,"quest.coin_hint2") && Pchar.quest.coin_hint2 == "noted")
						{
							//both
							Dialog.text = DLG_TEXT[21];
							link.l1 = DLG_TEXT[22];
							link.l1.go = "exit";
						}
						else
						{
							AddQuestRecord("Collection_box", "2");
							Pchar.quest.coin_hint2 = "noted";

							Pchar.quest.coin_hints = makeint(Pchar.quest.coin_hints)+1;
							//LogIt("coin_hints = " + Pchar.quest.coin_hints);

							if(CheckAttribute(Pchar,"quest.coin_hints") && Pchar.quest.coin_hints == 6)
							{
								CloseQuestHeader("Collection_box");
							}

							//both
							Dialog.text = DLG_TEXT[19];
							link.l1 = DLG_TEXT[20];
							link.l1.go = "exit";
						}
					}
				}
			}
			else
			{
				//Williams or Condent
				Dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";	
			}
		break;

		case "Exit_AdvancedCommerce":
			Pchar.perks.list.AdvancedCommerce = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;

			AddDialogExitQuest("perk_AdvancedCommerce");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_BasicLandOwner":
			Pchar.perks.list.BasicLandOwner = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;			

			AddDialogExitQuest("perk_BasicLandOwner");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_Trustworthy":
			Pchar.perks.list.Trustworthy = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;			

			AddDialogExitQuest("perk_Trustworthy");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_BasicCommerce":
			Pchar.perks.list.BasicCommerce = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;			

			AddDialogExitQuest("perk_BasicCommerce");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_no":
			AddDialogExitQuest("reset_pircaps");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
