#include "sea_ai\walk\Barque_walk.c"
#include "sea_ai\walk\Galeon1_walk.c"
#include "sea_ai\walk\Galeon2_walk.c"
#include "sea_ai\walk\Frigate_walk.c"
#include "sea_ai\walk\Frigate2_walk.c"
#include "sea_ai\walk\Frigate_sat_walk.c"
#include "sea_ai\walk\Corvette_walk.c"
#include "sea_ai\walk\Battleship_walk.c"
#include "sea_ai\walk\Battleship4_walk.c"
#include "sea_ai\walk\Caravel_walk.c"
#include "sea_ai\walk\Caravel2_walk.c"
#include "sea_ai\walk\Brig_walk.c"
#include "sea_ai\walk\Brig_20_Gun1_18_walk.c"
#include "sea_ai\walk\BrigQeen_walk.c"
#include "sea_ai\walk\BrigSW_walk.c"
#include "sea_ai\walk\Fleut1_walk.c"
#include "sea_ai\walk\Fleut2_walk.c"
#include "sea_ai\walk\Lugger_walk.c"
#include "sea_ai\walk\Lugger2_walk.c"
#include "sea_ai\walk\Schooner_walk.c"
#include "sea_ai\walk\Tartane_walk.c"
#include "sea_ai\walk\Xebec1_walk.c"
#include "sea_ai\walk\Xebec2_walk.c"
#include "sea_ai\walk\Yacht1_walk.c"
#include "sea_ai\walk\Yacht2_walk.c"
#include "sea_ai\walk\Pinnace_walk.c"
#include "sea_ai\walk\Manowar1_walk.c"
#include "sea_ai\walk\Manowar2_walk.c"
#include "sea_ai\walk\Manowar_gub_walk.c"
#include "sea_ai\walk\Sloop_walk.c"
#include "sea_ai\walk\Sloop2_walk.c"
#include "sea_ai\walk\Galeoth1_walk.c"
#include "sea_ai\walk\Galeoth2_walk.c"
#include "sea_ai\walk\Lineship_walk.c"
#include "sea_ai\walk\Warship_walk.c" // Surak'nar
#include "sea_ai\walk\Indefatigable_walk.c"
#include "sea_ai\walk\Flushdeck_walk.c"
#include "sea_ai\walk\SloopBermuda_walk.c"
#include "sea_ai\walk\Cutter1_walk.c"
#include "sea_ai\walk\Indiaman1_walk.c"
#include "sea_ai\walk\LuggerVML_walk.c"
#include "sea_ai\walk\LuggerP_walk.c"
#include "sea_ai\walk\BlackPearl_walk.c"
#include "sea_ai\walk\Ketch_walk.c" //Petros
#include "sea_ai\walk\Tartane50_walk.c" //Petros
#include "sea_ai\walk\Amsterdam_walk.c" //SeaNorris
#include "sea_ai\walk\FlyingDutchman_walk.c" //ZarethPL
#include "sea_ai\walk\Constitution_walk.c" //ZarethPL
#include "sea_ai\walk\XebecAS_walk.c" //ZarethPL
#include "sea_ai\walk\Bounty_walk.c" //ZarethPL
#include "sea_ai\walk\Dutchlineship1_walk.c" //Thomas the Terror
#include "sea_ai\walk\Corvette47_walk.c" //Sprut
#include "sea_ai\walk\LightFleut_walk.c" //SeaNorris
#include "sea_ai\walk\BarqueHeavy_walk.c" //back84
#include "sea_ai\walk\Carrack_walk.c" //back84
#include "sea_ai\walk\FastGalleon_walk.c" //back84
#include "sea_ai\walk\FleutWar_walk.c" //back84
#include "sea_ai\walk\Hooker_walk.c" //back84
#include "sea_ai\walk\LightPinnace_walk.c" //back84
#include "sea_ai\walk\Lugger3_walk.c" //back84
#include "sea_ai\walk\Sloop3_walk.c" //back84
#include "sea_ai\walk\WarGalleon_walk.c" //back84
#include "sea_ai\walk\Victory_walk.c" //pgargon -->
#include "sea_ai\Walk\Superbe_walk.c" 
#include "sea_ai\Walk\Bellona_walk.c"
#include "sea_ai\Walk\Nonsuch_walk.c"
#include "sea_ai\Walk\Greyhound_walk.c"
#include "sea_ai\Walk\Sophie_walk.c"
#include "sea_ai\Walk\USS_Enterprise_walk.c"
#include "sea_ai\Walk\Mordaunt_walk.c" //pgargon <--
#include "sea_ai\Walk\RN_Surprise_walk.c" //Jack Harrison
#include "sea_ai\Walk\Couronne_walk.c" //pgargon
#include "sea_ai\walk\ApostolFelipe_walk.c" //pgargon
#include "sea_ai\walk\Hannah_walk.c" //pgargon
#include "sea_ai\walk\Hannah_p_walk.c" //pgargon
#include "sea_ai\walk\Speedy_walk.c" //pgargon
#include "sea_ai\walk\Endeavour_walk.c" //pgargon
#include "sea_ai\walk\HMS_Surprise_walk.c" //craiggo
#include "sea_ai\walk\Poseidon_walk.c" //craiggo
#include "sea_ai\walk\BattleGalleon_walk.c" //craiggo
#include "sea_ai\walk\SanFelipe_walk.c" //pgargon
#include "sea_ai\walk\Intrepide_walk.c" //craiggo
#include "sea_ai\walk\SteamFrigate_walk.c" //Armada
#include "sea_ai\walk\Interceptor_walk.c" //Armada
#include "sea_ai\walk\CaravelR_walk.c" //pgargon
#include "sea_ai\walk\Revenge_walk.c"   //Hylie Pistof
#include "sea_ai\walk\QueenAnnesRevenge_walk.c"   //craiggo
#include "sea_ai\walk\Lyon_walk.c"   //Hylie Pistof
#include "sea_ai\walk\Neptunus_walk.c"   //Hylie Pistof
#include "sea_ai\walk\NL_Pinnace_walk.c"   //Hylie Pistof
#include "sea_ai\walk\DutchPinnace_walk.c"   //Hylie Pistof
#include "sea_ai\walk\Derfflinger_walk.c"   //Hylie Pistof
#include "sea_ai\walk\FWzP_walk.c"   //Hylie Pistof
#include "sea_ai\walk\Unicorn_walk.c"   //Hylie Pistof
#include "sea_ai\walk\Dilligente_walk.c"   //Hylie Pistof
#include "sea_ai\walk\RaaFrigate_walk.c"   //Hylie Pistof
#include "sea_ai\walk\Postillionen_walk.c"   //Hylie Pistof
#include "sea_ai\walk\Empress_walk.c"	//Iron Roger Flint
#include "sea_ai\walk\PrinceNeufchatel_walk.c"	//Captain Armstrong
#include "sea_ai\walk\Volage_walk.c"	//Captain Armstrong
#include "sea_ai\walk\US_Essex_walk.c"	//Captain Armstrong
#include "sea_ai\walk\XebecVML_walk.c"	//Rider88
#include "sea_ai\walk\Centurion_walk.c" //Armada
#include "sea_ai\walk\Aurora_walk.c" //Armada
#include "sea_ai\walk\FastMerchantman_walk.c" //Armada
#include "sea_ai\walk\Polacca_walk.c" //De Zeeroovers
#include "sea_ai\walk\PinnaceMerchant_walk.c" //De Zeeroovers
#include "sea_ai\walk\PinnaceMedium_walk.c" //Hylie Pistof
#include "sea_ai\walk\GoldenHind_walk.c" //JRH
#include "sea_ai\walk\CastelF_walk.c" //Hylie Pistof

