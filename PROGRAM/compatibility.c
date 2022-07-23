bool NEW_STORM_ENGINE = true;

int calcNumberOfTextureColumns(int columns) {
	if (NEW_STORM_ENGINE) {
		return columns * 2;
	}
	else {
		return columns;
	}
}

int calcTextureIndex(int index, int columns) {
	if (columns < 1) {
		columns = 1;
	}

	if (NEW_STORM_ENGINE) {
		int row = index / columns;
		int column = index % columns;
		return column + (row * columns * 2);
	}
	else {
		return index;
	}
}

int calcSelectedTextureIndex(int index, int columns) {
	if (NEW_STORM_ENGINE) {
		return calcTextureIndex(index, columns) + columns;
	}
	else {
		return index;
	}
}

/**
 * Hardcoded mapping of ship icons on the ships_all texture
 */
int getMappedShipIcon(int picture, int textureIndex) {
	int row = 0;
	int column = 0;
	switch(textureIndex) {
		case 10: // ships_16 (2, 4)
			row = picture / 4;
			column = picture % 4;
			picture = 2 + (column * 2) + (4 + row) * 16;
			break;
		case 11: // ships_1 (0, 0)
			picture += 0;
			break;
		case 12: // ships_2 (0, 1)
			row = picture / 1;
			column = picture % 1;
			picture = 0 + (column * 2) + (1 + row) * 16;
			break;
		case 14: // ships_32 (2, 0)
			row = picture / 4;
			column = picture % 4;
			picture = 2 + (column * 2) + (4 + row) * 16;
			break;
		case 15: // ships_48 (2, 8)
			row = picture / 4;
			column = picture % 4;
			picture = 2 + (column * 2) + (8 + row) * 16;
			break;
	}
	return picture;
}
