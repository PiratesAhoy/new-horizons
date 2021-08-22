//#include "DIALOGS\soldier2.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
	// -----------------------------------Диалог первый - первая встреча
		case "First time":
// NK -->
			if(CheckAttribute(pchar, "quest.Attwood1.MWtalk"))
			{
				DeleteAttribute(pchar, "quest.Attwood1.MWtalk");
				LAi_QuestDelay("Att_resit", 0.001); // NK
				DialogExit();
			}
// NK <--
			Dialog.defAni = "Gov_Dialog_1";
			Dialog.ani = "Gov_Dialog_2";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[2];
			Link.l2.go = "meeting";
			NPChar.greeting = ""; // NK
		break;

		case "meeting":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -500); // NK
			d.Text = DLG_TEXT[3];
			Link.l1 = DLG_TEXT[4];
			Link.l1.go = "exit1";
		break;

		case "meeting1":
			Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
			d.Text = DLG_TEXT[5] + DLG_TEXT[7]; // NK
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "exit2";
		break;

		case "exit":
// NK -->
			LAi_QuestDelay("stand_up", 0.5);
			Diag.CurrentNode = "First time";
			LAi_SetActorType(CharacterFromID("Martin Warner"));
			LAi_SetSitType(CharacterFromID("Martin Warner"));
			pchar.quest.Attwood1.MWtalk = 1;
// NK <--
			DialogExit();
		break;	
		
		case "exit1":
			LAi_QuestDelay("soldier_in_tavern3", 0.1); // NK
			Diag.CurrentNode = "meeting1";
			DialogExit();
		break;	

		case "exit2":
// NK -->
			pchar.quest.Attwood1.leave = 1;
			LAi_QuestDelay("stand_up", 1.0);
			SetCharacterShipLocation( Pchar, "Redmond_port" );
	
			Group_CreateGroup("Jack Greenfield");
			Group_AddCharacter("Jack Greenfield", "Jack Greenfield");
			ref jg = CharacterFromID("Jack Greenfield");
			jg.nosurrender = 2; // 05-07-06 no surrender at sea. Makes life easier. // KK
			Group_SetGroupCommander("Jack Greenfield", "Jack Greenfield");
			Group_SetTaskMove("Jack Greenfield", 10000, 10000);
			Group_SetPursuitGroup("Jack Greenfield", PLAYER_GROUP);
			Group_SetAddress("Jack Greenfield", "redmond", "", "");
			Pchar.quest.Battle.win_condition.l1 = "NPC_Death";
			Pchar.quest.Battle.win_condition.l1.character = "Jack Greenfield";
			PChar.quest.Battle.win_condition = "list_Attwood";
// NK <--
			Diag.CurrentNode = "meeting1";
			DialogExit();
		break;	
	}
}
