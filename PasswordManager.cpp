 
#include "PasswordManager.h"
#include <vector>
#include <string>
#include <iostream>

#include <iostream>
#include <string>
#include "cryptopp/aes.h"
#include "cryptopp/filters.h"
#include "cryptopp/modes.h"
#include "cryptopp/osrng.h"
#include "cryptopp/hex.h"

using namespace std;

PasswordManager :: PasswordManager() { // default constructor
    using namespace CryptoPP;

}


string PasswordManager :: getPassword(int number) {
    return passwords.at(number)->getDecryptedPassword();
}


void PasswordManager::savePassword(std::string plaintextPassword) {
    auto password = new Password();
    password->setPlainTextPassword(plaintextPassword);
    passwords.push_back(password);
}

