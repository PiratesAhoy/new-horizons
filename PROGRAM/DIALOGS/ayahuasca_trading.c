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
		// -----------------------------------Диалог первый - первая встреча
		case "node_3":
			Link.l1 = DLG_TEXT[0]; 
			Link.l1.go = "Buy";
		break;

		case "Buy":
			int sold = 1;
			if(CheckAttribute(NPChar,"ayahuasca.sold")) { sold = sti(NPChar.ayahuasca.sold); } 
			else { NPChar.ayahuasca.sold = 0; }
			NPChar.price = sold*500 + 1000;
			dialog.text = DLG_TEXT[1]+NPChar.price+ DLG_TEXT[2]; 
			Link.l1 = DLG_TEXT[3]
			Link.l1.go = "Exit";
			if(pchar.money > (sti(NPChar.price)*1))
			{
				Link.l2 = DLG_TEXT[4]
				Link.l2.go = "Buy1";
			}
		break;

		case "Buy1":
			TakeNItems(PChar, "ayahuasca", 1);
			AddMoneyToCharacter(PChar, -1*sti(NPChar.price)*1);
			NPChar.ayahuasca.sold = sti(NPChar.ayahuasca.sold)+1;
			PlayStereoSound("INTERFACE\took_item.wav");
			dialog.text = DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6]
			Link.l1.go = "Exit";
		break;
	}
}
