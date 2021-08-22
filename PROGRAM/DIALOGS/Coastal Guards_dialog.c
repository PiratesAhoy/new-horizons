//#include "DIALOGS\Coastal Guards_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d, her;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча

		case "exit":
			StopCoastalGuardPursuit();
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			LAi_SetPlayerType(Pchar);
		break;

		case "First time":
			dialog.snd = "Voice\COGU\COGU001";
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];

			LAi_LocationFightDisable(&Locations[FindLocation(pchar.location)], false); // ccc you can fight again

			/* ccc stormy start, IMHO this was too predictable, so I added a random factor
			ccc, if you don't agree delete the 4 lines marked with ccc but keep the original one below
			if(makeint(Pchar.reputation) >= 80 && makeint(Pchar.skill.Leadership) >= 5)	// original code
			ccc */
			if(makeint(Pchar.reputation) + (makeint(Pchar.skill.Leadership)*10) >= rand(200) && GetNationRelation2MainCharacter(sti(Npchar.nation)) != RELATION_ENEMY)	// ccc new
			{
				Link.l1.go = "ThisTimeFree";
			}
			else
			{
				Link.l1.go = "IDontBelieveYou";
			}
			Link.l2 = DLG_TEXT[2];

			/* ccc stormy start, IMHO this was too predictable, so I added a random factor
			ccc, if you don't agree delete the 4 lines marked with ccc but keep the original one below
			if(makeint(Pchar.rank) >= 4 && makeint(Pchar.skill.Commerce) >= 5)	// original code
			ccc */
			if(makeint(Pchar.skill.sneak) >= rand(12) )	// ccc new
			{
				Link.l2.go = "GiveMeSomeMoneyToo";
			}
			else
			{
				Link.l2.go = "TryingToGiveBribe";
			}
			Link.l3 = DLG_TEXT[3];
			if(makeint(Pchar.reputation) <= 10 && makeint(Pchar.skill.Fencing) >= 8)
			{
				Link.l3.go = "GettingLostFromHere";
			}
			else
			{
				Link.l3.go = "howDareYou";
			}
			if(CheckAttribute(PChar,"quest.smuggling_guild.governor_smuggling.nation"))
			{
				if(CheckCharacterItem(PChar,"smuggling_papers") && GetSmugglingNation() == sti(PChar.quest.smuggling_guild.governor_smuggling.nation))
				{
					Link.l4 = DLG_TEXT[29];
					Link.l4.go = "LookAtThis";
				}
			}
		break;
		
		//Added by Levis for the smugglers guild -->
		case "LookAtThis":
			pchar.quest.smuggling_guild.governor_quest.usedpaper = true;
			TakeItemFromCharacter(pchar,"smuggling_papers");	// GR: take the papers so you can't keep smuggling to the same nation forever
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			d.Text = DLG_TEXT[30];
			Link.l1 = DLG_TEXT[31];
			Link.l1.go = "exit";
			AddDialogExitQuest("Remove Coast Guard"); 
		break;
		//Added by Levis for the smugglers guild <--

		case "ThisTimeFree":
			dialog.snd = "Voice\COGU\COGU002";		
			Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
			d.Text = DLG_TEXT[4] + GetMyName(Pchar) + DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "ThisTimeFree_1";
			Link.l2 = DLG_TEXT[7];
			Link.l2.go = "ThisTimeFree_fight";				
		break;

		case "ThisTimeFree_1":	
			dialog.snd = "Voice\COGU\COGU003";	
			ChangeCharacterReputation(pchar, -40);
			d.Text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "ThisTimeFree_exit";
		break;

		case "ThisTimeFree_fight":			
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();

		//	Pchar.quest.Rand_ContrabandInterruptionAtSeaEnded.win_condition.l1 = "MapEnter";
		//	Pchar.quest.Rand_ContrabandInterruptionAtSeaEnded.win_condition = "Rand_ContrabandInterruptionAtSeaEnded";
			ChangeRMRelation(Pchar, GetSmugglingNation(), -10); // PB: was UpdateRMRelation
			
			LAi_group_FightGroups("Smugglers", "CoastalGuards", true);
			LAi_group_FightGroups(LAI_GROUP_PLAYER, "CoastalGuards", true);
			LAi_group_SetAlarmReaction(LAI_GROUP_PLAYER,"Smugglers",LAI_GROUP_FRIEND, LAI_GROUP_FRIEND); //Levis: now you can hit smugglers by accident

			LAi_SetPlayerType(Pchar);

			trace("And we fight those soldiers!!" + Pchar.quest.contraband.CurrentPlace);
		break;

		case "ThisTimeFree_exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();

			ChangeSmugglerLiking(pchar, -20);

			StopCoastalGuardPursuit();

			LAi_group_FightGroups("Smugglers", "CoastalGuards", true);
			LAi_group_SetAlarmReaction(LAI_GROUP_PLAYER,"CoastalGuards",LAI_GROUP_FRIEND, LAI_GROUP_FRIEND); //Levis: now you can hit guards by accident
			LAi_SetPlayerType(Pchar);
		break;

		case "IDontBelieveYou":
			dialog.snd = "Voice\COGU\COGU004";
			d.Text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "ThisTimeFree_fight";
		break;

		case "GiveMeSomeMoneyToo":	
			dialog.snd = "Voice\COGU\COGU005";		
			d.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13] + makeint(sti(Pchar.money)/10) + DLG_TEXT[14] ;
			if(makeint(Pchar.rank)*1000 <= makeint(sti(Pchar.money)/10))
			{
				Link.l1.go = "MoneyAccepted10";
			}
			else
			{
				Link.l1.go = "TryingToGiveBribe";
			}

			Link.l2 = DLG_TEXT[15] + makeint(sti(Pchar.money)/5) + DLG_TEXT[16];
			if(makeint(Pchar.rank)*1000 <= makeint(sti(Pchar.money)/5))
			{
				Link.l2.go = "MoneyAccepted5";
			}
			else
			{
				Link.l2.go = "TryingToGiveBribe";
			}

			Link.l3 = DLG_TEXT[17] + makeint(sti(Pchar.money)/2) + DLG_TEXT[18];
			if(makeint(Pchar.rank)*1000 <= makeint(sti(Pchar.money)/2))
			{
				Link.l3.go = "MoneyAccepted2";
			}
			else
			{
				Link.l3.go = "TryingToGiveBribe";
			}
		break;

		case "TryingToGiveBribe":
			dialog.snd = "Voice\COGU\COGU006";
			d.Text = DLG_TEXT[19];
			Link.l1 = DLG_TEXT[20];
			Link.l1.go = "ThisTimeFree_fight";
		break;

		case "MoneyAccepted":
			dialog.snd = "Voice\COGU\COGU007";
			d.Text = DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "ThisTimeFree_fight";
		break;

		// ccc stormy start; bribing NEVER worked cause "MoneyAccepted" leads to a fight! Sloppy Akella! 
		// Or righteous Disney censorship? Added three new cases instead:

		case "MoneyAccepted10":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, - makeint(sti(Pchar.money)/10));
			d.Text = DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "ThisTimeFree_exit";
		break;

		case "MoneyAccepted5":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, - makeint(sti(Pchar.money)/5));
			d.Text = DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "ThisTimeFree_exit";
		break;

		case "MoneyAccepted2":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(Pchar, - makeint(sti(Pchar.money)/2));
			d.Text = DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "ThisTimeFree_exit";
		break;
		// ccc end

		case "GettingLostFromHere":
			dialog.snd = "Voice\COGU\COGU008";
			d.Text = DLG_TEXT[23];
			Link.l1 = DLG_TEXT[24];
			Link.l1.go = "GettingLostFromHere_1";
		break;

		case "GettingLostFromHere_1":
			dialog.snd = "Voice\COGU\COGU009";
			d.Text = DLG_TEXT[25];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "GettingLostFromHere_exit";
		break;

		case "GettingLostFromHere_exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();

			StopCoastalGuardPursuit();
			LAi_ActorRunToLocation(&Characters[Pchar.quest.contraband.SoldierIDX1], "reload", "Reload1", "none", "", "", "", 120);
			LAi_ActorRunToLocation(&Characters[Pchar.quest.contraband.SoldierIDX2], "reload", "Reload1", "none", "", "", "", 120);
			LAi_ActorRunToLocation(&Characters[Pchar.quest.contraband.SoldierIDX3], "reload", "Reload1", "none", "", "", "", 120);
			LAi_ActorRunToLocation(&Characters[Pchar.quest.contraband.SoldierIDX4], "reload", "Reload1", "none", "", "", "", 120);
			LAi_ActorRunToLocation(&Characters[Pchar.quest.contraband.SoldierIDX5], "reload", "Reload1", "none", "", "", "", 120);
			LAi_ActorRunToLocation(&Characters[Pchar.quest.contraband.SoldierIDX6], "reload", "Reload1", "none", "", "", "", 120);
			LAi_SetPlayerType(Pchar);
		break;

		case "howDareYou":
			dialog.snd = "Voice\COGU\COGU010";
			d.Text = DLG_TEXT[27];
			Link.l1 = DLG_TEXT[28];
			Link.l1.go = "ThisTimeFree_fight";
		break;




	}
}