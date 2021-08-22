void ProcessDialogEvent()
{
	ref NPChar;
	
	DeleteAttribute(&Dialog,"Links");
	aref Link, NextDiag;
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
			
			dialog.snd = "Voice\HAAU\HAAU001";
			Preprocessor_Add("nation", GetNationNameByType(GetTownNation("Falaise de Fleur")));
			Dialog.Text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1];
			Link.l1 = DLG_TEXT[2] + GetMyFullName(PChar) + DLG_TEXT[3];
			link.l1.go = "Second time";
			NextDiag.TempNode = "Second time";
		break;

		case "Second time":
			dialog.snd = "Voice\HAAU\HAAU002";
			Dialog.text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "node_3";
			if (Characters[GetCharacterIndex("Patric Cardone")].quest.teodoro == "7") // NK thanks to Taghmon
			{
				Link.l2 = DLG_TEXT[6];
				link.l2.go = "teodoro";
			}
		break;

		case "node_3":
			dialog.snd = "Voice\HAAU\HAAU003";
			Dialog.text = DLG_TEXT[7] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[8];
			if(characters[GetCharacterIndex("Fred Bob")].quest.help == "agreed")  // <-- Cat Fred Bob quest 
			{
				if (GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS) Link.l1 = DLG_TEXT[53];
				else Link.l1 = DLG_TEXT[30];
				Link.l1.go = "fb_node_4"; 
			}   // <-- Cat Fred Bob quest
			else
			{
				link.l1 = DLG_TEXT[9];
				link.l1.go = "exit";
			}
		break;

		case "teodoro":
			dialog.snd = "Voice\HAAU\HAAU004";
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[12])]) + DLG_TEXT[14];
			link.l1.go = "teodoro_1";
		break;

		case "teodoro_1":
			dialog.snd = "Voice\HAAU\HAAU005";
			Dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go ="teodoro_2";
		break;

		case "teodoro_2":
			dialog.snd = "Voice\HAAU\HAAU006";
			Dialog.text = DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[19])]) + DLG_TEXT[21];
			link.l1.go = "teodoro_3";
		break;

		case "teodoro_3":
			dialog.snd = "Voice\HAAU\HAAU007";
			Dialog.text = DLG_TEXT[22];
			if (LAi_IsDead(Characters[GetCharacterIndex(DLG_TEXT[19])]))
			{
				link.l1 = DLG_TEXT[50] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[12])]) + DLG_TEXT[51];
				link.l1.go = "teodoro_6";
			}
			else
			{
				link.l1 = DLG_TEXT[23];
				Link.l1.go = "teodoro_4";
			}
		break;

		case "teodoro_4":
			dialog.snd = "Voice\HAAU\HAAU008";
			Dialog.text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[25];
			link.l1.go = "teodoro_5";
		break;

		case "teodoro_5":
			dialog.snd = "Voice\HAAU\HAAU009";
			Dialog.text = DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			link.l1.go = "teodoro_6";
		break;

		case "teodoro_6":
			dialog.snd = "Voice\HAAU\HAAU010";
			if (LAi_IsDead(Characters[GetCharacterIndex(DLG_TEXT[19])])) Dialog.text = DLG_TEXT[52];
			else Dialog.text = DLG_TEXT[28];
			Link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
			Characters[GetCharacterIndex("Patric Cardone")].dialog.currentnode = "Teodoro_completed";
			Characters[GetCharacterIndex("Patric Cardone")].quest.teodoro = "";
			characters[GetCharacterIndex("Lucien Bescanceny")].location	= "none";
			AddQuestRecord("Patric", 10); // NK
		break;
		
		// Cat Fred Bob quest -->
		case "fb_node_4":
			dialog.snd = "Voice\HAAU\HAAU004";
			Dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			Link.l1.go = "fb_node_5";
		break;
		
		case "fb_node_5":
			dialog.snd = "Voice\HAAU\HAAU005";
			Dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			Link.l1.go = "fb_node_6";
		break;
		
		case "fb_node_6":
			dialog.snd = "Voice\HAAU\HAAU006";
			Preprocessor_Add("nation", GetNationNameByType(GetTownNation("Falaise de Fleur")));
			Dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			if(makeint(PChar.reputation)>=6)
			{
				Link.l1.go = "fb_node_7";
			}
			else
			{
				Link.l1.go = "fb_node_8";
			}

			link.l2 = DLG_TEXT[37];
			Link.l2.go = "exit";
		break;
		
		case "fb_node_7":
			dialog.snd = "Voice\HAAU\HAAU007";
			Characters[GetCharacterIndex("Fred Bob")].quest.help = "done";
			characters[GetCharacterIndex("Fred Bob")].dialog.currentnode = "Help_succesful";
			Dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			Link.l1.go = "fb_node_9";
			AddQuestRecord("fred_bob", 6);
		break;
		
		case "fb_node_8":
			Characters[GetCharacterIndex("Fred Bob")].quest.help = "failed";
			Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
			Dialog.Text = DLG_TEXT[40] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[41];
			Link.l1 = DLG_TEXT[42];
			Link.l1.go = "exit";
			AddQuestRecord("fred_bob", 5);
			Link.l2 = DLG_TEXT[43];
			Link.l2.go = "Second time";
		break;
		
		case "fb_node_9":
			dialog.snd = "Voice\HAAU\HAAU008";
			Dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			Link.l1.go = "fb_node_10";
		break;
		
		case "fb_node_10":
			dialog.snd = "Voice\HAAU\HAAU009";
			Dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			Link.l1.go = "fb_node_11";
		break;
		
		case "fb_node_11":
			dialog.snd = "Voice\HAAU\HAAU010";
			Dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			Link.l1.go = "exit";
		break;
		// <-- Cat Fred Bob quest

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
		break;
	}
}
