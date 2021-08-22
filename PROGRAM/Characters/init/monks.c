#define MONK_OXBAY		"in the town of #sOxbay#"
#define MONK_REDMOND		"at the shore of #sisland_Redmond#"
#define MONK_CONCEICAO		"near the citygates of #sisland_Conceicao#"
#define MONK_MUELLE		"on the causeway of #sisland_Isla Muelle#"
#define MONK_FLEUR		"somewhere on #sisland_Falaise de Fleur#"
#define MONK_QUEBRADAS		"on #sisland_Quebradas Costillas#"
#define MONK_DOUWESEN		"somewhere in the jungles of #sisland_Douwesen#"
#define MONK_COUNT		7


void InitNoSaveMod()
{
	ref PChar = GetMainCharacter();
	if(!CheckAttribute(PChar, "NoSave.Init"))
	{
		//Trace("Create monks");
		CreateMonk( "Kanhoji",	   "Angria",	   PreprocessText(TranslateString("", MONK_OXBAY)),     "Oxbay_town");
		CreateMonk( "Robert",	   "Surcouf",	   PreprocessText(TranslateString("", MONK_REDMOND)),   "Redmond_shore_01");
		CreateMonk( "Yusuf",	   "Rais",		   PreprocessText(TranslateString("", MONK_CONCEICAO)), "Conceicao_town_exit");
		CreateMonk( "Uela",	       "de Marisco",   PreprocessText(TranslateString("", MONK_MUELLE)),    "Muelle_passage");
		CreateMonk( "Victor",	   "Hugues",	   PreprocessText(TranslateString("", MONK_FLEUR)),     "Falaise_de_fleur_shore");
		CreateMonk( "Brother",     "Nantucket",    PreprocessText(TranslateString("", MONK_QUEBRADAS)), "QC_town_exit");       // PB
		CreateMonk( "Brother",	   "Tuck",         PreprocessText(TranslateString("", MONK_DOUWESEN)),  "Douwesen_Jungle_02"); // PB

		PChar.NoSave.Init = true;
	}
}
		 

void CreateMonk(string Firstname, string Lastname, string Town,	string Location)
{
	int i;
	ref monk;
	string Fullname = Firstname + " " + Lastname;
	i = GetCharacterIndex(Fullname);
	//Trace("start create monk " + Fullname);
	if( i == -1 )
	{
		//Trace("Create new monk");
		// NK 05-04-05 use CHARACTERS_QUANTITY
		/*for(i=0; i<MAX_CHARACTERS; i++)
		{
			makeref(tailor,Characters[i]); 
			if(tailor.id == "0") break;
		}*/
		makeref(monk, Characters[CHARACTERS_QUANTITY]);
		CHARACTERS_QUANTITY++;
		if(monk.id != "0")
		{
			//Trace("cquant not blank!");
			i = FindBlankCharSlot();
			CHARACTERS_QUANTITY = i+1;
			makeref(monk, Characters[i]);
			//Trace("new slot is " + i + ", new charq " + (i+1));
		}
		// NK <--

		monk.old.name 		   = Firstname;
		monk.old.lastname	   = Lastname;
		monk.name 			   = TranslateString("",Firstname);
		monk.lastname 		   = TranslateString("",Lastname);
		monk.id				   = Fullname;
		monk.model			   = "Animists3";
		monk.town 			   = Town;
		monk.nation			   = CLERIC;
		monk.skill.Fencing	   = 10;
		monk.skill.Sneak	   = 10;
		monk.location 		   = Location;
		monk.location.group	   = "monk"; // KK
		monk.location.locator  = "goto1"; //Ah! That's why. This only works for _current_ loc, not desired loc. NK 05-04-24 LAi_FindRandomLocator(monk.location.group);
		monk.sex			   = "man";
		monk.dialog.filename   = "monk_dialog.c";
		LAi_SetCitizenType(monk);
		LAi_group_MoveCharacter(monk, "ENGLAND_CITIZENS");
		LAi_SetLoginTime(monk, 0.0, 24.0);
		LAi_SetHP(monk, 800.0, 800.0);
		facemaker(monk);
		//Trace ("location is " + Location)
		DeleteAttribute(monk, "location.etime");
		DeleteAttribute(monk, "location.stime");
	}
}

bool IsCharacterEquipByGroup(ref chref, string groupID)
{
	return CheckAttribute(chref,"equip."+groupID);
}

string GetRandomLocation(string ThisLocation)
{
	int i;
	int breakcounter = 0;
	string Location = ThisLocation;
	while(Location == ThisLocation)
	{
		i = rand(MONK_COUNT-1);
		//Trace ("monk switch " + i)
		switch (i)
		{
			case 0: 
				Location = MONK_OXBAY;
				break;
			case 1: 
				Location = MONK_REDMOND;
				break;
			case 2: 
				Location = MONK_CONCEICAO;
				break;
			case 3: 
				Location = MONK_MUELLE;
				break;
			case 4: 
				Location = MONK_FLEUR;
				break;
			case 5: 
				Location = MONK_QUEBRADAS;
				break;
			case 6: 
				Location = MONK_DOUWESEN;
				break;
		}
		breakcounter++;
		if(breakcounter > 1000) break;
		Location = PreprocessText(TranslateString("", Location)); // PB
	}
	return Location;
}

