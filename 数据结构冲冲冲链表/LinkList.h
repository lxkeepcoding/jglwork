#ifndef LINKLIST_H
#define LINKLIST_H

#include<iostream>
using namespace std;

template<class T>
struct Node
{
	T data;
	Node<T> *next;
};

template <class T>
class LinkList
{
public:
	LinkList();
	LinkList(T a[], int n);
	~LinkList();
	int Length();
	T Get(int pos);
	int Locate(T x);
	void Insert(int i, T item);
	T Delete(int i);
	void PrintList();
private:
	Node<T>*head;
};
#endif
