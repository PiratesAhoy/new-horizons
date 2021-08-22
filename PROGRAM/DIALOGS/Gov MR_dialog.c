// changed by MAXIMUS [moved here from Conversation.h] -->
//#include "DIALOGS\ENGLISH\Conversation.h"
//#include "DIALOGS\RUSSIAN\Conversation.h"
//#include "DIALOGS\FRENCH\Conversation.h" // uncomment this for French version
//#include "DIALOGS\GERMAN\Conversation.h" // uncomment this for German version
//#include "DIALOGS\SPANISH\Conversation.h" // uncomment this for Spanish version
#define MAX_FLIRT 64
int FLIRT_QUANTITY = 0;
#define MAX_PROP 64
int PROP_QUANTITY = 0;

string Flirt[MAX_FLIRT];
string Prop[MAX_PROP];

string RandFlirt(ref NPChar) {return Flirt[Rand(FLIRT_QUANTITY-1)]; }
string RandProp(ref NPChar) {return Prop[Rand(PROP_QUANTITY-1)]; }
// changed by MAXIMUS [moved here from Conversation.h] <--
#include "DIALOGS\Conversation.c"

void ProcessDialogEvent()
{
	InitConversation();
	if(GetMusicScheme() == "PGMUS") SetMusicNoPause("music_niece"); // PG // KK
	ref NPChar, PChar, d; 
	PChar = GetMainCharacter();
	aref Link, Diag;
	string tempt1, tempt2;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	int nat = sti(NPChar.nation);
	int repchg = 0;

	
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iDay + " " + iMonth;
	SetCurrentMR(&NPChar);
	
	switch(Dialog.CurrentNode)
	{
		
		case "exit":
			if(sti(NPChar.married) == MR_SINGLE) // sti(NPChar.talkpoints) == 0 && 
			{
				PChar.quest.RemoveMRs.win_condition.l1 = "ExitFromLocation";
				PChar.quest.RemoveMRs.win_condition.l1.location = PChar.location;
				PChar.quest.RemoveMRs.win_condition = "RemoveMRs";
				PChar.quest.RemoveMRs.skip = "yes";
			}
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "First time":
			if(!CheckAttribute(NPChar,"quest.meeting")) NPChar.quest.meeting = "0";
			if(!CheckAttribute(NPChar,"married")) NPChar.married = MR_SINGLE;
			nat = sti(NPChar.nation);
			SetCurrentMR(&NPChar);
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			if(NPChar.quest.meeting == "0")
			{
				NPChar.quest.meeting = "1";
				NPChar.quest.colombian_silver.counter = 0;	// Initialise counter for "Colombian Silver" sidequest
				tempt1 = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_TITLE, false, false) + DLG_TEXT[1];
				if(MRCanMarryRatio(PChar, NPChar, false) > 0.33) tempt1 = DLG_TEXT[2] + GetMyAddressForm(NPChar, PChar, ADDR_TITLE, false, false) +DLG_TEXT[3];
				if(MRCanMarryRatio(PChar, NPChar, false) > 0.67) tempt1 = DLG_TEXT[4];
				d.text = tempt1;
				Link.l1 = DLG_TEXT[5] + GetMyAddressForm(NPChar, PChar, ADDR_TITLE, true, true) + DLG_TEXT[6] + GetMyShipNameShow(PChar) + DLG_TEXT[7];
				Link.l1.go = "Meeting";
			}
			else
			{
				tempt1 = DLG_TEXT[8] + GetMyAddressForm(NPChar, PChar, ADDR_TITLE, false, false) + ".";
				if(MRCanMarryRatio(PChar, NPChar, false) > 0.33) tempt1 =  DLG_TEXT[9] + GetMyName(PChar) + DLG_TEXT[10];
				if(MRCanMarryRatio(PChar, NPChar, false) > 0.67) tempt1 = DLG_TEXT[11] + GetMyName(PChar) + DLG_TEXT[12];
				if(sti(NPChar.married)) tempt1 = DLG_TEXT[13];
				d.text = tempt1;
				Link.l3 = DLG_TEXT[14];
				Link.l3.go = "exit";
				if(CheckAttribute(NPChar,"skiptext")) { d.text = DLG_TEXT[15]; Link.l3 = DLG_TEXT[16]; }
				bool tt = false;
				tt = NPChar.quest.Meeting != lastspeak_date || sti(NPChar.talkpoints) == 0;
				// uncomment for debug - tt = true;
				if (tt && sti(NPChar.married) == MR_SINGLE && sti(PChar.married) == MR_SINGLE)
				{
					Link.l1 = RandFlirt(NPChar); //+ " " + DLG_TEXT[17];
					Link.l1.go = "makeconv";
					if(sti(PChar.married) == false)
					{
						Link.l2 = RandProp(NPChar); // + " " + DLG_TEXT[18];
						Link.l2.go = "propose";
					}
				}
				NPChar.quest.Meeting = lastspeak_date;
				if(sti(NPChar.married))
				{
					NPChar.quest.colombian_silver.counter = sti(NPChar.quest.colombian_silver.counter) + 1;	// GR: Increase chance of triggering "Colombian Silver" sidequest
					Link.l1 = DLG_TEXT[19];
					Link.l1.go = "info";
					if(sti(NPChar.pcounter))
					{
						Link.l2 = PCharRepPhrase(DLG_TEXT[20], DLG_TEXT[21]);
						Link.l2.go = "private";
					}
				}
				else
				{
					if(sti(NPChar.talkpoints))
					{
						if (NPChar.sex == "woman") Link.l4 = PCharRepPhrase(DLG_TEXT[55], DLG_TEXT[56]);
						else Link.l4 = PCharRepPhrase(DLG_TEXT[79], DLG_TEXT[56]);
						Link.l4.go = "dump";
					}
				}
				if(CheckAttribute(NPChar,"skiptext")) { DeleteAttribute(NPChar,"skiptext"); }
			}
			break;

		case "Meeting":
			nat = sti(NPChar.nation);
			tempt1 = DLG_TEXT[22] + GetMyFullName(NPChar) + DLG_TEXT[23] + GetMyAddressForm(NPChar, PChar, ADDR_TITLE, false, true) + ".";
			if(MRCanMarryRatio(PChar, NPChar, false) > 0.33) tempt1 = DLG_TEXT[24] + GetMyFullName(NPChar) + DLG_TEXT[25] + stringRet(GetRank(PChar, nat) >= 0, ", " + XI_ConvertString(GetRankName(PChar, nat)),"") + "!";
			if(MRCanMarryRatio(PChar, NPChar, false) > 0.67) tempt1 = GetMyAddressForm(NPChar, PChar, ADDR_TITLE, false, true) + DLG_TEXT[26];
			d.text = tempt1;
			if (NPChar.sex == "woman") Link.l1 = DLG_TEXT[27];
			else Link.l1 = DLG_TEXT[77];
			Link.l1.go = "First Time";
			NPChar.skiptext = true;
		break;

		case "makeconv":
			SetCurrentMR(&NPChar);
			nat = sti(NPChar.nation);
			if (NPChar.sex == "woman") Preprocessor_Add("lady", XI_Convertstring("gentlewoman"));
			else Preprocessor_Add("lady", XI_Convertstring("gentleman"));
			d.text = DLG_TEXT[28];
			Link.l1 = DLG_TEXT[29];
			Link.l1.go = "exit";
			MRAddTalkPoints(&PChar, &NPChar);
			if(MRCanMarry(&PChar, &NPChar, false) && sti(PChar.married) == MR_SINGLE)
			{
				Preprocessor_Add("pronoun", FirstLetterUp(XI_ConvertString(GetMyPronounSubj(NPChar))));
				d.text = DLG_TEXT[30] + NPChar.relationtype + DLG_TEXT[31];
				NPChar.pcounter = 1;
				NPChar.married = MR_MISTRESS;
				tempt1 = NPChar.id;
				PChar.mistress.(tempt1) = true;
			}
		break;

		case "private":
			d.text = DLG_TEXT[32];
			Link.l1 = DLG_TEXT[33];
			Link.l1.go = "exit_wait";
		break;

		case "propose":
			SetCurrentMR(&NPChar);
			MRAddTalkPoints(&PChar, &NPChar);
			if(MRCanMarry(&PChar, &NPChar, true))
			{
				Preprocessor_Add("man", XI_ConvertString(PChar.sex));
				Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(PChar)));
				d.text = DLG_TEXT[34] + GetMyName(PChar) + DLG_TEXT[35];
				Link.l1 = DLG_TEXT[36];
				Link.l1.go = "duel";
				Link.l2 = DLG_TEXT[37];
				Link.l2.go = "noduel";
			}
			else
			{
				d.text = DLG_TEXT[38] + GetMyName(PChar) + DLG_TEXT[39];
				Link.l1 = DLG_TEXT[40];
				Link.l1.go = "exit";
			}
		break;

		case "info":
			tempt1 = DLG_TEXT[41] + GetMarriedName(&NPChar) + DLG_TEXT[42];
			tempt1+= DLG_TEXT[43];
			d.text = tempt1;
			Link.l1 = DLG_TEXT[44];
			Link.l1.go = "exit";

			if(!CheckAttribute(PChar, "quest.colombian_silver") && rand(7) <= sti(NPChar.quest.colombian_silver.counter))
			{
				d.text = DLG_TEXT[69 + rand(2)];
				link.l1 = DLG_TEXT[72];
				link.l1.go = "exit_accept_colombian_silver";
				link.l2 = DLG_TEXT[73];
				link.l2.go = "exit_reject_colombian_silver";
				if(GetRMRelation(PChar, SPAIN) >= REL_AMNESTY)
				{
					link.l3 = DLG_TEXT[74];
					if(IsInServiceOf(SPAIN))
					{
						link.l3 = DLG_TEXT[75] + TranslateString(GetRankName(PChar, SPAIN),"") + DLG_TEXT[76];
					}
					link.l3.go = "exit_reject_colombian_silver";
				}
			}
		break;

		case "dump":
			Diag.TempNode = "dump";
			d.text = PCharRepPhrase(DLG_TEXT[57], DLG_TEXT[58]);
			if(sti(NPChar.talkpoints))
			{
				//NPChar.talkpoints = 0; why HERE? should be down below.
				float avetp = (MRGetAddTalkPoints(&PChar, &NPChar)+MRGetAddTalkPoints(&PChar, &NPChar)+MRGetAddTalkPoints(&PChar, &NPChar)+MRGetAddTalkPoints(&PChar, &NPChar)+MRGetAddTalkPoints(&PChar, &NPChar))/5.0;
				if(stf(NPChar.talkpoints)/avetp > MR_MINREP_TPTIMES)
				{
					float repch = stf(NPChar.talkpoints) / avetp * MR_REPPEN_SCALAR;
					if(repch > MR_MAXREPPENALTY) repch = MR_MAXREPPENALTY;
					repch *= stf(PCharRepPhrase("-1", "-2"));
					//ChangeCharacterReputation(PChar, repch);// prior float used (wrong)
					ChangeCharacterReputation(PChar, makeint(repch));// TIH changed to use proper int format Aug29'06
				}
				else
				{
					ChangeCharacterReputation(PChar, sti(PCharRepPhrase("-1", "-5")));// TIH added missing ';', stf to sti Agu29'06
				}
				NPChar.talkpoints = 0;
			}
			Link.l1 = PCharRepPhrase(DLG_TEXT[59], DLG_TEXT[60]);
			Link.l1.go = "exit";
		break;

		case "duel":
			PChar.marriageduel.MRid = NPChar.id;
			AddDialogExitQuest("marriageduel");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "noduel":
			NPChar.talkpoints = 1; //fix so not removed
			ChangeCharacterReputation(&PChar, -10);
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "married":
			DeleteAttribute(PChar,"marriageduel");
			NPChar.pcounter = 0;
			NPChar.married = MR_MARRIED;
			PChar.married = MR_MARRIED;
			PChar.married.id = NPChar.id;
			int ix = GetTownGovernorIndex (GetCurrentTownID());
