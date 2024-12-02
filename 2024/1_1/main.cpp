#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string> 

int main(int argc, char** argv)
{
    int out = 0;
    if (argc < 2)
    {
        std::cout << "Please give a input file name." << std::endl;
        exit(1);
    }

    std::vector<int> left;
    std::vector<int> right;

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
                right.push_back(stoi(buffer));
                buffer = "";
                continue;
            }
            else
            {
                buffer += c;
            }
        }

        std::sort(left.begin(), left.end());
        std::sort(right.begin(), right.end());

        for (int i = 0; i < left.size(); ++i)
        {
            out += abs(left[i] - right[i]);
        }
    }
    
    std::cout << "out : " << out << std::endl;
    return 0;
}
