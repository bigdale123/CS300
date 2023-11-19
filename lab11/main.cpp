#include <iostream>
#include <string>
#include "vignere.h"

int main() {
    Vigenere vigenereCipher("WAR");
    std::string originalMessage = "HELLO WORLD";
    
    std::string encryptedMessage = vigenereCipher.encrypt(originalMessage);
    std::cout << "Encrypted: " << encryptedMessage << std::endl;

    std::string decryptedMessage = vigenereCipher.decrypt(encryptedMessage);
    std::cout << "Decrypted: " << decryptedMessage << std::endl;

    bool encrypted = vigenereCipher.isEncrypted(encryptedMessage, decryptedMessage);
    std::cout << "Encrypted: " << (encrypted ? "true" : "false") << std::endl;

    vigenereCipher.setKey("NEWKEY");
    encryptedMessage = vigenereCipher.encrypt(originalMessage);
    decryptedMessage = vigenereCipher.decrypt(encryptedMessage);
    
    encrypted = vigenereCipher.isEncrypted(encryptedMessage, decryptedMessage);
    std::cout << "Encrypted after key change: " << (encrypted ? "true" : "false") << std::endl;

    return 0;
}