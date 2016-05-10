/*
Determine whether an integer is a palindrome. Do this without extra space
�ж�һ�������Ƿ�Ϊ����
����һ��ת�����ַ���
����������ѧ����������ԭ���֣��ж�����ǰ���Ƿ����
*/
#include<iostream>
#include<stdlib.h>
#include<string>
#include<sstream>
using namespace std;

//����һ
//bool isPalindrome(int x)
//{
//	stringstream ss;
//	string s;
//	ss << x;
//	ss >> s;
//	int len = s.size();
//	for (int i = 0; i < s.size() / 2; i++){
//		if (s[i] != s[len - i - 1])
//			return false;
//		else
//			continue;
//	}
//	return true;
//}
//������
bool isPalindrome(int x)
{
	if (x < 0)
		return false;

	int palindrome = 0;
	int origin = x;
	while (x!=0)
	{
		palindrome = palindrome * 10 + x % 10;
		x /= 10;
	}
	return palindrome == origin;
}

int main()
{
	int n;
	while (cin>>n)
	{
		if (isPalindrome(n))
			cout << "�ǻ�������" << endl;
		else
			cout << "���ǻ�������" << endl;
	}
	system("pause");
	return 0;
}