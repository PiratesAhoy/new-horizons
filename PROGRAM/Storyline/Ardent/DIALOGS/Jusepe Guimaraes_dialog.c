//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;
	string rank;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	int i, x, y, idx;
	ref sld, passenger;
	string passengerid, temp;
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Äèàëîã ïåðâûé - ïåðâàÿ âñòðå÷à
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
		break;

	
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			if(GetAttribute(NPChar, "meeting") == "1" && GetRank(PChar, SPAIN) >= 2) dialog.text = DLG_TEXT[25] + GetRankName(PChar, SPAIN) + " " + GetMyLastName(PChar) + "." + DLG_TEXT[1];
			else dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + "." + DLG_TEXT[1];
			
			if (CheckCharacterItem(PChar, "BattleOrders2"))
			{
				if (CheckAttribute(PChar, "quest.threat_governor_sent_me"))
				{
					link.l1 = DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[5] + GetMyFullName(CharacterFromID("Javier Balboa")) + DLG_TEXT[6];
				}
				else
				{
					link.l1 = DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[18];
				}
				link.l1.go = "show_battle_orders";
			}
			if (CheckAttribute(PChar, "quest.finale_governor_sent_me"))
			{
				link.l1 = DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[5] + GetMyFullName(CharacterFromID("Javier Balboa")) + DLG_TEXT[21];
				link.l1.go = "finale_no_defence";
			}
			if (CheckAttribute(PChar, "quest.imperial_escort_enable") && !CheckAttribute(PChar, "quest.imperial_escort") && GetRank(PChar, SPAIN) >= 5)
			{
				dialog.text = DLG_TEXT[26] + GetRankName(PChar, SPAIN) + " " + GetMyLastName(PChar) + DLG_TEXT[27];
				link.l2 = DLG_TEXT[28];
				link.l2.go = "imperial_escort_intro";
			}
			if (CheckAttribute(PChar, "quest.imperial_escort.failed_return_fleet") || CheckAttribute(PChar, "quest.imperial_escort.failed_grigorio_swap"))
			{
				link.l1 = DLG_TEXT[173] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[174];
				link.l1.go = "imperial_escort_merge_fleet_again";
			}
			if (CheckAttribute(PChar, "quest.imperial_escort.arrest_guzman") && sti(PChar.quest.imperial_escort.arrest_guzman) == true && LAi_IsDead(CharacterFromID("Emiliano de Guzmán")))
			{
				link.l1 = GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[179] + GetMyFullName(CharacterFromID("Emiliano de Guzmán")) + DLG_TEXT[180];
				link.l1.go = "imperial_escort_arrest_guzman_complete";
			}
			if (Characters[GetCharacterIndex("Gilles Clouzot")].location == "Muelle_port" && !CheckAttribute(PChar, "quest.imperial_escort.spy_search"))
			{
				link.l2 = DLG_TEXT[185] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[186];
				link.l2.go = "imperial_escort_find_spy";
			}
			link.l10 = DLG_TEXT[2] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[3];
			link.l10.go = "Exit";
		break;

		case "show_battle_orders":
			NPChar.meeting = "1";
			if (CheckAttribute(PChar, "quest.ardent_treachery_status")) DeleteQuestAttribute("ardent_treachery_status");
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			TakeItemFromCharacter(Pchar, "BattleOrders2");
			if (HasRank(PChar, SPAIN)) rank = GetRankName(PChar, SPAIN);
			else rank = XI_ConvertString("captain");

			if (CheckAttribute(PChar, "quest.threat_governor_sent_me"))
			{
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneytoCharacter(PChar, 5000);
				Preprocessor_Add("person", XI_ConvertString(PChar.sex));
				dialog.text = DLG_TEXT[7] + DLG_TEXT[8] + DLG_TEXT[11];	// Leads to mission which will lead to finale
				DeleteQuestAttribute("threat_governor_sent_me");
			}
			else
			{
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneytoCharacter(PChar, 5000);
				Preprocessor_Add("person", XI_ConvertString(PChar.sex));
				dialog.text = DLG_TEXT[19] + rank + DLG_TEXT[20] + DLG_TEXT[8] + DLG_TEXT[11];
			}
			link.l1 = DLG_TEXT[12];
			link.l1.go = "propose_mission";
		break;

		case "propose_mission":
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			if(CheckAttribute(PChar, "quest.finale_galleons") || GetCompanionQuantity(PChar) > COMPANION_MAX-2)
			{
				dialog.text = DLG_TEXT[13];
			}
			else
			{
				PChar.quest.finale_assign_galleons = "true";
				dialog.text = DLG_TEXT[13] + DLG_TEXT[14];
				AddDialogExitQuest("finale_assign_galleons");
				PChar.quest.finale_galleons_assigned_by = "Jusepe Guimaraes";
			}
			Diag.TempNode = "why_still_here";
			link.l1 = DLG_TEXT[15] + GetRankName(NPChar, sti(NPChar.nation)) + ".";
			link.l1.go = "exit_finale_accept_mission";
