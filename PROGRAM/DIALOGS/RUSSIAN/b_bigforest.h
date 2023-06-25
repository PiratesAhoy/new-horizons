// ccc Buildingset, new file	
/*
ccc Dec06:
В отличие от большинства других файлов в этой папке, этот содержит не только текстовый массив, но и объединенный код и текст.

Сборочный набор недавно был испорчен попыткой локализовать мои исходные полностью английские диалоговые файлы. 
Вместо того, чтобы тратить недели на исправление и тестирование новых файлов, я восстановил исходные файлы.. 
Однако проект локализации навсегда изменил структуру PotC. : 
При загрузке кодового файла  "x-dialog.c" программа теперь автоматически включает файл текстового массива "x-dialog.h"  из подпапки dialogs\english (или из папки Russian, если вы используете этот язык). 
Там диалоговый текст должен быть.

Однако я предпочитаю иметь код И простой текст в одном файле по трем причинам:
-Писать намного проще
-У вас гораздо меньше багов с несовпадающими текстами
-Отладчикам и людям, которые хотели бы изменить его, намного легче читать и понимать файл.
Последний пункт особенно важен для меня, потому что он должен быть инструментом для людей, которые хотят начать заниматься моддингом.
Вот почему я придерживаюсь исходных диалоговых файлов "код плюс английский текст".

В качестве уступки проекту локализации я поместил эти файлы НЕ в корневую папку \dialogs, а в подпапку \dialogs\English.
Поэтому, если вы хотите перевести этот диалог, вы можете просто скопировать "код плюс английский текст" в подпапку для вашего языка и перевести там английский текст..
Это, безусловно, будет меньше работы и проблем, чем снова испортить мои файлы. 
Не говоря уже о работе и проблемах, которые всегда вызывает отладка.
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
	ref lcn = &Locations[FindLocation(PChar.location)];

	string nr = NPChar.lastname;
/*
	string buildingstr = NPChar.equip.blade;
	aref buildingref;
	Items_FindItem(buildingstr,&buildingref);

	string interiorstr = "simple furniture";
	if(CheckAttribute(Npchar,"equip.gun"))
	{
	interiorstr = NPChar.equip.gun;
	aref interiorref;
	Items_FindItem(interiorstr,&interiorref);
	}

	int planks = 0;
	int money = 0;
	int crew = 0;
*/	
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
			Dialog.snd = "voice\PADI\PADI001";

	
			Dialog.text =  "НАСТОЯЩИЕ джунгли: густой подлесок, странные сорняки и папоротники, пробивающиеся сквозь землю повсюду.";

			link.l1 = "Мне бы не помешало немного древесины, и после расчистки здесь будет хорошая строительная площадка. Боцман! Соберите отряд лесорубов! Я ожидаю, что вы расчистите эту территорию к завтрашнему дню. Положите доски в наш трюм. И разместите несколько охранников, в джунглях могут бродить дикари...";
			if(rand(100)>50) {Link.l1.go = "Akellani";}
			else{Link.l1.go = "dismantle";}

			Link.l4 = "Самое подходящее место для засады.. Мне лучше убраться отсюда...";
			if(rand(100)>70) {Link.l4.go = "Akellani";}
			else{Link.l4.go = "exit";}
		break;

		case "Akellani":
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }
			Ambush("natives", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			DialogExit();
		break;

		case "dismantle":
			DialogExit();
			WaitDate("", 0, 0, 1, 0, 0);
			LAi_Fade("", "");
			PlaySound("ambient\shipyard\axe.wav");
			PlaySound("ambient\shipyard\vehicle.wav");
			PlaySound("ambient\shipyard\saw.wav");
			PlaySound("ambient\shipyard\hammer.wav");

			ChangeCharacterAddress(NPChar, "none", "");
			Building_delete(lcn, nr);

			AddCharacterGoods(pchar, GOOD_PLANKS, 20 + makeint(rand(20)) );
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
