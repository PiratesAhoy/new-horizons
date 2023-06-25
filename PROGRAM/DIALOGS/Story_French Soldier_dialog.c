//#include "DIALOGS\Story_French Soldier_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча

		case "exit":
			NPChar.quest.meeting = NPC_meeting; 
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("fra_soldiers_in_oxbay_exit_returned_to_post");
		break;

		case "exit_fight":
			NPChar.quest.meeting = NPC_meeting; 
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("fight_before_enter_to_oxbay");
		break;

		case "first time":
			Dialog.snd = "voice\STFR\STFR001";
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "node_2";
			Link.l2 = DLG_TEXT[2];
			Link.l2.go = "node_3";
			Link.l3 = GetMyFullName(PChar) + DLG_TEXT[3];
			Link.l3.go = "exit_fight";
		break;

		case "node_2":
			Dialog.snd = "voice\STFR\STFR002";
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "node_3";
			Link.l2 = DLG_TEXT[6];
			Link.l2.go = "node_4";
			Link.l3 = GetMyFullName(PChar) + DLG_TEXT[7];
			Link.l3.go = "exit_fight";
		break;

		case "node_3":
			Dialog.snd = "voice\STFR\STFR003";
			d.Text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "exit_fight";
		break;

		case "node_4":
			if(CalcCharacterSkill(PChar,SKILL_LEADERSHIP) >= 3 || IsCharacterPerkOn(PChar,"Disguiser")) // NK, PW: Added disguise perk
			{
				Dialog.snd = "voice\STFR\STFR004";
				d.Text = DLG_TEXT[10] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[11];
				Link.l1 = DLG_TEXT[12];
				Link.l1.go = "exit";
			}
			else
			{
				Dialog.snd = "voice\STFR\STFR005";
				d.Text = DLG_TEXT[13];
				Link.l2 = DLG_TEXT[14]);
				Link.l2.go = "exit_fight";
			}
		break;
	}
}

