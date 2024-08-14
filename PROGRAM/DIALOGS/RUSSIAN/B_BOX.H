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

	
			Dialog.text =  "Простая коробка, наполовину зарытая в землю. Служит препятствием и может быть заминирована с помощью гранаты.";

			link.l1 = "Эта штука - просто бесполезная помеха. Боцман! Убери это подальше. И положите доски в наш магазин.";
			link.l1.go = "dismantle";

			if(!CheckCharacterItem(NPChar,"pistolgrenade") && CheckCharacterItem(PChar,"pistolgrenade") )
			{
					link.l21 = "Как раз подходящее место для ловушки. Граната с кремневым замком, прикрепленным к крышке, станет приятным сюрпризом для любого любопытного парня. И вряд ли кто-нибудь устоит перед искушением...";
					link.l21.go = "grenade";

			}
			Link.l4 = "Мне лучше оставить эту штуку в покое...";
			Link.l4.go = "exit";

			link.l9 = "Эй, ты там, перед клавиатурой! Это здание, которое ВЫ создали, так как насчет того, чтобы создать свой собственный диалог? Просто используйте Блокнот, чтобы открыть файл program\dialogs\ " + NPchar.dialog.filename + " перезапишите этот текст своим. Тогда следуйте инструкциям в комментариях.";
			link.l9.go = "your_dialog"; //это тот случай, который выполняется, если вы выберете диалоговое окно l9. Это прямо под этим.
		
		break;
                
		case "your_dialog":
			Dialog.text = "Перезапишите это диалоговым текстом NPC." ;

			link.l1 = "Текст опции диалога игрока link.l1, которая завершает диалог ";
			link.l1.go = "exit";	// ссылка l1 закрывает диалог

			link.l2 = "Текст опции диалога игрока link.l2, которая ведет к другому обмену ";
			link.l2.go = "your_dialog2";	// l2 приводит к случаю your_dialog2
		break;	// конец регистра "ваш_диалог"
                
		case "your_dialog2":
			Dialog.text = "Перезапишите это диалоговым текстом NPC." ;

			link.l1 = "Текст опции диалога игрока link.l1, которая завершает диалог";
			link.l1.go = "exit";	// ссылка l1 закрывает диалог

			// Вот некоторые кодовые строки, которые дают вам золото, предметы, товары или опыт. Чтобы активировать их, удалите косую черту комментария «//» перед кодом. Вы можете изменить суммы на свое усмотрение.

			// AddMoneyToCharacter(Pchar, 1000);

			// GiveItem2Character(Pchar, "Spyglass3");
			// GiveItem2Character(Pchar, "Jewelry5");
			// GiveItem2Character(Pchar, "Mineral3");
			// TakenItems(Pchar, "potion1", 3);

 			// AddCharacterGoods(pchar, GOOD_SANDAL, 10 );
			// AddCharacterGoods(pchar, GOOD_SILK, 10 );
			// AddCharacterGoods(pchar, GOOD_RUM, 20 );
			// AddCharacterGoods(pchar, GOOD_WHEAT, 20 );

			// AddPartyExp(PChar, 100 );


		break;	// конец регистра "ваш_диалог2"

                
		case "grenade":
			TakeItemFromCharacter(pchar, "pistolgrenade" );
			GiveItem2Character(NPchar, "pistolgrenade");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "dismantle":
			DialogExit();
			planks += sti(buildingref.building.planks);
			crew += sti(buildingref.building.crew);

			if(CheckAttribute(Npchar,"equip.gun"))
			{
				planks += sti(interiorref.building.planks);
				crew += sti(interiorref.building.crew);
			}
			AddCharacterGoods(pchar, GOOD_PLANKS, planks);
			AddCharacterCrew(pchar, crew);   // ccc mar06
			Lai_KillCharacter(npchar);
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
