
/*
************************************************************************************************************
************************************************************************************************************

 the central functions
 for the the all-new
 SHIP BERTHING SYSTEM!!!!!
 by Kieron (KAM)

************************************************************************************************************
************************************************************************************************************


these functions are completely independent of the ship berthing interface (i.e. they do not depend on
global variables/objects/functions defined in the interface\kam_shipberthing* files); this file is
#included in seadogs.c, and so the functions in this file can be called from any other file (for example,
usefully, from the encounter officer's dialogue file).

however, they do not all have internal error-checking; it is assumed that the inputs to these functions
are checked *before* the function is called! (that includes: checking that ANY ship relaunched into slot 1
has the player character, and no other character, as its new captain; and checking that NO ship going on
shore leave has the player character as its captain.)
*/





void ShipBerthing(int SelCompSlot, int SelPort, int SelBerthSlot, int BDst, int NRCIdx, int NBCIdx)
{

	// SelCompSlot = the companion slot (from 0 to 3, where 0 is the player character slot) of the active ship being berthed AND/OR where the relaunching ship will be relaunched
	// SelPort = the port (from 0 to 7) where the relaunching ship is currently berthed AND/OR where the berthing ship will be berthed
	// SelBerthSlot = the slot (from 1 to 4) where the relaunching ship is currently berthed AND/OR where the berthing ship will be berthed
	// BDst = is 0 if the berthing ship is going on shore leave, 1 for laying up; if there is no berthing ship it doesn't matter what you set this to (it will be automatically set to -1)
	// NRCIdx = the index of the newly chosen captain of the relaunching ship; if there is no relaunching ship it doesn't matter what you set this to (it will be automatically set to -1)
	// NBCIdx = the index of the newly chosen captain of the ship going on shore leave; if there is no ship going on shore leave, it doesn't matter what you set this to (it will be automatically set to -1)





	// *************** STEP 1/5 : SET VARIABLES, REFERENCES AND OBJECTS ***************


	if (TRACELOG == 1) { trace("Ship Berthing step 1..."); }

	ref MainChar = GetMainCharacter();							// MainChar is the main character (surprise ^_^ )
	int MainCharIdx = MainChar.index();							// MainCharIdx is the main character's index

	string PortAttrib = "port" + SelPort;
	string SlotAttrib = "slot" + SelBerthSlot;

	int RSrc = 0; // RSrc is set to <<berthing slot>>.status, i.e.: 0 if there is no relaunching ship; 1 if the relaunching ship is currently laid up; and 2 if the relaunching ship is currently on shore leave
	if(checkAttribute(MainChar, "ShipBerthing." + PortAttrib  + "." + SlotAttrib + ".status")) RSrc = MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).status; //JA 9DEC06 Added checkAttribute to remove errors in log			

	int ORCIdx;
	ref ORC;
	ref NRC;
	switch (RSrc)
	{
		case 2:
			ORCIdx = sti(MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).captainindex);
			ORC = GetCharacter(ORCIdx);						// ORC is the old captain of the relaunching ship (this is only possible if that ship is on shore leave; you can test if ORC exists by checking ORCIdx >= 0 or by checking RSrc == 2)
			NRC = GetCharacter(NRCIdx);						// NRC is the new captain of the relaunching ship (this is only possible if there is a relaunching ship; you can test if NRC exists by checking NRCIdx >= 0 or by checking RSrc > 0)
		break;
		case 1:
			ORCIdx = -1;
			NRC = GetCharacter(NRCIdx);
		break;
		case 0:
			ORCIdx = -1;
			NRCIdx = -1;
		break;
	}

	int tempnumx1 = SelCompSlot-1;
	int OBCIdx = GetCompanionIndex(MainChar,tempnumx1);
	ref OBC;
	if (OBCIdx >= 0)
	{
		tempnumx1 = Characters[OBCIdx].ship.idx;
		if (tempnumx1 >= 0 && tempnumx1 != SHIP_NOTUSED)
		{
			OBC = GetCharacter(OBCIdx);						// OBC is the old captain of the berthing ship (this is only possible if there is a berthing ship; you can test if OBC exists by checking OBCIdx >= 0 or checking BDst >= 0)
		}
		else
		{
			OBCIdx = -1;
			BDst = -1;								// BDst is one of the variables passed to the function: -1 = no berthing ship; 0 = berthing ship is going on shore leave; 1 = berthing ship is being laid up; 2 = berthing ship is being scrapped;
		}
	}
	else
	{
		OBCIdx = -1;
		BDst = -1;
	}

	ref NBC;
	if (BDst == 0)
	{
		NBC = GetCharacter(NBCIdx);							// NBC is the new captain of the berthing ship (this is only possible if that ship is going on shore leave; you can test if NBC exists by checking NBCIdx >= 0 or by checking BDst == 0)
	}
	else
	{
		NBCIdx = -1;
	}

	object TempR;										// TempR is the object that temporarily stores the relaunching ship
	object TempB;										// TempR is the object that temporarily stores the berthing ship

	string tempstringx1;

	aref arcopyto, arcopyfrom; // PRS3

	if (TRACELOG == 1) { trace("...done"); }






	// *************** STEP 2/5 : STORE AWAY SHIPS ***************


	if (TRACELOG == 1) { trace("Ship Berthing step 2..."); }

	aref arORCShip;
	switch (RSrc)
	{
		case 2:
			// if the relaunching ship is currently on shore leave, move the ship from its old captain into TempR and clear the berthing record
			if (TRACELOG == 1) { trace("moving the ship from its old captain into TempR and clearing the berthing record"); }
			if (TRACELOG == 1) { trace("test: ORC.ship.name = " + ORC.ship.name); }
			makearef(arORCShip,ORC.ship); //JA 9DEC06 Moved inside case statememt as not initialized if no ship in slot
			CopyAttributes(&TempR,arORCShip);
			DeleteAttribute(ORC,"ship");
			ORC.ship.idx = SHIP_NOTUSED;
			ORC.ship.type = SHIP_NOTUSED_TYPE_NAME;
			DeleteAttribute(MainChar.ShipBerthing.(PortAttrib).(SlotAttrib),"");
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).status = 0;
			if (TRACELOG == 1) { trace("test: TempR.name = " + TempR.name); }
		break;

		case 1:
			// if the relaunching ship is currently laid up, create a new ship in TempR using the settings stored in the berthing slot, and clear the berthing record
			if (TRACELOG == 1) { trace("creating a new ship in TempR using the settings stored in the berthing slot, and clearing the berthing record"); }
			if (TRACELOG == 1) { trace("test: <<berthing slot>>.shipname = " + MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).shipname); }
			tempnumx1 = MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).shiptype;
			TempR.idx = tempnumx1;
			TempR.type = ShipsTypes[tempnumx1].id;
			TempR.name = MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).shipname;
			TempR.cannons.type = MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).guns;
			TempR.hp = MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).hull;
			TempR.sp = 0;
			TempR.crew.morale = 45;
			TempR.crew.quantity = 0;
			// PRS3 -->
			TempR.stats = "";
			makearef(arcopyto, TempR.stats); makearef(arcopyfrom, MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).stats);
			CopyAttributes(arcopyto, arcopyfrom);
			// PRS3 <--
			// NK cannons qty 05-04-18 -->
			TempR.cannons.borts = "";
			makearef(arcopyto, TempR.cannons.borts); makearef(arcopyfrom, MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).cannons.borts);
			CopyAttributes(arcopyto, arcopyfrom);
			// NK <--
			for(tempnumx1=0; tempnumx1<GOODS_QUANTITY; tempnumx1++)		// this loop initialises all goods quantities as 0
			{
				tempstringx1 = Goods[tempnumx1].name;
				TempR.ship.cargo.goods.(tempstringx1) = 0;
			}
			DeleteAttribute(MainChar.ShipBerthing.(PortAttrib).(SlotAttrib),"");
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).status = 0;
			if (TRACELOG == 1) { trace("test: TempR.name = " + TempR.name); }
		break;

		case 0:
			// if there is no relaunching ship
			if (TRACELOG == 1) { trace("no relaunching ship"); }
		break;
	}

	aref arOBCShip;
	if(OBCIdx != -1) makearef(arOBCShip,OBC.ship);

	if (BDst == 1)
	{
		if (GetCargoLoad(OBC) > 0)
		{
			// if the ship is being laid up and it has cargo, give mainchar the money for it
			if (TRACELOG == 1) { trace("OBC has cargo, giving him money for it"); }
			tempnumx1 = SBGetGoodsPrice(OBCIdx,SelPort);
			AddMoneyToCharacter(MainChar,tempnumx1);
		}
		else
		{
			if (TRACELOG == 1) { trace("OBC has no cargo"); }
		}

		// FlayedOne and unapply Tunning.
		stripUpgradesBerth(OBCIdx);
	}

	if (BDst >= 0)
	{
		// if there is a berthing ship, move it from its old captain into TempB
		if (TRACELOG == 1) { trace("moving berthing ship from its old captain into TempB"); }
		if (TRACELOG == 1) { trace("test: OBC.ship.name = " + OBC.ship.name); }
		CopyAttributes(&TempB,arOBCShip);
		DeleteAttribute(OBC,"ship");
		OBC.ship.idx = SHIP_NOTUSED;
		OBC.ship.type = SHIP_NOTUSED_TYPE_NAME;
		if (TRACELOG == 1) { trace("test: TempB.name = " + TempB.name); }
	}
	else
	{
		if (TRACELOG == 1) { trace("no berthing ship"); }
	}

	if (TRACELOG == 1) { trace("...done"); }






	// *************** STEP 3/5 : PUT SHIPS IN APPROPRIATE PLACES ***************


	if (TRACELOG == 1) { trace("Ship Berthing step 3..."); }

	aref arNRCShip;
	if (RSrc > 0)
	{
		// if there is a relaunching ship, move it to its new captain
		if (TRACELOG == 1) { trace("moving relaunching ship from TempR to new captain"); }
		if (TRACELOG == 1) { trace("test: TempR.name = " + TempR.name); }
		makearef(arNRCShip,NRC.ship); //JA 9DEC06 Moved inside case statememt as not initialized if no ship in slot
		CopyAttributes(arNRCShip,TempR);
		DeleteAttribute(&TempR,"");

//PW ------> copied and slightly amended from transfer_main.c since not called there by kam_shipberthing_ship.c routines
// to fix bug where MainChar has no location.from_sea since wiped in shipyard.c when you give up your ship and have no ship

// NK 04-17 lay up ships bugfix 
		
			if(!CheckAttribute(MainChar,"location.from_sea"))
			{	
				if( CheckAttribute(MainChar,"location.old_from_sea") )
				{
					MainChar.location.from_sea = MainChar.location.old_from_sea;
					SetFleetInTown(GetTownIDFromLocID(MainChar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
					DeleteAttribute(MainChar,"location.old_from_sea");
				}
			}
			if(MainChar.location.from_sea == "")
			{
				if( CheckAttribute(MainChar,"location.old_from_sea") )
				{
					MainChar.location.from_sea = MainChar.location.old_from_sea;
					SetFleetInTown(GetTownIDFromLocID(MainChar.location.from_sea), "pchar"); // NK 05-04-02 WM/IT set fleet.
					DeleteAttribute(MainChar,"location.old_from_sea");
				}	
			}
		// NK <--
//PW <------ copied from transfer_main.c

		if (TRACELOG == 1) { trace("test: NRC.ship.name = " + NRC.ship.name); }
	}
	else
	{
		if (TRACELOG == 1) { trace("no relaunching ship"); }
	}

	aref arNBCShip;
	switch (BDst)
	{
		case 1:
			// if the berthing ship is to be laid up, put the details in the berthing record
			if (TRACELOG == 1) { trace("berthing ship is to be laid up, putting the details in the berthing record"); }
			if (TRACELOG == 1) { trace("test: TempB.name = " + TempB.name); }
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).status = 1;
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).shipname = TempB.name;
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).shiptype = TempB.idx;
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).guns = TempB.cannons.type;
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).hull = TempB.hp;
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).daysinberth = 0;
			tempnumx1 = MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).shiptype;
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).dailycost = SBCalculateDailyCost(1,tempnumx1,SelPort);
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).nowdue = 0;
			// PRS3 -->
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).stats = "";
			makearef(arcopyto, MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).stats); makearef(arcopyfrom, TempB.stats);
			CopyAttributes(arcopyto, arcopyfrom);
			// PRS3 <--
			// NK cannons qty 05-04-18 -->
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).cannons.borts = "";
			makearef(arcopyto, MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).cannons.borts); makearef(arcopyfrom, TempB.cannons.borts);
			CopyAttributes(arcopyto, arcopyfrom);
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).cannons.qty = GetLocalShipAttrib(&TempB, &ShipsTypes[sti(TempB.idx)], "CurCanQty");
			// NK <--
			DeleteAttribute(&TempB,"");
			if (TRACELOG == 1) { trace("test: <<berthing slot>>.shipname = " + MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).shipname); }
		break;

		case 0:
			// if the berthing ship is going on shore leave, move it to its new captain and update the berthing record
			if (TRACELOG == 1) { trace("ship is going on shore leave, moving it to its new captain and updating the berthing record"); }
			if (TRACELOG == 1) { trace("test: TempB.name = " + TempB.name); }
			makearef(arNBCShip,NBC.ship); //JA 9DEC06 Moved inside case statememt as not initialized if no ship in slot
			CopyAttributes(arNBCShip,TempB);
			DeleteAttribute(&TempB,"");
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).status = 2;
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).shipname = NBC.ship.name;
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).shiptype = NBC.ship.idx;
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).captainindex = NBC.index;
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).daysinberth = 0;
			tempnumx1 = MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).shiptype;
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).dailycost = SBCalculateDailyCost(0,tempnumx1,SelPort);
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).nowdue = 0;
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).crewnowdue = 0;
			// PRS3 -->
			// 05-04-18 this block may not be necessary since it gets copied to NBC...
			MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).stats = "";
			makearef(arcopyto, MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).stats); makearef(arcopyfrom, arNBCShip.stats);
			CopyAttributes(arcopyto, arcopyfrom);
			// PRS3 <--
			if (TRACELOG == 1) { trace("test: NBC.ship.name = " + NBC.ship.name); }
			if (TRACELOG == 1) { trace("test: <<berthing slot>>.shipname = " + MainChar.ShipBerthing.(PortAttrib).(SlotAttrib).shipname); }
		break;

		//default:
			// if there is no berthing ship
			if (TRACELOG == 1) { trace("no berthing ship"); }
		break;
	}


	if (TRACELOG == 1) { trace("...done"); }






	// *************** STEP 4/5 : ADD/REMOVE FROM COMPANIONS LIST ***************


	if (TRACELOG == 1) { trace("Ship Berthing step 4..."); }

	if (BDst >= 0)
	{
		if (OBCIdx != MainCharIdx)
		{
			//if OBC exists and is different from mainchar, remove him from companions
			if (TRACELOG == 1) { trace("removing old berthing captain from companions"); }
			RemoveCharacterCompanion(MainChar,OBC);
			OBC.location = "none";
		}
	}

	if (RSrc > 0)
	{
		if (NRCIdx != MainCharIdx)
		{
			//if NRC exists and is different from mainchar, add him to companions
			if (TRACELOG == 1) { trace("adding new relaunching captain to companions"); }
			tempnumx1 = SelCompSlot-1;
			SetCompanionIndex(MainChar,tempnumx1,NRCIdx);
		}
	}

	if (TRACELOG == 1) { trace("...done"); }






	// *************** STEP 5/5 : ADD/REMOVE FROM PASSENGERS LIST ***************


	if (TRACELOG == 1) { trace("Ship Berthing step 5..."); }

	if (BDst == 0)
	{
		//if NBC exists...
		if (TRACELOG == 1) { trace("nbc exists"); }
		if (TRACELOG == 1) { trace("nbc " + nbcidx + "; obc " + obcidx + "; orc " + orcidx + "; mainchar " + maincharidx); }
		if (NBCIdx != OBCIdx && NBCIdx != ORCIdx && NBCIdx != MainCharIdx)
		{
			//...AND the new berthing captain is different from the old berthing captain...
			//...AND the new berthing captain is different from the old relaunching captain...
			//...AND the new berthing captain isn't the player character...
			//...THEN he must have been a passenger; remove the new berthing captain from the passengers list
			if (TRACELOG == 1) { trace("removing nbc from passengers"); }
			RemovePassenger(MainChar,NBC);
			NBC.location = "none";
		}
	}

	if (BDst >= 0)
	{
		//if OBC exists...
		if (TRACELOG == 1) { trace("obc exists"); }
		if (TRACELOG == 1) { trace("obc " + obcidx + "; nbc " + nbcidx + "; nrc " + nrcidx + "; mainchar " + maincharidx); }
		if (OBCIdx != NBCIdx && OBCIdx != NRCIdx && OBCIdx != MainCharIdx)
		{
			//...AND the old berthing captain is different from the new berthing captain...
			//...AND the old berthing captain is different from the new relaunching captain...
			//...AND the old berthing captain isn't the player character...
			//...THEN he is no longer assigned a ship; add the old berthing captain to the passengers list
			if (TRACELOG == 1) { trace("adding obc to passengers"); }
			AddPassenger(MainChar,OBC,false);
			OBC.location = "none";
		}
	}

	if (RSrc > 0)
	{
		//if NRC exists...
		if (TRACELOG == 1) { trace("nrc exists"); }
		if (TRACELOG == 1) { trace("nrc " + nrcidx + "; orc " + orcidx + "; obc " + obcidx + "; mainchar " + maincharidx); }
		if (NRCIdx != ORCIdx && NRCIdx != OBCIdx && NRCIdx != MainCharIdx)
		{
			//...AND the new relaunching captain is different from the old relaunching captain...
			//...AND the new relaunching captain is different from the old berthing captain...
			//...AND the new relaunching captain isn't the player character...
			//...THEN he must have been a passenger; remove the new relaunching captain from the passengers list
			if (TRACELOG == 1) { trace("removing nrc from passengers"); }
			RemovePassenger(MainChar,NRC);
			NRC.location = "none";
		}
	}

	if (RSrc == 2)
	{
		//if ORC exists...
		if (TRACELOG == 1) { trace("orc exists"); }
		if (TRACELOG == 1) { trace("orc " + orcidx + "; nrc " + nrcidx + "; orc " + orcidx + "; mainchar " + maincharidx); }
		if (ORCIdx != NRCIdx && ORCIdx != NBCIdx && ORCIdx != MainCharIdx)
		{
			//IF the old relaunching captain is different from the new relaunching captain...
			//...AND the old relaunching captain is different from the new berthing captain...
			//...AND the old relaunching captain isn't the player character (though this should actually be impossible - the player character is not allowed on shore leave!)...
			//...THEN he is no longer assigned a ship; add the old relaunching captain to the passengers list
			if (TRACELOG == 1) { trace("adding orc to passengers"); }
			AddPassenger(MainChar,ORC,false);
			ORC.location = "none";
		}
	}

	if (TRACELOG == 1) { trace("...done"); }






	// *************** FI ***************

}




