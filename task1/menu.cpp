#include "menu.h"

using namespace std;

void callMenu() {
	cout << "������� 0 - ��� ���������� ����������\n\
������� 1 - ��� ������ ���������� � ��������� �������;\n\
������� 2 - ��� �������� ��������� ���� � �����;\n\
������� 3 - ��� ���� �����������;\n����� ��������� ����� ����������\n";
	cout << "-------------------------------------------\n";
	int t ;
	cin >> t;
	switch (t) {
	case 0: {
		rewriteInputData();
		cout << "-------------------------------------------\n";
		break;
	}
	case 1: {
		showInput();
		cout << "-------------------------------------------\n";
		break;
	}
	case 2:{
		findeAndPrintAnswer();
		cout << "����� ��������\n";
		cout << "-------------------------------------------\n";
		break;
	}
	case 3: {
		showOutput();
		cout << "-------------------------------------------\n";
		break;
	}
	default: {
		cout << "����������!!!";
		return;
	}
	}

	callMenu();
}
void showInput() {
	char* text = read("input.txt");
	cout << "��������� �����...\n";
	cout << text << endl;
}
void showOutput() {
	char* text = read("output.txt");
	cout << "���������...\n";
	cout << text << endl;
}
void rewriteInputData() {
	cout << "������� ����� �� ������ ����� ��������������� �������� '/'\n";
	char* text = new char[TextMaxLen];
	cin.get(text, TextMaxLen - 10, '/');
	cout << text;
	cin.get();
	print("input.txt", text);
	cout << "\n���������� ��������� �������";
}

void findeAndPrintAnswer() {
	int* ANS = getAnswer();
	char* text = read("input.txt");
	
	print("output.txt", text, '\n');
	ofstream out;
	out.open("output.txt", ios::app);
	out << "����� � �������� ������ � �� ����������:\n";
	for (int i = 0; i < 40; i++)
		//cout << ANS[i] << endl;
		if (ANS[i] != 0) out << char('�' + i) << ' ' << ANS[i] << endl;
	out << '/';
	out.close();
}