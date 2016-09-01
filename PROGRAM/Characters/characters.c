
#include "characters\characters_ai.c"
#include "characters\characters_events.c"
#include "characters\characters_login.c"
#include "characters\characters_face.c"
#include "characters\characters.h"
#include "characters\characterUtilite.c"

object chrFindNearCharacters[32];
bool isBoardingLoading = false;
extern void CreateCharacters(); // KK

void CharactersInit()
{
    if(LoadSegment("characters\Characters_tables.c"))
	{
		InitCharactersTables();
		UnloadSegment("characters\Characters_tables.c");
	}
	ReloadProgressUpdate();
	if(LoadSegment("characters\characters_init.c"))
	{
		CreateCharacters();
		UnloadSegment("characters\characters_init.c");
	}
	ReloadProgressUpdate();
	InitCharacterEvents();
	ReloadProgressUpdate();
	LAi_NewGame();
}

// NK make this a separate function 05-05-11
bool Character_PostInit(int n)
{
	if(n >= CHARACTERS_QUANTITY) return false;
	ref rCharacter = GetCharacter(n);

	// NK 05-03-31 check to see if we're overwriting an animation -->
	if(!CheckAttribute(rCharacter,"model.animation") || rCharacter.model.animation == "")
	{
// changed by MAXIMUS [for AOP models] -->
		if(rCharacter.sex == "woman")
		{
			if(StraifCharacter(rCharacter)) rCharacter.model.animation = "new_woman";
			else rCharacter.model.animation = "towngirl";
// KK -->
			rCharacter.model.height = WOMAN_HEIGHT;
			rCharacter.capacity.max = WOMAN_CAPACITY;
// <-- KK
		}
		else
		{
			if(StraifCharacter(rCharacter)) rCharacter.model.animation = "new_man";
			else rCharacter.model.animation = "man";
// KK -->
			rCharacter.model.height = MAN_HEIGHT;
			rCharacter.capacity.max = MAN_CAPACITY;
// <-- KK
		}
// changed by MAXIMUS [for AOP models] <--
	}
	// NK <--
	rCharacter.FaceGroup = 0;

	// set fellows
	if (CheckAttribute(rCharacter,"fellows")) { SetBaseFellows(rCharacter); }
	// set base ship data
//	SetBaseShipData(rCharacter); // PB: This is already taken care of by the CheckCharacterSetup function now

	facemaker(rCharacter); // NK

	//rCharacter.headModel = "h_" + rCharacter.model; // NK called by above, unneeded (4-30)
	if(CheckAttribute(rCharacter,"blade"))
	{
		if(CheckAttribute(rCharacter,"blade.itemID"))
		{
			rCharacter.equip.blade = rCharacter.blade.itemID;
		}
		else
		{
			rCharacter.equip.blade = "blade4";
		}
		DeleteAttribute(rCharacter,"blade");
	}
	if(CheckAttribute(rCharacter,"gun"))
	{
		if(CheckAttribute(rCharacter,"gun.itemID"))
		{
			rCharacter.equip.gun = rCharacter.gun.itemID;
		}
		else
		{
			rCharacter.equip.gun = "pistol1";
		}
		DeleteAttribute(rCharacter,"gun");
	}
	if(CheckAttribute(rCharacter,"spyglass.itemID"))
	{
		rCharacter.equip.spyglass = rCharacter.spyglass.itemID;
		DeleteAttribute(rCharacter,"spyglass");
	}
	// NK equip all items 05-03-31 -->
	EquipCharacterByItem(rCharacter, FindCharacterItemByGroup(rCharacter,BLADE_ITEM_TYPE));
	EquipCharacterByItem(rCharacter, FindCharacterItemByGroup(rCharacter,GUN_ITEM_TYPE));
	EquipCharacterByItem(rCharacter, FindCharacterItemByGroup(rCharacter,ARMOR_ITEM_TYPE));
	// NK <--
	return true;
}
// NK <--

