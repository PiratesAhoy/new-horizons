//#include "DIALOGS\Docker Generated_dialog.h"
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
				d.Text = RandPhrase(TimeGreeting() + DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1], DLG_TEXT[2] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[3], DLG_TEXT[4] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[5]);
				Link.l1 = RandPhrase(DLG_TEXT[6] + GetMyFullName(PChar) + DLG_TEXT[7] + GetMyShipNameShow(PChar) + DLG_TEXT[8], DLG_TEXT[9] + GetMyFullName(PChar) + DLG_TEXT[10], DLG_TEXT[11] + GetMyName(Pchar) + DLG_TEXT[12]);
				Link.l1.go = "meeting";
			}
			else
			{
				
				d.Text = RandPhrase(DLG_TEXT[13] + GetMyName(Pchar) + DLG_TEXT[14], TimeGreeting() + DLG_TEXT[15], DLG_TEXT[16] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[17]);
				if(Rand(1)==0)
				{
					Link.l1 = RandPhrase(DLG_TEXT[18], DLG_TEXT[19], DLG_TEXT[20]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = RandPhrase(DLG_TEXT[21], DLG_TEXT[22], DLG_TEXT[23]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = RandPhrase(DLG_TEXT[24], DLG_TEXT[25], DLG_TEXT[26]);
					Link.l2.go = "info";
				}
				Link.l3 = DLG_TEXT[27];
				Link.l3.go = "exit";
			}
		break;

		case "Meeting":
				d.Text = RandPhrase(DLG_TEXT[28], DLG_TEXT[29] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[30], DLG_TEXT[31] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[32]);
				if(Rand(1)==0)
				{
					Link.l1 = RandPhrase(DLG_TEXT[33], DLG_TEXT[34], DLG_TEXT[35]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = RandPhrase(DLG_TEXT[36], DLG_TEXT[37], DLG_TEXT[38]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = RandPhrase(DLG_TEXT[39], DLG_TEXT[40], DLG_TEXT[41]);
					Link.l2.go = "info";
				}
				Link.l3 = DLG_TEXT[42];
				Link.l3.go = "exit";
		break;

		case "rumours":
				d.Text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) );
				Link.l1 = DLG_TEXT[43];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[44];
				Link.l2.go = "exit";

		break;

		case "new question":
				d.Text = RandPhrase(DLG_TEXT[45] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[46], DLG_TEXT[47] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[48], DLG_TEXT[49] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[50]);
				if(Rand(1)==0)
				{
					Link.l1 = RandPhrase(DLG_TEXT[51], DLG_TEXT[52], DLG_TEXT[53]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = RandPhrase(DLG_TEXT[54], DLG_TEXT[55], DLG_TEXT[56]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = RandPhrase(DLG_TEXT[57], DLG_TEXT[58], DLG_TEXT[59]);
					Link.l2.go = "info";
				}
				Link.l3 = DLG_TEXT[60];
				Link.l3.go = "exit";
		break;

		case "info":
				d.Text = RandPhrase(DLG_TEXT[61] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[62], DLG_TEXT[63] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[64], DLG_TEXT[65] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[66]);
				if(Rand(1)==0)
				{	
					TempInfoCharacterID_1 = "Robert Christopher Silehard";
					Link.l1 = DLG_TEXT[67];
					Link.l1.go = "info_1";
				}
				else
				{
					TempInfoCharacterID_1 = "Charles Windem";
					Link.l1 = DLG_TEXT[68];
					Link.l1.go = "info_1";
				}
				if(Rand(1)==0)	
				{
					TempInfoCharacterID_2 = "Roger Murray";
					Link.l2 = DLG_TEXT[69];
					Link.l2.go = "info_2";
				}
				else 
				{
					TempInfoCharacterID_2 = "Thomas O'Reily";
					Link.l2 = DLG_TEXT[70];
					Link.l2.go = "info_2";
				}
				Link.l3 = DLG_TEXT[71];
				Link.l3.go = "new question";
		break;

		case "info_1":
				trace("Айдишник персонажа - " + TempInfoCharacterID_1);
				d.Text = GetNPCInformation(TempInfoCharacterID_1);
				Link.l1 = DLG_TEXT[72];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[73];
				Link.l2.go = "exit";
		break;

		case "info_2":
				trace("Айдишник персонажа - " + TempInfoCharacterID_2);
				d.Text = GetNPCInformation(TempInfoCharacterID_2);
				Link.l1 = DLG_TEXT[74];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[75];
				Link.l2.go = "exit";
		break;


		case "town":
			d.Text = RandPhrase(DLG_TEXT[76], DLG_TEXT[77] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[78], DLG_TEXT[79] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[80]);
			Link.l1 = DLG_TEXT[81];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[82];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[83];
			Link.l3.go = "town_store";
		break;

		case "town_tavern":
			d.Text = DLG_TEXT[84];
			Link.l1 = DLG_TEXT[85];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[86];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[87];
			Link.l3.go = "town_store";
		break;

		case "town_shipyard":
			d.Text = DLG_TEXT[88] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[89] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[90];
			Link.l1 = DLG_TEXT[91];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[92];
			Link.l2.go = "town_store";
			Link.l3 = DLG_TEXT[93];
			Link.l3.go = "exit";
		break;

		case "town_store":
			d.Text = DLG_TEXT[94] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[95];
			Link.l1 = DLG_TEXT[96];
			Link.l1.go = "town_shipyard";
			Link.l2 = DLG_TEXT[97];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[98];
			Link.l3.go = "exit";
		break;
	}
}