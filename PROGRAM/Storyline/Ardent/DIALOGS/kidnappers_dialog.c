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
			link.l1.go = "Exit";
		break;

		case "negotiate":
			string agent_fate = DLG_TEXT[6] + GetMyFullName(CharacterFromID("Jaime Lezcano")) + DLG_TEXT[7];
			if (LAi_IsDead(CharacterFromID("Jaime Lezcano"))) agent_fate = GetMyFullName(CharacterFromID("Jaime Lezcano")) + DLG_TEXT[4];
			if (IsPrisoner(CharacterFromID("Jaime Lezcano"))) agent_fate = GetMyFullName(CharacterFromID("Jaime Lezcano")) + DLG_TEXT[5];
			dialog.text = DLG_TEXT[2] + GetMySimpleName(CharacterFromID("Jaime Lezcano")) + DLG_TEXT[3];
			link.l1 = agent_fate+ DLG_TEXT[8] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[9];
			link.l1.go = "negotiate2";
		break;

		case "negotiate2":
			dialog.text = DLG_TEXT[10];
			if (CheckQuestAttribute("alignment", "evil")) link.l1 = DLG_TEXT[13] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[14] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[15];
			else link.l1 = DLG_TEXT[11] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[12];
			link.l1.go = "negotiate3";
		break;

		case "negotiate3":
			int diceroll = RAND(5)+RAND(5)+2;
			if (LAi_IsDead(CharacterFromID("Jaime Lezcano"))) diceroll = diceroll + 1;		// More difficult to get them to surrender if Jaime Lezcano is dead because you killed him after going outside to talk
//			traceandlog("Leadership = " + CalcCharacterSkill(PChar, SKILL_LEADERSHIP) + ", Difficulty = " + GetDifficulty() + ", Dice roll = " + diceroll);
			if (CalcCharacterSkill(PChar, SKILL_LEADERSHIP) >= GetDifficulty() - 1 + diceroll)	// Randomised, passes if 2D6<=7, leadership 9, difficulty "Seadog", Jaime Lezcano alive
			{
				dialog.text = DLG_TEXT[19];
				link.l1 = DLG_TEXT[20];
				link.l1.go = "negotiate4";
				if (CheckQuestAttribute("alignment", "evil"))
				{
					if (CheckAttribute(PChar, "quest.imperial_escort.cave_climber")) link.l2 = DLG_TEXT[18];
					else link.l2 = DLG_TEXT[17];
					link.l2.go = "exit_fight";
				}
			}
			else
			{
				dialog.text = DLG_TEXT[16];
				if (CheckAttribute(PChar, "quest.hiding_officer")) link.l1 = DLG_TEXT[18];
				else link.l1 = DLG_TEXT[17];
				link.l1.go = "exit_fight";
			}
		break;

		case "negotiate4":
			Preprocessor_Add("person", PChar.sex);
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "exit_surrender";
			if (CheckQuestAttribute("alignment", "evil"))
			{
				if (CheckAttribute(PChar, "quest.hiding_officer")) link.l2 = DLG_TEXT[18];
				else link.l2 = DLG_TEXT[17];
				link.l2.go = "exit_fight";
			}
		break;

		case "exit_surrender":
			AddDialogExitQuest("imperial_escort_surrender_in_cave");
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
		break;

		case "exit_fight":
			AddDialogExitQuest("imperial_escort_fight_in_cave");
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
		break;
	}
}