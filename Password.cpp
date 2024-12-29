
#include "Password.h"

#include <iostream>
#include <string>
#include "cryptopp/aes.h"
#include "cryptopp/filters.h"
#include "cryptopp/modes.h"
#include "cryptopp/osrng.h"
#include "cryptopp/hex.h"

Password::Password() {
    key = CryptoPP::SecByteBlock(CryptoPP::AES::DEFAULT_KEYLENGTH);
    prng.GenerateBlock(key, key.size());
    prng.GenerateBlock(iv, sizeof(iv));
}

void Password::setPlainTextPassword(std::string plainTextPassword) {
    encrypt(plainTextPassword);
}

std::string Password::getDecryptedPassword() {
    return decrypt(encryptedPassword);
}

void Password::encrypt(std::string plaintextPassword) {
    using namespace CryptoPP;
    std::string plaintext = plaintextPassword;
    std::string ciphertext;
    std::string decryptedtext;

    // Encrypt
    try {
        CBC_Mode<AES>::Encryption encryptor(key, key.size(), iv);
        StringSource(plaintext, true,
                     new StreamTransformationFilter(encryptor,
                                                    new StringSink(ciphertext)
                     ) // StreamTransformationFilter
        ); // StringSource
    }
    catch (const CryptoPP::Exception& e) {
        std::cerr << "Encryption Error: " << e.what() << std::endl;
    }

    encryptedPassword = ciphertext;
    std::cout << "Encrypted text (for visual proof) is: " << encryptedPassword << std::endl;
}


std::string Password::decrypt(std::string encryptedPassword) {
    using namespace CryptoPP;
    std::string plaintext;
    std::string ciphertext = encryptedPassword;
    std::string decryptedtext;
    try {
        CBC_Mode<AES>::Decryption decryptor(key, key.size(), iv);
        StringSource ss2(ciphertext, true,
                         new StreamTransformationFilter(decryptor,
                                                        new StringSink(decryptedtext)
                         )
        );
    } catch (const CryptoPP::Exception& e) {
        std::cerr << "Decryption Error: " << e.what() << std::endl;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return decryptedtext;
}
