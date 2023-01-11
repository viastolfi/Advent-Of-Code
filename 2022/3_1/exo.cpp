#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::string;
using std::vector;

char compare(string s1, string s2);

int main(void){
	vector<string>* input = new vector<string>;
	char c;
	int res = 0;

	for (std::string line; std::getline(std::cin, line);) {
		if(line != ""){
			input->push_back(line.substr(0, line.length() / 2));
			input->push_back(line.substr(line.length() / 2, line.length()));
		}
    }

	for(vector<string>::iterator it = input->begin(); it != input->end(); it = it + 2){
		c = compare(*it, *(it+1));
		if(c >= 'a' && c <= 'z'){
			res = res + c - 'a' + 1;
		}else{
			res = res + c - 'A' + 27;
		}
	}

	std::cout << res << std::endl;

	return 0;
}

char compare(string s1, string s2){
	int i, j;


	for(i=0; i<s1.length(); i++){
		for(j=0; j<s2.length(); j++){
			if(s1[i] == s2[j]){
				return s1[i];	
			}
		}
	}
	return ' ';
}
