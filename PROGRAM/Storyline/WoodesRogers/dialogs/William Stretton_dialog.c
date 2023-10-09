//#include "DIALOGS\gunner Ben Gunn_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"


void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\PADI\PADI001";
						
			if(CheckAttribute(Pchar,"quest.med_Gunn") && Pchar.quest.med_Gunn == "prepare_explosion")
			{
				if(CheckCharacterItem(Pchar,"pistolmdchest_F3B") || CheckCharacterItem(Pchar,"pistolmdchest_F3B_C") 
					|| CheckCharacterItem(Pchar,"pistolmdchest_F3B_S") || CheckCharacterItem(Pchar,"pistolmdchest_F3B_CS") )
				{
					if(CheckCharacterItem(Pchar,"filled_large_drawer"))
					{
						PlaySound("VOICE\ENGLISH\Eng_m_b_083.wav");
						Dialog.text = DLG_TEXT[23];
						link.l1 = DLG_TEXT[24];
						link.l1.go = "prepare_explosion1";
					}
					else
					{
						PlaySound("VOICE\ENGLISH\Eng_m_b_059.wav");
						Dialog.text = DLG_TEXT[36];
						link.l1 = DLG_TEXT[37];
						link.l1.go = "exit";
					}
				}
				else
				{
					PlaySound("VOICE\ENGLISH\Eng_m_b_059.wav");
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "exit";
				}
			}
			else
			{
				PlaySound("VOICE\ENGLISH\Eng_m_b_059.wav");
				Dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}

			Diag.TempNode = "first time";
		break;

		case "sorry":
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;
	
		case "gunner":
			PlaySound("VOICE\ENGLISH\Eng_m_b_059.wav");
			Dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "gunner2";
		break;
	
		case "gunner2":
			Dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "gunner3";
		break;
		
		case "gunner3":
			Dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];

			int curcal = sti(GetCannonCaliber(GetCaracterShipCannonsType(Pchar)));	
			int maxcal = GetMaximumCaliber(Pchar);

			if(curcal < maxcal)
			{
				int upgr = 1;
				//Log_SetStringToLog("Cannons have been upgraded");
				
				if(USE_REAL_CANNONS)
				{
					if(maxcal == 32) Pchar.ship.Cannons.Type = CANNON_TYPE_LONG_LBS32;
					if(maxcal == 24) Pchar.ship.Cannons.Type = CANNON_TYPE_LONG_LBS24;
					if(maxcal == 18) Pchar.ship.Cannons.Type = CANNON_TYPE_LONG_LBS18;
					if(maxcal == 12) Pchar.ship.Cannons.Type = CANNON_TYPE_LONG_LBS12;
					if(maxcal == 9) Pchar.ship.Cannons.Type = CANNON_TYPE_LONG_LBS9;
					if(maxcal == 6) Pchar.ship.Cannons.Type = CANNON_TYPE_LONG_LBS6;
					if(maxcal == 4) Pchar.ship.Cannons.Type = CANNON_TYPE_LONG_LBS4;
					if(maxcal == 0) Pchar.ship.Cannons.Type = CANNON_TYPE_NONECANNON;
				}
				else
				{
					if(maxcal == 32) Pchar.ship.Cannons.Type = CANNON_TYPE_CANNON_LBS32;
					if(maxcal == 24) Pchar.ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS24;
					if(maxcal == 16) Pchar.ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS16;
					if(maxcal == 12) Pchar.ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS12;
					if(maxcal == 0) Pchar.ship.Cannons.Type = CANNON_TYPE_NONECANNON;
				}
			}
			
			
			int curcan = GetCannonCurQuantity(Pchar);
			int maxcan = GetMaxCannonQuantity(Pchar);

			if(curcan < maxcan) 
			{
				int rpr = 1;
				//Log_SetStringToLog("Cannons have been repaired");
				ResetCannons(Pchar);
			}
								
			int balls1 = GetSquadronGoods(Pchar, GOOD_BALLS);
			int grapes1 = GetSquadronGoods(Pchar, GOOD_GRAPES);
			int chains1 = GetSquadronGoods(Pchar, GOOD_KNIPPELS);
				
			RemoveCharacterGoods(Pchar, GOOD_BALLS, makeint(makefloat(GetCannonQuantity(Pchar)) * BALLS_PER));
			RemoveCharacterGoods(Pchar, GOOD_GRAPES, makeint(makefloat(GetCannonQuantity(Pchar)) * GRAPE_PER));
			RemoveCharacterGoods(Pchar, GOOD_KNIPPELS, makeint(makefloat(GetCannonQuantity(Pchar)) * CHAIN_PER));
			AddCharacterGoods(Pchar, GOOD_BALLS, makeint(makefloat(GetCannonQuantity(Pchar)) * BALLS_PER));
			AddCharacterGoods(Pchar, GOOD_GRAPES, makeint(makefloat(GetCannonQuantity(Pchar)) * GRAPE_PER));
			AddCharacterGoods(Pchar, GOOD_KNIPPELS, makeint(makefloat(GetCannonQuantity(Pchar)) * CHAIN_PER));

			int balls2 = GetSquadronGoods(Pchar, GOOD_BALLS);
			int grapes2 = GetSquadronGoods(Pchar, GOOD_GRAPES);
			int chains2 = GetSquadronGoods(Pchar, GOOD_KNIPPELS);

			if (!USE_REAL_CANNONS) 
			{ 
				int bombs1 = GetSquadronGoods(Pchar, GOOD_BOMBS);

				RemoveCharacterGoods(Pchar, GOOD_BOMBS, makeint(makefloat(GetCannonQuantity(Pchar)) * BOMBS_PER));
				AddCharacterGoods(Pchar, GOOD_BOMBS, makeint(makefloat(GetCannonQuantity(Pchar)) * BOMBS_PER));
					
				int bombs2 = GetSquadronGoods(Pchar, GOOD_BOMBS);
			}

			if (CANNONPOWDER_MOD) 
			{
				int gunpowder1 = GetSquadronGoods(Pchar, GOOD_GUNPOWDER);

				int fireGunpowder = 0;
				ref rCannon; makeref(rCannon,Cannon[GetCaracterShipCannonsType(Pchar)]);
				if(CheckAttribute(rCannon,"gunpowder")) fireGunpowder = sti(rCannon.gunpowder)*sti(GetCannonCurQuantity(Pchar));
				float averageQty = 0.0;
				if (USE_REAL_CANNONS) 	{ averageQty = makefloat(GetCargoGoods(Pchar,GOOD_BALLS) + GetCargoGoods(Pchar,GOOD_GRAPES) + GetCargoGoods(Pchar,GOOD_KNIPPELS))/3; }
				else 					{ averageQty = makefloat(GetCargoGoods(Pchar,GOOD_BALLS) + GetCargoGoods(Pchar,GOOD_GRAPES) + GetCargoGoods(Pchar,GOOD_KNIPPELS) + GetCargoGoods(Pchar,GOOD_BOMBS))/4; }
				float canCharge = makefloat(averageQty/makefloat(GetCannonCurQuantity(Pchar)));
				RemoveCharacterGoods(Pchar, GOOD_GUNPOWDER, makeint(makefloat(fireGunpowder * canCharge)) + makeint(sti(Pchar.ship.crew.quantity)*3));
				AddCharacterGoods(Pchar, GOOD_GUNPOWDER, makeint(makefloat(fireGunpowder * canCharge)) + makeint(sti(Pchar.ship.crew.quantity)*3));
					
				int gunpowder2 = GetSquadronGoods(Pchar, GOOD_GUNPOWDER);
			}

			int ammo1; int ammo2;

			if (CANNONPOWDER_MOD) 
			{
				if (!USE_REAL_CANNONS) 
				{
					ammo1 = balls1 + grapes1 + chains1 + bombs1 + gunpowder1;
				}
				else ammo1 = balls1 + grapes1 + chains1 + gunpowder1;
			}
			else
			{
				if (!USE_REAL_CANNONS) 
				{
					ammo1 = balls1 + grapes1 + chains1 + bombs1;
				}
				else ammo1 = balls1 + grapes1 + chains1;
			}

			if (CANNONPOWDER_MOD) 
			{
				if (!USE_REAL_CANNONS) 
				{
					ammo2 = balls2 + grapes2 + chains2 + bombs2 + gunpowder2;
				}
				else ammo2 = balls2 + grapes2 + chains2 + gunpowder2;
			}
			else
			{
				if (!USE_REAL_CANNONS) 
				{
					ammo2 = balls2 + grapes2 + chains2 + bombs2;
				}
				else ammo2 = balls2 + grapes2 + chains2;
			}

			if(ammo2 > ammo1)
			{
				//Log_SetStringToLog("Ammo have been added");
				int newammo = 1;
			}

			if(upgr == 1 && rpr == 1 && newammo == 1)
			{
				link.l1.go = "upgrade_ammo";
			}
			else
			{
				if(upgr == 1 && rpr == 1)
				{
					link.l1.go = "upgrade";
				}
			}
			else
			{
				if(upgr == 1 && newammo == 1)
				{
					link.l1.go = "upgrade_ammo";
				}
			}
			else
			{
				if(rpr == 1 && newammo == 1)
				{
					link.l1.go = "repair_ammo";
				}
			}
			else
			{
				if(upgr == 1)
				{
					link.l1.go = "upgrade";
				}
			}
			else
			{
				if(rpr == 1)
				{
					link.l1.go = "repair";
				}
			}
			else
			{
				if(newammo == 1)
				{
					link.l1.go = "ammo";
				}
			}
			else link.l1.go = "gunner4";
		break;

		case "upgrade_ammo":
			Dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "gunner4";
		break;

		case "repair_ammo":
			Dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "gunner4";
		break;

		case "upgrade":
			Dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "gunner4";
		break;

		case "repair":
			Dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "gunner4";
		break;

		case "ammo":
			Dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "gunner4";
		break;

		case "gunner4":
			Dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "exit";
			AddDialogExitQuest("armory_start");
		break;

		case "poetry":
			PlaySound("VOICE\ENGLISH\Eng_m_b_059.wav");
			Dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "poetry2";
		break;

		case "poetry2":
			Dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "poetry3";
		break;

		case "poetry3":
			Dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "poetry4";
		break;

		case "poetry4":
			Dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "exit";
			AddDialogExitQuest("poetry_talk_finished");
		break;

		case "prepare_explosion1":
			Dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "prepare_explosion2";
		break;

		case "prepare_explosion2":
			Dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";
			AddDialogExitQuest("gunner_opens_chest");
		break;

		case "hidden_key":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			Diag.TempNode = "first time";
			Dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "exit";
			AddDialogExitQuest("hidden_key");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
