/////////////////////////
// GOF 1.2
/////////////////////////

int Whr_GetColor(aref arRef, string sAttribute)
{
	return sti(arRef.(sAttribute));
}

float Whr_GetFloat(aref arRef, string sAttribute)
{
	string sTmpAttr = sAttribute + ".max";
	if (CheckAttribute(arRef,sTmpAttr))
	{
		float fMin = stf(arRef.(sAttribute).min);
		float fMax = stf(arRef.(sAttribute).max);
		return fMin + frnd() * (fMax - fMin);
	}

	if (!CheckAttribute(&arRef, sAttribute)) return 0.0;

	return stf(arRef.(sAttribute));
}

float Whr_GetCustWSpeedFloat(aref arRef, string sAttribute)
{
	//Jonathan A 19/5/2011
	//With the change of minimum wind speed to 0, the wind was on average a few points slower.  This function still returns 0 speed sometimes, but more often it gives something slightly above the average of max-min.

	//this is a custom, and completly opaque formula I made up to get a sort of skewed bellcurve for the wind speed.
	//it should give a distorted bell curve like speed distribution, with rarely minimum speed, rarely max speed, and most likely a little more than average speed.


	string sTmpAttr = sAttribute + ".max";
	if (CheckAttribute(arRef,sTmpAttr))
	{
//		trace("Custom Wind Speed");

		//we have a max (and min) speed, so calc a new speed in range:
		float fMin = stf(arRef.(sAttribute).min);
		float fMax = stf(arRef.(sAttribute).max);

		float fTuningParam1 = 0.6; //setting this to 1 gives a flat speed distribution (all speeds equally liekly), and 0 to get a bellcurve like distribution (with very small change of high or low speeds)
		float fTuningParam2 = 3;  //param 2 and 3 determine how skewed towards high speed the distribution is.  If you must mess with them, param2 + squareRoot(param3) MUST = 10, or you'll get silly wind speeds
		float fTuningParam3 = 49;  // p2=9 and p3=1 gives a flat speed curve, p2=1 and p3=81 gives a lots of high speeds. my choice is p2=3, p3=49, which gives a medium bonus chance for descent speeds.

		float fNewSpeed;
		if (frnd() < fTuningParam1) {
			//use flat distribution
			fNewSpeed = fMin + (frnd() * fMax - fMin) ;
		} else {
			//otherwise use steep bellcurve
			fNewSpeed = fMin + (frnd()*fTuningParam2 + sqrt(frnd()*fTuningParam3))/10 * (fMax - fMin);
		}
		trace("fmax=" + fMax + ", fMin = " + fMin + ", new speed = " + fNewSpeed);

		return fNewSpeed ;
	}

	//No max/min range, so return existing value if available, or 0
	if (!CheckAttribute(&arRef, sAttribute)) return 0.0;

	return stf(arRef.(sAttribute));
}

int Whr_GetLong(aref arRef, string sAttribute)
{
	string sTmpAttr = sAttribute + ".max";
	if (CheckAttribute(arRef,sTmpAttr))
	{
		int iMin = sti(arRef.(sAttribute).min);
		int iMax = sti(arRef.(sAttribute).max);
		return iMin + rand(iMax - iMin - 1);
	}
	return sti(arRef.(sAttribute));
}

string Whr_GetString(aref arRef, string sAttribute)
{
	return arRef.(sAttribute);
}


void eChangeDayNight()
{
	/*if(Whr_IsDay() == true)
	{
		ShowCitizens(false, FindLocation(pchar.location));
	}

	if(Whr_IsNight() == true)
	{
		HideCitizens();
	}
	RecalculateJumpTable();*/
}

//navy -->
float GetSunHeightAngle(int _hour)
{
	if (_hour > 5 && _hour < 13)
	{
		return Degree2Radian(0.0 + 12.0*(_hour-6));
	}
	if (_hour > 12 && _hour < 19)
	{
		return Degree2Radian(72.0 - 12.0*(_hour-12));
	}
	return -1;
}
//navy <--
