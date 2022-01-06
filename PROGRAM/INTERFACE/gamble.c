//=====| INTERFACE FOR GAMBLE IN TAVERN (written by MAXIMUS. INI files taken from SLiB addon and changed a little) |=====//
#define MAX_CARDS	52

//Debug parameters
#define		DEBUG_GAMBLING		0		//0 means no logs, 1 shows which functions are called, 2 also shows information about values
#define		DEBUG_GAMBLING_AI	0		//0 means no logs, 1 shows which choices made by AI
#define		DEBUG_GAMBLING_CARD	0		//0 means no logs, 1 shows what is set for the card images
#define		DEBUG_GAMBLING_RULE	0		//0 means no logs, 1 shows what is done to determine the winner/loser of the game.

// string DLG_TEXT[162];// from Habitue_dialog.h

object Cards[MAX_CARDS];
object CardPack;

int gameBet;
int BetIndex = 0; //Levis: Make bets more variable
int tmpBetIndex = 0; //Levis: used to store the BetIndex before raising bets.
int CardsAmount;

ref playerChar;
ref gambleChar;
int HandsPlayed = 0;//PW track hands
playerChar = GetMainCharacter();

bool bNewGame = true;
bool bPlayerMove = false;
bool bGambleMove = false;
bool bStop = false;
bool bQuitThisGame = false;
bool bFirstTime;// needed for help showing - once for each game
bool bStart = true;
bool bInTavern = true;// I planned to add a game with a friendly governor. This prevents showing shabby cards
bool bRaisedBet = false; //Levis: used for raising the bet during the game (like doubling up in vingt-un)
bool gambleperk = false; //Levis gamble perk

string infoText;
string GameName;
string gambleID;
string cardNames;
string imageGroup;

string you_lose; // Declared here as globals, defined later when "playerChar" is defined
string you_lose2;
string lucky_man;

int iNatural21 = 0;
int NATURAL21_PLAYER = 1;
int NATURAL21_GAMBLER = 2;
int NATURAL21_BOTH = 3;

int curSkillValue1,curSkillValue2;

string prefix1, prefix2;

void InitInterface_RS(string iniName, ref gambler, string curName)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Call function InitInterface");
	playerChar = GetMainCharacter();
	switch(curName)
	{
		case "Vingt-Un": GameInterface.title = "titleVingt-Un"; break;

		case "Poker":
			GameInterface.title = "titlePoker";
			if(GetAttribute(playerChar, "location") == "Turks_poker_room")
			{
				if (checkAttribute(playerChar,"quest.poker.started")) GameInterface.title = "titleDay1"; 
				if (GetAttribute(playerChar,"quest.poker.day") == "3") GameInterface.title = "titleDay2"; 
				if (GetAttribute(playerChar,"quest.poker.day") == "5") GameInterface.title = "titleDay3";
			}
		break;

		case "Dumb": GameInterface.title = "titleDumb"; break;

		case "Dice": GameInterface.title = "titleDice"; break;
	}
	HandsPlayed = 0;
	bool QuestBet = false;
	GameName = curName;
	if(GameName=="Dumb") CardsAmount = 36;
	else CardsAmount = MAX_CARDS;

	
	gambleperk = CheckCharacterPerk(playerChar,"HighStakes"); //Just to be sure because it seemed to work strange.
	gambleChar = gambler;
	gambleID = gambler.id;
	infoText = "";

	if (CheckAttribute(playerChar,"quest.poker.started"))
	{	
		if(GetDataYear() > 1725)
		{
			imageGroup = "pokerB_cards";
		}	
		else 
		{
			imageGroup = "pokerA_cards";
		}
	}
	else
	{
		imageGroup = FindCardsForNation(gambleChar);// returns nation-description (british, spanish, etc.) plus "_cards" 	
	}

	if(DEBUG_GAMBLING>1) trace("GAMBLING: imagegroup = "+imageGroup);

	if(HasSubStr(playerChar.location,"tavern") && imageGroup!="british_cards")
	{ 
		imageGroup = "OLD_SHADOWS";
		if(DEBUG_GAMBLING>1) trace("GAMBLING: Use old cards because location is tavern.");
	}
	
	// DeathDaisy --> putting this here because playerChar isn't defined outside the function
	if(playerChar.sex == "woman")
	{
		lucky_man = XI_ConvertString("lucky_girl");
	}
	else
	{
		lucky_man = XI_ConvertString("lucky_man");
	}
	you_lose = XI_ConvertString("you_lose") + " " + GetMyAddressForm(gambleChar, playerChar, ADDR_INFORMAL, false, false) + "!";
	you_lose2 = XI_ConvertString("you_lose2") + " " + GetMyAddressForm(gambleChar, playerChar, ADDR_INFORMAL, false, false) + "!";
	// DeathDaisy <-- Thanks GR!
	// GR: setting default value outside this function didn't work.  Settings for male character now brought in here.
	
	playerChar.gamepoints = "0";
	gambleChar.gamepoints = "0";

	if(CheckAttribute(playerChar,"quest.Contraband.CardsBet")) 
	{
		if(makeint(gambleChar.money)<=GetGameBet(BetIndex)) gambleChar.money = sti(gambleChar.money) + GetGameBet(BetIndex);
		QuestBet = true;
		if(DEBUG_GAMBLING>1) trace("GAMBLING: Opponent needed more money for quest best.");
	}

	if(!QuestBet)
	{
		if(!CheckAttribute(gambleChar,"money"))
		{
			gambleChar.money = sti(rand(1000)+2000);
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Opponent didn't have money so gave random amount of money");
		}
		else
		{
			if(sti(gambleChar.money)<=500) gambleChar.money = sti(rand(1000)+2000);
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Opponent had very little money so gave some extra.");
		}
	}

	if(!CheckAttribute(playerChar,"firsttime."+GameName)) { bFirstTime = true; }
	else { bFirstTime = false; }
	if(DEBUG_GAMBLING>1) trace("First time = "+bFirstTime);

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

	if(AUTO_SKILL_SYSTEM)
	{
		curSkillValue1 = 610;
		if(CheckAttribute(playerChar,"Experience.Sneak")) curSkillValue1 = 610 + sti(makeint(sti(playerChar.Experience.Sneak)/500)*0.58);
		CreateImage("LUCK1","ICONS", "status line filled",610,413,curSkillValue1,418);
		if(DEBUG_GAMBLING>1) trace("GAMBLING: Skill value of player set to "+curSkillValue1);

		curSkillValue2 = 0;
		if(CheckAttribute(gambleChar,"Experience.Sneak")) curSkillValue2 = sti(makeint(sti(gambleChar.Experience.Sneak)/500)*1.28);
		CreateImage("LUCK2","ICONS", "status line filled",0,2,curSkillValue2,8);
		if(DEBUG_GAMBLING>1) trace("GAMBLING: Skill value of gambler set to "+curSkillValue2);
	}

	CreateString(true,"CurrentBet","",FONT_SEADOGS,COLOR_NORMAL,20,300,SCRIPT_ALIGN_LEFT,1.2);
	CreateString(true,"PlayerMoney","",FONT_NORMAL,COLOR_MONEY,405,420,SCRIPT_ALIGN_LEFT,1.0);

	if (CheckAttribute(playerChar,"quest.poker.started"))
	{	
		playerChar.money.backup = playerChar.money;
		gambleChar.money.backup = gambleChar.money;
		playerChar.money = 10000;
		gambleChar.money = 10000;

		CreateString(true,"PlayerMoney","",FONT_NORMAL,COLOR_MONEY,550,460,SCRIPT_ALIGN_LEFT,1.0);//405,420
		CreateString(true,"GamblerMoney","",FONT_NORMAL,COLOR_MONEY,130,10,SCRIPT_ALIGN_LEFT,1.0);
		CreateString(true,"HandsPlayed","",FONT_NORMAL,COLOR_MONEY,320,30,SCRIPT_ALIGN_LEFT,1.0);
		ChangePicture("BACKGROUND", "interfaces\card_sukno.tga",true);
		ChangePicture("BOX", "",true);
	}
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	SetNodeUsing("STATUS", AUTO_SKILL_SYSTEM);
	SetNodeUsing("LUCK1", AUTO_SKILL_SYSTEM);
	SetNodeUsing("LUCK2", AUTO_SKILL_SYSTEM);
	ChangePicture("BACKGROUND", "interfaces\card_sukno.tga",!HasSubStr(playerChar.location,"tavern"));
	if (!CheckAttribute(playerChar,"quest.poker.started"))CreateString(AUTO_SKILL_SYSTEM,"GambleSneakLevel",sti(gambleChar.skill.Sneak),FONT_BOLD_NUMBERS,COLOR_NORMAL,120,105,SCRIPT_ALIGN_RIGHT,0.8);
	
	if (GameInterface.title == "titleDay1") GameInterface.title = "titlePoker"; //PW reset title string back to poker for in functions switches
	if (GameInterface.title == "titleDay2") GameInterface.title = "titlePoker";
	if (GameInterface.title == "titleDay3") GameInterface.title = "titlePoker";
	
	//Levis make the sure the cards are ready
	InitCards();
	ShuffleCards(1, false);
	
	//Set game specific stuff
	SetGame(GameName);

	string FirstTimeAttr = "firsttime." + GameName;
	playerChar.(FirstTimeAttr) = true;

	SetNewPicture("EN_FACE", "interfaces\portraits\128\face_" + gambleChar.FaceID + ".tga");
	SetNewPicture("MY_FACE", "interfaces\portraits\128\face_" + playerChar.FaceID + ".tga");

	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("CARD_PIC",false);

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("ExitPress","ProcessExit",0);
	SetEventHandler("StartGamble","StartGame",0);
	SetEventHandler("ExitNo","ProcessExit_no",0);
	SetEventHandler("ExitYes","ProcessExit_yes",0);
}

string FindCardsForNation(ref refCharacter)// by this way anyone can make his own cards, and can put new (properly named) *.tx file into RESOURCE\TEXTURES\INTERFACES (pictures.ini contains all needed sections already)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function FindCardsForNation");
	string cardsNation = "british_cards";
	object LocDirectory;

	DeleteAttribute(&LocDirectory, "");

	LocDirectory.dir = "RESOURCE\\TEXTURES\\INTERFACES";
	LocDirectory.mask = "*_cards.tga.tx";
	CreateEntity(&LocDirectory,"FINDFILESINTODIRECTORY");
	DeleteClass(&LocDirectory);
	aref arList;
	makearef(arList, LocDirectory.filelist);
	for(int i = 0; i < GetAttributesNum(arList); i++)
	{
		aref arCur = GetAttributeN(arList, i);
		string fname = GetAttributeValue(arCur);
		string curCardsNation = strcut(fname,0,strlen(fname)-14);
		if(DEBUG_GAMBLING>1) trace("GAMBLING: Compare if "+curCardsNation+" is equal to nation of gambler which is "+GetNationDescByType(sti(refCharacter.nation)));
		if(curCardsNation==GetNationDescByType(sti(refCharacter.nation)))
		{
		      cardsNation = strcut(fname,0,strlen(fname)-8);
		}
	}
	return cardsNation;
}

void SetGame(string gameName)// resets all to virginity :)
{
	if (LanguageGetLanguage() == "Spanish")
	{
		prefix1 = "¡";
		prefix2 = "¿";
	}
	else
	{
		prefix1 = "";
		prefix2 = "";
	}
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function SetGame");
	string plMoney = "";
	GameInterface.strings.CurrentBet = GetBetText(BetIndex);
	bNewGame = true;
	SetFormatedText("INFO_TEXT", infoText);
	GameName = strcut(GameInterface.title,5,strlen(GameInterface.title)-1);

	UpdateStuff();

	SetSelectable("ICON_GOLD",true);
	SetSelectable("EXIT_BUTTON",true);

	DeleteAttribute(playerChar,"gambling");
	DeleteAttribute(playerChar,"cards");
	DeleteAttribute(gambleChar,"gambling");
	DeleteAttribute(gambleChar,"cards");
	playerChar.cards.value = "0";
	gambleChar.cards.value = "0";

	UpdateMoneyPile(playerChar, imageGroup);
	UpdateMoneyPile(gambleChar, imageGroup);

	UpdateCardDeck();

	switch(gameName)
	{
		case "Vingt-Un":
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Set Game to Vingt-Un");
		break;

		case "Poker":
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Set Game to Poker");
			CreateImage("LEFT_01",imageGroup, "",285,269,360,364);
			CreateImage("LEFT_02",imageGroup, "",290,269,365,364);
			CreateImage("LEFT_03",imageGroup, "",293,269,394,369);
			CreateImage("LEFT_04",imageGroup, "",295,269,374,365);
			CreateImage("LEFT_05",imageGroup, "",297,269,392,369);

			CreateImage("LEFT_06",imageGroup, "",280,269,350,357);
			CreateImage("LEFT_07",imageGroup, "",270,269,362,329);
			CreateImage("LEFT_08",imageGroup, "",275,274,367,334);
			CreateImage("LEFT_09",imageGroup, "",260,250,360,335);
			CreateImage("LEFT_10",imageGroup, "",270,255,378,352);
		break;

		case "Dumb":
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Set Game to Dumb");
		break;

		case "Dice":
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Set Game to Dice");
			CreateImage("B_CARDS","DICE", "cup",445,40,600,160);
			SetNodeUsing("MYFACE",false);
			SetNodeUsing("ENFACE",false);
			if(bPlayerMove) bGambleMove = false;
			else bGambleMove = true;
			if(bGambleMove) bPlayerMove = false;
			else bPlayerMove = true;
		break;
	}
}

