#include "ConsoleInterface.h"
#include "Characters.h"
#include "ActionSystem.h"
#include "UIActions.h"
#include <memory>
#include <iostream>

auto CharacterPtr = std::make_unique<Characters>();
auto ActionPtr = std::make_unique<ActionSystem>();
auto LoadPtr = std::make_unique<UIActions>();


// Remove the class definition here, only implement the method
void ConsoleInterface::handleSelection(ConsoleInterface::SelectionOptions option)
{
	switch (option) {
	case SelectionOptions::Yes:

		break;
	case SelectionOptions::No:

		break;
	case SelectionOptions::Cancel:

		break;
	case SelectionOptions::Retry:

		break;
	case SelectionOptions::Ignore:

		break;
	default:
		std::cout << "Press any key to start the game" << std::endl;
		break;
	}

}