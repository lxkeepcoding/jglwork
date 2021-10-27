#define _CRT_SECURE_NO_WARNINGS   1

#include"Stack.cpp"
#include<iostream>
using namespace std;
char Precede(char c1,char c2)
{
	if (c1 == '+')
	{
		if (c2 == '+'||c2=='-'||c2==')'||c2=='@')
			return '>';
		if (c2 == '*' || c2 == '/' || c2 == '(')
			return '<';
	}
	if (c1 == '-')
	{
		if (c2 == '+' || c2 == '-' || c2 == ')' || c2 == '@')
			return '>';
		if (c2 == '*' || c2 == '/' || c2 == '(')
			return '<';
	}
	if (c1 == '*')
	{
		if (c2 == '+' || c2 == '-' || c2 == '*' || c2 == '/' || c2 == ')' || c2 == '@')
			return '>';
		if (c2 == '(')
			return '<';
	}
	if (c1 == '/')
	{
		if (c2 == '+' || c2 == '-' || c2 == '*' || c2 == '/' || c2 == ')' || c2 == '@')
			return '>';
		if (c2 == '(')
			return '<';
	}
	if (c1 == '(')
	{
		if (c2 == '+' || c2 == '-' || c2 == '*' || c2 == '/' || c2 == '(')
			return '<';
		if (c2 == ')')
			return '=';
	}
	if (c1 == ')')
	{
		if (c2 == '+' || c2 == '-' || c2 == '*' || c2 == '/' || c2 == ')'||c2=='@')
			return '>';
	}
	if (c1 == '@')
	{
		if (c2 == '+' || c2 == '-' || c2 == '*' || c2 == '/' || c2 == '(')
			return '<';
		if (c2 == '@')
			return '=';
	}
}

double Operate(double o1,char o2,double o3)
{
	if (o2 == '+')
		return o1 + o3;
	if (o2 == '-')
		return o1 - o3;
	if (o2 == '*')
		return o1*o3;
	if (o2 == '/')
		return o1 / o3;
}

int main()
{
	char ch = getchar();
	char preop;
	double a;
	double b;
	Stack<char, 20>StackOPTR;
	Stack<double, 20>StackOPND;
	StackOPTR.PushStack('@');
	while (ch != '@' || StackOPTR.TopStack() != '@')
	{
		if (ch >= '0'&&ch <= '9')
		{
			StackOPND.PushStack(ch - '0');
			ch = getchar();
		}
		else
		{
			preop = StackOPTR.TopStack();
			switch (Precede(preop, ch))
			{
			case '<':
				StackOPTR.PushStack(ch);
				ch = getchar();
				break;
			case '=':
				StackOPTR.PopStack();
				ch = getchar();
				break;
			case '>':
				b=StackOPND.PopStack();
				a = StackOPND.PopStack();
				preop = StackOPTR.PopStack();
				StackOPND.PushStack(Operate(a,preop,b));
				break;
			}
		}
	}
	cout << StackOPND.TopStack() << endl;
}