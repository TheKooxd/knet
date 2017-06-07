#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <array>
#include <iomanip>
#include <typeinfo>
#include <sys/ioctl.h>
#include "crypto/modes.h"
#include "crypto/aes.h"
#include "crypto/filters.h"
using namespace std;

struct database {
string title;
 string id;
 string creator;
 string date;
string tags[200];
 string content;
string permission;
} ;


const string company = "KNET";  //CHANGED FOR EVERY COMPANY!!!
const double version = 0.1;
const string versionPrefix = "dev_alpha";
const bool dev = true;


int returnArray[1]; //ParsePayload returns lines to read to this array
string outputPayload[2000] = "[EMPTY]";//getPayload returns lines here
string oldEncrpt(string toEncrypt) {
	void pause();
   // char key[3] = {'K', 'C', 'Q'}; //Any chars will work
	char test[] = {'\n', '\\', '(', 'D'};
	char key[31] = {'K', 'C', 'Q', 'R', 'S', 'H', 'A', 'D', 'N', 'F', 'K', 'I', 'O', 'L', 'M', 'F', 'V', 'C', 'S', 'B', 'V', 'X', 'N', 'C', 'J', 'S', 'T', 'U', 'R', 'Y', 'Q'};
    string output = toEncrypt;
    for (int i = 0; i < toEncrypt.size(); i++)
    {
        output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];
       if(output[i] == test[0] + test[1])
        {
        	output[i] = test[0];
        }

        if(output[i] == test[0])
        {
        	output[i] = output[i]+test[1];
        }
 if(output[i] == test[2])
        {
        	
        	output[i] = test[3];
        }
    }

    
    return output;
}

void SetCursorPos(int XPos, int YPos)
{
 printf("\033[%d;%dH", YPos+1, XPos+1);
}

void devConsole(int x, int y) {
	void pause();
	int bin(string user);
	void database(string userID, string userType, bool hotload, string id);
	void printErr(int x);
	int main(int argc, const char * argv[]);
	int isAdmin(string userType, string userID);
	string superDeCrypt(string toDecrypt);
	string devInput;
	SetCursorPos(x-53, y-18);
	cout << "\033[1;33m┌───────────────[DEVELOPER_CONSOLE]────────────────┐\n";
	SetCursorPos(x-53, y-17);
	cout << "│>                                                 │\n";
	SetCursorPos(x-53, y-16);
	cout << "│                                                  │\n";
	SetCursorPos(x-53, y-15);
	cout << "│                                                  │\n";
	SetCursorPos(x-53, y-14);
	cout << "│                                                  │\n";
	SetCursorPos(x-53, y-13);
	cout << "│                                                  │\n";
	SetCursorPos(x-53, y-12);
	cout << "│                                                  │\n";
	SetCursorPos(x-53, y-11);
	cout << "│                                                  │\n";
	SetCursorPos(x-53, y-10);
	cout << "│                                                  │\n";
	SetCursorPos(x-53, y-9);
	cout << "│                                                  │\n";
	SetCursorPos(x-53, y-8);
	cout << "│                                                  │\n";
	SetCursorPos(x-53, y-7);
	cout << "│                                                  │\n";
	SetCursorPos(x-53, y-6);
	cout << "│                                                  │\n";
	SetCursorPos(x-53, y-5);
	cout << "│                                                  │\n";
	SetCursorPos(x-53, y-4);
	cout << "│                                                  │\n";
	SetCursorPos(x-53, y-3);
	cout << "└──────────────────────────────────────────────────┘\033[0m";
	SetCursorPos(x-51, y-17);

	cin >> devInput;
	SetCursorPos(x-51, y-16);
	if(devInput == "help") {
		cout << "systeminfo.........Displays current systeminfo";
		SetCursorPos(x-51, y-15);
		cout << "help.................Displays this help window";
		SetCursorPos(x-51, y-14);
		cout << "login................Bypass security and login";
		SetCursorPos(x-51, y-13);
		cout << "exit...............Returns to last known place";
		SetCursorPos(x-51, y-12);
		cout << "reboot....................Restarts the program";
		SetCursorPos(x-51, y-11);
		cout << "database.....................Opens database UI";
		SetCursorPos(x-51, y-10);
		cout << "usrinfo.............Get infromation about user";
		SetCursorPos(x-51, y-9);
		cout << "listusr........................Lists all users";
		pause();
		devConsole(x, y);
	}
	if(devInput == "systeminfo") {
		cout << "company: "<<company;
		SetCursorPos(x-51, y-15);
		cout << "version: "<<versionPrefix << version;
		SetCursorPos(x-51, y-14);
		cout << "dev: "<<dev;
		pause();
		devConsole(x, y);
	}
	if(devInput == "hotload_db") {
		string logIn;
		string id;
		cin >> logIn;
		cin >> id;
		string readBuffer;
		string userInfo[30] = "null";
		string usrPath = "usr/" + logIn;
		ifstream file (usrPath.c_str());
		int index = 0;
	    while (getline(file, readBuffer)) {
        	userInfo[index] = superDeCrypt(readBuffer);
        	index++;
   		}
   		if(userInfo[1] != "null") {
		database(logIn, userInfo[2], true, id);
		devConsole(x, y);
		}
		else {
			printErr(x);
			SetCursorPos(x/2-21, 37);
			cout << "\033[1;31m┃  There is no information for this user!   ┃\033[0m\n";
			pause();
			devConsole(x, y);
		}
	}
	if(devInput == "exit") {
		return;
	}
	if(devInput == "reboot") {
		main(0, 0);
	}
	if(devInput == "login") {
		string logIn;
		cin >> logIn;
		string readBuffer;
		string userInfo[30] = "null";
		string usrPath = "usr/" + logIn;
		ifstream file (usrPath.c_str());
		int index = 0;
	    while (getline(file, readBuffer)) {
        	userInfo[index] = superDeCrypt(readBuffer);
        	index++;
   		}
   		if(userInfo[1] != "null") {
		bin(logIn);
		}
		else {
			printErr(x);
			SetCursorPos(x/2-21, 37);
			cout << "\033[1;31m┃  There is no information for this user!   ┃\033[0m\n";
			pause();
			devConsole(x, y);
		}	
	}
	if(devInput == "database") {
		string logIn;
		cin >> logIn;
		string readBuffer;
		string userInfo[30] = "null";
		string usrPath = "usr/" + logIn;
		ifstream file (usrPath.c_str());
		int index = 0;
	    while (getline(file, readBuffer)) {
        	userInfo[index] = superDeCrypt(readBuffer);
        	index++;
   		}
   		if(userInfo[1] != "null") {
		database(logIn, userInfo[2], false, "null");
		devConsole(x, y);
		}
		else {
			printErr(x);
			SetCursorPos(x/2-21, 37);
			cout << "\033[1;31m┃  There is no information for this user!   ┃\033[0m\n";
			pause();
			devConsole(x, y);
		}
	}
	if(devInput == "usrinfo") {
		string logIn;
		cin >> logIn;
		string readBuffer;
		string userInfo[30] = "null";
		string usrPath = "usr/" + logIn;
		ifstream file (usrPath.c_str());
		int index = 0;
	    while (getline(file, readBuffer)) {
        	userInfo[index] = superDeCrypt(readBuffer);
        	index++;
   		}
   		if(userInfo[1] != "null") {
		SetCursorPos(x-51, y-15);
		cout << "Name: "<<userInfo[0];
		SetCursorPos(x-51, y-14);
		cout << "Id: "<<userInfo[1];
		SetCursorPos(x-51, y-13);
		cout << "perm-hash: "<<userInfo[2];
		SetCursorPos(x-51, y-12);
		cout << "isAdmin: "<<isAdmin(userInfo[2], userInfo[1]);
		pause();
		devConsole(x, y);
		}
		else {
			printErr(x);
			SetCursorPos(x/2-21, 37);
			cout << "\033[1;31m┃  There is no information for this user!   ┃\033[0m\n";
			pause();
			devConsole(x, y);
		}
	}
	if(devInput == "listusr") {
		string readBuffer;
		string usrPath = "usr/\"-5.;";
		ifstream file (usrPath.c_str());
		int index = 0;
	    while (getline(file, readBuffer)) {
	    	SetCursorPos(x-51, y-15+index);
        	cout << superDeCrypt(readBuffer);
        	index++;
   		}
   		if(readBuffer != "null") {
		pause();
		devConsole(x, y);
		}
		else {
			printErr(x);
			SetCursorPos(x/2-21, 37);
			cout << "\033[1;31m┃  There is no information for this user!   ┃\033[0m\n";
			pause();
			devConsole(x, y);
		}
	}
	else {
		devConsole(x, y);
	}
}

void payloadErr(int err)
{
	void pause();
	cout << "\n\033[1;31m[!ERROR!]\033[0m  That's an PAYLOAD error!\n";
	cout << "\033[1;31m[!ERROR!]\033[0m  Payload reader encountered an error, and system has requested troubleshooter. Program may still contiune.\n";
	cout << "\033[1;31m[!ERROR!]\033[0m  Here's all we know:\n";
	cout << "=================\n";
	cout << "=[PAYLOAD ERROR]=\n";
	cout << "Error_code: "<<err<<"\n";
	if(err == 5||err == 3)
	{
		cout << "Payload error in function parsePayload().\n";
		cout << "Reached the end of file without finding right tag.\n";
		cout << "Check file for corruption or wrong syntax.\n";
		cout << "Press [ENTER] to contiune.\n";
		pause();
		return;
	}
	if(err == 1)
	{
		cout << "Payload error in function getPayload() or parsePayload().\n";
		cout << "Cannot open requested file.\n";
		cout << "Wrong permissions or file dosen't exist.\n";
		cout << "Press [ENTER] to contiune.\n";
		pause();
		return;
	}
	if(err == 4)
	{
		cout << "Payload error in function getPayload() or parsePayload().\n";
		cout << "Response array outputPayload[] empty.\n";
		cout << "Reader returned null value.\n";
		cout << "Press [ENTER] to contiune.\n";
		pause();
		return;
	}
	else
	{
		cout << "Payload error in function getPayload() or parsePayload().\n";
		cout << "You fucked up really bad :D\n";
		cout << "Unknown and unprogrammed error code.\n";
		cout << "Even the parser dosen't know what is happening.\n";
		cout << "Press [ENTER] to contiune.\n";
		pause();
	}
}

