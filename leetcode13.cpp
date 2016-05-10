/*
罗马数字与整型相互转换
输入为1-3999之间
https://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97
罗马数字共有7个，即I（1）、V（5）、X（10）、L（50）、C（100）、D（500）和M（1000）
重复数次：一个罗马数字重复几次，就表示这个数的几倍。
右加左减：
加线乘千
数码限制
*/
#include<iostream>
#include<stdlib.h>
#include<map>
#include<string>
using namespace std;

map<char, int> romanMap = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 },
						{ 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
map<int, string> intMap = 
{ { 1000, "M" }, { 900, "CM" }, { 500, "D" }, { 400, "CD" }, { 100, "C" }, { 90, "XC" },
{ 50, "L" }, { 40, "XL" }, { 10, "X" }, { 9, "IX" }, { 5, "V" }, { 4, "IV" }, { 1, "I" } };
/*
从前往后遍历罗马数字，如果某个数比前一个数小，则把该数加入到结果中；
反之，则在结果中两次减去前一个数并加上当前这个数；
*/
int romanToInt(string s)
{
	string::size_type len = s.size();
	if (len == 1)
		return romanMap[s[0]];
	int result = romanMap[s[0]];
	int pre = romanMap[s[0]];//前一位
	for (int i = 1; i < len; i++)
	{
		if (pre >= romanMap[s[i]])
			result += romanMap[s[i]];
		else
			result = result - 2 * pre + romanMap[s[i]];
		pre = romanMap[s[i]];
	}
	return result;
}
/*
把所有小数字在前的组合也作为基本数字，做一个对应的数值映射表。
比如4=1-5=IV,9=1-10=IX,40=10-50=XL,90=10-100=XC,400=100-500=CD, 900=100-1000=CM。
那么可以得到对应的映射为：
unsigned int a[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
string r[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
对于阿拉伯数字n，遍历a数组，如果n>=a[i]，则结果保留r[i]，同时更新n=n-a[i]，直到n=0为止。
*/
string intToRoman(int num)
{
	int a[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string result="";
	int i = 0;
	while (num>0)
	{
		while (num >= a[i])
		{
			result += intMap[a[i]];
			num -= a[i];
		}
		i++;
	}
	return result;

}
int main()
{
	string str;
	cin >> str;
	cout << romanToInt(str) << endl;
	
	int n;
	cin >> n;
	cout << intToRoman(n) << endl;
	system("pause");
	return 0;
}