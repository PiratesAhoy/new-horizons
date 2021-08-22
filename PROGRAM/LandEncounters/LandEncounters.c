#include "LandEncounters\LEnc_monsters.c"
#include "LandEncounters\LEnc_login.c"
#include "LandEncounters\LandEnc_init.c"

void InitLandRandomEncounters()
{
	int i;
	for(i = 0; i < MAX_LANDENCTEMPLATES; i++)
	{
		DeleteAttribute(&LandEncTemplate[i], "");
	}
	for(i = 0; i < MAX_LAND_ENCOUNTERS; i++)
	{
		DeleteAttribute(&LandEncounters[i], "");
	}
	
	LAND_ENCOUNTERS_QUANTITY = InitLandEncounters(); // NK
	LANDENCTEMPLATES_QUANTITY = InitLandEncTemplates(); // NK
}


ref GetLandEncByID(string id)
{
	if (id=="") return &LandEncounters[0];

	for(int n = 0; n<LAND_ENCOUNTERS_QUANTITY; n++) // NK
	{
		if(LandEncounters[n].id == id) return &LandEncounters[n];
	}

	return &LandEncounters[0];
}

ref GetLandEncTemplateByID(string id)
{
	if (id=="") return &LandEncTemplate[0];

	for(int n = 0; n<LANDENCTEMPLATES_QUANTITY; n++) // NK
	{
		if(LandEncTemplate[n].id == id) return &LandEncTemplate[n];
	}

	return &LandEncTemplate[0];
}
