#pragma once
// 有序链表的相关操作
#include "Node.h"


typedef struct {
	LinkType head, tail;  // 头尾结点
	int      size;   // 长度
}OrderedList;  // 有序链表类型


//  初始化有序链表L 
Status InitList(OrderedList& L);

// 销毁有序链表L
void DestroyList(OrderedList& L);

// 判断是否是空链表
bool ListEmpty(OrderedList L);

// 返回链表的长度
int ListLength(OrderedList L);

// 获取第pos个元素的指针
LinkType GetElemPos(OrderedList L, int pos);

// 判断有序列表中是否存在元素e
bool LocateElem(OrderedList L, ElemType e, LinkType& q);

// 在已经存在的有序链表L的末尾插入指针s所指结点
void Append(OrderedList& L, LinkType s);

// 在已经存在的有序链表L中q所指向的结点之后插入指针s所指结点
void InsertAfter(OrderedList &L, LinkType q, LinkType s);

// 从p指示的结点依次对每个结点调用visit函数
void ListTraverse(LinkType p, Status(*visit)(LinkType q));


