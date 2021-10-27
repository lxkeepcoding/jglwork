#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;
template <class T, int MaxSize>
class Stack
{
	T data[MaxSize];
	int top;
public:
	Stack();
	void PushStack(T x);
	T PopStack();
	T TopStack();
};

#endif