object	AISeaGoods;

void DeleteSeaGoodsEnvironment()
{
	DeleteClass(&AISeaGoods);

	DelEventHandler(SHIP_DEAD, "AISeaGoods_ShipDead");
}

void CreateSeaGoodsEnvironment()
{
	CreateEntity(&AISeaGoods, "AISeaGoods");
	
	LayerAddObject(SEA_EXECUTE, &AISeaGoods, -1);
	LayerAddObject(SEA_REALIZE, &AISeaGoods, 65532);

	SetEventHandler(SHIP_DEAD, "AISeaGoods_ShipDead", 0);
	SetEventHandler(SHIP_EAT_SWIM_GOOD, "AISeaGoods_ShipEatGood", 0);

	AISeaGoods.ModelsPath = "SwimGoods";
	AISeaGoods.DeleteGoodAnyway = true;
	AISeaGoods.DistanceMultiply = 0.5;
}

void AISeaGoods_ShipDead()
{
	ref rCharacter = GetCharacter(GetEventData());

	aref aGoods; makearef(aGoods, rCharacter.Ship.Cargo.Goods);
	for (int i=0; i<GetAttributesNum(aGoods); i++)
	{
		aref aGood = GetAttributeN(aGoods, i);
		int	iQuantity = sti(GetAttributeValue(aGood));
		ref	rGood = GetGoodByID(GetAttributeName(aGood));

		if (!CheckAttribute(rGood, "Swim")) { continue; }
		
		iQuantity = iQuantity / sti(rGood.Units);
		if (iQuantity <= 1) { continue; }

		if (rand(100) > 90) { continue; }

		int iSwimQuantity = 0; 
		while (iSwimQuantity == 0) { iSwimQuantity = MakeInt(iQuantity / 4 + rand(MakeInt(iQuantity * 2 / 4))); }
		float fTime = stf(rGood.Swim.Time);
		string sModel = rGood.Swim.Model;

		fTime = fTime + (frnd() - 0.5) * fTime / 2.0;

		AISeaGoods_AddGood(rCharacter, GetAttributeName(aGood), sModel, fTime * 60.0, iSwimQuantity);
	}
	// ccc rescue survivors // KK -->
	//survivor calculation for tutorial:  iSwimQuantity  = rand(20)  would work, but...
	iSwimQuantity = GetTotalCrewQuantity(rCharacter);
	if (iSwimQuantity > 0) { // don't produce survivors if ship sank with all souls
		iSwimQuantity = MakeInt((5 + sqrt(iSwimQuantity)) / 5);   //... this adds more survivors for bigger ships, but taking account only alive
		AISeaGoods.ModelsPath = "LowCharacters";   //path to the crewmodels
		AISeaGoods_AddGood(rCharacter, "Oil", "Lo_Man", 1000.0, makeint(rand(iSwimQuantity)));	// floats a "fake" salvagegood with a sailormodel
		AISeaGoods_AddGood(rCharacter, "Oil", "Lo_Ma2", 1000.0, makeint(rand(iSwimQuantity)));	//	Petros added 4 more swimmer models
		AISeaGoods_AddGood(rCharacter, "Oil", "Lo_Ma3", 1000.0, makeint(rand(iSwimQuantity)));	//	Ditto
		AISeaGoods_AddGood(rCharacter, "Oil", "Lo_Ma4", 1000.0, makeint(rand(iSwimQuantity)));	//	Ditto
		AISeaGoods_AddGood(rCharacter, "Oil", "Lo_Ma5", 1000.0, makeint(rand(iSwimQuantity)));	//	Ditto
		AISeaGoods.ModelsPath = "SwimGoods";   //reset path to the salvagemodels
	}
	// ccc rescue survivors end // <-- KK
}

void AISeaGoods_AddGood(ref rCharacter, string sGood, string sModel, float fTime, int iQuantity)
{
	if (!bSeaActive) return;

	Trace("Add good : " + sGood + ", rCharacter.id = " + rCharacter.id + ", iQuantity = " + iQuantity);

	// calculate random position
          float fAng = stf(rCharacter.Ship.Ang.y);
          float x = (frnd() - 0.5) * 60.0;      // ccc rescue original 20.0; spreads salvage wider	//build 13 changed to 50.0, //Petros Change to 60.0 to get swimmers from Galleons
          float z = (frnd() - 0.5) * 100.0;      // ccc rescue original 40.0				//build 13 changed to 90.0, //Petros Change to 100.0 to get swimmers from Galleons
          RotateAroundY(&x, &z, cos(fAng), sin(fAng));

	AISeaGoods.Good = sGood;
	AISeaGoods.Pos.x = stf(rCharacter.Ship.Pos.x) + x;
	AISeaGoods.Pos.z = stf(rCharacter.Ship.Pos.z) + z;
	AISeaGoods.CharIndex = rCharacter.Index;
	AISeaGoods.Time = fTime;
	AISeaGoods.Quantity = iQuantity;
	AISeaGoods.Model = sModel;
	AISeaGoods.Add = "";
}

