//#include "DIALOGS\Rys Bloom_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	if(npchar.quest.help == "done")
	{
		Diag.CurrentNode = "Help_Succesful";
		npchar.quest.help = "0";
	}
	if(npchar.quest.help == "failed")
	{
		Diag.CurrentNode = "Help_failed";
		npchar.quest.help = "0";
	}



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
			Dialog.snd = "voice\RYBL\RYBL001";

			Diag.TempNode = "First time";
			d.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) +DLG_TEXT[1];
			Link.l1 = DLG_TEXT[2];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[3] + GetMyName(Pchar) + DLG_TEXT[4];
			Link.l2.go = "node_2";
		break;

		case "Node_2":
			Diag.TempNode = "Second Time";
			Dialog.snd = "voice\RYBL\RYBL002";
			d.Text = DLG_TEXT[5] + GetMyShipNameShow(PChar) + DLG_TEXT[6] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[7];
			Link.l1 = DLG_TEXT[8];
			Link.l1.go = "node_3";
			Link.l2 = DLG_TEXT[9];
			Link.l2.go = "Exit";
		break;

		case "Node_3":
			Dialog.snd = "voice\RYBL\RYBL003";
			d.Text = DLG_TEXT[10] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.name +DLG_TEXT[11] + GetMyName(NPChar) + DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[14];
			Link.l2.go = "node_4";
		break;

		case "Node_4":
			Dialog.snd = "voice\RYBL\RYBL004";
			d.Text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "Node_5";
			Link.l2 = DLG_TEXT[17];
			Link.l2.go = "exit";
		break;

		case "Node_5":
			Dialog.snd = "voice\RYBL\RYBL005";
			d.Text = DLG_TEXT[18] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[19];
			Link.l1 = DLG_TEXT[20];
			Link.l1.go = "Node_6";
			Link.l2 = DLG_TEXT[21];
			Link.l2.go = "node_7";
			Link.l3 = DLG_TEXT[22];
			Link.l3.go = "exit";
		break;

		case "Node_6":
			Dialog.snd = "voice\RYBL\RYBL006";
			d.Text = DLG_TEXT[23] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[24];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "Node_8";
			Link.l2 = DLG_TEXT[26];
			Link.l2.go = "node_9";
		break;

		case "Node_7":
			Dialog.snd = "voice\RYBL\RYBL007";
			Diag.TempNode = "Second time";
			d.Text = DLG_TEXT[27] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[28];
			Link.l1 = DLG_TEXT[29];
			Link.l1.go = "node_10";
			Link.l2 = DLG_TEXT[30];
			Link.l2.go = "exit";
		break;

		case "Node_8":
			Diag.TempNode = "Agreed_help";
			NPChar.quest.help = "agreed";
			Dialog.snd = "voice\RYBL\RYBL008";
			d.Text = DLG_TEXT[31];
			Link.l1 = DLG_TEXT[32];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[33];
			Link.l2.go = "Node_10_1";
		break;

		case "Node_9":
			Diag.TempNode = "Second time";
			Dialog.snd = "voice\RYBL\RYBL009";
			d.Text = DLG_TEXT[34];
			Link.l1 = DLG_TEXT[35];
			Link.l1.go = "Exit";
		break;

		case "Node_10":
			Diag.TempNode = "Agreed_help";
			NPChar.quest.help = "agreed";
			Dialog.snd = "voice\RYBL\RYBL010";
			d.Text = DLG_TEXT[36];
			Link.l1 = DLG_TEXT[37];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[38];
			Link.l2.go = "Node_10_1";
		break;

		case "Node_10_1":
			Dialog.snd = "voice\RYBL\RYBL011";
			d.Text = DLG_TEXT[39];
			Link.l1 = DLG_TEXT[40];
			Link.l1.go = "Exit";
		break;
