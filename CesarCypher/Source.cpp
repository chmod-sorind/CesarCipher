/*
Title: C++ CesarCipher.
Author: Sorin Diaconescu
*/

#include <iostream>
#include <sstream>



int main()
{
	int encryptionKey;													// Store the encription key
	std::cout << "Enter a key to encrypt:" << std::endl;
	std::cin >> encryptionKey;

	std::string rawMessage;												// Store the unencrypted message.
	std::cout << "Enter your message: " << std::endl;
	std::getline(std::cin >> std::ws, rawMessage);

	std::string encriptedMessage;										// Define an empty vector which will later contain the encripted message.

	for (int i = 0; rawMessage[i]; ++i)									// Iterate through the characters of the message.
	{
		//char asciiLetter = rawMessage[i];														    // Store each character in a variable "asciiLetter" for conversion.
		//int asciiLetterIndex = static_cast<int>(asciiLetter);										// Convert the character into ascii value.
		//int newAsciiLetterIndex = static_cast<int>(asciiLetter) + encryptionKey;					// Apply the encryptionKey the ascii value of the character.
		//char newAsciiLetter = static_cast<char>(static_cast<int>(asciiLetter) + encryptionKey);	// Convert the ascii value into the new character.

		encriptedMessage.push_back(static_cast<char>(static_cast<int>(rawMessage[i]) + encryptionKey));
		/* Calculate the new ascii value by applying the encryptionKey to the caracter's ascii original value 
		and then append the new character to the encriptedMessage string.
		*/
	}

	std::cout << encriptedMessage << std::endl;;
	system("pause");
	return 0;
}