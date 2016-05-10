/*
Implement atoi to convert a string to an integer.
*/
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

int myAtoi(string str)
{
	long result = 0;
	if (str.size() == 0||str=="")
		return 0;
	int flag = 1;
	int i = str.find_first_not_of(" ");
	if (str[i] == '-')
	{
		flag = 0;
		i++; 
	}
	else if (str[i] == '+')
	{
		flag = 1;
		i++;
	}
	for (int j = i; i <= 10 + j&&isdigit(str[i]); i++)
	{
		result = result * 10 + (str[i] -'0');
	}
	if (!flag)
		result = -result;
	return (result > INT_MAX ? INT_MAX : (result < INT_MIN ? INT_MIN : result));

}
int main()
{
	string str;
	cin >> str;
	cout << myAtoi(str) << endl;
	system("pause");
	return 0;
}