void ShipScrapping(int ySelPort, int ySelBerthSlot)
{
	// scraps a ship which is already berthed

	// ySelPort = the port (from 0 to 7) where the ship is currently berthed
	// ySelBerthSlot = the slot (from 1 to 4) where the ship is currently berthed

	int tempnumy1;

	ref yMainChar = GetMainCharacter();
	string yPortAttrib = "port" + ySelPort;
	string ySlotAttrib = "slot" + ySelBerthSlot;
	ref yCaptainChar;
	int yCaptainCharIdx;

	if (yMainChar.ShipBerthing.(yPortAttrib).(ySlotAttrib).status == 2)
	{
		// if the ship is on shore leave
		yCaptainChar = GetCharacter(sti(yMainChar.ShipBerthing.(yPortAttrib).(ySlotAttrib).captainindex));
		yCaptainCharIdx = sti(yCaptainChar.index):

		if (TRACELOG == 1) { trace("yCaptainChar is " + yCaptainChar.name + " " + yCaptainChar.lastname); }

		if (GetCargoLoad(yCaptainChar) > 0)
		{
			// if it has cargo, give yMainChar the money for it
			if (TRACELOG == 1) { trace("yCaptainChar has cargo, giving him money for it"); }
			tempnumy1 = SBGetGoodsPrice(yCaptainCharIdx,ySelPort);
			AddMoneyToCharacter(yMainChar,tempnumy1);
		}
		else
		{
			if (TRACELOG == 1) { trace("yCaptainChar has no cargo"); }
		}

		// and delete the ship from its captain
		DeleteAttribute(yCaptainChar,"ship");
		yCaptainChar.ship.idx = SHIP_NOTUSED;
		yCaptainChar.ship.type = SHIP_NOTUSED_TYPE_NAME;

		// and add the captain to the passengers list
		AddPassenger(yMainChar,yCaptainChar,false);
	}

	// clear the berthing record
	DeleteAttribute(yMainChar.ShipBerthing.(yPortAttrib).(ySlotAttrib),"");
	yMainChar.ShipBerthing.(yPortAttrib).(ySlotAttrib).status = 0;
}




