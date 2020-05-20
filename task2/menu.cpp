#include "menu.h"
#include "map"

using namespace std;

void callMenu() {
	cout << "введите 0 - для перезаписи информации\n\
введите 1 - для показа информации о сохраненном векторе;\n\
введите 2 - для нахождения повторяющихся элементов;\n\
введите 3 - для пока результатов;\n\
введите 4 - для выполнения операций над вектором\nиначе программа будет завершнена\n";
	cout << "-------------------------------------------\n";
	cout << "-------------------------------------------\n";
	int t;
	cin >> t;
	switch (t) {
	case 0: {
		rewriteInputData();
		cout << "-------------------------------------------\n";
		cout << "-------------------------------------------\n";
		break;
	}
	case 1: {
		showInput();
		cout << "-------------------------------------------\n";
		cout << "-------------------------------------------\n";
		break;
	}
	case 2: {
		calcAns();
		cout << "ответ посчитан\n";
		cout << "-------------------------------------------\n";
		cout << "-------------------------------------------\n";
		break;
	}
	case 3: {
		showOutput();
		cout << "-------------------------------------------\n";
		cout << "-------------------------------------------\n";
		break;
	}
	case 4: {
		callOperationMenu();
		break;
	}
	default: {
		cout << "Досвидания!!!";
		return;
	}
	}

	callMenu();
}

void calcAns() {
	vector* a = readVector("input.txt");
	map <double, int> m;
	for (int i = 0; i < a->len; i++) {
		m[a->vals[i]] = 0;
	}

	for (int i = 0; i < a->len; i++) {
		m[a->vals[i]]++;
	}

	int len = 0;
	for (auto e = m.begin(); e != m.end(); e++) {
		if (e->second > 1) len++;
	}
	double* vals = new double[len];
	len = 0;
	for (auto e = m.begin(); e != m.end(); e++) {
		if (e->second > 1) vals[len] = e->first, len++;
	}

	vector* b = init(len, vals);
	print("output.txt", getStringRepresentation(b));
}
void showInput() {
	char* text = read("input.txt");
	cout << "сохраненный вектор...\n";
	cout << text << endl;
}
void showOutput() {
	char* text = read("output.txt");
	cout << "результат...\n";
	cout << text << endl;
}
void rewriteInputData() {
	vector* a = readVectorFromConsole();
	print("input.txt", getStringRepresentationforFIle(a));
	cout << "\nперезапись выполнена успешно\n";
}

void callOperationMenu() {
	cout << "введите 0 - для операции сложения\n\
введите 1 - для операции вычитания;\n\
введите 2 - для операции умножения;\n\
введите 3 - для операции деления;\n\
иначе программа будет совершен выход из данного режима\n!!!Внимание результат будет загружен в память!!!\n";
	cout << "-------------------------------------------\n";
	cout << "-------------------------------------------\n";
	int t;
	cin >> t;
	switch (t) {
	case 0: {
		cout << "операция сложения:\n";
		vector* a = readVector("input.txt");
		cout << "ваш вектор - " << getStringRepresentation(a) << endl;
		vector* b = readVectorFromConsole();
		print("input.txt", getStringRepresentationforFIle(add(a, b)));
		cout << "результат:\n";
		cout << getStringRepresentation(readVector("input.txt")) << endl;
		cout << "-------------------------------------------\n";
		cout << "-------------------------------------------\n";
		break;
	}
	case 1: {
		cout << "операция вычитания:\n";
		vector* a = readVector("input.txt");
		cout << "ваш вектор - " << getStringRepresentation(a) << endl;
		vector* b = readVectorFromConsole();
		print("input.txt", getStringRepresentationforFIle(subtract(a, b)));
		cout << "результат:\n";
		cout << getStringRepresentation(readVector("input.txt")) << endl;
		cout << "-------------------------------------------\n";
		cout << "-------------------------------------------\n";
		break;
	}
	case 2: {
		cout << "операция умножения:\n";
		vector* a = readVector("input.txt");
		cout << "ваш вектор - " << getStringRepresentation(a) << endl;
		vector* b = readVectorFromConsole();
		print("input.txt", getStringRepresentationforFIle(multiply(a, b)));
		cout << "результат:\n";
		cout << getStringRepresentation(readVector("input.txt")) << endl;
		cout << "-------------------------------------------\n";
		cout << "-------------------------------------------\n";
		break;
	}
	case 3: {
		cout << "операция деления:\n";
		vector* a = readVector("input.txt");
		cout << "ваш вектор - " << getStringRepresentation(a) << endl;
		vector* b = readVectorFromConsole();
		print("input.txt", getStringRepresentationforFIle(divide(a, b)));
		cout << "результат:\n";
		cout << getStringRepresentation(readVector("input.txt")) << endl;
		cout << "-------------------------------------------\n";
		cout << "-------------------------------------------\n";
		break;
	}
	default: {
		return;
	}
	}

	callOperationMenu();
}

vector* readVectorFromConsole() {
	cout << "Введите длинну вектора:\n";
	int len;
	cin >> len;
	cout << "Введите сам вектор:\n";
	double* vals = new double[len];
	for (int i = 0; i < len; i++) {
		cin >> vals[i];
	}
	return init(len, vals);
}