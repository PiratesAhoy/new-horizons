//#include "DIALOGS\Bartholomew Roberts_dialog.h"
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
			
			dialog.snd = "Voice\ARSI\ARSI001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "Exit":
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "First_meeting_Greenford":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "First_meeting_Greenford2";
		break;

		case "First_meeting_Greenford2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit_First_meeting_Greenford";
		break;

		case "Exit_First_meeting_Greenford":
			AddDialogExitQuest("captain_Sawyer_arrives_Greenford");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Bush_Sawyer_Reply1":
			PlaySound("VOICE\ENGLISH\Bush02.wav");
			dialog.text = DLG_TEXT[43];
			link.l1.go = "Exit_Bush_Sawyer_Reply1";
		break;

		case "Exit_Bush_Sawyer_Reply1":
			AddDialogExitQuest("Sawyer_answer2");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Bush_Sawyer_Reply2":
			PlaySound("VOICE\ENGLISH\Bush03.wav");
			dialog.text = DLG_TEXT[44];
			link.l1.go = "Exit_Bush_Sawyer_Reply2";
		break;

		case "Exit_Bush_Sawyer_Reply2":
			AddDialogExitQuest("Sawyer_answer3");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "What_are_you_talking_about":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "What_are_you_talking_about2";
		break;

		case "What_are_you_talking_about2":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "More_than_a_breeze";
			link.l1.go = "Exit_What_are_you_talking_about";
		break;

		case "Exit_What_are_you_talking_about":
			AddDialogExitQuest("we_will_see_in_the_morning");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "More_than_a_breeze":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "More_than_a_breeze2";
		break;

		case "More_than_a_breeze2":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "Exit_More_than_a_breeze";
		break;

		case "Exit_More_than_a_breeze":
			AddDialogExitQuest("Go_get_Captain_Sawyer");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Captains_meeting":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "Exit_Captains_meeting";
		break;

		case "Exit_Captains_meeting":
			AddDialogExitQuest("Go_to_Captains_Meeting");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Mutiny_meeting":
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "Mutiny_meeting2";
		break;

		case "Mutiny_meeting2":
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "Exit_Mutiny_meeting";
		break;

		case "Exit_Mutiny_meeting":
			AddDialogExitQuest("Just_me_and_Archie");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "About_Sail_to_Cuba":
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Exit_About_Sail_to_Cuba";
		break;

		case "Exit_About_Sail_to_Cuba":
			AddDialogExitQuest("The_Doctor_Speaks");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "looks_like_surrender":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "looks_like_surrender2";
		break;

		case "looks_like_surrender2":
			dialog.text = DLG_TEXT[28] + GetMyName(PChar) + DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit_looks_like_surrender";
		break;

		case "Exit_looks_like_surrender":
			AddDialogExitQuest("Go_accept_surrender");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "somethings_not_right":
			dialog.text = DLG_TEXT[31] + GetMyName(PChar) + DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Exit_somethings_not_right";
		break;

		case "Exit_somethings_not_right":
			AddDialogExitQuest("Buckland_arrives_at_Fort");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "are_we_all_ready":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Exit_are_we_all_ready";
		break;

		case "Exit_are_we_all_ready":
			AddDialogExitQuest("set_the_charges4");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "We_are_not_alone":
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "We_are_not_alone2";
		break;

		case "We_are_not_alone2":
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "Exit_We_are_not_alone";
		break;

		case "Exit_We_are_not_alone":
			AddDialogExitQuest("Prepare_to_fire");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "light_the_fuse":
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "light_the_fuse2";
		break;

		case "light_the_fuse2":
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "light_the_fuse3";
		break;

		case "light_the_fuse3":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Exit_light_the_fuse";
		break;

		case "Exit_light_the_fuse":
			AddDialogExitQuest("Get_across_the_bridge");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "ready_for_the_bang":
			dialog.text = DLG_TEXT[36];
			link.l1.go = "Exit_ready_for_the_bang";
		break;

		case "Exit_ready_for_the_bang":
			AddDialogExitQuest("the_fort_goes_up");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "mission_accomplished":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "mission_accomplished2";
		break;

		case "mission_accomplished2":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Exit_mission_accomplished";
		break;

		case "Exit_mission_accomplished":
			AddDialogExitQuest("The_ship_has_been_captured");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "get_to_the_wheel":
			dialog.text = DLG_TEXT[9] + GetMyName(PChar) + DLG_TEXT[10];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Exit_get_to_the_wheel";
		break;

		case "Exit_get_to_the_wheel":
			AddDialogExitQuest("maindeck_clear2");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "I'm_wounded":
			dialog.text = DLG_TEXT[41] + GetMyName(PChar) + ".";
			link.l1 = DLG_TEXT[42];
			link.l1.go = "Exit_I'm_wounded";
		break;

		case "Exit_I'm_wounded":
