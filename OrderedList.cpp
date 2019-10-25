#include "OrderedList.h"


// ��ʼ����������L
Status InitList(OrderedList& L) {
	//����һ����ͷ���������б�L ͷ��������Ԫ��Ϊ�ո��' ',����TRUE
	if (MakeNode(L.head, ' ')) {   
		L.tail = L.head;
		L.size = 0;
		return TRUE;
	}
	// ������ռ�ʧ�ܣ�����L.head ΪNULL,����FALSE
	else {
		L.head = NULL;
		return FALSE;
	}
}

// ������������L
void DestroyList(OrderedList& L) {
	LinkType p = L.head;
	while (p) {
		LinkType q = p;
		p = SuccNode(p); // p ָ����һ�����
	}
	L.head = L.tail = NULL;
}


// �ж��Ƿ��ǿ�����
bool ListEmpty(OrderedList L) {
	if (L.head == NULL) return TRUE;
	return FALSE;
}

// ��������ĳ���
int ListLength(OrderedList L) {
	return L.size;
}


// ��ȡ��pos��Ԫ�ص�ָ��
LinkType GetElemPos(OrderedList L, int pos) {
	LinkType p;
	int k; // k������¼����
	// ������ͷ��㲻Ϊ����1<= pos <= ListLength(L)
	if (!L.head || pos < 1 || pos > ListLength(L)) return NULL;
	else if (pos == L.size) return L.tail; // ��ȡ�������һ��Ԫ��,����β���
	else {
		p = L.head->next; k = 1;
		while (p && k < pos) {
			p = SuccNode(p);
			k++;
		}

		return p;
	}
}

// =============================================
// �ж������б����Ƿ����Ԫ��e
bool LocateElem(OrderedList L, ElemType e, LinkType& q) {
	NodeType* pre;
	if (L.head) {
		pre = L.head;
		q = pre->next;  
		// pre ָ��pre��ǰ����qָ��L�е�һ��ֵΪe�Ľ�㣬��ΪTRUE
		// ����qָʾ��һ������e��Ԫ�ص�ǰ��λ�ã�������FALASE
		while (q && q->data < e) {
			pre = q;
			q = SuccNode(q);
		}
		if (q && q->data == e) {
			return TRUE;
		}
		else
		{
			q = pre;
			return FALSE;
		}
	}
	else {
		return FALSE;
	}
}

//======================================================
// ���Ѿ����ڵ���������L��q��ָ��Ľ��֮�����ָ��s��ָ���
void InsertAfter(OrderedList &L, LinkType q, LinkType s) {
	// ǰ��ͷ��㡢q��s������
	if (L.head && q && s) {
		s->next = q->next;
		q->next = s;
		if (L.tail == q)
			L.tail = s;
		L.size++;
	}
}


// ���Ѿ����ڵ���������L��ĩβ����ָ��s��ָ���
void Append(OrderedList& L, LinkType s) {
	if (L.head && s)
	{
		if (L.tail != L.head)
			L.tail->next = s;
		else
			L.head->next = s;
		L.tail = s;
		L.size++; // �������+1
	}
}



// ��pָʾ�Ľ�����ζ�ÿ��������visit����
void ListTraverse(LinkType p, Status(*visit)(LinkType q)) {
	while (p)
	{
		visit(p);
		p = SuccNode(p);
	}
}

