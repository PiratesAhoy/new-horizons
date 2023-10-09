// ccc Buildingset, new file	
/*
ccc Dec06:
Unlike most other files in this folder this one contains not only a textarray but code and English text merged.

The buildingset has recently been messed up by the attempt to localize my original all-English dialogfiles.
Instead of spending weeks with fixing and testing the new files I restored my original files.
However, the localization project has changed the structure of PotC for good :
Upon loading a  "x-dialog.c" codefile the program now automatically includes a  "x-dialog.h" text array file from the dialogs\english subfolder(or from the Russian folder if you use that language).
There the dialogtext is supposed to be.

However, I prefer to have code AND plain text in one file, for 3 reasons:
-It is much easier to write
-You have much less bugs with not matching texts
-It is much easier to read and understand the file for debuggers and people who would like to change it
The last point is especially important for me cause the Buildingset is supposed to be a tool for people who want to start modding.
That's why I stick to the original "code plus English text" dialogfiles.

As a concession to the localization project I put these files NOT into the \dialogs rootfolder but into the \dialogs\English subfolder.
So if you want to translate this dialog you can simply copy the "code plus English text" into the subfolder for your language and translate the English text there.
That will certainly be less work and trouble than messing up my files again.
Not mention the work and trouble that the debuging always causes.
*/
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
	
	string natname = XI_ConvertString(GetNationNameByType(sti(npchar.nation)));

	switch(natname)
	{
	case "portugal":
		PlayStereoSound("voice\ENGLISH\por_m_a_038.wav");
		break;

	case "holland":
		PlayStereoSound("voice\ENGLISH\dut_m_a_040.wav");
		break;

	case "britain":
		PlayStereoSound("voice\ENGLISH\eng_m_a_051.wav");
		break;

	case "france":
		PlayStereoSound("voice\ENGLISH\fre_m_a_042.wav");
		break;

	case "spain":
		PlayStereoSound("voice\ENGLISH\spa_m_a_039.wav");
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
		dialog.text = "¡Ah, "+ XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false)) + " " + PChar.lastname +  "! ¡Por fin conozco en persona a tan insigne adalid de quien tanto he oído hablar! Solo cosas buenas, claro. Las noticias de tus heroicas hazañas han llegado a las más altas esferas de la corte de " + natname + ", donde han quedado tan impresionados por tu persona que incluso " + GetNationRoyalByType(sti(npchar.nation)) + " expresó su deseo de superar los... eh... pequeños malentendidos que han... ejem... ensombrecido la relación entre " + natname + " y tú. Así que olvidemos el pasado y naveguemos juntos hacia un brillante futuro. Si te prestas a luchar por nuestra orgullosa -y generosa- nación, te concederemos una amnistía y una real patente de corso. ¡Y en consideración por tu liderazgo y DESTREZA, te ofrecemos una suma de " + npchar.bribe + " piezas de oro!";

		if(sti(pchar.money)>sti(npchar.bribe))
		{
			link.l1 = "¿Qué? ¿Crees que puedes comprarme? ¿Quién te crees que soy? No necesito tu sucio dinero, desprecio esas mezquinas sumas. Ten, toma estas " + npchar.bribe + " piezas de oro que te ofrezco yo, llévaselas a Tu Mahjestad y dile que se las meta por su real culo. Sin duda, encontrarás una forma diplomática de hacerlo, ¿eh? Y ahora, ¡fuera de mi vista!";
			link.l1.go = "exit_reput";
		}

		link.l2 = "¿Qué? ¿Crees que puedes comprarme? ¿Quién te crees que soy? ¿Un mercenario? Bueno, pues estás de suerte, porque soy esa clase de " + XI_ConvertString(PChar.sex) + ". Muchas gracias por el dinero y mis saludos cordiales a " + GetNationRoyalByType(sti(npchar.nation)) + ". Dile que hundiré algunos barcos especialmente dedicados a él. Adiós.";
		link.l2.go = "exit_change";

		link.l3 = "Hum, me temo que a mi actual pagador... esto... a mi amada patria, quiero decir, no le gustará que cambie de bando. Y no puedo permitirme tener a " + XI_ConvertString(GetNationNameByType(GetServedNation())) + " como enemiga. Y también tengo que pensar en mi reputación. Así que no hay trato, lo siento. ";
		link.l3.go = "exit";
		break;


	case "exit":
		LAi_SetActorType(NPchar);
		LAi_ActorGoToLocation(NPchar, "reload", LAi_FindRandomLocator("reload"), "none", "", "", "", 25.0);
		DialogExit();
		NextDiag.CurrentNode = NextDiag.TempNode;
		break;

	case "exit_reput":
		PlayStereoSound("INTERFACE\took_item.wav");
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
			PlayStereoSound("voice\ENGLISH\por_m_a_038.wav");
			break;

		case "holland":
			PlayStereoSound("voice\ENGLISH\dut_m_a_040.wav");
			break;

		case "britain":
			PlayStereoSound("voice\ENGLISH\eng_m_a_051.wav");
			break;

		case "france":
			PlayStereoSound("voice\ENGLISH\fre_m_a_042.wav");
			break;

		case "spain":
			PlayStereoSound("voice\ENGLISH\spa_m_a_039.wav");
			break;
		}

		SetRelationsAsNation(Npchar.nation); // ccc Dec 06
		ReceiveLetterOfMarque(Npchar.nation);

		PlayStereoSound("INTERFACE\took_item.wav");
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
