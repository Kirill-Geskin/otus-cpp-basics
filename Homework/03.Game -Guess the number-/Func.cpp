#include <iostream>
#include <random> // ��� std::random_device � std::mt19937
#include <fstream>
#include <string>
#include "func.h"

void UserRangePrintTextQue() //���������� ����� �� ������������ ������� �������� ? 
{
    std::cout << "Do you want to change the range of numbers with which you will play? " <<
        "By default, it is set from 0 to 99 inclusive. If yes then enter Y, if no then enter N. ?";
}

int getUserSolution(std::string userName) // ���������� ����� �� ������������ ������ �������� ����� ��� ����. 
{
    char userSolution{ 0 };
    std::cin >> userSolution;

    if (userSolution == 'Y')
    {
        return 1;
    }
    else if (userSolution == 'N')
    {
        return 0;
    }
}

int getUserRangeMin() // ������� ����������� �������� ���������, ���� ������������ ����� ��� �������� ��. ����� (bool getUserSolution())
{
    int userRangeMin{ 0 };
    std::cout << "Enter the minimum digit of the range" << std::endl;
    std::cin >> userRangeMin;

    return userRangeMin;
}

int getUserRangeMax() // ������� ������������ �������� ���������, ���� ������������ ����� ��� �������� ��. ����� (bool getUserSolution())
{
    int userRangeMax{ 0 };
    std::cout << "Enter the maximum digit of the range" << std::endl;
    std::cin >> userRangeMax;

    return userRangeMax;
}

int getRandomNum(int& pefRangeMin, int& pefRangeMax) // ��������� ���������� � ������������ �������� ����������. ���������������� ���� ������������ �� ����� ��� ����������� 0 � 99 , ���� �� �����. getUserSolution()
{
    int min = pefRangeMin;
    int max = pefRangeMax;
    std::random_device rd;
    std::mt19937 gen(rd()); //������������� ����� ��������
    std::uniform_int_distribution<> distrib(min, max);

    return distrib(gen);
}

std::string getUserName()
{
    std::cout << "Enter your name please. " << std::endl;
    std::string userName{ 0 };
    std::getline(std::cin, userName);

    return userName;
}

int getNumFromUser()
{
    std::cout << "Enter your number " << std::endl;
    int numFromUser{ 0 };
    std::cin >> numFromUser;

    return numFromUser;
}

void helloFunc(std::string userName, int &pefRangeMin,int &pefRangeMax) // ����, ������������ ��������� ������ ��������, �������� ����������� �������� 0 � 99.
{
    std::cout << "Hi, " << userName << "!\n" << "It's time to play the Game." << std::endl << "Guess the number between 0 and 99." << std::endl;
    pefRangeMin = 0;
    pefRangeMax = 99;
}

void helloFuncDifRange(std::string userName, int& pefRangeMin, int& pefRangeMax)
{
 
    pefRangeMin = getUserRangeMin();
    pefRangeMax = getUserRangeMax();
    std::cout << "Hi, " << userName << "!\n" << "It's time to play the Game." << std::endl
        << "Guess the number between " << pefRangeMin << " and " << pefRangeMax << '.' << std::endl;
}

int compareNum(int& pefRangeMin, int& pefRangeMax)
{
    int randomNum{ 0 };
    randomNum = getRandomNum(pefRangeMin, pefRangeMax);

    int itrForGetNumFromUser{ 0 };

    do {
        int numFromUser{ 0 };
        numFromUser = getNumFromUser();

        if (numFromUser > randomNum)
        {
            std::cout << "Less than " << numFromUser << std::endl;
            itrForGetNumFromUser++;
        }
        else if (numFromUser < randomNum)
        {
            std::cout << "Greater than " << numFromUser << std::endl;
            itrForGetNumFromUser++;
        }
        else
        {
            std::cout << "You won after " << itrForGetNumFromUser << " tries!" << std::endl;
            break;
        }

    } while (true);

    return itrForGetNumFromUser;
}

int putInFile(std::string userName, int itrForGetNumFromUser)
{
    std::ofstream dataFile("UserHighScore.txt", std::ios::app);

    if (!dataFile)
    {
        // �� ������� ��������� �� ������ � ��������� ������� exit()
        std::cerr << "Uh oh, UserHighScore.txt could not be opened for writing!" << std::endl;
        return 1;
    }

    dataFile << userName << " - " << itrForGetNumFromUser << std::endl;
    dataFile.close();

    return 0;
}

void readFromFile()
{
    std::ifstream dataFile("UserHighScore.txt");

    if (!dataFile)
    {
        //�� ������� ��������� �� ������ � ��������� ������� exit()
        std::cerr << "Uh oh, UserHighScore.txt could not be opened for reading!" << std::endl;
        exit(1);
    }

    while (dataFile)
    {
        std::string strInput;
        std::getline(dataFile, strInput);
        std::cout << strInput << std::endl;
    }
}

