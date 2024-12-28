// Ported by Vex

void ProcessDialogEvent()
{
	aref Link;

	DeleteAttribute(&Dialog,"Links");

	makearef(Link, Dialog.Links);

    ref chr;
    float  fTemp;
    bool bOk;

	switch(Dialog.CurrentNode)
	{
        case "TalkSelf_Exit":
			DialogExit_Self();
		break;

		case "TalkSelf_Main":
			Dialog.Text = DLG_TEXT[2];

			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "TalkSelf_Wait1";

			Link.l10 = DLG_TEXT[4];
			Link.l10.go = "TalkSelf_Exit";
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
			Link.l1.go = "TalkSelf_Exit";
		break;
	}
}

void  DialogExit_Self()
{
    locCameraSleep(false);
    DialogExit();
}