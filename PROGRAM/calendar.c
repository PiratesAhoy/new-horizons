//--------------------------------------------------------------------
// Environment section
//--------------------------------------------------------------------
#define DAY_TIME_NIGHT		"Night"
#define DAY_TIME_MORNING	"Morning"
#define DAY_TIME_DAY		"Day"
#define DAY_TIME_EVENING	"Evening"

//Levis moon calculations
#define	MOON_CYCLE			29.530588853
#define FULL_MOON_DAYS		3
//Moon States
#define NEW_MOON			"New Moon"
#define	QUARTER_ONE			"Waxing crescent moon";
#define	QUARTER_TWO			"Waxing moon";
#define FULL_MOON			"Full Moon"
#define	QUARTER_THREE		"Waning moon"
#define QUARTER_FOUR		"Waning crescent moon"

void UpdateMoonInfo(bool print)
{
	ref PChar = GetMainCharacter();
	string oldstate = GetAttribute(PChar,"moonstate");
	string state = getMoonStateName(getMoonState());
	if(state != oldstate)
	{
		PChar.moonstate = state;
		if(print)
		{
			Logit(TranslateString("","Moon Status") + " " + TranslateString("",state));
		}
	}
}

string getMoonStateName(float state)
{
	//Set a threshold for full and new moon
	float threshold = (FULL_MOON_DAYS/2.0)/MOON_CYCLE;
	//Check for full moon
	if(state >= (0.5-Threshold) && state <= (0.5+Threshold))
	{
		return FULL_MOON;
	}
	//Check for new moon
	if(state >= (1-Threshold) || state <= (0+Threshold))
	{
		return NEW_MOON;
	}
	//Else return a normal state
	if(state >= 0.75) return QUARTER_FOUR;
	if(state >= 0.5) return QUARTER_THREE;
	if(state >= 0.25) return QUARTER_TWO;
	return QUARTER_ONE;
}

float getMoonState()
{
	//This returns a value between 0 and 1 where 0 is a new moon and 0.5 is a full moon.
	int days_since_epoch = GetPastTime("day", GetDataYear(),GetDataMonth() ,GetDataDay(), GetTime(), 1900,1,1,GetTime());
	float state = (1.0-fmod(MakeFloat(days_since_epoch), MOON_CYCLE))+0.5;
	if(state>=1)
	{
		state -= 1.0;
	}
	return state
}

float getMoonIntensity()
{
	//will return a value between 0 and 1 on how much light the moon produces with 1 being max.
	float state = getMoonState();
	state *= 2;
	if(state>1) state = 2-state;
	return state;
}

bool IsFullMoon(int accuracy)
{
	//accuray is a number of days which the full moon periode last. If put on 0 the default will be taken.
	if(accuracy<1)
	{
		accuracy = FULL_MOON_DAYS;
	}
	//Get the state of the moon.
	float cycle = getMoonState();
	//When the cycle gives 0.5 its a full moon we now calculate the Threshold value.
	float threshold = (accuracy/2.0)/MOON_CYCLE;
	if(threshold>0.5)
	{
		return true;
	}
	if(cycle >= (0.5-Threshold) && cycle <= (0.5+Threshold))
	{
		return true;
	}
	return false;
}

// KK -->
float GetTime()
{
	if (!CheckAttribute(&Environment, "time")) return 0.0;
	return stf(Environment.time);
}

//Levis -->
string GetTimeText(float time)
{
	//This function returns the time in an easy to read format
	string minutes;
	string hours = makeint(time);
	int iminutes = makeint((time-makeint(time))*60.0));
	if(iminutes < 10) minutes = "0";
	minutes += iminutes;
	return hours+":"+minutes;
}
//Levis <--
float GetHour()
{
	if (!CheckAttribute(&Environment, "date.hour")) return 0.0;
	return stf(Environment.date.hour);
}

float GetMinute()
{
	if (!CheckAttribute(&Environment, "date.min")) return 0.0;
	return stf(Environment.date.min);
}

float GetSecond()
{
	if (!CheckAttribute(&Environment, "date.sec")) return 0.0;
	return stf(Environment.date.sec);
}

int GetDataYear()
{
	if (!CheckAttribute(&Environment, "date.year")) return -1;
	return sti(Environment.date.year);
}

int GetDataMonth()
{
	if (!CheckAttribute(&Environment, "date.month")) return -1;
	return sti(Environment.date.month);
}

int GetDataDay()
{
	if (!CheckAttribute(&Environment, "date.day")) return -1;
	return sti(Environment.date.day);
}
// <-- KK

