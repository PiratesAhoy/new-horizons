//#include "DIALOGS\Laurence Wellman_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
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
			Dialog.snd = "dialogs\0\009";
			Diag.TempNode = "first time";

			if(NPChar.quest.meeting == "0")
			{
				NPC_meeting = "1";
				d.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
				Link.l1 = DLG_TEXT[2] + GetMyName(Pchar) + DLG_TEXT[3] + GetMyShipNameShow(PChar) + DLG_TEXT[4];
			}
			else
			{
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[5] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[6], DLG_TEXT[7] + GetMyName(Pchar) + DLG_TEXT[8], DLG_TEXT[9] + GetMyName(Pchar) + DLG_TEXT[10], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = DLG_TEXT[11];
			}
			Link.l1.go = "node_2";
		break;

		case "node_2":
			d.Text = DLG_TEXT[12] + GetMyName(Pchar) + DLG_TEXT[13];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "node_3";
			Link.l2 = DLG_TEXT[15];
			Link.l2.go = "node_work";
			if(characters[GetCharacterIndex("Rys Bloom")].quest.help == "agreed")
			{
				Link.l3 = DLG_TEXT[16];
				Link.l3.go = "Node_Rys";
			}
			if(CheckQuestAttribute("ardent_hunt_status", "searching"))
			{
				Preprocessor_Add("villain", GetMyFullName(characterFromID(PChar.quest.villain)));
				Link.l4 = DLG_TEXT[62];
				Link.l4.go = "ardent_hunt_which_ship";
			}
		break;

		case "node_3":
			d.Text = DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "node_4";
			Link.l2 = DLG_TEXT[19];
			Link.l2.go = "node_work";
			Link.l3 = DLG_TEXT[20];
			Link.l3.go = "exit";
		break;

		case "node_4":
			d.Text = DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[23];
			Link.l2.go = "node_work";
			
		break;

		case "node_work":
			Preprocessor_Add("gov_lastname", characters[GetCharacterIndex(towns[GetTownIndex("Redmond")].gov)].lastname);
			if(NPChar.quest.meeting == "0")
			{
				d.Text = DLG_TEXT[24] + GetMyName(Pchar) + DLG_TEXT[25];
			}
			else
			{
				d.Text = DLG_TEXT[26] + GetMyName(Pchar) + DLG_TEXT[27];
			}
			Link.l1 = DLG_TEXT[28];
			Link.l1.go = "node_3";
			Link.l2 = DLG_TEXT[29];
			Link.l2.go = "node_work_1";
			if(characters[GetCharacterIndex("Rys Bloom")].quest.help == "agreed")
			{
				Link.l3 = DLG_TEXT[30];
				Link.l3.go = "Node_Rys";
			}
		break;

		case "node_work_1":
			d.Text = DLG_TEXT[31];
			Link.l1 = DLG_TEXT[32];
			Link.l1.go = "node_3";
			if(characters[GetCharacterIndex("Rys Bloom")].quest.help == "agreed")
			{
				Link.l2 = DLG_TEXT[33];
				Link.l2.go = "Node_Rys";
			}
			Link.l3 = DLG_TEXT[34];
			Link.l3.go = "exit";
		break;

		case "node_Rys":
			d.Text = DLG_TEXT[35];
			Link.l1 = DLG_TEXT[36];
			Link.l1.go = "node_Rys Bloom_2";
			Link.l2 = DLG_TEXT[37];
			Link.l2.go = "node_Rys Bloom_3";
			Link.l3 = DLG_TEXT[38];
			Link.l3.go = "node_2";
		break;

		case "node_Rys Bloom_2":
			d.Text = DLG_TEXT[39];
			Link.l1 = DLG_TEXT[40];
			Link.l1.go = "node_Rys Bloom_3";
			Link.l2 = DLG_TEXT[41];
			Link.l2.go = "node_2";
		break;

		case "node_Rys Bloom_3":
			d.Text = DLG_TEXT[42];
			Link.l1 = DLG_TEXT[43];
			Link.l1.go = "node_Rys Bloom_4";
			Link.l2 = DLG_TEXT[44];
			Link.l2.go = "exit";
		break;

		case "node_Rys Bloom_4":
			if (PChar.sex == "man") Preprocessor_Add("person", XI_ConvertString("man"));
			else Preprocessor_Add("person", XI_ConvertString("woman"));
			d.Text = DLG_TEXT[45] + GetMyName(Pchar) + DLG_TEXT[46];
			Link.l1 = DLG_TEXT[47];
			if(makeint(PChar.reputation)>=6)
			{
				Link.l1.go = "node_Rys Bloom_5";
			}
			else
			{
				Link.l1.go = "node_Rys Bloom_6";
			}

			Link.l2 = DLG_TEXT[48];
			Link.l2.go = "node_2";
		break;

		case "node_Rys Bloom_5":
			Characters[GetCharacterIndex("Rys Bloom")].quest.help = "done";
			characters[GetCharacterIndex("Rys Bloom")].dialog.currentnode = "Help_succesful";
			d.Text = DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[51];
			Link.l2.go = "node_2";
		break;

		case "node_Rys Bloom_6":
			Characters[GetCharacterIndex("Rys Bloom")].quest.help = "failed";
			Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
			d.Text = DLG_TEXT[52] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[53];
			Link.l1 = DLG_TEXT[54];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[55];
			Link.l2.go = "node_2";
		break;

		case "Mooring_Boat":
			locCameraRight(NPChar); // a simple virtual sailor
			d.text = DLG_TEXT[56];
			Link.l1 = DLG_TEXT[57];
			Link.l1.go = "Mooring_discussion";
		break;

		case "Mooring_discussion":
			d.Text = DLG_TEXT[58];
			Link.l1 = DLG_TEXT[59];
			link.l1.go = "Mooring_discussion2";
		break;

		case "Mooring_discussion2":
			d.Text = DLG_TEXT[60];
			Link.l1 = DLG_TEXT[61];
			link.l1.go = "exitmoor";
		break;

		case "ardent_hunt_which_ship":
			Preprocessor_Add("villain", GetMyFullName(characterFromID(PChar.quest.villain)));
			if (Characters[GetCharacterIndex(PChar.quest.villain)].sex == "man") Preprocessor_Add("pronoun", XI_ConvertString("his"));
			else Preprocessor_Add("pronoun", XI_ConvertString("her"));
			d.text = DLG_TEXT[63] + GetMyName(PChar) + DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "ardent_hunt_which_ship2");
		break;

		case "ardent_hunt_which_ship2":
			d.text = DLG_TEXT[66] + GetMyLastName(characterFromID(PChar.quest.villain)) + DLG_TEXT[67];
			link.l1 = "...";
			AddDialogExitQuest("hunt_laurence_goes_to_window");
			link.l1.go = "exit";
		break;

		case "ardent_hunt_which_ship3":
			Preprocessor_AddQuestData("villain", GetMyFullName(characterFromID(PChar.quest.villain)));
			Preprocessor_AddQuestData("ship", Characters[GetCharacterIndex(PChar.quest.villain)].Ship.Name);
			AddQuestRecord("Villain_Hunt", 3);
			Preprocessor_Remove("ship");
			Preprocessor_Remove("villain");
			PChar.quest.ardent_hunt_status = "ship_known";
			Preprocessor_Add("ship", Characters[GetCharacterIndex(PChar.quest.villain)].Ship.Name);
			d.Text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "exit";
		break;

		case "exitmoor":
			AddDialogExitQuest("And_the_Film_Continues");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_meeting;
			DialogExit();
		break;
		
	}
}
