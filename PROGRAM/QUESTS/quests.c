#include "quests\quests_abordage.c"
#include "quests\quests_check.c"
#include "quests\quests_movie.c"
#include "quests\characters_task.c"
#include "quests\quests_scenes.c"
#include "quests\quests_common.c" // KK
#include "quests\quests_side.c"   // PB
#include "quests\quests_utils.c"

#define SHIPFORMATION_LINE	0

#event_handler("LocationWaitNihgtEnd","WaitDatePostEventControl");
#event_handler("evntQuestCameraRestore","QuestCameraRestore");
#event_handler("QuestDelayExit","DoQuestDelayExit");
#event_handler("QuitFromWorldMap","ReloadFromWMtoL_complete");
#event_handler(FORT_DESTROYED,"QuestFortDestroyed");
// KK -->
#event_handler(COLONY_CAPTURED, "QuestColonyCaptured");
// <-- KK
#event_handler("wdmCreateMap","QuestsCheck");
#event_handler("evntQuestsCheck","QuestsCheck");
#event_handler("evntQuestComplete","procEvntQuestComplete");
// NK add direct 05-04-17 -->
#event_handler("evntQuestCompleteDirect","procEvntQuestCompleteDirect");

object QuestText; // KK

void procEvntQuestCompleteDirect()
{
	string qname = GetEventData();
	/*ref mch = GetMainCharacter();

	if( CheckAttribute(mch,"quest."+qname) )
	{
		if( CheckAttribute(mch,"quest."+qname+".win_condition") )
		{*/
			CompleteQuestName(qname);
			/*QuestsCheck();
		}
		else
		{
			trace("WARNING! Not win condition for quest " + qname);
		}
	}
	else
	{
		trace("WARNING! Not found quest name: " + qname);
	}*/
}
// NK <--

void QuestsInit()
{
	ref rch = GetMainCharacter();
	aref postEvDelay, arTmp;
	makearef(postEvDelay,rch.PostEventQuest.questDelay);
	int q = GetAttributesNum(postEvDelay);
	for(int i=0; i<q; i++)
	{
		arTmp = GetAttributeN(postEvDelay,i);
		DoQuestCheckDelay(arTmp.qname, stf(arTmp.delay));
	}

	SetEventHandler(EVENT_CHARACTER_DEAD,"CharacterDeadProcess",0);
	SetEventHandler(EVENT_LOCATION_LOAD,"QuestsCheck_forLocEnter",0);
	SetEventHandler(EVENT_LOCATION_LOAD,"ExecuteLocationEntryActivity",0);
	SetEventHandler(EVENT_LOCATION_UNLOAD,"QC_DoUnloadLocation",0);
	SetEventHandler(EVENT_SEA_LOGIN,"QuestsCheck",0);
	SetEventHandler(EVENT_DIALOG_EXIT,"QuestDialogExitProcedure",0);
	SetEventHandler("NextDay","QuestsCheck",0);
	SetEventHandler(SHIP_DEAD,"QuestsCheck",0);

	SetEventHandler(ABORDAGE_START_EVENT,"QuestAbordageStartEvent",0);
}

void QuestsCheck_forLocEnter()
{
	QC_DoUnloadLocation();
	QuestsCheck();
}

void CharacterDeadProcess()
{
	aref charef = GetEventData();
	if (!CheckAttribute(charef, "index") || sti(charef.index) < 0) {
		QuestsCheck();
		return;
	}
	ref chref = GetCharacter(sti(charef.index));

	int charType = FindFellowtravellers(GetMainCharacter(),chref);
	switch(charType)
	{
	case FELLOWTRAVEL_COMPANION:
		RemoveCharacterCompanion(GetMainCharacter(),chref);
	break;
	case FELLOWTRAVEL_OFFICER:
		RemoveOfficersIndex(GetMainCharacter(),sti(chref.index));
		RemovePassenger(GetMainCharacter(),chref);
	break;
	case FELLOWTRAVEL_PASSENGER:
		RemovePassenger(GetMainCharacter(),chref);
	break;
	case FELLOWTRAVEL_CAPTIVE:
		RemovePassenger(GetMainCharacter(),chref);
	break;
	}
	QuestsCheck();
}

//*****************************************************
// Quest information utilite
//*****************************************************
aref GetQuestData(string idQuest)
{
	aref qdat;
	ref mainCh = GetMainCharacter();
	makearef(qdat,mainCh.QuestInfo.(idQuest));
	return qdat;
}
// US version:
bool CheckQuestRecord(aref qref,string textId)
{
	ref mc = GetMainCharacter();//PW need to check player attribute to allow repeat questbook entries for poker tournament
	/*if( CheckAttribute(qref,"Text") )
	{
		int pos0,pos1;
		string strpatch;
		pos0 = 0;
		while(true)
		{
			pos1 = findSubStr(qref.Text,",",pos0));
			if(pos1==-1)
			{
			}
			else
			{
			}
		}
	}
	else return false; //*/
	//bool retVal = SendMessage(&GameInterface,"las",MSG_INTERFACE_CHECK_QRECORD,qref,textId);
// This version falsely passes if it is looking for textId 2 and finds textId 22
/*	bool retVal = hasSubStr(qref.Text, textId + ","); // KK
	if (!retVal) retVal = hasSubStr(qref.Text, "," + textId); // KK
	return retVal; */
	bool retVal = false;
	if(!CheckAttribute(qref,"Text")) return false;
	if(qref.Text == textID) retVal = true;					// Check if textID is the only record present
	if(!retVal)
	{
		string strpatch = "*" +qref.Text + "*";				// Put markers at start and end of qref.Text, then check if textID is at either end
		retVal = hasSubstr(strpatch, "*" + textID + ",") || hasSubstr(strpatch, "," + textID + "*");
		if(!retVal) retVal = hasSubstr(qref.text, "," + textID + ",");	// Check if textID is somewhere in the middle
	}
	if (CheckAttribute(mc,"quest.poker.winner")) retVal = false;//PW allow repeat questbook entries for poker tournament iterations
	return retVal;
}
void SetQuestHeader(string idQuest)
{
	ref mainCh = GetMainCharacter();
	if(!CheckAttribute(mainCh,"QuestInfo."+idQuest))
	{
		object refNewAttr;
		refNewAttr.(idQuest).Complete = false;
		refNewAttr.(idQuest).Title = GetQuestBookTitle(idQuest); // KK
		refNewAttr.(idQuest).Text = "";

		aref refOldAttr; makearef(refOldAttr,mainCh.QuestInfo);
		string qName;
		aref curQ, newQ,oldQ;
		for(int i=0; i<GetAttributesNum(refOldAttr); i++)
		{
			curQ = GetAttributeN(refOldAttr,i);
			qName = GetAttributeName(curQ);
			refNewAttr.(qName) = "";
			makearef(newQ,refNewAttr.(qName));
			makearef(oldQ,refOldAttr.(qName));
			CopyAttributes(newQ,oldQ);
		}
		CopyAttributes(refOldAttr,&refNewAttr);
	}
}
void AddQuestRecord(string idQuest, int recordno)
{
	ref mc = GetMainCharacter(); // KK
	if(CheckAttribute(mc, "QuestInfo."+idQuest)==false) // KK
	{
		SetQuestHeader(idQuest);
	}
	string text = "";
	aref questRef; // KK
	string idText = "" + recordno; // KK
	if (CheckAttribute(mc, "QuestInfo."+idQuest+".Text") && mc.QuestInfo.(idQuest).Text != "") {
		makearef(questRef,mc.QuestInfo.(idQuest));
		if (!CheckQuestRecord(questRef,idText)) {
			string tmpStr = questRef.Text+","+idText; // KK
			questRef.Text = tmpStr;
			Log_SetStringToLog(XI_ConvertString("Logbook Update"));
			AddMsgToCharacter(mc,MSGICON_LOGBOOK);
			PlaySound("INTERFACE\notebook.wav");
		}
	} else {
		mc.QuestInfo.(idQuest).Text=idText;
		Log_SetStringToLog(XI_ConvertString("Logbook Update"));
		AddMsgToCharacter(mc,MSGICON_LOGBOOK);
		PlaySound("INTERFACE\notebook.wav");
	}

// KK -->
	if (CheckAttribute(mc, "QuestInfo." + idQuest + ".Text")) {
		makearef(questRef, mc.QuestInfo.(idQuest));
		text = GetQuestRecordText(idQuest, recordno);
		ref pd; makeref(pd, PreprocessorData);
		if (CheckAttribute(pd, "QuestData")) {
			aref qdata; makearef(qdata, pd.QuestData);
			string qn = "q" + recordno;
			if (!CheckAttribute(questRef, "data." + qn)) questRef.data.(qn) = "";
			aref qtrec; makearef(qtrec, questRef.data.(qn));
			CopyAttributes(qtrec, qdata);
			Preprocessor_Clear(false);
		}
	}
// <-- KK
}
// end US version


