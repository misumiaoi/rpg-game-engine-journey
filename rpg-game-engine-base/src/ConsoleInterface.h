#pragma once
#include "UIActions.h"
#include <iostream>
#include <random>
#include <string>
#include <memory>

class ConsoleInterface
{
public:
	enum class ConsoleColor
	{
		Red,Green,Blue,Yellow,Cyan,Magenta,Default
	};
	
	enum class ConsoleStyle
	{
		Bold,Italic,Underline,Reset
	};
	
	enum class ConsoleAlignment
	{
		Left,Center,Right
	};

	enum class ConsoleOptions
	{
		Confirm, Cancel, Back, Forward, Exit, Help, Settings, About, Restart, Continue, Save, Load, NewGame
	};

	enum class SelectionOptions
	{
		None, Yes, No, Cancel, Retry, Ignore
	};
	
	void handleSelection(SelectionOptions option);

private:
	int switcher = 0;


};
