#include "rumour_data.c"

#define Few_Quest_Sum		400
#define Some_Quest_Sum		2000
#define Medium_Quest_Sum	4000
#define Large_Quest_Sum		6000
#define Huge_Quest_Sum		10000
#define QUEST_COUNTER 		3

#define FRA_COLONY 		 		"Falaise De Fleur"
#define SPA_COLONY 		 		"Isla Muelle"
#define POR_COLONY 		 		"Conceicao"	
#define HOL_COLONY 		 		"Douwesen"
#define RED_COLONY 		 		"Redmond"
#define OX_COLONY 		 		"Oxbay"
#define GREEN_COLONY 		 	"Greenford"
#define QC_COLONY 		 		"Quebradas Costillas"
#define CAY_COLONY 		 		"Grand Cayman"
#define SANTO_DOMINGO_COLONY	"Santo Domingo"
#define PORT_AU_PRINCE_COLONY	"Port au Prince"
#define POINTE_A_PITRE_COLONY	"Pointe a Pitre"
#define HAVANA_COLONY 		 	"Havana"
#define MARIGOT_COLONY 		 	"Marigot"
#define PHILIPSBURG_COLONY 		"Philipsburg"
#define SANTIAGO_COLONY 		"Santiago"
#define CHARLESTOWN_COLONY 		"Charlestown"
#define ST_JOHNS_COLONY 		"St John's"
#define TURK_COLONY 		 	"Grand Turk"
#define TORTUGA_COLONY 		 	"Tortuga"
#define SMUGGLERS_COLONY 		"Smugglers Lair"
#define PIRATES_COLONY 		 	"Pirate Fort"

//========================| PLAYER |========================//
#define PLAYER_TYPE_ADVENTURER		1
#define PLAYER_TYPE_AGENT          	2
#define PLAYER_TYPE_MILITARY		3
#define PLAYER_TYPE_CORSAIR			4
#define PLAYER_TYPE_ENGINEER		5
#define PLAYER_TYPE_EXPLORER		6
#define PLAYER_TYPE_GAMBLER			7
#define PLAYER_TYPE_GUNNER			8
#define PLAYER_TYPE_MARINE			9
#define PLAYER_TYPE_MERCHANT		10
#define PLAYER_TYPE_NAVAL_OFFICER	11
#define PLAYER_TYPE_PHYSICIAN		12
#define PLAYER_TYPE_QUARTERMASTER	13
#define PLAYER_TYPE_REBEL			14
#define PLAYER_TYPE_ROGUE          	15
#define PLAYER_TYPE_SAILOR         	16
#define PLAYER_TYPE_SHIPWRIGHT		17
#define PLAYER_TYPE_SMUGGLER		18
#define PLAYER_TYPE_SOCIAL_CLIMBER	19
#define PLAYER_TYPE_SWORD_MASTER	20
#define PLAYER_TYPE_CURSED			21
#define PLAYER_TYPE_CASTAWAY		22
#define PLAYER_TYPE_CUSTOM         	23
#define PLAYER_TYPE_LAND_OWNER    	24

//=======================| DIFFICULTY |======================//
#define DIFFICULTY_LANDLUBBER		1
#define DIFFICULTY_MARINER			2
#define DIFFICULTY_SEADOG			3
#define DIFFICULTY_SWASHBUCKLER		4

//========================| QUESTS |========================//any smugglers colony and island in the future
string DEFAULT_DESTINATION = "Conceicao smugglers";
string DEFAULT_TRADEISLAND = "Conceicao";

// NK -->
//MR -->
// states-->
#define MR_SINGLE				0
#define MR_MARRIED				1
#define MR_MISTRESS				2
// states <--
#define MRTALKPOINTS_SCALAR		5.0 //talkpoints scaled by this when added
//marpoints = ((fame * coeff)^pow*scalar + offset) * (basescale + frnd() * randscale)
#define MR_MPCOEFF				5.0
#define MR_MPPOW				0.415 //MUST BE >= 0.25
#define MR_MPSCALAR				18
#define MR_MPOFFSET				0
#define MR_MPBASESCALE			0.9
#define MR_MPRANDSCALE			0.2
#define MR_MPMIN				100 // if calc'd MP < this, MP = this.
#define MR_NONPROP_SCALAR		1.5 //scalar to marpoints if _not_ a proposal
#define MR_DAUGHTER_THRESH		500 //if frnd() < marpoints / this, mr is daughter; else niece
#define MR_INTRODUCE_CHANCE		0.25 // chance for gov to introduce MR to pchar. NOTE THIS IS ONLY ONCE PER DAY!
#define MR_INTR_CH_RANK_SCL		0.02 //sqrt(fame) * this is added to above
#define MR_MAXNUM				3 //max number of MRs introduced by governor at one time
//rep defines for dumping MR -->
#define MR_MINREP_TPTIMES		5 //min number times talked to for rep penalty
#define MR_REPPEN_SCALAR		0.5 //this * num times talked to = rep penalty
#define MR_MAXREPPENALTY		10 //max rep penalty for dumping, scaled by pcharrepphrase
#define MR_MIST_FAME_SCL		0.5 //scalar to mistresses' marp + talkp for scoring purposes
//rep defines for dumping MR <--
// MR <--

#define QUESTRUM_CHANCE			0.25 //chance to force selection of questrumor if one is available
#define QUESTRUM_UNGIVEN_CHANCE 0.5 //chance to force if above is available and not given yet.
// NK <--



object Address_Form; // not used 05-07-19
string AddressForms[256]; // size = MAX_NATIONS * MAX_ADDR_TYPES * 2. NK 05-07-18

void PlayerLostMoney(ref NPChar, int lostSum)
{
	ref PChar = GetMainCharacter();
	if(!CheckAttribute(PChar,"money")) PChar.money = 0;
	if(sti(PChar.money)==0) return;
	if(sti(PChar.money)<lostSum) lostSum = sti(PChar.money);
	PChar.money = makeint(sti(PChar.money)-lostSum);
	PlayStereoSound("INTERFACE\took_item.wav");
	if(IsMainCharacter(NPChar)) return;
	if(!CheckAttribute(NPChar,"money")) NPChar.money = 0;
	NPChar.money = makeint(sti(NPChar.money)+lostSum);
}

