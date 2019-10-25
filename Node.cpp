#include "Node.h"


// 创建头结点
Status MakeNode(LinkType& p, ElemType e) {
	// 分配由p指向的数据元素为e，后继为”空“的结点，并返回TRUE
	// 若分配失败，则返回FALSE
	p = new(NodeType);
	if (!p)
		return ERROR;
	p->data = e;
	p->next = NULL;
	return OK;
}

// 释放p所指向的结点
void DeleteNode(LinkType& p) {
	// new 创建，delete释放
	delete p;
}

// 复制生成与p数据域相同的结点并返回
LinkType Copy(LinkType p) {
	LinkType s = new(NodeType);
	if (!s) return NULL;  // 若分配失败，则返回NULL
	s->data = p->data;
	s->next = NULL;
	return s;
}

// 获取p结点的数据域
ElemType Elem(LinkType p) {
	// p不为NULL时执行
	if (p != NULL) return p->data;
	else {
		return '#';  // 若为NULL，则返回'#'
	}
}

// 得到p的下一个结点
LinkType SuccNode(LinkType p) {
	// p不为NULL时执行
	if (p != NULL) return p->next;
	else {
		return NULL;
	}
}