// 1.03 version
// needs different DLL. 05-05-04
/*bool CheckQuestRecord(aref qref,string textId)
{
	if( CheckAttribute(qref,"Text") )
	{
		string str_date, str_text;
		string lastText = qref.Text;
		int nEnd, nSize;
		nSize = strlen(lastText);
		while(nSize>0)
		{
			nEnd = findSubStr(lastText,",",0);
			if(nEnd<0) {
				GetDateAndText(lastText,&str_date,&str_text);
				nSize = 0;
			} else {
				nSize -= nEnd+1;
				GetDateAndText(strcut(lastText,0,nEnd),&str_date,&str_text);
			}
			if(textId==str_text) return true;
			if(nSize>0) {lastText = strcut(lastText,nEnd+1,nSize);}
		}
	}
	return false;
	//bool retVal = SendMessage(&GameInterface,"las",MSG_INTERFACE_CHECK_QRECORD,qref,textId);
	//return retVal;
}

void GetDateAndText(string srcText, ref dstDate, ref dstText)
{
	dstDate = "";
	dstText = "";
	if(srcText=="") return;
	dstText = srcText;
	if( strcut(srcText,0,0)!="@" ) return;
	int nEnd = findSubStr(srcText,"@",1);
	if(nEnd<0) return;
	dstDate = strcut(srcText,1,nEnd-1);
	int nSrcSize = strlen(srcText);
	if(nEnd<nSrcSize-1) dstText = strcut(srcText,nEnd+1,nSrcSize-1);
}

void SetQuestHeader(string idQuest)
{
	ref mainCh = GetMainCharacter();
	if(!CheckAttribute(mainCh,"QuestInfo."+idQuest))
	{
		object refNewAttr;
		refNewAttr.(idQuest).Complete = false;
		refNewAttr.(idQuest).Text = "";

		aref refOldAttr; makearef(refOldAttr,mainCh.QuestInfo);
		string qName;
		aref curQ, newQ,oldQ;
		for(int i=0; i<GetAttributesNum(refOldAttr); i++)
		{
			curQ = GetAttributeN(refOldAttr,i);
			qName = GetAttributeName(curQ);
			refNewAttr.(qName) = "";
			makearef(newQ,refNewAttr.(qName));
			makearef(oldQ,refOldAttr.(qName));
			CopyAttributes(newQ,oldQ);
		}
		CopyAttributes(refOldAttr,&refNewAttr);
	}
}
// 1.03 patch this and its use below
string GetQuestBookData()
{
	return makeint(GetHour())+":"+makeint(GetMinute()) + " "+GetDataDay()+"."+GetDataMonth()+"."+GetDataYear();
}
void AddQuestRecord(string idQuest,string idText)
{
	if(CheckAttribute(GetMainCharacter(),"QuestInfo."+idQuest)==false)
	{
		SetQuestHeader(idQuest);
	}
	ref mc = GetMainCharacter();
	if( CheckAttribute(mc,"QuestInfo."+idQuest+".Text") && mc.QuestInfo.(idQuest).Text!="")
	{
		aref questRef; makearef(questRef,mc.QuestInfo.(idQuest));
		if( !CheckQuestRecord(questRef,idText) )
		{
			string tmpStr = "@"+GetQuestBookData()+"@"+idText+","+questRef.Text;
			questRef.Text = tmpStr;
			Log_SetStringToLog(XI_ConvertString("Logbook Update"));
			AddMsgToCharacter(mc,MSGICON_LOGBOOK);
			PlayStereoSound("notebook");
		}
	}
	else
	{
		mc.QuestInfo.(idQuest).Text="@"+GetQuestBookData()+"@"+idText;
		Log_SetStringToLog(XI_ConvertString("Logbook Update"));
		AddMsgToCharacter(mc,MSGICON_LOGBOOK);
		PlayStereoSound("notebook");
	}
}*/
void CloseQuestHeader(string idQuest)
{
	ref mc = GetMainCharacter();
	if (!CheckAttribute(mc, "QuestInfo." + idQuest)) return; // KK
	object questRef;
	CopyAttributes(&questRef,GetQuestData(idQuest));
	questRef.Complete = true;
	DeleteAttribute(mc,"QuestInfo."+idQuest);
	aref newAttr; makearef(newAttr,mc.QuestInfo.(idQuest));
	CopyAttributes(newAttr,questRef);
}
//JRH -->
void OpenQuestHeader(string idQuest)
{
	ref mc = GetMainCharacter();
	if (!CheckAttribute(mc, "QuestInfo." + idQuest)) return; // KK
	object questRef;
	CopyAttributes(&questRef,GetQuestData(idQuest));
    questRef.Complete = false;
	DeleteAttribute(mc,"QuestInfo."+idQuest);
	aref newAttr; makearef(newAttr,mc.QuestInfo.(idQuest));
	CopyAttributes(newAttr,questRef);
}
//<-- JRH
bool CheckActiveQuest(string idQuest)
{
	if(CheckAttribute(GetMainCharacter(),"QuestInfo."+idQuest)==false) return false;
	return true;
}
void DeleteQuestHeader(string idQuest)
{
	DeleteAttribute(GetMainCharacter(), "QuestInfo."+idQuest);
}

//**********************************************************************************
// Утилиты для работы с квестами
//==================================================================================

// проверить флаг состояния квеста
//-----------------------------------------
bool CheckQuestAttribute(string attributeName, string attributeValue)
{
	ref pchar = GetMainCharacter();
	if( CheckAttribute(pchar,"quest."+attributeName) )
		return (pchar.quest.(attributeName)==attributeValue);
	return false;
}

// удалить флаг состояния квеста
//------------------------------------------
void DeleteQuestAttribute(string attributeName)
{
	ref pchar = GetMainCharacter();
	if( CheckAttribute(pchar,"quest."+attributeName) )
		DeleteAttribute(pchar,"quest."+attributeName);
}

float GetLocatorSqrDistanceToMe(aref locatorRef)
{
	float x,y,z;
	GetCharacterPos(GetMainCharacter(),&x,&y,&z);
	x = stf(locatorRef.x)-x;
	y = stf(locatorRef.y)-y;
	z = stf(locatorRef.z)-z;
	return (x*x+y*y+z*z);
}

bool GetNearLocator(string groupName, ref float_dist, ref findedLocator, float minDistance)
{
	int loadLocationIndex = FindLoadedLocation();
	if(loadLocationIndex==-1) return false;
	ref refLoadLocation; makeref(refLoadLocation,Locations[loadLocationIndex]);
	if(!CheckAttribute(refLoadLocation,"locators."+groupName)) return false;
	aref refLocators; makearef(refLocators,refLoadLocation.locators.(groupName));
	int locatorsCount = GetAttributesNum(refLocators);
	int n;
	aref refCurLocator;
	bool  bYesFind = false;
	float minDist = 4000000.0;
	float curDist;
	for(n=0;n<locatorsCount;n++)
	{
		refCurLocator = GetAttributeN( refLocators, n );
		curDist = GetLocatorSqrDistanceToMe(refCurLocator);
		if(curDist<minDistance) continue;
		if(curDist>=minDist) continue;
		minDist = curDist;
		findedLocator = refCurLocator;
		bYesFind = true;
	}
	return bYesFind;
}

float GetLocatorSqrDistanceToLocator(aref locatorRef1, aref locatorRef2)
{
	float x,y,z;
	x = stf(locatorRef1.x)-stf(locatorRef2.x);
	y = stf(locatorRef1.y)-stf(locatorRef2.y);
	z = stf(locatorRef1.z)-stf(locatorRef2.z);
	return (x*x+y*y+z*z);
}

string GetNearLocatorToLocator(string origGroup, string origLocator, string findGroup)
{
	if(!CheckAttribute(loadedLocation,"locators."+origGroup)) return "";
	if(!CheckAttribute(loadedLocation,"locators."+findGroup)) return "";
	aref origLoc; makearef(origLoc,loadedLocation.locators.(origGroup).(origLocator));

	aref refLocators; makearef(refLocators,loadedLocation.locators.(findGroup));
	aref refCurLocator;
	float curDist;
	
	float minDist = 4000000.0;
	string findedLocator = "";
	for(int n=0;n<GetAttributesNum(refLocators);n++)
	{
		refCurLocator = GetAttributeN( refLocators, n );
		curDist = GetLocatorSqrDistanceToLocator(origLoc, refCurLocator);
		if(curDist<minDist)
		{
			minDist = curDist;
			findedLocator = GetAttributeName(refCurLocator);
		}
	}
	return findedLocator;
}

// установить персонажа в ближайший локатор группы goto (но не ближе минимальной дистанции)
//--------------------------------------------------------------------------------------------
bool SetCharacterToNearLocatorFromMe(string characterID, float minDistance)
{
	int loadLocationIndex = FindLoadedLocation();
	if(loadLocationIndex==-1) return false;
	float dist;
	aref findedLocator;
	if( GetNearLocator( "goto", &dist, &findedLocator, minDistance) )
	{
		ChangeCharacterAddress(CharacterFromID(characterID), Locations[loadLocationIndex].id, GetAttributeName(findedLocator));
		return true;
	}
	// PB: If "goto" not available, try "rld" -->
	if( GetNearLocator( "rld", &dist, &findedLocator, minDistance) )
	{
		ChangeCharacterAddressGroup(CharacterFromID(characterID), Locations[loadLocationIndex].id, "rld", GetAttributeName(findedLocator));
		return true;
	}
	// PB: If "goto" not available, try "rld" <--
	Trace("Can't use goto or rld group locators in location "+Locations[loadLocationIndex].id);
	return false;
}