// KK -->
//MAXIMUS: universal translation method -->
string SpellString(string tdir, string tfile, ref str1, ref str2, string joinString)
{
	string strData1 = str1;
	string strData2 = str2;
	string translator = tdir + "\" + tfile;
	bool bUseCommonIni = tfile == "";
	int tmpLangFileID = -1;

	if (!bUseCommonIni) {
		if (FindFile("RESOURCE\INI\TEXTS\" + LanguageGetLanguage() + "\" + tdir, "*.txt", tfile) == "") {
			str1 = "";
			str2 = "";
			return "";
		}
		tmpLangFileID = LanguageOpenFile(translator);
	}

	string tmpData = " ";
	if (strData1 == "" || strData2 == "") tmpData = "";
	string resultString1 = "";
	if (bUseCommonIni)
		resultString1 = XI_ConvertString(strData1);
	else
		resultString1 = LanguageConvertString(tmpLangFileID, strData1);
	string resultString2 = "";
	if (bUseCommonIni)
		resultString2 = XI_ConvertString(strData2);
	else
		resultString2 = LanguageConvertString(tmpLangFileID, strData2);
	string resultString = joinString;
	if (bUseCommonIni)
		resultString = XI_ConvertString(resultString);
	else
		resultString = LanguageConvertString(tmpLangFileID, resultString);

	if (!bUseCommonIni) LanguageCloseFile(tmpLangFileID);

	str1 = resultString1;
	str2 = resultString2;
	return resultString;
}
//MAXIMUS: universal translation method <--

// MAXIMUS: spelling correction - In russian language "2 days" and "5 days" (for example) - different words "days". I added this for proper phrases spelling. Anyone can add the same (if needed) for other languages -->
string GetLocalizedDayString(int days)
{
	string Translation = TranslateString("","days");
	string sDays = days;
	int ifcelng = GetInterfaceLanguage();

	int bCorrestion = 1;
	if (days/10<1) bCorrestion = 0;
	if (days/10>10) bCorrestion = 2;
	if (days/10>100) bCorrestion = 3;
	if (days/10>1000) bCorrestion = 4;
	if (days/10>10000) bCorrestion = 5;
	if (days/10>100000) bCorrestion = 6;
	if (days/10>1000000) bCorrestion = 7;
	if (days/10>10000000) bCorrestion = 8;
	if (days/10>100000000) bCorrestion = 9;
	string daysCount = strcut(sDays, bCorrestion, strlen(sDays)-1);
//	LogIt(daysCount);

	switch (ifcelng) 
	{
		case ILANG_RUS:
			if (daysCount == 1 && strcut(sDays, strlen(sDays)-2, strlen(sDays)-1) > 11) Translation = TranslateString("","loc_day");
			if (daysCount > 1 && daysCount < 5)
			{ 
				if (days > 20 || days < 10) Translation = TranslateString("","loc_days");
				if (days > 20 && strcut(sDays, strlen(sDays)-2, strlen(sDays)-1) > 11) Translation = TranslateString("","loc_days");
			}
		break;
//		case ILANG_FRA:
//		break;
//		case ILANG_GER:
//		break;
//		case ILANG_SPA:
//		break;
		case ILANG_POL:
			if (daysCount == 1 && strcut(sDays, strlen(sDays)-2, strlen(sDays)-1) > 11) Translation = TranslateString("","loc_day");
		break;
		// default:
//			if (daysCount == 1 && strcut(sDays, strlen(sDays)-2, strlen(sDays)-1) > 11) Translation = TranslateString("","day"); // Yields "day" if days ends with "1", e.g. 21
			if (days == 1) Translation = TranslateString("","day"); // Why complicate it for other languages?  1 day, 2 or more days!
	}
	return Translation;
}
// MAXIMUS: spelling correction<--

string TranslateString(string strData1, string strData2)
{
	string tmpData = " ";
	if (strData1 == "" || strData2 == "") tmpData = "";
	string joinString = strData1 + tmpData + strData2;//default for English
	string resultString = "";
	string str1 = strData1;
	string str2 = strData2;
	string rStr1 = "";
	string rStr2 = "";
	bool swap = false;

	resultString = SpellString("", "", &str1, &str2, joinString);
	if (resultString != "") return resultString;
	rStr1 = str1;
	rStr2 = str2;

	str1 = strData1;
	str2 = strData2;
	resultString = SpellString("", "interface_strings.txt", &str1, &str2, joinString);
	if (resultString != "") return resultString;
	if (rStr1 == "") rStr1 = str1;
	if (rStr2 == "") rStr2 = str2;

	str1 = strData1;
	str2 = strData2;
	resultString = SpellString("", "characters_names.txt", &str1, &str2, joinString);
	if (resultString != "") return resultString;
	if (rStr1 == "") rStr1 = str1;
	if (rStr2 == "") rStr2 = str2;

	str1 = strData1;
	str2 = strData2;
	resultString = SpellString(GetStorylinePath(FindCurrentStoryline()), "characters_names.txt", &str1, &str2, joinString);
	if (resultString != "") return resultString;
	if (rStr1 == "") rStr1 = str1;
	if (rStr2 == "") rStr2 = str2;

	str1 = strData1;
	str2 = strData2;
	resultString = SpellString("", "ItemsDescribe.txt", &str1, &str2, joinString);
	if (resultString != "") return resultString;
	if (rStr1 == "") rStr1 = str1;
	if (rStr2 == "") rStr2 = str2;

	str1 = strData1;
	str2 = strData2;
	resultString = SpellString(GetStorylinePath(FindCurrentStoryline()), "ItemsDescribe.txt", &str1, &str2, joinString);
	if (resultString != "") return resultString;
	if (rStr1 == "") rStr1 = str1;
	if (rStr2 == "") rStr2 = str2;

	str1 = strData1;
	str2 = strData2;
	resultString = SpellString("", "GoodsDescribe.txt", &str1, &str2, joinString);
	if (resultString != "") return resultString;
	if (rStr1 == "") rStr1 = str1;
	if (rStr2 == "") rStr2 = str2;

	string sPref = "";
	if (DEBUGINFO) sPref = "@";
	if (rStr1 == "" && strData1 != "") rStr1 = sPref + strData1;
	if (rStr2 == "" && strData2 != "") rStr2 = sPref + strData2;
	switch(LanguageGetLanguage())
	{
		case "Russian":
			resultString = rStr2 + tmpData + rStr1;
		break;
		case "Polish":
			resultString = rStr2 + tmpData + rStr1;
		break;
		resultString = rStr1 + tmpData + rStr2;//default for English
	}

	return resultString;
}
// <-- KK

/*string LAi_FindRandomLocator(string group)
{
	if(IsEntity(loadedLocation) != true) return "";
	string at = "locators." + group;
	if(CheckAttribute(loadedLocation, at) == 0) return "";
	aref grp;
	makearef(grp, loadedLocation.(at));
	int num = GetAttributesNum(grp);
	if(num <= 0) return "";
	num = rand(num - 1);
	return GetAttributeName(GetAttributeN(grp, num));
}*/


void Quest_Init()
{
	//SetRumourDefaults(false); // NK
}

// NK -->
int GetDifficulty()
{
	ref pchar = GetMainCharacter();
	if(!CheckAttribute(pchar,"Difficulty")) pchar.Difficulty = 1;
	return sti(pchar.Difficulty);
}

int SetDifficulty(int newdiff)
{
	ref pchar = GetMainCharacter();
	if(!CheckAttribute(pchar,"Difficulty")) pchar.Difficulty = CharDifficulty;
	int olddiff =  sti(pchar.Difficulty);
	pchar.Difficulty = newdiff;
	return olddiff;
}

string GetDifficultyName(int d)
{                             
	string retstr;
	switch(d)
	{
		case 1:
			retstr = XI_ConvertString("Landlubber");
			break;
		case 2:
			retstr = XI_ConvertString("Mariner");
			break;
		case 3:
			retstr = XI_ConvertString("Sea Dog");
			break;
		case 4:
			retstr = XI_ConvertString("Swashbuckler");
			break;

		//default: // scheffnow - bf
			retstr = XI_ConvertString("Unknown");
	}
	return retstr;
}

bool GetShipCap()
{
	ref pchar = GetMainCharacter();
	if(!CheckAttribute(pchar,"shipcap")) pchar.shipcap = START_DIFF_SHIPCAP; // NK add default. 05-04-24
	return sti(pchar.shipcap);
}

void SetShipCap(bool cap)
{

	ref pchar = GetMainCharacter();
	pchar.shipcap = cap;
}
// NK <--

// KAM -->
bool KAM_GetSailingIconsState()
{
	ref pchar = GetMainCharacter();
	if(!CheckAttribute(pchar,"sailingiconsstate")) pchar.sailingiconsstate = true;
	return sti(pchar.sailingiconsstate);
}

void KAM_SetSailingIconsState(bool cap)
{

	ref pchar = GetMainCharacter();
	pchar.sailingiconsstate = cap;
	// NK test 04-17 to make navigator disappear when icon pressed, not on reload BI
	//bah, doesn't work.
	/*if(IsEntity(&BattleInterface))
	{
		if(KAM_GetSailingIconsState())
		{
			BattleInterface.ShowNavigator = InterfaceStates.BattleShow.Navigator;
		}
		else
		{
			BattleInterface.ShowNavigator = false;
		}
		RefreshBattleInterface(false); // try to refresh BI
	}*/
	// NK <--
	
}
// KAM <--

// move to set_indialogattributes to address section below 05-07-18

string RandSwear()	// ccc Nov05  fixed mess by unknown source :(
{
	int RandS = Rand(16);

	switch (RandS)
	{
		case 0:
			return XI_ConvertString("Anchor in my stern") +"!! ";
		break;

		case 1:
			return XI_ConvertString("Damn") +"!! ";
		break;

		case 2:
			return XI_ConvertString("O God") +"!! ";
		break;

		case 3:
			return XI_ConvertString("Devil") +"!! ";
		break;

		case 4:
			return XI_ConvertString("Sink my ship") +"!! ";
		break;

		case 5:
			return XI_ConvertString("Blow my belly") +"!! ";
		break;

		case 6:
			return XI_ConvertString("Thousand sharks") +"!! ";
		break;

		case 7:
			return XI_ConvertString("Arrgh") +"!! ";
		break;

		case 8:
			return XI_ConvertString("Oh heaven") +"!! ";
		break;

		case 9:
			return XI_ConvertString("Hell") +"!! ";
		break;

		case 10:
			return XI_ConvertString("Blow me butt") +"!! ";
		break;

		case 11:
			return XI_ConvertString("Goodness gracious me") +"!! ";
		break;

		case 12:
			return XI_ConvertString("Yikes") +"!! ";
		break;

		case 13:
			return XI_ConvertString("Poxridden doxy") +"!! ";
		break;

		case 14:
			return XI_ConvertString("Christ") +"!! ";
		break;

		case 15:
			return "(*" +  XI_ConvertString("Censored obscene language")  + "*) ";
		break;

		case 16:
			return XI_ConvertString("By Jove") +"!! ";
		break;


	}
}


int RandSum(string Amount)
{
	int Sum;

	switch(Amount)
	{
		case "Few":

			Sum = Few_Quest_Sum + Rand(Few_Quest_Sum/20)*10;
			trace("Generated sum is: " + Sum);
			return Sum;

		break;


		case "Some":

			Sum = Some_Quest_Sum + Rand(Some_Quest_Sum/200)*100;
			trace("Generated sum is: " + Sum);
			return Sum;

		break;

		case "Medium":

			Sum = Medium_Quest_Sum + Rand(Medium_Quest_Sum/200)*100;
			trace("Generated sum is: " + Sum);
			return Sum;

		break;

		case "Large":

			Sum = Large_Quest_Sum + Rand(Large_Quest_Sum/200)*100;
			trace("Generated sum is: " + Sum);
			return Sum;

		break;

		case "Huge":

			Sum = Huge_Quest_Sum + Rand(Huge_Quest_Sum/1000+1)*500;
			trace("Generated sum is: " + Sum);
			return Sum;

		break;
	}
return 0;
}


string LinkRandPhrase (string Var1, string Var2, string Var3)
{
	int RandP;
	RandP = Rand(2);
	//Trace("AAA: " + RandP);
	//Trace("AAA1: " + Var1);
	//Trace("AAA2: " + Var2);
	//Trace("AAA3: " + Var3);
	switch(RandP)
	{
		case 0:

			return /*"First phrase selected" + */ Var1;

		break;

		case 1:

			return /*"Second phrase selected" + */Var2;

		break;

		case 2:

			return /*"Third phrase selected" + */Var3;

		break;
	}
	return "ERROR";
}



string RandPhrase (string Var1, string Var2, string Var3, ref Diag, string Sound1, string sound2, string sound3)
{
	int RandP;
	RandP = Rand(2);
	//Trace("AAA: " + RandP);
	//Trace("AAA1: " + Var1);
	//Trace("AAA2: " + Var2);
	//Trace("AAA3: " + Var3);
	DeleteAttribute(Diag, "snd1");
	DeleteAttribute(Diag, "snd2");
	DeleteAttribute(Diag, "snd3");
	switch(RandP)
	{
		case 0:

			diag.snd = sound1;
			return /*"First phrase selected" + */ Var1;

		break;

		case 1:

			diag.snd = sound2;
			return /*"Second phrase selected" + */Var2;

		break;

		case 2:

			diag.snd = sound3;
			return /*"Third phrase selected" + */Var3;

		break;
	}
	return "ERROR";
}

string PCharPhrase (string Var1, string Var2)
{
	ref PlayerCharacter = GetMainCharacter();

	switch(PlayerCharacter.id)
	{
		case "Blaze":

			return Var1;

		break;

		case "Danielle":

			return Var2;

		break;
	}
	return "___Player Character is not defined - can't select character phrase___";
}

// NK -->
//selects random rumor based on island and nation.
//set either to "any" to override loc-based rumors
string SelectRumour(string rIsland, string rNation)
{
	//build available rumor table, borrowed from build encounter table. ;)
	int AvailRumors[256]; //temp, should be [TOTAL_RUMOURS];
	int NumRumours = 0;
	bool questavail = false;
	bool qonly = false;
	bool qungiven = false;

	for(int i = 0; i < TOTAL_RUMOURS; i++)
	{
		//if not active because quest not in progress, skip
		if(!CheckAttribute(&Rumour[i],"given")) Rumour[i].given = false;
		if(Rumour[i].state != "active") { continue; }
		
		// check chance
		if(rand(100) > sti(Rumour[i].chance)) { continue; }

		//Check island/country
		if(rIsland != "any" && rNation != "any")
			{ if(Rumour[i].loc != "all" && Rumour[i].loc != rIsland && Rumour[i].loc != rNation) { continue; } }

		if(CheckAttribute(&Rumour[i],"id")) { questavail = true; if(!sti(Rumour[i].given)) { qungiven = true; } } //there is a quest rumor available
		
		AvailRumors[NumRumours] = i;
		NumRumours++;
	}
	if (NumRumours == 0) 
	{
		//if none found, return default rumor
		return Rumour[0].text;
	}

	//get random rumor to return
	if(frnd() < QUESTRUM_CHANCE && questavail) qonly = true;
	if(qungiven && frnd() < QUESTRUM_UNGIVEN_CHANCE) qonly = true;
	int RumPlace = rand(NumRumours - 1);
	int RetRum = AvailRumors[RumPlace];
	if(qonly && !CheckAttribute(&Rumour[RetRum],"id"))
	{
		while(!CheckAttribute(&Rumour[RetRum],"id"))
		{
			RumPlace = rand(NumRumours - 1);
			RetRum = AvailRumors[RumPlace];
		}
	}
	//Log_SetStringToLog("Return: " + RetRum);

	//return rumor
	Rumour[RetRum].given = true;
	return Rumour[RetRum].text;

	//return Rumour[0].text;
}

//turns rumor on or off. NOTE: Rumor must have an ID! If not found, returns false, else true
bool SetRumourState(string id, bool bstate)
{
	string rstate = "active";
	if(!bstate) rstate = "in" + rstate;

	int idx = GetRumourIndex(id);
	if(idx == -1) return false;

	Rumour[idx].state = rstate;
	return true;
}

//checks if rumor with id matching exists, and if so returns index
int GetRumourIndex(string id)
{
	for(int i = 0; i < TOTAL_RUMOURS; i++)
	{
		if(CheckAttribute(Rumour[i],"id"))
		{
			if(Rumour[i].id == id) { return i; }
		}
	}
	return -1;
}
// NK <--


string SelectFraRumour()
{
	int Rumour_Index;
	ref CurrentRumour;
	Rumour_Index = rand(MAX_RUMOURS - 1);

	for(Rumour_Index; Rumour_Index<MAX_RUMOURS; Rumour_Index++)
	{
		makeref (CurrentRumour, Rumour[Rumour_Index]);
		if(CurrentRumour.state == "active")
		{
			if(CurrentRumour.country == "fra")
			{
				return CurrentRumour.text;
			}
		}
	}
	return Rumour[0].text;

}

string PCharRepPhrase (string Var1, string Var2)
{
	ref pchar = GetMainCharacter();

	if(makeint(pchar.reputation) < REPUTATION_NEUTRAL)
	{
		return Var2;
	}
	else
	{
		return Var1;
	}
}

void Alchogol (string ncharID)
{
	ref PChar;
	PChar = GetMainCharacter();

	switch(pchar.location)
	{
		case "Redmond_tavern":
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit1")
			{
				DoQuestReloadToLocation("redmond_tavern", "Sit", "Sit9", "alc2");
			}
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit3")
			{
				DoQuestReloadToLocation("redmond_tavern", "Sit", "Sit2", "alc2");
			}
		break;

		case "Oxbay_tavern":
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit1")
			{
				DoQuestReloadToLocation("Oxbay_tavern", "Sit", "Sit9", "alc2");
			}
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit3")
			{
				DoQuestReloadToLocation("Oxbay_tavern", "Sit", "Sit2", "alc2");
			}
		break;

		case "Greenford_tavern":
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit5")
			{
				DoQuestReloadToLocation("Greenford_tavern", "Sit", "Sit4", "alc2");
			}
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit1")
			{
				DoQuestReloadToLocation("Greenford_tavern", "Sit", "Sit2", "alc2");
			}
		break;

		case "Falaise_De_Fleur_tavern":

		break;

		case "Muelle_tavern":
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit1")
			{
				DoQuestReloadToLocation("Muelle_tavern", "Sit", "Sit2", "alc2");
			}
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit7")
			{
				DoQuestReloadToLocation("Muelle_tavern", "Sit", "Sit3", "alc2");
			}
		break;

		case "Douwesen_tavern":
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit1")
			{
				DoQuestReloadToLocation("Douwesen_tavern", "Sit", "Sit2", "alc2");
			}
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit7")
			{
				DoQuestReloadToLocation("Douwesen_tavern", "Sit", "Sit3", "alc2");
			}
		break;

		case "Pirate_tavern":
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit1")
			{
				DoQuestReloadToLocation("Conceicao_tavern", "Sit", "Sit2", "alc2");
			}
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit4")
			{
				DoQuestReloadToLocation("Conceicao_tavern", "Sit", "Sit3", "alc2");
			}
		break;

		case "Conceicao_tavern":
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit1")
			{
				DoQuestReloadToLocation("Conceicao_tavern", "Sit", "Sit2", "alc2");
			}
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit7")
			{
				DoQuestReloadToLocation("Conceicao_tavern", "Sit", "Sit3", "alc2");
			}
		break;

		case "Smugglers_tavern":
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit5")
			{
				DoQuestReloadToLocation("Conceicao_tavern", "Sit", "Sit6", "alc2");
			}
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit4")
			{
				DoQuestReloadToLocation("Conceicao_tavern", "Sit", "Sit3", "alc2");
			}
		break;

		case "QC_tavern":
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit1")
			{
				DoQuestReloadToLocation("Conceicao_tavern", "Sit", "Sit2", "alc2");
			}
			if (characters[GetCharacterIndex(ncharID)].location.locator == "sit3")
			{
				DoQuestReloadToLocation("Conceicao_tavern", "Sit", "Sit7", "alc2");
			}
		break;
	}
}

// moved smuggling stuff to seperate file

string SelectSoldierModelByNation(int nat, string SoldierOrOfficer) // NK switched from ref char to int nat 05-07-10, rewritten for modeltypes
{
// KK -->
	switch (SoldierOrOfficer) {
		case "officer":
			if (nat != PERSONAL_NATION)
				return Nations[nat].fantomModel.m0;
			else
				return characters[GetMainCharacterIndex()].Soldier.m0;
		break;
		// default:
			string lot = "m" + (rand(5) + 1);
			if (nat != PERSONAL_NATION)
				return Nations[nat].fantomModel.(lot);
			else
				return characters[GetMainCharacterIndex()].Soldier.(lot);
	}
// <-- KK
}

void AddGeometryToLocation(string LocationID, string ModelName)
{
	ref LocationRef;
	int n = 1;
	string str;
	locationRef = &locations[FindLocation(LocationID)];

	for(n = 1; n < 10; n++)
	{
		str = "l" + n; // PB: Elsewhere this uses "l1" and not just "1"; now this does too
		if(!CheckAttribute(LocationRef, "models.always." + str))
		{
			LocationRef.models.always.(str) = ModelName;
			LocationRef.models.always.(str).tech = "dLightModel";
			break;
		}
	}
}

void RemoveGeometryFromLocation(string LocationID, string ModelName)
{
	ref LocationRef;
	int n = 1;
	string str;
	if(FindLocation(LocationID) != -1)
	{
		locationRef = &locations[FindLocation(LocationID)];
	}
	else
	{
		return;
	}

	for(n = 1; n < 10; n++)
	{
		str = "l" + n; // PB: Elsewhere this uses "l1" and not just "1"; now this does too
		if(CheckAttribute(LocationRef, "models.always." + str)) // PB: Add CheckAttribute to avoid error logs
		{
			if(LocationRef.models.always.(str) == ModelName)
			{
				DeleteAttribute(LocationRef, "models.always." + str);
				break;
			}
		}
	}
}

// NK -->
//MAXIMUS: the same way, as Enc_Officer -[it was my first version of this function (rewritten later by TIH)]->
int FindFreeCabinCaptain()
{
	for(int tempnum=0; tempnum<=CABINCAPTAINS_MAX; tempnum++)
	{
		string tempid = "Enc_CabinCaptain_" + tempnum;
		int tempidx = GetCharacterIndex(tempid);
		if(tempidx==-1) break;
		ref tempChar = GetCharacter(tempidx);

		if(bAllies(tempChar))									{ continue; }
		if(tempChar.location == loadedLocation.id)				{ continue; }	// PB: To prevent prospective officers from disappearing when you're talking to them
		if(LAi_IsBoardingProcess())
		{
			if (tempChar.id == boarding_enemy.id)				{ continue; }	// PB: Skip the captain of the ship you're currently boarding
			if (IsOfficerOf(boarding_enemy, tempChar))			{ continue; }	// MM: Skip also any officers assigned to this ship
		}

	//	TraceAndLog("FindFreeCabinCaptain clears " + GetMySimpleName(tempChar));
		ClearCharacter(tempChar); // PB: Completely erase the unused character

		return tempidx;
	}

	return -1;
}
//MAXIMUS: the same way, as Enc_Officer <-[it was my first version of this function (rewritten later by TIH)]-

// TIH --> consolidated officer hired functions
// used for cabinfight_dialog.c
// used for prisoned_dialog.c
// used for enc_fort_dialog.c 	(not yet needed ?)
// used for enc_shipmate.c 		(not yet needed ?)
// used for both_reaction.c 	(not yet needed ?)
// this makes a character into an officer for the player. Function flags allow control of how the officer is handled:
//	bLowSalary 		- makes their salary lower
//	bAutoAssign 	- will force the officer into one of the officer slots of the character
//	bPurgeCrud 		- this will 'clean' the copied result from garbage that existed in the copy from character (needed for shipcaptains)
//	bSetType 		- this will run the officer type setup function (needed for ones that dont show you stats when hiring)
//	bCreateOfficer 	- this will actually run the full create officer functions on a character slot (not used at the moment)
void TIH_OfficerHiredProcess(ref RefChar, bool bLowSalary, bool bAutoAssign, bool bPurgeCrud, bool bSetType, bool bCreateOfficer)
{
	ref PChar = GetMainCharacter();
	ref NewOfficer = &NullCharacter();
	int NewOfficerIdx;
	string NewOfficerID;

	PChar.quest.HiringOfficerIDX = GetCharacterIndex(RefChar.id);

	int freeidx = FindFreeRandomOfficer();// get an open officer slot to use (50 maximum)
	if(freeidx != -1)
	{
		//trace("-----------------------------------------------------------------");
		//trace("dialog_func.c:");

		// cleaner method
		NewOfficerIdx 	= sti(Characters[freeidx].index);
		NewOfficer 		= GetCharacter(NewOfficerIdx);
		NewOfficerID 	= NewOfficer.id;// store this because we have to put it back after the copyattr

		PChar.quest.NewOfficerIdx = NewOfficerIdx;// store for second function

		//	trace("Hiring Officer IDX is " + PChar.quest.HiringOfficerIDX + " and he has id  " + Characters[sti(PChar.quest.HiringOfficerIDX)].id);
		//	trace("Free Random Officer IDX is " + NewOfficerIdx + " and he has id  " + NewOfficerID);

//MAXIMUS: hired captain will stay in location with player -->
//		ChangeCharacterAddressGroup(&RefChar, "None", "", "");// get rid of the reference character
		if(RefChar.sex == "woman") RefChar.greeting = "Gr_Officer_f common";
		else RefChar.greeting = "Gr_Officer_m common";
		RefChar.Dialog.Filename = "Enc_Officer_dialog.c";
		RefChar.Dialog.CurrentNode = "Hired";
		CopyAttributes(&NewOfficer, &RefChar);// copy all attr from the reference character (the hiring officer) to the new officer char
		if(bSetType) { LAi_SetOfficerType(RefChar); }
		LAi_group_MoveCharacter(RefChar, LAI_GROUP_PLAYER);
		RefChar.location = "none";
//MAXIMUS: hired captain will stay in location with player <--

		NewOfficer.index = NewOfficerIdx;// reset these after the copyattr
		NewOfficer.id    = NewOfficerID; // reset these after the copyattr
		NewOfficer.friend = true;
		NewOfficer.ship.type = "Not Used";
		NewOfficer.ship.idx = 1000;
		NewOfficer.nodisarm = 1;
		NewOfficer.location = "none";


		//trace("New Officer IDX is " + NewOfficer.index + " and he has id  " + NewOfficer.id);
		//trace("dialog_func.c - > officer dump before cleaning:"); DumpAttributes( Characters[sti(PChar.quest.NewOfficerIdx)] );
/*
		// these do fixing
		if(NewOfficer.sex == "woman") 	NewOfficer.greeting = "Gr_Officer_f common";
		else 							NewOfficer.greeting = "Gr_Officer_m common";
		NewOfficer.Dialog.Filename = "Enc_Officer_dialog.c";
		NewOfficer.Dialog.CurrentNode = "Hired";
		NewOfficer.AbordageMode = 1;// boal 05.09.03 officer set to go to abordage
*/
		// TIH --> suggested additions from maximus, adjusted for this code Aug29'06
// TIH --> no, see if this attr doesnt exist for NEW officer, its because REF officer didn't have it in the first place, so trying to assign it the null field again is a bit pointless and dangerous - Oct30'06
//		if (!CheckAttribute(NewOfficer,"location.locator") && CheckAttribute(RefChar, "location.locator")) NewOfficer.location.locator = RefChar.location.locator;// ? was a bug with not existent location.locator // KK now that should be OK 
//		if (!CheckAttribute(NewOfficer,"location.locator"))	NewOfficer.location.locator = "";// TIH - actually set it to nothing for fresh reset - Oct30'06
// TIH <--
		if (!CheckAttribute(NewOfficer,"model.entity")) 	NewOfficer.model.entity = "NPCharacter";// ? sometimes was an error - "can't create class"
		if (!CheckAttribute(NewOfficer,"noFollowType")) 	NewOfficer.noFollowType = "nofollow";// ? new identifier for template LAi_follow.c
		if (!CheckAttribute(NewOfficer,"money")) 			NewOfficer.money = 1+rand(100);// ? was a bug with not existent money
		// TIH <--

		if (bPurgeCrud) {// purge a whole bunch of broken crud that causes bugs for this new officer (captured captains only)
			if ( CheckAttribute(NewOfficer,"ship") ) 			DeleteAttribute(NewOfficer,"ship");
			if ( CheckAttribute(NewOfficer,"shiptype") ) 		DeleteAttribute(NewOfficer,"shiptype");
			if ( CheckAttribute(NewOfficer,"shipmoney") ) 		DeleteAttribute(NewOfficer,"shipmoney");
			if ( CheckAttribute(NewOfficer,"curshipnum") ) 		DeleteAttribute(NewOfficer,"curshipnum");
			if ( CheckAttribute(NewOfficer,"seaai") ) 			DeleteAttribute(NewOfficer,"seaai");
			if ( CheckAttribute(NewOfficer,"features") ) 		DeleteAttribute(NewOfficer,"features");
			if ( CheckAttribute(NewOfficer,"seatime") ) 		DeleteAttribute(NewOfficer,"seatime");
			if ( CheckAttribute(NewOfficer,"relation") ) 		DeleteAttribute(NewOfficer,"relation");
			if ( CheckAttribute(NewOfficer,"fantomtype") ) 		DeleteAttribute(NewOfficer,"fantomtype");
			if ( CheckAttribute(NewOfficer,"canfiretime") ) 	DeleteAttribute(NewOfficer,"canfiretime");
			if ( CheckAttribute(NewOfficer,"rankscale") ) 		DeleteAttribute(NewOfficer,"rankscale");
			if ( CheckAttribute(NewOfficer,"tmpperks") ) 		DeleteAttribute(NewOfficer,"tmpperks");
			if ( CheckAttribute(NewOfficer,"tmpskill") ) 		DeleteAttribute(NewOfficer,"tmpskill");
			if ( CheckAttribute(NewOfficer,"points") ) 			DeleteAttribute(NewOfficer,"points");
			if ( CheckAttribute(NewOfficer,"randofficers") ) 	DeleteAttribute(NewOfficer,"randofficers");
			if ( CheckAttribute(NewOfficer,"skillnatmult") ) 	DeleteAttribute(NewOfficer,"skillnatmult");
			if ( CheckAttribute(NewOfficer,"nodisarm") ) 		DeleteAttribute(NewOfficer,"nodisarm");
			if ( CheckAttribute(NewOfficer,"points") ) 			DeleteAttribute(NewOfficer,"points");
			if ( CheckAttribute(NewOfficer,"isFantom") ) 		DeleteAttribute(NewOfficer,"isFantom");
			if ( CheckAttribute(NewOfficer,"status") ) 			DeleteAttribute(RefChar,"status");
			if ( CheckAttribute(NewOfficer,"position") ) 		DeleteAttribute(RefChar,"position");
			if ( CheckAttribute(NewOfficer,"fight") ) 			DeleteAttribute(RefChar,"fight");
			if ( CheckAttribute(NewOfficer,"cabinfight") ) 		DeleteAttribute(RefChar,"cabinfight");
			if (CheckAttribute(RefChar, "CompanionEnemyEnable"))	DeleteAttribute(NewOfficer, "CompanionEnemyEnable");
		}
		LAi_SetOfficerType(NewOfficer);
		if(bCreateOfficer)
		{
			/*switch(Rand(7))
			{
				case 0: NewOfficer.quest.officertype = OFFIC_TYPE_BOATSWAIN; break;
				case 1: NewOfficer.quest.officertype = OFFIC_TYPE_CANNONEER; break;
				case 2: NewOfficer.quest.officertype = OFFIC_TYPE_QMASTER; break;
				case 3: NewOfficer.quest.officertype = OFFIC_TYPE_NAVIGATOR; break;
				case 4: NewOfficer.quest.officertype = OFFIC_TYPE_FIRSTMATE; break;
				case 5: NewOfficer.quest.officertype = OFFIC_TYPE_CARPENTER; break;
				case 6: NewOfficer.quest.officertype = OFFIC_TYPE_DOCTOR; break;
				case 7: NewOfficer.quest.officertype = OFFIC_TYPE_ABORDAGE; break;
			}*/
			if(DEBUG_EXPERIENCE>0) TraceAndLog("TIH_OfficerHiredProcess: Set officer type for " + GetMySimpleName(NewOfficer));
			NewOfficer.quest.officertype = GetRandomOfficerType(); //Levis let's use a global function so we can easily add types later.
			LAi_Create_Officer(rand(8), &NewOfficer);/*
			NewOfficer.offgen = true;
			NewOfficer.officer = true;
			LAi_Create_Officer(rand(1),NewOfficer);*/
		}
		else
		{
//			if (!CheckAttribute(PChar, "IsOnDeck") && !bAbordageStarted) NewOfficer.location = "None"; // KK
			//NewOfficer.location.group = "officers";// not needed
			NewOfficer.chr_ai.type = "officer";
			NewOfficer.offgen = true;
			NewOfficer.officer = true;
			NewOfficer.friend = true;
			NewOfficer.land = "0";
			if(CheckAttribute(NewOfficer,"wealth"))  			NewOfficer.wealth = makeint(NewOfficer.wealth);// clean up the ungainly float!
			if(CheckAttribute(NewOfficer,"quest.officertype"))	NewOfficer.current = NewOfficer.quest.officertype;
		}

		if (bAutoAssign)
		{
			// added by MAXIMUS [for placing new officer in empty slot (default for some officers)] -->
			int ofNum = OFFICER_MAX-1 ;// default force into last slot
			if ( CheckAttribute(NewOfficer,"quest.officertype") ) {
				switch( NewOfficer.quest.officertype )
				{
					case OFFIC_TYPE_FIRSTMATE: ofNum = 1; break;
					case OFFIC_TYPE_BOATSWAIN: ofNum = 2; break;
					case OFFIC_TYPE_NAVIGATOR: ofNum = 3; break;
					//case OFFIC_TYPE_QMASTER:   ofNum = 1; break;
					//case OFFIC_TYPE_CANNONEER: ofNum = 2; break;
				}
			}
			SetOfficersIndex(PChar, ofNum, NewOfficerIdx);
			// added by MAXIMUS [for placing new officer in empty slot (default for some officers)] <--
		} else {
			//SetOfficersIndex(PChar, -1, NewOfficerIdx);// put them into an available slot if one exists (do not force it)
			AddPassenger(PChar,NewOfficer,false);// just add them as a passenger for now
//			AssignCaptiveAsCompanion(RefChar, NewOfficer);//MAXIMUS: not needed

			if(CheckAttribute(NewOfficer, "quest.officertype") && NewOfficer.quest.officertype == OFFIC_TYPE_ABORDAGE)
			{
			   DeleteAttribute(NewOfficer, "quest.officertype");
			}
		}

		// if they joined freely (no cost), they have a low salary ?
		if(!CheckAttribute(NewOfficer,"quest.officerprice"))
		{
			NewOfficer.quest.officerprice = makeint((sti(PChar.rank) * 2 + 10)*100) - 330 + rand(40)*15 + rand(10);
		}
		if(bLowSalary) NewOfficer.quest.officerprice = makeint( sti(NewOfficer.quest.officerprice) / 2 );

		if (!CheckCharacterEquipByGroup(NewOfficer, BLADE_ITEM_TYPE)) // KK
			LAi_NPC_Equip(NewOfficer, sti(PChar.rank), true, 0);// give the officer some weapons and equip them (NO GUN)

		// move any money they may have into their wealth, so MC can't steal their money
		if (CheckAttribute(NewOfficer,"money") && sti(NewOfficer.money) > 0)
		{
			if (!CheckAttribute(NewOfficer,"wealth")) { NewOfficer.wealth = 0; } // set if not set
			NewOfficer.wealth = makeint(sti(NewOfficer.wealth) + sti(NewOfficer.money)); // merge together into wealth
			NewOfficer.money = 0; // clear out their money now that its moved
		}

		// keep the NewOfficerIdx attribute, as its needed in the second function

		//trace("dialog_func.c -> officer dump at end:"); DumpAttributes( Characters[sti(PChar.quest.NewOfficerIdx)] );
		//trace("-----------------------------------------------------------------");
	}
	else
	{
		Log_SetStringToLog(QUEST_MESSAGE12);
	}
	DeleteAttribute(Pchar, "quest.HiringOfficerIDX");// deleted here, because we certainly no longer need it now
//	if (!CheckAttribute(PChar, "IsOnDeck") && bAbordageStarted) refEnCharacter = NewOfficer;
}

void TIH_OfficerHiredShow(bool bPlaceChar, bool bSameSpot, bool bStartDialog)
{
	ref PChar = GetMainCharacter();
	if ( CheckAttribute(PChar, "quest.NewOfficerIdx") ) {
		ref NewOfficer = GetCharacter(sti(PChar.quest.NewOfficerIdx));

	// TIH --> This section won't be activated from at-sea conditions yet.
	// Cabins and decks don't properly unload all characters when you leave them.
	// Thus hired captains or captives get 'left there' pretty much until you get to 
	// land and assign them as your officer. However if you had them assigned to a ship
	// you can't assign them as an officer, and then they will ALWAYS show up in cabins/decks.
	// So, until something is made for that, this section is not activated for now.
		if (bPlaceChar) {
			string locGroup;
			if (bAbordageStarted) 	locGroup = "rld";
			else 					locGroup = "goto";

			// prevents the officer from popping up somewhere else in the room when appearing
			// do not use bSameSpot for post quest officers (like officers sitting at a table!)
			if ( bSameSpot && CheckAttribute(NewOfficer,"location.locator") ) {
				LAi_SetStayTypeNoGroup(NewOfficer);
				ChangeCharacterAddressGroup(&NewOfficer, PChar.location, locGroup, NewOfficer.location.locator);
			} else {
				PlaceCharacter(NewOfficer, locGroup);
			}

			if (bStartDialog) DialogMain(NewOfficer);// they strike up a conversation with you

			BLI_UpdateOfficers();// for officers icons updates after new officer hire
		}
	// TIH <--

		DeleteAttribute(PChar, "quest.NewOfficerIdx");
	}
}
// TIH <--

string SelectSoldierModelbyLocationNation(string LocationID, string SoldierOrOfficer)
{
	// NK rewrite to use modeltypes 05-07-16
	ref PChar = GetMainCharacter();
	if(LocationID == "") LocationID = PChar.location;
	return SelectSoldierModelByNation(GetLocationNationFromID(LocationID), SoldierOrOfficer); // bugfix 05-07-19 GetLocationNation takes aref, not string.
	// NK <--
}

int getDeadManMoney()
{
	int money;

	money = Rand(10)*Rand(10)*10;

	return money;
}

string returnRandomDeadItem()
{
	return "potion";
}

//----------------------------- Недописанные функции, введенные для прописывания в диалоги ---------------------------


string TimeGreeting()
{
	// NK -->
	switch(GetDayTime())
	{
		case DAY_TIME_DAY: return XI_ConvertString("Good day"); break;
		case DAY_TIME_MORNING: return XI_ConvertString("Good morning"); break;
		case DAY_TIME_EVENING: return XI_ConvertString("Good evening"); break;
		case DAY_TIME_NIGHT: return XI_ConvertString("Good evening"); break;
	}
	// NK <--
	return XI_ConvertString("Good day");
}

//shorter way to check sex. Returns true if sex == "woman" (thus "man"/"skeleton"/whatever == 0 and "woman" == 1)
bool chrsex(ref chr)
{
	if (!CheckAttribute(chr, "sex")) return false;	// LDH some characters never got initialized 19Dec08
	return chr.sex == "woman";
}

// address types:
#define ADDR_CIVIL		0
#define ADDR_TITLE		1	// this defaults to CIVIL if no title.
#define ADDR_IMPTITLE	2	// Impersonal Title. Either rank or sir/madam. Used for, e.g., "my dear sir/captain/baron". This returns rank if exist, or ADDR_POLITE if not.
#define ADDR_COURTING	3
#define ADDR_POLITE		4
#define ADDR_INFORMAL	5
#define ADDR_INSULT		6
#define ADDR_HOSTILE	7
#define ADDR_CHILD		8
#define ADDR_KIN		9
#define ADDR_GENDER		10
// you also use address_form.noun, which I assume to return man/lady?
// for now I've replaced it in Alan Milds with GENDER...

// the reason I'm using defines rather than strings is so we can do math with them.

#define MAX_ADDR_TYPES	11 // must be last above addr form + 1!

void Set_inDialog_Attributes()
{
	// 05-07-18
	// Hijack this to set addressforms[] array.
	int csize = MAX_NATIONS * MAX_ADDR_TYPES * 2;
	SetArraySize(&AddressForms, csize);
	for(int i = 0; i < csize; i++)
	{
		AddressForms[i] = "";
	}

	// note: If the specific nation version does not exist, it will default to the English version.

	// TODO NOTE: PUT THESE IN COMMON.INI AND USE CONVERTSTRING!
	// Although we shouldn't for the ADDR_CIVIL because they're already translated; and for those other address forms we make multinational.
	
	AddressForms[GetAddressIndex(ADDR_CIVIL, ENGLAND, 0)] = XI_ConvertString("Mister");	// should this and Miss be master and mistress? This makes
	AddressForms[GetAddressIndex(ADDR_CIVIL, ENGLAND, 1)] = XI_ConvertString("Miss");	// especial sense because often it's used with the player's _first_ name...
	AddressForms[GetAddressIndex(ADDR_CIVIL, FRANCE, 0)] = XI_ConvertString("Monsieur");
	AddressForms[GetAddressIndex(ADDR_CIVIL, FRANCE, 1)] = XI_ConvertString("Mademoiselle");
	AddressForms[GetAddressIndex(ADDR_CIVIL, SPAIN, 0)] = XI_ConvertString("Señor");
	AddressForms[GetAddressIndex(ADDR_CIVIL, SPAIN, 1)] = XI_ConvertString("Señorita");
	// pirate omitted.
	AddressForms[GetAddressIndex(ADDR_CIVIL, HOLLAND, 0)] = XI_ConvertString("Mijnheer");
	AddressForms[GetAddressIndex(ADDR_CIVIL, HOLLAND, 1)] = XI_ConvertString("Juffrouw");
	AddressForms[GetAddressIndex(ADDR_CIVIL, PORTUGAL, 0)] = XI_ConvertString("Senhor");
	AddressForms[GetAddressIndex(ADDR_CIVIL, PORTUGAL, 1)] = XI_ConvertString("Senhorita");
// KK -->
	AddressForms[GetAddressIndex(ADDR_CIVIL, PERSONAL_NATION, 0)] = XI_ConvertString("Comrade");
	AddressForms[GetAddressIndex(ADDR_CIVIL, PERSONAL_NATION, 1)] = XI_ConvertString("Comrade");
// <-- KK
	
	AddressForms[GetAddressIndex(ADDR_COURTING, ENGLAND, 0)] = XI_ConvertString("m'lord");	//	Romancing, flattering or generally buttering up
	AddressForms[GetAddressIndex(ADDR_COURTING, ENGLAND, 1)] = XI_ConvertString("m'lady");
	
	
	AddressForms[GetAddressIndex(ADDR_POLITE, ENGLAND, 0)] = XI_ConvertString("sir");		//	Polite conversations (traders et cetera)
	AddressForms[GetAddressIndex(ADDR_POLITE, ENGLAND, 1)] = XI_ConvertString("ma'am");	// ma'am is then not a new contraction? Boy, learn something every day. :)
	// civil titles copied for polite for non-Eng
	AddressForms[GetAddressIndex(ADDR_POLITE, FRANCE, 0)] = XI_ConvertString("Monsieur");	
	AddressForms[GetAddressIndex(ADDR_POLITE, FRANCE, 1)] = XI_ConvertString("Mademoiselle");
	AddressForms[GetAddressIndex(ADDR_POLITE, SPAIN, 0)] = XI_ConvertString("Señor");
	AddressForms[GetAddressIndex(ADDR_POLITE, SPAIN, 1)] = XI_ConvertString("Señorita");
	AddressForms[GetAddressIndex(ADDR_POLITE, HOLLAND, 0)] = XI_ConvertString("Mijnheer");
	AddressForms[GetAddressIndex(ADDR_POLITE, HOLLAND, 1)] = XI_ConvertString("Juffrouw");
	AddressForms[GetAddressIndex(ADDR_POLITE, PORTUGAL, 0)] = XI_ConvertString("Senhor");
	AddressForms[GetAddressIndex(ADDR_POLITE, PORTUGAL, 1)] = XI_ConvertString("Senhorita");
// KK -->
	AddressForms[GetAddressIndex(ADDR_POLITE, PERSONAL_NATION, 0)] = XI_ConvertString("Comrade");
	AddressForms[GetAddressIndex(ADDR_POLITE, PERSONAL_NATION, 1)] = XI_ConvertString("Comrade");
// <-- KK

	AddressForms[GetAddressIndex(ADDR_INFORMAL, ENGLAND, 0)] = XI_ConvertString("lad");	//	Friendly references (matey's and friends)
	AddressForms[GetAddressIndex(ADDR_INFORMAL, ENGLAND, 1)] = XI_ConvertString("lass");
	
	AddressForms[GetAddressIndex(ADDR_INSULT, ENGLAND, 0)] = XI_ConvertString("sirrah");	//	Patronising reference (marriage duel et cetera)
	AddressForms[GetAddressIndex(ADDR_INSULT, ENGLAND, 1)] = XI_ConvertString("wench");
	
	AddressForms[GetAddressIndex(ADDR_HOSTILE, ENGLAND, 0)] = XI_ConvertString("bastard");	//	Insulting references (congratulations, you got an enemy)
	AddressForms[GetAddressIndex(ADDR_HOSTILE, ENGLAND, 1)] = XI_ConvertString("trollop");
	
	AddressForms[GetAddressIndex(ADDR_CHILD, ENGLAND, 0)] = XI_ConvertString("son");		//	Governors' daughters and what you are to the church
	AddressForms[GetAddressIndex(ADDR_CHILD, ENGLAND, 1)] = XI_ConvertString("daughter");
	
	AddressForms[GetAddressIndex(ADDR_KIN, ENGLAND, 0)] = XI_ConvertString("nephew");		//	Governors' nieces
	AddressForms[GetAddressIndex(ADDR_KIN, ENGLAND, 1)] = XI_ConvertString("niece");
	
	AddressForms[GetAddressIndex(ADDR_GENDER, ENGLAND, 0)] = XI_ConvertString("man"); 	//	Gendered noun ("My good woman" et cetera)
	AddressForms[GetAddressIndex(ADDR_GENDER, ENGLAND, 1)] = XI_ConvertString("woman");	//
}



// NK address wrapper function 05-06-28
// will return the address form addrtype used by chr on pchr, with optionally first (if fname is true) and/or last (if lname is true) names appended.
// will automatically handle nations based on chr.nation
// maybe later we can add checking for chr's wealth level and pass addrtype == -1 to automate things.
// if both fname and lname are true, add middle name as well to string if it exists (we don't need a third bool that way).
// updated 05-07-18
string GetMyAddressForm(ref chr, ref pchr, int addrtype, bool fname, bool lname)
{
	string retstr;
	int nat = sti(chr.nation);
	if (CheckAttribute(chr, "surrendered") == true && sti(chr.surrendered) == true && CheckAttribute(chr, "oldnation") == true) nat = sti(chr.oldnation); // KK
	int fakeNat = nat;//MAXIMUS: -[05.10.2007]->
	if(CheckAttribute(chr,"nation.name"))
	{
		if(nat==PIRATE || nat!=sti(chr.nation.name)) fakeNat = sti(chr.nation.name);//MAXIMUS: pirates can have a different own-nation <-[05.10.2007]-
	}
	bool bsex = chrsex(pchr); // CTM
	switch(addrtype)
	{
		case ADDR_TITLE:	retstr = stringret(GetRank(&pchr, nat) > 0, XI_ConvertString(GetRankName(&pchr, nat)), GetAddressForm(ADDR_TITLE, fakeNat, bsex)); break;// MAXIMUS 16.10.2006
		case ADDR_IMPTITLE:	retstr = stringret(GetRank(&pchr, nat) > 0, XI_ConvertString(GetRankName(&pchr, nat)), GetAddressForm(ADDR_IMPTITLE, fakeNat, bsex)); break;// MAXIMUS 16.10.2006
		/*default:*/		retstr = GetAddressForm(addrtype, fakeNat, bsex);
	}
	if (!CheckAttribute(pchr, "lastname") || pchr.lastname == "" || GetMyName(pchr) == FirstLetterUp(pchr.lastname))	// Character has only one name
	{
		if (fname || lname) retstr += " " + GetMyName(pchr);
	}
	else
	{
		if(fname) retstr += " " + GetMyName(pchr);
		if(fname && lname && CheckAttribute(pchr, "middlename")) retstr += " " + pchr.middlename;
		if(lname) retstr += " " + GetMyLastName(pchr);
	}
	return retstr;
}

// Swindler 05-09-25 -->
/**
 * Returns the address form of character <chr>. It takes into account
 * the nationality of the character. It works very similar to
 * GetMyAddressForm().
 */
string GetCharacterAddressForm(ref chr, int addrtype, bool fname, bool lname)
{
	string retstr;
	int nat = sti(chr.nation);
	int fakeNat = nat;//MAXIMUS: -[05.10.2007]->
	if(CheckAttribute(chr,"nation.name"))
	{
		if(nat==PIRATE || nat!=sti(chr.nation.name)) fakeNat = sti(chr.nation.name);//MAXIMUS: pirates can have a different own-nation <-[05.10.2007]-
	}
	// PB: Pretend to be of that nationality -->
/*	int fakeNat = GetCurrentFlag();
	if (fakeNat == PERSONAL_NATION) fakeNat = GetServedNation*/
	// PB: Pretend to be of that nationality <--
	bool bsex = chrsex(chr);
	switch(addrtype)
	{
		case ADDR_TITLE:
			retstr = stringret(GetRank(&chr, nat) > 0, XI_ConvertString(GetRankName(&chr, nat)), GetAddressForm(ADDR_TITLE, fakeNat, bsex));// MAXIMUS 16.10.2006 [changed 05.10.2007]
		break;
		case ADDR_IMPTITLE:
			retstr = stringret(GetRank(&chr, nat) > 0, XI_ConvertString(GetRankName(&chr, nat)), GetAddressForm(ADDR_IMPTITLE, fakeNat, bsex));// MAXIMUS 16.10.2006 [changed 05.10.2007]
		break;
		//default:
		retstr = GetAddressForm(addrtype, fakeNat, bsex);//MAXIMUS: 05.10.2007
	}
	
/*	if(fname)
		retstr += " " + chr.name;
	if(fname && lname && CheckAttribute(chr, "middlename"))
		retstr += " " + chr.middlename;
	if(lname)
		retstr += " " + chr.lastname;
	return retstr;	*/
	if (!CheckAttribute(chr, "lastname") || chr.lastname == "" || GetMyName(chr) == FirstLetterUp(chr.lastname))	// Character has only one name
	{
		if (fname || lname) retstr += " " + GetMyName(chr);
	}
	else
	{
		if(fname) retstr += " " + GetMyName(chr);
		if(fname && lname && CheckAttribute(chr, "middlename")) retstr += " " + chr.middlename;
		if(lname) retstr += " " + GetMyLastName(chr);
	}
	return retstr;
}
/**
 * Returns the officers address form as used e.g in the tailor's mod. But
 * it also takes into account the the nationality of the officer.
 */
string GetOfficerAddressForm(ref officer)
{
	return GetCharacterAddressForm(&officer, ADDR_CIVIL, true, true);
}	 
// Swindler <--

// gets the addressform of specified type of nation nat and for sex == "woman"
string GetAddressForm(int type, int nat, bool bsex)
{
	int idx = GetAddressIndex(type, nat, bsex);
	string retstr = AddressForms[idx];
	if(AddressForms[idx] != "" || nat == ENGLAND) return retstr; // for now check ENGLAND if blank
	return GetAddressForm(type, ENGLAND, bsex);
}

// gets the index of the address form. See above.
int GetAddressIndex(int type, int nat, bool bsex)
{
	// convert some address forms into their base types.
	// assume the only time we call TITLE and IMPTITTLE is if GetMyAddressForm() calls this; and the only time it would do that is
	// if the rank doesn't exist, so we go back to to CIVIL (for title) and POLITE (for imp. title)
	switch(type)
	{
		case ADDR_TITLE: type = ADDR_CIVIL; break;
		case ADDR_IMPTITLE: type = ADDR_POLITE; break;
	}
	return type * (MAX_NATIONS * 2) + (nat + 1) * 2 + bsex;
}

//RM put in dialog_func.c -->
//gets address form based on chr's nation
// 05-07-19 please DON'T use this!!!!
// use a GetMyAddressForm call above.
string GetMyNationAddress(ref chr, ref pchr)
{
	// PUT THESE IN COMMON.INI AND USE CONVERTSTRING!!!
	// rewritten 05-06-28 by NK
	string nataddr[MAX_NATIONS + 1];
// KK -->
	if(pchr.sex == "woman")
	{
		nataddr[SPAIN] = XI_ConvertString("Señorita");			//spell-checked by KAM
		nataddr[FRANCE] = XI_ConvertString("Mademoiselle");
		nataddr[ENGLAND] = XI_ConvertString("Miss");
		nataddr[PORTUGAL] = XI_ConvertString("Senhorita");
		nataddr[HOLLAND] = XI_ConvertString("Juffrouw");
	} else {
		nataddr[SPAIN] = XI_ConvertString("Señor");			//spell-checked by KAM
		nataddr[FRANCE] = XI_ConvertString("Monsieur");
		nataddr[ENGLAND] = XI_ConvertString("Mister"); // NK
		nataddr[PORTUGAL] = XI_ConvertString("Senhor");
		nataddr[HOLLAND] = XI_ConvertString("Mijnheer");
	}

	string nations = "0,1,2,4,5";
	nataddr[PIRATE] = nataddr[sti(GetRandSubString(nations))]; // argh. Oh well.
	nataddr[MAX_NATIONS] = XI_ConvertString("Comrade");

	if(CheckAttribute(chr,"nation.name") && sti(chr.nation.name)!=1) return nataddr[sti(chr.nation.name)];
	if(!CheckAttribute(chr,"nation")) return nataddr[ENGLAND];
	int iNation = sti(chr.nation);
	if (iNation == PERSONAL_NATION) iNation = MAX_NATIONS;
	return nataddr[iNation];
// <-- KK
}

// NAMES
//get chr's full name: Commodore Sir Nathaniel Hawk
//For more advanced things, use GetMyAddressForm() above...
string GetMyFullName(ref chr)
{
	string name = "";
	int nation = UNKNOWN_NATION;
	if (CheckAttribute(chr, "nation")) nation = sti(chr.nation);
	if(!CheckAttribute(chr,"name")) chr.name = name;//MAXIMUS -->
	if(!CheckAttribute(chr,"lastname")) chr.lastname = name;

	// PB: Include rank -->
	if (CheckAttribute(chr, "nation") && HasRank(chr, sti(chr.nation)) && sti(chr.nation) != PIRATE)
	{
		name = XI_ConvertString(GetRankName(chr, nation)) + " ";

		// GR: exclude "rank" for privateers of rank 7 or higher with honorific prefix, noble titles go at the end of the name
		if (GetRank(chr, nation) >= 7 && ProfessionalNavyNationChar(chr) == UNKNOWN_NATION && CheckAttribute(chr, "knighted")) name = "";
	}
	// PB: Include rank <--

	if (CheckAttribute(chr,"title")) {
		if (XI_ConvertString(chr.title) != "") chr.title = XI_ConvertString(chr.title);
		name += chr.title + " ";
	}
	name += GetMySimpleName(chr); // KK

	// GR: add noble title to the end of the name -->
	if (CheckAttribute(chr, "nation") && HasRank(chr, sti(chr.nation)) && sti(chr.nation) != PIRATE && GetRank(chr, nation) >= 7 && ProfessionalNavyNationChar(chr) == UNKNOWN_NATION && CheckAttribute(chr, "knighted"))
	{
		// Don't add noble title if it is exactly level 7 and from the same nation as prefix title. Knighthood is implied by the prefix.
		if (GetRank(chr, nation) > 7 || sti(chr.knighted) != nation)
		{
			name += ", " + XI_ConvertString(GetRankName(chr, nation));
		}
	}
	// GR: add noble title to the end of the name <--

	return name;
}

//get chr's simple name: Nathaniel Hawk or Christofor Manuel De Alencar
string GetMySimpleName(ref chr)
{
	string name = "";
	if (!CheckAttribute(chr,"name")) chr.name = name;//MAXIMUS
	if (!CheckAttribute(chr,"lastname")) chr.lastname = name;//MAXIMUS
	if (CheckAttribute(chr,"firstname")) {
		name = FirstLetterUp(chr.firstname); // KK
		if (CheckAttribute(chr,"middlename") == true && chr.middlename != "") {
			if (name != "") name += " "; // KK
			name += chr.middlename;
		} else {
			name += chr.firstname;
		}
	} else {
		if (chr.name != "") name += FirstLetterUp(chr.name);
		if (CheckAttribute(chr, "middlename") && chr.middlename != "") {
			if (name != "") name += " "; // KK
			name += chr.middlename;
		}
	}
// KK -->
	if(!HasSubStr(chr.lastname,"<") && !HasSubStr(chr.lastname,">") && chr.lastname!="") {
		if (name != "") name += " ";
		name += chr.lastname;
	}
// <-- KK
	return name;
}

//get chr's formal name: Nathaniel Hawk or Christofor Manuel De Alencar
//normally same as "GetMySimpleName", but fills in blank firstnames with Captain/Mister
string GetMyFormalName(ref chr)
{
	string name = "";
	if(!CheckAttribute(chr,"name")) chr.name = name;//MAXIMUS -->
	if(!CheckAttribute(chr,"lastname")) chr.lastname = name;
	if (CheckAttribute(chr,"title")) {
		if (XI_ConvertString(chr.title) != "") chr.title = XI_ConvertString(chr.title);
		name = chr.title + " ";
	}
	else
	{
		// PB: Use appropriate title if no first name available -->
		if (chr.name == "")
		{
			if(CheckAttribute(chr,"Ship.type") && chr.Ship.type!="" && chr.Ship.type!=SHIP_NOTUSED_TYPE_NAME)
			{
				name = XI_ConvertString("captain") + " "; // Use "Captain" if in command of a ship, but without rank
			}
			else
			{
				name = GetCharacterAddressForm(chr, ADDR_CIVIL, false, false) + " "; // Otherwise return a civil address form without name
			}
		}
		// PB: Use appropriate title if no first name available <--
	}

	name += GetMySimpleName(chr); // KK
	return name;
}

//get chr's first name; for "default" name (i.e. first if no title) just get chr.name.
string GetMyName(ref chr)
{
	string name = "";
	if(CheckAttribute(chr,"firstname")) { name += chr.firstname; }
	else { name += chr.name; }
	if (name == "" && CheckAttribute(chr, "lastname") && chr.lastname != "") name = chr.lastname;	// For characters such as Blackbeard
	return FirstLetterUp(name);
}

// KK -->
string GetMyFirstNames(ref chr, bool bNickname)
{
	string name = GetMyName(chr);
	if (CheckAttribute(chr, "middlename")) name += " " + chr.middlename;
	if (bNickname && CheckAttribute(chr, "nickname")) name += " '" + chr.nickname + "'";
	return name;
}
// <-- KK

string GetMyLastName(ref chr)
{
	string name = "";
	if(CheckAttribute(chr,"lastname")) { name += chr.lastname; }
	else { name += chr.name; }
	return name;
}

//get character's family name with a title, if he has one of them
string GetMyRespectfullyName(ref chr)
{
	string ourName = GetMyLastName(chr);
	if(!CheckAttribute(chr,"lastname")) chr.lastname = "";
	string name = "";
	if(CheckAttribute(chr,"title"))
	{
		string ourTitle = chr.title;
//		Check for knighthood titles given by 'GiveSwordAndPerks' in "NK.c"
//		Should be "Sir Francis", not "Sir Drake", for example
//		But only check to change to first name if you have a first name!
		if (GetMyName(chr) != "")
		{
			if(ourTitle == TranslateString("", "Dame") || ourTitle == TranslateString("", "Sir") ||
			   ourTitle == TranslateString("", "Chevalier") ||
			   ourTitle == TranslateString("", "Doña") || ourTitle == TranslateString("", "Don") ||
			   ourTitle == TranslateString("", "Dona") || ourTitle == TranslateString("", "Dom"))
			{
				ourName = GetMyName(chr);
			}
		}
		if(XI_ConvertString(chr.title)!="") ourTitle = XI_ConvertString(chr.title);
		if(ourName=="") name += ourTitle;
		else name += ourTitle + " " + ourName;
	}
	else
	{
		if(CheckAttribute(chr,"Ship.type") && chr.Ship.type!="" && chr.Ship.type!=SHIP_NOTUSED_TYPE_NAME) // PB: was SHIP_NOTUSED
		{
			if(chr.lastname=="") name += XI_ConvertString("captain");	// Was "Scaptain", which returns lower case "captain",
			else name += XI_ConvertString("captain") + " " + chr.lastname;	// which looks silly in introductions
		}
		else name += chr.lastname;
	}
	return name;
}


//translates #defined married state into string
string GetMarriedName(ref chr)
{
	if(CheckAttribute(chr,"married"))
	{
		switch(sti(chr.married))
		{
			case MR_MARRIED:
				if (chr.sex == "woman") return XI_ConvertString("wife");
				else return XI_ConvertString("husband");
			break;
			case MR_MISTRESS:
				if (chr.sex == "woman") return XI_ConvertString("mistress");
				else return XI_ConvertString("gentleman");
			break;
		}
	}
	return XI_ConvertString("friend");
}

// HSL 05-06-23 -->
string GetMyPronounSubj(ref chr)
{
	if(chr.sex == "woman")
	{
		return "she";
	}
	return "he";
}

string GetMyPronounObj(ref chr)
{
	if(chr.sex == "woman")
	{
		return "her";
	}
	return "him";
}


string GetMyPronounPoss(ref chr)
{
	if(chr.sex == "woman")
	{
		return "hers";
	}
	return "his";
}

string GetMyPronounPossessive(ref chr)	// Function output should be translated by XI_ConvertString
{
	if(chr.sex == "woman")
	{
		return "her1";		// Translates to "her" in English "common.ini"
	}
	return "his1";			// Translates to "his" in English "common.ini"
}

string GetMyPronoun(ref chr, string model)
{
	switch(model)
	{
		case "he": return XI_ConvertString(GetMyPronounSubj(&chr)); break;
		case "she": return XI_ConvertString(GetMyPronounSubj(&chr)); break;
		
		case "him": return XI_ConvertString(GetMyPronounObj(&chr)); break;
		case "her": return XI_ConvertString(GetMyPronounObj(&chr)); break;
		
		case "his": return XI_ConvertString(GetMyPronounPoss(&chr)); break;
		case "hers": return XI_ConvertString(GetMyPronounPoss(&chr)); break;
	}
	return XI_ConvertString(GetMyPronounObj(&chr));
}
// HSL <--

//returns name of model to use for MR
string FindMRModel(int rank)
{
	//rank = 10; //testing
	string modelch[2];
	int i;
	int size = 2;
	string sTown = GetCurrentTownID();
	int iNation;
	if (sTown == "") iNation = ENGLAND;
	else iNation = GetTownNation(sTown);
	ref PChar = GetMainCharacter();
	if (PChar.sex == "man")
	{
		if(rank<3) return "towngirl2";
		modelch[0] = "towngirl2";
		modelch[1] = "towngirl2_1";					// LDH fix name = 05Jan09
		if(rank>=3 && rank<8)
		{
			for(i = 0; i < 5; i++) //actually +1 because above
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "towngirl2";
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "towngirl2_1";	// LDH fix name = 05Jan09
			}
		}
		if(rank>=4)
		{
			for(i = 0; i < 9; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "towngirl5";
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "towngirl6";
			}
		}
		if(rank>=5)
		{
			for(i = 0; i < 11; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "towngirl3";
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "towngirl3_1";	// LDH fix name = 05Jan09
			}
		}
		if(rank>=6)
		{
			for(i = 0; i < 15; i++)
			{
				if (iNation == SPAIN || iNation == PORTUGAL)
				{
					size++;
					SetArraySize(&modelch,size);
					modelch[size-1] = "towngirl1_2"; // GR
					size++;
					SetArraySize(&modelch,size);
					modelch[size-1] = "towngirl1_3"; // GR
				}
				else
				{
					size++;
					SetArraySize(&modelch,size);
					modelch[size-1] = "towngirl1";
					size++;
					SetArraySize(&modelch,size);
					modelch[size-1] = "towngirl1_1";	// LDH fix name = 05Jan09
				}
			}
		}
		if(rank>=7)
		{
			for(i = 0; i < 11; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "towngirl7";
			}
	
			for(i = 0; i < 11; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "towngirl7_2"; // GR
			}
	
			for(i = 0; i < 24; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "towngirl4";
			}
	
			for(i = 0; i < 14; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "50_Rachel"; // GR
			}
	
			for(i = 0; i < 11; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "AnnaDeLeiva"; // GR
			}
		}
		if(rank>=8)
		{
			for(i = 0; i < 24; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				if (iNation == SPAIN || iNation == PORTUGAL)
				{
					modelch[size-1] = "liz2"; // GR
				}
				else
				{
					modelch[size-1] = "liz1"; // KK
				}
			}
	
			for(i = 0; i < 9; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "diz1"; // GR
			}
	
			for(i = 0; i < 9; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "diz2"; // GR
			}
	
			for(i = 0; i < 4; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "50_Petra2"; // GR
			}
		}
		if(rank>=9)
		{
			for(i = 0; i < 39; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "lady04_ab"; // GR
			}

			for(i = 0; i < 4; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "liz3"; // GR
			}
		}
		if(rank>=10)
		{
			for(i = 0; i < 44; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "lady6"; // GR
			}

			for(i = 0; i < 9; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "lady3"; // GR
			}
		}
		return modelch[rand(size-1)];
	}
	else
	{
		if(rank<3) return "Blaze_NB";
		modelch[0] = "Blaze_NB";
		modelch[1] = Nations[iNation].fantomModel.m1;
		if(rank>=3)
		{
			for(i = 0; i < 5; i++) //actually +1 because above
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = Nations[iNation].fantomModel.m2;
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = Nations[iNation].fantomModel.m3;
			}
		}
		if(rank>=4)
		{
			for(i = 0; i < 9; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = Nations[iNation].fantomModel.m0;
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "Corsair1_4";
			}
		}
		if(rank>=5)
		{
			for(i = 0; i < 11; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "Corsair3_J";
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "Corsair4_J";
			}
		}
		if(rank>=6)
		{
			for(i = 0; i < 15; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "47_JRMMLt1";
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "47_JRMMLcm";
			}
		}
		if(rank>=7)
		{
	
			for(i = 0; i < 35; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "47_JRMMCpt";
			}
	
			for(i = 0; i < 39; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				switch(iNation)
				{
					case ENGLAND: modelch[size-1] = "9JdEng"; break;
					case FRANCE: modelch[size-1] = "9JdFra"; break;
					case SPAIN: modelch[size-1] = "9JdSpa"; break;
					case PIRATE: modelch[size-1] = "9Jc"; break;
					case HOLLAND: modelch[size-1] = "9JdHol"; break;
					case PORTUGAL: modelch[size-1] = "9JdPor"; break;
					case GUEST1_NATION: modelch[size-1] = "9JdPor"; break;
					case GUEST2_NATION: modelch[size-1] = "9JdEng"; break;
				}
				modelch[size-1] = "9Jd";
			}
		}
		if(rank>=8)
		{
			for(i = 0; i < 24; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "Huber_Eng2_17";
			}
	
			for(i = 0; i < 19; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "Huber_Fra2_17";
			}
		}
		if(rank>=9)
		{
			for(i = 0; i < 39; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "Blood2";
			}

			for(i = 0; i < 4; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "LaCroix";
			}
		}
		if(rank>=10)
		{
			for(i = 0; i < 44; i++)
			{
				size++;
				SetArraySize(&modelch,size);
				modelch[size-1] = "hub_spa3";
			}
		}
		return modelch[rand(size-1)];
	}
}

