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
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\THDI\THDI001";

			Dialog.mood = "angry";

			dialog.snd = "Voice\CLLA\CLLA001";
			
			if (CheckAttribute(PChar,"quest.poker.day"))
			{
				if (CheckAttribute(PChar,"quest.Day_Expired"))
				{
					PlaySound("VOICE\ENGLISH\gr_Teach1.wav");
					dialog.text = DLG_TEXT[8];
					link.l1 = DLG_TEXT[9];
					link.l1.go = "Exit";
				}
				else
				{
					if (CheckAttribute(PChar,"quest.poker_next_tournament"))	
					{
						PlaySound("VOICE\ENGLISH\gr_Teach2.wav");
						dialog.text = DLG_TEXT[6];
						link.l1 = DLG_TEXT[7];
						link.l1.go = "Exit";
					}
					else
					{	
						if (CheckAttribute(PChar,"quest.poker.lockout"))
						{
						PlaySound("VOICE\ENGLISH\gr_Teach6.wav");
						AddDialogExitQuest("Competition_Lockout2");
						dialog.text = DLG_TEXT[15];
						link.l1 = DLG_TEXT[16];
						link.l1.go = "Exit";	
						}
						else
						{
							PlaySound("VOICE\ENGLISH\gr_Teach5.wav");
							dialog.text = DLG_TEXT[14];
							link.l1 = DLG_TEXT[7];
							link.l1.go = "Exit";
						}
					}
				}
			}	
			else
			{		
				if (CharPlayerType == PLAYER_TYPE_GAMBLER) 
				{
					if ((CheckCharacterItem(PChar,"poker_invite1")) || (CheckCharacterItem(PChar,"poker_invite2")))
					{	
					PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
						dialog.text = DLG_TEXT[10];
						if (PChar.money < 20000)
						{
							link.l1 = DLG_TEXT[12];
							link.l1.go = "Scram";
						}
						else
						{
							LAi_SetActorType(Pchar);
							Lai_ActorRunToLocator(Pchar, "goto", "desk", "", 2);// place at desk locator for fake reload
							link.l1 = DLG_TEXT[11];//start dialogue with twin
							link.l1.go = "Exit";
							AddDialogExitQuest("Competition_Day_One_Start");
							Dialog.CurrentNode = "First time";
						}	
					}
					else			
					{
						PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
						dialog.text = DLG_TEXT[4];
						link.l1 = DLG_TEXT[5];
						link.l1.go = "Exit";
					}
					
				}	
				else
				{	
					PlaySound("VOICE\ENGLISH\gr_Teach14.wav");
					dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "More info";
				}
			}
		break;
	
		case "More info":
			PlaySound("VOICE\ENGLISH\gr_Teach7.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit";
		break;	
		
		case "Scram":
			PlaySound("VOICE\ENGLISH\gr_Teach12.wav");
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit";
			NextDiag.TempNode = "First time";
		break;
		
			
		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			
		break;
	}
}