#ifndef SEQLIST_H
#define SEQLIST_H
#include<vector>
#include<iostream>
using namespace std;


template <class T, int MaxSize>  
class SeqList
{
	T data[MaxSize];        
	int length;              
public:
	SeqList();              
	SeqList(T a[], int n);  
	friend void SeqListMerge(SeqList<T, MaxSize> &S1, SeqList<T, MaxSize>&S2)
	{
		vector<int>s;
		int i = 0;
		int j = 0;
		while (i < S1.length&&j < S2.length)
		{
			if (S1.data[i] < S2.data[j])
			{
				s.push_back(S1.data[i]);
				i++;
			}
			else
			{
				s.push_back(S2.data[j]);
				j++;
			}
		}
		if (i < S1.length)
		{
			for (int k = i; k < S1.length; k++)
				s.push_back(S1.data[k]);
		}
		else
		{
			for (int k = j; k < S2.length; k++)
				s.push_back(S2.data[k]);
		}
		for (auto e : s)
		{
			cout << e << " ";
		}
		cout << endl;
	}
};

#endif