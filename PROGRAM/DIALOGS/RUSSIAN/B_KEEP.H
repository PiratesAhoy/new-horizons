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

	PlayStereoSound("ambient\jail\chains.wav");
	PlayStereoSound("ambient\cave\drop5.wav");

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

			if(rand(100)<10) //  шанс для случайной атаки, уменьшите последнюю цифру для меньшего количества атак
			{
				PlayStereoSound("voice\Eng_m_a_070.wav");
				ChangeCharacterReputation(Pchar, -2);  // наказание: потеря репутации. Будет компенсировано, если принять бой
				Dialog.text = adress + LinkRandPhrase(" Обнаружены вражеские силы. Приготовиться к обороне.", " движения противника в нашем секторе! Четвертовать!", "Подозрительные передвижения по нашему периметру, сражения с людьми!");

				link.l1 = "Подробный отчет, морпех, СЕЙЧАС ЖЕ.";
				if(rand(100)>50) {Link.l1.go = "attack1";}
				else{Link.l1.go = "attack2";}

				link.l9 = "Оставь меня в покое с этим, это ТВОЯ работа! В конце концов именно для этого я тебя и нанял : в качестве пушечного мяса.. эээ.. канонира. У меня все равно нет времени: я должен поспешить обратно в свой безопасный белый дом, снять куртку-бомбер и произнести несколько резких колкостей в адрес избирателей.";
				link.l9.go = "exit";
			}
			else
			{
				Dialog.text =  "Отчет " + buildingstr + " укомплектован и готов к бою ," + adress + " в этом секторе все спокойно.";

				if(NPChar.chr_ai.group==LAI_GROUP_PLAYER)
				{
					link.l1 = "Мы отказываемся от этой позиции. Разрушьте это строение " + buildingstr + ", погрузите доски в наш трюм и явитесь к сержанту моей морской пехоты для выполнения корабельных обязанностей.";
					link.l1.go = "dismantle";

					link.l21 = "Мне нужно безопасное место для хранения некоторых моих сокровищ и снаряжения, и эта старая крепость выглядит ОЧЕНЬ безопасным местом. Можешь оставить здесь кое-что для меня?";
					link.l21.go = "items";
					link.l22 = "Я бы хотел перекинуться парой слов о своих вещах с этим Стариной Крипером.";
					link.l22.go = "items";

					if(sti(pchar.money)>5000 && !CheckCharacterItem(NPChar,"cannon") )
					{
					link.l23 = "Интересно, имеет ли смысл размещать здесь оружие.";	// ccc feb06
					link.l23.go = "cannon";
					}

					if(CheckCharacterItem(PChar,"pistolgrenade") && !CheckCharacterItem(NPChar,"pistolgrenade") )
					{
					link.l24 = "Морской пехотинец, у меня есть для тебя особое задание: Вот, возьми эту гранату, и используй ее если враг прорвется и возьмет штурмом эту позицию...";
					link.l24.go = "grenade";
					}
				}
				else
				{
					link.l1 = "Просто проходил мимо... ";
					link.l1.go = "exit";
				}

				Link.l4 = "Очень хорошо, морской пехотинец, продолжайте.";
				Link.l4.go = "exit";

				// ccc feb06 link.l6 = "Кто, черт возьми, спроектировал этот каменный лабиринт? Не могу сделать здесь и шага, чтобы не врезаться головой в какой-нибудь свод или колонну..";
				// ccc feb06 link.l6.go = "odd";

				link.l5 = "Эй, почему ты стоишь здесь так неподвижно? " + LinkRandPhrase("Ты проглотил метлу...", "Давай, расслабься немного... СПОКОЙНО!", "Я ожидаю немного большей активности от моих морских пехотинцев, ты меня слышишь?");
				link.l5.go = "motion";

				link.l9 = "Эй, ты там, перед клавиатурой! Это здание, которое ВЫ создали, так как насчет того, чтобы создать свой собственный диалог? Просто используйте Блокнот, чтобы открыть файл program\dialogs\" " + NPchar.dialog.filename + " перезапишите этот текст своим. Тогда следуйте инструкциям в комментариях.";
				link.l9.go = "your_dialog"; //это тот случай, который запускается, если вы выбираете диалоговую опцию l13. Это прямо внизу.
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
			Dialog.text = "...И если какая-нибудь мразь осмелится войти в мое... э-э-э.. ваше поместье, я разнесу их в пух и прах!" ;
			link.l1 = "Вот это дух, Марин! С твоим чувством долга ты скоро станешь капралом. (..если вы проживете так долго..)";
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "pistolgrenade" );
			GiveItem2Character(NPchar, "pistolgrenade");
		break;

