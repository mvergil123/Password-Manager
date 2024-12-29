#include "SecurityVerification.h"
#include <string>
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

bool securityVerification(const string& ANSWER, const int& QUESTIONIDX, const vector<string>& QUESTIONS){
    // this function will verify the user's identity by making sure they provide the same answer to their chosen security question
    cout << "Your identity must be verified before continuing." << endl;
    cout << QUESTIONS[QUESTIONIDX-1] << endl; // print their chosen question
    cout << "Please type in your answer: ";
    string answer;
    cin >> answer; // store the new answer 
    cout << endl;
    
    if (answer == ANSWER) // answers match
    {
        cout << "Answers match. You may continue." << endl;
        return true;
    }
    else{ // answers don't match
        cout << "Answers don't match...." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false; // answers match
    }

}