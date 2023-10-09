//#include "DIALOGS\Redmond Citizen_dialog.h"
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

			NPC_Meeting = "1"; 
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";

			d.Text = TimeGreeting() + DLG_TEXT[1] + DLG_TEXT[2];
			Link.l1 = DLG_TEXT[9] + GetMyFullName(PChar) + DLG_TEXT[13];
			Link.l1.go = "meeting";
		break;

		case "Meeting":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[35], DLG_TEXT[36] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[37], DLG_TEXT[38], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				
				Link.l1 = LinkRandPhrase(DLG_TEXT[42], DLG_TEXT[43], DLG_TEXT[44]);
				Link.l1.go = "town";
				Link.l2 = LinkRandPhrase(DLG_TEXT[45], DLG_TEXT[46], DLG_TEXT[47]);
				Link.l2.go = "info";
				Link.l3 = DLG_TEXT[51];
				Link.l3.go = "exit";

				Diag.TempNode = "Meeting";
		break;
	
		case "info":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[73] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[74], DLG_TEXT[75] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[76], DLG_TEXT[77] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[78], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				
			Link.l1 = DLG_TEXT[80];
			Link.l1.go = "restaurantkeeper";
			Link.l2 = DLG_TEXT[81];
			Link.l2.go = "hotelowner";
			Link.l3 = DLG_TEXT[82];
			Link.l3.go = "localtrader";
			if(Pchar.model == "William Legrand") 	Link.l4 = DLG_TEXT[165];	
			if(Pchar.model == "Jupiter") 		Link.l4 = DLG_TEXT[169];
			Link.l4.go = "fortcommendant";
			Link.l5 = DLG_TEXT[83];
			Link.l5.go = "exit";

			Diag.TempNode = "Meeting";	
		break;

		case "restaurantkeeper":
			d.Text = DLG_TEXT[87];
			if(Pchar.model == "William Legrand") 	Link.l2 = DLG_TEXT[168];	
			if(Pchar.model == "Jupiter") 		Link.l2 = DLG_TEXT[51];
			Link.l2.go = "exit";
		break;

		case "hotelowner":
			d.Text = DLG_TEXT[90];
			if(Pchar.model == "William Legrand") 	Link.l2 = DLG_TEXT[168];	
			if(Pchar.model == "Jupiter") 		Link.l2 = DLG_TEXT[51];
			Link.l2.go = "exit";
		break;

		case "localtrader":
			d.Text = DLG_TEXT[93];
			if(Pchar.model == "William Legrand") 	Link.l2 = DLG_TEXT[168];	
			if(Pchar.model == "Jupiter") 		Link.l2 = DLG_TEXT[51];
			Link.l2.go = "exit";
		break;

		case "fortcommendant":
			d.Text = DLG_TEXT[84];
			if(CheckAttribute(Pchar,"quest.Jupiter_bug_mission") && Pchar.quest.Jupiter_bug_mission == "on")
			{
				Link.l2 = DLG_TEXT[166];
				Link.l2.go = "fortcommendant1";
			}
			else
			{				
				if(Pchar.model == "William Legrand") 	Link.l2 = DLG_TEXT[168];	
				if(Pchar.model == "Jupiter") 		Link.l2 = DLG_TEXT[51];
				Link.l2.go = "exit";
			}
		break;

		case "fortcommendant1":
			d.Text = DLG_TEXT[167];
			Link.l1 = DLG_TEXT[95];
			Link.l1.go = "exit";
			AddQuestRecord("Jupiters_Moultrie_mission","10");
			Pchar.quest.Jupiter_lutG_hint = "yes";
		break;

		case "town":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[96], DLG_TEXT[97] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[98], DLG_TEXT[99] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[100], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[101];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[102];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[103];
			Link.l3.go = "town_store";
			Link.l4 = DLG_TEXT[161];
			Link.l4.go = "town_hotel";
			Link.l5 = DLG_TEXT[124];
			Link.l5.go = "town_fort";
		break;
	
		case "town_tavern":
			d.Text = DLG_TEXT[104];
			Link.l1 = DLG_TEXT[105];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[106];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[107];
			Link.l3.go = "town_store";
			Link.l4 = DLG_TEXT[161];
			Link.l4.go = "town_hotel";
			Link.l5 = DLG_TEXT[124];
			Link.l5.go = "town_fort";

			Diag.TempNode = "Meeting";
		break;

		case "town_shipyard":
			d.Text = DLG_TEXT[108];
			Link.l3 = DLG_TEXT[113];
			Link.l3.go = "exit";
			Link.l1 = DLG_TEXT[111];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[112];
			Link.l2.go = "town_store";
			Link.l4 = DLG_TEXT[161];
			Link.l4.go = "town_hotel";
			Link.l5 = DLG_TEXT[124];
			Link.l5.go = "town_fort";

			Diag.TempNode = "Meeting";
		break;

		case "town_store":
			d.Text = DLG_TEXT[114];
			Link.l3 = DLG_TEXT[118];
			Link.l3.go = "exit";
			Link.l1 = DLG_TEXT[116];
			Link.l1.go = "town_shipyard";
			Link.l2 = DLG_TEXT[117];
			Link.l2.go = "town_tavern";
			Link.l4 = DLG_TEXT[161];
			Link.l4.go = "town_hotel";
			Link.l5 = DLG_TEXT[124];
			Link.l5.go = "town_fort";

			Diag.TempNode = "Meeting";
		break;

		case "town_hotel":
			d.Text = DLG_TEXT[162];
			Link.l4 = DLG_TEXT[118];
			Link.l4.go = "exit";
			Link.l1 = DLG_TEXT[116];
			Link.l1.go = "town_shipyard";
			Link.l2 = DLG_TEXT[117];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[112];
			Link.l3.go = "town_store";
			Link.l5 = DLG_TEXT[124];
			Link.l5.go = "town_fort";
			
			Diag.TempNode = "Meeting";
		break;

		case "town_fort":
			d.Text = DLG_TEXT[140];
			Link.l6 = DLG_TEXT[163];
			Link.l6.go = "town_fort1";
			Link.l4 = DLG_TEXT[118];
			Link.l4.go = "exit";
			Link.l1 = DLG_TEXT[116];
			Link.l1.go = "town_shipyard";
			Link.l2 = DLG_TEXT[117];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[112];
			Link.l3.go = "town_store";
			Link.l5 = DLG_TEXT[161];
			Link.l5.go = "town_hotel";
			
			Diag.TempNode = "Meeting";
		break;

		case "town_fort1":
			d.Text = DLG_TEXT[164];
			Link.l1 = DLG_TEXT[118];
			Link.l1.go = "exit";
			
			Diag.TempNode = "Meeting";
		break;
	}
}
