#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Caesar Cipher Encryption Function
string caesarCipherEncrypt(string text, int key) {
    string result = "";

    for (char& ch : text) {
        if (isalpha(ch)) {
            char shifted = 'A' + (toupper(ch) - 'A' + key) % 26;
            result += islower(ch) ? tolower(shifted) : shifted;
        } else {
            result += ch;
        }
    }

    return result;
}

// Caesar Cipher Decryption Function
string caesarCipherDecrypt(string text, int key) {
    return caesarCipherEncrypt(text, 26 - key);
}

// XOR Encryption/Decryption Function
string xorEncryptDecrypt(string text, char key) {
    string result = text;

    for (char& ch : result) {
        ch ^= key;
    }

    return result;
}

int main() {
    char choice;
    string inputFileName, outputFileName, text;
    int key;

    cout << "Select encryption method:" << endl;
    cout << "1. Caesar Cipher" << endl;
    cout << "2. XOR Encryption" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice != '1' && choice != '2') {
        cout << "Invalid choice. Exiting..." << endl;
        return 1;
    }

    cout << "Enter input file name: ";
    cin >> inputFileName;

    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    cout << "Enter output file name: ";
    cin >> outputFileName;

    cout << "Enter encryption key: ";
    cin >> key;

    // Read text from input file
    getline(inputFile, text, '\0');
    inputFile.close();

    string encryptedText, decryptedText;

    // Encrypt text based on user's choice
    if (choice == '1') {
        encryptedText = caesarCipherEncrypt(text, key);
        decryptedText = caesarCipherDecrypt(encryptedText, key);
    } else {
        encryptedText = xorEncryptDecrypt(text, key);
        decryptedText = xorEncryptDecrypt(encryptedText, key);
    }

    // Write encrypted text to output file
    ofstream outputFile(outputFileName);
    if (!outputFile) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    outputFile << "Encrypted Text:\n" << encryptedText << endl;
    outputFile << "Decrypted Text:\n" << decryptedText << endl;
    outputFile.close();

    cout << "Encryption/Decryption completed. Output written to " << outputFileName << endl;

    return 0;
}

