// ccc jul05 corpse
// This pseudo dialog only opens the itemexchange interface for looting corpses
// one could also add dialogchoices for reawakening or burial


void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	int loc_id = FindLocation(PChar.location);

	switch(Dialog.CurrentNode)
	{
		case "exit_hostile":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			LAi_group_SetRelation("random_pirates_group", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "first time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\PADI\PADI001";
			// ccc Dec 05 You are recognized for your pirating actions
			if (GetFlagRMRelation(sti(Npchar.nation)) != RELATION_ENEMY) //MT: You are either flying the pirate flag, or using your personal flag while not hostile with the pirates
			{
				if(GetServedNation() == PIRATE)	// PB: Link this to acting as a pirate
				{
					if(GetCurrentLocationNation() == PIRATE)
					{
						Dialog.Text = DLG_TEXT[0] + GetMySimpleName(PChar) + DLG_TEXT[1];
						Link.l1 = DLG_TEXT[2];
					}
					else
					{
						Dialog.Text = DLG_TEXT[0] + GetMySimpleName(PChar) + DLG_TEXT[1];
						Link.l1 = DLG_TEXT[5];
					}
					Link.l1.go = "exit";
				}
				else
				{
					if(GetNationRelation2MainCharacter(sti(NPChar.nation)) == RELATION_ENEMY && frnd() < GetChanceDetectFalseFlag()) //MT: At war with pirates
					{
						if (GetCurrentLocationNation() == PIRATE) // MT: If you were masquerading as a pirate to sneak into their town:
						{
							Dialog.Text = DLG_TEXT[3];
							Link.l1 = DLG_TEXT[4];
						}
						else //MT: Masquerading as a pirate, not in a pirate town, and got detected by pirates as not being a pirate
						{
							Dialog.Text = DLG_TEXT[6];
							Link.l1 = DLG_TEXT[7];
						}
						Link.l1.go = "exit_hostile";
					}
					else // MT: You're not at war with the pirates and/or didn't get detected as a false pirate, therefore aren't targeted by them
					{
						if (frnd()<makefloat(GetRankFromPoints(GetScore(PChar)))/12.0 || frnd()<makefloat(GetRank(pchar, sti(NPChar.nation)))/12.0)//MT: recognised as famous individual
						{
							Dialog.Text = DLG_TEXT[12];
							Link.l1 = DLG_TEXT[13];
						}
						else
						{
							Dialog.Text = DLG_TEXT[18];
							Link.l1 = DLG_TEXT[19];
						}
						Link.l1.go = "exit";
					}
				}
			}
			else //MT: Flying a flag hostile towards pirates, which can be your personal flag.
			{
				if(GetNationRelation2MainCharacter(sti(NPChar.nation)) != RELATION_ENEMY) //MT: You're NOT using your personal flag, and are personally not hostile
				{
					Dialog.Text = DLG_TEXT[8];
					Link.l1 = DLG_TEXT[9];
					Link.l1.go = "exit";
				}
				else //MT: Not a pirate, not using the pirate flag, and hostile towards pirates. Circumstances the player is most likely to encounter.
				{
					if (frnd()<makefloat(GetRankFromPoints(GetScore(PChar)))/12.0) //MT: You are a rich and famous individual
					{
						Dialog.Text = DLG_TEXT[20] + GetMySimpleName(PChar) + DLG_TEXT[21];
						Link.l1 = DLG_TEXT[22];
						Link.l1.go = "exit_hostile";
					}
					else //MT: The pirates don't want to bother attacking you despite being hostile:
					{
						Dialog.Text = DLG_TEXT[10];
						Link.l1 = DLG_TEXT[11];
						Link.l1.go = "exit";
					}
				}
			}
			Diag.TempNode = "first time";
		break;
	}
}