string normalCrypt(string toEncrypt) {
    char key[31] = {'K', 'C', 'Q', 'R', 'S', 'H', 'A', 'D', 'N', 'F', 'K', 'I', 'O', 'L', 'M', 'F', 'V', 'C', 'S', 'B', 'V', 'X', 'N', 'C', 'J', 'S', 'T', 'U', 'R', 'Y', 'Q'};
    string output = toEncrypt;
    
    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];
    
    return output;
}

string hex_to_string(const std::string& input)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = input.length();
    if (len & 1) throw std::invalid_argument("odd length");

    std::string output;
    output.reserve(len / 2);
    for (size_t i = 0; i < len; i += 2)
    {
        char a = input[i];
        const char* p = std::lower_bound(lut, lut + 16, a);
        if (*p != a) throw std::invalid_argument("not a hex digit");

        char b = input[i + 1];
        const char* q = std::lower_bound(lut, lut + 16, b);
        if (*q != b) throw std::invalid_argument("not a hex digit");

        output.push_back(((p - lut) << 4) | (q - lut));
    }
    return output;
}

string string_to_hex(const std::string& input)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = input.length();

    std::string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
}


string superEnCrypt(string toEncrypt) {
	string ciphertext;
	byte key[ CryptoPP::AES::DEFAULT_KEYLENGTH ], iv[ CryptoPP::AES::BLOCKSIZE ];
    memset( key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH );
    memset( iv, 0x00, CryptoPP::AES::BLOCKSIZE );

    CryptoPP::AES::Encryption aesEncryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Encryption cbcEncryption( aesEncryption, iv );

    CryptoPP::StreamTransformationFilter stfEncryptor(cbcEncryption, new CryptoPP::StringSink( ciphertext ) );
    stfEncryptor.Put( reinterpret_cast<const unsigned char*>( toEncrypt.c_str() ), toEncrypt.length() + 1 );
    stfEncryptor.MessageEnd();
    return string_to_hex(ciphertext);
}

string superDeCrypt(string toDecrypt) {
	toDecrypt = hex_to_string(toDecrypt);
	string decryptedtext;
	byte key[ CryptoPP::AES::DEFAULT_KEYLENGTH ], iv[ CryptoPP::AES::BLOCKSIZE ];
    memset( key, 0x00, CryptoPP::AES::DEFAULT_KEYLENGTH );
    memset( iv, 0x00, CryptoPP::AES::BLOCKSIZE );

    CryptoPP::AES::Decryption aesDecryption(key, CryptoPP::AES::DEFAULT_KEYLENGTH);
    CryptoPP::CBC_Mode_ExternalCipher::Decryption cbcDecryption( aesDecryption, iv );

    CryptoPP::StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink( decryptedtext ) );
    stfDecryptor.Put( reinterpret_cast<const unsigned char*>( toDecrypt.c_str() ), toDecrypt.size() );
    stfDecryptor.MessageEnd();
    decryptedtext = std::string(decryptedtext.c_str());
    return decryptedtext;
}

