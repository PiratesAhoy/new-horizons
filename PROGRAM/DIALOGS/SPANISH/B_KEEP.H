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
	if(NPChar.chr_ai.group==LAI_GROUP_PLAYER ){adress = " mi comandante,";}else{adress = "";}

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

			if(rand(100)<10) // chance for random attack, decrease last figure for fewer attacks
			{
				PlayStereoSound("voice\Eng_m_a_070.wav");	
				ChangeCharacterReputation(Pchar, -2);  // punishment: reputationloss. Will be offset if accept the fight	
				Dialog.text = adress + LinkRandPhrase(", fuerzas hostiles avistadas. Preparad la defensa.", ", ¡movimientos enemigos en nustro sector! ¡Zafarrancho de combate!", "¡Movimientos sospechosos en el perímetro, todos a sus puestos!");

				link.l1 = "Un informe detallado, soldado. Ahora.";
				if(rand(100)>50) {Link.l1.go = "attack1";}
				else{Link.l1.go = "attack2";}

				link.l9 = "¡Déjame en paz con esas tonterías, ese es tu trabajo! Para eso os he contratado como carne de cañ... cañoneros expertos. De todas formas no tengo tiempo: tengo que irme.";
				link.l9.go = "exit";
			}
			else
			{	
				Dialog.text =  "Informo de que la fortaleza está guarnecida y lista para el combate," + adress + " todo está tranquilo en este sector.";

				if(NPChar.chr_ai.group==LAI_GROUP_PLAYER)
				{
					link.l1 = "Nos retiramos de esta posición. Desmantelad la fortaleza, cargad las tablas en la bodega y presentaos al contramaestre para que os asigne vuestros deberes a bordo.";
					link.l1.go = "dismantle";

					link.l21 = "Necesito un lugar seguro para almacenar algunos de mis tesoros y objetos personales, y esta vieja fortaleza parece un lugar muy seguro. ¿Puedes poner algunas cosas a buen recaudo aquí?";
					link.l21.go = "items";
					link.l22 = "Me gustaría hablar sobre mis posesiones almacenadas con ese tal Guardián de la Modorra.";
					link.l22.go = "items";

					if(sti(pchar.money)>5000 && !CheckCharacterItem(NPChar,"cannon") )
					{
					link.l23 = "Me pregunto si tendría sentido apostar un cañón aquí.";	// ccc feb06
					link.l23.go = "cannon";
					}

					if(CheckCharacterItem(PChar,"pistolgrenade") && !CheckCharacterItem(NPChar,"pistolgrenade") )
					{
					link.l24 = "Soldado, tengo una misión especial para ti. Toma esta granada, y si el enemigo nos supera y asalta esta posición...";
					link.l24.go = "grenade";
					}
				}
				else
				{
					link.l1 = "Solo pasaba por aquí... ";
					link.l1.go = "exit";
				}

				Link.l4 = "Muy bien, soldado, continúa.";
				Link.l4.go = "exit";

				// ccc feb06 link.l6 = "Who the hell designed this maze of masonry? Can't take a step here without smashing my head into some vault or pillar..";
				// ccc feb06 link.l6.go = "odd";

				link.l5 = "Eh, ¿qué haces ahí sin moverte? " + LinkRandPhrase("¿Te has tragado un palo de escoba?...", "Vamos, relájate un poco... ¡DESCANSE, SOLDADO!", "Espero un poco más de actividad por parte de mis infantes de marina, ¿me oyes?");
				link.l5.go = "motion";

				link.l9 = "¡Eh, tú, enfrente del teclado! Este es un edificio creado POR TI, así que, ¿por qué no creas tu propio diálogo para acompañarlo? Solo tienes que usar Bloc de Notas para abrir el archivo PROGRAM\DIALOGS\SPANISH\" + NPchar.dialog.filename + " y sobreescribir este texto con el tuyo. Luego sigue las instrucciones en los comentarios.";
				link.l9.go = "your_dialog"; //this is the case that runs if you choose the dialogoption l9. It is right below.
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
			Dialog.text = "..., los volaré en pedazos. ¡Conozco mi deber, mi comandante!" ;
			link.l1 = "¡Así se habla, soldado! Con tu sentido del deber, pronto llegarás a cabo (... si vives lo sifciente).";
			link.l1.go = "exit";
			TakeItemFromCharacter(pchar, "pistolgrenade" );
			GiveItem2Character(NPchar, "pistolgrenade");
		break;

// give cannon to building for selfdefense                
		case "cannon":
			Dialog.text = "¡Por supuesto, " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)) + "! Un cañón aquí, cubriendo la entrada, podrá volar por los aires a cualquier intruso." ;	// ccc feb06
			link.l1 = "Quizás, pero no quiero gastar todavía más dinero aquí.";	// ccc feb06
			link.l1.go = "exit";

			link.l2 = "Aquí tienes 5000 piezas de oro. ¿Puedes... obtener un buen cañón con ese dinero?";
			link.l2.go = "cannon2";
		break;

		case "cannon2":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(Pchar, -5000);
			Pchar.Ship.crew.quantity = sti(Pchar.Ship.crew.quantity) -3;
			lcn.building.(nr).interior = "cannon";
			Dialog.text = "Sí, " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)) + ", conozco bastante bien al sargento mayor del arsenal local. Por 5000 piezas de oro, vendería toda su artillería. Solo necesitaré unas pocas horas." ;
			link.l1 = "¡Así se habla, soldado! Con tu buen entendimiento de la logística, pronto llegarás a cabo (.. si vives lo suficiente).";
			link.l1.go = "exit";
		break;