// получить ссылку на персонаж через его ID-шник
//------------------------------------------------------
ref CharacterFromID(string characterID)
{
	// PB: Error checking -->
	if(characterID == "") characterID = "Boat1234"; // just some random character to prevent error logs
	if(sti(GetCharacterIndex(characterID)) == -1)
	{
		TraceAndLog("ERROR - Missing Character ID: " + characterID);
		return &NullCharacter; // MM
	}
	// PB: Error checking <--
	return &characters[GetCharacterIndex(characterID)];
}

string sPostWaitName;
int postWaitYear,postWaitMonth,postWaitDay,postWaitHour,postWaitMinute;
void WaitDatePostEventControl()
{
	if(postWaitYear+postWaitMonth+postWaitDay>0) { AddDataToCurrent(postWaitYear,postWaitMonth,postWaitDay, true); } // NK 05-04-17 give adddata a bool
	AddTimeToCurrent(postWaitHour,postWaitMinute);
	if(sPostWaitName!="")	CompleteQuestName(sPostWaitName);
	QuestsCheck();
}

// пропустить некоторое время с фэйдом экрана
//----------------------------------------------------
void WaitDate(string postName,int year, int month, int day, int hour, int minute)
{
	sPostWaitName = postName;
	postWaitYear = year;
	postWaitMonth = month;
	postWaitDay = day;
	postWaitHour = hour;
	postWaitMinute = minute;
	WaitDatePostEventControl();
}

// установить камеру на просмотр корабля персонажа и вызвать квест через заданное число секунд
//---------------------------------------------------------------------------------------------
bool SetCameraToShipView(string characterName, string questCheckName, float viewTimeInSec)
{
	int chrIdx = GetCharacterIndex(characterName);
	if(chrIdx==-1) return false;
	ref chrRef = GetCharacter(chrIdx);

	float xship = stf(chrRef.ship.pos.x);
	float zship = stf(chrRef.ship.pos.z);

	float xchar,ychar,zchar;
	if( false==GetCharacterPos(GetMainCharacter(),&xchar,&ychar,&zchar) ) return false;

	float dx = xchar-xship;
	float dz = zchar-zship;
	float dist = sqrt(dx*dx+dz*dz);
	dx = dx/dist;
	dz = dz/dist;

	float xcam = xchar+dx*6.0;
	float zcam = zchar+dz*6.0;

	PostEvent("evntQuestCameraRestore",makeint(viewTimeInSec*1000),"s",questCheckName);

	return locCameraToPos(xcam,ychar+3.0,zcam,false);
}

void QuestCameraRestore()
{
	string sCameraQuestCheckName = GetEventData();
	locCameraFollow();
	if(sCameraQuestCheckName!="")
	{
		CompleteQuestName(sCameraQuestCheckName);
		QuestsCheck();
	}
}

// Закрыть все выходы на море в районе расположения своего корабля
//-----------------------------------------------------------------
bool QuestCloseSeaExit()
{
	ref mcRef = GetMainCharacter();
	int locIdx = FindLocation(mcRef.location.from_sea);
	if(locIdx==-1) return false;

	aref reloadRef;
	makearef(reloadRef,Locations[locIdx].reload);

	int n = GetAttributesNum(reloadRef);
	aref locRef;
	for(int i=0;i<n;i++)
	{
		locRef = GetAttributeN(reloadRef,i);
		if( FindIsland(locRef.go) != -1 )
		{
			chrEnableReloadLocator(Locations[locIdx].id, locRef.name, false);
		}
	}
	return true;
}

// Открыть все выходы на море в районе расположения своего корабля
//-----------------------------------------------------------------
bool QuestOpenSeaExit()
{
	ref mcRef = GetMainCharacter();
	int locIdx = FindLocation(mcRef.location.from_sea);
	if(locIdx==-1) return false;

	aref reloadRef;
	makearef(reloadRef,Locations[locIdx].reload);

	int n = GetAttributesNum(reloadRef);
	aref locRef;
	for(int i=0;i<n;i++)
	{
		locRef = GetAttributeN(reloadRef,i);
		if( FindIsland(locRef.go) != -1 )	chrEnableReloadLocator(Locations[locIdx].id, locRef.name, true);
	}
	return true;
}

// найти локатор в локации по имени
//-----------------------------------
bool FindLocator(string locationName, string locatorName, ref locatorRef, bool fromRealLoadedLocators)
{
	int i,j,n,m,locIdx;
	aref reloadRef,locRef,locGroupRef;

	locIdx = FindLocation(locationName);
	if(locIdx==-1)	return false;

	if(!IsEntity(&Locations[locIdx]) && fromRealLoadedLocators)	return false;

	if(locatorName=="")	return false;

	if(!fromRealLoadedLocators)
	{
		makearef(reloadRef,Locations[locIdx].reload);
		n = GetAttributesNum(reloadRef);
		for(i=0;i<n;i++)
		{
			locRef = GetAttributeN(reloadRef,i);
			if(locRef.name==locatorName)
			{
				locatorRef = locRef;
				return true;
			}
		}
		return false;
	}

	makearef(reloadRef,Locations[locIdx].locators);
	m = GetAttributesNum(reloadRef);
	for(j=0;j<m;j++)
	{
		locGroupRef = GetAttributeN(reloadRef,j);
		n = GetAttributesNum(locGroupRef);
		for(i=0;i<n;i++)
		{
			locRef = GetAttributeN(locGroupRef,i);
			if(GetAttributeName(locRef)==locatorName)
			{
				locatorRef = locRef;
				return true;
			}
		}
	}
	return false;
}

// проверить попадает ли координата в заданный локатор в текущей локации
bool CheckCurLocator(string group,string locator,float x,float y,float z)
{
	int locIdx = FindLoadedLocation();
	if(locIdx==-1) return false;
	if( !CheckAttribute(&Locations[locIdx],"locators."+group+"."+locator) ) return false;
	aref curloc; makearef(curloc,Locations[locIdx].locators.(group).(locator));
	float xloc = makefloat(curloc.x) - x;
	float yloc = makefloat(curloc.y) - y;
	float zloc = makefloat(curloc.z) - z;
	float rad = makefloat(curloc.radius);
	if( rad*rad > xloc*xloc+yloc*yloc+zloc*zloc ) return true;
	else return false;
}

// заменить один локатор на новый адрес перегрузкии
//---------------------------------------------------
bool ChangeReloadData(string locationName,string locatorName, string toLocationName,string toLocatorName)
{
	aref locRef;
	if( !FindLocator(locationName,locatorName, &locRef, false) )
	{
		return false;
	}

	if(!CheckAttribute(locRef,"old.go")) locRef.old.go = locRef.go;
	if(!CheckAttribute(locRef,"old.emerge")) locRef.old.emerge = locRef.emerge;

	if(toLocationName=="") toLocationName=locRef.go;
	if(toLocatorName=="") toLocatorName=locRef.emerge;

	locRef.go = toLocationName;
	locRef.emerge = toLocatorName;
	return true;
}

// вернуть локатору старый адрес перегрузки
bool ChangeBackReloadData(string locationName,string locatorName)
{
	aref locRef;
	if( !FindLocator(locationName,locatorName, &locRef, false) ) return false;

	if(CheckAttribute(locRef,"old.go"))	locRef.go = locRef.old.go;
	if(CheckAttribute(locRef,"old.emerge")) locRef.emerge = locRef.old.emerge;

	if(CheckAttribute(locRef,"old"))	DeleteAttribute(locRef,"old");
	return true;
}

// вызвать проверку квеста через заданное число секунд
//------------------------------------------------------
void DoQuestCheckDelay(string questCheckName, float delayInSecond)
{
	bool deleteOldQuest=false;
	ref mc = GetMainCharacter();
	if( CheckAttribute(mc,"quest."+questCheckName) )	deleteOldQuest=true;
	mc.PostEventQuest.questDelay.(questCheckName).delay = delayInSecond;
	mc.PostEventQuest.questDelay.(questCheckName).qname = questCheckName;
	PostEvent("QuestDelayExit",makeint(delayInSecond*1000),"sl",questCheckName,deleteOldQuest);
}

void DoQuestDelayExit()
{
	string stmp = GetEventData();
	bool deleteOldQuest = GetEventData();
	ref mc = GetMainCharacter();
	DeleteAttribute(mc,"PostEventQuest.questDelay."+stmp);
	if(stmp!="")
	{
		if(deleteOldQuest)
		{
			if( CheckAttribute(mc,"quest."+stmp) )
			{
				CompleteQuestName(stmp);
				mc.quest.(stmp).over = "yes";
				QuestsCheck();
				return;
			}
		}
		CompleteQuestName(stmp);
		QuestsCheck();
	}
}

