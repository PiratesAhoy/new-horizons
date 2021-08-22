
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];

	Npchar.nation = Characters[getCharacterIndex("Marigot Commander")].nation;
	
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
			
			Dialog.text =  LinkRandPhrase(DLG_TEXT[0], DLG_TEXT[1], DLG_TEXT[2]);

			if(GetRMRelation(Pchar, sti(NPChar.nation) ) <= REL_WAR )
			{
				link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4];
				link.l1.go = "fight";

				link.l2 = DLG_TEXT[5];
				if(rand(40)+sti(pchar.skill.Sneak)>25) {Link.l2.go = "bribe"}
				else{Link.l2.go = "fight"}

				link.l3 = DLG_TEXT[6];
				if(rand(40)+sti(pchar.skill.Fencing)>30) {Link.l3.go = "sorry"}
				else{Link.l3.go = "fight"}

				if(NPchar.chr_ai.group !=  "SMUGGLERS_SOLDIERS" )
				{
				link.l4 = DLG_TEXT[7];
				if(rand(40)+sti(pchar.skill.leadership)>30) {Link.l4.go = "sorry"}
				else{Link.l4.go = "fight"}
				}
			}
			else
			{
				link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4];
				link.l1.go = "sorry";
			}
			Diag.TempNode = "first time";
		break;

		case "bribe":
			AddMoneytoCharacter(Pchar, -200);
			Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
		break;

		case "fight":
			Dialog.text = LinkRandPhrase(DLG_TEXT[10], DLG_TEXT[11], DLG_TEXT[12]);
			link.l1 = RandSwear() + DLG_TEXT[13] + RandSwear() + DLG_TEXT[14];
			link.l1.go = "exit_fight";
		break;

		case "Exit_fight":
		// PB: To prevent the fight from starting before the dialog is closed
			PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_039.wav");
			LAi_group_SetRelation(NPchar.chr_ai.group, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			int hp = sti(PChar.rank)*10 + rand(100) + 50;
			LAi_SetHP(NPchar, hp, hp);	// for more variation and challenge
			Ambush(SelectSoldierModelByNation(sti(npchar.nation), "Soldier"),  1+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "");

			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "sorry":
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			Dialog.text = DLG_TEXT[15];
			link.l2 = DLG_TEXT[16];
			link.l2.go = "harbour";
			link.l3 = DLG_TEXT[17];
			link.l3.go = "provisions";
		break;

		case "harbour":
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "raid";
		break;

		case "raid":
			Dialog.text = DLG_TEXT[20] + RandSwear() + DLG_TEXT[21];
			link.l1 = RandSwear() + DLG_TEXT[22];
			link.l1.go = "Exit_raid";
		break;

		case "provisions":
			Dialog.text = DLG_TEXT[23];
			link.l2 = DLG_TEXT[24];
			link.l2.go = "harbour";
		break;

		case "Exit_raid":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			LAi_CreateFantomGroup("Soldiers", 6, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, HOLLAND, OFFIC_TYPE_GUARD, 0, true, "", "", "", "");
			LAi_group_SetSayRadius(Npchar.chr_ai.group, 40000000.0);
			LAi_group_SetHearRadius(Npchar.chr_ai.group, 40000000.0);
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