//finds index of free MR
int FindFreeMR()
{
	int Counter, MRIdx;
	ref PChar;
	
	PChar = GetMainCharacter();
	if(sti(PChar.married)) return -1;
	string MRId;

	int i;

	for(counter = 0; counter <10; counter++)
	{
		MRId = "GovRel" + counter;
		MRIdx = GetCharacterIndex(MRId);		
		if(sti(Characters[MRIdx].talkpoints) == 0 && sti(Characters[MRIdx].married) == MR_SINGLE) return MRIdx;
	}

	return -1;
}

//clears locations of all unused MRs, run after meeting MR and /not/ talking with her.
void ClearMRLocations()
{
	ref PChar = GetMainCharacter();
	int Counter, MRIdx;
	string MRId;
	ref mr;
	ref gov;
	int i, qty;

	for(counter = 0; counter <10; counter++)
	{
		MRId = "GovRel" + counter;
		MRIdx = GetCharacterIndex(MRId);
		mr = GetCharacter(MRIdx);
		if((mr.married) == MR_SINGLE)
		{
			if(sti(mr.talkpoints) == 0 || sti(PChar.married))
			{
				mr.location = "none";
				if(CheckAttribute(mr,"father"))
				{
					gov = GetCharacter(GetCharacterIndex(mr.father));
					if(CheckAttribute(gov,"MRs."+MRId))
					{
						aref mrs;
						makearef(mrs, gov.MRs);
						DeleteAttribute(gov,"MRs."+MRId);
						if(GetAttributesNum(mrs))
						{
							gov.currentMR = GetAttributeName(GetAttributeN(mrs,rand(GetAttributesNum(mrs)-1)));
						}
						else {DeleteAttribute(gov,"currentMR"); }
					}
					DeleteAttribute(mr,"father");
				}
			}
		}
	}
}