void ShipLUFromSO(int afSelPort, int afSelBerthSlot)
{
	// lays up a ship which is currently on shore leave

	// afSelPort = the port (from 0 to TOWNS_QUANTITY) where the ship is currently berthed // Screwface
	// afSelBerthSlot = the slot (from 1 to 4) where the ship is currently berthed

	int tempnumaf1;
	int tempnumaf2;
	int tempnumaf3;

	ref afMainChar = GetMainCharacter();
	string afPortAttrib = "port" + afSelPort;
	string afSlotAttrib = "slot" + afSelBerthSlot;
	ref afCaptainChar;
	int afCaptainCharIdx;

	if (afMainChar.ShipBerthing.(afPortAttrib).(afSlotAttrib).status != 2) { return; }		// if the ship in the slot isn't on shore leave, don't do anything

	if (TRACELOG == 1) { trace("assigning afCaptainChar..."); }
	tempnumaf1 = sti(afMainChar.ShipBerthing.(afPortAttrib).(afSlotAttrib).captainindex);
	afCaptainChar = GetCharacter(tempnumaf1);
	afCaptainCharIdx = sti(afCaptainChar.index);
	if (TRACELOG == 1) { trace("...done (test: afCaptainChar.ship.name = " + afCaptainChar.ship.name + ")"); }

	if (GetCargoLoad(afCaptainChar) > 0)
	{
		// if it has cargo, give afMainchar the money for it
		if (TRACELOG == 1) { trace("afCaptainChar has cargo, giving him money for it"); }
		tempnumaf1 = SBGetGoodsPrice(afCaptainCharIdx,afSelPort);
		AddMoneyToCharacter(afMainchar,tempnumaf1);
	}
	else
	{
		if (TRACELOG == 1) { trace("afCaptainChar has no cargo"); }
	}

	// save the days in berth and value from the berthing record
	tempnumaf1 = sti(afMainChar.ShipBerthing.(afPortAttrib).(afSlotAttrib).daysinberth);
	tempnumaf2 = sti(afMainChar.ShipBerthing.(afPortAttrib).(afSlotAttrib).nowdue);
//	tempnumaf3 = sti(afMainChar.ShipBerthing.(afPortAttrib).(afSlotAttrib).crewnowdue);

	// clear the berthing record
	DeleteAttribute(afMainChar.ShipBerthing.(afPortAttrib).(afSlotAttrib),"");

	// and write it back in laid-up format, using the ship's details from afCaptainChar
	afMainChar.ShipBerthing.(afPortAttrib).(afSlotAttrib).status = 1;
	afMainChar.ShipBerthing.(afPortAttrib).(afSlotAttrib).shipname = afCaptainChar.ship.name;
	afMainChar.ShipBerthing.(afPortAttrib).(afSlotAttrib).shiptype = afCaptainChar.ship.idx;
	afMainChar.ShipBerthing.(afPortAttrib).(afSlotAttrib).guns = afCaptainChar.ship.cannons.type;
	afMainChar.ShipBerthing.(afPortAttrib).(afSlotAttrib).hull = afCaptainChar.ship.hp;
	afMainChar.ShipBerthing.(afPortAttrib).(afSlotAttrib).daysinberth = tempnumaf1;
	tempnumaf1 = afMainChar.ShipBerthing.(afPortAttrib).(afSlotAttrib).shiptype;
	afMainChar.ShipBerthing.(afPortAttrib).(afSlotAttrib).dailycost = SBCalculateDailyCost(1,tempnumaf1,afSelPort);
	afMainChar.ShipBerthing.(afPortAttrib).(afSlotAttrib).nowdue = tempnumaf2;
//	afMainChar.ShipBerthing.(afPortAttrib).(afSlotAttrib).crewnowdue = tempnumaf3;

	// then delete the ship from afCaptainChar
	DeleteAttribute(afCaptainChar,"ship");
	afCaptainChar.ship.idx = SHIP_NOTUSED;
	afCaptainChar.ship.type = SHIP_NOTUSED_TYPE_NAME;

	// and add him to the passengers list
	AddPassenger(afMainChar,afCaptainChar,false);
}	




