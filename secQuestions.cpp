#include "secQuestions.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include "inputManager.h"
#include <sstream>
#include <limits>


using namespace std;

void promptQuestions(const vector<string>& QUESTIONS, int &choice, const string& NAME, string& answer) {
    system("clear"); // clear the screen

    cout << NAME << ", please select a security question: " << endl;
    cout << " " << endl;
    for (size_t i = 0; i < QUESTIONS.size(); i++){ // for loop that iterates through the question vector
        cout << QUESTIONS[i] << endl;
    }
    cout << " " << endl;
    cout << "Your input: "; // get the number of the question they want

    choice = getInputNumber("Please select a security question", int(QUESTIONS.size()));
    answer = getUserInput(std::string("Type in your answer (Remember this answer!) \n") +  QUESTIONS[choice-1]);
    cout << endl;
    std::cout << "Your answer was: " << answer << std::endl;
}
