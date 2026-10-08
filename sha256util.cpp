#include <iostream>
#include <iomanip>
#include <string>
#include <openssl/sha.h>
#include <openssl/evp.h>

using namespace std;


// Function to print the MD5 hash in hexadecimal format
void print_SHA256(unsigned char *md, long size = SHA256_DIGEST_LENGTH){
    for (int i = 0; i < size; i++){
        cout << hex << setw(2) << setfill('0') << (int)md[i];
    }
    cout << endl;
}

// Function to compute and print MD5 hash of a given string
string computeSHA256FromString(const string &str){
    unsigned char result[SHA256_DIGEST_LENGTH];
    EVP_Q_digest(NULL, "SHA256", NULL, str.c_str(), str.size(), result, NULL);

    cout << "MD5 of '" << str << "' : ";
    print_SHA256(result);
    
    stringstream ss;

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0')
           << static_cast<int>(result[i]);
    }

    return ss.str();
}
