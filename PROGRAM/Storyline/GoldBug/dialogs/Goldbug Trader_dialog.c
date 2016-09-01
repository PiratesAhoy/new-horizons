//#include "DIALOGS\Item Trader_dialog.h"
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
		case "exit":
			LAi_SetBarmanType(NPChar);
			Diag.CurrentNode = Diag.TempNode;
		//	NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
	
		break;

		case "Items":
			GiveItemToTrader(npchar);			
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();

			LaunchItemsTrade(NPChar);

			if(CheckAttribute(Pchar,"quest.trader_Pym_hint") && Pchar.quest.trader_Pym_hint == "yes")
			{

			}
			else LAi_QuestDelay("navigation_items", 0.5);
		break;

		case "First time":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			PlaySound("VOICE\ENGLISH\Eng_m_b_004.wav");
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Items";						
			Link.l2 = DLG_TEXT[2];
			Link.l2.go = "exit";						
		break;

		case "navigation_items":
			PlaySound("VOICE\ENGLISH\Eng_m_b_005.wav");
			Pchar.quest.trader_Pym_hint = "yes";
			d.Text = DLG_TEXT[16];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "navigation_items1";
		break;

		case "navigation_items1":
			PlaySound("VOICE\ENGLISH\Eng_m_b_003.wav");
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "navigation_items2";
		break;

		case "navigation_items2":
			PlaySound("VOICE\ENGLISH\Eng_m_b_006.wav");
			d.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "navigation_items3";
		break;

		case "navigation_items3":
			PlaySound("VOICE\ENGLISH\Eng_m_b_001.wav");
			d.Text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "exit";
			AddDialogExitQuest("shopping_1E");
		break;

		case "Pyms_house":
			PlaySound("VOICE\ENGLISH\Eng_m_b_003.wav");
			d.Text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "Pyms_house1";
		break;

		case "Pyms_house1":
			PlaySound("VOICE\ENGLISH\Eng_m_b_004.wav");
			d.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "Pyms_house2";
		break;

		case "Pyms_house2":
			PlaySound("VOICE\ENGLISH\Eng_m_b_002.wav");
			d.Text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "exit";
			AddDialogExitQuest("shopping_1G");
		break;

	}
}