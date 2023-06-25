//#include "DIALOGS\wench_dialog.h"

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

	string guardid;	

	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- Диалог первый - первая встреча

		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
		
			guardid = NPChar.id;
			switch(guardid)
			{
				case "devil_guard1":
					//CONQUISTADOR church L = DG13
					PlaySound("VOICE\ENGLISH\Spa_m_a_050.wav");
				break;

				case "devil_guard2":
					//CONQUISTADOR church R = DG14
					PlaySound("VOICE\ENGLISH\Spa_m_a_030.wav");
				break;

				case "devil_guard3":
					//PRIEST L
					PlaySound("VOICE\ENGLISH\Mutineer_Christian.wav");
				break;

				case "devil_guard4":
					//PRIEST R
					PlaySound("VOICE\ENGLISH\pir_capQ.wav");
				break;

				case "devil_guard5":
					//TEMPLAR L
					PlaySound("VOICE\ENGLISH\mystery_monk.wav");
				break;

				case "devil_guard6":
					//TEMPLAR R
					PlaySound("VOICE\ENGLISH\gr_Richards.wav");
				break;

				case "devil_guard7":
					//DEMON gate L
					PlaySound("VOICE\ENGLISH\zombie6.wav");
				break;

				case "devil_guard8":
					//DEMON ironmaiden
					PlaySound("VOICE\ENGLISH\zombie5.wav");
				break;

				case "devil_guard9":
					//DEMON gibbet
					PlaySound("VOICE\ENGLISH\zombie4.wav");
				break;

				case "devil_guard10":
					//MUMMY L
					PlaySound("VOICE\ENGLISH\Thug.wav");
				break;

				case "devil_guard11":
					//MUMMY R
					PlaySound("VOICE\ENGLISH\zombie3.wav");
				break;

				case "devil_guard12":
					//DEMON gate R
					PlaySound("VOICE\ENGLISH\zombie2.wav");
				break;

				case "devil_guard13":
					//CONQUISTADOR wood door R = DG1
					PlaySound("VOICE\ENGLISH\Spa_m_a_050.wav");
				break;

				case "devil_guard14":
					//CONQUISTADOR wood door L = DG2
					PlaySound("VOICE\ENGLISH\Spa_m_a_030.wav");
				break;
			}
		
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			Diag.TempNode = "First Time";
		break;

		case "password":
			guardid = NPChar.id;
			switch(guardid)
			{
				case "devil_guard1":
					//CONQUISTADOR church L = DG13
					PlaySound("VOICE\ENGLISH\Spa_m_a_050.wav");
				break;

				case "devil_guard2":
					//CONQUISTADOR church R = DG14
					PlaySound("VOICE\ENGLISH\Spa_m_a_030.wav");
				break;

				case "devil_guard3":
					//PRIEST L
					PlaySound("VOICE\ENGLISH\Mutineer_Christian.wav");
				break;

				case "devil_guard4":
					//PRIEST R
					PlaySound("VOICE\ENGLISH\pir_capQ.wav");
				break;

				case "devil_guard5":
					//TEMPLAR L
					PlaySound("VOICE\ENGLISH\mystery_monk.wav");
				break;

				case "devil_guard6":
					//TEMPLAR R
					PlaySound("VOICE\ENGLISH\gr_Richards.wav");
				break;

				case "devil_guard7":
					//DEMON gate L
					PlaySound("VOICE\ENGLISH\zombie6.wav");
				break;

				case "devil_guard8":
					//DEMON ironmaiden
					PlaySound("VOICE\ENGLISH\zombie5.wav");
				break;

				case "devil_guard9":
					//DEMON gibbet
					PlaySound("VOICE\ENGLISH\zombie4.wav");
				break;

				case "devil_guard10":
					//MUMMY L
					PlaySound("VOICE\ENGLISH\Thug.wav");
				break;

				case "devil_guard11":
					//MUMMY R
					PlaySound("VOICE\ENGLISH\zombie3.wav");
				break;

				case "devil_guard12":
					//DEMON gate R
					PlaySound("VOICE\ENGLISH\zombie2.wav");
				break;

				case "devil_guard13":
					//CONQUISTADOR wood door R = DG1
					PlaySound("VOICE\ENGLISH\Spa_m_a_050.wav");
				break;

				case "devil_guard14":
					//CONQUISTADOR wood door L = DG2
					PlaySound("VOICE\ENGLISH\Spa_m_a_030.wav");
				break;
			}

			dialog.text = DLG_TEXT[2];

			link.l1 = DLG_TEXT[7];
			link.l1.go = "Andrealphus"; 
			link.l2 = DLG_TEXT[8];
			link.l2.go = "Asmodeus";
			link.l3 = DLG_TEXT[9];
			link.l3.go = "Azazel"; 
			link.l4 = DLG_TEXT[10];
			link.l4.go = "Baphomet";
			link.l5 = DLG_TEXT[11];
			link.l5.go = "Beelzebub"; 
			link.l6 = DLG_TEXT[12];
			link.l6.go = "Behemoth";
			link.l7 = DLG_TEXT[13];
			link.l7.go = "Beleth"; 
			link.l8 = DLG_TEXT[14];
			link.l8.go = "Belphegor";
			link.l9 = DLG_TEXT[15];
			link.l9.go = "Demogorgon"; 
			link.l10 = DLG_TEXT[16];
			link.l10.go = "Ghoul";
			link.l11 = DLG_TEXT[17];
			link.l11.go = "Incubus"; 
			link.l12 = DLG_TEXT[18];
			link.l12.go = "Jinn";
			link.l13 = DLG_TEXT[19];
			link.l13.go = "Kali"; 
			link.l14 = DLG_TEXT[20];
			link.l14.go = "Krampus";
			link.l15 = DLG_TEXT[21];
			link.l15.go = "Legion"; 
			link.l16 = DLG_TEXT[22];
			link.l16.go = "Lempo";
			link.l17 = DLG_TEXT[23];
			link.l17.go = "Leviathan"; 
			link.l18 = DLG_TEXT[24];
			link.l18.go = "Lilith";
			link.l19 = DLG_TEXT[25];
			link.l19.go = "Lucifer"; 
			link.l20 = DLG_TEXT[26];
			link.l20.go = "Mammon";
			link.l21 = DLG_TEXT[27];
			link.l21.go = "Mephistophele"; 
			link.l22 = DLG_TEXT[28];
			link.l22.go = "Moloch";
			link.l23 = DLG_TEXT[29];
			link.l23.go = "Orobas"; 
			link.l24 = DLG_TEXT[30];
			link.l24.go = "Ronove";
			link.l25 = DLG_TEXT[31];
			link.l25.go = "Satan"; 
			link.l26 = DLG_TEXT[32];
			link.l26.go = "Succubus";
			link.l27 = DLG_TEXT[33];
			link.l27.go = "Tuchulcha"; 
			link.l28 = DLG_TEXT[34];
			link.l28.go = "Vassago";
		break;

		case "Andrealphus":
			if(NPChar.id == "devil_guard10" || NPChar.id == "devil_guard11")
			{
				PlaySound("AMBIENT\CRYPT\bell.wav");
				Pchar.hell_cave = "open";
				dialog.text = DLG_TEXT[3];
				link.l1 = DLG_TEXT[4];
				link.l1.go = "exit";				//yes, no more dialog
				AddDialogExitQuest("burning_cave_start2");
			}
			else
			{
				PlaySound("AMBIENT\CRYPT\daemon1.wav");
				PlaySound("AMBIENT\CRYPT\daemon1.wav");	
				dialog.text = DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				link.l1.go = "password";
			}
		break;

		case "Asmodeus":
			if(NPChar.id == "devil_guard13" || NPChar.id == "devil_guard14")
			{
				PlaySound("AMBIENT\CRYPT\bell.wav");
				Pchar.hell_gate1 = "password";
				dialog.text = DLG_TEXT[3];
				link.l1 = DLG_TEXT[4];
				link.l1.go = "bribing";	
			}
			else
			{
				PlaySound("AMBIENT\CRYPT\daemon1.wav");	
				PlaySound("AMBIENT\CRYPT\daemon1.wav");			
				dialog.text = DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				link.l1.go = "password";
			}
		break;

		case "Azazel":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Baphomet":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");		
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Beelzebub":
			if(NPChar.id == "devil_guard3" || NPChar.id == "devil_guard4")
			{
				PlaySound("AMBIENT\CRYPT\bell.wav");
				Pchar.hell_gate4 = "password";
				dialog.text = DLG_TEXT[3];
				link.l1 = DLG_TEXT[4];
				link.l1.go = "bribing";
				AddDialogExitQuest("hell_gate5_hole1");		//starts everything
			}
			else
			{
				PlaySound("AMBIENT\CRYPT\daemon1.wav");	
				PlaySound("AMBIENT\CRYPT\daemon1.wav");			
				dialog.text = DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				link.l1.go = "password";
			}
		break;

		case "Behemoth":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Beleth":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Belphegor":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Demogorgon":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Ghoul":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Incubus":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Jinn":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Kali":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Krampus":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Legion":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Lempo":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Leviathan":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Lilith":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Lucifer":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Mammon":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Mephistophele":
			if(NPChar.id == "devil_guard7" || NPChar.id == "devil_guard12")
			{
				PlaySound("AMBIENT\CRYPT\bell.wav");
				Pchar.hell_gate5 = "password";
				dialog.text = DLG_TEXT[3];
				link.l1 = DLG_TEXT[4];
				link.l1.go = "bribing";	
			}
			else
			{
				PlaySound("AMBIENT\CRYPT\daemon1.wav");
				PlaySound("AMBIENT\CRYPT\daemon1.wav");
				dialog.text = DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				link.l1.go = "password";
			}
		break;

		case "Moloch":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Orobas":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Ronove":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Satan":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Succubus":
			if(NPChar.id == "devil_guard1" || NPChar.id == "devil_guard2")
			{
				PlaySound("AMBIENT\CRYPT\bell.wav");
				Pchar.hell_gate2 = "password";
				dialog.text = DLG_TEXT[3];
				link.l1 = DLG_TEXT[4];
				link.l1.go = "bribing";
				AddDialogExitQuest("burning_cave_start4");	
			}
			else
			{
				PlaySound("AMBIENT\CRYPT\daemon1.wav");
				PlaySound("AMBIENT\CRYPT\daemon1.wav");
				dialog.text = DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				link.l1.go = "password";
			}
		break;

		case "Tuchulcha":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "password";
		break;

		case "Vassago":
			if(NPChar.id == "devil_guard5" || NPChar.id == "devil_guard6")
			{
				PlaySound("AMBIENT\CRYPT\bell.wav");
				Pchar.hell_gate3 = "outside";
				dialog.text = DLG_TEXT[3];
				link.l1 = DLG_TEXT[4];
				link.l1.go = "bribing";
	//			link.l1.go = "exit";				//yes, no more dialog
	//			AddDialogExitQuest("burning_cave_start3");	
			}
			else
			{
				PlaySound("AMBIENT\CRYPT\daemon1.wav");
				PlaySound("AMBIENT\CRYPT\daemon1.wav");
				dialog.text = DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				link.l1.go = "password";
			}
		break;
	//--------------------------------------------------------------------------------------------------
		case "bribing":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];

			if(NPChar.id == "devil_guard5" || NPChar.id == "devil_guard6")
			{
				PlaySound("VOICE\ENGLISH\defoe_psst.wav");
				link.l1.go = "medicines";
			}
			if(NPChar.id == "devil_guard13" || NPChar.id == "devil_guard14")
			{
				PlaySound("VOICE\ENGLISH\Spa_m_a_033.wav");
				link.l1.go = "inca_1";
			}
			if(NPChar.id == "devil_guard1" || NPChar.id == "devil_guard2")
			{
				PlaySound("VOICE\ENGLISH\Spa_m_a_033.wav");
				link.l1.go = "inca_2";
			}
			if(NPChar.id == "devil_guard3" || NPChar.id == "devil_guard4")
			{
				PlaySound("VOICE\ENGLISH\Eng_m_a_010.wav");
				link.l1.go = "black_magic";
			}
			if(NPChar.id == "devil_guard7" || NPChar.id == "devil_guard12")
			{
				PlaySound("VOICE\ENGLISH\Thug.wav");
				link.l1.go = "contracts";
			}
		break;

		case "medicines":
			PlaySound("VOICE\ENGLISH\Eden_so.wav");
			dialog.text = DLG_TEXT[46];

			if(CheckCharacterItem(Pchar,"potion1") || CheckCharacterItem(Pchar,"potion2") || CheckCharacterItem(Pchar,"potion3") || CheckCharacterItem(Pchar,"potion4")
			|| CheckCharacterItem(Pchar,"medical1") || CheckCharacterItem(Pchar,"medical2") || CheckCharacterItem(Pchar,"potionrum") || CheckCharacterItem(Pchar,"potionwine")
			|| CheckCharacterItem(Pchar,"potionwine2") || CheckCharacterItem(Pchar,"tobacco") || CheckCharacterItem(Pchar,"sewing_kit") || CheckCharacterItem(Pchar,"cognac"))
			{
				link.l1 = DLG_TEXT[39];
				link.l1.go = "exit";
				AddDialogExitQuest("burning_cave_start3");
			}
			else
			{
				link.l1 = DLG_TEXT[47];
				link.l1.go = "medicines_A";
			}
		break;
	
		case "medicines_A":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "exit";
			AddDialogExitQuest("burning_cave_start3");
		break;

		case "inca_1":
			PlaySound("VOICE\ENGLISH\Spa_m_a_040_short.wav");
			dialog.text = DLG_TEXT[37];

			if(CheckCharacterItem(Pchar,"indian1") && CheckCharacterItem(Pchar,"indian10"))
			{
				link.l1 = DLG_TEXT[39];
				link.l1.go = "exit";
				AddDialogExitQuest("gift_inca_1");
			}
			else
			{
				link.l1 = DLG_TEXT[38];
				link.l1.go = "exit";
				Pchar.hell_gate1 = "search_gift";
			}
		break;

		case "inca_2":
			PlaySound("VOICE\ENGLISH\Spa_m_a_040_short.wav");
			dialog.text = DLG_TEXT[37];

			if(CheckCharacterItem(Pchar,"icollection") && CheckCharacterItem(Pchar,"idol"))
			{
				link.l1 = DLG_TEXT[39];
				link.l1.go = "exit";
				AddDialogExitQuest("gift_inca_2");
			}
			else
			{
				link.l1 = DLG_TEXT[38];
				link.l1.go = "exit";
				Pchar.hell_gate2 = "search_gift";
			}
		break;

		case "black_magic":
			PlaySound("VOICE\ENGLISH\Eng_m_a_011.wav");
			dialog.text = DLG_TEXT[40];
	
			if(CheckCharacterItem(Pchar,"animists_amulet") && CheckCharacterItem(Pchar,"book62"))
			{
				link.l1 = DLG_TEXT[39];
				link.l1.go = "exit";
				AddDialogExitQuest("gift_black_magic");
			}
			else
			{
				link.l1 = DLG_TEXT[38];
				link.l1.go = "exit";
				Pchar.hell_gate4 = "search_gift";
			}
		break;

		case "contracts":
			dialog.text = DLG_TEXT[41];
	
			if(CheckCharacterItem(Pchar,"contract1") && CheckCharacterItem(Pchar,"contract2") && CheckCharacterItem(Pchar,"contract3"))
			{
				PlaySound("INTERFACE\paper.wav");
				TakeItemFromCharacter(Pchar, "contract1"); TakeItemFromCharacter(Pchar, "contract2"); TakeItemFromCharacter(Pchar, "contract3");
				link.l1 = DLG_TEXT[39];
				link.l1.go = "advice";
			}
			else
			{
				PlaySound("VOICE\ENGLISH\zombie_die.wav");
				link.l1 = DLG_TEXT[38];
				link.l1.go = "exit";
				Pchar.hell_gate5 = "search_gift";
				AddDialogExitQuest("bc_ladder_enabled_again");
			}
		break;

		case "advice":
			PlaySound("VOICE\ENGLISH\zombie_die.wav");
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "advice1";
		break;

		case "advice1":
			if(NPChar.id == "devil_guard7") PlaySound("VOICE\ENGLISH\zombie6.wav");
			if(NPChar.id == "devil_guard12") PlaySound("VOICE\ENGLISH\zombie2.wav");
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "exit";
			AddDialogExitQuest("gift_contracts1");
		break;

		case "exit":
			LAi_SetPlayerType(Pchar);
			Diag.TempNode = "First Time";
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			LAi_SetStayType(NPChar);
			DialogExit();
		break;
	}
}