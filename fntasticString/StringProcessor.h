#pragma once
#include "CustomCmdLine.h"
#include <map>

class StringProcessor
{
public:
	StringProcessor();
	~StringProcessor();

public:
	int go();

private:
	void initiate();
	void destroy();

private:
	std::string askUserForInput();
	bool assertUserInput(std::string input) const noexcept;
	std::string processUserInput(std::string input);
	void outputResultToUser(std::string input, std::string output);

private:
	void sayHelloNote() const noexcept;
	void sayGoodByeNote() const noexcept;

private:
	CustomCmdLine* cmdLine;

private:
	const std::string helloNote = "Hello, user!";
	const std::string typeInputNote = "Please, type an input here:";
	const std::string incorrectInputNote = "Please, make sure the input is correct and not empty and try again one more time";
	const std::string userInputNote = "Your input is:";
	const std::string resultNote = "The result output is:";
	const std::string byeNote = "Goodbye, user!";
};

