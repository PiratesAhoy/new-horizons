
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];

	switch(Dialog.CurrentNode)
	{
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			PlaySound("VOICE\ENGLISH\Pellew01.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "interupt fight":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "First_orders2";
		break;

		case "First_orders2":
			PlaySound("VOICE\ENGLISH\Pellew01.wav");
			dialog.text = DLG_TEXT[4] + pchar.lastname + DLG_TEXT[43];
			link.l1 = DLG_TEXT[5] + GetMySimpleName(PChar) + DLG_TEXT[44];
			link.l1.go = "First_orders3";
		break;

		case "First_orders3":
			dialog.text = DLG_TEXT[6] + pchar.lastname + DLG_TEXT[45] + pchar.lastname + DLG_TEXT[54];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_First_orders";
		break;

		case "got_to_Charlestown":
			PlaySound("VOICE\ENGLISH\Pellew01.wav");
			dialog.text = DLG_TEXT[8] + pchar.lastname + DLG_TEXT[46];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "ExitCharlestown1";
		break;

		case "youre_a_deserter":
			dialog.text = DLG_TEXT[52] + pchar.lastname + DLG_TEXT[53];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit_Deserter";
		break;

		case "message of war":
			PlaySound("VOICE\ENGLISH\Pellew01.wav");
			dialog.text = DLG_TEXT[9] + pchar.lastname;
			link.l1 = DLG_TEXT[1];
			link.l1.go = "message of war2";
		break;

		case "message of war2":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "message of war3";
		break;

		case "message of war3":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "message of war4";
		break;

		case "message of war4":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "message of war5";
		break;

		case "message of war5":
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "message of war6";
		break;

		case "message of war6":
			AddDialogExitQuest("At_War_with_France_Again");
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "Go_to_the_Naval_Academy":
			PlaySound("VOICE\ENGLISH\Pellew01.wav");
			dialog.text = DLG_TEXT[10] + Pchar.lastname + ".";
			link.l1 = DLG_TEXT[11];
			link.l1.go = "and now Oxbay2";
		break;

		case "and now Oxbay2":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "and now Oxbay3";
		break;

		case "and now Oxbay3":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "got_to_Oxbay_for_refit";
		break;

		case "got_to_Oxbay_for_refit":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "got_to_Oxbay_for_refit2";
		break;

		case "got_to_Oxbay_for_refit2":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "got_to_Oxbay_for_refit3";
		break;

		case "got_to_Oxbay_for_refit3":
			dialog.text = DLG_TEXT[26] + Pchar.lastname + ".";
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit_Oxbay_for_refit";
		break;

		case "get on with it man":
			dialog.text = DLG_TEXT[27] + pchar.lastname + DLG_TEXT[48];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "Exit_back to Port";
		break;

		case "report on the attack":
			dialog.text = DLG_TEXT[29] + pchar.lastname + DLG_TEXT[49];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit_report_on_the_attack";
		break;

		case "first_promotion":
			dialog.text = DLG_TEXT[31] + pchar.lastname + DLG_TEXT[50];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "first_promotion2";
		break;

		case "first_promotion2":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exitfirst_promotion";
		break;

		case "explanation":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "explanation2";
		break;

		case "explanation2":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "explanation3";
		break;

		case "explanation3":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "explanation4";
		break;

		case "explanation4":
			dialog.text = DLG_TEXT[39] + pchar.lastname + DLG_TEXT[51];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "explanation5";
		break;

		case "explanation5":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "explanation6";
		break;

		case "explanation6":
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "explanation7";
		break;

		case "explanation7":
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exitexplanation";
		break;

		case "Le_Reve_is_captured":
			dialog.text = Pchar.lastname + DLG_TEXT[70];
			link.l1 = DLG_TEXT[71];
			link.l1.go = "Le_Reve_is_captured2";
		break;

		case "Le_Reve_is_captured2":
			dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "Le_Reve_is_captured3";
		break;

		case "Le_Reve_is_captured3":
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit_Le_Reve_is_captured";
		break;

		case "Exit_Le_Reve_is_captured":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Quelp_cuts_in");
		break;

		case "Waiting_for_wellesley":
			dialog.text = DLG_TEXT[75];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit_Waiting_for_wellesley";
		break;

		case "Exit_Waiting_for_wellesley":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Soldier_speaks_up_on_tunnel");
		break;

		case "Pellew_and_Tunnel":
			dialog.text = DLG_TEXT[76] + Pchar.lastname + DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "Pellew_and_Tunnel2";
		break;

		case "Pellew_and_Tunnel2":
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "Exit_Pellew_and_Tunnel";
		break;

		case "Exit_Pellew_and_Tunnel":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Wellesley_cuts_in");
		break;

		case "Wellesley_and_Tunnel":
			dialog.text = DLG_TEXT[81] + Pchar.lastname + DLG_TEXT[82] + Pchar.lastname + DLG_TEXT[83]  + Pchar.lastname + ".";
			link.l1 = DLG_TEXT[84];
			link.l1.go = "Exit_Wellesley_and_Tunnel";
		break;

		case "Exit_Wellesley_and_Tunnel":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Wellesley_Pellew_Quelp_to_town");
		break;

		case "Wellesley_to_Tavern":
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit_Wellesley_to_Tavern";
		break;

		case "Exit_Wellesley_to_Tavern":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Wellesley_Quelp_to_Tavern");
		break;

		case "Wellesley_gone_for_now":
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit_Wellesley_gone_for_now";
		break;

		case "Exit_Wellesley_gone_for_now":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Harper_adds_his_part");
		break;

		case "Pellews_suggestion":
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "Pellews_suggestion2";
		break;

		case "Pellews_suggestion2":
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "Pellews_suggestion3";
		break;

		case "Pellews_suggestion3":
			dialog.text = DLG_TEXT[91] + Pchar.lastname + DLG_TEXT[92];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_Pellews_suggestion";
		break;

		case "Exit_Pellews_suggestion":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Down_the_rabbit_hole");
		break;

		case "Pellew_in_Back_Room":
			dialog.text = Pchar.lastname + DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "Pellew_in_Back_Room2";
		break;

		case "Pellew_in_Back_Room2":
			dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];
			link.l1.go = "Exit_Pellew_in_Back_Room";
		break;

		case "Exit_Pellew_in_Back_Room":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Wellesley_and_Sharpe_to_Leave");
		break;

		case "More_Pellew_in_Back_Room":
			dialog.text = DLG_TEXT[97] + Pchar.lastname + DLG_TEXT[98];
			link.l1 = DLG_TEXT[99];
			link.l1.go = "More_Pellew_in_Back_Room2";
		break;

		case "More_Pellew_in_Back_Room2":
			dialog.text = DLG_TEXT[100];
			link.l1 = DLG_TEXT[101];
			link.l1.go = "More_Pellew_in_Back_Room3";
		break;

		case "More_Pellew_in_Back_Room3":
			dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "More_Pellew_in_Back_Room4";
		break;

		case "More_Pellew_in_Back_Room4":
			dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];
			link.l1.go = "More_Pellew_in_Back_Room5";
		break;

		case "More_Pellew_in_Back_Room5":
			dialog.text = DLG_TEXT[106];
			link.l1 = DLG_TEXT[107];
			link.l1.go = "More_Pellew_in_Back_Room6";
		break;

		case "More_Pellew_in_Back_Room6":
			dialog.text = DLG_TEXT[108] + Pchar.lastname + DLG_TEXT[109];
			link.l1 = DLG_TEXT[110];
			link.l1.go = "More_Pellew_in_Back_Room7";
		break;

		case "More_Pellew_in_Back_Room7":
			dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[112];
			link.l1.go = "More_Pellew_in_Back_Room8";
		break;

		case "More_Pellew_in_Back_Room8":
			dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[114];
			link.l1.go = "More_Pellew_in_Back_Room9";
		break;

		case "More_Pellew_in_Back_Room9":
			dialog.text = DLG_TEXT[115];
			link.l1 = DLG_TEXT[116];
			link.l1.go = "More_Pellew_in_Back_Room10";
		break;

		case "More_Pellew_in_Back_Room10":
			dialog.text = DLG_TEXT[117];
			link.l1 = DLG_TEXT[118];
			link.l1.go = "More_Pellew_in_Back_Room11";
		break;

		case "More_Pellew_in_Back_Room11":
			dialog.text = DLG_TEXT[119] + Pchar.lastname + ".";
			link.l1 = DLG_TEXT[120];
			link.l1.go = "More_Pellew_in_Back_Room12";
		break;

		case "More_Pellew_in_Back_Room12":
			dialog.text = DLG_TEXT[121] + Pchar.lastname + ".";
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_More_Pellew_in_Back_Room";
		break;

		case "Exit_More_Pellew_in_Back_Room":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Academy_for_Quelp");
		break;

		case "No_Academy_Back_Room":
			dialog.text = Pchar.lastname + DLG_TEXT[122];
			link.l1 = DLG_TEXT[123];
			link.l1.go = "No_Academy_Back_Room2";
		break;

		case "No_Academy_Back_Room2":
			dialog.text = DLG_TEXT[124];
			link.l1 = DLG_TEXT[125];
			link.l1.go = "No_Academy_Back_Room3";
		break;

		case "No_Academy_Back_Room3":
			dialog.text = DLG_TEXT[126] + Pchar.lastname + DLG_TEXT[127];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_No_Academy_Back_Room";
		break;

		case "Exit_No_Academy_Back_Room":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Find_the_Academy_Entrance");
		break;

		case "Pellew_in_Back_Room_THIRD":
			dialog.text = Pchar.lastname + DLG_TEXT[128];
			link.l1 = DLG_TEXT[129];
			link.l1.go = "Pellew_in_Back_Room_THIRD2";
		break;

		case "Pellew_in_Back_Room_THIRD2":
			dialog.text = DLG_TEXT[130];
			link.l1 = DLG_TEXT[131];
			link.l1.go = "Exit_Pellew_in_Back_Room_THIRD";
		break;

		case "Exit_Pellew_in_Back_Room_THIRD":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Wellesley_and_Sharpe_to_Leave");
		break;

		case "Talk_to_Quelp_and_Buckland":
			dialog.text = DLG_TEXT[132] + Pchar.lastname + "?";
			link.l1 = DLG_TEXT[133];
			link.l1.go = "Talk_to_Quelp_and_Buckland2";
		break;

		case "Talk_to_Quelp_and_Buckland2":
			AddDialogExitQuest("Quelp_and_Soldier_to_Leave");
			dialog.text = DLG_TEXT[134];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit";
		break;

		case "Confirm_the_Quelp_plan":
			dialog.text = DLG_TEXT[135];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_Confirm_the_Quelp_plan";
		break;

		case "Exit_Confirm_the_Quelp_plan":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Hornblower_and_Soldier_Leave");
		break;

		case "Final_French_Quelp_plan":
			AddDialogExitQuest("Hornblower_and_Wellesley_To_House");
			dialog.text = DLG_TEXT[136];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit";
		break;

		case "outside_the_gates":
			PlaySound("VOICE\ENGLISH\Pellew04.wav");
			dialog.text = DLG_TEXT[151] + Pchar.lastname + DLG_TEXT[167];
			link.l1 = DLG_TEXT[133];
			link.l1.go = "outside_the_gates2";
		break;

		case "outside_the_gates2":
			dialog.text = DLG_TEXT[168];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "outside_the_gates3";
		break;

		case "outside_the_gates3":
			dialog.text = DLG_TEXT[169];
			link.l1 = DLG_TEXT[170];
			link.l1.go = "outside_the_gates4";
		break;

		case "outside_the_gates4":
			dialog.text = DLG_TEXT[171];
			link.l1 = DLG_TEXT[172];
			link.l1.go = "outside_the_gates5";
		break;

		case "outside_the_gates5":
			dialog.text = DLG_TEXT[173];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_outside_the_gates";
		break;

		case "Exit_outside_the_gates":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Meet_again_Pellew3");
		break;

		case "Your_wet_Back_to_Ship":
			dialog.text = DLG_TEXT[174];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_Your_wet_Back_to_Ship";
		break;

		case "Exit_Your_wet_Back_to_Ship":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Congrats_on_Indy");
		break;

		case "Acts_of_heroism":
			PlaySound("VOICE\ENGLISH\Pellew05.wav");
			dialog.text = DLG_TEXT[175];
			link.l1 = DLG_TEXT[176];
			link.l1.go = "Acts_of_heroism2";
		break;

		case "Acts_of_heroism2":
			PlaySound("VOICE\ENGLISH\Pellew06.wav");
			dialog.text = DLG_TEXT[177];
			link.l1 = DLG_TEXT[178];
			link.l1.go = "Acts_of_heroism3";
		break;

		case "Acts_of_heroism3":
			PlaySound("VOICE\ENGLISH\Pellew07.wav");
			dialog.text = DLG_TEXT[179];
			link.l1 = DLG_TEXT[180];
			link.l1.go = "Acts_of_heroism4";
		break;

		case "Acts_of_heroism4":
			PlaySound("VOICE\ENGLISH\Pellew08.wav");
			dialog.text = DLG_TEXT[181];
			link.l1 = DLG_TEXT[182];
			link.l1.go = "Acts_of_heroism5";
		break;

		case "Acts_of_heroism5":
			PlaySound("VOICE\ENGLISH\Pellew09.wav");
			dialog.text = DLG_TEXT[183];
			link.l1.go = "Exit_Acts_of_heroism";
		break;

		case "Exit_Acts_of_heroism":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Get_ready_for_the_Duchess");
		break;

		case "An_excellent_dinner":
			dialog.text = DLG_TEXT[184];
			link.l1 = DLG_TEXT[178];
			link.l1.go = "Exit_An_excellent_dinner";
		break;

		case "Exit_An_excellent_dinner":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Discuss_the_MissionBBB");
		break;

		case "Here_are_the_documents":
			PlaySound("VOICE\ENGLISH\Pellew03.wav");
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "Here_are_the_documents2";
		break;

		case "Here_are_the_documents2":
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Here_are_the_documents3";
		break;

		case "Here_are_the_documents3":
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "Here_are_the_documents4";
		break;

		case "Here_are_the_documents4":
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "Here_are_the_documents5";
		break;

		case "Here_are_the_documents5":
			dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit_Here_are_the_documents";
		break;

		case "Exit_Here_are_the_documents":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("And_now_the_Duchess");
		break;

		case "With_Sharpe_to_Jamaica":
			dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "With_Sharpe_to_Jamaica2";
		break;

		case "With_Sharpe_to_Jamaica2":
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "Exit_With_Sharpe_to_Jamaica";
		break;

		case "Indy_after_escape":
			dialog.text = DLG_TEXT[137];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_Indy_after_escape";
		break;

		case "Exit_Indy_after_escape":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Duchess_Promotion_and_return");
		break;

		case "Duchess_rested":
			dialog.text = DLG_TEXT[138];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit_Duchess_rested";
		break;

		case "Exit_Duchess_rested":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Duchess_parrot_cage");
		break;

		case "Duchess_going_to_Jamaica":
			dialog.text = DLG_TEXT[139];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit_Duchess_going_to_Jamaica";
		break;

		case "Exit_Duchess_going_to_Jamaica":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Burdened_her_Grace");
		break;

		case "Document_return_shout":
			dialog.text = DLG_TEXT[140];
			link.l1 = DLG_TEXT[141];
			link.l1.go = "Document_return_shout2";
		break;

		case "Document_return_shout2":
			dialog.text = DLG_TEXT[142];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit_Document_return_shout";
		break;

		case "Exit_Document_return_shout":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Duchess_and_promotion");
		break;

		case "Promotion_for_Horatio":
			dialog.text = DLG_TEXT[143] + Pchar.lastname + DLG_TEXT[144];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Promotion_for_Horatio2";
		break;

		case "Promotion_for_Horatio2":
			dialog.text = DLG_TEXT[145] + Pchar.lastname + DLG_TEXT[146];
			link.l1 = DLG_TEXT[147];
			link.l1.go = "Promotion_for_Horatio3";
		break;

		case "Promotion_for_Horatio3":
			dialog.text = DLG_TEXT[148];
			link.l1 = DLG_TEXT[149];
			link.l1.go = "Promotion_for_Horatio4";
		break;

		case "Promotion_for_Horatio4":
			dialog.text = DLG_TEXT[150];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit_Promotion_for_Horatio";
		break;

		case "Exit_Promotion_for_Horatio":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Go_to_see_the_crew");
		break;

		case "Address_the_ships_crew":
			dialog.text = DLG_TEXT[151] + Pchar.lastname + DLG_TEXT[152];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Address_the_ships_crew2";
		break;

		case "Address_the_ships_crew2":
			dialog.text = DLG_TEXT[153];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit_Address_the_ships_crew";
		break;

		case "Exit_Address_the_ships_crew":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Archie_agrees_prison");
		break;

		case "Return_the_ships_crew":
			dialog.text = DLG_TEXT[154];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit_Return_the_ships_crew";
		break;

		case "Exit_Return_the_ships_crew":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("From_Indy_to_Prison2");
		break;

		case "Remember_the_crack_troops":
			dialog.text = DLG_TEXT[151] + Pchar.lastname + DLG_TEXT[155];
			link.l1 = DLG_TEXT[120];
			link.l1.go = "Remember_the_crack_troops2";
		break;

		case "Remember_the_crack_troops2":
			dialog.text = DLG_TEXT[156];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Remember_the_crack_troops3";
		break;

		case "Remember_the_crack_troops3":
			dialog.text = DLG_TEXT[157];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Remember_the_crack_troops4";
		break;

		case "Remember_the_crack_troops4":
			dialog.text = DLG_TEXT[158] + Pchar.lastname + ".";
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_Remember_the_crack_troops";
		break;

		case "Exit_Remember_the_crack_troops":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Repair_to_Jamaica");
		break;

		case "Plan_for_crack_troops":
			dialog.text = DLG_TEXT[159] + Pchar.lastname + DLG_TEXT[160] + GetMySimpleName(PChar);
			link.l1 = DLG_TEXT[161];
			link.l1.go = "Plan_for_crack_troops2";
		break;

		case "Plan_for_crack_troops2":
			dialog.text = DLG_TEXT[162];
			link.l1 = DLG_TEXT[163];
			link.l1.go = "Plan_for_crack_troops3";
		break;

		case "Plan_for_crack_troops3":
			PlaySound("VOICE\ENGLISH\Pellew02.wav");
			dialog.text = DLG_TEXT[164] + Pchar.lastname + DLG_TEXT[165];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit_Plan_for_crack_troops";
		break;

		case "Exit_Plan_for_crack_troops":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Wellesley_joins_Troops");
		break;

		case "Go_attack_crack_troops":
			dialog.text = Pchar.lastname + DLG_TEXT[166];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit_Go_attack_crack_troops";
		break;

		case "Exit_Go_attack_crack_troops":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Redmond_Sharpe_Chumley");
		break;

		case "ExitOxbay3":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Make_sail_for_Oxbay");
		break;

		case "Transferred_to_Sawyer":
			dialog.text = DLG_TEXT[159] + Pchar.lastname + DLG_TEXT[185];
			link.l1 = DLG_TEXT[186];
			link.l1.go = "Transferred_to_Sawyer2";
		break;

		case "Transferred_to_Sawyer2":
			dialog.text = DLG_TEXT[187];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_Transferred_to_Sawyer";
		break;

		case "Exit_Transferred_to_Sawyer":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Find_Kennedy_in_Tavern");
		break;

		case "Court_Martial_one":
			dialog.text = DLG_TEXT[188];
			link.l1 = DLG_TEXT[189];
			link.l1.go = "Exit_Court_Martial_one";
		break;

		case "Exit_Court_Martial_one":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("The_Court_Martial_Begins4");
		break;

		case "Court_Martial_three":
			dialog.text = DLG_TEXT[190];
			link.l1 = DLG_TEXT[191];
			link.l1.go = "Court_Martial_three2";
		break;

		case "Court_Martial_three2":
			dialog.text = DLG_TEXT[192];
			link.l1 = DLG_TEXT[178];
			link.l1.go = "Court_Martial_three3";
		break;

		case "Court_Martial_three3":
			dialog.text = DLG_TEXT[193];
			link.l1 = DLG_TEXT[178];
			link.l1.go = "Court_Martial_three4";
		break;

		case "Court_Martial_three4":
			dialog.text = DLG_TEXT[194];
			link.l1.go = "Exit_Court_Martial_three";
		break;

		case "Exit_Court_Martial_three":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("The_Court_Martial_Begins6");
		break;

		case "Court_Martial_five":
			dialog.text = DLG_TEXT[195];
			link.l1.go = "Exit_Court_Martial_five";
		break;

		case "Exit_Court_Martial_five":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Court_Martial_Over");
		break;

		case "You_have_been_cleared":
			dialog.text = DLG_TEXT[196];
			link.l1 = DLG_TEXT[197];
			link.l1.go = "You_have_been_cleared2";
		break;

		case "You_have_been_cleared2":
			dialog.text = DLG_TEXT[198];
			link.l1 = DLG_TEXT[199];
			link.l1.go = "You_have_been_cleared3";
		break;

		case "You_have_been_cleared3":
			dialog.text = DLG_TEXT[200];
			link.l1 = DLG_TEXT[201];
			link.l1.go = "You_have_been_cleared4";
		break;

		case "You_have_been_cleared4":
			dialog.text = DLG_TEXT[202];
			link.l1 = DLG_TEXT[178];
			link.l1.go = "You_have_been_cleared5";
		break;

		case "You_have_been_cleared5":
			dialog.text = DLG_TEXT[203];
			link.l1 = DLG_TEXT[204];
			link.l1.go = "You_have_been_cleared6";
		break;

		case "You_have_been_cleared6":
			dialog.text = DLG_TEXT[205];
			link.l1 = DLG_TEXT[180];
			link.l1.go = "Exit_You_have_been_cleared";
		break;

		case "Exit_You_have_been_cleared":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("A_new_Quest_Line");
		break;

		case "Card_Night":
			PlaySound("VOICE\ENGLISH\Pellew10.wav");
			dialog.text = DLG_TEXT[208];
			link.l1 = DLG_TEXT[209];
			link.l1.go = "Card_Night2";
		break;

		case "Card_Night2":
			PlaySound("VOICE\ENGLISH\Pellew11.wav");
			dialog.text = DLG_TEXT[210];
			link.l1 = DLG_TEXT[211];
			link.l1.go = "Card_Night3";
		break;

		case "Card_Night3":
			PlaySound("VOICE\ENGLISH\Pellew12.wav");
			dialog.text = DLG_TEXT[212];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit_Card_Night";
		break;

		case "Exit_Card_Night":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Hammond_and_Nephew");
		break;

		case "With_whom_would_you_serve":
			PlaySound("VOICE\ENGLISH\Pellew13.wav");
			dialog.text = DLG_TEXT[213];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit_With_whom_would_you_serve";
		break;

		case "Exit_With_whom_would_you_serve":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("I_choose_Hornblower");
		break;

		case "Lets_play_cards":
			PlaySound("VOICE\ENGLISH\Pellew14.wav");
			dialog.text = DLG_TEXT[214];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit_Lets_play_cards";
		break;

		case "Exit_Lets_play_cards":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("After_the_game");
		break;

		case "Card_Payout":
			PlaySound("VOICE\ENGLISH\Pellew15.wav");
			dialog.text = DLG_TEXT[215];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit_Card_Payout";
		break;

		case "Exit_Card_Payout":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("On_board_the_Flagship");
		break;

		case "Hows_your_head":
			PlaySound("VOICE\ENGLISH\Pellew16.wav");
			dialog.text = DLG_TEXT[216];
			link.l1 = DLG_TEXT[217];
			link.l1.go = "Hows_your_head2";
		break;

		case "Hows_your_head2":
			PlaySound("VOICE\ENGLISH\Pellew17.wav");
			dialog.text = DLG_TEXT[218];
			link.l1 = DLG_TEXT[219];
			link.l1.go = "Hows_your_head3";
		break;

		case "Hows_your_head3":
			PlaySound("VOICE\ENGLISH\Pellew18.wav");
			dialog.text = DLG_TEXT[220];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Hows_your_head4";
		break;

		case "Hows_your_head4":
			LAi_SetActorType(characterFromID("Arthur Wellesley"));
			LAi_ActorGoToLocator(characterfromID("Arthur Wellesley"), "rld", "aloc5", "", 0.0);
			dialog.text = DLG_TEXT[232];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit_Wellesley_on_Board";
		break

		case "Exit_Wellesley_on_Board":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Wellesley_and_Pellew_on_ship");
		break;

		case "Hows_your_headXXX":
			dialog.text = DLG_TEXT[221];
			link.l1 = DLG_TEXT[222];
			link.l1.go = "Hows_your_head5";
		break;

		case "Hows_your_head5":
			dialog.text = DLG_TEXT[223];
			link.l1 = DLG_TEXT[224];
			link.l1.go = "Hows_your_head6";
		break;

		case "Hows_your_head6":
			dialog.text = DLG_TEXT[225];
			link.l1 = DLG_TEXT[226];
			link.l1.go = "Hows_your_head7";
		break;

		case "Hows_your_head7":
			dialog.text = DLG_TEXT[227];
			link.l1 = DLG_TEXT[228];
			link.l1.go = "Exit_for_Wellesley_again";
		break;

		case "Exit_for_Wellesley_again":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Wellesley_in_detail");
		break;

		case "Hows_your_head8":
			dialog.text = DLG_TEXT[229];
			link.l1 = DLG_TEXT[230];
			link.l1.go = "Hows_your_head9";
		break;

		case "Hows_your_head9":
			AddDialogExitQuest("Orders_and_Ship3");
			PlaySound("VOICE\ENGLISH\Pellew19.wav");
			dialog.text = DLG_TEXT[231];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "Exit_First_orders":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Our First venture");
			AddQuestRecord("My First Ship", 2);
		break;

		case "ExitCharlestown1":
			AddMoneyToCharacter(pchar, +1000);
			pchar.quest.My_First_ship = "and now Charlestown";
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("reprovision_Charlestown");
			AddQuestRecord("My First Ship", 3);
		break;

		case "Exit_Oxbay_for_refit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Off_to_the_Academy_meeting");
		break;

		case "Exit_back to Port":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("reprovision_Charlestown4");
		break;

		case "Exit_report_on_the_attack":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("discussion continues");
		break;

		case "Exit_With_Sharpe_to_Jamaica":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Off_to_Jamaica_with_Sharpe");
		break;

		case "Exitfirst_promotion":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("ready_the_fight");
		break;

		case "Exitexplanation":
