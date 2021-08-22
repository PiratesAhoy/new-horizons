//#include "DIALOGS\tailor_dialog.h"

int GetModelPrice(ref PChar, ref NPChar, string ModelPrice)
{
	int ModelBasePrice = sti(ModelPrice);
	int BuySkill		= sti(PChar.skill.Commerce);
	int SellSkill	  = sti(NPChar.skill.Commerce);
	int RandSeed;
	int RandomFactor;
	int SellPrice;
	if (BuySkill > SellSkill)
	{
		RandSeed	 = sti(ModelBasePrice / 30 * (BuySkill - SellSkill));
		RandomFactor = rand(RandSeed); // - 0-30%
		SellPrice	= sti(ModelBasePrice - RandomFactor);
	}
	else
	{
		if (BuySkill < SellSkill)
		{
			RandSeed	 = sti(ModelBasePrice / 5 * (SellSkill - BuySkill));
			RandomFactor = rand(RandSeed); // + 0-200% up
			SellPrice	= sti(ModelBasePrice + RandomFactor);
		}
		else
		{
			RandSeed	 = sti(ModelBasePrice / 20);
			RandomFactor = rand(RandSeed); // + 0-5% up
			SellPrice	= sti(ModelBasePrice + RandomFactor);
		}
	}
	if (SellPrice > 10000)
	{
		SellPrice = sti(SellPrice/1000)*1000;
	}
	else
	{
		if (SellPrice > 1000)
		{
			SellPrice = sti(SellPrice/100)*100;
		}
		else
		{
			if (SellPrice > 100)
			{
				SellPrice = sti(SellPrice/50)*50;
			}
			else
			{
				if (SellPrice > 10)
				{
					SellPrice = sti(SellPrice/10)*10;
				}
			}
		}
	}
	return SellPrice;
}

bool IsInvalidModel(ref PChar, int intModelIndex, int Slot)
{
	int i;
	bool boolIsInvalid = false;
	if(GetLevel(PChar) < sti(Models[intModelIndex].minlevel))
	{
		boolIsInvalid = true; // NK
	}
	for(i = 0; i < Slot; i++)
	{
		if (ModelSlots[i].Index == intModelIndex)
		{
			boolIsInvalid = true; // NK
		}
	}
	if(CheckAttribute(PChar,"clothes."+Models[intModelIndex].model))
	{
		boolIsInvalid = true;
	}
	return boolIsInvalid;
}

void InitModelSlots(ref PChar, ref refTailor, string strNow)
{
	int i;
	int intModelIndex;
	int intModelNation;
	int breakcounter = 0;
	bool boolGetNewModels = false; // Scheffnow: set default
	string strSlot;

	if(!CheckAttribute(refTailor, "AppearanceMod.Model_0"))
 	{
		boolGetNewModels = true;
 	}
 	else
 	{
		if(refTailor.AppearanceMod.LastSpeakDate != strNow)
		{
			boolGetNewModels = true;
			refTailor.AppearanceMod.LastSpeakDate = strNow; // NK
		}
		else
		{
			if(DEBUG) boolGetNewModels = true; // NK  // Scheffnow: When debug is true it should select new models
		}
	}
	boolGetNewModels = true;
	for(i = 0; i < 5; i++)
	{
		strSlot = "Model_" + i;
		DeleteAttribute(ModelSlots[i],""); // NK
		if (boolGetNewModels == true)
		{
			breakcounter = 0;
			intModelNation = refTailor.nation; // PB: ALL_NATIONS included later
			intModelIndex = GetRandomModelForNation(intModelNation,GetRank(&PChar,intModelNation)); // NK 04-06
			while(IsInvalidModel(PChar, intModelIndex, i) == true)
			{
				intModelIndex = GetRandomModelForNation(intModelNation,GetRank(&PChar,intModelNation)); // NK 04-06
				breakcounter++; // NK just in case
				if(breakcounter > 1000)
				{
					break; // ditto
				}
			}
			ModelSlots[i].Index = intModelIndex;
			ModelSlots[i].model = Models[intModelIndex].model;
			ModelSlots[i].price = GetModelPrice(PChar, refTailor, Models[intModelIndex].price);
			ModelSlots[i].descr = Models[intModelIndex].description;
			refTailor.AppearanceMod.(strSlot).model = ModelSlots[i].model;
			refTailor.AppearanceMod.(strSlot).index = ModelSlots[i].index;
			refTailor.AppearanceMod.(strSlot).price = ModelSlots[i].price;
			refTailor.AppearanceMod.(strSlot).descr = ModelSlots[i].descr;
		}
		else
		{
			ModelSlots[i].index = refTailor.AppearanceMod.(strSlot).index;
			ModelSlots[i].model = refTailor.AppearanceMod.(strSlot).model;
			ModelSlots[i].price = refTailor.AppearanceMod.(strSlot).price;
			ModelSlots[i].descr = refTailor.AppearanceMod.(strSlot).descr;
		}
	}
}

void AppearanceMod_ModelLinks(ref PChar, ref d, aref Link)
{
	d.Text = DLG_TEXT[15];
	Link.l1 = DLG_TEXT[16];
	Link.l1.go = "AppearanceMod_Exit";
	// NK -->
	string linkstr;
	int i;
	for(i = 0; i < MAX_MODELSLOTS; i++)
	{
		linkstr = "l" + (i+2);
		//Link.(linkstr) = Models[sti(ModelSlots[i].Index)].description;
		int tmpDescFileID = LanguageOpenFile("models_description.txt");
		Link.(linkstr) = ModelSlots[i].price + DLG_TEXT[17] + LanguageConvertString(tmpDescFileID,ModelSlots[i].descr);
		Link.(linkstr).go = "AppearanceMod_Select_"+(i+1);
		LanguageCloseFile(tmpDescFileID);
	}
}
void AppearanceMod_AnswerLinks(ref PChar, ref d, aref Link, int intPrice)
{
	int intOfficerPos = sti(PChar.AppearanceMod.OfficerPos);
	int intMoney	  = sti(PChar.money);
	d.Text	 = DLG_TEXT[18];
	Link.l1	= DLG_TEXT[19];
	Link.l1.go = "AppearanceMod_SetOfficer"+intOfficerPos;
	if (intPrice > intMoney)
	{
		Link.l2	= DLG_TEXT[20];
		Link.l2.go = "AppearanceMod_SetOfficer"+intOfficerPos;
	}
	else
	{
		Link.l2	= DLG_TEXT[21];
		Link.l2.go = "AppearanceMod_Buy_choice";
		PChar.AppearanceMod.Price = intPrice;
	}
	Link.l3	= DLG_TEXT[22];
	Link.l3.go = "AppearanceMod_Exit";
}

// NK real func moved to models.h
// move setmodelfromarray to models.c 05-04-30

void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
//	ref ch;								// added by El Rapido
	aref Link, Diag;
	string NPC_Area;
	string tempstr;
	ref refOfficer;
	int intOfficer;
	int i;
	int j;
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string strNow = iMonth + " " + iDay;
	
	int intRank;
    int intHealthPoints;
    int intFreeSkill;
    int intLeadership;
    int intFencing;
    int intSailing;
    int intAccuracy;
    int intCannons;
    int intGrappling;
    int intRepair;
    int intDefence;
    int intCommerce;
    int intSneak;
    int intFreePerks;
    int intMoney;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	//NPC_Area = NPChar.quest.area;

	switch(Dialog.CurrentNode)
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
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

			Dialog.snd1 = "voice\USDI\USDI004";
			Dialog.snd2 = "voice\USDI\USDI005";
			Dialog.snd3 = "voice\USDI\USDI006";
			if(!CheckAttribute(NPChar, "AppearanceMod"))
			{
				NPChar.AppearanceMod.LastSpeakDate = strNow;
				d.Text = DLG_TEXT[23] + GetMyFullName(NPChar)  + DLG_TEXT[24] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + ".";
				Link.l1 = DLG_TEXT[25];
				Link.l1.go = "AppearanceMod_MainDialog";
				if(GetCharacterMoney(Pchar) >= 10000)
				{
					Link.l2 = DLG_TEXT[60];
					Link.l2.go = "El_Rapido_Clothes";
				}
				if(ENABLE_CHEATMODE)
				{
					if(!AUTO_SKILL_SYSTEM)
					{
						Link.l3 = DLG_TEXT[64];
						Link.l3.go = "El_Rapido_ResetCharacter";
					}
					Link.l4 = DLG_TEXT[70];
					Link.l4.go = "El_Rapido_ResetPerks";
//					Link.l5 = DLG_TEXT[76];
//					Link.l5.go = "El_Rapido_HireOfficer";
				}
				Link.l99 = DLG_TEXT[26];
				Link.l99.go = "exit";
			}
			else
			{
				if (NPChar.AppearanceMod.LastSpeakDate != strNow)
				{
					// NK: lastspeakdate = strNow moved to InitModelSlots
					d.Text = DLG_TEXT[14] + GetMyAddressForm(NPChar, PChar, ADDR_TITLE, false, true) + DLG_TEXT[27];
					Link.l1 = DLG_TEXT[28] + GetMyName(NPChar) + DLG_TEXT[29];
					Link.l1.go = "AppearanceMod_MainDialog";
					Link.l2 = DLG_TEXT[30] + GetMyName(NPChar) + DLG_TEXT[31];
					Link.l2.go = "exit";
					if(GetCharacterMoney(Pchar) >= 10000)
					{
						Link.l3 = DLG_TEXT[60];
						Link.l3.go = "El_Rapido_Clothes";
					}
					if(ENABLE_CHEATMODE)
					{
						if(!AUTO_SKILL_SYSTEM)
						{
							Link.l4 = DLG_TEXT[64];
							Link.l4.go = "El_Rapido_ResetCharacter";
						}
						Link.l5 = DLG_TEXT[70];
						Link.l5.go = "El_Rapido_ResetPerks";
//						Link.l6 = DLG_TEXT[76];
//						Link.l6.go = "El_Rapido_HireOfficer";
					}
				}
				else
				{
					d.Text = DLG_TEXT[14] + GetMyAddressForm(NPChar, PChar, ADDR_TITLE, false, true) + DLG_TEXT[32];
					Link.l1 = DLG_TEXT[33] + GetMyName(NPChar) + DLG_TEXT[34];
					Link.l1.go = "AppearanceMod_MainDialog";
					Link.l2 = DLG_TEXT[35] + GetMyName(NPChar) + DLG_TEXT[36];
					Link.l2.go = "exit";
					if(GetCharacterMoney(Pchar) >= 10000)
					{
						Link.l3 = DLG_TEXT[60];
						Link.l3.go = "El_Rapido_Clothes";
					}
					if(ENABLE_CHEATMODE)
					{
						if(!AUTO_SKILL_SYSTEM)
						{
							Link.l4 = DLG_TEXT[64];
							Link.l4.go = "El_Rapido_ResetCharacter";
						}
						Link.l5 = DLG_TEXT[70];
						Link.l5.go = "El_Rapido_ResetPerks";
//						Link.l6 = DLG_TEXT[76];
//						Link.l6.go = "El_Rapido_HireOfficer";
					}
				}
			}
			if(DEBUG)
			{
				 PChar.AppearanceMod.ClothierModel = NPChar.model;
				 Link.l3 = DLG_TEXT[37];
				 Link.l3.go = "AppearanceMod_CircleThroughAllModels";
			}

		// Kapitein of Kralendijk side quest -->
			if(PChar.location == "Douwesen_TailorsShop")
			{
				if(CheckQuestAttribute("kapitein", "tailor") || CheckQuestAttribute("kapitein", "got_papers"))
				{
					if(PChar.sex == "woman") link.l11 = DLG_TEXT[87] + DLG_TEXT[89] + DLG_TEXT[90];
					else link.l11 = DLG_TEXT[87] + DLG_TEXT[88] + DLG_TEXT[90];
					if (PChar.model == GetAttribute(PChar, "quest.kapitein.soldier_model") && !CheckQuestAttribute("kapitein_already_got_uniform", "true")) link.l11.go = "kaptein_change_first"; 
					else link.l11.go = "kapitein_ask_papers";
				}
				if(CheckQuestAttribute("kapitein", "uniform_ready"))
				{
					link.l11 = DLG_TEXT[99];
					link.l11.go = "kapitein_uniform_ready";
				}
			}
		// <-- Kapitein of Kralendijk side quest
		break;

		
