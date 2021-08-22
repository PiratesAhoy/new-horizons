//#include "DIALOGS\wr guncrew_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c


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
	
			if(NPChar.id == "guncrew_1") PlaySound("VOICE\ENGLISH\guncrew_1.wav");
			if(NPChar.id == "guncrew_2") PlaySound("VOICE\ENGLISH\guncrew_2.wav");
			if(NPChar.id == "guncrew_3") PlaySound("VOICE\ENGLISH\guncrew_3.wav");
			if(NPChar.id == "guncrew_4") PlaySound("VOICE\ENGLISH\guncrew_4.wav");

		if(Pchar.quest.guncrew == "at_cannon_with_ammo" || Pchar.quest.guncrew == "at_cannon_without_ammo")
		{
				if(CheckCharacterItem(Pchar,"bladepowderhornA"))	//just to be sure
				{
					RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					TakeItemFromCharacter(Pchar, "bladepowderhornA");
					GiveItem2Character(Pchar,"bladepowderhornP");
				}
				
				//if(NPchar.quest.meeting == "9")		//not used
				if(CheckCharacterItem(Pchar,"bladepowderhornP"))
				{
					if(!IsEquipCharacterByItem(Pchar, "bladepowderhornP")) RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
					EquipCharacterByItem(Pchar, "bladepowderhornP");

					Dialog.text = DLG_TEXT[16];
					link.l1 = DLG_TEXT[37];		//never mind
					link.l1.go = "exit";
			
					if(!CheckCharacterItem(Pchar,"book41"))
					{
						link.l11 = DLG_TEXT[39];
						link.l11.go = "handbook";
					}
			
					if(Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_S1" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_S1X" 
					|| Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_S2") 
					{
						if(CheckAttribute(Pchar,"quest.cannon_enable_move") && Pchar.quest.cannon_enable_move == "yes")
						{
							if(Locations[FindLocation("wr_ships")].models.always.l3 == "goods_pile")
							{
								Link.l10 = DLG_TEXT[32];
								Link.l10.go = "move";
							}
						}					
					}
					link.l2 = DLG_TEXT[17];
					link.l2.go = "wad";
					Link.l3 = DLG_TEXT[18];
					Link.l3.go = "ram";
					Link.l4 = DLG_TEXT[19];
					Link.l4.go = "sponge";
					link.l5 = DLG_TEXT[20];
					link.l5.go = "powder";
					Link.l6 = DLG_TEXT[21];
					Link.l6.go = "ball";
					if(Locations[FindLocation("wr_ships")].models.always.l3 == "goods_pile")
					{
						Link.l7 = DLG_TEXT[22];
						Link.l7.go = "turn";
					}
					Link.l8 = DLG_TEXT[23];
					Link.l8.go = "dismiss";
					Link.l9 = DLG_TEXT[30];
					Link.l9.go = "fire";
					AddDialogExitQuest("guncrew_pchar_to_cannon");
				}
				else
				{
				//	if(NPchar.quest.meeting == "10")	//not used
				//	{
						//Pchar has no powderhorn
						Dialog.text = DLG_TEXT[38];
						link.l1 = DLG_TEXT[27];		
						link.l1.go = "exit";
						AddDialogExitQuest("find_powderhorn");
				//	}
				}
		}
		else
		{


			if(NPchar.quest.meeting == "0")
			{
				Characters[GetCharacterIndex("guncrew_1")].quest.meeting = "1";
				Characters[GetCharacterIndex("guncrew_2")].quest.meeting = "1";
				Characters[GetCharacterIndex("guncrew_3")].quest.meeting = "1";
				Characters[GetCharacterIndex("guncrew_4")].quest.meeting = "1";
				
				Dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
				AddDialogExitQuest("random_guncrew");
			}
			else
			{
				if(NPchar.quest.meeting == "1")
				{
					Characters[GetCharacterIndex("guncrew_1")].quest.meeting = "2";
					Characters[GetCharacterIndex("guncrew_2")].quest.meeting = "2";
					Characters[GetCharacterIndex("guncrew_3")].quest.meeting = "2";
					Characters[GetCharacterIndex("guncrew_4")].quest.meeting = "2";
					
					Dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "exit";
					AddDialogExitQuest("random_guncrew");
				}
			}
			else
			{
				if(NPchar.quest.meeting == "2")
				{
					Characters[GetCharacterIndex("guncrew_1")].quest.meeting = "3";
					Characters[GetCharacterIndex("guncrew_2")].quest.meeting = "3";
					Characters[GetCharacterIndex("guncrew_3")].quest.meeting = "3";
					Characters[GetCharacterIndex("guncrew_4")].quest.meeting = "3";
					
					Dialog.text = DLG_TEXT[4];
					link.l1 = DLG_TEXT[5];
					link.l1.go = "exit";
					AddDialogExitQuest("random_guncrew");
				}
			}
			else
			{
				if(NPchar.quest.meeting == "3")
				{
					Characters[GetCharacterIndex("guncrew_1")].quest.meeting = "4";
					Characters[GetCharacterIndex("guncrew_2")].quest.meeting = "4";
					Characters[GetCharacterIndex("guncrew_3")].quest.meeting = "4";
					Characters[GetCharacterIndex("guncrew_4")].quest.meeting = "4";
					
					Dialog.text = DLG_TEXT[6];
					link.l1 = DLG_TEXT[7];
					link.l1.go = "exit";
					AddDialogExitQuest("random_guncrew");
				}
			}
			else
			{
				if(NPchar.quest.meeting == "4")
				{
					Characters[GetCharacterIndex("guncrew_1")].quest.meeting = "5";
					Characters[GetCharacterIndex("guncrew_2")].quest.meeting = "5";
					Characters[GetCharacterIndex("guncrew_3")].quest.meeting = "5";
					Characters[GetCharacterIndex("guncrew_4")].quest.meeting = "5";
					
					Dialog.text = DLG_TEXT[8];
					link.l1 = DLG_TEXT[9];
					link.l1.go = "exit";
					AddDialogExitQuest("random_guncrew");
				}
			}
			else
			{
				if(NPchar.quest.meeting == "5")
				{
					Characters[GetCharacterIndex("guncrew_1")].quest.meeting = "6";
					Characters[GetCharacterIndex("guncrew_2")].quest.meeting = "6";
					Characters[GetCharacterIndex("guncrew_3")].quest.meeting = "6";
					Characters[GetCharacterIndex("guncrew_4")].quest.meeting = "6";
					
					Dialog.text = DLG_TEXT[10];
					link.l1 = DLG_TEXT[11];
					link.l1.go = "exit";
					AddDialogExitQuest("random_guncrew");
				}
			}
			else
			{
				if(NPchar.quest.meeting == "6")
				{
					Characters[GetCharacterIndex("guncrew_1")].quest.meeting = "7";
					Characters[GetCharacterIndex("guncrew_2")].quest.meeting = "7";
					Characters[GetCharacterIndex("guncrew_3")].quest.meeting = "7";
					Characters[GetCharacterIndex("guncrew_4")].quest.meeting = "7";
					
					Dialog.text = DLG_TEXT[12];
					link.l1 = DLG_TEXT[13];
					link.l1.go = "exit";
					AddDialogExitQuest("random_guncrew");
				}
			}
			else
			{
				if(NPchar.quest.meeting == "7")
				{
					Characters[GetCharacterIndex("guncrew_1")].quest.meeting = "8";
					Characters[GetCharacterIndex("guncrew_2")].quest.meeting = "8";
					Characters[GetCharacterIndex("guncrew_3")].quest.meeting = "8";
					Characters[GetCharacterIndex("guncrew_4")].quest.meeting = "8";
					//8 means no dialog, just greeting					

					Dialog.text = DLG_TEXT[14];
					link.l1 = DLG_TEXT[15];
					link.l1.go = "exit";
					SetQuestHeader("Cannon_drill");				
					AddQuestRecord("Cannon_drill", "1");
					AddDialogExitQuest("guncrew_hold_done");	//playertype after all 8 phrases
				}
			}
			else
			{
				if(NPchar.quest.meeting == "8")
				{
					if(NPChar.id == "guncrew_1") PlaySound("VOICE\ENGLISH\guncrew_1.wav");
					if(NPChar.id == "guncrew_2") PlaySound("VOICE\ENGLISH\guncrew_2.wav");
					if(NPChar.id == "guncrew_3") PlaySound("VOICE\ENGLISH\guncrew_3.wav");
					if(NPChar.id == "guncrew_4") PlaySound("VOICE\ENGLISH\guncrew_4.wav");

					NPChar.dlgover = true;
					DialogExit();
				}
			}

		}
			
			Diag.TempNode = "first time";
		break;
	
		case "handbook":
			Dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];		
			link.l1.go = "handbook1";
		break;

		case "handbook1":
			Dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[34];		
			link.l1.go = "exit";
			AddDialogExitQuest("find_handbook");
		break;

		case "wad":
			if(Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_W2" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_N2"
			|| Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_E2" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_S2")
			{
				Dialog.text = DLG_TEXT[26];		//too high
				link.l1 = DLG_TEXT[27];			//hmm
				link.l1.go = "exit";
				AddDialogExitQuest("guncrew_hah");
			}
			else
			{
				if(CheckAttribute(Pchar,"quest.guncrew")) 
				{
					if(Pchar.quest.guncrew == "at_cannon_with_ammo")
					{
						Dialog.text = DLG_TEXT[24];		//aye aye
						link.l1 = DLG_TEXT[25];			//captain
						link.l1.go = "exit";
						AddDialogExitQuest("guncrew_wad");
					}

					if(Pchar.quest.guncrew == "at_cannon_without_ammo")
					{
						Dialog.text = DLG_TEXT[29];		//no ammo
						link.l1 = DLG_TEXT[27];			//hmm
						link.l1.go = "exit";
						AddDialogExitQuest("guncrew_hah");
					}
				}
			}
		break;
		
		case "ram":
			if(Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_W2" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_N2"
			|| Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_E2" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_S2")
			{
				Dialog.text = DLG_TEXT[26];		//too high
				link.l1 = DLG_TEXT[27];			//hmm
				link.l1.go = "exit";
				AddDialogExitQuest("guncrew_hah");
			}
			else
			{
				Dialog.text = DLG_TEXT[24];		//aye aye
				link.l1 = DLG_TEXT[25];			//captain
				link.l1.go = "exit";
				AddDialogExitQuest("guncrew_ram");
			}
		break;

		case "sponge":
			if(Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_W2" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_N2"
			|| Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_E2" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_S2")
			{
				Dialog.text = DLG_TEXT[26];		//too high
				link.l1 = DLG_TEXT[27];			//hmm
				link.l1.go = "exit";
				AddDialogExitQuest("guncrew_hah");
			}
			else
			{
				Dialog.text = DLG_TEXT[24];		//aye aye
				link.l1 = DLG_TEXT[25];			//captain
				link.l1.go = "exit";
				AddDialogExitQuest("guncrew_sponge");
			}
		break;

		case "powder":
			if(Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_W2" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_N2"
			|| Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_E2" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_S2")
			{
				Dialog.text = DLG_TEXT[26];		//too high
				link.l1 = DLG_TEXT[27];			//hmm
				link.l1.go = "exit";
				AddDialogExitQuest("guncrew_hah");
			}
			else
			{
				if(CheckAttribute(Pchar,"quest.guncrew")) 
				{
					if(Pchar.quest.guncrew == "at_cannon_with_ammo")
					{
						Dialog.text = DLG_TEXT[24];		//aye aye
						link.l1 = DLG_TEXT[25];			//captain
						link.l1.go = "exit";
						AddDialogExitQuest("guncrew_powder");
					}

					if(Pchar.quest.guncrew == "at_cannon_without_ammo")
					{
						Dialog.text = DLG_TEXT[29];		//no ammo
						link.l1 = DLG_TEXT[27];			//hmm
						link.l1.go = "exit";
						AddDialogExitQuest("guncrew_hah");
					}
				}
			}
		break;
	
		case "ball":
			if(Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_W2" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_N2"
			|| Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_E2" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_S2")
			{
				Dialog.text = DLG_TEXT[26];		//too high
				link.l1 = DLG_TEXT[27];			//hmm
				link.l1.go = "exit";
				AddDialogExitQuest("guncrew_hah");
			}
			else
			{
				if(CheckAttribute(Pchar,"quest.guncrew")) 
				{
					if(Pchar.quest.guncrew == "at_cannon_with_ammo")
					{
						if(CheckAttribute(Pchar,"quest.cannon_goodspile") && Pchar.quest.cannon_goodspile == "gone")
						{
							if(CheckAttribute(Pchar,"quest.gall_captain") && Pchar.quest.gall_captain == "open")
							{
								Dialog.text = DLG_TEXT[24];		//aye aye
								link.l1 = DLG_TEXT[25];			//captain
								link.l1.go = "exit";
								AddDialogExitQuest("guncrew_ball");
							}
							else
							{

								Dialog.text = DLG_TEXT[33];		//no cannon balls left
								link.l1 = DLG_TEXT[34];			//is that so!
								link.l1.go = "exit";
								AddDialogExitQuest("guncrew_hah");
							}
						}
						else
						{
							Dialog.text = DLG_TEXT[24];		//aye aye
							link.l1 = DLG_TEXT[25];			//captain
							link.l1.go = "exit";
							AddDialogExitQuest("guncrew_ball");
						}
					}

					if(Pchar.quest.guncrew == "at_cannon_without_ammo")
					{
						Dialog.text = DLG_TEXT[29];		//no ammo
						link.l1 = DLG_TEXT[27];			//hmm
						link.l1.go = "exit";
						AddDialogExitQuest("guncrew_hah");
					}
				}
			}
		break;
		
		case "turn":
			if(Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_W2" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_N2"
			|| Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_E2" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_S2")
			{
				Dialog.text = DLG_TEXT[24];		//aye aye
				link.l1 = DLG_TEXT[25];			//captain
				link.l1.go = "exit";
				AddDialogExitQuest("guncrew_turn");
			}
			else
			{
				Dialog.text = DLG_TEXT[28];		//too heavy
				link.l1 = DLG_TEXT[27];			//hmm
				link.l1.go = "exit";
				AddDialogExitQuest("guncrew_hah");
			}
		break;

		case "dismiss":
			Dialog.text = DLG_TEXT[24];		//aye aye
			link.l1 = DLG_TEXT[25];			//captain
			link.l1.go = "exit";
			AddDialogExitQuest("guncrew_dismiss");
		break;

		case "fire":
			if(Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_W2" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_N2"
			|| Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_E2" || Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_S2")
			{
				Dialog.text = DLG_TEXT[26];		//too high
				link.l1 = DLG_TEXT[27];			//hmm
				link.l1.go = "exit";
				AddDialogExitQuest("guncrew_hah");
			}
			else
			{
				Dialog.text = DLG_TEXT[31];		//fire yourselfe
				link.l1 = DLG_TEXT[27];			//hmm
				link.l1.go = "exit";
				AddDialogExitQuest("guncrew_fire");
			}
		break;

		case "move":
			if(Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_S1") 
			{
				Dialog.text = DLG_TEXT[24];		//aye aye
				link.l1 = DLG_TEXT[25];			//captain
				link.l1.go = "exit";
				AddDialogExitQuest("guncrew_move");
			}
			else
			{
				if(Locations[FindLocation("wr_ships")].models.always.l4 == "cannon_S1X") 
				{
					Dialog.text = DLG_TEXT[24];		//aye aye
					link.l1 = DLG_TEXT[25];			//captain
					link.l1.go = "exit";
					AddDialogExitQuest("guncrew_move_back");
				}
			}
			else
			{
				Dialog.text = DLG_TEXT[26];		//too high
				link.l1 = DLG_TEXT[27];			//hmm
				link.l1.go = "exit";
				AddDialogExitQuest("guncrew_hah");
			}
		break;

		case "anvil":
			PlaySound("VOICE\ENGLISH\guncrew_1.wav");
			Dialog.text = DLG_TEXT[35];		
			link.l1 = DLG_TEXT[36];			
			link.l1.go = "exit";
			AddDialogExitQuest("anvil_push");
		break;

		case "neutral":
			if(NPChar.id == "guncrew_1") PlaySound("VOICE\ENGLISH\guncrew_1.wav");
			if(NPChar.id == "guncrew_2") PlaySound("VOICE\ENGLISH\guncrew_2.wav");
			if(NPChar.id == "guncrew_3") PlaySound("VOICE\ENGLISH\guncrew_3.wav");
			if(NPChar.id == "guncrew_4") PlaySound("VOICE\ENGLISH\guncrew_4.wav");

			Dialog.text = DLG_TEXT[16];		
			link.l1 = DLG_TEXT[37];			
			link.l1.go = "exit";
			Diag.TempNode = "neutral";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
