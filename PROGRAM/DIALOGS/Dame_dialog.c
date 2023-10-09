//#include "DIALOGS\Dame_dialog.h"

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
	PChar.scarlett = 1;
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = "";
			link.l1 = DLG_TEXT[0] + GetMyName(NPChar) + DLG_TEXT[1];
			link.l1.go = "First time part 2";
		break;

		case "First time part 2":
			dialog.text = LinkRandPhrase(DLG_TEXT[2], DLG_TEXT[3], DLG_TEXT[4]);
			link.l1 = "";
			link.l1.go = "begin_1";
		break;
                 
		case "begin_1":
			TortugaDame1 = NPChar;
			Lai_SetActorType(TortugaDame1);
			LAi_ActorAnimation(TortugaDame1, "attack_2", "Dame_1", -1);
			LAi_SetCurHPMax(pchar); // PB: No need for them to kill you
			LAi_CharacterPlaySound(PChar, "OBJECTS\duel\punch"+sti(Rand(2)+1)+".wav");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "begin_2":
			TortugaDame2 = NPChar;
			dialog.text = LinkRandPhrase(DLG_TEXT[5], DLG_TEXT[6], DLG_TEXT[7]);
			link.l1 = LinkRandPhrase(DLG_TEXT[8], DLG_TEXT[9], DLG_TEXT[10]);
			link.l1.go = "begin_3";
		break;

		case "begin_3":
			Lai_SetActorType(TortugaDame2);
			LAi_ActorAnimation(TortugaDame2, "attack_2", "Dame_3", -1);
			LAi_SetCurHPMax(pchar); // PB: No need for them to kill you
			LAi_CharacterPlaySound(PChar, "OBJECTS\duel\punch"+sti(Rand(2)+1)+".wav");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "begin_4":
			dialog.text = LinkRandPhrase(DLG_TEXT[11], DLG_TEXT[12], DLG_TEXT[13]);
			link.l1 = LinkRandPhrase(DLG_TEXT[14], DLG_TEXT[15], DLG_TEXT[16]);
			link.l1.go = "begin_5";
		break;

		case "begin_5":
			Lai_SetActorType(TortugaDame3);
			LAi_ActorAnimation(TortugaDame3, "attack_2", "Dame_5", -1);
			LAi_SetCurHPMax(pchar); // PB: No need for them to kill you
			LAi_CharacterPlaySound(PChar, "OBJECTS\duel\punch"+sti(Rand(2)+1)+".wav");
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
