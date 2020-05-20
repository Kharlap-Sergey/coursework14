#include "mylib.h"

using namespace std;

ifstream in;
ofstream out;
char* read(const char* filename) {
	in.open(filename);
	char* pointer = new char[TextMaxLen];
	in.get(pointer, TextMaxLen - 10, '/');
	in.close();
	return pointer;
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

vector* readVector(const char* filename) {
	in.open(filename);
	int len;
	in >> len;
	double* vals = new double[len];
	for (int i = 0; i < len; i++) {
		in >> vals[i];
	}
	in.close();
	return init(len, vals);
}
vector* init(int len, double* vals) {
	vector* pattern = new vector;
	pattern->len = len;
	pattern->vals = vals;
	return pattern;
}

vector* add(vector* a, vector* b) {
	if (a->len < b->len) {
		swap(a, b);
	}

	for (int i = 0; i < b->len; i++) {
		a->vals[i] += b->vals[i];
	}
	return a;
}

vector* subtract(vector* a, vector* b) {
	if (a->len < b->len) {
		swap(a, b);
	}

	for (int i = 0; i < b->len; i++) {
		a->vals[i] -= b->vals[i];
	}
	return a;
}

vector* multiply(vector* a, vector* b) {
	if (a->len < b->len) {
		swap(a, b);
	}

	for (int i = 0; i < b->len; i++) {
		a->vals[i] *= b->vals[i];
	}
	return a;

}

vector* divide(vector* a, vector* b) {
	if (a->len < b->len) {
		swap(a, b);
	}

	for (int i = 0; i < b->len; i++) {
		if(b->vals[i] != 0)
			a->vals[i] /= b->vals[i];
	}
	return a;

}

char* getStringRepresentation(vector* a) {
	char* boof = new char[TextMaxLen];
	ofstream out;
	out.open("e.txt");
	out << '(';
	for(int i = 0; i < a->len; i++){
		out << a->vals[i];
		if (a->len - 1 != i) out << ", ";
	}
	out << ")/";
	out.close();
	ifstream in;
	in.open("e.txt");
	in.get(boof, TextMaxLen, '/');
	in.close();
	return boof;
}

char* getStringRepresentationforFIle(vector* a) {
	char* boof = new char[TextMaxLen];
	ofstream out;
	out.open("e.txt");
	out << a->len;
	for (int i = 0; i < a->len; i++) {
		out << ' ' << a->vals[i];
	}
	out << "/";
	out.close();
	ifstream in;
	in.open("e.txt");
	in.get(boof, TextMaxLen, '/');
	in.close();
	return boof;
}
