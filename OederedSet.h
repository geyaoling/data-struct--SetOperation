#pragma once
// 有序集合的相关操作
#include "Constants.h"
#include "OrderedList.h"
#include "Node.h"



typedef OrderedList OrderedSet;


// 显示集合的一个元素
Status Print(LinkType p);

// 创建集合
void CreateSet(OrderedSet& T, char* s,char &c);

// 销毁集合
void DestroySet(OrderedSet& T);

// 求两个集合的并集
void Union(OrderedSet& T, OrderedSet S1, OrderedSet S2);

// 求两个集合的交集
void Intersaction(OrderedSet& T, OrderedSet S1, OrderedSet S2);

// 求两个集合的差集
void Difference(OrderedSet& T, OrderedSet S1, OrderedSet S2);

// 求两个集合的补集
void Complementary(OrderedSet& T, OrderedSet S1,char elemType);

// 判断是否为子集关系
Status SubSet(OrderedSet &S1, OrderedSet &S2);


// 显示集合的一个元素
Status Print(LinkType p);

// 显示集合的全部元素
void PrintSet(OrderedSet T);