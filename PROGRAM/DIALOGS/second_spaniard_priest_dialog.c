//#include "DIALOGS\second_spaniard_priest_dialog.h"
	
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

	if (PChar.sex == "man") Preprocessor_Add("addr", XI_ConvertString("my son"));
	else Preprocessor_Add("addr", XI_ConvertString("my child"));
	
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
			Dialog.snd = "voice\SESP\SESP001";
			
			dialog.text = GetCharacterFullName(DLG_TEXT[0]) + DLG_TEXT[1];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "haha";
		break;

		case "haha":
			Dialog.snd = "voice\SESP\SESP002";
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "buhbye";
			link.l2 = DLG_TEXT[5];
			link.l2.go = "haha2";
		break;

		case "haha2":
			LAi_QuestDelay("God_hit_us", 0.1);
			Dialog.snd = "voice\SESP\SESP003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "buhbye2";  // --> Cat
		break;
			
		case "buhbye":
			if(sti(GetStorylineVar(FindCurrentStoryline(), "JACK_SPARROW")) > 0)
			{
				AddQuestRecord("Sao Feng", 40);
			}
			else
			{
				AddDialogExitQuest("Story_Domingues_to_cave");
				AddQuestRecord("ANIMISTS", 40);
			}
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
		break;  
		
		case "buhbye2":
			if(sti(GetStorylineVar(FindCurrentStoryline(), "JACK_SPARROW")) > 0)
			{
				AddQuestRecord("Sao Feng", 40);
			}
			else
			{
				AddDialogExitQuest("Story_Domingues_to_cave");
				AddQuestRecord("ANIMISTS", 40);
			}
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
		break;  // <-- Cat

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