//sets gov's current MR to given MR
void SetCurrentMR(ref mr)
{
	//Added check by levis to prevent errors
	if(CheckAttribute(mr,"father"))
	{
		ref gov = CharacterFromID(mr.father);
		gov.currentMR = mr.id;
	}
	else
	{
		trace("SetCurrentMR failed");
	}
}

//sets up first free MR and teleports to pchar.location
bool SetupMR(ref pchar, ref govchar)
{
	if(CheckAttribute(govchar,"currentMR.relationtype")) return false;//MAXIMUS: prevents from doubled MRs in location
	int mridx = FindFreeMR();
	if(mridx == -1) return false;
	ref mr = GetCharacter(mridx);
	mr.quest.officertype = OFFIC_TYPE_CIVILIAN;
	int offset = sti(pchar.rank);
	if(offset >= 12) offset = -10;
	else offset = 0 - offset/2;
	LAi_Create_Officer(offset, mr);
	
	string MRID = mr.id;
	int nation = sti(govchar.nation);
	if(GetRank(pchar, nation) < 3) return false;
	if(!DEBUG && frnd() > MR_INTRODUCE_CHANCE + sqrt(GetFame(pchar,nation))*MR_INTR_CH_RANK_SCL) return false;
	if(!DEBUG && "" + environment.date.day + " " + environment.date.month == govchar.quest.Meeting) return false;
	int MRs = 0;
	aref govmrs;
	makearef(govmrs, govchar.MRs);
	MRs = GetAttributesNum(govmrs);
	if(MRs > MR_MAXNUM) return false;
	MRs++;
	govchar.MRs.(MRID) = true;
	
	govchar.currentMR = MRID;
	mr.marpoints = MRCalcMarpoints(&pchar, nation);
	if(DEBUGINFO) Log_SetStringToLog("MP: " + mr.marpoints + ", " + stf(mr.marpoints)/GetFame(pchar, nation) + "x fame");
	if(pchar.sex == "man")
	{
		mr.sex = "woman";
		if(frnd() < sti(mr.marpoints)/MR_DAUGHTER_THRESH) mr.relationtype = "daughter";
		else mr.relationtype = "niece";
	}
	else
	{
		mr.sex = "man";
		if(frnd() < sti(mr.marpoints)/MR_DAUGHTER_THRESH) mr.relationtype = "son";
		else mr.relationtype = "nephew";
	}

	mr.nation = nation;
	SetRandomNameToCharacter(mr);
	mr.lastname = govchar.lastname;
	mr.father = govchar.id;

	govchar.currentMR.relationtype = mr.relationtype;
//	mr.model = FindMRModel(GetRank(pchar,nation));		// GR: simply setting model like this does not set animation for special types
//	facemaker(mr);
	SetModelFromID(mr, FindMRModel(GetRank(pchar,nation)));	// GR: use the proper function!
	mr.talkpoints = 0;
	mr.dialog.currentnode = "First Time";
	mr.dialog.TempNode = "First Time";
	mr.pcounter = 0;
	mr.married = 0;
	if(mr.location == pchar.location) // if debugging above
	{
		SendMessage(mr, "lss", MSG_CHARACTER_SETMODEL, mr.model, mr.model.animation);
	}
	PlaceCharacter(&mr, "goto");
	return true;
}

