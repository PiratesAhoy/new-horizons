#define MAX_MODELS			1500 // Talisman was 600
#define MAX_MODELSLOTS		5
#define DEFAULT_ANI			"man"
#define DEFAULT_HEIGHT		1.8
#define DEFAULT_MODEL		"blaze"
#define DEFAULT_FACEID		41 // old animists face. now, actually, unused for animists.

//nation defines
#define ALL_NATIONS			266
#define CLERIC				254
#define RESTRICTED			253
#define BROKEN				252
#define CURSED				251

// modeltypes defines
#define CHANCEMULT_PIRATENATION_GENERICMODEL 0.5 // the multiplier to modelchance for generic models assigned, via assign-to-all-nations, to nation pirate.


int MODEL_HIGH = 0;
int MODELTYPES_QUANTITY = 0;
object Models[MAX_MODELS];
object ModelSlots[MAX_MODELSLOTS];
object ModelTypes[1024]; // must be at least (max model types) * (max nations + 1)
object ModelSubTypes;