bool CreateCharacter(ref character)
{
// KK -->
	if (IsUsedAlliesModel(character) == true && CheckAttribute(character, "IsFantom") == true && sti(character.IsFantom) == true && LAi_IsBoardingProcess() == false && ownDeckStarted() == false) {
		//MAXIMUS: for excluding player's allies twins (with some reservations for constant characters[quest-characters or enemy-captains, for example])
		return false;
	}
// <-- KK
	// NK bugfix 05-06-28 for chars who miss postinit.
	if(!CheckAttribute(character, "model.animation") || character.model.animation == "" || !CheckAttribute(character, "model.height"))
	{
		/*if(character.sex == "man")
		{
			character.model.animation = "man";
			character.model.height = 1.8;
		}else{
			character.model.animation = "woman"; // was towngirl. No real difference, IIRC.
			character.model.height = 1.75;
		}*/
		//Assume no postinit done.
		Character_PostInit(sti(character.index));
	}
	if(!CreateEntity(&character, character.model.entity)) return false;
// KK -->
	if(!SendMessage(character, "lss", MSG_CHARACTER_SETMODEL, character.model, character.model.animation))
	{
		trace("CreateCharacter -> character " + character.id + " can invalide model("+ character.model +") or animation(" + character.model.animation + ")");
		DeleteCharacter(character);
		return false;
	}
// <-- KK

	ExecuteCharacterEquip(character);
	if (!CheckAttribute(character,"completeinit") && !AllowCharacterPostInit()) 
	{
		//These are characters which are created after loading is done. To increase performance we are going to add them to the post init too if the queue isn't too large
		if(GetAmountInPostInitQueue() < 5) //No idea why I picked 5, but sounds good to me.
		{
			SetCharacterPostInit(true);
			InitCharacterSkills(character); //Levis
			SetCharacterPostInit(false);
			if(!PostInitActive) StartPostInitChars();
		}
		else
		{
			InitCharacterSkills(character); //Levis
		}
	}
	//Set fight level
	float fgtlevel = 0.0;
	if(isBoardingLoading == false)
	{
		fgtlevel = CalcCharacterSkill(character, SKILL_FENCING);
	}else{
		fgtlevel = GetShipSkill(character, SKILL_FENCING);
	}
	if(fgtlevel < 0.0) fgtlevel = 0.0;
	if(fgtlevel > SKILL_MAX) fgtlevel = SKILL_MAX;
	fgtlevel = fgtlevel/SKILL_MAX;
	SendMessage(character, "lf", MSG_CHARACTER_SETFTGLEVEL, fgtlevel);
	//Set character sex
	SendMessage(character, "lsl", MSG_CHARACTER_EX_MSG, "SetSex", character.sex == "man");
	//
// changed by MAXIMUS -->
	if(bAbordageStarted) AddCharacterLocatorGroup(character, "rld");
	else  AddCharacterLocatorGroup(character, "goto");
// changed by MAXIMUS <--
	BeginChangeCharacterActions(character);
	SetDefaultFight(character);
	EndChangeCharacterActions(character);
	return true;
}

bool DeleteCharacter(ref character)
{
	DeleteClass(character);
	return true;
}

// PB: Completely erase attributes -->
bool ClearCharacter(ref character)
{
	int index     = character.index;
	string id     = character.id;
//	TraceAndLog("ClearCharacter called on " + id);
	string entity = "";
	if (CheckAttribute(character, "model.entity")) entity = character.model.entity;
	DeleteClass(character);
	DeleteAttribute(character, "");
	character.index = index;
	character.id = id;
	if (entity != "") character.model.entity = entity;
	character.location = "none";
	character.location.locator = "";
	character.location.group = "";
	character.chr_ai.group = LAI_DEFAULT_GROUP;
	return true;
}
// PB: Completely erase attributes <--

bool TeleportCharacterToPos(ref character, float x, float y, float z)
{
	return SendMessage(character, "lfff", MSG_CHARACTER_TELEPORT, x, y, z);
}

bool TeleportCharacterToPosAy(ref character, float x, float y, float z, float ay)
{
	return SendMessage(character, "lffff", MSG_CHARACTER_TELEPORT_AY, x, y, z, ay);
}

bool TeleportCharacterToLocator(ref character, string group, string locator)
{
	return SendMessage(character, "lss", MSG_CHARACTER_TELEPORT_TO_LOCATOR, group, locator);
}

bool CheckLocationPosition(ref location, float x, float y, float z)
{//corrected by MAXIMUS 11.10.2007
	if(IsEntity(location) == false) return false;
	return (SendMessage(location, "lfff", MSG_LOCATION_CHECKENTRY, x, y, z) != 0);
}