void SetDayTime(string name)
{
	switch(name)
	{
	case DAY_TIME_NIGHT:	SetCurrentTime(5,59);	break;
	case DAY_TIME_MORNING:	SetCurrentTime(9,59);	break;
	case DAY_TIME_DAY:		SetCurrentTime(17,59);	break;
	case DAY_TIME_EVENING:	SetCurrentTime(21,59);	break;
	}
}

string GetDayTime()
{
	if(GetTime()<6.0) return DAY_TIME_NIGHT;
	if(GetTime()<10.0) return DAY_TIME_MORNING;
	if(GetTime()<18.0) return DAY_TIME_DAY;
	if(GetTime()<22.0) return DAY_TIME_EVENING;
	return DAY_TIME_NIGHT;
}
bool IsDay()
{
// LDH fix for day changing back to night for an hour in the mornings
//	if(GetTime() > 7.0)	{if(GetTime() < 22.0) return true; } return false;
	float fTime = GetTime();
	if(fTime > 6.0 && fTime < 22.0) return true;
	return false;
}

// KK: and what with a LEAP years?! -->
int GetMonthDays(int month, int year)
{
	bool isLeap = false;
	while (month>12)
	{
		month -= 12;
	}
	if (year == 1582) {
		if (month == 10) return 21;
	}
	
	switch (month)
	{
		case 1:
			return 31;
		break;
		case 2:
			if (year % 400 == 0) {
				isLeap = true;
			} else {
				if (year % 100 != 0) {
					if (year % 4 == 0) isLeap = true;
				}
			}
			if (isLeap)
				return 29;
			else
				return 28;
		break;
		case 3:
			return 31;
		break;
		case 4:
			return 30;
		break;
		case 5:
			return 31;
		break;
		case 6:
			return 30;
		break;
		case 7:
			return 31;
		break;
		case 8:
			return 31;
		break;
		case 9:
			return 30;
		break;
		case 10:
			return 31;
		break;
		case 11:
			return 30;
		break;
		case 12:
			return 31;
		break;
	}
	Trace("Error: " + month + " month is not relevant");
	return 30;
}

//Returns the ammount of days in the year with leapyears taken into account
int GetYearDays(int year)
{
	bool isLeap = false;
	if (year % 400 == 0) 
	{
		isLeap = true;
	}
	else 
	{
		if (year % 100 != 0) 
		{
			if (year % 4 == 0) isLeap = true;
		}
	}
	if (isLeap)
		return 366;
	else
		return 365;
}
// <-- KK

// LDH 20Feb09 -->
// returns number of days since beginning of year (Jan 1 returns 1, Feb 1 returns 32, etc)
int GetDayOfYear(int year, int month, int day)
{
	int yearday = 0;

	int Leap = 0;
	if (month > 2)
	{
		if (year % 400 == 0) {
			Leap = 1;
		} else {
			if (year % 100 != 0) {
				if (year % 4 == 0) Leap = 1;
			}
		}
	}

	switch (month)
	{
	case  1: yearday =   0; break;	//   0
	case  2: yearday =  31; break;	// +31
	case  3: yearday =  59; break;	// +28
	case  4: yearday =  90;	break;	// +31
	case  5: yearday = 120;	break;	// +30
	case  6: yearday = 151;	break;	// +31
	case  7: yearday = 181;	break;	// +30
	case  8: yearday = 212;	break;	// +31
	case  9: yearday = 243;	break;	// +31
	case 10: yearday = 273;	break;	// +30
	case 11: yearday = 304;	break;	// +31
	case 12: yearday = 334;	break;	// +30
	}
	yearday += Leap;
	yearday += day;
	return yearday;
}
// LDH <--

