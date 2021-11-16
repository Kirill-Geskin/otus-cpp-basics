#include <iostream>
#include <random> // ��� std::random_device � std::mt19937
#include <fstream>
#include <string>
#include "DeclFunc.h"

void UserRangePrintTextQue() //���������� ����� �� ������������ ������� �������� ? 
{
    std::cout << "Do you want to change the range of numbers with which you will play? " <<
        "By default, it is set from 0 to 99 inclusive. If yes then enter Y, if no then enter N. ?";
}

void getUserSolution() // ���������� ����� �� ������������ ������ �������� ����� ��� ����. 
{
    char userSolution{ 0 };
    std::cin >> userSolution;

    if (userSolution == 'Y')
    {
        helloFuncDifRange();
    }
    else if (userSolution == 'N')
    {
        helloFunc();
    }
}

uint16_t getUserRangeMin() // ������� ����������� �������� ���������, ���� ������������ ����� ��� �������� ��. ����� (bool getUserSolution())
{
    uint16_t userRangeMin{ 0 };
    std::cout << "Enter the minimum digit of the range" << std::endl;
    std::cin >> userRangeMin;

    return userRangeMin;
}

uint16_t getUserRangeMax() // ������� ������������ �������� ���������, ���� ������������ ����� ��� �������� ��. ����� (bool getUserSolution())
{
    uint16_t userRangeMax{ 0 };
    std::cout << "Enter the maximum digit of the range" << std::endl;
    std::cin >> userRangeMax;

    return userRangeMax;
}

uint16_t getRandomNum(uint16_t userRangeMin, uint16_t userRangeMax) // ��������� ���������� � ������������ �������� ����������. ���������������� ���� ������������ �� ����� ��� ����������� 0 � 99 , ���� �� �����.(bool getUserSolution())
{
    std::random_device rd;
    std::mt19937 gen(rd()); //������������� ����� ��������
    std::uniform_int_distribution<> distrib(userRangeMin, userRangeMax);

    return distrib(gen);
}

void getUserName()
{
    std::cout << "Enter your name please. " << std::endl;
    std::string userName{ 0 };
    std::getline(std::cin, userName);
    g_userName = userName;
}

uint16_t getNumFromUser()
{
    std::cout << "Enter your number " << std::endl;
    uint16_t numFromUser{ 0 };
    std::cin >> numFromUser;

    ++g_itrFor_getNumFromUser;

    return numFromUser;
}

void helloFunc() // ����, ������������ ��������� ������ ��������, �������� ����������� �������� 0 � 99.
{
    std::cout << "Hi, " << g_userName << "!\n" << "It's time to play the Game." << std::endl << "Guess the number between 0 and 99." << std::endl;
    compareNum(0, 99);
}

void helloFuncDifRange()
{
    uint16_t userRangeMin{ 0 };
    uint16_t userRangeMax{ 0 };
    userRangeMin = getUserRangeMin();
    userRangeMax = getUserRangeMax();
    std::cout << "Hi, " << g_userName << "!\n" << "It's time to play the Game." << std::endl
        << "Guess the number between " << userRangeMin << " and " << userRangeMax << '.' << std::endl;
    compareNum(userRangeMin, userRangeMax);
}

void compareNum(uint16_t userRangeMin, uint16_t userRangeMax)
{
    uint16_t randomNum{ 0 };
    randomNum = getRandomNum(userRangeMin, userRangeMax);

    do {
        uint16_t numFromUser{ 0 };
        numFromUser = getNumFromUser();

        if (numFromUser > randomNum)
        {
            std::cout << "Less than " << numFromUser << std::endl;
        }
        else if (numFromUser < randomNum)
        {
            std::cout << "Greater than " << numFromUser << std::endl;
        }
        else
        {
            std::cout << "You won after " << g_itrFor_getNumFromUser << " tries!" << std::endl;
            break;
        }

    } while (true);
}

void putInFile(std::string userName, uint16_t g_itrFor_getNumFromUser)
{
    std::ofstream dataFile("UserHighScore.txt", std::ios::app);

    if (!dataFile)
    {
        // �� ������� ��������� �� ������ � ��������� ������� exit()
        std::cerr << "Uh oh, UserHighScore.txt could not be opened for writing!" << std::endl;
        exit(1);
    }

    dataFile << userName << " - " << g_itrFor_getNumFromUser << std::endl;
    dataFile.close();
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
