#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void crackPassword(string hashAlgorithm, string attackType, string hash);

void usage () {
    cout << "Invalid arguments, the program needs the following arguments:" << endl;
    cout << "./hashcracker [hashing algorithm] [--dictionary or --bruteforce] [hash]" << endl;
    cout << "supported hashing algorithms are md5 and sha256" << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        usage();
        return 1;
    }

    string hashAlgorithm = string(argv[1]);
    string attackType = string(argv[2]);
    string hash = string(argv[3]);
    cout << "Hash Algorithm: " << hashAlgorithm << endl;
    cout << "Attack type: " << attackType << endl;
    cout << "Hash: " << hash << endl;

    if (hashAlgorithm != "md5" && hashAlgorithm != "sha256") {
        usage();
        return 1;
    }

    crackPassword(hashAlgorithm, attackType, hash);

    return 0;
}
