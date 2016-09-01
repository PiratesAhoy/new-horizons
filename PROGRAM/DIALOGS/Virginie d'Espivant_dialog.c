//#include "DIALOGS\Virginie d'Espivant_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	NPChar.gambled = true;//MAXIMUS
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		// PB -->
		case "exit_gov":
			AddDialogExitQuest("virginie_follow");
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
		// PB <--

		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\VIDE\VIDE001";
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (CheckQuestAttribute("gambling_with_girl", "gambled"))
			{
				Dialog.snd = "voice\VIDE\VIDE002";
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "she_becomes_prisoner";
				link.l2 =  DLG_TEXT[4];
				link.l2.go = "she_story";
				AddQuestRecord("gambled_girl", 4);
				if(CheckAttribute(PChar,"indialog.withgirl")) { DeleteAttribute(PChar,"indialog.withgirl"); }
			}		
			if (CheckQuestAttribute("gambling_with_girl", "to_hovernor"))
			{
				Dialog.snd = "voice\VIDE\VIDE019";
				dialog.text = DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				link.l1.go = "to_home";
				if(CheckAttribute(PChar,"indialog.withgirl")) { DeleteAttribute(PChar,"indialog.withgirl"); }
			}
		break;

		case "to_home":
			Dialog.snd = "voice\VIDE\VIDE003";
			dialog.text = DLG_TEXT[7];
			if (GetNationRelation2MainCharacter(FRANCE) == RELATION_ENEMY)
			{
				link.l1 = DLG_TEXT[8];
				link.l1.go = "to_home_bad";
				AddQuestRecord("gambled_girl", 11);
			}
			else
			{
				link.l1 = DLG_TEXT[9];
				link.l1.go = "exit_gov";
			}
			pchar.quest.gambling_with_girl = "to_hovernor_2";
			AddQuestRecord("gambled_girl", 10);
		break;

		case "to_home_bad":
			Dialog.snd = "voice\VIDE\VIDE004";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "to_home_bad_2";
			link.l2 = DLG_TEXT[12];
			link.l2.go = "exit_gov";
		break;

		case "to_home_bad_2":
			Dialog.snd = "voice\VIDE\VIDE005";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "exit";
			pchar.quest.gambling_with_girl = "done";
			AddDialogExitQuest("remove_virginie_complete"); // PB
			ChangeCharacterReputation(pchar, 1);
			OfficersReaction("good");
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 20);
			}
			else { AddPartyExp(pchar, 2000); }
			AddQuestRecord("gambled_girl", 12);
		break;

		case "she_story":
			Dialog.snd = "voice\VIDE\VIDE006";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "she_story_2";
		break;

		case "she_story_2":
			Dialog.snd = "voice\VIDE\VIDE007";
			dialog.text = DLG_TEXT[17] + GetCharacterFullName(npchar.id) + DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "she_story_3";
		break;

		case "she_story_3":
			Dialog.snd = "voice\VIDE\VIDE008";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "she_story_4";
		break;

		case "she_story_4":
			Dialog.snd = "voice\VIDE\VIDE009";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "she_story_5";
		break;

		case "she_story_5":
			Dialog.snd = "voice\VIDE\VIDE010";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "she_story_6";
		break;

		case "she_story_6":
			Dialog.snd = "voice\VIDE\VIDE011";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "she_story_7";
			link.l2 = DLG_TEXT[28];
			link.l2.go = "she_story_bad";
			AddQuestRecord("gambled_girl", 6);
		break;

		case "she_story_7":
			Dialog.snd = "voice\VIDE\VIDE012";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "she_story_8";
		break;

		case "she_story_8":
			Dialog.snd = "voice\VIDE\VIDE013";
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "she_story_9";
		break;

		case "she_story_9":
			Dialog.snd = "voice\VIDE\VIDE014";
// PB -->
		//	Why bother doing all this? The guy is only ever at Martinique anyway
		//	string island = FindIslandName(Islands[GetCharacterCurrentIsland(CharacterFromID("Raymond Bouchez"))].id); // KK
		//	dialog.text = DLG_TEXT[33] + GetCharacterFullName(DLG_TEXT[34]) + DLG_TEXT[35] + XI_ConvertString(island) + ".";//MAXIMUS: just for eye-candy :)
			dialog.text = DLG_TEXT[33] + GetCharacterFullName(DLG_TEXT[34]) + DLG_TEXT[35];
