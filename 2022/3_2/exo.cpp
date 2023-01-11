#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using std::vector;
using std::string;

void input(vector<string>* vect);
char getCommon(string s1, string s2, string s3);
int calcCharValue(char c);

int main(void){
	vector<string>* in= new vector<string>;
	int res = 0;

	input(in);

	for(vector<string>::iterator it = in->begin(); it != in->end(); it = it+3){
		res = res + calcCharValue(getCommon(*it, *(it+1), *(it+2)));
	}
	
	std::cout << res << std::endl;
}

void input(vector<string>* vect){
	while(1){
		string line;
		std::cin >> line;
		if(line == ""){
			return;
		}
		vect->push_back(line);
	}
}

char getCommon(string s1, string s2, string s3){
	std::unordered_set<char> set1;
	std::unordered_set<char> set2;
	for(int i=0; i<s1.length(); i++){
		set1.insert(s1[i]);
	}

	for(int i=0; i<s2.length(); i++){
		if(set1.count(s2[i]) > 0){
			set2.insert(s2[i]);
		}
	}

	for(int i=0; i<s3.length(); i++){
		if(set2.count(s3[i]) > 0){
			return s3[i];
		}
	}
	return '\0';
}

int calcCharValue(char c){
	return (c >= 'a' && c <= 'z')? c - 'a' + 1: c - 'A' + 27;
}
