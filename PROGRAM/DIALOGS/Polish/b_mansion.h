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
	
	if( !CheckAttribute(npchar, "enemynation") ) npchar.enemynation = FindEnemyNation2Character(GetMainCharacterIndex());
	int isnat = sti(Islands[GetCharacterCurrentIsland(Pchar)].smuggling_nation);
	string isnatname = GetNationNameByType(isnat);

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
	if(NPChar.chr_ai.group==LAI_GROUP_PLAYER ){adress = " my landlord ";}else{adress = " " + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " ";}
	
	ref chr;
	float x,y,z;
	
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

			if(rand(100)<15) // chance for random attack, decrease last figure for fewer attacks
			{
				PlayStereoSound("voice\ENGLISH\Eng_f_c_019.wav");
				ChangeCharacterReputation(Pchar, -2);  // punishment: reputationloss. Will be offset if you accept the fight	
				Dialog.text =  LinkRandPhrase("Dzi×kowaŢ Bogu, že ty tutaj jeste›! Možesz nas obroniŢ od tych brutali..", "Ahh, niebiosa przesłały ciebie w najbardziej kluczowym momencie: za nie długo b×dziemy zaatakowani. POMÓž NAM!", "Miło ciebie spotkaŢ, ale mam pro›b×, my potrzebujemy wojownika " + GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false) + " jak ty aby odrzuciŢ to zło...");
				link.l1 = LinkRandPhrase("Hey, wyluzij! No, No, ty juž si× trz×siesz ze strachu... Možesz mi powiedzieŢ teraz co si× tutaj dzieje.","Nie martw sie, niewažne jakie to jest zagroženie, Ja uchronie moją posia.. err.. ludzi. Co ciebie dr×czy?","Shh.. Wyluzuj, Nie masz si× czego bac tak długo gdy tutaj jestem (i zapłacisz moje rachunki). Wi×c jak tam?");
				if(interiorstr=="boudoir")
				{
				  if(rand(100)>50 && IsBrothelEnabled()) {Link.l1.go = "gentry1";}
				  else{Link.l1.go = "monks1";}
				}				
				else
				{
				  if(rand(100)>70) {Link.l1.go = "Akellani";}
				  else{Link.l1.go = "commando";}
				}
				link.l9 = "Oh, no weź, kobieto, nie strzelaj focha za jakie› plotki, które usłyszała›? Mam wažniejsze sprawy do wykonania i nie chc× byŢ zakłócany przez głupie plotki!";
				link.l9.go = "exit";
			}
			else
			{	
        PlayStereoSound("voice\ENGLISH\Fre_f_a_005.wav");
				Dialog.text = "Wiiitaj, Kapitanie. Miło ciebie widzieŢ znowi..";
				if(CheckAttribute(pchar,"chr_ai.poison") && pchar.chr_ai.poison > 0)
				{
					Link.l1 = "Oh, Czuje si× okropnie! Gorączka, spuchni×te nogi, krwiaki koło moich ran... Boj× si×, že mam gangrene!";
					Link.l1.go = "infected";
				}

				if(NPChar.chr_ai.group==LAI_GROUP_PLAYER) // if you are the landlord
				{
					if(interiorstr=="office")
					{
 				    link.l32 = "Tak, tak, Bardzo dzi×kuje. Mieli›my jaki› go›ci lub otrzymali›my jakie› wiadomo›ci?";
            link.l32.go = "office";
 				    link.l31 = "Haloooo, Panno Moneycent. Miło CIEBIE znowu spotkaŢ! Jestem naprawd× zadowolony, že ty i Q odszedli›cie z tajnej słužby by pracowaŢ dla mojej prywatnej agencji.";
					  link.l31.go = "office1";
				  }

					if(interiorstr=="boudoir")
					{
	   				if(taxdays>0)
	   				{
  					link.l5 = "Cze›Ţ kochanie. Przyszedłem zbieraŢ twoje pieniądze za dywidendy mojej inwestycji w twoim przedsi×biorstwie. Il× zarobiłe› przez " + taxdays + " dni od ostatniej zapłaty?";
  					if(rand(100)*sti(pchar.reputation)/50 > 20)   // chance for a refusal of payments, decrease last figure for fewer refusals
				  	{Link.l5.go = "tax";}
  					else{Link.l5.go = "taxevasion";}
 				    link.l32 = "Mam problem z załogą, i gdyž masz dužo.. err.. kontaktów z žeglarzami, može b×dziesz mógł mi pomóc.";
            link.l32.go = "crew";
					  link.l31 = "Cze›Ţ 'Panno Monique' *WINK*. Przyniosłasz dužo ciekawych mebli oraz broderie z moich pieni×dzy. Mam nadziej×, že moja inwestycja nie poszna na marn× žeđskie bezcenne fabianki. Zazwyczaj ty potrzebujesz tylko kup× słomy by zgiąŢ twoją transakcj×. Przez co b×dzie łatwiej wyczy›ciŢ niž wszystkie te aksamity i dywany.";
            link.l31.go = "frills";
            }
				  }

					if(CheckCharacterItem(PChar,"pistolgrenade") && !CheckCharacterItem(NPChar,"pistolgrenade") )
					{
					link.l7 = "Posłuchaj mnie, Wiele drani i przest×pstwów plaguje karaibskie kolonie, najeźdźcy uwielbiają plądrowaŢ, torturawaŢ i gwałciŢ. Mogą tutaj przybyŢ, i w tym wypadku potrzebujesz ostatniej deski ratunku. Prosz×, weź ten granat...";
					link.l7.go = "grenade";
					}

					link.l8 = "Ja juž nie mam užytku z tej budowli. Powiedz r×kom, które ci odłączyłem, aby to rozebrały, załadowały deski do ładowni i zgłosiły si× do bosmana do obowiązków na statku.";
					link.l8.go = "dismantle";

				}
				else   // if you are NOT the landlord
				{
					link.l9 = "Tylko si× rozglądam... ";
					link.l9.go = "exit";
				}

				Link.l2 = B_TEXT[8];
				Link.l2.go = "heal";

				Link.l4 = LinkRandPhrase(B_TEXT[9], B_TEXT[10], B_TEXT[11]);
				Link.l4.go = "chat";

				Link.l10 = B_TEXT[12];
				Link.l10.go = "exit";

				link.l11 = "Hey, Dlaczego ty stoisz w takim bezruchu? " + LinkRandPhrase("Czy ty połknąłe› miotł×?...", "No weź, troch× si× rozliźnij...", "Ja oczekuje troch× aktywno›ci z mojego mieszkania, rozumiesz?");
				link.l11.go = "motion";

				link.l12 = "Umm, Przepraszam, Nie chc× žeby› si× czuł pomniejszony, ale ten 'budynek' jest troch× dziwny według mnie...";
				link.l12.go = "odd";

				link.l13 = "Hey, ty za klawiaturą! To jest budynek, który TY stworzyłe›, wi×c co powiesz o stworzeniu swojego dialogu? Po prostu užyj Notepada by otworzyŢ plik program\dialogs\ " + NPchar.dialog.filename + " i nadpisał swoim własnymi słowami. Wtedy podąžaj za komentarzami dalej.";
				link.l13.go = "your_dialog"; //this is the case that runs if you choose the dialogoption l13. It is right below.
			}
		break;
                
		case "your_dialog":
			Dialog.text = "Nadpisz ten plik dialogowy dla NPC." ;

			link.l1 = "Tekst gracza link.l1, który kođczy dialog.";
			link.l1.go = "exit";	// link l1 exits the dialog

			link.l2 = "Tekst gracza link.l2,który dodaje kolejny dialog ";
			link.l2.go = "your_dialog2";	// l2 leads to the case your_dialog2
		break;	// end of case "your_dialog"
                
		case "your_dialog2":
			Dialog.text = "Nadpisz ten plik dialogowy dla NPC." ;

			link.l1 = "Tekst gracza link.l1, który kođczy dialog";
			link.l1.go = "exit";	// link l1 exits the dialog

			// Here are some codelines that give you money, items, goods or experience. To activate them delete the comment slashes '//' in front of the code. You can change the amounts to your liking.

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


		break;	// end of case "your_dialog2"