void StartGame()// no comments :)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function StartGame");
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	int k, j, l;
	string cardName = "";
	string btnName = "";
	GameName = strcut(GameInterface.title,5,strlen(GameInterface.title)-1);
	if(bNewGame)
	{
		bFirstTime = false;
		SetGame(GameName);
		SetFormatedText("FIRST_TEXT", "");
		switch(gameName)
		{
			if(GetGameBet(BetIndex)==0 || sti(playerChar.money)<GetGameBet(BetIndex) || makeint(gambleChar.money)<GetGameBet(BetIndex))
			{
				if(DEBUG_GAMBLING>1) trace("GAMBLING: Bet is zero or not viable");
				UpdateStuff();
				return;
			}
			case "Vingt-Un":
				if(DEBUG_GAMBLING>1) trace("GAMBLING: Start Game Vingt-Un");
				SetNodeUsing("MYFACE",true);
				SetNodeUsing("ENFACE",true);
				SetSelectable("BET_1",false);
				SetSelectable("ICON_GOLD",false);
				SetSelectable("EXIT_BUTTON",false);
				bPlayerMove = false;
				bGambleMove = false;
				playerChar.cards.aces = 0; //Levis Vingt-Un aces fix
				gambleChar.cards.aces = 0; //Levis Vingt-Un aces fix
				bStop = false;
				for(k=1; k<3; k++)
				{
					if(DEBUG_GAMBLING>1) trace("GAMBLING: Give starting card "+k+" to player for vingt-Un game");
					cardName = GetPlayableCard();
					ProcessGiveCards(playerChar, k, cardName);
					bPlayerMove = true;
					if(k>=3) { sndNum = makeint(k/3); }
					else { sndNum = k; }
					PlaySound("AMBIENT\TAVERN\GAMBLE\card"+sndNum+".wav");
				}

				for(j=1; j<3; j++)
				{
					if(DEBUG_GAMBLING>1) trace("GAMBLING: Give starting card "+j+" to gambler for vingt-Un game");
					cardName = GetPlayableCard();
					ProcessGiveCards(gambleChar, j, cardName);
					if(j>=3) { sndNum = makeint(j/3); }
					else { sndNum = j; }
					PlaySound("AMBIENT\TAVERN\GAMBLE\card"+sndNum+".wav");
				}
				bNewGame = false;
				iNatural21 = 0;
				if(sti(playerChar.cards.value)==21) { bStop = true; bPlayerMove = true; bGambleMove = false; iNatural21 = NATURAL21_PLAYER;}
				if(sti(gambleChar.cards.value)==21) { bStop = true; bPlayerMove = false; bGambleMove = true; iNatural21 = NATURAL21_GAMBLER;}
				if(sti(playerChar.cards.value)==21 && sti(gambleChar.cards.value)==21) { bStop = true; bPlayerMove = false; bGambleMove = true; iNatural21 = NATURAL21_BOTH;}

				UpdateTable();
				SetCardChanging(false, false); //Levis: Cleaning up code
			break;

			case "Poker":
				ShuffleCards(1,0);
				HandsPlayed++
				playerChar.quest.poker.hands = HandsPlayed;
				if (CheckAttribute(playerChar,"quest.poker.started"))
				{
					if (sti( playerChar.quest.poker.hands) == 51) ProcessExit();
				}
				if(DEBUG_GAMBLING>1) trace("GAMBLING: Start Game Poker");
				SetNodeUsing("MYFACE",true);
				SetNodeUsing("ENFACE",true);
				SetSelectable("BET_1",false);
				SetSelectable("ICON_GOLD",false);
				SetSelectable("EXIT_BUTTON",false);
				bPlayerMove = false;
				bGambleMove = false;
				bStop = false;
				bStart = true;
				bRaisedBet = false;
				string cardFace;
				int sndNum;
				for(k=1; k<6; k++)
				{
					if(DEBUG_GAMBLING>1) trace("GAMBLING: Give starting card "+k+" to player for poker game");
					cardName = GetPlayableCard();
					ProcessGiveCards(playerChar, k, cardName);
					bPlayerMove = true;
					if(k>=3) { sndNum = makeint(k/3); }
					else { sndNum = k; }
					PlaySound("AMBIENT\TAVERN\GAMBLE\card"+sndNum+".wav");
				}

				for(j=1; j<6; j++)
				{
					if(DEBUG_GAMBLING>1) trace("GAMBLING: Give starting card "+j+" to gambler for poker game");
					cardName = GetPlayableCard();
					ProcessGiveCards(gambleChar, j, cardName);
					if(j>=3) { sndNum = makeint(j/3); }
					else { sndNum = j; }
					PlaySound("AMBIENT\TAVERN\GAMBLE\card"+sndNum+".wav");
				}
				bNewGame = false;
				SetSelectable("MYFACE",false);

				DisableBet(); //Levis: Cleaning up code
				SetCardChanging(true, false); //Levis: Cleaning up code
			break;

			case "Dumb":
				if(DEBUG_GAMBLING>1) trace("GAMBLING: Start Game Dumb");
				ShuffleCards(1, false);
			break;

			case "Dice":
				if(DEBUG_GAMBLING>1) trace("GAMBLING: Start Game Dice");
				SetSelectable("EXIT_BUTTON",false);
				PlaySound("gamble_dice_shake");
				SetSelectable("B_PACK", false);
				SetEventHandler("DiceThrow","UpdateTable",1);
				PostEvent("DiceThrow", 1000);
			break;
		}
	}
	LanguageCloseFile(tmpLangFileID);
}

void AddOneCard(int crdNum, ref refCharacter)// deals cards (by one)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function AddOneCard");
	int l;//Levis: allow doubleup
	string btnName;//Levis: allow doubleup
	if(GetCardsOnHand(refCharacter)<0) return;
	GameName = strcut(GameInterface.title,5,strlen(GameInterface.title)-1);

	if(crdNum==0)
	{
		refCharacter.cards.value = sti(refCharacter.cards.value);
	}
	else
	{
		string cardName = GetPlayableCard();
		ProcessGiveCards(refCharacter, crdNum, cardName);
		PlaySound("gamble_card_take");
	}



	switch(GameName)
	{
		case "Vingt-Un":
			if(bPlayerMove)
			{
				if(GetCardsOnHand(playerChar)>=5)
				{
					if(DEBUG_GAMBLING>0) trace("GAMBLING: Game Vingt-Un disable double up because cards in hand is 5 or higher");
					if(DEBUG_GAMBLING>0) trace("GAMBLING: Disable option to doubleup");
					for(l=1; l<7; l++) //Changed to 7 for gamble perk
					{
						btnName = "BET_"+l;
						SetSelectable(btnName,false);
					}
				}
			}
			
			UpdateTable();
		break;

//		case "Poker":
//		break;

		case "Dumb":
		break;

//		case "Dice":
//		break;
	}
}

void UpdateTable()// shows the game result and resets portraits-buttons
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function UpdateTable");
	GameName = strcut(GameInterface.title,5,strlen(GameInterface.title)-1);
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	if(gameName!="Dice")
	{
		SetSelectable("EXIT_BUTTON",true);
		SetSelectable("ICON_GOLD",true);
	}
	switch(gameName)
	{
		case "Vingt-Un":
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Set Exit and Gold button to non-selectable");
			SetSelectable("EXIT_BUTTON",false);
			SetSelectable("ICON_GOLD",false);

			if(bStop)
			{
				if(DEBUG_GAMBLING_RULE>0 || DEBUG_GAMBLING>1) trace("GAMBLING: Vingt-Un game is set to stop so decide de winner.");
				if(iNatural21>0)	// GR: set by StartGame if player, gambler or both have a 21 right away
				{
					switch(iNatural21)
					{
						case NATURAL21_PLAYER:
							if(DEBUG_GAMBLING_RULE>0) trace("GAMBLING: Vingt-Un: player has natural 21. [WIN]");
							infoText = Randswear() + " " + XI_ConvertString("you_have_natural21");
							VewGamble(infoText);
							UpdateBet("win");
							return;
						break;

						case NATURAL21_GAMBLER:
							if(DEBUG_GAMBLING_RULE>0) trace("GAMBLING: Vingt-Un: gambler has natural 21. [LOSE]");
							infoText = XI_ConvertString("i_have_natural21");
							VewGamble(infoText);
							UpdateBet("lose");
							return;
						break;

						case NATURAL21_BOTH:
							if(DEBUG_GAMBLING_RULE>0) trace("GAMBLING: Vingt-Un: both player and gambler have natural 21. [DRAW]");
							infoText = XI_ConvertString("both_have_natural21");
							VewGamble(infoText);
							UpdateBet("draw");
							return;
						break;
					}
				}
				if(sti(gambleChar.cards.value)<21)
				{
					if(DEBUG_GAMBLING_RULE>0) trace("GAMBLING: Vingt-Un cards of the gambler are lower then 21.");
					if(sti(gambleChar.cards.value)>sti(playerChar.cards.value))
					{
						if(DEBUG_GAMBLING_RULE>0) trace("GAMBLING: Vingt-Un score of gambler is higher then player. [LOSE]");
						infoText = prefix1 + XI_ConvertString("ive_got") + " " + sti(gambleChar.cards.value) + you_lose;
						VewGamble(infoText);
						UpdateBet("lose");
						return;
					}
					else
					{
						if(sti(gambleChar.cards.value)==sti(playerChar.cards.value))
						{
							if(DEBUG_GAMBLING_RULE>0) trace("GAMBLING: Vingt-Un score of player equal to gambler. [DRAW]");
							infoText = RandSwear() + XI_ConvertString("i_hate_draws");
							VewGamble(infoText);
							UpdateBet("draw");
							return;
						}
						else
						{
							if(DEBUG_GAMBLING_RULE>0) trace("GAMBLING: Vingt-Un score of player is higher then gambler. [WIN]");
							infoText = Randswear() + " " + sti(gambleChar.cards.value) + XI_ConvertString("lady_luck_tart");
							VewGamble(infoText);
							UpdateBet("win");
							return;
						}
					}
				}
				else
				{
					if(DEBUG_GAMBLING_RULE>0) trace("GAMBLING: Vingt-Un cards of the gambler are 21 or higher.");
					if(sti(gambleChar.cards.value)==21)
					{
						if(DEBUG_GAMBLING_RULE>0) trace("GAMBLING: Vingt-Un score of gambler is exactly 21. [LOSE]");
						infoText = prefix1 + XI_ConvertString("ive_got") + " " + sti(gambleChar.cards.value) + you_lose;
						VewGamble(infoText);
						UpdateBet("lose");
						return;
					}
					else
					{
						if(DEBUG_GAMBLING_RULE>0) trace("GAMBLING: Vingt-Un score of gambler is higher then 21. [WIN]");
						infoText = Randswear() + " " + sti(gambleChar.cards.value) + XI_ConvertString("i_have_surplus");
						VewGamble(infoText);
						UpdateBet("win");
						return;
					}
				}
			}

			if(DEBUG_GAMBLING_RULE>0 || DEBUG_GAMBLING>1) trace("GAMBLING: Vingt-Un game is still ongoing.");

			if(sti(gambleChar.cards.value)==21)
			{
				if(sti(playerChar.cards.value)==21)
				{
					if(DEBUG_GAMBLING_RULE>0) trace("GAMBLING: Vingt-Un score of both player and gambler is exactly 21. [DRAW]");
					infoText = RandSwear() + XI_ConvertString("i_hate_draws");
					VewGamble(infoText);
					UpdateBet("draw");
					return;
				}
				else
				{
					if(DEBUG_GAMBLING_RULE>0) trace("GAMBLING: Vingt-Un score of gambler is exactly 21. [LOSE]");
					infoText = prefix1 + XI_ConvertString("ive_got") + " " + sti(gambleChar.cards.value) + you_lose;
					VewGamble(infoText);
					UpdateBet("lose");
					return;
				}
			}
			else
			{
				if(bGambleMove)
				{
					if(sti(gambleChar.cards.value)>21)
					{
						if(DEBUG_GAMBLING_RULE>0) trace("GAMBLING: Vingt-Un score of gambler went above 21. [WIN]");
						infoText = Randswear() + " " + sti(gambleChar.cards.value) + XI_ConvertString("i_have_surplus");
						VewGamble(infoText);
						UpdateBet("win");
						return;
					}
				}
			}

			if(bPlayerMove)
			{
				if(DEBUG_GAMBLING_RULE>0 || DEBUG_GAMBLING>1) trace("GAMBLING: Vingt-Un player's turn.");

				if(sti(playerChar.cards.value)==21)
				{
					if(DEBUG_GAMBLING_RULE>0) trace("GAMBLING: Vingt-Un score of player is exactly 21. Gambler may try to draw to match 21.");
//					infoText = sti(playerChar.cards.value) + lucky_man;
					SetNodeUsing("MYFACE",false);
					SetFormatedText("INFO_TEXT", sti(playerChar.cards.value) + lucky_man + " " + XI_ConvertString("try_to_match"));
					bGambleMove = true;
					bPlayerMove = false;
				}
				
				if(sti(playerChar.cards.value)>21)
				{
					if(DEBUG_GAMBLING_RULE>0) trace("GAMBLING: Vingt-Un score of player went above 21. [LOSE]");
					infoText = XI_ConvertString("ive_got") + " " + sti(gambleChar.cards.value) + XI_ConvertString("you_have_surplus");
					bPlayerMove = false;
					VewGamble(infoText);
					UpdateBet("lose");
					return;
				}
			}
		break;

		case "Poker":
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Poker Update the Hand.");
			UpdateHand(GetCardsCombination(playerChar));
		break;

		case "Dumb":
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Dumb no action.");
		break;

		case "Dice":
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Dice create the dice roll.");
			//Levis: This could probably also be revamped some more but I didn't want to touch the dice game now. Just focussed on the card games.
			int iEnemyDice, iPCDice, first, second, third, fourth, btn;
			string cardName = "dice_";
			DelEventHandler("DiceThrow","UpdateTable");
			if(bGambleMove)
			{
				for(btn=1; btn<7; btn++) //Changed to 7 for gamble perk
				{
					SetSelectable("BET_" + btn,false);
				}
				bGambleMove = false;
				bPlayerMove = true;

				first  = makeint(Rand(5)+1)-makeint(CalcCharacterSkill(playerChar,SKILL_SNEAK)/8)+makeint(CalcCharacterSkill(gambleChar,SKILL_SNEAK)/4);
				if(first<=0) first = 1;
				if(first>6) first = 6;
				second = makeint(Rand(5)+1)-makeint(CalcCharacterSkill(playerChar,SKILL_SNEAK)/8)+makeint(CalcCharacterSkill(gambleChar,SKILL_SNEAK)/4);
				if(second<=0) second = 1;
				if(second>6) second = 6;
				third  = makeint(Rand(5)+1)-makeint(CalcCharacterSkill(playerChar,SKILL_SNEAK)/8)+makeint(CalcCharacterSkill(gambleChar,SKILL_SNEAK)/4);
				if(third<=0) third = 1;
				if(third>6) third = 6;
				fourth = makeint(Rand(5)+1)-makeint(CalcCharacterSkill(playerChar,SKILL_SNEAK)/8)+makeint(CalcCharacterSkill(gambleChar,SKILL_SNEAK)/4);
				if(fourth<=0) fourth = 1;
				if(fourth>6) fourth = 6;
				iEnemyDice = makeint(first + second + third + fourth);
				playerChar.iEnemyDice = iEnemyDice;

				switch(Rand(4))
				{
					case 0:
						CreateImage("P_01","DICE", cardName + first  + "_" + Rand(2),200,215,260,270);
						CreateImage("P_02","DICE", cardName + second + "_" + Rand(2),275,215,335,270);
						CreateImage("P_03","DICE", cardName + third  + "_" + Rand(2),230,315,290,370);
						CreateImage("P_04","DICE", cardName + fourth + "_" + Rand(2),175,275,235,330);
					break;

					case 1:
						CreateImage("P_01","DICE", cardName + first  + "_" + Rand(2),300,265,360,320);
						CreateImage("P_02","DICE", cardName + second + "_" + Rand(2),125,215,185,270);
						CreateImage("P_03","DICE", cardName + third  + "_" + Rand(2),220,235,280,290);
						CreateImage("P_04","DICE", cardName + fourth + "_" + Rand(2),275,215,335,270);
					break;

					case 2:
						CreateImage("P_01","DICE", cardName + first  + "_" + Rand(2),290,345,350,400);
						CreateImage("P_02","DICE", cardName + second + "_" + Rand(2),135,325,195,380);
						CreateImage("P_03","DICE", cardName + third  + "_" + Rand(2),210,275,270,330);
						CreateImage("P_04","DICE", cardName + fourth + "_" + Rand(2),285,245,345,300);
					break;

					case 3:
						CreateImage("P_01","DICE", cardName + first  + "_" + Rand(2),300,335,360,390);
						CreateImage("P_02","DICE", cardName + second + "_" + Rand(2),205,325,265,380);
						CreateImage("P_03","DICE", cardName + third  + "_" + Rand(2),230,275,290,330);
						CreateImage("P_04","DICE", cardName + fourth + "_" + Rand(2),285,245,345,300);
					break;

					case 4:
						CreateImage("P_01","DICE", cardName + first  + "_" + Rand(2),240,365,300,420);
						CreateImage("P_02","DICE", cardName + second + "_" + Rand(2),145,355,205,410);
						CreateImage("P_03","DICE", cardName + third  + "_" + Rand(2),170,305,230,360);
						CreateImage("P_04","DICE", cardName + fourth + "_" + Rand(2),225,275,285,330);
					break;
				}

				PlaySound("gamble_dice_throw");
				SetSelectable("B_PACK", true);

				if(iEnemyDice<=10) { infoText = prefix1 + iEnemyDice + XI_ConvertString("seen_better_throws"); VewGamble(infoText); return; }
				if(iEnemyDice>10 && iEnemyDice<=15) { infoText = prefix1 + iEnemyDice + XI_ConvertString("not_best_throw"); VewGamble(infoText); return; }
				if(iEnemyDice>15 && iEnemyDice<=20) { infoText = prefix1 + iEnemyDice + XI_ConvertString("not_bad_throw"); VewGamble(infoText); return; }
				if(iEnemyDice>20) { infoText = prefix1 + iEnemyDice + XI_ConvertString("hot_throw"); VewGamble(infoText); return; }
			}

			if(bPlayerMove)
			{
				SetSelectable("ICON_GOLD",true);
				SetSelectable("EXIT_BUTTON",true);
				bPlayerMove = false;
				if(makeint(playerChar.money)>=GetGameBet(BetIndex)) bGambleMove = true;
				else
				{
					bGambleMove = false;
					playerChar.quest.gambling = makeint(playerChar.quest.gambling) - 1;
					infoText = LanguageConvertString(tmpLangFileID,"NoGambleMoney");
					BetIndex = 0;
					UpdateStuff();
					DeleteAttribute(playerChar, "iEnemyDice");
					return;
				}

				first  = makeint(Rand(5)+1)+makeint(CalcCharacterSkill(playerChar,SKILL_SNEAK)/4)-makeint(CalcCharacterSkill(gambleChar,SKILL_SNEAK)/8);
				if(first<=0) first = 1;
				if(first>6) first = 6;
				second = makeint(Rand(5)+1)+makeint(CalcCharacterSkill(playerChar,SKILL_SNEAK)/4)-makeint(CalcCharacterSkill(gambleChar,SKILL_SNEAK)/8);
				if(second<=0) second = 1;
				if(second>6) second = 6;
				third  = makeint(Rand(5)+1)+makeint(CalcCharacterSkill(playerChar,SKILL_SNEAK)/4)-makeint(CalcCharacterSkill(gambleChar,SKILL_SNEAK)/8);
				if(third<=0) third = 1;
				if(third>6) third = 6;
				fourth = makeint(Rand(5)+1)+makeint(CalcCharacterSkill(playerChar,SKILL_SNEAK)/4)-makeint(CalcCharacterSkill(gambleChar,SKILL_SNEAK)/8);
				if(fourth<=0) fourth = 1;
				if(fourth>6) fourth = 6;
				iPCDice = makeint(first + second + third + fourth);

				switch(Rand(4))
				{
					case 0:
						CreateImage("P_01","DICE", cardName + first  + "_" + Rand(2),210,235,270,290);
						CreateImage("P_02","DICE", cardName + second + "_" + Rand(2),285,215,345,270);
						CreateImage("P_03","DICE", cardName + third  + "_" + Rand(2),230,315,290,370);
						CreateImage("P_04","DICE", cardName + fourth + "_" + Rand(2),175,275,235,330);
					break;

					case 1:
						CreateImage("P_01","DICE", cardName + first  + "_" + Rand(2),290,275,350,330);
						CreateImage("P_02","DICE", cardName + second + "_" + Rand(2),135,225,195,280);
						CreateImage("P_03","DICE", cardName + third  + "_" + Rand(2),210,245,270,300);
						CreateImage("P_04","DICE", cardName + fourth + "_" + Rand(2),255,225,315,280);
					break;

					case 2:
						CreateImage("P_01","DICE", cardName + first  + "_" + Rand(2),280,355,340,410);
						CreateImage("P_02","DICE", cardName + second + "_" + Rand(2),165,325,225,380);
						CreateImage("P_03","DICE", cardName + third  + "_" + Rand(2),230,295,290,350);
						CreateImage("P_04","DICE", cardName + fourth + "_" + Rand(2),285,225,345,280);
					break;

					case 3:
						CreateImage("P_01","DICE", cardName + first  + "_" + Rand(2),320,305,380,360);
						CreateImage("P_02","DICE", cardName + second + "_" + Rand(2),215,355,275,410);
						CreateImage("P_03","DICE", cardName + third  + "_" + Rand(2),250,295,310,350);
						CreateImage("P_04","DICE", cardName + fourth + "_" + Rand(2),315,235,375,290);
					break;

					case 4:
						CreateImage("P_01","DICE", cardName + first  + "_" + Rand(2),260,345,320,400);
						CreateImage("P_02","DICE", cardName + second + "_" + Rand(2),165,335,225,390);
						CreateImage("P_03","DICE", cardName + third  + "_" + Rand(2),190,285,250,340);
						CreateImage("P_04","DICE", cardName + fourth + "_" + Rand(2),245,255,305,310);
					break;
				}

				PlaySound("gamble_dice_throw");

				if(iPCDice<makeint(playerChar.iEnemyDice))
				{
					bGambleMove = true;
					infoText = prefix1 + iPCDice + you_lose2;
					VewGamble(infoText);
					UpdateBet("lose");
					DeleteAttribute(playerChar, "iEnemyDice");
					return;
				}

				if(iPCDice>makeint(playerChar.iEnemyDice))
				{
					bGambleMove = true;
					infoText = RandSwear() + prefix1 + iPCDice + XI_ConvertString("you_won_dice");
					VewGamble(infoText);
					UpdateBet("win");
					DeleteAttribute(playerChar, "iEnemyDice");
					return;
				}

				if(iPCDice==makeint(playerChar.iEnemyDice))
				{
					bGambleMove = true;
					infoText = RandSwear() + XI_ConvertString("i_hate_draws");
					VewGamble(infoText);
					UpdateBet("draw");
					DeleteAttribute(playerChar, "iEnemyDice");
					return;
				}
			}
		break;
	}
	LanguageCloseFile(tmpLangFileID);
}