// отдать пушку зданию для самообороны
		case "cannon":
			Dialog.text = "Несомненно, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + "! Пушка здесь, внизу, прикрывающая вход, разнесет любого незваного гостя в пух и прах." ;	// ccc feb06
			link.l1 = "Может быть, но я не хочу тратить здесь еще больше денег.";	// ccc feb06
			link.l1.go = "exit";

			link.l2 = "Вот 5000 золотых, не могли бы вы... эээ... получить на это подходящее оружие?";
			link.l2.go = "cannon2";
		break;

		case "cannon2":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(Pchar, -5000);
			Pchar.Ship.crew.quantity = sti(Pchar.Ship.crew.quantity) -3;
			lcn.building.(nr).interior = "cannon";
			Dialog.text = "Да, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + ", Я довольно хорошо знаю главного сержанта местного магазина. За 5000 золотых он продал бы все свое снаряжение. Просто дай мне несколько часов." ;
			link.l1 = "Вот это дух, морской пехотинец! С твоим пониманием логистики ты скоро станешь капралом. (..если ты проживешь так долго..)";
			link.l1.go = "exit";
		break;

// хранитель загрузки предметов
		case "items":
		  if(taxdays>0 && rand(100)<120) // шанс получить случайный драгоценный камень, увеличьте последнюю цифру, чтобы получить больше драгоценных камней
		  {
  	 		lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
  			Dialog.text = LinkRandPhrase("Ах, говоря о ценностях, это напомнило мне, что я нашел украшение в старых катакомбах под этой крепостью. Я писял.. эээ.. патрулировал там внизу, когда заметил свежую щель в одной из стен. За ней я нашел старую погребальную камеру, и среди старых костей был этот маленький драгоценный камень, который блестел, словно приглашая меня взять его. Но, поразмыслив, я понял, что ", "Кстати, у меня есть дополнение к вашим вещам: это украшение. Нашел его вчера, когда убирал обломки недавно рухнувшей стены. Среди камней была разбитая урна, пепел, кости, зубы.. И этот прекрасный драгоценный камень. Конечно ", "Перед тем, как заняться инвентарем, вы можете добавить в него это украшение. Вчера я убирал погребальную камеру в бывшей часовне крепости ,чтобы освободить место для хранения рома.. эээ.. боеприпасов, тогда этот блестящий предмет выпал из груды костей, которую я нес. Прямо мне на колени, как подарок с небес. Или, скорее, с преисподни. По справедливости ")  + "он принадлежит вам, поскольку теперь вы являетесь владельцем этого поместья. Так что я предпочел бы передать его вам, чтобы проклятие его мертвого владельца не пало на меня." ;
  			link.l1 = "(Проклятие его мертвого владельца? Черт!) О нет, оставь это себе. В конце концов, ты заслуживаешь награды за свою честность и верность, морской пехотинец! С твоим чувством честности ты скоро станешь капралом. (..если ты проживешь так долго..)";
  			link.l1.go = "reward";
  			link.l2 = "Проклятие? Суеверный вздор! Ты хочешь напугать меня, чтобы я оставил тебе этот камень, да? Со мной этот трюк не пройдёт, давай сюда его. Быстро! ";
  			link.l2.go = "jewel";
			}
			else
		  {
  	 		lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
  			Dialog.text = "Да, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + ", Я позову Хранителя этой крепости. Кстати, его манеры немного старомодны.. эээ.. традиционные, слишком долго жил в этой древней Башне, если вы спросите меня. Но именно такое традиционное отношение делает его самым надежным хранителем вашего сокровища. Вы можете отдать ему на хранение все, что угодно, и быть уверенным, что он вернет вам это, когда вы этого захотите." ;
  			link.l1 = "Я надеюсь, что это так. Теперь, где этот средневековый помощник?";
  			link.l1.go = "items2";
			}
		break;

		case "jewel":
		  GiveItem2Character(PChar, "jewelry"+ makeint(1 + rand(15)) );
		  if(rand(100)<20) // шанс отравления, уменьшите последнюю цифру для меньшего отравления
		  {
  			DialogExit();
  			NextDiag.CurrentNode = NextDiag.TempNode;
  			pchar.chr_ai.poison = 20 + rand(50 -sti(PChar.skill.Sneak) -sti(PChar.skill.defence) );
  			PlaySound("OBJECTS\DUEL\man_hit6.wav");
  			Logit("Проклятие? Могила жертв чумы? Как бы то ни было, вы внезапно чувствуете себя ужасно больным!");
			}
			else
		  {
  		  pchar.ship.crew.morale=makeint(stf(pchar.ship.crew.morale) -5 );  // наказание: боевой дух экипажа. Изменить по своему вкусу
  			Dialog.text = "Да, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + ", твое желание для меня закон. Кстати, как насчет небольшой.. эээ.. награды? Было бы хорошо для морального духа ваших войск, если бы честные и преданные солдаты были вознаграждены?" ;
  			link.l1 = "Наглый ублюдок! Завуалированные требования? Как ты смеешь! Хватит об этом, я хочу разобраться со своими сокровищами. Сейчас же!";
  			link.l1.go = "items";
			}
		break;

		case "reward":
			ChangeCharacterReputation(Pchar, 2);  // награда: репутация. Изменить по своему вкусу
			Dialog.text = "Это очень великодушно с вашей стороны, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + ". Я всем расскажу, какой ты добрый и заботливый командир, можешь быть в этом уверен!";
			link.l1 = "О, не беспокойтесь, я не так уж забочусь о своей репутации. Кстати, я даю тебе отпуск сегодня вечером. Почему бы тебе не пойти в центр города, не пообщаться с горожанами, поболтать... А теперь, пожалуйста, вернемся к МОЕМУ сокровищу.";
			link.l1.go = "items";
		break;

		case "items2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			ref chr = characterFromID("B_keeper");
			string locator = LAi_FindRandomLocator("reload");
			float x,y,z;
	  	   	ChangeCharacterAddressGroup(chr, pchar.location, "reload", locator);
  			GetCharacterPos(pchar, &x, &y, &z);
  			x = x+1;
  			TeleportCharacterToPos(chr, x, y, z);
  			Lai_SetActorType(chr);
  			LAi_ActorTurnToCharacter(chr, pchar);
  			LAi_ActorDialog(chr,pchar, "", 4.0, 1.0);
		break;


