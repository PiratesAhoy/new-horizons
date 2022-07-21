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

			Dialog.mood = "normal";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

//			if (PChar.quest.Muerte == "search")
			if (!CheckAttribute(PChar, "quest.cotbp_done") || sti(PChar.quest.cotbp_done) == false)
			{
				if(checkquestattribute("Muerte", "search"))		
				{
					dialog.snd = "Voice\CLLA\CLLA004";
					dialog.text = DLG_TEXT[26];
					link.l1 = DLG_TEXT[2];
					link.l1.go = "begin_1";				
					PlaySound("trep\PEOPLE\snore.wav");
				}
				if(checkquestattribute("Jacks_early_days", "Get_ready_for_Guadeloupe"))
				{
					dialog.snd = "Voice\CLLA\CLLA004";
					dialog.text = DLG_TEXT[33];
					link.l1 = DLG_TEXT[35];
					link.l1.go = "exitGibbs";
				}	
   			}
		break;

		case "begin_1":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "begin_2";
		break;

		case "begin_2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = Pchar.name + DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "begin_3";
		break;

		case "begin_3":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[7];
			link.l1.go = "exit";
			LAi_SetStayType(characterFromID("Will Turner"));
			AddDialogExitQuest("Goto Tortuga tavern");
		break;

		case "begin_4":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "begin_5";
		break;

		case "begin_5":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "begin_6";
		break;

		case "begin_6":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = Pchar.name + DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "begin_7";
		break;

		case "begin_7":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "begin_8";
		break;

		case "begin_8":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "begin_8A";
		break;
// TALISMAN added --->

		case "begin_8A":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "begin_9";
		break;

