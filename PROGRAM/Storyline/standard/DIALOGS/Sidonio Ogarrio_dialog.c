//#include "DIALOGS\Sidonio Ogarrio_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d; 
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_meeting;
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
			Dialog.snd = "voice\SIOG\SIOG001";
			Diag.TempNode = "First time";
			d.Text = DLG_TEXT[0];

			if(GetAttribute(CharacterFromID("Wilfred Bythesea"), "quest.kill_Ogarrio") == "wait")
			{
				link.l1 = DLG_TEXT[2] + GetMyFullName(CharacterFromID("Wilfred Bythesea")) + ".";
				link.l1.go = "Fight";
			}
			link.l2 = DLG_TEXT[1];
			link.l2.go = "Exit";
		break;

		case "Fight":
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "Fight2";
		break;

		case "Fight2":
			Preprocessor_Add("person", XI_ConvertString(PChar.sex));
			Preprocessor_Add("pronoun3", XI_ConvertString(GetMyPronounPossessive(PChar)));
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			AddDialogExitQuest("kill_Ogario_fight");
			link.l1.go = "exit";
		break;
	}

}
