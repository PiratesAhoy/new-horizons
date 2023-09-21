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

	string interiorstr = "";
	if(CheckAttribute(Npchar,"equip.gun"))
	{
	interiorstr = NPChar.equip.gun;
	aref interiorref;
	Items_FindItem(interiorstr,&interiorref);
	}

	int planks = 0;
	int money = 0;
	int crew = 0;

	int grgbonus = 0;

	int iDYear = sti(lcn.building.(nr).taxyear);
	int iDMonth = sti(lcn.building.(nr).taxMonth);
	int iDDay = sti(lcn.building.(nr).taxDay);
	int taxdays = GetPastTime("day", iDYear, iDMonth, iDDay, 1, GetDataYear(), GetDataMonth(), GetDataDay(), 1);
	int tax = 0;

	string adress;
	if(NPChar.chr_ai.group==LAI_GROUP_PLAYER ){adress = " Commander, Sir, ";}else{adress = "";}

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

			if(rand(100)<30) // шанс для случайной атаки, уменьшите последнюю цифру для меньшего количества атак
			{
				ChangeCharacterReputation(Pchar, -2);  // наказание: потеря репутации. Будет компенсировано, если принять бой	
				PlayStereoSound("voice\Eng_m_a_070.wav");	
				Dialog.text = adress + LinkRandPhrase(" обнаружены вражеские силы. Приготовиться к обороне.", " вражеские передвижения в нашем секторе! Четвертовать!", "Подозрительные движения у нашего периметра, человек!");

				link.l1 = "Подробный отчет, морпех, СЕЙЧАС ЖЕ.";
				if(rand(100)>50) {Link.l1.go = "attack1";}
				else{Link.l1.go = "attack2";}

				link.l9 = "Оставь меня с этим в покое, это ТВОЯ работа! В конце концов, именно для этого я тебя и нанял: в качестве пушечного мяса... эээ.. канонира. У меня все равно нет времени: я должен поспешить обратно в свой безопасный белый дом, надеть свою бомбовую рубашку и произнести несколько резких колкостей в адрес избирателей.";
				link.l9.go = "exit";
			}
			else
			{
				PlayStereoSound("objects\duel\reload2.wav");
	      		PlayStereoSound("voice\ENGLISH\Eng_m_c_044.wav");
				Dialog.text =  "Сообщить, что здание " + buildingstr + " укомплектовано экипажем и готово к бою ," + adress + " в этом секторе все спокойно.";

				if(NPChar.chr_ai.group==LAI_GROUP_PLAYER)
				{
					link.l1 = "Мы отказываемся от этой позиции. Демонтируйте это " + buildingstr + ", погрузите доски в наш трюм и доложите сержанту моих морских пехотинцев о готовности к отправке.";
					link.l1.go = "dismantle";

					if(sti(pchar.money)>5000 && !CheckCharacterItem(NPChar,"cannon") )
					{
					link.l21 = "Это укрепление выглядело бы гораздо более грозным с пушкой. Не говоря уже об увеличении огневой мощи. Вот, морпех, возьми эти 5000 золотых и получи пушку для своей позиции.";
					link.l21.go = "cannon";
					}

					if(CheckCharacterItem(PChar,"pistolgrenade") && !CheckCharacterItem(NPChar,"pistolgrenade") )
					{
					link.l22 = "Морской пехотинец, у меня есть для тебя особое задание: Вот, возьми эту гранату, и если противник прорвется и будет штурмовать эту позицию, воспользуйся ей...";
					link.l22.go = "grenade";
					}
				}
				else
				{
					link.l1 = "Просто проходил мимо... ";
					link.l1.go = "exit";
				}

				Link.l4 = "Очень хорошо, морской пехотинец, продолжайте.";
				Link.l4.go = "exit";

				link.l6 = "Солдат, разве это укрепление не слишком низкое и слабое, чтобы остановить нападение?";
				link.l6.go = "odd";

				link.l5 = "Эй, почему ты стоишь здесь так неподвижно? " + LinkRandPhrase("Ты проглотил метлу...", "Давай, расслабься немного... УСПОКОЙСЯ!", "Я ожидаю немного большей активности от моих морских пехотинцев, вы меня слышите?");
				link.l5.go = "motion";

				link.l9 = "Эй, ты там, перед клавиатурой! Это здание, которое ВЫ создали, так как насчет того, чтобы создать свой собственный диалог? Просто используйте Блокнот, чтобы открыть файл program\dialogs\" " + NPchar.dialog.filename + " перезапишите этот текст своим. Тогда следуйте инструкциям в комментариях.";
				link.l9.go = "your_dialog"; //это тот случай, который запускается, если вы выбираете диалоговую опцию l9. Это прямо внизу.
			}
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

