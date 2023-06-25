void ProcessDialogEvent()
{
	ref NPChar, PChar, d; 
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
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

			dialog.snd = "Voice\BIBR\BIBR006";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (pchar.quest.Jacks_early_days == "about_to_go_down")
			{
					dialog.text = DLG_TEXT[22];
					link.l1 = DLG_TEXT[23];
					link.l1.go = "arrestexit";
			}
			if (pchar.quest.Jacks_early_days == "some_fast_talking")
			{
					dialog.snd = "Voice\BIBR\BIBR006";			
					dialog.text = DLG_TEXT[24];
					link.l1 = DLG_TEXT[25];
					link.l1.go = "fast_talking_exit"; //"keeptalking";
			}
			if (pchar.quest.Jacks_early_days == "continue_fast_talking")
			{
					dialog.snd = "Voice\BIBR\BIBR006";			
					dialog.text = DLG_TEXT[26];
					link.l1 = DLG_TEXT[27];
					link.l1.go = "arrestexit2";
			}
			if (pchar.quest.Jacks_early_days == "narrow_squeak")
			{
					dialog.text = DLG_TEXT[28];
					link.l1 = DLG_TEXT[29];
					link.l1.go = "arrestexit3";
			}
			if (pchar.quest.Jacks_early_days == "deeper_in_trouble")
			{
					dialog.text = DLG_TEXT[30];
					link.l1 = DLG_TEXT[31];
					link.l1.go = "deeper_in_trouble2";
			}
			if (pchar.quest.Jacks_early_days == "now_in_prison")
			{
					dialog.text = DLG_TEXT[36];
					link.l1 = DLG_TEXT[37];
					link.l1.go = "soldier_explains";
			}
		break;

		case "keeptalking":
					dialog.snd = "Voice\BIBR\BIBR006";		
					dialog.text = DLG_TEXT[26];
					link.l1 = DLG_TEXT[27];
					link.l1.go = "arrestexit2";
		break;

		case "deeper_in_trouble2":
					dialog.snd = "Voice\BIBR\BIBR006";
					dialog.text = DLG_TEXT[32];
					link.l1 = DLG_TEXT[33];
					link.l1.go = "deeper_in_trouble3";
		break;

		case "deeper_in_trouble3":
					dialog.snd = "Voice\BIBR\BIBR006";
					dialog.text = DLG_TEXT[34];
					link.l1 = DLG_TEXT[35];
					link.l1.go = "trouble_exit";
		break;

		case "soldier_explains":
					dialog.snd = "Voice\BIBR\BIBR006";
					dialog.text = DLG_TEXT[38];
					link.l1 = DLG_TEXT[39];
					link.l1.go = "explains_exit";
		break;

		case "trouble_exit":
			TakeItemFromCharacter(Pchar,"jewelry2");
			TakeItemFromCharacter(Pchar,"jewelry2");
			TakeItemFromCharacter(Pchar,"jewelry2");
			TakeItemFromCharacter(Pchar,"jewelry2");
			TakeItemFromCharacter(Pchar,"jewelry2");
			TakeItemFromCharacter(Pchar,"jewelry2");
			TakeItemFromCharacter(Pchar,"jewelry2");
			TakeItemFromCharacter(Pchar,"jewelry2");
			TakeItemFromCharacter(Pchar,"jewelry2");
			TakeItemFromCharacter(Pchar,"jewelry2");
			TakeItemFromCharacter(Pchar,"jewelry2");
			RemoveCharacterEquip(pchar, BLADE_ITEM_TYPE);
			RemoveCharacterEquip(pchar, GUN_ITEM_TYPE);
			EnableEquip(pchar, BLADE_ITEM_TYPE, false);
			EnableEquip(pchar, GUN_ITEM_TYPE, false);
			pchar.quest.Jacks_early_days = "Diamonds_to_jail"
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			AddDialogExitQuest("Arrested_this_time");
		break;

		case "arrestexit":
			pchar.quest.Jacks_early_days = "some_fast_talking"
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			AddDialogExitQuest("Almost_arrested");
		break;

		case "arrestexit2":
			pchar.quest.Jacks_early_days = "narrow_squeak"
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			AddDialogExitQuest("Almost_arrested2");
		break;

		case "fast_talking_exit":
			pchar.quest.Jacks_early_days = "narrow_squeak"
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			AddDialogExitQuest("Almost_arrested_again");
		break;		
		
		case "arrestexit3":
			pchar.quest.Jacks_early_days = "narrow_squeak_over"
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			AddDialogExitQuest("And_the_soldiers_leave");			
		break;

		case "explains_exit":
			pchar.quest.Jacks_early_days = "second_narrow_squeak"
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			AddDialogExitQuest("Back_to_the_Commander");
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}
