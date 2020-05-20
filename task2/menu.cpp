#include "menu.h"
#include "map"

using namespace std;

void callMenu() {
	cout << "������� 0 - ��� ���������� ����������\n\
������� 1 - ��� ������ ���������� � ����������� �������;\n\
������� 2 - ��� ���������� ������������� ���������;\n\
������� 3 - ��� ���� �����������;\n\
������� 4 - ��� ���������� �������� ��� ��������\n����� ��������� ����� ����������\n";
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
		cout << "����� ��������\n";
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
		cout << "����������!!!";
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
	cout << "����������� ������...\n";
	cout << text << endl;
}
void showOutput() {
	char* text = read("output.txt");
	cout << "���������...\n";
	cout << text << endl;
}
void rewriteInputData() {
	vector* a = readVectorFromConsole();
	print("input.txt", getStringRepresentationforFIle(a));
	cout << "\n���������� ��������� �������\n";
}

void callOperationMenu() {
	cout << "������� 0 - ��� �������� ��������\n\
������� 1 - ��� �������� ���������;\n\
������� 2 - ��� �������� ���������;\n\
������� 3 - ��� �������� �������;\n\
����� ��������� ����� �������� ����� �� ������� ������\n!!!�������� ��������� ����� �������� � ������!!!\n";
	cout << "-------------------------------------------\n";
	cout << "-------------------------------------------\n";
	int t;
	cin >> t;
	switch (t) {
	case 0: {
		cout << "�������� ��������:\n";
		vector* a = readVector("input.txt");
		cout << "��� ������ - " << getStringRepresentation(a) << endl;
		vector* b = readVectorFromConsole();
		print("input.txt", getStringRepresentationforFIle(add(a, b)));
		cout << "���������:\n";
		cout << getStringRepresentation(readVector("input.txt")) << endl;
		cout << "-------------------------------------------\n";
		cout << "-------------------------------------------\n";
		break;
	}
	case 1: {
		cout << "�������� ���������:\n";
		vector* a = readVector("input.txt");
		cout << "��� ������ - " << getStringRepresentation(a) << endl;
		vector* b = readVectorFromConsole();
		print("input.txt", getStringRepresentationforFIle(subtract(a, b)));
		cout << "���������:\n";
		cout << getStringRepresentation(readVector("input.txt")) << endl;
		cout << "-------------------------------------------\n";
		cout << "-------------------------------------------\n";
		break;
	}
	case 2: {
		cout << "�������� ���������:\n";
		vector* a = readVector("input.txt");
		cout << "��� ������ - " << getStringRepresentation(a) << endl;
		vector* b = readVectorFromConsole();
		print("input.txt", getStringRepresentationforFIle(multiply(a, b)));
		cout << "���������:\n";
		cout << getStringRepresentation(readVector("input.txt")) << endl;
		cout << "-------------------------------------------\n";
		cout << "-------------------------------------------\n";
		break;
	}
	case 3: {
		cout << "�������� �������:\n";
		vector* a = readVector("input.txt");
		cout << "��� ������ - " << getStringRepresentation(a) << endl;
		vector* b = readVectorFromConsole();
		print("input.txt", getStringRepresentationforFIle(divide(a, b)));
		cout << "���������:\n";
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
	cout << "������� ������ �������:\n";
	int len;
	cin >> len;
	cout << "������� ��� ������:\n";
	double* vals = new double[len];
	for (int i = 0; i < len; i++) {
		cin >> vals[i];
	}
	return init(len, vals);
}