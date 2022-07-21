#define FRP_STORE		0
#define FRT_STORE		0
#define FRN_STORE		"go_store" // KK

#define FRP_SHIPYARD		1
#define FRT_SHIPYARD		0
#define FRN_SHIPYARD		"go_shipyard" // KK

#define FRP_TAVERN		2
#define FRT_TAVERN		0
#define FRN_TAVERN		"go_tavern" // KK

#define FRP_RESIDENCE		3
#define FRT_RESIDENCE		0
#define FRN_RESIDENCE		"go_residence" // KK

#define FRP_LOANSHARK		4  //GreatZen
#define FRT_LOANSHARK		0  //GreatZen
#define FRN_LOANSHARK		"go_loanshark" // KK

// KK -->
#define FRP_CHURCH		5 // MAXIMUS
#define FRT_CHURCH		0 // MAXIMUS
#define FRN_CHURCH		"go_church"

#define FRP_TAILORSHOP		6
#define FRT_TAILORSHOP		0
#define FRN_TAILORSHOP		"go_tailorshop"

#define FRP_BLACKSMITH		7
#define FRT_BLACKSMITH		0
#define FRN_BLACKSMITH		"go_blacksmith"

#define FRP_PRISON		8
#define FRT_PRISON		0
#define FRN_PRISON		"go_prison"

#define FRP_FORT		9
#define FRT_FORT		0
#define FRN_FORT		"go_fort"

#define FRP_BROTHEL		10 // MAXIMUS interface MOD
#define FRT_BROTHEL		0 // MAXIMUS interface MOD
#define FRN_BROTHEL		"go_brothel" // KK

#define FRP_SHIPDECK		11
#define FRT_SHIPDECK		0
#define FRN_SHIPDECK		"go_shipdeck"

#define FRP_CABIN		12
#define FRT_CABIN		0
#define FRN_CABIN		"go_cabin"

#define FRP_SEADOGS		13
#define FRT_SEADOGS		0
#define FRN_SEADOGS		"go_seadogs"

#define FRP_DECK1		14
#define FRT_DECK1		0
#define FRN_DECK1		"go_maincannonsdeck"

#define FRP_DECK2		14
#define FRT_DECK2		0
#define FRN_DECK2		"go_lowercannonsdeck"

#define FRP_DECK3		14
#define FRT_DECK3		0
#define FRN_DECK3		"go_maincannonsdeck"

#define FRP_HOLD		15
#define FRT_HOLD		0
#define FRN_HOLD		"go_hold"

#define FRP_APOTHECARY		16
#define FRT_APOTHECARY		0
#define FRN_APOTHECARY		"go_apothecary"

#define FRP_GUNSMITH		17
#define FRT_GUNSMITH		0
#define FRN_GUNSMITH		"go_gunsmith"

#define FRP_GUNBLACKSMITH	18
#define FRT_GUNBLACKSMITH	0
#define FRN_GUNBLACKSMITH	"go_gunblacksmith"

#define FRP_OPIUM		19
#define FRT_OPIUM		0
#define FRN_OPIUM		"go_opium"

#define FRP_LIBRARY		20
#define FRT_LIBRARY		0
#define FRN_LIBRARY		"go_library"

#define FRP_MALTESE		21
#define FRT_MALTESE		0
#define FRN_MALTESE		"go_maltese"

#define FRP_INDIANSTORE		22
#define FRT_INDIANSTORE		0
#define FRN_INDIANSTORE		"go_indianstore"

#define FRP_TAVERN2		23
#define FRT_TAVERN2		0
#define FRN_TAVERN2		"go_tavern2"

#define FRP_EITC		24
#define FRT_EITC		0
#define FRN_EITC		"go_eitc"

#define FRP_DWIC		25
#define FRT_DWIC		0
#define FRN_DWIC		"go_dwic"

#define FRP_HQ			26
#define FRT_HQ			0
#define FRN_HQ			"go_hq"

#define FRP_ACADEMY		27
#define FRT_ACADEMY		0
#define FRN_ACADEMY		"go_academy"

#define FRP_CDC			28
#define FRT_CDC			0
#define FRN_CDC			"go_cdc"

#define FRP_FWIC		29
#define FRT_FWIC		0
#define FRN_FWIC		"go_fwic"

#define FRP_PORT		2
#define FRT_PORT		1
#define FRN_PORT		"go_port"

#define FRP_TOWN		3
#define FRT_TOWN		1
#define FRN_TOWN		"go_town"
// <-- KK

