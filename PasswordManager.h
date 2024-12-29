
#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

#include <vector>
#include <string>
#include "Password.h"

class PasswordManager {
    public:
    PasswordManager(); // default constructor
    std::string getPassword(int number); // returns the decryptedPassword variable
    void savePassword(std::string plaintextPassword);


    private:

    std::vector<Password*> passwords;

    std::string decryptedPassword; // stores the decrypted password
    std::vector<std::string> encryptedPasswords; // // vector string that will store the encrypted passwords
    std:: string PasswordtoEncrypt; // stores the password that is needed to be encrypted

};

#endif
