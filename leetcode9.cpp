/*
Determine whether an integer is a palindrome. Do this without extra space
判断一个整数是否为回文
方法一：转换成字符串
方法二：数学方法，逆置原数字，判断逆置前后是否相等
*/
#include<iostream>
#include<stdlib.h>
#include<string>
#include<sstream>
using namespace std;

//方法一
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
//方法二
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
			cout << "是回文数字" << endl;
		else
			cout << "不是回文数字" << endl;
	}
	system("pause");
	return 0;
}