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

void SetCreditsText() {
	SetFormatedText("INFO_TEXT", "");

	int offset = 0;
	aref config_categories;
	makearef(config_categories, Credits)
	for (int i = 0; i < GetAttributesNum(config_categories); i++) {
		string category_id = GetAttributeName(GetAttributeN(config_categories, i) );
		aref category;
		makearef(category, Credits.(category_id));
		int category_entries = GetAttributesNum(category);

		if (category_entries > 0) {
			string title = i18n("interface:credits:" + category_id);
			SendMessage(&GameInterface, "lsle", MSG_INTERFACE_MSG_TO_NODE, "INFO_TEXT", 0,  title);
			SendMessage(&GameInterface, "lslll", MSG_INTERFACE_MSG_TO_NODE, "INFO_TEXT", 8, offset, argb(255,251,237,68));
			offset += 1;
			for (int j = 0; j < category_entries; j++) {
				aref contributor = GetAttributeN(category, j);
				string contributor_name = contributor;
				SendMessage(&GameInterface, "lsle", MSG_INTERFACE_MSG_TO_NODE, "INFO_TEXT", 0, contributor_name);
				offset += 1;
			}
			offset += 1;
			SendMessage(&GameInterface, "lsle", MSG_INTERFACE_MSG_TO_NODE, "INFO_TEXT", 0, "\n");
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
	SetEventHandler("CreditsMoveTextEvent", "MoveText", 0);

	PostEvent("CreditsMoveTextEvent", 3000);

	SetCreditsText();
	SetMusic("credits");
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
	DelEventHandler("CreditsMoveTextEvent","MoveText");

	interfaceResultCommand = exitCode;
	if(CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true) EndCancelInterface(true);
	else EndCancelInterface(false);
}

void MoveText()
{
	if(gCreditsProgress >= 1)
	{
		ProcessCancelExit();
	}
	else
	{
		SendMessage(&GameInterface, "lslf", MSG_INTERFACE_MSG_TO_NODE, "INFO_TEXT", 2, gCreditsProgress);
		PostEvent("CreditsMoveTextEvent", 20);
		gCreditsProgress = gCreditsProgress + 0.0001;
	}
}
