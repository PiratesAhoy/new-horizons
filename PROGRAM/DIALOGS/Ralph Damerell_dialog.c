//#include "DIALOGS\Ralph Damerell_dialog.h"
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
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
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
			Dialog.snd = "dialogs\0\009";

			if(NPChar.quest.meeting == "0")
			{
				NPC_Meeting = "1"; 
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(TimeGreeting() + DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1] + GetMyFullName(NPChar) + DLG_TEXT[2], DLG_TEXT[3] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[4] + GetMyFullName(NPChar) + DLG_TEXT[5], DLG_TEXT[6] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[7] + GetMyFullName(NPChar) + DLG_TEXT[8], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = RandPhrase(DLG_TEXT[9] + GetMyFullName(PChar) + DLG_TEXT[10] + GetMyShipNameShow(PChar) + DLG_TEXT[11], DLG_TEXT[12] + GetMyFullName(PChar) + DLG_TEXT[13], DLG_TEXT[14] + GetMyName(Pchar) + DLG_TEXT[15]);
				Link.l1.go = "Meeting";
			}
			else
			{
				if(NPChar.sex == "man")
				     d.Text = RandPhrase(DLG_TEXT[16] + GetMyName(Pchar) + DLG_TEXT[17], DLG_TEXT[18] + GetMyRespectfullyName(PChar) + DLG_TEXT[19], DLG_TEXT[20] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + Pchar.lastname + DLG_TEXT[21]);
				else
				     d.Text = RandPhrase(DLG_TEXT[22] + GetMyName(Pchar) + DLG_TEXT[23], DLG_TEXT[24] + GetMyRespectfullyName(PChar) + DLG_TEXT[25], DLG_TEXT[26] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + Pchar.lastname + DLG_TEXT[27]);                     

				if(Rand(1)==0)
				{
					Link.l1 = RandPhrase(DLG_TEXT[28], DLG_TEXT[29], DLG_TEXT[30]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = RandPhrase(DLG_TEXT[31], DLG_TEXT[32], DLG_TEXT[33]);
					Link.l1.go = "town";
				}
				if (CheckQuestAttribute("Find_Blaze", "Ask_Barman"))
				{
					Link.l4 = DLG_TEXT[34];
					Link.l4.go = "dont_know_Blaze";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = RandPhrase(DLG_TEXT[35], DLG_TEXT[36], DLG_TEXT[37]);
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = RandPhrase(DLG_TEXT[38], DLG_TEXT[39], DLG_TEXT[40]);
					Link.l2.go = "colony";
				}

				Link.l3 = DLG_TEXT[41];
				Link.l3.go = "exit";
			}
		break;

		case "Meeting":
				d.Text = RandPhrase(DLG_TEXT[42], DLG_TEXT[43] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[44], DLG_TEXT[45] + GetMyName(Pchar) + DLG_TEXT[46]);
				if(Rand(1)==0)
				{
					Link.l1 = RandPhrase(DLG_TEXT[47], DLG_TEXT[48], DLG_TEXT[49]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = RandPhrase(DLG_TEXT[50], DLG_TEXT[51], DLG_TEXT[52]);
					Link.l1.go = "town";
				}
				if (CheckQuestAttribute("Find_Blaze", "Ask_Barman"))
				{
					Link.l4 = DLG_TEXT[53];
					Link.l4.go = "dont_know_Blaze";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = RandPhrase(DLG_TEXT[54], DLG_TEXT[55], DLG_TEXT[56]);
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = RandPhrase(DLG_TEXT[57], DLG_TEXT[58], DLG_TEXT[59]);
					Link.l2.go = "colony";
				}


				Link.l3 = DLG_TEXT[60];
				Link.l3.go = "exit";
		break;

		case "rumours":
				d.Text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) );
				Link.l1 = DLG_TEXT[61];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[62];
				Link.l2.go = "exit";
		break;

		case "new question":
				d.Text = RandPhrase(DLG_TEXT[63] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[64], DLG_TEXT[65] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[66], DLG_TEXT[67]);
				if(Rand(1)==0)
				{
					Link.l1 = RandPhrase(DLG_TEXT[68], DLG_TEXT[69], DLG_TEXT[70]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = RandPhrase(DLG_TEXT[71], DLG_TEXT[72], DLG_TEXT[73]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = RandPhrase(DLG_TEXT[77], DLG_TEXT[78], DLG_TEXT[79]);
					Link.l2.go = "colony";
				}
				else
				{
					Link.l2 = RandPhrase(DLG_TEXT[77], DLG_TEXT[78], DLG_TEXT[79]);
					Link.l2.go = "colony";
				}

				Link.l3 = DLG_TEXT[80];
				Link.l3.go = "exit";
		break;

		case "info":
				d.Text = RandPhrase(DLG_TEXT[81] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[82], DLG_TEXT[83], DLG_TEXT[84] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[85]);
				if(Rand(1)==0)
				{	
					TempInfoCharacterID_1 = "Charles Windem";
					Link.l1 = DLG_TEXT[86];
					Link.l1.go = "info_1";
				}
				else
				{
					TempInfoCharacterID_1 = "Simon Hanpool";
					Link.l1 = DLG_TEXT[87] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[88])]) + DLG_TEXT[90];
					Link.l1.go = "info_1";
				}
				if(Rand(1)==0)	
				{
					TempInfoCharacterID_2 = "David Fairweather";
					Link.l2 = DLG_TEXT[91] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[92])]) + DLG_TEXT[94];
					Link.l2.go = "info_2";
				}
				else 
				{
					TempInfoCharacterID_2 = "John  Filbert";
					Link.l2 = DLG_TEXT[95] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[96])]) + DLG_TEXT[98];
					Link.l2.go = "info_2";
				}
				Link.l3 = DLG_TEXT[99];
				Link.l3.go = "new question";
		break;

		case "info_1":
				trace("Айдишник персонажа - " + TempInfoCharacterID_1);
				d.Text = GetNPCInformation(TempInfoCharacterID_1);
				Link.l1 = DLG_TEXT[100];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[101];
				Link.l2.go = "exit";
		break;

		case "info_2":
				trace("Айдишник персонажа - " + TempInfoCharacterID_2);
				d.Text = GetNPCInformation(TempInfoCharacterID_2);
				Link.l1 = DLG_TEXT[102];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[103];
				Link.l2.go = "exit";
		break;

		case "town":
			if(NPChar.sex == "man")
			   d.Text = RandPhrase(DLG_TEXT[104] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname + DLG_TEXT[105], DLG_TEXT[106], DLG_TEXT[107] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[108]);
			else
			   d.Text = RandPhrase(DLG_TEXT[109] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname + DLG_TEXT[110], DLG_TEXT[111], DLG_TEXT[112] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[113]);

			Link.l1 = DLG_TEXT[114];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[115];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[116];
			Link.l3.go = "town_store";
		break;

		case "town_tavern":
			d.Text = DLG_TEXT[117];
			Link.l1 = DLG_TEXT[118];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[119];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[120];
			Link.l3.go = "town_store";
		break;

		case "town_shipyard":
			d.Text = DLG_TEXT[121]
			Link.l1 = DLG_TEXT[122];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[123];
			Link.l2.go = "town_store";
			Link.l3 = DLG_TEXT[124];
			Link.l3.go = "exit";
		break;

		case "town_store":
			d.Text = DLG_TEXT[125];
			Link.l1 = DLG_TEXT[126];
			Link.l1.go = "town_shipyard";
			Link.l2 = DLG_TEXT[127];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[128];
			Link.l3.go = "exit";
		break;


		case "colony":
			d.Text = RandPhrase(DLG_TEXT[129], DLG_TEXT[130], DLG_TEXT[131] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname + DLG_TEXT[132]);
			if(Rand(1)== 0)
			{
				Link.l1 = DLG_TEXT[133];
				Link.l1.go = "Greenford";
			}
			else
			{
				Link.l1 = DLG_TEXT[134];
				Link.l1.go = "island";
			}
			if(Rand(1)== 0)
			{
				Link.l1 = DLG_TEXT[135];
				Link.l1.go = "fort";
			}
	/*		else
			{
				Link.l1 = "С кем торгуют местные торговцы?";
				Link.l1.go = "trade";
			}*/

			Link.l2 = DLG_TEXT[136];
			Link.l2.go = "new question";
		break;

		case "Greenford":
			d.Text = DLG_TEXT[137];
			Link.l1 = DLG_TEXT[138];
			Link.l1.go = "Greenford_1";
			Link.l2 = DLG_TEXT[139];
			Link.l2.go = "new question";
		break;

		case "Greenford_1":
			d.Text = DLG_TEXT[140];
			//Link.l1 = "Дальше...";
			//Link.l1.go = "Redmond_2";
			Link.l2 = DLG_TEXT[141];
			Link.l2.go = "new question";
		break;

		case "island":
			switch(Rand(2))
			{	
				case 0:
					d.Text = DLG_TEXT[142];
					Link.l1 = DLG_TEXT[143];
					Link.l1.go = "colony";
				break;

				case 1:
					d.Text = DLG_TEXT[144];
					Link.l1 = DLG_TEXT[145];
					Link.l1.go = "colony";
				break;

				case 2:
					d.Text = DLG_TEXT[146];
					Link.l1 = DLG_TEXT[147];
					Link.l1.go = "colony";
				break;
			}
			Link.l2 = DLG_TEXT[148];
			Link.l2.go = "new question";
		break;

		case "fort":
			switch(Rand(2))
			{	
				case 0:
					d.Text = DLG_TEXT[149];
					Link.l1 = DLG_TEXT[150];
					Link.l1.go = "colony";
				break;

				case 1:
					d.Text = DLG_TEXT[151]
					Link.l1 = DLG_TEXT[152];
					Link.l1.go = "colony";
				break;

				case 2:
					d.Text = DLG_TEXT[153];
					Link.l1 = DLG_TEXT[154];
					Link.l1.go = "colony";
				break;
			}
			Link.l2 = DLG_TEXT[155];
			Link.l2.go = "new question";
		break;

		case "dont_know_Blaze":
			d.Text = DLG_TEXT[156];
			Link.l1 = DLG_TEXT[157];
			Link.l1.go = "exit";
			AddDialogExitQuest("danielle_greenford_stranger_reveals_Blaze");
		break;

	} // end of switch; 

}