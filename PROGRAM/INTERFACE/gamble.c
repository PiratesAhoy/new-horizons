//=====| INTERFACE FOR GAMBLE IN TAVERN (written by MAXIMUS. INI files taken from SLiB addon and changed a little) |=====//
#define MAX_CARDS	52

string DLG_TEXT[121];// from Habitue_dialog.h

object Cards[MAX_CARDS];

int gameBet;
int CardsAmount;

ref playerChar;
ref gambleChar;

bool bNewGame = true;
bool bPlayerMove = false;
bool bGambleMove = false;
bool bFirst = false;
bool bStop = false;
bool bFirstTime;// needed for help showing - once for each game
bool bStart = true;
bool bInTavern = true;// I planned to add a game with a friendly governor. This prevents showing shabby cards
bool dupfail = false; //Levis: allow doubleup
bool dupdone = false; //Levis: allow doubleup
bool gambleperk = false; //Levis gamble perk

string infoText;
string GameName;
string gambleID;
string cardNames;
string imageGroup;
// DeathDaisy -->
string you_lose = DLG_TEXT[36]; // "! You lose, lad/lass!"
string you_lose2 = DLG_TEXT[54]; // "You've lost, lad/lass!"
string lucky_man = DLG_TEXT[106]; // "... Lucky man/girl. Give me the card..."
// DeathDaisy <-- Thanks GR!

int curSkillValue1,curSkillValue2;

void InitInterface_RS(string iniName, ref gambler, string curName)
{
	switch(curName)
	{
		case "BlackJack": GameInterface.title = "titleBlackJack"; break;
		case "Poker": GameInterface.title = "titlePoker"; break;
		case "Dumb": GameInterface.title = "titleDumb"; break;
		case "Dice": GameInterface.title = "titleDice"; break;
	}

	GameName = curName;
	if(GameName=="Dumb") CardsAmount = 36;
	else CardsAmount = MAX_CARDS;

	playerChar = GetMainCharacter();
	gambleperk = CheckCharacterPerk(playerChar,"HighStakes"); //Just to be sure because it seemed to work strange.
	gambleChar = gambler;
	gambleID = gambler.id;
	gameBet = 0;
	infoText = "";
	imageGroup = FindCardsForNation(gambleChar);// returns nation-description (british, spanish, etc.) plus "_cards"
	
	// DeathDaisy --> putting this here because playerChar isn't defined outside the function
	if(playerChar.sex == "woman")
	{
		you_lose = DLG_TEXT[118];
		you_lose2 = DLG_TEXT[119];
		lucky_man = DLG_TEXT[120];
	}
	else
	{
		you_lose = DLG_TEXT[36];
		you_lose2 = DLG_TEXT[54];
		lucky_man = DLG_TEXT[106];
	}
	// DeathDaisy <-- Thanks GR!
	// GR: setting default value outside this function didn't work.  Settings for male character now brought in here.
	
	playerChar.gamepoints = "0";
	gambleChar.gamepoints = "0";

	if(!CheckAttribute(gambleChar,"money")) gambleChar.money = sti(rand(1000)+2000);
	else
	{
		if(sti(gambleChar.money)<=500) gambleChar.money = sti(rand(1000)+2000);
	}

	if(!CheckAttribute(playerChar,"firsttime."+GameName)) { bFirstTime = true; }
	else { bFirstTime = false; }

	if(HasSubStr(playerChar.location,"tavern")) { bInTavern = true; }
	else { bInTavern = false; }

	if(imageGroup=="british_cards") bInTavern = false;// shabby texture not needed for these cards

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);

    if(AUTO_SKILL_SYSTEM)
	{
		curSkillValue1 = 610;
		if(CheckAttribute(playerChar,"Experience.Sneak")) curSkillValue1 = 610 + sti(makeint(sti(playerChar.Experience.Sneak)/500)*0.58);
		CreateImage("LUCK1","ICONS", "status line filled",610,413,curSkillValue1,418);

		curSkillValue2 = 0;
		if(CheckAttribute(playerChar,"Experience.Sneak")) curSkillValue2 = sti(makeint(sti(gambleChar.Experience.Sneak)/500)*1.28);
		CreateImage("LUCK2","ICONS", "status line filled",0,2,curSkillValue2,8);
	}

	CreateString(true,"CurrentBet","",FONT_SEADOGS,COLOR_NORMAL,20,300,SCRIPT_ALIGN_LEFT,1.2);
	CreateString(true,"PlayerMoney","",FONT_NORMAL,COLOR_MONEY,405,420,SCRIPT_ALIGN_LEFT,1.0);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	SetNodeUsing("STATUS", AUTO_SKILL_SYSTEM);
	SetNodeUsing("LUCK1", AUTO_SKILL_SYSTEM);
	SetNodeUsing("LUCK2", AUTO_SKILL_SYSTEM);
	ChangePicture("BACKGROUND", "interfaces\card_sukno.tga", !HasSubStr(playerChar.location,"tavern"));
	CreateString(AUTO_SKILL_SYSTEM,"GambleSneakLevel",sti(gambleChar.skill.Sneak),FONT_BOLD_NUMBERS,COLOR_NORMAL,120,105,SCRIPT_ALIGN_RIGHT,0.8);

	SetGame(GameName);

	switch(GameName)
	{
		case "BlackJack": if(bFirstTime) playerChar.firsttime.BlackJack = true; break;
		case "Poker": if(bFirstTime) playerChar.firsttime.Poker = true; break;
		case "Dumb": if(bFirstTime) playerChar.firsttime.Dumb = true; break;
		case "Dice": if(bFirstTime) playerChar.firsttime.Dice = true; break;
	}

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

string FindCardsForNation(ref refCharacter)// by this way anyone can make his own cards, and can put new (properly named) *.tx file into RESOURCE\TEXTURES\INTERFACES (pictures.ini contains already all needed sections)
{
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
		if(curCardsNation==GetNationDescByType(sti(refCharacter.nation)))
		{
		      cardsNation = strcut(fname,0,strlen(fname)-8);
		}
	}
	return cardsNation;
}

void SetGame(string gameName)// resets all to virginity :)
{
	string plMoney = "";
	cardNames = "";
	InitCards();
	for(int n=0; n<CardsAmount; n++)
	{
		Cards[n].ingame = false;
	}
	GameInterface.strings.CurrentBet = XI_ConvertString("GameBet") + "  " + gameBet;
	if(CheckAttribute(playerChar,"quest.Contraband.Cards")) GameInterface.strings.CurrentBet = GameInterface.strings.CurrentBet + " + Smuggling Plans"; //Levis added for smuggling game
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

	CreateImage("B_CARDS",imageGroup, "pack",480,20,610,160);

	switch(gameName)
	{
		case "BlackJack":
			PlaySound("gamble_card_shuffle");
		break;

		case "Poker":
			PlaySound("gamble_card_shuffle");

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
			PlaySound("gamble_card_shuffle");
		break;

		case "Dice":
			CreateImage("B_CARDS","DICE", "cup",445,40,600,160);
			SetNodeUsing("MYFACE",false);
			SetNodeUsing("ENFACE",false);
			if(bPlayerMove) bGambleMove = false;
			else bGambleMove = true;
			if(bGambleMove) bPlayerMove = false;
			else bPlayerMove = true;
		break;
	}

	if(sti(playerChar.money)<=3000) plMoney = "silver";
	else plMoney = "gold";
			
	CreateImage("P_GOLD_1",imageGroup, plMoney,500,240,560,300);
	CreateImage("P_SILVER_1",imageGroup, "silver",530,230,590,290);
	CreateImage("P_GOLD_2",imageGroup, plMoney,490,245,550,305);
	CreateImage("P_SILVER_2",imageGroup, "silver",525,250,585,310);
	CreateImage("P_GOLD_3",imageGroup, plMoney,470,220,530,280);
	CreateImage("P_SILVER_3",imageGroup, "silver",520,260,580,320);

	CreateImage("G_SILVER_1",imageGroup, "silver",370,60,430,120);
	CreateImage("G_GOLD_1",imageGroup, "gold",360,50,420,110);
	CreateImage("G_SILVER_2",imageGroup, "silver",350,70,410,130);
	CreateImage("G_GOLD_2",imageGroup, "gold",375,75,435,135);
	CreateImage("G_SILVER_3",imageGroup, "silver",360,90,420,150);
	CreateImage("G_GOLD_3",imageGroup, "gold",430,50,490,110);

	if(sti(playerChar.money)>sti(gambleChar.money))
	{
		CreateImage("P_GOLD_4",imageGroup, plMoney,510,240,570,300);
		CreateImage("P_GOLD_5",imageGroup, plMoney,520,240,590,300);
	}
}

