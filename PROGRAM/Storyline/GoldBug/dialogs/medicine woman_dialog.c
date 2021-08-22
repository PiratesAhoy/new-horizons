//#include "DIALOGS\Claire Voyant_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"


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
			
			PlaySound("VOICE\ENGLISH\claire_light.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			
			Diag.TempNode = "First time";
		break;

		case "medicine_bag":
			PlaySound("VOICE\ENGLISH\claire_welcome.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "medicine_bag1";
		break;

		case "medicine_bag1":
			PlaySound("VOICE\ENGLISH\claire_help.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "medicine_bag2";
		break;

		case "medicine_bag2":
			PlaySound("VOICE\ENGLISH\claire_hmm.wav");
			if(CheckAttribute(Pchar,"quest.book53") && Pchar.quest.book53 == "yes")
			{
				Dialog.text = DLG_TEXT[6];
				link.l1 = DLG_TEXT[7];
				link.l1.go = "medicine_bag3";
			}
			else
			{
				AddQuestRecord("The_message","8");
				Dialog.text = DLG_TEXT[10];
				link.l1 = DLG_TEXT[7];
				link.l1.go = "medicine_bag3";
			}
		break;

		case "medicine_bag3":
			PlaySound("VOICE\ENGLISH\claire_items.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			AddDialogExitQuest("medicine_bag_done");

			Diag.TempNode = "First time";
		break;

		case "calabash":
			PlaySound("VOICE\ENGLISH\claire_welcome.wav");
			Dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "calabash1";
		break;

		case "calabash1":
			PlaySound("VOICE\ENGLISH\claire_hmm.wav");
			Dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "calabash2";
		break;

		case "calabash2":
			TakenItems(Pchar, "calabash", 2);
			TakenItems(Pchar, "herbs", 2);
			PlaySound("VOICE\ENGLISH\claire_fortune.wav");
			Dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "calabash3";
		break;

		case "calabash3":
			PlaySound("VOICE\ENGLISH\claire_items.wav");
			Dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "calabash4";
		break;

		case "calabash4":
			PlaySound("VOICE\ENGLISH\claire_light.wav");
			Dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "calabash5";
		break;

		case "calabash5":
			PlaySound("VOICE\ENGLISH\claire_hmm.wav");
			Dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "exit";
			AddDialogExitQuest("medwom_calabash_done");
		break;



	/*
		case "bring_the_chest":
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
		break;

		case "give_medicine":
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "give_medicine1";
		break;

		case "give_medicine1":
			DialogExit();
			Diag.TempNode = "First time";
			
			AddMoneyToCharacter(NPChar,-10000);
			LaunchCharacterItemChange(NPChar);
		break;

		case "psst":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			AddDialogExitQuest("claire_and_defoe1");
		break;

		case "mind_reading":
			PlaySound("VOICE\ENGLISH\claire_welcome.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "mind_reading1";
		break;

		case "mind_reading1":
			PlaySound("AMBIENT\JAIL\sigh.wav");
			PlaySound("AMBIENT\JAIL\sigh.wav");
			PlaySound("AMBIENT\JAIL\sigh.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
			AddDialogExitQuest("claire_and_defoe4");
		break;

		case "more_documents":
			PlaySound("VOICE\ENGLISH\claire_light.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			AddDialogExitQuest("claire_and_defoe6");
		break;

		case "more_documents1":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			AddDialogExitQuest("claire_and_defoe9");
		break;

		case "pistols":
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "pistols1";
		break;

		case "pistols1":
			PlaySound("VOICE\ENGLISH\claire_items.wav");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			AddDialogExitQuest("claire_and_defoe12");
		break;

		case "see_future":
			PlaySound("VOICE\ENGLISH\claire_light.wav");
			Dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "see_future1";
		break;

		case "see_future1":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			AddDialogExitQuest("claire_and_defoe14");
		break;

		case "magic_key":
			PlaySound("VOICE\ENGLISH\claire_help.wav");
			Dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "magic_key1";
		break;

		case "magic_key1":
			PlaySound("VOICE\ENGLISH\claire_light.wav");
			LAi_SetActorType(CharacterFromID("Claire Voyant"));
			LAi_ActorTurnToCharacter(characterFromID("Claire Voyant"), characterFromID("Defoe"));
			Dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_to_port9");
		break;

		case "breathe_on_key":
			PlaySound("VOICE\ENGLISH\claire_items.wav");
			LAi_SetActorType(CharacterFromID("Claire Voyant"));
			LAi_ActorTurnToCharacter(characterFromID("Claire Voyant"), characterFromID("Defoe"));
			Dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_to_port11");
		break;

		case "crew_is_complete":
			PlaySound("VOICE\ENGLISH\claire_help.wav");
			LAi_SetActorType(CharacterFromID("Claire Voyant"));
			LAi_ActorTurnToCharacter(characterFromID("Claire Voyant"), characterFromID("grandma"));
			Dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_future_plans15");
		break;

		case "claire_crew_lines":
			PlaySound("VOICE\ENGLISH\claire_help.wav");
			Dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "exit";
			AddDialogExitQuest("pchar_choose_sailors_and_officers");
		break;

		case "notebook":
			PlaySound("VOICE\ENGLISH\claire_fortune.wav");
			Dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_map13");
		break;

		case "Teach_joke":
			PlaySound("VOICE\ENGLISH\claire_light.wav");
			Dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_map25");
		break;
	*/
		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
