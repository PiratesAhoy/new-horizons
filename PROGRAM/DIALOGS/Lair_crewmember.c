//#include "DIALOGS\Lair_crewmember.h"
void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	int iTest;
	int i;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "wait_time":
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "wait_1";
			Link.l2 = DLG_TEXT[2];
			Link.l2.go = "wait_2";
			Link.l3 = DLG_TEXT[24];
			Link.l3.go = "wait_3";
			Link.l4 = DLG_TEXT[25];
			Link.l4.go = "wait_4";
			Link.l5 = DLG_TEXT[3];
			Link.l5.go = "exit";
		break;

		case "wait_1":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			WaitDate("", 0,0,1,0,0);
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You wait here 1 day for ship repairs") + ".");
			PlaySound("ambient\shipyard\axe.wav");
			PlaySound("ambient\shipyard\vehicle.wav");
		break;

		case "wait_2":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			for(i = 0; i < 5; i++)
			{
				WaitDate("", 0,0,1,0,0);
			}
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You wait here 5 days for ship repairs") + ".");
			PlaySound("ambient\shipyard\axe.wav");
			PlaySound("ambient\shipyard\vehicle.wav");
		break;
		
		case "wait_3":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			for(i = 0; i < 10; i++)
			{
				WaitDate("", 0,0,1,0,0);
			}
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You wait here 10 days for ship repairs") + ".");
			PlaySound("ambient\shipyard\axe.wav");
			PlaySound("ambient\shipyard\vehicle.wav");
		break;

		case "wait_4":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			for(i = 0; i < 30; i++)
			{
				WaitDate("", 0,0,1,0,0);
			}
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"You wait here all a month for ship repairs") + ".");
			PlaySound("ambient\shipyard\axe.wav");
			PlaySound("ambient\shipyard\vehicle.wav");
		break;

		case "First time":
			Dialog.defAni = "Gov_Dialog_1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Gov_Dialog_1";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			if(NPChar.quest.meeting == "0")
			{
				d.Text = DLG_TEXT[4] + DLG_TEXT[5];
				Link.l1 = DLG_TEXT[6];
				Link.l1.go = "meeting";
				NPC_Meeting = "1"; 
			}
			else
			{
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(TimeGreeting() + DLG_TEXT[8] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + DLG_TEXT[9] + DLG_TEXT[10], DLG_TEXT[11] + DLG_TEXT[12], DLG_TEXT[13], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = DLG_TEXT[14];
				Link.l1.go = "Wait_Time";
				Link.l2 = DLG_TEXT[26];
				Link.l2.go = "clothesyou";
				Link.l3 = DLG_TEXT[16];
				Link.l3.go = "exit";
			}
			Diag.TempNode = "First Time";
		break;

		case "Meeting":
				d.Text = DLG_TEXT[17] + DLG_TEXT[18] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + "?";
				Link.l1 = DLG_TEXT[19] + DLG_TEXT[20];
				Link.l1.go = "Wait_Time";
				Link.l2 = DLG_TEXT[26];
				Link.l2.go = "clothesyou";
				Link.l3 = DLG_TEXT[23];
				Link.l3.go = "exit";

		break;

		case "clothesyou":
			DialogExit();
			LaunchKAMSelectOfficerModel(sti(NPChar.index)); // KK
		break;

				
	}
	LanguageCloseFile(tmpLangFileID);
}