void SetCoastalEnemy(string model, string sex, string name, string lastname)
{
	ref Pchar = GetMainCharacter();
	ref rCap1 = CharacterFromID("Coastal_Captain01");

	Group_CreateGroup("Coastal_Guards");
	GenerateQuestShip("Enemy_Captain01", GetCurrentLocationNation()); // PB: Use Generic Function
	SetModelFromID(rCap1, model);
	rCap1.name 	= name;
	rCap1.lastname = lastname;
	if(sex=="woman")
	{
		rCap1.sex = sex;
		rCap1.ani ="woman";
	}
//	SetCharacterRelationBoth(GetCharacterIndex("Enemy_Captain01"),GetMainCharacterIndex(),RELATION_ENEMY); // PB: Is already done by Group_SetTaskAttack
	Group_AddCharacter("Coastal_Enemies", "Enemy_Captain01");
	Group_SetGroupCommander("Coastal_Enemies", "Enemy_Captain01");

	if(GetCompanionQuantity(Pchar) > 1 || makeint(Pchar.rank) > 50)
	{
		GenerateQuestShip("Enemy_Captain02", GetCurrentLocationNation()); // PB: Use Generic Function
		Group_addCharacter("Coastal_Enemies", "Enemy_Captain02");
	}

	Group_SetTaskAttack("Coastal_Enemies", PLAYER_GROUP, true);
	Group_LockTask("Coastal_Enemies");
	Group_SetPursuitGroup("Coastal_Enemies", PLAYER_GROUP);
	Group_SetAddress("Coastal_Enemies", Islands[GetCharacterCurrentIsland(Pchar)].id, "", "");
}

