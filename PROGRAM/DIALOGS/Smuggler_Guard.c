void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;
	
	switch(Dialog.CurrentNode)
	{
		case "OpiumCaught":
			NPChar.opiumfine = getOpiumFine();
			d.Text = DLG_TEXT[0]+NPChar.opiumfine+DLG_TEXT[12];
			if(PChar.money >= sti(NPChar.opiumfine))
			{
				Link.l1 = DLG_TEXT[1];
				Link.l1.go = "return";
			}
			Link.l2 = DLG_TEXT[2];
			Link.l2.go = "bribe";
			if(CheckAttribute(Pchar,"quest.smuggling_guild.governor_quest.nation"))
			{
				if(CheckCharacterItem(Pchar,"smuggling_papers") && GetCurrentLocationNation() == sti(pchar.quest.smuggling_guild.governor_quest.nation))
				{
					Link.l3 = DLG_TEXT[9];
					Link.l3.go = "LookAtThis";
				}
			}
			Link.l4 = DLG_TEXT[3];
			Link.l4.go = "Exitfight";
		break;
		
		//Added by Levis for the smugglers guild -->
		case "LookAtThis":
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			d.Text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "Exit2";
		break;
		//Added by Levis for the smugglers guild <--
		
		case "return":
			TakeNItems(PChar,"opium", -sti(PChar.items.opium));
			AddMoneyToCharacter(PChar, -sti(NPChar.opiumfine));
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "Exit1";
		break;
		
		case "bribe":
			int chance = CalcCharacterSkill(PChar,SKILL_SNEAK)*10 * (1 - (GetDifficulty()*0.2));
			if(rand(100)<=chance && PChar.money >= 2*sti(NPChar.opiumfine))
			{
				//Succesfull bribe
				AddMoneyToCharacter(PChar, -2*sti(NPChar.opiumfine));
				d.Text = DLG_TEXT[7];
				Link.l1 = DLG_TEXT[8];
				Link.l1.go = "Exit2";
			}
			else
			{
				d.Text = DLG_TEXT[6];
				Link.l1 = DLG_TEXT[3];
				Link.l1.go = "Exitfight";
			}
		break;
		
		case "Exitfight":
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Opium Fight");
			DialogExit();
		break;
		
		case "Exit1":
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Opium Don't Fight");
			DialogExit();
		break;

		case "Exit2":
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Opium Bribe");
			DialogExit();
		break;
	}
}