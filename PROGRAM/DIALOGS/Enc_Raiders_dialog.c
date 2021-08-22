//#include "DIALOGS\Enc_Raiders_dialog.h"
void ProcessDialogEvent()
{
	int pricePerk = 500; //Added by Levis
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	// DeathDaisy: Persuasion tags for the skill checks, if enabled
	string PersuasionSuccess = "";
	string PersuasionFailure = "";
	if(PERSUASION_TAGS){ 
		PersuasionSuccess = XI_ConvertString("Persuasion_Success") + " ";
		PersuasionFailure = XI_ConvertString("Persuasion_Failure") + " ";
	}
	
	switch(Dialog.CurrentNode)
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();			
		break;

		case "exit_Robbed":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -(makeint(makeint(Pchar.money)/20)*10));
			AddDialogExitQuest("LandEnc_RaidersRobbed");

			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();			
		break;

		case "exit_fight":
			AddDialogExitQuest("LandEnc_RaidersFight");

			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();			
		break;

		case "exit_RunFight":
			AddDialogExitQuest("LandEnc_RaidersRunAway");

			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit_noFight":
			AddDialogExitQuest("LandEnc_RaidersNoFight");

			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();			
		break;
		
		//Added by Levis
		case "exit_GetPerk":
			AddDialogExitQuest("LandEnc_RaidersNoFight");
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			UnlockPerkCharacter(PChar ,"Toughness");
			DialogExit();			
		break;
		
		case "exit_GetPerkPay":
			AddDialogExitQuest("LandEnc_RaidersNoFight");
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			AddMoneyToCharacter(pchar, (-1 * pricePerk));
			UnlockPerkCharacter(PChar ,"Toughness");
			DialogExit();			
		break;
		//End add

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

			LAi_type_actor_Reset(CharacterFromID("Enc_Char1"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char2"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char3"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char4"));

			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[0], DLG_TEXT[1], DLG_TEXT[2], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);

			// ccc stormy start
			Link.l3 = DLG_TEXT[48];
			if (rand(100) + (makeint(pchar.skill.Leadership)*2) >20) {Link.l3.go = "join";}
			else {Link.l3.go = "Node_2";}

			Link.l4 = DLG_TEXT[49];
			if (rand(100) + (makeint(pchar.skill.Leadership)*2) >20) {Link.l4.go = "planks";}
			else {Link.l4.go = "Node_2";}

			// ccc stormy start end

			Link.l1 = LinkRandPhrase(DLG_TEXT[3], DLG_TEXT[4], DLG_TEXT[5]);
			Link.l1.go = "Node_2";
			Link.l2 = LinkRandPhrase(DLG_TEXT[6], DLG_TEXT[7], DLG_TEXT[8]);
			Link.l2.go = "CheckSkills";
			
		break;

		case "Node_2":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			Preprocessor_Add("pronounsubj", GetMyPronounSubj(PChar)); // DeathDaisy
			d.Text = RandPhrase(DLG_TEXT[9], DLG_TEXT[10], DLG_TEXT[11], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[12] + makeint(makeint(Pchar.money)/20)*10 + DLG_TEXT[13];
			Link.l1.go = "CheckMoney";
			Link.l2 = DLG_TEXT[14];
			Link.l2.go = "CheckSkills";			
		break;

		case "CheckSkills":
			if(CheckCharacterPerkLocked(Pchar, "Toughness"))
			{
				if(CalcCharacterSkill(PChar,SKILL_FENCING) >= 4)
				{
					if(makeint(Pchar.Rank) >= 15)
					{
						//You don't need to pay
						Diag.TempNode = "GetLost";
						Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_INFORMAL, false, false)); // DeathDaisy
						if (PChar.sex == "woman") d.Text = PersuasionSuccess + DLG_TEXT[61];
						else d.Text = PersuasionSuccess + DLG_TEXT[56];
						Link.l1 = DLG_TEXT[57];
						Link.l1.go = "Exit_GetPerk";
						Link.l2 = DLG_TEXT[58];
						Link.l2.go = "Exit_RunFight";
					}
					else
					{
						//Check if you can pay
						if(makeint(Pchar.money) > pricePerk)
						{
							Diag.TempNode = "GetLost";
							if (PChar.sex == "woman") d.Text = PersuasionSuccess + DLG_TEXT[61] + DLG_TEXT[59] + " " + pricePerk + " " + DLG_TEXT[60];
							else d.Text = PersuasionSuccess + DLG_TEXT[56] + DLG_TEXT[59] + " " + pricePerk + " " + DLG_TEXT[60];
							Link.l1 = DLG_TEXT[57];
							Link.l1.go = "Exit_GetPerkPay";
							Link.l2 = DLG_TEXT[58];
							Link.l2.go = "Exit_Fight";
						}
						else
						{
							dialog.snd1 = "";
							dialog.snd2 = "";
							dialog.snd3 = "";
							d.Text = PersuasionFailure + RandPhrase(DLG_TEXT[24], DLG_TEXT[25], DLG_TEXT[26], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
							Link.l1 = DLG_TEXT[27];
							Link.l1.go = "Exit_Fight";	
						}
					}
				}
				else
				{
					dialog.snd1 = "";
					dialog.snd2 = "";
					dialog.snd3 = "";
					d.Text = PersuasionFailure + RandPhrase(DLG_TEXT[24], DLG_TEXT[25], DLG_TEXT[26], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
					Link.l1 = DLG_TEXT[27];
					Link.l1.go = "Exit_Fight";	
				}
			}
			else
			{
				if(CalcCharacterSkill(PChar,SKILL_FENCING) >= 7 && makeint(Pchar.Rank) >= 10 && Makeint(PChar.reputation) <= 30) //Upped the rank a bit by Levis, used to be 8
				{
					Diag.TempNode = "GetLost";
					dialog.snd1 = "";
					dialog.snd2 = "";
					dialog.snd3 = "";
					Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
					d.Text = PersuasionSuccess + RandPhrase(DLG_TEXT[15], DLG_TEXT[16], DLG_TEXT[17], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
					Link.l1 = LinkRandPhrase(DLG_TEXT[18], DLG_TEXT[19], DLG_TEXT[20]);
					Link.l1.go = "Exit_NoFight";
					Link.l99 = LinkRandPhrase(DLG_TEXT[21], DLG_TEXT[22], DLG_TEXT[23]);
					Link.l99.go = "Exit_RunFight";	
				}
				else
				{
					dialog.snd1 = "";
					dialog.snd2 = "";
					dialog.snd3 = "";
					d.Text = PersuasionFailure + RandPhrase(DLG_TEXT[24], DLG_TEXT[25], DLG_TEXT[26], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
					Link.l1 = DLG_TEXT[27];
					Link.l1.go = "Exit_Fight";	
				}
			}
		break;

		case "CheckMoney":
			if(makeint(makeint(Pchar.money)/20)*10 >= makeint(Pchar.rank)*100)
			{
				Diag.TempNode = "OnceAgain";
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[28], DLG_TEXT[29], DLG_TEXT[30], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = DLG_TEXT[31];
				Link.l1.go = "Exit_Robbed";				
			}
			else
			{
				Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
				d.Text = DLG_TEXT[32];
				Link.l1 = DLG_TEXT[33];
				Link.l1.go = "Exit_Fight";				
			}				
		break;

		case "OnceAgain":
			Diag.TempNode = "OnceAgain";
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[34], DLG_TEXT[35], DLG_TEXT[36], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[37];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[38];
			Link.l2.go = "Exit_Fight";
		break;
				
		case "GetLost":
			Diag.TempNode = "GetLost";
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			Preprocessor_Add("lad", GetMyAddressForm(NPChar, PChar, ADDR_INFORMAL, false, false)); // DeathDaisy
			d.Text = RandPhrase(DLG_TEXT[39], DLG_TEXT[40], DLG_TEXT[41], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[42];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[43];
			Link.l2.go = "Exit_Fight";
		break;

		case "GetTheHellOut":
			Diag.TempNode = "GetTheHellOut";
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			Preprocessor_Add("pronounsubj", FirstLetterUp(GetMyPronounSubj(PChar))); // DeathDaisy
			d.Text = RandPhrase(DLG_TEXT[44], DLG_TEXT[45], DLG_TEXT[46], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[47];
			Link.l1.go = "Exit";			
		break;

		// ccc stormy start
		case "join":
			AddCharacterCrew(pchar,makeint(10 + rand(10) ));
			pchar.ship.crew.morale=makeint(stf(pchar.ship.crew.morale) -20 ); 
			if(sti(pchar.ship.crew.morale)<1) { pchar.ship.crew.morale=1;}
			Diag.TempNode = "join";
			d.Text = DLG_TEXT[50];
			Link.l1 = DLG_TEXT[51] + GetMyShipNameShow(PChar) + DLG_TEXT[52];
			Link.l1.go = "exit_RunFight";			
		break;

		case "planks":
			AddCharacterGoods(pchar, GOOD_PLANKS, makeint(20 + rand(20)) );
		    PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -1500);
			Diag.TempNode = "planks";
			d.Text = DLG_TEXT[53];
			Link.l1 = DLG_TEXT[54] + GetMyShipNameShow(PChar) + DLG_TEXT[55];
			Link.l1.go = "exit_RunFight";			
		break;
		// ccc stormy start end

	}
}
