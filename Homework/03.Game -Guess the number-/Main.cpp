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

    int UserSolution{ 0 };
    UserSolution = getUserSolution(userName);

    int rangeMax{ 0 };
    int rangeMin{ 0 };
    int &pefRangeMax = rangeMax;
    int &pefRangeMin = rangeMin;

    if (UserSolution == 0)
    {
        helloFunc(userName, pefRangeMin, pefRangeMax);
    }
    else
    {
        helloFuncDifRange(userName, pefRangeMin, pefRangeMax);
    }

    int itrForGetNumFromUser{ 0 };
    itrForGetNumFromUser = compareNum(pefRangeMin, pefRangeMax);
   
    putInFile(userName, itrForGetNumFromUser);

    return 0;
}
