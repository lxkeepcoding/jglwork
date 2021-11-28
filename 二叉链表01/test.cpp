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
	cout << "|----------- ��ӭ����˳��� ----------|" << endl;
	cout << "|---------------1. �������-----------|" << endl;
	cout << "|---------------2. �������-----------|" << endl;
	cout << "|---------------3. �������-----------|" << endl;
	cout << "|---------------4. �������-----------|" << endl;
	cout << "|---------------5. �ҽ����-----------|" << endl;
	cout << "|---------------6. �����߶�-----------|" << endl;
	cout << "|---------------7. Ѱ�ҽ��-----------|" << endl;
	cout << "|---------------8. Ѱ��˫��-----------|" << endl;
	cout << "|---------------0. �˳�---------------|" << endl;
	cout << "|-------------------------------------|" << endl;
}
int main()
{
	vector<char>GetTree;
	char num;
	int input = 0;
	cout << "���ڿ�ʼ���ǵĳ���֮��" << endl;
	cout << endl;
	cout << "�������������У��ҽ��Դ�������һ��������ס�������Ǻ��������ָ�룬���ң���Ҫ��������ո�" << endl;
	while (1)
	{
		cin >> num;
		GetTree.push_back(num);
		if (cin.get() == '\n')
			break;
	}
	BiTree<char>tree(GetTree);
	cout << "������ɣ�������ѡ��������Ĳ���" << endl;
	do
	{
		menu();
		cout << endl;
		cout << "��ѡ����Ҫ���еĲ���" << endl;
		cout << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "��������Ľ������:";
			cout << endl;
			tree.PreOrder();
			break;
		case 2:
			cout << "��������Ľ������:";
			cout << endl;
			tree.InOrder();
			break;
		case 3:
			cout << "��������Ľ������:";
			cout << endl;
			tree.PostOrder();
			break;
		case 4:
			cout << "��������Ľ������:";
			cout << endl;
			tree.LevelOrder();
			break;
		case 5:
			cout << "�����Ľ����Ϊ: ";
			cout << tree.Count() << endl;
			break;
		case 6:
			cout << "�����ĸ߶�Ϊ: ";
			cout << tree.Height() << endl;
			break;
		case 7:
			char ch;
			cout << "��������Ҫ���ҵ�ֵ" << endl;
			cin >> ch;
			if (tree.Search(ch))
			{
				cout << "���ҵ��ˣ��ý������ڸ�����" << endl;
			}
			else
			{
				cout << "���ź����ý�㲢�������ڸ�����" << endl;
			}
			break;
		case 8:
			char ch1;
			cout << "��������Ҫ������˫�׵�ֵ" << endl;
			cin >> ch1;
			if (tree.Search(ch1))
			{
				cout << "����˫�׵�ֵΪ��";
				cout<<tree.SearchParent(tree.Search(ch1))->data<<endl;
			}
			else
			{
				cout << "���ź����ý�㲢�������ڸ����У��������ǲ���Ϊ�����ҵ�����˫��" << endl;
			}
			break;
		case 0:
			cout << "�����˳�,��л����ʹ��" << endl;
			exit(-1);
			break;
		default:
			cout << "��Ǹ�����������������޷���⵱ǰ����Ҫ���еĲ�������������������ѡ��" << endl;
		}

	} while (input);
	return 0;
}