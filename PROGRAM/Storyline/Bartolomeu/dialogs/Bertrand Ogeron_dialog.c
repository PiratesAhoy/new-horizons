//#include "DIALOGS\Bertrand Ogeron_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, PeaceGroup;
	int Nation, Sum;
	// RM -->
	int iNation;
	string sNation;
	// RM <--
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "First time":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			if(Pchar.quest.RelationAgentMet == "0")
			{
				Dialog.snd = "voice\REDI\REDI001";
				d.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
				Link.l1 = DLG_TEXT[2];
				Link.l1.go = "Tutorial";
				NPC_Meeting = "1"; 
				Pchar.quest.RelationAgentMet = "1"; // NK
			}
			else
			{
				if(NPChar.quest.meeting == "0")
				{
					Dialog.snd = "voice\REDI\REDI002";
					d.Text = DLG_TEXT[3];
					Link.l1 = DLG_TEXT[4] + Pchar.name + DLG_TEXT[5];
					Link.l1.go = "Service";
					Link.l2 = DLG_TEXT[6];
					Link.l2.go = "Exit";					
				}
				else
				{
					Dialog.snd = "voice\REDI\REDI003";
					d.Text = DLG_TEXT[7]; // NK
					Link.l1 = DLG_TEXT[8];
					Link.l1.go = "Service";
					Link.l2 = DLG_TEXT[9];
					Link.l2.go = "exit";

				}
			}

		break;

		case "Service":
			Dialog.snd = "voice\REDI\REDI004";
			d.Text = DLG_TEXT[10];
			if(GetRMRelation(PChar, PIRATE) <= REL_WAR) 
			{
				Link.l1 = DLG_TEXT[11];
				Link.l1.go = "Pirate";
			}
			else
			{
			Link.l2 = DLG_TEXT[16];
			Link.l2.go = "exit";
			}
		break;

		case "Tutorial":
			Dialog.snd = "voice\REDI\REDI005";
			d.Text = DLG_TEXT[17];
			Link.l99 = DLG_TEXT[18];
			Link.l99.go = "Tutorial_1";
		break;

		case "Tutorial_1":
			Dialog.snd = "voice\REDI\REDI006";
			d.Text = DLG_TEXT[19];
			Link.l99 = DLG_TEXT[20];
			Link.l99.go = "Tutorial_2";
		break;

		case "Tutorial_2":
			Dialog.snd = "voice\REDI\REDI007";
			d.Text = DLG_TEXT[21];
			Link.l99 = DLG_TEXT[22];
			Link.l99.go = "Tutorial_3";
		break;

		case "Tutorial_3":
			Dialog.snd = "voice\REDI\REDI008";
			d.Text = DLG_TEXT[23];
			Link.l99 = DLG_TEXT[24];
			Link.l99.go = "Tutorial_4";
		break;

		case "Tutorial_4":
			Dialog.snd = "voice\REDI\REDI009";
			d.Text = DLG_TEXT[25];
			Link.l99 = DLG_TEXT[26];
			Link.l99.go = "Service";
		break;

		case "Pirate": 
			iNation = GetNationTypeByID(Dialog.CurrentNode);
			sNation = iNation;
			Pchar.quest.Relations.nation = iNation;
			Pchar.quest.Relations.sum = RMAmnestyCost(PChar, iNation) * 1.5;
			Dialog.snd = "voice\REDI\REDI010";
			d.Text = DLG_TEXT[27] + ShowMoney(-sti(Pchar.quest.Relations.sum)) + DLG_TEXT[28];
			Link.l1 = DLG_TEXT[29];
			if(GetCharacterMoney(PChar) < 0-makeint(Pchar.quest.Relations.sum))
			{
				Link.l1.go = "No_money";			
			}
			else
			{
				Link.l1.go = "Agreed";			
			}
			Link.l2 = DLG_TEXT[30];
			Link.l2.go = "exit";			
		break;

		case "No_Money":
			Dialog.snd = "voice\REDI\REDI015";
			d.Text = DLG_TEXT[47];
			Link.l1 = DLG_TEXT[48];
			Link.l1.go = "exit";			
		break;

		case "Agreed":
			Dialog.snd = "voice\REDI\REDI016";
			RMAmnesty(PChar, sti(Pchar.quest.relations.nation));
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, makeint(Pchar.quest.Relations.sum)); // RM
			DeleteAttribute(Pchar, "quest.Relations");
			d.Text = DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[51];
			Link.l2.go = "Service";
		break;