void initFastReloadTable()
{
	objFastReloadTable.reloadEnable = true;
	aref curTable;

	makearef(curTable,objFastReloadTable.table.Eleuthera);//Philippe
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE;
	curTable.l1.location = "Eleuthera_store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD;
	curTable.l2.location = "Eleuthera_shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN;
	curTable.l3.location = "Eleuthera_tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE;
	curTable.l4.location = "Eleuthera_townhall";
	// loanshark GreatZen
	curTable.l5.pic = FRP_LOANSHARK;
	curTable.l5.tex = FRT_LOANSHARK;
	curTable.l5.note = FRN_LOANSHARK;
	curTable.l5.location = "Eleuthera_bank";
	// church MAXIMUS
	curTable.l6.pic = FRP_CHURCH;
	curTable.l6.tex = FRT_CHURCH;
	curTable.l6.note = FRN_CHURCH; 
	curTable.l6.location = "Eleuthera_church";
	// tailor's shop
	curTable.l7.pic = FRP_TAILORSHOP;
	curTable.l7.tex = FRT_TAILORSHOP;
	curTable.l7.note = FRN_TAILORSHOP;
	curTable.l7.location = "Eleuthera_TailorsShop";
	//brothel
	curTable.l8.pic = FRP_BROTHEL;
	curTable.l8.tex = FRT_BROTHEL;
	curTable.l8.note = FRN_BROTHEL;
	curTable.l8.location = "Eleuthera_brothel";

	makearef(curTable,objFastReloadTable.table.Alice);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE;
	curTable.l1.location = "Alice_store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD;
	curTable.l2.location = "Alice_shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN;
	curTable.l3.location = "Alice_tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE;
	curTable.l4.location = "Alice_townhall";
	// loanshark GreatZen
	curTable.l5.pic = FRP_LOANSHARK;
	curTable.l5.tex = FRT_LOANSHARK;
	curTable.l5.note = FRN_LOANSHARK;
	curTable.l5.location = "Alice_usurer";
	// church MAXIMUS
	curTable.l6.pic = FRP_CHURCH;
	curTable.l6.tex = FRT_CHURCH;
	curTable.l6.note = FRN_CHURCH; 
	curTable.l6.location = "Alice_church";
	//prison
	curTable.l9.pic = FRP_PRISON;
	curTable.l9.tex = FRT_PRISON;
	curTable.l9.note = FRN_PRISON;
	curTable.l9.location = "Alice_prison";
	//brothel
	curTable.l10.pic = FRP_BROTHEL;
	curTable.l10.tex = FRT_BROTHEL;
	curTable.l10.note = FRN_BROTHEL; // KK
	curTable.l10.location = "Alice_Brothel";
	// tailor's shop
	curTable.l11.pic = FRP_TAILORSHOP;
	curTable.l11.tex = FRT_TAILORSHOP;
	curTable.l11.note = FRN_TAILORSHOP;
	curTable.l11.location = "Alice_TailorsShop";

	makearef(curTable,objFastReloadTable.table.Conceicao);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE; // KK
	curTable.l1.location = "Conceicao_Store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD; // KK
	curTable.l2.location = "Conceicao_Shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN; // KK
	curTable.l3.location = "Conceicao_Tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE; // KK
	curTable.l4.location = "Conceicao_townhall";
	// loanshark GreatZen
	curTable.l5.pic = FRP_LOANSHARK;
	curTable.l5.tex = FRT_LOANSHARK;
	curTable.l5.note = FRN_LOANSHARK; // KK
	curTable.l5.location = "Conceicao_UsurerHouse";
	// church MAXIMUS
	curTable.l6.pic = FRP_CHURCH;
	curTable.l6.tex = FRT_CHURCH;
	curTable.l6.note = FRN_CHURCH; // KK
	curTable.l6.location = "Conceicao_church";
// KK -->
	// tailor's shop
	curTable.l7.pic = FRP_TAILORSHOP;
	curTable.l7.tex = FRT_TAILORSHOP;
	curTable.l7.note = FRN_TAILORSHOP;
	curTable.l7.location = "Conceicao_TailorsShop";
// <-- KK
	// gunsmith
	curTable.l8.pic = FRP_GUNSMITH;	//JRH
	curTable.l8.tex = FRT_GUNSMITH;
	curTable.l8.note = FRN_GUNSMITH;
	curTable.l8.location = "Con_blacksmith";

	makearef(curTable,objFastReloadTable.table.SL);
/*	// town
	curTable.l1.pic = FRP_TOWN;
	curTable.l1.tex = FRT_TOWN;
	curTable.l1.note = FRN_TOWN;
	curTable.l1.location = "Smugglers_Lair";*/
	// store
	curTable.l2.pic = FRP_STORE;
	curTable.l2.tex = FRT_STORE;
	curTable.l2.note = FRN_STORE;
	curTable.l2.location = "Smugglers_Store";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN;
	curTable.l3.location = "Smugglers_Tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE;
	curTable.l4.location = "Smugglers_residence";

	makearef(curTable,objFastReloadTable.table.Douwesen);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE; // KK
	curTable.l1.location = "Douwesen_Store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD; // KK
	curTable.l2.location = "Douwesen_shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN; // KK
	curTable.l3.location = "Douwesen_tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE; // KK
	curTable.l4.location = "Douwesen_townhall";
	// loanshark GreatZen
	curTable.l5.pic = FRP_LOANSHARK;
	curTable.l5.tex = FRT_LOANSHARK;
	curTable.l5.note = FRN_LOANSHARK; // KK
	curTable.l5.location = "Douwesen_UsurerHouse";
// KK -->
	// tailor's shop
	curTable.l6.pic = FRP_TAILORSHOP;
	curTable.l6.tex = FRT_TAILORSHOP;
	curTable.l6.note = FRN_TAILORSHOP;
	curTable.l6.location = "Douwesen_TailorsShop";
	// blacksmith
	curTable.l7.pic = FRP_BLACKSMITH;
	curTable.l7.tex = FRT_BLACKSMITH;
	curTable.l7.note = FRN_BLACKSMITH;
	curTable.l7.location = "Douw_blacksmith";
// <-- KK

	makearef(curTable,objFastReloadTable.table.Pirate_fort);
	// town
/*	curTable.l1.pic = FRP_TOWN;
	curTable.l1.tex = FRT_TOWN;
	curTable.l1.note = FRN_TOWN;
	curTable.l1.location = "Pirate_Fort";*/
	// tailor's shop
	curTable.l2.pic = FRP_TAILORSHOP;
	curTable.l2.tex = FRT_TAILORSHOP;
	curTable.l2.note = FRN_TAILORSHOP;
	curTable.l2.location = "Douwesen_Pirates_TailorsShop";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN;
	curTable.l3.location = "Pirate_Tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE;
	curTable.l4.location = "Douwesen_Pirate_Residence";
	// store
	curTable.l5.pic = FRP_STORE;
   	curTable.l5.tex = FRT_STORE;
   	curTable.l5.note = FRN_STORE); 
   	curTable.l5.location = "Pirate_store";

	makearef(curTable,objFastReloadTable.table.Falaise_de_fleur);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE); // KK
	curTable.l1.location = "Falaise_de_Fleur_store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD; // KK
	curTable.l2.location = "Falaise_de_fleur_shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN; // KK
	curTable.l3.location = "Falaise_de_fleur_tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE; // KK
	curTable.l4.location = "Falaise_de_fleur_townhall";
	// loanshark GreatZen
	curTable.l5.pic = FRP_LOANSHARK;
	curTable.l5.tex = FRT_LOANSHARK;
	curTable.l5.note = FRN_LOANSHARK; // KK
	curTable.l5.location = "FF_UsurerHouse";
	// church MAXIMUS
	curTable.l6.pic = FRP_CHURCH;
	curTable.l6.tex = FRT_CHURCH;
	curTable.l6.note = FRN_CHURCH; // KK
	curTable.l6.location = "Falaise_de_fleur_church";