void ExitActAnimation()
{
	aref arch = GetEventData();
	if(!CheckAttribute(arch,"activity.endAnimationQuest")) return;
	ref chref = GetCharacter(sti(arch.index));
	CharacterPlayAction(chref,"");
	string endAniQuestName = chref.activity.endAnimationQuest.Name;
	DeleteAttribute(chref,"activity.endAnimationQuest");
	if(endAniQuestName!="")
	{
		CompleteQuestName(endAniQuestName);
		QuestsCheck();
	}
}

// Временно сохранить все данные о нашем корабле в памяти
//--------------------------------------------------------
bool ShipTempRemove(ref _refCharacter)
{
	if( CheckAttribute(_refCharacter,"TmpShipHolder") ) return false;
	if( !CheckAttribute(_refCharacter,"Ship") ) return false;

	aref dstRef; makearef(dstRef, _refCharacter.TmpShipHolder);
	aref srcRef; makearef(srcRef, _refCharacter.Ship);

	CopyAttributes(dstRef,srcRef);
	DeleteAttribute(_refCharacter,"Ship");	// GR: Once your ship is copied into store, remove it
	return true;
}

// Восстановить данные о нашем старом корабле из памяти
//------------------------------------------------------
bool RestoreTempRemovedShip(ref _refCharacter)
{
	if( !CheckAttribute(_refCharacter,"TmpShipHolder") ) return false;
	DeleteAttribute(_refCharacter,"Ship");	// GR: Moved up here, used to be below 'aref' lines and caused game crash

	aref dstRef; makearef(dstRef, _refCharacter.Ship);
	aref srcRef; makearef(srcRef, _refCharacter.TmpShipHolder);

	CopyAttributes(dstRef,srcRef);
	DeleteAttribute(_refCharacter,"TmpShipHolder");
	return true;
}


bool TempRemoveItems(ref _refCharacter) // GR: Similar to ShipTempRemove, stores character's items
{
	if( CheckAttribute(_refCharacter,"TmpItemHolder") ) return false;
	if( !CheckAttribute(_refCharacter,"items") ) return false;

	aref dstRef; makearef(dstRef, _refCharacter.TmpItemHolder);
	aref srcRef; makearef(srcRef, _refCharacter.items);

	CopyAttributes(dstRef,srcRef);
	DeleteAttribute(_refCharacter,"items");
	return true;
}

bool RestoreTempRemovedItems(ref _refCharacter) // GR: Similar to RestoreTempRemovedShip, restores character's items
{
	if( !CheckAttribute(_refCharacter,"TmpItemHolder") ) return false;
	DeleteAttribute(_refCharacter,"items");
	aref dstRef; makearef(dstRef, _refCharacter.items);
	aref srcRef; makearef(srcRef, _refCharacter.TmpItemHolder);

	CopyAttributes(dstRef,srcRef);
	DeleteAttribute(_refCharacter,"TmpItemHolder");
	return true;
}

// Обменять двух персонажей кораблями
//------------------------------------
void ExchangeCharacterShip(ref oneCharacter, ref twoCharacter)
{
	object tmpObj;
	aref oneShip; makearef(oneShip,oneCharacter.Ship);
	aref twoShip; makearef(twoShip,twoCharacter.Ship);

	CopyAttributes(&tmpObj,oneShip);
	CopyAttributes(oneShip,twoShip);
	CopyAttributes(twoShip,&tmpObj);
}

void QuestProcessDialogExit()
{
	aref one_aref = GetEventData();
	aref two_aref = GetEventData();

	DeleteAttribute(one_aref,"act.disableDialog");
	DeleteAttribute(two_aref,"act.disableDialog");
}

// Задать квест, выполняемый после выхода из диалога
//---------------------------------------------------
void AddDialogExitQuest(string questName)
{
	string attrName;
	aref ar;
	ref mc = GetMainCharacter();

	if( CheckAttribute(mc,"DialogExitQuests") )
	{
		makearef(ar,mc.DialogExitQuests);
		attrName = "l" + GetAttributesNum(ar);
	}
	else
	{
		attrName = "l0";
	}
	mc.DialogExitQuests.(attrName) = questName;
}

void QuestDialogExitProcedure()
{
	int i = GetEventData();
	ref otherCh = GetCharacter(i);
	aref ar, lref;
	string attrName;
	ref mc = GetMainCharacter();

	// может быть выполним какую нибудь задачу
	ExecuteAfterDialogTask(otherCh);
	ExecuteAfterDialogTask(mc);

	if( CheckAttribute(mc,"DialogExitQuests") )
	{
		makearef(ar,mc.DialogExitQuests);
		for(i=0; i<GetAttributesNum(ar); i++)
		{
			lref = GetAttributeN(ar,i);
			attrName = GetAttributeValue(lref);
			CompleteQuestName(attrName);
			if( CheckAttribute(mc,"quest."+attrName+".win_condition") )	mc.quest.(attrName).over = "yes";
		}
		DeleteAttribute(mc,"DialogExitQuests");
	}

	QuestsCheck();
}

int idxOldLocation = -1;
string sQuestNameAfterReload = "_";
void DoDeleteFakeLocation()
{
	DelEventHandler(EVENT_LOCATION_LOAD,"DoDeleteFakeLocation");
	if(idxOldLocation!=-1)	DeleteAttribute(&Locations[idxOldLocation],"reload.fake1");
	if(sQuestNameAfterReload!="_")
	{
		ref mc = GetMainCharacter();
		CompleteQuestName(sQuestNameAfterReload);
		if( CheckAttribute(mc,"quest."+sQuestNameAfterReload+".win_condition") )
			mc.quest.(sQuestNameAfterReload).over = "yes";
		QuestsCheck();
		sQuestNameAfterReload = "_";
	}
}

// Перегрузить главного персонажа в другую локацию и по завершению вызвать квест
//-------------------------------------------------------------------------------
bool DoQuestReloadToLocation(string idLocation, string idGroup, string idLocator, string questName)
{
	if(sQuestNameAfterReload!="_") return false;
	sQuestNameAfterReload = questName;
	if(bSeaActive)
	{
		idxOldLocation = -1;
		SetEventHandler(EVENT_LOCATION_LOAD,"DoDeleteFakeLocation",0);
		return DoReloadFromSeaToLocation(idLocation,idGroup,idLocator);
	}
	if(IsEntity(worldMap))
	{
		idxOldLocation = -1;
		SetEventHandler(EVENT_LOCATION_LOAD,"DoDeleteFakeLocation",0);
		return DoReloadFromWorldMapToLocation(idLocation,idGroup,idLocator);
	}
	return DoReloadCharacterToLocation(idLocation,idGroup,idLocator);
}

// Перегрузить главного персонажа в другую локацию
//-------------------------------------------------------------------------------
bool DoReloadCharacterToLocation(string idLocation, string idGroup, string idLocator)
{
	idxOldLocation = FindLoadedLocation();
	if(idxOldLocation==-1)
	{
		idxOldLocation = 0;
		loadedLocation = &Locations[idxOldLocation];
	}
	else
	{
		if(Locations[idxOldLocation].id!=loadedLocation.id)
		{
			trace("WARNING!!! FindLocation is not same loadedLocation");
			if(IsEntity(loadedLocation))
			{	idxOldLocation = FindLocation(loadedLocation.id);
			}
		}
	}
	Locations[idxOldLocation].reload.fake1.name = "fakeReload";
	Locations[idxOldLocation].reload.fake1.go = idLocation;
	Locations[idxOldLocation].reload.fake1.emerge = idLocator;
	ref pchar = GetMainCharacter();
	aref rloc;
	if( FindLocator ( pchar.location, pchar.location.locator, &rloc, true ) )
	{
		Event("Location_CharacterExitFromLocator","aassf", rloc,pchar, pchar.location.group,pchar.location.locator, 1.0);
	}

	SetEventHandler(EVENT_LOCATION_LOAD,"DoDeleteFakeLocation",0);
	return TeleportCharacterFromCurLocationToLocation("fakeReload",idGroup,idLocator);
}

// Перегрузить главного персонажа в другую локацию из карты мира
//-------------------------------------------------------------------------------
bool DoReloadFromWorldMapToLocation(string idLocation, string idGroup, string idLocator)
{
	ref pchar = GetMainCharacter();
	if(FindLocation(idLocation)==-1) return false;
	pchar.tmpWDMtoLand.location = idLocation;
	pchar.tmpWDMtoLand.group = idGroup;
	pchar.tmpWDMtoLand.locator = idLocator;
	QuitFromWorldMap();
	return true;
}
void ReloadFromWMtoL_complete()
{
	ref pchar = GetMainCharacter();
	if( !CheckAttribute(pchar,"tmpWDMtoLand") ) return;
	ChangeCharacterAddressGroup( pchar, pchar.tmpWDMtoLand.location, pchar.tmpWDMtoLand.group, pchar.tmpWDMtoLand.locator );
	LoadLocation(&Locations[FindLocation(pchar.tmpWDMtoLand.location)]);
	DeleteAttribute(pchar,"tmpWDMtoLand");
}

