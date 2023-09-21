//#include "DIALOGS\vigila mendes_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

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
		// ----------------------------------- Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			if (npchar.quest.meeting == "0")
			{
				Dialog.snd = "voice\VIME\VIME001";
				dialog.text = DLG_TEXT[0];
				if (npchar.quest.escort == "0")
				{
					link.l1 = pcharrepphrase(DLG_TEXT[1], DLG_TEXT[2]));
					link.l1.go = "node_1";
				}
				else
				{
					link.l1 = pcharrepphrase(DLG_TEXT[3] + GetMyFullName(NPChar) + DLG_TEXT[4], DLG_TEXT[5] + GetMyFullName(NPChar) + DLG_TEXT[6]);
					link.l1.go = "node_3";
				}
				npchar.quest.meeting = "1";
			}
			else
			{
				Dialog.snd = "voice\VIME\VIME002";
				dialog.text = DLG_TEXT[7];
				link.l1 = pcharrepphrase(DLG_TEXT[8], DLG_TEXT[9]);
				link.l1.go = "exit";
				if ((npchar.quest.escort == "0")&&(makeint(pchar.reputation) >= 40))
				{
					Dialog.snd = "voice\VIME\VIME003";
					dialog.text = DLG_TEXT[10];
					link.l1 = DLG_TEXT[11];
					link.l1.go = "talk_2";
				}
				if (npchar.quest.escort == "1")
				{
					link.l1 = pcharrepphrase(DLG_TEXT[12], DLG_TEXT[13]);
					link.l1.go = "talk_3";
				}
				if ((npchar.quest.escort == "begin")&&(npchar.location == "Falaise_de_Fleur_store"))
				{
					Dialog.snd = "voice\VIME\VIME004";
					dialog.text = DLG_TEXT[14];
					link.l1 = pcharrepphrase(DLG_TEXT[15], DLG_TEXT[16]);
					link.l1.go = "talk_5";
				}
				if ((npchar.quest.escort == "end")&&(npchar.location == "Muelle_store"))
				{
					Dialog.snd = "voice\VIME\VIME005";
					dialog.text = DLG_TEXT[17] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[18];
					link.l1 = pcharrepphrase(DLG_TEXT[19], DLG_TEXT[20]);
					link.l1.go = "talk_6";
				}
			}
			NextDiag.TempNode = "First time";
		break;

		case "node_1":
			Dialog.snd = "voice\VIME\VIME006";
			dialog.text = DLG_TEXT[21] + GetMyFullName(NPChar) + DLG_TEXT[22];
			link.l1 = pcharrepphrase(DLG_TEXT[23] + GetMyFullName(PChar) + DLG_TEXT[24], DLG_TEXT[25] + GetMyName(Pchar) + DLG_TEXT[26] + GetMyFullName(PChar) + DLG_TEXT[27]);
			link.l1.go = "node_2";
		break;

		case "node_2":
			Dialog.snd = "voice\VIME\VIME007";
			dialog.text = DLG_TEXT[28];
			link.l1 = pcharrepphrase(DLG_TEXT[29], DLG_TEXT[30]);
			link.l1.go = "talk_1";
			link.l2 = pcharrepphrase(DLG_TEXT[31] + GetMyName(NPChar) + DLG_TEXT[32], DLG_TEXT[33]);
			link.l2.go = "exit";
		break;

		case "node_3":
			Dialog.snd = "voice\VIME\VIME008";
			dialog.text = DLG_TEXT[34];
			link.l1 = pcharrepphrase(DLG_TEXT[35] + GetMyFullName(PChar) + DLG_TEXT[36], DLG_TEXT[37]);
			link.l1.go = "talk_3";
		break;

		case "talk_1":
			if (makeint(pchar.reputation) < 40)
			{
				Dialog.snd = "voice\VIME\VIME009";
				dialog.text = DLG_TEXT[38] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[39];
				link.l1 = pcharrepphrase(DLG_TEXT[40], DLG_TEXT[41]);
				link.l1.go = "exit"; // 05-02-02 A_S
			} else { 
				dialog.text = DLG_TEXT[42];
				link.l1 = DLG_TEXT[43];
				link.l1.go = "talk_2";
			}
		break;

		case "talk_2":
			Dialog.snd = "voice\VIME\VIME011";
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "talk_3";
		break;

		// BEGIN Swindler 2006-07-01: Rewritten, so that Vigila Mendes
		// doesn't offer escort job when PChar has no free slot for
		// ship. Instead he gives advise.
		case "talk_3":
			Dialog.snd = "voice\VIME\VIME012";
			if (GetCompanionIndex(pchar,1) != -1 && GetCompanionIndex(pchar,2) != -1 && GetCompanionIndex(pchar,3) != -1)
			{
				Dialog.text = DLG_TEXT[74];
				link.l1 = PCharRepPhrase(DLG_TEXT[75], RandSwear() + DLG_TEXT[76]);
				link.l1.go = "Exit";				
			}
			else
			{
				dialog.text = DLG_TEXT[46];
				link.l1 = pcharrepphrase(DLG_TEXT[47], DLG_TEXT[48]);
				link.l1.go = "talk_4";
				
				if (CalcCharacterSkill(pchar, SKILL_COMMERCE) > 4)
				{
					link.l2 = pcharrepphrase(DLG_TEXT[49], DLG_TEXT[50]);
					link.l2.go = "money";
				}
				link.l3 = pcharrepphrase(DLG_TEXT[51], DLG_TEXT[52]);
				link.l3.go = "talk_exit";
				npchar.money.quest = 2500;
			}			
		break;
		// END Swindler

		case "talk_4":
			Dialog.snd = "voice\VIME\VIME013";
			dialog.text = DLG_TEXT[53];
			link.l1 = pcharrepphrase(DLG_TEXT[54], DLG_TEXT[55]);
			link.l1.go = "exit";
			npchar.quest.escort = "begin";
			AddDialogExitQuest("Mendes_go_away_from_muelle_store");
			SetQuestHeader("mendes");
			AddQuestRecord("mendes", 1);
		break;

		case "talk_5":
			Dialog.snd = "voice\VIME\VIME014";
			dialog.text = DLG_TEXT[56];
			link.l1 = pcharrepphrase(DLG_TEXT[57], DLG_TEXT[58]);
			link.l1.go = "exit";
			AddDialogExitQuest("Mendes_go_away_from_falaise_de_fleur_store");

			npchar.money.quest = makeint(npchar.money.quest)/2;
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, makeint(npchar.money.quest));
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 15);
			}
			else { AddPartyExp(pchar, 1500); }
			npchar.quest.escort = "end";
			AddQuestRecord("mendes", 2);
		break;

		case "talk_6":
			Dialog.snd = "voice\VIME\VIME015";
			dialog.text = DLG_TEXT[59] + GetCharacterFullName(DLG_TEXT[60]) + DLG_TEXT[61];
			link.l1 = pcharrepphrase(DLG_TEXT[62], DLG_TEXT[63]);
			link.l1.go = "exit";
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, makeint(npchar.money.quest));
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1800);
				AddPartyExpChar(pchar, "Sneak", 18);
			}
			else { AddPartyExp(pchar, 1800); }
			RemoveCharacterCompanion(pchar, npchar);
			npchar.quest.escort = "done";
			npchar.money.quest = 0;
			ChangeCharacterAddress(CharacterFromID("Zaid Murro"), "Muelle_port", "character6");
			pchar.quest.death_of_vigila_mendes.over = "yes";
			AddQuestRecord("mendes", 3);
			CloseQuestHeader("mendes");
			AddDialogExitQuest("mendes_away_forewer");
		break;

		case "money":
			Dialog.snd = "voice\VIME\VIME016";
			dialog.text = DLG_TEXT[64] + (2500 + CalcCharacterSkill(pchar, DLG_TEXT[65])*100) + DLG_TEXT[66];
			link.l1 = pcharrepphrase(DLG_TEXT[67], DLG_TEXT[68]);
			link.l1.go = "talk_4";
			link.l2 = pcharrepphrase(DLG_TEXT[69], DLG_TEXT[70]);
			link.l2.go = "talk_exit";
			npchar.money.quest = 2500 + CalcCharacterSkill(pchar, SKILL_COMMERCE)*100;
		break;

		case "talk_exit":
			Dialog.snd = "voice\VIME\VIME017";
			dialog.text = DLG_TEXT[71];
			link.l1 = pcharrepphrase(DLG_TEXT[72], DLG_TEXT[73]);
			link.l1.go = "exit";
			npchar.quest.escort = "done";
			npchar.money.quest = 0;
			npchar.location = "none";
		break;
					
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
