#include "Weather\Init\Common.c"

int InitWeather()
{
	int n = 0;

	Whr_InitCommon();

	Trace("Init weathers complete. " + n + " weathers found.");

	return n;
}