//			link.l2 = DLG_TEXT[16];
//			link.l2.go = "exit";
		break;

		case "finale_no_defence":
			NPChar.meeting = "1";
			DeleteQuestAttribute("finale_governor_sent_me");
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "finale_propose_mission";
		break;

		case "finale_propose_mission":
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			if(CheckAttribute(PChar, "quest.finale_galleons") || GetCompanionQuantity(PChar) > COMPANION_MAX-2)
			{
				dialog.text = DLG_TEXT[24];
			}
			else
			{
//				PChar.quest.finale_assign_galleons = "true";
				dialog.text = DLG_TEXT[24] + DLG_TEXT[14];
				AddDialogExitQuest("finale_assign_galleons");
				PChar.quest.finale_galleons_assigned_by = "Jusepe Guimaraes";
			}
			Diag.TempNode = "why_still_here";
			link.l1 = DLG_TEXT[15] + GetRankName(NPChar, sti(NPChar.nation)) + ".";
			link.l1.go = "exit_finale_accept_mission";
		break;

		case "why_still_here":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[2] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[3];
			link.l1.go = "Exit";
		break;

		case "exit_threat_accept_mission":
			Preprocessor_AddQuestData("target", FindTownName("Santiago"));
			AddQuestRecord("Santiago Threat", 6);
			CloseQuestHeader("Santiago Threat");
			Preprocessor_Remove("target");
			AddDialogExitQuest("finale_santiago_evacuation_setup");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "exit_finale_accept_mission":
			if (CheckAttribute(PChar, "Santiago Threat")) CloseQuestHeader("Santiago Threat");
			if (!CheckAttribute(PChar, "QuestInfo.Battle Royale")) SetQuestHeader("Battle Royale");
			Preprocessor_AddQuestData("admiral", GetMyFullName(NPChar));
			Preprocessor_AddQuestData("target", FindTownName("Santiago"));
			AddQuestRecord("Battle Royale", 23);
			Preprocessor_Remove("target");
			Preprocessor_Remove("admiral");
			AddDialogExitQuest("finale_santiago_evacuation_setup");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "imperial_escort_intro":
			NPChar.meeting = "1";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "imperial_escort_youre_recommended";
		break;

		case "imperial_escort_youre_recommended":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "imperial_escort_choice";
		break;

		case "imperial_escort_choice":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "imperial_escort_accept";
			link.l2 = DLG_TEXT[35];
			link.l2.go = "imperial_escort_reject";
		break;

		case "imperial_escort_reject":
			PChar.quest.imperial_escort = "rejected";
			dialog.text = DLG_TEXT[36] + GetMyLastName(CharacterFromID("Javier Balboa")) + DLG_TEXT[37];
			link.l1 = DLG_TEXT[39] + GetRankName(NPChar, sti(NPChar.nation)) + ".";
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[38];
			link.l2.go = "imperial_escort_accept";
		break;

		case "imperial_escort_accept":
			PChar.quest.imperial_escort.status = "mission_accepted";
			dialog.text = DLG_TEXT[40] + Characters[GetCharacterIndex("Imperial_Captain")].Ship.Name + DLG_TEXT[41] + GetMyFullName(CharacterFromID("Imperial_Captain")) + DLG_TEXT[42] + GetRankName(CharacterFromID("Imperial_Captain"), SPAIN) + " " + GetMyLastName(CharacterFromID("Imperial_Captain")) + DLG_TEXT[43];
			link.l1 = DLG_TEXT[44] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[45] + ".";
			AddDialogExitQuest("imperial_escort_to_sanjuan");
			link.l1.go = "exit";
		break;

		case "imperial_escort_execution":
			dialog.text = DLG_TEXT[46] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "imperial_escort_execution2";
		break;

		case "imperial_escort_execution2":
			dialog.text = DLG_TEXT[49] + GetMyLastName(CharacterFromID("Javier Balboa")) + DLG_TEXT[50];
			link.l1 = "...";
			link.l1.go = "exit";
		break;

		case "imperial_escort_envoy_taken":
			dialog.text = DLG_TEXT[51] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "imperial_escort_youre_not_searching";
		break;

		case "imperial_escort_youre_not_searching":
			dialog.text = DLG_TEXT[54] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			ChangeCharacterAddressGroup(CharacterFromID("Imperial_Captain"), "Havana_prison", "goto", "goto11");
			LAi_SetCitizenType(characterFromID("Imperial_Captain"));
			AddDialogExitQuest("imperial_escort_bad_stuff_arrested2");
			link.l1.go = "exit";
		break;

		case "imperial_escort_ship_missing":
			dialog.text = DLG_TEXT[25] + GetRankName(PChar, SPAIN) + " " + GetMyLastName(PChar) + DLG_TEXT[57] + GetMyFullName(CharacterFromID("Imperial_envoy")) + "?";
			link.l1 = DLG_TEXT[58] + PChar.quest.imperial_escort.ship_name + DLG_TEXT[59];
			link.l1.go = "imperial_escort_ship_missing2";
		break;

		case "imperial_escort_ship_missing2":
			dialog.text = DLG_TEXT[60] + PChar.quest.imperial_escort.ship_name + DLG_TEXT[61];
			link.l1 = DLG_TEXT[62] + GetMyLastName(CharacterFromID("Imperial_Captain")) + DLG_TEXT[63];
			link.l1.go = "imperial_escort_ship_missing3";
		break;

		case "imperial_escort_ship_missing3":
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65] + PChar.quest.imperial_escort.ship_name + DLG_TEXT[66];
			link.l1.go = "imperial_escort_ship_missing4";
		break;

		case "imperial_escort_ship_missing4":
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			AddDialogExitQuest("imperial_escort_bad_stuff_arrested2");
			link.l1.go = "exit";
		break;

		case "imperial_escort_development":
			dialog.text = DLG_TEXT[69] + GetMyLastName(PChar) + ".";
			link.l1 = DLG_TEXT[70] + GetMyFullName(CharacterFromID("Imperial_envoy")) + "?";
			link.l1.go = "imperial_escort_new_evidence";
		break;

		case "imperial_escort_new_evidence":
			if (CheckQuestAttribute("imperial_escort.status", "ship_missing")) dialog.text = DLG_TEXT[71] + PChar.quest.imperial_escort.ship_name + DLG_TEXT[72];
			else dialog.text = DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "imperial_escort_mistakes";
		break;

		case "imperial_escort_mistakes":
			dialog.text = DLG_TEXT[75] + GetMyFullName(CharacterFromID("Javier Balboa")) + DLG_TEXT[76] + GetMyName(CharacterFromID("Javier Balboa")) + DLG_TEXT[77] + GetMyName(CharacterFromID("Javier Balboa")) + DLG_TEXT[78] + GetMyLastName(PChar) + ".";
			link.l1 = DLG_TEXT[79];
			link.l1.go = "exit";
		break;

		case "imperial_escort_youre_back":
			dialog.text = DLG_TEXT[80] + GetMyLastName(PChar) + DLG_TEXT[81];
			link.l1 = DLG_TEXT[82] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[83] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[84];
			link.l1.go = "imperial_escort_do_you_believe";
		break;

		case "imperial_escort_do_you_believe":
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "imperial_escort_we_have_ransom_demand";
		break;

		case "imperial_escort_we_have_ransom_demand":
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "imperial_escort_whodunnit";
		break;

		case "imperial_escort_whodunnit":
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[91] + GetMyFullName(CharacterFromID("Javier Balboa")) + DLG_TEXT[92] + GetMyFullName(CharacterFromID("Emiliano de Guzmán")) + DLG_TEXT[93];
			link.l1.go = "imperial_escort_replaced_governor";
		break;

		case "imperial_escort_replaced_governor":
			dialog.text = DLG_TEXT[94];
			link.l1 = DLG_TEXT[95];
			link.l1.go = "imperial_escort_why_believe";
		break;

		case "imperial_escort_why_believe":
			dialog.text = DLG_TEXT[96] + GetMyName(CharacterFromID("Emiliano de Guzmán")) + DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "exit";
		break;

		case "imperial_escort_good_case":
			dialog.text = DLG_TEXT[99] + GetMyLastName(PChar) + DLG_TEXT[100];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "imperial_escort_that_seems_fair":
			string ships;
			if (sti(PChar.quest.imperial_escort.original_companions_number) == 0) ships = DLG_TEXT[106];
			else ships = DLG_TEXT[107];

			dialog.text = DLG_TEXT[101] + DLG_TEXT[102] + GetMyFullName(CharacterFromID("Emiliano de Guzmán")) + DLG_TEXT[103] + GetMyFullName(CharacterFromID("Javier Balboa")) + DLG_TEXT[104] + GetMyFullName(PChar) + DLG_TEXT[105] + ships + DLG_TEXT[108];
			if(LAi_IsDead(CharacterFromID("Emiliano de Guzmán")))
			{
				link.l1 = DLG_TEXT[115] + GetMyFullName(CharacterFromID("Emiliano de Guzmán")) + DLG_TEXT[116];
				AddDialogExitQuest("imperial_escort_restore_santiago_governor");
				link.l1.go = "exit";
			}
			else
			{
				link.l1 = GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[110] + GetMyFullName(CharacterFromID("Emiliano de Guzmán")) + DLG_TEXT[111];
				link.l1.go = "imperial_escort_arrest_guzman";
			}
		break;

		case "imperial_escort_arrest_guzman":
			dialog.text = DLG_TEXT[112];
			link.l1 = DLG_TEXT[113] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[114];
			AddDialogExitQuest("imperial_escort_go_get_guzman");
			link.l1.go = "exit";
		break;

		case "imperial_escort_deny_galleon":
			dialog.text = DLG_TEXT[117];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "imperial_escort_flattered":
			dialog.text = DLG_TEXT[118];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "imperial_escort_find_new_ship":
			dialog.text = DLG_TEXT[119];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "imperial_escort_payment":
			dialog.text = DLG_TEXT[120] + GetRankName(PChar, sti(NPChar.nation)) + " " + GetMyLastName(PChar) + DLG_TEXT[121] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[122];
			link.l1 = DLG_TEXT[123];
			link.l1.go = "imperial_escort_half_pay";
			link.l2 = DLG_TEXT[124];
			link.l2.go = "imperial_escort_no_pay";
		break;

		case "imperial_escort_half_pay":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(PChar, 25000);
			dialog.text = DLG_TEXT[125] + GetRankName(PChar, sti(NPChar.nation)) + DLG_TEXT[126];
			link.l1 = DLG_TEXT[127] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[128];
			link.l1.go = "imperial_escort_grigorio_ship";
		break;

		case "imperial_escort_no_pay":
			dialog.text = DLG_TEXT[129] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[130];
			link.l1 = DLG_TEXT[131];
			link.l1.go = "imperial_escort_grigorio_ship";
		break;

		case "imperial_escort_grigorio_ship":
			dialog.text = DLG_TEXT[132] + GetMyFullName(CharacterFromID("Grigorio Formoselle")) + DLG_TEXT[133];
			if (PChar.quest.rescuer == "Grigorio Formoselle") link.l1 = GetMyFullName(CharacterFromID("Grigorio Formoselle")) + DLG_TEXT[135];
			else link.l1 = DLG_TEXT[134];
			link.l1.go = "imperial_escort_grigorio_ship2";
		break;

		case "imperial_escort_grigorio_ship2":
			if(PChar.quest.imperial_escort.grigorio_ship != "None")
			{
				dialog.text = DLG_TEXT[136] + GetMyAddressForm(NPChar, CharacterFromID("Grigorio Formoselle"), ADDR_CIVIL, false, true) + DLG_TEXT[137] + DLG_TEXT[138] + Characters[GetCharacterIndex("Grigorio Formoselle")].Ship.Name + DLG_TEXT[139];
				link.l1 = DLG_TEXT[140];
				link.l1.go = "imperial_escort_merge_fleet";
			}
			else
			{
				dialog.text = DLG_TEXT[136] + GetMyAddressForm(NPChar, CharacterFromID("Grigorio Formoselle"), ADDR_CIVIL, false, true) + DLG_TEXT[137] + DLG_TEXT[141];
				if (sti(PChar.money) >= 18500)
				{
					link.l1 = DLG_TEXT[142] + GetMyAddressForm(NPChar, CharacterFromID("Grigorio Formoselle"), ADDR_CIVIL, false, true) + DLG_TEXT[143];
					link.l1.go = "imperial_escort_merge_fleet";
				}
				else
				{
					link.l1 = DLG_TEXT[144];
					link.l1.go = "imperial_escort_cant_pay";
				}
			}
		break;

		case "imperial_escort_cant_pay":
			dialog.text = DLG_TEXT[145];
			link.l1 = DLG_TEXT[146] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[147] + GetMyAddressForm(NPChar, CharacterFromID("Grigorio Formoselle"), ADDR_CIVIL, false, true) + DLG_TEXT[143];
			link.l1.go = "imperial_escort_merge_fleet";
		break;

		case "imperial_escort_merge_fleet":
			if (GetCharacterShipID(PChar) == SHIP_NOTUSED_TYPE_NAME)		// You have no ship.  Either you sold your own ship, or you sold or berthed your whole fleet
			{
				if (PChar.quest.imperial_escort.grigorio_ship == "None")	// Nobody has Grigorio's barque. You get a barque which can then be swapped to Grigorio to get your original flagship back
				{
					GiveShip2Character(PChar, "Barque1", "Mayordomo", -1, SPAIN, true, true);
				}
				else								// Someone else has Grigorio's barque. Swap it to you, remove that officer as a companion and add as a passenger.
				{
					sld = CharacterFromID(PChar.quest.imperial_escort.grigorio_ship);
					ExchangeCharacterShip(PChar, sld);
					DeleteAttribute(sld, "Ship");
					sld.Ship.Type = SHIP_NOTUSED_TYPE_NAME;
					sld.Ship.Name = "";
					RemoveCharacterCompanion(PChar, sld);
					AddPassenger(PChar, sld, 0);
				}
				PChar.quest.imperial_escort.grigorio_ship = PChar.id;
			}
			if (PChar.quest.imperial_escort.grigorio_ship != "None")
			{
				ExchangeCharacterShip(CharacterFromID(PChar.quest.imperial_escort.grigorio_ship), CharacterFromID("Grigorio Formoselle"));
				Preprocessor_Add("flagship", Characters[GetCharacterIndex(PChar.quest.imperial_escort.grigorio_ship)].ship.name);
				if (PChar.quest.imperial_escort.grigorio_ship == PChar.id) dialog.text = DLG_TEXT[148];
				else dialog.text = GetMyFullName(CharacterFromID(PChar.quest.imperial_escort.grigorio_ship)) + DLG_TEXT[149];
			}
			else
			{
				if (sti(PChar.money) >= 18500)
				{
					PlayStereoSound("INTERFACE\took_item.wav");
					AddMoneytoCharacter(PChar, -18500);
				}
				if (PChar.quest.imperial_escort.galleon == "None" || sti(PChar.quest.imperial_escort.keep_galleon) == true)
				{
					passengerid = "None";
					if (GetPassengersQuantity(PChar) > 0)
					{
						for(i = 0; i < GetPassengersQuantity(PChar); i++)
						{
							idx = GetPassenger(PChar, i);
							passenger = GetCharacter(idx);
							if (CheckAttribute(passenger, "id") && GetRemovable(passenger) && !IsPrisoner(passenger) && !IsCompanion(passenger) && passenger.id != PChar.id)
							{
								passengerid = passenger.id;
							}
						}
					}

					if (passengerid == "None")
					{
						passengerid = "Spanish_Captain3";	// Re-use the captain of the snow brig stolen near the start of the story
						passenger = CharacterFromID(passengerid);
						SetRandomNameToCharacter(passenger);
						GiveItem2Character(passenger,"blade16");
						EquipCharacterByItem(passenger,"blade16");
						passenger.dialog.Filename = "Enc_Officer_dialog.c";
						passenger.dialog.CurrentNode = "hired";
						PChar.quest.imperial_envoy.new_officer = true;
					}
					else
					{
						passenger = CharacterFromID(passengerid);
						if (IsOfficer(passenger)) RemoveOfficersIndex(PChar, idx);
						RemovePassenger(PChar, passenger);
					}
					ExchangeCharacterShip(passenger, CharacterFromID("Grigorio Formoselle"));
					GiveShip2Character(CharacterFromID("Grigorio Formoselle"), "Barque1", "Mayordomo", -1, SPAIN, true, true);
					PChar.quest.imperial_escort.grigorio_ship = passengerid;
					idx = GetCharacterIndex(passengerid);
					if (SetCompanionIndex(PChar, -1, idx) == idx)
					{
						if (HasSubStr(passengerid, "Enc_Officer")) LAi_StoreFantom(passenger); // Prevent character from being overwritten by another "Enc_Officer"
						PChar.quest.imperial_escort.failed_grigorio_swap = true;
					}
					Preprocessor_Add("flagship", Characters[GetCharacterIndex(PChar.quest.imperial_escort.grigorio_ship)].ship.name);
					if (PChar.quest.imperial_escort.grigorio_ship == "Spanish_Captain3")
					{
						if (CheckAttribute(PChar, "quest.imperial_escort.failed_grigorio_swap")) dialog.text = DLG_TEXT[150] + GetMyFullName(CharacterFromID(PChar.quest.imperial_escort.grigorio_ship)) + DLG_TEXT[152] + DLG_TEXT[153];
						else dialog.text = DLG_TEXT[150] + GetMyFullName(CharacterFromID(PChar.quest.imperial_escort.grigorio_ship)) + DLG_TEXT[152];
					}
					else
					{
						if (CheckAttribute(PChar, "quest.imperial_escort.failed_grigorio_swap")) dialog.text = DLG_TEXT[150] + GetMyFullName(CharacterFromID(PChar.quest.imperial_escort.grigorio_ship)) + DLG_TEXT[151] + DLG_TEXT[153];
						else dialog.text = DLG_TEXT[150] + GetMyFullName(CharacterFromID(PChar.quest.imperial_escort.grigorio_ship)) + DLG_TEXT[151];
					}
				}
				else
				{
					Preprocessor_Add("galleon", Characters[GetCharacterIndex(PChar.quest.imperial_escort.galleon)].ship.name);
					PChar.quest.imperial_escort.grigorio_ship = PChar.quest.imperial_escort.galleon;
					PChar.quest.imperial_escort.galleon = "None";
					ExchangeCharacterShip(CharacterFromID(PChar.quest.imperial_escort.grigorio_ship), CharacterFromID("Grigorio Formoselle"));
					GiveShip2Character(CharacterFromID("Grigorio Formoselle"), "Barque1", "Mayordomo", -1, SPAIN, true, true);
					Preprocessor_Add("flagship", Characters[GetCharacterIndex(PChar.quest.imperial_escort.grigorio_ship)].ship.name);
					if (PChar.quest.imperial_escort.grigorio_ship == PChar.id) dialog.text = DLG_TEXT[154];
					else dialog.text = GetMyFullName(CharacterFromID(PChar.quest.imperial_escort.grigorio_ship)) + DLG_TEXT[155];
				}
			}

			if (PChar.quest.imperial_escort.galleon != "None" && CheckAttribute(PChar, "quest.imperial_escort.keep_galleon") && sti(PChar.quest.imperial_escort.keep_galleon) == false)
			{									// Someone still has the galleon and you chose to decline to keep it, which should only happen if someone else had Grigorio's ship and now has your original flagship.
				if (PChar.quest.imperial_escort.galleon == PChar.id)
				{								// You personally have the galleon.  Swap with whoever got your original flagship.
					Preprocessor_Add("galleon", PChar.ship.name);
					Preprocessor_Add("flagship", Characters[GetCharacterIndex(PChar.quest.imperial_escort.grigorio_ship)].ship.name);
					dialog.text = DLG_TEXT[156];
					ExchangeCharacterShip(PChar, CharacterFromID(PChar.quest.imperial_escort.grigorio_ship));
					PChar.quest.imperial_escort.galleon = PChar.quest.imperial_escort.grigorio_ship;
					PChar.quest.imperial_escort.grigorio_ship = PChar.id;
				}
				sld = CharacterFromID(PChar.quest.imperial_escort.galleon);	// Remove galleon from whoever has it.
				DeleteAttribute(sld, "Ship");
				sld.Ship.Type = SHIP_NOTUSED_TYPE_NAME;
				sld.Ship.Name = "";
				RemoveCharacterCompanion(PChar, sld);
				AddPassenger(PChar, sld, 0);
				PChar.quest.imperial_escort.galleon = "None";
			}
			link.l1 = DLG_TEXT[157];
			link.l1.go = "imperial_escort_merge_fleet2";
		break;

		case "imperial_escort_merge_fleet2":
			x = sti(PChar.quest.imperial_escort.original_companions_number);