// load itemkeeper                
		case "items":
		  if(taxdays>0 && rand(100)<120) // chance for random jewel, increase last figure for	more jewels	  
		  {
  	 		lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
  			Dialog.text = LinkRandPhrase("Ah, hablando de objetos valiosos, eso me recuerda que encontré una joya en las viejas catacumbas debajo de la fortaleza. Estaba mean... patrullando ahí abajo cuando descubrí una hendidura en la pared. Conducía a una antigua cámara funeraria y, entre un montón de viejos huesos, encontré esta pequeña gema. La forma en que brillaba era como si me invitar a tomarla. Pero al pensarlo mejor, me di cuenta de que ", "Por cierto, tengo una nueva adición para tus posesiones: esta joya. La encontré ayer despejando escombros de un muro derrumbado. Entre las piedras, había una urna rota, cenizas, astillas de hueso, dientes... Y esta hermosa gema. Por supuesto, ", "Antes de empezar a rebuscar en tu inventario, añade esta joya. Ayer estaba despejando la cripta de la antigua capilla de la fortaleza para hacer sitio a mis reservas de ron... munición, cuando este objeto brillante se cayó de un montón de huesos que estaba transportando. Cayó en mi regazo ocmo un regalo del cielo. O del Hades, quizás. Por derecho, ")  + "te pertenece a ti, ya que la propiedad es tuya. Así que prefiero entregártela, no sea que la maldición de su dueño muerto caiga sobre mí." ;
  			link.l1 = "(¿Maldición de su dueño muerto? ¡Qué yuyu!) Oh, no, quedátela. Después de todo, mereces una recompensa por tu honestidad y tu lealtad, soldado. Con tu sentido de la honradez, pronto llegarás a cabo (.. si vive lo suficiente).";
  			link.l1.go = "reward";
  			link.l2 = "¿Mladición? ¡Supersticiones estúpidas! Quieres asustarme para que te deje la gema a tí, ¿eh? No funcionará, dámela. ¡Es una orden de tu comandante! ";
  			link.l2.go = "jewel";
			}
			else
		  {
  	 		lcn.building.(nr).taxyear = GetDataYear();
			lcn.building.(nr).taxMonth = GetDataMonth();
			lcn.building.(nr).taxDay = GetDataDay();
  			Dialog.text = "Sí, " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)) + ", llamaré al Guardián de la Mazmorra. Por cierto, puede que su forma de ser sea un poco anticua... tradicional; ha estado viviendo en esta vetusta torre demasiado tiempo, si quieres mi opinión. Pero esa actitud tradicional es precisamente la que hace de él un excelente guardián de tus tesoros. Puedes darle cualquier cosa para que la ponga a buen recaudo y ten por seguro que te la devolverá cuando la necesites." ;
  			link.l1 = "Eso espero. ¿Dónde está ese factótum medieval?";
  			link.l1.go = "items2";
			}
		break;

		case "jewel":
		  GiveItem2Character(PChar, "jewelry"+ makeint(1 + rand(15)) );
		  if(rand(100)<20) // chance of poisoning, decrease last figure for	less poisoning	  
		  {
  			DialogExit();
  			NextDiag.CurrentNode = NextDiag.TempNode;
  			pchar.chr_ai.poison = 20 + rand(50 -sti(PChar.skill.Sneak) -sti(PChar.skill.defence) );
  			PlaySound("OBJECTS\DUEL\man_hit6.wav");
  			Logit("¿Maldición? ¿La tumba de una víctima de peste? ¡Sea lo que sea, de repente sientes un terrible malestar!");
			}
			else
		  {
  		  pchar.ship.crew.morale=makeint(stf(pchar.ship.crew.morale) -5 );  // punishment: crew moraledrop. Change figure to your liking
  			Dialog.text = "Sí, " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)) + ",tus deseos son órdenes. Por cierto, ¿qué tal una pequeña... recompensa? ¿No sería bueno para la moral de la tropa recompensar a los soldados leales y honrados?" ;
  			link.l1 = "¡Bastardo insolente! ¿Demandas veladas? ¡Cómo te atreves! Ya basta, quiero ocuparme d emis tesoros. ¡AHORA!";
  			link.l1.go = "items";
			}
		break;

		case "reward":
			ChangeCharacterReputation(Pchar, 2);  // reward: reputation. Change figure to your liking
			Dialog.text = "Es muy generoso por tu parte, " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)) + ". ¡Le diré a todo el mundo que eres un comandante amable y que se preocupa por sus soldados, te lo aseguro!";
			link.l1 = "Oh, no te molestes, no me importa tanto mi reputación. Por cierto, te concedo un permiso para esta noche. ¿Por qué no vas a la ciudad, confraternizas con los vecinos, hablas con ellos...? ¡Diviértete!";
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


