void Rapid_Raid(string modeltype, int bmax, int nation, string mainrel, string npcrel, string alert, string attackers_name, string officertype, int offset, bool genrank, string bladeID, string gunID)
/* *** El Rapido's Rapid_Raid function *** PB: major simplification, 4 March 2016

Bind this to a key to put some flavour into your visits on land.
Creates a whole infantry regiment or a single raider that attacks the player.
Attention: When employing a high number of attackers the game may freeze for some seconds!
But the fun is definitely worth waiting 2 seconds! :)
Usage comparable to Random_Raid, but with slight differences.

Parameters: 		(attacker modeltype, number of attackers, nation,
					 main relation, npc relation, alert message, attackers' name, 
					 attacker's officer type, attacker's level offset, blade modeltype, gun modeltype)

attacker modeltype: 		Try "soldiers", "smugglers", "land_officers", "sailors", "mates", "outlaws"... sets the models.
							If an existing custom model ID is specified, then the game will use that
number of attackers:		self-explanatory.
nation:						Choose ENGLAND, FRANCE, SPAIN, PORTUGAL, HOLLAND or PIRATE.
main relation:				Don't mess with this, 'cause we want an attack and no childrens' birthday party!
npc relation:				Think of hugging, cuddling, giving presents to each other, singing and dancing together...
							Only change, if you know what you're doing!
alert message:				this text is displayed at the start of the attack
attackers' name:			Assigns a name to the attackers, maybe "Elite Soldiers" or "Pirate Hunters" or "Governor's Lifeguard".
							In case of a captain you might call him "Capitaine Francois Chevalier".
attacker's officer type:	different officer types give different skill and ability distributions
attacker's level offset:	if 'rank related to player' is 'false':	number is used as absolute level
							if 'rank related to player' is 'true':	number is used relative to the player level
							set negative for easier enemies, positive for harder ones; 0 for default
rank related to player:		true/false, modifies how 'attacker's level offset' is used; see above
blade modeltype: 			defines the item ID of blade, the soldiers are equipped with. Use "" for random!
gun modeltype: 				defines the item ID of gun, the soldiers are equipped with. Use "" for random!

EXAMPLE: Rapid_Raid("soldiers", 10, FRANCE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "A French infantry unit suddenly appears and attacks you!", "French Musketeer", OFFIC_TYPE_GUARD, 5, "blade13", "");
EFFECT:  10 French soldiers named "French Musketeer" will appear and attack the player.
 	 They are of the "guard" officer type and are on average 5 levels stronger than the player
 	 The Frenchmen use Dueling Rapiers and a random gun. 

UPDATE:	 It is possible to add a captain to the squad by simply calling a second Rapid_Raid with model modeltype set to "Land_Officers" and number of attackers to 1!
EXAMPLE: Rapid_Raid("Land_Officers", 1, FRANCE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "You spot the evil villain Francois Chevalier.", "Capitaine Francois Chevalier", OFFIC_TYPE_GUARD, 0, "", "");

UPDATE:	 You can even specify a certain model for your individual attacker! 
	 Maybe you want your attackers' captain or officer to look like Jack Sparrow.
EXAMPLE: Rapid_Raid("depp", 1, PIRATE, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "Why the hell did you provoke Jack Sparrow?", "Jack Sparrow", OFFIC_TYPE_GUARD, 0, "", "");

Before you call the Rapid_Raid function you should use
PlaySound("OBJECTS\raid.wav");
for atmosphere.

*/
{
	if( bSeaActive || bAbordageStarted)		// Raids are only available on land. 
	{										// Might this code be faster than the large IF-ELSE statement?
		LogIt("No raids on High Sea or during boardings, mate!");
		return;
	}

	LAi_CreateFantomGroup(modeltype, bmax, mainrel, npcrel, nation, officertype, offset, genrank, bladeID, gunID, attackers_name, LAi_FindFirstLocator("reload"));
	if (alert != "")	LogIt(alert);											// Don't show empty log messages
}

string LAi_FindFirstLocator(string group)	// This function is needed to place all troops and captains on the same spot. Random start positions look very dumb. :)
{
	if(IsEntity(loadedLocation) != true) return "";
	string at = "locators." + group;
	if(CheckAttribute(loadedLocation, at) == 0) return "";
	aref grp;
	makearef(grp, loadedLocation.(at));
	int num = GetAttributesNum(grp);
	if(num <= 0) return "";
	num = (num - 1);
	return GetAttributeName(GetAttributeN(grp, num));
}

//Levis Moved ResetMaxHP to leveling

void Restock_Ammo(int gunpowder, int pistol_bullets, int grapeshot, int musket_bullets)
{
	if (!ENABLE_AMMOMOD) return;	// LDH change

	ref _loc = &Locations[FindLocation("Tutorial_Deck")];
	
// KK -->
	if (CheckAttribute(_loc, "weaponslocker.items.gunpowder"))
	{
		_loc.weaponslocker.items.gunpowder = sti(_loc.weaponslocker.items.gunpowder) + gunpowder;
	} else {
		_loc.weaponslocker.items.gunpowder = gunpowder;
	}
	if (CheckAttribute(_loc, "weaponslocker.items.pistolbullets")) {
		_loc.weaponslocker.items.pistolbullets = sti(_loc.weaponslocker.items.pistolbullets) + pistol_bullets;
	} else {
		_loc.weaponslocker.items.pistolbullets = pistol_bullets;
	}
	if (CheckAttribute(_loc, "weaponslocker.items.pistolgrapes")) {
		_loc.weaponslocker.items.pistolgrapes = sti(_loc.weaponslocker.items.pistolgrapes) + grapeshot;
	} else {
		_loc.weaponslocker.items.pistolgrapes = grapeshot;
	}
	if (CheckAttribute(_loc, "weaponslocker.items.musketbullets")) {
		_loc.weaponslocker.items.musketbullets = sti(_loc.weaponslocker.items.musketbullets) + musket_bullets;
	} else {
		_loc.weaponslocker.items.musketbullets = musket_bullets;
	}
// <-- KK

	//PlaySound("interface\took_item.flac");	//JRH sound off when entering Captains cabin
}
