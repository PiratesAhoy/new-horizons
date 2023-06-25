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

			if(NPChar.id == "pir_cap2") PlaySound("VOICE\ENGLISH\pir_capEE.wav");//Bellamy
			if(NPChar.id == "pir_cap7") PlaySound("VOICE\ENGLISH\pir_capP.wav");//Anstis
			if(NPChar.id == "pir_cap14") PlaySound("VOICE\ENGLISH\pir_capT.wav");//Kennedy

			if(CheckAttribute(Pchar,"quest.pircap_perks") && Pchar.quest.pircap_perks == "start")
			{
				if(CheckAttribute(Pchar,"quest.Bperks") && Pchar.quest.Bperks >= 1)
				{
					if(CheckCharacterPerk(Pchar, "SailingProfessional"))
					{
						if(NPChar.id == "pir_cap2")
						{ 
							//Bellamy
							Dialog.text = DLG_TEXT[0];
							link.l1 = DLG_TEXT[1];
							link.l1.go = "exit";
						}

						if(NPChar.id == "pir_cap7")
						{ 
							//Anstis
							Dialog.text = DLG_TEXT[2];
							link.l1 = DLG_TEXT[3];
							link.l1.go = "exit";
						}
				
						if(NPChar.id == "pir_cap14")
						{ 
							//Kennedy
							Dialog.text = DLG_TEXT[4];
							link.l1 = DLG_TEXT[5];
							link.l1.go = "exit";
						}	
					}
					else
					{
						if(NPChar.id == "pir_cap2")
						{ 
							LAi_SetStayType(CharacterFromID("pir_cap2"));
							LAi_SetActorType(CharacterFromID("pir_cap2"));
							LAi_ActorTurnToCharacter(characterFromID("pir_cap2"), Pchar);
						}
					
						if(NPChar.id == "pir_cap7")
						{ 
							LAi_SetStayType(CharacterFromID("pir_cap7"));
							LAi_SetActorType(CharacterFromID("pir_cap7"));
							LAi_ActorTurnToCharacter(characterFromID("pir_cap7"), Pchar);
						}
				
						if(NPChar.id == "pir_cap14")
						{ 
							LAi_SetStayType(CharacterFromID("pir_cap14"));
							LAi_SetActorType(CharacterFromID("pir_cap14"));
							LAi_ActorTurnToCharacter(characterFromID("pir_cap14"), Pchar);
						}

						if(CheckCharacterPerk(Pchar, "SandbankManeuver"))
						{
							if(CheckCharacterPerk(Pchar, "StormProfessional"))
							{
								Dialog.text = DLG_TEXT[6];
								link.l1 = DLG_TEXT[20];
								link.l1.go = "SailingProfessional";
								link.l2 = DLG_TEXT[21];
								link.l2.go = "exit_no";
							}
							else
							{
								Dialog.text = DLG_TEXT[7];
								link.l1 = DLG_TEXT[20];
								link.l1.go = "exit_StormProfessional";
								link.l2 = DLG_TEXT[21];
								link.l2.go = "exit_no";
							}
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "Turn180"))
							{
								if(CheckCharacterPerk(Pchar, "StormProfessional"))
								{
									Dialog.text = DLG_TEXT[8];
									link.l1 = DLG_TEXT[20];
									link.l1.go = "exit_SandbankManeuver";
									link.l2 = DLG_TEXT[21];
									link.l2.go = "exit_no";
								}
								else
								{
									Dialog.text = DLG_TEXT[11];
									link.l1 = DLG_TEXT[16];
									link.l1.go = "exit_SandbankManeuver";
									link.l2 = DLG_TEXT[17];
									link.l2.go = "exit_StormProfessional";
									link.l3 = DLG_TEXT[21];
									link.l3.go = "exit_no";
								}
							}
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "ShipSpeedUp") && CheckCharacterPerk(Pchar, "ShipTurnRateUp"))
							{
								if(CheckCharacterPerk(Pchar, "StormProfessional"))
								{
									Dialog.text = DLG_TEXT[22];
									link.l1 = DLG_TEXT[20];
									link.l1.go = "exit_Turn180";
									link.l2 = DLG_TEXT[21];
									link.l2.go = "exit_no";
								}
								else
								{
									Dialog.text = DLG_TEXT[23];
									link.l1 = DLG_TEXT[24];
									link.l1.go = "exit_Turn180";
									link.l2 = DLG_TEXT[17];
									link.l2.go = "exit_StormProfessional";
									link.l3 = DLG_TEXT[21];
									link.l3.go = "exit_no";
								}
							}
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "ShipSpeedUp"))
							{
								if(CheckCharacterPerk(Pchar, "StormProfessional"))
								{
									Dialog.text = DLG_TEXT[10];
									link.l1 = DLG_TEXT[20];
									link.l1.go = "exit_ShipTurnRateUp";
									link.l2 = DLG_TEXT[21];
									link.l2.go = "exit_no";
								}
								else
								{
									Dialog.text = DLG_TEXT[13];
									link.l1 = DLG_TEXT[19];
									link.l1.go = "exit_ShipTurnRateUp";
									link.l2 = DLG_TEXT[17];
									link.l2.go = "exit_StormProfessional";
									link.l3 = DLG_TEXT[21];
									link.l3.go = "exit_no";
								}
							}
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "ShipTurnRateUp"))
							{
								if(CheckCharacterPerk(Pchar, "StormProfessional"))
								{
									Dialog.text = DLG_TEXT[9];
									link.l1 = DLG_TEXT[20];
									link.l1.go = "exit_ShipSpeedUp";
									link.l2 = DLG_TEXT[21];
									link.l2.go = "exit_no";
								}
								else
								{
									Dialog.text = DLG_TEXT[12];
									link.l1 = DLG_TEXT[18];
									link.l1.go = "exit_ShipSpeedUp";
									link.l2 = DLG_TEXT[17];
									link.l2.go = "exit_StormProfessional";
									link.l3 = DLG_TEXT[21];
									link.l3.go = "exit_no";
								}
							}
						}
						else
						{
							if(CheckCharacterPerk(Pchar, "StormProfessional"))
							{
								Dialog.text = DLG_TEXT[14];
								link.l1 = DLG_TEXT[18];
								link.l1.go = "exit_ShipSpeedUp";
								link.l2 = DLG_TEXT[19];
								link.l2.go = "exit_ShipTurnRateUp";
								link.l3 = DLG_TEXT[21];
								link.l3.go = "exit_no";
							}
						}
						else
						{
							Dialog.text = DLG_TEXT[15];
							link.l1 = DLG_TEXT[18];
							link.l1.go = "exit_ShipSpeedUp";
							link.l2 = DLG_TEXT[19];
							link.l2.go = "exit_ShipTurnRateUp";
							link.l3 = DLG_TEXT[17];
							link.l3.go = "exit_StormProfessional";
							link.l4 = DLG_TEXT[21];
							link.l4.go = "exit_no";
						}
					}
				}
				else
				{
					if(NPChar.id == "pir_cap2")
					{ 
						//Bellamy
						Dialog.text = DLG_TEXT[0];
						link.l1 = DLG_TEXT[1];
						link.l1.go = "exit";
					}

					if(NPChar.id == "pir_cap7")
					{ 
						//Anstis
						Dialog.text = DLG_TEXT[2];
						link.l1 = DLG_TEXT[3];
						link.l1.go = "exit";
					}
				
					if(NPChar.id == "pir_cap14")
					{ 
						//Kennedy
						Dialog.text = DLG_TEXT[4];
						link.l1 = DLG_TEXT[5];
						link.l1.go = "exit";
					}	
				}
			}
			else
			{
				if(NPChar.id == "pir_cap2")
				{ 
					//Bellamy
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "exit";
				}

				if(NPChar.id == "pir_cap7")
				{ 
					//Anstis
					Dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "exit";
				}
				
				if(NPChar.id == "pir_cap14")
				{ 
					//Kennedy
					Dialog.text = DLG_TEXT[4];
					link.l1 = DLG_TEXT[5];
					link.l1.go = "exit";
				}	
			}
		break;

		case "Exit_ShipSpeedUp":
			Pchar.perks.list.ShipSpeedUp = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;

			AddDialogExitQuest("perk_ShipSpeedUp");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_ShipTurnRateUp":
			Pchar.perks.list.ShipTurnRateUp = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;			

			AddDialogExitQuest("perk_ShipTurnRateUp");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_StormProfessional":
			Pchar.perks.list.StormProfessional = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;

			AddDialogExitQuest("perk_StormProfessional");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_Turn180":
			Pchar.perks.list.Turn180 = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;			

			AddDialogExitQuest("perk_Turn180");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_SandbankManeuver":
			Pchar.perks.list.SandbankManeuver = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;			

			AddDialogExitQuest("perk_SandbankManeuver");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_SailingProfessional":
			Pchar.perks.list.SailingProfessional = true;
			Pchar.quest.Bperks = makeint(Pchar.quest.Bperks)-1;			

			AddDialogExitQuest("perk_SailingProfessional");
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
