//#include "DIALOGS\tavern fightingman_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	switch(Dialog.CurrentNode)
	{		
		case "Give Opium Quest":
			dialog.text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "Accept Opium Smuggle";
			Link.l2 = DLG_TEXT[4];
			Link.l2.go = "Decline Opium Smuggle";
		break;
		
		case "Accept Opium Smuggle":
			NPChar.quest.opium_smuggling.amount = 5 + rand(15) + rand(sti(pchar.rank*5));
			NPChar.quest.opium_smuggling.price = GetOpiumSellPrice()*sti(NPChar.quest.opium_smuggling.amount);
			dialog.text = DLG_TEXT[5] + NPChar.quest.opium_smuggling.amount + DLG_TEXT[6] + sti(NPChar.quest.opium_smuggling.price);
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "Start Opium Smuggle";
			Link.l2 = DLG_TEXT[4];
			Link.l2.go = "ADecline Opium Smuggle";
		break;
		
		case "Start Opium Smuggle":
			ChangeSmugglerLiking(Pchar, 1);
			NPChar.quest.opium_smuggling.given = true;
			PChar.quest.opium_smuggling.lastbuyer = NPChar.id;
			PChar.quest.opium_smuggling.lastbuyer.name = GetMySimpleName(NPChar);
			PChar.quest.opium_smuggling.lastbuyer.amount = NPChar.quest.opium_smuggling.amount;
			AddDialogExitQuest("Start Opium Smuggle Quest");
			if(HasSubStr(PChar.location.locator,"sit")) AddDialogExitQuest("exit_sit");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "Decline Opium Smuggle":
			ChangeSmugglerLiking(Pchar, -4);
			if(HasSubStr(PChar.location.locator,"sit")) AddDialogExitQuest("exit_sit");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "Sell Opium":
			if(sti(PChar.items.opium) >= sti(NPChar.quest.opium_smuggling.amount))
			{
				dialog.text = DLG_TEXT[10];
				Link.l1 = DLG_TEXT[11];
				Link.l1.go = "Complete Opium Quest";
			}
			else
			{
				dialog.text = DLG_TEXT[8];
				Link.l1 = DLG_TEXT[9];
				Link.l1.go = "Not Enough Opium";
			}
		break;
		
		case "Not Enough Opium":
			ChangeSmugglerLiking(Pchar, -1);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "Complete Opium Quest":
			ChangeSmugglerLiking(Pchar, 5);
			AddXP(pchar, SKILL_SNEAK, sti(NPChar.quest.opium_smuggling.amount)*2, XP_GROUP_OFFIC);
			AddXP(pchar, SKILL_COMMERCE, sti(NPChar.quest.opium_smuggling.amount)*5, XP_GROUP_OFFIC);
			AddMoneyToCharacter(PChar, sti(NPChar.quest.opium_smuggling.price));
			TakeNItems(PChar,"opium", -sti(NPChar.quest.opium_smuggling.amount));
			DeleteAttribute(NPChar,"quest.opium_smuggling.given");
			AddDialogExitQuest("Complete Opium Smuggle Quest");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		//default:
		if(CheckCharacterItem(Pchar,"opium") && CheckAttribute(NPChar,"quest.opium_smuggling.given") && GetAttribute(pchar,"quest.opium_smuggling.lastbuyer")==NPChar.id)
		{
			Link.l1 = DLG_TEXT[0];
			Link.l1.go = "Sell Opium";
		}
		else
		{
			if(CheckOpiumBuyer(NPChar))
			{
				Link.l1 = DLG_TEXT[1];
				Link.l1.go = "Give Opium Quest";
			}
		}
	}
}