int GetAddingDataYear(int addYear,int addMonth,int addDay)
{
	int nextDay = GetDataDay()+addDay;
	int curMonth = GetDataMonth();
	int curYear = GetDataYear(); // KK
	while(GetMonthDays(curMonth, curYear)<nextDay) // KK
	{
		nextDay = nextDay - GetMonthDays(curMonth, curYear); // KK
		curMonth++;
		//added by Levis to catch faulty months
		if(12<curMonth)
		{
			curMonth = curMonth - 12;
			curYear++;
		}
		if(1>curMonth)
		{
			curMonth = curMonth + 12;
			curYear--;
		}
		//end add
	}
	//add by levis to allow negative values
	while(1>nextDay)
	{
		nextDay = nextDay + GetMonthDays(curMonth, curYear);
		curMonth--;
		//added by Levis to catch faulty months
		if(12<curMonth)
		{
			curMonth = curMonth - 12;
			curYear++;
		}
		if(1>curMonth)
		{
			curMonth = curMonth + 12;
			curYear--;
		}
		//end add
	}
	//end add
	int nextMonth = curMonth+addMonth;
	int nextYear = curYear+addYear; // KK
	while(12<nextMonth)
	{
		nextMonth = nextMonth - 12;
		nextYear++;
	}
	//add by levis to allow negative values
	while(1>nextMonth)
	{
		nextMonth = nextMonth + 12;
		nextYear--;
	}
	//end add
	return nextYear;
}
int GetAddingDataMonth(int addYear,int addMonth,int addDay)
{
	int nextDay = GetDataDay()+addDay;
	int curMonth = GetDataMonth();
	int curYear = GetDataYear(); // KK
	while(GetMonthDays(curMonth, curYear)<nextDay) // KK
	{
		nextDay = nextDay - GetMonthDays(curMonth, curYear); // KK
		curMonth++;
		//added by Levis to catch faulty months
		if(12<curMonth)
		{
			curMonth = curMonth - 12;
		}
		if(1>curMonth)
		{
			curMonth = curMonth + 12;
		}
		//end add
	}
	//add by levis to allow negative values
	while(1>nextDay) // KK
	{
		nextDay = nextDay + GetMonthDays(curMonth, curYear); // KK
		curMonth--;
		//added by Levis to catch faulty months
		if(12<curMonth)
		{
			curMonth = curMonth - 12;
		}
		if(1>curMonth)
		{
			curMonth = curMonth + 12;
		}
		//end add
	}
	//end add
	int nextMonth = curMonth+addMonth;
	while(12<nextMonth)
	{
		nextMonth = nextMonth - 12;
	}
	//add by levis to allow negative values
	while(1>nextMonth)
	{
		nextMonth = nextMonth + 12;
	}
	//end add
	return nextMonth;
}
int GetAddingDataDay(int addYear,int addMonth,int addDay)
{
	int nextDay = GetDataDay()+addDay;
	int curMonth = GetDataMonth();
	int curYear = GetDataYear(); // KK
	while(GetMonthDays(curMonth, curYear)<nextDay) // KK
	{
		nextDay = nextDay - GetMonthDays(curMonth, curYear); // KK
	}
	//add by levis to allow negative values
	while(1>nextDay)
	{
		nextDay = nextDay + GetMonthDays(curMonth, curYear);
	}
	//end add
	return nextDay;
}
int GetAddingTimeDay(int hour,int minute)
{
	float curtime = GetTime();
	float nexttime = curtime+hour+(makefloat(minute)/60.0);
	int addingDays = 0;
	while(nexttime>=24.0)
	{
		nexttime = nexttime - 24.0;
		addingDays++;
	}
	return addingDays;
}
void AddTimeToCurrent(int hour,int minute)
{
	float curtime = GetTime();
	float nexttime = curtime+hour+(makefloat(minute)/60.0);
	int addingDays = 0;
	while(nexttime>=24.0)
	{
		nexttime = nexttime - 24.0;
		addingDays++;
	}
	AddDataToCurrent(0,0,addingDays, true); // do each day's update
	//this is handled by AddData below NK 05-04-17 if(addingDays>0) PostEvent("NextDay",0);
	Environment.time = nexttime;
	Environment.date.hour = makeint(nexttime);
	worldMap.date.hour = makeint(nexttime);
	nexttime = (nexttime - stf(Environment.date.hour))*60.0;
	Environment.date.min = makeint(nexttime);
	worldMap.date.min = makeint(nexttime);
}
void AddDataToCurrent(int addYear,int addMonth,int addDay, bool doupdate)
{
	if(addYear == 0 && addMonth == 0 && addDay == 0) return; // NK 05-04-24
	int oldDay = GetDataDay();
	int oldMonth = GetDataMonth();
	int oldYear = GetDataYear(); // NK 05-04-17 for total days tracking
	int nextDay = GetDataDay()+addDay;
	int curMonth = GetDataMonth();
	int curYear = GetDataYear(); // KK
	while (GetMonthDays(curMonth, curYear)<nextDay) // KK
	{
		nextDay = nextDay - GetMonthDays(curMonth, curYear); // KK
		curMonth++;
	}
	int nextMonth = curMonth+addMonth;
	int nextYear = curYear+addYear; // KK
	while (12 < nextMonth)
	{
		nextMonth = nextMonth - 12;
		nextYear++;
	}
	if (addYear!=0 || addMonth!=0 || addDay!=0)	// NK 05-04-17 do this once per day: PostEvent("NextDay",0);
	{
		if(doupdate)
		{
			int totaldays = GetPastTime("day", oldYear, oldMonth, oldDay, 0, nextYear, nextMonth, nextDay, 0);
			int i;
			// WM -->
			int start = 0;
			/*if(CheckAttribute(wdmgrid,"lastupdate.start"))
			{
				start = sti(wdmgrid.lastupdate.start);
			}*/
			for(i = 0; i < totaldays; i++)
			{
				//Event("NextDay");
				DoDailyUpdates("all"); // 05-05-04
				AddDataToCurrent(0,0,1,false); // update the date
			}
			//for(i = 0; i < totaldays; i++) PostEvent("NextDay",0);
			// WM <--
		}
		else
		{
			Environment.date.year = nextYear;
			Environment.date.month = nextMonth;
			Environment.date.day = nextDay;
			worldMap.date.year = nextYear;
			worldMap.date.month = nextMonth;
			worldMap.date.day = nextDay;
		}
	}
	// NK <--
}