/*		case "El_Rapido_HireOfficer":    // El Rapido START
		  
				d.Text = DLG_TEXT[77];
                Link.l1    = DLG_TEXT[78];
                Link.l1.go = "El_Rapido_Hire_FirstMate";
				Link.l2    = DLG_TEXT[79];
                Link.l2.go = "El_Rapido_Hire_Boatswain";
				Link.l3    = DLG_TEXT[80];
                Link.l3.go = "El_Rapido_Hire_Gunner";
				Link.l4    = DLG_TEXT[81];
                Link.l4.go = "El_Rapido_Hire_Navigator";		
	            Link.l5    = DLG_TEXT[82];
                Link.l5.go = "El_Rapido_Hire_Quartermaster";
				Link.l6    = DLG_TEXT[83];
                Link.l6.go = "El_Rapido_Hire_Carpenter";
				Link.l7    = DLG_TEXT[84];
                Link.l7.go = "El_Rapido_Hire_Surgeon";
				Link.l8    = DLG_TEXT[85];
                Link.l8.go = "El_Rapido_Hire_Abordage";	
				Link.l9    = DLG_TEXT[86];
                Link.l9.go = "exit";	
				
		break;
		
			case "El_Rapido_Hire_FirstMate":  
		
				ch = CreateOfficer_Cheat(OFFIC_TYPE_FIRSTMATE, "bocman5", 0, PIRATE, false);
				ch.name = "New";
				ch.lastname = "Firstmate";
				SetOfficersIndex(pchar, -1, GetCharacterIndex(ch.id));
				
				DialogExit();		
				PlayStereoSound("INTERFACE\ITTB.wav");			
				LaunchCharacter(PChar);
				
			break;		
				
			case "El_Rapido_Hire_Gunner":  
		
				ch = CreateOfficer_Cheat(OFFIC_TYPE_CANNONEER, "bocman5", 0, PIRATE, false);
				ch.name = "New";
				ch.lastname = "Gunner";
				SetOfficersIndex(pchar, -1, GetCharacterIndex(ch.id));
				
				DialogExit();		
				PlayStereoSound("INTERFACE\ITTB.wav");			
				LaunchCharacter(PChar);
				
			break;						
				
			case "El_Rapido_Hire_Navigator":  
		
				ch = CreateOfficer_Cheat(OFFIC_TYPE_NAVIGATOR, "bocman5", 0, PIRATE, false);
				ch.name = "New";
				ch.lastname = "Navigator";
				SetOfficersIndex(pchar, -1, GetCharacterIndex(ch.id));
				
				DialogExit();		
				PlayStereoSound("INTERFACE\ITTB.wav");			
				LaunchCharacter(PChar);
				
			break;		
				
			case "El_Rapido_Hire_Quartermaster":  
		
				ch = CreateOfficer_Cheat(OFFIC_TYPE_QMASTER, "bocman5", 0, PIRATE, false);
				ch.name = "New";
				ch.lastname = "Quartermaster";
				SetOfficersIndex(pchar, -1, GetCharacterIndex(ch.id));
				
				DialogExit();		
				PlayStereoSound("INTERFACE\ITTB.wav");			
				LaunchCharacter(PChar);
				
			break;	

			case "El_Rapido_Hire_Carpenter":  
		
				ch = CreateOfficer_Cheat(OFFIC_TYPE_CARPENTER, "bocman5", 0, PIRATE, false);
				ch.name = "New";
				ch.lastname = "Carpenter";
				SetOfficersIndex(pchar, -1, GetCharacterIndex(ch.id));
				
				DialogExit();		
				PlayStereoSound("INTERFACE\ITTB.wav");			
				LaunchCharacter(PChar);
				
			break;		
				
			case "El_Rapido_Hire_Surgeon":  
		
				ch = CreateOfficer_Cheat(OFFIC_TYPE_DOCTOR, "bocman5", 0, PIRATE, false);
				ch.name = "New";
				ch.lastname = "Surgeon";
				SetOfficersIndex(pchar, -1, GetCharacterIndex(ch.id));
				
				DialogExit();		
				PlayStereoSound("INTERFACE\ITTB.wav");			
				LaunchCharacter(PChar);
				
			break;	

			case "El_Rapido_Hire_Abordage":  
		
				ch = CreateOfficer_Cheat(OFFIC_TYPE_ABORDAGE, "bocman5", 0, PIRATE, false);
				ch.name = "New";
				ch.lastname = "Fighter";
				SetOfficersIndex(pchar, -1, GetCharacterIndex(ch.id));
				
				DialogExit();		
				PlayStereoSound("INTERFACE\ITTB.wav");			
				LaunchCharacter(PChar);
				
			break;		
				
*/

		case "El_Rapido_ResetPerks":    // El Rapido START
		
		// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- start -----------
            
				d.Text = DLG_TEXT[71];
                Link.l1    = DLG_TEXT[72];
                Link.l1.go = "exit";
				Link.l2    = DLG_TEXT[73];
                Link.l2.go = "PerkReset_The_Officers";
				Link.l3    = DLG_TEXT[74];
                Link.l3.go = "PerkReset_The_Main_Character";
				Link.l4    = DLG_TEXT[75];
                Link.l4.go = "PerkReset_The_Characters";

		break;
		
		case "PerkReset_The_Officers":

			// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- start -----------

	intOfficer = sti(GetOfficersIndex(PChar,1));
	refOfficer = GetCharacter(intOfficer);
	
		// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------	
		
		intRank       = refOfficer.rank;
        intFreePerks                = intRank;
        if (intFreePerks < 0) 
        {
            intFreePerks = 0;
        }
        refOfficer.perks.freepoints = intFreePerks;
        
        DeleteAttribute(refOfficer,"perks.list.BasicDefence");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDefence");
        DeleteAttribute(refOfficer,"perks.list.SwordplayProfessional");
        DeleteAttribute(refOfficer,"perks.list.Rush");
        DeleteAttribute(refOfficer,"perks.list.CriticalHit");
        DeleteAttribute(refOfficer,"perks.list.Gunman");
        DeleteAttribute(refOfficer,"perks.list.GunProfessional");
        DeleteAttribute(refOfficer,"perks.list.FastReload");
        DeleteAttribute(refOfficer,"perks.list.ImmediateReload");
        DeleteAttribute(refOfficer,"perks.list.HullDamageUp");
        DeleteAttribute(refOfficer,"perks.list.SailsDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CrewDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CriticalShoot");
        DeleteAttribute(refOfficer,"perks.list.LongRangeShoot");
        DeleteAttribute(refOfficer,"perks.list.CannonProfessional");
        DeleteAttribute(refOfficer,"perks.list.LongRangeGrappling");
        DeleteAttribute(refOfficer,"perks.list.MusketsShoot");
        DeleteAttribute(refOfficer,"perks.list.GrapplingProfessional");
        DeleteAttribute(refOfficer,"perks.list.InstantBoarding");
        DeleteAttribute(refOfficer,"perks.list.BasicDamageControl");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDamageControl");
        DeleteAttribute(refOfficer,"perks.list.ProfessionalDamageControl");
        DeleteAttribute(refOfficer,"perks.list.BasicFirstAid");
        DeleteAttribute(refOfficer,"perks.list.AdvancedFirstAid");
        DeleteAttribute(refOfficer,"perks.list.Rigging");
        DeleteAttribute(refOfficer,"perks.list.RiggingAdvance");
        DeleteAttribute(refOfficer,"perks.list.LightRepair");
        DeleteAttribute(refOfficer,"perks.list.InstantRepair");
        DeleteAttribute(refOfficer,"perks.list.ShipSpeedUp");
        DeleteAttribute(refOfficer,"perks.list.ShipTurnRateUp");
        DeleteAttribute(refOfficer,"perks.list.StormProfessional");
        DeleteAttribute(refOfficer,"perks.list.Turn180");
        DeleteAttribute(refOfficer,"perks.list.SandbankManeuver");
        DeleteAttribute(refOfficer,"perks.list.SailingProfessional");
        DeleteAttribute(refOfficer,"perks.list.IronWill");
        DeleteAttribute(refOfficer,"perks.list.SharedExperience");
        DeleteAttribute(refOfficer,"perks.list.Brander");
        DeleteAttribute(refOfficer,"perks.list.Troopers");
        DeleteAttribute(refOfficer,"perks.list.Trustworthy");
        DeleteAttribute(refOfficer,"perks.list.BasicCommerce");
        DeleteAttribute(refOfficer,"perks.list.AdvancedCommerce");
        DeleteAttribute(refOfficer,"perks.list.BasicLandOwner");
		DeleteAttribute(refOfficer,"perks.list.Toughness");
		DeleteAttribute(refOfficer,"perks.list.ImproveAiming");
		DeleteAttribute(refOfficer,"perks.list.ImproveSmuggling");
		DeleteAttribute(refOfficer,"perks.list.AdvanceSmuggling");
		DeleteAttribute(refOfficer,"perks.list.ImprovePotions");
		DeleteAttribute(refOfficer,"perks.list.DefendPoison");
		DeleteAttribute(refOfficer,"perks.list.Cooking");
		DeleteAttribute(refOfficer,"perks.list.HighStakes");
		DeleteAttribute(refOfficer,"perks.list.Disguiser");
        
		intOfficer = sti(GetOfficersIndex(PChar,2));
	refOfficer = GetCharacter(intOfficer);
	
		// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------	
		
		intRank       = refOfficer.rank;
        intFreePerks                = intRank;
        if (intFreePerks < 0) 
        {
            intFreePerks = 0;
        }
        refOfficer.perks.freepoints = intFreePerks;
        
        DeleteAttribute(refOfficer,"perks.list.BasicDefence");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDefence");
        DeleteAttribute(refOfficer,"perks.list.SwordplayProfessional");
        DeleteAttribute(refOfficer,"perks.list.Rush");
        DeleteAttribute(refOfficer,"perks.list.CriticalHit");
        DeleteAttribute(refOfficer,"perks.list.Gunman");
        DeleteAttribute(refOfficer,"perks.list.GunProfessional");
        DeleteAttribute(refOfficer,"perks.list.FastReload");
        DeleteAttribute(refOfficer,"perks.list.ImmediateReload");
        DeleteAttribute(refOfficer,"perks.list.HullDamageUp");
        DeleteAttribute(refOfficer,"perks.list.SailsDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CrewDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CriticalShoot");
        DeleteAttribute(refOfficer,"perks.list.LongRangeShoot");
        DeleteAttribute(refOfficer,"perks.list.CannonProfessional");
        DeleteAttribute(refOfficer,"perks.list.LongRangeGrappling");
        DeleteAttribute(refOfficer,"perks.list.MusketsShoot");
        DeleteAttribute(refOfficer,"perks.list.GrapplingProfessional");
        DeleteAttribute(refOfficer,"perks.list.InstantBoarding");
        DeleteAttribute(refOfficer,"perks.list.BasicDamageControl");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDamageControl");
        DeleteAttribute(refOfficer,"perks.list.ProfessionalDamageControl");
        DeleteAttribute(refOfficer,"perks.list.BasicFirstAid");
        DeleteAttribute(refOfficer,"perks.list.AdvancedFirstAid");
        DeleteAttribute(refOfficer,"perks.list.Rigging");
        DeleteAttribute(refOfficer,"perks.list.RiggingAdvance");
        DeleteAttribute(refOfficer,"perks.list.LightRepair");
        DeleteAttribute(refOfficer,"perks.list.InstantRepair");
        DeleteAttribute(refOfficer,"perks.list.ShipSpeedUp");
        DeleteAttribute(refOfficer,"perks.list.ShipTurnRateUp");
        DeleteAttribute(refOfficer,"perks.list.StormProfessional");
        DeleteAttribute(refOfficer,"perks.list.Turn180");
        DeleteAttribute(refOfficer,"perks.list.SandbankManeuver");
        DeleteAttribute(refOfficer,"perks.list.SailingProfessional");
        DeleteAttribute(refOfficer,"perks.list.IronWill");
        DeleteAttribute(refOfficer,"perks.list.SharedExperience");
        DeleteAttribute(refOfficer,"perks.list.Brander");
        DeleteAttribute(refOfficer,"perks.list.Troopers");
        DeleteAttribute(refOfficer,"perks.list.Trustworthy");
        DeleteAttribute(refOfficer,"perks.list.BasicCommerce");
        DeleteAttribute(refOfficer,"perks.list.AdvancedCommerce");
        DeleteAttribute(refOfficer,"perks.list.BasicLandOwner");
		DeleteAttribute(refOfficer,"perks.list.Toughness");
		DeleteAttribute(refOfficer,"perks.list.ImproveAiming");
		DeleteAttribute(refOfficer,"perks.list.ImproveSmuggling");
		DeleteAttribute(refOfficer,"perks.list.AdvanceSmuggling");
		DeleteAttribute(refOfficer,"perks.list.ImprovePotions");
		DeleteAttribute(refOfficer,"perks.list.DefendPoison");
		DeleteAttribute(refOfficer,"perks.list.Cooking");
		DeleteAttribute(refOfficer,"perks.list.HighStakes");
		DeleteAttribute(refOfficer,"perks.list.Disguiser");
		

		intOfficer = sti(GetOfficersIndex(PChar,3));
	refOfficer = GetCharacter(intOfficer);
	
		// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------	
		
		intRank       = refOfficer.rank;
        intFreePerks                = intRank;
        if (intFreePerks < 0) 
        {
            intFreePerks = 0;
        }
        refOfficer.perks.freepoints = intFreePerks;
        
        DeleteAttribute(refOfficer,"perks.list.BasicDefence");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDefence");
        DeleteAttribute(refOfficer,"perks.list.SwordplayProfessional");
        DeleteAttribute(refOfficer,"perks.list.Rush");
        DeleteAttribute(refOfficer,"perks.list.CriticalHit");
        DeleteAttribute(refOfficer,"perks.list.Gunman");
        DeleteAttribute(refOfficer,"perks.list.GunProfessional");
        DeleteAttribute(refOfficer,"perks.list.FastReload");
        DeleteAttribute(refOfficer,"perks.list.ImmediateReload");
        DeleteAttribute(refOfficer,"perks.list.HullDamageUp");
        DeleteAttribute(refOfficer,"perks.list.SailsDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CrewDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CriticalShoot");
        DeleteAttribute(refOfficer,"perks.list.LongRangeShoot");
        DeleteAttribute(refOfficer,"perks.list.CannonProfessional");
        DeleteAttribute(refOfficer,"perks.list.LongRangeGrappling");
        DeleteAttribute(refOfficer,"perks.list.MusketsShoot");
        DeleteAttribute(refOfficer,"perks.list.GrapplingProfessional");
        DeleteAttribute(refOfficer,"perks.list.InstantBoarding");
        DeleteAttribute(refOfficer,"perks.list.BasicDamageControl");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDamageControl");
        DeleteAttribute(refOfficer,"perks.list.ProfessionalDamageControl");
        DeleteAttribute(refOfficer,"perks.list.BasicFirstAid");
        DeleteAttribute(refOfficer,"perks.list.AdvancedFirstAid");
        DeleteAttribute(refOfficer,"perks.list.Rigging");
        DeleteAttribute(refOfficer,"perks.list.RiggingAdvance");
        DeleteAttribute(refOfficer,"perks.list.LightRepair");
        DeleteAttribute(refOfficer,"perks.list.InstantRepair");
        DeleteAttribute(refOfficer,"perks.list.ShipSpeedUp");
        DeleteAttribute(refOfficer,"perks.list.ShipTurnRateUp");
        DeleteAttribute(refOfficer,"perks.list.StormProfessional");
        DeleteAttribute(refOfficer,"perks.list.Turn180");
        DeleteAttribute(refOfficer,"perks.list.SandbankManeuver");
        DeleteAttribute(refOfficer,"perks.list.SailingProfessional");
        DeleteAttribute(refOfficer,"perks.list.IronWill");
        DeleteAttribute(refOfficer,"perks.list.SharedExperience");
        DeleteAttribute(refOfficer,"perks.list.Brander");
        DeleteAttribute(refOfficer,"perks.list.Troopers");
        DeleteAttribute(refOfficer,"perks.list.Trustworthy");
        DeleteAttribute(refOfficer,"perks.list.BasicCommerce");
        DeleteAttribute(refOfficer,"perks.list.AdvancedCommerce");
        DeleteAttribute(refOfficer,"perks.list.BasicLandOwner");
		DeleteAttribute(refOfficer,"perks.list.Toughness");
		DeleteAttribute(refOfficer,"perks.list.ImproveAiming");
		DeleteAttribute(refOfficer,"perks.list.ImproveSmuggling");
		DeleteAttribute(refOfficer,"perks.list.AdvanceSmuggling");
		DeleteAttribute(refOfficer,"perks.list.ImprovePotions");
		DeleteAttribute(refOfficer,"perks.list.DefendPoison");
		DeleteAttribute(refOfficer,"perks.list.Cooking");
		DeleteAttribute(refOfficer,"perks.list.HighStakes");
		DeleteAttribute(refOfficer,"perks.list.Disguiser");
		
		DialogExit();		
		PlayStereoSound("INTERFACE\ITTB.wav");			
		LaunchCharacter(PChar);
	
	break;
	
	case "PerkReset_The_Characters":
	
			// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- start -----------

	intOfficer = sti(GetOfficersIndex(PChar,1));
	refOfficer = GetCharacter(intOfficer);
	
			// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- start -----------

	intOfficer = sti(GetOfficersIndex(PChar,1));
	refOfficer = GetCharacter(intOfficer);
	
		// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------	
		
		intRank       = refOfficer.rank;
        intFreePerks                = intRank;
        if (intFreePerks < 0) 
        {
            intFreePerks = 0;
        }
        refOfficer.perks.freepoints = intFreePerks;
        
        DeleteAttribute(refOfficer,"perks.list.BasicDefence");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDefence");
        DeleteAttribute(refOfficer,"perks.list.SwordplayProfessional");
        DeleteAttribute(refOfficer,"perks.list.Rush");
        DeleteAttribute(refOfficer,"perks.list.CriticalHit");
        DeleteAttribute(refOfficer,"perks.list.Gunman");
        DeleteAttribute(refOfficer,"perks.list.GunProfessional");
        DeleteAttribute(refOfficer,"perks.list.FastReload");
        DeleteAttribute(refOfficer,"perks.list.ImmediateReload");
        DeleteAttribute(refOfficer,"perks.list.HullDamageUp");
        DeleteAttribute(refOfficer,"perks.list.SailsDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CrewDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CriticalShoot");
        DeleteAttribute(refOfficer,"perks.list.LongRangeShoot");
        DeleteAttribute(refOfficer,"perks.list.CannonProfessional");
        DeleteAttribute(refOfficer,"perks.list.LongRangeGrappling");
        DeleteAttribute(refOfficer,"perks.list.MusketsShoot");
        DeleteAttribute(refOfficer,"perks.list.GrapplingProfessional");
        DeleteAttribute(refOfficer,"perks.list.InstantBoarding");
        DeleteAttribute(refOfficer,"perks.list.BasicDamageControl");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDamageControl");
        DeleteAttribute(refOfficer,"perks.list.ProfessionalDamageControl");
        DeleteAttribute(refOfficer,"perks.list.BasicFirstAid");
        DeleteAttribute(refOfficer,"perks.list.AdvancedFirstAid");
        DeleteAttribute(refOfficer,"perks.list.Rigging");
        DeleteAttribute(refOfficer,"perks.list.RiggingAdvance");
        DeleteAttribute(refOfficer,"perks.list.LightRepair");
        DeleteAttribute(refOfficer,"perks.list.InstantRepair");
        DeleteAttribute(refOfficer,"perks.list.ShipSpeedUp");
        DeleteAttribute(refOfficer,"perks.list.ShipTurnRateUp");
        DeleteAttribute(refOfficer,"perks.list.StormProfessional");
        DeleteAttribute(refOfficer,"perks.list.Turn180");
        DeleteAttribute(refOfficer,"perks.list.SandbankManeuver");
        DeleteAttribute(refOfficer,"perks.list.SailingProfessional");
        DeleteAttribute(refOfficer,"perks.list.IronWill");
        DeleteAttribute(refOfficer,"perks.list.SharedExperience");
        DeleteAttribute(refOfficer,"perks.list.Brander");
        DeleteAttribute(refOfficer,"perks.list.Troopers");
        DeleteAttribute(refOfficer,"perks.list.Trustworthy");
        DeleteAttribute(refOfficer,"perks.list.BasicCommerce");
        DeleteAttribute(refOfficer,"perks.list.AdvancedCommerce");
        DeleteAttribute(refOfficer,"perks.list.BasicLandOwner");
		DeleteAttribute(refOfficer,"perks.list.Toughness");
		DeleteAttribute(refOfficer,"perks.list.ImproveAiming");
		DeleteAttribute(refOfficer,"perks.list.ImproveSmuggling");
		DeleteAttribute(refOfficer,"perks.list.AdvanceSmuggling");
		DeleteAttribute(refOfficer,"perks.list.ImprovePotions");
		DeleteAttribute(refOfficer,"perks.list.DefendPoison");
		DeleteAttribute(refOfficer,"perks.list.Cooking");
		DeleteAttribute(refOfficer,"perks.list.HighStakes");
		DeleteAttribute(refOfficer,"perks.list.Disguiser");
        
		intOfficer = sti(GetOfficersIndex(PChar,2));
	refOfficer = GetCharacter(intOfficer);
	
		// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------	
		
		intRank       = refOfficer.rank;
        intFreePerks                = intRank;
        if (intFreePerks < 0) 
        {
            intFreePerks = 0;
        }
        refOfficer.perks.freepoints = intFreePerks;
        
        DeleteAttribute(refOfficer,"perks.list.BasicDefence");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDefence");
        DeleteAttribute(refOfficer,"perks.list.SwordplayProfessional");
        DeleteAttribute(refOfficer,"perks.list.Rush");
        DeleteAttribute(refOfficer,"perks.list.CriticalHit");
        DeleteAttribute(refOfficer,"perks.list.Gunman");
        DeleteAttribute(refOfficer,"perks.list.GunProfessional");
        DeleteAttribute(refOfficer,"perks.list.FastReload");
        DeleteAttribute(refOfficer,"perks.list.ImmediateReload");
        DeleteAttribute(refOfficer,"perks.list.HullDamageUp");
        DeleteAttribute(refOfficer,"perks.list.SailsDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CrewDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CriticalShoot");
        DeleteAttribute(refOfficer,"perks.list.LongRangeShoot");
        DeleteAttribute(refOfficer,"perks.list.CannonProfessional");
        DeleteAttribute(refOfficer,"perks.list.LongRangeGrappling");
        DeleteAttribute(refOfficer,"perks.list.MusketsShoot");
        DeleteAttribute(refOfficer,"perks.list.GrapplingProfessional");
        DeleteAttribute(refOfficer,"perks.list.InstantBoarding");
        DeleteAttribute(refOfficer,"perks.list.BasicDamageControl");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDamageControl");
        DeleteAttribute(refOfficer,"perks.list.ProfessionalDamageControl");
        DeleteAttribute(refOfficer,"perks.list.BasicFirstAid");
        DeleteAttribute(refOfficer,"perks.list.AdvancedFirstAid");
        DeleteAttribute(refOfficer,"perks.list.Rigging");
        DeleteAttribute(refOfficer,"perks.list.RiggingAdvance");
        DeleteAttribute(refOfficer,"perks.list.LightRepair");
        DeleteAttribute(refOfficer,"perks.list.InstantRepair");
        DeleteAttribute(refOfficer,"perks.list.ShipSpeedUp");
        DeleteAttribute(refOfficer,"perks.list.ShipTurnRateUp");
        DeleteAttribute(refOfficer,"perks.list.StormProfessional");
        DeleteAttribute(refOfficer,"perks.list.Turn180");
        DeleteAttribute(refOfficer,"perks.list.SandbankManeuver");
        DeleteAttribute(refOfficer,"perks.list.SailingProfessional");
        DeleteAttribute(refOfficer,"perks.list.IronWill");
        DeleteAttribute(refOfficer,"perks.list.SharedExperience");
        DeleteAttribute(refOfficer,"perks.list.Brander");
        DeleteAttribute(refOfficer,"perks.list.Troopers");
        DeleteAttribute(refOfficer,"perks.list.Trustworthy");
        DeleteAttribute(refOfficer,"perks.list.BasicCommerce");
        DeleteAttribute(refOfficer,"perks.list.AdvancedCommerce");
        DeleteAttribute(refOfficer,"perks.list.BasicLandOwner");
		DeleteAttribute(refOfficer,"perks.list.Toughness");
		DeleteAttribute(refOfficer,"perks.list.ImproveAiming");
		DeleteAttribute(refOfficer,"perks.list.ImproveSmuggling");
		DeleteAttribute(refOfficer,"perks.list.AdvanceSmuggling");
		DeleteAttribute(refOfficer,"perks.list.ImprovePotions");
		DeleteAttribute(refOfficer,"perks.list.DefendPoison");
		DeleteAttribute(refOfficer,"perks.list.Cooking");
		DeleteAttribute(refOfficer,"perks.list.HighStakes");
		DeleteAttribute(refOfficer,"perks.list.Disguiser");
		

		intOfficer = sti(GetOfficersIndex(PChar,3));
	refOfficer = GetCharacter(intOfficer);
	
		// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------	
		
		intRank       = refOfficer.rank;
        intFreePerks                = intRank;
        if (intFreePerks < 0) 
        {
            intFreePerks = 0;
        }
        refOfficer.perks.freepoints = intFreePerks;
        
        DeleteAttribute(refOfficer,"perks.list.BasicDefence");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDefence");
        DeleteAttribute(refOfficer,"perks.list.SwordplayProfessional");
        DeleteAttribute(refOfficer,"perks.list.Rush");
        DeleteAttribute(refOfficer,"perks.list.CriticalHit");
        DeleteAttribute(refOfficer,"perks.list.Gunman");
        DeleteAttribute(refOfficer,"perks.list.GunProfessional");
        DeleteAttribute(refOfficer,"perks.list.FastReload");
        DeleteAttribute(refOfficer,"perks.list.ImmediateReload");
        DeleteAttribute(refOfficer,"perks.list.HullDamageUp");
        DeleteAttribute(refOfficer,"perks.list.SailsDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CrewDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CriticalShoot");
        DeleteAttribute(refOfficer,"perks.list.LongRangeShoot");
        DeleteAttribute(refOfficer,"perks.list.CannonProfessional");
        DeleteAttribute(refOfficer,"perks.list.LongRangeGrappling");
        DeleteAttribute(refOfficer,"perks.list.MusketsShoot");
        DeleteAttribute(refOfficer,"perks.list.GrapplingProfessional");
        DeleteAttribute(refOfficer,"perks.list.InstantBoarding");
        DeleteAttribute(refOfficer,"perks.list.BasicDamageControl");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDamageControl");
        DeleteAttribute(refOfficer,"perks.list.ProfessionalDamageControl");
        DeleteAttribute(refOfficer,"perks.list.BasicFirstAid");
        DeleteAttribute(refOfficer,"perks.list.AdvancedFirstAid");
        DeleteAttribute(refOfficer,"perks.list.Rigging");
        DeleteAttribute(refOfficer,"perks.list.RiggingAdvance");
        DeleteAttribute(refOfficer,"perks.list.LightRepair");
        DeleteAttribute(refOfficer,"perks.list.InstantRepair");
        DeleteAttribute(refOfficer,"perks.list.ShipSpeedUp");
        DeleteAttribute(refOfficer,"perks.list.ShipTurnRateUp");
        DeleteAttribute(refOfficer,"perks.list.StormProfessional");
        DeleteAttribute(refOfficer,"perks.list.Turn180");
        DeleteAttribute(refOfficer,"perks.list.SandbankManeuver");
        DeleteAttribute(refOfficer,"perks.list.SailingProfessional");
        DeleteAttribute(refOfficer,"perks.list.IronWill");
        DeleteAttribute(refOfficer,"perks.list.SharedExperience");
        DeleteAttribute(refOfficer,"perks.list.Brander");
        DeleteAttribute(refOfficer,"perks.list.Troopers");
        DeleteAttribute(refOfficer,"perks.list.Trustworthy");
        DeleteAttribute(refOfficer,"perks.list.BasicCommerce");
        DeleteAttribute(refOfficer,"perks.list.AdvancedCommerce");
        DeleteAttribute(refOfficer,"perks.list.BasicLandOwner");
		DeleteAttribute(refOfficer,"perks.list.Toughness");
		DeleteAttribute(refOfficer,"perks.list.ImproveAiming");
		DeleteAttribute(refOfficer,"perks.list.ImproveSmuggling");
		DeleteAttribute(refOfficer,"perks.list.AdvanceSmuggling");
		DeleteAttribute(refOfficer,"perks.list.ImprovePotions");
		DeleteAttribute(refOfficer,"perks.list.DefendPoison");
		DeleteAttribute(refOfficer,"perks.list.Cooking");
		DeleteAttribute(refOfficer,"perks.list.HighStakes");
		DeleteAttribute(refOfficer,"perks.list.Disguiser");
		
	
	// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------	
		
		intRank       = PChar.rank;
        intFreePerks           = intRank;
        if (intFreePerks < 0) 
        {
            intFreePerks = 0;
        }
        PChar.perks.freepoints = intFreePerks;
        
        DeleteAttribute(PChar,"perks.list.BasicDefence");
        DeleteAttribute(PChar,"perks.list.AdvancedDefence");
        DeleteAttribute(PChar,"perks.list.SwordplayProfessional");
        DeleteAttribute(PChar,"perks.list.Rush");
        DeleteAttribute(PChar,"perks.list.CriticalHit");
        DeleteAttribute(PChar,"perks.list.Gunman");
        DeleteAttribute(PChar,"perks.list.GunProfessional");
        DeleteAttribute(PChar,"perks.list.FastReload");
        DeleteAttribute(PChar,"perks.list.ImmediateReload");
        DeleteAttribute(PChar,"perks.list.HullDamageUp");
        DeleteAttribute(PChar,"perks.list.SailsDamageUp");
        DeleteAttribute(PChar,"perks.list.CrewDamageUp");
        DeleteAttribute(PChar,"perks.list.CriticalShoot");
        DeleteAttribute(PChar,"perks.list.LongRangeShoot");
        DeleteAttribute(PChar,"perks.list.CannonProfessional");
        DeleteAttribute(PChar,"perks.list.LongRangeGrappling");
        DeleteAttribute(PChar,"perks.list.MusketsShoot");
        DeleteAttribute(PChar,"perks.list.GrapplingProfessional");
        DeleteAttribute(PChar,"perks.list.InstantBoarding");
        DeleteAttribute(PChar,"perks.list.BasicDamageControl");
        DeleteAttribute(PChar,"perks.list.AdvancedDamageControl");
        DeleteAttribute(PChar,"perks.list.ProfessionalDamageControl");
        DeleteAttribute(PChar,"perks.list.BasicFirstAid");
        DeleteAttribute(PChar,"perks.list.AdvancedFirstAid");
        DeleteAttribute(PChar,"perks.list.Rigging");
        DeleteAttribute(PChar,"perks.list.RiggingAdvance");
        DeleteAttribute(PChar,"perks.list.LightRepair");
        DeleteAttribute(PChar,"perks.list.InstantRepair");
        DeleteAttribute(PChar,"perks.list.ShipSpeedUp");
        DeleteAttribute(PChar,"perks.list.ShipTurnRateUp");
        DeleteAttribute(PChar,"perks.list.StormProfessional");
        DeleteAttribute(PChar,"perks.list.Turn180");
        DeleteAttribute(PChar,"perks.list.SandbankManeuver");
        DeleteAttribute(PChar,"perks.list.SailingProfessional");
        DeleteAttribute(PChar,"perks.list.IronWill");
        DeleteAttribute(PChar,"perks.list.SharedExperience");
        DeleteAttribute(PChar,"perks.list.Brander");
        DeleteAttribute(PChar,"perks.list.Troopers");
        DeleteAttribute(PChar,"perks.list.Trustworthy");
        DeleteAttribute(PChar,"perks.list.BasicCommerce");
        DeleteAttribute(PChar,"perks.list.AdvancedCommerce");
        DeleteAttribute(PChar,"perks.list.BasicLandOwner");
 		DeleteAttribute(PChar,"perks.list.Toughness");
		DeleteAttribute(PChar,"perks.list.ImproveAiming");
        DeleteAttribute(PChar,"perks.list.ImproveSmuggling");
        DeleteAttribute(PChar,"perks.list.AdvanceSmuggling");
        DeleteAttribute(PChar,"perks.list.ImprovePotions");
        DeleteAttribute(PChar,"perks.list.DefendPoison");
        DeleteAttribute(PChar,"perks.list.Cooking");
        DeleteAttribute(PChar,"perks.list.HighStakes");
 		DeleteAttribute(PChar,"perks.list.Disguiser");
		
        ResetHP(&PChar);
		
        DialogExit();	
		PlayStereoSound("INTERFACE\ITTB.wav");			
		LaunchCharacter(PChar);
	
	break;
	
	
	case "PerkReset_The_Main_Character":
	
		intRank       = PChar.rank;
        intFreePerks           = intRank;
        if (intFreePerks < 0) 
        {
            intFreePerks = 0;
        }
        PChar.perks.freepoints = intFreePerks;
        
        DeleteAttribute(PChar,"perks.list.BasicDefence");
        DeleteAttribute(PChar,"perks.list.AdvancedDefence");
        DeleteAttribute(PChar,"perks.list.SwordplayProfessional");
        DeleteAttribute(PChar,"perks.list.Rush");
        DeleteAttribute(PChar,"perks.list.CriticalHit");
        DeleteAttribute(PChar,"perks.list.Gunman");
        DeleteAttribute(PChar,"perks.list.GunProfessional");
        DeleteAttribute(PChar,"perks.list.FastReload");
        DeleteAttribute(PChar,"perks.list.ImmediateReload");
        DeleteAttribute(PChar,"perks.list.HullDamageUp");
        DeleteAttribute(PChar,"perks.list.SailsDamageUp");
        DeleteAttribute(PChar,"perks.list.CrewDamageUp");
        DeleteAttribute(PChar,"perks.list.CriticalShoot");
        DeleteAttribute(PChar,"perks.list.LongRangeShoot");
        DeleteAttribute(PChar,"perks.list.CannonProfessional");
        DeleteAttribute(PChar,"perks.list.LongRangeGrappling");
        DeleteAttribute(PChar,"perks.list.MusketsShoot");
        DeleteAttribute(PChar,"perks.list.GrapplingProfessional");
        DeleteAttribute(PChar,"perks.list.InstantBoarding");
        DeleteAttribute(PChar,"perks.list.BasicDamageControl");
        DeleteAttribute(PChar,"perks.list.AdvancedDamageControl");
        DeleteAttribute(PChar,"perks.list.ProfessionalDamageControl");
        DeleteAttribute(PChar,"perks.list.BasicFirstAid");
        DeleteAttribute(PChar,"perks.list.AdvancedFirstAid");
        DeleteAttribute(PChar,"perks.list.Rigging");
        DeleteAttribute(PChar,"perks.list.RiggingAdvance");
        DeleteAttribute(PChar,"perks.list.LightRepair");
        DeleteAttribute(PChar,"perks.list.InstantRepair");
        DeleteAttribute(PChar,"perks.list.ShipSpeedUp");
        DeleteAttribute(PChar,"perks.list.ShipTurnRateUp");
        DeleteAttribute(PChar,"perks.list.StormProfessional");
        DeleteAttribute(PChar,"perks.list.Turn180");
        DeleteAttribute(PChar,"perks.list.SandbankManeuver");
        DeleteAttribute(PChar,"perks.list.SailingProfessional");
        DeleteAttribute(PChar,"perks.list.IronWill");
        DeleteAttribute(PChar,"perks.list.SharedExperience");
        DeleteAttribute(PChar,"perks.list.Brander");
        DeleteAttribute(PChar,"perks.list.Troopers");
        DeleteAttribute(PChar,"perks.list.Trustworthy");
        DeleteAttribute(PChar,"perks.list.BasicCommerce");
        DeleteAttribute(PChar,"perks.list.AdvancedCommerce");
        DeleteAttribute(PChar,"perks.list.BasicLandOwner");
 		DeleteAttribute(PChar,"perks.list.Toughness");
		DeleteAttribute(PChar,"perks.list.ImproveAiming");
        DeleteAttribute(PChar,"perks.list.ImproveSmuggling");
        DeleteAttribute(PChar,"perks.list.AdvanceSmuggling");
        DeleteAttribute(PChar,"perks.list.ImprovePotions");
        DeleteAttribute(PChar,"perks.list.DefendPoison");
        DeleteAttribute(PChar,"perks.list.Cooking");
        DeleteAttribute(PChar,"perks.list.HighStakes");
 		DeleteAttribute(PChar,"perks.list.Disguiser");
		
        ResetHP(&PChar);
		
        DialogExit();		
		PlayStereoSound("INTERFACE\ITTB.wav");			
		LaunchCharacter(PChar);
	
	break;
	
// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------
		
		case "El_Rapido_ResetCharacter":    // El Rapido START
		
		// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- start -----------
            
				d.Text = DLG_TEXT[65];
                Link.l1    = DLG_TEXT[66];
                Link.l1.go = "exit";
				Link.l2    = DLG_TEXT[67];
                Link.l2.go = "Reset_The_Officers";
				Link.l3    = DLG_TEXT[68];
                Link.l3.go = "Reset_The_Main_Character";
				Link.l4    = DLG_TEXT[69];
                Link.l4.go = "Reset_The_Characters";

		break;
		
		case "Reset_The_Officers":

			// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- start -----------

	intOfficer = sti(GetOfficersIndex(PChar,1));
	refOfficer = GetCharacter(intOfficer);
	
		// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------	
		
		intRank       = refOfficer.rank;
	    intLeaderShip = refOfficer.skill.Leadership;
        intFencing    = refOfficer.skill.Fencing;
        intSailing    = refOfficer.skill.Sailing;
        intAccuracy   = refOfficer.skill.Accuracy;
        intCannons    = refOfficer.skill.Cannons;
        intGrappling  = refOfficer.skill.Grappling;
        intRepair     = refOfficer.skill.Repair;
        intDefence    = refOfficer.skill.Defence;
        intCommerce   = refOfficer.skill.Commerce;
        intSneak      = refOfficer.skill.Sneak;
        intFreeSkill  = intRank*2;
		
        if (intFreeSkill < 0) 
        {
            intFreeSkill = 0;
        }
		
        refOfficer.skill.freeskill  = intFreeSkill;
        refOfficer.skill.Leadership = "1";
        refOfficer.skill.Fencing    = "1";
        refOfficer.skill.Sailing    = "1";
        refOfficer.skill.Accuracy   = "1";
        refOfficer.skill.Cannons    = "1";
        refOfficer.skill.Grappling  = "1";
        refOfficer.skill.Repair     = "1";
        refOfficer.skill.Defence    = "1";
        refOfficer.skill.Commerce   = "1";
        refOfficer.skill.Sneak      = "1";
        intFreePerks                = intRank;
        if (intFreePerks < 0) 
        {
            intFreePerks = 0;
        }
        refOfficer.perks.freepoints = intFreePerks;
        
        DeleteAttribute(refOfficer,"perks.list.BasicDefence");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDefence");
        DeleteAttribute(refOfficer,"perks.list.SwordplayProfessional");
        DeleteAttribute(refOfficer,"perks.list.Rush");
        DeleteAttribute(refOfficer,"perks.list.CriticalHit");
        DeleteAttribute(refOfficer,"perks.list.Gunman");
        DeleteAttribute(refOfficer,"perks.list.GunProfessional");
        DeleteAttribute(refOfficer,"perks.list.FastReload");
        DeleteAttribute(refOfficer,"perks.list.ImmediateReload");
        DeleteAttribute(refOfficer,"perks.list.HullDamageUp");
        DeleteAttribute(refOfficer,"perks.list.SailsDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CrewDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CriticalShoot");
        DeleteAttribute(refOfficer,"perks.list.LongRangeShoot");
        DeleteAttribute(refOfficer,"perks.list.CannonProfessional");
        DeleteAttribute(refOfficer,"perks.list.LongRangeGrappling");
        DeleteAttribute(refOfficer,"perks.list.MusketsShoot");
        DeleteAttribute(refOfficer,"perks.list.GrapplingProfessional");
        DeleteAttribute(refOfficer,"perks.list.InstantBoarding");
        DeleteAttribute(refOfficer,"perks.list.BasicDamageControl");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDamageControl");
        DeleteAttribute(refOfficer,"perks.list.ProfessionalDamageControl");
        DeleteAttribute(refOfficer,"perks.list.BasicFirstAid");
        DeleteAttribute(refOfficer,"perks.list.AdvancedFirstAid");
        DeleteAttribute(refOfficer,"perks.list.Rigging");
        DeleteAttribute(refOfficer,"perks.list.RiggingAdvance");
        DeleteAttribute(refOfficer,"perks.list.LightRepair");
        DeleteAttribute(refOfficer,"perks.list.InstantRepair");
        DeleteAttribute(refOfficer,"perks.list.ShipSpeedUp");
        DeleteAttribute(refOfficer,"perks.list.ShipTurnRateUp");
        DeleteAttribute(refOfficer,"perks.list.StormProfessional");
        DeleteAttribute(refOfficer,"perks.list.Turn180");
        DeleteAttribute(refOfficer,"perks.list.SandbankManeuver");
        DeleteAttribute(refOfficer,"perks.list.SailingProfessional");
        DeleteAttribute(refOfficer,"perks.list.IronWill");
        DeleteAttribute(refOfficer,"perks.list.SharedExperience");
        DeleteAttribute(refOfficer,"perks.list.Brander");
        DeleteAttribute(refOfficer,"perks.list.Troopers");
        DeleteAttribute(refOfficer,"perks.list.Trustworthy");
        DeleteAttribute(refOfficer,"perks.list.BasicCommerce");
        DeleteAttribute(refOfficer,"perks.list.AdvancedCommerce");
        DeleteAttribute(refOfficer,"perks.list.BasicLandOwner");
		DeleteAttribute(refOfficer,"perks.list.Toughness");
		DeleteAttribute(refOfficer,"perks.list.ImproveAiming");
		DeleteAttribute(refOfficer,"perks.list.ImproveSmuggling");
		DeleteAttribute(refOfficer,"perks.list.AdvanceSmuggling");
		DeleteAttribute(refOfficer,"perks.list.ImprovePotions");
		DeleteAttribute(refOfficer,"perks.list.DefendPoison");
		DeleteAttribute(refOfficer,"perks.list.Cooking");
		DeleteAttribute(refOfficer,"perks.list.HighStakes");
		DeleteAttribute(refOfficer,"perks.list.Disguiser");
        
        ResetHP(&refOfficer);
	
	
		intOfficer = sti(GetOfficersIndex(PChar,2));
	refOfficer = GetCharacter(intOfficer);
	
		// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------	
		
		intRank       = refOfficer.rank;
	    intLeaderShip = refOfficer.skill.Leadership;
        intFencing    = refOfficer.skill.Fencing;
        intSailing    = refOfficer.skill.Sailing;
        intAccuracy   = refOfficer.skill.Accuracy;
        intCannons    = refOfficer.skill.Cannons;
        intGrappling  = refOfficer.skill.Grappling;
        intRepair     = refOfficer.skill.Repair;
        intDefence    = refOfficer.skill.Defence;
        intCommerce   = refOfficer.skill.Commerce;
        intSneak      = refOfficer.skill.Sneak;
        intFreeSkill  = intRank*2;
		
        if (intFreeSkill < 0) 
        {
            intFreeSkill = 0;
        }
		
        refOfficer.skill.freeskill  = intFreeSkill;
        refOfficer.skill.Leadership = "1";
        refOfficer.skill.Fencing    = "1";
        refOfficer.skill.Sailing    = "1";
        refOfficer.skill.Accuracy   = "1";
        refOfficer.skill.Cannons    = "1";
        refOfficer.skill.Grappling  = "1";
        refOfficer.skill.Repair     = "1";
        refOfficer.skill.Defence    = "1";
        refOfficer.skill.Commerce   = "1";
        refOfficer.skill.Sneak      = "1";
        intFreePerks                = intRank;
        if (intFreePerks < 0) 
        {
            intFreePerks = 0;
        }
        refOfficer.perks.freepoints = intFreePerks;
        
        DeleteAttribute(refOfficer,"perks.list.BasicDefence");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDefence");
        DeleteAttribute(refOfficer,"perks.list.SwordplayProfessional");
        DeleteAttribute(refOfficer,"perks.list.Rush");
        DeleteAttribute(refOfficer,"perks.list.CriticalHit");
        DeleteAttribute(refOfficer,"perks.list.Gunman");
        DeleteAttribute(refOfficer,"perks.list.GunProfessional");
        DeleteAttribute(refOfficer,"perks.list.FastReload");
        DeleteAttribute(refOfficer,"perks.list.ImmediateReload");
        DeleteAttribute(refOfficer,"perks.list.HullDamageUp");
        DeleteAttribute(refOfficer,"perks.list.SailsDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CrewDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CriticalShoot");
        DeleteAttribute(refOfficer,"perks.list.LongRangeShoot");
        DeleteAttribute(refOfficer,"perks.list.CannonProfessional");
        DeleteAttribute(refOfficer,"perks.list.LongRangeGrappling");
        DeleteAttribute(refOfficer,"perks.list.MusketsShoot");
        DeleteAttribute(refOfficer,"perks.list.GrapplingProfessional");
        DeleteAttribute(refOfficer,"perks.list.InstantBoarding");
        DeleteAttribute(refOfficer,"perks.list.BasicDamageControl");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDamageControl");
        DeleteAttribute(refOfficer,"perks.list.ProfessionalDamageControl");
        DeleteAttribute(refOfficer,"perks.list.BasicFirstAid");
        DeleteAttribute(refOfficer,"perks.list.AdvancedFirstAid");
        DeleteAttribute(refOfficer,"perks.list.Rigging");
        DeleteAttribute(refOfficer,"perks.list.RiggingAdvance");
        DeleteAttribute(refOfficer,"perks.list.LightRepair");
        DeleteAttribute(refOfficer,"perks.list.InstantRepair");
        DeleteAttribute(refOfficer,"perks.list.ShipSpeedUp");
        DeleteAttribute(refOfficer,"perks.list.ShipTurnRateUp");
        DeleteAttribute(refOfficer,"perks.list.StormProfessional");
        DeleteAttribute(refOfficer,"perks.list.Turn180");
        DeleteAttribute(refOfficer,"perks.list.SandbankManeuver");
        DeleteAttribute(refOfficer,"perks.list.SailingProfessional");
        DeleteAttribute(refOfficer,"perks.list.IronWill");
        DeleteAttribute(refOfficer,"perks.list.SharedExperience");
        DeleteAttribute(refOfficer,"perks.list.Brander");
        DeleteAttribute(refOfficer,"perks.list.Troopers");
        DeleteAttribute(refOfficer,"perks.list.Trustworthy");
        DeleteAttribute(refOfficer,"perks.list.BasicCommerce");
        DeleteAttribute(refOfficer,"perks.list.AdvancedCommerce");
        DeleteAttribute(refOfficer,"perks.list.BasicLandOwner");
		DeleteAttribute(refOfficer,"perks.list.Toughness");
		DeleteAttribute(refOfficer,"perks.list.ImproveAiming");
		DeleteAttribute(refOfficer,"perks.list.ImproveSmuggling");
		DeleteAttribute(refOfficer,"perks.list.AdvanceSmuggling");
		DeleteAttribute(refOfficer,"perks.list.ImprovePotions");
		DeleteAttribute(refOfficer,"perks.list.DefendPoison");
		DeleteAttribute(refOfficer,"perks.list.Cooking");
		DeleteAttribute(refOfficer,"perks.list.HighStakes");
		DeleteAttribute(refOfficer,"perks.list.Disguiser");
		
        ResetHP(&refOfficer);
	
	
		intOfficer = sti(GetOfficersIndex(PChar,3));
	refOfficer = GetCharacter(intOfficer);
	
		// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------	
		
		intRank       = refOfficer.rank;
	    intLeaderShip = refOfficer.skill.Leadership;
        intFencing    = refOfficer.skill.Fencing;
        intSailing    = refOfficer.skill.Sailing;
        intAccuracy   = refOfficer.skill.Accuracy;
        intCannons    = refOfficer.skill.Cannons;
        intGrappling  = refOfficer.skill.Grappling;
        intRepair     = refOfficer.skill.Repair;
        intDefence    = refOfficer.skill.Defence;
        intCommerce   = refOfficer.skill.Commerce;
        intSneak      = refOfficer.skill.Sneak;
        intFreeSkill  = intRank*2;
		
        if (intFreeSkill < 0) 
        {
            intFreeSkill = 0;
        }
		
        refOfficer.skill.freeskill  = intFreeSkill;
        refOfficer.skill.Leadership = "1";
        refOfficer.skill.Fencing    = "1";
        refOfficer.skill.Sailing    = "1";
        refOfficer.skill.Accuracy   = "1";
        refOfficer.skill.Cannons    = "1";
        refOfficer.skill.Grappling  = "1";
        refOfficer.skill.Repair     = "1";
        refOfficer.skill.Defence    = "1";
        refOfficer.skill.Commerce   = "1";
        refOfficer.skill.Sneak      = "1";
        intFreePerks                = intRank;
        if (intFreePerks < 0) 
        {
            intFreePerks = 0;
        }
        refOfficer.perks.freepoints = intFreePerks;
        
        DeleteAttribute(refOfficer,"perks.list.BasicDefence");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDefence");
        DeleteAttribute(refOfficer,"perks.list.SwordplayProfessional");
        DeleteAttribute(refOfficer,"perks.list.Rush");
        DeleteAttribute(refOfficer,"perks.list.CriticalHit");
        DeleteAttribute(refOfficer,"perks.list.Gunman");
        DeleteAttribute(refOfficer,"perks.list.GunProfessional");
        DeleteAttribute(refOfficer,"perks.list.FastReload");
        DeleteAttribute(refOfficer,"perks.list.ImmediateReload");
        DeleteAttribute(refOfficer,"perks.list.HullDamageUp");
        DeleteAttribute(refOfficer,"perks.list.SailsDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CrewDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CriticalShoot");
        DeleteAttribute(refOfficer,"perks.list.LongRangeShoot");
        DeleteAttribute(refOfficer,"perks.list.CannonProfessional");
        DeleteAttribute(refOfficer,"perks.list.LongRangeGrappling");
        DeleteAttribute(refOfficer,"perks.list.MusketsShoot");
        DeleteAttribute(refOfficer,"perks.list.GrapplingProfessional");
        DeleteAttribute(refOfficer,"perks.list.InstantBoarding");
        DeleteAttribute(refOfficer,"perks.list.BasicDamageControl");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDamageControl");
        DeleteAttribute(refOfficer,"perks.list.ProfessionalDamageControl");
        DeleteAttribute(refOfficer,"perks.list.BasicFirstAid");
        DeleteAttribute(refOfficer,"perks.list.AdvancedFirstAid");
        DeleteAttribute(refOfficer,"perks.list.Rigging");
        DeleteAttribute(refOfficer,"perks.list.RiggingAdvance");
        DeleteAttribute(refOfficer,"perks.list.LightRepair");
        DeleteAttribute(refOfficer,"perks.list.InstantRepair");
        DeleteAttribute(refOfficer,"perks.list.ShipSpeedUp");
        DeleteAttribute(refOfficer,"perks.list.ShipTurnRateUp");
        DeleteAttribute(refOfficer,"perks.list.StormProfessional");
        DeleteAttribute(refOfficer,"perks.list.Turn180");
        DeleteAttribute(refOfficer,"perks.list.SandbankManeuver");
        DeleteAttribute(refOfficer,"perks.list.SailingProfessional");
        DeleteAttribute(refOfficer,"perks.list.IronWill");
        DeleteAttribute(refOfficer,"perks.list.SharedExperience");
        DeleteAttribute(refOfficer,"perks.list.Brander");
        DeleteAttribute(refOfficer,"perks.list.Troopers");
        DeleteAttribute(refOfficer,"perks.list.Trustworthy");
        DeleteAttribute(refOfficer,"perks.list.BasicCommerce");
        DeleteAttribute(refOfficer,"perks.list.AdvancedCommerce");
        DeleteAttribute(refOfficer,"perks.list.BasicLandOwner");
		DeleteAttribute(refOfficer,"perks.list.Toughness");
		DeleteAttribute(refOfficer,"perks.list.ImproveAiming");
		DeleteAttribute(refOfficer,"perks.list.ImproveSmuggling");
		DeleteAttribute(refOfficer,"perks.list.AdvanceSmuggling");
		DeleteAttribute(refOfficer,"perks.list.ImprovePotions");
		DeleteAttribute(refOfficer,"perks.list.DefendPoison");
		DeleteAttribute(refOfficer,"perks.list.Cooking");
		DeleteAttribute(refOfficer,"perks.list.HighStakes");
		DeleteAttribute(refOfficer,"perks.list.Disguiser");
		
        ResetHP(&refOfficer);
		
		DialogExit();
		PlayStereoSound("INTERFACE\ITTB.wav");			
		LaunchCharacter(PChar);
	
	break;
	
	case "Reset_The_Characters":
	
			// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- start -----------

	intOfficer = sti(GetOfficersIndex(PChar,1));
	refOfficer = GetCharacter(intOfficer);
	
		// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------	
		
		intRank       = refOfficer.rank;
	    intLeaderShip = refOfficer.skill.Leadership;
        intFencing    = refOfficer.skill.Fencing;
        intSailing    = refOfficer.skill.Sailing;
        intAccuracy   = refOfficer.skill.Accuracy;
        intCannons    = refOfficer.skill.Cannons;
        intGrappling  = refOfficer.skill.Grappling;
        intRepair     = refOfficer.skill.Repair;
        intDefence    = refOfficer.skill.Defence;
        intCommerce   = refOfficer.skill.Commerce;
        intSneak      = refOfficer.skill.Sneak;
        intFreeSkill  = intRank*2;
		
        if (intFreeSkill < 0) 
        {
            intFreeSkill = 0;
        }
		
        refOfficer.skill.freeskill  = intFreeSkill;
        refOfficer.skill.Leadership = "1";
        refOfficer.skill.Fencing    = "1";
        refOfficer.skill.Sailing    = "1";
        refOfficer.skill.Accuracy   = "1";
        refOfficer.skill.Cannons    = "1";
        refOfficer.skill.Grappling  = "1";
        refOfficer.skill.Repair     = "1";
        refOfficer.skill.Defence    = "1";
        refOfficer.skill.Commerce   = "1";
        refOfficer.skill.Sneak      = "1";
        intFreePerks                = intRank;
        if (intFreePerks < 0) 
        {
            intFreePerks = 0;
        }
        refOfficer.perks.freepoints = intFreePerks;
        
        DeleteAttribute(refOfficer,"perks.list.BasicDefence");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDefence");
        DeleteAttribute(refOfficer,"perks.list.SwordplayProfessional");
        DeleteAttribute(refOfficer,"perks.list.Rush");
        DeleteAttribute(refOfficer,"perks.list.CriticalHit");
        DeleteAttribute(refOfficer,"perks.list.Gunman");
        DeleteAttribute(refOfficer,"perks.list.GunProfessional");
        DeleteAttribute(refOfficer,"perks.list.FastReload");
        DeleteAttribute(refOfficer,"perks.list.ImmediateReload");
        DeleteAttribute(refOfficer,"perks.list.HullDamageUp");
        DeleteAttribute(refOfficer,"perks.list.SailsDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CrewDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CriticalShoot");
        DeleteAttribute(refOfficer,"perks.list.LongRangeShoot");
        DeleteAttribute(refOfficer,"perks.list.CannonProfessional");
        DeleteAttribute(refOfficer,"perks.list.LongRangeGrappling");
        DeleteAttribute(refOfficer,"perks.list.MusketsShoot");
        DeleteAttribute(refOfficer,"perks.list.GrapplingProfessional");
        DeleteAttribute(refOfficer,"perks.list.InstantBoarding");
        DeleteAttribute(refOfficer,"perks.list.BasicDamageControl");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDamageControl");
        DeleteAttribute(refOfficer,"perks.list.ProfessionalDamageControl");
        DeleteAttribute(refOfficer,"perks.list.BasicFirstAid");
        DeleteAttribute(refOfficer,"perks.list.AdvancedFirstAid");
        DeleteAttribute(refOfficer,"perks.list.Rigging");
        DeleteAttribute(refOfficer,"perks.list.RiggingAdvance");
        DeleteAttribute(refOfficer,"perks.list.LightRepair");
        DeleteAttribute(refOfficer,"perks.list.InstantRepair");
        DeleteAttribute(refOfficer,"perks.list.ShipSpeedUp");
        DeleteAttribute(refOfficer,"perks.list.ShipTurnRateUp");
        DeleteAttribute(refOfficer,"perks.list.StormProfessional");
        DeleteAttribute(refOfficer,"perks.list.Turn180");
        DeleteAttribute(refOfficer,"perks.list.SandbankManeuver");
        DeleteAttribute(refOfficer,"perks.list.SailingProfessional");
        DeleteAttribute(refOfficer,"perks.list.IronWill");
        DeleteAttribute(refOfficer,"perks.list.SharedExperience");
        DeleteAttribute(refOfficer,"perks.list.Brander");
        DeleteAttribute(refOfficer,"perks.list.Troopers");
        DeleteAttribute(refOfficer,"perks.list.Trustworthy");
        DeleteAttribute(refOfficer,"perks.list.BasicCommerce");
        DeleteAttribute(refOfficer,"perks.list.AdvancedCommerce");
        DeleteAttribute(refOfficer,"perks.list.BasicLandOwner");
		DeleteAttribute(refOfficer,"perks.list.Toughness");
		DeleteAttribute(refOfficer,"perks.list.ImproveAiming");
		DeleteAttribute(refOfficer,"perks.list.ImproveSmuggling");
		DeleteAttribute(refOfficer,"perks.list.AdvanceSmuggling");
		DeleteAttribute(refOfficer,"perks.list.ImprovePotions");
		DeleteAttribute(refOfficer,"perks.list.DefendPoison");
		DeleteAttribute(refOfficer,"perks.list.Cooking");
		DeleteAttribute(refOfficer,"perks.list.HighStakes");
		DeleteAttribute(refOfficer,"perks.list.Disguiser");
        
        ResetHP(&refOfficer);
	
	
		intOfficer = sti(GetOfficersIndex(PChar,2));
	refOfficer = GetCharacter(intOfficer);
	
		// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------	
		
		intRank       = refOfficer.rank;
	    intLeaderShip = refOfficer.skill.Leadership;
        intFencing    = refOfficer.skill.Fencing;
        intSailing    = refOfficer.skill.Sailing;
        intAccuracy   = refOfficer.skill.Accuracy;
        intCannons    = refOfficer.skill.Cannons;
        intGrappling  = refOfficer.skill.Grappling;
        intRepair     = refOfficer.skill.Repair;
        intDefence    = refOfficer.skill.Defence;
        intCommerce   = refOfficer.skill.Commerce;
        intSneak      = refOfficer.skill.Sneak;
        intFreeSkill  = intRank*2;
		
        if (intFreeSkill < 0) 
        {
            intFreeSkill = 0;
        }
		
        refOfficer.skill.freeskill  = intFreeSkill;
        refOfficer.skill.Leadership = "1";
        refOfficer.skill.Fencing    = "1";
        refOfficer.skill.Sailing    = "1";
        refOfficer.skill.Accuracy   = "1";
        refOfficer.skill.Cannons    = "1";
        refOfficer.skill.Grappling  = "1";
        refOfficer.skill.Repair     = "1";
        refOfficer.skill.Defence    = "1";
        refOfficer.skill.Commerce   = "1";
        refOfficer.skill.Sneak      = "1";
        intFreePerks                = intRank;
        if (intFreePerks < 0) 
        {
            intFreePerks = 0;
        }
        refOfficer.perks.freepoints = intFreePerks;
        
        DeleteAttribute(refOfficer,"perks.list.BasicDefence");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDefence");
        DeleteAttribute(refOfficer,"perks.list.SwordplayProfessional");
        DeleteAttribute(refOfficer,"perks.list.Rush");
        DeleteAttribute(refOfficer,"perks.list.CriticalHit");
        DeleteAttribute(refOfficer,"perks.list.Gunman");
        DeleteAttribute(refOfficer,"perks.list.GunProfessional");
        DeleteAttribute(refOfficer,"perks.list.FastReload");
        DeleteAttribute(refOfficer,"perks.list.ImmediateReload");
        DeleteAttribute(refOfficer,"perks.list.HullDamageUp");
        DeleteAttribute(refOfficer,"perks.list.SailsDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CrewDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CriticalShoot");
        DeleteAttribute(refOfficer,"perks.list.LongRangeShoot");
        DeleteAttribute(refOfficer,"perks.list.CannonProfessional");
        DeleteAttribute(refOfficer,"perks.list.LongRangeGrappling");
        DeleteAttribute(refOfficer,"perks.list.MusketsShoot");
        DeleteAttribute(refOfficer,"perks.list.GrapplingProfessional");
        DeleteAttribute(refOfficer,"perks.list.InstantBoarding");
        DeleteAttribute(refOfficer,"perks.list.BasicDamageControl");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDamageControl");
        DeleteAttribute(refOfficer,"perks.list.ProfessionalDamageControl");
        DeleteAttribute(refOfficer,"perks.list.BasicFirstAid");
        DeleteAttribute(refOfficer,"perks.list.AdvancedFirstAid");
        DeleteAttribute(refOfficer,"perks.list.Rigging");
        DeleteAttribute(refOfficer,"perks.list.RiggingAdvance");
        DeleteAttribute(refOfficer,"perks.list.LightRepair");
        DeleteAttribute(refOfficer,"perks.list.InstantRepair");
        DeleteAttribute(refOfficer,"perks.list.ShipSpeedUp");
        DeleteAttribute(refOfficer,"perks.list.ShipTurnRateUp");
        DeleteAttribute(refOfficer,"perks.list.StormProfessional");
        DeleteAttribute(refOfficer,"perks.list.Turn180");
        DeleteAttribute(refOfficer,"perks.list.SandbankManeuver");
        DeleteAttribute(refOfficer,"perks.list.SailingProfessional");
        DeleteAttribute(refOfficer,"perks.list.IronWill");
        DeleteAttribute(refOfficer,"perks.list.SharedExperience");
        DeleteAttribute(refOfficer,"perks.list.Brander");
        DeleteAttribute(refOfficer,"perks.list.Troopers");
        DeleteAttribute(refOfficer,"perks.list.Trustworthy");
        DeleteAttribute(refOfficer,"perks.list.BasicCommerce");
        DeleteAttribute(refOfficer,"perks.list.AdvancedCommerce");
        DeleteAttribute(refOfficer,"perks.list.BasicLandOwner");
		DeleteAttribute(refOfficer,"perks.list.Toughness");
		DeleteAttribute(refOfficer,"perks.list.ImproveAiming");
		DeleteAttribute(refOfficer,"perks.list.ImproveSmuggling");
		DeleteAttribute(refOfficer,"perks.list.AdvanceSmuggling");
		DeleteAttribute(refOfficer,"perks.list.ImprovePotions");
		DeleteAttribute(refOfficer,"perks.list.DefendPoison");
		DeleteAttribute(refOfficer,"perks.list.Cooking");
		DeleteAttribute(refOfficer,"perks.list.HighStakes");
		DeleteAttribute(refOfficer,"perks.list.Disguiser");
		
        ResetHP(&refOfficer);
	
	
		intOfficer = sti(GetOfficersIndex(PChar,3));
	refOfficer = GetCharacter(intOfficer);
	
		// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------	
		
		intRank       = refOfficer.rank;
	    intLeaderShip = refOfficer.skill.Leadership;
        intFencing    = refOfficer.skill.Fencing;
        intSailing    = refOfficer.skill.Sailing;
        intAccuracy   = refOfficer.skill.Accuracy;
        intCannons    = refOfficer.skill.Cannons;
        intGrappling  = refOfficer.skill.Grappling;
        intRepair     = refOfficer.skill.Repair;
        intDefence    = refOfficer.skill.Defence;
        intCommerce   = refOfficer.skill.Commerce;
        intSneak      = refOfficer.skill.Sneak;
        intFreeSkill  = intRank*2;
		
        if (intFreeSkill < 0) 
        {
            intFreeSkill = 0;
        }
		
        refOfficer.skill.freeskill  = intFreeSkill;
        refOfficer.skill.Leadership = "1";
        refOfficer.skill.Fencing    = "1";
        refOfficer.skill.Sailing    = "1";
        refOfficer.skill.Accuracy   = "1";
        refOfficer.skill.Cannons    = "1";
        refOfficer.skill.Grappling  = "1";
        refOfficer.skill.Repair     = "1";
        refOfficer.skill.Defence    = "1";
        refOfficer.skill.Commerce   = "1";
        refOfficer.skill.Sneak      = "1";
        intFreePerks                = intRank;
        if (intFreePerks < 0) 
        {
            intFreePerks = 0;
        }
        refOfficer.perks.freepoints = intFreePerks;
        
        DeleteAttribute(refOfficer,"perks.list.BasicDefence");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDefence");
        DeleteAttribute(refOfficer,"perks.list.SwordplayProfessional");
        DeleteAttribute(refOfficer,"perks.list.Rush");
        DeleteAttribute(refOfficer,"perks.list.CriticalHit");
        DeleteAttribute(refOfficer,"perks.list.Gunman");
        DeleteAttribute(refOfficer,"perks.list.GunProfessional");
        DeleteAttribute(refOfficer,"perks.list.FastReload");
        DeleteAttribute(refOfficer,"perks.list.ImmediateReload");
        DeleteAttribute(refOfficer,"perks.list.HullDamageUp");
        DeleteAttribute(refOfficer,"perks.list.SailsDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CrewDamageUp");
        DeleteAttribute(refOfficer,"perks.list.CriticalShoot");
        DeleteAttribute(refOfficer,"perks.list.LongRangeShoot");
        DeleteAttribute(refOfficer,"perks.list.CannonProfessional");
        DeleteAttribute(refOfficer,"perks.list.LongRangeGrappling");
        DeleteAttribute(refOfficer,"perks.list.MusketsShoot");
        DeleteAttribute(refOfficer,"perks.list.GrapplingProfessional");
        DeleteAttribute(refOfficer,"perks.list.InstantBoarding");
        DeleteAttribute(refOfficer,"perks.list.BasicDamageControl");
        DeleteAttribute(refOfficer,"perks.list.AdvancedDamageControl");
        DeleteAttribute(refOfficer,"perks.list.ProfessionalDamageControl");
        DeleteAttribute(refOfficer,"perks.list.BasicFirstAid");
        DeleteAttribute(refOfficer,"perks.list.AdvancedFirstAid");
        DeleteAttribute(refOfficer,"perks.list.Rigging");
        DeleteAttribute(refOfficer,"perks.list.RiggingAdvance");
        DeleteAttribute(refOfficer,"perks.list.LightRepair");
        DeleteAttribute(refOfficer,"perks.list.InstantRepair");
        DeleteAttribute(refOfficer,"perks.list.ShipSpeedUp");
        DeleteAttribute(refOfficer,"perks.list.ShipTurnRateUp");
        DeleteAttribute(refOfficer,"perks.list.StormProfessional");
        DeleteAttribute(refOfficer,"perks.list.Turn180");
        DeleteAttribute(refOfficer,"perks.list.SandbankManeuver");
        DeleteAttribute(refOfficer,"perks.list.SailingProfessional");
        DeleteAttribute(refOfficer,"perks.list.IronWill");
        DeleteAttribute(refOfficer,"perks.list.SharedExperience");
        DeleteAttribute(refOfficer,"perks.list.Brander");
        DeleteAttribute(refOfficer,"perks.list.Troopers");
        DeleteAttribute(refOfficer,"perks.list.Trustworthy");
        DeleteAttribute(refOfficer,"perks.list.BasicCommerce");
        DeleteAttribute(refOfficer,"perks.list.AdvancedCommerce");
        DeleteAttribute(refOfficer,"perks.list.BasicLandOwner");
		DeleteAttribute(refOfficer,"perks.list.Toughness");
		DeleteAttribute(refOfficer,"perks.list.ImproveAiming");
		DeleteAttribute(refOfficer,"perks.list.ImproveSmuggling");
		DeleteAttribute(refOfficer,"perks.list.AdvanceSmuggling");
		DeleteAttribute(refOfficer,"perks.list.ImprovePotions");
		DeleteAttribute(refOfficer,"perks.list.DefendPoison");
		DeleteAttribute(refOfficer,"perks.list.Cooking");
		DeleteAttribute(refOfficer,"perks.list.HighStakes");
		DeleteAttribute(refOfficer,"perks.list.Disguiser");
		
        ResetHP(&refOfficer);
	
	
	
	
	// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------	
		
		intRank       = PChar.rank;
	    intLeaderShip = PChar.skill.Leadership;
        intFencing    = PChar.skill.Fencing;
        intSailing    = PChar.skill.Sailing;
        intAccuracy   = PChar.skill.Accuracy;
        intCannons    = PChar.skill.Cannons;
        intGrappling  = PChar.skill.Grappling;
        intRepair     = PChar.skill.Repair;
        intDefence    = PChar.skill.Defence;
        intCommerce   = PChar.skill.Commerce;
        intSneak      = PChar.skill.Sneak;
        intFreeSkill  = intRank*2;
        if (intFreeSkill < 0) 
        {
            intFreeSkill = 0;
        }
        PChar.skill.freeskill  = intFreeSkill;
        PChar.skill.Leadership = "1";
        PChar.skill.Fencing    = "1";
        PChar.skill.Sailing    = "1";
        PChar.skill.Accuracy   = "1";
        PChar.skill.Cannons    = "1";
        PChar.skill.Grappling  = "1";
        PChar.skill.Repair     = "1";
        PChar.skill.Defence    = "1";
        PChar.skill.Commerce   = "1";
        PChar.skill.Sneak      = "1";
        intFreePerks           = intRank;
        if (intFreePerks < 0) 
        {
            intFreePerks = 0;
        }
        PChar.perks.freepoints = intFreePerks;
        
        DeleteAttribute(PChar,"perks.list.BasicDefence");
        DeleteAttribute(PChar,"perks.list.AdvancedDefence");
        DeleteAttribute(PChar,"perks.list.SwordplayProfessional");
        DeleteAttribute(PChar,"perks.list.Rush");
        DeleteAttribute(PChar,"perks.list.CriticalHit");
        DeleteAttribute(PChar,"perks.list.Gunman");
        DeleteAttribute(PChar,"perks.list.GunProfessional");
        DeleteAttribute(PChar,"perks.list.FastReload");
        DeleteAttribute(PChar,"perks.list.ImmediateReload");
        DeleteAttribute(PChar,"perks.list.HullDamageUp");
        DeleteAttribute(PChar,"perks.list.SailsDamageUp");
        DeleteAttribute(PChar,"perks.list.CrewDamageUp");
        DeleteAttribute(PChar,"perks.list.CriticalShoot");
        DeleteAttribute(PChar,"perks.list.LongRangeShoot");
        DeleteAttribute(PChar,"perks.list.CannonProfessional");
        DeleteAttribute(PChar,"perks.list.LongRangeGrappling");
        DeleteAttribute(PChar,"perks.list.MusketsShoot");
        DeleteAttribute(PChar,"perks.list.GrapplingProfessional");
        DeleteAttribute(PChar,"perks.list.InstantBoarding");
        DeleteAttribute(PChar,"perks.list.BasicDamageControl");
        DeleteAttribute(PChar,"perks.list.AdvancedDamageControl");
        DeleteAttribute(PChar,"perks.list.ProfessionalDamageControl");
        DeleteAttribute(PChar,"perks.list.BasicFirstAid");
        DeleteAttribute(PChar,"perks.list.AdvancedFirstAid");
        DeleteAttribute(PChar,"perks.list.Rigging");
        DeleteAttribute(PChar,"perks.list.RiggingAdvance");
        DeleteAttribute(PChar,"perks.list.LightRepair");
        DeleteAttribute(PChar,"perks.list.InstantRepair");
        DeleteAttribute(PChar,"perks.list.ShipSpeedUp");
        DeleteAttribute(PChar,"perks.list.ShipTurnRateUp");
        DeleteAttribute(PChar,"perks.list.StormProfessional");
        DeleteAttribute(PChar,"perks.list.Turn180");
        DeleteAttribute(PChar,"perks.list.SandbankManeuver");
        DeleteAttribute(PChar,"perks.list.SailingProfessional");
        DeleteAttribute(PChar,"perks.list.IronWill");
        DeleteAttribute(PChar,"perks.list.SharedExperience");
        DeleteAttribute(PChar,"perks.list.Brander");
        DeleteAttribute(PChar,"perks.list.Troopers");
        DeleteAttribute(PChar,"perks.list.Trustworthy");
        DeleteAttribute(PChar,"perks.list.BasicCommerce");
        DeleteAttribute(PChar,"perks.list.AdvancedCommerce");
        DeleteAttribute(PChar,"perks.list.BasicLandOwner");
 		DeleteAttribute(PChar,"perks.list.Toughness");
		DeleteAttribute(PChar,"perks.list.ImproveAiming");
        DeleteAttribute(PChar,"perks.list.ImproveSmuggling");
        DeleteAttribute(PChar,"perks.list.AdvanceSmuggling");
        DeleteAttribute(PChar,"perks.list.ImprovePotions");
        DeleteAttribute(PChar,"perks.list.DefendPoison");
        DeleteAttribute(PChar,"perks.list.Cooking");
        DeleteAttribute(PChar,"perks.list.HighStakes");
 		DeleteAttribute(PChar,"perks.list.Disguiser");
		
        ResetHP(&PChar);
		
        DialogExit();			
		PlayStereoSound("INTERFACE\ITTB.wav");	
		LaunchCharacter(PChar);
	
	break;
	
	
	case "Reset_The_Main_Character":
	
		// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------	
		
		intRank       = PChar.rank;
	    intLeaderShip = PChar.skill.Leadership;
        intFencing    = PChar.skill.Fencing;
        intSailing    = PChar.skill.Sailing;
        intAccuracy   = PChar.skill.Accuracy;
        intCannons    = PChar.skill.Cannons;
        intGrappling  = PChar.skill.Grappling;
        intRepair     = PChar.skill.Repair;
        intDefence    = PChar.skill.Defence;
        intCommerce   = PChar.skill.Commerce;
        intSneak      = PChar.skill.Sneak;
        intFreeSkill  = intRank*2;
        if (intFreeSkill < 0) 
        {
            intFreeSkill = 0;
        }
        PChar.skill.freeskill  = intFreeSkill;
        PChar.skill.Leadership = "1";
        PChar.skill.Fencing    = "1";
        PChar.skill.Sailing    = "1";
        PChar.skill.Accuracy   = "1";
        PChar.skill.Cannons    = "1";
        PChar.skill.Grappling  = "1";
        PChar.skill.Repair     = "1";
        PChar.skill.Defence    = "1";
        PChar.skill.Commerce   = "1";
        PChar.skill.Sneak      = "1";
        intFreePerks           = intRank;
        if (intFreePerks < 0) 
        {
            intFreePerks = 0;
        }
        PChar.perks.freepoints = intFreePerks;
        
        DeleteAttribute(PChar,"perks.list.BasicDefence");
        DeleteAttribute(PChar,"perks.list.AdvancedDefence");
        DeleteAttribute(PChar,"perks.list.SwordplayProfessional");
        DeleteAttribute(PChar,"perks.list.Rush");
        DeleteAttribute(PChar,"perks.list.CriticalHit");
        DeleteAttribute(PChar,"perks.list.Gunman");
        DeleteAttribute(PChar,"perks.list.GunProfessional");
        DeleteAttribute(PChar,"perks.list.FastReload");
        DeleteAttribute(PChar,"perks.list.ImmediateReload");
        DeleteAttribute(PChar,"perks.list.HullDamageUp");
        DeleteAttribute(PChar,"perks.list.SailsDamageUp");
        DeleteAttribute(PChar,"perks.list.CrewDamageUp");
        DeleteAttribute(PChar,"perks.list.CriticalShoot");
        DeleteAttribute(PChar,"perks.list.LongRangeShoot");
        DeleteAttribute(PChar,"perks.list.CannonProfessional");
        DeleteAttribute(PChar,"perks.list.LongRangeGrappling");
        DeleteAttribute(PChar,"perks.list.MusketsShoot");
        DeleteAttribute(PChar,"perks.list.GrapplingProfessional");
        DeleteAttribute(PChar,"perks.list.InstantBoarding");
        DeleteAttribute(PChar,"perks.list.BasicDamageControl");
        DeleteAttribute(PChar,"perks.list.AdvancedDamageControl");
        DeleteAttribute(PChar,"perks.list.ProfessionalDamageControl");
        DeleteAttribute(PChar,"perks.list.BasicFirstAid");
        DeleteAttribute(PChar,"perks.list.AdvancedFirstAid");
        DeleteAttribute(PChar,"perks.list.Rigging");
        DeleteAttribute(PChar,"perks.list.RiggingAdvance");
        DeleteAttribute(PChar,"perks.list.LightRepair");
        DeleteAttribute(PChar,"perks.list.InstantRepair");
        DeleteAttribute(PChar,"perks.list.ShipSpeedUp");
        DeleteAttribute(PChar,"perks.list.ShipTurnRateUp");
        DeleteAttribute(PChar,"perks.list.StormProfessional");
        DeleteAttribute(PChar,"perks.list.Turn180");
        DeleteAttribute(PChar,"perks.list.SandbankManeuver");
        DeleteAttribute(PChar,"perks.list.SailingProfessional");
        DeleteAttribute(PChar,"perks.list.IronWill");
        DeleteAttribute(PChar,"perks.list.SharedExperience");
        DeleteAttribute(PChar,"perks.list.Brander");
        DeleteAttribute(PChar,"perks.list.Troopers");
        DeleteAttribute(PChar,"perks.list.Trustworthy");
        DeleteAttribute(PChar,"perks.list.BasicCommerce");
        DeleteAttribute(PChar,"perks.list.AdvancedCommerce");
        DeleteAttribute(PChar,"perks.list.BasicLandOwner");
 		DeleteAttribute(PChar,"perks.list.Toughness");
		DeleteAttribute(PChar,"perks.list.ImproveAiming");
        DeleteAttribute(PChar,"perks.list.ImproveSmuggling");
        DeleteAttribute(PChar,"perks.list.AdvanceSmuggling");
        DeleteAttribute(PChar,"perks.list.ImprovePotions");
        DeleteAttribute(PChar,"perks.list.DefendPoison");
        DeleteAttribute(PChar,"perks.list.Cooking");
        DeleteAttribute(PChar,"perks.list.HighStakes");
 		DeleteAttribute(PChar,"perks.list.Disguiser");
		
        ResetHP(&PChar);
		
        DialogExit();		
		PlayStereoSound("INTERFACE\ITTB.wav");		
		LaunchCharacter(PChar);
		
	
	break;
	
// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------

// El Rapido END
		
	case "El_Rapido_Clothes":			// El Rapido START
		Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
		d.Text = DLG_TEXT[61];
		Link.l1 = DLG_TEXT[62];
		Link.l1.go = "exit";
		GiveModel2Player("33_Ronald",false);
		GiveModel2Player("47_JRMMCpt",false);
		GiveModel2Player("47_JRMMCmd",false);
		GiveModel2Player("47_JRMMLcm",false);
		GiveModel2Player("47_JRMMLt1",false);
		GiveModel2Player("47_JRMMLt2",false);
		GiveModel2Player("47_Norrington_Pirate",false);
		GiveModel2Player("50_Becka",false);
		GiveModel2Player("50_India",false);
		GiveModel2Player("50LCroft",false);
		GiveModel2Player("9JdEng",false);
		GiveModel2Player("9Tb",false);
		GiveModel2Player("9Td_0",false);
		GiveModel2Player("9Td",false);
		GiveModel2Player("Aubrey",false);
		GiveModel2Player("Barbossa",false);
		GiveModel2Player("BeatriceA",false);
		GiveModel2Player("Blackbeard",false);
		GiveModel2Player("blackman",false);
		GiveModel2Player("bocman4",false);
		GiveModel2Player("bocman5",false);
		GiveModel2Player("capitan",false);
		GiveModel2Player("CapJRMM",false);
		GiveModel2Player("capstan",false);
		GiveModel2Player("CaptainTeague",false);
		GiveModel2Player("cnorrington",false);
		GiveModel2Player("Conorrington",false);
		GiveModel2Player("Corsair1",false);
		GiveModel2Player("Corsair1_1",false);
		GiveModel2Player("Corsair1_2",false);
		GiveModel2Player("Corsair1_3",false);
		GiveModel2Player("Corsair2",false);
		GiveModel2Player("Corsair3",false);
		GiveModel2Player("Corsair4",false);
		GiveModel2Player("Corsair1_J",false);
		GiveModel2Player("Corsair2_J",false);
		GiveModel2Player("Corsair3_J",false);
		GiveModel2Player("Corsair4_J",false);
		GiveModel2Player("Cpnorrington",false);
		GiveModel2Player("Danielle",false);
		GiveModel2Player("depp",false);
		GiveModel2Player("Eugene_Martin",false);
		GiveModel2Player("Fanielle",false);
		GiveModel2Player("Gherarde_De_Jongh",false);
		GiveModel2Player("Jack",false);
		GiveModel2Player("LaCroix",false);
		GiveModel2Player("Johan_Elting",false);
		GiveModel2Player("ladyinred",false);
		GiveModel2Player("Ltnorrington",false);
		GiveModel2Player("Mansveldt",false);
		GiveModel2Player("Mdnorrington",false);
		GiveModel2Player("Morgan",false);
		GiveModel2Player("MorrisWilliams",false);
		GiveModel2Player("Offic_per",false);
		GiveModel2Player("Pirat3",false);
		GiveModel2Player("Pirat8",false);
		GiveModel2Player("Pirat11",false);
		GiveModel2Player("Pirat15",false);
		GiveModel2Player("Rabel_Chardon",false);
		GiveModel2Player("sailor7",false);
		GiveModel2Player("Skull",false);
		GiveModel2Player("Soldier_Per4",false);
		GiveModel2Player("Spy2",false);
		GiveModel2Player("TiaDalma",false);
		GiveModel2Player("will",false);
		GiveModel2Player("will_2",false);
		GiveModel2Player("will_3",false);
		GiveModel2Player("armdelfra",false);
		GiveModel2Player("Cutler_Beckett",false);
		GiveModel2Player("Leonardo_Corrales",false);
		GiveModel2Player("Merciless_Mark",false);
		GiveModel2Player("Terror",false);
		GiveModel2Player("Emilio1",false);
		GiveModel2Player("ShkiperM_UH_a",false);
		GiveModel2Player("pir_cap4",false);
		GiveModel2Player("pir_cap5",false);
		GiveModel2Player("pir_cap6",false);
		GiveModel2Player("pir_cap8",false);
		GiveModel2Player("gm_crew1",false);
		GiveModel2Player("gm_crew4",false);
		GiveModel2Player("gm_crew5",false);
		GiveModel2Player("gm_crew3",false);
		GiveModel2Player("gm_crew22",false);
		GiveModel2Player("Napitan",false);
		GiveModel2Player("blaze",false);
		PlayStereoSound("INTERFACE\ITTB.wav");
		AddMoneyToCharacter(pchar, -10000);

		break;								// El Rapido END
	
		case "AppearanceMod_MainDialog":
			PChar.AppearanceMod.ClothierModel = NPChar.model;
			InitModelSlots(PChar,NPChar,strNow);
			d.Text = DLG_TEXT[38];
			Link.l1 = DLG_TEXT[39];
			Link.l1.go = "AppearanceMod_SetOfficer0"; // NK
			intOfficer = sti(GetOfficersIndex(PChar,1));
			if( intOfficer != -1)
			{
				 refOfficer = GetCharacter(intOfficer);
				 Link.l2 = DLG_TEXT[40] + refOfficer.name + " " +refOfficer.lastname + DLG_TEXT[59]; 
				 Link.l2.go = "AppearanceMod_SetOfficer1";
			}
			intOfficer = sti(GetOfficersIndex(PChar,2));
			if( intOfficer != -1)
			{
				 refOfficer = GetCharacter(intOfficer);
				 Link.l3 = DLG_TEXT[40] + refOfficer.name + " " +refOfficer.lastname + DLG_TEXT[59];
				 Link.l3.go = "AppearanceMod_SetOfficer2";
			}
			intOfficer = sti(GetOfficersIndex(PChar,3));
			if( intOfficer != -1)
			{
				 refOfficer = GetCharacter(intOfficer);
				 Link.l4 = DLG_TEXT[40] + refOfficer.name + " " +refOfficer.lastname + DLG_TEXT[59];
				 Link.l4.go = "AppearanceMod_SetOfficer3";
			}
		break;

		case "AppearanceMod_SetOfficer0":
			PChar.AppearanceMod.OfficerIndex = 0;
			PChar.AppearanceMod.OfficerPos	= 0;
			AppearanceMod_ModelLinks(PChar,d,Link);
		break;

		case "AppearanceMod_SetOfficer1":
			intOfficer = sti(GetOfficersIndex(PChar,1));
			PChar.AppearanceMod.OfficerIndex = intOfficer;
			PChar.AppearanceMod.OfficerPos	= 1;
			AppearanceMod_ModelLinks(PChar,d,Link);
		break;

		case "AppearanceMod_SetOfficer2":
			intOfficer = sti(GetOfficersIndex(PChar,2));
			PChar.AppearanceMod.OfficerIndex = intOfficer;
			PChar.AppearanceMod.OfficerPos	= 2;
			AppearanceMod_ModelLinks(PChar,d,Link);
		break;

		case "AppearanceMod_SetOfficer3":
			intOfficer = sti(GetOfficersIndex(PChar,3));
			PChar.AppearanceMod.OfficerIndex = intOfficer;
			PChar.AppearanceMod.OfficerPos	= 3;
			AppearanceMod_ModelLinks(PChar,d,Link);
		break;

		// NK add buy choice -->
		case "AppearanceMod_Buy_choice":
			int price = sti(Models[GetModelIndex(NPChar.model)].price);
			d.text = DLG_TEXT[41] + price + DLG_TEXT[42];
			if(GetCharacterMoney(PChar) >= price)
			{
				Link.l1 = DLG_TEXT[43];
				Link.l1.go = "AppearanceMod_Buy_now";
				Link.l2 = DLG_TEXT[44];
				Link.l2.go = "AppearanceMod_Buy";
			}
			Link.l3 = DLG_TEXT[45];
			Link.l3.go = "AppearanceMod_Exit";
		break;

		case "AppearanceMod_Buy": //NK: no model change, just buy
			// NK to buy the clothing -->
			tempstr = NPChar.model;
			PChar.clothes.(tempstr) = true;
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -sti(Models[GetModelIndex(tempstr)].price));
			// NK <--
			SetModel(NPChar, PChar.AppearanceMod.ClothierModel, "man", "man", 1.8, false);
			DeleteAttribute(PChar,"AppearanceMod");
			DialogExit();
		break;

		case "AppearanceMod_Buy_now": //NK: buy _and_ change clothes
			// NK to buy the clothing, _and_ set current clothing bought -->
			tempstr = PChar.model;
			PChar.clothes.(tempstr) = true;
			tempstr = NPChar.model;
			PChar.clothes.(tempstr) = true;
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -sti(Models[GetModelIndex(tempstr)].price));
			// NK <--
			intOfficer = sti(PChar.AppearanceMod.OfficerIndex);
			refOfficer = GetCharacter(intOfficer);
			SetModel(refOfficer, NPChar.model, NPChar.model.animation, NPChar.sex, stf(NPChar.model.height), true);
			SetModel(NPChar, PChar.AppearanceMod.ClothierModel, "man", "man", 1.8, false);
			DeleteAttribute(PChar,"AppearanceMod");
			DialogExit();
		break;

		case "AppearanceMod_Exit":
			SetModel(NPChar, PChar.AppearanceMod.ClothierModel, "man", "man", 1.8, false);
			DeleteAttribute(PChar,"AppearanceMod");
			DialogExit();
		break;

		case "AppearanceMod_Select_1":
			SetModelfromArray(NPChar, sti(ModelSlots[0].index));
			AppearanceMod_AnswerLinks(PChar,d,Link,ModelSlots[0].price));
		break;
		case "AppearanceMod_Select_2":
			SetModelfromArray(NPChar, sti(ModelSlots[1].index));
			AppearanceMod_AnswerLinks(PChar,d,Link,ModelSlots[1].price));
		break;
		case "AppearanceMod_Select_3":
			SetModelfromArray(NPChar, sti(ModelSlots[2].index));
			AppearanceMod_AnswerLinks(PChar,d,Link,ModelSlots[2].price));
		break;
		case "AppearanceMod_Select_4":
			SetModelfromArray(NPChar, sti(ModelSlots[3].index));
			AppearanceMod_AnswerLinks(PChar,d,Link,ModelSlots[3].price));
		break;
		case "AppearanceMod_Select_5":
			SetModelfromArray(NPChar, sti(ModelSlots[4].index));
			AppearanceMod_AnswerLinks(PChar,d,Link,ModelSlots[4].price));
		break;

		case "AppearanceMod_CircleThroughAllModels":
			if(!CheckAttribute(NPChar, "CircleThroughAllModels"))
			{
			  NPChar.CircleThroughAllModels.ModelIndex = 0;
			  NPChar.CircleThroughAllModels.Direction  = 1;
			}
			i = sti(NPChar.CircleThroughAllModels.ModelIndex);
			j = sti(NPChar.CircleThroughAllModels.Direction);
			if(j == 1)
			{
				NPChar.CircleThroughAllModels.ModelIndex = i + 1;
			}
			else
			{
				if (i > 0)
				{
					NPChar.CircleThroughAllModels.ModelIndex = i -1;
				}
			}
			if (Models[i].assigned == true)
			{
				SetModelfromArray(NPChar, i));
				int tmpDescFileID = LanguageOpenFile("models_description.txt");
				d.text = models[i].index  + ": " + models[i].model  + " : " + models[i].price + "/" + GetModelPrice(PChar, NPChar, Models[i].price)  + " : " +  LanguageConvertString(tmpDescFileID,models[i].description);
				LanguageCloseFile(tmpDescFileID);

				if(j == 1)
				{
					Link.l1 = DLG_TEXT[46];
					Link.l1.go = "AppearanceMod_CircleThroughAllModels";
				}
				else
				{
					Link.l1 = DLG_TEXT[47];
					Link.l1.go = "AppearanceMod_CircleThroughAllModels";
				}
				Link.l2 = DLG_TEXT[48];
				Link.l2.go = "AppearanceMod_CircleDirection";
				Link.l3 = DLG_TEXT[49];
				Link.l3.go = "AppearanceMod_CircleBuy_now";
				Link.l4 = DLG_TEXT[50];
				Link.l4.go = "AppearanceMod_Exit";
			}
			else
			{
				DeleteAttribute(NPChar,"CircleThroughAllModels");
				d.text = DLG_TEXT[51] + i  + DLG_TEXT[52];
				Link.l2 = DLG_TEXT[53];
				Link.l2.go = "AppearanceMod_CircleThroughAllModels";
				Link.l3 = DLG_TEXT[50];
				Link.l3.go = "AppearanceMod_Exit";
			}
		break;

		case "AppearanceMod_CircleDirection":
			if(NPChar.CircleThroughAllModels.Direction == 1)
			{
				NPChar.CircleThroughAllModels.Direction  = -1;
				NPChar.CircleThroughAllModels.ModelIndex = sti(NPChar.CircleThroughAllModels.ModelIndex) - 2;
			}
			else
			{
				NPChar.CircleThroughAllModels.Direction = 1;
				NPChar.CircleThroughAllModels.ModelIndex = sti(NPChar.CircleThroughAllModels.ModelIndex) + 2;
			}
			d.text	 = DLG_TEXT[54];
			Link.l1	= DLG_TEXT[55];
			Link.l1.go = "AppearanceMod_CircleThroughAllModels";
			Link.l2	= DLG_TEXT[50];
			Link.l2.go = "AppearanceMod_Exit";

		break;

		case "AppearanceMod_CircleBuy_now":
			tempstr = PChar.model;
			PChar.clothes.(tempstr) = true;
			tempstr = NPChar.model;
			PChar.clothes.(tempstr) = true;
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -sti(Models[GetModelIndex(tempstr)].price));
			SetModel(PChar, NPChar.model, NPChar.model.animation, NPChar.sex, stf(NPChar.model.height), true);
			SetModel(NPChar, PChar.AppearanceMod.ClothierModel, "man", "man", 1.8, false);
			d.text	 = DLG_TEXT[56];
			Link.l1	= DLG_TEXT[57];
			Link.l1.go = "AppearanceMod_CircleThroughAllModels";
			Link.l2	= DLG_TEXT[58];
			Link.l2.go = "AppearanceMod_Exit";
		break;

		// Kapitein of Kralendijk side quest -->
		case "kapitein_ask_papers":
			dialog.text = DLG_TEXT[91] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[92];
			if(CheckQuestAttribute("kapitein", "got_papers"))
			{
				link.l1 = DLG_TEXT[96];
				link.l1.go = "kapitein_papers_valid";
			}
			else
			{
				link.l1 = DLG_TEXT[93];
				link.l1.go = "kapitein_why_papers";
			}
		break;

		case "kapitein_why_papers":
			dialog.text = DLG_TEXT[94];
			link.l1 = DLG_TEXT[95];
			AddDialogExitQuest("Kapitein_need_papers");
			link.l1.go = "exit";
		break;

		case "kapitein_papers_valid":
			dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			AddDialogExitQuest("Kapitein_wait_for_tailor");
			link.l1.go = "exit";
		break;

		case "kapitein_uniform_ready":
			dialog.text = DLG_TEXT[100];
			if (sti(PChar.money) >= 4000)
			{
				link.l1 = DLG_TEXT[101];
				link.l1.go = "kapitein_buy_uniform";
			}
			else
			{
				link.l1 = DLG_TEXT[102];
				link.l1.go = "exit";
			}
		break;

		case "kapitein_buy_uniform":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -4000);
			AddDialogExitQuest("kapitein_buy_uniform");
			if (PChar.sex == "woman")
			{
				dialog.text = DLG_TEXT[103] + DLG_TEXT[105] + DLG_TEXT[106];
				link.l1 = DLG_TEXT[107] + DLG_TEXT[109] + DLG_TEXT[110];
			}
			else
			{
				dialog.text = DLG_TEXT[103] + DLG_TEXT[104] + DLG_TEXT[106];
				link.l1 = DLG_TEXT[107] + DLG_TEXT[108] + DLG_TEXT[110];
			}
			link.l1.go = "exit";
		break;

		case "kaptein_change_first":
			dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[112];
			link.l1.go = "exit";
		break;
		// <-- Kapitein of Kralendijk side quest
	}
}

