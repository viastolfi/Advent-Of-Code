#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <map>

bool checkSafe(std::vector<int> level)
{
    bool inc = false;
    bool dec = false;

    for (int i = 0; i < level.size() - 1; ++i)
    {
        int dif = level[i] - level[i + 1];
        if (abs(dif) > 3 || dif == 0)
            return false;
        
        if (level[i] > level[i + 1])
            dec = true;

        if (level[i] < level[i + 1])
            inc = true;

        if (dec && inc)
            return false;
    }

    return true;
}

int main(int argc, char** argv)
{
    int out = 0;
    std::vector<std::vector<int> > datas;
    std::vector<int> level;
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
                level.push_back(stoi(buffer));
                buffer = "";
                continue;
            }
            else if (c == '\n')
            {
                level.push_back(stoi(buffer));
                datas.push_back(level);
                level.clear();
                buffer = "";
                continue;
            }
            else 
            {
                buffer += c;
                continue;
            }
        }
    }

        for (int i = 0; i < datas.size(); ++i)
        {
            if (checkSafe(datas[i]))
                out++;
            else
            {
                for (int j = 0; j < datas[i].size(); ++j)
                {
                    std::vector<int> tmp(datas[i]);
                    tmp.erase(tmp.begin() + j);

                    if (checkSafe(tmp))
                    {
                        out++;
                        break;
                    }
                }
            }
        }

    std::cout << "Out : " << out << std::endl;

    return 0;
}