// NK 05-05-04
// mask is a bitmask for: repair/dcu/towns/itrade/berthing/stores/fleets/quests. Length is 8 chars.
// can also be set to "all" to do all.
void DoDailyUpdates(string mask)
{
	if(mask == "all")
	{
//--------------------------
		// LDH copied from worldmap_events.c to pay crew salary - 05Jan09
		// Note:  This only runs if we're sailing. Can we get it to work overnight in tavern?
		//if (bSeaActive)		// LDH added 07Jan09  //Can also be triggered on land - Levis
		//{
		ref PChar = GetMainCharacter();
		if(!CheckAttribute(PChar,"articles"))		PChar.articles = 0;
		if(!CheckAttribute(PChar,"LastPayMonth"))	PChar.LastPayMonth = GetDataMonth(); // PB: NOT at the beginning of the game
// KK -->
		if(!LAi_IsFightMode(PChar)) //Don't show while in a battle
		{
			if( sti(PChar.LastPayMonth) != GetDataMonth() )
			{
				//if( GetDataDay() >= 7 && !sti(PChar.articles) ) //Can be triggered every day of the month in case you had a large cargo shift or something like that.
				//{
				if(!sti(PChar.articles)) //Check for articles -Levis
				{
					if (bSeaActive && IsEntity(&worldMap))
						LaunchSalaryScreen();
					else
						PostEvent("AskingSalary", 2500, "1", 0);
				}
				//}
			}
		}
// <-- KK
		//}
//--------------------------

		//trace("Gauging: Start DU");
		ProcessDayRepair();
		DailyCrewUpdate();
		UpdateAllTowns(false);
		UpdateAllItemTraders(false);
		DailyShipBerthingUpdate();
		//trace("Gauging: Stores start");
		UpdateAllStores(false);
		//trace("Gauging: Stores end");
		//wdmFleetsUpdateDay(); //wdmFleetsUpdate(false, false);
		QuestsCheck();
		//trace("Gauging: end DU");
		UpdateMoonInfo(LogsToggle == LOG_VERBOSE);
		//Smuggling
		UpdateAllIslandSmuggling();
		//Cargos
		UpdateAllCargos();
	}
	else
	{
		if(getsymbol(mask, 0) == "1") ProcessDayRepair();
		if(getsymbol(mask, 1) == "1") DailyCrewUpdate();
		if(getsymbol(mask, 2) == "1") UpdateAllTowns(false);
		if(getsymbol(mask, 3) == "1") UpdateAllItemTraders(false);
		if(getsymbol(mask, 4) == "1") DailyShipBerthingUpdate();
		if(getsymbol(mask, 5) == "1") UpdateAllStores(false);
		//if(getsymbol(mask, 6) == "1") wdmFleetsUpdateDay(); //wdmFleetsUpdate(false, false);
		//if(getsymbol(mask, 7) == "1") QuestsCheck();
		if(getsymbol(mask, 6) == "1" || getsymbol(mask, 7) == "1") QuestsCheck();
		if(getsymbol(mask, 8) == "1") UpdateAllIslandSmuggling(); //added by levis
	}
	AllDaysCount++;//MAXIMUS: for daily skills update
}
// NK <--
// "year","month","day","hour","minute"
int GetPastTime(string timeUnit,
				int pastYear,int pastMonth,int pastDay, float pastTime,
				int currentYear,int currentMonth,int currentDay, float currentTime)
{
	float dtime = currentTime - pastTime;
	int dyear = currentYear - pastYear;
	int dmonth = currentMonth - pastMonth;
	int dday = currentDay - pastDay;

	if(dtime<0.0)
	{
		dday--;
		dtime = dtime + 24.0;
	}
	if(dday<0)
	{
		dmonth--;
		if(pastMonth>1) dday = dday + GetMonthDays(pastMonth, pastYear); // KK	// LDH 03Jan09
		else dday = dday + GetMonthDays(12, pastYear); // KK
	}
	if(dmonth<0)
	{
		dyear--;
		dmonth = dmonth+12;
	}

	if(dyear<0) return 0;
	if(timeUnit=="year") return dyear;

	if(timeUnit=="month")
	{
		return dmonth+dyear*12;
	}
	
	//int dayCount = dday + dyear*365;	// LDH needs to track leap years as well - 03Jan09
	int dayCount = dday; //Years is done below to take leapyears into account
	
	for(int i=0; i<dmonth; i++)
	{
		dayCount = dayCount + GetMonthDays(pastMonth, pastYear); // KK
		pastMonth++;
		if(pastMonth>12) pastMonth = 1;
	}
	
	//Check for leap years - Levis
	for(i=0; i<dyear; i++)
	{
		dayCount = dayCount + GetYearDays(pastYear);
		pastyear++;
	}

	//if(timeUnit=="day")	return dayCount;

	if(timeUnit=="hour") return dayCount*24 + makeint(dtime);
	if(timeUnit=="minute") return dayCount*1440 + makeint(dtime*60.0);
	return dayCount;
}

