
int GetNationByString(string id) {
	switch(id) {
		case "personal": return PERSONAL_NATION; break;
		case "england": return ENGLAND; break;
		case "france": return FRANCE; break;
		case "spain": return SPAIN; break;
		case "pirate": return PIRATE; break;
		case "holland": return HOLLAND; break;
		case "portugal": return PORTUGAL; break;
		case "america": return AMERICA; break;
		case "sweden": return SWEDEN; break;
		case "guest_nation_1": return GUEST1_NATION; break;
		case "guest_nation_2": return GUEST2_NATION; break;
		case "privateer": return PRIVATEER_NATION; break;
		case "neutral": return NEUTRAL_NATION; break;
	}

	return UNKNOWN_NATION;
}

int GetPlayerTypeByString(string id) {
	switch(id) {
		case "adventurer": return PLAYER_TYPE_ADVENTURER; break;
		case "agent": return PLAYER_TYPE_AGENT; break;
		case "military": return PLAYER_TYPE_MILITARY; break;
		case "corsair": return PLAYER_TYPE_CORSAIR; break;
		case "engineer": return PLAYER_TYPE_ENGINEER; break;
		case "explorer": return PLAYER_TYPE_EXPLORER; break;
		case "gambler": return PLAYER_TYPE_GAMBLER; break;
		case "gunner": return PLAYER_TYPE_GUNNER; break;
		case "marine": return PLAYER_TYPE_MARINE; break;
		case "merchant": return PLAYER_TYPE_MERCHANT; break;
		case "naval_officer": return PLAYER_TYPE_NAVAL_OFFICER; break;
		case "physician": return PLAYER_TYPE_PHYSICIAN; break;
		case "quartermaster": return PLAYER_TYPE_QUARTERMASTER; break;
		case "rebel": return PLAYER_TYPE_REBEL; break;
		case "rogue": return PLAYER_TYPE_ROGUE; break;
		case "sailor": return PLAYER_TYPE_SAILOR; break;
		case "shipwright": return PLAYER_TYPE_SHIPWRIGHT; break;
		case "smuggler": return PLAYER_TYPE_SMUGGLER; break;
		case "social_climber": return PLAYER_TYPE_SOCIAL_CLIMBER; break;
		case "sword_master": return PLAYER_TYPE_SWORD_MASTER; break;
		case "cursed": return PLAYER_TYPE_CURSED; break;
		case "castaway": return PLAYER_TYPE_CASTAWAY; break;
		case "custom": return PLAYER_TYPE_CUSTOM; break;
		case "land_owner": return PLAYER_TYPE_LAND_OWNER; break;
	}

	return DIFFICULTY_LANDLUBBER;
}

int GetDifficultyByString(string id) {
	switch(id) {
		case "landlubber": return DIFFICULTY_LANDLUBBER; break;
		case "mariner": return DIFFICULTY_MARINER; break;
		case "seadog": return DIFFICULTY_SEADOG; break;
		case "swashbuckler": return DIFFICULTY_SWASHBUCKLER; break;
	}

	return DIFFICULTY_LANDLUBBER;
}