// PB <--
			link.l1 = DLG_TEXT[36];
			link.l1.go = "she_story_good";
		break;

		case "she_story_good":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
//			AddDialogExitQuest("gambled_girl_to_FdF");
			LAi_SetActorType(NPChar);
			LAi_ActorGoToLocator(NPChar, "reload", LocatorExitSence(PChar.location, "from", "tavern"), "gambled_girl_to_FdF", -1);
			AddQuestRecord("gambled_girl", 7);
		break;

		case "she_story_bad":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();// MAXIMUS [Why it was not here?!]
//			AddDialogExitQuest("girl_exit_from_room");
			LAi_SetActorType(NPChar);
			LAi_ActorGoToLocator(NPChar, "reload", LocatorExitSence(PChar.location, "from", "tavern"), "girl_exit_from_room_2_complete", -1);
			AddQuestRecord("gambled_girl", 8);
		break;

		case "speak_1":
			Dialog.snd = "voice\VIDE\VIDE015";
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Raymond Bouchez")].dialog.currentnode = "speak_1";
			AddDialogExitQuest("Raymond_speak");
		break;

		case "speak_2":
			Dialog.snd = "voice\VIDE\VIDE016";
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Raymond Bouchez")].dialog.currentnode = "speak_2";
			AddDialogExitQuest("Raymond_speak");
		break;

		case "speak_3":
			Dialog.snd = "voice\VIDE\VIDE017";
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "exit";
			AddDialogExitQuest("gambled_girl_exit_from_FDF_tavern");
			Diag.TempNode = "first time";
			AddQuestRecord("gambled_girl", 9);
		break;

		case "she_becomes_prisoner":
			Dialog.snd = "voice\VIDE\VIDE018";
			dialog.text = DLG_TEXT[43] + GetCharacterFullName(npchar.id) + DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "exit_prisoned_1";
			link.l2 = DLG_TEXT[46];
			link.l2.go = "she_story_3";
		break;

		case "exit_prisoned_1":
			string model = LAi_GetBoardingModel(pchar, "");
			ref tmpChar = LAi_CreateFantomCharacterEx(true, 0, true, true, 0.25, model, "reload", LocatorExitSence(PChar.location, "from", "tavern"));
			LAi_SetActorType(tmpChar);
			LAi_ActorFollow(tmpChar, PChar, "", -1);
			pchar.quest.gambling_with_girl.guard = tmpChar.id;
			LAi_CharacterPlaySound(CharacterFromID(pchar.quest.gambling_with_girl.guard),"Gr_Officer_m common");
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "exit_prisoned_2";
		break;

		case "exit_prisoned_2":
			LAi_CharacterPlaySound(CharacterFromID(pchar.quest.gambling_with_girl.guard),"Gr_Officer_m common");
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "exit_prisoned_3";
		break;

		case "exit_prisoned_3":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			LAi_CharacterPlaySound(CharacterFromID(pchar.quest.gambling_with_girl.guard),"AMBIENT\man_laughter.wav");
			LAi_type_actor_Reset(CharacterFromID(pchar.quest.gambling_with_girl.guard));
			LAi_SetActorType(NPChar);
			LAi_ActorGoToLocator(NPChar, "reload", LocatorExitSence(PChar.location, "from", "tavern"), "girl_for_sale", -1);
			LAi_ActorGoToLocation(CharacterFromID(pchar.quest.gambling_with_girl.guard), "reload", LocatorExitSence(PChar.location, "from", "tavern"), "none", "", "", "open_room", -1);
			PostEvent("CheckQuestPossibility", 100, "1", 0);
			AddPassenger(pchar, npchar, 1);
			OfficersReaction("bad");
			pchar.quest.gambling_with_girl = "prisoned";
			DeleteAttribute(pchar,"quest.gambling_with_girl.guard");
		break;
	}
}