// random attacks
		case "attack1":
			Dialog.text = "¡Se acercan los salvajes caníbales akellani, " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)) + "! Oh, si tan solo tuviéramos más bastiones, empalizadas, minas y cañones...";
			link.l1 = RandSwear() + " ¡Atención, soldado! Mantén esta posición pase lo que pase. No dejes de dispararg y no dejes que el enemigo te arrastre a un combate cuerpo a cuerpo. Yo me ocuparé de eso...";
			link.l1.go = "exit_attack1";
		break;

		case "attack2":
			Dialog.text = "¡Francisco Pizarro el Joven y su horda de conquistadores merodeadores se acercan, " + XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)) + "! Ávidos de sangre, botín y bajos instintos... Oh, si tan solo tuviéramos más bastiones, empalizadas, minas y cañones...";
			link.l1 = RandSwear() + " ¡Atención, soldado! Mantén esta posición pase lo que pase. No dejes de dispararg y no dejes que el enemigo te arrastre a un combate cuerpo a cuerpo. Yo me ocuparé de eso...";
			link.l1.go = "exit_attack2";
		break;

		case "Exit_attack1":
		// PB: To prevent the fight from starting before the dialog is closed
			Ambush("native", 3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_attack2":
		// PB: To prevent the fight from starting before the dialog is closed
			Ambush("Soldier_Spa2",  3+sti(pchar.skill.fencing), LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, "");
			ChangeCharacterReputation(Pchar, 4);  // reward: reputation. Change figure to your liking
			if(AUTO_SKILL_SYSTEM) { AddPartyExpChar(PChar, "Fencing", (3+sti(pchar.skill.fencing)) * 100 ); }
			else { AddPartyExp(PChar, (3+sti(pchar.skill.fencing)) * 100 ); }  // reward: experience. Change last figure to your liking

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
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
			Dialog.text = "Sí, es cierto, el diseño de esta fortaleza es anticuado. El torreón pentagonal fue inventado en tiempos de los normandos, cuando las principales amenazas para una fortificación eran las escalas y las máquinas de asedio simples. Está pensado para resisitr contra arietes y minas, por lo que los sótanos y pisos inferiores están casi completamente rellenos de sillares y ofrecen poco espacio para el alojamiento. La invención de la pólvora ha hecho que esta arquitectura se quede obsoleta. Hoy en día, estas torres se suelen usar como prisiones o para almacenar tesoros, porque esa era su función original: evitar que la gente entrara. O saliera." ;
			link.l1 = "Hum, en ese caso es un diseño muy exitoso: encuentro muy difícil entrar o salir sin atravesar una pared.";
			link.l1.go = "exit";
		break;

		case "motion":
			Dialog.text = LinkRandPhrase(XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)) + ", siempre nos ponemos firmes en presencia de un superior. Esa es nuestra ionstrucción y la instrucción lo es todo.", "Le tengo el ojo echado a un objetivo sospoechoso y no quiero perderlo. 'Apunta bien, no te muevas, no parpadees', solía decir nuestro sargento instructor.", "La primera regla del camuflaje: el movimiento atrae la atención. Así que nunca te muevas si no tienes que hacerlo.");
			link.l1 = "Está bien, entiendo... Continúa.";
			link.l1.go = "exit";
		break;


// dialogexits

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