// KK -->
//MAXIMUS: changes, which was made here:
//Only Enc_Officer can be hired now. If we haven't free Enc_Officer - NPC will reject our suggestion
//NPC will stay in location, until we'll not leave this location
void TIH_PrisonerHiredAsOfficerProcess(ref RefChar, bool bLowSalary, bool bSetType, bool bCreateOfficer)
{
	if(FindFreeRandomOfficer()==-1) { RefChar.Dialog.CurrentNode = "officer"; DialogMain(RefChar); return; }
	ref PChar = GetMainCharacter();
	int freeidx = FindFreeRandomOfficer();

	RemovePassenger(PChar, RefChar);

	if (CheckAttribute(RefChar, "prisoned")) DeleteAttribute(RefChar, "prisoned");
	if (CheckAttribute(RefChar, "status")) DeleteAttribute(RefChar, "status");
	if (CheckAttribute(RefChar, "ransom")) DeleteAttribute(RefChar, "ransom");
	if (CheckAttribute(RefChar, "released")) DeleteAttribute(RefChar, "released");
	if (CheckAttribute(RefChar, "position")) DeleteAttribute(RefChar, "position");
	if (CheckAttribute(RefChar, "fight")) DeleteAttribute(RefChar, "fight");
	if (CheckAttribute(RefChar, "cabinfight")) DeleteAttribute(RefChar, "cabinfight");
	if (CheckAttribute(RefChar, "CompanionEnemyEnable")) DeleteAttribute(RefChar, "CompanionEnemyEnable");

	// these do fixing
	if(RefChar.sex=="woman") RefChar.greeting = "Gr_Officer_f common";
	else RefChar.greeting = "Gr_Officer_m common";
	RefChar.Dialog.Filename = "Enc_Officer_dialog.c";
	RefChar.Dialog.CurrentNode = "Hired";

	Pchar.quest.HiringOfficerIDX = RefChar.index;
	Pchar.quest.FreeRandomOfficerIdx = Characters[freeidx].index;
	Pchar.quest.FreeRandomOfficerID = Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)].id;

	trace("Free Random Officer IDX is " + Pchar.quest.FreeRandomOfficerIdx + " and he has id  " + Pchar.quest.FreeRandomOfficerID);

	CopyAttributes(&Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)], &Characters[makeint(Pchar.quest.HiringOfficerIDX)]);

	Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)].index = Pchar.quest.FreeRandomOfficerIdx;
	Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)].id = Pchar.quest.FreeRandomOfficerID;
	Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)].location = "None";
	Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)].Dialog.Filename = "Enc_Officer_dialog.c";
	Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)].Dialog.CurrentNode = "hired";
	Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)].AbordageMode = makeint(1);
	ref NewOfficer = &Characters[makeint(Pchar.quest.FreeRandomOfficerIdx)];
	DeleteAttribute(Pchar, "quest.FreeRandomOfficerIdx");
	DeleteAttribute(Pchar, "quest.FreeRandomOfficerID");
	DeleteAttribute(Pchar, "quest.HiringOfficerIDX");

//	RefChar.AbordageMode = 1;// boal 05.09.03 officer set to go to abordage

//	if (!CheckAttribute(RefChar, "model.entity")) 	RefChar.model.entity = "NPCharacter";// ? sometimes was an error - "can't create class"
//	if (!CheckAttribute(RefChar, "noFollowType")) 	RefChar.noFollowType = "nofollow";// ? new identifier for template LAi_follow.c
	if (!CheckAttribute(NewOfficer, "money")) NewOfficer.money = makeint(0);// ? was a bug with not existent money

	NewOfficer.chr_ai.type = "officer";
	if(bSetType) LAi_SetOfficerType(NewOfficer);
	NewOfficer.offgen = true;
	NewOfficer.officer = true;
	NewOfficer.friend = true;
	NewOfficer.land = "0";
	NewOfficer.nation = GetServedNation();
	NewOfficer.nation.name = RefChar.nation;
	NewOfficer.location = "none";
	if ( CheckAttribute(NewOfficer,"wealth") )  			NewOfficer.wealth = makeint(NewOfficer.wealth);// clean up the ungainly float!
	if ( CheckAttribute(NewOfficer,"quest.officertype") )	NewOfficer.current = NewOfficer.quest.officertype;

	// if they joined freely (no cost), they have a low salary ?
	if ( CheckAttribute(NewOfficer,"quest.officerprice") ) {
		if (bLowSalary) NewOfficer.quest.officerprice = makeint( sti(NewOfficer.quest.officerprice) / 2 );
	}

	if (!CheckCharacterEquipByGroup(NewOfficer, BLADE_ITEM_TYPE)) // KK
		LAi_NPC_Equip(NewOfficer, sti(NewOfficer.rank), true, 0);// give the officer some weapons and equip them (NO GUN)

	// move any money they may have into their wealth, so MC can't steal their money
	if (CheckAttribute(NewOfficer,"money") && sti(NewOfficer.money) > 0)
	{
		if (!CheckAttribute(NewOfficer,"wealth")) { NewOfficer.wealth = 0; } // set if not set
		NewOfficer.wealth = makeint(sti(NewOfficer.wealth) + sti(NewOfficer.money)); // merge together into wealth
		NewOfficer.money = 0; // clear out their money now that its moved
	}
	NewOfficer.old.chr_ai.group = "player";
	NewOfficer.chr_ai.group = "player";

	LAi_group_MoveCharacter(NewOfficer, LAI_GROUP_PLAYER);
	LAi_group_MoveCharacter(RefChar, LAI_GROUP_PLAYER);
	RefChar.location = "none";
	RefChar.friend = true;
	if(bSetType) LAi_SetOfficerType(RefChar);

	AddPassenger(PChar,NewOfficer,false);// just add them as a passenger for now
	LAi_SetOfficerType(RefChar);
	RefChar.ClearUponExit = true;		// GR: wipe the original Enc_CabinCaptain to free up his slot
}
//MAXIMUS: changes, which were made here:
//All code for prisoner was moved from Cabinfight_dialog.c
//FindFreeRandomOfficer changed to FindFreeCabinCaptain, because we do not need to create an officer on this stage
//Also added check for Enc_CabinCaptain - not need to make him twice
//Also added small action (if we haven't free Enc_CabinCaptain): angry NPC will attack player
void TIH_PrisonerTakenProcess(ref RefChar, bool bPurgeCrud)
{
	ref PChar = GetMainCharacter();
	ref Prisoner = &NullCharacter();
	int PrisonerIdx;
	string PrisonerID;
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	if(CORPSEMODE==4)
	{
		if(!CheckAttribute(RefChar,"money")) RefChar.money = "0";
		if(!CheckAttribute(RefChar,"wealth")) RefChar.wealth = "0";
		RefChar.money = sti(RefChar.money) + sti(RefChar.wealth);
		RefChar.wealth = "0";
	}

	//PChar.quest.HiringOfficerIDX = GetCharacterIndex(RefChar.id);

	int freeidx = sti(RefChar.index);
	if(!HasSubStr(RefChar.id,"Enc_CabinCaptain")) freeidx = FindFreeCabinCaptain();// get an open officer slot to use (50 maximum)
	if(freeidx != -1)
	{
		//trace("-----------------------------------------------------------------");
		//trace("dialog_func.c:");

		// cleaner method
		PrisonerIdx		= sti(Characters[freeidx].index);
		Prisoner		= GetCharacter(PrisonerIdx);
		PrisonerID		= Prisoner.id;// store this because we have to put it back after the copyattr

		//PChar.quest.PrisonerIdx = PrisonerIdx;// store for second function

		//	trace("Free Random Officer IDX is " + PrisonerIdx + " and he has id  " + PrisonerID);

		if(!HasSubStr(RefChar.id,"Enc_CabinCaptain"))
		{
			CopyAttributes(&Prisoner, &RefChar);// copy all attr from the reference character (the hiring officer) to the new officer char

			Prisoner.index = PrisonerIdx;// reset these after the copyattr
			Prisoner.id    = PrisonerID; // reset these after the copyattr
		}

		DisarmCharacter(Prisoner, true, false);

		if(!CheckAttribute(RefChar, "honourable_surrender"))	// GR: Only take prisoner's money if you did not offer honourable surrender terms
		{
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar,sti(Prisoner.money));
			Log_SetStringToLog(TranslateString("","CaptainMoney1")+" "+MakeMoneyShow(sti(Prisoner.money),"",MONEY_DELIVER)+" "+TranslateString("","CaptainMoney2"));
		}
		if(Prisoner.sex=="woman") Prisoner.greeting = "Gr_Pirate_f";
		else Prisoner.greeting = "Gr_Clauss"; // was "Gr_Dark Teacher" which is identical
		boarding_enemy.status = "dead";
		boarding_enemy.position = "captive";
		PlayStereoSound("AMBIENT\JAIL\jail_door2.wav");

		//trace("New Officer IDX is " + Prisoner.index + " and he has id  " + Prisoner.id);
		//trace("dialog_func.c - > officer dump before cleaning:"); DumpAttributes( Characters[sti(PChar.quest.PrisonerIdx)] );

		// these do fixing
		/*if(Prisoner.sex == "woman") 	Prisoner.greeting = "Gr_Officer_f common";
		else 							Prisoner.greeting = "Gr_Officer_m common";*/
		Prisoner.Dialog.Filename = "Prisoned_dialog.c";
		Prisoner.Dialog.CurrentNode = "First time";
		//Prisoner.AbordageMode = 1;// boal 05.09.03 officer set to go to abordage

		// TIH --> suggested additions from maximus, adjusted for this code Aug29'06
// TIH --> no, see if this attr doesnt exist for NEW officer, its because REF officer didn't have it in the first place, so trying to assign it the null field again is a bit pointless and dangerous - Oct30'06
//		if (!CheckAttribute(Prisoner,"location.locator") && CheckAttribute(RefChar, "location.locator")) Prisoner.location.locator = RefChar.location.locator;// ? was a bug with not existent location.locator // KK now that should be OK 
//		if (!CheckAttribute(Prisoner,"location.locator"))	Prisoner.location.locator = "";// TIH - actually set it to nothing for fresh reset - Oct30'06
// TIH <--
		if (!CheckAttribute(Prisoner,"model.entity")) 	Prisoner.model.entity = "NPCharacter";// ? sometimes was an error - "can't create class"
		if (!CheckAttribute(Prisoner,"noFollowType")) 	Prisoner.noFollowType = "nofollow";// ? new identifier for template LAi_follow.c
		if (!CheckAttribute(Prisoner,"money")) 			Prisoner.money = 1+rand(100);// ? was a bug with not existent money
		// TIH <--

		if (bPurgeCrud) {// purge a whole bunch of broken crud that causes bugs for this new officer (captured captains only)
			if ( CheckAttribute(Prisoner,"ship") ) 			DeleteAttribute(Prisoner,"ship");
			if ( CheckAttribute(Prisoner,"shiptype") ) 		DeleteAttribute(Prisoner,"shiptype");
			if ( CheckAttribute(Prisoner,"shipmoney") ) 	DeleteAttribute(Prisoner,"shipmoney");
			if ( CheckAttribute(Prisoner,"curshipnum") ) 	DeleteAttribute(Prisoner,"curshipnum");
			if ( CheckAttribute(Prisoner,"seaai") ) 		DeleteAttribute(Prisoner,"seaai");
			if ( CheckAttribute(Prisoner,"features") ) 		DeleteAttribute(Prisoner,"features");
			if ( CheckAttribute(Prisoner,"seatime") ) 		DeleteAttribute(Prisoner,"seatime");
			if ( CheckAttribute(Prisoner,"relation") ) 		DeleteAttribute(Prisoner,"relation");
			if ( CheckAttribute(Prisoner,"fantomtype") ) 	DeleteAttribute(Prisoner,"fantomtype");
			if ( CheckAttribute(Prisoner,"canfiretime") ) 	DeleteAttribute(Prisoner,"canfiretime");
			if ( CheckAttribute(Prisoner,"rankscale") ) 	DeleteAttribute(Prisoner,"rankscale");
			if ( CheckAttribute(Prisoner,"tmpperks") ) 		DeleteAttribute(Prisoner,"tmpperks");
			if ( CheckAttribute(Prisoner,"tmpskill") ) 		DeleteAttribute(Prisoner,"tmpskill");
			if ( CheckAttribute(Prisoner,"points") ) 		DeleteAttribute(Prisoner,"points");
			if ( CheckAttribute(Prisoner,"randofficers") ) 	DeleteAttribute(Prisoner,"randofficers");
			if ( CheckAttribute(Prisoner,"skillnatmult") ) 	DeleteAttribute(Prisoner,"skillnatmult");
			if ( CheckAttribute(Prisoner,"nodisarm") ) 		DeleteAttribute(Prisoner,"nodisarm");
			if ( CheckAttribute(Prisoner,"points") ) 		DeleteAttribute(Prisoner,"points");
			if ( CheckAttribute(Prisoner,"isFantom") ) 		DeleteAttribute(Prisoner,"isFantom");
		}
		//Prisoner.location.group = "officers";// not needed
		//Prisoner.chr_ai.type = "officer";
		//Prisoner.offgen = true;
		//Prisoner.officer = true;
		//Prisoner.friend = true;
		Prisoner.prisoned = true;
		Prisoner.land = "0";
		Prisoner.wealth = "0";

		AddPassenger(PChar, Prisoner, true);// just add them as a passenger for now
		ChangeCharacterAddressGroup(RefChar, "None", "", "");  // get rid of the reference character
		ChangeCharacterAddressGroup(Prisoner, "None", "", ""); // PB: To prevent him from showing on future boardings
		LAi_EnableReload();

		// keep the PrisonerIdx attribute, as its needed in the second function

		//trace("dialog_func.c -> officer dump at end:"); DumpAttributes( Characters[sti(PChar.quest.PrisonerIdx)] );
		//trace("-----------------------------------------------------------------");
	}
	else
	{
		LAi_SetImmortal(RefChar, false);
		LAi_SetPlayerType(PChar);
		if(CORPSEMODE<4) { if(CheckAttribute(RefChar,"location")) RefChar.location = "none"; }
		boarding_enemy.status = "dead";
		boarding_enemy.position = "corpse";
		LAi_group_MoveCharacter(RefChar, LAI_GROUP_BRDENEMY);
		LAi_group_FightGroups(LAI_GROUP_BRDENEMY, LAI_GROUP_PLAYER, true);
		LAi_group_SetCheck(LAI_GROUP_BRDENEMY, "Abordage_End"); // PB was: LAi_group_SetCheckEvent(LAI_GROUP_BRDENEMY);

//		Log_SetStringToLog(QUEST_MESSAGE12);
	}
	//LanguageCloseFile(tmpLangFileID);
	//DeleteAttribute(Pchar, "quest.HiringOfficerIDX");// deleted here, because we certainly no longer need it now