// дать гранату зданию для самообороны               
		case "grenade":
			Dialog.text = "...Я разнесу их в пух и прах. Я знаю свой долг, коммандер!" ;
			link.l1 = "Вот это дух, морской пехотинец! С твоим чувством долга ты скоро станешь капралом. (..если проживешь так долго..)";
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "pistolgrenade" );
			GiveItem2Character(NPchar, "pistolgrenade");
		break;

		case "cannon":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(Pchar, -5000);
			Pchar.Ship.crew.quantity = sti(Pchar.Ship.crew.quantity) -3;
			lcn.building.(nr).interior = "cannon";
			Dialog.text = "Да, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + ", Я довольно хорошо знаю старшину местного склада боеприпасов. За 5000 золотых он продал бы все свое снаряжение. Просто дай мне несколько часов." ;
			link.l1 = "Вот это дух, морской пехотинец! С твоим пониманием логистики ты скоро станешь капралом. (..если проживешь так долго..)";
			link.l1.go = "exit";
		break;


// случайные атаки
		case "attack1":
			Dialog.text = "Дикие каннибалы Акеллани приближаются, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + "! Ох, если бы у нас было побольше тех бастионов, частоколов, мин и пушек...";
			link.l1 = RandSwear() + " Внимание, солдат! Удерживайте эту позицию, что бы ни случилось. Продолжайте стрелять, не позволяйте врагу втянуть вас в ближний бой. Я возьму их на себя...";
			link.l1.go = "exit_attack1";
		break;

		case "attack2":
			Dialog.text = "Франсиско Писарро Младший и его орда мародерствующих конкистадоров приближаются, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + "! Жажда крови, грабежа и изнасилования... Ох, если бы у нас было побольше тех бастионов, частоколов, мин и пушек...";
			link.l1 = RandSwear() + " Внимание, солдат! Удерживайте эту позицию, что бы ни случилось. Продолжайте стрелять, не позволяйте врагу втянуть вас в ближний бой. Я возьму их на себя...";
			link.l1.go = "exit_attack2";
		break;

		case "Exit_attack1":
		// PB: Чтобы бой не начался до закрытия диалога.
			Ambush("natives", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			ChangeCharacterReputation(Pchar, 4);  // награда: репутация. Изменить по своему вкусу
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // награда: опыт. Измените последнюю цифру на свое усмотрение

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_attack2":
		// PB: Чтобы бой не начался до закрытия диалога
			Ambush("Soldier_Spa2_15",  3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			ChangeCharacterReputation(Pchar, 4);  // награда: репутация. Изменить по своему вкусу
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // награда: опыт. Измените последнюю цифру на свое усмотрение

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

// демонтаж этого здания
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

// информация о моддинге              
		case "odd":
			if(buildingstr == "bastion")
			{
				Dialog.text = "Слишком низко? Похоже, у вас такие же старомодные взгляды на военную архитектуру, как у тех русских каменщиков, которые строят здесь все эти средневековые городские стены и крепости-небоскребы. Но изобретение пороха сделало высокие зубчатые стены устаревшими. Низкий профиль этого бастиона делает осадную артиллерию менее уязвимой. Неважно, что вражеская пехота может забраться на низкие амбразуры, пока наша артиллерия продолжает стрелять, они долго не проживут." ;
			} else {
				Dialog.text = "Хм, ну, вся приличная древесина идет на верфи, так что нам пришлось построить этот частокол из ломких стволов и коряг. Правда, есть достаточно широкие бреши, через которые противник может протиснуться. Но пока наша артиллерия продолжает стрелять, они долго не проживут.";
			}
			link.l2 = "Так что артиллерия - ключ ко всему? Как я могу разместить свои пушки наилучшим образом?";
			link.l2.go = "odd2";
		break;

		case "odd2":
			Dialog.text = "Сгруппируйте несколько укреплений с пушками вместе, чтобы они могли поддерживать друг друга, но не настолько близко, чтобы все они подверглись атаке одновременно. На передовой сильный бастион, который принимает на себя основную тяжесть атаки, а за ним более дешевые частоколы, которые могут обстреливать атакующих, занятых бастионом. Но будьте осторожны, чтобы никто из ваших людей не попал на линию огня. На большой дистанции наши снаряды убивают всех, кто находится рядом с целью. Держитесь подальше от боя или держитесь ближе к орудиям, где вы будете в безопасности." ;
			link.l1 = "Ммм, я не уверен, что могу себе это позволить... Но спасибо за лекцию об укреплениях 17 века.";
			link.l1.go = "exit";
		break;

		case "motion":
			Dialog.text = LinkRandPhrase(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + ", мы всегда стоим по стойке смирно в присутствии начальника. Это тренировка, а тренировка - это все.", "Я присматриваю за подозрительной целью, и я не хочу слишком терять ее. 'Держи свою цель, никогда не вздрагивай, никогда не моргай' наш старший сержант обычно говорил.", "Первое правило маскировки: движение привлекает внимание. Так что никогда не двигайся, если в этом нет необходимости.");
			link.l1 = "Хорошо, я понимаю... Продолжай.";
			link.l1.go = "exit";
		break;


// диалоговые выходы
		case "moraledrop":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			pchar.ship.crew.morale=makeint(stf(pchar.ship.crew.morale) -5 );  // наказание: боевой дух экипажа. Изменить по своему вкусу
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
