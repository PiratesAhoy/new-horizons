//#include "DIALOGS\Danielle_quests_pirate_dialog.h"
// Nikita
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
	
	switch(Dialog.CurrentNode)
	{
		// ESCORT VIGILA MENDES' SHIP + ZAID MURRO'S PROBLEMS
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			NextDiag.TempNode = "first time";

			dialog.snd = "Voice\DAQU\DAQU001";
			
			Preprocessor_Add("lad", GetMyAddressForm(NPChar, PChar, ADDR_INFORMAL, false, false)); // DeathDaisy
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (characters[GetCharacterIndex("Zaid Murro")].quest.bandits == "1")
			{
				dialog.snd = "Voice\DAQU\DAQU002";
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "bandits_1";
			}
			if (characters[GetCharacterIndex("Zaid Murro")].quest.bandits == "2")
			{
				dialog.snd = "Voice\DAQU\DAQU003";
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "exit";
				AddDialogExitQuest("fight_with_other_bandits_in_muelle_town_exit_3");
			}
//			if (pchar.quest.gambling_with_girl == "prisoned")
			if (CheckQuestAttribute("gambling_with_girl", "prisoned"))
			{
				dialog.snd = "Voice\DAQU\DAQU004";
				dialog.text = DLG_TEXT[6];
				link.l1 = DLG_TEXT[7];
				link.l1.go = "gambled_girl";
			}
		break;

		case "gambled_girl":
			dialog.snd = "Voice\DAQU\DAQU005";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "gambled_girl_exit";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "gambled_girl_2";
		break;

		case "gambled_girl_2":
			dialog.snd = "Voice\DAQU\DAQU006";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "gambled_girl_trade";
			link.l2 = DLG_TEXT[13];
			link.l2.go = "gambled_girl_sold";
			pchar.quest.gambling_with_girl = "5000";
		break;

		case "gambled_girl_trade":
			dialog.snd = "Voice\DAQU\DAQU007";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "gambled_girl_sold";
			pchar.quest.gambling_with_girl = "5500";
			link.l2 = DLG_TEXT[16];
			link.l2.go = "gambled_girl_exit";
		break;

		case "gambled_girl_sold":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			PlayStereoSound("INTERFACE\took_item.wav");
		//	AddMoneyToCharacter(pchar, pchar.quest.gambling_with_girl);		//JRH -->
		
			if ( CheckAttribute(Pchar,"quest.gambling_with_girl") )
			{
			    switch(Pchar.quest.gambling_with_girl)
			    {
				case "5000": AddMoneyToCharacter(pchar, 5000); break;
				case "5500": AddMoneyToCharacter(pchar, 5500); break;
			    }
			}
												//<-- JRH
			RemovePassenger(pchar, characterFromID("Virginie d'Espivant"));
			pchar.quest.gambling_with_girl = "done";
			OfficersReaction("bad");
			npchar.location = "none";
			AddQuestRecord("gambled_girl", 16);
			CloseQuestHeader("gambled_girl");
		break;

		case "gambled_girl_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			npchar.location = "none";
			AddQuestRecord("gambled_girl", 5);
		break;

		case "bandits_1":
			dialog.snd = "Voice\DAQU\DAQU008";
			dialog.text = DLG_TEXT[17];
			link.l1 = pcharrepphrase(DLG_TEXT[18], DLG_TEXT[19]);
			link.l1.go = "bandits_2";
		break;

		case "bandits_2":
			dialog.snd = "Voice\DAQU\DAQU009";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			AddDialogExitQuest("fight_with_bandits_in_muelle_town_exit");
		break;

		case "exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
