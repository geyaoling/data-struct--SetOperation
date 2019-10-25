#include "FileOperation.h"
#include <fstream>


// 从文件中读取数据
void ReadFile(char* a, char* b) {
	// 从文件中按行读取
	ifstream infile;
	infile.open("I:/Microsoft Visual Studio/SetOperation/SetOperation/set.txt");
	infile >> a;
	infile >> b;

	// 测试
	// cout << "集合1:" << a << endl;
	// cout << "集合2:" << b << endl;

	infile.close();  // 关闭文件流
}


//写入文件操作
void WriteToFile(OrderedSet L, char c) {
	ofstream outfile;
	outfile.open("I:/Microsoft Visual Studio/SetOperation/SetOperation/set.txt", ios::app);
	switch (c) {
	case 'u':
		outfile << "并集结果是：" << endl;
		break;
	case 'i':
		outfile << "交集结果是：" << endl;
		break;
	case 'd':
		outfile << "差集结果是：" << endl;
		break;
	case 'c':
		outfile << "补集结果是：" << endl;
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