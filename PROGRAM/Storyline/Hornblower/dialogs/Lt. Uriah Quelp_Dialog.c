//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode; //"First time";
//			NPChar.quest.meeting = NPC_Meeting;
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

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "First_meeting_Greenford":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9] + GetMySimpleName(PChar) + DLG_TEXT[10];
			link.l1.go = "First_meeting_Greenford2";
		break;

		case "First_meeting_Greenford2":
			dialog.text = DLG_TEXT[11] + Pchar.lastname + DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "First_meeting_Greenford3";
		break;

		case "First_meeting_Greenford3":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Exit_First_meeting_Greenford";
		break;

		case "Exit_First_meeting_Greenford":
			AddDialogExitQuest("And_now_meet_Bracegirdle");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "We_should_attack":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit_We_should_attack";
		break;

		case "Exit_We_should_attack":
			AddDialogExitQuest("Pellew_stands_firm");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "reason_for_killing":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit_reason_for_killing";
		break;

		case "Exit_reason_for_killing":
			AddDialogExitQuest("Sharpe_makes_statement");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Quelp_and_Pellew":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_Quelp_and_Pellew";
		break;

		case "Exit_Quelp_and_Pellew":
			AddDialogExitQuest("Quelp_and_soldier_to_house");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "released_from_prison":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "released_from_prison2";
		break;

		case "released_from_prison2":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_released_from_prison";
		break;

		case "Exit_released_from_prison":
			AddDialogExitQuest("go_join_spanish_troops3");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "situation_report":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "situation_report2";
		break;

		case "situation_report2":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "situation_report3";
		break;

		case "situation_report3":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "situation_report4";
		break;

		case "situation_report4":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "situation_report5";
		break;

		case "situation_report5":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Exit_situation_report";
		break;

		case "Exit_situation_report":
			AddDialogExitQuest("Buckland_on_deck");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "not_in_a_Good_Mood":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "not_in_a_Good_Mood2";
		break;

		case "not_in_a_Good_Mood2":
			dialog.text = DLG_TEXT[0] + DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "not_in_a_Good_Mood3";
		break;

		case "not_in_a_Good_Mood3":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Exit_not_in_a_Good_Mood";
		break;

		case "Exit_not_in_a_Good_Mood":
			AddDialogExitQuest("Sharpe_makes_an_observation");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Get_things_sorted":
			dialog.text = DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "Get_things_sorted2";
		break;

		case "Get_things_sorted2":
			dialog.text = DLG_TEXT[75];
			link.l1 = DLG_TEXT[76];
			link.l1.go = "Get_things_sorted3";
		break;

		case "Get_things_sorted3":
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "Get_things_sorted4";
		break;

		case "Get_things_sorted4":
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "Get_things_sorted5";
		break;

		case "Get_things_sorted5":
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "Exit_Get_things_sorted";
		break;

		case "Exit_Get_things_sorted":
			AddDialogExitQuest("Put_Sharpe_at_ease");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "burial_completed":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "Exit_burial_completed";
		break;

		case "Exit_burial_completed":
			AddDialogExitQuest("Burials_over_now_Redmond");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "An_interesting_find":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "An_interesting_find2";
		break;

		case "An_interesting_find2":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "An_interesting_find3";
		break;

		case "An_interesting_find3":
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Exit_An_interesting_find";
		break;

		case "Exit_An_interesting_find":
			AddDialogExitQuest("Sharpe_asks_questiions");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "We_should_move_on":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "We_should_move_on2";
		break;

		case "We_should_move_on2":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "Exit_We_should_move_on";
		break;

		case "Exit_We_should_move_on":
			AddDialogExitQuest("Harper_and_the_miner");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "There's_nothing_here":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "There's_nothing_here2";
		break;

		case "There's_nothing_here2":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "Exit_There's_nothing_here";
		break;

		case "Exit_There's_nothing_here":
			AddDialogExitQuest("a_group_discussion");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "The_trick_exposed":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "The_trick_exposed2";
		break;

		case "The_trick_exposed2":
			ChangeCharacterAddressGroup(characterFromID("Rifleman Tongue"), "Antigua_shore", "reload", "reload2_back");
			ChangeCharacterAddressGroup(characterFromID("Patrick Harper"), "Antigua_shore", "reload", "reload2_back");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Haggman"), "Antigua_shore", "reload", "reload2_back");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Harris"), "Antigua_shore", "reload", "reload2_back");
			ChangeCharacterAddressGroup(characterFromID("Rifleman Mansfield"), "Antigua_shore", "reload", "reload2_back");
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "The_trick_exposed3";
		break;

		case "The_trick_exposed3":
			LAi_SetOfficerType(characterFromID("Rifleman Tongue"));
			LAi_SetOfficerType(characterFromID("Patrick Harper"));
			LAi_SetOfficerType(characterFromID("Rifleman Haggman"));
			LAi_SetOfficerType(characterFromID("Rifleman Harris"));
			LAi_SetOfficerType(characterFromID("Rifleman Mansfield"));
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "The_trick_exposed4";
		break;

		case "The_trick_exposed4":
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "The_trick_exposed5";
		break;

		case "The_trick_exposed5":
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[62]; //[60];
			link.l1.go = "Exit_The_trick_exposed";
		break;

