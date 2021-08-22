ref refMyCharacter;
ref refEnemyCharacter;

bool bBeParty;
int curOfficer;
ref xi_refMainChar;
ref xi_refCharacter;

int oldIndex = -1;

int ListMax;
ref MainChar;
ref newFriend = &NullCharacter; // KK

int nMyCharacterCompanionPlace = -1;
int nCompanionIndex = -1;

int nDiscardQuantity;
string strCurNodeName;

int curNum;

void InitInterface_RR(string iniName,ref pCharacter,ref enemyCh)
{
	int i;
	MainChar = GetMainCharacter();
	FillCharactersList(pCharacter);

	xi_refMainChar = GetMainCharacter();
	xi_refCharacter = pCharacter;
	nCompanionIndex = sti(enemyCh.index); //PW: if two companions involved

	refMyCharacter = xi_refCharacter;
	refEnemyCharacter = enemyCh;

	if(CheckAttribute(pCharacter,"InterfaceParam.i1")) {
		nMyCharacterCompanionPlace = sti(pCharacter.InterfaceParam.i1);
		nCompanionIndex = GetCompanionIndex(pCharacter,nMyCharacterCompanionPlace);
	}

// KK -->
	newFriend = &NullCharacter;
	if (nCompanionIndex == -1) {
		GameInterface.title = "titleAbordageTransfer";
	} else {
		newFriend = GetCharacter(nCompanionIndex);
		GameInterface.title = "titleTransferGoods";
	}
// <-- KK KK

	bBeParty = false;
	for(i=1;i<OFFICER_MAX  ;i++)	{if( GetOfficersIndex (pCharacter,i)>=0 ) bBeParty = true; break;}
	for(i=1;i<COMPANION_MAX;i++)	{if( GetCompanionIndex(pCharacter,i)>=0 ) bBeParty = true; break;}

	FillScroll();
	if(bAnimation && bNewInterface) iniName = "RESOURCE\INI\NEW_INTERFACES\ANIMATION\transfer_goods.ini";
    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

    CreateString(true,"MyShipType","",FONT_NORMAL,COLOR_NORMAL,104,270,SCRIPT_ALIGN_CENTER,0.8); // PS
    CreateString(true,"MyName","",FONT_NORMAL,COLOR_NORMAL,180,170,SCRIPT_ALIGN_CENTER,1.0); // MAXIMUS

	ref shipRef = GetShipByType(GetCharacterShipType(refEnemyCharacter)); // PS
	CreateImage("enemyShip",GetShipTextureName(sti(shipRef.index)),GetShipPicName(sti(shipRef.index)),472,240,600,368); // PS
    CreateString(true,"EnemyShipType",XI_ConvertString(shipRef.SName),FONT_NORMAL,COLOR_NORMAL,536,270,SCRIPT_ALIGN_CENTER,0.8); // PS

    CreateString(true,"MyShipName","",FONT_SEADOGS,COLOR_NORMAL,177,202,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(true,"EnemyShipName",refEnemyCharacter.ship.Name,FONT_SEADOGS,COLOR_NORMAL,463,202,SCRIPT_ALIGN_CENTER,1.0);

// added by MAXIMUS -->
	string curEnemyName = XI_ConvertString("No Captain Assigned");
	if(nCompanionIndex<0) 
	{
		if(CheckAttribute(refEnemyCharacter,"position"))
		{
			switch(refEnemyCharacter.position)
			{
				case "loser":
					curEnemyName = refEnemyCharacter.name + " " + refEnemyCharacter.lastname + " - " + XI_ConvertString("loser");
					//CreateString(true,"EnemyName",refEnemyCharacter.name + " " + refEnemyCharacter.lastname + " - " + XI_ConvertString("loser"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0);
				break;

				case "corpse":
					curEnemyName = XI_ConvertString("Dead") + " " + XI_ConvertString("s"+"captain");
					//CreateString(true,"EnemyName",XI_ConvertString("Dead") + " " + XI_ConvertString("captain"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0);
				break;

			// TIH --> changed to be less confusing Jul18'06
				// default:
				//CreateString(true,"EnemyName",XI_ConvertString("No Captain Assigned"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0);

			/* original method
				case "officer":
				    CreateString(true,"EnemyName",refEnemyCharacter.name + " " + refEnemyCharacter.lastname + " - " + XI_ConvertString("officer"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0);
				break;

				case "companion":
					CreateString(true,"EnemyName",refEnemyCharacter.name + " " + refEnemyCharacter.lastname + " - " + XI_ConvertString("s"+"companion"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0);
				break;

				case "captive":
					CreateString(true,"EnemyName",refEnemyCharacter.name + " " + refEnemyCharacter.lastname + " - " + XI_ConvertString("Scaptive"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0);
				break;
			*/
			// TIH <--
			}
		}
		else
		{
			curEnemyName = XI_ConvertString("Dead") + " " + XI_ConvertString("s"+"captain");
			//CreateString(true,"EnemyName",XI_ConvertString("Dead") + " " + XI_ConvertString("captain"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0);
		}
	}
	else 
	{
		if(IsCompanion(newFriend) || IsOfficerCompanion(newFriend))
		{
			curEnemyName = newFriend.name + " " + newFriend.lastname + " - " + XI_ConvertString("s"+"companion");
			//CreateString(true,"EnemyName",newFriend.name + " " + newFriend.lastname + " - " + XI_ConvertString("s"+"companion"),FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0); // MAXIMUS
		}
	}
	CreateString(true,"EnemyName",curEnemyName,FONT_NORMAL,COLOR_NORMAL,478,170,SCRIPT_ALIGN_CENTER,1.0); // MAXIMUS
// added by MAXIMUS <--

    CreateString(false,"GoodsName","",FONT_NORMAL,COLOR_NORMAL,320,234,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(false,"MyCargo","",FONT_NORMAL,COLOR_NORMAL,104,372,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(false,"EnemyCargo","",FONT_NORMAL,COLOR_NORMAL,536,372,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(false,"MyGoods","",FONT_BOLD_NUMBERS,COLOR_NORMAL,280,272,SCRIPT_ALIGN_RIGHT,1.0);
    CreateString(false,"EnemyGoods","",FONT_BOLD_NUMBERS,COLOR_NORMAL,360,272,SCRIPT_ALIGN_LEFT,1.0);
//	CreateString(true,"Weight",XI_ConvertString("weight"),FONT_NORMAL,COLOR_NORMAL,320,372,SCRIPT_ALIGN_CENTER,1.0);
    CreateString(false,"Discarding","",FONT_NORMAL,COLOR_NORMAL,320,314,SCRIPT_ALIGN_CENTER,1.0);

// --> MAXIMUS Interface MOD
	SetSelectable("EXIT_BUTTON",true);
	SetNodeUsing("VIDEOPIE",bAnimation && bNewInterface);
// <-- MAXIMUS Interface MOD

	SetNodeUsing("DISCARD_COUNTER",false);
	SetNodeUsing("ALL_DISCARD",false);
	SetNodeUsing("OK_DISCARD",false);
	SetNodeUsing("GOODS_DESCRIBE",false);

    EnableString("GoodsName");
    EnableString("MyCargo");
    EnableString("EnemyCargo");
    EnableString("MyGoods");
    EnableString("EnemyGoods");

	ChangeScroll();
	WasGoodsChange();
    SetVariable();

	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
    SetEventHandler("InterfaceCancel","ProcessCancelExit",0);
	SetEventHandler("TakeAllPress","TakeAllProcess",0);
	SetEventHandler("frame","WasGoodsChange",0);
	SetEventHandler("ChangerLeft","DoChangeLeft",0);
	SetEventHandler("ChangerRight","DoChangeRight",0);
	SetEventHandler("IEvnt_MouseClick","IProcMouseClick",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);

	if(!GetRemovable(enemyCh))
	{
		SetSelectable("GOODS_CHANGER",false);
		SetSelectable("TAKEALL_BUTTON",false);
	}
}

void SelectDiscard()
{
	if(GetSelectable("DISCARD_BUTTON")==true)	SetCurrentNode("DISCARD_BUTTON");
	else	SetCurrentNode("TAKEALL_BUTTON");
}

// TIH --> fixes loop hangs due to cargo that have too high of units numbers Jul20'06
void TransferCargoProcess(ref toChar, ref fromChar)
{
	// GOOD_GUNPOWDER is worst case scenario
	
	int goodsIdx 		= GetGoodsIndexForI(curNum);
	int changeQ 		= sti(Goods[goodsIdx].Units);
	int fromGoodsLeft 	= GetCargoGoods(fromChar,goodsIdx);

	// if the source has less units than a per-good transfer
	if ( fromGoodsLeft < changeQ ) changeQ = fromGoodsLeft;// set it down to what is actually left

	// if there is anything to be moved over
	if ( changeQ > 0 ) {
		if( CoreGoodAdding(toChar,goodsIdx,changeQ) )
		{
			// if it successfully added the goods to the destination, remove the goods from the source
			RemoveCharacterGoods(fromChar,goodsIdx,changeQ);
		} 
		else
		{
			// if there wasn't enough room for a bulk transfer, then loop through one by one until its full
			for(int i=0; i<changeQ; i++)
			{
				if(GetCargoGoods(fromChar,goodsIdx)<=0) break;
				if( !CoreGoodAdding(toChar,goodsIdx,1) ) break;
				RemoveCharacterGoods(fromChar,goodsIdx,1);
			}
		}
	}

	curNum = -1;
	WasGoodsChange();
}
// TIH <--

void DoChangeLeft()
{
	if( !GetSelectable("TAKEALL_BUTTON") ) { return; }
	TransferCargoProcess(xi_refCharacter, refEnemyCharacter);// TIH new method, reduces hangs Jul20'06
	/*
	int goodsIdx = GetGoodsIndexForI(curNum);
	int changeQ = sti(Goods[goodsIdx].Units);
	for(int i=0; i<changeQ; i++)
	{
		if(GetCargoGoods(refEnemyCharacter,goodsIdx)<=0) break;
		if( !CoreGoodAdding(xi_refCharacter,goodsIdx,1) ) break;
		RemoveCharacterGoods(refEnemyCharacter,goodsIdx,1);
	}
	if(i>0)
	{
		curNum = -1;
		WasGoodsChange();
	}
	*/
}

void DoChangeRight()
{
	TransferCargoProcess(refEnemyCharacter, xi_refCharacter);// TIH new method, reduces hangs Jul20'06
	/*
	int goodsIdx = GetGoodsIndexForI(curNum);
	int changeQ = sti(Goods[goodsIdx].Units);
	for(int i=0; i<changeQ; i++)
	{
		if(GetCargoGoods(xi_refCharacter,goodsIdx)<=0) break;
		if( !CoreGoodAdding(refEnemyCharacter,goodsIdx,1) ) break;
		RemoveCharacterGoods(xi_refCharacter,goodsIdx,1);
	}
	if(i>0)
	{
		curNum = -1;
		WasGoodsChange();
	}
	*/
}

void SetNextParty(bool bRight)
{
	string tempstring;
	int tempidx;

	if (bRight)
	{
		curOfficer++;
		if (curOfficer > ListMax) { curOfficer = 1; }
	}
	else
	{
		curOfficer--;
		if (curOfficer < 1) { curOfficer = ListMax; }
	}

	tempstring = "member" + curOfficer;
	tempidx = sti(MainChar.tempCharactersList.(tempstring).idx);
	xi_refCharacter = GetCharacter(tempidx);
	AddCharacterExp(xi_refCharacter,0);
}

void FillCharactersList(ref ViewingCharacter)
{
	int tempnum1;
	int tempnum2;
	int tempnum3;
	int tempnum4;
	int tempnum5;
	ref tempchar;
	string tempstring1;
	string tempstring2;
	string tempstring3;

	If (CheckAttribute(MainChar,"tempCharactersList"))
	{
		DeleteAttribute(MainChar,"tempCharactersList");
		if (TRACELOG == 1) { Trace("deleted existing list"); }
	}

	ListMax = 1;



	// ******* STEP 1/5: ADD MAIN CHARACTER *******

	MainChar.tempCharactersList.member1.idx = sti(MainChar.index);
	if (TRACELOG == 1) { Trace("added mainchar"); }
	ListMax++;



	// ******* STEP 3/5: ADD COMPANIONS AND THEIR OFFICERS *******

	for (tempnum1 = 1; tempnum1 < COMPANION_MAX; tempnum1++)
	{
		tempnum2 = GetCompanionIndex(MainChar,tempnum1);
		if(tempnum2>=0 && IsTrader(&characters[tempnum2]) == true) continue;//MAXIMUS: such companion will not be added // KK
// LDH deleted, causes "Using reference variable without initializing" errors - 20Feb09
//		if(CheckAttribute(newFriend,"index") && tempnum2==sti(newFriend.index)) continue;//MAXIMUS: companion will not be added
		if (tempnum2 >= 0)
		{
			tempstring1 = "member" + ListMax;
			MainChar.tempCharactersList.(tempstring1).idx = tempnum2;
			if (TRACELOG == 1) { Trace("added list member " + ListMax + ": idx " + tempnum2 + " type 2"); }
			ListMax++;

			tempchar = GetCharacter(tempnum2);
			for (tempnum3 = 1; tempnum3 < OFFICER_MAX; tempnum3++)
			{
				tempnum4 = GetOfficersIndex(tempchar,tempnum3);
				if (TRACELOG == 1) { Trace("checking officer " + tempnum3 + ", idx " + tempnum4 + ", of companion " + tempnum1 + ", idx " + tempnum2); }
				if (tempnum4 >= 0)
				{
					tempstring1 = "member" + ListMax;
					MainChar.tempCharactersList.(tempstring1).idx = tempnum4;
					if (TRACELOG == 1) { Trace("added list member " + ListMax + ": idx " + tempnum4 + " type 3"); }
					ListMax++;
				}
			}
		}
	}

	ListMax--;
	if (TRACELOG == 1) { Trace("list total: " + ListMax); }
	curOfficer = 1;
	xi_refCharacter = GetMainCharacter();

	tempnum3 = sti(ViewingCharacter.index);
	for (tempnum1 = 1; tempnum1 <= ListMax; tempnum1++)
	{
		tempstring1 = "member" + tempnum1;
		tempnum2 = sti(MainChar.tempCharactersList.(tempstring1).idx);
		if (tempnum2 == tempnum3)
		{
			curOfficer = tempnum1;
			xi_refCharacter = GetCharacter(tempnum2);
		}
	}

	AddCharacterExp(xi_refCharacter,0);
}

void SetVariable()
{
	bool bShown = true;
	if(GetCompanionQuantity(GetMainCharacter())<COMPANION_MAX)
	{
		for(int i=1; i<COMPANION_MAX; i++)
		{
			int cidx = GetCompanionIndex(GetMainCharacter(), i);
			if (cidx < 0) continue;
			if (bShown) {
				bShown = nCompanionIndex != cidx && IsTrader(&characters[cidx]) == false;
			}
		}
	}

	SetNodeUsing("LEFTCHANGE_CHARACTER", bAbordageStarted && GetCompanionQuantity(GetMainCharacter())>1 && bShown);
	SetSelectable("LEFTCHANGE_CHARACTER", bAbordageStarted && GetCompanionQuantity(GetMainCharacter())>1 && bShown);
	SetNodeUsing("RIGHTCHANGE_CHARACTER", bAbordageStarted && GetCompanionQuantity(GetMainCharacter())>1 && bShown);
	SetSelectable("RIGHTCHANGE_CHARACTER", bAbordageStarted && GetCompanionQuantity(GetMainCharacter())>1 && bShown);

	ref shipRef = GetShipByType(GetCharacterShipType(xi_refCharacter));
	CreateImage("myShip",GetShipTextureName(sti(shipRef.index)),GetShipPicName(sti(shipRef.index)),40,240,168,368);

	GameInterface.goodslist.current = curNum;
	GameInterface.strings.MyShipType = XI_ConvertString(shipRef.SName);
    GameInterface.strings.MyShipName = xi_refCharacter.ship.Name;

	if(IsMainCharacter(xi_refCharacter) && CheckAttribute(xi_refCharacter,"title") && xi_refCharacter.title!="") bShown = true;
	else bShown = false;
	if(bShown) GameInterface.strings.MyName = GetMyRespectfullyName(xi_refCharacter);
	else GameInterface.strings.MyName = GetMySimpleName(xi_refCharacter);

	SetNodeUsing("GOODS_CHANGER",GetCargoGoods(xi_refCharacter,GetGoodsIndexForI(curNum))+GetCargoGoods(refEnemyCharacter,GetGoodsIndexForI(curNum))>0 && !GetSelectable("ALL_DISCARD"));

	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"exp",0);
	oldIndex = -1;
	ChangeScroll();
	WasGoodsChange();
}

void FillScroll()
{
	int i;
	string attributeName;
    aref pRef;
    string goodsName;

    GameInterface.goodslist.current = 0;
	//GameInterface.goodslist.ListSize = GOODS_QUANTITY;// TIH
	GameInterface.goodslist.ImagesGroup.t1 = "ICONS";
	if(bNewIcons==true) GameInterface.goodslist.ImagesGroup.t2 = "GOODS_NEW";
	else GameInterface.goodslist.ImagesGroup.t2 = "GOODS";
	GameInterface.goodslist.SpecTechniqueColor = argb(55,255,255,255);
	GameInterface.goodslist.SpecTechniqueName = "iSpec1";
	int idx = 1;// TIH
	for(i=0; i<GOODS_QUANTITY; i++)
	{
		if (!CANNONPOWDER_MOD && i == GOOD_GUNPOWDER) continue;// TIH dont show if mod is OFF
	//	if (USE_REAL_CANNONS && i == GOOD_BOMBS) continue;// TIH dont show if mod is ON // PB: Commented out to enable transferring bombs when you got some from the forts
		attributeName = "pic" + idx;// TIH
        makearef(pRef,GameInterface.goodslist.(attributeName));
        goodsName = Goods[i].Name;
		pRef.str1 = goodsName;
		pRef.str2 = "";
		pRef.img2 = goodsName;
		pRef.img1 = "cannon back";
		pRef.tex2 = 1;
		pRef.tex1 = 0;
		pRef.goodsNum = i;
		idx++;// TIH
	}
	GameInterface.goodslist.ListSize = idx-1;// TIH
}

void ChangeScroll()
{
	int i;
	string attributeName;
    aref pRef;
    string goodsName;
	// fill visible goods
	int idx = 1;
	for(i=0; i<GOODS_QUANTITY; i++)
	{
		if(GetCargoGoods(xi_refCharacter,i)==0 && GetCargoGoods(refEnemyCharacter,i)==0) continue;
		if (!CANNONPOWDER_MOD && i == GOOD_GUNPOWDER) continue;// TIH dont show if mod is OFF Jul10'06
	//	if (USE_REAL_CANNONS && i == GOOD_BOMBS) continue;// TIH dont show if mod is ON Jul10'06 // PB: Commented out to enable transferring bombs when you got some from the forts
		attributeName = "pic" + idx;
		GameInterface.goodslist.(attributeName).str1 = Goods[i].Name;
		GameInterface.goodslist.(attributeName).str2 = "#"+GetCargoGoods(xi_refCharacter,i);//Goods[i].Name;
		GameInterface.goodslist.(attributeName).spec2 = false;
		GameInterface.goodslist.(attributeName).img1 = "cannon back";
		GameInterface.goodslist.(attributeName).img2 = Goods[i].Name;
		GameInterface.goodslist.(attributeName).goodsNum = i;
		GameInterface.goodslist.(attributeName).tex1 = 0;
		GameInterface.goodslist.(attributeName).tex2 = 1;
		idx++;
	}
	// fill invisible goods
	for(i=0; i<GOODS_QUANTITY; i++)
	{
		if(GetCargoGoods(xi_refCharacter,i)!=0 || GetCargoGoods(refEnemyCharacter,i)!=0) continue;
		if (!CANNONPOWDER_MOD && i == GOOD_GUNPOWDER) continue;// TIH dont show if mod is OFF Jul10'06
	//	if (USE_REAL_CANNONS && i == GOOD_BOMBS) continue;// TIH dont show if mod is ON Jul10'06 // PB: Commented out to enable transferring bombs when you got some from the forts
		attributeName = "pic" + idx;
		GameInterface.goodslist.(attributeName).str1 = "";
		GameInterface.goodslist.(attributeName).str2 = "";
		GameInterface.goodslist.(attributeName).spec2 = true;
		GameInterface.goodslist.(attributeName).img1 = "cannon back";
		GameInterface.goodslist.(attributeName).img2 = Goods[i].Name;
		GameInterface.goodslist.(attributeName).goodsNum = i;
		GameInterface.goodslist.(attributeName).tex1 = 0;
		GameInterface.goodslist.(attributeName).tex2 = 1;
		idx++;
	}

	GameInterface.strings.MyCargo = GetCargoLoad(xi_refCharacter) + "/" + GetCargoMaxSpace(xi_refCharacter);
	GameInterface.strings.MyGoods = GetCargoGoods(xi_refCharacter,GetGoodsIndexForI(curNum));
	GameInterface.strings.EnemyCargo = GetCargoLoad(refEnemyCharacter) + "/" + GetCargoMaxSpace(refEnemyCharacter);
	GameInterface.strings.GoodsName = XI_ConvertString(Goods[GetGoodsIndexForI(curNum)].Name);
	GameInterface.strings.EnemyGoods = GetCargoGoods(refEnemyCharacter,GetGoodsIndexForI(curNum)));

    SendMessage(&GameInterface,"lsl",MSG_INTERFACE_SCROLL_CHANGE,"GOODSLIST",-1);
	bool isEnable = false;
//	if(GetRemovable(xi_refCharacter) && GetCargoGoods(xi_refCharacter,GetGoodsIndexForI(curNum))>0)
//	{
	if(CheckAttribute(xi_refCharacter,"name") && CheckAttribute(xi_refCharacter,"lastname")) string myname = xi_refCharacter.name + " " + xi_refCharacter.lastname;
	if(CheckAttribute(newFriend,"name") && CheckAttribute(newFriend,"lastname")) string enemyname = newFriend.name + " " + newFriend.lastname;

	if(xi_refCharacter.index == refEnemyCharacter.index || myname == enemyname) isEnable = false;
	else isEnable = true;
	SetSelectable("DISCARD_BUTTON",GetCargoGoods(xi_refCharacter,GetGoodsIndexForI(curNum)));
	SetSelectable("TAKEALL_BUTTON",isEnable);
/*	}
	else
	{
		SetSelectable("DISCARD_BUTTON",GetCargoGoods(xi_refCharacter,GetGoodsIndexForI(curNum)));
	}*/
	if(GetCargoGoods(xi_refCharacter,GetGoodsIndexForI(curNum))+GetCargoGoods(refEnemyCharacter,GetGoodsIndexForI(curNum))==0) isEnable = false;
	if(GetSelectable("ALL_DISCARD")) isEnable = false;
	SetNodeUsing("GOODS_CHANGER",isEnable);
 // added by MAXIMUS -->
	if(GetCargoGoods(refEnemyCharacter,GetGoodsIndexForI(curNum))>0 && GetCargoLoad(xi_refCharacter)!=GetCargoMaxSpace(xi_refCharacter)) SetSelectable("TAKEALLCURRENT_BUTTON",isEnable);
	else SetSelectable("TAKEALLCURRENT_BUTTON",false);
	SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"TAKEALLCURRENT_BUTTON",0,XI_ConvertString(Goods[GetGoodsIndexForI(curNum)].Name)+" - "+XI_ConvertString("TakeAll"));
 // added by MAXIMUS <--
}

void WasGoodsChange()
{
	if(nDiscardQuantity>0) SetSelectable("OK_DISCARD",true);
	else SetSelectable("OK_DISCARD",false);
	if(curNum != sti(GameInterface.goodslist.current))
	{
		curNum = sti(GameInterface.goodslist.current);
	}
	    ChangeScroll();
}

void ProcessCancelExit()
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
    DelEventHandler("InterfaceCancel","ProcessCancelExit");
	DelEventHandler("TakeAllPress","TakeAllProcess");
	DelEventHandler("frame","WasGoodsChange");
	DelEventHandler("ChangerLeft","DoChangeLeft");
	DelEventHandler("ChangerRight","DoChangeRight");
	DelEventHandler("IEvnt_MouseClick","IProcMouseClick");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

	interfaceResultCommand = RC_INTERFACE_TRANSFER_MAIN_RETURN;
	EndCancelInterface(true);
}

