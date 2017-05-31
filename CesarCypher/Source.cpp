/*
Title: C++ CesarCipher.
Author: Sorin Diaconescu
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

static void show_usage( string name )
{
	cerr << "Usage: " << name << " Options:\n"
		<< "\t-h, --help\tShow this help message.\n"
		<< "\t-e, --encrypt \tUse this option to encrypt a message.\n" 
		<< "\t-d, --decrypt \tUse this option to decrypt message.\n" 
		<< "\t-k, --key \tSpecify a key form 1 to 100 to encrypt your message.\n";
}

string getMessage() {
	string msg;
	cout << "Enter your message: \n";
	getline(cin >> ws, msg);
	return msg;
}

int getKey() {
	int k;
	cout << "Enter a key to encrypt:\n";
	cin >> k;
	return k;
}

string encrypt( int k, string m ) {
	string msg;															// Define an empty string which will later contain the encripted message.
	for (int i = 0; m[i]; ++i)											// Iterate through the characters of the message.
	{
		/* Calculate the new ascii value by applying the encryptionKey to the caracter's ascii original value
		and then append the new character to the encriptedMessage string.
		*/
		msg.push_back(static_cast<char>(static_cast<int>(m[i]) + k));
	}
	return msg;
}

int main( int argc, char *argv[] ) {

	int encryptionKey;
	string rawMessage;
	string encryptedMsg;

	if (argc == 1) {
		encryptionKey = getKey();
		rawMessage = getMessage();
		encryptedMsg = encrypt(encryptionKey, rawMessage);
		cout << encryptedMsg << endl;
		return 0;
	}

	for ( int i = 1; i < argc; ++i ) {
		string arg = argv[i];
		if ( ( arg == "-h" ) || ( arg == "--help" ) ) {
			show_usage(argv[0]);
			return 0;
		}
		else if ( ( arg == "-k" ) || ( arg == "--key" )) {
			if  ( i + 1 < argc ) {											// Make sure we aren't at the end of argv!
				string k = argv[i + 1];										// Increment 'i' to get the next argument as the value for option -k / --key.
				encryptionKey = atoi(k.c_str());							// I have no clue what atoi nor c_str() do. My assumptio is that it converts stuf to other stuff ...DOOHH!!!
				if ( encryptionKey < 1 ) {
					cout << "option --key requires a integer value.\n";
					return 0;
				}
				rawMessage  = getMessage();
				encryptedMsg = encrypt(encryptionKey, rawMessage);
				cout << encryptedMsg << endl;
			}
			else {
				cout << "option --key requires a integer value.\n";
				return 0;
			}
		}
	}
	return 0;
}