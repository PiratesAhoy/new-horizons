//#include "DIALOGS\rachel blacque_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

void ProcessDialogEvent()
{
	ref NPChar;
	
	DeleteAttribute(&Dialog,"Links");
	aref Link, NextDiag;
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

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
			Dialog.snd = "voice\RABL\RABL001";

			Dialog.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
			if (characters[GetCharacterIndex("Milon Blacque")].quest.son == "letter_return" && NPChar.quest.letter != "done") //NK so you can only give it once
			{
				Preprocessor_Add("Marc", GetMyName(CharacterFromID("Marc Blacque")));
				link.l1 = DLG_TEXT[2];
				link.l1.go = "letter";
//NK add badguy quest back so you can still complete it even with letter -->
				if (NPChar.quest.badguy == "3")
				{
					Link.l3 = DLG_TEXT[11];
					Link.l3.go = "problems";
				}
				if (NPChar.quest.badguy == "done")
				{
					Link.l3 = DLG_TEXT[4] + GetMyName(NPChar) + DLG_TEXT[5] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[6])]) + DLG_TEXT[8];
					Link.l3.go = "problems_7";
				}
//NK <--
			}
			else
			{
				if (characters[GetCharacterIndex("Milon Blacque")].quest.son == "done")
				{
					link.l1 = DLG_TEXT[3];
					link.l1.go = "resque";
//NK allow you to complete badguy -->
					if (NPChar.quest.badguy == "3")
					{
						Link.l3 = DLG_TEXT[11];
						Link.l3.go = "problems";
					}
					if (NPChar.quest.badguy == "done")
					{
						Link.l3 = DLG_TEXT[4] + GetMyName(NPChar) + DLG_TEXT[5] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[6])]) + DLG_TEXT[8];
						Link.l3.go = "problems_7";
					}
