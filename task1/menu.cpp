#include "menu.h"

using namespace std;

void callMenu() {
	cout << "введите 0 - для перезаписи информации\n\
введите 1 - для показа информации о введенном тексете;\n\
введите 2 - для подсчета вхождения букв в текст;\n\
введите 3 - для пока результатов;\nиначе программа будет завершнена\n";
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
		cout << "ответ посчитан\n";
		cout << "-------------------------------------------\n";
		break;
	}
	case 3: {
		showOutput();
		cout << "-------------------------------------------\n";
		break;
	}
	default: {
		cout << "Досвидания!!!";
		return;
	}
	}

	callMenu();
}
void showInput() {
	char* text = read("input.txt");
	cout << "введенный текст...\n";
	cout << text << endl;
}
void showOutput() {
	char* text = read("output.txt");
	cout << "результат...\n";
	cout << text << endl;
}
void rewriteInputData() {
	cout << "введите текст на руском языке заканчивающийся символом '/'\n";
	char* text = new char[TextMaxLen];
	cin.get(text, TextMaxLen - 10, '/');
	cout << text;
	cin.get();
	print("input.txt", text);
	cout << "\nперезапись выполнена успешно";
}

void findeAndPrintAnswer() {
	int* ANS = getAnswer();
	char* text = read("input.txt");
	
	print("output.txt", text, '\n');
	ofstream out;
	out.open("output.txt", ios::app);
	out << "буквы в веденном тексте и их количество:\n";
	for (int i = 0; i < 40; i++)
		//cout << ANS[i] << endl;
		if (ANS[i] != 0) out << char('а' + i) << ' ' << ANS[i] << endl;
	out << '/';
	out.close();
}