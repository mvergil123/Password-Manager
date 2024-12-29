#include "menu.h"
#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

void Menu(int& menuChoice){

    system("clear"); // clear the screen 

    // prompts the menu screen
    cout << "PASSWORD MANAGER" << endl;
    cout << " " << endl;

    cout << "Select a choice: " << endl;
    cout << "1) Add a Password" << endl;
    cout << "2) Check my Stored Passwords" << endl;
    cout << "3) Decrypt a Password" << endl;
    cout << "4) Quit" << endl;
    cout << "Your Input: "; // ask for the input
    cin >> menuChoice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the newline character left in the input buffer
   
    cout << " " << endl;


}
