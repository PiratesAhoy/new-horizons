extern void StartCheckDialog();
extern void StartCheckChrDialog();

void ProcessDialogEvent()
{
	DeleteAttribute(&Dialog,"Links");

	switch(Dialog.CurrentNode)
	{
		case "Check_Files":
			LoadSegment("CheckDlgLoad.c");
			StartCheckDialog();
			DialogExit();
		break;

		case "Check_Characters":
			LoadSegment("CheckDlgLoad.c");
			StartCheckChrDialog();
			DialogExit();
		break;
	}
}
