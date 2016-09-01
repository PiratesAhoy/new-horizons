void GetCollideData_church(aref collidedata)
{
	collidedata.checkradius = 10;
	//Block 0
	collidedata.checks.check0.type = "polygon4";
	collidedata.checks.check0.x = 0.86; //relative to character
	collidedata.checks.check0.y = 0; //relative to character
	collidedata.checks.check0.z = -3.82; //relative to character
	collidedata.checks.check0.ay = 0; //relative to character
	//The polygon has 4 points with each an x and z value. the area in this polygon is off limits The coords are relative to the check coords
	collidedata.checks.check0.p0.x = -6.35;
	collidedata.checks.check0.p0.z = -7.37;
	collidedata.checks.check0.p1.x = 9.01;
	collidedata.checks.check0.p1.z = -3.59;
	collidedata.checks.check0.p2.x = 7.99;
	collidedata.checks.check0.p2.z = -0.40;
	collidedata.checks.check0.p3.x = -7.23;
	collidedata.checks.check0.p3.z = -3.90;
	
	//Block 1
	collidedata.checks.check1.type = "polygon4";
	collidedata.checks.check1.x = -0.58; //relative to character
	collidedata.checks.check1.y = 0; //relative to character
	collidedata.checks.check1.z = 2.09; //relative to character
	collidedata.checks.check1.ay = 0; //relative to character
	//The polygon has 4 points with each an x and z value. the area in this polygon is off limits The coords are relative to the check coords
	collidedata.checks.check1.p0.x = -5.69;
	collidedata.checks.check1.p0.z = -3.49;
	collidedata.checks.check1.p1.x = -7.56;
	collidedata.checks.check1.p1.z = 4.20;
	collidedata.checks.check1.p2.x = 6.42;
	collidedata.checks.check1.p2.z = -0.46;
	collidedata.checks.check1.p3.x = 4.5;
	collidedata.checks.check1.p3.z = 8.1;
	
	//Block 2
	collidedata.checks.check2.type = "polygon4";
	collidedata.checks.check2.x = -7.29; //relative to character
	collidedata.checks.check2.y = 0; //relative to character
	collidedata.checks.check2.z = 1.35; //relative to character
	collidedata.checks.check2.ay = 0; //relative to character
	//The polygon has 4 points with each an x and z value. the area in this polygon is off limits The coords are relative to the check coords
	collidedata.checks.check2.p0.x = -6.99;
	collidedata.checks.check2.p0.z = 3.01;
	collidedata.checks.check2.p1.x = -8.15;
	collidedata.checks.check2.p1.z = 2.68;
	collidedata.checks.check2.p2.x = -7.51;
	collidedata.checks.check2.p2.z = -0.41;
	collidedata.checks.check2.p3.x = -6.51;
	collidedata.checks.check2.p3.z = 0.11;
}