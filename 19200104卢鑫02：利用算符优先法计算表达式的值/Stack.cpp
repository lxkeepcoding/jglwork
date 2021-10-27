#define CRT_SECURE_NO_WARNINGS   1
#include"Stack.h"
#include<iostream>
using namespace std;

template<class T,int MaxSize>
Stack<T, MaxSize>::Stack()
{
	top = -1;
}

template<class T, int MaxSize>
void Stack<T, MaxSize>::PushStack(T x)
{
	if (top == MaxSize - 1)
	{
		cerr << "ÉÏÒç" << endl;
		exit(-1);
	}
	else
	{
		top++;
		data[top] = x;
	}
}

template<class T, int MaxSize>
T Stack<T, MaxSize>::PopStack()
{
	if (top ==  - 1)
	{
		cerr << "ÏÂÒç" << endl;
		exit(-1);
	}
	else
	{
		T x=data[top];
		top--;
		return x;
	}
}

template<class T, int MaxSize>
T Stack<T, MaxSize>::TopStack()
{
	if (top == MaxSize - 1)
	{
		cerr << "ÉÏÒç" << endl;
		exit(-1);
	}
	else
	{
		return data[top];
	}
}

