/*FOR WRITING ADDITIONAL LOCATORS, WHICH WILL BE LOADED BY GAME DURING RELOAD INTO LOCATION*/

int InitAdditionalLocators()
{
	ref mchr = GetMainCharacter(); // KK
	if(!CheckAttribute(mchr, "locIndex")) return -1;
	int n = sti(mchr.locIndex); // KK
	if(n<0) return -1;
	if(!CheckAttribute(locations[n],"id")) return -1;
	float x, y, z;
	string locationID, locatorGroup, locatorName;

	if (!CheckAttribute(&Locations[n], "id")) return -1; // KK
	locationID = locations[n].id;
	if(!CheckAttribute(wholeWorld, locationID)) return -1;

	ref lcn = &Locations[FindLocation(locationID)];
	string attrName, attrName1;

	aref wrldLoc; makearef(wrldLoc, wholeWorld.(locationID).locators);
	for(int i=0; i<GetAttributesNum(wrldLoc); i++)
    {
		aref curGroup = GetAttributeN(wrldLoc,i);
		locatorGroup = GetAttributeName(curGroup);
		if(CheckAttribute(wrldLoc, locatorGroup))
		{
			for(int j=0; j<GetAttributesNum(curGroup); j++)
			{
				aref curLoctr = GetAttributeN(curGroup,j);
				locatorName = GetAttributeName(curLoctr);

				if(CheckAttribute(wrldLoc, locatorGroup+"."+locatorName) && CheckAttribute(wrldLoc, locatorGroup+"."+locatorName+".tmpLocator") && wrldLoc.(locatorGroup).(locatorName).tmpLocator==false)
				{
					locations[n].locators.(locatorGroup).(locatorName).tmpLocator = wrldLoc.(locatorGroup).(locatorName).tmpLocator;
					locations[n].locators.(locatorGroup).(locatorName).corpseIdx = wrldLoc.(locatorGroup).(locatorName).corpseIdx;
					locations[n].locators.(locatorGroup).(locatorName).text = wrldLoc.(locatorGroup).(locatorName).text;

					locations[n].locators.(locatorGroup).(locatorName).x = stf(wholeWorld.(locationID).locators.(locatorGroup).(locatorName).x);
					locations[n].locators.(locatorGroup).(locatorName).y = stf(wholeWorld.(locationID).locators.(locatorGroup).(locatorName).y);
					locations[n].locators.(locatorGroup).(locatorName).z = stf(wholeWorld.(locationID).locators.(locatorGroup).(locatorName).z);

					locations[n].locators.(locatorGroup).(locatorName).vx.x = stf(wholeWorld.(locationID).locators.(locatorGroup).(locatorName).vx.x);
					locations[n].locators.(locatorGroup).(locatorName).vx.y = stf(wholeWorld.(locationID).locators.(locatorGroup).(locatorName).vx.y);
					locations[n].locators.(locatorGroup).(locatorName).vx.z = stf(wholeWorld.(locationID).locators.(locatorGroup).(locatorName).vx.z);

					locations[n].locators.(locatorGroup).(locatorName).vy.x = stf(wholeWorld.(locationID).locators.(locatorGroup).(locatorName).vy.x);
					locations[n].locators.(locatorGroup).(locatorName).vy.y = stf(wholeWorld.(locationID).locators.(locatorGroup).(locatorName).vy.y);
					locations[n].locators.(locatorGroup).(locatorName).vy.z = stf(wholeWorld.(locationID).locators.(locatorGroup).(locatorName).vy.z);

					locations[n].locators.(locatorGroup).(locatorName).vz.x = stf(wholeWorld.(locationID).locators.(locatorGroup).(locatorName).vz.x);
					locations[n].locators.(locatorGroup).(locatorName).vz.y = stf(wholeWorld.(locationID).locators.(locatorGroup).(locatorName).vz.y);
					locations[n].locators.(locatorGroup).(locatorName).vz.z = stf(wholeWorld.(locationID).locators.(locatorGroup).(locatorName).vz.z);

					locations[n].locators_radius.(locatorGroup).(locatorName) = stf(wholeWorld.(locationID).locators_radius.(locatorGroup).(locatorName));

					x = stf(locations[n].locators.(locatorGroup).(locatorName).x);
					y = stf(locations[n].locators.(locatorGroup).(locatorName).y);
					z = stf(locations[n].locators.(locatorGroup).(locatorName).z);

					int pID_1 = -1;
					int pID_2 = -1;
					int pID_3 = -1;
					int pID_4 = -1;
					int pID_5 = -1;

					if(HasSubStr(locatorGroup,"fire"))
					{
						string fireType = "camp";
						if(HasSubStr(locatorName, "flame")) { fireType = "flame"; }
						if(HasSubStr(locatorName, "blast")) { fireType = "blast"; }
						switch(fireType)
						{
							case "camp":
								if(!IsDay() && !Whr_IsRain())
								{
									pID_1 = CreateParticleSystem("fire", x, y, z, -1.57, 0, 0, 0);
									pID_2 = CreateParticleSystem("fire_mix", x, y, z, -1.57, 0, 0, 0);
									pID_3 = CreateParticleSystem("smoke", x, y, z, -1.57, 0, 0, 0);

									wholeWorld.(locationID).locators.(locatorGroup).(locatorName).pID.1 = pID_1;
									wholeWorld.(locationID).locators.(locatorGroup).(locatorName).pID.2 = pID_2;
									wholeWorld.(locationID).locators.(locatorGroup).(locatorName).pID.3 = pID_3;
									wholeWorld.(locationID).locators.(locatorGroup).(locatorName).pID.4 = pID_4;
									wholeWorld.(locationID).locators.(locatorGroup).(locatorName).pID.5 = pID_5;
								}
							break;

							case "flame":
								CreateParticleSystemX("fire_medium", x, y+0.1, z, x, y+0.1, z, 0);
							break;

							case "blast":
							break;
						}
					}
				}
			}
		}
	}
	DeleteAttribute(mchr,"locIndex");
	return n;
}

void AddNewLocators()
{
	WriteLocatorGlobal("QC_port", "camp_fire", "campfire", "", -1, 1.6411, 2.2977, -5.4587, false);
	Locations[FindLocation("QC_port")].models.night.lights.camp_fire = "heater";
	Locations[FindLocation("QC_port")].locators_radius.camp_fire = 3.0;

	WriteLocatorGlobal("Guadeloupe_Port", "camp_fire", "campfire1", "", -1, 20.4638252, 4.1738091, -3.6956100, false);
	WriteLocatorGlobal("Guadeloupe_Port", "camp_fire", "campfire2", "", -1, 20.4540234, 4.2214670, 9.8807011, false);
	WriteLocatorGlobal("Guadeloupe_Port", "camp_fire", "campfire3", "", -1, 24.2642326, 6.3004465, 9.8717833, false);
	WriteLocatorGlobal("Guadeloupe_Port", "camp_fire", "campfire4", "", -1, 24.2460709, 6.3005228, 5.9918156, false);
	WriteLocatorGlobal("Guadeloupe_Port", "camp_fire", "campfire5", "", -1, 24.2430992, 6.3004966, 0.2543197, false);
	WriteLocatorGlobal("Guadeloupe_Port", "camp_fire", "campfire6", "", -1, 24.2746677, 6.3004422, -3.5939960, false);
	Locations[FindLocation("Guadeloupe_Port")].models.night.lights.camp_fire = "heater";
	Locations[FindLocation("Guadeloupe_Port")].locators_radius.camp_fire = 4.0;
}
