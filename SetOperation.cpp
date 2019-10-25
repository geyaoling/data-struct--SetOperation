// SetOperation.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Node.h"
#include "OrderedList.h"
#include "OederedSet.h"
#include "Constants.h"
#include <windows.h>  // 设置控制台字体颜色 设置字体颜色
#include <fstream>    //  文件操作输入输出
#include "FileOperation.h"

using namespace std;   // C++命名空间


// 定义全局变量

OrderedList L1, L2, L3;
// char a[100] = "magzine";
// char b[100] = "paper";

// 定义字符串数组保存数据
char a[100];
char b[100];



// 函数声明

// 获取屏幕光标位置
void gotoxy(int x, int y);

// 文字颜色函数      
// 此函数的局限性：1、只能Windows系统下使用   
//                 2、不能改变背景颜色
int color(int c);

// 展示菜单页面
void ShowMenu();

// 读入操作命令符
void ReadCommand(char& cmd);

// 解释执行操作命令
void Interpret(char cmd,char &elemType);

// 绘制小花
void DrawFlower();

// 绘制兔子
void DrawRabbit();

// 打印初始界面边框
void PrintFirstBorder();
// 打印显示界面边框
void PrintSecondBorder();


int main()
{
	
	// 从文件中读取数据
	ReadFile(a, b);
	

	// 选择操作的数据类型
	char elemType = '1'; // 默认为1  小写字母


	
	// 接受输入的命令
	char cmd;
	do {
		ShowMenu();

		 ReadCommand(cmd);

		 Interpret(cmd, elemType);
	} while (cmd != 'q');
	
	system("pause");
	return 0;
	
}


// 展示菜单页面
void ShowMenu() {
	
	color(3);
	gotoxy(0, 3);
	cout << "                             ■■■■    ■■■■    ■■■■■                     \n";
	gotoxy(0, 4);
	cout << "                             ■          ■              ■                         \n";
	gotoxy(0, 5);
	cout << "                             ■          ■              ■                         \n";
	gotoxy(0, 6);
	cout << "                             ■■■■    ■■■■        ■                       \n";
	gotoxy(0, 7);
	cout << "                                   ■    ■              ■                        \n";
	gotoxy(0, 8);
	cout << "                                   ■    ■              ■                        \n";
	gotoxy(0, 9);
	cout << "                             ■■■■    ■■■■        ■                        \n";


	gotoxy(42, 10);
	color(11);
	cout << "集合操作\n";

	color(10);

	cout << "****************************************************************************************\n";  // 88 个星星
	cout << "*MakeSet1-1 MakeSet2-2  Union-u Intersaction-i  Diffenrence-d  Display-y Quit-q*********\n";
	cout << "****************************************************************************************\n";
	
	


	// 显示选项
	gotoxy(30, 16);
	cout << "0. 选择操作集合的数据类型--r";
	gotoxy(25, 18);
	cout << "1. 创建集合1--1";
	gotoxy(50, 18);
	cout << "2. 创建集合2--2";
	gotoxy(25, 20);
	cout << "3. 子集判定--s";
	gotoxy(50, 20);
	cout << "4. 求两个集合的并集--u";
	gotoxy(25, 22);
	cout << "5. 求两个集合的交集--i";
	gotoxy(50, 22);
	cout << ("6. 求两个集合的差集--d");
	gotoxy(25, 24);
	cout << "7. 求集合的补集--c";
	gotoxy(50, 24);
	cout << "8. 展示结果--y";
	gotoxy(40, 26);
	cout << "9. 退出程序--q";



	DrawRabbit();


	PrintFirstBorder();



	color(10);
	cout << "\n****************************************************************************************\n";
	cout << "*                              Enter an operation code!                                *\n";
	cout << "****************************************************************************************\n";
	
	
	
	

}

// 读入操作命令符
void ReadCommand(char& cmd) {
	gotoxy(30, 28);
	cout<<"请选择操作：[ ]\b\b";
	cmd = getchar();
}


