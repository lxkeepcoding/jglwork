#define _CRT_SECURE_NO_WARNINGS   1
#include"LinkList.cpp"
#include"SeqList.cpp"
#include<iostream>
using namespace std;

void menu()
{
	cout << "|--------------------------------------------|" << endl;
	cout << "|欢迎来到两个有序线性表的合并，请选择实现方式|" << endl;
	cout << "|******************  0.退出    **************|" << endl;
	cout << "|******************  1.顺序表  **************|" << endl;
	cout << "|******************  2.链表    **************|" << endl;
	cout << "|--------------------------------------------|" << endl;
}

int main()
{
	int *a;
	int n;
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int *b;
	int m;
	cin >> m;
	b = new int[m];
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	SeqList<int, 20>Seq1(a, n);
	SeqList<int, 20>Seq2(b, m);
	LinkList<int> Link1(a, n);
	LinkList<int>Link2(b, m);
	int input = 0;
	do
	{
		menu();
		cin >> input;
		switch (input)
		{
		case 1:
			SeqListMerge(Seq1,Seq2);
			break;
		case 2:
			LinkListMerge(Link1, Link2);
			break;
		case 0:
			cout << "感谢您的使用，程序退出" << endl;
			break;
		default:
			cout << "输入错误，请重新输入，或者，您可以选择0来终止程序" << endl;
		}
	} while (input);
	return 0;
}