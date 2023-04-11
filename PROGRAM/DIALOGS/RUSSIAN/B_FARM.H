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
#include "DIALOGS\English\B_resident_text.h"

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

	int grgbonus = 0;

	int iDYear = sti(lcn.building.(nr).taxyear);
	int iDMonth = sti(lcn.building.(nr).taxMonth);
	int iDDay = sti(lcn.building.(nr).taxDay);
	int taxdays = GetPastTime("day", iDYear, iDMonth, iDDay, 1, GetDataYear(), GetDataMonth(), GetDataDay(), 1);
	int tax = 0;

	string adress;
	if(NPChar.chr_ai.group==LAI_GROUP_PLAYER ) adress = "my Squire";
	else
	{
		if(PChar.sex=="woman") adress = "m'lady";
		else adress = "Mister";
	}

	PlayStereoSound("ambient\town\dog1.wav");
	PlayStereoSound("ambient\town\owen.wav");
	
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

			if(rand(100)<15) // шанс для случайной атаки, уменьшите последнюю цифру для меньшего количества атак
			{
				ChangeCharacterReputation(Pchar, -2);  // наказание: потеря репутации. Будет компенсировано, если принять бой	
        		PlayStereoSound("voice\ENGLISH\Eng_m_a_070.wav");	
				Dialog.text =  LinkRandPhrase("Слава Богу, что вы пришли! Вы можете защитить нас от этих тварей..", "Ах, небо послало вас в самый ответственный момент: мы вот-вот подвергнемся нападению. ПОМОГИ НАМ!", "Добро пожаловать, я говорю, нам отчаянно нужна борьба " + GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false) + " хотел бы, чтобы ты защитил от этого налета...");
				link.l1 = "Эй, успокойся! Боже, боже, ты уже окоченел от страха... А теперь скажи мне, что здесь происходит.";
				if(rand(100)>50) {Link.l1.go = "attack1";}
				else{Link.l1.go = "attack2";}

				link.l9 = "О, да ладно, ты же умеешь защищаться, не так ли? У меня есть важные дела, и я не хочу, чтобы меня беспокоили деревенские разборки!";
				link.l9.go = "exit";
			}
			else
			{	
				Dialog.text =  LinkRandPhrase("Ах, наш любимый помещик навещает свое " + buildingstr + ". Что я могу сделать для вас," + adress + "?" , "Добро пожаловать в мой.. эээ.. ВАШ " + buildingstr + " , " + adress + ", каково твое желание?" , "Добро пожаловать, " + adress + ". Что привело вас к моему.. эээ.. ВАШЕМУ " + buildingstr + "?");
				if(CheckAttribute(pchar,"chr_ai.poison") && pchar.chr_ai.poison > 0)
				{
					Link.l1 = "О, я чувствую себя ужасно! Лихорадка, опухшие конечности, потемнение вокруг моих ран... Боюсь, у меня гангрена!";
					Link.l1.go = "infected";
				}
				Link.l2 = B_TEXT[8];
				Link.l2.go = "heal";

				Link.l4 = LinkRandPhrase(B_TEXT[9], B_TEXT[10], B_TEXT[11]);
				Link.l4.go = "chat";

				if(NPChar.chr_ai.group==LAI_GROUP_PLAYER) // если вы домовладелец
				{
					if(taxdays>0)
					{
						link.l5 = "Как урожай на моей ферме? Сколько вы собрали за " + taxdays + " дней с момента последнего платежа?";
						if(rand(100)*sti(pchar.reputation)/50 > 20)   // вероятность отказа от платежей, уменьшите последнюю цифру для меньшего количества отказов
						{
							Link.l5.go = "tax";
						}
						else
						{
							Link.l5.go = "taxevasion";
						}
					}

					link.l6 = "Хм, интересно, можно ли эту постройку " + buildingstr + " улучшить.";
					link.l6.go = "interior";

					if(CheckCharacterItem(PChar,"pistolgrenade") && !CheckCharacterItem(NPChar,"pistolgrenade") )
					{
						link.l7 = "Послушай, на этих островах рыщет куча негодяев, налетчиков, которые наслаждаются грабежом, пытками и изнасилованиями. Может быть, они приходят сюда, и в этом случае вам нужно какое-то последнее средство. Вот, возьми эту гранату...";
						link.l7.go = "grenade";
					}

					link.l8 = "Мне больше не нужен этот фермерский дом. Демонтируйте его, погрузите доски в наш трюм и доложите боцману о судовых обязанностях.";
					link.l8.go = "dismantle";

				}
				else   // если вы НЕ арендодатель
				{
					link.l9 = "Просто проходил мимо...";
					link.l9.go = "exit";
				}

				Link.l10 = B_TEXT[12];
				Link.l10.go = "exit";

				link.l11 = "Эй, почему ты стоишь здесь так неподвижно? " + LinkRandPhrase("Ты проглотил метлу...", "Давай, расслабься немного...", "Я ожидаю немного больше активности от моих жильцов, слышишь?");
				link.l11.go = "motion";

				link.l12 = "Эмм, извините, не хочу мелочиться, но мне это 'здание' кажется немного странным...";
				link.l12.go = "odd";

				link.l13 = "Эй, ты там, перед клавиатурой! Это здание, которое ВЫ создали, так как насчет того, чтобы создать свой собственный диалог? Просто используйте Блокнот, чтобы открыть файл program\dialogs\" " + NPchar.dialog.filename + " перезапишите этот текст своим. Тогда следуйте инструкциям в комментариях.";
				link.l13.go = "your_dialog"; //это тот случай, который запускается, если вы выбираете диалоговую опцию l13. Это прямо внизу.
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
			Dialog.text = "...и если какая-нибудь мразь осмелится войти в мое... э-э-э.. ваше поместье, я разнесу их в пух и прах." ;
			link.l1 = "Вот это дух! Здорово иметь таких верных подданных. Но будь осторожен с теми, кого ты взрываешь..";
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "pistolgrenade" );
			GiveItem2Character(NPchar, "pistolgrenade");
		break;

