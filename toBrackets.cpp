#include <iostream>   
#include <cctype>
#include <cstring> 

struct Letters {
	
int acNum;
int placeInWord;
bool isMoreThanOne;
};

void lettersToBrackets(int acNum, char **argv, char *message, Letters *letters) { 

    int strlen = std::strlen(message);
	int letter;
	int i = 0;

    while (i < strlen) {
		letter = tolower(message[i]);
		
		if (letters[letter].placeInWord == -1) {
			letters[letter].placeInWord = i;
			letters[letter].acNum = acNum;
			message[i] = '(';
		} else {
			message[i] = ')';
			if (letters[letter].isMoreThanOne == false) {
				letters[letter].isMoreThanOne = true;
				argv[letters[letter].acNum - 1][letters[letter].placeInWord] = ')';
			}
		}
		i++;
	}
}

int main(int argc, char **argv) {

    if (argc != 1) {
		Letters *letters = new Letters[128];
    	int i = 0;
		while (i < 128) {
			letters[i].placeInWord = -1;
			letters[i].acNum = -1;
			letters[i].isMoreThanOne = false;
			i++;
		}
		
		i = 2;
        while (i <= argc) {
            lettersToBrackets(i, argv, argv[i - 1], letters);
            i++;
        }

		i = 2;
		while (i <= argc) {
			std::cout << argv[i-1] << " ";
			i++;
		}
    }
    std::cout << std::endl;

    return 0;
}