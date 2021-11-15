#define _CRT_SECURE_NO_WARNINGS   1

#include"SeqList.cpp"
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
	cout << "请输入您要构造的顺序表的长度" << endl;
	cin >> n;
	a = new int[n];
	cout << "请输入该顺序表中的每一个元素" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	SeqList<int, 20>seq(a, n);
	cout << "现在开始我们的程序之旅" << endl;
	int input=0;
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
			seq.Insert(pos,value);
			break;
		case 2:
			cout << "请输入您要删除的位置" << endl;
			int pos1;
			cin >> pos1;
			cout << "您删除的元素的值为：";
			cout << seq.Delete(pos1) << endl;
			break;
		case 3:
			cout << "您的顺序表当前的长度为：" << seq.ListLength() << endl;
			break;
		case 4:
			cout << "请输入您要查找的位置" << endl;
			int pos2;
			cin >> pos2;
			cout << "您查找的元素的值为：";
			cout << seq.Get(pos2) << endl;;
			break;
		case 5:
			cout << "请输入您要查找的元素" << endl;
			int item;
			cin >> item;
			cout << "您查找的元素的位置为：";
			cout << seq.Locate(item) << endl;;
			break;
		case 6:
			cout << "当前顺序表如下：" << endl;
			seq.SeqPrint();
			break;
		case 0:
			cout << "程序退出，感谢使用" << endl;
			exit(-1);
			break;
		default :
			cout << "您的输入有误，请重新选择" << endl;
		}
	} while (input);
	return 0;
}