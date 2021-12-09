
void Whr_DebugInfo(){
	// JL ----------------------------------------------------------
	Traceandlog("Fog: " + fog + " Fog Roll: " + rFog );
	Traceandlog("wRain: " + wRain + " wRain roll: " + rRain);
	Traceandlog("Wind Angle: "+ fWindA + " rWindA: " + rWindA);
	Traceandlog("winds: " + winds + " minwind: " + minwind +" maxwind: " + maxwind + " rWind: " + rWind);
	Traceandlog("Whr: Select lighting = " + WeathersNH.Lighting);
	Traceandlog("Fog Density: " + WeathersNH.Fog.Density);
	Traceandlog("Number of raindrops: " + WeathersNH.Rain.NumDrops );
	Traceandlog("Storm: " + WeathersNH.Storm );
	Traceandlog("windABallast: " + windABallast + " windBallast: " + windBallast + " rainBallast: " + rainBallast + " fogBallast: " + fogBallast);
	//JL --------------------------------------------------------
}


