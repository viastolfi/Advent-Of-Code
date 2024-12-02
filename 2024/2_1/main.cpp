#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <map>

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

        for (int i = 0; i < datas.size(); ++i)
        {
            for (int j = 0; j < datas[i].size() - 1; ++j)
            {
                int dif = datas[i][j] - datas[i][j + 1];
                if (abs(dif) > 3 || dif == 0)
                {
                   break; 
                }
                if (j != 0)
                {
                    int s = dif * (datas[i][j-1] - datas[i][j]);
                    if (s < 0)
                    {
                        break;
                    }
                }
                if (j+1 == datas[i].size() - 1)
                {
                    out += 1;
                    break;
                } 
            }
        }
    }

    std::cout << "Out : " << out << std::endl;

    return 0;
}
