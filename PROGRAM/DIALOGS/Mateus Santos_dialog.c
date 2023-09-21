//#include "DIALOGS\Mateus Santos_dialog.h"
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
			Dialog.snd = "voice\MASA\MASA001";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";

			if(PChar.quest.Hitman == "hit_ambroz")
			{
				PlayStereoSound("INTERFACE\took_item.flac");
				AddMoneyToCharacter(PChar, 3000);
				Dialog.snd = "voice\MASA\MASA002";
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "hit1";
				link.l2 = DLG_TEXT[4];
				link.l2.go = "refused1";
			}

			if(PChar.quest.Hitman == "hit_geffrey")
			{
				PlayStereoSound("INTERFACE\took_item.flac");
				AddMoneyToCharacter(PChar, 4500);
				Dialog.snd = "voice\MASA\MASA003";
				dialog.text = DLG_TEXT[5];
				link.l1 = DLG_TEXT[6]+ Characters[GetCharacterIndex(DLG_TEXT[7])].lastname +DLG_TEXT[8];
				link.l1.go = "hit2";
				link.l2 = DLG_TEXT[9];
				link.l2.go = "refused1";
			}

			if(PChar.quest.Hitman == "hit_pepin")
			{
				PlayStereoSound("INTERFACE\took_item.flac");
				AddMoneyToCharacter(PChar, 7000);
				Dialog.snd = "voice\MASA\MASA004";
				dialog.text = DLG_TEXT[10]+ Characters[GetCharacterIndex(DLG_TEXT[11])].lastname +DLG_TEXT[12];
				link.l1 = DLG_TEXT[13];
				link.l1.go = "hit3";
				link.l2 = DLG_TEXT[14];
				link.l2.go = "refused1";
			}

			if(PChar.quest.Hitman == "hit_amerigo")
			{
				PlayStereoSound("INTERFACE\took_item.flac");
				AddMoneyToCharacter(PChar, 10000);
				Dialog.snd = "voice\MASA\MASA005";
				dialog.text = DLG_TEXT[15]+ Characters[GetCharacterIndex(DLG_TEXT[16])].name +DLG_TEXT[17];
				link.l1 = DLG_TEXT[18];
				link.l1.go = "hit4";
				link.l2 = DLG_TEXT[19];
				link.l2.go = "refused1";
			}

			if(PChar.quest.Hitman == "hit_vito")
			{
				Dialog.snd = "voice\MASA\MASA006";
				dialog.text = DLG_TEXT[20];
				link.l1 = DLG_TEXT[21]+ Characters[GetCharacterIndex(DLG_TEXT[22])].lastname +DLG_TEXT[23];
				link.l1.go = "Exit_die";

			}

			if(PChar.quest.Hitman == "mark_mateus")
			{
				Dialog.snd = "voice\MASA\MASA007";
				dialog.text = DLG_TEXT[24];
				link.l1 = DLG_TEXT[25]+ Characters[GetCharacterIndex(DLG_TEXT[26])].lastname +DLG_TEXT[27];
				link.l1.go = "showdown";

			}
		break;

		case "start":
			Dialog.snd = "voice\MASA\MASA008";
			dialog.text = DLG_TEXT[28] + PChar.lastname + DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "start1";

		break;

		case "start1":
			Dialog.snd = "voice\MASA\MASA009";
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "start2";

		break;

		case "start2":
			Dialog.snd = "voice\MASA\MASA010";
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "start3";
			link.l2 = DLG_TEXT[35];
			link.l2.go = "die";
		break;

		case "start3":
			Dialog.snd = "voice\MASA\MASA011";
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			dialog.text = DLG_TEXT[36]+ Characters[GetCharacterIndex(DLG_TEXT[37])].name +DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "start4";
			link.l2 = DLG_TEXT[40];
			link.l2.go = "die";

		break;

		case "start4":
			Dialog.snd = "voice\MASA\MASA012";
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "start5";
			link.l2 = DLG_TEXT[43];
			link.l2.go = "refused";

		break;

		case "start5":
			Dialog.snd = "voice\MASA\MASA013";
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "start6";

		break;

		case "start6":
			Dialog.snd = "voice\MASA\MASA014";
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "start7";

		break;

		case "start7":
			Dialog.snd = "voice\MASA\MASA015";
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "start8";

		break;

		case "start8":
			Dialog.snd = "voice\MASA\MASA016";
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "start9";
			link.l2 = DLG_TEXT[52];
			link.l2.go = "refused";

		break;

		case "start9":
			Dialog.snd = "voice\MASA\MASA017";
			dialog.text = DLG_TEXT[53]+ Characters[GetCharacterIndex(DLG_TEXT[54])].name +DLG_TEXT[55]+ Characters[GetCharacterIndex(DLG_TEXT[56])].lastname +DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "start10";
			link.l2 = DLG_TEXT[59];
			link.l2.go = "refused";

		break;

		case "start10":
			Dialog.snd = "voice\MASA\MASA018";
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "Exit_start";

		break;

		case "refused":
			Dialog.snd = "voice\MASA\MASA019";
			dialog.text = DLG_TEXT[62]+ Characters[GetCharacterIndex(DLG_TEXT[63])].name +DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "Exit_refused";

		break;

		case "refused1":
			Dialog.snd = "voice\MASA\MASA020";
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "Exit_refused";

		break;

		case "die":
			Dialog.snd = "voice\MASA\MASA021";
			dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "Exit_die";

		break;

		case "hit1":
			Dialog.snd = "voice\MASA\MASA022";
			dialog.text = DLG_TEXT[70]+ Characters[GetCharacterIndex(DLG_TEXT[71])].name +" "+ Characters[GetCharacterIndex(DLG_TEXT[72])].lastname +DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "Exit_hit1";
			link.l2 = DLG_TEXT[75];
			link.l2.go = "refused1";
		break;

		case "hit2":
			Dialog.snd = "voice\MASA\MASA023";
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "hit2_1";
			link.l2 = DLG_TEXT[78];
			link.l2.go = "refused1";
		break;

		case "hit2_1":
			Dialog.snd = "voice\MASA\MASA024";
			dialog.text = DLG_TEXT[79]+ Characters[GetCharacterIndex(DLG_TEXT[80])].name +" "+ Characters[GetCharacterIndex(DLG_TEXT[81])].lastname +DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "hit2_2";
			link.l2 = DLG_TEXT[84];
			link.l2.go = "refused1";
		break;

		case "hit2_2":
			Dialog.snd = "voice\MASA\MASA025";
			dialog.text = DLG_TEXT[85]+ Characters[GetCharacterIndex(DLG_TEXT[86])].lastname +DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "Exit_hit2";
			link.l2 = DLG_TEXT[89];
			link.l2.go = "refused1";
		break;

		case "hit3":
			Dialog.snd = "voice\MASA\MASA026";
			dialog.text = DLG_TEXT[90];
			link.l1 = DLG_TEXT[91];
			link.l1.go = "hit3_1";
			link.l2 = DLG_TEXT[92];
			link.l2.go = "refused1";
		break;

		case "hit3_1":
			Dialog.snd = "voice\MASA\MASA027";
			dialog.text = DLG_TEXT[93]+ Characters[GetCharacterIndex(DLG_TEXT[94])].name +" "+ Characters[GetCharacterIndex(DLG_TEXT[95])].lastname +DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "hit3_2";
			link.l2 = DLG_TEXT[98];
			link.l2.go = "refused1";
		break;

		case "hit3_2":
			Dialog.snd = "voice\MASA\MASA028";
			dialog.text = DLG_TEXT[99]+ Characters[GetCharacterIndex(DLG_TEXT[100])].lastname +DLG_TEXT[101];
			link.l1 = DLG_TEXT[102];
			link.l1.go = "Exit_hit3";
			link.l2 = DLG_TEXT[103];
			link.l2.go = "refused1";
		break;

		case "hit4":
			Dialog.snd = "voice\MASA\MASA029";
			dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];
			link.l1.go = "hit4_1";
			link.l2 = DLG_TEXT[106];
			link.l2.go = "refused1";
		break;

		case "hit4_1":
			Dialog.snd = "voice\MASA\MASA030";
			dialog.text = DLG_TEXT[107];
			link.l1 = DLG_TEXT[108];
			link.l1.go = "hit4_2";
			link.l2 = DLG_TEXT[109];
			link.l2.go = "refused1";
		break;

		case "hit4_2":
			Dialog.snd = "voice\MASA\MASA031";
			dialog.text = DLG_TEXT[110];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "hit4_3";
			link.l2 = DLG_TEXT[112];
			link.l2.go = "refused1";
		break;

		case "hit4_3":
			Dialog.snd = "voice\MASA\MASA032";
			dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[114];
			link.l1.go = "Exit_hit4";
			link.l2 = DLG_TEXT[115];
			link.l2.go = "refused1";
		break;

		case "showdown":
			Dialog.snd = "voice\MASA\MASA033";
			dialog.text = DLG_TEXT[116];
			link.l1 = DLG_TEXT[117];
			link.l1.go = "Exit_kill";

		break;

		case "Exit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

		break;

		case "Exit_start":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Hit_mark_Ambroz");

		break;

		case "Exit_hit1":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Hit_mark_Geffrey");

		break;

		case "Exit_hit2":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Hit_mark_Pepin");

		break;

		case "Exit_hit3":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Hit_mark_Amerigo");

		break;

		case "Exit_hit4":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Hit_mark_Vito");

		break;

		case "Exit_refused":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Hit_refused_Mateus");

		break;

		case "Exit_die":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Hit_die");

		break;

		case "Exit_kill":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Hit_kill_Mateus");

		break;

	}
}
