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
#include "DIALOGS\SPANISH\B_resident_text.h"

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

	string interiorstr = "mobiliario sencillo";
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
	if(NPChar.chr_ai.group==LAI_GROUP_PLAYER ){adress = " Señoría";}else{adress = " " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false)) + " ";}
	
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
				Dialog.text =  LinkRandPhrase("¡Gracias a Dios que has venido! Puedes defendernos de estos brutos...", "Ah, tu llegada es un regalo del cielo en un momento crucial: están a punto de atacarnos. ¡AYÚDANOS!", "Qué alegría verte, necesitamos desesperadamente a alguien como tú, la clase de " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false)) + " capaz de luchar para protegernos del ataque...");
				link.l1 = LinkRandPhrase("¡Eh, cálmate! Vaya, pero si estás temblando de miedo... Ahora, dime lo que está pasando.","No te preocupes, sea cual sea la amenaza, protegeré mi propied... esto... mi gente. ¿Cuál es el problema?","Calma... No tienes nada que temer mientras estés bajo mi protección (y paguéis vuestras rentas). ¡Qué pasa?");
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
				link.l9 = "Oh, vamos mujer, no te pongas histérica por algún cotilleo que hayas oído por ahí, ¿quieres? ¡Tengo asuntos importantes que atender y no quiero que me molesten con rumores infundados!";
				link.l9.go = "exit";
			}
			else
			{	
        PlayStereoSound("voice\ENGLISH\Fre_f_a_005.wav");
				Dialog.text = "¡Hooolaaa, capitán! Qué placer volver a verte...";
				if(CheckAttribute(pchar,"chr_ai.poison") && pchar.chr_ai.poison > 0)
				{
					Link.l1 = "¡Oh, me encuentro fatal! Fiebre, extremidades inflamadass, oscurecimiento alrededor de las heridas... ¡Me temo que tengo gangrena!";
					Link.l1.go = "infected";
				}

				if(NPChar.chr_ai.group==LAI_GROUP_PLAYER) // if you are the landlord
				{
					if(interiorstr=="office")
					{
 				    link.l32 = "Sí, sí, gracias. ¿Alguna visita o mensaje para mí?";
            link.l32.go = "office";
 				    link.l31 = "¡Hoolaaa, señorita Moneycent! ¡Qué placer volver a verte a ti! Me alegra que Q y tú dejarais el servicio secreto para uniros a mi agencia privada.";
					  link.l31.go = "office1";
				  }

					if(interiorstr=="boudoir")
					{
	   				if(taxdays>0)
	   				{
  					link.l5 = "¡Hoolaaa, cariño! He venido a cobrar los dividendos de mi inversión en tu establecimiento. ¿Cuánto has ganado en los " + taxdays + " días que han pasado desde tu último pago?";
  					if(rand(100)*sti(pchar.reputation)/50 > 20)   // chance for a refusal of payments, decrease last figure for fewer refusals
				  	{Link.l5.go = "tax";}
  					else{Link.l5.go = "taxevasion";}
 				    link.l32 = "Tengo un problema con mi tripulación, y como tú tienes mucho... ejem... contacto con marineros, quizás puedas ayudarme.";
            link.l32.go = "crew";
					  link.l31 = "¡Hoolaaa, 'Madame Monique'! *GUIÑO*. Has comprado unos muebles y bordados muy bonitos con mi dinero. Espero que no hayas dilapidado mi inversión en caprichos y fruslerías femeninas. Normalmente solo haría falta un jergón de paja para practicar tu oficio. Que sería mucho más fácil de limpiar que todas estas alfombras y tercipelo.";
            link.l31.go = "frills";
            }
				  }

					if(CheckCharacterItem(PChar,"pistolgrenade") && !CheckCharacterItem(NPChar,"pistolgrenade") )
					{
					link.l7 = "Escucha: hay mucho canalla suelto que acecha por estas islas, saqueadores que disfrutan robando, torturando y violando. Quizás vengan aquí, y en ese caso, necesitarás algo que puedas usar como último recurso. Ten, toma esta granada...";
					link.l7.go = "grenade";
					}

					link.l8 = "Este edificio ya no tiene ninguna utilidad para mí. Di a los marineros que lo desmantelen, carguen las tablas en la bodega y que se presenten al contramaestre para que les asigne sus deberes a bordo.";
					link.l8.go = "dismantle";

				}
				else   // if you are NOT the landlord
				{
					link.l9 = "Solo pasaba por aquí... ";
					link.l9.go = "exit";
				}

				Link.l2 = B_TEXT[8];
				Link.l2.go = "heal";

				Link.l4 = LinkRandPhrase(B_TEXT[9], B_TEXT[10], B_TEXT[11]);
				Link.l4.go = "chat";

				Link.l10 = B_TEXT[12];
				Link.l10.go = "exit";

				link.l11 = "Eh, ¿qué haces ahí sin moverte? " + LinkRandPhrase("¿Te has tragado un palo de escoba?...", "Vamos, relájate un poco...", "Espero un poco más de actividad en los habitantes de mi asentamiento, ¿me oyes?");
				link.l11.go = "motion";

				link.l12 = "Hum, perdona, no quiero ser tiquismiquis, pero este 'edificio' me parece un poco raro...";
				link.l12.go = "odd";

				link.l13 = "¡Eh, tú, enfrente del teclado! Este es un edificio creado POR TI, así que, ¿por qué no creas tu propio diálogo para acompañarlo? Solo tienes que usar Bloc de Notas para abrir el archivo PROGRAM\DIALOGS\SPANISH\" + NPchar.dialog.filename + " y sobreescribir este texto con el tuyo. Luego sigue las instrucciones en los comentarios.";
				link.l13.go = "your_dialog"; //this is the case that runs if you choose the dialogoption l13. It is right below.
			}
		break;
                
		case "your_dialog":
			Dialog.text = "Escribe aquí el texto de diálogo del NPC." ;

			link.l1 = "Texto de diálogo del jugador: opción link.l1, que cierra el diálogo ";
			link.l1.go = "exit";	// link l1 exits the dialog

			link.l2 = "Texto de diálogo del jugador: opción link.l2, que conduce a otro intercambio ";
			link.l2.go = "your_dialog2";	// l2 leads to the case your_dialog2
		break;	// end of case "your_dialog"
                
		case "your_dialog2":
			Dialog.text = "Escribe aquí el texto de diálogo del NPC." ;

			link.l1 = "Texto de diálogo del jugador: opción link.l1, que cierra el diálogo";
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
			Dialog.text = "... y si esa escoria se atreve a entrar en mi... tu propiedad, patrón, lo volaré por los aires." ;
			link.l1 = "¡Esa es la actitud! Me alegra tener súbditos tan leales. Pero ten cuidado con a quién vuelas por los aires...";
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "pistolgrenade" );
			GiveItem2Character(NPchar, "pistolgrenade");
		break;




