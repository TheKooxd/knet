#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <sstream>

#include "crypto/modes.h"
#include "crypto/aes.h"
#include "crypto/filters.h"
using namespace std;
string encryptDecrypt(string toEncrypt) {
    char key[31] = {'K', 'C', 'Q', 'R', 'S', 'H', 'A', 'D', 'N', 'F', 'K', 'I', 'O', 'L', 'M', 'F', 'V', 'C', 'S', 'B', 'V', 'X', 'N', 'C', 'J', 'S', 'T', 'U', 'R', 'Y', 'Q'};
    string output = toEncrypt;
    
    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];
    
    return output;
}

int main(int argc, const char * argv[]){
	cout << "Give string\n";
	string input;
	getline(cin,input);
	string encrypt = encryptDecrypt(input);
	cout << "\n"<< encrypt << "\n";
	cout << "\n"<< encryptDecrypt(encrypt) << "\n";
	main(0,0);
}
