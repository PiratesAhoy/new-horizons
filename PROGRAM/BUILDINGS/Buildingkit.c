#include "BUILDINGS\Colliders.c"

#define MAXBUILDINGS  16  // Max number of buildings that can be built in a location

// *********************** BUILDING KIT FUNCTIONS **********************
// This erects a building with optional interior in front of the "user"
// In InitItems.c must be definitions for building(as BLADE_ITEM_TYPE) and interior (as GUN_ITEM_TYPE)

void Build_here(ref user, string building, string interior, bool permanent)
{
	ref chr;
	string nr = "";
	string attr;
	float x,y,z,ay;
	ref lcn = &Locations[FindLocation(user.location)];	// determines where you are
	string aigroup = user.chr_ai.group;
	
//check if a buildingslot is free
	for(int i = 1; i<=MAXBUILDINGS; i++)
	{
	  attr = "building."+i+".building"
		if( !CheckAttribute(lcn,attr) )
    {
     nr = i;
    }
	}

	if(nr == "" )	
	{
		Logit(TranslateString("","There is no building ground left anymore!"));
		return;
	}

//just earcandy :)
	PlaySound("ambient\shipyard\axe.wav");
	PlaySound("ambient\shipyard\vehicle.wav");
	PlaySound("ambient\shipyard\saw.wav");
	PlaySound("ambient\shipyard\hammer.wav");
	
	// determine position in front of user (by NK, thanks :)  )
	GetCharacterPos(user, &x, &y, &z); // get pos
	GetCharacterAy(user, &ay); // get angle
	z += cos(ay)*1; // add Z component
	x += sin(ay)*1; // add X component

	ay += PI/2; // rotate angle 90deg to get building facingdir
	ay += PI/2; // again, don't know how to turn 180deg otherwise :o

// buildinglike chr is set in front of user
	Build(nr, building, interior, x, y, z, ay, aigroup)

// save permanent building as locationattributes for reloading
  if(permanent)
  {
	lcn.building.(nr).building = building;
	lcn.building.(nr).interior = interior;
	lcn.building.(nr).x = x;
	lcn.building.(nr).y = y;
	lcn.building.(nr).z = z;
	lcn.building.(nr).ay = ay; // += PI;
	lcn.building.(nr).aigroup = aigroup;
	lcn.building.(nr).taxDay = GetDataDay();
	lcn.building.(nr).taxyear = GetDataYear();
	lcn.building.(nr).taxMonth = GetDataMonth();
  }
  
// time passing for building
	aref buildingref;
	Items_FindItem(building,&buildingref);
	//int planks = sti(buildingref.building.planks);
	WaitDate("", 0, 0, 0, sti(buildingref.building.planks) + (sti(buildingref.building.bricks) * 2), 0); // KK
	LAi_Fade("", "");
	Logit(TranslateString("","Switch to first-person-view if your avatar is inside of the building"));
	ref PChar = GetMainCharacter();
	LAi_type_player_Init(PChar); // keeps playerview from swaying
}

// This adds a building to the buildinglist of a location so that it appears at next locloading
void Build_at(string locname, string building, string interior, float x, float y, float z, float ay, string aigroup)
{
	string nr = "";
	string attr;
	ref lcn = &Locations[FindLocation(locname)];
	
//check if a buildingslot is free
	for(int i = 1; i<=MAXBUILDINGS; i++)
	{
		attr = "building."+i+".building"
		if( !CheckAttribute(lcn,attr) )
		{
			nr = i;
		}
	}

	if(nr == "" )	
	{
		Logit(TranslateString("","There is no building ground free at") + " " + TranslateString("",locname));
		return;
	}
	
// save permanent building as locationattributes for reloading
	lcn.building.(nr).building = building;
	lcn.building.(nr).interior = interior;
	lcn.building.(nr).x = x;
	lcn.building.(nr).y = y;
	lcn.building.(nr).z = z;
	lcn.building.(nr).ay = ay; // += PI;
	lcn.building.(nr).aigroup = aigroup;

// ccc Feb06  use fixed date at gamestart
	if( !CheckAttribute(Environment,"date") )
	{	
		lcn.building.(nr).taxDay = 15;
		lcn.building.(nr).taxMonth = 4;
		lcn.building.(nr).taxyear = 1690;
	}else{
		lcn.building.(nr).taxDay = GetDataDay();
		lcn.building.(nr).taxMonth = GetDataMonth();
		lcn.building.(nr).taxyear = GetDataYear();
	}
// Feb06 end 
}

