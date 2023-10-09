//#include "DIALOGS\isla muelle citizen_dialog.h"
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
				d.Text = RandPhrase(TimeGreeting() + DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1], DLG_TEXT[2] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[3], DLG_TEXT[4] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[5], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = LinkRandPhrase(DLG_TEXT[6] + GetMyFullName(Pchar) + DLG_TEXT[7] + GetMyShipNameShow(PChar) + DLG_TEXT[8], DLG_TEXT[9] + GetMyFullName(Pchar) + DLG_TEXT[10], DLG_TEXT[11] + GetMyName(PChar) + DLG_TEXT[12]);
				Link.l1.go = "meeting";
			}
			else
			{
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[13] + GetMyName(PChar) + DLG_TEXT[14], DLG_TEXT[15] + GetMyName(PChar) + DLG_TEXT[16] + TimeGreeting() + DLG_TEXT[17], DLG_TEXT[18] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[19], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(pcharrepphrase(DLG_TEXT[20], DLG_TEXT[21]), pcharrepphrase(DLG_TEXT[22], DLG_TEXT[23]), pcharrepphrase(DLG_TEXT[24], DLG_TEXT[25]));
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(pcharrepphrase(DLG_TEXT[26], DLG_TEXT[27]), pcharrepphrase(DLG_TEXT[28], DLG_TEXT[29]), pcharrepphrase(DLG_TEXT[30], DLG_TEXT[31]));
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(pcharrepphrase(DLG_TEXT[32], DLG_TEXT[33]), pcharrepphrase(DLG_TEXT[34], DLG_TEXT[35]), pcharrepphrase(DLG_TEXT[36], DLG_TEXT[37]));
					Link.l2.go = "info";
				}
				/*else
				{
					Link.l2 = RandPhrase(pcharrepphrase("Расскажите мне о Фале Де Флер.", "Какие истории связаны с этим, Богом забытом местом?"), pcharrepphrase("Я хочу побольше узнать об этой колонии.", "Расскажи мне историю этого города и острова."), pcharrepphrase("Что интересного Вы знаете о Фале Де Флер?", ""));
					Link.l2.go = "colony";
				}*/
				// NK -->
				else
				{
					Link.l2 = DLG_TEXT[144];
					Link.l2.go = "colony";
				}
			}
			Link.l3 = pcharrepphrase(DLG_TEXT[38], DLG_TEXT[39]);
			Link.l3.go = "exit";
			Diag.TempNode = "First Time";
		break;

		case "Meeting":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[40] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[41], DLG_TEXT[42], DLG_TEXT[43], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[44], DLG_TEXT[45], DLG_TEXT[46]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[47], DLG_TEXT[48], DLG_TEXT[49]);
					Link.l1.go = "town";
				}
				Link.l2 = LinkRandPhrase(DLG_TEXT[50], DLG_TEXT[51], DLG_TEXT[52]);
				Link.l2.go = "info";
				Link.l3 = DLG_TEXT[53];
				Link.l3.go = "exit";
		break;

		case "rumours":
				d.Text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) );
				Link.l1 = DLG_TEXT[54];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[55];
				Link.l2.go = "exit";
		break;

		case "new question":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[56] + GetMyName(PChar) + DLG_TEXT[57], DLG_TEXT[58] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[59], DLG_TEXT[60] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[61], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[62], DLG_TEXT[63], DLG_TEXT[64]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[65], DLG_TEXT[66], DLG_TEXT[67]);
					Link.l1.go = "town";
				}
				Link.l2 = LinkRandPhrase(DLG_TEXT[68], DLG_TEXT[69], DLG_TEXT[70]);
				Link.l2.go = "info";
				Link.l3 = DLG_TEXT[71];
				Link.l3.go = "exit";
		break;

		case "info":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[72] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[73], DLG_TEXT[74], DLG_TEXT[75], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				if(Rand(1)==0)
				{	
					Link.l1 = DLG_TEXT[76];
					Link.l1.go = "governor";
				}
				else
				{
					Link.l1 = DLG_TEXT[77];
					Link.l1.go = "tavernkeeper";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = DLG_TEXT[78];
					Link.l2.go = "shipwright";
				}
				else 
				{
					Link.l2 = DLG_TEXT[79];
					Link.l2.go = "localtrader";
				}
				// RobC/Alan_Smithee Blacksmiths -->
				if (ENABLE_WEAPONSMOD)
				{
					Link.l3 = DLG_TEXT[133];
					Link.l3.go = "smithy";
				}
				// RobC/Alan_Smithee Blacksmiths <--
				Link.l4 = DLG_TEXT[80];
				Link.l4.go = "new question";
		break;

		case "smithy":				
				d.Text = DLG_TEXT[134];
				Link.l1 = DLG_TEXT[135];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[136];
				Link.l2.go = "exit";
		break;