// Перегрузить главного персонажа в другую локацию из моря
//-------------------------------------------------------------------------------
bool DoReloadFromSeaToLocation(string idLocation, string idGroup, string idLocator)
{
	
	if(bSeaActive)	{ DeleteSeaEnvironment(); }
	else {bSkipSeaLogin = true;}

	ref pchar = GetMainCharacter();
	pchar.tmpWDMtoLand.location = idLocation;
	pchar.tmpWDMtoLand.group = idGroup;
	pchar.tmpWDMtoLand.locator = idLocator;

	SetEventHandler("FaderEvent_EndFade", "EndReloadToLocation", 0);
	CreateEntity(&reload_fader, "fader");
	if(IsEntity(&reload_fader) == 0) Trace("Reload fader not created!!!");
	float fadeOutTime = 0.5;
	SendMessage(&reload_fader, "lfl", FADER_OUT, fadeOutTime, true);
	SendMessage(&reload_fader, "l", FADER_STARTFRAME);
	return true;
}
void EndReloadToLocation()
{
	DelEventHandler("FaderEvent_EndFade", "EndReloadToLocation");
	ReloadFromWMtoL_complete();
}

// Удалить квест из списка проверяемых квестов
//---------------------------------------------
void DeleteQuestCheck(string sQuestName)
{
	ref mc = GetMainCharacter();
	if(sQuestName=="") return;
	if( CheckAttribute(mc,"quest."+sQuestName+".win_condition") )	mc.quest.(sQuestName).over = "yes";
}

// Получить полное имя персонажа
//----------------------------------
string GetCharacterFullName(string idCharacter)
{
	int idxCh = GetCharacterIndex(idCharacter);
	if(idxCh==-1) return "";
	ref chref = GetCharacter(idxCh);
	string retStr = "";
	if(CheckAttribute(chref,"name")) retStr = chref.name;
	if(CheckAttribute(chref,"middlename")) retStr = retStr + " " + chref.middlename;
	if(CheckAttribute(chref,"lastname")) retStr = retStr + " " + chref.lastname;
	return retStr;
}

// Сохранить состояние о пассажирах во временной переменной и временно удалить их всех
//-------------------------------------------------------------------------------------
bool StorePassengers(string idCharacter)
{
	int idxCh = GetCharacterIndex(idCharacter);
	if(idxCh==-1) return false;
	ref refCh = GetCharacter(idxCh);
	ref ch;
	if(CheckAttribute(refCh,"Fellows.Old")) return false;

	string sTmp;
	aref arTmp;
	int i,idx;
	// сохраним офицеров
	makearef(arTmp,refCh.Fellows.Old.Officers);
	for(i=1; i<4; i++)
	{
		idx = GetOfficersIndex(refCh,i);
		if(idx==-1) continue;
		sTmp = "id"+i;
		arTmp.(sTmp) = idx;
	}
	// сохраним пассажиров
	makearef(arTmp,refCh.Fellows.Old.Passengers);
	for(i=0; GetPassengersQuantity(refCh)>0; i++)
	{
		idx = GetPassenger(refCh,0);
		if(idx==-1) break;
		sTmp = "id"+i;
		arTmp.(sTmp) = idx;
		ch = GetCharacter(idx);
		RemovePassenger(refCh,ch);
		ChangeCharacterAddress(ch,"none","");
		ch.StoredFellow = true; // PB: Flag to prevent erasing this character
	}
	return true;
}

// Восстановить запомненных ранее пассажиров и по возможности офицеров
//----------------------------------------------------------------------
bool RestorePassengers(string idCharacter)
{
	int idxCh = GetCharacterIndex(idCharacter);
	if(idxCh==-1) return false;
	ref refCh = GetCharacter(idxCh);
	ref ch;
	if(!CheckAttribute(refCh,"Fellows.Old")) return false;

	int i,idx;
	aref arTmp,arCur;
	// Восстановление пассажиров
	makearef(arTmp,refCh.Fellows.Old.Passengers);
	for(i=0; i<GetAttributesNum(arTmp); i++)
	{
		arCur = GetAttributeN(arTmp,i);
		idx = sti(GetAttributeValue(arCur));
		ch = GetCharacter(idx);
		AddPassenger(refCh,ch,false);
		DeleteAttribute(ch,"StoredFellow"); // PB: Erase this attribute
	}
	// Восстановление офицеров
	makearef(arTmp,refCh.Fellows.Old.Officers);
	for(i=0; i<GetAttributesNum(arTmp); i++)
	{
		arCur = GetAttributeN(arTmp,i);
		idx = sti(GetAttributeValue(arCur));
		if(idx==-1) continue;
		SetOfficersIndex(refCh,-1,idx);
	}

	// удаление временного хранилища пассажиров
	DeleteAttribute(refCh,"Fellows.Old");
	return true;
}

// Смотрим на какого нибудь персонажа
//--------------------------------------
bool StartLookAfterCharacter(string idCharacter)
{
	int chIdx = GetCharacterIndex(idCharacter);
	if(chIdx==-1) return false;

	CharacterTurnByChr(GetMainCharacter(),GetCharacter(chIdx));
	SetEventHandler("evntLookAfterCharacter","LookAfterCharacterProc",0);
	PostEvent("evntLookAfterCharacter",100,"l",chIdx);
	return true;
}
void LookAfterCharacterProc()
{
	int idxCh = GetEventData();
	CharacterTurnByChr(GetMainCharacter(),GetCharacter(idxCh));
	PostEvent("evntLookAfterCharacter",100,"l",idxCh);
}

// Прекратили смотреть на персонаж
//-----------------------------------
void EndLookAfterCharacter()
{
	DelEventHandler("evntLookAfterCharacter","LookAfterCharacterProc");
}

// восстановить персонаж (на случай, если он был до этого убит)
bool ReanimateCharacter(string characterID)
{
	int idx = GetCharacterIndex(characterID);
	if(idx==-1)
	{
		trace("Not found character for function : ReanimateCharacter(" + characterID + ")");
		return false;
	}
	ref chref = GetCharacter(idx);
	LAi_SetCurHP(chref,LAi_GetCharacterMaxHP(chref));
	return true;
}

//extern void SetRandomNameToCharacter(ref chref);
// установить случайное имя для персонажа
bool SetCharacterRandomName(string characterID)
{
	int idx = GetCharacterIndex(characterID);
	if(idx==-1)
	{
		trace("Warning!!! Missing character id = " + characterID);
		return false;
	}
	SetRandomNameToCharacter(GetCharacter(idx));
	return true;
}


// обработка события об уничтожении форта
void QuestFortDestroyed()
{
	int idx = GetEventData();
	if(idx==-1) return;
	ref chref = GetCharacter(idx);
	chref.FortDestroy = "1";
	QuestsCheck();
}

// KK -->
void QuestColonyCaptured()
{
	int townidx = GetEventData();
	int iNation = GetEventData();
	ref mchr = GetMainCharacter();
	if (iNation < 0 || iNation >= NATIONS_QUANTITY) {
		if (iNation != PERSONAL_NATION || iNation != ANY_NATION) return;
	}
	if (townidx < 0 || townidx >= TOWNS_QUANTITY) return;
	mchr.QuestColonyCaptured = true;
	mchr.QuestColonyCaptured.town = Towns[townidx].id;
	if (iNation != ANY_NATION) mchr.QuestColonyCaptured.nation = iNation;
	QuestsCheck();
}

void QuestGroupDeath(int chrIdx)
{
	int i, idx, iNum, j, jNum, l;
	ref chr, chref;
	ref mc = GetMainCharacter();
	aref arQuest, arQuestCurrent, arCondition, arConditionCurrent;
	string groupName;
	bool bDeath = false;
	if (chrIdx < 0) return;
	chref = GetCharacter(chrIdx);
	if (!CheckAttribute(chref, "chr_ai.group")) return;
	groupName = chref.chr_ai.group;
	if (!CheckAttribute(mc, "quest")) return;
	makearef(arQuest, mc.quest);
	iNum = GetAttributesNum(arQuest);
	for (i = 0; i < iNum; i++)
	{
		arQuestCurrent = GetAttributeN(arQuest, i);
		if (!CheckAttribute(arQuestCurrent, "win_condition")) continue;
		makearef(arCondition, arQuestCurrent.win_condition);
		jNum = GetAttributesNum(arCondition);
		for (j = 0; j < jNum; j++)
		{
			arConditionCurrent = GetAttributeN(arCondition, j);
			if (GetAttributeValue(arConditionCurrent) == "Group_Death" && CheckAttribute(arConditionCurrent, "group") == true && arConditionCurrent.group == groupName) {
				bDeath = true;
				for (l = 0; l < LAi_numloginedcharacters; l++)
				{
					idx = LAi_loginedcharacters[l];
					if(idx < 0 || idx == chrIdx) continue;
					chr = GetCharacter(idx);
					if (CheckAttribute(chr, "chr_ai.group") == true && chr.chr_ai.group == groupName && CharacterIsDead(chr) == false) {
						bDeath = false;
						break;
					}
				}
				if (bDeath) mc.GroupDeath.(groupName) = true;
			}
		}
	}
}
// <-- KK

