#include "PasswordManager.h" // access password class
#include <fstream> // read the securityquestions file
#include "menu.h" // access menu function
#include "secQuestions.h" // access security questions function
#include <cstdlib> // to clear the terminal 
#include <vector> 
#include <string>
#include <iostream> // for output 
#include <sstream>
#include <limits>
#include "inputManager.h"
#include "SecurityVerification.h"

using namespace std;


int main(){

    system("clear"); // clear the screen

    // read through the security questions file
    ifstream questionsFile;
    questionsFile.open("SecurityQuestions.txt"); // open the file

    if (!questionsFile.is_open()) // check for file errors
    {
        cerr << "File failed to open." << endl;
        return -1;
    }

    string q; // string to store the current question
    vector<string> securityQuestions; // vector that will store all the questions 
    while(getline(questionsFile, q))
    {
        securityQuestions.push_back(q); // append the questions into the vector
    }
    questionsFile.close(); // close the file

    system("clear"); // clear the screen

    // ask the user for their name
    string name;
    cout << "Welcome" << endl;
    cout << "Please Type in your name: "; 

    getline(cin, name);; // store the name of the user
    cout << " " << endl;

    // present the questions 
    int questionChoice; // stores the question number that the user has picked
    string questionAnswer; // stores the answer to the questions
    promptQuestions(securityQuestions, questionChoice, name, questionAnswer); // call the prompt questions function

    cout << "Press ENTER to go back to the menu." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int menuChoice(0); // var that will store the input from the menu screen

    PasswordManager* passwordManager = new PasswordManager(); // pointer that will store the current password

    vector<string> passwordNames; // vector that will store all the password names
    string passName; // stores the current password name
    string password; // stores the current password
    int passwordIDX; // stores the index of the password

    bool isVerified = true; // bool value to store the ID verification of the user

    while (menuChoice != 4){ // while loop that will have the program running until the user exits
        Menu(menuChoice); // prompt the menu by calling the menu function

        if (menuChoice == 1){ // wanting to add a password 

            system("clear"); // clear the screen 
            cout << "Add a Password" << endl; // header
            cout << "Type in the name of your password: "; //Type the name of the password
            getline(cin, passName); // get the current password name
            cout << " " << endl;
            passwordNames.push_back(passName); // append the name to the list of password names

            cout << "Type in the password to store: " << endl; // ask for the password
            getline(cin, password); // get the current password 
        
            passwordManager->savePassword(password);

            cout << "Press ENTER to go back to the menu." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }
        else if (menuChoice == 2){ // check stored passwords

            system("clear"); // clear the screen 
            cout << "Stored Passwords" << endl; // header
            if (!passwordNames.empty()){ // vector passwordNames is not empty
                for (size_t j = 0; j < passwordNames.size(); j++) { // for loop to iterate through the passwordNames
                cout << j + 1 << ") " << passwordNames[j] << endl; // prints each password
            }
            }
            else{ // vector passwordNames is empty
                cout << "No current passwords available" << endl;
            }
            cout << "Press ENTER to go back to the menu." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }
        else if (menuChoice == 3){ // Decrypt a password
            system("clear"); // clear the screen
            isVerified = securityVerification(questionAnswer, questionChoice, securityQuestions); // check for identity 

            if (isVerified){

            cout << "Decrypt a Password" << endl; // header
            cout<< " " << endl;
            cout << "Stored Passwords" << endl; // header
            if (!passwordNames.empty()){ // vector passwordNames is not empty
                for (size_t j = 0; j < passwordNames.size(); j++) { // for loop to iterate through the passwordNames
                cout << j + 1 << ") " << passwordNames[j] << endl; // prints each password
            }
                cout << " " << endl;
                cout << "Select the password you would like to decrypt: " << endl; // ask which password they wanna access

                cin >> passwordIDX; // get the index of the password they want to decrypt

                while (passwordIDX <= 0 || passwordIDX > int(passwordNames.size())){ // while loop that makes sure the user answered properly
                    cout << "Invalid option. Please type in a valid number: ";
                    cin >> passwordIDX;
                    cout << " " << endl;  
                }

                std::string decryptedPassword = passwordManager->getPassword(passwordIDX - 1); // send to decrypt the password
                cout << "Password is: " << decryptedPassword << endl; // print the password

            }

            else{ // vector passwordNames is empty
                cout << "No current passwords available" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');


            }

        }
        cout << "Press ENTER to go back to the menu." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }

    }
    delete passwordManager; // delete the pointer
    passwordManager = nullptr; // set the pointer to nullptr

    return 0;
}
