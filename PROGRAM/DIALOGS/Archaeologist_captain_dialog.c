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
	int FdeFNation = GetTownNation("Falaise de Fleur");
	string FdeFnationDesc = GetNationDescByType(FdeFNation);
	
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

		case "introduction":
			dialog.text = DLG_TEXT[2] + GetMyFullName(NPChar) + DLG_TEXT[3];
			if (LAi_isDead(characterFromID("Carib_Warrior"))) link.l1 = DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[6];
			else link.l1 = DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[5] + GetMyFullName(CharacterFromID("Carib_Warrior")) + DLG_TEXT[6];
			link.l1.go = "I_have_cannon";
		break;

		case "I_have_cannon":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "insurance";
		break;

		case "insurance":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "money";
		break;

		case "money":
			Preprocessor_Add("person", GetAddressForm(ADDR_INFORMAL, ENGLAND, chrsex(PChar)));
			Preprocessor_Add("nationdesc", FdeFnationDesc);
			dialog.text = DLG_TEXT[11];
			if (!LAi_isDead(characterFromID("Carib_Warrior")))
			{
				link.l1 = DLG_TEXT[12];
				AddDialogExitQuest("crysskull_carib_warrior_refuses_skull");
				link.l1.go = "exit";
			}
			else
			{
				link.l1 = DLG_TEXT[12] + DLG_TEXT[15];
				link.l1.go = "wise_choice";
			}
		break;

		case "wise_choice":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14] + GetMyLastName(NPChar) + ".";
			if (CheckCharacterItem(PChar, "cryskull"))
			{
				PlayStereoSound("INTERFACE\important_item.wav");
				TakeItemFromCharacter(PChar, "cryskull");
				GiveItem2Character(characterFromID("Archaeologist_captain"), "cryskull");
			}
			AddDialogExitQuest("crysskull_enemy_captain_leaves");
			link.l1.go = "exit";
		break;
	}
}