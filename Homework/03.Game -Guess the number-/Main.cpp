#include <iostream>
#include <string>
#include "DeclFunc.h"

int main(int argc, char* argv[])
{ 
    for (int i = 1; argv[i]; i++)
    {
        if (std::string(argv[i]) == "-table")
        {
            readFromFile();
            exit(0);
        }
    }
 
    getUserName();
    UserRangePrintTextQue();
    getUserSolution();
    putInFile(g_userName, g_itrFor_getNumFromUser);

    return 0;
}