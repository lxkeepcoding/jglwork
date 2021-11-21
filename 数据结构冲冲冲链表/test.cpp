#define _CRT_SECURE_NO_WARNINGS   1

#include"LinkList.cpp"

#include<iostream>
using namespace std;

void menu()
{
	cout << "|------------------------------------|" << endl;
	cout << "|----------- 欢迎来到顺序表 ---------|" << endl;
	cout << "|---------------1.插入---------------|" << endl;
	cout << "|---------------2.删除---------------|" << endl;
	cout << "|---------------3.求长---------------|" << endl;
	cout << "|---------------4.取值---------------|" << endl;
	cout << "|---------------5.定位---------------|" << endl;
	cout << "|---------------6.打印---------------|" << endl;
	cout << "|---------------0.退出---------------|" << endl;
	cout << "|------------------------------------|" << endl;
}
int main()
{
	int *a;
	int n;
	cin >> n;
	a=new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "现在开始我们的程序之旅" << endl;
	LinkList<int>L(a, n);
	int input = 0;
	do
	{
		menu();
		cout << "输入您要进行的操作的编号" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "请输入您要插入的位置和数值" << endl;
			int pos;
			int value;
			cin >> pos;
			cin >> value;
			L.Insert(pos, value);
			break;
		case 2:
			cout << "请输入您要删除的位置" << endl;
			int pos1;
			cin >> pos1;
			cout << "您删除的元素的值为：";
			cout << L.Delete(pos1) << endl;
			break;
		case 3:
			cout << "您的顺序表当前的长度为：" << L.Length() << endl;
			break;
		case 4:
			cout << "请输入您要查找的位置" << endl;
			int pos2;
			cin >> pos2;
			cout << "您查找的元素的值为：";
			cout << L.Get(pos2) << endl;;
			break;
		case 5:
			cout << "请输入您要查找的元素" << endl;
			int item;
			cin >> item;
			cout << "您查找的元素的位置为：";
			cout << L.Locate(item) << endl;;
			break;
		case 6:
			cout << "当前顺序表如下：" << endl;
			L.PrintList();
			break;
		case 0:
			cout << "程序退出，感谢使用" << endl;
			exit(-1);
			break;
		default:
			cout << "您的输入有误，请重新选择" << endl;
		}
	} while (input);
}