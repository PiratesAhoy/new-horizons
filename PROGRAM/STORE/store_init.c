//===========================================================================================
//			RULE:
//	pStore.StoreSize	- размер магазина ("large" или "small") - влияет на кол-во товара,
//						по умолчанию берется равным "large".
//	pStore.Island		- id острова к которому принадлежит магазин.
//	pStore.Goods.имя_товара.NotUsed		- устанавливается в TRUE для тех товаров, которыми
//										нельзя торговать в данном магазине.
//										(по умолчанию false).
//===========================================================================================
void StoreInit()
{
	ref pStore;
	STORE_QUANTITY = 0; // NK 05-03-30 use int qty and oversized array

	// Falaise de fleur
	Stores[FALAISE_DE_FLEUR_STORE].Island	= "FalaiseDeFleur";
	Stores[FALAISE_DE_FLEUR_STORE].group	= "Falaise de Fleur";
	Stores[FALAISE_DE_FLEUR_STORE].owner	= "Arnaud Matton"; // KK
	Stores[FALAISE_DE_FLEUR_STORE].dockyard = "Jean Filaut"; // KK
	Stores[FALAISE_DE_FLEUR_STORE].tavern = "Antoine Lebretton"; // KK
	Stores[FALAISE_DE_FLEUR_STORE].usurer = "FF Usurer"; // KK
	Stores[FALAISE_DE_FLEUR_STORE].taylor = "Rene Duguay"; // KK
	Stores[FALAISE_DE_FLEUR_STORE].blacksmith = "Tomasina Pickfurt"; // Levis
	STORE_QUANTITY++; // NK 05-03-30 use int qty and oversized array

	// Redmond
	Stores[REDMOND_STORE].Island	= "Redmond";
	Stores[REDMOND_STORE].group	= "Redmond";
	Stores[REDMOND_STORE].owner	= "Thomas O'Reily"; // KK
	Stores[REDMOND_STORE].dockyard = "Roger Murray"; // KK
	Stores[REDMOND_STORE].tavern = "Charles Windem"; // KK
	Stores[REDMOND_STORE].usurer = "Redmond Usurer"; // KK
	Stores[REDMOND_STORE].taylor = "Gilbert Sullivan"; // KK
	Stores[REDMOND_STORE].blacksmith = "Mortimer Pitchblende"; // Levis
	STORE_QUANTITY++; // NK 05-03-30 use int qty and oversized array

	// Isla Muelle
	Stores[ISLA_MUELLE_STORE].Island	= "IslaMuelle";
	Stores[ISLA_MUELLE_STORE].group	= "Isla Muelle";
	Stores[ISLA_MUELLE_STORE].owner	= "Emiliano Rionda"; // KK
	Stores[ISLA_MUELLE_STORE].dockyard = "Esteban Castillo"; // KK
	Stores[ISLA_MUELLE_STORE].tavern = "Claudio Burrieza"; // KK
	Stores[ISLA_MUELLE_STORE].usurer = "Muelle Usurer"; // KK
	Stores[ISLA_MUELLE_STORE].taylor = "Jose Gaspar"; // KK
	Stores[ISLA_MUELLE_STORE].blacksmith = "Robierto Cabellodoferro"; // KK
	STORE_QUANTITY++; // NK 05-03-30 use int qty and oversized array

	// Oxbay
	Stores[OXBAY_STORE].Island	= "Oxbay";
	Stores[OXBAY_STORE].Group	= "Oxbay";
	Stores[OXBAY_STORE].owner	= "Alan Milds"; // KK
	Stores[OXBAY_STORE].dockyard = "Oweyn McDorey"; // KK
	Stores[OXBAY_STORE].tavern = "Everard Gordon"; // KK
	Stores[OXBAY_STORE].usurer = "Oxbay Usurer"; // KK
	Stores[OXBAY_STORE].taylor = "Guy Gilroy"; // KK
	STORE_QUANTITY++; // NK 05-03-30 use int qty and oversized array

	// незахваченный город в Oxbay
	Stores[GREENFORD_STORE].Island	= "Oxbay";
	Stores[GREENFORD_STORE].Group	= "Greenford";
	Stores[GREENFORD_STORE].owner	=	"John Filbert"; // KK
	Stores[GREENFORD_STORE].dockyard = "David Fairweather"; // KK
	Stores[GREENFORD_STORE].tavern = "Simon Hanpool"; // KK
	Stores[GREENFORD_STORE].usurer = "Greenford Usurer"; // KK
	Stores[GREENFORD_STORE].taylor = "Brian Bratcher"; // KK
	Stores[GREENFORD_STORE].apothecary = "Steven Mather-Wren"; // KK
	STORE_QUANTITY++; // NK 05-03-30 use int qty and oversized array

	// Conceicao
	Stores[CONCEICAO_STORE].Island	= "Conceicao";
	Stores[CONCEICAO_STORE].Group	= "Conceicao";
	Stores[CONCEICAO_STORE].owner	= "Martinho Guterres"; // KK
	Stores[CONCEICAO_STORE].dockyard = "Humberto de Paiva"; // KK
	Stores[CONCEICAO_STORE].tavern = "Duarte Correja"; // KK
	Stores[CONCEICAO_STORE].usurer = "Conceicao Usurer"; // KK
	Stores[CONCEICAO_STORE].taylor = "Abenito de Soto"; // KK
	Stores[CONCEICAO_STORE].gunsmith = "Diego Uargo"; // Levis
	STORE_QUANTITY++; // NK 05-03-30 use int qty and oversized array

	// контрабандисты
	Stores[SMUGGLERS_STORE].Island	= "Conceicao";
	Stores[SMUGGLERS_STORE].group	= "Smugglers Lair";
	Stores[SMUGGLERS_STORE].owner	= "Leonardo Violate"; // KK
	Stores[SMUGGLERS_STORE].tavern = "Fabiao Dunga"; // KK
	STORE_QUANTITY++; // NK 05-03-30 use int qty and oversized array

	// Douwesen
	Stores[DOUWESEN_STORE].Island	= "Douwesen";
	Stores[DOUWESEN_STORE].group	= "Douwesen"; // Fix Cap Hawk
	Stores[DOUWESEN_STORE].owner	= "Gheerlof Darlang"; // KK
	Stores[DOUWESEN_STORE].dockyard = "Lambrecht Fobes"; // KK
	Stores[DOUWESEN_STORE].tavern = "Friedrich Corleis"; // KK
	Stores[DOUWESEN_STORE].usurer = "Douwesen Usurer"; // KK
	Stores[DOUWESEN_STORE].taylor = "Rost van Moor"; // KK
	Stores[DOUWESEN_STORE].blacksmith = "Boudewijn Smidt"; // Levis
	STORE_QUANTITY++; // NK 05-03-30 use int qty and oversized array

	// Quebradas
	Stores[PIRATES_STORE].Island	= "QuebradasCostillas";
	Stores[PIRATES_STORE].group		= "Quebradas Costillas";
	Stores[PIRATES_STORE].owner		= "Kate Blowhorn"; // KK // Estharos was Peter
	Stores[PIRATES_STORE].dockyard = "Jakob Nickerson"; // KK
	Stores[PIRATES_STORE].tavern = "Ines Diaz"; // KK
	Stores[PIRATES_STORE].usurer = "Quebradas Costillas Usurer"; // KK
	Stores[PIRATES_STORE].taylor = "Howell Davis"; // KK
	Stores[PIRATES_STORE].blacksmith = "Arne Saknussem"; // Levis
	STORE_QUANTITY++; // NK 05-03-30 use int qty and oversized array

	// Turks
	Stores[TURKS_STORE].Island	= "Turks";
	Stores[TURKS_STORE].group	= "Grand Turk";
	Stores[TURKS_STORE].owner	= "Ricardo Sanchez"; // KK
	Stores[TURKS_STORE].dockyard = "Maarten Verlinden"; // KK
	Stores[TURKS_STORE].tavern = "Josephine Bonassieu"; // KK
	Stores[TURKS_STORE].taylor = "Samuel Pugh"; // KK
	Stores[TURKS_STORE].gunsmith = "Lorenza Trevisano"; //Levis
	STORE_QUANTITY++; // NK 05-03-30 use int qty and oversized array

	// Tortuga
	Stores[TORTUGA_STORE].Island	= "Hispaniola";
	Stores[TORTUGA_STORE].group	= "Tortuga";
	Stores[TORTUGA_STORE].owner	= "Jasmine Cotton"; // KK // Estharos was James
	Stores[TORTUGA_STORE].dockyard = "Adhemar Bertillon"; // KK
	Stores[TORTUGA_STORE].tavern = "John Adams"; // KK
	Stores[TORTUGA_STORE].usurer = "Tortuga usurer"; // KK
	Stores[TORTUGA_STORE].taylor = "Guy Lafleur"; //JRH
	STORE_QUANTITY++; // NK 05-03-30 use int qty and oversized array

	// Santo Domingo
	Stores[SANTO_DOMINGO_STORE].Island	= "Hispaniola";
	Stores[SANTO_DOMINGO_STORE].group	= "Santo Domingo";
	Stores[SANTO_DOMINGO_STORE].owner	= "Pedro Ortega"; // KK
	Stores[SANTO_DOMINGO_STORE].dockyard = "Teodinus Serrano"; // KK
	Stores[SANTO_DOMINGO_STORE].tavern = "Rodrigo Ramos"; // KK
	Stores[SANTO_DOMINGO_STORE].usurer = "Santo Domingo usurer"; // GR
	STORE_QUANTITY++; // NK 05-03-30 use int qty and oversized array

	// Grand Cayman
	Stores[GRAND_CAYMAN_STORE].Island	= "Cayman";
	Stores[GRAND_CAYMAN_STORE].group	= "Grand Cayman";
	Stores[GRAND_CAYMAN_STORE].owner	=	"Laurence Bannerman"; // KK
	Stores[GRAND_CAYMAN_STORE].dockyard = "Fletcher Rosewood"; // KK
	Stores[GRAND_CAYMAN_STORE].tavern = "Olyver Littlejohn"; // KK
	STORE_QUANTITY++; // NK 05-03-30 use int qty and oversized array

	// Port au Prince
	Stores[PORT_AU_PRINCE_STORE].Island	= "Hispaniola";
	Stores[PORT_AU_PRINCE_STORE].group	= "Port au Prince";
	Stores[PORT_AU_PRINCE_STORE].owner	= "Violette De Colville"; // KK
	Stores[PORT_AU_PRINCE_STORE].dockyard = "Benoit Bertignac"; // KK
	Stores[PORT_AU_PRINCE_STORE].tavern = "Francois Chabert"; // KK
	STORE_QUANTITY++; // NK 05-03-30 use int qty and oversized array

	// Pointe a Pitre
	Stores[POINTE_A_PITRE_STORE].Island	= "Guadeloupe";
	Stores[POINTE_A_PITRE_STORE].group	= "Pointe a Pitre";
	Stores[POINTE_A_PITRE_STORE].owner	= "Dieudonne Toussaint"; // KK
	Stores[POINTE_A_PITRE_STORE].dockyard = "Prosper Fraigneau"; // KK
	Stores[POINTE_A_PITRE_STORE].tavern = "Albin Bonaventure"; // KK
	STORE_QUANTITY++; // NK 05-03-30 use int qty and oversized array

	// Havana
	Stores[HAVANA_STORE].Island	= "Cuba";
	Stores[HAVANA_STORE].group	= "Havana";
	Stores[HAVANA_STORE].owner	= "Juan Mendoza"; // KK
	Stores[HAVANA_STORE].dockyard = "Jorge Suarez"; // KK
	Stores[HAVANA_STORE].tavern = "Fadrique Castillo"; // KK
	Stores[HAVANA_STORE].blacksmith = "Marco Quintero"; // Levis
	STORE_QUANTITY++; // NK 05-03-30 use int qty and oversized array

	// ccc Feb06 Antigua
	Stores[ST_JOHNS_STORE].Island	= "Antigua";
	Stores[ST_JOHNS_STORE].group	= "St John's";
	Stores[ST_JOHNS_STORE].owner	= "Antigua_Victualler"; // KK
	Stores[ST_JOHNS_STORE].dockyard = "Antigua_Dockyard"; // KK
	Stores[ST_JOHNS_STORE].tavern = "Brian Moods"; // KK
	STORE_QUANTITY++;

    // Eleuthera
	Stores[ELEUTHERA_STORE].Island	= "Eleuthera";
	Stores[ELEUTHERA_STORE].group	= "Eleuthera";
	Stores[ELEUTHERA_STORE].owner	= "Fox Ratter"; // Philippe
	Stores[ELEUTHERA_STORE].dockyard = "Philippe"; // KK
	Stores[ELEUTHERA_STORE].tavern = "Brian Armstrong"; // KK
	Stores[ELEUTHERA_STORE].usurer = "Eleuthera Usurer"; // KK
	Stores[ELEUTHERA_STORE].taylor = "Brendan Arrowsmith"; // KK
	STORE_QUANTITY++; // NK 05-03-30 use int qty and oversized array

	// Alice
	Stores[ALICE_STORE].Island	= "Eleuthera";//"Alice";
	Stores[ALICE_STORE].group	= "Alice";
	Stores[ALICE_STORE].owner	= "Dawg Bennett"; // change name // Philippe
	Stores[ALICE_STORE].dockyard = "Patrick Webster"; // KK
	Stores[ALICE_STORE].tavern = "Robert Wicker"; // KK
	Stores[ALICE_STORE].usurer = "Alice Usurer"; // KK
	Stores[ALICE_STORE].taylor = "Karen Cakebread"; // KK
	STORE_QUANTITY++; // NK 05-03-30 use int qty and oversized array

// KK -->
	Stores[MARIGOT_STORE].Island	= "SaintMartin";
	Stores[MARIGOT_STORE].group	= "Marigot";
	Stores[MARIGOT_STORE].owner	= "Jean Maginot";
	Stores[MARIGOT_STORE].dockyard = "Maurice Dupont";
	Stores[MARIGOT_STORE].tavern = "Andree Figaux"; // KK
	STORE_QUANTITY++;

	Stores[PHILIPSBURG_STORE].Island	= "SaintMartin";
	Stores[PHILIPSBURG_STORE].group	= "Philipsburg";
	Stores[PHILIPSBURG_STORE].owner	= "Pieter Van Vecker";
	Stores[PHILIPSBURG_STORE].dockyard = "Arendt Verheugen";
	Stores[PHILIPSBURG_STORE].tavern = "Marcus Maas"; // KK
	STORE_QUANTITY++;

	Stores[SANTIAGO_STORE].Island	= "Cuba";
	Stores[SANTIAGO_STORE].group	= "Santiago";
	Stores[SANTIAGO_STORE].owner	=	"Jose Zugarro";
	Stores[SANTIAGO_STORE].dockyard = "Pablo Duarte";
	Stores[SANTIAGO_STORE].tavern = "Pedro Fructoso"; // KK
	Stores[SANTIAGO_STORE].blacksmith = "Santiago_blacksmith"; // GR
	STORE_QUANTITY++;

	// Charlestown
	Stores[CHARLESTOWN_STORE].Island	= "QuebradasCostillas";
	Stores[CHARLESTOWN_STORE].group	= "Charlestown";
	Stores[CHARLESTOWN_STORE].owner	= "James Griffith";
	Stores[CHARLESTOWN_STORE].dockyard = "Hugh Chadman";
	Stores[CHARLESTOWN_STORE].tavern = "Pete Manchester"; // KK
	STORE_QUANTITY++;

	Stores[WILLEMSTAD_STORE].Island	= "Curacao";
	Stores[WILLEMSTAD_STORE].group	= "Willemstad";
	Stores[WILLEMSTAD_STORE].owner	= "Jacobus Colijn";
	Stores[WILLEMSTAD_STORE].dockyard = "Gheret Bogardus";
	Stores[WILLEMSTAD_STORE].tavern = "Pierart Kamerling"; // KK
	Stores[WILLEMSTAD_STORE].usurer = "Willemstad Usurer"; // KK
	Stores[WILLEMSTAD_STORE].taylor = "Pelgrem Christus"; // KK
	STORE_QUANTITY++;

	Stores[ORANJESTAD_STORE].Island	= "Aruba";
	Stores[ORANJESTAD_STORE].group	= "Oranjestad";
	Stores[ORANJESTAD_STORE].owner	= "Cornelis Huijser";
	Stores[ORANJESTAD_STORE].tavern = "Johannes Harlekeyn"; // KK
	Stores[ORANJESTAD_STORE].usurer = "Oranjestad Usurer"; // KK
	Stores[ORANJESTAD_STORE].taylor = "Jan Thijs"; // KK
	STORE_QUANTITY++;

	Stores[BUCCANEERS_CAMP_STORE].Island	= "Hispaniola";
	Stores[BUCCANEERS_CAMP_STORE].group	= "Buccaneers Camp";
	Stores[BUCCANEERS_CAMP_STORE].owner	= "Eugene Martin";
	Stores[BUCCANEERS_CAMP_STORE].tavern = "Florentin Destot"; // KK
	STORE_QUANTITY++;
// <-- KK

	Stores[CARTAGENA_STORE].Island	= "Colombia";
	Stores[CARTAGENA_STORE].group	= "Cartagena";
	Stores[CARTAGENA_STORE].owner	= "Augustin Frechilla";
	Stores[CARTAGENA_STORE].dockyard = "Ricardo Ordiales";
	Stores[CARTAGENA_STORE].tavern = "Valerio Xalmiento";
	Stores[CARTAGENA_STORE].usurer = "Cartagena Usurer";
	Stores[CARTAGENA_STORE].taylor = "Virmundus Gastelu";
	Stores[CARTAGENA_STORE].blacksmith = "Uitalez Chiamuhera"; //Levis
	STORE_QUANTITY++;

	// Pirate Fort
	Stores[PIRATE_FORT_STORE].Island	= "Douwesen";
	Stores[PIRATE_FORT_STORE].group	= "Pirate Fort";
	Stores[PIRATE_FORT_STORE].owner	= "Cornelius Vanslyperken"; // Ansel
	STORE_QUANTITY++;
}