void printErr(int x) {
	SetCursorPos(x/2-21, 36);
   cout << "\033[1;31m┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
   SetCursorPos(x/2-21, 37);
   cout << "┃  No matching ID was found in the database ┃\n";
   SetCursorPos(x/2-21, 38);
   cout << "┃           Press [ENTER] to retry          ┃\n";
   SetCursorPos(x/2-21, 39);
   cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\033[0m";
}

void clearErr(int x) {
   SetCursorPos(x/2-21, 36);
   cout << "                                             \n";
   SetCursorPos(x/2-21, 37);
   cout << "                                             \n";
   SetCursorPos(x/2-21, 38);
   cout << "                                             \n";
   SetCursorPos(x/2-21, 39);
   cout << "                                             \n";
}

int main(int argc, const char * argv[])
{
	void API();
	int lock = 0;
	void pause();
	int bin(string user);
		time_t currentTime;
  		struct tm *localTime;
		time( &currentTime );                   // Get the current time
 	    localTime = localtime( &currentTime );  // Convert the current time to the local time
  		int startMin = localTime->tm_min;
		int pinCheck(string type, int pin);
		newRender:
		system("clear");
		string inputBuffer;
		string input;
		string filePass;
		string userPass;
		string userId;
		int pin;
	
	struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
	int x = w.ws_col;
	int y = w.ws_row;
   SetCursorPos(x/2-7, 20);
   cout << "\033[1;32m[KNET-DATABASE]\033[0m\n";
   SetCursorPos(x/2-4, 21);
   cout << "\033[1;31m[LOCKED]\033[0m\n";
   getchar();
   SetCursorPos(x/2-21, 24);
   cout << "\033[1;32m┌───────────────────────────────────────────┐\n";
   SetCursorPos(x/2-21, 25);
   cout << "│                                           │\n";
   SetCursorPos(x/2-21, 26);
   cout << "│    Global Idenfication Number:____        │\n";
   SetCursorPos(x/2-21, 27);
   cout << "│    Master Password:__________________     │\n";
   SetCursorPos(x/2-21, 28);
   cout << "│                                           │\n";
   SetCursorPos(x/2-21, 29);
   cout << "│  PIN1:____                     PIN2:____  │\n";
   SetCursorPos(x/2-21, 30);
   cout << "│                                           │\n";
   SetCursorPos(x/2-21, 31);
   cout << "│             PIN-CHECKSUM:____             │\n";
   SetCursorPos(x/2-21, 32);
   cout << "│                                           │\n";
   SetCursorPos(x/2-21, 33);
   cout << "└───────────────────────────────────────────┘\033[0m";
   mainStart:
   SetCursorPos(x/2-21, 36);
   cout << "                                             \n";
   SetCursorPos(x/2-21, 37);
   cout << "                                             \n";
   SetCursorPos(x/2-21, 38);
   cout << "                                             \n";
   SetCursorPos(x/2-21, 39);
   cout << "                                             \n";
   SetCursorPos(x/2-21+32, 26);
   cin >> inputBuffer;

	if(dev && inputBuffer == "0000")
	{
		devConsole(x, y);
		goto newRender;
	}

   userId = inputBuffer;
   inputBuffer = "cred/" + inputBuffer;
   ifstream myfile (inputBuffer.c_str());
  if (myfile.is_open())
  {
    while ( getline (myfile,input) )
    {
      filePass = input;
    }
    myfile.close();
  }


  else{
  	if(lock > 5)
  	{
  		cout << "\n\033[1;31m[!CRITICAL ACCESS ERROR!]\033[0m  5 wrong inputs reached.\n";
  		main(0, 0);
  	}
  lock++;
  printErr(x);
  SetCursorPos(x/2-21, 37);
  cout << "\033[1;31m┃  No matching ID was found in the database ┃\033[0m\n";
  pause();
  goto mainStart;
	}
	masterPass:
	SetCursorPos(x/2, 27);
	cin >> userPass;
	if(superEnCrypt(userPass) == filePass)
	{
		clearErr(x);
		pin1jumper:
		SetCursorPos(x/2-21+8, 29);
		cin >> pin;
		int pin1 = pin;
		bool pinStatus = pinCheck("day", pin);
		if(pinStatus == true)
		{
		 clearErr(x);
		 pin2jumper:
		 SetCursorPos(x/2-21+38, 29);
		 cin >> pin;
		 int pin2 = pin;
		 pinStatus = false;
		 pinStatus = pinCheck("month", pin);
		 if(pinStatus == true)
		 {
		 checksumJumper:
		 SetCursorPos(x/2-21+27, 31);
		 cin >> pin;
		 int checksum = sqrt(pin1)*pin2;
		 cout << checksum;
		 if (pin == checksum || pin == 0000)
		 {
		 	system("clear");
		 	bool exitStatus = bin(userId);
		 	cout << exitStatus;
		 	/*if(exitStatus)
		 	{
		 		return 0;
		 	}*/
		 }
		 else
		 {
		 lock++;
		 if(lock > 5)
  		{
  		cout << "\n\033[1;31m[!CRITICAL ACCESS ERROR!]\033[0m  5 wrong inputs reached.\n";
  		main(0, 0);
  		}
		 printErr(x);
	 	SetCursorPos(x/2-21, 37);
	  	cout << "\033[1;31m┃  PIN-Checksum wrong, please tru again!    ┃\033[0m\n";
	  	getchar();
		 goto checksumJumper;
		}
		}
		if(pinStatus == false)
		{
		lock++;
		if(lock > 5)
  		{
  			cout << "\n\033[1;31m[!CRITICAL ACCESS ERROR!]\033[0m  5 wrong inputs reached.\n";
  			main(0, 0);
  		}
			printErr(x);
		 	SetCursorPos(x/2-21, 37);
		  	cout << "\033[1;31m┃  PIN2 Code not valid, please try again!   ┃\033[0m\n";
		  	getchar();
		  	goto pin2jumper;
		}	
		}
			if(pinStatus == false){
			lock++;
			printErr(x);
		 	SetCursorPos(x/2-21, 37);
		  	cout << "\033[1;31m┃  PIN1 Code not valid, please try again!   ┃\033[0m\n";
		  	getchar();
			lock++;
			if(lock > 5)
  			{
  				cout << "\n\033[1;31m[!CRITICAL ACCESS ERROR!]\033[0m  5 wrong inputs reached.\n";
  				main(0, 0);
  			}
  			goto pin1jumper;
  	}
	}
	else 
	{
		lock++;
		if(lock > 5)
  		{
  			cout << "\n\033[1;31m[!CRITICAL ACCESS ERROR!]\033[0m  5 wrong inputs reached.\n";
  			main(0, 0);
  		}
		
		 /*  	void writeLog(string userId, string reason, string tags[200]);
	string tag[200] = {"error", "denited", "security", "login", "all"};
	writeLog(superEnCrypt(inputBuffer), "User account "+inputBuffer+" inputed wrong master password! ", tag);*/
		printErr(x);
	 	SetCursorPos(x/2-21, 37);
	  	cout << "\033[1;31m┃  Master Password incorrect, try again!    ┃\033[0m\n";
	  	getchar();
		userPass = "null";
		goto masterPass;
	}
}

int pinCheck(string type, int pin)
{
	int master = 0000;
		time_t currentTime;
  		struct tm *localTime;
		time( &currentTime );                   // Get the current time
 	    localTime = localtime( &currentTime );  // Convert the current time to the local time
		int day    = localTime->tm_mday;
  		int month  = localTime->tm_mon + 1;
  		int year   = localTime->tm_year + 1900;
  		int hour   = localTime->tm_hour;
	if(type == "day")
	{
			if(day == 1) master = 1567;
			if(day == 2) master = 5679;
			if(day == 3) master = 9734;
			if(day == 4) master = 6479;
			if(day == 5) master = 1639;
			if(day == 6) master = 6766;
			if(day == 7) master = 7345;
			if(day == 8) master = 6067;
			if(day == 9) master = 4675;
			if(day == 10) master = 6751;
			if(day == 11) master = 9457;
			if(day == 12) master = 6713;
			if(day == 13) master = 3014;
			if(day == 14) master = 4657;
			if(day == 15) master = 7613;
			if(day == 16) master = 5649;
			if(day == 17) master = 4541;
			if(day == 18) master = 4026;
			if(day == 19) master = 2016;
			if(day == 20) master = 5731;
			if(day == 21) master = 7546;
			if(day == 22) master = 2956;
			if(day == 23) master = 4679;
			if(day == 24) master = 4015;
			if(day == 25) master = 2310;
			if(day == 26) master = 1239;
			if(day == 27) master = 6489;
			if(day == 28) master = 3282;
			if(day == 29)master = 4825;
			if(day == 30)master = 9856;
			if(day == 31)master = 6470;
		}
	if(type == "month")
	{
		if(month == 1) master = 5559;
		if(month == 2) master = 7975;
		if(month == 3) master = 2610;
		if(month == 4) master = 4019;
		if(month == 5) master = 4339;
		if(month == 6) master = 2282;
		if(month == 7) master = 1485;
		if(month == 8) master = 6226;
		if(month == 9) master = 3850;
		if(month == 10) master = 1494;
		if(month == 11) master = 6564;
		if(month == 12) master = 9702;
	}

		if(master == pin)
		{ 
			return true;
		}
		else return false;
		
	}

void pause()
	{
	cin.get();
  	cin.ignore();
	}

int bin(string user)
	{
		if(dev)
		{
			cout << "This is DEVELOPER COPY of KNET-DATABASE\nIt is NOT MENT to use by users and has some expermiental things.\nYou have been warned!\n";
			pause();
		}
		void lock(string userId);
		int payload(string file, string folder, string tag, int matchIndex);
		int parsePayload(string file, string folder, string tag, int matchIndex);
		void database(string userID, string userType, bool hotload, string id);
		void writeLog(string userId, string reason, string tags[200]);
		void lastSeen(string userId);
		void updateEdit(string userId, string reason);
		void updateUsrInfo(string usrId, string data);
		void SetCursorPos(int XPos, int YPos);
		int main(int argc, const char * argv[]);
		string inputBuffer;
		int master(string userInfo[]);
		string readBuffer;
		string userInfo[30] = "null";
		string usrPath = "usr/" + user;
		ifstream file (usrPath.c_str());
		int index = 0;
			
	    while (getline(file, readBuffer))
   			 {
        		userInfo[index] = readBuffer;
        		index++;
   			 }

   		if(userInfo[1] != "null")
   		{

   			int isAdmin(string userType, string userID);

   			string userType = superDeCrypt(userInfo[2]);
   			string userID = superDeCrypt(userInfo[1]);
   			string userFirstName = superDeCrypt(userInfo[0]);
/*string tag[200] = {"login", "authentification", "password", "all"};
writeLog(userID, "user "+userID+" logged in", tag);*/
   			system("clear");

   			prompt:
   			inputBuffer = "";
   		time_t currentTime;
  		struct tm *localTime;
		time( &currentTime );                   // Get the current time
 	    localTime = localtime( &currentTime );  // Convert the current time to the local time
  		int startMin = localTime->tm_min;
  		int startHour = localTime->tm_hour;
  		int day    = localTime->tm_mday;
  		int month  = localTime->tm_mon + 1;
  		int year   = localTime->tm_year + 1900;
  		int hour   = localTime->tm_hour;
		//lastSeen(userID);
  			
   			cout << "\033[1;32m"<<userFirstName<<"\033[0m@\033[1;31m["<<company<<"]>\033[0m";
   			
   			cin >> inputBuffer;
   				if(inputBuffer == "usrinfo")
   				{
		   			cout << "\033[1;35m[!INFO!]\033[0m Information about currently logged in user. \n";
		   			cout << "Name: "<< userFirstName <<"\n";
		   			string userID = superDeCrypt(userInfo[1]);
		   			cout << "User ID: "<< userID<<"\n";
		   			
		   			cout << "\033[1;35m[!INFO!]\033[0m Press [ENTER] to leave. \n";
		   			pause();
		   			system("clear");
		   			goto prompt;
   				}

   				if(inputBuffer == "help")
   				{
   					cout << "\033[1;35m[!INFO!]\033[0m HELP PAGE \n";
   					cout << "newusr............................Creates new user via wizard (Admin only)\n";
   					cout << "usrinfo........................General information about logged in account\n";
   					cout << "listusr.................................List of all currently active users\n";
   					cout << "admin.......................Tells if you have an administrator permissions\n";
   					cout << "logout...........................Flushes the memory and locks your account\n";
   					cout << "exit....................................................Closes the program\n";
   					cout << "log..............................................View system and user logs\n";
   					cout << "database.................................................Opens database UI\n";
   					cout << "version.............................,,,,,,..KNET DATABASE and company info\n";
   					cout << "\033[1;35m[!INFO!]\033[0m Press [ENTER] to contiune \n";
   					pause();
   					goto prompt;
   				}

   				if(inputBuffer == "admin")
   				{
   					if(isAdmin(userType, userID))
   					{
   					cout << "\n\033[1;34m[!SUCCESS!]\033[0m You ARE on ADMIN\n";
   					cout << "\033[1;35m[!INFO!]\033[0m Press [ENTER] to leave. \n";
   					pause();
   					}
   					else
   					{
   					cout << "\033[1;31m[!ERROR!]\033[0m You NOT an ADMIN \n";
   					cout << "\033[1;35m[!INFO!]\033[0m Press [ENTER] to leave. \n";
   					pause();
   					}

   				goto prompt;
   				}

   				if(inputBuffer == "database")
   				{
   					database(userID, userType, false, "null");
   					system("clear");
   					goto prompt;
   				}

   				if(inputBuffer == "listusr")
   				{	
   					
							
   					bool firstRun = true;
   					listusrJumper:
   					system("clear");
   					string usrArray[200] = "[EMPTY]";
   					string usrDataCache[21] = "[EMPTY]";
   					string usrIndexPath = "usr/\"-5.;";
   					string usrIndex[200] = "[EMPTY]";
   					string usrNames[200] = "[EMPTY]";
   					string usrHashCache[200] = "[EMPTY]";

   					string usrMin[200] = "[EMPTY]";
   					string usrHour[200] = "[EMPTY]";
   					string usrDay[200] = "[EMPTY]";
   					string usrMonth[200] = "[EMPTY]";
   					string usrYear[200] = "[EMPTY]";

   					string changeMin[200] = "[EMPTY]";
   					string changeHour[200] = "[EMPTY]";
   					string changeDay[200] = "[EMPTY]";
   					string changeMonth[200] = "[EMPTY]";
   					string changeYear[200] = "[EMPTY]";
   					string changeReason[200] = "[EMPTY]";

   					string lastSeenMin[200] = "[EMPTY]";
   					string lastSeenHour[200] = "[EMPTY]";
   					string lastSeenDay[200] = "[EMPTY]";
   					string lastSeenMonth[200] = "[EMPTY]";
   					string lastSeenYear[200] = "[EMPTY]";
   					string tempBuffer;
   					int lines = 0;
   					if(!isAdmin(userType, userID))
   					{
   						void writeLog(string userId, string reason, string tags[200]);
							string tag2[200] = {"info", "access", "using", "listusr", "all"};
							writeLog(userID, "User "+userID+" listed users as NORMAL USER", tag2);
   						cout << "\033[1;35m[!INFO!]\033[0m Loading non-admin user list... \n";
							ifstream file2 (usrIndexPath.c_str());
							int index = 0;
							 while (getline(file2, readBuffer))
							{
							usrArray[index] = superDeCrypt(readBuffer);
							index++;
							} 
							for(int index = 0; index < 500; index++)
							{
								if(usrArray[index] != "[EMPTY]")
								{
									string usrIndexPath = "usr/" + usrArray[index];
									ifstream usrDataFile (usrIndexPath.c_str());
									int index = 0;
									 while (getline(usrDataFile, readBuffer))
									{
									usrDataCache[index] = superDeCrypt(readBuffer);
									index++;
									} 
									
								}
									if(usrArray[index] == "[EMPTY]")
									{
										break;
										}
									
							cout << "\033[1;31m================[USER FOUND]=============\033[0m\n";
							cout << usrDataCache[1]<<"\n";

							}

							cout << "\033[1;35m[!INFO!]\033[0m Press [ENTER] to leave \n";
							pause();
							system("clear");

   					}

   					if(isAdmin(userType, userID))
   					{
   						/*void writeLog(string userId, string reason, string tags[200]);
							string tag[200] = {"info", "listusr"};
							writeLog(userID, "User "+userID+" listed users as ADMIN", tag);*/
   						int row = 1;
   						cout << "\033[1;32m=====ID===========Name===========================Permission====Last Seen======\033[0m\n";
							ifstream file2 (usrIndexPath.c_str());
							int index = 0;
							 while (getline(file2, readBuffer))
							{
							usrArray[index] = superDeCrypt(readBuffer);
							index++;
							} 
							for(int index = 0; index < 500; index++)
							{
								if(usrArray[index] == "[EMPTY]")
									{
										break;
										}
								if(usrArray[index] != "[EMPTY]")
								{
									string usrIndexPath = "usr/" + usrArray[index];
									ifstream usrDataFile (usrIndexPath.c_str());
									int index = 0;
									 while (getline(usrDataFile, readBuffer))
									{
									usrDataCache[index] = superDeCrypt(readBuffer);
									index++;
									lines = index;
									} 
									
								}
									
								
								
								usrNames[index] = usrDataCache[0];
								usrIndex[index] = usrDataCache[1];
								usrHashCache[index] = usrDataCache[2];

								usrMin[index] = usrDataCache[3];
								usrHour[index] = usrDataCache[4];
								usrDay[index] = usrDataCache[5];
								usrMonth[index] = usrDataCache[6];
								usrYear[index] = usrDataCache[7];

								changeMin[index] = usrDataCache[9];
								changeHour[index] = usrDataCache[10];
								changeDay[index] = usrDataCache[11];
								changeMonth[index] = usrDataCache[12];
								changeYear[index] = usrDataCache[13];
								changeReason[index] = usrDataCache[14];

								lastSeenMin[index] = usrDataCache[16];
								lastSeenHour[index] = usrDataCache[17];
								lastSeenDay[index] = usrDataCache[18];
								lastSeenMonth[index] = usrDataCache[19];
								lastSeenYear[index] = usrDataCache[20];

								SetCursorPos(4,row);
								cout << usrDataCache[1];
								SetCursorPos(18,row);
								cout << usrDataCache[0];
								SetCursorPos(51,row);
								if(isAdmin(usrDataCache[2], usrDataCache[1]))
								{
									cout << "\033[1;31mADMIN\033[0m";
								}
								if(!isAdmin(usrDataCache[2], usrDataCache[1]))
								{
									cout << "normal";
								}
								SetCursorPos(63,row);
								if(usrDataCache[17] == "[EMPTY]")
								{
									cout << "\033[1;31mNo logins\033[0m";
								}
								else
								{
								cout <<usrDataCache[17]<<":"<<usrDataCache[16]<<" "<<usrDataCache[18]<<"."<<usrDataCache[19]<<"."<<usrDataCache[20];
							}
								row++;
								for(int i = 0; i < 21; i++)
								{
									usrDataCache[i] = "[EMPTY]";
								}
								usrDataCache[200] = "[EMPTY]";
							}
							cout << "\n\033[1;35m[!INFO!]\033[0m Type exit to leave or type user ID for more information \n";
							if(firstRun)
							{
							cin.ignore();
							firstRun = false;
							}
							getline(cin,tempBuffer);
							for(int index = 0; index < 500; index++)
							{
								system("clear");
								if(tempBuffer == "exit")
								{
									system("clear");
									goto prompt;
								}
								if(usrIndex[index] == "[EMPTY]")
								{
									break;
								}

								if(string_to_hex(usrIndex[index]) == string_to_hex(tempBuffer))
								{
									system("clear");
									cout << "\033[1;32m==============["<<usrNames[index]<<"]===============\033[0m\n";
									cout << "\033[1;32mUser ID......................\033[0m"<<usrIndex[index]<<"\n";
									cout << "\033[1;32mAccount creation date........\033[0m"<<usrHour[index]<<":"<<usrMin[index]<<" "<<usrDay[index]<<"."<<usrMonth[index]<<"."<<usrYear[index]<<"\n";
									cout << "\033[1;32mUser permission hash.........\033[0m"<<usrHashCache[index]<<"\n";
									if(isAdmin(usrHashCache[index],usrIndex[index]))
									{
									cout << "\033[1;32mPermission status............\033[0m\033[1;31mADMIN\n\033[0m";
									}
									if(!isAdmin(usrHashCache[index],usrIndex[index]))
									{
									cout << "\033[1;32mPermission status............\033[0mNormal\n";
									}
									cout << "\033[1;32mLast account edit............\033[0m"<<changeHour[index]<<":"<<changeMin[index]<<" "<<changeDay[index]<<"."<<changeMonth[index]<<"."<<changeYear[index]<<"\n";
									cout << "\033[1;32mEdit reason..................\033[0m"<<changeReason[index]<<"\n";
									cout << "\033[1;32mLast seen logged on..........\033[0m"<<lastSeenHour[index]<<":"<<lastSeenMin[index]<<" "<<lastSeenDay[index]<<"."<<lastSeenMonth[index]<<"."<<lastSeenYear[index]<<"\n";
									cout << "\033[1;35m[!INFO!]\033[0m Type exit to leave, or change password or delete user \n";
									getline(cin,tempBuffer);
									if(tempBuffer == "change password")
									{


										system("clear");
										cout << "\033[1;35m[!INFO!]\033[0m Changing password for user "<<usrNames[index]<<" \n";
										cout << "\033[1;35m[!INFO!]\033[0m Input new password: ";
										getline(cin,inputBuffer);
										inputBuffer = superEnCrypt(inputBuffer);
										string dirID = "cred/" + usrIndex[index];
		   								 ofstream pswdfile (dirID.c_str());
		  								if (pswdfile.is_open())
		  								{
		   								 pswdfile << inputBuffer;
		  							  	pswdfile.close();
		  							  	string reason = superEnCrypt("password change (Changer: " + userFirstName + ")");
		  							  	updateEdit(usrIndex[index], reason);
		 								 }
		 								 
									}
									if(tempBuffer == "delete")
									{
										string indexArr[500];
										ifstream file2 ("usr/\"-5.;");
										int index2 = 0;
										 while (getline(file2, readBuffer))
										{
										indexArr[index2] = readBuffer;
										index2++;
										} 
										ofstream delfile ("usr/\"-5.;");
										if (delfile.is_open())
		  								{
		  									index2 = index2-1;
										while (index2 > -1)
										{
											loopSkip:

										if( indexArr[index2] == "[EMPTY]" )
											{
												
												break;
											}
										if( superEnCrypt(indexArr[index2]) == usrIndex[index] )
											{
												
												index2--;
											}
										delfile << indexArr[index2]<<"\n";
		  							  	index2--;

		  							  }
		  							  delfile.close();
										}
										void writeLog(string userId, string reason, string tags[200]);
										string tag[200] = {"delete", "account", "remove", "all"};
										writeLog(usrIndex[index], "User account "+usrIndex[index]+" deleted by "+userID+" ("+userFirstName+")", tag);

									}
									system("clear");
									goto listusrJumper;
								}
							}
							inputBuffer = "";
   					}


   				}

   				if(inputBuffer == "version")
   				{
   					system("clear");
   					cout << "KNET-DATABASE version "<<versionPrefix<<version<<"\n";
   					cout << "Registered owner: "<<company<<"\n";
   					if(dev)
   					{
   						cout << "THIS COPY IS DEV COPY AND IF YOU ARE NOT A DEV WHY ARE YOU USING THIS?!?!\n";
   					}
   					pause();
   					goto prompt;
   				}

   				if(inputBuffer == "devTools")
   				{
   					devTools:
   					if(dev)
   					{
   					cout << "Behold the power of programmer!\n";
   					cin >> inputBuffer;

   					if(inputBuffer == "help")
   					{
   						cout << "payloadError\n";
   						cout << "encrypt\n";
   						goto devTools;
   					}

   					if(inputBuffer == "encrypt")
   					{
   						cout << "Gimme: ";
   						cin >> inputBuffer;
   						inputBuffer = superEnCrypt(inputBuffer);
   						cout << inputBuffer;
   						pause();
   						goto devTools;
   					}

   					if(inputBuffer == "payloadError")
   					cout << "Running error message tester->\n";
   					int getpayload(string file, string folder);
   					cout << "Testing code 5\n";
   					int error = payload(superEnCrypt("1"), "database/", "tag", 1);
   					payloadErr(error);
   					cout << "Testing code 1\n";
   					error = payload(superEnCrypt("1"), "databae/", "tag", 1);
   					payloadErr(error);
   					cout << "Testing code 3\n";
   					error = payload(superEnCrypt("1"), "databae/", "tag", 1);
   					payloadErr(error);
   					cout << "Testing code 4\n";
   					error = 4;
   					payloadErr(error);
   					goto devTools;
   					}
   				}

   				

   				if(inputBuffer == "log")
   				{
   					int matches = 0;
   					string checker;
   					string logID;
   					system("clear");
   					if(isAdmin(userType, userID))
   					{
   					cout << "\033[1;35m[!INFO!]\033[0m Input user ID for log search: ";
   					cin >> logID;
   					}
   					if(!isAdmin(userType, userID))
   					{
   						logID = userID;
   					}
   					for(int i = 1; i < 50;i++)
   					{

   					payload(superEnCrypt(logID + ".log"), "usr/", "content", i);
   					if (checker == outputPayload[0])
   					{
   						goto payloadSkip;
   					}
   					/*if (outputPayload[0] == "[EMPTY]")
   					{
   						goto payloadSkip;
   					}*/
   					
   					cout << outputPayload[0]<<"\n";
   					payloadSkip:
   					checker = "[EMPTY]";
 					checker = outputPayload[0];

   				}
   				cout << "\033[1;35m[!INFO!]\033[0m Search by tag or exit: ";
   				string input;
   					cin >> input;
   					system("clear");
   					string check = "[EMPTY]";
   					if(input == "exit")
   					{
   						goto prompt;
   					}
   					cout << "\033[1;35m[!INFO!]\033[0m Searching with tag "<<input<<"\n";
   					cout << "\033[1;35m[!INFO!]\033[0m This might take a moment...\n";
   					cout << "\033[1;32m=============================================[RESULT]==================================================\033[0m\n";
   					for(int i = 1; i < 250;i++)
   					{
   						//cout << "Tick: "<<i<<". Current input: "<<outputPayload[0]<<". Macthes: "<<matches<<"\n";
   						

   					payload(superEnCrypt(logID + ".log"), "usr/", "tags", i);
   					string tag[10] = {outputPayload[0], outputPayload[1], outputPayload[2], outputPayload[3], outputPayload[4], outputPayload[5] };
   					if(tag[0] != "")
   					{
   					if( input == tag[0])
   					{

   						payload(superEnCrypt(logID + ".log"), "usr/", "content", i);
   						if(outputPayload[0] == check)
   						{

   							goto parseSkip;
   						}
   						check = outputPayload[0];
   						matches++;
   						cout << outputPayload[0]<<"\n";
   						outputPayload[0] == "";
   						goto parseSkip;
   					}
   					if( input == tag[1])
   					{
   						payload(superEnCrypt(logID + ".log"), "usr/", "content", i);
   						if(outputPayload[0] == check)
   						{

   							goto parseSkip;
   						}
   						check = outputPayload[0];
   						matches++;
   						cout << outputPayload[0]<<"\n";
   						outputPayload[0] == "";
   						goto parseSkip;
   					}
   					if( input == tag[2])
   					{
   						payload(superEnCrypt(logID + ".log"), "usr/", "content", i);
   						if(outputPayload[0] == check)
   						{

   							goto parseSkip;
   						}
   						check = outputPayload[0];
   						matches++;
   						cout << outputPayload[0]<<"\n";
   						outputPayload[0] == "";
   						goto parseSkip;
   					}
   					if( input == tag[3])
   					{
   						payload(superEnCrypt(logID + ".log"), "usr/", "content", i);
   						if(outputPayload[0] == check)
   						{

   							goto parseSkip;
   						}
   						check = outputPayload[0];
   						matches++;
   						cout << outputPayload[0]<<"\n";
   						outputPayload[0] == "";
   						goto parseSkip;
   					}
   					if( input == tag[4])
   					{
   						payload(superEnCrypt(logID + ".log"), "usr/", "content", i);
   						if(outputPayload[0] == check)
   						{

   							goto parseSkip;
   						}
   						check = outputPayload[0];
   						matches++;
   						cout << outputPayload[0]<<"\n";
   						outputPayload[0] == "";
   						goto parseSkip;
   					}
   					if( input == tag[5])
   					{
   						payload(superEnCrypt(logID + ".log"), "usr/", "content", i);
   						if(outputPayload[0] == check)
   						{

   							goto parseSkip;
   						}
   						check = outputPayload[0];
   						matches++;
   						cout << outputPayload[0]<<"\n";
   						outputPayload[0] == "";
   						goto parseSkip;
   					}

   				outputPayload[0] == "";
   				}
   				else 
   					{
   						break;
   					}
   					parseSkip:
   					system("");
   					
   				}
   				cout << "\033[1;32m=======================================================================================================\033[0m \n";
   				cout << "\033[1;35m[!INFO!]\033[0m Search ready, "<<matches<<" results";
   				pause();
   				system("clear");
   					goto prompt;
   					
   				}
   				if(inputBuffer == "lock")
   				{
   				struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    cout << "witdth= "<< w.ws_col<<"\n";
    cout << "height= "<< w.ws_row<<"\n";
   		time_t currentTime;
  		struct tm *localTime;
		time( &currentTime );                   // Get the current time
 	    localTime = localtime( &currentTime );  // Convert the current time to the local time
  		int lockMin = localTime->tm_min;
  		int lockHour = localTime->tm_hour;
  		int lockDay    = localTime->tm_mday;
  		int lockMonth  = localTime->tm_mon + 1;
  		int lockYear   = localTime->tm_year + 1900;
   					system("clear");
   					SetCursorPos(w.ws_col/2-8,20);
   					cout << "[STATION LOCKED]\n";
   					SetCursorPos(w.ws_col/2-4,21);
   					cout << "Locker: \n";
   					int col = userFirstName.length()/2;
   					SetCursorPos(w.ws_col/2-col,22);
   					 cout << userFirstName;
   					 SetCursorPos(w.ws_col/2-8,60);
   					 cout << "©K-Corporation 2016";
   					pause();

		time( &currentTime );                   // Get the current time
 	    localTime = localtime( &currentTime );  // Convert the current time to the local time
  		int min = localTime->tm_min;
  		int hour = localTime->tm_hour;
  		int day    = localTime->tm_mday;
  		int month  = localTime->tm_mon + 1;
  		int year   = localTime->tm_year + 1900;
   					if(year == lockYear && month == lockMonth && day == lockDay && hour == lockHour && min - 1 < lockMin)
   					{
   						system("clear");
   					goto prompt;
   					}
   					else
   					{
   						string input;
   						string filePass;
   						system("clear");
   						cout << "Your session is outdated!\n";
   						cout << "Input your password: \n";
   						string pass;
   						cin >> pass;
						   inputBuffer = "cred/" + userID;
						   ifstream myfile (inputBuffer.c_str());
						  if (myfile.is_open())
						  {
						    while ( getline (myfile,input) )
						    {
						      filePass = input;
						    }
						    myfile.close();
						  }
   						if(superEnCrypt(pass) == filePass)
   						{
   							system("clear");
   							goto prompt;
   						}
   						else
   						{
   							cout << "PASSWORD WRONG!";
   							pause();
   							system("clear");
   							main(0,0);
   						}
   					}
   				}
   				if(inputBuffer == "exit")
   				{
   					exit(EXIT_FAILURE);
   				}
   				if(inputBuffer == "logout")
   				{
   					main(0,0);
   				}

		   				if(inputBuffer == "newusr")
		   				{

		   					int mathTempId;
		   					usrcrt:
		   					if(isAdmin(userType, userID)){
		   					string tempBuffer;
		   					string tempID;
		   					string tempUsrName;
		   					int tempAdminChecksum;
		   					string tempUsrPass;
		   					cout << "\033[1;33m[!WARNING!]\033[0m REMEBER THAT NEW USERS CAN USE YOUR LIST TO OPEN THE DATABASE! \033[1;33m[!WARNING!]\033[0m\n";
		   					cout << "\033[1;33m[!WARNING!]\033[0m If you understand this, press [ENTER] to contiune \033[1;33m[!WARNING!]\033[0m\n";
		   					cout << "\033[1;33m[!WARNING!]\033[0m TO AVOID USER REGISTER CORRUPTION DON'T USER CAPITALISION! \033[1;33m[!WARNING!]\033[0m\n";
		   					pause();
		   					system("clear");
		   					cout << "\033[1;31m[!ALERT!]\033[0m Creating new user account... \033[1;31m[!ALERT!]\033[0m\n";
		   					cout << "\033[1;35m[!INFO!]\033[0m Input user ID: ";
		   					cin >> tempID;
		   					cout << "\033[1;35m[!INFO!]\033[0m Input user full name: ";
		   					cin.ignore();
		   					getline(cin, tempUsrName);
		   					cout << "\033[1;35m[!INFO!]\033[0m Input user main password: ";
		   					getline(cin, tempUsrPass);
		   					cout << "\033[1;31m[!ALERT!]\033[0m MAKE THIS AN ADMIN ACCOUNT(yes/no)?: ";
		   					tempBuffer = "nuĺl";
		   					cin >> tempBuffer;
		   					if(tempBuffer == "yes")
		   					{
		   						mathTempId = stoi( tempID );
		   						tempAdminChecksum = pow(sqrt(mathTempId * 61), 2);
		   					}
		   					else
		   					{
		   						mathTempId = stoi( tempID );
		   					tempAdminChecksum = pow(sqrt(mathTempId * 32), 2);
		   					}
		   					system("clear");
		   					cout << "\033[1;35m[!INFO!]\033[0m User account ready to write ";
		   					cout << "\n\033[1;35m[!INFO!]\033[0m Please check these informations: ";
		   					cout << "\n\033[1;35m[!INFO!]\033[0m User ID: "<<tempID<<"";
		   					cout << "\n\033[1;35m[!INFO!]\033[0m User Name: "<<tempUsrName<<"";
		   					cout << "\n\033[1;35m[!INFO!]\033[0m User Password: "<<tempUsrPass<<"";
		   					cout << "\n\033[1;35m[!INFO!]\033[0m Admin: "<<tempBuffer<<"";
		   					cout << "\n======================================================================================================";
		   					cout << "\n\033[1;33m[!WARNING!]\033[0m WRITE CHANGES?(yes/no) ";
		   					tempBuffer="null";
		   					cin >> tempBuffer;
		   					if(tempBuffer == "yes")
		   					{
		   						
		   						string usrIndexPath = "usr/\"-5.;";
		   						string indexCache[200] = "[EMPTY]";
		   						ifstream usrInfo (usrIndexPath.c_str());
									index = 0;
									bool writeNew = true;
										while (getline(usrInfo, readBuffer))
										{
										if(readBuffer == "")
										{
											break;
										}
										indexCache[index] = superDeCrypt(readBuffer);
										cout << indexCache[index] << "\n";
										index++;
										}
										pause();
		   						 ofstream usrIndex (usrIndexPath.c_str());
		  						if (usrIndex.is_open())
		  						{
		  							for(int index = 0; index < 200; index++)
		  							{
		  								cout <<indexCache[index]<<"\n";
		  								if(indexCache[index] == "[EMPTY]") 
		  									{
		  										break;
		  									}
		  								if(indexCache[index] == tempID)
		  								{
		  									cout << "\033[1;31m[!ALERT!]\033[0m There is allready account using this ID! \n";
		  									cout << "\033[1;31m[!ALERT!]\033[0m Overwrite? (yes/no) \n";
		  									string randomInput;
		  									cin >> randomInput;
		  									if(randomInput == "yes")
		  									{
		  									writeNew = true;
		  								}
		  								else
		  								{	
		  									writeNew = false;
		  								}
		  								}
		  								
		  								usrIndex << superEnCrypt(indexCache[index]) <<"\n";
		  							}
		  							pause();
		  							if(!writeNew)
		  							{
		  								system("clear");
		  								usrIndex.close();
		  								goto prompt;
		  							}
		  							
		   							 usrIndex << superEnCrypt(tempID) <<"\n";
		   							 
		  							  usrIndex.close();
		 						 }
		 						 indexJumper:
		   						string dirID = "cred/" + tempID;
		   						 ofstream myfile (dirID.c_str());
		  						if (myfile.is_open())
		  						{
		  							tempUsrPass = superEnCrypt(tempUsrPass);

		   							 myfile << tempUsrPass;
		  							  myfile.close();
		 						 }
		 						 else
		 						 {
		 						 	cout << "\033[1;31m[!ALERT!]\033[0m CRITICAL ERROR: CANNOT OPEN CRED WRITE LOCATION \n";
		 						 }
		 						 string backupid = tempID;
		 						 dirID = "usr/" + tempID;
		 						 
		 						  ofstream myfile2 (dirID.c_str());
		  						if (myfile2.is_open())
		  						{
		  							
		  							tempUsrName = superEnCrypt(tempUsrName);
		  							tempID = superEnCrypt(tempID);
		  							string writeAdmin = to_string(tempAdminChecksum);
		  							writeAdmin= superEnCrypt(writeAdmin);
		  							string startMinStr = to_string(startMin);
		  							startMinStr = superEnCrypt(startMinStr);

		  							string startHourStr = to_string(startHour);
		  							startHourStr = superEnCrypt(startHourStr);

		  							string dayStr = to_string(day);
		  							dayStr = superEnCrypt(dayStr);

		  							string monthStr = to_string(month);
		  							monthStr = superEnCrypt(monthStr);

		  							string yearStr = to_string(year);
		  							yearStr = superEnCrypt(yearStr);

		  							
		   							 myfile2 << tempUsrName<<"\n";
		   							 myfile2 << tempID<<"\n";
		   							 myfile2 << writeAdmin<<"\n";
		   							 myfile2 << startMinStr<<"\n";
		   							 myfile2 << startHourStr<<"\n";
		   							 myfile2 << dayStr<<"\n";
		   							 myfile2 << monthStr<<"\n";
		   							 myfile2 << yearStr<<"\n";
		   							 myfile2 << superEnCrypt("payload")<<"\n";
		   							 myfile2 << startMinStr<<"\n";
		   							 myfile2 << startHourStr<<"\n";
		   							 myfile2 << dayStr<<"\n";
		   							 myfile2 << monthStr<<"\n";
		   							 myfile2 << yearStr<<"\n";
		   							 myfile2 << superEnCrypt("account creation")<<"\n";
		   							
		  							  myfile2.close();
		  							  	
		 						 }
		 						 else
		 						 {
		 						 	cout << "\033[1;31m[!ALERT!]\033[0m CRITICAL ERROR: CANNOT OPEN USR WRITE LOCATION \n";
		 						 }
		 						
		 						 cout << "\n\033[1;35m[!INFO!]\033[0m Loading new user....";
		 						 string tempUserInfo[21] = "null";
									string usrPath = "usr/" + backupid;
									
									ifstream file (usrPath.c_str());
									int index = 0;
								    while (getline(file, readBuffer))
							   			 {
							        		tempUserInfo[index] = readBuffer;
							        		index++;
							   			 }
							   			 lastSeen(tempUserInfo[1]);
							   		cout << "\n\033[1;31m[!SUCCESS!]\033[0m Following information has been wrote successfully:\n";
							   		tempUserInfo[0] = superDeCrypt(tempUserInfo[0]);
							   		tempUserInfo[1] = superDeCrypt(tempUserInfo[1]);
							   		tempUserInfo[2] = superDeCrypt(tempUserInfo[2]);
							   		cout << "User Full Name: "<<tempUserInfo[0]<<"\n";
							   		cout << "User ID: "<<tempUserInfo[1]<<"\n";
							   		cout << "User hash: "<<tempUserInfo[2]<<"\n";
							   		if(isAdmin(tempUserInfo[2], tempUserInfo[1])){
							   		cout << "Admin: \033[1;33mYES\033[0m \n";
							   	}
							   		else cout << "Admin: No\n";
		 						 pause();
		 						 system("clear");
		   					}
		   					else{
		   						goto usrcrt;
		   					}
		   				}
		   				else
		   				{
		   					cout << "\033[1;31m[!ACCESS DENITED!]\033[0m You need admin permissions to create new accounts!\n";
		   					pause();
		   				}
		   				}
		   				else
		   				{
		   					cout << "\033[1;31m[!ERROR!]\033[0mCannot find command "<<inputBuffer<<". Please try another type case or try \"help\" to see all commands.\n"  ;
		   					cout << "Press [ENTER] to contiune.";
		   					pause();
		   					system("clear");
		   				}
		   				system("clear");
   				goto prompt;
   		}
	}

int isAdmin(string userType, string userID)
{
	int userMathType = stoi( userType );
   	int userMathID = stoi( userID );
   	int checksum = pow(sqrt(userMathID * 61), 2);

   		if(checksum == userMathType)
   		{
   			void writeLog(string userId, string reason, string tags[200]);
			/*string tag[200] = {"user", "admin", "security", "granted", "all"};
			writeLog(normalCrypt(userID), "User "+userID+" have been granted with admin permissions", tag);*/
   			return true;
   						
   		}
   		   	void writeLog(string userId, string reason, string tags[200]);
			/*string tag[200] = {"user", "admin", "security", "denited", "all"};
			writeLog(normalCrypt(userID), "User "+userID+" haveb't been granted with admin permissions", tag);*/
   		
   		return false;

}

void updateUsrInfo(string usrId, string data, string payload)
{
string readBuffer;
string dataArray[28] = "EMPTY";
string path = "usr/" + usrId;
int lineIndex = 0;
	ifstream usrInfo (path.c_str());
		int index = 0;
		while (getline(usrInfo, readBuffer))
		{
			dataArray[index] = superDeCrypt(readBuffer);
			index++;
		}
		for(int index = 0; index < 21; index++)
		{
			if(dataArray[index] == "EMPTY")
			{
				lineIndex = index;
				break;
			}
			
			if(dataArray[index] == payload)
			{
				lineIndex = index;
				break;
			}
		
		}
	    ofstream myfile2 (path.c_str());
		if (myfile2.is_open())
		{
		for(int index = 0; index < 50; index++)
		{
			if(index == lineIndex)
			{
				break;
			}
			
			
			
			myfile2 << superEnCrypt(dataArray[index])<<"\n";
		}
		
		myfile2 << data<<"\n";
		myfile2.close();
		}
		else
		{
		 cout << "\033[1;31m[!ALERT!]\033[0m CRITICAL ERROR: CANNOT OPEN USR WRITE LOCATION \n";
		}

}

void updateEdit(string userId, string reason)
{
	void writeLog(string userId, string reason, string tags[200]);
string tag[200] = {"admin", "safety", "password", "change", "cred", "all"};
	writeLog(userId, "user "+userId+" last information changed with reason: " + superEnCrypt(reason), tag);
	time_t currentTime;
  		struct tm *localTime;
		time( &currentTime );                   // Get the current time
 	    localTime = localtime( &currentTime );  // Convert the current time to the local time
  		int startMin = localTime->tm_min;
  		int startHour = localTime->tm_hour;
  		int day    = localTime->tm_mday;
  		int month  = localTime->tm_mon + 1;
  		int year   = localTime->tm_year + 1900;


		string startMinStr = to_string(startMin);
		startMinStr = superEnCrypt(startMinStr);

		string startHourStr = to_string(startHour);
		startHourStr = superEnCrypt(startHourStr);

		string dayStr = to_string(day);
		dayStr = superEnCrypt(dayStr);

		string monthStr = to_string(month);
		monthStr = superEnCrypt(monthStr);

		string yearStr = to_string(year);
		yearStr = superEnCrypt(yearStr);

		updateUsrInfo(userId, superEnCrypt("payload"), "payload");
		updateUsrInfo(userId, startMinStr, "false");
		updateUsrInfo(userId, startHourStr, "false");
		updateUsrInfo(userId, dayStr, "false");
		updateUsrInfo(userId, monthStr, "false");
		updateUsrInfo(userId, yearStr, "false");
		updateUsrInfo(userId, reason, "false");

}

void lastSeen(string userId)
{
	
	void writeLog(string userId, string reason, string tag[200]);
	
	time_t currentTime;
  		struct tm *localTime;
		time( &currentTime );                   // Get the current time
 	    localTime = localtime( &currentTime );  // Convert the current time to the local time
  		int startMin = localTime->tm_min;
  		int startHour = localTime->tm_hour;
  		int day    = localTime->tm_mday;
  		int month  = localTime->tm_mon + 1;
  		int year   = localTime->tm_year + 1900;


		string startMinStr = to_string(startMin);
		startMinStr = superEnCrypt(startMinStr);

		string startHourStr = to_string(startHour);
		startHourStr = superEnCrypt(startHourStr);

		string dayStr = to_string(day);
		dayStr = superEnCrypt(dayStr);

		string monthStr = to_string(month);
		monthStr = superEnCrypt(monthStr);

		string yearStr = to_string(year);
		yearStr = superEnCrypt(yearStr);

		updateUsrInfo(userId, superEnCrypt("lastSeenPayload"), "lastSeenPayload");
		updateUsrInfo(userId, startMinStr, "false");
		updateUsrInfo(userId, startHourStr, "false");
		updateUsrInfo(userId, dayStr, "false");
		updateUsrInfo(userId, monthStr, "false");
		updateUsrInfo(userId, yearStr, "false");

}

void writeLog(string userId, string reason, string tags[200])
{
	string user = userId;
	time_t currentTime;
  		struct tm *localTime;
		time( &currentTime );                   // Get the current time
 	    localTime = localtime( &currentTime );  // Convert the current time to the local time
  		int startMin = localTime->tm_min;
  		int startHour = localTime->tm_hour;
  		int day    = localTime->tm_mday;
  		int month  = localTime->tm_mon + 1;
  		int year   = localTime->tm_year + 1900;


		string startMinStr = to_string(startMin);


		string startHourStr = to_string(startHour);


		string dayStr = to_string(day);


		string monthStr = to_string(month);


		string yearStr = to_string(year);

	string readBuffer;
string dataArray[2000] = "[EMPTY]";
string file = superEnCrypt(userId + ".log");
string path = "usr/" + file;
int lineIndex = 0;
	ifstream usrInfo (path.c_str());
		int index = 0;
		  						
									
		while (getline(usrInfo, readBuffer))
		{
			if(readBuffer == "")
			{
				break;
			}
			dataArray[index] = superDeCrypt(readBuffer);
			index++;
		}
		ofstream logIndex (path.c_str(), ios::app);
			if (logIndex.is_open())
			{
				/*
			for(int index; index < 200000; index++)
			{
			if(dataArray[index] == "[EMPTY]") 
			{
				break;
			}
		  								
		logIndex << normalCrypt(dataArray[index]) <<"\n";
			}
		  		*/					
		  							
		string datePrefix = "["+startHourStr+":"+startMinStr+" "+dayStr+"."+monthStr+"."+yearStr+"]:";
		string write = datePrefix + reason;
		logIndex << superEnCrypt("payload")<<"\n";
		logIndex << superEnCrypt("tags")<<"\n";
		for(int index = 0; index < 200; index++)
		{
			if(tags[index] == "")
			{
				break;
			}
			logIndex << normalCrypt(tags[index])<<"\n";
		}
		logIndex << superEnCrypt("tags")<<"\n";
		logIndex << superEnCrypt("content")<<"\n";
		logIndex << superEnCrypt(write) <<"\n";
		logIndex << superEnCrypt("content")<<"\n";
		logIndex << superEnCrypt("payload")<<"\n";   							 
		logIndex.close();
			}
			else
			{
				 cout << "\033[1;31m[!ALERT!]\033[0m CRITICAL ERROR: CANNOT OPEN LOG WRITE LOCATION "<<path<<"\n";
				
			}
			tryagain:
			string file2 = superEnCrypt("system.log");
			string path2 = "usr/" + file2;
			ifstream create (path2.c_str());
			ofstream globalLog (path2.c_str(), ios::app);
			if (globalLog.is_open())
			{
				/*
			for(int index; index < 200000; index++)
			{
			if(dataArray[index] == "[EMPTY]") 
			{
				break;
			}
		  								
		logIndex << normalCrypt(dataArray[index]) <<"\n";
			}
		  		*/					
		  							
		string datePrefix = "["+startHourStr+":"+startMinStr+" "+dayStr+"."+monthStr+"."+yearStr+"]:";
		string write = datePrefix + reason;
		globalLog << superEnCrypt("payload")<<"\n";
		globalLog << superEnCrypt("tags")<<"\n";
		for(int index = 0; index < 200; index++)
		{
			if(tags[index] == "")
			{
				break;
			}
			globalLog << superEnCrypt(tags[index])<<"\n";
		}
		globalLog << superEnCrypt(userId)<<"\n";
		globalLog << superEnCrypt("tags")<<"\n";
		globalLog << superEnCrypt("content")<<"\n";
		globalLog << superEnCrypt(write) <<"\n";
		globalLog << superEnCrypt("content")<<"\n";
		globalLog << superEnCrypt("payload")<<"\n";   							 
		globalLog.close();
			}

}

int parsePayload(string file, string folder, string tag, int matchIndex)
{
int counter = 0;
string readBuffer;
string dataArray[5000] = "EMPTY";
string path = folder + file;
int startPoint = 0;
int point = 0;
int endPoint = 0;
bool encryption = true;
bool reached = false;

	fstream searchFile (path.c_str(), ios::in);
	if(searchFile.is_open())
	{
		int index = 0;

		while (getline(searchFile, readBuffer))
		{
			if(encryption)
			{
				dataArray[index] = superDeCrypt(readBuffer);
			}
			else
			{
				dataArray[index] = readBuffer;
			}
			index++;
		}
		for(int index2 = 0; index2 < 500; index2++)
		{
			if(counter == matchIndex)
			{
				break;	
			}

			if(dataArray[index2] == "EMPTY")
			{
				break;
			}
			if(dataArray[index2] == tag)
			{
				if(reached)
				{
					endPoint = index2;
					reached = false;
					point++;
					counter++;
					goto skip;
				}
				if(!reached)
				{
				startPoint = index2;
				reached = true;
				}
				skip:
				system("");
			}

		}
		returnArray[0] = startPoint;
		returnArray[1] = endPoint;
		if(startPoint == 0)
		{
			return 5;
		}
		if(endPoint == 0)
		{
			return 5;
		}
		return 0;
		
		}
		else
		{
			return 1;
		}

		}

int getpayload(string file, string folder)
{
	
	for(int i = 0; i < 199; i++)
	{
		outputPayload[i] = "[EMPTY]";
	}

	int lines[2] = { returnArray[0], returnArray[1] };
	string dataArray[20000] = "[EMPTY]";
	string readBuffer;
	string path = folder + file;
	bool encryption = true;

	fstream searchFile (path.c_str(), ios::in);
	if(searchFile.is_open())
	{
		int index = 0;

			while (getline(searchFile, readBuffer))
			{
				if(encryption)
				{

					dataArray[index] = superDeCrypt(readBuffer);
				}
				else
				{
					dataArray[index] = readBuffer;
				}
				index++;
			}
			int arrayIndex = 0;
			
		for(int i = lines[0] + 1; i < lines[1]; i++)
		{
			outputPayload[arrayIndex] = dataArray[i];
			arrayIndex++;

		}
		if(outputPayload[0] == "[EMPTY]")
		{
			return 4;
		}
		 return 0;
			}
			else
			{
				return 1;
			}
}

int payload(string file, string folder, string tag, int matchIndex)
{
	outputPayload[0] = "[null]";
	int getpayload(string file, string folder);
	int parseErr = parsePayload(file, folder, tag, matchIndex);
	int getErr = getpayload(file, folder);
	if(parseErr != 0)
	{
		return parseErr;
	}
	if(getErr != 0)
	{
		return getErr;
	}
	return 0;
}

void writeDatabase(string content[200], string userID, string permission, string tags[200], string title)
{
	int ID;
	string user = userID;
	time_t currentTime;
  		struct tm *localTime;
		time( &currentTime );                   // Get the current time
 	    localTime = localtime( &currentTime );  // Convert the current time to the local time
  		int startMin = localTime->tm_min;
  		int startHour = localTime->tm_hour;
  		int day    = localTime->tm_mday;
  		int month  = localTime->tm_mon + 1;
  		int year   = localTime->tm_year + 1900;


		string startMinStr = to_string(startMin);


		string startHourStr = to_string(startHour);


		string dayStr = to_string(day);


		string monthStr = to_string(month);


		string yearStr = to_string(year);
		
	string readBuffer;
string dataArray[2000] = "[EMPTY]";
string file = superEnCrypt("index");
string pathIndex = "database/" + file;
int lineIndex = 0;
	ifstream dbIndexRead (pathIndex.c_str());
		int index = 0;
								
									
		while (getline(dbIndexRead, readBuffer))
		{
			if(readBuffer == "")
			{
				break;
			}
			dataArray[index] = superDeCrypt(readBuffer);
			index++;
		}
		ID = index;

		ofstream dbIndex (pathIndex.c_str(), ios::app);
		string dataID = to_string(ID);
		if(dbIndex.is_open())
		{
			
			dbIndex << superEnCrypt(dataID)<<"\n";
		}
		else
		{
			cout << "CRITICAL ERROR CANNOT WRITE DATACARD ID!\n";
		}
		string dbPath = "database/" + superEnCrypt(dataID);

		ofstream dbWrite (dbPath.c_str(), ios::app);
			if (dbWrite.is_open())
			{				
		  							
		string date = ""+startHourStr+":"+startMinStr+" "+dayStr+"."+monthStr+"."+yearStr+"";
		dbWrite << superEnCrypt("payload")<<"\n";

		dbWrite << superEnCrypt("permission")<<"\n";
		dbWrite << superEnCrypt(permission) <<"\n";
		dbWrite << superEnCrypt("permission")<<"\n";

		dbWrite << superEnCrypt("title")<<"\n";
		dbWrite << superEnCrypt(title) <<"\n";
		dbWrite << superEnCrypt("title")<<"\n";

		dbWrite << superEnCrypt("tags")<<"\n";
		for(int index = 0; index < 200; index++)
		{
			if(tags[index] == "")
			{
				break;
			}
			dbWrite << superEnCrypt(tags[index])<<"\n";
		}
		dbWrite << superEnCrypt("tags")<<"\n";

		dbWrite << superEnCrypt("id")<<"\n";
		dbWrite << superEnCrypt(dataID)<<"\n";
		dbWrite << superEnCrypt("id")<<"\n";

		dbWrite << superEnCrypt("date")<<"\n";
		dbWrite << superEnCrypt(date)<<"\n";
		dbWrite << superEnCrypt("date")<<"\n";

		dbWrite << superEnCrypt("creator")<<"\n";
		dbWrite << superEnCrypt(userID)<<"\n";
		dbWrite << superEnCrypt("creator")<<"\n";

		dbWrite << superEnCrypt("content")<<"\n";
		for(int index = 0; index < 200; index++)
		{
			if(tags[index] == "")
			{
				break;
			}
		dbWrite << superEnCrypt(content[index]) <<"\n";
	}
		dbWrite << superEnCrypt("content")<<"\n";

		dbWrite << superEnCrypt("payload")<<"\n";   							 
		dbWrite.close();
			}
			else
			{
				 cout << "\033[1;31m[!ALERT!]\033[0m CRITICAL ERROR: CANNOT OPEN LOG WRITE LOCATION "<<dbPath<<"\n";
				
			}
}

void database(string userID, string userType, bool hotload, string id) {
 int line();
 struct database {
	 string title;
	 string id;
	 string creator;
	 string creatorName;
	 string date;
	 string tags[1000];
	 string content[200];
	 string permission;
} ;
struct crossrefrence {
	int rank = 0;
	string id;
	string title;
	string tags[200];
	bool read = false;
	bool wrote = false;
} cr[200];

system("clear");
string dataArray[2000];
string readBuffer;
string userInfo[21] = "null";
string usrPath = "usr/" + userID;
ifstream file (usrPath.c_str());
int index = 0;
string tag[20];
while (getline(file, readBuffer)) {
    userInfo[index] = superDeCrypt(readBuffer);
    index++;
}
string userName = userInfo[0];
userID = userInfo[1];
string userPermission = userInfo[3];
string inputBuffer;
database:
inputBuffer = "";
string tags[200] = {"testi", "ei"};
int watchDog = 0;
if(hotload) {
	inputBuffer = "search";
	cin.ignore();
}
else {
cout << "\033[1;32m"<<userName<<"\033[0m@\033[1;31m["<<company<<" DATABASE]>\033[0m";
cin >> inputBuffer;
}
if(inputBuffer == "exit") {
	return;
}
if(inputBuffer == "new")
	{
		int tagsIndex = 0;
		string title;
		string permission;
		string content[200];
		int contentIndex = 0;
		string tags[1000] = "[EMPTY]";
		cout << "\n\033[1;35m[!INFO!]\033[0m Input title: ";
		cin.ignore();
		getline(cin, title);
		cout << "\n\033[1;35m[!INFO!]\033[0m Write content: ";
		tagJumper2:
		getline(cin, content[contentIndex]);
		if(content[contentIndex] != "end") {
			contentIndex++;
			goto tagJumper2;
		}
		cout << "\n\033[1;35m[!INFO!]\033[0m Permission: ";
		getline(cin, permission);
		cout << "\n\033[1;35m[!INFO!]\033[0m Input tags (to end input, write 'end'): ";
		tagJumper:
		cin >> tags[tagsIndex];
		if(tags[tagsIndex] != "end") {
			tagsIndex++;
			goto tagJumper;
		}
		writeDatabase(content, userID, permission, tags, title);
		goto database;
	}
	if(inputBuffer == "search") {
		bool crossrefrence = false;
		string result[2000] = "[EMPTY]";
		int resultInt = 0;
		if(hotload) {
			inputBuffer = "end";
		}
		else {
			cout << "\033[1;35m[!INFO!]\033[0m Give search term: ";
			cin >> inputBuffer;
		}
		string databaseDir = "database/" + superEnCrypt("index");
		ifstream dbIndexRead (databaseDir.c_str());
		int index = 0;
		while (getline(dbIndexRead, readBuffer)) {
			if(readBuffer == "") {
				break;
			}
			dataArray[index] = readBuffer;
			index++;
		}
		while(index != -1)
		{
			payload(dataArray[index], "database/", "tags", 1);
			for(int i = 0; i < 30; i++) {
	   		tag[i] = outputPayload[i];
	   		}
		   		for(int i = 0; i < 30;i++) {
		   			if(tag[i] == inputBuffer)
		   			{
		   				payload(dataArray[index], "database/", "id", 1);
		   				result[resultInt] = outputPayload[0];
		   				resultInt++;
		   			}
		   		}
		   		
		   		index--;
		}
		dbListPrint:
		int loop = 0;
		string printId[200] = "[EMPTY]";
		string printTitle[200] = "[EMPTY]";
		string printDate[200] = "[EMPTY]";
		string printCreator[200] = "[EMPTY]";
		string searchTerm = "[EMPTY]";
		int printOut = 0;
		int row = 2;
		while(result[loop] != "[EMPTY]")
			{
				payload(superEnCrypt(result[loop]), "database/", "id", 1);
				printId[loop] = outputPayload[0];
				payload(superEnCrypt(result[loop]), "database/", "title", 1);
				printTitle[loop] = outputPayload[0];
				payload(superEnCrypt(result[loop]), "database/", "date", 1);
				printDate[loop] = outputPayload[0];
				payload(superEnCrypt(result[loop]), "database/", "creator", 1);
				printCreator[loop] = outputPayload[0];
				loop++;
			}
		loop--;
		list:
		row = 2;
		system("clear");
		if(!crossrefrence)
		{
			int x = line();
			SetCursorPos(((x+(inputBuffer.length()))/2)-16, 0);
			cout << "[SEARCH RESULT FOR TERM "<<inputBuffer<<"]\n";
			line();
			SetCursorPos(1,1);
			cout << "ID";
			SetCursorPos(x/6,1);
			cout << "TITLE";
			SetCursorPos(x/1.6,1);
			cout << "CREATOR";
			SetCursorPos(x/1.2,1);
			cout << "DATE\n";
			while(loop > -1)
			{
				SetCursorPos(1,row);
				cout << printId[loop];
				SetCursorPos(x/6,row);
				cout << printTitle[loop];
				SetCursorPos(x/1.6,row);
				cout << printCreator[loop];
				SetCursorPos(x/1.2,row);
				cout << printDate[loop]<<"\n";
				row = row + 1;
				
				loop--;
			}
			line();
		}
		if(crossrefrence) {
			int x = line();
			SetCursorPos(x/2-11, 0);
			cout << "[CROSSREFRENCE RESULTS]\n";
			line();
			SetCursorPos(1,1);
			cout << "ID";
			SetCursorPos(x/6,1);
			cout << "TITLE";
			SetCursorPos(x/1.8,1);
			cout << "CREATOR";
			SetCursorPos(x/1.4,1);
			cout << "DATE\n";
			SetCursorPos(x/1.1,1);
			cout << "MACTHES\n";
			while(loop > -1) {
				SetCursorPos(1,row);
				cout << printId[loop];
				SetCursorPos(x/6,row);
				cout << printTitle[loop];
				SetCursorPos(x/1.8,row);
				cout << printCreator[loop];
				SetCursorPos(x/1.4,row);
				cout << printDate[loop];
				SetCursorPos(x/1.1,row);
				cout << cr[stoi(printId[loop])].rank<<"\n";
				row = row + 1;
				loop--;
			}
			line();
			crossrefrence = false;
			}
			if(hotload) {
				inputBuffer = id;
			}
			else {
				cout << "\n\033[1;35m[!INFO!]\033[0m Exit, refine or type in [id] for more information: ";
				cin >> inputBuffer;
			}	
			if(inputBuffer == "exit") {
				system("clear");
				goto database;
			}

			if(inputBuffer == "refine") {
				for(int i = 0;i < 2000;i++) {
						result[i] = "[EMPTY]";
				}
				bool match;
				cout << "\033[1;35m[!INFO!]\033[0m Give refine term: ";
				cin >> inputBuffer;
				index = 0;
				resultInt = 0;
				while(printId[index] != "[EMPTY]") {
					payload(superEnCrypt(printId[index]), "database/", "tags", 1);
					for(int i = 0; i < 13; i++) {
						tag[i] = outputPayload[i];
			  		}
					for(int i = 0; i < 11;i++) {
						if(tag[i] == inputBuffer) {
			   				match = true;
			   				payload(superEnCrypt(printId[index]), "database/", "id", 1);
			   				result[resultInt] = outputPayload[0];
			   				resultInt++;
					   	}
					}
					index++;
				}
			goto dbListPrint;
			}
			else {
				loop = 0;
				while(printId[loop] != "[EMPTY]")
				{
					if(printId[loop] == inputBuffer) {
						searchTerm = printId[loop];
						break;
					}
					loop++;
				}
				if(searchTerm != "[EMPTY]") {
					hotloadJumper:
					if(hotload) searchTerm = id;
					cout << "\n\033[1;35m[!INFO!]\033[0m Loading data for file "<<searchTerm<<"\n";	
					database dataCache; 
					dataCache.content[200] = "[EMPTY]";
					payload(superEnCrypt(searchTerm), "database/", "title", 1);
					dataCache.title = outputPayload[0];
					payload(superEnCrypt(searchTerm), "database/", "creator", 1);
					dataCache.creator = outputPayload[0];
					payload(superEnCrypt(searchTerm), "database/", "date", 1);
					dataCache.date = outputPayload[0];
					payload(superEnCrypt(searchTerm), "database/", "content", 150);
					for(int i=0; i < 150;i++) {
						dataCache.tags[i] = outputPayload[i];
						dataCache.content[i] = outputPayload[i];
					}
					payload(superEnCrypt(searchTerm), "database/", "tags", 150);
					for(int i=0; i < 199;i++) {
						dataCache.tags[i] = outputPayload[i];
					}
					payload(superEnCrypt(searchTerm), "database/", "permission", 1);
					dataCache.permission = outputPayload[0];
					if(dataCache.permission == "admin") {
						if(!isAdmin(userType, userID)) {
							cout << "\033[1;31m[!ALERT!]\033[0m This file requires an administrative permissions!\n";
							pause();
							goto skipDatabase;
						}

					}
					dataCache.id = inputBuffer;
					system("clear");
					int length = dataCache.title.length();
					int x = line();
					SetCursorPos((x/2) - length/2, 0);
					cout << "[\033[1;32m"<<dataCache.title<<"\033[0m]\n";
					SetCursorPos(x/8,2);
					cout << "Creator: \033[1;33m"<<dataCache.creator<<"\033[0m\n";
					SetCursorPos(x/2.2,2);
					if(dataCache.permission == "admin") {
						cout << "Permission level: \033[1;33m"<<dataCache.permission<<"\033[0m\n";
					}
					else cout << "Permission level: "<<dataCache.permission<<"\n";
					SetCursorPos(x/1.3,2);
					cout << "Creation date: \033[1;33m"<<dataCache.date<<"\033[0m\n";
					SetCursorPos(0,4);
					line();
					SetCursorPos(0,6);
					int index = 0;
					while(dataCache.content[index] != "end") {
						cout << dataCache.content[index]<<"\n";
						index++;
					}
					int lineX = index + 6;
					index = 0;
					line();
					cout << "\n\033[1;33mTAGS:\033[0m\n\n";
					while(dataCache.tags[index] != "end") {
						cout << "  " << dataCache.tags[index]<<"\n";
						index++;
					}
					hotload = false;
					cout << "\n\033[1;35m[!INFO!]\033[0m Write exit to leave or crossrefrence.\n";
					cin >> inputBuffer;
					if(inputBuffer == "crossrefrence") {
						for(int i = 0; i<200;i++) {
							cr[i].rank = 0;
							cr[i].id = "0";
							cr[i].read = false;
							cr[i].wrote = false;
						}
						cout << "Crossrefrencing against all database files.\n";
						resultInt = 0;
						index = 0;
						string databaseDir = "database/" + superEnCrypt("index");
						ifstream dbIndexRead (databaseDir.c_str());
						while (getline(dbIndexRead, readBuffer)) {
							if(readBuffer == "") {
								break;
							}
							dataArray[index] = superDeCrypt(readBuffer);
							index++;
						}
						index--;
						int loopVar = index;
						while(index != -1) {
							payload(superEnCrypt(dataArray[index]), "database/", "tags", 1);
							for(int i = 0; i < 25; i++) {
					   			tag[i] = outputPayload[i];
					   		}	
					   		for(int y = 0; y < 25;y++)
					   		{
								for(int i = 0; i < 25;i++) {
							   		if(tag[i] == "[EMPTY]"||tag[i] == "end"||dataCache.tags[y] == "[EMPTY]"||dataCache.tags[y] == "end") {
							   			goto emptySkip;	
							   		}
							   		if(tag[i] == dataCache.tags[y]) {
						   				payload(superEnCrypt(dataArray[index]), "database/", "id", 1);
						   				string idNum = outputPayload[0];
						   				if(cr[stoi(idNum)].read)
						   				{
						   					cr[stoi(idNum)].rank++;
						   					cr[stoi(idNum)].id = idNum;
						   				}
						   				if(!cr[stoi(idNum)].read)
						   				{
						   				cr[stoi(idNum)].id = outputPayload[0];
						   				cr[stoi(idNum)].read = true;
						   				cr[stoi(idNum)].rank++;
						   				}
						   			}
							   		emptySkip:
							   		system("");
							   	}
							}
							index--;
						}
						cout <<"\n";
						cr[stoi(dataCache.id)].rank = 0;
						int temp = 0;
						row = 2;
						for(int i = 0; i<200;i++)
						{
							result[i] = "[EMPTY]";
						}
						for(int i = 0; i<200;i++)
						{
							if(cr[i].rank != 0)
							{
								result[temp] = cr[i].id;
								temp++;
							}
						}
						inputBuffer = "";
						crossrefrence = true;
						goto dbListPrint;
					
					}
					if(inputBuffer == "exit")
					{
					system("clear");
					}
					else {
						cout << "That ID is not on the list!\nPress [ENTER] to contiune.";
						pause();
						system("clear");
						goto list;
					}
				}
			}
skipDatabase:
	goto database;
}
else {
	goto database;
}
}

int line()
{
	struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
	int x = w.ws_col;
	int xloop = x;
	 while(xloop>0)
	{
	cout << "\033[1;32m=\033[0m";
	xloop--;
	}
	return x;
}

void API()
{
	
}
