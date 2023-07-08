bool CanSave()
{
	if(bPlayVideoNow) return false;

	ref PChar = GetMainCharacter();
	if(!IsEntity(PChar))
	{
		if(!IsEntity(&worldMap) && CharacterIsDead(PChar))  return false;
	}

	if(!ENABLE_CHEATMODE)
	{
		// PB: Prevent CTDs while being resurrected -->
		if(CheckAttribute(PChar, "NoSave.Resurrection"))
		{
			LogIt(TranslateString("", "You can't save or load until") + " " + GetMyFullName(ResurrectingOfficiant) + " " + TranslateString("", "leaves."));
			return false;
		}
		// PB: Prevent CTDs while being resurrected <--
		// PW -->
		if (CheckAttribute(PChar,"NoSave.CarryRelic") == true && PChar.NoSave.CarryRelic != "none") {
			LogIt(TranslateString("","You can't save while carrying a holy relic! Give it to a monk") + " " + PChar.NoSave.ReleaseMonkLocation + "."); // NK
			return false;
		}

			// PW <--
		bool bEnableSave = true;
		string restrictSave = "save_now";

		aref arTmp;
		if(FindEntity(&arTmp,"fader")) bEnableSave = false;

		if(dialogRun || dialogSelf) bEnableSave = false;
		if(!CheckAttribute(&InterfaceStates, "Buttons.Save.enable") || InterfaceStates.Buttons.Save.enable!= 1) bEnableSave = false;
		if(InterfaceStates.Launched!=0) bEnableSave = false;

		aref arScrShoter;
		if(FindEntity(&arScrShoter,"scrshoter")) bEnableSave = false;

		if(bSeaActive && !bMapEnter) { bEnableSave = false; restrictSave = "save_while sailing"; }
		if(LAi_IsBoardingProcess()) { bEnableSave = false; restrictSave = "save_while boarding"; }
		if(bAbordageStarted && !ownDeckStarted()) { bEnableSave = false; restrictSave = "save_while sailing or boarding"; }
		if(bMutinyDeckStarted) { bEnableSave = false; restrictSave = "save_while sailing or boarding"; }
		if(bEnableSave && ownDeckStarted() && bSeaActive) { bEnableSave = false; restrictSave = "save_on deck"; }
		if(bEnableSave && HasSubStr(PChar.location,"Deck") && bSeaActive) { bEnableSave = false; restrictSave = "save_on deck"; }

		if(!bEnableSave) {
			Log_SetStringToLog(TranslateString("","save_You can't save")+" "+TranslateString("",restrictSave)+"!");
			return false;
		}
	}

	return true;
}
