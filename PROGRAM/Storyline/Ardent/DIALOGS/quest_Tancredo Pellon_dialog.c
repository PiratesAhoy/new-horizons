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

	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string strNow = iMonth + " " + iDay;
	
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

			Dialog.snd1 = "voice\USDI\USDI004";
			Dialog.snd2 = "voice\USDI\USDI005";
			Dialog.snd3 = "voice\USDI\USDI006";

			if(!CheckAttribute(NPChar, "AppearanceMod"))
			{
				NPChar.AppearanceMod.LastSpeakDate = strNow;
				dialog.Text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[2];
			}
			else
			{
				if (NPChar.AppearanceMod.LastSpeakDate != strNow)
				{
					NPChar.AppearanceMod.LastSpeakDate = strNow;
					dialog.Text = DLG_TEXT[3] + GetMyAddressForm(NPChar, PChar, ADDR_TITLE, false, true) + DLG_TEXT[4];
				}
				else dialog.Text = DLG_TEXT[3] + GetMyAddressForm(NPChar, PChar, ADDR_TITLE, false, true) + DLG_TEXT[5];
			}
			link.l1 = DLG_TEXT[6] + GetCharacterAddressForm(NPChar, ADDR_CIVIL, false, true) + DLG_TEXT[7];
			link.l1.go = "buy_dress";
		break;

		case "buy_dress":
			dialog.text = DLG_TEXT[8];
			if (sti(PChar.money >= 1000))
			{
				link.l1 = DLG_TEXT[9];
				link.l1.go = "pay_for_dress";
			}
			else
			{
				link.l1 = DLG_TEXT[10];
				link.l1.go = "dont_pay_for_dress";
			}
		break;

		case "pay_for_dress":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -1000);
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "try_dress";
		break;

		case "dont_pay_for_dress":
			dialog.text = DLG_TEXT[11] + DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "try_dress";
		break;

		case "try_dress":
			Diag.TempNode = "changing_room_reminder";
			dialog.text = DLG_TEXT[14];
			link.l1= DLG_TEXT[15];
			AddDialogExitQuest("go_to_changing_room");
			link.l1.go = "exit";
		break;

		case "changing_room_reminder":
			dialog.text = DLG_TEXT[16] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[17];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
		break;
	}
}