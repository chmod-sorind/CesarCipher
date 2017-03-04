/*
Title: C++Cipher.
Author: Sorin Diaconescu
Description:
	This is a representation in C++ of the Cesar Cipher.
*/
#include <iostream>
#include <string>


int main( int argc, char ** argv )
{
	int key;
	char message[256];
	
	std::cout<< "enter your key: ";
	std::cin>> key;
		
	std::cout << "enter a message: ";
	std::cin>> message;

	
	char alphaSpace[] = " abcdefghijklmnopqrstuvwxyz";         // Store the alphabet in a char array. This array contains also a space for a more ambiguous encryption. 

	for ( int l = 0; message[l]; ++l ) {                       // Iterate through the characters of the message.
		char letter = message[l];                              // Store each character in a variable "letter" for later comparison.
		for ( int c = 0; alphaSpace[c]; ++c ) {                // Iterate through the caracters of the alphaSpace.
			if ( letter == alphaSpace[c] ) {                   // Test if the letter matches a character in alphaSpace.
				int index = c;                                 // Store the intex of the matching letter in a variable called index.
				break;                                         // Break out of the loop.
			}
		}
	}

	//std::cout << std::endl;


	for ( int i = key; alphaSpace[i]; ) {
		if ( i == 26 ) {
			//printf(" %c  ", alphaSpace[i]);
			i = 0;			
		}
		else {
			//printf(" %c  ", alphaSpace[i]);
			++i;
			if (i == key) {
				break;
			}
		}
	}

	//std::cout<< std::endl;

	for ( int i = 0; alphaSpace[i]; ++i ) {
		if ( i > 9) {
			//printf(" %d ", i);
		}
		else
		{
			//printf(" %d  ", i);
		}
	}

	//std::cout << std::endl;

	for (int i = 0; alphaSpace[i]; ++i) {
		//printf(" %c  ", alphaSpace[i]);
	}
}