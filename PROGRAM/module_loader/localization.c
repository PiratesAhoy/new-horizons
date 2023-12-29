object Localization;

string i18n(string key) {
	if (CheckAttribute(Localization, "translations." + Localization.activeLanguage)) {
		string language_key = Localization.activeLanguage;
		aref language; makearef(language, Localization.translations.(language_key));
		if (CheckAttribute(language, key)) {
			return language.(key);
		}
	}
	else {
		Trace("No translations available for active language (" + Localization.activeLanguage + ")");
	}
	return key;
}

void LoadTranslations() {
	DeleteAttribute(&Localization, "translations");

	string active_language = "en";
	Localization.activeLanguage = active_language;

	aref TranslationData; makearef(TranslationData, Localization.translations);

	aref modules_attr;
	makearef(modules_attr, Modules);
	for (int i = 0; i < GetAttributesNum(modules_attr); i++) {
		aref module = GetAttributeN(modules_attr, i);
		if (module.enabled) {
			Trace("Loading translations for module '" + module.name + "'");
			LoadModuleTranslations(&TranslationData, module.root);
		}
	}
}

void LoadModuleTranslations(ref data, string root) {
	object LanguageFinder;
	ListFiles(&LanguageFinder, root + "/lang");

	aref language_list;
	makearef(language_list, LanguageFinder.files);
	int language_count = GetAttributesNum(language_list);
	int module_count = 0;
	for (int i = 0; i < GetAttributesNum(language_list); i++) {
		string language_key = GetAttributeN(language_list, i);
		string folder = root + "/lang/" + language_key;
		aref config_list = GetFiles(folder, "*.toml");
		Trace("Found " + GetAttributesNum(config_list) + " translation files for '" + language_key + "'");
		aref language_dict; makearef(language_dict, data.(language_key));
		for (int j = 0; j < GetAttributesNum(config_list); j++) {
			string config_path = GetAttributeN(config_list, j);
			LoadConfig(language_dict, folder + "/" + config_path);
		}
	}
}

