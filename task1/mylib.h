#include <iostream>
#include <fstream>

const int NL = 100; 
const int NUMW = 100; 
const int NW = 200; 
const int TextMaxLen = NL * NUMW * NW + 10;
const int LineMaxLen = NUMW * NW + 100;

char* read(const char* filename); // ������ ������ �� �����
void print(const char* filename, char* text, char c='/'); // ����� ������ � ����
void setConsoleLengvRus(); // ��������� ������� ����� � �������
int* getAnswer(); // ��������� �����, ����� � ������� ANS
bool isRusAlpha(char c); //�������� ������� 'c' �� �������������� � �������� ��������
char toLower(char c); // ������� ������� 'c' � ������ �������