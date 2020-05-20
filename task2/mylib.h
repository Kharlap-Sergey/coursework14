#include <iostream>
#include <fstream>

const int TextMaxLen = 10000;

struct vector {
	double* vals;
	int len;
};

char* read(const char* filename); // чтение информации из файла
void print(const char* filename, char* text, char c = '/'); // вывод информации в файл
void setConsoleLengvRus(); // установка руского языка в консоли

vector* readVector(const char* filename);// читает вектор из файла
vector* init(int len, double* vals);// создает вектор длинной len и элементами из vals
vector* add(vector* a, vector* b);// слаживает два вектора, в случае несовпадения длинны, операция проводиться относительно длинного
vector* subtract(vector* a, vector* b);//отнимает два вектора, в случае несовпадения длинны операция проводиться относительно длинного
vector* multiply(vector* a, vector* b);//умножает два вектора, в случае несовпадения длинны операция проводиться относительно длинного
vector* divide(vector* a, vector* b);//делит два вектора, в случае несовпадения длинны операция проводиться относительно длинного
char* getStringRepresentation(vector* a);//получает представление вектора в типе char
char* getStringRepresentationforFIle(vector* a);//получает представление вектора в типе char, но для послед корректного воода