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

			dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_TITLE, false, true) + DLG_TEXT[1];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "imperial_escort_want_disguise";
		break;

		case "imperial_escort_want_disguise":
			dialog.text = DLG_TEXT[3];
			if(PChar.sex == "woman") link.l1 = DLG_TEXT[5];
			else link.l1 = DLG_TEXT[4];
			link.l1.go = "imperial_escort_youre_in_luck";
		break;

		case "imperial_escort_youre_in_luck":
			if(PChar.sex == "woman") dialog.text = DLG_TEXT[6] + DLG_TEXT[8] + DLG_TEXT[9] + XI_ConvertString(GetMyPronounSubj(PChar)) + DLG_TEXT[10];
			else dialog.text = DLG_TEXT[6] + DLG_TEXT[7] + DLG_TEXT[9] + XI_ConvertString(GetMyPronounSubj(PChar)) + DLG_TEXT[10];
			if(sti(PChar.money) >= 2000)
			{
				NPChar.quest.disguise_price = 2000;
				link.l1 = DLG_TEXT[11];
				link.l1.go = "imperial_escort_disguise_deal";
			}
			if(sti(PChar.money) >= 1000 && CalcCharacterSkill(PChar, SKILL_COMMERCE) >= 5)
			{
				link.l2 = DLG_TEXT[12];
				link.l2.go = "imperial_escort_disguise_haggle";
			}
			else
			{
				link.l2 = DLG_TEXT[13];
				link.l2.go = "exit";
			}
		break;

		case "imperial_escort_disguise_haggle":
			NPChar.quest.disguise_price = 1500;
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "imperial_escort_disguise_deal";
			link.l2 = DLG_TEXT[16];
			link.l2.go = "exit";
		break;

		case "imperial_escort_disguise_deal":
			int price = sti(NPChar.quest.disguise_price);
			dialog.text = DLG_TEXT[17] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "imperial_escort_get_outfit_now";
			link.l2 = DLG_TEXT[20];
			link.l2.go = "imperial_escort_get_outfit_bagged";
		break;

		case "imperial_escort_get_outfit_now":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -1 * sti(NPChar.quest.disguise_price));
			DeleteAttribute(NPChar, "quest.disguise_price");
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			AddDialogExitQuest("imperial_escort_restore_tortuga_tailor");
			link.l1.go = "exit"
			if(PChar.sex == "woman") GiveModel2Player("ArdentF_2", true);
			else GiveModel2Player("ArdentM_2", true);
		break;

		case "imperial_escort_get_outfit_bagged":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -1 * sti(NPChar.quest.disguise_price));
			DeleteAttribute(NPChar, "quest.disguise_price");
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			AddDialogExitQuest("imperial_escort_restore_tortuga_tailor");
			link.l1.go = "exit"
			if(PChar.sex == "woman") GiveModel2Player("ArdentF_2", false);
			else GiveModel2Player("ArdentM_2", false);
		break;
	}
}