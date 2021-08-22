//#include "DIALOGS\Inquisitor_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	ref romance, villain;
	int romanceidx, villainidx;

	switch(Dialog.CurrentNode)
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "start":
			dialog.text = DLG_TEXT[0];			
			link.l1 = DLG_TEXT[1];
			link.l1.go = "unexpected1";
		break;

		case "unexpected1":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "charles";
			link.l2 = DLG_TEXT[4];
			link.l2.go = "helen";
		break;

		case "charles":
			SetModelfromArray(PChar, GetModelIndex("Ardent"));
			PChar.sex = "man";
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "adventure";
			link.l2 = DLG_TEXT[7];
			link.l2.go = "gold";
		break;

		case "helen":
			GiveModel2Player("Ardent_F", true);
			DeleteAttribute(PChar, "clothes.ardent");	
			PChar.sex = "woman";
			PChar.old.name = "Helen";
			PChar.name = TranslateString("","Helen");
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "adventure";
			link.l2 = DLG_TEXT[7];
			link.l2.go = "gold";
		break;

		case "adventure":
			if (PChar.sex == "woman") GiveModel2Player("ArdentF_3", false);
			PChar.quest.alignment = "good";
			ChangeCharacterReputation(pchar, 5);
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "pirate";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "personal";
		break;

		case "gold":
			if (PChar.sex == "woman") GiveModel2Player("ArdentF_3", true);
			PChar.quest.alignment = "evil";
			ChangeCharacterReputation(pchar, -5);
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "pirate";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "personal";
		break;

		case "pirate":
			SetServedNation(PIRATE);
			PChar.quest.background = "pirate";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			if (ENABLE_CHEATMODE) link.l1.go = "cheats";
			else link.l1.go = "exit";
		break;

		case "personal":
			SetServedNation(PERSONAL_NATION);
			PChar.quest.background = "smuggler";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			if (ENABLE_CHEATMODE) link.l1.go = "cheats";
			else link.l1.go = "exit";
		break;

		case "cheats":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[15];
			link.l2.go = "mona_attack";
		break;

		case "mona_attack":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit_cheat";
			PChar.quest.cheating = "true";

			if (checkquestattribute("alignment", "evil"))
			{
				SetOfficersIndex(Pchar, 1, GetCharacterIndex("Gheerkin Kamalaas"));
				SetOfficersIndex(Pchar, 2, GetCharacterIndex("Morys Badlad"));
				ChangeCharacterAddressGroup(characterFromID("Gheerkin Kamalaas"), "Santiago_port", "officers", "reload2_1");
				ChangeCharacterAddressGroup(characterFromID("Morys Badlad"), "Santiago_port", "officers", "reload2_2");
			}
			else
			{
				SetOfficersIndex(Pchar, 1, GetCharacterIndex("Louwe Louwman"));
				SetOfficersIndex(Pchar, 2, GetCharacterIndex("Giraldo Annibal"));
				ChangeCharacterAddressGroup(characterFromID("Louwe Louwman"), "Santiago_port", "officers", "reload2_1");
				ChangeCharacterAddressGroup(characterFromID("Giraldo Annibal"), "Santiago_port", "officers", "reload2_2");
			}
			if (PChar.sex == "man")
			{
				romance = characterFromID("Lucia de la Vega");
				romanceidx = getCharacterIndex("Lucia de la Vega");
				villain = characterFromID("Piers Downing");
				villainidx = getCharacterIndex("Piers Downing");
				ChangeCharacterAddress(characterFromID("Edmundo de la Vega"), "None", "");
				ChangeCharacterAddress(characterFromID("Valerie Downing"), "None", "");
			}
			else
			{
				romance = characterFromID("Edmundo de la Vega");
				romanceidx = getCharacterIndex("Edmundo de la Vega");
				villainidx = getCharacterIndex("Valerie Downing");
				LAi_SetStayType(characterfromID("Valerie Downing"));
				ChangeCharacterAddress(characterFromID("Lucia de la Vega"), "None", "");
				ChangeCharacterAddress(characterFromID("Piers Downing"), "None", "");
			}

			Characters[romanceidx].married = MR_MARRIED;
			Characters[romanceidx].married.id = characters[villainidx].id;
			Characters[romanceidx].annulled = "pending";
			characters[villainidx].married = MR_MARRIED;
			characters[villainidx].married.id = characters[romanceidx].id;
			SetOfficersIndex(Pchar, 3, romanceidx);
			ChangeCharacterAddressGroup(romance, "Santiago_port", "officers", "reload2_3");
			AddPassenger(PChar, characterFromID("Two Dogs"), 0);
			characters[GetCharacterIndex("Two Dogs")].name = TranslateString("","Two Dogs");
			characters[GetCharacterIndex("Two Dogs")].lastname = TranslateString("","Fighting");
			GiveShip2Character(PChar, "RN_WarGalleon", "Assurance", -1, ENGLAND, true, true);
			DeleteQuestAttribute("crew_left");
			SetRank(PChar, SPAIN, GetOldRank(PChar, SPAIN));
			locations[FindLocation("Tutorial_Deck")].type = "own_deck";

			GiveItem2Character(PChar, "key3");

			if (PChar.sex == "man")
			{
				GiveModel2Player("Ardent_S", false);
				PChar.quest.lucia_new_outfit.win_condition.l1 = "party_goods";
				PChar.quest.lucia_new_outfit.win_condition.l1.goods = GOOD_SILK;
				PChar.quest.lucia_new_outfit.win_condition.l1.quantity = 1;
				PChar.quest.lucia_new_outfit.win_condition.l1.operation = ">=";
				PChar.quest.lucia_new_outfit.win_condition = "lucia_new_outfit";
			}
			else GiveModel2Player("Ardent_SF", false);

			PChar.quest.payroll_ship = "success";
			PChar.quest.mayan_temple = "been_to_temple";
			PChar.quest.signet_ring_known = "true";
			PChar.quest.revenge_type = "officer";
		break;

		case "museum_assistant":
			Preprocessor_Add("otherguy", GetMySimpleName(CharacterFromID("Museum Inquisitor 1")));
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			AddDialogExitQuest("museum_interrogation1");
			link.l1.go = "exit";
		break;

		case "museum_heresy":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "museum_get_chair";
			link.l2 = DLG_TEXT[20];
			link.l2.go = "museum_must_cooperate";
		break;

		case "museum_must_cooperate":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "museum_get_chair";
		break;

		case "museum_get_chair":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			AddDialogExitQuest("museum_interrogation2");
			link.l1.go = "exit";
		break;

		case "museum_no_chair":
			dialog.text = DLG_TEXT[25];
			link.l1 = "...";
			link.l1.go = "exit";
		break;

		case "museum_no_trinkets":
			dialog.text = DLG_TEXT[26];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "museum_should only_be_two":
			dialog.text = DLG_TEXT[27];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "museum_begone":
			dialog.text = DLG_TEXT[28];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "museum_following_you":
			dialog.text = DLG_TEXT[29] + GetMySimpleName(PChar) + ".";
			link.l1 = DLG_TEXT[30];
			link.l1.go = "museum_who_are_you";
		break;

		case "museum_who_are_you":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "museum_must_go";
		break;

		case "museum_must_go":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "exit";
			if (ENABLE_CHEATMODE)
			{
				link.l2 = DLG_TEXT[34];
				link.l2.go = "museum_no_power";
			}
		break;

		case "museum_no_power":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "exit";
		break;

		case "exit_cheat":
			PChar.location.from_sea = "Santiago_port";
			SetFleetInTown("Santiago", "PChar");
			DoReloadCharacterToLocation("Santiago_port", "reload", "reload2");
			HoistFlag(SPAIN);

			if (ENABLE_WEAPONSMOD)
			{
				GiveItem2Character(PChar, "blade44+1");
				EquipCharacterByItem(PChar, "blade44+1");
			}
			else
			{
				GiveItem2Character(PChar, "blade44");
				EquipCharacterByItem(PChar, "blade44");
			}
			GiveItem2Character(PChar, "PiratesPistol");
			EquipCharacterByItem(PChar, "PiratesPistol");
			//JRH ammo mod -->
			if (ENABLE_AMMOMOD)
			{
				TakenItems(PChar, "gunpowder", 6);
				TakenItems(PChar, "pistolbullets", 6);
			}
			//JRH ammo mod <--
			GiveItem2Character(PChar, "spyglass2");
			GiveItem2Character(PChar, "compass2");
			GiveItem2Character(PChar, "clock1");
			EquipCharacterByItem(PChar, "spyglass2");
			EquipCharacterByItem(PChar, "compass2");
			EquipCharacterByItem(PChar, "clock1");
			AddMoneyToCharacter(PChar, 1000);

			EndQuestMovie();
			AddDialogExitQuest("mona_attack_triggers");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	}
}