void InitialiseShipBerthingData()
// (re-)initialises the ship berthing info structure (avoids lots of "missed attribute" errors)
{
	string tempstringe1;
	string tempstringe2;
	int tempnume1;
	int tempnume2;

	ref eMainChar = GetMainCharacter();

	if (CheckAttribute(eMainChar,"ShipBerthing"))
	{
		DeleteAttribute(eMainChar,"ShipBerthing")
	}

	for (tempnume1=0; tempnume1<TOWNS_QUANTITY; tempnume1++) // Screwface
	{
		tempstringe1 = "port" + tempnume1;
		for (tempnume2=1; tempnume2<5; tempnume2++)
		{
			tempstringe2 = "slot" + tempnume2;
			eMainChar.ShipBerthing.(tempstringe1).(tempstringe2).status = 0;
		}
	}
}




bool IsOnShoreLeave(ref ajCaptainChar)
{
	string ajPortAttrib;
	string ajSlotAttrib;
	int tempnumaj1;
	int tempnumaj2;
	int ajCaptainIdx;

	ref ajMainChar = GetMainCharacter();

	ajCaptainIdx = sti(ajCaptainChar.index);


	for (tempnumaj1 = 0; tempnumaj1 < TOWNS_QUANTITY; tempnumaj1++) // Screwface
	{
		ajPortAttrib = "port" + tempnumaj1;

		for (tempnumaj2 = 1; tempnumaj2 < 5; tempnumaj2++)
		{
			ajSlotAttrib = "slot" + tempnumaj2;
			if(CheckAttribute(ajMainChar,"ShipBerthing."+(ajPortAttrib)+"."+(ajSlotAttrib)+".status"))//MAXIMUS
			{
			if (sti(ajMainChar.ShipBerthing.(ajPortAttrib).(ajSlotAttrib).status) == 2)
			{
				if (sti(ajMainChar.ShipBerthing.(ajPortAttrib).(ajSlotAttrib).captainindex) == ajCaptainIdx)
				{
					if (TRACELOG == 1) { Trace("character " + ajCaptainChar.name + " " + ajCaptainChar.lastname + " tested positive for being on shore leave"); }
					return true;
				}
			}
			}//MAXIMUS
		}
	}

	if (TRACELOG == 1) { Trace("character " + ajCaptainChar.name + " " + ajCaptainChar.lastname + " tested negative for being on shore leave"); }
	return false;
}




