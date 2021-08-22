// -------
// GLOBALS
// -------

bool    bFCoHS_HailCanBe = false;
	// Can we currently hail another ship?

bool    bFCoHS_ContactCanBe = false;
	// Can we currently contact a ship?

int	iFCoHS_ContactCanBeCharIdx;
	// Char/Ship we can contact

bool	bFCoHS_FriendlyBoardingStarted = false;
	// Are we in "Friendly Boarding" mode

string  sFCoHS_DeckName;
int 	iFCoHS_FromDeckIdx = -1;
int     iFCoHS_BoardingLocation = -1;
int     iFCoHS_BoardingCaptain = -1;

object  oFCoHS_FriendlyCrew[10];
	// Friendly crew




