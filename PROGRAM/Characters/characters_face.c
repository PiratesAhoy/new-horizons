string	sEnManFaces = "30,35,10,6,32,33,42,43";
string	sFrManFaces = "19,27,29,31,32,33,43,43";
string	sSpManFaces = "25,37,38,44,7,32,33,42,43";
string	sHoManFaces = "11,26,28,36,32,33,42,43";
string	sPoManFaces = "12,30,39,32,33,42,43";
string	sPiManFaces = "0,1,13,14,2,23,24,3,40,5";

void SetRandomFaceToCharacter(ref rCharacter)
{
	string sFaceID = "1";
	if (rCharacter.sex == "man")
	{
		switch (sti(rCharacter.nation))
		{
			case ENGLAND:	sFaceID = GetRandSubString(sEnManFaces); break;
			case FRANCE:	sFaceID = GetRandSubString(sFrManFaces); break;
			case SPAIN:		sFaceID = GetRandSubString(sSpManFaces); break;
			case PIRATE:	sFaceID = GetRandSubString(sPiManFaces); break;
			case HOLLAND:	sFaceID = GetRandSubString(sHoManFaces); break;
			case PORTUGAL:	sFaceID = GetRandSubString(sPoManFaces); break;
		}
	}
	else
	{
		sFaceID = "16";
	}
	
	rCharacter.FaceId = sti(sFaceID);
}