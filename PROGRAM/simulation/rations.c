
int GetFleetLivingCrew(ref leader) {
	int crew_quantity = GetSquadronTotalCrewQuantity(leader);
	// PB: Cursed Coins -->
	if (CheckCharacterItem(leader,"cursedcoin") ) {
		int cursed_count_count = GetCursedCoinCount();
		crew_quantity -= cursed_count_count;
	}
	// PB: Cursed Coins <--
	crew_quantity += GetUnremovableCrewQuantity(leader);
	if (crew_quantity < 0) {
		crew_quantity = 0;
	}
	return crew_quantity;
}

float GetFleetFoodConsumption(ref leader) {
	int crew_quantity = GetFleetLivingCrew(leader);

	float consumption_rate = 1.0;

	if (CheckAttribute(leader, "crewStatus.foodRations") ) {
		consumption_rate /= stf(leader.crewStatus.foodRations);
	}

	if (CheckPerkForGroup(leader, "Cooking") ) {
		consumption_rate *= 0.9;
	}

	return makefloat(crew_quantity) * consumption_rate * FOOD_PER_CREW;
}

float GetFleetRumConsumption(ref leader) {
	int crew_quantity = GetFleetLivingCrew(leader);

	float consumption_rate = 0.5;

	if (CheckAttribute(leader, "crewStatus.rumRations") ) {
		consumption_rate = 1.0 / stf(leader.crewStatus.rumRations);
	}

	return makefloat(crew_quantity) * consumption_rate * FOOD_PER_CREW;
}

float GetFleetFoodAvailable(ref leader) {
	int food_quantity = GetSquadronGoods(leader, GOOD_WHEAT);

	float consumed_food = 0;
	if (CheckAttribute(leader, "crewStatus.foodUsed") ) {
		consumed_food += stf(leader.crewStatus.foodUsed);
	}

	return makefloat(food_quantity) - consumed_food;
}

float GetFleetRumAvailable(ref leader) {
	int rum_quantity = GetSquadronGoods(leader, GOOD_RUM);

	float consumed_rum = 0;
	if (CheckAttribute(leader, "crewStatus.rumUsed") ) {
		consumed_rum += stf(leader.crewStatus.rumUsed);
	}

	return makefloat(rum_quantity) - consumed_rum;
}

float CalculateFoodRations(ref character)
{
	float food_quantity = GetFleetFoodAvailable(character);
	float daily_food_consumed = GetFleetFoodConsumption(character);

	if (daily_food_consumed <= 0) {
		return -1.0;
	}

	return food_quantity/daily_food_consumed;
}

float CalculateRumRations(ref character)
{
	float rum_quantity = GetFleetRumAvailable(character);
	float daily_rum_consumed = GetFleetRumConsumption(character);

	if (daily_rum_consumed <= 0) {
		return -1.0;
	}

	return rum_quantity/daily_rum_consumed;
}
