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
		case "Sell Bows":
			dialog.text = DLG_TEXT[1];
			Link.l1 = DLG_TEXT[2];
			Link.l1.go = "Agree Sell Bows";
			Link.l2 = DLG_TEXT[3];
			Link.l2.go = "Decline Sell Bows";
		break;
		
		case "Decline Sell Bows":
			dialog.text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "exit bows";
		break;
		
		case "Agree Sell Bows":
			AddDialogExitQuest("Finish Collector Quest Smugglers");
			dialog.text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "exit bows";
		break;
		
		case "exit bows":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
		
		//default:
		if(CheckAttribute(PChar,"quest.smuggle_collector.meet_buyer") && sti(PChar.items.pistolbow) >= 10)
		{
			Link.l1 = DLG_TEXT[0];
			Link.l1.go = "Sell Bows";
		}
	}
}
