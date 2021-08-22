
extern void LAi_CharacterFireExecute_WR(aref attack, aref enemy, float kDist, int isFindedEnemy); // PB: Create external function
extern void LAi_CharacterFireExecute_BUG(aref attack, aref enemy, float kDist, int isFindedEnemy); // PB: Create external function
extern void LAi_CharacterFireExecute_BART(aref attack, aref enemy, float kDist, int isFindedEnemy); // PB: Create external function

//==========================================================================================
//Update events
//==========================================================================================

void LAi_Character_FrameUpdate()
{
	float dltTime = GetEventData();
	//Обновляем состояние персонажей
	LAi_AllCharactersUpdate(dltTime);
	//Задержка исполнения квестов
	LAi_QuestDelayProcess(dltTime);
}

//MAXIMUS -->
void LAi_CharacterTypeUpdate()
{
	//Параметры
	string chID = GetEventData();
	aref chr = CharacterFromID(chID);
	if(!CheckAttribute(chr,"chr_ai.type")) return;
	float dltTime = 0.0;
	//Процессируем соответствующий тип
	string func = chr.chr_ai.type;
	if(func != "")
	{
		func = "LAi_type_" + func + "_CharacterUpdate";
		call func(chr, dltTime);
	}
	//Процессируем соответствующий шаблон
	func = chr.chr_ai.tmpl;
	if(func == "") return;
	func = "LAi_tmpl_" + func + "_CharacterUpdate";
	call func(chr, dltTime);
	DelEventHandler("CharacterTypeUpdate", "LAi_CharacterTypeUpdate");
}
//MAXIMUS <--

void LAi_CharacterUpdate()
{
	//Параметры
	aref chr = GetEventData();
	float dltTime = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterUpdate") == false) return;
	//Процессируем соответствующий тип
	string func = chr.chr_ai.type;
	if(func != "")
	{
		func = "LAi_type_" + func + "_CharacterUpdate";
		call func(chr, dltTime);
	}
	//Процессируем соответствующий шаблон
	func = chr.chr_ai.tmpl;
	if(func == "") return;
	func = "LAi_tmpl_" + func + "_CharacterUpdate";
	call func(chr, dltTime);
}

//==========================================================================================
//EndTask events
//==========================================================================================

void LAi_CharacterEndTask()
{
	//Параметры
	string endTask = GetEventData();
	aref chr = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterEndTask") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//Определяем отработавшую задачу
	bool isProcessed = false;
	switch(endTask)
	{
	case "Goto point":
		func = "LAi_tmpl_" + func + "_EndGoToPoint";
		isProcessed = true;
		break;
	case "Runto point":
		func = "LAi_tmpl_" + func + "_EndRunToPoint";
		isProcessed = true;
		break;
	case "Escape":
		func = "LAi_tmpl_" + func + "_EndEscape";
		isProcessed = true;
		break;
	}
	if(isProcessed != false)
	{
		call func(chr);
	}else{
		Trace("LAi_CharacterEndTask -> unknow end task <" + endTask + ">");
	}
}

//==========================================================================================
//TaskFailure events
//==========================================================================================

void LAi_CharacterTaskFailure()
{
	//Параметры
	string endTask = GetEventData();
	aref chr = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterTaskFailure") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//Определяем невыполнившиюся задачу
	bool isProcessed = false;
	switch(endTask)
	{
	case "Goto point":
		func = "LAi_tmpl_" + func + "_FailureGoToPoint";
		isProcessed = true;
		break;
	case "Runto point":
		func = "LAi_tmpl_" + func + "_FailureRunToPoint";
		isProcessed = true;
		break;
	case "Follow character":
		func = "LAi_tmpl_" + func + "_FailureFollow";
		isProcessed = true;
		break;
	case "Fight":
		func = "LAi_tmpl_" + func + "_FailureFight";
		isProcessed = true;
		break;
	case "Escape":
		func = "LAi_tmpl_" + func + "_FailureEscape";
		isProcessed = true;
		break;
	}
	if(isProcessed != false)
	{
		call func(chr);
	}else{
		Trace("LAi_CharacterTaskFailure -> unknow failure task <" + endTask + ">");
	}
}

void LAi_CharacterBusyPos()
{
	//Параметры
	aref chr = GetEventData();
	float x = GetEventData();
	float y = GetEventData();
	float z = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterTaskFailure") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	func = "LAi_tmpl_" + func + "_BusyPos";
	call func(chr, x, y, z);
}


//==========================================================================================
//Follow character's events
//==========================================================================================

void LAi_CharacterFollowGo()
{
	//Параметры
	string endTask = GetEventData();
	aref chr = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterFollowGo") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//Исполнение
	func = "LAi_tmpl_" + func + "_FollowGo";
	call func(chr);
}

void LAi_CharacterFollowStay()
{
	//Параметры
	string endTask = GetEventData();
	aref chr = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterFollowStay") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//Исполнение
	func = "LAi_tmpl_" + func + "_FollowStay";
	call func(chr);
}

//==========================================================================================
//Fight character's events
//==========================================================================================

void LAi_CharacterFightGo()
{
	//Параметры
	string endTask = GetEventData();
	aref chr = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterFightGo") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//Исполнение
	func = "LAi_tmpl_" + func + "_FightGo";
	call func(chr);
}

void LAi_CharacterFightStay()
{
	//Параметры
	string endTask = GetEventData();
	aref chr = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterFightStay") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//Исполнение
	func = "LAi_tmpl_" + func + "_FightStay";
	call func(chr);
}

void LAi_CharacterAttack()
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	aref attack = GetEventData();
	aref enemy = GetEventData();
	float attackDmg = GetEventData();
	float hitDmg = GetEventData();

	// end of unchanged original code

	bool CheckHostile = true; // run LAi_Attacked etc. set-hostile code. NK 05-07-10
	bool SetHostile = true;
	string effects_to_play = "always"; // for selective playing of FX
	int i;
	ref mainCh = GetMainCharacter();//MAXIMUS
	bool bPlayer = false;//MAXIMUS

	//skillearning(attack, "Fencing", 1);	// ccc skillearning
//JRH -->
    //Cartagena
	if(CheckAttribute(attack,"quest.church_burglar") && attack.quest.church_burglar == "4")
	{
		if(CheckAttribute(enemy, "id") && enemy.id == "window_target")
		{
			PlaySound("AMBIENT\TOWN\window_dog.wav");
			attack.quest.church_burglar = "5";
			LAi_SetFightMode(attack, false);
			ChangeCharacterAddressGroup(characterFromID("window_target"), "none", "", "");
			RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );
			TakeItemFromCharacter(attack, "bladepclub203");
			EquipCharacterByItem(attack, "bladeX4");
			GiveItem2Character(attack, "pistol203");
			EquipCharacterByItem(attack, "pistol203");

			LAi_QuestDelay("shot_at_church_window", 3.0);		//delay before you are being shot at
		}
		
		return;
	}

	if(CheckAttribute(attack,"quest.inquisition_priest"))
	{
		if(attack.quest.inquisition_priest == "sleeping_left")
		{
			PlaySound("OBJECTS\DUEL\club1.wav");

			LAi_QuestDelay("cartagena_priest_stunned_left", 0.1);
			return;
		}

		if(attack.quest.inquisition_priest == "sleeping_right")
		{
			PlaySound("OBJECTS\DUEL\club1.wav");

			LAi_QuestDelay("cartagena_priest_stunned_right", 0.1);
			return;
		}
	}

	if(CheckAttribute(attack,"quest.inquisition_monk"))
	{
		if(attack.quest.inquisition_monk == "monk1_hit" || attack.quest.inquisition_monk == "monk2_hit"
		|| attack.quest.inquisition_monk == "monk3_hit" || attack.quest.inquisition_monk == "monk4_hit")
		{
			PlaySound("OBJECTS\DUEL\club2.wav");

			LAi_QuestDelay("cartagena_monks_hit", 0.1);
			return;
		}
	}

	if(CheckAttribute(enemy, "id") && enemy.id == "box_ghost")
	{
		CreateParticleSystem("blast_dirt" , -1.25, 1.8, -5.8, 0.0, 0.0, 0.0, sti(20) );
		CreateParticleSystem("blast_dirt" , -1.25, 2.3, -5.8, 0.0, 0.0, 0.0, sti(20) );
		CreateParticleSystem("splinters", -1.25, 1.8, -5.8, 0.0, 0.0, 0.0, 0);
		CreateParticleSystem("splinters2", -1.25, 1.8, -5.8, 0.0, 0.0, 0.0, 0);
		CreateParticleSystem("splinters", -1.25, 2.3, -5.8, 0.0, 0.0, 0.0, 0);
		CreateParticleSystem("splinters2", -1.25, 2.3, -5.8, 0.0, 0.0, 0.0, 0);
		PlaySound("PEOPLE\roof_broken1.wav");
		PlaySound("PEOPLE\slide_down_roof.wav");
		LAi_SetFightMode(attack, false);
		ChangeCharacterAddressGroup(characterFromID("box_ghost"), "none", "", "");

		LAi_QuestDelay("jup_kungfu_done2", 2.5);
	}

	if(CheckAttribute(enemy, "id") && enemy.id == "gate_ghost")
	{
		
		LAi_SetFightMode(attack, false);
		ChangeCharacterAddressGroup(characterFromID("gate_ghost"), "none", "", "");
		Locations[FindLocation(mainCh.location)].models.always.l4 = "bars_down";	
		Locations[FindLocation(mainCh.location)].models.always.l7 = "plank_ground";		
		
		LAi_QuestDelay("Jup_stops_maroons000", 0.5);
	}

	if(CheckAttribute(enemy, "id") && enemy.id == "chapel_target")
	{
		PlaySound("AMBIENT\TOWN\window_dog.wav");
		LAi_SetFightMode(attack, false);
		ChangeCharacterAddressGroup(characterFromID("chapel_target"), "none", "", "");
		Locations[FindLocation(mainCh.location)].reload.l7.disable = 0;
		attack.chapel_window = "broken";
	}

	if(CheckAttribute(enemy, "id") && enemy.id == "painting_target")
	{
		PlaySound("OBJECTS\DUEL\pistol_out1.wav");
		SetLocatorRadius(locations[FindLocation(attack.location)], "box", "box15", 0.0001);
		Locations[FindLocation("bb_lower_cave")].locators_radius.box.box15 = 0.0001;
		LAi_SetPlayerType(attack);
		LAi_SetFightMode(attack, false);
		LAi_LocationFightDisable(&Locations[FindLocation(attack.location)], true);
		ChangeCharacterAddressGroup(characterFromID("painting_target"), "none", "", "");
		
		LAi_QuestDelay("prepare_FH_painting_check", 0.1);
	}
