#pragma once

#include <iostream>

static int g_itrFor_getNumFromUser{ 0 }; // глобальная переменная для записи количества попыток 
//static std::string g_userName{ 0 }; // глобальная переменная для записи именни пользователя

std::string getUserName();
void compareNum(uint16_t userRangeMin, uint16_t userRangeMax);
void helloFuncDifRange(std::string userName);
void helloFunc(std::string userName);
void readFromFile();
void UserRangePrintTextQue();
void getUserSolution(std::string userName);
void putInFile(std::string userName);
