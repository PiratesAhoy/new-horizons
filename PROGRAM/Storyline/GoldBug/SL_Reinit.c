void SL_Reinit()
{
	ref pc = GetMainCharacter();
	ref ch;
	int n;

	aref gun;

	if (Items_FindItem("pistolbbuss", &gun) >= 0) {	// Blunderbuss
		DeleteAttribute(gun, "multidmg");
		DeleteAttribute(gun, "misfire");
	}
}
