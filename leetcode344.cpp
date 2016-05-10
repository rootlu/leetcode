/*
Write a function that takes a string as input and returns the string reversed.
Example:
Given s = "hello", return "olleh".
*/
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

string reverseString(string s)
{
	string res="";
	for (int i = s.size()-1; i>=0; i--)
		res += s[i];
	return res;
}
int main()
{
	string str;
	cin >> str;
	cout << reverseString(str) << endl;
	system("pause");
	return 0;
}