void ProcessDiscard()
{
    SetNodeUsing("DISCARD_COUNTER",true);
    SetNodeUsing("ALL_DISCARD",true);
    SetNodeUsing("OK_DISCARD",true);
    SetNodeUsing("TAKEALL_BUTTON",false);
    SetNodeUsing("DISCARD_BUTTON",false);
    SetNodeUsing("GOODS_CHANGER",false);
    EnableString("Discarding");
    EnableString("GoodsName");
    DisableString("MyCargo");
    DisableString("EnemyCargo");
    DisableString("MyGoods");
    DisableString("EnemyGoods");
    DisableString("Weight");
    nDiscardQuantity = 0;
    GameInterface.strings.Discarding = "0";
}

void DiscardOk()
{
	RemoveCharacterGoods(xi_refCharacter,GetGoodsIndexForI(curNum),nDiscardQuantity);
    SetNodeUsing("DISCARD_BUTTON",true);
    SetNodeUsing("TAKEALL_BUTTON",true);
    SetNodeUsing("GOODS_CHANGER",true);
    SetNodeUsing("DISCARD_COUNTER",false);
    SetNodeUsing("ALL_DISCARD",false);
    SetNodeUsing("OK_DISCARD",false);
    DisableString("Discarding");
    EnableString("GoodsName");
    EnableString("MyCargo");
    EnableString("EnemyCargo");
    EnableString("MyGoods");
    EnableString("EnemyGoods");
    EnableString("Weight");
	SetCurrentNode("GOODSLIST");
	PlayStereoSound("OBJECTS\SHIPCHARGE\take_prey.wav");
	ChangeScroll();
}