// KK -->
	// tailor's shop
	curTable.l7.pic = FRP_TAILORSHOP;
	curTable.l7.tex = FRT_TAILORSHOP;
	curTable.l7.note = FRN_TAILORSHOP;
	curTable.l7.location = "Falaise_de_fleur_TailorsShop";
	// blacksmith
	curTable.l8.pic = FRP_BLACKSMITH;
	curTable.l8.tex = FRT_BLACKSMITH;
	curTable.l8.note = FRN_BLACKSMITH;
	curTable.l8.location = "FdF_blacksmith";
// <-- KK

	makearef(curTable,objFastReloadTable.table.Muelle);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE; // KK
	curTable.l1.location = "Muelle_Store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD; // KK
	curTable.l2.location = "Muelle_Shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN; // KK
	curTable.l3.location = "Muelle_Tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE; // KK
	curTable.l4.location = "Muelle_Residence";
	// loanshark GreatZen
	curTable.l5.pic = FRP_LOANSHARK;
	curTable.l5.tex = FRT_LOANSHARK;
	curTable.l5.note = FRN_LOANSHARK; // KK
	curTable.l5.location = "Muelle_UsurerHouse";
	// church MAXIMUS
	curTable.l6.pic = FRP_CHURCH;
	curTable.l6.tex = FRT_CHURCH;
	curTable.l6.note = FRN_CHURCH; // KK
	curTable.l6.location = "Muelle_church";
// KK -->
	// tailor's shop
	curTable.l7.pic = FRP_TAILORSHOP;
	curTable.l7.tex = FRT_TAILORSHOP;
	curTable.l7.note = FRN_TAILORSHOP;
	curTable.l7.location = "Muelle_TailorsShop";
	// blacksmith
	curTable.l8.pic = FRP_BLACKSMITH;
	curTable.l8.tex = FRT_BLACKSMITH;
	curTable.l8.note = FRN_BLACKSMITH;
	curTable.l8.location = "IM_blacksmith";
// <-- KK

	makearef(curTable,objFastReloadTable.table.KhaelRoa); // нет ничего, кроме причала

	makearef(curTable,objFastReloadTable.table.Oxbay);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE; // KK
	curTable.l1.location = "Oxbay_store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD; // KK
	curTable.l2.location = "Oxbay_Shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN; // KK
	curTable.l3.location = "Oxbay_Tavern";
	// loanshark
	curTable.l4.pic = FRP_LOANSHARK;
	curTable.l4.tex = FRT_LOANSHARK;
	curTable.l4.note = FRN_LOANSHARK; // KK
	curTable.l4.location = "Oxbay_UsurerHouse";
// KK -->
	// tailor's shop
	curTable.l5.pic = FRP_TAILORSHOP;
	curTable.l5.tex = FRT_TAILORSHOP;
	curTable.l5.note = FRN_TAILORSHOP;
	curTable.l5.location = "Oxbay_TailorsShop";
	// fort
	curTable.l6.pic = FRP_FORT;
	curTable.l6.tex = FRT_FORT;
	curTable.l6.note = FRN_FORT; // KK
	curTable.l6.location = "Oxbay_fakefort1";
// <-- KK

	makearef(curTable,objFastReloadTable.table.Greenford);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE; // KK
	curTable.l1.location = "Greenford_Store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD; // KK
	curTable.l2.location = "Greenford_Shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN; // KK
	curTable.l3.location = "Greenford_tavern";
	// loanshark GreatZen
	curTable.l4.pic = FRP_LOANSHARK;
	curTable.l4.tex = FRT_LOANSHARK;
	curTable.l4.note = FRN_LOANSHARK; // KK
	curTable.l4.location = "Greenford_UsurerHouse";
	// church MAXIMUS
	curTable.l5.pic = FRP_CHURCH;
	curTable.l5.tex = FRT_CHURCH;
	curTable.l5.note = FRN_CHURCH; // KK
	curTable.l5.location = "Greenford_church";
// KK -->
	// prison
	curTable.l6.pic = FRP_PRISON;
	curTable.l6.tex = FRT_PRISON;
	curTable.l6.note = FRN_PRISON);
	curTable.l6.location = "Greenford_prison";
	// tailor's shop
	curTable.l7.pic = FRP_TAILORSHOP;
	curTable.l7.tex = FRT_TAILORSHOP;
	curTable.l7.note = FRN_TAILORSHOP;
	curTable.l7.location = "Greenford_TailorsShop";
	// fort
	curTable.l8.pic = FRP_FORT;
	curTable.l8.tex = FRT_FORT;
	curTable.l8.note = FRN_FORT;
	curTable.l8.location = "Greenford_fakefort1";