//TALISMAN <-----		
		
		case "begin_9":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "begin_10";
		break;

		case "begin_10":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			AddDialogExitQuest("meetthecrew");
		break;

		case "begin_11":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
			AddDialogExitQuest("voirannamaria");
		break;

		case "begin_12":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			AddDialogExitQuest("directionislademuerta");
		break;

		case "begin_13":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[27] + Pchar.name + " !";
			link.l1 = DLG_TEXT[28];
			link.l1.go = "begin_14";
		break;

		case "begin_14":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "begin_15";
		break;

		case "begin_15":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "exit";
			AddDialogExitQuest("findecotbp");
		break;

		case "Playing_Vanguard":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "exit";
			AddDialogExitQuest("Gibbs_to_Tavern");
		break;

		case "Stay_or_Accompany":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "Exit_Stay";
			link.l2 = DLG_TEXT[38];
			link.l2.go = "ExitAccompany";			
		break;
		
				
		case "Exit_Stay":
			AddDialogExitQuest("Goodbye_Gibbs_and_Willemoes");
			RemoveOfficersIndex(pchar, GetCharacterIndex("Mr. Gibbs"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Peter Willemoes"));			
			RemoveCharacterCompanion(Pchar, &Characters[GetCharacterIndex("Peter Willemoes")]);
			SetCharacterRemovable(characterFromID("Peter Willemoes"), true);
			RemovePassenger(Pchar, characterFromID("Peter Willemoes"));				
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "ExitAccompany":
			AddDialogExitQuest("Continue_with_Gibbs_and_Willemoes");		
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "ExitGibbs":
			AddDialogExitQuest("Gibbs_to_sort_ship");		
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "ExitGibbs":
			AddDialogExitQuest("Gibbs_to_sort_ship");		
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		//Dead mans chest dialogue
		case "talk_jack_ship":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "exit";
			AddDialogExitQuest("Set_sail_turks");
		break;
		
		//Dead mans chest dialogue on ship after turks
		case "talk_jack_ship_turks":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "talk_jack_ship_turks2";
		break;
		
		//Dead mans chest dialogue on ship after turks
		case "talk_jack_ship_turks2":
			dialog.snd = "Voice\CLLA\CLLA003";
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "talk_jack_ship_turks3";
			
		break;
		
		//Dead mans chest dialogue on ship after turks
		case "talk_jack_ship_turks3":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "exit";
			AddDialogExitQuest("tp_deck_anamaria_dialog");
		break;
		
		//Dead mans chest dialogue on ship after turks
		case "tp_deck_gibbs_dialog_turks":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "tp_deck_gibbs_dialog_turks2";
		break;
		
		//Dead mans chest dialogue on ship after turks
		case "tp_deck_gibbs_dialog_turks2":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "tp_deck_gibbs_dialog_turks3";
		break;
		
		//Dead mans chest dialogue on ship after turks
		case "tp_deck_gibbs_dialog_turks3":
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "tp_deck_gibbs_dialog_turks4";
		break;
		
		//Dead mans chest dialogue on ship after turks
		case "tp_deck_gibbs_dialog_turks4":
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "tp_deck_gibbs_dialog_turks5";
		break;

		//Dead mans chest dialogue on ship after turks
		case "tp_deck_gibbs_dialog_turks5":
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "exit";
			AddDialogExitQuest("cleanup_after_turks");
		break;


		//Dead mans chest dialogue after bootstrap meeting, sail to shore
		case "tp_deck_gibbs_dialog_bootstrap":
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "tp_deck_gibbs_dialog_bootstrap2";
		break;
		
		//Dead mans chest dialogue after bootstrap meeting, sail to shore
		case "tp_deck_gibbs_dialog_bootstrap2":
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "tp_deck_gibbs_dialog_bootstrap3";
		break;
		
		//Dead mans chest dialogue after bootstrap meeting, sail to shore
		case "tp_deck_gibbs_dialog_bootstrap3":
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "exit";
			AddDialogExitQuest("load_shore_cannibal"); 
		break;	
		
		case "talk_gibbs_cannibal_shore":
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "exit";
			AddDialogExitQuest("talk_gibbs_canniba2");
		break;	
		
		//Ambush
		case "dialogue_gibbs_cave":
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "exit";
			AddDialogExitQuest("attack_cannibals_2");
		break;	
		
		case "dialogue_gibbs_cave_poisoned":
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "exit";
			AddDialogExitQuest("fade_before_stunned");
		break;	
		
		case "cavern_talk_gibbs_escape":
			dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "exit";
			AddDialogExitQuest("cavern_talk_gibbs_escape4");
		break;	
		//On board talk
		case "after_cannib_talk":
			dialog.text = DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "after_cannib_talk2";
		break;	
		//On board talk
		case "after_cannib_talk2":
			dialog.text = DLG_TEXT[75];
			link.l1 = DLG_TEXT[76];
			link.l1.go = "exit";
			AddDialogExitQuest("dialogue_start_deck_cannibals_after_will");
		break;
		
		//At antigua dalma
		case "talk_jack_antigua":
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "exit";
			AddDialogExitQuest("antigua_walk_to_dalma_1");
		break;
		
		//At shack dalma
		case "talk_dalma_antigua":
			dialog.text = DLG_TEXT[79];
			link.l1.go = "exit";
			AddDialogExitQuest("At_Shack_Warning2_6");
		break;
		
		//At shack dalma
		case "talk_dalma_antigua2":
			dialog.text = DLG_TEXT[80];
			link.l1.go = "exit";
			AddDialogExitQuest("At_Shack_Warning2_9");
		break;
		
		case "talk_shipwreck_dutchman":
			dialog.text = DLG_TEXT[81];
			link.l1.go = "exit";
			AddDialogExitQuest("dialogue_start_deck_shipwreck_4");
		break;
		
		case "talk_shipwreck_dutchman_after":
			dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "talk_shipwreck_dutchman_after_2";
		break;
		
		case "talk_shipwreck_dutchman_after_2":
			dialog.text = DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "exit";
			AddDialogExitQuest("Sparrow_to_tortuga_after_shipw");
		break;
		
		case "Tortuga_gibbs_DMC_talk":
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[87];
			link.l1.go = "exit";
			AddDialogExitQuest("Tortuga_gibbs_DMC_tavern");
		break;
		
		case "Tavern_gibbs_DMC_talk":
			dialog.text = DLG_TEXT[88];
			link.l1.go = "exit";
			AddDialogExitQuest("Crewman_to_gibbs_tavern");
		break;
		
		case "Tavern_gibbs_DMC_talk_after":
			dialog.text = DLG_TEXT[89];
			link.l1.go = "exit";
			AddDialogExitQuest("Crewman1go");
		break;
		
		case "Tavern_gibbs_DMC_talk_after2":
			dialog.text = DLG_TEXT[90];
			link.l1.go = "exit";
			AddDialogExitQuest("Crewman2go");
		break;
		
		case "Tavern_gibbs_DMC_talk_after3":
			dialog.text = DLG_TEXT[91];
			link.l1.go = "exit";
			AddDialogExitQuest("Crewman3go");
		break;
	
		
		
		case "Talk_Gibbs_to_norrington":
			dialog.text = DLG_TEXT[92];
			link.l1.go = "exit";
			AddDialogExitQuest("Norrington_to_gibbs");
		break;
		
		case "Talk_Gibbs_to_norrington_2":
			dialog.text = DLG_TEXT[93];
			link.l1.go = "exit";
			AddDialogExitQuest("Norrington_to_gibbs_2");
		break;
		
		case "Gibbs_port_final_talk":
		dialog.text = DLG_TEXT[94];
		link.l1 = DLG_TEXT[95];
		link.l1.go = "Gibbs_port_final_talk2";
		break;
		
		case "Gibbs_port_final_talk2":
		dialog.text = DLG_TEXT[96];
		link.l1 = DLG_TEXT[97];
		link.l1.go = "exit";
		AddDialogExitQuest("After_Tortuga_port_cleanup");
		break;
	
	}
}
