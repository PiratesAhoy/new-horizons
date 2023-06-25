//#include "DIALOGS\Sylvie Bondies_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

void ProcessDialogEvent()
{
	ref NPChar;
	
	DeleteAttribute(&Dialog,"Links");
	aref Link, NextDiag;
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	int iTest;

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
			Dialog.snd = "voice\SYBO001\SYBO001";

			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			// включить проверку, если девушка была или захвачена игроком, но выкуп за нее Сильвией уже заплачен, то она ругает игрока.
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			Dialog.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
			link.l1 = pcharrepphrase(DLG_TEXT[2], DLG_TEXT[3]);
			link.l1.go = "exit";
			if (characters[GetCharacterIndex("Sabine Matton")].quest.hire == "blaze_on_ship")
			{
				Dialog.snd = "voice\SYBO001\SYBO002";
				dialog.text = DLG_TEXT[4] 
				link.l1 = pcharrepphrase(DLG_TEXT[8] + GetMyFullName(NPChar) + DLG_TEXT[9] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[10])]) + DLG_TEXT[11], DLG_TEXT[12]+ GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[14])]) +DLG_TEXT[7]);
				link.l1.go = "goddaughter";
				link.l2 = pcharrepphrase(DLG_TEXT[13] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[14])]) + DLG_TEXT[15], DLG_TEXT[16] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[17])]) + DLG_TEXT[18]);
				link.l2.go = "goddaughter_denied";
			}
			if (characters[GetCharacterIndex("Sabine Matton")].quest.hire == "captured_by_blaze")
			{
				Dialog.snd = "voice\SYBO001\SYBO003";
				dialog.text = DLG_TEXT[19];
				link.l1 = pcharrepphrase(DLG_TEXT[20], DLG_TEXT[21]);
				link.l1.go = "ransom";
			}
			NextDiag.TempNode = "First time";
		break;

		case "ransom":
			Dialog.snd = "voice\SYBO001\SYBO004";
			dialog.text = DLG_TEXT[22];
			link.l1 = pcharrepphrase(DLG_TEXT[23], DLG_TEXT[24]);
			link.l1.go = "ransom_1";
			link.l2 = pcharrepphrase(DLG_TEXT[25], DLG_TEXT[26] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[27])]) + DLG_TEXT[28]);
			link.l2.go = "ransom_free";
			link.l3 = pcharrepphrase(DLG_TEXT[29], DLG_TEXT[30]);
			link.l3.go = "exit";
		break;

		case "ransom_1":
			Dialog.snd = "voice\SYBO001\SYBO005";
			dialog.text = DLG_TEXT[31];
			link.l1 = pcharrepphrase(DLG_TEXT[32], DLG_TEXT[33]);
			link.l1.go = "ransom_2";
		break;

		case "ransom_2":
			Dialog.snd = "voice\SYBO001\SYBO006";
			dialog.text = DLG_TEXT[34];
			link.l1 = pcharrepphrase(DLG_TEXT[35], DLG_TEXT[36]);
			link.l1.go = "ransom_3";
			link.l2 = pcharrepphrase(DLG_TEXT[37] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[38])]) + DLG_TEXT[39], DLG_TEXT[40]);
			link.l2.go = "ransom_lie";
		break;

		case "ransom_3":
			Dialog.snd = "voice\SYBO001\SYBO007";
			dialog.text = DLG_TEXT[41];
			link.l1 = pcharrepphrase(DLG_TEXT[42], DLG_TEXT[43]);
			link.l1.go = "exit";
			ChangeCharacterReputation(pchar, -1);
			characters[GetCharacterIndex("Sabine Matton")].quest.hire = "almost_done_ransom";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 2000);
			RemovePassenger(pchar, Characters[GetCharacterIndex("Sabine Matton")]);