// Aguadilla Battle Quest
		case "gov_1":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "gov_2";
		break;

		case "gov_2":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "gov_3";
		break;

		case "gov_3":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "gov_4";
		break;

		case "gov_4":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "gov_5";
		break;

		case "gov_5":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "gov_6";
		break;

		case "gov_6":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "gov_7";
		break;

		case "gov_7":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "gov_8";
		break;

		case "gov_8":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "gov_9";
		break;

		case "gov_9":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "gov_10";
		break;

		case "gov_10":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[71];
			link.l1.go = "gov_11";
		break;

		case "gov_11":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "gov_12";
		break;

		case "gov_12":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "gov_13";
		break;

		case "gov_13":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "gov_14";
		break;

		case "gov_14":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79];
			link.l1.go = "gov_15";
		break;

		case "gov_15":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[80];
			link.l1 = DLG_TEXT[81];
			link.l1.go = "gov_16";
		break;

		case "gov_16":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "gov_17";
		break;

		case "gov_17":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "gov_18";
		break;

		case "gov_18":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[87];
			link.l1.go = "gov_19";
		break;

		case "gov_19":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[88];
			link.l1 = DLG_TEXT[89];
			link.l1.go = "gov_20";
		break;

		case "gov_20":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[90];
			link.l1 = DLG_TEXT[91];
			link.l1.go = "exit";
                AddDialogExitQuest("voir_Montbars_tortue");			
		break;

		case "gov_21":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[92];
			link.l1 = DLG_TEXT[93];
			link.l1.go = "gov_22";
		break;

		case "gov_22":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[94];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "exit";
                AddDialogExitQuest("paymaster_tortuga3");			
		break;

		case "gov_23":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];
			link.l1.go = "exit";
                AddDialogExitQuest("paymaster_tortuga5");			
		break;

		case "gov_24":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "exit";
                AddDialogExitQuest("paymaster_tortuga9");			
		break;

		case "gov_25":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[98];
			link.l1 = DLG_TEXT[99];
			link.l1.go = "gov_26";
		break;

		case "gov_26":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[100];
			link.l1 = DLG_TEXT[101];
			link.l1.go = "gov_27";
		break;

		case "gov_27":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "exit";
                AddDialogExitQuest("paymaster_tortuga11");			
		break;

		case "gov_28":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[103];
			link.l1 = DLG_TEXT[104];
			link.l1.go = "gov_29";
		break;

		case "gov_29":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[106];
			link.l1.go = "gov_30";
		break;	

		case "gov_30":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[107];
			link.l1 = DLG_TEXT[108];
			link.l1.go = "gov_31";
		break;

		case "gov_31":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[109];
			link.l1 = DLG_TEXT[110];
			link.l1.go = "exit";
                AddDialogExitQuest("fontaines_tortuga");			
		break;

		case "gov_32":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[112];
			link.l1 = DLG_TEXT[113];
			link.l1.go = "gov_33";
		break;

		case "gov_33":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[114];
			link.l1 = DLG_TEXT[115];
			link.l1.go = "gov_34";
		break;

		case "gov_34":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[116];
			link.l1 = DLG_TEXT[117];
			link.l1.go = "gov_35";
		break;

		case "gov_35":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[118];
			link.l1 = DLG_TEXT[119];
			link.l1.go = "gov_36";
		break;

		case "gov_36":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[120];
			link.l1 = DLG_TEXT[121];
			link.l1.go = "gov_37";
		break;

		case "gov_37":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[122];
			link.l1 = DLG_TEXT[123];
			link.l1.go = "exit";
                AddDialogExitQuest("searching_montbars");			
		break;		

		case "gov_38":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[124];
			link.l1 = DLG_TEXT[125];
			link.l1.go = "gov_39";
		break;

		case "gov_39":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[127];
			link.l1.go = "gov_40";
		break;

		case "gov_40":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[128];
			link.l1 = DLG_TEXT[129];
			link.l1.go = "gov_41";
		break;

		case "gov_41":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[130];
			link.l1 = DLG_TEXT[131];
			link.l1.go = "gov_42";
		break;

		case "gov_42":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[132];
			link.l1 = DLG_TEXT[133];
			link.l1.go = "gov_43";
		break;

		case "gov_43":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[134];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "exit";
    			Locations[FindLocation("Tortuga_port")].vcskip = true;			
                AddDialogExitQuest("partager_gold");			
		break;

		case "gov_44":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[135];
			link.l1 = DLG_TEXT[136];
			link.l1.go = "gov_45";
		break;

		case "gov_45":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[137];
			link.l1 = DLG_TEXT[138];
			link.l1.go = "gov_46";
		break;

		case "gov_46":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[139];
			link.l1 = DLG_TEXT[140];
			link.l1.go = "exit";
			AddMoneyToCharacter(pchar, 80000);				
                AddDialogExitQuest("partager_goldbis2");			
		break;				
		
	}
}