// KK -->
void SetCurrentDate(int day, int month, int year)
{
	if (year == 1582 && month == 10) {
		if (day > 4 && day < 15) day = 15;
	}
	Environment.date.day = day;
	Environment.date.month = month;
	Environment.date.year = year;
	worldMap.date.day = day;
	worldMap.date.month = month;
	worldMap.date.year = year;
}
// <-- KK

void SetCurrentTime(int hour, int minutes)
{
	Environment.date.hour = hour;
	Environment.date.min = minutes;
	Environment.time = hour + makeint(makefloat(minutes) / 60.0); // KK
	worldMap.date.hour = hour;
	worldMap.date.min = minutes;
}

// NK add names 05-04-16 -->
string GetMonthName(int month)
{
	string tmpstr = "January";
	switch(month)
	{
		case 1:		tmpstr = "January";	break;
		case 2:		tmpstr = "February";	break;
		case 3:		tmpstr = "March";	break;
		case 4:		tmpstr = "April";	break;
		case 5:		tmpstr = "May";	break;
		case 6:		tmpstr = "June";	break;
		case 7:		tmpstr = "July";	break;
		case 8:		tmpstr = "August";	break;
		case 9:		tmpstr = "September";	break;
		case 10:	tmpstr = "October";	break;
		case 11:	tmpstr = "November";	break;
		case 12:	tmpstr = "December";	break;
		Trace("Error: " + month + " month is not relevant");
	}
	return tmpstr;
}

// KK -->
string GetDayName(int weekday)
{
	string tmpstr = "Sunday";
	switch(weekday)
	{
		case 0: tmpstr = "Sunday";    break;
		case 1: tmpstr = "Monday";    break;
		case 2: tmpstr = "Tuesday";   break;
		case 3: tmpstr = "Wednesday"; break;
		case 4: tmpstr = "Thursday";  break;
		case 5: tmpstr = "Friday";    break;
		case 6: tmpstr = "Saturday";  break;
	}
	return tmpstr;
}

// Returns: 0 - Sunday, 1 - Monday, ..., 6 - Saturday
int GetWeekday(int day, int month, int year)
{
	int wday;
	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + (12 * a) - 2;
	if (IsGregorian(day, month, year))
		wday = (day + y + makeint(y / 4) - makeint(y / 100) + makeint(y / 400) + makeint((31 * m) / 12)) % 7;
	else
		wday = (5 + day + y + makeint(y / 4) + makeint((31 * m) / 12)) % 7;
	return wday;
}

// Pass from Julian to Gregorian calendar: 4 Oct 1582 was followed by 15 Oct 1582
bool IsGregorian(int day, int month, int year)
{
	if (year > 1582) return true;
	if (year < 1582) return false;
	if (month > 10) return true;
	if (month < 10) return false;
	if (day > 14) return true;
	return false;
}
// <-- KK
