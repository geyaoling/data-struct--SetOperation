#include "FileOperation.h"
#include <fstream>


// ���ļ��ж�ȡ����
void ReadFile(char* a, char* b) {
	// ���ļ��а��ж�ȡ
	ifstream infile;
	infile.open("I:/Microsoft Visual Studio/SetOperation/SetOperation/set.txt");
	infile >> a;
	infile >> b;

	// ����
	// cout << "����1:" << a << endl;
	// cout << "����2:" << b << endl;

	infile.close();  // �ر��ļ���
}


//д���ļ�����
void WriteToFile(OrderedSet L, char c) {
	ofstream outfile;
	outfile.open("I:/Microsoft Visual Studio/SetOperation/SetOperation/set.txt", ios::app);
	switch (c) {
	case 'u':
		outfile << "��������ǣ�" << endl;
		break;
	case 'i':
		outfile << "��������ǣ�" << endl;
		break;
	case 'd':
		outfile << "�����ǣ�" << endl;
		break;
	case 'c':
		outfile << "��������ǣ�" << endl;
		break;
	}
	LinkType p = L.head->next;
	while (p) {
		outfile << p->data;
		p = SuccNode(p);
	}
	outfile << "\n";
	outfile.close();
}