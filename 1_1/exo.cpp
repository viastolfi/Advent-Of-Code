#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using std::vector;

int main(void){
	vector<int>* tab = new vector<int>;
	std::ifstream myfile; 
	int value = 0;

	myfile.open("input");
	std::string line;
	while (std::getline(myfile, line)){
		if(line.empty()){
			tab->push_back(value);
			value = 0;
		}else{
			value = value + stoi(line);
		}
	}

	std::vector<int>::const_iterator it;
	it = std::max_element(tab->begin(), tab->end());

	std::cout << *it << std::endl;
	return 0;
}