void UpdateHand(string cardCombination)// shows the game result and resets portraits-buttons ("Poker")
{
	if(DEBUG_GAMBLING>1) trace("GAMBLING: Call function UpdateHand");
	string cardsInCombo = "";
	string cardsCombo = "";
	int pcombo,gcombo,phigh,ghigh,random;
	playerChar.gambling.most = "";
	gambleChar.gambling.most = "";
	string playerbestface = GetMostCard(playerChar);
	string gamblebestface = GetMostCard(gambleChar);
	string gambler_most, player_most;
	string prefix = prefix1;

	gambler_most = XI_ConvertString(gambleChar.gambling.most);
	if (CheckAttribute(playerChar,"quest.poker.started")) prefix = "";
	if (gambler_most != "") gambler_most = "! " + prefix + gambler_most;
	if (CheckAttribute(playerChar,"quest.poker.started") && gambler_most == "") gambler_most = "!";
	switch(GetCardsCombination(gambleChar))
	{
		case "Pair": cardsInCombo = gambler_most; break;
		case "Four of Kind": cardsInCombo = gambler_most; break;
		case "HighCard": cardsInCombo = gambler_most; break;
		
		if (CheckAttribute(playerChar,"quest.poker.started"))cardsInCombo = XI_ConvertString("my combination is best");
		else cardsInCombo = XI_ConvertString("my combination is better");
	}

	prefix = prefix1;
	player_most = XI_ConvertString(playerChar.gambling.most);
	if (player_most == "") player_most = "!";
	else player_most = "! " + player_most;
	switch(GetCardsCombination(playerChar))
	{
		case "Pair": cardsCombo = player_most; break;
		case "Four of Kind": cardsCombo = player_most; break;
		case "HighCard": cardsCombo = player_most; break;
		random = Rand(4);
		if (CheckAttribute(playerChar,"quest.poker.started")) random = 0;//PW removing some comments for tournament
		switch(Random)
		{
			case 0: cardsCombo = XI_ConvertString("your combination is better"); break;
			case 1: cardsCombo = XI_ConvertString("combination1"); break;
			case 2: cardsCombo = XI_ConvertString("combination2"); break;
			case 3: cardsCombo = XI_ConvertString("combination3"); break;
			case 4: cardsCombo = XI_ConvertString("combination4"); prefix = ""; break;
		}
	}

	if(DEBUG_GAMBLING_RULE>0) trace("GAMBLING: Poker checked card combo for gambler and player.");

	SetSelectable("B_PACK",true);

	SetCardChanging(false, false); //Levis: Code Cleanup

	pcombo = ValidateCombination(playerChar);
	gcombo = ValidateCombination(gambleChar);

	//trace("player combo = "+pcombo+" gamble combo = "+gcombo);
	if (CheckAttribute(playerChar,"quest.poker.started"))
	{
		if(pcombo>gcombo)
		{
			//trace("combo better");
			infoText = prefix + XI_ConvertString(GetCardsCombination(playerChar)) + cardsCombo;
			UpdateBet("win");
		}
		else
		{
			if(pcombo==gcombo)
			{		
				phigh = ValidateHighCard(playerbestface);
				ghigh = ValidateHighCard(gamblebestface);
			
				//trace("combo equal player most "+phigh+" gambler most "+ghigh)
				if(phigh>ghigh)
				{
					//trace("equal higher");
					infoText = prefix + XI_ConvertString(GetCardsCombination(playerChar)) + cardsCombo;
					UpdateBet("win");
				}
				else
				{
					if(phigh==ghigh)
					{
						//trace("equal equal");
						infoText = prefix1 + XI_ConvertString(GetCardsCombination(playerChar)) + XI_ConvertString("same combination") + "...";
						UpdateBet("draw");
					}
					else
					{
						//trace("equal lower");
						infoText = prefix1 + XI_ConvertString(GetCardsCombination(gambleChar)) + cardsInCombo;
						UpdateBet("lose");
					}
				}
			}
			else
			{
				//trace("combo worse");
				infoText = prefix1 + XI_ConvertString(GetCardsCombination(gambleChar)) + cardsInCombo;
				UpdateBet("lose");
			}
		}
	}
	else
	{
		if(pcombo>gcombo)
		{
			//trace("combo better");
			infoText = Randswear() + prefix + XI_ConvertString(GetCardsCombination(playerChar)) + cardsCombo + XI_ConvertString("lady_luck_tart");
			UpdateBet("win");
		}
		else
		{
			if(pcombo==gcombo)
			{		
				phigh = ValidateHighCard(playerbestface);
				ghigh = ValidateHighCard(gamblebestface);
			
				//trace("combo equal player most "+phigh+" gambler most "+ghigh)
				if(phigh>ghigh)
				{
					//trace("equal higher");
					infoText = Randswear() + prefix + XI_ConvertString(GetCardsCombination(playerChar)) + cardsCombo + XI_ConvertString("lady_luck_tart");
					UpdateBet("win");
				}
				else
				{
					if(phigh==ghigh)
					{
						//trace("equal equal");
						infoText = Randswear() + prefix + XI_ConvertString(GetCardsCombination(playerChar)) + XI_ConvertString("same combination") + "...";
						UpdateBet("draw");
					}
					else
					{
						//trace("equal lower");
						infoText = prefix1 + XI_ConvertString("ive_got") + " " + XI_ConvertString(GetCardsCombination(gambleChar)) + cardsInCombo + you_lose;
						UpdateBet("lose");
					}
				}
			}
			else
			{
				//trace("combo worse");
				infoText = prefix1 + XI_ConvertString("ive_got") + " " + XI_ConvertString(GetCardsCombination(gambleChar)) + cardsInCombo + you_lose;
				UpdateBet("lose");
			}
		}
	}
	VewGamble(infoText);
	return;
}

int ValidateCombination(ref refCharacter)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Call function ValidateCombination");
	int comboNum = 0;
	string charCombination = GetCardsCombination(refCharacter);
	switch(charCombination)
	{	
		case "Pair": comboNum = 13; break;
		case "Two Pairs": comboNum = 14; break;
		case "Three of Kind": comboNum = 15; break;
		case "Straight": comboNum = 16; break;
		case "Flush": comboNum = 17; break;
		case "Full House": comboNum = 18; break;
		case "Four of Kind": comboNum = 19; break;
		case "Straight Flush": comboNum = 20; break;
		case "Royal Flush": comboNum = 21; break;
	}
	if(comboNum == 0)
	{
		if(DEBUG_GAMBLING>0) trace("GAMBLING: No combination was found so check for highcard");
		comboNum = ValidateHighCard(GetMostCard(refCharacter));
	}
	return comboNum;
}

int ValidateHighCard(string Face)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Call function ValidateHighCard");
	int comboNum = 0;
	switch(Face)
	{
		case "2": comboNum = 0; break;
		case "3": comboNum = 1; break;
		case "4": comboNum = 2; break;
		case "5": comboNum = 3; break;
		case "6": comboNum = 4; break;
		case "7": comboNum = 5; break;
		case "8": comboNum = 6; break;
		case "9": comboNum = 7; break;
		case "10": comboNum = 8; break;
		case "J": comboNum = 9; break;
		case "Q": comboNum = 10; break;
		case "K": comboNum = 11; break;
		case "A": comboNum = 12; break;
	}
	return comboNum;
}

void UpdateBet(string gameResult)// shows player money on the table, calculate game-result and works with bet-buttons
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function UpdateBet");
	float expDivider = 1.0;
	bNewGame = true;
	SetNodeUsing("ENFACE",false);
	SetNodeUsing("MYFACE",false);
	
	for(int j=1; j<7; j++) //changed to 7 for gamble perk
	{
		string btnName = "BET_"+j;		
		SetSelectable(btnName,false);
	}

	SetEventHandler("Money","MoneyOperation",1);

	if(BetIndex>3) expDivider = 1.5;
	if(DEBUG_GAMBLING>1) trace("GAMBLING: expDivider = "+expDivider);

	switch(gameResult)
	{
		case "win":
			if(DEBUG_GAMBLING>1 || DEBUG_GAMBLING_RULE>0) trace("GAMBLING: Game Won");
			AddMoneyToCharacter(playerChar, GetGameBet(BetIndex));
			AddMoneyToCharacter(gambleChar, (-1 * GetGameBet(BetIndex)));
			if (!checkAttribute(playerChar,"quest.poker.started"))PlaySound("gamble_shout_loose");
			SetSelectable("B_PACK", false);
			PostEvent("Money",500,"s",gameResult);
			playerChar.gamepoints = sti(playerChar.gamepoints) + GetGameBet(BetIndex);
			if(AUTO_SKILL_SYSTEM) { AddCharacterExpChar(playerChar, "Sneak", makeint(GetGameBet(BetIndex)/expDivider)); }
			else { AddCharacterExp(playerChar, makeint(GetGameBet(BetIndex)/expDivider)); }
			playerChar.quest.gambling = makeint(playerChar.quest.gambling) + sti(playerChar.Skill.Sneak);
			//Levis smuggling game
			if(CheckAttribute(playerChar,"quest.Contraband.CardsBet"))
			{
				AddMoneyToCharacter(playerChar, -1 * GetGameBet(BetIndex)); //You only get the plans, the money was your bet against them.
				gambleChar.money = 0;
				playerChar.quest.Contraband.WonGame = 1;
				bQuitThisGame = true;
			}
		break;

		case "lose":
			if(DEBUG_GAMBLING>1 || DEBUG_GAMBLING_RULE>0) trace("GAMBLING: Game Lost");
			AddMoneyToCharacter(playerChar, (-1 * GetGameBet(BetIndex)));
			AddMoneyToCharacter(gambleChar, GetGameBet(BetIndex));
			if (!checkAttribute(playerChar,"quest.poker.started"))PlaySound("gamble_shout_win");
			SetSelectable("B_PACK", false);
			PostEvent("Money",500,"s",gameResult);
			gambleChar.gamepoints = sti(gambleChar.gamepoints) + GetGameBet(BetIndex);
			if(AUTO_SKILL_SYSTEM) { AddCharacterExpNSChar(gambleChar, "Sneak", makeint(GetGameBet(BetIndex)/expDivider)); }
			else { AddCharacterExp(gambleChar, makeint(GetGameBet(BetIndex)/expDivider)); }
			playerChar.quest.gambling = makeint(playerChar.quest.gambling) - 1;
		break;

		case "draw":
			if(DEBUG_GAMBLING>1 || DEBUG_GAMBLING_RULE>0) trace("GAMBLING: Game Draw");
			playerChar.gamepoints = sti(playerChar.gamepoints) + GetGameBet(BetIndex);
			gambleChar.gamepoints = sti(gambleChar.gamepoints) + GetGameBet(BetIndex);
			if(AUTO_SKILL_SYSTEM)
			{
				AddCharacterExpChar  (playerChar, SKILL_SNEAK, makeint(GetGameBet(BetIndex)/makeint(expDivider*5)));
				AddCharacterExpNSChar(gambleChar, SKILL_SNEAK, makeint(GetGameBet(BetIndex)/makeint(expDivider*5)));
			}
			else
			{
				AddCharacterExp(playerChar, makeint(GetGameBet(BetIndex)/makeint(expDivider*5)));
				AddCharacterExp(gambleChar, makeint(GetGameBet(BetIndex)/makeint(expDivider*5)));
			}
			if (!checkAttribute(playerChar,"quest.poker.started"))PlaySound("gamble_shout_draw");
			SetSelectable("B_PACK", false);
			PostEvent("Money",200,"s",gameResult);
		break;
	}

	if(AUTO_SKILL_SYSTEM)
	{
		curSkillValue1 = 610;
		if(CheckAttribute(playerChar,"Experience.Sneak")) curSkillValue1 = 610 + sti(makeint(sti(playerChar.Experience.Sneak)/500)*0.58);
		CreateImage("LUCK1","ICONS", "status line filled",610,413,curSkillValue1,418);

		curSkillValue2 = 0;
		if(CheckAttribute(playerChar,"Experience.Sneak")) curSkillValue2 = sti(makeint(sti(gambleChar.Experience.Sneak)/500)*1.28);
		CreateImage("LUCK2","ICONS", "status line filled",0,3,curSkillValue2,8);

		if (!CheckAttribute(playerChar,"quest.poker.started"))
		{
			if(sti(GameInterface.strings.GambleSneakLevel)<sti(gambleChar.skill.Sneak))
			{
				SetFormatedText("FIRST_TEXT", XI_ConvertString("Warning")+"! "+GetCharacterFullName(gambleChar.id)+" "+XI_ConvertString("playing_better")+".");
				GameInterface.strings.GambleSneakLevel = sti(gambleChar.skill.Sneak);
			}
		}
	}
}

