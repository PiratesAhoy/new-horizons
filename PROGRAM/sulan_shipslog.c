#define MAX_LOG_ENTRIES         100

// Write a new log entry to the ship's log
// logTitle: Title of the log entry
// logEntry: Text of the log entry
// logCategory: "General", "Battle", "Ship", "Personal", "Notes"
// bVisible: if log entry is visible (e.g. the news is known to the character) 
void WriteNewLogEntry(string logTitle, string logEntry, string logCategory, bool bVisible)
{
	ref pchar = GetMainCharacter();
	bool bUpdate;
	int i;
	int maxVal;
	string tmpLogTitle;
	string oldLog;
	string newLog;

	bUpdate = false;
	if(logCategory == GetAttribute(pchar, "shiplog.Category.log0")) // Update existing log entries to avoid log flooding
	{
		switch(logCategory)
		{
		case "Battle":
			if(GetStringDate(GetDataYear(), GetDataMonth(), GetDataDay()) == pchar.shiplog.Date.log0)
			{
				newLog = "";
				if(pchar.shiplog.Title.log0 != GetTranslatedLog("Several battles at sea")) { newLog = GetTranslatedLog("Encountered several enemy ships today"); newLog += "\n \n"; }
				pchar.shiplog.Title.log0 = GetTranslatedLog("Several battles at sea");
				newLog += pchar.shiplog.Entry.log0;
				newLog += "\n \n";
				newLog += logEntry;
				pchar.shiplog.Entry.log0 = newLog;
				bUpdate = true;
			}
			break;
		case "Ship":
			newLog = "";
			if(pchar.shiplog.Title.log0 == logTitle)
			{
				newLog += pchar.shiplog.Entry.log0;
				newLog += "\n \n";
				if(GetStringDate(GetDataYear(), GetDataMonth(), GetDataDay()) != pchar.shiplog.Date.log0) newLog += GetDayName(GetWeekday(GetDataDay(), GetDataMonth(), GetDataYear()))+", "+GetHumanDate(GetDataYear(), GetDataMonth(), GetDataDay())+": ";
				newLog += logEntry;
				pchar.shiplog.Entry.log0 = newLog;
				bUpdate = true;
			}
			break;
		}
	}

	if(bUpdate) return;
	// move all log entries one down.
	for(i=MAX_LOG_ENTRIES-1;i>=0;i--)
	{
		newLog = "log"+i;
		oldLog = "log"+(i+1);
		if(CheckAttribute(pchar, "shiplog.Title."+newLog))    
		{
			pchar.shiplog.Date.(oldLog) = pchar.shiplog.Date.(newLog);            
			pchar.shiplog.Title.(oldLog) = pchar.shiplog.Title.(newLog);
			pchar.shiplog.Entry.(oldLog) = pchar.shiplog.Entry.(newLog);
			pchar.shiplog.Category.(oldLog) = pchar.shiplog.Category.(newLog);
			pchar.shiplog.Visible.(oldLog) = pchar.shiplog.Visible.(newLog);
		}
	} 
	// set the new log entry.
	pchar.shiplog.Date.log0 = GetStringDate(GetDataYear(), GetDataMonth(), GetDataDay());
	pchar.shiplog.Title.log0 = logTitle;
	pchar.shiplog.Entry.log0 = logEntry;
	pchar.shiplog.Category.log0 = logCategory;
	pchar.shiplog.Visible.log0 = bVisible;        

	// PB: Sound and on-screen effects -->
	if (bVisible)
	{
		if (logCategory == "General" || logCategory == "Personal")
		{
			Log_SetStringToLog(XI_ConvertString("Ship Log Update"));
			AddMsgToCharacter(pchar,MSGICON_LOGBOOK);
			PlaySound("INTERFACE\notebook_01.wav");
		}
	}
	// PB: Sound and on-screen effects <--
}

// Make all invisible log entries visible (e.g. after reading news at tavern)
void SetLogVisible()
{
	ref pchar = GetMainCharacter();
	int i;
	string tmp;
	
	for(i=0;i<=MAX_LOG_ENTRIES;i++)
	{
		tmp = "log"+i;
		if(CheckAttribute(pchar, "shiplog.Title."+tmp))    
		{
			pchar.shiplog.Visible.(tmp) = true;        
		}
	}
}

// Check, if log entry with such title already exists
bool LogEntryExists(string logTitle)
{
	ref pchar = GetMainCharacter();
	int i;
	string tmp;
	
	for(i=0;i<=MAX_LOG_ENTRIES;i++)
	{
		tmp = "log"+i;
		if(CheckAttribute(pchar, "shiplog.Title."+tmp))    
		{
			if(pchar.shiplog.Title.(tmp) == logTitle)
			{
				return true;
			}        
		}
	}
	return false;
}

void UpdateStatistics(string sStat, int num)
{
	ref pchar = GetMainCharacter();
	pchar.shiplog.Stats.(sStat) = sti(pchar.shiplog.Stats.(sStat))+num;
}

string GetStatistics(string sStat)
{
	ref pchar = GetMainCharacter();
	if(CheckAttribute(pchar, "shiplog.Stats."+sStat)) return pchar.shiplog.Stats.(sStat);
	else return "0";
}


string GetLogTime()
{
	int i = makeint(GetTime());
	string tmp;
	string sDateTime;  

	tmp="around midnight";
	
	switch(i)
	{
	case 2:
		tmp="in the night, quite some time after midnight";
		break;
	case 3:
		tmp="in the night, quite some time after midnight";
		break;
	case 4:
		tmp="in the early morning, before dawn,";
		break;
	case 5:
		tmp="in the early morning, before dawn,";
		break;
	case 6:
		tmp="in the early morning, with the sun rising,";
		break;
	case 7:
		tmp="in the early morning, with the sun rising,";
		break;
	case 8:
		tmp="in the morning";
		break;
	case 9:
		tmp="in the morning";
		break;
	case 10:
		tmp="in the morning";
		break;
	case 11:
		tmp="around noon";
		break;
	case 12:
		tmp="around noon";
		break;
	case 13:
		tmp="around noon";
		break;
	case 14:
		tmp="in the early afternoon";
		break;
	case 15:
		tmp="in the early afternoon";
		break;
	case 16:
		tmp="in the afternoon";
		break;
	case 17:
		tmp="in the afternoon";
		break;
	case 18:
		tmp="in the evening";
		break;
	case 19:
		tmp="in the evening";
		break;
	case 20:
		tmp="in the evening, the sun was not yet set,";
		break;
	case 21:
		tmp="in the evening, the sun was not yet set,";
		break;
	case 22:
		tmp="in the late evening after sunset";
		break;
	case 23: 
		tmp="in the night";   
		break;
	}

	sDateTime=GetTranslatedLog("On ")+GetDayName(GetWeekday(GetDataDay(), GetDataMonth(), GetDataYear()))+", "+GetHumanDate(GetDataYear(), GetDataMonth(), GetDataDay())+" "+GetTranslatedLog(tmp);
	return sDateTime;
}
