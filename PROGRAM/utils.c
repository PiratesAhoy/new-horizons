// KK #define PARSE_STRING	"PARSE_STRING"

// KK -->
#define DEFAULT_PROFILE_NAME "Player"
// <-- KK

// KK #event_handler(PARSE_STRING, "ParseString");

int AddStr2Array(ref rNames, int iNum, string sStr)
{
	SetArraySize(rNames, iNum + 1);
	rNames[iNum] = sStr;
	iNum++;
	return iNum;
}

string GetRandSubString(string sStr)
{
	string sTemp = sStr;	// LDH 07Oct06
	int iFindPos = findSubStr(&sStr, ",", 0);
	if(iFindPos < 0) return sTemp;	// one word in string - LDH 07Oct06 fix invalid return error, was return sStr
	int iNumFind = 1;
	while (iFindPos > 0)
	{
		iNumFind++;
		iFindPos = findSubStr(&sStr, ",", iFindPos + 1);
	}
	int iSelect = rand(iNumFind - 1);
	int	iLastPos = 0;
	for (int i=0; i<iNumFind; i++)
	{
		iFindPos = findSubStr(&sStr, ",", iFindPos + 1);
		if(i == iSelect)
		{
			if(iFindPos == -1) iFindPos = strlen(&sStr);
			sTemp = strcut(&sStr, iLastPos, iFindPos - 1);
			return sTemp;
		}
		iLastPos = iFindPos + 1;
	}

	return "If you see this, you can kick Vano :)";
}

float GetDotProduct(float fA1, float fA2)
{
	float x1, y1, x2, y2;
	x1 = sin(fA1);	y1 = cos(fA1);
	x2 = sin(fA2);	y2 = cos(fA2);

	return (x2 * x1 + y2 * y1);
}

/*float Clampf(float fClamp)
{
	if(fClamp > 1.0) return 1.0;
	if(fClamp < 0.0) return 0.0;
	return fClamp;
}
*/

/*float Bring2Range(float fMin1, float fMax1, float fMin2, float fMax2, float fValue)
{
	if(fValue < fMin2) { fValue = fMin2; }
	if(fValue > fMax2) { fValue = fMax2; }
	float fDelta = (fValue - fMin2) / (fMax2 - fMin2);
	return fMin1 + fDelta * (fMax1 - fMin1);
}
*/

/* KK -->
void ParseString()
{
	int		i, iLen;
	string	sParams[2];
	string	sDst = "";

	aref aRes = GetEventData();
	string rSourceString = GetEventData();
	int	iNumParameters = GetEventData();

	//Trace("parser started: " + rSourceString + ", params = " + iNumParameters);

	if(iNumParameters == 0)
	{
		aRes.Str = rSourceString;
		return;
	}

	SetArraySize(&sParams, iNumParameters + 1);
	for (i=0; i<iNumParameters; i++) { sParams[i] = GetEventData();	}

	iLen = strlen(&rSourceString);
	for (i=0; i<iLen; i++)
	{
		string sChar = GetSymbol(&rSourceString, i);
		if(sChar == "%")
		{
			if(GetSymbol(&rSourceString, i + 1) == "%")
			{
				sDst = sDst + "%";
				i++;
				continue;
			}
			// get parameter number
			string sNumber = "";
			i++;
			while (i < iLen)
			{
				string sTmp = GetSymbol(&rSourceString, i);
				if(!isDigit(&sTmp, 0)) { break; }
				sNumber = sNumber + sTmp;
				i++;
			}
			sDst = sDst + sParams[sti(sNumber) - 1]; i--;
			continue;
		}
		sDst = sDst + sChar;
	}

	aRes.Str = sDst;
}
<-- KK */