void Ship_Walk_Init()
{
	Barque_walk_init();
	Galeon1_walk_init();
	Galeon2_walk_init();
	Galeoth1_walk_init();
	Galeoth2_walk_init();
	Frigate_walk_init();
	Frigate2_walk_init();
	Frigate_sat_walk_init();
	Corvette_walk_init();
	Battleship_walk_init();
	Battleship4_walk_init();
	Caravel_walk_init();
	Caravel2_walk_init();
	Brig_walk_init();
	Brig_20_Gun1_18_walk_init();
	BrigQeen_walk_init();
	BrigSW_walk_init();
	Fleut1_walk_init();
	Fleut2_walk_init();
	Lugger_walk_init();
	Lugger2_walk_init();
	Schooner_walk_init();
	Tartane_walk_init();
	Xebec1_walk_init();
	Xebec2_walk_init();
	Yacht1_walk_init();
	Yacht2_walk_init();
	Pinnace_walk_init();
	Manowar1_walk_init();
	Manowar2_walk_init();
	Manowar_gub_walk_init();
	Sloop_walk_init();
	Sloop2_walk_init();
	Lineship_walk_init();
	Warship_walk_init(); // Surak'nar
	Indefatigable_walk_init();
	Flushdeck_walk_init();
	SloopBermuda_walk_init();
	Cutter1_walk_init();
	Indiaman1_walk_init();
	LuggerVML_walk_init();
	LuggerP_walk_init();
	BlackPearl_walk_init();
	Ketch_walk_init();
	Tartane50_walk_init(); // Petros
	Amsterdam_walk_init();
	FlyingDutchman_walk_init(); // ZarethPL
	Constitution_walk_init(); // ZarethPL
	XebecAS_walk_init(); // ZarethPL
	Bounty_walk_init(); // ZarethPL
	Dutchlineship1_walk_init(); // Thomas the Terror
	Corvette47_walk_init(); // Sprut
	LightFleut_walk_init(); // SeaNorris
	BarqueHeavy_walk_init(); //back84
	Carrack_walk_init(); //back84
	FastGalleon_walk_init(); //back84
	FleutWar_walk_init(); //back84
	Hooker_walk_init(); //back84
	LightPinnace_walk_init(); //back84
	Lugger3_walk_init(); //back84
	Sloop3_walk_init(); //back84
	WarGalleon_walk_init(); //back84
	Victory_walk_init(); // pgargon -->
	Superbe_walk_init();
	Bellona_walk_init();
	Nonsuch_walk_init();
	Greyhound_walk_init();
	Sophie_walk_init();
	USS_Enterprise_walk_init();
	Mordaunt_walk_init(); // pgargon <--
	RN_Surprise_walk_init(); //Jack Harrison
	Couronne_walk_init(); // pgargon
	ApostolFelipe_walk_init(); // pgargon
	Hannah_walk_init(); //pgargon
	Hannah_p_walk_init(); //pgargon
	Speedy_walk_init(); //pgargon
	Endeavour_walk_init(); //pgargon
	HMS_Surprise_walk_init(); //craiggo
	Poseidon_walk_init(); //craiggo
	BattleGalleon_walk_init(); //craiggo
	SanFelipe_walk_init(); //pgargon
	Intrepide_walk_init(); //craiggo
	SteamFrigate_walk_init(); //Armada
	Interceptor_walk_init(); //Armada
	CaravelR_walk_init(); //pgargon
	Revenge_walk_init();   //Hylie Pistof
	QueenAnnesRevenge_walk_init();   //craiggo
	Lyon_walk_init();   //Hylie Pistof
	Neptunus_walk_init();   //Hylie Pistof
	NL_Pinnace_walk_init();   //Hylie Pistof
	DutchPinnace_walk_init();   //Hylie Pistof
	Derfflinger_walk_init();   //Hylie Pistof
	FWzP_walk_init();   //Hylie Pistof
	Unicorn_walk_init();   //Hylie Pistof
	Dilligente_walk_init();   //Hylie Pistof
	RaaFrigate_walk_init();   //Hylie Pistof
	Postillionen_walk_init();   //Hylie Pistof
	Empress_walk_init();	//Iron Roger Flint
	PrinceNeufchatel_walk_init();	//Captain Armstrong
	Volage_walk_init();	//Captain Armstrong
	US_Essex_walk_init();	//Captain Armstrong
	XebecVML_walk_init();	//Rider88
	Centurion_walk_init(); //Armada
	Aurora_walk_init(); //Armada
	FastMerchantman_walk_init(); //Armada
	Polacca_walk_init(); //De Zeeroovers
	PinnaceMerchant_walk_init(); //De Zeeroovers
	PinnaceMedium_walk_init(); //Hylie Pistof
	GoldenHind_walk_init(); //JRH
	CastelF_walk_init(); //Hylie Pistof
}