//			ChangeCharacterAddress(characterFromID("Sabine Matton"), "house_of_sylvie_bondies", "locator4")  //TALISMAN Changed - locator does not exist
			ChangeCharacterAddress(characterFromID("Sabine Matton"), "house_of_sylvie_bondies", "goto5")		//TALISMAN Changed - original locator does not exist
			Locations[FindLocation("Muelle_town_01")].reload.l8.disable = 1;// PW lock location now Sabine freed
			TakeItemFromCharacter(Pchar, "Correspondence1");// PW remove Arnaud letter
		break;

		case "ransom_lie":
			Dialog.snd = "voice\SYBO001\SYBO008";
			dialog.text = DLG_TEXT[44] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[45];
			link.l1 = pcharrepphrase(DLG_TEXT[46], DLG_TEXT[47]);
			link.l1.go = "ransom_lie_1";
		break;

		case "ransom_lie_1":
			Dialog.snd = "voice\SYBO001\SYBO009";
			dialog.text = DLG_TEXT[48];
			link.l1 = pcharrepphrase(DLG_TEXT[49], DLG_TEXT[50]);
			link.l1.go = "exit";
			ChangeCharacterReputation(pchar, -1);
			characters[GetCharacterIndex("Sabine Matton")].quest.hire = "captured_by_blaze_again";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 2000);
			TakeItemFromCharacter(Pchar, "Correspondence1");// PW remove Arnaud letter
			NextDiag.TempNode = "Last time";
		break;

		case "ransom_free":
			Dialog.snd = "voice\SYBO001\SYBO010";
			dialog.text = DLG_TEXT[51] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[52];
			link.l1 = pcharrepphrase(DLG_TEXT[53], DLG_TEXT[54]);
			link.l1.go = "ransom_free_wrong";
			link.l2 = pcharrepphrase(DLG_TEXT[55], DLG_TEXT[56]);
			link.l2.go = "ransom_free_right";
		break;

		case "ransom_free_wrong":
			Dialog.snd = "voice\SYBO001\SYBO011";
			dialog.text = DLG_TEXT[57];
			link.l1 = pcharrepphrase(DLG_TEXT[58], DLG_TEXT[59]);
			link.l1.go = "exit";
			RemovePassenger(pchar, Characters[GetCharacterIndex("Sabine Matton")]);
			characters[GetCharacterIndex("Sabine Matton")].quest.hire = "almost_done_ransom_free";
			ChangeCharacterAddress(characterFromID("Sabine Matton"), "house_of_sylvie_bondies", "goto8");// PW Sabine in house
			TakeItemFromCharacter(Pchar, "Correspondence1"); // PW remove Arnaud letter
			ChangeCharacterReputation(pchar, -1);
			Locations[FindLocation("Muelle_town_01")].reload.l8.disable = 1;// PW lock location against return now Sabine freed
		break;

		case "ransom_free_right":
			Dialog.snd = "voice\SYBO001\SYBO012";
			dialog.text = DLG_TEXT[60];
			link.l1 = pcharrepphrase(DLG_TEXT[61], DLG_TEXT[62]);
			link.l1.go = "exit";
			RemovePassenger(pchar, Characters[GetCharacterIndex("Sabine Matton")]);
			ChangeCharacterAddress(characterFromID("Sabine Matton"), "house_of_sylvie_bondies", "goto8");// PW Sabine in house
			TakeItemFromCharacter(Pchar, "Correspondence1"); // PW remove Arnaud letter
			characters[GetCharacterIndex("Sabine Matton")].quest.hire = "almost_done_ransom_free";// PW was "almost_done"
			ChangeCharacterReputation(pchar, 1);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 500);
				AddPartyExpChar(pchar, "Sneak", 5);
			}
			else { AddPartyExp(pchar, 500); }
			Locations[FindLocation("Muelle_town_01")].reload.l8.disable = 1;// PW lock location against return now Sabine freed
		break;

		case "goddaughter_denied":
			Dialog.snd = "voice\SYBO001\SYBO013";
			dialog.text = DLG_TEXT[63];
			link.l1 = pcharrepphrase(DLG_TEXT[64], DLG_TEXT[65]);
			link.l1.go = pcharrepphrase("goddaughter_denied_1", "goddaughter_denied_2");
		break;

		case "goddaughter_denied_1":
			Dialog.snd = "voice\SYBO001\SYBO014";
			dialog.text = DLG_TEXT[66] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[67] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[68])]) + DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "goddaughter_denied_confirm";
			link.l2 = DLG_TEXT[71];
			link.l2.go = "goddaughter";
		break;

		case "goddaughter_denied_confirm":
			Dialog.snd = "voice\SYBO001\SYBO015";
			dialog.text = DLG_TEXT[72] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Sabine Matton")].quest.hire = "captured_by_blaze";
			TakeItemFromCharacter(Pchar, "Correspondence1");// PW remove Arnaud letter
			///////////////////////////////////////////
			// Убрать сабину и перегрузить локацию
			///////////////////////////////////////////
		//	ChangeCharacterAddress(characterFromID("Sabine Matton"), "none", "none")// PW she should still be on pchar ship
		break;

		case "goddaughter_denied_2":
			Dialog.snd = "voice\SYBO001\SYBO016";
			dialog.text = DLG_TEXT[75] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "goddaughter_denied_confirm_1";
		break;

		case "goddaughter_denied_confirm_1":
			Dialog.snd = "voice\SYBO001\SYBO017";
			dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Sabine Matton")].quest.hire = "captured_by_blaze";
			ChangeCharacterReputation(pchar, -3);
			///////////////////////////////////////////
			// Убрать сабину и перегрузить локацию
			///////////////////////////////////////////
		//	ChangeCharacterAddress(characterFromID("Sabine Matton"), "none", "none")// PW she should still be on pchar ship
		break;

		case "goddaughter":
			Dialog.snd = "voice\SYBO001\SYBO018";
			dialog.text = DLG_TEXT[80];
			link.l1 = pcharrepphrase(DLG_TEXT[81] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[82])]) + DLG_TEXT[83], DLG_TEXT[84]);
			link.l1.go = pcharrepphrase("goddaughter_1", "goddaughter_2");
			TakeItemFromCharacter(PChar, "Correspondence1");// PW remove Arnaud's letter
			RemovePassenger(pchar, Characters[GetCharacterIndex("Sabine Matton")]);
