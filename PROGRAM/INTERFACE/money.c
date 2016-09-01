int TrMoney;

void InitInterface(string iniName)
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
    GameInterface.title = "titleMoney";
    SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button

	ref chm=GetMainCharacter();
	SetNewPicture("CHARPIC", "interfaces\portraits\256\face_" + chm.FaceId + ".tga");
	CreateString(true,"PrMoney","",FONT_NORMAL,COLOR_MONEY,500,305,SCRIPT_ALIGN_LEFT,1.0);
	CreateString(true,"QMoney","",FONT_NORMAL,COLOR_MONEY,150,305,SCRIPT_ALIGN_RIGHT,1.0);
	CreateString(true,"TMoney","",FONT_BOLD_NUMBERS,COLOR_NORMAL,330,299,SCRIPT_ALIGN_CENTER,1.0);
	CreateString(true,"Descr","",FONT_NORMAL,COLOR_NORMAL,330,264,SCRIPT_ALIGN_CENTER,1.0);
        
	GameInterface.strings.PrMoney =  MakeMoneyShow(sti(chm.money),MONEY_SIGN,MONEY_DELIVER);
	GameInterface.strings.QMoney = MakeMoneyShow(sti(chm.wealth),MONEY_SIGN,MONEY_DELIVER);
	GameInterface.strings.TMoney = MakeMoneyShow(TrMoney,MONEY_SIGN,MONEY_DELIVER);
	GameInterface.strings.Descr = LanguageConvertString(tmpLangFileID,"Donation of personal wealth to crew");

	SetSelectable("EXIT_BUTTON",true);

	SendMessage(&GameInterface,"lsl",MSG_INTERFACE_MSG_TO_NODE,"INFO_TEXT",5);

	SetEventHandler("InterfaceBreak","ProcessBreakExit",0);//MAXIMUS: was missing ";"
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcCommand",0);
	SetEventHandler("evntDoPostExit","DoPostExit",0);

	LanguageCloseFile(tmpLangFileID);
}


void ProcessBreakExit()
{
	IDoExit( RC_INTERFACE_SALARY_EXIT );
}

void ProcessCancelExit()
{
	IDoExit( RC_INTERFACE_SALARY_EXIT );
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessBreakExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("ievnt_command","ProcCommand");
	DelEventHandler("evntDoPostExit","DoPostExit");

	interfaceResultCommand = exitCode;
// MAXIMUS interface MOD -->
	PostEvent("LaunchIAfterFrame",1,"sl", "I_SHIP",1);
	EndCancelInterface(false);
//	EndCancelInterface(true);
// MAXIMUS interface MOD <--
}

void ProcCommand()
{
	// LDH 26Sep06 change amount per click from 50 to 500
	string comName = GetEventData();
	string nodName = GetEventData();
        ref mch=GetMainCharacter();

	switch(nodName)
	{
	case "MTR":
		if(comName=="leftstep")
		{
		  if (trmoney>0)
		   {  trmoney=trmoney-500;mch.wealth=sti(mch.wealth)+500;
		      mch.money=sti(mch.money)-500;
                      GameInterface.strings.PrMoney =  MakeMoneyShow(sti(mch.money),MONEY_SIGN,MONEY_DELIVER);
		      GameInterface.strings.QMoney = MakeMoneyShow(sti(mch.wealth),MONEY_SIGN,MONEY_DELIVER);
	              GameInterface.strings.TMoney = MakeMoneyShow(TrMoney,MONEY_SIGN,MONEY_DELIVER);


		   }

		}
                if(comName=="rightstep")
		{
		 if (mch.wealth>=500)
		 {
		  trmoney=trmoney+500;mch.wealth=sti(mch.wealth)-500;
		  mch.money=sti(mch.money)+500;

                  GameInterface.strings.PrMoney =  MakeMoneyShow(sti(mch.money),MONEY_SIGN,MONEY_DELIVER);
	 	  GameInterface.strings.QMoney = MakeMoneyShow(sti(mch.wealth),MONEY_SIGN,MONEY_DELIVER);
	          GameInterface.strings.TMoney = MakeMoneyShow(TrMoney,MONEY_SIGN,MONEY_DELIVER);
	         }
		}

	break;
	case "B_OK":
		trmoney=0;
            	PostEvent("evntDoPostExit",1,"l",RC_INTERFACE_MONEYT_EXIT);

		
		break;
	case "B_CANCEL":
	 	 trmoney=0;
                 mch.wealth=sti(mch.wealth)+trmoney;
		 mch.money=sti(mch.money)-trmoney;
	         PostEvent("evntDoPostExit",1,"l",RC_INTERFACE_MONEYT_EXIT);

		
	break;
	}
}


void DoPostExit()
{
	int exitCode = GetEventData();
	IDoExit(exitCode);
}

