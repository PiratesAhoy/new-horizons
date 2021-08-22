void InitInterface_BB(string iniName, ref book)
{
	int lngFileID = -1;
	SendMessage(&GameInterface,"ls",MSG_INTERFACE_INIT,iniName);
	CreateExitString();//MAXIMUS: standard exit-string for exit-button
	CreateString(false, "Book_StoryTitle", GetAssembledString(TranslateString("" , book.name),book), FONT_QUESTBOOK, COLOR_WHITE, 320, 50, SCRIPT_ALIGN_CENTER, 1.2);
	if(CheckAttribute(book,"UnlockedPerk"))
	{
		UnlockPerkCharacter(GetMainCharacter() ,book.UnlockedPerk);
		lngFileID = LanguageOpenFile("AbilityDescribe.txt");
		CreateString(true, "TIME", "You unlocked the perk: " + LanguageConvertString(lngFileID,book.UnlockedPerk), FONT_NORMAL, COLOR_NORMAL, 320, 482, SCRIPT_ALIGN_CENTER, 0.7);
		LanguageCloseFile(lngFileID);
		DeleteAttribute(book,"UnlockedPerk");
	}
	//Levis: support quests starting after reading a book -->
	if(CheckAttribute(book,"QuestName"))
	{
		LAi_QuestDelay(book.QuestName, 0.0);
	}
	//Levis: support quests starting after reading a book <--
	SetSelectable("EXIT_BUTTON",true);
	if(CheckAttribute(book,"text"))
	{
		if (FindFile("RESOURCE\\INI\\TEXTS\\ENGLISH\\BOOKS","*.txt", book.text+".txt") != "") 
		{
			lngFileID = LanguageOpenFile("BOOKS\\" +book.text + ".txt");
		}
		else
		{
			trace("BOOK ERROR: cant find "+book.text+".txt");
		}
	}
	else
	{
		trace("BOOK ERROR: no text set for book, attempting to use id to open book");
		lngFileID = LanguageOpenFile("BOOKS\\" +book.id + ".txt");
	}
	string text = LanguageConvertString(lngFileID,"TEXT");
	LanguageCloseFile(lngFileID);
	//Fix for crashing with books without info
	if(HasSubStr(text,"#"))
	{
		text = GetAssembledString(text,book);
	}
	//End fix
	DisplayBookText(text)
	SetEventHandler("InterfaceBreak","ProcessCancelExit",0);
	SetEventHandler("exitCancel","ProcessCancelExit",0);
	SetEventHandler("ievnt_command","ProcessCommandExecute",0);
	SetEventHandler("SetScrollerPos","SetScrollerPos",0);
	SetEventHandler("ScrollPosChange","ProcScrollPosChange",0);
}

void ProcessCommandExecute()
{
	string comName = GetEventData();
	string nodName = GetEventData();

	int x;ref tmpch;string tmpstr;
	if(nodName=="I_CHARACTER")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_BOOK_EXIT;
			EndCancelInterface(false);
		}
	}
    if(nodName=="I_SHIP")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_BOOK_EXIT;
			EndCancelInterface(false);

		}
	}
    if(nodName=="I_SHIPHOLD")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_BOOK_EXIT;
			EndCancelInterface(false);

		}
	}
    if(nodName=="I_PASSENGER")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_BOOK_EXIT;
			EndCancelInterface(false);
		}
	}
    if(nodName=="I_TRADEBOOK")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_BOOK_EXIT;
			EndCancelInterface(false);
		}
	}
    if(nodName=="I_SHIPLOG")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_BOOK_EXIT;
			EndCancelInterface(false);

		}
	}
    if(nodName=="I_NATIONS")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_BOOK_EXIT;
			EndCancelInterface(false);

		}
	}
    if(nodName=="I_ITEMS")
	{
		if(comName=="activate" || comName=="click")
		{
			PostEvent("LaunchIAfterFrame",1,"sl", nodName, 2);
			InterfaceStack.SelectMenu_node = nodName;
			interfaceResultCommand = RC_INTERFACE_BOOK_EXIT;
			EndCancelInterface(false);

		}
	}
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_BOOK_EXIT);
}

void XI_SetScroller(float fpos)
{
	SendMessage(&GameInterface,"lsf",MSG_INTERFACE_SET_SCROLLER,"BOOKSCROLL",fpos);
}

void SetScrollerPos()
{
	string nodName = GetEventData();
	if(nodName=="BOOK_TEXT") return;
	float fpos = GetEventData();
	XI_SetScroller(fpos);
}

void IDoExit(int exitCode)
{
	DelEventHandler("InterfaceBreak","ProcessCancelExit");
	DelEventHandler("exitCancel","ProcessCancelExit");
	DelEventHandler("SetScrollerPos","SetScrollerPos");
	DelEventHandler("ScrollPosChange","ProcScrollPosChange");
	DelEventHandler("ievnt_command","ProcessCommandExecute");

    interfaceResultCommand = exitCode;
	// PB: Return to Items Tab -->
	ref PChar = GetMainCharacter();
	PChar.bookreading = true;
	PostEvent("LaunchIAfterFrame",1,"sl", "I_ITEMS", 2);
	InterfaceStack.SelectMenu_node = "I_ITEMS";
	interfaceResultCommand = exitCode;
	EndCancelInterface(false);
	// PB: Return to Items Tab <--
}

void ProcScrollPosChange()
{
	float newPos = GetEventData();
	SendMessage(&GameInterface,"lslf",MSG_INTERFACE_MSG_TO_NODE,"BOOK_TEXT", 2, newPos);
}

void ProcScrollChange()
{
	int changeNum = GetEventData();
	if(changeNum==0) return;
	string controlNode = "";
	if( GetSelectable("BOOK_WINDOW") ) controlNode = "BOOK_WINDOW";
	if( GetSelectable("BOOK_TEXT") ) controlNode = "BOOK_TEXT";

	if(controlNode!="")
	{
		if(changeNum>0) {
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,controlNode,-1, 0,ACTION_DOWNSTEP);
		} else {
			SendMessage(&GameInterface,"lslll",MSG_INTERFACE_MSG_TO_NODE,controlNode,-1, 0,ACTION_UPSTEP);
		}
	}
}


void DisplayBookText(string text)
{
	ChangeStringColor("Book_StoryTitle", COLOR_WHITE);
	EnableString("Book_StoryTitle");
	SendMessage(&GameInterface, "lsle", MSG_INTERFACE_MSG_TO_NODE, "BOOK_TEXT", 0, &text);
	SetNodeUsing("BOOK_WINDOW", false);
	SetNodeUsing("BOOKTEXT_LINE", true);
	SetNodeUsing("BOOK_TEXT", true);
	SetCurrentNode("BOOK_TEXT");
}
