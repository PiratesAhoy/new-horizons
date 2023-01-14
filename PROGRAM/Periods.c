#define PERIOD_EARLY_EXPLORERS			0
#define PERIOD_THE_SPANISH_MAIN			1
#define PERIOD_GOLDEN_AGE_OF_PIRACY		2
#define PERIOD_COLONIAL_POWERS			3
#define PERIOD_REVOLUTIONS				4
#define PERIOD_NAPOLEONIC				5

#define MAX_PERIODS						6

object Periods[MAX_PERIODS];

int PeriodsQuantity = 0;

void InitPeriods()
{
	ref period;
	int n = 0;

	for (n = 0; n < MAX_PERIODS; n++) {
		makeref(period, Periods[n]);
		DeleteAttribute(period, "");
		period.id = "Period" + n;
		period.name = "";
		period.date.start = "";
		period.date.end = "";
	}

	n = 0;

	makeref(period, Periods[n]);
	period.name = "Early Explorers";
	period.date.start = "1500";
	period.date.end = "1599";
	period.Royal.England.Name = "Elizabeth I";
	period.Royal.England.Title = XI_ConvertString("Her Royal Majesty");
	period.Royal.France.Name = "François Ier";
	period.Royal.France.Title = XI_ConvertString("His Most Christian Majesty");
	period.Royal.Spain.Name = "Felipe II";
	period.Royal.Spain.Title = XI_ConvertString("His Most Catholic Majesty");
	period.Royal.Pirate.Name = "Pedro Menéndez de Avilés";
	period.Royal.Pirate.Title = XI_ConvertString("The chief");
	period.Royal.Holland.Title = XI_ConvertString("The Dutch Republic");
	period.Royal.Portugal.Name = "JoÝo III";
	period.Royal.Portugal.Title = XI_ConvertString("His Most Faithful Majesty");
	period.Relations.England.France = RELATION_NEUTRAL;
	period.Relations.England.Spain = RELATION_ENEMY;
	period.Relations.England.Holland = RELATION_FRIEND;
	period.Relations.England.Portugal = RELATION_ENEMY;
	period.Relations.France.Spain = RELATION_ENEMY;
	period.Relations.France.Holland = RELATION_ENEMY;
	period.Relations.France.Portugal = RELATION_NEUTRAL;
	period.Relations.Spain.Holland = RELATION_ENEMY;
	period.Relations.Spain.Portugal = RELATION_FRIEND;
	period.Relations.Holland.Portugal = RELATION_ENEMY;
	period.Islands.Redmond.Name = "Santiago";
	period.Islands.Redmond.smuggling_nation = SPAIN;
	period.Islands.FalaiseDeFleur.Name = "Martinica";
	period.Islands.FalaiseDeFleur.smuggling_nation = SPAIN;
	period.Islands.Oxbay.Name = "Los Barbados";
	period.Islands.Oxbay.smuggling_nation = SPAIN;
	period.Islands.Conceicao.Name = "Camahogne";
	period.Islands.Douwesen.Name = "Isla do Palo Brasil";
	period.Islands.Douwesen.smuggling_nation = SPAIN;
	period.Islands.QuebradasCostillas.Name = "Nuestra Senora de las Nieves";
	period.Islands.QuebradasCostillas.smuggling_nation = SPAIN;
	period.Islands.Antigua.smuggling_nation = SPAIN;
	period.Islands.Antigua.disable = true;
	period.Islands.Antigua.Model = "Antigua_townless";
	period.Islands.Cayman.Name = "Las Tortugas";
	period.Islands.Cayman.smuggling_nation = SPAIN;
	period.Islands.Cuba.Name = "Isla Juana";

	period.Islands.Guadeloupe.Name = "Santa Maria de Guadalupe de Extremadura";
	period.Islands.Guadeloupe.smuggling_nation = SPAIN;
	period.Islands.Guadeloupe.Model = "Guadelupa_townless";
	period.Islands.Guadeloupe.towns.quantity = 1;
	period.Islands.Guadeloupe.towns.1 = "";
	period.Islands.Guadeloupe.reload.l1.label = "Bahía Grande";
	period.Islands.Guadeloupe.reload.l1.name = "reload_2";
	period.Islands.Guadeloupe.reload.l1.go = "Guadeloupe_shore_02";
	period.Islands.Guadeloupe.reload.l1.emerge = "reload1";
	period.Islands.Guadeloupe.reload.l1.radius = 200.0;
	period.Islands.Guadeloupe.reload.l1.pic = 27;
	period.Islands.Guadeloupe.reload.l1.tex = "t2";
	period.Islands.Guadeloupe.reload.l1.goto_enable = false;
	period.Islands.Guadeloupe.reload.l2.label = "Ensenada del Bosque Quebrado";
	period.Islands.Guadeloupe.reload.l2.name = "reload_3";
	period.Islands.Guadeloupe.reload.l2.go = "Guadeloupe_shore_01";
	period.Islands.Guadeloupe.reload.l2.emerge = "see";
	period.Islands.Guadeloupe.reload.l2.radius = 200.0;
	period.Islands.Guadeloupe.reload.l2.pic = 20;
	period.Islands.Guadeloupe.reload.l2.tex = "t2";
	period.Islands.Guadeloupe.reload.l2.goto_enable = false;
//	period.Islands.Guadeloupe.disable = true;

	period.Islands.SaintMartin.Name = "Isla de San Martin";
	period.Islands.SaintMartin.smuggling_nation = SPAIN;
	period.Islands.SaintMartin.Model = "Sent_townless";
	period.Islands.SaintMartin.disable = true;
	period.Islands.Turks.Name = "San Salvador";
	period.Islands.Turks.smuggling_nation = SPAIN;
	period.Islands.Eleuthera.smuggling_nation = SPAIN;

//	period.Islands.Aruba.Name = "";
	period.Islands.Aruba.smuggling_nation = SPAIN;
//	period.Islands.Aruba.disable = true;
	period.Islands.Aruba.towns.quantity = 1;
	period.Islands.Aruba.towns.1 = "";
	period.Islands.Aruba.reload.l1.label = "Sandy Beach";
	period.Islands.Aruba.reload.l1.name = "reload_1";
	period.Islands.Aruba.reload.l1.go = "Aruba_shore2";
	period.Islands.Aruba.reload.l1.emerge = "reload1";
	period.Islands.Aruba.reload.l1.radius = 200.0;
	period.Islands.Aruba.reload.l1.pic = 21;
	period.Islands.Aruba.reload.l1.tex = "t2";
	period.Islands.Aruba.reload.l1.goto_enable = false;
	period.Islands.Aruba.reload.l2.label = "Rocky Cove";
	period.Islands.Aruba.reload.l2.name = "reload_3";
	period.Islands.Aruba.reload.l2.go = "Aruba_shore";
	period.Islands.Aruba.reload.l2.emerge = "see";
	period.Islands.Aruba.reload.l2.radius = 200.0;
	period.Islands.Aruba.reload.l2.pic = 30;
	period.Islands.Aruba.reload.l2.tex = "t2";
	period.Islands.Aruba.reload.l2.goto_enable = false;

	period.Islands.Curacao.Name = "";
	period.Islands.Curacao.smuggling_nation = SPAIN;
	period.Islands.Curacao.disable = true;
	period.Islands.Colombia.Name = "Kingdom of Granada";
	period.Towns."Isla Muelle".gov.name = "Juan";
	period.Towns."Isla Muelle".gov.middlename = "Ponce";
	period.Towns."Isla Muelle".gov.lastname = "de León";
	period.Towns.Conceicao.gov.name = "Gonzalo";
	period.Towns.Conceicao.gov.lastname = "de Guzmán";
	period.Towns.Douwesen.Name = "Palo Brasil";
	period.Towns.Douwesen.nation = SPAIN;
	period.Towns.Douwesen.gov.name = "Juan";
	period.Towns.Douwesen.gov.lastname = "de Ávila";
	period.Towns."Falaise de Fleur".Name = "San Pedro";
	period.Towns."Falaise de Fleur".nation = SPAIN;
	period.Towns."Falaise de Fleur".gov.name = "Antonio";
	period.Towns."Falaise de Fleur".gov.lastname = "de las Casas";
	period.Towns."Isla Muelle".gov.name = "Juan";
	period.Towns."Isla Muelle".gov.middlename = "Ponce";
	period.Towns."Isla Muelle".gov.lastname = "de León";
	period.Towns.Oxbay.Name = "San Luis";
	period.Towns.Oxbay.nation = SPAIN;
	period.Towns.Greenford.Name = "Santa Ines";
	period.Towns.Greenford.nation = SPAIN;
	period.Towns.Redmond.Name = "Villa de la Vega";
	period.Towns.Redmond.nation = SPAIN;
	period.Towns.Redmond.gov.name = "Juan";
	period.Towns.Redmond.gov.lastname = "de Esquivel";
	period.Towns.Charlestown.Name = "Pueblo Carlos";
	period.Towns.Charlestown.nation = SPAIN;
	period.Towns.Charlestown.gov.name = "Gonzalo";
	period.Towns.Charlestown.gov.middlename = "Pérez";
	period.Towns.Charlestown.gov.lastname = "de Angulo";
	period.Towns."Port au Prince".Name = "Santa Maria del Puerto";
	period.Towns."Port au Prince".nation = SPAIN;
	period.Towns."Port au Prince".gov.name = "Nicolás";
	period.Towns."Port au Prince".gov.lastname = "de Ovando";
	period.Towns."Port au Prince".gov.sex = "man";
	period.Towns.Tortuga.relation_to_pirates = RELATION_NEUTRAL;
	period.Towns."Grand Turk".gov.name = "Diego";
	period.Towns."Grand Turk".gov.lastname = "de Mazariegos";
	period.Towns."Santo Domingo".gov.name = "Diego";
	period.Towns."Santo Domingo".gov.lastname = "Columbus";
	period.Towns."Grand Cayman".Name = "Cumana";
	period.Towns."Grand Cayman".nation = SPAIN;
	period.Towns."Grand Cayman".gov.name = "Francisco";
	period.Towns."Grand Cayman".gov.middlename = "García";
	period.Towns."Grand Cayman".gov.lastname = "Osorio";
	period.Towns.Havana.Name = "San Cristobal de la Habana";
	period.Towns.Havana.gov.name = "Hernando";
	period.Towns.Havana.gov.lastname = "de Soto";
	period.Towns.Santiago.Name = "Santiago de Cuba";
	period.Towns.Santiago.gov.name = "Pedro";
	period.Towns.Santiago.gov.middlename = "Menéndez";
	period.Towns.Santiago.gov.lastname = "de Avilés";
	//period.Towns."Pointe a Pitre" = "Guadalupe";					// what's this for???
//	period.Towns."Pointe a Pitre".disable = true;					// not working entirely right yet
	period.Towns."Pointe a Pitre".gov.name = "Gabriel";
	period.Towns."Pointe a Pitre".gov.lastname = "Montalvo";
//	period.Towns.Philipsburg.disable = true;						// not working entirely right yet
//	period.Towns.Marigot.disable = true;							// not working entirely right yet
	period.Towns.Eleuthera.Name = "Puerto la Cruz";
	period.Towns.Eleuthera.nation = SPAIN;
	period.Towns.Eleuthera.gov.name = "Francisco";
	period.Towns.Eleuthera.gov.lastname = "Carreño";
	period.Towns.Alice.Name = "San Elena";
	period.Towns.Alice.nation = SPAIN;
	period.Towns.Alice.gov.name = "Gaspar";
	period.Towns.Alice.gov.lastname = "de Torres";
	n++;

	makeref(period, Periods[n]);
	period.name = "The Spanish Main";
	period.date.start = "1600";
	period.date.end = "1679";
	period.Royal.England.Name = "James I Stuart";
	period.Royal.England.Title = XI_ConvertString("His Royal Majesty");
	period.Royal.France.Name = "Louis XIII le Juste";
	period.Royal.France.Title = XI_ConvertString("His Most Christian Majesty");
	period.Royal.Spain.Name = "Felipe III";
	period.Royal.Spain.Title = XI_ConvertString("His Most Catholic Majesty");
	period.Royal.Pirate.Name = "Abraham Blauvelt";
	period.Royal.Pirate.Title = XI_ConvertString("The chief");
	period.Royal.Holland.Title = XI_ConvertString("The Dutch Republic");
	period.Royal.Portugal.Name = "Filipe II"; // = Felipe III
	period.Royal.Portugal.Title = XI_ConvertString("His Most Faithful Majesty");
	if (SWEDEN_ALLOWED)
	{
		period.Nations.Guest1 = "Sweden";
		period.Royal.Sweden.Name = "Gustav II Adolf";
		period.Royal.Sweden.Title = XI_ConvertString("King of Sweden");
		period.Relations.Sweden.England = RELATION_NEUTRAL;
		period.Relations.Sweden.France = RELATION_NEUTRAL;
		period.Relations.Sweden.Spain = RELATION_NEUTRAL;
		period.Relations.Sweden.Holland = RELATION_NEUTRAL;
		period.Relations.Sweden.Portugal = RELATION_NEUTRAL;
	}
	period.Relations.England.France = RELATION_FRIEND;
	period.Relations.England.Spain = RELATION_ENEMY;
	period.Relations.England.Holland = RELATION_FRIEND;
	period.Relations.England.Portugal = RELATION_ENEMY;
	period.Relations.France.Spain = RELATION_ENEMY;
	period.Relations.France.Holland = RELATION_FRIEND;
	period.Relations.France.Portugal = RELATION_ENEMY;
	period.Relations.Spain.Holland = RELATION_ENEMY;
	period.Relations.Spain.Portugal = RELATION_ENEMY;
	period.Relations.Holland.Portugal = RELATION_ENEMY;
	period.Islands.Conceicao.Name = "Concepcion";
//	period.Islands.Douwesen.Name = "Isla do Palo Brasil";			// PB: For Assassin storyline
//	period.Islands.Douwesen.smuggling_nation = SPAIN;				// PB: For Assassin storyline
//	period.Islands.Guadeloupe.Name = "Santa Maria de Guadalupe de Extremadura";
//	period.Islands.Guadeloupe.smuggling_nation = SPAIN;
	period.Islands.SaintMartin.Name = "Isla de San Martin";
	period.Islands.SaintMartin.smuggling_nation = SPAIN;
	period.Islands.Turks.Name = "San Salvador";
	period.Islands.Turks.smuggling_nation = SPAIN;
	period.Islands.Eleuthera.smuggling_nation = SPAIN;
	period.Islands.IslaMona.smuggling_nation = ENGLAND;				// PB: For Assassin storyline
	period.Islands.Colombia.Name = "Kingdom of Granada";
	period.Towns."Isla Muelle".gov.name = "Juan";
	period.Towns."Isla Muelle".gov.middlename = "Ponce";
	period.Towns."Isla Muelle".gov.lastname = "de León";
	period.Towns.Conceicao.gov.name = "Francisco";
	period.Towns.Conceicao.gov.lastname = "de Venegas";
//	period.Towns.Douwesen.Name = "Palo Brasil";						// PB: For Assassin storyline
//	period.Towns.Douwesen.nation = SPAIN;							// PB: For Assassin storyline
//	period.Towns.Douwesen.gov.name = "Diego";						// PB: For Assassin storyline
//	period.Towns.Douwesen.gov.lastname = "Rangel";					// PB: For Assassin storyline
	period.Towns."Falaise de Fleur".gov.name = "Francisco";
	period.Towns."Falaise de Fleur".gov.lastname = "Terril";
	period.Towns."Isla Muelle".gov.name = "Sancho";
	period.Towns."Isla Muelle".gov.middlename = "Ochoa";
	period.Towns."Isla Muelle".gov.lastname = "de Castro";
	period.Towns.Redmond.gov.name = "Sir George";
	period.Towns.Redmond.gov.lastname = "Ayscue";
	period.Towns.Redmond.relation_to_pirates = RELATION_NEUTRAL;
	period.Towns.Charlestown.gov.name = "Anthony";
	period.Towns.Charlestown.gov.lastname = "Hilton";
	period.Towns."Port au Prince".Name = "Hopital";
	period.Towns."Port au Prince".relation_to_pirates = RELATION_NEUTRAL;
	period.Towns.Tortuga.relation_to_pirates = RELATION_NEUTRAL;
	period.Towns."Grand Turk".gov.name = "Juan";
	period.Towns."Grand Turk".gov.lastname = "de Salamanca";
	period.Towns."Santo Domingo".gov.name = "Juan";
	period.Towns."Santo Domingo".gov.middlename = "de Montanos";
	period.Towns."Santo Domingo".gov.lastname = "Blázquez";
	period.Towns."Grand Cayman".gov.name = "Francisco";
	period.Towns."Grand Cayman".gov.lastname = "Xelder";
	period.Towns.Havana.gov.name = "Pedro";
	period.Towns.Havana.gov.lastname = "Valdés";
	period.Towns.Santiago.gov.name = "Gaspar";
	period.Towns.Santiago.gov.middlename = "Ruíz";
	period.Towns.Santiago.gov.lastname = "de Pereda";
	period.Towns."Pointe a Pitre".gov.name = "José";
	period.Towns."Pointe a Pitre".gov.middlename = "Fernandez";
	period.Towns."Pointe a Pitre".gov.lastname = "Córdoba";
	period.Towns.Eleuthera.Name = "Puerto la Cruz";
	period.Towns.Eleuthera.nation = SPAIN;
	period.Towns.Alice.gov.name = "Francis";
	period.Towns.Alice.gov.lastname = "Willoughby";
	n++;

	makeref(period, Periods[n]);
	period.name = "Golden Age of Piracy";
	period.date.start = "1680";
	period.date.end = "1739";
	period.Nations.Name.England = "Britain";
	period.Nations.OfficialName.England = "Great Britain";
	period.Royal.England.Name = "Anne of Great Britain";
	period.Royal.England.Title = XI_ConvertString("Her Royal Majesty");
	period.Royal.France.Name = "Louis XIV le Grand";
	period.Royal.France.Title = XI_ConvertString("His Most Christian Majesty");
	period.Royal.Spain.Name = "Carlos II";
	period.Royal.Spain.Title = XI_ConvertString("His Most Catholic Majesty");
	period.Royal.Pirate.Name = "Isaac Rochussen";
	period.Royal.Pirate.Title = XI_ConvertString("The chief");
	period.Royal.Holland.Title = XI_ConvertString("The Dutch Republic");
	period.Royal.Portugal.Name = "Pedro II";
	period.Royal.Portugal.Title = XI_ConvertString("His Most Faithful Majesty");
	if (SWEDEN_ALLOWED)
	{
		period.Nations.Guest1 = "Sweden";
		period.Royal.Sweden.Name = "Karl XII";
		period.Royal.Sweden.Title = XI_ConvertString("of Sweden");
		period.Relations.Sweden.England = RELATION_NEUTRAL;
		period.Relations.Sweden.France = RELATION_NEUTRAL;
		period.Relations.Sweden.Spain = RELATION_NEUTRAL;
		period.Relations.Sweden.Holland = RELATION_NEUTRAL;
		period.Relations.Sweden.Portugal = RELATION_NEUTRAL;
	}
	period.Relations.England.France = RELATION_ENEMY;
	period.Relations.England.Spain = RELATION_ENEMY;
	period.Relations.England.Holland = RELATION_FRIEND;
	period.Relations.England.Portugal = RELATION_FRIEND;
	period.Relations.France.Spain = RELATION_FRIEND;
	period.Relations.France.Holland = RELATION_ENEMY;
	period.Relations.France.Portugal = RELATION_ENEMY;
	period.Relations.Spain.Holland = RELATION_ENEMY;
	period.Relations.Spain.Portugal = RELATION_ENEMY;
	period.Relations.Holland.Portugal = RELATION_FRIEND;
	period.Islands.Turks.smuggling_nation = PIRATE;
	period.Islands.Conceicao.Name = "La Grenade";
	period.Islands.Colombia.Name = "New Granada";
	period.Towns."Isla Muelle".gov.name = "Juan";
	period.Towns."Isla Muelle".gov.middlename = "Francisco";
	period.Towns."Isla Muelle".gov.lastname = "Medina";
	period.Towns.Conceicao.gov.name = "Joseph";
	period.Towns.Conceicao.gov.lastname = "de Bouloc";
	period.Towns."Isla Muelle".gov.name = "Juan";
	period.Towns."Isla Muelle".gov.middlename = "Francisco";
	period.Towns."Isla Muelle".gov.lastname = "Medina";
	period.Towns.Redmond.gov.name = "Sir Henry";
	period.Towns.Redmond.gov.lastname = "Morgan";
	period.Towns.Redmond.gov.model = "Henry_Morgan";
	period.Towns.Charlestown.gov.name = "Sir William";
	period.Towns.Charlestown.gov.lastname = "Stapleton";
	period.Towns.Tortuga.relation_to_pirates = RELATION_NEUTRAL;
	period.Towns."Grand Turk".gov.name = "Juan";
	period.Towns."Grand Turk".gov.lastname = "de Tejeda";
	period.Towns."Santo Domingo".gov.name = "Ignacio";
	period.Towns."Santo Domingo".gov.middlename = "Pérez";
	period.Towns."Santo Domingo".gov.lastname = "Caro";
	period.Towns.Havana.gov.name = "Vicente";
	period.Towns.Havana.gov.lastname = "de Raja";
	period.Towns.Santiago.gov.name = "Dionisio";
	period.Towns.Santiago.gov.middlename = "Martínez";
	period.Towns.Santiago.gov.lastname = "de la Vega";
	period.Towns.Philipsburg.gov.name = "Jan";
	period.Towns.Philipsburg.gov.middlename = "Simonszoon";
	period.Towns.Philipsburg.gov.lastname = "de Buck";
	period.Towns.Marigot.gov.name = "Chevalier";
	period.Towns.Marigot.gov.middlename = "Martínez";
	period.Towns.Marigot.gov.lastname = "de Rionville";
	period.Towns.Eleuthera.Name = "Governor's Harbour";
	period.Towns.Eleuthera.gov.name = "Sir John";
	period.Towns.Eleuthera.gov.lastname = "Witham";
	period.Towns.Alice.gov.name = "Sir Richard";
	period.Towns.Alice.gov.lastname = "Dutton";
	n++;

	makeref(period, Periods[n]);
	period.name = "Colonial Powers";
	period.date.start = "1740";
	period.date.end = "1769";
	period.Nations.Name.England = "Britain";
	period.Nations.OfficialName.England = "Great Britain";
	period.Royal.England.Name = "George II";
	period.Royal.England.Title = XI_ConvertString("His Royal Majesty");
	period.Royal.France.Name = "Louis XV le Bien-Aimé";
	period.Royal.France.Title = XI_ConvertString("His Most Christian Majesty");
	period.Royal.Spain.Name = "Fernando V";
	period.Royal.Spain.Title = XI_ConvertString("His Most Catholic Majesty");
	period.Royal.Pirate.Name = "Bartholomew Roberts";
	period.Royal.Pirate.Title = XI_ConvertString("The chief");
	period.Royal.Holland.Title = XI_ConvertString("The Dutch Republic");
	period.Royal.Portugal.Name = "José I";
	period.Royal.Portugal.Title = XI_ConvertString("His Most Faithful Majesty");
	if (SWEDEN_ALLOWED)
	{
		period.Nations.Guest1 = "Sweden";
		period.Royal.Sweden.Name = "Adolf Fredrik";
		period.Royal.Sweden.Title = XI_ConvertString("King of Sweden");
		period.Relations.Sweden.England = RELATION_NEUTRAL;
		period.Relations.Sweden.France = RELATION_NEUTRAL;
		period.Relations.Sweden.Spain = RELATION_NEUTRAL;
		period.Relations.Sweden.Holland = RELATION_NEUTRAL;
		period.Relations.Sweden.Portugal = RELATION_NEUTRAL;
	}
	period.Relations.England.France = RELATION_ENEMY;
	period.Relations.England.Spain = RELATION_ENEMY;
	period.Relations.England.Holland = RELATION_FRIEND;
	period.Relations.England.Portugal = RELATION_FRIEND;
	period.Relations.France.Spain = RELATION_FRIEND;
	period.Relations.France.Holland = RELATION_ENEMY;
	period.Relations.France.Portugal = RELATION_ENEMY;
	period.Relations.Spain.Holland = RELATION_ENEMY;
	period.Relations.Spain.Portugal = RELATION_ENEMY;
	period.Relations.Holland.Portugal = RELATION_NEUTRAL;
	period.Islands.Conceicao.Name = "La Grenade";
	period.Islands.Hispaniola.smuggling_nation = FRANCE;
	period.Islands.Colombia.Name = "New Granada";
	period.Islands.Turks.smuggling_nation = PIRATE;			// Grey Roger: to match Grand Turk nation
	period.Towns."Isla Muelle".gov.name = "Juan";
	period.Towns."Isla Muelle".gov.middlename = "José";
	period.Towns."Isla Muelle".gov.lastname = "Colomo";
	period.Towns.Conceicao.gov.name = "Gabriel";
	period.Towns.Conceicao.gov.lastname = "de Luján";
	period.Towns."Falaise de Fleur".gov.name = "Joseph";
	period.Towns."Falaise de Fleur".gov.middlename = "Claude";
	period.Towns."Falaise de Fleur".gov.lastname = "Le Moigne II";
	period.Towns."Falaise de Fleur".gov.model = "huber_Fra3_17"; 	// Thomas the Terror
	period.Towns."Isla Muelle".gov.name = "Juan";
	period.Towns."Isla Muelle".gov.middlename = "José";
	period.Towns."Isla Muelle".gov.lastname = "Colomo";
	period.Towns.Redmond.gov.name = "Sir Henry";
	period.Towns.Redmond.gov.lastname = "Moore";
	period.Towns.Charlestown.gov.name = "Michael";
	period.Towns.Charlestown.gov.lastname = "Smith";
	period.Towns.Tortuga.relation_to_pirates = RELATION_NEUTRAL;
	period.Towns."Santo Domingo".Name = "Santo Domingo";
	period.Towns."Santo Domingo".nation = SPAIN;
	period.Towns."Santo Domingo".gov.name = "Juan";
	period.Towns."Santo Domingo".gov.middlename = "José";
	period.Towns."Santo Domingo".gov.lastname = "Colomo";
	period.Towns.Havana.gov.name = "Juan";
	period.Towns.Havana.gov.middlename = "de Prado Mayera Portocarrero";
	period.Towns.Havana.gov.lastname = "y Luna";
	period.Towns.Santiago.gov.name = "Francisco";
	period.Towns.Santiago.gov.middlename = "Antonio Cagigal";
	period.Towns.Santiago.gov.lastname = "de la Vega";
	period.Towns."Pointe a Pitre".gov.name = "Gabriel";
	period.Towns."Pointe a Pitre".gov.middlename = "d'Erchigny";
	period.Towns."Pointe a Pitre".gov.lastname = "de Clieu";
	period.Towns.Philipsburg.gov.name = "Jan";
	period.Towns.Philipsburg.gov.lastname = "de Wever";
	period.Towns.Marigot.gov.name = "Louis";
	period.Towns.Marigot.gov.middlename = "Guillaume";
	period.Towns.Marigot.gov.lastname = "Durepaire";
	period.Towns.Eleuthera.Name = "Governor's Harbour";
	period.Towns.Eleuthera.gov.name = "Sir Thomas";
	period.Towns.Eleuthera.gov.lastname = "Robinson";
	period.Towns.Alice.gov.name = "Henry";
	period.Towns.Alice.gov.lastname = "Grenville";
	n++;

	makeref(period, Periods[n]);
	period.name = "Revolutions";
	period.date.start = "1770";
	period.date.end = "1789";
	period.Nations.Guest1 = "America";
	period.Nations.Name.England = "Britain";
	period.Nations.Name.America = "United States";
	period.Nations.OfficialName.England = "Great Britain";
	period.Nations.OfficialName.France = "French Republic";
	period.Nations.OfficialName.America = "United States of America";
	period.Royal.England.Name = "George III";
	period.Royal.England.Title = XI_ConvertString("His Royal Majesty");
	period.Royal.France.Name = "Louis XVI";
	period.Royal.France.Title = XI_ConvertString("His Most Christian Majesty");
	period.Royal.Spain.Name = "Carlos III";
	period.Royal.Spain.Title = XI_ConvertString("His Most Catholic Majesty");
	period.Royal.Pirate.Name = "Peter Alston";
	period.Royal.Pirate.Title = XI_ConvertString("The chief");
	period.Royal.Holland.Title = XI_ConvertString("The Dutch Republic");
	period.Royal.Portugal.Name = "Pedro III and Maria I";
	period.Royal.Portugal.Title = XI_ConvertString("The Most Faithful Majesties of");
	period.Royal.America.Name = "George Washington";
	period.Royal.America.Title = XI_ConvertString("President");
	period.Relations.England.France = RELATION_ENEMY;
	period.Relations.England.Spain = RELATION_ENEMY;
	period.Relations.England.Holland = RELATION_ENEMY;
	period.Relations.England.Portugal = RELATION_FRIEND;
	period.Relations.England.America = RELATION_ENEMY;
	period.Relations.France.Spain = RELATION_FRIEND;
	period.Relations.France.Holland = RELATION_FRIEND;
	period.Relations.France.Portugal = RELATION_NEUTRAL;
	period.Relations.France.America = RELATION_FRIEND;
	period.Relations.Spain.Holland = RELATION_FRIEND;
	period.Relations.Spain.Portugal = RELATION_NEUTRAL;
	period.Relations.Spain.America = RELATION_FRIEND;
	period.Relations.Holland.Portugal = RELATION_NEUTRAL;
	period.Relations.Holland.America = RELATION_FRIEND;
	period.Relations.Portugal.America = RELATION_NEUTRAL;
	period.Islands.Conceicao.smuggling_nation = ENGLAND;
	period.Islands.Battle_Rocks.smuggling_nation = ENGLAND;
	period.Islands.Hispaniola.smuggling_nation = FRANCE;
	period.Islands.Eleuthera.smuggling_nation = AMERICA;
	period.Islands.Colombia.Name = "New Granada";
	period.Islands.Turks.smuggling_nation = ENGLAND;		// Grey Roger: to match Grand Turk nation
	period.Towns."Falaise de Fleur".gov.name = "Ulysses";
	period.Towns."Falaise de Fleur".gov.lastname = "FitzMaurice";
	period.Towns."Isla Muelle".gov.name = "Miguel";
	period.Towns."Isla Muelle".gov.lastname = "de Musesas";
	period.Towns.Conceicao.Name = "Saint George";
	period.Towns.Conceicao.nation = ENGLAND;
	period.Towns.Conceicao.gov.name = "Samuel";
	period.Towns.Conceicao.gov.lastname = "Mitchell";
	period.Towns.Redmond.Name = "Kingston";
	period.Towns.Redmond.gov.name = "Sir John";
	period.Towns.Redmond.gov.lastname = "Dalling";
	period.Towns.Charlestown.gov.name = "Joseph";
	period.Towns.Charlestown.gov.middlename = "Richardson";
	period.Towns.Charlestown.gov.lastname = "Herbert";
	period.Towns."Grand Turk".nation = ENGLAND;
	period.Towns."Grand Turk".gov.name = "Daniel";
	period.Towns."Grand Turk".gov.lastname = "Sicilian";
	period.Towns.Tortuga.relation_to_pirates = RELATION_NEUTRAL;
	period.Towns."Santo Domingo".Name = "Santo Domingo";
	period.Towns."Santo Domingo".nation = SPAIN;
	period.Towns."Santo Domingo".gov.name = "Joaquín";
	period.Towns."Santo Domingo".gov.middlename = "García";
	period.Towns."Santo Domingo".gov.lastname = "y Moreno";
	period.Towns.Havana.gov.name = "José";
	period.Towns.Havana.gov.middlename = "Manuel";
	period.Towns.Havana.gov.lastname = "de Ezpeleta";
	period.Towns.Santiago.gov.name = "Domingo";
	period.Towns.Santiago.gov.middlename = "Cabello";
	period.Towns.Santiago.gov.lastname = "y Robles";
	period.Towns."Pointe a Pitre".gov.name = "Louis";
	period.Towns."Pointe a Pitre".gov.middlename = "François";
	period.Towns."Pointe a Pitre".gov.lastname = "de Dion";
	period.Towns.Philipsburg.gov.name = "Jan";
	period.Towns.Philipsburg.gov.lastname = "de Wever";
	period.Towns.Marigot.gov.name = "Louis";
	period.Towns.Marigot.gov.middlename = "Guillaume";
	period.Towns.Marigot.gov.lastname = "Durepaire";
	period.Towns.Eleuthera.nation = AMERICA;
	period.Towns.Alice.nation = AMERICA;
	period.Towns.Alice.gov.name = "James";
	period.Towns.Alice.gov.lastname = "Cunninghame";
	n++;

	makeref(period, Periods[n]);
	period.name = "Napoleonic";
	period.date.start = "1790";
	period.date.end = "1830";
	period.Nations.Guest1 = "America";
	period.Nations.Name.England = "Britain";
	period.Nations.Name.America = "United States";
	period.Nations.OfficialName.England = "United Kingdom of Great Britain";
	period.Nations.OfficialName.France = "Empire of the French";
	period.Nations.OfficialName.Holland = "Batavian Republic";
	period.Nations.OfficialName.America = "United States of America";
	period.Royal.England.Name = "George III";
	period.Royal.England.Title = XI_ConvertString("His Royal Majesty");
	period.Royal.France.Name = "Napoléon Bonaparte";
	period.Royal.France.Title = XI_ConvertString("L'Empereur");
	period.Royal.Spain.Name = "Joseph-Napoléon Bonaparte";
	period.Royal.Spain.Title = XI_ConvertString("His Majesty");
	period.Royal.Pirate.Name = "Henri Caesar";
	period.Royal.Pirate.Title = XI_ConvertString("The chief");
	period.Royal.Holland.Title = XI_ConvertString("The Dutch Republic");
	period.Royal.Portugal.Name = "Maria I"; // DeathDaisy: Pedro was already dead in 1790
	period.Royal.Portugal.Title = XI_ConvertString("Her Most Faithful Majesty");
	period.Royal.America.Name = "Thomas Jefferson";
	period.Royal.America.Title = XI_ConvertString("President");
	period.Relations.England.France = RELATION_ENEMY;
	period.Relations.England.Spain = RELATION_ENEMY;
	period.Relations.England.Holland = RELATION_ENEMY;
	period.Relations.England.Portugal = RELATION_FRIEND;
	period.Relations.England.America = RELATION_NEUTRAL;
	period.Relations.France.Spain = RELATION_FRIEND;
	period.Relations.France.Holland = RELATION_FRIEND;
	period.Relations.France.Portugal = RELATION_ENEMY;
	period.Relations.France.America = RELATION_NEUTRAL;
	period.Relations.Spain.Holland = RELATION_ENEMY;
	period.Relations.Spain.Portugal = RELATION_ENEMY;
	period.Relations.Spain.America = RELATION_NEUTRAL;
	period.Relations.Holland.Portugal = RELATION_ENEMY;
	period.Relations.Holland.America = RELATION_FRIEND;
	period.Relations.Portugal.America = RELATION_FRIEND;
	period.Islands.Conceicao.smuggling_nation = ENGLAND;
	period.Islands.Battle_Rocks.smuggling_nation = ENGLAND;
	period.Islands.Hispaniola.smuggling_nation = FRANCE;
	period.Islands.Eleuthera.smuggling_nation = AMERICA;
	period.Islands.Turks.smuggling_nation = ENGLAND;		// Grey Roger: to match Grand Turk nation
	period.Towns."Falaise de Fleur".gov.name = "Louis Thomas";
	period.Towns."Falaise de Fleur".gov.middlename = "Villaret";
	period.Towns."Falaise de Fleur".gov.lastname = "de Joyeuse";
	period.Towns."Isla Muelle".gov.name = "Francisco";
	period.Towns."Isla Muelle".gov.lastname = "Torralbo";
	period.Towns.Conceicao.Name = "Saint George";
	period.Towns.Conceicao.nation = ENGLAND;
	period.Towns.Conceicao.gov.name = "Samuel";
	period.Towns.Conceicao.gov.lastname = "Mitchell";
	period.Towns.Redmond.Name = "Kingston";
	period.Towns.Redmond.gov.name = "Sir George";
	period.Towns.Redmond.gov.lastname = "Nugent";
	period.Towns.Charlestown.gov.name = "James";
	period.Towns.Charlestown.gov.lastname = "Daniell";
	period.Towns."Grand Turk".nation = ENGLAND;
	period.Towns."Grand Turk".gov.name = "Daniel";
	period.Towns."Grand Turk".gov.lastname = "Sicilian";
	period.Towns.Tortuga.relation_to_pirates = RELATION_NEUTRAL;
	period.Towns."Santo Domingo".Name = "Saint Domingue";
	period.Towns."Santo Domingo".nation = FRANCE;
	period.Towns."Santo Domingo".gov.name = "Louis";
	period.Towns."Santo Domingo".gov.middlename = "Marie";
	period.Towns."Santo Domingo".gov.lastname = "Ferrand";
	period.Towns.Havana.gov.name = "Juan";
	period.Towns.Havana.gov.middlename = "Ruíz";
	period.Towns.Havana.gov.lastname = "de Apodaca";
	period.Towns.Santiago.gov.name = "José";
	period.Towns.Santiago.gov.lastname = "Cienfuegos";
	period.Towns."Pointe a Pitre".gov.name = "Victor";
	period.Towns."Pointe a Pitre".gov.lastname = "Collot";
	period.Towns.Marigot.gov.name = "Louis";
	period.Towns.Marigot.gov.middlename = "Guillaume";
	period.Towns.Marigot.gov.lastname = "Durepaire";
	period.Towns.Eleuthera.nation = AMERICA;
	period.Towns.Eleuthera.gov.name = "William";
	period.Towns.Eleuthera.gov.lastname = "Bishop";
	period.Towns.Alice.nation = AMERICA;
	period.Towns.Alice.gov.name = "Francis";
	period.Towns.Alice.gov.middlename = "Humberstone";
	period.Towns.Alice.gov.lastname = "Mackenzie";
	n++;

	PeriodsQuantity = n;
}