void MoneyOperation()
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function MoneyOperation");
	string gameResult = GetEventData();
	ClearBetImages();
	UpdateMoneyPile(playerChar, imageGroup);
	UpdateMoneyPile(gambleChar, imageGroup);
	switch(gameResult)
	{
		case "win": PlayStereoSound("INTERFACE\took_item.wav"); break;
		case "lose": PlayStereoSound("gamble_give_money"); break;
	}
	
	//Revert the double up
	if(bRaisedBet)
	{
		if(DEBUG_GAMBLING>1) trace("GAMBLING: Revert the bet to how it was before doubling up.");
		bRaisedBet = false;
		BetIndex = tmpBetIndex;
	}
	
	UpdateBetButtons(BetIndex);
	UpdateBetImages(BetIndex);

	GameInterface.strings.PlayerMoney = playerChar.money;
	GameInterface.strings.CurrentBet = GetBetText(BetIndex);

	SetSelectable("B_PACK", true);
	DelEventHandler("Money","MoneyOperation");
}

void ChangeBet()
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function ChangeBet");
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	UpdateBetButtons(BetIndex);
	UpdateBetImages(BetIndex);

	GameInterface.strings.PlayerMoney = playerChar.money;
	GameInterface.strings.CurrentBet = GetBetText(BetIndex);

	string infoText = GetBetInfoText(tmpLangFileID, BetIndex);
	SetFormatedText("INFO_TEXT", infoText);
	LanguageCloseFile(tmpLangFileID);

	//Check if the max amount of raises was reached
	if(!bNewGame)
	{
		if((BetIndex - tmpBetIndex) >= GetMaxRaises())
		{
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Disable betting because max bets was reached.");
			DisableBet();
			if(GetAttribute(playerChar, "location") != "Turks_poker_room")
			{
				infoText = XI_ConvertString("enough_raising");
				SetFormatedText("INFO_TEXT", infoText);
			}
		}
	}
}

void UpdateStuff()// shows money on the table and resets all buttons
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function UpdateStuff");
	SetSelectable("B_PACK", true);
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	if(bNewGame)
	{
		ClearCardImages(imageGroup);
	}

	SetCardChanging(false, false); //Levis: Code cleanup
	UpdateBetButtons(BetIndex);
	UpdateBetImages(BetIndex);

	GameInterface.strings.PlayerMoney = playerChar.money;
	GameInterface.strings.CurrentBet = GetBetText(BetIndex);
	GameInterface.strings.GamblerMoney = gambleChar.money;
	GameInterface.strings.HandsPlayed = HandsPlayed;

	infoText = "";
	SetFormatedText("INFO_TEXT", infoText);

	SetFormatedText("FIRST_TEXT", "");
	GameName = strcut(GameInterface.title,5,strlen(GameInterface.title)-1);

	switch(GameName)
	{
		case "Vingt-Un": if(bFirstTime) { SetFormatedText("FIRST_TEXT", LanguageConvertString(tmpLangFileID,"FirstTimePlayingVingtUn")); } else { SetFormatedText("FIRST_TEXT", ""); } break;
		case "Poker": if(bFirstTime) { SetFormatedText("FIRST_TEXT", LanguageConvertString(tmpLangFileID,"FirstTimePlayingPoker")); } else { SetFormatedText("FIRST_TEXT", ""); } break;
		case "Dumb": if(bFirstTime) { SetFormatedText("FIRST_TEXT", LanguageConvertString(tmpLangFileID,"FirstTimePlayingDumb")); } else { SetFormatedText("FIRST_TEXT", ""); } break;
		case "Dice": if(bFirstTime) { SetFormatedText("FIRST_TEXT", LanguageConvertString(tmpLangFileID,"FirstTimePlayingDice")); } else { SetFormatedText("FIRST_TEXT", ""); } break;
	}

	LanguageCloseFile(tmpLangFileID);
}

void VewGamble(string infoText)// shows the game result
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function VewGamble");
	SetFormatedText("INFO_TEXT", infoText);
	GameName = strcut(GameInterface.title,5,strlen(GameInterface.title)-1);
	string curCard, cardName, cardFace;
	int j, i, k, l;
	switch(GameName)
	{
		case "Vingt-Un":
			if(DEBUG_GAMBLING>1 || DEBUG_GAMBLING_CARD>0) trace("GAMBLING: Vingt-Un show all cards");
			for(i=1; i<6; i++)
			{
				UpdateCardImage("P", playerChar, imageGroup, i, true);
				UpdateCardImage("G", gambleChar, imageGroup, i, true);
			}

			if(DEBUG_GAMBLING>1) trace("GAMBLING: Set Exit and Gold button to selectable");
			SetSelectable("EXIT_BUTTON",true);
			SetSelectable("ICON_GOLD",true);
		break;

		case "Poker":
			bool allShow = false;
			bool showcard = false;
			string highcardvalue = "";
			string highcard = "";
			int x, y, shownum;
			if(ValidateCombination(playerChar)>=16)
			{
				if(ValidateCombination(playerChar)!=19) allShow = true;
			}
			else allShow = false;

			shownum = 0;
			
			if(DEBUG_GAMBLING>1 || DEBUG_GAMBLING_CARD>0) trace("GAMBLING: Poker show cards used in combinations for player");

			for(i=1; i<6; i++)
			{
				curCard = "card" + i;
				showcard = false;
				if(CheckAttribute(playerChar,"gambling."+curCard))
				{
					cardName = playerChar.gambling.(curCard);
					if(!allShow)
					{
						cardFace = GetCardName(cardName);
						if(GetCardsAmount(playerChar, cardFace)>1) 
						{
							showcard = true;
							shownum ++;
						}
					}
					else
					{
						showcard = true;
						shownum ++;
					}
					UpdateCardImageWithCardName("P", imageGroup, curCard, cardName, showcard);

					if(ValidateHighCard(cardFace) > ValidateHighCard(highcardvalue))
					{
						highcard = curCard;
						highcardvalue = cardFace;
					}
				}
			}

			if(shownum < 1){
				if(DEBUG_GAMBLING>1 || DEBUG_GAMBLING_CARD>0) trace("GAMBLING: Poker no cards were shown so show High Card");
				if(CheckAttribute(playerChar,"gambling."+highcard))
				{
					cardName = playerChar.gambling.(highcard);
					UpdateCardImageWithCardName("P", imageGroup, highcard, cardName, true);
				}
			}

			if(ValidateCombination(gambleChar)>=16)
			{
				if(ValidateCombination(gambleChar)!=19) allShow = true;
			}
			else allShow = false;

			shownum = 0;
			highcardvalue = "";
			highcard = "";

			if(DEBUG_GAMBLING>1 || DEBUG_GAMBLING_CARD>0) trace("GAMBLING: Poker show cards used in combinations for gambler");

			for(j=1; j<6; j++)
			{
				curCard = "card" + j;
				showcard = false;
				if(CheckAttribute(gambleChar,"gambling."+curCard))
				{
					cardName = gambleChar.gambling.(curCard);
					if(!allShow)
					{
						cardFace = GetCardName(cardName);
						if(GetCardsAmount(gambleChar, cardFace)>1)
						{
							showcard = true;
							shownum ++;
						}
					}
					else
					{
						showcard = true;
						shownum ++;
					}

					if(!showcard) cardName = "blank";
					UpdateCardImageWithCardName("G", imageGroup, curCard, cardName, showcard);
					
					if(ValidateHighCard(cardFace) > ValidateHighCard(highcardvalue))
					{
						highcard = curCard;
						highcardvalue = cardFace;
					}
				}
			}

			if(shownum < 1){
				if(DEBUG_GAMBLING>1 || DEBUG_GAMBLING_CARD>0) trace("GAMBLING: Poker no cards were shown so show High Card");
				if(CheckAttribute(gambleChar,"gambling."+highcard))
				{
					cardName = gambleChar.gambling.(highcard);
					UpdateCardImageWithCardName("G", imageGroup, highcard, cardName, true);
				}
			}
		break;

		case "Dumb":
		break;

		case "Dice":
			SetFormatedText("INFO_TEXT", infoText);
			infoText = "";
		break;
	}
}

void GambleMove(ref refCharacter)// Give turn to opponent for "poker"
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function GambleMove");
	int i;
	SetNodeUsing("ENFACE",bGambleMove);
	SetSelectable("ENFACE",bGambleMove);
	SetSelectable("MYFACE",bPlayerMove);
	SetSelectable("B_PACK",bPlayerMove);

	SetCardChanging(false, false); //Levis: Code Cleanup

	for(i=1; i<6; i++)
	{
		UpdateCardImage("P", refCharacter, imageGroup, i, false);
	}
}

void CardChange(ref refCharacter, string curCard)// changing cards for "Poker" (left out - in game)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function CardChange");
	if(curCard=="") return;
	string cardName = "";
	string ourCard = "";
	string slotNum, btnName, cardFace;
	PlaySound("gamble_card_take");
	switch(sti(refCharacter.index))
	{
		case 0:// player section
			//Make sure you can't select the opponent now
			SetNodeUsing("ENFACE",false);
		
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Set click status for all cards right");
			for(int i=1; i<6; i++)
			{
				btnName = "B_HeroDice"+i;
				UpdateButtons(btnName, GetClickable(btnName));

				btnName = "B_HeroDice"+i+"_1";
				UpdateButtons(btnName, GetClickable(btnName));
			}

			if(CheckAttribute(refCharacter,"gambling."+curCard))
			{
				cardName = UpdateCardOut(refCharacter, curCard);
				if(DEBUG_GAMBLING>1) trace("GAMBLING: Move player card "+curCard+" up");
				UpdateCardImageWithCardName("P", imageGroup, curCard, cardName, true);
			}
			else
			{
				if(CheckAttribute(refCharacter,"gambling.stored."+curCard))
				{
					cardName = UpdateCardIn(refCharacter, curCard);
					if(DEBUG_GAMBLING>1) trace("GAMBLING: Move player card "+curCard+" down");
					UpdateCardImageWithCardName("P", imageGroup, curCard, cardName, false);
				}
			}
		break;

		// gambler section [default]

		if(!CheckAttribute(refCharacter,"gambling.stored."+curCard))
		{
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Move gambler card "+curCard+" down");
			UpdateCardImageWithCardName("G", imageGroup, curCard, "blank", false);
		}
		else
		{
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Move gambler card "+curCard+" up");
			UpdateCardImageWithCardName("G", imageGroup, curCard, "blank", true);
		}
	}
}

void AutoUpdateOut(ref refCharacter, string curCard)// updates cards status for computer (left out or not)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function AutoUpdateOut");
	string cardName = refCharacter.gambling.(curCard);
	refCharacter.gambling.stored.(curCard) = cardName;
	string slotNum = strcut(curCard,strlen(curCard)-1,strlen(curCard)-1);
	refCharacter.gambling.freeslot.(slotNum) = sti(slotNum);
	string cardFace = GetCardName(cardName);
	refCharacter.gambling.(cardFace) = sti(refCharacter.gambling.(cardFace)) - 1;
	DeleteAttribute(refCharacter,"gambling."+curCard);

	CardChange(refCharacter, curCard);
}

void AutoUpdateIn(ref refCharacter, string curCard)// updates cards status for computer
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function AutoUpdateIn");
	if(CheckAttribute(refCharacter,"gambling.stored."+curCard))
	{
		string cardName = refCharacter.gambling.(curCard);
		string slotNum = strcut(curCard,strlen(curCard)-1,strlen(curCard)-1);
		string cardFace = GetCardName(cardName);
		DeleteAttribute(refCharacter,"gambling.stored."+curCard);
		DeleteAttribute(refCharacter,"gambling.freeslot."+slotNum);

		CardChange(refCharacter, curCard);
	}
}

string UpdateCardOut(ref refCharacter, string curCard)// updates cards status for player (left out or not)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function UpdateCardOut");
	string cardName = refCharacter.gambling.(curCard);
	refCharacter.gambling.stored.(curCard) = cardName;
	string slotNum = strcut(curCard,strlen(curCard)-1,strlen(curCard)-1);
	refCharacter.gambling.freeslot.(slotNum) = sti(slotNum);
	string cardFace = GetCardName(cardName);
	refCharacter.gambling.(cardFace) = sti(refCharacter.gambling.(cardFace)) - 1;
	DeleteAttribute(refCharacter,"gambling."+curCard);
	return cardName;
}

string UpdateCardIn(ref refCharacter, string curCard)// updates cards status for player (left out or not) and returns card name
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function UpdateCardIn");
	refCharacter.gambling.(curCard) = refCharacter.gambling.stored.(curCard);
	string cardName = refCharacter.gambling.(curCard);
	string slotNum = strcut(curCard,strlen(curCard)-1,strlen(curCard)-1);
	string cardFace = GetCardName(cardName);
	refCharacter.gambling.(cardFace) = sti(refCharacter.gambling.(cardFace)) + 1;
	DeleteAttribute(refCharacter,"gambling.stored."+curCard);
	DeleteAttribute(refCharacter,"gambling.freeslot."+slotNum);
	return cardName;
}

void UpdateButtons(string btnName, bool bEnable)// updates buttons
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function UpdateButtons");
	SetClickable(btnName, bEnable);
}

