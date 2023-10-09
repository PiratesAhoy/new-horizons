//#include "DIALOGS\Will Turner_dialog.h"

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
			
			dialog.text = DLG_TEXT[122];
			link.l1 = DLG_TEXT[123];
			link.l1.go = "exit";
			
			if(CheckQuestAttribute("Turner", "Straight_from_Jail"))
			{
				dialog.text = DLG_TEXT[18];
				link.l1 = DLG_TEXT[19];
				link.l1.go = "exitTurner2";
			}
			if(CheckQuestAttribute("Turner", "In_the_Shipyard"))
			{
				dialog.text = DLG_TEXT[81];
				link.l1 = DLG_TEXT[82];
				link.l1.go = "shipyard1";
			}			
			if(CheckQuestAttribute("Jackpot", "search"))
			{
				dialog.snd = "Voice\CLLA\CLLA004";
				if (PChar.model == "will" || PChar.model == "will_A1" || PChar.model == "will_A2" || PChar.model == "will_A3") dialog.text = DLG_TEXT[125];
				else dialog.text = DLG_TEXT[41];
				link.l1 = DLG_TEXT[42] + GetMyFullName(PChar) + DLG_TEXT[43] + GetMyShipNameShow(PChar) + DLG_TEXT[44];
				link.l1.go = "begin_1";	
			}
			if(CheckQuestAttribute("Turner", "Change_over_to_Bartolomeu_Quest"))
			{
				dialog.snd = "Voice\CLLA\CLLA004";
				dialog.text = DLG_TEXT[79];
				link.l1 = DLG_TEXT[80];
				link.l1.go = "begin_28xxx";
			}
			if(CheckQuestAttribute("Turner", "rescue_Jack"))
			{
				dialog.text = DLG_TEXT[93];
				link.l1 = DLG_TEXT[94];
				link.l1.go = "rescue_Jack2";
			}
		break;

		case "afterSkeletons":
			dialog.text = DLG_TEXT[112] + Pchar.lastname + "!";
			link.l1 = DLG_TEXT[113];
			link.l1.go = "speak1A";
		break;

		case "Here_they_Come":
			dialog.text = DLG_TEXT[124]
			link.l1.go = "exit";
		break;

		case "speak1A":
			dialog.text = DLG_TEXT[114];
			link.l1 = DLG_TEXT[115];
			link.l1.go = "speak1B";
		break;		

		case "speak1B":
			dialog.text = DLG_TEXT[116];
			link.l1 = DLG_TEXT[117];
			link.l1.go = "speak1C";
		break;

		case "speak1C":
			dialog.text = DLG_TEXT[118];
			link.l1 = DLG_TEXT[119];
			link.l1.go = "speak1D";
		break;

		case "speak1D":
			dialog.text = DLG_TEXT[120];
			link.l1 = DLG_TEXT[121];
			link.l1.go = "speak1E";
		break;

		case "speak1E":
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "speak1";
		break;
		
		case "speak1":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "speak2";
		break;

		case "speak2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "speak3";
		break;

		case "speak3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "speak3AA";
		break;

		case "speak3AA":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "speak4";
		break;


		case "speak4":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "speak5";
		break;

		case "speak5":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "speak6";
		break;

		case "speak6":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "speak7";
		break;

		case "speak7":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "speak8";
		break;

		case "speak8":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exitTurner1";
		break;
 
		case "shipyardfirst":
 			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "shipyard1";
		break;
 
		case "shipyard1":
			dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "shipyard2";
		break;
                
		case "shipyard2":
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "shipyard3";
		break;

		case "shipyard3":
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "exitshipyard";
		break;		
		
		case "shipyardagain":
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "shipyardagain2";
		break;
                
		case "shipyardagain2":
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "exitshipyard2";
		break;
		
        case "begin_1":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "begin_2";
		break;
						
		case "begin_2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "begin_3";
		break;

		case "begin_3":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "begin_4";
		break;
               
        case "begin_4":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "begin_5";
		break;

		case "begin_5":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "begin_6";
		break;

		case "begin_6":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "begin_7";
		break;

		case "begin_7":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "begin_8";
		break;

		case "begin_8":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "begin_10";
			link.l2 = DLG_TEXT[61];
			link.l2.go = "begin_9";
		break;

		case "begin_9":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "exit";
			AddDialogExitQuest("jackpotrefused");
		break;

		case "begin_10":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[64];
			link.l1.go = "exit";
			AddDialogExitQuest("talktoswann");
		break;

		case "begin_11":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "exit";
			AddDialogExitQuest("meetindians");
		break;

		case "begin_12":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "exit";
			AddDialogExitQuest("gospanishcamp");
		break;

		case "begin_13":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "begin_14";
		break;

		case "begin_14":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "exit";
			AddDialogExitQuest("gosilvertrain");
		break;

		case "begin_15":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "exit";
			AddDialogExitQuest("leavedevilcreek");
		break;

		case "begin_16":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[75];
			link.l1 = DLG_TEXT[76];
			link.l1.go = "begin_17";
		break;

		case "begin_17":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "exit";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddDialogExitQuest("leaveturner");
		break;

		case "begin_18":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "begin_19";
		break;
                 
		case "begin_19":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			AddDialogExitQuest("partirtortue");
		break;

		case "begin_20":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = Pchar.name + " !";
			link.l1 = DLG_TEXT[28];
			link.l1.go = "begin_21";
		break;

		case "begin_21":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "begin_22";
		break;

		case "begin_22":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[31] + Pchar.name + " !";
			link.l1.go = "exit";
			AddDialogExitQuest("coupwill");
		break;

		case "begin_23":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "begin_24";
			LAi_SetActorType(characterFromID("Elizabeth Swann"));
			LAi_ActorFollowEverywhere(characterFromID("Elizabeth Swann"), "", 60.0);
			LAi_ActorFollowEverywhere(characterFromID("Will Turner"), "", 60.0); // SJG			
		break;

		case "begin_24":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[34];
			link.l1.go = "exit";
			LAi_SetPlayerType(pchar);
			AddDialogExitQuest("justapresfight2");
		break;

		case "begin_25":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "exit";
			AddDialogExitQuest("arrestatGrotto");
		break;

        case "begin_26":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "begin_27";
		break;

		case "begin_27":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "exit";
			AddDialogExitQuest("avoirbp");
		break;

		case "begin_28":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "begin_28xxx";
		break;

        case "begin_28xxx":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
            AddDialogExitQuest("voirgibbs");
		break;
 
		case "Turner_Jail_Break":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exitTurner2";
		break;

		case "On_the_Beach_with_Gibbs":
			dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
           		AddDialogExitQuest("muerte_with_Gibbs_and_Turner2");
			link.l1.go = "exit";		
		break;

		case "It_Is_Me_You_Want":
			LAi_ActorTurnToCharacter(characterFromID("Barbossa"), characterFromID("Will Turner"));		
			dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[100];
			link.l1.go = "It_Is_Me_You_Want2";			
		break; 
		
		case "It_Is_Me_You_Want2":
			LAi_ActorTurnToCharacter(characterFromID("Will Turner"), characterFromID("Barbossa"));		
			dialog.text = DLG_TEXT[101] + pchar.name + DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "ExitMeYouWant";			
		break; 		
		
        case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "ExitMeYouWant":
			AddDialogExitQuest("Elizabeth_and_me_to_Island");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;		
		
		case "rescue_Jack2":
			dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];
			link.l1.go = "exitexecution";
		break;		

		case "talking on turks":
			dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];
			link.l1.go = "talking on turks2";
		break;		

		case "talking on turks2":
			dialog.text = DLG_TEXT[106];
			link.l1 = DLG_TEXT[107];
			link.l1.go = "talking on turks3";
		break;		

		case "talking on turks3":
			dialog.text = DLG_TEXT[108];
			link.l1 = DLG_TEXT[109];
			link.l1.go = "talking on turks4";
		break;		

		case "talking on turks4":
			dialog.text = DLG_TEXT[110];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "exit talking on turks";
		break;		

		case "cannibals_will_talk":
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[127];
			link.l1.go = "cannibals_will_talk_2";
		break;	
		
		case "cannibals_will_talk_2":
			dialog.text = DLG_TEXT[128];
			link.l1 = DLG_TEXT[129];
			link.l1.go = "cannibals_will_talk_3";
		break;	
		
		case "cannibals_will_talk_3":
			dialog.text = DLG_TEXT[130];
			link.l1 = DLG_TEXT[131];
			AddDialogExitQuest("cannibals_will_fight");
			link.l1.go = "Exit";
		break;	
		
		//Run to bridge
		case "cannibals_will_talk2":
			dialog.text = DLG_TEXT[132];
			link.l1 = DLG_TEXT[133];
			AddDialogExitQuest("cannibals_bridge_run1");
			link.l1.go = "Exit";
		break;	

		//On board after cannibals
		case "after_cannib_talk_will":
			dialog.text = DLG_TEXT[134];
			link.l1 = DLG_TEXT[135];
			link.l1.go = "after_cannib_talk_will2";
		break;	
		
		//On board after cannibals
		case "after_cannib_talk_will2":
			dialog.text = DLG_TEXT[136];
			link.l1 = DLG_TEXT[137];
			link.l1.go = "after_cannib_talk_will3";
		break;	
		
		//On board after cannibals
		case "after_cannib_talk_will3":
			dialog.text = DLG_TEXT[138];
			link.l1 = DLG_TEXT[139];
			link.l1.go = "after_cannib_talk_will4";
		break;	
		
		//On board after cannibals
		case "after_cannib_talk_will4":
			dialog.text = DLG_TEXT[140];
			link.l1 = DLG_TEXT[141];
			link.l1.go = "after_cannib_talk_will5";
		break;

		//On board after cannibals
		case "after_cannib_talk_will5":
			dialog.text = DLG_TEXT[142];
			link.l1 = DLG_TEXT[143];
			link.l1.go = "after_cannib_talk_will6";
		break;
		
		//On board after cannibals
		case "after_cannib_talk_will6":
			dialog.text = DLG_TEXT[144];
			link.l1 = DLG_TEXT[145];
			link.l1.go = "Exit";
			AddDialogExitQuest("cleanup_after_roa");
		break;
		
		//Antigua in search of dalma
		case "At_jungle_talk_will":
			dialog.text = DLG_TEXT[146];
			link.l1 = DLG_TEXT[147];
			link.l1.go = "Exit";
			AddDialogExitQuest("At_jungle_will_walk");
		break;
		
		//Antigua in search of dalma
		case "talk_jack_antigua":
			dialog.text = DLG_TEXT[148];
			link.l1 = DLG_TEXT[149];
			link.l1.go = "Exit";
			AddDialogExitQuest("At_smugglers_talk_will_2");
		break;
		
		//Antigua in search of dalma
		case "talk_jack_swamp":
			dialog.text = DLG_TEXT[150];
			link.l1 = DLG_TEXT[151];
			link.l1.go = "Exit";
			AddDialogExitQuest("At_swamp_talk_will2");
		break;
		
		//Antigua in hut
		case "talk_dalma_hut":
			dialog.text = DLG_TEXT[152];
			link.l1.go = "Exit";
			AddDialogExitQuest("At_Shack_Warning2_4");
		break;
		
		//Antigua in hut
		case "talk_dalma_hut2":
			dialog.text = DLG_TEXT[153];
			link.l1 = DLG_TEXT[154];
			link.l1.go = "Exit";
			AddDialogExitQuest("At_Shack_Warning2_8");
		break;
		
		//Antigua in hut
		case "talk_dalma_hut3":
			dialog.text = DLG_TEXT[155];
			link.l1 = DLG_TEXT[156];
			link.l1.go = "talk_dalma_hut4";
		break;
		
		//Antigua in hut
		case "talk_dalma_hut4":
			dialog.text = DLG_TEXT[157];
			link.l1.go = "Exit";
			AddDialogExitQuest("At_Shack_Warning2_13");
		break;
		
		case "talk_shipwreck_dutchman":
			dialog.text = DLG_TEXT[158];
			link.l1 = DLG_TEXT[159];
			link.l1.go = "Exit";
			AddDialogExitQuest("dialogue_start_deck_shipwreck_3");
		break;
		
		case "talk_shipwreck_dutchman_2":
			dialog.text = DLG_TEXT[160];
			link.l1 = DLG_TEXT[161];
			link.l1.go = "talk_shipwreck_dutchman_3";
		break;
		
		case "talk_shipwreck_dutchman_3":
			dialog.text = DLG_TEXT[162];
			link.l1 = DLG_TEXT[163];
			link.l1.go = "Exit";
			AddDialogExitQuest("tp_deck_shipwreck");
		break;
		
		case "exitexecution":
			AddDialogExitQuest("Turner_and_me_in_trouble");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "exitTurner1":		
			SetCurrentTime(10, 0);					
			SetNextWeather("Blue Sky");		
			AddDialogExitQuest("Turner_and_me_take_ship");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "exitTurner2":
			AddPassenger(Pchar, characterFromID("Will Turner"), 0);
			AddDialogExitQuest("Dauntless_Deck_JACK");
//			LAi_ActorFollowEverywhere(characterFromID("Will Turner"), "", 60.0);			
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Will Turner"));
			DialogExit();
//			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "exitshipyard":
			AddDialogExitQuest("Turner_Swordfight");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "exitshipyard2":
			AddDialogExitQuest("In_the_Clink");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "exit talking on turks":	
			HoistFlag(PIRATE);
			SetRMRelation(PChar, PIRATE, REP_LEAVEMIN);		
			AddPassenger(Pchar, characterFromID("Will Turner"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Will Turner"));			
			AddDialogExitQuest("Turner_and_me_back to film");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
