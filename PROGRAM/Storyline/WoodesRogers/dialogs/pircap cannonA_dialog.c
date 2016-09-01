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

			PlaySound("VOICE\ENGLISH\pir_capI.wav");

			if(CheckAttribute(Pchar,"quest.pircap_perks") && Pchar.quest.pircap_perks == "start")
			{
				if(CheckAttribute(Pchar,"quest.Bperks") && Pchar.quest.Bperks >= 1)
				{
					if(CheckCharacterPerk(Pchar, "CannonProfessional"))
					{
						//Spriggs
						Dialog.text = DLG_TEXT[0];
						link.l1 = DLG_TEXT[1];
						link.l1.go = "exit";	
					}
					else
					{
						LAi_SetStayType(CharacterFromID("pir_cap24"));
						LAi_SetActorType(CharacterFromID("pir_cap24"));
						LAi_ActorTurnToCharacter(characterFromID("pir_cap24"), Pchar);

						if(CheckCharacterPerk(Pchar, "LongRangeShoot") && CheckCharacterPerk(Pchar, "CriticalShoot") && CheckCharacterPerk(Pchar, "FastReload"))
						{
							Dialog.text = DLG_TEXT[2];
							link.l1 = DLG_TEXT[10];
							link.l1.go = "exit_CannonProfessional";
							link.l2 = DLG_TEXT[11];
							link.l2.go = "exit_no";
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "LongRangeShoot") && CheckCharacterPerk(Pchar, "CriticalShoot"))
							{
								Dialog.text = DLG_TEXT[4];
								link.l1 = DLG_TEXT[10];
								link.l1.go = "exit_FastReload";
								link.l2 = DLG_TEXT[11];
								link.l2.go = "exit_no";
							}
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "LongRangeShoot") && CheckCharacterPerk(Pchar, "FastReload"))
							{
								Dialog.text = DLG_TEXT[5];
								link.l1 = DLG_TEXT[6];
								link.l1.go = "exit_no";
							}
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "CriticalShoot") && CheckCharacterPerk(Pchar, "FastReload"))
							{
								Dialog.text = DLG_TEXT[3];
								link.l1 = DLG_TEXT[10];
								link.l1.go = "exit_LongRangeShoot";
								link.l2 = DLG_TEXT[11];
								link.l2.go = "exit_no";
							}
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "LongRangeShoot"))
							{
								Dialog.text = DLG_TEXT[4];
								link.l1 = DLG_TEXT[10];
								link.l1.go = "exit_LongRangeShoot";
								link.l2 = DLG_TEXT[11];
								link.l2.go = "exit_no";
							}
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "CriticalShoot"))
							{
								Dialog.text = DLG_TEXT[7];
								link.l1 = DLG_TEXT[8];
								link.l1.go = "exit_LongRangeShoot";
								link.l2 = DLG_TEXT[9];
								link.l2.go = "exit_FastReload";
								link.l3 = DLG_TEXT[11];
								link.l3.go = "exit_no";
							}
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "FastReload"))
							{
								Dialog.text = DLG_TEXT[3];
								link.l1 = DLG_TEXT[10];
								link.l1.go = "exit_LongRangeShoot";
								link.l2 = DLG_TEXT[11];
								link.l2.go = "exit_no";
							}
						}
						else
						{
							Dialog.text = DLG_TEXT[7];
							link.l1 = DLG_TEXT[8];
							link.l1.go = "exit_LongRangeShoot";
							link.l2 = DLG_TEXT[9];
							link.l2.go = "exit_FastReload";
							link.l3 = DLG_TEXT[11];
							link.l3.go = "exit_no";
						}
					}
				}
				else
				{
					//Spriggs
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "exit";	
				}
			}
			else
			{
				if(CheckAttribute(Pchar, "quest.Spriggs") && Pchar.quest.Spriggs == "on_shore")
				{
					//Spriggs
					Dialog.text = DLG_TEXT[12];
					link.l1 = DLG_TEXT[11];
					link.l1.go = "exit";
				}
			}
			else
			{
				//Spriggs
				Dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";	
			}
		break;

		case "Exit_CannonProfessional":
			Pchar.perks.list.CannonProfessional = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;

			AddDialogExitQuest("perk_CannonProfessional");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_LongRangeShoot":
			Pchar.perks.list.LongRangeShoot = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;			

			AddDialogExitQuest("perk_LongRangeShoot");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_FastReload":
			Pchar.perks.list.FastReload = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;

			AddDialogExitQuest("perk_FastReload");
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