void ProcessGiveCards(ref refCharacter, int cardNum, string cardName)// deals cards
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function ProcessGiveCards");
	if(cardNum==0) return;

	int CardValue;
	string cardFace = "";

	GameName = strcut(GameInterface.title,5,strlen(GameInterface.title)-1);
	string curCard = "card" + cardNum;

	//Store the card for the character
	refCharacter.gambling.(curCard) = cardName;

	switch(sti(refCharacter.index))
	{
		case 0:// player section
			switch(GameName)
			{
				case "Vingt-Un":
					CardValue = GetCardValue(cardName);
					if(DEBUG_GAMBLING>1) trace("GAMBLING: Vingt-Un add card with value "+CardValue+" for player");
	
					if(CardValue==11) refCharacter.cards.aces = sti(refCharacter.cards.aces) + 1;
					refCharacter.cards.value = sti(refCharacter.cards.value) + CardValue;
					
					//Check if the value is larger then 21 and if so see if we have any aces
					if(refCharacter.cards.value>21 && refCharacter.cards.aces>0)
					{
						//Substract 10 point from the value and count 1 less ace cause now it counts as 1
						refCharacter.cards.value = sti(refCharacter.cards.value) - 10;
						refCharacter.cards.aces = sti(refCharacter.cards.aces) - 1;
					}
					
					UpdateCardImage("P", refCharacter, imageGroup, cardNum, false);
				break;

				case "Poker":
					if(bNewGame)
					{
						if(DEBUG_GAMBLING>1) trace("GAMBLING: Poker give card to player at start of the game.");
						UpdateCardImage("P", refCharacter, imageGroup, cardNum, false);
					}
					else
					{
						if(DEBUG_GAMBLING>1) trace("GAMBLING: Poker give card to player during the game.");
						UpdateCardImageWithCardName("P", imageGroup, curCard, "blank", true);
					}
				break;

				case "Dumb":
				break;

//				case "Dice":
//				break;
			}
		break;

		// default:
			switch(GameName)
			{
				case "Vingt-Un":
					CardValue = GetCardValue(cardName);
					if(DEBUG_GAMBLING>1) trace("GAMBLING: Vingt-Un add card with value "+CardValue+" for gambler");
	
					if(CardValue==11) refCharacter.cards.aces = sti(refCharacter.cards.aces) + 1;
					refCharacter.cards.value = sti(refCharacter.cards.value) + CardValue;
					
					//Check if the value is larger then 21 and if so see if we have any aces
					if(refCharacter.cards.value>21 && refCharacter.cards.aces>0)
					{
						//Substract 10 point from the value and count 1 less ace cause now it counts as 1
						refCharacter.cards.value = sti(refCharacter.cards.value) - 10;
						refCharacter.cards.aces = sti(refCharacter.cards.aces) - 1;
					}

/*
					switch(cardNum)
					{
						case 1:
							if(DEBUG_GAMBLING_CARD>0) trace("GAMBLING: Vingt-Un gamblers first card so show this one face up");
							UpdateCardImage("G", refCharacter, imageGroup, cardNum, false);
						break;
						
						//default:
							if(DEBUG_GAMBLING_CARD>0) trace("GAMBLING: Vingt-Un gamblers later card so show this one face down");
							UpdateCardImageWithCardName("G", imageGroup, curCard, "blank", false);
					}
*/
					if(DEBUG_GAMBLING_CARD>0) trace("GAMBLING: Vingt-Un gambler shows cards face down");
					UpdateCardImageWithCardName("G", imageGroup, curCard, "blank", false);
				break;

				case "Poker":
					if(DEBUG_GAMBLING>1) trace("GAMBLING: Poker give card to gambler.");
					UpdateCardImageWithCardName("G", imageGroup, curCard, "blank", false);
				break;

				case "Dumb":
					trace("ProcessGiveCards Dumb enemy default");
					UpdateCardImageWithCardName("G", imageGroup, curCard, "blank", false);
				break;

//				case "Dice":
//				break;
			}
		break;
	}

	if(GameName!="Dice")
	{
		cardFace = GetCardName(cardName);
		refCharacter.gambling.(cardFace) = sti(refCharacter.gambling.(cardFace)) + 1;
	}
}

void ShuffleCards(int packs, bool excludeinplay)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Call function ShuffleCards");
	PlaySound("gamble_card_shuffle");

	string cardid = ""
	string curCard, cardName;
	int i;

	//Clear previous cardpack
	DeleteAttribute(&CardPack,"cards");

	for(int n=0; n<CardsAmount; n++)
	{
		cardid = Cards[n].id
		CardPack.cards.(cardid) = packs;
	}

	//Remove cards which are in player
	if(excludeinplay)
	{
		if(DEBUG_GAMBLING>1) trace("GAMBLING: Check hands of player and gambler and remove these cards from the deck.");
		for(i=1; i<6; i++)
		{
			curCard = "card" + i;
			if(CheckAttribute(playerChar,"gambling."+curCard))
			{
				cardName = playerChar.gambling.(curCard);
				if(DEBUG_GAMBLING>1) trace("GAMBLING: Remove card "+cardName+" from new pack because it's still in play.");
				DeleteAttribute(&CardPack,"cards."+cardName);
			}
		}

		for(i=1; i<6; i++)
		{
			curCard = "card" + i;
			if(CheckAttribute(gambleChar,"gambling."+curCard))
			{
				cardName = gambleChar.gambling.(curCard);
				if(DEBUG_GAMBLING>1) trace("GAMBLING: Remove card "+cardName+" from new pack because it's still in play.");
				DeleteAttribute(&CardPack,"cards."+cardName);
			}
		}
	}
}

string GetPlayableCard()// returns cards-pictures names (from pictures.ini)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Call function GetPlayableCard");
	//Set some variables
	aref playingcards;
	string cardName;
	makearef(playingcards,CardPack.cards);
	//Check how many cards there are left in the pack and if none shuffle the pack
	int amountcards = GetAttributesNum(playingcards);
	if(amountcards == 0){
		ShuffleCards(1, true);
		makearef(playingcards,CardPack.cards);
		amountcards = GetAttributesNum(playingcards);
	}
	//Get a random card from the pack
	int randomcard = rand(amountcards-1);
	cardName = GetAttributeName(GetAttributeN(playingcards,randomcard));
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Picked card "+cardName);
	//Remove the card from the pack so it wont be picked again.
	if(sti(CardPack.cards.(cardName)) == 1)
	{
		if(DEBUG_GAMBLING>0) trace("GAMBLING: Card "+cardName+" removed from CardPack");
		DeleteAttribute(&CardPack,"cards."+cardName);
	}
	else
	{
		if(DEBUG_GAMBLING>0) trace("GAMBLING: Card "+cardName+" has more occurances in the pack, number is reduced.");
		CardPack.cards.(cardName) = sti(CardPack.cards.(cardName)) - 1;
	}
	//update the card deck image
	UpdateCardDeck();
	//return the card
	return cardName;
}

string GetCardsCombination(ref refCharacter)// returns cards combinations ("Pair", "Straight", "Royal Flash", etc.)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Call function GetCardsCombination");
	int i, HighCardValue;
	bool bFlush = false;
	string cardsNames, cardsCombination, cardColour, cardName, cardFace, curCard, allCards, allCards1;
	cardsCombination = "Variegated";
	cardsNames = "";
	cardColour = "";
	allCards = "";
	allCards1 = "";
	cardFace = "";
	allCards = "";
	cardName = "blank";
	for(i=1; i<=GetCardsOnHand(refCharacter); i++)
	{
		curCard = "card" + i;
		if(CheckAttribute(refCharacter,"gambling."+curCard))
		{
			cardName = refCharacter.gambling.(curCard);
			cardsNames = StoreString(cardsNames, cardName);
			cardFace = GetCardName(cardName);
			
			if(CheckAttribute(refCharacter,"gambling."+cardFace))
			{
				switch(GetCardsAmount(refCharacter, cardFace))
				{
					case 2:
						if(allCards=="") { allCards = "Pair"; allCards1 = "Pair"+"_"+cardFace; }
						else
						{
							if(allCards=="Pair")
							{
								if(allCards1!="Pair"+"_"+cardFace) allCards = "Two Pairs";
							}
							else
							{
								if(allCards=="Three of Kind") { allCards = "Full House"; }
							}
						}
					break;

					case 3:
						if(allCards=="") { allCards = "Three of Kind"; }
						if(allCards=="Pair") { allCards = "Full House"; }
					break;

					case 4:
						allCards = "Four of Kind";
					break;
				}
				if(allCards!="") cardsCombination = allCards;
			}
		}

		if(cardColour=="") { cardColour = GetCardColour(cardName); }
		else
		{
			if(cardColour==GetCardColour(cardName)) { cardColour = GetCardColour(cardName); }
			else { cardColour = "Variegated"; }
		}
	}

	if(cardColour!="Variegated") { cardsCombination = "Flush"; bFlush = true; }
	else { bFlush = false; }

	if(HasSubStr(cardsNames,"_A"))
	{
		if(HasSubStr(cardsNames,"_2"))
		{
			if(HasSubStr(cardsNames,"_3"))
			{
				if(HasSubStr(cardsNames,"_4"))
				{
					if(HasSubStr(cardsNames,"_5"))
					{
						if(bFlush) cardsCombination = "Straight Flush";
						else cardsCombination = "Straight";
					}
				}
			}
		}
	}

	if(HasSubStr(cardsNames,"_2"))
	{
		if(HasSubStr(cardsNames,"_3"))
		{
			if(HasSubStr(cardsNames,"_4"))
			{
				if(HasSubStr(cardsNames,"_5"))
				{
					if(HasSubStr(cardsNames,"_6"))
					{
						if(bFlush) cardsCombination = "Straight Flush";
						else cardsCombination = "Straight";
					}
				}
			}
		}
	}

	if(HasSubStr(cardsNames,"_3"))
	{
		if(HasSubStr(cardsNames,"_4"))
		{
			if(HasSubStr(cardsNames,"_5"))
			{
				if(HasSubStr(cardsNames,"_6"))
				{
					if(HasSubStr(cardsNames,"_7"))
					{
						if(bFlush) cardsCombination = "Straight Flush";
						else cardsCombination = "Straight";
					}
				}
			}
		}
	}

	if(HasSubStr(cardsNames,"_4"))
	{
		if(HasSubStr(cardsNames,"_5"))
		{
			if(HasSubStr(cardsNames,"_6"))
			{
				if(HasSubStr(cardsNames,"_7"))
				{
					if(HasSubStr(cardsNames,"_8"))
					{
						if(bFlush) cardsCombination = "Straight Flush";
						else cardsCombination = "Straight";
					}
				}
			}
		}
	}

	if(HasSubStr(cardsNames,"_5"))
	{
		if(HasSubStr(cardsNames,"_6"))
		{
			if(HasSubStr(cardsNames,"_7"))
			{
				if(HasSubStr(cardsNames,"_8"))
				{
					if(HasSubStr(cardsNames,"_9"))
					{
						if(bFlush) cardsCombination = "Straight Flush";
						else cardsCombination = "Straight";
					}
				}
			}
		}
	}

	if(HasSubStr(cardsNames,"_6"))
	{
		if(HasSubStr(cardsNames,"_7"))
		{
			if(HasSubStr(cardsNames,"_8"))
			{
				if(HasSubStr(cardsNames,"_9"))
				{
					if(HasSubStr(cardsNames,"_10"))
					{
						if(bFlush) cardsCombination = "Straight Flush";
						else cardsCombination = "Straight";
					}
				}
			}
		}
	}

	if(HasSubStr(cardsNames,"_7"))
	{
		if(HasSubStr(cardsNames,"_8"))
		{
			if(HasSubStr(cardsNames,"_9"))
			{
				if(HasSubStr(cardsNames,"_10"))
				{
					if(HasSubStr(cardsNames,"_J"))
					{
						if(bFlush) cardsCombination = "Straight Flush";
						else cardsCombination = "Straight";
					}
				}
			}
		}
	}

	if(HasSubStr(cardsNames,"_8"))
	{
		if(HasSubStr(cardsNames,"_9"))
		{
			if(HasSubStr(cardsNames,"_10"))
			{
				if(HasSubStr(cardsNames,"_J"))
				{
					if(HasSubStr(cardsNames,"_Q"))
					{
						if(bFlush) cardsCombination = "Straight Flush";
						else cardsCombination = "Straight";
					}
				}
			}
		}
	}

	if(HasSubStr(cardsNames,"_9"))
	{
		if(HasSubStr(cardsNames,"_10"))
		{
			if(HasSubStr(cardsNames,"_J"))
			{
				if(HasSubStr(cardsNames,"_Q"))
				{
					if(HasSubStr(cardsNames,"_K"))
					{
						if(bFlush) cardsCombination = "Straight Flush";
						else cardsCombination = "Straight";
					}
				}
			}
		}
	}

	if(HasSubStr(cardsNames,"_10"))
	{
		if(HasSubStr(cardsNames,"_J"))
		{
			if(HasSubStr(cardsNames,"_Q"))
			{
				if(HasSubStr(cardsNames,"_K"))
				{
					if(HasSubStr(cardsNames,"_A"))
					{
						if(bFlush) cardsCombination = "Royal Flush";
						else cardsCombination = "Straight";
					}
				}
			}
		}
	}

	if(cardsCombination=="Variegated") cardsCombination = "HighCard"; //We just call it by the suit of the card

	return cardsCombination;
}

int GetCardsAmount(ref refCharacter, string cardFace)// returns amount of identical cards
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Call function GetCardsAmount");
	int curAmount = 1;
	if(CheckAttribute(refCharacter,"gambling."+cardFace)) curAmount = makeint(refCharacter.gambling.(cardFace));
	return curAmount;
}

string GetCardColour(string cardName)// returns cards colour ("spades", "hearts", and etc.)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Call function GetCardColour");
	string curColour = "";
	for(int n=0; n<CardsAmount; n++)
	{
		if(cardName==Cards[n].id) 
		{
			return Cards[n].colour;
		}
	}
	return curColour;
}

string GetCardName(string cardName)// returns cards names ("A", "K", "Q", and etc.)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Call function GetCardName");
	string curName = "blank";
	for(int n=0; n<CardsAmount; n++)
	{
		if(cardName==Cards[n].id)
		{
			return Cards[n].face;
		}
	}
	return curName;
}

int GetCardFaceId(string cardName)// returns cards identifier (from 0 to 12)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Call function GetCardFaceId");
	int curCardNum = -1;
	for(int n=0; n<CardsAmount; n++)
	{
		if(cardName==Cards[n].id)
		{
			return sti(Cards[n].faceId);
		}
	}
	return curCardNum;
}

string GetCardPlayName(string cardName)// returns cards names for translation ("card_queen", "card_king", "card_ace", and etc.)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Call function GetCardPlayName");
	string curCardName = "";
	for(int n=0; n<CardsAmount; n++)
	{
		if(cardName==Cards[n].id)
		{
			return Cards[n].name;
		}
	}
	return curCardName;
}

string GetMostCard(ref refCharacter)// returns a biggest identifier (from 0 to 12)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Call function GetMostCard");
	int mostAmount = 0;
	int tmpAmount = 0;
	string bestFace = "";
	string curCard, cardName, cardFace;

	for(int i=1; i<6; i++)
	{
		curCard = "card" + i;
		cardName = "";
		if(CheckAttribute(refCharacter,"gambling."+curCard))
		{
			cardName = refCharacter.gambling.(curCard);
			cardFace = GetCardName(cardName);
			tmpAmount = GetCardsAmount(refCharacter, cardFace);
			//Check if this cardface is higher then the other cardface we have the equal amount of
			if(tmpAmount==mostAmount)
			{
				if(ValidateHighCard(cardFace)>ValidateHighCard(bestFace))
				{
					mostAmount = tmpAmount;
					bestFace = cardFace;
					refCharacter.gambling.most = GetCardPlayName(cardName);
				}
			}
			//We found a cardface with a higher amount so set this as best face and amount
			if(tmpAmount>mostAmount)
			{
				mostAmount = tmpAmount;
				bestFace = cardFace;
				refCharacter.gambling.most = GetCardPlayName(cardName);
			}
		}
	}
	return bestFace;
}

int GetCardValue(string cardName)// returns cards value ("9", "10", "11", and etc.)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Call function GetCardValue");
	int curCardNum = 0;
	for(int n=0; n<CardsAmount; n++)
	{
		if(cardName==Cards[n].id) 
		{
			return sti(Cards[n].value);
		}
	}
	return curCardNum;
}

int GetCardsOnHand(ref refPlayer)// returns cards amount of current gambler (from 1 to 5)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Call function GetCardsOnHand");
	int ourCards = 0;
	for(int j=1; j<6; j++)
	{
		string curCard = "card" + j;
		if(CheckAttribute(refPlayer,"gambling."+curCard))
		{
			ourCards = j;
		}
	}
	return ourCards;
}

void SetCardsToHandByNum(ref refCharacter)// deals cards to the current gambler empty slots (from 1 to 5)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Call function SetCardsToHandByNum");
	int curCard;
	string cardName = "";
	string cardFace = "";
	string ourCard = "";
	if(GetCardsOnHand(refCharacter)<=5)
	{
		for(int j=1; j<6; j++)
		{
			if(CheckAttribute(refCharacter,"gambling.freeslot."+j))
			{
				DiscardCard(refCharacter, imageGroup, j);

				SetClickable("B_HeroDice"+j+"_1",false);
				curCard = sti(refCharacter.gambling.freeslot.(j));
				cardName = GetPlayableCard();
				ProcessGiveCards(refCharacter, j, cardName);
				DeleteAttribute(refCharacter,"gambling.freeslot."+j);
			}
			SetClickable("B_HeroDice"+j,false);
		}
	}
}

