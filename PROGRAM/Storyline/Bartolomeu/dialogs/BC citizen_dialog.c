//#include "DIALOGS\BC citizen_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	
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
			Dialog.snd = "voice\QCSI\QCSI001";
			
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			dialog.text = randphrase(DLG_TEXT[0], DLG_TEXT[1], DLG_TEXT[2], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			if(!Rand(3)) dialog.text = DLG_TEXT[11] + GetTownSize("Quebradas Costillas") + DLG_TEXT[12]; // NK
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
// RobC/Alan_Smithee Blacksmiths (plus A_S' whim, expanding the dialog mightily -->
			link.l2 = DLG_TEXT[13];
			link.l2.go = "new question";
//<--ditto
			if (pchar.quest.main_line == "blaze_talk_with_silehard_complete" && characters[GetCharacterIndex("Ines Diaz")].quest.rheims != "speak_with_humans")
			{
				Dialog.snd = "voice\QCSI\QCSI001";
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5] + characters[GetCharacterIndex(DLG_TEXT[6])].name + " " + characters[GetCharacterIndex(DLG_TEXT[7])].lastname + DLG_TEXT[8];
				link.l1.go = "search_rheims";
				AddQuestRecord("Blaze_search_Rheims", "12");
				characters[GetCharacterIndex("Ines Diaz")].quest.rheims = "speak_with_humans";
			}
			NextDiag.TempNode = "first time";
		break;

		case "search_rheims":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
		break;
		
// RobC/Alan_Smithee Blacksmiths (&tc) -->
		case "new question":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			dialog.Text = RandPhrase(DLG_TEXT[14], DLG_TEXT[15], DLG_TEXT[16], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = LinkRandPhrase(DLG_TEXT[17], DLG_TEXT[18], DLG_TEXT[19]);
				Link.l1.go = "town";
				Link.l2 = DLG_TEXT[20];
				Link.l2.go = "colony";
				Link.l3 = LinkRandPhrase(DLG_TEXT[21], DLG_TEXT[22], DLG_TEXT[23]);
				Link.l3.go = "info";
				Link.l4 = DLG_TEXT[24];
				Link.l4.go = "exit";
		break;

		case "info":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				dialog.Text = RandPhrase(DLG_TEXT[25], DLG_TEXT[26], DLG_TEXT[27], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				if(Rand(1)==0)
				{	
					Link.l1 = DLG_TEXT[28];
					Link.l1.go = "governor";
				}
				else
				{
					Link.l1 = DLG_TEXT[29];
					Link.l1.go = "tavernkeeper";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = DLG_TEXT[30];
					Link.l2.go = "shipwright";
				}
				else 
				{
					Link.l2 = DLG_TEXT[31];
					Link.l2.go = "localtrader";
				}
				if(Rand(1)==0 || !IsBrothelEnabled())	// KK
				{
					Link.l3 = DLG_TEXT[32];
					Link.l3.go = "smithy";
				}
				else 
				{
					Link.l3 = DLG_TEXT[33];
					Link.l3.go = "brothel";
				}
				Link.l4 = DLG_TEXT[34];
				Link.l4.go = "new question";
		break;

		case "smithy":				
				dialog.Text = DLG_TEXT[35];
				Link.l1 = DLG_TEXT[36];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[37];
				Link.l2.go = "exit";
		break;

		case "governor":				
				dialog.Text = DLG_TEXT[38];
				Link.l1 = DLG_TEXT[39];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[40];
				Link.l2.go = "exit";
		break;

		case "tavernkeeper":
				dialog.Text = DLG_TEXT[41];
				Link.l1 = DLG_TEXT[42];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[40];
				Link.l2.go = "exit";
		break;

		case "shipwright":
				dialog.Text = DLG_TEXT[43];
				Link.l1 = DLG_TEXT[44];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[40];
				Link.l2.go = "exit";
		break;

		case "localtrader":
				dialog.Text = DLG_TEXT[45];
				Link.l1 = DLG_TEXT[46];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[47];
				Link.l2.go = "exit";
		break;

		case "brothel":
				dialog.Text = DLG_TEXT[48];
				Link.l1 = DLG_TEXT[49];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[40];
				Link.l2.go = "exit";
		break;


		case "town":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			dialog.Text = RandPhrase(DLG_TEXT[50], DLG_TEXT[51], DLG_TEXT[52], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[53];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[54];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[55];
			Link.l3.go = "town_store";
			Link.l4 = DLG_TEXT[56];
			Link.l4.go = "town_smithy";
			Link.l5 = DLG_TEXT[57];
			Link.l5.go = "town_whores";
		break;

		case "town_smithy":
			dialog.Text = DLG_TEXT[58];
			Link.l1 = DLG_TEXT[59];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[60];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[61];
			Link.l3.go = "town_store";
		break;

		case "town_tavern":
			dialog.text = DLG_TEXT[62];
			Link.l1 = DLG_TEXT[63];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[64];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[65];
			Link.l3.go = "town_store";
			Link.l4 = DLG_TEXT[66];
			Link.l4.go = "town_smithy";
		break;

		case "town_shipyard":
			dialog.text = DLG_TEXT[67];
			Link.l1 = DLG_TEXT[68];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[69];
			Link.l2.go = "town_store";
			Link.l3 = DLG_TEXT[70];
			Link.l3.go = "exit";
			Link.l4 = DLG_TEXT[71];
			Link.l4.go = "town_smithy";
		break;

		case "town_store":
			dialog.text = DLG_TEXT[72];
			Link.l1 = DLG_TEXT[73];
			Link.l1.go = "town_shipyard";
			Link.l2 = DLG_TEXT[74];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[75];
			Link.l3.go = "exit";
			Link.l4 = DLG_TEXT[76];
			Link.l4.go = "town_smithy";
		break;

		case "town_whores":
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "whores2";
		break;

		case "whores2":
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "whores3";
		break;

		case "whores3":
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];

			link.l1.go = "whores4";
		break;

		case "whores4":
			dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "exit";
		break;

		case "colony":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			dialog.text = RandPhrase(DLG_TEXT[85], DLG_TEXT[86], DLG_TEXT[87] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[103], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			if(Rand(1)== 0)
			{
				Link.l1 = DLG_TEXT[88];
				Link.l1.go = "QC";
			}
			else
			{
				Link.l1 = DLG_TEXT[89];
				Link.l1.go = "island";
			}
			Link.l2 = DLG_TEXT[90];
			Link.l2.go = "new question";
		break;

		case "QC":
			dialog.text = DLG_TEXT[91] + GetTownSize("Quebradas Costillas") + DLG_TEXT[104]; // 05-03-21 NK added town size.
			Link.l1 = DLG_TEXT[92];
			Link.l1.go = "Fleur_1";
			Link.l2 = DLG_TEXT[93];
			Link.l2.go = "new question";
		break;

		case "Fleur_1":
			dialog.text = DLG_TEXT[94];
			Link.l2 = DLG_TEXT[95];
			Link.l2.go = "new question";
		break;

		case "island":
			switch(Rand(2))
			{	
				case 0:
					dialog.text = DLG_TEXT[96];
					Link.l1 = DLG_TEXT[97];
					Link.l1.go = "colony";
				break;

				case 1:
					dialog.text = DLG_TEXT[98];
					Link.l1 = DLG_TEXT[99];
					Link.l1.go = "colony";
				break;

				case 2:
					dialog.text = DLG_TEXT[100];
					Link.l1 = DLG_TEXT[101];
					Link.l1.go = "colony";
				break;
			}
			Link.l2 = DLG_TEXT[102];
			Link.l2.go = "new question";
		break;
//<-- bada-bing

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
