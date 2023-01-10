#include <iostream>
#include <string>
#include <vector>

using std::vector;

int compare(char opp, char my);

int main(void){
	vector<char>* vect = new vector<char>;
	int total = 0;

	for (std::string line; std::getline(std::cin, line);) {
		for(char& c : line){
			if(c != ' '){
				vect->push_back(c);
			}
		}
    }

	for(std::vector<char>::iterator it = vect->begin(); it!=vect->end(); it=it+2){
		total = total + compare(*it, *(it+1));
	}

	std::cout << total << std::endl;

    return 0;
}

int compare(char opp, char my){
	switch(opp){
		case 'A':
			switch(my){
				case 'X':
					return 3;
				case 'Y':
					return 4;
				case 'Z':
					return 8;
			}
		case 'B':
			switch(my){
				case 'X':
					return 1;
				case 'Y':
					return 5;
				case 'Z':
					return 9;
			}
	case 'C':
			switch(my){
				case 'X':
					return 2;
				case 'Y':
					return 6;
				case 'Z':
					return 7;
			}
	}
	return 0;
}

