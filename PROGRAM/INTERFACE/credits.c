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
	Credits.text = "";

	aref config_categories;
	aref config_contributors;
	makearef(config_categories, config.categories)
	for (int i = 0; i < GetAttributesNum(config_categories); i++) {
		string category_id = config_categories.(i);
		string title = i18n("interface:credits:" + category_id);
		Credits.(i).title = title;
		Credits.text = Credits.text + title + "\n";
		makearef(config_contributors, config.contributors);
		for (int j = 0; j < GetAttributesNum(config_contributors); j++) {
			aref contributor;
			makearef(contributor, config_contributors.(j));
			aref contributor_categories;
			makearef(contributor_categories, contributor.categories);
			for (int k = 0; k < GetAttributesNum(contributor_categories); k++) {
				if (contributor_categories.(k) == category_id) {
					Credits.text = Credits.text + contributor.name + "\n";
				}
			}
		}
	}
}

void InitInterface(string ini_name)
{
	LoadCredits();
	DumpAttributes(&Credits);

	GameInterface.title = "";
	SendMessage(&GameInterface, "ls", MSG_INTERFACE_INIT, ini_name);

	SetEventHandler("InterfaceBreak", "ProcessCancelExit", 0);
	SetEventHandler("exitCancel", "ProcessCancelExit", 0);

	SetFormatedText("INFO_TEXT", Credits.text);
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
