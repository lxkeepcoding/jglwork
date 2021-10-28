#ifndef LINKLIST_H
#define LINKLIST_H
#include<iostream>
#include<vector>
using namespace std;


template <class T>
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
	friend void LinkListMerge(LinkList<T> &L1, LinkList<T> &L2)
	{
		
		Node<T>*p1 = L1.head->next;
		Node<T>*p2 = L2.head->next;
		Node<T>*p3 = L1.head;
		vector<int>l;
		while ((p1 != NULL) && (p2 != NULL))
		{
			if ((p1->data)<(p2->data))
			{
				l.push_back(p1->data);
				p3->next = p1;	
				p1 = p1->next;
				p3 = p3->next;
			}
			else
			{
				l.push_back(p2->data);
				p3->next = p2;   
				p2 = p2->next;
				p3 = p3->next;
			}
		}
		if (p1 != NULL)
			p3->next = p1;
		if (p2 != NULL)
			p3-> next = p2;
		p3 = p3->next;
		while (p3 != NULL)
		{
			l.push_back(p3->data);
			p3=p3->next;
		}
		for (auto e : l)
		{
			cout << e << " ";
		}
		cout << endl;
	}
private:
	Node<T> *head;
};

#endif