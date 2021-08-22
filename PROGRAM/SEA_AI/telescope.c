void Telescope_Request()
{
// KK -->
	ref mchref = GetMainCharacter();
	aref arScopeItm;
	if (Items_FindItem(GetCharacterEquipByGroup(mchref, SPYGLASS_ITEM_TYPE), &arScopeItm) >= 0 && SeaCameras.Camera == "SeaDeckCamera")
		SendMessage(&Telescope, "l", MSG_TELESCOPE_REQUEST);
// <-- KK
}