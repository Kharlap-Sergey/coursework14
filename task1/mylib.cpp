#include "mylib.h"

using namespace std;

int ANS[40];
ifstream in;
ofstream out;
char* read(const char* filename) {
	in.open(filename);
	char* pointer = new char[TextMaxLen];
	in.get(pointer, TextMaxLen-10, '/');
	in.close();
	return pointer;
}

bool isRusAlpha(char c) {
	bool ans = '�' <= c && c <= '�';
	return ans;
}

char toLower(char c) {
	if (c >= '�' && c <= '�') {
		c = c + 32;
	}
	return c;
}

int* getAnswer() {
	char* text;
	text = read("input.txt");

	for (int i = 0; i < 30; i++)
		ANS[i] = 0;
	for (int i = 0; text[i] != '\0'; i++) {
		if (isRusAlpha(text[i])) {
			char c = toLower(text[i]);
			int pos = c - '�';
			ANS[pos]++;
		}
	}

	return ANS;
}

void print(const char* OUT, char* text, char c) {
	out.open(OUT);
	out << text;
	out << c;
	out.close();
}

void setConsoleLengvRus() {
	system("chcp 1251");
	setlocale(LC_ALL, "rus");
}