//#include "DIALOGS\Isla Mona Indian_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d; 
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- Диалог первый - первая встреча
		
		case "First time":
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
				NPC_Meeting = "1"; 
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(TimeGreeting() + DLG_TEXT[0], DLG_TEXT[1], DLG_TEXT[2], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = LinkRandPhrase(DLG_TEXT[3] + GetMyFullName(Pchar) + DLG_TEXT[4] + GetMyShipNameShow(PChar) + DLG_TEXT[5], DLG_TEXT[6] + GetMyFullName(Pchar) + DLG_TEXT[7], DLG_TEXT[8] + GetMyLastName(PChar) + DLG_TEXT[9]);
				Link.l1.go = "meeting";
			}
			else
			{
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[10] + GetMyLastName(PChar) + DLG_TEXT[11], DLG_TEXT[12] + GetMyLastName(PChar) + DLG_TEXT[13] + TimeGreeting() + DLG_TEXT[14], DLG_TEXT[15] + GetMyName(PChar) + DLG_TEXT[16], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(pcharrepphrase(DLG_TEXT[17], DLG_TEXT[18]), pcharrepphrase(DLG_TEXT[19], DLG_TEXT[20]), pcharrepphrase(DLG_TEXT[21], DLG_TEXT[22]));
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(pcharrepphrase(DLG_TEXT[23], DLG_TEXT[24]), pcharrepphrase(DLG_TEXT[25], DLG_TEXT[26]), pcharrepphrase(DLG_TEXT[27], DLG_TEXT[28]));
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(pcharrepphrase(DLG_TEXT[29], DLG_TEXT[30]), pcharrepphrase(DLG_TEXT[31], DLG_TEXT[32]), pcharrepphrase(DLG_TEXT[33], DLG_TEXT[34]));
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = DLG_TEXT[35];
					Link.l2.go = "colony";
				}
			}
			Link.l3 = pcharrepphrase(DLG_TEXT[36], DLG_TEXT[37]);
			Link.l3.go = "exit";
			Diag.TempNode = "First Time";
		break;

		case "Meeting":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[38] + GetMyFirstNames(PChar, false) + DLG_TEXT[39], DLG_TEXT[40], DLG_TEXT[41], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[42], DLG_TEXT[43], DLG_TEXT[44]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[45], DLG_TEXT[46], DLG_TEXT[47]);
					Link.l1.go = "town";
				}
				Link.l2 = LinkRandPhrase(DLG_TEXT[48], DLG_TEXT[49], DLG_TEXT[50]);
				Link.l2.go = "info";
				Link.l3 = DLG_TEXT[51];
				Link.l3.go = "exit";
		break;

		case "rumours":
				d.Text = RandPhrase(DLG_TEXT[129], DLG_TEXT[130], DLG_TEXT[131], &Dialog, "", "", "");
				Link.l1 = DLG_TEXT[52];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[53];
				Link.l2.go = "exit";
		break;

		case "new question":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[54] + GetMyLastName(PChar) + DLG_TEXT[55], DLG_TEXT[56] + GetMyName(PChar) + DLG_TEXT[57], DLG_TEXT[58] + GetMyFirstNames(PChar, false) + DLG_TEXT[59], &Dialog, "", "", "");
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[60], DLG_TEXT[61], DLG_TEXT[62]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[63], DLG_TEXT[64], DLG_TEXT[65]);
					Link.l1.go = "town";
				}
				Link.l2 = LinkRandPhrase(DLG_TEXT[66], DLG_TEXT[67], DLG_TEXT[68]);
				Link.l2.go = "info";
				Link.l3 = DLG_TEXT[69];
				Link.l3.go = "exit";
		break;

		case "info":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[70] + GetMyFirstNames(PChar, false) + DLG_TEXT[71], DLG_TEXT[72], DLG_TEXT[73], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = DLG_TEXT[74];
				Link.l1.go = "governor";
				Link.l2 = DLG_TEXT[75];
				Link.l2.go = "tavernkeeper";
				if (rand(2) == 2)
				{
					Link.l3 = DLG_TEXT[76];
					Link.l3.go = "shipwright";
				}
