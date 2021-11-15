#define _CRT_SECURE_NO_WARNINGS   1

#include"SeqList.h"
template<class T, int MAXSIZE>
SeqList<T,MAXSIZE>::SeqList()
{
	length = 0;
}
template<class T, int MAXSIZE>
SeqList<T, MAXSIZE>::SeqList(T a[], int n)
{
	if (n < MAXSIZE)
	{
		length = n;
		for (int i = 0; i < n; i++)
		{
			data[i] = a[i];
		}
	}
	else
	{
		cerr << "您的数据已经超过范围，系统无法继续工作" << endl;
		exit(-1);
		
	}
}
template<class T, int MAXSIZE>
SeqList<T, MAXSIZE>::~SeqList()
{

}
template<class T, int MAXSIZE>
int SeqList<T, MAXSIZE>::ListLength()
{
	return length;
}
template<class T, int MAXSIZE>
T SeqList<T, MAXSIZE>::Get(int pos)
{
	if (pos > length || pos < 0)
	{
		cerr << "您要查找的位置不存在，系统无法继续为您服务" << endl;
		exit(-1);
	}
	else
	{
		return data[pos - 1];
	}
}
template<class T, int MAXSIZE>
int SeqList<T, MAXSIZE>::Locate(T item)
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == item)
			return i + 1;
	}
	return -1;
}
template<class T, int MAXSIZE>
void SeqList<T, MAXSIZE>::SeqPrint()
{
	for (int i = 0; i < length; i++)
	{
		cout << data[i] << "  ";
	}
	cout << endl;
}
template<class T, int MAXSIZE>
void SeqList<T, MAXSIZE>::Insert(int i, T item)
{
	if (length < MAXSIZE)
	{
		for (int j = length - 1; j>=i - 1; j--)
		{
			data[j + 1] = data[j];
		}
		data[i - 1] = item;
		length++;
	}
	else
	{
		cerr << "抱歉，当前已经达到系统最大的储存，无法为您插入" << endl;
		exit(-1);
	}
}
template<class T, int MAXSIZE>
T SeqList<T, MAXSIZE>::Delete(int i)
{
	if (length == 0)
	{
		cerr << "当前无可删除元素" << endl;
		exit(-1);
	}
	if (i<1 || i>length)
	{
		cerr << "该位置非法" << endl;
		exit(-1);
	}
	T x = data[i - 1];
	for (int j = i; j < length; j++)
	{
		data[j - 1] = data[j];
	}
	length--;
	return x;
}