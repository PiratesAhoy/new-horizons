#define DEFAULT_STORYLINE "new_horizons"

string i18n(string str) {
	return str;
}


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
		LoadStoryline(storyline, j);
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

void LoadStoryline(aref config, int n) {
	ref storyline; makeref(storyline, Storylines);
	string sn = "sl" + (n + 1);
	aref sl; makearef(sl, storyline.list.(sn));

	if (config.id == DEFAULT_STORYLINE) {
		Storylines.default = n;
	}

	sl.index = n;
	sl.id = config.id;
	sl.dir = config.dir;
	sl.start.location = config.start.location;
	sl.start.port = config.start.port;
	sl.start.model = config.start.model;
	sl.start.name = config.start.first_name;
	sl.start.lastname = config.start.last_name;
	// TODO: Nation
	// TODO: Player type
	// TODO: Difficulty
	sl.start.Flags.Pirate = config.start.pirate_flag;
	sl.start.Flags.Personal = config.start.personal_flag;
	sl.start.ship = config.start.ship;
	sl.start.shipname = config.start.ship_name;
	sl.start.date.hour = config.start.date.hour;
	sl.start.date.min = config.start.date.min;
	sl.start.date.sec = config.start.date.sec;
	sl.start.date.day = config.start.date.day;
	sl.start.date.month = config.start.date.month;
	sl.start.date.year = config.start.date.year;

	sl.title = i18n("storyline:" + config.id + ":title");
	sl.description = i18n("storyline:" + config.id + ":description");

	aref config_variables;
	makearef(config_variables, config.variables)
	for (int j = 0; j < GetAttributesNum(config_variables); j++) {
		string variable_name = GetAttributeName(GetAttributeN(config_variables, j));
		AddStorylineVar(n, variable_name, config_variables.(variable_name));
	}

	Trace("Registered storyline '" + config.id + "'");
}