//NK <--
				}
				else
				{
					if (NPChar.quest.badguy == "done")
					{
						Link.l1 = DLG_TEXT[4] + GetMyName(NPChar) + DLG_TEXT[5] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[6])]) + DLG_TEXT[8];
						Link.l1.go = "problems_7";
					}
					else
					{
						Link.l1 = DLG_TEXT[9];
						Link.l1.go = "exit";
						Link.l2 = DLG_TEXT[10];
						if (makeint(PChar.reputation) > 50)
						{
							Link.l2.go = "good guy";
						}
						else
						{
							Link.l2.go = "bad guy";
						}
						if (NPChar.quest.badguy == "3")
						{
							Link.l3 = DLG_TEXT[11];
							Link.l3.go = "problems";
						}
						// NK -->
						Preprocessor_AddQuestData("Blacque", GetMyLastName(CharacterFromID("Marc Blacque")));
						Preprocessor_AddQuestData("Rachel Blacque", GetMyFullName(NPChar));
						SetQuestHeader("Blacques");
						AddQuestRecord("Blacques", 1);
						Preprocessor_Remove("Rachel Blacque");
						Preprocessor_Remove("Blacque");
						// NK <--
					}
				}
			}
			NextDiag.TempNode = "First time";
		break;

		case "Second time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\RABL\RABL001";

			Preprocessor_Add("Rachel", GetMyName(NPChar));
			Dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "exit";
								
			NextDiag.TempNode = "Second time";		
		break;			
			
		case "good guy":
			Dialog.snd = "voice\RABL\RABL002";
			Dialog.Text = DLG_TEXT[12] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[13])]) + DLG_TEXT[15];
			if (Characters[GetCharacterIndex("Milon Blacque")].quest.first_talk != "0")
			{
				Link.l1 = DLG_TEXT[16];
				Link.l1.go ="Milon Know";
			}
			else
			{
				Link.l1 = DLG_TEXT[17];
				Link.l1.go = "Mad Milon_3";
			}
			Link.l2 = DLG_TEXT[18];
			Link.l2.go = "exit";
		break;

		case "bad guy":
			Dialog.snd = "voice\RABL\RABL003";
			Dialog.Text = DLG_TEXT[19] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "Exit";
		break;

		case "Milon Know":
			Dialog.snd = "voice\RABL\RABL004";
			Dialog.Text = DLG_TEXT[22];
			if (Characters[GetCharacterIndex("Milon Blacque")].quest.first_talk == "done")
			{
				Link.l1 = DLG_TEXT[23];
				Link.l1.go = "Mad Milon_1";
				Link.l2 = DLG_TEXT[24];
				Link.l2.go = "Mad Milon_2";
			}
			else
			{
				Link.l1 = DLG_TEXT[25];
				Link.l1.go = "Mad Milon_3";
			}
		break;
		
		case "Mad Milon_1":
			Dialog.snd = "voice\RABL\RABL005";
			Dialog.Text = DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "Exit";
		break;

		case "Mad Milon_2":
			Dialog.snd = "voice\RABL\RABL006";
			ChangeCharacterReputation(pchar, -5);
			Dialog.Text = DLG_TEXT[28] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[29];
			Link.l1 = DLG_TEXT[30];
			Link.l1.go = "Exit";
		break;

		case "Mad Milon_3":
			Dialog.snd = "voice\RABL\RABL007";
			Dialog.Text = DLG_TEXT[31];
			Link.l1 = DLG_TEXT[32];
			Link.l1.go = "Exit";
		break;

		case "problems":
			Dialog.snd = "voice\RABL\RABL008";
			Dialog.text = DLG_TEXT[33] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "problems_1";
			link.l2 = DLG_TEXT[36] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[37])]) + DLG_TEXT[38];
			link.l2.go = "problems_2";
		break;

		case "problems_1":
			if (makeint(PChar.reputation) > 50)
			{
				Dialog.snd = "voice\RABL\RABL009";
				Dialog.text = DLG_TEXT[39] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[40];
				Link.l1 = DLG_TEXT[41];
				link.l1.go = "exit";
				link.l2 = DLG_TEXT[42];
				link.l2.go = "problems_3";
			}
			else
			{
				Dialog.snd = "voice\RABL\RABL010";
				Dialog.text = DLG_TEXT[43];
				link.l1 = DLG_TEXT[44];
				link.l1.go = "exit";
			}
		break;

		case "problems_2":
			Dialog.snd = "voice\RABL\RABL011";
			Dialog.text = GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[45])]) + DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "problems_2_1";
		break;

		case "problems_2_1":
			Dialog.snd = "voice\RABL\RABL012";
			Dialog.text = DLG_TEXT[48] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[51];
			link.l2.go = "problems_3";
		break;

		case "problems_3":
			Dialog.snd = "voice\RABL\RABL013";
			Dialog.text = DLG_TEXT[52];
			Link.l1 = DLG_TEXT[53];
			link.l1.go = "problems_4";
			if (PChar.money > 100)
			{
				Link.l2 = DLG_TEXT[54];
				Link.l2.go = "money";
			}
		break;

		case "problems_4":
			Dialog.snd = "voice\RABL\RABL014";
			Dialog.text = DLG_TEXT[55] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[56];
			Link.l1 = DLG_TEXT[57];
			Link.l1.go = "exit";
			//NPChar.quest.badguy == "money"; //NK dunno why this here but it shouldn't be
			Link.l2 = DLG_TEXT[58];			Link.l2 = DLG_TEXT[58];
			Link.l2.go = "problems_5";
		break;

		case "problems_5":
			Dialog.snd = "voice\RABL\RABL015";
			Dialog.text = DLG_TEXT[59] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[60])]) + DLG_TEXT[62];
			Link.l1 = DLG_TEXT[63];
			Link.l1.go = "exit";
			//NPChar.quest.badguy == "money"; //NK dunno why this here but it shouldn't be
			Link.l2 = GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[64])]) + DLG_TEXT[66];
			Link.l2.go = "problems_6";
		break;

		case "problems_6":
			Dialog.snd = "voice\RABL\RABL016";
			Dialog.text = DLG_TEXT[67];
			Link.l1 = DLG_TEXT[68];
			NPChar.quest.badguy = "1";
			Preprocessor_AddQuestData("Orable Caron", GetMySimpleName(CharacterFromID("Orable Caron")));
			Preprocessor_AddQuestData("Rachel", GetMyName(NPChar));
			AddQuestRecord("Blacques", 5); // NK
			Preprocessor_Remove("Rachel");
			Preprocessor_Remove("Orable Caron");
			Link.l1.go = "exit";
		break;

		case "problems_7":
			Preprocessor_AddQuestData("Rachel", GetMyName(NPChar));
			AddQuestRecord("Blacques", 8); // NK
			Preprocessor_Remove("Rachel");
			Dialog.snd = "voice\RABL\RABL017";
			Dialog.text = DLG_TEXT[69] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[70];
			//ChangeCharacterAddress(characterFromID("Orable caron"), "none", ""); //NK move Rachel to port, and set so you can't keep saying you've delt with Orable and get more rep.
			NPChar.location	= "Falaise_de_fleur_port_01";
			NPChar.location.group = "goto";
			NPChar.location.locator = "goto15";
			NPChar.quest.badguy = "really_done";
			Link.l1 = DLG_TEXT[71];
			Link.l1.go = "exit";
			ChangeCharacterReputation(pchar, 1);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 700);
				AddPartyExpChar(pchar, "Sneak", 7);
			}
			else { AddPartyExp(pchar, 700); }
		break;

		case "money":
			Dialog.snd = "voice\RABL\RABL018";
			Dialog.text = DLG_TEXT[72] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) DLG_TEXT[73];
			Link.l1 = DLG_TEXT[74];
			link.l1.go = "exit";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -100);
			Preprocessor_AddQuestData("Rachel", GetMyName(NPChar));
			AddQuestRecord("Blacques", 6); // NK
			Preprocessor_Remove("Rachel");
			NPChar.quest.badguy = "money";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 700);
				AddPartyExpChar(pchar, "Sneak", 7);
			}
			else { AddPartyExp(pchar, 700); }
			ChangeCharacterReputation(pchar, 1);
			//npchar.location = "none";
			//ChangeCharacterAddress(characterFromID("Orable caron"), "none", ""); //NK disable the removal of both, as they still have roles...
			Rumour[3].state = "active";
		break;

		case "letter":
			Dialog.snd = "voice\RABL\RABL019";
			Dialog.text = DLG_TEXT[75];
			link.l1 = DLG_TEXT[76];
			link.l1.go = "letter_1";
		break;

		case "letter_1":
			Dialog.snd = "voice\RABL\RABL020";
			Preprocessor_Add("Marc", GetMyName(CharacterFromID("Marc Blacque")));
			Dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "letter_2";
		break;

		case "letter_2":
			Dialog.snd = "voice\RABL\RABL021";
			Dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[81];
			link.l2.go = "letter_3";
		break;

		case "letter_3":
			Dialog.snd = "voice\RABL\RABL022";
			Dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "letter_4";
		break;
		
		case "letter_4":
			Dialog.snd = "voice\RABL\RABL023";
			Dialog.text = DLG_TEXT[84] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "exit";
			ChangeCharacterReputation(pchar, 1);
			NPChar.quest.letter = "done"; //NK make quest done
		break;

		case "resque":
			Dialog.snd = "voice\RABL\RABL024";
			Dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "resque_1";
		break;

		case "resque_1":
			Preprocessor_AddQuestData("Marc", GetMyName(CharacterFromID("Marc Blacque")));
			Preprocessor_AddQuestData("Rachel", GetMyName(NPChar));
			AddQuestRecord("Blacques", 13); // NK
			Preprocessor_Remove("Rachel");
			Preprocessor_Remove("Marc");
			Preprocessor_Add("Marc", GetMyName(CharacterFromID("Marc Blacque")));
			if (makeint(pchar.reputation) < 51)
			{
				Dialog.snd = "voice\RABL\RABL025";
				Dialog.text = DLG_TEXT[89];
				link.l1 = DLG_TEXT[90];
				link.l1.go = "exit";
			}
			else
			{
				Dialog.snd = "voice\RABL\RABL026";
				Dialog.text = DLG_TEXT[91];
				link.l1 = DLG_TEXT[92];
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "Second time";				
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