object GetCharacterModel(ref character)
{
	object model;
	SendMessage(character, "le", MSG_CHARACTER_GETMODEL, &model);
	return model;
}

bool GetCharacterPos(ref character, ref float_x, ref float_y, ref float_z)
{
	float cx, cy, cz;
	if(SendMessage(character, "leee", MSG_CHARACTER_GETPOS, &cx, &cy, &cz) == 0) return false;
	float_x = cx; float_y = cy; float_z = cz;
	return true;
}

bool GetCharacterAy(ref character, ref float_ay)
{
	float ay = 0.0;
	if(SendMessage(character, "le", MSG_CHARACTER_GETAY, &ay) == 0) return false;
	float_ay = ay;
	return true;
}

// NK sidestep 04-09-17 -[corrected by MAXIMUS 11.10.2007]->
bool Sidestep(ref pchar, float mag, bool docheck)
{
	if(FindLoadedLocation() == -1) return false; //if not in loc mode, return
	ref curLocation = &locations[FindLoadedLocation()];
	float x,y,z, ay;
	GetCharacterPos(pchar, &x, &y, &z); // get pos
	GetCharacterAy(pchar, &ay); // get angle
		//Logit("Pos Before: (" + x + ", " + y + ", " + z + "), " + ay);
	ay += PId2; // rotate angle to perpendicular
	/*while(ay > PIm2) ay -= PIm2;
	while(ay < 0) ay += PIm2;*/ //unneeded, cos/sin should be fine with any angle
	z += cos(ay) * mag; // add Z component
	x += sin(ay) * mag; // add X component
	if(docheck)
	{//MAXIMUS: low mag will not be recognized, by some reason - 0.8 minimum. So I made an additional check. But CheckLocationPosition only checks target point for characters - not checks patch :(
		float chkX, chkY, chkZ, chkAY, side;
		if(mag>=0.0) side = 1;
		else side = -1;
		GetCharacterPos(&pchar, &chkX, &chkY, &chkZ);
		GetCharacterAy(&pchar, &chkAY);
		chkAY += PId2; // rotate angle to perpendicular
		chkZ += cos(chkAY) * stf(side*0.8); // add Z component
		chkX += sin(chkAY) * stf(side*0.8); // add X component
		if(CheckLocationPosition(curLocation, chkX, chkY, chkZ)==0) return false; // NK 05-07-21 add check
	}
	TeleportCharacterToPos(pchar, x, y, z); // move char
		//GetCharacterPos(pchar, &x, &y, &z);
		//Logit("Pos After: (" + x + ", " + y + ", " + z + ")");
	return true;
}
// NK <-[corrected by MAXIMUS 11.10.2007]-

bool PushCharacterAy(ref character)
{
	return SendMessage(character, "l", MSG_CHARACTER_TURNPUSH);
}

bool PopCharacterAy(ref character)
{
	return SendMessage(character, "l", MSG_CHARACTER_TURNPOP);
}

int FindNearCharacters(ref character, float rad, float ax, float testAng, float nearDist, bool isVisibleTest, bool isSort)
{
	int num = 0;
	SendMessage(character, "leeffffll", MSG_CHARACTER_FINDNEAR, &chrFindNearCharacters, &num, rad, ax, testAng, nearDist, isVisibleTest, isSort);
	return num;
}

//Levis:
int FindNearEnemies(ref chr, int radius, bool CountAllies)
{
	int num = FindNearCharacters(chr, radius, -1.0, -1.0, 0.001, false, false);
	ref findCh;
	int enemies = 0;
	for(int j = 0; j < num; j++)	// the following loop runs for each near character
	{
		int cidx = sti(chrFindNearCharacters[j].index);	// defines near character as idx
		if(cidx == chr.index) continue;
		if(cidx < 0) continue;
		findCh = &characters[cidx];
		if(LAi_group_IsEnemy(chr, findCh)) enemies += 1;
		if(CountAllies)
		{
			if(GetAttribute(chr,"chr_ai.group") == GetAttribute(findCh,"chr_ai.group")) enemies -= 1;
		}
	}
	return enemies;
}