bool AISeaGoods_ShipEatGood()
{
	int iCharacterIndex = GetEventData();
	int iGoodCharacterIndex = GetEventData();
	string sGood = GetEventData();
	int iQuantity = GetEventData();

	ref rCharacter = GetCharacter(iCharacterIndex);

	if (iGoodCharacterIndex == iCharacterIndex) return false;
	if (LAi_IsDead(rCharacter)) return false;

	ref rShip = GetShipByID(rCharacter.Ship.Type); // PS
	aref arship; makearef(arship, rCharacter.ship); // PRS3
	ref rGood = GetGoodByID(sGood);

	int iLoad = sti(rCharacter.Ship.Cargo.Load);
	int iCapacity = sti(GetLocalShipAttrib(arship, rShip, "Capacity")); // PRS3
	int iGoodWeight = sti(rGood.Weight);
	int iGoodUnits = sti(rGood.Units);

	int iMaxGoodAllow = (iCapacity - iLoad) / iGoodWeight;
	if (iMaxGoodAllow < 0)	// LDH 19Oct06 fix for weird negative quantities of goods picked up
	{
		trace("Got Goods Error: iCapacity = " + iCapacity + ", iLoad = " + iLoad + ", iGoodWeight = " + iGoodWeight + ", iMaxGoodAllow = " + iMaxGoodAllow + " (set to zero)");
		iMaxGoodAllow = 0;
	}

	string sGoodName = LanguageConvertString(iSeaSectionLang, "seg_" + sGood);

	// ccc Jan07 Directsail, special events that happen if you sail over flotsam of a certain kind
       if (sGood=="Oil")   //Oil, which usually never floats, serves as trigger for events
       {
          SwimGoodEvent(rCharacter,iQuantity);   //new function in CCCdirectsail.c, so that future changes won't affect this common file
          return false;   //aborts the function so that no "oil" goods are added
       }
	
/* Jan07, original survivor code moved to SwimGoodEvent in CCCdirectsail.c
	// ccc rescue survivors
       if (sGood=="Oil" && iCharacterIndex == GetMainCharacterIndex() )   //runs only for "fake" salvage and the player
       {
          AddCharacterCrew(rCharacter,iQuantity);   //adds crew
	      int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
          Log_SetStringToLog(iQuantity + " " + LanguageConvertString(tmpLangFileID,"survivors rescued"));   //screenmessage
          PlaySound("objects\abordage\abordage_loosing.wav");   //soundeffect
          ChangeCharacterReputation(rCharacter, 1);   //rescuer deserves praise :)
		  LanguageCloseFile(tmpLangFileID);	// LDH moved line above return 19Oct06
          return false;   //aborts the function so that no "oil" goods are added
       }
       // ccc rescue survivors end
*/
// ccc Jan07 end

	if (iMaxGoodAllow == 0)
	{
		Log_SetStringToLog(LanguageConvertString(iSeaSectionLang, "Ship_cant_got_good_1") + " " + sGoodName + " " + LanguageConvertString(iSeaSectionLang, "Ship_cant_got_good_2")); // KK
		return false;
	}

	if (iQuantity > iMaxGoodAllow) iQuantity = iMaxGoodAllow;

	if (iCharacterIndex == GetMainCharacterIndex())
	{
		if (ENABLE_EXTRA_SOUNDS == 1) PlaySound("#cargo_aboard"); // NK // added by KAM after build 11
		int iGoodQuantity = iQuantity * iGoodWeight;
// KK -->
		Log_SetStringToLog(LanguageConvertString(iSeaSectionLang, "Ship_got_good_1") + " " + iGoodQuantity + LanguageConvertString(iSeaSectionLang, "Ship_got_good_2") + " " + sGoodName + ".");
		trace("Got Goods: " + sGoodName + " (" + iGoodQuantity + ")");
// <-- KK
	}

	AddCharacterGoods(rCharacter, FindGood(sGood), iQuantity * iGoodUnits);
	return true;
}