bool IsOfficerOnShoreLeave(ref anCaptainChar)
{
	string anPortAttrib;
	string anSlotAttrib;
	int tempnuman1;
	int tempnuman2;
	int tempnuman3;
	int tempnuman4;
	ref tempcharan1;
	int anCaptainIdx;

	ref anMainChar = GetMainCharacter();

	anCaptainIdx = sti(anCaptainChar.index);


	for (tempnuman1 = 0; tempnuman1 < TOWNS_QUANTITY; tempnuman1++) // Screwface
	{
		anPortAttrib = "port" + tempnuman1;

		for (tempnuman2 = 1; tempnuman2 < 5; tempnuman2++)
		{
			anSlotAttrib = "slot" + tempnuman2;
			if(CheckAttribute(anMainChar,"ShipBerthing."+(anPortAttrib)+"."+(anSlotAttrib)+".status"))//MAXIMUS
			{
			if (sti(anMainChar.ShipBerthing.(anPortAttrib).(anSlotAttrib).status) == 2)
			{
				tempcharan1 = GetCharacter(sti(anMainChar.ShipBerthing.(anPortAttrib).(anSlotAttrib).captainindex));
				for (tempnuman3 = 1; tempnuman3 < 3; tempnuman3++)
				{
					tempnuman4 = GetOfficersIndex(tempcharan1,tempnuman3);
					if (tempnuman4 == anCaptainIdx)
					{
						if (TRACELOG == 1) { Trace("character " + anCaptainChar.name + " " + anCaptainChar.lastname + " tested positive for being an officer of a captain on shore leave"); }
						return true;
					}
				}
			}
			}//MAXIMUS
		}
	}

	if (TRACELOG == 1) { Trace("character " + anCaptainChar.name + " " + anCaptainChar.lastname + " tested negative for being on shore leave"); }
	return false;
}






// --> Swindler 2005-10-12: corrected syntax error
//bool GetShoreLeaveQuantity();
bool GetShoreLeaveQuantity()
{
	string alPortAttrib;
	string alSlotAttrib;
	int tempnumal1;
	int tempnumal2;
	int tempnumal3;
	int tempnumal4;

	ref alMainChar = GetMainCharacter();

	tempnumal4 = 0;
	for (tempnumal1 = 0; tempnumal1 < TOWNS_QUANTITY; tempnumal1++) // Screwface
	{
		alPortAttrib = "port" + tempnumal1;

		for (tempnumal2 = 1; tempnumal2 < 5; tempnumal2++)
		{
			alSlotAttrib = "slot" + tempnumal2;
			if (sti(alMainChar.ShipBerthing.(alPortAttrib).(alSlotAttrib).status) == 2)
			{
				tempnumal4 += 1;
			}
		}
	}

	if (TRACELOG == 1) { Trace("found that there were " + tempnumal4 + " captains on shore leave"); }
	return tempnumal4;
}


