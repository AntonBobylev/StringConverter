#include "CustomCmdLine.h"

void CustomCmdLine::printMessage(
	std::string message, 
	bool clearScreen, 
	bool pauseScreen,
	bool newLine
) const
{
	if (clearScreen) {
		this->clearScreen();
	}

	std::cout << message << std::endl;

	if (newLine) {
		this->printNewLine();
	}

	if (pauseScreen) {
		this->pauseScreen();
	}
}

void CustomCmdLine::clearScreen() const noexcept
{
	system("CLS");
}

std::string CustomCmdLine::getUserInput()
{
	std::string result = "";
	getline(std::cin, result);
	return result;
}

void CustomCmdLine::pauseScreen() const noexcept
{
	system("PAUSE");
}

void CustomCmdLine::printNewLine() const noexcept
{
	std::cout << std::endl;
}
