//#include "DIALOGS\Garda_dialog.h"

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
			
                        dialog.snd = "Voice\CLLA\CLLA001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "begin";
                       PlayStereoSound("VOICE\ENGLISH\Eng_m_c_009.wav");
                       break;

		case "begin":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "begin_2";
			LAi_SetOfficerType(characterFromID("Roxanne Lalliere"));

		break;

		case "begin_2":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";
			LAi_group_FightGroups("SHORE_GARDAS", LAI_GROUP_PLAYER, true);
			LAi_group_SetCheck("SHORE_GARDAS", "directbarco");

		break;


		case "begin_3":

			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "begin_4";
                       PlayStereoSound("VOICE\ENGLISH\Eng_m_a_058.wav");
		break;

		case "begin_4":

			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
                        LAi_SetPlayerType(pchar);
			LAi_SetOfficerType(characterFromID("Roxanne Lalliere"));
                        LAi_type_actor_Reset(characterFromID("garda3"));
                        AddDialogExitQuest("directbarco4");

		break;



              
               case "Exit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		

                       break;



	}
}