//			AddMoneyToCharacter(pchar, +240000);
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("prepare_for_French_siege");
		break;

		case "Exit_Deserter":
			TakeItemFromCharacter(Pchar,"blade1");
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Deserters Jail");
		break;

		case "You_are_to_be_shot":
			AddDialogExitQuest("hung at dawn");
			dialog.text = DLG_TEXT[207];
			link.l1.go = "Exit";
		break;

		case "I_have_read_your_report":
			dialog.text = DLG_TEXT[233];
			link.l1 = DLG_TEXT[234];
			link.l1.go = "I_have_read_your_report2";
		break;

		case "I_have_read_your_report2":
			AddDialogExitQuest("Hammond_chips_in");
			dialog.text = DLG_TEXT[235];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit";
		break;

		case "Indeed_continue":
			dialog.text = DLG_TEXT[236];
			link.l1 = DLG_TEXT[237];
			link.l1.go = "Indeed_continue2";
		break;

		case "Indeed_continue2":
			dialog.text = DLG_TEXT[238];
			link.l1 = DLG_TEXT[239];
			link.l1.go = "Indeed_continue3";
		break;

		case "Indeed_continue3":
			dialog.text = DLG_TEXT[240];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Indeed_continue4";
		break;

		case "Indeed_continue4":
			AddDialogExitQuest("Hammond_gets_gritty");
			PlaySound("VOICE\ENGLISH\Hornblwr03.wav");
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[241];
			link.l1.go = "Exit";
		break;

		case "Hammond_Hornblower_Plan":
			PlaySound("VOICE\ENGLISH\Pellew20.wav");
			dialog.text = DLG_TEXT[242];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Hammond_Hornblower_Plan2";
		break;

		case "Hammond_Hornblower_Plan2":
			PlaySound("VOICE\ENGLISH\Hornblwr04.wav");
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[243];
			link.l1.go = "Hammond_Hornblower_Plan3";
		break;

		case "Hammond_Hornblower_Plan3":
			AddDialogExitQuest("Jack_goes_too");
			PlaySound("VOICE\ENGLISH\Pellew21.wav");
			dialog.text = DLG_TEXT[244];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit";
		break;

		case "Hogan_and_Spies":
			AddDialogExitQuest("Shut_the_Door");
			dialog.text = DLG_TEXT[245];
			link.l1 = DLG_TEXT[246];
			link.l1.go = "Exit";
		break;

		case "Spies_somewhere":
			PlaySound("VOICE\ENGLISH\Hornblwr05.wav");
			dialog.text = DLG_TEXT[247];
			link.l1 = DLG_TEXT[248];
			link.l1.go = "Spies_somewhere2";
		break;

		case "Spies_somewhere2":
			AddDialogExitQuest("Maria_in_Jail");
			PlaySound("VOICE\ENGLISH\Pellew22.wav");
			dialog.text = DLG_TEXT[249];
			link.l1 = DLG_TEXT[250];
			link.l1.go = "Exit";
		break;

		case "Can_we_Help_Hornblower":
			PlaySound("VOICE\ENGLISH\Pellew23.wav");
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[251];
			link.l1.go = "Can_we_Help_Hornblower2";
		break;

		case "Can_we_Help_Hornblower2":
			PlaySound("VOICE\ENGLISH\Pellew24.wav");
			dialog.text = DLG_TEXT[252];
			link.l1 = DLG_TEXT[253];
			link.l1.go = "Can_we_Help_Hornblower3";
		break;

		case "Can_we_Help_Hornblower3":
			AddDialogExitQuest("Crew_Wolfe_Prison");
			PlaySound("VOICE\ENGLISH\Pellew25.wav");
			dialog.text = DLG_TEXT[254];
			link.l1 = DLG_TEXT[255];
			link.l1.go = "Exit";
		break;

		case "In_Your_Report":
			PlaySound("VOICE\ENGLISH\Pellew26.wav");
			dialog.text = DLG_TEXT[256];
			link.l1 = DLG_TEXT[178];
			link.l1.go = "In_Your_Report2";
		break;

		case "In_Your_Report2":
			PlaySound("VOICE\ENGLISH\Pellew27.wav");
			dialog.text = DLG_TEXT[257];
			link.l1 = DLG_TEXT[258];
			link.l1.go = "In_Your_Report3";
		break;

		case "In_Your_Report3":
			PlaySound("VOICE\ENGLISH\Pellew28.wav");
			dialog.text = DLG_TEXT[259];
			link.l1 = DLG_TEXT[260];
			link.l1.go = "In_Your_Report4";
		break;

		case "In_Your_Report4":
			PlaySound("VOICE\ENGLISH\Pellew29.wav");
			dialog.text = DLG_TEXT[261];
			link.l1 = DLG_TEXT[262];
			link.l1.go = "In_Your_Report5";
		break;

		case "In_Your_Report5":
			PlaySound("VOICE\ENGLISH\Pellew30.wav");
			dialog.text = DLG_TEXT[263];
			link.l1 = DLG_TEXT[264];
			link.l1.go = "In_Your_Report6";
		break;

		case "In_Your_Report6":
			AddDialogExitQuest("Propose_to_Maria");
			PlaySound("VOICE\ENGLISH\Pellew31.wav");
			dialog.text = DLG_TEXT[265];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Exit";
		break;

		case "Give_atropos":
			PlaySound("VOICE\ENGLISH\Pellew04.wav");
			dialog.text = DLG_TEXT[266];
			link.l1 = DLG_TEXT[206];
			link.l1.go = "Congrats_in_order";
		break;

		case "Congrats_in_order":
			dialog.text = DLG_TEXT[267];
			link.l1 = DLG_TEXT[268];
			link.l1.go = "Engagement";
		break;

		case "Engagement":
			dialog.text = DLG_TEXT[269];
			link.l1 = DLG_TEXT[270];
			link.l1.go = "Give_atropos2";
		break;

		case "Give_atropos2":
			AddDialogExitQuest("assigned_to_atropos5");
			dialog.text = DLG_TEXT[271];
			link.l1 = DLG_TEXT[246];
			link.l1.go = "leads_to_Wolfe";
		break;

		case "leads_to_Wolfe":
			dialog.text = DLG_TEXT[272];
			link.l1 = DLG_TEXT[246];
			link.l1.go = "leads_to_Wolfe2";
		break;

		case "leads_to_Wolfe2":
			dialog.text = DLG_TEXT[273];
			link.l1 = DLG_TEXT[230];
			link.l1.go = "Exit";
		break;

		case "traitors_done":
			dialog.text = DLG_TEXT[274];
			link.l1 = DLG_TEXT[246];
			link.l1.go = "traitors_done2";
		break;

		case "traitors_done2":
			dialog.text = DLG_TEXT[275];
			link.l1 = DLG_TEXT[276];
			link.l1.go = "traitors_done3";
		break;

		case "traitors_done3":
			dialog.text = DLG_TEXT[277];
			link.l1 = DLG_TEXT[278];
			link.l1.go = "traitors_done4";
		break;

		case "traitors_done4":
			dialog.text = DLG_TEXT[279];
			link.l1 = DLG_TEXT[280];
			link.l1.go = "traitors_done5";
		break;

		case "traitors_done5":
			dialog.text = DLG_TEXT[281];
			link.l1 = DLG_TEXT[282];
			link.l1.go = "traitors_done6";
		break;

		case "traitors_done6":
			dialog.text = DLG_TEXT[283];
			link.l1 = DLG_TEXT[284];
			link.l1.go = "traitors_done7";
		break;

		case "traitors_done7":
			dialog.text = DLG_TEXT[285];
			link.l1 = DLG_TEXT[286];
			link.l1.go = "traitors_done8";
		break;

		case "traitors_done8":
			dialog.text = DLG_TEXT[287];
			link.l1 = DLG_TEXT[219];
			link.l1.go = "Exit";
		break;
	}
}