void DiscardAll()
{
    nDiscardQuantity = GetCargoGoods(xi_refCharacter,GetGoodsIndexForI(curNum));
    DiscardOk();
	PlayStereoSound("OBJECTS\SHIPCHARGE\take_prey.wav");
}

void DiscardCancel()
{
    SetNodeUsing("DISCARD_BUTTON",true);
    SetNodeUsing("TAKEALL_BUTTON",true);
    SetNodeUsing("GOODS_CHANGER",true);
    SetNodeUsing("DISCARD_COUNTER",false);
    SetNodeUsing("ALL_DISCARD",false);
    SetNodeUsing("OK_DISCARD",false);
    DisableString("Discarding");
    EnableString("GoodsName");
    EnableString("MyCargo");
    EnableString("EnemyCargo");
    EnableString("MyGoods");
    EnableString("EnemyGoods");
    EnableString("Weight");
	SetCurrentNode("GOODSLIST");
	ChangeScroll();
}

void DecreaseDiscard()
{
    if(nDiscardQuantity>0)
    {
        nDiscardQuantity = nDiscardQuantity - GetGoodsUnitSize();
		if(nDiscardQuantity<0) nDiscardQuantity = 0;
        GameInterface.strings.Discarding = ""+nDiscardQuantity;
		int oldGoodsQ = GetCargoGoods(xi_refCharacter,GetGoodsIndexForI(curNum));
		int deltaGoodsW = GetGoodWeightByType(GetGoodsIndexForI(curNum),oldGoodsQ-nDiscardQuantity) - GetGoodWeightByType(GetGoodsIndexForI(curNum),oldGoodsQ);
    }
}