//<-- RobC/Alan_Smithee 'smiths

		case "governor":				
				d.Text = DLG_TEXT[81];
				Link.l1 = DLG_TEXT[82];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[83];
				Link.l2.go = "exit";
		break;

		case "tavernkeeper":
				d.Text = DLG_TEXT[84];
				Link.l1 = DLG_TEXT[85];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[86];
				Link.l2.go = "exit";
		break;

		case "shipwright":
				d.Text = DLG_TEXT[87];
				Link.l1 = DLG_TEXT[88];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[89];
				Link.l2.go = "exit";
		break;

		case "localtrader":
				d.Text = DLG_TEXT[90];
				Link.l1 = DLG_TEXT[91];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[92];
				Link.l2.go = "exit";
		break;


		case "town":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[93] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[94], DLG_TEXT[95], DLG_TEXT[96] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[97], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[98];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[99];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[100];
			Link.l3.go = "town_store";
			// RobC/Alan_Smithee Blacksmiths -->
			if (ENABLE_WEAPONSMOD)
			{
				Link.l4 = DLG_TEXT[137];
				Link.l4.go = "town_smithy";
			}
			// RobC/Alan_Smithee Blacksmiths <--
		break;

		case "town_smithy":
			d.Text = DLG_TEXT[138];
			Link.l1 = DLG_TEXT[139];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[140];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[141];
			Link.l3.go = "town_store";
			DeleteAttribute(&locations[FindLocation("Muelle_town_03")], "reload.l11.goto_disable"); // BOP: Unlock Fast Travel
		break;
//<--RobC/Alan_Smithee 'smiths

		case "town_tavern":
			d.Text = DLG_TEXT[101];
			Link.l1 = DLG_TEXT[102];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[103];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[104];
			Link.l3.go = "town_store";
			if (ENABLE_WEAPONSMOD)
			{
				Link.l4 = DLG_TEXT[137];
				Link.l4.go = "town_smithy";
			}
			DeleteAttribute(&locations[FindLocation("Muelle_town_01")], "reload.l11.goto_disable"); // BOP: Unlock Fast Travel
		break;

		case "town_shipyard":
			d.Text = DLG_TEXT[105];
			Link.l1 = DLG_TEXT[106];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[107];
			Link.l2.go = "town_store";
			if (ENABLE_WEAPONSMOD)
			{
				Link.l4 = DLG_TEXT[137];
				Link.l4.go = "town_smithy";
			}
			Link.l3 = DLG_TEXT[108];
			Link.l3.go = "exit";
			DeleteAttribute(&locations[FindLocation("Muelle_town_01")], "reload.l12.goto_disable"); // BOP: Unlock Fast Travel
		break;

		case "town_store":
			d.Text = DLG_TEXT[109];
			Link.l1 = DLG_TEXT[110];
			Link.l1.go = "town_shipyard";
			Link.l2 = DLG_TEXT[111];
			Link.l2.go = "town_tavern";
			if (ENABLE_WEAPONSMOD)
			{
				Link.l4 = DLG_TEXT[137];
				Link.l4.go = "town_smithy";
			}
			Link.l3 = DLG_TEXT[112];
			Link.l3.go = "exit";
			DeleteAttribute(&locations[FindLocation("Muelle_town_01")], "reload.l9.goto_disable"); // BOP: Unlock Fast Travel
		break;

		case "colony":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[113] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[114], DLG_TEXT[115], DLG_TEXT[116] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[117], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			if(Rand(1)== 0)
			{
				Link.l1 = DLG_TEXT[118];
				Link.l1.go = "Fleur";
			}
			else
			{
				Link.l1 = DLG_TEXT[119];
				Link.l1.go = "island";
			}
			Link.l2 = DLG_TEXT[120];
			Link.l2.go = "new question";
		break;

		case "Fleur":
			d.Text = DLG_TEXT[121] + DLG_TEXT[142] + GetTownSize("Isla Muelle") + DLG_TEXT[143]; // NK
			Link.l1 = DLG_TEXT[122];
			Link.l1.go = "Fleur_1";
			Link.l2 = DLG_TEXT[123];
			Link.l2.go = "new question";
		break;

		case "Fleur_1":
			d.Text = DLG_TEXT[124];
			Link.l2 = DLG_TEXT[125];
			Link.l2.go = "new question";
		break;

		case "island":
			switch(Rand(2))
			{	
				case 0:
					d.Text = DLG_TEXT[126];
					Link.l1 = DLG_TEXT[127];
					Link.l1.go = "colony";
				break;

				case 1:
					d.Text = DLG_TEXT[128];
					Link.l1 = DLG_TEXT[129];
					Link.l1.go = "colony";
				break;

				case 2:
					d.Text = DLG_TEXT[130];
					Link.l1 = DLG_TEXT[131];
					Link.l1.go = "colony";
				break;
			}
			Link.l2 = DLG_TEXT[132];
			Link.l2.go = "new question";
		break;
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}
