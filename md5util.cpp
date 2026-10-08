#include <iostream>
#include <iomanip>
#include <string>
#include <openssl/md5.h>
#include <openssl/evp.h>

using namespace std;


// Function to print the MD5 hash in hexadecimal format
void print_MD5(unsigned char *md, long size = MD5_DIGEST_LENGTH){
    for (int i = 0; i < size; i++){
        cout << hex << setw(2) << setfill('0') << (int)md[i];
    }
    cout << endl;
}

// Function to compute and print MD5 hash of a given string
string computeMD5FromString(const string &str){
    unsigned char result[MD5_DIGEST_LENGTH];
    EVP_Q_digest(NULL, "MD5", NULL, str.c_str(), str.size(), result, NULL);

    cout << "MD5 of '" << str << "' : ";
    print_MD5(result);

    /* 
    The following does not work, because it converts the hash into a binary
    representation not an hexadecimal one

    string sResult(reinterpret_cast<char*>(result));


    return sResult;
    */
    
    stringstream ss;

    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0')
           << static_cast<int>(result[i]);
    }

    return ss.str();
}