string GetPeriodName(int idx)
{
	if (idx < 0 || idx >= PeriodsQuantity) return "";
	ref period; makeref(period, Periods[idx]);
	if (!CheckAttribute(period, "name")) return "";
	return period.name;
}

int GetPeriodFromYear(int year)
{
	ref period;
	for (int i = 0; i < PeriodsQuantity; i++) {
		makeref(period, Periods[i]);
		if (sti(period.date.start) <= year && sti(period.date.end) >= year) return i;
	}
	return -1;
}

int GetCurrentPeriod()
{
	ref period; makeref(period, Periods[0]);
	if (!CheckAttribute(period, "current")) return PERIOD_GOLDEN_AGE_OF_PIRACY;
	return sti(period.current);
}

void SetCurrentPeriod(int cperiod)
{
	ref period; makeref(period, Periods[0]);
	if(cperiod < 0 || cperiod >= MAX_PERIODS) period.current = PERIOD_GOLDEN_AGE_OF_PIRACY;
	else period.current = cperiod;
}

// PB -->
void InitTownNationalities()
{
	int i;
	aref item;
	int iNation = ProfessionalNavyNation();
	ref pchar = GetMainCharacter();

	if(GetTownNation("Redmond") == SPAIN)
	{
		locations[FindLocation("Redmond_Port")].image = "Town_Redmond_Port_Spain";
		locations[FindLocation("Redmond_Port")].filespath.textures = "locations\SPAIN";
		locations[FindLocation("Redmond_Town_01")].image = "Town_Redmond_Town_01_Spain";
		locations[FindLocation("Redmond_Town_01")].filespath.textures = "locations\SPAIN";
		locations[FindLocation("Redmond_Town_03")].image = "Town_Redmond_Town_03_Spain";
		locations[FindLocation("Redmond_Town_03")].filespath.textures = "locations\SPAIN";
		locations[FindLocation("Redmond_Town_04")].image = "Town_Redmond_Town_04_Spain";
		locations[FindLocation("Redmond_Town_04")].filespath.textures = "locations\SPAIN";
	}
	if(GetTownNation("Douwesen") == SPAIN)
	{
		locations[FindLocation("Douwesen_port")].image = "Town_Douwesen_Port_Spain";
		locations[FindLocation("Douwesen_port")].filespath.textures = "locations\SPAIN";
		locations[FindLocation("Douwesen_town")].image = "Town_Douwesen_Town_Spain";
		locations[FindLocation("Douwesen_town")].filespath.textures = "locations\SPAIN";
	}
	if(GetTownNation("Grand Cayman") == SPAIN)
	{
		locations[FindLocation("Cayman_Port")].image = "Town_FalaiseDeFleur_Port2_Spain";
		locations[FindLocation("Cayman_Port")].filespath.textures = "locations\SPAIN";
		locations[FindLocation("Grand_Cayman_Town")].image = "Town_Douwesen_Town_Spain";
		locations[FindLocation("Grand_Cayman_Town")].filespath.textures = "locations\SPAIN";
	}
	if(GetTownNation("Santo Domingo") == FRANCE)
	{
		locations[FindLocation("Santo_Domingo_port")].image = "Town_Greenford_Port_France";
		locations[FindLocation("Santo_Domingo_port")].filespath.textures = "locations\FRANCE";
		//locations[FindLocation("Santo_Domingo_town")].image = "Town_Greenford_Town";			// PB: Location now replaced
		//locations[FindLocation("Santo_Domingo_town")].filespath.textures = "locations\FRANCE";	// PB: Always looks Spanish
	}
	if(GetTownNation("Conceicao") == ENGLAND)
	{
		locations[FindLocation("Conceicao_port")].image = "Town_Conceicao_Port_England";
		locations[FindLocation("Conceicao_port")].filespath.textures = "locations\ENGLAND";
		locations[FindLocation("Conceicao_town")].image = "Town_Conceicao_Town_England";
		locations[FindLocation("Conceicao_town")].filespath.textures = "locations\ENGLAND";
	}
	if(GetTownNation("Falaise de Fleur") == SPAIN)
	{
		locations[FindLocation("Falaise_de_fleur_port_01")].image = "Town_FalaiseDeFleur_Port_Spa";
		locations[FindLocation("Falaise_de_fleur_port_01")].filespath.textures = "locations\SPAIN";
		locations[FindLocation("Falaise_de_fleur_port_02")].image = "Town_FalaiseDeFleur_Port2_Spa";
		locations[FindLocation("Falaise_de_fleur_port_02")].filespath.textures = "locations\SPAIN";
		locations[FindLocation("Falaise_de_fleur_location_02")].image = "Town_FalaiseDeFleur_Town_01_Spa";
		locations[FindLocation("Falaise_de_fleur_location_02")].filespath.textures = "locations\SPAIN";
		locations[FindLocation("Falaise_de_fleur_location_03")].image = "Town_FalaiseDeFleur_Town_02_Spa";
		locations[FindLocation("Falaise_de_fleur_location_03")].filespath.textures = "locations\SPAIN";
		locations[FindLocation("Falaise_de_fleur_location_04")].image = "Town_FalaiseDeFleur_Town_03_Spa";
		locations[FindLocation("Falaise_de_fleur_location_04")].filespath.textures = "locations\SPAIN";
		locations[FindLocation("Falaise_de_fleur_location_05")].image = "Town_FalaiseDeFleur_Town_04_Spa";
		locations[FindLocation("Falaise_de_fleur_location_05")].filespath.textures = "locations\SPAIN";
		locations[FindLocation("Falaise_De_Fleur_Jungle")].image = "Town_FalaiseDeFleur_Exit_Spa";
		locations[FindLocation("Falaise_De_Fleur_Jungle")].filespath.textures = "locations\SPAIN";
	}

	switch(GetCurrentPeriod())
	{
		case PERIOD_EARLY_EXPLORERS:
			ChangeCharacterAddressGroup(characterFromID("English Emissary"), "Tortuga_Townhall",  "goto","goto2");
			ChangeCharacterAddressGroup(characterFromID("Dutch Emissary"),   "Tortuga_Townhall",  "Sit", "Sit1");
			ChangeCharacterAddressGroup(characterFromID("English Tailor"),   "Tortuga_tailorsShop", "goto","stay2");
			ChangeCharacterAddressGroup(characterFromID("Dutch Tailor"),     "Tortuga_tailorsShop", "goto","stay3");
			Towns[GetTownIndex("Pointe a Pitre")].skiptrade = true;	// Block trade to towns which shouldn't exist
			Towns[GetTownIndex("Oranjestad")].skiptrade = true;

			if (Items_FindItem("mapGuadeloupe", &item) >= 0) {
				item.skiptrade = true;
				item.skipsell  = true;
			}
			if (Items_FindItem("mapSaintMartin", &item) >= 0) {
				item.skiptrade = true;
				item.skipsell  = true;
			}
			if (Items_FindItem("mapAruba", &item) >= 0) {
				item.skiptrade = true;
				item.skipsell  = true;
			}
			if (Items_FindItem("mapCuracao", &item) >= 0) {
				item.skiptrade = true;
				item.skipsell  = true;
			}
			if (Items_FindItem("mapAntigua", &item) >= 0) {
				item.skiptrade = true;
				item.skipsell  = true;
			}
		/*	if (Items_FindItem("musketbullets", &item) >= 0) {
				item.rare      = 0.00;
				item.skiptrade = true;
				item.skipsell  = true;
			}*/
		break;

		case PERIOD_THE_SPANISH_MAIN:
			if (SWEDEN_ALLOWED)
			{
				if (GetDataYear() == 1668) ChangeCharacterAddressGroup(CharacterFromID("Swedish Emissary"), "Philipsburg_residence",  "goto","goto5");
				else ChangeCharacterAddressGroup(CharacterFromID("Swedish Emissary"), "Marigot_mansion_hall",  "goto","goto5");
			}
		/*	if (Items_FindItem("musketbullets", &item) >= 0) {
				item.rare      = 0.00;
				item.skiptrade = true;
				item.skipsell  = true;
			}*/
		break;

		case PERIOD_GOLDEN_AGE_OF_PIRACY:
			if (SWEDEN_ALLOWED)
			{
				ChangeCharacterAddressGroup(CharacterFromID("Swedish Emissary"), "Marigot_mansion_hall",  "goto","goto5");
				if (GetDataYear() >= 1688 && GetDataYear() <= 1691) ChangeCharacterAddressGroup(CharacterFromID("Swedish Emissary"), "Philipsburg_residence",  "goto","goto5");
				if (GetDataYear() == 1700) ChangeCharacterAddressGroup(CharacterFromID("Swedish Emissary"), "Philipsburg_residence",  "goto","goto5");
			}
		break;

		case PERIOD_COLONIAL_POWERS:
			locations[FindLocation("Tortuga_Tavern")].id.label = "The Faithful Bride";
			if (SWEDEN_ALLOWED)
			{
				ChangeCharacterAddressGroup(CharacterFromID("Swedish Emissary"), "Marigot_mansion_hall",  "goto","goto5");
			}
		break;

		case PERIOD_REVOLUTIONS:
			ChangeCharacterAddressGroup(characterFromID("Portuguese Emissary"), "Conceicao_townhall",   "Sit", "Sit3");
			ChangeCharacterAddressGroup(characterFromID("Portuguese Tailor"),   "Conceicao_TailorsShop","goto","locator6");
		break;

		case PERIOD_NAPOLEONIC:
			ChangeCharacterAddressGroup(characterFromID("Portuguese Emissary"), "Conceicao_townhall",   "Sit", "Sit3");
			ChangeCharacterAddressGroup(characterFromID("Portuguese Tailor"),   "Conceicao_TailorsShop","goto","locator6");
		break;
	}

	if(iNation != UNKNOWN_NATION)	JoinNavy(iNation); // For Commissioned Naval Officers

	// Claire Larrouse
	setCharacterShipLocation(characterFromID("Claire Larrouse"), "Muelle_port"); // boal

	//Voysey
	PChar.quest.Install_Voysey_And_Blythe.win_condition.l1 = "location";
	PChar.quest.Install_Voysey_And_Blythe.win_condition.l1.character = PChar.id;
	PChar.quest.Install_Voysey_And_Blythe.win_condition.l1.location = "QC_town_exit";
	PChar.quest.Install_Voysey_And_Blythe.win_condition = "Install_Voysey_And_Blythe";
	//Voysey

	//Hitman
	PChar.quest.Hitman = "";
	PChar.quest.Hit_start.win_condition.l1 = "location";
	PChar.quest.Hit_start.win_condition.l1.character = PChar.id;
	PChar.quest.Hit_start.win_condition.l1.location = "Conceicao_tavern";
	PChar.quest.Hit_start.win_condition = "Hit_start";
	//Hitman

	//Lucas
	PChar.quest.Lucas = "";
	PChar.quest.Luc_start.win_condition.l1 = "location";
	PChar.quest.Luc_start.win_condition.l1.character = PChar.id;
	PChar.quest.Luc_start.win_condition.l1.location = "Muelle_Residence";
	PChar.quest.Luc_start.win_condition = "Luc_start";
	if (Characters[GetCharacterIndex("Arabella Silehard")].lastname == TranslateString("","Silehard"))
	{
		Characters[GetCharacterIndex("Arabella Silehard")].lastname = Characters[GetCharacterIndex("John Clifford Brin")].lastname; // Name after actual governor
	}
	//Lucas

	//Edgar Attwood
	characters[GetCharacterIndex("Edgar Attwood")].quest.to_hire = "possible_to_hire_edgard";
	//Edgar Attwood

	//Bartolomeu
	PChar.quest.Bartolomeu = "";
	PChar.quest.Bart_start.win_condition.l1 = "location";
	PChar.quest.Bart_start.win_condition.l1.character = PChar.id;
	PChar.quest.Bart_start.win_condition.l1.location = "Grand_Cayman_Tavern";
	PChar.quest.Bart_start.win_condition = "Bart_start";
	//Bartolomeu

	//Turks quest
	PChar.quest.Turkshelp = "";
	PChar.quest.Turks_start.win_condition.l1 = "location";
	PChar.quest.Turks_start.win_condition.l1.character = PChar.id;
	PChar.quest.Turks_start.win_condition.l1.location = "Turks_Tavern";
	PChar.quest.Turks_start.win_condition = "Turks_start";
	//Turks quest

	//Missing Man quest
	PChar.quest.Missingman = "";
	PChar.quest.Missing_start.win_condition.l1 = "location";
	PChar.quest.Missing_start.win_condition.l1.character = PChar.id;
	PChar.quest.Missing_start.win_condition.l1.location = "PoPrince_town";
	PChar.quest.Missing_start.win_condition = "Missing_start";
	PChar.quest.Missing_start.skip = "yes";
	//Missing Man quest

	//Tortuga Atmosphere
	PChar.quest.Tortuga_atmosphere.win_condition.l1 = "location";
	PChar.quest.Tortuga_atmosphere.win_condition.l1.character = PChar.id;
	PChar.quest.Tortuga_atmosphere.win_condition.l1.location = "Tortuga_port";
	PChar.quest.Tortuga_atmosphere.win_condition = "Tortuga_atmosphere";
	PChar.quest.Tortuga_atmosphere.skip = "yes";
	//Tortuga Atmosphere

	//Santiago quest
	PChar.quest.Santiago = "";
	PChar.quest.Santiago_start.win_condition.l1 = "location";
	PChar.quest.Santiago_start.win_condition.l1.character = "Bartolomeu o Portugues";
	PChar.quest.Santiago_start.win_condition.l1.location = "Guadeloupe_Port";
	PChar.quest.Santiago_start.win_condition = "Santiago_start";
	PChar.quest.Santiago_start.skip = "yes";
	//Santiago quest

	//Colombian Silver quest
	PChar.quest.colombian_silver_start.win_condition.l1 = "location";
	PChar.quest.colombian_silver_start.win_condition.l1.character = PChar.id;
	PChar.quest.colombian_silver_start.win_condition.l1.location = "Smugglers_Tavern";
	PChar.quest.colombian_silver_start.win_condition = "colombian_silver_start";
	PChar.quest.colombian_silver_start.skip = "yes";
	//Colombian Silver quest

	//Traps for Martinique bridge and Crystal Skullquest
	PChar.quest.crysskull_bridge_trap1.win_condition.l1 = "locator";
	PChar.quest.crysskull_bridge_trap1.win_condition.l1.location = "FalaiseDeFleur_Bridge";
	PChar.quest.crysskull_bridge_trap1.win_condition.l1.locator_group = "goto";
	PChar.quest.crysskull_bridge_trap1.win_condition.l1.locator = "goto30";
	PChar.quest.crysskull_bridge_trap1.win_condition = "crysskull_bridge_trap";
	PChar.quest.crysskull_bridge_trap2.win_condition.l1 = "locator";
	PChar.quest.crysskull_bridge_trap2.win_condition.l1.location = "FalaiseDeFleur_Bridge";
	PChar.quest.crysskull_bridge_trap2.win_condition.l1.locator_group = "goto";
	PChar.quest.crysskull_bridge_trap2.win_condition.l1.locator = "goto40";
	PChar.quest.crysskull_bridge_trap2.win_condition = "crysskull_bridge_trap";
	//Traps for Martinique bridge and Crystal Skullquest

	// Captain Murphy Tribute
	PChar.quest.Murphy_tribute_activate.win_condition.l1 = "location";
	PChar.quest.Murphy_tribute_activate.win_condition.l1.location = "Capt_Murphy_house";
	PChar.quest.Murphy_tribute_activate.win_condition = "Murphy_tribute_activate";
	// Captain Murphy Tribute

	//JRH: Cartagena New_cloister
	PChar.quest.cloister_start.win_condition.l1 = "location";
	PChar.quest.cloister_start.win_condition.l1.location = "new_cloister_garden";
	PChar.quest.cloister_start.win_condition = "cloister_start";

	if(GetCurrentPeriod() == PERIOD_EARLY_EXPLORERS)
	{
		/* GR: Moved to "Preprocessor_Init()" in "utils.c" so that "Padre" is set up before preprocessing
		Characters[GetCharacterIndex("Father Bernard")].name = TranslateString("","Padre"); // Override random first name
		Characters[GetCharacterIndex("Father Jerald")].name = TranslateString("","Padre"); // Override random first name
		Characters[GetCharacterIndex("pater Jourdain")].name = TranslateString("","Padre"); // Override random first name
		ref ch = CharacterFromID("Father Gareth");
		ch.nation = GetTownNation("Redmond");
		SetRandomNameToCharacter(ch);
		ch.name = "Padre"; // Override random first name
		*/
		ChangeCharacterAddress(characterFromID("Contre-Amirale"), "none", ""); //Sinking the Vogelstruijs
		Characters[GetCharacterIndex("Milon Blacque")].lastname = GetMyLastName(CharacterFromID("Marc Blacque"));	// Saga of the Blacque Family
		Characters[GetCharacterIndex("Rachel Blacque")].lastname = GetMyLastName(CharacterFromID("Marc Blacque"));	// All family members have same last name
		Characters[GetCharacterIndex("Sabine Matton")].lastname = GetMyLastName(CharacterFromID("Arnaud Matton"));
	}
	else
	{
		//First Contact quest
		PChar.quest.Firstcontact = "";
		PChar.quest.Contact_start.win_condition.l1 = "location";
		PChar.quest.Contact_start.win_condition.l1.character = PChar.id;
		PChar.quest.Contact_start.win_condition.l1.location = "Grand_Cayman_townhall";
		PChar.quest.Contact_start.win_condition = "Contact_start";
		//First Contact quest
	}

	//Church_Help
	characters[GetCharacterIndex("Father Bernard")].quest.church_help.quest.Church_Help = "";
	//Church_help

	//Jackpot
	PChar.quest.Jackpot = "";
	PChar.quest.Jackpot_start.win_condition.l1 = "location";
	PChar.quest.Jackpot_start.win_condition.l1.character = PChar.id;
	PChar.quest.Jackpot_start.win_condition.l1.location = "Tortuga_tavern";
	PChar.quest.Jackpot_start.win_condition = "Jackpot_start";
	//Jackpot

	// No Blackbeard around if you're him yourself:
	if (!CheckAttribute(PChar, "quest.blackbeard_shore"))	ChangeCharacterAddressGroup(CharacterFromID("Blackbeard"), "none", "", "");
}
// PB <--