void ProcessCommandExecute()
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Call function ProcessCommandExecute");
	string comName = GetEventData();
	string nodName = GetEventData();

	GameName = strcut(GameInterface.title,5,strlen(GameInterface.title)-1);
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	string plMoney = "";
	string curCard = "";
	string cardName = "";
	int c;

	if(nodName=="ENFACE")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(!bNewGame)
			{
				switch(gameName)
				{
					case "Vingt-Un":
						if(DEBUG_GAMBLING>1) trace("GAMBLING: Vingt-Un clicked gambler portrait.");
						bPlayerMove = false;
						bGambleMove = true;
						DecideEnemyMove(gambleChar, playerChar, gameName);
					break;

					case "Poker":
						if(bStart)
						{
							if(DEBUG_GAMBLING>1) trace("GAMBLING: Poker clicked gambler portrait first time in game.");
							bStart = false;
							DecideEnemyMove(gambleChar, playerChar, gameName);
						}
						else
						{
							bPlayerMove = false;
							SetCardsToHandByNum(gambleChar);
							for(c=1; c<6; c++)
							{
								curCard = "card" + c;
								cardName = "";
								if(CheckAttribute(gambleChar,"gambling."+curCard))
								{
									AutoUpdateIn(gambleChar, curCard);
								}
							}
							
							//Check with the player if they want to raise the bet
							if(!bRaisedBet && !CheckAttribute(playerChar,"quest.Contraband.CardsBet"))
							{
								if(GetAttribute(playerChar, "location") != "Turks_poker_room")
								{
									if(DEBUG_GAMBLING>1) trace("GAMBLING: Poker clicked gambler portrait so ask for raising the bet.");
									infoText = XI_ConvertString("want_to_raise");
									SetFormatedText("INFO_TEXT", infoText);
								}
								bRaisedBet = true;
								tmpBetIndex = BetIndex;
								UpdateBetButtons(BetIndex);
							}
							else
							{
								if(DEBUG_GAMBLING>1) trace("GAMBLING: Poker clicked gambler portrait after asked for raising the bet.");
								DisableBet();
								UpdateTable();
							}
						}
					break;

					case "Dumb": break;

					case "Dice": break;
				}
			}
		}
	}

	if(nodName=="MYFACE")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(!bNewGame)
			{
				switch(gameName)
				{
					case "Vingt-Un":
						if(bPlayerMove)
						{
							if(DEBUG_GAMBLING>1) trace("GAMBLING: Vingt-Un clicked player portrait while turn is still active.");
							if(GetCardsOnHand(playerChar)<5) AddOneCard(GetCardsOnHand(playerChar)+1, playerChar);
						}
					break;

					case "Poker":
						if(bPlayerMove)
						{
							if(bStart)
							{
								if(DEBUG_GAMBLING>1) trace("GAMBLING: Poker clicked player portrait first time.");
								bStart = false;
								if(GetCardsOnHand(playerChar)<=5) SetCardsToHandByNum(playerChar);
							}
							else
							{
								if(DEBUG_GAMBLING>1) trace("GAMBLING: Poker clicked player portrait after card exchange.");
								bStart = true;
								bPlayerMove = false;
								bGambleMove = true;
								GambleMove(playerChar);
							}
						}
					break;

					case "Dumb": break;

//					case "Dice": break;
				}
			}
		}
	}

	if(nodName=="B_PACK")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(bQuitThisGame)
			{
				ProcessExit();
			}
			else
			{
				if(bNewGame)
				{
					if(DEBUG_GAMBLING>1) trace("GAMBLING: Clicked on the card pack to start a game of "+gameName+".");
					switch(gameName)
					{
						case "Vingt-Un": StartGame(); break;
						case "Poker": StartGame(); break;
						case "Dumb": StartGame(); break;
						case "Dice": StartGame(); break;
					}
				}
			}
		}
	}

	if(nodName=="ICON_GOLD")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(bNewGame)
			{
				if(DEBUG_GAMBLING>1) trace("GAMBLING: Clicked on gold.");
				PlaySound("gamble_give_money");
				BetIndex = 0;
				SetGame(GameName);
			}
		}
	}
	
	bool bClick;
	if(GetCardsOnHand(playerChar)<5) bClick = true;
	if (gameName == "Poker")
	{
		if(ValidateCombination(playerChar)>=16)
		{
			if(ValidateCombination(playerChar)!=19) bClick = true;
			else bClick = false;
		}
	}

	if(nodName=="B_HeroDice1")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Poker clicked card 1 normal state.");
			SetClickable("B_HeroDice1",false);
			SetClickable("B_HeroDice1_1",true);
			CardChange(playerChar, "card1");
			SetSelectable("MYFACE",true);
		}
	}

	if(nodName=="B_HeroDice1_1")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Poker clicked card 1 raised state.");
			SetClickable("B_HeroDice1",true);
			SetClickable("B_HeroDice1_1",false);
			CardChange(playerChar, "card1");
			SetSelectable("MYFACE",bClick);
		}
	}

	if(nodName=="B_HeroDice2")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Poker clicked card 2 normal state.");
			SetClickable("B_HeroDice2",false);
			SetClickable("B_HeroDice2_1",true);
			CardChange(playerChar, "card2");
			SetSelectable("MYFACE",true);
		}
	}

	if(nodName=="B_HeroDice2_1")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Poker clicked card 2 raised state.");
			SetClickable("B_HeroDice2",true);
			SetClickable("B_HeroDice2_1",false);
			CardChange(playerChar, "card2");
			SetSelectable("MYFACE",bClick);
		}
	}

	if(nodName=="B_HeroDice3")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Poker clicked card 3 normal state.");
			SetClickable("B_HeroDice3",false);
			SetClickable("B_HeroDice3_1",true);
			CardChange(playerChar, "card3");
			SetSelectable("MYFACE",true);
		}
	}

	if(nodName=="B_HeroDice3_1")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Poker clicked card 3 raised state.");
			SetClickable("B_HeroDice3",true);
			SetClickable("B_HeroDice3_1",false);
			CardChange(playerChar, "card3");
			SetSelectable("MYFACE",bClick);
		}
	}

	if(nodName=="B_HeroDice4")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Poker clicked card 4 normal state.");
			SetClickable("B_HeroDice4",false);
			SetClickable("B_HeroDice4_1",true);
			CardChange(playerChar, "card4");
			SetSelectable("MYFACE",true);
		}
	}

	if(nodName=="B_HeroDice4_1")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Poker clicked card 4 raised state.");
			SetClickable("B_HeroDice4",true);
			SetClickable("B_HeroDice4_1",false);
			CardChange(playerChar, "card4");
			SetSelectable("MYFACE",bClick);
		}
	}

	if(nodName=="B_HeroDice5")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Poker clicked card 5 normal state.");
			SetClickable("B_HeroDice5",false);
			SetClickable("B_HeroDice5_1",true);
			CardChange(playerChar, "card5");
			SetSelectable("MYFACE",true);
		}
	}

	if(nodName=="B_HeroDice5_1")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Poker clicked card 5 raised state.");
			SetClickable("B_HeroDice5",true);
			SetClickable("B_HeroDice5_1",false);
			CardChange(playerChar, "card5");
			SetSelectable("MYFACE",bClick);
		}
	}

	if(nodName=="BET_1")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Clicked Bet 1.");
			BetIndex = 1;
			ChangeBet();
			if(bPlayerMove==true && gameName=="Vingt-Un")
			{
				DoubleUp();
			}
		}
	}

	if(nodName=="BET_2")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Clicked Bet 2.");
			BetIndex = 2;
			ChangeBet();
			if(bPlayerMove==true && gameName=="Vingt-Un")
			{
				DoubleUp();
			}
		}
	}

	if(nodName=="BET_3")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Clicked Bet 3.");
			BetIndex = 3;
			ChangeBet();
			if(bPlayerMove==true && gameName=="Vingt-Un")
			{
				DoubleUp();
			}
		}
	}

	if(nodName=="BET_4")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Clicked Bet 4.");
			BetIndex = 4;
			ChangeBet();
			if(bPlayerMove==true && gameName=="Vingt-Un")
			{
				DoubleUp();
			}
		}
	}

	if(nodName=="BET_5")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Clicked Bet 5.");
			BetIndex = 5;
			ChangeBet();
			if(bPlayerMove==true && gameName=="Vingt-Un")
			{
				DoubleUp();
			}
		}
	}

	if(nodName=="BET_6")
	{ 
		if(comName=="activate" || comName=="click")
		{
			if(DEBUG_GAMBLING>1) trace("GAMBLING: Clicked Bet 6.");
			BetIndex = 6;
			ChangeBet();
			if(bPlayerMove==true && gameName=="Vingt-Un")
			{
				DoubleUp();
			}
		}
	}

	LanguageCloseFile(tmpLangFileID);
}

void DoubleUp()
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function DoubleUp");
	int l;
	string btnName;
	//Check if character has enough money for double up
	if(sti(playerChar.money)<GetGameBet(BetIndex))
	{
		infoText = XI_ConvertString("I don't have enough money to double up");
		SetFormatedText("INFO_TEXT", infoText);
		BetIndex--;
		ChangeBet();
	}
	else
	{
		for(l=1; l<7; l++) //changed to 7 for gamble perk
		{
			btnName = "BET_"+l;
			SetSelectable(btnName,false);
		}
		
		infoText = XI_ConvertString("you are doubling up");
		SetFormatedText("INFO_TEXT", infoText);
		
		AddOneCard(GetCardsOnHand(playerChar)+1, playerChar);
		bPlayerMove = false;
		bGambleMove = true;
		bRaisedBet = true;
		tmpBetIndex = BetIndex - 1;
	}
}

void ProcessCancelExit()
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function ProcessCancelExit");
	if(bNewGame)
	{
		SetNodeUsing("CONFIRM_RECTANGLE",true);
		SetNodeUsing("TEXTWINDOW",true);
		SetNodeUsing("CONFIRM_YES_BUTTON",true);
		SetNodeUsing("CONFIRM_NO_BUTTON",true);
		SetNodeUsing("CARD_PIC",true);
		if (CheckAttribute(playerChar,"quest.poker.started")) SetNodeUsing("CARD_PIC",false);
		int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
		SetCurrentNode("CONFIRM_NO_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CONFIRM_NO_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CONFIRM_YES_BUTTON");

		if (CheckAttribute(playerChar,"quest.poker.started"))SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Exit from gamble confirmPoker"));
		else SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Exit from gamble confirm"));

		LanguageCloseFile(tmpLangFileID);
	}
}

void ProcessExit_no()
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function ProcessExit_no");
	SendMessage(&GameInterface,"ll", MSG_INTERFACE_LOCK_NODE, 0);

	SetNodeUsing("CONFIRM_RECTANGLE",false);
	SetNodeUsing("TEXTWINDOW",false);
	SetNodeUsing("CONFIRM_YES_BUTTON",false);
	SetNodeUsing("CONFIRM_NO_BUTTON",false);
	SetNodeUsing("CARD_PIC",false);
	SetCurrentNode("TITLE");

	SetGame(GameName);
}

void ProcessExit_yes()
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function ProcessExit_yes");
	ProcessExit();
}

void ProcessExit()
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function ProcessExit");
	ref playerChar = GetMainCharacter();
	ref gambleChar = characterFromID(gambleID);
	bool bInTavern;
	int result;

	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");
	DelEventHandler("ExitPress","ProcessExit");
	DelEventHandler("StartGamble","StartGame");
	DelEventHandler("ExitNo","ProcessExit_no");
	DelEventHandler("ExitYes","ProcessExit_yes");

	interfaceResultCommand = RC_INTERFACE_GAMBLE_EXIT;

	UnloadSegment("DIALOGS\\" + LanguageGetLanguage() + "\\Habitue_dialog.h");

	EndCancelInterface(true);

	if(gambleChar.Dialog.Filename=="Habitue_dialog.c" || gambleChar.Dialog.Filename=="Poker_Gamblers_dialog.c")
	{
		LAi_SetActorType(playerChar);
		LAi_ActorAnimation(playerChar, "Sit_Look_Around","exit_sit", 1);

		if (CheckAttribute(playerChar,"quest.poker.started"))// tournament result setting conditions
		{
			result = sti(playerChar.quest.poker.result);
			//TraceAndLog("result = " + result);
			//TraceAndLog("player = " + sti(playerChar.money));
			//TraceAndLog("gambler = " + sti(gambleChar.money));
			if (sti(playerChar.money) >  sti(gambleChar.money)) 
			{
				if (sti(playerChar.quest.poker.hands) >= 51)
				{
					//TraceAndLog("one");
					playerChar.quest.poker.result = result + sti(playerChar.quest.poker.day);
					if(DEBUG_GAMBLING>0) trace("GAMBLING: Called exit win");
				}
				else
				{
					if (sti(playerChar.money) == 20000)
					{
					//	TraceAndLog("two");
					//							TraceAndLog(sti(playerChar.quest.poker.day));
						result = sti(playerChar.quest.poker.result);
						playerChar.quest.poker.result = result + sti(playerChar.quest.poker.day);
				//TraceAndLog(sti(playerChar.quest.poker.result));
						if(DEBUG_GAMBLING>0) trace("GAMBLING: Called exit win");
					}
					else playerChar.quest.poker.result = result;
				}
			}
			else playerChar.quest.poker.result = result;
			
			if(DEBUG_GAMBLING>0) trace("GAMBLING: " + sti(playerChar.money));	
			playerChar.money = playerChar.money.backup;
			gambleChar.money = gambleChar.money.backup;
			if(DEBUG_GAMBLING>0) trace("money " + playerChar.money);
				
		}	//PW exit conditions for win lose etc  playerChar.money.backup = playerChar.money;
		else
		{
			if(sti(gambleChar.gamepoints)>sti(playerChar.gamepoints))
			{
				gambleChar.Dialog.Currentnode = "gamble_money";
			}
			else
			{
				if(sti(gambleChar.gamepoints)==sti(playerChar.gamepoints))
				{
					if(sti(playerChar.gamepoints)!=0) { gambleChar.Dialog.Currentnode = "draw"; }
				}
				else
				{
					gambleChar.Dialog.Currentnode = "lose_money";
				}
			}
		}
	}
	else
	{
		//Levis smuggling
		if(CheckAttribute(playerChar,"quest.Contraband.WonGame"))
		{
		//	gambleChar.Dialog.Filename = "random_guards_group_dialog.c";	// PB: This should already be the case!
			gambleChar.Dialog.Currentnode = "wongame";
			LAi_SetActorType(gambleChar);
			LAi_ActorDialog(gambleChar, playerChar, "", 5, 0);
		}
	}
	
	//Clean up quest relate stuff
	if(CheckAttribute(playerChar,"quest.Contraband.CardsBet"))
	{
		DeleteAttribute(playerChar,"quest.Contraband.CardsBet");
	}

	DeleteAttribute(playerChar,"gamepoints");
	DeleteAttribute(playerChar,"gambling");
	DeleteAttribute(playerChar,"cards");

	DeleteAttribute(gambleChar,"gamepoints");
	DeleteAttribute(gambleChar,"gambling");
	DeleteAttribute(gambleChar,"cards");
}

