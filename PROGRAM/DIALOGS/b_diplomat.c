// ccc Buildingset, new file

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
	
	string natname = GetNationNameByType(sti(npchar.nation));

	switch(natname)
	{
	case "portugal":
		PlayStereoSound("voice\por_m_a_038.wav");
		break;

	case "holland":
		PlayStereoSound("voice\dut_m_a_040.wav");
		break;

	case "britain":
		PlayStereoSound("voice\eng_m_a_051.wav");
		break;

	case "france":
		PlayStereoSound("voice\fre_m_a_042.wav");
		break;

	case "spain":
		PlayStereoSound("voice\spa_m_a_039.wav");
		break;
	}

	npchar.bribe = (sti(pchar.skill.fencing)+sti(pchar.skill.leadership)+sti(pchar.skill.accuracy))*1000;
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
		NextDiag.TempNode = "first time";
		dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, true) + DLG_TEXT[1] + XI_ConvertString(natname) + DLG_TEXT[2] + GetNationRoyalByType(sti(npchar.nation)) + DLG_TEXT[3] + XI_ConvertString(natname) + DLG_TEXT[4] + npchar.bribe + DLG_TEXT[5];

		if(sti(pchar.money)>sti(npchar.bribe))
		{
			link.l1 = DLG_TEXT[6] + npchar.bribe + DLG_TEXT[7];
			link.l1.go = "exit_reput";
		}

		link.l2 = DLG_TEXT[8] + XI_ConvertString("mistah") + DLG_TEXT[9] + GetNationRoyalByType(sti(npchar.nation)) + DLG_TEXT[10];
		link.l2.go = "exit_change";

		link.l3 = DLG_TEXT[11] + XI_ConvertString(GetNationNameByType(GetServedNation())) + DLG_TEXT[12];
		link.l3.go = "exit";
		break;


	case "exit":
		LAi_SetActorType(NPchar);
		LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		break;

	case "exit_reput":
		PlayStereoSound("INTERFACE\took_item.flac");
		AddMoneyToCharacter(pchar, -sti(npchar.bribe));
		ChangeCharacterReputation(pchar, 3);
		if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", sti(npchar.bribe)/10/2 ); AddPartyExpChar(PChar, "Sneak", sti(npchar.bribe)/10/2 ); }
		else { AddPartyExp(PChar, sti(npchar.bribe)/10 ); }

		LAi_SetActorType(NPchar);
		LAi_ActorRunToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		break;

	case "exit_change":

		switch(natname)
		{
		case "portugal":
			PlayStereoSound("voice\por_m_a_038.wav");
			break;

		case "holland":
			PlayStereoSound("voice\dut_m_a_040.wav");
			break;

		case "britain":
			PlayStereoSound("voice\eng_m_a_051.wav");
			break;

		case "france":
			PlayStereoSound("voice\fre_m_a_042.wav");
			break;

		case "spain":
			PlayStereoSound("voice\spa_m_a_039.wav");
			break;
		}

		SetRelationsAsNation(Npchar.nation); // ccc Dec 06
		ReceiveLetterOfMarque(Npchar.nation);

		PlayStereoSound("INTERFACE\took_item.flac");
		AddMoneyToCharacter(pchar, sti(npchar.bribe));
		ChangeCharacterReputation(pchar, -6);
		if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", sti(npchar.bribe)/10/2 ); AddPartyExpChar(PChar, "Sneak", sti(npchar.bribe)/10/2 ); }
		else { AddPartyExp(PChar, sti(npchar.bribe)/10 ); }

		LAi_SetActorType(NPchar);
		LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		break;

	}
}