//--------------------------Диалог 2: Игрок познакомился с Рисом, но отказался ему помочь.


		case "Second time":
			Dialog.snd1 = "voice\RYBL\RYBL012";
			Dialog.snd2 = "voice\RYBL\RYBL013";
			Dialog.snd3 = "voice\RYBL\RYBL014";
			d.Text = RandPhrase(DLG_TEXT[41] + GetMyName(Pchar) + DLG_TEXT[42] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[43], DLG_TEXT[44] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + GetMyName(PChar) + DLG_TEXT[45], DLG_TEXT[46] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[47], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
			Link.l1 = DLG_TEXT[48] + GetMyName(NPChar) + DLG_TEXT[49];
			Link.l1.go = "Node_11";
			Link.l2 = DLG_TEXT[50];
			Link.l2.go = "exit";
		break;

		case "Node_11":
			Dialog.snd = "voice\RYBL\RYBL015";
			d.Text = DLG_TEXT[51] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[52];
			Link.l1 = DLG_TEXT[53];
			Link.l1.go = "Node_12";
			Link.l2 = DLG_TEXT[54];
			Link.l2.go = "node_13";
			Link.l3 = DLG_TEXT[55];
			Link.l3.go = "exit";
		break;

		case "Node_12":
			Dialog.snd = "voice\RYBL\RYBL016";
			d.Text = DLG_TEXT[56] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[57];
			Link.l1 = DLG_TEXT[58];
			Link.l1.go = "Node_14";
			Link.l2 = DLG_TEXT[59];
			Link.l2.go = "node_15";
		break;

		case "Node_13":
			Diag.TempNode = "Second time";
			Dialog.snd = "voice\RYBL\RYBL017";
			d.Text = DLG_TEXT[60] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + GetMyName(PChar) + DLG_TEXT[61];
			Link.l1 = DLG_TEXT[62];
			Link.l1.go = "node_16";
			Link.l2 = DLG_TEXT[63];
			Link.l2.go = "exit";
		break;

		case "Node_14":
			Diag.TempNode = "Agreed_help";
			NPChar.quest.help = "agreed";
			Dialog.snd = "voice\RYBL\RYBL018";
			d.Text = DLG_TEXT[64];
			Link.l1 = DLG_TEXT[65];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[66];
			Link.l2.go = "Node_10_1";
		break;

		case "Node_15":
			Dialog.snd = "voice\RYBL\RYBL019";
			Diag.TempNode = "Second time";
			d.Text = DLG_TEXT[67];
			Link.l1 = DLG_TEXT[68];
			Link.l1.go = "Exit";
		break;

		case "Node_16":
			Dialog.snd = "voice\RYBL\RYBL020";
			Diag.TempNode = "Agreed_help";
			NPChar.quest.help = "agreed";
			d.Text = DLG_TEXT[69];
			Link.l1 = DLG_TEXT[70];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[71];
			Link.l2.go = "Node_10_1";
		break;


//-------------------------Диалог 3 - Игрок поговорил с Блюмом, и согласился ему помочь.

		case "Agreed_Help":
			Dialog.snd1 = "voice\RYBL\RYBL021";
			Dialog.snd2 = "voice\RYBL\RYBL022";
			Dialog.snd3 = "voice\RYBL\RYBL023";
			Diag.TempNode = "Agreed_help";
			d.Text = RandPhrase(DLG_TEXT[72] + GetMyName(Pchar) + DLG_TEXT[73] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[74], DLG_TEXT[75] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) +" "+ GetMyName(PChar) + DLG_TEXT[76], DLG_TEXT[77] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[78], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3) + DLG_TEXT[79];
			Link.l1 = DLG_TEXT[80];
			Link.l1.go = "Node_17";
			Link.l2 = DLG_TEXT[81];
			Link.l2.go = "exit";
			Link.l2 = DLG_TEXT[82];
			Link.l2.go = "Node_10_1";
		break;

		case "Node_17":
			Dialog.snd = "voice\RYBL\RYBL024";
			d.Text = DLG_TEXT[83] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[84];
			Link.l1 = DLG_TEXT[85];
			Link.l1.go = "Node_18";
			if(NPChar.quest.dialog == "0") {
			Link.l2 = DLG_TEXT[86];
			Link.l2.go = "node_19";
			NPChar.quest.dialog = "1"; // NK fixed 04-09-20
			}
			else 
			{
			Link.l2 = DLG_TEXT[87];
			Link.l2.go = "node_20";
			}
		break;

		case "Node_18":
			Dialog.snd = "voice\RYBL\RYBL025";
			d.Text = DLG_TEXT[88] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[89];
			Link.l1 = DLG_TEXT[90];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[91];
			Link.l2.go = "exit";
		break;

		case "Node_19":
			Dialog.snd = "voice\RYBL\RYBL026";
			d.Text = DLG_TEXT[92] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[93];
			Link.l1 = DLG_TEXT[94];
			Link.l1.go = "node_20";
			Link.l2 = DLG_TEXT[95];
			Link.l2.go = "exit";
		break;

		case "Node_20":
			Dialog.snd = "voice\RYBL\RYBL027";
			d.Text = DLG_TEXT[96];
			Link.l1 = DLG_TEXT[97];
			Link.l1.go = "node_21";
			Link.l2 = DLG_TEXT[98];
			Link.l2.go = "node_23";
			Link.l3 = DLG_TEXT[99];
			Link.l3.go = "node_24";
		break;

		case "Node_21":
			Dialog.snd = "voice\RYBL\RYBL028";
			d.Text = DLG_TEXT[100];
			Link.l1 = DLG_TEXT[101];
			Link.l1.go = "node_22";
		break;

		case "Node_22":
			Dialog.snd = "voice\RYBL\RYBL029";
			d.Text = DLG_TEXT[102];
			Link.l1 = DLG_TEXT[103];
			Link.l1.go = "node_25";
			Link.l1 = DLG_TEXT[104];
			Link.l1.go = "Exit";
		break;
		
		case "Node_23":
			Dialog.snd = "voice\RYBL\RYBL030";
			d.Text = DLG_TEXT[105];
			Link.l1 = DLG_TEXT[106];
			Link.l1.go = "node_26";
		break;

		case "Node_24":
			Dialog.snd = "voice\RYBL\RYBL031";
			d.Text = DLG_TEXT[107];
			Link.l1 = DLG_TEXT[108];
			Link.l1.go = "node_27";
			Link.l2 = DLG_TEXT[109];
			Link.l2.go = "exit";
		break;

		case "Node_25":
			Dialog.snd = "voice\RYBL\RYBL032";
			d.Text = DLG_TEXT[110];
			Link.l1 = DLG_TEXT[111];
			Link.l1.go = "node_28";
			Link.l2 = DLG_TEXT[112];
			Link.l2.go = "exit";
		break;

		case "Node_26":
			Dialog.snd = "voice\RYBL\RYBL033";
			d.Text = DLG_TEXT[113];
			Link.l1 = DLG_TEXT[114];
			Link.l1.go = "Node_20";
			Link.l2 = DLG_TEXT[115];
			Link.l2.go = "exit";
		break;

		case "Node_27":
			Dialog.snd = "voice\RYBL\RYBL034";
			d.Text = DLG_TEXT[116] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[117]; 
			Link.l1 = DLG_TEXT[118];
			Link.l1.go = "Node_20";
			Link.l2 = DLG_TEXT[119];
			Link.l2.go = "exit";
		break;

		case "Node_28":
			Dialog.snd = "voice\RYBL\RYBL035";
			d.Text = DLG_TEXT[120];
			Link.l1 = DLG_TEXT[121];
			Link.l1.go = "Node_29";
			Link.l2 = DLG_TEXT[122];
			Link.l2.go = "exit";
		break;

		case "Node_29":
			Dialog.snd = "voice\RYBL\RYBL036";
			d.Text = DLG_TEXT[123] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[124];
			Link.l1 = DLG_TEXT[125];
			Link.l1.go = "Node_20";
			Link.l2 = DLG_TEXT[126];
			Link.l2.go = "exit";
		break;

