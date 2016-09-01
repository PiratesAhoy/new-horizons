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

			Dialog.mood = "normal";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

//			if (PChar.quest.Muerte == "search")
			if(checkquestattribute("Muerte", "search"))			
			{
				dialog.snd = "Voice\CLLA\CLLA004";
				dialog.text = DLG_TEXT[26];
				link.l1 = DLG_TEXT[2];
				link.l1.go = "begin_1";				
				PlaySound("trep\PEOPLE\snore.wav");
			}
			if(checkquestattribute("Jacks_early_days", "Get_ready_for_Guadeloupe"))
			{
				dialog.snd = "Voice\CLLA\CLLA004";
				dialog.text = DLG_TEXT[33];
				link.l1 = DLG_TEXT[35];
				link.l1.go = "exitGibbs";
			}			
		break;

		case "begin_1":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "begin_2";
		break;

		case "begin_2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = Pchar.name + DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "begin_3";
		break;

		case "begin_3":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[7];
			link.l1.go = "exit";
			LAi_SetStayType(characterFromID("Will Turner"));
			AddDialogExitQuest("Goto Tortuga tavern");
		break;

		case "begin_4":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "begin_5";
		break;

		case "begin_5":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "begin_6";
		break;

		case "begin_6":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = Pchar.name + DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "begin_7";
		break;

		case "begin_7":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "begin_8";
		break;

		case "begin_8":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "begin_8A";
		break;
// TALISMAN added --->

		case "begin_8A":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "begin_9";
		break;

//TALISMAN <-----		
		
		case "begin_9":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "begin_10";
		break;

		case "begin_10":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			AddDialogExitQuest("meetthecrew");
		break;

		case "begin_11":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
			AddDialogExitQuest("voirannamaria");
		break;

		case "begin_12":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			AddDialogExitQuest("directionislademuerta");
		break;

		case "begin_13":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[27] + Pchar.name + " !";
			link.l1 = DLG_TEXT[28];
			link.l1.go = "begin_14";
		break;

		case "begin_14":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "begin_15";
		break;

		case "begin_15":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "exit";
			AddDialogExitQuest("findecotbp");
		break;

		case "Playing_Vanguard":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "exit";
			AddDialogExitQuest("Gibbs_to_Tavern");
		break;

		case "Stay_or_Accompany":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "Exit_Stay";
			link.l2 = DLG_TEXT[38];
			link.l2.go = "ExitAccompany";			
		break;

		case "Exit_Stay":
			AddDialogExitQuest("Goodbye_Gibbs_and_Willemoes");
			RemoveOfficersIndex(pchar, GetCharacterIndex("Mr. Gibbs"));
			RemoveOfficersIndex(pchar, GetCharacterIndex("Peter Willemoes"));			
			RemoveCharacterCompanion(Pchar, &Characters[GetCharacterIndex("Peter Willemoes")]);
			SetCharacterRemovable(characterFromID("Peter Willemoes"), true);
			RemovePassenger(Pchar, characterFromID("Peter Willemoes"));				
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "ExitAccompany":
			AddDialogExitQuest("Continue_with_Gibbs_and_Willemoes");		
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "ExitGibbs":
			AddDialogExitQuest("Gibbs_to_sort_ship");		
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