// подготовиться к выгрузке в море по квесту
object questToSeaLoginer;
void QuestToSeaLogin_PrepareLoc(string islandID, string locGroup, string locName, bool sailUP)
{
	int i, j, num, chnum, chrIdx, iIsland;
	string sTown;
	aref arQuestGroups, arGroup, arLocator;
	ref rIsland, chr;
	DeleteAttribute(&questToSeaLoginer,""); // KK
	questToSeaLoginer.PlayerGroup.x = 0.0;
	questToSeaLoginer.PlayerGroup.ay = 0.0;
	questToSeaLoginer.PlayerGroup.z = 0.0;
	questToSeaLoginer.Island = islandID;
	if (!sailUP) questToSeaLoginer.FromCoast = true;
	//questToSeaLoginer.Title = TranslateString("", "Sea"); // KK

	iIsland = FindIsland(islandID);
	if (iIsland >= 0) {
		if (locGroup == "") locGroup = "reload";
		rIsland = GetIslandByIndex(iIsland);
		if (!CheckAttribute(rIsland, locGroup)) return;
		makearef(arGroup, rIsland.(locGroup));

		num = GetAttributesNum(arGroup);
		for (i = 0; i < num; i++)
		{
			arLocator = GetAttributeN(arGroup, i);
			if (CheckAttribute(arLocator, "name") == true && arLocator.name == locName) {
				if (CheckAttribute(arLocator, "x")) questToSeaLoginer.PlayerGroup.x = arLocator.x;
				if (CheckAttribute(arLocator, "z")) questToSeaLoginer.PlayerGroup.z = arLocator.z;
				if (CheckAttribute(arLocator, "ay")) {
          questToSeaLoginer.PlayerGroup.ay = arLocator.ay;
        } else {
      	 if (CheckAttribute(arLocator, "ships.l0.ay")) questToSeaLoginer.PlayerGroup.ay = arLocator.ships.l0.ay;
      	}
				break;			// LDH 10Feb09
			}
		}
	}

	questToSeaLoginer.ImageName = "Sea.tga";
	num = GetIslandTownsQuantity(islandID);
	for (i = 0; i < num; i++)
	{
		sTown = GetTownIDFromIsland(islandID, i);
		chnum = GetTownNumForts(sTown);
		for (j = 0; j < chnum; j++)
		{
			chrIdx = GetTownFortCommanderIndex(sTown, j);
			if (chrIdx < 0) continue;
			chr = GetCharacter(chrIdx);
			if (GetDistance2D(stf(chr.ship.pos.x), stf(chr.ship.pos.z), stf(questToSeaLoginer.PlayerGroup.x), stf(questToSeaLoginer.PlayerGroup.z)) <= MIN_ENEMY_DISTANCE_TO_DISABLE_MAP_ENTER && GetNationRelation(sti(characters[GetMainCharacterIndex()].nation), sti(chr.nation)) == RELATION_ENEMY) {
				questToSeaLoginer.ImageName = "Battle.tga";
				break;
			}
		}
		if (questToSeaLoginer.ImageName != "Sea.tga") break;
	}
}

void QuestToSeaLogin_Prepare(float x, float z, string islandID)
{
	DeleteAttribute(&questToSeaLoginer,"");
	questToSeaLoginer.PlayerGroup.x = x;
	questToSeaLoginer.PlayerGroup.ay = 0.0;
	questToSeaLoginer.PlayerGroup.z = z;
	questToSeaLoginer.Island = islandID;
}
// KK -->
void QuestToSeaLogin_SetStorm()
{
	questToSeaLoginer.Storm = true;
	//questToSeaLoginer.Title = TranslateString("", "Storm");
	questToSeaLoginer.ImageName = "Storm.tga";
}

void QuestToSeaLogin_SetTornado(float x, float z)
{
	questToSeaLoginer.Storm = true;
	questToSeaLoginer.Tornado = true;
	//questToSeaLoginer.Title = TranslateString("", "Twister");
	questToSeaLoginer.ImageName = "Twister.tga";
	Tornado.init.x = x;
	Tornado.init.z = z;
}

// подготовить персонажа для выгрузки в море по квесту
void QuestToSeaLogin_AddGroup(string sGroupID, int formation, float x, float z, float ay, bool sailUP)
{
	int i, j, num, chnum, chrIdx;
	string newAttrName, sIsland, sTown;
	aref arQuestGroups;
	ref qtsl; makeref(qtsl, questToSeaLoginer);
	if (!CheckAttribute(qtsl, "QuestGroups")) qtsl.QuestGroups = "";
	makearef(arQuestGroups, qtsl.QuestGroups);
	i = 0;
	num = GetAttributesNum(arQuestGroups);
	while (i < num)
	{
		if (GetAttributeValue(GetAttributeN(arQuestGroups, i)) == sGroupID) return;
		i++;
	}
	newAttrName = "l" + i;
	arQuestGroups.(newAttrName) = sGroupID;
	Group_SetXZ_AY(sGroupID, x, z, ay);
	Group_SetSailsUp(sGroupID, sailUP);

	if (Group_GetTask(sGroupID) == AITASK_ATTACK && Group_GetGroupTarget(sGroupID) == PLAYER_GROUP) questToSeaLoginer.ImageName = "Battle.tga";

	chnum = Group_GetCharactersNum(sGroupID);
	for (j = 0; j < chnum; j++)
	{
		chrIdx = Group_GetCharacterIndex(sGroupID, j);
		if (chrIdx < 0) continue;
		if (!CheckAttribute(&characters[chrIdx], "nation")) continue;
		if (GetNationRelation(sti(characters[GetMainCharacterIndex()].nation), sti(characters[chrIdx].nation)) == RELATION_ENEMY) {
			questToSeaLoginer.ImageName = "Battle.tga";
			break;
		}
	}
	sIsland = qtsl.Island;
	num = GetIslandTownsQuantity(sIsland);
	for (i = 0; i < num; i++)
	{
		sTown = GetTownIDFromIsland(sIsland, i);
		chnum = GetTownNumForts(sTown);
		for (j = 0; j < chnum; j++)
		{
			chrIdx = GetTownFortCommanderIndex(sTown, j);
			if (chrIdx < 0) continue;
			if (GetNationRelation(sti(characters[GetMainCharacterIndex()].nation), sti(characters[chrIdx].nation)) == RELATION_ENEMY) {
				questToSeaLoginer.ImageName = "Battle.tga";
				return;
			}
		}
	}
}

void QuestToSeaLogin_AddGroupLoc(string sGroupID, int formation, string locGroup, string locName, bool sailUP)
{
	int iIsland, chnum, i, j, num, chrIdx;
	string islandID, sTown;
	ref qtsl;

	makeref(qtsl, questToSeaLoginer);
	if (!CheckAttribute(qtsl, "Island")) return;
	islandID = qtsl.Island;
	Group_SetAddress(sGroupID, islandID, locGroup, locName);
	Group_SetSailsUp(sGroupID, sailUP);

	if (Group_GetTask(sGroupID) == AITASK_ATTACK && Group_GetGroupTarget(sGroupID) == PLAYER_GROUP) {
		questToSeaLoginer.ImageName = "Battle.tga";
		return;
	}

	chnum = Group_GetCharactersNum(sGroupID);
	for (j = 0; j < chnum; j++)
	{
		chrIdx = Group_GetCharacterIndex(sGroupID, j);
		if (chrIdx < 0) continue;
		if (!CheckAttribute(&characters[chrIdx], "nation")) continue;
		if (GetNationRelation(sti(characters[GetMainCharacterIndex()].nation), sti(characters[chrIdx].nation)) == RELATION_ENEMY) {
			questToSeaLoginer.ImageName = "Battle.tga";
			return;
		}
	}
	num = GetIslandTownsQuantity(islandID);
	for (i = 0; i < num; i++)
	{
		sTown = GetTownIDFromIsland(islandID, i);
		chnum = GetTownNumForts(sTown);
		for (j = 0; j < chnum; j++)
		{
			chrIdx = GetTownFortCommanderIndex(sTown, j);
			if (chrIdx < 0) continue;
			if (GetNationRelation(sti(characters[GetMainCharacterIndex()].nation), sti(characters[chrIdx].nation)) == RELATION_ENEMY) {
				questToSeaLoginer.ImageName = "Battle.tga";
				return;
			}
		}
	}
}

// запустить квестовую выгрузку в море
void QuestToSeaLogin_Launch()
{
	if (LAi_boarding_process) return;
	if (CheckAttribute(GetMainCharacter(), "IsOnDeck") == true && sti(characters[GetMainCharacterIndex()].IsOnDeck) == true) return;

	SetEventHandler("FaderEvent_StartFade", "QuestToSeaLoginStartFade", 0);
	SetEventHandler("FaderEvent_EndFade", "QuestToSeaLoginEndFade", 0);

	/*ref qtsl; makeref(qtsl, questToSeaLoginer);
	if (qtsl.ImageName == "Sea.tga") {
	}*/

	if (CheckAttribute(&worldMap, "isLoaded") == true && worldMap.isLoaded == "true") {
		wdmCurrentIsland = questToSeaLoginer.Island;
		if (wdmCurrentIsland == "") wdmCurrentIsland = WDM_NONE_ISLAND;
		worldMap.FromCoast = sti(questToSeaLoginer.FromCoast);
		worldMap.QuestToSeaLogin = true;
		Event("ExitFromWorldMap");
		return;
	}

	CreateEntity(&SeaFader, "fader");
	SendMessage(&SeaFader, "ls", FADER_PICTURE, FindReloadPicture(questToSeaLoginer.ImageName));
	SendMessage(&SeaFader, "lfl", FADER_OUT, 1.0, true);
}

