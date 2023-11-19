#include <iostream>
#include <string>
#include "vignere.h"

/**
 * @brief Constructor that takes a key as an argument.
 * @param key The key for encryption and decryption.
 */
Vigenere::Vigenere(std::string key) : key(key) {}

/**
 * @brief Destructor.
 */
Vigenere::~Vigenere() {}

/**
 * @brief Encrypts a given message using the Vigenere cipher.
 * @param msg The message to be encrypted.
 * @return The encrypted message.
 */
std::string Vigenere::encrypt(std::string msg) {
    std::string encryptedMsg = msg;
    int keyLength = key.length();

    for (size_t i = 0; i < msg.length(); ++i) {
        if (isalpha(msg[i])) {
            char shift = isupper(msg[i]) ? 'A' : 'a';
            encryptedMsg[i] = (msg[i] + key[i % keyLength] - shift * 2) % 26 + shift;
        }
    }

    return encryptedMsg;
}

/**
 * @brief Decrypts a given message using the Vigenere cipher.
 * @param msg The message to be decrypted.
 * @return The decrypted message.
 */
std::string Vigenere::decrypt(std::string msg) {
    std::string decryptedMsg = msg;
    int keyLength = key.length();

    for (size_t i = 0; i < msg.length(); ++i) {
        if (isalpha(msg[i])) {
            char shift = isupper(msg[i]) ? 'A' : 'a';
            decryptedMsg[i] = (msg[i] - key[i % keyLength] + 26) % 26 + shift;
        }
    }

    return decryptedMsg;
}

/**
 * @brief Checks if encryption and decryption are consistent.
 * @param encryptedMsg The encrypted message.
 * @param decryptedMsg The decrypted message.
 * @return True if consistent, false otherwise.
 */
bool Vigenere::isEncrypted(std::string encryptedMsg, std::string decryptedMsg) {
    return decrypt(encryptedMsg) == decryptedMsg;
}

/**
 * @brief Changes the key used for encryption and decryption.
 * @param newKey The new key to be set.
 */
void Vigenere::setKey(std::string newKey) {
    key = newKey;
}