void InitCards()
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function InitCards");
	ref card;
	int n;

	for(n=0; n<MAX_CARDS; n++)
	{
		makeref(card,Cards[n]);
		DeleteAttribute(&card, "");
		card.id = "blank";
		card.face = "";
		card.value = "";
		card.colour = "";
	}
	n = 0;

	makeref(card,Cards[n]);
	card.id = "clubs_6";
	card.face = "6";
	card.faceId = "4";
	card.name = "card_six";
	card.value = "6";
	card.colour = "clubs";
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_6";
	card.face = "6";
	card.faceId = "4";
	card.name = "card_six";
	card.value = "6";
	card.colour = "hearts";
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_6";
	card.face = "6";
	card.faceId = "4";
	card.name = "card_six";
	card.value = "6";
	card.colour = "spades";
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_6";
	card.face = "6";
	card.faceId = "4";
	card.name = "card_six";
	card.value = "6";
	card.colour = "diamonds";
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_7";
	card.face = "7";
	card.faceId = "5";
	card.name = "card_seven";
	card.value = "7";
	card.colour = "clubs";
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_7";
	card.face = "7";
	card.faceId = "5";
	card.name = "card_seven";
	card.value = "7";
	card.colour = "hearts";
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_7";
	card.face = "7";
	card.faceId = "5";
	card.name = "card_seven";
	card.value = "7";
	card.colour = "spades";
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_7";
	card.face = "7";
	card.faceId = "5";
	card.name = "card_seven";
	card.value = "7";
	card.colour = "diamonds";
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_8";
	card.face = "8";
	card.faceId = "6";
	card.name = "card_eight";
	card.value = "8";
	card.colour = "clubs";
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_8";
	card.face = "8";
	card.faceId = "6";
	card.name = "card_eight";
	card.value = "8";
	card.colour = "hearts";
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_8";
	card.face = "8";
	card.faceId = "6";
	card.name = "card_eight";
	card.value = "8";
	card.colour = "spades";
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_8";
	card.face = "8";
	card.faceId = "6";
	card.name = "card_eight";
	card.value = "8";
	card.colour = "diamonds";
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_9";
	card.face = "9";
	card.faceId = "7";
	card.name = "card_nine";
	card.value = "9";
	card.colour = "clubs";
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_9";
	card.face = "9";
	card.faceId = "7";
	card.name = "card_nine";
	card.value = "9";
	card.colour = "hearts";
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_9";
	card.face = "9";
	card.faceId = "7";
	card.name = "card_nine";
	card.value = "9";
	card.colour = "spades";
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_9";
	card.face = "9";
	card.faceId = "7";
	card.name = "card_nine";
	card.value = "9";
	card.colour = "diamonds";
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_10";
	card.face = "10";
	card.faceId = "8";
	card.name = "card_ten";
	card.value = "10";
	card.colour = "clubs";
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_10";
	card.face = "10";
	card.faceId = "8";
	card.name = "card_ten";
	card.value = "10";
	card.colour = "hearts";
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_10";
	card.face = "10";
	card.faceId = "8";
	card.name = "card_ten";
	card.value = "10";
	card.colour = "spades";
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_10";
	card.face = "10";
	card.faceId = "8";
	card.name = "card_ten";
	card.value = "10";
	card.colour = "diamonds";
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_J";
	card.face = "J";
	card.faceId = "9";
	card.name = "card_jack";
	card.value = "10";
	card.colour = "clubs";
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_J";
	card.face = "J";
	card.faceId = "9";
	card.name = "card_jack";
	card.value = "10";
	card.colour = "hearts";
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_J";
	card.face = "J";
	card.faceId = "9";
	card.name = "card_jack";
	card.value = "10";
	card.colour = "spades";
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_J";
	card.face = "J";
	card.faceId = "9";
	card.name = "card_jack";
	card.value = "10";
	card.colour = "diamonds";
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_Q";
	card.face = "Q";
	card.faceId = "10";
	card.name = "card_queen";
	card.value = "10";
	card.colour = "clubs";
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_Q";
	card.face = "Q";
	card.faceId = "10";
	card.name = "card_queen";
	card.value = "10";
	card.colour = "hearts";
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_Q";
	card.face = "Q";
	card.faceId = "10";
	card.name = "card_queen";
	card.value = "10";
	card.colour = "spades";
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_Q";
	card.face = "Q";
	card.faceId = "10";
	card.name = "card_queen";
	card.value = "10";
	card.colour = "diamonds";
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_K";
	card.face = "K";
	card.faceId = "11";
	card.name = "card_king";
	card.value = "10";
	card.colour = "clubs";
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_K";
	card.face = "K";
	card.faceId = "11";
	card.name = "card_king";
	card.value = "10";
	card.colour = "hearts";
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_K";
	card.face = "K";
	card.faceId = "11";
	card.name = "card_king";
	card.value = "10";
	card.colour = "spades";
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_K";
	card.face = "K";
	card.faceId = "11";
	card.name = "card_king";
	card.value = "10";
	card.colour = "diamonds";
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_A";
	card.face = "A";
	card.faceId = "12";
	card.name = "card_ace";
	card.value = "11";
	card.colour = "clubs";
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_A";
	card.face = "A";
	card.faceId = "12";
	card.name = "card_ace";
	card.value = "11";
	card.colour = "hearts";
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_A";
	card.face = "A";
	card.faceId = "12";
	card.name = "card_ace";
	card.value = "11";
	card.colour = "spades";
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_A";
	card.face = "A";
	card.faceId = "12";
	card.name = "card_ace";
	card.value = "11";
	card.colour = "diamonds";
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_2";
	card.face = "2";
	card.faceId = "0";
	card.name = "card_two";
	card.value = "2";
	card.colour = "clubs";
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_2";
	card.face = "2";
	card.faceId = "0";
	card.name = "card_two";
	card.value = "2";
	card.colour = "hearts";
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_2";
	card.face = "2";
	card.faceId = "0";
	card.name = "card_two";
	card.value = "2";
	card.colour = "spades";
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_2";
	card.face = "2";
	card.faceId = "0";
	card.name = "card_two";
	card.value = "2";
	card.colour = "diamonds";
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_3";
	card.face = "3";
	card.faceId = "1";
	card.name = "card_three";
	card.value = "3";
	card.colour = "clubs";
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_3";
	card.face = "3";
	card.faceId = "1";
	card.name = "card_three";
	card.value = "3";
	card.colour = "hearts";
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_3";
	card.face = "3";
	card.faceId = "1";
	card.name = "card_three";
	card.value = "3";
	card.colour = "spades";
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_3";
	card.face = "3";
	card.faceId = "1";
	card.name = "card_three";
	card.value = "3";
	card.colour = "diamonds";
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_4";
	card.face = "4";
	card.faceId = "2";
	card.name = "card_four";
	card.value = "4";
	card.colour = "clubs";
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_4";
	card.face = "4";
	card.faceId = "2";
	card.name = "card_four";
	card.value = "4";
	card.colour = "hearts";
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_4";
	card.face = "4";
	card.faceId = "2";
	card.name = "card_four";
	card.value = "4";
	card.colour = "spades";
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_4";
	card.face = "4";
	card.faceId = "2";
	card.name = "card_four";
	card.value = "4";
	card.colour = "diamonds";
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_5";
	card.face = "5";
	card.faceId = "3";
	card.name = "card_five";
	card.value = "5";
	card.colour = "clubs";
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_5";
	card.face = "5";
	card.faceId = "3";
	card.name = "card_five";
	card.value = "5";
	card.colour = "hearts";
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_5";
	card.face = "5";
	card.faceId = "3";
	card.name = "card_five";
	card.value = "5";
	card.colour = "spades";
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_5";
	card.face = "5";
	card.faceId = "3";
	card.name = "card_five";
	card.value = "5";
	card.colour = "diamonds";
	n++;
}

int CardIndexFromId(string cardID)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function CardIndexFromId");
	int n = -1;
	for(n=0; n<CardsAmount; n++)
	{
		if(Cards[n].id==cardID) break;
		return n;
	}
	return n;
}

//Levis: Cleanup gambling code a bit
void DecideEnemyMove(ref Enemy, ref Player, string game)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Call function DecideEnemyMove");
	switch(game)
	{
		case "Vingt-Un":
			//Vingt-Un has open info so we can see info of the player
			trace("in Vingt-Un");
			if(sti(Enemy.cards.value)>sti(Player.cards.value))
			{
				if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI VINGT-UN: Enemy has more points then player so stop drawing cards.");
				bStop = true;
				AddOneCard(0, Enemy);
			}
			else
			{
				if(GetCardsOnHand(Enemy)<5)
				{
					if(sti(Enemy.cards.value)==sti(Player.cards.value))
					{
						if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI VINGT-UN: Enemy has equal points to the player so decide if extra cards need to be drawn.");
						
						//For now let's implement soft 17 stopping for a dealer, but this could be tweaked at a later stage
						//One suggestion is to also check on how many aces the gambler has, if he has an ace he wont stop at 17 because it could also be user as 1.
						//But that would need to then also check if this aces wasn't used as a 1 already.
						if(sti(Enemy.cards.value)<17)
						{
							if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI VINGT-UN: Enemy has less then 17 points and less then 5 cards so draw more.");
							AddOneCard(GetCardsOnHand(Enemy)+1, Enemy);
						}
						else
						{
							if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI VINGT-UN: The enemy has 17 or more points so accept the draw because the risk is to high.");
							bStop = true;
							AddOneCard(0, Enemy);
						}
					}
					else
					{
						if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI VINGT-UN: Enemy has less points then player and less then 5 cards so draw more.");
						AddOneCard(GetCardsOnHand(Enemy)+1, Enemy);
					}
				}
				else
				{
					if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI VINGT-UN: The enemy has to many cards on hand so check score.");
					bStop = true;
					AddOneCard(0, Enemy);
				}
			}
		break;
		
		case "Poker":
			int c, Amount;
			bool changecard = true;
			string curCard, cardName, cardFace, cardColour, max;
			aref multiples;
			//Poker has hidden info so we can't look at the cards of the player
			if(ValidateCombination(Enemy)>=16)
			{
				if(ValidateCombination(Enemy)!=19)
				{
					if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI POKER: Enemy has a combination which requires 5 cards so don't change cards.");
					changecard = false;
				}
			}
			if(changecard)
			{
				//Check the cards for paterns
				for(c=1; c<6; c++)
				{
					curCard = "card" + c;
					if(CheckAttribute(Enemy,"gambling."+curCard))
					{
						//Get the card
						cardName = Enemy.gambling.(curCard);
						if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI POKER: Check Card "+curCard+" Card is ["+cardName+"]");
						
						//Check for the type of card (A, K, 10 etc)
						cardFace = GetCardName(cardName);
						
						//Store the highest card
						if(!CheckAttribute(Enemy,"gambling.AI.highcard"))
						{
							if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI POKER: Stored "+cardFace+" as highcard");
							Enemy.gambling.AI.highcard = cardFace;
						}
						else
						{
							if(ValidateHighCard(cardFace) > ValidateHighCard(Enemy.gambling.AI.highcard))
							{
								if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI POKER: Stored "+cardFace+" as highcard");
								Enemy.gambling.AI.highcard = cardFace;
							}
						}
						
						//Check for how often the card is present in hand
						Amount = GetCardsAmount(Enemy, cardFace);
						if(Amount>1)
						{
							//Store cardsface of which we have a multiple
							if(!CheckAttribute(Enemy,"gambling.AI.multiples."+cardFace))
							{
								if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI POKER: Found "+Amount+" card of type "+cardFace);
								Enemy.gambling.AI.multiples.(cardFace) = Amount;
							}
							
							//Store the highest multiple we have
							if(!CheckAttribute(Enemy,"gambling.AI.multiples_max"))
							{
								if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI POKER: Stored "+Amount+" as highest multiple");
								Enemy.gambling.AI.multiples_max = Amount;
							}
							else
							{
								if(Amount > sti(Enemy.gambling.AI.multiples_max))
								{
									if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI POKER: Stored "+Amount+" as highest multiple");
									Enemy.gambling.AI.multiples_max = Amount;
								}
							}
						}
						
						//Check for the suit of the card (spades, hearts etc)
						cardColour = GetCardColour(cardName);
						
						//Store cardsface of which we have a multiple
						if(!CheckAttribute(Enemy,"gambling.AI.colours."+cardColour))
						{
							Amount = 1;
						}
						else
						{
							Amount = sti(Enemy.gambling.AI.colours.(cardColour)) + 1;
						}
						
						if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI POKER: Found "+cardColour+" amount "+Amount);
						Enemy.gambling.AI.colours.(cardColour) = Amount;
						
						//Store the highest multiple we hace
						if(!CheckAttribute(Enemy,"gambling.AI.colours_max"))
						{
							if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI POKER: Stored "+cardColour+" as highest colour");
							Enemy.gambling.AI.colours_max = cardColour;
						}
						else
						{
							max = Enemy.gambling.AI.colours_max;
							if(Amount > sti(Enemy.gambling.AI.colours.(max)))
							{
								if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI POKER: Stored "+cardColour+" as highest colour");
								Enemy.gambling.AI.colours_max = cardColour;
							}
						}
					}
				}
				
				//Decide what action to taken
				if(!CheckAttribute(Enemy,"gambling.AI.multiples")) //There are no pairs
				{
					if(Enemy.gambling.AI.colours_max == 4) //There is almost a flush
					{
						if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI POKER: No multiples in hand but 4 the same colours. So go for a flush.");
						for(c=1; c<6; c++)
						{
							curCard = "card" + c;
							if(CheckAttribute(Enemy,"gambling."+curCard))
							{
								//Get the card
								cardName = Enemy.gambling.(curCard);
								cardColour = GetCardColour(cardName);
								if(cardColour != Enemy.gambling.AI.colours_max)
								{
									if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI POKER: Replace "+curCard+" as it's not of colour "+Enemy.gambling.AI.colours_max);
									AutoUpdateOut(Enemy, curCard);
								}
							}
						}
					}
					else
					{
						if(ValidateHighCard(Enemy.gambling.AI.highcard) > 7) //There is a jack or higher in hand so keep that incase of high card
						{
							for(c=1; c<6; c++)
							{
								curCard = "card" + c;
								if(CheckAttribute(Enemy,"gambling."+curCard))
								{
									cardName = Enemy.gambling.(curCard);
									cardFace = GetCardName(cardName);
									if(cardFace != Enemy.gambling.AI.highcard)
									{
										if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI POKER: Replace "+curCard+" because it's value is to low for highcard");
										AutoUpdateOut(Enemy, curCard);
									}
								}
							}
						}
						else //Replace all
						{
							for(c=1; c<6; c++)
							{
								curCard = "card" + c;
								if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI POKER: Replace "+curCard+" because hand is rubish");
								AutoUpdateOut(Enemy, curCard);
							}
						}
					}
				}
				else
				{
					//There are multiples
					if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI POKER: Multiples in hand so replace the cards not part of a multiple.");
					for(c=1; c<6; c++)
					{
						curCard = "card" + c;
						if(CheckAttribute(Enemy,"gambling."+curCard))
						{
							cardName = Enemy.gambling.(curCard);
							cardFace = GetCardName(cardName);
							Amount = GetCardsAmount(Enemy, cardFace);
							if(Amount == 1)
							{
								if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI POKER: Replace "+curCard+" because it's not part of a multiple of "+Amount);
								AutoUpdateOut(Enemy, curCard);
							}
						}
					}
				}
			}
		break;
	}
	
	if(CheckAttribute(Enemy,"gambling.AI"))
	{
		if(DEBUG_GAMBLING_AI>0) trace("GAMBLING AI: Cleared AI data");
		DeleteAttribute(Enemy,"gambling.AI");
	}
}

void DisableBet()
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function DisableBet");
	string btnName;
	int l;
	for(l=1; l<=GetMaxBetIndex(); l++) //Changed to 7 for gamble perk
	{
		btnName = "BET_"+l;
		SetSelectable(btnName,false);
	}
}

void ClearCardImages(string iGroup)
{
	if(DEBUG_GAMBLING>0 || DEBUG_GAMBLING_CARD>0) trace("GAMBLING: Called function ClearCardImages");
	CreateImage("P_01",iGroup, "",  0,405,60,490);
	CreateImage("P_02",iGroup, "", 75,405,135,490);
	CreateImage("P_03",iGroup, "",155,405,210,490);
	CreateImage("P_04",iGroup, "",235,405,290,490);
	CreateImage("P_05",iGroup, "",315,405,370,490);
	CreateImage("G_01",iGroup, "",  0,145,50,230);
	CreateImage("G_02",iGroup, "", 75,145,135,230);
	CreateImage("G_03",iGroup, "",155,145,210,230);
	CreateImage("G_04",iGroup, "",235,145,290,230);
	CreateImage("G_05",iGroup, "",315,145,370,230);
}

void UpdateCardImage(string type, ref Character, string iGroup, int cardidx, bool cardup)
{
	if(DEBUG_GAMBLING>0 || DEBUG_GAMBLING_CARD>0) trace("GAMBLING: Called function UpdateCardImage");
	string curCard = "card" + cardidx;
	if(CheckAttribute(Character,"gambling."+curCard))
	{
		string cardName = "";
		cardName = Character.gambling.(curCard);
		UpdateCardImageWithCardName(type, iGroup, curCard, cardName, cardup);
	}
}

