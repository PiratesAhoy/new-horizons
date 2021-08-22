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
			dialog.text = GetMyName(NPChar) + "! How are you?";
			link.l1 = LinkRandPhrase("Why have you been away so long?", "I thought you'd never come back.", "Fine. But no thanks to you.");
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
			dialog.text = LinkRandPhrase("Who was she?", "Do you know her?", "I thought I was the only one for you. Who is that?");
			link.l1 = LinkRandPhrase("Who?", "What are you talking about?", "Who do you mean?");
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
			dialog.text = LinkRandPhrase("Who were they?", "Do you know them?", "I thought I was the only one for you. Who are they??");
			link.l1 = LinkRandPhrase("WHO?", "What the HECK are you all talking about?", "I don't know either of them. And I don't know you either.");
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