// 解释执行操作命令
void Interpret(char cmd,char &elemType) {
	system("cls");

	// 打印显示界面边框
	PrintSecondBorder();
	// 画小花
	DrawFlower();

	switch (cmd)
	{
	case 'r':  // 选择操作集合的数据类型
		 getchar();

		system("color 97"); // 设置背景颜色与前景颜色

		// 用户需要得到的数据类型  1. 小写字母 a-z  2. 大写字母 A-Z  3. 数字 0-9
		gotoxy(40, 15);
		cout << "1. 小写字母 \n";
		gotoxy(40, 17);
		cout << "2. 大写字母 \n";
		gotoxy(40, 19);
		cout << "3. 数字 \n";
		gotoxy(40, 21);
		cout << "请选择要操作的数据类型：[ ]\b\b";
		elemType = getchar();
		
		
		gotoxy(40, 23);
		cout << "请按回车继续！\n";
		getchar(); system("cls");

		// 思考如何使用清除键盘缓存
		// fflush(stdout);

		system("color 07");   // 恢复默认背景颜色和前景颜色
		break;
	case '1':  // 创建集合1
		getchar();


		gotoxy(30, 15);
		cout << "请输入字符串：";

		scanf_s("%[^\n]", a, (unsigned int)sizeof(a));
		gotoxy(30, 17);
		cout << "原始字符串：";
		cout <<a<<endl;


		CreateSet(L1, a, elemType);
		gotoxy(30, 19);
		cout << "构建的集合:";
		PrintSet(L1);
		
		// 用完就销毁
		DestroyList(L1);

		gotoxy(30, 21);
		cout << "请按回车继续！\n";
		getchar(); getchar(); system("cls");
		break;
	case '2':   // 创建集合2
		getchar();  // 吃掉回车符

		gotoxy(30, 15);
		cout << "请输入字符串：";
		scanf_s("%[^\n]", b, (unsigned int)sizeof(b));
		gotoxy(30, 17);
		cout << "原始字符串：";
		cout <<b<<endl;


		CreateSet(L2, b, elemType);
		gotoxy(30, 19);
		cout << "构建的集合:";
		PrintSet(L2);
		
		// 用完就销毁
		DestroyList(L2);

		gotoxy(30, 21);
		cout << "请按回车继续！\n";
		getchar(); getchar(); system("cls");
		break;
	case 's':  // 判断L2是否为L1的子集
		getchar();

		CreateSet(L1, a, elemType);
		gotoxy(30, 15);
		cout << "Set1：";
		PrintSet(L1);
		CreateSet(L2, b, elemType);
		gotoxy(30, 17);
		cout << "Set2：";
		PrintSet(L2);

		if (SubSet(L1,L2))
		{
			gotoxy(30, 19);
			cout << "集合2是集合1的子集";
		}
		else {
			gotoxy(30, 19);
			cout << "集合2不是集合1的子集";
		}


		// 用完就销毁
		DestroyList(L1);
		DestroyList(L2);


		gotoxy(30, 21);
		cout << "请按回车继续！\n";
		getchar(); getchar(); system("cls");
		break;
	case 'u':  // 求并集
		CreateSet(L1, a, elemType);
		CreateSet(L2, b, elemType);
		Union(L3, L1, L2);
		gotoxy(30, 15);
		cout << "集合1:";
		PrintSet(L1);
		
		gotoxy(30, 17);
		cout << "集合2:";
		PrintSet(L2);
		
		gotoxy(30, 19);
		cout << "并集:";
		PrintSet(L3);

		WriteToFile(L3, 'u');

		// 用完就销毁
		DestroyList(L1);
		DestroyList(L2);
		DestroyList(L3);
		
		gotoxy(30, 21);
		cout << "请按回车继续！\n";
		getchar(); getchar(); system("cls");
		break;
	case 'i':  // 求交集
		CreateSet(L1, a, elemType);
		CreateSet(L2, b, elemType);
		Intersaction(L3, L1, L2);
		gotoxy(30, 15);
		cout << "集合1:";
		PrintSet(L1);
		
		gotoxy(30, 17);
		cout << "集合2:";
		PrintSet(L2);
		
		gotoxy(30, 19);
		cout << "交集:";
		PrintSet(L3);

		WriteToFile(L3, 'i');
		

		// 用完就销毁
		DestroyList(L1);
		DestroyList(L2);
		DestroyList(L3);


		gotoxy(30, 21);
		cout << "请按回车继续！\n";
		getchar(); getchar(); system("cls");
		break;
	case 'd':  // 求差集
		CreateSet(L1, a, elemType);
		CreateSet(L2, b, elemType);
		Difference(L3, L1, L2);
		gotoxy(30, 15);
		cout << "集合1:";
		PrintSet(L1);
		
		gotoxy(30, 17);
		cout << "集合2:";
		PrintSet(L2);
		
		gotoxy(30, 19);
		cout << "差集:";
		PrintSet(L3);

		WriteToFile(L3, 'd');

		// 用完就销毁
		DestroyList(L1);
		DestroyList(L2);
		DestroyList(L3);

		
		gotoxy(30, 21);
		cout << "请按回车继续！\n";
		getchar(); getchar(); system("cls");
		break;
	case 'c':  // 求集合的补集
		getchar();



		// 改动之前
		char m[100];
		gotoxy(30, 15);
		cout << "请输入字符串：";

		scanf_s("%[^\n]", m, (unsigned int)sizeof(m));
		CreateSet(L1, m, elemType);


		gotoxy(30, 17);
		cout << "构建的集合:";
		PrintSet(L1);

		Complementary(L3, L1, elemType);



		gotoxy(30, 19);
		cout << "补集:";
		PrintSet(L3);

		WriteToFile(L3, 'c');

		// 用完就销毁
		DestroyList(L1);
		DestroyList(L3);
		
		gotoxy(30, 21);
		cout << "请按回车继续！\n";
		getchar(); getchar(); system("cls");
		break;
	case 'y':  // 展示集合
		CreateSet(L1, a, elemType);
		CreateSet(L2, b, elemType);
		gotoxy(30, 15);
		cout << "集合1:";
		PrintSet(L1);
		
		gotoxy(30, 17);
		cout << "集合2:";
		PrintSet(L2);
		

		Union(L3, L1, L2);
		gotoxy(30, 19);
		cout << "并集:";
		PrintSet(L3);
		

		Intersaction(L3, L1, L2);
		gotoxy(30, 21);
		cout << "交集:";
		PrintSet(L3);
		

		Difference(L3, L1, L2);
		gotoxy(30, 23);
		cout << "差集:";
		PrintSet(L3);

		// 用完就销毁
		DestroyList(L1);
		DestroyList(L2);
		DestroyList(L3);

		

		gotoxy(30, 25);
		cout << "请按回车继续！\n";
		getchar(); getchar(); system("cls");
		break;
	case 'q':   // 推出程序
		gotoxy(30, 15);
		cout << "成功退出系统!\n";
		exit(0);
		getchar(); getchar(); system("cls");
		break;
	default:
		gotoxy(30, 15);
		cout << "输入有误!\n";
		exit(0);
		break;
	}
}




