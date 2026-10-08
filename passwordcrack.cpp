#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

enum AttackType {
    INVALID_TYPE = 0,
    DICTIONARY = 1,
    BRUTEFORCE = 2
};

AttackType resolveAttackType(string input) {
    if(input == "--dictionary") return DICTIONARY;
    if(input == "--bruteforce") return BRUTEFORCE;
    return INVALID_TYPE;
}

string computeMD5FromString(const string &str);

string computeSHA256FromString(const string &str);

void dictionaryAttack(string hashAlgorithm, string hash) {
    string test = hashAlgorithm;

    ifstream ifs("wordlist.txt");
    string content( (istreambuf_iterator<char>(ifs)),
                        (istreambuf_iterator<char>()));


    istringstream f(content);

    string line;    
    while (getline(f, line)) {
        if (hashAlgorithm == "md5") {
            if (computeMD5FromString(line) == hash) {
                cout << "Password/collision found for the following password: " << line << endl;
                return;
            }
        } else {
            if (computeSHA256FromString(line) == hash) {
                cout << "Password/collision found for the following password: " << line << endl;
                return;
            }
        }
    }
    cout << "No collision found in dictionary" << endl;
}

void crackPassword (string hashAlgorithm, string attackType, string hash) {
    switch(resolveAttackType(attackType)) {
        case DICTIONARY:
            dictionaryAttack(hashAlgorithm, hash);
            break;
        case BRUTEFORCE:

            break;
        default:
            cout << "Invalid attack type" << endl;
            break;
    }
}
