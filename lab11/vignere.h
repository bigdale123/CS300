#ifndef _vignere_h
#define _vignere_h
#include <iostream>
#include <string>

/**
 * @class Vigenere
 * @brief Class for Vigenere cipher encryption and decryption.
 */
class Vigenere {
public:
    /**
     * @brief Constructor that takes a key as an argument.
     * @param key The key for encryption and decryption.
     */
    Vigenere(std::string key);

    /**
     * @brief Destructor.
     */
    ~Vigenere();

    /**
     * @brief Encrypts a given message using the Vigenere cipher.
     * @param msg The message to be encrypted.
     * @return The encrypted message.
     */
    std::string encrypt(std::string msg);

    /**
     * @brief Decrypts a given message using the Vigenere cipher.
     * @param msg The message to be decrypted.
     * @return The decrypted message.
     */
    std::string decrypt(std::string msg);

    /**
     * @brief Checks if encryption and decryption are consistent.
     * @param encryptedMsg The encrypted message.
     * @param decryptedMsg The decrypted message.
     * @return True if consistent, false otherwise.
     */
    bool isEncrypted(std::string encryptedMsg, std::string decryptedMsg);

    /**
     * @brief Changes the key used for encryption and decryption.
     * @param newKey The new key to be set.
     */
    void setKey(std::string newKey);

private:
    /**
     * @brief The key used for encryption and decryption.
     */
    std::string key;
};
#endif