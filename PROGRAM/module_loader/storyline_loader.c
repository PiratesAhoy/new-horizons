#define DEFAULT_STORYLINE "new_horizons"

void LoadStoryLines() {
	DeleteAttribute(&Storylines, "");
	Storylines.list = "";
	Storylines.default = 0;

	object StorylineConfig;

	aref modules_attr;
	makearef(modules_attr, Modules);
	for (int i = 0; i < GetAttributesNum(modules_attr); i++) {
		aref module = GetAttributeN(modules_attr, i);
		if (module.enabled) {
			Trace("Loading storylines for module '" + module.name + "'");
			LoadStorylineConfigs(&StorylineConfig, module.root);
		}
	}

	aref storyline_config_attr;
	makearef(storyline_config_attr, StorylineConfig.storyline);
	for (int j = 0; j < GetAttributesNum(storyline_config_attr); j++) {
		aref storyline = GetAttributeN(storyline_config_attr, j);
		string storyline_id = GetAttributeName(storyline);
		LoadStoryline(storyline, storyline_id, j);
	}
}

void LoadStorylineConfigs(ref config, string root) {
	string folder = root + "/config/storyline/";
	aref config_list = GetFiles(folder, "*.toml");
	Trace("Found " + GetAttributesNum(config_list) + " storylines");
	for (int i = 0; i < GetAttributesNum(config_list); i++) {
		string config_path = GetAttributeN(config_list, i);
		LoadConfig(&config, folder + config_path);
	}
}

bool IsStoryLineConfigLocked(aref config, string property) {
	if (CheckAttribute(config, "start.editable")) {
		if (CheckAttribute(config, "start.editable." + property)) {
			return sti(config.start.editable.(property)) != 1;
		}
	}
	return true;
}

void LoadStoryline(aref config, string id, int n) {
	ref storyline; makeref(storyline, Storylines);
	string sn = "sl" + (n + 1);
	aref sl; makearef(sl, storyline.list.(sn));

	if (id == DEFAULT_STORYLINE) {
		Storylines.default = n;
	}

	sl.index = n;
	sl.id = id
	sl.dir = config.dir;
	sl.start.location = config.start.location;
	sl.start.location.lock = IsStoryLineConfigLocked(config, "location");
	sl.start.port = config.start.port;
	sl.start.port.lock = IsStoryLineConfigLocked(config, "port");
	sl.start.model = config.start.model;
	sl.start.model.lock = IsStoryLineConfigLocked(config, "model");
	sl.start.name = config.start.first_name;
	sl.start.name.lock = IsStoryLineConfigLocked(config, "first_name");
	sl.start.lastname = config.start.last_name;
	sl.start.lastname.lock = IsStoryLineConfigLocked(config, "last_name");
	sl.start.nation = GetNationByString(config.start.nation);
	sl.start.nation.lock = IsStoryLineConfigLocked(config, "nation");
	sl.start.playerType = GetPlayerTypeByString(config.start.player_type);
	sl.start.playerType.lock = IsStoryLineConfigLocked(config, "player_type");
	if (CheckAttribute(config, "start.difficulty") ) {
		sl.start.difficulty = GetDifficultyByString(config.start.difficulty);
	}
	else {
		sl.start.difficulty = DIFFICULTY_LANDLUBBER;
	}
	sl.start.difficulty.lock = IsStoryLineConfigLocked(config, "difficulty");
	sl.start.Flags.Pirate = config.start.pirate_flag;
	sl.start.Flags.Pirate.lock = IsStoryLineConfigLocked(config, "pirate_flag");
	sl.start.Flags.Personal = config.start.personal_flag;
	sl.start.Flags.Personal.lock = IsStoryLineConfigLocked(config, "personal_flag");
	if (CheckAttribute(config, "start.ship") ) {
		sl.start.ship = config.start.ship;
	}
	sl.start.ship.lock = IsStoryLineConfigLocked(config, "ship");
	if (CheckAttribute(config, "start.ship_name") ) {
		sl.start.shipName = config.start.ship_name;
	}
	sl.start.shipName.lock = IsStoryLineConfigLocked(config, "ship_name");
	sl.start.date.hour = config.start.date.hour;
	sl.start.date.min = config.start.date.min;
	sl.start.date.sec = config.start.date.sec;
	sl.start.date.day = config.start.date.day;
	sl.start.date.month = config.start.date.month;
	sl.start.date.year = config.start.date.year;
	sl.start.date.lock = IsStoryLineConfigLocked(config, "date");

	sl.title = i18n("storyline:" + id + ":title");
	sl.description = i18n("storyline:" + id + ":description");

	aref config_variables;
	makearef(config_variables, config.variables)
	for (int j = 0; j < GetAttributesNum(config_variables); j++) {
		string variable_name = GetAttributeName(GetAttributeN(config_variables, j));
		AddStorylineVar(n, variable_name, config_variables.(variable_name));
	}

	if (CheckAttribute(config, "tags") ) {
		aref tags;
		makearef(tags, config.tags);
		for (int k = 0; k < GetAttributesNum(tags); k++) {
			string tag_name = GetAttributeName(GetAttributeN(tags, k));
			sl.tags.(tag_name) = tags.(tag_name);
		}
	}

	Trace("Registered storyline '" + id + "'");
}
