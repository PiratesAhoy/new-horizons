
int nCurScroll;
//ref PChar;

void InitInterface(string iniName)
{
	PChar = GetMainCharacter();

	GameInterface.title = "titleKAMArticles";

	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	CreateString(true,"IslandName","",FONT_NORMAL,COLOR_NORMAL,320,190,SCRIPT_ALIGN_CENTER,1.0);

	SetSelectable("EXIT_BUTTON",true);
	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("frame","FrameProcess",1);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);

	KAM_UpdateDisplay();
}

void FrameProcess()
{
}

void KAM_UpdateDisplay()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");

	string tempmessage1;
	string tempmessage2;
	string tempmessage3;

	SetSelectable("ARTICLES_SALARY_BUTTON",true);

	if(CheckAttribute(PChar, "articles") && sti(PChar.articles))
	{
		SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"ARTICLES_SALARY_BUTTON",0,"KAMPaySalary");
		tempmessage1 = LanguageConvertString(tmpLangFileID,"You have signed articles with your crew.");
		tempmessage2 = LanguageConvertString(tmpLangFileID,"This means");// they are paid by division of plunder after each expedition. If you've had enough of all that privateering, you can pay your crew a regular salary. This would make crew morale more stable, although it would not be as high as it could be under a divide-the-plunder agreement.";
		if(sti(PChar.CrewStatus.explength) > 1)	// LDH was "!= 1", this makes it possible to go back to salary immediately - 07Mar09
		{
			SetSelectable("ARTICLES_SALARY_BUTTON",false);
			tempmessage3 = LanguageConvertString(tmpLangFileID,"Note: Before you can do this, you must divide the plunder.");
		}
		else
		{
			tempmessage3 = LanguageConvertString(tmpLangFileID,"WARNING! A proportion of the crew will desert if you do this.");
		}
	}
	else
	{
		SendMessage(&GameInterface,"lsls",MSG_INTERFACE_MSG_TO_NODE,"ARTICLES_SALARY_BUTTON",0,"KAMSignArticles");
		tempmessage1 = LanguageConvertString(tmpLangFileID,"Your crew is currently paid by regular salary.");
		tempmessage2 = LanguageConvertString(tmpLangFileID,"The alternative");// is to sign articles with your crew, which means you pay them by dividing the plunder of each expedition (do this at the Loanshark's office in any port). If you sign articles with your crew, it is possible to raise your crew's morale much higher than before, but harder to keep it that way!";
		tempmessage3 = LanguageConvertString(tmpLangFileID,"WARNING! A proportion of the crew will desert if you do this.");

	}
	if(GetSelectable("ARTICLES_SALARY_BUTTON")) SetCurrentNode("ARTICLES_SALARY_BUTTON");
	else SetCurrentNode("TEXTWINDOW1");
	SetFormatedText("TEXTWINDOW1",tempmessage1);
	SetFormatedText("TEXTWINDOW2",tempmessage2);
	SetFormatedText("TEXTWINDOW3",tempmessage3);
}


void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();
	if(comName=="activate" || comName=="click")
	{
		switch (nodName)
		{
			case "ARTICLES_SALARY_BUTTON":
				if(CheckAttribute(PChar, "articles") && sti(PChar.articles))
				{
					SetSquadronCrewQuantityRatio(PChar, 0.2 * (1 + makefloat(CalcCharacterSkill(PChar, SKILL_LEADERSHIP))/3.0));
					ResetAllLengths(PChar);			// LDH 14Mar09
					PChar.articles = false;
					KAM_UpdateDisplay();
				}
				else
				{
					SetSquadronCrewQuantityRatio(PChar, 0.2 * (1 + makefloat(CalcCharacterSkill(PChar, SKILL_LEADERSHIP))/3.0));
					ResetAllLengths(PChar);			// LDH 14Mar09
					PChar.articles = true;
					DeleteAttribute(PChar, "repeat_salary_payment"); // PB
					KAM_UpdateDisplay();
				}
				break;

			case "CANCELBUTTON":
				ProcessCancelExit();
				break;
		}
	}
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_KAM_ARTICLES_EXIT);
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("frame","FrameProcess");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

    interfaceResultCommand = exitCode;
// MAXIMUS interface MOD -->
/*	if( CheckAttribute(&InterfaceStates,"InstantExit") && sti(InterfaceStates.InstantExit)==true )
	{
		EndCancelInterface(true);
	}
	else
	{
		PostEvent("LaunchIAfterFrame",1,"sl", "I_SELECTMENU", 1);
		EndCancelInterface(false);
	}*/
	PostEvent("LaunchIAfterFrame",1,"sl", "I_SHIP",1);
	EndCancelInterface(false);
// MAXIMUS interface MOD <--
}
