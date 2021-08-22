
void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
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
			Dialog.snd = "voice\PADI\PADI001";
			
			PlaySound("VOICE\ENGLISH\Poe_ok.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";

			Diag.TempNode = "first time";
		break;

		case "visitor":
			PlaySound("VOICE\ENGLISH\Poe_well.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "visitor1";
		break;

		case "visitor1":
			PlaySound("VOICE\ENGLISH\Poe_trophy.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
			AddDialogExitQuest("visitor_done");
		break;

		case "new_shells":
			PlaySound("VOICE\ENGLISH\Poe_and.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("new_shells_done");
		break;
		
		case "goldbug":
			PlaySound("VOICE\ENGLISH\Poe_obvious.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "goldbug1";
		break;

		case "goldbug1":
			PlaySound("VOICE\ENGLISH\Poe_go_on.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "goldbug2";
		break;

		case "goldbug2":
			PlaySound("VOICE\ENGLISH\Poe_ooh.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
			AddDialogExitQuest("Poe_goldbug_done");
		break;

		case "goldbug_describe":
			PlaySound("VOICE\ENGLISH\Poe_ok.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "goldbug_describe1";
		break;

		case "goldbug_describe1":
			PlaySound("VOICE\ENGLISH\Poe_and.wav");
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			AddDialogExitQuest("Poe_goldbug_describe_done");
		break;

		case "show_me_drawing":
			PlaySound("VOICE\ENGLISH\Poe_ooh.wav");
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			AddDialogExitQuest("show_me_drawing_done");
		break;




		case "less_fire":
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			AddDialogExitQuest("Poe_sittype");
		break;

		case "more_fire":
			PlaySound("VOICE\ENGLISH\Poe_go_on.wav");
			Dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			AddDialogExitQuest("Poe_sittype");
		break;

		case "light_fire":
			PlaySound("VOICE\ENGLISH\Poe_try_again.wav");
			Dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			AddDialogExitQuest("Poe_sittype");
		break;




		case "a_skull":
			PlaySound("VOICE\ENGLISH\Poe_result.wav");
			Dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "a_skull1";
		break;

		case "a_skull1":
			PlaySound("VOICE\ENGLISH\Poe_very_nice.wav");
			Dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "a_skull2";
		break;

		case "a_skull2":
			PlaySound("VOICE\ENGLISH\Poe_well.wav");
			Dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "a_skull3";
		break;

		case "a_skull3":
			PlaySound("VOICE\ENGLISH\Poe_try_again.wav");
			Dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			AddDialogExitQuest("a_skull_done");
		break;

		case "good_night":
			PlaySound("VOICE\ENGLISH\Poe_well.wav");
			Dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
			AddDialogExitQuest("good_night_done");
		break;

	//------------------------------------------------------------------

		case "Poe_bedroom":
			PlaySound("VOICE\ENGLISH\Poe_well.wav");
			Dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
			AddDialogExitQuest("Legrand_to_armchair");
		break;

		case "Poe_bedroom1":
			PlaySound("VOICE\ENGLISH\Poe_go_on.wav");
			Dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit";
			AddDialogExitQuest("Legrand_tells_story");
		break;

		case "Poe_bedroom2":
			PlaySound("VOICE\ENGLISH\Poe_ooh.wav");
			Dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
			AddDialogExitQuest("Poe_takes_document");
		break;

		case "Poe_bedroom3":
			PlaySound("VOICE\ENGLISH\Poe_obvious.wav");
			Dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "Poe_bedroom4";
		break;

		case "Poe_bedroom4":
			PlaySound("VOICE\ENGLISH\Poe_simplicity.wav");
			Dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "Poe_bedroom5";
		break;

		case "Poe_bedroom5":
			AddQuestRecord("The_message","10");
			PlaySound("VOICE\ENGLISH\Poe_look.wav");
			Dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "Poe_bedroom6";
		break;

		case "Poe_bedroom6":
			PlaySound("VOICE\ENGLISH\Poe_symbols.wav");
			Dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			AddDialogExitQuest("Through_word");		//player consults excel file
		break;

	//-----------------------------------------------------------------------

		case "Poe_letter_O":
			PlaySound("VOICE\ENGLISH\Poe_symbols.wav");
			Dialog.text = DLG_TEXT[52];
			
			link.l1 = DLG_TEXT[53];
			link.l1.go = "no_idea";
			
			link.l2 = DLG_TEXT[55];
			link.l2.go = "no_idea";
			link.l3 = DLG_TEXT[56];
			link.l3.go = "no_idea";
			link.l4 = DLG_TEXT[57];
			link.l4.go = "no_idea";
			link.l5 = DLG_TEXT[58];
			link.l5.go = "no_idea";
			link.l6 = DLG_TEXT[59];
			link.l6.go = "no_idea";
			link.l7 = DLG_TEXT[60];
			link.l7.go = "no_idea";
			link.l8 = DLG_TEXT[61];
			link.l8.go = "no_idea";
			link.l9 = DLG_TEXT[62];
			link.l9.go = "no_idea";
			link.l10 = DLG_TEXT[63];
			link.l10.go = "no_idea";
			link.l11 = DLG_TEXT[64];
			link.l11.go = "no_idea";
			link.l12 = DLG_TEXT[65];
			link.l12.go = "no_idea";
			link.l13 = DLG_TEXT[66];
			link.l13.go = "no_idea";
			link.l14 = DLG_TEXT[67];
			link.l14.go = "Poe_letter_U";
			link.l15 = DLG_TEXT[68];
			link.l15.go = "no_idea";
			link.l16 = DLG_TEXT[69];
			link.l16.go = "no_idea";
			link.l17 = DLG_TEXT[70];
			link.l17.go = "no_idea";
			link.l18 = DLG_TEXT[71];
			link.l18.go = "no_idea";
			link.l19 = DLG_TEXT[72];
			link.l19.go = "no_idea";
			link.l20 = DLG_TEXT[73];
			link.l20.go = "no_idea";
			link.l21 = DLG_TEXT[74];
			link.l21.go = "no_idea";
			link.l20 = DLG_TEXT[75];
			link.l20.go = "no_idea";
			link.l21 = DLG_TEXT[76];
			link.l21.go = "no_idea";
		break;

		case "no_idea":
			PlaySound("VOICE\ENGLISH\Poe_try_again.wav");
			Dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			AddDialogExitQuest("Poe_checks_oug");
		break;

		case "Poe_letter_U":
	Pchar.quest.letter_O = "ok";

			PlaySound("VOICE\ENGLISH\Poe_and.wav");
			Dialog.text = DLG_TEXT[77];
			
			link.l1 = DLG_TEXT[53];
			link.l1.go = "no_idea";
			
			link.l2 = DLG_TEXT[55];
			link.l2.go = "no_idea";
			link.l3 = DLG_TEXT[56];
			link.l3.go = "no_idea";
			link.l4 = DLG_TEXT[57];
			link.l4.go = "no_idea";
			link.l5 = DLG_TEXT[58];
			link.l5.go = "no_idea";
			link.l6 = DLG_TEXT[59];
			link.l6.go = "no_idea";
			link.l7 = DLG_TEXT[60];
			link.l7.go = "no_idea";
			link.l8 = DLG_TEXT[61];
			link.l8.go = "no_idea";
			link.l9 = DLG_TEXT[62];
			link.l9.go = "no_idea";
			link.l10 = DLG_TEXT[63];
			link.l10.go = "no_idea";
			link.l11 = DLG_TEXT[64];
			link.l11.go = "no_idea";
			link.l12 = DLG_TEXT[65];
			link.l12.go = "no_idea";
			link.l13 = DLG_TEXT[66];
			link.l13.go = "no_idea";
			
			link.l15 = DLG_TEXT[68];
			link.l15.go = "no_idea";
			link.l16 = DLG_TEXT[69];
			link.l16.go = "no_idea";
			link.l17 = DLG_TEXT[70];
			link.l17.go = "no_idea";
			link.l18 = DLG_TEXT[71];
			link.l18.go = "Poe_letter_G";
			link.l19 = DLG_TEXT[72];
			link.l19.go = "no_idea";
			link.l20 = DLG_TEXT[73];
			link.l20.go = "no_idea";
			link.l21 = DLG_TEXT[74];
			link.l21.go = "no_idea";
			link.l20 = DLG_TEXT[75];
			link.l20.go = "no_idea";
			link.l21 = DLG_TEXT[76];
			link.l21.go = "no_idea";
		break;

		case "Poe_letter_G":
	Pchar.quest.letter_U = "ok";

			PlaySound("VOICE\ENGLISH\Poe_promising.wav");
			Dialog.text = DLG_TEXT[78];
			
			link.l1 = DLG_TEXT[53];
			link.l1.go = "no_idea";
			
			link.l2 = DLG_TEXT[55];
			link.l2.go = "no_idea";
			link.l3 = DLG_TEXT[56];
			link.l3.go = "no_idea";
			link.l4 = DLG_TEXT[57];
			link.l4.go = "no_idea";
			link.l5 = DLG_TEXT[58];
			link.l5.go = "no_idea";
			link.l6 = DLG_TEXT[59];
			link.l6.go = "no_idea";
			link.l7 = DLG_TEXT[60];
			link.l7.go = "Poe_G_ok";
			link.l8 = DLG_TEXT[61];
			link.l8.go = "no_idea";
			link.l9 = DLG_TEXT[62];
			link.l9.go = "no_idea";
			link.l10 = DLG_TEXT[63];
			link.l10.go = "no_idea";
			link.l11 = DLG_TEXT[64];
			link.l11.go = "no_idea";
			link.l12 = DLG_TEXT[65];
			link.l12.go = "no_idea";
			link.l13 = DLG_TEXT[66];
			link.l13.go = "no_idea";
			
			link.l15 = DLG_TEXT[68];
			link.l15.go = "no_idea";
			link.l16 = DLG_TEXT[69];
			link.l16.go = "no_idea";
			link.l17 = DLG_TEXT[70];
			link.l17.go = "no_idea";
			
			link.l19 = DLG_TEXT[72];
			link.l19.go = "no_idea";
			link.l20 = DLG_TEXT[73];
			link.l20.go = "no_idea";
			link.l21 = DLG_TEXT[74];
			link.l21.go = "no_idea";
			link.l20 = DLG_TEXT[75];
			link.l20.go = "no_idea";
			link.l21 = DLG_TEXT[76];
			link.l21.go = "no_idea";
		break;

		case "Poe_G_ok":
	Pchar.quest.letter_G = "ok";

			PlaySound("VOICE\ENGLISH\Poe_go_on.wav");
			Dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "exit";
			AddDialogExitQuest("Jupiter_degree");
		break;

		//Jupiter jumps into the dialog here


		case "Poe_leaves_bedroom":
	ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Poe_bedroom", "goto", "stay1");

			AddQuestRecord("The_message","13");
			PlaySound("VOICE\ENGLISH\Poe_well.wav");
			Dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "Poe_leaves_bedroom1";
		break;

		case "Poe_leaves_bedroom1":
			PlaySound("VOICE\ENGLISH\Poe_go_on.wav");
			Dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "Poe_leaves_bedroom2";
		break;

		case "Poe_leaves_bedroom2":
			PlaySound("VOICE\ENGLISH\Poe_simplicity.wav");
			Dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "exit";
			AddDialogExitQuest("Dupin_house");
		break;
//-----------------------------------------------------------------------
		case "visitor_again":
			PlaySound("VOICE\ENGLISH\Poe_well.wav");
			Dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "visitor_again1";
		break;

		case "visitor_again1":
			PlaySound("VOICE\ENGLISH\Poe_go_on.wav");
			Dialog.text = DLG_TEXT[90];
			link.l1 = DLG_TEXT[91];
			link.l1.go = "exit";
			AddDialogExitQuest("visitor_again_done");
		break;



		case "sentences":
			LAi_SetSitType(NPchar);
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box6");
			PlaySound("VOICE\ENGLISH\Poe_ok.wav");
			Dialog.text = DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "sentences1";
		break;

		case "sentences1":
			LAi_SetSitType(NPchar);
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box6");
			PlaySound("VOICE\ENGLISH\Poe_very_nice.wav");
			Dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[87];
			link.l1.go = "sentences2";
		break;

		case "sentences2":
			LAi_SetSitType(NPchar);
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box6");
			PlaySound("VOICE\ENGLISH\Poe_look.wav");
			Dialog.text = DLG_TEXT[88];
			link.l1 = DLG_TEXT[89];
			link.l1.go = "sentences3";
		break;

		case "sentences3":
			LAi_SetSitType(NPchar);
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box6");
			PlaySound("VOICE\ENGLISH\Poe_promising.wav");
			Dialog.text = DLG_TEXT[92];
			link.l1 = DLG_TEXT[93];
			link.l1.go = "exit";
			AddDialogExitQuest("Poe_last_paper");
		break;

		case "sentences4":
			LAi_SetSitType(NPchar);
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "box", "box6");
			PlaySound("VOICE\ENGLISH\Poe_well.wav");
			Dialog.text = DLG_TEXT[94];
			link.l1 = DLG_TEXT[95];
			link.l1.go = "exit";
			AddDialogExitQuest("Poe_last_paper5");
		break;

		case "bye_bye_Poe":
			PlaySound("VOICE\ENGLISH\Poe_well.wav");
			LAi_SetStayType(NPchar);
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Poe_bedroom", "goto", "stay3");
			Dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "exit";
			AddDialogExitQuest("bye_bye_Poe_done");
		break;

		case "Poe_has_compass":
			PlaySound("VOICE\ENGLISH\Poe_well.wav");
			Dialog.text = DLG_TEXT[98];
			link.l1 = DLG_TEXT[99];
			link.l1.go = "Poe_has_compass1";
		break;

		case "Poe_has_compass1":
			PlaySound("VOICE\ENGLISH\Poe_ok.wav");
			Dialog.text = DLG_TEXT[100];
			link.l1 = DLG_TEXT[101];
			link.l1.go = "Poe_has_compass2";
		break;

		case "Poe_has_compass2":
			PlaySound("VOICE\ENGLISH\Poe_look.wav");
			Dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "Poe_has_compass3";
		break;

		case "Poe_has_compass3":
			PlaySound("VOICE\ENGLISH\Poe_obvious.wav");
			Dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];
			link.l1.go = "exit";
			AddDialogExitQuest("meeting_at_Poes15");
		break;

		case "Poe_gives_compass":
			PlaySound("VOICE\ENGLISH\Poe_promising.wav");
			Dialog.text = DLG_TEXT[108];
			link.l1 = DLG_TEXT[109];
			link.l1.go = "Poe_gives_compass1";
		break;

		case "Poe_gives_compass1":
			PlaySound("VOICE\ENGLISH\Poe_ooh.wav");
			Dialog.text = DLG_TEXT[110];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "Poe_gives_compass2";
		break;

		case "Poe_gives_compass2":
			PlaySound("VOICE\ENGLISH\Poe_very_nice.wav");
			Dialog.text = DLG_TEXT[106];
			link.l1 = DLG_TEXT[107];
			link.l1.go = "exit";
			AddDialogExitQuest("meeting_at_Poes19");
		break;

		case "Poe_and_landlady":
			PlaySound("VOICE\ENGLISH\Poe_and.wav");
			Dialog.text = DLG_TEXT[112];
			link.l1 = DLG_TEXT[113];
			link.l1.go = "Poe_and_landlady_A";
		break;

		case "Poe_and_landlady_A":
			PlaySound("VOICE\ENGLISH\Poe_ok.wav");
			Dialog.text = DLG_TEXT[114];
			link.l1 = DLG_TEXT[115];
			link.l1.go = "exit";
			AddDialogExitQuest("Poe_and_landlady6");
		break;

		case "last_Poe_bedroom":
			ChangeCharacterAddressGroup(NPchar, "poe_bedroom", "sit", "sit2");
			LAi_SetSitType(NPchar);
			LAi_SetSitType(Pchar);
			PlaySound("VOICE\ENGLISH\Poe_well.wav");
			Dialog.text = DLG_TEXT[116];
			link.l1 = DLG_TEXT[117];
			link.l1.go = "last_Poe_bedroom_A";
		break;

		case "last_Poe_bedroom_A":
			LAi_SetSitType(NPchar);
			LAi_SetSitType(Pchar);
			PlaySound("VOICE\ENGLISH\Poe_symbols.wav");
			Dialog.text = DLG_TEXT[118];
			link.l1 = DLG_TEXT[119];
			link.l1.go = "last_Poe_bedroom_B";
		break;

		case "last_Poe_bedroom_B":
			LAi_SetSitType(NPchar);
			LAi_SetSitType(Pchar);
			PlaySound("VOICE\ENGLISH\Poe_try_again.wav");
			Dialog.text = DLG_TEXT[120];
			link.l1 = DLG_TEXT[121];
			link.l1.go = "last_Poe_bedroom_C";
		break;

		case "last_Poe_bedroom_C":
			LAi_SetSitType(NPchar);
			LAi_SetSitType(Pchar);
			PlaySound("VOICE\ENGLISH\Poe_simplicity.wav");
			Dialog.text = DLG_TEXT[122];
			link.l1 = DLG_TEXT[123];
			link.l1.go = "last_Poe_bedroom_D";
		break;

		case "last_Poe_bedroom_D":
			LAi_SetSitType(NPchar);
			LAi_SetSitType(Pchar);
			PlaySound("VOICE\ENGLISH\Poe_obvious.wav");
			Dialog.text = DLG_TEXT[124];
			link.l1 = DLG_TEXT[125];
			link.l1.go = "last_Poe_bedroom_E";
		break;

		case "last_Poe_bedroom_E":
			LAi_SetSitType(NPchar);
			LAi_SetSitType(Pchar);
			PlaySound("VOICE\ENGLISH\Poe_go_on.wav");
			Dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[127];
			link.l1.go = "last_Poe_bedroom_F";
		break;

		case "last_Poe_bedroom_F":
			LAi_SetSitType(NPchar);
			LAi_SetSitType(Pchar);
			PlaySound("VOICE\ENGLISH\Poe_and.wav");
			Dialog.text = DLG_TEXT[128];
			link.l1 = DLG_TEXT[129];
			link.l1.go = "last_Poe_bedroom_G";
		break;

		case "last_Poe_bedroom_G":
			LAi_SetSitType(NPchar);
			LAi_SetSitType(Pchar);
			PlaySound("VOICE\ENGLISH\Poe_ok.wav");
			Dialog.text = DLG_TEXT[130];
			link.l1 = DLG_TEXT[131];
			link.l1.go = "exit";
			AddDialogExitQuest("last_Poe_bedroom7");
		break;

		case "last_Poe_bedroom_H":
			PlaySound("VOICE\ENGLISH\Poe_ooh.wav");
			Dialog.text = DLG_TEXT[132];
			link.l1 = DLG_TEXT[133];
			link.l1.go = "exit";
			AddDialogExitQuest("last_Poe_bedroom11");
		break;

		case "outside_gates":
			PlaySound("VOICE\ENGLISH\Poe_go_on.wav");
			Dialog.text = DLG_TEXT[134];
			link.l1 = DLG_TEXT[135];
			link.l1.go = "exit";
			AddDialogExitQuest("last_Poe_bedroom13");
		break;

		case "I_got_nails":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("Jupiter"));
			LAi_SetActorType(characterFromID("Jupiter"));
			LAi_ActorTurnToCharacter(characterFromID("Jupiter"), NPchar);

			PlaySound("VOICE\ENGLISH\Poe_result.wav");
			Dialog.text = DLG_TEXT[136];
			link.l1 = DLG_TEXT[137];
			link.l1.go = "exit";
			AddDialogExitQuest("I_got_nails_done");
		break;

		case "this_is_the_tree":
			PlaySound("VOICE\ENGLISH\Poe_well.wav");
			Dialog.text = DLG_TEXT[138];
			link.l1 = DLG_TEXT[139];
			link.l1.go = "exit";
			AddDialogExitQuest("Jup_climbs_tree_again");
		break;

		case "its_so_silent":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("Jupiter"));
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Jupiter"));

			PlaySound("VOICE\ENGLISH\Poe_and.wav");
			Dialog.text = DLG_TEXT[140];
			link.l1 = DLG_TEXT[141];
			link.l1.go = "exit";
			AddDialogExitQuest("Jup_why_stop_delay");
		break;

		case "beeline_how_long":
			Pchar.quest.beeline = "unknown";
			PlaySound("VOICE\ENGLISH\Poe_symbols.wav");
			Dialog.text = DLG_TEXT[142];
			link.l1 = DLG_TEXT[143];
			link.l1.go = "exit";
			AddDialogExitQuest("beeline_how_long1");
		break;

		case "beeline_how_long2":
			PlaySound("VOICE\ENGLISH\Poe_symbols.wav");
			Dialog.text = DLG_TEXT[144];
			link.l1 = DLG_TEXT[145];
			link.l1.go = "exit";
			AddDialogExitQuest("beeline_how_long1");
		break;

		case "beeline_50_feet":
			PlaySound("VOICE\ENGLISH\Poe_and.wav");
			Dialog.text = DLG_TEXT[144];
			link.l1 = DLG_TEXT[146];
			link.l1.go = "beeline_how_long3";
		break;

		case "beeline_how_long3":
			PlaySound("VOICE\ENGLISH\Poe_look.wav");
			Dialog.text = DLG_TEXT[147];
			link.l1 = DLG_TEXT[148];
			link.l1.go = "exit";
			AddDialogExitQuest("beeline_how_long4");
		break;		

		case "beeline_how_long6_A":
			PlaySound("VOICE\ENGLISH\Poe_promising.wav");
			Dialog.text = DLG_TEXT[149];
			link.l1 = DLG_TEXT[150];
			link.l1.go = "exit";
			AddDialogExitQuest("beeline_how_long7");
		break;

		case "wrong_spot2":
			PlaySound("VOICE\ENGLISH\Poe_obvious.wav");
			Dialog.text = DLG_TEXT[151];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			AddDialogExitQuest("wrong_spot2_done");
		break;

		case "right_eye2":
			PlaySound("VOICE\ENGLISH\Poe_simplicity.wav");
			LAi_SetOfficerType(characterFromID("Jupiter"));
			Dialog.text = DLG_TEXT[152];
			link.l1 = DLG_TEXT[153];
			link.l1.go = "right_eye3";
		break;

		case "right_eye3":
			PlaySound("VOICE\ENGLISH\Poe_look.wav");
			Dialog.text = DLG_TEXT[154];
			link.l1 = DLG_TEXT[155];
			link.l1.go = "exit";
			AddDialogExitQuest("right_eye3_done");
		break;

		case "skeletons_found":
			PlaySound("VOICE\ENGLISH\Poe_result.wav");
			Dialog.text = DLG_TEXT[156];
			link.l1 = DLG_TEXT[157];
			link.l1.go = "exit";
			AddDialogExitQuest("skeletons_found1");
		break;

		case "Poe_unlocks_chest":
			PlaySound("VOICE\ENGLISH\Poe_promising.wav");
			Dialog.text = DLG_TEXT[158];
			link.l1 = DLG_TEXT[159];
			link.l1.go = "exit";
			AddDialogExitQuest("Poe_unlocks_chest1");
		break;

		case "where_are_the_maroons":
			PlaySound("VOICE\ENGLISH\Poe_result.wav");
			Dialog.text = DLG_TEXT[160];
			link.l1 = DLG_TEXT[161];
			link.l1.go = "exit";
			AddDialogExitQuest("where_are_the_maroons1");
		break;

		case "maroons_defeated":
			PlaySound("VOICE\ENGLISH\Poe_well.wav");
			Dialog.text = DLG_TEXT[162];
			link.l1 = DLG_TEXT[163];
			link.l1.go = "exit";
			AddDialogExitQuest("Hero_my_cousin");
		break;

		case "good_night1":
			PlaySound("VOICE\ENGLISH\Poe_ok.wav");
			Dialog.text = DLG_TEXT[164];
			link.l1 = DLG_TEXT[165];
			link.l1.go = "exit";
			AddDialogExitQuest("good_night2");
		break;

		case "treasure_gone2":
			PlaySound("VOICE\ENGLISH\Poe_well.wav");
			Dialog.text = DLG_TEXT[166];
			link.l1 = DLG_TEXT[170];
			link.l1.go = "treasure_gone3";
		break;

		case "treasure_gone3":
			PlaySound("VOICE\ENGLISH\Poe_very_nice.wav");
			Dialog.text = DLG_TEXT[171];
			link.l1 = DLG_TEXT[172];
			link.l1.go = "treasure_gone4";
		break;

		case "treasure_gone4":
			PlaySound("VOICE\ENGLISH\Poe_trophy.wav");
			Dialog.text = DLG_TEXT[173];
			link.l1 = DLG_TEXT[167];
			link.l1.go = "treasure_gone5";
		break;

		case "treasure_gone5":
			PlaySound("VOICE\ENGLISH\Poe_promising.wav");
			Dialog.text = DLG_TEXT[168];
			link.l1 = DLG_TEXT[169];
			link.l1.go = "exit";
			AddDialogExitQuest("treasure_gone6");
		break;

//-------------------------------------------------------------------------

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
