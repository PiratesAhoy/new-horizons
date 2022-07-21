//#include "DIALOGS\Oxbay James_Norrington_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar,PChar,d; 
	aref Link, Diag;
	
	DeleteAttribute(&Dialog,"Links");

	//ref PChar;
	PChar = GetMainCharacter();

	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	//int DonationSize;
	


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

			Dialog.mood = "normal";
			PlaySound("VOICE\ENGLISH\Norrington02.wav");
			if(CheckQuestAttribute("henry_talk", "Swann_and_French_attack_plan"))
			{
				dialog.text = DLG_TEXT[74];
				link.l1 = DLG_TEXT[75];
				link.l1.go = "exit_back_to_Swann";
			}
			/*if(CheckQuestAttribute("henry_talk", "not_taking_Interceptor"))
			{
				dialog.text = DLG_TEXT[70];
				link.l1 = DLG_TEXT[71];
				link.l1.go = "Ally_with_pirates";
			}*/
			if(CheckQuestAttribute("Turner", "Straight_from_Jail"))
			{
				dialog.text = DLG_TEXT[17] + pchar.lastname + DLG_TEXT[18];
				link.l1 = DLG_TEXT[19];
				link.l1.go = "Take_the_Interceptor";
			} else {
				PlaySound("VOICE\ENGLISH\Norrington02.wav");
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "Norrington_talk_2";
			}
			//AddDialogExitQuest("Norrington_talk_1");
		break;

		case "Take_the_Interceptor":
			dialog.text = DLG_TEXT[20];
//			link.l1 = DLG_TEXT[21] + GetMyFullName(PChar);
			link.l1 = DLG_TEXT[21] + GetMySimpleName(PChar) + ".";
			link.l1.go = "Take_the_Interceptor2";
		break;

		case "Take_the_Interceptor2":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
		break;

		case "The_French_Spy_Oxbay":
			dialog.text = DLG_TEXT[16] + Pchar.name + DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "The_French_Spy_Oxbay2";
		break;

		case "The_French_Spy_Oxbay2":
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "The_French_Spy_Oxbay3";
		break;

		case "The_French_Spy_Oxbay3":
			dialog.text = DLG_TEXT[67] + Pchar.name + DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "The_French_Spy_Oxbay_Exit";
		break;

		case "The_French_Spy_Oxbay_Exit":
			Pchar.quest.Norrington = 3;			
			AddDialogExitQuest("Norrington_and_the_French");
			DialogExit();
		break;	
		
		case "The_Governor_and_Norrington":
			LAi_ActorGoToLocator(characterFromID("Malvert Mullroy"), "goto", "goto_44", "", -1);		
//			dialog.text = DLG_TEXT[32] + GetMyFullName(PChar);	// GR: GetMyFullName includes your rank if you have one
//			link.l1 = DLG_TEXT[33] + GetMyFullName(PChar) + DLG_TEXT[34];
			dialog.text = DLG_TEXT[32] + GetMySimpleName(PChar) + ".";
			link.l1 = DLG_TEXT[33] + GetMySimpleName(PChar) + DLG_TEXT[34];
			link.l1.go = "Norrington_and_Governor";
		break;
		
		case "Norrington_and_Governor":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Swannexit";
		break;

		case "Governor_knocked_out":
			dialog.text = DLG_TEXT[92];
			link.l1 = DLG_TEXT[93];
			link.l1.go = "Swannexitagain";
		break;		
		
		case "Swannexit":
			AddDialogExitQuest("Swann_starts_talking");
//			Diag.CurrentNode = Diag.TempNode;
//			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "Swannexitagain":
			AddDialogExitQuest("Off_to_shipyard_now");
			DialogExit();
		break;
		
		case "Norrington_talk_2":
			dialog.text = DLG_TEXT[2];
//			link.l1 = DLG_TEXT[3] + GetMyFullName(Pchar) + DLG_TEXT[4];	// GR: GetMyFullName includes your rank if you have one
			link.l1 = DLG_TEXT[3] + GetMySimpleName(Pchar) + DLG_TEXT[4];
			link.l1.go = "Norrington_talk_3";		
		break;

		case "Norrington_talk_3":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6] + GetMyName(Pchar) + DLG_TEXT[7];
			link.l1.go = "originalOxbay2";
		break;

		case "originalOxbay2":
			dialog.text = DLG_TEXT[8] + GetMyName(Pchar) + DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "originalOxbay3";
		break;

		case "originalOxbay3":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "originalOxbay4";
		break;

		case "originalOxbay4":
			AddDialogExitQuest("Norrington_walk_Cliffs");
			dialog.text = DLG_TEXT[13] + GetMyName(PChar) + DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "originalOxbay_exit";
		break;

		case "originalOxbay_exit":
			// KK DeleteAttribute(&Locations[FindLocation("Oxbay_town")],"vcskip"); 
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("Norrington_walk_Cliffs");			
		break;


		case "Other_Island_Start":
			dialog.text = DLG_TEXT[2];
