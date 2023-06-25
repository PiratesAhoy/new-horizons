//#include "DIALOGS\Enc_Rapers_dialog.h"
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
	
	switch(Dialog.CurrentNode)
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();			
		break;

		case "exit_fight":
			AddDialogExitQuest("LandEnc_Defector_PursuersFight");

			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();			
		break;

		case "exit_noFight":
			AddDialogExitQuest("LandEnc_Defector_NoFight");

			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();			
		break;

		case "Node_1":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			LAi_type_actor_Reset(CharacterFromID("Enc_Char1"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char2"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char3"));
			LAi_type_actor_Reset(CharacterFromID("Enc_Char4"));
			
			Preprocessor_Add("person",GetCharacterAddressForm(CharacterFromID("Enc_Char1"),ADDR_GENDER,false,false));
			Preprocessor_Add("pronoun",GetMyPronounObj(CharacterFromID("Enc_Char1")));

			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[0], DLG_TEXT[1], DLG_TEXT[2], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = LinkRandPhrase(DLG_TEXT[3], DLG_TEXT[4], DLG_TEXT[5]);
			Link.l1.go = "Node_2";
			Link.l2 = LinkRandPhrase(DLG_TEXT[6], DLG_TEXT[7], DLG_TEXT[8]);
			Link.l2.go = "Exit_NoFight";
			
		break;

		case "Node_2":
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounPossessive(PChar)));
		//	if(PChar.sex == "woman") Preprocessor_Add("pronoun", XI_ConvertString("her"));
		//	else Preprocessor_Add("pronoun", XI_ConvertString("his"));
			d.Text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "Exit_Fight";
		break;

		case "OnceAgain":
			Diag.TempNode = "OnceAgain";
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "Exit_NoFight";
			Link.l2 = DLG_TEXT[13];
			Link.l2.go = "Node_2";
		break;
				
	}
}