// добавить интерьер
		case "interior":
			Dialog.text = "О, да, мы могли бы сбросить "+interiorstr+" ,который в настоящее время у нас есть, если вы хотите дать этому строению " + buildingstr + " новые функции. Вы просто должны дать нам "+ GetSquadronGoods(pchar,GOOD_PLANKS) +" досок, "+ pchar.money +" золота и "+ Pchar.Ship.crew.quantity +" людей. Что Вы думаете на счет этого?";
			Link.l1 = "Хм, я не думаю, что я должен вкладывать сюда еще больше.";
			Link.l1.go = "exit";
			Link.l5 = "Роскошная мебель (повышает вероятность успешного лечения ран в домашних условиях; 5 досок, 1000 золота, 1 Человек)";
			Link.l5.go = "luxurious furniture";
		break;

		case "luxurious furniture":
			npchar.interior = "luxurious furniture";
			Dialog.text = "Один " + npchar.interior + " ?";
			Link.l2 = "Верно. Мой помощник выделит вам необходимые ресурсы, и я ожидаю, что вы закончите работу до моего следующего визита. Увидимся!";
			Link.l2.go = "erect";
		break;

		case "erect":
			aref interiornewref;
			Items_FindItem(npchar.interior,&interiornewref);
			planks = sti(interiornewref.building.planks);
			money = sti(interiornewref.building.money);
			crew = sti(interiornewref.building.crew);

			if(money > sti(pchar.money) || crew > sti(Pchar.Ship.crew.quantity) || planks > GetSquadronGoods(pchar,GOOD_PLANKS) )
			{
				Dialog.text = "Хм, " + GetMyAddressForm(NPChar, PChar, ADDR_Polite, false, false) + " один " + npchar.interior + " требует " + planks + " досок, " + money + " золота и "+crew+" людей. Но, как я уже сказал, у нас есть только "+ GetSquadronGoods(pchar,GOOD_PLANKS) +" досок, "+pchar.money+" золота и "+Pchar.Ship.crew.quantity+" людей...";
				Link.l3 = "Упс.. небольшая.. ошибка.. Что ж, значит, тебе придется жить в этом месте как есть..";
				Link.l3.go = "exit";
			}
			else
			{
				DialogExit();
				NextDiag.CurrentNode = NextDiag.TempNode;

				// взять строительные ресурсы
				RemoveCharacterGoods(pchar, GOOD_PLANKS, planks-1 );
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(Pchar, -money);
				Pchar.Ship.crew.quantity = sti(Pchar.Ship.crew.quantity) -crew;
				
				// магазин нового интерьера
				lcn.building.(nr).interior = npchar.interior;
			}
		break;


