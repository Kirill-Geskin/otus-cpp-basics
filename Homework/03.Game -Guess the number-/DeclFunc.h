#pragma once

static uint16_t g_itrFor_getNumFromUser{ 0 }; // глобальная переменная для записи количества попыток 
static std::string g_userName{ 0 }; // глобальная переменная для записи именни пользователя

void getUserName();
void compareNum(uint16_t userRangeMin, uint16_t userRangeMax);
void helloFuncDifRange();
void helloFunc();
void readFromFile();
void UserRangePrintTextQue();
bool getUserSolution();
void putInFile(std::string userName, uint16_t g_itrFor_getNumFromUser);