//<-- JRH

	// ccc special weapon assembly kit start
	// note: the function we are in here runs if a character (referred to as "attack") uses a blade on a targetcharacter ("enemy")
	if(CheckAttribute(attack, "equip.blade")) // NK just in case.
	{
		string weaponID = GetCharacterEquipByGroup(attack,BLADE_ITEM_TYPE); // defines weaponname
		aref weapon;
		Items_FindItem(weaponID, &weapon);	// defines object for weaponattributes

		if( CheckAttribute(weapon, "sound" ) )
		{
			PlaySound( weapon.sound ); 				//JRH
			//LAi_CharacterPlaySound(attack, weapon.sound ); 	//didn't accept stereo sounds
			// plays soundfile if defined in items\itemsinit.c
		}

	// move FX to bottom. NK 05-07-10

// NK move hardcoded chances to the weapon attribute. 05-07-10

		// NK add check so only works for pchar and only works on person who is not pchar's group. 05-07-06
		if( CheckAttribute(weapon, "steal" ) && sti(attack.index) == GetMainCharacterIndex() && !LAi_IsFightMode(enemy) && attack.chr_ai.group != enemy.chr_ai.group)
		 	// if weapon is a thief's tool; works only if victim is not prepared for fight
		{
			CheckHostile = false; // NK for stealth check below
			//skillearning(attack, "sneak", 1);	// ccc skillearning

			LAi_AttemptSteal(attack, enemy, weapon); // NK do this in one function. 05-07-10
		}
		if( CheckAttribute(weapon, "stun" ) && !LAi_IsFightMode(enemy) && enemy.chr_ai.group != LAI_GROUP_PLAYER )
		// if weapon stuns victim; works only if victim is not prepared for fight and no playerassociate
		{
			//skillearning(attack, "sneak", 1);	// ccc skillearning
			if(frnd() < stf(weapon.stun)*GetAttackLuckMod(&attack))	// jun 05 stun doesnt work always anymore
			{
				int duration = 100;
				if(CheckAttribute(weapon, "stun.duration")) duration = sti(weapon.stun.duration);
				//MAXIMUS: during fight, character can join to his crew. Sometimes it may be helpful -->
				bPlayer = false;
				if(CheckAttribute(enemy, "chr_ai.group") && enemy.chr_ai.group==LAI_GROUP_PLAYER)
				{
					if(sti(mainCh.skill.Leadership)>sti(enemy.skill.Leadership)) bPlayer = true;
				}
				else
				{
					if(sti(mainCh.skill.Leadership)<sti(enemy.skill.Leadership)) bPlayer = true;
				}
				LAi_Stunned_StunCharacter(enemy, duration, true, STUN_STARS, bPlayer);
				//MAXIMUS: during fight, character can join to his crew. Sometimes it may be helpful <--
				//effects_to_play += " stun";
			}
		}

		if( CheckAttribute(weapon, "poison" ) ) 	// if weapon poisonous
		{
			if(GetAttribute(enemy, "id") == "Blackbeard")	LAi_SetImmortal(enemy, false);	// PB: Blackbeard can be killed only using a Borgiablade
			Log_SetStringToLog(TranslateString("","Victim poisoned!"));
			enemy.chr_ai.poison =  300 ;		// initial targetchr poisoned
			LAi_CharacterPlaySound(enemy, "OBJECTS\Voices\dead\male\dead4.wav");
			effects_to_play += " poison";

			if(GetAttribute(attack, "chr_ai.group") == LAI_GROUP_PLAYER && CheckAttribute(enemy, "itemtrade"))	// PB: For streetmerchants only
			{
				MerchantGuildAttack(enemy, true);
			}

			if(attack.id == "zombie1") LAi_QuestDelay("zombie1_voice", 0.5);	//JRH
			if(attack.id == "zombie2") LAi_QuestDelay("zombie2_voice", 0.5);
			if(attack.id == "zombie3") LAi_QuestDelay("zombie3_voice", 0.5);
			if(attack.id == "zombie4") LAi_QuestDelay("zombie4_voice", 0.5);
			if(attack.id == "zombie5") LAi_QuestDelay("zombie5_voice", 0.5);
			if(attack.id == "zombie6") LAi_QuestDelay("zombie6_voice", 0.5);
		}
		// NK fix for stealing weapons 05-07-06
		// 05-07-10 reorder this, do actual hostile-setting at bottom.
		if(CheckHostile)
		{
			if(CheckAttribute(weapon, "stealth"))	// silent weapons don't alarm the victim, for others next line runs
			{
		          	if(frnd() < stf(weapon.stealth)*GetAttackLuckMod(&attack)) { SetHostile = false; }
				else { LAi_CharacterPlaySound(enemy,"VOICE\" + LanguageGetLanguage() + "\Eng_m_a_067.wav"); } // sound alarm
			}
		}
		else SetHostile = false;

		if( CheckAttribute(weapon, "throw" ) )	// for onetime use
		{
			if(GetCharacterItem(attack, weaponID) <= 1) RemoveCharacterEquip(attack, weapon.groupID);	// unequips thrown weapon
	              TakeItemFromCharacter(attack, weaponID );		// deletes thrown weapon from inventory
		}


		if( CheckAttribute(weapon, "fist" ) && !LAi_IsImmortal(enemy))
		// PB: New weapons attribute, exclusively for your fists
		//     Can't knock out immortal characters, nor can you do damage to them
		{
			int rank = makeint(attack.rank);
		//	int punch = rand(rank) + rank; // PB: Orig code
			// Baste -->
			float damage
			if(GetAttribute(weapon, "id") == "bladeflint")
				damage = rand(rank)*1;	//JRH
			else
				damage = rand(rank)*0.5;
			float kDmg = 1.0;
			if(IsCharacterPerkOn(enemy, "BasicDefence")) kDmg = 0.9;
			if(IsCharacterPerkOn(enemy, "AdvancedDefence")) kDmg = 0.8;
			if(IsCharacterPerkOn(enemy, "SwordplayProfessional")) kDmg = 0.7;
			damage = damage*kDmg;
			if(makeint(damage) <= 0) damage = 1;
			float critical = 0.0;
			if(rand(100) <= 5) critical = damage*2.0;
			/*bool noExp = false;
			if(CheckAttribute(attack, "chr_ai.group"))
			{
				if(CheckAttribute(enemy, "chr_ai.group"))
				{
					if(attack.chr_ai.group == enemy.chr_ai.group && !CheckAttribute(GetMainCharacter(),"TrainingFight") && !HasSubStr(attack.id,"TrainingFight_") && !HasSubStr(enemy.id,"TrainingFight_"))//MAXIMUS
					{
					// ccc mar05 REPLOSS tweak added
					//	PB: I don't think we need this; no harm done = no reploss needed
					//	LAi_ChangeReputation(attack, - REPLOSS);	// ccc rephit for attacking friends
					//	if(sti(attack.index) == GetMainCharacterIndex()) LogIt("CHANGE REP for player: " + -REPLOSS + " - attacking friends");	// LDH 19Dec08
						damage = 0.0;
						critical = 0.0;
						noExp = true;
					}
				}
			}*/
			if(critical > 0.0)
			{
				if(sti(attack.index) == GetMainCharacterIndex())
				{
					Log_SetStringToLog(XI_ConvertString("Critical Hit"));
				}
			}
			// Calculates the strength of your punch; character's rank increases damage

			//LAi_ApplyCharacterDamage(enemy, punch);
			if(critical > 0.0)
			{
				LAi_ApplyCharacterDamage(enemy, MakeInt(ApplyArmor(enemy, attack, critical, true) + 0.5)); // GreatZen-NK
			}
			else
			{
				LAi_ApplyCharacterDamage(enemy, MakeInt(ApplyArmor(enemy, attack, damage, true) + 0.5)); // GreatZen-NK
			}
			if(critical > 0.0) damage = critical; // For stun check below and EXP calculation
			// Applies damage to enemy
			PlaySound("OBJECTS\duel\punch"+sti(Rand(2)+1)+".wav");
			// Play a random punch impact sound

			LAi_CheckKillCharacter(enemy); // Checks if this has killed the character

			if(!LAi_IsDead(enemy)) //checks if char now dead or not
			{
			//	if(rand(100) < punch + sti(attack.skill.Sneak) && sti(enemy.index) != GetMainCharacterIndex()) // PB: Orig code
				if(rand(50) < damage && sti(enemy.index) != GetMainCharacterIndex()) // Baste
				// Checks if punch knocks enemy out; character's rank increases chance
				{	//MAXIMUS: during fight, character can join to his crew. Sometimes it may be helpful -->
					bPlayer = false;
					if(CheckAttribute(enemy, "chr_ai.group") && enemy.chr_ai.group==LAI_GROUP_PLAYER)
					{
						if(sti(CalcCharacterSkill(mainCh,SKILL_LEADERSHIP)) > sti(CalcCharacterSkill(enemy,SKILL_LEADERSHIP))) bPlayer = true;
					}
					/*else
					{
						if(sti(CalcCharacterSkill(mainCh,SKILL_LEADERSHIP)) < sti(CalcCharacterSkill(enemy,SKILL_LEADERSHIP))) bPlayer = true;
					}*/
					LAi_Stunned_StunCharacter(enemy, 100, true, STUN_STARS, bPlayer);
					//MAXIMUS: during fight, character can join to his crew. Sometimes it may be helpful <--
					SetHostile = false;
				}
			}
		}
		bool isSetBalde = (CheckAttribute(enemy, "equip.blade") == true);//(SendMessage(enemy, "ls", MSG_CHARACTER_EX_MSG, "IsSetBalde") != 0);
		int erank = makeint(enemy.rank);
		//float exp = damage*((1.0 + erank*0.5)/(1.0 + rank*0.5)) * sqrt(erank); //Levis this is done in fight params already
		if(!isSetBalde)
		{
			// ccc mar05 REPLOSS tweak added
			if(enemy.chr_ai.group != LAi_monsters_group)
			{
				if(!CheckAttribute(enemy,"corpse")) enemy.corpse = false; //Fix by levis
				if(enemy.corpse==false) //Levis: fix so you won't get reploss from hitting corpses
				{					
					if (CheckAttribute(enemy, "attacked_you")) // GR: No reploss if enemy attacked you.  If player attacks enemy who attacked you and is now running, show warning
					{
						if (sti(GetAttribute(attack, "index")) == GetMainCharacterIndex()) logit(TranslateString("", "Enemy lost weapon, trying to run!"));
					}
					else
					{
						if (!CheckAttribute(enemy,"pickgold") || GetCharacterEquipByGroup(attack, BLADE_ITEM_TYPE) != "bladeX3") // GR: no reploss if he robbed you and you use a thief's knife
						{
							if(GetAttribute(attack, "index") && sti(attack.index) == GetMainCharacterIndex()) LogIt(TranslateString("","CHANGE REP for player:") + " " + -REPLOSS + " - " + TranslateString("","undrawn blade 2")); 	// LDH 19Dec08
							LAi_ChangeReputation(attack, - REPLOSS); // NK tempfix for un-drawn blades 04-17
						}
					}
				}
			}
			//exp = 0.0;
		}

		/*if(!noExp)
		{
			AddCharacterExp(attack, MakeInt(exp*0.5 + 0.5));
		}*/
		// Baste <--

		if( CheckAttribute(weapon, "pistolclub") || CheckAttribute(weapon, "rifleclub") )
		// JRH: New weapons attribute, exclusively for your pistolclub or rifleclub
		{
			int rankk = makeint(attack.rank);
			int club;
			if(CheckAttribute(weapon, "rifleclub"))
			{
				club = rand(rankk) + rankk + 10;
			}
			else club = rand(rankk) + rankk + 5;		//testing how much better this should be than fists
			// Calculates the strength of your club; character's rank increases damage

			LAi_ApplyCharacterDamage(enemy, club);
			// Applies damage to enemy

			switch(rand(2))
			{
				case 0: PlaySound("OBJECTS\duel\club1.wav"); break;
				case 1: PlaySound("OBJECTS\duel\club2.wav"); break;
				case 2: PlaySound("OBJECTS\duel\club3.wav"); break;
			}
			// Play a random club impact sound

	//		if(CheckAttribute(weapon, "rifleclub")) PlaySound("OBJECTS\duel\punch"+sti(Rand(2)+1)+".wav");//heavier club - more sound
			if(CheckAttribute(weapon, "rifleclub")) PlaySound("PEOPLE\wood1.wav");//heavier club - more sound

			if(CheckAttribute(weapon, "rifleclub"))
			{
				if(LAi_IsDead(enemy)) 
				{
					if(!IsOfficer(enemy)) LAi_KillCharacter(enemy);
				}
			}
			else LAi_CheckKillCharacter(enemy); // Checks if this has killed the character
						            			// JRH: but it doesn't work

			//skip stunned??? - think it's strange: enemy just standing there - or causes other strange situations
			if(!LAi_IsDead(enemy)) //checks if char now dead or not
			{
				if(rand(100) < club + sti(attack.skill.Sneak) && sti(enemy.index) != GetMainCharacterIndex())
				// Checks if club knocks enemy out; character's rank increases chance
				{
					//LAi_Stunned_StunCharacter(enemy, 100, true, STUN_STARS, false);
					//SetHostile = false;

					float u, v, w;
					GetCharacterPos(enemy, &u, &v, &w);
					CreateParticleSystem("stars" , u, v+1, w, 0.0, 0.0, 0.0, sti(20) );
					LAi_SetStunnedType(enemy);
					//sitting now
				}
			}
		}

		string weaponID2 = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);
		aref weapon2;
		Items_FindItem(weaponID2, &weapon2);

		if(CheckAttribute(weapon2, "id") && weapon2.id == "pistolbow")
		{
			if(IsMainCharacter(attack) || IsOfficer(attack) || IsOfficerType(attack))
			{
				
			}
			else
			{
				if(CheckAttribute(weapon, "id") && weapon.id != "tomahawk")
				{
					RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );
					GiveItem2Character(attack, "tomahawk");
					EquipCharacterByItem(attack, "tomahawk");
				}
			}
		}

		if(CheckAttribute(weapon, "id") && weapon.id == "bladearrows")
		{
			if(IsMainCharacter(attack) || IsOfficer(attack) || IsOfficerType(attack))
			{
				RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );
				EquipCharacterByItem(attack, FindCharacterItemByGroup(attack, BLADE_ITEM_TYPE));

				weaponID = GetCharacterEquipByGroup(attack,BLADE_ITEM_TYPE);
				if(weaponID == "")
				{
					if(!CheckCharacterItem(attack, "bladeX4")) GiveItem2Character(attack, "bladeX4");
					EquipCharacterByItem(attack, "bladeX4");
				}
			}
		}

		// CCC and PB: New attribute to weapons to allow for disarming opponents
		bool tbool = CheckAttribute(enemy, "equip.blade");
		if(tbool) tbool = GetCharacterEquipByGroup(enemy,BLADE_ITEM_TYPE) != "bladeX4";
		if( DISARM_MODE && CheckAttribute(weapon, "disarm" ) &&  LAi_IsFightMode(enemy) && !CheckAttribute(enemy, "nodisarm" ) && tbool)
		{
			int disarmbonus = 0;
			if(CheckAttribute(attack,"perks.list.SwordplayProfessional")) {disarmbonus = 20;}
			// if attacker has professional fencing skill, increase disarm chance with 20%

			int disarmpenalty = 0;
			if(CheckAttribute(enemy,"perks.list.SwordplayProfessional")) {disarmpenalty = 10;}
			// if attacked victim has professional fencing skill, decrease disarm chance with 10%

			if(sti(rand(100)+enemy.skill.Fencing) < sti(weapon.disarm)+sti(attack.skill.Fencing) + disarmbonus - disarmpenalty)
			{
				LAi_CharacterPlaySound(enemy,"OBJECTS\duel\sword_fallen.wav");
				string enemy_blade = GetCharacterEquipByGroup(enemy,BLADE_ITEM_TYPE);
				RemoveCharacterEquip(enemy,  BLADE_ITEM_TYPE );
				GiveItem2Character(attack, enemy_blade);

				if ( enemy.chr_ai.group !=  LAI_GROUP_PLAYER && !bAbordageStarted )
				// no disarming opponents during boarding
				{
					LAi_SetCitizenTypeNoGroup(enemy);
					Log_SetStringToLog(TranslateString("","Opponent disarmed !"));
				}
				else
				{
					TakeItemFromCharacter(enemy, enemy_blade);
					if ( sti(enemy.index) != GetMainCharacterIndex() && !bAbordageStarted ) // if NOT player
					// officers safe from being disarmed boarding; player NOT safe from being disarmed during boarding
					{
						RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );			// makes enemy use your blade against your officer
						EquipCharacterByItem(attack, enemy_blade);			// and enables you to get it back by killing him/her
						Log_SetStringToLog(TranslateString("","One of your officers was disarmed!"));
						LAi_tmpl_afraid_SetAfraidCharacter(enemy, attack, true);	// makes officer flee
						LAi_SetAfraidDead(enemy);
					}
					else
					{
						RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );			// makes enemy use your blade against you
						EquipCharacterByItem(attack, enemy_blade);			// and enables you to get it back by killing him/her
						EquipCharacterByItem(enemy, "bladeX4");
						Log_SetStringToLog(TranslateString("","You were disarmed!"));
					}
				}
			}
		}

		//Реакция груп на атаку
		// ccc LAi_group_Attack(attack, enemy);	// line moved into "stealth" section


		//Начисление повреждений

		// ccc particle effects, runs only if effect defined  in inititems.c
		LAi_PlayHitGFX(attack, enemy, weapon, effects_to_play); // NK do in centralized function 05-07-10

		if(!CheckAttribute(weapon, "fist" ) || !CheckAttribute(weapon, "pistolclub" ))	// PB: Fists will only do damage once with one hit, JRH: same for pclub
		{LAi_ApplyCharacterAttackDamage(attack, enemy, attackDmg, hitDmg);}
	}

	//JRH -->
	if(CheckAttribute(weapon, "id") && weapon.id == "bladeanchor")
	{
		if(CheckAttribute(enemy, "id") && enemy.id == "pir_cap10")
		{
			if(CheckAttribute(attack, "quest.Bunce") && attack.quest.Bunce == "in_boat")
			{
				attack.quest.Bunce = "awaken";
				LAi_SetFightMode(attack, false);
				LAi_LocationFightDisable(&Locations[FindLocation("wr_cave_shore")], true);

				LAi_QuestDelay("Bunce_wakes_up", 1.0);
			}
		}
	}

	if(CheckAttribute(weapon, "id") && weapon.id == "bladethunder")
	{
		if(CheckAttribute(enemy, "protection") && enemy.protection == "off")
		{
			GetCharacterPos(enemy, &u, &v, &w);
			CreateParticleSystem("blast" , u, v+1.2, w, 0.0, 0.0, 0.0, sti(20) );		//effect on pchar (enemy)
			PlaySound("NATURE\thunder1.wav");
			LAi_ApplyCharacterDamage(enemy, 30 + rand(10));					//was 30 + rand(20)
		}
	}

	if(CheckAttribute(weapon, "id") && weapon.id == "snakewand")
	{
		if(CheckAttribute(enemy, "id") && enemy.id == "devil")
		{
			GetCharacterPos(enemy, &u, &v, &w);
			CreateParticleSystem("artifact_very_short" , u, v+1.2, w, 0.0, 0.0, 0.0, sti(20) );
			PlaySound("OBJECTS\DUEL\snakewand.wav");
			PlaySound("OBJECTS\DUEL\boom.wav");
			attack.snakewand_hits = sti(attack.snakewand_hits) + 1;

			LAi_QuestDelay("count_snakewand_hits", 0.1);
		}
		else
		{
			if(IsMainCharacter(attack))
			{
				LAi_SetFightMode(attack, false);
				LAi_SetPlayerType(attack);
				
				LAi_QuestDelay("pchar_huh", 1.0);
			}
		}
	}
	//<-- JRH

	// TIH --> prevent stunned characters getting hit, causing everyone to go hostile with them
	if(CheckAttribute(enemy, "stuntime"))
	{
		SetHostile = false;
	}
	// TIH <--

	if(SetHostile) // if we are setting enemy hostile to us (and haven't yet)
	{
		if(!LAi_IsDead(enemy)) { LAi_group_Attack(attack, enemy); } // if not dead, alarm!
		else // otherwise...
		{
			// for now, just behave like normal. When I have a chance, I'll check near characters vs. see/hear radius.
			//int num = FindNearCharacters(enemy, float rad, float ax, float testAng, float nearDist, bool isVisibleTest, bool isSort)
			LAi_group_Attack(attack, enemy);
		}
	}
	// ccc special weapon assembly kit end

	// PB -->
	if(LAi_IsDead(enemy) && GetAttribute(attack, "chr_ai.group") == LAI_GROUP_PLAYER)
	{
		//if you killed a merchant
		if(CheckAttribute(enemy, "itemtrade"))
		{
			if(attack.location == "wr_ships" || attack.location == "wr_gall_captain") return; //JRH
			MerchantGuildAttack(enemy, true);
		}

		SoldierReinforcements(enemy); //if you killed a town guard
	}
	// PB <--

	// unchanged code begins:

	//Исполнение типа
	string func = attack.chr_ai.type;
	if(func == "") return;
	func = "LAi_type_" + func + "_Attack";
	call func(attack, enemy, attackDmg, hitDmg);
	//Обновим цель сразу
	LAi_group_UpdateTargets(enemy);
	func = enemy.chr_ai.type;
	if(func == "") return;
	func = "LAi_type_" + func + "_Attacked";
	call func(enemy, attack);
	func = "LAi_type_" + enemy.chr_ai.type + "_CharacterUpdate";
	call func(enemy, 0.0001);
	//LanguageCloseFile(tmpLangFileID);
}

void LAi_CharacterBlock()
{
	aref attack = GetEventData();
	aref enemy = GetEventData();
	float attackDmg = GetEventData();
	float hitDmg = GetEventData();

	// PB: Bladedamage mod -->
	int bladedamage_usage;
	int bladedamage_level = 0; // changed by MAXIMUS
	int total_chance;
	string BladeID;
	string BladeBaseID;
	string weaponID;
	aref weapon;
	bool DecreaseQuality;
	bool BladeBreak;
	bool Continue_Bladedamage;

	ref PChar = GetMainCharacter();

// Counters to gather information for balancing this mod -->
	if(sti(enemy.index) == GetMainCharacterIndex())
	// This counts how many times an enemy hit the PChar while the PChar was blocking
	{
		if(!CheckAttribute(PChar,"hitduringblock")) PChar.hitduringblock = 0;
		PChar.hitduringblock = sti(PChar.hitduringblock) + 1;

		//JRH-->
		BladeID = GetCharacterEquipByGroup(attack,BLADE_ITEM_TYPE);
		if(BladeID == "bladearrows")
		{
			RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );
			GiveItem2Character(attack, "tomahawk");
			EquipCharacterByItem(attack, "tomahawk");
		}
		//<--JRH
	}

	if(sti(attack.index) == GetMainCharacterIndex())
	// This counts how many times the PChar hit an enemy while the enemy was blocking
	{
		if(!CheckAttribute(PChar,"hitwhileblocking")) PChar.hitwhileblocking = 0;
		PChar.hitwhileblocking = sti(PChar.hitwhileblocking) + 1;

		//JRH-->
		BladeID = GetCharacterEquipByGroup(attack,BLADE_ITEM_TYPE);
		if(BladeID == "bladearrows")
		{
			RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );
			EquipCharacterByItem(attack, FindCharacterItemByGroup(attack, BLADE_ITEM_TYPE));

			BladeID = GetCharacterEquipByGroup(attack,BLADE_ITEM_TYPE);
			if(BladeID == "")
			{
				if(!CheckCharacterItem(attack, "bladeX4")) GiveItem2Character(attack, "bladeX4");
				EquipCharacterByItem(attack, "bladeX4");
			}
		}
		//<--JRH
	}

	//JRH-->
	if(IsOfficer(attack) || IsOfficerType(attack))
	{
		BladeID = GetCharacterEquipByGroup(attack,BLADE_ITEM_TYPE);
		if(BladeID == "bladearrows")
		{
			RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );
			EquipCharacterByItem(attack, FindCharacterItemByGroup(attack, BLADE_ITEM_TYPE));

			BladeID = GetCharacterEquipByGroup(attack,BLADE_ITEM_TYPE);
			if(BladeID == "")
			{
				if(!CheckCharacterItem(attack, "bladeX4")) GiveItem2Character(attack, "bladeX4");
				EquipCharacterByItem(attack, "bladeX4");
			}
		}
	}
	//<--JRH

