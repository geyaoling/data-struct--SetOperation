#include "OederedSet.h"
#include <string.h>
#include "Constants.h"
#include <ctype.h>  // �жϴ�Сд����ʹ�õ�ͷ�ļ�
using namespace std;



//��������ȫ��
char LOWER_CASE[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char UPPER_CASE[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char NUMBER[10] = {'0','1','2','3','4','5','6','7','8','9'};


/*
// �����б��� Сд��ĸ ��д��ĸ  ����
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




// ����һ������
void CreateSet(OrderedSet& T, char* s,char &c) {
	LinkType p, q;
	if (InitList(T)) {
		//�����û����� ���˵����Ϸ�������
		switch (c) {
		case '1'://Сд��ĸ���Ҳ���������
			for (int i = 0; i <= strlen(s); i++) {
				if (islower(s[i]) && !LocateElem(T, s[i], p)) {
					if (MakeNode(q, s[i])) {
						//����ĸ˳����� ����p��ֵΪ��s[i]��ĵ�һ��Ԫ�ص�ǰ��
						//����Ϊ�գ��������ڣ� Ϊ�������²��뺯����ִ��
						//���뵽������
						InsertAfter(T, p, q);
					}
				}
			}
			break;
		case '2'://��д��ĸ�Ҳ���������
			for (int i = 0; i <= strlen(s); i++) {
				if (isupper(s[i]) && !LocateElem(T, s[i], p)) {
					if (MakeNode(q, s[i])) {
						//����ĸ˳����� ����p��ֵΪ��s[i]��ĵ�һ��Ԫ�ص�ǰ��
						//����Ϊ�գ��������ڣ� Ϊ�������²��뺯����ִ��
						//���뵽������
						InsertAfter(T, p, q);
					}
				}
			}
			break;
		case '3'://�����֣��Ҳ���������
			for (int i = 0; i <= strlen(s); i++) {
				if (s[i] >= '0' && s[i] <= '9' && !LocateElem(T, s[i], p)) {
					if (MakeNode(q, s[i])) {
						//����ĸ˳����� ����p��ֵΪ��s[i]��ĵ�һ��Ԫ�ص�ǰ��
						//����Ϊ�գ��������ڣ� Ϊ�������²��뺯����ִ��
						//���뵽������
						InsertAfter(T, p, q);
					}
				}
			}
			break;
		}
	}

}




// ���ټ���
void DestroySet(OrderedSet& T) {
	// ���ټ���T�Ľṹ
	DestroyList(T);
}

// ���������ϵĲ���
void Union(OrderedSet& T, OrderedSet S1, OrderedSet S2) {
	LinkType p1, p2;
	if (InitList(T)) {
		// �ֱ��ȡp1,p2�ĵ�һ��Ԫ��λ�õ�ָ��
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

// ���������ϵĽ���
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
				// Ԫ����ͬ����ӵ�T�� 
				Append(T, Copy(p1));
				p1 = SuccNode(p1);
				p2 = SuccNode(p2);
			}

		}
	}
}


// ���������ϵĲ
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


// �󼯺ϵĲ���
void Complementary(OrderedSet& T, OrderedSet S1, char elemType) {

	/*
	// ��������
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
	

	
	LinkType p,q;          //����p1ȡS1�ڵ�Ԫ�� q����Ϊ�ڵ���뵽T��
	char *temp;             //������ʱ���飬��������ȫ��
	char c1, c2;           //ȡ����Ԫ�ص�ֵ�������Ƚϴ�С
	int k = 0;    //��¼�±��ֵ
	if (elemType == '1') {            //ͨ���Ƚϣ��ж�ȫ����c����������
		temp = LOWER_CASE;        //ȫ����Сд��ĸ
	}
	else if (elemType == '2') {
		temp = UPPER_CASE;    //ȫ���Ǵ�д��ĸ
	}
	else{
		temp = NUMBER;    //ȫ��������
	}


	p = GetElemPos(S1, 1);
	if (InitList(T)) {          //��ʼ����������
		while (p) { 
			//ͨ����С�Ƚϣ��������Ԫ��
			c1 = Elem(p);    //��ȡԪ��
			c2 = temp[k];
			if (c1 > c2&& MakeNode(q, c2)) {//����Ԫ�����������еģ����Ա���ʱֻ�ñȽϴ�С�ķ������Ϳɽ�����Ԫ�ض��Ƚ�һ��
				k++;                 //ȫ����ȡ��Ԫ��С�������ʱ����Ԫ���������û�У����뵽����
				Append(T, q);         //��Ԫ���±��һ
			}

			//==================��һ���ֿ��Ժ��ԣ���Ϊc1>= c2 ��������===================================================
			else if (c1 < c2) {       //����ʱ��������������һλ
				p = SuccNode(p);
			}
			else {                   //���ʱ���������һλ
				k++;
				p = SuccNode(p);
			}
		}

		for (int i = k; i < strlen(temp); i++) {
			c2 = temp[i];                //�����������ȫ������ֵ��ȫ�Ƶ�������
			if (MakeNode(q, c2)) {           //ͨ��������
				Append(T, q);
			}
		}

	}
}

// �ж��Ƿ�Ϊ�Ӽ���ϵ, ������򷵻�TRUE,���Ƿ���FALSE
Status SubSet(OrderedSet &S1,OrderedSet &S2) {
	LinkType p,q;		//������������ָ��p
	p = S2.head->next;	//pָ���Ӽ�LS����Ԫ���
	while (p)
	{
		if ( !LocateElem(S1, p->data,q))
		{
			return FALSE;//����L�в�����Ԫ��e������FALSE
		}
		p = SuccNode(p);//����L��D����Ԫ��e��������һԪ��
	}
	return TRUE;		//�Ӽ�LS������Ԫ�ؾ�������L�У�����TRUE
}




// ��ʾ���ϵ�һ��Ԫ��
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

// ��ʾ���ϵ�ȫ��Ԫ��
void PrintSet(OrderedSet T) {
	LinkType p = GetElemPos(T, 1);
	cout << "[";
	if (p)
	{
		ListTraverse(p, Print);
	}
	cout << "] " << endl;
}
