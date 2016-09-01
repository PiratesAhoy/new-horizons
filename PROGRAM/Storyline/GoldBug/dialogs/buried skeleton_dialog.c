// JRH fake dialog for buried skeletons

void ProcessDialogEvent()
{
	aref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makearef(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	PlaySound("AMBIENT\CRYPT\wind2.wav");
		
	DialogExit();
}