//#include "DIALOGS\Bartholomew Roberts_dialog.h"
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

	locations[FindLocation("Antigua_port")].type = "port";

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			ResumeAllSounds();
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\ARSI\ARSI001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
			link.l2 = DLG_TEXT[2];
			link.l2.go = "Antigua_for_battle";
			link.l3 = DLG_TEXT[3];
			link.l3.go = "Examination_for_lieutenant";
			link.l4 = DLG_TEXT[4];
			link.l4.go = "Court_Martial";
			link.l5 = DLG_TEXT[5];
			link.l5.go = "French_Sea_Battle";
			link.l6 = DLG_TEXT[6];
			link.l6.go = "Fire_Ship";
			link.l7 = DLG_TEXT[7];
			link.l7.go = "Mutiny";
			link.l8 = DLG_TEXT[8];
			link.l8.go = "New Characters";
			link.l9 = DLG_TEXT[9];
			link.l9.go = "New_Story_Line";
			link.l10 = DLG_TEXT[10];
			link.l10.go = "Hotspur and Loyalty";
			link.l11 = DLG_TEXT[11];
			link.l11.go = "From Cayman";
			link.l12 = DLG_TEXT[12];
			link.l12.go = "Quest Ship Deck";
			link.l13 = DLG_TEXT[13];
			link.l13.go = "Out_of_Spanish_Prison";
			link.l14 = DLG_TEXT[14];
			link.l14.go = "Tunnel Stuff";
			link.l15 = DLG_TEXT[15];
			link.l15.go = "Hunt_the_traitors";
		break;

		case "Exit":
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "Quest Ship Deck":
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Keene"));
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Harvey"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Percy Buckland"));

			DisableFastTravel(false);
			pchar.quest.Players_Rank = "Commander";
			SetRank(pchar, ENGLAND, 5); // PB: 3rd Lieutenant
			GiveModel2Player("brtHComdr_18", true);
			pchar.quest.story_path = "neutral";
			SetShipRemovable(pchar, true);
			DeleteAttribute(PChar, "isnotcaptain");
			GiveShip2Character(pchar,"RN_Volage","Hotspur",-1,ENGLAND,true,true);
			setCharacterShipLocation(Pchar, "Greenford_port");
			
			Characters[GetCharacterIndex("Sir Edward Pellew")].model = "PellewA_18";
			Characters[GetCharacterIndex("Sir Edward Pellew")].headmodel = "h_PellewA_18";
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Cabin2SJG", "officers", "officer1");
			ChangeCharacterAddressGroup(characterFromID("Black Charlie Hammond"), "Cabin2SJG", "rld", "aloc6");

			DoQuestReloadToLocation("Cabin2SJG", "reload", "reload1", "Pellew_Hammond_Plan2");
			
			ChangeCharacterAddressGroup(NPChar, "none", "", "");
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "Tunnel Stuff":
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Keene"));
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Harvey"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Percy Buckland"));

			DisableFastTravel(false);
			GiveShip2Character(pchar,"HMS_Indefatigable","Indefatigable",-1,ENGLAND,true,true);
			SetCharacterShipLocation(Pchar, "Charlestown_port");

			DoQuestReloadToLocation("Charlestown_port", "reload", "Sea_1_back", "FrenchShipDestroyed");

			ChangeCharacterAddressGroup(NPChar, "none", "", "");
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "Antigua_for_battle":
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Keene"));
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Harvey"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Percy Buckland"));

			ChangeCharacterAddress(characterFromID("Major Dunnitt"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Cooper"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Haggman"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Harris"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Higgins"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Tongue"), "None", "");

			Characters[GetCharacterIndex("Arthur Wellesley")].model = "WellesleyG_18";
			Characters[GetCharacterIndex("Arthur Wellesley")].headmodel = "h_WellesleyG_18";
			
			pchar.quest.Players_Rank = "Commander";
			SetRank(pchar, ENGLAND, 5);
			pchar.quest.story_path = "neutral";
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"HMS_Sophie","Retribution",-1,ENGLAND,true,true);
			setCharacterShipLocation(Pchar, "Antigua_port");
			GiveModel2Player("brtHComdr_18", true);
			
//			ChangeCharacterAddressGroup(NPChar, "none", "", "");
//			NextDiag.CurrentNode = "First time";		
//			DialogExit();

			AddDialogExitQuest("change_uniforms");
			ChangeCharacterAddressGroup(NPChar, "none", "", "");
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "change_uniforms":
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Keene"));
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Harvey"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Percy Buckland"));

			pchar.quest.Players_Rank = "Commander";
			SetRank(pchar, ENGLAND, 5);
			GiveModel2Player("brtHComdr_18", true);
			pchar.quest.Soldier_Company = "Sergeant";
			ChangeCharacterAddressGroup(characterFromID("Richard Sharpe"), "Antigua_port", "goto", "goto9");
			ChangeCharacterAddressGroup(characterFromID("Lt. Uriah Quelp"), "Antigua_port", "goto", "goto27");
			SetModelfromArray(characterFromID("Richard Sharpe"), GetModelIndex("SharpeS_Rif8_18"));
			Characters[GetCharacterIndex("Richard Sharpe")].headmodel = "h_SharpeS_Rif8_18";

			SetModelfromArray(characterFromID("Parick Harper"), GetModelIndex("Rifleman_Harper"));
			Characters[GetCharacterIndex("Patrick Harper")].headmodel = "h_Rifleman_Harper";
			SetModelfromArray(characterFromID("Rifleman Haggman"), GetModelIndex("Rifleman95B4_18"));
			Characters[GetCharacterIndex("Rifleman Haggman")].headmodel = "h_Rifleman95B4_18";
			SetModelfromArray(characterFromID("Rifleman Higgins"), GetModelIndex("Rifleman95D3_18"));
			Characters[GetCharacterIndex("Rifleman Higgins")].headmodel = "h_Rifleman95D3_18";
			SetModelfromArray(characterFromID("Rifleman Tongue"), GetModelIndex("Rifleman95F3_18"));
			Characters[GetCharacterIndex("Rifleman Tongue")].headmodel = "h_Rifleman95F3_18";
			SetModelfromArray(characterFromID("Rifleman Cooper"), GetModelIndex("Rifleman95E3_18"));
			Characters[GetCharacterIndex("Rifleman Cooper")].headmodel = "h_Rifleman95E3_18";
			SetModelfromArray(characterFromID("Rifleman Harris"), GetModelIndex("Rifleman95B3_18"));
			Characters[GetCharacterIndex("Rifleman Harris")].headmodel = "h_Rifleman95B3_18";
			SetModelfromArray(characterFromID("Rifleman Mansfield"), GetModelIndex("Rifleman95A3_18"));
			Characters[GetCharacterIndex("Rifleman Mansfield")].headmodel = "h_Rifleman95A3_18";

			SetOfficersIndex(Pchar, 1, getCharacterIndex("Lt. Uriah Quelp"));
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Matthews"));
			LAi_SetActorType(characterFromID("Oldroyd"));
			LAi_SetActorType(characterFromID("Styles"));

			DoQuestReloadToLocation("Antigua_port", "reload", "Sea_1_back", "Antigua_for_battle");
		break;

		case "New_Story_Line":
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Keene"));
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Harvey"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Percy Buckland"));

			DisableFastTravel(false);
			pchar.quest.Players_Rank = "Commander";
			SetRank(pchar, ENGLAND, 5); // PB: 3rd Lieutenant
			GiveModel2Player("brtHComdr_18", true);
			pchar.quest.Soldier_Company = "Sergeant";
			SetModelfromArray(characterFromID("Richard Sharpe"), GetModelIndex("SharpeL_Rif7_18"));
			Characters[GetCharacterIndex("Richard Sharpe")].headmodel = "h_SharpeL_Rif7_18";
			Characters[GetCharacterIndex("Patrick Harper")].model = "Harper_Sergeant";
			Characters[GetCharacterIndex("Patrick Harper")].headmodel = "h_Harper_Sergeant";
			Characters[GetCharacterIndex("Rifleman Haggman")].model = "Rifleman95B4_18";
			Characters[GetCharacterIndex("Rifleman Haggman")].headmodel = "h_Rifleman95B4_18";
			Characters[GetCharacterIndex("Rifleman Higgins")].headmodel = "h_Rifleman95D3_18";
			Characters[GetCharacterIndex("Rifleman Higgins")].headmodel = "h_Rifleman95D3_18";
			Characters[GetCharacterIndex("Rifleman Tongue")].model = "Rifleman95f3_18";
			Characters[GetCharacterIndex("Rifleman Tongue")].headmodel = "h_Rifleman95F3_18";
			Characters[GetCharacterIndex("Rifleman Cooper")].model = "Rifleman95E3_18";
			Characters[GetCharacterIndex("Rifleman Cooper")].headmodel = "h_Rifleman95E3_18";
			Characters[GetCharacterIndex("Rifleman Harris")].model = "Rifleman95B3_18";
			Characters[GetCharacterIndex("Rifleman Harris")].headmodel = "h_Rifleman95B3_18";
			Characters[GetCharacterIndex("Rifleman Mansfield")].model = "Rifleman95A3_18";
			Characters[GetCharacterIndex("Rifleman Mansfield")].headmodel = "h_Rifleman95A3_18";

			DoQuestReloadToLocation("Greenford_port", "goto", "goto21", "Coming_to_the_end");

			ChangeCharacterAddressGroup(NPChar, "none", "", "");
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "Hotspur and Loyalty":
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Keene"));
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Harvey"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Percy Buckland"));

			DisableFastTravel(false);
			pchar.quest.Players_Rank = "Commander";
			SetRank(pchar, ENGLAND, 5);
			GiveModel2Player("brtHComdr_18", true);
			pchar.quest.story_path = "neutral";
			SetShipRemovable(pchar, true);
			DeleteAttribute(PChar, "isnotcaptain");
			GiveShip2Character(pchar,"RN_Volage","Hotspur",-1,ENGLAND,true,true);
			setCharacterShipLocation(Pchar, "Greenford_port");
			pchar.quest.Soldier_Company = "Lieutenant";
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Lt. William Bush"));
			SetModelfromArray(characterFromID("Richard Sharpe"), GetModelIndex("SharpeL_Rif7_18"));
			Characters[GetCharacterIndex("Richard Sharpe")].headmodel = "h_SharpeL_Rif7_18";
			Characters[GetCharacterIndex("Patrick Harper")].model = "Harper_Sergeant";
			Characters[GetCharacterIndex("Patrick Harper")].headmodel = "h_Harper_Sergeant";
			ChangeCharacterAddressGroup(characterFromID("Lt. Uriah Quelp"), "Greenford_port", "goto", "goto21");
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Greenford_port", "goto", "goto3");
			DoQuestReloadToLocation("Greenford_port", "reload", "reload1", "Set_up_the_quest2");
			Locations[FindLocation("Greenford_port")].vcskip = true;
			Locations[FindLocation("Greenford_tavern")].vcskip = true;

			ChangeCharacterAddressGroup(NPChar, "none", "", "");
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "From Cayman":
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Keene"));
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Harvey"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Percy Buckland"));

			DisableFastTravel(false);
			pchar.quest.Players_Rank = "Commander";
			SetRank(pchar, ENGLAND, 5);
			GiveModel2Player("brtHComdr_18", true);
			pchar.quest.story_path = "neutral";
			SetShipRemovable(pchar, true);
			DeleteAttribute(PChar, "isnotcaptain");
			GiveShip2Character(pchar,"RN_Volage","Hotspur",-1,ENGLAND,true,true);
			setCharacterShipLocation(Pchar, "Cayman_port");
			pchar.quest.Soldier_Company = "Lieutenant";
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Lt. William Bush"));
			SetModelfromArray(characterFromID("Richard Sharpe"), GetModelIndex("SharpeL_Rif7_18"));
			Characters[GetCharacterIndex("Richard Sharpe")].headmodel = "h_SharpeL_Rif7_18";
			Characters[GetCharacterIndex("Rifleman Mansfield")].model = "Rifleman95A3_18";
			Characters[GetCharacterIndex("Rifleman Mansfield")].headmodel = "h_Rifleman95A3_18";
			Characters[GetCharacterIndex("Patrick Harper")].model = "Harper_Sergeant";
			Characters[GetCharacterIndex("Patrick Harper")].headmodel = "h_Harper_Sergeant";
			Characters[GetCharacterIndex("Rifleman Haggman")].model = "Rifleman95B4_18";
			Characters[GetCharacterIndex("Rifleman Haggman")].headmodel = "h_Rifleman95B4_18";
			Characters[GetCharacterIndex("Rifleman Higgins")].model = "Rifleman95D3_18";
			Characters[GetCharacterIndex("Rifleman Higgins")].headmodel = "h_Rifleman95D3_18";
			Characters[GetCharacterIndex("Rifleman Tongue")].model = "Rifleman95F3_18";
			Characters[GetCharacterIndex("Rifleman Tongue")].headmodel = "h_Rifleman95F3_18";
			Characters[GetCharacterIndex("Rifleman Cooper")].model = "Rifleman95E3_18";
			Characters[GetCharacterIndex("Rifleman Cooper")].headmodel = "h_Rifleman95E3_18";
			Characters[GetCharacterIndex("Rifleman Harris")].model = "Rifleman95B3_18";
			Characters[GetCharacterIndex("Rifleman Harris")].headmodel = "h_Rifleman95B3_18";
			Characters[GetCharacterIndex("Rifleman Perkins")].model = "RiflemanPerk_18";
			Characters[GetCharacterIndex("Rifleman Perkins")].headmodel = "h_RiflemanPerk_18";
			
			ChangeCharacterAddressGroup(characterFromID("Lt. William Bush"), "Cayman_port", "officers", "sea_1");
			DoQuestReloadToLocation("Cayman_port", "goto", "goto8", "Bush_gets_suspicious");
			Locations[FindLocation("Cayman_port")].vcskip = true;

			ChangeCharacterAddressGroup(NPChar, "none", "", "");
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "Examination_for_lieutenant":
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Keene"));
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Harvey"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Percy Buckland"));

			SetQuestHeader("Examination for Lieutenant");
			AddQuestRecord("Examination for Lieutenant", 1);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Arthur Wellesley"));
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar,"FR_Sloop","Le Rиve",-1,FRANCE,true,true);
			SetCharacterShipLocation(Pchar, "REDMOND_PORT");
			SetCrewQuantity(pchar, 150);
			AddCharacterGoods(pchar, GOOD_BALLS, 500);
			AddCharacterGoods(pchar, GOOD_GRAPES, 300);
			AddCharacterGoods(pchar, GOOD_KNIPPELS, 200);
			AddCharacterGoods(pchar, GOOD_RUM, 10);
			AddCharacterGoods(pchar, GOOD_WHEAT, 20);

			DoQuestReloadToLocation("REDMOND_PORT", "reload", "Sea_1_back", "With_Foster_to_Jamaica"); 

			ChangeCharacterAddressGroup(NPChar, "none", "", "");
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "Court_Martial":
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Keene"));
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Harvey"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Percy Buckland"));

			SetOfficersIndex(Pchar, 1, getCharacterIndex("Lt. Percy Buckland"));
			ChangeCharacterAddressGroup(characterFromID("Lt. Percy Buckland"), "REDMOND_PORT", "officers", "Sea_1_3");

			DoQuestReloadToLocation("REDMOND_PORT", "reload", "Sea_1_back", "Arrested_at_Redmond");

			ChangeCharacterAddressGroup(NPChar, "none", "", "");
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "French_Sea_Battle":
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Keene"));
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Harvey"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Percy Buckland"));

			GiveShip2Character(pchar,"HMS_Indefatigable","Indefatigable",-1,ENGLAND,true,true);
			SetCharacterShipLocation(Pchar, "Charlestown_port");
			DoQuestReloadToLocation("Charlestown_port", "reload", "Sea_1_back", "War_with_France");

			ChangeCharacterAddressGroup(NPChar, "none", "", "");
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "Fire_Ship":
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Keene"));
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Harvey"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Percy Buckland"));

			DoQuestReloadToLocation("Quest_FireShipDeck", "rld", "aloc4", "Fire_ship_main_deck");

			ChangeCharacterAddressGroup(NPChar, "none", "", "");
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "Mutiny":
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Keene"));
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Harvey"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Percy Buckland"));

			ChangeCharacterAddressGroup(characterFromID("William Chumley"), "Oxbay_port", "goto", "goto3");
			LAi_SetOfficerType(characterFromID("William Chumley"));
			DoQuestReloadToLocation("Oxbay_port", "reload", "Reload2_back", "wounded_to_Oxbay");

			ChangeCharacterAddressGroup(NPChar, "none", "", "");
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "New Characters":
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Keene"));
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Harvey"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Percy Buckland"));

