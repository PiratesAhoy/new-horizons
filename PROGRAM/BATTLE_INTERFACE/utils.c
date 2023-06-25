
native float funcGetSailSpeed(int holeQ,int holeMax,float sailPow);
native int RandomHole2Sail(int chrIdx, string reyName, int groupNum, int maxHole, int holeData, int addHoleQ);
native int DeleteOneSailHole(int chrIdx, string groupName, string reyName, int holeMask, int deleteHoleQ );
native string GetAssembledString(string formatStr, aref arDataBase);

#libriary "script_rigging_files"

//==========================================================
//   Секция починки при использовании специальных умений.
//
//==========================================================
#define BI_SLOW_REPAIR_PERCENT	1
#define BI_SLOW_REPAIR_PERIOD	1000
#define BI_FAST_REPAIR_PERCENT	5.0
#define BI_FAST_REPAIR_PERIOD	1000

#event_handler("evntActionRepair","procActionRepair");

void ActivateSpecRepair(ref chref,int repairType)
{
	if(repairType==0)
	{	PostEvent("evntActionRepair",BI_SLOW_REPAIR_PERIOD,"ll",sti(chref.index),0);
	}
	else
	{	PostEvent("evntActionRepair",BI_FAST_REPAIR_PERIOD,"llff",sti(chref.index),1, 0.0,0.0);
	}
}

void procActionRepair()
{
	int chrIdx = GetEventData();
	int eRepType = GetEventData();
	if(chrIdx<0) return;
	if(!bSeaActive)	return;
	ref chref = GetCharacter(chrIdx);
	if( LAi_IsDead(chref) ) return;

	if(eRepType!=0)
	{
		float fMaterialH = GetEventData();
		float fMaterialS = GetEventData();
	}

	if(bAbordageStarted)
	{
		if(eRepType==0)
		{
			PostEvent("evntActionRepair",BI_FAST_REPAIR_PERIOD,"ll", chrIdx, 0);
		}
		else
		{
			PostEvent("evntActionRepair",BI_FAST_REPAIR_PERIOD,"llff", chrIdx, eRepType, fMaterialH,fMaterialS);
		}
		return;
	}

	float hpp = GetHullPercent(chref);
	float spp = GetSailPercent(chref);
	float fRepairH,fRepairS;

	if(eRepType==0)
	//=====================================================
	// Slow repair
	//=====================================================
	{
		if(hpp<10.0)
		{
			fRepairH = 10.0-hpp;
			if(fRepairH>BI_SLOW_REPAIR_PERCENT)	{fRepairH=BI_SLOW_REPAIR_PERCENT;}
			hpp += ProcessHullRepair(chref,fRepairH);
		}
		if(spp<10.0)
		{
			fRepairS = 10.0-spp;
			if(fRepairS>BI_SLOW_REPAIR_PERCENT)	{fRepairS=BI_SLOW_REPAIR_PERCENT;}
			spp += ProcessSailRepair(chref,fRepairS);
		}
		if( IsPerkIntoList("LightRepair") ) {
			PostEvent("evntActionRepair",BI_SLOW_REPAIR_PERIOD,"ll",chrIdx,0);
		}
	}
	else
	//======================================================
	// Fast repair
	//======================================================
	{
		float ftmp1,ftmp2;
		int nMaterialH = GetCargoGoods(chref,GOOD_PLANKS);
		int nMaterialS = GetCargoGoods(chref,GOOD_SAILCLOTH);
		int nMatDeltaH = 0;
		int nMatDeltaS = 0;
		string goodsName;
		if(hpp<90.0 && nMaterialH>0)
		{
			fRepairH = 90.0-hpp;
			if(fRepairH>BI_FAST_REPAIR_PERCENT)	{fRepairH=BI_FAST_REPAIR_PERCENT;}
			ftmp1 = GetHullPPP(chref);
			ftmp2 = fMaterialH + ftmp1*fRepairH;
			if(ftmp2>nMaterialH)
			{
				fRepairH = (nMaterialH-fMaterialH)/ftmp1;
				nMatDeltaH = nMaterialH;
				fMaterialH = 0.0;
			}
			else
			{
				if(ftmp2>1.0)
				{
					nMatDeltaH = makeint(ftmp2);
					fMaterialH = ftmp2 - nMatDeltaH;
				}
			}
			hpp += ProcessHullRepair(chref,fRepairH);
		}
		if(spp<90.0 && nMaterialS>0)
		{
			fRepairS = 90.0-spp;
			if(fRepairS>BI_FAST_REPAIR_PERCENT)	{fRepairS=BI_FAST_REPAIR_PERCENT;}
			ftmp1 = GetSailSPP(chref);
			ftmp2 = fMaterialS + ftmp1*fRepairS;
			if(ftmp2>nMaterialS)	{ fRepairS = (nMaterialS-fMaterialS)/ftmp1; }
			fRepairS = ProcessSailRepair(chref,fRepairS);
			if(fRepairS<=0.0)
			{
				nMatDeltaS = 0;
				fMaterialS = 0.0;
				nMaterialS = 0;
			}
			else
			{
				ftmp2 = fMaterialS + ftmp1*fRepairS;
				if(ftmp2>1.0)
				{
					nMatDeltaS = makeint(ftmp2);
					fMaterialS = ftmp2 - nMatDeltaS;
				}
			}
		}
		if(nMatDeltaH>0)
		{
			nMaterialH -= nMatDeltaH;
			SetCharacterGoods(chref,GOOD_PLANKS,nMaterialH);	// LDH probably should use this 29Jan09
		}
		if(nMatDeltaS>0)
		{
			nMaterialS -= nMatDeltaS;
			SetCharacterGoods(chref,GOOD_SAILCLOTH,nMaterialS);	// LDH probably should use this 29Jan09
		}

		if(hpp<90.0 && nMaterialH>0)
		{	PostEvent("evntActionRepair",BI_FAST_REPAIR_PERIOD,"llff",chrIdx,1, fMaterialH,fMaterialS);
		}
		else
		{	if(spp<90.0 && nMaterialS>0)
			{	PostEvent("evntActionRepair",BI_FAST_REPAIR_PERIOD,"llff",chrIdx,1, fMaterialH,fMaterialS);
			}
			else
			{	EnableUsingAbility(chref,"InstantRepair");
			}
		}
	}
}
//============================================================

