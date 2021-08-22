// tools for writing locators
// NK/Inez 05-07-14

void DoLocWrite(float magForward, float magUp, int numdigits, bool placebody)
{
	ref pchar = GetMainCharacter();
	if(CheckAttribute(pchar, "lwmagup"))
	{
	    magUp = stf(pchar.lwmagup);
	    Logit("LOCWRITE: Up magnitude is now " + floattostring(magup, 2));
	}
		
	if(FindLoadedLocation() == -1) return; //if not in loc mode, return
	float x, y, z, ay, xx, xz, zx, zz;
	GetCharacterPos(pchar, &x, &y, &z); // get pos
	GetCharacterAy(pchar, &ay); // get angle
	if(!CheckAttribute(pchar, "locwrite"))
	{
		Logit("Locator coordinate writing (LOCWRITE). This assumes the bed will have the head to your right.");
		Logit("If this is the case, press F12 again now. If this is not the case--the head is to your left--turn around first and then press F12 again.");
		Logit("If you don't want to write this position as the locators, move somewhere else before hitting F12 and it will clear.");
		pchar.locwrite = true;
		pchar.locwrite.x = x;
		pchar.locwrite.z = z;
		pchar.locwrite.ay = ay;
		return;
	}
	else
	{
		DeleteAttribute(&pchar, "lwmagup");
		float lx, lz, lay, firstay, seconday, side;
		lx = stf(pchar.locwrite.x);
		lz = stf(pchar.locwrite.z);
		lay = stf(pchar.locwrite.ay);
		DeleteAttribute(&pchar, "locwrite");
		
		bool bx, bz, ba;
		bx = false; bz = false; ba = false;
		/*if(lx * 0.999 <= x && lx * 1.001 >= x) bx = true;
		if(lz * 0.999 <= z && lz * 1.001 >= z) bz = true;*/
		if(lx == x) bx = true;
		if(lz == z) bz = true;
		if(clampangle(lay) * 0.999 <= clampangle(ay) && clampangle(lay) * 1.001 >= clampangle(ay)) ba = true;
//		if(bx && bz)
//		{
		    //Inez: corrected angle
			//if(ba) { seconday = lay + PId2}
			//else { seconday = lay - PId2;}
			if(ba) { seconday = lay + PI}
			else { seconday = lay;}
//		}
//		else
//		{
//			logit("LOCWRITE: Positions not the same, clearing...");
			//trace("old pchar pos: " + lx + ", "+ lz +"; new pos " + x + ", " + z);
//			return;
//		}
		ref loc = &Locations[FindLoadedLocation()];
		string locname = "locatormodel: Resource\\models\\" + loc.filespath.models + "\\" + loc.models.always.locators + ".gm";
		// angle components
		
		//Inez: corrected angle
		//xx = sin(lay+PI);
		xx = sin(lay-PId2);  
		
		zz = xx;
		
		//Inez: corrected angle
		//xz = cos(lay+PI);
		xz = cos(lay-PId2); 
		
		zx = -1.0 * xz;
		
//		trace(locname);
//		trace("goto,upfrombed,"+floattostring(xx, numdigits)+",0,"+floattostring(xz, numdigits)+",0,1,0,"+floattostring(zx, numdigits)+",0,"+floattostring(zz, numdigits)+","+floattostring(x, numdigits)+","+floattostring(y, numdigits)+","+floattostring(z, numdigits)+",1,0,0,0,0,0,0,0,0,");

		// change for bed
		z += cos(lay) * magForward;
		x += sin(lay) * magForward;
		y += magUp;

		xx = sin(seconday);
		zz = xx;
		xz = cos(seconday);
		zx = -1.0 * xz;

		trace("reload,reload,"+floattostring(xx, numdigits)+",0,"+floattostring(xz, numdigits)+",0,1,0,"+floattostring(zx, numdigits)+",0,"+floattostring(zz, numdigits)+","+floattostring(x, numdigits)+","+floattostring(y, numdigits)+","+floattostring(z, numdigits)+",1,0,0,0,0,0,0,0,0,");
//		trace("rld,loc,"+floattostring(xx, numdigits)+",0,"+floattostring(xz, numdigits)+",0,1,0,"+floattostring(zx, numdigits)+",0,"+floattostring(zz, numdigits)+","+floattostring(x, numdigits)+","+floattostring(y, numdigits)+","+floattostring(z, numdigits)+",1,0,0,0,0,0,0,0,0,");
//		trace("rld,aloc,"+floattostring(xx, numdigits)+",0,"+floattostring(xz, numdigits)+",0,1,0,"+floattostring(zx, numdigits)+",0,"+floattostring(zz, numdigits)+","+floattostring(x, numdigits)+","+floattostring(y, numdigits)+","+floattostring(z, numdigits)+",1,0,0,0,0,0,0,0,0,");
//		trace("goto,goto,"+floattostring(xx, numdigits)+",0,"+floattostring(xz, numdigits)+",0,1,0,"+floattostring(zx, numdigits)+",0,"+floattostring(zz, numdigits)+","+floattostring(x, numdigits)+","+floattostring(y, numdigits)+","+floattostring(z, numdigits)+",1,0,0,0,0,0,0,0,0,");
//		trace("sit,sit,"+floattostring(xx, numdigits)+",0,"+floattostring(xz, numdigits)+",0,1,0,"+floattostring(zx, numdigits)+",0,"+floattostring(zz, numdigits)+","+floattostring(x, numdigits)+","+floattostring(y, numdigits)+","+floattostring(z, numdigits)+",1,0,0,0,0,0,0,0,0,");
//		trace("item,button,"+floattostring(xx, numdigits)+",0,"+floattostring(xz, numdigits)+",0,1,0,"+floattostring(zx, numdigits)+",0,"+floattostring(zz, numdigits)+","+floattostring(x, numdigits)+","+floattostring(y, numdigits)+","+floattostring(z, numdigits)+",1,0,0,0,0,0,0,0,0,");
		logit("LOCWRITE: Writing complete. The head of the bed was to your " + stringret(ba, "right", "left"));
		
		if(placebody)
		{
			ref fch;
			if(!CheckAttribute(pchar, "lwfant")) fch = LAi_CreateFantomCharacter(false, 0, true, false, false, pchar.model, "reload", "reload1");
			else fch = GetCharacter(sti(pchar.lwfant));
			pchar.lwfant = fch.index;
			LAi_SetActorType(fch);
			LAi_ActorSetLayMode(fch);
			TeleportCharacterToPosAY(&fch, x, y, z, seconday); // move char
		}
		return;
	}
}
