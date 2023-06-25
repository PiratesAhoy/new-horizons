void InitSounds()
{
	ref tmpref; makeref(tmpref, Sounds_Alias);

	tmpref.loading_cannonballs.f1.name = "RUSSIAN\OBJECTS\SHIPCHARGE\_balls.wav";

	tmpref.loading_bombs.f1.name = "RUSSIAN\OBJECTS\SHIPCHARGE\_bombs.wav";

	tmpref.loading_grapeshot.f1.name = "RUSSIAN\OBJECTS\SHIPCHARGE\_grapes.wav";

	tmpref.loading_knippels.f1.name = "RUSSIAN\OBJECTS\SHIPCHARGE\_chain.wav";

	tmpref.GunReadyR.f1.name = "RUSSIAN\OBJECTS\SHIPCHARGE\_GunReadyR.wav";

	tmpref.GunReadyL.f1.name = "RUSSIAN\OBJECTS\SHIPCHARGE\_GunReadyL.wav";

	tmpref.GunReadyB.f1.name = "RUSSIAN\OBJECTS\SHIPCHARGE\_GunReady.wav";

	tmpref.GunReadyF.f1.name = "RUSSIAN\OBJECTS\SHIPCHARGE\_GunReady.wav";

	tmpref.GunReady.f1.name = "RUSSIAN\OBJECTS\SHIPCHARGE\_GunReady.wav";

	tmpref.GunNotReady.f1.name = "RUSSIAN\OBJECTS\SHIPCHARGE\_NotReady.wav";

	tmpref.ship_sinking.f1.name = "RUSSIAN\OBJECTS\SHIPCHARGE\_Abandon0.wav";
	tmpref.ship_sinking.f2.name = "RUSSIAN\OBJECTS\SHIPCHARGE\_Abandon1.wav";
	tmpref.ship_sinking.f3.name = "RUSSIAN\OBJECTS\SHIPCHARGE\_Abandon2.wav";
	tmpref.ship_sinking.f4.name = "RUSSIAN\OBJECTS\SHIPCHARGE\_Abandon3.wav";

	tmpref.sail_ho.f1.name = "RUSSIAN\INTERFACE\_EvShip0.wav";
	tmpref.sail_ho.f2.name = "RUSSIAN\INTERFACE\_EvShip1.wav";

	tmpref.clear_for_action.f1.name = "RUSSIAN\INTERFACE\_EvEnemy0.wav";

	tmpref.ship_ahoy.f1.name = "RUSSIAN\INTERFACE\_EvEnemy1.wav";

	tmpref.land_ho.f1.name = "RUSSIAN\INTERFACE\_EvLand0.wav";
	tmpref.land_ho.f2.name = "RUSSIAN\INTERFACE\_EvLand1.wav";

	tmpref.cargo_aboard.f1.name = "RUSSIAN\OBJECTS\SHIPCHARGE\_Gotcha.wav";

	tmpref.boarding.f1.name = "RUSSIAN\INTERFACE\_GTBoard0.wav";
	tmpref.boarding.f2.name = "RUSSIAN\INTERFACE\_GTBoard1.wav";
	tmpref.boarding.f3.name = "RUSSIAN\INTERFACE\_GTBoard2.wav";
	tmpref.boarding.f4.name = "RUSSIAN\INTERFACE\_GTBoard3.wav";

	tmpref.sails_up.f1.name = "RUSSIAN\OBJECTS\SHIPCHARGE\_set_up.wav";

	tmpref.sails_down.f1.name = "RUSSIAN\OBJECTS\SHIPCHARGE\_strike_down.wav";

	trace("InitSounds ("+LanguageGetLanguage()+"): created " + GetAttributesNum(tmpref) + " entries.");
}
