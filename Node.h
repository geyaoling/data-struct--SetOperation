#pragma once
// ������صĲ���
#include "Constants.h"


typedef int Status;
typedef char ElemType;

typedef struct NodeType {
	ElemType         data;  // ������
	struct NodeType* next;  // ָ����
}NodeType, * LinkType;

// �������
Status MakeNode(LinkType& p, ElemType e);

// �ͷ�p��ָ��Ľ��
void DeleteNode(LinkType& p);

// ����������p��������ͬ�Ľ�㲢����
LinkType Copy(LinkType p);

// ��ȡp����������
ElemType Elem(LinkType p);

// �õ�p����һ�����
LinkType SuccNode(LinkType p);