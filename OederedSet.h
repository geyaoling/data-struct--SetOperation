#pragma once
// ���򼯺ϵ���ز���
#include "Constants.h"
#include "OrderedList.h"
#include "Node.h"



typedef OrderedList OrderedSet;


// ��ʾ���ϵ�һ��Ԫ��
Status Print(LinkType p);

// ��������
void CreateSet(OrderedSet& T, char* s,char &c);

// ���ټ���
void DestroySet(OrderedSet& T);

// ���������ϵĲ���
void Union(OrderedSet& T, OrderedSet S1, OrderedSet S2);

// ���������ϵĽ���
void Intersaction(OrderedSet& T, OrderedSet S1, OrderedSet S2);

// ���������ϵĲ
void Difference(OrderedSet& T, OrderedSet S1, OrderedSet S2);

// ���������ϵĲ���
void Complementary(OrderedSet& T, OrderedSet S1,char elemType);

// �ж��Ƿ�Ϊ�Ӽ���ϵ
Status SubSet(OrderedSet &S1, OrderedSet &S2);


// ��ʾ���ϵ�һ��Ԫ��
Status Print(LinkType p);

// ��ʾ���ϵ�ȫ��Ԫ��
void PrintSet(OrderedSet T);