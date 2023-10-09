//#include "DIALOGS\orable caron_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;

	DeleteAttribute(&Dialog,"Links");

	aref Link, NextDiag;
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	int iTest;
	itest = 0;

	ref PChar;
	PChar = GetMainCharacter();

	switch(Dialog.CurrentNode)
	{

		// -----------------------------------ƒиалог первый - перва€ встреча
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

			if (Characters[GetCharacterIndex("Milon Blacque")].quest.first_talk == "1")
			{
				Dialog.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[2])]) + DLG_TEXT[3];
				Link.l1 = DLG_TEXT[4];
				Link.l1.go = "exit";
				Link.l2 = DLG_TEXT[5];
				Link.l2.go = "MilonTalk_1";
			}
			else
			{
				Dialog.Text = DLG_TEXT[6] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[7];
				Link.l1 = DLG_TEXT[8] + GetMyShipNameShow(PChar) + DLG_TEXT[9];
				Link.l1.go = "node_2";
				NextDiag.TempNode = "Second Time";
			}
		break;

		case "node_2":
			Dialog.Text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "node_3";
		break;

		case "node_3":
			Dialog.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "node_4";
		break;

		case "node_4":
			Dialog.Text = DLG_TEXT[14] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[15] + GetMyFullName(NPChar) + DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17] + GetMyFullName(PChar) + DLG_TEXT[18] + GetMyShipNameShow(PChar) + DLG_TEXT[19];
			Link.l1.go = "node_5";
		break;

		case "node_5":
			Dialog.Text = DLG_TEXT[20] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "node_6";
		break;

		case "node_6":
			Dialog.Text = DLG_TEXT[23];
			Link.l1 = DLG_TEXT[24];
			Link.l1.go = "node_7";
			if (makeint(PChar.money) > 1)
			{
				Link.l2 = DLG_TEXT[25];
				Link.l2.go = "node_9";
			}
		break;

		case "node_7":
			Dialog.Text = DLG_TEXT[26] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[27];
			Link.l1 = DLG_TEXT[28];
			Link.l1.go = "Exit";
			if (makeint(PChar.money) > 1)
			{
				Link.l2 = DLG_TEXT[29];
				Link.l2.go = "node_9";
			}
		break;

		case "node_9":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -1);
			Dialog.Text = DLG_TEXT[30] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[31];
			Link.l1 = DLG_TEXT[32];
			if (Characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers == "0")
			{
				Link.l1.go = "node_10";
			}
			else 
			{
				if (Characters[GetCharacterIndex("Thierry Bosquet")].quest.gambling == "0")
				{
					Link.l1.go = "node_12";
				}
				else
				{
					Link.l1.go = "node_14"; // PB: For Fred Bob
				}
			}
		break;

		case "node_10":
			Dialog.Text = DLG_TEXT[33] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[34])]) + DLG_TEXT[36];
			Characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers = "1";
			Link.l1 = DLG_TEXT[37];
			Link.l1.go = "node_11";
			Link.l2 = DLG_TEXT[38];
			Link.l2.go = "port watcher";
		break;

		case "node_11":
			Dialog.Text = DLG_TEXT[39];
			Link.l1 = DLG_TEXT[40];
			Link.l1.go = "node_12";
			Link.l2 = DLG_TEXT[41] + GetMyName(NPChar) + DLG_TEXT[42];
			Link.l2.go = "exit";
		break;

		case "node_12":
			Dialog.Text = DLG_TEXT[43];
			Link.l1 = DLG_TEXT[44];
			Link.l1.go = "node_14"; // <--added by CatalinaThePirate for Fred Bob quest
			Link.l2 = DLG_TEXT[45];
			Link.l2.go = "node_13";
		break;

		case "node_13":
			Dialog.Text = DLG_TEXT[46];
			Link.l1 = DLG_TEXT[47];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[48];
			Link.l2.go = "Rumours";
		break;

		case "port watcher":
			Dialog.Text = DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[51];
			Link.l2.go = "node_12";
		break;

		// -----------------------------------ƒиалог если игрок поговорил с Milon Blacque
		case "MilonTalk_1":
			Dialog.Text = DLG_TEXT[52] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[53] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[54])]) + DLG_TEXT[55];
			Link.l1 = DLG_TEXT[56];
			Link.l1.go = "MilonTalk_11";
		break;

		case "MilonTalk_11":
			Dialog.Text = DLG_TEXT[57];
			Link.l1 = DLG_TEXT[58];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[59];
			Link.l2.go = "MilonTalk_2";
		break;

		case "MilonTalk_2":
			Dialog.Text = DLG_TEXT[60];
			Link.l1 = DLG_TEXT[61];
			Link.l1.go = "MilonTalk_3";
		break;

		case "MilonTalk_3":
			Characters[GetCharacterIndex("Milon Blacque")].quest.first_talk = "done";
			Preprocessor_AddQuestData("Milon Blacque", GetMyFullName(CharacterFromID("Milon Blacque")));
			Preprocessor_AddQuestData("Orable Caron", GetMyFullName(NPChar));
			Preprocessor_AddQuestData("Milon", GetMyName(CharacterFromID("Milon Blacque")));
			Preprocessor_AddQuestData("Rachel", GetMyName(CharacterFromID("Rachel Blacque")));
			AddQuestRecord("Blacques", "3"); // NK
			Preprocessor_Remove("Rachel");
			Preprocessor_Remove("Milon");
			Preprocessor_Remove("Orable Caron");
			Preprocessor_Remove("Milon Blacque");
			Dialog.Text = DLG_TEXT[62] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[63])]) + DLG_TEXT[64];
			Link.l1 = DLG_TEXT[65];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[66];
			Link.l2.go = "node_6";
		break;

		// -----------------------------------ƒиалог при последующих встречах
		case "Second Time":
			if (Characters[GetCharacterIndex("Milon Blacque")].quest.first_talk == "1")
			{
				Dialog.Text = DLG_TEXT[67] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[68] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[69])]) + DLG_TEXT[70];
				Link.l1 = DLG_TEXT[71];
				Link.l1.go = "exit";
				Link.l2 = DLG_TEXT[72];
				Link.l2.go = "MilonTalk_1";
			}
			else
			{
				Dialog.Text = DLG_TEXT[73] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[74];
				Link.l1 = DLG_TEXT[75];
				if (Characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers == "0")
				{
					Link.l1.go = "node_10";
				}
				else 
				{
					if (Characters[GetCharacterIndex("Thierry Bosquet")].quest.gambling == "0")
					{
						Link.l1.go = "node_12";
					}
					else
					{
						Link.l1.go = "node_14"; // PB: For Fred Bob
					}
				}
				iTest = iTest + 1;
				if ( Characters[GetCharacterIndex("rachel Blacque")].quest.badguy == "1" && iTest < QUEST_COUNTER )
				{
					Link.l2 = DLG_TEXT[76] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[77])]) + DLG_TEXT[78];
					Link.l2.go = "Rachel";
					iTest = iTest + 1;
				}
				if ( characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers == "teodoro" && iTest < QUEST_COUNTER )
				{
					dialog.text = DLG_TEXT[79] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[80];
					link.l3 = pcharrepphrase(DLG_TEXT[81], DLG_TEXT[82]);
					link.l3.go = "smugglers";
					iTest = iTest + 1;
				}
				Link.l99 = DLG_TEXT[83];
				Link.l99.go = "exit";
			}
		break;

		case "smugglers":
			Locations[FindLocation("house_of_smuggler_in_FiF")].vcskip = true; // NK
			dialog.text = DLG_TEXT[84] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[85];
			link.l1 = pcharrepphrase(DLG_TEXT[86], DLG_TEXT[87]);
			link.l1.go = "smugglers_1";
		break;

		case "smugglers_1":
			dialog.text = DLG_TEXT[88];
			link.l1 = pcharrepphrase(DLG_TEXT[89], DLG_TEXT[90]);
			link.l1.go = "smugglers_2";
		break;

		case "smugglers_2":
			dialog.text = DLG_TEXT[91];
			link.l1 = pcharrepphrase(DLG_TEXT[92], DLG_TEXT[93]);
			link.l1.go = "smugglers_3";
		break;

		case "smugglers_3":
			dialog.text = DLG_TEXT[94];
			link.l1 = pcharrepphrase(DLG_TEXT[95], DLG_TEXT[96]);
			link.l1.go = "exit";
			///////////////////////////////////////////////
			//активизируем ветку, когда на игрока нападают!
			characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers = "orable";
			///////////////////////////////////////////////
			link.l2 = pcharrepphrase(DLG_TEXT[97], DLG_TEXT[98]);
			link.l2.go = pcharrepphrase("smugglers_good", "smugglers_bad");
		break;

		case "smugglers_good":
			dialog.text = DLG_TEXT[99] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[100];
			if (makeint(pchar.money)>=500)
			{
				link.l1 = DLG_TEXT[101];
				link.l1.go = "smugglers_good_1";
			}
			link.l2 = DLG_TEXT[102];
			link.l2.go = "smugglers_good_denied";
		break;

		case "smugglers_good_denied":
			dialog.text = DLG_TEXT[103] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];
			link.l1.go = "smugglers_bad"; // NK thanks to Taghmon
			characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers = "orable";
		break;

		case "smugglers_good_1":
			dialog.text = DLG_TEXT[106] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[107])]) + DLG_TEXT[109];
			link.l1 = DLG_TEXT[110];
			link.l1.go = "exit";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -500);
			characters[GetCharacterIndex("Turpin Cabanel")].quest.smugglers = "orable_truth";
		break;

		case "smugglers_bad":
			dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[112];
			link.l1.go = "smugglers_bad_1";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 500); // NK thanks to Taghmon
		break;

		case "smugglers_bad_1":
			dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[114];
			link.l1.go = "smugglers_bad_2";
		break;

		case "smugglers_bad_2":
			dialog.text = DLG_TEXT[115];
			link.l1 = DLG_TEXT[116];
			ChangeCharacterReputation(pchar, -1); // NK thanks to Taghmon
			link.l1.go = "smugglers_good_1";
		break;

		case "Rumours":
			Dialog.Text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) );
			Link.l1 = DLG_TEXT[117];
			Link.l1.go = "exit";
		break;

		case "Rachel":
			Dialog.Text = DLG_TEXT[118] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[119];
			Link.l1 = DLG_TEXT[120];
			Link.l1.go = "Rachel_good";
			Link.l2 = DLG_TEXT[121];
			Link.l2.go = "Rachel_bad";
		break;

		case "Rachel_good":
			Dialog.Text = DLG_TEXT[122];
			Link.l1 = DLG_TEXT[123];
			Link.l1.go = "exit";
			Characters[GetCharacterIndex("Rachel Blacque")].quest.badguy = "done";
			Preprocessor_AddQuestData("Rachel", GetMyName(CharacterFromID("Rachel Blacque")));
			Preprocessor_AddQuestData("Caron", GetMyLastName(NPChar));
			AddQuestRecord("Blacques", 7); // NK
			Preprocessor_Remove("Caron");
			Preprocessor_Remove("Rachel");
		break;

		case "Rachel_bad":
			Dialog.Text = DLG_TEXT[124] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[125];
			Link.l1 = DLG_TEXT[126];
			Link.l1.go  = "Rachel_good";
			Link.l2 = DLG_TEXT[127];
			Link.l2.go = "Rachel_bad_2";
		break;

		case "Rachel_bad_2":
			Dialog.Text = DLG_TEXT[128];
			Link.l1 = DLG_TEXT[129] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[130])]) + DLG_TEXT[131];
			Link.l1.go = "Rachel_bad_3";
		break;

		case "Rachel_bad_3":
			Dialog.Text = DLG_TEXT[132] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[133];
			Link.l1 = DLG_TEXT[134];
			Link.l1.go = "exit";
			ChangeCharacterReputation(pchar, -5); // NK thanks to Taghmon
			Characters[GetCharacterIndex("Rachel Blacque")].quest.badguy = "dead"; //NK make her dead when she should be, so you can do appropriate dialog with Marc.
			NextDiag.TempNode = "MilonTalk";
			characters[GetCharacterIndex("Rachel Blacque")].location = "none";
			Preprocessor_AddQuestData("Rachel", GetMyName(CharacterFromID("Rachel Blacque")));
			Preprocessor_AddQuestData("Orable", GetMyName(NPChar));
			AddQuestRecord("Blacques", 21); // NK
			Preprocessor_Remove("Orable");
			Preprocessor_Remove("Rachel");
			npchar.location = "none";
			Rumour[3].state = "active";
		break;
		
		//  --> Fred Bob inclusion dialog added by CatalinaThePirate
		case "node_14":
			Dialog.Text = DLG_TEXT[135];
			Link.l1 = DLG_TEXT[136];
			Link.l1.go = "node_15";
			Link.l2 = DLG_TEXT[137] + GetMyName(NPChar) + DLG_TEXT[138];
			Link.l2.go = "node_21";
		break;
		
		case "node_15":
			if (characters[GetCharacterIndex("Fred Bob")].quest.help == "fired")
			{
				Dialog.Text = DLG_TEXT[167] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[168];
				Link.l1 = DLG_TEXT[169];
				Link.l1.go = "rehire_fb";
			}
			else
			{
				if (characters[GetCharacterIndex("Fred Bob")].quest.help == "hired")
				{
					Dialog.Text = DLG_TEXT[139];
					Link.l1 = RandSwear() + DLG_TEXT[140];
					Link.l1.go = "node_21";
					Link.l2 = DLG_TEXT[48];
					Link.l2.go = "Rumours";
				}
				else
				{
					if (Characters[GetCharacterIndex("Fred Bob")].quest.dialog == "0") // PB: Only get told once
					{
						Dialog.Text = DLG_TEXT[141];
						Link.l1 = DLG_TEXT[142];
						Link.l1.go = "node_16";
					}
					else
					{
						Dialog.Text = DLG_TEXT[139];
						Link.l1 = DLG_TEXT[48];
						Link.l1.go = "Rumours";
					}
					Link.l2 = DLG_TEXT[143];
					Link.l2.go = "node_21";
				}
			}
		break;
		
		case "node_16":
			Dialog.Text = DLG_TEXT[144];
			Link.l1 = DLG_TEXT[145];
			Link.l1.go = "node_17";
			Link.l2 = DLG_TEXT[146];
			Link.l2.go = "node_21";
		break;
		
		case "node_17":
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			Dialog.Text = DLG_TEXT[147];
			Link.l1 = DLG_TEXT[148];
			Link.l1.go = "node_18";
			Link.l2 = DLG_TEXT[149];
			Link.l2.go = "node_21";
		break;
		
		case "node_18":
			Dialog.Text = DLG_TEXT[150];
			Link.l1 = DLG_TEXT[151];
			Link.l1.go = "node_19";
			Link.l2 = DLG_TEXT[152];
			Link.l2.go = "node_21";
			Characters[GetCharacterIndex("Fred Bob")].quest.dialog = "1"; // PB: Mark that you know about him now
			ChangeCharacterAddressGroup(characterFromID("Fred Bob"), "Falaise_de_fleur_port_02", "goto", "locator28");
			SetQuestHeader("fred_bob");
			AddQuestRecord("fred_bob", 1);
		break;
		
		case "node_19":
			Dialog.Text = DLG_TEXT[153];
			Link.l2 = DLG_TEXT[154];
			Link.l2.go = "node_20";
			Link.l1 = DLG_TEXT[155];
			Link.l1.go = "exit";
		break;

		case "node_20":
			Dialog.Text = DLG_TEXT[156];
			Link.l1 = DLG_TEXT[157];
			Link.l1.go = "node_20a";
		break;

		case "node_20a":
			Dialog.Text = DLG_TEXT[158] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[159];			
			Link.l1 = DLG_TEXT[160];
			Link.l1.go = "node_21";
		break;

		case "node_21":
			Dialog.Text = LinkRandPhrase(DLG_TEXT[161], DLG_TEXT[163], DLG_TEXT[164]);
			Link.l1 = LinkRandPhrase(DLG_TEXT[162], DLG_TEXT[165], DLG_TEXT[166]);
			Link.l1.go = "exit";
		break;
		
		case "rehire_fb":
			Dialog.Text = DLG_TEXT[170] + PChar.name +  DLG_TEXT[171];
			Link.l1 = DLG_TEXT[172];
			Link.l1.go = "rehire_fb2";
			Link.l2 = DLG_TEXT[173];
			Link.l2.go = "node_21";
		break;
		
		case "rehire_fb2":
			Dialog.Text = DLG_TEXT[174];
			Link.l1 = DLG_TEXT[175];
			Link.l1.go = "node_21";
		break;
			
		// <-- end Fred Bob dialog by CatalinaThePirate

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

	}
}