/**
 * 获取屏幕光标位置
 */
void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/**
 * 文字颜色函数      此函数的局限性：1、只能Windows系统下使用   2、不能改变背景颜色
 */
int color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);        //更改文字颜色
	return 0;
}


// 绘制小花
void DrawFlower() {
	gotoxy(66,22);
	color(12);
	cout << "(_)";

	gotoxy(64,23);
	color(12);
	cout << "(_)";

	gotoxy(67,23);
	color(6);
	cout << "@";

	gotoxy(68,23);
	color(12);
	cout << "(_)";

	gotoxy(66,24);
	color(12);
	cout << "(_)";

	gotoxy(70,24);
	color(6);
	cout << "\\";       //注意、\为转义字符。想要输入\，必须在前面需要转义

	gotoxy(70,25);
	color(6);
	cout << "`|/";

	gotoxy(70,26);
	color(6);
	cout << "\\|";

	gotoxy(71,27);
	color(6);
	cout << "| /";

	gotoxy(67,28);
	color(10);
	cout << "\\\\\\\\";

	gotoxy(71,28);
	color(6);
	cout << "|";

	gotoxy(73,28);
	color(10);
	cout << "//";

	gotoxy(67,29);
	color(10);
	cout << "^^^^^^^^";
}

// 绘制兔子
void DrawRabbit() {
	color(3);
	gotoxy(72, 20);
	cout << "┏-┓  ┏-┓";
	gotoxy(72, 21);
	cout << "┃ ┃  ┃ ┃";
	gotoxy(72, 22);
	cout << "┃ ┃  ┃ ┃";
	gotoxy(71, 23);
	cout << "_┃";
	gotoxy(82, 23);
	cout << "┃_";
	gotoxy(70, 24);
	cout << ("┃");
	gotoxy(84, 24);
	cout << "┃";
	gotoxy(70, 25);
	cout << "┃            ┃";
	gotoxy(70, 26);
	cout << "┃";
	gotoxy(84, 26);
	cout << "┃";
	gotoxy(70, 27);
	cout << "┃            ┃";
	gotoxy(70, 28);
	cout << "┗━┳━━┳━┛";
	gotoxy(72, 29);
	cout << "┏┫    ┣┓";
	gotoxy(70, 30);
	cout << "—┺┻━┻┻┹—";
	color(5);
	gotoxy(75, 23);
	cout << "`~ ＇~`";
	color(4);
	gotoxy(75, 24);
	cout << "○   ○";
	color(13);
	gotoxy(73, 25);
	cout << "〃";
	gotoxy(82, 25);
	cout << "〃";
	color(12);
	gotoxy(77, 27);
	cout << "┻";
}
	


// 打印初始界面边框
void PrintFirstBorder() {
	int i, j = 1;

	color(14);             //黄色边框
	for (i = 14; i <= 30; i++)    //输出上下边框===
	{
		for (j = 0; j <= 88; j++)  //输出左右边框||
		{
			gotoxy(j, i);
			if (i == 14 || i == 30) cout << "=";
			else if (j == 0 || j == 87) cout << "||";
		}
	}
}


//  打印显示界面边框
void PrintSecondBorder() {
	int i, j = 1;

	color(14);             //黄色边框
	for (i = 5; i <= 30; i++)    //输出上下边框===
	{
		for (j = 20; j <= 88; j++)  //输出左右边框||
		{
			gotoxy(j, i);
			if (i == 5 || i == 30) cout << "=";
			else if (j == 20 || j == 87) cout << "||";
		}
	}
}