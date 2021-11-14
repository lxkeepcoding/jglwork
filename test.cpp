#define _CRT_SECURE_NO_WARNINGS   1

#include<iostream>
#include<string>
using namespace std;
string Replace(string s1, string s2, string s3, int pos)
{
	string s4;
	s4 = s1.substr(0, pos) + s3 + s1.substr((pos + s2.length()), s1.length() - 1);
	return s4;
}
int* getNext(string p)
{
	int* next = new int[p.length()];
	next[0] = -1;         
	int j = 0;
	int k = -1;
	while (j < (int)p.length() - 1)
	{
		if (k == -1 || p[j] == p[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
	return next;
}

int KMP(string T, string p)
{
	int i = 0;
	int j = 0;
	int* next = getNext(T);
	while (i < (int)T.length() && j < (int)p.length())
	{
		if (j == -1 || T[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == (int)p.length())
	{
		return i - j;
	}
	return -1;
}


int main()
{
	string str1, str2, str3;
	cin >> str1;
	cin >> str2;
	cin >> str3;
	int pos = 0;
	pos = KMP(str1, str2);
	while (pos != -1)
	{
		str1=Replace(str1, str2, str3, pos);
		pos = KMP(str1, str2);
	}
	cout << str1 << endl;
	return 0;
}
