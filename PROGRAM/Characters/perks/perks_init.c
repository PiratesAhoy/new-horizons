void extrnInitPerks()
{
	//	Combat Skills Group
	//==========================================================
	ChrPerksList.list.BasicDefence.descr = "perkBasicDefence";
	ChrPerksList.list.BasicDefence.cost = 1; // Levis
	ChrPerksList.list.BasicDefence.type = PERK_TYPE_COMBAT; //Levis

	ChrPerksList.list.AdvancedDefence.descr = "perkAdvancedDefence";
	ChrPerksList.list.AdvancedDefence.condition.BasicDefence = true;
	ChrPerksList.list.AdvancedDefence.locked = true; //Levis
	ChrPerksList.list.AdvancedDefence.cost = 2; // Levis
	ChrPerksList.list.AdvancedDefence.type = PERK_TYPE_COMBAT; //Levis

	// El Rapido -->
	ChrPerksList.list.Toughness.descr = "perkToughness";
	ChrPerksList.list.Toughness.condition.AdvancedDefence = true;
	ChrPerksList.list.Toughness.locked = true; //Levis
	ChrPerksList.list.Toughness.cost = 2; // Levis
	ChrPerksList.list.Toughness.type = PERK_TYPE_COMBAT; //Levis
	// El Rapido <--

	ChrPerksList.list.CriticalHit.descr = "perkCriticalHit";
	ChrPerksList.list.CriticalHit.cost = 2; // Levis
	ChrPerksList.list.CriticalHit.type = PERK_TYPE_COMBAT; //Levis

	ChrPerksList.list.SwordplayProfessional.descr = "perkSwordplayProfessional";
	ChrPerksList.list.SwordplayProfessional.condition.AdvancedDefence = true;
	ChrPerksList.list.SwordplayProfessional.condition.CriticalHit = true;
	ChrPerksList.list.SwordplayProfessional.cost = 2; // Levis
	ChrPerksList.list.SwordplayProfessional.locked = true; //Levis
	ChrPerksList.list.SwordplayProfessional.type = PERK_TYPE_COMBAT; //Levis

	ChrPerksList.list.Rush.descr = "perkRush";
	ChrPerksList.list.Rush.TimeDuration = 30;
	ChrPerksList.list.Rush.disable.iRealismMode = 1; //Levis
	ChrPerksList.list.Rush.disable.REALISTIC_ABILITIES = 1; //Levis
	ChrPerksList.list.Rush.cost = 2; // Levis
	ChrPerksList.list.Rush.type = PERK_TYPE_COMBAT; //Levis

	ChrPerksList.list.Gunman.descr = "perkGunman";
	ChrPerksList.list.Gunman.cost = 1; // Levis
	ChrPerksList.list.Gunman.type = PERK_TYPE_COMBAT; //Levis

	ChrPerksList.list.ImproveAiming.descr = "perkImproveAiming";
	ChrPerksList.list.ImproveAiming.condition.Gunman = true;
	ChrPerksList.list.ImproveAiming.cost = 3; // Levis
	ChrPerksList.list.ImproveAiming.disable.iRealismMode = 2; //Levis
	ChrPerksList.list.ImproveAiming.disable.REALISTIC_ABILITIES = 2; //Levis
	ChrPerksList.list.ImproveAiming.locked = true; //Levis
	ChrPerksList.list.ImproveAiming.type = PERK_TYPE_COMBAT; //Levis
	
	ChrPerksList.list.GunProfessional.descr = "perkGunProfessional";
	ChrPerksList.list.GunProfessional.condition.Gunman = true;
	ChrPerksList.list.GunProfessional.rank = 15;
	ChrPerksList.list.GunProfessional.cost = 2; // Levis
	ChrPerksList.list.GunProfessional.locked = true; //Levis
	ChrPerksList.list.GunProfessional.type = PERK_TYPE_COMBAT; //Levis

    //JRH BB6 ->
	ChrPerksList.list.GunFighter.descr = "perkGunFighter";
	ChrPerksList.list.GunFighter.condition.GunProfessional = true;
	ChrPerksList.list.GunFighter.condition.BasicDefence = true;
	ChrPerksList.list.GunFighter.condition.IronWill = true;
	ChrPerksList.list.GunFighter.disable.StorylineVar = "GUNFIGHTER_PERK";
	ChrPerksList.list.GunFighter.cost = 1; // Levis
	ChrPerksList.list.GunFighter.type = PERK_TYPE_COMBAT; //Levis
    //<-- JRH

	// Party Abilities
	//==========================================================================
	ChrPerksList.list.ImprovePotions.descr = "perkImprovePotions"; //Levis
	ChrPerksList.list.ImprovePotions.rank = 15;
	ChrPerksList.list.ImprovePotions.cost = 3; // Levis
	ChrPerksList.list.ImprovePotions.locked = true; //Levis
	ChrPerksList.list.ImprovePotions.type = PERK_TYPE_PARTY; //Levis

	ChrPerksList.list.DefendPoison.descr = "perkDefendPoison"; //Levis
	ChrPerksList.list.DefendPoison.rank = 10;
	ChrPerksList.list.DefendPoison.cost = 3; // Levis
	ChrPerksList.list.DefendPoison.type = PERK_TYPE_PARTY; //Levis

	// Ship Control Abilities
	//==========================================================================
	ChrPerksList.list.ShipTurnRateUp.descr = "perkShipTurnRateUp";
	ChrPerksList.list.ShipTurnRateUp.disable.iRealismMode = 2; //Levis
	ChrPerksList.list.ShipTurnRateUp.disable.REALISTIC_ABILITIES = 2; //Levis
	ChrPerksList.list.ShipTurnRateUp.cost = 1; // Levis
	ChrPerksList.list.ShipTurnRateUp.type = PERK_TYPE_SAILING; //Levis

	ChrPerksList.list.ShipSpeedUp.descr = "perkShipSpeedUp";
	ChrPerksList.list.ShipSpeedUp.disable.iRealismMode = 2; //Levis
	ChrPerksList.list.ShipSpeedUp.disable.REALISTIC_ABILITIES = 2; //Levis
	ChrPerksList.list.ShipSpeedUp.cost = 2; // Levis
	ChrPerksList.list.ShipSpeedUp.type = PERK_TYPE_SAILING; //Levis

	ChrPerksList.list.Turn180.descr = "perkTurn180";
	ChrPerksList.list.Turn180.condition.ShipTurnRateUp = true;
//	ChrPerksList.list.Turn180.condition.ShipSpeedUp = true; //Armada: Turn180 is now 'club hauling', so no need for this perk.
	ChrPerksList.list.Turn180.TimeDelay = 180;
	ChrPerksList.list.Turn180.disable.iRealismMode = 2; //Levis
	ChrPerksList.list.Turn180.disable.REALISTIC_ABILITIES = 2; //Levis
	ChrPerksList.list.Turn180.cost = 2; // Levis
	ChrPerksList.list.Turn180.locked = true; //Levis
	ChrPerksList.list.Turn180.type = PERK_TYPE_SAILING; //Levis

	ChrPerksList.list.SandbankManeuver.descr = "perkSandbankManeuver";
//	ChrPerksList.list.SandbankManeuver.condition.Turn180 = true;
	ChrPerksList.list.SandbankManeuver.condition.ShipTurnRateUp = true;
	ChrPerksList.list.SandbankManeuver.condition.ShipSpeedUp = true;
	ChrPerksList.list.SandbankManeuver.TimeDuration = 60;
	ChrPerksList.list.SandbankManeuver.disable.iRealismMode = 2; //Levis
	ChrPerksList.list.SandbankManeuver.disable.REALISTIC_ABILITIES = 2; //Levis
	ChrPerksList.list.SandbankManeuver.cost = 2; // Levis
	ChrPerksList.list.SandbankManeuver.type = PERK_TYPE_SAILING; //Levis

	ChrPerksList.list.StormProfessional.descr = "perkStormProfessional";
//	ChrPerksList.list.StormProfessional.condition.LightRepair = true; // KK		edited by El Rapido
	ChrPerksList.list.StormProfessional.condition.ShipTurnRateUp = true; // KK		added by El Rapido
	ChrPerksList.list.StormProfessional.condition.ShipSpeedUp = true; // KK
	ChrPerksList.list.StormProfessional.rank = 20; // KK
	ChrPerksList.list.StormProfessional.disable.iRealismMode = 2; //Levis
	ChrPerksList.list.StormProfessional.disable.REALISTIC_ABILITIES = 2; //Levis
	ChrPerksList.list.StormProfessional.cost = 2; // Levis
	ChrPerksList.list.StormProfessional.type = PERK_TYPE_SAILING; //Levis

	ChrPerksList.list.SailingProfessional.descr = "perkSailingProfessional";
	ChrPerksList.list.SailingProfessional.condition.SandbankManeuver = true;
	ChrPerksList.list.SailingProfessional.condition.StormProfessional = true;
	ChrPerksList.list.SailingProfessional.disable.iRealismMode = 2; //Levis
	ChrPerksList.list.SailingProfessional.disable.REALISTIC_ABILITIES = 2; //Levis
	ChrPerksList.list.SailingProfessional.cost = 3; // Levis
	ChrPerksList.list.SailingProfessional.type = PERK_TYPE_SAILING; //Levis

	// Ship Combat Abilities
	//==========================================================================
	ChrPerksList.list.BasicBattleState.descr = "perkBasicBattleState";
	ChrPerksList.list.BasicBattleState.cost = 1; // Levis
	ChrPerksList.list.BasicBattleState.type = PERK_TYPE_SEACOMBAT; //Levis

	ChrPerksList.list.AdvancedBattleState.descr = "perkAdvancedBattleState";
	ChrPerksList.list.AdvancedBattleState.condition.BasicBattleState = true;
	ChrPerksList.list.AdvancedBattleState.Rank = 10; // KK
	ChrPerksList.list.AdvancedBattleState.disable.iRealismMode = 2; //Levis
	ChrPerksList.list.AdvancedBattleState.disable.REALISTIC_ABILITIES = 2; //Levis
	ChrPerksList.list.AdvancedBattleState.cost = 3; // Levis set from 2 to 3 El Rapido
	ChrPerksList.list.AdvancedBattleState.locked = true; //Levis
	ChrPerksList.list.AdvancedBattleState.type = PERK_TYPE_SEADEFENCE; //Levis

	ChrPerksList.list.ShipDefenceProfessional.descr = "perkShipDefenceProfessional";
	ChrPerksList.list.ShipDefenceProfessional.condition.AdvancedBattleState = true;
	ChrPerksList.list.ShipDefenceProfessional.rank = 15; // KK
	ChrPerksList.list.ShipDefenceProfessional.disable.iRealismMode = 2; //Levis
	ChrPerksList.list.ShipDefenceProfessional.disable.REALISTIC_ABILITIES = 2; //Levis
	ChrPerksList.list.ShipDefenceProfessional.cost = 4; // Levis set from 3 to 4 El Rapido
	ChrPerksList.list.ShipDefenceProfessional.type = PERK_TYPE_SEADEFENCE; //Levis

	ChrPerksList.list.FastReload.descr = "perkFastReload";
	ChrPerksList.list.FastReload.cost = 2; // Levis
	ChrPerksList.list.FastReload.type = PERK_TYPE_SEACOMBAT; //Levis

	ChrPerksList.list.ImmediateReload.descr = "perkImmediateReload";
	ChrPerksList.list.ImmediateReload.condition.FastReload = true;
	ChrPerksList.list.ImmediateReload.TimeDelay = 300;
	ChrPerksList.list.ImmediateReload.disable.iRealismMode = 1; //Levis
	ChrPerksList.list.ImmediateReload.disable.REALISTIC_ABILITIES = 1; //Levis
	ChrPerksList.list.ImmediateReload.cost = 2; // Levis
	ChrPerksList.list.ImmediateReload.locked = true; //Levis
	ChrPerksList.list.ImmediateReload.type = PERK_TYPE_SEACOMBAT; //Levis

	ChrPerksList.list.HullDamageUp.descr = "perkHullDamageUp";
	ChrPerksList.list.HullDamageUp.disable.iRealismMode = 2; //Levis
	ChrPerksList.list.HullDamageUp.disable.REALISTIC_ABILITIES = 2; //Levis
	ChrPerksList.list.HullDamageUp.cost = 2; // Levis
	ChrPerksList.list.HullDamageUp.type = PERK_TYPE_SEACOMBAT; //Levis

	ChrPerksList.list.SailsDamageUp.descr = "perkSailsDamageUp";
	ChrPerksList.list.SailsDamageUp.disable.iRealismMode = 2; //Levis
	ChrPerksList.list.SailsDamageUp.disable.REALISTIC_ABILITIES = 2; //Levis
	ChrPerksList.list.SailsDamageUp.cost = 2; // Levis
	ChrPerksList.list.SailsDamageUp.type = PERK_TYPE_SEACOMBAT; //Levis

	ChrPerksList.list.CrewDamageUp.descr = "perkCrewDamageUp";
	ChrPerksList.list.CrewDamageUp.disable.iRealismMode = 2; //Levis
	ChrPerksList.list.CrewDamageUp.disable.REALISTIC_ABILITIES = 2; //Levis
	ChrPerksList.list.CrewDamageUp.cost = 2; // Levis
	ChrPerksList.list.CrewDamageUp.type = PERK_TYPE_SEADEFENCE; //Levis

	ChrPerksList.list.CriticalShoot.descr = "perkCriticalShoot";
	ChrPerksList.list.CriticalShoot.condition.HullDamageUp = true;
	ChrPerksList.list.CriticalShoot.condition.SailsDamageUp = true;
	ChrPerksList.list.CriticalShoot.condition.CrewDamageUp = true;
	ChrPerksList.list.CriticalShoot.disable.iRealismMode = 2; //Levis
	ChrPerksList.list.CriticalShoot.disable.REALISTIC_ABILITIES = 2; //Levis
	ChrPerksList.list.CriticalShoot.cost = 1; // Levis
	ChrPerksList.list.CriticalShoot.type = PERK_TYPE_SEACOMBAT; //Levis

	ChrPerksList.list.LongRangeShoot.descr = "perkLongRangeShoot";
	ChrPerksList.list.LongRangeShoot.disable.iRealismMode = 2; //Levis
	ChrPerksList.list.LongRangeShoot.disable.REALISTIC_ABILITIES = 2; //Levis
	ChrPerksList.list.LongRangeShoot.cost = 1; // Levis
	ChrPerksList.list.LongRangeShoot.type = PERK_TYPE_SEACOMBAT; //Levis

	ChrPerksList.list.CannonProfessional.descr = "perkCannonProfessional";
	ChrPerksList.list.CannonProfessional.condition.FastReload = true;
	ChrPerksList.list.CannonProfessional.condition.CriticalShoot = true;
	ChrPerksList.list.CannonProfessional.condition.LongRangeShoot = true;
	ChrPerksList.list.CannonProfessional.disable.iRealismMode = 2; //Levis
	ChrPerksList.list.CannonProfessional.disable.REALISTIC_ABILITIES = 2; //Levis
	ChrPerksList.list.CannonProfessional.cost = 2; // Levis
	ChrPerksList.list.CannonProfessional.locked = true; //Levis
	ChrPerksList.list.CannonProfessional.type = PERK_TYPE_SEACOMBAT; //Levis

	ChrPerksList.list.LongRangeGrappling.descr = "perkLongRangeGrappling";
	ChrPerksList.list.LongRangeGrappling.disable.iRealismMode = 2; //Levis
	ChrPerksList.list.LongRangeGrappling.disable.REALISTIC_ABILITIES = 2; //Levis
	ChrPerksList.list.LongRangeGrappling.cost = 3; // Levis
	ChrPerksList.list.LongRangeGrappling.locked = true; //Levis
	ChrPerksList.list.LongRangeGrappling.type = PERK_TYPE_BOARDING; //Levis

	// GreatZen -->
	ChrPerksList.list.MusketsShoot.descr = "perkMusketsShoot";
	ChrPerksList.list.MusketsShoot.condition.GunProfessional = true;
	ChrPerksList.list.MusketsShoot.condition.LongRangeGrappling = true;
	ChrPerksList.list.MusketsShoot.cost = 1; // Levis
	ChrPerksList.list.MusketsShoot.type = PERK_TYPE_BOARDING; //Levis
	// GreatZen <--

	ChrPerksList.list.GrapplingProfessional.descr = "perkGrapplingProfessional";
	ChrPerksList.list.GrapplingProfessional.condition.LongRangeGrappling = true;
	ChrPerksList.list.GrapplingProfessional.disable.iRealismMode = 2; //Levis
	ChrPerksList.list.GrapplingProfessional.disable.REALISTIC_ABILITIES = 2; //Levis
	ChrPerksList.list.GrapplingProfessional.cost = 3; // Levis								set from 2 to 3 by El Rapido
	ChrPerksList.list.GrapplingProfessional.type = PERK_TYPE_BOARDING; //Levis

	ChrPerksList.list.InstantBoarding.descr = "perkInstantBoarding";
	ChrPerksList.list.InstantBoarding.condition.SwordplayProfessional = true;
//  ChrPerksList.list.InstantBoarding.condition.SailingProfessional = true;				edited by El Rapido
	ChrPerksList.list.InstantBoarding.condition.GrapplingProfessional = true;
	ChrPerksList.list.InstantBoarding.TimeDelay = -1;
	ChrPerksList.list.InstantBoarding.disable.iRealismMode = 1; //Levis
	ChrPerksList.list.InstantBoarding.disable.REALISTIC_ABILITIES = 1; //Levis
	ChrPerksList.list.InstantBoarding.cost = 3; // Levis
	ChrPerksList.list.InstantBoarding.type = PERK_TYPE_BOARDING; //Levis

	// Miscellaneous Abilities
	//==========================================================================
	ChrPerksList.list.Troopers.descr = "perkTroopers";  // GreatZen
	//ChrPerksList.list.Troopers.condition.LongRangeGrappling = true; // PB: To prevent sacking fortless towns in the early game //Changed by Levis
	ChrPerksList.list.Troopers.locked = true; // Levis
	ChrPerksList.list.Troopers.rank = 20; // KK
	ChrPerksList.list.Troopers.cost = 4; // Levis
	ChrPerksList.list.Troopers.type = PERK_TYPE_MISC; //Levis

	ChrPerksList.list.LightRepair.descr = "perkLightRepair";
	ChrPerksList.list.LightRepair.TimeDelay = 60;
	ChrPerksList.list.LightRepair.cost = 3; // Levis										edited by El Rapido - set from 1 to 3, so that Carpenters actually have a job
	ChrPerksList.list.LightRepair.type = PERK_TYPE_REPAIR; //Levis
	
	ChrPerksList.list.InstantRepair.descr = "perkInstantRepair";
	ChrPerksList.list.InstantRepair.condition.LightRepair = true;
	ChrPerksList.list.InstantRepair.disable.iRealismMode = 2; //Aconcagua
	ChrPerksList.list.InstantRepair.disable.REALISTIC_ABILITIES = 2; //Levis
	ChrPerksList.list.InstantRepair.cost = 4; // Levis										edited by El Rapido - set from 3 to 4
	ChrPerksList.list.InstantRepair.locked = true; // Levis
	ChrPerksList.list.InstantRepair.type = PERK_TYPE_REPAIR; //Levis

	ChrPerksList.list.Cooking.descr = "perkCooking"; //Levis
	ChrPerksList.list.Cooking.cost = 2; // Levis
	ChrPerksList.list.Cooking.type = PERK_TYPE_PARTY; //Levis

	//Levis -->
	ChrPerksList.list.HighStakes.descr = "perkHighStakes";
	ChrPerksList.list.HighStakes.rank = 8;
	ChrPerksList.list.HighStakes.cost = 1;
	ChrPerksList.list.HighStakes.type = PERK_TYPE_DARING; //Levis
	
	ChrPerksList.list.Disguiser.descr = "perkDisguiser";
	ChrPerksList.list.Disguiser.cost = 2;
	ChrPerksList.list.Disguiser.type = PERK_TYPE_DARING; //Levis
	
	ChrPerksList.list.ImproveSmuggling.descr = "perkImproveSmuggling";
	ChrPerksList.list.ImproveSmuggling.cost = 1;
	ChrPerksList.list.ImproveSmuggling.locked = true;
	ChrPerksList.list.ImproveSmuggling.type = PERK_TYPE_DARING; //Levis
	
	ChrPerksList.list.AdvanceSmuggling.descr = "perkAdvanceSmuggling";
	ChrPerksList.list.AdvanceSmuggling.condition.ImproveSmuggling = true;
	ChrPerksList.list.AdvanceSmuggling.condition.BasicCommerce = true;
	ChrPerksList.list.AdvanceSmuggling.condition.Disguiser = true;
	ChrPerksList.list.AdvanceSmuggling.cost = 2;
	ChrPerksList.list.AdvanceSmuggling.type = PERK_TYPE_DARING; //Levis
	// <-- Levis
	
	// Personal Abilities Skills Group
	//=================================================================
	ChrPerksList.list.BasicCommerce.descr = "perkBasicCommerce";
	ChrPerksList.list.BasicCommerce.cost = 2; // Levis
	ChrPerksList.list.BasicCommerce.locked = true;
	ChrPerksList.list.BasicCommerce.type = PERK_TYPE_MERCHANT; //Levis

	ChrPerksList.list.AdvancedCommerce.descr = "perkAdvancedCommerce";
	ChrPerksList.list.AdvancedCommerce.condition.BasicCommerce = true;
	ChrPerksList.list.AdvancedCommerce.cost = 4; // Levis
	ChrPerksList.list.AdvancedCommerce.locked = true; // Levis
	ChrPerksList.list.AdvancedCommerce.type = PERK_TYPE_MERCHANT; //Levis

	ChrPerksList.list.Trustworthy.descr = "perkTrustworthy";
	ChrPerksList.list.Trustworthy.condition.BasicCommerce = true;
	ChrPerksList.list.Trustworthy.condition.AdvancedCommerce = true;
	ChrPerksList.list.Trustworthy.locked = true; // Levis
	ChrPerksList.list.Trustworthy.cost = 2; // Levis
	ChrPerksList.list.Trustworthy.type = PERK_TYPE_MERCHANT; //Levis

	// GreatZen -->
	ChrPerksList.list.BasicLandOwner.descr = "perkBasicLandOwner";
	ChrPerksList.list.BasicLandOwner.condition.BasicCommerce = true;
	ChrPerksList.list.BasicLandOwner.locked = true; // Levis
	ChrPerksList.list.BasicLandOwner.cost = 1; // Levis
	ChrPerksList.list.BasicLandOwner.type = PERK_TYPE_MERCHANT; //Levis
	// GreatZen <--

	ChrPerksList.list.SharedExperience.descr = "perkSharedExperience";
	ChrPerksList.list.SharedExperience.rank = 10; // Levis
	ChrPerksList.list.SharedExperience.cost = 2; // Levis
	ChrPerksList.list.SharedExperience.type = PERK_TYPE_MISC; //Levis

	ChrPerksList.list.IronWill.descr = "perkIronWill";
	ChrPerksList.list.IronWill.cost = 2; // Levis
	ChrPerksList.list.IronWill.type = PERK_TYPE_MISC; //Levis

	ChrPerksList.list.Brander.descr = "perkBrander";
	ChrPerksList.list.Brander.rank = 20; // KK
	ChrPerksList.list.Brander.cost = 1; // Levis
	ChrPerksList.list.Brander.type = PERK_TYPE_DARING; //Levis
}
