#include "Console.hpp"

void Console::print(const string& message)
{
	std::cout << message << std::endl;
}

void Console::pause()
{
	std::cout << "press any key to continue...";

	std::cin.ignore();
}