// This deletes a building "plan" that was stored as locationattributes
void Building_delete(ref lcn, string nr)  // nr must be called as string "" !
{
  DeleteAttribute(lcn,"building."+nr);
}

// This reerects all buildings stored as attributes to a location
void Build_again(ref lcn)
{
	if(ENABLE_BUILDINGSET == 0) return;	// ccc oct06 toggle

	ref chr;
	float x,y,z,ay;
	string building;
	string interior;
	string nr;
	string attr;
	string aigroup;

	for(int i = 1; i<=MAXBUILDINGS; i++)
	{
	 nr = i+"";
	 attr = "building."+i+".building";
	 if(CheckAttribute(lcn,attr) )
	 {
    // load building locationattributes 
	   building = lcn.building.(nr).building;
	   interior = lcn.building.(nr).interior;
	   x = stf(lcn.building.(nr).x);
	   y = stf(lcn.building.(nr).y);
	   z = stf(lcn.building.(nr).z);
	   ay = stf(lcn.building.(nr).ay);
	   aigroup = lcn.building.(nr).aigroup;

    // buildinglike chr is set to stored pos
		lcn.building.(nr).index = Build(nr, building, interior, x, y, z, ay, aigroup);
    }
  }
}


// This performs the actual building process
int Build(string nr, string building, string interior, float x, float y, float z, float ay, string aigroup)
{
	aref buildingref;
	Items_FindItem(building,&buildingref);
	int planks = sti(buildingref.building.planks);
	int bricks = 0; // KK
	if (CheckAttribute(buildingref, "building.bricks")) bricks = sti(buildingref.building.bricks); // KK
	int hp = 50 + (planks * 20) + (bricks * 30); // KK
	ref chr;
	chr = LAi_CreateFantomCharacterEx(false, 0, false, false, 0.0, buildingref.building.chrmodel, "", "");
	LAi_SetBuildingType(chr);
	LAi_SetHP(chr, hp, hp);
	LAi_group_MoveCharacter(chr, aigroup);

// MAXIMUS 09.10.2006 [for correct names showing] -->
	string corName = XI_ConvertString(building);
	if (corName == "") return;	// LDH 04Jan09
	if(LanguageGetLanguage()!="Russian") corName = strcut(corName,1,strlen(corName)-1);
	chr.old.name = building;// MAXIMUS 16.10.2006
	chr.name = corName;
// MAXIMUS 09.10.2006 [for correct names showing] <--

	chr.old.lastname = nr;	// Do not assign another oldlastname!// MAXIMUS 16.10.2006
	chr.lastname = nr;	// Do not assign another lastname!
 	chr.dialog.filename = buildingref.building.dialog;

// added by MAXIMUS [for AOP towns] -->
	if(CheckAttribute(Locations[FindLoadedLocation()],"(building).status"))
	{
		if(Locations[FindLoadedLocation()].(building).status == "permanent")
		{
			LAi_SetImmortal(chr, true);
			DeleteAttribute(chr,"dialog.filename");
		}
	}
// added by MAXIMUS [for AOP towns] <--

	GiveItem2Character(chr, building);
 	GiveItem2Character(chr, interior);
 	EquipCharacterbyItem(chr, building);
 	EquipCharacterbyItem(chr, interior);
	
	//Levis let's add colliding data
	AddCollider(building, sti(chr.index), x, y, z, ay);
	//AddCollider(interior, sti(chr.index), x, y, z, ay);

	TeleportCharacterToPosAy(chr, x, y, z, ay); // move char

	return sti(chr.index);
}

// Building Kit end _______________________________________