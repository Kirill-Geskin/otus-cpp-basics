#pragma once

#include <iostream>

static int g_itrFor_getNumFromUser{ 0 }; // ���������� ���������� ��� ������ ���������� ������� 
//static std::string g_userName{ 0 }; // ���������� ���������� ��� ������ ������ ������������

std::string getUserName();
void compareNum(uint16_t userRangeMin, uint16_t userRangeMax);
void helloFuncDifRange(std::string userName);
void helloFunc(std::string userName);
void readFromFile();
void UserRangePrintTextQue();
void getUserSolution(std::string userName);
void putInFile(std::string userName);
