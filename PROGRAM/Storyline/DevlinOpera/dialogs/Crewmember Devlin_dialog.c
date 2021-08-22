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
			link.l1.go = "Turks2";
		break;

		case "Turks2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Turks3";
		break;

		case "Turks3":
			dialog.snd = "Voice\ARSI\ARSI003";
			DisableFastTravel(true);
			ChangeCharacterAddressGroup(characterfromID("Merciless Mark"),"Turks_townhall", "sit", "sit6");
            LAi_SetSitType(characterfromID("Merciless Mark"));
			ChangeCharacterAddressGroup(characterfromID("Robert Cook"),"Turks_townhall", "sit", "sit4");
            LAi_SetSitType(characterfromID("Robert Cook"));
			ChangeCharacterAddressGroup(characterfromID("Couch Captain Charles"),"Turks_townhall", "sit", "sit5");
            LAi_SetSitType(characterfromID("Couch Captain Charles"));
			ChangeCharacterAddressGroup(characterfromID("Maximus"),"Turks_townhall", "sit", "sit3");
            LAi_SetSitType(characterfromID("Maximus"));
			ChangeCharacterAddressGroup(characterfromID("Sir Christopher Mings"),"Turks_townhall", "sit", "sit7");
            LAi_SetSitType(characterfromID("Sir Christopher Mings"));
			ChangeCharacterAddressGroup(characterfromID("Nathan Kell"),"Turks_townhall", "goto", "goto6");
			ChangeCharacterAddressGroup(characterfromID("Thomas the Terror"),"Turks_townhall", "goto", "goto4");
			ChangeCharacterAddressGroup(characterfromID("Petros"),"Turks_townhall", "goto", "goto5");
			ChangeCharacterAddressGroup(characterfromID("Catalina the Pirate"),"Turks_townhall", "goto", "goto1");
			ChangeCharacterAddressGroup(characterfromID("Morgan Terror"),"Turks_port", "goto", "T3_citizen03"); // JRH: new Turks
			pchar.quest.Morgan_talk = "Approach_Residence";
			Pchar.quest.to_find_Short_Jack_Gold2.win_condition.l1 = "location";
			PChar.quest.to_find_Short_Jack_Gold2.win_condition.l1.character = Pchar.id;
			Pchar.quest.to_find_Short_Jack_Gold2.win_condition.l1.location = "Turks_townhall";
			Pchar.quest.to_find_Short_Jack_Gold2.win_condition = "to_find_Short_Jack_Gold2";
			AddQuestRecord("Such Devoted Sisters",3);
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";
		break;

		case "Sailho_Blaze":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("Meet_Blaze_Guad3");
		break;
	}
}