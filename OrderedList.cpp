#include "OrderedList.h"


// 初始化有序链表L
Status InitList(OrderedList& L) {
	//构造一个带头结点的有序列表L 头结点的虚设元素为空格符' ',返回TRUE
	if (MakeNode(L.head, ' ')) {   
		L.tail = L.head;
		L.size = 0;
		return TRUE;
	}
	// 若分配空间失败，则令L.head 为NULL,返回FALSE
	else {
		L.head = NULL;
		return FALSE;
	}
}

// 销毁有序链表L
void DestroyList(OrderedList& L) {
	LinkType p = L.head;
	while (p) {
		LinkType q = p;
		p = SuccNode(p); // p 指向下一个结点
	}
	L.head = L.tail = NULL;
}


// 判断是否是空链表
bool ListEmpty(OrderedList L) {
	if (L.head == NULL) return TRUE;
	return FALSE;
}

// 返回链表的长度
int ListLength(OrderedList L) {
	return L.size;
}


// 获取第pos个元素的指针
LinkType GetElemPos(OrderedList L, int pos) {
	LinkType p;
	int k; // k用来记录次数
	// 需满足头结点不为空且1<= pos <= ListLength(L)
	if (!L.head || pos < 1 || pos > ListLength(L)) return NULL;
	else if (pos == L.size) return L.tail; // 获取的是最后一个元素,返回尾结点
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
// 判断有序列表中是否存在元素e
bool LocateElem(OrderedList L, ElemType e, LinkType& q) {
	NodeType* pre;
	if (L.head) {
		pre = L.head;
		q = pre->next;  
		// pre 指向pre的前驱，q指向L中第一个值为e的结点，并为TRUE
		// 否则q指示第一个大于e的元素的前驱位置，并返回FALASE
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
// 在已经存在的有序链表L中q所指向的结点之后插入指针s所指结点
void InsertAfter(OrderedList &L, LinkType q, LinkType s) {
	// 前提头结点、q、s都存在
	if (L.head && q && s) {
		s->next = q->next;
		q->next = s;
		if (L.tail == q)
			L.tail = s;
		L.size++;
	}
}


// 在已经存在的有序链表L的末尾插入指针s所指结点
void Append(OrderedList& L, LinkType s) {
	if (L.head && s)
	{
		if (L.tail != L.head)
			L.tail->next = s;
		else
			L.head->next = s;
		L.tail = s;
		L.size++; // 有序表长度+1
	}
}



// 从p指示的结点依次对每个结点调用visit函数
void ListTraverse(LinkType p, Status(*visit)(LinkType q)) {
	while (p)
	{
		visit(p);
		p = SuccNode(p);
	}
}