void QuestToSeaLoginStartFade()
{
	DelEventHandler("FaderEvent_StartFade", "QuestToSeaLoginStartFade");

	ResetSoundScheme();
	PauseAllSounds();
	if (bSeaActive) {
		DeleteSeaEnvironment();
	} else {
		int idxLoadLoc = FindLoadedLocation();
		if (idxLoadLoc != -1) UnloadLocation(&Locations[idxLoadLoc]);
	}
}

void QuestToSeaLoginEndFade()
{
	DelEventHandler("FaderEvent_EndFade", "QuestToSeaLoginEndFade");
	ReloadProgressStart();
	SeaLogin(&questToSeaLoginer);
	ReloadProgressEnd();
}
// <-- KK

// Получить следующего персонажа одной группы
int	GetCharacterFromFantom(ref chref)
{
	/*int tmpi = FindLoadedLocation();
	if(tmpi==-1) return -1;
	string locID = Locations[tmpi].id;
	int retVal = -1;
	ref fantRef;
	int startVal = sti(chref.index)+1;
	if ( startVal < FANTOM_CHARACTERS ) startVal = FANTOM_CHARACTERS;
	for(int i=startVal; i<BOARDING_CHARACTERS; i++)
	{
		fantRef = GetCharacter(i);
		if(fantRef.location!=locID) continue;
		if(CharacterIsDead(fantRef)) continue;
		if ( CheckAttribute(fantRef,"act.team") && fantRef.act.team==chref.act.team )
		{
			retVal = sti(fantRef.index);
			break;
		}
	}
	return retVal;*/
	return -1;
}

// убрать из локации всех персов указанного типа
/*void RemoveCharactersFromLocation(string idLocation, string modelName, string type)
{
	for(int i=0; i<CHARACTERS_QUANTITY; i++) // NK 05-04-05 use CHARACTERS_QUANTITY
	{
		if( Characters[i].location!=idLocation ) continue;
		if( modelName!="" && modelName!=Characters[i].model ) continue;
		if( type!="" && type!=Characters[i].act.type ) continue;
		ChangeCharacterAddress(&Characters[i], "none", "");
	}
}*/
//Levis: Not used anymore