// <-- KK
	//apothecary
	curTable.l9.pic = FRP_APOTHECARY;	//JRH
	curTable.l9.tex = FRT_APOTHECARY;
	curTable.l9.note = FRN_APOTHECARY;
	curTable.l9.location = "apothecary";
	//maltese abbey
	curTable.l10.pic = FRP_MALTESE;		//JRH
	curTable.l10.tex = FRT_MALTESE;
	curTable.l10.note = FRN_MALTESE;
	curTable.l10.location = "Greenford_M_church";
	//naval HQ
	curTable.l11.pic = FRP_HQ;		//JRH
	curTable.l11.tex = FRT_HQ;
	curTable.l11.note = FRN_HQ;
	curTable.l11.location = "Greenford Naval HQ";

	makearef(curTable,objFastReloadTable.table.QC);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE; // KK
	curTable.l1.location = "QC_store";
	// shipyard ------ADDED IN, LOVE VERRUCKT
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD; // KK
	curTable.l2.location = "QC_shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN; // KK
	curTable.l3.location = "QC_tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE; // KK
	curTable.l4.location = "QC_Residence";
	// loanshark
	curTable.l5.pic = FRP_LOANSHARK;
	curTable.l5.tex = FRT_LOANSHARK;
	curTable.l5.note = FRN_LOANSHARK; // KK
	curTable.l5.location = "QC_UsurerHouse";
	// blacksmith
	curTable.l6.pic = FRP_BLACKSMITH;
	curTable.l6.tex = FRT_BLACKSMITH;
	curTable.l6.note = FRN_BLACKSMITH;
	curTable.l6.location = "QC_blacksmith";
	// brothel
	curTable.l7.pic = FRP_BROTHEL; // MAXIMUS interface MOD
	curTable.l7.tex = FRT_BROTHEL; // MAXIMUS interface MOD
	curTable.l7.note = FRN_BROTHEL; // KK
	curTable.l7.location = "QC_brothel"; // MAXIMUS interface MOD

	makearef(curTable,objFastReloadTable.table.Redmond);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE; // KK
	curTable.l1.location = "Redmond_store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD; // KK
	curTable.l2.location = "Redmond_shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN; // KK
	curTable.l3.location = "Redmond_tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE; // KK
	curTable.l4.location = "Redmond_residence";
	// loanshark GreatZen
	curTable.l5.pic = FRP_LOANSHARK;
	curTable.l5.tex = FRT_LOANSHARK;
	curTable.l5.note = FRN_LOANSHARK; // KK
	curTable.l5.location = "Redmond_UsurerHouse";
	// church MAXIMUS
	curTable.l6.pic = FRP_CHURCH;
	curTable.l6.tex = FRT_CHURCH;
	curTable.l6.note = FRN_CHURCH; // KK
	curTable.l6.location = "Redmond_church";
// KK -->
	// tailor's shop
	curTable.l7.pic = FRP_TAILORSHOP;
	curTable.l7.tex = FRT_TAILORSHOP;
	curTable.l7.note = FRN_TAILORSHOP;
	curTable.l7.location = "Redmond_TailorsShop";
	// blacksmith
	curTable.l8.pic = FRP_BLACKSMITH;
	curTable.l8.tex = FRT_BLACKSMITH;
	curTable.l8.note = FRN_BLACKSMITH;
	curTable.l8.location = "red_blacksmith";
	// prison
	curTable.l9.pic = FRP_PRISON;
	curTable.l9.tex = FRT_PRISON;
	curTable.l9.note = FRN_PRISON;
	curTable.l9.location = "Redmond_prison";
