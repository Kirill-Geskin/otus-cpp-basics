#pragma once

static uint16_t g_itrFor_getNumFromUser{ 0 }; // ���������� ���������� ��� ������ ���������� ������� 
static std::string g_userName{ 0 }; // ���������� ���������� ��� ������ ������ ������������

void getUserName();
void compareNum(uint16_t userRangeMin, uint16_t userRangeMax);
void helloFuncDifRange();
void helloFunc();
void readFromFile();
void UserRangePrintTextQue();
bool getUserSolution();
void putInFile(std::string userName, uint16_t g_itrFor_getNumFromUser);
