void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	//Added to every piece of dialog at the end
	if(DEBUG_EXPERIENCE>0)
	{
		link.l99 = "Show your skills";
		link.l99.go = "ShowSkillsAll";
	}
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "ShowSkillsAll":
			DialogExit();			
			LaunchOfficer(NPChar);
		break;
	}
}