void IncreaseDiscard()
{
    if( nDiscardQuantity<GetCargoGoods(xi_refCharacter,GetGoodsIndexForI(curNum)) )
    {
		nDiscardQuantity = nDiscardQuantity + GetGoodsUnitSize();
		if( nDiscardQuantity > GetCargoGoods(xi_refCharacter,GetGoodsIndexForI(curNum)) )
		{
			nDiscardQuantity = GetCargoGoods(xi_refCharacter,GetGoodsIndexForI(curNum));
		}
        GameInterface.strings.Discarding = ""+nDiscardQuantity;
		int oldGoodsQ = GetCargoGoods(xi_refCharacter,GetGoodsIndexForI(curNum));
		int deltaGoodsW = GetGoodWeightByType(GetGoodsIndexForI(curNum),oldGoodsQ-nDiscardQuantity) - GetGoodWeightByType(GetGoodsIndexForI(curNum),oldGoodsQ);
    }
}

int GetGoodsUnitSize()
{
	if(curNum<0) return 0;
	return sti( Goods[GetGoodsIndexForI(curNum)].Units );
}

void TakeAllProcess()
{
	int i;
	int itmp;
	int freeSpace;
	int freeQuantity;
// NK -->
	int x,y;
	float holder;
	int place;

	float GoodsSort[33];
	int GSID[33];

	for(i = 0; i < GOODS_QUANTITY; i++)
	{
		GoodsSort[i] = GetGoodPricePerWeight(i);
		GSID[i] = i;
	}

// bubblesort grabbed from http://www.metalshell.com/view/source/105/
	for(x = 0; x < GOODS_QUANTITY; x++)
	{
		for(y = 0; y < GOODS_QUANTITY-1; y++)
		{
			if(GoodsSort[y] < GoodsSort[y+1])
			{
				holder = GoodsSort[y+1];
				place = GSID[y+1];
				GoodsSort[y+1] = GoodsSort[y];
				GSID[y+1] = GSID[y];
				GoodsSort[y] = holder;
				GSID[y] = place;
      			}
		}
	}

	for(i=0;i<GOODS_QUANTITY;i++)
	{
		freeSpace = GetCargoFreeSpace(xi_refCharacter);
		freeQuantity = GetGoodQuantityByWeight(GSID[i],freeSpace);
		itmp = GetCargoGoods(refEnemyCharacter,GSID[i]);
		if(itmp<=freeQuantity)
		{
			AddCharacterGoods(xi_refCharacter,GSID[i],itmp);
			RemoveCharacterGoods(refEnemyCharacter,GSID[i],itmp);
		}
		else
		{
			AddCharacterGoods(xi_refCharacter,GSID[i],freeQuantity);
			RemoveCharacterGoods(refEnemyCharacter,GSID[i],freeQuantity);
		}
	}
// NK -->
	ProcessCancelExit();
}

