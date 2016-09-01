// fort attacking
void Situation1()
{
	InitGame();
	DelEventHandler("frame","Situation1");

	object Login;
	Login.PlayerGroup.x = 0.0;
	Login.PlayerGroup.y = 0.0;
	Login.PlayerGroup.z = 200.0;
	Login.PlayerGroup.ay = 3.6;
	Login.Island = "FalaiseDeFleur"; // KK

	SeaLogin(&Login);
}

// we against pirate group with 3 ships
void Situation2()
{
	InitGame();
	DelEventHandler("frame","Situation2");

	object Login;
	Login.PlayerGroup.x = 0.0;
	Login.PlayerGroup.y = 0.0;
	Login.PlayerGroup.z = 200.0;
	Login.PlayerGroup.ay = 3.6;
	Login.Island = "";

	Login.Encounters.m1.Type = ENCOUNTER_TYPE_MERCHANT0;
	Login.Encounters.m1.nation = PIRATE;
	Login.Encounters.m1.x = 1000;
	Login.Encounters.m1.z = 0;
	Login.Encounters.m1.ay = 0;
	Login.Encounters.m1.Attack = "OurGroup";

	SeaLogin(&Login);
}

// pirates vs france
void Situation3()
{
	DelEventHandler("frame","Situation3");
	InitGame();

	object Login;
	Login.PlayerGroup.x = 0.0;
	Login.PlayerGroup.y = 0.0;
	Login.PlayerGroup.z = 200.0;
	Login.PlayerGroup.ay = 0.0;
	Login.Island = "";

	Login.Encounters.m1.Type = ENCOUNTER_TYPE_MERCHANT0;
	Login.Encounters.m1.nation = PIRATE;
	Login.Encounters.m1.x = 1000;
	Login.Encounters.m1.z = 0;
	Login.Encounters.m1.ay = 0;
	Login.Encounters.m1.Attack = "m2";

	Login.Encounters.m2.Type = ENCOUNTER_TYPE_MERCHANT0;
	Login.Encounters.m2.nation = FRANCE;
	Login.Encounters.m2.x = 300;
	Login.Encounters.m2.z = 600;
	Login.Encounters.m2.ay = 0;
	Login.Encounters.m2.Attack = "m1";

	SeaLogin(&Login);
}
