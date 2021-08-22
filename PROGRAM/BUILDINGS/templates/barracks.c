void GetCollideData_barracks(aref collidedata)
{
	collidedata.checkradius = 7.5;
	//Block 0
	collidedata.checks.check0.type = "polygon4";
	collidedata.checks.check0.x = 0; //relative to character
	collidedata.checks.check0.y = 0; //relative to character
	collidedata.checks.check0.z = 1; //relative to character
	collidedata.checks.check0.ay = 0; //relative to character
	//The polygon has 4 points with each an x and z value. the area in this polygon is off limits The coords are relative to the check coords
	collidedata.checks.check0.p0.x = -7.2;
	collidedata.checks.check0.p0.z = 3.3;
	collidedata.checks.check0.p1.x = 6.0;
	collidedata.checks.check0.p1.z = 5.1;
	collidedata.checks.check0.p2.x = 7.3;
	collidedata.checks.check0.p2.z = -3.3;
	collidedata.checks.check0.p3.x = -6.0;
	collidedata.checks.check0.p3.z = -5.1;
}