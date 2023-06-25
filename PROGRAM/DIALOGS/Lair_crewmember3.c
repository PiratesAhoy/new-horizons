//#include "DIALOGS\Lair_crewmember3.h"
void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	int iOurCharacterIndex = GetEventData();
	ref rOurCharacter = GetCharacter(iOurCharacterIndex);
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

		case "Jungle_expedition":
			d.Text = DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "Planks";
			Link.l2 = DLG_TEXT[7];
			Link.l2.go = "exit";
		break;

		case "Planks":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			WaitDate("", 0,0,1,0,0);
			int casualties = makeint(sti(rOurCharacter.Ship.Crew.Quantity)* rand(3)/100 );	// a few men may die
			RemoveCharacterCrew(rOurCharacter,casualties);
			int foodboarded = MakeInt(Pchar.skill.sneak);
			AddCharacterGoods(Pchar, GOOD_WHEAT, makeint(foodboarded));
			Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"Captain, we killed and fished for") + " " + foodboarded + " " + LanguageConvertString(tmpLangFileID,"rations today"));
			if(casualties>0) 
			{
				Log_SetStringToLog(LanguageConvertString(tmpLangFileID,"but") + " " + sti(casualties) + " " + LanguageConvertString(tmpLangFileID,"men were killed by wild jungle or disappeared.."));
				PlaySound("OBJECTS\VOICES\DEAD\monkey\monkey_dead1.wav");
			}
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

			if(TradeCheck(PChar, NPChar, true)) { // NK
			if(NPChar.quest.meeting == "0")
			{
				d.Text = DLG_TEXT[0];
				Link.l1 = DLG_TEXT[1];
				Link.l1.go = "meeting";
				NPC_Meeting = "1"; 
			}
			else
			{
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = DLG_TEXT[8];
				Link.l1 = DLG_TEXT[3] + DLG_TEXT[4];
				Link.l1.go = "Jungle_expedition";
				Link.l2 = DLG_TEXT[10];
				Link.l2.go = "clothesyou";
				Link.l3 = DLG_TEXT[9];
				Link.l3.go = "exit";
			}
			// NK -->
			}
			else
			{
				dialog.text = DLG_TEXT[11] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[12];
				Link.l1 = DLG_TEXT[13];
				Link.l1.go = "exit";
			}
			// NK <--
			Diag.TempNode = "First Time";
		break;

		case "Meeting":
				d.Text = DLG_TEXT[2];
				Link.l1 = DLG_TEXT[3] + DLG_TEXT[4];
				Link.l1.go = "Jungle_expedition";
				Link.l2 = DLG_TEXT[10];
				Link.l2.go = "clothesyou";
				Link.l3 = DLG_TEXT[9];
				Link.l3.go = "exit";

		break;

		case "clothesyou":
			DialogExit();
			LaunchKAMSelectOfficerModel(sti(NPChar.index)); // KK
		break;
	}
	LanguageCloseFile(tmpLangFileID);
}