//-------------------------------Диалог 4 - если игроку не удалось уломать начальника порта. 

		case "Help_Failed":
			Dialog.snd1 = "voice\RYBL\RYBL037";
			Dialog.snd2 = "voice\RYBL\RYBL038";
			Dialog.snd3 = "voice\RYBL\RYBL039";
			Diag.TempNode = "Common";
			d.Text = RandPhrase(DLG_TEXT[127] + GetMyName(Pchar) + DLG_TEXT[128] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[129], DLG_TEXT[130] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + GetMyName(PChar) + DLG_TEXT[131], DLG_TEXT[132] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[133], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3) + DLG_TEXT[134];
			Link.l1 = DLG_TEXT[135] + GetMyName(NPChar) + DLG_TEXT[136];
			Link.l1.go = "Node_30";
			Link.l2 = DLG_TEXT[137];
			Link.l2.go = "exit";
		break;

		case "Node_30":
			Dialog.snd = "voice\RYBL\RYBL041";
			d.Text = DLG_TEXT[138] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[139];
			Link.l1 = DLG_TEXT[140] + GetMyName(NPChar) + DLG_TEXT[141];
			Link.l1.go = "Node_18";
			if(NPChar.quest.dialog == "0") {
			Link.l2 = DLG_TEXT[142];
			Link.l2.go = "node_19";
			NPChar.quest.dialog == "1";
			}
			else 
			{
			Link.l2 = DLG_TEXT[143];
			Link.l2.go = "node_20";
			}
		break;

