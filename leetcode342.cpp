/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
Example:
Given num = 16, return true. Given num = 5, return false.
Follow up: Could you solve it without loops/recursion?
λ���������λΪ1������λΪ0��0�ĸ���Ϊż����
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

bool isPowerOfFour(int num)
{
	return num > 0 && (num&(num - 1)) == 0 && (num & 0x55555555) != 0;
}
int main()
{
	int num;
	while (cin >> num)
	{
		if (isPowerOfFour(num))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	system("pause");
	return 0;
}