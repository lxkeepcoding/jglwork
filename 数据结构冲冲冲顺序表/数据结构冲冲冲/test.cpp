#define _CRT_SECURE_NO_WARNINGS   1

#include"SeqList.cpp"
#include<iostream>
using namespace std;

void menu()
{
	cout << "|------------------------------------|" << endl;
	cout << "|----------- ��ӭ����˳��� ---------|" << endl;
	cout << "|---------------1.����---------------|" << endl;
	cout << "|---------------2.ɾ��---------------|" << endl;
	cout << "|---------------3.��---------------|" << endl;
	cout << "|---------------4.ȡֵ---------------|" << endl;
	cout << "|---------------5.��λ---------------|" << endl;
	cout << "|---------------6.��ӡ---------------|" << endl;
	cout << "|---------------0.�˳�---------------|" << endl;
	cout << "|------------------------------------|" << endl;
}
int main()
{
	int *a;
	int n;
	cout << "��������Ҫ�����˳���ĳ���" << endl;
	cin >> n;
	a = new int[n];
	cout << "�������˳����е�ÿһ��Ԫ��" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	SeqList<int, 20>seq(a, n);
	cout << "���ڿ�ʼ���ǵĳ���֮��" << endl;
	int input=0;
	do
	{
		menu();
		cout << "������Ҫ���еĲ����ı��" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "��������Ҫ�����λ�ú���ֵ" << endl;
			int pos;
			int value;
			cin >> pos;
			cin >> value;
			seq.Insert(pos,value);
			break;
		case 2:
			cout << "��������Ҫɾ����λ��" << endl;
			int pos1;
			cin >> pos1;
			cout << "��ɾ����Ԫ�ص�ֵΪ��";
			cout << seq.Delete(pos1) << endl;
			break;
		case 3:
			cout << "����˳���ǰ�ĳ���Ϊ��" << seq.ListLength() << endl;
			break;
		case 4:
			cout << "��������Ҫ���ҵ�λ��" << endl;
			int pos2;
			cin >> pos2;
			cout << "�����ҵ�Ԫ�ص�ֵΪ��";
			cout << seq.Get(pos2) << endl;;
			break;
		case 5:
			cout << "��������Ҫ���ҵ�Ԫ��" << endl;
			int item;
			cin >> item;
			cout << "�����ҵ�Ԫ�ص�λ��Ϊ��";
			cout << seq.Locate(item) << endl;;
			break;
		case 6:
			cout << "��ǰ˳������£�" << endl;
			seq.SeqPrint();
			break;
		case 0:
			cout << "�����˳�����лʹ��" << endl;
			exit(-1);
			break;
		default :
			cout << "������������������ѡ��" << endl;
		}
	} while (input);
	return 0;
}