//	if (bAbordageStarted) refEnCharacter = Prisoner;//commented by MAXIMUS: we need this? for what?
}

// LDH -->  03Sep06  Reset AlwaysRunToggle if it was changed before boarding cabin dialog
void RestoreAlwaysRunState()
{
	return;
	/*if (!ACTOR_WHEN_BOARDING) return;
	if (HasSubStr(Locations[FindLoadedLocation()].filespath.models, "locations\decks\deckLowVS")) return;
	ref mchr = GetMainCharacter();
	if (CheckAttribute(mchr, "SavedAlwaysRunToggle") == true && sti(mchr.SavedAlwaysRunToggle) == true) {
		AlwaysRunToggle = true;		// global alwaysrun variable, set by K key
		BeginChangeCharacterActions(mchr);
		SetDefaultNormWalk(mchr);
		SetDefaultFight(mchr);
		EndChangeCharacterActions(mchr);
		DeleteAttribute(mchr, "SavedAlwaysRunToggle");
	}*/
}
// LDH <--

// Riley -->
void Riley_Restock_Ammo(int chridx, int gunpowder, int pistol_bullets, int grapeshot, int musket_bullets, int theprice)
{
// KK -->
	if (chridx >= 0 && IsCompanion(GetCharacter(chridx)) == false) return;
	ref mchr = GetMainCharacter();
	int companionsq = 1;
	if (chridx < 0) companionsq = GetCompanionQuantity(mchr);
	float fgp = makefloat(gunpowder) / makefloat(companionsq);
	int gpratio = makeint(fgp);
	fgp -= makefloat(gpratio);
	float fpb = makefloat(pistol_bullets) / makefloat(companionsq);
	int pbratio = makeint(fpb);
	fpb -= makefloat(pbratio);
	float fgs = makefloat(grapeshot) / makefloat(companionsq);
	int gsratio = makeint(fgs);
	fgs -= makefloat(gsratio);
	float fmb = makefloat(musket_bullets) / makefloat(companionsq);
	int mbratio = makeint(fmb);
	fmb -= makefloat(mbratio);
	float ftp = makefloat(theprice) / makefloat(companionsq);
	int tpratio = makeint(ftp);
	ftp -= makefloat(tpratio);

	if (chridx < 0 || chridx == GetMainCharacterIndex()) {
		// restock the weapons locker in the captain's cabin
		ref _loc = &Locations[FindLocation("Tutorial_Deck")];
	
		if (CheckAttribute(_loc, "weaponslocker.items.gunpowder")) {
			_loc.weaponslocker.items.gunpowder = sti(_loc.weaponslocker.items.gunpowder) + gpratio + (fgp > 0.0);
		} else {
			_loc.weaponslocker.items.gunpowder = gpratio + (fgp > 0.0);
		}
		if (CheckAttribute(_loc, "weaponslocker.items.pistolbullets")) {
			_loc.weaponslocker.items.pistolbullets = sti(_loc.weaponslocker.items.pistolbullets) + pbratio + (fpb > 0.0);
		} else {
			_loc.weaponslocker.items.pistolbullets = pbratio + (fpb > 0.0);
		}
		if (CheckAttribute(_loc, "weaponslocker.items.pistolgrapes")) {
			_loc.weaponslocker.items.pistolgrapes = sti(_loc.weaponslocker.items.pistolgrapes) + gsratio + (fgs > 0.0);
		} else {
			_loc.weaponslocker.items.pistolgrapes = gsratio + (fgs > 0.0);
		}
		if (CheckAttribute(_loc, "weaponslocker.items.musketbullets")) {
			_loc.weaponslocker.items.musketbullets = sti(_loc.weaponslocker.items.musketbullets) + mbratio + (fmb > 0.0);
		} else {
			_loc.weaponslocker.items.musketbullets = mbratio + (fmb > 0.0);
		}
		Log_SetStringToLog(GetMyShipNameShow(mchr) + " " + XI_ConvertString("weapons locker") + ": " + (gpratio + (fgp > 0.0)) + " " + XI_ConvertString("wgunpowder") + ", "  + (pbratio + (fpb > 0.0)) + " " + XI_ConvertString("wpistol bullets") + ", " + (gsratio + (fgs > 0.0)) + " " + XI_ConvertString("wgrapeshot loads") + ", " +  (mbratio + (fmb > 0.0)) + " " + XI_ConvertString("wmusket bullets purchased for") + " " + (tpratio + (ftp * tpratio)) + " " + XI_ConvertString("wgold") + ".");
	}

	for (int i = 1; i < COMPANION_MAX; i++) {
		if (chridx == GetMainCharacterIndex()) break;
		int cn = GetCompanionIndex(mchr, i);
		if (cn < 0) continue;
		if (chridx != cn && chridx > -1) continue;
		// restock the weapons locker in the companion's cabin
		_loc = &Locations[FindLocation("Companion_Cabin_" + i)];
	
		if (CheckAttribute(_loc, "weaponslocker.items.gunpowder")) {
			_loc.weaponslocker.items.gunpowder = sti(_loc.weaponslocker.items.gunpowder) + gpratio;
		} else {
			_loc.weaponslocker.items.gunpowder = gpratio;
		}
		if (CheckAttribute(_loc, "weaponslocker.items.pistolbullets")) {
			_loc.weaponslocker.items.pistolbullets = sti(_loc.weaponslocker.items.pistolbullets) + pbratio;
		} else {
			_loc.weaponslocker.items.pistolbullets = pbratio;
		}
		if (CheckAttribute(_loc, "weaponslocker.items.pistolgrapes")) {
			_loc.weaponslocker.items.pistolgrapes = sti(_loc.weaponslocker.items.pistolgrapes) + gsratio;
		} else {
			_loc.weaponslocker.items.pistolgrapes = gsratio;
		}
		if (CheckAttribute(_loc, "weaponslocker.items.musketbullets")) {
			_loc.weaponslocker.items.musketbullets = sti(_loc.weaponslocker.items.musketbullets) + mbratio;
		} else {
			_loc.weaponslocker.items.musketbullets = mbratio;
		}
		Log_SetStringToLog(GetMyShipNameShow(&characters[cn]) + " " + XI_ConvertString("weapons locker") + ": " + gpratio + " " + XI_ConvertString("wgunpowder") + ", "  + pbratio + " " + XI_ConvertString("wpistol bullets") + ", " + gsratio + " " + XI_ConvertString("wgrapeshot loads") + ", " +  mbratio + " " + XI_ConvertString("wmusket bullets purchased for") + " " + tpratio + " " + XI_ConvertString("wgold") + ".");
	}
// <-- KK
	PlayStereoSound("interface\took_item.wav");
}

void Riley_Officer_Restock_Ammo(int officer_price)
{
// restock the officer's and your own ammo and gunpowder supply

	if (!ENABLE_AMMOMOD) return;	// LDH -- skip if ammo mod is not enabled

	ref _refCharacter = GetMainCharacter();
	int psgQuant = GetPassengersQuantity(_refCharacter);

	int gunpowder_officers = 0;
	int pistolbullets_officers = 0;
	int pistolgrapes_officers = 0;
	int musketbullets_officers = 0;
	int pistolbulletcheck = 0;
	int max_powder = 6;
	int max_ammo = 6;

	string pb_sgpl = " " + XI_ConvertString("wpistol bullets") + ", ";
	string pg_sgpl = " " + XI_ConvertString("wgrapeshot loads") + ", ";
	string mb_sgpl = " " + XI_ConvertString("wmusket bullets bought for") + " ";
	if (LAi_IsCapturedLocation) mb_sgpl = " " + XI_ConvertString("wmusket bullets taken"); // KK
			
	ref curChar;
	int cn;
	for(int i=0;i<psgQuant;i++)
	{
		cn = GetPassenger(_refCharacter,i);
		if(cn==-1) break;

		curChar = GetCharacter(cn);
		if(CheckAttribute(curChar,"prisoned"))
		{
			if(sti(curChar.prisoned)==true) continue;
		}
		pistolbulletcheck = 0;

		// checking for powder flask, ammo pouch, powder barrel and ammunition bag
		max_powder = MAX_GUNPOWDER;
		max_ammo = MAX_SHOTS;
		if(CheckCharacterItem(curChar,"powderflask") > 0) { max_powder = (2 * MAX_GUNPOWDER); }
		if(CheckCharacterItem(curChar,"powderbarrel") > 0) { max_powder = (4 * MAX_GUNPOWDER); }
		if(CheckCharacterItem(curChar,"ammopouch") > 0) { max_ammo = (2 * MAX_SHOTS); }
		if(CheckCharacterItem(curChar,"ammobag") > 0) { max_ammo = (4 * MAX_SHOTS); }

		// restock gunpowder to max_powder loads if the amount of gunpowder is < max_powder.

		if(sti(curChar.items.gunpowder) < max_powder)
		{
			gunpowder_officers += max_powder - sti(curChar.items.gunpowder);
			curChar.items.gunpowder = max_powder;
		}

		// restock pistolgrapes to max_ammo loads, if a grapeshot pistol or musketoon is equipped and the amount of pistolgrapes is < max_ammo.
		if(IsEquipCharacterByItem(curChar, "pistol3-2") || IsEquipCharacterByItem(curChar, "pistol3-1") || IsEquipCharacterByItem(curChar, "pistol3") || IsEquipCharacterByItem(curChar, "pistol3+1") || IsEquipCharacterByItem(curChar, "pistol3+2") || IsEquipCharacterByItem(curChar, "pistol3+3") || IsEquipCharacterByItem(curChar, "pistolmtoon"))
		{
			pistolbulletcheck++;

			if(sti(curChar.items.pistolgrapes) < max_ammo)
			{
				pistolgrapes_officers += max_ammo - sti(curChar.items.pistolgrapes);
				curChar.items.pistolgrapes = max_ammo;
			}
			curChar.items.pistolbullets = 0;
			curChar.items.musketbullets = 0;
		}

		// restock musketbullets to (max_ammo/2) loads, if a musket is equipped and the amount of musketbullets is < (max_ammo/2).
		if(IsEquipCharacterByItem(curChar, "pistolmket"))
		{
			pistolbulletcheck++;

			if(sti(curChar.items.musketbullets) < (max_ammo/2))
			{
				musketbullets_officers += (max_ammo/2) - sti(curChar.items.musketbullets);
				curChar.items.musketbullets = (max_ammo/2);
			}
			curChar.items.pistolbullets = 0;
			curChar.items.pistolgrapes = 0;
		}

		// restock pistol bullets to max_ammo, if grapes and musketbullets were not restocked before and the amount of pistolbullets is < max_ammo.
		if(pistolbulletcheck == 0)
		{

			if(sti(curChar.items.pistolbullets) < max_ammo)
			{
				pistolbullets_officers += max_ammo - sti(curChar.items.pistolbullets);
				curChar.items.pistolbullets = max_ammo;
			}
			curChar.items.pistolgrapes = 0;
			curChar.items.musketbullets = 0;
		}
	}

	if(officer_price > 0)
	{
		// singular / plural check for words. Wheeeee! :)
		if(pistolbullets_officers == 1)pb_sgpl = " " + XI_ConvertString("wpistol bullet") + ", ";
		if(pistolgrapes_officers == 1)pg_sgpl = " " + XI_ConvertString("wgrapeshot load") + ", ";
		if(musketbullets_officers == 1)mb_sgpl = " " + XI_ConvertString("wmusket bullet bought for") + " ";
		// Log entry and sound
		Log_SetStringToLog(XI_ConvertString("Officers") + ": " + gunpowder_officers + " " + XI_ConvertString("wgunpowder") + ", "  + pistolbullets_officers + pb_sgpl + pistolgrapes_officers + pg_sgpl +  musketbullets_officers + mb_sgpl + officer_price + " " + XI_ConvertString("wgold") + ".");
		PlaySound("interface\officers_ammo.wav");
	}
// KK -->
	if (LAi_IsCapturedLocation) {
		// singular / plural check for words. Wheeeee! :)
		if(pistolbullets_officers == 1)pb_sgpl = " " + XI_ConvertString("wpistol bullet") + ", ";
		if(pistolgrapes_officers == 1)pg_sgpl = " " + XI_ConvertString("wgrapeshot load") + ", ";
		if(musketbullets_officers == 1)mb_sgpl = " " + XI_ConvertString("wmusket bullet taken");
		// Log entry and sound
		Log_SetStringToLog(XI_ConvertString("Officers") + ": " + gunpowder_officers + " " + XI_ConvertString("wgunpowder") + ", "  + pistolbullets_officers + pb_sgpl + pistolgrapes_officers + pg_sgpl +  musketbullets_officers + mb_sgpl + ".");
		PlaySound("interface\officers_ammo.wav");
	}
// <-- KK
}

