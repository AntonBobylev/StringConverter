#pragma once
#include <iostream>
#include <string>

class CustomCmdLine
{
public:
	CustomCmdLine() {};
	~CustomCmdLine() {};

public:
	void printMessage(std::string message, bool clearScreen = false, bool pauseScreen = false, bool newLine = false) const;
	void clearScreen() const noexcept;
	std::string getUserInput();

private:
	void pauseScreen() const noexcept;
	void printNewLine() const noexcept;
};