// give grenade to building for selfdefense                
		case "grenade":
			Dialog.text = "...i ježeli jakikolwiek drađ tutaj przejdzie na moj.. err.. twoją posiadło›Ţ, Squire, To ja ich wysadz× prosto do nieba." ;
			link.l1 = "Takiego ducha walki trzeba! Miło słyszeŢ o lojalno›ci moich przedmiotów. Ale bądz ostorožny, kogo wysadzasz w powietrze..";
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "pistolgrenade" );
			GiveItem2Character(NPchar, "pistolgrenade");
		break;




// random attacks
		case "monks1":
			dialog.text = "Wielu pastorów ostatnio si× zgromadziło i utworzyli dužą fanatyczną sekt× na tej wyspie poprzez głoszenie ognia i siarki. Na jego ostatnim kazaniu mówił že jeste›my tutaj z powodu rozłamki žółtej gorączki, nazywając to 'grzesznym zachowaniem'. On podniecił tłum swoich zwolenników, i ja si× boj×, že oni spalą naszą posiadło›Ţ.";
			Link.l4 = "Oh, taki typ zazwyczaj szanuje prywatne posiadło›ci, nie chc× zniszczyŢ naszych darowizn od innych. I ježeli b×dą tobie groziŢ to po prostu udawaj, že płaczesz. Pokaž im troch× gołego ciała to troch× ich 'fanatycyzm' wypłynie z nich na długą moment, wow, že rzucisz swoje grzeszne žycie i podąžasz za nimi WSZ×DZIE!. Ci hipokryci z ogniem i siarką są ch×tni do okazywania skruchy w dziewczynach, po prostu graj, a wszystko b×dzie dobrze. Jak každy polityk može wam powiedzieŢ, lepiej nie krzyžowaŢ si× z religijnymi grupami nacisku. A ja po prostu nie mog× sobie pozwoliŢ na publiczne kojarzenie si× z tobą, wi×c lepiej zostawi× ci× teraz. Niech Bóg b×dzie z tobą.";
			Link.l4.go = "exit";
			Link.l1 = "Ja po prostu nie znosz×, kiedy tak zwani gorliwi chrze›cijanie uzywają religii jako wymówki do wywoływania m×ki nad innymi. Ci, którzy biją innych Biblią, tak naprawd× nie zrozumieli lekcji ewangelii!";
			Link.l1.go = "monks";
		break;

		case "monks":
			Dialog.text = "Oh, oh! Oni tutaj są... 'Wyznawcy Czy›Ţca', wypełnieni cytatami biblijnymi i nienawi›cią!";
			link.l1 = RandSwear() + "Well, I'll teach them the gospel my way!";
			link.l1.go = "exit_monks";
		break;

		case "Exit_monks":
		// PB: To prevent the fight from starting before the dialog is closed
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking
			Ambush("monks", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "gentry1":
			dialog.text = "Miejscowa szlachta wiejska ma dzi› wielkie wydarzenie towarzyskie: idą na polowanie na lisy. Przynajmniej tak mówią swoim žonom, ale wła›ciwie cała ekipa my›liwska przyježdža tu, by sp×dziŢ dzieđ z moimi dziewczynami. Jak dotąd idealny dzieđ dla wszystkich zainteresowanych, ale ci zdeprawowani szlachcice bardzo lubią przemoc i upokorzenia. Jedną z ich ulubionych gier jest „polowanie na suki”: dziewczyna jest ›cigana do džungli, a potem cała ekipa konna idzie za nią ze sforą psów gođczych. A kiedy ją łapią, ponižają ją i maltretują WSZYSTKIM, w co są wyposaženi jeźdźcy i psy gođcze, je›li možesz sobie wyobraziŢ, co mam na my›li.";
			Link.l4 = "Lepiej žebym sobie tego nie wyobražał, bo nie b×d× mógł dzi› spaŢ w nocy... oczywi›cie z powodu moralnego oburzenia! Dam lekcj× tym zdeprawowanym szlachcicom. Každa kobieta z mojej posiadło›ci ma byŢ traktowana z szacunkiem i uprzejmo›cią, bez wzgl×du na zawód, jaki ma! ";
			Link.l4.go = "gentry";
			Link.l1 = "Przykro mi za tą biedną dziewczyn×, ale takie jest ryzyko twojego zawodu, eh? Jestem pewien, že panowie dobrze zapłacą odszkodowanie. A ja po prostu nie mog× sobie pozwoliŢ na obražanie lokalnej społeczno›ci przez psucie im imprez. Tally ho!";
			Link.l1.go = "exit";
		break;

		case "gentry":
			Dialog.text = "Oh, oh! Nadchodzą... Samo zdeklarowana lokalna szlachta. Próbująca poprawiŢ swój status społeczny poprzez ujarzmienie i nadužycia!";
			link.l1 = RandSwear() + "Cóž, pokaž× im, že narodzeni ze złotą łyžką w ustach nie daje im prawa do traktowania zwykłych ludzi jak ›mieci!";
			link.l1.go = "exit_gentry";
		break;

		case "Exit_gentry":
		// PB: To prevent the fight from starting before the dialog is closed
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking
			Ambush("Rich_Citizens", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Akellani":
			Dialog.text = "Za późno! Nadchodzą... dzicy kanibale Akelanni! Oh, gdyby›my mieli wi×cej bastionów, palisad, miny i armat...";
			link.l1 = RandSwear() + "Wszystkie szczury lądowe są sparaližowane w strachu! Straceni z žycia lądowego. Wygląda na to, že b×d× trzeba walczyŢ bez nich pomocy w przyszło›ci.";
			link.l1.go = "exit_akellani";
		break;

		case "Exit_akellani":
		// PB: To prevent the fight from starting before the dialog is closed
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking
			Ambush("natives", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "commando":
			Dialog.text = "Oh, na Boga, ty sprowokowałe› swojego arcywroga " + GetNationNameByType(sti(npchar.enemynation)) + " o jeden raz za dužo! Oni wysłali partol komandosów by ciebie wyniszczyŢ jak robaka! " +  RandSwear() + " Komandosi nie biorą wi×źniów, oni zabiją nas wszystkich!";
			link.l1 = RandSwear() + "So their soldiers are finally attacking me instead of standing by if I stroll into their towns? Must be a bunch of overmotivated newbies. They won't last long!";
			link.l1.go = "exit_commando";
		break;

		case "Exit_commando":
		// PB: To prevent the fight from starting before the dialog is closed
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking
			Ambush(SelectSoldierModelByNation(sti(npchar.enemynation), "Soldier"),  3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

// taxes and other profits and rewards
		case "tax":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			npchar.tax = taxdays * 50;	// Reward taxmoney, you can change the figure before the ';' to your liking
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// Reputationinfluence on tax, delete line to disable that 
			if(interiorstr=="marketstall") npchar.tax = sti(npchar.tax)*2;

			Dialog.text = "Co? " + taxdays + " dni juž przemin×ło? No dobra, Udało mi si× zaoszcz×dzic " + npchar.tax + " złota.";
			link.l1 = LinkRandPhrase("Dzi×kuj×, bardzo jestem zobowiązany do ciebie. Cóž, miło było ciebie poznaŢ ale musz× teraz i›Ţ. Do nastepnego razu *WINK* ","Na co potrzebujsz teraz oszcz×dno›ci? W kođcu załatwiłem to co dla ciebie potrzebne: ochron×, mieszkanie, jedzenie, praca.. Wi×c jedynie uczciwie, že całe twoje złoto błąkają si× w moich.. err.. kufrach na czarną godzine.","Ja.. err.. zajm× si× tym. Inaczej jaki› gówniarz može tobie podebraŢ z twojej kieszeni, wi×c najlepiej by było, žeby te pieniądz× były u mnie przetrzymywane u dobroczynnego skarbnika, któremu ufasz.");
			link.l1.go = "taxfull";
			link.l2 = LinkRandPhrase("Dobra robota. Zostawie połow× tobie. Užyj tej fortuny, aby zarobiŢ wi×cej. (oraz dla mnie tež zarób..)","Wi×c ci×žką praca była, eh? Jako nagrode za twoją prac×, zostawiam tobie połow× pieni×dzy.(Z nadzieją, že b×dzie takie same t×po pracy u ciebie..)","Posłuchaj mnie teraz uwažnie, Zostawiam tobie połowe, aby› kupił ›wiežą smoł×, i može troch× beczek na kosmetyki Doctora Maturina. Chc×, žeby moja posiadło›Ţ była czystym i zdrowym miejscem. (Oraz žeby była efektywna i cenna..)");
			link.l2.go = "taxhalf";
		break;

		case "taxevasion":
			ChangeCharacterReputation(Pchar, -1);  // punishment: reputationdrop. Change figure to your liking

			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			npchar.tax = taxdays * 50;	// Reward taxmoney, you can change the figure before the ';' to your liking
			npchar.tax = makeint( sti(npchar.tax) * sti(pchar.reputation)/50 );	// Reputationinfluence on tax, delete line to disable that 
			if(interiorstr=="marketstall") npchar.tax = sti(npchar.tax)*2;

			Dialog.text = RandSwear() + LinkRandPhrase("Oh, przepraszam, Mój Panie, ale ostatnio czasy były trudne: kiła ostatnio nas uderza i zakarza každego na raz, nie mogli›my zarobiŢ žadnych pieni×dzy i wydali›my wszystkie oszcz×dno›ci na lekarstwa...", "Ja okropnie przepraszam, Giermku, nie mam žadnych pieni×dzy w moich kieszeniach: ostatniej nocy złodziej ukradł wszystko i nie mam žadnych oszcz×dno›ci dla ciebie. Ty naprawd× musisz zwi×kszyŢ ochron× swoich posiadło›ci...", "Nie lubie tego mówiŢ, Wasza Wysoko›Ţ, ale paru gówniarzy juž mnie zabrali.. err.. i wzieli mnie pod opiek× u swojego Pana. Próbowałem odmówiŢ, ale on jest okrutny. Zobacz sam co zrobił moimi r×koma, on je połamał...") ;
			link.l1 = LinkRandPhrase("No cóž, ježeli sytuacja jest až taka ci×žka to nie dodam tobie wi×cej problemów: Odpuszcz× twoje długi, ale tylko ten jeden raz. Poniewaž nie mog× ukazywaŢ takiej słabo›ci, ja mog× kontrolawaŢ moją sytuacje z załogą tak długo, gdy mnie podziwiają jako nieust×pliwego kapitana.", "No dobra, przeskoczmy TĄ zapłat×. Ale nast×pnym razem, nie b×d× dawaŢ miejsca na žadne wymówki...Przeciež wszystkie twoje składki mają wesprzeŢ mój statek, a załoga nie b×dzie zadowolona, je›li b×dzie musiała straciŢ premi× .", "Hmm, nie ma powodu, žeby zabijaŢ krow×, którą chcesz wydoiŢ, co nie? Ja tobie odpuszcz× tym razem, ale ja b×d× oczekiwaŢ zapłaty do czasu gdy wszystko wróci do ciebie do normy. Aczkolwiek moja załoga b×dzie troch× marudziła gdyž oni mówią, že miłosierny za bardzo jestem wobec was.");
			link.l1.go = "moraledrop";

			link.l2 = LinkRandPhrase("Zaprzestađ tego marudzenia, Ja wystarczająco cz×sto słysz× pustych obietnic aby w nie uwierzyŢ. ZapłaciŢ tu i teraz.", "No dawaj, nie przesadzaj! To ciebie nie zabije... Ja tylko domagam si× tego co jest dla mnie zasłužone, nic wi×cej, ale tež nie za mało.", "Zamknij sie, ty wyjąca kurwo! To albo zapłacisz mi albo b×dziesz pracowaŢ w pirackiej ładowni.");
			switch(Rand(5))   // chance for taxevader backing down, increase figure for less revolts and suicides
			{
			case 1: link.l2.go = "taxsuicide"; break;
			case 2: link.l2.go = "taxrevolt"; break;
			link.l2.go = "taxfull"; break;
			}
		break;

		case "taxhalf":
			AddMoneytoCharacter(Pchar, sti(npchar.tax)/2 );
			ChangeCharacterReputation(Pchar, 1);  // reward: reputation. Change figure to your liking
			Dialog.text = "Jeste› bardzo szczodrobliwym kapitanem, " + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + ". Ja powiem wszystkim jaki jeste› takim dobrym gów.. err.. protektorem, Mog× tobie to zagwarantowaŢ!";
			link.l1 = "Oh, nie zawracaj sobie głowy tym, mnie až tak mocno na reputacji niezaležy. Tak po drodze, daj× tobie wolną noc od pracy. Czemu nie pójdziesz do ›ródmie›cia, zabawiŢ si×, pogadaŢ z mieszkađcami...Miłej zabawy!";
			link.l1.go = "exit";
		break;

		case "taxfull":
			AddMoneytoCharacter(Pchar, sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // punishment: reputationdrop. Change figure to your liking
			Dialog.text =  RandSwear() + LinkRandPhrase("Dobra,masz, oto są twoje jebane pieniądze. Ale potem, žeby nie było jaki› tam skarg z twojej strony gdy wkrótce nie b×dziesz miał žadnych dziewczyn, poniewaž my umieramy z głodu...", "W takim razie nie mam innego wyboru, b×d× musiał požyczyŢ od twojego lichwiarza pieniądze. I to prawdopodobnie oznacza, že to si× z skođczy kolejnym złamaniem r×ki... w NAJLEPSZYM wypadku...", "No dobra, ty pijawko, prosz×, weź te pieniądze, które udało mi si× zaoszcz×dziŢ na lekarstwa dla mojej chorej matki.") ;
			link.l1 = "Hmm, zastanawiam si×, czy to był dobry pomysł na zrujnowanie sobie reputacje dla " + npchar.tax + " sztuk złota ";
			link.l1.go = "exit";
		break;

		case "taxrevolt":
			AddMoneytoCharacter(Pchar, sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // punishment: reputationdrop. Change figure to your liking
			Ambush("Liz1", 6+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			Dialog.text =  RandSwear() + "Dobra, prosz×, bierz swoje pieniądze, ty pieprzony smarkaczu. Ale bądź kapitanie pewien, že moje siostry z kobiecego ruchu ciebie dorwią, za traktowanie kobiet w taki sposób!";
			link.l1 = RandSwear() + " Widocznie nie možna byŢ w tych czasach szowinistą m×ską ›winą! Wi×c, kochana, zasługuje na surową kar×. Chociaž, musz× wyznaŢ prawd×, že b×d× oczekiwał tej surowej kary w przyszło›ci z twoich własnych rąk...";
			link.l1.go = "exit";
		break;

		case "taxsuicide":
			Dialog.text =  RandSwear() + LinkRandPhrase("Wi×c, ježeli zabierzesz wszystkie moje dobytki to ja tež zabior× od ciebie! z jednych TWOICH granatów! Co za ironia, co nie? Moje žycie to nic wi×cej jak žart...","Jeste› moją ruiną! Z czego mam teraz zyŢ? Ja umr× z głodu! ... NIE! Nie umr×! Ja umr× szybko, z hukiem, a nie z j×czeniem! Gdzie jest moja beczka z prochem?","Ty jebany wampirze, zniszczyłe› moje žycie! Została mi tylko beczka rumu... Bardzo silnego rumu, płonie w twoim gardle jak ogieđ piekielny... Piekła, tam gdzie powiniene› byŢ... SŁYSZYSZ MNIE, TY PIJAWKO? TY DOSTANIESZ SI× DO PIEKŁA! Hehe, ta dusza pali nie tylko w gardle...");
			link.l1 = LinkRandPhrase("Oh, prosz× ciebie, teraz ty NAPRAWD× sprzesadzasz..","Hey, co ty wyprawiasz? Ostrožnie, ty možesz spowodowaŢ ›miertelny wypadek..","Dobra, zabij si× jak ci si× to podoba. Frajerów možna łatwo zastąpiŢ..");
			link.l1.go = "taxsuicide2";
		break;

		case "taxsuicide2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			Explosion (NPchar, 30);
			Lai_KillCharacter(NPchar);
		break;


// dismantling of this building
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

// info about modding                
		case "odd":
			Dialog.text = "Ah, no co ty nie powiesz... Ja  musze znie›Ţ te 'dziwaczno›ci' w moim domy cały czas! Najgorsza rzecz jest taka,že ›ciany są tak poniszczone, že ludzie mogą przez nie przechodziŢ. Nie mu cholernej prywatno›ci, nawet w moim łóžku! To wszystko wina tego žałosnego architekta, który to stworzył, Couchcaptain Charles. Ten maniak od kodu nic nie wie o modelowaniu domów, on tylko ukradł par× szkiców od Inez Diaz i połožył je w bardzo niemožliwych miejscach." ;
			link.l1 = "Hey, przestađ marudziŢ! Nie jest lepiej, žeby był taki dom niž nic? Bardziej wolałby› spaŢ na plažy? Z mojej strony, ciesz× si× nowymi widoki oraz dodatkami zamiast marnowaŢ czas na czepianie si× o byle co.";
			link.l1.go = "exit";
			link.l2 = "Može zamiast oskaržaŢ innych, powiniene› ruszyŢ swoją dup× i sam rozwiązaŢ te problemy. Co jest tego przyczyną? Ja co› tam wiem o tworzeniu modelów , može ja pomog×?";
			link.l2.go = "odd2";
			link.l3 = "WaliŢ wygląd, ja nie lubie tylko cz×›ci ekonomicznej: liczba dochodów i podatków. Oraz cz×stotliwo›Ţ walk i wydarzeđ, ukrania..";
			link.l3.go = "tweaking";
		break;

		case "odd2":
			Dialog.text = "Každa pomoc b×dzie doceniana. Par× modułów budowlanych z pewno›cią podlegają ponownego wytworzenia. Peoblem polega na tym, že te budowle nie są cz×›cią modułu lokalizacyjnego tylko przedmiotami dołączonymi to stojącej postaci, jak ja. Przez co łatka od chodzenia w module lokalizacji -która pozwala na bezruch postaci z budynkami- nie pokrywa tych nowych budowli. Co my potrzenujemy to łatka od chodzenia dla tych budowlanych przedmiotów. Albo wokół tych postaci co mają przypisane te budowlane przedmioty. Gdyby› ty znalazł pomysł na załatwienie tych problemów, prosz× wstaw na ten temat posta na forum PotC (P.S od Jacob: Napisz posta w j×zyku angielskim)"+PA_INET;
			link.l1 = "Ummm, Pomy›l× o tym...";
			link.l1.go = "exit";
		break;

		case "tweaking":
			Dialog.text = "Nie ma co narzekaŢ. Možesz sam to edytowaŢ w notatku. Na przykład: tutaj može zmieniŢ liczb× pieni×dzy lub skróciŢ mi połow× pieni×dzy dla ciebie (hehe): Otwórz plik 'pirates of the caribbean\program\dialogs\ " + NPchar.dialog.filename + " ' z edytorem tekstu jak notatnik. Užyj funkji 'Znajdź' by znaleźŢ słowo 'reward'. To ciebie skieruje do jednego lub kilka linii kodu które są podobne do tego: ' npchar.tax = taxdays * 10;	// Reward rentmoney,...  '. Zamieđ z  '10' na '5' by zapłaciŢ tobie połow×. (Nie oczekuj odemnie, že tobie powiem jak je podnie›c ;) ). Može w taki sam sposób zamieniŢ inne rzeczy np. 'chance' na szanse odkrycie lub wydarzenia czego› dobrego lub 'punishment' dla np. utrat× reputacji. Komentarz pod takimi znakami '//' podwójny uko›nik powie ci co ten dany kod(P.S od Jacob: Musisz znaŢ angielski aby zrozumieŢ komentarze). Aby wyłączyŢ wpływ twojej reputacji to znajdziesz w kodzie linie, która tak brzmi '// reputationinfluence..' i nast×pnie ją usuđ. Ježeli potrzebujesz wi×cej informacji na ten temat,wstaw posta na forum PotC (P.S od Jacob: Možesz pisaŢ na forum tylko po angielsku) "+PA_INET;
			link.l1 = "Hey, dzi×ki za wskazówki. Brzmi troch× jak modelowanie nie jest takie trudne, eh? Tylko troch× cierpliwo›ci i po›wi×cenia. Ale ježeli chc× poprawiŢ sobie jako›c gry, to powinienem umieŢ troch× umieŢ jak ją ulepszyŢ.";
			link.l1.go = "exit";
		break;

		case "frills":
			Dialog.text = "Oh nie, nie znowu jaki› kolejny smarkacz z brakiem wiedzy o wyrafinowanej erotyki. Posłuchaj mnie, nasza twórczo›c wyrafinowane znactwa oraz róžne motywy: Nasz 'Sen czerwonego aksamitu'TM wygodne kabiny mają szuflady wypełnione erotyką oraz słoikami pełnym egzotycznego oleju do masažu, lub li›cie khatu, lub skrzynie wypełnione zabawkami. Wy›ciełane biurko jest przeznaczone do prowadzenia spraw biurowych, doniczkowe drzewka dla 'niewoli' na ›wiežym powietrzi (przepraszam za bardzo słaby ich stan, li›cie są kompletnie wychłostane..). Potem mamy zwykły dywanik przed kominkiem..." ;
			link.l1 = "Ta, ta, wszystko jest fajne. Co we mnie budzi inwestora to, že wszystkie te pi×kne dekoracje są PUSTE. Jak zamierzasz wypłaciŢ dywidendy za ,które mi wisisz bez klientów?";
			link.l1.go = "frills2";
		break;

		case "frills2":
			PlayStereoSound("ambient\shipyard\axe.wav");
			PlayStereoSound("nature\windmill.wav");
			PlayStereoSound("ambient\town\vehicle.wav");
			Dialog.text = "No, prawda, nie Až TAK dužo wyrafinowanych koneserów na tych wyspach. Ale teraz ci co czasem przychodzą od czasu do czasu płacą bardzo dužo. I my nie mamy znižek bez podatku na strychu powyžej z kilkoma hamakami dla žeglarzy oraz duža kupa słomy dla wie›niaków. I mog× zapewniŢ, že oni są zaj×ci, nawet možesz to usłyszeŢ stąd." ;
			link.l5 = "Ah, TO jest źrodło całego hałasu. A ja juž my›lałem, že to cie›larze wymieniają podłog× na strychu... No cóž, mena.. err.. gni.. eh.. wyrafinowany džentelmen we mnie jest oczywi›cie obražony przez ten twój prymitywne braki fanabanki są baedziej dla biedaków  niž dla pierwszej klasy. Ale businessman we mnie jest zadowolony z kieszonkowych bez wzgl×du na to, jak została zrobiona. Ile udało ci si× przechowaŢ pieni×dzy przez te " + taxdays + " dni od mojej ostatniej wizyty?";
  			if(rand(100)*sti(pchar.reputation)/50 > 20)   // chance for a refusal of payments, decrease last figure for fewer refusals
			{Link.l5.go = "tax";}
			else{Link.l5.go = "taxevasion";}
		break;

		case "motion":
			Dialog.text = LinkRandPhrase("Aww, Jestem bardzo zachwycony twoją obeno›cią, nawet niewarz× si× ruszyŢ z miejsca.", "Kurna, pracowałem cały dzieđ, moje nogi wchodzą w dup×, i niezamierzam powstrzymywaŢ ci× od twojego odpoczynku.", "By›mi uwierzył,že ja musz× podeprzeŢ ten cały budynek. To si× rozpadnie ježeli ja si× rusz×, nawet palcami...");
			link.l1 = "Psaw, allright, I understand... Goodbye.";
			link.l1.go = "exit";
		break;

// enc_resident stuff: healing, spending time etc. 
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
			Log_SetStringToLog("Rozmawiali›cie ze sobą przez godziny i dužo si× nauczyłe› z tych rozmów.");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 50+(sti(PChar.skill.Leadership)*10)+Rand(50) ); }
			else { AddPartyExp(PChar, 50+(sti(PChar.skill.Leadership)*10)+Rand(50)); }
		break;

		case "hall_night_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			TavernWaitDate("wait_night");
			PlaySound("VOICE\ENGLISH\Eng_m_a_014.wav");
			Log_SetStringToLog("Rozmawiali›cie ze sobą przez godziny i dužo si× nauczyłe› z tych rozmów.");
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
			Log_SetStringToLog("Po całej dobie wstajesz z łóžka, czujesz si× silniejszy niž wcze›niej.");
			Log_SetStringToLog("+ zyskujesz +1 punkt žycua");
			Log_SetStringToLog("Dužo si× nauczyłe› o leczeniu ran.");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Defence", 50+(sti(PChar.skill.Defence)*10)+Rand(50) + grgbonus ); }
			else { AddPartyExp(PChar, 50+(sti(PChar.skill.Defence)*10)+Rand(50) + grgbonus); }
		break;

		case "exit infected":
			Dialog.text = B_TEXT[48];
			Link.l1 = LinkRandPhrase(B_TEXT[49], B_TEXT[50], B_TEXT[51]);
			Link.l1.go = "exit infected2";
		break;

		case "exit infected2":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			if (makeint(environment.time) < 22.0 && makeint(environment.time) >= 10.0) TavernWaitDate2("wait_day"); // NK to catch if not night
			TavernWaitDate("wait_day"); // NK so there is a fade
			pchar.chr_ai.poison = 20 + rand(50 -sti(PChar.skill.Sneak) -sti(PChar.skill.defence) );
			grgbonus = 200+Rand(200)
			PlaySound("OBJECTS\DUEL\man_hit6.wav");
			Log_SetStringToLog("Po wstaniu z łóžka czujesz ,že masz gorączk×.");
			Log_SetStringToLog("Twoje rany płoną jak piekło!");
		break;



// boudoir
		case "crew":
			Dialog.text = "Z pewno›cią, ja wiem wi×cej o žeglarza niž twoje matki. No, može to prawdopodobnie lepiej,že ich matki nie wiedzą o ICH stronach. Wi×c jaki jest problem z twoją załogą?";
			Link.l1 = "Chce polepszyŢ ich motywacj× oraz ch×Ţ do walki. Czy možesz zorganizowach im grupowy s.. err.. rozrywk× dla nich? Z pewno›cią bym ich rozweselił gdyby oni mogli. er.. spotkaŢ ciebie oraz twoje dziewczyny. ";
			Link.l1.go = "orgy";
			Link.l2 = "Ja bym zrobił dužo rzeczy z wi×kszą załogą, ale nie mogą znaleźŢ žadnych ochotników, którzy mogli przyłączyŢ si× na mój okr×t. Nie mogą sobie tego wyobraźiŢ. Przeciež załatwiłem przyzwoite jedzenie, robaki i rujkowce są ugotowane i doprawione. Jest jeden wygodny hamak dla každego faceta, oraž oszcuje že moja ›miertelno›c osiąga tylko do 42 procent.. w každym tygodniu. Teraz, je›li nie są to znacznie powyžej przeci×tnych warunków žycia dla dziegciu..";
			Link.l2.go = "crimp";
		break;

		case "crimp":
			Dialog.text = "OCHOTNIKÓW?? Czy ty naprawd× taki naiwny jeste›? Który statek w dzisiejszych czasach može byŢ obsadzony ochotnikami? Marynarka manipuluje nimi impresją, a kupcy obciskaniem. Z łatwo›cią mógłbym zacisnąŢ ci pełny dodatek dla załogi. Po pracowitej nocy zawsze mamy dziesiątki klientów, którzy są tak wyczerpani i pijani, že bez oporów možna ich zaciągnąŢ na swój statek.";
			Link.l1 = "I zanim odzyskają przytomno›Ţ, mój statek b×dzie daleko od brzegu, a b×dąc bez grosza i bez grosza, nie b×dą mieli innego wyboru, jak tylko poddaŢ si× dyscyplinie okr×towej. Bez wątpienia niech×tnie, ale kot na pewno ich zmotywuje. Tak wła›nie zaczyna si× wi×kszo›Ţ marynarskich karier w dzisiejszych czasach. W porządku, sprowadź moją załog× do pełnego składu, a zostawi× ci dywidendy, które mi jeste› winien. Do zobaczenia.";
			Link.l1.go = "crimp2";
			Link.l2 = "Umm, nie lubie pomysłu z bajda demoralizujących k×dzierzawców w mojej załodze.Do widzenia";
			Link.l2.go = "exit";
		break;

		case "crimp2":
		  pchar.ship.crew.morale=sti(pchar.ship.crew.morale)-30;  // reward: crew moral. Change figure to your liking
		  if(sti(pchar.ship.crew.morale)<11) pchar.ship.crew.morale=11;
	    SetCrewQuantity(&pchar, GetMaxCrewQuantity(&pchar));
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "orgy":
			Dialog.text = "TWOJA CAŁA ZAŁOGa?? Whew, no, my wszyscy jeste›my do›wiadczeni, i z paroma sztuczkami i mleczkami, my možemy to wykonaŢ. Ale wtedy nie b×dziemy mogli usługiwaŢ innych klientom przez jaki› czas, wi×c b×dziesz musiał nam da› rekompesat× za stracony dochód.";
			Link.l1 = "Och, to nie b×dzie takie wymagające. Moi koledzy nie poznali dziewczyny od tygodni, wi×c nie b×dą... e.. trwaŢ długo. Zwłaszcza nie w tak pi×knych... hm... r×kach jak twoje. A jako rekompensat× zostawi× ci dywidendy, które mi jeste› winien. A teraz lepiej odejd×, zanim pojawią si× moje r×ce. Gdy są podnieceni i pijani, žadna przystojna istota ludzka nie jest przed nimi bezpieczna.. ";
			Link.l1.go = "orgy2";
			Link.l2 = "Umm, može b×dzie taniej,ježeli ja im dam troch× złota. Do widzenia";
			Link.l2.go = "exit";
		break;

		case "orgy2":
		  pchar.ship.crew.morale=sti(pchar.ship.crew.morale)+10;  // reward: crew moral. Change figure to your liking
		  if(sti(pchar.ship.crew.morale)>99) pchar.ship.crew.morale=99;
	    PlaySound("OBJECTS\abordage\abordage_wining.wav");
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;


// headquarter
		case "office1":
			Dialog.Text = "Oh,Ciesz× si× równiež z mojej przeprowadzki. Miałem serdecznie dosyŢ tej siatki starych chłopców w Królewskiej Słužbie Bezpieczeđstwa. A ciągłe n×kanie przez spłukanych testosteronem niedoszłych superagentów równiež znudziło si× na dłužszą met×. Nie, jestem szcz×›liwszy w twojej eleganckiej siedzibie tutaj. Chociaž… wła›ciwie nie ma jeszcze wielu misji tajnych słužb, chyba?";
 			link.l3 = "Obawiam si×, že masz racj×, ale mam nadziej×, že pewnego dnia to biuro stanie si× siedzibą kwitnącej prywatnej agencji detektywistycznej. Nasz agent specjalny Couchcaptain Charles od dawna obiecywał, že zdob×dzie dla nas tajne misje, ale jeszcze ich nie dostarczył. Ten niewiarygodny, obskurny tenisówka został wplątany w jaką› podejrzaną transakcj× na rynku nieruchomo›ci i przez jaki› czas musiał ležeŢ nisko. Wi×c na razie musimy sp×dzaŢ czas na bardziej przyziemnych sprawach.";
			link.l3.go = "office";
		break;

		case "office":
		  if(taxdays>0)
	   	  {
			Dialog.Text = "Jeden z džentelmenów, który podaje si× za dyplomate chce, žeby› dołączył do jego niepodległej słužby u niego troch× mniej wybitny człowiek chce ciebie zatrudniŢ jako eskort× oraz n×dzny facet błaga ci×, žeby› to zatrudnił. Jako oficera. Przedstawiciel z jednych sąsiednich platacji przyszedł aby złožyŢ danin×. I stary dobry Q wytworzył znowu kolejne specjalne bronie";
			Link.l1 = "Specjalne bronie są zawsze mile widziane, ale wykłady Q na ich temat juž nie. Chciałbym dostaŢ zabawki, nie spotykając si× z nim. Bądź dobrą sekretarzem i przynie› mi je, dobrze? Z góry dzi×kuje.";
			Link.l1.go = "weapons";
			if (sti(npchar.enemynation)!= -1 && sti(npchar.enemynation)!= PIRATE)
			{
			Link.l2 = "Dyplomatat? kto go przysłał?";
			Link.l2.go = "nations";
			}
			Link.l3 = "Zobaczmy tego kupca co potrzebował eskorty.";
			Link.l3.go = "convoy";
			Link.l4 = "Sprawdźmy tego 'co chce byŢ' oficera.";
			Link.l4.go = "officer";
			Link.l5 = "Danina? W słowach czy w złocie?";
			Link.l5.go = "Tribute";
			Link.l6 = "Oh, nie marnuj mojego czasu z tymi dokuczliwymi nudziarzami . Bądź dobrym sekretarzem i si× ich pozbądź, dobra? Z góry dzi×kuje.";
			Link.l6.go = "Exit skip tax";
			}
			else
			{
			Dialog.text = "W moimeh rozpisce nie ma wi×cej spotkađ na dzi›. Wszyscy wcze›niejsi rozmówcy stracili w mi×dzyczasie cierpliwo›Ţ i odeszli. ";
			Link.l2 = "Oh, no cóž, zgaduje, že oni jutro zadzwonią. Jak narazie, czołem.";
			Link.l2.go = "exit";
        }
		break;


		case "Tribute":
			Dialog.text = "No, to zaležy od ciebie. Plantatorzy ci ostatnio bardzo ucierpieli w wyniku najazdów plemion Akellani. Gubernator tej wyspy mówi, že" + isnatname + " nie može oszcz×dziŢ žadnych žołnierzy do ochrony plantatorów. Wi×c przyszli do ciebie po ochron× i proszą, aby› został ich przedstawicielem.";
			Link.l1 = "Umm.. obawiam si×, že  " + isnatname + " uzna to za bunt, je›li ominiemy gubernatora i wybierzemy własnego przedstawiciela. Bądź dobrą sekretarką i grzecznie powiedz moim sąsiadom, že musz× odrzuciŢ ich hojną ofert×.";
			Link.l1.go = "repdrop";

			Link.l2 = "Najwyžszy czas, žeby pokazaŢ" + isnatname + " , že nie jeste›my wie›niakami. Jestem zaszczycony by zaakceptowaŢ tytuł wybranego przedstawiciela a co do indianów, ja si× z nimi rozprawi×.";
			if(rand(100)<30)    // chance for attack, decrease last figure for fewer attack 
      		{Link.l2.go = "akellani";}
			else{Link.l2.go = "represent";}

			Link.l5 = "Nie obchodzą mnie žadne tytułu oraz polityka, jestem uczciwym korsarzem: powiedz tym rodakom,že jak chcą ochrony odemnie to mają mu zapłaciŢ uczciwie: 500 sztuk złota každego dnia, płatne od dnia załoženia mojego majątku. I powiedz im, že lepiej nie odrzucają tej oferty. Ježeli " + isnatname + " nie može ich sam ochroniŢ przez dzikusami, to ja tež im nie b×d× pomogał, hehe.";
			Link.l5.go = "Tribute2";
		break;

		case "Tribute2":
			npchar.tax = taxdays*500;
			ChangeCharacterReputation(Pchar, -3);  // punishment: reputation. Change figure to your liking
			Dialog.text = npchar.tax + " łoto? Przypomn×, že szlachta kolonialna bardzo dba o status społeczny i konwencje. Mogą si× obraziŢ taką pochopną „ofertą” od początkującego korsarza.";
			Link.l2 = "Never mind, those snobs shall pay or I'll show them some common down-to-earth manners.";
			if(rand(100)<50)    // chance for attack, decrease last figure for fewer attack 
      		{Link.l2.go = "gentry";}
			else{Link.l2.go = "Exit pay tax";}
		break;


		case "weapons":
				LAi_Fade("", "");
			Dialog.text = "Oto wszystkie wysoce wybuchowe rzeczy, które Q stworzył podczas " + taxdays + " dni od mojej ostatniej wizyty.";
			link.l1 = "›wietny. Bądź dobrą sekretarką i włóž te wszystkie ›mierciono›ne gadžety do mojej torby, dobrze? Ale na miło›Ţ boską uwažaj na te materiały wybuchowe..";
			if(rand(100)>20)    // chance for explosion, decrease last figure for fewer explosions 
      		{Link.l1.go = "weapons_got";}
			else{Link.l1.go = "explosion";}
		break;

		case "weapons_got":
 			 // ccc special weapons, SW assembly kit must be installed !
			TakenItems(Pchar, "bladeX1", rand(1));	
			TakenItems(Pchar, "bladeX2", rand(1));	
			TakenItems(Pchar, "bladeX3", rand(1));	
			TakenItems(Pchar, "pistolpdart", rand(taxdays));
			TakenItems(Pchar, "pistolgrenade", rand(taxdays));
			TakenItems(Pchar, "pistolgas", rand(taxdays));
			TakenItems(Pchar, "pistolrock", rand(taxdays));
			TakenItems(Pchar, "pistolstink", rand(taxdays));
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "explosion":
		  Explosion(NPchar, 60);
		  lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;


		case "nations":
			Dialog.text = GetNationRoyalByType(sti(npchar.enemynation)) + " of " + GetNationNameByType(sti(npchar.enemynation));
			link.l1 = "Bah, Nie chce zajmowaŢ si× tymi knypkami. Bądź dobrym sekretarzem i pozbądź si× tego dyplomaty w dyplomatyczny sposób, dobrze? Czy možesz mi znowu powiedzieŢ moją rozpisk× na dzisiaj? Po prostu nie pami×tam tych drobnych szczegółów..";
			if(rand(100)>30) {Link.l1.go = "office";}
			else{Link.l1.go = "commando";}
			Link.l2 = GetNationNameByType(sti(npchar.enemynation)) + "? wpu›c go, teraz, prosz×!";
			Link.l2.go = "nations2";
		break;

		case "nations2":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			chr = LAi_CreateFantomCharacterEx(false, 0, false, false, 0.0, GetRandomModelForTypeSex(1, "Rich_Citizens", "man"), "", "");	
			chr.dialog.filename = "B_diplomat.c";
			LAi_SetStayType(chr);
			chr.nation = npchar.enemynation;
			chr.name = "Envoy from";
			chr.lastname = GetNationNameByType(sti(chr.nation));
  		GetCharacterPos(pchar, &x, &y, &z);
  		x = x+1;
  		TeleportCharacterToPos(chr, x, y, z);
  		Lai_SetActorType(chr);
  		LAi_ActorTurnToCharacter(chr, pchar);
  		LAi_ActorDialog(chr,pchar, "", 4.0, 1.0);
		break;

		case "officer":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			chr = LAi_CreateFantomCharacterEx(false, 0, true, true, 0.0, GetRandomModelForType(1, "Smugglers"), "", "");
			chr.dialog.filename = "Enc_officer_dialog.c";
			chr.dialog.CurrentNode = "Node_1";
			LAi_SetStayType(chr);
			GetCharacterPos(pchar, &x, &y, &z);
			x = x+1;
			TeleportCharacterToPos(chr, x, y, z);
		break;

		
		case "convoy":
	
			string iDay, iMonth;
			iDay = environment.date.day;
			iMonth = environment.date.month;
			string lastspeak_date = iday + " " + iMonth;
			npchar.work = lastspeak_date;

			if (GetCompanionIndex(pchar,1) != -1 && GetCompanionIndex(pchar,2) != -1 && GetCompanionIndex(pchar,3) != -1)
			{
				dialog.text = "Umm, Obawiam si×, že masz za dužą flot× aby dodaŢ kolejny statek.";
				link.l1 = "Masz racj×, wi×cej statków oznacza niepokonaną eskadr×. Wi×c o czym mówili›my?";
				link.l1.go = "office";
			}
			else
			{
			  if (CheckQuestAttribute("generate_convoy_quest_progress", "begin"))
			  {
		  		dialog.text = "Umm, Obawiam si×, že masz juž umow× o eskort× z innym kupcem.";
		  		link.l1 = "Dzi×kuj× za przypomnienie, w kođcu obiecałem mu niepodzielną uwag× i szybką eskort×. Powinienem od razu wyruszyŢ z nim w rejs!";
		  		link.l1.go = "office";
        }else
			  {
		  		dialog.text = "On jest w drodz× do tego miejsca, on powinien si× wktrótc× pojawiŢ.";
		  		link.l1 = "Može powinienem sam do niego podej›c. Nie chc×, žeby on si× zgubuł na wybrzežu..";
		  		link.l1.go = "Exit skip tax";
		  		AddDialogExitQuest("prepare_for_convoy_quest");
				}
			}
		break;

// dialogexits
		case "moraledrop":
			ChangeCharacterReputation(Pchar, 3);  // reward: reputation. Change figure to your liking

		  pchar.ship.crew.morale=makeint(stf(pchar.ship.crew.morale) -5 );  // punishment: crew moraledrop. Change figure to your liking
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "repdrop":
			ChangeCharacterReputation(Pchar, -3);  // punishment: reputation. Change figure to your liking
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "represent":
			ChangeCharacterReputation(Pchar, 6);  // reward: reputation. Change figure to your liking
			if (GetRMRelation(pchar, isnat) > REL_WAR) SetRMRelation(pchar, isnat, REL_WAR);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit skip tax":
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit pay tax":
		  AddMoneytoCharacter(Pchar, sti(npchar.tax));
			lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
