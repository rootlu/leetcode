/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

string convert(string s, int numRows) 
{
	string result="";
	if (numRows == 1)
		return s;
	for (int i = 0; i < numRows;i++)
	{
		for (int j = i; j < s.size(); j +=2*numRows-2)
		{
			result += s[j];//第一行和最后一行生成规则
			if (i != 0 && i != numRows - 1)
			{
				int temp=j + 2 * numRows - 2 - 2 * i;//!!!
				if(temp<s.size())
					result += s[temp];
			}
		}	
	}
	return result;
}
int main()
{
	string str;
	int nRows;
	cin >> str >> nRows;
	cout << convert(str, nRows) << endl;
	system("pause");
	return 0;
}