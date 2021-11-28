#define _CRT_SECURE_NO_WARNINGS   1


#include"BiTree.cpp"
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void menu()
{
	cout << endl;
	cout << "|-------------------------------------|" << endl;
	cout << "|----------- 欢迎来到顺序表 ----------|" << endl;
	cout << "|---------------1. 先序输出-----------|" << endl;
	cout << "|---------------2. 中序输出-----------|" << endl;
	cout << "|---------------3. 后序输出-----------|" << endl;
	cout << "|---------------4. 层序输出-----------|" << endl;
	cout << "|---------------5. 找结点数-----------|" << endl;
	cout << "|---------------6. 求树高度-----------|" << endl;
	cout << "|---------------7. 寻找结点-----------|" << endl;
	cout << "|---------------8. 寻找双亲-----------|" << endl;
	cout << "|---------------0. 退出---------------|" << endl;
	cout << "|-------------------------------------|" << endl;
}
int main()
{
	vector<char>GetTree;
	char num;
	int input = 0;
	cout << "现在开始我们的程序之旅" << endl;
	cout << endl;
	cout << "请输入先序序列，我将以此来构造一棵树，记住，请用星号来代表空指针，并且，不要忘记输入空格" << endl;
	while (1)
	{
		cin >> num;
		GetTree.push_back(num);
		if (cin.get() == '\n')
			break;
	}
	BiTree<char>tree(GetTree);
	cout << "构造完成，您可以选择接下来的操作" << endl;
	do
	{
		menu();
		cout << endl;
		cout << "请选择您要进行的操作" << endl;
		cout << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "先序遍历的结果如下:";
			cout << endl;
			tree.PreOrder();
			break;
		case 2:
			cout << "中序遍历的结果如下:";
			cout << endl;
			tree.InOrder();
			break;
		case 3:
			cout << "后序遍历的结果如下:";
			cout << endl;
			tree.PostOrder();
			break;
		case 4:
			cout << "层序遍历的结果如下:";
			cout << endl;
			tree.LevelOrder();
			break;
		case 5:
			cout << "该树的结点数为: ";
			cout << tree.Count() << endl;
			break;
		case 6:
			cout << "该树的高度为: ";
			cout << tree.Height() << endl;
			break;
		case 7:
			char ch;
			cout << "请输入您要查找的值" << endl;
			cin >> ch;
			if (tree.Search(ch))
			{
				cout << "查找到了，该结点存在于该树中" << endl;
			}
			else
			{
				cout << "很遗憾，该结点并不存在于该树中" << endl;
			}
			break;
		case 8:
			char ch1;
			cout << "请输入您要查找其双亲的值" << endl;
			cin >> ch1;
			if (tree.Search(ch1))
			{
				cout << "它的双亲的值为：";
				cout<<tree.SearchParent(tree.Search(ch1))->data<<endl;
			}
			else
			{
				cout << "很遗憾，该结点并不存在于该树中，所以我们不能为您查找到它的双亲" << endl;
			}
			break;
		case 0:
			cout << "程序退出,感谢您的使用" << endl;
			exit(-1);
			break;
		default:
			cout << "抱歉，您的输入有误，我无法理解当前您想要进行的操作，请重新输入您的选择" << endl;
		}

	} while (input);
	return 0;
}