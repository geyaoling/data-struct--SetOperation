#include "Node.h"


// ����ͷ���
Status MakeNode(LinkType& p, ElemType e) {
	// ������pָ�������Ԫ��Ϊe�����Ϊ���ա��Ľ�㣬������TRUE
	// ������ʧ�ܣ��򷵻�FALSE
	p = new(NodeType);
	if (!p)
		return ERROR;
	p->data = e;
	p->next = NULL;
	return OK;
}

// �ͷ�p��ָ��Ľ��
void DeleteNode(LinkType& p) {
	// new ������delete�ͷ�
	delete p;
}

// ����������p��������ͬ�Ľ�㲢����
LinkType Copy(LinkType p) {
	LinkType s = new(NodeType);
	if (!s) return NULL;  // ������ʧ�ܣ��򷵻�NULL
	s->data = p->data;
	s->next = NULL;
	return s;
}

// ��ȡp����������
ElemType Elem(LinkType p) {
	// p��ΪNULLʱִ��
	if (p != NULL) return p->data;
	else {
		return '#';  // ��ΪNULL���򷵻�'#'
	}
}

// �õ�p����һ�����
LinkType SuccNode(LinkType p) {
	// p��ΪNULLʱִ��
	if (p != NULL) return p->next;
	else {
		return NULL;
	}
}