void DiscardCard(ref Character, string iGroup, int cardidx)
{
	if(DEBUG_GAMBLING>0 || DEBUG_GAMBLING_CARD>0) trace("GAMBLING: Called function DiscardCard");
	string curCard = ""
	if(IsMainCharacter(Character))
	{
		PlaySound("gamble_card_take");
		curCard = "left_" + cardidx;
	}
	else
	{
		curCard = "left_" + (cardidx+5);
	}
	UpdateCardImageWithCardName("D", iGroup, curCard, curCard, false);
}

void UpdateCardImageWithCardName(string type, string iGroup, string curCard, string cardName, bool cardup)
{
	if(DEBUG_GAMBLING>0 || DEBUG_GAMBLING_CARD>0) trace("GAMBLING: Called function UpdateCardImageWithCardName");
	if(DEBUG_GAMBLING_CARD>0) trace("GAMBLING CARD: type = "+type+" iGroup = "+iGroup+" curCard = "+curCard+" cardName = "+cardName+" cardup = "+cardup);
	int x, y;
	switch(type)
	{
		case "P": //Cards for the player character
			if(cardup) { x = 370; y = 455; }
			else { x = 405; y = 490; }
			switch(curCard)
			{
				case "card1": CreateImage("P_01",iGroup, cardName,  0,x, 60,y); break;
				case "card2": CreateImage("P_02",iGroup, cardName, 75,x,135,y); break;
				case "card3": CreateImage("P_03",iGroup, cardName,150,x,210,y); break;
				case "card4": CreateImage("P_04",iGroup, cardName,225,x,285,y); break;
				case "card5": CreateImage("P_05",iGroup, cardName,300,x,360,y); break;
			}
		break;
		
		case "G": //Cards for the gambler character
			if(cardup) { x = 180; y = 265;}
			else { x = 145; y = 230;}
			switch(curCard)
			{
				case "card1": CreateImage("G_01",iGroup, cardName,  0,x, 60,y); break;
				case "card2": CreateImage("G_02",iGroup, cardName, 75,x,135,y); break;
				case "card3": CreateImage("G_03",iGroup, cardName,150,x,210,y); break;
				case "card4": CreateImage("G_04",iGroup, cardName,225,x,285,y); break;
				case "card5": CreateImage("G_05",iGroup, cardName,300,x,360,y); break;
			}
		break;
		
		case "D": //Discarded cards
			switch(curCard)
			{
				//Side Player
				case "left_1": CreateImage("LEFT_06",iGroup, "left_1", 285,269,360,364); break;
				case "left_2": CreateImage("LEFT_07",iGroup, "left_2", 290,269,365,364); break;
				case "left_3": CreateImage("LEFT_08",iGroup, "left_3", 293,269,394,369); break;
				case "left_4": CreateImage("LEFT_09",iGroup, "left_4", 295,269,374,365); break;
				case "left_5": CreateImage("LEFT_10",iGroup, "left_5", 297,269,392,369); break;
				
				//Side Gambler
				case "left_6": CreateImage("LEFT_01",iGroup, "left_6", 280,269,343,357); break;
				case "left_7": CreateImage("LEFT_02",iGroup, "left_7", 270,269,356,325); break;
				case "left_8": CreateImage("LEFT_03",iGroup, "left_8", 275,274,361,330); break;
				case "left_9": CreateImage("LEFT_04",iGroup, "left_9", 260,250,355,330); break;
				case "left_10": CreateImage("LEFT_05",iGroup, "left_10",270,255,374,348); break;
			}
		break;
	}
}

void SetCardChanging(bool card, bool trade)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function SetCardChanging");
	string btnName;
	int l;
	for(l=1; l<=5; l++)
	{
		btnName = "B_HeroDice"+l;
		UpdateButtons(btnName, card);

		btnName = "B_HeroDice"+l+"_1";
		UpdateButtons(btnName, trade);
	}
}

void ClearBetImages()
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function ClearBetImages");
	CreateImage("BET_1","", "",60,250,120,310);
	CreateImage("BET_2","", "",30,280,90,340);
	CreateImage("BET_3","", "",50,270,110,330);
	CreateImage("BET_4","", "",80,230,140,290);
	CreateImage("BET_5","", "",40,240,100,300);
	CreateImage("BET_6","", "",70,220,130,280);
}

void UpdateBetButtons(int BIndex)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function UpdateBetButtons");	
	//First Disable all
	DisableBet();
	
	//Check if the money is right
	if(makeint(playerChar.money)<GetGameBet(BIndex+1) || makeint(gambleChar.money)<GetGameBet(BIndex+1))
	{
		if(bNewGame) //Check if we are betting or in a game where raising is an option
		{
			SetSelectable("BET_1",true);
		}
	}
	else
	{
		//Set right bet selectable
		string btnName = "Bet_"+(BIndex+1);
		if(BIndex > 4){
			if(gambleperk){
				if(BIndex > 5)
				{
					if(bNewGame)
					{
						SetSelectable("BET_1",true);
					}
				}
				else
				{
					SetSelectable(btnName,true);
				}
			}
			else
			{
				if(bNewGame) 
				{
					SetSelectable("BET_1",true);
				}
			}
		}
		else
		{
			SetSelectable(btnName,true);
		}
	}
}

void UpdateBetImages(int BIndex)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function UpdateBetImages");
	
	bool QuestBet = false;
	
	// First clear all
	ClearBetImages();
	
	if(CheckAttribute(playerChar,"quest.Contraband.CardsBet")) 
	{
		SetSelectable("BET_1",false); //change to false for gamble perk
		SetSelectable("BET_2",false);
		SetSelectable("BET_3",false);
		SetSelectable("BET_4",false);
		SetSelectable("BET_5",false);
		SetSelectable("BET_6",false);
		CreateImage("BET_3","", "",50,270,110,330);
		CreateImage("BET_4","", "",80,230,140,290);
		CreateImage("BET_5","", "",40,240,100,300);
		CreateImage("BET_1",imageGroup, "gold",70,265,130,325);
		CreateImage("BET_2",imageGroup, "gold",85,275,145,335);
		QuestBet = true;
	}

	if(!QuestBet)
	{
		switch(BIndex)
		{
			case 1:
				switch(Rand(1))
				{
					case 0: CreateImage("BET_1",imageGroup, "silver",30,280,90,340); break;
					case 1: CreateImage("BET_1",imageGroup, "silver",60,250,120,310); break;
				}
			break;
				
			case 2:
				CreateImage("BET_1",imageGroup, "silver",60,250,120,310);
				CreateImage("BET_2",imageGroup, "silver", 30,280,90,340);
			break;

			case 3:
				CreateImage("BET_1",imageGroup, "silver",60,250,120,310);
				CreateImage("BET_2",imageGroup, "silver", 30,280,90,340);
				CreateImage("BET_3",imageGroup, "silver",50,270,110,330);
				CreateImage("BET_4",imageGroup, "silver",80,230,140,290);
				CreateImage("BET_5",imageGroup, "silver",40,240,100,300);
			break;

			case 4:
				switch(Rand(1))
				{
					case 0: CreateImage("BET_1",imageGroup, "gold",70,265,130,325); break;
					case 1: CreateImage("BET_1",imageGroup, "gold",85,275,145,335); break;
				}
			break;

			case 5:
				CreateImage("BET_1",imageGroup, "gold",70,265,130,325);
				CreateImage("BET_2",imageGroup, "gold",85,275,145,335);
			break;
			
			case 6:
				CreateImage("BET_1",imageGroup, "gold",70,265,130,325);
				CreateImage("BET_2",imageGroup, "gold",85,275,145,335);
				CreateImage("BET_3",imageGroup, "gold",40,240,100,300);
				CreateImage("BET_4",imageGroup, "gold",50,270,110,330);
				CreateImage("BET_5",imageGroup, "gold",60,250,120,310);
			break;
		}
	}
}

String GetBetInfoText(int tmpLangFileID, int BIndex)
{
	if (CheckAttribute(playerChar,"quest.poker.started"))
	{
		if(makeint(playerChar.money)<GetGameBet(BIndex)) return LanguageConvertString(tmpLangFileID,"NoGambleMoneyPoker");
		if(makeint(gambleChar.money)<GetGameBet(BIndex)) return gambleChar.name + "! " + LanguageConvertString(tmpLangFileID,"NoGamblerMoneyPoker");
	}
	else
	{
		if(makeint(playerChar.money)<GetGameBet(BIndex)) return LanguageConvertString(tmpLangFileID,"NoGambleMoney");
		if(makeint(gambleChar.money)<GetGameBet(BIndex)) return gambleChar.name + "! " + LanguageConvertString(tmpLangFileID,"NoGamblerMoney");
	}
		
	switch(BIndex)
	{
		case 0:
			if (CheckAttribute(playerChar,"quest.poker.started"))
			{
				return LanguageConvertString(tmpLangFileID,"NoGambleMoneyPoker");
			}
			else 
			{
				return LanguageConvertString(tmpLangFileID,"NoGambleMoney");
			}
		break;
		
		case 1:
			if (CheckAttribute(playerChar,"quest.poker.started"))
			{
				return LanguageConvertString(tmpLangFileID,"GambleBetMinPoker");
			}
			else 
			{
				return LanguageConvertString(tmpLangFileID,"GambleBetMin");
			}
		break;
	}
	
	return "";
}

string GetBetText(int BIndex)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function GetBetText");
	string text = XI_ConvertString("GameBet") + "  " + GetGameBet(BetIndex);
	
	//Quest stuff
	if(CheckAttribute(playerChar,"quest.Contraband.CardsBet"))
	{
		text = text + " " + XI_ConvertString("GameSmug");
	}
	
	return text;
}

void UpdateMoneyPile(ref Character, string IGroup)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function UpdateMoneyPile");
	int moneyRemaing = sti(Character.money);
	int coins = 1;
	string moneyType = "G";
	string coindid = "";
	if(IsMainCharacter(Character)) moneyType = "P";
	
	while(moneyRemaing > 0 && coins < 7)
	{
		coindid = "COIN_"+coins
		
		if(moneyRemaing > GetGameBet(4))
		{
			moneyRemaing -= GetGameBet(4);
			UpdateCoinImage(moneyType, IGroup, coindid, "gold");
		}
		else
		{
			if(moneyRemaing > GetGameBet(1))
			{
				moneyRemaing -= GetGameBet(1);
				UpdateCoinImage(moneyType, IGroup, coindid, "silver");
			}
			else
			{
				moneyRemaing = 0;
				UpdateCoinImage(moneyType, IGroup, coindid, "silver");
			}
		}
		
		coins++;
	}
	
	// Make the rest empty
	for(coins; coins < 7; coins++)
	{
		coindid = "COIN_"+coins
		UpdateCoinImage(moneyType, IGroup, coindid, "");
	}
}

void UpdateCoinImage(string type, string iGroup, string coindid, string cointype)
{
	if (CheckAttribute(playerChar,"quest.poker.started"))
	{	
		switch(type)
		{
		
			case "P": //Player money pile
				switch(coindid)
				{
					case "COIN_1": CreateImage("P_COIN1",imageGroup, "silver",500,240,560,300); break;
					case "COIN_2": CreateImage("P_COIN2",imageGroup, cointype,530,230,590,290); break;
					case "COIN_3": CreateImage("P_COIN3",imageGroup, cointype,490,245,550,305); break;
					case "COIN_4": CreateImage("P_COIN4",imageGroup, cointype,525,250,585,310); break;
					case "COIN_5": CreateImage("P_COIN5",imageGroup, cointype,470,220,530,280); break;
					case "COIN_6": CreateImage("P_COIN6",imageGroup, cointype,520,260,580,320); break;
				}
			break;
		
			case "G": //Gamble money pile
				switch(coindid)
				{
					case "COIN_1": CreateImage("G_COIN1",imageGroup, "silver",170,60,230,120); break;
					case "COIN_2": CreateImage("G_COIN2",imageGroup, cointype,160,50,220,110); break;
					case "COIN_3": CreateImage("G_COIN3",imageGroup, cointype,150,70,210,130); break;
					case "COIN_4": CreateImage("G_COIN4",imageGroup, cointype,175,70,235,130); break;
					case "COIN_5": CreateImage("G_COIN5",imageGroup, cointype,160,80,220,140); break;
					case "COIN_6": CreateImage("G_COIN6",imageGroup, cointype,130,50,190,110); break;
				}
			break;
		}
	}
	else
	{	
		switch(type)
		{
			case "P": //Player money pile
				switch(coindid)
				{
					case "COIN_1": CreateImage("P_COIN1",imageGroup, cointype,500,240,560,300); break;
					case "COIN_2": CreateImage("P_COIN2",imageGroup, cointype,530,230,590,290); break;
					case "COIN_3": CreateImage("P_COIN3",imageGroup, cointype,490,245,550,305); break;
					case "COIN_4": CreateImage("P_COIN4",imageGroup, cointype,525,250,585,310); break;
					case "COIN_5": CreateImage("P_COIN5",imageGroup, cointype,470,220,530,280); break;
					case "COIN_6": CreateImage("P_COIN6",imageGroup, cointype,520,260,580,320); break;
				}
			break;
		
			case "G": //Gamble money pile
				switch(coindid)
				{
					case "COIN_1": CreateImage("G_COIN1",imageGroup, cointype,370,60,430,120); break;
					case "COIN_2": CreateImage("G_COIN2",imageGroup, cointype,360,50,420,110); break;
					case "COIN_3": CreateImage("G_COIN3",imageGroup, cointype,350,70,410,130); break;
					case "COIN_4": CreateImage("G_COIN4",imageGroup, cointype,375,75,435,135); break;
					case "COIN_5": CreateImage("G_COIN5",imageGroup, cointype,360,90,420,150); break;
					case "COIN_6": CreateImage("G_COIN6",imageGroup, cointype,430,50,490,110); break;
				}
			break;
		}
	}
}

void UpdateCardDeck()
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function UpdateCardDeck");
	aref playingcards;
	makearef(playingcards,CardPack.cards);
	int amountcards = GetAttributesNum(playingcards);
	if(amountcards > 5)
	{
		CreateImage("B_CARDS",imageGroup, "pack",480,20,610,160);
	}
	else
	{
		CreateImage("B_CARDS",imageGroup, "blank",518,25,600,155);
	}
}

int GetMaxRaises()
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function GetMaxRaises");
	int MaxRaises = 0;
	bool QuestBet = false;
	//Quest related best
	if(CheckAttribute(playerChar,"quest.Contraband.CardsBet")) QuestBet = true;	// Block raising if gambling for smuggling info
	
	if(!QuestBet)
	{
		switch(playerChar.location)
		{	
			case "Cartagena Casino":
				MaxRaises = 2;
			break;
			
			//default:
			MaxRaises = 3;
		}
	}
	return MaxRaises;
}

//Levis: Make bets more variable
int GetGameBet(int BIndex)
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function GetGameBet");
	int GameBet = 0;
	bool QuestBet = false;
	//Quest related best
	if(CheckAttribute(playerChar,"quest.Contraband.CardsBet"))
	{
		GameBet = sti(playerChar.quest.Contraband.CardsBet);
		QuestBet = true;
	}
	
	if(!QuestBet)
	{
		switch(playerChar.location){
			
			case "Cartagena Casino":
				switch(BIndex) 
				{
					case 1:  GameBet = 300; break;
					case 2:  GameBet = 600; break;
					case 3:  GameBet = 1250; break;
					case 4:  GameBet = 2500; break;
					case 5:  GameBet = 5000; break;
					case 6:  GameBet = 10000; break;
				}
			break;
			
			//default:
				switch(BIndex)
				{
					case 1:  GameBet = 100; break;
					case 2:  GameBet = 200; break;
					case 3:  GameBet = 500; break;
					case 4:  GameBet = 1000; break;
					case 5:  GameBet = 2000; break;
					case 6:  GameBet = 5000; break;
				}
		
		}
	}
	return GameBet;
}

int GetMaxBetIndex()
{
	if(DEBUG_GAMBLING>0) trace("GAMBLING: Called function GetMaxBetIndex");
	return 6;
}