// added by MAXIMUS [take all current GOOD] -->
void TakeCurrentProcess()
{
	int i;
	int itmp;
	int freeSpace;
	int freeQuantity;

// TIH --> nonneeded loop bug fix Jul20'06
//	for(i=0;i<GOODS_QUANTITY;i++)
//	{
		freeSpace = GetCargoFreeSpace(xi_refCharacter);
		freeQuantity = GetGoodQuantityByWeight(GetGoodsIndexForI(curNum),freeSpace);
		itmp = GetCargoGoods(refEnemyCharacter,GetGoodsIndexForI(curNum));
		if(itmp<=freeQuantity)
		{
			AddCharacterGoods(xi_refCharacter,GetGoodsIndexForI(curNum),itmp);
			RemoveCharacterGoods(refEnemyCharacter,GetGoodsIndexForI(curNum),itmp);
		}
		else
		{
			AddCharacterGoods(xi_refCharacter,GetGoodsIndexForI(curNum),freeQuantity);
			RemoveCharacterGoods(refEnemyCharacter,GetGoodsIndexForI(curNum),freeQuantity);
		}

//	}
}
// added by MAXIMUS [take all current GOOD] <--

ref GetMyCharacterRef()
{
	return refMyCharacter;
}

ref GetEnemyCharacterRef()
{
	return refEnemyCharacter;
}