//			WriteNewLogEntry("Married my beautiful wife", "On this wonderful day I married my beautiful wife, "+NPChar.name+" "+NPChar.lastname+", daugther of "+Characters[ix].name+" "+Characters[ix].lastname+", the governor of "+FindTownName(GetCurrentTownID())+". I won her heart with my wit and charm, and last but not least with my swordmanship, as I had to defeat her jealous suitor, before she could agree to a marriage. We're both very happy, and now I am going to finish this writing, because I have something more important to do ...","Personal",true);
			if (PChar.sex == "man") WriteNewLogEntry("Married my beautiful wife", "On this wonderful day I married my beautiful wife, "+GetMySimpleName(NPChar)+", "+XI_ConvertString(NPChar.relationtype)+" of "+GetMySimpleName(Characters[ix])+", the governor of "+FindTownName(GetCurrentTownID())+". I won her heart with my wit and charm, and last but not least with my swordmanship, as I had to defeat her jealous suitor, before she could agree to a marriage. We're both very happy, and now I am going to finish this writing, because I have something more important to do ...","Personal",true);
			else WriteNewLogEntry("Married my handsome husband", "On this wonderful day I married my handsome husband, "+GetMySimpleName(NPChar)+", "+XI_ConvertString(NPChar.relationtype)+" of "+GetMySimpleName(Characters[ix])+", the governor of "+FindTownName(GetCurrentTownID())+". I won his heart with my wit and charm, and last but not least with my swordmanship, as I had to defeat his jealous suitor, before he could agree to a marriage. We're both very happy, and now I am going to finish this writing, because I have something more important to do ...","Personal",true);
			d.text = DLG_TEXT[45];
			Link.l1 = DLG_TEXT[46];
			Link.l1.go = "married2";
		break;

		case "married2":
			d.text = DLG_TEXT[47];
			Link.l1 = DLG_TEXT[48];
			Link.l1.go = "exit_wait";
		break;

		case "exit_wait":
			NPChar.pcounter = sti(NPChar.pcounter) + 1;
			if(sti(NPChar.pcounter)>8)
			{
				NPChar.pcounter = 1; // for now, you can do this as often as you like.
			}
			if(AUTO_SKILL_SYSTEM) { AddCharacterExpNSChar(&PChar, "Leadership", sti(NPChar.marpoints) * 3); }
			else { AddCharacterExpNS(&PChar, sti(NPChar.marpoints) * 3); }
			MRAddTalkpoints(PChar, NPChar); //Well, I would /hope/ so...
			Log_SetStringToLog("" + DLG_TEXT[49]);
			repchg = 0;
			if(sti(NPChar.married) == MR_MARRIED) repchg = 2;
			else
			{
				if(sti(PChar.married)) { repchg = -3; }
				else { repchg = -1; }
			}
			ChangeCharacterReputation(&PChar, repchg);
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			TavernWaitDate("wait_night");
			TavernWaitDate2("wait_day");
		break;

		// suitor dialog
		case "engarde":
			if (PChar.sex == "man") d.text = Characters[GetCharacterIndex(PChar.marriageduel.MRid)].name + DLG_TEXT[50];
			else  d.text = Characters[GetCharacterIndex(PChar.marriageduel.MRid)].name + DLG_TEXT[78];
			Link.l1 = DLG_TEXT[51];
			Link.l1.go = "exit_duel";
		break;

		case "duelend":
			d.text = DLG_TEXT[52] + GetMyAddressForm(&NPChar, &PChar, ADDR_TITLE, false, false) + DLG_TEXT[53];
			Link.l1 = DLG_TEXT[54];
			Link.l1.go = "exit_duelend";
		break;

		case "exit_duel":
			AddDialogExitQuest("marriageduel_fight");
			DialogExit();
		break;

		case "exit_duelend":
			Diag.CurrentNode = "First Time";
			AddDialogExitQuest("marriageduel_end");
			DialogExit();
		break;

		// Exits for "Colombian Silver"
		case "exit_accept_colombian_silver":
			SetQuestHeader("colombian_silver");
			Preprocessor_AddQuestData("name", GetMyFullName(NPChar));
			AddQuestRecord("colombian_silver", 1);
			Preprocessor_Remove("name");
			AddDialogExitQuest("colombian_silver_prepare_taverns");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "exit_reject_colombian_silver":
			AddDialogExitQuest("colombian_silver_reject_quest");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		// Wedding
		case "her_answer":
			d.text = DLG_TEXT[61];
			Link.l1 = DLG_TEXT[44];
			Link.l1.go = "kiss_the_bride";
		break;

		case "kiss_the_bride":
			d.text = DLG_TEXT[62];
			Link.l1 = DLG_TEXT[63];
			WriteNewLogEntry("Married my beautiful wife", "On this wonderful day I married my beautiful wife, "+GetMySimpleName(NPChar)+". We're both very happy, and now I am going to finish this writing, because I have something more important to do...","Personal",true);
			Link.l1.go = "exit";
		break;

		case "consent_answer1":
			d.text = DLG_TEXT[64];
			if (NPChar.sex == "woman") Link.l1 = DLG_TEXT[60];
			else Link.l1 = DLG_TEXT[68];
			Link.l1.go = "exit";
		break;

		case "consent_answer2":
			d.text = DLG_TEXT[64];
			if (NPChar.sex == "woman") Link.l1 = DLG_TEXT[60];
			else Link.l1 = DLG_TEXT[65];
			Link.l1.go = "exit";
		break;

		case "consent_answer3":
			d.text = DLG_TEXT[65];
			if (NPChar.sex == "woman") Link.l1 = DLG_TEXT[60];
			else Link.l1 = DLG_TEXT[66];
			Link.l1.go = "exit";
		break;

		case "he_gives_ring":
			if (NPChar.sex == "woman")
			{
				d.text = "";
				Link.l1 = PChar.quest.bride + DLG_TEXT[67];
				Link.l1.go = "she_gives_ring";
			}
			else
			{
				d.text = PChar.quest.bride + DLG_TEXT[67];
				Link.l1 = PChar.quest.groom + DLG_TEXT[67];
				Link.l1.go = "exit";
			}
		break;

		case "she_gives_ring":
			d.text = PChar.quest.groom + DLG_TEXT[67];
			Link.l1 = DLG_TEXT[60];
			Link.l1.go = "exit";
		break;

		case "vow_answer":
			d.text = DLG_TEXT[61];
			Link.l1 = DLG_TEXT[60];
			Link.l1.go = "exit";
		break;

	} // end of switch; 

}
// RM <--

