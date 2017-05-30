/*
Title: C++ CesarCipher.
Author: Sorin Diaconescu
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static void show_usage( std::string name )
{
	std::cerr << "Usage: " << name << " Options:\n"
		<< "\t-h, --help\tShow this help message.\n"
		<< "\t-e, --encrypt \tUse this option to encrypt a message.\n" 
		<< "\t-d, --decrypt \tUse this option to decrypt message.\n" 
		<< "\t-k, --key \tSpecify a key form 1 to 100 to encrypt your message.\n";
}


int main( int argc, char *argv[] ) {
	if ( argc < 2 ) {
		show_usage( argv[0] );
		return 1;
	}



	for ( int i = 1; i < argc; ++i ) {
		std::string arg = argv[i];
		if ( ( arg == "-h" ) || ( arg == "--help" ) ) {
			show_usage(argv[0]);
			return 0;
		}
		else if ( ( arg == "-k" ) || ( arg == "--key" )) {
			if  ( i + 1 < argc ) {											// Make sure we aren't at the end of argv!
				std::string key = argv[i + 1];								// Increment 'i' so we don't get the argument as the next argv[i].
				std::cout << key << std::endl;
				int encryptionKey = static_cast<int>(key);

			}
			else {															// There was no argument to the key option.
				std::cerr << "--key option requires one argument.\n";
				return 1;
			}
		}
		else {
			std::cout << "Some code here.\n";
		}
	}

	std::cout << "Enter a key to encrypt:\n";
	std::cin >> encryptionKey;

	std::string rawMessage;													// Store the unencrypted message.
	std::cout << "Enter your message: \n";
	std::getline( std::cin >> std::ws, rawMessage );

	std::string encriptedMessage;										 	// Define an empty string which will later contain the encripted message.

	for ( int i = 0; rawMessage[i]; ++i )									// Iterate through the characters of the message.
	{
		/* Calculate the new ascii value by applying the encryptionKey to the caracter's ascii original value
		and then append the new character to the encriptedMessage string.
		*/
		encriptedMessage.push_back( static_cast<char>( static_cast<int>( rawMessage[i]) + encryptionKey ) );
	}

	std::cout << encriptedMessage << std::endl;;
	//system("pause");
	return 0;
}