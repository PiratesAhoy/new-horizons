
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	string NPC_Meeting;
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	PChar.storekeeper.Idx = -1;//MAXIMUS
	ref lcn = &Locations[FindLocation(PChar.location)];
	
	Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
	
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
			Dialog.snd = "voice\PADI\PADI001";

			if(NPChar.quest.meeting == "0")
			{
				NPChar.itemtrade.quality = makeint(rand(sti(pchar.skill.commerce))+1);
				NPChar.itemtrade.tradetype = IT_TYPE_STALL;
				GiveItemToTrader(npchar);
				NPC_Meeting = "1"; 

				Dialog.text = LinkRandPhrase(DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + "?", DLG_TEXT[1], DLG_TEXT[2]);

				link.l3 = DLG_TEXT[3];
				link.l3.go = "shop";

				link.l9 = DLG_TEXT[4];
				link.l9.go = "exit";
			}
			else
			{
				Dialog.text = LinkRandPhrase(DLG_TEXT[5] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + "?", DLG_TEXT[6], DLG_TEXT[7]);

				link.l3 = DLG_TEXT[8];
				link.l3.go = "shop";

				link.l9 = DLG_TEXT[9];
				link.l9.go = "exit";
			}
		break;

		case "shop":
			NPC_Meeting = "1";

			if(rand(100)<10) // chance for random attack, decrease last figure for fewer attacks (GR: was 20)
			{
			 ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			 if(AUTO_SKILL_SYSTEM)
			 {
				 AddPartyExpChar(pchar, "Commerce", (1+sti(pchar.skill.fencing)) * 100);
				 AddPartyExpChar(pchar, "Sneak", (1+sti(pchar.skill.fencing)));
			 }
			 else { AddPartyExp(pchar, (1+sti(pchar.skill.fencing)) * 100); }
			 int sum = sti(pchar.skill.fencing) * 1000;
			 PlayStereoSound("INTERFACE\took_item.wav");
			 AddMoneyToCharacter(Pchar, sum);
//			Ambush("outlaws", 1+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			Ambush("outlaws", 1+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "reload1");
			 Dialog.text = DLG_TEXT[10] + sum + DLG_TEXT[11];
			 link.l1 = RandSwear() + DLG_TEXT[12];
			 link.l1.go = "exit";
			}
			else
			{
			 Dialog.Text = DLG_TEXT[13];
			 Link.l1 = DLG_TEXT[14];
			 Link.l1.go = "trade";
			 Link.l2 = DLG_TEXT[15];
			 Link.l2.go = "items";
			}
		break;

		case "trade":
			NPChar.quest.meeting = NPC_Meeting;

			DialogExit();
			PChar.storekeeper.Idx = sti(NPChar.index);//MAXIMUS
			LaunchStore(SMUGGLERS_STORE);
		break;

		case "items":
			NPChar.quest.meeting = NPC_Meeting;
			
			DialogExit();
			LaunchItemsTrade(NPChar);
		break;

		case "Exit":
			NPChar.quest.meeting = NPC_Meeting;

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
