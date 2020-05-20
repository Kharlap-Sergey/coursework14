#include <iostream>
#include <fstream>

const int TextMaxLen = 10000;

struct vector {
	double* vals;
	int len;
};

char* read(const char* filename); // ������ ���������� �� �����
void print(const char* filename, char* text, char c = '/'); // ����� ���������� � ����
void setConsoleLengvRus(); // ��������� ������� ����� � �������

vector* readVector(const char* filename);// ������ ������ �� �����
vector* init(int len, double* vals);// ������� ������ ������� len � ���������� �� vals
vector* add(vector* a, vector* b);// ��������� ��� �������, � ������ ������������ ������, �������� ����������� ������������ ��������
vector* subtract(vector* a, vector* b);//�������� ��� �������, � ������ ������������ ������ �������� ����������� ������������ ��������
vector* multiply(vector* a, vector* b);//�������� ��� �������, � ������ ������������ ������ �������� ����������� ������������ ��������
vector* divide(vector* a, vector* b);//����� ��� �������, � ������ ������������ ������ �������� ����������� ������������ ��������
char* getStringRepresentation(vector* a);//�������� ������������� ������� � ���� char
char* getStringRepresentationforFIle(vector* a);//�������� ������������� ������� � ���� char, �� ��� ������ ����������� �����