#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <map>

int main(int argc, char** argv)
{
    int out = 0;
    std::vector<int> left;
    std::map<int, int> right;
    if (argc < 2)
    {
        std::cout << "Please give a input file name." << std::endl;
        exit(1);
    }
    
    std::ifstream inputFile (argv[1]);

    if (inputFile.is_open()) 
    {
        char c;
        std::string buffer;
        while (inputFile) 
        {
            c = inputFile.get();
            if (c == ' ')
            {
                if (buffer != "") 
                {
                    left.push_back(stoi(buffer));
                    buffer = "";
                }
                continue;
            }
            else if (c == '\n')
            {
                int v = stoi(buffer);
                if (right.find(v) != right.end()) 
                {
                    right[v] += 1;
                }
                else 
                {
                    right.insert(std::make_pair(v, 1));
                }
                buffer = "";
                continue;
            }
            else
            {
                buffer += c;
            }
        }

        for (int i = 0; i < left.size(); ++i)
        {
           out += right.find(left[i]) != right.end() ? left[i] * right[left[i]] : 0;
        }
    }

    std::cout << "Out : " << out << std::endl;

    return 0;
}
