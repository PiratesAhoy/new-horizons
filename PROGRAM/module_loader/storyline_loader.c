#define DEFAULT_STORYLINE "new_horizons"

void LoadStorylineConfigs(string root) {
	object StorylineConfig;
	string folder = root + "/config/storyline/";
	aref config_list = GetFiles(folder, "*.toml");
	Trace("Found " + GetAttributesNum(config_list) + " storylines");
	for (int i = 0; i < GetAttributesNum(config_list); i++) {
		string config_path = GetAttributeN(config_list, i);
		LoadConfig(&StorylineConfig, folder + config_path);
	}

	DeleteAttribute(&Storylines, "");
	Storylines.list = "";
	Storylines.default = 0;

	aref storyline_config;
	makearef(storyline_config, StorylineConfig.storyline);
	for (int j = 0; j < GetAttributesNum(storyline_config); j++) {
		aref storyline = GetAttributeN(storyline_config, j);
		Trace("Found storyline '" + storyline.title + "'");
		LoadStoryline(storyline, j);
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

	sl.title = config.title;
	sl.description = config.description;

	aref config_variables;
	makearef(config_variables, config.variables)
	for (int j = 0; j < GetAttributesNum(config_variables); j++) {
		string variable_name = GetAttributeName(GetAttributeN(config_variables, j));
		AddStorylineVar(n, variable_name, config_variables.(variable_name));
	}
}