void DailyShipBerthingUpdate()
{
	//trace("Gauging: NEXTDAY_Berth start");
	// this is run every day to update the values in the berthing records

	ref zMainChar = GetMainCharacter();

	int tempnumz1;
	int tempnumz2;
	string tempstringz1;
	string tempstringz2;
	int tempnumz3;
	int tempnumz4;
	int tempnumz5;
	int tempnumz6;

	for(tempnumz1=0; tempnumz1<TOWNS_QUANTITY; tempnumz1++) // screwface
	{
		tempstringz1 = "port" + tempnumz1;
		if(!CheckAttribute(zMainChar,"ShipBerthing."+tempstringz1)) continue; // screwface

		for (tempnumz2=1; tempnumz2<5; tempnumz2++)
		{
			tempstringz2 = "slot" + tempnumz2;
			if(!CheckAttribute(zMainChar,"ShipBerthing." + tempstringz1 + "." + tempstringz2)) continue; // screwface

			tempnumz3 = zMainChar.ShipBerthing.(tempstringz1).(tempstringz2).status;
			if (tempnumz3 > 0)
			{
				tempnumz4 = sti(zMainChar.ShipBerthing.(tempstringz1).(tempstringz2).nowdue);
				tempnumz5 = sti(zMainChar.ShipBerthing.(tempstringz1).(tempstringz2).dailycost);
				tempnumz4 += tempnumz5;
				zMainChar.ShipBerthing.(tempstringz1).(tempstringz2).nowdue = tempnumz4;
				tempnumz4 = sti(zMainChar.ShipBerthing.(tempstringz1).(tempstringz2).daysinberth);
				tempnumz4 += 1;
				zMainChar.ShipBerthing.(tempstringz1).(tempstringz2).daysinberth = tempnumz4;
			}
			if (tempnumz3 == 2 && sti(worldMap.date.day) == 7)
			{
				tempnumz4 = sti(zMainChar.ShipBerthing.(tempstringz1).(tempstringz2).crewnowdue);
				tempnumz5 = sti(zMainChar.ShipBerthing.(tempstringz1).(tempstringz2).captainindex);
				tempnumz6 = GetCrewQuantity(GetCharacter(tempnumz5));
				tempnumz4 += SBGetShoreLeavePay(tempnumz5,tempnumz6);
				zMainChar.ShipBerthing.(tempstringz1).(tempstringz2).crewnowdue = tempnumz4;
			}
		}
	}
	//trace("Gauging: NEXTDAY_birth end");
}




int SBCalculateDailyCost(int BMNum, int STNum, int PortNum)
{
	// works out the daily berthing charge
	// BMNum: berthing method; 0 for shore leave, 1 for laying up
	// STNum: ship type; the .idx of the ship being berthed
	// PortNum: the port (from 0 to 7) where the ship is being berthed

	if (BMNum < 0 || BMNum > 1) { trace("bad berthing method (" + BMNum + ")"); return -1; }
	if (STNum < 0 || STNum == SHIP_NOTUSED) { trace("bad ship type idx (" + STNum + ")"); return -1; }
	//if (PortNum < 0 || PortNum > 7) { trace("bad port number (" + PortNum + ")"); return -1; }
	// Screwface : Portnum can now be > 7
	if (PortNum < 0) { trace("bad port number (" + PortNum + ")"); return -1; }




	// STEP 1/2: SET PRICING BRACKETS

	int ShipCostBracket = (9-sti(ShipsTypes[STNum].class))/2;
	if (TRACELOG == 1) { trace("ship placed in ship cost bracket " + ShipCostBracket); }

// KK -->
	int PortCostBracket = -1;
	if (CheckAttribute(&Towns[PortNum], "shipberth")) PortCostBracket = sti(Towns[PortNum].shipberth);
	if (TRACELOG == 1) { trace("port placed in port cost bracket " + PortCostBracket); }
// <-- KK


	// STEP 2/2: CALCULATE COST

	float TempDailyCost;
	switch (BMNum)
	{
		case 1:		TempDailyCost = 1.0;	break;		// if the ship is being laid up, the basic cost is 1 / day
		case 0:		TempDailyCost = 3.0;	break;		// if the ship is going on shore leave, the basic cost is 3 / day
	}
	if (TRACELOG == 1) { trace("basic cost (TempDailyCost) is " + TempDailyCost); }

	float tempcoefficient;
	switch (ShipCostBracket)
	{
		case 0:		tempcoefficient = 0.0;		break;
		case 1:		tempcoefficient = 1.0;		break;
		case 2:		tempcoefficient = 1.5;		break;
		case 3:		tempcoefficient = 2.0;		break;
		case 4:		tempcoefficient = 3.0;		break;
	}
	if (TRACELOG == 1) { trace("based solely on ship cost bracket, tempcoefficient is " + tempcoefficient); }

	switch (PortCostBracket)
	{
		case 0:		tempcoefficient -= 0.5;		break;
		case 2:		tempcoefficient += 0.5;		break;
	}
	if (TRACELOG == 1) { trace("modified according to port cost bracket, tempcoefficient is " + tempcoefficient); }

	if (tempcoefficient < 0) { tempcoefficient = 0; if (TRACELOG == 1) { trace("after correction, tempcoefficient is now " + tempcoefficient); } }

	TempDailyCost *= tempcoefficient;
	if (TRACELOG == 1) { trace("raw daily cost (TempDailyCost * tempcoefficient) is therefore " + TempDailyCost); }

	// FI

	int FinalDailyCost = makeint(TempDailyCost);

	if (TRACELOG == 1) { trace("rounded final daily cost: " + FinalDailyCost); }
	return FinalDailyCost;
}




