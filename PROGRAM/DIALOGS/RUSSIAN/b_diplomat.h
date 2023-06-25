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
	
	string natname = GetNationNameByType(sti(npchar.nation));

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
		dialog.text = "Ах, мой дорогой "+ GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname +  "! Наконец-то я лично встречаюсь с героем, о котором так часто слышал! Разумеется, только самые благоприятные истории. Весть о ваших героических подвигах достигла высших кругов при дворе " + natname + ", который был настолько впечатлен вашим характером, что даже " + GetNationRoyalByType(sti(npchar.nation)) + " выразил желание преодолеть.. эээ... небольшие недоразумения, которые... эээ... омрачили отношения между " + natname + " и тобой. Так что давайте забудем прошлое и отправимся в светлое общее будущее. Если вы готовы сражаться за нашу гордую и великодушную нацию, мы предоставим вам амнистию и королевскую каперскую грамоту. А учитывая ваше лидерство и боевые НАВЫКИ, мы даже предлагаем вам сумму " + npchar.bribe + " золота!";

		if(sti(pchar.money)>sti(npchar.bribe))
		{
			link.l1 = "Что? Ты думаешь, что сможешь купить меня? За кого ты меня принимаешь? Мне не нужны ваши грязные взятки, я презираю такие мелкие суммы. Вот, возьми " + npchar.bribe + " Золотых монет от МЕНЯ, отнесите их вашему величеству и скажите ему, чтобы он засунул их в свою королевскую задницу. Я уверен, что вы найдете дипломатический способ сделать это, да? А теперь убирайся с моих глаз!";
			link.l1.go = "exit_reput";
		}

		link.l2 = "Что? Ты думаешь, что сможешь купить меня? За кого ты меня принимаешь? За Предателя? Головореза по найму? Что ж, вы пришли по правильному адресу " + XI_ConvertString(PChar.sex) + ". Большое спасибо за деньги, и низкий поклон " + GetNationRoyalByType(sti(npchar.nation)) + ". Скажи ему, что специально для него я потоплю несколько кораблей. До свидания.";
		link.l2.go = "exit_change";

		link.l3 = "Ммм, я боюсь, что моя нынешняя работа... эээ... моя любимая родина, я имею в виду, не будет рада, если я перейду на другую сторону. И я не могу позволить испортить себе отношения с " + GetNationNameByType(GetServedNation()) + " до вражеских. Также я должен думать о своей репутации. Так что сегодня сделки нет, извини. ";
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
