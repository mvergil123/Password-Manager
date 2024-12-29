#ifndef PASSWORDMANAGER_PASSWORD_H
#define PASSWORDMANAGER_PASSWORD_H

#include "cryptopp/osrng.h"

class Password {


public:
    Password();

    void setPlainTextPassword(std::string plainTextPassword);
    std::string getDecryptedPassword();

private:
    std::string encryptedPassword;
    void encrypt(std::string plaintextPassword);
    std::string decrypt(std::string encryptedPassword);

    CryptoPP::AutoSeededRandomPool prng;
    CryptoPP::SecByteBlock key;
    CryptoPP::byte iv[CryptoPP::AES::BLOCKSIZE];



};


#endif //PASSWORDMANAGER_PASSWORD_H
