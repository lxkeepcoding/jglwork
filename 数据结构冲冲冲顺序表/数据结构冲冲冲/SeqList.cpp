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
		cerr << "���������Ѿ�������Χ��ϵͳ�޷���������" << endl;
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
		cerr << "��Ҫ���ҵ�λ�ò����ڣ�ϵͳ�޷�����Ϊ������" << endl;
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
		cerr << "��Ǹ����ǰ�Ѿ��ﵽϵͳ���Ĵ��棬�޷�Ϊ������" << endl;
		exit(-1);
	}
}
template<class T, int MAXSIZE>
T SeqList<T, MAXSIZE>::Delete(int i)
{
	if (length == 0)
	{
		cerr << "��ǰ�޿�ɾ��Ԫ��" << endl;
		exit(-1);
	}
	if (i<1 || i>length)
	{
		cerr << "��λ�÷Ƿ�" << endl;
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