bool CharactersVisibleTest(ref character, ref lookTo)
{
	return SendMessage(character, "li", MSG_CHARACTER_VISIBLE, lookTo);
}

//
void BeginChangeCharacterActions(ref character)
{
	DeleteAttribute(character, "actions");
}

//
void EndChangeCharacterActions(ref character)
{
	character.actions = "";
}

//Character is stay where play idle animation
void SetDefaultStayIdle(ref character)
{
	character.actions.idle.i1 = "idle_1";
	character.actions.idle.i2 = "idle_2";
	character.actions.idle.i3 = "idle_3";
	character.actions.idle.i4 = "idle_4";
	character.actions.idle.i5 = "idle_5";
	character.actions.idle.i6 = "idle_6";
	character.actions.idle.i7 = "idle_7";
	character.actions.idle.i8 = "idle_8";
	character.actions.idle.i9 = "idle_9";
	character.actions.idle.i10 = "idle_10";
}

//Character is sit where play idle animation
void SetDefaultSitIdle(ref character)
{	
	character.actions.idle.i1 = "Sit_Look_Around";
	character.actions.idle.i2 = "Sit_Lower_head";
	character.actions.idle.i3 = "Sit_WaveFly";
	character.actions.idle.i5 = "Sit_Blew_1";
	character.actions.idle.i6 = "Sit_Blew_1";
	character.actions.idle.i7 = "Sit_Blew_1";
}

void SetDefaultNormWalk(ref character)
{
// MAXIMUS: -[unlinks from character.id]->
	if(IsMainCharacter(character) && AlwaysRunToggle)
	{
		character.actions.walk = "run";
		character.actions.backwalk = "back walk";
		character.actions.run = "walk";
		character.actions.backrun = "back run";
		character.actions.stsUp = "run stairs up";
		character.actions.stsUpRun = "stairs up";
		character.actions.stsDown = "run stairs down";
		character.actions.stsDownRun = "stairs down";
	}
	else
    {
		character.actions.walk = "walk";
		character.actions.backwalk = "back walk";
		character.actions.run = "run";
		character.actions.backrun = "back run";
		character.actions.stsUp = "stairs up";
		character.actions.stsUpRun = "run stairs up";
		character.actions.stsDown = "stairs down";
		character.actions.stsDownRun = "run stairs down";
    }
// MAXIMUS: <-[unlinks from character.id]-
   
   character.actions.stsUpBack = "back stairs up";
   character.actions.stsDownBack = "back stairs down";
   
   
   character.actions.stsUpRunBack = "back run stairs up";
   character.actions.stsDownRunBack = "back run stairs down";
   character.actions.turnLeft = "turn left";
   character.actions.turnRight = "turn right";
   character.actions.swim = "swim";
   character.actions.hit = "face_hit";// MAXIMUS

	if(StraifCharacter(character))
	{
		character.actions.Sidestep_left_on = "straif_left";
		character.actions.Sidestep_right_on = "straif_right";
	}
	else
	{
		character.actions.Sidestep_left_on = "skip";
		character.actions.Sidestep_right_on = "skip";
	}
}

