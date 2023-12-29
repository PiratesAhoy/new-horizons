void Telescope_Request()
{
	int nTelescopeIn = GetEventData();

	ref mchref = GetMainCharacter();

	if (GetCharacterEquipByGroup(mchref, SPYGLASS_ITEM_TYPE) == "") {
		nTelescopeIn = 0;
	}

	if (nTelescopeIn != 0 && Scene.Camera == DECK_CAMERA) {
		SendMessage(&objISpyGlass, "ll", MSG_TELESCOPE_REQUEST, 1);
	}
	else {
		SendMessage(&objISpyGlass, "ll", MSG_TELESCOPE_REQUEST, 0);
	}
}