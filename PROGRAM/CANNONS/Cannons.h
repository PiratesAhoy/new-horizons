// NK -->
#define CANNON_TYPES_MAX		32
int CANNON_TYPES_QUANTITY = 0;
int CANNON_CALIBERS_MAX = 0;
int Cannon_Calibers[CANNON_TYPES_MAX];
// NK <--

#define CANNON_TYPE_CULVERINE_LBS12	0
#define CANNON_TYPE_CULVERINE_LBS16	1
#define CANNON_TYPE_CULVERINE_LBS24	2
#define CANNON_TYPE_CANNON_LBS12	3
#define CANNON_TYPE_CANNON_LBS16	4
#define CANNON_TYPE_CANNON_LBS24	5
#define CANNON_TYPE_CANNON_LBS32	6

// KNB -->
#define CANNON_TYPE_LONG_LBS4 0
#define CANNON_TYPE_LONG_LBS6 1
#define CANNON_TYPE_LONG_LBS9 2
#define CANNON_TYPE_LONG_LBS12 3
#define CANNON_TYPE_LONG_LBS18 4
#define CANNON_TYPE_LONG_LBS24 5
#define CANNON_TYPE_LONG_LBS32 6
#define CANNON_TYPE_LONG_LBS42 7
#define CANNON_TYPE_CARRONADE_LBS12  8
#define CANNON_TYPE_CARRONADE_LBS18  9
#define CANNON_TYPE_CARRONADE_LBS24  10
#define CANNON_TYPE_CARRONADE_LBS32  11
#define CANNON_TYPE_CARRONADE_LBS42  12
#define CANNON_TYPE_CARRONADE_LBS68  13
#define CANNON_TYPE_CARRONADE_LBS68I 14
#define CANNON_TYPE_CARRONADE_LBS42I 15
#define CANNON_TYPE_CARRONADE_LBS68SPEC 16
#define CANNON_TYPE_CARRONADE_DUTCHMAN 17

#define CANNON_NAME_LONG              1
#define CANNON_NAME_CARRONADE         2

#define CARRONADE_DISPERSION_MULT 1.2 // NK so it's not hardcoded.
// KNB <--


// Scheffnow - bfd
// #define CANNON_TYPE_NONECANNON		1000
#define CANNON_TYPE_NONECANNON		31

#define CANNON_NAME_CANNON              1
#define CANNON_NAME_CULVERINE           2
#define CANNON_NAME_SPECIAL_CANNON		3

#define CANNON_ARC_FRONT		0
#define CANNON_ARC_BACK			2
#define CANNON_ARC_LEFT			3
#define CANNON_ARC_RIGHT		1

object  Cannon[CANNON_TYPES_MAX]; // NK

ref GetCannonByType(int iCannonType) { return &Cannon[iCannonType]; }

int GetCannonCaliber(int nCannon)
{
	// Aconcagua:
	// what about this??? is it more efficient? at least more readable...
	// return sti(GetCannonByType(nCannon).caliber);

	// KNB -->
	if(USE_REAL_CANNONS)
	{
		switch(nCannon)
		{
		case CANNON_TYPE_NONECANNON:
			return 0;
			break;
		case CANNON_TYPE_LONG_LBS4:
			return 4;
			break;
		case CANNON_TYPE_LONG_LBS6:
			return 6;
			break;
		case CANNON_TYPE_LONG_LBS9:
			return 9;
			break;
		case CANNON_TYPE_LONG_LBS12:
			return 12;
			break;
		case CANNON_TYPE_LONG_LBS18:
			return 18;
			break;
		case CANNON_TYPE_LONG_LBS24:
			return 24;
			break;
		case CANNON_TYPE_LONG_LBS32:
			return 32;
			break;
		case CANNON_TYPE_LONG_LBS42:
			return 42;
			break;
		case CANNON_TYPE_CARRONADE_LBS12:
			return 6;
			break;
		case CANNON_TYPE_CARRONADE_LBS18:
			return 9;
			break;
		case CANNON_TYPE_CARRONADE_LBS24:
			return 12;
			break;
		case CANNON_TYPE_CARRONADE_LBS32:
			return 18;
			break;
		case CANNON_TYPE_CARRONADE_LBS42:
			return 24;
			break;
		case CANNON_TYPE_CARRONADE_LBS68:
			return 32;
			break;
		case CANNON_TYPE_CARRONADE_LBS68I:
			return 32;
			break;
		case CANNON_TYPE_CARRONADE_LBS42I:
			return 24;
			break;
		case CANNON_TYPE_CARRONADE_LBS68SPEC:
			return 68;
			break;
		case CANNON_TYPE_CARRONADE_DUTCHMAN:
			return 128;
			break;
		}
	}
	// KNB <--
	else
	{
		switch(nCannon)
		{
			case CANNON_TYPE_NONECANNON:
				return 0;
			break;
			case CANNON_TYPE_CULVERINE_LBS12:
				return 12;
			break;
			case CANNON_TYPE_CANNON_LBS12:
				return 12;
				break;
			case CANNON_TYPE_CULVERINE_LBS16:
				return 16;
				break;
			case CANNON_TYPE_CANNON_LBS16:
				return 16;
				break;
			case CANNON_TYPE_CULVERINE_LBS24:
				return 24;
				break;
			case CANNON_TYPE_CANNON_LBS24:
				return 24;
				break;
			case CANNON_TYPE_CANNON_LBS32:
				return 32;
				break;
		}
	}
}
