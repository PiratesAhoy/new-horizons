
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

	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

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
			Dialog.snd = "dialogs\0\009";

			if(NPchar.sex == "man") {PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_c_006.wav");}	//ccc
			else {PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_f_c_003.wav");}			//MAXIMUS: in russians sounds Dut_f_a_001.wav says 'Do you want to rent a room for the night?', but this sound says 'What can I serve for you?' or something like that

			NPChar.Dialog.Filename = "Enc_Officer_dialog.c";
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "exit_change_dlg";
			NPChar.offgen = true;
			NPChar.officer = true;
			/*switch(Rand(7))
			{
				case 0: NPChar.quest.officertype = OFFIC_TYPE_BOATSWAIN; break;
				case 1: NPChar.quest.officertype = OFFIC_TYPE_CANNONEER; break;
				case 2: NPChar.quest.officertype = OFFIC_TYPE_QMASTER; break;
				case 3: NPChar.quest.officertype = OFFIC_TYPE_NAVIGATOR; break;
				case 4: NPChar.quest.officertype = OFFIC_TYPE_FIRSTMATE; break;
// MAXIMUS officers -->
				case 5: NPChar.quest.officertype = OFFIC_TYPE_CARPENTER; break;
				case 6: NPChar.quest.officertype = OFFIC_TYPE_DOCTOR; break;
				case 7: NPChar.quest.officertype = OFFIC_TYPE_ABORDAGE; break;
// MAXIMUS officers <--
			}*/
			NPChar.quest.officertype = GetRandomOfficerType(); //Levis let's use a global function so we can easily add types later.
			LAi_Create_Officer(rand(8), &NPChar);
		break;

		// NK -->
		case "exit_change_dlg":
			Diag.CurrentNode = "Node_1";
			DialogExit();
		break;
		// NK <--
	}
}