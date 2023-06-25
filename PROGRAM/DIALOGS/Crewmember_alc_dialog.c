//#include "DIALOGS\Crewmember_alc_dialog.h"

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
	int con, maxcrew;
	
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
			
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			if(sti(GetStorylineVar(FindCurrentStoryline(), "NO_CREW_OR_OFFICERS")) < 1)
			{
				link.l2 = DLG_TEXT[2];
				link.l2.go = "Howmany";
			}
			//Link.l3 = DLG_TEXT[3];
			//Link.l3.go = "clothesyou";
			Diag.TempNode = "first time";
		break;

		case "Howmany":
			Dialog.Text = DLG_TEXT[4];
			maxcrew = GetMaxLandCrew(sti(PChar.Ship.Crew.Quantity));
			if(maxcrew > 0)
			{ 
				link.l1 = DLG_TEXT[5];
				link.l1.go ="one";
				if(maxcrew>=2)
				{
					link.l2 = DLG_TEXT[6];
					link.l2.go = "two";
				}
				if(maxcrew>=3)
				{
					link.l3 = DLG_TEXT[7];
					link.l3.go = "three";
				}
				if(maxcrew>=4)
				{
					link.l4 = DLG_TEXT[8];
					link.l4.go = "four";
				}
				if(maxcrew>=5)
				{
					link.l5 = DLG_TEXT[9];
					link.l5.go = "five";
				}
				if(maxcrew>=6)
				{
					link.l6 = DLG_TEXT[10];
					link.l6.go = "six";
				}
				if(maxcrew>=7)
				{
					link.l7 = DLG_TEXT[11];
					link.l7.go = "seven";
				}
				if(maxcrew>=8)
				{
					link.l8 = DLG_TEXT[12];
					link.l8.go = "eight";
				}
				if(maxcrew>=9)
				{
					link.l9 = DLG_TEXT[13];
					link.l9.go = "nine";
				}
				if(maxcrew>=10)
				{
					link.l10 = DLG_TEXT[14];
					link.l10.go = "ten";
				}
			}
			link.l11 = DLG_TEXT[26];
			link.l11.go = "exit";
		break;

		case "one":
			Dialog.Text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 1;
		break;

		case "two":
			Dialog.Text = DLG_TEXT[16];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 2;
		break;

		case "three":
			Dialog.Text = DLG_TEXT[17];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 3;
		break;

		case "four":
			Dialog.Text = DLG_TEXT[18];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 4;
		break;

		case "five":
			Dialog.Text = DLG_TEXT[19];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 5;
		break;

		case "six":
			Dialog.Text = DLG_TEXT[20];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 6;
		break;

		case "seven":
			Dialog.Text = DLG_TEXT[21];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 7;
		break;

		case "eight":
			Dialog.Text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 8;
		break;

		case "nine":
			Dialog.Text = DLG_TEXT[23];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 9;
		break;

		case "ten":
			Dialog.Text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "exit";
			LANDCREWMEMBERS = true;
			MAX_CREWMEMBERS = 10;
		break;

		case "clothesyou":
			DialogExit();
			LaunchKAMSelectOfficerModel(sti(NPChar.index)); // KK
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
