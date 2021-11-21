#include <iostream>
#include <string>
#include "func.h"

int main(int argc, char* argv[])
{
    for (int i = 1; argv[i]; i++)
    {
        if (std::string(argv[i]) == "-table")
        {
            readFromFile();
            return(0);
        }
    }

    std::string userName = getUserName();
    UserRangePrintTextQue();
    getUserSolution(userName);
    putInFile(userName);

    return 0;
}