void SetDefaultFight(ref character)
{
// MAXIMUS: -[unlinks from character.id]->
	if(IsMainCharacter(character) && AlwaysRunToggle)
	{
		character.actions.fightwalk = "fight run";
		character.actions.fightbackwalk = "fight back run";
		character.actions.fightrun = "fight Walk";
		character.actions.fightbackrun = "fight back walk";
	}
	else
	{
		character.actions.fightwalk = "fight walk";
		character.actions.fightbackwalk = "fight back walk";
		character.actions.fightrun = "fight run";
		character.actions.fightbackrun = "fight back run";
	}
// MAXIMUS: <-[unlinks from character.id]-

	character.actions.attack.a1 = "attack_1";
	character.actions.attack.a2 = "attack_2";
	character.actions.attack.a3 = "attack_3";
	character.actions.attack.a4 = "attack_4";
	character.actions.attack.a5 = "attack_5";
	character.actions.attack.a6 = "attack_6";
	character.actions.attack.a7 = "attack_7";
	character.actions.attack.a8 = "attack_8";

	character.actions.attacktl.a1 = "attack_left_1";

	character.actions.attacktr.a1 = "attack_right_1";

	character.actions.hit.h1 = "hit_1";
	character.actions.hit.h2 = "hit_2";
	character.actions.hit.h3 = "hit_3";
	if(IsMainCharacter(character)) character.actions.hit.h4 = "face_hit";// MAXIMUS

	character.actions.block = "block";
	character.actions.blockhit = "block_hit";
	character.actions.recoil = "Recoil";
	character.actions.shot = "Shot";


	if(StraifCharacter(character))
	{
		character.actions.fightSidestep_left_on = "straif_weapon_left";
		character.actions.fightSidestep_right_on = "straif_weapon_right";
	}
	else
	{
		character.actions.fightSidestep_left_on = "skip";
		character.actions.fightSidestep_right_on = "skip";
	}

	SetDefaultFightDead(character);

	//Idle анимация в режиме боя
	character.actions.fightidle.i1 = "fight stand_1";
	character.actions.fightidle.i2 = "fight stand_2";
	character.actions.fightidle.i3 = "fight stand_3";
	character.actions.fightidle.i4 = "fight stand_4";
	if(GetAttribute(character,"model.animation")=="blaze" || GetAttribute(character,"model.animation")=="new_man") // PB: missed attribute: model ???
	{
		character.actions.fightidle.i5 = "fight stand_5";
		character.actions.fightidle.i6 = "fight stand_6";
	}

}

void SetDefaultDead(ref character)
{
	character.actions.dead.d1 = "death_citizen_1";
	character.actions.dead.d2 = "death_citizen_2";
	if(GetAttribute(character,"model.animation")=="blaze" || GetAttribute(character,"model.animation")=="new_man") // PB: missed attribute: model ???
	{
		character.actions.dead.d3 = "death_citizen_3";
		character.actions.dead.d4 = "death_citizen_4";
	}
}

void SetDefaultSitDead(ref character)
{
	character.actions.dead.d1 = "Sit_Death";
}

void SetAfraidDead(ref character)
{
	character.actions.dead.d1 = "death_afraid_1";
	character.actions.dead.d2 = "death_afraid_2";

}

void SetDefaultFightDead(ref character)
{
	character.actions.fightdead.d1 = "death_0";
	character.actions.fightdead.d2 = "death_1";
	character.actions.fightdead.d3 = "death_2";
	character.actions.fightdead.d4 = "death_3";
	if(GetAttribute(character,"model.animation")=="blaze" || GetAttribute(character,"model.animation")=="new_man") // PB: missed attribute: model ???
	{
		character.actions.fightdead.d5 = "death_4";
		character.actions.fightdead.d6 = "death_p";
	}
}

void SetHuberAnimation(ref character)
{
	character.actions.idle.i1 = "Gov_ObserveHands";
	character.actions.idle.i2 = "Gov_LegOnLeg";
	character.actions.idle.i3 = "Gov_Look_Around";
	character.actions.idle.i4 = "Gov_think_1";
	character.actions.idle.i5 = "Gov_think_2";
}

int GetMaxLandCrew(int crewQuantity)
{
   if(crewQuantity >=5)
   {
      if(crewQuantity >=10)
      {
         if(crewQuantity >=25)
         {
            if(crewQuantity >=55)
            {
               if(crewQuantity >=100)
               {
                  if(crewQuantity >=160)
                  {
                     if(crewQuantity >=235)
                     {
                        if(crewQuantity >=325)
                        {
                           if(crewQuantity >=430)
                           {
                              if(crewQuantity >=550)
                              {
                                 return 10;
                              }
                              return 9;
                           }
                           return 8;
                        }
                        return 7;
                     }
                     return 6;
                  }
                  return 5;
               }
               return 4;
            }
            return 3;
         }
         return 2;
      }
      return 1;
   }
   return 0;
}

