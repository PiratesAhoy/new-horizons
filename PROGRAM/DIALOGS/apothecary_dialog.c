//#include "DIALOGS\apothecary_dialog.h"

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
		case "bloodletting":
			Dialog.text = DLG_TEXT[31];
			Link.l1 = DLG_TEXT[32];
			Link.l1.go = "bill";
			pchar.chr_ai.poison = 0;
		break;

		case "bill":
			Dialog.text = DLG_TEXT[33];
			Link.l1 = DLG_TEXT[34];
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneytoCharacter(Pchar, -100);
			Link.l1.go = "exit";
		break;

		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\TAFI\TAFI001";
			
			if(CheckAttribute(pchar,"chr_ai.poison") && pchar.chr_ai.poison > 0)
			{
				Dialog.text = DLG_TEXT[8];
				Link.l1 = DLG_TEXT[9];
				Link.l1.go = "bloodletting";
			}
			else
			{
				if(NPChar.quest.meeting == "0")
				{
					dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "talking1";
					link.l2 = DLG_TEXT[2];
					link.l2.go = "exit";
					NPChar.quest.meeting = "1";
			
					NextDiag.TempNode = "first time";
				}
				else
				{
					dialog.text = DLG_TEXT[3];
					link.l1 = DLG_TEXT[4];
					link.l1.go = "recover";
					link.l2 = DLG_TEXT[5];
					link.l2.go = "increase_hp";
					link.l3 = DLG_TEXT[6];
					link.l3.go = "buy";
					//Levis -->
					if(CheckCharacterItem(pchar,"opium"))
					{
						link.l4 = DLG_TEXT[48];
						link.l4.go = "Opium Explain";
					}
					//Levis <--
					link.l5 = DLG_TEXT[7];
					link.l5.go = "exit";

					NextDiag.TempNode = "first time";
				}
			}
		break;
		
		//Levis -->
		case "Opium Explain":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "exit";
		break;
		//Levis <--

		case "talking1":
			dialog.text = DLG_TEXT[10] + GetMyFullName(NPChar) + DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "talking2";
		break;

		case "talking2":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "recover";
			link.l2 = DLG_TEXT[5];
			link.l2.go = "increase_hp";
			link.l3 = DLG_TEXT[6];
			link.l3.go = "buy";
			link.l4 = DLG_TEXT[7];
			link.l4.go = "exit";
		break;
	
		case "recover":
			dialog.text = DLG_TEXT[15];
			if(sti(PChar.money) >=200)
			{
				link.l1 = DLG_TEXT[16];
				link.l1.go = "recover2";
			}
			link.l2 = DLG_TEXT[17];
			link.l2.go = "exit";
		break;

		case "recover2":
			HealBy (&pChar, &nextDiag);
		break;

		case "increase_hp":
			// Swindler 05-09-25: for testing purposes so we have officers -->
			//SetOfficersIndex(Pchar, 1, GetCharacterIndex("Fred Bob"));
			//SetOfficersIndex(Pchar, 2, GetCharacterIndex("Estrella de Alencar"));
			//SetOfficersIndex(Pchar, 3, GetCharacterIndex("Sabine Matton"));
			//GiveItem2Character(Pchar, "meds1");
			//GiveItem2Character(Pchar, "meds2");
			//GiveItem2Character(Pchar, "meds3");
			//GiveItem2Character(Pchar, "meds4");
			// <--
			
			if(CheckCharacterItem(Pchar,"meds1") && CheckCharacterItem(Pchar,"meds2") && CheckCharacterItem(Pchar,"meds3") && CheckCharacterItem(Pchar,"meds4")) 
			{
				dialog.Text = DLG_TEXT[18];
				// Swindler 05-09-25: gives you the possibilty to increase
				// max hp of your officers -->
				Link.l1 = DLG_TEXT[19];
				Link.l1.go = "increase_hp2";
				int intOfficer;
				ref refOfficer;
				string strLink;
				for (int i = 0; i < 3; i++) {
					intOfficer = sti(GetOfficersIndex(PChar,i+1));
					if( intOfficer != -1)
					{
						strLink = "l" + (i+2);
				 		refOfficer = GetCharacter(intOfficer);
				 		Link.(strLink) = DLG_TEXT[20] + GetOfficerAddressForm(&refOfficer) + DLG_TEXT[21];
				 		Link.(strLink).go = "increase_hp2_" + (i+1);
					}
				}
				// <--
				Link.l5 = DLG_TEXT[47];
				Link.l5.go = "exit";
			}
			else
			{
				Preprocessor_Add("gender", GetCharacterAddressForm(PChar, ADDR_GENDER, false, false)); // DeathDaisy
				dialog.text = DLG_TEXT[23];
				link.l1 = DLG_TEXT[24];
				link.l1.go = "exit";
			}
		break;

		// LDH --> 31AUG06 - HP increase up from 5 points to 10% of current HP and costing 500 per character level

		// Swindler 05-09-25: switch the officer, whose max hp to be increased.
		// The code for increasing the hp, etc. moved to the IncreaseMaxHP()
		// function -->
		case "increase_hp2":
			pChar.apothecary.chr = 0;
			pChar.apothecary.payment = sti(pChar.rank) * 500;
			dialog.Text = DLG_TEXT[44] + pChar.apothecary.payment + DLG_TEXT[45];
			if (sti(pChar.wealth) >= sti(pChar.apothecary.payment))
			{
				Link.l1 = DLG_TEXT[46];
				Link.l1.go = "increase_hp3";
			}
			Link.l2 = DLG_TEXT[22];
			Link.l2.go = "exit";
		break;
		
		case "increase_hp2_1":
			pChar.apothecary.chr = 1;
			intOfficer = sti(GetOfficersIndex(PChar, 1));
			refOfficer = GetCharacter(intOfficer);
			pChar.apothecary.payment = sti(refOfficer.rank) * 500;
			dialog.Text = DLG_TEXT[44] + pChar.apothecary.payment + DLG_TEXT[45];
			if (sti(pChar.wealth) >= sti(pChar.apothecary.payment))
			{
				Link.l1 = DLG_TEXT[46];
				Link.l1.go = "increase_hp3";
			}
			Link.l2 = DLG_TEXT[22];
			Link.l2.go = "exit";
		break;
		
		case "increase_hp2_2":
			pChar.apothecary.chr = 2;
			intOfficer = sti(GetOfficersIndex(PChar, 2));
			refOfficer = GetCharacter(intOfficer);
			pChar.apothecary.payment = sti(refOfficer.rank) * 500;
			dialog.Text = DLG_TEXT[44] + pChar.apothecary.payment + DLG_TEXT[45];
			if (sti(pChar.wealth) >= sti(pChar.apothecary.payment))
			{
				Link.l1 = DLG_TEXT[46];
				Link.l1.go = "increase_hp3";
			}
			Link.l2 = DLG_TEXT[22];
			Link.l2.go = "exit";
		break;
		
		case "increase_hp2_3":
			pChar.apothecary.chr = 3;
			intOfficer = sti(GetOfficersIndex(PChar, 3));
			refOfficer = GetCharacter(intOfficer);
			pChar.apothecary.payment = sti(refOfficer.rank) * 500;
			dialog.Text = DLG_TEXT[44] + pChar.apothecary.payment + DLG_TEXT[45];
			if (sti(pChar.wealth) >= sti(pChar.apothecary.payment))
			{
				Link.l1 = DLG_TEXT[46];
				Link.l1.go = "increase_hp3";
			}
			Link.l2 = DLG_TEXT[22];
			Link.l2.go = "exit";
		break;
		// Swindler <--

		case "increase_hp3":
			increaseMaxHP(&pChar, &NextDiag);
		break;
		// LDH <--

		case "buy":
			if(CheckCharacterItem(Pchar,"albatross"))
			{
				dialog.Text = DLG_TEXT[25];
				Link.l1 = DLG_TEXT[26];
				Link.l1.go = "buy_leeches2";
				Link.l2 = DLG_TEXT[27];
				Link.l2.go = "exit";
			}
			else
			{
				Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
				dialog.text = DLG_TEXT[28];
				if (makeint(pchar.money) >= 300)
				{
					link.l1 = DLG_TEXT[29];
					link.l1.go = "buy_leeches";
				}
				link.l2 = DLG_TEXT[30];
				link.l2.go = "exit";
			}
		break;

		case "buy_leeches":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			GiveItem2Character(Pchar,"leeches");
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(Pchar, -300);
		break;

		case "buy_leeches2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			GiveItem2Character(Pchar,"leeches");
			TakeItemFromCharacter(Pchar,"albatross");
		break;

		case "Exit":
			DeleteAttribute(pChar, "apothecary");	// LDH
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}