// Counters to gather information for balancing this mod <--

	// Code for the bladedamage for the enemy:
	if(BLADEDAMAGE_ENABLED && ENABLE_WEAPONSMOD && GetCharacterEquipByGroup(enemy,BLADE_ITEM_TYPE) != "bladeX4" && !bDeckEnter && GetItemQualityName(GetItemQualityByID(GetCharacterEquipByGroup(enemy,BLADE_ITEM_TYPE))) != "") // PB
	{
		if(!CheckAttribute(enemy,"bladedamagecounter"))
		{
			if(sti(enemy.index) == GetMainCharacterIndex())
		 	{enemy.bladedamagecounter = 0;}
			else
			{enemy.bladedamagecounter = rand(BLADEDAMAGE_RAND + BLADEDAMAGE_BASE) - 0.5 * BLADEDAMAGE_RAND;} // to decrease the chance of an enemy's blade breaking on first hit
		}
		enemy.bladedamagecounter = sti(enemy.bladedamagecounter) + 1;
		// Counts the amount of strokes you performed with your blade

			BladeID = GetCharacterEquipByGroup(enemy,BLADE_ITEM_TYPE);
		if (findSubStr(&BladeID, "+", 0) > -1 || findSubStr(&BladeID, "-", 0) > -1)
			BladeBaseID = strcut(&BladeID, 0, strlen(BladeID) - 3);
		else
			BladeBaseID = BladeID;

		weaponID = GetCharacterEquipByGroup(enemy,BLADE_ITEM_TYPE); // defines weaponname
		Items_FindItem(weaponID, &weapon);	// defines object for weaponattributes

		DecreaseQuality = false;
		BladeBreak = false;
		Continue_Bladedamage = true;

		// Bladedamage based on the usage of your blade
		// -------------------------------------------------------
		bladedamage_usage = enemy.bladedamagecounter;

		//LogIt("Bladedamage Usage = " + bladedamage_usage);

		// Bladedamage based on your level vs the blade's minlevel
		// -------------------------------------------------------
		if(CheckAttribute(weapon,"minlevel") && sti(weapon.minlevel) < 95) bladedamage_level = sti(weapon.minlevel) - sti(enemy.rank); // changed by MAXIMUS
		if(bladedamage_level < 0) bladedamage_level = 0;
		bladedamage_level = 0.01 * (BLADEDAMAGE_BASE + BLADEDAMAGE_RAND) * sti(bladedamage_level); // to keep this effect having impact, even if BASE or RAND are increased

		//LogIt("Bladedamage Level = " + bladedamage_level);

		total_chance = sti(bladedamage_usage) + sti(bladedamage_level);
		if(CheckCharacterItem(enemy, "bladekit") && !HasSubStr(BladeID,"halberd"))	total_chance = total_chance/2; // JRMM
		if(total_chance > rand(BLADEDAMAGE_RAND) + BLADEDAMAGE_BASE)
		{DecreaseQuality = true;}

		//LogIt("Total chance points = " + total_chance + " for character " + enemy.name + " " + enemy.lastname);

		// Broken blades break VERY quickly!!!
		if(GetItemQualityByID(BladeID) == 0 && rand(sti(bladedamage_usage)) > 10) // Add some randomness
		{DecreaseQuality = true;}

		if(DecreaseQuality)
		{
			RemoveCharacterEquip(enemy, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(enemy, BladeID);

			enemy.bladedamagecounter = 0;

			switch(GetItemQualityByID(BladeID))
			{
				case 0:
					LAi_CharacterPlaySound(enemy, "OBJECTS\duel\sword_broken.wav");//MAXIMUS
					BladeBreak = true;
				break;

				case 1:
					if(enemy.chr_ai.group ==  LAI_GROUP_PLAYER)
					{LAi_CharacterPlaySound(enemy, "OBJECTS\duel\sword_broken.wav");}//MAXIMUS
					// To only play the sound for player-related characters

					// To give broken blades
					if(enemy.chr_ai.group ==  LAI_GROUP_PLAYER || BLADEDAMAGE_KEEPBROKENBLADE)
					{
						GiveItem2Character(enemy, BladeBaseID + "-2");
						EquipCharacterByItem(enemy, BladeBaseID + "-2");
					}
					BladeBreak = true;
				break;

				case 2:
					GiveItem2Character(enemy, BladeBaseID + "-1");
					EquipCharacterByItem(enemy, BladeBaseID + "-1");
				break;

				case 3:
					GiveItem2Character(enemy, BladeBaseID);
					EquipCharacterByItem(enemy, BladeBaseID);
				break;

				case 4:
					GiveItem2Character(enemy, BladeBaseID + "+1");
					EquipCharacterByItem(enemy, BladeBaseID + "+1");
				break;

				case 5:
					GiveItem2Character(enemy, BladeBaseID + "+2");
					EquipCharacterByItem(enemy, BladeBaseID + "+2");
				break;
			}

			if(BladeBreak)
			{
				if(sti(enemy.index) == GetMainCharacterIndex())
				{
					Continue_Bladedamage = false;
					LogIt(TranslateString("", "Your blade decreased in quality!"));
				}
				if(CheckAttribute(enemy, "nodisarm")) Continue_Bladedamage = false;
				if(enemy.chr_ai.group == LAI_GROUP_PLAYER) Continue_Bladedamage = false;
				if(bAbordageStarted) Continue_Bladedamage = false;

				if(Continue_Bladedamage && rand(1) > 0)
				{
					LAi_SetCitizenTypeNoGroup(enemy);
					enemy.attacked_you = true;
				}
				else
				{
					if(CheckCharacterItem(enemy, FindCharacterItemByGroup(enemy, BLADE_ITEM_TYPE)) && GetItemQualityByID(FindCharacterItemByGroup(enemy, BLADE_ITEM_TYPE)) != 0 && BLADEDAMAGE_USEOTHERBLADE)
					// If character has another blade and the other blade is not broken and USEOTHERBLADE is on
					{
						// Then use the other blade
						EquipCharacterByItem(enemy, FindCharacterItemByGroup(enemy, BLADE_ITEM_TYPE));
					}
					else
					{
						// Else use the default blade
						if(!CheckCharacterItem(enemy, BLADEDAMAGE_DEFAULTBLADE))
						{GiveItem2Character(enemy, BLADEDAMAGE_DEFAULTBLADE);}
						// To prevent characters being given another defaultblade if they already have one
						EquipCharacterByItem(enemy, BLADEDAMAGE_DEFAULTBLADE);
					}
				}
			}
		}
	}

	// Code for the bladedamage for the attack:
	if(BLADEDAMAGE_ENABLED && ENABLE_WEAPONSMOD && GetCharacterEquipByGroup(attack,BLADE_ITEM_TYPE) != "bladeX4" && !bDeckEnter && GetItemQualityName(GetItemQualityByID(GetCharacterEquipByGroup(attack,BLADE_ITEM_TYPE))) != "") // PB
	{
		if(!CheckAttribute(attack,"bladedamagecounter"))
		{
			if(sti(attack.index) == GetMainCharacterIndex())
		 	{attack.bladedamagecounter = 0;}
			else
			{attack.bladedamagecounter = rand(BLADEDAMAGE_RAND + BLADEDAMAGE_BASE) - 0.5 * BLADEDAMAGE_RAND;} // to decrease the chance of an enemy's blade breaking on first hit
		}
		attack.bladedamagecounter = sti(attack.bladedamagecounter) + 1;
		// Counts the amount of strokes you performed with your blade

			BladeID = GetCharacterEquipByGroup(attack,BLADE_ITEM_TYPE);
		if (findSubStr(&BladeID, "+", 0) > -1 || findSubStr(&BladeID, "-", 0) > -1)
			BladeBaseID = strcut(&BladeID, 0, strlen(BladeID) - 3);
		else
			BladeBaseID = BladeID;

		weaponID = GetCharacterEquipByGroup(attack,BLADE_ITEM_TYPE); // defines weaponname
		Items_FindItem(weaponID, &weapon);	// defines object for weaponattributes

		DecreaseQuality = false;
		BladeBreak = false;
		Continue_Bladedamage = true;

		// Bladedamage based on the usage of your blade
		// -------------------------------------------------------
		bladedamage_usage = attack.bladedamagecounter;

		//LogIt("Bladedamage Usage = " + bladedamage_usage);

		// Bladedamage based on your level vs the blade's minlevel
		// -------------------------------------------------------
		if(CheckAttribute(weapon,"minlevel") && sti(weapon.minlevel) < 95)  bladedamage_level = sti(weapon.minlevel) - sti(attack.rank); // changed by MAXIMUS
		if(bladedamage_level < 0) bladedamage_level = 0;
		bladedamage_level = 0.01 * (BLADEDAMAGE_BASE + BLADEDAMAGE_RAND) * sti(bladedamage_level); // to keep this effect having impact, even if BASE or RAND are increased

		//LogIt("Bladedamage Level = " + bladedamage_level);

		total_chance = sti(bladedamage_usage) + sti(bladedamage_level);
		if(CheckCharacterItem(attack, "bladekit") && !HasSubStr(BladeID,"halberd"))	total_chance = total_chance/2; // JRMM

		if(total_chance > rand(BLADEDAMAGE_RAND) + BLADEDAMAGE_BASE)
		{DecreaseQuality = true;}

		//LogIt("Total chance points = " + total_chance + " for character " + attack.name + " " + attack.lastname);

		// Broken blades break VERY quickly!!!
		if(GetItemQualityByID(BladeID) == 0 && rand(sti(bladedamage_usage)) > 10) // Add some randomness
		{DecreaseQuality = true;}

		if(DecreaseQuality)
		{
			RemoveCharacterEquip(attack, BLADE_ITEM_TYPE);
			TakeItemFromCharacter(attack, BladeID);

			attack.bladedamagecounter = 0;

			switch(GetItemQualityByID(BladeID))
			{
				case 0:
					LAi_CharacterPlaySound(attack, "OBJECTS\duel\sword_broken.wav");//MAXIMUS
					BladeBreak = true;
				break;

				case 1:
					if(attack.chr_ai.group ==  LAI_GROUP_PLAYER)
					{LAi_CharacterPlaySound(attack, "OBJECTS\duel\sword_broken.wav");}//MAXIMUS
					// To only play the sound for player-related characters

					// To give broken blades
					if(attack.chr_ai.group ==  LAI_GROUP_PLAYER || BLADEDAMAGE_KEEPBROKENBLADE)
					{
						GiveItem2Character(attack, BladeBaseID + "-2");
						EquipCharacterByItem(attack, BladeBaseID + "-2");
					}
					BladeBreak = true;
				break;

				case 2:
					GiveItem2Character(attack, BladeBaseID + "-1");
					EquipCharacterByItem(attack, BladeBaseID + "-1");
				break;

				case 3:
					GiveItem2Character(attack, BladeBaseID);
					EquipCharacterByItem(attack, BladeBaseID);
				break;

				case 4:
					GiveItem2Character(attack, BladeBaseID + "+1");
					EquipCharacterByItem(attack, BladeBaseID + "+1");
				break;

				case 5:
					GiveItem2Character(attack, BladeBaseID + "+2");
					EquipCharacterByItem(attack, BladeBaseID + "+2");
				break;
			}

			if(BladeBreak)
			{
				if(sti(attack.index) == GetMainCharacterIndex()) Continue_Bladedamage = false;
				if(CheckAttribute(attack, "nodisarm")) Continue_Bladedamage = false;
				if(attack.chr_ai.group == LAI_GROUP_PLAYER) Continue_Bladedamage = false;
				if(bAbordageStarted) Continue_Bladedamage = false;

				if(Continue_Bladedamage && rand(1) > 0)
				{
					LAi_SetCitizenTypeNoGroup(attack);
				}
				else
				{
					if(CheckCharacterItem(attack, FindCharacterItemByGroup(attack, BLADE_ITEM_TYPE)) && GetItemQualityByID(FindCharacterItemByGroup(attack, BLADE_ITEM_TYPE)) != 0 && BLADEDAMAGE_USEOTHERBLADE)
					// If character has another blade and the other blade is not broken and USEOTHERBLADE is on
					{
						// Then use the other blade
						EquipCharacterByItem(attack, FindCharacterItemByGroup(attack, BLADE_ITEM_TYPE));
					}
					else
					{
						// Else use the default blade
						if(!CheckCharacterItem(attack, BLADEDAMAGE_DEFAULTBLADE))
						{GiveItem2Character(attack, BLADEDAMAGE_DEFAULTBLADE);}
						// To prevent characters being given another defaultblade if they already have one
						EquipCharacterByItem(attack, BLADEDAMAGE_DEFAULTBLADE);
					}
				}
			}
		}
	}
	// PB: Bladedamage mod <--

	//JRH --> weapon sound also when blocking for planks etc
	weaponID = GetCharacterEquipByGroup(enemy,BLADE_ITEM_TYPE); // defines weaponname
	Items_FindItem(weaponID, &weapon);	// defines object for weaponattributes

	if( CheckAttribute(weapon, "sound" ) ) { PlaySound( weapon.sound ); }
		// plays soundfile if defined in items\itemsinit.c

	string weaponID3 = GetCharacterEquipByGroup(attack,BLADE_ITEM_TYPE);
	aref weapon3;
	Items_FindItem(weaponID3, &weapon3);	// defines object for weaponattributes

	if( CheckAttribute(weapon3, "sound" ) ) { PlaySound( weapon3.sound ); }
		// plays soundfile if defined in items\itemsinit.c

	if(CheckAttribute(weapon3, "id") && weapon3.id == "bladethunder")
	{
		if(CheckAttribute(enemy, "protection") && enemy.protection == "off")
		{
			float u, v, w;
			GetCharacterPos(enemy, &u, &v, &w);
			CreateParticleSystem("blast" , u, v+1.2, w, 0.0, 0.0, 0.0, sti(20) );		//effect on pchar (enemy)
			PlaySound("NATURE\thunder1.wav");
			LAi_ApplyCharacterDamage(enemy, 30 + rand(10));					//was 30 + rand(20)
		}
	}


	if(BladeID == "blademketB" || BladeID == "blademketK") PlaySound("PEOPLE\wood1.wav");
   	//<-- JRH

	//skillearning(attack, "Fencing", 1);	// ccc skillearning

	//Реакция груп на атаку
	LAi_group_Attack(attack, enemy);
	//Начисление повреждений
	LAi_ApplyCharacterBlockDamage(attack, enemy, attackDmg, hitDmg);
	//Исполнение типа
	string func = attack.chr_ai.type;
	if(func == "") return;
	func = "LAi_type_" + func + "_Block";
	call func(attack, enemy, attackDmg, hitDmg);
	//Обновим цель сразу
	LAi_group_UpdateTargets(enemy);
	func = enemy.chr_ai.type;
	if(func == "") return;
	func = "LAi_type_" + func + "_Attacked";
	call func(enemy, attack);
	func = "LAi_type_" + enemy.chr_ai.type + "_CharacterUpdate";
	call func(enemy, 0.0001);
}

void LAi_CharacterFire()
	// ccc jul 05 Most code moved into the new LAi_CharacterFireExecute()
	// This now only gets the EventData from the original targeting process and passes them on if we don't correct them
{
	aref attack = GetEventData();
	aref enemy = GetEventData();
	float kDist = GetEventData();	//0..1
	int isFindedEnemy = GetEventData();

	// ccc jul05 shooting past corpses and barricades
	if(isFindedEnemy)
	{
		bool bPass = CheckAttribute(enemy,"corpse")==true;
		(!bPass) bPass = enemy.name=="A ";
		if(bPass)// if original target is corpse or barricade
		{
			int nm = FindNearCharacters(enemy, 2.5, -1.0, -1.0, 0.001, false, true);
			for(int k = 0; k <= nm; k++)
				// checks for other chrs around original target and loops through them
			{
				//changed by MAXIMUS - [fix - CheckAttribute] -->
				int ix = -1;
				if(CheckAttribute(chrFindNearCharacters[k],"index")) ix = sti(chrFindNearCharacters[k].index);
				if(ix == -1) return;
				//changed by MAXIMUS - [fix - CheckAttribute] <--
				ref findC = GetCharacter(ix);
				if(!CheckAttribute(findC,"corpse") && findC.name != "A " && findC.name != attack.name)// if bystander is neither corpse, barricade or shooter himself...
				{
					LAi_CharacterFireExecute(attack, findC, kDist, isFindedEnemy);//... shooting is executed with bystander as new target
					break;
				}
			}
		}
		else
		{
			LAi_CharacterFireExecute(attack, enemy, kDist, isFindedEnemy);	// unchanged targetdata passed on
		}
	}
	else LAi_CharacterFireExecute(attack, enemy, kDist, isFindedEnemy);	// unchanged targetdata passed on
}


void LAi_CharacterFireExecute(aref attack, aref enemy, float kDist, int isFindedEnemy)
	// ccc jul 05 Former LAi_CharacterFire() function minus the EventData yielded by the original targeting process
	// Shooting can now also be executed from other functions with other data
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	//ccc aref attack = GetEventData();
	//ccc aref enemy = GetEventData();
	//ccc float kDist = GetEventData();
	//ccc int isFindedEnemy = GetEventData();
	//Заряд персонажа
	if(!CheckAttribute(attack, "chr_ai.charge")) attack.chr_ai.charge = "0";
	float charge = stf(attack.chr_ai.charge) - 1.0;
	if(charge <= 0.0)
	{
		charge = 0.0;
		attack.chr_ai.chargeprc = "1";
	}
	attack.chr_ai.charge = charge;
	//Если промахнулись, то ничего не делаем

//JRH moved up block from below
	string weaponID = GetCharacterEquipByGroup(attack,GUN_ITEM_TYPE);	// defines weaponname
	aref weapon;
	Items_FindItem(weaponID, &weapon);	// defines object for weaponattributes

	float u, v, w;          		//JRH coordinates for effects
	GetCharacterPos(attack, &u, &v, &w);    //JRH determines position of initial target

	float x, y, z;          		//JRH revolver effect
	GetCharacterPos(enemy, &x, &y, &z);

	float a, b, c;				//JRH for maquahuitl multidamage effects

	ref PChar = GetMainCharacter();		//JRH

	float ay;
	GetCharacterAy(attack, &ay);

	int inc;	//incense for pistolcenserD

	if(isFindedEnemy == 0)
	{
		//здесь можно поднимать тревогу в случае близкого выстрела

		//JRH added for rifles when firing at nothing:

		if(IsMainCharacter(attack))
		{
			if(GetAttribute(weapon,"model") == "musket")		PostEvent("mket_on_back", 1000, "i", attack);
			if(GetAttribute(weapon,"model") == "musketoon")		PostEvent("mtoon_on_back", 1000, "i", attack);
			if(GetAttribute(weapon,"model") == "musketB")		PostEvent("mketB_on_back", 1000, "i", attack);
			if(GetAttribute(weapon,"model") == "Arguebuse")		PostEvent("Arguebuse_on_back", 1000, "i", attack);
			if(GetAttribute(weapon,"model") == "blunder1_10")	PostEvent("bbuss_on_back", 1000, "i", attack);
			if(GetAttribute(weapon,"model") == "pistol13")		PostEvent("pistol13_on_back", 1000, "i", attack);
			if(GetAttribute(weapon,"model") == "LongRifle_C")	PostEvent("LongRifle_C_on_back", 1000, "i", attack);
			if(GetAttribute(weapon,"model") == "LongRifle_H")	PostEvent("LongRifle_H_on_back", 1000, "i", attack);
			if(GetAttribute(weapon,"model") == "LongRifle_W")	PostEvent("LongRifle_W_on_back", 1000, "i", attack);

			if(GetAttribute(weapon,"model") == "maquahuitl_cursed")
			{
				CreateParticleSystem("blast" , u, v+1.2, w, 0.0, 0.0, 0.0, sti(20) );		//effect on pchar
				PlaySound("NATURE\thunder1.wav");
			}

			if(GetAttribute(weapon, "id") == "pistolwhip")
			{
				PlaySound("OBJECTS\duel\whip.wav");
				weapon.model = "whip_out";
				RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
				EquipCharacterByItem(attack, "pistolwhip");
			
				LAi_QuestDelay("reset_whip_rolled_pchar", 1.0);
			}

			if(GetAttribute(weapon, "id") == "pistolbladeBB")
			{
				PlaySound("OBJECTS\duel\sword_wind.wav");
			}
		
			if(GetAttribute(weapon, "id") == "pistolcenserD")
			{
				inc = GetCharacterItem(attack, "incense");
				if(inc >= 1)
				{
					TakeNItems(attack,"incense", -1);
					PlaySound("OBJECTS\DUEL\censer.wav");
					GetCharacterPos(attack, &u, &v, &w);
					CreateParticleSystem("gunfire" , u, v+1.2, w, 0.0, 0.0, 0.0, sti(20) );
					attack.protection = "on";
					logit("ON");
					//PlaySound("OBJECTS\duel\chalice.wav");

					LAi_QuestDelay("pchar_protection_off", 3.0);

					inc = GetCharacterItem(attack, "incense");
					if(inc >= 1)
					{
						//ok
					}
					else
					{	
						RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
						TakeItemFromCharacter(attack, "pistolcenserD");
						GiveItem2Character(attack, "pistolcenserE");
						EquipCharacterByItem(attack, "pistolcenserE");

						if(IsMainCharacter(attack))
						{
							if(inc == 0) Log_SetStringToLog(TranslateString("","There is no Incense left"));
						}
					}
				}
			}
		
			if(IsCharacterPerkOn(attack, "Gunfighter") && attack.chr_ai.charge >= "2")
			{
				attack.chr_ai.charge = charge + 1.0;
			}
		}
		else
		{
			//OFFICERS & OTHER

			if(GetAttribute(weapon,"model") == "musket")		PostEvent("mket_on_back", 1000, "i", attack);
			if(GetAttribute(weapon,"model") == "musketoon")		PostEvent("mtoon_on_back", 1000, "i", attack);
			if(GetAttribute(weapon,"model") == "musketB")		PostEvent("mketB_on_back", 1000, "i", attack);
			if(GetAttribute(weapon,"model") == "Arguebuse")		PostEvent("Arguebuse_on_back", 1000, "i", attack);
			if(GetAttribute(weapon,"model") == "blunder1_10")	PostEvent("bbuss_on_back", 1000, "i", attack);
			if(GetAttribute(weapon,"model") == "pistol13")		PostEvent("pistol13_on_back", 1000, "i", attack);
			if(GetAttribute(weapon,"model") == "LongRifle_C")	PostEvent("LongRifle_C_on_back", 1000, "i", attack);
			if(GetAttribute(weapon,"model") == "LongRifle_H")	PostEvent("LongRifle_H_on_back", 1000, "i", attack);
			if(GetAttribute(weapon,"model") == "LongRifle_W")	PostEvent("LongRifle_W_on_back", 1000, "i", attack);

			if(GetAttribute(weapon, "id") == "pistolwhip")
			{
				PlaySound("OBJECTS\duel\whip.wav");
				weapon.model = "whip_out";
				RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
				EquipCharacterByItem(attack, "pistolwhip");
				Pchar.opc_whip = attack.id;
			
				LAi_QuestDelay("reset_whip_rolled_officer", 1.0);
			}
		}

		if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0)
		{
			LoadStorylineFile("", "SL_utils.c");	// PB: To Prevent Errors
			LAi_CharacterFireExecute_WR(attack, enemy, kDist, isFindedEnemy);
			return;
		}
		if(sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0)
		{
			LoadStorylineFile("", "SL_utils.c");	// PB: To Prevent Errors
			LAi_CharacterFireExecute_BUG(attack, enemy, kDist, isFindedEnemy);
			return;
		}
		if(sti(GetStorylineVar(FindCurrentStoryline(), "BART_PUZZLES")) > 0)
		{
			LoadStorylineFile("", "SL_utils.c");	// PB: To Prevent Errors
			LAi_CharacterFireExecute_BART(attack, enemy, kDist, isFindedEnemy);
			return;
		}

		return;
	}
//<-- JRH

	// end of unchanged original code

	//skillearning(attack, "Fencing", 1);	// ccc skillearning

	// ccc special weapon assembly kit start
	// note: the function we are in here runs if a character (refered to as "attack") uses a gun AND has a targetcharacter ("enemy") in range

	bool CheckHostile = true; // run LAi_Attacked etc. set-hostile code. NK 05-07-10
	bool SetHostile = true;
	string effects_to_play = "always"; // for selective playing of FX
	int i;

	//================================================================================================
	// JRH ammo mod --->

	int gp;
	int pb;
	int pg;
	int mb;
	int ca;
	int na;
	int ar;
	int ar2;
	int ro;
	int gpb;	//paper cartridges = gp + pb
	int cap;	//percussion caps