//				else 
//				{
//					Link.l3 = DLG_TEXT[77];
//					Link.l3.go = "localtrader";
//				}
				Link.l4 = DLG_TEXT[78];
				Link.l4.go = "new question";
		break;

		case "governor":				
				d.Text = DLG_TEXT[79];
				Link.l1 = DLG_TEXT[80];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[81];
				Link.l2.go = "exit";
		break;

		case "tavernkeeper":
				d.Text = DLG_TEXT[82];
				Link.l1 = DLG_TEXT[80];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[81];
				Link.l2.go = "exit";
		break;

		case "shipwright":
				d.Text = DLG_TEXT[83];
				Link.l1 = DLG_TEXT[80];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[81];
				Link.l2.go = "exit";
		break;

		case "localtrader":
				d.Text = DLG_TEXT[84];
				Link.l1 = DLG_TEXT[80];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[81];
				Link.l2.go = "exit";
		break;


		case "town":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[85] + GetMyFirstNames(PChar, false) + DLG_TEXT[86], DLG_TEXT[87], DLG_TEXT[88] + GetMyFirstNames(PChar, false) + DLG_TEXT[89], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[90];
			Link.l1.go = "town_tavern";
			if (rand(2) == 2)
			{
				Link.l2 = DLG_TEXT[91];
				Link.l2.go = "town_shipyard";
			}
//			Link.l3 = DLG_TEXT[92];
//			Link.l3.go = "town_store";
		break;

		case "town_tavern":
			d.Text = DLG_TEXT[93];
			Link.l1 = DLG_TEXT[94];
			Link.l1.go = "exit";
//			Link.l2 = DLG_TEXT[96];
//			Link.l2.go = "town_store";
		break;

		case "town_shipyard":
			d.Text = DLG_TEXT[97];
			Link.l1 = DLG_TEXT[98];
			Link.l1.go = "town_tavern";
//			Link.l2 = DLG_TEXT[99];
//			Link.l2.go = "town_store";
			Link.l3 = DLG_TEXT[100];
			Link.l3.go = "exit";
		break;

		case "town_store":
			d.Text = DLG_TEXT[101];
			Link.l1 = DLG_TEXT[102];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[104];
			Link.l2.go = "exit";
		break;

		case "colony":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[105] + GetMyFirstNames(PChar, false) + DLG_TEXT[106], DLG_TEXT[107], DLG_TEXT[108] + GetMyFirstNames(PChar, false) + DLG_TEXT[109], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			if(Rand(1)== 0)
			{
				Link.l1 = DLG_TEXT[110];
				Link.l1.go = "Fleur";
			}
			else
			{
				Link.l1 = DLG_TEXT[111];
				Link.l1.go = "island";
			}
			Link.l2 = DLG_TEXT[112];
			Link.l2.go = "new question";
		break;

		case "Fleur":
			d.Text = DLG_TEXT[113];
			Link.l1 = DLG_TEXT[114];
			Link.l1.go = "Fleur_1";
			Link.l2 = DLG_TEXT[115];
			Link.l2.go = "new question";
		break;

		case "Fleur_1":
			d.Text = DLG_TEXT[116];
			Link.l1 = DLG_TEXT[117];
			Link.l1.go = "new question";
		break;

		case "island":
			switch(Rand(2))
			{	
				case 0:
					d.Text = DLG_TEXT[118];
					Link.l1 = DLG_TEXT[119];
					Link.l1.go = "island";
				break;

				case 1:
					d.Text = DLG_TEXT[120];
					Link.l1 = DLG_TEXT[121];
					Link.l1.go = "island";
				break;

				case 2:
					d.Text = DLG_TEXT[122];
					Link.l1 = DLG_TEXT[123];
					Link.l1.go = "colony";
				break;
			}
			Link.l2 = DLG_TEXT[124];
			Link.l2.go = "new question";
			Link.l3 = DLG_TEXT[125];
			Link.l3.go = "exit";
		break;
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}
