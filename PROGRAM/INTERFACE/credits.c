#define CREDITS_DEFAULT_WEIGHT 1
#define CREDITS_MAX_WEIGHT 2000

float gCreditsProgress;

Object Credits;

void LoadCredits() {
	DeleteAttribute(&Credits, "");

	object ModuleCredits;

	aref modules_attr;
	makearef(modules_attr, Modules);
	for (int i = 0; i < GetAttributesNum(modules_attr); i++) {
		aref module = GetAttributeN(modules_attr, i);
		if (module.enabled) {
			Trace("Loading credits for module '" + module.name + "'");
			LoadCreditsConfig(&ModuleCredits, module.root);
		}
	}

	LoadModuleCredits(ModuleCredits);
}

void LoadCreditsConfig(ref config, string root) {
	string credits_file = root + "/config/credits.toml";
	LoadConfig(&config, credits_file);
}

void LoadModuleCredits(aref config) {
	aref config_categories;
	aref config_contributors;
	makearef(config_categories, config.categories)
	for (int i = 0; i < GetAttributesNum(config_categories); i++) {
		string category_id = config_categories.(i);
		aref category;
		makearef(category, Credits.(category_id));
		makearef(config_contributors, config.contributors);
		for (int j = 0; j < GetAttributesNum(config_contributors); j++) {
			aref contributor;
			makearef(contributor, config_contributors.(j));
			aref contributor_categories;
			makearef(contributor_categories, contributor.categories);
			for (int k = 0; k < GetAttributesNum(contributor_categories); k++) {
				if (contributor_categories.(k) == category_id) {
					int weight = CREDITS_DEFAULT_WEIGHT;
					if (CheckAttribute(contributor, "weight") ) {
						weight = makeint(contributor.weight);
					}
					string sort_id = (CREDITS_MAX_WEIGHT - weight) + "_" + contributor.name;
					category.(sort_id) = contributor.name;
				}
			}
		}
		sort(category);
	}
}

string GetCreditsText() {
	string result = "";

	aref config_categories;
	makearef(config_categories, Credits)
	for (int i = 0; i < GetAttributesNum(config_categories); i++) {
		string category_id = GetAttributeName(GetAttributeN(config_categories, i) );
		string title = i18n("interface:credits:" + category_id);
		result = result + title + "\n";
		aref category;
		makearef(category, Credits.(category_id));
		for (int j = 0; j < GetAttributesNum(category); j++) {
			aref contributor = GetAttributeN(category, j);
			string contributor_name = contributor;
			result = result + contributor_name + "\n";
		}
	}

	return result;
}

void InitInterface(string ini_name)
{
	LoadCredits();
	DumpAttributes(&Credits);

	GameInterface.title = "";
	SendMessage(&GameInterface, "ls", MSG_INTERFACE_INIT, ini_name);

	SetEventHandler("InterfaceBreak", "ProcessCancelExit", 0);
	SetEventHandler("exitCancel", "ProcessCancelExit", 0);

	SetFormatedText("INFO_TEXT", GetCreditsText());
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_CREDITS_EXIT);
	if(!CheckAttribute(&InterfaceStates,"InstantExit") || sti(InterfaceStates.InstantExit)==false) ReturnToMainMenu();
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");

	interfaceResultCommand = exitCode;
	if(CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true) EndCancelInterface(true);
	else EndCancelInterface(false);
}
