void GetCollideData_windmill(aref collidedata)
{
	collidedata.checkradius = 3;
	//Block 0
	collidedata.checks.check0.type = "circle";
	collidedata.checks.check0.x = 0; //relative to character
	collidedata.checks.check0.y = 0; //relative to character
	collidedata.checks.check0.z = 0; //relative to character
	collidedata.checks.check0.ay = 0; //relative to character
	collidedata.checks.check0.radius = 3; //Circles only need a radius
}