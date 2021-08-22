//#include "DIALOGS\Redmond Soldier_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d; 
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;
	
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
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";


			if(NPChar.id == "GB_Pyle") PlaySound("VOICE\ENGLISH\blaze_drunk1.wav");
			if(NPChar.id == "GB_Caroline") PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			if(NPChar.id == "GB_Friday") PlaySound("VOICE\ENGLISH\gr_friday1.wav");
			if(NPChar.id == "GB_Selkirk") PlaySound("VOICE\ENGLISH\Eng_m_c_073.wav");
			if(NPChar.id == "GB_Grandma") PlaySound("VOICE\ENGLISH\grandma_4.wav");
			if(NPChar.id == "GB_Dave") PlaySound("VOICE\ENGLISH\Dave_Edna_2.wav");

			if(NPChar.id == "GB_Hawk") PlaySound("VOICE\ENGLISH\blaze_drunk2.wav");
			if(NPChar.id == "GB_Danielle") PlaySound("VOICE\ENGLISH\Fre_f_a_001.wav");
			if(NPChar.id == "GB_Fawn") PlaySound("VOICE\ENGLISH\Eng_m_a_002.wav");

			if(NPChar.id == "GB_Maturin") PlaySound("VOICE\ENGLISH\Eng_m_a_003.wav");
			if(NPChar.id == "GB_Aubrey") PlaySound("OBJECTS\SHIPCHARGE\gunner_fire.wav");

			if(NPChar.id == "GB_Sparrow") PlaySound("VOICE\ENGLISH\ayay_captain.wav");
			if(NPChar.id == "GB_Elizabeth") PlaySound("VOICE\ENGLISH\estrella.wav");
			if(NPChar.id == "GB_Barbossa") PlaySound("VOICE\ENGLISH\Barbossa01.wav");
			if(NPChar.id == "GB_Turner") PlaySound("VOICE\ENGLISH\windem_drunk.wav");

			if(NPChar.id == "GB_Beatrice") PlaySound("VOICE\ENGLISH\Dut_f_a_001.wav");
			if(NPChar.id == "GB_LaCroix") PlaySound("VOICE\ENGLISH\Fre_m_a_012.wav");

			if(NPChar.id == "GB_Hornblower") PlaySound("VOICE\ENGLISH\Hornblwr02.wav");
			if(NPChar.id == "GB_Kennedy") PlaySound("VOICE\ENGLISH\Archie01.wav");
			if(NPChar.id == "GB_Pellew") PlaySound("VOICE\ENGLISH\Pellew03.wav");
			if(NPChar.id == "GB_Bush") PlaySound("VOICE\ENGLISH\Bush02.wav");

			if(NPChar.id == "GB_Sharpe") PlaySound("VOICE\ENGLISH\Sharpe06.wav");
			if(NPChar.id == "GB_Harper") PlaySound("VOICE\ENGLISH\Eng_m_b_039.wav");
			if(NPChar.id == "GB_Haggman") PlaySound("VOICE\ENGLISH\Eng_m_a_040.wav");
			if(NPChar.id == "GB_Harris") PlaySound("VOICE\ENGLISH\Eng_m_c_043.wav");

			if(NPChar.id == "GB_Lafitte") PlaySound("VOICE\ENGLISH\Fre_m_b_075.wav");

			if(NPChar.id == "GB_Bartolomeu") PlaySound("VOICE\ENGLISH\Por_m_b_040.wav");
			if(NPChar.id == "GB_Emilio") PlaySound("VOICE\ENGLISH\Por_m_a_002.wav");
			if(NPChar.id == "GB_Elting") PlaySound("VOICE\ENGLISH\Dut_m_a_031.wav");


				int iPhrase = rand(9);
			
				switch (iPhrase)
				{
					case 0:
					dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[10];
					link.l1.go = "exit";
					break;
				
					case 1:
					dialog.text = DLG_TEXT[1];
					link.l1 = DLG_TEXT[11];
					link.l1.go = "exit";
					break;
				
					case 2:
					dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[12];
					link.l1.go = "exit";
					break;
				
					case 3:
					dialog.text = DLG_TEXT[3];
					link.l1 = DLG_TEXT[13];
					link.l1.go = "exit";
					break;
				
					case 4:
					dialog.text = DLG_TEXT[4];
					link.l1 = DLG_TEXT[15];
					link.l1.go = "exit";
					break;
				
					case 5:
					dialog.text = DLG_TEXT[5];
					link.l1 = DLG_TEXT[14];
					link.l1.go = "exit";
					break;
				
					case 6:
					dialog.text = DLG_TEXT[6];
					link.l1 = DLG_TEXT[10];
					link.l1.go = "exit";
					break;
				
					case 7:
					dialog.text = DLG_TEXT[7];
					link.l1 = DLG_TEXT[10];
					link.l1.go = "exit";
					break;
				
					case 8:
					dialog.text = DLG_TEXT[8];
					link.l1 = DLG_TEXT[11];
					link.l1.go = "exit";
					break;
				
					case 9:
					dialog.text = DLG_TEXT[9];
					link.l1 = DLG_TEXT[13];
					link.l1.go = "exit";
					break;
				}

			


		break;
	}
}
