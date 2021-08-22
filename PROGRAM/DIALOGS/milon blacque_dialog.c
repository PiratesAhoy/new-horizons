//#include "DIALOGS\milon blacque_dialog.h"
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
			Dialog.snd = "voice\MIBL\MIBL001";

			Dialog.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
			Link.l1 = DLG_TEXT[2] + GetMyShipNameShow(PChar) + DLG_TEXT[3];
			Link.l1.go = "node_2";
			NPChar.quest.first_talk = "1";
			NextDiag.TempNode = "Second time";
		break;

		case "node_2":
			Dialog.snd = "voice\MIBL\MIBL002";
			Dialog.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "node_3";
		break;

		case "node_3":
			Dialog.snd = "voice\MIBL\MIBL003";
			Dialog.Text = DLG_TEXT[6];
			// NK -->
			Preprocessor_AddQuestData("Blacque", GetMyLastName(CharacterFromID("Marc Blacque")));
			Preprocessor_AddQuestData("Milon Blacque", GetMyFullName(NPChar));
			SetQuestHeader("Blacques");
			AddQuestRecord("Blacques", 2);
			Preprocessor_Remove("Milon Blacque");
			Preprocessor_Remove("Blacque");
			// NK <--
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "Exit";
		break;

		case "Second Time":
			Dialog.snd = "voice\MIBL\MIBL004";
			Dialog.text = DLG_TEXT[8] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[9];
			if (Npchar.quest.son == "letter")
			{
				link.l1 = DLG_TEXT[10];
				link.l1.go = "letter";
			}
			else 
			{
				if (Npchar.quest.son == "rescue")
				{
					link.l1 = pcharrepphrase(DLG_TEXT[11], DLG_TEXT[12]);
					link.l1.go = "rescue";
				}
				else
				{
					link.l1 = DLG_TEXT[13];
					link.l1.go = "exit";
				}
			}
			link.l2 = DLG_TEXT[14];
			link.l2.go = "exit";
		break;

		case "letter":
			Dialog.snd = "voice\MIBL\MIBL005";
			Preprocessor_AddQuestData("Marc", GetMyName(CharacterFromID("Marc Blacque")));
			AddQuestRecord("Blacques", 16);
			Preprocessor_Remove("Marc");
			Preprocessor_Add("Marc", GetMyName(CharacterFromID("Marc Blacque")));
			Dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
			// NK -->
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 100);
				AddPartyExpChar(pchar, "Sneak", 1);
			}
			else { AddPartyExp(pchar, 100); }
			// NK <--
			npchar.quest.son = "letter_return";
		break;

		case "rescue":
			Dialog.snd = "voice\MIBL\MIBL006";
			Preprocessor_AddQuestData("Marc", GetMyName(CharacterFromID("Marc Blacque")));
			Preprocessor_AddQuestData("Milon", GetMyName(NPChar));
			AddQuestRecord("Blacques", 12); // NK
			Preprocessor_Remove("Milon");
			Preprocessor_Remove("Marc");
			Preprocessor_Add("Marc", GetMyName(CharacterFromID("Marc Blacque")));
			Dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "exit";
			ChangeCharacterAddress(characterFromID("Marc Blacque"), "Falaise_de_fleur_port_01", "carpenter2");
			RemovePassenger(pchar, characterFromID("Marc Blacque"));
			ChangeCharacterReputation(pchar, 1);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1000);
				AddPartyExpChar(pchar, "Sneak", 100);
			}
			else { AddPartyExp(pchar, 1000); }
			npchar.quest.son = "done";
			if (Characters[GetCharacterIndex("Rachel Blacque")].quest.badguy == "dead")
			{
				NextDiag.TempNode = "Third time";
				ChangeCharacterAddress(characterFromID("Marc Blacque"), "None", "");
			}
			else NextDiag.TempNode = "Fourth time";
		break;
		// BT  For hire of Marc -->
		case "Third time":
			Dialog.snd = "voice\MIBL\MIBL006";
			Dialog.text = DLG_TEXT[19] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			if(!CheckAttribute(NPChar,"donetemp"))
			{
				NPChar.donetemp = 1;
				Preprocessor_AddQuestData("Milon", GetMyName(NPChar));
				AddQuestRecord("Blacques", 14);
				Preprocessor_Remove("Milon");
				CloseQuestHeader("Blacques");
			}
			link.l1.go = "exit";
			NextDiag.TempNode = "Third Time";
		break;
		
		case "Fourth time":
			Dialog.snd = "voice\MIBL\MIBL006";
			Preprocessor_Add("Milon", GetMyName(NPChar));
			Dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			ChangeCharacterAddress(characterFromID("Marc Blacque"), "Falaise_De_Fleur_Store", "goto5");	
			link.l1.go = "Marc1";
		break;

		case "Marc1":
			Dialog.snd = "voice\MIBL\MIBL006";
			Preprocessor_Add("Rachel", GetMyName(CharacterFromID("Rachel Blacque")));
			Preprocessor_Add("Marc", GetMyName(CharacterFromID("Marc Blacque")));
			Dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Marc2";
		break;
		
		case "Marc2":
			Dialog.snd = "voice\MIBL\MIBL006";
			Preprocessor_Add("Marc", GetMyName(CharacterFromID("Marc Blacque")));
			Dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Third time";
		break;
		// BT  For hire of Marc  <--

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
