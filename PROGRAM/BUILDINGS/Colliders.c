//extern void GetCollideData(aref collidedata);

object Colliders;

#event_handler("CheckCollide","CheckCollide");
#event_handler("StartCollideCheck","StartCollideCheck");

//Levis: Collider functions
void AddCollider(string building, int index, float x, float y, float z, float ay)
{
	if(!BUILDING_COLLISION) return;
	if(building == "") return;
	if (FindFile("PROGRAM\BUILDINGS\templates\", "*.c", building+".c") != "") 
	{
		if(LoadSegment("BUILDINGS\templates\" + building + ".c"))
		{
			string idx = index;
			Colliders.checklist.(idx).building = building;
			aref Colliderdata; makearef(Colliderdata, Colliders.checklist.(idx));
			string func = "GetCollideData_"+building;
			call func(Colliderdata);
			Colliders.checklist.(idx).building.x = x;
			Colliders.checklist.(idx).building.y = y;
			Colliders.checklist.(idx).building.z = z;
			Colliders.checklist.(idx).building.ay = ay;
			//Now let's transform the coords of the checkblocks
			aref Checks; makearef(Checks,Colliders.checklist.(idx).checks);
			int numcheck = GetAttributesNum(Checks);
			float newx = 0;
			float newz = 0;
			float rotangle = ay;
			for(int n = 0; n < numcheck; n++)
			{
				aref check = GetAttributeN(Checks,n);
				switch(check.type)
				{
					case "circle":
						check.ay = stf(check.ay) + ay;
						check.y = stf(check.y) + y;
						newx = x + (stf(check.x) * cos(stf(check.ay)) - stf(check.z) * sin(stf(check.ay)));
						newz = z + (stf(check.x) * sin(stf(check.ay)) + stf(check.z) * cos(stf(check.ay)));
						check.x = newx;
						check.z = newz;
						if(stf(check.ay) > PI) check.ay = stf(check.ay) - 2*PI;
						if(stf(check.ay) < (-1*PI)) check.ay = stf(check.ay) + 2*PI;
					break;
					
					case "polygon4":
						float angle = stf(check.ay) + ay;
						check.ay = stf(check.ay) + ay;
						check.y = stf(check.y) + y;
						newx = x + (stf(check.x) * cos(stf(check.ay)) - stf(check.z) * sin(stf(check.ay)));
						newz = z + (stf(check.x) * sin(stf(check.ay)) + stf(check.z) * cos(stf(check.ay)));
						check.x = newx;
						check.z = newz;
						for(int p = 0; p < 4; p++)
						{
							string point = "p"+p;
							newx = x + (stf(check.(point).x) * cos(angle) - stf(check.(point).z) * sin(angle));
							newz = z + (stf(check.(point).x) * sin(angle) + stf(check.(point).z) * cos(angle));
							check.(point).x = newx;
							check.(point).z = newz;
						}
						check.area = GetTriangleArea(stf(check.p0.x), stf(check.p0.z), stf(check.p1.x), stf(check.p1.z), stf(check.p2.x), stf(check.p2.z)) + GetTriangleArea(stf(check.p3.x), stf(check.p3.z), stf(check.p1.x), stf(check.p1.z), stf(check.p2.x), stf(check.p2.z));
					break;
				}
			}
		}
	}
}

void StartCollideCheck()
{
	int checktime = 10;
	aref CollideList; makearef(CollideList,Colliders.checklist);
	int numcheck = GetAttributesNum(CollideList);
	Colliders.numcheck = numcheck;
	int interval = checktime;
	for(int n = 0; n < numcheck; n++)
	{
		int index = GetAttributeName(GetAttributeN(CollideList, n));
		SetEventHandler("CollideCheck"+index,"CollideCheck",1);
		PostEvent("CollideCheck"+index,(checktime/numcheck*n),"ll",interval,index);
	}
}

void CollideCheck()
{
	int interval = GetEventData();
	int index = GetEventData();
	int radius = sti(Colliders.checklist.(index).checkradius);
	int num = FindNearCharacters(GetCharacter(index), radius, -1.0, -1.0, 0.001, false, true);
	ref findCh;
	for(int j = 0; j < num; j++)	// the following loop runs for each near character
	{
		int cidx = sti(chrFindNearCharacters[j].index);	// defines near character as idx
		if(cidx == index) continue;
		if(cidx < 0) continue;
		aref Checks; makearef(Checks,Colliders.checklist.(index).checks);
		int numcheck = GetAttributesNum(Checks);
		for(int n = 0; n < numcheck; n++)
		{
			PostEvent("CheckCollide",1,"lll",cidx,index,n);
		}
	}
	PostEvent("CollideCheck"+index,interval,"ll",interval,index);
}

void StopCollideCheck()
{
	aref CollideList; makearef(CollideList,Colliders.checklist);
	int numcheck = GetAttributesNum(CollideList);
	for(int n = 0; n < numcheck; n++)
	{
		int index = GetAttributeName(GetAttributeN(CollideList, n));
		UnloadSegment("BUILDINGS\templates\"+Colliders.checklist.(index).building+".c");
		DelEventHandler("CollideCheck"+index,"CollideCheck");
		DeleteAttribute(CollideList,index);
	}
	Colliders.numcheck = 0;
}

void CheckCollide()
{
	int charidx = GetEventData();
	int buildingidx = GetEventData();
	int numcheck = GetEventData();
	string check = "check"+numcheck;
	ref character = GetCharacter(charidx);
	if(GetAttribute(character,"chr_ai.type") == LAI_TYPE_BUILDING) return;
	
	float x,cx,y,cy,z,cz,ay,cay;
	GetCharacterPos(character, &x, &y, &z);
	GetCharacterAy(character, &ay);
	aref tocheck; makearef(tocheck,Colliders.checklist.(buildingidx).checks.(check));
	cx = stf(tocheck.x);
	cy = stf(tocheck.y);
	cz = stf(tocheck.z);
	cay = stf(tocheck.ay);
	bool isMove = false;
	switch(tocheck.type)
	{
		case "circle":
			float distance = GetDistance2D(x, z, cx, cz);
			if(distance < sti(Colliders.checklist.(buildingidx).checks.(check).radius))
			{
				isMove = true;
			}
		break;
		
		case "polygon4":
			//we need to calculate the area between the points and the player for 4 triangles. if that is equal to the area (with a small treshold its in the polygon)
			float area = 0;
			float checkarea = stf(tocheck.area);
			float threshold = checkarea*0.05; //5% of checkarea
			area += GetTriangleArea(x, z, stf(tocheck.p0.x), stf(tocheck.p0.z), stf(tocheck.p1.x), stf(tocheck.p1.z));
			area += GetTriangleArea(x, z, stf(tocheck.p1.x), stf(tocheck.p1.z), stf(tocheck.p2.x), stf(tocheck.p2.z));
			area += GetTriangleArea(x, z, stf(tocheck.p2.x), stf(tocheck.p2.z), stf(tocheck.p3.x), stf(tocheck.p3.z));
			area += GetTriangleArea(x, z, stf(tocheck.p3.x), stf(tocheck.p3.z), stf(tocheck.p0.x), stf(tocheck.p0.z));
			if(area < (checkarea + threshold))
			{
				isMove = true;
			}
		break;
	}
	if(isMove)
	{
		float angle = atan2((x-cx),(z-cz));
		float move = 0.1 *GetTimeScale();
		x = x + move*sin(angle);
		z = z + move*cos(angle);
		if(!IsMainCharacter(character)) ay = ay+0.25*pi; //to nudge npc's in another direction
	}
	TeleportCharacterToPosAy(character, x, y, z, ay);
}

float GetTriangleArea(float x0, float y0, float x1, float y1, float x2, float y2)
{
	 float area = abs((x0*(y1-y2)+x1*(y2-y0)+x2*(y0-y1)) / 2);
	 return area;
}