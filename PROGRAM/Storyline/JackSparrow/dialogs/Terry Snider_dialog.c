//#include "DIALOGS\Terry Snider_dialog.h"
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
			dialog.text = randphrase(DLG_TEXT[11], DLG_TEXT[12], DLG_TEXT[13], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			if(!Rand(3)) dialog.text = DLG_TEXT[14] + GetTownSize("Quebradas Costillas") + DLG_TEXT[15]; // NK
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
// RobC/Alan_Smithee Blacksmiths (plus A_S' whim, expanding the dialog mightily) (and edited to suit character by Cat) -->
			link.l2 = DLG_TEXT[17];
			link.l2.go = "new question";
//<--ditto
			if (pchar.quest.main_line == "blaze_talk_with_silehard_complete" && characters[GetCharacterIndex("Ines Diaz")].quest.rheims != "speak_with_humans")
			{
				Dialog.snd = "voice\QCSI\QCSI001";
				dialog.text = DLG_TEXT[18];
				link.l1 = DLG_TEXT[19] + characters[GetCharacterIndex("Raoul Rheims")].name + " " + characters[GetCharacterIndex("Raoul Rheims")].lastname + DLG_TEXT[20];
				link.l1.go = "search_rheims";
				AddQuestRecord("Blaze_search_Rheims", 12);
				characters[GetCharacterIndex("Ines Diaz")].quest.rheims = "speak_with_humans";
			}
			NextDiag.TempNode = "first time";
		break;
		
		case "search_rheims":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "exit";
		break;
// RobC/Alan_Smithee Blacksmiths (&tc) -->
		case "new question":
					dialog.snd1 = "";
					dialog.snd2 = "";
					dialog.snd3 = "";
					dialog.Text = RandPhrase(DLG_TEXT[23], DLG_TEXT[24], DLG_TEXT[25], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
					if (CheckQuestAttribute("ANIMISTST","go_to_beach"))  //  -->  Added by Cat to fix confusion in Animists quest  
					{
						link.l1 = DLG_TEXT[26];
						link.l1.go = "mefisto1";
					}  //  <--  Cat					
					else
					{
						Link.l1 = LinkRandPhrase(DLG_TEXT[27], DLG_TEXT[28], DLG_TEXT[29]);
						Link.l1.go = "town";
						Link.l2 = DLG_TEXT[30];
						Link.l2.go = "colony";
						Link.l3 = LinkRandPhrase(DLG_TEXT[31], DLG_TEXT[32], DLG_TEXT[33]);
						Link.l3.go = "info";
						Link.l4 = DLG_TEXT[34];
						Link.l4.go = "exit";
					}
		break;
		case "info":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				dialog.Text = RandPhrase(DLG_TEXT[35], DLG_TEXT[36], DLG_TEXT[37], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				
				if(Rand(1)==0)
				{	
					Link.l1 = DLG_TEXT[38];
					Link.l1.go = "governor";
				}
				else
				{
					Link.l1 = DLG_TEXT[39];
					Link.l1.go = "tavernkeeper";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = DLG_TEXT[40];
					Link.l2.go = "shipwright";
				}
				else 
				{
					Link.l2 = DLG_TEXT[41];
					Link.l2.go = "localtrader";
				}
				if(Rand(1)==0)	
				{
					Link.l3 = DLG_TEXT[42];
					Link.l3.go = "smithy";
				}
				else 
				{
					Link.l3 = DLG_TEXT[43];
					Link.l3.go = "brothel";
				}
				Link.l4 = DLG_TEXT[44];
				Link.l4.go = "new question";
		break;

		case "smithy":				
				dialog.Text = DLG_TEXT[45];
				Link.l1 = DLG_TEXT[46];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[47];
				Link.l2.go = "exit";
		break;

		case "governor":				
				dialog.Text = DLG_TEXT[48];
				Link.l1 = DLG_TEXT[49];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[50];
				Link.l2.go = "exit";
		break;

		case "tavernkeeper":
				dialog.Text = DLG_TEXT[51];
				Link.l1 = DLG_TEXT[52];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[50];
				Link.l2.go = "exit";
		break;

		case "shipwright":
				dialog.Text = DLG_TEXT[121];
				Link.l1 = DLG_TEXT[122];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[50];
				Link.l2.go = "exit";
		break;

		case "localtrader":
				dialog.Text = DLG_TEXT[53];
				Link.l1 = DLG_TEXT[54];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[55];
				Link.l2.go = "exit";
		break;

		case "brothel":
				dialog.Text = DLG_TEXT[56];
				Link.l1 = DLG_TEXT[57];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[50];
				Link.l2.go = "exit";
		break;


		case "town":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			dialog.Text = RandPhrase(DLG_TEXT[58], DLG_TEXT[59], DLG_TEXT[60], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[61];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[62];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[63];
			Link.l3.go = "town_store";
			Link.l4 = DLG_TEXT[64];
			Link.l4.go = "town_smithy";
			Link.l5 = DLG_TEXT[65];
			Link.l5.go = "town_whores";
		break;

		case "town_smithy":
			dialog.Text = DLG_TEXT[66];
			Link.l1 = DLG_TEXT[67];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[68];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[69];
			Link.l3.go = "town_store";
		break;

		case "town_tavern":
			dialog.text = DLG_TEXT[70];
			Link.l1 = DLG_TEXT[71];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[72];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[73];
			Link.l3.go = "town_store";
			Link.l4 = DLG_TEXT[74];
			Link.l4.go = "town_smithy";
		break;

		case "town_shipyard":
			dialog.text = DLG_TEXT[75];
			Link.l1 = DLG_TEXT[76];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[77];
			Link.l2.go = "town_store";
			Link.l3 = DLG_TEXT[78];
			Link.l3.go = "exit";
			Link.l4 = DLG_TEXT[79];
			Link.l4.go = "town_smithy";
		break;

		case "town_store":
			dialog.text = DLG_TEXT[80];
			Link.l1 = DLG_TEXT[81];
			Link.l1.go = "town_shipyard";
			Link.l2 = DLG_TEXT[82];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[83];
			Link.l3.go = "exit";
			Link.l4 = DLG_TEXT[84];
			Link.l4.go = "town_smithy";
		break;

		case "town_whores":
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "whores2";
		break;

		case "whores2":
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "whores3";
		break;

		case "whores3":
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "whores4";
		break;

		case "whores4":
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "exit";
		break;

case "colony":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			dialog.text = RandPhrase(DLG_TEXT[93], DLG_TEXT[94], DLG_TEXT[95] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + ".", &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			if(Rand(1)== 0)
			{
				Link.l1 = DLG_TEXT[96];
				Link.l1.go = "QC";
			}
			else
			{
				Link.l1 = DLG_TEXT[97];
				Link.l1.go = "island";
			}
			Link.l2 = DLG_TEXT[98];
			Link.l2.go = "new question";
		break;

		case "QC":
			dialog.text = DLG_TEXT[99];
			Link.l1 = DLG_TEXT[100];
			Link.l1.go = "Fleur_1";
			Link.l2 = DLG_TEXT[101];
			Link.l2.go = "new question";
		break;

		case "Fleur_1":
			dialog.text = DLG_TEXT[102];
			Link.l2 = DLG_TEXT[103];
			Link.l2.go = "new question";
		break;

		case "island":
			switch(Rand(2))
			{	
				case 0:
					dialog.text = DLG_TEXT[104];
					Link.l1 = DLG_TEXT[105];
					Link.l1.go = "colony";
				break;

				case 1:
					dialog.text = DLG_TEXT[106];
					Link.l1 = DLG_TEXT[107];
					Link.l1.go = "colony";
				break;

				case 2:
					dialog.text = DLG_TEXT[108];
					Link.l1 = DLG_TEXT[109];
					Link.l1.go = "colony";
				break;
			}
			Link.l2 = DLG_TEXT[110];
			Link.l2.go = "new question";
		break;
//<-- bada-bing

		case "mefisto1":  // -->  Dialog added by CatalinaThePirate for Animists quest
			dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[112];
			link.l1.go = "mefisto2";
		break;
		
		case "mefisto2":
			dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[114];
			link.l1.go = "mefisto3";
		break;
		
		case "mefisto3":
			dialog.text = DLG_TEXT[115];
			link.l1 = DLG_TEXT[116];
			link.l1.go = "mefisto4";
		break;
		
		case "mefisto4":
			dialog.text = DLG_TEXT[117];
			link.l1 = DLG_TEXT[118];
			link.l1.go = "mefisto5";
		break;
		
		case "mefisto5":
			dialog.text = DLG_TEXT[119];
			link.l1 = DLG_TEXT[120];
			link.l1.go = "exit";
			pchar.quest.ANIMISTST = "kilt_me_bruthah";
			if (GetAttribute(pchar, "Church") != "1")
			{
				AddQuestRecord("Sao Feng", 39);
			}
			else
			{
				AddQuestRecord("Sao Feng", 42);
			}
		break;  //  <-- selah, haha!

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