//============================================================
//	Починка заданного количества процентов повреждения корпуса
// (возвращает число реально починеных процентов,
//  материалы не использует, пробоины в корпусе удаляет)
//============================================================
float ProcessHullRepair(ref chref,float repPercent)
{
	if (repPercent == 0.0) return 0.0;			// LDH out of planks - 25Feb09
	float dmg = 100.0 - GetHullPercent(chref);
	if(dmg==0.0) return 0.0;
	if(repPercent>dmg) repPercent=dmg;
	int blotsQuantity = GetBlotsQuantity(chref);
	int repBlots = makeint(blotsQuantity*repPercent/dmg);
	DeleteBlots(chref,repBlots);
	float baseHP = makefloat(GetCharacterShipHP(chref));
	chref.ship.HP = baseHP+(repPercent-dmg)*baseHP/100.0;

	// LDH add repair skill for repairs - 25Dec08
	// This will add skill for repairs done at shipyard. This is intentional.
	if (AUTO_SKILL_SYSTEM) 
	{
		int AddSkill = makeint(repPercent + 0.5);  if (AddSkill < 20) AddSkill = 20;
		AddPartyExpChar(chref, "Repair", AddSkill));
		AddPartyExpChar(chref, "Defence", AddSkill);
	}

	return repPercent;
}

//============================================================
//	Починка заданного количества процентов повреждения парусов
// (возвращает число реально починеных процентов,
//  материалы не использует, дырки залатывает)
//============================================================
float ProcessSailRepair(ref chref, float repPercent)
{
	if (repPercent == 0.0) return 0.0;			// LDH out of sailcloth - 25Feb09
	float dmg = 100.0-GetSailPercent(chref);
	if(dmg==0.0) return 0.0;
	if(repPercent>dmg) repPercent=dmg;
	float maxShipSP = GetCharacterShipSP(chref); // new line by PaterBrown. Serge Grey have made tests ;)
	float fMakeRepair = (repPercent * maxShipSP)/100; // new line, was float fMakeRepair = repPercent;
	int i,j,rq,gq;
	aref arRoot,arGroup,arSail;
	string tmpstr;
	makearef(arRoot, chref.ship.sails);
	rq = GetAttributesNum(arRoot);
	for(i=0; i<rq; i++)
	{
		arGroup = GetAttributeN(arRoot, i);
		gq = GetAttributesNum(arGroup);
		for(j=0; j<gq; j++)
		{
			arSail = GetAttributeN(arGroup, j);
			if( CheckAttribute(arSail,"mastFall") )
			{
				tmpstr = "ship.masts."+arSail.mastFall;
				if( CheckAttribute(chref,tmpstr) && stf(chref.(tmpstr))>=1.0 )	{continue;}
			}
			fMakeRepair -= OneSailDmgRepair(chref,arGroup,arSail,fMakeRepair);
			if(fMakeRepair<=0.0) {break;}
			if(!CheckAttribute(chref,"ship.sails")) break;
			if(GetAttributesNum(arRoot)!=rq) break;
			if(GetAttributesNum(arGroup)!=gq)
			{
				gq = GetAttributesNum(arGroup);
				j--;
			}
		}
		if(fMakeRepair<=0.0) {break;}
		if(!CheckAttribute(chref,"ship.sails")) break;
		if(GetAttributesNum(arRoot)!=rq)
		{
			rq = GetAttributesNum(arRoot);
			i--;
		}
	}
	chref.ship.sp = CalculateShipSP(chref);	// Note: this is wrong for tutorial, damage isn't set correctly on tutorial ship - 25Feb09

	// LDH add repair skill for repairs - 21Jan09
	// This will add skill for repairs done at shipyard. This is intentional.
	if (AUTO_SKILL_SYSTEM)
	{
		if (sti(chref.index) == GetMainCharacterIndex())		// LDH 24Jan09
			Trace("Repair & Defence skill added in ProcessSailRepair: " + repPercent + " actual " + makeint(repPercent + 0.5));
		int AddSkill = makeint(repPercent + 0.5);  if (AddSkill < 20) AddSkill = 20;
		AddPartyExpChar(chref, "Repair", AddSkill); //Serge Grey: deleted excessive char ")".
		AddPartyExpChar(chref, "Defence", AddSkill);
	}
	return repPercent;
}