//		case "The_trick_exposed6":
//			dialog.text = DLG_TEXT[61];
//			link.l1 = DLG_TEXT[62];
//			link.l1.go = "Exit_The_trick_exposed";
//		break;
		case "A_different_plan":
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "A_different_plan2";
		break;

		case "A_different_plan2":
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "A_different_plan3";
		break;

		case "A_different_plan3":
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[71];
			link.l1.go = "A_different_plan4";
		break;

		case "A_different_plan4":
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "Exit_A_different_plan";
		break;

		case "Exit_A_different_plan":
			AddDialogExitQuest("Sharpe_has_a_ruse");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;
		case "Exit_The_trick_exposed":
			AddDialogExitQuest("a_group_discussion3");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exposed_and_death":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "Exposed_and_death2";
		break;

		case "Exposed_and_death2":
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "Exposed_and_death3";
		break;

		case "Exposed_and_death3":
			dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "Exposed_and_death4";
		break;

		case "Exposed_and_death4":
			dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit_Exposed_and_death";
		break;

		case "Exit_Exposed_and_death":
			AddDialogExitQuest("Sharpe_is_killed");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "The_Final_Explanation":
			dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "The_Final_Explanation2";
		break;

		case "The_Final_Explanation2":
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "The_Final_Explanation3";
		break;

		case "The_Final_Explanation3":
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "The_Final_Explanation4";
		break;

		case "The_Final_Explanation4":
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "The_Final_Explanation5";
		break;

		case "The_Final_Explanation5":
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "The_Final_Explanation6";
		break;

		case "The_Final_Explanation6":
			dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "The_Final_Explanation7";
		break;

		case "The_Final_Explanation7":
			dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];
			link.l1.go = "Exit_The_Final_Explanation";
		break;

		case "Exit_The_Final_Explanation":
			AddDialogExitQuest("Attack_the_Midshipman");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "It_was_Hunter":
			dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "Exit_It_was_Hunter";
		break;

		case "Exit_It_was_Hunter":
			AddDialogExitQuest("The_French_Dead_Lighthouse2");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Quelp_on_the_dock":
			dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[100];
			link.l1.go = "Quelp_on_the_dock2";
		break;

		case "Quelp_on_the_dock2":
			dialog.text = DLG_TEXT[101];
			link.l1 = DLG_TEXT[102];
			link.l1.go = "Exit_Quelp_on_the_dock";
		break;

		case "Exit_Quelp_on_the_dock":
			AddDialogExitQuest("Bush_First_Lieutenant");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Quelp_will_leave_now":
			dialog.text = DLG_TEXT[103];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Quelp_will_leave_now2";
		break;

		case "Quelp_will_leave_now2":
			dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];
			link.l1.go = "Quelp_will_leave_now3";
		break;

		case "Quelp_will_leave_now3":
			LAi_SetActorType(characterFromID("Thomas Wolfe"));
			dialog.text = DLG_TEXT[106];
			link.l1 = DLG_TEXT[107];
			link.l1.go = "Quelp_will_leave_now4";
		break;

		case "Quelp_will_leave_now4":
			LAi_ActorGoToLocation(characterFromID("Thomas Wolfe"), "reload", "sea", "none", "", "", "",0.0);
			dialog.text = DLG_TEXT[108];
			link.l1 = DLG_TEXT[109];
			link.l1.go = "Exit_Quelp_will_leave_now";
		break;
 
		case "Exit_Quelp_will_leave_now":
			LAi_SetActorType(characterFromID("Lt. Uriah Quelp"));
			AddDialogExitQuest("Bush_gets_suspicious");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "showdown1":
			dialog.text = DLG_TEXT[110];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "showdown2";
		break;

		case "showdown2":
			dialog.text = DLG_TEXT[112];
			link.l1 = DLG_TEXT[113];
			link.l1.go = "showdown3";
		break;

		case "showdown3":
			dialog.text = DLG_TEXT[114];
			link.l1 = DLG_TEXT[115];
			link.l1.go = "exit";
			AddDialogExitQuest("kill_wolfe");
		break;

		case "Quelps_plot":
			dialog.text = DLG_TEXT[116];
			link.l1 = DLG_TEXT[117];
			link.l1.go = "plot2";
		break;

		case "plot2":
			dialog.text = DLG_TEXT[118];
			link.l1 = DLG_TEXT[119];
			link.l1.go = "plot3";
		break;

		case "plot3":
			dialog.text = DLG_TEXT[120];
			link.l1 = DLG_TEXT[121];
			link.l1.go = "plot4";
		break;

		case "plot4":
			dialog.text = DLG_TEXT[122];
			link.l1 = DLG_TEXT[123];
			link.l1.go = "plot5";
		break;

		case "plot5":
			dialog.text = DLG_TEXT[124];
			link.l1 = DLG_TEXT[125];
			link.l1.go = "plot6";
		break;

		case "plot6":
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[127];
			link.l1.go = "plot7";
		break;

		case "plot7":
			dialog.text = DLG_TEXT[128];
			link.l1 = DLG_TEXT[129];
			link.l1.go = "exit";
			AddDialogExitQuest("Sharpe_knows_theyre_French");
		break;
	}
}
