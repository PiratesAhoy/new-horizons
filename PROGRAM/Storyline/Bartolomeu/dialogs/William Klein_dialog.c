//#include "DIALOGS\William Klein_dialog.h"

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
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";	
			
		break;
        
                case "begin_1":
  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "begin_2";
               break;


                case "begin_2":
  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "begin_3";
               break;

                case "begin_3":
  
                        dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "begin_4";
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
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
			AddDialogExitQuest("Bartolomeu_search");
                       
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
			link.l1.go = "exit";

                        AddDialogExitQuest("fight");
                       
		break;

                case "begin_9":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";

                        AddDialogExitQuest("bartfollow");
                       
		break;

                case "begin_10":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "begin_11";
                        PlayStereoSound("VOICE\ENGLISH\Spa_m_a_029.wav");			
                      
		break;

                case "begin_11":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "begin_12";                 
                      
		break;

                case "begin_12":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "begin_13";                 
                      
		break;

                case "begin_13":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "begin_14";                 
                      
		break;

                case "begin_14":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit"; 
                
                         AddDialogExitQuest("fight_2");                     
		break;

                case "begin_15":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit"; 
                
                         AddDialogExitQuest("goverplace");                     
		break;

                case "begin_16":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "begin_17";                 
                      
		break;

                case "begin_17":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "begin_18";                 
                      
		break;

                case "begin_18":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "begin_19";                 
                      
		break;

                case "begin_19":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";                 
                        AddDialogExitQuest("commandant");
                     
		break;

                case "begin_20":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "begin_21";                 
                        PlayStereoSound("VOICE\ENGLISH\Spa_m_a_030.wav");                           
		break;

                case "begin_21":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "exit"; 
                        AddDialogExitQuest("combat");                
                      
		break;

                case "begin_22":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "begin_23";                 
                      
		break;

                case "begin_23":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "exit"; 
                        AddDialogExitQuest("bartmoi");                
                      
		break;

                case "begin_24":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "begin_25";                 
                      
		break;

                case "begin_25":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "exit"; 
                        AddDialogExitQuest("fight_5");                
                      
		break;

                case "begin_26":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "exit"; 
                        AddDialogExitQuest("evasion_3");                
                      
		break;

                case "begin_27":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "begin_28"; 
                                                
		break;

                case "begin_28":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "exit"; 
                        AddDialogExitQuest("embarquer");
                                                
		break;

                case "begin_29":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "exit";
              LAi_SetActorType(characterFromID("William Klein"));
              LAi_ActorFollowEverywhere(characterFromID("William Klein"), "", 60.0); 
                                                
		break;

                case "begin_30":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "begin_31";
                                        
		break;

                case "begin_31":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "begin_32"; 
                                                           
		break;

                case "begin_32":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "exit"; 
                        AddDialogExitQuest("directredmond"); 
                                                           
		break;

                case "begin_33":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "begin_34";
                                                           
		break;

                case "begin_34":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "begin_35";
                                        
		break;

                case "begin_35":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[71];
			link.l1.go = "begin_36"; 
                                                           
		break;

                case "begin_36":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "begin_37"; 
                                                           
		break;

                case "begin_37":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "exit";
                       AddDialogExitQuest("dispute_3"); 
                                                    
		break;

                case "begin_38":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "begin_39";
                       PlayStereoSound("VOICE\ENGLISH\Eng_m_b_001.wav");                                                                        
		break;

                case "begin_39":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79];
			link.l1.go = "exit";
                       AddDialogExitQuest("bartcaptain"); 
                                                                        
		break;

               case "Exit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		

                       break;



	}
}