//			SetModelfromArray(characterFromID("Ebenezer Bracegirdle"), GetModelIndex("BracegrdlC"));
//			Characters[GetCharacterIndex("Ebenezer Bracegirdle")].model = "h_BracegrdlC";
//			Characters[GetCharacterIndex("Ebenezer Bracegirdle")].headmodel = "h_BracegrdlC";
//			SetModelfromArray(characterFromID(""), GetModelIndex("BracegrdlC"));
//			Characters[GetCharacterIndex("Captain Murray")].headmodel = "h_Cmurray_Wound18";
//			SetModelfromArray(characterFromID("Captain Murray"), GetModelIndex("Cmurray_Wound18"));
//			Characters[GetCharacterIndex("Patrick Harper")].model = "Harper_Sergeant";
//			Characters[GetCharacterIndex("Patrick Harper")].headmodel = "h_Harper_Sergeant";
			Characters[GetCharacterIndex("Captain Murray")].model = "Cmurray_Wound18";
			Characters[GetCharacterIndex("Captain Murray")].headmodel = "h_Cmurray_Wound18";
			//Characters[GetCharacterIndex("Rifleman Harris")].model = "Rifleman95B3_18";
			//Characters[GetCharacterIndex("Rifleman Harris")].headmodel = "h_Rifleman95B3_18";

			//ChangeCharacterAddressGroup(characterFromID("Test Man"), "Antigua_port", "goto", "goto38");
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Captain Murray"));
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Black Charlie Hammond"));
//			SetOfficersIndex(Pchar, 2, getCharacterIndex("Patrick Harper"));
//			SetOfficersIndex(Pchar, 3, getCharacterIndex("Captain James Sawyer"));

			GiveModel2Player("CivilianHB", true);
			//LAi_SetOfficerType(characterFromID("Richard Sharpe"));

			ChangeCharacterAddressGroup(NPChar, "none", "", "");
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;
		
		case "Out_of_Spanish_Prison":
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Keene"));
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Harvey"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Percy Buckland"));

			Characters[GetCharacterIndex("Don Masseredo")].dialog.currentnode = "A_man_of_honour";
			DoQuestReloadToLocation("Havana_fakefort4", "rld", "loc2", "Back_in_Prison_from_Indy");

			ChangeCharacterAddressGroup(NPChar, "none", "", "");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Hunt_the_traitors":
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Keene"));
			RemoveCharacterCompanion(Pchar, characterFromID("Captain Harvey"));
			RemoveCharacterCompanion(Pchar, characterFromID("Lt. Percy Buckland"));

			SetModelfromArray(characterFromID("Richard Sharpe"), GetModelIndex("SharpeL_Rif7_18"));
			Characters[GetCharacterIndex("Richard Sharpe")].headmodel = "h_SharpeL_Rif7_18";
			Characters[GetCharacterIndex("Rifleman Mansfield")].model = "Rifleman95A3_18";
			Characters[GetCharacterIndex("Rifleman Mansfield")].headmodel = "h_Rifleman95A3_18";
			Characters[GetCharacterIndex("Patrick Harper")].model = "Harper_Sergeant";
			Characters[GetCharacterIndex("Patrick Harper")].headmodel = "h_Harper_Sergeant";
			Characters[GetCharacterIndex("Rifleman Haggman")].model = "Rifleman95B4_18";
			Characters[GetCharacterIndex("Rifleman Haggman")].headmodel = "h_Rifleman95B4_18";
			Characters[GetCharacterIndex("Rifleman Higgins")].model = "Rifleman95D3_18";
			Characters[GetCharacterIndex("Rifleman Higgins")].headmodel = "h_Rifleman95D3_18";
			Characters[GetCharacterIndex("Rifleman Tongue")].model = "Rifleman95F3_18";
			Characters[GetCharacterIndex("Rifleman Tongue")].headmodel = "h_Rifleman95F3_18";
			Characters[GetCharacterIndex("Rifleman Cooper")].model = "Rifleman95E3_18";
			Characters[GetCharacterIndex("Rifleman Cooper")].headmodel = "h_Rifleman95E3_18";
			Characters[GetCharacterIndex("Rifleman Harris")].model = "Rifleman95B3_18";
			Characters[GetCharacterIndex("Rifleman Harris")].headmodel = "h_Rifleman95B3_18";
			Characters[GetCharacterIndex("Rifleman Perkins")].model = "RiflemanPerk_18";
			Characters[GetCharacterIndex("Rifleman Perkins")].headmodel = "h_RiflemanPerk_18";

			SetOfficersIndex(Pchar, 1, getCharacterIndex("Lt. William Bush"));
			AddPassenger(Pchar, characterFromID("Matthews"), 0);
			AddPassenger(Pchar, characterFromID("Styles"), 0);

			Characters[GetCharacterIndex("Sir Edward Pellew")].model = "PellewA_18";
			Characters[GetCharacterIndex("Sir Edward Pellew")].headmodel = "h_PellewA_18";
			ChangeCharacterAddressGroup(characterFromID("Lt. Eccleston"), "Greenford Naval HQ", "sit", "sit1");
			LAi_ActorSetSitMode(characterFromID("Lt. Eccleston"));
			ChangeCharacterAddressGroup(characterFromID("Sir Edward Pellew"), "Greenford Naval HQ", "goto", "goto3")

			pchar.quest.Players_Rank = "Commander";
			SetRank(pchar, ENGLAND, 5);
			GiveModel2Player("brtHComdr_18", true);
			pchar.quest.story_path = "neutral";
			SetShipRemovable(pchar, true);
			ReceiveLetterOfMarque(ENGLAND);
			DeleteAttribute(PChar, "isnotcaptain");
			AddStorylineVar(FindCurrentStoryline(), "CHANGING_RELATIONS", "1");
			GiveShip2Character(pchar, "HMS_Greyhound", "Atropos", -1, ENGLAND, true, false);
			setCharacterShipLocation(Pchar, "Greenford_port");
			PChar.married = MR_MARRIED;
			PChar.married.id = "Maria Mason";

			SetNationRelationBoth(ENGLAND, FRANCE, RELATION_ENEMY);
			SetNationRelationBoth(ENGLAND, SPAIN, RELATION_ENEMY);
			SetRMRelation(PChar, FRANCE, REL_WAR);
			SetRMRelation(PChar, SPAIN, REL_WAR);

			DoQuestReloadToLocation("Greenford_port", "reload", "reload1", "wolfes_ship");
			
			ChangeCharacterAddressGroup(NPChar, "none", "", "");
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;
	}
}

