
#include <string>
#include <iostream>
#include <limits>
#include "inputManager.h"


int getInputNumber(std::string output, int numberOfChoices) {
    auto isSelectionBad = false;
    do {
        std::cout << output << std::endl;
        std::string userInput;
        std::getline(std::cin, userInput);
        int number = 0;
        try {
            number = std::stoi(userInput);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid input: no valid conversion could be performed." << std::endl;
            number = -1;
        } catch (const std::out_of_range& e) {
            std::cerr << "Invalid input: the converted value would fall out of the range of the result type." << std::endl;
            number = -1;
        }
        isSelectionBad = number < 0 || number > numberOfChoices;
        if (!isSelectionBad) {
            return number;
        }
    } while (isSelectionBad);
    return -1;
}

std::string getUserInput(std::string output) {
    std::cout << output;
    std::cout << std::endl;
    std::string input;
    std::getline(std::cin, input);
    return input;
}

