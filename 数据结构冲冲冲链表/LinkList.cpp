#define _CRT_SECURE_NO_WARNINGS   1

#include"LinkList.h"

template<class T>
LinkList<T>::LinkList()
{
	head = new Node<T>;
	head->next = NULL;
}
template<class T>
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
template<class T>
LinkList<T>::~LinkList()
{
	Node<T>*p = head;
	while (p)
	{
		Node<T>*q = p;
		p = p->next;
		delete q;
	}
	head = NULL;

}
template<class T>
int LinkList<T>::Length()
{
	int num = 0;
	Node<T>*p = head->next;
	while (p)
	{
		p = p->next;
		num++;
	}
	return num;
}
template<class T>
T LinkList<T>::Get(int pos)
{
	Node<T>*p = head->next;
	int j = 1;
	while (j < pos&&p)
	{
		p = p->next;
		j++;
	}
	if (!p&&j>pos)
	{
		cerr << "查找位置非法\n";
		exit(-1);
	}
	else
	{
		return p->data;
	}
}
template<class T>
int LinkList<T>::Locate(T x)
{
	Node<T>*p = head->next;
	int j = 1;
	while (p&&p->data != x)
	{
		p = p->next;
		j++;
	}
	if (p)
		return j;
	else
		return 0;
}
template<class T>
void LinkList<T>::Insert(int i, T item)
{
	Node<T>*p = head;
	int j = 0;
	while (p&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p)
	{
		cerr << "输入非法\n";
		exit(-1);
	}
	else
	{
		Node<T>*s = new Node<T>;
		s->data = item;
		s->next = p->next;
		p -> next = s;
	}
}
template<class T>
T LinkList<T>::Delete(int i)
{
	Node<T>*p = head;
	int j = 0;
	int x = 0;
	while (j < i - 1 && p)
	{
		p = p->next;
		j++;
	}
	if (!p&&!p->next)
	{
		cerr << "输入非法\n";
		exit(-1);
	}
	else
	{
		Node<T>*q = p->next;
		x = q->data;
		p->next = q->next;
		delete q;
		return x;
	}
}
template<class T>
void LinkList<T>::PrintList()
{
	Node<T>*p = head->next;
	while (p)
	{
		cout << p->data << "  ";
		p = p->next;
	}
	cout << endl;
}