// случайные атаки
		case "attack1":
			Dialog.text = "Дикие каннибалы Акеллани приближаются, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + "! Ох, если бы у нас было побольше этих бастионов, частоколов, мин и пушек...";
			link.l1 = RandSwear() + " Внимание, солдат! Сохраняйте эту позицию, что бы ни случилось. Продолжайте стрелять, не дайте противнику втянуть вас в ближний бой. Я позабочусь о ближних противниках...",
			link.l1.go = "exit_attack1";
		break;

		case "attack2":
			Dialog.text = " Франсиско Писарро Младший и его орда мародерствующих конкистадоров приближаются, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + "! Жаждющие крови, грабежа и насилия... Ох, если бы у нас было побольше этих бастионов, частоколов, мин и пушек...";
			link.l1 = RandSwear() + " Внимание, солдат! Сохраняйте эту позицию, что бы ни случилось. Продолжайте стрелять, не дайте противнику втянуть вас в ближний бой. Я позабочусь о ближних противниках...",
			link.l1.go = "exit_attack2";
		break;

		case "Exit_attack1":
		// PB: Чтобы предотвратить начало боя до закрытия диалогового окна
			Ambush("native", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			ChangeCharacterReputation(Pchar, 4);  // награда: репутация. Измените по своему вкусу
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // награда: опыт. Измените последнюю цифру по своему вкусу

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_attack2":
		// PB: Чтобы предотвратить начало боя до закрытия диалогового окна
			Ambush("Soldier_Spa2",  3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			ChangeCharacterReputation(Pchar, 4);  // награда: репутация. Измените фигуру по своему вкусу
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // награда: опыт. Измените последнюю цифру по своему вкусу


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
			Dialog.text = "Что ж, правда, конструкция этой башни устарела. Пятиугольная крепость была изобретена во времена норманнов, когда главной угрозой для укрепления были лестницы и простые осадные машины. Массивные своды были спроектированы так, чтобы выдерживать удары таранов и подрывы, поэтому нижние этажи здесь почти полностью заполнены каменной кладкой и не предлагают места для размещения. Изобретение пороха сделало эту архитектуру устаревшей. В настоящее время эти башни часто используются в качестве тюрьмы или для хранения ценностей, потому что именно для этого они и были спроектированы в первую очередь: удерживая людей от проникновения внутрь. Или из нее." ;
			link.l1 = "Ммм, в этом отношении это очень удачный дизайн: Мне очень трудно войти или выйти, не врезавшись в какую-нибудь стену.";
			link.l1.go = "exit";
		break;

		case "motion":
			Dialog.text = LinkRandPhrase(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + ", мы всегда стоим по стойке смирно в присутствии вышестоящего начальника. Это тренировка, а тренировка - это все.", "Я слежу за подозрительной целью, и я не хочу ее потерять. 'Держи цель, никогда не вздрагивай, никогда не моргай' наш сержант по строевой подготовке обычно говорил.", "Первое правило камуфляжа: движение привлекает внимание. Так что никогда не двигайся, если в этом нет необходимости.");
			link.l1 = "Хорошо, я понимаю... Продолжай.";
			link.l1.go = "exit";
		break;


// выход из диалогового окна

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