//			if (CheckAttribute(PChar, "quest.imperial_escort.failed_grigorio_swap")) x++;
			y = GetCompanionQuantity(PChar) - 1;
			string ship_quantity = DLG_TEXT[163];
			if (y == 0) ship_quantity = DLG_TEXT[162];
			if (x == 0)	// You had only your own ship when you were arrested, and that has either been returned to you or can not be returned as you currently have a full size fleet
			{
				if (CheckAttribute(PChar, "quest.imperial_escort.failed_grigorio_swap")) dialog.text = DLG_TEXT[158] + DLG_TEXT[165];
				else dialog.text = DLG_TEXT[158] + DLG_TEXT[164];
			}
			else		// You had additional ships when you were arrested
			{
				if (CheckAttribute(PChar, "quest.imperial_escort.failed_grigorio_swap")) dialog.text = DLG_TEXT[158] + (x+1) + DLG_TEXT[160];
				else dialog.text = DLG_TEXT[158] + (x+1) + DLG_TEXT[159];
				dialog.text = dialog.text + DLG_TEXT[161] + (y+1) + ship_quantity;
				if (CheckAttribute(PChar, "quest.imperial_escort.failed_grigorio_swap") || (x + y + 1) > COMPANION_MAX)		// Too many ships, can't merge fleets
				{
					if (CheckAttribute(PChar, "quest.imperial_escort.failed_grigorio_swap") && x+1 == COMPANION_MAX)	// Original fleet was maximum size and the flagship has not been returned
					{
						dialog.text = dialog.text + "\n" + DLG_TEXT[168];
						AddQuestRecord("Imperial Escort", 46);						// Need to sell or berth entire current fleet!
					}
					else
					{
						dialog.text = dialog.text + "\n" + DLG_TEXT[167];
						AddQuestRecord("Imperial Escort", 45);
					}
					PChar.quest.imperial_escort.failed_return_fleet = true;
					link.l1 = DLG_TEXT[171] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[172];
				}
				else
				{
					dialog.text = dialog.text + DLG_TEXT[166];
					for (i=1; i<COMPANION_MAX; i++)
					{
						temp = "companion" + i;
						if (PChar.quest.imperial_escort.(temp) != "*NULL*")
						{
							idx = GetCharacterIndex(PChar.quest.imperial_escort.(temp));
							SetCompanionIndex(PChar,-1, idx)
							if (HasSubStr(PChar.quest.imperial_escort.(temp), "Enc_Officer")) LAi_UnStoreFantom(CharacterFromID(PChar.quest.imperial_escort.(temp))); // Cancel protection
						}
					}
					if (CheckAttribute(PChar, "quest.imperial_escort.failed_return_fleet")) DeleteQuestAttribute("imperial_escort.failed_return_fleet");	// This piece of dialog may have been triggered from "imperial_escort_merge_fleet_again", which was triggered if "imperial_escort.failed_return_fleet" was previously set
					link.l1 = DLG_TEXT[169] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[170];
				}

			}
			Preprocessor_Add("flagship", Characters[GetCharacterIndex(PChar.quest.imperial_escort.grigorio_ship)].ship.name);
			link.l1.go = "exit";
		break;

		case "imperial_escort_merge_fleet_again":
			if (CheckAttribute(PChar, "quest.imperial_escort.failed_grigorio_swap"))	// You originally did not have either Grigorio's ship or the galleon, so your flagship was assigned either to one of your officers or to "Spanish_Captain3"
			{										// And you had a full fleet so the flagship could not be given to you
				if (GetCompanionQuantity(PChar) >= COMPANION_MAX)			// You still have a full fleet, so you're still not getting the flagship back
				{
					dialog.text = DLG_TEXT[175];
					link.l1 = DLG_TEXT[171] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[172];
					link.l1.go = "exit";
				}
				else								// You don't have a full fleet so there's a free slot for the flagship
				{
					if (GetCharacterShipID(PChar) == SHIP_NOTUSED_TYPE_NAME)		// You have no ship.  Either you sold your own ship, or you sold or berthed your whole fleet
					{
						if (PChar.quest.imperial_escort.grigorio_ship == "None")	// Nobody has Grigorio's barque. You get a barque which can then be swapped to Grigorio to get your original flagship back
						{
							GiveShip2Character(PChar, "Barque1", "Mayordomo", -1, SPAIN, true, true);
						}
						else								// Someone else has Grigorio's barque. Swap it to you, remove that officer as a companion and add as a passenger.
						{
							sld = CharacterFromID(PChar.quest.imperial_escort.grigorio_ship);
							ExchangeCharacterShip(PChar, sld);
							DeleteAttribute(sld, "Ship");
							sld.Ship.Type = SHIP_NOTUSED_TYPE_NAME;
							sld.Ship.Name = "";
							RemoveCharacterCompanion(PChar, sld);
							AddPassenger(PChar, sld, 0);
						}
						PChar.quest.imperial_escort.grigorio_ship = PChar.id;
					}
					else
					{
						sld = CharacterFromID(PChar.quest.imperial_escort.grigorio_ship);
						idx = GetCharacterIndex(PChar.quest.imperial_escort.grigorio_ship);
						SetCompanionIndex(PChar, -1, idx);
					}
					Preprocessor_Add("flagship", Characters[GetCharacterIndex(PChar.quest.imperial_escort.grigorio_ship)].ship.name);
					if (PChar.quest.imperial_escort.grigorio_ship == "Spanish_Captain3")
					{
						dialog.text = DLG_TEXT[150] + GetMyFullName(CharacterFromID(PChar.quest.imperial_escort.grigorio_ship)) + DLG_TEXT[152];
					}
					else
					{
						if (PChar.quest.imperial_escort.grigorio_ship == PChar.id) dialog.text = DLG_TEXT[210];
						else dialog.text = DLG_TEXT[150] + GetMyFullName(CharacterFromID(PChar.quest.imperial_escort.grigorio_ship)) + DLG_TEXT[151];
					}
					DeleteQuestAttribute("imperial_escort.failed_grigorio_swap");
					link.l1 = DLG_TEXT[157];
					link.l1.go = "imperial_escort_merge_fleet2";
				}
			}
			else
			{
				dialog.text = DLG_TEXT[176] + GetRankName(PChar, sti(NPChar.nation)) + DLG_TEXT[177];
				link.l1 = DLG_TEXT[157];
				link.l1.go = "imperial_escort_merge_fleet2";
			}
		break;

		case "imperial_escort_arrest_guzman_complete":
			DeleteAttribute(PChar, "quest.imperial_escort.arrest_guzman");
			AddDialogExitQuest("imperial_escort_restore_santiago_governor");
			dialog.text = DLG_TEXT[181] + "\n" + GetMyFullName(CharacterFromID("Javier Balboa")) + DLG_TEXT[182];
			if (CheckAttribute(PChar, "quest.imperial_escort.failed_return_fleet") || CheckAttribute(PChar, "quest.imperial_escort.failed_grigorio_swap"))
			{
				link.l1 = DLG_TEXT[173] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[174];
				link.l1.go = "imperial_escort_merge_fleet_again";
			}
			link.l2 = DLG_TEXT[183] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[184];
			link.l2.go = "exit";
		break;

		case "imperial_escort_find_spy":
			dialog.text = DLG_TEXT[187];
			link.l1 = DLG_TEXT[188];
			link.l1.go = "imperial_escort_find_spy2";
		break;

		case "imperial_escort_find_spy2":
			dialog.text = DLG_TEXT[189] + GetRankName(PChar, sti(NPChar.nation)) + DLG_TEXT[190];
			link.l1 = DLG_TEXT[191]
			link.l1.go = "imperial_escort_find_spy3";
		break;

		case "imperial_escort_find_spy3":
			dialog.text = DLG_TEXT[192];
			link.l1 = DLG_TEXT[193] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[194];
			AddDialogExitQuest("imperial_escort_go_get_spy");
			link.l1.go = "exit";
		break;

		case "imperial_escort_spy_result":
			dialog.text = DLG_TEXT[195] + GetRankName(PChar, sti(NPChar.nation)) + DLG_TEXT[196];
			link.l1 = DLG_TEXT[197] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[198];
			link.l1.go = "exit";
			if (CheckQuestAttribute("imperial_escort.spy_search", "spy_dead_ashore"))
			{
				link.l1 = DLG_TEXT[199] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[200] + GetMyFullName(CharacterFromID("Gilles Clouzot")) + DLG_TEXT[201] + GetMyFullName(CharacterFromID("Uasco Mazinho")) + DLG_TEXT[202] + GetMySimpleName(CharacterFromID("Uasco Mazinho")) + DLG_TEXT[203] + GetMySimpleName(CharacterFromID("Gilles Clouzot")) + DLG_TEXT[204];
				link.l1.go = "imperial_escort_spy_reward";
			}
			if (CheckQuestAttribute("imperial_escort.spy_search", "spy_dead_aboard"))
			{
				link.l1 = DLG_TEXT[199] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[200] + GetMyFullName(CharacterFromID("Gilles Clouzot")) + DLG_TEXT[201] + GetMyFullName(CharacterFromID("Uasco Mazinho")) + DLG_TEXT[205];
				link.l1.go = "imperial_escort_spy_reward";
			}
		break;

		case "imperial_escort_spy_reward":
			dialog.text = DLG_TEXT[206] + GetMyFullName(CharacterFromID("Gilles Clouzot")) + DLG_TEXT[207];
			link.l1 = DLG_TEXT[208] + GetRankName(NPChar, sti(NPChar.nation)) + DLG_TEXT[209];
			AddDialogExitQuest("imperial_escort_spy_reward");
			link.l1.go = "exit";
		break;
	}
}