//-------------------------------Диалог 4 - игроку удалось уговорить начальника порта . 

		case "Help_succesful":
			Dialog.snd = "voice\RYBL\RYBL042";
			Diag.TempNode = "Help_succesful";
			d.Text = DLG_TEXT[144];
			Link.l1 = DLG_TEXT[145];
			Link.l1.go = "Help_succesful_1";
			Link.l2 = DLG_TEXT[146];
			Link.l2.go = "exit";
		break;

		case "Help_succesful_1":
			Dialog.snd = "voice\RYBL\RYBL043";
			Diag.TempNode = "common";
			d.Text = DLG_TEXT[147] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[148];
			Link.l1 = DLG_TEXT[149];
			Link.l1.go = "Help_succesful_2";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 450);
				AddPartyExpChar(pchar, "Sneak", 5);
			}
			else { AddPartyExp(pchar, 450); }
		break;

		case "Help_succesful_2":
			Dialog.snd = "voice\RYBL\RYBL044";
			d.Text = DLG_TEXT[150];
			Link.l1 = DLG_TEXT[151];
			Link.l1.go = "Help_succesful_3";
			Link.l2 = DLG_TEXT[152] + GetMyName(NPChar) + DLG_TEXT[153];
			Link.l2.go = "exit";
		break;

		case "Help_succesful_3":
			Dialog.snd = "voice\RYBL\RYBL045";
			d.Text = DLG_TEXT[154] + GetMyName(Pchar) + DLG_TEXT[155];
			Link.l1 = DLG_TEXT[156] + GetMyName(NPChar) + DLG_TEXT[157];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[158];
			Link.l2.go = "hire";
			Link.l3 = DLG_TEXT[159];
			Link.l3.go = "Node_20";
		break;
		
		case "hire":
			dialog.text = DLG_TEXT[160] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[161];
			link.l1 = DLG_TEXT[162];
			link.l1.go = "hire_2";
		break;
		
		case "hire_2":
			dialog.text = DLG_TEXT[163];
			if (sti(pchar.money) >= 500)
			{
				link.l1 = DLG_TEXT[164];
				link.l1.go = "exit_hire";
			}
			link.l2 = DLG_TEXT[165];
			link.l2.go = "exit";
		break;
		
		case "exit_hire":
			Diag.TempNode = "empty";
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("rys_becomes_officer");
		break;

//-------------------------------Диалог 5 - обычный диалог. 


		case "common":
			Dialog.snd = "voice\RYBL\RYBL046";
			Diag.Tempnode = "common";
			d.Text = TimeGreeting() + DLG_TEXT[166];
			Link.l1 = DLG_TEXT[167] + GetMyName(NPChar) + DLG_TEXT[168];
			Link.l1.go = "node_20";
			link.l2 = DLG_TEXT[169];
			link.l2.go = "hire";
			Link.l3 = DLG_TEXT[170];
			Link.l3.go = "Exit";
		break;
		
		case "empty":
			dialog.text = DLG_TEXT[171];
			link.l1 = DLG_TEXT[172];
			link.l1.go = "exit";
		break;
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
	}
}