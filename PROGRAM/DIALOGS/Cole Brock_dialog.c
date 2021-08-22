//#include "DIALOGS\Cole Brock_dialog.h"
void ProcessDialogEvent() //Mosh D33
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	ref PChar;
	PChar = GetMainCharacter();
	
	// DeathDaisy: Persuasion tags for the skill checks, if enabled
	string PersuasionSuccess = "";
	string PersuasionFailure = "";
	if(PERSUASION_TAGS){ 
		PersuasionSuccess = XI_ConvertString("Persuasion_Success") + " ";
		PersuasionFailure = XI_ConvertString("Persuasion_Failure") + " ";
	}

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "Exit":
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

			NextDiag.TempNode = "First time";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if(CheckQuestAttribute("RheimsBook","11"))
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "Node_1";
			}
			if( CheckAttribute(PChar,"quest.RheimsBook") && sti(PChar.quest.RheimsBook) > 11 )
			{
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "Exit";
			}
		break;

		case "node_1":
			if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) > 5)
			{
				dialog.text = PersuasionSuccess + DLG_TEXT[6];
				link.l1 = DLG_TEXT[7];
				link.l1.go = "Exit";
				Pchar.quest.RheimsBook = "escape_from_prison";//For Mosh D34
				AddDialogExitQuest("DamielleWarderSwindle");
			}
			else
			{
				dialog.text = PersuasionFailure + DLG_TEXT[8];
				link.l1 = DLG_TEXT[9];
				link.l1.go = "node_2";
			}
		break;

		case "node_2":
			if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) >3)
			{
				dialog.text = PersuasionSuccess + DLG_TEXT[10];
				link.l1 = DLG_TEXT[11];
				link.l1.go = "exit";
				Pchar.quest.RheimsBook = "escape_from_prison";//For Mosh D34
				AddDialogExitQuest("DamielleWarderSwindle");
			}
			else
			{
				dialog.text = PersuasionFailure + DLG_TEXT[12];
				link.l1  = DLG_TEXT[13];
				link.l1.go = "exit";
				AddDialogExitQuest("second_guard");
				pchar.quest.RheimsBook = "second_guard";//For Mosh D34
				AddDialogExitQuest("second_guard");
			}
		break;

		/*case "Node_1":
			dialog.text = "Сейчас я с ним разберусь!!!";
			link.l1 = "Быстрее пожалуйста!!";
			link.l1.go = "Exit";
			Pchar.quest.RheimsBook = "12";//For Mosh D34
			AddDialogExitQuest("DamielleWarderSwindle");
		break;
		*/
	}
};