// Swindler 05-09-25 --> 
/* Increases the maximum hp of the officer at slot <officerIndex>.
 * 
 * @param  ref  a reference to the players character.
 * @param  int  the slot of the officer whose max hp to increase.
 * @param  int  the players money.
 * @param  ref  a refernce to the next dialog.
 * @return void
 */
//void increaseMaxHP(ref pChar, int officerIndex, int playerMoney, ref nextDiag)
// LDH --> 31AUG06 changes for 10% increase for 500 per character level
void increaseMaxHP(ref pChar, ref nextDiag)
{	
	int officerIndex = sti(pChar.apothecary.chr);
	int playerMoney = sti(pChar.wealth);
	ref refOfficer;
	int increasePer;
	
	if (officerIndex == 0) {
		refOfficer = pChar;		
		increasePer = sti(refOfficer.chr_ai.hp_max) / 10;		// 10% increase
	} else {
		int intOfficer = sti(GetOfficersIndex(PChar, officerIndex));
		refOfficer = GetCharacter(intOfficer);
		increasePer = sti(refOfficer.chr_ai.hp_max) / 20;		// 5% increase
	}
	
	ChangeHPBonus(refOfficer, increasePer);
	
	string logMsg1 = DLG_TEXT[38] + GetMyFullName(&refOfficer) + DLG_TEXT[39] + GetMyPronoun(&refOfficer, "he") + DLG_TEXT[40];
	string logMsg2 = DLG_TEXT[41];
	string logMsg3 = DLG_TEXT[42] + increasePer + DLG_TEXT[43];
	DialogExit();
	nextDiag.CurrentNode = nextDiag.TempNode;
	playerMoney -= sti(pChar.apothecary.payment);
	if (playerMoney < 0) playerMoney = 0;	// just in case
	pChar.wealth = PlayerMoney;

	DeleteAttribute(pChar, "apothecary");	// LDH
	
	// NK 05-07-03 -->
	/*ChangeHPBonus(PChar, 5);
	pchar.chr_ai.hp_max = sti(pchar.chr_ai.hp_max) + 5;
	LAi_SetCurHPMax(pchar);*/
	// NK <--
	LAi_Fade("", "");
	WaitDate("", 0,0,1,0,0);
	RecalculateJumpTable();
	PlaySound("AMBIENT\SHOP\sigh2.wav");
	Log_SetStringToLog(logMsg1);
	Log_SetStringToLog(logMsg2);
	Log_SetStringToLog(logMsg3);
	TakeItemFromCharacter(pChar, "meds1");
	TakeItemFromCharacter(pChar, "meds2");
	TakeItemFromCharacter(pChar, "meds3");
	TakeItemFromCharacter(pChar, "meds4");
}
// Swindler <--
// LDH <--

//----->PW changed previous case "recover2" to a function to allow use of dialog as text (as per above example IncreaseMaxHP)
	Void HealBy (ref pChar, ref nextDiag)
	{
		string logMsg1 = "  " + DLG_TEXT[35];
		string logMsg2 = "  " + DLG_TEXT[36];
		string logMsg3 = "  " + DLG_TEXT[37];
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		PlayStereoSound("INTERFACE\took_item.flac");
		AddMoneyToCharacter(Pchar, -200);
		pchar.chr_ai.poison = 0;
		LAi_SetCurHPMax(pchar);
		LAi_Fade("", "");
		WaitDate("", 0,0,1,0,0);
		RecalculateJumpTable();
		pchar.quest.opium_use.opiumsickness = 0; //Levis also heals opium sickness
		PlaySound("AMBIENT\SHOP\sigh2.wav");
			
		Log_SetStringToLog(logMsg1);
		Log_SetStringToLog(logMsg2);
		Log_SetStringToLog(logMsg3);
	}
//<--------------PW end of function replacing "recover2"