void CompleteQuestName(string sQuestName)
{
	if(sQuestName == "_") return;
	if( CheckAttribute(&objQuestScene,"list."+sQuestName+".chrIdx") )
	{
		Event("qprocTaskEnd","a",GetCharacter(sti(objQuestScene.list.(sQuestName).chrIdx)));
	}
	else
	{
		// PB: Error checking -->
		ref PChar = GetMainCharacter();
		DeleteAttribute(PChar, "questnotfound");				// Make sure this is GONE!

		// Common Quests
		CommonQuestComplete(sQuestName);						// <-- Execute the actual quest case
		if(!CheckAttribute(PChar, "questnotfound"))
		{
			trace("Quest name " + sQuestName + " FOUND in CommonQuestComplete");
			return;
		}
		DeleteAttribute(PChar, "questnotfound");

		// Main Quests
		if (FindFile("PROGRAM\" + GetStorylinePath(FindCurrentStoryline()), "*.c", "SL_utils.c") != "")
		{
			if (!SegmentIsLoaded(GetStorylinePath(FindCurrentStoryline()) + "SL_utils.c"))
			{
				trace("Loading " + GetStorylinePath(FindCurrentStoryline()) + "SL_utils.c");
				LoadSegment(GetStorylinePath(FindCurrentStoryline()) + "SL_utils.c");
			}
		}
		LoadStorylineFile("quests\", "quests_reaction.c");		// PB: To Prevent Errors
		QuestComplete(sQuestName);								// <-- Execute the actual quest case
		if(!CheckAttribute(PChar, "questnotfound"))
		{
			trace("Quest name " + sQuestName + " FOUND in QuestComplete");
			return;
		}
		DeleteAttribute(PChar, "questnotfound");

		// Both Quests
		if (FindFile("PROGRAM\" + GetStorylinePath(FindCurrentStoryline()), "*.c", "SL_utils.c") != "")
		{
			if (!SegmentIsLoaded(GetStorylinePath(FindCurrentStoryline()) + "SL_utils.c"))
			{
				trace("Loading " + GetStorylinePath(FindCurrentStoryline()) + "SL_utils.c");
				LoadSegment(GetStorylinePath(FindCurrentStoryline()) + "SL_utils.c");
			}
		}
		LoadStorylineFile("quests\", "both_reaction.c");		// PB: To Prevent Errors
		BothQuestComplete(sQuestName);							// <-- Execute the actual quest case
		if(!CheckAttribute(PChar, "questnotfound"))
		{
			trace("Quest name " + sQuestName + " FOUND in BothQuestComplete");
			return;
		}
		DeleteAttribute(PChar, "questnotfound");

		// Side Quests
		SideQuestComplete(sQuestName);							// <-- Execute the actual quest case
		if(!CheckAttribute(PChar, "questnotfound"))
		{
			trace("Quest name " + sQuestName + " FOUND in SideQuestComplete");
			return;
		}
		DeleteAttribute(PChar, "questnotfound");

		TraceAndLog("ERROR - Quest name " + sQuestName + " NOT found in ANY function");
		// PB: Error checking <--
	}
}

void procEvntQuestComplete()
{
	string qname = GetEventData();
	ref mch = GetMainCharacter();

	if( CheckAttribute(mch,"quest."+qname) )
	{
		if( CheckAttribute(mch,"quest."+qname+".win_condition") )
		{
			CompleteQuestName(mch.quest.(qname).win_condition);
			QuestsCheck();
		}
		else
		{
			trace("WARNING! Not win condition for quest " + qname);
		}
	}
	else
	{
		trace("WARNING! Not found quest name: " + qname);
	}
}

///////////////////////////////////
///  Это старая фигня - за использование буду бить морду... сильно
///////////////////////////////////

// Проиграть анимацию и по ее завершению вызвать квест
//------------------------------------------------------------
void ActAnimation(ref chref, string action, string questName)
{
//	chref.activity.endAnimationQuest.Name = questName;
//	actAction(chref, action, "ExitActAnimation");
}

// Всем воюющим персам убрать оружие, солдатам вернуться на свои позиции.
void BreakAllAttack()
{
//	actAllarm = 0.0;
//	int idxCurLoc = FindLoadedLocation();
//	if(idxCurLoc==-1) return;
//	string curLocName = Locations[idxCurLoc].id;
//
//	for(int n=0; n<MAX_CHARACTERS; n++)
//	{
//		if(Characters[n].location == curLocName)
//		{
//			actReset(&Characters[n]);
//			if( Characters[n].act.type == "soldier" ) SetCharacterTask_GotoPoint(&Characters[n],Characters[n].location.group,Characters[n].location.locator);
//		}
//	}
}

// KK -->
bool StoreOfficers(string idCharacter)
{
	int idxCh = GetCharacterIndex(idCharacter);
	if(idxCh==-1) return false;
	ref refCh = GetCharacter(idxCh);

	if(CheckAttribute(refCh,"Fellows.Old.Officers")) return false;

	string sTmp;
	aref arTmp;
	int i, indx;

	makearef(arTmp,refCh.Fellows.Old.Officers);
	for(i=1; i<4; i++)
	{
		indx = GetOfficersIndex(refCh,i);
		if(indx==-1) continue;
		sTmp = "id"+i;
		arTmp.(sTmp) = indx;

		RemoveOfficersIndex(refCh, indx);
		ChangeCharacterAddress(&characters[indx], "none", "");
	}
	return true;
}

bool RestoreOfficers(string idCharacter)
{
	int idxCh = GetCharacterIndex(idCharacter);
	if(idxCh==-1) return false;
	ref refCh = GetCharacter(idxCh);
	if(!CheckAttribute(refCh,"Fellows.Old.Officers")) return false;

	int i,idx;
	aref arTmp,arCur;

	makearef(arTmp,refCh.Fellows.Old.Officers);
	for(i=0; i<GetAttributesNum(arTmp); i++)
	{
		arCur = GetAttributeN(arTmp,i);
		idx = sti(GetAttributeValue(arCur));
		if(idx==-1) continue;
		SetOfficersIndex(refCh,-1,idx);
	}

	DeleteAttribute(refCh,"Fellows.Old.Officers");

	if (!CheckAttribute(refCh,"Fellows.Old.Passengers"))
		DeleteAttribute(refCh,"Fellows.Old");

	return true;
}

bool GiveShipCommandToOfficer(string idCharacter, int idx)
{
	int idxCh = GetCharacterIndex(idCharacter);
	if(idxCh==-1) return false;
	ref refCh = GetCharacter(idxCh);

	if(idx==-1) return false;
	if(CheckAttribute(refCh,"Fellows.Old.Passengers")) return false;

	string sTmp;
	aref arTmp;

	makearef(arTmp,refCh.Fellows.Old.Passengers);
	sTmp = "id0";
	arTmp.(sTmp) = idx;

	RemovePassenger(refCh,GetCharacter(idx));
	ChangeCharacterAddress(GetCharacter(idx),"none","");

	return true;
}

bool TakeShipCommandFromOfficer(string idCharacter)
{
	int idxCh = GetCharacterIndex(idCharacter);
	if(idxCh==-1) return false;
	ref refCh = GetCharacter(idxCh);
	if(!CheckAttribute(refCh,"Fellows.Old.Passengers")) return false;

	int idx;
	aref arTmp,arCur;

	makearef(arTmp,refCh.Fellows.Old.Passengers);
	arCur = GetAttributeN(arTmp,0);
	idx = sti(GetAttributeValue(arCur));
	AddPassenger(refCh,GetCharacter(idx),false);

	DeleteAttribute(refCh,"Fellows.Old.Passengers");

	if (!CheckAttribute(refCh,"Fellows.Old.Officers"))
		DeleteAttribute(refCh,"Fellows.Old");

	return true;
}

void SafePortLeave(int iNation, bool bOverride)
{
	ref mchr = GetMainCharacter();
	if (GetNationRelation2MainCharacter(iNation) == RELATION_ENEMY || bOverride) // Only if Required
	{
		mchr.quest.Safe_Port_Leave.flag = GetCurrentFlag();
		mchr.quest.Safe_port_leave.win_condition.l1 = "MapEnter";
		mchr.quest.Safe_port_leave.win_condition = "Safe_port_leave";

		HoistFlag(iNation); // PB: Hoist False Flag

		iForceDetectionFalseFlag = -1;
	}
}

bool LoadQuestBookData(string qname)
{
	//Changes for multiple istances of same quest by Levis -->
	string identifier = "&number=";
	if(hasSubStr(qname,identifier))
	{
		int place = findSubStr(qname, identifier, 0);
		qname = strleft(qname, place);
	}
	//Changes for multiple istances of same quest by Levis <--
	string language = LanguageGetLanguage();
	string dirname = "RESOURCE\INI\TEXTS\" + language + "\" + GetStorylinePath(FindCurrentStoryline()) + "QUESTBOOK\";
	string filename = qname + ".txt";
	if (FindFile(dirname, "*.txt", filename) == "") {
		dirname = "RESOURCE\INI\TEXTS\" + language + "\QUESTBOOK\";
		if (FindFile(dirname, "*.txt", filename) == "") return false;
	}
	filename = dirname + filename;
	ref qt; makeref(qt, QuestText);
	DeleteAttribute(qt, "");
	object otmp;
	ref rtmp; makeref(rtmp, otmp);
	SendMessage(&GameInterface, "lsa", MSG_INTERFACE_LOADOPTIONS, filename, &rtmp);
	CopyAttributes(qt, rtmp);
	qt.loaded=qname;
	return true;
}

string GetQuestBookTitle(string qname)
{
	ref qt; makeref(qt, QuestText);
	bool res = true;
	//Changes for multiple istances of same quest by Levis -->
	string identifier = "&number=";
	string qnamefile = qname;
	if(hasSubStr(qname,identifier))
	{
		int place = findSubStr(qname, identifier, 0);
		qnamefile = strleft(qname, place);
	}
	//Changes for multiple istances of same quest by Levis <--
	if (!CheckAttribute(qt, "loaded")) res = LoadQuestBookData(qnamefile);
	if (!res) return "";
	if (qt.loaded != qnamefile) res = LoadQuestBookData(qnamefile);
	if (!res) return "";
	string t = qt.title;
	int length = strlen(t);
	int j = 0;
	string text = "";
	while (j < length - 1) {
		text += strcut(t, j, j);
		j++;
	}
	return PreprocessText(text);
}

string GetQuestBookText(string qname, int n)
{
	if (n <= 0) return "";
	ref qt; makeref(qt, QuestText);
	bool res = true;
	//Changes for multiple istances of same quest by Levis -->
	string identifier = "&number=";
	string qnamefile = qname;
	if(hasSubStr(qname,identifier))
	{
		int place = findSubStr(qname, identifier, 0);
		qnamefile = strleft(qname, place);
	}
	//Changes for multiple istances of same quest by Levis <--
	if (!CheckAttribute(qt, "loaded")) res = LoadQuestBookData(qnamefile);
	if (!res) return "";
	if (qt.loaded != qnamefile) res = LoadQuestBookData(qnamefile);
	if (!res) return "";
	ref mc = GetMainCharacter();
	int i, num;
	string tn = "q" + n;
	if (CheckAttribute(mc, "QuestInfo." + qname + ".data." + tn)) {
		aref qdata; makearef(qdata, mc.QuestInfo.(qname).data.(tn));
		num = GetAttributesNum(qdata);
		for (i = 0; i < num; i++) {
			aref qd = GetAttributeN(qdata, i);
			Preprocessor_Add(GetAttributeName(qd), GetAttributeValue(qd));
		}
	}
	tn = "t" + n;
	if (!CheckAttribute(qt, "text."+tn)) return "";
	string text = "";
	aref artn; makearef(artn, qt.text.(tn));
	num = GetAttributesNum(artn);
	int length = 0;
	int j = 0;
	string t = "";
	if (num == 0) {
		text = qt.text.(tn);
		length = strlen(text);
		while (j < length - 1) {
			t += strcut(text, j, j);
			j++;
		}
		text = PreprocessText(t);
	} else {
		for (i = 0; i < num; i++) {
			tn = GetAttributeName(GetAttributeN(artn, i));
			string txt = "";
			length = strlen(artn.(tn));
			j = 0;
			t = "";
			while (j < length - 1) {
				t += strcut(artn.(tn), j, j);
				j++;
			}
			text += PreprocessText(t);
		}
	}
	Preprocessor_Clear(false);
	return text;
}

string GetQuestRecordText(string qname, int n)
{
	if (n <= 0) return "";
	ref qt; makeref(qt, QuestText);
	bool res = true;
	//Changes for multiple istances of same quest by Levis -->
	string identifier = "&number=";
	if(hasSubStr(qname,identifier))
	{
		int place = findSubStr(qname, identifier, 0);
		qname = strleft(qname, place);
	}
	//Changes for multiple istances of same quest by Levis <--
	if (!CheckAttribute(qt, "loaded")) res = LoadQuestBookData(qname);
	if (!res) return "";
	if (qt.loaded != qname) res = LoadQuestBookData(qname);
	if (!res) return "";
	string tn = "t" + n;
	if (!CheckAttribute(qt, "text."+tn)) return "";
	string text = "";
	aref artn; makearef(artn, qt.text.(tn));
	int num = GetAttributesNum(artn);
	int length = 0;
	int j = 0;
	string t = "";
	if (num == 0) {
		text = qt.text.(tn);
		length = strlen(text);
		while (j < length - 1) {
			t += strcut(text, j, j);
			j++;
		}
		text = PreprocessText(t);
	} else {
		for (int i = 0; i < num; i++) {
			tn = GetAttributeName(GetAttributeN(artn, i));
			string txt = "";
			length = strlen(artn.(tn));
			j = 0;
			t = "";
			while (j < length - 1) {
				t += strcut(artn.(tn), j, j);
				j++;
			}
			text += PreprocessText(t);
		}
	}
	return text;
}

int GetQuestRecord(string qname, int n)
{
	ref mchr = GetMainCharacter();
	if (!CheckAttribute(mchr, "QuestInfo." + qname)) return 0;
	int i = 1;
	int pos_beg = 0;
	int pos_end = 0;
	string text = mchr.QuestInfo.(qname).Text;
	while (i <= n) {
		pos_end = findSubStr(text, ",", pos_beg);
		if (pos_end < 0) {
			if (n == 1) return sti(text);
			if (i == n) return sti(strcut(text, pos_beg, strlen(text) - 1));
			return 0;
		}
		if (i == n) return sti(strcut(text, pos_beg, pos_end));
		pos_beg = pos_end + 1;
		i++;
	}
	return 0;
}
// <-- KK

// PB: To Prevent Errors -->
void LoadStorylineFile(string FolderName, string FileName)
{
	bool bSegLoaded = false;
	string segName = GetStorylinePath(FindCurrentStoryline()) + FolderName + FileName;
	if (FindFile("PROGRAM\" + GetStorylinePath(FindCurrentStoryline()) + FolderName, "*.c", FileName) != "")
	{
		if (!SegmentIsLoaded(segName))
		{
			bSegLoaded = LoadSegment(segName);
			trace(segName + " not loaded, loading now!");
		}
		if (!SegmentIsLoaded(segName))
		{
			TraceAndLog("ERROR - Unable to load " + segName + "!!!");
		}
	}
}

void UnloadStorylineFile(string FolderName, string FileName)
{
	string segName = GetStorylinePath(FindCurrentStoryline()) + FolderName + FileName;
//	if (SegmentIsLoaded(segName))
//	{
		trace(segName + " was loaded, unloading now...");
		UnloadSegment(segName);
//	}
}
// PB: To Prevent Errors <--
