

//--------------------------------------------------------------------------------------
//Генерация энкоунтеров
//--------------------------------------------------------------------------------------

//Частота штормов в секунду
#define WDM_STORM_RATE			0.002
//Частота торговцев в секунду
#define WDM_MERCHANTS_RATE		0.3 // NK upped to 0.3, was 0.2. I will now use them as also warfleets (with simple orders, not chase-player orders)  05-06-27
//Частота воюищих кораблей в секунду
#define WDM_WARRING_RATE		0.04 // NK upped slightly. We _are_ at war, folks. Was 0.03
//Частота нападающих кораблей в секунду
#define WDM_FOLLOW_RATE			0.04 // was 0.06; because of using merchant as also warfleet

#define ENC_NONFOLLOW_WARFLEET_CHANCE 0.25 // chance for merchant (i.e. nonfollow) enc to be warfleet minding its own business...a chance for non-hostile warfleets.
#define WARRING_CHANCE_TRADE		0.5 // chance for a side in the warring enc to not be type war.

//--------------------------------------------------------------------------------------







float wdmTimeOfLastStorm = 0.0;
float wdmTimeOfLastMerchant = 0.0;
float wdmTimeOfLastWarring = 0.0;
float wdmTimeOfLastFollow = 0.0;



void wdmReset()
{
	wdmTimeOfLastStorm = 0.0;
	wdmTimeOfLastMerchant = 0.0;
	wdmTimeOfLastWarring = 0.0;
	wdmTimeOfLastFollow = 0.0;
}

//Storm
void wdmStormGen(float dltTime, float playerShipX, float playerShipZ, float playerShipAY)
{
	ref mc = GetMainCharacter();
	bool encoff = false;
	if(GetAttribute(mc,"worldmapencountersoff") == 1)	return;
	if(CheckAttribute(mc,"ship.SubmergeDutchman"))		return;	// PB: No encounters or storms while you are submerged
	int numStorms = wdmGetNumberStorms();
	if(numStorms < 1)
	{
		wdmTimeOfLastStorm = wdmTimeOfLastStorm + dltTime*WDM_STORM_RATE*1000.0;
		if(rand(1001) < wdmTimeOfLastStorm)
		{
			wdmCreateStorm();
			wdmTimeOfLastStorm = 0.0;
		}
	}else{
		wdmTimeOfLastStorm = 0.0;
	}
}

//Random ships
void wdmShipEncounter(float dltTime, float playerShipX, float playerShipZ, float playerShipAY)
{
	int numShips = wdmGetNumberShipEncounters();
	if(numShips < 5)
	{
		rand(1001);
		//Вероятности появления
		wdmTimeOfLastMerchant = wdmTimeOfLastMerchant + dltTime*WDM_MERCHANTS_RATE*1000.0;
		wdmTimeOfLastWarring = wdmTimeOfLastWarring + dltTime*WDM_WARRING_RATE*1000.0;
		wdmTimeOfLastFollow = wdmTimeOfLastFollow + dltTime*WDM_FOLLOW_RATE*1000.0;
		//Вероятность от количества созданных
		float nump = 1.0 - numShips*0.15;
		//Идентификаторы энкоунтеров
		int i1 = -1;
		int i2 = -1;
		//Выбираем
		ref mc = GetMainCharacter();
		bool encoff = false;
		if(GetAttribute(mc,"worldmapencountersoff") == 1)	return;
		if(rand(1001) + 1 < wdmTimeOfLastMerchant)
		{
			wdmTimeOfLastMerchant = 0.0;
			if(GenerateMapEncounter(WDM_ETYPE_MERCHANT, wdmGetCurrentIsland(), &i1, &i2) == false) return;
//NK -->
			wdmCreateMerchantShip(i1, "", rand(50) - 50);
// NK <--
		}else{
			if(encoff == false)
			{
				if(rand(1001) + 1 < wdmTimeOfLastWarring)
				{
					wdmTimeOfLastWarring = 0.0;
					if(GenerateMapEncounter(WDM_ETYPE_WARRING, wdmGetCurrentIsland(), &i1, &i2) == false) return;
					wdmCreateWarringShips(i1, i2);
				}else{
					if(rand(1001) + 1 < wdmTimeOfLastFollow)
					{
						wdmTimeOfLastFollow = 0.0;
						if(GenerateMapEncounter(WDM_ETYPE_FOLLOW, wdmGetCurrentIsland(), &i1, &i2) == false) return;
						wdmCreateFollowShip(i1, rand(50) - 20);
					}
				}
			}
		}
	}else{
		wdmTimeOfLastMerchant = 0.0;
		wdmTimeOfLastWarring = 0.0;
		wdmTimeOfLastFollow = 0.0;
	}
}


string wdmGetCurrentIsland()
{
	if(wdmCurrentIsland != WDM_NONE_ISLAND)
	{
		return wdmCurrentIsland;
	}
	return "";
}


//Quest ships
void wdmQuestShipEncounter(float dltTime, float playerShipX, float playerShipZ, float playerShipAY)
{


}

//true if storm with tornado
bool wdmDisableTornadoGen = true;
bool wdmTornadoGenerator()
{
	if(wdmDisableTornadoGen) return false;
	if(wdmCurrentIsland !=	WDM_NONE_ISLAND) return false;
	int r = rand(1000);
	if(r == 0) return false;
	return r < 450;
}