void Ship_Walk_Create()
{
	int charIndex = GetEventData();
	aref ship = GetEventData();
	
	ref ch = GetCharacter(charIndex);
	int shipType = GetCharacterShipType(ch); // PS

	//Trace("Adding ship: " + ShipsTypes[shipType].name);

	// PS -->
	string walk = ShipsTypes[shipType].name;
	if(CheckAttribute(ShipsTypes[shipType],"walk")) walk = ShipsTypes[shipType].walk;

	switch (walk)
	// PS <--
	{
	case "GALEOTH1":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Galeoth1_walk_count, &Galeoth1_walk_verts, &Galeoth1_walk_graph, &Galeoth1_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "GALEOTH1", Galeoth1_walk_count, &Galeoth1_walk_verts, &Galeoth1_walk_graph, &Galeoth1_walk_types);
		break;
	case "GALEOTH2":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Galeoth2_walk_count, &Galeoth2_walk_verts, &Galeoth2_walk_graph, &Galeoth2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "GALEOTH2", Galeoth2_walk_count, &Galeoth2_walk_verts, &Galeoth2_walk_graph, &Galeoth2_walk_types);
		break;
	case "GALEON1":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Galeon1_walk_count, &Galeon1_walk_verts, &Galeon1_walk_graph, &Galeon1_walk_types);
		//SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "GALEON1", Galeon1_walk_count, &Galeon1_walk_verts, &Galeon1_walk_graph, &Galeon1_walk_types);
		break;
	case "GALEON2":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Galeon2_walk_count, &Galeon2_walk_verts, &Galeon2_walk_graph, &Galeon2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "GALEON2", Galeon2_walk_count, &Galeon2_walk_verts, &Galeon2_walk_graph, &Galeon2_walk_types);
		break;
	case "FRIGATE":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Frigate_walk_count, &Frigate_walk_verts, &Frigate_walk_graph, &Frigate_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "FRIGATE1", Frigate_walk_count, &Frigate_walk_verts, &Frigate_walk_graph, &Frigate_walk_types);
		break;
	case "FRIGATE2":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Frigate2_walk_count, &Frigate2_walk_verts, &Frigate2_walk_graph, &Frigate2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "FRIGATE2", Frigate2_walk_count, &Frigate2_walk_verts, &Frigate2_walk_graph, &Frigate2_walk_types);
		break;
	case "FRIGATE_SAT":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Frigate_sat_walk_count, &Frigate_sat_walk_verts, &Frigate_sat_walk_graph, &Frigate_sat_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "FRIGATE_sat", Frigate_sat_walk_count, &Frigate_sat_walk_verts, &Frigate_sat_walk_graph, &Frigate_sat_walk_types);
		break;
	case "CORVETTE":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Corvette_walk_count, &Corvette_walk_verts, &Corvette_walk_graph, &Corvette_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "CORVETTE1", Corvette_walk_count, &Corvette_walk_verts, &Corvette_walk_graph, &Corvette_walk_types);
        break;
	case "BARQUE1":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Barque_walk_count, &Barque_walk_verts, &Barque_walk_graph, &Barque_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BARQUE1", Barque_walk_count, &Barque_walk_verts, &Barque_walk_graph, &Barque_walk_types);
        break;
	case "BARQUE2":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Barque_walk_count, &Barque_walk_verts, &Barque_walk_graph, &Barque_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BARQUE2", Barque_walk_count, &Barque_walk_verts, &Barque_walk_graph, &Barque_walk_types);
        break;
	case "BATTLESHIP1":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Battleship_walk_count, &Battleship_walk_verts, &Battleship_walk_graph, &Battleship_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BATTLESHIP1", Battleship_walk_count, &Battleship_walk_verts, &Battleship_walk_graph, &Battleship_walk_types);
        break;
	case "BATTLESHIP2":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Battleship_walk_count, &Battleship_walk_verts, &Battleship_walk_graph, &Battleship_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BATTLESHIP2", Battleship_walk_count, &Battleship_walk_verts, &Battleship_walk_graph, &Battleship_walk_types);
        break;
	case "BATTLESHIP4":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Battleship4_walk_count, &Battleship4_walk_verts, &Battleship4_walk_graph, &Battleship4_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BATTLESHIP4", Battleship4_walk_count, &Battleship4_walk_verts, &Battleship4_walk_graph, &Battleship4_walk_types);
        break;
 	case "BRIG1":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Brig_walk_count, &Brig_walk_verts, &Brig_walk_graph, &Brig_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BRIG1", Brig_walk_count, &Brig_walk_verts, &Brig_walk_graph, &Brig_walk_types);
        break;
 	case "BRIG2":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Brig_walk_count, &Brig_walk_verts, &Brig_walk_graph, &Brig_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BRIG2", Brig_walk_count, &Brig_walk_verts, &Brig_walk_graph, &Brig_walk_types);
        break;
 	case "BRIG_20_GUN1_18":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Brig_20_Gun1_18_walk_count, &Brig_20_Gun1_18_walk_verts, &Brig_20_Gun1_18_walk_graph, &Brig_20_Gun1_18_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BRIG_20_GUN1_18", Brig_20_Gun1_18_walk_count, &Brig_20_Gun1_18_walk_verts, &Brig_20_Gun1_18_walk_graph, &Brig_20_Gun1_18_walk_types);
        break;
 	case "BRIGQEEN":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,BrigQeen_walk_count, &BrigQeen_walk_verts, &BrigQeen_walk_graph, &BrigQeen_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BRIGQEEN", BrigQeen_walk_count, &BrigQeen_walk_verts, &BrigQeen_walk_graph, &BrigQeen_walk_types);
        break;
 	case "BRIGSW":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,BrigSW_walk_count, &BrigSW_walk_verts, &BrigSW_walk_graph, &BrigSW_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BRIGSW", BrigSW_walk_count, &BrigSW_walk_verts, &BrigSW_walk_graph, &BrigSW_walk_types);
        break;
	case "CARAVEL1":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Caravel_walk_count, &Caravel_walk_verts, &Caravel_walk_graph, &Caravel_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "CARAVEL1", Caravel_walk_count, &Caravel_walk_verts, &Caravel_walk_graph, &Caravel_walk_types);
        break;
	case "CARAVEL2":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Caravel2_walk_count, &Caravel2_walk_verts, &Caravel2_walk_graph, &Caravel2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "CARAVEL2", Caravel2_walk_count, &Caravel2_walk_verts, &Caravel2_walk_graph, &Caravel2_walk_types);
        break;
	case "FLEUT1":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Fleut1_walk_count, &Fleut1_walk_verts, &Fleut1_walk_graph, &Fleut1_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "FLEUT1", Fleut1_walk_count, &Fleut1_walk_verts, &Fleut1_walk_graph, &Fleut1_walk_types);
        break;
	case "FLEUT2":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Fleut2_walk_count, &Fleut2_walk_verts, &Fleut2_walk_graph, &Fleut2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "FLEUT2", Fleut2_walk_count, &Fleut2_walk_verts, &Fleut2_walk_graph, &Fleut2_walk_types);
        break;
	case "LUGGER1":
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Lugger_walk_count, &Lugger_walk_verts, &Lugger_walk_graph, &Lugger_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "LUGGER1", Lugger_walk_count, &Lugger_walk_verts, &Lugger_walk_graph, &Lugger_walk_types);
        break;
	case "LUGGER2":
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Lugger2_walk_count, &Lugger2_walk_verts, &Lugger2_walk_graph, &Lugger2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "LUGGER2", Lugger2_walk_count, &Lugger2_walk_verts, &Lugger2_walk_graph, &Lugger2_walk_types);
        break;
	case "SCHOONER1":
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Schooner_walk_count, &Schooner_walk_verts, &Schooner_walk_graph, &Schooner_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "SCHOONER1", Schooner_walk_count, &Schooner_walk_verts, &Schooner_walk_graph, &Schooner_walk_types);
        break;
	case "SCHOONER2":
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Schooner_walk_count, &Schooner_walk_verts, &Schooner_walk_graph, &Schooner_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "SCHOONER2", Schooner_walk_count, &Schooner_walk_verts, &Schooner_walk_graph, &Schooner_walk_types);
        break;
	case "TARTANE1":
    	SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Tartane_walk_count, &Tartane_walk_verts, &Tartane_walk_graph, &Tartane_walk_types);
        ////SendMessage(WALK_TOOL,"ls", AI_MESSAGE_ADD_SHIP, "TARTANE1", Tartane_walk_count, &Tartane_walk_verts, &Tartane_walk_graph, &Tartane_walk_types);
        break;
	case "TARTANE2":
    	SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Tartane_walk_count, &Tartane_walk_verts, &Tartane_walk_graph, &Tartane_walk_types);
        ////SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "TARTANE", Tartane_walk_count, &Tartane_walk_verts, &Tartane_walk_graph, &Tartane_walk_types);
        break;
	case "XEBEC1":
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Xebec1_walk_count, &Xebec1_walk_verts, &Xebec1_walk_graph, &Xebec1_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "XEBEC1", Xebec1_walk_count, &Xebec1_walk_verts, &Xebec1_walk_graph, &Xebec1_walk_types);
        break;
	case "XEBEC2":
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Xebec2_walk_count, &Xebec2_walk_verts, &Xebec2_walk_graph, &Xebec2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "XEBEC2", Xebec2_walk_count, &Xebec2_walk_verts, &Xebec2_walk_graph, &Xebec2_walk_types);
        break;
	case "YACHT1": 
    	SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Yacht1_walk_count, &Yacht1_walk_verts, &Yacht1_walk_graph, &Yacht1_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "YACHT1", Yacht1_walk_count, &Yacht1_walk_verts, &Yacht1_walk_graph, &Yacht1_walk_types);
		break;
	case "YACHT2": 
    	SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Yacht2_walk_count, &Yacht2_walk_verts, &Yacht2_walk_graph, &Yacht2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "YACHT2", Yacht2_walk_count, &Yacht2_walk_verts, &Yacht2_walk_graph, &Yacht2_walk_types);
		break;
	case "PINNACE1": 
    	SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Pinnace_walk_count, &Pinnace_walk_verts, &Pinnace_walk_graph, &Pinnace_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "PINNACE1", Pinnace_walk_count, &Pinnace_walk_verts, &Pinnace_walk_graph, &Pinnace_walk_types);
		break;                                                              
	case "PINNACE2": 
    	SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Pinnace_walk_count, &Pinnace_walk_verts, &Pinnace_walk_graph, &Pinnace_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "PINNACE2", Pinnace_walk_count, &Pinnace_walk_verts, &Pinnace_walk_graph, &Pinnace_walk_types);
		break;
	case "MANOWAR1": 
        SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Manowar1_walk_count, &Manowar1_walk_verts, &Manowar1_walk_graph, &Manowar1_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "MANOWAR1", Manowar1_walk_count, &Manowar1_walk_verts, &Manowar1_walk_graph, &Manowar1_walk_types);
		break;
	case "MANOWAR2": 
        SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Manowar2_walk_count, &Manowar2_walk_verts, &Manowar2_walk_graph, &Manowar2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "MANOWAR2", Manowar2_walk_count, &Manowar2_walk_verts, &Manowar2_walk_graph, &Manowar2_walk_types);
		break;
	case "MANOWAR_GUB": 
        SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Manowar_gub_walk_count, &Manowar_gub_walk_verts, &Manowar_gub_walk_graph, &Manowar_gub_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "MANOWAR_gub", Manowar_gub_walk_count, &Manowar_gub_walk_verts, &Manowar_gub_walk_graph, &Manowar_gub_walk_types);
		break;
	case "SLOOP1": 
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Sloop_walk_count, &Sloop_walk_verts, &Sloop_walk_graph, &Sloop_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "SLOOP1", Sloop_walk_count, &Sloop_walk_verts, &Sloop_walk_graph, &Sloop_walk_types);
		break;
	case "SLOOP2": 
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Sloop2_walk_count, &Sloop2_walk_verts, &Sloop2_walk_graph, &Sloop2_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "SLOOP2", Sloop2_walk_count, &Sloop2_walk_verts, &Sloop2_walk_graph, &Sloop2_walk_types);
		break;
	case "Lineship": 
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Lineship_walk_count, &Lineship_walk_verts, &Lineship_walk_graph, &Lineship_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Lineship", Lineship_walk_count, &Lineship_walk_verts, &Lineship_walk_graph, &Lineship_walk_types);
		break;
	//Surak'nar -->
	case "Warship": 
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Warship_walk_count, &Warship_walk_verts, &Warship_walk_graph, &Warship_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Warship", Warship_walk_count, &Warship_walk_verts, &Warship_walk_graph, &Warship_walk_types);
		break;
	//Surak'nar <--
 	case "Flushdeck":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Flushdeck_walk_count, &Flushdeck_walk_verts, &Flushdeck_walk_graph, &Flushdeck_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Flushdeck", Flushdeck_walk_count, &Flushdeck_walk_verts, &Flushdeck_walk_graph, &Flushdeck_walk_types);
		break;   
 	case "Indefatigable":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Indefatigable_walk_count, &Indefatigable_walk_verts, &Indefatigable_walk_graph, &Indefatigable_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Indefatigable", Indefatigable_walk_count, &Indefatigable_walk_verts, &Indefatigable_walk_graph, &Indefatigable_walk_types);
		break;   
	case "SloopBermuda": 
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, SloopBermuda_walk_count, &SloopBermuda_walk_verts, &SloopBermuda_walk_graph, &SloopBermuda_walk_types);
		//SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "SloopBermuda", SloopBermuda_walk_count, &SloopBermuda_walk_verts, &SloopBermuda_walk_graph, &SloopBermuda_walk_types);
		break;
	case "Cutter1": 
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Cutter1_walk_count, &Cutter1_walk_verts, &Cutter1_walk_graph, &Cutter1_walk_types);
		//SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Cutter1", Cutter1_walk_count, &Cutter1_walk_verts, &Cutter1_walk_graph, &Cutter1_walk_types);
		break;
	case "Indiaman1": 
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Indiaman1_walk_count, &Indiaman1_walk_verts, &Indiaman1_walk_graph, &Indiaman1_walk_types);
		//SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Indiaman1", Indiaman1_walk_count, &Indiaman1_walk_verts, &Indiaman1_walk_graph, &Indiaman1_walk_types);
		break;
	case "LuggerVML":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, LuggerVML_walk_count, &LuggerVML_walk_verts, &LuggerVML_walk_graph, &LuggerVML_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "LuggerVML", LuggerVML_walk_count, &LuggerVML_walk_verts, &LuggerVML_walk_graph, &LuggerVML_walk_types);
		break;
	case "LuggerP":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, LuggerP_walk_count, &LuggerP_walk_verts, &LuggerP_walk_graph, &LuggerP_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "LuggerP", LuggerP_walk_count, &LuggerP_walk_verts, &LuggerP_walk_graph, &LuggerP_walk_types);
		break;
	case "BlackPearl":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, BlackPearl_walk_count, &BlackPearl_walk_verts, &BlackPearl_walk_graph, &BlackPearl_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BlackPearl", BlackPearl_walk_count, &BlackPearl_walk_verts, &BlackPearl_walk_graph, &BlackPearl_walk_types);
		break;
	//Petros -->
	case "Ketch": 
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Ketch_walk_count, &Ketch_walk_verts, &Ketch_walk_graph, &Ketch_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Ketch", Ketch_walk_count, &Ketch_walk_verts, &Ketch_walk_graph, &Ketch_walk_types);
	break;

	case "Tartane50": 
	    SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Tartane50_walk_count, &Tartane50_walk_verts, &Tartane50_walk_graph, &Tartane50_walk_types);
       	//SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Tartane50", Tartane50_walk_count, &Tartane50_walk_verts, &Tartane50_walk_graph, &Tartane50_walk_types);
	break;
	//Petros <--
	// SeaNorris -->
	case "Amsterdam":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, Amsterdam_walk_count, &Amsterdam_walk_verts, &Amsterdam_walk_graph, &Amsterdam_walk_types);
		//SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Amsterdam", Amsterdam_walk_count, &Amsterdam_walk_verts, &Amsterdam_walk_graph, &Amsterdam_walk_types);
		break;
	case "LightFleut":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship, LightFleut_walk_count, &LightFleut_walk_verts, &LightFleut_walk_graph, &LightFleut_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "LightFleut", LightFleut_walk_count, &LightFleut_walk_verts, &LightFleut_walk_graph, &LightFleut_walk_types);
        break;
	// SeaNorris <--
	// ZarethPL -->
	case "FlyingDutchman":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,FlyingDutchman_walk_count, &FlyingDutchman_walk_verts, &FlyingDutchman_walk_graph, &FlyingDutchman_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "FlyingDutchman", FlyingDutchman_walk_count, &FlyingDutchman_walk_verts, &FlyingDutchman_walk_graph, &FlyingDutchman_walk_types);
        break;
	case "Constitution":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Constitution_walk_count, &Constitution_walk_verts, &Constitution_walk_graph, &Constitution_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Constitution", Constitution_walk_count, &Constitution_walk_verts, &Constitution_walk_graph, &Constitution_walk_types);
        break;
	case "XebecAS":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,XebecAS_walk_count, &XebecAS_walk_verts, &XebecAS_walk_graph, &XebecAS_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "XebecAS", XebecAS_walk_count, &XebecAS_walk_verts, &XebecAS_walk_graph, &XebecAS_walk_types);
        break;
	case "Bounty":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Bounty_walk_count, &Bounty_walk_verts, &Bounty_walk_graph, &Bounty_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Bounty", Bounty_walk_count, &Bounty_walk_verts, &Bounty_walk_graph, &Bounty_walk_types);
        break;
	// ZarethPL <--
	// Thomas the Terror -->
	case "Dutchlineship1":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Dutchlineship1_walk_count, &Dutchlineship1_walk_verts, &Dutchlineship1_walk_graph, &Dutchlineship1_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Dutchlineship1", Dutchlineship1_walk_count, &Dutchlineship1_walk_verts, &Dutchlineship1_walk_graph, &Dutchlineship1_walk_types);
        break;
	// Thomas the Terror <--
	// Sprut -->
	case "Corvette47":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Corvette47_walk_count, &Corvette47_walk_verts, &Corvette47_walk_graph, &Corvette47_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Corvette47", Corvette47_walk_count, &Corvette47_walk_verts, &Corvette47_walk_graph, &Corvette47_walk_types);
        break;
	// Sprut <--
	// back84 -->
	case "BarqueHeavy":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,BarqueHeavy_walk_count, &BarqueHeavy_walk_verts, &BarqueHeavy_walk_graph, &BarqueHeavy_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BarqueHeavy", BarqueHeavy_walk_count, &BarqueHeavy_walk_verts, &BarqueHeavy_walk_graph, &BarqueHeavy_walk_types);
        break;
	case "Carrack":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Carrack_walk_count, &Carrack_walk_verts, &Carrack_walk_graph, &Carrack_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Carrack", Carrack_walk_count, &Carrack_walk_verts, &Carrack_walk_graph, &Carrack_walk_types);
        break;
	case "FastGalleon":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,FastGalleon_walk_count, &FastGalleon_walk_verts, &FastGalleon_walk_graph, &FastGalleon_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "FastGalleon", FastGalleon_walk_count, &FastGalleon_walk_verts, &FastGalleon_walk_graph, &FastGalleon_walk_types);
        break;
	case "FleutWar":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,FleutWar_walk_count, &FleutWar_walk_verts, &FleutWar_walk_graph, &FleutWar_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "FleutWar", FleutWar_walk_count, &FleutWar_walk_verts, &FleutWar_walk_graph, &FleutWar_walk_types);
        break;
	case "Hooker":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Hooker_walk_count, &Hooker_walk_verts, &Hooker_walk_graph, &Hooker_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Hooker", Hooker_walk_count, &Hooker_walk_verts, &Hooker_walk_graph, &Hooker_walk_types);
        break;
	case "LightPinnace":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,LightPinnace_walk_count, &LightPinnace_walk_verts, &LightPinnace_walk_graph, &LightPinnace_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "LightPinnace", LightPinnace_walk_count, &LightPinnace_walk_verts, &LightPinnace_walk_graph, &LightPinnace_walk_types);
        break;
	case "Lugger3":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Lugger3_walk_count, &Lugger3_walk_verts, &Lugger3_walk_graph, &Lugger3_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Lugger3", Lugger3_walk_count, &Lugger3_walk_verts, &Lugger3_walk_graph, &Lugger3_walk_types);
        break;
	case "Sloop3":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Sloop3_walk_count, &Sloop3_walk_verts, &Sloop3_walk_graph, &Sloop3_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Sloop3", Sloop3_walk_count, &Sloop3_walk_verts, &Sloop3_walk_graph, &Sloop3_walk_types);
        break;
	case "WarGalleon":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,WarGalleon_walk_count, &WarGalleon_walk_verts, &WarGalleon_walk_graph, &WarGalleon_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "WarGalleon", WarGalleon_walk_count, &WarGalleon_walk_verts, &WarGalleon_walk_graph, &WarGalleon_walk_types);
        break;
	// back84 <--
	// pgargon -->
	case "Victory":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Victory_walk_count, &Victory_walk_verts, &Victory_walk_graph, &Victory_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Victory", Victory_walk_count, &Victory_walk_verts, &Victory_walk_graph, &Victory_walk_types);
        break;
	case "Superbe":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Superbe_walk_count, &Superbe_walk_verts, &Superbe_walk_graph, &Superbe_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Superbe", Superbe_walk_count, &Superbe_walk_verts, &Superbe_walk_graph, &Superbe_walk_types);
        break;	
	case "Bellona":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Bellona_walk_count, &Bellona_walk_verts, &Bellona_walk_graph, &Bellona_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Bellona", Bellona_walk_count, &Bellona_walk_verts, &Bellona_walk_graph, &Bellona_walk_types);
        break;
	case "Nonsuch":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Nonsuch_walk_count, &Nonsuch_walk_verts, &Nonsuch_walk_graph, &Nonsuch_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Nonsuch", Nonsuch_walk_count, &Nonsuch_walk_verts, &Nonsuch_walk_graph, &Nonsuch_walk_types);
        break;
	case "Greyhound":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Greyhound_walk_count, &Greyhound_walk_verts, &Greyhound_walk_graph, &Greyhound_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Greyhound", Greyhound_walk_count, &Greyhound_walk_verts, &Greyhound_walk_graph, &Greyhound_walk_types);
        break;
	case "Sophie":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Sophie_walk_count, &Sophie_walk_verts, &Sophie_walk_graph, &Sophie_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Sophie", Sophie_walk_count, &Sophie_walk_verts, &Sophie_walk_graph, &Sophie_walk_types);
        break;
	case "USS_Enterprise":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,USS_Enterprise_walk_count, &USS_Enterprise_walk_verts, &USS_Enterprise_walk_graph, &USS_Enterprise_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "USS_Enterprise", USS_Enterprise_walk_count, &USS_Enterprise_walk_verts, &USS_Enterprise_walk_graph, &USS_Enterprise_walk_types);
        break;
	case "Mordaunt":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Mordaunt_walk_count, &Mordaunt_walk_verts, &Mordaunt_walk_graph, &Mordaunt_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Mordaunt", Mordaunt_walk_count, &Mordaunt_walk_verts, &Mordaunt_walk_graph, &Mordaunt_walk_types);
        break;
	case "Couronne":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Couronne_walk_count, &Couronne_walk_verts, &Couronne_walk_graph, &Couronne_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Couronne", Couronne_walk_count, &Couronne_walk_verts, &Couronne_walk_graph, &Couronne_walk_types);
        break;
	case "ApostolFelipe":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,ApostolFelipe_walk_count, &ApostolFelipe_walk_verts, &ApostolFelipe_walk_graph, &ApostolFelipe_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "ApostolFelipe", ApostolFelipe_walk_count, &ApostolFelipe_walk_verts, &ApostolFelipe_walk_graph, &ApostolFelipe_walk_types);
		break;
	case "Hannah":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Hannah_walk_count, &Hannah_walk_verts, &Hannah_walk_graph, &Hannah_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Hannah", Hannah_walk_count, &Hannah_walk_verts, &Hannah_walk_graph, &Hannah_walk_types);
		break;
	case "Hannah_p":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Hannah_p_walk_count, &Hannah_p_walk_verts, &Hannah_p_walk_graph, &Hannah_p_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Hannah_p", Hannah_p_walk_count, &Hannah_p_walk_verts, &Hannah_p_walk_graph, &Hannah_p_walk_types);
		break;
	case "Speedy":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Speedy_walk_count, &Speedy_walk_verts, &Speedy_walk_graph, &Speedy_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Speedy", Speedy_walk_count, &Speedy_walk_verts, &Speedy_walk_graph, &Speedy_walk_types);
		break;
	case "Endeavour":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Endeavour_walk_count, &Endeavour_walk_verts, &Endeavour_walk_graph, &Endeavour_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Endeavour", Endeavour_walk_count, &Endeavour_walk_verts, &Endeavour_walk_graph, &Endeavour_walk_types);
		break;
	case "SanFelipe":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,SanFelipe_walk_count, &SanFelipe_walk_verts, &SanFelipe_walk_graph, &SanFelipe_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "SanFelipe", SanFelipe_walk_count, &SanFelipe_walk_verts, &SanFelipe_walk_graph, &SanFelipe_walk_types);
		break;
	case "CaravelR":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,CaravelR_walk_count, &CaravelR_walk_verts, &CaravelR_walk_graph, &CaravelR_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "CaravelR", CaravelR_walk_count, &CaravelR_walk_verts, &CaravelR_walk_graph, &CaravelR_walk_types);
		break;
	// pgargon <--
	// Jack Harrison -->
	case "RN_Surprise":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,RN_Surprise_walk_count, &RN_Surprise_walk_verts, &RN_Surprise_walk_graph, &RN_Surprise_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "RN_Surprise", RN_Surprise_walk_count, &RN_Surprise_walk_verts, &RN_Surprise_walk_graph, &RN_Surprise_walk_types);
        break;
	// Jack Harrison <--
	// craiggo -->
	case "HMS_Surprise":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,HMS_Surprise_walk_count, &HMS_Surprise_walk_verts, &HMS_Surprise_walk_graph, &HMS_Surprise_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "HMS_Surprise", HMS_Surprise_walk_count, &HMS_Surprise_walk_verts, &HMS_Surprise_walk_graph, &HMS_Surprise_walk_types);
		break;
	case "Poseidon":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Poseidon_walk_count, &Poseidon_walk_verts, &Poseidon_walk_graph, &Poseidon_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Poseidon", Poseidon_walk_count, &Poseidon_walk_verts, &Poseidon_walk_graph, &Poseidon_walk_types);
		break;	
	case "BattleGalleon":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,BattleGalleon_walk_count, &BattleGalleon_walk_verts, &BattleGalleon_walk_graph, &BattleGalleon_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "BattleGalleon", BattleGalleon_walk_count, &BattleGalleon_walk_verts, &BattleGalleon_walk_graph, &BattleGalleon_walk_types);
		break;
	case "Intrepide":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Intrepide_walk_count, &Intrepide_walk_verts, &Intrepide_walk_graph, &Intrepide_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Intrepide", Intrepide_walk_count, &Intrepide_walk_verts, &Intrepide_walk_graph, &Intrepide_walk_types);
		break;
	case "QueenAnnesRevenge":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,QueenAnnesRevenge_walk_count, &QueenAnnesRevenge_walk_verts, &QueenAnnesRevenge_walk_graph, &QueenAnnesRevenge_walk_types);
		//SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "QueenAnnesRevenge", QueenAnnesRevenge_walk_count, &QueenAnnesRevenge_walk_verts, &QueenAnnesRevenge_walk_graph, &QueenAnnesRevenge_walk_types);
		break;
	//craiggo <--
	//Armada -->
	case "SteamFrigate":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,SteamFrigate_walk_count, &SteamFrigate_walk_verts, &SteamFrigate_walk_graph, &SteamFrigate_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "SteamFrigate", SteamFrigate_walk_count, &SteamFrigate_walk_verts, &SteamFrigate_walk_graph, &SteamFrigate_walk_types);
		break;
	case "Interceptor":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Interceptor_walk_count, &Interceptor_walk_verts, &Interceptor_walk_graph, &Interceptor_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Interceptor", Interceptor_walk_count, &Interceptor_walk_verts, &Interceptor_walk_graph, &Interceptor_walk_types);
		break;
	case "Centurion":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Centurion_walk_count, &Centurion_walk_verts, &Centurion_walk_graph, &Centurion_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Centurion", Centurion_walk_count,&Centurion_walk_verts, &Centurion_walk_graph, &Centurion_walk_types);
        break;	
	case "Aurora":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Aurora_walk_count, &Aurora_walk_verts, &Aurora_walk_graph, &Aurora_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Aurora", Aurora_walk_count,&Aurora_walk_verts, &Aurora_walk_graph, &Aurora_walk_types);
        break;			
	case "FastMerchantman":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,FastMerchantman_walk_count, &FastMerchantman_walk_verts, &FastMerchantman_walk_graph, &FastMerchantman_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "FastMerchantman", FastMerchantman_walk_count,&FastMerchantman_walk_verts, &FastMerchantman_walk_graph, &FastMerchantman_walk_types);
        break;
	//Armada <--
	//Hylie Pistof -->
	case "Revenge":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Revenge_walk_count, &Revenge_walk_verts, &Revenge_walk_graph, &Revenge_walk_types);
		//SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Revenge", Revenge_walk_count, &Revenge_walk_verts, &Revenge_walk_graph, &Revenge_walk_types);
		break;
	case "Lyon":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Lyon_walk_count, &Lyon_walk_verts, &Lyon_walk_graph, &Lyon_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Lyon", Lyon_walk_count, &Lyon_walk_verts, &Lyon_walk_graph, &Lyon_walk_types);
        break;
	case "Neptunus":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Neptunus_walk_count, &Neptunus_walk_verts, &Neptunus_walk_graph, &Neptunus_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Neptunus", Neptunus_walk_count, &Neptunus_walk_verts, &Neptunus_walk_graph, &Neptunus_walk_types);
        break;
	case "NL_Pinnace":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,NL_Pinnace_walk_count, &NL_Pinnace_walk_verts, &NL_Pinnace_walk_graph, &NL_Pinnace_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "NL_Pinnace", NL_Pinnace_walk_count, &NL_Pinnace_walk_verts, &NL_Pinnace_walk_graph, &NL_Pinnace_walk_types);
        break;
	case "DutchPinnace":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,DutchPinnace_walk_count, &DutchPinnace_walk_verts, &DutchPinnace_walk_graph, &DutchPinnace_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "DutchPinnace", DutchPinnace_walk_count, &DutchPinnace_walk_verts, &DutchPinnace_walk_graph, &DutchPinnace_walk_types);
        break;
	case "Derfflinger":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Derfflinger_walk_count, &Derfflinger_walk_verts, &Derfflinger_walk_graph, &Derfflinger_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Derfflinger", Derfflinger_walk_count, &Derfflinger_walk_verts, &Derfflinger_walk_graph, &Derfflinger_walk_types);
        break;
	case "FWzP":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,FWzP_walk_count, &FWzP_walk_verts, &FWzP_walk_graph, &FWzP_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "FWzP", FWzP_walk_count, &FWzP_walk_verts, &FWzP_walk_graph, &FWzP_walk_types);
        break;
	case "Unicorn":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Unicorn_walk_count, &Unicorn_walk_verts, &Unicorn_walk_graph, &Unicorn_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Unicorn", Unicorn_walk_count, &Unicorn_walk_verts, &Unicorn_walk_graph, &Unicorn_walk_types);
        break;
	case "Dilligente":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Dilligente_walk_count, &Dilligente_walk_verts, &Dilligente_walk_graph, &Dilligente_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Dilligente", Dilligente_walk_count, &Dilligente_walk_verts, &Dilligente_walk_graph, &Dilligente_walk_types);
        break;
	case "RaaFrigate":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,RaaFrigate_walk_count, &RaaFrigate_walk_verts, &RaaFrigate_walk_graph, &RaaFrigate_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "RaaFrigate", RaaFrigate_walk_count,&RaaFrigate_walk_verts, &RaaFrigate_walk_graph, &RaaFrigate_walk_types);
        break;
	case "Postillionen":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Postillionen_walk_count, &Postillionen_walk_verts, &Postillionen_walk_graph, &Postillionen_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Postillionen", Postillionen_walk_count,&Postillionen_walk_verts, &Postillionen_walk_graph, &Postillionen_walk_types);
        break;
	//Hylie Pistof <--
	//Iron Roger Flint -->
	case "Empress":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Empress_walk_count, &Empress_walk_verts, &Empress_walk_graph, &Empress_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Empress", Empress_walk_count,&Empress_walk_verts, &Empress_walk_graph, &Empress_walk_types);
        break;
	//Iron Roger Flint <--
	//Captain Armstrong -->
	case "PrinceNeufchatel":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,PrinceNeufchatel_walk_count, &PrinceNeufchatel_walk_verts, &PrinceNeufchatel_walk_graph, &PrinceNeufchatel_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "PrinceNeufchatel", PrinceNeufchatel_walk_count,&PrinceNeufchatel_walk_verts, &PrinceNeufchatel_walk_graph, &PrinceNeufchatel_walk_types);
        break;
	case "Volage":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Volage_walk_count, &Volage_walk_verts, &Volage_walk_graph, &Volage_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Volage", Volage_walk_count,&Volage_walk_verts, &Volage_walk_graph, &Volage_walk_types);
        break;
	case "US_Essex":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,US_Essex_walk_count, &US_Essex_walk_verts, &US_Essex_walk_graph, &US_Essex_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "US_Essex", US_Essex_walk_count,&US_Essex_walk_verts, &US_Essex_walk_graph, &US_Essex_walk_types);
        break;
	//Captain Armstrong <--
	//Rider88 -->
	case "XebecVML":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,XebecVML_walk_count, &XebecVML_walk_verts, &XebecVML_walk_graph, &XebecVML_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "XebecVML", XebecVML_walk_count,&XebecVML_walk_verts, &XebecVML_walk_graph, &XebecVML_walk_types);
        break;
	//Rider88 <--
	//De Zeeroovers -->
	case "Polacca":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,Polacca_walk_count, &Polacca_walk_verts, &Polacca_walk_graph, &Polacca_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "Polacca", Polacca_walk_count,&Polacca_walk_verts, &Polacca_walk_graph, &Polacca_walk_types);
        break;
	case "PinnaceMerchant":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,PinnaceMerchant_walk_count, &PinnaceMerchant_walk_verts, &PinnaceMerchant_walk_graph, &PinnaceMerchant_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "PinnaceMerchant", PinnaceMerchant_walk_count,&PinnaceMerchant_walk_verts, &PinnaceMerchant_walk_graph, &PinnaceMerchant_walk_types);
        break;
	//De Zeeroovers <--
	case "PinnaceMedium":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,PinnaceMedium_walk_count, &PinnaceMedium_walk_verts, &PinnaceMedium_walk_graph, &PinnaceMedium_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "PinnaceMedium", PinnaceMedium_walk_count,&PinnaceMedium_walk_verts, &PinnaceMedium_walk_graph, &PinnaceMedium_walk_types);
        break;
	//Hylie Pistof <--
	//JRH -->
	case "GoldenHind":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,GoldenHind_walk_count, &GoldenHind_walk_verts, &GoldenHind_walk_graph, &GoldenHind_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "GoldenHind", GoldenHind_walk_count,&GoldenHind_walk_verts, &GoldenHind_walk_graph, &GoldenHind_walk_types);
        break;
	//JRH <--
	//HP -->
	case "CastelF":
		SendMessage(PeopleOnShip,"lileee",AI_MESSAGE_ADD_SHIP,ship,CastelF_walk_count, &CastelF_walk_verts, &CastelF_walk_graph, &CastelF_walk_types);
        //SendMessage(WALK_TOOL,"lslee", AI_MESSAGE_ADD_SHIP, "CastelF", CastelF_walk_count,&CastelF_walk_verts, &CastelF_walk_graph, &CastelF_walk_types);
        break;
	//HP <--
	}
}