void SBInvoiceOnLanding(int aaPortNum)
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	// this is run on docking in a port to exact monies owed for berthed ships (and can be run at any point to exact the monies owed for any specific port)
	// if aaPortNum is not a number from 0 to TOWNS_QUANTITY, the current port is found (and failing that nothing happens)

	ref aaMainChar = GetMainCharacter();
	int aaCurrentPortNumber;

	string tempstringaa1;
	string tempstringaa2;
	int tempnumaa1;
	int tempnumaa2;
	int tempnumaa3;
	int tempnumaa4;

	if (aaPortNum >= 0 && aaPortNum < TOWNS_QUANTITY) // Screwface
	{
		aaCurrentPortNumber = aaPortNum;
	}
	else
	{
		aaCurrentPortNumber = FindCurrentPort();
	}

	if (aaCurrentPortNumber == -1)
	{
		return;
	}
	else
	{
		tempnumaa2 = 0;
		tempnumaa4 = 0;
		tempstringaa1 = "port" + aaCurrentPortNumber;
		for (tempnumaa1 = 1; tempnumaa1 < 5; tempnumaa1++)
		{
			tempstringaa2 = "slot" + tempnumaa1;
			tempnumaa3 = 0; if(CheckAttribute(aaMainChar.ShipBerthing,"(tempstringaa1)")) tempnumaa3 = sti(aaMainChar.ShipBerthing.(tempstringaa1).(tempstringaa2).status); //added by MAXIMUS [CheckAttribute]
			if (tempnumaa3 > 0)
			{
				tempnumaa2 += sti(aaMainChar.ShipBerthing.(tempstringaa1).(tempstringaa2).nowdue);
				aaMainChar.ShipBerthing.(tempstringaa1).(tempstringaa2).nowdue = 0;
			}
			if (tempnumaa3 == 2)
			{
				tempnumaa4 += sti(aaMainChar.ShipBerthing.(tempstringaa1).(tempstringaa2).crewnowdue);
				aaMainChar.ShipBerthing.(tempstringaa1).(tempstringaa2).crewnowdue = 0;
			}
		}

		if (tempnumaa2 > 0)
		{
			Log_SetStringToLog(XI_ConvertString("The") + " " + FindTownName(GetPortName(aaCurrentPortNumber)) + " " + TranslateString("","port authority")); // KK
			Log_SetStringToLog(" " + XI_ConvertString("exact") + " " + tempnumaa2 + " " + TranslateString("","from your party in berthing duties."));
			tempnumaa3 = 0 - tempnumaa2;
			AddMoneyToCharacter(aaMainChar,tempnumaa3);
		}
		if (tempnumaa4 > 0)
		{
			Log_SetStringToLog(TranslateString("","You pay") + " " + tempnumaa4 + " " + TranslateString("","to the crew and officers you have"));
			Log_SetStringToLog(" " + TranslateString("","on shore leave at") + " " + FindTownName(GetPortName(aaCurrentPortNumber))); // KK
			tempnumaa3 = 0 - tempnumaa4;
			AddMoneyToCharacter(aaMainChar,tempnumaa4);
		}
	}
	//LanguageCloseFile(tmpLangFileID);
}

// KK -->
int FindCurrentIsland()
{
	// PB: Simplified -->
	ref PChar = GetMainCharacter();
	if (CheckAttribute(PChar, "location"))	return FindIsland(FindIslandByLocation(PChar.location)); // PB: This uses strings as input and output, but needs to return the island index here
	else									return 0;
	// PB: Simplified <--
	
/*	ref lcn = &locations[FindLocation(FindLoadedLocation())];
	//if (FindIslandByLocation(lcn.id) == "KhaelRoa") return FindIsland("KhaelRoa"); // PB: Fix this properly by adding island attributes to all Khael Roa locations
	// Screwface 
	if(Checkattribute(lcn,"island")) return FindIsland(lcn.island);
	// This way causes errors on seashores
	int townidx = FindCurrentPort();
	return FindIsland(Towns[townidx].island);*/
}
// <-- KK

int FindCurrentPort()
{
	// checks if MainChar is currently docked in one of the eight ports; returns -1 if not, or the port number (from 0 to 7) if yes
	// if MainChar has no ship, but is in a town, it returns the port number of that town

	int tempnumab1;
	int tempnumab2;
	string tempstringab1;

	ref abMainChar = GetMainCharacter();

	tempnumab2 = -1;
	// NK per Meigger allow choice for only allowing berthing at shipyards.
	bool tmpbool = bSeaActive == false && abMainChar.location != "Tutorial_Deck";
	if(ALLOWBERTHING_ONLYAT != "") tmpbool = tmpbool && HasSubStr(abMainChar.location, ALLOWBERTHING_ONLYAT);
	if (tmpbool)
	// NK <--
	{
// KK -->
		tempnumab2 = GetTownIndex(GetTownIDFromLocID(GetCharacterShipLocation(abMainChar)));
		if (abMainChar.ship.idx == SHIP_NOTUSED)
		{
			tempnumab1 = FindLoadedLocation();
// KK -->
			tempstringab1 = GetTownIDFromLocID(Locations[tempnumab1].id);
			if (tempstringab1 == "") return tempnumab2;
			tempnumab2 = GetTownIndex(tempstringab1);
// <-- KK
		}
	}

	return tempnumab2;
}

string GetPortName(int acPortNum)
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	// returns the string name of one of the eight ports when given an integer from 0 to 7
// KK -->
//	return nCurTown;
	string tempstringac1 = "(error)";
	if (acPortNum >= 0 && acPortNum < TOWNS_QUANTITY) return Towns[acPortNum].id;
	return tempstringac1;
// <-- KK
}

// ============================================= added by MAXIMUS for fine viewing on Russian only -->
string GetIslandName(int acPortNum)
{
	//int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	// returns the string name of one of the nineteen islands when given an integer from 0 to 18
// KK -->
	string tempstringac2;// = GetIslandIDFromTown(GetPortName(acPortNum));
	string pic = "pic" + (acPortNum + 1);
	tempstringac2 = GameInterface.islandslist.(pic).img1;
// <-- KK
	//return TranslateString("", FindIslandName(tempstringac2)); // KK // Screwface : TranslateString causes bug with Curacao
	return tempstringac2;
}
// ============================================= added by MAXIMUS for fine viewing on Russian only <--


