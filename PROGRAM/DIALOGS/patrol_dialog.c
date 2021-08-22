// //#include "DIALOGS\patrol_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"


void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];

	int iNation = GetTownNation(GetCurrentTownID()); // KK
	int Relation = GetRMRelation(PChar, iNation);
	
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
			Dialog.snd = "voice\PADI\PADI001";
			
			Dialog.text =  LinkRandPhrase(DLG_TEXT[2], DLG_TEXT[3], DLG_TEXT[4]);

			if (Relation <= REL_WAR )
			{
				link.l1 = DLG_TEXT[5] + GetMyFullName(PChar) + DLG_TEXT[6];
				link.l1.go = "fight";

				link.l2 = DLG_TEXT[7];
				if(rand(40)+sti(pchar.skill.Sneak)>25) {Link.l2.go = "bribe";}
				else{Link.l2.go = "fight";}

				link.l3 = DLG_TEXT[8];
				if(rand(40)+sti(pchar.skill.Fencing)>30) {Link.l3.go = "sorry";}
				else{Link.l3.go = "fight";}

				if(NPchar.chr_ai.group !=  "SMUGGLERS_SOLDIERS" )
				{
					link.l4 = DLG_TEXT[9];
					if(rand(40)+sti(pchar.skill.leadership)>30) {Link.l4.go = "sorry";}
					else{Link.l4.go = "fight";}
				}
			}
			else
			{
				if (iNation != PERSONAL_NATION) {
					link.l1 = DLG_TEXT[5] + GetMyFullName(PChar) + DLG_TEXT[6];
					link.l1.go = "sorry";
				} else {
					Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
					Dialog.text = DLG_TEXT[21];
					link.l1 = DLG_TEXT[22];
					link.l1.go = "Exit";
				}
			}
			Diag.TempNode = "first time";
		break;

		case "bribe":
			Preprocessor_Add("pronoun", GetMyAddressForm(npchar, pchar, ADDR_GENDER, false, false)); // DeathDaisy
			AddMoneytoCharacter(Pchar, -200);
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
		break;

		case "fight":
			Dialog.text = LinkRandPhrase(DLG_TEXT[12], DLG_TEXT[13], DLG_TEXT[13]);// TIH bugfix must have three vars Jul11'06
			link.l1 = RandSwear() + DLG_TEXT[14], DLG_TEXT[15], DLG_TEXT[16];
			link.l1.go = "exit_fight";
		break;

		case "exit_fight":
			PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_039.wav");	// ccc Jan06 bug corr
			LAi_group_SetRelation(NPchar.chr_ai.group, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			int hp = sti(PChar.rank)*10 + rand(100) + 50;
			LAi_SetHP(NPchar, hp, hp);	// for more variation and challenge

			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "sorry":
			if(lcn.type != "military" )
			{
				Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false));
				Dialog.text = DLG_TEXT[17];
				link.l1 = DLG_TEXT[18];
				link.l1.go = "exit";
			}
			else
			{
				Dialog.text = DLG_TEXT[19];
				link.l1 = DLG_TEXT[20];
				link.l1.go = "fight";
			}

		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
