// ccc special weapons assembly kit
// This dialog is temporarily assigned to characters that you have knocked out
// While they are stunned you can rob their money and weapons, or reawaken them with a potion to get reputation
//#include "DIALOGS\stunned_dialog.h"


void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	string poor_fella;
	if (NPChar.sex == "woman") poor_fella = DLG_TEXT[18];
	else poor_fella = DLG_TEXT[4];

	switch(Dialog.CurrentNode)
	{
		case "Exit":
			Diag.CurrentNode = Diag.TempNode;	// restores the current node of the original dialog
			DialogExit();
		break;

		case "reputation":
			TakeItemFromCharacter(pchar, "potion1" );	// one potion for victim(if you have one)
			//ChangeCharacterReputation(pchar, 1);		// reward for being helpful
			/*NPChar.dialog.filename = NPChar.stuntime.dialog.filename;	// restores original dialog
			LAi_SetCitizenTypeNoGroup(NPchar);	// makes character walk again, but not very agile
			DeleteAttribute(NPChar,"stuntime");	// removes "stunned" tag*/
// MAXIMUS [so, we can heal our crewmembers and add them to the fighting command] -->
/*			if(bAbordageStarted)
			{
				LAi_SetStayType(NPChar);
				LAi_group_MoveCharacter(NPChar, LAI_GROUP_PLAYER);
				LAi_tmpl_SetFollow(NPChar, PChar, 0);
				DeleteAttribute(NPChar,"Dialog.Filename");
				if(IsOfficer(NPChar))
				{
					LAi_SetOfficerType(NPChar);
					NPChar.Dialog.Filename = "Enc_Officer_dialog.c";
					Diag.CurrentNode = "hired";
				}
				DeleteAttribute(NPChar,"stuntime");
			}
			else
			{*/ //MAXIMUS: outcommented, because LAi_Stunned_AwakenCharacter was rewritten a little
// MAXIMUS [so, we can heal our crewmembers and add them to the fighting command] <--

			Diag.CurrentNode = Diag.TempNode;	// restores the current node of the original dialog
			DialogExit();
			//MAXIMUS: moved here for nice-showing process -->
			LAi_Stunned_AwakenCharacter(&NPChar);// awaken them from the stun_type update, not here!
			if(NPChar.sex != "woman") { PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_007.wav"); }	// "thank you"
			else { PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_f_c_007.wav"); }
			//MAXIMUS: moved here for nice-showing process <--
		break;

		case "loot":
			if(CheckAttribute(NPChar,"itemtrade")) MerchantGuildAttack(NPChar, false);	// PB: For streetmerchants only
			if(rand(100)+sti(pchar.skill.Sneak)>25) // chance of successful theft are 75% + luckskill
			{

				if(NPChar.sex == "woman") {PlaySound("OBJECTS\Voices\dead\female\dead_wom2.wav");}	// groan
				else{PlaySound("OBJECTS\Voices\dead\male\dead1.wav");}

				PlaySound("INTERFACE\took_item.wav");
				if(!LAi_group_IsEnemy(pchar,npchar) )  // rephit for robbing neutrals ???  NOT SURE ABOUT GAMEBALANCE
				{
					ChangeCharacterReputation(pchar, -1);
					Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Robbing helpless citizens isn't good for your reputation !"));
				}
				Diag.CurrentNode = Diag.TempNode;	// restores the current node of the original dialog
				DialogExit();
				bStealExchange = true; // added by MAXIMUS
				LaunchCharacterItemChange(NPChar);	// ccc jun 05 stealinterface

			} else {
				if(NPChar.sex != "woman") {PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_067.wav");}	// victim raises alarm
				else{PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_f_c_016.wav");}
				LAi_group_SetRelation(LAI_DEFAULT_GROUP, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
				LAi_group_SetRelation(LAI_GROUP_GUARDS, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
				ChangeCharacterReputation(pchar, -3);		// rephit for being caught
				SoldierReinforcements(NPChar); //PB: If you loot a town guard
				Diag.CurrentNode = Diag.TempNode;	// restores the current node of the original dialog
				DialogExit();
			}

		break;
// added by MAXIMUS [for crewmembers] -->
		case "loot_friend":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			bStealExchange = true;
			LaunchCharacterItemChange(NPChar);
		break;
// added by MAXIMUS [for crewmembers] <--

			// dialogstart is not in a case but here as default so that the original Dialog.CurrentNode doesn't matter
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			/* done via greeting - if(NPChar.sex == "man") {PlaySound("OBJECTS\Voices\dead\male\dead1.wav");}	// groan
			else{PlaySound("OBJECTS\Voices\dead\female\dead_wom2.wav");}*/

			Diag.TempNode = Dialog.CurrentNode;	// stores the current node of the original dialog
//MAXIMUS 23.09.2006 [during abordage we can speak and interact with our stunned crewmembers and officers] -->
			if(bAbordageStarted || IsOfficer(NPChar) || LAi_group_IsActivePlayerAlarm())//we can heal our people during fight
			{
				if(CheckAttribute(NPChar, "stuntime.group") && NPChar.stuntime.group==LAI_GROUP_PLAYER)
				{
					string addString = DLG_TEXT[14];
					dialog.text = RandSwear() + LinkRandPhrase(DLG_TEXT[10], DLG_TEXT[11], DLG_TEXT[12]);
					Link.l1 = DLG_TEXT[13];
					Link.l1.go = "loot_friend";
					if(CheckCharacterItem(Pchar, "potion1"))
					{
						if(IsOfficer(NPChar))
						{
							if(LAi_IsBoardingProcess()) { addString += DLG_TEXT[16]; }
							else { if(LAi_group_IsActivePlayerAlarm()) { addString += DLG_TEXT[17]; } }
						}
						else { if(LAi_group_IsActivePlayerAlarm()) { addString += DLG_TEXT[17]; } }
						Link.l2 = addString;
						Link.l2.go = "reputation";
					}
					Link.l3 = DLG_TEXT[15];
					Link.l3.go = "exit";
				}//MAXIMUS: for other people -->
				else
				{
					dialog.text = LinkRandPhrase(DLG_TEXT[1], DLG_TEXT[2], DLG_TEXT[3]);
					Link.l1 = LinkRandPhrase(poor_fella, DLG_TEXT[5], DLG_TEXT[6]);
					Link.l1.go = "loot";
					if(CheckCharacterItem(Pchar, "potion1"))
					{
						Link.l2 = LinkRandPhrase(DLG_TEXT[7], DLG_TEXT[8], DLG_TEXT[9]);
						Link.l2.go = "reputation";
					}
					Link.l3 = DLG_TEXT[0];
					Link.l3.go = "exit";
				}//MAXIMUS: for other people <--
			}
			else
			{//MAXIMUS: for our stunned crewmwmbers -->
				if(CheckAttribute(NPChar, "stuntime.group") && NPChar.stuntime.group==LAI_GROUP_PLAYER)
				{
					dialog.text = RandSwear() + LinkRandPhrase(DLG_TEXT[10], DLG_TEXT[11], DLG_TEXT[12]);
					Link.l1 = DLG_TEXT[13];
					Link.l1.go = "loot_friend";
					if(CheckCharacterItem(Pchar, "potion1"))
					{
						Link.l2 = DLG_TEXT[14];
						Link.l2.go = "reputation";
					}
					Link.l3 = DLG_TEXT[15];
					Link.l3.go = "exit";
				}
				else
				{//MAXIMUS: for our stunned crewmwmbers <--
//MAXIMUS 23.09.2006 [during abordage we can speak and interact with our stunned crewmembers and officers] <--
					dialog.text = LinkRandPhrase(DLG_TEXT[1], DLG_TEXT[2], DLG_TEXT[3]);

					Link.l1 = LinkRandPhrase(poor_fella, DLG_TEXT[5], DLG_TEXT[6]);
					Link.l1.go = "loot";		// link for robbers

					if(CheckCharacterItem(Pchar, "potion1")) // PB: Can't choose the repution option if you don't actually have a potion
					{
						Link.l2 = LinkRandPhrase(DLG_TEXT[7], DLG_TEXT[8], DLG_TEXT[9]);
						Link.l2.go = "reputation";
					}	// link for samaritans

					Link.l3 = DLG_TEXT[0];
					Link.l3.go = "exit";		// link for Hamlets ;)
				}
			}
	}
	LanguageCloseFile(tmpLangFileID);
}