void GiveSoldierWeapon(ref curchar, int iNation)
{
	if(GetAttribute(curchar, "auto_weapons") == "off") return;		//JRH: skip auto given and equipped weapons
	DeleteAttribute      (curchar,"Items.gunpowder");
	DeleteAttribute      (curchar,"Items.pistolbullets");
	DeleteAttribute      (curchar,"Items.musketbullets");
	TakeItemFromCharacter(curchar, GetCharacterEquipByGroup(curchar, BLADE_ITEM_TYPE));
	TakeItemFromCharacter(curchar, GetCharacterEquipByGroup(curchar, GUN_ITEM_TYPE));

	string SoldierBlade = "";
	string SoldierGun   = "";
	if (bSeaActive && bAbordageStarted)
	{
		if(GetCurrentPeriod() >= PERIOD_GOLDEN_AGE_OF_PIRACY)
		{
			switch(iNation)
			{
				case ENGLAND:	SoldierBlade = "blade11";	break;		// ARF: Highlander (available from The Spanish Main)
				case FRANCE:	SoldierBlade = "blade13";	break;		// ARF: Duelling Rapier (available from The Spanish Main but marines get later)
				case SPAIN:		SoldierBlade = "blade47";	break;		// ARF: Light Tizona (available in all periods)
				case PIRATE:	SoldierBlade = "blade27";	break;		// GR: Bosun's Choice (available from The Golden Age of Piracy)
				case HOLLAND:	SoldierBlade = "blade19";	break;		// ARF: German Rapier (available from The Spanish Main but marines get later)
				case PORTUGAL:	SoldierBlade = "bladeC11";	break;		// GR: Milanese longsword (available from The Spanish Main but marines get later)
				case AMERICA:	SoldierBlade = "bladeC6";	break;		// ARF: Smallsword (available from The Golden Age of Piracy)
				// default:
				SoldierBlade = "blade36";								// ARF: Hunting Sword (all periods available), only for "non regular" nation
			}
			if(iNation == PIRATE)	SoldierGun = "pistol7";				// GR: Brace of Small Pistols, because pirates are getting a better than average sword
			else					SoldierGun = "pistol8";				// GR: Brace of Flintlock Pistols for periods from Golden Age of Piracy
			//else					SoldierGun = "pistolmtoon";			// PB: Musketoon for periods from Golden Age of Piracy
		}
		else
		{
			switch(iNation)
			{
				case ENGLAND:	SoldierBlade = "blade36";	break;		// ARF: Hunting Sword (available all periods)
				case FRANCE:	SoldierBlade = "blade3";	break;		// ARF: Badelaire (available all periods)
				case SPAIN:		SoldierBlade = "blade16";	break;		// ARF: Tizona (not available after Golden Age of Piracy)
				case PIRATE:	SoldierBlade = "blade6";	break;		// ARF: Schiavona (not available after Colonial Powers)
				case HOLLAND:	SoldierBlade = "blade21";	break;		// ARF: Falchion (not available after The Spanish Main)
				case PORTUGAL:	SoldierBlade = "blade15";	break;		// ARF: Iberian Longsword (not available after Golden Age of Piracy)
				case AMERICA:	SoldierBlade = "blade10";	break;		// ARF: Piranha (not available after Golden Age of Piracy, anyway AMERICA doesn't exist early)
				// default:
				SoldierBlade = "blade10";								// ARF: Piranha (not available after Golden Age of Piracy)
			}
			SoldierGun   = "pistol2";									// GR: Duelling Pistol for earlier periods
		}
	}
	else
	{
		switch(GetCurrentPeriod())
		{
			case PERIOD_EARLY_EXPLORERS:
				switch(iNation)
				{
					case ENGLAND:	SoldierBlade = "blade36";	break;		// ARF: Hunting Sword (available all periods)
					case FRANCE:	SoldierBlade = "blade3";	break;		// ARF: Badelaire (available all periods)
					case SPAIN:		SoldierBlade = "blade16";	break;		// ARF: Tizona (not available after Golden Age of Piracy)
					case PIRATE:	SoldierBlade = "blade6";	break;		// ARF: Schiavona (not available after Colonial Powers)
					case HOLLAND:	SoldierBlade = "blade21";	break;		// ARF: Falchion (not available after The Spanish Main)
					case PORTUGAL:	SoldierBlade = "blade15";	break;		// ARF: Iberian Longsword (not available after Golden Age of Piracy)
					case AMERICA:	SoldierBlade = "blade10";	break;		// ARF: Piranha (not available after Golden Age of Piracy, anyway AMERICA doesn't exist early)
					// default:
					SoldierBlade = "blade10";								// ARF: Piranha (not available after Golden Age of Piracy)
				}
				SoldierGun   = "Arguebuse";
			break;
			case PERIOD_THE_SPANISH_MAIN:
				switch(iNation)
				{
					case ENGLAND:	SoldierBlade = "blade36";	break;		// ARF: Hunting Sword (available all periods)
					case FRANCE:	SoldierBlade = "blade3";	break;		// ARF: Badelaire (available all periods)
					case SPAIN:		SoldierBlade = "blade16";	break;		// ARF: Tizona (not available after Golden Age of Piracy)
					case PIRATE:	SoldierBlade = "blade6";	break;		// ARF: Schiavona (not available after Colonial Powers)
					case HOLLAND:	SoldierBlade = "blade21";	break;		// ARF: Falchion (not available after The Spanish Main)
					case PORTUGAL:	SoldierBlade = "blade15";	break;		// ARF: Iberian Longsword (not available after Golden Age of Piracy)
					case AMERICA:	SoldierBlade = "blade10";	break;		// ARF: Piranha (not available after Golden Age of Piracy, anyway AMERICA doesn't exist early)
					// default:
					SoldierBlade = "blade10";								// ARF: Piranha (not available after Golden Age of Piracy)
				}
				SoldierGun   = "Arguebuse";
			break;
			case PERIOD_GOLDEN_AGE_OF_PIRACY:								// JRH: Musket for Golden Age of Piracy & Colonial Powers
				if(iNation == PIRATE)
				{
					SoldierBlade = "blade50";
					SoldierGun   = "pistolbbuss";
				}
				else
				{
					if(iNation == SWEDEN)
					{
						SoldierBlade = "bladeC6";
					}
					else SoldierBlade = "blade_mKnife";
					SoldierGun   = "pistolmket";
				}
			break;
			case PERIOD_COLONIAL_POWERS:									// JRH: Musket for Golden Age of Piracy & Colonial Powers
				if(iNation == PIRATE)
				{
					SoldierBlade = "blade50";
					SoldierGun   = "pistolbbuss";
				}
				else
				{
					if(iNation == SWEDEN)
					{
						SoldierBlade = "bladeC6";
					}
					else SoldierBlade = "blade_mKnife";
					SoldierGun   = "pistolmket";
				}
			break;
			case PERIOD_REVOLUTIONS:										// JRH: Bayonet Musket for Revolutions & Napoleonic
				if(iNation == PIRATE)
				{
					SoldierBlade = "blade50";
					SoldierGun   = "pistolbbuss";
				}
				else
				{
					SoldierBlade = "bladeX4";
					SoldierGun   = "pistolmketB";
				}
			break;
			case PERIOD_NAPOLEONIC:											// JRH: Bayonet Musket for Revolutions & Napoleonic
				if(iNation == PIRATE)
				{
					SoldierBlade = "blade50";
					SoldierGun   = "pistolbbuss";
				}
				else
				{
					SoldierBlade = "bladeX4";
					SoldierGun   = "pistolmketB";
				}
			break;
		}
	}

	GiveItem2Character  (curchar, SoldierBlade);
	EquipCharacterByItem(curchar, SoldierBlade);

	GiveItem2Character  (curchar, SoldierGun);
	EquipCharacterByItem(curchar, SoldierGun);

	// JRH: Ammo Mod -->
	if (ENABLE_AMMOMOD)
	{
		string GunBullets = "pistolbullets";
		switch(SoldierGun)
		{
			case "pistol7":		GunBullets = "pistolbullets";	break;
			case "pistolbbuss":	GunBullets = "pistolgrapes";	break;
			case "pistolmketB":	GunBullets = "musketbullets";	break;
			case "pistolmket":	GunBullets = "musketbullets";	break;
			case "Arguebuse":	GunBullets = "musketbullets";	break;
			case "pistolmtoon": GunBullets = "pistolgrapes";	break;
		}
		TakenItems(curchar, "gunpowder", 1 + rand(2));
		TakenItems(curchar,  GunBullets, 1 + rand(1));
	}
	// JRH: Ammo Mod <--
}

bool NationNoIsland(int iNation, int curPeriod)
{
	bool NoIsland = false;
	switch(curPeriod)
	{
		case PERIOD_EARLY_EXPLORERS:
			if (iNation == ENGLAND || iNation == HOLLAND || iNation == FRANCE)	NoIsland = true;
			// Force France to start at Tortuga as Martinique is now Spanish
		break;
		// England is friendly to Portugal, so this is OK
	/*	case PERIOD_REVOLUTIONS:
			if (iNation == PORTUGAL)						NoIsland = true;
		break;
		case PERIOD_NAPOLEONIC:
			if (iNation == PORTUGAL)						NoIsland = true;
		break;*/
	}

	if (curPeriod >= PERIOD_THE_SPANISH_MAIN && curPeriod <= PERIOD_COLONIAL_POWERS && iNation == SWEDEN) NoIsland = true;
	// Otherwise Sweden, being GUEST1_NATION same as America, starts at Eleuthera, which may be hostile

	return NoIsland;
}