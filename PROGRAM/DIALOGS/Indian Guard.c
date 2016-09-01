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
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			dialog.snd = "Voice\ARGU\ARGU001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "First time";
			link.l2 = DLG_TEXT[2];
			link.l2.go = "First time";
			if(CheckAttribute(PChar,"quest.smuggle_collector.collect_bows"))
			{
				link.l3 = DLG_TEXT[8];
				link.l3.go = "Get Weapon 1";
			}
			link.l4 = DLG_TEXT[3];
			link.l4.go = "Exit";
		break;
		
		case "Get Weapon 1":
			dialog.text = DLG_TEXT[0];
			if(CalcCharacterSkill(PChar,SKILL_FENCING) > 4)
			{
				link.l1 = DLG_TEXT[9];
				link.l1.go = "Get Weapon 2";
			}
			else
			{
				link.l1 = DLG_TEXT[15];
				link.l1.go = "Exit provocation";
			}
		break;
		
		case "Get Weapon 2":
			dialog.text = DLG_TEXT[0];
			if(CalcCharacterSkill(PChar,SKILL_COMMERCE) > 5)
			{
				link.l1 = DLG_TEXT[10];
				link.l1.go = "Get Weapon 3";
			}
			else
			{
				link.l1 = DLG_TEXT[15];
				link.l1.go = "Exit provocation";
			}
		break;
		
		case "Get Weapon 3":
			dialog.text = DLG_TEXT[0];
			if(CalcCharacterSkill(PChar,SKILL_SNEAK) > 6)
			{
				link.l1 = DLG_TEXT[11];
				link.l1.go = "Get Weapon 4";
			}
			else
			{
				link.l1 = DLG_TEXT[15];
				link.l1.go = "Exit provocation";
			}
		break;
		
		case "Get Weapon 4":
			dialog.text = DLG_TEXT[0];
			if(pchar.money >= 200)
			{
				link.l1 = DLG_TEXT[12];
				link.l1.go = "Get Weapon 5";
			}
			else
			{
				link.l1 = DLG_TEXT[15];
				link.l1.go = "Exit provocation";
			}
		break;
		
		case "Get Weapon 5":
			TakenItems(NPChar,"pistolbow",-1);
			TakenItems(pchar,"pistolbow",1);
			AddMoneyToCharacter(PChar, -200);
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "Exit";
		break;
		
		case "Exit provocation":
			DialogExit();
			LAi_SetGuardianType(NPChar);
			NextDiag.CurrentNode = NextDiag.TempNode;
			LAi_group_Attack(pchar, NPChar);
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "Following":
			AddDialogExitQuest("Apothecary Found Follow");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "First Time";
		break;
		
		case "Spotted warehouse":
			AddDialogExitQuest("Apothecary seen by guard warehouse");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
		break;
	}
}