//			link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4];	// GR: GetMyFullName includes your rank if you have one
			link.l1 = DLG_TEXT[3] + GetMySimpleName(PChar) + DLG_TEXT[4];
			link.l1.go = "captured2";
		break;

		case "captured2":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27] + GetMyName(PChar) + DLG_TEXT[28];
			link.l1.go = "captured3";
		break;

		case "captured3":
			dialog.text = DLG_TEXT[29] + GetMyName(Pchar) + DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "captured4";
		break;

		case "captured4":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "captured_exit";
		break;

		case "captured_exit":
			// KK DeleteAttribute(&Locations[FindLocation("Oxbay_town")],"vcskip"); 
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("Norrington_walk_Cliffs");
		break;

		case "Find_French_Officer":	
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay1";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20] + GetMyFullName(PChar) + DLG_TEXT[21];
			link.l1.go = "not Oxbay start";
		break;

		case "not Oxbay start":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27] + GetMyName(PChar) + DLG_TEXT[28];
			link.l1.go = "not Oxbay start2";
		break;

		case "not Oxbay start2":
			dialog.text = DLG_TEXT[29] + GetMyName(PChar) + DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "not Oxbay start3";
		break;

		case "not Oxbay start3":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "not Oxbay start4";

		break;

		case "not Oxbay start4":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "notOxbay_exit";

		break;

		case "notOxbay_exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			npchar.location = "none";
		break;

		case "begin_1_on_Island":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay1";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";
			
//			dialog.text = DLG_TEXT[37] + GetMyFullName(PChar);	// GR: GetMyFullName includes rank if you have one, e.g. Mr. Freebooter Jack Sparrow
			dialog.text = DLG_TEXT[37] + GetMySimpleName(PChar) + "."; 
			link.l1 = DLG_TEXT[38];
			link.l1.go = "Begin_2";
		break;

		case "Begin_2":
			dialog.text = DLG_TEXT[39]; 
			link.l1 = DLG_TEXT[40];
			link.l1.go = "exit";
			AddDialogExitQuest("abordauntless");
		break;

		case "Begin_3":
			dialog.text = DLG_TEXT[41]; 
			link.l1 = DLG_TEXT[42];
			link.l1.go = "Begin_4";
		break;

		case "Begin_4":
			dialog.text = DLG_TEXT[43]; 
			link.l1 = DLG_TEXT[44];
			link.l1.go = "Begin_5";
		break;

		case "Begin_5":
			dialog.text = DLG_TEXT[45]; 
			link.l1.go = "exit";
			LAi_SetStayType(CharacterFromID("Elizabeth Swann"));
			AddDialogExitQuest("proposerabarbossa");
		break;

		case "the_prison_fight_scene":
			dialog.text = DLG_TEXT[50] + Pchar.lastname + DLG_TEXT[51]; 
			link.l1 = DLG_TEXT[52];
			link.l1.go = "the_prison_fight_scene2";
		break;
		
		case "the_prison_fight_scene2":
//			RemoveCharacterEquip(characterFromID("James Norrington"), BLADE_ITEM_TYPE);		
			dialog.text = DLG_TEXT[53] + Pchar.lastname + DLG_TEXT[54]; 
			link.l1 = DLG_TEXT[55];
			LAi_SetActorType(Pchar);
//			LAi_ActorAnimation(pchar, "attack_2", "", 0.0);			
//			PlaySound("OBJECTS\duel\punch1.wav");
			link.l1.go = "the_prison_fight_scene3";
		break;

		case "the_prison_fight_scene3":
			dialog.text = DLG_TEXT[56]; 
			link.l1 = DLG_TEXT[57];
			link.l1.go = "exit";
//			LAi_ActorAnimation(pchar, "attack_2", "", 0.0);			
//			PlaySound("OBJECTS\duel\punch1.wav");	
			RemoveCharacterEquip(characterFromID("James Norrington"), BLADE_ITEM_TYPE);			
			GiveItem2Character(Pchar, "blade4");   
			EquipCharacterByItem(Pchar, "blade4");			
			AddDialogExitQuest("Over_the_wall");
		break;
		
		case "In_the_fort":
			dialog.text = DLG_TEXT[46]; 
			link.l1 = DLG_TEXT[47];
			link.l1.go = "exit";
		break;
		
		case "the_prison_scene":
			dialog.text = DLG_TEXT[48]; 
			link.l1 = DLG_TEXT[49] + Pchar.name;
			link.l1.go = "exit";
			AddDialogExitQuest("Governor_to_Elizabeth");
		break;

		case "Grottoarrest":
			dialog.text = DLG_TEXT[60] + Pchar.lastname + DLG_TEXT[61]; 
			link.l1 = DLG_TEXT[62];
			link.l1.go = "exit";
		break;
			
		case "Goodbye_Commodore":
			dialog.text = DLG_TEXT[58]; 
