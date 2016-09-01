// ccc jul05 corpse
// This pseudo dialog only opens the itemexchange interface for looting corpses
// one could also add dialogchoices for reawakening or burial

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
	
	string questname  = "";
	string patroltime = GetPatrolTimeText(Islands[GetCharacterCurrentIsland(Pchar)], GetBestSmugglingtime(Islands[GetCharacterCurrentIsland(Pchar)]));
	if(CheckAttribute(Pchar,"amount_smuggleruns")) questname = "smuggle&number="+Pchar.amount_smuggleruns; //Set a questname
	
	int loc_id = FindLocation(PChar.location);
	int price = makeint(sqrt(sti(pchar.rank)))*250;
	string sNation = "";

	switch(Dialog.CurrentNode)
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "first time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\PADI\PADI001";

			// PB: You are a KNOWN enemy because you're flying a hostile flag
			if (GetFlagRMRelation(sti(Npchar.nation)) == RELATION_ENEMY)
			{
				sNation = " " + GetNationDescByType(GetCurrentFlag());
				if (GetCurrentFlag() == PERSONAL_NATION) sNation = "n "; // PB: Grammar "an enemy"
				Dialog.Text = DLG_TEXT[7] + GetMySimpleName(PChar) + DLG_TEXT[8] + sNation + DLG_TEXT[32];
				Link.l1 = DLG_TEXT[9];
				Link.l1.go = "exit_soldiers";
			}
			else
			{
				// ccc Dec 05 You are recognized for your pirating actions
				if(GetServedNation() == PIRATE && GetCurrentLocationNation() != PIRATE)	// MT: If serving the pirates and in a non-pirate location, then:
				{
					if(frnd()<makefloat(GetRank(pchar, sti(NPChar.nation)))/12.0) //MT: Meant to make you easier to detect as a pirate as you go up in pirate rank
					{
						Dialog.Text = DLG_TEXT[7] + GetMySimpleName(PChar) + DLG_TEXT[11];
						Link.l1 = DLG_TEXT[9];
						Link.l1.go = "exit_soldiers";
					}
					else
					{
						Dialog.Text = DLG_TEXT[0] + GetMySimpleName(PChar) + DLG_TEXT[1];
						Link.l1 = DLG_TEXT[2];
						Link.l1.go = "exit";
					}
				}
				else
				{
					//MT: If at war with the nation the guard belongs to, there is a chance to be detected (false flags should only occur when at war):
					if (GetNationRelation(PERSONAL_NATION, sti(Npchar.nation)) == RELATION_ENEMY && frnd() < GetChanceDetectFalseFlag())
					{
						sNation = " " + GetNationDescByType(GetServedNation());
						if (GetServedNation() == PERSONAL_NATION) sNation = ""; // PB: Grammar "a spy"
						Dialog.Text = DLG_TEXT[7] + GetMySimpleName(PChar) + DLG_TEXT[8] + sNation + DLG_TEXT[10];
						Link.l1 = DLG_TEXT[9];
						Link.l1.go = "exit_soldiers";
					}
					else
					{
						Dialog.Text = DLG_TEXT[18];
						Link.l1 = DLG_TEXT[19];
						Link.l1.go = "exit";
					}
					
				}
			}
			//Levis smuggling addon -->
			if(CheckAttribute(Pchar,"quest.Contraband.scout"))
			{
				if(!CheckAttribute(Pchar,"quest.Contraband.Talked") && !CheckAttribute(Pchar,"quest.Contraband.Cardwon"))
				{
					Link.l2 = DLG_TEXT[3];
					Link.l2.go = "patrolquestion";
				}
			}
			//Levis smuggling addon <--
			Diag.TempNode = "first time";
		break;

		case "exit_soldiers":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			LAi_LocationFightDisable(&locations[FindLocation(Pchar.location)], false);
			Random_Raid("Soldiers", 2, sti(NPchar.nation), LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "");
		break;
		
		//Levis smuggling dialog options
		case "patrolquestion":
			Dialog.Text = DLG_TEXT[4];
			if(!CheckAttribute(Pchar,"quest.Contraband.Talked"))
			{
				Link.l1 = DLG_TEXT[5];
				Link.l1.go = "seasidepicknick";
			}
			if(!CheckAttribute(Pchar,"quest.Contraband.Cardwon"))
			{
				if(CheckCharacterPerk(PChar,"HighStakes"))
				{
					Link.l2 = DLG_TEXT[28];
					Link.l2.go = "playgame";
				}
			}
		break;
		
		case "seasidepicknick":
			if(CheckOfficiantHadSex(GetCurrentTownID())==TRUE)
			{
				Dialog.Text = DLG_TEXT[6]+patroltime+DLG_TEXT[12];
				Link.l1 = DLG_TEXT[13];
				Link.l1.go = "exit";
				Preprocessor_AddQuestData("time",patroltime);
				AddQuestRecord(questname, 3);
				Preprocessor_Remove("time");
				Pchar.quest.Contraband.Talked = true;
				AddPartyExpChar(pchar, SKILL_SNEAK, 200);
			}
			else
			{
				if(pchar.money > price)
				{
					Dialog.Text = DLG_TEXT[14];
					Link.l1 = DLG_TEXT[15];
					Link.l1.go = "buyinfo";
				}
				else
				{
					Dialog.Text = DLG_TEXT[18];
					Link.l1 = DLG_TEXT[19];
					Link.l1.go = "exit";
				}
			}
		break;
		
		case "buyinfo":
			Dialog.Text = DLG_TEXT[20]+price+DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "acceptprice";
			Link.l2 = DLG_TEXT[23];
			Link.l2.go = "declineprice";
		break;
		
		case "acceptprice":
			AddMoneyToCharacter(pchar, -price);
			Dialog.Text = DLG_TEXT[25]+patroltime+DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "exit";
			Preprocessor_AddQuestData("time",patroltime);
			AddQuestRecord(questname, 2);
			Preprocessor_Remove("time");
			Pchar.quest.Contraband.Talked = true;
		break;
		
		case "declineprice":
			AddMoneyToCharacter(pchar, -10);
			Dialog.Text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[19];
			Link.l1.go = "exit";
		break;
		
		case "playgame":
			Pchar.quest.Contraband.CardsBet = (getSmugglingState(Islands[GetCharacterCurrentIsland(PChar)])+1)*1000;
			Dialog.Text = DLG_TEXT[29] + Pchar.quest.Contraband.CardsBet + ".";
			if(sti(PChar.money) >= sti(Pchar.quest.Contraband.CardsBet))
			{
				Link.l1 = DLG_TEXT[30];
				Link.l1.go = "playgame2";
			}
			Link.l2 = DLG_TEXT[31];
			Link.l2.go = "exit";
		break;
		
		case "playgame2":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			Pchar.quest.Contraband.Cards = 1;
			LaunchGambling(NPChar, "Poker");
		break;
		
		case "wongame":
			AddMoneyToCharacter(pchar, -price);
			Dialog.Text = DLG_TEXT[25]+patroltime+DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "exit";
			Preprocessor_AddQuestData("time",patroltime);
			AddQuestRecord(questname, 12);
			Preprocessor_Remove("time");
			LAi_SetCivilianPatrolType(NPChar);
			Pchar.quest.Contraband.Cardwon = true;
			DeleteAttribute(pchar,"quest.Contraband.WonGame"); // PB: Must get rid of this again afterwards!
		break;
		//End smuggling dialog options

	}
}