int SBGetGoodsPrice(int adCptnIdx, int adPortNum)
{
	// calculates the value of the goods in a ship's hold
	// based on "Add Cargo Value to Ship Price" code by Viper and NK

	// adCptnIdx = the index of the captain whose ship we're dealing with
	// adPortNum = the port (0 to 7) where berthing is to take place

	if(!Checkattribute(&Towns[adPortNum],"store")) return 0; // Screwface : for towns with no store (Khael roa)

	int tempnumad1;
	int tempnumad2;
	int tempnumad3;
	int tempnumad4;

	ref adCharacter = GetCharacter(adCptnIdx);

	ref refStore;
	tempnumad2 = SBConvertPortNumToIslandIdx(adPortNum);
	for(tempnumad1 = 0; tempnumad1 < STORE_QUANTITY; tempnumad1++)
	{
		if(stores[tempnumad1].Island == Islands[tempnumad2].id)
		{
			tempnumad3 = tempnumad1;
		}
	}
	makeref (refStore, Stores[tempnumad3]);

	tempnumad4 = 0;
	for(tempnumad1 = 0; tempnumad1 < GOODS_QUANTITY; tempnumad1++)
	{
		if(!GetStoreGoodsUsed(refStore,tempnumad1))
		{
			continue;
		}

		tempnumad3 = GetCargoGoods(adCharacter,tempnumad1);
		if(tempnumad3 == 0)
		{
			continue;
		}

		if (IsCompanion(adCharacter))					// if he is currently a companion it uses maincharacter's commerce skill, otherwise (e.g. if he's on shore leave) it uses his own
		{
			tempnumad2 = GetGoodPriceByType(&refStore, GetMainCharacter(), tempnumad1, tempnumad3, PRICE_TYPE_SELL);
		}
		else
		{
			tempnumad2 = GetGoodPriceByType(&refStore, adCharacter, tempnumad1, tempnumad3, PRICE_TYPE_SELL);
		}
		tempnumad4 += tempnumad2;
	}

	return tempnumad4;
}




int SBConvertPortNumToIslandIdx(int aePortNum)
{
	// returns the island index (used by the entire game) when given the 0-7 port number (used only by ship berthing)
// KK -->
	if (aePortNum >= 0 && aePortNum < TOWNS_QUANTITY) {
		return FindIsland(Towns[aePortNum].island);
	}
	return FindIsland("KhaelRoa"); // screwface
// <-- KK
}




int SBGetShoreLeavePay(int amCaptainIdx, int amCrewQty)
{
	// returns the monthly shore leave pay, or potential monthly shore leave pay, of a ship

	int SHORE_LEAVE_PAY_REDUCTION = 4;
	int tempnumam1;
	int tempnumam2;
	float tempfloatam1;

	ref amCaptainChar = GetCharacter(amCaptainIdx);
	int amLeaderShip = GetShipSkill(amCaptainChar,SKILL_LEADERSHIP);

	// the following was heavily modified by me to make use of common payment routines -jsv, 2015-12-17
	// ***** 1: WORK OUT PAY FOR CREW *****
	
	float amCrewPaymentQ = makefloat(amCrewQty) * AdjustedCrewPay();
	if (TRACELOG == 1) { Trace("shore leave pay calculation: raw crew pay " + amCrewPaymentQ); }

	// ***** 2: WORK OUT OWN PAY AND OFFICERS' PAY *****
	float amOfficerPaymentQ = 0;

	// The original code had captain's salary reduced by half and other officer's salaried divided by 5;
	// after that everything was mistakingly divided by 4 again.
	// I just collect normal salaries, twice for the captain, and divide everything by 4 in the very end.
	if(CheckAttribute(amCaptainChar,"quest.OfficerPrice") && GetRemovable(amCaptainChar))
	{
//		tempfloatam1 = sti(amCaptainChar.quest.OfficerPrice)/2;
		tempfloatam1 = CalcEncOfficerPrice(amCaptainChar) * 2;		// LDH 16Apr09
		if (TRACELOG == 1) { Trace("shore leave pay calculation: captain taken into account, idx " + amCaptainIdx + ", pay " + tempfloatam1); }
		amOfficerPaymentQ += tempfloatam1;
	}

	for(tempnumam1 = 1; tempnumam1 < OFFICER_MAX; tempnumam1++)
	{
		tempnumam2 = GetOfficersIndex(amCaptainChar, tempnumam1);
		if(tempnumam2 == -1) continue;
		if(CheckAttribute(Characters[tempnumam2],"quest.OfficerPrice") && GetRemovable(&Characters[tempnumam2]))
		{
//			tempfloatam1 = sti(Characters[tempnumam2].quest.OfficerPrice)/5;
			tempfloatam1 = CalcEncOfficerPrice(Characters[tempnumam2]);		// LDH 16Apr09
			if (TRACELOG == 1) { Trace("shore leave pay calculation: officer taken into account, idx " + tempnumam2 + ", pay " + tempfloatam1); }
			amOfficerPaymentQ += tempfloatam1;
		}
	}
	if (TRACELOG == 1) { Trace("shore leave pay calculation: total raw officers' pay " + amOfficerPaymentQ); }

	int amFinalPayment = makeint((amCrewPaymentQ + amOfficerPaymentQ) / makefloat(SHORE_LEAVE_PAY_REDUCTION));
	if (TRACELOG == 1) { Trace("shore leave pay calculation: final result " + amFinalPayment); }

	return amFinalPayment;
}

// KK -->
int GetBerthedShipsQuantityForTown(string townID)
{
	int tbspidx = GetTownIndex(townID);
	if (tbspidx < 0) return -1;
	string tempattrib = "port" + tbspidx;

	// TIH --> attribute checking fix Jul10'06
	int tmpstatus = 0;
	ref PChar = GetMainCharacter();
	if (CheckAttribute(PChar, "ShipBerthing." + tempattrib + ".slot1.status")) tmpstatus  = sti(PChar.ShipBerthing.(tempattrib).slot1.status);
	if (CheckAttribute(PChar, "ShipBerthing." + tempattrib + ".slot2.status")) tmpstatus += sti(PChar.ShipBerthing.(tempattrib).slot2.status);
	if (CheckAttribute(PChar, "ShipBerthing." + tempattrib + ".slot3.status")) tmpstatus += sti(PChar.ShipBerthing.(tempattrib).slot3.status);
	if (CheckAttribute(PChar, "ShipBerthing." + tempattrib + ".slot4.status")) tmpstatus += sti(PChar.ShipBerthing.(tempattrib).slot4.status);
	// TIH <--
	return tmpstatus;
}
// <-- KK
