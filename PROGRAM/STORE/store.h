int STORE_QUANTITY = 27; // NK 05-03-30 use int qty and oversized array
#define STORE_MAX					32
#define FALAISE_DE_FLEUR_STORE		0
#define REDMOND_STORE				1
#define OXBAY_STORE					2
#define GREENFORD_STORE				3
#define ISLA_MUELLE_STORE			4
#define DOUWESEN_STORE				5
#define CONCEICAO_STORE				6
#define SMUGGLERS_STORE				7
#define PIRATES_STORE				8
#define TURKS_STORE					9
#define TORTUGA_STORE				10
#define SANTO_DOMINGO_STORE			11
#define GRAND_CAYMAN_STORE			12
#define PORT_AU_PRINCE_STORE		13
#define	POINTE_A_PITRE_STORE		14
#define	HAVANA_STORE				15
#define	ST_JOHNS_STORE				16	// ccc Feb06 Antigua
#define MARIGOT_STORE				17 // KK
#define PHILIPSBURG_STORE			18 // KK
#define SANTIAGO_STORE				19 // KK
#define CHARLESTOWN_STORE			20 // KK
#define WILLEMSTAD_STORE			21 // KK
#define ELEUTHERA_STORE				22 // KK
#define ORANJESTAD_STORE			23 // KK
#define BUCCANEERS_CAMP_STORE		24 // KK
#define ALICE_STORE					25 // Philippe
#define CARTAGENA_STORE				26 // Bartolomeu o Portugues
#define PIRATE_FORT_STORE			27 // Ansel

#define TRADE_TYPE_NORMAL		0
#define TRADE_TYPE_EXPORT		1
#define TRADE_TYPE_IMPORT		2
#define TRADE_TYPE_CONTRABAND	3
#define TRADE_TYPE_AMMUNITION	4

#define TRADE_TYPE_NORMAL_NAME		"normal"
#define TRADE_TYPE_EXPORT_NAME		"export"
#define TRADE_TYPE_IMPORT_NAME		"import"
#define TRADE_TYPE_CONTRABAND_NAME	"contraband"
#define TRADE_TYPE_AMMUNITION_NAME	"ammunition"


object  stores[STORE_MAX]; // NK 05-03-30 use int qty and oversized array
string  StoreName[STORE_MAX]; // ditto

#include "store\store_init.c" // OK, I'm putting this in store.h rather than using loadsegment. 05-07-12
