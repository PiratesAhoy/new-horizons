//#include "DIALOGS\Enc_RapersGirl_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	
	switch(Dialog.CurrentNode)
	{
		case "exit_1":
//			AddDialogExitQuest("LandEnc_RapersTalk");
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();			
		break;

		case "Node_1":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			Preprocessor_Add("sir", FirstLetterUp(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false))); // DeathDaisy
			d.Text = RandPhrase(DLG_TEXT[0], DLG_TEXT[1], DLG_TEXT[2], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = LinkRandPhrase(DLG_TEXT[3], DLG_TEXT[4], DLG_TEXT[5]);
			Link.l1.go = "Node_2";			
		break;

		case "Node_2":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			d.Text = RandPhrase(DLG_TEXT[6], DLG_TEXT[7], DLG_TEXT[8], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "exit_1";
			AddDialogExitQuest("LandEnc_RapersTalk");			
		break;

		case "ThanksForHelp":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			Preprocessor_Add("sir", FirstLetterUp(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false))); // DeathDaisy
			if (CalcCharacterSkill(PChar, SKILL_FENCING) < 3)
				d.Text = RandPhrase(DLG_TEXT[10], DLG_TEXT[11], DLG_TEXT[12], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			else
				d.Text = RandPhrase(DLG_TEXT[33], DLG_TEXT[34], DLG_TEXT[35], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "ThanksForHelp_1";			
		break;
		
		case "ThanksForHelp_1":
			Diag.TempNode = "ThanksAgain";
			if(makeint(Pchar.reputation) >= 80)
			{
	            int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
				PlayStereoSound("INTERFACE\took_item.wav");
				addMoneyToCharacter(Pchar, makeint(PChar.rank)*100);
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You got") + " " + (makeint(PChar.rank)*100) + " " + LanguageConvertString(tmpLangFileID,"gold.")); // NK
				d.Text = DLG_TEXT[14];
				Link.l1 = DLG_TEXT[15];
				Link.l1.go = "Exit_1";			
			}
			else 
			{
				if(Rand(3))
				{
					// DeathDaisy ->
					string PCharGentle;
					if(PChar.sex == "woman")	PCharGentle = XI_ConvertString("gentlewoman");
					else	PCharGentle = XI_ConvertString("gentleman");
					Preprocessor_Add("gentleman", PCharGentle);
					// DeathDaisy <-
					d.Text = DLG_TEXT[16];
					Link.l1 = DLG_TEXT[17];
					int repch2 = 3;
					if(makeint(Pchar.reputation) >= 60) repch2 = 2;
					if(makeint(Pchar.reputation) >= 70) repch2 = 1;
					ChangeCharacterReputation(pchar, repch2); // NK
					Link.l1.go = "exit_1";			
				}
				else
				{
					PlayStereoSound("INTERFACE\took_item.wav");
					addMoneyToCharacter(Pchar, makeint(PChar.rank)*100);
					Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You got") + " " + (makeint(PChar.rank)*100) + " " + LanguageConvertString(tmpLangFileID,"gold.")); // NK
					d.Text = DLG_TEXT[18];
					Link.l1 = DLG_TEXT[19];
					Link.l1.go = "Exit_1";			
				}
	            LanguageCloseFile(tmpLangFileID);
	
			}
			AddDialogExitQuest("LandEnc_Char1_Leaves");
		break;

/*		case "ThanksAgain":



		break; */




















/*		case "CheckSkills":
			if(CalcCharacterSkill(PChar,SKILL_FENCING) >= 5 && makeint(Pchar.skill.Fencing) >= makeint(Pchar.rank)) 
			{
				Diag.TempNode = "GetLost";
				d.Text = RandPhrase(DLG_TEXT[20], DLG_TEXT[21], DLG_TEXT[22]);
				Link.l1 = RandPhrase(DLG_TEXT[23], DLG_TEXT[24], DLG_TEXT[25]);
				Link.l1.go = "Exit_NoFight";
				Link.l99 = RandPhrase(DLG_TEXT[26], DLG_TEXT[27], DLG_TEXT[28]);
				Link.l99.go = "Exit_RunFight";
			}
			else 
			{
				d.Text = RandPhrase(DLG_TEXT[29], DLG_TEXT[30], DLG_TEXT[31]);
				Link.l1 = DLG_TEXT[32];
				Link.l1.go = "Exit_Fight";				
			}

		break; */

/*		case "OnceAgain":
			Diag.TempNode = "OnceAgain";
			Preprocessor_Add("lad", GetMyAddressForm(NPChar, PChar, ADDR_INFORMAL, false, false)); // DeathDaisy
			d.Text = RandPhrase(DLG_TEXT[39], DLG_TEXT[40], DLG_TEXT[41]);
			Link.l1 = DLG_TEXT[42];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[43];
			Link.l2.go = "Exit_Fight";
		break; */
				
/*		case "GetLost":
			Diag.TempNode = "GetLost";
			d.Text = RandPhrase(DLG_TEXT[44], DLG_TEXT[45], DLG_TEXT[46]);
			Link.l1 = DLG_TEXT[47];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[48];
			Link.l2.go = "Exit_Fight";
		break; */

/*		case "GetTheHellOut":
			Diag.TempNode = "GetTheHellOut";
			Preprocessor_Add("pronoun", FirstLetterUp(GetMyPronounSubj(PChar))); // DeathDaisy
			d.Text = RandPhrase(DLG_TEXT[49], DLG_TEXT[50], DLG_TEXT[51]);
			Link.l1 = DLG_TEXT[52];
			Link.l1.go = "Exit";			
		break; */


	}
}