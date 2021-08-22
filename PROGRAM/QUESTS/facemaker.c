// KAM -->
void FaceMaker(ref rCharacter)						//changed by KAM
{
	rCharacter.FaceId = GetCharacterFaceID(rCharacter.model);
	rCharacter.headModel = "h_" + rCharacter.model;
}
// KAM <--

int GetCharacterFaceID(string modelname)
{
	// NK move all faceID to the Models[] array 05-07-11 -->
	//trace("modelname = " + modelname);
	ref mdl = &Models[0];
	//trace("made ref");
	int idx = GetModelIndex(modelname);
	//trace("getindex gives " + idx);
	if(idx >= 0 && idx <= MODEL_HIGH) mdl = &Models[idx];
	string sfid = mdl.FaceID;
	//trace("fid is " + sfid);
	int fid = sti(sfid);
	//trace("sti of that is " + fid);
	if(fid == 0 && GetSymbol(sfid, 0) != "0") return GetCharacterFaceID(sfid);
	return fid;
	// NK <--
}