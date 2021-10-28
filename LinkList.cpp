#define _CRT_SECURE_NO_WARNINGS   1
#include"LinkList.h"

template <class T>
LinkList<T>::LinkList()
{
	head = new Node<T>;
	head->next = NULL;
}
template <class T>
LinkList<T>::LinkList(T a[], int n)
{
	Node<T>* rear, *s;
	head = new Node<T>;
	rear = head;
	for (int i = 0; i < n; i++)
	{
		s = new Node<T>;
		s->data = a[i];
		rear->next = s;
		rear = s;
	}
	rear->next = NULL;
}

template <class T>
LinkList<T>:: ~LinkList()
{
	Node<T>* p, *q;
	p = head;
	while (p)
	{
		q = p;
		p = p->next;
		delete q;
	}
	head = NULL;
}

