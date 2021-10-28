#define _CRT_SECURE_NO_WARNINGS   1
#include"LinkList.cpp"
#include"SeqList.cpp"
#include<iostream>
using namespace std;

void menu()
{
	cout << "|--------------------------------------------|" << endl;
	cout << "|��ӭ���������������Ա�ĺϲ�����ѡ��ʵ�ַ�ʽ|" << endl;
	cout << "|******************  0.�˳�    **************|" << endl;
	cout << "|******************  1.˳���  **************|" << endl;
	cout << "|******************  2.����    **************|" << endl;
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
			cout << "��л����ʹ�ã������˳�" << endl;
			break;
		default:
			cout << "����������������룬���ߣ�������ѡ��0����ֹ����" << endl;
		}
	} while (input);
	return 0;
}