//			AddDialogExitQuest("the_fort_goes_up");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Meet_at_Greenford":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "Meet_at_Greenford2";
		break;

		case "Meet_at_Greenford2":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Exit_Meet_at_Greenford";
		break;

		case "Exit_Meet_at_Greenford":
			AddDialogExitQuest("Bush_to_Mrs_Mason's");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Pay_in_advance":
			PlaySound("VOICE\ENGLISH\Bush04.wav");
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_Pay_in_advance";
		break;
		
		case "Exit_Pay_in_advance":
			AddDialogExitQuest("Mrs_Mason_reckons_up");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Maria_likes_you":
			PlaySound("VOICE\ENGLISH\Bush05.wav");
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "Maria_likes_you2";
		break;

		case "Maria_likes_you2":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "Maria_likes_you3";
		break;

		case "Maria_likes_you3":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "Exit_Maria_likes_you";
		break;

		case "Exit_Maria_likes_you":
			AddDialogExitQuest("Out_for_the_night");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "What_does_he_want":
			PlaySound("VOICE\ENGLISH\Bush06.wav");
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "Exit_What_does_he_want";
		break;

		case "Exit_What_does_he_want":
			AddDialogExitQuest("On_board_the_Flagship2");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "What_did_he_want":
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "What_did_he_want2";
		break;

		case "What_did_he_want2":
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "What_did_he_want3";
		break;

		case "What_did_he_want3":
			dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "What_did_he_want4";
		break;

		case "What_did_he_want4":
			dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[71];
			link.l1.go = "What_did_he_want5";
		break;

		case "What_did_he_want5":
			dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "What_did_he_want6";
		break;

		case "What_did_he_want6":
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "What_did_he_want7";
		break;

		case "What_did_he_want7":
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "What_did_he_want8";
		break;

		case "What_did_he_want8":
			dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79];
			link.l1.go = "Exit_What_did_he_want";
		break;

		case "Exit_What_did_he_want":
			AddDialogExitQuest("Bush_Joins_the_Hotspur");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Styles_needs_a_job":
			PlaySound("VOICE\ENGLISH\Bush07.wav");
			dialog.text = DLG_TEXT[80];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Styles_needs_a_job2";
		break;

		case "Styles_needs_a_job2":
			PlaySound("VOICE\ENGLISH\Bush08.wav");
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Exit_Styles_needs_a_job";
		break;

		case "Exit_Styles_needs_a_job":
			LAi_SetOfficerType(characterFromID("Thomas Wolfe"));
			LAi_SetActorType(characterFromID("Styles"));
			AddDialogExitQuest("And_now_Wolf");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Experience":
			PlaySound("VOICE\ENGLISH\Bush09.wav");
			dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Exit_Experience";
		break;

		case "Exit_Experience":
			AddDialogExitQuest("And_now_Wolf2");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Why_here":
			PlaySound("VOICE\ENGLISH\Bush10.wav");
			dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Exit_Why_here";
		break;

		case "Exit_Why_here":
			AddDialogExitQuest("And_now_Wolf3");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Sign_here_coxswain":
			PlaySound("VOICE\ENGLISH\Bush11.wav");
			dialog.text = DLG_TEXT[84];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Exit_Sign_here_coxswain";
		break;

		case "Exit_Sign_here_coxswain":
			LAi_SetActorType(characterFromID("Thomas Wolfe"));
			AddDialogExitQuest("Goodbye_to_Maria");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Mrs Mason's_to Pack":
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "Exit_Mrs Mason's_to Pack";
		break;

		case "Exit_Mrs Mason's_to Pack":
			AddDialogExitQuest("Goodbye_to_Maria2");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Going_to_sleep_onboard":
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "Going_to_sleep_onboard2";
		break;

		case "Going_to_sleep_onboard2":
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "Exit_Going_to_sleep_onboard";
		break;

		case "Exit_Going_to_sleep_onboard":
			LAi_SetActorType(characterFromID("Lt. William Bush"));
			LAi_SetOfficerType(characterFromID("Maria Mason"));
			AddDialogExitQuest("Maria_I_have_a_ship");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "What_was_that_all_about":
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "What_was_that_all_about2";
		break;

		case "What_was_that_all_about2":
			dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "What_was_that_all_about3";
		break;

		case "What_was_that_all_about3":
			dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];
			link.l1.go = "Exit_What_was_that_all_about";
		break;

		case "Exit_What_was_that_all_about":
			AddDialogExitQuest("find_the_95th");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Is_this_wise_sir":
			dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "Exit_Is_this_wise_sir";
		break;

		case "Exit_Is_this_wise_sir":
			AddDialogExitQuest("Bush_and_me_get_some_sleep");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "The_Hogan_ship_is_ready":
			dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[100];
			link.l1.go = "Exit_The_Hogan_ship_is_ready";
		break;

		case "Exit_The_Hogan_ship_is_ready":
			AddDialogExitQuest("Meet_Teresa_on_dock");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Beach_orders_Hogan":
			dialog.text = DLG_TEXT[101];
			link.l1 = DLG_TEXT[102];
			link.l1.go = "Beach_orders_Hogan2";
		break;

		case "Beach_orders_Hogan2":
			dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[103] + DLG_TEXT[104];
			link.l1.go = "Exit_Beach_orders_Hogan";
		break;

		case "Exit_Beach_orders_Hogan":
			AddDialogExitQuest("Hogan_Step_one");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Thank_God_you're_back":
			dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[106];
			link.l1.go = "Thank_God_you're_back2";
		break;

		case "Thank_God_you're_back2":
			dialog.text = DLG_TEXT[107];
			link.l1 = DLG_TEXT[108];
			link.l1.go = "Exit_Thank_God_you're_back";
		break;

		case "Exit_Thank_God_you're_back":
			AddDialogExitQuest("Pellew_at_Greenford_Two");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Not_more_whist":
			dialog.text = DLG_TEXT[109];
			link.l1 = DLG_TEXT[110];
			link.l1.go = "Not_more_whist2";
		break;

		case "Not_more_whist2":
			dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[112];
			link.l1.go = "Exit_Not_more_whist";
		break;

		case "Exit_Not_more_whist":
			AddDialogExitQuest("Pellew_Hammond_Plan");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Wolfe_is_back_sir":
			dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[114];
			link.l1.go = "Wolfe_is_back_sir2";
		break;

		case "Wolfe_is_back_sir2":
			LAi_ActorRunToLocator(characterFromID("Thomas Wolfe"), "reload", "reload1", "",0.0);
			dialog.text = DLG_TEXT[115];
			link.l1 = DLG_TEXT[116];
			link.l1.go = "Wolfe_is_back_sir3";
		break;

		case "Wolfe_is_back_sir3":
			dialog.text = DLG_TEXT[117];
			link.l1 = DLG_TEXT[118];
			link.l1.go = "Exit_Wolfe_is_back_sir";
		break;

		case "Exit_Wolfe_is_back_sir":
			AddDialogExitQuest("Sail_to_blow_Semaphore");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Maybe_share_a_boat":
			dialog.text = DLG_TEXT[119];
			link.l1 = DLG_TEXT[120];
			link.l1.go = "Exit_Maybe_share_a_boat";
		break;

		case "Exit_Maybe_share_a_boat":
			AddDialogExitQuest("Missed_them_Hammond_Quelp");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Standby_for_action":
			PlaySound("VOICE\ENGLISH\Bush12.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[121];
			link.l1.go = "Standby_for_action2";
		break;

		case "Standby_for_action2":
			PlaySound("VOICE\ENGLISH\Bush13.wav");
			dialog.text = DLG_TEXT[122];
			link.l1 = DLG_TEXT[123];
			link.l1.go = "Standby_for_action3";
		break;

		case "Standby_for_action3":
			PlaySound("VOICE\ENGLISH\Bush14.wav");
			dialog.text = DLG_TEXT[124];
			link.l1 = DLG_TEXT[125];
			link.l1.go = "Standby_for_action4";
		break;

		case "Standby_for_action4":
			PlaySound("VOICE\ENGLISH\Bush15.wav");
			dialog.text = DLG_TEXT[126];
//			link.l1 = DLG_TEXT[121];
			link.l1.go = "Exit_Standby_for_action";
		break;

		case "Exit_Standby_for_action":
			AddDialogExitQuest("Interupt_for_Hotspur3");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Line_astern":
			PlaySound("VOICE\ENGLISH\Bush20.wav");
			dialog.text = DLG_TEXT[127];
			link.l1 = DLG_TEXT[128];
			link.l1.go = "Exit_Line_astern";
		break;

		case "Exit_Line_astern":
			AddDialogExitQuest("Interupt_for_Hotspur6");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Dont_like_look":
			dialog.text = DLG_TEXT[129];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Dont_like_look2";
		break;

		case "Dont_like_look2":
			PlaySound("VOICE\ENGLISH\Bush16.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[130];
			link.l1.go = "Dont_like_look2A";
		break;

		case "Dont_like_look2A":
			PlaySound("VOICE\ENGLISH\Bush17.wav");
			dialog.text = DLG_TEXT[131];
//			link.l1 = DLG_TEXT[130];
			link.l1.go = "Exit_Dont_like_look";
		break;

		case "Exit_Dont_like_look":
			AddDialogExitQuest("Interupt_for_Hotspur8");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Line_astern":
			AddDialogExitQuest("Interupt_for_Hotspur6");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Bring_her_inshore":
			PlaySound("VOICE\ENGLISH\Bush18.wav");
			dialog.text = DLG_TEXT[132];
			link.l1 = DLG_TEXT[133];
			link.l1.go = "Bring_her_inshore2";
		break;

		case "Bring_her_inshore2":
			PlaySound("VOICE\ENGLISH\Bush19.wav");
			dialog.text = DLG_TEXT[134];
			link.l1 = DLG_TEXT[135];
			link.l1.go = "Exit_Bring_her_inshore";
		break;

		case "Exit_Bring_her_inshore":
			AddDialogExitQuest("Hotspur_underfire9");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "We_did_our_bit":
			dialog.text = DLG_TEXT[136];
			link.l1 = DLG_TEXT[137];
			link.l1.go = "We_did_our_bit2";
		break;

		case "We_did_our_bit2":
			dialog.text = DLG_TEXT[138];
			link.l1 = DLG_TEXT[139];
			link.l1.go = "Exit_We_did_our_bit";
		break;

		case "Exit_We_did_our_bit":
			AddDialogExitQuest("After_the_fort_and_Hammond");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "marriage_congrats":
			dialog.text = DLG_TEXT[144];
			link.l1 = DLG_TEXT[145];
			link.l1.go = "Exit";
		break;

		case "wolfe_prison":
			dialog.text = DLG_TEXT[140];
			link.l1 = DLG_TEXT[141];
			link.l1.go = "met_sharpe_too";
		break;

		case "met_sharpe_too":
			dialog.text = DLG_TEXT[142];
			link.l1 = DLG_TEXT[143];
			link.l1.go = "wolfe_prison_exit";
		break;

		case "wolfe_prison_exit":
			AddDialogExitQuest("wolfe_locked_up");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "A rum lot":
			dialog.text = DLG_TEXT[146];
			link.l1 = DLG_TEXT[147];
			link.l1.go = "Odd allies";
		break;

		case "Odd allies":
			dialog.text = DLG_TEXT[148];
			link.l1 = GetMyFullName(CharacterFromID("El Supremo")) + DLG_TEXT[149];
			link.l1.go = "Arms for him";
		break;

		case "Arms for him":
			dialog.text = DLG_TEXT[150];
			link.l1 = DLG_TEXT[151] + GetAttribute(CharacterFromID("El Supremo"), "title") + " " + GetMyName(CharacterFromID("El Supremo")) + DLG_TEXT[152];
			link.l1.go = "exit";
		break;

		case "If not back":
			dialog.text = "";
			link.l1 = DLG_TEXT[153];
			link.l1.go = "On our side";
		break;

		case "On our side":
			dialog.text = DLG_TEXT[154];
			link.l1 = DLG_TEXT[155];
			link.l1.go = "exit";
		break;

		case "Provisions and cargo":
			dialog.text = "";
			link.l1 = DLG_TEXT[156];
			link.l1.go = "Send lookout for Natividad";
		break;

		case "Send lookout for Natividad":
			dialog.text = DLG_TEXT[157];
			link.l1 = DLG_TEXT[158];
			link.l1.go = "Send lookout for Natividad2";
		break;

		case "Send lookout for Natividad2":
			dialog.text = DLG_TEXT[157];
			link.l1 = "";
			AddDialogExitQuest("Hornblower_exchange_weapons_for_supplies");
			link.l1.go = "exit";
		break;

		case "Natividad sighted":
			dialog.text = DLG_TEXT[159];
			link.l1 = DLG_TEXT[160];
			link.l1.go = "Natividad sighted2";
		break;

		case "Natividad sighted2":
			dialog.text = DLG_TEXT[161];
			link.l1 = "";
			link.l1.go = "Natividad sighted3";
		break;

		case "Natividad sighted3":
			dialog.text = DLG_TEXT[162];
			link.l1 = DLG_TEXT[163];
			link.l1.go = "Natividad sighted4";
		break;

		case "Natividad sighted4":
			dialog.text = DLG_TEXT[164];
			link.l1 = DLG_TEXT[165];
			link.l1.go = "Natividad sighted5";
		break;

		case "Natividad sighted5":
			dialog.text = DLG_TEXT[157];
			link.l1 = DLG_TEXT[166];
			link.l1.go = "Natividad sighted6";
		break;

		case "Natividad sighted6":
			dialog.text = DLG_TEXT[167];
			link.l1 = DLG_TEXT[168];
			link.l1.go = "Natividad sighted7";
		break;

		case "Natividad sighted7":
			dialog.text = DLG_TEXT[157];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "Natividad gamble":
			dialog.text = "";
			link.l1 = DLG_TEXT[169];
			link.l1.go = "Natividad gamble2";
		break;

		case "Natividad gamble2":
			dialog.text = "";
			link.l1 = DLG_TEXT[170];
			AddDialogExitQuest("Hornblower_Natividad_plan");
			link.l1.go = "exit";
		break;

		case "put_them_in_irons":
			dialog.text = "";
			link.l1 = DLG_TEXT[171] + PChar.ship.name + DLG_TEXT[172];
			link.l1.go = "exit";
		break;

		case "shes_a_beauty":
			dialog.text = DLG_TEXT[173] + PChar.quest.oldship.name + DLG_TEXT[174];
			link.l1 = DLG_TEXT[175];
			link.l1.go = "wot_no_prize";
		break;

		case "wot_no_prize":
			dialog.text = DLG_TEXT[176];
			link.l1 = DLG_TEXT[177];
			link.l1.go = "your_share_worth_loads";
		break;

		case "your_share_worth_loads":
			dialog.text = DLG_TEXT[178];
			link.l1 = DLG_TEXT[179];
			link.l1.go = "you_said_hes_mad";
		break;

		case "you_said_hes_mad":
			dialog.text = DLG_TEXT[180];
			link.l1 = DLG_TEXT[181];
			AddDialogExitQuest("Hornblower_Natividad_handover");
			link.l1.go = "exit";
		break;

		case "El_Supremo_boarding":
			dialog.text = DLG_TEXT[182];
			link.l1 = DLG_TEXT[183];
			link.l1.go = "fire_salute";
		break;

		case "fire_salute":
			dialog.text = DLG_TEXT[184];
			link.l1.go = "";
			AddDialogExitQuest("Hornblower_11_gun_salute");
			link.l1.go = "exit";
		break;

		case "return_to_ship":
			dialog.text = "";
			link.l1 = DLG_TEXT[185] +"'" + PChar.quest.oldship.name + "'";
			link.l1.go = "exit";
		break;

		case "lugger_report":
			dialog.text = "";
			link.l1 = DLG_TEXT[186];
			link.l1.go = "lugger_report2";
		break;

		case "lugger_report2":
			dialog.text = DLG_TEXT[187];
			link.l1 = DLG_TEXT[188];
			link.l1.go = "Aye-aye_sir";
		break;

		case "Bring the prisoners":
			dialog.text = "";
			link.l1 = DLG_TEXT[189];
			link.l1.go = "exit_fetch_prisoners";
		break;

		case "exit_fetch_prisoners":
			dialog.text = DLG_TEXT[157];
			link.l1 = "";
			link.l1.go = "exit";
			AddDialogExitQuest("Hornblower_Bush_to_get_prisoners2");
			link.l1.go = "exit";
		break;

		case "still_ship_of_war":
			dialog.text = "";
			link.l1 = DLG_TEXT[190];
			link.l1.go = "exit";
		break;

		case "Aye-aye_sir":
			dialog.text = DLG_TEXT[157];
			link.l1 = "";
			link.l1.go = "exit";
		break;
	}
}

