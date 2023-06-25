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

			PlaySound("VOICE\ENGLISH\pir_capQ.wav");

			if(CheckAttribute(Pchar,"quest.pircap_perks") && Pchar.quest.pircap_perks == "start")
			{
				if(CheckAttribute(Pchar,"quest.Bperks") && Pchar.quest.Bperks >= 1)
				{
					if(CheckCharacterPerk(Pchar, "SwordplayProfessional"))
					{
						//Low
						Dialog.text = DLG_TEXT[0];
						link.l1 = DLG_TEXT[1];
						link.l1.go = "exit";
					}
					else
					{
						LAi_SetStayType(CharacterFromID("pir_cap9"));
						LAi_SetActorType(CharacterFromID("pir_cap9"));
						LAi_ActorTurnToCharacter(characterFromID("pir_cap9"), Pchar);

						if(CheckCharacterPerk(Pchar, "CriticalHit"))
						{
							if(CheckCharacterPerk(Pchar, "AdvancedDefence"))
							{
								Dialog.text = DLG_TEXT[2];
								link.l1 = DLG_TEXT[10];
								link.l1.go = "exit_SwordplayProfessional";
								link.l2 = DLG_TEXT[11];
								link.l2.go = "exit_no";
							}
							else
							{
								if(CheckCharacterPerk(Pchar, "BasicDefence"))
								{
									Dialog.text = DLG_TEXT[3];
									link.l1 = DLG_TEXT[10];
									link.l1.go = "exit_AdvancedDefence";
									link.l2 = DLG_TEXT[11];
									link.l2.go = "exit_no";
								}
							}
							else
							{
								Dialog.text = DLG_TEXT[4];
								link.l1 = DLG_TEXT[5];
								link.l1.go = "exit_no";
							}
						}
					}
					else
					{
						if(CheckCharacterPerk(Pchar, "AdvancedDefence"))
						{
							Dialog.text = DLG_TEXT[6];
							link.l1 = DLG_TEXT[10];
							link.l1.go = "exit_CriticalHit";
							link.l2 = DLG_TEXT[11];
							link.l2.go = "exit_no";
						}
					}
					else
					{
						if(CheckCharacterPerk(Pchar, "BasicDefence"))
						{
							Dialog.text = DLG_TEXT[7];
							link.l1 = DLG_TEXT[8];
							link.l1.go = "exit_AdvancedDefence";
							link.l2 = DLG_TEXT[9];
							link.l2.go = "exit_CriticalHit";
							link.l3 = DLG_TEXT[11];
							link.l3.go = "exit_no";
						}
					}
					else
					{
						Dialog.text = DLG_TEXT[2];
						link.l1 = DLG_TEXT[10];
						link.l1.go = "exit_CriticalHit";
						link.l2 = DLG_TEXT[11];
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
				if(CheckAttribute(Pchar,"quest.pircap_perks") && Pchar.quest.pircap_perks == "coins_instead")
				{
					if(CheckAttribute(Pchar,"quest.coin_hints") && Pchar.quest.coin_hints == 6)
					{
						Dialog.text = DLG_TEXT[16];
						link.l1 = DLG_TEXT[17];
						link.l1.go = "exit";
					}
					else
					{
						if(CheckAttribute(Pchar,"quest.coin_hint4") && Pchar.quest.coin_hint4 == "noted")
						{
							Dialog.text = DLG_TEXT[14];
							link.l1 = DLG_TEXT[15];
							link.l1.go = "exit";
						}
						else
						{
							AddQuestRecord("Collection_box", "4");
							Pchar.quest.coin_hint4 = "noted";

							Pchar.quest.coin_hints = makeint(Pchar.quest.coin_hints)+1;
							//LogIt("coin_hints = " + Pchar.quest.coin_hints);

							if(CheckAttribute(Pchar,"quest.coin_hints") && Pchar.quest.coin_hints == 6)
							{
								CloseQuestHeader("Collection_box");
							}

							Dialog.text = DLG_TEXT[12];
							link.l1 = DLG_TEXT[13];
							link.l1.go = "exit";
						}
					}
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

		case "Exit_CriticalHit":
			Pchar.perks.list.CriticalHit = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;

			AddDialogExitQuest("perk_CriticalHit");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_SwordplayProfessional":
			Pchar.perks.list.SwordplayProfessional = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;

			AddDialogExitQuest("perk_SwordplayProfessional");
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
