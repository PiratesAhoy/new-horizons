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
	
	string iDay, iMonth, cargoid, questbookname;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;
	ref ctown = GetCurrentTown();
	int chancecaught = 0;
	
	// DeathDaisy: Persuasion tags for the skill checks, if enabled
	string PersuasionSuccess = "";
	string PersuasionFailure = "";
	if(PERSUASION_TAGS){ 
		PersuasionSuccess = XI_ConvertString("Persuasion_Success") + " ";
		PersuasionFailure = XI_ConvertString("Persuasion_Failure") + " ";
	}
	
	Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			if(CheckAttribute(pchar,"quest.mysterious_plants.declined"))
			{
				Link.l0 = DLG_TEXT[28];
				Link.l0.go = "agree_donate";
			}
			else
			{
				if (sti(GetAttribute(PChar,"quest.mysterious_plants.donate")) < 1000 )
				{
					if(CheckAttribute(PChar,"quest.mysterious_plants.donate"))
					{
						Link.l0 = DLG_TEXT[94];
						Link.l0.go = "decline_donate_later";
					
					}
				}
				else
				{
					if(!CheckAttribute(PChar,"quest.mysterious_plants.heard_job"))
					{
						Link.l0 = DLG_TEXT[29];
						Link.l0.go = "Talk Business";
					}
				}
			}
			if(CheckAttribute(PChar,"quest.mysterious_plants.met_smuggler") && GetAttribute(PChar,"quest.mysterious_plants.heard_job") == "explain")
			{
				Link.l0 = DLG_TEXT[55];
				Link.l0.go = "Meet In Tavern";
			}

			if(CheckAttribute(PChar,"quest.mysterious_plants.crewmember.attacked_tell_steven"))
			{
				Link.l0 = DLG_TEXT[172];
				Link.l0.go = "Shock attack";
			}
			if (CheckAttribute(PChar, "quest.mysterious_plants.setwarehouse"))//PW 
			{
				Link.l0 = DLG_TEXT[167];
				Link.l0.go = "Tell Steven about warehouse";
			}
			if (CheckAttribute(PChar,"quest.mysterious_plants.No_Follow"))//PW 
			{
				Link.l0 = DLG_TEXT[175];
				Link.l0.go = "No Follow";
			}
			if (CheckAttribute(PChar,"quest.mysterious_plants.Lost_Indian"))//PW 
			{
				Link.l0 = DLG_TEXT[165];
				Link.l0.go = "Lost Indian";
			}
			if (CheckAttribute(pchar,"quest.mysterious_plants.spy.killed"))
			{
				Link.l0 = DLG_TEXT[177];
				Link.l0.go = "Killed Spy";
			}
			if (GetAttribute(PChar,"quest.mysterious_plants.give_up") == "true")//PW 
			{
				Link.l0 = DLG_TEXT[99];
				Link.l0.go = "Give Up 1";
			}
			if(CheckAttribute(PChar,"quest.found_vegetal"))
			{
				Link.l0 = DLG_TEXT[64];
				Link.l0.go = "Explain Vegetal";
			}
			if(GetAttribute(pchar,"quest.mysterious_plants.heard_job") == "Returned")
			{
		//		if(CheckCharacterItem(Pchar,"package_steven"))
				if(CheckCharacterItem(Pchar,"ayahuasca"))
				{
					//Success
					//JRH
					Link.l0 = DLG_TEXT[162];
					Link.l0.go = "Success Plants";
				}
				else
				{
					pchar.quest.mysterious_plants.heard_job = "Returned given up";
					Link.l0 = DLG_TEXT[160];
					Link.l0.go = "Give Up 1";
					
				}
			}
			if((pchar.location == "Cartagena Hotel") && CheckAttribute(pchar,"quest.mysterious_plants.give_up.amount"))
			{
				Link.l10 = DLG_TEXT[169];
				Link.l10.go = "Bring Opium";
			}
			if(!CheckAttribute(PChar,"quest.plants"))
			{			
			Link.l10 = DLG_TEXT[0];
			Link.l10.go = "Trust Check";
			}

		break;
		
		case "Explain Vegetal":
			AddDialogExitQuest("Finish Indian Treasure Quest");
			d.Text = DLG_TEXT[65];
			Link.l1 = DLG_TEXT[66];
			Link.l1.go = "exit";
		break;
		
		// ====================== PART 1
		
		case "Trust Check":
			if(GetCharacterShipLocation(Pchar) == "Greenford_port")
			{
			d.Text = DLG_TEXT[1];
			Link.l1 = DLG_TEXT[2];
			Link.l1.go = "Convince"; 
			}
			else
			{
			d.Text = DLG_TEXT[170];
			Link.l1 = DLG_TEXT[171];
			Link.l1.go = "exit"; 
			}
		
			
		break;
		
		case "Convince":
			pchar.quest.plants = "start"
			if(!CheckAttribute(PChar,"quest.mysterious_plants"))
			{
				SetQuestHeader("plants");
				AddQuestRecord("plants", 1);
			}
			AddQuestRecord("plants", 2);
			AddDialogExitQuest ("Learned About Apothecary");
			d.Text = DLG_TEXT[3];
			Link.l1 = DLG_TEXT[4];
			Link.l1.go = "agree_donate";
			Link.l2 = DLG_TEXT[5];
			Link.l2.go = "decline_donate"; 			
		break;
		
		case "agree_donate":
			d.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "exit";
			DeleteAttribute(&PChar,"quest.mysterious_plants.declined");
			AddDialogExitQuest("Accept Donate Apothecary");			
		break;
		
		case "decline_donate":
			d.Text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "exit";
			AddDialogExitQuest("Decline Donate Apothecary"); 			
		break;
		
		case "decline_donate_later":
			d.Text = DLG_TEXT[95];
			Link.l1 = DLG_TEXT[96];
			Link.l1.go = "exit";
			AddDialogExitQuest("Decline Donate Apothecary");
		break;

		case "Killed Mob":
			d.Text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[23];
			Link.l1.go = "Killed Mob 2";
		break;
		
		case "Killed Mob 2":
			d.Text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "Killed Mob 3";
		break;
		
		case "Killed Mob 3":
			AddDialogExitQuest("Officiant helps steven"); 
			d.Text = DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "exit";
		break;
		

		

		//===================== PART 2
		case "Talk Business":
			AddDialogExitQuest("Apothecary Talk Business");
			d.Text = DLG_TEXT[30];
			Link.l1 = DLG_TEXT[31];
			Link.l1.go = "Talk Business 2";
		break;
		
		case "Talk Business 2":
			d.Text = DLG_TEXT[32];
			Link.l1 = DLG_TEXT[33];
			Link.l1.go = "Talk Business 3";
		break;
		
		case "Talk Business 3":
			d.Text = DLG_TEXT[34];
			Link.l1 = DLG_TEXT[35];
			Link.l1.go = "Talk Business 4";
		break;
		
		case "Talk Business 4":
			d.Text = DLG_TEXT[36];
			Link.l1 = DLG_TEXT[37];
			Link.l1.go = "Talk Business Accept";
			Link.l2 = DLG_TEXT[38];
			Link.l2.go = "Talk Business Decline";
		break;
		
		case "Talk Business Decline":
			d.Text = DLG_TEXT[39];
			Link.l1 = DLG_TEXT[40];
			Link.l1.go = "exit decline business";
			Link.l2 = DLG_TEXT[41];
			Link.l2.go = "Talk Business Reconsider";
		break;
		
		case "Talk Business Reconsider":
			d.Text = DLG_TEXT[42];
			Link.l1 = DLG_TEXT[37];
			Link.l1.go = "Talk Business Accept";
			Link.l2 = DLG_TEXT[38];
			Link.l2.go = "exit decline business";
		break;
		
		case "exit decline business":
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Apothecary Decline Business");
			DialogExit();
		break;
		
		case "Talk Business Accept":
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Talk Business Accept");
			DialogExit();
		break;
		
		case "Discuss Guarded":
			d.Text = DLG_TEXT[45];
			Link.l1 = DLG_TEXT[46];
			Link.l1.go = "Discuss Guarded 2";
		break;
		
		case "Discuss Guarded 2":
			AddDialogExitQuest("Prepare Apothecary Voyage");
			d.Text = DLG_TEXT[47];
			Link.l1 = DLG_TEXT[48];
			Link.l1.go = "exit";
		break;
		
		

		case "Meet In Tavern":
			AddDialogExitQuest("Apothecary Meet In Tavern");
			d.Text = DLG_TEXT[56];
			Link.l1 = DLG_TEXT[57];
			Link.l1.go = "exit";
		break;
		
		//===================== Give up Quest
		
		case "Give Up 1":
			AddDialogExitQuest("At Steven while Giving Up 1");
			d.Text = DLG_TEXT[100];
			Link.l1 = DLG_TEXT[101];
			Link.l1.go = "exit2";
		break;
		
		case "Give Up 2":
			AddDialogExitQuest("At Steven while Giving Up 2");
			d.Text = DLG_TEXT[102];
			Link.l1 = DLG_TEXT[103];
			Link.l1.go = "exit2";
		break;
		
		case "Give Up 3":
			AddDialogExitQuest("At Steven while Giving Up 3");
			if(GetAttribute(pchar,"quest.mysterious_plants.heard_job") == "Returned given up")
			{
				d.Text = DLG_TEXT[161];
			}
			else
			{
				d.Text = DLG_TEXT[104];
			}
			Link.l1 = DLG_TEXT[105];
			Link.l1.go = "exit2";
		break;
		
		case "Give Up 4":
			bool reported = false;
			if(CheckAttribute(PChar,"quest.mysterious_plants.reported_crime.withoutproof") || CheckAttribute(PChar,"quest.mysterious_plants.reported_crime.withproof")) reported = true;
			if(sti(GetAttribute(pchar,"quest.mysterious_plants.indians.killed")) > 1 || reported)
			{
				if(reported)
				{
					d.Text = DLG_TEXT[106]+DLG_TEXT[108]+DLG_TEXT[109];
					Link.l1 = DLG_TEXT[110];
					Link.l1.go = "Give Up 5";
				}
				else
				{
					d.Text = DLG_TEXT[106]+DLG_TEXT[107]+DLG_TEXT[109];
					Link.l1 = DLG_TEXT[110];
					Link.l1.go = "Give Up 5";
				}
			}
			else
			{
				AddDialogExitQuest("Given Up End at Steven");
				d.Text = DLG_TEXT[106]+DLG_TEXT[107];
				Link.l1 = DLG_TEXT[59];
				Link.l1.go = "exit2";
			}
		break;
		
		case "Give Up 5":
			PChar.quest.mysterious_plants.give_up.amount = sti(GetAttribute(pchar,"quest.mysterious_plants.indians.killed")) * 4;
			if (sti(GetAttribute(PChar,"quest.mysterious_plants.give_up.amount")) <= 0 )PChar.quest.mysterious_plants.give_up.amount = 2;//PW got a "give us 0 plants" response during testing
			if(GetDifficulty() >= DIFFICULTY_SEADOG)
			{
				d.Text = DLG_TEXT[111]+PChar.quest.mysterious_plants.give_up.amount+DLG_TEXT[112];
			}
			else
			{
				d.Text = DLG_TEXT[111]+PChar.quest.mysterious_plants.give_up.amount+DLG_TEXT[112]+DLG_TEXT[113];
			}
			Link.l1 = DLG_TEXT[114];
			Link.l1.go = "Give Up 6";
		break;
		
		case "Give Up 6":
			PChar.quest.mysterious_plants.give_up.time = 6 - GetDifficulty();
			d.Text = DLG_TEXT[115]+PChar.quest.mysterious_plants.give_up.time+DLG_TEXT[116];
			Link.l1 = DLG_TEXT[117];
			Link.l1.go = "exit2";
			AddDialogExitQuest("Payback Indians after give up at Steven");
		break;
		
		case "Bring Opium":
			d.Text = DLG_TEXT[121];
			if(sti(PChar.items.opium) >= sti(GetAttribute(PChar,"quest.mysterious_plants.give_up.amount")))
			{

				Link.l1 = DLG_TEXT[122];
				Link.l1.go = "Give Up Complete";
			}
			else
			{

			Link.l1 = DLG_TEXT[123];
			Link.l1.go = "exit";
			Dialog.NextNode = "Bring Opium";
			}
		
		break;
		
		case "Give Up Complete":
			d.Text = DLG_TEXT[124];
			Link.l1 = DLG_TEXT[125];
			Link.l1.go = "exit2";
			AddDialogExitQuest("Give Up Completed in Cartagena");
		break;
		
		//===================== PART FROM MOB LEADER
		case "Mob Leader":
			d.Text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "Choose Mob";
		break;
		
		case "Choose Mob":
			d.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "Choose BOOM";
			//if(sti(PChar.money)>=1000)//PW this removed pay option if you didn't have 1000. This effectively closes the apothecary with no player option otherwise from this point.
			// PW If you were trying the quest because you didn't have much money you could think you HAD to refuse to donate and end up here. 
			//{
				Link.l2 = DLG_TEXT[14];
				Link.l2.go = "Choose Money";
			//}
			Link.l3 = DLG_TEXT[15];
			Link.l3.go = "Choose Fight";
		break;
		
		case "Choose BOOM":
			d.Text = DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17];
			Link.l1.go = "exit2";
			AddDialogExitQuest("Apothecary BOOM"); 
		break;
		
		case "Choose Money":
			//AddMoneyToCharacter(pchar, -1000);//PW so was working to make indirect donaion but not raising donated sum for continuing quest
			d.Text = DLG_TEXT[18];
			Link.l1 = DLG_TEXT[19];
			Link.l1.go = "exit2";
			AddDialogExitQuest("Apothecary Pay"); 
		break;
		
		case "Choose Fight":
			//AddMoneyToCharacter(pchar, -1000);// PW ?? no money involved if you fight
			d.Text = DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "exit2";
			AddDialogExitQuest("Apothecary Fight Mob"); 
		break;
		
		case "exit2":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
		//=================== Crew Member Part
		case "Crew Spotted Natives":
			d.Text = DLG_TEXT[43];
			Link.l1 = DLG_TEXT[44];
			Link.l1.go = "exit guarded";
		break;
		
		case "exit guarded":
			AddDialogExitQuest("Apothecary Discuss Guards"); 
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
		case "Saved from Natives":
			AddDialogExitQuest("Apothecary Crewmember goes to ship");
			d.Text = DLG_TEXT[53];
			Link.l1 = DLG_TEXT[54];
			Link.l1.go = "exit2";
		break;
		
		case "Shock attack"://PW new optional dialog available with steven after your crewmember attacked
			DeleteAttribute(&PChar,"quest.mysterious_plants.crewmember.attacked_tell_steven");
			d.Text = DLG_TEXT[173];
			if (CheckAttribute(&Pchar,"quest.mysterious_plants.reported_crime"))
			{
			Link.l1 = DLG_TEXT[176];
			Link.l1.go = "exit";
			}
			else
			{
			if (FindCurrentStoryline() == FindStoryline("jack_sparrow"))
				{
    				Link.l1 = DLG_TEXT[180];
				Link.l1.go = "exit"; 
				}
				else
				{
   				Link.l1 = DLG_TEXT[174];
				Link.l1.go = "exit"; 
				}
			}
			
		break;



		case "Help During Ambush":
			AddDialogExitQuest("Continue Apothecary Ambush");
			d.Text = DLG_TEXT[67];
			Link.l1 = DLG_TEXT[68];
			Link.l1.go = "exit2";
		break;
		
		case "Won Ambush":
			AddDialogExitQuest("Apothecary Exit Warehouse");
			d.Text = DLG_TEXT[69];
			Link.l1 = DLG_TEXT[70];
			Link.l1.go = "exit2";
		break;
		
		//=================== Officiant Part
		case "Hit by Blast":
			d.Text = DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "Hit by Blast 2";
		break;
		
		case "Hit by Blast 2":
			AddDialogExitQuest("ResurrectionEvent_OfficiantLeaves");
			d.Text = DLG_TEXT[51];
			Link.l1 = DLG_TEXT[52];
			Link.l1.go = "exit2";
		break;
		
		case "Help Steven Leave":
			d.Text = DLG_TEXT[60];
			Link.l1 = DLG_TEXT[61];
			Link.l1.go = "Help Steven Leave 2";
		break;
		
		case "Help Steven Leave 2":
			AddDialogExitQuest("Steven Leaves");
			d.Text = DLG_TEXT[62];
			Link.l1 = DLG_TEXT[63];
			Link.l1.go = "exit2";
		break;
		



		case "officiant Leave":
			d.Text = DLG_TEXT[60];
			Link.l1 = DLG_TEXT[61];
			Link.l1.go = "officiant Leave 2";
		break;
		
		case "officiant Leave 2":
			AddDialogExitQuest("officiant Leaves");
			d.Text = DLG_TEXT[62];
			Link.l1 = DLG_TEXT[63];
			Link.l1.go = "exit2";
		break;
		//================== Captain Part
		case "Talk about plan":
			AddDialogExitQuest("Apothecary Meet At Lighthouse");
			d.Text = DLG_TEXT[58];
			Link.l1 = DLG_TEXT[59];
			Link.l1.go = "exit2";
		break;
		
		case "Arrived at Lighthouse":
			AddDialogExitQuest("Apothecary Arrived at Lighthouse");
			d.Text = DLG_TEXT[88];
			Link.l1 = DLG_TEXT[89];
			Link.l1.go = "exit2";
		break;
		
		case "Arrived at Lighthouse during day":
			AddDialogExitQuest("Apothecary Arrived at Lighthouse");
			d.Text = DLG_TEXT[97];
			Link.l1 = DLG_TEXT[98];
			Link.l1.go = "exit2";
		break;
		
		case "Arrived at Lighthouse by sea":
			AddDialogExitQuest("Apothecary Arrived at Lighthouse");
			d.Text = DLG_TEXT[120];
			Link.l1 = DLG_TEXT[98];
			Link.l1.go = "exit2";
		break;
		
		case "Ship Blow Up":
			AddDialogExitQuest("Apothecary Indians Attack at Lighthouse");
			d.Text = DLG_TEXT[90];
			Link.l1 = DLG_TEXT[91];
			Link.l1.go = "exit2";
		break;
		
		case "Depart To Columbia":
			AddDialogExitQuest("Depart To Columbia for Apothecary");
			d.Text = DLG_TEXT[92];
			Link.l1 = DLG_TEXT[93];
			Link.l1.go = "exit2";
		break;
		
		case "Arrived at Cartagena":
			AddDialogExitQuest("Start Cartagena Exploration for Apothecary");
			d.Text = DLG_TEXT[126];
			Link.l1 = DLG_TEXT[127];
			Link.l1.go = "exit2";
		break;
		
		case "Return To Greenford":
			d.Text = DLG_TEXT[128];
			Link.l1 = DLG_TEXT[129];
			Link.l1.go = "exit2";
			Link.l2 = DLG_TEXT[157];
			Link.l2.go = "Go Back To Greenford";
			Diag.TempNode = "Return To Greenford";
		break;
		
		case "Go Back To Greenford":
			AddDialogExitQuest("Return to Greenford for Apothecary");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
		case "Arrived back in Greenford":
			d.Text = DLG_TEXT[158];
			Link.l1 = DLG_TEXT[159];
			Link.l1.go = "exit2";
			AddDialogExitQuest("Returned in Greenford for Apothecary");
		break;
		
		//================= Indians in warehouse part

		case "Tell Steven about warehouse"://PW optional new dialog if you know about warehouse 
			DeleteAttribute(PChar, "quest.mysterious_plants.setwarehouse");
			d.Text = DLG_TEXT[168];
			if (FindCurrentStoryline() == FindStoryline("jack_sparrow"))
				{
    				Link.l1 = DLG_TEXT[179];
				}
				else
				{
   				Link.l1 = DLG_TEXT[59];
				}
			
			Link.l1.go = "exit2";
		break;
		
		case "No Follow"://PW optional new dialog with steven to setup indians in warehouse if you din't follow from tavern
			//DeleteAttribute(PChar,"quest.mysterious_plants.No_Follow");
			d.Text = DLG_TEXT[166];
			Link.l1 = DLG_TEXT[171];
			Link.l1.go = "exit2";
			AddDialogExitQuest("Apothecary Build Obstacles"); 
		break;
		
		case "Lost Indian"://PW optional new dialog with steven to set indians in warehouse if you didn't follow into suburb
			//DeleteAttribute(PChar,"quest.mysterious_plants.Lost_Indian");
			d.Text = DLG_TEXT[166];
			Link.l1 = DLG_TEXT[59];
			Link.l1.go = "exit2";
			AddDialogExitQuest("Setup Warehouse"); 
		break;
		
		case "Killed Spy"://PW optional new dialog with steven to set indians in warehouse if you killed the indian "spy"
			DeleteAttribute(PChar,"quest.mysterious_plants.spy.killed");
			d.Text = DLG_TEXT[166];
			Link.l1 = DLG_TEXT[59];
			Link.l1.go = "exit2";
			AddDialogExitQuest("Setup Warehouse"); //PW no build obstacles (should be in place)
		break;

		case "Indians Talk 1":
			PChar.quest.mysterious_plants.node = "Indians Talk 2";
			d.Text = DLG_TEXT[71];
			Link.l1 = DLG_TEXT[72];
			Link.l1.go = "Exit_Next_Person";
			Link.l2 = DLG_TEXT[73];
			Link.l2.go = "Exit_Fight_Indians";
		break;
		
		case "Indians Talk 2":
			AddDialogExitQuest("Set Up Meeting Beach Thomas");
			PChar.quest.mysterious_plants.node = "Indians Talk 3";
			d.Text = DLG_TEXT[75];
			Link.l1 = DLG_TEXT[72];
			Link.l1.go = "Exit_Next_Person";
			Link.l2 = DLG_TEXT[73];
			Link.l2.go = "Exit_Fight_Indians";
		break;
		
		case "Indians Talk 3":
			PChar.quest.mysterious_plants.node = "Indians Talk 4";
			d.Text = DLG_TEXT[76];
			Link.l1 = DLG_TEXT[72];
			Link.l1.go = "Exit_Next_Person";
			Link.l2 = DLG_TEXT[73];
			Link.l2.go = "Exit_Fight_Indians";
		break;
		
		case "Indians Talk 4":
			PChar.quest.mysterious_plants.node = "Indians Talk 5";
			d.Text = DLG_TEXT[77];
			Link.l1 = DLG_TEXT[72];
			Link.l1.go = "Exit_Next_Person";
			Link.l2 = DLG_TEXT[73];
			Link.l2.go = "Exit_Fight_Indians";
		break;
		
		case "Indians Talk 5":
			AddQuestRecord("plants", 24);
			PChar.quest.mysterious_plants.node = "Indians Talk 7";
			d.Text = DLG_TEXT[78];
			Link.l1 = DLG_TEXT[72];
			Link.l1.go = "Exit_Next_Person";
			Link.l2 = DLG_TEXT[73];
			Link.l2.go = "Exit_Fight_Indians";
			Link.l3 = DLG_TEXT[74];
			Link.l3.go = "Sneak away";
		break;
		
		case "Indians Talk 7":
			chancecaught = (2 - CalcCharacterSkill(PChar, SKILL_SNEAK)) * 10;
			if(rand(100) < chancecaught) PChar.quest.mysterious_plants.node = "Indians Talk Caught";
			else PChar.quest.mysterious_plants.node = "Indians Talk 8";
			d.Text = DLG_TEXT[79];
			Link.l1 = DLG_TEXT[72];
			Link.l1.go = "Exit_Next_Person";
			Link.l2 = DLG_TEXT[73];
			Link.l2.go = "Exit_Fight_Indians";
			Link.l3 = DLG_TEXT[74];
			Link.l3.go = "Sneak away";
		break;
		
		case "Indians Talk 8":
			AddDialogExitQuest("Hide Indian Treasure");
			chancecaught = (15 - CalcCharacterSkill(PChar, SKILL_SNEAK)) * 10;
			if(rand(100) < chancecaught) PChar.quest.mysterious_plants.node = "Indians Talk Caught Treasure";
			else PChar.quest.mysterious_plants.node = "Indians Talk 9";
			d.Text = DLG_TEXT[80];
			Link.l1 = DLG_TEXT[72];
			Link.l1.go = "Exit_Next_Person";
			Link.l2 = DLG_TEXT[73];
			Link.l2.go = "Exit_Fight_Indians";
			Link.l3 = DLG_TEXT[74];
			Link.l3.go = "Sneak away";
		break;
		
		case "Indians Talk 9":
			AddQuestRecord("indian_treasure", 1);
			chancecaught = (4 - CalcCharacterSkill(PChar, SKILL_SNEAK)) * 10;
			if(rand(100) < chancecaught) PChar.quest.mysterious_plants.node = "Indians Talk Caught";
			else PChar.quest.mysterious_plants.node = "Indians Talk 10";
			d.Text = DLG_TEXT[81];
			Link.l1 = DLG_TEXT[72];
			Link.l1.go = "Exit_Next_Person";
			Link.l2 = DLG_TEXT[73];
			Link.l2.go = "Exit_Fight_Indians";
			Link.l3 = DLG_TEXT[74];
			Link.l3.go = "Sneak away";
		break;
		
		case "Indians Talk 10":
			chancecaught = (5 - CalcCharacterSkill(PChar, SKILL_SNEAK)) * 10;
			if(rand(100) < chancecaught) PChar.quest.mysterious_plants.node = "Indians Talk Caught";
			else PChar.quest.mysterious_plants.node = "Indians Talk 11";
			d.Text = DLG_TEXT[82];
			Link.l1 = DLG_TEXT[72];
			Link.l1.go = "Exit_Next_Person";
			Link.l2 = DLG_TEXT[73];
			Link.l2.go = "Exit_Fight_Indians";
			Link.l3 = DLG_TEXT[74];
			Link.l3.go = "Sneak away";
		break;
		
		case "Indians Talk 11":
			chancecaught = (6 - CalcCharacterSkill(PChar, SKILL_SNEAK)) * 10;
			if(rand(100) < chancecaught) PChar.quest.mysterious_plants.node = "Indians Talk Caught";
			else 
			{
				if(sti(GetAttribute(pchar,"quest.mysterious_plants.indians.killed")) > 1)
				{
					PChar.quest.mysterious_plants.node = "Indians Talk 12b";
				}
				else
				{
					PChar.quest.mysterious_plants.node = "Indians Talk 12a";
				}
			}
			d.Text = DLG_TEXT[83];
			Link.l1 = DLG_TEXT[72];
			Link.l1.go = "Exit_Next_Person";
			Link.l2 = DLG_TEXT[73];
			Link.l2.go = "Exit_Fight_Indians";
			Link.l3 = DLG_TEXT[74];
			Link.l3.go = "Sneak away";
		break;
		
		case "Indians Talk 12a":
			chancecaught = (7 - CalcCharacterSkill(PChar, SKILL_SNEAK)) * 10;
			if(rand(100) < chancecaught) PChar.quest.mysterious_plants.node = "Indians Talk Caught";
			else PChar.quest.mysterious_plants.node = "Indians Talk 13a";
			d.Text = DLG_TEXT[84];
			Link.l1 = DLG_TEXT[72];
			Link.l1.go = "Exit_Next_Person";
			Link.l2 = DLG_TEXT[73];
			Link.l2.go = "Exit_Fight_Indians";
			Link.l3 = DLG_TEXT[74];
			Link.l3.go = "Sneak away";
		break;
		
		case "Indians Talk 13a":
			PChar.quest.mysterious_plants.node = "Indians Talk Caught";
			d.Text = DLG_TEXT[85];
			Link.l1 = DLG_TEXT[72];
			Link.l1.go = "Exit_Next_Person";
			Link.l2 = DLG_TEXT[73];
			Link.l2.go = "Exit_Fight_Indians";
			Link.l3 = DLG_TEXT[74];
			Link.l3.go = "Sneak away";
		break;
		
		case "Indians Talk 12b":
			PChar.quest.mysterious_plants.node = "Indians Talk Caught";
			d.Text = DLG_TEXT[87];
			Link.l1 = DLG_TEXT[72];
			Link.l1.go = "Exit_Next_Person";
			Link.l2 = DLG_TEXT[73];
			Link.l2.go = "Exit_Fight_Indians";
			Link.l3 = DLG_TEXT[74];
			Link.l3.go = "Sneak away";
		break;
		
		case "Indians Talk Caught":
			d.Text = DLG_TEXT[86];
			Link.l1 = DLG_TEXT[73];
			Link.l1.go = "Exit_Fight_Spotted";
		break;
		
		case "Indians Talk Caught Treasure":
			AddQuestRecord("indian_treasure", 7);
			d.Text = DLG_TEXT[86];
			Link.l1 = DLG_TEXT[73];
			Link.l1.go = "Exit_Fight_Spotted";
		break;
		
		case "Exit_Next_Person":
			AddDialogExitQuest("Apothecary Sneak in Warehouse Dialog");
			DialogExit();
		break;
		
		case "Exit_Fight_Indians":
			AddDialogExitQuest("Apothecary Sneak in Warehouse Fight");
			DialogExit();
		break;
		
		case "Exit_Fight_Spotted":
			AddDialogExitQuest("Apothecary Sneak in Warehouse Spotted");
			DialogExit();
		break;
		
		case "Sneak away":
			AddDialogExitQuest("Apothecary Sneak in Warehouse Away");
			DialogExit();
		break;
		
		case "Thomas Spotted":
			
			If (PChar.location.locator == "citizen06")
			{
			d.Text = DLG_TEXT[178];
			}
			else
			{
			d.Text = DLG_TEXT[118];
			}
			Link.l1 = DLG_TEXT[119];
			Link.l1.go = "exit2";
			Diag.TempNode = "First time";
			AddDialogExitQuest("Thomas Makes Deal Natives 3");
		break;
		
		case "Beggar In Cartagena":
			if(sti(Npchar.quest.indians.liking) >  0)
			{
				if(sti(Npchar.quest.indians.liking) >  0)  d.Text = DLG_TEXT[130];
				if(sti(Npchar.quest.indians.liking) >  15) d.Text = DLG_TEXT[131];
				if(sti(Npchar.quest.indians.liking) >  30) d.Text = DLG_TEXT[132];
				if(sti(Npchar.quest.indians.liking) >  50) d.Text = DLG_TEXT[133];
				if(sti(Npchar.quest.indians.liking) >  65) d.Text = DLG_TEXT[134];
				if(sti(Npchar.quest.indians.liking) >= 80) d.Text = DLG_TEXT[135];
				if(sti(Npchar.quest.indians.liking) >= 80)
				{
					if(CheckCharacterItem(Pchar,"hotel_flyer"))
					{
						//JRH: could give multiple 'hotel_flyers'
					}
					else
					{
						Link.l1 = DLG_TEXT[139];
						Link.l1.go = "Succes with Beggar";
					}
				}
				else
				{
					if(sti(Npchar.quest.indians.liking) > 50)
					{
						Link.l2 = DLG_TEXT[136];
						Link.l2.go = "Try Luck With Beggar";
					}
					if(sti(PChar.money)>=10)
					{
						Link.l3 = DLG_TEXT[140];
						Link.l3.go = "Pay Beggar 10 Coins";
					}
					if(sti(PChar.money)>=500)
					{
						Link.l4 = DLG_TEXT[144];
						Link.l4.go = "Pay Beggar 500 Coins";
					}
					if(CheckCharacterItem(Pchar,"vegetal"))
					{
						Link.l5 = DLG_TEXT[145];
						Link.l5.go = "Give Beggar Vegetal";
					}
					Link.l6 = DLG_TEXT[147];
					Link.l6.go = "Tell Story To Beggar";
				}
				if(sti(GetAttribute(Pchar,"quest.mysterious_plants.indians.killed")) >= 2)
				{
					Link.l7 = DLG_TEXT[150];
					Link.l7.go = "Tell About Dead Indians";
				}
				Link.l8 = DLG_TEXT[155];
				Link.l8.go = "exit2";
			}
			else
			{
				d.Text = DLG_TEXT[154];
				Link.l1 = DLG_TEXT[119];
				Link.l1.go = "exit2";
			}
			Diag.TempNode = "Beggar In Cartagena";
		break;
		
		case "Try Luck With Beggar":
			int succeschance = CalcCharacterSkill(PChar, SKILL_SNEAK) * 10;
			if(rand(99) < succeschance)
			{
				//succes
				d.Text = PersuasionSuccess + DLG_TEXT[135];
				Link.l1 = DLG_TEXT[139];
				Link.l1.go = "Succes with Beggar";
			}
			else
			{
				//fail
				Npchar.quest.indians.liking = sti(Npchar.quest.indians.liking) - 5;
				d.Text = PersuasionFailure + DLG_TEXT[137];
				Link.l1 = DLG_TEXT[138];
				Link.l1.go = "Beggar In Cartagena";
			}
		break;
		
		case "Pay Beggar 10 Coins":
			int succeschancepay = 50 + CalcCharacterSkill(PChar, SKILL_SNEAK) * 5;
			AddMoneyToCharacter(pchar, -10);
			if(sti(Npchar.quest.indians.liking) <  30 || rand(99) > succeschancepay)
			{
				//fail
				Npchar.quest.indians.liking = sti(Npchar.quest.indians.liking) - 5;
				d.Text = DLG_TEXT[143];
				Link.l1 = DLG_TEXT[138];
				Link.l1.go = "Beggar In Cartagena";
			}
			else
			{
				//succes
				Npchar.quest.indians.liking = sti(Npchar.quest.indians.liking) + 5;
				d.Text = DLG_TEXT[141];
				Link.l1 = DLG_TEXT[142];
				Link.l1.go = "Beggar In Cartagena";
			}
		break;
		
		case "Pay Beggar 500 Coins":
			AddMoneyToCharacter(pchar, -500);
			Npchar.quest.indians.liking = sti(Npchar.quest.indians.liking) + 10 + rand(5*(3+makeint(CalcCharacterSkill(PChar, SKILL_SNEAK)/2))); //little bit of randomness to this
			d.Text = DLG_TEXT[141];
			Link.l1 = DLG_TEXT[142];
			Link.l1.go = "Beggar In Cartagena";
		break;
		
		case "Give Beggar Vegetal":
			Npchar.quest.indians.liking = sti(Npchar.quest.indians.liking) + 25;
			d.Text = DLG_TEXT[146];
			Link.l1 = DLG_TEXT[142];
			Link.l1.go = "Beggar In Cartagena";
		break;
		
		case "Tell Story To Beggar":
			int comparerep = REPUTATION_PLAIN
			if(sti(Npchar.quest.indians.liking) > REPUTATION_PLAIN) comparerep = sti(Npchar.quest.indians.liking);
			if(GetCharacterReputation(pchar) >= comparerep && rand(99)>33) //Let's also add a little randomness to this because not every storey is nice (1/3 chance to fail)
			{
				//succes
				Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)); // DeathDaisy
				Npchar.quest.indians.liking = sti(Npchar.quest.indians.liking) + 10;
				d.Text = DLG_TEXT[148];
				Link.l1 = DLG_TEXT[141];
				Link.l1.go = "Beggar In Cartagena";
			}
			else
			{
				//fail
				Npchar.quest.indians.liking = sti(Npchar.quest.indians.liking) - 5;
				d.Text = DLG_TEXT[149];
				Link.l1 = DLG_TEXT[138];
				Link.l1.go = "Beggar In Cartagena";
			}
		break;
		
		case "Tell About Dead Indians":
			if(sti(GetAttribute(Pchar,"quest.mysterious_plants.indians.killed")) >= 8)
			{
				Npchar.quest.indians.liking = 0;
				d.Text = DLG_TEXT[153];
				Link.l1 = DLG_TEXT[152];
				Link.l1.go = "Beggar In Cartagena";
			}
			else
			{
				Npchar.quest.indians.liking = 14;
				d.Text = DLG_TEXT[151];
				Link.l1 = DLG_TEXT[152];
				Link.l1.go = "Beggar In Cartagena";
			}
		break;
		
		case "Succes with Beggar":
			d.Text = DLG_TEXT[156];
			Link.l1 = DLG_TEXT[141];
			Link.l1.go = "exit2";
			AddDialogExitQuest("Got information from Indian Beggar");
			TakenItems(NPChar,"hotel_flyer",-1);
		break;

		case "Success Plants":
			d.Text = DLG_TEXT[163];
			Link.l1 = DLG_TEXT[164];
			Link.l1.go = "exit2";
			AddDialogExitQuest("Plants_end");
			TakenItems(NPChar,"ayahuasca",-4);
		break;
	}
}