int CoreGoodAdding(ref charRef, int goodType, int goodQuantity)
{
	int oldGood = GetCargoGoods(charRef,goodType);
	int newGoodWeight = GetGoodWeightByType(goodType,oldGood+goodQuantity);
	int oldGoodWeight = GetGoodWeightByType(goodType,oldGood);
	int freeSpace = GetCargoFreeSpace(charRef);
	if( freeSpace >= (newGoodWeight-oldGoodWeight) ) // TIH teeny glitch fix Jul20'06
	{
		SetCharacterGoods(charRef, goodType, oldGood+goodQuantity);
		return true;
	}
	return false;
}

int GetGoodsIndexForI(int n)
{
	if(n<0) return 0;
	string attrName = "pic"+(n+1);
	return sti(GameInterface.goodslist.(attrName).goodsNum);
}

void IProcMouseClick()
{
	string nodName = GetEventData();
	int btnCode = GetEventData();

	if(nodName=="GOODS_CHANGER")
	{
		if(btnCode==0) DoChangeLeft();
		if(btnCode==1) DoChangeRight();
	}
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	switch(nodName)
	{	
	case "GOODSLIST":
		if(comName=="activate" || comName=="downstep")	{SelectDiscard();}
	break;

	case "DISCARD_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			ProcessDiscard();
			SetCurrentNode("DISCARD_COUNTER");
		}
	break;

	case "DISCARD_COUNTER":
		if(comName=="deactivate")	{DiscardCancel();}
		if(comName=="leftstep")		{DecreaseDiscard();}
		if(comName=="rightstep")	{IncreaseDiscard();}
	break;

	case "ALL_DISCARD":
		if(comName=="deactivate")	{DiscardCancel();}
		if(comName=="activate" || comName=="click")
		{
			DiscardAll();
			SetCurrentNode("GOODSLIST");
		}
	break;

	case "OK_DISCARD":
		if(comName=="deactivate")	{DiscardCancel();}
		if(comName=="activate" || comName=="click")
		{
			DiscardOk();
			SetCurrentNode("GOODSLIST");
		}
	break;
// added by MAXIMUS [take all current GOOD] -->
	case "TAKEALLCURRENT_BUTTON":
		if(comName=="activate" || comName=="click")
		{
			TakeCurrentProcess();
			SetCurrentNode("GOODSLIST");
		}
	break;
// added by MAXIMUS [take all current GOOD] <--
	case "GOODS_CHANGER":
		if(comName=="downstep")
		{	if( GetSelectable("TAKEALL_BUTTON") )
			{	SetCurrentNode("TAKEALL_BUTTON");
			}
		}
	break;

	case "LEFTCHANGE_CHARACTER":
		if(comName=="click")
		{
			if(bBeParty)
			{
				SetNextParty(false);
				SetVariable();
			}
		}
	break;

	case "RIGHTCHANGE_CHARACTER":
		if(comName=="click")
		{
			if(bBeParty)
			{
				SetNextParty(true);
				SetVariable();
			}
		}
	break;
	}
}
