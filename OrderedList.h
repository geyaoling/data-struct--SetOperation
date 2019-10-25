#pragma once
// �����������ز���
#include "Node.h"


typedef struct {
	LinkType head, tail;  // ͷβ���
	int      size;   // ����
}OrderedList;  // ������������


//  ��ʼ����������L 
Status InitList(OrderedList& L);

// ������������L
void DestroyList(OrderedList& L);

// �ж��Ƿ��ǿ�����
bool ListEmpty(OrderedList L);

// ��������ĳ���
int ListLength(OrderedList L);

// ��ȡ��pos��Ԫ�ص�ָ��
LinkType GetElemPos(OrderedList L, int pos);

// �ж������б����Ƿ����Ԫ��e
bool LocateElem(OrderedList L, ElemType e, LinkType& q);

// ���Ѿ����ڵ���������L��ĩβ����ָ��s��ָ���
void Append(OrderedList& L, LinkType s);

// ���Ѿ����ڵ���������L��q��ָ��Ľ��֮�����ָ��s��ָ���
void InsertAfter(OrderedList &L, LinkType q, LinkType s);

// ��pָʾ�Ľ�����ζ�ÿ��������visit����
void ListTraverse(LinkType p, Status(*visit)(LinkType q));


