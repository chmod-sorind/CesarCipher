/*
Title: C++Cipher.
Author: Sorin Diaconescu
Description:
	This is a representation in C++ of the Cesar Cipher.
*/
#include <iostream>
#include <string.h>
#include <vector>


int main(int argc, char ** argv)
{
	int key;
	char message[256];
	
	std::cout<< "Enter a key to encrypt: ";
	std::cin>> key;
		
	std::cout<< "Enter your message: ";
	std::cin>> message;
	
	std::string alphaSpace = " abcdefghijklmnopqrstuvwxyz";          // Store the characters used in a char array.
	int alphaSpaceLenght = std::size(alphaSpace);                    // Store the lenght of the character array.

	std::vector<int> list;                                           // Define an empty vector which will later contain a list of leter indexes used to encrypt the message.
	std::vector<char> encMSG;                                        // Define an empty vector which will later contain the encripted message.

	for (int l = 0; message[l]; ++l) {                               // Iterate through the characters of the message.
		char letter = message[l];                                    // Store each character in a variable "letter" for later comparison.
		for (int c = 0; alphaSpace[c]; ++c) {                        // Iterate through the caracters of the alphaSpace.
			if (letter == alphaSpace[c]) {                           // Test if the letter matches a character in alphaSpace.
				int shiftedIndexes = c + key;                        // Store the intex of the matching letter and increment it by the shiftting value.
				if (shiftedIndexes > alphaSpaceLenght) {
					shiftedIndexes = (shiftedIndexes - alphaSpaceLenght) - 1 ;
				}
				list.insert(list.end(), shiftedIndexes);
				break;                                               // Break out of the loop.
			}
		}
	}

	std::vector<int>::iterator listBegin = list.begin();
	std::vector<int>::iterator listEnd = list.end();
	for (auto listb = listBegin; listb < listEnd; ++listb) {
		for (int i = 0; alphaSpace[i]; ++i) {
			if (i == *listb) {
				encMSG.insert(encMSG.end(), alphaSpace[i]);
				break;
			}
		}
	}

	std::string encriptedMessage(encMSG.begin(), encMSG.end());
	printf("Your Encripted message is: %s", encriptedMessage.c_str());

}