// <-- KK
	// EITC
	curTable.l10.pic = FRP_EITC;		//JRH
	curTable.l10.tex = FRT_EITC;
	curTable.l10.note = FRN_EITC;
	curTable.l10.location = "EITC_Office";
	// opium den
	curTable.l11.pic = FRP_OPIUM;		//JRH
	curTable.l11.tex = FRT_OPIUM;
	curTable.l11.note = FRN_OPIUM;
	curTable.l11.location = "den";
	// naval HQ
	curTable.l12.pic = FRP_HQ;		//JRH
	curTable.l12.tex = FRT_HQ;
	curTable.l12.note = FRN_HQ;
	curTable.l12.location = "Redmond Naval HQ";

	makearef(curTable,objFastReloadTable.table.Pointe_a_Pitre);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE; // KK
	curTable.l1.location = "Pointe_a_pitre_store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD; // KK
	curTable.l2.location = "Pointe_a_pitre_shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN; // KK
	curTable.l3.location = "Pointe_a_pitre_tavern";
	// residence MAXIMUS
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE; // KK
	curTable.l4.location = "PaP_townhall";
	// loanshark MAXIMUS
	curTable.l5.pic = FRP_LOANSHARK;
	curTable.l5.tex = FRT_LOANSHARK;
	curTable.l5.note = FRN_LOANSHARK; // KK
	curTable.l5.location = "PaP_usurer";
	// church MAXIMUS
	curTable.l6.pic = FRP_CHURCH;
	curTable.l6.tex = FRT_CHURCH;
	curTable.l6.note = FRN_CHURCH; // KK
	curTable.l6.location = "PaP_Church";
	// fort	
	curTable.l7.pic = FRP_FORT;
	curTable.l7.tex = FRT_FORT;
	curTable.l7.note = FRN_FORT;
	curTable.l7.location = "Guadeloupe_fakefort1";
	// brothel MAXIMUS
	curTable.l8.pic = FRP_BROTHEL;
	curTable.l8.tex = FRT_BROTHEL;
	curTable.l8.note = FRN_BROTHEL; // KK
	curTable.l8.location = "PaP_Brothel";
	// academy
	curTable.l9.pic = FRP_ACADEMY;		//JRH
	curTable.l9.tex = FRT_ACADEMY;
	curTable.l9.note = FRN_ACADEMY;
	curTable.l9.location = "PaP_Academy";

	makearef(curTable,objFastReloadTable.table.Grand_Turk);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE; // KK
	curTable.l1.location = "Turks_Store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD; // KK
	curTable.l2.location = "Grand_Turk_Shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN; // KK
	curTable.l3.location = "Turks_Tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE; // KK
	curTable.l4.location = "Turks_townhall";
	// loanshark JRH
	curTable.l5.pic = FRP_LOANSHARK;
	curTable.l5.tex = FRT_LOANSHARK;
	curTable.l5.note = FRN_LOANSHARK;
	curTable.l5.location = "Turks_usurerhouse";
	// church MAXIMUS
	curTable.l6.pic = FRP_CHURCH;
	curTable.l6.tex = FRT_CHURCH;
	curTable.l6.note = FRN_CHURCH;
	curTable.l6.location = "Turks_church";
	// tailor's shop
	curTable.l7.pic = FRP_TAILORSHOP;
	curTable.l7.tex = FRT_TAILORSHOP;
	curTable.l7.note = FRN_TAILORSHOP;
	curTable.l7.location = "Turks_TailorsShop";
	// blacksmith
	curTable.l8.pic = FRP_GUNBLACKSMITH;		//JRH
	curTable.l8.tex = FRT_GUNBLACKSMITH;
	curTable.l8.note = FRN_GUNBLACKSMITH;
	curTable.l8.location = "Turks_blacksmith";
	// library
	curTable.l9.pic = FRP_LIBRARY;			//JRH
	curTable.l9.tex = FRT_LIBRARY;
	curTable.l9.note = FRN_LIBRARY;
	curTable.l9.location = "Turks_library";

	makearef(curTable,objFastReloadTable.table.Havana);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE; // KK
	curTable.l1.location = "Havana_Store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD; // KK
	curTable.l2.location = "Havana_Shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN; // KK
	curTable.l3.location = "Havana_Tavern";
// KK -->
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE;
	curTable.l4.location = "Havana_townhall";
	// fort
	curTable.l5.pic = FRP_FORT;
	curTable.l5.tex = FRT_FORT;
	curTable.l5.note = FRN_FORT;
	curTable.l5.location = "Havana_fakefort1";
// <-- KK
	// blacksmith
	curTable.l6.pic = FRP_BLACKSMITH;
	curTable.l6.tex = FRT_BLACKSMITH;
	curTable.l6.note = FRN_BLACKSMITH;
	curTable.l6.location = "Havana_blacksmith";
	// church MAXIMUS
	curTable.l7.pic = FRP_CHURCH;
	curTable.l7.tex = FRT_CHURCH;
	curTable.l7.note = FRN_CHURCH; // KK
	curTable.l7.location = "Havana_church";
	// navy residence
	curTable.l8.pic = FRP_HQ;
	curTable.l8.tex = FRT_HQ;
	curTable.l8.note = FRN_HQ; // KK
	curTable.l8.location = "Havana_House_03";
/*	curTable.l8.pic = FRP_HQ;
	curTable.l8.tex = FRP_HQ;
	curTable.l8.note = FRP_HQ; //JRH
	curTable.l8.location = "Havana_House_03";*/
/*
	// loanshark GreatZen
	curTable.l9.pic = FRP_LOANSHARK;
	curTable.l9.tex = FRT_LOANSHARK;
	curTable.l9.location = "";*/

	makearef(curTable,objFastReloadTable.table.Grand_Cayman);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE; // KK
	curTable.l1.location = "Grand_Cayman_Store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD; // KK
	curTable.l2.location = "Grand_Cayman_shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN; // KK
	curTable.l3.location = "Grand_Cayman_Tavern";
// KK -->
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE;
	curTable.l4.location = "Grand_Cayman_townhall";
	// fort
	curTable.l5.pic = FRP_FORT;
	curTable.l5.tex = FRT_FORT;
	curTable.l5.note = FRN_FORT; // KK
	curTable.l5.location = "Cayman_fakefort1";
// <-- KK
/*
	// loanshark GreatZen
	curTable.l5.pic = FRP_LOANSHARK;
	curTable.l5.tex = FRT_LOANSHARK;
	curTable.l5.location = "";
	// church MAXIMUS
	curTable.l6.pic = FRP_CHURCH;
	curTable.l6.tex = FRT_CHURCH;
	curTable.l6.location = "";*/

	makearef(curTable,objFastReloadTable.table.Antigua);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE; // KK
	curTable.l1.location = "Antigua_store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD; // KK
	curTable.l2.location = "Antigua_yard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN; // KK
	curTable.l3.location = "Antigua_Tavern";
	// residence, naval HQ
	curTable.l4.pic = FRP_HQ;	// JRH
	curTable.l4.tex = FRT_HQ;
	curTable.l4.note = FRN_HQ;
	curTable.l4.location = "Antigua_Residence";
// KK -->
	// Fort
	curTable.l5.pic = FRP_FORT;
	curTable.l5.tex = FRT_FORT;
	curTable.l5.note = FRN_FORT;
	curTable.l5.location = "Antigua_fakefort1";