// KK -->
void SetTownCharacterGreeting(ref curChar, int iNation)
{
	int chridx = sti(curChar.index);
	string town = GetTownIDFromLocID(curChar.location);
	switch (iNation)
	{
		case ENGLAND:
			if (Checkattribute(curChar, "greeting") && HasSubStr(curChar.greeting, "citizen")) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_English Citizen";
				else
					curChar.greeting = "Gr_Redmond Citizen";
			}
			if (GetTownShipyardOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_English Citizen";
				else
					curChar.greeting = "Gr_Roger Murray";
			}
			if (GetTownStoreOwnerIndex(town) == chridx) {
				if(curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_English Citizen";
				else
					curChar.greeting = "Gr_John Filbert";
			}
			if (GetTownTavernOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_English Citizen";
				else
					curChar.greeting = "Gr_Olyver Littlejohn";
			}
		break;
		case FRANCE:
			if (Checkattribute(curChar, "greeting") && HasSubStr(curChar.greeting, "citizen")) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_French citizen";
				else
					curChar.greeting = "Gr_falaise de fleur citizen";
			}
			if (GetTownShipyardOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_French citizen";
				else
					curChar.greeting = "Gr_jean filaut";
			}
			if (GetTownStoreOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_French citizen";
				else
					curChar.greeting = "Gr_arnaud matton";
			}
			if (GetTownTavernOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_French citizen";
				else
					curChar.greeting = "Gr_Albin Bonaventure";
			}
		break;
		case SPAIN:
			if (Checkattribute(curChar, "greeting") && HasSubStr(curChar.greeting, "citizen")) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_English Citizen";
				else
					curChar.greeting = "Gr_isla muelle citizen";
			}
			if (GetTownShipyardOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_English Citizen";
				else
					curChar.greeting = "Gr_esteban castillo";
			}
			if (GetTownStoreOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_English Citizen";
				else
					curChar.greeting = "Gr_Emiliano Rionda";
			}
			if (GetTownTavernOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_English Citizen";
				else
					curChar.greeting = "Gr_claudio burrieza";
			}
		break;
		case PIRATE:
			if (Checkattribute(curChar, "greeting") && HasSubStr(curChar.greeting, "citizen")) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_English Citizen";
				else
					curChar.greeting = "Gr_QC Citizen";
			}
			if (GetTownShipyardOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Desiree' Muerte";
				else
					curChar.greeting = "Gr_QC Citizen";
			}
			if (GetTownStoreOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Desiree' Muerte";
				else
					curChar.greeting = "Gr_Peter Blowhorn";
			}
			if (GetTownTavernOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Ines Diaz";
				else
					curChar.greeting = "Gr_Mario Figuiera";
			}
		break;
		case HOLLAND:
			if (Checkattribute(curChar, "greeting") && HasSubStr(curChar.greeting, "citizen")) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_Dutch Citizen";
				else
					curChar.greeting = "Gr_Douwesen Citizen";
			}
			if (GetTownShipyardOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_Dutch Citizen";
				else
					curChar.greeting = "Gr_Lambrecht Fobes";
			}
			if (GetTownStoreOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_Dutch Citizen";
				else
					curChar.greeting = "Gr_Gheerlof Darlang";
			}
			if (GetTownTavernOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Ines Diaz";
				else
					curChar.greeting = "Gr_Friedrich Corleis";
			}
		break;
		case PORTUGAL:
			if (Checkattribute(curChar, "greeting") && HasSubStr(curChar.greeting, "citizen")) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_English Citizen";
				else
					curChar.greeting = "Gr_Conceicao Citizen";
			}
			if (GetTownShipyardOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_English Citizen";
				else
					curChar.greeting = "Gr_Humberto de Paiva";
			}
			if (GetTownStoreOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_English Citizen";
				else
					curChar.greeting = "Gr_Martinho Guterres";
			}
			if (GetTownTavernOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_English Citizen";
				else
					curChar.greeting = "Gr_Duarte Correja";
			}
		break;
		// default:
			if (Checkattribute(curChar, "greeting") && HasSubStr(curChar.greeting, "citizen")) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_English Citizen";
				else
					curChar.greeting = "Gr_Oxbay Citizen";
			}
			if (GetTownShipyardOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_English Citizen";
				else
					curChar.greeting = "Gr_Oweyn McDorey";
			}
			if (GetTownStoreOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_English Citizen";
				else
					curChar.greeting = "Gr_Alan Milds";
			}
			if (GetTownTavernOwnerIndex(town) == chridx) {
				if (curchar.sex == "woman")
					curChar.greeting = "Gr_Woman_English Citizen";
				else
					curChar.greeting = "Gr_Everard Gordon";
			}
	}
}
// <-- KK
