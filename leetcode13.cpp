/*
���������������໥ת��
����Ϊ1-3999֮��
https://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97
�������ֹ���7������I��1����V��5����X��10����L��50����C��100����D��500����M��1000��
�ظ����Σ�һ�����������ظ����Σ��ͱ�ʾ������ļ�����
�Ҽ������
���߳�ǧ
��������
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
��ǰ��������������֣����ĳ������ǰһ����С����Ѹ������뵽����У�
��֮�����ڽ�������μ�ȥǰһ���������ϵ�ǰ�������
*/
int romanToInt(string s)
{
	string::size_type len = s.size();
	if (len == 1)
		return romanMap[s[0]];
	int result = romanMap[s[0]];
	int pre = romanMap[s[0]];//ǰһλ
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
������С������ǰ�����Ҳ��Ϊ�������֣���һ����Ӧ����ֵӳ���
����4=1-5=IV,9=1-10=IX,40=10-50=XL,90=10-100=XC,400=100-500=CD, 900=100-1000=CM��
��ô���Եõ���Ӧ��ӳ��Ϊ��
unsigned int a[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
string r[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
���ڰ���������n������a���飬���n>=a[i]����������r[i]��ͬʱ����n=n-a[i]��ֱ��n=0Ϊֹ��
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