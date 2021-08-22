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

			PlaySound("VOICE\ENGLISH\pir_capF.wav");

			if(CheckAttribute(Pchar,"quest.pircap_perks") && Pchar.quest.pircap_perks == "start")
			{
				if(CheckAttribute(Pchar,"quest.Bperks") && Pchar.quest.Bperks >= 1)
				{
					if(CheckCharacterPerk(Pchar, "Toughness") && CheckCharacterPerk(Pchar, "Rush"))
					{
						//Bunce
						Dialog.text = DLG_TEXT[0];
						link.l1 = DLG_TEXT[1];
						link.l1.go = "exit";
					}
					else
					{
						LAi_SetStayType(CharacterFromID("pir_cap10"));
						LAi_SetActorType(CharacterFromID("pir_cap10"));
						LAi_ActorTurnToCharacter(characterFromID("pir_cap10"), Pchar);

						if(CheckCharacterPerk(Pchar, "Toughness"))
						{
							Dialog.text = DLG_TEXT[6];
							link.l1 = DLG_TEXT[12];
							link.l1.go = "exit_Rush";
							link.l2 = DLG_TEXT[13];
							link.l2.go = "exit_no";
	
						}
					}
					else
					{
						if(CheckCharacterPerk(Pchar, "Rush") && CheckCharacterPerk(Pchar, "AdvancedDefence"))
						{
							Dialog.text = DLG_TEXT[2];
							link.l1 = DLG_TEXT[12];
							link.l1.go = "exit_Toughness";
							link.l2 = DLG_TEXT[13];
							link.l2.go = "exit_no";
						}
					}
					else
					{
						if(CheckCharacterPerk(Pchar, "Rush") && CheckCharacterPerk(Pchar, "BasicDefence"))
						{
							Dialog.text = DLG_TEXT[3];
							link.l1 = DLG_TEXT[12];
							link.l1.go = "exit_AdvancedDefence";
							link.l2 = DLG_TEXT[13];
							link.l2.go = "exit_no";
						}
					}
					else
					{
						if(CheckCharacterPerk(Pchar, "Rush"))
						{
							Dialog.text = DLG_TEXT[4];
							link.l1 = DLG_TEXT[5];
							link.l1.go = "exit_no";
						}
					}
					else
					{
						if(CheckCharacterPerk(Pchar, "AdvancedDefence"))
						{
							Dialog.text = DLG_TEXT[7];
							link.l1 = DLG_TEXT[10];
							link.l1.go = "exit_Toughness";
							link.l2 = DLG_TEXT[11];
							link.l2.go = "exit_Rush";
							link.l3 = DLG_TEXT[13];
							link.l3.go = "exit_no";
						}
					}
					else
					{
						if(CheckCharacterPerk(Pchar, "BasicDefence"))
						{
							Dialog.text = DLG_TEXT[8];
							link.l1 = DLG_TEXT[9];
							link.l1.go = "exit_AdvancedDefence";
							link.l2 = DLG_TEXT[11];
							link.l2.go = "exit_Rush";
							link.l3 = DLG_TEXT[13];
							link.l3.go = "exit_no";
						}
					}
					else
					{
						Dialog.text = DLG_TEXT[6];
						link.l1 = DLG_TEXT[12];
						link.l1.go = "exit_Rush";
						link.l2 = DLG_TEXT[13];
						link.l2.go = "exit_no";
					}	
				}
				else
				{
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "exit";
				}
			}
			else
			{
				if(CheckAttribute(Pchar, "quest.Bunce") && Pchar.quest.Bunce == "on_shore")
				{
					//Bunce
					Dialog.text = DLG_TEXT[14];
					link.l1 = DLG_TEXT[13];
					link.l1.go = "exit";
				}
			}
			else
			{
				Dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}
		break;

		case "Exit_AdvancedDefence":
			Pchar.perks.list.AdvancedDefence = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;	
		
			AddDialogExitQuest("perk_AdvancedDefence");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_Toughness":
			Pchar.perks.list.Toughness = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;

			AddDialogExitQuest("perk_Toughness");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_Rush":
			Pchar.perks.list.Rush = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;

			AddDialogExitQuest("perk_Rush");
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
