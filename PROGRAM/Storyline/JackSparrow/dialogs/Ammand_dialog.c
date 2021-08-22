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

	switch(Dialog.CurrentNode)
	{
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			//Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			//Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			//Dialog.snd = "voice\TOOR\TOOR001";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (GetAttribute(pchar, "church_help") != "met_Ammand")
			{
				if (IsInServiceOf(PIRATE))
				{
					dialog.text = DLG_TEXT[2];
					if (GetAttribute(PChar, "Jack") == "Pirate_lord")
					{
						link.l1 = DLG_TEXT[4];
						link.l1.go = "plan";
					}
					else
					{
						link.l1 = DLG_TEXT[3];
						link.l1.go = "plan";
					}
				}
				else
				{
					dialog.text = DLG_TEXT[20];
					link.l1 = DLG_TEXT[21];
					link.l1.go = "Exit_reset";
				}
			}
			break;

		case "plan":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "plan2";
		break;

		case "plan2":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "plan3";
		break;

		case "plan3":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
			AddDialogExitQuest("Waiting_(Read_questbook)");
			pchar.church_help = "met_Ammand";

			CloseQuestHeader("Church_Help");
			DeleteQuestHeader("Church_Help");
			SetQuestHeader("Ammand");
			AddQuestRecord("Ammand",1);
			AddQuestRecord("Ammand",2);
			AddQuestRecord("Ammand", 15);
		break;

		case "Outside_Church":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "Outside_Church2";
		break;

		case "Outside_Church2":
			AddQuestRecord("Pirate Lord", 6);
			GiveModel2Player("Animists2", true);
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "exit";
			AddDialogExitQuest("Ammand_being_sneaky");
		break;

		case "On_Jetty":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "On_Jetty1";
			
		break;

		case "On_Jetty1":
			dialog.text = DLG_TEXT[17];
			if(GetAttribute(pchar, "Church_help") != "blackmail")
			{
				link.l1 = DLG_TEXT[18];
				link.l1.go = "exit";
			}
			else
			{
				link.l1 = DLG_TEXT[19];
				link.l1.go = "exit";
			}
			AddDialogExitQuest("Hit_Ammand_and_run");
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "Exit_reset":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			LAi_SetCitizenType(NPChar);
		break;
	}
}
