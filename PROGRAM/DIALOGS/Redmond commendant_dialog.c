//#include "DIALOGS\Redmond commendant_dialog.h"
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
	// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "Gov_Dialog_1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Gov_Dialog_2";
			Dialog.cam = "1";
			Dialog.snd = "voice\RECO\RECO001";
			
			dialog.text = DLG_TEXT[0];
			link.l99 = DLG_TEXT[1];
			link.l99.go = "exit";
		break;

		case "continue2":
			Dialog.snd = "voice\RECO\RECO002";
			dialog.text = DLG_TEXT[2];
			link.l99 = DLG_TEXT[3];
			link.l99.go = "continue3";
		break;

		case "continue3":
			Dialog.snd = "voice\RECO\RECO003";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit1";
			link.l99 = DLG_TEXT[6];
			link.l99.go = "continue4";
		break;

		case "continue4":
			Dialog.snd = "voice\RECO\RECO004";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "continue5";
		break;

		case "continue5":
			Dialog.snd = "voice\RECO\RECO005";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit1";
			link.l2 = DLG_TEXT[11];
			link.l2.go = "continue6";
		break;

		case "continue6":
			Diag.CurrentNode = "First time";
// NK -->
			AddDialogExitQuest("Let_my_edgar_go");
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar,-5000);
	
			ChangeCharacterAddressGroup(CharacterFromID("Jack Greenfield"), "", "sit", "sit2");
			ChangeCharacterAddressGroup(CharacterFromID("Martin Warner"), "", "sit", "sit2");
			SetCharacterShipLocation(CharacterFromID("Jack Greenfield"), "none" );
// NK <--
			DialogExit();
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit1":
			Diag.CurrentNode = "First time";
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
		
	}
}
