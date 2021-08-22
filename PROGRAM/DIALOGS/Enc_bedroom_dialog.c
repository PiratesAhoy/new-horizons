//#include "DIALOGS\Enc_Bedroom_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	int NPC_Meeting;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			NextDiag.TempNode = "leave";
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			dialog.text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[2];
			Link.l1.go = "jewels";
			Link.l2 = DLG_TEXT[3];
			Link.l2.go = "reputation";
			Link.l3 = DLG_TEXT[1];
			Link.l3.go = "leave";

			if (CheckAttribute(PChar, "quest.defector_gemtype") && CheckCharacterItem(PChar, PChar.quest.defector_gemtype))
			{
				Preprocessor_Add("gem", GetItemNameByID(GetAttribute(PChar, "quest.defector_gemtype")));
				dialog.text = DLG_TEXT[6];
				Link.l1 = DLG_TEXT[8];
				link.l1.go = "return_gem";
				link.l2 = DLG_TEXT[9]
				Link.l3 = DLG_TEXT[7];
			}
		break;

		case "leave":
			if (CheckAttribute(PChar, "quest.defector_gemtype")) DeleteAttribute(PChar, "quest.defector_gemtype");
			dialog.text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "exit_ambush";
		break;

		case "exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "exit_ambush":
		// PB: To prevent the fight from starting before the dialog is closed
			Ambush("Rich_Citizens", 3, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "");
			Lai_group_MoveCharacter(NPChar, LAI_DEFAULT_GROUP);//MAXIMUS: if not - fighters will kill an NPC first
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "jewels":
			GiveItem2Character(pchar, "jewelry" + (1 + rand(15)));
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "reputation":
			NextDiag.TempNode = "exit_good";
			NextDiag.CurrentNode = NextDiag.TempNode;
			ChangeCharacterReputation(pchar, 1);
			if (CheckAttribute(PChar, "quest.defector_gemtype")) DeleteAttribute(PChar, "quest.defector_gemtype");
			DialogExit();
		break;

		case "return_gem":
			if(PChar.sex == "woman") Preprocessor_Add("gentleperson", XI_ConvertString("gentlewoman"));
			else Preprocessor_Add("gentleperson", XI_ConvertString("gentleman"));
			ChangeCharacterReputation(PChar, 5);
			NextDiag.TempNode = "exit_good";
			dialog.text = DLG_TEXT[10] + DLG_TEXT[rand(2) + 11] + DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			DeleteAttribute(PChar, "quest.defector_gemtype");
		break;

		case "exit_good":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			NextDiag.TempNode = "leave";
		break;
	}
}
// ccc <--
