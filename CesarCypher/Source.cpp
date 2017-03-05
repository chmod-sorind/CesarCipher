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
	
	std::string alphaSpace = " abcdefghijklmnopqrstuvwxyz";          // Store the alphabet in a char array. This array contains also a space for a more ambiguous encryption.
	int alphaSpaceLenght = std::size(alphaSpace);

	std::vector<int> list;                                      // Define an empty vector which later will contain a list of leter indexes used to encrypt the message.
	std::vector<char> encMSG;

	for (int l = 0; message[l]; ++l) {                               // Iterate through the characters of the message.
		char letter = message[l];                                    // Store each character in a variable "letter" for later comparison.
		//std::cout << std::endl;
		//printf("=%c=", letter);
		for (int c = 0; alphaSpace[c]; ++c) {                        // Iterate through the caracters of the alphaSpace.
			if (letter == alphaSpace[c]) {                           // Test if the letter matches a character in alphaSpace.
				//std::cout << std::endl;
				//printf("+%c+", alphaSpace[c]);
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
		//std::cout << *listb << ' ';
		for (int i = 0; alphaSpace[i]; ++i) {
			if (i == *listb) {
				encMSG.insert(encMSG.end(), alphaSpace[i]);
				break;
			}
		}
	}

	std::string encriptedMessage(encMSG.begin(), encMSG.end());
	printf("Your Encripted message is: %s", encriptedMessage.c_str());


	//std::vector<char>::iterator encMSG_begin = encMSG.begin();
	//std::vector<char>::iterator encMSG_end = encMSG.end();
	//for (auto encMSG_b = encMSG_begin; encMSG_b < encMSG_end; ++encMSG_b) {
	//	std::cout << *encMSG_b;
	//}


	//std::cout << std::endl;


	//for (int i = key; alphaSpace[i];) {
	//	if (i == 26) {
	//		printf(" %c  ", alphaSpace[i]);
	//		i = 0;			
	//	}
	//	else {
	//		printf(" %c  ", alphaSpace[i]);
	//		++i;
	//		if (i == key) {
	//			break;
	//		}
	//	}
	//}

	//std::cout<< std::endl;

	//for (int i = 0; alphaSpace[i]; ++i) {
	//	if (i > 9) {
	//		printf(" %d ", i);
	//	}
	//	else
	//	{
	//		printf(" %d  ", i);
	//	}
	//}

	//std::cout << std::endl;

	//for (int i = 0; alphaSpace[i]; ++i) {
	//	printf(" %c  ", alphaSpace[i]);
	//}
}