//			link.l1 = DLG_TEXT[59] + GetMyFullName(PChar);	// GR: GetMyFullName includes rank if you have one
			link.l1 = DLG_TEXT[59] + GetMySimpleName(PChar) + ".";
			link.l1.go = "exit";
		break;
	
		case "Ally_with_pirates":
			dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[71];
			link.l1.go = "Ally_with_pirates2";
		break;

		case "Ally_with_pirates2":
			dialog.text = DLG_TEXT[72]; 
			link.l1 = DLG_TEXT[73];
			link.l1.go = "exit";
			pchar.quest.henry_talk = "Swann_and_French_attack_plan";			
			AddDialogExitQuest("Continue_with_French_attack_plan");			
		break;

		case "Fix_it_line":
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "exit_back_to_Swann";
		break;
		
		case "exit_back_to_Swann":
			pchar.quest.henry_talk = "Norrington_to_be_pirate";		
			AddDialogExitQuest("Continue_with_French_attack_plan2");
			DialogExit();
			Diag.CurrentNode = "First time";
		break;
		
		case "serving_as_a_pirate":
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "exit_back_to_Player";
		break;

		case "exit_back_to_Player":		
			pchar.quest.henry_talk = "zilch";		
			DialogExit();
			Diag.CurrentNode = "serving_as_a_pirate";
		break;

		case "exit_back_to_Player_at_port":
			AddDialogExitQuest("Farewell_at_the_dock");		
			pchar.quest.henry_talk = "zilch";		
			DialogExit();
			Diag.CurrentNode = "talk_at_dock";
		break;		
		
		
		case "Talk_in_Turks_Tavern":
			dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79];
			link.l1.go = "Talk_in_Turks_Tavern2";
		break;
		
		case "Talk_in_Turks_Tavern2":
			dialog.text = DLG_TEXT[80];
			link.l1 = DLG_TEXT[81];
			link.l1.go = "Talk_in_Turks_Tavern3";
		break;		
 
		case "Talk_in_Turks_Tavern3":
			dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "Talk_in_Turks_Tavern4";
		break;

		case "Talk_in_Turks_Tavern4":
			pchar.quest.henry_talk = "leaves_turks";		
			dialog.text = DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "exit_back_to_Player_at_port";
		break;

		case "Talk_at_Turks_Dock":
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[87];
			link.l1.go = "Talk_at_Turks_Dock2";
		break;		

		case "Talk_at_Turks_Dock2":
			dialog.text = DLG_TEXT[88];
			link.l1 = DLG_TEXT[89];
			link.l1.go = "Talk_at_Turks_Dock3";
		break;

		case "Talk_at_Turks_Dock3":
			AddDialogExitQuest("Norrington_sails_away");		
			dialog.text = DLG_TEXT[90];
			link.l1 = DLG_TEXT[91];
			link.l1.go = "exit";
		break;

		case "Talk_at_Tortuga_Tavern":		
			dialog.text = DLG_TEXT[94];
			link.l1.go = "exit";
			AddDialogExitQuest("Gibbs_to_norrington_2");
		break;

		case "Talk_at_Tortuga_Tavern_2":		
			dialog.text = DLG_TEXT[95];
			link.l1.go = "Talk_at_Tortuga_Tavern_3";
		break;

		case "Talk_at_Tortuga_Tavern_3":		
			dialog.text = DLG_TEXT[96];
			link.l1.go = "Talk_at_Tortuga_Tavern_4";
		break;
		
		case "Talk_at_Tortuga_Tavern_4":		
			dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "Talk_at_Tortuga_Tavern_5";
		break;
		
		case "Talk_at_Tortuga_Tavern_5":		
			dialog.text = DLG_TEXT[99];
			link.l1.go = "exit";
			AddDialogExitQuest("Norrington_attack_stand_fade");
		break;
		
		case "Talk_at_Tortuga_Port":		
			dialog.text = DLG_TEXT[100];
			link.l1 = DLG_TEXT[101];
			link.l1.go = "Talk_at_Tortuga_Port2";
		break;
		
		case "Talk_at_Tortuga_Port2":		
			dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "exit";
			AddDialogExitQuest("Elizabeth_tortuga_port_talk3");
		break;
		
	}
}