int Riley_Officer_Restock_Ammo_Price()
{
	if (!ENABLE_AMMOMOD) return 0;		// LDH -- skip if ammo mod is not enabled
	if (LAi_IsCapturedLocation) return 0; // KK

	// restock the officer's and your own ammo and gunpowder supply
	ref _refCharacter = GetMainCharacter();
	int psgQuant = GetPassengersQuantity(_refCharacter);

	int gunpowder_officers = 0;
	int pistolbullets_officers = 0;
	int pistolgrapes_officers = 0;
	int musketbullets_officers = 0;
	int pistolbulletcheck = 0;
	int officer_restock_price = 0;
	int maxpowder = MAX_GUNPOWDER;
	int maxammo = MAX_SHOTS;

	ref curChar;
	int cn;
	for(int i=0;i<psgQuant;i++)
	{
		cn = GetPassenger(_refCharacter,i);
		if(cn==-1) break;

		curChar = GetCharacter(cn);
		if(CheckAttribute(curChar,"prisoned"))
		{
			if(sti(curChar.prisoned)==true) continue;
		}
		pistolbulletcheck = 0;
		

		// checking for powder flask, ammo pouch, powder barrel and ammunition bag
		maxpowder = MAX_GUNPOWDER;
		maxammo = MAX_SHOTS;
		if(CheckCharacterItem(curChar,"powderflask") > 0) { maxpowder = (2 * MAX_GUNPOWDER); }
		if(CheckCharacterItem(curChar,"powderbarrel") > 0) { maxpowder = (4 * MAX_GUNPOWDER); }
		if(CheckCharacterItem(curChar,"ammopouch") > 0) { maxammo = (2 * MAX_SHOTS); }
		if(CheckCharacterItem(curChar,"ammobag") > 0) { maxammo = (4 * MAX_SHOTS); }

		// restocking gunpowder to maxpowder loads if the amount of gunpowder is < 24.

		if (CheckAttribute(curChar, "items.gunpowder") == true && sti(curChar.items.gunpowder) < maxpowder) gunpowder_officers += maxpowder - sti(curChar.items.gunpowder); // KK

		// restocking pistolgrapes to maxammo loads, if a grapeshot pistol or musketoon is equipped and the amount of pistolgrapes is < maxammo.
		if(IsEquipCharacterByItem(curChar, "pistol3-2") || IsEquipCharacterByItem(curChar, "pistol3-1") || IsEquipCharacterByItem(curChar, "pistol3") || IsEquipCharacterByItem(curChar, "pistol3+1") || IsEquipCharacterByItem(curChar, "pistol3+2") || IsEquipCharacterByItem(curChar, "pistol3+3") || IsEquipCharacterByItem(curChar, "pistolmtoon"))
		{
			pistolbulletcheck++;
			if(sti(curChar.items.pistolgrapes) < maxammo)pistolgrapes_officers += maxammo - sti(curChar.items.pistolgrapes);
		}

		// restocking musketbullets to (maxammo/2) loads, if a musket is equipped and the amount of musketbullets is < (maxammo/2).
		if(IsEquipCharacterByItem(curChar, "pistolmket"))
		{
			pistolbulletcheck++;
			if(sti(curChar.items.musketbullets) < (maxammo/2))musketbullets_officers += (maxammo/2) - sti(curChar.items.musketbullets);
		}
		// restock pistol bullets to maxammo, if grapes and musketbullets were not restocked before and the amount of pistolbullets is < maxammo.
		if(pistolbulletcheck == 0)
		{
			if (CheckAttribute(curChar, "items.pistolbullets") == true && sti(curChar.items.pistolbullets) < maxammo) pistolbullets_officers += maxammo - sti(curChar.items.pistolbullets); // KK
		}
	}
	// Calculate price for restock of the officer's supplies
	officer_restock_price = gunpowder_officers * (13 - rand(3)) + pistolbullets_officers * (8 - rand(3)) + pistolgrapes_officers * (14 - rand(4)) + musketbullets_officers * (15 - rand(5));
	return officer_restock_price;
}
// <-- Riley

void RansomColony(string TownName, int nBooty)
{
	int iNation, townsize, troops, nExp, i;
	ref PChar = GetMainCharacter();
	float relchg = 10.0;

	if (!TownExist(TownName)) return;
	iNation = GetTownNation(TownName);
	townsize = GetTownSize(TownName);
	troops = GetTownNumTroops(TownName);
	nExp = troops * 50;
	
	ref chref = GetTownFortCommander(TownName, 0); // PB
	if (CheckAttribute(chref, "skipRM"))
	{
		DeleteAttribute(chref, "skipRM");
		DeleteAttribute(chref, "betrayed");
	}
	else
	{
		if (CheckAttribute(chref, "betrayed"))	PChar.traitor = true; // PB: Temporary attribute, will be deleted in the next function
		UpdateRMRelation(PChar, iNation, makefloat(townsize+troops)/100.0);
	}
	
	SetTownGold(TownName, GetTownGold(TownName) - nBooty);
	AddMoneyToCharacter(PChar, nBooty);
	SetTownNumTroops(TownName, makeint(makefloat(troops) * SACK_TROOPS_DECREASE * (0.75 + frand(0.5))));
	if (AUTO_SKILL_SYSTEM) {
		AddCharacterExpChar(PChar, "Cannons", makeint(nExp/2));
		AddCharacterExpChar(PChar, "Grappling", makeint(nExp/2));
	} else {
		AddCharacterExp(PChar, nExp);
	}
	SetTownSize(TownName, townsize * SACK_TOWN_DECREASE); // NK

	// PB: Turn Hostile Upon Looting -->
	if(GetRMRelation(PChar, iNation) > REL_WAR)
	{
		SetRMRelation(PChar, iNation, REL_WAR);
	}
	// PB: Turn Hostile Upon Looting <--
	ChangeRMRelation(PChar, iNation, -relchg);
	for (i = 0; i < NATIONS_QUANTITY; i++)
	{
		if (i != iNation && GetNationRelation(iNation, i) == RELATION_ENEMY) ChangeRMRelation(PChar, i, 1.0);
	}

	SetTownCapturedState(TownName, true);
	OccupyTown(TownName);

	string sLogTitle = "Ransacked " + FindTownName(TownName);
	string sLogEntry = "My men pillaged and plundered to their heart's content. Of course " + GetNationNameByType(iNation) + " and their allies aren't happy about this, but it made for an extra " + MakeMoneyShow(nBooty,MONEY_SIGN,MONEY_DELIVER) + " gold in the ship's chest. Hopefully it was worth it.";
	WriteNewLogEntry(sLogTitle,sLogEntry, "Personal", true);
}

void CaptureColony(string TownName, int toNation)
{
	int i, fn, nExp, iNation, townsize, troops;
	ref PChar = GetMainCharacter();
	ref chref;
	bool tmpbool = toNation >= 0 && toNation < NATIONS_QUANTITY;

	tmpbool = tmpbool || toNation == PERSONAL_NATION;
	if (!tmpbool || !TownExist(TownName)) return;
	iNation = GetTownNation(TownName);
	townsize = GetTownSize(TownName);
	troops = GetTownNumTroops(TownName);
	
	chref = GetTownFortCommander(TownName, 0); // PB
	if (CheckAttribute(chref, "skipRM"))
	{
		DeleteAttribute(chref, "skipRM");
		DeleteAttribute(chref, "betrayed");
	}
	else
	{
		if (CheckAttribute(chref, "betrayed"))	PChar.traitor = true; // PB: Temporary attribute, will be deleted in the next function
		UpdateRMRelation(PChar, iNation, makefloat(townsize+troops)/100.0);
	}
	
	string sLogTitle;
	string sLogEntry;
	if (toNation != PERSONAL_NATION) {
		ChangeRMRelation(PChar, toNation, 10.0);
		if(GetRMRelation(PChar, toNation) < REL_AMNESTY)	SetRMRelation(PChar, toNation, REL_AMNESTY); // PB: Destination Nation to Turn Friendly
		sLogTitle = "Captured " + FindTownName(TownName) + " for " + GetNationNameByType(toNation);
		sLogEntry = "The " + GetNationDescByType(iNation) + " and their allies will not be happy about this. But " + GetNationNameByType(toNation) + " and their friends most certainly will be!";
	}
	else
	{
		sLogTitle = "Captured " + FindTownName(TownName) + " for myself";
		sLogEntry = "What used to belong to " + GetNationNameByType(iNation) + " now belongs to me. The original owners of course won't be pleased and neither will their allies. But that is the price to pay for building my personal empire.";
	}
	WriteNewLogEntry(sLogTitle,sLogEntry, "Personal", true);

	nExp = troops * 50;
	SetTownNumTroops(TownName, makeint(makefloat(troops) * SACK_TROOPS_DECREASE * (0.75 + frand(0.5))));
	if (AUTO_SKILL_SYSTEM) {
		AddCharacterExpChar(PChar, "Cannons", makeint(nExp/2));
		AddCharacterExpChar(PChar, "Grappling", makeint(nExp/2));
	} else {
		AddCharacterExp(PChar, nExp);
	}
	SetTownSize(TownName, townsize * SACK_TOWN_DECREASE); // NK

	if (iNation != toNation) {
		fn = GetTownNumForts(TownName);
		for (i = 0; i < fn; i++) {
			chref = GetTownFortCommander(TownName, i);
			ResetCharacterMemory(chref); // PB
			SetFortCharacterCaptured(chref, false);
			DeleteAttribute(chref, "Fort.Cannons.Damaged");
			chref.Fort.Mode = FORT_NORMAL;
			chref.Fort.PlayerDamage = 0.0;
		}
	}

	CaptureTownForNation(TownName, toNation);

	Event(COLONY_CAPTURED, "ll", GetTownIndex(TownName), toNation);
}
// <-- KK

// MAXIMUS: can be used in any situation [used in Silehard-dialog] --> // KK -->
string GetShipDescribe(string charId, bool nation, bool nguns, bool shipname, bool accusative)
{
	ref chr, shipRef;
	int canQuantity;
	aref arShip;
	string shipType, tmpDescr;
	string shipDescribe = "";

	chr = characterFromID(charId);
	shipRef = GetShipByType(GetCharacterShipType(chr));
	shipType = shipRef.Sname;

//	if (nation) shipDescribe += XI_ConvertString("sw_" + GetNationDescByType(sti(chr.nation))) + " "; // MAXIMUS 30.05.2019: moved to the end of function for correct phrase spelling
	if (nguns) shipDescribe += GetMaxCannonQuantity(chr) + XI_ConvertString("cannonsQuantity") + " ";
	tmpDescr = shipDescribe + strlower(XI_ConvertString(shipType));
	if (accusative) {
		switch (LanguageGetLanguage()) {
			case "Polish":
				int dl = strlen(tmpDescr);
				if (GetSymbol(tmpDescr, dl - 1) == "a") {
					string tmpstr = "";
					for (int i = 0; i < dl - 1; i++) {
						if (GetSymbol(tmpDescr, i + 1) == " ")
							tmpstr += "¹";
						else
							tmpstr += strcut(tmpDescr, i, i);
					}
					tmpstr += "×";
					shipDescribe = tmpstr;
				}
			break;
			shipDescribe = tmpDescr;
			// default:
		}
	}
	else {
		shipDescribe += strlower(XI_ConvertString(shipType));
	}
	if (shipname) shipDescribe += " " + GetMyShipNameShow(chr);
	if (nation) shipDescribe += " " + TranslateString("", "flying the colors of") + " " + XI_ConvertString("q" + GetNationDescByType(sti(chr.nation))); // MAXIMUS 30.05.2019: placed here for correct phrase spelling

// GR: what is this supposed to achieve?
/*
	if(HasSubStr(shipType,"0") || HasSubStr(shipType,"1") || HasSubStr(shipType,"2") || HasSubStr(shipType,"3") || HasSubStr(shipType,"4") || HasSubStr(shipType,"5") || HasSubStr(shipType,"6") || HasSubStr(shipType,"7") || HasSubStr(shipType,"8") || HasSubStr(shipType,"9"))
	{
		if(!HasSubStr(shipType," 0") && !HasSubStr(shipType," 1") && !HasSubStr(shipType," 2") && !HasSubStr(shipType," 3") && !HasSubStr(shipType," 4") && !HasSubStr(shipType," 5") && !HasSubStr(shipType," 6") && !HasSubStr(shipType," 7") && !HasSubStr(shipType," 8") && !HasSubStr(shipType," 9"))
		{
			shipDescribe = XI_ConvertString(shipType);
		}
	}
*/
	return shipDescribe;
}
// MAXIMUS: can be used in any situation [used in Silehard-dialog] <-- // <-- KK

//MAXIMUS -->
void GotSlut(string wait)
{
	ref pchar = GetMainCharacter();
	PlayStereoSound("INTERFACE\took_item.wav");
	AddMoneyToCharacter(pchar, -50);
	string roomName = pchar.location;
	aref cLoctr; makearef(cLoctr,locations[FindLocation(pchar.location)].reload);
	for(int i=0; i<GetAttributesNum(cLoctr); i++)
	{
		aref curItem1 = GetAttributeN(cLoctr,i);
		string attrName1 = GetAttributeName(curItem1);
		if(CheckAttribute(cLoctr,attrName1+".go"))
		{
			if(HasSubStr(cLoctr.(attrName1).go,"_upstairs") || HasSubStr(cLoctr.(attrName1).go,"_bedroom")) roomName = cLoctr.(attrName1).go;
		}
	}
	DoQuestReloadToLocation(roomName, "goto", "goto4", "to_bedroom_for_girl");
	TavernWaitDate2("wait_"+wait);
}
//MAXIMUS <--

// MAXIMUS: sometimes player can't see his interlocutor - now camera will be moved to the some side for full scene viewing <--
bool DialogCamera(ref pchar, float mag, bool docheck)
{
	int side = 1;
	float x, y, z, ay, tmpY;
	bool bSmallLoc = false;
	if (FindLoadedLocation() == -1) return false; //if not in loc mode, return
	GetCharacterPos(&pchar, &x, &y, &z); // get pos
	GetCharacterAy(&pchar, &ay); // get angle
	if (mag == 0.0) {
		z -= cos(ay);
		x -= sin(ay);
		ay += PI;
		x += sin(ay);
		z += cos(ay);
		y += stf(pchar.model.height);
		locCameraToPos(x, y, z, true);
		return true;
	}
	if (Rand(3) == Rand(3)) side = -1;
	mag *= makefloat(side); // KK
	if (CheckAttribute(loadedLocation,"models.back") || HasSubStr(loadedLocation.id,"House") || HasSubStr(loadedLocation.id,"Tutorial_Deck") || HasSubStr(loadedLocation.id,"Cabin") || HasSubStr(loadedLocation.id,"Seadog")) bSmallLoc = true;
	if (bSmallLoc)
		tmpY = y + 2.2;
	else
		tmpY = y + 3.0;

	//moves back a little for viewing interlocutor
	z -= cos(ay); // add Z component
	x -= sin(ay); // add X component

	ay += PId2; // rotate angle to perpendicular
	z += cos(ay) * mag; // add Z component
	x += sin(ay) * mag; // add X component
	if (docheck)
	{
		if(CheckLocationPosition(loadedLocation, x, tmpY, z)==0)
		{
			locCameraFollow();
			return false;
		}
	}
	locCameraToPos(x, tmpY, z, true);
	return true;
}
// MAXIMUS: sometimes player can't see his interlocutor - now camera will be moved to the some side for full scene viewing <--

// CCC -->
void GotSkill(string topic)
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	LAi_Fade("", "");
	WaitDate("", 0,0,0,5,0);
	RecalculateJumpTable();
	PlaySound("AMBIENT\SHOP\sigh2.wav");
	Log_SetStringToLog(TranslateString("","For five hours are you being lectured on") + " " + XI_ConvertString(topic));
	Log_SetStringToLog(TranslateString("","This has improved your") + " " + XI_ConvertString(topic) + " " + TranslateString("","skill"));
	//LanguageCloseFile(tmpLangFileID);
}
// <-- CCC

// GR ---->
bool StoreDialog(ref ch)
{
	if (CheckAttribute(ch, "quest.original_dialog_filename"))
	{
		return false;
	}
	else
	{
		ch.quest.original_dialog_filename = ch.Dialog.Filename;
		ch.quest.original_dialog_CurrentNode = ch.dialog.CurrentNode;
		ch.quest.original_dialog_TempNode = ch.dialog.TempNode;
		return true;
	}
}

bool RestoreDialog(ref ch)
{
	if (CheckAttribute(ch, "quest.original_dialog_filename"))
	{
		ch.Dialog.Filename = ch.quest.original_dialog_filename;
		ch.dialog.CurrentNode = ch.quest.original_dialog_CurrentNode;
		ch.dialog.TempNode = ch.quest.original_dialog_TempNode;
		DeleteAttribute(ch, "quest.original_dialog_filename");
		DeleteAttribute(ch, "quest.original_dialog_CurrentNode");
		DeleteAttribute(ch, "quest.original_dialog_TempNode");
		return true;
	}
	else
	{
		return false;
	}
}
// <---- GR
