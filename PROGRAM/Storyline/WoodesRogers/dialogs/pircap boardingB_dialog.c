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

			PlaySound("VOICE\ENGLISH\pir_capFFF.wav");

			if(CheckAttribute(Pchar,"quest.pircap_perks") && Pchar.quest.pircap_perks == "start")
			{
				if(CheckAttribute(Pchar,"quest.Bperks") && Pchar.quest.Bperks >= 1)
				{
					if(CheckCharacterPerk(Pchar, "MusketsShoot"))
					{
						//Winter
						Dialog.text = DLG_TEXT[0];
						link.l1 = DLG_TEXT[1];
						link.l1.go = "exit";
					}
					else
					{
						LAi_SetStayType(CharacterFromID("pir_cap21"));
						LAi_SetActorType(CharacterFromID("pir_cap21"));
						LAi_ActorTurnToCharacter(characterFromID("pir_cap21"), Pchar);
						
						if(CheckCharacterPerk(Pchar, "LongRangeGrappling"))
						{
							if(CheckCharacterPerk(Pchar, "GunProfessional"))
							{
								Dialog.text = DLG_TEXT[2];
								link.l1 = DLG_TEXT[6];
								link.l1.go = "exit_MusketsShoot";
								link.l2 = DLG_TEXT[7];
								link.l2.go = "exit_no";
							}
							else
							{
								Dialog.text = DLG_TEXT[3];
								link.l1 = DLG_TEXT[4];
								link.l1.go = "exit_no";		//for reset reason
							}
						}
						else
						{
							Dialog.text = DLG_TEXT[5];
							link.l1 = DLG_TEXT[6];
							link.l1.go = "exit_LongRangeGrappling";
							link.l2 = DLG_TEXT[7];
							link.l2.go = "exit_no";
						}
					}
				}
				else
				{
					//Winter
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "exit";
				}
			}
			else
			{
				if(CheckAttribute(Pchar, "quest.Winter") && Pchar.quest.Winter == "on_shore")
				{
					//Winter
					Dialog.text = DLG_TEXT[8];
					link.l1 = DLG_TEXT[7];
					link.l1.go = "exit";
				}
			}
			else
			{
				//Winter
				Dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}
		break;

		case "Exit_LongRangeGrappling":
			Pchar.perks.list.LongRangeGrappling = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;

			AddDialogExitQuest("perk_LongRangeGrappling");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_MusketsShoot":
			Pchar.perks.list.MusketsShoot = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;			

			AddDialogExitQuest("perk_MusketsShoot");
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
