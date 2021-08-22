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

			if(NPChar.id == "pir_cap4") PlaySound("VOICE\ENGLISH\pir_capD.wav");//Yeats
			if(NPChar.id == "pir_cap22") PlaySound("VOICE\ENGLISH\pir_capAAA.wav");//Auger

			if(CheckAttribute(Pchar,"quest.pircap_perks") && Pchar.quest.pircap_perks == "start")
			{
				if(CheckAttribute(Pchar,"quest.Bperks") && Pchar.quest.Bperks >= 1)
				{
					if(CheckCharacterPerk(Pchar, "CriticalShoot"))
					{
						if(NPChar.id == "pir_cap4")
						{ 
							//Yeats
							Dialog.text = DLG_TEXT[0];
							link.l1 = DLG_TEXT[1];
							link.l1.go = "exit";
						}
				
						if(NPChar.id == "pir_cap22")
						{ 
							//Auger
							Dialog.text = DLG_TEXT[2];
							link.l1 = DLG_TEXT[3];
							link.l1.go = "exit";
						}	
					}
					else
					{
						if(NPChar.id == "pir_cap4")
						{ 
							//Yeats
							LAi_SetStayType(CharacterFromID("pir_cap4"));
							LAi_SetActorType(CharacterFromID("pir_cap4"));
							LAi_ActorTurnToCharacter(characterFromID("pir_cap4"), Pchar);
						}
				
						if(NPChar.id == "pir_cap22")
						{ 
							//Auger
							LAi_SetStayType(CharacterFromID("pir_cap22"));
							LAi_SetActorType(CharacterFromID("pir_cap22"));
							LAi_ActorTurnToCharacter(characterFromID("pir_cap22"), Pchar);
						}	
					
						if(CheckCharacterPerk(Pchar, "HullDamageUp") && CheckCharacterPerk(Pchar, "SailsDamageUp") && CheckCharacterPerk(Pchar, "CrewDamageUp"))
						{
							Dialog.text = DLG_TEXT[4];
							link.l1 = DLG_TEXT[15];
							link.l1.go = "exit_CriticalShoot";
							link.l2 = DLG_TEXT[16];
							link.l2.go = "exit_no";
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "HullDamageUp") && CheckCharacterPerk(Pchar, "SailsDamageUp"))
							{
								Dialog.text = DLG_TEXT[5];
								link.l1 = DLG_TEXT[15];
								link.l1.go = "exit_CrewDamageUp";
								link.l2 = DLG_TEXT[16];
								link.l2.go = "exit_no";
							}
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "HullDamageUp") && CheckCharacterPerk(Pchar, "CrewDamageUp"))
							{
								Dialog.text = DLG_TEXT[6];
								link.l1 = DLG_TEXT[15];
								link.l1.go = "exit_SailsDamageUp";
								link.l2 = DLG_TEXT[16];
								link.l2.go = "exit_no";
							}
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "SailsDamageUp") && CheckCharacterPerk(Pchar, "CrewDamageUp"))
							{
								Dialog.text = DLG_TEXT[7];
								link.l1 = DLG_TEXT[15];
								link.l1.go = "exit_HullDamageUp";
								link.l2 = DLG_TEXT[16];
								link.l2.go = "exit_no";
							}
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "HullDamageUp"))
							{
								Dialog.text = DLG_TEXT[8];
								link.l1 = DLG_TEXT[13];
								link.l1.go = "exit_SailsDamageUp";
								link.l2 = DLG_TEXT[14];
								link.l2.go = "exit_CrewDamageUp";
								link.l3 = DLG_TEXT[16];
								link.l3.go = "exit_no";
							}
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "SailsDamageUp"))
							{
								Dialog.text = DLG_TEXT[9];
								link.l1 = DLG_TEXT[12];
								link.l1.go = "exit_HullDamageUp";
								link.l2 = DLG_TEXT[14];
								link.l2.go = "exit_CrewDamageUp";
								link.l3 = DLG_TEXT[16];
								link.l3.go = "exit_no";
							}
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "CrewDamageUp"))
							{
								Dialog.text = DLG_TEXT[10];
								link.l1 = DLG_TEXT[12];
								link.l1.go = "exit_HullDamageUp";
								link.l2 = DLG_TEXT[13];
								link.l2.go = "exit_SailsDamageUp";
								link.l3 = DLG_TEXT[16];
								link.l3.go = "exit_no";
							}
						}
						else
						{
							Dialog.text = DLG_TEXT[11];
							link.l1 = DLG_TEXT[12];
							link.l1.go = "exit_HullDamageUp";
							link.l2 = DLG_TEXT[13];
							link.l2.go = "exit_SailsDamageUp";
							link.l3 = DLG_TEXT[14];
							link.l3.go = "exit_CrewDamageUp";
							link.l4 = DLG_TEXT[16];
							link.l4.go = "exit_no";
						}
					}
				}
				else
				{
					if(NPChar.id == "pir_cap4")
					{ 
						//Yeats
						Dialog.text = DLG_TEXT[0];
						link.l1 = DLG_TEXT[1];
						link.l1.go = "exit";
					}
				
					if(NPChar.id == "pir_cap22")
					{ 
						//Auger
						Dialog.text = DLG_TEXT[2];
						link.l1 = DLG_TEXT[3];
						link.l1.go = "exit";
					}	
				}
			}
			else
			{
				if(CheckAttribute(Pchar,"quest.pircap_perks") && Pchar.quest.pircap_perks == "coins_instead")
				{
					if(CheckAttribute(Pchar,"quest.coin_hints") && Pchar.quest.coin_hints == 6)
					{
						Dialog.text = DLG_TEXT[21];
						link.l1 = DLG_TEXT[22];
						link.l1.go = "exit";
					}
					else
					{
						if(CheckAttribute(Pchar,"quest.coin_hint6") && Pchar.quest.coin_hint6 == "noted")
						{
							//both
							Dialog.text = DLG_TEXT[19];
							link.l1 = DLG_TEXT[20];
							link.l1.go = "exit";
						}
						else
						{
							AddQuestRecord("Collection_box", "6");
							Pchar.quest.coin_hint6 = "noted";

							Pchar.quest.coin_hints = makeint(Pchar.quest.coin_hints)+1;
							//LogIt("coin_hints = " + Pchar.quest.coin_hints);

							if(CheckAttribute(Pchar,"quest.coin_hints") && Pchar.quest.coin_hints == 6)
							{
								CloseQuestHeader("Collection_box");
							}

							//both
							Dialog.text = DLG_TEXT[17];
							link.l1 = DLG_TEXT[18];
							link.l1.go = "exit";
						}
					}
				}
			}
			else
			{
				if(NPChar.id == "pir_cap4")
				{ 
					//Yeats
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "exit";
				}
				
				if(NPChar.id == "pir_cap22")
				{ 
					//Auger
					Dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "exit";
				}	
			}
		break;

		case "Exit_HullDamageUp":
			Pchar.perks.list.HullDamageUp = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;

			AddDialogExitQuest("perk_HullDamageUp");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_SailsDamageUp":
			Pchar.perks.list.SailsDamageUp = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;			

			AddDialogExitQuest("perk_SailsDamageUp");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_CrewDamageUp":
			Pchar.perks.list.CrewDamageUp = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;

			AddDialogExitQuest("perk_CrewDamageUp");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_CriticalShoot":
			Pchar.perks.list.CriticalShoot = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;

			AddDialogExitQuest("perk_CriticalShoot");
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