// <-- KK
	// academy
	curTable.l6.pic = FRP_ACADEMY;	//JRH
	curTable.l6.tex = FRT_ACADEMY;
	curTable.l6.note = FRN_ACADEMY;
	curTable.l6.location = "Antigua_Academy";
/*
	// loanshark GreatZen
	curTable.l5.pic = FRP_LOANSHARK;
	curTable.l5.tex = FRT_LOANSHARK;
	curTable.l5.location = "";
	// church MAXIMUS
	curTable.l6.pic = FRP_CHURCH;
	curTable.l6.tex = FRT_CHURCH;
	curTable.l6.location = "";*/

	makearef(curTable,objFastReloadTable.table.Tortuga);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE; // KK
	curTable.l1.location = "Tortuga_store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD; // KK
	curTable.l2.location = "Tortuga_shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN; // KK
	curTable.l3.location = "Tortuga_tavern";
	// brothel MAXIMUS
	curTable.l4.pic = FRP_BROTHEL;
	curTable.l4.tex = FRT_BROTHEL;
	curTable.l4.note = FRN_BROTHEL; // KK
	curTable.l4.location = "Tortuga_Brothel";
	// loanshark MAXIMUS
	curTable.l5.pic = FRP_LOANSHARK;
	curTable.l5.tex = FRT_LOANSHARK;
	curTable.l5.note = FRN_LOANSHARK; // KK
	curTable.l5.location = "Tortuga_usurer";
	// residence MAXIMUS
	curTable.l6.pic = FRP_RESIDENCE;
	curTable.l6.tex = FRT_RESIDENCE;
	curTable.l6.note = FRN_RESIDENCE;
	curTable.l6.location = "Tortuga_townhall";
    // prison
	curTable.l7.pic = FRP_PRISON;
	curTable.l7.tex = FRT_PRISON;
	curTable.l7.note = FRN_PRISON);
	curTable.l7.location = "Tortuga_prison";
    // tailor
	curTable.l8.pic = FRP_TAILORSHOP;
	curTable.l8.tex = FRT_TAILORSHOP;
	curTable.l8.note = FRN_TAILORSHOP;
	curTable.l8.location = "Tortuga_TailorsShop";
	// church MAXIMUS
/*	curTable.l9.pic = FRP_CHURCH;
	curTable.l9.tex = FRT_CHURCH;
	curTable.l9.note = FRN_CHURCH;
	curTable.l9.location = "Tortuga_Church";*/

// KK -->
	makearef(curTable,objFastReloadTable.table.BuccaneersCamp);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE;
	curTable.l1.location = "BC_Store";
	// tavern
	curTable.l2.pic = FRP_TAVERN;
	curTable.l2.tex = FRT_TAVERN;
	curTable.l2.note = FRN_TAVERN;
	curTable.l2.location = "BC_Tavern";
// <-- KK

	makearef(curTable,objFastReloadTable.table.Marigot);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE; // KK
	curTable.l1.location = "Marigot_store"; // KK
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD; // KK
	curTable.l2.location = "Marigot_Shipyard"; // KK
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN; // KK
	curTable.l3.location = "Marigot_Tavern"; // KK
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE; // KK
	curTable.l4.location = "Marigot_mansion_hall";
// KK -->
	// fort
	curTable.l5.pic = FRP_FORT;
	curTable.l5.tex = FRT_FORT;
	curTable.l5.note = FRN_FORT;
	curTable.l5.location = "Marigot_fakefort1";
// <-- KK
// Levis -->
	// church
	curTable.l6.pic = FRP_CHURCH;
	curTable.l6.tex = FRT_CHURCH;
	curTable.l6.note = FRN_CHURCH; 
	curTable.l6.location = "Marigot_Church";
// Levis <--

	makearef(curTable,objFastReloadTable.table.Philipsburg);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE; // KK
	curTable.l1.location = "Philipsburg_store"; // KK
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD; // KK
	curTable.l2.location = "Philipsburg_Shipyard"; // KK
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN; // KK
	curTable.l3.location = "Philipsburg_Tavern"; // KK
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE; // KK
	curTable.l4.location = "Philipsburg_residence";
// KK -->
	// fort
	curTable.l5.pic = FRP_FORT;
	curTable.l5.tex = FRT_FORT;
	curTable.l5.note = FRN_FORT;
	curTable.l5.location = "Philipsburg_fakefort1";
// <-- KK

	makearef(curTable,objFastReloadTable.table.Santo_Domingo);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE; // KK
	curTable.l1.location = "Santo_Domingo_store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD; // KK
	curTable.l2.location = "Santo_Domingo_Shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN; // KK
	curTable.l3.location = "Santo_Domingo_tavern";
// KK -->
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE;
	curTable.l4.location = "Santo_Domingo_townhall";
	// fort
	curTable.l5.pic = FRP_FORT;
	curTable.l5.tex = FRT_FORT;
	curTable.l5.note = FRN_FORT;
	curTable.l5.location = "Santo_Domingo_fakefort1";
// <-- KK
	curTable.l6.pic = FRP_LOANSHARK;
	curTable.l6.tex = FRT_LOANSHARK;
	curTable.l6.note = FRN_LOANSHARK;
	curTable.l6.location = "Santo_Domingo_usurer";

	makearef(curTable,objFastReloadTable.table.PoPrince);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE; // KK
	curTable.l1.location = "PoPrince_Store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD; // KK
	curTable.l2.location = "PoPrince_Shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN; // KK
	curTable.l3.location = "PoPrince_tavern";
