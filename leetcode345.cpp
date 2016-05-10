/*
Write a function that takes a string as input and reverse only the vowels of a string.
Example 1:
Given s = "hello", return "holle".
Example 2:
Given s = "leetcode", return "leotcede".
µ÷»»ÔªÒô×ÖÄ¸
*/
#include<iostream>#include<stdlib.h>
#include<string>
using namespace std;

string reverseVowels(string s) 
{
	string::iterator p1 = s.begin(), p2 = s.end() - 1;
	string vowels = "aoeiuAOEIU";
	while (p1<p2)
	{
		while ((vowels.find(*p1)==string::npos)&& (p1 < p2))
			p1++;
		while ((vowels.find(*p2)==string::npos)&& (p1 < p2))
			p2--;
		if (p1 < p2)
			swap(*p1, *p2);
		p1++;
		p2--;
	}
	return s;

}
int main()
{
	string str, resultStr;
	while (cin>>str)
	{
		resultStr = reverseVowels(str);
		cout << resultStr << endl;
	}
	system("pause");
	return 0;
}