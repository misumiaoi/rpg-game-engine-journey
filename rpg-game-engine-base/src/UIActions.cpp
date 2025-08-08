#include <iostream>
#include <random>
#include <time.h>
#include <memory>
#include <chrono>
#include <thread>
#include "Characters.h"
#include "ActionSystem.h"
#include "UIACtions.h"



void UIActions::pauseFor(int ms) { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }


void UIActions::countDown(int start, int end, int step, int timeperiod)
{
	for (int i = start; i >= end; i -= step)
	{
		std::cout << i << std::endl;
		pauseFor(timeperiod);
	}

}


void UIActions::typeText(std::string& text, int delay_ms)
{
	for (const char c : text)
	{
		std::cout << c << std::flush;
		pauseFor(delay_ms);
	}
	
}
void UIActions::clearScreen()
{
	#ifdef _WIN32
	system("cls");
	#endif
	
}
void UIActions::drawProgress(int totalsteps, int current, int width = 50)
{
	#ifdef _WIN32
	system("cls");
	#else
	system("clear");
	#endif
	int pos = static_cast<int>(static_cast<double>(current) / totalsteps * width);
	std::cout << "[";
	for (int i = 0; i < width; ++i)
	{
		if (i < pos)
			std::cout << "=";
		else if (i == pos)
			std::cout << ">";
		else
			std::cout << " ";
	}
	std::cout << "] " << current << "/" << totalsteps << std::endl;

}
void UIActions::pauseForEnter() 
{
	std::cout << "Press Enter to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}