// random attacks
		case "monks1":
			dialog.text = "Algún misteroso predicador ha reunido una gran secta de fanáticos en esta isla sermoneándolos sobre fuego y azufre. Su último tema fetiche es que nuestro 'comportamiento pecaminoso' es la causa del último brote de fiebre amarilla. Ha  soliviantado a una turba de sus seguidores y temo que intenten quemar nuestro establecimiento.";
			Link.l4 = "Oh, estos tipos suelen respoetar la propiedad privada, no quieren arruinar a posibles donantes. Y si te amenazan solo tienes que representar una pantomima con mucha lágrima y mucho arrepentimiento. Enséñales algo de carne desnuda que puedan azotar un poco, jura que abandonarás tu vida de pecado y te unirás a ellos. A estos fanáticos hipócritas les encantan las chicas arrepentidas, sígueles la corriente y todo irá bien. Cualquier político podrá decirte que no conviene enemistarse con los grupos de presión religiosos. Y yo no puedo permitirme que se me asocie contigo en público, así que será mejor que me vaya. Que Dios te guíe.";
			Link.l4.go = "exit";
			Link.l1 = "No soporto cuando estos supuestos cristianos devotos abusan de la religión para causar daño a otros. ¡Los que apalean a otros a golpes de biblia raramente entienden las lecciones del Evangelio!";
			Link.l1.go = "monks";
		break;

		case "monks":
			Dialog.text = "¡Oh, oh! Aquí vienen... ¡Los 'Adoradores del Purgatorio', con la cabeza llena de versículos d ela Biblia y odio!";
			link.l1 = RandSwear() + "¡Bueno, voy a enseñarles el Evangelio a mi manera!";
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
			dialog.text = "La nobleza local celebra un gran evento social hpy: una caza del zorro. Al menos, eso es lo que dicen a sus esposas, pero en realidad toda la partida de caza a lomos de sus caballos viene aquí a pasar el día con mis chicas. Un día perfecto para todos, de momento, pero a esos nobles depravados les suele gustar la violencia y la humillación. Uno de sus juegos favoritos es la'caza de la zorra': mandan a una chica a la selva y luego toda la partida de caza la persigue a caballo con una jauría de perros. Cuando la atrapan, la someten a todo tipo de humillaciones y abusos, Te lo puedes imaginar...";
			Link.l4 = "Prefiero no imaginarlo o no podré dormir esta noche... ¡por la indignación, por supuesto! Enseñarçe una lección a esos nobles depravados. ¡Todas las mujeres en mi propiedad deben ser tratadas con respeto y cortesía, sin importar su profesión! ";
			Link.l4.go = "gentry";
			Link.l1 = "Lo siento por esa pobre chica, pero esos son los riesgos de vuestra profesión. Seguro que los caballeros pagarán bien como compensación. Y no puedo permitirme ofender a la nobleza local estropeando sus celebraciones. Tally ho!";
			Link.l1.go = "exit";
		break;

		case "gentry":
			Dialog.text = "¡Oh, oh! Aquí vienen... La autoproclamada nobleza local. ¡Intentando reforzar su estatus social mediante la subyugación y el abuso!";
			link.l1 = RandSwear() + "¡Yo les enseñaré que nacer en una cuna de oro no les da derecho a tratar a la gente como basura!";
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
			Dialog.text = "¡Demasiado tarde! Aquí vienen... ¡Los salvajes caníbales akellani! Oh, si tan solo tuviéramos bastiones, empalizadas, minas y cañones...";
			link.l1 = RandSwear() + "¡Estos marineros de agua dulce están paralizados de miedo! La vida en tierra los ha ablandado. Parece que tendré que luchar sin su ayuda.";
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
			Dialog.text = "¡Oh, cielos, tu nación archienemiga " + XI_ConvertString(GetNationNameByType(sti(npchar.enemynation))) + " se ha hartado de tus provocaciones! Han enviado a un comando de fuerzas especiales para exterminarte! " +  RandSwear() + " ¡Los comandos no toman prisioneros, nos matarásna a todos!";
			link.l1 = RandSwear() + "¿Así que sus soldados finalmente se deciden a atacarme, eb vez de dejarme pasear por sus ciudades? Deben de ser un hatajo de novatos con más motivación que cerebro. ¡No durarán mucho!";
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

			Dialog.text = "¿Qué? ¿Ya han pasado " + taxdays + " días? Está bien, he conseguido reunir " + npchar.tax + " piezas de oro.";
			link.l1 = LinkRandPhrase("Gracias, muy amable. Bueno, ha sido un placer conocerte, pero tengo que irme. Hasta la próxima *GUIÑO* ","¿Para qué necesitas ahorros? Después de todo, yo te proporciono todo lo que puedas necesitar: protección, alojamiento, comida, trabajo... Así que lo correcto sería que todo tu oro acabe en mis cofr... en los cofres comunales.","Yo me quedaré con eso... esto... te guardaré eso. De lo contrario, algún rufián intentaría quitártelo, así que es por tu bien si yo me ocupo de administrar tu dinero.");
			link.l1.go = "taxfull";
			link.l2 = LinkRandPhrase("Bien hecho. Te dejaré la mitad para ti. Úsalo sabiamente para acrecentar tu fortuna (y la mía).","Así que has trabajado duro, ¿eh? Como recompensa por tus desvelos, te dejaré la mitad para ti (con la esperanza de que eso te anime a trabajar aún más duro).","Escucha, te dejaré la mitad de este dinero para que puedas cambiar la paja del jergón y quizás un par de barriles de de Poción Antisifilítica del Doctor Maturin. Quiero que mi propiedad sea un lugar limpio y saludable (y eficiente y rentable).");
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

			Dialog.text = RandSwear() + LinkRandPhrase("Oh, mis disculpas, Excelencia, pero hemos pasado por tiempos duros últimamente: la sífilis ha afectado a una chica tras otra y no hemos podido ganar ningún dinero, además de gastar mucho en pócimas de mercurio...", "Lo siento mucho, Señoría, pero no me queda ni una moneda en el bolsillo: justo la otra noche, un ladrón robó todo lo que tenía ahorrado para ti. Deberías hacer algo más por la seguridad de tus propiedades...", "Odio tener que decírtelo, Excelencia, pero un rufián ya me ha puesto bajo su... protección. Intenté negarme, pero es de los violentos. Mira mis brazos rotos...") ;
			link.l1 = LinkRandPhrase("Bueno, si las cosas están tan difíciles para vosotras, no voy a complicároslas más: os libraréis por esta vez, pero solo esta vez. Porque no puedo permitirme mostrar debilidad demasiado a menudo, solo puedo mantener a mi tripulaciñon bajo control si me muestro inflexible.", "Está bien, aceptaré tu explicación esta vez. Pero, para la próxima, no quiero oír más excusas... Después de todo, se supone que el dinero de vuestras rentas es para financiar mi barco, y a la tripulación no le hará gracia tener que renunciar a sus dividendos.", "Hum, no tiene sentido matar a la vaca que quieres ordeñar, ¿verdad? No tomaré medidas esta vez, pero espero que reanudes la producción en cuanto se apsoible. Aunque mi tripulación se quejará de que soy demasiado indulgente con vosotras.");
			link.l1.go = "moraledrop";

			link.l2 = LinkRandPhrase("Ya basta de lloriqueos, he oído esas excusas vacías demasiadas veces como para darles más crédito. Pagarás, aquí y ahora.", "Vamos, no exageres, esto no te matará... Solo reclamo lo que me corresponde, nada más, pero tampoco nada menos.", "¡Cállate, ramera chillona! O cumples con lo estipulado en el contrato, o trabajarás en la bodega de un barco pirata.");
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
			Dialog.text = "Es muy generoso por tu parte, " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)) + ". ¡Le diré a todo el mundo que eres un proxene.... protector amable y que se preocupa por sus chicas, te lo aseguro!";
			link.l1 = "Oh, no te molestes, no me importa tanto mi reputación. Por cierto, te concedo la noche libre. ¿Por qué no vas a la ciudad, confraternizas con los vecinos, hablas con ellos...? ¡Diviértete!";
			link.l1.go = "exit";
		break;

		case "taxfull":
			AddMoneytoCharacter(Pchar, sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // punishment: reputationdrop. Change figure to your liking
			Dialog.text =  RandSwear() + LinkRandPhrase("Está bien, toma tu maldito dinero. Pero no te quejes si te encuentras pronto sin chicas porque se han muerto de hambre...", "Entonces, no tendré otra opción que pedir prestado el dinero que t edebo aun usurero. Lo que significa que probablemente acabaré con un brazo roto..., en el mejor de los casos...", "Está bien, sanguijuela, toma. Toma este dinero que había ahorrado para ayudar a mi madre enferma.") ;
			link.l1 = "Hum, me pregunto si ha sido buena idea manchar mi buena reputación isistiendo en el cobro de estas " + tax + " piezas de oro. ";
			link.l1.go = "exit";
		break;

		case "taxrevolt":
			AddMoneytoCharacter(Pchar, sti(npchar.tax));
			ChangeCharacterReputation(Pchar, -2);  // punishment: reputationdrop. Change figure to your liking
			Ambush("Liz1", 6+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			Dialog.text =  RandSwear() + "Está bien, toma tu sucio dinero, rufián sin corazón. ¡Pero ten por seguro que mis hermanas de la Liha de LIberación Femenina harán que te arrepientas de tratar a las mujeres así!";
			link.l1 = RandSwear() + " ¡Se me olvidaba que en estos tiempo que corren ya no s epuede ser un cerdo machista! Bueno, señora, está claro que me merezco un castigo por mi comportamiento. La verdad, debo confesar que estoy deseando que me castigues.";
			link.l1.go = "exit";
		break;

		case "taxsuicide":
			Dialog.text =  RandSwear() + LinkRandPhrase("¡Si tú me arrebatas mis posesiones, yo te arrebataré las tuyas! ¡Con una de tus propias granadas! Irónico, ¿verdad? Mi vida no es más que una farsa...","¡Eres mi ruina! ¿Cómo voy a seguir viviendo? ¡Moriré de hambre!... ¡NO! ¡No lo haré! ¡Prefiero morir rápido, arder como una estrella y no consumirme como una vela! ¿Dónde está mi barril de pólvora?","¡Has destruido mi vida, chupasangre! Lo único que me queda es este barril de ron... Delicioso ron, del fuerte, del que quema la garganta como los fuegos del infienro... Los fuegos del infierno, eso es lo que te espera... ¿ME OYES, CHUPASANGRE? ¡YO TE ENSEÑARÉ LOS FUEGOS DEL INFIERNO! Este alcohol no solo quema en la garganta...");
			link.l1 = LinkRandPhrase("Oh, vamos, no seas tan dramático...","¡Eh!, ¿qué estás tramando? Cuidado, podrías causar un accidente...","Está bien, mátate si te apetece. Los perdedores como tú son fáciles de reemplazar...");
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
			Dialog.text = "Ah, a mí me lo dices... ¡Yo soy quien tiene que soportar la 'rareza' de mi hogar día sí y día también! Lo peor es que las paredes están tan agrietadas que la gente puede colarse por ellas. ¡No puedo tener privacidad ni en mi propia cama! Todo es culpa del desgraciado arquitecto que diseñó esto, Couchcaptain Charles. Ese empollón picacódigo no tiene ni la menor idea sobre modelos de edificios, solo ha robado diseños de Inez Diaz y los ha plantado en los lugares más imposibles." ;
			link.l1 = "¡Eh, deja de quejarte! ¿No es mejor tener una casa rara que no tener casa? ¿Preferirías dormir en la playa? Por mi parte, yo pienso disfrutar de las vistas y de las capacodades de mis nuevos edificios en vez de perder el tiempo con comentarios quisiquillosos.";
			link.l1.go = "exit";
			link.l2 = "En vez de quejarte sobre lo que hacen otros, deberías mover el culo y resolver el problema tú mismo. ¿Cuál es la causa exacta de este problema? Sé algunas cosas sobre modelos 3D, ¿quizás pueda ayudar?";
			link.l2.go = "odd2";
			link.l3 = "¿Qué importa el aspecto que tenga? Lo que no me gusta es el aspecto económico: la cantidad de productos y beneficios. Y la frecuencia de ataques y eventos, las penalizaciones...";
			link.l3.go = "tweaking";
		break;

		case "odd2":
			Dialog.text = "Cualquier tipo de ayuda será muy apreciada. A algunos de estos modelos de edificios les vendría bien una remodelación. El prinicpal problema es que estos modelos de edificios no son parte del modelo del mapa, sino objetos ligados a personajes inmóviles, como yo. Por lo tanto, el 'walkpatch' del modelo del mapa -lo que impide a los personajes caminar a través de las paredes- dno cubres estos nuevos edificios. Lo que neceistamos es un 'walkpatch' alrededor de los objetos que componen el edificio. O alrededor del personaje al que el edificio está ligado. Si conoces una solución a este problema, ponte en contacto con el foro de la comunidad de creadores de mods de PotC en "+PA_INET;
			link.l1 = "Hum, lo pensaré...";
			link.l1.go = "exit";
		break;

		case "tweaking":
			Dialog.text = "Eso tiene fácil arreglo. Puedes hacer esa clase de cambios a tu gusto editando un archivo de texto. Por ejemplo, aquí puedes reducir los pagos que recibes por este negocio: abre el archivo 'Pirates of the Caribbean\PROGRAM\DIALOGS\SPANISH\ " + NPchar.dialog.filename + " ' con un editor d etexto como Bloc de Notas. Usa la función de búsqueda y busca la palabra clave 'reward'. Esto te llevará a una línea similar a esta: ' tax = taxdays * 1;	// Reward ...  '. Reemplaza el '1' por '0.5' para reducir lo que te pago a la mitad (no esperarás que te diga cómo aumentarlo ;) ). Del mismo modo, puedes modificar otras cosas buscando las palabras clave 'chance' para la proababilidad de activar eventos, o 'punishment' para cosas como la pérdida de reputación. Los comentarios que hay detrás de las '//' barras dobles te explicarán qué es lo que hace el código que tienen delante. Para desactivar la infleucnai de la reputación sobre los beneficios, busca las líneas con el comentario '// reputationinfluence..' y bórralas. Si necesitas más información, ponte en contacto con el foro de la comunidad de creadores de mods de PotC en "+PA_INET;
			link.l1 = "Gracias por las indicaciones. Parece que moddear no es tan difícil, ¿eh? Solo requiere un poco de paciencia y dedicación. Pero si me manejo jugando a este juego, también debería ser capaz de modificarlo un poco.";
			link.l1.go = "exit";
		break;

		case "frills":
			Dialog.text = "Oh no, no otro primitivo rufián que no entiende el refinado arte del entretenimiento erótico. Escucha, nuestro establecimiento ofrece al connoisseur sofisticado varias ambientaciones temáticas: nuestros cubículos 'Sueño de Terciopelo Rojo' TM son confortables e incluyen una biblioteca de literatura erótica, frascos de aceite para masajes exóticos, estimulantes o cajas llenas de juguetes. El escritorio acolchado es para representar idilios de oficina. También tenemos la clásica alfombra frente a la chimenea..." ;
			link.l1 = "Sí, sí, todo eso está muy bien. Lo que me molesta como inversor es que todas estas ambientaciones tan bonitas están vacías. ¿Cómo vas a pagarme los dividendos que me debes sin clientes?";
			link.l1.go = "frills2";
		break;

		case "frills2":
			PlayStereoSound("ambient\shipyard\axe.wav");
			PlayStereoSound("nature\windmill.wav");
			PlayStereoSound("ambient\town\vehicle.wav");
			Dialog.text = "Es cierto, no hay tantos connoisseurs sofisticados en estas islas. pero los que vienen pagan precios de lujo. Y todavía tenemos una zona con precios populares en el desván, sin refinamientos y con docenas de hamacas para marineros y un gran montón de paja para la gente del pueblo. Y te aseguro que siempre está llena, como pidrás oír." ;
			link.l5 = "Ah, esa es la fuente de todo ese ruido. Y yo que pensaba que había un carpintero cambiando el suelo del desván... Bueno, el connoi... esto... coniss... eh... caballero refinado que soy se siente ofendido de que la vulgar zona popular esté mucho más concurrida que la de primera clase. Pero el hombre de negocios que también soy se alegra de embolsarse el dinero, independientemente de su origen. ¿Cuánto has ganado en los " + taxdays + " días que han pasado desde mi última visita?";
  			if(rand(100)*sti(pchar.reputation)/50 > 20)   // chance for a refusal of payments, decrease last figure for fewer refusals
			{Link.l5.go = "tax";}
			else{Link.l5.go = "taxevasion";}
		break;

		case "motion":
			Dialog.text = LinkRandPhrase("Oh, me abruma tanto tu presencia que no puedo moverme.", "He estado trabajando todo el día, me duelen los huesos y no dejaré que me impidas tomarme un bien merecido descanso.", "¿Me creerías si te dijera que tengo que soportar todo el peso del edificio? Se vendría abajo si hago el más mínimo movimiento...");
			link.l1 = "Está bien, lo comprendo... Adiós.";
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
			Log_SetStringToLog("Charláis durante horas y aprendes mucho.");
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Leadership", 50+(sti(PChar.skill.Leadership)*10)+Rand(50) ); }
			else { AddPartyExp(PChar, 50+(sti(PChar.skill.Leadership)*10)+Rand(50)); }
		break;

		case "hall_night_wait":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
			TavernWaitDate("wait_night");
			PlaySound("VOICE\ENGLISH\Eng_m_a_014.wav");
			Log_SetStringToLog("Charláis durante horas y aprendes mucho.");
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
			Log_SetStringToLog("Después de 24 horas, vuelves a estar en forma, incluso más fuerte que antes.");
			Log_SetStringToLog("+ 1 salud máxima");
			Log_SetStringToLog("Has aprendido mucho sobre tratamiento de heridas.");
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
			Log_SetStringToLog("Despiertas sintiéndote febril.");
			Log_SetStringToLog("¡Tus heridas arden como el fuego!");
		break;



// boudoir
		case "crew":
			Dialog.text = "Claro, sé más sobre los marineros que sus propias madres. A decir verdad, probablemente sea mejor que sus madres no conozcan esos lados de sus hijos. ¿Qué problema tienes con tus chicos?";
			Link.l1 = "Me gustaría mejorar su humor y motivación. ¿Podrías organizar una orgí... esto... velada de entretenimiento para ellos? Seguro que les alegraría muhco... conoceros a ti y a tus chicas. ";
			Link.l1.go = "orgy";
			Link.l2 = "Me vendrían bien más marineros, pero no puedo encontrar voluntarios que se unan a mi barco. No puedo imaginar por qué. Después de todo, doy buena comida, los gusanos y gorgojos están bien aliñados y hervidos. Hay una hamaca cómoda y caliente para cada dos hombres y mi tasa de mortalidad es de solo 42 por ciento... por semana. Yo diría que eso está por encima de la media para el típico lobo de mar...";
			Link.l2.go = "crimp";
		break;

		case "crimp":
			Dialog.text = "¿VOLUNTARIOS? ¡Cuánta ingenuidad! ¿Qué barco hoy en día puede completar su tripulación solo con voluntarios? La marina de guerra utiliza el reclutamiento forzoso y los mercantes recurren al secuestro. Sería muy fácil para mí conseguirte una tripulación entera. Después de una noche concurrida, siempre tenemos docenas de clientes tan agotados y borrachos que podrían ser arrastrados a tu barco sin resistencia.";
			Link.l1 = "Y antes de que recuperen la consciencia, mi barco estará muy lejos de la costa, y sin dinero ni otra alternativa, tendrán que someterse a la disciplina de a bordo. A regañadientes, sin duda, pero el gato de nueve colas los motivará... Así es como empiezan la mayoría de carreras mavales hoy en día. Está bien, complet ami tripulación y te perdonaré los dividendos que me debes. Hasta otra.";
			Link.l1.go = "crimp2";
			Link.l2 = "Hum, no me gusta la idea de tener en mi tripulación a una panda de marineros desmoralizados embarcados a la fuerza. Adiós.";
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
			Dialog.text = "¿¿TODA TU TRIPULACIÓN?? Gauu... Bueno, estamos bien entrenadas y con algunos trucos y linimento, podremos aguantarlo. Pero después de esto, no podremos atender a más cleintes durante un tiempo, así que tendrás que compensarnos por la falta de ingresos.";
			Link.l1 = "Oh, no será par atanto. Mis chicos no han estado con una chica en semanas, así que no... esto... aguantarán mucho. Sobre todo no en vuestras hermosas... manos. Y como compensación, os perdonaré los dividendos que me debéis. Y ahora será mejor que me vaya antes de que lleguen mis hombres. Una vez que están borrachos y excitados, ningún ser humano atractivo está salvo de ellos... ";
			Link.l1.go = "orgy2";
			Link.l2 = "Hum, tal vez sea más barato repartiles algo de dinero. Adiós.";
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
			Dialog.Text = "Oh, yo también me alegro de este traslado. Estaba harta de ese club de muchachos en que se ha transformado el Servicio Secreto de Su Majestad. Y el constante acoso de aspirantes a agente secreto con demasaida testosterona acaba por aburrir. No, Estoy mucho más contenta en este elegante cuartel general. Aunque... la verdad es que no hay muchas misiones secretas, ¿verdad?";
 			link.l3 = "Me temo que tienes razón, pero espero que algún día esta oficina se convierta en el cuartel general de una floreciente agencia de investigación privada. Nuestro agente especial Couchcaptain Charles prometió hace mucho tiempo conseguirnos misiones clandestinas, pero todavía no hemos tenido noticias. Habrá acabado involucrado en algún turbio negocio inmobiliario y habrá tenido que ocultarse por un tiempo. Así que, de momento, debemos emplear nuestro tiempo en asuntos más mundanos.";
			link.l3.go = "office";
		break;

		case "office":
		  if(taxdays>0)
	   	  {
			Dialog.Text = "Ha venido un caballero que dice ser un diplomático y quiere que te pongas al servicio de su soberano, un señor ligeramente menos distinguido que quería contratarte como escolta para su barco mercante y un tipo bastante desharrapado pidiendo trabajo como oficial. Un representante de los plantadores vecinos ha venido a pagar tributos. Y el viejo Q ha vuelto a desarrollar algún tipo de arma secreta.";
			Link.l1 = "Las armas secretas siempre se agradecen, al contrario que las lecciones de Q sobre ellas. Me gustaría poder recibir sus juguetes sin tener que hablar con él. Sé una buena secretaria y traémelos, ¿quieres? Muchas gracias.";
			Link.l1.go = "weapons";
			if (sti(npchar.enemynation)!= -1 && sti(npchar.enemynation)!= PIRATE)
			{
			Link.l2 = "¿Un diplomático? ¿Quién lo ha mandado?";
			Link.l2.go = "nations";
			}
			Link.l3 = "Que pase el mercader que quiere escolta.";
			Link.l3.go = "convoy";
			Link.l4 = "Veamos a ese aspirante a oficial.";
			Link.l4.go = "officer";
			Link.l5 = "¿Tributo? ¿En palabras o en metálico?";
			Link.l5.go = "Tribute";
			Link.l6 = "Oh, no puedo perder el tiempo con estos aburridos pedigüeños. Sé una buena secretaria y líbrate de ellos, ¿quieres? Muchas gracias.";
			Link.l6.go = "Exit skip tax";
			}
			else
			{
			Dialog.text = "No hay más citas para hoy en mi agenda. Todos los anteriores han perdido la paciencia y se han marchado. ";
			Link.l2 = "Oh, bueno, seguramente volverán mañana. Hasta entonces.";
			Link.l2.go = "exit";
        }
		break;


		case "Tribute":
			Dialog.text = "Bueno, eso depende de ti. Esos plantadores han sufrido mucho debido a los ataques de las tribus akellani. El gobernador de esta isla dice que " + isnatname + " no puede prescindir de tropas para porteger las plantaciones. Así que han venido a pedirte protección a ti y a solciitar que seas su representante.";
			Link.l1 = "Hum... Me temo que " + isnatname + " lo verá como una rebelión si pasamos por encima del gobernador y elegimos a nuestro propio representante. Sé una buena secretaria y dile educadamente a mis vecinos que debo declinar su generosa oferta.";
			Link.l1.go = "repdrop";

			Link.l2 = "Ya era hora de enseñar a " + isnatname + " que no pueden tratarnos como a siervos. Me honra aceptar el título de representante electo, y me encargaré de esos nativos.";
			if(rand(100)<30)    // chance for attack, decrease last figure for fewer attack 
      		{Link.l2.go = "akellani";}
			else{Link.l2.go = "represent";}

			Link.l5 = "No me importan los títulos ni la política, soy un honrado corsario: dile a esos caballeros que mi protección tiene unprecio: 500 piezas de oro al día, pagables desde el día de la fundación de mi propiedad. Y diles que m´ças les vale aceptar la oferta. Si " + isnatname + " no puede protegerlos de unos pocos salvajes, tampoco podrá protegerlo de mí, ¡je, je!";
			Link.l5.go = "Tribute2";
		break;

		case "Tribute2":
			npchar.tax = taxdays*500;
			ChangeCharacterReputation(Pchar, -3);  // punishment: reputation. Change figure to your liking
			Dialog.text ="¿" + npchar.tax + " piezas de oro? ¿Debo recordarte que la nobleza colonial se preocupa mucho por su posición social? Puede que les ofenda una 'oferta' tan precipitada de un corsario advenedizo.";
			Link.l2 = "No importa, esos petimetres pagarán o les enseñaré los modales del pueblo llano.";
			if(rand(100)<50)    // chance for attack, decrease last figure for fewer attack 
      		{Link.l2.go = "gentry";}
			else{Link.l2.go = "Exit pay tax";}
		break;


		case "weapons":
				LAi_Fade("", "");
			Dialog.text = "Este es todo el material altamente explosivo que Q ha producido en los últimos " + taxdays + " días.";
			link.l1 = "Genial. Sé una buena secretaria y pon todos estos artilugios letale sen mi bolsa, ¿quieres? Pero, por el amor de Dios, ten cuidado con esos explosivos...";
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
			Dialog.text = (GetNationRoyalByType(sti(npchar.enemynation)) + " de " + XI_ConvertString(GetNationNameByType(sti(npchar.enemynation)));
			link.l1 = "Bah, no quiero tener que aguantar a esos sinvergüenzas. Sé una buena secretaria y líbrate de ese diplomático de una forma diplomática, ¿quieres? ¿Y podrías volver a recordarme mis citas para hoy? Nunca me acuerdo de esos detalles administrativos...";
			if(rand(100)>30) {Link.l1.go = "office";}
			else{Link.l1.go = "commando";}
			Link.l2 = "¿" + XI_ConvertString(GetNationNameByType(sti(npchar.enemynation))) + "? ¡Que pase ahora mismo, por favor!";
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
			chr.name = "Emisario de";
			chr.lastname = XI_ConvertString(GetNationNameByType(sti(chr.nation)));
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
				dialog.text = "Hum, me temo que ya tienes más barcos en tu flota de los que puedes controlar.";
				link.l1 = "Tienes razón, una escuadra de más de cuatro barcos puede ser un poco difícil de manejar. ¿De qué estábamos hablando?";
				link.l1.go = "office";
			}
			else
			{
			  if (CheckQuestAttribute("generate_convoy_quest_progress", "begin"))
			  {
		  		dialog.text = "Hum, me temo que ya tienes un contrato de escolta con otro mercader.";
		  		link.l1 = "Gracias por recordármelo. Después de todo, le prometí mi total y completa atención y una escolta rápida. ¡Debería zarpar con él de inmediato!";
		  		link.l1.go = "office";
        }else
			  {
		  		dialog.text = "Está de camino aquí. Debería llegar en cualquier momento.";
		  		link.l1 = "Quizás debería salir a recibirlo. No uqiero que se pierda.";
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