//	int inc;	//incense for pistolcenserD

	float dist = GetDistance2D(x, z, u, w);		//JRH revolver effect
	if (dist == 0.0) dist = 0.1;				// PB: Avoid "Divide by zero"
	float alpha = x - ((dist-1.6)*(x-u))/dist;
	float beta  = z - ((dist-1.6)*(z-w))/dist;

	string enemy_blade = GetCharacterEquipByGroup(enemy,BLADE_ITEM_TYPE);

	if (ENABLE_AMMOMOD == 1 )
	{
		if(IsMainCharacter(attack) || IsOfficer(attack)) // JRH fix oct 06: officer should consume ammo
		{
			//Log_SetStringToLog("PCHAR or OFFICER");

			if(GetCharacterIndex(attack.id)==GetMainCharacterIndex() && attack.location == "wr_ships")
			{
				if(CheckAttribute(attack,"quest.deck_position") && attack.quest.deck_position == "cannon")
				{
					ChangeCharacterAddressGroup(attack, "wr_ships", "goto", "fire");//if he's running away

					if(attack.quest.cannon_priming == "yes")
					{
						//LogIt("priming = yes");
						CreateParticleSystem("gunfire_red" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
						CreateParticleSystem("stars_fire" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
						PlaySound("OBJECTS\duel\GI_ValidClick.wav");

						attack.quest.cannon_priming = "no";
						//LogIt("cannon priming = " + attack.quest.cannon_priming);

						LAi_QuestDelay("guncrew_fire2", 0.5);
						return;
					}
					else
					{
						//LogIt("priming = no");
						LAi_SetPlayerType(attack);
						LAi_SetFightMode(attack, false);
						LAi_LocationFightDisable(&Locations[FindLocation("wr_ships")], true);
						return;
					}
				}

				if(CheckAttribute(attack,"quest.deck_position") && attack.quest.deck_position == "elsewhere")
				{
					LAi_SetPlayerType(attack);
					LAi_SetFightMode(attack, false);
					LAi_LocationFightDisable(&Locations[FindLocation("wr_ships")], true);
					return;		//just in case
				}
			}

			if(CheckAttribute(attack,"quest.wet_gp") && attack.quest.wet_gp == "yes")
			{
				weapon.misfunction22 = 100;
			}
			else weapon.misfunction22 = 0;

			switch(GetAttribute(weapon, "shottype"))
			{
				case "pg2":
					//for officers essentially
				
					gp = GetCharacterItem(attack, "gunpowder");
					pg = GetCharacterItem(attack, "pistolgrapes");
					if(gp >=2 && pg >= 2)
					{
						TakeNItems(attack,"gunpowder", -2);

						if(CheckAttribute(attack,"quest.wet_gp") && attack.quest.wet_gp == "yes")
						{
							//don't consume grapes
						}
						else TakeNItems(attack,"pistolgrapes", -2);	//shot!

						gp = GetCharacterItem(attack, "gunpowder");
						pg = GetCharacterItem(attack, "pistolgrapes");
						if(gp >=2 && pg >= 2)
						{
							//ok
						}
						else
						{
							if(IsMainCharacter(attack)) // JRH fix oct 06: moved back from LAi_fightparams
							{
								if(gp == 1) Log_SetStringToLog(TranslateString("","There is not enough Gunpowder"));
								if(pg == 1) Log_SetStringToLog(TranslateString("","There are not enough Grapeshots"));
								if(gp == 0) Log_SetStringToLog(TranslateString("","There is no Gunpowder left"));
								if(pg == 0) Log_SetStringToLog(TranslateString("","There are no Grapeshots left"));
							}
						}
					}
					else
					{
						weapon.misfunction21 = 100;	//misf needed to avoid normal pistol sound
						if(IsMainCharacter(attack))
						{
							if(gp == 1) Log_SetStringToLog(TranslateString("","There is not enough Gunpowder"));
							if(pg == 1) Log_SetStringToLog(TranslateString("","There are not enough Grapeshots"));
							if(gp == 0) Log_SetStringToLog(TranslateString("","There is no Gunpowder left"));
							if(pg == 0) Log_SetStringToLog(TranslateString("","There are no Grapeshots left"));

							if(GetAttribute(weapon,"model") == "musketoon")		PostEvent("mtoon_on_back", 1000, "i", attack);
							if(GetAttribute(weapon,"model") == "blunder1_10")	PostEvent("bbuss_on_back", 1000, "i", attack);
						}
					}
				break;

				case "na2": //SPECIAL QUEST AMMO: NAILS
					//for officers essentially
					if(IsOfficer(attack))
					{
						if(CheckAttribute(weapon,"model") && weapon.model == "musketoon_back")
						{
							PlaySound("OBJECTS\duel\reload1.wav");
							attack.chr_ai.charge = "1";

							return;
						}
					}

					gp = GetCharacterItem(attack, "gunpowder");
					na = GetCharacterItem(attack, "nails");
					if(gp >=2 && na >= 2)
					{
						TakeNItems(attack,"gunpowder", -2);

						if(CheckAttribute(attack,"quest.wet_gp") && attack.quest.wet_gp == "yes")
						{
							//don't consume grapes
						}
						else TakeNItems(attack,"nails", -2);	//shot!

						if(attack.id == "Jupiter")
						{
							RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
							RemoveCharacterEquip(characterFromID("Jupiter"), BLADE_ITEM_TYPE);
							TakeItemFromCharacter(characterFromID("Jupiter"), "pistolmtoon");
							GiveItem2Character(characterFromID("Jupiter"), "clubmusketoon");
							EquipCharacterByItem(characterFromID("Jupiter"), "clubmusketoon");

							LAi_QuestDelay("Jup_clubmtoon_equip_check", 0.1);	
						}

						gp = GetCharacterItem(attack, "gunpowder");
						na = GetCharacterItem(attack, "nails");
						if(gp >=2 && na >= 2)
						{
							//ok
						}
						else
						{
							if(IsMainCharacter(attack)) // JRH fix oct 06: moved back from LAi_fightparams
							{
								if(gp == 1) Log_SetStringToLog(TranslateString("","There is not enough Gunpowder"));
								if(na == 1) Log_SetStringToLog(TranslateString("","There are not enough Grapeshots"));
								if(gp == 0) Log_SetStringToLog(TranslateString("","There is no Gunpowder left"));
								if(na == 0) Log_SetStringToLog(TranslateString("","There are no Grapeshots left"));
							}
						}
					}
					else
					{
						weapon.misfunction21 = 100;	//misf needed to avoid normal pistol sound
						if(IsMainCharacter(attack))
						{
							if(gp == 1) Log_SetStringToLog(TranslateString("","There is not enough Gunpowder"));
							if(na == 1) Log_SetStringToLog(TranslateString("","There are not enough Grapeshots"));
							if(gp == 0) Log_SetStringToLog(TranslateString("","There is no Gunpowder left"));
							if(na == 0) Log_SetStringToLog(TranslateString("","There are no Grapeshots left"));
						}
					}
				break;

				case "mb":
					gp = GetCharacterItem(attack, "gunpowder");
					mb = GetCharacterItem(attack, "musketbullets");

					if(gp >=2 && mb >= 1)
					{
						TakeNItems(attack,"gunpowder", -2);

						if(CheckAttribute(attack,"quest.wet_gp") && attack.quest.wet_gp == "yes")
						{
							//don't consume bullets
						}
						else TakeNItems(attack,"musketbullets", -1);

						gp = GetCharacterItem(attack, "gunpowder");
						mb = GetCharacterItem(attack, "musketbullets");
						if(gp >=2 && mb >= 1)
						{
							//ok
						}
						else
						{
							if(IsMainCharacter(attack))
							{
								if(gp == 1) Log_SetStringToLog(TranslateString("","There is not enough Gunpowder"));
								if(gp == 0) Log_SetStringToLog(TranslateString("","There is no Gunpowder left"));
								if(mb == 0) Log_SetStringToLog(TranslateString("","There are no Musketbullets left"));
							}
						}
					}
					else
					{
						weapon.misfunction21 = 100;	//misf needed to avoid normal pistol sound
						if(IsMainCharacter(attack))
						{
							if(gp == 1) Log_SetStringToLog(TranslateString("","There is not enough Gunpowder"));
							if(gp == 0) Log_SetStringToLog(TranslateString("","There is no Gunpowder left"));
							if(mb == 0) Log_SetStringToLog(TranslateString("","There are no Musketbullets left"));

							if(GetAttribute(weapon,"model") == "musket")	PostEvent("mket_on_back", 1000, "i", attack);
							if(GetAttribute(weapon,"model") == "musketB")	PostEvent("mketB_on_back", 1000, "i", attack);
							if(GetAttribute(weapon,"model") == "Arguebuse")	PostEvent("Arguebuse_on_back", 1000, "i", attack);
						}
					}
				break;

				case "pg":
					gp = GetCharacterItem(attack, "gunpowder");
					pg = GetCharacterItem(attack, "pistolgrapes");
					if(gp >= 1 && pg >= 1)
					{
						TakeNItems(attack,"gunpowder", -1);

						if(CheckAttribute(attack,"quest.wet_gp") && attack.quest.wet_gp == "yes")
						{
							//don't consume grapes
						}
						else TakeNItems(attack,"pistolgrapes", -1);	//shot!

						gp = GetCharacterItem(attack, "gunpowder");
						pg = GetCharacterItem(attack, "pistolgrapes");
						if(gp >= 1 && pg >= 1)
						{
							//ok
							//additional sound for
							if(CheckAttribute(weapon, "id") && weapon.id == "Arguebuse")
							{
								PlaySound("OBJECTS\duel\pistol_musket2.wav");
								PlaySound("OBJECTS\duel\pistol_musket2.wav");
							}
						}
						else
						{
							if(IsMainCharacter(attack))
							{
								if(gp == 0) Log_SetStringToLog(TranslateString("","There is no Gunpowder left"));
								if(pg == 0) Log_SetStringToLog(TranslateString("","There are no Grapeshots left"));
							}
						}
					}
					else
					{
						weapon.misfunction21 = 100;	//misf needed to avoid normal pistol sound
						if(IsMainCharacter(attack))
						{
							if(gp == 0) Log_SetStringToLog(TranslateString("","There is no Gunpowder left"));
							if(pg == 0) Log_SetStringToLog(TranslateString("","There are no Grapeshots left"));
						}
					}
				break;

				case "pb2":
					gp = GetCharacterItem(attack, "gunpowder");
					pb = GetCharacterItem(attack, "pistolbullets");
					if(gp >=2 && pb >= 2)
					{
						TakeNItems(attack,"gunpowder", -2);

						if(CheckAttribute(attack,"quest.wet_gp") && attack.quest.wet_gp == "yes")
						{
							//don't consume grapes
						}
						else TakeNItems(attack,"pistolbullets", -2);	//shot!

						gp = GetCharacterItem(attack, "gunpowder");
						pb = GetCharacterItem(attack, "pistolbullets");
						if(gp >=2 && pb >= 2)
						{
							//ok
						}
						else
						{
							if(IsMainCharacter(attack)) // JRH fix oct 06: moved back from LAi_fightparams
							{
								if(gp == 1) Log_SetStringToLog(TranslateString("","There is not enough Gunpowder"));
								if(pb == 1) Log_SetStringToLog(TranslateString("","There are not enough Pistolbullets"));
								if(gp == 0) Log_SetStringToLog(TranslateString("","There is no Gunpowder left"));
								if(pb == 0) Log_SetStringToLog(TranslateString("","There are no Pistolbullets left"));

								if(GetAttribute(weapon,"model") == "pisto13") PostEvent("pistol13_on_back", 1000, "i", attack);
								if(GetAttribute(weapon,"model") == "LongRifle_C") PostEvent("LongRifle_C_on_back", 1000, "i", attack);
								if(GetAttribute(weapon,"model") == "LongRifle_H") PostEvent("LongRifle_H_on_back", 1000, "i", attack);
								if(GetAttribute(weapon,"model") == "LongRifle_W") PostEvent("LongRifle_W_on_back", 1000, "i", attack);
							}
						}
					}
					else
					{
						weapon.misfunction21 = 100;	//misf needed to avoid normal pistol sound
						if(IsMainCharacter(attack))
						{
							if(gp == 1) Log_SetStringToLog(TranslateString("","There is not enough Gunpowder"));
							if(pb == 1) Log_SetStringToLog(TranslateString("","There are not enough Pistolbullets"));
							if(gp == 0) Log_SetStringToLog(TranslateString("","There is no Gunpowder left"));
							if(pb == 0) Log_SetStringToLog(TranslateString("","There are no Pistolbullets left"));
						}
					}
				break;

				case "pb":
					gp = GetCharacterItem(attack, "gunpowder");
					pb = GetCharacterItem(attack, "pistolbullets");
					if(gp >= 1 && pb >= 1)
					{
						TakeNItems(attack,"gunpowder", -1);

						if(CheckAttribute(attack,"quest.wet_gp") && attack.quest.wet_gp == "yes")
						{
							//don't consume bullets
						}
						else TakeNItems(attack,"pistolbullets", -1);	//shot!

						gp = GetCharacterItem(attack, "gunpowder");
						pb = GetCharacterItem(attack, "pistolbullets");
						if(gp >= 1 && pb >= 1)
						{
							//ok
						}
						else
						{
							if(IsMainCharacter(attack))
							{
								if(gp == 0) Log_SetStringToLog(TranslateString("","There is no Gunpowder left"));
								if(pb == 0) Log_SetStringToLog(TranslateString("","There are no Pistolbullets left"));
							}
						}
					}
					else
					{
						weapon.misfunction21 = 100;	//misf needed to avoid normal pistol sound
						if(IsMainCharacter(attack))
						{
							if(gp == 0) Log_SetStringToLog(TranslateString("","There is no Gunpowder left"));
							if(pb == 0) Log_SetStringToLog(TranslateString("","There are no Pistolbullets left"));
						}
					}
				break;

				case "pc":
					gpb = GetCharacterItem(attack, "cart_box_O");	//paper cartridges = gp + pb
					cap = GetCharacterItem(attack, "caps_box_O");	//percussion caps
					if(gpb >= 1 && cap >= 1)
					{
						TakeNItems(attack,"cart_box_O", -1);
						TakeNItems(attack,"caps_box_O", -1);	//also when wet
						
						Pchar.gpb_status = sti(Pchar.gpb_status) - 1;
						Pchar.cap_status = sti(Pchar.cap_status) - 1;
						
						if(CheckAttribute(weapon, "id") && weapon.id == "pistol204_P")
						{
							PlaySound("OBJECTS\duel\reload1.wav");
							PlaySound("OBJECTS\duel\reload1.wav");
						}

						gpb = GetCharacterItem(attack, "cart_box_O");
						cap = GetCharacterItem(attack, "caps_box_O");
						if(gpb >= 1 && cap >= 1)
						{
							//ok
						}
						else
						{
							if(IsMainCharacter(attack))
							{
								if(gpb == 0) Log_SetStringToLog(TranslateString("","There are no Paper Cartridges left"));
								if(cap == 0) Log_SetStringToLog(TranslateString("","There are no Percussion Caps left"));
							}
						}
					}
					else
					{
						weapon.misfunction21 = 100;	//misf needed to avoid normal pistol sound
						if(IsMainCharacter(attack))
						{
							if(gpb == 0) Log_SetStringToLog(TranslateString("","There are no Paper Cartridges left"));
							if(cap == 0) Log_SetStringToLog(TranslateString("","There are no Percussion Caps left"));
						}
					}
				break;

				case "ca":
					ca = GetCharacterItem(attack, "cartridges");
					if(ca >= 1)
					{
						TakeNItems(attack,"cartridges", -1);	//shot!
				//		PlaySound("OBJECTS\duel\ricoshet.wav");			//only at special occasion
			
						CreateParticleSystem("gunfire_revolver" , alpha, v+1.4, beta, alpha, v+1.4, beta, sti(20) );
						CreateParticleSystem("gunfire_revolver" , alpha, v+1.4, beta, alpha, v+1.4, beta, sti(20) );

						if(CheckAttribute(weapon, "id") && weapon.id == "revolver")
						{
							CreateParticleSystem("gunfire_small" , alpha, v+1.4, beta, alpha, v+1.4, beta, sti(20) );

							PlaySound("OBJECTS\duel\reload2.wav");
							PlaySound("OBJECTS\duel\reload2.wav");
						}

						ca = GetCharacterItem(attack, "cartridges");
						if(ca >= 1)
						{
							//ok
						}
						else
						{
							if(IsMainCharacter(attack))
							{
								if(ca == 0) Log_SetStringToLog(TranslateString("","There are no Cartridges left"));
							}
						}
					}
					else
					{
						weapon.misfunction21 = 100;	//misf needed to avoid normal pistol sound
						if(IsMainCharacter(attack))
						{
							if(ca == 0) Log_SetStringToLog(TranslateString("","There are no Cartridges left"));
						}
					}
				break;

				case "ar":
					ar = GetCharacterItem(attack, "bladearrows");
					if(ar >= 1)
					{
						RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );
						if(!CheckCharacterItem(attack, "bladeX4")) GiveItem2Character(attack, "bladeX4");
						EquipCharacterByItem(attack, "bladeX4");

						TakeNItems(attack,"bladearrows", -1);	//shot!

					   	if(CheckAttribute(enemy, "chr_ai.hp") && enemy.chr_ai.hp > 30)
					    {
							if(CheckCharacterItem(attack, "curare") && !LAi_IsPoison(enemy))
							{
								weapon.poison = 1; 
								TakeNItems(attack,"curare", -1);
							}
							else
							{
								if(CheckCharacterItem(attack, "tar"))
								{
									weapon.flaming = 1;
									TakeNItems(attack,"tar", -1);

									GetCharacterPos(attack, &u, &v, &w);
									GetCharacterPos(enemy, &x, &y, &z);
									CreateParticleSystem("gunfire_small" , alpha, v+1.4, beta, alpha, v+1.4, beta, sti(20) );
									CreateParticleSystem("gunfire_small" , alpha, v+1.4, beta, alpha, v+1.4, beta, sti(20) );

									Pchar.npc_flaming = enemy.id;

									LAi_QuestDelay("NPC_flaming_hit", 0.75);
								}
							}
						}
						
						if(!CheckAttribute(weapon, "flaming") || weapon.flaming != 1)
						{
							if(!bAllies(enemy) && rand(100) > 50)
							{
								ar = GetCharacterItem(enemy, "bladearrows");

								if(IsEquipCharacterByItem(enemy, "quiver") && ar < 12)
								{
									TakeNItems(enemy,"bladearrows", 1);
								}
								else
								{
									if(ar < 3) TakeNItems(enemy,"bladearrows", 1);
								}
							}
						}
					
						ar = GetCharacterItem(attack, "bladearrows");
						if(ar >= 1)
						{
							//ok
							if(IsMainCharacter(attack))
							{
								LAi_QuestDelay("equip_new_arrow", 1.5);
							}

							else
							{
								//officer
								Pchar.off_bow = attack.id;

								LAi_QuestDelay("off_equip_new_arrow", 0.75);
							}
						}
						else
						{
							if(IsMainCharacter(attack))
							{
								if(ar == 0) 
								{
									Log_SetStringToLog(TranslateString("","There are no Arrows left"));
									RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );
									EquipCharacterByItem(attack, FindCharacterItemByGroup(attack, BLADE_ITEM_TYPE));
								}
							}

							if(IsOfficer(attack))
							{
								if(ar == 0) 
								{
									RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );
									EquipCharacterByItem(attack, FindCharacterItemByGroup(attack, BLADE_ITEM_TYPE));
								}
							}
						}
					}
					else
					{
						//weapon.misfunction21 = 100;	//misf needed to avoid normal pistol sound
						if(IsMainCharacter(attack))
						{
							if(ca == 0) Log_SetStringToLog(TranslateString("","There are no Arrows left"));
						}
					}
				break;

				case "ar2":
					//poisoned small arrows for the blowgun
					ar2 = GetCharacterItem(attack, "arrows2");
					if(ar2 >= 1)
					{
						TakeNItems(attack,"arrows2", -1);	//shot!
			
						ar2 = GetCharacterItem(attack, "arrows2");
						if(ar2 >= 1)
						{
							//ok
						}
						else
						{
							if(IsMainCharacter(attack))
							{
								if(ar == 0) Log_SetStringToLog(TranslateString("","There are no Arrows left"));
							}
						}
					}
					else
					{
						//weapon.misfunction21 = 100;	//misf needed to avoid normal pistol sound
						if(IsMainCharacter(attack))
						{
							if(ar2 == 0) Log_SetStringToLog(TranslateString("","There are no Arrows left"));
						}
					}
				break;

				case "tb":
					if(GetAttribute(weapon, "id") == "pistolsteel")
					{
						if(IsEquipCharacterByItem(attack, "bladeflint"))
						{
							CreateParticleSystem("gunfire_red" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
							CreateParticleSystem("stars_fire" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
							PlaySound("OBJECTS\duel\GI_ValidClick.wav");
							PlaySound("OBJECTS\duel\steelflint.wav");

							if(CheckAttribute(attack, "filled_pipe") && attack.filled_pipe == "equipped")
							{
								LAi_SetStayType(attack);
								attack.filled_pipe = "none";
								RemoveCharacterEquip(attack, OUTFIT_ITEM_TYPE );
								TakeItemFromCharacter(attack, "filled_pipe");
								GiveItem2Character(attack, "empty_pipe");

								LAi_QuestDelay("smoking_mushrooms0", 1.0);//stops all sounds
								LAi_QuestDelay("smoking_mushrooms1", 2.0);
								LAi_QuestDelay("smoking_mushrooms4", 3.0);//new music starts
							}
						}
						else
						{
							PlaySound("VOICE\ENGLISH\blaze_hah.wav");
							Log_SetStringToLog(TranslateString("","I need a Flint too!"));
						}
					}
					else
					{
						//pistoltinderbox
						if(!CheckAttribute(attack,"quest.Legrands_parchment_place") && attack.quest.Legrands_parchment_place == "in_cauldron")
						{
							CreateParticleSystem("gunfire_red" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
							CreateParticleSystem("stars_fire" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
							PlaySound("OBJECTS\duel\GI_ValidClick.wav");
						}
					}

					return;
				break;

				case "ro":
					gp = GetCharacterItem(attack, "gunpowder");
					ro = GetCharacterItem(attack, "rockets");
					if(gp >= 3 && ro >= 1)
					{
						TakeNItems(attack,"gunpowder", -3);
						TakeNItems(attack,"rockets", -1);

						gp = GetCharacterItem(attack, "gunpowder");
						pb = GetCharacterItem(attack, "pistolbullets");
						if(gp >= 3 && ro >= 1)
						{
							//ok
						}
						else
						{
							if(IsMainCharacter(attack))
							{
								if(gp == 0) Log_SetStringToLog(TranslateString("","There is no Gunpowder left"));
								if(gp == 1 || gp == 2) Log_SetStringToLog(TranslateString("","There is not enough Gunpowder"));
								if(ro == 0) Log_SetStringToLog(TranslateString("","There are no Rockets left"));
							}
						}
					}
				break;

				case "pg6":
					//for hand cannon
				
					gp = GetCharacterItem(attack, "gunpowder");
					pg = GetCharacterItem(attack, "pistolgrapes");
					if(gp >=6 && pg >= 6)
					{
						TakeNItems(attack,"gunpowder", -6);

						if(CheckAttribute(attack,"quest.wet_gp") && attack.quest.wet_gp == "yes")
						{
							//don't consume grapes
						}
						else 
						{
							PlaySound("OBJECTS\SHIPCHARGE\CR24C.wav");
							PlaySound("OBJECTS\SHIPCHARGE\CR24C.wav");

							CreateParticleSystem("gunfire_red" , alpha, v+1.4, beta, 0.0, ay, 0.0, sti(20) );
							CreateParticleSystem("gunfire_red" , alpha, v+1.5, beta, 0.0, ay, 0.0, sti(20) );
							CreateParticleSystem("gunfire_red" , alpha, v+1.6, beta, 0.0, ay, 0.0, sti(20) );
							CreateParticleSystem("MMcancloud" , alpha, v+1.4, beta, 0.0, 0.0, 0.0, sti(20) );
							CreateParticleSystem("MMcancloud" , alpha, v+1.4, beta, 0.0, 0.0, 0.0, sti(20) );
							CreateParticleSystem("gunfire_small" , alpha, v+1.4, beta, 0.0, 0.0, 0.0, sti(20) );
							CreateParticleSystem("gunfire_small" , alpha-0.5, v+1.5, beta-0.5, 0.0, 0.0, 0.0, sti(20) );
							CreateParticleSystem("gunfire_small" , alpha-0.3, v+1.6, beta-0.3, 0.0, 0.0, 0.0, sti(20) );

							TakeNItems(attack,"pistolgrapes", -6);	//shot!
							LAi_ApplyCharacterDamage(attack, 10.0);
					//		LAi_SetPoorType(attack);
							LAi_QuestDelay("pchar_oh", 2.5);
					//		LAi_QuestDelay("recoil_sound", 2.5);
					//		LAi_QuestDelay("pchar_playertype", 5.0);
						}

						gp = GetCharacterItem(attack, "gunpowder");
						pg = GetCharacterItem(attack, "pistolgrapes");
						if(gp >=6 && pg >= 6)
						{
							//ok
						}
						else
						{
							if(IsMainCharacter(attack))
							{
								if(gp <= 5) 
								{	
									if(gp == 0) {Log_SetStringToLog(TranslateString("","There is no Gunpowder left"));}
									else Log_SetStringToLog(TranslateString("","There is not enough Gunpowder"));
								}
								if(pg <= 5) 
								{
									if(pg == 0) {Log_SetStringToLog(TranslateString("","There are no Grapeshots left"));}
									else Log_SetStringToLog(TranslateString("","There are not enough Grapeshots"));
								}
							}
						}
					}
					else
					{
						weapon.misfunction21 = 100;	//misf needed to avoid normal pistol sound
						if(IsMainCharacter(attack))
						{
							if(gp <= 5) Log_SetStringToLog(TranslateString("","There is not enough Gunpowder"));
							if(pg <= 5) Log_SetStringToLog(TranslateString("","There are not enough Grapeshots"));
							if(gp == 0) Log_SetStringToLog(TranslateString("","There is no Gunpowder left"));
							if(pg == 0) Log_SetStringToLog(TranslateString("","There are no Grapeshots left"));

						//	if(GetAttribute(weapon,"model") == "musketoon")		PostEvent("mtoon_on_back", 1000, "i", attack);
						//	if(GetAttribute(weapon,"model") == "blunder1_10")	PostEvent("bbuss_on_back", 1000, "i", attack);
						}
					}
				break;

				case "inc":
					//incense for pistolcenserD

					inc = GetCharacterItem(attack, "incense");
					if(inc >= 1)
					{
						TakeNItems(attack,"incense", -1);
						PlaySound("OBJECTS\DUEL\censer.wav");
						GetCharacterPos(attack, &u, &v, &w);
						CreateParticleSystem("gunfire" , u, v+1.2, w, 0.0, 0.0, 0.0, sti(20) );
						attack.protection = "on";
						logit("ON");
						//PlaySound("OBJECTS\duel\chalice.wav");

						LAi_QuestDelay("pchar_protection_off", 3.0);

						inc = GetCharacterItem(attack, "incense");
						if(inc >= 1)
						{
							//ok
						}
						else
						{	
							RemoveCharacterEquip(attack, GUN_ITEM_TYPE);
							TakeItemFromCharacter(attack, "pistolcenserD");
							GiveItem2Character(attack, "pistolcenserE");
							EquipCharacterByItem(attack, "pistolcenserE");

							if(IsMainCharacter(attack))
							{
								if(inc == 0) Log_SetStringToLog(TranslateString("","There is no Incense left"));
							}
						}
					}
				break;

				if(GetAttribute(weapon, "id") == "pistolmaquahuitl")
				{
					LAi_SetImmortal(enemy, false);
					CreateParticleSystem("blast" , u, v+1.2, w, 0.0, 0.0, 0.0, sti(20) );		//effect on pchar
					CreateParticleSystem("canfire2" , x, y+2.0, z, 5.1, y+1.2, 0.0, sti(20) );
					CreateParticleSystem("gunfire" , x, y+1.8, z, 0.0, 0.0, 0.0, sti(20) );//smoke puff
					PlaySound("NATURE\thunder1.wav");	//additional sound
				}

				if(GetAttribute(weapon, "id") == "LongRifle_BT")
				{
					PlaySound("OBJECTS\duel\pistol_big2.wav");
				}

				if(GetAttribute(weapon, "id") == "pistolwhip")
				{
					weapon.model = "whip_out";
					RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
					EquipCharacterByItem(attack, "pistolwhip");
		
					if(dist <= 3.0)
					{
						LAi_ApplyCharacterDamage(enemy, 5.0);
						GetCharacterPos(enemy, &x, &y, &z);
						CreateParticleSystem("blast_dirt_small" , x, y+1.2, z, 0.0, 0.0, 0.0, sti(20) );

						If(enemy_blade != "bladearrows" && enemy_blade != "bladeX4" && LAi_IsFightMode(enemy) && !IsMainCharacter(enemy) && !IsOfficer(enemy))
						{
							Pchar.npc_whip = enemy.id;
							int acc = makeint(attack.skill.Accuracy);
							int DisarmChance = acc + 2;
							if(DisarmChance > 9) DisarmChance = 9;

							if(rand(10) <= DisarmChance)
							{
								LAi_QuestDelay("delayed_disarm_sound", 0.5);
							}
						}
					}
			
					if(IsMainCharacter(attack)) 
					{
						LAi_QuestDelay("reset_whip_rolled_pchar", 1.0);
					}
					else
					{
						Pchar.opc_whip = attack.id;

						LAi_QuestDelay("reset_whip_rolled_officer", 1.0);
					}
				}

				if(GetAttribute(weapon, "id") == "pistolbladeBB")
				{
					if(dist <= 3.0)		//this value corresponds best to the range of a right hand blade
					{
						If(enemy_blade != "bladearrows" && enemy_blade != "bladeX4" && LAi_IsFightMode(enemy) && !IsMainCharacter(enemy) && !IsOfficer(enemy))
						{
							int fenc = makeint(enemy.skill.Fencing);
							int BlockChance = fenc + 2;
							if(BlockChance > 9) BlockChance = 9;

							if(rand(10) <= BlockChance)
							{
								//no dmg
								switch(rand(2))
								{
									case 0: PlaySound("OBJECTS\duel\sword_hit1.wav"); PlaySound("OBJECTS\duel\sword_wind.wav"); break;
									case 1: PlaySound("OBJECTS\duel\sword_hit2.wav"); PlaySound("OBJECTS\duel\sword_wind.wav"); break;
									case 2: PlaySound("OBJECTS\duel\sword_hit3.wav"); PlaySound("OBJECTS\duel\sword_wind.wav"); break;
								}
							}
							else
							{
								LAi_ApplyCharacterDamage(enemy, 22.0 + rand(15));
								switch(rand(2))
								{
									case 0: PlaySound("OBJECTS\duel\sword_inbody.wav"); break;
									case 1: PlaySound("OBJECTS\duel\sword_inbody.wav"); break;
									case 2: PlaySound("OBJECTS\duel\sword_inbody2.wav"); break;
								}
							}
						}

						if(!LAi_IsFightMode(enemy))
						{
							LAi_ApplyCharacterDamage(enemy, 22.0 + rand(15));
							switch(rand(2))
							{
								case 0: PlaySound("OBJECTS\duel\sword_inbody.wav"); break;
								case 1: PlaySound("OBJECTS\duel\sword_inbody.wav"); break;
								case 2: PlaySound("OBJECTS\duel\sword_inbody2.wav"); break;
							}
						}

						if(LAi_IsDead(enemy))
						{
							if(!IsOfficer(enemy)) LAi_KillCharacter(enemy);
						}
					}
					else 
					{
						PlaySound("OBJECTS\duel\sword_wind.wav");
					}

					return;		//yes: skips the extra 1 dmg always this way
				}
			}
		}
		else
		{
			//JRH added for NPC:s bows -->
			if(GetAttribute(weapon, "shottype") == "ar")
			{
				if(!IsEquipCharacterByItem(attack, "bladearrows"))
				{
					RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );
					if(CheckCharacterItem(attack, "tomahawk")) TakeItemFromCharacter(attack, "tomahawk");

					if(!CheckCharacterItem(attack, "bladearrows")) GiveItem2Character(attack, "bladearrows");
					EquipCharacterByItem(attack, "bladearrows");
				}

				if(IsEquipCharacterByItem(attack, "bladearrows"))
				{
					RemoveCharacterEquip(attack, BLADE_ITEM_TYPE );
					TakeItemFromCharacter(attack, "bladearrows");
					if(!CheckCharacterItem(attack, "bladeX4")) GiveItem2Character(attack, "bladeX4");
					EquipCharacterByItem(attack, "bladeX4");
			
			    	if(CheckAttribute(enemy, "chr_ai.hp") && enemy.chr_ai.hp > 30)
			    	{
						if(CheckCharacterItem(attack, "curare") && !LAi_IsPoison(enemy))
						{
							weapon.poison = 1; 
							TakeNItems(attack,"curare", -1);
						}
						else
						{
							if(CheckCharacterItem(attack, "tar"))
							{
								weapon.flaming = 1; 
								TakeNItems(attack,"tar", -1);

								GetCharacterPos(attack, &u, &v, &w);
								GetCharacterPos(enemy, &x, &y, &z);
								CreateParticleSystem("gunfire_small" , alpha, v+1.4, beta, alpha, v+1.4, beta, sti(20) );
								CreateParticleSystem("gunfire_small" , alpha, v+1.4, beta, alpha, v+1.4, beta, sti(20) );

								Pchar.npc_flaming = enemy.id;

								LAi_QuestDelay("NPC_flaming_hit", 0.75);
							}
						}
				   	}

					if(!CheckAttribute(weapon, "flaming") || weapon.flaming != 1)
					{
						if(bAllies(enemy) && rand(100) > 50) 
						{
							ar = GetCharacterItem(enemy, "bladearrows");

							if(IsEquipCharacterByItem(enemy, "quiver") && ar < 12)
							{
								TakeNItems(enemy,"bladearrows", 1);
							}
							else
							{
								if(ar < 3) TakeNItems(enemy,"bladearrows", 1);
							}
						}
					}

					Pchar.npc_bow = attack.id;

					LAi_QuestDelay("NPC_equip_new_arrow", 0.75);
				}
			}
			//<-- JRH added for NPC:s bows

			//JRH added for NPC:s rockets -->
			if(GetAttribute(weapon, "shottype") == "ro")
			{
				gp = GetCharacterItem(attack, "gunpowder");
				ro = GetCharacterItem(attack, "rockets");
				if(gp >= 3 && ro >= 1)
				{
					TakeNItems(attack,"gunpowder", -3);
					TakeNItems(attack,"rockets", -1);
				}
			}
			//<-- JRH added for NPC:s rockets
		
			if(GetAttribute(weapon, "id") == "pistollightning")
			{
				if(CheckAttribute(enemy, "protection") && enemy.protection == "off")
				{
					CreateParticleSystem("canfire2" , x, y+2.0, z, 5.1, y+1.2, 0.0, sti(20) );		//lightning
					PlaySound("OBJECTS\DUEL\electricity.wav");
					LAi_ApplyCharacterDamage(enemy, 10 + rand(10));
				}
			}
		}

		//this goes for all (mainchar, officers, NPC:s)
		if(GetAttribute(weapon, "id") == "pistolrocket")
		{
			CreateParticleSystem("rocket_fire" , alpha, v+1.4, beta, 0.0, ay, 0.0, sti(20) );
			CreateParticleSystem("gunfire_small" , alpha, v+1.4, beta, 0.0, 0.0, 0.0, sti(20) );

			if(IsMainCharacter(attack) || IsOfficer(attack) || IsOfficerType(attack))
			{
				Pchar.npc_rocket = enemy.id;
				
				LAi_QuestDelay("NPC_rocket_hit", 0.75);	
			}
			else
			{
				//is NPC	
				LAi_QuestDelay("pchar_rocket_hit", 0.75);
			}
		}

		if(weapon.id == "pistol13") PlaySound("OBJECTS\duel\pistol_medium3.wav");

		if(weapon.id == "pistolcenser")
		{
			CreateParticleSystem("gunfire" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );

			if(IsMainCharacter(attack) && enemy.id == "crypt_zombie1")
			{
				PlaySound("VOICE\ENGLISH\black_witch_disappear.wav");
				ChangeCharacterAddressGroup(characterFromID("crypt_zombie1"), "none", "", "");
				attack.crypt_zombie = "defeated";

				LAi_QuestDelay("close_crypt1_box", 1.5);
			}
		/*
			if(IsMainCharacter(attack))
			{
				attack.protection = "on";
				logit("ON");
				//PlaySound("OBJECTS\duel\chalice.wav");

				LAi_QuestDelay("pchar_protection_off", 3.0);
			}
		*/
		}

		if(weapon.id == "LongRifle_H" || weapon.id == "LongRifle_W" || weapon.id == "LongRifle_WT")
		{
			PlaySound("OBJECTS\duel\pistol_musket2.wav");
			PlaySound("OBJECTS\duel\pistol_musket2.wav");
		}
		if(CheckAttribute(weapon, "id"))
		{
			if(weapon.id == "LongRifle_C" || weapon.id == "LongRifle_CT")
			{
				PlaySound("OBJECTS\duel\pistol_big2.wav");
			}
		}
		
	}

	//click-shot, normally this will NOT show up, just in case
	//gun will not reload if gp or shot = 0 see LAi_fightparams & Character_utilite
	//mtoon & musket with not ENOUGH ammo will give a click-shot, and that is only if inventory is opened
	if(CheckAttribute(weapon, "misfunction21") && rand(100)<sti(weapon.misfunction21) )
	{
		CreateParticleSystem("gunfire_red" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
		CreateParticleSystem("stars_fire" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );
		LAi_CharacterPlaySound(attack, "OBJECTS\duel\GI_ValidClick.wav");//MAXIMUS

		weapon.misfunction21 = 0;

		//LanguageCloseFile(tmpLangFileID);
		return;
	}

// JRH ammo mod <---
//================================================================================================
 //JRH switch model & sound pistol20 (BB6) -->
	if(CheckAttribute(weapon, "id") && weapon.id == "pistol20")
	{
		if(CheckAttribute(weapon, "change") && weapon.change == 7 )
		{
			attack.chr_ai.charge = "6";
			attack.chr_ai.chargeprc = "0";//was 0
			weapon.change = 1;
		}

		if(CheckAttribute(weapon, "change") && weapon.change == 6 )
		{
			if(CheckAttribute(weapon, "misfunction22") && weapon.misfunction22 == 100 )
			{
				weapon.dmg_min = 0.0;
        			weapon.dmg_max = 0.0;
        			weapon.accuracy = 0;
			}
			else
			{
				weapon.dmg_min = 65.0;
        			weapon.dmg_max = 85.0;
        			weapon.accuracy = 75;
				PlaySound("OBJECTS\DUEL\pistol_musket.wav");
			}

			if(gp == 0 || pb == 0)
			{
				if(CheckAttribute(weapon, "misfunction22") && weapon.misfunction22 == 100 )
				{
					weapon.model = "pistol201_w";
				}
				else weapon.model = "pistol201";
				RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
				EquipCharacterByItem(attack, weaponID);

				attack.chr_ai.charge = "0";
				attack.chr_ai.chargeprc = "1";	//only one "1"
				weapon.change = 7;
			}
			else
			{
				if(CheckAttribute(weapon, "misfunction22") && weapon.misfunction22 == 100 )
				{
					weapon.model = "pistol201_w";
				}
				else weapon.model = "pistol201";
				RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
				EquipCharacterByItem(attack, weaponID);

				attack.chr_ai.charge = "0";
				attack.chr_ai.chargeprc = "1";
				weapon.change = 7;
			}
		}

		if(CheckAttribute(weapon, "change") && weapon.change == 5 )
		{
			if(CheckAttribute(weapon, "misfunction22") && weapon.misfunction22 == 100 )
			{
				weapon.dmg_min = 0.0;
        			weapon.dmg_max = 0.0;
        			weapon.accuracy = 0;
			}
			else
			{
				weapon.dmg_min = 50.0;
        			weapon.dmg_max = 67.5;
        			weapon.accuracy = 60;
				PlaySound("OBJECTS\duel\pistol_medium2.wav");
			}

			if(gp == 0 || pb == 0)
			{
				if(CheckAttribute(weapon, "misfunction22") && weapon.misfunction22 == 100 )
				{
					weapon.model = "pistol201_w";
				}
				else weapon.model = "pistol201";
				RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
				EquipCharacterByItem(attack, weaponID);

				attack.chr_ai.charge = "0";
				attack.chr_ai.chargeprc = "1";	//only one "1"
				weapon.change = 7;
			}
			else
			{
				if(CheckAttribute(weapon, "misfunction22") && weapon.misfunction22 == 100 )
				{
					weapon.model = "pistol206_w";
				}
				else weapon.model = "pistol206";
				RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
				EquipCharacterByItem(attack, weaponID);

				attack.chr_ai.charge = "1";
				attack.chr_ai.chargeprc = "0";
				weapon.change = 6;
			}
		}

		if(CheckAttribute(weapon, "change") && weapon.change == 4 )
		{
			if(CheckAttribute(weapon, "misfunction22") && weapon.misfunction22 == 100 )
			{
				weapon.dmg_min = 0.0;
				weapon.dmg_max = 0.0;
				weapon.accuracy = 0;
			}
			else
			{
				weapon.dmg_min = 40.0;
				weapon.dmg_max = 55.0;
				weapon.accuracy = 50;
				PlaySound("OBJECTS\duel\pistol_grape2.wav");
			}

			if(gp == 0 || pb == 0)
			{
				if(CheckAttribute(weapon, "misfunction22") && weapon.misfunction22 == 100 )
				{
					weapon.model = "pistol201_w";
				}
				else weapon.model = "pistol201";
				RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
				EquipCharacterByItem(attack, weaponID);

				attack.chr_ai.charge = "0";
				attack.chr_ai.chargeprc = "1";	//only one "1"
				weapon.change = 7;
			}
			else
			{
				if(CheckAttribute(weapon, "misfunction22") && weapon.misfunction22 == 100 )
				{
					weapon.model = "pistol205_w";
				}
				else weapon.model = "pistol205";
				RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
				EquipCharacterByItem(attack, weaponID);

				attack.chr_ai.charge = "2";
				attack.chr_ai.chargeprc = "0";
				weapon.change = 5;
			}
		}

		if(CheckAttribute(weapon, "change") && weapon.change == 3 )
		{
			if(CheckAttribute(weapon, "misfunction22") && weapon.misfunction22 == 100 )
			{
				weapon.dmg_min = 0.0;
				weapon.dmg_max = 0.0;
				weapon.accuracy = 0;
			}
			else
			{
				weapon.dmg_min = 60.0;
				weapon.dmg_max = 80.0;
				weapon.accuracy = 70;
				PlaySound("OBJECTS\duel\pistol_big2.wav");
			}

			if(gp == 0 || pb == 0)
			{
				if(CheckAttribute(weapon, "misfunction22") && weapon.misfunction22 == 100 )
				{
					weapon.model = "pistol201_w";
				}
				else weapon.model = "pistol201";
				RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
				EquipCharacterByItem(attack, weaponID);

				attack.chr_ai.charge = "0";
				attack.chr_ai.chargeprc = "1";	//only one "1"
				weapon.change = 7;
			}
			else
			{
				if(CheckAttribute(weapon, "misfunction22") && weapon.misfunction22 == 100 )
				{
					weapon.model = "pistol204_w";
				}
				else weapon.model = "pistol204";
				RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
				EquipCharacterByItem(attack, weaponID);

				attack.chr_ai.charge = "3";
				attack.chr_ai.chargeprc = "0";
				weapon.change = 4;
			}
		}

		if(CheckAttribute(weapon, "change") && weapon.change == 2 )
		{
			if(CheckAttribute(weapon, "misfunction22") && weapon.misfunction22 == 100 )
			{
				weapon.dmg_min = 0.0;
				weapon.dmg_max = 0.0;
				weapon.accuracy = 0;
			}
			else
			{
				weapon.dmg_min = 35.0;
				weapon.dmg_max = 50.0;
				weapon.accuracy = 40;
				PlaySound("OBJECTS\duel\pistol_small2.wav");
			}

			if(gp == 0 || pb == 0)
			{
				if(CheckAttribute(weapon, "misfunction22") && weapon.misfunction22 == 100 )
				{
					weapon.model = "pistol201_w";
				}
				else weapon.model = "pistol201";
				RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
				EquipCharacterByItem(attack, weaponID);

				attack.chr_ai.charge = "0";
				attack.chr_ai.chargeprc = "1";	//only one "1"
				weapon.change = 7;
			}
			else
			{
				if(CheckAttribute(weapon, "misfunction22") && weapon.misfunction22 == 100 )
				{
					weapon.model = "pistol203_w";
				}
				else weapon.model = "pistol203";
				RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
				EquipCharacterByItem(attack, weaponID);

				attack.chr_ai.charge = "4";
				attack.chr_ai.chargeprc = "0";
				weapon.change = 3;
			}
		}

		if(CheckAttribute(weapon, "change") && weapon.change == 1 )
		{
			if(CheckAttribute(weapon, "misfunction22") && weapon.misfunction22 == 100 )
			{
				weapon.dmg_min = 0.0;
				weapon.dmg_max = 0.0;
				weapon.accuracy = 0;
			}
			else
			{
				weapon.dmg_min = 50.0;
				weapon.dmg_max = 67.5;
				weapon.accuracy = 60;
				PlaySound("OBJECTS\duel\pistol_medium3.wav");
			}

			if(gp == 0 || pb == 0)
			{
				attack.chr_ai.charge = "0";
				attack.chr_ai.chargeprc = "1";	//only one "1"
				weapon.change = 7;
			}
			else
			{
				if(CheckAttribute(weapon, "misfunction22") && weapon.misfunction22 == 100 )
				{
					weapon.model = "pistol202_w";
				}
				else weapon.model = "pistol202";
				RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
				EquipCharacterByItem(attack, weaponID);

				attack.chr_ai.charge = "5";
				attack.chr_ai.chargeprc = "0";
				weapon.change = 2;
			}
		}
	}
   //<--JRH

   //JRH wet gunpowder -->
	if(CheckAttribute(weapon, "misfunction22") && weapon.misfunction22 == 100 )
	{
		Log_SetStringToLog(TranslateString("","Gunpowder must be wet!"));
		PlaySound("OBJECTS\duel\wet_gunpowder.wav");
		CreateParticleSystem("gunfire_black" , u, v+1.5, w, 0.0, 0.0, 0.0, sti(20) );

		//LogIt("misf 12 = " + weapon.misfunction12);
		return;
	}
   //<--JRH

   //JRH switch model trowing pistols -->
	if(CheckAttribute(weapon, "id") && weapon.id == "pistolthrow1")
	{
		RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
		TakeItemFromCharacter(attack, "pistolthrow1");
		GiveItem2Character(attack, "pistolbelt");
		EquipCharacterByItem(attack, "pistolbelt");
		GiveItem2Character(enemy, "pistol206");
	}

	if(CheckAttribute(weapon, "id") && weapon.id == "pistolthrow2")
	{
		RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
		TakeItemFromCharacter(attack, "pistolthrow2");
		GiveItem2Character(attack, "pistolthrow1");
		EquipCharacterByItem(attack, "pistolthrow1");
		GiveItem2Character(enemy, "pistol205");
	}

	if(CheckAttribute(weapon, "id") && weapon.id == "pistolthrow3")
	{
		RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
		TakeItemFromCharacter(attack, "pistolthrow3");
		GiveItem2Character(attack, "pistolthrow2");
		EquipCharacterByItem(attack, "pistolthrow2");
		GiveItem2Character(enemy, "pistol204");
	}

	if(CheckAttribute(weapon, "id") && weapon.id == "pistolthrow4")
	{
		RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
		TakeItemFromCharacter(attack, "pistolthrow4");
		GiveItem2Character(attack, "pistolthrow3");
		EquipCharacterByItem(attack, "pistolthrow3");
		GiveItem2Character(enemy, "pistol202");
	}

	if(CheckAttribute(weapon, "id") && weapon.id == "pistolthrow5")
	{
		RemoveCharacterEquip(attack, GUN_ITEM_TYPE );
		TakeItemFromCharacter(attack, "pistolthrow5");
		GiveItem2Character(attack, "pistolthrow4");
		EquipCharacterByItem(attack, "pistolthrow4");
		GiveItem2Character(enemy, "pistol201");
	}
    //<-- JRH
//================================================================================================
	if(CheckAttribute(weapon, "misfire") && rand(100)<sti(weapon.misfire) )
		// if a weapon can misfire & chance for that, as defined in items\itemsinit.c
	{
		if(attack.location != "BB_careen_shore")								//can give problems in WR2
		{
			Log_SetStringToLog(TranslateString("","Weapon misfired & blew up !"));
			Explosion (attack, rand(20));			// New "explosion" function hurts weaponuser
  			if(GetCharacterItem(attack, weaponID) <= 1) RemoveCharacterEquip(attack, weapon.groupID);	// unequips thrown weapon
               		TakeItemFromCharacter(attack, weaponID );	// deletes exploded weapon from inventory
			LAi_CharacterPlaySound(attack, "OBJECTS\duel\sword_fallen.wav");//MAXIMUS
			//LanguageCloseFile(tmpLangFileID);
			return;
		}
	}

	if(CheckAttribute(weapon, "id"))
	{
		if(weapon.id == "pistolmket" || weapon.id == "pistolmketB")
		{
			if(ENABLE_WEAKER_PISTOL_SOUNDS == 1)
			{
				PlaySound("OBJECTS\duel\pistol_musket2.wav");
			}
			else PlaySound("OBJECTS\duel\pistol_musket.wav");
		}
	}

	if( CheckAttribute(weapon, "sound" ) )
	{
		if (ENABLE_WEAKER_PISTOL_SOUNDS == 1)
		{
			//JRH
			Play3DSound(weapon.sound, u, v, w);
			Play3DSound(weapon.sound, u, v, w);
			Play3DSound(weapon.sound, u, v, w);
		}
		else 
		{
			if(GetAttribute(attack,"location") == "Tortuga_port" && !IsMainCharacter(attack) && !IsMainCharacter(enemy))
			{
				Play3DSound(weapon.sound, u, v, w);		//JRH
				Play3DSound(weapon.sound, u, v, w);
				Play3DSound(weapon.sound, u, v, w);
			}
			else PlaySound( weapon.sound );
		}
	} 
	else 
	{
		if(CheckAttribute(weapon, "id"))
		{
			if(weapon.id != "pistol20" && weapon.id != "holy_water") //JRH: not for these ones!
			{
				LAi_CharacterPlaySound(attack, "OBJECTS\duel\pistol_shot2.wav"); //MAXIMUS: otherwise normal pistolsound
			}
		}
	}

	int damagetoapply = 0;
	ref mainCh = GetMainCharacter();
	if( CheckAttribute(weapon, "multidmg" ) )	// next section runs only if chr near target shall be hurt
	{
		int num = FindNearCharacters(enemy, 2.5, -1.0, -1.0, 0.001, false, true);
			// checks if there are other people around the initial target. 2.5 is the checkradius

		//for(int j = 0; j <= num; j++)	// LDH no wonder this was getting people who weren't near: it included an extra character!
		for (int j = 0; j < num; j++)	// the following loop runs for each near character	// LDH fixed <=num - 08May09
		{
			int idx = -1;// MAXIMUS [fix for CheckAttribute]
			if(CheckAttribute(chrFindNearCharacters[j],"index")) idx = sti(chrFindNearCharacters[j].index);	// defines near character as idx
			if(idx == -1) continue;
			ref findCh;
			findCh = GetCharacter(idx);	// necessary? to get object for next line

			LAi_ApplyCharacterFireDamage(attack, &Characters[idx], kDist );
				// applies normal gunfire damage to near characters EXCEPT user & officers!

		//JRH-->
			if(CheckAttribute(weapon, "id") && weapon.id == "pistolmaquahuitl")
			{
				if(!IsMainCharacter(&Characters[idx]) || !IsOfficer(&Characters[idx]) )
				{
					GetCharacterPos(&Characters[idx], &a, &b, &c);
					CreateParticleSystem("canfire2" , a, b+2.0, c, 5.1, b+1.2, 0.0, sti(20) );
					CreateParticleSystem("gunfire" , a, b+1.8, c, 0.0, 0.0, 0.0, sti(20) );	//smoke puff
				}
			}
		//<--JRH

			if( CheckAttribute(weapon, "selfdmg" ) && findCh.id==attack.id)	// if user shall be hurt if too close
			{
				LAi_ApplyCharacterDamage( &Characters[idx], sti(weapon.dmg_min) );
					// applies minimumdamage of weapon to every near character, i.e. user also

				if(stf(attack.chr_ai.hp) < 1.0) attack.chr_ai.hp = 1 + makeint(rand(10));
					// jun05 so you dont kill yourself

				// LAi_CheckKillCharacter( &Characters[idx] );
					// checks if this has killed the character
			}

			if(CheckAttribute(weapon, "stun")&&!LAi_IsFightMode(&Characters[idx])&&findCh.chr_ai.group!=LAI_GROUP_PLAYER)
			 	// if weapon stuns victim; works only if victim is not prepared for fight and no playerassociate
			{
				int tduration = 100;
				if(CheckAttribute(weapon, "stun.duration")) tduration = sti(weapon.stun.duration);
				//MAXIMUS: during fight, character can join to his crew. Sometimes it may be helpful -->
				bool bPlayer = false;
				if(CheckAttribute(&findCh, "chr_ai.group") && findCh.chr_ai.group==LAI_GROUP_PLAYER)
				{
					if(sti(mainCh.skill.Leadership)>sti(findCh.skill.Leadership)) bPlayer = true;
				}
				else
				{
					if(sti(mainCh.skill.Leadership)<sti(findCh.skill.Leadership)) bPlayer = true;
				}
				LAi_Stunned_StunCharacter(&findCh, tduration, true, STUN_STARS, bPlayer);
				//MAXIMUS: during fight, character can join to his crew. Sometimes it may be helpful <--
			}

			if( CheckAttribute(weapon, "poison" ) ) 	// if weapon poisonous
			{
				findCh.chr_ai.poison =  300 ;	// poisons EVERY near character
				// NK play sound too 05-07-10
				if(findCh.sex == "woman") {LAi_CharacterPlaySound(findCh, "OBJECTS\Voices\dead\female\dead_wom2.wav");}	// groan
				else{LAi_CharacterPlaySound(findCh, "OBJECTS\Voices\dead\male\dead4.wav");}
			}
		}	// end of loop
		// NK do this below for GFX support
		damagetoapply = sti(weapon.dmg_min);
		/*LAi_ApplyCharacterDamage( enemy, sti(weapon.dmg_min) );
			// to ensure that initial target suffers minimumdamage, wasn't always the case
		LAi_CheckKillCharacter( enemy );
			// checks if this has killed the character*/

	}	// end of multidamage section

	if( CheckAttribute(weapon, "steal" ) && !LAi_IsFightMode(enemy) )
	 	// if weapon is a thief's tool; works only if victim is not prepared for fight
	{

		//skillearning(attack, "sneak", 1);	// ccc skillearning
		CheckHostile = false;
		LAi_AttemptSteal(attack, enemy, weapon); // NK do this in one function. 05-07-10
	}

	if( CheckAttribute(weapon, "stun" ) && !LAi_IsFightMode(enemy) && enemy.chr_ai.group != LAI_GROUP_PLAYER )
	 	// if weapon stuns victim; works only if victim is not prepared for fight and no playerassociate
	{

		//skillearning(attack, "sneak", 1);	// ccc skillearning
		if(frnd() < stf(weapon.stun)*GetAttackLuckMod(&attack))	// jun 05 stun doesnt work always anymore
		{
			int duration = 100;
			if(CheckAttribute(weapon, "stun.duration")) duration = sti(weapon.stun.duration);
				//MAXIMUS: during fight, character can join to his crew. Sometimes it may be helpful -->
				bPlayer = false;
				if(CheckAttribute(enemy, "chr_ai.group") && enemy.chr_ai.group==LAI_GROUP_PLAYER)
				{
					if(sti(mainCh.skill.Leadership)>sti(GetAttribute(enemy, "skill.Leadership"))) bPlayer = true;
				}
				else
				{
					if(sti(mainCh.skill.Leadership)<sti(GetAttribute(enemy, "skill.Leadership"))) bPlayer = true;
				}
				LAi_Stunned_StunCharacter(enemy, duration, true, STUN_STARS, bPlayer);
				//MAXIMUS: during fight, character can join to his crew. Sometimes it may be helpful <--
			//effects_to_play += " stun";
		}
	}

	if( CheckAttribute(weapon, "arrow" ) ) 	// checks if enemy got a shield
	{
		if(IsEquipCharacterByItem(enemy, "shield_hand"))
		{
			if(rand(100) > 50)
			{
				//protected by shield
				if(CheckAttribute(weapon, "id") && weapon.id == "blowgun")
				{
					LAi_QuestDelay("shield_stopped_dart", 0.5);
				}

				if(CheckAttribute(weapon, "id") && weapon.id == "pistolbow")
				{
					LAi_QuestDelay("shield_stopped_arrow", 0.5);
				}
				return;		//so poison (below) can't happen if shield stopped the dart
			}
		}
	}

	if( CheckAttribute(weapon, "poison" ) ) 	// if weapon poisonous
	{
		//JRH -->
		if(CheckAttribute(weapon, "id") && weapon.id == "blowgun")
		{
			if(!IsMainCharacter(attack))
			{ if(!CheckAttribute(attack, "chr_ai.poison" )) attack.poison_check = "no"; }
			
			if(!IsMainCharacter(enemy))
			{ if(!CheckAttribute(enemy, "chr_ai.poison" )) enemy.poison_check = "no"; }
		
			if(IsMainCharacter(enemy))
			{
				PlaySound("OBJECTS\Voices\dead\male\dead4.wav");
			 	enemy.chr_ai.curare =  1;			//slower poisoning for mainchar
				LAi_QuestDelay("pchar_curare", 1.0);
			}
			else
			{
				enemy.chr_ai.poison =  300 ;
				if(!CheckAttribute(weapon, "selfdmg" ) )
				{ attack.chr_ai.poison = 0 ;}
			}

			if(!IsMainCharacter(attack))
			{ if(CheckAttribute(attack,"poison_check") && attack.poison_check == "no") DeleteAttribute(attack, "poison"); }
				//so not poisoned attacker stays that way
	
			if(!IsMainCharacter(enemy))
			{ if(CheckAttribute(enemy,"poison_check") && enemy.poison_check == "no") DeleteAttribute(enemy, "poison"); }
				//so not poisoned enemy stays that way 
			
			if(!CheckAttribute(weapon, "selfdmg" ) )
			{ attack.chr_ai.poison = 0 ;}
		}
		//<-- JRH
		else
		{
			if(CheckAttribute(weapon, "id") && weapon.id == "pistolbow")
			{
				GetCharacterPos(enemy, &x, &y, &z);
				CreateParticleSystem("poison_green" , x, y+1.2, z, 0.0, 0.0, 0.0, sti(20) );	//JRH

				if(CheckAttribute(weapon, "id") && weapon.id == "pistolbow") DeleteAttribute(weapon, "poison");	//JRH reset
			}

			enemy.chr_ai.poison =  300 ;		// initial targetchr poisoned
	
			//if(enemy.sex == "man") {LAi_CharacterPlaySound(enemy, "OBJECTS\Voices\dead\male\dead4.wav");}	// groan
			//	else{LAi_CharacterPlaySound(enemy, "OBJECTS\Voices\dead\female\dead_wom2.wav");}

			if(IsMainCharacter(enemy))
			{
				if(enemy.sex == "man") {PlaySound("OBJECTS\Voices\dead\male\dead4.wav");}		//JRH: was very hard to hear at all
				else{PlaySound("OBJECTS\Voices\dead\male\Death_NPC_03.wav");}
			}
			else
			{
				if(enemy.sex == "man") {PlaySound("OBJECTS\DUEL\man_hit6.wav");}		//JRH: was very hard to hear at all
				else{PlaySound("OBJECTS\Voices\dead\female\dead_wom2.wav");}
			}

			if(!CheckAttribute(weapon, "selfdmg" ) )	// if user shall NOT ! be hurt if too close
			{ attack.chr_ai.poison = 0 ;}			// "UNpoisons" the user in this case
				// this may in rare cases heal the user from another poisoning, but I doubt that's a problem
		}

		effects_to_play += " poison";
	}

	if( CheckAttribute(weapon, "flaming" ) ) 	// if flaming arrows
	{
		if(CheckAttribute(weapon, "id") && weapon.id == "pistolbow") DeleteAttribute(weapon, "flaming"); 	//JRH reset
	}

	if(CheckHostile)
	{
		if(CheckAttribute(weapon, "stealth"))	// silent weapons don't alarm the victim, for others next line runs
		{
	          	if(frnd() < stf(weapon.stealth)*GetAttackLuckMod(&attack)) { SetHostile = false; }
			//MAXIMUS -->
			else
			{
				if(enemy.sex=="woman") LAi_CharacterPlaySound(enemy, "VOICE\" + LanguageGetLanguage() + "\Eng_f_c_001.wav");//woman voice - "Help, help me, please. I adjure..."
				else LAi_CharacterPlaySound(enemy, "VOICE\" + LanguageGetLanguage() + "\Fre_m_c_038.wav");//man voice - "Stay here! Who are you?"
			}
			PlaySound("AMBIENT\TOWN\Alarm.wav");
			//MAXIMUS <--
//			else { PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_067.wav"); } // sound alarm
		}
	}
	else SetHostile = false;

	if( CheckAttribute(weapon, "throw" ) && charge <= 1.0 )	// for weapons that you throw, so only onetime use
	{
		if(GetCharacterItem(attack, weaponID) <= 1) RemoveCharacterEquip(attack, weapon.groupID);	// unequips thrown weapon
		TakeItemFromCharacter(attack, weaponID );		// deletes thrown weapon from inventory
	}

	if( CheckAttribute(weapon, "throw_HW" ) && charge <= 1.0 )	// for weapons that you throw, so only onetime use
	{
		if(HasSubStr(enemy.id,"zombie"))
		{
			if(enemy.id == "zombie1")
			{
				Pchar.quest.zombie = "1";
				if(CheckAttribute(attack,"zombie1.temp.safe") && attack.zombie1.temp.safe == "yes")
				{
					LAi_QuestDelay("dont_throw_HW", 0.1);
					return;
				}
				else
				{
					PlaySound("OBJECTS\DUEL\holy_water.wav");
					if(GetCharacterItem(attack, weaponID) <= 1) RemoveCharacterEquip(attack, weapon.groupID);
					TakeItemFromCharacter(attack, weaponID );
				}
			}
			if(enemy.id == "zombie2")
			{
				Pchar.quest.zombie = "2";
				if(CheckAttribute(attack,"zombie2.temp.safe") && attack.zombie2.temp.safe == "yes")
				{
					LAi_QuestDelay("dont_throw_HW", 0.1);
					return;
				}
				else
				{
					PlaySound("OBJECTS\DUEL\holy_water.wav");
					if(GetCharacterItem(attack, weaponID) <= 1) RemoveCharacterEquip(attack, weapon.groupID);
					TakeItemFromCharacter(attack, weaponID );
				}
			}
			if(enemy.id == "zombie3")
			{
				Pchar.quest.zombie = "3";
				if(CheckAttribute(attack,"zombie3.temp.safe") && attack.zombie3.temp.safe == "yes")
				{
					LAi_QuestDelay("dont_throw_HW", 0.1);
					return;
				}
				else
				{
					PlaySound("OBJECTS\DUEL\holy_water.wav");
					if(GetCharacterItem(attack, weaponID) <= 1) RemoveCharacterEquip(attack, weapon.groupID);
					TakeItemFromCharacter(attack, weaponID );
				}
			}
			if(enemy.id == "zombie4")
			{
				Pchar.quest.zombie = "4";
				if(CheckAttribute(attack,"zombie4.temp.safe") && attack.zombie4.temp.safe == "yes")
				{
					LAi_QuestDelay("dont_throw_HW", 0.1);
					return;
				}
				else
				{
					PlaySound("OBJECTS\DUEL\holy_water.wav");
					if(GetCharacterItem(attack, weaponID) <= 1) RemoveCharacterEquip(attack, weapon.groupID);
					TakeItemFromCharacter(attack, weaponID );
				}
			}
			if(enemy.id == "zombie5")
			{
				Pchar.quest.zombie = "5";
				if(CheckAttribute(attack,"zombie5.temp.safe") && attack.zombie5.temp.safe == "yes")
				{
					LAi_QuestDelay("dont_throw_HW", 0.1);
					return;
				}
				else
				{
					PlaySound("OBJECTS\DUEL\holy_water.wav");
					if(GetCharacterItem(attack, weaponID) <= 1) RemoveCharacterEquip(attack, weapon.groupID);
					TakeItemFromCharacter(attack, weaponID );
				}
			}
			if(enemy.id == "zombie6")
			{
				Pchar.quest.zombie = "6";
				if(CheckAttribute(attack,"zombie6.temp.safe") && attack.zombie6.temp.safe == "yes")
				{
					LAi_QuestDelay("dont_throw_HW", 0.1);
					return;
				}
				else
				{
					PlaySound("OBJECTS\DUEL\holy_water.wav");
					if(GetCharacterItem(attack, weaponID) <= 1) RemoveCharacterEquip(attack, weapon.groupID);
					TakeItemFromCharacter(attack, weaponID );
				}
			}

			LAi_QuestDelay("holy_water_on_zombie", 1.0);
		}
	}

	//Реакция груп на атаку
	// ccc LAi_group_Attack(attack, enemy);	// line moved into "stealth" section

	// ccc particle effects, runs only if effect defined  in inititems.c
	LAi_PlayHitGFX(attack, enemy, weapon, effects_to_play); // NK do in centralized function 05-07-10


	//Начисление повреждений
	//jul 05 tools don't do damage. NK multidmg to target chr still is done, but is done direct, not with firedamage
	if( !CheckAttribute(weapon, "multidmg" ) && !CheckAttribute(weapon, "tool") ) { LAi_ApplyCharacterFireDamage(attack, enemy, kDist); }
	else // NK except we need to apply multidmg to the target chr _after_ the GFX or the GFX won't have a character to get position from.
	{
		if(damagetoapply > 0) // i.e. is multidmg after all
		{
			LAi_ApplyCharacterDamage( enemy, damagetoapply );
			// to ensure that initial target suffers minimumdamage, wasn't always the case

			// ccc sep05, keeps player & officers barely alive
			if(stf(enemy.chr_ai.hp)<1.0 && enemy.chr_ai.group==LAI_GROUP_PLAYER) enemy.chr_ai.hp = MIN_GUNATTACK_HP;

			LAi_CheckKillCharacter( enemy );
			// checks if this has killed the character
		}
	}
//JRH -->
	if(CheckAttribute(attack,"quest.kill_mistress") && attack.quest.kill_mistress == "yes")
	{
		LAi_KillCharacter(characterFromID("Mistress"));
		PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom5.wav");
	}
//<-- JRH
	if(SetHostile) // if we are setting enemy hostile to us (and haven't yet)
	{
		if(!LAi_IsDead(enemy)) { LAi_group_Attack(attack, enemy); } // if not dead, alarm!
		else // otherwise...
		{
			// for now, just behave like normal. When I have a chance, I'll check near characters vs. see/hear radius.
			//int num = FindNearCharacters(enemy, float rad, float ax, float testAng, float nearDist, bool isVisibleTest, bool isSort)
			LAi_group_Attack(attack, enemy);
		}
	}
	// ccc special weapon assembly kit end

	// PB -->
	if(LAi_IsDead(enemy) && GetAttribute(attack, "chr_ai.group") == LAI_GROUP_PLAYER)
	{
		//if you killed a merchant
		if(CheckAttribute(enemy, "itemtrade"))
		{
			if(attack.location == "wr_ships" || attack.location == "wr_gall_captain") return; //JRH
			MerchantGuildAttack(enemy, true);
		}

		SoldierReinforcements(enemy); //if you killed a town guard
	}
	// PB <--

	// unchanged code begins:

	//Исполнение типа
	string func = attack.chr_ai.type;
	if(func == "") return;
	func = "LAi_type_" + func + "_Fire";
	call func(attack, enemy, kDist, isFindedEnemy != 0);
	//Обновим цель сразу
	LAi_group_UpdateTargets(enemy);
	func = enemy.chr_ai.type;
	if(func == "") return;
	func = "LAi_type_" + func + "_Attacked";
	call func(enemy, attack);
	func = "LAi_type_" + enemy.chr_ai.type + "_CharacterUpdate";
	call func(enemy, 0.0001);

    //JRH switch rifles -->
	if(IsEquipCharacterByItem(attack, "pistolmket")) 
	{
		if(CheckCharacterItem(attack, "blade_mKnife"))
		{
			PostEvent("mketK_as_blade", 1000, "i", attack);
		}
		else
		{
			PostEvent("mket_on_back", 1000, "i", attack);
			PostEvent("mguns_fight_check", 1000, "i", attack);
		}
	}

	if(IsEquipCharacterByItem(attack, "pistolmtoon"))
	{
		PostEvent("mtoon_on_back", 1000, "i", attack);
		PostEvent("mguns_fight_check", 1000, "i", attack);
	}

	if(IsEquipCharacterByItem(attack, "pistolmketB"))
	{
		PostEvent("mketB_as_blade", 1000, "i", attack);
	}

	if(IsEquipCharacterByItem(attack, "Arguebuse"))
	{
		PostEvent("Arguebuse_on_back", 1000, "i", attack);
		PostEvent("mguns_fight_check", 1000, "i", attack);
	}

	if(IsEquipCharacterByItem(attack, "pistolbbuss"))
	{
		PostEvent("bbuss_on_back", 1000, "i", attack);
		PostEvent("mguns_fight_check", 1000, "i", attack);
	}

	if(IsEquipCharacterByItem(attack, "pistol13"))
	{
		PostEvent("pistol13_on_back", 1000, "i", attack);
		PostEvent("mguns_fight_check", 1000, "i", attack);
	}

	if(IsEquipCharacterByItem(attack, "LongRifle_C"))
	{
		PostEvent("LongRifle_C_on_back", 1000, "i", attack);
		PostEvent("mguns_fight_check", 1000, "i", attack);
	}

	if(IsEquipCharacterByItem(attack, "LongRifle_H"))
	{
		PostEvent("LongRifle_H_on_back", 1000, "i", attack);
		PostEvent("mguns_fight_check", 1000, "i", attack);
	}

	if(IsEquipCharacterByItem(attack, "LongRifle_W"))
	{
		PostEvent("LongRifle_W_on_back", 1000, "i", attack);
		PostEvent("mguns_fight_check", 1000, "i", attack);
	}
    //<--- JRH switch rifles

	if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0) LAi_QuestDelay("pistol20_ammo_check", 0.1);		//JRH: see quest_reaction
}


bool LAi_tmp_return_bool;
bool LAi_CharacterIsFire()
{
	aref chr = GetEventData();
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//Исполнение
	func = "LAi_tmpl_" + func + "_IsFire";
	LAi_tmp_return_bool = call func(chr);
	return LAi_tmp_return_bool;
}

bool LAi_CharacterIsFight()
{
	aref chr = GetEventData();
	string func = chr.chr_ai.tmpl;
	if(func == "") return true; // KK
	//Исполнение
	func = "LAi_tmpl_" + func + "_IsFight";
	LAi_tmp_return_bool = call func(chr);
	return LAi_tmp_return_bool;
}

//==========================================================================================
//Escape events
//==========================================================================================

void LAi_CharacterEscapeSlide()
{
	//Параметры
	string endTask = GetEventData();
	aref chr = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterEscapeSlide") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//Исполнение
	func = "LAi_tmpl_" + func + "_EscapeSlide";
	call func(chr);
}

//==========================================================================================
//Collision events
//==========================================================================================

void LAi_CharacterColThreshold()
{
	//Параметры
	string endTask = GetEventData();
	aref chr = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_CharacterColThreshold") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//Исполнение
	func = "LAi_tmpl_" + func + "_ColThreshold";
	call func(chr);
}

//==========================================================================================
//Animation events
//==========================================================================================

void LAi_Character_EndAction()
{
	//Параметры
	aref chr = GetEventData();
	if(LAi_CheckCharacter(chr, "LAi_Character_EndAction") == false) return;
	string func = chr.chr_ai.tmpl;
	if(func == "") return;
	//Исполнение
	func = "LAi_tmpl_" + func + "_EndAction";
	call func(chr);
}


//==========================================================================================
//Dead event
//==========================================================================================

void LAi_Character_Dead_Process(aref chr)
{
	// PB: Blade Damage mod
	if(!IsMainCharacter(chr) && FindCharacterItemByGroup(chr, "bladeX4")) TakeItemFromCharacter(chr, "bladeX4");

// ccc building kit aug05 ; deletes "killed" buildings from location
	if(CheckAttribute(chr,"chr_ai.type") && chr.chr_ai.type == "Building") // TIH
	{
		Building_delete(loadedLocation, chr.lastname);

		// demolition effects
		float x, y, z;			// coordinates for effects...
		//get deathsite coords(the current coords of logoffed chr are different!)
		x=stf(chr.deathx);
		y=stf(chr.deathy);
		z=stf(chr.deathz);

		CreateParticleSystemX("blast_inv", x, y, z, x, y, z,0);	// effects at that pos
		CreateParticleSystemX("cancloud", x, y, z, x, y, z,20);
		CreateParticleSystemX("cancloud", x+5, y, z, x, y, z,20);
		CreateParticleSystemX("cancloud", x-5, y, z, x, y, z,20);
		CreateParticleSystemX("cancloud", x, y, z+5, x, y, z,20);
		CreateParticleSystemX("cancloud", x, y, z-5, x, y, z,20);

		PlaySound("OBJECTS\shipcharge\mast_fall3.wav");
		PlaySound("OBJECTS\shipcharge\hit_torock.wav");
	}
// ccc building kit end

	QuestGroupDeath(sti(chr.index)); // KK

// added by MAXIMUS [fix for Player dialog closed after anyone is dead] -->
	int tmpi = SendMessage(GetMainCharacter(),"ls",MSG_CHARACTER_EX_MSG,"FindDialogCharacter");
	if(CheckAttribute(chr,"index") && tmpi==sti(chr.index)) DialogExit();
// added by MAXIMUS [fix for Player dialog closed after anyone is dead] <--

	DeleteAttribute(chr, "donotshowXP"); // NK so XP is shown next time.
	// move logoff into if(), CORPSEMODE dependent.
	if(!IsMainCharacter(chr)) // MAXIMUS
	{
		//SCREWFACE : if a permanent crewmember is killed, his corpse disapear immediatly (don't remove that unless that will cause a bug)
		if(CORPSEMODE == 3 && !LAi_DoCORPEMODE(chr)) // NK persist original corpse 05-07-19 //GO Add Test for Quest that doesn't work with CORPSEMODE=3
		{
			LAi_GenerateFantomFromMe(chr);
			SetCharacterTask_Stay(chr);
			//PopCharacterTask(GetCharacter(sti(chr.index)));
			LAi_Stunned_MakeCorpse(chr);
			LAi_SetImmortal(chr, true);
		}
		else
		{
			if(CORPSEMODE!=2 && CORPSEMODE!=4 && !CheckAttribute(chr,"CORPSEMODE"))
			{//MAXIMUS: so, Maltese-corpse will always be lootable
				if(CheckAttribute(chr,"dialog.filename"))
				{
					if(chr.dialog.filename=="monk_dialog.c" || chr.dialog.filename=="Maltese_corpse_dialog.c") chr.CORPSEMODE = 4;
				}
			}
			int bCorpseMode = CORPSEMODE;
			if(CheckAttribute(chr,"CORPSEMODE") && sti(chr.CORPSEMODE)==4) bCorpseMode = 4;
			if(bCorpseMode<4 || CheckAttribute(chr,"makelocator")) { LAi_CharacterLogoff(chr); } //MAXIMUS: makes box from corpse with hand-icon in the top-left corner
			if(bCorpseMode==0)
				PostEvent("LAi_event_Character_Dead", 100, "l", sti(chr.index)); // MAXIMUS: corpse disappear
			else
				PostEvent("LAi_event_Character_Dead", 500, "l", sti(chr.index)); // ccc jul05 corpse, time chg from 10000. NK change to 500. Make part of corpsemode != 3. // KK
		}
		// NK do this in DeadEvent below: 05-07-13 - LAi_GenerateFantomFromMe(chr);
		// KK LAi_group_CheckGroupQuest(chr);
	}
	else
	{

		// PB: Immediately determine if you survive or die
		if (rand(100) + (makeint(chr.skill.Sneak)*3) >= DEATHRATE && !CheckQuestAttribute("disable_rebirth", true) && !bSuppressResurrection) // SJG
		{
			//ccc new survival section
			// KK -->
			string loc = "";
			if (CheckAttribute(chr, "location")) loc = chr.location;
			if (GetCharacterShipType(chr) != SHIP_NOTUSED) loc = GetCharacterShipLocation(chr);
			string TownID = GetBestTown(loc);
			// <-- KK
			
			if (TownID != "")
			{
				if(GetIslandIDFromTown(TownID) == "Redmond" && CheckAttribute(chr,"quest.Rdm_officiant") && chr.quest.Rdm_officiant == "Claire")
				{
					ResurrectingOfficiant = characterFromID("Redmond_officiant_jrh"); //JRH
				}
				else ResurrectingOfficiant = GetTownOfficiant(TownID);

				if (GetNationRelation2MainCharacter(GetTownNation(TownID)) == RELATION_ENEMY && CheckAttribute(ResurrectingOfficiant, "resurrection.shore") == true && FindLocation(ResurrectingOfficiant.resurrection.shore) > 0) {
					chr.location.from_sea = ResurrectingOfficiant.resurrection.shore;
					PlaceFleetNearShore(chr.location.from_sea);
				}
				if (chr.location.from_sea == "Muelle_shore_02") {
					chr.location.from_sea = "Muelle_port";
					PlaceFleetNearShore(chr.location.from_sea);
				}
				chr.NoSave.Resurrection = 1; // PB: Lock the main menu
			}
		}
	
		LAi_CharacterLogoff(chr);
// KK -->
		if (!LAi_IsBoardingProcess()) {
			PostEvent("LAi_event_GameOver", 5000, "s", "land");
		} else {
			if (bMutinyDeckStarted)
				PostEvent("LAi_event_GameOver", 5000, "s", "mutiny");
			else
				PostEvent("LAi_event_GameOver", 5000, "s", "boarding");
		}
// <-- KK
	}
}

#event_handler("LAi_event_Character_Dead", "LAi_Character_Dead_Event");
void LAi_Character_Dead_Event() // should never be run when CORPSEMODE == 3. NK 05-07-19
{
	int chridx = GetEventData(); // KK
	if (chridx < 0) return; // KK

	int tmpNameFileID = LanguageOpenFile("characters_names.txt");

	ref chr = GetCharacter(chridx); // KK

// changed by MAXIMUS 12.10.2006 -->
	bool bLoc = IsEntity(loadedLocation); // KK CheckAttribute(chr,"location")==true;
	// KK ref lcn;
	// KK if(bLoc) lcn = &Locations[FindLocation(chr.location)];	// determines where you are
// changed by MAXIMUS 12.10.2006 <--

	// TIH --> changed behavior Sep2'06
	bool DissolveBody = true;
	int bCorpseMode = CORPSEMODE;
	if(CheckAttribute(chr,"CORPSEMODE") && sti(chr.CORPSEMODE)==4) bCorpseMode = 4;

	if(bCorpseMode==1 || bCorpseMode==4) DissolveBody = false;//MAXIMUS
	if(LAi_IsBoardingProcess()==true && AUTOLOOT_BOARDINGS) DissolveBody = false;//MAXIMUS: excludes player's decks
// changed by MAXIMUS 12.10.2006 -->
	if(bLoc)
	{
		if(GetAttribute(loadedLocation, "abbey") == true && bCorpseMode<4)		DissolveBody = true; // TIH for maltese knight abbey // KK
		if(CheckAttribute(chr,"chr_ai.type") && chr.chr_ai.type == "Building")	DissolveBody = true; // PB: For BuildingSet characters
	}
// changed by MAXIMUS 12.10.2006 <--

	if (DissolveBody)
	{
		CharacterExitFromLocation(chr);
	}
	else
	{
		// we wont be clearing the old body nor making a new body, so we need to keep this one around
		// however we set it as a neutral entity so that the warning indicator will go out when all enemies are dead
		if(bCorpseMode<4)
		{
			LAi_group_MoveCharacter(chr, LAI_GROUP_CORPSES);
		}
		if(bCorpseMode<4 || CheckAttribute(chr,"makelocator")) { LAi_CharacterLogoff(chr); }//MAXIMUS
	}
	// TIH <--

	// original chr body disappears, put 'if(chr.name != "The late")' in front to keep corpses lying around after looting
	// ccc jul05 corpse for looting

// KK -->
	/*if (!CheckAttribute(chr, "name"))		// LDH added to prevent errors on dead captains
	{
		Trace("Warning: Invalid character in LAi_CharacterDeadEvent(), ignored");
		LanguageCloseFile(tmpLangFileID);
		LanguageCloseFile(tmpNameFileID);
		return;
	}*/
// <-- KK

	//Levis fix for corpsmode=2 -->
	bool makeCorpse;
	if(bCorpseMode==4){ makeCorpse = CheckAttribute(chr,"corpse")==true; }
	if(bCorpseMode==2){ makeCorpse = CheckAttribute(chr,"corpse")==true; }
	//Levis fix for corpsmode=2 <--
	if(!makeCorpse) makeCorpse = CheckAttribute(chr,"corpse")==false;
	if(makeCorpse && bCorpseMode!=3) // do not generate a corpse from a corpse
	{
		bool GenerateCorpse = true;
		if(CheckAttribute(chr,"sex") && chr.sex == "monkey") GenerateCorpse = false; // No corpses for monkeys
		if(GetAttribute(chr, "name")==LanguageConvertString(tmpNameFileID,"Crewmember") && bCorpseMode<4) GenerateCorpse = false; // No corpses for permanent crewmembers (Screwface) //MAXIMUS

	     //JRH -->
		if(CheckAttribute(chr,"location"))
		{
			if(chr.location == "wr_port")
			{
				chr.money = 0;
				TakenItems(chr, "gunpowder", -1);
				TakenItems(chr, "pistolbullets", -1);
			}

			if(chr.location == "Redmond_shipyard")
			{
				if(CheckAttribute(chr,"id") && chr.id == "wr_bochat")
				{
				 	chr.money = 30;
				}
				else chr.money = 0;
			}

			if(chr.location == "wr_shop")
			{
				if(CheckAttribute(chr,"id") && chr.id == "wr_oman1X")
				{
				 	chr.money = 30;
				}
				else chr.money = 0;

				if(CheckAttribute(chr,"id") && chr.id == "wr_fralut") {TakenItems(chr, "blade3carpets", -2);}
				if(CheckAttribute(chr,"id") && chr.id == "wr_mong") {TakenItems(chr, "bladebarrel", -1); TakenItems(chr, "pistolbarrel", -1);}
				if(CheckAttribute(chr,"id") && chr.id == "wr_pir4") {TakenItems(chr, "bladeglobe", -1);}
			}

			if(chr.location == "Charleston_shore")
			{
				if(CheckAttribute(chr,"id") && chr.id == "white_trash1")
				{
				 	chr.money = 0;
					TakenItems(chr, "Minersspade", -1);
				}
			}

			if(chr.location == "GB_Charleston_wine_cellar")
			{
				chr.money = 0;
				TakenItems(chr, "zombie_touch", -1);
				TakenItems(chr, "bladebone", -1);
			}

			if(chr.location == "Legrands_boathouse")
			{
				chr.money = 0;
				if(CheckAttribute(chr,"id"))
				{
					if(chr.id == "maroon1") chr.money = 4;
					if(chr.id == "maroon_girl") chr.money = 2;
					if(chr.id == "deserter_us1") chr.money = 1;
				}
			}

			if(chr.location == "Cloister_inside")
			{
				if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0)
				{
					DeleteAttribute(chr, "items");
					chr.money = 0;
				}
			}

			if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0 || sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0)
			{
				if(chr.location == "wr_wine_cellar") 
				{
					chr.money = 0;
					if(CheckAttribute(chr,"id") && chr.id == "wr_fatj") {TakenItems(chr, "bladebasket", -1);}
				}
				if(chr.location == "wr_ships" || chr.location == "wr_gall_captain" || chr.location == "wr_corv_capmd")
					ChangeCharacterAddressGroup(chr, "none", "", "");
			}
		}
	    //<-- JRH

		if(CheckAttribute(chr,"chr_ai.type") && chr.chr_ai.type == "Building") GenerateCorpse = false; // No corpses for buildings (ccc building kit Jan06)
		if(LAi_IsBoardingProcess()==true && AUTOLOOT_BOARDINGS && bCorpseMode<4) GenerateCorpse = false; // PB: No corpses during boardings - Instead automatic looting (at LDH's request) //MAXIMUS: excludes player's decks
		if(bCorpseMode!=2 && bCorpseMode<4) GenerateCorpse = false; // TIH only corpsemode 2 makes a lootable corpse Sep2'06
		// LDH 27Sep06 added CheckAttribute
// changed by MAXIMUS 12.10.2006 -->
		if(bLoc)
		{
			if(GetAttribute(loadedLocation, "abbey") == true) GenerateCorpse = true; // TIH for maltese knight abbey // KK
		}
// changed by MAXIMUS 12.10.2006 <--
		if(bCorpseMode==4 && CheckAttribute(chr,"makelocator")) 
		{ 
			DeleteAttribute(chr,"makelocator"); 
			CharacterExitFromLocation(chr); 
			GenerateCorpse = false; 
		}//MAXIMUS: for captains cabin
		if(GenerateCorpse)
		{
			if(bCorpseMode!=4) { LAi_GenerateFantomFromMe(chr); }// NK do this here 05-07-13 //MAXIMUS
			// ccc Nov 05 Greater Oxbay create ghosts in Maltese Abbey
			ref corpse, corpseLoc;
			int x, y, z, locNum;
			aref ito, ifrom, rootLocs;
			// TIH --> we make sure that no already looted items are transfered Sep2'06
			bool bPurgeLoot = false;
			string tempitm, newLocName;

			if(CheckAttribute(chr,"model") && chr.model == "Animists3")
			{
				if(bCorpseMode==4) { LAi_GenerateFantomFromMe(chr); } //MAXIMUS
				x = stf(chr.deathx);
				y = stf(chr.deathy);
				z = stf(chr.deathz);

				CreateParticleSystemX("fire_medium", x, y+2, z, x, y+2, z,2);	// effects at that pos
				If(USE_PARTICLES>0) CreateParticleSystemX("seafoam", x, y+1.5, z, x, y+2, z,2);	// ccc Dec05 tweak added
				If(USE_PARTICLES>1) CreateParticleSystemX("artifact", x, y+1.5, z, x, y+2, z,2);	// ccc Dec05 tweak added

				LAi_CharacterPlaySound(chr, "OBJECTS\VOICES\DEAD\skeleton\skeleton_dead01.wav");
				PlayStereoSound("AMBIENT\INCA TEMPLE\teleporter.wav");
				if(USE_PARTICLES>0) PlayStereoSound("NATURE\wind_tornado.wav");	// ccc Dec05 tweak added
				logit(TranslateString("","The weird monk reveals his true nature.."));

				corpse = LAi_CreateFantomCharacterEx(false, 3, true, false, 0.0, "skel2", "", "");
				GiveItem2Character(corpse, "blade8");
				EquipCharacterByItem(corpse, "blade8");
				LAi_SetWarriorType(corpse);
				LAi_group_MoveCharacter(corpse, LAI_GROUP_MONSTERS);
				LAi_group_SetRelation(LAI_GROUP_PLAYER, LAI_GROUP_MONSTERS, LAI_GROUP_ENEMY);
				corpse.name = LanguageConvertString(tmpNameFileID,"Maltese");
				corpse.lastname = LanguageConvertString(tmpNameFileID,"Knight");
				corpse.dialog.filename = "Maltese_corpse_dialog.c";
				corpse.humantype = "MalteseKnight";
				LAi_SetImmortal(corpse, false);
				if(bCorpseMode==4)
				{
					if(CheckAttribute(chr, "items"))
					{
						makearef(ifrom, chr.items);
						corpse.items = "";
						makearef(ito, corpse.items);
						CopyAttributes(&ito, &ifrom);
					}
					LAi_CharacterLogoff(chr);
					CharacterExitFromLocation(chr);

					TeleportCharacterToPosAY(corpse, stf(chr.deathx), stf(chr.deathy), stf(chr.deathz), stf(chr.deathay));
				}
			}
			else
			{
				// original corpsecreation
				if(bCorpseMode!=4)
				{
					corpse = LAi_CreateFantomCharacterEx(false, 0, false, false, 0.0, chr.model, "", "");
					corpse.corpse = true;
					LAi_SetImmortal(corpse, true);
					corpse.lastname = GetMyFullName(chr);
					//corpse.name = XI_ConvertString("The late");
					LAi_SetStunnedTypeNoGroup(corpse);
					LAi_group_MoveCharacter(corpse, LAI_GROUP_CORPSES);
					corpse.dialog.filename = "Corpse_dialog.c";
					if(CheckAttribute(corpse,"humantype") && corpse.humantype=="MalteseKnight") corpse.dialog.filename = "Maltese_corpse_dialog.c";
					DeleteAttribute(corpse, "items");
					if(AUTOLOOT_ON)															bPurgeLoot = true;
					if(bAbordageStarted && AUTOLOOT_BOARDINGS)								bPurgeLoot = true;
					if(sti(GetStorylineVar(FindCurrentStoryline(), "WR_PUZZLES")) > 0)		bPurgeLoot = false; // JRH
					if(sti(GetStorylineVar(FindCurrentStoryline(), "BUG_PUZZLES")) > 0)		bPurgeLoot = false; // JRH
					if(CheckAttribute(chr, "items"))
					{
						if(bPurgeLoot)
						{
							tempitm = "";
							tempitm = GetCharacterEquipByGroup(chr,BLADE_ITEM_TYPE);
							if (tempitm != "") TakeItemFromCharacter(chr, tempitm);
							tempitm = GetCharacterEquipByGroup(chr,GUN_ITEM_TYPE);
							if (tempitm != "") TakeItemFromCharacter(chr, tempitm);
						}
						makearef(ifrom, chr.items);
						corpse.items = "";
						makearef(ito, corpse.items);
						CopyAttributes(&ito, &ifrom);
					}
					TeleportCharacterToPosAY(corpse, stf(chr.deathx), stf(chr.deathy), stf(chr.deathz), stf(chr.deathay));
					if(CORPSE_AUTODISAPPEAR>0 && bCorpseMode!=1)//MAXIMUS: if(CORPSEMODE==1) - corpse must stay in location till player will leave this place
					{
						if(bCaptureShip==true) PostEvent("LAi_RemoveCorpse", 100, "i", corpse);
						else PostEvent("LAi_RemoveCorpse", CORPSE_AUTODISAPPEAR, "i", corpse);
					}
				}// NK added Friend, turned off genrank. 05-07-10//MAXIMUS
				else
				{
					corpse = CharacterFromId(chr.id);
					LAi_group_MoveCharacter(corpse, LAI_GROUP_CORPSES);
					//MAXIMUS: makes box from corpse with hand-icon in the top-left corner -->
					locNum = FindLocation(corpse.location);
					if (locNum > -1) // PB: Prevent error.log entries
					{
						corpseLoc = &Locations[locNum];
						locNum = 1;
						if(CheckAttribute(corpseLoc,"locators.box"))
						{
							rootLocs; makearef(rootLocs, corpseLoc.locators.box);
							locNum = GetAttributesNum(rootLocs)+1;
						}
						newLocName = "corpse_box"+locNum;
						WriteLocatorGlobal(corpse.location, "box", newLocName, TranslateString("","body_of_"+corpse.sex)+" "+GetMySimpleName(corpse), sti(corpse.index), stf(corpse.deathx), stf(corpse.deathy), stf(corpse.deathz), true);
					}
					//MAXIMUS: makes box from corpse with hand-icon in the top-left corner <--
				}// KK -->
				tempitm = GetCharacterEquipByGroup(corpse, BLADE_ITEM_TYPE);
				if (tempitm != "") corpse.old.blade = tempitm;
				tempitm = GetCharacterEquipByGroup(corpse, GUN_ITEM_TYPE);
				if (tempitm != "") corpse.old.gun = tempitm;// <-- KK
			}
			if(CheckAttribute(chr,"CORPSEMODE")) corpse.CORPSEMODE = chr.CORPSEMODE;
			if(bPurgeLoot) chr.money = 0;// TIH if already looted, make sure there is no money Sep2'06
			if(!CheckAttribute(chr,"money")) { chr.money = 0; }//MAXIMUS: for missed attribute
			corpse.money = chr.money;
			// KK LAi_group_CheckGroupQuest(chr);
		}
	}
	LanguageCloseFile(tmpNameFileID);
// ccc jul05 corpse end
}

// added by MAXIMUS [corpses are automatic disappear from location] -->
#event_handler("LAi_RemoveCorpse", "LAi_CleanCorpses");
void LAi_CleanCorpses()
{
	aref corpse = GetEventData();
// LDH -->  Keeps corpses from disappearing while we're in a dialog which breaks the dialog and can kill a quest.
	if(CheckAttribute(GetMainCharacter(), "IsInDialog"))
	{
		if (CORPSE_AUTODISAPPEAR > 0)	// Defensive programming, in case logic is changed elsewhere
			PostEvent("LAi_RemoveCorpse", CORPSE_AUTODISAPPEAR, "i", corpse);
		else
			PostEvent("LAi_RemoveCorpse", 500, "i", corpse);
		return;
	}
// LDH <--
	if(LAi_IsImmortal(corpse)) Lai_KillCharacter(corpse);
}
// added by MAXIMUS [corpses are automatic disappear from location] <--

#event_handler("LAi_event_GameOver", "LAi_GameOver");
void LAi_GameOver()
{
	string str = GetEventData();
	GameOver(str);
}



//==========================================================================================
//Internal events
//==========================================================================================

//------------------------------------------------------------------------------------------
//Сообщение об окончании работы темплейта
//------------------------------------------------------------------------------------------

void LAi_Character_TemplateComplite(aref chr, string tmplName)
{

	int index = sti(chr.index);
	PostEvent("LAi_event_Character_TemplateComplite", 1, "ls", index, tmplName);

}

#event_handler("LAi_event_Character_TemplateComplite", "LAi_Character_TemplateComplite_Event");
void LAi_Character_TemplateComplite_Event()
{
	int index = GetEventData();
	string tmpl = GetEventData();
	ref chr = &Characters[index];
	if (!CheckAttribute(chr, "chr_ai.type")) return;		// LDH - fix for missing chr 20AUG06 [MAXIMUS fix - was (chr, "chr_ai")]
	string func = chr.chr_ai.type;
	if(func != "")
	{
		func = "LAi_type_" + func + "_TemplateComplite";
		call func(chr, tmpl);
	}
}

//------------------------------------------------------------------------------------------
//Запрос локатора
//------------------------------------------------------------------------------------------

void LAi_Character_FreeLocator(aref chr, string group, string locator)
{
	int index = sti(chr.index);
	PostEvent("LAi_event_Character_FreePos", 1, "lss", index, group, locator);
}

#event_handler("LAi_event_Character_FreePos", "LAi_Character_FreePos_Event");
void LAi_Character_FreePos_Event()
{
	int index = GetEventData();
	string group = GetEventData();
	string locator = GetEventData();
	for(int i = 0; i < LAi_numloginedcharacters; i++)
	{
		int idx = LAi_loginedcharacters[i];
		if(idx >= 0)
		{
			if(idx != index)
			{
				float dist;
				if(GetCharacterDistByLoc(&Characters[idx], group, locator, dist))
				{
					if(dist < 0.8)
					{
						string func = Characters[idx].chr_ai.tmpl;
						if(func == "") return;
						//Исполнение
						func = "LAi_tmpl_" + func + "_FreePos";
						call func(&Characters[idx], &Characters[index]);
					}
				}
			}
		}
	}
}


//------------------------------------------------------------------------------------------
//Запрос на диалог
//------------------------------------------------------------------------------------------

void LAi_Character_NeedDialog(aref chr, aref by)
{
	if(IsEntity(by))
	{
		string func = chr.chr_ai.type;
		if(func != "")
		{
			func = "LAi_type_" + func + "_NeedDialog";
			call func(by, chr);
		}
	}
}

//Запрос на диалог, если возвратить true то в этот момент можно начать диалог
bool LAi_Character_CanDialog(aref chr, aref by)
{
	if(locCameraCurMode == LOCCAMERA_FREE) return false;									// PB: Don't bother me when I'm flying
	if(IsEntity(by) && !CheckAttribute(by,"condition") && !CheckAttribute(chr,"condition"))	// MAXIMUS: for skipping dialog with character during ChangeCharacterAddress
	{
		bool isDisable = false;
		if(CheckAttribute(chr, "chr_ai.disableDlg"))
		{
			if(sti(chr.chr_ai.disableDlg) != 0) isDisable = true;
		}
		if(isDisable == false)
		{
			string func = by.chr_ai.type;
			if(func != "")
			{
				func = "LAi_type_" + func + "_CanDialog";
				return call func(by, chr);
			}
		}
	}
	return false;
}

//Начать диалог
void LAi_Character_StartDialog(aref chr, aref by)
{
	if(IsEntity(by))
	{
		string func = by.chr_ai.type;
		if(func != "")
		{
			func = "LAi_type_" + func + "_StartDialog";
			call func(by, chr);
		}
	}
}

//Закончить диалог
void LAi_Character_EndDialog(aref chr, aref by)
{
	if(IsEntity(by))
	{
		string func = by.chr_ai.type;
		if(func != "")
		{
			func = "LAi_type_" + func + "_EndDialog";
			call func(by, chr);
		}
	}
}
bool LAi_DoCORPEMODE(aref chr)
{
		if (CheckAttribute(chr, "corpse")) return true;
		if (bAbordageStarted) return true;
		if (chr.name==XI_ConvertString("Crewmember")) return true;
		if (chr.name=="Pirate") return true;
		if (chr.name+chr.lastname=="Bernardo"+"Gamboa") return true;
		if (chr.name+chr.lastname=="Nigel"+"Blythe") return true;
		if (chr.name+chr.lastname=="Artois"+"Voysey") return true;
		if (chr.chr_ai.group=="FBQ_SPAIN_SOLDIERS") return true;
		if (chr.name=="French Soldier") return true;
		if (chr.chr_ai.group=="ENGLAND_TAVERN_SOLDIERS") return true;
		if (chr.chr_ai.group=="SMUGGLERS_SOLDIERS") return true;
		if (chr.chr_ai.group=="ACTOR") return true;
		if (chr.chr_ai.group=="GREENFORD_MURDERERS") return true;
		return false;
}
