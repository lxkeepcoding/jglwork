#ifndef SEQLIST_H
#define SEQLIST_H

#include<iostream>
using namespace std;

template<class T,int MAXSIZE>
class SeqList
{
	T data[MAXSIZE];
	int length;
public:
	SeqList();
	SeqList(T a[],int n);
	~SeqList();
	int ListLength();
	T Get(int pos);
	int Locate(T item);
	void SeqPrint();
	void Insert(int i, T item);
	T Delete(int i);
};

#endif