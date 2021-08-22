//#include "DIALOGS\Lucas Da Saldanha_dialog.h"
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
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";

		break;

		case "free":

				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "Exit_talk1_end";

		break;

		case "free_fight":

				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "Exit_talk1_fight_end";

		break;

		case "free1":

			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7] + GetMySimpleName(PChar) + DLG_TEXT[8];
			link.l1.go = "free2";

		break;

		case "free2":

			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "free3";

		break;

		case "free3":

			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "Exit_talk2_end";

		break;

		case "join":

			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "Exit_join";
			link.l2 = DLG_TEXT[15];
			link.l2.go = "no_join";

		break;

		case "no_join":

			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Exit_no_join";

		break;

		case "join_loop":

			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_join";
			link.l2 = DLG_TEXT[20];
			link.l2.go = "Exit_join_loop";
		break;
		
		case "concern":
		
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22] + Characters[GetCharacterIndex(DLG_TEXT[23])].name + DLG_TEXT[24];
			link.l1.go = "concern1";
			
		break;
		
		case "concern1":
		
			dialog.text = DLG_TEXT[25] + Characters[GetCharacterIndex(DLG_TEXT[26])].lastname + DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "Exit_Cayman";
			link.l2 = DLG_TEXT[29];
			link.l2.go = "Exit_No_Cayman";
			
		break;
		
		case "Governer":
		
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit_change";
			
		break;
		
		case "Find_Shaw":
		
			dialog.text = DLG_TEXT[32] + Characters[GetCharacterIndex(DLG_TEXT[33])].name + DLG_TEXT[34];
			link.l1 = DLG_TEXT[35] + Characters[GetCharacterIndex(DLG_TEXT[36])].name;
			link.l1.go = "Exit_Gov";
			
		break;

		case "poem_1":

			/*
			Усталые глаза почти не видят
			Сиянья звезд в манящей вышине.
			Их свет холодный можно ненавидеть,
			А можно просто взять себе.

			Соткать из льдистых нитей покрывало,
			Ему доверив сокровенность снов,
			А если этого окажется вдруг мало -
			Порвать его на бессполезность слов.

			Сорвать цветок, в подарок своей Даме,
			А по пути - швырнуть его куда-то в грязь.
			Сменить стихи на меч, и рваться к славе,
			А после удивляться - как же низко можно пасть.

			Свой наточить клинок, готовясь к бою...
			И спрятать в ножны, испугавшись боли.
			*/

		break;

		case "Exit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

		break;

		case "Exit_free1":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Lucas_talk1_1");

		break;

		case "Exit_talk1_end":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Lucas_talk1_1");

		break;

		case "Exit_talk2_end":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Lucas_talk2_1");

		break;

		case "Exit_talk1_fight_end":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Lucas_fight_talk1_1");

		break;

		case "Exit_join":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Lucas_join");

		break;

		case "Exit_no_join":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Lucas_no_join");

		break;

		case "Exit_join_loop":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "join_loop";

		break;
		
		case "Exit_Cayman":
		
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			
			Pchar.quest.meet_Maggee.win_condition.l1 = "location";
			Pchar.quest.meet_Maggee.win_condition.l1.character = "Lucas Da Saldanha";
			Pchar.quest.meet_Maggee.win_condition.l1.location = "Falaise_de_Fleur_port_01";
			PChar.quest.meet_Maggee.win_condition = "meet_Maggee";
			
			RemovePassenger(pchar, characterFromID("Lucas Da Saldanha"));
			AddDialogExitQuest("reset_Lucas");
			
			//JOURNAL
			AddQuestRecord("Lucas", 15);
		
		break;
		
		case "Exit_No_Cayman":
		
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			
			RemovePassenger(pchar, characterFromID("Lucas Da Saldanha"));
			AddDialogExitQuest("reset_Lucas");
			
			//JOURNAL
			CloseQuestHeader("Lucas");
			AddQuestRecord("Lucas", 16);
			
		break;
		
		case "Exit_change":
		
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		
			LAi_ActorGoToLocation(CharacterFromID("Lucas Da Saldanha"), "officers", "falaise_de_fleur_location_01_05_2", "none","","","", 100.0);
			RemovePassenger(pchar, characterFromID("Lucas Da Saldanha"));
			
			AddDialogExitQuest("reset_Lucas");
		break;
		
		case "Exit_Gov":
		
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			
			AddDialogExitQuest("Contact_Gov");
			
		break;

	}
}
