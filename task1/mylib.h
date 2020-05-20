#include <iostream>
#include <fstream>

const int NL = 100; 
const int NUMW = 100; 
const int NW = 200; 
const int TextMaxLen = NL * NUMW * NW + 10;
const int LineMaxLen = NUMW * NW + 100;

char* read(const char* filename); // чтение текста из файла
void print(const char* filename, char* text, char c='/'); // вывод текста в файл
void setConsoleLengvRus(); // установка руского языка в консоли
int* getAnswer(); // получение отвеа, ответ в массиве ANS
bool isRusAlpha(char c); //проверка символа 'c' на пренадлежность к русскому алфовиту
char toLower(char c); // перевод символа 'c' в нижний регистр