float GetDistance2D(float x1, float y1, float x2, float y2)
{
	return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

void RotateAroundY(ref rX, ref rZ, float fCos, float fSin)
{
	float xxx = rX;
	float zzz = rZ;
	float xx = xxx * fCos + zzz * fSin;
	float zz = zzz * fCos - xxx * fSin;
	rX = xx;
	rZ = zz;
}

int Tonnes2CWT(int iTonnes)
{
	int a = iTonnes * 10000 / 508;
	a = 100 * ((a + 99) / 100);
	return a;
}

// NK -->

//these work like if statements in excel, i.e. they're in-line ifs. -->

int intRet(bool test, int retT, int retF)
{
	if(test) return retT;
	return retF;
}

float floatRet(bool test, float retT, float retF)
{
	if(test) return makefloat(retT);
	return makefloat(retF);
}

string stringRet(bool stest, string sretT, string sretF)
{
	if(stest) return sretT;
	return sretF;
}

object objectRet(bool test, object retT, object retF)
{
	if(test) return retT;
	return retF;
}

ref refRet(bool test, ref retT, ref retF)
{
	if(test) return &retT;
	return &retF;
}
// inline ifs <--

int roundup(float num)
{
	if(makeint(num) >= num) return makeint(num);
	else return makeint(num) + 1;
}

int rounddown(float num)
{
	//this is actually unneeded since makeint() already does this. Argh, I thought it rounded.
	return makeint(num);
	/*if(makeint(num) <= num) return makeint(num);
	else return makeint(num) - 1;*/
}

// new 05-04-05
int round(float num)
{
	return makeint(num + 0.5);
}

//Levis:
float roundto(float num, int fractals)
{
	return makefloat(round(num*(pow(10,fractals))))/100.0;
}

//strips spaces from a string
string stripblank(string str)
{
	string retstr = "";
	for(int i = 0; i < strlen(str); i++) {
		if(GetSymbol(str,i) != " ") { retstr += GetSymbol(str,i); }}
	return retstr;
}

// strips the hashes (for inventories)
string striphash(string str)
{
	string retstr = "";
	for(int i = 0; i < strlen(str); i++) {
		if(GetSymbol(str,i) != "#") { retstr += GetSymbol(str,i); }}
	return retstr;
}

float pow2(float num, float exp) // supports exponents of less than one via sqrt and a loop. Pure math, woohoo!
{
	if(exp == 1.0) return num; // NK 05-03-30 add this check
	if(exp > 1.0) return pow(num, exp);
	int sqrtx = 0;
	while(exp < 1.0)
	{
		exp *= 2;
		sqrtx++;
	}
	num = pow(num, exp);
	for(int i = 0; i < sqrtx; i++)
	{
		// PB: No negative values to fix CTDs -->
		if(num<0) trace("BUG in float pow2(float num, float exp) function : function called with negative num");
		num = sqrt(abs(num));
		// PB: No negative values to fix CTDs <--
	}
	return num;
}

// KK -->
float fmod(float x, float y)
{
	if (y == 0.0) return 0.0;
	return ((x / y) - (x % y));
}
// <-- KK

// 05-04-18 quadrant handling funcs

// 05-04-30 returns quadrant based on points vs. origin
int QuadrantFromPoints(float x, float y)
{
	if(x >= 0)
	{
		if(y >=0) { return 0; }
		return 1;
	}
	//assume x < 0
	if(y < 0) { return 2; }
	return 3;
}


//returns gun arc. 0 = f, 1 = r, 2 = b, 3 = l
int quadrantG(float ship, float ball)
{
	ship = clampangle(ship); ball = clampangle(ball);
	// rotate angles so ship is 0
	ball = ball - ship; // + PI/4.0; // so that it's not +-45degrees, it's 0-90deg
	//ship = 0;
	//do it here.
	//trace("Doing check. Ball = " + Radian2Degree(ball) + ", Ship = " + Radian2Degree(ship));
	int ang = round(Radian2Degree(ball));
	while (ang >= 360) ang -= 360;
	while(ang < 0) ang += 360;
	if(ang < 180+30)
	{
		if(ang < 30) return 0;
		if(ang < 180-30) return 1;
		return 2;
	}
	else
	{
		if(ang < 360-30) return 3;
		return 0;
	}
	//return quadrant(ball, 0.075);
	/*if(ship > PI)
	{
		tmp = PIm2 - ship;
		ball += tmp;
	}
	return quadrant2(ang1+PI/2.0, ang2+PI/2.0);*/
}
//returns quadrant off vs base
int quadrant2(float base, float off)
{
	return quadrant(clampangle(off-base), false);
}

//returns quadrant of ang1. fudge is for gun arcs (sides more important)
int quadrant(float ang1, float fudge)
{
	if(fudge)
	{
		if(ang1 < fudge) return 3;
		if(ang1 < PId2-fudge) return 0;
		if(ang1 < PI+fudge) return 1;
		if(ang1 < PI + PId2-fudge) return 2;
		return 3;
	}
	else
	{
		if(ang1 < PId2) return 0;
		if(ang1 < PI) return 1;
		if(ang1 < PI + PId2) return 2;
		return 3;
	}
}

// KK -->
int GetQuadFromBort(string bortName)
{
	switch (bortName)
	{
		case "cannonF": return 0; break;
		case "cannonR": return 1; break;
		case "cannonB": return 2; break;
		case "cannonL": return 3; break;
	}
	return 0;
}
// <-- KK

//returns name of gun arc
string GetQuadName(int quad)
{
	switch(quad)
	{
		case 0: return "cannonF"; break;
		case 1: return "cannonR"; break;
		case 2: return "cannonB"; break;
		case 3: return "cannonL"; break;
	}
	return "cannonf"; // just in case
}

//returns fancy name of gun arc
string GetQuadText(int quad)
{
	string retstr = "";
	switch(quad)
	{
		case 0: retstr =  "bow"; break;
		case 1: retstr =  "starboard"; break;
		case 2: retstr =  "stern"; break;
		case 3: retstr =  "port"; break;
	}
	//return XI_ConvertString(retstr);
	return retstr;
}
//clamps angle to 0-2Pi range. 04-09-21
float ClampAngle(float ang)
{
	while (ang >= PIm2) ang -= PIm2;
	while (ang < 0) ang += PIm2;
	return ang;
}

// 05-03-30 fclamp
float fClamp(float min, float max, float val)
{
	if(val < min) val = min;
	else
	{
		if(val > max) val = max;
	}
	return val;
}

// 05-04-18 int version
int iClamp(int min, int max, int val)
{
	if(val < min) val = min;
	else
	{
		if(val > max) val = max;
	}
	return val;
}


//convert angle in radians to degrees 04-09-23
float Radian2Degree(float ang)
{
	return ClampAngle(ang) / PIm2 * 360;
}

// takes a time in seconds and spits out a nice friendly string
string MakeTimeString(int time)
{
	string retstr = "";
	if(time >= 60*60)
	{
		retstr = makeint(makefloat(time)/(60*60)) + " " + XI_ConvertString("hours");
		time = time - (makeint(makefloat(time)/(60*60)) * 60 * 60);
	}
	if(time > 60)
	{
		if(retstr != "") retstr += ", ";
		retstr += makeint(makefloat(time)/(60)) + " " + XI_ConvertString("minutes");
		time = time - (makeint(makefloat(time)/(60)) * 60);
	}
	//if(time > 0)
	//{
		if(retstr != "") retstr += ", ";
		retstr += time + " " + XI_ConvertString("seconds");
	//}
	return retstr;
}

// STRING OPERATIONS

// will return specified piece of string. Takes string in, goes to the start'th appearance of div, and returns the following chars until hitting div.
// rewritten 05-07-10 to use native calls. Woot!
string GetSubString(string in, string div, int start)
{
	if(start <0) return "";
	int i = 0;
	int pos = 0;
	while(i < start && pos != -1)
	{
		pos = findsubstr(in, div, pos+1);
		i++;
	}
	if(pos == -1) return "";
	if(pos > 0) pos++;
	int endpos = findsubstr(in, div, pos+1);
	if(endpos == -1) endpos = strlen(in);
	string retstr = strcut(in, pos, endpos-1);
	if(retstr != div) return retstr;
	return "";
}


// 05-05-02
// will remove specified string from basestring, either the first instance or all instances.
// causes an INVALID RANGE error because of the argument (found + sublen); I have no idea why. Works perfectly though.
string SubtractString(string base, string subtract, bool allinstances)
{
	int found = findSubStr(base, subtract, 0);
	if(found == -1) return base;
	int sublen = strlen(subtract);
	int baselen = strlen(base);
	string retstr = strcut(base, found + sublen, baselen-1);
	if(found != 0) retstr = strcut(base, 0, found-1) + retstr;
	if(allinstances) return SubtractString(retstr, subtract, true);
	else return retstr;
}

// 05-05-08
// will send back string instr in two pieces, with part1 being all of instr up to cutstr, and part2 all of instr after cutstr
// returns true if cutstr exists in instr (and operation successful)
// based on iface\Character.c SetCharacterName()
bool DivideString(string instr, string cutstr, ref part1, ref part2)
{
	bool bret = false;
	int fndNum = findSubStr(instr,cutstr,0);
	part1 = instr;
	part2 = "";
	int slen;
	if(fndNum>0)
	{
		bret = true;
		part1 = strcut(instr,0,fndNum-1);
		slen = strlen(instr);
		part2 = strcut(instr,fndNum+strlen(cutstr),slen-1);
	}
	else
	{
		part1 = instr;
		part2 = "";
	}

	return bret;
}

int FindSubstrTrim(string instr, int startIdx, ref part)
{
	int endIdx = findSubStr(instr, " ", startIdx);
	if(endIdx == startIdx)
	{
		endIdx = findSubStr(instr, " ", startIdx + 1);
		while(endIdx == startIdx + 1)
		{
			startIdx = endIdx;
			endIdx = findSubStr(instr, " ", endIdx + 1);
		}
		// start still on last space before word, so:
		startIdx++;
	}

	if(endIdx < 0)
	{
		// spaces not found or only at start
		part = strcut(instr, startIdx, strlen(instr) - 1);
		return -1;
	}

	part = strcut(instr, startIdx, endIdx - 1);

	// search for first nonspace character
	startIdx = endIdx - 1;
	while(endIdx == startIdx + 1)
	{
		startIdx = endIdx;
		endIdx = findSubStr(instr, " ", endIdx + 1);
	}

	startIdx++;

	if(endIdx < 0 && startIdx == strlen(instr))
	{
		return -1;
	}

	// endIdx is first space AFTER the new word!
	// start is last before
	return startIdx;
}

// added 05-07-13 to ease in use in if() statements
bool HasSubStr(string basestr, string findstr)
{
	return findSubStr(basestr, findstr, 0) != -1;
}

// returns "num" characters from left end of string
// strleft("abcd",1) returns "a"
// strleft("abcd",3) returns "abc"
// strleft("abcd",10) returns "abcd" without error
string strleft(string str, int num)
{
	if (num < 1) return "";
	int len = strlen(str);
	if (num > len) num = len;
	return strcut(str,0,num-1);
}

string strright(string str, int num)
{
	if (num < 1) return "";
	int len = strlen(str);
	int start = len - num;
	if (start < 0) start = 0;
	return strcut(str,start,len-1);
}

// KK -->
string strreplace(string str, string from, string into)
{
	int pos = findSubStr(str, from, 0);
	if (pos < 0) return str;
	if (HasSubStr(into, from)) return str;
	string ret = "";
	if (pos > 0) ret = strcut(str, 0, pos - 1);
	ret += into;
	if (pos + strlen(from) <= strlen(str) - 1) ret += strcut(str, pos + strlen(from), strlen(str) - 1);
	return strreplace(ret, from, into);
}
// <-- KK

/*
string strcut1(string str, int start, int stop)
{
	int len = strlen(str);
	if (start > stop) return "";
	if (len < start+1) return "";
	if (len < stop) return strcut(str, start, len-1);
	if (len >= stop) return strcut(str, start, stop);	// normal return
	return "";
}
*/

// Bitwise operators, implemented for strings.
// 05-07-07

string BitNot(string instr)
{
	string outstr = "";
	for(int i = 0; i < strlen(instr); i++)
	{
		if(getsymbol(instr, i) == "1") outstr += "0";
		else outstr += "1";
	}
	return outstr;
}

string BitAnd(string instr1, string instr2)
{
	string outstr = "";
	int shortlen, longlen; shortlen = strlen(instr1); longlen = strlen(instr2);
	if(shortlen > longlen)
	{
		shortlen = longlen; longlen = strlen(instr1);
	}
	for(int i = 0; i < shortlen; i++)
	{
		if(getsymbol(instr1, i) == "1" && getsymbol(instr2, i) == "1") outstr += "1";
		else outstr += "0";
	}
	for(i = shortlen; i < longlen; i++)
	{
		outstr += "0";
	}
	return outstr;
}

string BitOr(string instr1, string instr2)
{
	string outstr = "";
	int shortlen, longlen; shortlen = strlen(instr1); longlen = strlen(instr2);
	int longstr = 2;
	if(shortlen > longlen)
	{
		shortlen = longlen; longlen = strlen(instr1);
		longstr = 1;
	}
	for(int i = 0; i < shortlen; i++)
	{
		if(getsymbol(instr1, i) == "1" || getsymbol(instr2, i) == "1") outstr += "1";
		else outstr += "0";
	}
	if(shortlen != longlen)
	{
		switch(longstr)
		{
			case 1:
				for(i = shortlen; i < longlen; i++)
				{
					if(getsymbol(instr1, i) == "1") outstr += "1";
					else outstr += "0";
				}
			break;

			case 2:
				for(i = shortlen; i < longlen; i++)
				{
					if(getsymbol(instr2, i) == "1") outstr += "1";
					else outstr += "0";
				}
			break;
		}
	}
	return outstr;
}

string BitXOr(string instr1, string instr2)
{
	string outstr = "";
	int shortlen, longlen; shortlen = strlen(instr1); longlen = strlen(instr2);
	int longstr = 2;
	if(shortlen > longlen)
	{
		shortlen = longlen; longlen = strlen(instr1);
		longstr = 1;
	}
	for(int i = 0; i < shortlen; i++)
	{
		if(getsymbol(instr1, i) == "1" && getsymbol(instr2, i) == "0") outstr += "1";
		else
		{
			if(getsymbol(instr1, i) == "0" && getsymbol(instr2, i) == "1") { outstr += "1"; }
			else { outstr += "0"; }
		}
	}
	if(shortlen != longlen)
	{
		switch(longstr)
		{
			case 1:
				for(i = shortlen; i < longlen; i++)
				{
					if(getsymbol(instr1, i) == "1") outstr += "1";
					else outstr += "0";
				}
			break;

			case 2:
				for(i = shortlen; i < longlen; i++)
				{
					if(getsymbol(instr2, i) == "1") outstr += "1";
					else outstr += "0";
				}
			break;
		}
	}
	return outstr;
}

// 05-07-21
// toupper and tolower
// KK -->
string toupper(string c)
{
	int kl = GetKeyboardLayout();
	switch (kl) {
		case ILANG_RUS:
			return toupperrus(c);
		break;
		case ILANG_SPA:
			return toupperspa(c);
		break;
		case ILANG_FRA:
			return toupperfra(c);
		break;
		case ILANG_GER:
			return toupperger(c);
		break;
		case ILANG_POL:
			return toupperpol(c);
		break;
	}
	return touppereng(c);
}

string tolower(string c)
{
	int kl = GetKeyboardLayout();
	switch (kl) {
		case ILANG_RUS:
			return tolowerrus(c);
		break;
		case ILANG_SPA:
			return tolowerspa(c);
		break;
		case ILANG_FRA:
			return tolowerfra(c);
		break;
		case ILANG_GER:
			return tolowerger(c);
		break;
		case ILANG_POL:
			return tolowerpol(c);
		break;
	}
	return tolowereng(c);
}

string touppereng(string c)
{
	switch(c)
	{
		case "a": return "A"; break;
		case "b": return "B"; break;
		case "c": return "C"; break;
		case "d": return "D"; break;
		case "e": return "E"; break;
		case "f": return "F"; break;
		case "g": return "G"; break;
		case "h": return "H"; break;
		case "i": return "I"; break;
		case "j": return "J"; break;
		case "k": return "K"; break;
		case "l": return "L"; break;
		case "m": return "M"; break;
		case "n": return "N"; break;
		case "o": return "O"; break;
		case "p": return "P"; break;
		case "q": return "Q"; break;
		case "r": return "R"; break;
		case "s": return "S"; break;
		case "t": return "T"; break;
		case "u": return "U"; break;
		case "v": return "V"; break;
		case "w": return "W"; break;
		case "x": return "X"; break;
		case "y": return "Y"; break;
		case "z": return "Z"; break;

		case "à": return "À"; break;
		case "á": return "Á"; break;
		case "â": return "Â"; break;
		case "ã": return "Ã"; break;
		case "İ": return "Ã"; break; // PB: Needed to display this properly
		case "ä": return "Ä"; break;
		case "å": return "Å"; break;
		case "¸": return "¨"; break;
		case "æ": return "Æ"; break;
		case "ç": return "Ç"; break;
		case "è": return "È"; break;
		case "é": return "É"; break;
		case "ê": return "Ê"; break;
		case "ë": return "Ë"; break;
		case "ì": return "Ì"; break;
		case "í": return "Í"; break;
		case "î": return "Î"; break;
		case "ï": return "Ï"; break;
		case "ğ": return "Ğ"; break;
		case "ñ": return "Ñ"; break;
		case "ò": return "Ò"; break;
		case "ó": return "Ó"; break;
		case "ô": return "Ô"; break;
		case "õ": return "Õ"; break;
		case "ö": return "Ö"; break;
		case "÷": return "×"; break;
		case "ø": return "Ø"; break;
		case "ù": return "Ù"; break;
		case "ú": return "Ú"; break;
		case "û": return "Û"; break;
		case "ü": return "Ü"; break;
		case "ı": return "İ"; break;
		case "ş": return "Ş"; break;
		case "ÿ": return "ß"; break;

		case "1": return "!"; break;
		case "2": return "@"; break;
		case "3": return "#"; break;
		case "4": return "$"; break;
		case "5": return "%"; break;
		case "6": return "^"; break;
		case "7": return "&"; break;
		case "8": return "*"; break;
		case "9": return "("; break;
		case "0": return ")"; break;
	//	case "-": return "_"; break;
		case "-": return " "; break; // PB: Interface title font has no dash
		case "=": return "+"; break;
		case "[": return "{"; break;
		case "]": return "}"; break;
		case "\": return "|"; break;
		case ";": return ":"; break;
		case "'": return GlobalStringConvert("DOUBLE_QUOTE"); break;
		case ",": return "<"; break;
		case ".": return ">"; break;
		case "/": return "?"; break;
		case "`": return "~"; break;
	}
	return c;
}

string tolowereng(string c)
{
	switch(c)
	{
		case "a": return "a"; break;
		case "b": return "b"; break;
		case "c": return "c"; break;
		case "d": return "d"; break;
		case "e": return "e"; break;
		case "f": return "f"; break;
		case "g": return "g"; break;
		case "h": return "h"; break;
		case "i": return "i"; break;
		case "j": return "j"; break;
		case "k": return "k"; break;
		case "l": return "l"; break;
		case "m": return "m"; break;
		case "n": return "n"; break;
		case "o": return "o"; break;
		case "p": return "p"; break;
		case "q": return "q"; break;
		case "r": return "r"; break;
		case "s": return "s"; break;
		case "t": return "t"; break;
		case "u": return "u"; break;
		case "v": return "v"; break;
		case "w": return "w"; break;
		case "x": return "x"; break;
		case "y": return "y"; break;
		case "z": return "z"; break;
		case "=": return ""; break;
	}
	return c;
}

// added by MAXIMUS for typing on Russian -->
string toupperrus (string c)
{
	switch(c)
	{
		case "à": return "À"; break;
		case "á": return "Á"; break;
		case "â": return "Â"; break;
		case "ã": return "Ã"; break;
		case "ä": return "Ä"; break;
		case "å": return "Å"; break;
		case "¸": return "¨"; break;
		case "æ": return "Æ"; break;
		case "ç": return "Ç"; break;
		case "è": return "È"; break;
		case "é": return "É"; break;
		case "ê": return "Ê"; break;
		case "ë": return "Ë"; break;
		case "ì": return "Ì"; break;
		case "í": return "Í"; break;
		case "î": return "Î"; break;
		case "ï": return "Ï"; break;
		case "ğ": return "Ğ"; break;
		case "ñ": return "Ñ"; break;
		case "ò": return "Ò"; break;
		case "ó": return "Ó"; break;
		case "ô": return "Ô"; break;
		case "õ": return "Õ"; break;
		case "ö": return "Ö"; break;
		case "÷": return "×"; break;
		case "ø": return "Ø"; break;
		case "ù": return "Ù"; break;
		case "ú": return "Ú"; break;
		case "û": return "Û"; break;
		case "ü": return "Ü"; break;
		case "ı": return "İ"; break;
		case "ş": return "Ş"; break;
		case "ÿ": return "ß"; break;

		case "1": return "!"; break;
		case "2": return "''"; break;
		case "3": return "¹"; break;
		case "4": return ";"; break;
		case "5": return "%"; break;
		case "6": return ":"; break;
		case "7": return "?"; break;
		case "8": return "*"; break;
		case "9": return "("; break;
		case "0": return ")"; break;
		case "-": return "_"; break;
		case "=": return "+"; break;

		case ".": return ","; break;
	}
	return c;
}

string tolowerrus(string c)
{
	switch(c)
	{
		case "à": return "à"; break;
		case "á": return "á"; break;
		case "â": return "â"; break;
		case "ã": return "ã"; break;
		case "ä": return "ä"; break;
		case "å": return "å"; break;
		case "¸": return "¸"; break;
		case "æ": return "æ"; break;
		case "ç": return "ç"; break;
		case "è": return "è"; break;
		case "é": return "é"; break;
		case "ê": return "ê"; break;
		case "ë": return "ë"; break;
		case "ì": return "ì"; break;
		case "í": return "í"; break;
		case "î": return "î"; break;
		case "ï": return "ï"; break;
		case "ğ": return "ğ"; break;
		case "ñ": return "ñ"; break;
		case "ò": return "ò"; break;
		case "ó": return "ó"; break;
		case "ô": return "ô"; break;
		case "õ": return "õ"; break;
		case "ö": return "ö"; break;
		case "÷": return "÷"; break;
		case "ø": return "ø"; break;
		case "ù": return "ù"; break;
		case "ú": return "ú"; break;
		case "û": return "û"; break;
		case "ü": return "ü"; break;
		case "ı": return "ı"; break;
		case "ş": return "ş"; break;
		case "ÿ": return "ÿ"; break;

		case ".": return "."; break;
	}
	return c;
}
// added by MAXIMUS for typing on Russian <--

// KK -->
string toupperfra(string c)
{
	switch(c)
	{
		case "à": return "À"; break;
		case "â": return "Â"; break;
		case "ç": return "Ç"; break;
		case "è": return "È"; break;
		case "é": return "É"; break;
		case "ë": return "Ë"; break;
		case "ê": return "Ê"; break;
		case "æ": return "Æ"; break;
		case "ï": return "Ï"; break;
		case "î": return "Î"; break;
		case "ô": return "Ô"; break;
		case "ñ": return "Ñ"; break;
		case "œ": return "Œ"; break;
		case "ü": return "Ü"; break;
		case "Å": return "Ã"; break;
		case "ù": return "Ù"; break;
	}
	return touppereng(c);
}

string tolowerfra(string c)
{
	switch(c)
	{
		case "À": return "à"; break;
		case "Â": return "â"; break;
		case "Ç": return "ç"; break;
		case "È": return "è"; break;
		case "È": return "é"; break;
		case "Ë": return "ë"; break;
		case "Ë": return "ê"; break;
		case "Æ": return "æ"; break;
		case "Ï": return "ï"; break;
		case "Î": return "î"; break;
		case "Ô": return "ô"; break;
		case "Ñ": return "ñ"; break;
		case "Œ": return "œ"; break;
		case "Ü": return "ü"; break;
		case "Ã": return "Å"; break;
		case "Ù": return "ù"; break;
	}
	return tolowereng(c);
}

string toupperger(string c)
{
	switch(c)
	{
		case "ä": return "Ä"; break;
		case "ö": return "Ö"; break;
		case "ß": return "ß"; break;
		case "ü": return "Ü"; break;
	}
	return touppereng(c);
}

string tolowerger(string c)
{
	switch(c)
	{
		case "Ä": return "ä"; break;
		case "Ö": return "ö"; break;
		case "ß": return "ß"; break;
		case "Ü": return "ü"; break;
	}
	return tolowereng(c);
}

string toupperspa(string c)
{
	switch(c)
	{
		case "á": return "Á"; break;
		case "é": return "É"; break;
		case "í": return "Í"; break;
		case "ñ": return "Ñ"; break;
		case "ó": return "Ó"; break;
		case "ú": return "Ú"; break;
		case "ü": return "Ü"; break;
	}
	return touppereng(c);
}

string tolowerspa(string c)
{
	switch(c)
	{
		case "Á": return "á"; break;
		case "É": return "é"; break;
		case "Í": return "í"; break;
		case "Ñ": return "ñ"; break;
		case "Ó": return "ó"; break;
		case "Ú": return "ú"; break;
		case "Ü": return "ü"; break;
	}
	return tolowereng(c);
}

string toupperpol(string c)
{
	switch(c)
	{
		case "¹": return "¥"; break;
		case "å": return "ş"; break;
		case "×": return "½"; break;
		case "³": return "£"; break;
		case "ğ": return "ı"; break;
		case "ó": return "Ó"; break;
		case "›": return ""; break;
		case "Ÿ": return ""; break;
		case "": return "¯"; break;
	}
	return touppereng(c);
}

string tolowerpol(string c)
{
	switch(c)
	{
		case "¥": return "¹"; break;
		case "ş": return "å"; break;
		case "½": return "×"; break;
		case "£": return "³"; break;
		case "ı": return "ğ"; break;
		case "Ó": return "ó"; break;
		case "": return "›"; break;
		case "": return "Ÿ"; break;
		case "¯": return ""; break;
	}
	return tolowereng(c);
}

// Returns characteristic letter for language when ALT is pressed together with "c"
string GetDiacriticalChar(string c, string lang)
{
	switch (lang) {
		case "French":
			switch (c) {
				case "a": return "à"; break;
				case "s": return "â"; break;
				case "c": return "ç"; break;
				case "w": return "è"; break;
				case "e": return "é"; break;
				case "d": return "ê"; break;
				case "i": return "ï"; break;
				case "q": return "æ"; break;
				case "r": return "ë"; break;
				case "t": return "œ"; break;
				case "n": return "ñ"; break;
				case "o": return "ô"; break;
				case "h": return "ü"; break;
				case "y": return "Å"; break;
				case "u": return "ù"; break;
			}
		break;
		case "German":
			switch (c) {
				case "a": return "ä"; break;
				case "o": return "ö"; break;
				case "s": return "ß"; break;
				case "u": return "ü"; break;
			}
		break;
		case "Spanish":
			switch (c) {
				case "a": return "á"; break;
				case "e": return "é"; break;
				case "i": return "í"; break;
				case "n": return "ñ"; break;
				case "o": return "ó"; break;
				case "u": return "ú"; break;
				case "y": return "ü"; break;
				case "/": return "¿"; break;
				case "1": return "¡"; break;
			}
		break;
		case "Polish":
			switch (c) {
				case "a": return "¹"; break;
				case "c": return "å"; break;
				case "e": return "×"; break;
				case "l": return "³"; break;
				case "n": return "ğ"; break;
				case "o": return "ó"; break;
				case "s": return "›"; break;
				case "x": return "Ÿ"; break;
				case "z": return ""; break;
			}
		break;
	}
	return c;
}

string ChrFromCode(int code)
{
	switch (code) {
		case 32: return " "; break;
		case 33: return "!"; break;
		case 34: return GlobalStringConvert("DOUBLE_QUOTE"); break;
		case 35: return "#"; break;
		case 36: return "$"; break;
		case 37: return "%"; break;
		case 38: return "&"; break;
		case 39: return "'"; break;
		case 40: return "("; break;
		case 41: return ")"; break;
		case 42: return "*"; break;
		case 43: return "+"; break;
		case 44: return ","; break;
		case 45: return "-"; break;
		case 46: return "."; break;
		case 47: return "/"; break;
		case 48: return "0"; break;
		case 49: return "1"; break;
		case 50: return "2"; break;
		case 51: return "3"; break;
		case 52: return "4"; break;
		case 53: return "5"; break;
		case 54: return "6"; break;
		case 55: return "7"; break;
		case 56: return "8"; break;
		case 57: return "9"; break;
		case 58: return ":"; break;
		case 59: return ";"; break;
		case 60: return "<"; break;
		case 61: return "="; break;
		case 62: return ">"; break;
		case 63: return "?"; break;
		case 64: return "@"; break;
		case 65: return "A"; break;
		case 66: return "B"; break;
		case 67: return "C"; break;
		case 68: return "D"; break;
		case 69: return "E"; break;
		case 70: return "F"; break;
		case 71: return "G"; break;
		case 72: return "H"; break;
		case 73: return "I"; break;
		case 74: return "J"; break;
		case 75: return "K"; break;
		case 76: return "L"; break;
		case 77: return "M"; break;
		case 78: return "N"; break;
		case 79: return "O"; break;
		case 80: return "P"; break;
		case 81: return "Q"; break;
		case 82: return "R"; break;
		case 83: return "S"; break;
		case 84: return "T"; break;
		case 85: return "U"; break;
		case 86: return "V"; break;
		case 87: return "W"; break;
		case 88: return "X"; break;
		case 89: return "Y"; break;
		case 90: return "Z"; break;
		case 91: return "["; break;
		case 92: return "\"; break;
		case 93: return "]"; break;
		case 94: return "^"; break;
		case 95: return "_"; break;
		case 96: return "`"; break;
		case 97: return "a"; break;
		case 98: return "b"; break;
		case 99: return "c"; break;
		case 100: return "d"; break;
		case 101: return "e"; break;
		case 102: return "f"; break;
		case 103: return "g"; break;
		case 104: return "h"; break;
		case 105: return "i"; break;
		case 106: return "j"; break;
		case 107: return "k"; break;
		case 108: return "l"; break;
		case 109: return "m"; break;
		case 110: return "n"; break;
		case 111: return "o"; break;
		case 112: return "p"; break;
		case 113: return "q"; break;
		case 114: return "r"; break;
		case 115: return "s"; break;
		case 116: return "t"; break;
		case 117: return "u"; break;
		case 118: return "v"; break;
		case 119: return "w"; break;
		case 120: return "x"; break;
		case 121: return "y"; break;
		case 122: return "z"; break;
		case 123: return "{"; break;
		case 124: return "|"; break;
		case 125: return "}"; break;
		case 126: return ""; break;
		case 127: return ""; break;
		case 128: return ""; break;
		case 129: return ""; break;
		case 130: return ""; break;
		case 131: return ""; break;
		case 132: return ""; break;
		case 133: return ""; break;
		case 134: return ""; break;
		case 135: return ""; break;
		case 136: return ""; break;
		case 137: return ""; break;
		case 138: return ""; break;
		case 139: return ""; break;
		case 140: return "Œ"; break;
		case 141: return ""; break;
		case 142: return ""; break;
		case 143: return ""; break;
		case 144: return ""; break;
		case 145: return "‘"; break;
		case 146: return "’"; break;
		case 147: return "“"; break;
		case 148: return "”"; break;
		case 149: return ""; break;
		case 150: return "–"; break;
		case 151: return "—"; break;
		case 152: return ""; break;
		case 153: return ""; break;
		case 154: return ""; break;
		case 155: return "›"; break;
		case 156: return "œ"; break;
		case 157: return ""; break;
		case 158: return ""; break;
		case 159: return "Ÿ"; break;
		case 160: return ""; break;
		case 161: return "¡"; break;
		case 162: return ""; break;
		case 163: return "£"; break;
		case 164: return "¤"; break;
		case 165: return "¥"; break;
		case 166: return ""; break;
		case 167: return ""; break;
		case 168: return ""; break;
		case 169: return ""; break;
		case 170: return ""; break;
		case 171: return "«"; break;
		case 172: return ""; break;
		case 173: return "­"; break;
		case 174: return ""; break;
		case 175: return "¯"; break;
		case 176: return ""; break;
		case 177: return ""; break;
		case 178: return ""; break;
		case 179: return "³"; break;
		case 180: return ""; break;
		case 181: return ""; break;
		case 182: return ""; break;
		case 183: return ""; break;
		case 184: return ""; break;
		case 185: return "¹"; break;
		case 186: return ""; break;
		case 187: return "»"; break;
		case 188: return ""; break;
		case 189: return "½"; break;
		case 190: return ""; break;
		case 191: return "¿"; break;
		case 192: return "À"; break;
		case 193: return "Á"; break;
		case 194: return "Â"; break;
		case 195: return "Ã"; break;
		case 196: return "Ä"; break;
		case 197: return "Å"; break;
		case 198: return "Æ"; break;
		case 199: return "Ç"; break;
		case 200: return "È"; break;
		case 201: return "É"; break;
		case 202: return "Ê"; break;
		case 203: return "Ë"; break;
		case 204: return "Ì"; break;
		case 205: return "Í"; break;
		case 206: return "Î"; break;
		case 207: return "Ï"; break;
		case 208: return "Ğ"; break;
		case 209: return "Ñ"; break;
		case 210: return "Ò"; break;
		case 211: return "Ó"; break;
		case 212: return "Ô"; break;
		case 213: return "Õ"; break;
		case 214: return "Ö"; break;
		case 215: return "×"; break;
		case 216: return "Ø"; break;
		case 217: return "Ù"; break;
		case 218: return "Ú"; break;
		case 219: return "Û"; break;
		case 220: return "Ü"; break;
		case 221: return "İ"; break;
		case 222: return "Ş"; break;
		case 223: return "ß"; break;
		case 224: return "à"; break;
		case 225: return "á"; break;
		case 226: return "â"; break;
		case 227: return "ã"; break;
		case 228: return "ä"; break;
		case 229: return "å"; break;
		case 230: return "æ"; break;
		case 231: return "ç"; break;
		case 232: return "è"; break;
		case 233: return "é"; break;
		case 234: return "ê"; break;
		case 235: return "ë"; break;
		case 236: return "ì"; break;
		case 237: return "í"; break;
		case 238: return "î"; break;
		case 239: return "ï"; break;
		case 240: return "ğ"; break;
		case 241: return "ñ"; break;
		case 242: return "ò"; break;
		case 243: return "ó"; break;
		case 244: return "ô"; break;
		case 245: return "õ"; break;
		case 246: return "ö"; break;
		case 247: return "÷"; break;
		case 248: return "ø"; break;
		case 249: return "ù"; break;
		case 250: return "ú"; break;
		case 251: return "û"; break;
		case 252: return "ü"; break;
		case 253: return "ı"; break;
		case 254: return "ş"; break;
	}
	return "";
}

int ascii(string chr)
{
	string ch = GetSymbol(chr, 0);
	if (ch == GlobalStringConvert("DOUBLE_QUOTE")) return 34;
	switch (ch)
	{
		case " ": return 32; break;
		case "!": return 33; break;
		case "#": return 35; break;
		case "$": return 36; break;
		case "%": return 37; break;
		case "&": return 38; break;
		case "'": return 39; break;
		case "(": return 40; break;
		case ")": return 41; break;
		case "*": return 42; break;
		case "+": return 43; break;
		case ",": return 44; break;
		case "-": return 45; break;
		case ".": return 46; break;
		case "/": return 47; break;
		case "0": return 48; break;
		case "1": return 49; break;
		case "2": return 50; break;
		case "3": return 51; break;
		case "4": return 52; break;
		case "5": return 53; break;
		case "6": return 54; break;
		case "7": return 55; break;
		case "8": return 56; break;
		case "9": return 57; break;
		case ":": return 58; break;
		case ";": return 59; break;
		case "<": return 60; break;
		case "=": return 61; break;
		case ">": return 62; break;
		case "?": return 63; break;
		case "@": return 64; break;
		case "A": return 65; break;
		case "B": return 66; break;
		case "C": return 67; break;
		case "D": return 68; break;
		case "E": return 69; break;
		case "F": return 70; break;
		case "G": return 71; break;
		case "H": return 72; break;
		case "I": return 73; break;
		case "J": return 74; break;
		case "K": return 75; break;
		case "L": return 76; break;
		case "M": return 77; break;
		case "N": return 78; break;
		case "O": return 79; break;
		case "P": return 80; break;
		case "Q": return 81; break;
		case "R": return 82; break;
		case "S": return 83; break;
		case "T": return 84; break;
		case "U": return 85; break;
		case "V": return 86; break;
		case "W": return 87; break;
		case "X": return 88; break;
		case "Y": return 89; break;
		case "Z": return 90; break;
		case "[": return 91; break;
		case "\": return 92; break;
		case "]": return 93; break;
		case "^": return 94; break;
		case "_": return 95; break;
		case "`": return 96; break;
		case "a": return 97; break;
		case "b": return 98; break;
		case "c": return 99; break;
		case "d": return 100; break;
		case "e": return 101; break;
		case "f": return 102; break;
		case "g": return 103; break;
		case "h": return 104; break;
		case "i": return 105; break;
		case "j": return 106; break;
		case "k": return 107; break;
		case "l": return 108; break;
		case "m": return 109; break;
		case "n": return 110; break;
		case "o": return 111; break;
		case "p": return 112; break;
		case "q": return 113; break;
		case "r": return 114; break;
		case "s": return 115; break;
		case "t": return 116; break;
		case "u": return 117; break;
		case "v": return 118; break;
		case "w": return 119; break;
		case "x": return 120; break;
		case "y": return 121; break;
		case "z": return 122; break;
		case "{": return 123; break;
		case "|": return 124; break;
		case "}": return 125; break;
		case "Œ": return 140; break;
		case "": return 141; break;
		case "": return 143; break;
		case "‘": return 145; break;
		case "’": return 146; break;
		case "“": return 147; break;
		case "”": return 148; break;
		case "–": return 150; break;
		case "—": return 151; break;
		case "›": return 155; break;
		case "œ": return 156; break;
		case "": return 158; break;
		case "Ÿ": return 159; break;
		case "¡": return 161; break;
		case "£": return 163; break;
		case "¤": return 164; break;
		case "¥": return 165; break;
		case "«": return 171; break;
		case "­": return 173; break;
		case "¯": return 175; break;
		case "³": return 179; break;
		case "¹": return 185; break;
		case "»": return 187; break;
		case "½": return 189; break;
		case "¿": return 191; break;
		case "À": return 192; break;
		case "Á": return 193; break;
		case "Â": return 194; break;
		case "Ã": return 195; break;
		case "Ä": return 196; break;
		case "Å": return 197; break;
		case "Æ": return 198; break;
		case "Ç": return 199; break;
		case "È": return 200; break;
		case "É": return 201; break;
		case "Ê": return 202; break;
		case "Ë": return 203; break;
		case "Ì": return 204; break;
		case "Í": return 205; break;
		case "Î": return 206; break;
		case "Ï": return 207; break;
		case "Ğ": return 208; break;
		case "Ñ": return 209; break;
		case "Ò": return 210; break;
		case "Ó": return 211; break;
		case "Ô": return 212; break;
		case "Õ": return 213; break;
		case "Ö": return 214; break;
		case "×": return 215; break;
		case "Ø": return 216; break;
		case "Ù": return 217; break;
		case "Ú": return 218; break;
		case "Û": return 219; break;
		case "Ü": return 220; break;
		case "İ": return 221; break;
		case "Ş": return 222; break;
		case "ß": return 223; break;
		case "à": return 224; break;
		case "á": return 225; break;
		case "â": return 226; break;
		case "ã": return 227; break;
		case "ä": return 228; break;
		case "å": return 229; break;
		case "æ": return 230; break;
		case "ç": return 231; break;
		case "è": return 232; break;
		case "é": return 233; break;
		case "ê": return 234; break;
		case "ë": return 235; break;
		case "ì": return 236; break;
		case "í": return 237; break;
		case "î": return 238; break;
		case "ï": return 239; break;
		case "ğ": return 240; break;
		case "ñ": return 241; break;
		case "ò": return 242; break;
		case "ó": return 243; break;
		case "ô": return 244; break;
		case "õ": return 245; break;
		case "ö": return 246; break;
		case "÷": return 247; break;
		case "ø": return 248; break;
		case "ù": return 249; break;
		case "ú": return 250; break;
		case "û": return 251; break;
		case "ü": return 252; break;
		case "ı": return 253; break;
		case "ş": return 254; break;
	}
	return 0;
}

string GetCursorSymbol()
{
	if (bKeyboardOverwriteMode) return "€";
	return "ÿ";
}
// <-- KK

string strupper(string s)
{
	int dl = strlen(s);
	string ret = "";
	for (int i = 0; i < dl; i++) {
		ret += toupper(GetSymbol(s, i));
	}
	return ret;
}

string strlower(string s)
{
	int dl = strlen(s);
	string ret = "";
	for (int i = 0; i < dl; i++) {
		ret += tolower(GetSymbol(s, i));
	}
	return ret;
}
// <-- KK

// 05-04-30 fills a string with the names of the attributes passed to it, via commas and and
string FillStringFromAttributes(aref attr)
{
	int i;
	string tmpstr;
	int aqty = GetAttributesNum(attr);
	for(i = 0; i < aqty; i++)
	{
		if(i != 0)
		{
			if(i < aqty - 1) tmpstr += ", ";
			else
			{
				if(aqty > 2) tmpstr += ", and ";
				else tmpstr += " and ";
			}
		}
		tmpstr += GetAttributeName(GetAttributeN(attr, i));
	}
	return tmpstr;
}

// 04-10-24 checks if two numbers have the same sign
bool SameSign(float x, float y)
{
	if(x >= 0)
	{
		if(y >=0) { return true; }
		return false;
	}
	//assume x < 0
	if(y < 0) { return true; }
	return false;
}

bool SameSignPairs(float x, float y, float u, float v)
{
	if(x >= 0)
	{
		if(u < 0) { return false; }
		if(y >= 0)
		{
			if(v < 0) { return false; }
		}
		return true;
	}
	//assume x < 0
	if(u >= 0) { return false; }
	if(y >= 0)
	{
		if(v < 0) { return false; }
	}
	return true;
}

int Sign(float num)
{
	if(num >= 0) return 1;
	else return -1;
}

// 05-03-26 add Min, Max.
float retMin(float x, float y)
{
	x = makefloat(x); y = makefloat(y);
	if(x<y) return x;
	return y;
}

float retMax(float x, float y)
{
	if(x>y) return makefloat(x);
	return makefloat(y);
}

int iretMin(int x, int y)
{
	if(x<y) return x;
	return y;
}

int iretMax(int x, int y)
{
	if(x>y) return x;
	return y;
}


// multiplies by up to +/-pct. 05-05-11
float RandMult(float pct)
{
	return 1.0 - pct + (frnd()*pct*2.0);
}
// NK <--

// dchaley -->

// Moved this from save_load.c
string GetStringTime(float time)
{
	int hour = makeint(time);
	int minute = makeint( (time-makefloat(hour)) * 60.0 + 0.01);
	// LDH fix rounding errors 03Feb09
	if (minute == 60)
	{
		// commented out the message 10Feb09
//		Trace("GetStringTime decided the time was " + stringRet(hour<10,"0","") + hour + ":60 - fixed, but you might want to make sure the time is OK *****");
//		logit("GetStringTime decided the time was " + stringRet(hour<10,"0","") + hour + ":60 - fixed, but you might want to make sure the time is OK *****");
		minute = 0;
		hour += 1;
		if (hour > 24) hour = 0;
	}
	string retVal;
	if(hour<10) retVal = "0"+hour;
	else retVal = hour;
	retVal += ":";
	if(minute<10) retVal += "0"+minute;
	else retVal += minute;
	return retVal;
}

string GetStringDate(int year,int month,int day)
{
	string retVal;
	// boal -->
    if (day < 10)
    {
        retVal = "0"+day;
    }
    else
    {
        retVal = day;
    }
    if (month < 10)
    {
        retVal = retVal + "-0" + month + "-" + year;
    }
    else
    {
        retVal = retVal + "-" + month + "-" + year;
    }
    // boal <--
	return retVal;
}

// dchaley <--

// KK -->
string GetHumanDate(int year, int month, int day)
{
	string sufix = "th";
	if (day == 1 || day == 21 || day == 31) sufix = "st";
	if (day == 2 || day == 22) sufix = "nd";
	if (day == 3 || day == 23) sufix = "rd";
	return XI_ConvertString("g_month_" + month) + " " + day + XI_ConvertString(sufix) + ", " + year; // PB: Formatting changed to appear more historically appropriate
}
// <-- KK

// LDH --> 07Sep06
// Natural logarithm
// Useful for normally distributed random numbers among other calcs
float logN(float num)
{
	float e = 2.71828;			// limit of accuracy to keep calcs reasonable
	if (num <= 0) return 0.0;	// can't do logs of negative numbers or zero
	float exp = 0.0;
	while (num > 1.6)	// optimize a bit, probably 1.6 is best here.  Near 2.5 it crashes.
	{
		num = num / e;
		exp = exp + 1.0;
	}
	while (num < 0.2)
	{
		num = num * e;
		exp = exp - 1.0;
	}
	float x = num - 1.0;
	float y = x;
	int i;
	float n = 2.0;
	float z;
	for ( i=1 ; i<100 ; i++ )		// arbitrarily high limit just for safety, normally never goes over 28
	{
		z = y;
		y = y - pow(x,n)/n;
		n = n + 1.0;
		y = y + pow(x,n)/n;
		n = n + 1.0;
		if (z == y) break;
	}
	return y + exp;
}

float log10(float num)
{
	return logN(num) / 2.302585093;	// for log base 10, divide by logN(10)
}

//  Return a normally distributed random number with specified mean and standard deviation
//  68% of samples will be within 1 stdev of mean, 95% within 2 stdev's, 99% within 3 stdev's.
//  100% should be within 4.56 stdev's due to frnd() and accuracy of math in this system
//  This is the standard "bell curve"
float randnorm2 = 9999.0;
float randnorm(float mean, float stdev)
{
    float  r, u;
    float  randnorm1;

	if (randnorm2 != 9999.0)
	{
		float rc = randnorm2 * stdev + mean;
		randnorm2 = 9999.0;
		return rc;
	}

	r = sqrt(-2.0 * logN(frnd()));	// .000030519 is lowest frnd() (besides zero, 1.2 occurences in 30,000), 4.5601 is largest r
	u = frnd();
	randnorm1 = r * sin(PIm2 * u);
	randnorm2 = r * cos(PIm2 * u);

	return ( randnorm1 * stdev + mean );
}
/*  some test runs with randnorm(100,20) run 30000 times (takes 3 seconds)
Low = 27.533, high = 191.20, average = 99.581, s1 = 67.94,  s2 = 94.76,  s3 = 99.54  <-- highest possible number
Low = 31.661, high = 182.22, average = 99.957, s1 = 68.16,  s2 = 95.40,  s3 = 99.74
Low = 33.555, high = 170.57, average = 100.26, s1 = 67.86,  s2 = 95.72,  s3 = 99.70
Low = 28.825, high = 173.36, average = 99.642, s1 = 68.14,  s2 = 95.34,  s3 = 99.72
Low = 36.479, high = 168.16, average = 100.13, s1 = 68.00,  s2 = 95.44,  s3 = 99.84
Low = 19.649, high = 184.28, average = 99.98,  s1 = 67.803, s2 = 95.42,  s3 = 99.68
Low = 11.931, high = 175.91, average = 99.921, s1 = 67.827, s2 = 95.383, s3 = 99.697
Low = 8.8004, high = 182.91, average = 100.09, s1 = 68.477, s2 = 95.34,  s3 = 99.787 <-- lowest possible number
Low = 22.55,  high = 184.76, average = 99.967, s1 = 68.327, s2 = 95.3,   s3 = 99.657
*/

// integer absolute value
int iabs(int num)
{
	if (num < 0)
		return -num;
	else
		return num;
}

// LDH <--


// KK -->
object PreprocessorData;

bool Preprocessor_Add(string label, string text)
{
	ref pd; makeref(pd, PreprocessorData);
	if (!CheckAttribute(pd, "data")) pd.data = "";
	if (CheckAttribute(pd, "data." + label + ".save") == true && sti(pd.data.(label).save) == true) return false;
	pd.data.(label) = text;
	return true;
}

void Preprocessor_Save(string label, string text)
{
	if (Preprocessor_Add(label, text)) {
		ref pd; makeref(pd, PreprocessorData);
		pd.data.(label).save = true;
	}
}

bool Preprocessor_AddQuestData(string label, string text)
{
	ref pd; makeref(pd, PreprocessorData);
	if (!CheckAttribute(pd, "data")) pd.data = "";
	if (!CheckAttribute(pd, "QuestData")) pd.QuestData = "";
	if (CheckAttribute(pd, "data." + label + ".save") == true && sti(pd.data.(label).save) == true) return false;
	pd.data.(label) = text;
	pd.QuestData.(label) = text;
	return true;
}

string Preprocessor_Get(string label)
{
	ref pd; makeref(pd, PreprocessorData);
	if (!CheckAttribute(pd, "data")) return label;
	if (CheckAttribute(pd, "data." + label)) return pd.data.(label);
	return label;
}

void Preprocessor_Remove(string label)
{
	ref pd; makeref(pd, PreprocessorData);
	if (CheckAttribute(pd, "data." + label)) {
		if (CheckAttribute(pd, "data." + label + ".save") == true && sti(pd.data.(label).save) == true) return;
		DeleteAttribute(pd, "data." + label);
	}
}

void Preprocessor_Delete(string label)
{
	ref pd; makeref(pd, PreprocessorData);
	if (CheckAttribute(pd, "data." + label)) DeleteAttribute(pd, "data." + label);
}

void Preprocessor_Clear(bool all)
{
	ref pd; makeref(pd, PreprocessorData);
	if (all) {
		DeleteAttribute(pd, "");
		pd.data = "";
		pd.QuestData = "";
		return;
	}
	DeleteAttribute(pd, "QuestData");
	aref pdat; makearef(pdat, pd.data);
	int num = GetAttributesNum(pdat) - 1;
	for (int i = num; i >= 0; i--) {
		string label = GetAttributeName(GetAttributeN(pdat, i));
		if (CheckAttribute(pdat, label + ".save") == true && sti(pdat.(label).save) == true) continue;
		DeleteAttribute(pdat, label);
	}
	pd.QuestData = "";
}

void Preprocessor_Init()
{
	Preprocessor_Clear(true);
	Preprocessor_Save("_hash_", "#");
	Preprocessor_Save("Falaise de Fleur", FindTownName("Falaise de Fleur"));
	Preprocessor_Save("Redmond", FindTownName("Redmond"));
	Preprocessor_Save("Isla Muelle", FindTownName("Isla Muelle"));
	Preprocessor_Save("Oxbay", FindTownName("Oxbay"));
	Preprocessor_Save("Greenford", FindTownName("Greenford"));
	Preprocessor_Save("Conceicao", FindTownName("Conceicao"));
	Preprocessor_Save("Douwesen", FindTownName("Douwesen"));
	Preprocessor_Save("Quebradas Costillas", FindTownName("Quebradas Costillas"));
	Preprocessor_Save("Santo Domingo", FindTownName("Santo Domingo"));
	Preprocessor_Save("Port au Prince", FindTownName("Port au Prince"));
	Preprocessor_Save("Tortuga", FindTownName("Tortuga"));
	Preprocessor_Save("Havana", FindTownName("Havana"));
	Preprocessor_Save("Santiago", FindTownName("Santiago"));
	Preprocessor_Save("Marigot", FindTownName("Marigot"));
	Preprocessor_Save("Philipsburg", FindTownName("Philipsburg"));
	Preprocessor_Save("Eleuthera", FindTownName("Eleuthera"));
	Preprocessor_Save("Alice", FindTownName("Alice"));
	Preprocessor_Save("Grand Cayman", FindTownName("Grand Cayman"));
	Preprocessor_Save("Grand Turk", FindTownName("Grand Turk"));
	Preprocessor_Save("Oranjestad", FindTownName("Oranjestad"));
	Preprocessor_Save("Willemstad", FindTownName("Willemstad"));
	Preprocessor_Save("Pointe a Pitre", FindTownName("Pointe a Pitre"));
	Preprocessor_Save("St John's", FindTownName("St John's"));
	Preprocessor_Save("Charlestown", FindTownName("Charlestown"));
	Preprocessor_Save("Cartagena", FindTownName("Cartagena"));
	Preprocessor_Save("island_Falaise de Fleur", FindIslandName("Falaise de Fleur"));
	Preprocessor_Save("island_Redmond", FindIslandName("Redmond"));
	Preprocessor_Save("island_Isla Muelle", FindIslandName("Isla Muelle"));
	Preprocessor_Save("island_Oxbay", FindIslandName("Oxbay"));
	Preprocessor_Save("island_Conceicao", FindIslandName("Conceicao"));
	Preprocessor_Save("island_Douwesen", FindIslandName("Douwesen"));
	Preprocessor_Save("island_Quebradas Costillas", FindIslandName("Quebradas Costillas"));
	Preprocessor_Save("island_Khael Roa", FindIslandName("Khael Roa"));
	Preprocessor_Save("island_Hispaniola", FindIslandName("Hispaniola"));
	Preprocessor_Save("island_Cuba", FindIslandName("Cuba"));
	Preprocessor_Save("island_Saint Martin", FindIslandName("Saint Martin"));
	Preprocessor_Save("island_Eleuthera", FindIslandName("Eleuthera"));
	Preprocessor_Save("island_Cayman", FindIslandName("Cayman"));
	Preprocessor_Save("island_Turks", FindIslandName("Turks"));
	Preprocessor_Save("island_Aruba", FindIslandName("Aruba"));
	Preprocessor_Save("island_Curacao", FindIslandName("Curacao"));
	Preprocessor_Save("island_Guadeloupe", FindIslandName("Guadeloupe"));
	Preprocessor_Save("island_Antigua", FindIslandName("Antigua"));
	Preprocessor_Save("island_Battle Rocks", FindIslandName("Battle_Rocks"));
	Preprocessor_Save("island_Isla Mona", FindIslandName("IslaMona"));
	Preprocessor_Save("island_Isla De Muerte", FindIslandName("Isla De Muerte"));
	Preprocessor_Save("island_Colombia", FindIslandName("Colombia"));
	Preprocessor_Save("cursed_ship", "Black Pearl");		// PB: For Jack Sparrow storyline
	Preprocessor_Save("uncursed_ship", "Crimson Blood");	// PB: For Jack Sparrow storyline
	if (GetCharacterIndex("Father Bernard") >= 0) // PB: Not initialized yet the first time this function is called
	{
		Preprocessor_Save("FatherBernard",	GetMySimpleName(CharacterFromID("Father Bernard")));  // GR: For "Church Help"
		Preprocessor_Save("FatherJerald",	GetMySimpleName(CharacterFromID("Father Jerald")));  // and "Animists"
		Preprocessor_Save("FatherGareth",	GetMySimpleName(CharacterFromID("Father Gareth")));  // side quests.
	}
}

string PreprocessText(string text)
{
	ref pd; makeref(pd, PreprocessorData);
	aref pdat; makearef(pdat, pd.data);
	return GetAssembledString(text, pdat);
}

object Storylines;

extern void RegisterStoryline(int i);

void InitStorylines()
{
	aref flist = GetFiles("PROGRAM\Storyline", "*.c");
	int num = GetAttributesNum(flist);

	ref sl; makeref(sl, Storylines);
	DeleteAttribute(sl, "");
	sl.list = "";

	string sfile;
	string send;
	int n = 0;
	for (int i = 0; i < num; i++) {
		sfile = GetAttributeValue(GetAttributeN(flist, i));
		// PB: Disable certain storylines -->
		send  = strcut(sfile, strlen(sfile) - 6, strlen(sfile) - 3);
		if (send == "_off")		continue;
		else					n++;
		// PB: Disable certain storylines <--

		if (LoadSegment("Storyline\" + sfile)) {
			RegisterStoryline(n); // PB: was i
			UnloadSegment("Storyline\" + sfile);
		}
	}
}

void DeleteStoryline(int idx)
{
	if (idx < 0 || idx > GetStorylinesQuantity() - 1) return;
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	int num = GetAttributesNum(sl);
	int i = 0;
	aref arsl;
	for (i = 0; i < num; i++) {
		arsl = GetAttributeN(sl, i);
		if (!CheckAttribute(arsl, "index")) continue;
		if (sti(arsl.index) == idx) {
			DeleteAttribute(sl, GetAttributeName(arsl));
			break;
		}
	}
	num = GetAttributesNum(sl);
	for (i = 0; i < num; i++) {
		arsl = GetAttributeN(sl, i);
		if (!CheckAttribute(arsl, "index")) continue;
		if (sti(arsl.index) > idx) {
			arsl.index = sti(arsl.index) - 1;
		}
	}
}

string GetStoryline(int idx)
{
	if (idx < 0 || idx > GetStorylinesQuantity() - 1) return GetStoryline(FindDefaultStoryline());
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	int num = GetAttributesNum(sl);
	for (int i = 0; i < num; i++) {
		aref arsl = GetAttributeN(sl, i);
		if (!CheckAttribute(arsl, "index")) continue;
		if (sti(arsl.index) == idx) {
			if (CheckAttribute(arsl, "id"))
				return arsl.id;
			else
				break;
		}
	}
	return GetStoryline(FindDefaultStoryline());
}

int FindStoryline(string name)
{
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	int num = GetAttributesNum(sl);
	for (int i = 0; i < num; i++) {
		aref arsl = GetAttributeN(sl, i);
		if (!CheckAttribute(arsl, "id")) continue;
		if (arsl.id == name) return sti(arsl.index);
	}
	return -1;
}

int GetStorylinesQuantity()
{
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	return GetAttributesNum(sl);
}

int FindDefaultStoryline()
{
	ref sl; makeref(sl, Storylines);
	if (!CheckAttribute(sl, "default")) return -1;
	return sti(sl.default);
}

void SetCurrentStoryline(int idx)
{
	ref sl; makeref(sl, Storylines);
	ref rGlobal; makeref(rGlobal, GlobalSettings);
	sl.current = idx;
	rGlobal.Storyline = idx;
}

int FindCurrentStoryline()
{
	ref sl; makeref(sl, Storylines);
	if (!CheckAttribute(sl, "current")) return FindDefaultStoryline();
	return sti(sl.current);
}

string GetStorylineDir(int idx)
{
	if (idx < 0 || idx > GetStorylinesQuantity() - 1) return GetStorylineDir(FindDefaultStoryline());
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	int num = GetAttributesNum(sl);
	for (int i = 0; i < num; i++) {
		aref arsl = GetAttributeN(sl, i);
		if (!CheckAttribute(arsl, "index")) continue;
		if (sti(arsl.index) == idx) {
			if (CheckAttribute(arsl, "dir")) {
				if (getsymbol(arsl.dir, strlen(arsl.dir) - 1) != "\") arsl.dir = arsl.dir + "\";
				return arsl.dir;
			} else {
				break;
			}
		}
	}
	return GetStorylineDir(FindDefaultStoryline());
}

string GetStorylinePath(int idx)
{
	return "storyline\" + GetStorylineDir(idx);
}

string GetStorylineTitle(int idx)
{
	if (idx < 0 || idx > GetStorylinesQuantity() - 1) return GetStorylineTitle(FindDefaultStoryline());
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	int num = GetAttributesNum(sl);
	for (int i = 0; i < num; i++) {
		aref arsl = GetAttributeN(sl, i);
		if (!CheckAttribute(arsl, "index")) continue;
		if (sti(arsl.index) == idx) {
			if (CheckAttribute(arsl, "title"))
				return arsl.title;
			else
				break;
		}
	}
	return GetStorylineTitle(FindDefaultStoryline());
}

string GetStorylineDescription(int idx)
{
	if (idx < 0 || idx > GetStorylinesQuantity() - 1) return GetStorylineDescription(FindDefaultStoryline());
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	int num = GetAttributesNum(sl);
	for (int i = 0; i < num; i++) {
		aref arsl = GetAttributeN(sl, i);
		if (!CheckAttribute(arsl, "index")) continue;
		if (sti(arsl.index) == idx) {
			if (CheckAttribute(arsl, "description"))
				return arsl.description;
			else
				break;
		}
	}
	return GetStorylineDescription(FindDefaultStoryline());
}

aref GetStorylineStartParams(int idx)
{
	if (idx < 0 || idx > GetStorylinesQuantity() - 1) return GetStorylineStartParams(FindDefaultStoryline());
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	int num = GetAttributesNum(sl);
	for (int i = 0; i < num; i++) {
		aref arsl = GetAttributeN(sl, i);
		if (!CheckAttribute(arsl, "index")) continue;
		if (sti(arsl.index) == idx) {
			if (CheckAttribute(arsl, "start")) {
				aref arst; makearef(arst, arsl.start);
				return arst;
			} else {
				break;
			}
		}
	}
	return GetStorylineStartParams(FindDefaultStoryline());
}

void CleanStorylineObject()
{
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	int num = GetAttributesNum(sl);
	for (int i = 0; i < num; i++) {
		aref arsl = GetAttributeN(sl, i);
		if (!CheckAttribute(arsl, "index")) continue;
		DeleteAttribute(arsl, "start");
		DeleteAttribute(arsl, "description");
	}
}

void CheckStorylines()
{
	int i = 0;
	while (i < GetStorylinesQuantity()) {
		string sdir = GetStorylinePath(i);
		bool bok = true;
		bok = FindFile("PROGRAM\" + sdir, "*.c", "StartStoryline.c") != "";
		bok = bok == true && FindFile("PROGRAM\" + sdir + "\quests", "*.c", "both_reaction.c") != "";
		bok = bok == true && FindFile("PROGRAM\" + sdir + "\quests", "*.c", "quests_reaction.c") != "";
		if (!bok) {
			DeleteStoryline(i);
			continue;
		}
		i++;
	}
}

void RefreshStorylines()
{
	object t_sl;
	ref tsl; makeref(tsl, t_sl);
	ref storyline; makeref(storyline, Storylines);
	aref sl; makearef(sl, storyline.list);
	CopyAttributes(tsl, sl);
	DeleteAttribute(sl, "");
	int num = GetAttributesNum(tsl);
	for (int i = 0; i < num; i++) {
		aref arsl = GetAttributeN(tsl, i);
		string sfile = "Storyline\" + arsl.dir;
		sfile = strcut(sfile, 0, strlen(sfile) - 2) + ".c";

		if (LoadSegment(sfile)) {
			RegisterStoryline(i);
			UnloadSegment(sfile);
		}
	}
}

void AddStorylineVar(int n, string name, string value)
{
	ref storyline; makeref(storyline, Storylines);
	string sn = "sl" + (n + 1);
	aref sl; makearef(sl, storyline.list.(sn));
	sl.data.(name) = value;
}

void DelStorylineVar(int n, string name)
{
	ref storyline; makeref(storyline, Storylines);
	string sn = "sl" + (n + 1);
	if (!CheckAttribute(storyline, "list." + sn + ".data")) return;
	aref sd; makearef(sd, storyline.list.(sn).data);
	if (CheckAttribute(sd, name)) DeleteAttribute(sd, name);
}

string GetStorylineVar(int n, string name)
{
	ref storyline; makeref(storyline, Storylines);
	string sn = "sl" + (n + 1);
	if (!CheckAttribute(storyline, "list." + sn + ".data")) return "";
	aref sd; makearef(sd, storyline.list.(sn).data);
	if (!CheckAttribute(sd, name)) return "";
	return sd.(name);
}

string GetInterfaceLanguageName(int lnginterface)
{
	string slname = "English";
	switch (lnginterface) {
		case ILANG_RUS:
			slname = "Russian";
		break;
		case ILANG_FRA:
			slname = "French";
		break;
		case ILANG_GER:
			slname = "German";
		break;
		case ILANG_SPA:
			slname = "Spanish";
		break;
		case ILANG_POL:
			slname = "Polish";
		break;
	}
	return slname;
}

int GetCurrentModelrNumber()
{
	int n = 0;
	aref arModel;
	if (FindClass(&arModel, "modelr")) {
		n++;
		while (FindClassNext(&arModel)) 
		{
			n++;
		}
	}
	return n;
}

object SaveProfiles;

void InitProfiles()
{
	int SLinesNum = GetStorylinesQuantity();
	string storyline;
	ref rSP; makeref(rSP, SaveProfiles);
	for (int i = 0; i < SLinesNum; i++) {
		storyline = GetStoryline(i);
		GameInterface.SavePath = "SAVE\" + GetStorylineDir(i);
		string saveName = "";
		int fSize = 0;
		int j = 0;
		while (SendMessage(&GameInterface, "llee", MSG_INTERFACE_SAVE_FILE_FIND, j, &saveName, &fSize) != 0) {
			if (HasSubStr(saveName, "_options")) {
				j++;
				continue;
			}
			string profile = "";
			if (strcut(saveName, 0, 1) == "-=") {
				int epos = findSubStr(saveName, "=", 3);
				if (epos >= 0) profile = strcut(saveName, 2, epos - 1);
			}
			if (profile != "") {
				int pnum = FindProfile(storyline, profile);
				string p;
				if (pnum < 0) {
					CreateProfile(storyline, profile);
					pnum = 1;
				}
			}
			j++;
		}
	}
}

int FindProfile(string storyline, string id)
{
	if (FindStoryline(storyline) < 0) return -1;
	ref rSP; makeref(rSP, SaveProfiles);
	if (CheckAttribute(rSP, storyline)) {
		aref arPStoryline; makearef(arPStoryline, rSP.(storyline));
		int iNum = GetAttributesNum(arPStoryline);
		for (int i = 0; i < iNum; i++) {
			aref arProfile = GetAttributeN(arPStoryline, i);
			if (CheckAttribute(arProfile, "id") == true && arProfile.id == id) {
				string attrName = GetAttributeName(arProfile);
				//return sti(strcut(attrName, 1, strlen(attrName) - 1)); // Screwface : Something is wrong with that when you create many profiles in same storyline
				return 1;
			}
		}
	}
	return -1;
}

string GetProfileName(string storyline, int idx)
{
	if (FindStoryline(storyline) < 0) return "";
	if (idx < 1) return "";
	ref rSP; makeref(rSP, SaveProfiles);
	if (CheckAttribute(rSP, storyline)) {
		aref arPStoryline; makearef(arPStoryline, rSP.(storyline));
		int iNum = GetAttributesNum(arPStoryline);
		if (iNum < idx) return "";
		string p = "p" + idx;
		if (CheckAttribute(arPStoryline, p + ".id")) return arPStoryline.(p).id;
	}
	return "";
}

int GetProfilesQuantity(string storyline)
{
	if (FindStoryline(storyline) < 0) return 0;
	ref rSP; makeref(rSP, SaveProfiles);
	if (CheckAttribute(rSP, storyline)) {
		aref arPStoryline; makearef(arPStoryline, rSP.(storyline));
		return GetAttributesNum(arPStoryline);
	}
	return 0;
}

int GetProfileSavesQuantity(string storyline, string profile)
{
	int slidx = FindStoryline(storyline);
	if (slidx < 0) return 0;
	int pnum = FindProfile(storyline, profile);
	if (pnum < 0) return 0;
	aref arSaveFiles = GetFiles("SAVE\" + GetStorylineDir(slidx), "-=" + profile + "=-*");
	return GetAttributesNum(arSaveFiles);
}

int GetAnyProfileSavesQuantity(string storyline)
{
	int slidx = FindStoryline(storyline);
	if (slidx < 0) return 0;
	aref arSaveFiles = GetFiles("SAVE\" + GetStorylineDir(slidx), "-=*=-*");
	return GetAttributesNum(arSaveFiles);
}

bool SetCurrentProfile(string storyline, string profile)
{
	if (FindStoryline(storyline) < 0) return false;
	int pnum = FindProfile(storyline, profile);
	if (pnum < 0 && profile != "") return false;
	GlobalSettings.profile.(storyline) = profile;
	GlobalSettings.profile.(storyline).len = strlen(profile); // Screwface
	return true;
}

string GetCurrentProfile(string storyline)
{
	if (FindStoryline(storyline) < 0) return "";
	if (!CheckAttribute(GlobalSettings, "profile." + storyline)) GlobalSettings.profile.(storyline) = "";
	return GlobalSettings.profile.(storyline);
}

bool CreateProfile(string storyline, string profile)
{
	if (FindStoryline(storyline) < 0) return false;
	//int pnum = FindProfile(storyline, profile);
	//if (pnum > 0) return false;
	DeleteProfile(storyline, profile); // Screwface : question is asked previously so we must delete here
	ref rSP; makeref(rSP, SaveProfiles);
	int pq = GetProfilesQuantity(storyline) + 1;
	string p = "p" + pq;
	rSP.(storyline).(p).id = profile;
	return true;
}

bool DeleteProfile(string storyline, string profile)
{
	int slidx = FindStoryline(storyline);
	if (slidx < 0) return false;
	int pnum = FindProfile(storyline, profile);
	if (pnum < 0) return false;
	GameInterface.SavePath = "SAVE\" + GetStorylineDir(slidx);
	string saveName;
	int fSize;
	int i = 0;
	while (SendMessage(&GameInterface, "llee", MSG_INTERFACE_SAVE_FILE_FIND, i, &saveName, &fSize) != 0) {
		if (hasSubStr(saveName, "-=" + profile + "=-")) {
			SendMessage(&GameInterface, "ls", MSG_INTERFACE_DELETE_SAVE_FILE, saveName);
			continue;
		}
		i++;
	}
	saveName = profile + "_options";
	if (FindFile(GameInterface.SavePath, "*", saveName) != "") SendMessage(&GameInterface, "ls", MSG_INTERFACE_DELETE_SAVE_FILE, saveName);
	ref rSP; makeref(rSP, SaveProfiles);
	string p = "p" + pnum;
	DeleteAttribute(rSP, storyline + "." + p);
	return true;
}
// <-- KK

// LDH no scientific notation 06Apr09
// Float to string 2
string f2s2(float num)
{
	object temp;
	temp.data = num;
	return temp.data;
}