//			ChangeCharacterAddress(characterFromID("Sabine Matton"), "house_of_sylvie_bondies", "locator4")  //TALISMAN Changed - locator does not exist
			ChangeCharacterAddress(characterFromID("Sabine Matton"), "house_of_sylvie_bondies", "goto5")  	//TALISMAN Changed - original locator does not exist
		break;

		case "goddaughter_1":
			Dialog.snd = "voice\SYBO001\SYBO019";
			dialog.text = DLG_TEXT[85] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[86])]) + DLG_TEXT[87];
			link.l1 = pcharrepphrase(DLG_TEXT[88], DLG_TEXT[89]);
			link.l1.go = "exit";
			////////////////////////////////////////
			// Убрать письмо, добавить новое письмо
			////////////////////////////////////////
			ChangeCharacterReputation(pchar, 1);
			characters[GetCharacterIndex("Sabine Matton")].quest.hire = "almost_done";
			GiveItem2Character(PChar, "Correspondence2");// PW give Syvie's letter
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 700);
				AddPartyExpChar(pchar, "Sneak", 7);
			}
			else { AddPartyExp(pchar, 700); }
			Locations[FindLocation("Muelle_town_01")].reload.l8.disable = 1;// PW lock location now Sabine freed
		break;

		case "goddaughter_2":
			Dialog.snd = "voice\SYBO001\SYBO020";
			dialog.text = DLG_TEXT[90];
			link.l1 = DLG_TEXT[91];
			link.l1.go = "goddaughter_1";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 800);
		break;

		case "Last time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\SYBO001\SYBO001";

			Dialog.Text = DLG_TEXT[92] ;
			link.l1 = pcharrepphrase(DLG_TEXT[2], DLG_TEXT[3]);
			link.l1.go = "exit";
			NextDiag.TempNode = "Last time";
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
