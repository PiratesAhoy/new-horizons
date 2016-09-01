//#include "DIALOGS\Henry_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	int RandQuestSum;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	



	trace("Temp Node = " + Diag.TempNode);
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
			Dialog.snd = "dialogs\0\009";

			Diag.TempNode = "Node_15";
			
			dialog.snd1 = "Voice\HENR\HENR001";
			dialog.snd2 = "Voice\HENR\HENR002";
			dialog.snd3 = "Voice\HENR\HENR003";
			d.Text = RandPhrase(DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1], DLG_TEXT[2], DLG_TEXT[3] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[4], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[6];
			Link.l2.go = "Node_2";
			Link.l3 = DLG_TEXT[7];
			Link.l3.go = "Node_4";
		break;

		case "node_2":
			if(makeint(PChar.money)>=1)
			{	
			    PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(pchar, -1);
				dialog.snd = "Voice\HENR\HENR004";
				d.Text = DLG_TEXT[8] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[9];
				Link.l1 = DLG_TEXT[10];
				Link.l1.go = "Node_3";
				Link.l2 = DLG_TEXT[11];
				Link.l2.go = "exit";
			}
			else
			{
				dialog.snd = "Voice\HENR\HENR005";
				d.Text = DLG_TEXT[12] + GetMyName(Pchar) + DLG_TEXT[13];
				link.l1 = DLG_TEXT[14];
				link.l1.go = "First time";
			}
		break;

		case "Node_3":
			dialog.snd = "Voice\HENR\HENR006";
			d.Text = DLG_TEXT[15] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17];
			Link.l1.go = "node_5";
			Link.l2 = DLG_TEXT[18];
			Link.l2.go = "node_6";
			Link.l3 = DLG_TEXT[19];
			Link.l3.go = "exit";
		break;

		case "Node_4":
			if(makeint(PChar.money)>=1)
			{	
			    PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(pchar, -1);
				dialog.snd = "Voice\HENR\HENR007";
				d.Text = DLG_TEXT[20] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[21];
				Link.l1 = DLG_TEXT[22];
				Link.l1.go = "exit";
				Link.l2 = DLG_TEXT[23];
				Link.l2.go = "node_7";
			}
			else
			{
				dialog.snd = "Voice\HENR\HENR008";
				d.Text = DLG_TEXT[24] + GetMyName(Pchar) + DLG_TEXT[25];
				link.l1 = DLG_TEXT[26];
				link.l1.go = "First time";
			}
		break;

		case "Node_5":
			dialog.snd = "Voice\HENR\HENR009";
			d.Text = DLG_TEXT[27] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[28];
			Link.l1 = DLG_TEXT[29];
			Link.l1.go = "node_8";
			Link.l2 = DLG_TEXT[30];
			Link.l2.go = "node_9";
			Link.l3 = DLG_TEXT[31];
			Link.l3.go = "Node_10";
		break;

		case "Node_6":
			dialog.snd = "Voice\HENR\HENR010";
			d.Text = DLG_TEXT[32] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[33];
			Link.l1 = DLG_TEXT[34];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[35];
			Link.l2.go = "node_11";
		break;

		case "node_7":
			dialog.snd = "Voice\HENR\HENR011";
			d.Text = DLG_TEXT[36] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false);
			Link.l1 = DLG_TEXT[37];
			Link.l1.go = "node_5";
			Link.l2 = DLG_TEXT[38];
			Link.l2.go = "node_6";
			Link.l3 = DLG_TEXT[39];
			Link.l3.go = "exit";
		break;

		case "Node_8":
			dialog.snd = "Voice\HENR\HENR012";
			d.Text = DLG_TEXT[40];
			Link.l1 = DLG_TEXT[41];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[42];
			Link.l2.go = "node_9";
			Link.l3 = DLG_TEXT[43];
			Link.l3.go = "node_10";
		break;

		case "Node_9":
			dialog.snd = "Voice\HENR\HENR013";
			d.Text = DLG_TEXT[44] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[45] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[46];
			Link.l1 = DLG_TEXT[47];
			Link.l1.go = "node_8";
			Link.l2 = DLG_TEXT[48];
			Link.l2.go = "node_10";
			Link.l3 = DLG_TEXT[49];
			Link.l3.go = "exit";
		break;

		case "Node_10":
			dialog.snd = "Voice\HENR\HENR014";
			d.Text = DLG_TEXT[50] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[51];
			Link.l1 = DLG_TEXT[52];
			Link.l1.go = "node_9";
			Link.l2 = DLG_TEXT[53];
			Link.l2.go = "node_8";
			Link.l3 = DLG_TEXT[54];
			Link.l3.go = "exit";
		break;

		case "Node_11":
			RandQuestSum = RandSum("Few");
			dialog.snd = "Voice\HENR\HENR015";
			d.Text = RandQuestSum  + DLG_TEXT[55] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[56];
			Link.l1 = DLG_TEXT[57];
			Link.l1.go = "node_12";
			Link.l2 = DLG_TEXT[58];
			Link.l2.go = "exit";
		break;

		case "Node_12":
			if(makeint(PChar.money)>=RandQuestSum)
			{
				Diag.TempNode = "Node_29";
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(pchar, - (RandQuestSum));
				dialog.snd = "Voice\HENR\HENR016";
				d.Text = DLG_TEXT[59] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[60];
				Link.l1 = DLG_TEXT[61];
				Link.l1.go = "node_13";
				Link.l2 = DLG_TEXT[62];
				Link.l2.go = "exit";
			}
			else
			{
				dialog.snd = "Voice\HENR\HENR017";
				d.Text = DLG_TEXT[63] + GetMyName(Pchar) + DLG_TEXT[64];
				link.l1 = DLG_TEXT[65];
				link.l1.go = "node_11";
			}

		break;

		case "Node_13":
			dialog.snd = "Voice\HENR\HENR018";
			d.Text = DLG_TEXT[66] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[67];
			Link.l1 = DLG_TEXT[68];
			Link.l1.go = "node_14";
			Link.l2 = DLG_TEXT[69];
			Link.l2.go = "exit";
		break;

		case "Node_14":
			dialog.snd = "Voice\HENR\HENR019";
			d.Text = DLG_TEXT[70];
			Link.l1 = DLG_TEXT[71];
			Link.l1.go = "exit";
			
		break;

	//Диалог второй - игрок уже встречался с Генри, но не заплатил ему за информацию.
		
		case "Node_15":
			dialog.snd1 = "Voice\HENR\HENR020";
			dialog.snd2 = "Voice\HENR\HENR021";
			dialog.snd3 = "Voice\HENR\HENR022";
			d.Text = RandPhrase(DLG_TEXT[72] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[73], DLG_TEXT[74], GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[75], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[76];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[77];
			Link.l2.go = "Node_16";
			Link.l3 = DLG_TEXT[78];
			Link.l3.go = "Node_18";
		break;

		case "Node_16":
			if(makeint(PChar.money)>=1)
			{
			    PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(pchar, -1);
				dialog.snd = "Voice\HENR\HENR023";
				d.Text = DLG_TEXT[79] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[80];
				Link.l1 = DLG_TEXT[81];
				Link.l1.go = "node_17";
				Link.l2 = DLG_TEXT[82];
				Link.l2.go = "exit";
			}
			else
			{
				dialog.snd = "Voice\HENR\HENR024";
				d.Text = DLG_TEXT[83] + GetMyName(Pchar) + DLG_TEXT[84];
				link.l1 = DLG_TEXT[85];
				link.l1.go = "Node_15";
			}

		break;

		case "Node_17":
			dialog.snd = "Voice\HENR\HENR025";
			d.Text = DLG_TEXT[86] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[87];
			Link.l1 = DLG_TEXT[88];
			Link.l1.go = "node_19";
			Link.l2 = DLG_TEXT[89];
			Link.l2.go = "node_20";
			Link.l3 = DLG_TEXT[90];
			Link.l3.go = "exit";
		break;

		case "Node_18":
			if(makeint(PChar.money) >= 1)
			{
			    PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(pchar, -1);
				dialog.snd = "Voice\HENR\HENR026";
				d.Text = DLG_TEXT[91] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[92];
				Link.l1 = DLG_TEXT[93];
				Link.l1.go = "node_21";
				Link.l2 = DLG_TEXT[94];
				Link.l2.go = "exit";
			}
			else
			{
				dialog.snd = "Voice\HENR\HENR027";
				d.Text = DLG_TEXT[95] + GetMyName(Pchar) + DLG_TEXT[96];
				link.l1 = DLG_TEXT[97];
				link.l1.go = "Node_15";
			}

		break;

		case "Node_19":
			dialog.snd = "Voice\HENR\HENR028";
			d.Text = DLG_TEXT[98] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[99];
			Link.l1 = DLG_TEXT[100];
			Link.l1.go = "node_22";
			Link.l2 = DLG_TEXT[101];
			Link.l2.go = "node_23";
			Link.l3 = DLG_TEXT[102];
			Link.l3.go = "node_24";
		break;

		case "Node_20":
			dialog.snd = "Voice\HENR\HENR029";
			d.Text = DLG_TEXT[103] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[104];
			Link.l1 = DLG_TEXT[105];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[106];
			Link.l2.go = "node_25";
		break;
		
		case "Node_21":
			dialog.snd = "Voice\HENR\HENR030";
			d.Text = DLG_TEXT[107] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false);
			Link.l1 = DLG_TEXT[108];
			Link.l1.go = "node_19";
			Link.l2 = DLG_TEXT[109];
			Link.l2.go = "node_20";
			Link.l3 = DLG_TEXT[110];
			Link.l3.go = "exit";
		break;
	
		case "Node_22":
			dialog.snd = "Voice\HENR\HENR031";
			d.Text = DLG_TEXT[111];
			Link.l1 = DLG_TEXT[112];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[113];
			Link.l2.go = "node_23";
			Link.l3 = DLG_TEXT[114];
			Link.l3.go = "node_24";
		break;
	
		case "Node_23":
			dialog.snd = "Voice\HENR\HENR032";
			d.Text = DLG_TEXT[115] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[116] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[117];
			Link.l1 = DLG_TEXT[118];
			Link.l1.go = "node_22";
			Link.l2 = DLG_TEXT[119];
			Link.l2.go = "node_24";
			Link.l3 = DLG_TEXT[120];
			Link.l3.go = "exit";
		break;
	
		case "Node_24":
			dialog.snd = "Voice\HENR\HENR033";
			d.Text = DLG_TEXT[121] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[122];
			Link.l1 = DLG_TEXT[123];
			Link.l1.go = "node_22";
			Link.l2 = DLG_TEXT[124];
			Link.l2.go = "node_23";
			Link.l3 = DLG_TEXT[125];
			Link.l3.go = "exit";
		break;

		case "Node_25":
			dialog.snd = "Voice\HENR\HENR034";
			RandQuestSum = RandSum("Few");
			d.Text = RandQuestSum  + DLG_TEXT[126] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[127];
			Link.l1 = DLG_TEXT[128];
			Link.l1.go = "node_26";
			Link.l2 = DLG_TEXT[129];
			Link.l2.go = "exit";

		break;

		case "Node_26":
			if(makeint(PChar.money)>=RandQuestSum)
			{
			    PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(pchar, -(RandQuestSum));
				Diag.TempNode = "Node_29";
				dialog.snd = "Voice\HENR\HENR035";
				d.Text = DLG_TEXT[130] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[131];
				Link.l1 = DLG_TEXT[132];
				Link.l1.go = "node_27";
				Link.l2 = DLG_TEXT[133];
				Link.l2.go = "exit";
			}
			else
			{
				dialog.snd = "Voice\HENR\HENR036";
				d.Text = DLG_TEXT[134] + GetMyName(Pchar) + DLG_TEXT[135];
				link.l1 = DLG_TEXT[136];
				link.l1.go = "node_25";
			}
		break;

		case "Node_27":
			dialog.snd = "Voice\HENR\HENR037";
			d.Text = DLG_TEXT[137] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[138];
			Link.l1 = DLG_TEXT[139];
			Link.l1.go = "node_28";
			Link.l2 = DLG_TEXT[140];
			Link.l2.go = "exit";
		break;

		case "Node_28":
			dialog.snd = "Voice\HENR\HENR038";
			d.Text = DLG_TEXT[141];
			Link.l1 = DLG_TEXT[142];
			Link.l1.go = "exit";
		break;

		//Диалог 3: Игрок заплатил Генри сто золотых за информацию о губернаторе.

		case "Node_29":
			dialog.snd1 = "Voice\HENR\HENR039";
			dialog.snd2 = "Voice\HENR\HENR040";
			dialog.snd3 = "Voice\HENR\HENR041";
			d.Text = RandPhrase(DLG_TEXT[143] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[144], DLG_TEXT[145], DLG_TEXT[146] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[147], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[148];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[149];
			Link.l2.go = "Node_30";
		break;

		case "node_30":
			if(makeint(PChar.money)>=1)
			{
			    PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(pchar, -1);
				dialog.snd = "Voice\HENR\HENR042";
				d.Text = DLG_TEXT[150] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[151];
				Link.l1 = DLG_TEXT[152];
				Link.l1.go = "Node_31";
				Link.l2 = DLG_TEXT[153];
				Link.l2.go = "Exit";
			}
			else
			{
				dialog.snd = "Voice\HENR\HENR043";
				d.Text = DLG_TEXT[154] + GetMyName(Pchar) + DLG_TEXT[155];
				link.l1 = DLG_TEXT[156];
				link.l1.go = "Node_29";
			}

		break;

		case "Node_31":
			dialog.snd = "Voice\HENR\HENR044";
			d.Text = DLG_TEXT[157] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[158];
			Link.l1 = DLG_TEXT[159];
			Link.l1.go = "node_33";
			Link.l2 = DLG_TEXT[160];
			Link.l2.go = "node_32";
			Link.l3 = DLG_TEXT[161];
			Link.l3.go = "Exit";
		break;

		case "Node_32":
			dialog.snd = "Voice\HENR\HENR045";
			d.Text = DLG_TEXT[162] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[163];
			Link.l1 = DLG_TEXT[164];
			Link.l1.go = "Node_38";
			Link.l2 = DLG_TEXT[165];
			Link.l2.go = "node_34";
		break;

		case "Node_33":
			dialog.snd = "Voice\HENR\HENR046";
			d.Text = DLG_TEXT[166] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[167];
			Link.l1 = DLG_TEXT[168];
			Link.l1.go = "node_35";
			Link.l2 = DLG_TEXT[169];
			Link.l2.go = "node_36";
			Link.l3 = DLG_TEXT[170];
			Link.l3.go = "Node_37";
		break;

		case "Node_34":
			dialog.snd = "Voice\HENR\HENR047";
			d.Text = DLG_TEXT[171] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[172];
			Link.l1 = DLG_TEXT[173];
			Link.l1.go = "node_33";
			Link.l2 = DLG_TEXT[174];
			Link.l2.go = "exit";
		break;

		case "Node_35":
			dialog.snd = "Voice\HENR\HENR048";
			d.Text = DLG_TEXT[175];
			Link.l1 = DLG_TEXT[176];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[177];
			Link.l2.go = "node_36";
			Link.l3 = DLG_TEXT[178];
			Link.l3.go = "node_37";
		break;

		case "Node_36":
			dialog.snd = "Voice\HENR\HENR049";
			d.Text = DLG_TEXT[179] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[180] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[181];
			Link.l1 = DLG_TEXT[182];
			Link.l1.go = "node_35";
			Link.l2 = DLG_TEXT[183];
			Link.l2.go = "node_37";
			Link.l3 = DLG_TEXT[184];
			Link.l3.go = "Exit";
		break;

		case "Node_37":
			dialog.snd = "Voice\HENR\HENR050";
			d.Text = DLG_TEXT[185] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[186];
			Link.l1 = DLG_TEXT[187];
			Link.l1.go = "node_36";
			Link.l2 = DLG_TEXT[188];
			Link.l2.go = "node_35";
			Link.l3 = DLG_TEXT[189];
			Link.l3.go = "Exit";
		break;

		case "Node_38":
			dialog.snd = "Voice\HENR\HENR051";
			d.Text = DLG_TEXT[190];
			Link.l1 = DLG_TEXT[191];
			Link.l1.go = "node_39";
			Link.l2 = DLG_TEXT[192];
			Link.l2.go = "Exit";
		break;

		case "Node_39":
			dialog.snd = "Voice\HENR\HENR052";
			d.Text = DLG_TEXT[193];
			Link.l1 = DLG_TEXT[194];
			Link.l1.go = "exit";
		break;

		//-------------------------------- Диалог 4 (Игрок завершил квест с нищим)  -------------



		case "exit":
			trace("Dialog Temp Node = " + Diag.TempNode);
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	}
}