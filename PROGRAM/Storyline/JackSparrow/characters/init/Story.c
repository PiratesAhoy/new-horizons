void CreateStoryCharacters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

	ch.old.name = "Joshamee";
	ch.old.lastname = "Gibbs";
	ch.name = TranslateString("","Joshamee");
	ch.lastname = TranslateString("","Gibbs");
	ch.id		= "Storyteller";
	ch.model	= "bocman5";
	ch.sex = "man";
	ch.location	= "Tortuga_tavern";
	ch.location.group = "candles";
	ch.location.locator = "sit5";
	ch.Dialog.Filename = "Storyteller_dialog.c";
	ch.Dialog.CurrentNode = "Tavern_Story";
	ch.greeting = "Gr_Mr. Gibbs";
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "10";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "0";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "10";
	ch.skill.Sneak = "0";
	ch.money = 10000;
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n,ch);

	ch.old.name = "Random";
	ch.old.lastname = "Drunk";
	ch.name = TranslateString("Random","Drunk");
	ch.lastname = "";
	ch.id		= "Random Drunk";
	ch.model	= "50FatJack";
	ch.sex = "man";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Billy Brock_dialog.c";
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "10";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "4";
	ch.skill.Accuracy = "6";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "0";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "10";
	ch.skill.Sneak = "0";
	ch.money = 10000;
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n,ch);
}