//=========================================================================
//	Починка заданного количества процентов повреждения конкретного паруса
//=========================================================================
float OneSailDmgRepair(ref chref, aref arSailNode, aref arSail, float fDmgRepair)
{
	if(fDmgRepair<=0.0) return 0.0;
	if(!CheckAttribute(arSail,"dmg")) return 0.0;//MAXIMUS
	float fSailDmg = stf(arSail.dmg);
	if(fDmgRepair>=fSailDmg)
	{
		DeleteOneSailHole( sti(chref.index), GetAttributeName(arSail), GetAttributeName(arSailNode), sti(arSail.hd), sti(arSail.hc) );
		DeleteAttribute(arSailNode,GetAttributeName(arSail));
		if( GetAttributesNum(arSailNode)==0 )
		{
			DeleteAttribute(chref,"ship.sails."+GetAttributeName(arSailNode));
		}
		return fSailDmg;
	}

	fSailDmg -= fDmgRepair;
	float sailDmgMax = GetCharacterShipSP(chref) * stf(arSail.sp);
	int iAfterHole = GetNeedHoleFromDmg( fSailDmg, sailDmgMax, sti(arSail.mhc) );
	if( sti(arSail.hc) > iAfterHole )
	{
		arSail.hd = DeleteOneSailHole( sti(chref.index), GetAttributeName(arSail), GetAttributeName(arSailNode), sti(arSail.hd), sti(arSail.hc)-iAfterHole );
		arSail.hc = iAfterHole;
	}
	arSail.dmg = fSailDmg;
	return fDmgRepair;
}

//============================================================
// Получить число дырок в корпусе корабля
//============================================================
int GetBlotsQuantity(ref chref)
{
	if( !CheckAttribute(chref,"ship.blots") ) return 0;
	aref blref;
	makearef(blref,chref.ship.blots);
	return GetAttributesNum(blref);
}

//============================================================
// Удалить заданное число дырок в корпусе корабля
//============================================================
void DeleteBlots(ref chref, int repBlots)
{
	if( !CheckAttribute(chref,"ship.blots") ) return;
	aref blref,curblots;
	makearef(blref,chref.ship.blots);
	int blotsQ = GetAttributesNum(blref);
	while(repBlots>0)
	{
		if(blotsQ==0) break;
		blotsQ--;
		curblots = GetAttributeN(blref,blotsQ);
		DeleteAttribute(blref,GetAttributeName(curblots));
	}
}


//================================================================
// Получить число дырок в парусах исходя из имеющихся повреждений
//================================================================
int GetNeedHoleFromDmg(float sailDmg, float sailDmgMax, int maxHoleCount)
{
	if(sailDmgMax<=0.0) return 0;
	int holeNeed = makeint(sailDmg/sailDmgMax*maxHoleCount);
	return holeNeed;
}

//================================================================
// Надырявить конкретный парус на заданное число дырок и получить
// маску получившихся дырок
// (в параметрах координаты паруса: индекс перса, полное имя реи и
//  номер группы; затем идут максимальное возможное число дырок в
//  парусе, текущая маска дырок и число дополнительных дырок)
//================================================================
/*int RandomHole2Sail(int chrIdx, string reyName, int groupNum, int maxHole, int holeData, int addHoleQ)
{
	return holeData;
}*/

//================================================================
// Получить повреждение в парусах исходя из имеющихся дырок
//================================================================
float GetNeedDmgFromHole(int holeCount, float sailDmgMax, int maxHoleCount)
{
	if(maxHoleCount<=0) return 0.0;
	return sailDmgMax*holeCount/maxHoleCount;
}

//================================================================
// Посчитать состояние парусов
//================================================================
float CalculateShipSP(ref chref)
{
	float fSP = GetCharacterShipSP(chref);
	aref arRoot,arGroup,arSail;
	int q,n,i,j;

	makearef(arRoot, chref.ship.sails);
	q = GetAttributesNum(arRoot);
	for(i=0; i<q; i++)
	{
		arGroup = GetAttributeN(arRoot,i);
		n = GetAttributesNum(arGroup);
		for(j=0; j<n; j++)
		{
			arSail = GetAttributeN(arGroup,j);
			if (CheckAttribute(arSail,"dmg"))	// LDH - avoid errors on missing dmg
				fSP -= stf(arSail.dmg);
		}
	}

	if(fSP<0.0) fSP = 0.0;
	return fSP;
}

//===============================================
// Заполнение 
//===============================================
int AddTextureToList(ref rHostObj, string texName, int hSize, int vSize)
{
	return SendMessage(rHostObj, "lsll", BI_MSG_ADD_NEWTEXTURE, texName, hSize, vSize);
}
