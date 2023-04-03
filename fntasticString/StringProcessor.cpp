#include "StringProcessor.h"

StringProcessor::StringProcessor()
    : cmdLine(nullptr)
{
    initiate();
}

StringProcessor::~StringProcessor()
{
    destroy();
}

int StringProcessor::go()
{
    std::string userInput = this->askUserForInput();
    
    if (this->assertUserInput(userInput)) {
        this->cmdLine->printMessage(this->incorrectInputNote, true, true);
        return 1;
    }

    std::string result = this->processUserInput(userInput);

    this->outputResultToUser(userInput, result);

    return 0;
}

void StringProcessor::initiate()
{
    this->cmdLine = new CustomCmdLine();

    this->sayHelloNote();
}

void StringProcessor::destroy()
{
    if (this->cmdLine) {
        delete this->cmdLine;
        this->cmdLine = nullptr;
    }

    this->sayGoodByeNote();
}

std::string StringProcessor::askUserForInput()
{
    this->cmdLine->printMessage(typeInputNote, true, false, true);
    std::string userInput = this->cmdLine->getUserInput();
    this->cmdLine->clearScreen();

    return userInput;
}

bool StringProcessor::assertUserInput(std::string input) const noexcept
{
    return input == "";
}

std::string StringProcessor::processUserInput(std::string input)
{
    std::string result = "";
    std::map<char, int> symbolsMap;
    std::map<char, char> replaceMap;

    for (char symbol : input) {
        symbol = tolower(symbol);

        if (symbolsMap.contains(symbol)) {
            symbolsMap[symbol]++;
            continue;
        }

        symbolsMap[symbol] = 1;
    }

    for (auto const& [key, val] : symbolsMap) {
        char characterToPrint = '(';
        if (val > 1) {
            characterToPrint = ')';
        }

        replaceMap[key] = characterToPrint;
    }

    for (char symbol : input) {
        char symbolToPrint = replaceMap[tolower(symbol)];
        result += symbolToPrint;
    }

    return result;
}

void StringProcessor::outputResultToUser(std::string input, std::string output)
{
    this->cmdLine->printMessage(this->userInputNote + '\n' + input, true, false, true);
    this->cmdLine->printMessage(this->resultNote + '\n' + output, false, true, true);
}

void StringProcessor::sayHelloNote() const noexcept
{
    this->cmdLine->printMessage(this->helloNote, true, true);
}

void StringProcessor::sayGoodByeNote() const noexcept
{
    this->cmdLine->printMessage(this->byeNote, true, true);
}
