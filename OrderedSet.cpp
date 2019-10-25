#include "OederedSet.h"
#include <string.h>
#include "Constants.h"
#include <ctype.h>  // 判断大小写函数使用的头文件
using namespace std;



//创建三个全集
char LOWER_CASE[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char UPPER_CASE[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char NUMBER[10] = {'0','1','2','3','4','5','6','7','8','9'};


/*
// 输入判别函数 小写字母 大写字母  数字
bool IsLowerCase(char c) {
	if (c >= 'a' && c <= 'z') return TRUE;
	else {
		return FALSE;
	}
}

bool IsUpperCase(char c) {
	if (c >= 'A' && c <= 'Z') return TRUE;
	else {
		return FALSE;
	}
}

bool IsNumber(char c) {
	if (c >= '0' && c <= '9') return TRUE;
	else {
		return FALSE;
	}
}
*/




// 创建一个集合
void CreateSet(OrderedSet& T, char* s,char &c) {
	LinkType p, q;
	if (InitList(T)) {
		//遍历用户输入 过滤掉不合法的输入
		switch (c) {
		case '1'://小写字母并且不在链表中
			for (int i = 0; i <= strlen(s); i++) {
				if (islower(s[i]) && !LocateElem(T, s[i], p)) {
					if (MakeNode(q, s[i])) {
						//按字母顺序插入 所得p的值为比s[i]大的第一个元素的前驱
						//或者为空（链表不存在） 为空则以下插入函数不执行
						//插入到链表中
						InsertAfter(T, p, q);
					}
				}
			}
			break;
		case '2'://大写字母且不再链表中
			for (int i = 0; i <= strlen(s); i++) {
				if (isupper(s[i]) && !LocateElem(T, s[i], p)) {
					if (MakeNode(q, s[i])) {
						//按字母顺序插入 所得p的值为比s[i]大的第一个元素的前驱
						//或者为空（链表不存在） 为空则以下插入函数不执行
						//插入到链表中
						InsertAfter(T, p, q);
					}
				}
			}
			break;
		case '3'://是数字，且不在链表中
			for (int i = 0; i <= strlen(s); i++) {
				if (s[i] >= '0' && s[i] <= '9' && !LocateElem(T, s[i], p)) {
					if (MakeNode(q, s[i])) {
						//按字母顺序插入 所得p的值为比s[i]大的第一个元素的前驱
						//或者为空（链表不存在） 为空则以下插入函数不执行
						//插入到链表中
						InsertAfter(T, p, q);
					}
				}
			}
			break;
		}
	}

}




// 销毁集合
void DestroySet(OrderedSet& T) {
	// 销毁集合T的结构
	DestroyList(T);
}

// 求两个集合的并集
void Union(OrderedSet& T, OrderedSet S1, OrderedSet S2) {
	LinkType p1, p2;
	if (InitList(T)) {
		// 分别获取p1,p2的第一个元素位置的指针
		p1 = GetElemPos(S1, 1);
		p2 = GetElemPos(S2, 1);
		while (p1 && p2) {
			ElemType c1 = Elem(p1);
			ElemType c2 = Elem(p2);
			if (c1 <= c2) {
				Append(T, Copy(p1));
				if (c1 == c2)  p2 = SuccNode(p2);
				p1 = SuccNode(p1);
			}
			else {
				Append(T, Copy(p2));
				p2 = SuccNode(p2);
			}			
		}

		// 
		while (p1) {
			Append(T, Copy(p1));
			p1 = SuccNode(p1);
		}
		while (p2) {
			Append(T, Copy(p2));
			p2 = SuccNode(p2);
		}
	}
}

// 求两个集合的交集
void Intersaction(OrderedSet& T, OrderedSet S1, OrderedSet S2) {
	LinkType p1, p2;
	if (!InitList(T)) T.head = NULL;
	else {
		p1 = GetElemPos(S1, 1);
		p2 = GetElemPos(S2, 1);
		while (p1 && p2) {
			ElemType c1 = Elem(p1);
			ElemType c2 = Elem(p2);
			if (c1 < c2) {
				p1 = SuccNode(p1);
			}
			else if (c1 > c2) {
				p2 = SuccNode(p2);
			}
			else {
				// 元素相同，添加到T中 
				Append(T, Copy(p1));
				p1 = SuccNode(p1);
				p2 = SuccNode(p2);
			}

		}
	}
}


// 求两个集合的差集
void Difference(OrderedSet& T, OrderedSet S1, OrderedSet S2) {
	LinkType p1, p2;
	if (!InitList(T))
		T.head = NULL;
	else {
		p1 = GetElemPos(S1, 1);
		p2 = GetElemPos(S2, 1);
		while (p1 && p2) {
			ElemType c1 = Elem(p1);
			ElemType c2 = Elem(p2);
			if (c1 < c2) {
				Append(T, Copy(p1));
				p1 = SuccNode(p1);
			}
			else if (c1 > c2) {
				p2 = SuccNode(p2);
			}
			else { // c1 == c2
				p1 = SuccNode(p1);
				p2 = SuccNode(p2);
			}
		}

		while (p1) {
			Append(T, Copy(p1));
			p1 = SuccNode(p1);
		}
	}
}


// 求集合的补集
void Complementary(OrderedSet& T, OrderedSet S1, char elemType) {

	/*
	// 测试数据
	printf("********\n");
	printf(NUMBER);
	char* s = NUMBER;
	for (; *s != NULL;s++) {
		printf("%c", *s);
	}

	printf("********\n");
	printf(LOWER_CASE);
	printf("********\n");
	printf(UPPER_CASE);
	*/
	

	
	LinkType p,q;          //创建p1取S1内的元素 q是作为节点加入到T中
	char *temp;             //创建临时数组，用来保存全集
	char c1, c2;           //取出的元素的值，用来比较大小
	int k = 0;    //记录下标的值
	if (elemType == '1') {            //通过比较，判断全集，c是数据类型
		temp = LOWER_CASE;        //全集是小写字母
	}
	else if (elemType == '2') {
		temp = UPPER_CASE;    //全集是大写字母
	}
	else{
		temp = NUMBER;    //全集是数字
	}


	p = GetElemPos(S1, 1);
	if (InitList(T)) {          //初始化补集集合
		while (p) { 
			//通过大小比较，进行添加元素
			c1 = Elem(p);    //提取元素
			c2 = temp[k];
			if (c1 > c2&& MakeNode(q, c2)) {//由于元素是有序排列的，所以遍历时只用比较大小的方法，就可将所有元素都比较一遍
				k++;                 //全集内取的元素小于有序表时，该元素有序表中没有，加入到补集
				Append(T, q);         //且元素下标加一
			}

			//==================这一部分可以忽略，因为c1>= c2 总是满足===================================================
			else if (c1 < c2) {       //大于时，有序表结点向后移一位
				p = SuccNode(p);
			}
			else {                   //相等时，都向后移一位
				k++;
				p = SuccNode(p);
			}
		}

		for (int i = k; i < strlen(temp); i++) {
			c2 = temp[i];                //遍历完有序表，全集还有值，全移到补集中
			if (MakeNode(q, c2)) {           //通过结点添加
				Append(T, q);
			}
		}

	}
}

// 判断是否为子集关系, 如果是则返回TRUE,不是返回FALSE
Status SubSet(OrderedSet &S1,OrderedSet &S2) {
	LinkType p,q;		//定义遍历链表的指针p
	p = S2.head->next;	//p指向子集LS的首元结点
	while (p)
	{
		if ( !LocateElem(S1, p->data,q))
		{
			return FALSE;//集合L中不存在元素e，返回FALSE
		}
		p = SuccNode(p);//集合L中D存在元素e，查找下一元素
	}
	return TRUE;		//子集LS中所有元素均存在于L中，返回TRUE
}




// 显示集合的一个元素
Status Print(LinkType p) {
	if (p) {
		cout << p->data ;
		if (p->next != NULL) {
			cout << ",";
		}
		return OK;
	}
	else {
		return ERROR;
	}
}

// 显示集合的全部元素
void PrintSet(OrderedSet T) {
	LinkType p = GetElemPos(T, 1);
	cout << "[";
	if (p)
	{
		ListTraverse(p, Print);
	}
	cout << "] " << endl;
}
