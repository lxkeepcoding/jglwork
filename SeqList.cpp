#define _CRT_SECURE_NO_WARNINGS   1

#include"SeqList.h"
#include<iostream>
template <class T, int MaxSize>

SeqList<T, MaxSize >::SeqList()
{
	length = 0;
}

template <class T, int MaxSize>
SeqList<T, MaxSize>::SeqList(T a[], int n)
{
	if (n>MaxSize) 
	{ 
		cerr << "参数非法"; exit(1); 
	}
	for (int i = 0; i<n; i++)
		data[i] = a[i];
	length = n;
}

