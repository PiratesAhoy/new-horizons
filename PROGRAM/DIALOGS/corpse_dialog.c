// ccc jul05 corpse
// This pseudo dialog only opens the itemexchange interface for looting corpses
// one could also add dialogchoices for reawakening or burial


void ProcessDialogEvent()
{
	//ref NPChar;
	aref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	//makeref(NPChar,CharacterRef);
	makearef(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

		NPChar.dlgover = true;
		DialogExit();
		PlaySound("OBJECTS\shipcharge\sail_damage1.wav");
		bDeadExchange = true; // added by MAXIMUS
		LaunchCharacterItemChange(NPChar);
    	// ccc building kit, no persistent corpses in locations with buildings
  		ref lcn = &Locations[FindLocation(NPChar.location)];
	//	if(CheckAttribute(lcn,"building") || CORPSEMODE < 2) // NK true persistent corpses
		if(CheckAttribute(lcn,"building") || CORPSEMODE < 3) // TIH lootable corpses adjustment Sep2'06
		{ 
			LAi_SetImmortal(NPChar, false);
			//Lai_KillCharacter(NPChar); 
			LAi_CharacterLogoff(NPChar);
			CharacterExitFromLocation(NPChar);
		}	// "kills" the looted corpse to clear characterslot 
}
