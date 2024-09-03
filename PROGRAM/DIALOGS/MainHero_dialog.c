// Ported by Vex

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

    ref chr;
    float  fTemp;
    bool bOk;

	switch(Dialog.CurrentNode)
	{
        case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit_Self();
		break;

		case "First time":
	      	NextDiag.TempNode = "First time";

	        Dialog.Text = "First time";
			Link.l1 = DLG_TEXT[0];
			Link.l1.go = DLG_TEXT[1];
		break;

		case "TalkSelf_Main":
	   		NextDiag.TempNode = "First time";
			Dialog.Text = DLG_TEXT[2];

			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "TalkSelf_Wait1";

			Link.l10 = DLG_TEXT[4];
			Link.l10.go = "exit";
		break;

		case "TalkSelf_Wait1":
			Dialog.Text = DLG_TEXT[5];

			Link.l1.edit = "string";
			Link.l1.go = "TalkSelf_Wait2";

		break;

		case "TalkSelf_Wait2":
			Dialog.Text = DLG_TEXT[6]; // If a valid integer is given, this won't have time to show up.

			int iWaitHours = sti(Dialog.value);

			if (iWaitHours > 0){
				WaitDate("", 0, 0, 0, iWaitHours, 0);
				LAi_Fade("", "");
				RecalculateJumpTable();
				Whr_UpdateWeather(false);
				DialogExit_Self();
			}
			Link.l1 = DLG_TEXT[4];
			Link.l1.go = "exit";
		break;
	}
}

void  DialogExit_Self()
{
    locCameraSleep(false);
    DialogExit();
}