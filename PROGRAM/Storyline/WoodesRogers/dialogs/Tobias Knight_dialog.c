//#include "DIALOGS\Church crew_dialog.h"
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
			Dialog.snd = "voice\THDI\THDI001";
		break;

		case "he_hit_me":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("Margaret_Pough"));
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("black_servant1"));

			PlaySound("VOICE\ENGLISH\Eng_m_c_082.wav");			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];  
			link.l1.go = "exit";
			AddDialogExitQuest("Estate_end5"); 
		break;

		case "hostile":
			PlaySound("VOICE\ENGLISH\Eng_m_c_041.wav");			
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];  
			link.l1.go = "exit";
			Diag.TempNode = "hostile";
		break;

		case "office1":
			LAi_SetStayType(characterFromID("Knight"));
			ChangeCharacterAddressGroup(characterFromID("Knight"), "BB_Eden_office", "goto", "knight_stay");
			PlaySound("VOICE\ENGLISH\Eng_m_c_079.wav");			
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];  
			link.l1.go = "office2";
			AddDialogExitQuest("Eden_bribing_scene6");	//only once this 
		break;

		case "office2":
			LAi_SetStayType(characterFromID("Knight"));
			ChangeCharacterAddressGroup(characterFromID("Knight"), "BB_Eden_office", "goto", "knight_stay");
			PlaySound("VOICE\ENGLISH\Eng_m_c_080.wav");			
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];  
			link.l1.go = "exit";
			AddDialogExitQuest("Knight_office2_done"); 
		break;

		case "orwell":
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Eden"));
			PlaySound("VOICE\ENGLISH\Eng_m_c_062.wav");			
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];  
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene22"); 
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
