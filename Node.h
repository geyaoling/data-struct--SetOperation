#pragma once
// 与结点相关的操作
#include "Constants.h"


typedef int Status;
typedef char ElemType;

typedef struct NodeType {
	ElemType         data;  // 数据域
	struct NodeType* next;  // 指针域
}NodeType, * LinkType;

// 创建结点
Status MakeNode(LinkType& p, ElemType e);

// 释放p所指向的结点
void DeleteNode(LinkType& p);

// 复制生成与p数据域相同的结点并返回
LinkType Copy(LinkType p);

// 获取p结点的数据域
ElemType Elem(LinkType p);

// 得到p的下一个结点
LinkType SuccNode(LinkType p);