void StartGame()// no comments :)
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	bFirst = false;
	dupfail = false; //Levis: allow double up
	dupdone = false; //Levis: allow double up
	int k, j, l;
	string cardName = "";
	string btnName = "";
	GameName = strcut(GameInterface.title,5,strlen(GameInterface.title)-1);
	if(bNewGame)
	{
		bFirstTime = false;
		SetGame(GameName);
		SetFormatedText("FIRST_TEXT", "");
//		cardNames = "clubs_2,hearts_2,spades_2,diamonds_2,clubs_3,hearts_3,spades_3,diamonds_3,clubs_4,hearts_4,spades_4,diamonds_4,clubs_5,hearts_5,spades_5,diamonds_5,clubs_6,hearts_6,spades_6,diamonds_6,clubs_7,hearts_7,spades_7,diamonds_7,clubs_8,hearts_8,spades_8,diamonds_8,clubs_9,hearts_9,spades_9,diamonds_9,clubs_10,hearts_10,spades_10,diamonds_10,clubs_J,hearts_J,spades_J,diamonds_J,clubs_Q,hearts_Q,spades_Q,diamonds_Q,clubs_K,hearts_K,spades_K,diamonds_K,clubs_A,hearts_A,spades_A,diamonds_A";
		switch(gameName)
		{
			if(gameBet==0 || sti(playerChar.money)<gameBet || makeint(gambleChar.money)<gameBet)
			{
				UpdateStuff();
				return;
			}
			case "BlackJack":
				cardNames = ShuffleCards();
				SetNodeUsing("MYFACE",false);
				SetNodeUsing("ENFACE",false);
				SetSelectable("BET_1",false);
				SetSelectable("ICON_GOLD",false);
				SetSelectable("EXIT_BUTTON",false);
				bPlayerMove = false;
				bGambleMove = false;
				playerChar.cards.aces = 0; //Levis blackjack aces fix
				gambleChar.cards.aces = 0; //Levis blackjack aces fix
				bFirst = true;
				bStop = false;
				for(k=1; k<3; k++)
				{
					cardName = GetPlayableCard();
					ProcessGiveCards(playerChar, k, cardName);
					SetNodeUsing("MYFACE",true);
					bPlayerMove = true;
					if(k>=3) { sndNum = makeint(k/3); }
					else { sndNum = k; }
					PlaySound("AMBIENT\TAVERN\GAMBLE\card"+sndNum+".wav");
				}

				for(j=1; j<3; j++)
				{
					cardName = GetPlayableCard();
					ProcessGiveCards(gambleChar, j, cardName);
					if(sti(playerChar.cards.value)>=14) { SetNodeUsing("ENFACE",true); SetSelectable("ENFACE",true); }
					if(makeint(21-sti(playerChar.cards.value))<=7) { bGambleMove = true; }
					if(j>=3) { sndNum = makeint(j/3); }
					else { sndNum = j; }
					PlaySound("AMBIENT\TAVERN\GAMBLE\card"+sndNum+".wav");
				}
				bNewGame = false;
				if(sti(playerChar.cards.value)>=21) { bStop = false; bPlayerMove = true; bGambleMove = false; UpdateTable(); }
				if(sti(gambleChar.cards.value)==21) { bStop = false; bPlayerMove = false; bGambleMove = true; UpdateTable(); }

				for(l=1; l<7; l++) //Changed to 7 for gamble perk
				{
					btnName = "B_HeroDice"+l;
					UpdateButtons(btnName, false); //Levis 16-10-13 Changed to false because you can't change cards.

					btnName = "B_HeroDice"+l+"_1";
					UpdateButtons(btnName, false);

					//btnName = "BET_"+l;
					//SetSelectable(btnName,true); //Levis allow double up.
				}
			break;

			case "Poker":
				cardNames = ShuffleCards();
				SetNodeUsing("MYFACE",true);
				SetNodeUsing("ENFACE",false);
				SetSelectable("BET_1",false);
				SetSelectable("ICON_GOLD",false);
				SetSelectable("EXIT_BUTTON",false);
				bPlayerMove = false;
				bGambleMove = false;
				bFirst = true;
				bStop = false;
				bStart = true;
				string cardFace;
				int sndNum;
				for(k=1; k<6; k++)
				{
					cardName = GetPlayableCard();
					ProcessGiveCards(playerChar, k, cardName);
					bPlayerMove = true;
					if(k>=3) { sndNum = makeint(k/3); }
					else { sndNum = k; }
					PlaySound("AMBIENT\TAVERN\GAMBLE\card"+sndNum+".wav");
				}

				for(j=1; j<6; j++)
				{
					cardName = GetPlayableCard();
					ProcessGiveCards(gambleChar, j, cardName);
					if(j>=3) { sndNum = makeint(j/3); }
					else { sndNum = j; }
					PlaySound("AMBIENT\TAVERN\GAMBLE\card"+sndNum+".wav");
				}
				bNewGame = false;
				SetSelectable("MYFACE",false);
				if(ValidateCombination(playerChar)>=4)
				{
					if(ValidateCombination(playerChar)!=7)
					{
						SetNodeUsing("ENFACE",true);
						SetSelectable("ENFACE",true);
						bGambleMove = true;
						bStart = true;
					}
				}

				for(l=1; l<7; l++) //Changed to 7 for gamble perk
				{
					btnName = "B_HeroDice"+l;
					UpdateButtons(btnName, true);

					btnName = "B_HeroDice"+l+"_1";
					UpdateButtons(btnName, false);

					btnName = "BET_"+l;
					SetSelectable(btnName,false);
				}
			break;

			case "Dumb":
				cardNames = ShuffleCards();
			break;

			case "Dice":
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
	//Levis: allow doubleup -->
	if(GetCardsOnHand(playerChar)>=5)
	{
		for(l=1; l<7; l++) //Changed to 7 for gamble perk
		{
			btnName = "BET_"+l;
			SetSelectable(btnName,false);
		}
	}
	//Levis: allow doubleup <--
	switch(GameName)
	{
		case "BlackJack":
			if(bGambleMove)
			{
				if(!bPlayerMove)
				{
					if(sti(playerChar.skill.Sneak)>sti(gambleChar.skill.Sneak))
					{
						switch(Rand(2))
						{
							case 0: if(sti(gambleChar.cards.value)>=18) { bStop = true; bGambleMove = false; UpdateTable(); return; } break;
							case 1: if(sti(gambleChar.cards.value)>=19) { bStop = true; bGambleMove = false; UpdateTable(); return; } break;
							case 2: if(sti(gambleChar.cards.value)>=20) { bStop = true; bGambleMove = false; UpdateTable(); return; } break;
						}
					}
					else
					{
						if(sti(gambleChar.cards.value)>=20) { bStop = true; bGambleMove = false; UpdateTable(); return; }
					}
				}
			}

			if(sti(playerChar.cards.value)>=14) { SetNodeUsing("ENFACE",true); SetSelectable("ENFACE",true); }

			if(bPlayerMove)
			{
				if(sti(playerChar.cards.value)>=21) { bStop = false; bGambleMove = false; bPlayerMove = true; UpdateTable(); return; }
				if(makeint(21-sti(playerChar.cards.value))<=7) { bStop = false; bGambleMove = true; return; }
			}
		
			if(bGambleMove)
			{
				if(!bPlayerMove)
				{
					bFirst = false;
					bPlayerMove = false;
					if(sti(gambleChar.cards.value)>=20) { bStop = true; bGambleMove = false; UpdateTable(); return; }
					else
					{
						if(sti(gambleChar.cards.value)>=sti(playerChar.cards.value))
						{
							if(!bFirst) { bStop = true; bGambleMove = false; UpdateTable(); return; }
						}
					}
				}
				if(GetCardsOnHand(gambleChar)>=5) { bStop = false; bGambleMove = true; bPlayerMove = false; UpdateTable(); return; }
				//Levis allow doubleup -->
				for(l=1; l<7; l++) //change to 7 for gamble perk
				{
					btnName = "BET_"+l;
					SetSelectable(btnName,false);
				}
				//Levis allow doubleup <--
			}
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
	GameName = strcut(GameInterface.title,5,strlen(GameInterface.title)-1);
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	if(gameName!="Dice")
	{
		SetSelectable("EXIT_BUTTON",true);
		SetSelectable("ICON_GOLD",true);
	}
	switch(gameName)
	{		
		case "BlackJack":
			if(bStop)
			{
				if(sti(gambleChar.cards.value)<21)
				{
					if(sti(gambleChar.cards.value)>=sti(playerChar.cards.value))
					{
						infoText = DLG_TEXT[101] + sti(gambleChar.cards.value) + you_lose;
						VewGamble(infoText);
						UpdateBet("lose");
						return;
					}
					else
					{
						infoText = Randswear() + " " + sti(gambleChar.cards.value) + DLG_TEXT[104];
						VewGamble(infoText);
						UpdateBet("win");
						return;
					}
				}
				else
				{
					if(sti(gambleChar.cards.value)==21)
					{
						infoText = DLG_TEXT[101] + sti(gambleChar.cards.value) + you_lose;
						VewGamble(infoText);
						UpdateBet("lose");
						return;
					}
					else
					{
						infoText = Randswear() + " " + sti(gambleChar.cards.value) + DLG_TEXT[103];
						VewGamble(infoText);
						UpdateBet("win");
						return;
					}
				}
			}

			if(sti(gambleChar.cards.value)==21)
			{
				infoText = DLG_TEXT[101] + sti(gambleChar.cards.value) + you_lose;
				VewGamble(infoText);
				UpdateBet("lose");
				return;
			}
			else
			{
				if(bGambleMove)
				{
					if(sti(gambleChar.cards.value)>21)
					{
						infoText = Randswear() + " " + sti(gambleChar.cards.value) + DLG_TEXT[103];
						VewGamble(infoText);
						UpdateBet("win");
						return;
					}
					else
					{
						if(sti(gambleChar.cards.value)==20)
						{
							if(sti(gambleChar.cards.value)>=sti(playerChar.cards.value))
							{
								infoText = DLG_TEXT[101] + sti(gambleChar.cards.value) + you_lose;
								VewGamble(infoText);
								UpdateBet("lose");
								return;
							}
							else
							{
								infoText = Randswear() + " " + sti(gambleChar.cards.value) + DLG_TEXT[104];
								VewGamble(infoText);
								UpdateBet("win");
								return;
							}
						}
						else
						{
							if(sti(gambleChar.cards.value)>=sti(playerChar.cards.value))
							{
								infoText = DLG_TEXT[101] + sti(gambleChar.cards.value) + you_lose;
								VewGamble(infoText);
								UpdateBet("lose");
								return;
							}
							else
							{
								infoText = Randswear() + " " + sti(gambleChar.cards.value) + DLG_TEXT[104];
								VewGamble(infoText);
								UpdateBet("win");
								return;
							}
						}
					}
				}
			}

			if(bPlayerMove)
			{
				if(sti(playerChar.cards.value)<=21)
				{
					SetSelectable("EXIT_BUTTON",false);
					SetSelectable("ICON_GOLD",false);
				}

				if(sti(playerChar.cards.value)==21)
				{
					SetNodeUsing("MYFACE",false);
					SetFormatedText("INFO_TEXT", sti(playerChar.cards.value) + lucky_man);
					bGambleMove = true;
					bPlayerMove = false;
					bFirst = false;
				}
				else
				{						
					if(sti(playerChar.cards.value)>21)
					{
						infoText = DLG_TEXT[101] + sti(gambleChar.cards.value) + DLG_TEXT[107];
						bPlayerMove = false; //Fix for double after end
						VewGamble(infoText);
						UpdateBet("lose");
						return;
					}
					else
					{
						if(sti(playerChar.cards.value)<=sti(gambleChar.cards.value))
						{
							if(sti(gambleChar.cards.value)<=21)
							{
								infoText = DLG_TEXT[101] + sti(gambleChar.cards.value) + you_lose;
								VewGamble(infoText);
								UpdateBet("lose");
								return;
							}
							else
							{
								infoText = Randswear() + " " + sti(gambleChar.cards.value) + DLG_TEXT[103];
								VewGamble(infoText);
								UpdateBet("win");
								return;
							}
						}
						else
						{
							infoText = Randswear() + " " + sti(gambleChar.cards.value) + DLG_TEXT[104];
							VewGamble(infoText);
							UpdateBet("win");
							return;
						}
					}
				}
			}
		break;

		case "Poker":
			UpdateHand(GetCardsCombination(playerChar));
		break;

		case "Dumb":
		break;

		case "Dice":
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

				if(iEnemyDice<=10) { infoText = iEnemyDice + DLG_TEXT[48]; VewGamble(infoText); return; }
				if(iEnemyDice>10 && iEnemyDice<=15) { infoText = iEnemyDice + DLG_TEXT[49]; VewGamble(infoText); return; }
				if(iEnemyDice>15 && iEnemyDice<=20) { infoText = iEnemyDice + DLG_TEXT[50]; VewGamble(infoText); return; }
				if(iEnemyDice>20) { infoText = iEnemyDice + DLG_TEXT[51]; VewGamble(infoText); return; }
			}

			if(bPlayerMove)
			{
				SetSelectable("ICON_GOLD",true);
				SetSelectable("EXIT_BUTTON",true);
				bPlayerMove = false;
				if(makeint(playerChar.money)>=gameBet) bGambleMove = true;
				else
				{
					bGambleMove = false;
					playerChar.quest.gambling = makeint(playerChar.quest.gambling) - 1;
					infoText = LanguageConvertString(tmpLangFileID,"NoGambleMoney");
					gameBet = 0;
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
					infoText = iPCDice + DLG_TEXT[53] + you_lose2;
					VewGamble(infoText);
					UpdateBet("lose");
					DeleteAttribute(playerChar, "iEnemyDice");
					return;
				}

				if(iPCDice>makeint(playerChar.iEnemyDice))
				{
					bGambleMove = true;
					infoText = RandSwear() + iPCDice + DLG_TEXT[57] + DLG_TEXT[58];
					VewGamble(infoText);
					UpdateBet("win");
					DeleteAttribute(playerChar, "iEnemyDice");
					return;
				}

				if(iPCDice==makeint(playerChar.iEnemyDice))
				{
					bGambleMove = true;
					infoText = RandSwear() + DLG_TEXT[61];
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
	int c, k, j, playerCount, gambleCount;
	string curCard = "";
	string cardName = "";
	string cardFace = "";
	string btnName = "";
	string cardsInCombo = "";
	string cardsCombo = "";
	playerChar.gambling.most = "";
	gambleChar.gambling.most = "";
	playerCount = GetMostCard(playerChar);
	gambleCount = GetMostCard(gambleChar);
	switch(GetCardsCombination(gambleChar))
	{
		case "Pair": cardsInCombo = XI_ConvertString(gambleChar.gambling.most); break;
		case "Four of Kind": cardsInCombo = XI_ConvertString(gambleChar.gambling.most); break;
		case "Variegated": cardsInCombo = ""; break;

		cardsInCombo = XI_ConvertString("my combination is better");
	}

	switch(GetCardsCombination(playerChar))
	{
		case "Pair": cardsCombo = XI_ConvertString(playerChar.gambling.most); break;
		case "Four of Kind": cardsCombo = XI_ConvertString(playerChar.gambling.most); break;
		case "Variegated": cardsCombo = ""; break;

		switch(Rand(4))
		{
			case 0: cardsCombo = XI_ConvertString("your combination is better"); break;
			case 1: cardsCombo = XI_ConvertString("combination1"); break;
			case 2: cardsCombo = XI_ConvertString("combination2"); break;
			case 3: cardsCombo = XI_ConvertString("combination3"); break;
			case 4: cardsCombo = XI_ConvertString("combination4"); break;
		}
	}

	SetSelectable("B_PACK",true);

	for(j=1; j<6; j++)
	{
		btnName = "B_HeroDice"+j;
		UpdateButtons(btnName, false);

		btnName = "B_HeroDice"+j+"_1";
		UpdateButtons(btnName, false);
	}

	if(GetCardsCombination(gambleChar)==cardCombination)
	{
		if(playerCount>gambleCount)
		{
			infoText = Randswear() + XI_ConvertString(GetCardsCombination(playerChar)) + cardsCombo + DLG_TEXT[104];
			VewGamble(infoText);
			UpdateBet("win");
			return;
		}

		if(playerCount<gambleCount)
		{
			infoText = DLG_TEXT[101] + XI_ConvertString(GetCardsCombination(gambleChar)) + cardsInCombo + you_lose;
			VewGamble(infoText);
			UpdateBet("lose");
			return;
		}

		if(playerCount==gambleCount)
		{
			infoText = Randswear() + XI_ConvertString(GetCardsCombination(playerChar)) + XI_ConvertString("same combination") + "...";
			VewGamble(infoText);
			UpdateBet("draw");
			return;
		}
	}
	else
	{
		if(GetCardsCombination(gambleChar)=="Variegated")
		{
			infoText = Randswear() + XI_ConvertString(GetCardsCombination(playerChar)) + cardsCombo + DLG_TEXT[104];
			VewGamble(infoText);
			UpdateBet("win");
			return;
		}

		if(ValidateCombination(playerChar)<=1)
		{
			infoText = DLG_TEXT[101] + XI_ConvertString(GetCardsCombination(gambleChar))  + cardsInCombo + you_lose;
			UpdateBet("lose");
		}
		else
		{
			if(ValidateCombination(playerChar)>ValidateCombination(gambleChar))
			{
				infoText = Randswear() + XI_ConvertString(GetCardsCombination(playerChar)) + cardsCombo + DLG_TEXT[104];
				UpdateBet("win");
			}
			else
			{
				infoText = DLG_TEXT[101] + XI_ConvertString(GetCardsCombination(gambleChar)) + cardsInCombo + you_lose;
				UpdateBet("lose");
			}
		}
		VewGamble(infoText);
		return;
	}
}

int ValidateCombination(ref refCharacter)
{
	int comboNum = 0;
	string charCombination = GetCardsCombination(refCharacter);
	switch(charCombination)
	{
		case "Variegated": comboNum = 0; break;
		case "Pair": comboNum = 1; break;
		case "Two Pairs": comboNum = 2; break;
		case "Three of Kind": comboNum = 3; break;
		case "Straight": comboNum = 4; break;
		case "Flush": comboNum = 5; break;
		case "Full House": comboNum = 6; break;
		case "Four of Kind": comboNum = 7; break;
		case "Straight Flush": comboNum = 8; break;
		case "Royal Flush": comboNum = 9; break;
	}
	return comboNum;
}

void UpdateBet(string gameResult)// shows player money on the table, calculate game-result and works with bet-buttons
{
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

	if(gameBet>500) expDivider = 1.5;

	switch(gameResult)
	{
		case "win":
			AddMoneyToCharacter(playerChar, gameBet);
			AddMoneyToCharacter(gambleChar, -gameBet);
			PlaySound("gamble_shout_loose");
			SetSelectable("B_PACK", false);
			PostEvent("Money",500,"s",gameResult);
			playerChar.gamepoints = sti(playerChar.gamepoints) + makeint(gameBet);
			if(AUTO_SKILL_SYSTEM) { AddCharacterExpChar(playerChar, "Sneak", makeint(gameBet/expDivider)); }
			else { AddCharacterExp(playerChar, makeint(gameBet/expDivider)); }
			playerChar.quest.gambling = makeint(playerChar.quest.gambling) + sti(playerChar.Skill.Sneak);
			//Levis smuggling game
			if(CheckAttribute(playerChar,"quest.Contraband.Cards"))
			{
				gambleChar.money = 0;
				DeleteAttribute(playerChar,"quest.Contraband.Cards"));
				playerChar.quest.Contraband.WonGame = 1;
			}
		break;

		case "lose":
			AddMoneyToCharacter(playerChar, -gameBet);
			AddMoneyToCharacter(gambleChar, gameBet);
			PlaySound("gamble_shout_win");
			SetSelectable("B_PACK", false);
			PostEvent("Money",500,"s",gameResult);
			gambleChar.gamepoints = sti(gambleChar.gamepoints) + makeint(gameBet);
			if(AUTO_SKILL_SYSTEM) { AddCharacterExpNSChar(gambleChar, "Sneak", makeint(gameBet/expDivider)); }
			else { AddCharacterExp(gambleChar, makeint(gameBet/expDivider)); }
			playerChar.quest.gambling = makeint(playerChar.quest.gambling) - 1;
		break;

		case "draw":
			playerChar.gamepoints = sti(playerChar.gamepoints) + makeint(gameBet);
			gambleChar.gamepoints = sti(gambleChar.gamepoints) + makeint(gameBet);
			if(AUTO_SKILL_SYSTEM)
			{
				AddCharacterExpChar  (playerChar, SKILL_SNEAK, makeint(gameBet)/makeint(expDivider*5));
				AddCharacterExpNSChar(gambleChar, SKILL_SNEAK, makeint(gameBet)/makeint(expDivider*5));
			}
			else
			{
				AddCharacterExp(playerChar, makeint(gameBet)/makeint(expDivider*5));
				AddCharacterExp(gambleChar, makeint(gameBet)/makeint(expDivider*5));
			}
			PlaySound("gamble_shout_draw");
			SetSelectable("B_PACK", false);
			PostEvent("Money",200,"s",gameResult);
		break;
	}

	GameInterface.strings.PlayerMoney = playerChar.money;
	GameInterface.strings.CurrentBet = XI_ConvertString("GameBet") + "  " + gameBet;

    if(AUTO_SKILL_SYSTEM)
	{
		curSkillValue1 = 610;
		if(CheckAttribute(playerChar,"Experience.Sneak")) curSkillValue1 = 610 + sti(makeint(sti(playerChar.Experience.Sneak)/500)*0.58);
		CreateImage("LUCK1","ICONS", "status line filled",610,413,curSkillValue1,418);

		curSkillValue2 = 0;
		if(CheckAttribute(playerChar,"Experience.Sneak")) curSkillValue2 = sti(makeint(sti(gambleChar.Experience.Sneak)/500)*1.28);
		CreateImage("LUCK2","ICONS", "status line filled",0,3,curSkillValue2,8);

		if(sti(GameInterface.strings.GambleSneakLevel)<sti(gambleChar.skill.Sneak))
		{
			SetFormatedText("FIRST_TEXT", XI_ConvertString("Warning")+"! "+GetCharacterFullName(gambleChar.id)+" "+XI_ConvertString("playing_better")+".");
			GameInterface.strings.GambleSneakLevel = sti(gambleChar.skill.Sneak);
		}
	}
	//Levis: allow doubleup-->
	if(dupdone)
	{
		gameBet = gameBet/2;
		if(gameBet==250) gameBet=200;
		if(gameBet==2500) gameBet=2000; //Gamble Perk
	}
	//Levis: allow doubleup<--
	
	switch(gameBet) //Levis: moved for allow doubleup
	{
		case 0:    SetSelectable("BET_1",true); break;
		case 100:  SetSelectable("BET_2",true); break;
		case 200:  SetSelectable("BET_3",true); break;
		case 500:  SetSelectable("BET_4",true); break;
		case 1000: SetSelectable("BET_5",true); break;
		case 2000: if(gambleperk) SetSelectable("BET_6",true); else SetSelectable("BET_1",true); break; // changed to BET_6 for gamble perk
		case 5000: SetSelectable("BET_1",true); break; //Gamble Perk
	}
	if(sti(playerChar.money)<=0)
	{
		CreateImage("P_GOLD_1","", "",  500,240,560,300);
		CreateImage("P_SILVER_1","", "",530,230,590,290);
		CreateImage("P_GOLD_2","", "",  490,245,550,305);
		CreateImage("P_SILVER_2","", "",525,250,585,310);
		CreateImage("P_GOLD_3","", "",  470,220,530,280);
		CreateImage("P_SILVER_3","", "",520,260,580,320);
	}
}

void MoneyOperation()
{
	string gameResult = GetEventData();
	if(gameResult!="draw")
	{
		CreateImage("BET_1","", "",40,235,100,295);
		CreateImage("BET_2","", "",55,275,115,335);
		CreateImage("BET_3","", "",60,250,120,310);
		CreateImage("BET_4","", "", 30,280,90,340);
		CreateImage("BET_5","", "",40,240,100,300);
		CreateImage("BET_6","", "",70,220,130,280); // gamble perk
	}
	switch(gameResult)
	{
		case "win": PlayStereoSound("INTERFACE\took_item.wav"); break;
		case "lose": PlayStereoSound("gamble_give_money"); break;
	}
	SetSelectable("B_PACK", true);
	DelEventHandler("Money","MoneyOperation");
}

void UpdateStuff()// shows money on the table and resets all buttons
{
	SetSelectable("B_PACK", true);
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	if(makeint(playerChar.money)<gameBet) infoText = LanguageConvertString(tmpLangFileID,"NoGambleMoney");
	else
	{
		if(makeint(gambleChar.money)<gameBet) infoText = gambleChar.name + "! " + LanguageConvertString(tmpLangFileID,"NoGamblerMoney");
		else infoText = "";
	}

	string btnName;
	for(int i=1; i<6; i++)
	{
		btnName = "B_HeroDice"+i;
		UpdateButtons(btnName, false);

		btnName = "B_HeroDice"+i+"_1";
		UpdateButtons(btnName, false);
	}
	
	if(bNewGame)//Levis allow doubleup
	{
		if(bInTavern)
		{
			CreateImage("P_1","OLD_SHADOWS", "",  0,405,60,490);
			CreateImage("P_2","OLD_SHADOWS", "", 75,405,135,490);
			CreateImage("P_3","OLD_SHADOWS", "",150,405,210,490);
			CreateImage("P_4","OLD_SHADOWS", "",225,405,285,490);
			CreateImage("P_5","OLD_SHADOWS", "",300,405,360,490);
			CreateImage("G_1","OLD_SHADOWS", "",  0,145,60,230);
			CreateImage("G_2","OLD_SHADOWS", "", 75,145,135,230);
			CreateImage("G_3","OLD_SHADOWS", "",150,145,210,230);
			CreateImage("G_4","OLD_SHADOWS", "",225,145,285,230);
			CreateImage("G_5","OLD_SHADOWS", "",300,145,360,230);
		}

		CreateImage("P_01",imageGroup, "",  0,405,60,490);
		CreateImage("P_02",imageGroup, "", 75,405,135,490);
		CreateImage("P_03",imageGroup, "",155,405,210,490);
		CreateImage("P_04",imageGroup, "",235,405,290,490);
		CreateImage("P_05",imageGroup, "",315,405,370,490);
		CreateImage("G_01",imageGroup, "",  0,145,50,230);
		CreateImage("G_02",imageGroup, "", 75,145,135,230);
		CreateImage("G_03",imageGroup, "",155,145,210,230);
		CreateImage("G_04",imageGroup, "",235,145,290,230);
		CreateImage("G_05",imageGroup, "",315,145,370,230);
	}//Levis allow doubleup

	if(makeint(playerChar.money)>=gameBet && makeint(gambleChar.money)>=gameBet)
	{
		CreateImage("BET_1","", "",60,250,120,310);
		CreateImage("BET_2","", "",30,280,90,340);
		CreateImage("BET_3","", "",50,270,110,330);
		CreateImage("BET_4","", "",80,230,140,290);
		CreateImage("BET_5","", "",40,240,100,300);
		CreateImage("BET_6","", "",70,220,130,280); // gamble perk
		if(gameBet>0) { PlaySound("gamble_give_money"); }
		switch(gameBet)
		{
			case 0:
				SetSelectable("BET_1",true);
				SetSelectable("BET_2",false);
				SetSelectable("BET_3",false);
				SetSelectable("BET_4",false);
				SetSelectable("BET_5",false);
				SetSelectable("BET_6",false); //Gamble Perk
				if(makeint(gambleChar.money)<=gameBet) infoText = gambleChar.name + "! " + LanguageConvertString(tmpLangFileID,"NoGamblerMoney");
				else infoText = LanguageConvertString(tmpLangFileID,"NoGambleMoney");
			break;
			case 100:
				SetSelectable("BET_1",false);
				SetSelectable("BET_2",true);
				SetSelectable("BET_3",false);
				SetSelectable("BET_4",false);
				SetSelectable("BET_5",false);
				SetSelectable("BET_6",false); //Gamble Perk
				//CreateImage("BET_1",imageGroup, "silver",30,280,90,340);
				//Added a bit of randomization
				switch(Rand(1))
				{
					case 0: CreateImage("BET_1",imageGroup, "silver",30,280,90,340); break;
					case 1: CreateImage("BET_1",imageGroup, "silver",60,250,120,310); break;
				}
				infoText = LanguageConvertString(tmpLangFileID,"GambleBetMin");
			break;
				
			case 200:
				SetSelectable("BET_1",false);
				SetSelectable("BET_2",false);
				SetSelectable("BET_3",true);
				SetSelectable("BET_4",false);
				SetSelectable("BET_5",false);
				SetSelectable("BET_6",false); //Gamble Perk
				CreateImage("BET_1",imageGroup, "silver",60,250,120,310);
				CreateImage("BET_2",imageGroup, "silver", 30,280,90,340);
			break;

			case 500:
				SetSelectable("BET_1",false);
				SetSelectable("BET_2",false);
				SetSelectable("BET_3",false);
				SetSelectable("BET_4",true);
				SetSelectable("BET_5",false);
				SetSelectable("BET_6",false); //Gamble Perk
				CreateImage("BET_3",imageGroup, "silver",50,270,110,330);
				CreateImage("BET_4",imageGroup, "silver",80,230,140,290);
				CreateImage("BET_5",imageGroup, "silver",40,240,100,300);
				CreateImage("BET_1",imageGroup, "silver",60,250,120,310);
				CreateImage("BET_2",imageGroup, "silver", 30,280,90,340);
			break;

			case 1000:				
				SetSelectable("BET_1",false);
				SetSelectable("BET_2",false);
				SetSelectable("BET_3",false);
				SetSelectable("BET_4",false);
				SetSelectable("BET_5",true);
				SetSelectable("BET_6",false); //Gamble Perk
				CreateImage("BET_2","", "",50,270,110,330);
				CreateImage("BET_3","", "",50,270,110,330);
				CreateImage("BET_4","", "",80,230,140,290);
				CreateImage("BET_5","", "",40,240,100,300);
				switch(Rand(1))
				{
					case 0: CreateImage("BET_1",imageGroup, "gold",70,265,130,325); break;
					case 1: CreateImage("BET_1",imageGroup, "gold",85,275,145,335); break;
				}
			break;

			case 2000:
				SetSelectable("BET_1",false); //change to false for gamble perk
				SetSelectable("BET_2",false);
				SetSelectable("BET_3",false);
				SetSelectable("BET_4",false);
				SetSelectable("BET_5",false);
				// gambleperk -->
				if(!CheckAttribute(playerChar,"quest.Contraband.Cards"))
				{
					if(gambleperk)
					{
						SetSelectable("BET_6",true);
					}
					else
					{
						SetSelectable("BET_6",false);
						SetSelectable("BET_1",true);
					}
				}
				else
				{
					SetSelectable("BET_6",false);
				}
				// <--- gamble perk
				// Changed by Levis
				CreateImage("BET_3","", "",50,270,110,330);
				CreateImage("BET_4","", "",80,230,140,290);
				CreateImage("BET_5","", "",40,240,100,300);
				CreateImage("BET_1",imageGroup, "gold",70,265,130,325);
				CreateImage("BET_2",imageGroup, "gold",85,275,145,335);
				// End Change
				/*if(makeint(playerChar.money)<=3000)
				{
					CreateImage("BET_2",imageGroup, "silver", 30,280,90,340);
					CreateImage("BET_4",imageGroup, "silver",80,230,140,290);
					CreateImage("BET_5",imageGroup, "silver",40,240,100,300);
					CreateImage("BET_3",imageGroup, "silver",50,270,110,330);
					CreateImage("BET_1",imageGroup, "silver",60,250,120,310);

					switch(Rand(4))
					{
						case 0: CreateImage("BET_1",imageGroup, "gold",70,265,130,325); break;
						case 1: CreateImage("BET_2",imageGroup, "gold",85,275,145,335); break;
						case 2: CreateImage("BET_3",imageGroup, "gold",40,240,100,300); break;
						case 3: CreateImage("BET_4",imageGroup, "gold",50,270,110,330); break;
						case 3: CreateImage("BET_5",imageGroup, "gold",60,250,120,310); break;
					}
				}
				else
				{
					CreateImage("BET_1",imageGroup, "gold",70,265,130,325);
					CreateImage("BET_2",imageGroup, "gold",85,275,145,335);
				}*/
			break;
			
			//Gamble Perk -->
			case 5000:
				SetSelectable("BET_1",true);
				SetSelectable("BET_2",false);
				SetSelectable("BET_3",false);
				SetSelectable("BET_4",false);
				SetSelectable("BET_5",false);
				SetSelectable("BET_6",false); //Gamble Perk
				CreateImage("BET_1",imageGroup, "gold",70,265,130,325);
				CreateImage("BET_2",imageGroup, "gold",85,275,145,335);
				CreateImage("BET_3",imageGroup, "gold",40,240,100,300);
				CreateImage("BET_4",imageGroup, "gold",50,270,110,330);
				CreateImage("BET_5",imageGroup, "gold",60,250,120,310);
			break;
			//<--- Gameble Perk
		}
	}
	else
	{
		//Levis: allow doubleup -->
		if(bPlayerMove && GameName=="BlackJack")
		{
			infoText = DLG_TEXT[117];
			VewGamble(infoText);
			dupfail=false
		}
		else
		{ //Levis: allow doubleup <--
			if(makeint(playerChar.money)<gameBet) infoText = LanguageConvertString(tmpLangFileID,"NoGambleMoney");
			else
			{
				if(makeint(gambleChar.money)<gameBet) infoText = gambleChar.name + "! " + LanguageConvertString(tmpLangFileID,"NoGamblerMoney");
				else infoText = LanguageConvertString(tmpLangFileID,"NoGambleMoney");
			}
			SetSelectable("BET_1",true);
			SetSelectable("BET_2",false);
			SetSelectable("BET_3",false);
			SetSelectable("BET_4",false);
			SetSelectable("BET_5",false);
			SetSelectable("BET_6",false); //gamble perk
			CreateImage("BET_1","", "",70,265,130,325);
			CreateImage("BET_2","", "",85,275,145,335);
			CreateImage("BET_3","", "",40,240,100,300);
			CreateImage("BET_4","", "",50,270,110,330);
			CreateImage("BET_5","", "",60,250,120,310);
			CreateImage("BET_6","", "",70,220,130,280); //gamble perk
			gameBet = 0;
		}//Levis: allow doubleup
	}
	SetFormatedText("INFO_TEXT", infoText);
	GameInterface.strings.CurrentBet = XI_ConvertString("GameBet") + "  " + gameBet;
	//Levis add smuggling game
	if(CheckAttribute(playerChar,"quest.Contraband.Cards")) 
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
		gameBet = sti(playerChar.quest.Contraband.CardsBet); //Levis smuggling way to get plans
		GameInterface.strings.CurrentBet = XI_ConvertString("GameBet") + "  " + gameBet;
		if(makeint(gambleChar.money)<=gameBet) gambleChar.money = sti(gambleChar.money) + gameBet;
		GameInterface.strings.CurrentBet = GameInterface.strings.CurrentBet + " + Smuggling Plans";
	}
	GameInterface.strings.PlayerMoney = playerChar.money;

	SetFormatedText("FIRST_TEXT", "");
	GameName = strcut(GameInterface.title,5,strlen(GameInterface.title)-1);
	switch(GameName)
	{
		case "BlackJack": if(bFirstTime) { SetFormatedText("FIRST_TEXT", LanguageConvertString(tmpLangFileID,"FirstTimePlayingBlackJack")); } else { SetFormatedText("FIRST_TEXT", ""); } break;
		case "Poker": if(bFirstTime) { SetFormatedText("FIRST_TEXT", LanguageConvertString(tmpLangFileID,"FirstTimePlayingPoker")); } else { SetFormatedText("FIRST_TEXT", ""); } break;
		case "Dumb": if(bFirstTime) { SetFormatedText("FIRST_TEXT", LanguageConvertString(tmpLangFileID,"FirstTimePlayingDumb")); } else { SetFormatedText("FIRST_TEXT", ""); } break;
		case "Dice": if(bFirstTime) { SetFormatedText("FIRST_TEXT", LanguageConvertString(tmpLangFileID,"FirstTimePlayingDice")); } else { SetFormatedText("FIRST_TEXT", ""); } break;
	}

	LanguageCloseFile(tmpLangFileID);
}

void VewGamble(string infoText)// shows the game result
{
	SetFormatedText("INFO_TEXT", infoText);
	GameName = strcut(GameInterface.title,5,strlen(GameInterface.title)-1);
	string curCard, cardName, cardFace;
	int j, i, k, l;
	switch(GameName)
	{
		case "BlackJack":
			for(i=1; i<6; i++)
			{
				curCard = "card" + i;
				cardName = "";
				if(CheckAttribute(playerChar,"gambling."+curCard))
				{
					cardName = playerChar.gambling.(curCard);
					switch(curCard)
					{
						case "card1": CreateImage("P_01",imageGroup, cardName,  0,405, 60,490); if(bInTavern) CreateImage("P_1","OLD_SHADOWS", cardName,  0,405, 60,490); break;
						case "card2": CreateImage("P_02",imageGroup, cardName, 75,405,135,490); if(bInTavern) CreateImage("P_2","OLD_SHADOWS", cardName, 75,405,135,490); break;
						case "card3": CreateImage("P_03",imageGroup, cardName,150,405,210,490); if(bInTavern) CreateImage("P_3","OLD_SHADOWS", cardName,150,405,210,490); break;
						case "card4": CreateImage("P_04",imageGroup, cardName,225,405,285,490); if(bInTavern) CreateImage("P_4","OLD_SHADOWS", cardName,225,405,285,490); break;
						case "card5": CreateImage("P_05",imageGroup, cardName,300,405,360,490); if(bInTavern) CreateImage("P_5","OLD_SHADOWS", cardName,300,405,360,490); break;
					}
				}
			}
			for(j=1; j<6; j++)
			{
				curCard = "card" + j;
				cardName = "";
				if(CheckAttribute(gambleChar,"gambling."+curCard))
				{
					cardName = gambleChar.gambling.(curCard);
					switch(curCard)
					{
						case "card1": CreateImage("G_01",imageGroup, cardName,  0,145, 60,230); if(bInTavern) CreateImage("G_1","OLD_SHADOWS", cardName,  0,145, 60,230); break;
						case "card2": CreateImage("G_02",imageGroup, cardName, 75,145,135,230); if(bInTavern) CreateImage("G_2","OLD_SHADOWS", cardName, 75,145,135,230); break;
						case "card3": CreateImage("G_03",imageGroup, cardName,150,145,210,230); if(bInTavern) CreateImage("G_3","OLD_SHADOWS", cardName,150,145,210,230); break;
						case "card4": CreateImage("G_04",imageGroup, cardName,225,145,285,230); if(bInTavern) CreateImage("G_4","OLD_SHADOWS", cardName,225,145,285,230); break;
						case "card5": CreateImage("G_05",imageGroup, cardName,300,145,360,230); if(bInTavern) CreateImage("G_5","OLD_SHADOWS", cardName,300,145,360,230); break;
					}
				}
			}
		break;

		case "Poker":
			bool allShow = false;
			int x, y;
			if(ValidateCombination(playerChar)>=4)
			{
				if(ValidateCombination(playerChar)!=7) allShow = true;
			}
			else allShow = false;
			for(i=1; i<6; i++)
			{
				curCard = "card" + i;
				cardName = "";
				if(CheckAttribute(playerChar,"gambling."+curCard))
				{
					cardName = playerChar.gambling.(curCard);
					cardFace = GetCardName(cardName);
					if(allShow || GetCardsAmount(playerChar, cardFace)>1) { x = 370; y = 455; }
					else { x = 405; y = 490; }
					switch(curCard)
					{
						case "card1": CreateImage("P_01",imageGroup, cardName,  0,x, 60,y); if(bInTavern) CreateImage("P_1","OLD_SHADOWS", cardName,  0,x, 60,y); break;
						case "card2": CreateImage("P_02",imageGroup, cardName, 75,x,135,y); if(bInTavern) CreateImage("P_2","OLD_SHADOWS", cardName, 75,x,135,y); break;
						case "card3": CreateImage("P_03",imageGroup, cardName,150,x,210,y); if(bInTavern) CreateImage("P_3","OLD_SHADOWS", cardName,150,x,210,y); break;
						case "card4": CreateImage("P_04",imageGroup, cardName,225,x,285,y); if(bInTavern) CreateImage("P_4","OLD_SHADOWS", cardName,225,x,285,y); break;
						case "card5": CreateImage("P_05",imageGroup, cardName,300,x,360,y); if(bInTavern) CreateImage("P_5","OLD_SHADOWS", cardName,300,x,360,y); break;
					}
				}
			}

			if(ValidateCombination(gambleChar)>=4)
			{
				if(ValidateCombination(gambleChar)!=7) allShow = true;
			}
			else allShow = false;
			for(j=1; j<6; j++)
			{
				bool bVisible = false;
				curCard = "card" + j;
				cardName = "";
				string ourCard = "blank";
				if(CheckAttribute(gambleChar,"gambling."+curCard))
				{
					cardName = gambleChar.gambling.(curCard);
					cardFace = GetCardName(cardName);
					if(allShow || GetCardsAmount(gambleChar, cardFace)>1) { x = 180; y = 265; ourCard = cardName; bVisible = true; }
					else { x = 145; y = 230; ourCard = "blank"; bVisible = false; }
					switch(curCard)
					{
						case "card1": CreateImage("G_01",imageGroup, ourCard,  0,x, 60,y); if(bInTavern && bVisible) CreateImage("G_1","OLD_SHADOWS", cardName,  0,x, 60,y); break;
						case "card2": CreateImage("G_02",imageGroup, ourCard, 75,x,135,y); if(bInTavern && bVisible) CreateImage("G_2","OLD_SHADOWS", cardName, 75,x,135,y); break;
						case "card3": CreateImage("G_03",imageGroup, ourCard,150,x,210,y); if(bInTavern && bVisible) CreateImage("G_3","OLD_SHADOWS", cardName,150,x,210,y); break;
						case "card4": CreateImage("G_04",imageGroup, ourCard,225,x,285,y); if(bInTavern && bVisible) CreateImage("G_4","OLD_SHADOWS", cardName,225,x,285,y); break;
						case "card5": CreateImage("G_05",imageGroup, ourCard,300,x,360,y); if(bInTavern && bVisible) CreateImage("G_5","OLD_SHADOWS", cardName,300,x,360,y); break;
					}
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

void GambleMove(ref refCharacter)// table updates for "Poker"
{
	string curCard = "";
	string cardName = "";
	string cardFace = "";
	int i;
	SetNodeUsing("ENFACE",bGambleMove);
	SetSelectable("ENFACE",bGambleMove);
	SetSelectable("MYFACE",bPlayerMove);
	SetSelectable("B_PACK",bPlayerMove);

	string btnName;
	for(int j=1; j<6; j++)
	{
		btnName = "B_HeroDice"+j;
		UpdateButtons(btnName, false);

		btnName = "B_HeroDice"+j+"_1";
		UpdateButtons(btnName, false);
	}

	if(IsMainCharacter(refCharacter))
	{
		for(i=1; i<6; i++)
		{
			curCard = "card" + i;
			if(CheckAttribute(refCharacter,"gambling."+curCard))
			{
				PlaySound("gamble_card_take");
				cardName = refCharacter.gambling.(curCard);
				switch(curCard)
				{
					case "card1": CreateImage("P_01",imageGroup, cardName,  0,405, 60,490); if(bInTavern) CreateImage("P_1","OLD_SHADOWS", cardName,  0,405, 60,490); break;
					case "card2": CreateImage("P_02",imageGroup, cardName, 75,405,135,490); if(bInTavern) CreateImage("P_2","OLD_SHADOWS", cardName, 75,405,135,490); break;
					case "card3": CreateImage("P_03",imageGroup, cardName,150,405,210,490); if(bInTavern) CreateImage("P_3","OLD_SHADOWS", cardName,150,405,210,490); break;
					case "card4": CreateImage("P_04",imageGroup, cardName,225,405,285,490); if(bInTavern) CreateImage("P_4","OLD_SHADOWS", cardName,225,405,285,490); break;
					case "card5": CreateImage("P_05",imageGroup, cardName,300,405,360,490); if(bInTavern) CreateImage("P_5","OLD_SHADOWS", cardName,300,405,360,490); break;
				}
			}
		}
	}
	else
	{
		bool allShow = false;
		int x, y;
		if(ValidateCombination(gambleChar)>=4)
		{
			if(ValidateCombination(gambleChar)!=7) allShow = true;
		}
		else allShow = false;
		for(j=1; j<6; j++)
		{
			bool bVisible = false;
			curCard = "card" + j;
			cardName = "";
			string ourCard = "blank";
			if(CheckAttribute(gambleChar,"gambling."+curCard))
			{
				PlaySound("gamble_card_take");
				cardName = gambleChar.gambling.(curCard);
				cardFace = GetCardName(cardName);
				if(allShow || GetCardsAmount(gambleChar, cardFace)>1) { x = 180; y = 265; ourCard = cardName; bVisible = true; }
				else { x = 145; y = 230; ourCard = "blank"; bVisible = false; }
				switch(curCard)
				{
					case "card1": CreateImage("G_01",imageGroup, ourCard,  0,x, 60,y); if(bInTavern && bVisible) CreateImage("G_1","OLD_SHADOWS", cardName,  0,x, 60,y); break;
					case "card2": CreateImage("G_02",imageGroup, ourCard, 75,x,135,y); if(bInTavern && bVisible) CreateImage("G_2","OLD_SHADOWS", cardName, 75,x,135,y); break;
					case "card3": CreateImage("G_03",imageGroup, ourCard,150,x,210,y); if(bInTavern && bVisible) CreateImage("G_3","OLD_SHADOWS", cardName,150,x,210,y); break;
					case "card4": CreateImage("G_04",imageGroup, ourCard,225,x,285,y); if(bInTavern && bVisible) CreateImage("G_4","OLD_SHADOWS", cardName,225,x,285,y); break;
					case "card5": CreateImage("G_05",imageGroup, ourCard,300,x,360,y); if(bInTavern && bVisible) CreateImage("G_5","OLD_SHADOWS", cardName,300,x,360,y); break;
				}
			}
		}
	}
}

void CardChange(ref refCharacter, string curCard)// changing cards for "Poker" (left out - in game)
{
	if(curCard=="") return;
	string cardName = "";
	string ourCard = "";
	string slotNum, btnName, cardFace;
	PlaySound("gamble_card_take");
	switch(sti(refCharacter.index))
	{
		case 0:// player section
			ourCard = strcut(curCard,0,strlen(curCard)-3);
			for(int i=1; i<6; i++)
			{
				btnName = "B_HeroDice"+i;
				UpdateButtons(btnName, GetClickable(btnName));

				btnName = "B_HeroDice"+i+"_1";
				UpdateButtons(btnName, GetClickable(btnName));
			}

			if(CheckAttribute(refCharacter,"gambling."+curCard))
			{
				cardName = refCharacter.gambling.(curCard);
				switch(curCard)
				{
					case "card1": CreateImage("P_01",imageGroup, cardName,  0,405, 60,490); if(bInTavern) CreateImage("P_1","OLD_SHADOWS", cardName,  0,405, 60,490); break;
					case "card2": CreateImage("P_02",imageGroup, cardName, 75,405,135,490); if(bInTavern) CreateImage("P_2","OLD_SHADOWS", cardName, 75,405,135,490); break;
					case "card3": CreateImage("P_03",imageGroup, cardName,150,405,210,490); if(bInTavern) CreateImage("P_3","OLD_SHADOWS", cardName,150,405,210,490); break;
					case "card4": CreateImage("P_04",imageGroup, cardName,225,405,285,490); if(bInTavern) CreateImage("P_4","OLD_SHADOWS", cardName,225,405,285,490); break;
					case "card5": CreateImage("P_05",imageGroup, cardName,300,405,360,490); if(bInTavern) CreateImage("P_5","OLD_SHADOWS", cardName,300,405,360,490); break;
				}
			}
			else
			{
				if(CheckAttribute(refCharacter,"gambling.stored."+curCard))
				{
					cardName = UpdateCardIn(refCharacter, curCard);
					switch(curCard)
					{
						case "card1": CreateImage("P_01",imageGroup, cardName,  0,405, 60,490); if(bInTavern) CreateImage("P_1","OLD_SHADOWS", cardName,  0,405, 60,490); break;
						case "card2": CreateImage("P_02",imageGroup, cardName, 75,405,135,490); if(bInTavern) CreateImage("P_2","OLD_SHADOWS", cardName, 75,405,135,490); break;
						case "card3": CreateImage("P_03",imageGroup, cardName,150,405,210,490); if(bInTavern) CreateImage("P_3","OLD_SHADOWS", cardName,150,405,210,490); break;
						case "card4": CreateImage("P_04",imageGroup, cardName,225,405,285,490); if(bInTavern) CreateImage("P_4","OLD_SHADOWS", cardName,225,405,285,490); break;
						case "card5": CreateImage("P_05",imageGroup, cardName,300,405,360,490); if(bInTavern) CreateImage("P_5","OLD_SHADOWS", cardName,300,405,360,490); break;
					}
				}
			}

			if(CheckAttribute(refCharacter,"gambling."+ourCard))
			{
				cardName = refCharacter.gambling.(ourCard);
				UpdateCardOut(refCharacter, ourCard);
				switch(curCard)
				{
					case "card1_1": CreateImage("P_01",imageGroup, cardName,  0,370, 60,455); if(bInTavern) CreateImage("P_1","OLD_SHADOWS", cardName,  0,370, 60,455); break;
					case "card2_1": CreateImage("P_02",imageGroup, cardName, 75,370,135,455); if(bInTavern) CreateImage("P_2","OLD_SHADOWS", cardName, 75,370,135,455); break;
					case "card3_1": CreateImage("P_03",imageGroup, cardName,150,370,210,455); if(bInTavern) CreateImage("P_3","OLD_SHADOWS", cardName,150,370,210,455); break;
					case "card4_1": CreateImage("P_04",imageGroup, cardName,225,370,285,455); if(bInTavern) CreateImage("P_4","OLD_SHADOWS", cardName,225,370,285,455); break;
					case "card5_1": CreateImage("P_05",imageGroup, cardName,300,370,360,455); if(bInTavern) CreateImage("P_5","OLD_SHADOWS", cardName,300,370,360,455); break;
				}
			}
		break;

		// gambler section [default]
		switch(curCard)
		{
			case "card1": CreateImage("G_01",imageGroup, "blank",  0,145, 60,230); break;
			case "card2": CreateImage("G_02",imageGroup, "blank", 75,145,135,230); break;
			case "card3": CreateImage("G_03",imageGroup, "blank",150,145,210,230); break;
			case "card4": CreateImage("G_04",imageGroup, "blank",225,145,285,230); break;
			case "card5": CreateImage("G_05",imageGroup, "blank",300,145,360,230); break;
		}

		if(!CheckAttribute(refCharacter,"gambling.stored."+curCard))
		{
			switch(curCard)
			{
				case "card1": CreateImage("G_01",imageGroup, "blank",  0,145, 60,230); break;
				case "card2": CreateImage("G_02",imageGroup, "blank", 75,145,135,230); break;
				case "card3": CreateImage("G_03",imageGroup, "blank",150,145,210,230); break;
				case "card4": CreateImage("G_04",imageGroup, "blank",225,145,285,230); break;
				case "card5": CreateImage("G_05",imageGroup, "blank",300,145,360,230); break;
			}
		}
		else
		{
			switch(curCard)
			{
				case "card1": CreateImage("G_01",imageGroup, "blank",  0,180, 60,265); break;
				case "card2": CreateImage("G_02",imageGroup, "blank", 75,180,135,265); break;
				case "card3": CreateImage("G_03",imageGroup, "blank",150,180,210,265); break;
				case "card4": CreateImage("G_04",imageGroup, "blank",225,180,285,265); break;
				case "card5": CreateImage("G_05",imageGroup, "blank",300,180,360,265); break;
			}
		}
	}
}

void AutoUpdateOut(ref refCharacter, string curCard)// updates cards status for computer (left out or not)
{
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

void UpdateCardOut(ref refCharacter, string curCard)// updates cards status for player (left out or not)
{
	string cardName = refCharacter.gambling.(curCard);
	refCharacter.gambling.stored.(curCard) = cardName;
	string slotNum = strcut(curCard,strlen(curCard)-1,strlen(curCard)-1);
	refCharacter.gambling.freeslot.(slotNum) = sti(slotNum);
	string cardFace = GetCardName(cardName);
	refCharacter.gambling.(cardFace) = sti(refCharacter.gambling.(cardFace)) - 1;
	DeleteAttribute(refCharacter,"gambling."+curCard);
}

string UpdateCardIn(ref refCharacter, string curCard)// updates cards status for player (left out or not) and returns card name
{
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
	SetClickable(btnName, bEnable);
}

void ProcessGiveCards(ref refCharacter, int cardNum, string cardName)// deals cards
{
	if(cardNum==0) return;
	GameName = strcut(GameInterface.title,5,strlen(GameInterface.title)-1);

	string curCard = "card" + cardNum;
	//Fix to make ace be 1 or 11 - Levis 11-10-2013 
	int CardValue = GetCardValue(cardName);
	//begin add
	if(CardValue==11) refCharacter.cards.aces = sti(refCharacter.cards.aces) + 1;
	//end add
	refCharacter.cards.value = sti(refCharacter.cards.value) + CardValue;
	//begin add
	if(GameName=="BlackJack")
	{
		//Check if the value is larger then 21 and if so see if we have any aces
		if(refCharacter.cards.value>21 && refCharacter.cards.aces>0)
		{
			//Substract 10 point from the value and count 1 less ace cause now it counts as 1
			refCharacter.cards.value = sti(refCharacter.cards.value) - 10;
			refCharacter.cards.aces = sti(refCharacter.cards.aces) - 1;
		}
	}
	//End add
	//End fix
	string cardFace = "";

	switch(sti(refCharacter.index))
	{
		case 0:// player section
			playerChar.gambling.(curCard) = cardName;
			switch(GameName)
			{
				case "BlackJack":
					switch(cardNum)
					{
						case 1: CreateImage("P_01",imageGroup, cardName,  0,405, 60,490); if(bInTavern) CreateImage("P_1","OLD_SHADOWS", cardName,  0,405, 60,490); break;
						case 2: CreateImage("P_02",imageGroup, cardName, 75,405,135,490); if(bInTavern) CreateImage("P_2","OLD_SHADOWS", cardName, 75,405,135,490); break;
						case 3: CreateImage("P_03",imageGroup, cardName,150,405,210,490); if(bInTavern) CreateImage("P_3","OLD_SHADOWS", cardName,150,405,210,490); break;
						case 4: CreateImage("P_04",imageGroup, cardName,225,405,285,490); if(bInTavern) CreateImage("P_4","OLD_SHADOWS", cardName,225,405,285,490); break;
						case 5: CreateImage("P_05",imageGroup, cardName,300,405,360,490); if(bInTavern) CreateImage("P_5","OLD_SHADOWS", cardName,300,405,360,490); break;
					}
				break;

				case "Poker":
					if(bNewGame)
					{
						switch(cardNum)
						{
							case 1: CreateImage("P_01",imageGroup, cardName,  0,405, 60,490); if(bInTavern) CreateImage("P_1","OLD_SHADOWS", cardName,  0,405, 60,490); break;
							case 2: CreateImage("P_02",imageGroup, cardName, 75,405,135,490); if(bInTavern) CreateImage("P_2","OLD_SHADOWS", cardName, 75,405,135,490); break;
							case 3: CreateImage("P_03",imageGroup, cardName,150,405,210,490); if(bInTavern) CreateImage("P_3","OLD_SHADOWS", cardName,150,405,210,490); break;
							case 4: CreateImage("P_04",imageGroup, cardName,225,405,285,490); if(bInTavern) CreateImage("P_4","OLD_SHADOWS", cardName,225,405,285,490); break;
							case 5: CreateImage("P_05",imageGroup, cardName,300,405,360,490); if(bInTavern) CreateImage("P_5","OLD_SHADOWS", cardName,300,405,360,490); break;
						}
					}
					else
					{
						switch(cardNum)
						{
							case 1: CreateImage("P_01",imageGroup, "blank",  0,370, 60,455); if(bInTavern) CreateImage("P_1","OLD_SHADOWS", "",  0,370, 60,455); break;
							case 2: CreateImage("P_02",imageGroup, "blank", 75,370,135,455); if(bInTavern) CreateImage("P_2","OLD_SHADOWS", "", 75,370,135,455); break;
							case 3: CreateImage("P_03",imageGroup, "blank",150,370,210,455); if(bInTavern) CreateImage("P_3","OLD_SHADOWS", "",150,370,210,455); break;
							case 4: CreateImage("P_04",imageGroup, "blank",225,370,285,455); if(bInTavern) CreateImage("P_4","OLD_SHADOWS", "",225,370,285,455); break;
							case 5: CreateImage("P_05",imageGroup, "blank",300,370,360,455); if(bInTavern) CreateImage("P_5","OLD_SHADOWS", "",300,370,360,455); break;
						}
					}
				break;

				case "Dumb":
				break;

//				case "Dice":
//				break;
			}
		break;

		// gambler section [default]
		gambleChar.gambling.(curCard) = cardName;
		if(GameName!="Dice")
		{
			switch(cardNum)
			{
				case 1: CreateImage("G_01",imageGroup, "blank",0,145,60,230); break;
				case 2: CreateImage("G_02",imageGroup, "blank",75,145,135,230); break;
				case 3: CreateImage("G_03",imageGroup, "blank",150,145,210,230); break;
				case 4: CreateImage("G_04",imageGroup, "blank",225,145,285,230); break;
				case 5: CreateImage("G_05",imageGroup, "blank",300,145,360,230); break;
			}
		}
	}
	playerChar.cards.(cardName) = cardName;
	if(GameName!="Dice")
	{
		Cards[CardIndexFromId(cardName)].ingame = true;
		cardFace = GetCardName(cardName);
		refCharacter.gambling.(cardFace) = sti(refCharacter.gambling.(cardFace)) + 1;
	}
}

string ShuffleCards()// alternative way for creating cards-list
{
	string card = "";
	string tmpPack = "";
	string newPack = "";
	string cardsPack = "";
	int i;

	for(i=0; i<CardsAmount; i++)
	{
		cardsPack = StoreString(cardsPack, Cards[i].id);
	}

	for(i=0; i<CardsAmount; i++)
	{
		card = GetRandSubString(cardsPack);
		tmpPack = StoreString(tmpPack, card);
		cardsPack = RemoveFromString(cardsPack, card);
	}

	for(i=0; i<CardsAmount; i++)
	{
		card = GetRandSubString(tmpPack);
		newPack = StoreString(newPack, card);
		tmpPack = RemoveFromString(tmpPack, card);
	}

	return newPack;
}

string GetPlayableCard()// returns cards-pictures names (from pictures.ini)
{//===================| maybe someone can find a better way for this function, I can't |===================//
	string cardName = GetRandSubString(cardNames);
	cardNames = RemoveFromString(cardNames, cardName);// looks like a better way, which I can find
/*	string tmpString1, tmpString2;

	if(strlen(GetSubString(cardNames,cardName,0))+strlen(cardName+",")>=strlen(cardNames))
	{
		if(strlen(GetSubString(cardNames,cardName,0))==strlen(cardNames)) tmpString1 = strcut(cardNames,strlen(cardName+","),strlen(cardNames)-1);
		else
		{
			if(strcut(GetSubString(cardNames,cardName,0),strlen(GetSubString(cardNames,cardName,0))-1,strlen(GetSubString(cardNames,cardName,0))-1))==",") tmpString1 = strleft(GetSubString(cardNames,cardName,0),strlen(GetSubString(cardNames,cardName,0))-1);
			else tmpString1 = strcut(GetSubString(cardNames,cardName,0),0,strlen(GetSubString(cardNames,cardName,0))-1));
		}
		tmpString2 = "";
	}
	else
	{
		tmpString1 = GetSubString(cardNames,cardName,0);
		if(strcut(strcut(cardNames,strlen(tmpString1)+strlen(cardName+","),strlen(cardNames)-1),strlen(strcut(cardNames,strlen(tmpString1)+strlen(cardName+","),strlen(cardNames)-1))-1,strlen(strcut(cardNames,strlen(tmpString1)+strlen(cardName+","),strlen(cardNames)-1))-1)==",") tmpString2 = strcut(cardNames,strlen(tmpString1)+strlen(cardName+","),strlen(cardNames)-2);
		else tmpString2 = strcut(cardNames,strlen(tmpString1)+strlen(cardName+","),strlen(cardNames)-1);
	}

	cardNames = tmpString1 + tmpString2;
	if(strcut(cardNames,strlen(cardNames)-1,strlen(cardNames)-1)==",")
	{
		cardNames = strleft(cardNames,strlen(cardNames)-1);
	}*///MAXIMUS: if new code not makes troubles, commented section can be deleted
	return cardName;
}

string GetCardsCombination(ref refCharacter)// returns cards combinations ("Pair", "Straight", "Royal Flash", etc.)
{
	int i;
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
						if(bFlush) cardsCombination = "Royal Flush";
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

	return cardsCombination;
}

int GetCardsAmount(ref refCharacter, string cardFace)// returns amount of identical cards
{
	int curAmount = 1;
	if(CheckAttribute(refCharacter,"gambling."+cardFace)) curAmount = makeint(refCharacter.gambling.(cardFace));
	return curAmount;
}

string GetCardColour(string cardName)// returns cards colour ("spades", "hearts", and etc.)
{
	string curColour = "";
	for(int n=0; n<CardsAmount; n++)
	{
		if(cardName==Cards[n].id) curColour = Cards[n].colour;
	}
	return curColour;
}

string GetCardName(string cardName)// returns cards names ("A", "K", "Q", and etc.)
{
	string curName = "blank";
	for(int n=0; n<CardsAmount; n++)
	{
		if(cardName==Cards[n].id) curName = Cards[n].face;
	}
	return curName;
}

int GetCardFaceId(string cardName)// returns cards identifier (from 0 to 12)
{
	int curCardNum = -1;
	for(int n=0; n<CardsAmount; n++)
	{
		if(cardName==Cards[n].id) curCardNum = Cards[n].faceId;
	}
	return curCardNum;
}

string GetCardPlayName(string cardName)// returns cards names for translation ("card_queen", "card_king", "card_ace", and etc.)
{
	string curCardName = "";
	for(int n=0; n<CardsAmount; n++)
	{
		if(cardName==Cards[n].id) curCardName = Cards[n].name;
	}
	return curCardName;
}

int GetMostCard(ref refCharacter)// returns a biggest identifier (from 0 to 12)
{
	int mostCard = 0;
	int tmpMost = 0;
	for(int i=1; i<6; i++)
	{
		string curCard = "card" + i;
		string cardName = "";
		if(CheckAttribute(refCharacter,"gambling."+curCard))
		{
			cardName = refCharacter.gambling.(curCard);
			string cardFace = GetCardName(cardName);
			if(GetCardsAmount(refCharacter, cardFace)>=2)
			{
				tmpMost = GetCardFaceId(cardName);
				if(mostCard==0) mostCard = tmpMost;
				else
				{
					if(tmpMost>mostCard) mostCard = tmpMost;
				}
				refCharacter.gambling.most = GetCardPlayName(cardName);
			}
		}
	}
	return mostCard;
}

int GetCardValue(string cardName)// returns cards value ("9", "10", "11", and etc.)
{
	int curCardNum = 0;
	for(int n=0; n<CardsAmount; n++)
	{
		if(cardName==Cards[n].id) curCardNum = Cards[n].value;
	}
	return curCardNum;
}

int GetCardsOnHand(ref refPlayer)// returns cards amount of current gambler (from 1 to 5)
{
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
				if(IsMainCharacter(refCharacter))
				{
					PlaySound("gamble_card_take");
					switch(j)
					{
						case 1: CreateImage("LEFT_06",imageGroup, "left_1", 285,269,360,364); break;
						case 2: CreateImage("LEFT_07",imageGroup, "left_2", 290,269,365,364); break;
						case 3: CreateImage("LEFT_08",imageGroup, "left_3", 293,269,394,369); break;
						case 4: CreateImage("LEFT_09",imageGroup, "left_4", 295,269,374,365); break;
						case 5: CreateImage("LEFT_10",imageGroup, "left_5", 297,269,392,369); break;
					}
				}
				else
				{
					switch(j)
					{
						case 1: CreateImage("LEFT_01",imageGroup, "left_6", 280,269,343,357); break;
						case 2: CreateImage("LEFT_02",imageGroup, "left_7", 270,269,356,325); break;
						case 3: CreateImage("LEFT_03",imageGroup, "left_8", 275,274,361,330); break;
						case 4: CreateImage("LEFT_04",imageGroup, "left_9", 260,250,355,330); break;
						case 5: CreateImage("LEFT_05",imageGroup, "left_10",270,255,374,348); break;
					}
				}

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
					case "BlackJack":
						if(bGambleMove)
						{
							bPlayerMove = false;
							if(sti(gambleChar.cards.value)>=sti(playerChar.cards.value)) AddOneCard(0, gambleChar);
							else { if(GetCardsOnHand(gambleChar)<5) AddOneCard(GetCardsOnHand(gambleChar)+1, gambleChar); }
						}
					break;
					case "Poker":
						if(bGambleMove)
						{
							if(bStart)
							{
								bStart = false;
								if(ValidateCombination(gambleChar)>=4)
								{
									if(ValidateCombination(playerChar)!=7)
									{
										bFirst = false;
										bPlayerMove = false;
										bGambleMove = false;
										UpdateTable();
										return;
									}
								}
								if(GetCardsOnHand(gambleChar)<=5)
								{
									for(c=1; c<6; c++)
									{
										curCard = "card" + c;
										cardName = "";
										if(CheckAttribute(gambleChar,"gambling."+curCard))
										{
											cardName = gambleChar.gambling.(curCard);
											string cardFace = GetCardName(cardName);
											if(GetCardsAmount(gambleChar, cardFace)<=1)
											{
												AutoUpdateOut(gambleChar, curCard);
											}
										}
									}
								}
							}
							else
							{
								bFirst = false;
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
					case "BlackJack":
						if(bPlayerMove)
						{
							bFirst = false;
							if(GetCardsOnHand(playerChar)<5) AddOneCard(GetCardsOnHand(playerChar)+1, playerChar);
						}
					break;
					case "Poker":
						if(bPlayerMove)
						{
							if(bStart)
							{
								bStart = false;
								if(GetCardsOnHand(playerChar)<=5) SetCardsToHandByNum(playerChar);
							}
							else
							{
								bStart = true;
								bFirst = false;
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
			if(bNewGame)
			{
				if(gameBet==100)
				{
					if(makeint(playerChar.money)>=gameBet)
					{
						PlaySound("gamble_give_money");
						switch(Rand(3))
						{
							case 0: CreateImage("BET_1",imageGroup, "silver",30,280,90,340); break;
							case 1: CreateImage("BET_1",imageGroup, "silver",85,275,145,335); break;
							case 2: CreateImage("BET_1",imageGroup, "silver",60,250,120,310); break;
							case 3: CreateImage("BET_1",imageGroup, "silver",30,280,90,340); break;
						}
						infoText = LanguageConvertString(tmpLangFileID,"GambleBetMin");
						SetFormatedText("INFO_TEXT", infoText);

						switch(gameName)
						{
							case "BlackJack": StartGame(); break;
							case "Poker": StartGame(); break;
							case "Dumb": StartGame(); break;
							case "Dice": StartGame(); break;
						}
					}
					else
					{
						infoText = LanguageConvertString(tmpLangFileID,"NoGambleMoney");
						SetFormatedText("INFO_TEXT", infoText);
					}
				}
				else
				{
					gameBet = makeint(gameBet);
					switch(gameName)
					{
						case "BlackJack": StartGame(); break;
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
				PlaySound("gamble_give_money");
				gameBet = 0;
				SetGame(GameName);
			}
		}
	}
	
	bool bClick;
	if(GetCardsOnHand(playerChar)<5) bClick = true;
	if(ValidateCombination(playerChar)>=4)
	{
		if(ValidateCombination(playerChar)!=7) bClick = true;
		else bClick = false;
	}

	if(nodName=="B_HeroDice1")
	{ 
		if(comName=="activate" || comName=="click")
		{
			SetClickable("B_HeroDice1",false);
			SetClickable("B_HeroDice1_1",true);
			CardChange(playerChar, "card1_1");
			SetSelectable("MYFACE",true);
		}
	}

	if(nodName=="B_HeroDice1_1")
	{ 
		if(comName=="activate" || comName=="click")
		{
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
			SetClickable("B_HeroDice2",false);
			SetClickable("B_HeroDice2_1",true);
			CardChange(playerChar, "card2_1");
			SetSelectable("MYFACE",true);
		}
	}

	if(nodName=="B_HeroDice2_1")
	{ 
		if(comName=="activate" || comName=="click")
		{
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
			SetClickable("B_HeroDice3",false);
			SetClickable("B_HeroDice3_1",true);
			CardChange(playerChar, "card3_1");
			SetSelectable("MYFACE",true);
		}
	}

	if(nodName=="B_HeroDice3_1")
	{ 
		if(comName=="activate" || comName=="click")
		{
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
			SetClickable("B_HeroDice4",false);
			SetClickable("B_HeroDice4_1",true);
			CardChange(playerChar, "card4_1");
			SetSelectable("MYFACE",true);
		}
	}

	if(nodName=="B_HeroDice4_1")
	{ 
		if(comName=="activate" || comName=="click")
		{
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
			SetClickable("B_HeroDice5",false);
			SetClickable("B_HeroDice5_1",true);
			CardChange(playerChar, "card5_1");
			SetSelectable("MYFACE",true);
		}
	}

	if(nodName=="B_HeroDice5_1")
	{ 
		if(comName=="activate" || comName=="click")
		{
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
			infoText = DLG_TEXT[117];
			VewGamble(infoText);
			gameBet = 100;
			UpdateStuff();
			if(bPlayerMove==true && dupfail==false) DoubleUp(); //Levis allow doubleup
		}
	}

	if(nodName=="BET_2")
	{ 
		if(comName=="activate" || comName=="click")
		{
			infoText = DLG_TEXT[117];
			VewGamble(infoText);
			gameBet = 200;
			UpdateStuff();
			if(bPlayerMove==true && dupfail==false) DoubleUp(); //Levis allow doubleup
		}
	}

	if(nodName=="BET_3")
	{ 
		if(comName=="activate" || comName=="click")
		{
			infoText = DLG_TEXT[117];
			VewGamble(infoText);
			gameBet = 500;
			UpdateStuff();
			if(bPlayerMove==true && dupfail==false) DoubleUp(); //Levis allow doubleup
		}
	}

	if(nodName=="BET_4")
	{ 
		if(comName=="activate" || comName=="click")
		{
			infoText = DLG_TEXT[117];
			VewGamble(infoText);
			gameBet = 1000;
			UpdateStuff();
			if(bPlayerMove==true && dupfail==false) DoubleUp(); //Levis allow doubleup
		}
	}

	if(nodName=="BET_5")
	{ 
		if(comName=="activate" || comName=="click")
		{
			infoText = DLG_TEXT[117];
			VewGamble(infoText);
			gameBet = 2000;
			UpdateStuff();
			if(bPlayerMove==true && dupfail==false) DoubleUp(); //Levis allow doubleup
		}
	}
	
	// Gamble Perk -->
	if(nodName=="BET_6")
	{ 
		if(comName=="activate" || comName=="click")
		{
			infoText = DLG_TEXT[117];
			VewGamble(infoText);
			gameBet = 5000;
			UpdateStuff();
			if(bPlayerMove==true && dupfail==false) DoubleUp(); //Levis allow doubleup
		}
	}
	// <--- Gamble Perk
	LanguageCloseFile(tmpLangFileID);
}

//Levis allow doubleup -->
void DoubleUp()
{
	int l;
	string btnName;
	dupdone = true;
	for(l=1; l<7; l++) //changed to 7 for gamble perk
	{
		btnName = "BET_"+l;
		SetSelectable(btnName,false);
	}
	infoText = DLG_TEXT[116];
	VewGamble(infoText);
	AddOneCard(GetCardsOnHand(playerChar)+1, playerChar);
	bPlayerMove = false;
	bGambleMove = true;
	SetNodeUsing("ENFACE",true);
}
//Levis allow doubleup <--

void ProcessCancelExit()
{
	if(bNewGame)
	{
		SetNodeUsing("CONFIRM_RECTANGLE",true);
		SetNodeUsing("TEXTWINDOW",true);
		SetNodeUsing("CONFIRM_YES_BUTTON",true);
		SetNodeUsing("CONFIRM_NO_BUTTON",true);
		SetNodeUsing("CARD_PIC",true);
		int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
		SetCurrentNode("CONFIRM_NO_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 1, "CONFIRM_NO_BUTTON");
		SendMessage(&GameInterface,"lls", MSG_INTERFACE_LOCK_NODE, 2, "CONFIRM_YES_BUTTON");

		SetFormatedText("TEXTWINDOW",LanguageConvertString(tmpLangFileID,"Exit from gamble confirm"));
		LanguageCloseFile(tmpLangFileID);
	}
}

void ProcessExit_no()
{
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
	ProcessExit();
}

void ProcessExit()
{
	ref playerChar = GetMainCharacter();
	ref gambleChar = characterFromID(gambleID);
	bool bInTavern;

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
	
	if(gambleChar.Dialog.Filename=="Habitue_dialog.c")
	{
		LAi_SetActorType(playerChar);
		LAi_ActorAnimation(playerChar, "Sit_Look_Around","exit_sit", 1);

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

	DeleteAttribute(playerChar,"gamepoints");
	DeleteAttribute(playerChar,"gambling");
	DeleteAttribute(playerChar,"cards");

	DeleteAttribute(gambleChar,"gamepoints");
	DeleteAttribute(gambleChar,"gambling");
	DeleteAttribute(gambleChar,"cards");
}

void InitCards()
{
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
		card.trump = false;
		card.ingame = false;
	}
	n = 0;

	makeref(card,Cards[n]);
	card.id = "clubs_6";
	card.face = "6";
	card.faceId = "4";
	card.name = "card_six";
	card.value = "6";
	card.colour = "clubs";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_6";
	card.face = "6";
	card.faceId = "4";
	card.name = "card_six";
	card.value = "6";
	card.colour = "hearts";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_6";
	card.face = "6";
	card.faceId = "4";
	card.name = "card_six";
	card.value = "6";
	card.colour = "spades";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_6";
	card.face = "6";
	card.faceId = "4";
	card.name = "card_six";
	card.value = "6";
	card.colour = "diamonds";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_7";
	card.face = "7";
	card.faceId = "5";
	card.name = "card_seven";
	card.value = "7";
	card.colour = "clubs";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_7";
	card.face = "7";
	card.faceId = "5";
	card.name = "card_seven";
	card.value = "7";
	card.colour = "hearts";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_7";
	card.face = "7";
	card.faceId = "5";
	card.name = "card_seven";
	card.value = "7";
	card.colour = "spades";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_7";
	card.face = "7";
	card.faceId = "5";
	card.name = "card_seven";
	card.value = "7";
	card.colour = "diamonds";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_8";
	card.face = "8";
	card.faceId = "6";
	card.name = "card_eight";
	card.value = "8";
	card.colour = "clubs";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_8";
	card.face = "8";
	card.faceId = "6";
	card.name = "card_eight";
	card.value = "8";
	card.colour = "hearts";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_8";
	card.face = "8";
	card.faceId = "6";
	card.name = "card_eight";
	card.value = "8";
	card.colour = "spades";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_8";
	card.face = "8";
	card.faceId = "6";
	card.name = "card_eight";
	card.value = "8";
	card.colour = "diamonds";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_9";
	card.face = "9";
	card.faceId = "7";
	card.name = "card_nine";
	card.value = "9";
	card.colour = "clubs";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_9";
	card.face = "9";
	card.faceId = "7";
	card.name = "card_nine";
	card.value = "9";
	card.colour = "hearts";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_9";
	card.face = "9";
	card.faceId = "7";
	card.name = "card_nine";
	card.value = "9";
	card.colour = "spades";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_9";
	card.face = "9";
	card.faceId = "7";
	card.name = "card_nine";
	card.value = "9";
	card.colour = "diamonds";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_10";
	card.face = "10";
	card.faceId = "8";
	card.name = "card_ten";
	card.value = "10";
	card.colour = "clubs";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_10";
	card.face = "10";
	card.faceId = "8";
	card.name = "card_ten";
	card.value = "10";
	card.colour = "hearts";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_10";
	card.face = "10";
	card.faceId = "8";
	card.name = "card_ten";
	card.value = "10";
	card.colour = "spades";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_10";
	card.face = "10";
	card.faceId = "8";
	card.name = "card_ten";
	card.value = "10";
	card.colour = "diamonds";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_J";
	card.face = "J";
	card.faceId = "9";
	card.name = "card_jack";
	card.value = "10";
	card.colour = "clubs";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_J";
	card.face = "J";
	card.faceId = "9";
	card.name = "card_jack";
	card.value = "10";
	card.colour = "hearts";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_J";
	card.face = "J";
	card.faceId = "9";
	card.name = "card_jack";
	card.value = "10";
	card.colour = "spades";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_J";
	card.face = "J";
	card.faceId = "9";
	card.name = "card_jack";
	card.value = "10";
	card.colour = "diamonds";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_Q";
	card.face = "Q";
	card.faceId = "10";
	card.name = "card_queen";
	card.value = "10";
	card.colour = "clubs";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_Q";
	card.face = "Q";
	card.faceId = "10";
	card.name = "card_queen";
	card.value = "10";
	card.colour = "hearts";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_Q";
	card.face = "Q";
	card.faceId = "10";
	card.name = "card_queen";
	card.value = "10";
	card.colour = "spades";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_Q";
	card.face = "Q";
	card.faceId = "10";
	card.name = "card_queen";
	card.value = "10";
	card.colour = "diamonds";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_K";
	card.face = "K";
	card.faceId = "11";
	card.name = "card_king";
	card.value = "10";
	card.colour = "clubs";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_K";
	card.face = "K";
	card.faceId = "11";
	card.name = "card_king";
	card.value = "10";
	card.colour = "hearts";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_K";
	card.face = "K";
	card.faceId = "11";
	card.name = "card_king";
	card.value = "10";
	card.colour = "spades";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_K";
	card.face = "K";
	card.faceId = "11";
	card.name = "card_king";
	card.value = "10";
	card.colour = "diamonds";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_A";
	card.face = "A";
	card.faceId = "12";
	card.name = "card_ace";
	card.value = "11";
	card.colour = "clubs";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_A";
	card.face = "A";
	card.faceId = "12";
	card.name = "card_ace";
	card.value = "11";
	card.colour = "hearts";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_A";
	card.face = "A";
	card.faceId = "12";
	card.name = "card_ace";
	card.value = "11";
	card.colour = "spades";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_A";
	card.face = "A";
	card.faceId = "12";
	card.name = "card_ace";
	card.value = "11";
	card.colour = "diamonds";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_2";
	card.face = "2";
	card.faceId = "0";
	card.name = "card_two";
	card.value = "2";
	card.colour = "clubs";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_2";
	card.face = "2";
	card.faceId = "0";
	card.name = "card_two";
	card.value = "2";
	card.colour = "hearts";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_2";
	card.face = "2";
	card.faceId = "0";
	card.name = "card_two";
	card.value = "2";
	card.colour = "spades";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_2";
	card.face = "2";
	card.faceId = "0";
	card.name = "card_two";
	card.value = "2";
	card.colour = "diamonds";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_3";
	card.face = "3";
	card.faceId = "1";
	card.name = "card_three";
	card.value = "3";
	card.colour = "clubs";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_3";
	card.face = "3";
	card.faceId = "1";
	card.name = "card_three";
	card.value = "3";
	card.colour = "hearts";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_3";
	card.face = "3";
	card.faceId = "1";
	card.name = "card_three";
	card.value = "3";
	card.colour = "spades";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_3";
	card.face = "3";
	card.faceId = "1";
	card.name = "card_three";
	card.value = "3";
	card.colour = "diamonds";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_4";
	card.face = "4";
	card.faceId = "2";
	card.name = "card_four";
	card.value = "4";
	card.colour = "clubs";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_4";
	card.face = "4";
	card.faceId = "2";
	card.name = "card_four";
	card.value = "4";
	card.colour = "hearts";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_4";
	card.face = "4";
	card.faceId = "2";
	card.name = "card_four";
	card.value = "4";
	card.colour = "spades";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_4";
	card.face = "4";
	card.faceId = "2";
	card.name = "card_four";
	card.value = "4";
	card.colour = "diamonds";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "clubs_5";
	card.face = "5";
	card.faceId = "3";
	card.name = "card_five";
	card.value = "5";
	card.colour = "clubs";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "hearts_5";
	card.face = "5";
	card.faceId = "3";
	card.name = "card_five";
	card.value = "5";
	card.colour = "hearts";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "spades_5";
	card.face = "5";
	card.faceId = "3";
	card.name = "card_five";
	card.value = "5";
	card.colour = "spades";
	card.trump = false;
	card.ingame = false;
	n++;

	makeref(card,Cards[n]);
	card.id = "diamonds_5";
	card.face = "5";
	card.faceId = "3";
	card.name = "card_five";
	card.value = "5";
	card.colour = "diamonds";
	card.trump = false;
	card.ingame = false;
	n++;
}

int CardIndexFromId(string cardID)
{
	int n = -1;
	for(n=0; n<CardsAmount; n++)
	{
		if(Cards[n].id==cardID) break;
		return n;
	}
	return n;
}