// случайные атаки
		case "attack1":
			Dialog.text = "Рабы на плантациях восстают. И они уже захватили некоторое оружие! Они так озверели за годы жестокого угнетения, что не пощадят ни одного белого мужчину.. или женщину! О, если бы у нас было побольше тех бастионов, частоколов, мин и пушек...";
			link.l1 = RandSwear() + "Все эти сухопутные парализованы страхом! Избалованные жизнью на суше. Похоже, мне придется сражаться без них.";
			link.l1.go = "exit_attack1";
		break;

		case "attack2":
			Dialog.text = "Кучка грабителей пиратов... ТАМ!!";
			link.l1.go = "exit_attack2";
		break;

		case "Exit_attack1":
		// PB: Чтобы бой не начался до закрытия диалога.
			ChangeCharacterReputation(Pchar, 4);  // награда: репутация. Изменить по своему вкусу
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // награда: опыт. Измените последнюю цифру на свое усмотрение
			Ambush("rabBlack_1", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_attack2":
		// PB: Чтобы бой не начался до закрытия диалога
			ChangeCharacterReputation(Pchar, 4);  // награда: репутация. Изменить по своему вкусу
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // награда: опыт. Измените последнюю цифру на свое усмотрение
			Ambush("Sailors",  3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

// налоги и другие прибыли и вознаграждения
		case "tax":
			npchar.tax = taxdays * 2;	// Вознаграждение налогов, вы можете изменить цифру перед ';' на ваш вкус
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// Влияние репутации на налог, удалите строку, чтобы отключить это

			Dialog.text = "Нам удалось собрать " + npchar.tax + " бушелей пшеницы и "  + npchar.tax + " тюков табака. Экспорт этого принесет нам деньги, которые нам срочно нужны для товаров и инструментов, которые мы не можем производить сами. Хотя местный магазин не купит табак, потому что здешние фермы производят его в изобилии." ;
			link.l1 = "Отлично, мне нужна пшеница, чтобы накормить мою жадную команду. ";
			link.l1.go = "wheat";
			link.l2 = "Я заберу товарный урожай.";
			link.l2.go = "tobacco";
			link.l3 = "Почему " + npchar.tax + " бушелей? Как все это складывается? Не могли бы вы просветить меня, пожалуйста.";
			link.l3.go = "economy";
		break;

		case "wheat":
			npchar.taxcrop = GOOD_WHEAT;
			Dialog.text = "Что? Накормить свою команду? Нашей пшеницей?";
			link.l1 = "Эй, не выходи за рамки своего положения, раб! Это МОЯ ферма и, следовательно, МОЙ урожай.";
			link.l1.go = "tax2";
		break;

		case "tobacco":
			npchar.taxcrop = GOOD_TOBACCO;
			Dialog.text = "О, нет! Ты хочешь ЗАБРАТЬ наш табак?";
			link.l1 = "Эй, не выходи за рамки своего положения, раб! Это МОЯ ферма и, следовательно, МОЙ урожай.";
			link.l1.go = "tax2";
		break;


		case "tax2":
			Dialog.text = RandSwear() + " Извините!," + adress + ", у нас уже другие планы на урожай. Нам удалось собрать " + npchar.tax + " бушелей, и мы уже связались с торговцем, который будет экспортировать его для нас. Как я уже сказал, нам срочно нужен какой-то доход, чтобы покупать товары и инструменты, которые мы не можем производить сами.";
			link.l1 = LinkRandPhrase("*Я* владею этой фермой, поэтому *мне* принадлежит и урожай. Вы, наемные работники, не имеете прав, а только обязанности! ","Для чего вам нужны деньги и товары? И инструменты? Разве у тебя нет рук? В конце концов, я предоставляю вам все, что вам нужно: защиту, материалы, работу.. ","Я возьму это на себя... э-э... позабочусь об этом. Держу пари, покупатель все равно вас обманет, так что в ваших интересах, если я организую продажу для вас.") +" Отправьте все это на мой корабль.";
			link.l1.go = "taxfull";
			link.l2 = LinkRandPhrase("Отличная работа. Я уменьшу арендную плату и оставлю вам половину урожая. Используйте прибыль с умом, чтобы увеличить свое состояние. (И моё тоже..)","Значит, ты усердно работал, да? В награду за это я уменьшу арендную плату и оставлю вам половину урожая на ваш собственный счет.(В надежде, что вы будете работать еще усерднее..)","Послушайте, я оставлю вам половину, чтобы вы могли улучшить свои условия жизни и работы. Я хочу, чтобы мое поместье было достойным и счастливым местом. (Эффективным и прибыльным..)");
			link.l2.go = "taxhalf";
			link.l4 = "Так много? Хм, я должен проверить, достаточно ли места на моем корабле для этого. Было бы немного неприятно, если бы плоды всего вашего тяжелого труда пришлось выбросить бы на пляж из-за отсутствия места для хранения";
			link.l4.go = "exit";
			link.l3 = "Почему " + npchar.tax + "бушелей? Как все это складывается? Не могли бы вы просветить меня, пожалуйста.";
			link.l3.go = "economy";
		break;

		case "taxevasion":
			ChangeCharacterReputation(Pchar, -1);  // наказание: падение репутации. Изменить по своему вкусу

			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			npchar.tax = taxdays * 10;	// Вознаграждение налогов, вы можете изменить цифру перед ';' на ваш вкус
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// Влияние репутации на налог, удалите строку, чтобы отключить это

			Dialog.text = RandSwear() + LinkRandPhrase("О, прошу прощения, милорд, но в последнее время у нас были тяжелые времена: желтая лихорадка поражала нас одного за другим, и мы не могли работать на полях...", "Мне очень жаль, помещик, но в нашем сарае не осталось ни бушеля: буквально прошлой ночью какие-то грабители украли все, что мы хранили для тебя. Вы действительно должны делать больше для безопасности своего имущества...", "Мне неприятно это говорить, ваша светлость, но мы вряд ли проживем здесь в вашем поместье: плохая почва, плохой климат и недавняя засуха уничтожили весь урожай...") ;
			link.l1 = LinkRandPhrase("Что ж, если тебе действительно так тяжело, я не стану усложнять ситуацию еще больше: Я оставлю тебя в должности, но только на этот раз. Потому что я не могу позволить себе слишком часто проявлять слабости, я могу держать свою команду под контролем, только если они уважают меня как крутого парня.", "Хорошо, давайте пропустим этот платеж. Но в следующий раз я не хочу снова слышать никаких оправданий... В конце концов, предполагается,что все ваши сборы предназначены для поддержки моего корабля, и команда не будет рада, если им придется лишиться своей премии", "Хм, нет смысла убивать корову, которую ты хочешь подоить, не так ли? На этот раз я снял вас с крючка, но я ожидаю, что вы возобновите оплату, как только у вас все наладится. Хотя моя команда будет ворчать, что я слишком мягок с вами, сухопутными.") + "";
			link.l1.go = "moraledrop";

			link.l2 = LinkRandPhrase("Оставь это нытье, я слишком часто слышал эти пустые оправдания, чтобы верить им дальше. Ты, наверное, целыми днями спал на стоге сена вместо того, чтобы ухаживать за моими полями, а?  Что ж, если вы не можете оплатить аренду за счет долевого участия, вам придется платить золотом....", "Ленивый ублюдок, ты должен был тратить меньше времени на приставание к своим овцам! Что ж, если вы не можете оплатить аренду за счет долевого участия, вам придется платить золотом...", "Заткнись, плаксивый казнокрад! Ты, наверное, продал все это? Я конфискую ваши деньги. все равно это МОЕ.");
			switch(Rand(5))   // шанс уклонения от уплаты налогов, увеличьте показатель для уменьшения бунтов и самоубийств
			{
			case 1: link.l2.go = "taxsuicide"; break;
			case 2: link.l2.go = "taxrevolt"; break;
			link.l2.go = "taxfine"; break;
			}
		break;

		case "taxhalf":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			AddCharacterGoods(pchar, sti(npchar.taxcrop), sti(npchar.tax)/2);
			ChangeCharacterReputation(Pchar, 1);  // награда: репутация. Изменить по своему вкусу
			Dialog.text = "Это самый щедрый из вас, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + ". Я всем расскажу, какой вы добрый и заботливый хозяин, можете быть в этом уверены!";
			link.l1 = "О, не беспокойтесь, я не так уж забочусь о своей репутации. Кстати, я даю тебе отпуск сегодня вечером. Почему бы тебе не пойти в центр города, не пообщаться с горожанами... Повеселиться!";
			link.l1.go = "exit";
		break;

		case "taxfull":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			AddCharacterGoods(pchar, sti(npchar.taxcrop), sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // наказание: падение репутации. Измените по своему вкусу
			Dialog.text =  RandSwear() + LinkRandPhrase("Ладно, ты владеешь этим поместьем, так что, если ты не хочешь его испортить... Не жалуйся, если ты скоро останешься без рабочих, потому что мы голодали...", "Немного недальновидно выжимать состояние досуха только для того, чтобы увеличить краткосрочную прибыль, если вы спросите меня. Но я полагаю, вы меня НЕ спрашиваете, а? Что ж, у тебя будет арендная плата за место, даже если ты задохнешься от него...", "Ты хочешь снять весь результат всего нашего тяжелого труда? Ну, ТЫ говоришь, что мои.. эээ.. твои рабочие. И не удивляйтесь, если часть урожая попадет в море по пути к вашему кораблю...") ;
			link.l1 = "Хм, интересно, было ли хорошей идеей запятнать мою репутацию и подавить усердие моих работников, забрав все это. ";
			link.l1.go = "exit";
		break;

		case "taxrevolt":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(Pchar, sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // наказание: падение репутации. Изменить по своему вкусу
			Ambush("outlaws", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			Dialog.text =  RandSwear() + "Ну, вот, возьми свою арендную плату за место, ты, капиталистический эксплуататор. Но будь уверен, что замаскированные авангарды революционной ООП предъявят тебе обвинение перед народным трибуналом за это! Фермеры всех островов, объединяйтесь! Долой феодальное иго!";
			link.l1 = LinkRandPhrase("Не пойму твою болтовню, но если ты заплатишь, мне все равно, что ты скажешь.","Что? Организация освобождения пиратов все еще существует? Разве наше правительство не утверждало, что 'освобождение' варварских государств уничтожит их? Что ж, никогда не верьте этим лжецам в государственном доме..","Ааа! Организация освобождения пиратов! Мятеж в моем собственном поместье!");
			link.l1.go = "exit";
		break;

		case "taxsuicide":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			Dialog.text =  RandSwear() + LinkRandPhrase("Что ж, если ты заберешь у меня мое имущество, я заберу и твое тоже! С одной из ТВОИХ гранат! Ирония судьбы, не правда ли? Моя жизнь - не что иное, как плохая шутка..."," Ты - моя погибель! На что я должен жить? Я буду голодать! ... НЕТ! Я не буду! Я лучше умру быстро,с треском, а не со стоном! Где моя пороховая бочка?","Ты разрушил мою жизнь, ты, вампир! Все, что у меня осталось, это этот бочонок рома... Прекрасный крепкий ром, обжигающий твое горло, как адское пламя... Твое место в Аду... ТЫ СЛЫШИШЬ МЕНЯ, КРОВОСОС? АДСКИЙ ОГОНЬ, КОТОРЫЙ ТЫ ПОЛУЧИШЬ! Хе-хе, этот дух горит не только в горле...");
			link.l1 = LinkRandPhrase("Ох, да ладно, теперь ты ДЕЙСТВИТЕЛЬНО драматизируешь..","Эй, что ты задумал? Осторожно, вы можете стать причиной несчастного случая со смертельным исходом..","Ладно, убей себя, если хочешь. Таких лузеров, как ты, легко заменить.");
			link.l1.go = "taxsuicide2";
		break;

		case "taxsuicide2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			Explosion (NPchar, 30);
			Lai_KillCharacter(NPchar);
		break;

		case "taxfine":
			AddMoneytoCharacter(Pchar, sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // наказание: падение репутации. Изменить по своему вкусу
			Dialog.text =  RandSwear() + LinkRandPhrase("Ну вот, возьми свои чертовы деньги. Но не жалуйтесь, если вы скоро останетесь без рабочих, потому что мы голодали...", "Тогда у меня нет другого выбора, кроме как одолжить для тебя деньги у ростовщика. Это означает, что я, вероятно, закончу со сломанной рукой... в ЛУЧШЕМ случае...", "Ладно, ты, пиявка, вот, возьми эти деньги, которые я скопил для своей больной матери.") ;
			link.l1 = "Хм, интересно, было ли хорошей идеей запятнать мою репутацию, настаивая на эти " + npchar.tax + " золотых ";
			link.l1.go = "exit";
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
			Dialog.text = "Ах, ты мне это говоришь... Мне приходится терпеть эти 'странности' моего здания целыми днями! Хуже всего то, что стены настолько потрескались, что люди могут проходить прямо сквозь них. Никакого уединения, даже в моей собственной постели! Во всем виноват убогий архитектор, спроектировавший это, диванный капитан Чарльз. Этот ботаник-программист на самом деле ничего не знает о моделях домов, он только украл несколько дизайнов у Инес Диас и разместил их в самых невозможных местах." ;
			link.l1 = "Эй, прекрати этот вой! Разве не лучше иметь странный дом, чем вообще никакого дома? Вы бы предпочли спать на пляже? Я, со своей стороны, буду наслаждаться достопримечательностями и особенностями моих новых зданий вместо того, чтобы тратить свое время на придирки.";
			link.l1.go = "exit";
			link.l2 = "Вместо того, чтобы жаловаться на других, вы должны заставить свою задницу двигаться и решать проблему самостоятельно. Какова точная причина этого? Я кое-что знаю о моделировании, может быть, я смогу помочь?";
			link.l2.go = "odd2";
			link.l3 = "Не обращайте внимания на внешний вид, что мне не нравится, так это экономическая часть: сумма налогов и прибыли. И частота нападений и событий, наказания.";
			link.l3.go = "tweaking";
		break;

		case "odd2":
			Dialog.text = "Любая помощь будет принята с благодарностью. Некоторые из этих моделей зданий, безусловно, нуждаются в реконструкции. Основная проблема в том, что эти модели зданий не являются частью модели локации, а являются предметами, прикрепленными к стационарным персонажам, таким как я. Поэтому патч для модели местоположения -который не позволяет персонажам проходить сквозь стены- не распространяется на эти новостройки. Что нам нужно, так это патч вокруг строительных предметов. Или вокруг персонажей, к которым прикреплены строительные предметы. Если вы знаете решение этого, опубликуйте его на форуме моддинга PotC по адресу "+PA_INET;
			link.l1 = "Эммм, я подумаю об этом...";
			link.l1.go = "exit";
		break;

		case "tweaking":
			Dialog.text = "Не нужно жаловаться на это. Вы можете настроить это самостоятельно, просто отредактировав текстовый файл. Например, вот как вы можете вдвое сократить мои выплаты вам (хе-хе): Откройте файл 'pirates of the caribbean\program\dialogs\ " + NPchar.dialog.filename + " с помощью текстового редактора, такого как блокнот. Используйте функцию поиска для поиска ключевого слова 'reward'(награда). Это приведет вас к одной или нескольким строкам, подобным этой: ' npchar.tax = taxdays * 10;	// Вознаграждение арендные деньги... '. Замените '10' на '5' для половины моих платежей. (Не ждите, что я расскажу вам, как их ПОДНИМАТЬ ;) ). Точно так же вы можете настроить другие вещи, выполнив поиск ключевых слов 'chance'(шанс) для событий, или 'punishment'(наказание) например потери репутации. Комментарий за '//' расскажет вам, что делает предыдущий код. Чтобы отключить влияние репутации на доход найдите две строчки с комментарием '// reputationinfluence (влияние на репутацию)' и удалите код. Если вам нужна дополнительная информация, напишите на форуме моддинга PotC по адресу" +PA_INET;
			link.l1 = "Эй, спасибо за подсказки. Похоже, моддинг не так уж и сложен,да? Просто требуется немного терпения и самоотдачи. Но если я могу играть в эту игру, то также и смогу немного ее настроить.";
			link.l1.go = "exit";
		break;

		case "economy":
			Dialog.text = "Хорошо, вот небольшой урок по социально-экономической политике вашего поместья: Каждый день ваши работники и арендаторы работают в вашем поместье, откладывают заработанные деньги или накапливают товары. Сколько они сохраняют и хранят, во многом зависит от вашего поведения: довольные люди работают более эффективно, уверенные в себе люди сберегают и хранят на будущее, и если вы относитесь к своим людям достойно и показываете, что можете их защитить, они с большей готовностью отдают вам деньги или товары. В противном случае они расслабляются, присваивают то, что должно быть вашим, или даже восстают. Хорошим показателем является ваша репутация: чем выше ваша репутация, тем выше ваш доход. И наоборот: чем лучше вы ведете себя в своем поместье, тем выше ваша репутация. Поэтому вы должны научиться уравновешивать свою сиюминутную потребность в деньгах и товарах с долгосрочным процветанием вашего поместья. Будь строг, когда должен, и великодушен, когда можешь." ;
			link.l1 = "И вы называете это социоэкономикой? По-моему, это больше похоже на экономическую магию вуду. Или, скорее, диванная экономика. Для чего вам нужны сбережения? Ведь я обеспечиваю тебя всем необходимым: защитой, жильем, едой, работой... Так что будет справедливо... если все твое золото окажется в моей... Э-э... общественной казне.. Это то, что я называю социоэкономикой, научился этому у действительно умного парня Карла Маркса!";
			link.l1.go = "taxfull";
			link.l2 = "Я понимаю... Послушай, я оставлю тебе половину твоих сбережений, чтобы ты мог улучшить свои жилищные и рабочие условия. Я хочу, чтобы мое поместье было достойным и счастливым местом. (Эффективным и прибыльным..)";
			link.l2.go = "taxhalf";
			link.l3 = "Мне это не нравится. Я бы пожертвовал этим налоговым платежом за информацию о том, как настроить этот мод по своему вкусу. Все эти события и влияния просто не подходят моему стилю игры.";
			link.l3.go = "tweaking";
		break;

		case "motion":
			Dialog.text = LinkRandPhrase("Оу, я так трепещу от твоего присутствия, что не смею пошевелиться.", "Чувак, я весь день работаю, у меня все кости болят, и я не позволю тебе лишить меня заслуженного отдыха.", "Вы не поверите, но мне приходится поддерживать все здание. Оно рухнет, если я пошевелю хотя бы мизинцем...");
			link.l1 = "Хорошо, я понимаю... До свидания.";
			link.l1.go = "exit";
		break;

// enc_resident stuff: исцеление, проведение времени и т. д. 
		case "chat":
			dialog.text = B_TEXT[17];
			Link.l4 = B_TEXT[12];
			Link.l4.go = "exit";
			Link.l1 = B_TEXT[18];
			Link.l1.go = "chat2";
		break;

		case "chat2":
			dialog.text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) );

			if (makeint(environment.time) >= 22.0 || makeint(environment.time) < 10.0)
			{
				Link.l1 = B_TEXT[22];
				Link.l1.go = "hall_day_wait";
			}
			else
			{
				Link.l1 = B_TEXT[23];
				Link.l1.go = "hall_night_wait";
			}
		break;

		case "heal":
			Dialog.text = B_TEXT[20];
			Link.l1 = B_TEXT[21];
			if (rand(100) + makeint(pchar.skill.Sneak) >= 35 || interiorstr=="luxurious furniture") {Link.l1.go = "exit recovered";}
			else {Link.l1.go = "exit infected";}
			Link.l3 = B_TEXT[24];
			Link.l3.go = "exit";
		break;

		case "infected":
			Dialog.text = LinkRandPhrase(B_TEXT[25], B_TEXT[26], B_TEXT[27]); 
			int winlink = rand(100) 
			if (winlink >= 50) 
			{
				Link.l1 = LinkRandPhrase(B_TEXT[38], B_TEXT[39], B_TEXT[40]);
				Link.l1.go = "exit recovered"
			}
			Link.l2 = LinkRandPhrase(B_TEXT[41], B_TEXT[42], B_TEXT[43]);
			Link.l2.go = "exit infected";
			Link.l3 = LinkRandPhrase(B_TEXT[44], B_TEXT[45], B_TEXT[46]);
			Link.l3.go = "exit infected";
			if (winlink < 50) 
			{
				Link.l4 = LinkRandPhrase(B_TEXT[38], B_TEXT[39], B_TEXT[40]);
				Link.l4.go = "exit recovered"
			}
			Link.l5 = B_TEXT[47];
			Link.l5.go = "exit";
		break;


		case "hall_day_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			TavernWaitDate("wait_day");
			PlaySound("VOICE\ENGLISH\Eng_m_a_013.wav");
			Log_SetStringToLog("Вы болтаете часами и многому учитесь.");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 50+(sti(PChar.skill.Leadership)*10)+Rand(50) ); }
			else { AddPartyExp(PChar, 50+(sti(PChar.skill.Leadership)*10)+Rand(50)); }
		break;

		case "hall_night_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			TavernWaitDate("wait_night");
			PlaySound("VOICE\ENGLISH\Eng_m_a_014.wav");
			Log_SetStringToLog("Вы болтаете часами и многому учитесь.");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 50+(sti(PChar.skill.Leadership)*10)+Rand(50) ); }
			else { AddPartyExp(PChar, 50+(sti(PChar.skill.Leadership)*10)+Rand(50)); }
		break;

		case "exit recovered":
			Dialog.text = B_TEXT[48];
			Link.l1 = LinkRandPhrase(B_TEXT[49], B_TEXT[50], B_TEXT[51]);
			Link.l1.go = "exit recovered2";
		break;

		case "exit recovered2":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			pchar.chr_ai.poison = 0;
			pchar.chr_ai.hp_max = sti(pchar.chr_ai.hp_max) + 1;
			LAi_SetCurHPMax(pchar);
			LAi_Fade("", "");
			WaitDate("", 0,0,1,0,0);
			RecalculateJumpTable();
			PlaySound("AMBIENT\SHOP\sigh2.wav");
			Log_SetStringToLog("Через 24 часа вы снова в форме, даже сильнее, чем раньше.");
			Log_SetStringToLog("+ 1 max HP");
			Log_SetStringToLog("Вы многое узнали о лечении ран.");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Defence", 50+(sti(PChar.skill.Defence)*10)+Rand(50) + grgbonus ); }
			else { AddPartyExp(PChar, 50+(sti(PChar.skill.Defence)*10)+Rand(50) + grgbonus ); }
		break;

		case "exit infected":
			Dialog.text = B_TEXT[48];
			Link.l1 = LinkRandPhrase(B_TEXT[49], B_TEXT[50], B_TEXT[51]);
			Link.l1.go = "exit infected2";
		break;

		case "exit infected2":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			if (makeint(environment.time) < 22.0 && makeint(environment.time) >= 10.0) TavernWaitDate2("wait_day"); //  NK чтобы поймать, если не ночь
			TavernWaitDate("wait_day"); // NK таким образом, происходит затухание
			pchar.chr_ai.poison = 20 + rand(50 -sti(PChar.skill.Sneak) -sti(PChar.skill.defence) );
			grgbonus = 200+Rand(200)
			PlaySound("OBJECTS\DUEL\man_hit6.wav");
			Log_SetStringToLog("Вы просыпаетесь с ощущением лихорадки.");
			Log_SetStringToLog("Твои раны горят, как огонь!");
		break;

// диалоговые окна
		case "moraledrop":
			ChangeCharacterReputation(Pchar, 3);  // награда: репутация. Изменить по своему вкусу

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