// KK -->
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE;
	curTable.l4.location = "PoPrince_townhall";
	// fort
	curTable.l5.pic = FRP_FORT;
	curTable.l5.tex = FRT_FORT;
	curTable.l5.note = FRN_FORT;
	curTable.l5.location = "PoPrince_fakefort1";
	// French West India Company
	curTable.l6.pic = FRP_FWIC;		//GR
	curTable.l6.tex = FRT_FWIC;
	curTable.l6.note = FRN_FWIC;
	curTable.l6.location = "French_WIC_Office";
// <-- KK

// KK -->
	makearef(curTable,objFastReloadTable.table.Santiago);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE;
	curTable.l1.location = "Santiago_Store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD;
	curTable.l2.location = "Santiago_Shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN;
	curTable.l3.location = "Santiago_tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE;
	curTable.l4.location = "Santiago_townhall";

	makearef(curTable,objFastReloadTable.table.Charlestown);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE;
	curTable.l1.location = "Charlestown_store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD;
	curTable.l2.location = "Charlestown_shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN;
	curTable.l3.location = "Charlestown_tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE;
	curTable.l4.location = "Charlestown_residence";
	// loanshark MAXIMUS
	curTable.l5.pic = FRP_LOANSHARK;
	curTable.l5.tex = FRT_LOANSHARK;
	curTable.l5.note = FRN_LOANSHARK;
	curTable.l5.location = "Charlestown_usurer";
	// brothel MAXIMUS
	curTable.l6.pic = FRP_BROTHEL;
	curTable.l6.tex = FRT_BROTHEL;
	curTable.l6.note = FRN_BROTHEL;
	curTable.l6.location = "Charlestown_Brothel";
	// academy
	curTable.l7.pic = FRP_ACADEMY;		//JRH
	curTable.l7.tex = FRT_ACADEMY;
	curTable.l7.note = FRN_ACADEMY;
	curTable.l7.location = "Charlestown_Academy";
	// Church
	curTable.l8.pic = FRP_CHURCH;		// GR
	curTable.l8.tex = FRT_CHURCH;
	curTable.l8.note = FRN_CHURCH; 
	curTable.l8.location = "Charlestown_church";
	// Guardhouse
	curTable.l9.pic = FRP_PRISON;		// GR
	curTable.l9.tex = FRT_PRISON;
	curTable.l9.note = FRN_PRISON;
	curTable.l9.location = "Charlestown_Guardhouse";

	makearef(curTable,objFastReloadTable.table.Oranjestad);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE;
	curTable.l1.location = "Oranjestad_store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD;
	curTable.l2.location = "Oranjestad_shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN;
	curTable.l3.location = "Oranjestad_tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE;
	curTable.l4.location = "Oranjestad_townhall";
	// loanshark GreatZen
	curTable.l5.pic = FRP_LOANSHARK;
	curTable.l5.tex = FRT_LOANSHARK;
	curTable.l5.note = FRN_LOANSHARK;
	curTable.l5.location = "Oranjestad_UsurerHouse";
	// church MAXIMUS
	curTable.l6.pic = FRP_CHURCH;
	curTable.l6.tex = FRT_CHURCH;
	curTable.l6.note = FRN_CHURCH; 
	curTable.l6.location = "Oranjestad_church";
	// tailor's shop
	curTable.l7.pic = FRP_TAILORSHOP;
	curTable.l7.tex = FRT_TAILORSHOP;
	curTable.l7.note = FRN_TAILORSHOP;
	curTable.l7.location = "Oranjestad_TailorsShop";
	// indian store
	curTable.l8.pic = FRP_INDIANSTORE;		//JRH
	curTable.l8.tex = FRT_INDIANSTORE;
	curTable.l8.note = FRN_INDIANSTORE;
	curTable.l8.location = "Oranjestad_Store_02";

	makearef(curTable,objFastReloadTable.table.Willemstad);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE;
	curTable.l1.location = "Willemstad_store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD;
	curTable.l2.location = "Willemstad_shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN;
	curTable.l3.location = "Willemstad_tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE;
	curTable.l4.location = "Willemstad_townhall";
	// loanshark GreatZen
	curTable.l5.pic = FRP_LOANSHARK;
	curTable.l5.tex = FRT_LOANSHARK;
	curTable.l5.note = FRN_LOANSHARK;
	curTable.l5.location = "Willemstad_UsurerHouse";
	// church MAXIMUS
	curTable.l6.pic = FRP_CHURCH;
	curTable.l6.tex = FRT_CHURCH;
	curTable.l6.note = FRN_CHURCH; 
	curTable.l6.location = "Willemstad_church";
	// tailor's shop
	curTable.l7.pic = FRP_TAILORSHOP;
	curTable.l7.tex = FRT_TAILORSHOP;
	curTable.l7.note = FRN_TAILORSHOP;
	curTable.l7.location = "Willemstad_TailorsShop";
	// DWIC
	curTable.l8.pic = FRP_DWIC;		//JRH
	curTable.l8.tex = FRT_DWIC;
	curTable.l8.note = FRN_DWIC;
	curTable.l8.location = "DWIC";

	makearef(curTable,objFastReloadTable.table.Eleuthera);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE;
	curTable.l1.location = "Eleuthera_store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD;
	curTable.l2.location = "Eleuthera_shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN;
	curTable.l3.location = "Eleuthera_tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE;
	curTable.l4.location = "Eleuthera_townhall";
	// loanshark GreatZen
	curTable.l5.pic = FRP_LOANSHARK;
	curTable.l5.tex = FRT_LOANSHARK;
	curTable.l5.note = FRN_LOANSHARK;
	curTable.l5.location = "Eleuthera_UsurerHouse";
	// church MAXIMUS
	curTable.l6.pic = FRP_CHURCH;
	curTable.l6.tex = FRT_CHURCH;
	curTable.l6.note = FRN_CHURCH; 
	curTable.l6.location = "Eleuthera_church";
	// tailor's shop
	curTable.l7.pic = FRP_TAILORSHOP;
	curTable.l7.tex = FRT_TAILORSHOP;
	curTable.l7.note = FRN_TAILORSHOP;
	curTable.l7.location = "Eleuthera_TailorsShop";
	
	makearef(curTable,objFastReloadTable.table.Cartagena);
	// store
	curTable.l1.pic = FRP_STORE;
	curTable.l1.tex = FRT_STORE;
	curTable.l1.note = FRN_STORE; // KK
	curTable.l1.location = "Cartagena_store";
	// shipyard
	curTable.l2.pic = FRP_SHIPYARD;
	curTable.l2.tex = FRT_SHIPYARD;
	curTable.l2.note = FRN_SHIPYARD; // KK
	curTable.l2.location = "Cartagena_shipyard";
	// tavern
	curTable.l3.pic = FRP_TAVERN;
	curTable.l3.tex = FRT_TAVERN;
	curTable.l3.note = FRN_TAVERN; // KK
	curTable.l3.location = "Cartagena_tavern";
	// residence
	curTable.l4.pic = FRP_RESIDENCE;
	curTable.l4.tex = FRT_RESIDENCE;
	curTable.l4.note = FRN_RESIDENCE; // KK
	curTable.l4.location = "Cartagena_Townhall";
	// loanshark GreatZen
	curTable.l5.pic = FRP_LOANSHARK;
	curTable.l5.tex = FRT_LOANSHARK;
	curTable.l5.note = FRN_LOANSHARK; // KK
	curTable.l5.location = "Cartagena_UsurerHouse";
	// church MAXIMUS
	curTable.l6.pic = FRP_CHURCH;
	curTable.l6.tex = FRT_CHURCH;
	curTable.l6.note = FRN_CHURCH; // KK
	curTable.l6.location = "Cartagena_church";
