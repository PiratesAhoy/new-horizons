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