// KK -->
	// tailor's shop
	curTable.l7.pic = FRP_TAILORSHOP;
	curTable.l7.tex = FRT_TAILORSHOP;
	curTable.l7.note = FRN_TAILORSHOP;
	curTable.l7.location = "Cartagena_TailorsShop";
	// blacksmith
	curTable.l8.pic = FRP_BLACKSMITH;
	curTable.l8.tex = FRT_BLACKSMITH;
	curTable.l8.note = FRN_BLACKSMITH;
	curTable.l8.location = "Cartagena_blacksmith";
// <-- KK
	// tavern 2
	curTable.l9.pic = FRP_TAVERN2;		//JRH
	curTable.l9.tex = FRT_TAVERN2;
	curTable.l9.note = FRN_TAVERN2; 	
	curTable.l9.location = "Cartagena_tavern2";
	// naval HQ
	curTable.l10.pic = FRP_HQ;		//JRH
	curTable.l10.tex = FRT_HQ;
	curTable.l10.note = FRN_HQ;
	curTable.l10.location = "Admiral_Office";
	// Casa de Contratación
	curTable.l11.pic = FRP_CDC;		//GR
	curTable.l11.tex = FRT_CDC;
	curTable.l11.note = FRN_CDC;
	curTable.l11.location = "CdC_Office";

	makearef(curTable,objFastReloadTable.table.Ship);
	// ship deck
	curTable.l1.pic = FRP_SHIPDECK;
	curTable.l1.tex = FRT_SHIPDECK;
	curTable.l1.note = FRN_SHIPDECK;
	curTable.l1.location = "ShipDeck";
	// cabin
	curTable.l2.pic = FRP_CABIN;
	curTable.l2.tex = FRT_CABIN;
	curTable.l2.note = FRN_CABIN;
	curTable.l2.location = "Cabin";
	// crew quarters
	curTable.l3.pic = FRP_SEADOGS;
	curTable.l3.tex = FRT_SEADOGS;
	curTable.l3.note = FRN_SEADOGS;
	curTable.l3.location = "Seadogs";
	// cannons deck 1
	curTable.l4.pic = FRP_DECK1;
	curTable.l4.tex = FRT_DECK1;
	curTable.l4.note = FRN_DECK1;
	curTable.l4.location = "Deck1";
	// cannons deck 2
	curTable.l5.pic = FRP_DECK2;
	curTable.l5.tex = FRT_DECK2;
	curTable.l5.note = FRN_DECK2;
	curTable.l5.location = "Deck2";
	// cannons deck 3
	curTable.l6.pic = FRP_DECK3;
	curTable.l6.tex = FRT_DECK3;
	curTable.l6.note = FRN_DECK3;
	curTable.l6.location = "Deck3";
	// cargo hold 1
	curTable.l7.pic = FRP_HOLD;
	curTable.l7.tex = FRT_HOLD;
	curTable.l7.note = FRN_HOLD;
	curTable.l7.location = "Hold1";
	// cargo hold 2
	curTable.l8.pic = FRP_HOLD;
	curTable.l8.tex = FRT_HOLD;
	curTable.l8.note = FRN_HOLD+"2";
	curTable.l8.location = "Hold2";
	// port
	curTable.l9.pic = FRP_PORT;
	curTable.l9.tex = FRT_PORT;
	curTable.l9.note = FRN_PORT;
	curTable.l9.location = "Port";
// <-- KK
}
